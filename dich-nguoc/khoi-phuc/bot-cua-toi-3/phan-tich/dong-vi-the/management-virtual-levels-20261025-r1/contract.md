# Bot 3: mức dừng/chốt ảo — mô tả trước khi viết, 20261025-r1

Dự án khôi phục nguồn bot The Gold Reaper MT5 thuộc chủ dự án.
EX5 SHA-256 ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83.
Đầu mã 0x17156250000. Codex đã đọc analysis.json/native của hai hàm
0x32f60/0x37590 trong ../management-20261025-r1. Không sửa EX5/khóa/MT5 chính.
Chỉ hai đoạn dưới đây, chưa phải toàn hàm quản lý hoặc EA.

Các trường position là các giá trị cục bộ đã đọc trước đó, không bị API
bên ngoài sửa trong mô hình này. Các biến chung current_stop/current_take,
tick, unit và cài đặt truyền qua tham chiếu. ticket là long đã được đổi từ
ticket_number ở phần mốc trước đó, không đọc lại vé chung trong đoạn này.
Không thêm luật hoặc sửa hành vi lạ. Giữ thứ tự cộng/trừ và đọc trước/sau API.
Dùng Bot3RoundPrice đã có, không dùng NormalizeDouble.

## A. Bắt đầu nhánh ảo

Ranh giới mua 0x35d65..0x35f8f; bán 0x39ff5..0x3a21a.
Mức dừng hiện tại P: double 0x6d670; mức chốt hiện tại: double 0x724a0.
unit: double 0x73dd8; stop_distance: double 0x6d588;
delay_seconds của hàm chờ: int32 0x6d518 (khác giờ chờ dời dừng 0x7449c).
Mua/bán dùng bid 0x74798 / ask 0x747a0.
initial_stop là xmm10, initial_take là xmm9. ticket ở stack mua+40/bán+48.
Các đích đóng là 0x36fd4/0x3b1c7: gọi SymbolInfoTick rồi helper kiểm đóng
0x47d20, không in thông báo và không gọi đóng trực tiếp 0x2e370.

Viết Bot3StartVirtualManagement, bool, đúng thứ tự tham số:
const bool buy,const string &symbol,const double &unit,
const double &stop_distance,const int &delay_seconds,const long ticket,
Bot3ManagedPosition &position,MqlTick &tick,
Bot3VirtualStopState &table,long &open_tickets[],
double &initial_stop,double &initial_take,double &current_stop,double &current_take,
Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
const ulong &deviation,const double &threshold_a,const double &threshold_b.

1. initial_stop=Bot3VirtualStopLevel(table,open_tickets,symbol,unit,
   buy?1:2,position.open_price,stop_distance,ticket).
   Ghi current_stop=initial_stop TRƯỚC lời gọi lấy chốt.
2. initial_take=Bot3VirtualTakeLevel(table,open_tickets,position.tp,ticket).
   Ghi current_take=initial_take.
3. Nếu mua: current_stop>=tick.bid có thứ tự, HOẶC
   0.0<initial_take và tick.bid>=initial_take có thứ tự.
   Bán: tick.ask>=current_stop có thứ tự, HOẶC
   0.0<initial_take và initial_take>=tick.ask có thứ tự.
   Nếu chạm: gọi SymbolInfoTick(symbol,tick), bỏ bool trả;
   gọi Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,
   threshold_a,threshold_b,(ulong)ticket), trả true.
   NaN không làm điều kiện chạm đúng. Dùng initial_take trong điều kiện này.
4. Nếu không chạm: gọi Bot3VirtualStopDelayPassed(table,delay_seconds,ticket).
   Nếu false, trả false.
5. Hỏi digits SymbolInfoInteger(symbol,SYMBOL_DIGITS), rồi đọc current_stop
   và RoundPrice thành candidate. Gọi SymbolInfoDouble(symbol,SYMBOL_POINT).
   Mua: chỉ tiếp nếu position.sl+point<candidate.
   Bán: chỉ tiếp nếu candidate<position.sl-point.
