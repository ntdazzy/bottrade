# Kiểm ghép toàn bộ tệp tiêu đề

Đã tạo bộ biên dịch chỉ kiểm tra cú pháp và kiểu dữ liệu, kéo toàn bộ tệp
`.mqh` hiện có của từng bot vào một đơn vị dịch:

| Bot | Tệp tiêu đề | Lỗi | Cảnh báo |
|---|---:|---:|---:|
| Bot 1 | 84 | 0 | 0 |
| Bot 3 | 91 | 0 | 0 |

Bộ này xác nhận các khối đã viết có thể cùng tồn tại và include không vỡ.
Nó chưa gọi hàm giao dịch, chưa xác nhận thứ tự chạy, khởi tạo, menu, sự
kiện hay EA hoàn chỉnh.
