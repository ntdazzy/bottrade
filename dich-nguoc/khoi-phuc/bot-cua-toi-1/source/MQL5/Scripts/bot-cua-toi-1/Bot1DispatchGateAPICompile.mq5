#property strict
#include "../../Include/bot-cua-toi-1/Bot1DispatchGate.mqh"
void OnStart()
{
   uchar mode=0,m1=0;string symbol=_Symbol;Bot1DispatchGateState state;ZeroMemory(state);
   Print(Bot1DispatchGate(mode,m1,symbol,state));
}
