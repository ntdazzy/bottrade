"""Khôi phục hồ sơ dịch ngược từ commit Git cũ vào dich-nguoc/khoi-phuc.

Chỉ đọc kho Git bằng --git-dir; không đổi lịch sử. Mỗi tệp được kiểm lại
mã object Git (SHA-1 của blob) trước khi ghi, rồi lưu SHA-256 vào NGUON-GOC.json.
Bằng chứng giữ nguyên từng byte; chỉ 4 tệp nguồn bot 13 được đổi tên theo
bảng DOI_TEN bên dưới (không đổi logic, không đổi thông số số học).

Dùng:
  python -I -B -X utf8 khoi-phuc-tu-git.py --git-dir <thu-muc-git> --commit d2c4292 --out <dich-nguoc/khoi-phuc>
Không ghi đè tệp khác nội dung; chạy lại cho cùng kết quả thì bỏ qua.
"""
import argparse
import hashlib
import json
import re
import subprocess
import sys
from pathlib import Path

# Số bot theo hồ sơ cũ (slug thư mục cũ -> số mới).
SO_BOT = {
    'gold-trade-pro-mt5': 1, 'goldbot-one-mt5': 2, 'the-gold-reaper-mt5': 3,
    'cryonx-ea-mt5': 4, 'dynamic-liquidity-intelligence': 5, 'ea-super-trend-xauusd': 6,
    'gold-beaver': 7, 'moondog-ea': 8, 'quantum-titan-mt5': 9,
    'ultimate-breakout-system': 10, 'my-ai-gold': 11, 'scalping-robot-pro-mt5': 12,
    'twisterpro-scalper': 13, 'ai-golden-life-mt5': 14, 'quantum-queen-x-mt5': 15,
}
BOTS = 'dich-nguoc/bots/'
T13 = BOTS + 'twisterpro-scalper/'

# Tệp bot 13 cần để tiếp tục (đường dẫn cũ tương đối T13 -> đường dẫn mới trong bot-cua-toi-13).
BOT13 = {
    'analysis/TwisterPro-Scalper-annotated-v5.c': 'phan-tich/ma-trung-gian-v5.c',
    'analysis/TwisterPro-Scalper-annotated-v5.c.summary.json': 'phan-tich/ma-trung-gian-v5.c.summary.json',
    'analysis/reconstruction-notes/core-map.md': 'phan-tich/ghi-chu-cu/core-map.md',
    'analysis/reconstruction-notes/trade-map.md': 'phan-tich/ghi-chu-cu/trade-map.md',
    'analysis/reconstruction-notes/dispatch-override-review.md': 'phan-tich/ghi-chu-cu/dispatch-override-review.md',
    'tests/check-twister-filters.py': 'kiem-tra/cu/check-filters.py',
    'tests/check-twister-settings.py': 'kiem-tra/cu/check-settings.py',
    'verification/setup.json': 'bang-chung/may-thu-cu-setup.json',
    'verification/native-code-manifest.json': 'bang-chung/native-code-manifest.json',
    'verification/twister-function-call-graph-v2.json': 'bang-chung/call-graph-v2.json',
    'verification/twister-dispatch-callsite-types.json': 'bang-chung/dispatch-callsite-types.json',
    'verification/dispatch-additional-four.json': 'bang-chung/dispatch-additional-four.json',
    'verification/dispatch-v5-init-verification.json': 'bang-chung/dispatch-v5-init-verification.json',
    'verification/twister-inputs-from-log.json': 'bang-chung/tham-so-tu-nhat-ky.json',
    'verification/twisterdata1_09-job.json': 'bang-chung/ban-chup-ma-may/lenh-chup.json',
    'verification/twisterdata1_09-result.json': 'bang-chung/ban-chup-ma-may/ket-qua-chup.json',
    'verification/behavior-check/matrix-v2.json': 'bang-chung/so-hanh-vi/matrix-v2.json',
    'verification/behavior-check/version1/comparison.json': 'bang-chung/so-hanh-vi/version1-comparison.json',
    'verification/behavior-check/version2/comparison.json': 'bang-chung/so-hanh-vi/version2-comparison.json',
    'verification/behavior-check/version2/TwisterProRecovered.mq5': 'bang-chung/so-hanh-vi/version2-nguon-da-chay.mq5.txt',
    'verification/behavior-check/version2/TwisterProRecovered.build.json': 'bang-chung/so-hanh-vi/version2-build.json',
    'verification/settings-check/cases.json': 'bang-chung/kiem-khoi-tao/cases.json',
    'verification/settings-check/twsettings_v1/comparison.json': 'bang-chung/kiem-khoi-tao/comparison.json',
    'verification/settings-check/twsettings_v1/receipt.json': 'bang-chung/kiem-khoi-tao/receipt.json',
    'verification/filter-check/twfilters_v3/comparison.json': 'bang-chung/kiem-bo-loc/comparison.json',
    'verification/filter-check/twfilters_v3/receipt.json': 'bang-chung/kiem-bo-loc/receipt.json',
    'verification/api-probe-v6/copy-volume-operation-evidence.json': 'bang-chung/doi-chung-api/copy-volume-operation-evidence.json',
    'verification/api-probe-v6/probes.json': 'bang-chung/doi-chung-api/probes.json',
    'verification/enum-probe-v1/enum-values.json': 'bang-chung/doi-chung-api/enum-values.json',
    'verification/enum-probe-v1/types.json': 'bang-chung/doi-chung-api/enum-types.json',
}
for name in ('data.tsv', 'functions.tsv', 'import.json', 'refs.tsv', 'seeds.txt', 'strings.tsv'):
    BOT13['analysis/twister-meta-v2/' + name] = 'phan-tich/ghidra-nhap/' + name
