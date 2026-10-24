"""So nguồn MQL5 cho phần chọn chiến lược với các ca gốc đã kiểm.

Chỉ chạy chương trình kiểm trong MT5 riêng; không gọi giao dịch. Ca gốc
được lấy từ các lượt đã khớp trực tiếp với EX5, không tự tạo kỳ vọng mới.

Usage: python -I -B -X utf8 kiem-chon-chien-luoc-bot-1-3.py prepare|mql5|compare BOT RUN
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT = Path(__file__).resolve().parents[1]
MT = ROOT.parent / '.local/claude-recovery-20261023/mt5'
MAGIC = 0x53454C31


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def bot1_rows():
    source = ROOT / 'bot-cua-toi-1/phan-tich/bat-tat-chien-luoc/enable-20261023-r3/results.json'
    rows = json.loads(source.read_text(encoding='utf-8'))
    summary = json.loads(source.with_name('summary.json').read_text(encoding='utf-8'))
    if not summary['passed'] or summary['results_sha256'] != sha(source):
        raise ValueError('NATIVE_EVIDENCE_NOT_VERIFIED')
    if any(not row['matched'] for row in rows):
        raise ValueError('NATIVE_EVIDENCE_CONTAINS_FAILURE')
    cases = [{'id': i, 'mask': int(row['mask']),
              'expected_mask': sum(1 << index for index in row['original_selected_profiles'])}
             for i, row in enumerate(rows)]
    return source, cases


def bot3_rows():
    source = ROOT / 'bot-cua-toi-3/phan-tich/chon-chien-luoc/select-20261023-r1/results.jsonl'
    summary = json.loads(source.with_name('summary.json').read_text(encoding='utf-8'))
    if not summary['passed'] or summary['results_sha256'] != sha(source):
        raise ValueError('NATIVE_EVIDENCE_NOT_VERIFIED')
    cases = []
    for i, line in enumerate(source.read_text(encoding='utf-8').splitlines()):
        row = json.loads(line)
        if not row['matched']:
            raise ValueError('NATIVE_EVIDENCE_CONTAINS_FAILURE')
        item = row['inputs']
        cases.append({
            'id': i,
            'frequency': int(item['frequency']),
            'risk': int(item['risk']),
            'max_dd': float(item['max_dd']),
            'converted_balance': float(item['converted_balance']),
            'variable': int(item['variable']),
            'manual': int(item['manual']),
            'initial': int(item['initial']),
            'initial_mode': -97,
            'initial_divisor': float(item['initial_divisor']),
            'threshold_flags': int(item['threshold_flags']),
            'expected': row['original'],
            'path': row['path'],
            'case': int(row['case']),
        })
    return source, cases


def encode(bot, cases):
    raw = bytearray(struct.pack('<3i', MAGIC, 1, len(cases)))
    if bot == 1:
        for row in cases:
            raw += struct.pack('<2i', row['id'], row['mask'])
    else:
        for row in cases:
            raw += struct.pack('<3i2d4idi', row['id'], row['frequency'], row['risk'],
                               row['max_dd'], row['converted_balance'], row['variable'], row['manual'],
                               row['initial'], row['initial_mode'], row['initial_divisor'], row['threshold_flags'])
    return bytes(raw)


def read_header(data):
    magic, version, count = struct.unpack_from('<3i', data)
    if (magic, version) != (MAGIC, 1) or count < 1:
        raise ValueError('BAD_CASE_HEADER')
    return count


def start_mt5(bot, run, files):
    params = MT / 'MQL5/Presets' / f'b{bot}-{run}.set'
    params.write_text(f'CheckRun={run}\n', encoding='utf-16')
    ini = MT / f'b{bot}-{run}-strategy-selection.ini'
    ini.write_text(
        '[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n'
        '[StartUp]\n'
        f'Script=bot-cua-toi-{bot}\\Bot{bot}StrategySelectionCheck\n'
        f'ScriptParameters={params.name}\n'
        'Symbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',
        encoding='utf-16')
    start = time.monotonic()
    proc = subprocess.Popen(f'"{MT / "terminal64.exe"}" /portable /config:"{ini}"',
                            cwd=MT, creationflags=subprocess.CREATE_NO_WINDOW)
    try:
        code = proc.wait(timeout=180)
    except subprocess.TimeoutExpired:
        proc.terminate()
        proc.wait(timeout=30)
        raise RuntimeError('MQL5_CHECK_TIMEOUT')
    result = files / 'mql5-results.bin'
    if code != 0 or not result.is_file():
        raise RuntimeError(f'MQL5_CHECK_FAILED {code}')
    return code, round(time.monotonic() - start, 2), result


def verify_build(bot, build):
    receipt_path = ROOT / f'bot-cua-toi-{bot}/bang-chung/bien-dich' / build / 'bien-nhan.json'
    receipt = json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    target = f'Scripts/bot-cua-toi-{bot}/Bot{bot}StrategySelectionCheck.mq5'
    script = MT / target.replace('.mq5', '.ex5').replace('Scripts/', 'MQL5/Scripts/', 1)
    if receipt['target'] != target or receipt['errors'] != 0 or receipt['warnings'] != 0:
        raise ValueError('BUILD_NOT_VERIFIED')
    if sha(script) != receipt['binary_sha256']:
        raise ValueError('COMPILED_SCRIPT_CHANGED')
    for path, expected_hash in receipt['sources_sha256'].items():
        if sha(ROOT / f'bot-cua-toi-{bot}/source/MQL5' / path) != expected_hash:
            raise ValueError('SOURCE_CHANGED_AFTER_BUILD ' + path)
    return receipt_path, receipt, script


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('mode', choices=['prepare', 'mql5', 'compare'])
    ap.add_argument('bot', type=int, choices=[1, 3])
    ap.add_argument('run')
    ap.add_argument('--build')
    args = ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+', args.run):
        raise ValueError('INVALID_RUN')
    out = ROOT / f'bot-cua-toi-{args.bot}/bang-chung/kiem-chon-chien-luoc' / args.run
    if args.mode == 'prepare':
        if out.exists():
            raise FileExistsError(out)
        out.mkdir(parents=True)
        source, cases = bot1_rows() if args.bot == 1 else bot3_rows()
        (out / 'cases.bin').write_bytes(encode(args.bot, cases))
        (out / 'baseline.json').write_text(json.dumps({
            'cases': len(cases), 'source': str(source.relative_to(ROOT)),
            'native_evidence_sha256': sha(source), 'cases_sha256': sha(out / 'cases.bin'),
            'scope': 'MQL5 selector only; expected values come from native results, not the analysis hypothesis.'
        }, ensure_ascii=False, indent=2), encoding='utf-8')
        print(json.dumps({'bot': args.bot, 'cases': len(cases)}))
        return
    if not out.is_dir():
        raise FileNotFoundError(out)
    target = out / 'mql5-results.bin'
    if args.mode == 'mql5':
        if target.exists():
            raise FileExistsError(target)
        if not args.build or not re.fullmatch('[a-z0-9-]+', args.build):
            raise ValueError('VERIFIED_BUILD_REQUIRED')
        receipt_path, receipt, script = verify_build(args.bot, args.build)
        files = MT / f'MQL5/Files/bot{args.bot}-strategy-selection' / args.run
        if files.exists():
            raise FileExistsError(files)
        files.mkdir(parents=True)
        shutil.copyfile(out / 'cases.bin', files / 'cases.bin')
        code, seconds, source_result = start_mt5(args.bot, args.run, files)
        shutil.copyfile(source_result, target)
        (out / 'mql5-run.json').write_text(json.dumps({
            'exit_code': code, 'seconds': seconds,
            'script_sha256': sha(script), 'results_sha256': sha(target),
            'build_receipt': str(receipt_path.relative_to(ROOT)),
            'build_receipt_sha256': sha(receipt_path),
            'sources_sha256': receipt['sources_sha256']
        }, indent=2), encoding='utf-8')
        print('MQL5 results saved')
        return
    data = target.read_bytes()
    count = read_header(data)
    source, cases = bot1_rows() if args.bot == 1 else bot3_rows()
    baseline = json.loads((out / 'baseline.json').read_text(encoding='utf-8'))
    if baseline['native_evidence_sha256'] != sha(source) or baseline['cases_sha256'] != sha(out / 'cases.bin'):
        raise ValueError('BASELINE_CHANGED')
    if encode(args.bot, cases) != (out / 'cases.bin').read_bytes():
        raise ValueError('INPUTS_DIFFER_FROM_NATIVE_CASES')
    if count != len(cases):
        raise ValueError('CASE_COUNT_DIFFERS_FROM_BASELINE')
    pos = 12
    failures = []
    if args.bot == 1:
        if len(data) != 12 + count * 8:
            raise ValueError('RESULT_SHAPE_MISMATCH')
        for row in cases:
            ident, mask = struct.unpack_from('<2i', data, pos); pos += 8
            if (ident, mask) != (row['id'], row['expected_mask']):
                failures.append({'id': row['id'], 'original': row['expected_mask'], 'mql5': [ident, mask]})
    else:
        if len(data) != 12 + count * 20:
            raise ValueError('RESULT_SHAPE_MISMATCH')
        for row in cases:
            ident, mode, mask, divisor_bits = struct.unpack_from('<3iQ', data, pos); pos += 20
            expected = row['expected']
            expected_mask = sum((int(value) & 1) << i for i, value in enumerate(expected['enabled']))
            expected_bits = bytes.fromhex(expected['divisor_bits'])
            expected_divisor_bits = struct.unpack('<Q', expected_bits)[0]
            actual = [ident, mode, mask, divisor_bits]
            wanted = [row['id'], int(expected['mode']), expected_mask, expected_divisor_bits]
            if actual != wanted:
                failures.append({'path': row['path'], 'case': row['case'], 'expected': wanted, 'mql5': actual})
    if pos != len(data):
        raise ValueError('RESULT_BYTES_NOT_EXACT')
    result = {
        'cases': count, 'matched': count - len(failures), 'failed': len(failures),
        'first_failures': failures[:20],
        'hashes': {'cases.bin': sha(out / 'cases.bin'), 'mql5-results.bin': sha(target)},
        'native_evidence_sha256': sha(source),
        'scope': 'Selector source compared with previously captured native selector results; not an EA or trade comparison.'
    }
    (out / 'comparison.json').write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding='utf-8')
    print(json.dumps(result))
    raise SystemExit(bool(failures))


if __name__ == '__main__':
    main()
