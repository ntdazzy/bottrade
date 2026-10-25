"""Ca đầu vào cố định cho Bot3PositionManagementFlowCheck.mq5.

Theo CONTRACT.md ở thư mục bot3-manager-flow-check-20261025-r1. Tệp này chỉ tạo
cases.bin và fixture khởi tạo: settings, vị thế sống, lời đáp tick,
StopLevel/TakeLevel và VOLUME_MIN. Không có thuật toán manager, không có kết quả
mong đợi, không dùng số ngẫu nhiên. Cần Python 3.9 trở lên.
"""

import itertools
import struct

MAGIC = 0x4d504d33
VERSION = 1
HEADER = struct.Struct("<3i")  # magic, version, count
CASE = struct.Struct("<20iI")  # 20 int32 theo INTS, rồi uint32 error_count
HEADER_SIZE = 12
RECORD_SIZE = 84
MAX_COUNT = 10000  # count hợp lệ của cases.bin: 1..10000
MAX_CASES = 800  # tổng ca vượt mức này thì báo lỗi, không cắt bớt

INT32_MIN = -(2**31)
INT32_MAX = 2**31 - 1
UINT32_MAX = 2**32 - 1

INTS = [
    "id",
    "buy",
    "profile",
    "position_count",
    "mode",
    "flip_digit",
    "flip_mode",
    "eligible_initial",
    "eligible_after_total",
    "tick_ok",
    "modify_ok",
    "close_ok",
    "delay_pass",
    "digits",
    "index",
    "enabled",
    "magic",
    "error_code",
    "counter",
    "ticket_kind",
]

# Miền CONTRACT kiểm; trường không có ở đây chỉ cần nằm trong int32.
RANGES = {
    "buy": (0, 1),
    "profile": (0, 22),
    "position_count": (0, 3),
    "mode": (-1, 3),
    "flip_digit": (0, 30),
    "flip_mode": (-1, 3),
    "eligible_initial": (0, 255),
    "eligible_after_total": (0, 255),
    "tick_ok": (0, 1),
    "modify_ok": (0, 1),
    "close_ok": (0, 1),
    "delay_pass": (0, 1),
    "index": (0, 8),
    "ticket_kind": (0, 1),
    "error_count": (0, UINT32_MAX),
}

# Giá trị dùng khi nhóm không nêu trường đó.
DEFAULTS = {
    "mode": 0,
    "position_count": 1,
    "flip_digit": 0,
    "flip_mode": 2,
    "eligible_initial": 0,
    "eligible_after_total": 1,
    "tick_ok": 1,
    "modify_ok": 1,
    "close_ok": 1,
    "delay_pass": 0,
    "digits": 3,
    "index": 2,
    "enabled": 1,
    "magic": 9001,
    "error_code": 4756,
    "counter": 1,
    "ticket_kind": 0,
    "error_count": 0,
}

BUYS = (0, 1)
MODES = (0, 2)
FLIP_MODE = {0: 2, 2: 0}  # modeflip: flip_mode ngược mode ban đầu
# Ticket theo hàng khi ticket_kind 1: 2^53+1, 2^63-1, 2^64-1 (ulong).
TICKETS64 = (9007199254740993, 9223372036854775807, 18446744073709551615)


def _field(row: dict, name: str) -> int:
    """Một trường số nguyên của ca, đã kiểm kiểu và miền."""
    value = row[name]
    if type(value) is not int:
        raise TypeError(f"ca {row.get('id')}: {name}={value!r} không phải int")
    low, high = RANGES.get(name, (INT32_MIN, INT32_MAX))
    if not low <= value <= high:
        raise ValueError(f"ca {row.get('id')}: {name}={value} ngoài {low}..{high}")
    return value


def _grid(profiles: tuple[int, ...], position_count: int, **fixed: int) -> list[dict]:
    """profile × buy × mode của một nhóm, kèm các trường cố định."""
    return [
        {"profile": profile, "buy": buy, "mode": mode, "position_count": position_count, **fixed}
        for profile, buy, mode in itertools.product(profiles, BUYS, MODES)
    ]


