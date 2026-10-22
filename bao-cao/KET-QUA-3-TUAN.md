# Đo 15 bot của chủ dự án — 3 tuần gần nhất (bản sửa)

**Cách đo:** bot chạy từ 01/09/2026 để "khởi động" (có sẵn lệnh, lệnh chờ như tài khoản thật), chỉ tính các lệnh **đóng trong 3 tuần 28/09 → 19/10/2026** (thứ Hai 28/09 đến hết dữ liệu). Vốn đầu 10.000 USD lúc 01/09, đòn bẩy 1:500, XAUUSD không phí (chênh lệch, hoa hồng, qua đêm = 0, đã kiểm từng lệnh).

| # | Bot | Lời/lỗ 3 tuần | % | Nếu bắt đầu 29/09 | Sụt trong 3 tuần | Sụt cả lượt | MUA lệnh/USD | BÁN lệnh/USD |
|---|---|---:|---:|---:|---:|---:|---|---|
| 1 | Ultimate Breakout — bộ "Scalp C Live" của tác giả ⚠️ lot lớn | 14.301 | +69,6% | +65,0% | 3.8% | 5.55% | 9 / 7.227 | 12 / 7.074 |
| 2 | TwisterPro Scalper (Mode 1, 3%/lệnh) | 9.164 | +44,4% | +44,4% | 0.0% | 0.25% | 1 / 1.006 | 8 / 8.158 |
| 3 | My AI Gold | 3.048 | +32,7% | +25,7% | 13.4% | 36.01% | 7 / 1.547 | 6 / 1.501 |
| 4 | Scalping Robot Pro ⚠️ lưới | 6.154 | +30,9% | +26,9% | 0.0% | 0.06% | 5289 / 2.996 | 5023 / 3.158 |
| 5 | CryonX | 1.648 | +16,2% | +16,2% | 0.0% | 17.02% | 4 / 408 | 13 / 1.240 |
| 6 | EA Super Trend XAUUSD | 800 | +7,4% | +6,9% | 2.1% | 4.29% | 149 / 584 | 61 / 216 |
| 7 | Gold Beaver (Combo Safe) | 744 | +7,3% | +6,7% | 0.0% | 5.04% | 0 / 0 | 12 / 744 |
| 8 | The Gold Reaper 5.5 (mặc định = Quick Start tác giả) | 687 | +6,7% | -8,3% | 10.8% | 11.18% | 8 / 86 | 23 / 602 |
| 9 | Quantum Titan | 665 | +6,3% | +4,0% | 2.5% | 3.09% | 6 / 396 | 8 / 269 |
| 10 | Goldbot One — bộ Medium của tác giả | 309 | +3,1% | -7,5% | 7.5% | 9.99% | 4 / -3 | 15 / 312 |
| 11 | Gold Trade Pro 7.1 (mặc định; bộ tài khoản thật cho kết quả y hệt) | 102 | +1,0% | -2,6% | 3.2% | 3.80% | 1 / -12 | 17 / 114 |
| 12 | Dynamic Liquidity Intelligence | 96 | +0,9% | +0,8% | 0.6% | 0.67% | 14 / 23 | 7 / 73 |
| 13 | Goldbot One — mặc định | 80 | +0,8% | -1,7% | 1.7% | 2.22% | 4 / -6 | 15 / 86 |
| 14 | MoonDog (SET 1) | 72 | +0,7% | +0,7% | 0.0% | 0.06% | 14 / 51 | 9 / 21 |
| 15 | Ultimate Breakout — mặc định | 25 | +0,2% | +0,1% | 0.0% | 0.23% | 1 / 13 | 2 / 12 |
| 16 | AI Golden Life | -2 | -0,0% | -0,0% | 0.0% | 0.06% | 8 / -1 | 6 / -1 |
| 17 | Quantum Queen X ⚠️ lưới | -12.709 | -106,2% | -105,9% | 104.8% | 104.75% | 163 / -13.338 | 19 / 629 |

## Điều cần biết
- **Lần đo đầu sai vì cách đo:** bắt đầu trắng ngày 29/09 (thứ Ba). Ba bot lời lớn đúng **thứ Hai 28/09** (vàng mở cửa giảm, lệnh chờ BÁN khớp). Dời mốc bắt đầu 1 ngày đổi Gold Reaper từ −8,3% thành +6,7%. **3 tuần quá ngắn, kết quả phụ thuộc may rủi ngày bắt đầu.**
- **So với tài khoản thật của tác giả** (tăng trưởng theo tuần trên trang tín hiệu MQL5): Gold Trade Pro khớp chiều từng tuần (tuần đến 05/10: thật +7,6%, đo +4,4%); Gold Reaper 7 tuần thật +13,6%, đo +10,2%; Goldbot One tổng gần (thật +4,0%, đo +2,5%) nhưng lệch thời điểm.
- **Gold Trade Pro:** bộ "Live Signal" (bản V2.0) nạp đúng nhưng cho kết quả y hệt mặc định — bản 7.1 vẫn tính lot 0,01 mỗi 600 USD ở cả hai.
- **Ultimate Breakout "Scalp C Live":** bộ dành cho tài khoản 200 USD (0,01 lot mỗi 80 USD) → trên 10.000 USD là lot rất lớn; tiền lời lớn đi kèm rủi ro lớn. Đã bỏ ForceSymbol=XAUUSD để chạy trên mã thử.
- **Không đáng tin:** Scalping Robot Pro (lưới, 10.312 lệnh) — dữ liệu không có chênh lệch và giá trong phút do MT5 dựng từ nến M1 nên bot lướt nhanh đẹp hơn thực tế rất nhiều. My AI Gold sụt 36% trong lượt.
- **Quantum Queen X cháy tài khoản** (lưới lệnh, ngưng do hết ký quỹ).
- Giờ máy chủ = 0 (Exness). Theo sách hướng dẫn Gold Reaper V5.1, giờ GMT chỉ dùng cho bộ lọc tin NFP; lịch tin MT5 không có trong máy thử nên bot dùng lịch có sẵn bên trong.

Nguồn: báo cáo MT5 `work/bot-tests/mt5-market*/reports/{w_,m7w_}*.htm`; tính bằng `window_market.py`; so tín hiệu bằng `compare_signal.py` (Codex workspace 2026-10-20).
