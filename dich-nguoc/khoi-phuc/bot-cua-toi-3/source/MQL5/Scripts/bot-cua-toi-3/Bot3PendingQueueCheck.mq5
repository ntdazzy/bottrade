#property script_show_inputs
#include <bot-cua-toi-3/Bot3TradeSend.mqh>
#include <bot-cua-toi-3/Bot3TradeErrors.mqh>
#define Bot3OpenPending QueueOpenPending
#define GetLastError QueueLastError
#define Sleep QueueSleep
#define Print QueuePrint
#include <bot-cua-toi-3/Bot3PendingQueue.mqh>
#undef Bot3OpenPending
#undef GetLastError
#undef Sleep
#undef Print
input string CheckRun="";
Bot3PendingQueue CheckQueue;
Bot3PendingQueueContext CheckContext;
Bot3PendingRequestState CheckTrade;
Bot3TradeSendOptions CheckOptions;
int CheckOutput=INVALID_HANDLE,CheckError=0,CheckScenario=0,CheckFocus=0;
int CheckSends=0,CheckSleeps=0,CheckPrints=0,CheckReplyCount=0;
int CheckReplies[20][2];bool CheckBad=false;
void WriteText(const int file,const string text)
{
   int n=StringLen(text);FileWriteInteger(file,n,INT_VALUE);
   if(n>0) FileWriteString(file,text,n);
}
string ReadText(const int file)
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
bool QueueOpenPending(Bot3PendingRequestState &trade,Bot3TradeSendOptions &options,
                      const int magic,const uchar virtual_expiration,const string symbol,
                      const ENUM_ORDER_TYPE type,const double volume,const double price,
                      const double sl,const double tp,const string comment,const datetime expiration)
{
   FileWriteInteger(CheckOutput,2,INT_VALUE);FileWriteInteger(CheckOutput,(int)type,INT_VALUE);
   FileWriteInteger(CheckOutput,magic,INT_VALUE);FileWriteInteger(CheckOutput,(int)virtual_expiration,INT_VALUE);
   FileWriteDouble(CheckOutput,volume);FileWriteDouble(CheckOutput,price);FileWriteDouble(CheckOutput,sl);FileWriteDouble(CheckOutput,tp);
   FileWriteLong(CheckOutput,(long)expiration);WriteText(CheckOutput,symbol);WriteText(CheckOutput,comment);
   int accepted=1;CheckError=0;
   if(CheckReplyCount>0)
   {
      if(CheckSends>=CheckReplyCount) { CheckBad=true;CheckQueue.enabled=0; }
      else { accepted=CheckReplies[CheckSends][0];CheckError=CheckReplies[CheckSends][1]; }
   }
   CheckSends++;ApplyBoundaryChange(2);
   if(CheckSends>200) { CheckBad=true;CheckError=0;CheckQueue.enabled=0; }
   return accepted!=0;
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
   string folder="bot3-pending-queue\\"+CheckRun+"\\";
   ResetLastError();SetUserError(132);uint first=(uint)GetLastError(),second=(uint)GetLastError();ResetLastError();
   int calibration=FileOpen(folder+"last-error-calibration.bin",FILE_WRITE|FILE_BIN);
   if(calibration==INVALID_HANDLE) return 3;
   FileWriteInteger(calibration,(int)first,INT_VALUE);FileWriteInteger(calibration,(int)second,INT_VALUE);FileClose(calibration);
   if(first==0 || second!=first) return 4;
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN|FILE_UNICODE);
   if(input_file==INVALID_HANDLE) return 5;
   int magic=FileReadInteger(input_file,INT_VALUE),version=FileReadInteger(input_file,INT_VALUE),count=FileReadInteger(input_file,INT_VALUE);
   if(magic!=0x51554531 || version!=1 || count<1 || count>20000) { FileClose(input_file);return 6; }
   CheckOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(CheckOutput==INVALID_HANDLE) { FileClose(input_file);return 7; }
   FileWriteInteger(CheckOutput,magic,INT_VALUE);FileWriteInteger(CheckOutput,version,INT_VALUE);FileWriteInteger(CheckOutput,count,INT_VALUE);
   for(int i=0;i<count;i++)
   {
      CheckBad=false;CheckSends=0;CheckSleeps=0;CheckPrints=0;
      int id=FileReadInteger(input_file,INT_VALUE);CheckScenario=FileReadInteger(input_file,INT_VALUE);CheckFocus=FileReadInteger(input_file,INT_VALUE);
      CheckQueue.enabled=(uchar)FileReadInteger(input_file,INT_VALUE);CheckQueue.error_count=(uint)FileReadInteger(input_file,INT_VALUE);CheckError=FileReadInteger(input_file,INT_VALUE);
      CheckContext.ask=FileReadDouble(input_file);CheckContext.bid=FileReadDouble(input_file);CheckContext.gap=FileReadDouble(input_file);
      CheckContext.sl_distance=FileReadDouble(input_file);CheckContext.tp_distance=FileReadDouble(input_file);CheckContext.unit=FileReadDouble(input_file);
      CheckContext.expiration_base=(datetime)FileReadLong(input_file);CheckContext.strategy_magic=FileReadInteger(input_file,INT_VALUE);CheckContext.virtual_expiration=(uchar)FileReadInteger(input_file,INT_VALUE);
      CheckContext.symbol=ReadText(input_file);CheckContext.comment=ReadText(input_file);
      for(int j=0;j<100;j++) for(int k=0;k<3;k++) CheckQueue.orders[j][k]=FileReadDouble(input_file);
      for(int j=0;j<100;j++) for(int k=0;k<2;k++) CheckQueue.results[j][k]=FileReadDouble(input_file);
      CheckReplyCount=FileReadInteger(input_file,INT_VALUE);
      if(id!=i || CheckFocus<0 || CheckFocus>=100 || CheckScenario<0 || CheckScenario>13 || CheckReplyCount<0 || CheckReplyCount>20 || CheckBad)
      { FileClose(input_file);FileClose(CheckOutput);return 8; }
      for(int j=0;j<CheckReplyCount;j++) { CheckReplies[j][0]=FileReadInteger(input_file,INT_VALUE);CheckReplies[j][1]=FileReadInteger(input_file,INT_VALUE); }
      FileWriteInteger(CheckOutput,id,INT_VALUE);Bot3ProcessPendingQueue(CheckQueue,CheckContext,CheckTrade,CheckOptions);WriteState();
      if(CheckBad || (CheckReplyCount>0 && CheckSends!=CheckReplyCount)) { FileClose(input_file);FileClose(CheckOutput);return 9; }
   }
   bool consumed=FileTell(input_file)==FileSize(input_file);FileClose(input_file);FileClose(CheckOutput);return consumed ? 0 : 10;
}
