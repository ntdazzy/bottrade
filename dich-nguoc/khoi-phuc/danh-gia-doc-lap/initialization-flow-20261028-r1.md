# Thứ tự khởi tạo gốc

Đây là đặc tả đọc từ hàm khởi tạo thật, không phải mã EA hoàn chỉnh.
Địa chỉ là độ lệch so với đầu bản chụp.

| Bước | Bot 1 | Bot 3 |
|---|---|---|
| Hàm khởi tạo | `0xc30..0x5880` | `0xc30..0x61a0` |
| Đặt cờ hoạt động=0 | `0x67470` | `0x744b0` |
| Đọc quyền dùng | gọi `0x5880` | gọi `0x61a0` |
| Đặt cờ hoạt động=1 | sau khi quyền dùng cho phép | sau khi quyền dùng cho phép |
| Chế độ kiểm thử | `MQLInfoInteger(6)`, ghi cờ `0x621e0/0x621c9` | ghi `0x6d1e8/0x6d1d0` |
| Ba hàm lấy lịch tin | `0x61b0`, `0x6600`, `0x6a90` | `0x6ad0`, `0x6f20`, `0x73b0` |
| Chọn mốc tin dùng chung | `0x7310` | `0x7c30` |
| Nối phần tin tới trả về | `0xd60..0x5658`, 239/239 ca, ba hàm lấy lịch được cấp kết quả | chưa dựng đoạn nối tương ứng |
| Nối cả thân lấy lịch tới trả về | `0xd60..0x5658`, 158/158 ca; nguyên ba thân lịch, dịch vụ cấp mảng dữ liệu | chưa dựng đoạn nối tương ứng |
| Thêm thân tìm mức và kiểm lệnh gần | `0xd60..0x5658`, 85/85 ca; nguyên các thân lịch/tìm mức/kiểm lệnh gần | chưa dựng đoạn nối tương ứng |
| Thêm cả ba thân hàm bảng | `0xd60..0x5658`, 42/42 ca, 57.592 lời gọi; chưa so ảnh vẽ thật hoặc kiểm quyền | chưa dựng đoạn nối tương ứng |
| Đoạn vốn/tài khoản trong OnInit | `0x126c..0x1941` | `0x1279..0x193f` |
| Nối vốn, lịch dự phòng tới trả về | `0x126c..0x5658`, 93/93 ca, cùng trạng thái và 900 ô lịch | `0x1279..0x5f34`, 108/108 ca, 283 trường/900 ô lịch/2.800 ô bảng; thân đổi giờ/đổi tiền/chuẩn bị chạy thật |
| Nạp dữ liệu lịch dự phòng và hai cờ | `0x1941..0x3827` | `0x193f..0x3840` |
| Ngữ cảnh/bộ đếm/đuôi mã trước chuẩn bị | `0x3827..0x3c9d` | `0x3ce6..0x4580`, 298/298 ca |
| Nối đổi giờ/chọn tần suất với ngữ cảnh | không có đoạn chọn tương ứng | `0x3840..0x4580`, 233/233 ca; kết quả hai hàm mùa hè/đổi tiền được cấp |
| Thêm thân mùa hè/đổi tiền trong phần nối | ngoài phạm vi lượt này | `0x3840..0x4580`, 344/344 ca; 18.982 lời gọi/thông báo; còn các nhánh lỗi khi đã nối |
| Nối chọn tần suất tới trả về | không có đoạn chọn tương ứng | `0x3840..0x5f34`, 224/224 ca, 274 trường/2.800 ô; nguyên thân mùa hè/đổi tiền/chuẩn bị |
| Nối ngữ cảnh tới trả về | `0x3827..0x5658`, 459/459 ca, cùng trạng thái qua chuẩn bị đầu | `0x3ce6..0x5f34`, 531/531 ca, 248 trường/dãy chỉ báo/2.800 ô; chưa ghép chọn tần suất phía trước |
| Chuẩn bị chiến lược đầu | `0x7500` | `0xe0c0` |
| Bốn chuỗi ghi chú, lịch sử và thứ tự bảng tới trả về | `0x4e77..0x5658` | `0x574c..0x5f34`, 222/222 ca; ba thân bảng được thay bằng bộ ghi, chưa nối đoạn giữa |
| Nối chuẩn bị đầu đến trả về | gọi `0x7500` tại `0x3ca9`, chạy tới `0x5658`; 161/161 ca và 3/3 ca lỗi | gọi `0xe0c0` tại `0x458c`, từ `0x4580` tới `0x5f34`; 233/233 ca và 3/3 ca lỗi riêng |
| Trạng thái giao dịch sau chuẩn bị | `0x3cab..0x4e77`, gồm nhánh ngoài đến `0x4f4b`; 315/315 ca | `0x458e..0x574c`, gồm nhánh ngoài đến `0x5873`; 315/315 ca, 53 trường/2.800 ô |
| Nối trạng thái giao dịch đến trả về | `0x3cab..0x5658`, 639/639 ca chạy liên tục, chung trạng thái | `0x458e..0x5f34`, 569/569 ca, 130 trường/2.800 ô; hai thân tìm mức và ba thân bảng được thay bằng bộ ghi |
| Tạo bảng | `0x8320`, `0xe1b0`, `0xffb0` | `0xef40`, `0x14fa0`, `0x16e80` |

