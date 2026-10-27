# Kiểm vòng đời khi thoát

Đã viết `Bot1Lifecycle.mqh` và `Bot3Lifecycle.mqh` theo thân native, rồi
chạy bản gốc và bản MQL5 riêng trên cùng bốn ca:

- cờ dọn 300 dòng tắt/bật;
- tay cầm chỉ báo `-1`/`42`.

| Bot | Ca khớp | Số lời gọi sự kiện từng ca | Kết quả |
|---|---:|---|---:|
| Bot 1 | 4/4 | 3.049, 3.050, 4.249, 4.250 | 4/4 |
| Bot 3 | 4/4 | 3.050, 3.051, 4.250, 4.251 | 4/4 |

Bộ kiểm soát cả tên và thứ tự `ObjectDelete`, lời gọi đổi số sang chữ,
`IndicatorRelease`, giá trị tay cầm sau khi giải phóng và
`ObjectsDeleteAll(0,-1,-1)`. Bằng chứng dùng EX5 gốc có SHA-256 đã khóa;
EX5 gốc không bị sửa.

Phạm vi này chỉ xác nhận hàm dọn khi thoát. Khối khởi tạo đầy đủ, đăng ký
sự kiện, menu/tài nguyên và EA hoàn chỉnh vẫn chưa được xác nhận.
