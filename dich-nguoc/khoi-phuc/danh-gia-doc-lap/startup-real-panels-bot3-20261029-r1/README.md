# Chạy cả ba thân bảng trong khởi động — bot 3

Lượt `b3-startup-real-panels-20261029-r2`: **56/56 ca khớp**, 284
trường, dãy chỉ báo, 2.800 ô bảng, 900 ô lịch, **85.375 lời gọi**
và 23.510 phép tính CPU. Biên dịch
`b3-startup-real-panels-check-20261029-r1`: 0 lỗi, 0 cảnh báo.

Chạy liên tục mã gốc từ `0xd60` tới trả về `0x5f34`, nền
`0x17156250000`. Giữ các thân lịch, đổi giờ, đổi tiền, chuẩn bị,
tìm điểm vào, kiểm lệnh chờ gần giá và cả ba thân bảng. Không cấp
sẵn kết quả của các thân này, không đặt lại trạng thái tại điểm nối.

| Phần | RVA gốc | Kiểm thêm trong lượt này |
|---|---|---|
| Tạo bảng | `0xef40` | Chữ, vị trí, cỡ chữ, màu, lời gọi tạo/đổi đối tượng |
| Cập nhật lệnh đang mở | `0x14fa0` | Mã giá, mã nhận diện, hướng, chọn lệnh, lời/lỗ |
| Cập nhật lịch sử | `0x16e80` | Chọn lịch sử, lệnh rỗng/sai mã, lời/lỗ/phí |
| Hai hàm ô bảng | `0x53a10`, `0x555e0` | Thân mã gốc và phép tính chạy thật |
| Các chế độ bot 3 | Đầu vào `0x1d7130`, chế độ dùng chung `0x6d630` | Giá trị -1, 0, 3, 1234, 9999 đi qua chuẩn bị; không chỉ đổi biến bảng trước khi bị ghi đè |
| Tần suất/9 chiến lược | `0x6d21c`, các mảng 9 phần tử | Tần suất -1, 0..6, INT_MAX; nhóm 9 được nhận, nhóm 10 bị loại |

Dùng lại công cụ bot 1 bằng một lớp chuyển nhỏ, ánh xạ đầy đủ địa
chỉ bot 3 và số dịch vụ 110..130. Gói tạo đối tượng vẫn 88 byte.
Bản nháp chưa đạt đã được giữ riêng trong `.local`; lượt `r1` của
bộ bảng chỉ tạo dữ liệu đầu vào, không phải bằng chứng chạy đạt.

Kiểm độc lập không thấy lỗi mã trong phần ghép. Mã kiểm tra nguồn,
công cụ, EX5 biên dịch và hai kết quả được đối chiếu riêng trước
khi lưu Git. Các nguồn bot không đổi so với lượt trước; bộ ghép
116 tệp `.mqh` đã biên dịch sạch ở `b3-all-headers-api-20261029-r9`.

## Cách chạy và giới hạn

`kiem-noi-bang-that-khoi-dong-bot-3.py`: `generate`, `prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`. Dùng tên
lượt mới; chạy MQL5 trước mã gốc trong MT5 bot 3 riêng.

So trạng thái và từng đối số/kết quả/thứ tự dịch vụ. Dịch vụ biểu
đồ, tài khoản, lịch, giá, lệnh và kho lưu dùng dữ liệu kiểm; không
gửi lệnh thật. Chuỗi định dạng được đo từ MT5; cấp phát thành công
được cấp. Không chạy hoặc thay kết quả quyền dùng.

Chưa so ảnh bảng vẽ thật trong luồng ghép, chưa kiểm mọi lỗi cấp
phát/toàn trạng thái khi lỗi, chưa có EA đầy đủ hoặc chạy cặp hai
bot hoàn chỉnh. 56 ca đạt không phải tỷ lệ hoàn thành toàn bot.

[Số liệu và mã kiểm tra](verification.json),
[danh sách tệp](../startup-real-panels-bot3-20261029-r1-manifest.txt).
