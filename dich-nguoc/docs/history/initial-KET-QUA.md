# Kết quả thử phân tích sâu các tệp EX5

**Chưa khôi phục được mã nguồn của bot nào.** Đã thử trực tiếp trên toàn bộ 17 tệp, tương ứng 15 tên bot.

## Đã thử và kết quả

- Đọc toàn bộ từng tệp, tìm chữ và dấu mã nguồn phổ biến bằng hai cách lưu chữ thường gặp (ASCII và UTF-16LE). Chưa tìm thấy các dấu `#property`, `#include`, `OnTick(`, `OnInit(`, `OrderSend(`.
- Tìm chương trình Windows nằm trong tệp, kiểm cả phần đầu và bảng vùng dữ liệu: không tìm thấy phần đủ cấu trúc để đưa vào bộ đọc mã Windows.
- Thử giải nén 1182 vị trí có dấu nhận dạng thông dụng. Có 6 phần giải nén đủ; cả 6 nằm trong ảnh PNG của MoonDog.
- Tách được 7 ảnh PNG của MoonDog, kiểm số kiểm tra của từng phần ảnh và giải nén đầy đủ dữ liệu ảnh. Đây là dữ liệu hình ảnh, chưa phải luật giao dịch.
- Chưa giải được lớp chứa lệnh của EX5; chưa chạy bộ dịch ngược lệnh máy hoặc đọc bộ nhớ MT5 đang chạy.

## Vì sao chưa thể đưa ra mã MQ5

- Tệp EX5 có cấu trúc riêng. Nhóm phát triển Ghidra cho biết cần phần đọc định dạng riêng; yêu cầu tương tự tháng 05/2026 vẫn dẫn về vấn đề này.
- Bài nghiên cứu tìm được của 0xMastEB nhắm EX4/MT4 bản 1471, khác các EX5 ở đây. Chưa có căn cứ dùng thuật toán hoặc vị trí dữ liệu của bài đó cho các bot này.
- Tìm qua danh mục GitHub thấy ba kho mang mô tả dịch ngược EX5/EX4, nhưng chưa xác nhận được có mã công cụ dùng được. Yêu cầu đọc cây tệp bị giới hạn số lượt, mã HTTP 403. Không coi lời quảng cáo là bằng chứng dịch ngược thành công.
- Không tạo tệp MQ5 từ phỏng đoán. Muốn đi tiếp theo hướng dịch ngược cần xác định cách EX5 được nạp và giải mã, rồi kiểm từng hàm; lượt này chưa làm được bước đó.

## Từng tệp đã thử

| Tệp | Vị trí thử giải nén | Giải nén đủ | Ảnh PNG tách được |
|---|---:|---:|---:|
| `mt5-btc-recovery/AI Golden Life MT5.ex5` | 36 | 0 | 0 |
| `mt5-btc-recovery/CryonX EA MT5.ex5` | 28 | 0 | 0 |
| `mt5-btc-recovery/Dynamic Liquidity Intelligence.ex5` | 9 | 0 | 0 |
| `mt5-btc-recovery/Gold Beaver.ex5` | 42 | 0 | 0 |
| `mt5-btc-recovery/Gold Trade Pro MT5.ex5` | 13 | 0 | 0 |
| `mt5-btc-recovery/Goldbot One MT5.ex5` | 15 | 0 | 0 |
| `mt5-btc-recovery/MoonDog EA.ex5` | 663 | 6 | 7 |
| `mt5-btc-recovery/Quantum Titan MT5.ex5` | 4 | 0 | 0 |
| `mt5-btc-recovery/TwisterPro Scalper.ex5` | 10 | 0 | 0 |
| `mt5-btc-recovery/Ultimate Breakout System.ex5` | 16 | 0 | 0 |
| `mt5-program-files/EA Super Trend XAUUSD.ex5` | 15 | 0 | 0 |
| `mt5-program-files/My AI Gold.ex5` | 234 | 0 | 0 |
| `mt5-program-files/Quantum Queen X MT5.ex5` | 25 | 0 | 0 |
| `mt5-program-files/Quantum Titan MT5.ex5` | 5 | 0 | 0 |
| `mt5-program-files/Scalping Robot Pro MT5.ex5` | 23 | 0 | 0 |
| `mt5-program-files/The Gold Reaper MT5.ex5` | 15 | 0 | 0 |
| `mt5-program-files/Ultimate Breakout System.ex5` | 29 | 0 | 0 |

## Các ảnh tách được

- [MoonDog-offset-11110586.png](MoonDog-offset-11110586.png): 16 × 16, 936 byte.
- [MoonDog-offset-11111522.png](MoonDog-offset-11111522.png): 24 × 24, 1,840 byte.
- [MoonDog-offset-11113362.png](MoonDog-offset-11113362.png): 32 × 32, 3,021 byte.
- [MoonDog-offset-11116383.png](MoonDog-offset-11116383.png): 48 × 48, 6,161 byte.
- [MoonDog-offset-11122544.png](MoonDog-offset-11122544.png): 64 × 64, 10,293 byte.
- [MoonDog-offset-11132837.png](MoonDog-offset-11132837.png): 128 × 128, 37,710 byte.
- [MoonDog-offset-11170547.png](MoonDog-offset-11170547.png): 256 × 256, 137,318 byte.

Mọi vị trí, mã kiểm tra, lỗi giải nén và phương pháp được lưu trong `chi-tiet.json`. Tệp bot gốc được giữ nguyên.

## Nguồn đã đối chiếu

- [mql5_cloud_protector](https://www.metatrader5.com/en/metaeditor/help/development/mql5_cloud_protector)
- [1173](https://github.com/NationalSecurityAgency/ghidra/issues/1173)
- [9211](https://github.com/NationalSecurityAgency/ghidra/issues/9211)
- [metatrader-analysis.md](https://github.com/0xMastEB/0xMastEB.github.io/blob/main/posts/metatrader-analysis.md)
