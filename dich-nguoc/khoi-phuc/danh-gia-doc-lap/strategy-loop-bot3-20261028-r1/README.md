# Vòng chạy bot 3 và đánh dấu lệnh còn lại

Đã nối `Bot3RunSelectedStrategies` với bước quét lệnh thật trong nguồn.
Hàm quét đọc vị thế đang mở rồi lệnh chờ, đánh dấu 16 ô theo mã nhận
diện. Vòng sau đó chạy chỉ số 0,3,1,2,5,4,8,6,7. Một chiến lược được
gọi khi cờ bật hoặc còn lệnh mang mã của chiến lược đó.

Sau bước chuẩn bị, `Bot3SetupAndEvaluate` đọc lại byte cờ qua tham
chiếu. Byte bằng 0 tạo `prefix.caller_flag=1`; các byte khác tạo 0.
Không lấy cờ này trước khi chuẩn bị và không dùng giá trị cũ trong
`prefix`. Đã cập nhật các nơi gọi để truyền đúng byte cờ.

| Phép kiểm | Kết quả |
|---|---:|
| Quét → chín cổng → cờ sau chuẩn bị | 5.563/5.563 ca |
| Lượt gọi đánh giá được so | 32.734 |
| Quét lệnh độc lập | 543/543 ca |
| Dịch vụ trong phép quét độc lập | 5.754 |
| Hai lượt giữ trạng thái, có trả sớm | đạt |
| Hai lượt nối chuẩn bị/đánh giá/thống kê | đạt |
| Tệp `.mqh` cùng biên dịch | 104 |
| Lỗi / cảnh báo biên dịch | 0 / 0 |

Lượt cuối: `b3-strategy-loop-20261028-r2`,
`b3-strategy-presence-20261028-r1`, `b3-shared-handoff-20261028-r4`,
`b3-strategy-cycle-20261028-r4`, `b3-all-headers-api-20261028-r20`.

Toàn bộ nguồn thuộc hai phép kiểm mới khớp từng byte với bản đưa lên
Git. Trong tệp biên dịch chung có bốn tệp từ trước chỉ khác cách xuống
dòng; nội dung sau khi đưa về cùng cách xuống dòng khớp.
[Kiểm chi tiết](git-newline-audit.json).

## Phạm vi so với mã gốc

Trong phép kiểm nối, mã gốc chạy liên tục từ `0x1a68e` đến trước
`0x1f501`: quét lệnh, chín cổng và các nơi gọi chuẩn bị/đánh giá. Phía
gốc bỏ qua thân nạp cấu hình, ngữ cảnh và chuẩn bị tại ranh giới đã
chỉ rõ. Nguồn chạy ba phần đó với phản hồi dịch vụ được cấp. Thân
đánh giá được thay bằng bộ ghi ở cả hai bên. So toàn bộ cờ, thứ tự và
đối số chỉ số/cờ tại nơi gọi; chưa so các trạng thái khác hoặc toàn EA.

Có đủ tổ hợp chín cờ, các trạng thái còn lệnh, byte khác 0/1, thay đổi
cờ trong chuẩn bị/sau đánh giá và 27 ca chuẩn bị trả sớm. Vì vậy có
thể phân biệt đọc cờ trước/sau chuẩn bị và dùng sai ô cờ.

Phép quét riêng chạy nguyên đoạn `0x1a68e..0x1a7c3`. So từng lời gọi,
phản hồi, mã nhận diện và 20 ô trước dịch vụ/sau khi chạy. Bốn ô ngoài
16 ô phải giữ nguyên. Có vé bằng 0, mã nhận diện âm, sát giới hạn
32 bit, dữ liệu đổi trong dịch vụ và đọc mã mới giữa hai lượt quét.
Không thêm điều kiện lọc mã giá hoặc loại lệnh vì đoạn gốc không có.

Các bản `.txt` trong thư mục này giữ nguồn lượt đầu chỉ so cổng với
cờ có sẵn; bản hiện hành đã nối thêm quét lệnh. Lượt đầu vẫn được giữ
trong bằng chứng, không dùng thay kết quả mới.

Chưa có sự kiện EA gọi bộ điều phối này. Còn phần trước/sau vòng,
khởi tạo, toàn trạng thái dùng chung, ảnh cài đặt/bảng và chạy cặp
EA đầy đủ. Không đổi EX5 gốc hoặc gửi lệnh thật.

## Chạy lại

Từ gốc dự án, dùng tên lượt mới; không biên dịch tệp khác trong cùng
MT5 riêng khi chương trình kiểm đang chạy.

```powershell
& .\dich-nguoc\khoi-phuc\cong-cu\bien-dich.ps1 -Bot 3 -Terminal .\dich-nguoc\.local\mt5-bot3-thread-20261025 -Run b3-loop-build-new -Source .\dich-nguoc\khoi-phuc\bot-cua-toi-3\source\MQL5\Scripts\bot-cua-toi-3\Bot3StrategyLoopCheck.mq5 -CheckFloatingPointDividers
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-vong-chien-luoc-bot-3.py prepare b3-loop-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-vong-chien-luoc-bot-3.py mql5 b3-loop-new --build b3-loop-build-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-vong-chien-luoc-bot-3.py original b3-loop-new
python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/kiem-vong-chien-luoc-bot-3.py compare b3-loop-new
```

Phần quét dùng công cụ `kiem-lenh-con-lai-bot-3.py` với cùng các bước
và tệp `Bot3StrategyPresenceCheck.mq5`. `generate` chỉ dùng khi chưa có
tệp kiểm. Phản hồi dịch vụ được cấp; chưa phải chạy hai EA.
