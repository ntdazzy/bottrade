# Phần đầu quản lý bot 3 — mô tả đã sửa

Mô tả này thay `management-20261025-r1/prelude-specification.md`, giữ
nguyên tệp cũ để thấy lỗi đã sửa. Gốc SHA-256
`ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83`,
đầu mã `0x17156250000`. Codex đã kiểm lại byte của hai thân hàm so
với `management-20261025-r1/analysis.json` và đọc riêng hai chiều.

## Ranh giới và ba sửa đổi

- Chỉ dựng đọc/lọc một vị thế, bổ sung dừng/chốt, ba lần đóng theo
  nến. Mua từ `0x330f1` tới trước `0x33b73`; bán `0x3771e` tới
  trước `0x38194`. Không viết vòng quản lý hoặc nhánh dời dừng.
- Cờ/khung nến đúng là `0x6d29c..0x6d2a2`, không phải `0x5d...`.
  Địa chỉ được tính bằng địa chỉ tuyệt đối trừ đầu mã.
- `iTime` đầu mỗi nhóm dùng byte shift `0x6d29c`, không cố định 1.
  Các lời đọc giá đóng/mở vẫn shift 1. `iTime` sau đó dùng shift 0.
- Vòng ngoài gốc đọc PositionsTotal lúc vào và sau từng vòng; phần
  này không dựng vòng ngoài, vì vậy không thêm vòng total cố định.

## Kiểu dữ liệu và đọc/lọc

`Bot3ManagedPosition` có sl,tp,ticket_number,open_price,volume là
double; comment/symbol là string; opened,type,magic là long.
Hàm `Bot3ReadManagementPosition(index,buy,magic,enabled,symbol,
last_ticket,tick,position)` trả bool và dùng lại struct này.
`magic`, `enabled`, `symbol` là tham chiếu đến cài đặt dùng chung;
last_ticket ulong, tick MqlTick và position là đầu ra tham chiếu.

1. Gọi PositionGetTicket(index), ghi vào last_ticket `0x74838`. Nếu 0
   thì trả false ngay, không thay các trường position/tick.
2. SymbolInfoInteger(symbol,17) rồi PositionGetDouble(6), làm tròn
   theo Bot3RoundPrice và gán sl. Lặp hai lời gọi riêng cho tp (7).
3. Sau tp mới lấy last_ticket hiện tại, đổi `(double)(long)` vào
   ticket_number; sau đó đọc digits rồi PositionGetDouble(4), làm
   tròn vào open_price. Không dùng vé nguyên ban đầu nếu lời gọi đã
   thay last_ticket. Digits lấy thấp uint32, chặn trên 11.
4. Đọc PositionGetString(11) vào comment; double(3) vào volume;
   integer(1) vào opened; integer(2) vào type; integer(12) vào magic;
   string(0) vào symbol của vị thế. Giữ đúng thứ tự từng lời gọi.
5. SymbolInfoTick(symbol,tick). Nếu false, Print("Tick not ok");
   vẫn tiếp tục lọc. Không tự xóa tick khi API trả false.
6. Type lấy thấp int32, phải bằng buy?0:1. Magic lấy thấp int32,
   so bằng cài đặt magic int32; enabled phải ==1. Chuỗi vị thế so
   đúng với symbol dùng chung hiện tại, phân biệt NULL và rỗng theo
   MQL5. Không dùng cờ khác 0 hoặc gộp lời đọc.

Lời gọi gốc đã có bằng chứng chữ ký ở các phép kiểm chọn/đóng/sửa
vị thế và chương trình có nguồn. Scratch double `0x1d6e48`, string
`0x1d6e3c`, tick `0x74790` (+8 Bid, +16 Ask).

## Bổ sung mức ban đầu

`Bot3FillManagementInitialLevels(buy,symbol,unit,stop_distance,
take_distance,position,state,options)`; cài đặt symbol/unit/khoảng là
tham chiếu. Đọc digits TRƯỚC khi đọc lại các cài đặt tính giá.

