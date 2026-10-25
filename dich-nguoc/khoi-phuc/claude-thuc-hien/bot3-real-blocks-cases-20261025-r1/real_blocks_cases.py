"""Ca đầu vào cố định cho Bot3ManagementRealBlocksCheck.mq5.

Giao diện theo ../bot3-real-blocks-check-20261025-r1/CONTRACT.md: đầu tệp
3 int32 (magic, version, count), mỗi ca 456 byte `<22iqQII43d`.
Chỉ tạo đầu vào: không tính kết quả mong đợi, không dùng số ngẫu nhiên.
NaN, ±0, ±Inf dựng từ bit, không chuẩn hoá; mỗi ca có list volumes/levels
riêng. Dùng: data = encode(cases()).
"""

import itertools
import math
import struct

MAGIC = 0x4d524233
VERSION = 1
MAX_COUNT = 100000
CASE_LIMIT = 4000
ARRAY_SIZE = 9

HEADER = struct.Struct('<3i')
CASE = struct.Struct('<22iqQII43d')

INTS = [
    'id', 'buy', 'stage', 'scenario', 'modify_ok', 'error_code',
    'digits0', 'digits1', 'digits2', 'digits3',
    'enabled', 'gap_count', 'minimum_steps', 'counter',
    'passed_flag', 'eligible_flag', 'before_open', 'shift_setting',
    'step_enabled', 'guard', 'prior_changed', 'table_pattern',
]
DOUBLES = [
    'sl', 'tp', 'open_price', 'volume', 'bid', 'ask',
    'unit', 'trail', 'step', 'start', 'limit', 'reference',
    'anchor', 'gap', 'freeze', 'point', 'minimum',
    'lock_start', 'lock_extra', 'step_reference', 'step_distance',
    'copied_step', 'initial_stop', 'ticket_number', 'current_stop',
]

INT_MIN = -2**31
INT_MAX = 2**31 - 1
UINT32_MAX = 2**32 - 1
INT64_MIN = -2**63
UINT64_MAX = 2**64 - 1


def _from_bits(bits: int) -> float:
    return struct.unpack('<d', struct.pack('<Q', bits))[0]


def _bits(value: float) -> int:
    return struct.unpack('<Q', struct.pack('<d', value))[0]


NEG_INF = _from_bits(0xfff0000000000000)
POS_INF = _from_bits(0x7ff0000000000000)
NEG_ZERO = _from_bits(0x8000000000000000)
POS_ZERO = _from_bits(0x0000000000000000)
NAN_A = _from_bits(0x7ff8000000000123)
NAN_B = _from_bits(0xfff8000000000456)

SPECIAL_VALUES = [
    NEG_INF, -1e19, -100.125, NEG_ZERO, POS_ZERO, 0.01,
    100.125, 1e19, POS_INF, NAN_A, NAN_B,
]
# Trường thay bằng từng giá trị đặc biệt, theo stage 0..5.
SPECIAL_FIELDS = [
    ['sl', 'tp', 'unit', 'trail', 'step', 'start', 'limit', 'anchor',
     'gap', 'freeze', 'point', 'volume', 'minimum'],
    ['sl', 'tp', 'unit', 'trail', 'start', 'limit', 'reference',
     'gap', 'freeze', 'point'],
    ['sl', 'tp', 'open_price', 'unit', 'gap', 'freeze', 'point',
     'levels[index]'],
    ['sl', 'tp', 'unit', 'lock_start', 'lock_extra', 'gap', 'freeze',
     'point'],
    ['sl', 'tp', 'unit', 'step_distance', 'step_reference', 'copied_step',
     'anchor', 'gap', 'freeze'],
    ['initial_stop', 'current_stop', 'ticket_number'],
]
STAGE2_FIELDS = [
    ('enabled', (-1, 0, 1, 2)),
    ('eligible_flag', (0, 1, 2, 255)),
    ('before_open', (0, 1, 2, 255)),
    ('shift_setting', (0, 1, 2, 255)),
    ('gap_count', (INT_MIN, -1, 0, INT_MAX)),
]
STAGE4_FIELDS = [
    ('step_enabled', (0, 1, 2, 255)),
    ('counter', (INT_MIN, -1, 0, 1, INT_MAX)),
    ('minimum_steps', (INT_MIN, -1, 0, 2, INT_MAX)),
    ('step_reference', (POS_ZERO, NEG_ZERO, 1.0, NAN_A)),
]
TICKETS = (0, 2**53 + 1, -1, INT64_MIN)
DIGIT_FIELDS = ('digits0', 'digits1', 'digits2', 'digits3')
DIGIT_SETS = [
    (-1, 0, 1, 2),
    (0, 1, 2, 3),
    (2, 8, 3, 1),
    (11, 10, 9, 8),
    (INT_MIN, INT_MAX, -1, 12),
]
SL_FRACTION = 0.123456789
# Cặp trường cùng nhận NaN, theo stage 0..4.
NAN_PAIRS = [
    [('unit', 'trail')],
    [('unit', 'trail'), ('sl', 'point')],
    [('sl', 'point')],
    [('sl', 'point'), ('unit', 'lock_extra')],
    [('sl', 'step_distance')],
]
SIDES = (0, 1)
# Khoảng bộ kiểm MQL5 xét; int32/int64/uint64/uint32 còn lại do struct giữ.
LIMITS = {
    'buy': (0, 1), 'stage': (0, 5), 'scenario': (0, 11), 'modify_ok': (0, 1),
    'passed_flag': (0, 255), 'eligible_flag': (0, 255),
    'before_open': (0, 255), 'shift_setting': (0, 255),
    'step_enabled': (0, 255), 'guard': (0, 255),
    'prior_changed': (0, 1), 'table_pattern': (0, 5), 'index': (0, 8),
}


