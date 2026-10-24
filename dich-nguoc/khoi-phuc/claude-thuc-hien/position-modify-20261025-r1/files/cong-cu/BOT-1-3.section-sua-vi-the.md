## Sửa dừng lỗ/chốt lời theo vé

- `phan-tich-goi-sua-vi-the-bot-1-3.py BOT NEW_RUN`: đọc bản chụp, liệt
  kê mọi chỗ gọi `0x26d20`/`0x32a90`, lệnh ghi RCX/XMM1/XMM2 trong cùng
  khối và cách dùng RAX sau gọi. Ghi `caller-sites.json` vào
  `phan-tich/dong-vi-the/NEW_RUN/`; không chạy mã bot hoặc MT5.
- `kiem-sua-vi-the-bot-1-3.py MODE BOT RUN [--build BUILD]`: thứ tự
  `prepare` → biên dịch `BotNPositionModifyCheck.mq5` → `mql5 --build`
  → `original` → `compare`. Mã gốc chạy tới lệnh trả, gồm gửi/thông
  báo và hàm chuỗi; phải chạy đủ 196 lệnh của hàm. Chỉ cấp cờ dừng, kết
  quả chọn vé/đọc mã giá và kết quả gửi; không gửi lệnh thật. Sơ đồ tệp:
  [kiem-sua-vi-the-bot-1-3-schema.md](kiem-sua-vi-the-bot-1-3-schema.md).

Cần có trước `prepare`: `BotNPositionModify.mqh`, `BotNPositionModifyCheck.mq5`
và `semantics.json` trong `phan-tich/dong-vi-the/modify-20261025-r1/`.
Chưa có lượt chạy đạt; số ca đạt không phải tỷ lệ hoàn thành toàn bot.
[Phân tích](../PHAN-TICH-SUA-VI-THE-BOT-1-3.md).
