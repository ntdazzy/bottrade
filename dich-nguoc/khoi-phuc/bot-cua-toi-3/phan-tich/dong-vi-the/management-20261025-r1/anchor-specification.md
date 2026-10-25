# Phần lấy giá lưu trước khi dời dừng/chốt

Phạm vi đã đọc trực tiếp: mua `0x33b73..0x33d76` (cuối không gồm),
bán `0x38194..0x3839c`. Đây là hai đoạn nằm trong hàm quản lý,
không phải hai hàm gốc độc lập. Chưa xác nhận toàn hai hàm quản lý.

## Đầu vào và tác dụng

- Bảng vé/giá `0x72e10`: 100×2 double; bắt đầu từ `0x73450-1600`.
  Không nhầm với hai bảng ảo 500 hàng. Tìm theo vé double và ưu tiên
  hàng đầu tiên. Vé 0 có thể khớp hàng trống; NaN không khớp.
- Giá mở đã làm tròn ở XMM6, vé double ở XMM9, số 0 ở XMM11.
  Phần này gọi `SymbolInfoInteger(symbol,17)` một lần. Giữ đơn vị giá,
  khoảng cách và cờ dưới dạng tham chiếu để đọc sau lời gọi đó.
- Trước gọi API: chép double cài đặt `0x6d600` sang `0x74428`.
- Sau API: đổi vé double sang long có dấu, rồi đổi long đó lại thành
  double để tìm/ghi bảng. Lệnh `cvttsd2si` cho LONG_MIN khi NaN/vô hạn/
  ngoài khoảng. Vé dùng ở các phần kế tiếp được giữ kiểu long.
- Tìm hàng có vé bằng giá trị vừa đổi; lấy mức lưu hoặc +0 nếu không
  tìm thấy. Làm tròn bằng công thức `Bot3RoundPrice`, digits lấy thấp
  32 bit và chặn trên 11. Hai nhóm hằng làm tròn đều ±0.5000001.
- Nếu mức sau làm tròn khác 0 (gồm NaN), cộng `unit * negative_zero`.
  Số âm 0 lấy từ `0x58478` ở mua, `0x584a0` ở bán; cả hai có byte
  `0000000000000080`. Không bỏ phép nhân/cộng này vì unit có thể
  không hữu hạn. Giữ phép nhân rồi mới cộng, không đổi thứ tự.
- Nếu mức bằng 0: lấy giá mở làm mức, tìm hàng trống đầu có vé==0;
  có hàng thì ghi vé rồi giá mở. Bảng đầy vẫn trả giá mở, không dọn.
- Cờ khoảng cách, mua: `anchor > (0-unit*0)` rồi mới kiểm
  `(opened-anchor) > (limit*unit)`; bán: `anchor > (unit*0+0)` rồi
  mới kiểm `(anchor-opened) > (limit*unit)`. `jbe` gốc chặn cả NaN;
  không viết thành phủ định hai phép `<=` như C trung gian.
- Giá tham chiếu cuối bằng giá mở, cờ byte `0x6d508` khác 0 thì lấy
  anchor. Không đổi điều kiện này thành cờ==1.

## Nguồn dựng và cách kiểm

`Bot3ManagementAnchor.mqh` chỉ dựng đoạn trên. Cần so trực tiếp đoạn
lệnh gốc với nguồn đã biên dịch: toàn bảng 200 double, vé long, mức,
cờ khoảng cách, giá tham chiếu, giá trị chép trước API và trạng thái
trước/sau API. Đầu vào gồm ±0, NaN, vô hạn, vé lớn/trùng, bảng đầy,
digits thấp 32 bit, các giá trị sát ngưỡng và cài đặt đổi trong API.
Phép kiểm không thay việc ghép/sửa/đóng/gửi và vòng lặp của cả quản lý.
