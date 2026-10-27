# Kết quả ghép chuỗi thay đổi khối lượng

Mỗi bot **316/316 ca thường** khớp từng byte, thêm **2/2 ca chia0** dừng
đúng. Mỗi bot có221ca gọi tiếp tính khối lượng và95ca bỏ qua tại cổng.
Bốn bản biên dịch bộ kiểm/nguồn gọi trực tiếp đều0lỗi,0cảnh báo.

Đã chạy liên tục bản gốc qua kiểm vốn → tính khối lượng/rút tiền/đổi
tiền → xóa/mở/gửi lệnh chờ, không đặt lại dữ liệu giữa các hàm. Giữ
khác biệt: bot1 cập nhật mốc trước tính, bot3 giữ nguyên ở đoạn này.
Có đổi dữ liệu giữa lần đọc/gửi; đã đối chiếu cùng chỉ số/mảng và toàn
bộ bảng/trạng thái giao dịch.

Chưa có EA đầy đủ. Trạng thái sát điểm lỗi sau dịch vụ cuối, phần
trước/sau chuỗi và phép chạy song song toàn bot vẫn còn. [Đặc tả](SPEC.md),
[kết quả/mã kiểm](verification.json).