def _name(value) -> str:
    """Nhãn ngắn của một giá trị, giữ dấu của 0 và payload NaN."""
    if isinstance(value, int):
        return str(value)
    if math.isnan(value):
        return f'nan{_bits(value):016x}'
    if value == 0.0:
        return '-0' if _bits(value) >> 63 else '+0'
    return repr(value)


def _around(value: float) -> tuple:
    """Double liền dưới, value, double liền trên (value hữu hạn, >= +0)."""
    if value == 0.0:
        return (_from_bits(0x8000000000000001), value,
                _from_bits(0x0000000000000001))
    bits = _bits(value)
    return _from_bits(bits - 1), value, _from_bits(bits + 1)


def _base(buy: int, stage: int) -> dict:
    """Ca gốc của một phía (buy 1 = mua, 0 = bán) và một stage."""
    is_buy = buy == 1
    return {
        'id': 0, 'buy': buy, 'stage': stage, 'scenario': 0,
        'modify_ok': 1, 'error_code': 4756,
        'digits0': 3, 'digits1': 3, 'digits2': 3, 'digits3': 3,
        'enabled': 1, 'gap_count': 1, 'minimum_steps': 2, 'counter': 1,
        'passed_flag': 1, 'eligible_flag': 1, 'before_open': 0,
        'shift_setting': 0, 'step_enabled': 1, 'guard': 1,
        'prior_changed': 0, 'table_pattern': 0,
        'ticket': 7, 'deviation': 11, 'index': 2, 'error_count': 0,
        'sl': 90.0 if is_buy else 110.0,
        'tp': 130.0 if is_buy else 70.0,
        'open_price': 100.0, 'volume': 0.1,
        'bid': 105.0 if is_buy else 95.0,
        'ask': 106.0 if is_buy else 96.0,
        'unit': 1.0, 'trail': 2.0, 'step': 0.5, 'start': 1.0, 'limit': 4.0,
        'reference': 100.0, 'anchor': 100.0, 'gap': 0.2, 'freeze': 2.5,
        'point': 0.01, 'minimum': 0.01, 'lock_start': 2.0, 'lock_extra': 1.0,
        'step_reference': POS_ZERO, 'step_distance': 1.0, 'copied_step': 0.5,
        'initial_stop': 90.0, 'ticket_number': 7.0, 'current_stop': 95.0,
        'volumes': [0.1 + i * 0.01 for i in range(ARRAY_SIZE)],
        'levels': [(95.0 if is_buy else 105.0) + i * 0.01
                   for i in range(ARRAY_SIZE)],
    }


