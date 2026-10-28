#ifndef BOT1_EVALUATION_BRIDGE_MQH
#define BOT1_EVALUATION_BRIDGE_MQH

#include "Bot1StrategySetup.mqh"
#include "Bot1EntryLoop.mqh"
#include "Bot1EntryLevelCache.mqh"

// Copy the fields that the native caller passes from preparation/context into
// the shared evaluator objects. The objects are supplied by the caller and
// remain alive across strategy iterations.
void Bot1ProjectPreparationToEvaluation(const Bot1PreparationInputs &inputs,
                                        const Bot1PreparationState &preparation,
                                        const Bot1StrategyContextState &context,
                                        const int magic_base,const ulong deviation,
                                        Bot1NfpExecution &execution,const double &unit,
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
   execution.deviation=deviation;

   restore.sl_distance=preparation.stop_distance;
   restore.tp_distance=preparation.target_distance;
   restore.expiration_base=(datetime)preparation.expiration;
   restore.comment=context.order_comment;
   restore.virtual_expiration=preparation.virtual_expiration;

   loop.submission.check_free_margin=preparation.check_free_margin;
   loop.submission.omit_real_sl_tp=preparation.omit_real_sl_tp;
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

void Bot1SetupAndProjectEvaluation(const uint index,const bool use_hl,
                                   const Bot1ProfileAdjustments &adjustments,
                                   Bot1PreparationInputs &inputs,
                                   const Bot1StrategyContextInputs &context_inputs,
                                   Bot1ProfileRuntimeState &profile_state,
                                   Bot1StrategyContextState &context_state,
                                   Bot1PreparationState &preparation,
                                   const int magic_base,const ulong deviation,
                                   Bot1NfpExecution &execution,const double &unit,
                                   Bot1PendingRestoreSettings &restore,
                                   Bot1EntryLoopSettings &loop,
                                   Bot1LevelCacheSettings &levels)
{
   Bot1SetupStrategy(index,use_hl,adjustments,inputs,context_inputs,
                     profile_state,context_state,preparation);
   Bot1ProjectPreparationToEvaluation(inputs,preparation,context_state,
                                      magic_base,deviation,execution,unit,
                                      restore,loop,levels);
}

#endif
