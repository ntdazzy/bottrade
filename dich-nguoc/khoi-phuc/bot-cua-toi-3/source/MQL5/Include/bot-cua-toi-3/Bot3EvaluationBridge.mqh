#ifndef BOT3_EVALUATION_BRIDGE_MQH
#define BOT3_EVALUATION_BRIDGE_MQH

#include "Bot3StrategySetup.mqh"
#include "Bot3EntryLoop.mqh"
#include "Bot3EntryLevelCache.mqh"

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

#endif
