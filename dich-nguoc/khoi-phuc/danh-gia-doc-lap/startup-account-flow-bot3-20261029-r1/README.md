# Nối vốn và lịch dự phòng tới trả về — bot 3

`Bot3StartupAccountFlow.mqh` chạy phần khởi tạo vốn, nạp lịch dự
phòng rồi nối đổi giờ/chọn tần suất, ngữ cảnh, chuẩn bị và đuôi.
Mã gốc chạy liên tục `0x1279..0x5f34`, nền `0x17156250000`.

| Phần | Bằng chứng gốc | Cách phục hồi/kiểm | Kết quả/còn thiếu |
|---|---|---|---|
| Đọc vốn | `UseEquity=0x1d7180` đọc sau lần hỏi số dư `0x1292` | Truyền tham chiếu byte để đọc đúng lúc | Khớp cả khi cài đặt đổi sau dịch vụ |
| Quyết định đặt lại | Byte `0x1d7168` đọc tại `0x14b9`, dùng lại tại `0x189b` | Giữ một bản đã đọc sau khi tạo khóa | Khớp, không đọc lại sai sau lời gọi |
| Mức vốn cao nhất | In tại `0x16c3`, ghi ô `0x1d6c68` tại `0x16f5` | Chọn bằng biến cục bộ, ghi sau thông báo | Đã sửa việc ghi sớm trong nguồn cũ |
| Vốn thủ công | `0x1d7128` đọc cuối tại `0x1919` | Giữ riêng vốn dùng và số dư được hỏi lại ở bước chọn tần suất | Khớp |
| Lịch dự phòng | `0x193f..0x3840`; các mảng `0x75360/0x75cd0/0x76630` | So đủ 900 ô; chỉ ghi 240/89/134 ô đầu; hai cờ và lời gọi thông tin ở đúng thứ tự | Khớp, giữ nguyên đuôi mảng |
| Các phần sau | `0x3840..0x5f34` | Cùng vùng nhớ từ đầu; các giá trị nối do đoạn trước tạo ra | Khớp; hai thân tìm mức và ba thân bảng vẫn được thay bằng bộ ghi |

Lượt `b3-startup-account-flow-20261029-r1`: **108/108 ca khớp**,
283 trường, dãy chỉ báo, 2.800 ô bảng và 900 ô lịch; 15.095 lần
gọi, 6.591 phép tính CPU. Bộ kiểm bắt đầu với vùng trả chuỗi rỗng,
không cấp sẵn các thanh ghi cho điểm nối `0x3840`; đoạn vốn/lịch
gốc phải tự tạo đúng giá trị trước khi đi tiếp.

Cách gọi cũ `Bot3InitializeAccountState` được giữ lại và so lại
**616/616 ca** trong `b3-account-compat-20261029-r1`. Bộ cũ so kết
quả số, khóa lưu, thời điểm và thứ tự dịch vụ; phần thông báo đã
được kiểm ở bộ nối mới. Hai nguồn kiểm và bộ ghép
`b3-all-headers-api-20261029-r8`: 0 lỗi, 0 cảnh báo; đủ 115 tệp `.mqh`.
Kiểm độc lập không thấy lỗi cần sửa trong phạm vi này.

## Giới hạn

Tài khoản, kho giá trị lưu, đồng hồ và thời gian chờ được cấp trong
bộ kiểm; không đọc tài khoản thật, không đổi biến MT5 thật và không
chạy quyền dùng. Chuỗi số được đo từ MQL5, các nhánh và phép nối
chuỗi vẫn chạy mã gốc. Cấp phát thành công được cấp.

Còn phần lấy lịch tin trước `0x1279`, các thân tìm mức/bảng trong
phép kiểm nối, lỗi cấp phát/toàn trạng thái ở lỗi, ảnh bảng và EA
đầy đủ. Chưa phải phép chạy cặp hai bot hoàn chỉnh.

Chạy lại công cụ `kiem-noi-von-khoi-dong-bot-3.py`: `generate`,
`prepare RUN`, `mql5 RUN --build BUILD`, `original RUN`, `compare RUN`.
Dùng tên lượt mới và MT5 bot 3 riêng; MQL5 chạy trước mã máy.
Bộ tương thích cũ dùng `kiem-khoi-tao-von-bot-1-3.py` với
`settings.MT` trỏ tới máy thử `mt5-bot3-thread-20261025`.

[Số liệu/địa chỉ](verification.json), [danh sách tệp](../startup-account-flow-bot3-20261029-r1-manifest.txt).
