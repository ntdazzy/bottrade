# Điều kiện chạy theo giờ/nến — đã so riêng từng phần

Bot 1 và 3: **640/640 ca mỗi bot**, **1.159 lời gọi dịch vụ mỗi bot**.
Chạy từ điểm vào hàm điều phối gốc và dừng trước cờ hoạt động/kiểm
quyền dùng. So mọi đối số, trạng thái trước dịch vụ, mã lỗi và kết quả.

Nguồn: `BotNDispatchGate.mqh`. Lượt so `bN-dispatch-gate-20261028-r2`;
bản kiểm `bN-dispatch-gate-check-20261028-r3`, bản gọi MT5 trực tiếp
`bN-dispatch-gate-api-20261028-r1`: cả bốn bản 0 lỗi, 0 cảnh báo.

Hai bản sai có chủ ý mỗi bot bị phát hiện: để cờ cũ chặn nến mới,
và coi mọi byte khác0 là dừng. Kết quả ở `botN-negative.json`.
Codex đã rà độc lập; chưa có đánh giá Claude mới.

Lặp lại: `kiem-cong-dieu-phoi-bot-1-3.py generate BOT`, biên dịch
`BotNDispatchGateCheck.mq5`, rồi lần lượt `prepare BOT RUN`,
`mql5 BOT RUN --build BUILD`, `original BOT RUN`, `compare BOT RUN`.
Kiểm sai: `negative-control.py BOT RUN`. Luôn dùng tên lượt mới.

[Thuật toán, vị trí và giới hạn](SPEC.md). Chưa là toàn bộ điều phối
hoặc EA; không có kiểm quyền dùng, lệnh tài khoản thật hoặc phép so
hai bot đầy đủ trong bộ kiểm này.
