# Chương trình cấp dữ liệu kiểm sáu khối quản lý MQL5

Chỉ tính toán/ghi lời gọi, không gửi lệnh. Đích là
Scripts/bot-cua-toi-3/Bot3ManagementRealBlocksCheck.mq5, input string CheckRun.
Thư mục Files `bot3-management-real-blocks\\CheckRun\\`, quy tắc CheckRun
1..50 ký tự a-z,0-9,-. Không ghi đè. Mẫu nhị phân/file/hash có thể đọc
Bot3ManagementRealTakeCheck.mq5 ở nguồn hiện hành, nhưng giao diện dưới đây khác.

Ca đầu3int32 magic0x4d524233,version1,count1..100000. Mỗi ca456byte:
22int32: id,buy,stage,scenario,modify_ok,error_code,digits0,digits1,digits2,digits3,
enabled,gap_count,minimum_steps,counter,passed_flag,eligible_flag,before_open,
shift_setting,step_enabled,guard,prior_changed,table_pattern;
int64ticket;uint64deviation;2uint32 index,error_count;
25double sl,tp,open_price,volume,bid,ask,unit,trail,step,start,limit,reference,
anchor,gap,freeze,point,minimum,lock_start,lock_extra,step_reference,
step_distance,copied_step,initial_stop,ticket_number,current_stop;
9doublevolumes,9doublelevels.
PythonStruct `<22iqQII43d`. Kiểm idthứtự,buy0/1,stage0..5,scenario0..11,
index0..8,flagbytes0..255,prior_changed0/1,table_pattern0..5,modify_ok0/1;
cácintkhácgiữđúngsignedint32. Đọchếtca rồi mớiquyếtđịnhgọihàm.

Các biến càiđặt vàcấugiá/intcounter/index/deviation là biến toàncục choAPI
giảthayđổiquathamchiếu. position.sl/tp/open_price/volume lấytừca,cục bộ.
counterint32 localhoặcglobalđềuđượcnhưngphảicùngbiếnMutatecóthểghi.
initial_stop,ticket_number,reference,anchor,point,minimum cốđịnhkhôngmutate.
Khởi tạo state/options rỗng,table.guard=(uchar)guard. Đủ500 hàng stop:
rows[i]={10000.0+i,20000.0+i,-30000.0-i}; take_rows[i]={40000.0+i,-50000.0-i}.
Pattern0thìrows[0][0]=ticket_number;1hàng250;2hàng499;3cảhàng1,17,499;
4khôngkhớp;5hàng0[0]=NaNbits7ff8000000000011,hàng499[0]=ticket_number.
Khôngđổiôkhác. Bămtoànbộ2500double cuối ca FNV1a64littleendian thứtựstoprow0..499
3ô,hếtmớitakerow0..4992ô. Sốbanđầu0xcbf29ce484222325,nhân0x100000001b3.

## Lời gọi và dữ liệu thay sau API

APIghi5uint64 mỗi sự kiện. FNV1a64từngbyteLE,đếm số sự kiện. textHashUTF16LE.
CácAPIgiảsaukhighixongsựkiện mớigọiMutate(target):
- DIGITSlần0..3: (3,17,(ulong)(long)digit,digit_index,0),rồităngindex,trảdigit;
  targetslần0=1,lần1=3,lần2=4,lần3=5. Tốiđa4,SymbolCHECK.
- POINTlần0/1: (4,16,bits(point),point_index,0),rồităngindex,trảpoint;
  targetlần0=2,lần1=6. Tốiđa2.
- VOLUME_MIN: (4,34,bits(minimum),0,0),target10,trảminimum.
- Modify(state,options,ticket,sl,tp): (5,ticket,bits(sl),bits(tp),modify_ok),target7;
  trảmodify_ok!=0. Khônggửilệnh.
- GetLastErrorgiảchỉtrảerror_code củaca,khôngghisựkiện/đổi/đếmlỗi.
- Printgiảnhận1string: (13,textHash(text),error_count hiệnthời,0,0),target8nếulà
  thôngbáolỗi(textbắtđầuTrailStop/error/errorwhen),target9nếukhác. GiữPrintnội dung
  thậtđượctạobởihàmnguồn;KHÔNGthayBot3TradeErrorText hoặcbahelperbáolỗi.
- TryClose:2sựkiện(6,ticket,deviation,bits(bid),bits(ask)),(7,bits(gap),bits(freeze),0,0),
  target11,trảtrue,khônglàmmớigiá/đóngthật. Ghichínhđốisốnhậnđượccủahàm.

