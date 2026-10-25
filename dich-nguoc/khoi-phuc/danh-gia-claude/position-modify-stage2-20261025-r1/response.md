Đã xong phần việc lượt 2. Mọi tệp mới chỉ nằm trong `claude-thuc-hien/position-modify-20261025-r1/stage2/`. Tôi không chạy shell/MT5/git, không tự tính mã băm, không sửa tệp lượt 1, tệp chính hay EX5 gốc.

**Codex đã làm xong trước khi tôi viết tài liệu** (tôi đọc từ tệp kết quả):
- Codex đã chép runner `--modify` và tệp tổng kiểm của tôi vào `cong-cu/`, rồi chạy cả hai.
- Máy thử `engine-modify-b1-r1` / `-b3-r1`:
  - Biên dịch 0 lỗi, 0 cảnh báo. MetaEditor vẫn trả mã 1.
  - Chạy trên tài khoản demo, mã thoát 0; nhật ký có `POSITIONMODIFY_NATIVE_CHECK_EXIT:0`.
  - Mỗi bot khớp 1.596/1.596 ca. Kết quả giống từng byte giữa mã gốc, chương trình MQL5 và máy thử (`76f88d45…`).
- Tổng kiểm `KIEM-CHUNG-SUA-VI-THE-BOT-1-3.json` đạt. Mỗi bot:
  - Chạy lại 45 ca bằng mã gốc, đủ 196/196 lệnh máy.
  - Từ chối 22 kiểu dữ liệu sai, 12 tệp hỏng và 18 tệp bị cắt cụt.
- Codex đã sửa một lỗi của tôi trong tổng kiểm: danh sách nguồn phải so như tập hợp, không so thứ tự. Bản trong `stage2` đã nhận đúng sửa đổi đó.

**Tôi viết thêm trong `stage2/`:**
- `lap-ban-do-bot-1-3.py`: thêm mô tả hàm sửa vị thế (`0x26d20` / `0x32a90`) và nối bằng chứng: lượt so, máy thử, nơi gọi (19 nơi ở bot 1, 21 nơi ở bot 3) và tổng kiểm.
- `BOT-1-3.md`: thêm mục sửa vị thế; giữ nguyên mục của Codex.
- `BAN-DO-TOAN-BO-BOT-1-3.md`: cập nhật hàng P20 và thêm đoạn cho bản đồ r4; giữ nguyên đoạn ghi lần từ chối khối điều phối.
- Hai README: mỗi tệp thêm một đoạn đầu.
- `PHAN-TICH-SUA-VI-THE-BOT-1-3.md`: tài liệu mới, ghi thứ tự xử lý, kết quả, nơi gọi và giới hạn.
- `integration.json` và `SUMMARY.md`: đích của từng tệp và các lệnh theo thứ tự cho Codex.

**Việc còn chờ:**
- Codex cần băm hai tệp đã ghép để xác nhận trùng bản đã chạy (`55dceaaf…` và `e1ed2078…`).
- Sau đó chạy bản đồ `luot-20261025-r4` và so với r3: chỉ được khác ở `0x26d20` (bot 1) và `0x32a90` (bot 3).
- Chỉ khi các bước trên đạt mới chép tài liệu, vì tài liệu ghi r4 là lượt hiện hành.

**Chưa chứng minh:**
- 19/21 nơi gọi và nguồn giá trị dừng lỗ/chốt lời truyền vào.
- Cả hai chiều quản lý vị thế và việc đặt dừng lỗ/chốt lời sau khớp.
- Kết quả sửa trên tài khoản thật, `_LastError`, lỗi cấp bộ nhớ.
- Toàn EA, menu/cài đặt, bảng hiển thị, khởi động lại.

Không có kết luận hoàn thành 100%.
