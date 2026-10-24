// Native 0x32450: unlike bot1, this wrapper returns the send bool.
#ifndef BOT3_ORDER_CANCEL_MQH
#define BOT3_ORDER_CANCEL_MQH
#include "Bot3TradeSend.mqh"
bool Bot3DeletePending(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,const ulong ticket)
{
   if(OrderSelect(ticket))
   {
      string symbol=OrderGetString(ORDER_SYMBOL);
      double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
      MqlTick tick;
      if(!(point<=0.0) && SymbolInfoTick(symbol,tick))
      {
         double limit=point*(double)SymbolInfoInteger(symbol,SYMBOL_TRADE_FREEZE_LEVEL);
         if(limit<=0.0) limit=tick.ask-tick.bid;
         if(!(limit<=0.0))
         {
            double price=OrderGetDouble(ORDER_PRICE_OPEN);
            uint kind=(uint)OrderGetInteger(ORDER_TYPE);
            double distance=0.0;
            bool known=true;
            switch(kind)
            {
               case ORDER_TYPE_BUY_LIMIT: distance=tick.ask-price;break;
               case ORDER_TYPE_SELL_LIMIT: distance=price-tick.bid;break;
               case ORDER_TYPE_BUY_STOP: case ORDER_TYPE_BUY_STOP_LIMIT: distance=price-tick.ask;break;
               case ORDER_TYPE_SELL_STOP: case ORDER_TYPE_SELL_STOP_LIMIT: distance=tick.bid-price;break;
               default: known=false;break;
            }
            if(known && distance<=limit) return false;
         }
      }
   }
   if(IsStopped())
   {
      PrintFormat("%s: MQL5 program is stopped. Trading is disabled","CTrade::OrderDelete");
      state.result.retcode=10027;
      return false;
   }
   ZeroMemory(state.request);
   ZeroMemory(state.result);
   ZeroMemory(state.check);
   state.request.action=TRADE_ACTION_REMOVE;
   state.request.magic=state.magic;
   state.request.order=ticket;
   return Bot3SendTrade(options,state.request,state.result);
}
#endif
