#ifndef BOT1_STRATEGY_CYCLE_MQH
#define BOT1_STRATEGY_CYCLE_MQH
#include "Bot1EvaluationBridge.mqh"
#include "Bot1StrategyHour.mqh"
#include "Bot1StrategyStatistics.mqh"

// The caller obtains hour_changed once before processing any strategy.
Bot1EntryLevelDecision Bot1SetupEvaluateAndUpdateStatistics(const uint index,const bool use_hl,
                                            const Bot1ProfileAdjustments &adjustments,
                                            Bot1PreparationInputs &inputs,
                                            const Bot1StrategyContextInputs &context_inputs,
                                            Bot1ProfileRuntimeState &profile_state,
                                            Bot1StrategyContextState &context_state,
                                            Bot1PreparationState &preparation,
                                            Bot1NfpExecution &execution,
                                            const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                                            const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                                            const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                                            Bot1NewsEvents &events,MqlDateTime &cached_calendar,
                                            const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                            Bot1NewsSelection &selection,const Bot1FridaySettings &friday,uchar &friday_closed,
                                            Bot1SpreadSettings &spread_settings,double &spread,
                                            Bot1PendingQueue &queue,Bot1PendingRestoreSettings &restore,
                                            Bot1LevelCacheSettings &level_settings,
                                            uint &current_index,long &bar_times[],double &upper[],double &lower[],
                                            Bot1EntryLoopSettings &loop_settings,Bot1EntryLoopState &loop_state,
                                            Bot1VolumeSettings &volume_settings,Bot1VolumeState &volume_state,
                                            const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                                            long &last_check,long &last_deal_time,const string &suffix,double &volumes[],
                                            const uchar &panel_show,const uchar &panel_tester,const int &panel_mode,
                                            const double &panel_trade_risk,const int &panel_balance_step,
                                            const uchar &day_switch_filter,const double &balance_change_percent,
                                            double &previous_balance,Bot1EvaluationPrefixSettings &prefix,
                                            Bot1EvaluationPrefixState &state,Bot1DisplayState &display,
                                            const bool hour_changed,int &closed_trades[],
                                            Bot1StrategyHistoryCache &history_cache,
                                            double &strategy_totals[],double &strategy_average[])
{
   const Bot1EntryLevelDecision result=Bot1SetupAndEvaluate(
      index, use_hl, adjustments, inputs, context_inputs, profile_state, context_state,
      preparation, execution, nfp_settings, nfp, interest_settings, interest, cpi_settings,
      cpi, events, cached_calendar, nfp_history, interest_history, cpi_history, selection,
      friday, friday_closed, spread_settings, spread, queue, restore, level_settings,
      current_index, bar_times, upper, lower, loop_settings, loop_state, volume_settings,
      volume_state, reset_on_withdrawal, peak_key, time_key, last_check, last_deal_time, suffix,
      volumes, panel_show, panel_tester, panel_mode, panel_trade_risk, panel_balance_step, day_switch_filter,
      balance_change_percent, previous_balance, prefix, state, display);
   Bot1UpdateStrategyStatistics(hour_changed,index,panel_tester,inputs.symbol,context_state.magic,
                                 current_index,closed_trades,history_cache,strategy_totals,strategy_average);
   preparation.strategy_index=current_index;
   execution.symbol=inputs.symbol;
   execution.strategy_magic=context_state.magic;
   return result;
}
#endif
