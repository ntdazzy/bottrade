// Native pending-order scans 3ca00/3cc20 followed by the complete delete/send path.
#ifndef BOT3_PENDING_DISTANCE_CANCEL_MQH
#define BOT3_PENDING_DISTANCE_CANCEL_MQH
#include "Bot3OrderCancel.mqh"
void Bot3CancelDistantPending(const int enabled,const bool buy,const int &strategy_magic,
                              const string &symbol,const double &reference_quote,const double &gap,
                              ulong &last_ticket,Bot3PendingRequestState &trade,Bot3TradeSendOptions &options)
{
   if(enabled!=1) return;
   const int total=OrdersTotal();
   if(total<0) return;
   for(int index=total;index>=0;index--)
   {
      last_ticket=OrderGetTicket(index);
      if(last_ticket==0) continue;
      if(OrderGetInteger(ORDER_MAGIC)!=(long)strategy_magic) continue;
      const string order_symbol=OrderGetString(ORDER_SYMBOL);
      if(order_symbol!=symbol) continue;
      const long kind=OrderGetInteger(ORDER_TYPE);
      if(kind!=(buy ? (long)ORDER_TYPE_BUY_STOP : (long)ORDER_TYPE_SELL_STOP)) continue;
      const double quote=reference_quote;
      const double price=OrderGetDouble(ORDER_PRICE_OPEN);
      if(buy ? price-gap>quote : quote>price+gap) Bot3DeletePending(trade,options,last_ticket);
   }
}
#endif
