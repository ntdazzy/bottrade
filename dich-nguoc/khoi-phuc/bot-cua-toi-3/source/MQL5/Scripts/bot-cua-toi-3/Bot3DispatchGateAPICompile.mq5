#property strict
#include "../../Include/bot-cua-toi-3/Bot3DispatchGate.mqh"
void OnStart()
{
   uchar mode=0,m1=0;string symbol=_Symbol;Bot3DispatchGateState state;ZeroMemory(state);
   Print(Bot3DispatchGate(mode,m1,symbol,state));
}
