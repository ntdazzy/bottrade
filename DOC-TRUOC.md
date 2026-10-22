# Bot Market Demo — đọc trước

15 bot vàng (XAUUSD) của chủ dự án. Chủ dự án xác nhận đã mất mã nguồn khi đổi máy.
Các tệp EX5 hiện có được dùng làm đầu vào phục hồi; một số bản chỉ chạy trong
máy thử MT5 (không chạy trên tài khoản demo/thật).

## Thư mục

| Thư mục | Nội dung |
|---|---|
| `1-dang-tin-nhat` | 3 bot có kết quả đo **khớp tài khoản thật của tác giả** |
| `2-co-loi` | Lời cả 2 năm, chưa đối chiếu được tài khoản thật |
| `3-so-ao-luot-nhanh` | Lời cực lớn nhưng do vào/ra lệnh rất nhanh trên dữ liệu không chênh lệch giá |
| `4-loai` | Cháy tài khoản hoặc không lời |
| `bao-cao` | Báo cáo kết quả và tài liệu phục hồi |

Mỗi bot một thư mục: file `.ex5`, dữ liệu cài đặt và tài liệu phục hồi liên quan.

## Bảng xếp hạng (vốn 10.000 USD mỗi năm, không phí, không chênh lệch)

| Hạng | Bot | 2025 | 2026 (đến 19/10) | Sụt lớn nhất | Nhóm |
|---:|---|---:|---:|---:|---|
| 1 | Ultimate Breakout — bộ "Scalp C Live" | +1.508% | +48.166% | 23% | 2 |
| 2 | TwisterPro | +11.371% | +10.912% | 6% | 3 |
| 3 | My AI Gold | +7.641% | +2.241% | 59% | 3 |
| 4 | Scalping Robot Pro | +651% | +1.069% | 0,1% | 3 |
| 5 | Quantum Titan | +188% | +772% | 8% | 2 |
| 6 | Gold Beaver | +447% | +287% | 23% | 2 |
| 7 | CryonX | +350% | +40% | 40% | 2 |
| 8 | **Gold Reaper** | +178% | +142% | 17% | 1 |
| 9 | **Gold Trade Pro** | +82% | +56% | 14% | 1 |
| 10 | **Goldbot One** | +85% | +26% | 15% | 1 |
| 11 | Super Trend | +84% | +25% | 12% | 2 |
| 12 | Dynamic Liquidity | +10% | +15% | 1% | 2 |
| 13 | MoonDog | +6% | +20% | 0,2% | 2 |
| 14 | Ultimate Breakout — mặc định | +1% | +2% | 0,4% | 2 |
| 15 | AI Golden Life | −0,2% | +0,03% | 0,3% | 4 |
| 16 | Quantum Queen X | cháy | cháy | 100% | 4 |

% chênh nhau chủ yếu do mức lot mỗi bot đặt (có lãi kép). Chi tiết MUA/BÁN: `bao-cao\KET-QUA-2025-2026.md`.

## Thông số đã dùng khi đo (muốn đo lại cho giống)

- Mã giá Exness giờ GMT+0. Nhóm Gold Reaper, Gold Trade Pro, Goldbot One và Ultimate Breakout dùng: `AutoGMT=false`, `Broker_GMT_OFFSET_Winter=0`, `Broker_GMT_OFFSET_Summer=0` (máy thử không tự lấy được giờ).
- **Gold Trade Pro:** `Risk=3` (rủi ro tối đa mỗi chiến lược, `MaxRiskPerStrategy=3`). Mặc định `Risk=0` là lot cố định 0,01.
- **Goldbot One:** bộ `Goldbot_MediumRisk_Max30DD.set`.
- **Gold Reaper:** mặc định (trùng mục Quick Start trong sách hướng dẫn V5.1).
- **Ultimate Breakout "Scalp C":** `GOLD_Scalp\scalph1_C_LiveSettings.set`, khung H1, bỏ `ForceSymbol`. Bộ này làm cho tài khoản 200 USD nên lot rất lớn.
- **MoonDog:** SET 1 của tác giả (lot 0,01). Không nạp bộ này thì máy thử tự chuyển sang rủi ro 2%.
- Bot khác: mặc định của tác giả. Khung: Gold Trade Pro/Goldbot One/Ultimate mặc định = D1; Scalping Robot Pro = M1; Gold Beaver/Dynamic Liquidity/TwisterPro = M15; còn lại H1.
- Đo năm 2026 cho chạy từ 01/12/2025 để bot có sẵn lệnh, chỉ tính lệnh đóng từ 01/01/2026.

## Cách mở lại bot trong MT5

Chép file `.ex5` vào `MQL5\Experts\Market\` của MT5, mở Strategy Tester và chọn bot.
