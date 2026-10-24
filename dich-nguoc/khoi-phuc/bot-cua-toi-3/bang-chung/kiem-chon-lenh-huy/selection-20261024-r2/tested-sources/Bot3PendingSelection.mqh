// Native 0x3da90/0x3dd60: select, ignore cancel bool, clear first row, print.
#ifndef BOT3_PENDING_SELECTION_MQH
#define BOT3_PENDING_SELECTION_MQH
#include "Bot3OrderCancel.mqh"
void Bot3DeleteExtremePending(const bool buy,const int &strategy_magic,const string &symbol,
                              ulong &last_ticket,double &results[][2],
                              Bot3PendingRequestState &state,Bot3TradeSendOptions &options)
{
   string order_symbol;
   ulong candidate=0;
   double candidate_price=buy ? 0.0 : 9999.0;
   long kind=buy ? (long)ORDER_TYPE_BUY_STOP : (long)ORDER_TYPE_SELL_STOP;
   for(int index=OrdersTotal();index>=0;index--)
   {
      last_ticket=OrderGetTicket(index);
      if(last_ticket==0) continue;
      if(OrderGetInteger(ORDER_MAGIC)!=(long)strategy_magic) continue;
      order_symbol=OrderGetString(ORDER_SYMBOL);
      if(order_symbol!=symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)!=kind) continue;
      double price=OrderGetDouble(ORDER_PRICE_OPEN);
      if((buy && price>candidate_price) || (!buy && price<candidate_price))
      {
         candidate=last_ticket;
         candidate_price=OrderGetDouble(ORDER_PRICE_OPEN);
      }
   }
   if(candidate==0) return;
   Bot3DeletePending(state,options,candidate);
   double recorded=(double)(long)candidate;
   for(int row=0;row<100;row++)
   {
      if(results[row][0]==recorded)
      { results[row][0]=0.0;results[row][1]=0.0;break; }
   }
   if(buy) Print("Max number of pending buy orders reached... deleting highest buystop order!");
   else Print("Max number of pending sell orders reached... deleting lowest sellstop order!");
}
void Bot3DeleteHighestBuyPending(const int &strategy_magic,const string &symbol,ulong &last_ticket,
                                double &results[][2],Bot3PendingRequestState &state,Bot3TradeSendOptions &options)
{
   Bot3DeleteExtremePending(true,strategy_magic,symbol,last_ticket,results,state,options);
}
void Bot3DeleteLowestSellPending(const int &strategy_magic,const string &symbol,ulong &last_ticket,
                                double &results[][2],Bot3PendingRequestState &state,Bot3TradeSendOptions &options)
{
   Bot3DeleteExtremePending(false,strategy_magic,symbol,last_ticket,results,state,options);
}
#endif
