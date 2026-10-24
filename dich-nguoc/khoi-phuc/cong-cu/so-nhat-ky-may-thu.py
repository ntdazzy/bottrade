"""So dòng hoạt động giao dịch giữa hai nhật ký máy thử MT5 (bản gốc và bản dựng lại).

Dòng hoạt động = dòng của tác tử "Core NN" có mốc giờ mô phỏng "YYYY.MM.DD hh:mm:ss"
(đặt/khớp/sửa/hủy/hết hạn/đóng lệnh, dòng Print có mốc giờ). Không tính dòng
tham số đầu vào, dòng "OnTester result" và dòng thống kê cuối.

Dùng:
  python -I -B -X utf8 so-nhat-ky-may-thu.py <nhat-ky-goc> <nhat-ky-dung-lai> [--json <ra.json>] [--case ten]
Nhật ký nhận UTF-8 (đầu ra của run_market.py) hoặc UTF-16 (nhật ký gốc của MT5).
Mã thoát 0 khi mọi dòng trùng theo thứ tự, 1 khi có khác biệt.
"""
import argparse
import hashlib
import json
import re
import sys
from pathlib import Path

LINE = re.compile(r'^\S*\t\d+\t[\d:.]+\tCore \d+\t(\d{4}\.\d\d\.\d\d \d\d:\d\d:\d\d(?:\.\d+)?)\s+(.*?)\s*$')
SUMMARY = re.compile(r'^\S*\t\d+\t[\d:.]+\tCore \d+\t(final balance .*|.*Test passed in .*|OnTester result .*)$')
# Thời gian chạy thật (không phải giờ mô phỏng) khác nhau giữa các lần chạy; bỏ khỏi dòng tóm tắt khi so.
WALLCLOCK = re.compile(r'(Environment synchronized in|Test passed in|including ticks preprocessing) [\d:.]+')


def read(path):
    raw = Path(path).read_bytes()
    if raw[:2] in (b'\xff\xfe', b'\xfe\xff'):
        return raw.decode('utf-16'), raw
    return raw.decode('utf-8-sig'), raw


INPUT = re.compile(r'^\S*\t\d+\t[\d:.]+\tCore \d+\t  (.*?)\s*$')
STARTED = re.compile(r'^\S*\t\d+\t[\d:.]+\tCore \d+\t.*started with inputs:')


def inputs(text):
    """Khối tham số máy thử in sau 'started with inputs:' (tác tử Core), gồm cả tiêu đề nhóm."""
    rows, active = [], False
    for line in text.splitlines():
        if STARTED.match(line):
            if rows:
                break
            active = True
            continue
        if active:
            # Nhật ký do chay-may-thu.py ghi có kết thúc dòng \r\r\n nên xen dòng rỗng.
            if not line.strip():
                continue
            m = INPUT.match(line)
            if not m:
                break
            rows.append(m.group(1))
    return rows


def events(text):
    rows, summary = [], []
    for line in text.splitlines():
        m = LINE.match(line)
        if m:
            rows.append(m.group(1) + ' ' + m.group(2))
            continue
        s = SUMMARY.match(line)
        if s:
            summary.append(s.group(1).strip())
    return rows, summary


def compare(orig_path, reco_path, case=None):
    t1, r1 = read(orig_path)
    t2, r2 = read(reco_path)
    e1, s1 = events(t1)
    e2, s2 = events(t2)
    diffs = []
    for i in range(max(len(e1), len(e2))):
        a = e1[i] if i < len(e1) else None
        b = e2[i] if i < len(e2) else None
        if a != b:
            diffs.append({'index': i, 'original': a, 'recovered': b})
            if len(diffs) >= 5:
                break
    bal1 = [s for s in s1 if s.startswith('final balance')]
    bal2 = [s for s in s2 if s.startswith('final balance')]
    i1, i2 = inputs(t1), inputs(t2)
    first_input = next((i for i in range(max(len(i1), len(i2)))
                        if (i1[i] if i < len(i1) else None) != (i2[i] if i < len(i2) else None)), None)
    return {
        'inputs': [len(i1), len(i2)], 'inputs_identical': i1 == i2,
        'first_input_difference': None if first_input is None else {
            'index': first_input, 'original': i1[first_input] if first_input < len(i1) else None,
            'recovered': i2[first_input] if first_input < len(i2) else None},
        'case': case or Path(orig_path).stem,
        'original_log': str(orig_path), 'recovered_log': str(reco_path),
        'log_sha256': [hashlib.sha256(r1).hexdigest(), hashlib.sha256(r2).hexdigest()],
        'original_events': len(e1), 'recovered_events': len(e2),
        'all_events_identical': not diffs and len(e1) == len(e2),
        'first_differences': diffs,
        'final_balance': [bal1, bal2],
        'summary': [[WALLCLOCK.sub(r'\1 <t>', s) for s in s1], [WALLCLOCK.sub(r'\1 <t>', s) for s in s2]],
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('original')
    ap.add_argument('recovered')
    ap.add_argument('--json')
    ap.add_argument('--case')
    a = ap.parse_args()
    result = compare(a.original, a.recovered, a.case)
    text = json.dumps(result, ensure_ascii=False, indent=1)
    if a.json:
        out = Path(a.json)
        if out.exists():
            raise FileExistsError('REFUSE_OVERWRITE ' + str(out))
        out.write_text(text + '\n', encoding='utf-8')
    print(json.dumps({k: result[k] for k in ('case', 'original_events', 'recovered_events',
                                             'all_events_identical', 'final_balance', 'inputs',
                                             'inputs_identical', 'first_input_difference')}, ensure_ascii=False))
    return 0 if result['all_events_identical'] else 1


if __name__ == '__main__':
    sys.exit(main())
