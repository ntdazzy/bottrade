#property script_show_inputs
#include "Bot1PipelineApi.mqh"
#include <bot-cua-toi-1/Bot1TradeSend.mqh>
#include <bot-cua-toi-1/Bot1TradeErrors.mqh>
#define Bot1OpenPending QueueOpenPending
#define GetLastError QueueLastError
#define Sleep QueueSleep
#define Print QueuePrint
#include <bot-cua-toi-1/Bot1PendingQueue.mqh>
#undef Bot1OpenPending
#undef GetLastError
#undef Sleep
#undef Print
Bot1PendingQueue CheckQueue;
Bot1PendingQueueContext CheckContext;
Bot1PendingRequestState CheckTrade;
Bot1TradeSendOptions CheckOptions;
int CheckOutput=INVALID_HANDLE,CheckError=0,CheckScenario=0,CheckFocus=0;
int CheckSends=0,CheckSleeps=0,CheckPrints=0,CheckReplyCount=0;
int CheckReplies[20][2];bool CheckBad=false;
void WriteText(const int file,const string text)
{
   int n=StringLen(text);FileWriteInteger(file,n,INT_VALUE);
   if(n>0) FileWriteString(file,text,n);
}
string QueueReadText(const int file)
{
   int n=FileReadInteger(file,INT_VALUE);
   if(n<0 || n>4096) { CheckBad=true;return ""; }
   return n>0 ? FileReadString(file,n) : "";
}
void ApplyBoundaryChange(const int api)
{
   int s=CheckScenario,i=CheckFocus;
   if(api==2 && CheckSends==1)
   {
      if(s==1) CheckQueue.orders[i][0]+=.375;
      if(s==2 || s==10)
      {
         CheckQueue.orders[i][0]=s==2 ? 99.0 : -7.5;CheckQueue.orders[i][1]=5.0;CheckContext.bid=s==2 ? 101.0 : 0.0;
      }
      if(s==3 || s==4) CheckQueue.enabled=(uchar)(s==3 ? 2 : 3);
      if(s==7) { CheckQueue.results[0][0]=17.;CheckQueue.results[0][1]=111.;CheckQueue.results[1][0]=0.;CheckQueue.results[1][1]=222.; }
   }
   if((api==1 && CheckPrints==1 && s==6) || (api==3 && CheckSleeps==1 && s==5))
   {
      CheckQueue.orders[i][0]=-7.5;CheckQueue.orders[i][1]=s==5 ? 6.0 : 4.0;CheckQueue.orders[i][2]=.333;
      CheckContext.sl_distance=-2.5;CheckContext.tp_distance=3.75;CheckContext.unit=.125;
      CheckContext.ask=-99.;CheckContext.bid=100.;CheckContext.gap=10000.;CheckContext.expiration_base=-172801;
      CheckContext.symbol="Vàng.x";CheckContext.comment="Vé mới";
   }
   if((api==1 && CheckPrints==1 && s==8) || (api==3 && CheckSleeps==1 && s==9)) CheckQueue.enabled=0;
   if(api==3 && CheckSleeps==1 && s==11) CheckError=0;
   if(api==1 && CheckPrints==1 && s==12) { CheckQueue.orders[i][0]=CheckQueue.orders[i][2];CheckQueue.orders[i][2]=.333; }
   if(api==1 && CheckPrints==1 && s==13) { CheckQueue.orders[i][0]=-0.0;CheckContext.sl_distance=-0.0;CheckContext.tp_distance=-0.0;CheckContext.unit=1.0; }
}
int QueueLastError() { return CheckError; }
void QueuePrint(const string text)
{
   FileWriteInteger(CheckOutput,1,INT_VALUE);WriteText(CheckOutput,text);CheckPrints++;ApplyBoundaryChange(1);
}
void QueueSleep(const int ms)
{
   FileWriteInteger(CheckOutput,3,INT_VALUE);FileWriteInteger(CheckOutput,ms,INT_VALUE);CheckSleeps++;ApplyBoundaryChange(3);
   if(ms!=2500 || CheckSleeps>200) { CheckBad=true;CheckError=0;CheckQueue.enabled=0; }
}
int PipelinePlannedSendError=0,PipelinePropertyError=0,PipelineActualSends=0;
void PipelineSendComplete() { CheckError=PipelinePlannedSendError;PipelineActualSends++; }
void PipelinePropertyComplete(const bool ok) { if(!ok) CheckError=PipelinePropertyError; }
void SeedPipelineCheck(MqlTradeCheckResult &value)
{
   value.retcode=301;value.balance=1301.25;value.equity=1302.25;value.profit=1303.25;
   value.margin=1304.25;value.margin_free=1305.25;value.margin_level=1306.25;value.comment="TRADE_LAYOUT_CHECK";
}
void WriteTradeState(const int file,const Bot1PendingRequestState &state)
{
   FileWriteLong(file,(long)state.magic);FileWriteInteger(file,(int)state.preferred);
   WriteRequest(file,state.request);WriteResult(file,state.result);
   FileWriteInteger(file,(int)state.check.retcode);FileWriteDouble(file,state.check.balance);FileWriteDouble(file,state.check.equity);
   FileWriteDouble(file,state.check.profit);FileWriteDouble(file,state.check.margin);FileWriteDouble(file,state.check.margin_free);
   FileWriteDouble(file,state.check.margin_level);FileWriteLong(file,(long)TextHash(state.check.comment));
   Text(file,state.request.symbol);Text(file,state.request.comment);Text(file,state.result.comment);Text(file,state.check.comment);
}
bool QueueOpenPending(Bot1PendingRequestState &trade,Bot1TradeSendOptions &options,
                      const int magic,const uchar virtual_expiration,const string symbol,
                      const ENUM_ORDER_TYPE type,const double volume,const double price,
                      const double sl,const double tp,const string comment,const datetime expiration)
{
   FileWriteInteger(CheckOutput,2,INT_VALUE);FileWriteInteger(CheckOutput,(int)type,INT_VALUE);
   FileWriteInteger(CheckOutput,magic,INT_VALUE);FileWriteInteger(CheckOutput,(int)virtual_expiration,INT_VALUE);
   FileWriteDouble(CheckOutput,volume);FileWriteDouble(CheckOutput,price);FileWriteDouble(CheckOutput,sl);FileWriteDouble(CheckOutput,tp);
   FileWriteLong(CheckOutput,(long)expiration);WriteText(CheckOutput,symbol);WriteText(CheckOutput,comment);
   Event(10);Text(fixture,"5");Text(fixture,(string)(uint)type);Text(fixture,"0");Text(fixture,(string)supplied_result.retcode);WriteTradeState(fixture,trade);
   accepted_value=true;PipelinePlannedSendError=0;
   if(CheckReplyCount>0)
   {
      if(CheckSends>=CheckReplyCount) { CheckBad=true;CheckQueue.enabled=0; }
      else { accepted_value=CheckReplies[CheckSends][0]!=0;PipelinePlannedSendError=CheckReplies[CheckSends][1]; }
   }
   property_index[0]=0;property_index[1]=0;pending_execution_index=0;pending_filling_index=0;pending_expiration_index=0;
   bool accepted=Bot1OpenPending(trade,options,magic,virtual_expiration,symbol,type,volume,price,sl,tp,comment,expiration);
   Event(11);FileWriteInteger(fixture,(int)accepted);WriteTradeState(fixture,trade);
   CheckSends++;ApplyBoundaryChange(2);
   if(CheckSends>200) { CheckBad=true;CheckError=0;CheckQueue.enabled=0; }
   return accepted;
}
void WriteState()
{
   FileWriteInteger(CheckOutput,0,INT_VALUE);FileWriteInteger(CheckOutput,(int)CheckQueue.enabled,INT_VALUE);
   FileWriteInteger(CheckOutput,(int)CheckQueue.error_count,INT_VALUE);FileWriteInteger(CheckOutput,CheckError,INT_VALUE);
   FileWriteInteger(CheckOutput,CheckSends,INT_VALUE);FileWriteInteger(CheckOutput,CheckSleeps,INT_VALUE);FileWriteInteger(CheckOutput,CheckPrints,INT_VALUE);
   for(int i=0;i<100;i++) for(int k=0;k<3;k++) FileWriteDouble(CheckOutput,CheckQueue.orders[i][k]);
   for(int i=0;i<100;i++) for(int k=0;k<2;k++) FileWriteDouble(CheckOutput,CheckQueue.results[i][k]);
   FileWriteDouble(CheckOutput,CheckContext.ask);FileWriteDouble(CheckOutput,CheckContext.bid);FileWriteDouble(CheckOutput,CheckContext.gap);
   FileWriteDouble(CheckOutput,CheckContext.sl_distance);FileWriteDouble(CheckOutput,CheckContext.tp_distance);FileWriteDouble(CheckOutput,CheckContext.unit);
   FileWriteLong(CheckOutput,(long)CheckContext.expiration_base);FileWriteInteger(CheckOutput,CheckContext.strategy_magic,INT_VALUE);
   FileWriteInteger(CheckOutput,(int)CheckContext.virtual_expiration,INT_VALUE);WriteText(CheckOutput,CheckContext.symbol);WriteText(CheckOutput,CheckContext.comment);
}
int OnStart()
{
   int length=StringLen(CheckRun);
   if(length<1 || length>48) return 1;
   for(int k=0;k<length;k++)
   {
      ushort c=StringGetCharacter(CheckRun,k);
      if(!((c>=97 && c<=122) || (c>=48 && c<=57) || c==45)) return 2;
   }
   pending_mode=true;
   string folder="bot1-pending-pipeline\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN|FILE_UNICODE);
   if(input_file==INVALID_HANDLE) return 3;
   int magic=FileReadInteger(input_file,INT_VALUE),version=FileReadInteger(input_file,INT_VALUE),count=FileReadInteger(input_file,INT_VALUE);
   if(magic!=0x51465331 || version!=1 || count<1 || count>20000) { FileClose(input_file);return 4; }
   CheckOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   fixture=FileOpen(folder+"api-fixtures.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(CheckOutput==INVALID_HANDLE || fixture==INVALID_HANDLE)
   { FileClose(input_file);if(CheckOutput!=INVALID_HANDLE) FileClose(CheckOutput);if(fixture!=INVALID_HANDLE) FileClose(fixture);return 5; }
   FileWriteInteger(CheckOutput,magic);FileWriteInteger(CheckOutput,version);FileWriteInteger(CheckOutput,count);
   FileWriteInteger(fixture,magic);FileWriteInteger(fixture,version);FileWriteInteger(fixture,count);Text(fixture,_Symbol);FileWriteInteger(fixture,_Digits);
   for(int i=0;i<count;i++)
   {
      CheckBad=false;api_error=false;CheckSends=0;CheckSleeps=0;CheckPrints=0;PipelineActualSends=0;
      int id=FileReadInteger(input_file,INT_VALUE);CheckScenario=FileReadInteger(input_file,INT_VALUE);CheckFocus=FileReadInteger(input_file,INT_VALUE);
      CheckQueue.enabled=(uchar)FileReadInteger(input_file,INT_VALUE);CheckQueue.error_count=(uint)FileReadInteger(input_file,INT_VALUE);CheckError=FileReadInteger(input_file,INT_VALUE);
      CheckContext.ask=FileReadDouble(input_file);CheckContext.bid=FileReadDouble(input_file);CheckContext.gap=FileReadDouble(input_file);
      CheckContext.sl_distance=FileReadDouble(input_file);CheckContext.tp_distance=FileReadDouble(input_file);CheckContext.unit=FileReadDouble(input_file);
      CheckContext.expiration_base=(datetime)FileReadLong(input_file);CheckContext.strategy_magic=FileReadInteger(input_file,INT_VALUE);CheckContext.virtual_expiration=(uchar)FileReadInteger(input_file,INT_VALUE);
      CheckContext.symbol=QueueReadText(input_file);CheckContext.comment=QueueReadText(input_file);
      for(int j=0;j<100;j++) for(int k=0;k<3;k++) CheckQueue.orders[j][k]=FileReadDouble(input_file);
      for(int j=0;j<100;j++) for(int k=0;k<2;k++) CheckQueue.results[j][k]=FileReadDouble(input_file);
      CheckReplyCount=FileReadInteger(input_file,INT_VALUE);
      if(id!=i || CheckFocus<0 || CheckFocus>=100 || CheckScenario<0 || CheckScenario>13 || CheckReplyCount<0 || CheckReplyCount>20 || CheckBad)
      { FileClose(input_file);FileClose(CheckOutput);FileClose(fixture);return 6; }
      for(int j=0;j<CheckReplyCount;j++) { CheckReplies[j][0]=FileReadInteger(input_file,INT_VALUE);CheckReplies[j][1]=FileReadInteger(input_file,INT_VALUE); }
      case_id=FileReadInteger(input_file);
      CheckOptions.async_mode=(uchar)FileReadInteger(input_file);CheckOptions.log_level=FileReadInteger(input_file);CheckOptions.margin_mode=FileReadInteger(input_file);
      accepted_value=(bool)FileReadInteger(input_file);write_result=(bool)FileReadInteger(input_file);
      for(int j=0;j<2;j++) digits_values[j]=FileReadLong(input_file);
      for(int j=0;j<2;j++) execution_values[j]=FileReadLong(input_file);
      for(int j=0;j<2;j++) digits_ok[j]=(bool)FileReadInteger(input_file);
      for(int j=0;j<2;j++) execution_ok[j]=(bool)FileReadInteger(input_file);
      ReadRequest(input_file,CheckTrade.request);ReadResult(input_file,CheckTrade.result);ReadResult(input_file,supplied_result);
      SeedPipelineCheck(CheckTrade.check);CheckTrade.magic=0x7654321076543210;
      pending_stopped=(bool)FileReadInteger(input_file);CheckTrade.preferred=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(input_file);
      pending_executions[0]=FileReadLong(input_file);pending_filling[0]=FileReadLong(input_file);
      pending_executions[1]=FileReadLong(input_file);pending_filling[1]=FileReadLong(input_file);
      pending_auto_expiration=FileReadLong(input_file);pending_order_flags=FileReadLong(input_file);pending_order_ok=(bool)FileReadInteger(input_file);
      pending_expiration[0]=FileReadLong(input_file);pending_expiration_ok[0]=(bool)FileReadInteger(input_file);
      pending_expiration[1]=FileReadLong(input_file);pending_expiration_ok[1]=(bool)FileReadInteger(input_file);PipelinePropertyError=FileReadInteger(input_file);
      bool expected_seed=CheckReplyCount>0 ? CheckReplies[0][0]!=0 : true;
      if(case_id!=id || accepted_value!=expected_seed || api_error || CheckBad) { FileClose(input_file);FileClose(CheckOutput);FileClose(fixture);return 7; }
      event_count=0;print_count=0;printed_hash=0;
      Event(12);FileWriteInteger(fixture,2+CheckReplyCount);
      FileWriteInteger(fixture,CheckError);Text(fixture,(string)CheckError);
      FileWriteInteger(fixture,PipelinePropertyError);Text(fixture,(string)PipelinePropertyError);
      for(int j=0;j<CheckReplyCount;j++) { FileWriteInteger(fixture,CheckReplies[j][1]);Text(fixture,(string)CheckReplies[j][1]); }
      FileWriteInteger(CheckOutput,id);Bot1ProcessPendingQueue(CheckQueue,CheckContext,CheckTrade,CheckOptions);WriteState();
      WriteTradeState(CheckOutput,CheckTrade);FileWriteInteger(CheckOutput,event_count);FileWriteInteger(CheckOutput,PipelineActualSends);
      FileWriteInteger(CheckOutput,print_count);FileWriteLong(CheckOutput,(long)printed_hash);
      if(CheckBad || api_error || (CheckReplyCount>0 && CheckSends!=CheckReplyCount)) { FileClose(input_file);FileClose(CheckOutput);FileClose(fixture);return 8; }
   }
   bool consumed=FileTell(input_file)==FileSize(input_file);FileClose(input_file);FileClose(CheckOutput);FileClose(fixture);
   if(!consumed) return 9;
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 10;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
