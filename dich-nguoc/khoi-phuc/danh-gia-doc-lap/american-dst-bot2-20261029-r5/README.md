# Hàm đổi giờ mùa hè — bot 2

`Bot2AmericanDST.mqh` phục hồi nguyên hàm `0x17440..0x17917` từ
bản chụp nền `0x253f2620000`. Kiểm đúng EX5 đã cài, SHA
`390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795`;
không dùng bản EX5 khác mã trong kho.

- **4.737/4.737 ca khớp**, kết quả và thứ tự lời gọi giống từng byte.
- Giữ ngưỡng năm 1987/2007, công thức và việc loại cả hai ngày biên.
- Kiểm ngày thường/sát biên, giờ đổi giữa các lần đọc, số năm sát
  giới hạn, chuyển ngày thất bại sau lần đầu và chuỗi ngày trả 0.
- Bộ chạy kiểm đúng vùng làm việc của dịch vụ, vùng nhớ chuỗi được
  cấp và giải phóng; không bỏ qua thân hàm hoặc nới vùng được chạy.
- Biên dịch `b2-american-dst-20261029-r1`: 0 lỗi, 0 cảnh báo.
  Kiểm độc lập đã xác nhận mã hiện tại khớp biên nhận/bằng chứng.

Mã SHA của phần mã chụp là `ae4e9020f7f5f08d49774728bed14c17eb2bd26b6271c20da51bd3aaa446014f`,
của thân hàm là `387ac43a69b29852283f875ee393710e7cca3fb785dcfddbff71d48ce953e3a7`.

Giới hạn: thời gian được cấp; kết quả phép chia dư, lịch và chuỗi
được đo thật trong MT5 riêng rồi cấp ở chỗ gọi dịch vụ của mã máy.
Chưa kiểm lần chuyển ngày đầu không ghi dữ liệu, lỗi cấp phát hoặc
ghép hàm vào toàn bộ EA. Số ca này không phải tỷ lệ hoàn thành bot 2.

Chạy lại: `cong-cu/kiem-gio-mua-he-bot-2.py prepare RUN`,
`mql5 RUN --build BUILD`, `original RUN`, `compare RUN`. Dùng tên
lượt mới; chạy MQL5 trước mã máy gốc. Máy thử dùng thư mục riêng
`dich-nguoc/.local/mt5-bot1-thread-20261025` và tắt giao dịch.

[Số liệu](verification.json), [kiểm tệp bàn giao](publication-verification.json),
[danh sách tệp](../american-dst-bot2-20261029-r5-manifest.txt).
