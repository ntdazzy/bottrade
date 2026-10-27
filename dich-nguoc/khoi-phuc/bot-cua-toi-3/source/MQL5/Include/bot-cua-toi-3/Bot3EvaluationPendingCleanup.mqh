// Native evaluator order cleanup 0x212ff..0x214ee.
#ifndef BOT3_EVALUATION_PENDING_CLEANUP_MQH
#define BOT3_EVALUATION_PENDING_CLEANUP_MQH
#include "Bot3OrderCancel.mqh"

void Bot3CleanEvaluationPending(const uchar caller_flag,const int &strategy_magic,
                                const string &symbol,double &results[][2],
                                Bot3PendingRequestState &trade,
                                Bot3TradeSendOptions &options)
{
   if(caller_flag==0) return;
   const int total=OrdersTotal();
   for(int index=total-1;index>=0;index--)
   {
      const ulong ticket=OrderGetTicket(index);
      if(ticket==0) continue;
      if(OrderGetInteger(ORDER_MAGIC)!=(long)strategy_magic) continue;
      if(OrderGetString(ORDER_SYMBOL)!=symbol) continue;
      const uint type=(uint)OrderGetInteger(ORDER_TYPE);
      if((type&0xfffffffe)==0) continue;
      if(!Bot3DeletePending(trade,options,ticket)) continue;
      const double recorded=(double)(long)ticket;
      for(int row=0;row<100;row++)
      {
         if(results[row][0]==recorded)
         {
            results[row][0]=0.0;
            results[row][1]=0.0;
            break;
         }
      }
   }
}

#endif
