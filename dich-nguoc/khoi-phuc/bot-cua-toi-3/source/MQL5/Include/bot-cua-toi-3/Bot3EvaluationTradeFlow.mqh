#ifndef BOT3_EVALUATION_TRADE_FLOW_MQH
#define BOT3_EVALUATION_TRADE_FLOW_MQH
#include "Bot3EvaluationEntryLevels.mqh"
#include "Bot3EntryLoop.mqh"

Bot3EntryLevelDecision Bot3EvaluateTradeFlow(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                                             const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                                             const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                                             Bot3NewsEvents &events,const MqlDateTime &cached_calendar,
                                             const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                             Bot3NfpExecution &execution,Bot3NewsSelection &selection,
                                             const Bot3FridaySettings &friday,uchar &friday_closed,
                                             const Bot3SpreadSettings &spread_settings,const double &unit,double &spread,
                                             Bot3PendingQueue &queue,Bot3PendingRestoreSettings &restore,
                                             const int &pending_enabled,const int &maximum_pending,
                                             const Bot3LevelCacheSettings &level_settings,const uint caller_index,
                                             uint &current_index,long &bar_times[],double &upper[],double &lower[],
                                             const Bot3EntryLoopSettings &loop_settings,Bot3EntryLoopState &loop_state,
                                             const Bot3VolumeSettings &volume_settings,Bot3VolumeState &volume_state,
                                             const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                                             long &last_check,long &last_deal_time,const string &suffix,
                                             const double &weight_denominator,const uchar &enabled[],double &volumes[])
{
   const Bot3EntryLevelDecision decision=Bot3EvaluateThroughEntryLevels(
      nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
      nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
      spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending,level_settings,
      caller_index,current_index,bar_times,upper,lower);
   if(decision==BOT3_LEVEL_NEW_BAR)
      Bot3RunEntryLoop(maximum_pending,loop_settings,loop_state,volume_settings,volume_state,
                       reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,
                       weight_denominator,enabled,unit,current_index,volumes,restore,execution,queue);
   return decision;
}

#endif