Mutatechỉkhi scenario==target:
unit*=2;trail+=.5;step+=.125;start+=.25;limit+=.75;gap+=.125;freeze+=.25;
lock_start+=.5;lock_extra+=.25;step_distance+=.25;copied_step+=.125;
tick.bid+=.25;tick.ask+=.5;index=(index+1)%9;levels[index]+=1.25;deviation++ulongwrap;
counter=(int)((uint)counter+1);current_stop+=1.25;table.guard=(uchar)(((int)table.guard+1)%3).
KHÔNGđổi position,reference/anchor/step_reference/initial_stop/ticket_number,
volumes,point/minimum,enabled/gap_count/minimum_steps/flags,error_count trongMutate.
NaNđượccộngtheophépMQLbìnhthường,khôngtựchuẩnhoáhaykiểmlọcthêm.

## Các hàm cần gọi

IncludePrelude,VirtualStops,VirtualFinish(trongđókhôngcóReport)trướcMacros.
SauđóđịnhnghĩaSymbolInfoInteger/Double,GetLastError,Print,Modify,TryClose macros;
includeManagementMessagesvàtấtcảheadersdướitrongmacrosrồibỏmacros.
TradeErrorTextphảilàthânnguồncósẵn: counter++vàthôngbáođúngmãlỗi. Cầnđọcgiao diện
Messages/TradeErrorsđểkhôngnạpMessagestrướcmacroGetLastError/Print. Cácsourcechưađủ
sẽđượcCodexđặtcạnhheaderschínhtrướckhibiêndịch;khôngtựtạohàmgiảthayphầnnày.

stage0distance: headerBot3ManagementRealDistance.mqh;
returned=Bot3AdvanceDistanceBuyStop hoặcSellStop(symbol,unit,trail,step,start,limit,
anchor,gap,freeze,position,tick,volumes,index,changed,state,options,deviation,error_count,ticket).
stage1slippage: headerBot3ManagementRealSlippage.mqh;void
Bot3AdvanceSlippageRealBuyStop/SellStop(symbol,unit,enabled,(uchar)passed_flag,reference,
trail,start,limit,gap,freeze,position,tick,changed,state,options,error_count,ticket).
stage2HL: headerBot3ManagementRealHighLow.mqh;void
Bot3AdvanceHighLowRealBuyStop/SellStop(symbol,enabled,(uchar)eligible_flag,gap_count,unit,
before_openucharref,shift_settingucharref,gap,freeze,levels,index,position,tick,changed,
state,options,error_count,ticket).
stage3lock: headerBot3ManagementRealLock.mqh;void
Bot3AdvanceRealLockBuyStop/SellStop(symbol,lock_start,lock_extra,unit,gap,freeze,
position,tick,changed,state,options,error_count,ticket).
stage4counter: headerBot3ManagementRealCounter.mqh;void
Bot3AdvanceRealCounterBuyStop/SellStop(symbol,step_enableducharref,step_reference,
minimum_steps,step_distance,unit,copied_step,anchor,gap,freeze,counter,position,tick,changed,
state,options,ticket).
stage5store: headerBot3ManagementRealStore.mqh;void
Bot3StoreRealStop(symbol,initial_stop,current_stop,ticket_number,table).
returned=false chotấtcảvoidstage,khôngsuytừchanged. Đầuvàoposition/tickvàcácmảng
vẫnghiđủđầurasaukhibấtkỳstageđãchạyđểpháthiệnghinhamô.

Kếtquả đầu3int32nhưinput. Mỗi ca400byte:
5int32id,returned,changed,counter,final_guard;
2uint32final_index,error_count;uint64final_deviation;
43doublecùngthứtự25double+9volume+9levelsvớigiátrịcuốicùng;
int32event_count;uint64ordered_hash;uint64table_hash.
PythonStruct `<5iIIQ43diQQ` hoặcđốichiếubit `<5iIIQ43QiQQ`.
GhiFileReadDouble/FileWriteDoublekhônglàmtròn/đổiNaN/âm0.
script-status.bin2int32fault,count; kiểmđọchết,vàFILEsize456*count+12.
Mãlỗi đơn giản,giữlỗiđầutiên,khôngđặtthành0mỗica,khôngghiđèkếtquảcósẵn.
TrướcPrintkếtthúcOnStartđãundefmacro,nênPrinttrạngtháikhônglọtvàobămcase.
