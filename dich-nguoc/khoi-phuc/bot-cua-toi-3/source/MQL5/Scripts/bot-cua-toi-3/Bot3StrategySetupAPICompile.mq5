#property strict
#include "../../Include/bot-cua-toi-3/Bot3StrategySetup.mqh"
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
   Bot3SetupStrategy((uint)0,adjustments,inputs,context_inputs,profile_state,context_state,state);
   return 0;
}
