# Chọn thời điểm chặn tin — bot1và3

Nguồn hiện hành `BotNNewsSelector.mqh` chạy đầy đủ selector7310..74f8
và7c30..7e18: **961/961ca mỗi bot**, gồm946ca kiểm lại phần số học
cũ sau sửa phép nhân phút32bit. Nguồn gọi MT5 trực tiếp và bộ kiểm
đều biên dịch0lỗi/0cảnh báo. [Bằng chứng/phạm vi mới](danh-gia-doc-lap/news-selector-20261027-r1/SPEC.md).

Hàm xóa thời điểm/nhãn, xét lần lượtNFP,lãi suất,CPI. Mỗi nhánh đủcờ
và thời điểm>0 mới đọc giờ máy chủ. Thời lượng là phút×60 ở32bit rồi
mở rộng dấu; hết hạn đúng mốc thì bỏ. Sau đọc giờ mới đọc lại thời
điểm để ghi/so với tin đã chọn. Cùng thời điểm giữ tin đứng trước,
bao gồm nhãn hiển thị. Không gom ba lần đọc giờ thành một ảnh chụp.

Phần cũ BotNNewsBlock chỉ nhận giờ làm đầu vào. Phép kiểm1.620ca cũ
chưa phủ tràn32bit/nhãn/đọc giờ đổi giữa các bước; nguồn cũ được giữ
trong hồ sơ mới. Không dùng bộ ca cũ làm bằng chứng cho toàn bộ bộlọc.

Lịch NFP đã có nguồn `BotNNfpCalendar.mqh`:1.916/1.916ca +8/8ca
mảng thiếu mỗi bot, cả bốn tổ hợp mảng xuôi/ngược. Tên được tìm là
chuỗi `Nonfarm Payrolls` ở bất kỳ vị trí, phân biệt hoa/thường; không
phải chỉ tìm tên bắt đầu bằngN. [Phạm vi lịch](danh-gia-doc-lap/nfp-calendar-20261027-r1/SPEC.md).

Đã phân tích thêm nhánhNFPdựphòng, chốt chuỗi gốc trướcStringToTime
và bảng300ô; [phân tích còn phải ghép](danh-gia-doc-lap/news-selector-20261027-r1/NFP-FALLBACK-ANALYSIS.md).
Quét/hủy mua-bán theo khoảng cách cũng đã có698/698ca mỗi bot qua
thân hủy/gửi; [phạm vi](danh-gia-doc-lap/pending-distance-20261027-r1/SPEC.md).

Còn tìm lịch lãi suất/CPI, toàn nhánh gọi lịch/dự phòng, ghép hủy/đóng
khi tin chặn, dữ liệu lịch trực tuyến, giờUTCqua mạng, lỗi cấp phát
và toànEA. Chưa thể xác nhận toàn bộ bộ lọc tin hoặc bot đạt100%.
