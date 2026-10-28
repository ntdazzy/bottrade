#property strict
input string CheckRun="";
int MockInfo(const ENUM_MQL_INFO_INTEGER property);
int MockBars(const string symbol,const ENUM_TIMEFRAMES period);
double MockAccountInfoDouble(const ENUM_ACCOUNT_INFO_DOUBLE property);
bool MockHistorySelect(const datetime from,const datetime to);
int MockHistoryDealsTotal();
ulong MockHistoryDealGetTicket(const int index);
long MockHistoryDealGetInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property);
double MockHistoryDealGetDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property);
datetime MockITime(const string symbol,const ENUM_TIMEFRAMES period,const int shift);
datetime MockServer();datetime MockCurrent();datetime MockCurrent(MqlDateTime &dt);
bool MockStruct(const datetime value,MqlDateTime &dt);double MockMod(const double a,const double b);
datetime MockParse(const string value);string MockTimeText(const datetime value,const int flags=TIME_DATE|TIME_MINUTES);
string MockIntegerText(const long value,const int length=0,const ushort fill=' ');
bool MockConcat(string &target,const int year,const string suffix);void MockPrint(const string value);void MockPrint(const string a,const string b);
int MockEvents(const string currency,MqlCalendarEvent &events[]);int MockValues(const ulong id,MqlCalendarValue &values[],const datetime from,const datetime to=0);
int MockOrders();ulong MockOrderTicket(const int index);int MockPositions();ulong MockPositionTicket(const int index);
long MockOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property);string MockOrderString(const ENUM_ORDER_PROPERTY_STRING property);
double MockOrderDouble(const ENUM_ORDER_PROPERTY_DOUBLE property);bool MockOrderSelect(const ulong ticket);
bool MockSend(const MqlTradeRequest &request,MqlTradeResult &result);bool MockAsync(const MqlTradeRequest &request,MqlTradeResult &result);
long MockPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property);string MockPositionString(const ENUM_POSITION_PROPERTY_STRING property);
double MockPositionDouble(const ENUM_POSITION_PROPERTY_DOUBLE property);bool MockPositionSelect(const ulong ticket);
long MockSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property);bool MockSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value);
double MockSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property);bool MockTick(const string symbol,MqlTick &tick);bool MockStopped();
int MockCountry(const string country,MqlCalendarEvent &events[]);
#define MQLInfoInteger MockInfo
#define Bars MockBars
#define AccountInfoDouble MockAccountInfoDouble
#define HistorySelect MockHistorySelect
#define HistoryDealsTotal MockHistoryDealsTotal
#define HistoryDealGetTicket MockHistoryDealGetTicket
#define HistoryDealGetInteger MockHistoryDealGetInteger
#define HistoryDealGetDouble MockHistoryDealGetDouble
#define iTime MockITime
#define TimeTradeServer MockServer
#define TimeCurrent MockCurrent
#define TimeToStruct MockStruct
#define MathMod MockMod
#define StringToTime MockParse
#define TimeToString MockTimeText
#define IntegerToString MockIntegerText
#define StringConcatenate MockConcat
#define Print MockPrint
#define CalendarEventByCurrency MockEvents
#define CalendarEventByCountry MockCountry
#define CalendarValueHistoryByEvent MockValues
#define OrdersTotal MockOrders
#define OrderGetTicket MockOrderTicket
#define PositionsTotal MockPositions
#define PositionGetTicket MockPositionTicket
#define OrderGetInteger MockOrderInteger
#define OrderGetString MockOrderString
#define OrderGetDouble MockOrderDouble
#define OrderSelect MockOrderSelect
#define OrderSend MockSend
#define OrderSendAsync MockAsync
#define PositionGetInteger MockPositionInteger
#define PositionGetString MockPositionString
#define PositionGetDouble MockPositionDouble
#define PositionSelectByTicket MockPositionSelect
#define SymbolInfoInteger MockSymbolInteger
#define SymbolInfoDouble MockSymbolDouble
#define SymbolInfoTick MockTick
#define IsStopped MockStopped
#include "../../Include/bot-cua-toi-1/Bot1NewsFridayFlow.mqh"
#include "../../Include/bot-cua-toi-1/Bot1DailyLossGuard.mqh"
#undef MQLInfoInteger
#undef Bars
#undef AccountInfoDouble
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef HistoryDealGetInteger
#undef HistoryDealGetDouble
#undef iTime
#undef TimeTradeServer
#undef TimeCurrent
#undef TimeToStruct
#undef MathMod
#undef StringToTime
#undef TimeToString
#undef IntegerToString
#undef StringConcatenate
#undef Print
#undef CalendarEventByCurrency
#undef CalendarEventByCountry
#undef CalendarValueHistoryByEvent
#undef OrdersTotal
#undef OrderGetTicket
#undef PositionsTotal
#undef PositionGetTicket
#undef OrderGetInteger
#undef OrderGetString
#undef OrderGetDouble
#undef OrderSelect
#undef OrderSend
#undef OrderSendAsync
#undef PositionGetInteger
#undef PositionGetString
#undef PositionGetDouble
#undef PositionSelectByTicket
#undef SymbolInfoInteger
#undef SymbolInfoDouble
#undef SymbolInfoTick
#undef IsStopped
enum Parameter { p_enabled,p_use_calendar,p_throttle,p_delete_pending,p_close_positions,p_before_minutes,p_after_minutes,p_initialization_notice,p_notice,p_blocked,p_last_query,p_utc_reference,p_nfp,p_server,p_current,p_release,p_info,p_calendar_status,p_orders,p_position,p_async_mode,p_accepted,p_order_select };
long P[23],History[300];MqlDateTime Cached;
Bot1NfpFilterSettings Settings;Bot1NfpFilterState State;Bot1NewsEvents Events;Bot1NfpExecution Execution;
Bot1ReleaseFilterSettings InterestSettings,CpiSettings;Bot1ReleaseFilterState InterestState,CpiState;Bot1NewsSelection Selection;
long Extra[18],FridayData[12];Bot1FridaySettings Friday;uchar FridayClosed;
double Percent;Bot1DailyLossState Daily;
long HistorySelectReply,HistoryDealsTotalReply;long BarsReplies[256],EquityReplies[256],BalanceReplies[256],TimeReplies[256];
int BarsReplyCount,EquityReplyCount,BalanceReplyCount,TimeReplyCount;
int BarsReplyPos,EquityReplyPos,BalanceReplyPos,TimeReplyPos;
long DealTicket[256],DealTime[256],DealEntry[256],DealProfit[256],DealCommission[256],DealSwap[256];int DealCount,SelectedDeal;
long EffectApi[256],EffectN[256],EffectField[256],EffectValue[256];int EffectCount,ApiN[64];
bool Mutated=false,RecordFinal=false,NewsBlocked=false;int OrderTypeReads=0;
int TapeFile,EndErrorOverride=-1;union NumberBits { double value;ulong bits; };
ulong Bits(const double value) { NumberBits n;n.value=value;return n.bits; }
void Word(const ulong value) { FileWriteLong(TapeFile,(long)value); }
void Text(const string value)
{
   if(value==NULL) { FileWriteInteger(TapeFile,-1);return; }
   int n=StringLen(value);FileWriteInteger(TapeFile,n);if(n>0) FileWriteString(TapeFile,value,n);
}
void Snapshot()
{
   uint error=EndErrorOverride>=0 ? (uint)EndErrorOverride : GetLastError();
   Word(Settings.enabled);Word(Settings.use_calendar);Word(Settings.throttle);Word(Settings.delete_pending);Word(Settings.close_positions);
   Word((ulong)(long)Settings.before_minutes);Word((ulong)(long)Settings.after_minutes);
   Word(State.initialization_notice);Word(State.notice);Word(State.blocked);Word((ulong)State.last_query);Word((ulong)State.utc_reference);
   Word(InterestSettings.enabled);Word(InterestSettings.delete_pending);Word(InterestSettings.close_positions);Word((ulong)(long)InterestSettings.before_minutes);Word((ulong)(long)InterestSettings.after_minutes);Word(InterestState.notice);Word(InterestState.blocked);Word((ulong)InterestState.last_query);
   Word(CpiSettings.enabled);Word(CpiSettings.delete_pending);Word(CpiSettings.close_positions);Word((ulong)(long)CpiSettings.before_minutes);Word((ulong)(long)CpiSettings.after_minutes);Word(CpiState.notice);Word(CpiState.blocked);Word((ulong)CpiState.last_query);
   Word((ulong)Selection.block_time);Text(Selection.label);
   Word((ulong)Events.nfp);Word((ulong)Events.interest);Word((ulong)Events.cpi);
   Word((ulong)(long)Cached.year);Word((ulong)(long)Cached.mon);Word((ulong)(long)Cached.day);Word((ulong)(long)Cached.hour);
   Word((ulong)(long)Cached.min);Word((ulong)(long)Cached.sec);Word((ulong)(long)Cached.day_of_week);Word((ulong)(long)Cached.day_of_year);
   Word((ulong)(long)Execution.strategy_magic);Word((ulong)(long)Execution.magic_base);Text(Execution.symbol);
   Word(Bits(Execution.tick.bid));Word(Bits(Execution.tick.ask));Word(Bits(Execution.threshold_a));Word(Bits(Execution.gap));
   Word(Execution.last_ticket);Word(Execution.deviation);
   Word((ulong)Execution.trade.request.action);
   Word((ulong)Execution.trade.request.magic);
   Word((ulong)Execution.trade.request.order);
   Text(Execution.trade.request.symbol);
   Word(Bits(Execution.trade.request.volume));
   Word(Bits(Execution.trade.request.price));
   Word(Bits(Execution.trade.request.stoplimit));
   Word(Bits(Execution.trade.request.sl));
   Word(Bits(Execution.trade.request.tp));
   Word((ulong)Execution.trade.request.deviation);
   Word((ulong)Execution.trade.request.type);
   Word((ulong)Execution.trade.request.type_filling);
   Word((ulong)Execution.trade.request.type_time);
   Word((ulong)Execution.trade.request.expiration);
   Text(Execution.trade.request.comment);
   Word((ulong)Execution.trade.request.position);
   Word((ulong)Execution.trade.request.position_by);
   Word((ulong)Execution.trade.result.retcode);
   Word((ulong)Execution.trade.result.deal);
   Word((ulong)Execution.trade.result.order);
   Word(Bits(Execution.trade.result.volume));
   Word(Bits(Execution.trade.result.price));
   Word(Bits(Execution.trade.result.bid));
   Word(Bits(Execution.trade.result.ask));
   Text(Execution.trade.result.comment);
   Word((ulong)Execution.trade.result.request_id);
   Word((ulong)Execution.trade.result.retcode_external);
   Word((ulong)Execution.trade.check.retcode);
   Word(Bits(Execution.trade.check.balance));
   Word(Bits(Execution.trade.check.equity));
   Word(Bits(Execution.trade.check.profit));
   Word(Bits(Execution.trade.check.margin));
   Word(Bits(Execution.trade.check.margin_free));
   Word(Bits(Execution.trade.check.margin_level));
   Text(Execution.trade.check.comment);
   Word(Execution.trade.magic);Word((ulong)(long)Execution.trade.preferred);Word(Execution.options.async_mode);
   Word((ulong)(long)Execution.options.log_level);Word((ulong)(long)Execution.options.margin_mode);Word(error);
   Word(Friday.enabled);Word((ulong)(long)Friday.hour);Word(FridayClosed);
   Word(Bits(Percent));Word((ulong)(long)Daily.bars);Word(Daily.blocked);Word(Bits(Daily.peak));
   if(RecordFinal) Word((ulong)NewsBlocked);
}
int ReplyInt(const long &items[],const int count,int &pos)
{
   if(count<=0) return 0;
   const int index=pos<count ? pos : count-1;pos++;return (int)items[index];
}
ulong ReplyBits(const long &items[],const int count,int &pos)
{
   if(count<=0) return 0;
   const int index=pos<count ? pos : count-1;pos++;return (ulong)items[index];
}
int DealIndex(const ulong ticket)
{
   if(SelectedDeal>=0 && SelectedDeal<DealCount && (ticket==0 || (ulong)DealTicket[SelectedDeal]==ticket)) return SelectedDeal;
   return -1;
}
void DailyEffect(const int api)
{
   const int n=(api>=0 && api<64) ? ++ApiN[api] : 0;
   for(int i=0;i<EffectCount;i++)
   {
      if((int)EffectApi[i]!=api || (int)EffectN[i]!=n) continue;
      if(EffectField[i]==1) { NumberBits bits;bits.bits=(ulong)EffectValue[i];Percent=bits.value; }
      else if(EffectField[i]==2) { NumberBits bits;bits.bits=(ulong)EffectValue[i];Daily.peak=bits.value; }
      else if(EffectField[i]==3) Daily.blocked=(uchar)EffectValue[i];
      else if(EffectField[i]==4) Daily.bars=(int)EffectValue[i];
   }
}
void Begin()
{
   ulong start=FileTell(TapeFile);FileWriteInteger(TapeFile,0);Snapshot();ulong end=FileTell(TapeFile);
   FileSeek(TapeFile,(long)start,SEEK_SET);FileWriteInteger(TapeFile,(int)(end-start-4));FileSeek(TapeFile,(long)end,SEEK_SET);
}
void Header(const int api,const ulong a,const ulong b,const ulong c,const ulong d,
            const string t0,const string t1,const string t2,const string t3,const int bytes)
{
   FileWriteInteger(TapeFile,api);Word(a);Word(b);Word(c);Word(d);Text(t0);Text(t1);Text(t2);Text(t3);FileWriteInteger(TapeFile,bytes);
}
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,
         const string t0=NULL,const string t1=NULL,const string t2=NULL,const string t3=NULL)
{ uint error=GetLastError();Header(api,a,b,c,d,t0,t1,t2,t3,0);FileWriteInteger(TapeFile,(int)error); }
void CalendarPayload(const MqlDateTime &dt)
{ FileWriteInteger(TapeFile,dt.year);FileWriteInteger(TapeFile,dt.mon);FileWriteInteger(TapeFile,dt.day);FileWriteInteger(TapeFile,dt.hour);FileWriteInteger(TapeFile,dt.min);FileWriteInteger(TapeFile,dt.sec);FileWriteInteger(TapeFile,dt.day_of_week);FileWriteInteger(TapeFile,dt.day_of_year); }
int MockInfo(const ENUM_MQL_INFO_INTEGER property) { Begin();int value=(int)P[p_info];End(1,(ulong)property,(ulong)(long)value);return value; }
datetime MockServer() { Begin();long value=P[p_server];End(2,(ulong)value);return (datetime)value; }
datetime MockCurrent() { Begin();long value=P[p_current];End(3,0,(ulong)value);return (datetime)value; }
datetime MockCurrent(MqlDateTime &dt)
{
   Begin();long value=P[p_current];TimeToStruct((datetime)value,dt);uint error=GetLastError();
   Header(3,1,(ulong)value,0,0,NULL,NULL,NULL,NULL,32);CalendarPayload(dt);FileWriteInteger(TapeFile,(int)error);return (datetime)value;
}
bool MockStruct(const datetime value,MqlDateTime &dt)
{ Begin();bool ok=TimeToStruct(value,dt);uint error=GetLastError();Header(4,(ulong)value,(ulong)ok,0,0,NULL,NULL,NULL,NULL,32);CalendarPayload(dt);FileWriteInteger(TapeFile,(int)error);return ok; }
double MockMod(const double a,const double b) { Begin();double value=MathMod(a,b);End(5,Bits(a),Bits(b),Bits(value));return value; }
datetime MockParse(const string value) { Begin();datetime result=StringToTime(value);End(6,(ulong)result,0,0,0,value);return result; }
string MockTimeText(const datetime value,const int flags)
{ Begin();string result=TimeToString(value,flags);End(7,(ulong)value,(ulong)flags,0,0,result);return result; }
string MockIntegerText(const long value,const int length,const ushort fill)
{ Begin();string result=IntegerToString(value,length,fill);End(8,(ulong)value,(ulong)(long)length,fill,0,result);return result; }
bool MockConcat(string &target,const int year,const string suffix)
{ Begin();string before=target;bool ok=StringConcatenate(target,year,suffix);End(9,(ulong)(long)year,(ulong)ok,0,0,before,suffix,target);return ok; }
void ServiceEffect(const int api,const string text=NULL,const long property=-1)
{
   const int mode=(int)FridayData[10];
   if(((mode==1 && api==13) || (mode==2 && api==17 && property==15)) && !Mutated)
   { Execution.magic_base=(int)FridayData[11];Mutated=true; }
   if(mode==3 && api==10 && text=="deleting pending order") { Execution.last_ticket=999;Mutated=true; }
   if(mode==4 && api==10 && text=="Weekend starting! closing trades..") { FridayClosed=2;Mutated=true; }

   DailyEffect(api);
}
void MockPrint(const string value) { Begin();ServiceEffect(10,value);End(10,1,0,0,0,value); }
void MockPrint(const string a,const string b) { Begin();DailyEffect(10);End(10,2,0,0,0,a,b); }
int MockEvents(const string currency,MqlCalendarEvent &events[])
{
   Begin();int status=(int)P[p_calendar_status],count=status>0 ? 2 : 0;ArrayResize(events,count);
   if(count>0)
   {
      ZeroMemory(events[0]);ZeroMemory(events[1]);events[0].id=status==3 ? 0 : 77;events[1].id=status==3 ? 0 : 88;
      events[0].name=status==4 ? NULL : (status==2 ? "Other" : "Nonfarm Payrolls");
      events[1].name=status==4 ? NULL : (status==2 ? "Other" : "CPI (YoY)");
   }
   int reply=status<0 ? -1 : count;End(11,(ulong)(long)reply,(ulong)count,0,0,currency);return reply;
}
int MockCountry(const string country,MqlCalendarEvent &events[])
{
   Begin();int status=(int)P[p_calendar_status],count=status>0 ? 1 : 0;ArrayResize(events,count);
   if(count>0) { ZeroMemory(events[0]);events[0].id=status==3 ? 0 : 99;events[0].name=status==4 ? NULL : (status==2 ? "Other" : "Fed Interest Rate Decision"); }
   int reply=status<0 ? -1 : count;End(31,(ulong)(long)reply,(ulong)count,0,0,country);return reply;
}
int MockValues(const ulong event_id,MqlCalendarValue &values[],const datetime from,const datetime to)
{ Begin();ArrayResize(values,1);ZeroMemory(values[0]);values[0].time=(datetime)(event_id==99 || event_id==0x3212255e ? Extra[16] : (event_id==88 || event_id==0x3211d735 ? Extra[17] : P[p_release]));End(12,event_id,(ulong)from,(ulong)to,1);return 1; }
int MockOrders() { Begin();int total=P[p_orders]<0 ? -1 : (P[p_orders]!=0 ? 1 : 0);ServiceEffect(13);End(13,(ulong)(long)total);return total; }
ulong MockOrderTicket(const int index) { Begin();ulong value=P[p_orders]!=0 && index==0 ? 11 : 0;OrderTypeReads=0;End(14,(ulong)(long)index,value);return value; }
int MockPositions() { Begin();int total=P[p_position]<0 ? -1 : (P[p_position]!=0 ? 1 : 0);ServiceEffect(15);End(15,(ulong)(long)total);return total; }
ulong MockPositionTicket(const int index) { Begin();ulong value=P[p_position]!=0 && index==0 ? 21 : 0;End(16,(ulong)(long)index,value);return value; }
long MockOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{ Begin();long value=property==ORDER_MAGIC ? FridayData[6] : (OrderTypeReads++==0 ? FridayData[8] : FridayData[9]);ServiceEffect(17,NULL,(long)property);End(17,(ulong)property,(ulong)value);return value; }
string MockOrderString(const ENUM_ORDER_PROPERTY_STRING property)
{ Begin();string value=FridayData[7]==1 ? "xauusd" : (FridayData[7]==2 ? "OTHER" : "XAUUSD");End(18,(ulong)property,0,0,0,value);return value; }
double MockOrderDouble(const ENUM_ORDER_PROPERTY_DOUBLE property)
{ Begin();double value=P[p_orders]==2 ? 90. : 110.;End(19,(ulong)property,Bits(value));return value; }
bool MockOrderSelect(const ulong ticket)
{ Begin();bool ok=P[p_order_select]!=0 && ticket==11;End(20,ticket,(ulong)ok);return ok; }
bool MockSend(const MqlTradeRequest &request,MqlTradeResult &result)
{ Begin();bool ok=P[p_accepted]!=0;End(21,0,(ulong)ok);return ok; }
bool MockAsync(const MqlTradeRequest &request,MqlTradeResult &result)
{ Begin();bool ok=P[p_accepted]!=0;End(21,1,(ulong)ok);return ok; }
long MockPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{ Begin();long value=property==POSITION_MAGIC ? 43 : (P[p_position]==2 ? 1 : 0);End(22,(ulong)property,(ulong)value);return value; }
string MockPositionString(const ENUM_POSITION_PROPERTY_STRING property)
{ Begin();string value="XAUUSD";End(23,(ulong)property,0,0,0,value);return value; }
double MockPositionDouble(const ENUM_POSITION_PROPERTY_DOUBLE property)
{ Begin();double value=property==POSITION_VOLUME ? .25 : 0.;End(24,(ulong)property,Bits(value));return value; }
bool MockPositionSelect(const ulong ticket) { Begin();bool ok=ticket==21;End(25,ticket,(ulong)ok);return ok; }
long MockSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{ Begin();long value=property==SYMBOL_TRADE_FREEZE_LEVEL ? 5 : (property==SYMBOL_FILLING_MODE ? 3 : 0);End(26,(ulong)property,(ulong)value,0,0,symbol);return value; }
bool MockSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value)
{ Begin();value=63;End(29,(ulong)property,(ulong)value,1,0,symbol);return true; }
double MockSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{ Begin();double value=property==SYMBOL_POINT ? .01 : (property==SYMBOL_BID ? 100. : 101.);End(27,(ulong)property,Bits(value),0,0,symbol);return value; }
bool MockTick(const string symbol,MqlTick &tick)
{
   Begin();ZeroMemory(tick);tick.bid=100.;tick.ask=101.;uint error=GetLastError();Header(28,1,0,0,0,symbol,NULL,NULL,NULL,64);
   Word((ulong)tick.time);Word(Bits(tick.bid));Word(Bits(tick.ask));Word(Bits(tick.last));Word(tick.volume);Word((ulong)tick.time_msc);
   FileWriteInteger(TapeFile,(int)tick.flags);FileWriteInteger(TapeFile,0);Word(Bits(tick.volume_real));FileWriteInteger(TapeFile,(int)error);return true;
}
int MockBars(const string symbol,const ENUM_TIMEFRAMES period)
{ Begin();const int value=ReplyInt(BarsReplies,BarsReplyCount,BarsReplyPos);DailyEffect(32);End(32,(ulong)period,(ulong)(long)value,0,0,symbol);return value; }
double MockAccountInfoDouble(const ENUM_ACCOUNT_INFO_DOUBLE property)
{ Begin();const ulong bits=property==ACCOUNT_EQUITY ? ReplyBits(EquityReplies,EquityReplyCount,EquityReplyPos) : ReplyBits(BalanceReplies,BalanceReplyCount,BalanceReplyPos);NumberBits n;n.bits=bits;DailyEffect(33);End(33,(ulong)property,bits,0,0);return n.value; }
bool MockHistorySelect(const datetime from,const datetime to)
{ Begin();const bool value=HistorySelectReply!=0;DailyEffect(34);End(34,(ulong)from,(ulong)to,(ulong)value,0);return value; }
int MockHistoryDealsTotal()
{ Begin();const int value=(int)HistoryDealsTotalReply;DailyEffect(35);End(35,(ulong)(long)value,0,0,0);return value; }
ulong MockHistoryDealGetTicket(const int index)
{ Begin();SelectedDeal=index>=0 && index<DealCount ? index : -1;const ulong value=SelectedDeal>=0 ? (ulong)DealTicket[SelectedDeal] : 0;DailyEffect(36);End(36,(ulong)(long)index,value,0,0);return value; }
long MockHistoryDealGetInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property)
{ Begin();const int i=DealIndex(ticket);long value=0;if(i>=0) value=property==DEAL_TIME ? DealTime[i] : property==DEAL_ENTRY ? DealEntry[i] : 0;DailyEffect(37);End(37,ticket,(ulong)property,(ulong)value,0);return value; }
double MockHistoryDealGetDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property)
{ Begin();const int i=DealIndex(ticket);ulong bits=0;if(i>=0) bits=(ulong)(property==DEAL_PROFIT ? DealProfit[i] : property==DEAL_COMMISSION ? DealCommission[i] : property==DEAL_SWAP ? DealSwap[i] : 0);NumberBits n;n.bits=bits;DailyEffect(39);End(39,ticket,(ulong)property,bits,0);return n.value; }
datetime MockITime(const string symbol,const ENUM_TIMEFRAMES period,const int shift)
{ Begin();const long value=(long)ReplyBits(TimeReplies,TimeReplyCount,TimeReplyPos);DailyEffect(38);End(38,(ulong)period,(ulong)(long)shift,(ulong)value,0,symbol);return (datetime)value; }
bool MockStopped() { return false; }
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot1-daily-loss\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4e465231 || version!=1 || count<1) { FileClose(file);return 3; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),tapes=FileOpen(folder+"sdk-tape.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE || tapes==INVALID_HANDLE) { FileClose(file);return 4; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   FileWriteInteger(tapes,magic);FileWriteInteger(tapes,version);FileWriteInteger(tapes,count);
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(file);for(int i=0;i<23;i++) P[i]=FileReadLong(file);
      Cached.year=FileReadInteger(file);Cached.mon=FileReadInteger(file);Cached.day=FileReadInteger(file);Cached.hour=FileReadInteger(file);
      Cached.min=FileReadInteger(file);Cached.sec=FileReadInteger(file);Cached.day_of_week=FileReadInteger(file);Cached.day_of_year=FileReadInteger(file);
      for(int i=0;i<300;i++) History[i]=FileReadLong(file);
      for(int i=0;i<18;i++) Extra[i]=FileReadLong(file);
      for(int i=0;i<12;i++) FridayData[i]=FileReadLong(file);
      NumberBits percent_bits;percent_bits.bits=(ulong)FileReadLong(file);Percent=percent_bits.value;
      NumberBits peak_bits;peak_bits.bits=(ulong)FileReadLong(file);Daily.peak=peak_bits.value;Daily.bars=(int)FileReadLong(file);Daily.blocked=(uchar)FileReadLong(file);
      BarsReplyCount=FileReadInteger(file);if(BarsReplyCount<0 || BarsReplyCount>256) { FileClose(file);return 8; }for(int i=0;i<BarsReplyCount;i++) BarsReplies[i]=FileReadLong(file);BarsReplyPos=0;
      EquityReplyCount=FileReadInteger(file);if(EquityReplyCount<0 || EquityReplyCount>256) { FileClose(file);return 8; }for(int i=0;i<EquityReplyCount;i++) EquityReplies[i]=FileReadLong(file);EquityReplyPos=0;
      BalanceReplyCount=FileReadInteger(file);if(BalanceReplyCount<0 || BalanceReplyCount>256) { FileClose(file);return 8; }for(int i=0;i<BalanceReplyCount;i++) BalanceReplies[i]=FileReadLong(file);BalanceReplyPos=0;
      TimeReplyCount=FileReadInteger(file);if(TimeReplyCount<0 || TimeReplyCount>256) { FileClose(file);return 8; }for(int i=0;i<TimeReplyCount;i++) TimeReplies[i]=FileReadLong(file);TimeReplyPos=0;
      HistorySelectReply=FileReadInteger(file);HistoryDealsTotalReply=FileReadInteger(file);DealCount=FileReadInteger(file);if(DealCount<0 || DealCount>256) { FileClose(file);return 8; }SelectedDeal=-1;
      for(int i=0;i<DealCount;i++) { DealTicket[i]=FileReadLong(file);DealTime[i]=FileReadLong(file);DealEntry[i]=FileReadLong(file);DealProfit[i]=FileReadLong(file);DealCommission[i]=FileReadLong(file);DealSwap[i]=FileReadLong(file); }
      EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>256) { FileClose(file);return 8; }for(int i=0;i<EffectCount;i++) { EffectApi[i]=FileReadLong(file);EffectN[i]=FileReadLong(file);EffectField[i]=FileReadLong(file);EffectValue[i]=FileReadLong(file); }ArrayInitialize(ApiN,0);
      ZeroMemory(Friday);Friday.enabled=(uchar)FridayData[0];Friday.hour=(int)FridayData[1];FridayClosed=(uchar)FridayData[2];
      Mutated=false;OrderTypeReads=0;
      ZeroMemory(Settings);ZeroMemory(State);ZeroMemory(Events);ZeroMemory(Execution);ZeroMemory(InterestSettings);ZeroMemory(InterestState);ZeroMemory(CpiSettings);ZeroMemory(CpiState);ZeroMemory(Selection);
      InterestSettings.enabled=(uchar)Extra[0];InterestSettings.delete_pending=(uchar)Extra[1];InterestSettings.close_positions=(uchar)Extra[2];InterestSettings.before_minutes=(int)Extra[3];InterestSettings.after_minutes=(int)Extra[4];InterestState.notice=(uchar)Extra[5];InterestState.blocked=(uchar)Extra[6];InterestState.last_query=Extra[7];
      CpiSettings.enabled=(uchar)Extra[8];CpiSettings.delete_pending=(uchar)Extra[9];CpiSettings.close_positions=(uchar)Extra[10];CpiSettings.before_minutes=(int)Extra[11];CpiSettings.after_minutes=(int)Extra[12];CpiState.notice=(uchar)Extra[13];CpiState.blocked=(uchar)Extra[14];CpiState.last_query=Extra[15];
      Settings.enabled=(uchar)P[p_enabled];Settings.use_calendar=(uchar)P[p_use_calendar];Settings.throttle=(uchar)P[p_throttle];
      Settings.delete_pending=(uchar)P[p_delete_pending];Settings.close_positions=(uchar)P[p_close_positions];
      Settings.before_minutes=(int)P[p_before_minutes];Settings.after_minutes=(int)P[p_after_minutes];
      State.initialization_notice=(uchar)P[p_initialization_notice];State.notice=(uchar)P[p_notice];State.blocked=(uchar)P[p_blocked];
      State.last_query=P[p_last_query];State.utc_reference=P[p_utc_reference];Events.nfp=P[p_nfp];Events.interest=7777;Events.cpi=8888;
      Execution.strategy_magic=42;Execution.magic_base=(int)FridayData[5];Execution.symbol="XAUUSD";Execution.tick.bid=100.;Execution.tick.ask=101.;
      Execution.threshold_a=1.;Execution.gap=1.;Execution.last_ticket=(ulong)0x1122334455667788;Execution.deviation=99;Execution.options.async_mode=(uchar)P[p_async_mode];
      string name=folder+"tape-"+IntegerToString(id)+".bin";TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE) return 5;
      Print("DAILY_LOSS_CASE:",id);ResetLastError();
      RecordFinal=false;EndErrorOverride=-1;NewsBlocked=Bot1ProcessDailyLoss(Percent,Daily,Execution);int final_error=GetLastError();FileClose(TapeFile);
      int part=FileOpen(name,FILE_READ|FILE_BIN);if(part==INVALID_HANDLE) return 6;
      int size=(int)FileSize(part);uchar bytes[];ArrayResize(bytes,size);if(size>0) FileReadArray(part,bytes,0,size);FileClose(part);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0) FileWriteArray(tapes,bytes,0,size);
      FileWriteInteger(output,id);TapeFile=output;EndErrorOverride=final_error;RecordFinal=true;Begin();
   }
   FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
