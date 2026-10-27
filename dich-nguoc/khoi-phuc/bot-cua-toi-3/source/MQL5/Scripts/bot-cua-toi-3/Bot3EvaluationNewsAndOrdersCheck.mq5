#property strict
input string CheckRun="";
int SourceError();void MockSleep(const int milliseconds);
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
int MockCountry(const string country,MqlCalendarEvent &events[]);
#define GetLastError SourceError
#define Sleep MockSleep
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
#include "../../Include/bot-cua-toi-3/Bot3EvaluationNewsAndOrders.mqh"
#undef GetLastError
#undef Sleep
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
Bot3NfpFilterSettings Settings;Bot3NfpFilterState State;Bot3NewsEvents Events;Bot3NfpExecution Execution;
Bot3ReleaseFilterSettings InterestSettings,CpiSettings;Bot3ReleaseFilterState InterestState,CpiState;Bot3NewsSelection Selection;
long Extra[18],FridayData[12];Bot3FridaySettings Friday;uchar FridayClosed;
bool Mutated=false,RecordFinal=false,NewsBlocked=false;int OrderTypeReads=0,MagicReads=0,PriceReads=0;long WideData[21];
Bot3SpreadSettings SpreadSettings;Bot3PendingQueue Queue;double SpreadUnit,CurrentSpread;
Bot3PendingRestoreSettings Restore;long RestoreData[14],SyntheticError=-1;bool CastProofOk=true;int SendCalls=0,SleepCalls=0,RestorePrints=0;
int PendingEnabled=0,MaximumPending=0,TotalCalls=0;long LimitData[11];
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
   uint error=EndErrorOverride>=0 ? (uint)EndErrorOverride : SourceError();
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
   Word(Friday.enabled);Word((ulong)(long)Friday.hour);Word(FridayClosed);Word(Friday.delete_pending);Word(Friday.close_positions);
   Word(SpreadSettings.enabled);Word((ulong)(long)SpreadSettings.distance_points);Word(Queue.enabled);
   Word(Bits(SpreadSettings.maximum));Word(Bits(SpreadSettings.minimum));Word(Bits(SpreadUnit));Word(Bits(CurrentSpread));
   for(int row=0;row<100;row++) for(int col=0;col<3;col++) Word(Bits(Queue.orders[row][col]));
   for(int row=0;row<100;row++) for(int col=0;col<2;col++) Word(Bits(Queue.results[row][col]));
   Word(Bits(Restore.sl_distance));Word(Bits(Restore.tp_distance));Word((ulong)Restore.expiration_base);
   Word(Restore.virtual_expiration);Word(Queue.error_count);Text(Restore.comment);
   Word((ulong)(long)PendingEnabled);Word((ulong)(long)MaximumPending);
   if(RecordFinal) Word((ulong)NewsBlocked);
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
{ uint error=SourceError();Header(api,a,b,c,d,t0,t1,t2,t3,0);FileWriteInteger(TapeFile,(int)error); }
void CalendarPayload(const MqlDateTime &dt)
{ FileWriteInteger(TapeFile,dt.year);FileWriteInteger(TapeFile,dt.mon);FileWriteInteger(TapeFile,dt.day);FileWriteInteger(TapeFile,dt.hour);FileWriteInteger(TapeFile,dt.min);FileWriteInteger(TapeFile,dt.sec);FileWriteInteger(TapeFile,dt.day_of_week);FileWriteInteger(TapeFile,dt.day_of_year); }
int MockInfo(const ENUM_MQL_INFO_INTEGER property) { Begin();int value=(int)P[p_info];End(1,(ulong)property,(ulong)(long)value);return value; }
datetime MockServer() { Begin();long value=P[p_server];End(2,(ulong)value);return (datetime)value; }
datetime MockCurrent() { Begin();long value=P[p_current];End(3,0,(ulong)value);return (datetime)value; }
datetime MockCurrent(MqlDateTime &dt)
{
   Begin();long value=P[p_current];TimeToStruct((datetime)value,dt);uint error=SourceError();
   Header(3,1,(ulong)value,0,0,NULL,NULL,NULL,NULL,32);CalendarPayload(dt);FileWriteInteger(TapeFile,(int)error);return (datetime)value;
}
bool MockStruct(const datetime value,MqlDateTime &dt)
{ Begin();bool ok=TimeToStruct(value,dt);uint error=SourceError();Header(4,(ulong)value,(ulong)ok,0,0,NULL,NULL,NULL,NULL,32);CalendarPayload(dt);FileWriteInteger(TapeFile,(int)error);return ok; }
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
   if(mode==5 && api==15 && !Mutated) { Friday.delete_pending=0;Mutated=true; }

}
void WideEffect(const int api,const string text=NULL,const long property=-1)
{
   const int mode=(int)WideData[11];
   if(api==19 && property==9)
   {
      PriceReads++;
      if(mode==1 && PriceReads==1) Execution.tick.ask=105.;
      if(mode==2 && PriceReads==2) Execution.tick.ask=1000.;
   }
   if(mode==3 && api==10 && StringFind(text,"Spread too high..(")==0) Queue.enabled=0;
   if(mode==4 && api==10 && StringFind(text,"Storing pending order nr ")==0) Execution.last_ticket=999;
   if(mode==5 && api==19 && property==7) { Queue.results[0][0]=(double)(long)Execution.last_ticket;Queue.results[0][1]=3.; }
   if(mode==6 && api==17 && property==15 && MagicReads==1) Execution.strategy_magic=43;
   if(mode==7 && api==10 && StringFind(text,"Spread too high..(")==0) SpreadSettings.minimum=-1.;
   if(mode==8 && api==18) Execution.symbol="OTHER";
}
int SourceError() { return SyntheticError>=0 ? (int)SyntheticError : GetLastError(); }
void SetSdkError(const int error)
{
   if(error==0) { SyntheticError=-1;ResetLastError(); }
   else SyntheticError=error;
}
void RestoreEffect(const int api,const string text=NULL)
{
   const int mode=(int)RestoreData[5];bool first=false;
   if(api==10 && (text=="Restoring pending buy-order" || text=="Restoring pending sell-order"))
   { RestorePrints++;first=RestorePrints==1; }
   if((mode==1 && first) || (mode==2 && api==21 && SendCalls==1) || (mode==3 && api==33 && SleepCalls==1))
   {
      Restore.sl_distance=12.;Restore.tp_distance=7.;SpreadUnit=.5;Execution.strategy_magic=77;Restore.comment="updated";
      if(mode==3) { int row=(int)RestoreData[6];Queue.orders[row][0]=RestoreData[7]==4 ? 112. : 88.;Queue.orders[row][1]=(double)RestoreData[7];Queue.orders[row][2]=.5; }
   }
   if((mode==4 || mode==5) && api==21 && SendCalls==1) Queue.enabled=(uchar)(mode==4 ? 0 : 2);
   if(mode==6 && first) { int row=(int)RestoreData[6];Queue.orders[row][0]=90.;Queue.orders[row][1]=5.;Queue.orders[row][2]=.25; }
   if(mode==8 && first) Execution.threshold_a=1000.;
   if(mode==9 && api==33 && SleepCalls==1) SetSdkError(0);
}
void MockSleep(const int milliseconds) { Begin();SleepCalls++;RestoreEffect(33);End(33,(ulong)(long)milliseconds); }
void MockPrint(const string value) { Begin();ServiceEffect(10,value);WideEffect(10,value);RestoreEffect(10,value);End(10,1,0,0,0,value); }
void MockPrint(const string a,const string b) { Begin();End(10,2,0,0,0,a,b); }
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
void LimitEffect(const int api)
{
   const int mode=(int)LimitData[10];
   if(mode==1 && api==13 && TotalCalls==1) PendingEnabled=2;
   if(mode==2 && api==13 && TotalCalls==2) MaximumPending=2;
   if(mode==3 && api==18) MaximumPending=0;
   if(mode==4 && api==21 && SendCalls==1) PendingEnabled=0;
   if(mode==5 && api==14) MaximumPending=2;
}
int MockOrders() { Begin();int index=TotalCalls<8 ? TotalCalls : 7;int total=(int)LimitData[2+index];TotalCalls++;ServiceEffect(13);LimitEffect(13);End(13,(ulong)(long)total);return total; }
ulong MockOrderTicket(const int index) { Begin();ulong value=P[p_orders]!=0 && index==0 ? (ulong)WideData[13] : 0;OrderTypeReads=0;MagicReads=0;PriceReads=0;LimitEffect(14);End(14,(ulong)(long)index,value);return value; }
int MockPositions() { Begin();int total=P[p_position]<0 ? -1 : (P[p_position]!=0 ? 1 : 0);ServiceEffect(15);End(15,(ulong)(long)total);return total; }
ulong MockPositionTicket(const int index) { Begin();ulong value=P[p_position]!=0 && index==0 ? 21 : 0;End(16,(ulong)(long)index,value);return value; }
long MockOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{ Begin();long value=property==ORDER_MAGIC ? (MagicReads++==0 ? FridayData[6] : WideData[12]) : ((LimitData[10]==4 && SendCalls>0) ? 5 : (OrderTypeReads++==0 ? FridayData[8] : FridayData[9]));ServiceEffect(17,NULL,(long)property);WideEffect(17,NULL,(long)property);End(17,(ulong)property,(ulong)value);return value; }
string MockOrderString(const ENUM_ORDER_PROPERTY_STRING property)
{ Begin();string value=FridayData[7]==1 ? "xauusd" : (FridayData[7]==2 ? "OTHER" : "XAUUSD");WideEffect(18);LimitEffect(18);End(18,(ulong)property,0,0,0,value);return value; }
double MockOrderDouble(const ENUM_ORDER_PROPERTY_DOUBLE property)
{ Begin();double value=property==ORDER_PRICE_OPEN ? Number((ulong)WideData[14+(PriceReads<6 ? PriceReads : 5)]) : Number((ulong)WideData[20]);WideEffect(19,NULL,(long)property);End(19,(ulong)property,Bits(value));return value; }
bool MockOrderSelect(const ulong ticket)
{ Begin();bool ok=P[p_order_select]!=0 && ticket==11;End(20,ticket,(ulong)ok);return ok; }
bool MockSend(const MqlTradeRequest &request,MqlTradeResult &result)
{ Begin();int index=SendCalls<3 ? SendCalls : 2;bool ok=RestoreData[8+index]!=0;SetSdkError((int)RestoreData[11+index]);SendCalls++;RestoreEffect(21);LimitEffect(21);End(21,0,(ulong)ok);return ok; }
bool MockAsync(const MqlTradeRequest &request,MqlTradeResult &result)
{ Begin();int index=SendCalls<3 ? SendCalls : 2;bool ok=RestoreData[8+index]!=0;SetSdkError((int)RestoreData[11+index]);SendCalls++;RestoreEffect(21);LimitEffect(21);End(21,1,(ulong)ok);return ok; }
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
{ Begin();value=(RestoreData[5]==7 && property==SYMBOL_ORDER_MODE) ? 0 : 63;if(RestoreData[5]==7 && property==SYMBOL_ORDER_MODE) SetSdkError(3);End(29,(ulong)property,(ulong)value,1,0,symbol);return true; }
double MockSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{ Begin();double value=property==SYMBOL_POINT ? .01 : (property==SYMBOL_BID ? 100. : 101.);End(27,(ulong)property,Bits(value),0,0,symbol);return value; }
bool MockTick(const string symbol,MqlTick &tick)
{
   Begin();ZeroMemory(tick);tick.bid=100.;tick.ask=101.;uint error=SourceError();Header(28,1,0,0,0,symbol,NULL,NULL,NULL,64);
   Word((ulong)tick.time);Word(Bits(tick.bid));Word(Bits(tick.ask));Word(Bits(tick.last));Word(tick.volume);Word((ulong)tick.time_msc);
   FileWriteInteger(TapeFile,(int)tick.flags);FileWriteInteger(TapeFile,0);Word(Bits(tick.volume_real));FileWriteInteger(TapeFile,(int)error);return true;
}
bool MockStopped() { return false; }
double Number(const ulong bits) { NumberBits value;value.bits=bits;return value.value; }
void WriteCast(const int file,const int kind,const ulong bits,const uint error,const string text)
{
   FileWriteInteger(file,kind);FileWriteLong(file,(long)bits);FileWriteInteger(file,(int)error);
   int length=StringLen(text);FileWriteInteger(file,length);if(length>0) FileWriteString(file,text,length);
}
void DoubleCast(const int file,const double value)
{
   ResetLastError();string text=(string)value;SetUserError(7);uint before=GetLastError();string second=(string)value;uint after=GetLastError();
   if(before!=after || text!=second) CastProofOk=false;WriteCast(file,0x58,Bits(value),0xffffffff,text);
}
void TicketCast(const int file,const ulong value)
{
   ResetLastError();string text=(string)value;SetUserError(7);uint before=GetLastError();string second=(string)value;uint after=GetLastError();
   if(before!=after || text!=second) CastProofOk=false;WriteCast(file,0x55,value,0xffffffff,text);
}
void SignedCast(const int file,const int value)
{
   ResetLastError();string text=(string)value;SetUserError(7);uint before=GetLastError();string second=(string)value;uint after=GetLastError();
   if(before!=after || text!=second) CastProofOk=false;WriteCast(file,0x52,(ulong)(uint)value,0xffffffff,text);
}
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-news-orders\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4e465231 || version!=1 || count<1) { FileClose(file);return 3; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),tapes=FileOpen(folder+"sdk-tape.bin",FILE_WRITE|FILE_BIN);
   int casts=FileOpen(folder+"cast-values.bin",FILE_WRITE|FILE_BIN);if(casts==INVALID_HANDLE) return 8;
   FileWriteInteger(casts,magic);FileWriteInteger(casts,version);FileWriteInteger(casts,count*9);
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
      for(int i=0;i<21;i++) WideData[i]=FileReadLong(file);
      ZeroMemory(SpreadSettings);ZeroMemory(Queue);SpreadSettings.enabled=(uchar)WideData[0];SpreadSettings.distance_points=(int)WideData[1];Queue.enabled=(uchar)WideData[2];
      SpreadSettings.maximum=Number((ulong)WideData[3]);SpreadSettings.minimum=Number((ulong)WideData[4]);SpreadUnit=Number((ulong)WideData[5]);CurrentSpread=Number((ulong)WideData[6]);
      for(int row=0;row<100;row++) for(int col=0;col<3;col++) Queue.orders[row][col]=FileReadDouble(file);
      for(int row=0;row<100;row++) for(int col=0;col<2;col++) Queue.results[row][col]=FileReadDouble(file);
      for(int i=0;i<14;i++) RestoreData[i]=FileReadLong(file);
      for(int i=0;i<11;i++) LimitData[i]=FileReadLong(file);PendingEnabled=(int)LimitData[0];MaximumPending=(int)LimitData[1];TotalCalls=0;
      ZeroMemory(Restore);Restore.sl_distance=Number((ulong)RestoreData[0]);Restore.tp_distance=Number((ulong)RestoreData[1]);
      Restore.expiration_base=(datetime)RestoreData[2];Restore.virtual_expiration=(uchar)RestoreData[3];Queue.error_count=(uint)RestoreData[4];Restore.comment="restore";
      SyntheticError=-1;SendCalls=0;SleepCalls=0;RestorePrints=0;
      ZeroMemory(Friday);Friday.enabled=(uchar)FridayData[0];Friday.hour=(int)FridayData[1];FridayClosed=(uchar)FridayData[2];Friday.delete_pending=(uchar)FridayData[3];Friday.close_positions=(uchar)FridayData[4];
      Mutated=false;OrderTypeReads=0;MagicReads=0;PriceReads=0;
      ZeroMemory(Settings);ZeroMemory(State);ZeroMemory(Events);ZeroMemory(Execution);ZeroMemory(InterestSettings);ZeroMemory(InterestState);ZeroMemory(CpiSettings);ZeroMemory(CpiState);ZeroMemory(Selection);
      InterestSettings.enabled=(uchar)Extra[0];InterestSettings.delete_pending=(uchar)Extra[1];InterestSettings.close_positions=(uchar)Extra[2];InterestSettings.before_minutes=(int)Extra[3];InterestSettings.after_minutes=(int)Extra[4];InterestState.notice=(uchar)Extra[5];InterestState.blocked=(uchar)Extra[6];InterestState.last_query=Extra[7];
      CpiSettings.enabled=(uchar)Extra[8];CpiSettings.delete_pending=(uchar)Extra[9];CpiSettings.close_positions=(uchar)Extra[10];CpiSettings.before_minutes=(int)Extra[11];CpiSettings.after_minutes=(int)Extra[12];CpiState.notice=(uchar)Extra[13];CpiState.blocked=(uchar)Extra[14];CpiState.last_query=Extra[15];
      Settings.enabled=(uchar)P[p_enabled];Settings.use_calendar=(uchar)P[p_use_calendar];Settings.throttle=(uchar)P[p_throttle];
      Settings.delete_pending=(uchar)P[p_delete_pending];Settings.close_positions=(uchar)P[p_close_positions];
      Settings.before_minutes=(int)P[p_before_minutes];Settings.after_minutes=(int)P[p_after_minutes];
      State.initialization_notice=(uchar)P[p_initialization_notice];State.notice=(uchar)P[p_notice];State.blocked=(uchar)P[p_blocked];
      State.last_query=P[p_last_query];State.utc_reference=P[p_utc_reference];Events.nfp=P[p_nfp];Events.interest=7777;Events.cpi=8888;
      Execution.strategy_magic=42;Execution.magic_base=(int)FridayData[5];Execution.symbol="XAUUSD";Execution.tick.bid=Number((ulong)WideData[8]);Execution.tick.ask=Number((ulong)WideData[7]);
      Execution.threshold_a=1.;Execution.gap=Number((ulong)WideData[9]);Execution.last_ticket=(ulong)0x1122334455667788;Execution.deviation=99;Execution.options.async_mode=(uchar)P[p_async_mode];
      DoubleCast(casts,CurrentSpread);DoubleCast(casts,Execution.tick.ask-Execution.tick.bid);TicketCast(casts,(ulong)WideData[13]);TicketCast(casts,999);TicketCast(casts,(ulong)0x1122334455667788);SignedCast(casts,0);SignedCast(casts,3);SignedCast(casts,132);SignedCast(casts,999);if(!CastProofOk) return 9;
      string name=folder+"tape-"+IntegerToString(id)+".bin";TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE) return 5;
      Print("NEWS_ORDERS_CASE:",id);ResetLastError();
      RecordFinal=false;EndErrorOverride=-1;NewsBlocked=Bot3EvaluateNewsAndPendingLimits(Settings,State,InterestSettings,InterestState,CpiSettings,CpiState,Events,Cached,History,History,History,Execution,Selection,Friday,FridayClosed,SpreadSettings,SpreadUnit,CurrentSpread,Queue,Restore,PendingEnabled,MaximumPending);int final_error=SourceError();FileClose(TapeFile);
      int part=FileOpen(name,FILE_READ|FILE_BIN);if(part==INVALID_HANDLE) return 6;
      int size=(int)FileSize(part);uchar bytes[];ArrayResize(bytes,size);if(size>0) FileReadArray(part,bytes,0,size);FileClose(part);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0) FileWriteArray(tapes,bytes,0,size);
      FileWriteInteger(output,id);TapeFile=output;EndErrorOverride=final_error;RecordFinal=true;Begin();
   }
   FileClose(file);FileClose(output);FileClose(tapes);FileClose(casts);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
