#property strict
// Isolated margin reads only; no request is sent to a trading account.
input string CheckRun="";
union DoubleBits { double value;ulong bits; };
ulong ValueBits(const double value) { DoubleBits v;v.value=value;return v.bits; }
int calls,messages;
ulong call_hash;
string account_currency;
double bid,ask,supplied_equity,free_margin,required_margin;
bool tick_ok,calc_ok;
ulong TextHash(const string value)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++) { uint ch=StringGetCharacter(value,i);h^=ch&0xff;h*=(ulong)0x100000001b3;h^=(ch>>8)&0xff;h*=(ulong)0x100000001b3; }
   return h;
}
void Trace(const int size,const ulong a,const ulong b,const ulong c,const ulong d=0,const ulong e=0,const ulong f=0,const ulong g=0)
{
   ulong words[7];words[0]=a;words[1]=b;words[2]=c;words[3]=d;words[4]=e;words[5]=f;words[6]=g;
   for(int n=0;n<size;n++) for(int i=0;i<8;i++) { call_hash^=(words[n]>>(8*i))&0xff;call_hash*=(ulong)0x100000001b3; }
   calls++;
}
string MockString(const ENUM_ACCOUNT_INFO_STRING property)
{ Trace(3,10,(ulong)property,TextHash(account_currency));return account_currency; }
double MockDouble(const ENUM_ACCOUNT_INFO_DOUBLE property)
{ double value=property==ACCOUNT_EQUITY ? supplied_equity : free_margin;Trace(3,11,(ulong)property,ValueBits(value));return value; }
bool MockTick(const string symbol,MqlTick &tick)
{ tick.bid=bid;tick.ask=ask;Trace(5,12,TextHash(symbol),ValueBits(bid),ValueBits(ask),(ulong)tick_ok);return tick_ok; }
bool MockMargin(const ENUM_ORDER_TYPE type,const string symbol,const double volume,const double price,double &margin)
{ margin=required_margin;Trace(7,13,(ulong)type,TextHash(symbol),ValueBits(volume),ValueBits(price),(ulong)calc_ok,ValueBits(margin));return calc_ok; }
void MockPrint(const string message) { messages++; }
#define AccountInfoString MockString
#define AccountInfoDouble MockDouble
#define SymbolInfoTick MockTick
#define OrderCalcMargin MockMargin
#define Print MockPrint
#include "../../Include/bot-cua-toi-3/Bot3Margin.mqh"
string ReadText(const int h) { int n=FileReadInteger(h);return n>0 ? FileReadString(h,n) : ""; }
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-margin\\"+CheckRun+"\\";
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(h==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(h),version=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x4d524731 || version!=1 || count<1) { FileClose(h);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(h);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   int enums[]={ACCOUNT_CURRENCY,ACCOUNT_EQUITY,ACCOUNT_MARGIN_FREE,ORDER_TYPE_BUY,ORDER_TYPE_SELL};
   for(int e=0;e<ArraySize(enums);e++) FileWriteInteger(output,enums[e]);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(h),guard=FileReadInteger(h),type=FileReadInteger(h);
      tick_ok=FileReadInteger(h)!=0;calc_ok=FileReadInteger(h)!=0;
      double volume=FileReadDouble(h);bid=FileReadDouble(h);ask=FileReadDouble(h);supplied_equity=FileReadDouble(h);free_margin=FileReadDouble(h);required_margin=FileReadDouble(h);
      account_currency=ReadText(h);string symbol=ReadText(h);
      calls=0;messages=0;call_hash=(ulong)0xcbf29ce484222325;
      bool result=guard!=0 ? Bot3MarginGuard(symbol,(ENUM_ORDER_TYPE)type,volume) : Bot3MarginAvailable(symbol,volume,(ENUM_ORDER_TYPE)type);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)result);FileWriteInteger(output,calls);FileWriteLong(output,(long)call_hash);FileWriteInteger(output,messages);
   }
   bool exact=FileTell(h)==FileSize(h);FileClose(h);FileClose(output);return exact ? 0 : 1;
}
