# Mô tả phần đầu quản lý bot 3

Codex đọc trực tiếp hai đoạn mã máy `0x32f60` (mua) và `0x37590`
(bán), cùng C tại `ma-trung-gian-day-du.c` và `native-guards.txt`.
Đây là phần đầu đến trước các nhánh dời dừng; chưa phải hai hàm đầy đủ.

## Đọc và lọc vị thế

- Gọi `PositionsTotal()` một lần. Vòng chỉ số tăng từ 0 đến total-1;
  total nhỏ hơn 1 thì không đọc vé.
- Mỗi vòng gọi `PositionGetTicket(index)`, ghi vé 64 bit vào biến dùng
  chung. Vé 0 bỏ qua toàn bộ thuộc tính còn lại.
- Với vé khác 0, lặp đúng thứ tự: `SymbolInfoInteger(symbol,17)` rồi
  `PositionGetDouble(6)` và làm tròn; hỏi digits lại rồi double(7) và
  làm tròn; đổi vé signed long sang double; hỏi digits lại rồi đọc
  `PositionGetDouble(4)` và làm tròn; đọc string property 11; đọc
  volume property 3; integer 1 (thời gian), 2 (loại), 12 (mã); đọc
  string property 0; cuối cùng `SymbolInfoTick`.
- Tick lỗi chỉ in thông báo qua dispatcher; sau đó vẫn lọc tiếp.
  Không bỏ vị thế chỉ vì tick lỗi.
- Nhánh mua nhận type full32 == 0; nhánh bán nhận type full32 == 1.
  Mã nhận diện phải bằng int cài đặt; cờ bật phải đúng 1; chuỗi mã
  phải so đúng nội dung UTF-16 (null khác chuỗi rỗng). Không đổi sang
  “khác 0” hoặc so không phân biệt hoa thường.

## Dừng/chốt ban đầu

- Mua: nếu dừng đã làm tròn == 0, tính `open - stop_setting*unit`,
  hỏi digits và làm tròn rồi gọi `Bot3PositionModify(ticket,sl,tp)`.
  Nếu chốt == 0, tính `take_setting*unit + open`, làm tròn và gọi
  sửa lần hai. Bỏ qua giá trị trả.
- Bán: dấu của hai phép tính đảo lại theo mã máy: dừng `open +
  stop_setting*unit`, chốt `open - take_setting*unit`. Mỗi phép gọi
  sửa riêng, không đọc lại vị thế.
- Vé truyền cho helper là long đã đổi từ double vé, giữ nguyên bit khi
  chuyển sang ulong. NaN không thỏa so bằng 0.

## Đóng theo nến

Mua và bán đều có ba nhóm cờ độc lập; chỉ khác chiều so giá (mua:
close<open và close<giá mở; bán: open<close và giá mở<close).

- Nhóm 1 dùng cờ byte `0x5d29e`, khung byte `0x5d29d` và gọi
  `iTime(tf,1)`, `iTime(tf,0)`, `iClose(tf,1)`, `iOpen(tf,1)`, rồi
  đọc lại `iClose(tf,1)`. Điều kiện thời gian là
  `open_time >= previous && open_time < current`.
- Nhóm 2 dùng cờ `0x5d2a0`; khung là 0 nếu byte `0x5d29f` bằng 0,
  ngược lại 15. Đọc lại khung trước từng lời gọi.
- Nhóm 3 dùng cờ `0x5d2a2`; khung là 0 nếu byte `0x5d2a1` bằng 0,
  ngược lại `0x4001`. Giữ thứ tự đọc và điều kiện như nhóm 2.
- Khi đủ điều kiện gọi helper đóng `0x47d20` bằng vé local và gọi
  dispatcher in thông báo. Không dừng hàm; nhóm sau và nhánh dời
  dừng tiếp tục chạy.

## Bằng chứng và giới hạn

Vị trí helper đã map trong
`management-20261025-r1/branch-map.md`: sửa `0x32a90`, đóng `0x47d20`,
lấy dừng `0x47f10`, lấy chốt `0x482b0`, chờ `0x484c0`, ghi giờ
`0x48560`. Các helper con đã có phép kiểm riêng. Chưa có nguồn MQL5
cho phần đầu bot 3 và chưa có phép so chạy; Claude chỉ viết theo mô tả
này. Các nhánh dời dừng, khối lượng, ghi bảng, nơi gọi và EA còn thiếu.