6. Nếu đạt, hỏi digits lần nữa, đọc LẠI current_stop, RoundPrice,
   gán position.sl bằng giá này; gọi Bot3ModifyPosition(state,options,
   (ulong)ticket,position.sl,position.tp). Bỏ bool trả.
   Gọi Bot3VirtualStopStamp(table,ticket) dù Modify trả false.
7. Trả false (false nghĩa không đi đường đóng của đoạn này).
Không tự sửa position.tp, không reset cờ changed ở đây; cờ đó thuộc bên gọi.
position.sl ở giao diện là giá lần cuối yêu cầu sửa; XMM8 gốc là thanh ghi
tạm sau phép cộng/trừ point, không dùng XMM8 làm giá SL đầu ra tại ranh giới.

## B. Cập nhật chốt ảo

Mua 0x36189..0x364e2; bán 0x3a4af..0x3a803.
distance=double 0x6d378, start_distance=double 0x6d380,
current_take=double 0x724a0, unit=double 0x73dd8.
anchor là double cục bộ stack mua+78/bán+88, đã chốt trước đoạn này.
volumes=double[] 0x73ac0; strategy_index=uint32 0x74934.
threshold_a=0x73ab0; threshold_b=0x744a8. Helper kiểm đóng là 0x47d20.
Đoạn này ghi current_take, KHÔNG ghi mức chốt thật position.tp.

Viết Bot3AdvanceVirtualTake, bool, tham số:
const bool buy,const string &symbol,const double &unit,
const double &distance,const double &start_distance,const double anchor,
const Bot3ManagedPosition &position,MqlTick &tick,
const double &volumes[],const uint &strategy_index,
double &current_take,bool &changed,
Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
const ulong &deviation,const double &threshold_a,const double &threshold_b,
const ulong ticket.

1. Chỉ tiếp khi 0.0<distance rồi 0.0<current_take. So có thứ tự.
2. Chụp quote=tick.ask nếu mua, tick.bid nếu bán TRƯỚC hỏi digits thứ nhất.
   Sau digits, chụp take=current_take TRƯỚC hỏi point.
   Gọi SymbolInfoDouble(symbol,SYMBOL_POINT).
   Sau point mới đọc distance và unit để tính gate:
   mua gate=RoundPrice((take-point)-distance*unit,digits1);
   bán gate=RoundPrice(distance*unit+(take+point),digits1).
   Mua yêu cầu quote<gate; bán gate<quote; không đạt trả false.
3. Chụp quote2 (ask mua/bid bán) TRƯỚC digits thứ hai.
   Sau digits tính boundary và làm tròn:
   mua RoundPrice(anchor-start_distance*unit,digits2), yêu cầu quote2<boundary;
   bán RoundPrice(start_distance*unit+anchor,digits2), yêu cầu boundary<quote2.
4. Hỏi digits thứ ba, sau đó đọc lại cài đặt/unit/tick để tính:
   mua current_take=RoundPrice(distance*unit+tick.bid,digits3);
   bán current_take=RoundPrice(tick.bid-distance*unit,digits3).
   Bản gốc dùng BID cho giá chốt mới ở cả hai phía; không đổi sang ask.
5. volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2), rồi changed=true.
   Nếu volume<position.volume thì gọi SYMBOL_VOLUME_MIN.
   Nếu minimum<=volume, gọi Bot3TryClosePosition(state,options,deviation,
   tick.bid,tick.ask,threshold_a,threshold_b,ticket), rồi trả true.
   Mọi trường hợp khác trả false; giữ current_take/changed đã cập nhật.
6. Không Modify, không Stamp hoặc Print, không thêm điều kiện TP/SL khác,
   không sửa tham số/giới hạn chỉ số mảng. Chỉ số hợp lệ là tiền đề bộ so đoạn.
Mọi phép so dương là có thứ tự; NaN làm điều kiện dương sai.

## Còn phải kiểm

Cả hai đoạn cần biên dịch và đối chiếu native với MQL5 trên dữ liệu cố định,
biên ngưỡng, NaN/vô cực, nguồn thay đổi sau từng API, helper trả false,
thứ tự/đối số/ảnh hưởng. Chưa có phép so đạt cho các đoạn mới.
Hàm con từng được kiểm riêng không thay cho phép ghép các hàm này.
