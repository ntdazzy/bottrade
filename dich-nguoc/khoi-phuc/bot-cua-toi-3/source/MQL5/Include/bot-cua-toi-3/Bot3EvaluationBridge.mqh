#ifndef BOT3_EVALUATION_BRIDGE_MQH
#define BOT3_EVALUATION_BRIDGE_MQH

#include "Bot3StrategySetup.mqh"
#include "Bot3EntryLoop.mqh"
#include "Bot3EntryLevelCache.mqh"
#include "Bot3EvaluationWithDisplay.mqh"

void Bot3ProjectPreparationToEvaluation(const Bot3PreparationInputs &inputs,
                                        const Bot3PreparationState &preparation,
                                        const Bot3StrategyContextState &context,
                                        const int magic_base,const ulong deviation,
                                        Bot3NfpExecution &execution,const double &unit,
                                        Bot3PendingRestoreSettings &restore,
                                        Bot3EntryLoopSettings &loop,
                                        Bot3LevelCacheSettings &levels)
{
   execution.strategy_magic=context.magic;
   execution.magic_base=magic_base;
   execution.symbol=inputs.symbol;
   execution.tick=preparation.tick;
   execution.threshold_a=preparation.stop_min_price;
   execution.gap=preparation.freeze_min_price;
   execution.deviation=deviation;

   restore.sl_distance=preparation.stop_distance;
   restore.tp_distance=preparation.target_distance;
   restore.expiration_base=(datetime)preparation.expiration;
   restore.comment=context.order_comment;
   restore.virtual_expiration=preparation.virtual_expiration;

   loop.submission.check_free_margin=preparation.native_6d51c;
   loop.submission.omit_real_sl_tp=preparation.native_6d510;
   loop.confirmation_frame=(ENUM_TIMEFRAMES)preparation.entry_frame;
   loop.older_width=preparation.older_width;
   loop.recent_width=preparation.recent_width;
   loop.last_shift=preparation.last_shift;
   loop.expiration_setting=preparation.expiration_hours;
   loop.expiration_seconds=preparation.expiration_seconds;
   loop.gap_points=preparation.gap_points;
   loop.buy_offset=preparation.buy_offset;
   loop.sell_offset=preparation.sell_offset;
   loop.radius=preparation.nearby_radius;
   loop.step_reference=preparation.unit;

   levels.timeframe=(ENUM_TIMEFRAMES)preparation.entry_frame;
   levels.aux_timeframe=(ENUM_TIMEFRAMES)preparation.aux_frame;
   levels.aux_older=preparation.aux_older;
   levels.aux_recent=preparation.aux_recent;
   levels.last_shift=preparation.last_shift;
   levels.aux_offset=preparation.aux_offset;
}

void Bot3SetupAndProjectEvaluation(const uint index,
                                   const Bot3ProfileAdjustments &adjustments,
                                   Bot3PreparationInputs &inputs,
                                   const Bot3StrategyContextInputs &context_inputs,
                                   Bot3ProfileRuntimeState &profile_state,
                                   Bot3StrategyContextState &context_state,
                                   Bot3PreparationState &preparation,
                                   const int magic_base,const ulong deviation,
                                   Bot3NfpExecution &execution,const double &unit,
                                   Bot3PendingRestoreSettings &restore,
                                   Bot3EntryLoopSettings &loop,
                                   Bot3LevelCacheSettings &levels)
{
   Bot3SetupStrategy(index,adjustments,inputs,context_inputs,
                     profile_state,context_state,preparation);
   Bot3ProjectPreparationToEvaluation(inputs,preparation,context_state,
                                      magic_base,deviation,execution,unit,
                                      restore,loop,levels);
}

Bot3EntryLevelDecision Bot3SetupAndEvaluate(const uint index,
                                            const Bot3ProfileAdjustments &adjustments,
                                            Bot3PreparationInputs &inputs,
                                            const Bot3StrategyContextInputs &context_inputs,
                                            Bot3ProfileRuntimeState &profile_state,
                                            Bot3StrategyContextState &context_state,
                                            Bot3PreparationState &preparation,
                                            const int magic_base,const ulong deviation,
                                            Bot3NfpExecution &execution,const double &unit,
                                            const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                                            const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                                            const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                                            Bot3NewsEvents &events,MqlDateTime &cached_calendar,
                                            const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                            Bot3NewsSelection &selection,const Bot3FridaySettings &friday,uchar &friday_closed,
                                            const Bot3SpreadSettings &spread_settings,double &spread,
                                            Bot3PendingQueue &queue,Bot3PendingRestoreSettings &restore,
                                            const int &pending_enabled,const int &maximum_pending,
                                            Bot3LevelCacheSettings &level_settings,const uint caller_index,
                                            uint &current_index,long &bar_times[],double &upper[],double &lower[],
                                            Bot3EntryLoopSettings &loop_settings,Bot3EntryLoopState &loop_state,
                                            const Bot3VolumeSettings &volume_settings,Bot3VolumeState &volume_state,
                                            const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                                            long &last_check,long &last_deal_time,const string &suffix,
                                            const double &weight_denominator,const uchar &enabled[],double &volumes[],
                                            const uchar &panel_show,const uchar &panel_tester,const double &panel_manual_lots,
                                            const uchar &day_switch_filter,const double &balance_change_percent,
                                            double &previous_balance,Bot3EvaluationPrefixSettings &prefix,
                                            Bot3EvaluationPrefixState &state,Bot3DisplayState &display)
{
   Bot3SetupAndProjectEvaluation(index,adjustments,inputs,context_inputs,profile_state,context_state,
                                 preparation,magic_base,deviation,execution,unit,restore,loop_settings,level_settings);
   return Bot3EvaluateWithDisplay(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,
      cached_calendar,nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
      spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending,level_settings,caller_index,
      current_index,bar_times,upper,lower,loop_settings,loop_state,volume_settings,volume_state,
      reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,weight_denominator,enabled,volumes,
      panel_show,panel_tester,panel_manual_lots,day_switch_filter,balance_change_percent,previous_balance,
      prefix,state,display);
}

#endif
