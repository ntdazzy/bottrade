#property strict
input string CheckRun="";
union DoubleBits { double value;ulong bits; };
ulong ValueBits(const double value) { DoubleBits v;v.value=value;return v.bits; }
ulong TextHash(const string value)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      uint ch=StringGetCharacter(value,i);
      h^=ch&0xff;h*=(ulong)0x100000001b3;h^=(ch>>8)&0xff;h*=(ulong)0x100000001b3;
   }
   return h;
}
int calls;
ulong call_hash;
bool api_error;
long login_value,now_value;
double balance_value,equity_value,peak_value,time_value;
bool has_peak,has_time;
string expected_peak_key,expected_time_key;
void Trace(const ulong api,const ulong first,const ulong value)
{
   ulong words[3];words[0]=api;words[1]=first;words[2]=value;
   for(int n=0;n<3;n++) for(int i=0;i<8;i++) { call_hash^=(words[n]>>(8*i))&0xff;call_hash*=(ulong)0x100000001b3; }
   calls++;
}
double MockAccountDouble(const ENUM_ACCOUNT_INFO_DOUBLE property)
{
   if(property!=ACCOUNT_BALANCE && property!=ACCOUNT_EQUITY) api_error=true;
   double value=property==ACCOUNT_BALANCE ? balance_value : equity_value;
   Trace(1,(ulong)property,ValueBits(value));return value;
}
long MockAccountInteger(const ENUM_ACCOUNT_INFO_INTEGER property)
{
   if(property!=ACCOUNT_LOGIN) api_error=true;
   Trace(2,(ulong)property,(ulong)login_value);return login_value;
}
double MockGet(const string name)
{
   double value=0.0;
   if(name==expected_peak_key) value=has_peak ? peak_value : 0.0;
   else if(name==expected_time_key) value=has_time ? time_value : 0.0;
   else api_error=true;
   Trace(5,TextHash(name),ValueBits(value));return value;
}
datetime MockSet(const string name,const double value)
{
   if(name==expected_peak_key) { has_peak=true;peak_value=value; }
   else if(name==expected_time_key) { has_time=true;time_value=value; }
   else api_error=true;
   Trace(3,TextHash(name),ValueBits(value));return 0;
}
bool MockCheck(const string name)
{
   if(name!=expected_time_key) api_error=true;
   Trace(6,TextHash(name),(ulong)has_time);return has_time;
}
datetime MockTime() { Trace(7,(ulong)now_value,0);return (datetime)now_value; }
void MockSleep(const int delay)
{
   if(delay!=5000) api_error=true;
   Trace(4,(ulong)delay,0);
}
void MockPrint(const string message) { if(StringFind(message,"HighestBalance value found: ")!=0) api_error=true; }
#define AccountInfoDouble MockAccountDouble
#define AccountInfoInteger MockAccountInteger
#define GlobalVariableGet MockGet
#define GlobalVariableSet MockSet
#define GlobalVariableCheck MockCheck
#define TimeCurrent MockTime
#define Sleep MockSleep
#define Print MockPrint
#include "../../Include/bot-cua-toi-3/Bot3AccountInitialization.mqh"
void WriteText(const int file,const string value) { FileWriteInteger(file,StringLen(value));FileWriteString(file,value,StringLen(value)); }
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-initial-state\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(input_file==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x494e4931 || version!=1 || count<1) { FileClose(input_file);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(input_file);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(input_file);login_value=FileReadLong(input_file);
      bool reset=FileReadInteger(input_file)!=0,use_equity=FileReadInteger(input_file)!=0;
      double manual=FileReadDouble(input_file);balance_value=FileReadDouble(input_file);equity_value=FileReadDouble(input_file);
      has_peak=FileReadInteger(input_file)!=0;peak_value=FileReadDouble(input_file);
      has_time=FileReadInteger(input_file)!=0;time_value=FileReadDouble(input_file);now_value=FileReadLong(input_file);
      expected_peak_key="HighestBalance"+IntegerToString(login_value);
      expected_time_key="LastBalanceOp"+IntegerToString(login_value);
      calls=0;call_hash=(ulong)0xcbf29ce484222325;api_error=false;
      double current=0.0,peak=0.0;string peak_key="",time_key="";long last_time=0;
      Bot3InitializeAccountState(use_equity,reset,manual,current,peak,peak_key,time_key,last_time);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)api_error);
      FileWriteLong(output,(long)ValueBits(current));FileWriteLong(output,(long)ValueBits(peak));
      FileWriteLong(output,last_time);FileWriteInteger(output,calls);FileWriteLong(output,(long)call_hash);
      WriteText(output,peak_key);WriteText(output,time_key);
   }
   bool exact=FileTell(input_file)==FileSize(input_file);FileClose(input_file);FileClose(output);
   return exact ? 0 : 1;
}
