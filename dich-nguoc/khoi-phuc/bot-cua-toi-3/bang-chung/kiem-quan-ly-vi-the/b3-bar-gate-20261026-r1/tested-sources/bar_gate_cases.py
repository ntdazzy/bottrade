"""Ca đầu vào cố định cho Bot3ManagementBarGateCheck.mq5.

Theo claude-thuc-hien/bot3-newbar-check-20261026-r1/TASK.md (đường dẫn từ
dich-nguoc/khoi-phuc/). cases.bin: đầu tệp 3 int32 (magic, version, count),
mỗi ca 64 byte `<8i4q` = 8 int32 (id, index, timeframe, after_first_frame,
buy_reply, sell_reply, change_first_bar, change_buy) rồi 4 int64 (previous,
observed, second, after_first_bar). Chỉ tạo đầu vào: không có thuật toán
helper, không có kết quả mong đợi, không dùng số ngẫu nhiên, không ghi tệp.
Cần Python 3.6 trở lên. Dùng: data = encode(cases()).
"""

import itertools
import struct

MAGIC = 0x4d424733
VERSION = 1
HEADER = struct.Struct("<3i")  # magic, version, count
CASE = struct.Struct("<8i4q")  # 8 int32 theo INTS, rồi 4 int64 theo LONGS
HEADER_SIZE = 12
RECORD_SIZE = 64
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
]
LONGS = ["previous", "observed", "second", "after_first_bar"]

INT32 = (-(2**31), 2**31 - 1)
INT64 = (-(2**63), 2**63 - 1)
# Miền script kiểm; trường khác chỉ cần nằm trong độ rộng có dấu của nó.
RANGES = {
    "index": (0, 8),
    "buy_reply": (0, 1),
    "sell_reply": (0, 1),
    "change_first_bar": (0, 1),
    "change_buy": (0, 1),
}

# Các trục tích Descartes, đúng thứ tự TASK; trục đầu đổi chậm nhất.
INDEXES = (0, 4, 8)
FRAMES = ((15, 16385), (0, 15))  # (timeframe, after_first_frame)
TIMES = ((0, 0, 5), (1000, 1000, 1100), (1000, 1100, 1200), (1000, 0, 1300))  # (previous, observed, second)
FLAGS = (0, 1)  # lần lượt cho change_first_bar, change_buy, buy_reply, sell_reply
AFTER_FIRST_BAR = 5000


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
    """384 ca theo thứ tự tích Descartes của TASK, id liên tục từ 0.

    Trục lặp, ngoài cùng trước: index, (timeframe, after_first_frame),
    (previous, observed, second), change_first_bar, change_buy, buy_reply,
    sell_reply. after_first_bar luôn 5000. Mỗi lần gọi tạo dict mới; group
    chỉ ghép giá trị đầu vào của ba trục đầu.
    """
    rows = []
    axes = itertools.product(INDEXES, FRAMES, TIMES, FLAGS, FLAGS, FLAGS, FLAGS)
    for index, frames, times, change_first_bar, change_buy, buy_reply, sell_reply in axes:
        timeframe, after_first_frame = frames
        previous, observed, second = times
        rows.append({
            "id": len(rows),
            "index": index,
            "timeframe": timeframe,
            "after_first_frame": after_first_frame,
            "buy_reply": buy_reply,
            "sell_reply": sell_reply,
            "change_first_bar": change_first_bar,
            "change_buy": change_buy,
            "previous": previous,
            "observed": observed,
            "second": second,
            "after_first_bar": AFTER_FIRST_BAR,
            "group": f"index{index}/frame{timeframe}/times{previous}-{observed}-{second}",
        })
    return rows


def encode(rows: list) -> bytes:
    """Nội dung cases.bin: header 3 int32 rồi mỗi ca một bản ghi 64 byte.

    Kiểm count, id liên tục, kiểu int, miền index/cờ và độ rộng có dấu; sai
    thì báo lỗi, không sửa ca.
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
