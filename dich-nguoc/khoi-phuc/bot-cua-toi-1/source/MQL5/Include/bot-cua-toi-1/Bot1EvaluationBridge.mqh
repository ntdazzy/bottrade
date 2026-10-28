#ifndef BOT1_EVALUATION_BRIDGE_MQH
#define BOT1_EVALUATION_BRIDGE_MQH

#include "Bot1StrategySetup.mqh"
#include "Bot1EntryLoop.mqh"
#include "Bot1EntryLevelCache.mqh"
#include "Bot1EvaluationWithDisplay.mqh"

// Copy the fields that the native caller passes from preparation/context into
// the shared evaluator objects. The objects are supplied by the caller and
// remain alive across strategy iterations.
void Bot1ProjectPreparationToEvaluation(const Bot1PreparationInputs &inputs,
                                        const Bot1PreparationState &preparation,
                                        const Bot1StrategyContextState &context,
                                        const int magic_base,
                                        Bot1NfpExecution &execution,
                                        Bot1PendingRestoreSettings &restore,
                                        Bot1EntryLoopSettings &loop,
                                        Bot1LevelCacheSettings &levels)
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

   loop.submission.check_free_margin=preparation.check_free_margin;
   loop.submission.omit_real_sl_tp=preparation.omit_real_sl_tp;
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
   loop.step_reference=preparation.native_62510;

   levels.timeframe=(ENUM_TIMEFRAMES)preparation.entry_frame;
   levels.aux_timeframe=(ENUM_TIMEFRAMES)preparation.aux_frame;
   levels.aux_older=preparation.aux_older;
   levels.aux_recent=preparation.aux_recent;
   levels.last_shift=preparation.aux_scan;
   levels.aux_offset=preparation.aux_offset;
}

// Fields backed by the same native globals as the preparation output.
// Other settings remain owned by the caller.
void Bot1ProjectEvaluationControls(const bool use_hl,const Bot1ProfileRuntimeState &profile,
                                    const Bot1StrategyContextState &context,
                                    const Bot1PreparationState &p,Bot1SpreadSettings &spread,
                                    Bot1VolumeSettings &volume,Bot1VolumeState &volume_state,
                                    Bot1EvaluationPrefixSettings &prefix)
{
   spread.enabled=p.feature_flag;
   spread.maximum=p.max_spread;
   spread.distance_points=p.freeze_buffer;
   volume.start_lots=p.native_62530;
   volume.max_lots=p.native_62538;
   volume.lot_scale=p.lot_scale;
   volume.manual_risk=p.native_62548;
   volume_state.mode=(uint)p.native_62540;
   volume_state.balance_step=p.native_62550;
   volume_state.strategy_loss=context.converted_value;
   prefix.management_timeframe=p.native_6248c;
   prefix.management.anchor_limit=p.native_623e8;
   prefix.management.use_anchor=p.native_62410;
   prefix.management.high_low_eligible=(uchar)use_hl;
   prefix.management.timed_activation=p.native_624f8;
   prefix.management.timed_distance=p.native_62500;
   prefix.management.virtual_delay_seconds=p.native_62420;
   prefix.management.trail=p.trail_distance;
   prefix.management.trail_step=p.trail_step;
   prefix.management.trail_start=p.trail_start;
   prefix.management.trail_limit=p.trail_limit;
   prefix.management.slippage_enabled=p.native_623f0;
   prefix.management.slippage_trail=p.native_62400;
   prefix.management.slippage_start=p.native_623f8;
   prefix.management.slippage_limit=p.native_62408;
   prefix.management.high_low_gap_count=profile.native_62360;
   prefix.management.finish.high_low_enabled=p.aux_older;
   prefix.management.finish.high_low_before_open=p.native_624d8;
   prefix.management.finish.high_low_shift=p.native_624ec;
   prefix.management.finish.high_low_buy_shift=10.0;
   prefix.management.finish.high_low_sell_shift=10.0;
   prefix.management.finish.lock_start=p.trigger_distance;
   prefix.management.finish.lock_extra=p.locked_distance;
   prefix.management.finish.mode=p.mode;
   prefix.management.finish.step_enabled=p.native_62508;
   prefix.management.finish.step_reference=p.native_62510;
   prefix.management.finish.min_steps=p.native_62518;
   prefix.management.finish.step_distance=p.min_change;
}

void Bot1SetupAndProjectEvaluation(const uint index,const bool use_hl,
                                   const Bot1ProfileAdjustments &adjustments,
                                   Bot1PreparationInputs &inputs,
                                   const Bot1StrategyContextInputs &context_inputs,
                                   Bot1ProfileRuntimeState &profile_state,
                                   Bot1StrategyContextState &context_state,
                                   Bot1PreparationState &preparation,
                                   Bot1NfpExecution &execution,
                                   Bot1PendingRestoreSettings &restore,
                                   Bot1EntryLoopSettings &loop,
                                   Bot1LevelCacheSettings &levels)
{
   Bot1SetupStrategy(index,use_hl,adjustments,inputs,context_inputs,
                     profile_state,context_state,preparation);
   Bot1ProjectPreparationToEvaluation(inputs,preparation,context_state,
                                      context_inputs.base_magic,execution,
                                      restore,loop,levels);
}

Bot1EntryLevelDecision Bot1SetupAndEvaluate(const uint index,const bool use_hl,
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
                                            Bot1EvaluationPrefixState &state,Bot1DisplayState &display)
{
   Bot1SetupAndProjectEvaluation(index,use_hl,adjustments,inputs,context_inputs,profile_state,
                                 context_state,preparation,execution,
                                 restore,loop_settings,level_settings);
   Bot1ProjectEvaluationControls(use_hl,profile_state,context_state,preparation,spread_settings,
                                 volume_settings,volume_state,prefix);
   cached_calendar=preparation.calendar;
   spread=preparation.spread;
   current_index=preparation.strategy_index;
   const Bot1EntryLevelDecision result=Bot1EvaluateWithDisplay(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,
      cached_calendar,nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
      spread_settings,preparation.unit,spread,queue,restore,preparation.native_62428,preparation.native_62458,level_settings,index,
      current_index,bar_times,upper,lower,loop_settings,loop_state,volume_settings,volume_state,
      reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,suffix,volumes,panel_show,panel_tester,
      panel_mode,panel_trade_risk,panel_balance_step,day_switch_filter,balance_change_percent,previous_balance,
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
   preparation.native_62540=(int)volume_state.mode;
   preparation.native_62550=volume_state.balance_step;
   inputs.symbol=execution.symbol;
   inputs.virtual_expiration=restore.virtual_expiration;
   context_state.magic=execution.strategy_magic;
   context_state.order_comment=restore.comment;
   context_state.converted_value=volume_state.strategy_loss;
   return result;
}

#endif
