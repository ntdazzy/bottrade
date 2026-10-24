#property script_show_inputs
long CloseFillingInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property);
bool CloseFillingInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value);
#define SymbolInfoInteger CloseFillingInteger
#include <bot-cua-toi-3/Bot3Filling.mqh>
#undef SymbolInfoInteger
#include "Bot3PipelineApi.mqh"
Bot3PendingRequestState CloseState;
Bot3TradeSendOptions CloseOptions;
int CloseMode=0,CloseScenario=0,CloseStoppedValue=0,CloseSelectOk[3],CloseSelectIndex=0,CloseTypeIndex=0;
int CloseSLIndex=0,CloseVolumeIndex=0,CloseSymbolIndex=0,ClosePriceIndex=0;
int CloseCalls=0,CloseSends=0,CloseFormatFailures=0,CloseEarlyPrints=0,CloseSymbolNull[2];
ulong CloseTicket=0,CloseDeviation=0;
long ClosePositionMagic=0,CloseTypes[4];
double CloseSL[4],CloseVolumes[2],ClosePrices[2],CloseVariables[4];
string CloseSymbols[2];
void SeedCheck(MqlTradeCheckResult &value)
{
   value.retcode=301;value.balance=1301.25;value.equity=1302.25;value.profit=1303.25;
   value.margin=1304.25;value.margin_free=1305.25;value.margin_level=1306.25;value.comment="TRADE_LAYOUT_CHECK";
}
void WriteCloseState(const int file)
{
   FileWriteLong(file,(long)CloseState.magic);FileWriteInteger(file,(int)CloseState.preferred);
   WriteRequest(file,CloseState.request);WriteResult(file,CloseState.result);
   FileWriteInteger(file,(int)CloseState.check.retcode);FileWriteDouble(file,CloseState.check.balance);FileWriteDouble(file,CloseState.check.equity);
   FileWriteDouble(file,CloseState.check.profit);FileWriteDouble(file,CloseState.check.margin);FileWriteDouble(file,CloseState.check.margin_free);
   FileWriteDouble(file,CloseState.check.margin_level);FileWriteLong(file,(long)TextHash(CloseState.check.comment));
   Text(file,CloseState.request.symbol);Text(file,CloseState.request.comment);Text(file,CloseState.result.comment);Text(file,CloseState.check.comment);
   FileWriteInteger(file,(int)(CloseState.request.symbol==NULL));FileWriteInteger(file,(int)(CloseState.request.comment==NULL));
   FileWriteInteger(file,(int)(CloseState.result.comment==NULL));FileWriteInteger(file,(int)(CloseState.check.comment==NULL));
   FileWriteLong(file,(long)CloseDeviation);
   for(int i=0;i<4;i++) { DoubleBits v;v.value=CloseVariables[i];FileWriteLong(file,(long)v.bits); }
}
void CloseSnapshot() { Event(18);WriteCloseState(fixture); }
void CloseChange(const int api)
{
   if(api==20 && CloseSelectIndex==1 && CloseScenario==1)
   { CloseState.magic=(ulong)0x1111222233334444;CloseDeviation=77; }
   if(api==22 && CloseSLIndex==1 && (CloseScenario==2 || CloseScenario==3))
   {
      CloseVariables[0]=120.0;CloseVariables[1]=130.0;CloseVariables[2]=3.0;CloseVariables[3]=4.0;
      if(CloseScenario==3) { DoubleBits v;v.bits=(ulong)0x7ff0000000000000;CloseVariables[2]=v.value; }
   }
   if(api==22 && CloseVolumeIndex==1 && CloseScenario==4)
   { CloseState.magic=(ulong)0xfedcba9876543210;CloseDeviation=(ulong)0xdeadbeef12345678; }
   if(api==1 && CloseSends==1 && CloseScenario==5) { CloseVariables[0]=200.0;CloseVariables[1]=300.0; }
}
void PipelineSendComplete()
{
   CloseSends++;CloseChange(1);CloseSnapshot();property_index[0]=0;property_index[1]=0;
}
void PipelinePropertyComplete(const bool ok) { if(!ok) CloseFormatFailures++; }
long CloseFillingInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   CloseSnapshot();Event(26);FileWriteInteger(fixture,(int)(symbol==NULL));Text(fixture,symbol);
   return MockInteger(symbol,property);
}
bool CloseFillingInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value)
{
   CloseSnapshot();Event(26);FileWriteInteger(fixture,(int)(symbol==NULL));Text(fixture,symbol);
   return MockInteger(symbol,property,value);
}
bool CloseSelect(const ulong ticket)
{
   CloseSnapshot();int index=CloseSelectIndex++;
   bool ok=false;if(index<3) ok=CloseSelectOk[index]!=0;else api_error=true;
   if(ticket!=CloseTicket) api_error=true;
   Event(20);FileWriteInteger(fixture,index);FileWriteLong(fixture,(long)ticket);FileWriteInteger(fixture,(int)ok);
   CloseChange(20);return ok;
}
long CloseInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   CloseSnapshot();int index=0;long value=0;
   if(property==POSITION_MAGIC) value=ClosePositionMagic;
   else if(property==POSITION_TYPE)
   { index=CloseTypeIndex++;if(index<4) value=CloseTypes[index];else api_error=true; }
   else api_error=true;
   Event(21);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,index);FileWriteLong(fixture,value);return value;
}
double CloseDouble(const ENUM_POSITION_PROPERTY_DOUBLE property)
{
   CloseSnapshot();int index=0;double value=0.0;
   if(property==POSITION_SL) { index=CloseSLIndex++;if(index<4) value=CloseSL[index];else api_error=true; }
   else if(property==POSITION_VOLUME) { index=CloseVolumeIndex++;if(index<2) value=CloseVolumes[index];else api_error=true; }
   else api_error=true;
   Event(22);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,index);FileWriteDouble(fixture,value);
   CloseChange(22);return value;
}
string CloseString(const ENUM_POSITION_PROPERTY_STRING property)
{
   CloseSnapshot();int index=CloseSymbolIndex++;string value;
   if(property!=POSITION_SYMBOL || index>=2) api_error=true;
   else if(CloseSymbolNull[index]!=0) value=NULL;else value=CloseSymbols[index];
   Event(23);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,index);FileWriteInteger(fixture,(int)(value==NULL));Text(fixture,value);return value;
}
double CloseSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   CloseSnapshot();int index=ClosePriceIndex++;double value=0.0;
   if((property!=SYMBOL_BID && property!=SYMBOL_ASK) || index>=2) api_error=true;else value=ClosePrices[index];
   Event(24);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,index);FileWriteInteger(fixture,(int)(symbol==NULL));Text(fixture,symbol);FileWriteDouble(fixture,value);return value;
}
bool CloseStopped() { CloseCalls++;return CloseStoppedValue!=0; }
void ClosePrintFormat(const string format,const string method)
{
   CloseSnapshot();CloseEarlyPrints++;MockFormat(format,method);
}
#define IsStopped CloseStopped
#define PositionSelectByTicket CloseSelect
#define PositionGetInteger CloseInteger
#define PositionGetDouble CloseDouble
#define PositionGetString CloseString
#define SymbolInfoDouble CloseSymbolDouble
#define PrintFormat ClosePrintFormat
#include <bot-cua-toi-3/Bot3PositionClose.mqh>
#undef IsStopped
#undef PositionSelectByTicket
#undef PositionGetInteger
#undef PositionGetDouble
#undef PositionGetString
#undef SymbolInfoDouble
#undef PrintFormat
int OnStart()
{
   pending_mode=true;string folder="bot3-position-close\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN|FILE_UNICODE);if(file==INVALID_HANDLE) return 3;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x50434c31 || version!=1 || count<1 || count>30000) { FileClose(file);return 4; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);fixture=FileOpen(folder+"api-fixtures.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(output==INVALID_HANDLE || fixture==INVALID_HANDLE) { FileClose(file);if(output!=INVALID_HANDLE) FileClose(output);if(fixture!=INVALID_HANDLE) FileClose(fixture);return 5; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   FileWriteInteger(fixture,magic);FileWriteInteger(fixture,version);FileWriteInteger(fixture,count);Text(fixture,_Symbol);FileWriteInteger(fixture,_Digits);
   for(int i=0;i<count;i++)
   {
      case_id=FileReadInteger(file);CloseOptions.async_mode=(uchar)FileReadInteger(file);CloseOptions.log_level=FileReadInteger(file);CloseOptions.margin_mode=FileReadInteger(file);
      accepted_value=(bool)FileReadInteger(file);write_result=(bool)FileReadInteger(file);
      for(int j=0;j<2;j++) digits_values[j]=FileReadLong(file);
      for(int j=0;j<2;j++) execution_values[j]=FileReadLong(file);
      for(int j=0;j<2;j++) digits_ok[j]=(bool)FileReadInteger(file);
      for(int j=0;j<2;j++) execution_ok[j]=(bool)FileReadInteger(file);
      api_error=false;ReadRequest(file,CloseState.request);ReadResult(file,CloseState.result);ReadResult(file,supplied_result);SeedCheck(CloseState.check);
      CloseMode=FileReadInteger(file);CloseScenario=FileReadInteger(file);CloseTicket=(ulong)FileReadLong(file);CloseState.magic=(ulong)FileReadLong(file);CloseDeviation=(ulong)FileReadLong(file);
      CloseStoppedValue=FileReadInteger(file);CloseState.preferred=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(file);ClosePositionMagic=FileReadLong(file);
      for(int j=0;j<3;j++) CloseSelectOk[j]=FileReadInteger(file);
      for(int j=0;j<4;j++) CloseTypes[j]=FileReadLong(file);
      for(int j=0;j<4;j++) CloseSL[j]=FileReadDouble(file);
      for(int j=0;j<2;j++) CloseVolumes[j]=FileReadDouble(file);
      for(int j=0;j<2;j++) ClosePrices[j]=FileReadDouble(file);
      for(int j=0;j<2;j++) { CloseSymbolNull[j]=FileReadInteger(file);CloseSymbols[j]=ReadText(file); }
      for(int j=0;j<2;j++) pending_executions[j]=FileReadLong(file);
      for(int j=0;j<2;j++) pending_filling[j]=FileReadLong(file);
      for(int j=0;j<4;j++) CloseVariables[j]=FileReadDouble(file);
      if(case_id!=i || CloseMode<0 || CloseMode>1 || CloseScenario<0 || CloseScenario>5 || api_error) { FileClose(file);FileClose(output);FileClose(fixture);return 6; }
      CloseSelectIndex=0;CloseTypeIndex=0;CloseSLIndex=0;CloseVolumeIndex=0;CloseSymbolIndex=0;ClosePriceIndex=0;
      CloseCalls=0;CloseSends=0;CloseFormatFailures=0;CloseEarlyPrints=0;event_count=0;print_count=0;printed_hash=0;
      property_index[0]=0;property_index[1]=0;pending_execution_index=0;pending_filling_index=0;
      Event(17);Text(fixture,(string)(int)TRADE_ACTION_DEAL);Text(fixture,(string)(uint)ORDER_TYPE_BUY);Text(fixture,(string)(uint)ORDER_TYPE_SELL);Text(fixture,(string)supplied_result.retcode);
      if(CloseMode==0) Bot3ClosePosition(CloseState,CloseOptions,CloseDeviation,CloseTicket);
      else Bot3TryClosePosition(CloseState,CloseOptions,CloseDeviation,CloseVariables[0],CloseVariables[1],CloseVariables[2],CloseVariables[3],CloseTicket);
      FileWriteInteger(output,case_id);WriteCloseState(output);FileWriteInteger(output,CloseCalls);FileWriteInteger(output,CloseSends);
      FileWriteInteger(output,CloseFormatFailures);FileWriteInteger(output,CloseEarlyPrints);FileWriteInteger(output,event_count);FileWriteInteger(output,print_count);FileWriteLong(output,(long)printed_hash);
      if(api_error) { FileClose(file);FileClose(output);FileClose(fixture);return 7; }
   }
   bool consumed=FileTell(file)==FileSize(file);FileClose(file);FileClose(output);FileClose(fixture);if(!consumed) return 8;
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
