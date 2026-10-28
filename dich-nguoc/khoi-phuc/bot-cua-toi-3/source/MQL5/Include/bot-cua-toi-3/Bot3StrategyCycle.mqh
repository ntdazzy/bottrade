#ifndef BOT3_STRATEGY_CYCLE_MQH
#define BOT3_STRATEGY_CYCLE_MQH
#include "Bot3EvaluationBridge.mqh"
#include "Bot3StrategyHour.mqh"
#include "Bot3StrategyStatistics.mqh"

// The caller obtains hour_changed once before processing any strategy.
Bot3EntryLevelDecision Bot3SetupEvaluateAndUpdateStatistics(const uint index,const uchar &strategy_enabled,
                                            const Bot3ProfileAdjustments &adjustments,
                                            Bot3PreparationInputs &inputs,
                                            const Bot3StrategyContextInputs &context_inputs,
                                            Bot3ProfileRuntimeState &profile_state,
                                            Bot3StrategyContextState &context_state,
                                            Bot3PreparationState &preparation,
                                            Bot3NfpExecution &execution,
                                            const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                                            const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                                            const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                                            Bot3NewsEvents &events,MqlDateTime &cached_calendar,
                                            const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                            Bot3NewsSelection &selection,const Bot3FridaySettings &friday,uchar &friday_closed,
                                            Bot3SpreadSettings &spread_settings,double &spread,
                                            Bot3PendingQueue &queue,Bot3PendingRestoreSettings &restore,
                                            Bot3LevelCacheSettings &level_settings,
                                            uint &current_index,long &bar_times[],double &upper[],double &lower[],
                                            Bot3EntryLoopSettings &loop_settings,Bot3EntryLoopState &loop_state,
                                            Bot3VolumeSettings &volume_settings,Bot3VolumeState &volume_state,
                                            const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                                            long &last_check,long &last_deal_time,const string &suffix,
                                            const double &weight_denominator,const uchar &enabled[],double &volumes[],
                                            const uchar &panel_show,const uchar &panel_tester,const double &panel_manual_lots,
                                            const uchar &day_switch_filter,const double &balance_change_percent,
                                            double &previous_balance,Bot3EvaluationPrefixSettings &prefix,
                                            Bot3EvaluationPrefixState &state,Bot3DisplayState &display,
                                            const bool hour_changed,int &closed_trades[],
                                            Bot3StrategyHistoryCache &history_cache,
                                            double &strategy_totals[],double &strategy_average[])
{
   const Bot3EntryLevelDecision result=Bot3SetupAndEvaluate(
      index, strategy_enabled, adjustments, inputs, context_inputs, profile_state, context_state, preparation,
      execution, nfp_settings, nfp, interest_settings, interest, cpi_settings, cpi,
      events, cached_calendar, nfp_history, interest_history, cpi_history, selection, friday,
      friday_closed, spread_settings, spread, queue, restore, level_settings, current_index,
      bar_times, upper, lower, loop_settings, loop_state, volume_settings, volume_state,
      reset_on_withdrawal, peak_key, time_key, last_check, last_deal_time, suffix, weight_denominator,
      enabled, volumes, panel_show, panel_tester, panel_manual_lots, day_switch_filter, balance_change_percent,
      previous_balance, prefix, state, display);
   Bot3UpdateStrategyStatistics(hour_changed,index,panel_tester,inputs.symbol,context_state.magic,
                                 current_index,closed_trades,history_cache,strategy_totals,strategy_average);
   preparation.strategy_index=current_index;
   execution.symbol=inputs.symbol;
   execution.strategy_magic=context_state.magic;
   return result;
}
#endif