for name in ('dispatch-calls.tsv', 'inputs.json', 'inputs.tsv', 'native-labels.json', 'native-labels.tsv',
             'native-signatures.tsv', 'predefined.tsv', 'return-channel-correction.json', 'state.tsv'):
    BOT13['analysis/twister-symbols-v4/' + name] = 'phan-tich/ky-hieu-v4/' + name
for case in ('ticks1', 'ticks2', 'delay', 'broker1'):
    for side, label in (('orig', 'goc'), ('reco', 'dung-lai')):
        BOT13[f'verification/market-logs/tw_{side}_{case}_v2.log'] = f'bang-chung/so-hanh-vi/nhat-ky-v2/{label}-{case}.log'
for name in ('tworig_m1_a', 'twreco_m1_a_v1'):
    BOT13[f'verification/market-logs/{name}.log'] = f'bang-chung/so-hanh-vi/nhat-ky-v1/{name.replace("tworig", "goc").replace("twreco", "dung-lai")}.log'

# Nguồn MQL5 hiện hành bot 13 -> bộ nguồn làm việc đã đổi tên.
NGUON13 = {
    'source/TwisterProRecovered.mq5': 'source/MQL5/Experts/bot-cua-toi-13/bot-cua-toi-13.mq5',
    'source/TwisterInputs.mqh': 'source/MQL5/Include/bot-cua-toi-13/Bot13Inputs.mqh',
    'source/TwisterSettings.mqh': 'source/MQL5/Include/bot-cua-toi-13/Bot13Settings.mqh',
    'source/TwisterFilters.mqh': 'source/MQL5/Include/bot-cua-toi-13/Bot13Filters.mqh',
}
DOI_TEN = [
    ('TWISTER_RECOVERED_INPUTS_MQH', 'BOT13_INPUTS_MQH'),
    ('TWISTER_RECOVERED_SETTINGS_MQH', 'BOT13_SETTINGS_MQH'),
    ('TWISTER_RECOVERED_FILTERS_MQH', 'BOT13_FILTERS_MQH'),
    ('TwisterRecoveredInputs', 'Bot13Inputs'),
    ('TwisterRecoveredDefaults', 'Bot13Defaults'),
    ('TwisterRecoveredSettings', 'Bot13Settings'),
    ('TwisterRecoverSettings', 'Bot13RecoverSettings'),
    ('TwisterRecoverPriceDistances', 'Bot13RecoverPriceDistances'),
    ('TwisterRecoveredTrend', 'Bot13Trend'),
    ('TwisterRecoveredCandle', 'Bot13Candle'),
    ('TwisterRecoveredVolume', 'Bot13Volume'),
    ('#include "TwisterInputs.mqh"', '#include "Bot13Inputs.mqh"'),
    ('#include "TwisterSettings.mqh"', '#include "../../Include/bot-cua-toi-13/Bot13Settings.mqh"'),
    ('#include "TwisterFilters.mqh"', '#include "../../Include/bot-cua-toi-13/Bot13Filters.mqh"'),
    ('Print("TwisterRecovered: ', 'Print("Bot13: '),
    ('input string TradeComment="TwisterPro";', 'input string TradeComment="Bot13";'),
    ('p.TradeComment="TwisterPro";', 'p.TradeComment="Bot13";'),
    ('twister-inputs-from-log.json', 'bang-chung/tham-so-tu-nhat-ky.json'),
]

