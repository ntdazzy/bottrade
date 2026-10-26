"""Ca đầu vào cố định cho Bot1ManagementRouterCheck.mq5.

Theo claude-thuc-hien/bot1-main-router-check-20261026-r1/TASK.md (đường dẫn từ
dich-nguoc/khoi-phuc/). cases.bin: đầu tệp 3 int32 (magic, version, count),
mỗi ca 88 byte `<14i4q` = 14 int32 (id, index, timeframe, after_first_frame,
buy_reply, sell_reply, change_first_bar, change_buy, license_valid,
tick_management, bar_override, profile, shrink_after_buy, magic) rồi 4 int64
(previous, observed, second, after_first_bar). Chỉ tạo đầu vào: không có thuật
toán điều phối, không có kết quả mong đợi, không dùng số ngẫu nhiên, không ghi
tệp. Cần Python 3.6 trở lên. Dùng: data = encode(cases()).
"""

import itertools
import struct

MAGIC = 0x4d525431
VERSION = 1
HEADER = struct.Struct("<3i")  # magic, version, count
CASE = struct.Struct("<14i4q")  # 14 int32 theo INTS, rồi 4 int64 theo LONGS
HEADER_SIZE = 12
RECORD_SIZE = 88
MAX_COUNT = 10000  # count hợp lệ của cases.bin: 1..10000

INTS = [
    "id",
    "index",
    "timeframe",
    "after_first_frame",
    "buy_reply",
    "sell_reply",
    "change_first_bar",
    "change_buy",
    "license_valid",
    "tick_management",
    "bar_override",
    "profile",
    "shrink_after_buy",
    "magic",
]
LONGS = ["previous", "observed", "second", "after_first_bar"]

INT32 = (-(2**31), 2**31 - 1)
INT64 = (-(2**63), 2**63 - 1)
FLAG = (0, 1)
# Miền script kiểm; trường khác chỉ cần nằm trong độ rộng có dấu của nó.
RANGES = {
    "index": (0, 7),
    "profile": (0, 7),
    "buy_reply": FLAG,
    "sell_reply": FLAG,
    "change_first_bar": FLAG,
    "change_buy": FLAG,
    "license_valid": FLAG,
    "tick_management": FLAG,
    "bar_override": FLAG,
    "shrink_after_buy": FLAG,
}

# Các trục tích Descartes, đúng thứ tự TASK; trục đầu đổi chậm nhất.
LICENSE_VALID = (0, 1)
ROUTE_FLAGS = ((0, 0), (1, 0), (1, 1))  # (tick_management, bar_override)
PROFILES = range(8)
TIMES = ((1000, 1000, 1100), (1000, 1100, 1200))  # (previous, observed, second)
FLAGS = (0, 1)  # lần lượt cho buy_reply, sell_reply, change_buy, shrink_after_buy
TIMEFRAME = 15
AFTER_FIRST_FRAME = 16385
AFTER_FIRST_BAR = 5000
CASE_MAGIC = 123  # ca có id % 3 == 0 dùng -CASE_MAGIC


def _field(row: dict, name: str) -> int:
    """Một trường số nguyên của ca, đã kiểm có mặt, kiểu và miền."""
    if name not in row:
        raise ValueError(f"ca {row.get('id')}: thiếu trường {name}")
    value = row[name]
    if type(value) is not int:
        raise TypeError(f"ca {row.get('id')}: {name}={value!r} không phải int")
    low, high = RANGES.get(name, INT64 if name in LONGS else INT32)
    if not low <= value <= high:
        raise ValueError(f"ca {row.get('id')}: {name}={value} ngoài {low}..{high}")
    return value


def cases() -> list:
    """1536 ca theo thứ tự tích Descartes của TASK, id liên tục từ 0.

    Trục lặp, ngoài cùng trước: license_valid, (tick_management, bar_override),
    profile, (previous, observed, second), buy_reply, sell_reply, change_buy,
    shrink_after_buy. Theo id: index = (id % 3) * 3, change_first_bar = id % 2,
    magic = -123 khi id % 3 == 0, ngược lại 123. timeframe 15,
    after_first_frame 16385, after_first_bar 5000. Mỗi lần gọi tạo dict mới;
    group chỉ ghép giá trị đầu vào của bốn trục đầu, không ghi vào cases.bin.
    """
    rows = []
    axes = itertools.product(LICENSE_VALID, ROUTE_FLAGS, PROFILES, TIMES,
                             FLAGS, FLAGS, FLAGS, FLAGS)
    for (license_valid, route_flags, profile, times,
         buy_reply, sell_reply, change_buy, shrink_after_buy) in axes:
        tick_management, bar_override = route_flags
        previous, observed, second = times
        case_id = len(rows)
        rows.append({
            "id": case_id,
            "index": (case_id % 3) * 3,
            "timeframe": TIMEFRAME,
            "after_first_frame": AFTER_FIRST_FRAME,
            "buy_reply": buy_reply,
            "sell_reply": sell_reply,
            "change_first_bar": case_id % 2,
            "change_buy": change_buy,
            "license_valid": license_valid,
            "tick_management": tick_management,
            "bar_override": bar_override,
            "profile": profile,
            "shrink_after_buy": shrink_after_buy,
            "magic": -CASE_MAGIC if case_id % 3 == 0 else CASE_MAGIC,
            "previous": previous,
            "observed": observed,
            "second": second,
            "after_first_bar": AFTER_FIRST_BAR,
            "group": (f"license{license_valid}/route{tick_management}{bar_override}"
                      f"/profile{profile}/times{previous}-{observed}-{second}"),
        })
    return rows


def encode(rows: list) -> bytes:
    """Nội dung cases.bin: header 3 int32 rồi mỗi ca một bản ghi 88 byte.

    Giữ đúng thứ tự rows. Kiểm count, id liên tục, kiểu int, miền index,
    profile, cờ và độ rộng có dấu; sai thì báo lỗi, không sửa ca.
    """
    count = len(rows)
    if not 1 <= count <= MAX_COUNT:
        raise ValueError(f"count={count} ngoài 1..{MAX_COUNT}")
    data = bytearray(HEADER.pack(MAGIC, VERSION, count))
    for position, row in enumerate(rows):
        if _field(row, "id") != position:
            raise ValueError(f"ca thứ {position} có id={row['id']}; id phải liên tục từ 0")
        record = CASE.pack(*(_field(row, name) for name in INTS + LONGS))
        if len(record) != RECORD_SIZE:
            raise ValueError(f"ca {position}: bản ghi {len(record)} byte, cần {RECORD_SIZE}")
        data += record
    expected = HEADER_SIZE + RECORD_SIZE * count
    if len(data) != expected:
        raise ValueError(f"cases.bin dài {len(data)} byte, cần {expected}")
    return bytes(data)


if __name__ == "__main__":
    rows = cases()
    print(f"total {len(rows)} cases, {len(encode(rows))} bytes")
