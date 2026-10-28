# Nối khởi động sau chuẩn bị đầu — bot 1

**Bản r1 đã được sửa:** bảng dưới gán nhầm bình luận giao dịch
`0x62470` vào `p.comment`, trong khi trường đó thật sự thuộc `0x62480`.
639 ca cũ chưa phát hiện được lỗi liên kết này. Dùng
[bản sửa và 655 ca hiện hành](../startup-comment-binding-20261028-r1/README.md).
Phần còn lại dưới đây giữ làm hồ sơ lượt r1.

Đã nối `Bot1InitializeTradingState` với `Bot1InitializeStartupTail`
trong `Bot1StartupPostPreparation.mqh`. Bản gốc chạy liên tục từ
`0x3cab` đến lệnh trả về `0x5658`, đi qua điểm nối `0x4e77` đúng một
lần mỗi ca. Không đặt lại bộ nhớ, thanh ghi hoặc chuỗi tạm tại điểm nối.

## Trạng thái dùng chung

| Vị trí gốc | Nguồn dùng chung | Điều phải giữ |
|---|---|---|
| `0x66a80` | `panel.lots[8]` | Phần giao dịch ghi ngay vào mảng mà phần cuối dùng |
| `0x678f4` | `p.strategy_index` | Giữ chỉ số sau phần giao dịch và các lời gọi con |
| `0x62530` | `p.native_62530` | Dùng giá trị đã xử lý, kể cả âm được đổi thành `0.01` |
| `0x62470` | `p.comment` | Giữ bình luận dùng tạo bốn chuỗi lệnh |
| `0x67918` | `inputs.symbol` | Dùng chung mã giá cho hai phần |
| `0x6779c` | `p.calendar.hour` | Giữ giờ do bước chuẩn bị trước đó cung cấp |
| `0x6246c` | `magic` | Mã chiến lược dùng tìm mức và lọc lịch sử |
| `0x6a610` | `magic_base` | Mã gốc truyền vào các hàm bảng, không đổi với mã chiến lược |
| `0x677f8` | `last_ticket` | Giữ vé lệnh qua các hàm tìm mức và cập nhật bảng |

[Bảng đầy đủ 124 giá trị](storage-map.json). Không tạo bản sao mảng
khối lượng hoặc đặt lại trạng thái giữa hai lời gọi.

## Kết quả

Lượt `b1-startup-joined-20261028-r1`: **639/639 ca khớp**,
**23.747 lời gọi**, **19.143 phép số học CPU thật**, **639 lần qua
điểm nối**. So 124 giá trị, mã lỗi, chuỗi, thứ tự/đối số dịch vụ và
1.800 ô bảng. Mọi lần gọi đều so trạng thái trước lời gọi; khi kết
thúc so đủ từng byte của các bảng và giá trị trả về.

639 ca gồm 315 ca phần giao dịch, 309 ca phần cuối và 15 ca nối có
thay đổi chỉ số, khối lượng, giờ, mã chiến lược hoặc vé lệnh trong
lời gọi con. Các giá trị thay đổi tiếp tục được phần sau đọc lại.

`b1-startup-joined-check-20261028-r1` biên dịch 0 lỗi, 0 cảnh báo.
Kết quả gốc và MQL5 có cùng SHA-256, được lưu trong hai biên nhận
`original-run.json` và `mql5-run.json` của lượt trên.

Toàn bộ 103 tệp `.mqh` tại `b1-all-headers-api-20261028-r25` biên
dịch 0 lỗi, 0 cảnh báo. [Biên nhận tổng hợp](verification.json).
Phép ghép 103 tệp dùng nguồn tại máy. Bốn tệp cũ về vốn/rút tiền có
ký tự xuống dòng khác bản Git nhưng mã giống nhau; cả bốn giữ nguyên
so với trước lượt này. Danh sách và mã băm nằm trong biên nhận tổng
hợp. Phần nối mới, phần cuối và nguồn kiểm được kiểm Git từng byte
riêng; không gọi phép ghép 103 tệp là kiểm toàn bộ Git từng byte.

## Kiểm bằng cách cố ý nối sai

Một chương trình MQL5 riêng gọi hai phần giống nguồn đúng, rồi bật
từng lỗi tại chỗ nối. Khi tắt cả bốn lỗi, **639/639 ca vẫn khớp**.

| Lỗi được cài | Số ca phát hiện khác biệt trên 639 ca |
|---|---:|
| Đưa mảng khối lượng về giá trị cũ | 639 |
| Đưa chỉ số chiến lược về giá trị cũ | 369 |
| Truyền khối lượng khởi đầu cũ vào phần sau | 3 |
| Đưa vé lệnh về giá trị cũ | 2 |

Mỗi ca khác được tính một lần dù khác cả kết quả và băng lời gọi.
Chuẩn so là kết quả mã gốc của lượt nối đúng, đã kiểm lại mã băm
nguồn, đầu vào và bằng chứng trước khi chạy. Chương trình cố ý sai
nằm riêng trong `Bot1StartupPostPreparationNegativeCheck.mq5`;
không đưa các nhánh sai vào nguồn phục hồi.

Codex kiểm độc lập đã yêu cầu bổ sung phần đối chứng này và đọc lại
sau khi chạy. Không còn điểm cần sửa được phát hiện trong phạm vi
đoạn nối; điều này không mở rộng phạm vi sang toàn bot.

## Giới hạn và bước tiếp

- Trạng thái trước lần chuẩn bị đầu chưa thuộc lượt kiểm này.
- Hai hàm tìm mức giá và ba hàm bảng được thay thân bằng bộ ghi;
  kiểm đầy đủ đối số và thay đổi trạng thái của chúng trong lượt này.
- Dữ liệu dịch vụ MT5 và cấp phát chuỗi thành công được cung cấp.
- Chưa kiểm lỗi chia cho 0, lỗi cấp phát hoặc nhánh lỗi sau `0x5658`.
- Còn phần trước của `OnInit`, nguồn trạng thái ban đầu, liên kết
  cài đặt, kiểm quyền gốc, sự kiện và chạy cặp hai EA hoàn chỉnh.

Đây là phép kiểm đoạn nối, chưa phải toàn bộ `OnInit` hay toàn bot.
Không dùng 639 ca làm tỷ lệ hoàn thành bot.

## Chạy lại

`cong-cu/kiem-noi-khoi-dong-bot-1.py` có các bước `generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Chỉ tạo nguồn kiểm khi tệp chưa tồn tại. Dùng tên lượt mới, giữ
nguyên bằng chứng cũ và kiểm mã băm trước khi dùng lại kết quả.

Phép cố ý sai dùng `kiem-phu-dinh-noi-khoi-dong-bot-1.py`:
`generate`, sau đó `run RUN --build BUILD --source-run SOURCE_RUN
--fault control|reset-lots|reset-index|old-start-lots|reset-ticket`.
Chạy `control` trước và yêu cầu không khác; bốn chế độ còn lại phải
phát hiện khác biệt. [Danh sách tệp bàn giao](manifest.txt).
