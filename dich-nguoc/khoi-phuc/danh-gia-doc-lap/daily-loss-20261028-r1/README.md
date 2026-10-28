# Giới hạn lỗ ngày — đã so riêng từng phần

Bot 1 và 3: **330/330 ca mỗi bot**, **4.428 lời gọi dịch vụ mỗi bot**,
**1.193 phép số học trên CPU thật mỗi bot**. Kết quả, trạng thái trước
từng dịch vụ, mã lỗi, thông báo và chuỗi hành động đều khớp từng bit.

Nguồn thật: `BotNDailyLossGuard.mqh`; dùng chung các thân đóng vị thế,
xóa lệnh chờ và gửi đã có. Bot 3 vẫn đóng/xóa khi hai cài đặt cuối tuần
tắt, đúng nhánh giới hạn lỗ ngày gốc.

| Bot | Lượt so | Bản kiểm đã biên dịch | Bản gọi trực tiếp MT5 |
|---|---|---|---|
| 1 | `b1-daily-loss-20261028-r2` | `b1-daily-loss-check-20261028-r1` | `b1-daily-loss-api-20261028-r1` |
| 3 | `b3-daily-loss-20261028-r2` | `b3-daily-loss-check-20261028-r1` | `b3-daily-loss-api-20261028-r2` |

Bốn bản trên đều 0 lỗi, 0 cảnh báo. Các lượt đo nằm tại
`bot-cua-toi-N/bang-chung/kiem-quan-ly-vi-the/`.

Ca bổ sung có hai giao dịch với số lớn làm thay đổi quyết định đóng
nếu đổi thứ tự cộng. Hai phép kiểm sai có chủ ý mỗi bot đều bị phát
hiện: đóng khi bằng ngưỡng và cộng phí qua đêm sau tổng. Chi tiết
trong `botN-negative.json`, lặp lại bằng `negative-control.py BOT RUN`.
Chỉ sửa bản dùng một lần trong bộ mô phỏng để kiểm lỗi; EX5 trên đĩa
không đổi.

Codex đã rà độc lập mã và bộ so; chưa có đánh giá mới từ Claude.
Lần gọi Claude gần nhất cùng ngày bị từ chối vì tổ chức đã tắt quyền
dùng gói, 0 đầu vào/đầu ra; [bằng chứng](../input-settings-20261028-r2/claude-access.json).
Codex tiếp tục theo ngoại lệ người dùng đã xác nhận trong AGENTS.md.

Lặp lại: biên dịch `BotNDailyLossCheck.mq5` bằng `bien-dich.ps1`, rồi
chạy `kiem-lo-ngay-bot-1-3.py prepare BOT RUN`,
`mql5 BOT RUN --build BUILD`, `original BOT RUN`, `compare BOT RUN`.
Dùng tên lượt mới; không ghi đè bằng chứng cũ.

Git lưu nguồn, công cụ và mã kiểm tra của kết quả. Các tệp nhị phân,
nhật ký và bản sao `cases.json` sinh từ công cụ được giữ tại máy.
Ba dòng lệnh máy không có toán hạng giữ dấu cách cuối dòng như lúc
trích xuất; kiểm khoảng trắng của nguồn MQL5/Python/tài liệu đều đạt.

Giới hạn đầy đủ tại [SPEC.md](SPEC.md). Đây chưa là bộ điều phối hoặc
EA hoàn chỉnh; chưa chạy cặp hai bot đầy đủ. Lượt r1 có329ca được giữ
nguyên, cùng bản công cụ trước khi thêm ca thứ330.
