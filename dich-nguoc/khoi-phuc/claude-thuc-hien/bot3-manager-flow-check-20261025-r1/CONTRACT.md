# Kiểm cả vòng quản lý vị thế bằng câu trả lời được cấp

Tệp MQL5 đích Scripts/bot-cua-toi-3/Bot3PositionManagementFlowCheck.mq5.
Chạy Bot3ManagePositions từ Bot3PositionManagement.mqh, không viết lại thuậttoán.
Các dịch vụ/hàm con ở dưới được cấp trả lời. Không gửi lệnh.

## Input
input string CheckRun; thưmục Files bot3-position-management-flow\\CheckRun\\.
CheckRun1..50 kýtựa-z,0-9,-;khôngghiđè. cases.binđầu3int32:
magic0x4d504d33,version1,count1..10000. Mỗica84byte `<20iI`:
id,buy,profile,position_count,mode,flip_digit,flip_mode,eligible_initial,
eligible_after_total,tick_ok,modify_ok,close_ok,delay_pass,digits,index,enabled,
magic,error_code,counter,ticket_kind;uint32error_count.
Kiểmid0..count-1,buy0/1,profile0..22,countpositions0..3,mode/flip_mode-1..3,
flip_digit0..30,eligbytes0..255,tick/modify/close/delaybool0/1,index0..8,ticket_kind0/1.
Cácintcòn lại giữnguyên. Dữliệucốđịnhsauđâylàinputfixture,khôngkếtquảmongđợi.

## Khởi tạo mỗi ca
ZeroMemorysettings/shared/requests/options. KHÔNGghiđè settings/shared tronglúcchạybằngbảnsaocục bộ.
settings.symbol="CHECK",magic/enableddùnginput;unit1,stop_distance10,take_distance20,
emergency_offset.5,gap.2,freeze2.5;finish.mode=mode;high_low_eligible=eligible_initial;
finish.high_low_buy_shift=finish.high_low_sell_shift=10.0;
timed_delay_seconds60,virtual_delay_seconds7;anchor_limit1,use_anchor0;
mọicờ/khoảngdờikhác0,sốmin_steps2. levels[9]=buy?95.0:105.0,tấtcả9ôcùnggiá;
shared.volumes[i]=.1+i*.01;strategy_index=inputindex,error_count/countertừinput;
current_stop333,current_take444,anchor.step_reference7.5,last_ticket123456,
tick.bid=-100,tick.ask=-101,cácthuộctínhtickkhác0;deviation=0x0123456789abcdef.
shared.table.guard1;mọihàngstop/take0. shared.anchor.rows100×2mọiô0.
Open_ticketsrỗng,khôngtựgọihelperdọnbảngởkhởitạo.

Danh sách vịthếsốngđầuvàocóposition_countrow:
ticket_kind0:ticket7+i;ticket_kind1:arrayulong[9007199254740993,9223372036854775807,18446744073709551615].
typebuy?0:1,magicinputmagic,opened1000,slbuy90/sell110,tpbuy130/sell70,
open100,volume.1,comment="note",symbol="CHECK".
GiátrảlờiTickbidbuy105/sell95,askbuy106/sell96. Đâyđộc lập tickbanđầu-100/-101.
stopreplybuy95/sell105;takereplybuy120/sell80. Thời gianTimeCurrent1061.
Với mỗivịthếđầuvào,table.rows[i]={normalized_ticket_double,stopreply,0},
take_rows[i]={normalized_ticket_double,takereply}; normalized=(double)(long)(double)(long)ticket,
giữđổiulong→long→double→long→double. Chỉghi khi ticketbanđầukhác0. Ápdụngsauprofilethayticketnếucó.

