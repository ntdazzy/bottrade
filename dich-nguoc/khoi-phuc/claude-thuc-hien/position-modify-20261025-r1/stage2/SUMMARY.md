# Lượt 2 — nối máy thử, tổng kiểm, bản đồ r4 và tài liệu

Claude chỉ đọc/ghi tệp trong `stage2/`; không chạy shell, MT5, git và
không tự tính mã băm. Không sửa tệp lượt 1, tệp chính, EX5 gốc hay bản chụp.

## Hiện trạng đã đọc được khi viết

Codex đã chép runner và tổng kiểm của lượt này vào `cong-cu/` và đã chạy:

- `doi-chung-mt5/sua-vi-the-20261025/engine-modify-b1-r1` / `-b3-r1`:
  dựng 0 lỗi/0 cảnh báo (MetaEditor trả mã 1), chạy demo, mã thoát 0,
  nhật ký có `POSITIONMODIFY_NATIVE_CHECK_EXIT:0`, 1.596/1.596 ca khớp;
  kết quả giống từng byte mã gốc/MQL5 (`76f88d45…`). Bản runner lưu
  trong lượt: `tester-check-tool.py`, băm ghi `55dceaaf…`.
- `KIEM-CHUNG-SUA-VI-THE-BOT-1-3.json`: trạng thái
  `position-modify-helper-verified-with-stated-limits`, mỗi bot 45 ca
  mã gốc chạy lại (196/196 lệnh), 22 kiểu dữ liệu sai, 12 tệp sai,
  18 tệp cắt cụt bị từ chối; `whole_bot_complete:false`; băm công cụ `e1ed2078…`.
- Codex sửa một dòng tổng kiểm trước khi chạy: `build.json` ghi
  `PipelineApi` cuối danh sách nên phải so tập hợp, không so thứ tự.
  Bản `stage2` đã nhận đúng sửa đổi đó.

Chưa có `ban-do-bot-1-3/luot-20261025-r4/` và chưa có
`PHAN-TICH-SUA-VI-THE-BOT-1-3.md` ở thư mục chính.

## Tệp trong `stage2/files/`

| Tệp | Đích | Việc |
|---|---|---|
| `cong-cu/kiem-hang-doi-trong-may-thu.py` | cùng tên | Đã ghép; chỉ kiểm băm = `55dceaaf…` |
| `cong-cu/kiem-chung-sua-vi-the-bot-1-3.py` | cùng tên | Đã ghép; chỉ kiểm băm = `e1ed2078…` |
| `cong-cu/lap-ban-do-bot-1-3.py` | cùng tên | Thay: vai trò `0x26d20/0x32a90`, bằng chứng sửa vị thế, máy thử, nơi gọi, tổng kiểm |
| `cong-cu/BOT-1-3.md` | cùng tên | Thay sau r4: thêm mục sửa vị thế, giữ mục Codex, lượt hiện hành r4 |
| `BAN-DO-TOAN-BO-BOT-1-3.md` | cùng tên | Thay sau r4: liên kết r4, hàng P20, đoạn r4; giữ đoạn từ chối khối điều phối |
| `bot-cua-toi-1/README.md`, `bot-cua-toi-3/README.md` | cùng tên | Thay sau r4: thêm một đoạn đầu |
| `PHAN-TICH-SUA-VI-THE-BOT-1-3.md` | gốc `khoi-phuc` | Tạo mới |

Tùy chọn: `../files/cong-cu/kiem-sua-vi-the-bot-1-3-schema.md` (lượt 1,
không đổi) → `cong-cu/kiem-sua-vi-the-bot-1-3-schema.md`.

## Lệnh cho Codex, theo thứ tự

Bản đầy đủ, nguyên văn: `integration.json` → `commands_to_run_in_order`.

1. Băm hai tệp đã ghép trong `stage2` (phải ra `55dceaaf…`, `e1ed2078…`).
2. Chép `lap-ban-do-bot-1-3.py`, kiểm `luot-20261025-r4` chưa có, rồi chạy:
   `python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/lap-ban-do-bot-1-3.py dich-nguoc/khoi-phuc/ban-do-bot-1-3/luot-20261025-r4 --extra-calibration dich-nguoc/khoi-phuc/doi-chung-mt5/api-bo-sung-20261023/api-extra-r2/calibration.json --menu-evidence dich-nguoc/khoi-phuc/menu-bot-1-3/luot-20261023-r1/verified-menu.json`
3. So r3/r4: chỉ được khác `0x26d20` (bot 1) và `0x32a90` (bot 3); in
   khóa bằng chứng của hai hàm này (lệnh có sẵn trong `integration.json`).
4. Đạt mới chép tài liệu: tạo `PHAN-TICH-SUA-VI-THE-BOT-1-3.md` (dừng
   nếu đã có), rồi thay `BOT-1-3.md`, `BAN-DO-TOAN-BO-BOT-1-3.md`, hai README.

Dừng nếu băm khác, r4 lỗi hoặc đã có, hay r3/r4 khác ở hàm khác.
Không chạy lại hai lệnh máy thử và lệnh tổng kiểm: đầu ra đã có, công
cụ từ chối ghi đè.

## Ghi chú và giới hạn

- Mỗi bản ghi chạy máy thử có `2026.hcc` khác băm trước/sau: đây là dữ
  liệu giá của MT5 riêng do máy thử cập nhật, không dùng làm bằng chứng.
- Trường `return_use` của công cụ nơi gọi tính cả lệnh `nop` có `rax`
  là "đọc"; tài liệu không dùng trường này làm bằng chứng.
- Cấu hình lượt này: môi trường báo mô hình `claude-opus-5-5`; mức
  `max`/Ultracode không hiển thị cho Claude, cần lấy từ nhật ký yêu cầu.
- Còn: 19/21 nơi gọi và nguồn đối số, cả hai chiều quản lý, đặt sau
  khớp, kết quả sửa trên tài khoản thật, `_LastError`, lỗi cấp bộ nhớ,
  toàn EA, cài đặt/menu, hiển thị, khởi động lại/trạng thái lưu. Khối
  điều phối vẫn bị từ chối như đã ghi; không làm phần đó. Không xác
  nhận hoàn thành 100%.
