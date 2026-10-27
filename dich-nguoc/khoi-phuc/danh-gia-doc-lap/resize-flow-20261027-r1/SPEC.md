# Chuỗi kiểm vốn → tính khối lượng → tạo lại lệnh chờ

| Điểm trong evaluator | Bot 1 | Bot 3 |
|---|---|---|
| Đầu kiểm vốn | `1a6e5` | `22920` |
| Mốc vốn lưu | `67480` | `744c0` |
| Cờ chọn số nhân | `62554` | `6d644` |
| Khoảng dừng lỗ | `62498` | `6d588` |
| Lệnh gọi khối lượng | `1a815→34780` | `22a57→3f900` |
| Trở về và quét lệnh chờ | `1a817` | `22a59` |
| Kết thúc chuỗi | `1b317` | `235f7` |

Codex đã đọc raw của điểm nối trước khi viết. Mã kiểm toàn evaluator
và đoạn kiểm nằm trong native-evidence.json. Thân khối lượng/rút tiền/
đổi tiền được chốt ở volume-runtime-20261027-r1; thân xóa/mở/gửi ở
pending-resize-20261027-r1 của từng bot. Không đổi thân con thành kết quả cấp sẵn.

Hàm nguồn BotNRefreshEvaluationPending gọi ba phần hiện hành theo đúng
thứ tự. Cổng vốn bỏ qua thì không gọi dịch vụ, không tính lại khối lượng,
không quét lệnh chờ. Khi chọn thay đổi, bot1 ghi mốc=vốn hiệu lực tại
1a7eb; bot3 không ghi mốc. Cờ chọn số nhân là byte: khác0→100, bằng0→0;
đọc khoảng dừng lỗ trước gọi hàm khối lượng. Không thay bằng số nhân luôn100.

Khối lượng đọc tài khoản/giá theo thân gốc rồi ghi trực tiếp vào mảng
chiến lược dùng chung. Tiếp tục vào vòng lệnh chờ, giữ chung chỉ số,
mảng khối lượng, mã nhận diện, tên mã, ô lệnh cuối, bảng100×2 và trạng
thái yêu cầu/kết quả giao dịch. Không sao chép hoặc đặt lại trạng thái
ở ranh giới hàm. Hàm trảbool để quan sát cổng có đi tiếp hay không;
không thêm hành động giao dịch theo giá trị này.

Bộ kiểm dùng dữ liệu điều kiện trước cổng được cấp. Mã máy chạy từ đầu
cổng qua nguyên các hàm khối lượng, rút tiền, đổi tiền, xóa, mở lệnh,
chọn khớp và gửi, tới điểm cuối; chỉ cấp trả lời dịch vụ MT5/cấp phát/
chuỗi số đo trong MT5 riêng. Bộ trả lời phần khối lượng và phần giao
dịch cùng dùng một bộ nhớ native; không khởi tạo lại giữa hai phần.

Nguồn kiểm MQL5 dùng chung ResizeIndex/ResizeVolumes cho cả hai phần;
có ca đổi chỉ số trong lần đọc giá và đổi mảng/chỉ số/tên mã/loại lệnh
sau gửi. So từng byte trạng thái trước dịch vụ phần khối lượng, mốc vốn,
đủ8/9ô khối lượng, toàn200ô bảng và35trường/4chuỗi giao dịch ở các ranh giới.
Chuỗi dịch vụ phần khối lượng và giao dịch được lưu riêng rồi ghép
đúng thứ tự thực thi khi so. Nội dung và kiểu dữ liệu chuỗi số được
MT5 riêng đo trước, không dùng kết quả thuật toán của nguồn mới làm đáp án.

Hai ca lỗi mỗi bot: cổng chia0 trước dịch vụ, hoặc hàm khối lượng chia0
sau cổng đã chọn. Chạy từng ca trong MT5 riêng, bật kiểm chia0, so nhật
ký mới/mã ca, dừng thật, không có bản ghi bình thường và toàn bộ sự kiện
đã hoàn tất trước lỗi. Trạng thái thay đổi sau dịch vụ cuối ngay tại
điểm lỗi vẫn chưa được Script bị dừng xuất ra.

Đây chưa là toàn evaluator hoặc EA. Cần nối trạng thái từ các bước
trước cổng và phần lọc tin/giờ/giới hạn/điểm vào phía sau, rồi so hai EA
hoàn chỉnh trên cùng dữ liệu. Không suy từ632ca của chuỗi này ra100%toàn bot.
