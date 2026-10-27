#property strict
#include "Bot3EvaluationResizeApi.mqh"
#define RESIZE_MAGIC 0x45525333
struct CleanupOrder
{
   ulong ticket;
   long magic,type;
   int select_ok,tick_ok;
   ulong point,bid,ask,price;
   long freeze,expiration;
   ulong sl,tp,volume;
   string comment;
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
   if(property!=ORDER_MAGIC && property!=ORDER_TYPE && property!=ORDER_TIME_EXPIRATION) Fail(402);
   long value=(property==ORDER_MAGIC ? CleanupOrders[SelectedOrder].magic : (property==ORDER_TYPE ? CleanupOrders[SelectedOrder].type : CleanupOrders[SelectedOrder].expiration));
   StopEvent(25,(ulong)property,(ulong)value,(ulong)(long)SelectedOrder);return value;
}
string PendingString(const ENUM_ORDER_PROPERTY_STRING property)
{
   if(!HaveOrder()) return NULL;
   if(property!=ORDER_SYMBOL && property!=ORDER_COMMENT) Fail(403);
   string value=(property==ORDER_SYMBOL ? CleanupOrders[SelectedOrder].symbol : CleanupOrders[SelectedOrder].comment);
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
   if(property!=ORDER_PRICE_OPEN && property!=ORDER_SL && property!=ORDER_TP && property!=(ENUM_ORDER_PROPERTY_DOUBLE)7) Fail(406);
   ulong value=(property==ORDER_PRICE_OPEN ? CleanupOrders[SelectedOrder].price : (property==ORDER_SL ? CleanupOrders[SelectedOrder].sl : (property==ORDER_TP ? CleanupOrders[SelectedOrder].tp : CleanupOrders[SelectedOrder].volume)));
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
void ResizeSleep(const int milliseconds);
bool ObservedResizeDelete(Bot3PendingRequestState &trade,Bot3TradeSendOptions &options,const ulong ticket);
bool ObservedOpen(Bot3PendingRequestState &trade,Bot3TradeSendOptions &options,const int magic,const uchar virtual_expiration,const string symbol,const ENUM_ORDER_TYPE type,const double volume,const double price,const double sl,const double tp,const string comment,const datetime expiration);
#define Bot3OpenPending ObservedOpen
#define Bot3DeletePending ObservedResizeDelete
#define Print ResizePrint
#define Sleep ResizeSleep
#include "../../Include/bot-cua-toi-3/Bot3EvaluationPendingResize.mqh"
#undef Bot3OpenPending
#undef Bot3DeletePending
#undef Sleep
#undef Print
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
uint ResizeIndex=0;
uchar ResizeVirtual=0;
double ResizePercent=0,ResizeVolumes[9];
ulong ResizeLastTicket=0;
long ResizeExecution=0,ResizeFilling=0,ResizeOrderFlags=0,ResizeOrderOK=0;
long ResizeExpirationFlags=0,ResizeExpirationOK=0,ResizeAutoExpiration=0;
int ResizeMutationKind=0;
bool ResizeChanged=false;
string ResizeCastText="";
void ResizeMutation()
{
   if(ResizeChanged) return;
   if(ResizeMutationKind==1) ResizeVolumes[ResizeIndex]=.75;
   else if(ResizeMutationKind==2) ResizeIndex=8;
   else if(ResizeMutationKind==3) ActiveInputs.symbol="Đổi mã";
   else if(ResizeMutationKind==4 && SelectedOrder>=0) CleanupOrders[SelectedOrder].type=5;
   else return;
   ResizeChanged=true;
}
long ResizeSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   long value=0;
   if(property==SYMBOL_TRADE_EXEMODE) value=ResizeExecution;
   else if(property==SYMBOL_FILLING_MODE) value=ResizeFilling;
   else if(property==SYMBOL_EXPIRATION_MODE) value=ResizeAutoExpiration;
   else { Fail(501);return 0; }
   StopEvent(41,(ulong)property,(ulong)value,0,0,0,symbol);return value;
}
bool ResizeSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value)
{
   long ok=0;
   if(property==SYMBOL_ORDER_MODE) { value=ResizeOrderFlags;ok=ResizeOrderOK; }
   else if(property==SYMBOL_EXPIRATION_MODE) { value=ResizeExpirationFlags;ok=ResizeExpirationOK; }
   else { Fail(502);value=0;return false; }
   StopEvent(42,(ulong)property,(ulong)value,(ulong)ok,0,0,symbol);return ok!=0;
}
void ResizePrint(const string value)
{
   if(StringFind(value,"lotsize changed more than ")==0 || StringFind(value,"Lotsize changed more than ")==0)
   {
      DoubleBits n;n.value=ResizePercent;
      // No observable SDK call occurs between the native cast and Print.
      // Both casts are real MT5 conversions, then native input/type are checked.
      StopEvent(43,n.bits,0x58,0,0,0,ResizeCastText);
   }
   StopEvent(32,1,0,0,0,0,value);
}
void ResizePrint(const string a,const string b) { StopEvent(32,2,0,0,0,0,a,b); }
void ResizeSleep(const int milliseconds) { StopEvent(44,(ulong)milliseconds);if(milliseconds!=1000) Fail(503); }
bool ObservedOpen(Bot3PendingRequestState &trade,Bot3TradeSendOptions &options,
                  const int magic,const uchar virtual_expiration,const string symbol,
                  const ENUM_ORDER_TYPE type,const double volume,const double price,
                  const double sl,const double tp,const string comment,const datetime expiration)
{
   DoubleBits a,b,c,d;a.value=volume;b.value=price;c.value=sl;d.value=tp;
   StopEvent(40,(ulong)type,a.bits,b.bits,c.bits,d.bits,symbol,comment,NULL,true);
   return Bot3OpenPending(trade,options,magic,virtual_expiration,symbol,type,volume,price,sl,tp,comment,expiration);
}
bool ObservedResizeDelete(Bot3PendingRequestState &trade,Bot3TradeSendOptions &options,const ulong ticket)
{
   StopEvent(21,ticket,0,0,0,0,NULL,NULL,NULL,true);
   return Bot3DeletePending(trade,options,ticket);
}
bool ReadResizeExtra(const int file)
{
   ResizeIndex=(uint)FileReadInteger(file);ResizeVirtual=(uchar)FileReadInteger(file);DoubleBits n;
   n.bits=(ulong)FileReadLong(file);ResizePercent=n.value;
   for(int i=0;i<9;i++) { n.bits=(ulong)FileReadLong(file);ResizeVolumes[i]=n.value; }
   ResizeExecution=FileReadLong(file);ResizeFilling=FileReadLong(file);ResizeOrderFlags=FileReadLong(file);ResizeOrderOK=FileReadLong(file);
   ResizeExpirationFlags=FileReadLong(file);ResizeExpirationOK=FileReadLong(file);ResizeAutoExpiration=FileReadLong(file);
   ResizeMutationKind=(int)FileReadLong(file);int count=FileReadInteger(file);
   if(count!=ArraySize(CleanupOrders) || ResizeIndex>=9) { Fail(504);return false; }
   for(int i=0;i<count;i++)
   {
      CleanupOrders[i].sl=(ulong)FileReadLong(file);CleanupOrders[i].tp=(ulong)FileReadLong(file);
      CleanupOrders[i].volume=(ulong)FileReadLong(file);CleanupOrders[i].expiration=FileReadLong(file);
      bool is_null=false;CleanupOrders[i].comment=ReadText(file,is_null);
   }
   return FileTell(file)<=FileSize(file);
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   { ushort c=StringGetCharacter(CheckRun,i);if(!((c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='-')) return 4; }
   string folder="bot3-evaluation-pending-resize\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin") || FileIsExist(folder+"cast-results.bin")) return 5;
   InputFile=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(InputFile==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(InputFile),version=FileReadInteger(InputFile),count=FileReadInteger(InputFile);
   if(magic!=RESIZE_MAGIC || version!=1 || count<1 || count>10000) { FileClose(InputFile);return 7; }
   OutputFile=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(OutputFile==INVALID_HANDLE) { FileClose(InputFile);return 8; }
   int casts=FileOpen(folder+"cast-results.bin",FILE_WRITE|FILE_BIN);if(casts==INVALID_HANDLE) { FileClose(InputFile);FileClose(OutputFile);return 9; }
   FileWriteInteger(OutputFile,magic);FileWriteInteger(OutputFile,1);FileWriteInteger(OutputFile,count);FileWriteInteger(OutputFile,200);
   FileWriteInteger(casts,magic);FileWriteInteger(casts,1);FileWriteInteger(casts,count);
   for(int row=0;row<count;row++)
   {
      if(!ReadCase(InputFile) || !ReadStopCase(InputFile) || !ReadCleanupCase(InputFile) || !ReadResizeExtra(InputFile)) { Fail(505);break; }
      if(CurrentCase.id!=row) Fail(506);
      ZeroMemory(ActiveInputs);ActiveInputs.symbol=CurrentCase.symbol;ActiveInputs.native_1d6d08=0;
      ActiveStop.magic=StopCase.magic;SelectedPosition=-1;SelectedOrder=-1;ResizeChanged=false;StopChanged=false;
      SeedStopTrade();ResizeLastTicket=(ulong)0x1122334455667788;
      ResizeCastText=(string)ResizePercent;DoubleBits n;n.value=ResizePercent;
      FileWriteInteger(casts,row);FileWriteLong(casts,(long)n.bits);FileWriteInteger(casts,StringLen(ResizeCastText));
      if(StringLen(ResizeCastText)>0) FileWriteString(casts,ResizeCastText,StringLen(ResizeCastText));
      FileWriteInteger(OutputFile,row);
      Bot3ResizeEvaluationPending(ActiveStop.magic,ResizeVirtual,ActiveInputs.symbol,ResizePercent,ResizeVolumes,
                                  ResizeIndex,ResizeLastTicket,CleanupResults,ActiveTrade,ActiveOptions);
      EndEvents();WriteStopTrade();FileWriteLong(OutputFile,(long)SelectedOrder);FileWriteLong(OutputFile,(long)ResizeLastTicket);
      for(int i=0;i<100;i++)
         for(int j=0;j<2;j++) { n.value=CleanupResults[i][j];FileWriteLong(OutputFile,(long)n.bits); }
      FileWriteLong(OutputFile,(long)ResizeIndex);
      for(int i=0;i<9;i++) { n.value=ResizeVolumes[i];FileWriteLong(OutputFile,(long)n.bits); }
      WriteText(ActiveInputs.symbol);
   }
   if(FileTell(InputFile)!=FileSize(InputFile)) Fail(507);
   FileClose(InputFile);FileClose(OutputFile);FileClose(casts);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 10;
   FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);return Fault;
}
