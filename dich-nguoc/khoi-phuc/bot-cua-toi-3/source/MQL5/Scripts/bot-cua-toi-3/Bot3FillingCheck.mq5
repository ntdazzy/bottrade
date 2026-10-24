#property strict
input string CheckRun="";
long execution_value=0,filling_flags=0,expiration_flags=0;
bool expiration_ok=false,api_error=false;
int calls=0;
ulong call_hash=0;
ulong TextHash(const string value)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      uint c=StringGetCharacter(value,i);
      h^=c&255;h*=(ulong)0x100000001b3;
      h^=(c>>8)&255;h*=(ulong)0x100000001b3;
   }
   return h;
}
void Trace(const ulong api,const ulong property,const ulong symbol,const ulong value,const ulong ok)
{
   ulong words[5];words[0]=api;words[1]=property;words[2]=symbol;words[3]=value;words[4]=ok;
   for(int i=0;i<5;i++)
      for(int j=0;j<8;j++) { call_hash^=(words[i]>>(8*j))&255;call_hash*=(ulong)0x100000001b3; }
   calls++;
}
long MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   long value=0;
   if(property==SYMBOL_TRADE_EXEMODE) value=execution_value;
   else if(property==SYMBOL_FILLING_MODE) value=filling_flags;
   else api_error=true;
   Trace(1,(ulong)property,TextHash(symbol),(ulong)value,1);
   return value;
}
bool MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value)
{
   if(property!=SYMBOL_EXPIRATION_MODE) api_error=true;
   value=expiration_flags;
   Trace(2,(ulong)property,TextHash(symbol),(ulong)value,(ulong)expiration_ok);
   return expiration_ok;
}
void MockPrint(const string value)
{
   if(value!="CTrade::ExpirationCheck: Unknown expiration type") api_error=true;
   Trace(3,0,TextHash(value),0,0);
}
#define SymbolInfoInteger MockInteger
#define Print MockPrint
#include "../../Include/bot-cua-toi-3/Bot3Filling.mqh"
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-filling\\"+CheckRun+"\\";
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x46494c31 || version!=1 || count<1 || FileSize(source)!=(ulong)12+(ulong)count*60)
   { FileClose(source);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(source);
      execution_value=FileReadLong(source);filling_flags=FileReadLong(source);expiration_flags=FileReadLong(source);
      expiration_ok=(bool)FileReadInteger(source);
      MqlTradeRequest request={};MqlTradeResult result={};
      request.action=(ENUM_TRADE_REQUEST_ACTIONS)FileReadInteger(source);
      request.type=(ENUM_ORDER_TYPE)FileReadInteger(source);
      request.type_time=(ENUM_ORDER_TYPE_TIME)FileReadInteger(source);
      ENUM_ORDER_TYPE_FILLING preferred=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(source);
      request.type_filling=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(source);
      result.retcode=(uint)FileReadInteger(source);
      int symbol_kind=FileReadInteger(source);
      string symbol="XAUUSD";
      if(symbol_kind==1) symbol="";
      else if(symbol_kind==2) symbol=NULL;
      else if(symbol_kind==3) symbol="Vàng";
      calls=0;call_hash=(ulong)0xcbf29ce484222325;api_error=false;
      bool accepted=Bot3CheckFilling(symbol,request,result,preferred);
      FileWriteInteger(output,id);FileWriteInteger(output,api_error ? -2 : (int)accepted);
      FileWriteInteger(output,(int)preferred);FileWriteInteger(output,(int)request.type_filling);
      FileWriteInteger(output,(int)request.type_time);FileWriteInteger(output,(int)result.retcode);
      FileWriteInteger(output,calls);FileWriteLong(output,(long)call_hash);
   }
   bool exact=FileTell(source)==FileSize(source);FileClose(source);FileClose(output);
   return exact ? 0 : 1;
}