Thứ tự gọi thấy được trong mã máy:

1. Ghi cờ hoạt động bằng 0, đọc `AccountInfoInteger(0x20)`, gọi hàm
   kiểm quyền. Nhánh từ chối gọi bộ thông báo lỗi rồi kết thúc.
2. Ghi cờ hoạt động bằng 1. Đọc `MQLInfoInteger(6)`; trong một chế độ
   kiểm thử với tốc độ 2 đặt cổng giờ/nến và cờ M1 bằng 1; tốc độ 3
   đặt cổng giờ/nến bằng 0 và cờ M1 bằng 1. Các tốc độ khác giữ nguyên
   hai cờ này.
3. Đặt mốc lần hỏi NFP về 0. Cả hai bot có ba khối lịch: NFP, lãi suất
   và CPI. Mỗi khối được bật thì lấy lịch, lưu thời điểm và in thông
   báo. Sau đó gọi bộ chọn mốc tin dùng chung; hàm này không phải hàm
   chuẩn bị tài khoản. Các nhánh lỗi chuỗi vẫn cần kiểm riêng.
4. Đọc số dư; nếu cài đặt dùng vốn
   chủ sở hữu thì đọc thêm vốn chủ sở hữu. Tạo chuỗi khóa vốn theo số
   tài khoản và xử lý giá trị lưu trước khi chọn vốn thực dùng.
5. Ghi 240, 89 và 134 mốc vào đầu ba mảng lịch dự phòng, giữ các ô còn
   lại, đồng thời đặt lại hai byte trạng thái. Bot 3 còn đọc thông tin
   kiểm thử sau khi đặt hai byte về 0. Phần khởi tạo tham số, các mốc
   nến và hàng chờ tiếp theo còn cần ghép. Nơi gọi gốc chuẩn bị chiến
   lược đầu trực tiếp qua `0x7500` / `0xe0c0`; không tự chèn thêm bước
   nạp cấu hình chiến lược vào nơi này khi chưa đối chiếu.
6. Gọi tạo bảng rồi cập nhật trạng thái mở và trạng thái đã đóng theo
   đúng thứ tự nêu trong bảng. Hàm tạo bảng có thể gọi nhiều dịch vụ
   biểu đồ; phần này đã có bộ kiểm riêng.

`0x20a00` (bot 1) và `0x2bb80` (bot 3) là hàm khởi tạo tĩnh của thời
gian tải, không phải OnInit. Không gộp chúng vào hàm khởi tạo EA.

Đã sửa ngày 28/10: bản trước bỏ sót NFP của bot 1, gọi nhầm bộ chọn
tin là khối tài khoản và lấy nhầm phần đuôi địa chỉ mã C làm độ lệch.
Các địa chỉ sửa trong bảng được đọc lại trực tiếp từ lệnh máy.
Phần tin đã so 637/637 ca mỗi bot; dữ liệu lịch dự phòng và hai cờ
đã so 108/108 ca mỗi bot. Xem
[phần tin](news-initialization-20261028-r1/README.md) và
[dữ liệu dự phòng](builtin-news-initialization-20261028-r1/README.md).

