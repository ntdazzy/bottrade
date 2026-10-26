// Compile-only check for the numeric preparation adapter. Do not run with live trading.
#property strict
#include "../../Include/bot-cua-toi-1/Bot1PreparationNumeric.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot1PreparationNumericApiCompile: compile only");return; }
   Bot1DistanceInputs inputs;ZeroMemory(inputs);
   Bot1PreparationMarket market;ZeroMemory(market);
   Bot1PreparationNumericState state;ZeroMemory(state);
   Bot1PrepareNumeric((uint)0,inputs,market,state);
}
