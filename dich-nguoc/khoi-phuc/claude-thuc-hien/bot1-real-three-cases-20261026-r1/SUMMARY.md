# SUMMARY — real_blocks_cases.py cho Bot1 (r1)

**Trạng thái:** đã viết mã; **chưa chạy, chưa import thử, chưa sinh tệp
nhị phân**. Không tính kết quả mong đợi, không có test tự khẳng định.
Đường dẫn tính từ `dich-nguoc/khoi-phuc/`.

## Phạm vi
- Tệp: `real_blocks_cases.py` (đích sau ghép
  `bot-cua-toi-1/tests/real_blocks_cases.py`) và `SUMMARY.md`.
- Đã đọc: `claude-thuc-hien/bot1-real-three-check-20261026-r1/TASK.md` và
  `bot-cua-toi-3/tests/real_blocks_cases.py`. Chỉ liệt kê tên tệp trong hai
  thư mục `tests/`, tìm `importlib.util` ở đó (không có) và xem `.gitignore`.
  Không đọc EX5, mã máy, phân tích, MQL5 production.
- Không chạy lệnh, không tạo tác tử, không sửa nguồn chính/Git/MT5.

## Giao diện
- `MAGIC=0x4d524231`, `VERSION=1`, `HEADER=Struct('<3i')`,
  `CASE=Struct('<22iqQII41d')`: tệp dài 12 + 440·count byte.
- `INTS` (22 tên), `DOUBLES` (25 tên): cùng tên/thứ tự B3 và TASK.md, kiểu
  `list` như B3; viết cố định, không lấy từ module B3, để khóa định dạng Bot1.
- Thêm: `MIDDLE` (ticket q, deviation Q, index I, error_count I), `ARRAYS`,
  `MAX_COUNT=100000`, `ARRAY_SIZE=8`, `STAGES=(0, 1, 5)`, `LIMITS`,
  `SOURCE_PATH`.

## cases()
- Nạp B3 một lần lúc import qua `importlib.util.spec_from_file_location`, từ
  `Path(__file__).resolve().parents[2] / 'bot-cua-toi-3/tests/real_blocks_cases.py'`,
  tên module `bot3_real_blocks_cases`, không ghi vào `sys.modules`. Thư mục đề
  xuất và đích đều cách `dich-nguoc/khoi-phuc/` hai cấp nên đường dẫn giữ đúng
  sau ghép.
- Mỗi lần gọi: chỉ gọi `cases()` của B3; lọc stage 0/1/5, giữ thứ tự;
  `copy.deepcopy` từng ca; `source_case_id` = id B3; id mới 0..n-1;
  `volumes`/`levels` lấy 8 phần đầu; `index %= 8`. Không đổi stage (5 vẫn là
  5), giá trị khác, bit NaN/−0, group; không sửa biến/hàm/mảng của B3.

## encode(rows)
- Kiểm hết trước khi đóng gói; sai thì báo `ValueError` kèm số hàng:
  1 ≤ count ≤ 100000; đủ trường; id liên tục; buy/modify_ok/prior_changed
  0..1; stage ∈ (0, 1, 5); scenario 0..11; index 0..7; passed_flag,
  eligible_flag, before_open, shift_setting, step_enabled, guard 0..255;
  table_pattern 0..5; volumes/levels đúng 8 phần tử.
- Độ rộng int32/int64/uint64/uint32 và kiểu số do `struct.pack` giữ; lỗi được
  báo lại là `struct.error` kèm số hàng.
- Double đóng gói thẳng, giữ bit, không làm tròn; không loại NaN/Inf, không
  thêm luật cho double; không sửa ngầm index/mảng trong encode.

## Phụ thuộc
- Bộ ca Bot1 phụ thuộc nội dung hiện hành của
  `bot-cua-toi-3/tests/real_blocks_cases.py`; Codex khóa SHA tệp này trong bộ
  đo. Tệp B3 đổi thì bộ ca Bot1 đổi theo.
- Khi nạp B3, Python có thể ghi `__pycache__` cạnh tệp B3 (mặc định; đã có
  trong `.gitignore`), trừ khi chạy với `-B`. Không ghi tệp nguồn nào.

## Đếm tay (chưa chạy để xác nhận)
Theo mã B3 đã đọc: stage0 536, stage1 400, stage5 310, tổng 1246 ca;
12 + 440·1246 = 548252 byte. `python real_blocks_cases.py` in số ca theo
stage/nhóm để đối chiếu.

## Lưu ý
- 4 ca nhóm `index` có index=8 ở B3 (stage 0 và 1, mỗi phía) thành index=0
  do `%8`, group vẫn ghi `index/index=8`. Bản ghi nhị phân của chúng giống ca
  `index/index=0` cùng stage/phía, chỉ khác id.
- Theo mã B3, không ca stage 0/1/5 nào ghi giá trị riêng vào phần tử vị trí 8
  của volumes/levels; phần bị cắt chỉ là giá trị gốc của `_base`.

## Cấu hình lượt
Môi trường báo model `claude-opus-5-5` và Ultracode bật; mức `max` không tự
kiểm được trong phiên. Phiên không có công cụ Workflow/tác tử và người dùng
cấm tạo tác tử, nên làm một mình.
