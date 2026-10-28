#ifndef BOT1_STRATEGY_HOUR_MQH
#define BOT1_STRATEGY_HOUR_MQH

// Original dispatcher 0x11ed7..0x11f3f. Reuse the result for each strategy.
bool Bot1StrategyHourChanged(const string &symbol,long &previous_hour)
{
   const long previous=previous_hour;
   const long first=(long)iTime(symbol,PERIOD_H1,1);
   if(previous==first) return false;
   previous_hour=(long)iTime(symbol,PERIOD_H1,1);
   return true;
}

#endif
