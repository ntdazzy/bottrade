// Three dispatcher stages before evaluating one valid strategy (0..7).
#ifndef BOT1_STRATEGY_SETUP_MQH
#define BOT1_STRATEGY_SETUP_MQH
#include "Bot1RuntimeProfile.mqh"
#include "Bot1StrategyContext.mqh"
void Bot1SetupStrategy(const uint index,const bool use_hl,const Bot1ProfileAdjustments &adjustments,
                       Bot1PreparationInputs &inputs,const Bot1StrategyContextInputs &context_inputs,
                       Bot1ProfileRuntimeState &profile_state,Bot1StrategyContextState &context_state,
                       Bot1PreparationState &preparation_state)
{
   Bot1LoadRuntimeProfile(index,use_hl,adjustments,inputs,profile_state);
   Bot1LoadStrategyContext(index,context_inputs,context_state);
   Bot1PrepareStrategy(index,inputs,preparation_state);
}
#endif
