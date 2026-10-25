# Bốn hàm bảng dừng ảo cần cho quản lý vị thế bot 1

Đã tách trước khi viết nguồn: `0x18790` (178 lệnh), `0x3d200`
(174), `0x3d5a0` (39), `0x3d640` (29), tổng 420 lệnh. Bản EX5
`a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922`.
`analysis.json`, `functions.c`, `native-guards.txt` và `receipt.json`
giữ bằng chứng gốc; `api-contract.json` nối tám lời gọi ngoài.
Đây là phân tích trước nguồn, chưa phải kết quả so MQL5.

## Dữ liệu chung

- `0x62590`: 500 hàng, mỗi hàng ba số thực: vé, mức dừng, dấu giờ.
- `0x66410`: một byte; truy cập bảng chỉ khi bằng đúng 1.
- `0x66418`: vé đã báo đầy bảng, số nguyên 64 bit có dấu.
- `0x62420`: thời gian chờ, số nguyên 32 bit có dấu.
- `0x66d98`: đơn vị khoảng cách, số thực.
- `0x67918`: tên mã giao dịch, bộ mô tả chuỗi MQL5.
- `0x6a3c0`: mảng vé kiểu `long`, phần tử 8 byte; độ dài tại +8,
  con trỏ vùng phần tử tại +28, cờ đảo chỉ số là bit `0x10` tại +2.

Mọi địa chỉ trên là RVA: lấy địa chỉ đầy đủ trừ `0x23e5aa10000`.
Không lấy đuôi chữ số của tên C làm RVA.

## Dọn vé đã đóng — 0x18790

C11091–11206; toàn bộ 178 lệnh nằm trong `analysis.json`.

1. Nếu mảng vé ngắn hơn 64, gọi mở rộng lên 64, dự trữ bằng 0.
2. Đọc tổng vị thế một lần. Duyệt chỉ số từ 0 đến tổng trừ 1;
   mỗi lần lấy vé khác 0 mới đọc loại vị thế. Chỉ nhận giá trị loại
   khi đổi sang số nguyên không dấu 64 bit nhỏ hơn 2.
3. Khi chưa đủ chỗ, gọi mở rộng lên số vé đã nhận cộng 64, dự trữ 0.
   Ghi vé 64 bit vào phần tử kế tiếp. Không tự bỏ qua lỗi mở rộng;
   truy cập quá kích thước đi vào lỗi mảng gốc.
4. Chỉ sau khi thu vé xong mới kiểm byte cho phép bằng 1.
5. Duyệt đúng 500 hàng. Chỉ xét vé dạng số thực lớn hơn 0. So vé
   đã đổi sang `long` với danh sách vừa thu; không thấy thì xóa dấu
   giờ, mức, rồi vé. Vé âm, 0 và NaN được giữ theo đúng phép so.
6. Mảng không thu nhỏ. Giữ tác dụng chọn vị thế của lần lấy vé cuối;
   không chọn lại vị thế trước đó và không đặt lại mã lỗi.

Nhánh chỉ số đảo dùng cách truy cập tự có của mảng MQL5; không đổi
thứ tự logic thu vé. Lỗi mảng gọi `0x3959a0`, phần mã thấp `0x1f6`;
phần cao chứa vị trí trong nguồn gốc. Vị trí báo lỗi của nguồn dựng
lại còn phải ghi riêng, không giả vờ là cùng vị trí nguồn.

## Lấy hoặc tạo mức — 0x3d200

C27109–27190. Tham số: `ECX` hướng 32 bit, `XMM1` giá,
`XMM2` khoảng cách, `R9` vé 64 bit có dấu; trả số thực trong `XMM0`.

1. Byte bằng 1: quét từ hàng 0 đến 499, trả mức của hàng đầu có vé
   bằng `(double)ticket`. Vé 0 có thể khớp một ô trống; không bỏ qua.
