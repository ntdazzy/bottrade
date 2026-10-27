# Lịch sử từng chiến lược — 28/10/2026

Đã phục hồi toàn hàm `BotNStrategyClosedProfit`, bộ lưu dùng chung và
đường gọi hàm sắp xếp thật. Nguồn nằm trong `Bot1StrategyHistory.mqh`
và `Bot3StrategyHistory.mqh`. Đây là phần còn thiếu được gọi sau từng
chiến lược trong bộ điều phối; chưa phải bộ điều phối đầy đủ.

| Bằng chứng | Bot 1 | Bot 3 |
|---|---:|---:|
| Ca trả về bình thường khớp | 270/270 | 270/270 |
| Lời gọi dịch vụ đã so | 7.202 | 7.252 |
| Lần vào hàm sắp xếp gốc, kể cả đệ quy | 72 | 76 |
| Phép cộng chạy trên CPU thật | 612 | 618 |
| Nhánh lỗi dãy khớp loại lỗi/trạng thái trước khi dừng | 4/4 | 4/4 |
| Tệp ghép biên dịch cùng nhau | 88 | 95 |
| Lỗi / cảnh báo biên dịch | 0 / 0 | 0 / 0 |

Lượt đúng hiện hành: `bN-strategy-history-20261028-r3`, dùng bản
biên dịch `bN-strategy-history-check-20261028-r3`. So từng lời gọi,
phản hồi theo đầu vào, các biến, hai dãy vật lý và cờ đảo chiều,
số lần đóng từng chiến lược và bit của kết quả. Có trường hợp gọi
liên tiếp chung bộ lưu, tổng lịch sử giữ nguyên/đổi, kiểu giao dịch,
nhãn rỗng/NULL, số âm/tràn và dữ liệu đổi sau lời gọi dịch vụ.

Lượt lỗi `bN-strategy-history-fault-20261028-r2` chạy nguồn thật trên
MT5 riêng, đối chiếu bốn nơi dừng do vượt dãy: ghi mã vị thế, ghi mã
chiến lược, tìm mã vị thế và đọc mã đi kèm. So chuỗi lời gọi và toàn
trạng thái ngay trước lỗi với hàm gốc. MT5 dừng với mã 4294967295;
đây là lỗi cố ý trong bộ kiểm, không gọi là chương trình thoát thường.
Chưa so toàn bộ trạng thái hoặc nội dung thông báo sau khi runtime dừng.

## Sửa phép cộng và kiểm công cụ

Nguồn đầu dùng `+=` bị lệch dấu của số không hợp lệ khi hai đầu vào
không hợp lệ. Đã giữ nguyên thứ tự phép cộng của CPU bằng hàm số học
nhỏ; bản sai được lưu riêng và bị bộ kiểm mới từ chối ở ca 178 của
cả hai bot. Xem [đối chứng mã sai](bot1-negative.json).

Đồng thời phát hiện Unicorn cho dữ liệu NaN khác CPU thật ở 15/100
cặp đầu vào. Chạy lại bằng chương trình đo độc lập cho cùng 100 kết
quả, giống từng byte. Vì vậy bộ kiểm mới chạy chính ba lệnh `ADDSD`
trên CPU thật; giữ nguyên mã gốc, phần còn lại vẫn được mô phỏng,
dịch vụ MT5 được cấp phản hồi đo được. Không lấy kết quả từ nguồn mới
để thay câu trả lời của mã gốc và không nới sai số.

Xem [đo CPU](nan-add-cpu-probe.json), [mô tả đầy đủ](SPEC.md),
[bảng chứng cứ](verification.json). Các phép kiểm cũ có NaN cần được
rà lại bằng CPU thật trước khi dùng để xác nhận 100% toàn bot.

## Chạy lại

Từ gốc dự án, dùng tên lượt mới; MT5 của mỗi bot phải riêng. Không
biên dịch tệp khác cùng bot trong lúc chương trình kiểm đang chạy.

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-lich-su-chien-luoc-bot-1-3.py generate 1
& .\dich-nguoc\khoi-phuc\cong-cu\bien-dich.ps1 -Bot 1 -Terminal .\dich-nguoc\.local\mt5-bot1-thread-20261025 -Run b1-strategy-history-check-new -Source .\dich-nguoc\khoi-phuc\bot-cua-toi-1\source\MQL5\Scripts\bot-cua-toi-1\Bot1StrategyHistoryCheck.mq5
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-lich-su-chien-luoc-bot-1-3.py prepare 1 b1-strategy-history-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-lich-su-chien-luoc-bot-1-3.py mql5 1 b1-strategy-history-new --build b1-strategy-history-check-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-lich-su-chien-luoc-bot-1-3.py original 1 b1-strategy-history-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-lich-su-chien-luoc-bot-1-3.py compare 1 b1-strategy-history-new
```

Đổi 1 thành 3 ở bot, tên tệp, đường dẫn và tên lượt để kiểm bot 3.
Phần lỗi dùng `kiem-loi-lich-su-chien-luoc-bot-1-3.py generate N`,
biên dịch `BotNStrategyHistoryFaultCheck.mq5` rồi gọi
`run N TEN-LUOT --build TEN-BIEN-DICH`.

Chưa hoàn tất EA: còn khởi tạo, điều phối đầy đủ, các sự kiện, tác
dụng của mọi cài đặt, đối ảnh và chạy cặp hai EA cùng điều kiện.
Claude chưa đánh giá lượt này; Codex làm tiếp theo ngoại lệ đã cho phép.
EX5 gốc, khóa bản quyền và MT5 chính giữ nguyên.