# Công cụ và tài liệu chung cần để làm tiếp.
CHUNG = {
    'dich-nguoc/README.md': 'tai-lieu-cu/README-dich-nguoc.md',
    'dich-nguoc/QUY-TRINH.md': 'tai-lieu-cu/QUY-TRINH.md',
    'dich-nguoc/catalog.json': 'tai-lieu-cu/catalog.json',
    'dich-nguoc/requirements.txt': 'cong-cu-cu/requirements.txt',
    'dich-nguoc/tools/README.md': 'cong-cu-cu/README.md',
    'dich-nguoc/tools/inspect-ex5-running-code.py': 'cong-cu-cu/inspect-ex5-running-code.py',
    'dich-nguoc/tools/run-market-ex5-capture.ps1': 'cong-cu-cu/run-market-ex5-capture.ps1',
    'dich-nguoc/tools/run_market.py': 'cong-cu-cu/run_market.py',
    'dich-nguoc/tools/build.ps1': 'cong-cu-cu/build.ps1',
    'dich-nguoc/tools/project_paths.py': 'cong-cu-cu/project_paths.py',
    'dich-nguoc/tools/analyze-api-probes.py': 'cong-cu-cu/analyze-api-probes.py',
    'dich-nguoc/tools/verify-project.py': 'cong-cu-cu/verify-project.py',
    'dich-nguoc/docs/environment/ghidra-receipt.json': 'cong-cu-cu/moi-truong/ghidra-receipt.json',
    'dich-nguoc/docs/environment/jdk-receipt.json': 'cong-cu-cu/moi-truong/jdk-receipt.json',
}
for name in ('AnnotateTwister.java', 'ExportEx5Code.java', 'LoadEx5ProgramData.java',
             'OverrideMqlDispatchCalls.java', 'SetEx5CaptureBase.java'):
    CHUNG['dich-nguoc/tools/ghidra/' + name] = 'cong-cu-cu/ghidra/' + name

INITIAL_NAMES = [
    (re.compile(r'^\d\d_[A-Za-z0-9_]+\.c$'), 'ma-trung-gian.c'),
    (re.compile(r'^\d\d_[A-Za-z0-9_]+\.c\.summary\.json$'), 'ma-trung-gian.c.summary.json'),
    (re.compile(r'^\d\d_[A-Za-z0-9_]+\.bin\.base\.txt$'), 'dia-chi-nen.txt'),
    (re.compile(r'^\d\d_[A-Za-z0-9_]+\.bin\.seeds\.txt$'), 'diem-bat-dau-ham.txt'),
    (re.compile(r'^re2batch1_\d\d-job\.json$'), 'lenh-chup.json'),
    (re.compile(r'^re2batch1_\d\d-result\.json$'), 'ket-qua-chup.json'),
]


def git(git_dir, *args, binary=False):
    out = subprocess.run(['git', '--git-dir=' + git_dir, *args], capture_output=True, check=True)
    return out.stdout if binary else out.stdout.decode('utf-8')


def tree(git_dir, commit):
    rows = {}
    for line in git(git_dir, 'ls-tree', '-r', '-z', '--full-tree', commit).split('\0'):
        if line:
            meta, path = line.split('\t', 1)
            mode, kind, obj = meta.split()
            rows[path] = obj
    return rows


