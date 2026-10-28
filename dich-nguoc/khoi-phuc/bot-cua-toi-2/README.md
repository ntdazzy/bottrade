# bot-cua-toi-2

Đã chốt từ báo cáo đúng EX5: **62 cài đặt và 8 tiêu đề** theo thứ
tự, cùng giá trị của lượt chạy. Ba mục GMT được truyền đè đã đối
chiếu với cấu hình chạy. Kiểu khai báo, mặc định và vị trí lưu còn
chưa rõ; chưa viết khối nhập liệu theo suy đoán.
[Danh sách và bằng chứng](../danh-gia-doc-lap/inputs-bot2-20261029-r1/README.md).

Đã phục hồi hai chiều đổi tiền: **1.650/1.650 ca khớp từng byte**,
gồm toàn bộ thứ tự đọc tiền tệ/tỷ giá; thêm 4 ca chia 0 khớp loại
lỗi và lời gọi trước lỗi. Giữ nguyên nhánh CHF bị lặp của bản gốc.
Hai tệp `.mqh` hiện hành biên dịch 0 lỗi, 0 cảnh báo; chưa có EA đầy đủ.
[Bằng chứng](../danh-gia-doc-lap/currency-bot2-full-20261029-r1/README.md).

Đã phục hồi hàm đổi giờ mùa hè `Bot2AmericanDST`: **4.737/4.737 ca
khớp**, kể cả thứ tự lời gọi; biên dịch 0 lỗi, 0 cảnh báo. Dùng đúng
bản EX5 đã cài, SHA bắt đầu `390d8ab1`; bản EX5 cũ trong kho khác mã.
[Bằng chứng và giới hạn](../danh-gia-doc-lap/american-dst-bot2-20261029-r5/README.md).

Đang phân tích song song theo yêu cầu26/10/2026; bot1 vàbot3 vẫn ưu tiên.
Đã có bản chụp mới đúng EX5Goldbot One MT5 đã cài:86dải hàm,680chuỗi,
141nhãn dịch vụ đã đối chiếu cùng bản máy thử,81chữ ký. Đã xuất mã C
trung gian cho đủ86dải, giữ kết quả lỗi/hết thời gian ban đầu để tra.

**Chưa có EA MQL5 phục hồi hoặc phép so hai EA.** Xuất được C không có
nghĩa đã hiểu hoặc khôi phục thuật toán.

- [Danh sách mới có mã băm từng hàm](phan-tich/luot-20261026-data-r2/inventory-v3/inventory-v3.md).
- [Bằng chứng kiểm bản chụp](phan-tich/luot-20261026-data-r2/root-verification.json).
- [Hai bản EX5 và năm bộ cài đặt](phan-tich/khoi-dong-20261026-r1/README.md).

Cần chốt cài đặt, công thức/nhánh, thứ tự gọi và trạng thái từ bản mới,
rồi Codex viết và kiểm từng phần. Bản83hàm cũ giữ riêng, không
dùng số86để kết luận đã thấy toàn bộ EX5.

Đã đọc thêm raw đầu hàm đánh giá186c0..1f2b3, kiểm lạiSHA thân vàEX5,
chốt chỗ nhận chỉ số/giờ/lịch và cờ đầu; [bằng chứng mới](phan-tich/evaluation-entry-20261027-r1/README.md).
Chưa viết mã trước khi chốt các nhánh còn lại.
