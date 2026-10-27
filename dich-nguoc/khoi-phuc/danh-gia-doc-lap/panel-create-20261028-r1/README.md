# Tạo toàn bộ bảng — 28/10/2026

| Kết quả | Bot 1 | Bot 3 |
|---|---:|---:|
| Ca đối chiếu toàn hàm gốc | 170/170 | 179/179 |
| Lời gọi được so đầy đủ | 213.322 | 248.042 |
| Đối tượng dựng thật trên MT5 | 45 | 50 |
| Ô trong bảng | 36 | 40 |
| Hàng chiến lược | 8 | 9 |
| Tệp ghép đã biên dịch cùng nhau | 87 | 94 |
| Lỗi / cảnh báo | 0 / 0 | 0 / 0 |

Nguồn mới: `Bot1PanelCreation.mqh`, `Bot3PanelCreation.mqh`. Phục hồi
nguyên hàm tạo bảng, gọi lại các hàm tạo ô, chọn tin và làm tròn đã kiểm.
Lượt cuối là `b1-panel-create-20261028-r4`, `b3-panel-create-20261028-r4`,
dùng bản biên dịch `b1-panel-create-check-20261028-r3` và bản tương ứng
của bot 3. Các chữ/số/ngày được đo trên MT5, rồi cấp cho mã gốc để
so từng tham số, chuỗi, thứ tự và trạng thái trước mỗi dịch vụ/cuối hàm.

Lượt đầu bắt sai màu của dòng tổng lời/lỗ. Lượt thứ hai bắt sai
phép kiểm cờ màu của bốn dòng có tên ghép số: phải kiểm bit thấp nhất,
không phải mọi giá trị khác 0. Đã sửa theo lệnh gốc. Bản sai có mã
kiểm tra trùng biên nhận đã biên dịch được giữ dưới đuôi `.rejected.mqh.txt`;
`negative-control.py` xác nhận bộ kiểm hiện hành vẫn loại đúng bản sai.
Các lượt cũ giữ nguyên trong máy; không ghi lại thành kết quả đạt.

Đã chạy nguồn gọi dịch vụ thật trên hai MT5 riêng, xem cả hai ảnh và
đọc lại danh sách đối tượng. Xem [nhận xét ảnh](visual-inspection.json).
Đã so 459/510 thuộc tính đọc được với chuỗi lệnh gốc đã kiểm. Riêng
thuộc tính `0x40b` của khung không đọc lại được: MT5 nhận lời gọi đặt,
nhưng lời gọi đọc trả mã lỗi 4203. Đã đo riêng và giữ nguyên lời gọi
trong nguồn; không dùng giá trị đọc lỗi để kết luận nguồn bị sai.
Ảnh PNG và dữ liệu nhị phân được giữ cục bộ, có mã kiểm tra trong biên
nhận; có thể tạo lại bằng công cụ dưới. Với bộ cài đặt thử này, một
số chữ tiêu đề ô bị cắt. Chưa có phép đối ảnh gốc nên giữ nguyên các
kích thước và cách đặt chữ đã đo từ mã gốc.

Chưa phải EA hoàn chỉnh: còn khởi tạo đầy đủ, điều phối ngoài và
các sự kiện, ảnh menu, tài nguyên và chạy cặp hai EA cùng điều kiện.
Chưa xác nhận đạt 100% toàn bot. Claude chưa đánh giá lượt này; lần
gọi gần nhất lưu tại `input-settings-20261028-r2/claude-access.json`
cho biết tài khoản không được dùng Claude Code. Codex làm tiếp theo
ngoại lệ người dùng đã cho phép.

## Lặp lại phép kiểm

Từ gốc dự án, chọn tên lượt mới. Không biên dịch tệp khác cùng bot
trong lúc MT5 đang chạy kiểm. Công cụ biên dịch có thể thay thư mục
nguồn riêng và xóa các EX5 đã biên dịch trước trong thư mục đó.

```powershell
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-tao-bang-bot-1-3.py generate 1
& .\dich-nguoc\khoi-phuc\cong-cu\bien-dich.ps1 -Bot 1 -Terminal .\dich-nguoc\.local\mt5-bot1-thread-20261025 -Run b1-panel-create-check-new -Source .\dich-nguoc\khoi-phuc\bot-cua-toi-1\source\MQL5\Scripts\bot-cua-toi-1\Bot1PanelCreationCheck.mq5
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-tao-bang-bot-1-3.py prepare 1 b1-panel-create-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-tao-bang-bot-1-3.py mql5 1 b1-panel-create-new --build b1-panel-create-check-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-tao-bang-bot-1-3.py original 1 b1-panel-create-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-tao-bang-bot-1-3.py compare 1 b1-panel-create-new
```

Làm tương tự với bot 3 và MT5 riêng của bot 3. Để xem ảnh, sinh
`BotNPanelCreationVisualCheck.mq5` bằng `kiem-hinh-bang-bot-1-3.py generate N`,
biên dịch tệp này rồi gọi `run N TEN-LUOT --build TEN-BIEN-DICH`.
Lệnh không gửi lệnh giao dịch, không sửa EX5 gốc hay MT5 chính.

Chi tiết: [mô tả phục hồi](SPEC.md), [kiểm mã sai](bot1-negative.json),
[bảng chứng cứ cuối](verification.json).
