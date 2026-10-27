#property strict
#include "../../Include/bot-cua-toi-1/Bot1StrategySetup.mqh"
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
   Bot1SetupStrategy((uint)0,false,adjustments,inputs,context_inputs,profile_state,context_state,state);
   return 0;
}
