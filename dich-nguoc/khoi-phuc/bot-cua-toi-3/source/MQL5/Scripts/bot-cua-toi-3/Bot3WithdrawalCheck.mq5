#property strict
// All terminal writes are mocked; this script never changes real MT5 variables.
input string CheckRun="";
union DoubleBits { double value;ulong bits; };
ulong ValueBits(const double value) { DoubleBits v;v.value=value;return v.bits; }
int calls,clock_calls,select_calls,tester,reported_count;
bool select_ok,restore_ok;
long times[3];
ulong tickets[];
long deal_types[],deal_times[];
double profits[];
ulong call_hash;
void Trace(const int api,const ulong first,const ulong second,const ulong value)
{
   ulong words[4];words[0]=(ulong)api;words[1]=first;words[2]=second;words[3]=value;
   for(int n=0;n<4;n++) for(int i=0;i<8;i++) { call_hash^=(words[n]>>(8*i))&0xff;call_hash*=(ulong)0x100000001b3; }
   calls++;
}
ulong TextHash(const string value)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   { uint ch=StringGetCharacter(value,i);h^=ch&0xff;h*=(ulong)0x100000001b3;h^=(ch>>8)&0xff;h*=(ulong)0x100000001b3; }
   return h;
}
int MockMql(const ENUM_MQL_INFO_INTEGER property) { Trace(10,(ulong)property,0,(ulong)(long)tester);return tester; }
datetime MockTime()
{ long value=times[MathMin(clock_calls,2)];clock_calls++;Trace(11,0,0,(ulong)value);return (datetime)value; }
bool MockSelect(const datetime from,const datetime to)
{ bool value=select_calls==0 ? select_ok : restore_ok;select_calls++;Trace(12,(ulong)from,(ulong)to,(ulong)value);return value; }
int MockTotal() { Trace(13,0,0,(ulong)(long)reported_count);return reported_count; }
ulong MockTicket(const int index)
{ ulong value=index>=0 && index<ArraySize(tickets) ? tickets[index] : 0;Trace(14,(ulong)index,0,value);return value; }
int FindDeal(const ulong ticket) { for(int i=0;i<ArraySize(tickets);i++) if(tickets[i]==ticket) return i;return -1; }
long MockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property)
{
   int index=FindDeal(ticket);long value=index<0 ? 0 : (property==DEAL_TYPE ? deal_types[index] : deal_times[index]);
   Trace(15,ticket,(ulong)property,(ulong)value);return value;
}
double MockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property)
{ int index=FindDeal(ticket);double value=index<0 ? 0.0 : profits[index];Trace(16,ticket,(ulong)property,ValueBits(value));return value; }
datetime MockSet(const string name,const double value) { Trace(17,TextHash(name),0,ValueBits(value));return 0; }
void MockPrint(const string message,const double balance) { Trace(19,0,0,0); }
#define MQLInfoInteger MockMql
#define TimeCurrent MockTime
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define HistoryDealGetInteger MockInteger
#define HistoryDealGetDouble MockDouble
#define GlobalVariableSet MockSet
#define Print MockPrint
#include "../../Include/bot-cua-toi-3/Bot3Withdrawal.mqh"
string ReadText(const int h) { int n=FileReadInteger(h);return n>0 ? FileReadString(h,n) : ""; }
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-withdrawal\\"+CheckRun+"\\";
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(h==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(h),version=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x57445431 || version!=1 || count<1) { FileClose(h);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(h);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   int enums[]={MQL_TESTER,DEAL_TYPE,DEAL_TIME,DEAL_PROFIT};
   for(int e=0;e<ArraySize(enums);e++) FileWriteInteger(output,enums[e]);
   for(int c=0;c<count;c++)
   {
      int id=FileReadInteger(h);bool enabled=FileReadInteger(h)!=0;tester=FileReadInteger(h);
      select_ok=FileReadInteger(h)!=0;restore_ok=FileReadInteger(h)!=0;reported_count=FileReadInteger(h);
      long last_check=FileReadLong(h),last_deal=FileReadLong(h);double peak=FileReadDouble(h),balance=FileReadDouble(h);
      for(int t=0;t<3;t++) times[t]=FileReadLong(h);
      string peak_key=ReadText(h),time_key=ReadText(h);int total=FileReadInteger(h);
      ArrayResize(tickets,total);ArrayResize(deal_types,total);ArrayResize(deal_times,total);ArrayResize(profits,total);
      for(int i=0;i<total;i++) { tickets[i]=(ulong)FileReadLong(h);deal_types[i]=FileReadLong(h);deal_times[i]=FileReadLong(h);profits[i]=FileReadDouble(h); }
      calls=0;clock_calls=0;select_calls=0;call_hash=(ulong)0xcbf29ce484222325;
      Bot3UpdateWithdrawals(enabled,balance,peak_key,time_key,last_check,last_deal,peak);
      FileWriteInteger(output,id);FileWriteLong(output,last_check);FileWriteLong(output,last_deal);FileWriteLong(output,(long)ValueBits(peak));
      FileWriteInteger(output,calls);FileWriteLong(output,(long)call_hash);
   }
   bool exact=FileTell(h)==FileSize(h);FileClose(h);FileClose(output);return exact ? 0 : 1;
}
