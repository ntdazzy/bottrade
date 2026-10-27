# Tạo toàn bộ bảng của bot 1 và bot 3

Đọc lại EX5 và bản chụp trước khi viết. Bot 1: SHA-256
`a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
Bot 3: `ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`.

| Phần | Bot 1 | Bot 3 |
|---|---|---|
| Hàm tạo bảng đầy đủ | `0x8320..0xe1ae` | `0xef40..0x14f98` |
| SHA-256 thân hàm | `7c540d0d6d2057502c8e57b66291ae617d1fb325ce677f2e066ac2ccd20bb8dc` | `889bf0b36cb6250816cadfa17e0e2e21beedbccf54ff84bd7c1b1ad9de042920` |
| Kích thước đầu vào, cỡ chữ | `0x6a538`, `0x6a540` | `0x1d6f48`, `0x1d6f50` |
| Cờ màu ban đầu | `0x678f8` | `0x74938` |
| Chế độ, nhịp giao dịch | `0x6a748`, không có | `0x6d630`, `0x6d21c` |
| Cờ dấu sao, cờ đã tạo hàng | `0x623c4`, `0x67930` | `0x6d43c`, `0x74970` |
| Ba dãy số `double` | `0x69f80`, `0x67ad0`, `0x66a80` | `0x76fc0`, `0x74b10`, `0x73ac0` |
| Số chiến lược | 8 | 9 |

Các địa chỉ trong bảng tính từ đầu vùng mã. Không trừ địa chỉ tuyệt đối
nhầm một đoạn `0x10000`: hằng số bot 1 nằm tại `0x4fd60..0x4fdc8`.
Tệp phân tích ban đầu có trường `constants` đọc nhầm địa chỉ; không dùng
trường đó. Đã đối chiếu lại lệnh máy và đọc đúng: chiều rộng 350,
chiều cao 320 (bot 1) hoặc 350 (bot 3), các mốc 20, 4, 32, 44,
76, 92, 108, 124, 160. Bot 3 có thêm mốc 60 cho `linet`.

## Đầu vào, thứ tự và tác dụng phụ

- Đọc cỡ chữ kiểu `int32` một lần trước lời gọi MT5 đầu: nếu > 0 dùng
  giá trị đó, còn lại dùng 7. Cộng 1, 3, 4 theo số 32 bit, có tràn số.
- Tạo `infopanel_rectangle` loại 110, rồi đặt lần lượt vị trí X=5,
  Y=20. Sau đó mới đọc và giữ kích thước đầu vào trong biến cục bộ.
  Rộng = 350 * kích thước, cao = 320 * kích thước + 0 hoặc
  350 * kích thước + 0. Ép sang `long` theo MT5.
- Đặt thuộc tính khung theo đúng thứ tự: 0x402=0, 0=0x3a2a1e,
  0x401=0x17110d, 3=0, 0x40b=0x3a2a1e, 0x405=0, 1=0, 2=2, 10=0.
- Tạo `line1`, `linec`, `line2`, `lines`, loại 102; bot 3 tạo thêm
  `linet`. X=11. Y lần lượt 24; scale*20+20+4;
  scale*32+20+4; scale*44+20+4; scale*60+20+4.
  Giữ nguyên các chuỗi gốc, gồm cả chữ `lotsizee` và tên tác giả.
- Màu ban đầu ở các tên cố định bằng 0x8b0000 khi cờ màu khác 0;
  còn lại 0. Riêng bốn dòng có tên ghép số kiểm bit thấp nhất của cờ.
  Cờ phải đọc tại từng vị trí gốc, không chụp chung từ đầu hàm.
- Bot 1: `lines` đặt cỡ chữ trước khi dựng chữ. Chế độ 3 hiện mức
  rủi ro theo chiến lược; 999 theo từng giao dịch; 9999 hiện bước
  số dư; còn lại làm tròn 2 số dãy khối lượng[0] rồi hiện 2 chữ số.
- Bot 3: `lines` hiện nhịp 0..4 hoặc nhãn chọn chiến lược thủ công.
  Chụp chế độ sau khi đặt cỡ chữ `lines`, trước khi tạo `linet`.
  Chế độ 3 hiện rủi ro chiến lược, 1234 hiện mức sụt giảm cho phép,
  còn lại hiện khối lượng thủ công. Giữ phép đổi số thành chữ của MT5.
- Tạo bốn dòng `lineopl0`, `linea0`, `linetp0`, `linenfp0`, tại
  scale*(76,92,108,124)+20+4. Mỗi lần sử dụng tên đều gọi lại
  `IntegerToString(0,0,32)`, kể cả trước từng thuộc tính.
  Riêng màu: đọc cờ trước lời gọi đổi số thành chữ.
- Sau khi đặt X của `linenfp0`, chạy nguyên khối chọn tin đã phục hồi,
  dựng chữ tin/ngày giờ, rồi mới dựng lại tên và đặt chữ, màu, cỡ chữ.
- Y đầu bảng = ép `int32` của (scale*160+20+4). Tạo bốn ô tiêu đề
  `Strategy`, `Closed PL` hoặc `Closed PL*` khi cờ dấu sao ==1,
  `PL per trade`, `Lotsize`. Màu 0xc4b741, hàng 0, cột 0..3.
- Sau bốn tiêu đề, ghi cờ đã tạo hàng =1. Lặp đúng 8 hoặc 9 hàng.
  Mỗi hàng: tên chiến lược (đổi số i+1), số đã đóng, số mỗi giao dịch,
  khối lượng. Các số đọc mới ngay trước làm tròn, giữ công thức
  `BotNRoundPrice(value,2)` và `DoubleToString(value,2)` đã kiểm.
  Cột 0..3, hàng i+1, màu 0xb09a8b. Ô gọi hàm `BotNCreatePanelCell`
  đã kiểm đủ; giữ tham chiếu kích thước/cờ chữ cho phép đọc mới.
- Dò từng tên để đặt màu, cỡ chữ và phông: line1, linec, lines,
  linet (cả bot 1), lineopl0, linea0, lineto0, linetp0, linenfp0,
  linenextnews0. Chỉ sửa khi `ObjectFind` khác -1, kể cả các giá trị
  âm khác. line1 dùng Arial Bold và cỡ+4; các dòng còn lại Arial,
  cỡ+1. Màu theo lời gọi gốc được lưu trong bản ghi phân tích.
- Đường kẻ cuối bắt đầu chuỗi rỗng, nối ký tự `─` đúng số lần bằng
  ép `int32` của rộng/(cỡ chữ+3). Không tự giới hạn số vòng.
  Đặt chữ line2; nếu dò thấy thì đặt màu 0x503a2a, cỡ+1, Arial.
- Không kiểm/đổi kết quả trả về các lời gọi tạo/sửa đối tượng.
  Khối chọn tin vẫn cập nhật trạng thái tin như bản gốc.

## Kiểm cần làm

Chạy nguồn thật trong MT5 riêng để ghi tất cả lời gọi, tham số, chữ
và trạng thái. Cấp đúng phản hồi đó cho thân hàm gốc còn nguyên,
kể cả hàm tạo ô, chọn tin và quản lý chuỗi. So từng bước và trạng thái
cuối, có ca đổi cờ/số sau lời gọi, lỗi MT5, các nhánh nhãn, làm tròn,
dò không thấy, tràn cỡ chữ và chuỗi rỗng. Bản ghi phân tích dùng phản
hồi giả để hiểu luồng; tự nó không chứng minh nguồn đã khớp.

Chưa kiểm ảnh bảng thực tế và chưa phải phép so hai EA đầy đủ.
