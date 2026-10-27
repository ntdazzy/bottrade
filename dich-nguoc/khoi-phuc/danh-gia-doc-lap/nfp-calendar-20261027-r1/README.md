# Kết quả phục hồi tìm lịch NFP

Mỗi bot **1.916/1.916 ca thường**, **8/8 ca mảng thiếu** khớp.
So đủ thời điểm trả, mã lỗi cuối và thứ tự/đối số/trả lời dịch vụ.
Đã phủ cả4tổ hợp mảng đọc xuôi/ngược. Nguồn trực tiếp/bộ kiểm của hai
bot đều biên dịch0lỗi/0cảnh báo.

Đã giữ mã dự phòng khi không thấy tên hoặc mã sự kiện bằng0; không
thêm điều kiện tự chặn thời điểm ngoài cuối khoảng. Mảng thiếu dừng
đúng loại lỗi và đúng chuỗi dịch vụ trước lỗi, không trả0 để che lỗi.

Probe mảng mới có trạng thái thoát0; probe cũ dùng void entry cho mã
thoát không ổn định nhưng ghi đúng dữ liệu, được giữ riêng và không
lấy làm căn cứ xác nhận thành công. Lượt479ca trước mở rộng cờ mảng
vẫn được giữ với nguồn tương ứng trong before-series-bot1/bot3.

Còn lời gọi từ evaluator, hủy/đóng vị thế theo tin, lịch trực tuyến và
lỗi cấp phát thực. Hai mã kiểu mảng ngoài bản chụp được cấp ở ranh giới
SDK như mô tả trong[đặc tả](SPEC.md). Chưa làEA hoàn chỉnh.
[Kết quả/mã kiểm](verification.json), [mã gốc](native-evidence.json).
