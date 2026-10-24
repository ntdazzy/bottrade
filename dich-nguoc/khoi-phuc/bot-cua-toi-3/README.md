# bot-cua-toi-3

Luồng mới bắt buộc: [phân tích toàn bộ trước khi viết tiếp](../BAN-DO-TOAN-BO-BOT-1-3.md).
Bản đồ có đủ 82 hàm trong bản chụp. Đã nối 80 dòng cài đặt với vị trí
lưu và mặc định: 720/720 lần đối chiếu khớp. Đã đọc trực tiếp nhãn nhìn
thấy và bốn menu/17 lựa chọn. Còn kiểu/phạm vi, tác dụng đầy đủ và tài nguyên.
[Bảng cài đặt](../PHAN-TICH-CAI-DAT-BOT-1-3.md).

Đã dựng phần nạp vốn/tên lưu/mốc thời gian, 616/616 ca khớp mã gốc;
biên dịch 0 lỗi, 0 cảnh báo. [Menu và khởi động](../PHAN-TICH-MENU-VA-KHOI-TAO-BOT-1-3.md).

Hai đoạn chọn chiến lược khớp 7.724 ca phân tích với mã gốc, gồm đủ 512
tổ hợp bật/tắt thủ công. Nguồn `Bot3StrategySelection.mqh` khớp lại
7.724/7.724 ca; [báo cáo nguồn mới](../PHAN-TICH-CHON-CHIEN-LUOC-MQL5-BOT-1-3.md).
[Kết quả mã gốc](../PHAN-TICH-CHON-CHIEN-LUOC-BOT-3.md).

Phần vốn vừa ghép khớp 1.883/1.883 ca; kiểm ký quỹ khớp 1.141/1.141 ca.
[Bằng chứng](../PHAN-TICH-LUONG-VON-VA-KY-QUY-BOT-1-3.md).

Chưa có EA MQL5 hoàn chỉnh. Đã xuất 82 hàm từ bảng mã mới và dựng lại
hai hàm mức giá; 1.104/1.104 ca so với đoạn mã gốc trùng kết quả.

Lượt tiếp đã thêm xác nhận mức giá, lọc lệnh chờ gần và bảng tham số gốc
của 9 chiến lược: 1.096/1.096 ca mới và 54/54 giá trị khớp.
Xem [kết quả phần mới](../PHAN-TICH-VAO-LENH-BOT-1-3.md).

Lượt mới nhất thêm tính khoảng cách/thời hạn và bảng cơ bản của từng
chiến lược: 1.034/1.034 ca, 9/9 bảng khớp; biên dịch 0 lỗi, 0 cảnh báo.
Xem [phạm vi và nguồn mới](../PHAN-TICH-DIEU-CHINH-BOT-1-3.md).

Đã ghép thêm đổi tiền tệ với tính khối lượng: 966/966 ca khớp; phần đổi
tiền riêng khớp 1.530/1.530 ca. [Bằng chứng và giới hạn](../PHAN-TICH-KHOI-LUONG-BOT-1-3.md).

Đã dựng cập nhật vốn sau khi rút tiền: 915/915 ca khớp; ghi/đọc qua hai
lần mở MT5 riêng đạt. [Kết quả mới](../PHAN-TICH-RUT-TIEN-BOT-1-3.md).

- [Phân tích và giới hạn](../PHAN-TICH-BOT-1-3.md)
- [Nguồn mức giá](source/MQL5/Include/bot-cua-toi-3/Bot3PriceLevels.mqh)
- [Bộ kiểm MQL5](source/MQL5/Scripts/bot-cua-toi-3/Bot3PriceLevelsCheck.mq5)
- [Mã C trung gian hiện hành](phan-tich/luot-20261023-data/ma-trung-gian-day-du.c)
- [Danh sách hàm](phan-tich/luot-20261023-data/danh-sach-ham.json)
- [Kết quả kiểm](bang-chung/kiem-muc-gia/gia-20261023-r1/comparison.json)

Hàm `0xc30` được xuất riêng sau lần quá thời gian và ghép vào bản C đầy
đủ. Tệp gốc, phần bổ sung và mã kiểm tra đều được giữ trong thư mục phân tích.
