#property strict
#include "../../Include/bot-cua-toi-1/Bot1InitializationGate.mqh"
void OnStart()
{
   Bot1InitializationGateState state;ZeroMemory(state);
   Print(Bot1InitializeGate(true,1,2,state),state.active,state.dispatch_mode,state.m1_enabled);
}
