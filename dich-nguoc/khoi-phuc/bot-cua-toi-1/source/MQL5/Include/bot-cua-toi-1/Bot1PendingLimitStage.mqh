#ifndef BOT1_PENDING_LIMIT_STAGE_MQH
#define BOT1_PENDING_LIMIT_STAGE_MQH
#include "Bot1NfpFilter.mqh"
#include "Bot1PendingQueue.mqh"
#include "Bot1OrderScan.mqh"
#include "Bot1PendingSelection.mqh"

void Bot1ApplyPendingLimit(const int &enabled,const int &maximum,Bot1NfpExecution &execution,
                           Bot1PendingQueue &queue)
{
   if(enabled!=1) return;
   if(OrdersTotal()<=0) return;
   const int buy_count=Bot1CountBuyPending(execution.strategy_magic,execution.symbol,execution.last_ticket);
   if(buy_count>maximum)
      Bot1DeleteHighestBuyPending(execution.strategy_magic,execution.symbol,execution.last_ticket,
                                  queue.results,execution.trade,execution.options);
   const int sell_count=Bot1CountSellPending(execution.strategy_magic,execution.symbol,execution.last_ticket);
   if(sell_count>maximum)
      Bot1DeleteLowestSellPending(execution.strategy_magic,execution.symbol,execution.last_ticket,
                                  queue.results,execution.trade,execution.options);
}

#endif
