# Metadata SDK bot2 — đang chờ

Hồ sơ chụp `ban-ex5-06` thuộc bản đã cài `Goldbot One MT5.ex5`:

- EX5 SHA-256: `390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795`.
- Capture PID: `22804`, tiến trình `C:/Users/NTD/Desktop/BotTradeEA/local/market-demos-20261020/dich-nguoc-luot2/terminal/metatester64.exe`.
- Vùng mã: `0x24fc8630000`, 311296 byte, SHA `c549d8a7ce64156e32c0dde4268ab1a791f424b33c5287d83fd9278e25b4d2b3`.
- Vùng engine riêng trong `capture.json` không có nhãn `kind` executable/mutable program data; vì vậy công cụ `tao-ho-so-ma-chup.py` không thể dùng hồ sơ này để tạo metadata SDK.
- Không tìm thấy `engine-observed.json` có cùng PID/tiến trình `market-demos-20261020/dich-nguoc-luot2` trong workspace. Các engine metadata hiện có thuộc tester khác hoặc bản kiểm khác; không được gán sang bot2.

## Kết luận

Chưa có raw engine proof đủ để lập target map SDK/thunk map cho bot2. Các địa chỉ `0x7ff...` trong C vẫn chỉ là địa chỉ gọi gián tiếp thô. Cần xuất lại metadata engine với đúng tester PID/engine build của capture bot2, ghi SHA engine, engine base, imported target labels/signatures và giữ liên kết PID với `capture.json`. Không chạy MT5 trong bước này.