Profilethayđầuvào(cácmụcchưanêuvẫnmặcđịnh):
0 mặcđịnh;
1 row0ticket0;
2 row0type=buy?1:0;
3 row0magic=inputmagic+1 (int64);
4 row0symbol="OTHER";
5 settings.enabled0;
6 tấtcảrowSL=TP=0;
7/8 bật candle_enabled[0]=1,frame0=15,shift1;groupkhác0. Khácbiệt7khôngxóavịthếkhiClose,
8cóxóanếuc.close_ok1;
9 emergency_offset0,stop_distance.1;tickreplybuybid95/ask96,sellbid104/ask105;
10 stopreplybuy106/sell95 (khôngđổirowSL); cậpnhậtbảngstopkhởitạotheoreplymới;
11 mọiro wSLbuy106/sell95;
12 stopreply=buy?bidreply:askreply; cậpnhậtbảngstoptheoreplymới;
13 takereply=buy?bidreply:askreply; cậpnhậttake_rows;
14 timed_activation1,timed_distance2;
15 trail2,trail_step.5,trail_start1,trail_limit4;
16 take_trail_distance2,take_trail_start-12;
17 slippage_enabled1,slippage_trail2,slippage_start-12,slippage_limit4,anchor_limit-1;
18 finish.high_low_enabled1,high_low_gap_count1,before_open0,high_low_shift0;
19 finish.lock_start2,finish.lock_extra1;
20 finish.step_enabled1,finish.step_distance1,finish.min_steps2,finish.step_reference0;
21 đồngthờicácsettingstừ14..20 (anchor_limit-1,khôngđổigiá/cơsởkhác);
22 như15vàminimumreply0 (profilekhácminimumreply.01).
Profile11chỉthaySL,khôngđổiStopLevelreply. Profile10/12khôngđổiSLvịthế.

## Nhật ký và API giả
Sựkiện5uint64,bămFNV1a64từngbyteLE,đếm sốsựkiện;seedcbf29ce484222325,prime100000001b3.
textHashFNVUTF16LE. ĐịnhnghĩacácSDKgiảTRƯỚCnạpheadersđểPreludeđọcthậtfixture.
Chỉlỗihợplệ giữfaultđầutiên;khôngxóafaultgiữavòng.
- PositionsTotal: (17,live_count,total_call_index,0,0),tăngindex;SAUlầngọiđầu
  settings.high_low_eligible=eligible_after_total. Trảlive_count hiệnthời. KhôngtựgọiAPIkhác.
- PositionGetTicket(index): (2,index,0,ticket,0); indexhợplệchọnrow,trảticket,khônghợplệtrả0vàselected=-1.
- PositionGetDouble(prop):giữmapSL6,TP7,OPEN4,VOLUME3; (3,prop,0,bits(value),0).
  selectedkhônghợplệgiátrị0,khôngfault.
- PositionGetInteger:TIME1,TYPE2,MAGIC12;(4,prop,0,(ulong)longvalue,0),noselection0.
- PositionGetString:COMMENT11,SYMBOL0;(5,prop,textHash(text),text==NULL,0),noselectionNULL.
- SymbolInfoInteger(symbol,DIGITS17): (1,17,textHash(symbol),(ulong)(long)digits,symbol==NULL).
  Tăngdigit_counttoànca,SAUghisựkiệnnếuflip_digit>0vàdigit_count==flip_digit:
  settings.finish.mode=flip_mode đúngmộtlần. Trảdigitsinput.
- SymbolInfoDouble:POINT16=.01;VOLUME_MIN34=profile22?0:.01;
  (18,prop,bits(value),0,0). Symbolcầnbằng"CHECK".
- SymbolInfoTick: (6,textHash(symbol),tick_ok,bits(bidreply),bits(askreply));
  truechỉghi2ôbid/ask,tickfieldskhácgiữnguyên;falsekhôngghi.Trảtick_ok.
- TimeCurrent: (19,1061,0,0,0),trảdatetime1061.
- iTime: shift1trả900,shift0trả1100; (10,timeframe,shift,(ulong)value,textHash(symbol)).
- iClose:buy90,sell110,mọilần; (11,tf,shift,bits(value),textHash(symbol)).
- iOpen:buy95,sell105;(12,tf,shift,bits(value),textHash(symbol)).
- Print:nhận1string,(7,textHash(text),0,0,0). ChạythânhelperbáolỗithậtnêncầnGetLastErrorgiả.
- GetLastError:trảerror_codeinput,khôngghisựkiện/đếmtăngthêm.
- Bot3ModifyPosition: (8,ticket,bits(sl),bits(tp),modify_ok),trảmodify_ok;
  khôngđổidanh sáchvịthế/last_ticket/tick/setting.Khônggửilệnh.
