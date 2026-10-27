#ifndef BOT1_HIGH_SPREAD_MQH
#define BOT1_HIGH_SPREAD_MQH
#include "Bot1NfpFilter.mqh"
#include "Bot1PendingQueue.mqh"

struct Bot1SpreadSettings
{
   uchar enabled;
   int distance_points;
   double maximum,minimum;
};

void Bot1StorePendingForHighSpread(const Bot1SpreadSettings &settings,const double &unit,
                                   const double &spread,Bot1NfpExecution &execution,
                                   Bot1PendingQueue &queue)
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
         const double threshold=Bot1QueueSum(Bot1QueueProduct((double)settings.distance_points,unit),quote);
         if(threshold>first_price)
         {
            const double second_price=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)9);
            if(Bot1QueueDifference(second_price,execution.gap)>quote)
               Bot1StoreHighSpreadAction(settings,spread,execution,queue);
         }
      }
      if(OrderGetInteger(ORDER_TYPE)==5)
      {
         const double first_price=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)9);
         const double bid=execution.tick.bid;
         const double threshold=Bot1QueueDifference(bid,Bot1QueueProduct((double)settings.distance_points,unit));
         if(first_price>threshold)
         {
            const double second_price=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)9);
            if(bid>Bot1QueueSum(second_price,execution.gap))
               Bot1StoreHighSpreadAction(settings,spread,execution,queue);
         }
      }
   }
}

void Bot1StoreHighSpreadAction(const Bot1SpreadSettings &settings,const double &spread,
                               Bot1NfpExecution &execution,Bot1PendingQueue &queue)
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
   Bot1DeletePending(execution.trade,execution.options,execution.last_ticket);
}

bool Bot1ProcessHighSpread(const Bot1SpreadSettings &settings,const double &unit,double &spread,
                           Bot1NfpExecution &execution,Bot1PendingQueue &queue)
{
   spread=Bot1QueueDifference(execution.tick.ask,execution.tick.bid);
   if(settings.enabled==0) return false;
   if(!(spread>Bot1QueueProduct(settings.maximum,unit))) return false;
   Bot1StorePendingForHighSpread(settings,unit,spread,execution,queue);
   return true;
}

#endif
