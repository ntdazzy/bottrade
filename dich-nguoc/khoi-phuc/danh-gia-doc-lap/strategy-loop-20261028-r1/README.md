# Vòng gọi tám chiến lược bot 1

Đã nối `Bot1RunEnabledStrategies` trong `Bot1StrategyDispatcher.mqh` với
hàm chuẩn bị → đánh giá → thống kê hiện có. Vòng chạy đọc từng cờ ngay
trước chiến lược tương ứng, theo thứ tự 0 đến 7. Kết quả dừng của một
chiến lược không làm dừng cả vòng. Điều kiện đổi giờ được nơi gọi lấy
trước vòng, đúng thời điểm gốc; hàm này không tự đọc giờ lần nữa.

Phép so `b1-strategy-loop-20261028-r1` khớp **896/896 ca**, gồm toàn bộ
256 tổ hợp bật/tắt và thay đổi cờ lúc một chiến lược chạy. So **2.799
lượt gọi chiến lược**, thứ tự, số lượt và cờ còn lại. Bộ ghi phía
nguồn còn kiểm việc truyền điều kiện giờ và lựa chọn dùng đỉnh/đáy.
Mã gốc chạy liên tục từ `0x12424` đến trước `0x16730`.

Mỗi thân chiến lược được thay bằng bộ ghi ở cả hai bên trong phép kiểm
này; không dùng kết quả này để chứng minh thuật toán bên trong. Bản
nguồn thật gọi `Bot1SetupEvaluateAndUpdateStatistics`; các phần trong
đó có phép kiểm riêng tại `strategy-cycle-20261028-r1`.

Chưa có EA hoàn chỉnh hoặc nơi gọi từ sự kiện MT5. Còn phần trước
vòng, cập nhật bảng sau vòng, khởi tạo và nối toàn bộ trạng thái.
Không đổi EX5 gốc hay chạy giao dịch thật.

Toàn bộ 96 tệp `.mqh` bot 1 có trong tệp biên dịch chung; lượt
`b1-all-headers-api-20261028-r19` có 0 lỗi, 0 cảnh báo. Bốn tệp có sẵn
vẫn khác Git ở cách xuống dòng như bằng chứng của lượt trước; riêng
toàn bộ nguồn thuộc vòng chiến lược khớp từng byte với bản đưa lên Git.

## Bảng nối bot 3 đã làm rõ

`bot3-gate-mapping.json` lưu lệnh gốc của đủ chín cổng và các nơi gọi.
Ô cờ không phải chỉ số hàm đánh giá. Đối chiếu thêm chín ca chỉ bật một
mục trong kết quả gốc xác nhận mục cài đặt 1 đến 9 gọi chỉ số 0 đến 8.
Thứ tự chạy là 0,3,1,2,5,4,8,6,7. Bảng này phục vụ bước nối tiếp;
chưa có vòng điều phối bot 3 trong nguồn hiện hành.

Ở từng nơi gọi bot 3, mã gốc đọc lại cờ sau bước chuẩn bị rồi truyền
`DL=1` nếu cờ bằng 0. Cờ này dùng để tiếp tục quản lý phần còn tồn
tại khi chiến lược đã tắt. `Bot3SetupAndEvaluate` hiện còn nhận cờ qua
trạng thái `prefix.caller_flag`; bước nối vòng cần cấp đúng cờ tại
thời điểm này, không lấy trước bước chuẩn bị.

## Chạy lại

Dùng tên lượt mới và máy MT5 riêng của bot 1:

```powershell
& .\dich-nguoc\khoi-phuc\cong-cu\bien-dich.ps1 -Bot 1 -Terminal .\dich-nguoc\.local\mt5-bot1-thread-20261025 -Run b1-loop-build-new -Source .\dich-nguoc\khoi-phuc\bot-cua-toi-1\source\MQL5\Scripts\bot-cua-toi-1\Bot1StrategyLoopCheck.mq5 -CheckFloatingPointDividers
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-vong-chien-luoc-bot-1.py prepare b1-loop-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-vong-chien-luoc-bot-1.py mql5 b1-loop-new --build b1-loop-build-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-vong-chien-luoc-bot-1.py original b1-loop-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-vong-chien-luoc-bot-1.py compare b1-loop-new
```
