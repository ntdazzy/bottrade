# Thời điểm tính thống kê chiến lược

Đã phục hồi đoạn nhận biết nến H1 mới trước các chiến lược. Bot nhớ thời
điểm cũ, đọc thời điểm một lần để so, và chỉ khi khác mới đọc lần hai
để lưu. Kết quả so lần đầu được giữ để dùng sau từng chiến lược; không
được so lại với thời điểm lần hai.

| Phạm vi | Bot 1 | Bot 3 |
|---|---:|---:|
| Ca so khớp | 512/512 | 512/512 |
| Lần đọc thời gian | 912 | 912 |
| Lỗi / cảnh báo biên dịch | 0 / 0 | 0 / 0 |

Mã gốc lần lượt là `0x11ed7..0x11f3f` và `0x194ef..0x19550`. So từng
lần đọc, khung H1, nến số 1, mã giao dịch, giá trị nhớ và trạng thái
sau khi chạy. Có ca đổi thời gian hoặc mã giao dịch trong lúc gọi để
kiểm đúng thứ tự đọc. Đầu vào trả lời và thay đổi này do bộ kiểm cấp.

Lượt kiểm: `b1-strategy-hour-20261028-r1` và
`b3-strategy-hour-20261028-r1` trong thư mục bằng chứng của từng bot.
Chưa chạy bộ điều phối đầy đủ hay hai EA. Hàm nguồn
`BotNStrategyHour.mqh` còn phải được nơi điều phối gọi đúng một lần
trước khi lặp chiến lược.

## Chạy lại

Dùng tên lượt mới; `generate` chỉ dùng khi tệp kiểm chưa tồn tại.

```powershell
& .\dich-nguoc\khoi-phuc\cong-cu\bien-dich.ps1 -Bot 1 -Terminal .\dich-nguoc\.local\mt5-bot1-thread-20261025 -Run b1-hour-build-new -Source .\dich-nguoc\khoi-phuc\bot-cua-toi-1\source\MQL5\Scripts\bot-cua-toi-1\Bot1StrategyHourCheck.mq5
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-gio-chien-luoc-bot-1-3.py prepare 1 b1-hour-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-gio-chien-luoc-bot-1-3.py mql5 1 b1-hour-new --build b1-hour-build-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-gio-chien-luoc-bot-1-3.py original 1 b1-hour-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-gio-chien-luoc-bot-1-3.py compare 1 b1-hour-new
```

Đổi số bot và đường dẫn tương ứng để chạy bot 3. Không biên dịch tệp
khác trong cùng máy MT5 riêng khi bộ kiểm đang chạy.
