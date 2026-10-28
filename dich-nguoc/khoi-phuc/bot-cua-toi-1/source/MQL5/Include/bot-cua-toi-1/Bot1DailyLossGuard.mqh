#ifndef BOT1_DAILY_LOSS_GUARD_MQH
#define BOT1_DAILY_LOSS_GUARD_MQH
#include "Bot1FridayClose.mqh"
#include "Bot1PendingQueue.mqh"

struct Bot1DailyLossState
{
   int bars;
   uchar blocked;
   double peak;
};

union Bot1DailyLossBits
{
   double value;
   ulong bits;
};

double Bot1DailyLossNegate(const double value)
{
   Bot1DailyLossBits bits;
   bits.value=value;
   bits.bits^=0x8000000000000000;
   return bits.value;
}

bool Bot1ProcessDailyLoss(const double &percent,Bot1DailyLossState &state,
                          Bot1NfpExecution &execution)
{
   const int current_bars=Bars(execution.symbol,PERIOD_D1);
   if(current_bars!=state.bars)
   {
      state.bars=Bars(execution.symbol,PERIOD_D1);
      state.blocked=0;
      state.peak=0.0;
   }
   const double cached_percent=percent;
   if(cached_percent>0.0)
   {
      double equity=AccountInfoDouble(ACCOUNT_EQUITY);
      double balance=AccountInfoDouble(ACCOUNT_BALANCE);
      if(equity==balance) return state.blocked!=0;
      equity=AccountInfoDouble(ACCOUNT_EQUITY);
      if(state.peak<equity) state.peak=AccountInfoDouble(ACCOUNT_EQUITY);

      double sum=0.0;
      if(HistorySelect((datetime)0,(datetime)0x7fffffff))
      {
         const int total=HistoryDealsTotal();
         for(int index=(int)((uint)total-1);index>=0;index--)
         {
            const ulong ticket=HistoryDealGetTicket(index);
            const long deal_time=HistoryDealGetInteger(ticket,DEAL_TIME);
            const datetime day_time=iTime(execution.symbol,PERIOD_D1,0);
            if(day_time<=deal_time && HistoryDealGetInteger(ticket,DEAL_ENTRY)==1)
            {
               const double profit=HistoryDealGetDouble(ticket,DEAL_PROFIT);
               const double commission=HistoryDealGetDouble(ticket,DEAL_COMMISSION);
               double part=Bot1QueueSum(profit,commission);
               const double swap=HistoryDealGetDouble(ticket,DEAL_SWAP);
               part=Bot1QueueSum(part,swap);
               sum=Bot1QueueSum(sum,part);
            }
         }
      }
      equity=AccountInfoDouble(ACCOUNT_EQUITY);
      balance=AccountInfoDouble(ACCOUNT_BALANCE);
      const double loss=Bot1DailyLossNegate(Bot1QueueSum(Bot1QueueDifference(equity,balance),sum));
      const double threshold=Bot1QueueProduct(cached_percent,state.peak)/100.0;
      if(threshold<loss)
      {
         if(state.blocked==0) Print("Max Daily Drawdown reached, closing trades and skipping rest of the day");
         Bot1CloseForFriday(execution);
         state.blocked=1;
         state.peak=0.0;
         return true;
      }
   }
   return state.blocked!=0;
}

#endif
