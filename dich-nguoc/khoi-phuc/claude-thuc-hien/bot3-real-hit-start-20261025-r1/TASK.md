Viết duy nhất Bot3ManagementRealStart.mqh và SUMMARY.md trong thư mục này. Mục tiêu hai hàm MQL5 chốt ở dưới. Chỉtheomôtả,khôngphântíchlịchsử/tựtìmthuậttoán. Khôngsửanguồnchính/Git/lệnh/táctửkhác. Codexkiểm/ghép/chạy. Opus5.5max,Ultracodeyêucầu;khôngclaimđãbiêndịch/chạy.
IncludeBot3ManagementPrelude.mqh vàBot3VirtualStops.mqh. Cáclevel/tick/unit/settings làthamchiếucóthểđổisauAPI;ticketlonglàcốđịnh. Khôngtrùngvùngnhớ.
1 bool Bot3CloseRealStopHit(const bool buy,const string &symbol,const double &current_stop,MqlTick &tick,Bot3PendingRequestState &state,Bot3TradeSendOptions &options,const ulong &deviation,const double &gap,const double &freeze,const long ticket):
- Luôn in ba dòng theo thứtự: Print("Closing with virtual SL"); Print("Virtual_SL: "+(string)current_stop); Print("Last Bid: "+(string)(buy ? tick.bid : tick.ask));
- GiữnhãnLastBidởSELLdùgiátruyềnlàASK. Đọccurrent_stopSAUPrint1;đọcquoteSAUPrint2,khôngchụpcảhaingayđầu. Giữcast(string)double,khôngDoubleToString/NormalizeDouble,tựthêmdigits hoặcđổinhãn.
- SauPrint3 SymbolInfoTick(symbol,tick) bỏquakếtquả; Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket). Bỏquakếtquảcon,trảtrue. Khôngđọclạivịthế/khốilượng/ghiP/SL/cờ/bảngngoàiviệchelperconđãlàm.
2 bool Bot3StartRealManagement(const bool buy,const string &symbol,const double &unit,const double &stop_distance,const long ticket,Bot3ManagedPosition &position,MqlTick &tick,Bot3VirtualStopState &table,long &open_tickets[],double &initial_stop,double &current_stop,Bot3PendingRequestState &state,Bot3TradeSendOptions &options,const ulong &deviation,const double &gap,const double &freeze):
- level=Bot3VirtualStopLevel(table,open_tickets,symbol,unit,buy?1:2,position.open_price,stop_distance,ticket). Mặc dùtênReal,hàmconVirtualStopLevelđượcgọiđúngmôtả.
- current_stop=levelngay. SELLinitial_stop=leveltrướckiểmhit;BUYchỉgáninitial_stopSAUkhi khônghit.
- HitBUYtick.bid<level;SELLlevel<tick.ask;soNGHIÊMNGẶT<,không>=/<=. NaNkhônghit.
- Nếuhit:returnBot3CloseRealStopHit(buy,symbol,current_stop,tick,state,options,deviation,gap,freeze,ticket). BUYkhônggáninitial_stoptrướcreturnhit;SELLđãgán.
- Khônghit:BUYgáninitial_stop=level;trảfalse. KhônghỏiDigits,TakeLevel,Delay,Stamp,Modify,PositionsTotalhayPositionGetDoubleởhàmnày.
Khôngtựthêmluật,chữkýđủ/thứtựđúng.Mãgọnrõràng,SUMMARYđọchiệuứng/thứtự/chưachạy. Đượcđọchaiheadersđểđúnggiao diện.
