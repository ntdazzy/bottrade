#property strict
#include "../../Include/bot-cua-toi-1/Bot1RuntimeProfile.mqh"
#include "../../Include/bot-cua-toi-1/Bot1StrategyContext.mqh"
input bool InvokeFunctions=false;
int OnStart()
{
   if(!InvokeFunctions) return 0;
   Bot1PreparationInputs inputs;ZeroMemory(inputs);
   Bot1PreparationState state;ZeroMemory(state);
   Bot1StrategyContextInputs context_inputs;ZeroMemory(context_inputs);
   Bot1StrategyContextState context_state;ZeroMemory(context_state);
   Bot1ProfileAdjustments adjustments;ZeroMemory(adjustments);
   Bot1ProfileRuntimeState profile_state;ZeroMemory(profile_state);
   profile_state.random_seed=1;
   Bot1LoadRuntimeProfile((uint)0,false,adjustments,inputs,profile_state);
   Bot1LoadStrategyContext((uint)0,context_inputs,context_state);
   Bot1PrepareStrategy((uint)0,inputs,state);
   return 0;
}

