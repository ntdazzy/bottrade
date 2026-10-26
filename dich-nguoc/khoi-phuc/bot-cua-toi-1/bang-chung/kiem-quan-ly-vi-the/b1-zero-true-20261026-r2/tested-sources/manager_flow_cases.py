"""Ca đầu vào cố định cho Bot1PositionManagementFlowCheck.mq5.

Theo claude-thuc-hien/bot1-manager-flow-check-20261026-r1/TASK.md (đường dẫn
từ dich-nguoc/khoi-phuc/). Dùng lại nhà máy ca Bot3 cố định
bot-cua-toi-3/tests/manager_flow_cases.py rồi đổi cho Bot1: bỏ profile 16
(chốt lời dời, Bot1 không có), id mới liên tục, index %= 8, magic 0x4d504d31;
settings bỏ take trail và candle_shift, nến 2 nhóm; levels_reply chỉ trả mức
dừng. Chỉ tạo cases.bin và fixture khởi tạo: không có thuật toán manager,
không có kết quả mong đợi. Cần Python 3.9 trở lên. Dùng: data = encode(cases()).
"""

import copy
import importlib.util
import struct
from pathlib import Path

# Thư mục đề xuất claude-thuc-hien/<tên>/ và đích bot-cua-toi-1/tests/ cùng
# cách dich-nguoc/khoi-phuc/ hai cấp nên dùng chung đường dẫn này.
B3_PATH = Path(__file__).resolve().parents[2] / "bot-cua-toi-3" / "tests" / "manager_flow_cases.py"


def _load_b3():
    """Nạp tệp ca Bot3 một lần, tên module riêng, không ghi vào sys.modules."""
    spec = importlib.util.spec_from_file_location("bot3_manager_flow_cases", str(B3_PATH))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


B3 = _load_b3()

MAGIC = 0x4d504d31
VERSION = 1
HEADER = B3.HEADER  # magic, version, count; struct.Struct không đổi được nên dùng chung
CASE = struct.Struct("<20iI")  # 20 int32 theo INTS, rồi uint32 error_count
HEADER_SIZE = 12
RECORD_SIZE = 84
MAX_COUNT = 10000  # count hợp lệ của cases.bin: 1..10000
INTS = list(B3.INTS)
DEFAULTS = dict(B3.DEFAULTS)

INDEX_SIZE = 8  # volumes/levels Bot1 có 8 ô: index 0..7
REJECTED_PROFILE = 16
REMOVED_SETTINGS = ("take_trail_distance", "take_trail_start", "candle_shift")
CANDLE_GROUPS = 2


def _field(row: dict, name: str) -> int:
    """Trường số nguyên của ca: kiểu và miền Bot3, thêm index 0..7 và profile khác 16."""
    value = B3._field(row, name)
    if name == "index" and not 0 <= value < INDEX_SIZE:
        raise ValueError(f"ca {row.get('id')}: index={value} ngoài 0..{INDEX_SIZE - 1}")
    if name == "profile" and value == REJECTED_PROFILE:
        raise ValueError(f"ca {row.get('id')}: profile {REJECTED_PROFILE} không có ở Bot1")
    return value


def _check(c: dict) -> None:
    """Ca phải dùng được cho Bot1 trước khi lấy fixture."""
    _field(c, "profile")
    _field(c, "index")


def cases() -> list[dict]:
    """Ca Bot3 theo thứ tự cũ, bỏ profile 16; mỗi lần gọi tạo dict mới.

    Mỗi ca là bản sao sâu: source_case_id giữ id Bot3, id mới liên tục từ 0,
    index %= 8. Các giá trị khác và group giữ nguyên.
    """
    rows = []
    for source in B3.cases():
        if source["profile"] == REJECTED_PROFILE:
            continue
        row = copy.deepcopy(source)
        row["source_case_id"] = source["id"]
        row["id"] = len(rows)
        row["index"] %= INDEX_SIZE
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
    """Settings khởi tạo Bot1 của ca, dict phẳng như Bot3 (bỏ tiền tố finish.).

    Bản sao settings Bot3, bỏ take_trail_distance, take_trail_start và
    candle_shift; candle_enabled/candle_timeframe chỉ giữ 2 nhóm đầu.
    """
    _check(c)
    values = copy.deepcopy(B3.settings(c))
    for name in REMOVED_SETTINGS:
        del values[name]
    values["candle_enabled"] = values["candle_enabled"][:CANDLE_GROUPS]
    values["candle_timeframe"] = values["candle_timeframe"][:CANDLE_GROUPS]
    return values


def positions(c: dict) -> list[dict]:
    """position_count vị thế sống đầu vào của ca, bản sao từ Bot3."""
    _check(c)
    return copy.deepcopy(B3.positions(c))


def tick_reply(c: dict) -> tuple[float, float]:
    """(bid, ask) SymbolInfoTick giả trả, như Bot3."""
    _check(c)
    return B3.tick_reply(c)


def levels_reply(c: dict) -> float:
    """Mức dừng Bot1VirtualStopLevel giả trả: phần tử đầu của levels_reply Bot3.

    Bot1 không có lời đáp chốt lời nên không trả phần tử take.
    """
    _check(c)
    return B3.levels_reply(c)[0]


def minimum_reply(c: dict) -> float:
    """SYMBOL_VOLUME_MIN giả trả, như Bot3."""
    _check(c)
    return B3.minimum_reply(c)
