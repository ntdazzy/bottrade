#property strict
input string CheckRun="";
union DoubleBits { double value;ulong bits; };
ulong ValueBits(const double value) { DoubleBits v;v.value=value;return v.bits; }
int price_count;
ulong price_hash;
double prices[4];
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
void Mix(const ulong value)
{
   for(int i=0;i<8;i++) { price_hash^=(value>>(8*i))&0xff;price_hash*=(ulong)0x100000001b3; }
}
double MockClose(const string symbol,const ENUM_TIMEFRAMES tf,const int shift)
{
   double value=price_count<4 ? prices[price_count] : 0.0;
   Mix(TextHash(symbol));Mix((ulong)tf);Mix((ulong)shift);Mix(ValueBits(value));price_count++;
   return value;
}
#define iClose MockClose
#include "../../Include/bot-cua-toi-1/Bot1Currency.mqh"
string ReadText(const int h) { int length=FileReadInteger(h);return length>0 ? FileReadString(h,length) : ""; }
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot1-currency\\"+CheckRun+"\\";
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(h==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(h),version=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x43555231 || version!=1 || count<1) { FileClose(h);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(h);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(h),to_usd=FileReadInteger(h);double amount=FileReadDouble(h);
      for(int p=0;p<4;p++) prices[p]=FileReadDouble(h);
      string currency=ReadText(h),suffix=ReadText(h);
      price_count=0;price_hash=(ulong)0xcbf29ce484222325;double result=0.0;
      bool ok=Bot1ConvertCurrency(amount,currency,suffix,to_usd!=0,result);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)ok);FileWriteLong(output,ok ? (long)ValueBits(result) : 0);
      FileWriteInteger(output,price_count);FileWriteLong(output,(long)price_hash);
   }
   bool exact=FileTell(h)==FileSize(h);FileClose(h);FileClose(output);return exact ? 0 : 1;
}
