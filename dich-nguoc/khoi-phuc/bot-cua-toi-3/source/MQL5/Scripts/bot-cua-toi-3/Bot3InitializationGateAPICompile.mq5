#property strict
#include "../../Include/bot-cua-toi-3/Bot3InitializationGate.mqh"
void OnStart()
{
   Bot3InitializationGateState state;ZeroMemory(state);int speed=2;
   Bot3StartInitializationGate(state);
   Print(Bot3FinishInitializationGate(false,speed,state),state.active,state.dispatch_mode,state.m1_enabled);
}