def _groups() -> list[tuple[str, list[dict]]]:
    """Các nhóm độc lập, đúng thứ tự TASK.md."""
    return [
        ("baseline", _grid(tuple(range(23)), 1)),
        ("multipos", _grid((0, 1, 2, 3, 4, 5, 6, 7, 8, 14, 20, 21), 3)),
        ("empty", _grid((0,), 0)),
        (
            "modeflip",
            [
                {**spec, "flip_digit": digit, "flip_mode": FLIP_MODE[spec["mode"]]}
                for spec in _grid((0, 14), 2)
                for digit in range(1, 10)
            ],
        ),
        (
            "eligibility",
            [
                {**spec, "eligible_after_total": after}
                for spec in _grid((18,), 3)
                for after in (0, 1)
            ],
        ),
        ("modifyfalse", _grid((6, 14, 15, 16, 17, 18, 19, 20, 21), 2, modify_ok=0)),
        ("close_replyfalse", _grid((8, 9, 10, 11, 12, 13, 22), 3, close_ok=0)),
        ("ticket64", _grid((0, 6, 9, 10, 12, 15, 16, 20), 3, ticket_kind=1)),
        ("tickfalse", _grid((0, 9, 12, 14), 2, tick_ok=0)),
        (
            "error_countwrap",
            _grid((14, 15, 17, 18, 19), 1, modify_ok=0, error_code=-1, error_count=UINT32_MAX),
        ),
    ]


def cases() -> list[dict]:
    """Mọi ca theo thứ tự nhóm, id liên tục từ 0; mỗi lần gọi tạo dict mới.

    Mỗi dict có 20 trường INTS, error_count và group. Không cắt bớt ca;
    tổng vượt MAX_CASES thì báo ValueError kèm số đếm từng nhóm.
    """
    groups = _groups()
    total = sum(len(specs) for _, specs in groups)
    if total > MAX_CASES:
        counts = ", ".join(f"{group}={len(specs)}" for group, specs in groups)
        raise ValueError(f"tổng {total} ca > {MAX_CASES} ({counts})")
    rows = []
    for group, specs in groups:
        for spec in specs:
            values = {"id": len(rows), **DEFAULTS, **spec}
            row = {name: values[name] for name in INTS}
            row["error_count"] = values["error_count"]
            row["group"] = group
            rows.append(row)
    return rows


def encode(rows: list[dict]) -> bytes:
    """Nội dung cases.bin: header 3 int32 rồi mỗi ca một bản ghi 84 byte."""
    count = len(rows)
    if not 1 <= count <= MAX_COUNT:
        raise ValueError(f"count={count} ngoài 1..{MAX_COUNT}")
    data = bytearray(HEADER.pack(MAGIC, VERSION, count))
    for position, row in enumerate(rows):
        if _field(row, "id") != position:
            raise ValueError(f"ca thứ {position} có id={row['id']}; id phải liên tục từ 0")
        data += CASE.pack(*(_field(row, name) for name in INTS), _field(row, "error_count"))
    expected = HEADER_SIZE + RECORD_SIZE * count
    if len(data) != expected:
        raise ValueError(f"cases.bin dài {len(data)} byte, cần {expected}")
    return bytes(data)


