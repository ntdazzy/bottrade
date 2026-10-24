# Phân tích bật/tắt chiến lược bot 1 — 23/10/2026

Đã so đủ **256 cách bật/tắt tám chiến lược**, tổng cộng **2.048 lần
kiểm nhánh gốc**. Tất cả khớp. Đã viết MQL5 cho riêng các cổng này;
[bằng chứng và giới hạn](PHAN-TICH-CHON-CHIEN-LUOC-MQL5-BOT-1-3.md).

| Cài đặt | Chỉ số chiến lược | Vị trí nhánh bật/tắt |
|---|---|---|
| `RunStrategyA` | 0 | `0x12463` |
| `RunStrategyB` | 1 | `0x12fcf` |
| `RunStrategyC` | 2 | `0x138d3` |
| `RunStrategyD` | 3 | `0x140fe` |
| `RunStrategyE` | 4 | `0x147f8` |
| `RunStrategyF` | 5 | `0x14f23` |
| `RunStrategyG` | 6 | `0x1581b` |
| `RunStrategyH` | 7 | `0x15efb` |

Mỗi nhánh đọc đúng vị trí đầu vào đã nối, so với 0 rồi đi vào phần
tham số của chiến lược khi bật; tắt thì nhảy qua. Chỉ số lấy từ bằng
chứng bảng tham số gốc đã kiểm, không lấy từ tên tự đặt.

[Tóm tắt và lệnh gốc](bot-cua-toi-1/phan-tich/bat-tat-chien-luoc/enable-20261023-r3/summary.json),
[256 tổ hợp](bot-cua-toi-1/phan-tich/bat-tat-chien-luoc/enable-20261023-r3/results.json),
[công cụ](cong-cu/phan-tich-bat-tat-bot-1.py).

Chỉ chạy các lệnh đọc/so và nhảy, dừng trước cả hai đích; không chạy
thân chiến lược hay gọi MT5. Vì vậy phép kiểm này chưa chứng minh điều
kiện vào lệnh, quản lý vị thế khi tắt, thứ tự ghép toàn bộ hoặc nguồn
MQL5 dựng lại. Các phần đó vẫn nằm trong bản đồ để phân tích tiếp.

Hai lượt đầu chưa tạo kết quả đạt. Cách dừng cũ để bộ mô phỏng chạy
quá nhánh cần kiểm khi chuyển sang đoạn tiếp, báo
`UC_ERR_FETCH_UNMAPPED`. Đã thay bằng theo dõi từng lệnh và dừng trước
hai đích; gặp lệnh ngoài đoạn cần kiểm sẽ báo lỗi. Bằng chứng:
[lỗi lượt r2](bot-cua-toi-1/phan-tich/bat-tat-chien-luoc/enable-20261023-r2/failure.json).
Chỉ dùng lượt r3 cho kết luận ở trên.
