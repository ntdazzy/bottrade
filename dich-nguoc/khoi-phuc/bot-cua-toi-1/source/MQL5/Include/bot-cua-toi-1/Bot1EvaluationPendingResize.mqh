// Recreate pending orders after the native volume changed (RVA 0x1a817..0x1b317).
#ifndef BOT1_EVALUATION_PENDING_RESIZE_MQH
#define BOT1_EVALUATION_PENDING_RESIZE_MQH
#include "Bot1OrderCancel.mqh"

void Bot1ResizeOnePending(const ENUM_ORDER_TYPE type,const ulong saved_ticket,
                          const int &strategy_magic,const uchar &virtual_expiration,
                          const string &symbol,const double &change_percent,
                          const double &volumes[],const uint &strategy_index,
                          double &results[][2],
                          Bot1PendingRequestState &trade,Bot1TradeSendOptions &options,
                          const double sl,const double tp,const double price,
                          const datetime expiration,const string comment)
{
   Bot1DeletePending(trade,options,saved_ticket);

   const double volume=volumes[strategy_index];
   const bool accepted=Bot1OpenPending(trade,options,strategy_magic,virtual_expiration,
                                       symbol,type,volume,price,sl,tp,comment,expiration);
   const double recorded=(double)(int)saved_ticket;
   for(int row=0;row<100;row++)
   {
      if(results[row][0]==recorded)
      {
         results[row][0]=(double)(uint)accepted;
         break;
      }
   }
   const string prefix=type==ORDER_TYPE_BUY_STOP ? "lotsize changed more than "
                                                  : "Lotsize changed more than ";
   Print(prefix+(string)change_percent+"%... adjusting lotsize of pending orders");
   Sleep(1000);
}

void Bot1ResizeEvaluationPending(const int &strategy_magic,const uchar &virtual_expiration,
                                 const string &symbol,const double &change_percent,
                                 const double &volumes[],const uint &strategy_index,
                                 ulong &last_ticket,double &results[][2],
                                 Bot1PendingRequestState &trade,Bot1TradeSendOptions &options)
{
   const int total=OrdersTotal();
   if(total<0) return;
   for(int index=total;index>=0;index--)
   {
      last_ticket=OrderGetTicket(index);
      if(last_ticket==0) continue;
      if(OrderGetInteger(ORDER_MAGIC)!=(long)strategy_magic) continue;
      if(OrderGetString(ORDER_SYMBOL)!=symbol) continue;

      const long first_type=OrderGetInteger(ORDER_TYPE);
      if(first_type==ORDER_TYPE_BUY_STOP)
      {
         const double old_volume=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)7);
         if(old_volume!=volumes[strategy_index])
         {
            const double sl=OrderGetDouble(ORDER_SL);
            const ulong saved_ticket=last_ticket;
            const double tp=OrderGetDouble(ORDER_TP);
            const double price=OrderGetDouble(ORDER_PRICE_OPEN);
            const datetime expiration=(datetime)OrderGetInteger(ORDER_TIME_EXPIRATION);
            const string comment=OrderGetString(ORDER_COMMENT);
            Bot1ResizeOnePending(ORDER_TYPE_BUY_STOP,saved_ticket,strategy_magic,
                                 virtual_expiration,symbol,change_percent,volumes,
                                 strategy_index,results,trade,options,
                                 sl,tp,price,expiration,comment);
         }
      }

      const long second_type=OrderGetInteger(ORDER_TYPE);
      if(second_type==ORDER_TYPE_SELL_STOP)
      {
         const double old_volume=OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)7);
         if(old_volume!=volumes[strategy_index])
         {
            const double sl=OrderGetDouble(ORDER_SL);
            const ulong saved_ticket=last_ticket;
            const double tp=OrderGetDouble(ORDER_TP);
            const double price=OrderGetDouble(ORDER_PRICE_OPEN);
            const datetime expiration=(datetime)OrderGetInteger(ORDER_TIME_EXPIRATION);
            const string comment=OrderGetString(ORDER_COMMENT);
            Bot1ResizeOnePending(ORDER_TYPE_SELL_STOP,saved_ticket,strategy_magic,
                                 virtual_expiration,symbol,change_percent,volumes,
                                 strategy_index,results,trade,options,
                                 sl,tp,price,expiration,comment);
         }
      }
   }
}

#endif
