// Native 0x3bb10: the deferred100-order queue, including its retry behavior.
#ifndef BOT3_PENDING_QUEUE_MQH
#define BOT3_PENDING_QUEUE_MQH
#include "Bot3TradeSend.mqh"
#include "Bot3TradeErrors.mqh"
struct Bot3PendingQueue
{
   uchar enabled;
   double orders[100][3];
   double results[100][2];
   uint error_count;
};
struct Bot3PendingQueueContext
{
   double ask,bid,gap;
   double sl_distance,tp_distance,unit;
   datetime expiration_base;
   string symbol,comment;
   int strategy_magic;
   uchar virtual_expiration;
};
// Preserve the original CPU operand order and NaN bits. The compiler otherwise
// folds conditional subtraction into sign-flip plus addition.
double Bot3QueueSum(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left+right;
}
double Bot3QueueProduct(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left*right;
}
double Bot3QueueDifference(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left-right;
}
bool Bot3SendQueuedPending(Bot3PendingQueue &queue,Bot3PendingQueueContext &context,
                          Bot3PendingRequestState &trade,Bot3TradeSendOptions &options,
                          const int index,const ENUM_ORDER_TYPE type)
{
   string comment=context.comment;
   datetime expiration=context.expiration_base+172800;
   double sl_distance=context.sl_distance,price=queue.orders[index][0],unit=context.unit,tp_distance=context.tp_distance;
   sl_distance=Bot3QueueSum(sl_distance,0.0);
   tp_distance=Bot3QueueProduct(tp_distance,unit);
   sl_distance=Bot3QueueProduct(sl_distance,unit);
   double sl=price,tp=price;
   if(type==ORDER_TYPE_BUY_STOP)
   {
      tp=Bot3QueueSum(tp_distance,price);
      sl=Bot3QueueDifference(price,sl_distance);
   }
   else
   {
      tp=Bot3QueueDifference(price,tp_distance);
      sl=Bot3QueueSum(sl_distance,price);
   }
   double volume=queue.orders[index][2];string symbol=context.symbol;
   bool accepted=Bot3OpenPending(trade,options,context.strategy_magic,context.virtual_expiration,symbol,type,volume,price,sl,tp,comment,expiration);
   for(int k=0;k<100;k++)
   {
      if(queue.results[k][0]==0.0)
      {
         queue.results[k][0]=(double)(uint)accepted;
         queue.results[k][1]=queue.orders[index][0];
         break;
      }
   }
   return accepted;
}
void Bot3RetryQueuedPending(Bot3PendingQueue &queue,Bot3PendingQueueContext &context,
                           Bot3PendingRequestState &trade,Bot3TradeSendOptions &options,
                           const int index,const ENUM_ORDER_TYPE type)
{
   while(GetLastError()==132)
   {
      Sleep(2500);
      Bot3SendQueuedPending(queue,context,trade,options,index,type);
   }
   int error=GetLastError();
   string text=Bot3TradeErrorText(error,queue.error_count);
   Print("error: '"+text+"' when setting entry order");
}
void Bot3ProcessPendingQueue(Bot3PendingQueue &queue,Bot3PendingQueueContext &context,
                            Bot3PendingRequestState &trade,Bot3TradeSendOptions &options)
{
   if(queue.enabled!=1) return;
   for(int i=0;i<100;i++)
   {
      if(queue.orders[i][0]>0.0)
      {
         if(queue.orders[i][1]==4.0 && queue.orders[i][0]-context.gap>context.ask)
         {
            Print("Restoring pending buy-order");
            if(!Bot3SendQueuedPending(queue,context,trade,options,i,ORDER_TYPE_BUY_STOP))
               Bot3RetryQueuedPending(queue,context,trade,options,i,ORDER_TYPE_BUY_STOP);
         }
         if(queue.orders[i][1]==5.0 && queue.orders[i][0]+context.gap<context.bid)
         {
            Print("Restoring pending sell-order");
            if(!Bot3SendQueuedPending(queue,context,trade,options,i,ORDER_TYPE_SELL_STOP))
               Bot3RetryQueuedPending(queue,context,trade,options,i,ORDER_TYPE_SELL_STOP);
         }
      }
      if(i==99 || (queue.enabled&1)==0) break;
   }
   if((queue.enabled&1)!=0) ZeroMemory(queue.orders);
}
#endif
