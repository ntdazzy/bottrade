// Three dispatcher stages before evaluating one valid internal strategy (0..8).
#ifndef BOT3_STRATEGY_SETUP_MQH
#define BOT3_STRATEGY_SETUP_MQH
#include "Bot3RuntimeProfile.mqh"
#include "Bot3StrategyContext.mqh"
void Bot3SetupStrategy(const uint index,const Bot3ProfileAdjustments &adjustments,
                       Bot3PreparationInputs &inputs,const Bot3StrategyContextInputs &context_inputs,
                       Bot3ProfileRuntimeState &profile_state,Bot3StrategyContextState &context_state,
                       Bot3PreparationState &preparation_state)
{
   // Both input fields represent the same native byte at 0x1d6f28.
   inputs.variable_distances=context_inputs.native_1d6f28;
   Bot3LoadRuntimeProfile(index,adjustments,inputs,profile_state);
   Bot3LoadStrategyContext(index,context_inputs,inputs.reference,context_state);
   Bot3PrepareStrategy(index,inputs,preparation_state);
}
#endif
