#ifndef BOT3_EVALUATION_ACTIVE_FLOW_MQH
#define BOT3_EVALUATION_ACTIVE_FLOW_MQH
#include "Bot3EvaluationTradeFlow.mqh"
#include "Bot3EvaluationResizeFlow.mqh"
#include "Bot3EvaluationAvailability.mqh"
#include "Bot3OpenStatusPanel.mqh"

Bot3EntryLevelDecision Bot3EvaluateActiveFlow(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
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
                                             const double &weight_denominator,const uchar &enabled[],double &volumes[],
                                             const uchar &panel_show,const uchar &panel_tester,const double &panel_manual_lots,
                                             const bool evaluation_blocked,const uchar &day_switch_filter,
                                             const double &balance_change_percent,double &previous_balance)
{
   Bot3UpdateOpenStatusPanelFields(panel_show,panel_tester,execution.magic_base,execution.symbol,
                                   volume_state.effective_balance,volume_settings.frequency,volume_state.mode,panel_manual_lots,
                                   volume_settings.max_total_dd,volume_settings.strategy_risk,events,nfp_settings.enabled,
                                   nfp_settings.after_minutes,interest_settings.enabled,interest_settings.after_minutes,
                                   cpi_settings.enabled,cpi_settings.after_minutes,selection,execution.last_ticket);
   if(evaluation_blocked) return BOT3_LEVEL_STOP;
   Bot3RefreshEvaluationPending(loop_settings.volume_enabled,restore.sl_distance,volume_settings,volume_state,
                                reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,weight_denominator,enabled,
                                execution.strategy_magic,restore.virtual_expiration,execution.symbol,suffix,
                                balance_change_percent,previous_balance,current_index,volumes,execution.last_ticket,
                                queue.results,execution.trade,execution.options);
   if(!Bot3AllowsOrderEvaluation(day_switch_filter,cached_calendar,nfp.initialization_notice))
      return BOT3_LEVEL_STOP;
   return Bot3EvaluateTradeFlow(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                                nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
                                spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending,level_settings,
                                caller_index,current_index,bar_times,upper,lower,loop_settings,loop_state,volume_settings,
                                volume_state,reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,
                                weight_denominator,enabled,volumes);
}

#endif
