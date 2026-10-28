#ifndef BOT3_STRATEGY_HOUR_MQH
#define BOT3_STRATEGY_HOUR_MQH

// Original dispatcher 0x194ef..0x19550. Reuse the result for each strategy.
bool Bot3StrategyHourChanged(const string &symbol,long &previous_hour)
{
   const long previous=previous_hour;
   const long first=(long)iTime(symbol,PERIOD_H1,1);
   if(previous==first) return false;
   previous_hour=(long)iTime(symbol,PERIOD_H1,1);
   return true;
}

#endif
