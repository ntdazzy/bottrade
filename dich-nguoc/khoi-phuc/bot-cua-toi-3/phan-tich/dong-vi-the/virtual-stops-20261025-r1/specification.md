# Mô tả năm hàm bảng dừng/chốt ảo bot 3

Codex đọc trực tiếp 530 lệnh trong `analysis.json`, `native-guards.txt`
và bản C đi kèm trước khi giao viết nguồn. Đây là mô tả để dựng từng
phần; chưa phải kết quả so MQL5 hoặc xác nhận toàn EA.

## Dữ liệu và bằng chứng

- EX5 gốc: SHA-256 `ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`.
- Đầu mã chụp `0x17156250000`; mọi vị trí sau đây đã trừ đầu mã.
- Bảng dừng lỗ `0x6d680`: `double[500][3]`, lần lượt vé, mức, giờ.
- Bảng chốt lời `0x70560`: `double[500][2]`, lần lượt vé, mức.
- Cờ `0x73450`: byte; chỉ truy cập bảng khi đúng bằng 1.
- Vé đã báo đầy bảng: dừng `0x73458`, chốt `0x73460`, số nguyên có dấu 64 bit.
- Chờ `0x6d518`: số nguyên có dấu 32 bit. Đơn vị giá `0x73dd8`: double.
- Mảng vé đang mở `0x1d6d10`: số nguyên có dấu 64 bit, chiều động,
  thứ tự thường/đảo theo cờ mảng. `api-contract.json` xác nhận kiểu,
  cách đổi kích thước và tám lời gọi bên ngoài.
- Hằng làm tròn ±0.5000001 đã có ở
  `doi-chung-mt5/bang-dung-ao-20261024/rounding.json`.
- Nội dung/kiểu/thứ tự 7 đối số thông báo đã có ở
  `doi-chung-mt5/bang-dung-ao-20261024/full-table-warning-schema.json`.

## 0x20bc0 — dọn cả hai bảng

1. Nếu độ dài mảng vé <64: `ArrayResize(open_tickets,64,0)`.
2. Đọc `PositionsTotal()` đúng một lần. Duyệt chỉ số 0 đến total-1;
   nếu total<=0 không duyệt. Mỗi chỉ số gọi `PositionGetTicket(index)`.
   Vé 0 bỏ qua. Vé khác 0 đọc `PositionGetInteger(POSITION_TYPE=2)`;
   đổi kết quả sang unsigned 64 bit rồi chỉ nhận giá trị <2.
3. Trước ghi mỗi vé: nếu length<=count, đổi dài thành count+64,
   reserve 0. Không tự xử lý kết quả thất bại; phép ghi mảng kế tiếp
   phải giữ lỗi vượt giới hạn nếu vẫn không đủ. Ghi vé vào chỉ số
   logic count theo cờ đảo hiện tại rồi tăng count. Không thu nhỏ mảng.
4. Sau quét mới đọc cờ; nếu cờ!=1 thì thoát. Duyệt row=0..499.
   Tại MỖI hàng xử lý dừng rồi mới xử lý chốt. Chỉ xét vé double>0;
   số không xác định, 0, số âm không được xóa. Đổi vé double sang
   long có dấu; tìm trong count vé đã thu, không xét đuôi mảng cũ.
   Không tìm thấy thì xóa dừng theo thứ tự giờ→mức→vé; xóa chốt
   theo thứ tự vé→mức. Giữ điều kiện/lỗi mảng của ngôn ngữ gốc.

## 0x47f10 — lấy/tạo dừng lỗ

Đầu vào `(int side,double price,double distance,long ticket)`;
symbol và unit là biến dùng chung, đọc lại sau lời gọi lấy digits.

1. Nếu cờ==1: tìm từ hàng 0, so double vé với `(double)ticket`,
   NaN không bằng; gặp đầu tiên trả mức nguyên trạng. Vé 0 có thể
   khớp hàng trống và trả mức cũ ngay, trước bất kỳ tính toán nào.
2. side==2: gọi SymbolInfoInteger(symbol,17), rồi tính riêng
   `distance*unit+price`. side==1: gọi như trên rồi tính
   `price-distance*unit`. side khác: mức +0, không đọc digits.
