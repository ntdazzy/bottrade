#property strict
#property tester_file "b3-pendingselection-engine-selection-b3-r2.bin"
#include "Bot3PipelineApi.mqh"

int SelectionKind=0,SelectionScenario=0,SelectionTotal=0,SelectionMagic=0,SelectionSelected=-1,SelectionOrderCount=0;
int SelectionTicketCalls=0,SelectionIntegerCalls=0,SelectionStringCalls=0,SelectionCancelCalls=0,SelectionPrints=0;
int SelectionOrderNull[100],SelectionPriceReads[100];
ulong SelectionLastTicket=0,SelectionOrderTickets[100],SelectionPrintHash=0;
long SelectionOrderMagic[100],SelectionOrderTypes[100];
string SelectionSymbol,SelectionOrderSymbols[100];
double SelectionPriceFirst[100],SelectionPriceSecond[100],SelectionResults[100][2];
bool SelectionCancelling=false;
void SelectionChange(const int api,const ulong ticket=0)
{
   if(api==21 && SelectionTicketCalls==1 && SelectionScenario==1)
   { SelectionMagic=-1;SelectionSymbol="Renamed"; }
   if(api==22 && SelectionIntegerCalls==1 && SelectionScenario==2) SelectionMagic=43;
   if(api==23 && SelectionStringCalls==1 && SelectionScenario==3) SelectionSymbol="Renamed";
   if(api==10 && SelectionScenario==4)
   { SelectionLastTicket=(ulong)0xdeadbeef12345678;SelectionResults[0][0]=(double)(long)ticket;SelectionResults[0][1]=-7.5; }
}
int SelectionOrdersTotal()
{
   Event(20);FileWriteInteger(fixture,SelectionTotal);return SelectionTotal;
}
ulong SelectionOrderGetTicket(const int index)
{
   ulong ticket=0;
   if(index>=0 && index<SelectionOrderCount) ticket=SelectionOrderTickets[index];
   if(ticket!=0) SelectionSelected=index;
   Event(21);FileWriteInteger(fixture,index);FileWriteLong(fixture,(long)ticket);FileWriteInteger(fixture,SelectionSelected);
   SelectionTicketCalls++;SelectionChange(21);return ticket;
}
long SelectionInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{
   long value=0;
   if(SelectionSelected<0 || SelectionSelected>=SelectionOrderCount) api_error=true;
   else if(property==ORDER_MAGIC) value=SelectionOrderMagic[SelectionSelected];
   else if(property==ORDER_TYPE) value=SelectionOrderTypes[SelectionSelected];
   else api_error=true;
   Event(22);FileWriteInteger(fixture,(int)property);FileWriteLong(fixture,value);
   SelectionIntegerCalls++;SelectionChange(22);return value;
}
string SelectionString(const ENUM_ORDER_PROPERTY_STRING property)
{
   string value;
   if(property!=ORDER_SYMBOL || SelectionSelected<0 || SelectionSelected>=SelectionOrderCount) api_error=true;
   else if(SelectionOrderNull[SelectionSelected]!=0) value=NULL;
   else value=SelectionOrderSymbols[SelectionSelected];
   Event(23);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,(int)(value==NULL));Text(fixture,value);
   SelectionStringCalls++;SelectionChange(23);return value;
}
double SelectionDouble(const ENUM_ORDER_PROPERTY_DOUBLE property)
{
   double value=0.0;int read=0;
   if(property!=ORDER_PRICE_OPEN || SelectionSelected<0 || SelectionSelected>=SelectionOrderCount) api_error=true;
   else
   {
      read=SelectionPriceReads[SelectionSelected]++;
      if(read>1) api_error=true;
      value=read==0 ? SelectionPriceFirst[SelectionSelected] : SelectionPriceSecond[SelectionSelected];
   }
   Event(24);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,read);FileWriteDouble(fixture,value);return value;
}
void SelectionPrint(const string message)
{
   Event(25);Text(fixture,message);SelectionPrints++;SelectionPrintHash=TextHash(message);
}

