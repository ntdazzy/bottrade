#property strict
#property tester_file "b3-positionmodify-engine-modify-b3-r1.bin"
// Supplies only IsStopped, position queries and the send reply; production modify/send/messages run.
#include "Bot3PipelineApi.mqh"
Bot3PendingRequestState ModifyState;
Bot3TradeSendOptions ModifyOptions;
int ModifyScenario=0,ModifyStoppedValue=0,ModifySelectOk=0,ModifySymbolNull=0;
int ModifyCalls=0,ModifySelectIndex=0,ModifySymbolIndex=0,ModifySends=0,ModifyFormatFailures=0,ModifyEarlyPrints=0;
ulong ModifyTicket=0,ModifyDeviation=0;
double ModifySL=0.0,ModifyTP=0.0;
string ModifySymbol;
void SeedCheck(MqlTradeCheckResult &value)
{
   value.retcode=301;value.balance=1301.25;value.equity=1302.25;value.profit=1303.25;
   value.margin=1304.25;value.margin_free=1305.25;value.margin_level=1306.25;value.comment="TRADE_LAYOUT_CHECK";
}
void WriteModifyState(const int file)
{
   FileWriteLong(file,(long)ModifyState.magic);FileWriteInteger(file,(int)ModifyState.preferred);
   WriteRequest(file,ModifyState.request);WriteResult(file,ModifyState.result);
   FileWriteInteger(file,(int)ModifyState.check.retcode);FileWriteDouble(file,ModifyState.check.balance);FileWriteDouble(file,ModifyState.check.equity);
   FileWriteDouble(file,ModifyState.check.profit);FileWriteDouble(file,ModifyState.check.margin);FileWriteDouble(file,ModifyState.check.margin_free);
   FileWriteDouble(file,ModifyState.check.margin_level);FileWriteLong(file,(long)TextHash(ModifyState.check.comment));
   Text(file,ModifyState.request.symbol);Text(file,ModifyState.request.comment);Text(file,ModifyState.result.comment);Text(file,ModifyState.check.comment);
   FileWriteInteger(file,(int)(ModifyState.request.symbol==NULL));FileWriteInteger(file,(int)(ModifyState.request.comment==NULL));
   FileWriteInteger(file,(int)(ModifyState.result.comment==NULL));FileWriteInteger(file,(int)(ModifyState.check.comment==NULL));
   FileWriteLong(file,(long)ModifyDeviation);
   FileWriteInteger(file,(int)ModifyOptions.async_mode);FileWriteInteger(file,ModifyOptions.margin_mode);FileWriteInteger(file,ModifyOptions.log_level);
}
void ModifySnapshot() { Event(18);WriteModifyState(fixture); }
// Controlled writes at service boundaries; kiem-sua-vi-the-bot-1-3.py applies the same bytes to the original.
void ModifyChange(const int api)
{
   if(api==20 && ModifySelectIndex==1)
   {
      if(ModifyScenario==1)
      {
         ModifyState.magic=(ulong)0x1111222233334444;ModifyDeviation=77;ModifyState.request.price=11.5;
         ModifyState.result.retcode=4242;ModifyState.check.balance=-3.5;ModifyOptions.log_level=2;
      }
      if(ModifyScenario==7) ModifyStoppedValue=ModifyStoppedValue==0 ? 1 : 0;
   }
   if(api==23 && ModifySymbolIndex==1)
   {
      if(ModifyScenario==2) ModifyState.magic=(ulong)0xfedcba9876543210;
      if(ModifyScenario==3)
      {
         ModifyState.request.price=33.25;ModifyState.request.action=(ENUM_TRADE_REQUEST_ACTIONS)7;ModifyState.request.position=(ulong)0x55;
         ModifyState.request.type_filling=(ENUM_ORDER_TYPE_FILLING)3;ModifyState.request.expiration=(datetime)1234567;
         ModifyState.result.deal=(ulong)99;ModifyState.check.margin=8.5;
      }
      if(ModifyScenario==4)
      {
         ModifyState.request.sl=1.0;ModifyState.request.tp=2.0;ModifyState.request.magic=(ulong)3;ModifyState.request.symbol="changed";
      }
   }
   if(api==1 && ModifySends==1 && ModifyScenario==5) { ModifyState.magic=(ulong)0x0123456789abcdef;ModifyState.request.tp=-7.5; }
   if(api==8 && ModifyEarlyPrints==1 && ModifyScenario==6) { ModifyState.result.retcode=777;ModifyState.request.price=55.5;ModifyState.magic=(ulong)42; }
}
void PipelineSendComplete()
{
   ModifySends++;ModifyChange(1);ModifySnapshot();property_index[0]=0;property_index[1]=0;
}
void PipelinePropertyComplete(const bool ok) { if(!ok) ModifyFormatFailures++; }
bool ModifyStopped() { ModifyCalls++;return ModifyStoppedValue!=0; }
bool ModifySelect(const ulong ticket)
{
   ModifySnapshot();int index=ModifySelectIndex++;
   bool ok=false;if(index<1) ok=ModifySelectOk!=0;else api_error=true;
   if(ticket!=ModifyTicket) api_error=true;
   Event(20);FileWriteInteger(fixture,index);FileWriteLong(fixture,(long)ticket);FileWriteInteger(fixture,(int)ok);
   ModifyChange(20);return ok;
}
string ModifyString(const ENUM_POSITION_PROPERTY_STRING property)
{
   ModifySnapshot();int index=ModifySymbolIndex++;string value;
   if(property!=POSITION_SYMBOL || index>=1) api_error=true;
   else if(ModifySymbolNull!=0) value=NULL;else value=ModifySymbol;
   Event(23);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,index);FileWriteInteger(fixture,(int)(value==NULL));Text(fixture,value);
   ModifyChange(23);return value;
}
void ModifyPrintFormat(const string format,const string method)
{
   ModifySnapshot();ModifyEarlyPrints++;MockFormat(format,method);ModifyChange(8);
}
#define IsStopped ModifyStopped
#define PositionSelectByTicket ModifySelect
#define PositionGetString ModifyString
#define PrintFormat ModifyPrintFormat
#include <bot-cua-toi-3/Bot3PositionModify.mqh>
#undef IsStopped
#undef PositionSelectByTicket
#undef PositionGetString
#undef PrintFormat
int RunQueueCheck()
{
   if(StringLen(CheckRun)==0) return 2;
   pending_mode=true;string folder="bot3-position-modify\\"+CheckRun+"\\";
   int file=FileOpen("b3-positionmodify-engine-modify-b3-r1.bin",FILE_READ|FILE_BIN|FILE_UNICODE);if(file==INVALID_HANDLE) return 3;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4d4f4431 || version!=1 || count<1 || count>30000) { FileClose(file);return 4; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);fixture=FileOpen(folder+"api-fixtures.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(output==INVALID_HANDLE || fixture==INVALID_HANDLE) { FileClose(file);if(output!=INVALID_HANDLE) FileClose(output);if(fixture!=INVALID_HANDLE) FileClose(fixture);return 5; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   FileWriteInteger(fixture,magic);FileWriteInteger(fixture,version);FileWriteInteger(fixture,count);Text(fixture,_Symbol);FileWriteInteger(fixture,_Digits);
   for(int i=0;i<count;i++)
   {
      case_id=FileReadInteger(file);ModifyOptions.async_mode=(uchar)FileReadInteger(file);ModifyOptions.log_level=FileReadInteger(file);ModifyOptions.margin_mode=FileReadInteger(file);
      accepted_value=(bool)FileReadInteger(file);write_result=(bool)FileReadInteger(file);
      for(int j=0;j<2;j++) digits_values[j]=FileReadLong(file);
      for(int j=0;j<2;j++) execution_values[j]=FileReadLong(file);
      for(int j=0;j<2;j++) digits_ok[j]=(bool)FileReadInteger(file);
      for(int j=0;j<2;j++) execution_ok[j]=(bool)FileReadInteger(file);
      api_error=false;ReadRequest(file,ModifyState.request);ReadResult(file,ModifyState.result);ReadResult(file,supplied_result);SeedCheck(ModifyState.check);
      ModifyScenario=FileReadInteger(file);ModifyTicket=(ulong)FileReadLong(file);ModifyState.magic=(ulong)FileReadLong(file);ModifyDeviation=(ulong)FileReadLong(file);
      ModifyStoppedValue=FileReadInteger(file);ModifyState.preferred=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(file);ModifySelectOk=FileReadInteger(file);
      ModifySymbolNull=FileReadInteger(file);ModifySymbol=ReadText(file);ModifySL=FileReadDouble(file);ModifyTP=FileReadDouble(file);
      if(case_id!=i || ModifyScenario<0 || ModifyScenario>7 || (ModifySelectOk!=0 && ModifySelectOk!=1) || (ModifySymbolNull!=0 && ModifySymbolNull!=1) || api_error)
      { FileClose(file);FileClose(output);FileClose(fixture);return 6; }
      ModifyCalls=0;ModifySelectIndex=0;ModifySymbolIndex=0;ModifySends=0;ModifyFormatFailures=0;ModifyEarlyPrints=0;
      event_count=0;print_count=0;printed_hash=0;property_index[0]=0;property_index[1]=0;pending_execution_index=0;pending_filling_index=0;
      Event(17);Text(fixture,(string)(int)TRADE_ACTION_SLTP);Text(fixture,(string)(uint)0);Text(fixture,(string)(uint)0);Text(fixture,(string)supplied_result.retcode);
      bool ok=Bot3ModifyPosition(ModifyState,ModifyOptions,ModifyTicket,ModifySL,ModifyTP);
      FileWriteInteger(output,case_id);FileWriteInteger(output,(int)ok);WriteModifyState(output);
      FileWriteInteger(output,ModifyCalls);FileWriteInteger(output,ModifySelectIndex);FileWriteInteger(output,ModifySymbolIndex);FileWriteInteger(output,ModifySends);
      FileWriteInteger(output,ModifyFormatFailures);FileWriteInteger(output,ModifyEarlyPrints);FileWriteInteger(output,event_count);FileWriteInteger(output,print_count);
      FileWriteLong(output,(long)printed_hash);
      if(api_error) { FileClose(file);FileClose(output);FileClose(fixture);return 7; }
   }
   bool consumed=FileTell(file)==FileSize(file);FileClose(file);FileClose(output);FileClose(fixture);if(!consumed) return 8;
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}

int OnInit()
{
   int result=RunQueueCheck();
   Print("POSITIONMODIFY_NATIVE_CHECK_EXIT:",result);
   return result==0 ? INIT_SUCCEEDED : INIT_FAILED;
}
void OnTick() { ExpertRemove(); }
