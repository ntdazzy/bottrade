#property strict
#include "../../Include/bot-cua-toi-3/Bot3InitializationGate.mqh"
void OnStart()
{
   Bot3InitializationGateState state;ZeroMemory(state);
   Print(Bot3InitializeGate(true,1,2,state),state.active,state.dispatch_mode,state.m1_enabled);
}