- Bot3TryClosePosition: (9,ticket,close_ok,0,0). Ghichínhvéđượctruyền.
  Kiểmđốisốdeviationvàbid/ask/gap/freezecóbitgiốngthamchiếushared.tick/settingsđượcgiao.
  Nếuclose_ok1vàprofile!=7: tìmrowticketbằngvéulong, xóarowKHỚPĐẦUTIÊN, dồncácrowsau
  sangtrái,live_count--,selected=-1. Profile7khôngxóadùclose_oktrue. Trảclose_ok.
- Bot3VirtualStopLevel: (20,side,bits(price),bits(distance),(ulong)ticket),trảstopreply.
  Đúnggiaodiện(table,open_tickets,symbol,unit,side,price,distance,longticket);
  KHÔNGđổi tables,open_tickets hoặcquaylạigọiPositionsTotal. Đây làcâutrảlờiđượccấp.
- Bot3VirtualTakeLevel: (21,(ulong)ticket,bits(tp),0,0),trảtakereply;khôngghi bảng.
- Bot3VirtualStopDelayPassed: (22,(ulong)ticket,(ulong)(long)seconds,delay_pass,0),trảdelay_pass.
- Bot3VirtualStopStamp: (23,(ulong)ticket,0,0,0),khôngđổibảng.

Headers/Macros thứtựđềnghị đểkhôngđổi tênDEFINITIONcủahelperscũngkhôngbỏmockPrelude:
SDKfakesbuiltintypes+prototypevoid AfterFirstTotal(); rồi macroSDK(SymbolInfo/PositionGet/PositionsTotal,
iTime/iClose/iOpen/TimeCurrent/GetLastError)TRƯỚCincludePositionModify,PositionClose,VirtualStops.
ChưađặtPrintmacroở3headersnàyvìcóPrintnhiềuđốisốkhôngdùngtrongphépkiểm.
Chúngcungcấptypesvàđịnhnghĩahelpersđượcchặn,nhưngkhôngnạpPrelude.
SauđóđịnhnghĩacáchàmModify/Close/Virtual4giảvớitypesđãcó,đặtmacrochéntên,
đặtPrintmacro1string,rồiincludeBot3PositionManagement.mqh. Preludeđượcnạplầnđầuởđây
vớicácSDKfakes. VirtualStops đãguardnênkhôngtrùngđịnhnghĩafakeStopLevel.
Cácglobalsettings/sharedđịnhnghĩasauinclude(vìtypesnàymớicó);SDKfakemàcầnchạmsettings
gọiAfterFirstTotal()prototypevàđịnhnghĩanósauglobal. Tươngtựwrappercallbackkiểmbid/gap.
KhôngđổiSourceHeaderđểphục vụbộkiểm.KhôngmockTradeErrorTextvàkhôngviếtlạithuậttoánmanager.

## Đầu ra
mql5-results.binđầucùngmagic/version/count. Mỗica120byte `<7iIIQ5di4Q`:
7int32id,returned,final_counter,final_mode,live_count,final_eligible,final_guard;
2uint32final_strategy_index,error_count;uint64last_ticket;
5doublecurrent_stop,current_take,tick.bid,tick.ask,anchor.step_reference;
int32event_count;4uint64ordered_hash,cache_hash,table_hash,positions_hash.
cache_hashtrên200doublecủaanchor.rows100×2;table_hashtrên1500doublestop500×3rồimới1000doubletake500×2;
positions_hashtrêncácvéulongsốngtheothứtự,trốngthìseed. Mọiwordbăm8byteLE.
script-status.bin2int32fault,count.Kiểmđọchết/size84*count+12,khôngghiđè.

Thêm `cast-values.bin` đểcấpđịnhdạngsốthựccủaMT5:
headercùngmagic/version/count; mỗicaint32id,int32n, rồinentry:
uint64doublebits,int32UTF16codeunits,chuỗiUTF16LEkhôngkếtthúc0.
Mỗi giá trịdoublechỉ1entry,thứtựdanh sáchsau,lọctrùngbit:
0,333,444,-100,-101,.01,.2,.5,1,2,4,7.5,10,20,90,91,93,95,96,98,99,100,101,103,104,105,106,107,109,110,120,130.
text=(string)value đượcđotrongMT5,khônglấyStringtừkếtquảmanager/khôngtựtínhcôngthức.
Ghicácfixturetrướckhichạycase,khôngghisựkiện/đổicounterchochúng.
Đâychỉlàfixtuređịnhdạngsố,khônglàexpectedchoviệcmua/bán/đổiSL/đóng.