def _make(buy: int, stage: int, category: str, changes: dict) -> dict:
    """Ca gốc cộng các thay đổi; group = 'nhóm/trường=giá trị,...'."""
    row = _base(buy, stage)
    for field, value in changes.items():
        if field == 'volumes[index]':
            row['volumes'][row['index']] = value
        elif field == 'levels[index]':
            row['levels'][row['index']] = value
        elif field in row:
            row[field] = value
        else:
            raise KeyError(f'unknown field {field}')
    detail = ','.join(f'{field}={_name(value)}'
                      for field, value in changes.items())
    row['group'] = f'{category}/{detail}' if detail else category
    return row


def _baseline():
    """Ca gốc cho mỗi stage 0..5 và mỗi phía."""
    for stage in range(6):
        for buy in SIDES:
            yield _make(buy, stage, 'baseline', {})


def _special():
    """Thay từng trường liên quan bằng từng giá trị đặc biệt (scenario 0)."""
    for stage, fields in enumerate(SPECIAL_FIELDS):
        for buy in SIDES:
            for field, value in itertools.product(fields, SPECIAL_VALUES):
                yield _make(buy, stage, 'special', {field: value})


def _scenario():
    """scenario × modify_ok × prior_changed, minimum +0 để nhánh Close chạy.

    Stage5 chỉ gọi DIGITS 3 lần nên chỉ dùng scenario 0, 1, 3, 4.
    """
    for stage in range(6):
        scenarios = (0, 1, 3, 4) if stage == 5 else range(12)
        for buy in SIDES:
            for scenario, modify_ok, prior in itertools.product(
                    scenarios, (0, 1), (0, 1)):
                yield _make(buy, stage, 'scenario', {
                    'scenario': scenario, 'modify_ok': modify_ok,
                    'prior_changed': prior, 'minimum': POS_ZERO})


def _stage0_volume():
    """Stage0: volumes[index] × minimum × volume (45 ca/phía)."""
    for buy in SIDES:
        for at_index, minimum, volume in itertools.product(
                (POS_INF, NAN_A, 0.1),
                (-0.01, NEG_ZERO, POS_ZERO, 0.01, NAN_B),
                (POS_ZERO, 0.1, POS_INF)):
            yield _make(buy, 0, 'volume', {
                'volumes[index]': at_index, 'minimum': minimum,
                'volume': volume})


def _stage0_deviation_ticket():
    """Stage0: deviation, ticket đổi riêng; mỗi giá trị với minimum gốc và +0."""
    for buy in SIDES:
        for minimum in (0.01, POS_ZERO):
            for deviation in (0, UINT64_MAX):
                yield _make(buy, 0, 'deviation', {
                    'deviation': deviation, 'minimum': minimum})
            for ticket in TICKETS:
                yield _make(buy, 0, 'ticket', {
                    'ticket': ticket, 'minimum': minimum})


def _stage1_flags():
    """Stage1: enabled × passed_flag (20 ca/phía)."""
    for buy in SIDES:
        for enabled, passed in itertools.product(
                (-1, 0, 1, 2), (0, 1, 2, 3, 255)):
            yield _make(buy, 1, 'flags', {
                'enabled': enabled, 'passed_flag': passed})


def _single_fields(buy: int, stage: int, fields: list):
    for field, values in fields:
        for value in values:
            yield _make(buy, stage, 'field', {field: value})


def _stage2_fields():
    """Stage2: đổi từng trường độc lập, không tích."""
    for buy in SIDES:
        yield from _single_fields(buy, 2, STAGE2_FIELDS)


def _stage4_fields():
    """Stage4: đổi từng trường độc lập; thêm counter INT_MAX với scenario 3."""
    for buy in SIDES:
        yield from _single_fields(buy, 4, STAGE4_FIELDS)
        yield _make(buy, 4, 'counter-wrap', {
            'counter': INT_MAX, 'scenario': 3})


def _stage5_table():
    """Stage5: table_pattern × guard × scenario (96 ca/phía)."""
    for buy in SIDES:
        for pattern, guard, scenario in itertools.product(
                range(6), (0, 1, 2, 255), (0, 1, 3, 4)):
            yield _make(buy, 5, 'table', {
                'table_pattern': pattern, 'guard': guard,
                'scenario': scenario})


