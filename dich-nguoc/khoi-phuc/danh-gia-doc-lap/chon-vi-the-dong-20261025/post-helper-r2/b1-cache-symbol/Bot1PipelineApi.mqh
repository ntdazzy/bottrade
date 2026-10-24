// Derived from Bot1TradeSendCheck.mq5, SHA256 ecdb190fa206cd86103a69dbd57b7bf666a623977dc5b3fc2e103806da739c90.
// Only API completion observers are added; production headers are included unchanged.
#ifndef BOT1_PIPELINE_API_MQH
#define BOT1_PIPELINE_API_MQH
#property strict
// Send APIs are replaced. Formatting results are measured with real MT5 builtins.
input string CheckRun="";
union DoubleBits { double value;ulong bits; };
int fixture=INVALID_HANDLE,event_count=0,print_count=0,case_id=0,property_index[2];
bool api_error=false,accepted_value=false,write_result=false;
long digits_values[2],execution_values[2];bool digits_ok[2],execution_ok[2];
ulong printed_hash=0;
MqlTradeResult supplied_result;
bool pending_mode=false,pending_stopped=false,pending_order_ok=false,pending_expiration_ok[2];
long pending_executions[2],pending_filling[2],pending_auto_expiration=0,pending_order_flags=0,pending_expiration[2];
int pending_execution_index=0,pending_filling_index=0,pending_expiration_index=0;
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
   WriteResult(fixture,result);PipelineSendComplete();return accepted_value;
}
bool MockSend(const MqlTradeRequest &request,MqlTradeResult &result) { return MockSendCommon(0,request,result); }
bool MockAsync(const MqlTradeRequest &request,MqlTradeResult &result) { return MockSendCommon(1,request,result); }
long MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(!pending_mode) { api_error=true;return 0; }
   long value=0;
   if(property==SYMBOL_TRADE_EXEMODE && pending_execution_index<2) value=pending_executions[pending_execution_index++];
   else if(property==SYMBOL_FILLING_MODE && pending_filling_index<2) value=pending_filling[pending_filling_index++];
   else if(property==SYMBOL_EXPIRATION_MODE) value=pending_auto_expiration;
   else api_error=true;
   Event(9);FileWriteInteger(fixture,(int)property);Text(fixture,symbol);FileWriteLong(fixture,value);
   return value;
}
bool MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value)
{
   if(pending_mode && (property==SYMBOL_ORDER_MODE || property==SYMBOL_EXPIRATION_MODE))
   {
      bool ok=false;
      if(property==SYMBOL_ORDER_MODE) { value=pending_order_flags;ok=pending_order_ok; }
      else if(pending_expiration_index<2)
      { value=pending_expiration[pending_expiration_index];ok=pending_expiration_ok[pending_expiration_index++]; }
      else { api_error=true;value=0; }
      Event(2);FileWriteInteger(fixture,(int)property);Text(fixture,symbol);
      FileWriteLong(fixture,value);FileWriteInteger(fixture,(int)ok);PipelinePropertyComplete(ok);return ok;
   }
   int kind=property==SYMBOL_DIGITS ? 0 : 1;
   if(property!=SYMBOL_DIGITS && property!=SYMBOL_TRADE_EXEMODE) api_error=true;
   int n=property_index[kind]++;
   if(n>=2) { api_error=true;value=0;return false; }
   value=kind==0 ? digits_values[n] : execution_values[n];
   bool ok=kind==0 ? digits_ok[n] : execution_ok[n];
   Event(2);FileWriteInteger(fixture,(int)property);Text(fixture,symbol);
   FileWriteLong(fixture,value);FileWriteInteger(fixture,(int)ok);PipelinePropertyComplete(ok);return ok;
}
string MockDouble(const double value,const int digits)
{
   string result=DoubleToString(value,digits);
   Event(3);FileWriteDouble(fixture,value);FileWriteInteger(fixture,digits);Text(fixture,result);return result;
}
void MockPrint(const string value)
{
   if(!pending_mode) api_error=true;
   Event(7);FileWriteInteger(fixture,1);Text(fixture,value);
}
void MockPrint(const string a,const string b)
{
   if(!pending_mode) api_error=true;
   Event(7);FileWriteInteger(fixture,2);Text(fixture,a);Text(fixture,b);
}
void MockFormat(const string format,const string request,const string result)
{
   string output=StringFormat(format,request,result);
   Event(6);Text(fixture,format);Text(fixture,request);Text(fixture,result);Text(fixture,output);
   print_count++;printed_hash=TextHash(output);
}
void MockFormat(const string format,const string value)
{
   if(!pending_mode) api_error=true;
   Event(8);Text(fixture,format);Text(fixture,value);Text(fixture,StringFormat(format,value));
}
bool MockStopped() { return pending_stopped; }
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
#define IsStopped MockStopped
#include <bot-cua-toi-1/Bot1TradeSend.mqh>

#undef OrderSend
#undef OrderSendAsync
#undef SymbolInfoInteger
#undef DoubleToString
#undef StringFormat
#undef PrintFormat
#undef Print
#undef IsStopped
#endif
