// Compile-only check of the default MT5 API bindings. Not executed.
#property strict
#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"
input bool RunApiCalls=false;
int OnStart()
{
   if(!RunApiCalls) return 0;
   Bot1VirtualStopState state;ZeroMemory(state);state.guard=1;
   long tickets[];
   string symbol="XAUUSD_NOCOST_V2";
   double unit=0.01;int delay=99;
   Bot1VirtualStopLevel(state,tickets,symbol,unit,1,100.0,10.0,7);
   Bot1VirtualStopDelayPassed(state,delay,7);
   Bot1VirtualStopStamp(state,7);
   Bot1DropClosedVirtualStops(state,tickets);
   return 0;
}