Bot 1 đã dựng đoạn ngữ cảnh trước chuẩn bị, 298/298 ca khớp; có điều
kiện nối từ phần trước được cấp. Vẫn cần khởi tạo tĩnh các đầu vào
chuẩn bị, không dùng bộ cấu hình chiến lược 0 thay cho giá trị đầu.
[Phạm vi ngữ cảnh](startup-context-20261028-r1/README.md).

Bot 1 đã dựng đuôi sau chuẩn bị `0x4e77..0x5658`, khớp **309/309 ca**.
Phần này dùng chung `panel.lots`, chỉ số chiến lược và trạng thái từ đoạn
trước. Có ghi nhận riêng lịch sử và ba hàm bảng; chưa kiểm nhánh lỗi
`0x5659..0x5877` hoặc toàn bộ `OnInit`.
[Phạm vi đuôi](startup-tail-20261028-r1/README.md).

Đã quan sát bản gốc chạy thật với tám chiến lược tắt và phục hồi 41
đầu vào chuẩn bị nội bộ của bot 1, giữ riêng 13 trường người dùng.
Hàm `Bot1InitializeStartupInputs` chỉ dùng khi nạp trạng thái chương
trình; chưa là toàn bộ khởi tạo tĩnh hoặc các đầu ra của nó.
[Bằng chứng và giới hạn](startup-inputs-20261028-r1/README.md).

Phần còn thiếu trước khi viết OnInit bàn giao:

Khi nối chuẩn bị bot 3, cần giữ đúng các vùng dùng chung: `P.native_6d630`
và `Panel.mode` cùng ô 32 bit `0x6d630` nhưng một bên có dấu, một bên
không dấu. `Inputs.native_1d7138`/`Panel.manual_lots` ở `0x1d7138`
khác ô khối lượng đã chuẩn bị `P.native_6d620` tại `0x6d620`; không
được gộp hoặc chép ngược hai ô này chỉ vì ban đầu có thể bằng nhau.
Nguồn ánh xạ: `check-preparation-full.py` phần `EXTRA` và
`kiem-tao-bang-bot-1-3.py` phần `fields(3)`.
`Bot3StartupPreparationFlow` đã nối hai cách đọc ô chế độ, truyền
tham chiếu khối lượng cài đặt và đồng bộ các bản giữ dữ liệu ở biên
hàm. Ca trả về sớm, giá trị âm của chế độ và thay đổi giữa lời gọi
đã được đối chiếu; không chép khối lượng đã chuẩn bị về cài đặt.

- ghép phần trước khởi tạo với đoạn sau chuẩn bị đầu; bot 1 đã nối
  đến trả về và so 639 ca, còn lỗi chia 0/cấp phát và ba thân hiển thị
  thật trong phép kiểm nối;
- phép so trực tiếp của hàm kiểm quyền và trạng thái từ chối;
- bảng nối đầy đủ mọi cài đặt đầu vào vào các vùng khởi tạo;
- thứ tự chính xác của các mảng nến, hàng chờ và các nhánh lỗi cấp phát;
- các sự kiện OnTick/OnDeinit và nơi gọi vòng đánh giá sau khởi tạo.

[Bằng chứng đoạn sau chuẩn bị](startup-trading-state-20261028-r1/README.md):
54 trường/1.800 ô, giữ nguyên khung tuần và các lần đọc lại thông tin.

Thân kiểm quyền đã được băm và mô tả riêng tại
`authorization-flow-20261028-r1.md`; không ghi khóa hoặc gửi yêu cầu mạng.

Nguồn: `ma-trung-gian.c` dòng 714–2466 và
`ma-trung-gian-day-du.c` dòng 715–2734; bảng hàm trong
`metadata/import.json`. Không dùng đặc tả này để vượt kiểm quyền hay
để gọi là đã có EA hoàn chỉnh.