def _stage5_ticket():
    """Stage5: ticket_number và ticket int64 đổi riêng."""
    for buy in SIDES:
        for value in (NEG_ZERO, POS_ZERO, float(2**53 + 2), NAN_A, POS_INF):
            yield _make(buy, 5, 'ticket-number', {'ticket_number': value})
        for ticket in TICKETS:
            yield _make(buy, 5, 'ticket', {'ticket': ticket})


def _index_digits():
    """Stage0..4: index 0, 8; bộ digits riêng với SL cộng 0.123456789."""
    for stage in range(5):
        for buy in SIDES:
            for index in (0, 8):
                yield _make(buy, stage, 'index', {'index': index})
            raised_sl = _base(buy, stage)['sl'] + SL_FRACTION
            for digits in DIGIT_SETS:
                changes = dict(zip(DIGIT_FIELDS, digits))
                changes['sl'] = raised_sl
                yield _make(buy, stage, 'digits', changes)


def _errors():
    """Stage0..3: error_count × (modify_ok 1, hoặc modify_ok 0 × error_code)."""
    for stage in range(4):
        for buy in SIDES:
            for error_count in (0, UINT32_MAX):
                yield _make(buy, stage, 'error', {
                    'error_count': error_count, 'modify_ok': 1})
                for error_code in (-1, 0, 4001, 4756):
                    yield _make(buy, stage, 'error', {
                        'error_count': error_count, 'modify_ok': 0,
                        'error_code': error_code})


def _nan_pairs():
    """Hai toán hạng cùng NaN, chạy cả hai thứ tự payload."""
    for stage, pairs in enumerate(NAN_PAIRS):
        for buy in SIDES:
            for (first, second), (first_nan, second_nan) in itertools.product(
                    pairs, ((NAN_A, NAN_B), (NAN_B, NAN_A))):
                yield _make(buy, stage, 'nan-pair', {
                    first: first_nan, second: second_nan})


def _sweeps():
    """Quét ±1 ulp: stage3 lock_start × lock_extra, stage4 gap."""
    for buy in SIDES:
        lock_center = 5.0 if buy == 1 else 4.0
        for lock_start, lock_extra in itertools.product(
                _around(lock_center), _around(0.0)):
            yield _make(buy, 3, 'lock-sweep', {
                'lock_start': lock_start, 'lock_extra': lock_extra})
    for buy in SIDES:
        for gap in _around(14.0 if buy == 1 else 13.0):
            yield _make(buy, 4, 'gap-sweep', {'gap': gap})


GROUPS = (
    _baseline, _special, _scenario, _stage0_volume, _stage0_deviation_ticket,
    _stage1_flags, _stage2_fields, _stage4_fields, _stage5_table,
    _stage5_ticket, _index_digits, _errors, _nan_pairs, _sweeps,
)


def cases() -> list:
    """Mọi ca theo thứ tự cố định, id liên tục từ 0; không cắt bớt ca."""
    rows = [row for group in GROUPS for row in group()]
    if len(rows) >= CASE_LIMIT:
        raise ValueError(f'{len(rows)} cases; must stay below {CASE_LIMIT}')
    for position, row in enumerate(rows):
        row['id'] = position
    return rows


def _check(rows: list) -> None:
    if not 1 <= len(rows) <= MAX_COUNT:
        raise ValueError(f'count {len(rows)} outside 1..{MAX_COUNT}')
    for position, row in enumerate(rows):
        if row['id'] != position:
            raise ValueError(f'row {position}: id {row["id"]} is not sequential')
        for name, (low, high) in LIMITS.items():
            if not low <= row[name] <= high:
                raise ValueError(
                    f'row {position}: {name}={row[name]} outside {low}..{high}')
        if len(row['volumes']) != ARRAY_SIZE or len(row['levels']) != ARRAY_SIZE:
            raise ValueError(
                f'row {position}: volumes/levels need {ARRAY_SIZE} values')


def encode(rows: list) -> bytes:
    """3 int32 đầu tệp (magic, version, count) rồi 456 byte mỗi ca."""
    _check(rows)
    parts = [HEADER.pack(MAGIC, VERSION, len(rows))]
    for row in rows:
        parts.append(CASE.pack(
            *[row[name] for name in INTS],
            row['ticket'], row['deviation'], row['index'], row['error_count'],
            *[row[name] for name in DOUBLES],
            *row['volumes'], *row['levels']))
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