def settings(c: dict) -> dict:
    """Settings khởi tạo của ca dạng dict phẳng (bỏ tiền tố finish.).

    Chỉ là giá trị trước khi chạy: high_low_eligible = eligible_initial,
    mode = mode ban đầu; thay đổi do API giả lúc chạy không nằm ở đây.
    """
    profile = _field(c, "profile")
    values = {
        "symbol": "CHECK",
        "magic": _field(c, "magic"),
        "enabled": _field(c, "enabled"),
        "unit": 1.0,
        "stop_distance": 10.0,
        "take_distance": 20.0,
        "emergency_offset": 0.5,
        "gap": 0.2,
        "freeze": 2.5,
        "candle_enabled3": [0, 0, 0],
        "candle_timeframe3": [0, 0, 0],
        "candle_shift": 0,
        "anchor_limit": 1,
        "use_anchor": 0,
        "high_low_eligible": _field(c, "eligible_initial"),
        "timed_activation": 0,
        "timed_distance": 0.0,
        "timed_delay_seconds": 60,
        "virtual_delay_seconds": 7,
        "trail": 0.0,
        "trail_step": 0.0,
        "trail_start": 0.0,
        "trail_limit": 0.0,
        "take_trail_distance": 0.0,
        "take_trail_start": 0.0,
        "slippage_enabled": 0,
        "slippage_trail": 0.0,
        "slippage_start": 0.0,
        "slippage_limit": 0.0,
        "high_low_gap_count": 0,
        "high_low_enabled": 0,
        "high_low_before_open": 0,
        "high_low_shift": 0,
        "high_low_buy_shift": 10.0,
        "high_low_sell_shift": 10.0,
        "lock_start": 0.0,
        "lock_extra": 0.0,
        "mode": _field(c, "mode"),
        "step_enabled": 0,
        "step_reference": 0.0,
        "min_steps": 2,
        "step_distance": 0.0,
    }
    if profile == 5:
        values["enabled"] = 0
    if profile in (7, 8):  # chỉ nhóm nến 0 bật, nhóm 1 và 2 giữ 0
        values["candle_enabled3"] = [1, 0, 0]
        values["candle_timeframe3"] = [15, 0, 0]
        values["candle_shift"] = 1
    if profile == 9:
        values["emergency_offset"] = 0.0
        values["stop_distance"] = 0.1
    # Profile 21 gộp settings của 14..20; profile 22 dùng settings của 15.
    if profile in (14, 21):
        values.update(timed_activation=1, timed_distance=2.0)
    if profile in (15, 21, 22):
        values.update(trail=2.0, trail_step=0.5, trail_start=1.0, trail_limit=4.0)
    if profile in (16, 21):
        values.update(take_trail_distance=2.0, take_trail_start=-12.0)
    if profile in (17, 21):
        values.update(
            slippage_enabled=1,
            slippage_trail=2.0,
            slippage_start=-12.0,
            slippage_limit=4.0,
            anchor_limit=-1,
        )
    if profile in (18, 21):
        values.update(
            high_low_enabled=1, high_low_gap_count=1, high_low_before_open=0, high_low_shift=0
        )
    if profile in (19, 21):
        values.update(lock_start=2.0, lock_extra=1.0)
    if profile in (20, 21):
        values.update(step_enabled=1, step_distance=1.0, min_steps=2, step_reference=0.0)
    return values


def positions(c: dict) -> list[dict]:
    """position_count vị thế sống đầu vào của ca, đã áp profile."""
    profile = _field(c, "profile")
    buy = _field(c, "buy") == 1
    magic = _field(c, "magic")
    ticket_kind = _field(c, "ticket_kind")
    rows = [
        {
            "ticket": TICKETS64[i] if ticket_kind == 1 else 7 + i,
            "type": 0 if buy else 1,
            "magic": magic,
            "opened": 1000,
            "sl": 90.0 if buy else 110.0,
            "tp": 130.0 if buy else 70.0,
            "open": 100.0,
            "volume": 0.1,
            "comment": "note",
            "symbol": "CHECK",
        }
        for i in range(_field(c, "position_count"))
    ]
    if rows:  # profile 1..4 chỉ sửa hàng 0
        if profile == 1:
            rows[0]["ticket"] = 0
        elif profile == 2:
            rows[0]["type"] = 1 if buy else 0
        elif profile == 3:
            rows[0]["magic"] = magic + 1  # int64; magic int32 nên không tràn
        elif profile == 4:
            rows[0]["symbol"] = "OTHER"
    for row in rows:
        if profile == 6:
            row["sl"] = 0.0
            row["tp"] = 0.0
        elif profile == 11:  # chỉ đổi SL, không đổi lời đáp StopLevel
            row["sl"] = 106.0 if buy else 95.0
    return rows


def tick_reply(c: dict) -> tuple[float, float]:
    """(bid, ask) SymbolInfoTick giả trả; độc lập với tick_ok và tick ban đầu."""
    buy = _field(c, "buy") == 1
    if _field(c, "profile") == 9:
        return (95.0, 96.0) if buy else (104.0, 105.0)
    return (105.0, 106.0) if buy else (95.0, 96.0)


def levels_reply(c: dict) -> tuple[float, float]:
    """(stop, take) mà Bot3VirtualStopLevel và Bot3VirtualTakeLevel giả trả."""
    profile = _field(c, "profile")
    buy = _field(c, "buy") == 1
    bid, ask = tick_reply(c)
    stop = 95.0 if buy else 105.0
    take = 120.0 if buy else 80.0
    if profile == 10:
        stop = 106.0 if buy else 95.0
    elif profile == 12:
        stop = bid if buy else ask
    elif profile == 13:
        take = bid if buy else ask
    return stop, take


def minimum_reply(c: dict) -> float:
    """SYMBOL_VOLUME_MIN giả trả: profile 22 là 0, profile khác 0.01."""
    return 0.0 if _field(c, "profile") == 22 else 0.01
