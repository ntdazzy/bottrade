#property strict
long MockAccount(const ENUM_ACCOUNT_INFO_INTEGER property);
long MockMqlInfo(const ENUM_MQL_INFO_INTEGER property);
#define AccountInfoInteger MockAccount
#define MQLInfoInteger MockMqlInfo
#include "../../Include/bot-cua-toi-3/Bot3InitializationGate.mqh"
#undef AccountInfoInteger
#undef MQLInfoInteger
input string CheckRun="";
Bot3InitializationGateState State;int Speed,Tester,Effect,EffectValue,AccountCalls,TesterCalls,Errors;
void ApplyEffect(const int stage)
{
   if(Effect/10!=stage)return;
   int field=Effect%10;
   if(field==1)State.active=(uchar)EffectValue;
   else if(field==2)State.dispatch_mode=(uchar)EffectValue;
   else if(field==3)State.m1_enabled=(uchar)EffectValue;
   else if(field==4)Speed=EffectValue;
}
long MockAccount(const ENUM_ACCOUNT_INFO_INTEGER property)
{
   if((int)property!=32 || State.active!=0 || AccountCalls!=0 || TesterCalls!=0)Errors|=1;
   AccountCalls++;ApplyEffect(1);return 0;
}
long MockMqlInfo(const ENUM_MQL_INFO_INTEGER property)
{
   if((int)property!=6 || State.active!=1 || AccountCalls!=1 || TesterCalls!=0)Errors|=2;
   TesterCalls++;ApplyEffect(3);return Tester;
}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-init-sequence\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x49535131 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(file),auth=FileReadInteger(file);Tester=FileReadInteger(file);Speed=FileReadInteger(file);
      State.active=(uchar)FileReadInteger(file);State.dispatch_mode=(uchar)FileReadInteger(file);State.m1_enabled=(uchar)FileReadInteger(file);
      Effect=FileReadInteger(file);EffectValue=FileReadInteger(file);AccountCalls=0;TesterCalls=0;Errors=0;
      Bot3StartInitializationGate(State);ApplyEffect(2);bool allowed=Bot3FinishInitializationGate(auth!=0,Speed,State);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)allowed);FileWriteInteger(output,(int)State.active);FileWriteInteger(output,(int)State.dispatch_mode);FileWriteInteger(output,(int)State.m1_enabled);FileWriteInteger(output,AccountCalls);FileWriteInteger(output,TesterCalls);FileWriteInteger(output,Errors);
   }
   if(FileTell(file)!=FileSize(file))return 5;FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
