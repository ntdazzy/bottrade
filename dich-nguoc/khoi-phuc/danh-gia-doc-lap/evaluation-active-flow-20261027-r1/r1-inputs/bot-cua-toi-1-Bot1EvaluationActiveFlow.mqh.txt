#ifndef BOT1_EVALUATION_ACTIVE_FLOW_MQH
#define BOT1_EVALUATION_ACTIVE_FLOW_MQH
#include "Bot1EvaluationTradeFlow.mqh"
#include "Bot1EvaluationResizeFlow.mqh"
#include "Bot1EvaluationAvailability.mqh"
#include "Bot1OpenStatusPanel.mqh"

Bot1EntryLevelDecision Bot1EvaluateActiveFlow(const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
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
                                             long &last_check,long &last_deal_time,const string &suffix,double &volumes[],
                                             const uchar &panel_show,const uchar &panel_tester,const int &panel_mode,
                                             const double &panel_trade_risk,const int &panel_balance_step,
                                             const bool evaluation_blocked,const uchar &day_switch_filter,
                                             const double &balance_change_percent,double &previous_balance)
{
   Bot1UpdateOpenStatusPanelFields(panel_show,panel_tester,execution.magic_base,execution.symbol,
                                   volume_state.effective_balance,volumes[0],panel_mode,panel_trade_risk,
                                   volume_settings.strategy_risk,panel_balance_step,events,nfp_settings.enabled,
                                   nfp_settings.after_minutes,interest_settings.enabled,interest_settings.after_minutes,
                                   cpi_settings.enabled,cpi_settings.after_minutes,selection,execution.last_ticket);
   if(evaluation_blocked) return BOT1_LEVEL_STOP;
   Bot1RefreshEvaluationPending(loop_settings.volume_enabled,restore.sl_distance,volume_settings,volume_state,
                                reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,
                                execution.strategy_magic,restore.virtual_expiration,execution.symbol,suffix,
                                balance_change_percent,previous_balance,current_index,volumes,execution.last_ticket,
                                queue.results,execution.trade,execution.options);
   if(!Bot1AllowsOrderEvaluation(day_switch_filter,cached_calendar,nfp.initialization_notice))
      return BOT1_LEVEL_STOP;
   return Bot1EvaluateTradeFlow(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                                 nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
                                 spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending,level_settings,
                                 caller_index,current_index,bar_times,upper,lower,loop_settings,loop_state,volume_settings,
                                 volume_state,reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,volumes);
}

#endif
