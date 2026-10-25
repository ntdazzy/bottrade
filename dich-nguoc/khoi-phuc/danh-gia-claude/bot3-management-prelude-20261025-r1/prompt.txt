# Viết phần đầu quản lý bot 3

Đây là dự án khôi phục nguồn bot giao dịch. Codex đã đọc mã máy và
chốt đầy đủ mô tả ở
`dich-nguoc/khoi-phuc/bot-cua-toi-3/phan-tich/dong-vi-the/management-20261025-r1/prelude-specification.md`.
Bạn chỉ viết MQL5 theo mô tả, không tự phân tích EX5/C. Không đọc EX5,
không lệnh/MT5/git/kỹ năng lồng nhau; chỉ Read/Grep/Glob/Edit/Write
trong thư mục này, không ghi ngoài thư mục.

Viết mã thật trong thư mục này:

- `Bot3ManagementPrelude.mqh`: phần đọc/lọc một vị thế, bổ sung dừng
  và chốt ban đầu, ba nhóm đóng theo nến. Chữ ký và kiểu tham số rõ,
  dùng `Bot3PositionModify`/`Bot3PositionClose` đã có, không viết lại
  helper con. Không viết vòng điều phối toàn hàm, không thêm luật.
- `SUMMARY.md`: đối chiếu mô tả → hàm, giới hạn, và ghi rõ chưa biên
  dịch/chưa so nếu chưa có bằng chứng.

Giữ đúng thứ tự đọc, kiểu số, làm tròn, so chuỗi UTF-16, lỗi tick vẫn
lọc tiếp, cờ byte đúng bằng 1, ba khung nến và hai chiều mua/bán.
Không dùng “gần giống”, không đổi điều kiện `<` thành `<=`, không bỏ
nhóm sau khi nhóm trước đóng. Có thể đặt tên hàm mới, nhưng phải giữ
đủ dữ liệu đầu vào/đầu ra để Codex ghép vào hai hàm quản lý sau.
