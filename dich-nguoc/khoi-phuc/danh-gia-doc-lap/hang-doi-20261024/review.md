# Kiểm độc lập hàng đợi và các điểm Claude nêu

Agent nội bộ chỉ đọc đã đối chiếu C/mã máy, nguồn hiện hành và kết
quả. Chưa thấy lỗi đã chứng minh trong phạm vi giao.

- Cờ đầu ==1, tiếp tục/xóa bằng bit thấp; đọc lại loại sau nhánh mua,
  ghi kết quả/giá sau lời gọi và lặp 132 giữ đúng thứ tự gốc.
- Ba hàm số học giữ đúng thứ tự phép cộng/nhân/trừ, phần `NaN` và số
  0 có dấu. Cả hai bot khớp 374 ca trong script và máy đo quá khứ.
- Phần sửa bộ mô phỏng lấy quy tắc hai toán hạng `NaN` từ 25 cặp đo
  CPU thật của MT5. Không đọc nguồn hàng đợi mới để tạo đáp án gốc.
- So đủ 500 số của hai bảng, cờ/bộ đếm/lỗi, dữ liệu, chữ và đối số
  có kiểu của tạo lệnh/in/chờ. Chưa so đầy đủ các cờ lỗi CPU.
- Còn thiếu phép so chung hàng đợi + tạo yêu cầu + gửi. Kết quả tạo
  lệnh vẫn được cấp sẵn; chưa có bằng chứng toàn EA/nơi giao dịch.

Đã rà lại đánh giá Claude cho hàm mã lỗi. Các điểm đúng đã xử lý:
phủ mọi mã -1..4207 mà không nhân tất cả tổ hợp quá giới hạn số ca;
nối nguồn/EX5/biên nhận/kết quả khi so; thêm trạng thái hoàn tất của
script; kiểm nguồn MT5 riêng trước/sau chạy; ghi rõ chuỗi cũ chỉ kiểm
ở gốc; thêm đối chứng int32/uint32/int64 và tăng đếm trước chép chuỗi.

Hai nhận xét của Claude đã được hiệu chỉnh sau đối chiếu: hàm lưu
đã dùng `open('x')`, không ghi đè; giá trị signed đã có trong C, còn
phép đối chứng mới làm rõ thêm ý nghĩa mã kiểu. Không xem phản hồi
Claude là xác nhận EX5 hoặc toàn bộ bot đạt 100%.
