#define OnStart UnusedStandaloneSendCheck
#include "Bot3TradeSendCheck.mq5"
#undef OnStart
void SeedOpenCheck(MqlTradeCheckResult &value)
{
   value.retcode=301;value.balance=1301.25;value.equity=1302.25;value.profit=1303.25;
   value.margin=1304.25;value.margin_free=1305.25;value.margin_level=1306.25;
   value.comment="TRADE_LAYOUT_CHECK";
}
void WriteOpenCheck(const int f,const MqlTradeCheckResult &value)
{
   FileWriteInteger(f,(int)value.retcode);FileWriteDouble(f,value.balance);FileWriteDouble(f,value.equity);
   FileWriteDouble(f,value.profit);FileWriteDouble(f,value.margin);FileWriteDouble(f,value.margin_free);
   FileWriteDouble(f,value.margin_level);FileWriteLong(f,(long)TextHash(value.comment));
}
int OnStart()
{
   if(CheckRun=="") return 1;
   pending_mode=true;
   string folder="bot3-open-pending\\"+CheckRun+"\\";
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4f504e31 || version!=1 || count<1) { FileClose(source);return 1; }
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
      Bot3PendingRequestState state;
      ReadRequest(source,state.request);ReadResult(source,state.result);ReadResult(source,supplied_result);
      SeedOpenCheck(state.check);state.magic=0x7654321076543210;
      pending_stopped=(bool)FileReadInteger(source);uchar virtual_expiration=(uchar)FileReadInteger(source);
      int strategy_magic=FileReadInteger(source);ENUM_ORDER_TYPE type=(ENUM_ORDER_TYPE)FileReadInteger(source);
      state.preferred=(ENUM_ORDER_TYPE_FILLING)FileReadInteger(source);
      pending_executions[0]=FileReadLong(source);pending_filling[0]=FileReadLong(source);
      pending_executions[1]=FileReadLong(source);pending_filling[1]=FileReadLong(source);
      pending_auto_expiration=FileReadLong(source);pending_order_flags=FileReadLong(source);
      pending_order_ok=(bool)FileReadInteger(source);
      for(int j=0;j<2;j++) { pending_expiration[j]=FileReadLong(source);pending_expiration_ok[j]=(bool)FileReadInteger(source); }
      double volume=FileReadDouble(source),price=FileReadDouble(source),sl=FileReadDouble(source),tp=FileReadDouble(source);
      datetime expiration=(datetime)FileReadLong(source);int symbol_kind=FileReadInteger(source),comment_kind=FileReadInteger(source);
      string symbol="XAUUSD",comment="Recovery";
      if(symbol_kind==1) symbol="";else if(symbol_kind==2) symbol=NULL;else if(symbol_kind==3) symbol="Vàng";
      if(comment_kind==1) comment="";else if(comment_kind==2) comment=NULL;else if(comment_kind==3) comment="Vé kiểm";
      FileWriteInteger(fixture,case_id);FileWriteInteger(fixture,0);
      Text(fixture,"5");Text(fixture,(string)(uint)type);Text(fixture,"0");Text(fixture,(string)supplied_result.retcode);
      event_count=0;print_count=0;printed_hash=0;property_index[0]=0;property_index[1]=0;
      pending_execution_index=0;pending_filling_index=0;pending_expiration_index=0;
      bool accepted=Bot3OpenPending(state,options,strategy_magic,virtual_expiration,symbol,type,volume,price,sl,tp,comment,expiration);
      FileWriteInteger(output,case_id);FileWriteInteger(output,api_error ? -2 : (int)accepted);
      FileWriteLong(output,(long)state.magic);FileWriteInteger(output,(int)state.preferred);
      WriteRequest(output,state.request);WriteResult(output,state.result);WriteOpenCheck(output,state.check);
      FileWriteInteger(output,event_count);FileWriteInteger(output,print_count);FileWriteLong(output,(long)printed_hash);
   }
   bool exact=FileTell(source)==FileSize(source);FileClose(source);FileClose(output);FileClose(fixture);
   return exact ? 0 : 1;
}
