# Lịch sử thật trong vòng chiến lược — bot 1

Lượt `b1-real-history-loop-20261029-r2`: **27/27 ca khớp**,
208 lần chuẩn bị và 18.942 lời gọi dịch vụ lịch sử. Nguyên thân
`0x1efa0..0x1f5df` và hàm sắp xếp `0x47950` chạy trong cùng vùng
nhớ với nạp cấu hình, ngữ cảnh, chuẩn bị và thống kê.

| Nội dung | Bằng chứng kiểm |
|---|---|
| Dùng lại dữ liệu đã lưu | Đổi mã chủ của lệnh mở nhưng giữ tổng số giao dịch: giữ bộ nhớ cũ như bản gốc |
| Nạp lại dữ liệu | Tổng số giao dịch đổi: dựng lại hai mảng và sắp xếp |
| Thứ tự mảng | Cả bốn tổ hợp cờ đảo chiều của hai mảng; so toàn bộ nội dung vật lý |
| Chế độ kiểm thử/lỗi chọn lịch sử | Cờ 0, 1, 255; thông tin chế độ 0/1; chọn lịch sử thất bại |
| Cộng lời/lỗ/phí | Thứ tự gốc, số lớn, vô cực và NaN; 1.140 phép cộng dùng CPU thật để giữ đúng bit NaN |
| Tắt vòng/thay đổi giờ | Kiểm trường hợp không bật chiến lược hoặc không tới bước cập nhật thống kê |

Trước mỗi lời gọi dịch vụ so trạng thái: chỉ số, mã nhận diện,
mã giá, số đếm, tổng lịch sử và cả hai mảng lưu. Sau mỗi lần hàm
lịch sử trả về so trạng thái và số thực theo từng bit; cuối ca
kiểm dữ liệu ghi đã đọc hết. Có 54 lần vào hàm sắp xếp, gồm các
lần hàm tự gọi lại.

Phần lịch sử dùng chung bộ nhớ, bộ cấp chuỗi và thanh ghi với
vòng gốc. Không gọi lại bộ khởi tạo lịch sử giữa các chiến lược.
Các mảng được cấp/chỉnh kích thước theo kết quả đo từ MT5.

Biên dịch `b1-real-history-loop-check-20261029-r1`: **0 lỗi, 0 cảnh báo**.
Kiểm độc lập không thấy lỗi cần sửa. Lượt `r2` bổ sung kiểm mã
SHA-256 của toàn bộ bản ghi dịch vụ trước khi chạy mã gốc và khi
so kết quả; giữ lượt `r1` và mã công cụ của lượt đó để tra cứu.

## Lặp lại và giới hạn

`kiem-vong-lich-su-that-bot-1.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`. Dùng tên
lượt mới và MT5 bot 1 riêng; MQL5 chạy trước mã gốc.

Thân đánh giá giao dịch `0x18aa0` vẫn là bộ ghi. Chưa ghép đoạn
chọn mã/dọn bảng phía trước hoặc đoạn sau `0x16730` trong lượt
này. Phản hồi dịch vụ và cấp phát thành công được cấp; chưa kiểm
mọi lỗi cấp phát, toàn trạng thái khi lỗi hoặc môi giới thật.
Không chạy quyền dùng hay gửi lệnh thật. Chưa có EA đầy đủ hoặc
phép chạy cặp hai EA.

[Số liệu và mã kiểm tra](verification.json),
[danh sách tệp](../real-history-loop-bot1-20261029-r1-manifest.txt).
