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
| Lịch tin | `0x16600`, `0x16a90` | `0x56ad0`, `0x56f20`, `0x573b0` |
| Vốn/tài khoản | `0x17310` | `0x57c30` |
| Chuẩn bị chiến lược đầu | `0x7500` | `0xe0c0` |
| Tạo bảng | `0x8320`, `0xe1b0`, `0x1ffb0` | `0xef40`, `0x14fa0`, `0x16e80` |

Thứ tự gọi thấy được trong mã máy:

1. Ghi cờ hoạt động bằng 0, đọc `AccountInfoInteger(0x20)`, gọi hàm
   kiểm quyền. Nhánh từ chối gọi bộ thông báo lỗi rồi kết thúc.
2. Ghi cờ hoạt động bằng 1. Đọc `MQLInfoInteger(6)`; trong một chế độ
   kiểm thử đặt cổng giờ/nến bằng 1, trong chế độ khác đặt bằng 0,
   đồng thời đặt cờ M1 bằng 1.
3. Đặt cờ trạng thái lịch tin về 0. Bot 1 có hai khối lịch; bot 3 có
   ba khối. Mỗi khối gọi hàm lấy lịch, dựng chuỗi, cấp phát chuỗi,
   kiểm kết quả và gọi thông báo lỗi khi cần. Không gộp ba khối bot 3.
4. Gọi khối chuẩn bị tài khoản. Sau đó đọc số dư; nếu cài đặt dùng vốn
   chủ sở hữu thì đọc thêm vốn chủ sở hữu. Tạo chuỗi khóa vốn theo số
   tài khoản và xử lý giá trị lưu trước khi chọn vốn thực dùng.
5. Khởi tạo các mốc nến, trạng thái tin và hàng chờ theo vùng dữ liệu
   gốc. Gọi chuẩn bị chiến lược đầu với cùng các vùng trạng thái dùng
   lại; không tạo lại trạng thái riêng cho từng vòng.
6. Gọi tạo bảng rồi cập nhật trạng thái mở và trạng thái đã đóng theo
   đúng thứ tự nêu trong bảng. Hàm tạo bảng có thể gọi nhiều dịch vụ
   biểu đồ; phần này đã có bộ kiểm riêng.

`0x20a00` (bot 1) và `0x2bb80` (bot 3) là hàm khởi tạo tĩnh của thời
gian tải, không phải OnInit. Không gộp chúng vào hàm khởi tạo EA.

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
