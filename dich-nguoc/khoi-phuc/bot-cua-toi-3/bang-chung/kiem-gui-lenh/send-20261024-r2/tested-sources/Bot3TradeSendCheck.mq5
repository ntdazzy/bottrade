#property strict
// Send APIs are replaced. Formatting results are measured with real MT5 builtins.
input string CheckRun="";
union DoubleBits { double value;ulong bits; };
int fixture=INVALID_HANDLE,event_count=0,print_count=0,case_id=0,property_index[2];
bool api_error=false,accepted_value=false,write_result=false;
long digits_values[2],execution_values[2];bool digits_ok[2],execution_ok[2];
ulong printed_hash=0;
MqlTradeResult supplied_result;
ulong TextHash(const string text)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(text);i++)
   {
      uint c=StringGetCharacter(text,i);
      h^=c&255;h*=(ulong)0x100000001b3;h^=(c>>8)&255;h*=(ulong)0x100000001b3;
   }
   return h;
}
void Text(const int f,const string value)
{
   FileWriteInteger(f,StringLen(value));
   for(int i=0;i<StringLen(value);i++) FileWriteInteger(f,StringGetCharacter(value,i),SHORT_VALUE);
}
string ReadText(const int f)
{
   int n=FileReadInteger(f);
   if(n<0 || n>4096) { api_error=true;return ""; }
   string value="";
   for(int i=0;i<n;i++) value+=ShortToString((ushort)FileReadInteger(f,SHORT_VALUE));
   return value;
}
void Event(const int api) { FileWriteInteger(fixture,case_id);FileWriteInteger(fixture,api);event_count++; }
void ArgString(const string text) { FileWriteInteger(fixture,0x590008);Text(fixture,text); }
void ArgUnsigned(const ulong value) { FileWriteInteger(fixture,0x560015);FileWriteLong(fixture,(long)value); }
void WriteRequest(const int f,const MqlTradeRequest &r)
{
   FileWriteInteger(f,(int)r.action);FileWriteLong(f,(long)r.magic);FileWriteLong(f,(long)r.order);
   FileWriteLong(f,(long)TextHash(r.symbol));FileWriteDouble(f,r.volume);FileWriteDouble(f,r.price);
   FileWriteDouble(f,r.stoplimit);FileWriteDouble(f,r.sl);FileWriteDouble(f,r.tp);
   FileWriteLong(f,(long)r.deviation);FileWriteInteger(f,(int)r.type);FileWriteInteger(f,(int)r.type_filling);
   FileWriteInteger(f,(int)r.type_time);FileWriteLong(f,(long)r.expiration);
   FileWriteLong(f,(long)TextHash(r.comment));FileWriteLong(f,(long)r.position);FileWriteLong(f,(long)r.position_by);
}
void WriteResult(const int f,const MqlTradeResult &r)
{
   FileWriteInteger(f,(int)r.retcode);FileWriteLong(f,(long)r.deal);FileWriteLong(f,(long)r.order);
   FileWriteDouble(f,r.volume);FileWriteDouble(f,r.price);FileWriteDouble(f,r.bid);FileWriteDouble(f,r.ask);
   FileWriteLong(f,(long)TextHash(r.comment));FileWriteInteger(f,(int)r.request_id);FileWriteInteger(f,r.retcode_external);
}
void ReadRequest(const int f,MqlTradeRequest &r)
{
   r.action=(ENUM_TRADE_REQUEST_ACTIONS)FileReadInteger(f);r.magic=(ulong)FileReadLong(f);r.order=(ulong)FileReadLong(f);
   int symbol_kind=FileReadInteger(f);r.symbol=ReadText(f);if(symbol_kind==1) r.symbol=NULL;
   r.volume=FileReadDouble(f);r.price=FileReadDouble(f);r.stoplimit=FileReadDouble(f);
   r.sl=FileReadDouble(f);r.tp=FileReadDouble(f);r.deviation=(ulong)FileReadLong(f);
   r.type=(ENUM_ORDER_TYPE)FileReadInteger(f);r.type_filling=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(f);
   r.type_time=(ENUM_ORDER_TYPE_TIME)FileReadInteger(f);r.expiration=(datetime)FileReadLong(f);
   r.comment=ReadText(f);r.position=(ulong)FileReadLong(f);r.position_by=(ulong)FileReadLong(f);
}
void ReadResult(const int f,MqlTradeResult &r)
{
   r.retcode=(uint)FileReadInteger(f);r.deal=(ulong)FileReadLong(f);r.order=(ulong)FileReadLong(f);
   r.volume=FileReadDouble(f);r.price=FileReadDouble(f);r.bid=FileReadDouble(f);r.ask=FileReadDouble(f);
   r.comment=ReadText(f);r.request_id=(uint)FileReadInteger(f);r.retcode_external=FileReadInteger(f);
}
bool MockSendCommon(const int async_mode,const MqlTradeRequest &request,MqlTradeResult &result)
{
   Event(1);FileWriteInteger(fixture,async_mode);FileWriteInteger(fixture,(int)accepted_value);
   WriteRequest(fixture,request);WriteResult(fixture,result);
   if(write_result) result=supplied_result;
   WriteResult(fixture,result);return accepted_value;
}
bool MockSend(const MqlTradeRequest &request,MqlTradeResult &result) { return MockSendCommon(0,request,result); }
bool MockAsync(const MqlTradeRequest &request,MqlTradeResult &result) { return MockSendCommon(1,request,result); }
long MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{ api_error=true;return 0; }
bool MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value)
{
   int kind=property==SYMBOL_DIGITS ? 0 : 1;
   if(property!=SYMBOL_DIGITS && property!=SYMBOL_TRADE_EXEMODE) api_error=true;
   int n=property_index[kind]++;
   if(n>=2) { api_error=true;value=0;return false; }
   value=kind==0 ? digits_values[n] : execution_values[n];
   bool ok=kind==0 ? digits_ok[n] : execution_ok[n];
   Event(2);FileWriteInteger(fixture,(int)property);Text(fixture,symbol);
   FileWriteLong(fixture,value);FileWriteInteger(fixture,(int)ok);return ok;
}
string MockDouble(const double value,const int digits)
{
   string result=DoubleToString(value,digits);
   Event(3);FileWriteDouble(fixture,value);FileWriteInteger(fixture,digits);Text(fixture,result);return result;
}
void MockPrint(const string value) { api_error=true; }
void MockPrint(const string a,const string b) { api_error=true; }
void MockFormat(const string format,const string request,const string result)
{
   string output=StringFormat(format,request,result);
   Event(6);Text(fixture,format);Text(fixture,request);Text(fixture,result);Text(fixture,output);
   print_count++;printed_hash=TextHash(output);
}
void MockFormat(const string format,const string value) { api_error=true; }
string MockStringFormat(const string format,const string a0)
{
   string output=StringFormat(format,a0);
   Event(5);FileWriteInteger(fixture,2);ArgString(format);ArgString(a0);
   Text(fixture,output);return output;
}

