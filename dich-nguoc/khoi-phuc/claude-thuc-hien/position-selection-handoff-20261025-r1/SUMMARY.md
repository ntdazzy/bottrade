# Bàn giao: tích hợp bằng chứng quét/chọn vị thế r3

Claude chỉ đọc tệp và ghi trong thư mục này. Không chạy lệnh, Python,
MT5, git; không sửa tệp chuẩn. Hai công cụ Python **chưa được chạy thử**.
Mô hình theo thông tin hệ thống: `claude-opus-5-5`; lượt này không có
nhật ký để xác nhận mức effort, nên không ghi là đã dùng `max`. Không
dùng Workflow/agent vì nhiệm vụ cấm.

## Bằng chứng đã đọc

| Phần | Kết quả | Tệp |
|---|---|---|
| r3 mã gốc = MQL5 | 4.600/4.600, 0 lỗi, mỗi bot | `bot-cua-toi-N/bang-chung/kiem-chon-vi-the-dong/position-selection-20261025-r3/comparison.json` |
| r3 máy đo quá khứ | 4.600/4.600, 0 lỗi, mỗi bot; nhật ký có `POSITIONSELECTION_NATIVE_CHECK_EXIT:0` | `doi-chung-mt5/chon-vi-the-dong-20261025/engine-position-selection-bN-r3/` |
| r1, r2 | 4.598/4.598 ở cả mã gốc/MQL5 và máy đo | `comparison.json` các lượt r1/r2 |
| Hai ca mới 4.598/4.599 | 2 lần kiểm đóng, 2 đóng, 2 gửi, khớp | `danh-gia-doc-lap/chon-vi-the-dong-20261025/post-helper-change-r3.json` |
| Bản sai cố ý | 4 bản, mỗi bản 2/2 ca bị từ chối | `danh-gia-doc-lap/chon-vi-the-dong-20261025/post-helper-r2/summary.json` |
| Bộ đọc tệp | r1 nhận tệp thiếu 2/4 byte; r2 từ chối 9 tệp cắt cụt, 36 kiểu sai | `parser-eof-r1.json`, `parser-eof-r2.json` |

Nguồn MQL5, biên nhận `bN-position-selection-01` và băm script giống
nhau ở r1/r2/r3; chỉ công cụ kiểm đổi. `cases.bin` r3 dùng chung hai bot.

## Đã ghi

- `files/cong-cu/kiem-chung-chon-vi-the-dong-bot-1-3.py`: giữ mọi kiểm
  cũ; thêm kiểm hai ca mới (thứ tự, chuỗi cuối `Renamed`), tính lại
  `post-helper-change-r3.json`, và kiểm bốn bản sai: đúng lược đồ
  `summary.json`/`result.json`, băm công cụ, nguồn bản sai dựng lại từ
  nguồn r3 đóng băng, header sản xuất = nguồn r3 đã kiểm = nguồn hiện
  hành, nhật ký biên dịch 0/0 và không nạp header sản xuất, băm ca/dữ
  liệu, kết quả MQL5 bản sai chỉ một lần kiểm đóng, chạy lại mã gốc và
  chỉ nhận đúng mã lỗi lệch dấu vết đã ghi.
- `files/cong-cu/lap-ban-do-bot-1-3.py`: chỉ đổi dòng 251, 280, 281.
- Sáu tài liệu cập nhật và `parent-review.md` mới; xem `integration.json`.

## Phát hiện

1. Công cụ tổng kiểm hiện hành đã trỏ r3 (4.600) nhưng chưa có tệp
   tổng kiểm r3; `KIEM-CHUNG-CHON-VI-THE-DONG-BOT-1-3.json` vẫn là r2.
2. `lap-ban-do-bot-1-3.py` và bản đồ hiện hành còn trỏ r2/4.598.
3. `kiem-doc-lai-sau-dong.py` nhận lỗi theo chuỗi con (cả `STATE_DIFFERS`);
   tổng kiểm mới chặt hơn: đúng mã theo từng bản sai.
4. EX5 của bản sai chỉ nằm trong MT5 riêng, không lưu vào bằng chứng.
5. Trong `cong-cu/` không có công cụ ghi `post-helper-change-r3.json`
   hay `parser-eof-*.json`. Tổng kiểm mới tính lại tệp đầu từ kết quả
   r3; phép cắt cụt tệp được tổng kiểm chạy lại. `parser-eof-r1.json`
   chỉ còn là ghi chép lịch sử.
6. Dòng "lượt bản đồ hiện hành" trong `BOT-1-3.md` đã cũ (`r8`); đề
   xuất đổi sang `luot-20261025-r3`. Bỏ dòng này nếu không muốn.
7. `danh-gia-doc-lap/chon-vi-the-dong-20261025/review.md` là ghi chép
   r2, giữ nguyên.
8. Chưa làm các tăng cường tùy chọn Claude nêu: giới hạn 8/15 lần đọc
   mã theo bot, chuỗi khác ký tự cuối, trả lời khác nhau mỗi lần kiểm
   đóng, kiểm thanh ghi cần giữ khi kiểm đóng trả về.

## Còn phải kiểm (Codex)

1. Chạy tổng kiểm mới; phải ra `mutants: 4`, `rejected_mutant_cases: 8`.
   Nếu lỗi, xem lý do trong `integration.json`; không nới kiểm.
2. Tạo bản đồ `luot-20261025-r3`, kiểm không còn tham chiếu r2.
3. Kiểm kiểu xuống dòng của tệp chuẩn rồi mới chép tài liệu.

Lệnh, chạy từ thư mục dự án:

```powershell
Copy-Item -LiteralPath 'dich-nguoc/khoi-phuc/claude-thuc-hien/position-selection-handoff-20261025-r1/files/cong-cu/kiem-chung-chon-vi-the-dong-bot-1-3.py' -Destination 'dich-nguoc/khoi-phuc/cong-cu/kiem-chung-chon-vi-the-dong-bot-1-3.py'
Copy-Item -LiteralPath 'dich-nguoc/khoi-phuc/claude-thuc-hien/position-selection-handoff-20261025-r1/files/cong-cu/lap-ban-do-bot-1-3.py' -Destination 'dich-nguoc/khoi-phuc/cong-cu/lap-ban-do-bot-1-3.py'
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-chung-chon-vi-the-dong-bot-1-3.py dich-nguoc/khoi-phuc/KIEM-CHUNG-CHON-VI-THE-DONG-BOT-1-3-R2.json
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/lap-ban-do-bot-1-3.py dich-nguoc/khoi-phuc/ban-do-bot-1-3/luot-20261025-r3 --extra-calibration dich-nguoc/khoi-phuc/doi-chung-mt5/api-bo-sung-20261023/api-extra-r2/calibration.json --menu-evidence dich-nguoc/khoi-phuc/menu-bot-1-3/luot-20261023-r1/verified-menu.json
```

Lệnh xem khác biệt, kiểm bản đồ và chép tài liệu nằm trong
`integration.json` → `commands`.

## Giới hạn

Truy vấn/kết quả gửi và mô hình chọn vị thế được cấp. Chưa có tài
khoản/nơi khớp thật, `_LastError` thật, toàn EA, mọi cài đặt, bảng
hiển thị, khởi động lại/trạng thái lưu, lỗi cấp bộ nhớ. Bốn bản sai
chỉ chứng minh bộ ca bắt được hai lỗi này. 4.600 ca mỗi bot không phải
phần trăm hoàn thành; không có kết luận 100% toàn bot.
