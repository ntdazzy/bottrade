#ifndef BOT3_EVALUATION_BRIDGE_MQH
#define BOT3_EVALUATION_BRIDGE_MQH

#include "Bot3StrategySetup.mqh"
#include "Bot3EntryLoop.mqh"
#include "Bot3EntryLevelCache.mqh"
#include "Bot3EvaluationWithDisplay.mqh"

void Bot3ProjectPreparationToEvaluation(const Bot3PreparationInputs &inputs,
                                        const Bot3PreparationState &preparation,
                                        const Bot3StrategyContextState &context,
                                        const int magic_base,
                                        Bot3NfpExecution &execution,
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

   restore.sl_distance=preparation.stop_distance;
   restore.tp_distance=preparation.target_distance;
   restore.expiration_base=(datetime)preparation.expiration;
   restore.comment=context.order_comment;
   restore.virtual_expiration=inputs.virtual_expiration;

   loop.submission.check_free_margin=preparation.native_6d51c;
   loop.submission.omit_real_sl_tp=preparation.native_6d510;
   loop.delete_expired=preparation.virtual_expiration;
   loop.confirmation_frame=(ENUM_TIMEFRAMES)inputs.entry.confirmation_frame;
   loop.older_width=preparation.older_width;
   loop.recent_width=preparation.recent_width;
   loop.last_shift=preparation.last_shift;
   loop.expiration_setting=preparation.expiration_hours;
   loop.expiration_seconds=preparation.expiration_seconds;
   loop.gap_points=preparation.gap_points;
   loop.buy_offset=preparation.buy_offset;
   loop.sell_offset=preparation.sell_offset;
   loop.radius=preparation.nearby_radius;
   loop.step_reference=preparation.native_6d600;

   levels.timeframe=(ENUM_TIMEFRAMES)preparation.entry_frame;
   levels.aux_timeframe=(ENUM_TIMEFRAMES)preparation.aux_frame;
   levels.aux_older=preparation.aux_older;
   levels.aux_recent=preparation.aux_recent;
   levels.last_shift=preparation.aux_scan;
   levels.aux_offset=preparation.aux_offset;
}

void Bot3ProjectEvaluationControls(const Bot3ProfileRuntimeState &profile,
                                    const Bot3StrategyContextState &context,
                                    const Bot3PreparationState &p,Bot3SpreadSettings &spread,
                                    Bot3VolumeSettings &volume,Bot3VolumeState &volume_state,
                                    Bot3EvaluationPrefixSettings &prefix)
{
   spread.enabled=p.feature_flag;
   spread.maximum=p.max_spread;
   spread.distance_points=p.freeze_buffer;
   volume.start_lots=p.native_6d620;
   volume.max_lots=p.native_6d628;
   volume.lot_scale=p.lot_scale;
   volume.manual_risk=p.native_6d638;
   volume_state.mode=(uint)p.native_6d630;
   volume_state.balance_step=p.native_6d640;
   volume_state.strategy_loss=context.converted_value;
   prefix.management_timeframe=p.management_timeframe;
   prefix.management.anchor_limit=p.native_6d4e0;
   prefix.management.use_anchor=p.native_6d508;
   prefix.management.timed_activation=p.native_6d5e8;
   prefix.management.timed_distance=p.native_6d5f0;
   prefix.management.virtual_delay_seconds=p.native_6d518;
   prefix.management.trail=p.trail_distance;
   prefix.management.trail_step=p.trail_step;
   prefix.management.trail_start=p.trail_start;
   prefix.management.trail_limit=p.trail_limit;
   prefix.management.take_trail_distance=p.native_6d378;
   prefix.management.take_trail_start=p.native_6d380;
   prefix.management.slippage_enabled=p.native_6d4e8;
   prefix.management.slippage_trail=p.native_6d4f8;
   prefix.management.slippage_start=p.native_6d4f0;
   prefix.management.slippage_limit=p.native_6d500;
   prefix.management.high_low_gap_count=profile.native_6d3c0;
   prefix.management.finish.high_low_enabled=p.aux_older;
   prefix.management.finish.high_low_before_open=p.native_6d5c8;
   prefix.management.finish.high_low_shift=p.native_6d5dc;
   prefix.management.finish.high_low_buy_shift=10.0;
   prefix.management.finish.high_low_sell_shift=10.0;
   prefix.management.finish.lock_start=p.trigger_distance;
   prefix.management.finish.lock_extra=p.locked_distance;
   prefix.management.finish.mode=p.mode;
   prefix.management.finish.step_enabled=p.native_6d5f8;
   prefix.management.finish.step_reference=p.native_6d600;
   prefix.management.finish.min_steps=p.native_6d608;
   prefix.management.finish.step_distance=p.min_change;
}

void Bot3SetupAndProjectEvaluation(const uint index,
                                   const Bot3ProfileAdjustments &adjustments,
                                   Bot3PreparationInputs &inputs,
                                   const Bot3StrategyContextInputs &context_inputs,
                                   Bot3ProfileRuntimeState &profile_state,
                                   Bot3StrategyContextState &context_state,
                                   Bot3PreparationState &preparation,
                                   Bot3NfpExecution &execution,
                                   Bot3PendingRestoreSettings &restore,
                                   Bot3EntryLoopSettings &loop,
                                   Bot3LevelCacheSettings &levels)
{
   Bot3SetupStrategy(index,adjustments,inputs,context_inputs,
                     profile_state,context_state,preparation);
   Bot3ProjectPreparationToEvaluation(inputs,preparation,context_state,
                                      context_inputs.base_magic,execution,
                                      restore,loop,levels);
}

Bot3EntryLevelDecision Bot3SetupAndEvaluate(const uint index,
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
                                            Bot3EvaluationPrefixState &state,Bot3DisplayState &display)
{
   Bot3SetupAndProjectEvaluation(index,adjustments,inputs,context_inputs,profile_state,context_state,
                                 preparation,execution,restore,loop_settings,level_settings);
   Bot3ProjectEvaluationControls(profile_state,context_state,preparation,spread_settings,
                                 volume_settings,volume_state,prefix);
   cached_calendar=preparation.calendar;
   spread=preparation.spread;
   current_index=preparation.strategy_index;
   const Bot3EntryLevelDecision result=Bot3EvaluateWithDisplay(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,
      cached_calendar,nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
      spread_settings,preparation.unit,spread,queue,restore,preparation.native_6d520,preparation.native_6d550,level_settings,index,
      current_index,bar_times,upper,lower,loop_settings,loop_state,volume_settings,volume_state,
      reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,weight_denominator,enabled,volumes,
      panel_show,panel_tester,panel_manual_lots,day_switch_filter,balance_change_percent,previous_balance,
      prefix,state,display);
   preparation.tick=execution.tick;
   preparation.stop_min_price=execution.threshold_a;
   preparation.freeze_min_price=execution.gap;
   preparation.stop_distance=restore.sl_distance;
   preparation.target_distance=restore.tp_distance;
   preparation.calendar=cached_calendar;
   preparation.spread=spread;
   preparation.strategy_index=current_index;
   preparation.expiration=(long)restore.expiration_base;
   preparation.native_6d630=(int)volume_state.mode;
   preparation.native_6d640=volume_state.balance_step;
   inputs.symbol=execution.symbol;
   inputs.virtual_expiration=restore.virtual_expiration;
   context_state.magic=execution.strategy_magic;
   context_state.order_comment=restore.comment;
   context_state.converted_value=volume_state.strategy_loss;
   return result;
}

#endif
