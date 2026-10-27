#ifndef BOT3_EVALUATION_ENTRY_LEVELS_MQH
#define BOT3_EVALUATION_ENTRY_LEVELS_MQH
#include "Bot3EvaluationNewsAndOrders.mqh"
#include "Bot3EntryLevelCache.mqh"

Bot3EntryLevelDecision Bot3EvaluateThroughEntryLevels(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                                                     const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                                                     const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                                                     Bot3NewsEvents &events,const MqlDateTime &cached_calendar,
                                                     const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                                     Bot3NfpExecution &execution,Bot3NewsSelection &selection,
                                                     const Bot3FridaySettings &friday,uchar &friday_closed,
                                                     const Bot3SpreadSettings &spread_settings,const double &unit,double &spread,
                                                     Bot3PendingQueue &queue,const Bot3PendingRestoreSettings &restore,
                                                     const int &pending_enabled,const int &maximum_pending,
                                                     const Bot3LevelCacheSettings &settings,const uint caller_index,
                                                     uint &current_index,long &bar_times[],double &upper[],double &lower[])
{
   if(Bot3EvaluateNewsAndPendingLimits(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                                       nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
                                       spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending))
      return BOT3_LEVEL_STOP;
   return Bot3UpdateEntryLevelCache(pending_enabled,friday_closed,settings,caller_index,current_index,execution,unit,
                                     spread,bar_times,upper,lower);
}

#endif
