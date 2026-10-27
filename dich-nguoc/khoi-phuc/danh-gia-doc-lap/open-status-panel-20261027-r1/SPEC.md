# Bảng thông tin đang mở: mô tả đã chốt

Bot1 `e1b0..ffac`, SHA `d07dad1697521b171f73ab53d282d9271f6361b95dcab4ef7de0a18dc9587a7e`.
Bot3 `14fa0..16e79`, SHA `ddd0398ac83f078510fa3a42a42373670bb9f4a18b45972a40f8706a1f4c5906`.
Các bản symbolic chỉ dùng đọc cách ghép chữ, chưa phải phép kiểm đạt.

## Giao diện và thứ tự

Hàm `BotNUpdateOpenStatusPanel` nhận tham chiếu const cho mọi giá trị gốc:
`uchar show,show_tester; int seed; string symbol; double balance;`
Bot1 thêm `double first_volume; int mode; double trade_risk,strategy_risk; int balance_step`.
Bot3 thêm `int frequency,mode; double manual_lots,allowed_dd,strategy_risk`.
Cuối cùng cùng nhận `const BotNNewsEvents &events,const BotNNewsWindows &windows,
BotNNewsSelection &selection,ulong &last_ticket`.

1. `show==0`: trả ngay. Đọc `MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6)`.
   Bot1 sau lần đọc này chụp `show_tester` vào biến cục bộ. Nếu kết quả==1
   và cờ này==0 thì trả. Bot1 gọi lại MQLInfoInteger(6); chỉ cộng vị thế
   khi kết quả lần hai!=1 hoặc cờ đã chụp!=0. Bot3 chỉ đọc thông tin một lần;
   nếu==1 và show_tester==0 thì trả, còn lại luôn xét vị thế.
2. `open_pl=0.0`. PositionsTotal một lần; nếu>0 thì chụp 8 mã (B1) hoặc
   15 mã (B3): cộng seed+1..N theo số 32 bit có dấu rồi mở rộng thành long.
   Duyệt tăng từ0. Mỗi lượt `last_ticket=PositionGetTicket(i)`; khác0 mới:
   PositionGetString(0), so nguyên chuỗi với symbol hiện tại; sau đó lặp
   PositionGetInteger(12) riêng từng lần so với từng mã đã chụp, dừng khi khớp.
   Khi khớp mã, PositionGetInteger(2)==0 hoặc gọi mới lần2 ==1 thì:
   PositionSelectByTicket(last_ticket), bỏ kết quả; đọc PositionGetDouble(10),
   lưu kết quả; đọc PositionGetDouble(9); SetUserError(4014), để lỗi=69550;
   `part=first+second; part=part+0.0; open_pl=open_pl+part`.
   Cuối mọi lượt tăng i rồi đọc PositionsTotal mới, tiếp tục nếu i<kết quả.
3. `value=DoubleToString(open_pl,2)` TRƯỚC `IntegerToString(0,0,32)`.
   ObjectSetString(0,"lineopl"+số0, (ENUM_OBJECT_PROPERTY_STRING)6,"Open P/L: "+value).
4. DoubleToString(balance,2), IntegerToString(0,0,32),
   ObjectSetString(0,"linea"+số0,6,"Account Balance: "+value).
5. Gọi nguyên `BotNUpdateNewsSelection(events,windows,selection)`.
   Nếu selection.block_time!=0: tạo chữ `"Next News: "+selection.label+", "+
   chuyển datetime thành string; còn0 dùng `"no news coming up"`.
   Chuyển IntegerToString(0,0,32) SAU chuỗi tin; ObjectSetString0,"linenfp"+số0,6,chữ.
6. Bot1: mode3 dùng `(string)strategy_risk`, nhãn
   `"Using Max Risk Per Strategy: "+value+"%"`;
   mode999 `(string)trade_risk`, `"Using Max Risk Per Trade: "+value+"%"`;
   mode9999 `(string)balance_step`, `"Using Lots Per Balance, stepsize: "+value`;
   còn lại DoubleToString(Bot1RoundPrice(first_volume,2),2),
   `"Using fixed lotsizee: "+value+"lots"` (giữ nguyên lỗi chữ).
   Gọi ObjectSetString0,"lines",6,chữ. Không gọi IntegerToString cho tên này.
7. Bot3: frequency0..4 lần lượt `extreme conservative`, `conservative`,
   `moderate`, `intense`, `extreme`; còn lại `manual strategy selection`.
   ObjectSetString0,"lines",6,"Trade Frequency: "+tên.
   Sau lời gọi này mới đọc mode:3 `(string)strategy_risk`,
   `"Max risk per strategy: "+value+"%"`;1234 `(string)allowed_dd`,
   `"Max allowed DD: "+value+"%"`;còn lại `(string)manual_lots`,
   `"Manual lotsize: "+value+"lots"`. ObjectSetString0,"linet",6,chữ.
   Hậu tố `lots` đã xác nhận bằng `bot3-manual-symbolic.json` với mode0.

Mọi kết quả ObjectSetString đều bị bỏ qua. Không thêm/đổi màu hoặc tạo đối tượng.
Không sao chép toàn bộ trạng thái: các giá trị sau mỗi lời gọi phải đọc từ tham chiếu
gốc. Các mã nhóm, cờ tester B1, kết quả số/chữ cục bộ giữ giá trị đã chụp.

## Địa chỉ dữ liệu

| Trường | B1 | B3 |
|---|---|---|
| show / show_tester | 6a528 / 6a530 | 1d6f38 / 1d6f40 |
| seed / symbol / ticket | 6a610 / 67918 / 677f8 | 1d6ff0 / 74958 / 74838 |
| balance / first_volume | 6a320 / 66a80 | 1d6c60 / không dùng |
| mode | 6a748 | 6d630 |
| trade_risk / strategy_risk / step | 6a750 / 6a758 / 6a768 | không dùng / 1d7150 / không dùng |
| frequency / manual_lots / allowed_dd | không dùng | 6d21c / 1d7138 / 1d7140 |
| error | 6a410 | 1d6e10 |

Phạm vi là cập nhật chữ và tính lãi/lỗ mở; chưa gồm tạo bảng, màu/vị trí, lịch sử,
EA đầy đủ hoặc ảnh bảng chạy thật. Bộ kiểm sẽ so toàn bộ lời gọi, trạng thái
trước dịch vụ/cuối hàm và chữ UTF-16 với chính thân native.
