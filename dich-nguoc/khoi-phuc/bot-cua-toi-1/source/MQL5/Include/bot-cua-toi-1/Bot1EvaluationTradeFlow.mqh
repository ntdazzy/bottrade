#ifndef BOT1_EVALUATION_TRADE_FLOW_MQH
#define BOT1_EVALUATION_TRADE_FLOW_MQH
#include "Bot1EvaluationEntryLevels.mqh"
#include "Bot1EntryLoop.mqh"

Bot1EntryLevelDecision Bot1EvaluateTradeFlow(const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                                             const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                                             const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                                             Bot1NewsEvents &events,const MqlDateTime &cached_calendar,
                                             const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                             Bot1NfpExecution &execution,Bot1NewsSelection &selection,
                                             const Bot1FridaySettings &friday,uchar &friday_closed,
                                             const Bot1SpreadSettings &spread_settings,const double &unit,double &spread,
                                             Bot1PendingQueue &queue,Bot1PendingRestoreSettings &restore,
                                             const int &pending_enabled,const int &maximum_pending,
                                             const Bot1LevelCacheSettings &level_settings,const uint caller_index,
                                             uint &current_index,long &bar_times[],double &upper[],double &lower[],
                                             const Bot1EntryLoopSettings &loop_settings,Bot1EntryLoopState &loop_state,
                                             const Bot1VolumeSettings &volume_settings,Bot1VolumeState &volume_state,
                                             const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                                             long &last_check,long &last_deal_time,const string &suffix,double &volumes[])
{
   const Bot1EntryLevelDecision decision=Bot1EvaluateThroughEntryLevels(
      nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
      nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
      spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending,level_settings,
      caller_index,current_index,bar_times,upper,lower);
   if(decision==BOT1_LEVEL_NEW_BAR)
      Bot1RunEntryLoop(maximum_pending,loop_settings,loop_state,volume_settings,volume_state,
                       reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,unit,
                       current_index,volumes,restore,execution,queue);
   return decision;
}

#endif
