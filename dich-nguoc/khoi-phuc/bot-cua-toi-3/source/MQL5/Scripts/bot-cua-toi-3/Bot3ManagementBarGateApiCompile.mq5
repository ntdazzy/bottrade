// Compile-only check of the coordinator slice; do not run this script.
#property strict
#include "../../Include/bot-cua-toi-3/Bot3ManagementBarGate.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot3ManagementBarGateApiCompile: compile only");return; }
   Bot3PositionManagementSettings settings;ZeroMemory(settings);
   Bot3PositionManagementState shared;ZeroMemory(shared);
   Bot3PendingRequestState requests;ZeroMemory(requests);
   Bot3TradeSendOptions options;ZeroMemory(options);
   long times[9];ArrayInitialize(times,0);
   double buy_levels[9],sell_levels[9];ArrayInitialize(buy_levels,0.0);ArrayInitialize(sell_levels,0.0);
   string symbol="CHECK";int timeframe=15;ulong deviation=1;
   Bot3ManageOnBarChange(symbol,timeframe,(uint)0,times,settings,shared,buy_levels,sell_levels,requests,options,deviation);
}
