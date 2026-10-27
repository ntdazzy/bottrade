#ifndef BOT3_PENDING_QUEUE_LIVE_MQH
#define BOT3_PENDING_QUEUE_LIVE_MQH
#include "Bot3NfpFilter.mqh"
#include "Bot3PendingQueue.mqh"

struct Bot3PendingRestoreSettings
{
   double sl_distance,tp_distance;
   datetime expiration_base;
   string comment;
   uchar virtual_expiration;
};

bool Bot3SendQueuedPendingLive(Bot3PendingQueue &queue,const Bot3PendingRestoreSettings &settings,
                               const double &unit,Bot3NfpExecution &execution,const int index,
                               const ENUM_ORDER_TYPE type)
{
   Bot3PendingQueueContext context;
   context.comment=settings.comment;
   context.expiration_base=settings.expiration_base;
   context.sl_distance=settings.sl_distance;
   context.unit=unit;
   context.tp_distance=settings.tp_distance;
   context.symbol=execution.symbol;
   context.strategy_magic=execution.strategy_magic;
   context.virtual_expiration=settings.virtual_expiration;
   return Bot3SendQueuedPending(queue,context,execution.trade,execution.options,index,type);
}

void Bot3RetryQueuedPendingLive(Bot3PendingQueue &queue,const Bot3PendingRestoreSettings &settings,
                                const double &unit,Bot3NfpExecution &execution,const int index,
                                const ENUM_ORDER_TYPE type)
{
   while(GetLastError()==132)
   {
      Sleep(2500);
      Bot3SendQueuedPendingLive(queue,settings,unit,execution,index,type);
   }
   const int error=GetLastError();
   const string text=Bot3TradeErrorText(error,queue.error_count);
   Print("error: '"+text+"' when setting entry order");
}

void Bot3ProcessPendingQueueLive(Bot3PendingQueue &queue,const Bot3PendingRestoreSettings &settings,
                                 const double &unit,Bot3NfpExecution &execution)
{
   if(queue.enabled!=1) return;
   for(int i=0;i<100;i++)
   {
      if(queue.orders[i][0]>0.0)
      {
         if(queue.orders[i][1]==4.0 && Bot3QueueDifference(queue.orders[i][0],execution.threshold_a)>execution.tick.ask)
         {
            Print("Restoring pending buy-order");
            if(!Bot3SendQueuedPendingLive(queue,settings,unit,execution,i,ORDER_TYPE_BUY_STOP))
               Bot3RetryQueuedPendingLive(queue,settings,unit,execution,i,ORDER_TYPE_BUY_STOP);
         }
         if(queue.orders[i][1]==5.0 && Bot3QueueSum(queue.orders[i][0],execution.threshold_a)<execution.tick.bid)
         {
            Print("Restoring pending sell-order");
            if(!Bot3SendQueuedPendingLive(queue,settings,unit,execution,i,ORDER_TYPE_SELL_STOP))
               Bot3RetryQueuedPendingLive(queue,settings,unit,execution,i,ORDER_TYPE_SELL_STOP);
         }
      }
      if(i==99 || (queue.enabled&1)==0) break;
   }
   if((queue.enabled&1)!=0) ZeroMemory(queue.orders);
}

#endif
