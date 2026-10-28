# Chạy thân đổi giờ/đổi tiền trong khởi động bot 3

Lượt `b3-startup-selection-live-20261029-r2` mở rộng phép kiểm
`0x3840..0x4580`: chạy nguyên thân mùa hè `0x7e20..0x82f7` và đổi
tiền `0x8300..0xe0b5`, giữ chung vùng nhớ của phần gọi. Nguồn sản
phẩm giữ nguyên; bộ kiểm mới bỏ việc cấp kết quả cuối của hai hàm.

| Nội dung | Bằng chứng | Kết quả/còn thiếu |
|---|---|---|
| Phần nối, 47 trường và 5 chuỗi | So trước mỗi lời gọi và khi kết thúc | **344/344 ca khớp từng byte** |
| Thân mùa hè | Mã kiểm tra hàm và số lần vào từng ca | 344 lần, mỗi ca đúng 1 lần |
| Thân đổi tiền | Mã kiểm tra hàm, đối số từng lần đọc và số lần vào | 232 lần, đúng điều kiện tần suất/rủi ro |
| Lời gọi/thông báo | Đối số được kiểm trước khi cấp phản hồi | 18.982 lần, gồm 296 lần in |
| Phép nhân/chia | Kiểm vị trí lệnh gốc trước chạy, thực hiện trên CPU | 1.686 phép nhân, 275 phép chia |
| Biên dịch | `b3-startup-selection-live-check-20261029-r3` | 0 lỗi, 0 cảnh báo |

Ca kiểm gồm ngày quanh mốc đổi giờ, năm 1986/1987/2006/2007, nhiều
lần đọc giờ khác nhau; các tên tiền tệ hoa/thường, giá đổi giữa hai
lần đọc, cặp dự phòng, đuôi mã; làm tròn trước ngưỡng, cờ, chế độ,
số không hợp lệ/vô cực và giữ mã lỗi. Bộ kiểm bắt buộc số lần vào
hai thân đúng theo từng ca, không chỉ ghi số tổng để tham khảo.

Kiểm độc lập đã xác nhận nguồn đang dùng khớp bằng chứng và biên
nhận. Lỗi thứ tự nạp hàm trong bản nháp được phát hiện qua sai thứ
tự lời gọi và đã sửa trước lượt đạt. Bản nháp/lượt cũ được giữ;
không dùng lượt chỉ có kết quả MQL5 làm bằng chứng khớp.

## Giới hạn

Thời gian, tên tiền tệ, số dư và giá là dữ liệu kiểm. Các hàm lịch,
chuỗi ngày và chia dư chạy thật trong MT5; kết quả được cấp cho mã
máy gốc sau khi đã kiểm đúng đối số/thứ tự. Cấp phát chuỗi thành
công được cấp. Chưa kiểm lỗi chia 0, chuyển ngày thất bại hoặc cấp
phát thất bại trong phần nối này. Chưa chạy chuẩn bị đầu, toàn
OnInit/EA hoặc hai bot hoàn chỉnh cùng dữ liệu. Không chạy phần
quyền dùng; bộ chặn các điểm bảo vệ vẫn có hiệu lực.

## Chạy lại

`cong-cu/kiem-noi-ham-that-chon-khoi-dong-bot-3.py`: `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`. Phải chạy
MQL5 trước mã máy gốc. Dùng tên lượt mới và MT5 bot 3 riêng.

[Số liệu và mã kiểm tra](verification.json), [danh sách tệp](../startup-selection-live-bot3-20261029-r1-manifest.txt).