3. Làm tròn bằng `Bot3RoundPrice`: long whole=(long)value;
   nếu whole==LONG_MIN trả value; digits lấy thấp 32 bit rồi chặn
   trên 11; scale=10^digits; kết quả
   `(double)(long)((value-(double)whole)*scale+(value>0 ? 0.5000001 : -0.5000001))/scale+(double)whole`.
4. Đọc lại cờ; nếu ==1 tìm ô đầu có vé==0. Ghi vé, mức, giờ=+0,
   trả mức. Nếu không có ô hoặc cờ!=1, gọi dọn 0x20bc0 vô điều kiện.
5. Đọc lại cờ và thử tìm/ghi ô trống lần nữa theo đúng thứ tự trên.
6. Vẫn không ghi được: nếu vé đã báo dừng khác ticket thì ghi ticket
   vào vé đã báo TRƯỚC, gọi PositionsTotal, đọc lại cờ để số ô bằng
   0 khi cờ==0, còn lại 500. Print đúng bảy đối số trong schema,
   chuỗi đầu `Virtual SL table full (`. Trả mức dù không lưu được.

## 0x482b0 — lấy/tạo chốt lời

Đầu vào `(double level,long ticket)`.

1. Nếu cờ==1 tìm vé từ hàng 0 và trả mức lưu ở lần khớp đầu,
   trước khi xét level. Vé so bằng double như hàm dừng.
2. Nếu `level<=0.0` trả +0. Lệnh gốc tại 0x4830b/0x4830f và
   0x4833d/0x48341 là `ucomisd 0,level; jae`: NaN KHÔNG thoát,
   vì vậy không thay bằng điều kiện `!(level>0)`. Với cờ==1 và
   chưa có vé: NaN được lưu vào ô trống. +inf được lưu; -inf trả 0.
3. Nếu cờ==1 tìm ô trống đầu có vé==0; ghi `(double)ticket` rồi
   level nguyên trạng. Không làm tròn và không đọc digits/unit.
4. Không có ô hoặc cờ!=1: gọi dọn cả hai bảng 0x20bc0, đọc lại cờ,
   thử tìm/ghi ô trống như trên. Chưa được thì báo đầy như hàm dừng,
   dùng vé đã báo chốt riêng và chuỗi đầu `Virtual TP table full (`.
   Trả level nguyên trạng. Không gọi lại bước tìm vé sau dọn.

## 0x484c0 — kiểm thời gian chờ

Nếu delay<=0 hoặc cờ!=1 trả false. Tìm vé đầu bằng `(double)ticket`
trong bảng dừng. Không thấy trả false. Đổi giờ double sang long;
nếu long==0 trả true và không gọi giờ hiện tại. Còn lại gọi
TimeCurrent(), rồi đọc lại delay; lấy long elapsed=now-stamp
(tràn 64 bit giữ như gốc); trả `(long)delay<=elapsed` bằng phép so
có dấu. Không dùng phần cao của giá trị trả máy; chỉ bool thấp.

## 0x48560 — ghi giờ

Cờ!=1: thoát. Tìm vé đầu trong bảng dừng bằng double. Không thấy:
thoát. Đã tìm thấy: gọi TimeCurrent(), đổi long sang double, ghi
vào cột giờ của đúng hàng vừa tìm, kể cả dữ liệu đổi trong lời gọi.

## Phạm vi kiểm bắt buộc, còn mở

So kết quả trả có nghĩa, toàn bộ 2.500 số double của hai bảng, cờ,
hai vé đã báo, độ dài/cờ đảo/nội dung mảng vé và thứ tự lời gọi.
Gồm cờ 0/1/2/255; vé 0/âm/lớn/trùng; NaN/vô hạn/±0; ô đầu/cuối,
bảng đầy/dọn rồi ghi; hai loại vị thế và loại bị loại; mảng đảo,
mở rộng/thất bại; trước/đúng mốc chờ; thay trạng thái trong API.
So từng phần trong MT5 riêng trước khi ghép quản lý và EA đầy đủ.
