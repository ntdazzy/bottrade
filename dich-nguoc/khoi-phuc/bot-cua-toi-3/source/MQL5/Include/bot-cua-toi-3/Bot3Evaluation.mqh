// Continuous evaluator through the entry loop; final display/lifecycle remain separate.
#ifndef BOT3_EVALUATION_MQH
#define BOT3_EVALUATION_MQH
#include "Bot3EvaluationActiveFlow.mqh"
#include "Bot3EvaluationPrelude.mqh"
#include "Bot3EvaluationStops.mqh"
#include "Bot3ManagementBarGate.mqh"
#include "Bot3EvaluationPendingCleanup.mqh"
struct Bot3EvaluationPrefixSettings
{
   Bot3EvaluationHeadInputs inputs;
   Bot3PositionManagementSettings management;
   int management_timeframe;
   uchar caller_flag;
};
struct Bot3EvaluationPrefixState
{
   Bot3EvaluationPreludeState prelude;
   Bot3PositionManagementState management;
   long management_times[9];
};
Bot3EntryLevelDecision Bot3Evaluate(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
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
                                             Bot3EvaluationPrefixSettings &prefix,Bot3EvaluationPrefixState &state)
{
   bool reported_sessions=false;
   const uchar caller_flag=prefix.caller_flag;
   Bot3PrepareEvaluationFields(caller_index,caller_flag,prefix.inputs,state.prelude,execution.symbol,execution.tick,
                                spread,cached_calendar,reported_sessions);
   Bot3CleanEvaluationPending(caller_flag,execution.strategy_magic,execution.symbol,queue.results,execution.trade,execution.options);
   Bot3FillEvaluationStopsFields(execution.symbol,loop_settings.submission.omit_real_sl_tp,
      execution.strategy_magic,restore.sl_distance,restore.tp_distance,unit,execution.trade,execution.options);
   if(Bot3ManageOnBarChangeFields(execution.symbol,prefix.management_timeframe,caller_index,state.management_times,
      prefix.management,state.management,lower,upper,execution.trade,execution.options,execution.deviation,
      loop_state.active_step,queue.results,volumes,current_index,queue.error_count,execution.last_ticket,execution.tick,execution.strategy_magic,unit,restore.sl_distance,restore.tp_distance,execution.threshold_a,execution.gap,level_settings.aux_older,loop_settings.step_reference,pending_enabled,spread)) return BOT3_LEVEL_STOP;
   const bool evaluation_blocked=caller_flag!=0 || state.prelude.session_flag!=0;
   return Bot3EvaluateActiveFlow(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending,level_settings,caller_index,current_index,bar_times,upper,lower,loop_settings,loop_state,volume_settings,volume_state,reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,weight_denominator,enabled,volumes,panel_show,panel_tester,panel_manual_lots,evaluation_blocked,day_switch_filter,balance_change_percent,previous_balance);
}
#endif
