#property strict
// Only two newly created keys in the isolated terminal are touched.
input string CheckRun="";
input bool ReadStored=false;
int clock_calls=0;
int FakeMql(const ENUM_MQL_INFO_INTEGER property) { return 0; }
datetime FakeTime() { datetime values[3]={1000,1001,1002};return values[MathMin(clock_calls++,2)]; }
bool FakeSelect(const datetime from,const datetime to) { return true; }
int FakeTotal() { return 2; }
ulong FakeTicket(const int index) { return (ulong)(index+1); }
long FakeInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property)
{ return property==DEAL_TYPE ? 2 : (long)(ticket+5)*100; }
double FakeDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property) { return ticket==1 ? -100.0 : 100.0; }
void SilentPrint(const string message,const double value) {}
#define MQLInfoInteger FakeMql
#define TimeCurrent FakeTime
#define HistorySelect FakeSelect
#define HistoryDealsTotal FakeTotal
#define HistoryDealGetTicket FakeTicket
#define HistoryDealGetInteger FakeInteger
#define HistoryDealGetDouble FakeDouble
#define Print SilentPrint
#include "../../Include/bot-cua-toi-3/Bot3Withdrawal.mqh"
int OnStart()
{
   if(CheckRun=="" || StringLen(CheckRun)>40) return 1;
   string peak_key="b3.wd."+CheckRun+".peak",time_key="b3.wd."+CheckRun+".time";
   string folder="bot3-withdrawal-storage\\"+CheckRun+"\\";
   if(!ReadStored)
   {
      if(GlobalVariableCheck(peak_key) || GlobalVariableCheck(time_key)) return 1;
      long last_check=900,last_deal=500;double peak=10000.0;
      Bot3UpdateWithdrawals(true,9000.0,peak_key,time_key,last_check,last_deal,peak);
      if(last_check!=1001 || last_deal!=700 || peak!=9000.0) return 1;
   }
   if(!GlobalVariableCheck(peak_key) || !GlobalVariableCheck(time_key)) return 1;
   double peak=GlobalVariableGet(peak_key),time=GlobalVariableGet(time_key);
   bool correct=peak==9000.0 && time==700.0;
   bool cleaned=true;
   if(ReadStored)
   {
      bool first=GlobalVariableDel(peak_key),second=GlobalVariableDel(time_key);
      cleaned=first && second && !GlobalVariableCheck(peak_key) && !GlobalVariableCheck(time_key);
   }
   int output=FileOpen(folder+(ReadStored ? "read.bin" : "write.bin"),FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) return 1;
   FileWriteInteger(output,0x53544731);FileWriteInteger(output,(int)ReadStored);
   FileWriteInteger(output,(int)correct);FileWriteInteger(output,(int)cleaned);
   FileWriteDouble(output,peak);FileWriteDouble(output,time);FileClose(output);
   return correct && cleaned ? 0 : 1;
}
