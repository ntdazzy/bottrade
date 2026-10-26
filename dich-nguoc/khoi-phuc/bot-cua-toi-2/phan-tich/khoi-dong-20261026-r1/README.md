# Khởi động phân tích bot2 — 26/10/2026

Đang phân tích, chưa có nguồn MQL5 hoặc phép so toàn bot.
Bot1 và bot3 vẫn tiếp tục song song theo yêu cầu hiện tại.

Đã xác định hai tệp cùng226872byte:

- Bản workspace `1-dang-tin-nhat/bot-cua-toi-2/bot-cua-toi-2.ex5`, SHA
  `0b501b712685844b8cdd17a3bf691767383e7edd727fb62c4630fe323050c557`.
- Bản đã cài `Goldbot One MT5.ex5`, SHA
  `390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795`.

Codex tự kiểm lại: khác52byte trong hai vùng chuỗi, các byte khác trùng.
Giữ riêng hai SHA; chưa xem đây là bằng chứng đầy đủ hai bản vận hành
đồng nhất. Đường dẫn và năm bộ cài đặt đã băm trong inputs-r2.json và
inputs.json. Tệp gốc/khóa cấp phép không bị sửa.

Bản chụp cũ ban-ex5-06 gắn với đúng SHA bản đã cài. Đã lập danh sách83
hàm đã chụp, đối chiếu vị trí bằng phép trừ địa chỉ đầy đủ cho đủ83hàm.
Nguồn C có SHA `00942e3bc004dbf6a12a2df4530556c13807b957a7baeb48e196e42814d9f902`.
call-map-v2.json/MD ghi dòng khai báo, SHA thân C chuẩnLF, lời gọi nội bộ,
địa chỉ gọi ngoài chưa gắn tên, nơi nhắc biến và ứng viên phép gán.
Số83không chứng minh đã thấy hoặc hiểu toàn bộ EX5.

Chưa có bản đồ đầy đủ cho đầu vào/menu, nhánh chiến lược, gửi/sửa/đóng,
lịch tin, hiển thị, khởi động/lưu trạng thái và lỗi. Đặc tả chuẩn bị
khoảng cách cũ có địa chỉ sai nên bị loại khỏi việc giao viết mã; xem
REVIEW.md. Không lấy bảng gọi hàm hoặc tên bộ rủi ro làm thuật toán.

Tiếp theo: gắn các lời gọi MT5 bằng bằng chứng, chốt từng khối chức
năng/kiểu số/thứ tự đọc ghi rồi giao Claude viết mã theo mô tả. Chưa
cần người dùng cung cấp lại tệp; đã có bản gốc đã cài và bản chụp để
phân tích tiếp.

Dùng call-map-v2.py với --json và --md trỏ hai tên đầu ra MỚI khác nhau;
không ghi đè hồ sơ cũ. Các bảng chỉ là phân tích C, chưa là nguồn EA.
README-initial-superseded.md và inputs.json giữ nhận định ban đầu để
tra; kết luận hiện hành về hai bản nằm ở đây và inputs-r2.json.
