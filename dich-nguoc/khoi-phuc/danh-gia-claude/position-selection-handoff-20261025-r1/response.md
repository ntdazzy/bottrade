Đã ghi xong mọi tệp bàn giao vào `dich-nguoc/khoi-phuc/claude-thuc-hien/position-selection-handoff-20261025-r1/`. Tôi không chạy lệnh, Python, MT5 hay git và không sửa tệp chuẩn nào, nên hai công cụ Python mới **chưa được chạy thử**.

**Bằng chứng đã đọc (mọi số đều có tệp gốc):**
- Mã gốc so với MQL5, lượt r3: cả hai bot khớp 4.600/4.600, 0 lỗi, 2.300 ca mỗi chiều.
- Máy đo quá khứ r3 (`engine-position-selection-bN-r3`) đã có `comparison.json`: cả hai bot khớp 4.600/4.600, 0 lỗi. Nhật ký có `POSITIONSELECTION_NATIVE_CHECK_EXIT:0`.
- Lượt r1 và r2 đều khớp 4.598 ca. Nguồn MQL5 và bản biên dịch `bN-position-selection-01` giống nhau qua r1–r3; chỉ công cụ kiểm thay đổi.
- Hai ca mới id 4.598/4.599: mỗi ca gọi kiểm đóng 2 lần, đóng 2 lần, gửi 2 lần, khớp MQL5.
- Thử bản sai cố ý: 4 bản sai, mã gốc từ chối đủ 8/8 ca. Băm header sản xuất trùng với nguồn r3 đã kiểm, tức nguồn chính không đổi.

**Tệp đã ghi:**
- `files/cong-cu/kiem-chung-chon-vi-the-dong-bot-1-3.py`: giữ mọi kiểm cũ về nguồn gốc và tệp cắt cụt. Thêm phần kiểm độc lập:
  - hai ca mới;
  - bốn bản sai, mỗi bản 2 ca bị từ chối, dùng đúng lược đồ `summary.json`/`result.json`;
  - header sản xuất trùng nguồn đã kiểm;
  - chạy lại mã gốc và chỉ chấp nhận đúng mã lỗi đã ghi.
- `files/cong-cu/lap-ban-do-bot-1-3.py`: chỉ sửa dòng 251, 280, 281 (đổi sang r3/4.600).
- Sáu tài liệu cập nhật. Liên kết bản đồ chính trỏ tới `luot-20261025-r3`; tổng kiểm mới là `KIEM-CHUNG-CHON-VI-THE-DONG-BOT-1-3-R2.json`.
- `parent-review.md` mới cho L1/L2. Ghi rõ Claude chỉ đọc bản r1 đóng băng.
- `integration.json` (đích → tệp bàn giao, lệnh nguyên văn, điều kiện đạt) và `SUMMARY.md`.

**Cần lưu ý:**
- Tôi thêm một số kiểm chặt hơn công cụ cũ mà chưa chạy: chuỗi cuối phải là `Renamed`, kết quả MQL5 của bản sai chỉ có 1 lần kiểm đóng, và tập tệp được nạp khi biên dịch bản sai. Nếu tổng kiểm báo lỗi, cần xem lý do, không nới kiểm. Các lỗi có thể gặp đã liệt kê trong `integration.json`.
- EX5 của bản sai chỉ nằm trong MT5 riêng, không được lưu vào thư mục bằng chứng.
- Tôi đổi thêm dòng "lượt bản đồ hiện hành" trong `BOT-1-3.md` từ `r8` (đã cũ) sang `luot-20261025-r3`. Có thể bỏ thay đổi này nếu không muốn.
- Tệp bàn giao xuống dòng kiểu LF. Cần kiểm kiểu xuống dòng của tệp chuẩn trước khi chép.

**Codex còn phải chạy:** tổng kiểm mới (kết quả mong đợi `mutants: 4`, `rejected_mutant_cases: 8`), rồi tạo bản đồ `luot-20261025-r3`, xem khác biệt, sau cùng mới chép tài liệu. Lệnh đầy đủ nằm trong `integration.json`.

**Giới hạn:** chưa có bằng chứng cho toàn EA, mọi cài đặt, bảng hiển thị, khởi động lại/trạng thái lưu, tài khoản thật, `_LastError` thật, lỗi cấp bộ nhớ. Bốn bản sai chỉ cho thấy bộ ca bắt được hai lỗi cụ thể. Không có kết luận 100% toàn bot.

**Cấu hình:** theo thông tin hệ thống, mô hình là `claude-opus-5-5`. Lượt này không có nhật ký nên không xác nhận được mức `max`. Không dùng Workflow hay agent vì nhiệm vụ cấm.

Tôi cũng ghi một mục bộ nhớ dự án mô tả cách làm việc bàn giao này cho các lượt sau.