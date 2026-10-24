// Native 0x950, including all message branches. Terminal send APIs are real here.
#ifndef BOT1_TRADE_SEND_MQH
#define BOT1_TRADE_SEND_MQH
#include "Bot1TradeMessages.mqh"
#include "Bot1PendingRequest.mqh"
struct Bot1TradeSendOptions
{
   uchar async_mode;
   int log_level;
   int margin_mode;
};
bool Bot1SendTrade(Bot1TradeSendOptions &options,const MqlTradeRequest &request,MqlTradeResult &result)
{
   bool accepted=options.async_mode!=0 ? OrderSendAsync(request,result) : OrderSend(request,result);
   if((accepted && options.log_level>1) || (!accepted && options.log_level>0))
   {
      string result_text=Bot1FormatTradeResult(request,result);
      string request_text=Bot1FormatTradeRequest(request,options.margin_mode);
      PrintFormat("CTrade::OrderSend: %s [%s]",request_text,result_text);
   }
   return accepted;
}
bool Bot1OpenPending(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                    const int strategy_magic,const uchar virtual_expiration,const string symbol,
                    const ENUM_ORDER_TYPE type,const double volume,const double price,
                    const double sl,const double tp,const string comment,const datetime expiration)
{
   if(!Bot1PreparePendingRequest(state,strategy_magic,virtual_expiration,symbol,type,volume,price,sl,tp,comment,expiration)) return false;
   return Bot1SendTrade(options,state.request,state.result);
}
#endif
