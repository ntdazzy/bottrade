#ifndef BOT1_ENTRY_LEVEL_CACHE_MQH
#define BOT1_ENTRY_LEVEL_CACHE_MQH
#include "Bot1NfpFilter.mqh"
#include "Bot1PriceLevels.mqh"
#include "Bot1PendingQueue.mqh"

enum Bot1EntryLevelDecision
{
   BOT1_LEVEL_STOP=0,
   BOT1_LEVEL_SAME_BAR=1,
   BOT1_LEVEL_NEW_BAR=2
};

struct Bot1LevelCacheSettings
{
   ENUM_TIMEFRAMES timeframe,aux_timeframe;
   int aux_older,aux_recent,last_shift;
   double aux_offset;
   uchar blocked;
};

Bot1EntryLevelDecision Bot1UpdateEntryLevelCache(const int &pending_enabled,const uchar &friday_closed,
                                                 const Bot1LevelCacheSettings &settings,const uint caller_index,
                                                 uint &current_index,Bot1NfpExecution &execution,const double &unit,
                                                 const double &spread,long &bar_times[],double &upper[],double &lower[])
{
   if(friday_closed!=0 || pending_enabled!=1 || settings.blocked!=0) return BOT1_LEVEL_STOP;
   const long previous=bar_times[caller_index];
   const long observed=(long)iTime(execution.symbol,settings.timeframe,1);
   if(previous==observed) return BOT1_LEVEL_SAME_BAR;
   const long current=(long)iTime(execution.symbol,settings.timeframe,1);
   bar_times[caller_index]=current;
   if(settings.aux_older>0)
   {
      const double upper_result=Bot1UpperLevel(execution.symbol,settings.aux_timeframe,settings.aux_older,
                                               settings.aux_recent,settings.last_shift,execution.tick.ask,
                                               execution.threshold_a);
      const uint upper_slot=current_index;
      upper[upper_slot]=Bot1QueueSum(Bot1QueueProduct(settings.aux_offset,unit),
                                     Bot1QueueSum(upper_result,spread));
      const double lower_result=Bot1LowerLevel(execution.symbol,settings.aux_timeframe,settings.aux_older,
                                               settings.aux_recent,settings.last_shift,execution.tick.bid,
                                               execution.threshold_a);
      const uint lower_slot=current_index;
      lower[lower_slot]=Bot1QueueDifference(lower_result,Bot1QueueProduct(settings.aux_offset,unit));
   }
   return BOT1_LEVEL_NEW_BAR;
}

#endif