Bot3PendingRequestState CancelState;
Bot3TradeSendOptions CancelOptions;
int CancelSelected=0,CancelOrderNull=0,CancelTickOk=0;
int CancelActualSends=0,CancelFormatFailures=0,CancelEarlyPrints=0;
long CancelType=0,CancelFreeze=0;
double CancelPoint=0.0,CancelBid=0.0,CancelAsk=0.0,CancelPrice=0.0;
string CancelSymbol;
void PipelineSendComplete() { CancelActualSends++; }
void PipelinePropertyComplete(const bool ok) { if(!ok) CancelFormatFailures++; }
bool CancelSelect(const ulong ticket)
{
   SelectionCancelling=true;SelectionCancelCalls++;
   Event(10);FileWriteLong(fixture,(long)ticket);FileWriteInteger(fixture,(int)(CancelSelected!=0));
   if(CancelSelected!=0)
   {
      bool found=false;
      for(int i=0;i<SelectionOrderCount;i++) if(SelectionOrderTickets[i]==ticket) { SelectionSelected=i;found=true;break; }
      if(!found) api_error=true;
   }
   SelectionChange(10,ticket);return CancelSelected!=0;
}
string CancelOrderString(const ENUM_ORDER_PROPERTY_STRING property)
{
   if(!SelectionCancelling) return SelectionString(property);
   string value;
   if(CancelOrderNull!=0) value=NULL;else value=CancelSymbol;
   Event(11);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,(int)(value==NULL));Text(fixture,value);
   if(property!=ORDER_SYMBOL) api_error=true;
   return value;
}
double CancelSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   Event(12);FileWriteInteger(fixture,(int)(symbol==NULL));Text(fixture,symbol);FileWriteInteger(fixture,(int)property);FileWriteDouble(fixture,CancelPoint);
   if(property!=SYMBOL_POINT) api_error=true;
   return CancelPoint;
}
bool CancelSymbolTick(const string symbol,MqlTick &tick)
{
   ZeroMemory(tick);tick.bid=CancelBid;tick.ask=CancelAsk;
   Event(13);FileWriteInteger(fixture,(int)(symbol==NULL));Text(fixture,symbol);FileWriteInteger(fixture,(int)(CancelTickOk!=0));FileWriteDouble(fixture,tick.bid);FileWriteDouble(fixture,tick.ask);
   return CancelTickOk!=0;
}
long CancelSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   Event(14);FileWriteInteger(fixture,(int)(symbol==NULL));Text(fixture,symbol);FileWriteInteger(fixture,(int)property);FileWriteLong(fixture,CancelFreeze);
   if(property!=SYMBOL_TRADE_FREEZE_LEVEL) api_error=true;
   return CancelFreeze;
}
double CancelOrderDouble(const ENUM_ORDER_PROPERTY_DOUBLE property)
{
   if(!SelectionCancelling) return SelectionDouble(property);
   Event(15);FileWriteInteger(fixture,(int)property);FileWriteDouble(fixture,CancelPrice);
   if(property!=ORDER_PRICE_OPEN) api_error=true;
   return CancelPrice;
}
long CancelOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{
   if(!SelectionCancelling) return SelectionInteger(property);
   Event(16);FileWriteInteger(fixture,(int)property);FileWriteLong(fixture,CancelType);
   if(property!=ORDER_TYPE) api_error=true;
   return CancelType;
}
void CancelPrintFormat(const string format,const string method)
{
   CancelEarlyPrints++;MockFormat(format,method);
}
#define OrderSelect CancelSelect
#define OrderGetString CancelOrderString
#define SymbolInfoDouble CancelSymbolDouble
#define SymbolInfoTick CancelSymbolTick
#define SymbolInfoInteger CancelSymbolInteger
#define OrderGetDouble CancelOrderDouble
#define OrderGetInteger CancelOrderInteger
#define IsStopped MockStopped
#define PrintFormat CancelPrintFormat
#define OrdersTotal SelectionOrdersTotal
#define OrderGetTicket SelectionOrderGetTicket
#define Print SelectionPrint
#include <bot-cua-toi-3/Bot3PendingSelection.mqh>
#undef OrdersTotal
#undef OrderGetTicket
#undef Print
#undef OrderSelect
#undef OrderGetString
#undef SymbolInfoDouble
#undef SymbolInfoTick
#undef SymbolInfoInteger
#undef OrderGetDouble
#undef OrderGetInteger
#undef IsStopped
#undef PrintFormat
void SeedCheck(MqlTradeCheckResult &value)
{
   value.retcode=301;value.balance=1301.25;value.equity=1302.25;value.profit=1303.25;
   value.margin=1304.25;value.margin_free=1305.25;value.margin_level=1306.25;value.comment="TRADE_LAYOUT_CHECK";
}
void WriteTradeState(const int file,const Bot3PendingRequestState &state)
{
   FileWriteLong(file,(long)state.magic);FileWriteInteger(file,(int)state.preferred);
   WriteRequest(file,state.request);WriteResult(file,state.result);
   FileWriteInteger(file,(int)state.check.retcode);FileWriteDouble(file,state.check.balance);FileWriteDouble(file,state.check.equity);
   FileWriteDouble(file,state.check.profit);FileWriteDouble(file,state.check.margin);FileWriteDouble(file,state.check.margin_free);
   FileWriteDouble(file,state.check.margin_level);FileWriteLong(file,(long)TextHash(state.check.comment));
   Text(file,state.request.symbol);Text(file,state.request.comment);Text(file,state.result.comment);Text(file,state.check.comment);
   FileWriteInteger(file,(int)(state.request.symbol==NULL));FileWriteInteger(file,(int)(state.request.comment==NULL));
   FileWriteInteger(file,(int)(state.result.comment==NULL));FileWriteInteger(file,(int)(state.check.comment==NULL));
}
int RunQueueCheck()
{
   pending_mode=true;string folder="bot3-pending-selection\\"+CheckRun+"\\";
   int file=FileOpen("b3-pendingselection-engine-selection-b3-r2.bin",FILE_READ|FILE_BIN|FILE_UNICODE);if(file==INVALID_HANDLE) return 3;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x53454c31 || version!=1 || count<1 || count>20000) { FileClose(file);return 4; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);fixture=FileOpen(folder+"api-fixtures.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(output==INVALID_HANDLE || fixture==INVALID_HANDLE) { FileClose(file);if(output!=INVALID_HANDLE) FileClose(output);if(fixture!=INVALID_HANDLE) FileClose(fixture);return 5; }
   FileWriteInteger(output,magic);FileWriteInteger(output,2);FileWriteInteger(output,count);
   FileWriteInteger(fixture,magic);FileWriteInteger(fixture,version);FileWriteInteger(fixture,count);Text(fixture,_Symbol);FileWriteInteger(fixture,_Digits);
   for(int i=0;i<count;i++)
   {
      case_id=FileReadInteger(file);CancelOptions.async_mode=(uchar)FileReadInteger(file);CancelOptions.log_level=FileReadInteger(file);CancelOptions.margin_mode=FileReadInteger(file);
      accepted_value=(bool)FileReadInteger(file);write_result=(bool)FileReadInteger(file);
      for(int j=0;j<2;j++) digits_values[j]=FileReadLong(file);
      for(int j=0;j<2;j++) execution_values[j]=FileReadLong(file);
      for(int j=0;j<2;j++) digits_ok[j]=(bool)FileReadInteger(file);
      for(int j=0;j<2;j++) execution_ok[j]=(bool)FileReadInteger(file);
      api_error=false;ReadRequest(file,CancelState.request);ReadResult(file,CancelState.result);ReadResult(file,supplied_result);SeedCheck(CancelState.check);
      CancelSelected=FileReadInteger(file);pending_stopped=FileReadInteger(file)!=0;CancelOrderNull=FileReadInteger(file);
      CancelState.preferred=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(file);CancelType=FileReadLong(file);CancelState.magic=(ulong)FileReadLong(file);CancelTickOk=FileReadInteger(file);
      CancelPoint=FileReadDouble(file);CancelBid=FileReadDouble(file);CancelAsk=FileReadDouble(file);CancelPrice=FileReadDouble(file);CancelFreeze=FileReadLong(file);CancelSymbol=ReadText(file);
      SelectionKind=FileReadInteger(file);SelectionScenario=FileReadInteger(file);SelectionTotal=FileReadInteger(file);SelectionMagic=FileReadInteger(file);
      int symbol_null=FileReadInteger(file);SelectionSelected=FileReadInteger(file);SelectionLastTicket=(ulong)FileReadLong(file);SelectionSymbol=ReadText(file);if(symbol_null!=0) SelectionSymbol=NULL;
      SelectionOrderCount=FileReadInteger(file);
      if(case_id!=i || SelectionKind<0 || SelectionKind>1 || SelectionScenario<0 || SelectionScenario>4 || SelectionOrderCount<0 || SelectionOrderCount>100 || api_error)
      { FileClose(file);FileClose(output);FileClose(fixture);return 6; }
      for(int j=0;j<SelectionOrderCount;j++)
      {
         SelectionOrderTickets[j]=(ulong)FileReadLong(file);SelectionOrderMagic[j]=FileReadLong(file);SelectionOrderTypes[j]=FileReadLong(file);SelectionOrderNull[j]=FileReadInteger(file);
         SelectionPriceFirst[j]=FileReadDouble(file);SelectionPriceSecond[j]=FileReadDouble(file);SelectionOrderSymbols[j]=ReadText(file);SelectionPriceReads[j]=0;
      }
      for(int row=0;row<100;row++) for(int col=0;col<2;col++) SelectionResults[row][col]=FileReadDouble(file);
      CancelActualSends=0;CancelFormatFailures=0;CancelEarlyPrints=0;event_count=0;print_count=0;printed_hash=0;property_index[0]=0;property_index[1]=0;
      SelectionCancelling=false;SelectionTicketCalls=0;SelectionIntegerCalls=0;SelectionStringCalls=0;SelectionCancelCalls=0;SelectionPrints=0;SelectionPrintHash=0;
      Event(17);Text(fixture,"8");Text(fixture,"0");Text(fixture,"0");Text(fixture,(string)supplied_result.retcode);
      if(SelectionKind==0) Bot3DeleteHighestBuyPending(SelectionMagic,SelectionSymbol,SelectionLastTicket,SelectionResults,CancelState,CancelOptions);
      else Bot3DeleteLowestSellPending(SelectionMagic,SelectionSymbol,SelectionLastTicket,SelectionResults,CancelState,CancelOptions);
      FileWriteInteger(output,case_id);WriteTradeState(output,CancelState);FileWriteLong(output,(long)SelectionLastTicket);
      FileWriteInteger(output,SelectionSelected);FileWriteInteger(output,SelectionMagic);FileWriteInteger(output,(int)(SelectionSymbol==NULL));Text(output,SelectionSymbol);
      FileWriteInteger(output,CancelActualSends);FileWriteInteger(output,CancelFormatFailures);FileWriteInteger(output,CancelEarlyPrints);FileWriteInteger(output,event_count);FileWriteInteger(output,print_count);FileWriteLong(output,(long)printed_hash);
      FileWriteInteger(output,SelectionCancelCalls);FileWriteInteger(output,SelectionPrints);FileWriteLong(output,(long)SelectionPrintHash);
      for(int row=0;row<100;row++) for(int col=0;col<2;col++)
      { DoubleBits value;value.value=SelectionResults[row][col];FileWriteLong(output,(long)value.bits); }
      if(api_error) { FileClose(file);FileClose(output);FileClose(fixture);return 7; }
   }
   bool consumed=FileTell(file)==FileSize(file);FileClose(file);FileClose(output);FileClose(fixture);if(!consumed) return 8;
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}

int OnInit()
{
   int result=RunQueueCheck();
   Print("PENDINGSELECTION_NATIVE_CHECK_EXIT:",result);
   return result==0 ? INIT_SUCCEEDED : INIT_FAILED;
}
void OnTick() { ExpertRemove(); }
