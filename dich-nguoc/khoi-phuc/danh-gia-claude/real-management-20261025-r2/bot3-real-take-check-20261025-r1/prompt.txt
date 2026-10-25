Viết duy nhất Bot3ManagementRealTakeCheck.mq5 và SUMMARY.md trong thư mục hiện tại này. Không sửa nguồn chính, không chạy lệnh hoặc tác tử khác. Opus5.5 max; Ultracode được yêu cầu. Chỉ nhận mô tả chức năng và giao diện dưới đây. Codex sẽ kiểm/ghép/chạy. Không khẳng định đã chạy.

Mục tiêu: chương trình MQL5 chạy các hàm tính mức chốt lời với câu trả lời API được cấp, ghi đầy đủ kết quả và thứ tự lời gọi. Mẫu nhập/xuất, kiểm đường dẫn, bit double và hàm băm có thể tham khảo source/MQL5/Scripts/bot-cua-toi-3/Bot3ManagementRealTimedCheck.mq5 của bot3 hiện tại. Không đọc tài liệu phân tích lịch sử.
Nguồn cuối sẽ ở Scripts/bot-cua-toi-3; include ../../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh và Bot3ManagementMessages.mqh TRƯỚC macros, rồi định nghĩa macros và include Bot3ManagementRealTake.mqh. Header đó sẽ có hai hàm Bot3AdvanceRealTakeBuy/Sell, cùng giao diện:
bool FUNCTION(const string &symbol,const double &unit,const double &distance,const double &start,const double anchor,const double &gap,const double &freeze,Bot3ManagedPosition &position,MqlTick &tick,const double &volumes[],const uint &strategy_index,bool &changed,Bot3PendingRequestState &state,Bot3TradeSendOptions &options,const ulong &deviation,uint &error_count,const ulong ticket).

CheckRun hợp lệ 1..50 chữ a-z,0-9,-; thư mục bot3-management-real-take\\CheckRun\\. Không ghi đè kết quả có sẵn. Đầu cases.bin 3int32: magic0x4d525033,version1,count1..100000. Mỗi ca 244byte theo thứ tự, không đệm:
8int32 id,buy,scenario,modify_ok,error_code,digits0,digits1,digits2;
int64 ticket;uint64 deviation;3uint32 strategy_index,error_count,prior_changed;
23double sl,tp,open_price,volume,bid,ask,unit,distance,start,anchor,gap,freeze,point,minimum,volumes[0]..volumes[8].
Kiểm kích thước 12+count*244, id thứ tự, buy0/1,scenario0..8,index0..8,prior_changed0/1. Lỗi ghi trạng thái khác0, không gọi hàm với dữ liệu sai.

Mọi ca reset số lần gọi/băm/digitindex, trạng thái và options rỗng. position.sl/tp/open_price/volume từ ca, tick.bid/ask từ ca. unit,distance,start,gap,freeze,index,deviation,volumes và tick là biến toàn cục được truyền tham chiếu. anchor,point,minimum là giá trị của ca không thay đổi. error_count biến local truyền ref; changed=(prior_changed!=0).
Sau MỖI sự kiện sau đây, gọi Mutate(target); nếu scenario==target thì unit*=2;distance+=.5;start+=.25;gap+=.125;freeze+=.25;tick.bid+=.25;tick.ask+=.5;index=(index+1)%9;deviation++ (ulong wrap). KHÔNG đổi volumes,point,minimum,anchor,position hoặc error_count trong Mutate. Các targets: DIGITS1=1,POINT=2,DIGITS2=3,DIGITS3=4,Modify=5,VOLUME_MIN=6,Report=7,TryClose=8.
API cung cấp:
SymbolInfoInteger CHECK,SYMBOL_DIGITS tối đa3 lần: ghi sự kiện(3,17,(ulong)(long)digit,digitindex,0), tăngdigitindex rồi Mutate(target theo lần), trả digit (long).
SymbolInfoDouble CHECK,SYMBOL_POINT: sự kiện(4,16,bits(point),0,0),Mutate2,trả point. SYMBOL_VOLUME_MIN: sự kiện(4,34,bits(minimum),0,0),Mutate6,trả minimum. Giá trị property khác/symbol khác là lỗi.
Bot3ModifyPosition: ghi(5,ticket,bits(sl),bits(tp),modify_ok),Mutate5,trảmodify_ok!=0. Không gửi lệnh.
Bot3PrintManagementError: kiểm suffix đúng "' when setting trailing Exit_TP.  Trying again!"; ghi(10,(ulong)(long)error_code,error_count,textHash(suffix),0);error_count++ uint wrap;Mutate7. Chỉ ghi lời gọi, không kiểm hàm tạo chuỗi thật ở đây.
Bot3TryClosePosition có giao diện từ Prelude: ghi hai sự kiện (6,ticket,deviation,bits(bid),bits(ask)), (7,bits(gap),bits(freeze),0,0). Mutate8 rồi trả true (kết quả con không được hai hàm gọi dùng). Không làm mới giá, không gửi lệnh. Kiểm state/options là các tham chiếu đã cấp nếu thuận tiện; không đổi chúng.
Sự kiện gồm5uint64, băm FNV1a64 từng byte little endian; số lần gọi là số sự kiện (TryClose2sự kiện), ban đầu0xcbf29ce484222325, nhân0x100000001b3. textHash UTF16LE cùng thuật toán.
Macros chỉ thay SymbolInfoInteger/Double,Bot3ModifyPosition,Bot3PrintManagementError,Bot3TryClosePosition quanh include header cần kiểm. Đọc đúng giao diện từ Prelude nếu cần, không thay lời gọi khác.

Kết quả đầu cùng magic/version/count. Mỗi kết quả224byte:
3int32 id,returned,changed;2uint32 final_index,error_count;uint64 final_deviation;
23double cùng thứ tự/sl,tp,open_price,volume,bid,ask,unit,distance,start,anchor,gap,freeze,point,minimum,9volumes;
int32 event_count;uint64 ordered_hash.
Cuối script-status.bin ghi2int32 fault,count. Kiểm đã đọc hết, không FileWriteString hoặc làm tròn bất cứ đầu ra nào; giữ bit NaN/âm0. Chỉ chạy hai hàm với dữ liệu ca, không dùng thời gian/tài khoản/giao dịch thật.