string MockStringFormat(const string format,const string a0,const string a1)
{
   string output=StringFormat(format,a0,a1);
   Event(5);FileWriteInteger(fixture,3);ArgString(format);ArgString(a0);ArgString(a1);
   Text(fixture,output);return output;
}

string MockStringFormat(const string format,const string a0,const string a1,const string a2)
{
   string output=StringFormat(format,a0,a1,a2);
   Event(5);FileWriteInteger(fixture,4);ArgString(format);ArgString(a0);ArgString(a1);ArgString(a2);
   Text(fixture,output);return output;
}

string MockStringFormat(const string format,const string a0,const string a1,const string a2,const string a3)
{
   string output=StringFormat(format,a0,a1,a2,a3);
   Event(5);FileWriteInteger(fixture,5);ArgString(format);ArgString(a0);ArgString(a1);ArgString(a2);ArgString(a3);
   Text(fixture,output);return output;
}

string MockStringFormat(const string format,const string a0,const string a1,const ulong a2,const string a3,const string a4)
{
   string output=StringFormat(format,a0,a1,a2,a3,a4);
   Event(5);FileWriteInteger(fixture,6);ArgString(format);ArgString(a0);ArgString(a1);ArgUnsigned(a2);ArgString(a3);ArgString(a4);
   Text(fixture,output);return output;
}

