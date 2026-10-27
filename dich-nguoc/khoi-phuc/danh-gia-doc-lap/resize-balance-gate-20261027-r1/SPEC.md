# Cổng thay đổi vốn trước tính khối lượng và tạo lại lệnh

Codex đọc raw trước khi viết. Bot1 trong evaluator18aa0..1ef9c SHA
45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd;
bot3 trong20ef0..2a1bc SHA6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920.

| Thao tác | Bot1 | Bot3 |
|---|---|---|
| Đầu cổng |1a6e5|22920|
| Vốn hiệu lực |6a320|1d6c60|
| Mốc so trước |67480|744c0|
| Phần trăm thay đổi |62528|6d618|
| Không đổi/bỏ qua |1b317|235f7|
| Đã chọn nhánh gọi tính khối lượng |1a7e1|22a28|
| Cờ chọn hệ số100/0 |62554|6d644|
| Khoảng dừng lỗ truyền XMM0 |62498|6d588|
| Lệnh gọi tính khối lượng |1a815 (34780)|22a57 (3f900)|
| Lỗi chia0 |1ed65|29dc5|

Nguồn `BotNPendingResizeBalance.mqh` gồm hàm thuần
`bool BotNCheckResizeBalance(const double current,double &previous,
const double change_percent)`. Không gọi SDK, tính khối lượng hoặc
vòng lệnh trong hàm này. Đây là cổng cần nối, không thay hàm con bằng
trả lời giả trong mã bàn giao.

1. So current với previous theo phép bằng có thứ tự. Bằng thì false,
   giữ previous nguyên từng bit. NaN làm không bằng, tiếp bước2.
2. factor=change_percent/100.0+1.0, đúng thứ tự chia rồi cộng.
3. Nếu current>previous*factor (so chặt, có thứ tự) thì chọn thay đổi;
   không tính previous/factor trong nhánh này, kể cả factor=0.
4. Còn lại tính previous/factor. Nếu factor bằng±0, chương trình phải
   dừng do phép chia thực, không trảfalse/true thay cho lỗi.
   Nếu previous/factor>current thì chọn thay đổi; còn lại false.
   NaN ở factor hoặc thương làm so>thất bại, không tự báo lỗi NaN.
5. Nếu chọn thay đổi, BOT1 ghi previous=current trước khi gọi tính
   khối lượng (`1a7eb`), BOT3 KHÔNG ghi ô previous trong cổng này.
   Sau đó trảtrue. Không sửa hành vi khác nhau này.

Biên dịch bật kiểm chia0. Phép so thường chạy từ đầu cổng raw tới
ngay trước call tính khối lượng hoặc điểm bỏ qua, không thay nhánh;
so kết quả cổng và mốc lưu. Ca chia0 phải chạy riêng trong MT5, so
lỗi/dừng và trạng thái mốc khi native gọi runtime-error3959a0.
SDK/các hàm con không cần để kiểm cổng này; không suy từ đây ra toàn
hàm tính khối lượng, vòng tạo lại lệnh hoặc EA đã chạy song song.