- Nếu sl==0.0, gọi SymbolInfoInteger(symbol,17), tính riêng:
  mua `open_price-stop_distance*unit`; bán
  `stop_distance*unit+open_price` (giữ thứ tự hai số cộng).
  Bot3RoundPrice, ghi position.sl, gọi Bot3ModifyPosition với
  `(ulong)(long)position.ticket_number`, sl và tp địa phương.
- Sau đó nếu tp==0.0, lại đọc digits: mua
  `take_distance*unit+open_price`; bán
  `open_price-take_distance*unit`. Ghi tp rồi sửa lần hai.
- Bỏ qua bool của sửa. Không đọc lại vị thế; NaN không bằng 0.
- Hằng làm tròn của hai chiều `0x58468/0x58490` đều đúng
  [-0.5000001,+0.5000001], đã đọc trực tiếp.

## Ba nhóm đóng theo nến

Viết một hàm `Bot3CloseManagementCandle` cho một nhóm; bên gọi chạy
nhóm 0,1,2 độc lập theo đúng thứ tự. Các cờ/khung/shift truyền tham
chiếu; position là ảnh địa phương đã đọc. Nhóm là int 0/1/2 xác định
khung: 0 dùng nguyên byte; 1 byte==0?0:15; 2 byte==0?0:0x4001.

| Nhóm | Cờ bật byte | Khung byte | Shift iTime đầu |
|---|---|---|---|
| 0 | 0x6d29e | 0x6d29d | byte 0x6d29c |
| 1 | 0x6d2a0 | 0x6d29f | byte 0x6d29c |
| 2 | 0x6d2a2 | 0x6d2a1 | byte 0x6d29c |

1. Cờ phải đúng 1. iTime(symbol,khung_hiện_tại,shift_hiện_tại).
   Nếu previous>position.opened thoát riêng nhóm.
2. Đọc lại khung, iTime(symbol,khung,0). Nếu opened>=current thoát.
3. Đọc lại khung, iClose(symbol,khung,1); giữ close1. Đọc lại khung,
   iOpen(symbol,khung,1). Mua cần close1<open1; bán open1<close1.
4. Đọc lại khung rồi iClose lần nữa shift1. Mua cần close2<open_price;
   bán open_price<close2. Mỗi phép < có thứ tự; NaN làm sai.
5. Gọi **Bot3TryClosePosition**, không gọi trực tiếp Bot3ClosePosition.
   Hàm gốc `0x47d20` có bước kiểm trước đóng đã có nguồn; truyền state,
   options,deviation, tick.bid,tick.ask,threshold_a,threshold_b và
   `(ulong)(long)ticket_number`. Threshold lần lượt tham chiếu các
   biến gốc `0x73ab0/0x744a8`. Không thay helper này bằng hàm giả
   trong nguồn thật. Chỉ bộ kiểm được chặn ở ranh giới helper.
6. Print("closing candle confirmation") sau helper, kể cả nó không
   gửi đóng. Không thoát khỏi phần quản lý, tiếp tục nhóm kế tiếp.

Chuỗi đã đọc trực tiếp từ mô tả `0x5cd78` và `0x5de78`. Không có
chuỗi khác/phép cập nhật tài khoản nào trong chính phần này.

## Cách kiểm và phần còn thiếu

So đoạn máy gốc đến ranh giới trên với nguồn MQL5, gồm sl,tp,vé
double/ulong, giá mở/volume/giờ/type/magic, chuỗi (cờ NULL), tick và
toàn bộ thứ tự/đối số lời gọi. Bộ kiểm được cấp dữ liệu truy vấn và
bool sửa/helper đóng để kiểm chính phần gọi; ghi rõ chưa ghép con.
Kiểm cả ba nhóm, shift 0/1/2/255, cờ 0/1/2/255, vé lớn/âm, chữ Việt,
số đặc biệt, sát ngưỡng và giá đóng lần hai khác lần một.

Chưa phải toàn hai hàm; còn vòng ngoài, cách ghép helper thật, dời
dừng thật/ảo, đọc/ghi bảng, chế độ, lỗi bộ nhớ, cài đặt/UI/lưu trạng
thái và EA chính. Không dùng số ca để tuyên bố hoàn thành toàn bot.
