#property strict
#include "../../Include/bot-cua-toi-1/Bot1InitializationGate.mqh"
void OnStart()
{
   Bot1InitializationGateState state;ZeroMemory(state);int speed=2;
   Bot1StartInitializationGate(state);
   Print(Bot1FinishInitializationGate(false,speed,state),state.active,state.dispatch_mode,state.m1_enabled);
}
