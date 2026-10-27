// Evaluator through its closed-history display and hourly results cleanup.
#ifndef BOT3_EVALUATION_WITH_DISPLAY_MQH
#define BOT3_EVALUATION_WITH_DISPLAY_MQH
#include "Bot3Evaluation.mqh"
#include "Bot3ClosedStatusPanel.mqh"
#include "Bot3OrderScan.mqh"
struct Bot3DisplayState { double wins,losses;int last_hour; };
Bot3EntryLevelDecision Bot3EvaluateWithDisplay(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                                             const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                                             const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                                             Bot3NewsEvents &events,MqlDateTime &cached_calendar,
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
                                             const double &weight_denominator,const uchar &enabled[],double &volumes[],
                                             const uchar &panel_show,const uchar &panel_tester,const double &panel_manual_lots,
                                             const uchar &day_switch_filter,
                                             const double &balance_change_percent,double &previous_balance,
                                             Bot3EvaluationPrefixSettings &prefix,Bot3EvaluationPrefixState &state,Bot3DisplayState &display)
{
   const Bot3EntryLevelDecision decision=Bot3Evaluate(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending,level_settings,caller_index,current_index,bar_times,upper,lower,loop_settings,loop_state,volume_settings,volume_state,reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,weight_denominator,enabled,volumes,panel_show,panel_tester,panel_manual_lots,day_switch_filter,balance_change_percent,previous_balance,prefix,state);
   if(decision!=BOT3_LEVEL_STOP)
   {
      Bot3UpdateClosedStatusPanel(panel_show,panel_tester,execution.magic_base,execution.symbol,display.wins,display.losses);
      if(display.last_hour!=cached_calendar.hour)
      {
         display.last_hour=cached_calendar.hour;
         Bot3CleanPendingResults(queue.results,execution.last_ticket);
      }
   }
   return decision;
}
#endif
