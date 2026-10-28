#ifndef BOT1_STRATEGY_STATISTICS_MQH
#define BOT1_STRATEGY_STATISTICS_MQH
#include "Bot1StrategyHistory.mqh"

void Bot1UpdateStrategyStatistics(const bool hour_changed,const uint caller_index,
                                  const uchar &show_tester,const string &symbol,const int &magic,
                                  const uint &current_index,int &closed_trades[],
                                  Bot1StrategyHistoryCache &cache,double &total[],double &average[])
{
   if(!hour_changed) return;
   const double amount=Bot1StrategyClosedProfit(show_tester,symbol,magic,current_index,closed_trades,cache);
   total[caller_index]=amount;
   if(amount!=0.0 && closed_trades[caller_index]>0)
      average[caller_index]=amount/(double)closed_trades[caller_index];
}

#endif
