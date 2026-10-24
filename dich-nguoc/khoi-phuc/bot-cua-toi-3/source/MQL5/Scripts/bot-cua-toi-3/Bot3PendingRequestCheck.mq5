#property strict
input string CheckRun="";
bool stopped=false,order_ok=false,expiration_ok[2],api_error=false;
long executions[2],filling_flags[2],auto_expiration=0,order_flags=0,expiration_flags[2];
int execution_index=0,filling_index=0,expiration_index=0,calls=0;
ulong call_hash=0;
ulong TextHash(const string value)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      uint c=StringGetCharacter(value,i);
      h^=c&255;h*=(ulong)0x100000001b3;h^=(c>>8)&255;h*=(ulong)0x100000001b3;
   }
   return h;
}
void Trace(const ulong api,const ulong property,const ulong a,const ulong b,const ulong ok)
{
   ulong words[5];words[0]=api;words[1]=property;words[2]=a;words[3]=b;words[4]=ok;
   for(int i=0;i<5;i++)
      for(int j=0;j<8;j++) { call_hash^=(words[i]>>(8*j))&255;call_hash*=(ulong)0x100000001b3; }
   calls++;
}
bool MockStopped() { return stopped; }
long MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   long value=0;
   if(property==SYMBOL_TRADE_EXEMODE && execution_index<2) value=executions[execution_index++];
   else if(property==SYMBOL_FILLING_MODE && filling_index<2) value=filling_flags[filling_index++];
   else if(property==SYMBOL_EXPIRATION_MODE) value=auto_expiration;
   else api_error=true;
   Trace(1,(ulong)property,TextHash(symbol),(ulong)value,1);return value;
}
bool MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value)
{
   bool ok=false;
   if(property==SYMBOL_ORDER_MODE) { value=order_flags;ok=order_ok; }
   else if(property==SYMBOL_EXPIRATION_MODE && expiration_index<2)
   { value=expiration_flags[expiration_index];ok=expiration_ok[expiration_index++]; }
   else { api_error=true;value=0; }
   Trace(2,(ulong)property,TextHash(symbol),(ulong)value,(ulong)ok);return ok;
}
void MockPrint(const string value) { Trace(3,0,TextHash(value),0,0); }
void MockPrint(const string a,const string b) { Trace(4,0,TextHash(a),TextHash(b),0); }
void MockFormat(const string format,const string value) { Trace(5,0,TextHash(format),TextHash(value),0); }
#define IsStopped MockStopped
#define SymbolInfoInteger MockInteger
#define Print MockPrint
#define PrintFormat MockFormat
#include "../../Include/bot-cua-toi-3/Bot3PendingRequest.mqh"
void Seed(Bot3PendingRequestState &s)
{
   s.magic=0x7654321076543210;
   s.request.action=(ENUM_TRADE_REQUEST_ACTIONS)101;
   s.request.magic=0x1122334455667788;s.request.order=0x2132435465768798;
   s.request.symbol="TRADE_LAYOUT_SYMBOL";
   s.request.volume=1101.25;s.request.price=1102.25;s.request.stoplimit=1103.25;
   s.request.sl=1104.25;s.request.tp=1105.25;s.request.deviation=0x31425364758697a8;
   s.request.type=(ENUM_ORDER_TYPE)102;s.request.type_filling=(ENUM_ORDER_TYPE_FILLING)103;
   s.request.type_time=(ENUM_ORDER_TYPE_TIME)104;s.request.expiration=(datetime)0x415263748596a7b8;
   s.request.comment="TRADE_LAYOUT_COMMENT";
   s.request.position=0x5162738495a6b7c8;s.request.position_by=0x61728394a5b6c7d8;
   s.result.retcode=201;s.result.deal=0x1234567812345678;s.result.order=0x2345678923456789;
   s.result.volume=1201.25;s.result.price=1202.25;s.result.bid=1203.25;s.result.ask=1204.25;
   s.result.comment="TRADE_LAYOUT_RESULT";s.result.request_id=202;s.result.retcode_external=203;
   s.check.retcode=301;s.check.balance=1301.25;s.check.equity=1302.25;s.check.profit=1303.25;
   s.check.margin=1304.25;s.check.margin_free=1305.25;s.check.margin_level=1306.25;
   s.check.comment="TRADE_LAYOUT_CHECK";
}
void WriteState(const int f,const Bot3PendingRequestState &s)
{
   FileWriteLong(f,(long)s.magic);FileWriteInteger(f,(int)s.preferred);
   FileWriteInteger(f,(int)s.request.action);FileWriteLong(f,(long)s.request.magic);
   FileWriteLong(f,(long)s.request.order);FileWriteLong(f,(long)TextHash(s.request.symbol));
   FileWriteDouble(f,s.request.volume);FileWriteDouble(f,s.request.price);FileWriteDouble(f,s.request.stoplimit);
   FileWriteDouble(f,s.request.sl);FileWriteDouble(f,s.request.tp);FileWriteLong(f,(long)s.request.deviation);
   FileWriteInteger(f,(int)s.request.type);FileWriteInteger(f,(int)s.request.type_filling);
   FileWriteInteger(f,(int)s.request.type_time);FileWriteLong(f,(long)s.request.expiration);
   FileWriteLong(f,(long)TextHash(s.request.comment));FileWriteLong(f,(long)s.request.position);
   FileWriteLong(f,(long)s.request.position_by);
   FileWriteInteger(f,(int)s.result.retcode);FileWriteLong(f,(long)s.result.deal);FileWriteLong(f,(long)s.result.order);
   FileWriteDouble(f,s.result.volume);FileWriteDouble(f,s.result.price);FileWriteDouble(f,s.result.bid);FileWriteDouble(f,s.result.ask);
   FileWriteLong(f,(long)TextHash(s.result.comment));FileWriteInteger(f,(int)s.result.request_id);FileWriteInteger(f,s.result.retcode_external);
   FileWriteInteger(f,(int)s.check.retcode);FileWriteDouble(f,s.check.balance);FileWriteDouble(f,s.check.equity);
   FileWriteDouble(f,s.check.profit);FileWriteDouble(f,s.check.margin);FileWriteDouble(f,s.check.margin_free);
   FileWriteDouble(f,s.check.margin_level);FileWriteLong(f,(long)TextHash(s.check.comment));
}
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-pending-request\\"+CheckRun+"\\";
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x504e4431 || version!=1 || count<1 || FileSize(source)!=(ulong)12+(ulong)count*148)
   { FileClose(source);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(source);stopped=(bool)FileReadInteger(source);
      uchar virtual_expiration=(uchar)FileReadInteger(source);int strategy_magic=FileReadInteger(source);
      ENUM_ORDER_TYPE type=(ENUM_ORDER_TYPE)FileReadInteger(source);
      Bot3PendingRequestState s;Seed(s);s.preferred=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(source);
      executions[0]=FileReadLong(source);filling_flags[0]=FileReadLong(source);
      executions[1]=FileReadLong(source);filling_flags[1]=FileReadLong(source);
      auto_expiration=FileReadLong(source);order_flags=FileReadLong(source);order_ok=(bool)FileReadInteger(source);
      for(int j=0;j<2;j++) { expiration_flags[j]=FileReadLong(source);expiration_ok[j]=(bool)FileReadInteger(source); }
      double volume=FileReadDouble(source),price=FileReadDouble(source),sl=FileReadDouble(source),tp=FileReadDouble(source);
      datetime expiration=(datetime)FileReadLong(source);
      int symbol_kind=FileReadInteger(source),comment_kind=FileReadInteger(source);
      string symbol="XAUUSD",comment="Recovery";
      if(symbol_kind==1) symbol="";else if(symbol_kind==2) symbol=NULL;else if(symbol_kind==3) symbol="Vàng";
      if(comment_kind==1) comment="";else if(comment_kind==2) comment=NULL;else if(comment_kind==3) comment="Vé kiểm";
      execution_index=0;filling_index=0;expiration_index=0;calls=0;
      call_hash=(ulong)0xcbf29ce484222325;api_error=false;
      bool ready=Bot3PreparePendingRequest(s,strategy_magic,virtual_expiration,symbol,type,volume,price,sl,tp,comment,expiration);
      FileWriteInteger(output,id);FileWriteInteger(output,api_error ? -2 : (int)ready);WriteState(output,s);
      FileWriteInteger(output,calls);FileWriteLong(output,(long)call_hash);
   }
   bool exact=FileTell(source)==FileSize(source);FileClose(source);FileClose(output);
   return exact ? 0 : 1;
}