def blob(git_dir, obj):
    data = git(git_dir, 'cat-file', 'blob', obj, binary=True)
    if hashlib.sha1(b'blob %d\0' % len(data) + data).hexdigest() != obj:
        raise ValueError('GIT_BLOB_MISMATCH ' + obj)
    return data


def write(out, rel, data):
    path = out / rel
    if path.exists():
        if path.read_bytes() != data:
            raise FileExistsError('REFUSE_OVERWRITE_DIFFERENT ' + rel)
        return
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(data)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--git-dir', required=True)
    ap.add_argument('--commit', required=True)
    ap.add_argument('--out', required=True)
    a = ap.parse_args()
    out = Path(a.out).resolve()
    commit = git(a.git_dir, 'rev-parse', a.commit + '^{commit}').strip()
    rows = tree(a.git_dir, commit)
    catalog = json.loads(blob(a.git_dir, rows['dich-nguoc/catalog.json']).decode('utf-8-sig'))
    records = []

    def add(old, new, kind, data=None, note=None):
        obj = rows[old]
        raw = blob(a.git_dir, obj)
        final = raw if data is None else data(raw)
        write(out, new, final)
        rec = {'old_path': old, 'git_blob': obj, 'old_sha256': hashlib.sha256(raw).hexdigest(),
               'new_path': new, 'sha256': hashlib.sha256(final).hexdigest(), 'bytes': len(final),
               'loai': kind, 'nguyen_ban': data is None}
        if note:
            rec['ghi_chu'] = note
        records.append(rec)

    for old, new in CHUNG.items():
        add(old, new, 'cong-cu-hoac-tai-lieu-cu')
    for old, new in BOT13.items():
        kind = 'ma-trung-gian' if new.endswith('.c') else 'bang-chung-hoac-ghi-chu'
        add(T13 + old, 'bot-cua-toi-13/' + new, kind)
    capture = T13 + 'verification/captures/twisterdata1_09/'
    for old in sorted(p for p in rows if p.startswith(capture)):
        add(old, 'bot-cua-toi-13/bang-chung/ban-chup-ma-may/' + old[len(capture):], 'du-lieu-chup-ma-may')

    def rename(raw):
        text = raw.decode('utf-8')
        for before, after in DOI_TEN:
            text = text.replace(before, after)
        if re.search('twister', text, re.I):
            raise ValueError('OLD_NAME_LEFT_IN_SOURCE')
        return text.encode('utf-8')
    for old, new in NGUON13.items():
        add(T13 + old, 'bot-cua-toi-13/' + new, 'nguon-dung-lai', rename,
            'Chỉ đổi tên theo DOI_TEN trong công cụ; logic và thông số số học giữ nguyên.')

    for path in sorted(rows):
        m = re.match(r'dich-nguoc/bots/([^/]+)/analysis/initial/(\d\d)_[^/]+/(.+)$', path)
        if not m:
            continue
        slug, index, rest = m.groups()
        name = rest
        for pattern, repl in INITIAL_NAMES:
            if pattern.match(rest):
                name = repl
        kind = 'ma-trung-gian' if name == 'ma-trung-gian.c' else 'du-lieu-chup-ma-may'
        add(path, f'bot-cua-toi-{SO_BOT[slug]}/phan-tich/ban-ex5-{index}/{name}', kind)

    manifest = {
        'git_dir': a.git_dir, 'commit': commit,
        'commit_tree': git(a.git_dir, 'rev-parse', commit + '^{tree}').strip(),
        'so_bot': SO_BOT,
        'ex5_goc_theo_catalog': [{'index': c['index'], 'bot': SO_BOT[c['bot_id']], 'sha256': c['sha256'].lower()}
                                 for c in catalog],
        'files': records,
    }
    (out / 'NGUON-GOC.json').write_text(json.dumps(manifest, ensure_ascii=False, indent=1) + '\n', encoding='utf-8')
    print(json.dumps({'files': len(records), 'bytes': sum(r['bytes'] for r in records), 'commit': commit}))


if __name__ == '__main__':
    sys.exit(main())
