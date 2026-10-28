# Ba lịch tin khi khởi tạo

Đã viết `BotNInitializeNews`: đặt mốc lần hỏi NFP về 0, lần lượt đọc
ba cờ, lấy thời điểm/in thông báo cho mỗi cờ bật, rồi chọn mốc tin
dùng chung. Cờ tắt giữ thời điểm cũ; thời điểm trả về bằng 0 vẫn được
lưu và in. Không tự thêm điều kiện `UseEconomicCalendar` ở đoạn này.

| Kết quả | Bot 1 | Bot 3 |
|---|---:|---:|
| Ca khớp | 637/637 | 637/637 |
| Lượt gọi đã so | 5.570 | 5.570 |
| Lỗi / cảnh báo bộ kiểm | 0 / 0 | 0 / 0 |

Mã gốc chạy từ `0xd60` đến `0x126c` / `0x1279`. Có đủ ba chỗ gọi
lấy lịch: `61b0/6600/6a90` và `6ad0/6f20/73b0`; sau đó chạy nguyên
thân chọn tin `7310` / `7c30`, cùng các hàm chuỗi gốc.

Phản hồi ba hàm lịch được cấp. Chuỗi chuyển ngày được đo trên MT5 rồi
cấp tại ranh giới chuyển chuỗi của mã gốc; đối số kiểu/thời điểm vẫn
được kiểm. So 11 trường đã nối và nhãn trước từng lần gọi, thứ tự, nội dung thông
báo và kết quả cuối. Có cờ 0/1/2/255, ngày 0/âm, phút tràn 32 bit và
dữ liệu/cờ đổi trong lời gọi. Chưa kiểm cấp phát chuỗi thất bại, quyền
dùng, toàn OnInit hoặc toàn EA.

Lượt: `bN-news-init-20261028-r1`; bản biên dịch:
`bN-news-init-check-20261028-r1`. Bản gọi trực tiếp dịch vụ và phép
chuyển ngày thật được biên dịch qua `bN-news-init-api-20261028-r1`.
Chưa có OnInit hoàn chỉnh gọi phần này.

Toàn bộ nguồn trong các phép kiểm mới khớp từng byte với bản đưa lên
Git. Tệp biên dịch chung có bốn tệp từ trước của mỗi bot chỉ khác
cách xuống dòng; nội dung mã khớp sau khi chuẩn hóa xuống dòng.
[Kiểm chi tiết](git-newline-audit.json).

## Chạy lại

Từ gốc dự án, dùng tên lượt mới và MT5 riêng. Ví dụ bot 1:

```powershell
& .\dich-nguoc\khoi-phuc\cong-cu\bien-dich.ps1 -Bot 1 -Terminal .\dich-nguoc\.local\mt5-bot1-thread-20261025 -Run b1-news-build-new -Source .\dich-nguoc\khoi-phuc\bot-cua-toi-1\source\MQL5\Scripts\bot-cua-toi-1\Bot1NewsInitializationCheck.mq5
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-khoi-tao-tin-bot-1-3.py prepare 1 b1-news-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-khoi-tao-tin-bot-1-3.py mql5 1 b1-news-new --build b1-news-build-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-khoi-tao-tin-bot-1-3.py original 1 b1-news-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-khoi-tao-tin-bot-1-3.py compare 1 b1-news-new
```

Đổi số bot và đường dẫn tương ứng cho bot 3. `generate` chỉ dùng khi
chưa có tệp kiểm; không ghi đè bằng chứng cũ.
