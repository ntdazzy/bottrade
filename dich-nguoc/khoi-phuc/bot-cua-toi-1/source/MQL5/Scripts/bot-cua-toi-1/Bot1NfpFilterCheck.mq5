#property strict
input string CheckRun="";
int MockInfo(const ENUM_MQL_INFO_INTEGER property);
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
#define MQLInfoInteger MockInfo
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
#include "../../Include/bot-cua-toi-1/Bot1NfpFilter.mqh"
#undef MQLInfoInteger
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
void MockPrint(const string value) { Begin();End(10,1,0,0,0,value); }
void MockPrint(const string a,const string b) { Begin();End(10,2,0,0,0,a,b); }
int MockEvents(const string currency,MqlCalendarEvent &events[])
{
   Begin();int status=(int)P[p_calendar_status];int count=status>0 ? 1 : 0;ArrayResize(events,count);
   if(count>0) { ZeroMemory(events[0]);events[0].id=status==3 ? 0 : 77;events[0].name=status==4 ? NULL : (status==2 ? "Other" : "Nonfarm Payrolls"); }
   int reply=status<0 ? -1 : count;End(11,(ulong)(long)reply,(ulong)count,0,0,currency);return reply;
}
int MockValues(const ulong event_id,MqlCalendarValue &values[],const datetime from,const datetime to)
{ Begin();ArrayResize(values,1);ZeroMemory(values[0]);values[0].time=(datetime)P[p_release];End(12,event_id,(ulong)from,(ulong)to,1);return 1; }
int MockOrders() { Begin();int total=P[p_orders]!=0 ? 1 : 0;End(13,(ulong)total);return total; }
ulong MockOrderTicket(const int index) { Begin();ulong value=P[p_orders]!=0 && index==0 ? 11 : 0;End(14,(ulong)(long)index,value);return value; }
int MockPositions() { Begin();int total=P[p_position]!=0 ? 1 : 0;End(15,(ulong)total);return total; }
ulong MockPositionTicket(const int index) { Begin();ulong value=P[p_position]!=0 && index==0 ? 21 : 0;End(16,(ulong)(long)index,value);return value; }
long MockOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{ Begin();long value=property==ORDER_MAGIC ? 42 : (P[p_orders]==2 ? 5 : 4);End(17,(ulong)property,(ulong)value);return value; }
string MockOrderString(const ENUM_ORDER_PROPERTY_STRING property)
{ Begin();string value="XAUUSD";End(18,(ulong)property,0,0,0,value);return value; }
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
bool MockStopped() { return false; }
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot1-nfp-filter\\"+CheckRun+"\\";
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
      ZeroMemory(Settings);ZeroMemory(State);ZeroMemory(Events);ZeroMemory(Execution);
      Settings.enabled=(uchar)P[p_enabled];Settings.use_calendar=(uchar)P[p_use_calendar];Settings.throttle=(uchar)P[p_throttle];
      Settings.delete_pending=(uchar)P[p_delete_pending];Settings.close_positions=(uchar)P[p_close_positions];
      Settings.before_minutes=(int)P[p_before_minutes];Settings.after_minutes=(int)P[p_after_minutes];
      State.initialization_notice=(uchar)P[p_initialization_notice];State.notice=(uchar)P[p_notice];State.blocked=(uchar)P[p_blocked];
      State.last_query=P[p_last_query];State.utc_reference=P[p_utc_reference];Events.nfp=P[p_nfp];Events.interest=7777;Events.cpi=8888;
      Execution.strategy_magic=42;Execution.magic_base=42;Execution.symbol="XAUUSD";Execution.tick.bid=100.;Execution.tick.ask=101.;
      Execution.threshold_a=1.;Execution.gap=1.;Execution.last_ticket=(ulong)0x1122334455667788;Execution.deviation=99;Execution.options.async_mode=(uchar)P[p_async_mode];
      string name=folder+"tape-"+IntegerToString(id)+".bin";TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE) return 5;
      Print("NFP_FILTER_CASE:",id);ResetLastError();
      EndErrorOverride=-1;Bot1ProcessNfpFilter(Settings,State,Events,Cached,History,Execution);int final_error=GetLastError();FileClose(TapeFile);
      int part=FileOpen(name,FILE_READ|FILE_BIN);if(part==INVALID_HANDLE) return 6;
      int size=(int)FileSize(part);uchar bytes[];ArrayResize(bytes,size);if(size>0) FileReadArray(part,bytes,0,size);FileClose(part);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0) FileWriteArray(tapes,bytes,0,size);
      FileWriteInteger(output,id);TapeFile=output;EndErrorOverride=final_error;Begin();
   }
   FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
