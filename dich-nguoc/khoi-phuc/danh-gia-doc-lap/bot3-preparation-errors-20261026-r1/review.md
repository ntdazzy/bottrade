# Rà độc lập phép kiểm lỗi chuẩn bị bot3

Tác tử chỉ đọc `/root/review_bot3_parent_flow` đã đọc bộ kiểm lỗi,
chương trình chọnca và tùy chọn biên dịch mới; không tìm thấy lỗi thật.
Không chạy thêm hoặc sửa nguồn.

- Mỗi ca ghi dấu mốc và đẩy đầu tệp ra đĩa trước khi chuẩn bị. Ca lỗi
  phải có dòngzero divide, mã thoátFFFF/-1, chỉ còn đầu16byte, không có
  bản ghi thường hoặc script-status.bin.
- Thân gốc kiểm lớp lỗi thấp0x1f7; nguồn mới kiểm đúng lớp chia0 và dừng.
  Báo cáo không khẳng định so đủ trạng thái đang ghi hoặc vị trí dòng lỗi.
- Tùy chọn biên dịch là switch mặc địnhfalse. Khi bật, tạo và lưu dự án
  fpzerocheck1 có mã băm; giữ bản nguồn Bot3Preparation.mqh nguyên vẹn.
- Các dịch vụ giá/chỉ báo được cấp trong Script, không có gửi lệnh thật.

Giới hạn:1.016ca thường và18ca lỗi chưa chứng minh mọi lỗi chỉ báo,
tick/lịch, tài khoản hoặc toàn EA.
