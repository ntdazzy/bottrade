#ifndef BOT3_FRIDAY_CLOSE_MQH
#define BOT3_FRIDAY_CLOSE_MQH
#include "Bot3NfpFilter.mqh"

struct Bot3FridaySettings
{
   uchar enabled,delete_pending,close_positions;
   int hour;
};

void Bot3CloseForFriday(const uchar &delete_pending,const uchar &close_positions,
                        Bot3NfpExecution &execution)
{
   if(close_positions!=0)
   {
      Bot3CloseFilteredBuyPositions(execution.magic_base,execution.symbol,execution.last_ticket,execution.trade,
                                    execution.options,execution.deviation,execution.tick.bid,execution.tick.ask,
                                    execution.threshold_a,execution.gap);
      Bot3CloseFilteredSellPositions(execution.magic_base,execution.symbol,execution.last_ticket,execution.trade,
                                     execution.options,execution.deviation,execution.tick.bid,execution.tick.ask,
                                     execution.threshold_a,execution.gap);
   }
   if(delete_pending==0) return;
   const int total=OrdersTotal();
   if(total<0) return;
   const int magic_base=execution.magic_base;
   long accepted[15];
   for(int i=0;i<15;i++)
      accepted[i]=(long)(int)((uint)magic_base+(uint)(i+1));
   for(int index=total;index>=0;index--)
   {
      execution.last_ticket=OrderGetTicket(index);
      if(execution.last_ticket==0) continue;
      bool accepted_magic=false;
      for(int i=0;i<15;i++)
      {
         if(OrderGetInteger(ORDER_MAGIC)==accepted[i])
         {
            accepted_magic=true;
            break;
         }
      }
      if(!accepted_magic) continue;
      if(OrderGetString(ORDER_SYMBOL)!=execution.symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)==4 || OrderGetInteger(ORDER_TYPE)==5)
      {
         Print("deleting pending order");
         Bot3DeletePending(execution.trade,execution.options,execution.last_ticket);
      }
   }
}

bool Bot3ProcessFridayClose(const Bot3FridaySettings &settings,const MqlDateTime &cached,
                            uchar &closed,Bot3NfpExecution &execution)
{
   if(settings.enabled!=1) return false;
   if(cached.day_of_week!=5)
   {
      if(closed!=0) closed=0;
      return false;
   }
   if(cached.hour<settings.hour || closed!=0) return false;
   closed=1;
   Bot3CloseForFriday(settings.delete_pending,settings.close_positions,execution);
   Print("Weekend starting! closing trades..");
   return true;
}

#endif
