#ifndef BOT1_FRIDAY_CLOSE_MQH
#define BOT1_FRIDAY_CLOSE_MQH
#include "Bot1NfpFilter.mqh"

struct Bot1FridaySettings
{
   uchar enabled;
   int hour;
};

void Bot1CloseForFriday(Bot1NfpExecution &execution)
{
   Bot1CloseFilteredBuyPositions(execution.magic_base,execution.symbol,execution.last_ticket,execution.trade,
                                 execution.options,execution.deviation,execution.reference_a,execution.reference_b,
                                 execution.threshold_a,execution.gap);
   Bot1CloseFilteredSellPositions(execution.magic_base,execution.symbol,execution.last_ticket,execution.trade,
                                  execution.options,execution.deviation,execution.reference_a,execution.reference_b,
                                  execution.threshold_a,execution.gap);

   const int total=OrdersTotal();
   if(total<0) return;
   const int magic_base=execution.magic_base;
   long accepted[8];
   for(int i=0;i<8;i++)
      accepted[i]=(long)(int)((uint)magic_base+(uint)(i+1));
   for(int index=total;index>=0;index--)
   {
      execution.last_ticket=OrderGetTicket(index);
      if(execution.last_ticket==0) continue;
      bool accepted_magic=false;
      for(int i=0;i<8;i++)
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
         Bot1DeletePending(execution.trade,execution.options,execution.last_ticket);
      }
   }
}

bool Bot1ProcessFridayClose(const Bot1FridaySettings &settings,const MqlDateTime &cached,
                            uchar &closed,Bot1NfpExecution &execution)
{
   if(settings.enabled!=1) return false;
   if(cached.day_of_week!=5)
   {
      if(closed!=0) closed=0;
      return false;
   }
   if(cached.hour<settings.hour || closed!=0) return false;
   Bot1CloseForFriday(execution);
   Print("Weekend starting! closing trades..");
   closed=1;
   return true;
}

#endif
