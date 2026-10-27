#ifndef BOT1_PENDING_QUEUE_LIVE_MQH
#define BOT1_PENDING_QUEUE_LIVE_MQH
#include "Bot1NfpFilter.mqh"
#include "Bot1PendingQueue.mqh"

struct Bot1PendingRestoreSettings
{
   double sl_distance,tp_distance;
   datetime expiration_base;
   string comment;
   uchar virtual_expiration;
};

bool Bot1SendQueuedPendingLive(Bot1PendingQueue &queue,const Bot1PendingRestoreSettings &settings,
                               const double &unit,Bot1NfpExecution &execution,const int index,
                               const ENUM_ORDER_TYPE type)
{
   Bot1PendingQueueContext context;
   context.comment=settings.comment;
   context.expiration_base=settings.expiration_base;
   context.sl_distance=settings.sl_distance;
   context.unit=unit;
   context.tp_distance=settings.tp_distance;
   context.symbol=execution.symbol;
   context.strategy_magic=execution.strategy_magic;
   context.virtual_expiration=settings.virtual_expiration;
   return Bot1SendQueuedPending(queue,context,execution.trade,execution.options,index,type);
}

void Bot1RetryQueuedPendingLive(Bot1PendingQueue &queue,const Bot1PendingRestoreSettings &settings,
                                const double &unit,Bot1NfpExecution &execution,const int index,
                                const ENUM_ORDER_TYPE type)
{
   while(GetLastError()==132)
   {
      Sleep(2500);
      Bot1SendQueuedPendingLive(queue,settings,unit,execution,index,type);
   }
   const int error=GetLastError();
   const string text=Bot1TradeErrorText(error,queue.error_count);
   Print("error: '"+text+"' when setting entry order");
}

void Bot1ProcessPendingQueueLive(Bot1PendingQueue &queue,const Bot1PendingRestoreSettings &settings,
                                 const double &unit,Bot1NfpExecution &execution)
{
   if(queue.enabled!=1) return;
   for(int i=0;i<100;i++)
   {
      if(queue.orders[i][0]>0.0)
      {
         if(queue.orders[i][1]==4.0 && Bot1QueueDifference(queue.orders[i][0],execution.threshold_a)>execution.reference_b)
         {
            Print("Restoring pending buy-order");
            if(!Bot1SendQueuedPendingLive(queue,settings,unit,execution,i,ORDER_TYPE_BUY_STOP))
               Bot1RetryQueuedPendingLive(queue,settings,unit,execution,i,ORDER_TYPE_BUY_STOP);
         }
         if(queue.orders[i][1]==5.0 && Bot1QueueSum(queue.orders[i][0],execution.threshold_a)<execution.reference_a)
         {
            Print("Restoring pending sell-order");
            if(!Bot1SendQueuedPendingLive(queue,settings,unit,execution,i,ORDER_TYPE_SELL_STOP))
               Bot1RetryQueuedPendingLive(queue,settings,unit,execution,i,ORDER_TYPE_SELL_STOP);
         }
      }
      if(i==99 || (queue.enabled&1)==0) break;
   }
   if((queue.enabled&1)!=0) ZeroMemory(queue.orders);
}

#endif
