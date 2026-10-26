"""Ca kiểm thuần số cho Bot3RuntimeProfile.mqh.

Tệp chỉ tạo đầu vào; không chứa công thức mong đợi. Kết quả được lấy riêng
từ thân gốc và từ hàm MQL5 rồi so theo từng bit.
"""
import struct

MAGIC = 0x52504633
VERSION = 1
HEADER = struct.Struct("<3i")
CASE = struct.Struct("<2iI7d")
RESULT = struct.Struct("<3i32Q")

DELTA_NAMES = (
    "price_delta",
    "stop_delta",
    "target_delta",
    "trail_delta",
    "aux_delta",
    "lock_delta",
)


def _bits(value: int) -> float:
    return struct.unpack("<d", struct.pack("<Q", value))[0]


NAN_POSITIVE = _bits(0x7FF8000000000123)
NAN_NEGATIVE = _bits(0xFFF8000000000456)
SNAN_POSITIVE = _bits(0x7FF0000000000789)


def cases() -> list[dict]:
    rows = []
    next_id = 0
    seeds = (0, 1, 2, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF)
    randomizations = (-1.0, -0.0, 0.0, 1e-300, 1.0, 17.25, 1000.0, float("nan"), float("inf"))
    for index in range(9):
        for seed in seeds:
            for randomization in randomizations:
                rows.append({
                    "id": next_id,
                    "group": "randomization-and-seed",
                    "index": index,
                    "seed": seed,
                    "randomization": randomization,
                    "price_delta": 0.0,
                    "stop_delta": 0.0,
                    "target_delta": 0.0,
                    "trail_delta": 0.0,
                    "aux_delta": 0.0,
                    "lock_delta": 0.0,
                })
                next_id += 1

    delta_values = (-1e16, -0.1, 0.0, 0.1, 1e16, NAN_POSITIVE, NAN_NEGATIVE, SNAN_POSITIVE, float("inf"), float("-inf"))
    for index in range(9):
        for selected in DELTA_NAMES:
            for value in delta_values:
                for randomization in (0.0, 17.25, float("inf")):
                    row = {
                        "id": next_id,
                        "group": "delta-and-floating-order-" + selected,
                        "index": index,
                        "seed": 1,
                        "randomization": randomization,
                        "price_delta": 0.0,
                        "stop_delta": 0.0,
                        "target_delta": 0.0,
                        "trail_delta": 0.0,
                        "aux_delta": 0.0,
                        "lock_delta": 0.0,
                    }
                    row[selected] = value
                    rows.append(row)
                    next_id += 1
    if len(rows) != 2106 or any(row["id"] != i for i, row in enumerate(rows)):
        raise AssertionError("runtime profile case set changed")
    return rows


def encode(rows: list[dict]) -> bytes:
    output = bytearray(HEADER.pack(MAGIC, VERSION, len(rows)))
    for row in rows:
        output.extend(CASE.pack(
            row["id"], row["index"], row["seed"],
            row["randomization"], row["price_delta"], row["stop_delta"],
            row["target_delta"], row["trail_delta"], row["aux_delta"],
            row["lock_delta"],
        ))
    return bytes(output)


RESULT_NAMES = [
    "id", "fault", "untouched_changed", "random_seed", "native_6d324", "native_6d3c0",
    "entry_confirmation_frame", "entry_frame", "older_width", "recent_width", "last_shift",
    "gap_points", "buy_offset", "sell_offset", "nearby_radius", "expiration_hours",
    "stop_distance", "target_distance", "trail_distance", "trail_start", "trail_limit",
    "trail_step", "native_6d368", "native_6d370", "trigger_distance", "locked_distance",
    "aux_hour1", "aux_scan50", "aux_older", "aux_recent", "aux_offset", "indicator_period",
    "indicator_timeframe", "native_6d2e0", "management_timeframe",
]
if len(RESULT_NAMES) != 35:
    raise AssertionError("result name count changed")
