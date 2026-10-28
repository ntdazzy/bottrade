# Nối kết quả từng chiến lược — 28/10/2026

Đã viết `BotNStrategyStatistics.mqh` và `BotNStrategyCycle.mqh`.
Phần nối gọi chuẩn bị/đánh giá trước, sau đó cập nhật thống kê nếu
thời điểm nến giờ đã đổi. Nơi điều phối phải lấy điều kiện đổi giờ một
lần trước các chiến lược bằng `BotNStrategyHourChanged`; hiện chưa có
nơi gọi điều phối hoàn chỉnh.

| Phép kiểm | Bot 1 | Bot 3 |
|---|---:|---:|
| Đoạn thống kê so với mã gốc | 1.920/1.920 ca | 2.160/2.160 ca |
| Vị trí chiến lược đã kiểm | 8 | 9 |
| Nối hai lượt trong MT5 riêng | đạt | đạt |
| Toàn bộ tệp nguồn biên dịch | 95 | 102 |
| Lỗi / cảnh báo biên dịch | 0 / 0 | 0 / 0 |

Khi biên dịch toàn bộ tệp, bốn tệp có sẵn của mỗi bot khác bản Git ở
cách xuống dòng; nội dung sau khi đưa về cùng cách xuống dòng khớp.
Phép kiểm nối và thống kê dùng đúng từng byte nguồn đã lưu trong Git.
[Chi tiết kiểm](git-newline-audit.json).

Khi so đoạn thống kê, kết quả và thay đổi số đếm của hàm lịch sử được
cấp tại chỗ gọi. Có nến giữ nguyên/đổi, số đếm âm/0/dương, tiền bằng
0, âm, dương, vô cực và số không hợp lệ; so toàn bộ các dãy. Có ca chỉ
số hiện hành khác chỉ số chiến lược đang chạy. Thân lịch sử đã được
[kiểm riêng](../strategy-history-20261028-r1/README.md).

Phép kiểm nối chạy bước chuẩn bị thật hai lần; lần hai chủ động cấp
lỗi thiếu dữ liệu để bước chuẩn bị trả sớm. Thân đánh giá và lịch sử
được thay bằng bộ ghi; kiểm thứ tự, cả khi đánh giá trả kết quả dừng,
và dữ liệu được thay đổi lúc gọi lịch sử. Không chạy toàn bộ bộ điều
phối, không so hai EA, không dùng tài khoản thật.

Các lượt cuối: `bN-strategy-statistics-20261028-r1`,
`bN-strategy-cycle-20261028-r3`, `bN-all-headers-api-20261028-r18`.
Trong lượt nối đầu, bộ kiểm bot 3 lấy sai mã mong đợi: chiến lược 1
dùng 42 + 5 = 47, không phải 44 như bot 1. Đã sửa bộ kiểm và giữ bản
kiểm cũ tại thư mục này. Lượt biên dịch tiếp theo có cảnh báo do tên
biến kiểm trùng tên trong mã, đã đổi tên biến kiểm; bản cũ được giữ
tại `strategy-cycle-20261028-r2`.

Đây là kết quả từng phần. Chưa thể suy ra tỷ lệ hoàn thành toàn bot.

## Chạy lại

Dùng tên lượt mới và MT5 riêng của từng bot. Với bot 1:

```powershell
& .\dich-nguoc\khoi-phuc\cong-cu\bien-dich.ps1 -Bot 1 -Terminal .\dich-nguoc\.local\mt5-bot1-thread-20261025 -Run b1-stats-build-new -Source .\dich-nguoc\khoi-phuc\bot-cua-toi-1\source\MQL5\Scripts\bot-cua-toi-1\Bot1StrategyStatisticsCheck.mq5 -CheckFloatingPointDividers
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-thong-ke-chien-luoc-bot-1-3.py prepare 1 b1-stats-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-thong-ke-chien-luoc-bot-1-3.py mql5 1 b1-stats-new --build b1-stats-build-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-thong-ke-chien-luoc-bot-1-3.py original 1 b1-stats-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-thong-ke-chien-luoc-bot-1-3.py compare 1 b1-stats-new
& .\dich-nguoc\khoi-phuc\cong-cu\bien-dich.ps1 -Bot 1 -Terminal .\dich-nguoc\.local\mt5-bot1-thread-20261025 -Run b1-cycle-build-new -Source .\dich-nguoc\khoi-phuc\bot-cua-toi-1\source\MQL5\Scripts\bot-cua-toi-1\Bot1StrategyCycleCheck.mq5 -CheckFloatingPointDividers
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-noi-thong-ke-chien-luoc-bot-1-3.py run 1 b1-cycle-new --build b1-cycle-build-new
```

Đổi số bot và đường dẫn tương ứng để chạy bot 3.
