# Phạm vi hoàn thành bot 1 và bot 3

Mục tiêu: khôi phục đầy đủ hai bot đang làm, có nguồn MQL5 hoàn chỉnh,
biên dịch được và đối chiếu hoạt động với bản gốc. Chưa đạt hoàn thành.
Không lấy số ca kiểm của một phần để thay cho mức hoàn thành toàn bộ bot.

Luồng bắt buộc: phân tích kỹ và lập danh sách toàn bộ các phần trước,
rồi mới viết tiếp từng phần. Quy tắc có hiệu lực tại [AGENTS.md](../../AGENTS.md).
Danh sách phải bao gồm mọi lựa chọn cài đặt và phần hiển thị; chỗ chưa
rõ phải được giữ lại trong bảng theo dõi đến khi đã kiểm xong.

Danh sách hiện hành: [33 phần bắt buộc và toàn bộ hàm/cài đặt đã thấy](BAN-DO-TOAN-BO-BOT-1-3.md).
Việc liệt kê không đồng nghĩa đã phân tích xong toàn bộ EX5; các khoảng
chưa rõ vẫn đang được xử lý trước khi viết phần tương ứng.

| Hạng mục bắt buộc | Bằng chứng hiện có | Còn thiếu |
|---|---|---|
| Đúng bản gốc và đầu vào | 72/80 dòng đã nối, đọc nhãn trên cửa sổ và 28 lựa chọn/7 menu | Kiểu/phạm vi, ký tự nhãn ẩn, khai báo và ghép toàn bộ đầu vào của EA dựng lại |
| Khởi tạo, các sự kiện và thoát | Mã trung gian 84/82 hàm; nạp vốn/tên lưu/mốc giờ dựng và so 616 ca mỗi bot | Ghép EA, nối đủ sự kiện, chỉ báo, xử lý thất bại và giải phóng |
| Chọn chiến lược và tham số | Bảng 8/9 chiến lược; bot 1 đã so 256 tổ hợp bật/tắt, bot 3 đã so 7.724 ca riêng hai đoạn chọn | Ghép phần chọn, nguồn cờ/trạng thái, quản lý khi tắt, điều chỉnh thêm và ngẫu nhiên |
| Điều kiện mua/bán | Mức giá, kiểm giá bị phá, lọc lệnh chờ gần đã so | Ghép đầy đủ các điều kiện vào lệnh |
| Khối lượng và trạng thái vốn | Đổi tiền, tính khối lượng, rút tiền, luồng vốn/ký quỹ và nạp trạng thái đã so theo phần | Ghép EA chính, kiểm cùng tài khoản, bước/nhỏ nhất/lớn nhất khối lượng, mã lỗi/thông báo |
| Đặt/sửa/hủy/đóng lệnh | Mã trung gian hiện có | Khôi phục cả hai chiều, lỗi, thử lại và hết hạn |
| Dừng lỗ/chốt lời và dời lệnh | Tham số khoảng cách đã so | Toàn bộ luật sau khớp, dừng/chốt ảo và các chế độ đặc biệt |
| Giới hạn lỗ và lịch sử giao dịch | Một phần lịch sử rút tiền đã so | Giới hạn ngày/tổng, cập nhật theo giao dịch, các trường hợp dữ liệu thiếu |
| Thời gian và tin tức | Mã trung gian hiện có | Giờ mùa hè, giờ giao dịch, bộ lọc tin và lỗi dữ liệu |
| Hiển thị và thao tác | Bản EX5 gốc và mã trung gian | Trích tài nguyên, bảng hiển thị, đối tượng trên biểu đồ và các thao tác được hỗ trợ |
| Đối chiếu toàn bộ và bàn giao | Các phần riêng có bằng chứng | EA chính, tài nguyên, biên dịch sạch, so từng lệnh cùng điều kiện, hướng dẫn sử dụng |

Các báo cáo theo phần ghi phạm vi và giới hạn cụ thể. Chỉ coi mục tiêu
đạt khi từng hàng đã có bằng chứng trực tiếp, nguồn hiện hành khớp bản
đã kiểm và không còn phần bắt buộc bị bỏ hoặc sai khác chưa giải quyết.

Chỉ dùng MT5 riêng cho phép thử. Việc chạy trên tài khoản thật không
thuộc lượt khôi phục này.