string MockStringFormat(const string format,const string a0,const string a1,const ulong a2,const string a3)
{
   string output=StringFormat(format,a0,a1,a2,a3);
   Event(5);FileWriteInteger(fixture,5);ArgString(format);ArgString(a0);ArgString(a1);ArgUnsigned(a2);ArgString(a3);
   Text(fixture,output);return output;
}

string MockStringFormat(const string format,const ulong a0,const string a1,const string a2,const string a3)
{
   string output=StringFormat(format,a0,a1,a2,a3);
   Event(5);FileWriteInteger(fixture,5);ArgString(format);ArgUnsigned(a0);ArgString(a1);ArgString(a2);ArgString(a3);
   Text(fixture,output);return output;
}

string MockStringFormat(const string format,const ulong a0)
{
   string output=StringFormat(format,a0);
   Event(5);FileWriteInteger(fixture,2);ArgString(format);ArgUnsigned(a0);
   Text(fixture,output);return output;
}

string MockStringFormat(const string format,const ulong a0,const ulong a1)
{
   string output=StringFormat(format,a0,a1);
   Event(5);FileWriteInteger(fixture,3);ArgString(format);ArgUnsigned(a0);ArgUnsigned(a1);
   Text(fixture,output);return output;
}

#define OrderSend MockSend
#define OrderSendAsync MockAsync
#define SymbolInfoInteger MockInteger
#define DoubleToString MockDouble
#define StringFormat MockStringFormat
#define PrintFormat MockFormat
#define Print MockPrint
#include "../../Include/bot-cua-toi-3/Bot3TradeSend.mqh"
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-trade-send\\"+CheckRun+"\\";
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x534e4431 || version!=1 || count<1) { FileClose(source);return 1; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   fixture=FileOpen(folder+"api-fixtures.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE || fixture==INVALID_HANDLE)
   { FileClose(source);if(output!=INVALID_HANDLE) FileClose(output);if(fixture!=INVALID_HANDLE) FileClose(fixture);return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   FileWriteInteger(fixture,magic);FileWriteInteger(fixture,version);FileWriteInteger(fixture,count);
   Text(fixture,_Symbol);FileWriteInteger(fixture,_Digits);
   for(int i=0;i<count;i++)
   {
      api_error=false;case_id=FileReadInteger(source);
      Bot3TradeSendOptions options;options.async_mode=(uchar)FileReadInteger(source);
      options.log_level=FileReadInteger(source);options.margin_mode=FileReadInteger(source);
      accepted_value=(bool)FileReadInteger(source);write_result=(bool)FileReadInteger(source);
      for(int j=0;j<2;j++) digits_values[j]=FileReadLong(source);
      for(int j=0;j<2;j++) execution_values[j]=FileReadLong(source);
      for(int j=0;j<2;j++) digits_ok[j]=(bool)FileReadInteger(source);
      for(int j=0;j<2;j++) execution_ok[j]=(bool)FileReadInteger(source);
      MqlTradeRequest request={};MqlTradeResult result={};ReadRequest(source,request);
      ReadResult(source,result);ReadResult(source,supplied_result);
      FileWriteInteger(fixture,case_id);FileWriteInteger(fixture,0);
      Text(fixture,(string)(int)request.action);Text(fixture,(string)(uint)request.type);
      Text(fixture,(string)result.retcode);Text(fixture,(string)supplied_result.retcode);
      event_count=0;print_count=0;printed_hash=0;property_index[0]=0;property_index[1]=0;
      bool accepted=Bot3SendTrade(options,request,result);
      FileWriteInteger(output,case_id);FileWriteInteger(output,api_error ? -2 : (int)accepted);
      WriteRequest(output,request);WriteResult(output,result);FileWriteInteger(output,event_count);
      FileWriteInteger(output,print_count);FileWriteLong(output,(long)printed_hash);
   }
   bool exact=FileTell(source)==FileSize(source);FileClose(source);FileClose(output);FileClose(fixture);
   return exact ? 0 : 1;
}
