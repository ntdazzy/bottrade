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
| Đoạn vốn/tài khoản trong OnInit | `0x126c..0x1941` | `0x1279..0x193f` |
| Nạp dữ liệu lịch dự phòng và hai cờ | `0x1941..0x3827` | `0x193f..0x3840` |
| Ngữ cảnh/bộ đếm/đuôi mã trước chuẩn bị | `0x3827..0x3c9d` | chưa dựng phần tương ứng |
| Chuẩn bị chiến lược đầu | `0x7500` | `0xe0c0` |
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

Phần còn thiếu trước khi viết OnInit bàn giao:

- phép so trực tiếp của hàm kiểm quyền và trạng thái từ chối;
- bảng nối đầy đủ mọi cài đặt đầu vào vào các vùng khởi tạo;
- thứ tự chính xác của các mảng nến, hàng chờ và các nhánh lỗi cấp phát;
- các sự kiện OnTick/OnDeinit và nơi gọi vòng đánh giá sau khởi tạo.

Thân kiểm quyền đã được băm và mô tả riêng tại
`authorization-flow-20261028-r1.md`; không ghi khóa hoặc gửi yêu cầu mạng.

Nguồn: `ma-trung-gian.c` dòng 714–2466 và
`ma-trung-gian-day-du.c` dòng 715–2734; bảng hàm trong
`metadata/import.json`. Không dùng đặc tả này để vượt kiểm quyền hay
để gọi là đã có EA hoàn chỉnh.
