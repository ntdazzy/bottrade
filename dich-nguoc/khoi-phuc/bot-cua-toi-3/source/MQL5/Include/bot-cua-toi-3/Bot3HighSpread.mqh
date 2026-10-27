#ifndef BOT3_HIGH_SPREAD_MQH
#define BOT3_HIGH_SPREAD_MQH
#include "Bot3NfpFilter.mqh"
#include "Bot3PendingQueue.mqh"

struct Bot3SpreadSettings
{
   uchar enabled;
   int distance_points;
   double maximum,minimum;
};

void Bot3StorePendingForHighSpread(const Bot3SpreadSettings &settings,const double &unit,
                                   const double &spread,Bot3NfpExecution &execution,
                                   Bot3PendingQueue &queue)
{
   const int total=OrdersTotal();
   if(total<0) return;
   for(int index=total;index>=0;index--)
   {
      execution.last_ticket=OrderGetTicket(index);
      if(execution.last_ticket==0) continue;
      if(!(OrderGetInteger(ORDER_MAGIC)==execution.strategy_magic || OrderGetInteger(ORDER_MAGIC)==0)) continue;
      if(OrderGetString(ORDER_SYMBOL)!=execution.symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)==4)
      {
         const double first_price=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)9);
         const double quote=execution.tick.ask;
         const double threshold=Bot3QueueSum(Bot3QueueProduct((double)settings.distance_points,unit),quote);
         if(threshold>first_price)
         {
            const double second_price=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)9);
            if(Bot3QueueDifference(second_price,execution.gap)>quote)
               Bot3StoreHighSpreadAction(settings,spread,execution,queue);
         }
      }
      if(OrderGetInteger(ORDER_TYPE)==5)
      {
         const double first_price=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)9);
         const double bid=execution.tick.bid;
         const double threshold=Bot3QueueDifference(bid,Bot3QueueProduct((double)settings.distance_points,unit));
         if(first_price>threshold)
         {
            const double second_price=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)9);
            if(bid>Bot3QueueSum(second_price,execution.gap))
               Bot3StoreHighSpreadAction(settings,spread,execution,queue);
         }
      }
   }
}

void Bot3StoreHighSpreadAction(const Bot3SpreadSettings &settings,const double &spread,
                               Bot3NfpExecution &execution,Bot3PendingQueue &queue)
{
   const double minimum=settings.minimum;
   const string value=(string)spread;
   const bool store=minimum>0.0;
   Print("Spread too high..("+value+(store ? ") storing and deleting order ":") deleting order ")+(string)execution.last_ticket);
   if(store && queue.enabled==1)
   {
      for(int row=0;row<100;row++)
      {
         if(queue.orders[row][0]==0.0)
         {
            Print("Storing pending order nr "+(string)execution.last_ticket);
            queue.orders[row][1]=(double)OrderGetInteger(ORDER_TYPE);
            queue.orders[row][0]=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)9);
            queue.orders[row][2]=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)7);
            break;
         }
      }
   }
   const double ticket=(double)(long)execution.last_ticket;
   for(int row=0;row<100;row++)
   {
      if(queue.results[row][0]==ticket)
      {
         queue.results[row][0]=0.0;
         queue.results[row][1]=0.0;
         break;
      }
   }
   Bot3DeletePending(execution.trade,execution.options,execution.last_ticket);
}

bool Bot3ProcessHighSpread(const Bot3SpreadSettings &settings,const double &unit,double &spread,
                           Bot3NfpExecution &execution,Bot3PendingQueue &queue)
{
   spread=Bot3QueueDifference(execution.tick.ask,execution.tick.bid);
   if(settings.enabled==0) return false;
   if(!(spread>Bot3QueueProduct(settings.maximum,unit))) return false;
   Bot3StorePendingForHighSpread(settings,unit,spread,execution,queue);
   return true;
}

#endif
