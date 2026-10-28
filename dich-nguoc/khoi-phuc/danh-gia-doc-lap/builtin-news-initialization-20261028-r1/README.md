# Dữ liệu lịch dự phòng nguyên bản

Đã lấy toàn bộ mốc từ lệnh ghi hằng của OnInit, không tính lại hoặc
cập nhật ngày theo dự đoán. Mỗi bot có ba mảng 300 ô:

| Mảng | Ô được ghi | Ô còn lại |
|---|---:|---|
| NFP | 240 | giữ nguyên |
| Lãi suất | 89 | giữ nguyên |
| CPI | 134 | giữ nguyên |

Nguồn `BotNBuiltInNewsHistory.mqh` còn đặt lại hai byte tại
`69f60/69f61` hoặc `76f90/76f91`. Tên tham số hiện giữ dạng cờ bản gốc;
vẫn cần nối vào đúng trạng thái dùng chung khi tạo EA. Bot 3 có thêm
`MQLInfoInteger(6)` sau hai lần đặt cờ, trước khi ghi lịch; kết quả
không được dùng để đổi nhánh.

Nguyên đoạn `1941..3827` và `193f..3840` đã chạy đối chiếu. Mỗi bot
khớp **108/108 ca**, so đủ **900 ô**, hai cờ, thứ tự đọc thông tin và
thay đổi trong lần đọc. Đã thử mảng có sẵn dữ liệu khác 0 để bắt lỗi
xóa nhầm đuôi; bot 3 có ca thay đổi cờ/ô đuôi/ô đầu trong dịch vụ.
Hai bản kiểm biên dịch 0 lỗi, 0 cảnh báo. Chưa là toàn OnInit/EA và
không kiểm mảng sai kích thước hoặc lỗi cấp phát.

`bot1-native.json` / `bot3-native.json` chứa các giá trị, vị trí và mã
băm. Chương trình kiểm xác nhận mọi lần ghi mốc là lệnh ghi hằng,
không lấy dữ liệu từ bản MQL5 để tạo kết quả gốc.

Lượt đúng: `bN-builtin-news-20261028-r1`, bản biên dịch
`bN-builtin-news-check-20261028-r1`. Hai bộ lịch có cùng các mốc đã
trích xuất; vẫn giữ bằng chứng riêng của đúng EX5 từng bot.

## Chạy lại

Dùng `kiem-du-lieu-lich-tin-bot-1-3.py` với các bước
`prepare BOT RUN`, `mql5 BOT RUN --build BUILD`, `original BOT RUN`,
`compare BOT RUN`; biên dịch `BotNBuiltInNewsHistoryCheck.mq5` trước
bằng `bien-dich.ps1`. Dùng tên lượt mới và MT5 riêng của từng bot.
`generate BOT` chỉ dùng khi chưa có nguồn và bằng chứng trích xuất.
