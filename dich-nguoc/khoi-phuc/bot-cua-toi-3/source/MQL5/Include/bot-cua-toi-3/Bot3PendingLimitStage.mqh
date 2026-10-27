#ifndef BOT3_PENDING_LIMIT_STAGE_MQH
#define BOT3_PENDING_LIMIT_STAGE_MQH
#include "Bot3NfpFilter.mqh"
#include "Bot3PendingQueue.mqh"
#include "Bot3PendingSelection.mqh"

int Bot3CountPendingForLimit(const bool buy,const int &strategy_magic,const string &symbol,ulong &last_ticket)
{
   const int total=OrdersTotal();
   int count=0;
   for(int index=total;index>=0;index--)
   {
      last_ticket=OrderGetTicket(index);
      if(last_ticket==0) continue;
      if(OrderGetInteger(ORDER_MAGIC)!=(long)strategy_magic) continue;
      if(OrderGetString(ORDER_SYMBOL)!=symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)==(buy ? 4 : 5)) count++;
   }
   return count;
}

void Bot3ApplyPendingLimit(const int &enabled,const int &maximum,Bot3NfpExecution &execution,
                           Bot3PendingQueue &queue)
{
   if(enabled!=1) return;
   if(OrdersTotal()<=0) return;
   const int buy_count=Bot3CountPendingForLimit(true,execution.strategy_magic,execution.symbol,execution.last_ticket);
   if(buy_count>maximum)
      Bot3DeleteHighestBuyPending(execution.strategy_magic,execution.symbol,execution.last_ticket,
                                  queue.results,execution.trade,execution.options);
   const int sell_count=Bot3CountPendingForLimit(false,execution.strategy_magic,execution.symbol,execution.last_ticket);
   if(sell_count>maximum)
      Bot3DeleteLowestSellPending(execution.strategy_magic,execution.symbol,execution.last_ticket,
                                  queue.results,execution.trade,execution.options);
}

#endif
