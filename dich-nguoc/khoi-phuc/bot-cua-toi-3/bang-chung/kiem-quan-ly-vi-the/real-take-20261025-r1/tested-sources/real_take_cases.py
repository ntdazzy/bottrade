"""Fixed input cases for Bot3ManagementRealTakeCheck.mq5 (cases.bin).

Only inputs are produced: no expected results, no bot logic, no randomness.
encode(cases()) returns the whole file: a 3 x int32 header followed by one
244-byte CASE record per case.
"""

import math
import struct

MAGIC = 0x4D525033
VERSION = 1
HEADER = struct.Struct('<3i')
CASE = struct.Struct('<8iqQIII23d')

INTS = ['id', 'buy', 'scenario', 'modify_ok', 'error_code',
        'digits0', 'digits1', 'digits2']
DOUBLES = ['sl', 'tp', 'open_price', 'volume', 'bid', 'ask', 'unit',
           'distance', 'start', 'anchor', 'gap', 'freeze', 'point',
           'minimum']
VOLUME_COUNT = 9

_INT_KEYS = INTS + ['ticket', 'deviation', 'index', 'error_count',
                    'prior_changed']
_KEYS = sorted(_INT_KEYS + DOUBLES + ['volumes', 'group'])
_MAX_CASES = 1499


def _from_bits(bits):
    return struct.unpack('<d', struct.pack('<Q', bits))[0]


NAN_POS_BITS = 0x7FF8000000000123
NAN_NEG_BITS = 0xFFF8000000000456
NAN_POS = _from_bits(NAN_POS_BITS)
NAN_NEG = _from_bits(NAN_NEG_BITS)
NEG_ZERO = _from_bits(0x8000000000000000)
INT32_MIN = -2 ** 31
INT32_MAX = 2 ** 31 - 1

# Labelled values: (value, text used in the case group).
_NAN_POS = (NAN_POS, 'nan(0x%016x)' % NAN_POS_BITS)
_NAN_NEG = (NAN_NEG, 'nan(0x%016x)' % NAN_NEG_BITS)
_NEG_ZERO = (NEG_ZERO, '-0')
_POS_ZERO = (0.0, '+0')
_BASE_MINIMUM = (0.01, '0.01')
# minimum 0 so that Close can be called.
_CLOSE_MINIMUM = _POS_ZERO
_MINIMUM_PATHS = (_BASE_MINIMUM, _CLOSE_MINIMUM)

_SWEEP = (
    (-math.inf, '-inf'),
    (-1e19, '-1e19'),
    (-100.125, '-100.125'),
    _NEG_ZERO,
    _POS_ZERO,
    (0.01, '0.01'),
    (100.125, '100.125'),
    (1e19, '1e19'),
    (math.inf, '+inf'),
    _NAN_POS,
    _NAN_NEG,
)

_GATE_MINIMUM = ((-0.01, '-0.01'), _NEG_ZERO, _POS_ZERO, _BASE_MINIMUM,
                 _NAN_POS)
_GATE_VOLUME = ((-0.1, '-0.1'), _NEG_ZERO, _POS_ZERO, (0.1, '0.1'),
                (math.inf, '+inf'), _NAN_NEG)
_GATE_CELL = ((0.1, '0.1'), (math.inf, '+inf'), _NAN_POS)
# Mutate targets beside the volume gate: VOLUME_MIN and TryClose.
_GATE_SCENARIOS = (6, 8)

_INDEX_EDGES = (0, 8)
# Every value differs from all base cells .1 + i * .01.
_INDEX_CELL = ((1.0, '1'), (math.inf, '+inf'), _NAN_POS)

_DIGITS = ((-1, 0, 1), (0, 1, 2), (2, 8, 3), (11, 10, 9), (12, 3, 0),
           (INT32_MIN, INT32_MAX, -1), (3, 3, 3))
_TP_FRACTION = 0.123456789

_TICKETS = (0, 1, 2 ** 53 + 1, 2 ** 63 - 1, -2 ** 63, -1)
_DEVIATION_MAX = 2 ** 64 - 1
_DEVIATIONS = (0, 11, _DEVIATION_MAX)
_ERROR_COUNTS = (0, 2 ** 32 - 1)
_ERROR_CODES = (0, 4001, 4756, -1)

_NAN_PAIRS = (('unit', 'distance'), ('start', 'anchor'), ('tp', 'point'))

