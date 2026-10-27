#property strict
#include "Bot3EvaluationPendingApi.mqh"
#define CLEANUP_MAGIC 0x45504333
struct CleanupOrder
{
   ulong ticket;
   long magic,type;
   int select_ok,tick_ok;
   ulong point,bid,ask,price;
   long freeze;
   string symbol;
};
CleanupOrder CleanupOrders[];
int CleanupTotal=0,SelectedOrder=-1;
double CleanupResults[100][2];
int PendingTotal() { StopEvent(23,(ulong)(long)CleanupTotal);return CleanupTotal; }
ulong PendingTicket(const int index)
{
   ulong ticket=(index>=0 && index<ArraySize(CleanupOrders)) ? CleanupOrders[index].ticket : 0;
   if(ticket!=0) SelectedOrder=index;
   StopEvent(24,(ulong)(long)index,ticket,(ulong)(long)SelectedOrder);return ticket;
}
bool HaveOrder()
{
   if(SelectedOrder<0 || SelectedOrder>=ArraySize(CleanupOrders)) { Fail(401);return false; }
   return true;
}
long PendingInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{
   if(!HaveOrder()) return 0;
   if(property!=ORDER_MAGIC && property!=ORDER_TYPE) Fail(402);
   long value=(property==ORDER_MAGIC ? CleanupOrders[SelectedOrder].magic : CleanupOrders[SelectedOrder].type);
   StopEvent(25,(ulong)property,(ulong)value,(ulong)(long)SelectedOrder);return value;
}
string PendingString(const ENUM_ORDER_PROPERTY_STRING property)
{
   if(!HaveOrder()) return NULL;
   if(property!=ORDER_SYMBOL) Fail(403);
   string value=CleanupOrders[SelectedOrder].symbol;
   StopEvent(26,(ulong)property,(ulong)(long)SelectedOrder,0,0,0,value);return value;
}
bool PendingSelect(const ulong ticket)
{
   int found=-1;
   for(int i=0;i<ArraySize(CleanupOrders);i++)
      if(CleanupOrders[i].ticket==ticket) { found=i;break; }
   bool ok=found>=0 && CleanupOrders[found].select_ok!=0;
   if(ok) SelectedOrder=found;
   StopEvent(27,ticket,(ulong)ok,(ulong)(long)SelectedOrder);return ok;
}
double PendingSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(!HaveOrder()) return 0;
   if(property!=SYMBOL_POINT) Fail(404);
   ulong value=CleanupOrders[SelectedOrder].point;
   StopEvent(28,(ulong)property,value,0,0,0,symbol);DoubleBits n;n.bits=value;return n.value;
}
bool PendingTick(const string symbol,MqlTick &tick)
{
   if(!HaveOrder()) return false;
   CleanupOrder value=CleanupOrders[SelectedOrder];DoubleBits n;
   n.bits=value.bid;tick.bid=n.value;n.bits=value.ask;tick.ask=n.value;
   StopEvent(29,(ulong)value.tick_ok,value.bid,value.ask,0,0,symbol);return value.tick_ok!=0;
}
long PendingSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(!HaveOrder()) return 0;
   if(property!=SYMBOL_TRADE_FREEZE_LEVEL) Fail(405);
   long value=CleanupOrders[SelectedOrder].freeze;
   StopEvent(30,(ulong)property,(ulong)value,0,0,0,symbol);return value;
}
double PendingDouble(const ENUM_ORDER_PROPERTY_DOUBLE property)
{
   if(!HaveOrder()) return 0;
   if(property!=ORDER_PRICE_OPEN) Fail(406);
   ulong value=CleanupOrders[SelectedOrder].price;
   StopEvent(31,(ulong)property,value,(ulong)(long)SelectedOrder);DoubleBits n;n.bits=value;return n.value;
}
#define OrdersTotal PendingTotal
#define OrderGetTicket PendingTicket
#define OrderGetInteger PendingInteger
#define OrderGetString PendingString
#define OrderSelect PendingSelect
#define SymbolInfoDouble PendingSymbolDouble
#define SymbolInfoTick PendingTick
#define SymbolInfoInteger PendingSymbolInteger
#define OrderGetDouble PendingDouble
#define IsStopped StopIsStopped
#define PrintFormat StopPrintFormat
#include "../../Include/bot-cua-toi-3/Bot3OrderCancel.mqh"
bool ObservedDelete(Bot3PendingRequestState &trade,Bot3TradeSendOptions &options,const ulong ticket);
#define Bot3DeletePending ObservedDelete
#include "../../Include/bot-cua-toi-3/Bot3EvaluationPendingCleanup.mqh"
#undef Bot3DeletePending
#undef OrdersTotal
#undef OrderGetTicket
#undef OrderGetInteger
#undef OrderGetString
#undef OrderSelect
#undef SymbolInfoDouble
#undef SymbolInfoTick
#undef SymbolInfoInteger
#undef OrderGetDouble
#undef IsStopped
#undef PrintFormat
bool ObservedDelete(Bot3PendingRequestState &trade,Bot3TradeSendOptions &options,const ulong ticket)
{
   StopEvent(21,ticket,0,0,0,0,NULL,NULL,NULL,true);
   bool value=Bot3DeletePending(trade,options,ticket);
   StopEvent(22,(ulong)value,0,0,0,0,NULL,NULL,NULL,true);return value;
}
bool ReadCleanupCase(const int file)
{
   CleanupTotal=FileReadInteger(file);int count=FileReadInteger(file);
   if(count<0 || count>8) { Fail(407);return false; }
   if(ArrayResize(CleanupOrders,count)!=count) { Fail(408);return false; }
   for(int i=0;i<count;i++)
   {
      CleanupOrders[i].ticket=(ulong)FileReadLong(file);CleanupOrders[i].magic=FileReadLong(file);
      CleanupOrders[i].type=FileReadLong(file);CleanupOrders[i].select_ok=FileReadInteger(file);
      CleanupOrders[i].point=(ulong)FileReadLong(file);CleanupOrders[i].bid=(ulong)FileReadLong(file);
      CleanupOrders[i].ask=(ulong)FileReadLong(file);CleanupOrders[i].price=(ulong)FileReadLong(file);
      if(FileReadLong(file)!=0) Fail(409);
      CleanupOrders[i].freeze=FileReadLong(file);CleanupOrders[i].tick_ok=FileReadInteger(file);
      bool is_null=false;CleanupOrders[i].symbol=ReadText(file,is_null);
   }
   DoubleBits n;
   for(int i=0;i<100;i++)
      for(int j=0;j<2;j++) { n.bits=(ulong)FileReadLong(file);CleanupResults[i][j]=n.value; }
   return FileTell(file)<=FileSize(file);
}
void WriteCleanupState()
{
   FileWriteLong(OutputFile,(long)SelectedOrder);DoubleBits n;
   for(int i=0;i<100;i++)
      for(int j=0;j<2;j++) { n.value=CleanupResults[i][j];FileWriteLong(OutputFile,(long)n.bits); }
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   { ushort c=StringGetCharacter(CheckRun,i);if(!((c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='-')) return 4; }
   string folder="bot3-evaluation-pending-cleanup\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   InputFile=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(InputFile==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(InputFile),version=FileReadInteger(InputFile),count=FileReadInteger(InputFile);
   if(magic!=CLEANUP_MAGIC || version!=1 || count<1 || count>10000) { FileClose(InputFile);return 7; }
   OutputFile=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(OutputFile==INVALID_HANDLE) { FileClose(InputFile);return 8; }
   FileWriteInteger(OutputFile,CLEANUP_MAGIC);FileWriteInteger(OutputFile,1);FileWriteInteger(OutputFile,count);FileWriteInteger(OutputFile,31);
   for(int row=0;row<count;row++)
   {
      if(!ReadCase(InputFile) || !ReadStopCase(InputFile) || !ReadCleanupCase(InputFile)) { Fail(410);break; }
      if(CurrentCase.id!=row) Fail(411);
      FileWriteInteger(OutputFile,CurrentCase.id);SelectedPosition=-1;SelectedOrder=-1;StopChanged=false;TimeTextCall=0;
      ZeroMemory(ActiveInputs);ActiveInputs.symbol=CurrentCase.symbol;ActiveInputs.native_1d6e28=CurrentCase.native_symbol;
      ActiveInputs.native_1d6d08=CurrentCase.native_1d6d08;
      ActiveStop.enabled=(uchar)StopCase.enabled;ActiveStop.magic=StopCase.magic;DoubleBits n;
      n.bits=StopCase.stop;ActiveStop.stop_distance=n.value;n.bits=StopCase.target;ActiveStop.target_distance=n.value;
      n.bits=StopCase.unit;ActiveStop.unit=n.value;SeedStopTrade();
      Bot3EvaluationPreludeState state;InitPrefix(state);
      Bot3PrepareEvaluation(CurrentCase.index,CurrentCase.caller_flag,ActiveInputs,state);
      EndEvents();WriteFinal(state);
      Bot3CleanEvaluationPending(CurrentCase.caller_flag,ActiveStop.magic,ActiveInputs.symbol,CleanupResults,ActiveTrade,ActiveOptions);
      Bot3FillEvaluationStops(ActiveInputs.symbol,ActiveStop,ActiveTrade,ActiveOptions);
      EndEvents();WriteStopTrade();WriteStopContext();WriteCleanupState();
   }
   if(FileTell(InputFile)!=FileSize(InputFile)) Fail(412);
   FileClose(InputFile);FileClose(OutputFile);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);return Fault;
}
