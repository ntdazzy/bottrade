#ifndef BOT3_ENTRY_LEVEL_CACHE_MQH
#define BOT3_ENTRY_LEVEL_CACHE_MQH
#include "Bot3NfpFilter.mqh"
#include "Bot3PriceLevels.mqh"
#include "Bot3PendingQueue.mqh"

enum Bot3EntryLevelDecision
{
   BOT3_LEVEL_STOP=0,
   BOT3_LEVEL_SAME_BAR=1,
   BOT3_LEVEL_NEW_BAR=2
};

struct Bot3LevelCacheSettings
{
   ENUM_TIMEFRAMES timeframe,aux_timeframe;
   int aux_older,aux_recent,last_shift;
   double aux_offset;
   uchar blocked;
};

Bot3EntryLevelDecision Bot3UpdateEntryLevelCache(const int &pending_enabled,const uchar &friday_closed,
                                                 const Bot3LevelCacheSettings &settings,const uint caller_index,
                                                 uint &current_index,Bot3NfpExecution &execution,const double &unit,
                                                 const double &spread,long &bar_times[],double &upper[],double &lower[])
{
   if(friday_closed!=0 || pending_enabled!=1 || settings.blocked!=0) return BOT3_LEVEL_STOP;
   const long previous=bar_times[caller_index];
   const long observed=(long)iTime(execution.symbol,settings.timeframe,1);
   if(previous==observed) return BOT3_LEVEL_SAME_BAR;
   const long current=(long)iTime(execution.symbol,settings.timeframe,1);
   bar_times[caller_index]=current;
   if(settings.aux_older>0)
   {
      const double upper_result=Bot3UpperLevel(execution.symbol,settings.aux_timeframe,settings.aux_older,
                                               settings.aux_recent,settings.last_shift,execution.tick.ask,
                                               execution.threshold_a);
      const uint upper_slot=current_index;
      upper[upper_slot]=Bot3QueueSum(Bot3QueueProduct(settings.aux_offset,unit),
                                     Bot3QueueSum(upper_result,spread));
      const double lower_result=Bot3LowerLevel(execution.symbol,settings.aux_timeframe,settings.aux_older,
                                               settings.aux_recent,settings.last_shift,execution.tick.bid,
                                               execution.threshold_a);
      const uint lower_slot=current_index;
      lower[lower_slot]=Bot3QueueDifference(lower_result,Bot3QueueProduct(settings.aux_offset,unit));
   }
   return BOT3_LEVEL_NEW_BAR;
}

#endif