_BASE_INDEX = 2
_COMMON = {
    'scenario': 0, 'modify_ok': 1, 'error_code': 4756,
    'digits0': 3, 'digits1': 3, 'digits2': 3,
    'ticket': 7, 'deviation': 11, 'index': _BASE_INDEX,
    'error_count': 0, 'prior_changed': 0,
    'gap': 0.2, 'freeze': 2.5, 'point': 0.01, 'minimum': _BASE_MINIMUM[0],
}

# (name, buy, side prices, near-threshold points as (gate, field, value))
_SIDES = (
    ('buy', 1,
     {'sl': 90.0, 'tp': 130.0, 'open_price': 100.0, 'volume': 0.1,
      'bid': 105.0, 'ask': 106.0, 'unit': 1.0, 'distance': 2.0,
      'start': 2.0, 'anchor': 115.0},
     (('gate1', 'tp', 108.01), ('gate2', 'anchor', 108.0),
      ('freeze', 'tp', 107.5), ('final', 'gap', 1.0))),
    ('sell', 0,
     {'sl': 110.0, 'tp': 70.0, 'open_price': 100.0, 'volume': 0.1,
      'bid': 95.0, 'ask': 96.0, 'unit': 1.0, 'distance': 2.0,
      'start': 2.0, 'anchor': 85.0},
     (('gate1', 'tp', 92.99), ('gate2', 'anchor', 93.0),
      ('freeze', 'tp', 92.5), ('final', 'gap', 2.0))),
)


def _row(name, buy, prices, group, cells, fields):
    row = {'id': None, 'buy': buy}
    row.update(_COMMON)
    row.update(prices)
    row['volumes'] = [0.1 + i * 0.01 for i in range(VOLUME_COUNT)]
    for key, value in fields.items():
        if key in ('id', 'buy', 'volumes') or key not in row:
            raise KeyError(key)
        row[key] = value
    # Cells are written last, so no computed value replaces a NaN.
    for cell, value in cells:
        row['volumes'][cell] = value
    row['group'] = '%s.%s' % (name, group)
    return row


