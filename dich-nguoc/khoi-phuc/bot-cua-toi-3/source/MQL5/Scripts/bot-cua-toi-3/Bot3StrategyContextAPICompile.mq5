#property strict
#include "../../Include/bot-cua-toi-3/Bot3RuntimeProfile.mqh"
#include "../../Include/bot-cua-toi-3/Bot3StrategyContext.mqh"
input bool InvokeFunctions=false;
int OnStart()
{
   if(!InvokeFunctions) return 0;
   Bot3PreparationInputs inputs;ZeroMemory(inputs);
   Bot3PreparationState state;ZeroMemory(state);
   Bot3StrategyContextInputs context_inputs;ZeroMemory(context_inputs);
   Bot3StrategyContextState context_state;ZeroMemory(context_state);
   Bot3ProfileAdjustments adjustments;ZeroMemory(adjustments);
   Bot3ProfileRuntimeState profile_state;ZeroMemory(profile_state);
   profile_state.random_seed=1;
   Bot3LoadRuntimeProfile((uint)0,adjustments,inputs,profile_state);
   Bot3LoadStrategyContext((uint)0,context_inputs,inputs.reference,context_state);
   Bot3PrepareStrategy((uint)0,inputs,state);
   return 0;
}

