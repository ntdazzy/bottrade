// Compile-only check for the runtime profile API. Do not run with live trading.
#property strict
#include "../../Include/bot-cua-toi-3/Bot3RuntimeProfile.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot3RuntimeProfileApiCompile: compile only");return; }
   Bot3ProfileAdjustments adjustments;ZeroMemory(adjustments);
   Bot3PreparationInputs inputs;ZeroMemory(inputs);
   Bot3ProfileRuntimeState state;ZeroMemory(state);
   state.random_seed=1;
   Bot3LoadRuntimeProfile((uint)0,adjustments,inputs,state);
}
