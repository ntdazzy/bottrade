# Kiểm tra khả năng dịch ngược các bot

Ngày kiểm tra: 20/10/2026. Phạm vi: toàn bộ tệp trong thư mục này, gồm tệp nén và tệp nén lồng bên trong.

**Chưa dịch ngược được bot nào thành mã nguồn `.mq5`. Báo cáo này là kết quả kiểm tra tệp, không phải mã nguồn đã khôi phục.**

Đã thử phân tích sâu tiếp theo yêu cầu của người dùng: xem [kết quả mới](thu-dich-nguoc/KET-QUA.md).

- Có 17 tệp `.ex5`, tương ứng 15 tên bot; cả 17 có dấu định dạng `EX5`.
- Đã kiểm 398 tệp ban đầu. Không tìm thấy tệp `.mq5`, `.mq4`, `.mqh` hoặc `.mqproj` bên ngoài hay trong các tệp nén.
- Có 4 tệp ZIP trên đĩa; đã kiểm 5 lượt tệp nén, gồm bản ZIP nằm bên trong ZIP khác.
- Có 372 tệp `.set` và 2 tài liệu PDF trên đĩa. Những tệp này chưa được phân tích để xác định luật giao dịch trong lượt này.
- Hai tên có hai bản khác nội dung: `Quantum Titan MT5` và `Ultimate Breakout System`. Khác mã kiểm tra không đủ để kết luận khác phiên bản hoặc khác luật giao dịch.

## Căn cứ và giới hạn

- Tài liệu MetaEditor xác nhận `.ex5` là sản phẩm biên dịch từ mã nguồn, có định dạng riêng che thuật toán; có thể phân phối riêng mà không kèm `.mq5`/`.mqh`.
- Tài liệu MetaQuotes mô tả cơ chế bảo vệ chống dịch ngược và bảo vệ bổ sung đối với sản phẩm Market. Đây là mô tả của nhà cung cấp, không phải phép đo mức bảo vệ riêng của từng tệp ở đây.
- Đọc được tên tác giả hoặc liên kết ở đầu tệp không có nghĩa đã đọc được điều kiện vào lệnh, dừng lỗ, chốt lời hoặc cách tính khối lượng.
- Không dùng công cụ dịch ngược trong lượt này; chưa có quy trình đã kiểm chứng để chuyển các bản này thành mã nguồn có thể sửa và biên dịch lại.
- Không khởi chạy bot hoặc MT5, không đo lại lợi nhuận, không thay đổi tệp ban đầu.

## Kết quả từng tệp

Mọi hàng dưới đây đều có kết quả: **chưa khôi phục mã nguồn**. Mã kiểm tra đầy đủ ở `kiem-tra-dich-nguoc.json`.

| Tệp | Dung lượng (byte) | Mã kiểm tra rút gọn |
|---|---:|---|
| `mt5-btc-recovery/AI Golden Life MT5.ex5` | 600,464 | `7F162ECCA001271C` |
| `mt5-btc-recovery/CryonX EA MT5.ex5` | 775,396 | `0791D1A189DC1805` |
| `mt5-btc-recovery/Dynamic Liquidity Intelligence.ex5` | 127,938 | `E69FAB805E88ED53` |
| `mt5-btc-recovery/Gold Beaver.ex5` | 762,912 | `EA5174FE310381AF` |
| `mt5-btc-recovery/Gold Trade Pro MT5.ex5` | 237,660 | `A3B0DE423A06E10E` |
| `mt5-btc-recovery/Goldbot One MT5.ex5` | 226,872 | `390D8AB14FC213FF` |
| `mt5-btc-recovery/MoonDog EA.ex5` | 11,307,865 | `D019AE0232A15A12` |
| `mt5-btc-recovery/Quantum Titan MT5.ex5` | 168,798 | `74A780C9CF6E2C82` |
| `mt5-btc-recovery/TwisterPro Scalper.ex5` | 109,212 | `C705E2BBBB66D18E` |
| `mt5-btc-recovery/Ultimate Breakout System.ex5` | 423,012 | `6309CDFC78467DC7` |
| `mt5-program-files/EA Super Trend XAUUSD.ex5` | 267,650 | `F9A04943CACC50AD` |
| `mt5-program-files/My AI Gold.ex5` | 3,680,992 | `E1F1BF70C8E2AECC` |
| `mt5-program-files/Quantum Queen X MT5.ex5` | 489,074 | `BD6AA7E27C9748A2` |
| `mt5-program-files/Quantum Titan MT5.ex5` | 168,726 | `0B4B0F32B37A8F66` |
| `mt5-program-files/Scalping Robot Pro MT5.ex5` | 402,498 | `75B8DA04760B374D` |
| `mt5-program-files/The Gold Reaper MT5.ex5` | 261,524 | `EE063D3D87490AFE` |
| `mt5-program-files/Ultimate Breakout System.ex5` | 422,364 | `7F7E7C0527B93523` |

## Thông tin đọc được ở đầu tệp

Chỉ đọc 4.096 byte đầu mỗi tệp; không suy ra luật bot từ các dòng này.

- **AI Golden Life MT5:** MQL BLUE; https://www.mqlblue.com
- **CryonX EA MT5:** Copyright 2023, MetaQuotes Ltd.; https://www.mql5.com
- **Dynamic Liquidity Intelligence:** Sathit Sukhirun; https://www.mql5.com/en/users/nicedata
- **EA Super Trend XAUUSD:** Copyright 2026,Trading Systems EA Quantum Lab | Algorithms, Indicators, Signals; https://t.me/EAQuantumLab
- **Gold Beaver:** 2026, Arnold Bobrinskii
- **Gold Trade Pro MT5:** Copyright 2023 - Wim Schrynemakers
- **Goldbot One MT5:** Copyright 2024 - Wim Schrynemakers
- **MoonDog EA:** Không thấy đoạn chữ Latin đủ dài theo cách đọc đã dùng.
- **My AI Gold:** Vitalii Kosov
- **Quantum Queen X MT5:** Click here to contact the author.; https://www.mql5.com/en/users/weredeu
- **Quantum Titan MT5:** Click here to contact the author.; https://www.mql5.com/en/users/weredeu
- **Scalping Robot Pro MT5:** MQL BLUE; https://www.mqlblue.com
- **The Gold Reaper MT5:** Copyright 2024 - Wim Schrynemakers
- **TwisterPro Scalper:** Copyright 2026, Twister Pro Systems; https://www.mql5.com
- **Ultimate Breakout System:** Copyright 2026 - Profalgo LTD; https://www.forexeasolutions.com

## Hướng tiếp theo

- Để sửa đúng mã gốc: cần bộ mã `.mq5` và `.mqh` tương ứng từ tác giả hoặc bản sao lưu.
- Có thể nghiên cứu cách bot hoạt động từ hướng dẫn, tham số và giao dịch trong máy thử, rồi viết bản riêng. Cách này không chứng minh đã khôi phục đầy đủ mã hoặc mọi hành vi của bot gốc.
- Báo cáo cũ `KET-QUA-3-TUAN.md` chỉ mô tả kết quả chạy thử; chưa được kiểm lại trong lượt này và không chứng minh toàn bộ luật giao dịch.

## Nguồn chính thức

- [MetaEditor: Compilation](https://www.metatrader5.com/en/metaeditor/help/development/compile)
- [MetaEditor: MQL5 Cloud Protector](https://www.metatrader5.com/en/metaeditor/help/development/mql5_cloud_protector)