def _side_cases(name, buy, prices, thresholds):
    rows = []

    def add(group, cells=(), **fields):
        rows.append(_row(name, buy, prices, group, cells, fields))

    add('base')

    # One field per case; volumes[2] is the cell read at the base index.
    for field in DOUBLES:
        for value, label in _SWEEP:
            add('sweep:%s=%s' % (field, label), **{field: value})
    for value, label in _SWEEP:
        add('sweep:volumes[%d]=%s' % (_BASE_INDEX, label),
            cells=((_BASE_INDEX, value),))

    for scenario in range(9):
        for modify_ok in (1, 0):
            for prior_changed in (0, 1):
                for minimum, minimum_label in _MINIMUM_PATHS:
                    add('state:scenario=%d,modify_ok=%d,prior_changed=%d,'
                        'minimum=%s' % (scenario, modify_ok, prior_changed,
                                        minimum_label),
                        scenario=scenario, modify_ok=modify_ok,
                        prior_changed=prior_changed, minimum=minimum)

    for minimum, minimum_label in _GATE_MINIMUM:
        for volume, volume_label in _GATE_VOLUME:
            for cell, cell_label in _GATE_CELL:
                add('gate:minimum=%s,volume=%s,volumes[%d]=%s'
                    % (minimum_label, volume_label, _BASE_INDEX, cell_label),
                    cells=((_BASE_INDEX, cell),),
                    minimum=minimum, volume=volume)
    for scenario in _GATE_SCENARIOS:
        for minimum, minimum_label in _MINIMUM_PATHS:
            for cell, cell_label in _GATE_CELL:
                add('gate:scenario=%d,minimum=%s,volumes[%d]=%s'
                    % (scenario, minimum_label, _BASE_INDEX, cell_label),
                    cells=((_BASE_INDEX, cell),),
                    scenario=scenario, minimum=minimum)

    for index in _INDEX_EDGES:
        for scenario in range(9):
            for minimum, minimum_label in _MINIMUM_PATHS:
                add('index:index=%d,scenario=%d,minimum=%s'
                    % (index, scenario, minimum_label),
                    index=index, scenario=scenario, minimum=minimum)
    for index in range(VOLUME_COUNT):
        for cell, cell_label in _INDEX_CELL:
            for minimum, minimum_label in _MINIMUM_PATHS:
                add('cell:index=%d,volumes[%d]=%s,minimum=%s'
                    % (index, index, cell_label, minimum_label),
                    cells=((index, cell),), index=index, minimum=minimum)

    for digits in _DIGITS:
        add('digits:digits=(%d,%d,%d),tp=%r+%r'
            % (digits + (prices['tp'], _TP_FRACTION)),
            tp=prices['tp'] + _TP_FRACTION,
            digits0=digits[0], digits1=digits[1], digits2=digits[2])

    for ticket in _TICKETS:
        for minimum, minimum_label in _MINIMUM_PATHS:
            add('ticket:ticket=%d,minimum=%s' % (ticket, minimum_label),
                ticket=ticket, minimum=minimum)
    for deviation in _DEVIATIONS:
        for minimum, minimum_label in _MINIMUM_PATHS:
            add('deviation:deviation=%d,minimum=%s'
                % (deviation, minimum_label),
                deviation=deviation, minimum=minimum)
    close_minimum, close_label = _CLOSE_MINIMUM
    for scenario in range(1, 9):
        add('deviation:deviation=%d,minimum=%s,scenario=%d'
            % (_DEVIATION_MAX, close_label, scenario),
            deviation=_DEVIATION_MAX, minimum=close_minimum,
            scenario=scenario)
    for error_count in _ERROR_COUNTS:
        for error_code in _ERROR_CODES:
            for modify_ok in (1, 0):
                add('error:error_count=%d,error_code=%d,modify_ok=%d'
                    % (error_count, error_code, modify_ok),
                    error_count=error_count, error_code=error_code,
                    modify_ok=modify_ok)

    for gate, field, value in thresholds:
        for near, step in ((math.nextafter(value, -math.inf), '-1ulp'),
                           (value, ''),
                           (math.nextafter(value, math.inf), '+1ulp')):
            add('threshold.%s:%s=%r%s' % (gate, field, value, step),
                **{field: near})

    for first, second in _NAN_PAIRS:
        for (a, a_label), (b, b_label) in ((_NAN_POS, _NAN_NEG),
                                           (_NAN_NEG, _NAN_POS)):
            add('nanpair:%s=%s,%s=%s' % (first, a_label, second, b_label),
                **{first: a, second: b})

    return rows


def _check(rows):
    if not 0 < len(rows) <= _MAX_CASES:
        raise ValueError('case count %d' % len(rows))
    for case_id, row in enumerate(rows):
        if sorted(row) != _KEYS or len(row['volumes']) != VOLUME_COUNT:
            raise ValueError('case %d: wrong fields' % case_id)
        doubles = [row[key] for key in DOUBLES] + row['volumes']
        if (row['id'] != case_id
                or any(type(row[key]) is not int for key in _INT_KEYS)
                or any(type(value) is not float for value in doubles)
                or type(row['group']) is not str
                or row['buy'] not in (0, 1)
                or not 0 <= row['scenario'] <= 8
                or row['modify_ok'] not in (0, 1)
                or not 0 <= row['index'] < VOLUME_COUNT
                or row['prior_changed'] not in (0, 1)):
            raise ValueError('case %d: wrong value (%s)'
                             % (case_id, row['group']))


def cases():
    """Return new case dicts, ids 0..n-1, checked before return."""
    rows = []
    for name, buy, prices, thresholds in _SIDES:
        rows.extend(_side_cases(name, buy, prices, thresholds))
    for case_id, row in enumerate(rows):
        row['id'] = case_id
    _check(rows)
    return rows


def encode(rows):
    """Pack rows exactly as cases.bin.

    Value rules are checked by cases(), not here, so files with invalid
    values can still be built when the script's error handling is tested.
    """
    parts = [HEADER.pack(MAGIC, VERSION, len(rows))]
    for row in rows:
        volumes = row['volumes']
        if len(volumes) != VOLUME_COUNT:
            raise ValueError('case %r: %d volumes'
                             % (row['id'], len(volumes)))
        parts.append(CASE.pack(
            *[row[key] for key in INTS],
            row['ticket'], row['deviation'], row['index'],
            row['error_count'], row['prior_changed'],
            *[row[key] for key in DOUBLES],
            *volumes))
    return b''.join(parts)
