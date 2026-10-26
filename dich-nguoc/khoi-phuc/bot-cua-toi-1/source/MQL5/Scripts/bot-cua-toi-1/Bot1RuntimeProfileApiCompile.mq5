// Compile-only check for the bot1 runtime profile API. Do not run with live trading.
#property strict
#include "../../Include/bot-cua-toi-1/Bot1RuntimeProfile.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot1RuntimeProfileApiCompile: compile only");return; }
   Bot1ProfileAdjustments adjustments;ZeroMemory(adjustments);
   Bot1DistanceInputs inputs;ZeroMemory(inputs);
   Bot1ProfileRuntimeState state;ZeroMemory(state);state.random_seed=1;
   Bot1LoadRuntimeProfile((uint)0,false,adjustments,inputs,state);
}