2. Không thấy: hướng 1 tính `price-distance*unit`; hướng 2 tính
   `distance*unit+price`; hướng khác trả mức tính bằng `+0.0`.
3. Với hướng 1/2, gọi `SymbolInfoInteger(...,17)` trước khi đọc đơn
   vị và tính giá. Dùng 32 bit thấp của số chữ số, chặn trên ở 11.
   Công thức và cặp hằng đúng ±0.5000001 đã có trong
   `doi-chung-mt5/bang-dung-ao-20261024/rounding.json`, trùng
   `Bot1RoundPrice`. Nếu đổi giá sang `long` cho `LONG_MIN`, giữ giá.
4. Byte bằng 1: tìm ô vé bằng 0 đầu tiên, ghi vé dạng số thực,
   mức và dấu giờ bằng `+0.0`. Không kiểm mức dương hoặc hợp lệ.
5. Nếu không có ô, luôn gọi dọn `0x18790`, rồi chỉ tìm ô trống lại
   một lần. Không tìm lại vé trùng sau lần gọi dọn.
6. Vẫn không có ô và vé khác vé đã báo: ghi vé đã báo trước, gọi
   `PositionsTotal`, sau đó mới đọc byte để tính số ô trong thông báo
   (0 nếu byte bằng 0, còn lại 500). In đúng bảy đối số:
   `"Virtual SL table full (",slots," slots, ",positions,
   " open positions) - ticket ",ticket," will not trail."`.
   Luôn trả mức dù không lưu được.

Thứ tự đọc byte sau `PositionsTotal`: `0x3d494` gọi, `0x3d498`
so byte với 0, `0x3d52e` chọn số ô. Bảng và thông báo đã được giải
riêng trong `full-table-warning-schema.json`; mã gọi 2 là `Print`
đã có `print-opcode-proof.json` ở cùng thư mục bằng chứng cũ.

## Kiểm chờ — 0x3d5a0

C27194–27219. Chỉ byte thấp của kết quả là giá trị đúng/sai.

- Thời gian chờ phải dương, byte phải bằng 1; quét 500 hàng theo thứ tự.
- Vé khớp đầu tiên: đổi dấu giờ sang `long`. Bằng 0 thì trả đúng
  ngay, không đọc giờ. Nếu khác 0, gọi `TimeCurrent`, rồi đọc lại thời
  gian chờ, so với hiệu giờ hiện tại trừ dấu đã đổi kiểu.
- Không thấy vé hoặc điều kiện đầu không thỏa thì trả sai.
- Chứng cứ thứ tự: `0x3d606` đổi dấu, `0x3d627` đọc giờ,
  `0x3d629` đọc lại thời gian chờ, `0x3d62c` trừ, `0x3d632` so có dấu.

## Ghi giờ — 0x3d640

C27223–27244. Byte bằng 1 mới quét. Gặp vé khớp đầu tiên thì gọi
`TimeCurrent`, đổi kết quả 64 bit có dấu sang số thực và ghi dấu giờ
vào đúng hàng đã tìm; không dò lại vé sau khi đọc giờ. Không thêm hàng.
Lệnh ghi ở `0x3d6b3`; hàm không có giá trị trả về dùng được.

## Phải kiểm trước khi ghép

So nguồn đã biên dịch với bốn hàm gốc: toàn bộ 1.500 số trong bảng,
vé đã báo, độ dài/phần đã xác định của mảng vé, giá trị trả có nghĩa,
thứ tự và đối số gọi ngoài, trạng thái chọn vị thế, lỗi mở rộng/mảng.
Kiểm byte 0/1/2/255; vé 0/trùng/âm/lớn; bảng đầy; gọi dọn rồi thử lại;
dấu giờ NaN/vô hạn/phần lẻ và hiệu số 64 bit; thay dữ liệu trong lần
gọi ngoài để kiểm đúng thời điểm đọc lại. Còn so trong máy đo quá khứ
và ghép vào hai hàm quản lý. Chưa xác nhận phần này hoặc toàn bot đạt.
