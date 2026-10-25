// Compile-only check of default MT5 bindings. Never executed by the checker.
#property strict
#include "../../Include/bot-cua-toi-3/Bot3VirtualStops.mqh"
input bool RunApiCalls=false;
int OnStart()
{
   if(!RunApiCalls) return 0;
   Bot3VirtualStopState state;ZeroMemory(state);state.guard=1;
   long tickets[];
   string symbol="XAUUSD_NOCOST_V2";
   double unit=0.01;int delay=99;
   Bot3VirtualStopLevel(state,tickets,symbol,unit,1,100.0,10.0,7);
   Bot3VirtualTakeLevel(state,tickets,101.0,7);
   Bot3VirtualStopDelayPassed(state,delay,7);
   Bot3VirtualStopStamp(state,7);
   Bot3DropClosedVirtualStops(state,tickets);
   return 0;
}
