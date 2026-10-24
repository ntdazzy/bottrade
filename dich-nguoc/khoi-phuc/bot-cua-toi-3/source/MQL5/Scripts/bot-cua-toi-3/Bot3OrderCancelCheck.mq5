#property script_show_inputs
#include "Bot3PipelineApi.mqh"
Bot3PendingRequestState CancelState;
Bot3TradeSendOptions CancelOptions;
ulong CancelTicket=0;
int CancelSelected=0,CancelOrderNull=0,CancelTickOk=0;
int CancelActualSends=0,CancelFormatFailures=0,CancelEarlyPrints=0;
long CancelType=0,CancelFreeze=0;
double CancelPoint=0.0,CancelBid=0.0,CancelAsk=0.0,CancelPrice=0.0;
string CancelSymbol;
void PipelineSendComplete() { CancelActualSends++; }
void PipelinePropertyComplete(const bool ok) { if(!ok) CancelFormatFailures++; }
bool CancelSelect(const ulong ticket)
{
   Event(10);FileWriteLong(fixture,(long)ticket);FileWriteInteger(fixture,(int)(CancelSelected!=0));
   if(ticket!=CancelTicket) api_error=true;
   return CancelSelected!=0;
}
string CancelOrderString(const ENUM_ORDER_PROPERTY_STRING property)
{
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
   Event(15);FileWriteInteger(fixture,(int)property);FileWriteDouble(fixture,CancelPrice);
   if(property!=ORDER_PRICE_OPEN) api_error=true;
   return CancelPrice;
}
long CancelOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{
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
#include <bot-cua-toi-3/Bot3OrderCancel.mqh>
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
}
int OnStart()
{
   pending_mode=true;string folder="bot3-order-cancel\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN|FILE_UNICODE);if(file==INVALID_HANDLE) return 3;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x43414e31 || version!=1 || count<1 || count>20000) { FileClose(file);return 4; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);fixture=FileOpen(folder+"api-fixtures.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(output==INVALID_HANDLE || fixture==INVALID_HANDLE) { FileClose(file);if(output!=INVALID_HANDLE) FileClose(output);if(fixture!=INVALID_HANDLE) FileClose(fixture);return 5; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
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
      CancelTicket=(ulong)FileReadLong(file);CancelSelected=FileReadInteger(file);pending_stopped=FileReadInteger(file)!=0;CancelOrderNull=FileReadInteger(file);
      CancelState.preferred=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(file);CancelType=FileReadLong(file);CancelState.magic=(ulong)FileReadLong(file);CancelTickOk=FileReadInteger(file);
      CancelPoint=FileReadDouble(file);CancelBid=FileReadDouble(file);CancelAsk=FileReadDouble(file);CancelPrice=FileReadDouble(file);CancelFreeze=FileReadLong(file);CancelSymbol=ReadText(file);
      if(case_id!=i || api_error) { FileClose(file);FileClose(output);FileClose(fixture);return 6; }
      CancelActualSends=0;CancelFormatFailures=0;CancelEarlyPrints=0;event_count=0;print_count=0;printed_hash=0;property_index[0]=0;property_index[1]=0;
      Event(17);Text(fixture,"8");Text(fixture,"0");Text(fixture,"0");Text(fixture,(string)supplied_result.retcode);
      int value=(int)Bot3DeletePending(CancelState,CancelOptions,CancelTicket);
      FileWriteInteger(output,case_id);FileWriteInteger(output,value);WriteTradeState(output,CancelState);
      FileWriteInteger(output,CancelActualSends);FileWriteInteger(output,CancelFormatFailures);FileWriteInteger(output,CancelEarlyPrints);FileWriteInteger(output,event_count);FileWriteInteger(output,print_count);FileWriteLong(output,(long)printed_hash);
      if(api_error) { FileClose(file);FileClose(output);FileClose(fixture);return 7; }
   }
   bool consumed=FileTell(file)==FileSize(file);FileClose(file);FileClose(output);FileClose(fixture);if(!consumed) return 8;
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
