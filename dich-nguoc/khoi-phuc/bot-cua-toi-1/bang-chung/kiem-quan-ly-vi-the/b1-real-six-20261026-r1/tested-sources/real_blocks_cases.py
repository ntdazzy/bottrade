"""Ca đầu vào cố định cho Bot1ManagementRealBlocksCheck.mq5.

Giao diện theo claude-thuc-hien/bot1-real-three-check-20261026-r1/TASK.md
(đường dẫn từ dich-nguoc/khoi-phuc/): đầu tệp 3 int32 (magic, version,
count), mỗi ca 440 byte `<22iqQII41d` = 22 int32, int64 ticket, uint64
deviation, uint32 index, uint32 error_count, 25 double, 8 volumes, 8 levels.
Ca lấy từ bộ ca Bot3 hiện hành bot-cua-toi-3/tests/real_blocks_cases.py,
mọi stage 0..5 theo claude-thuc-hien/bot1-real-six-check-20261026-r1/TASK.md.
Chỉ tạo đầu vào: không tính kết quả mong đợi, không gọi mã MQL5 production
hay mã gốc. Dùng: data = encode(cases()).
"""

import copy
import importlib.util
import struct
from pathlib import Path

MAGIC = 0x4d524231
VERSION = 1
MAX_COUNT = 100000
ARRAY_SIZE = 8
STAGES = (0, 1, 2, 3, 4, 5)

HEADER = struct.Struct('<3i')
CASE = struct.Struct('<22iqQII41d')

INTS = [
    'id', 'buy', 'stage', 'scenario', 'modify_ok', 'error_code',
    'digits0', 'digits1', 'digits2', 'digits3',
    'enabled', 'gap_count', 'minimum_steps', 'counter',
    'passed_flag', 'eligible_flag', 'before_open', 'shift_setting',
    'step_enabled', 'guard', 'prior_changed', 'table_pattern',
]
# Giữa INTS và DOUBLES: int64, uint64, uint32, uint32.
MIDDLE = ['ticket', 'deviation', 'index', 'error_count']
DOUBLES = [
    'sl', 'tp', 'open_price', 'volume', 'bid', 'ask',
    'unit', 'trail', 'step', 'start', 'limit', 'reference',
    'anchor', 'gap', 'freeze', 'point', 'minimum',
    'lock_start', 'lock_extra', 'step_reference', 'step_distance',
    'copied_step', 'initial_stop', 'ticket_number', 'current_stop',
]
ARRAYS = ['volumes', 'levels']

# Khoảng encode kiểm; độ rộng int32/int64/uint64/uint32 còn lại do struct giữ.
LIMITS = {
    'buy': (0, 1), 'scenario': (0, 11), 'modify_ok': (0, 1),
    'passed_flag': (0, 255), 'eligible_flag': (0, 255),
    'before_open': (0, 255), 'shift_setting': (0, 255),
    'step_enabled': (0, 255), 'guard': (0, 255),
    'prior_changed': (0, 1), 'table_pattern': (0, 5),
    'index': (0, ARRAY_SIZE - 1),
}

# Thư mục đề xuất claude-thuc-hien/<tên>/ và đích bot-cua-toi-1/tests/ cùng
# cách dich-nguoc/khoi-phuc/ hai cấp nên dùng chung đường dẫn này.
SOURCE_PATH = (Path(__file__).resolve().parents[2]
               / 'bot-cua-toi-3' / 'tests' / 'real_blocks_cases.py')


def _load_source():
    """Nạp tệp ca Bot3 một lần, tên module riêng, không ghi vào sys.modules."""
    spec = importlib.util.spec_from_file_location(
        'bot3_real_blocks_cases', str(SOURCE_PATH))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


_SOURCE = _load_source()


def cases() -> list:
    """Ca stage 0..5 của Bot3 theo thứ tự gốc, id liên tục từ 0.

    Mỗi ca là bản sao sâu; source_case_id giữ id Bot3, volumes/levels lấy
    ARRAY_SIZE phần đầu, index %= ARRAY_SIZE. Stage, các giá trị khác (cả bit
    NaN/±0) và group giữ nguyên.
    """
    rows = []
    for source in _SOURCE.cases():
        if source['stage'] not in STAGES:
            continue
        row = copy.deepcopy(source)
        row['source_case_id'] = source['id']
        row['id'] = len(rows)
        row['volumes'] = row['volumes'][:ARRAY_SIZE]
        row['levels'] = row['levels'][:ARRAY_SIZE]
        row['index'] %= ARRAY_SIZE
        rows.append(row)
    return rows


def _check(rows: list) -> None:
    if not 1 <= len(rows) <= MAX_COUNT:
        raise ValueError(f'count {len(rows)} outside 1..{MAX_COUNT}')
    fields = INTS + MIDDLE + DOUBLES + ARRAYS
    for position, row in enumerate(rows):
        missing = [name for name in fields if name not in row]
        if missing:
            raise ValueError(f'row {position}: missing {", ".join(missing)}')
        if row['id'] != position:
            raise ValueError(f'row {position}: id {row["id"]} is not sequential')
        if row['stage'] not in STAGES:
            raise ValueError(
                f'row {position}: stage={row["stage"]} not in {STAGES}')
        for name, (low, high) in LIMITS.items():
            if not low <= row[name] <= high:
                raise ValueError(
                    f'row {position}: {name}={row[name]} outside {low}..{high}')
        for name in ARRAYS:
            if len(row[name]) != ARRAY_SIZE:
                raise ValueError(
                    f'row {position}: {name} needs {ARRAY_SIZE} values')


def encode(rows: list) -> bytes:
    """3 int32 đầu tệp (magic, version, count) rồi 440 byte mỗi ca."""
    _check(rows)
    parts = [HEADER.pack(MAGIC, VERSION, len(rows))]
    for position, row in enumerate(rows):
        try:
            parts.append(CASE.pack(
                *[row[name] for name in INTS], *[row[name] for name in MIDDLE],
                *[row[name] for name in DOUBLES],
                *row['volumes'], *row['levels']))
        except struct.error as error:
            raise struct.error(f'row {position}: {error}') from error
    return b''.join(parts)


if __name__ == '__main__':
    rows = cases()
    counts = {}
    for row in rows:
        key = (row['stage'], row['group'].split('/')[0])
        counts[key] = counts.get(key, 0) + 1
    for (stage, category), count in sorted(counts.items()):
        print(f'stage{stage} {category}: {count}')
    print(f'total {len(rows)} cases, {len(encode(rows))} bytes')
