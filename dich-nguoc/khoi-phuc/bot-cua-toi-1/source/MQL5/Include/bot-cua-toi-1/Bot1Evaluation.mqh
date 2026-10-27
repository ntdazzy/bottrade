// Continuous evaluator through the entry loop; final display/lifecycle remain separate.
#ifndef BOT1_EVALUATION_MQH
#define BOT1_EVALUATION_MQH
#include "Bot1EvaluationActiveFlow.mqh"
#include "Bot1EvaluationPrelude.mqh"
#include "Bot1EvaluationStops.mqh"
#include "Bot1ManagementRouter.mqh"
#include "Bot1ManagementCallerContext.mqh"
struct Bot1EvaluationPrefixSettings
{
   Bot1EvaluationPreludeInputs inputs;
   Bot1PositionManagementSettings management;
   int management_timeframe;
   uchar license_valid,tick_management,bar_override;bool incoming_changed;
};
struct Bot1EvaluationPrefixState
{
   Bot1EvaluationPreludeState prelude;
   Bot1PositionManagementState management;
   long management_times[8];
};
Bot1EntryLevelDecision Bot1Evaluate(const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                                             const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                                             const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                                             Bot1NewsEvents &events,MqlDateTime &cached_calendar,
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
                                             long &last_check,long &last_deal_time,const string &suffix,double &volumes[],
                                             const uchar &panel_show,const uchar &panel_tester,const int &panel_mode,
                                             const double &panel_trade_risk,const int &panel_balance_step,
                                             const uchar &day_switch_filter,
                                             const double &balance_change_percent,double &previous_balance,
                                             Bot1EvaluationPrefixSettings &prefix,Bot1EvaluationPrefixState &state)
{
   bool reported_sessions=false;
   Bot1PrepareEvaluationFields(caller_index,prefix.inputs,state.prelude,execution.symbol,execution.tick,
                                spread,cached_calendar,reported_sessions);
   const int initial_total=Bot1FillEvaluationStopsFields(execution.symbol,loop_settings.submission.omit_real_sl_tp,
      execution.strategy_magic,restore.sl_distance,restore.tp_distance,unit,execution.trade,execution.options);
   const bool first_zero=Bot1BarFirstZeroTicketChanged(loop_settings.submission.omit_real_sl_tp,initial_total,
      state.prelude.calendar.day_of_week,reported_sessions,prefix.incoming_changed);
   if(Bot1RoutePositionManagementFields(prefix.license_valid,prefix.tick_management,prefix.bar_override,
      prefix.management_timeframe,caller_index,state.management_times,prefix.management,state.management,
      lower,upper,execution.trade,execution.options,execution.deviation,first_zero,
      loop_state.active_step,queue.results,volumes,current_index,queue.error_count,execution.last_ticket,execution.tick,execution.symbol,execution.strategy_magic,unit,restore.sl_distance,restore.tp_distance,execution.threshold_a,execution.gap,level_settings.aux_older,loop_settings.step_reference,pending_enabled,spread)) return BOT1_LEVEL_STOP;
   const bool evaluation_blocked=state.prelude.session_flag!=0;
   return Bot1EvaluateActiveFlow(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending,level_settings,caller_index,current_index,bar_times,upper,lower,loop_settings,loop_state,volume_settings,volume_state,reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,volumes,panel_show,panel_tester,panel_mode,panel_trade_risk,panel_balance_step,evaluation_blocked,day_switch_filter,balance_change_percent,previous_balance);
}
#endif
