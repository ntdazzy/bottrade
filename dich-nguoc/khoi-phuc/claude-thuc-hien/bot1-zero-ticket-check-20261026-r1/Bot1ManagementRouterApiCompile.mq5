// Compile-only check against actual MT5 API declarations; do not run this script.
#property strict
#include "../../Include/bot-cua-toi-1/Bot1ManagementRouter.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot1ManagementRouterApiCompile: compile only");return; }
   Bot1PositionManagementSettings settings;ZeroMemory(settings);
   Bot1PositionManagementState shared;ZeroMemory(shared);
   Bot1PendingRequestState requests;ZeroMemory(requests);
   Bot1TradeSendOptions options;ZeroMemory(options);
   double buy_levels[8],sell_levels[8];ArrayInitialize(buy_levels,0.0);ArrayInitialize(sell_levels,0.0);
   long last_times[8];ArrayInitialize(last_times,0);
   uchar license_valid=0,tick_management=0,bar_override=0;int timeframe=0;ulong deviation=1;
   Bot1RoutePositionManagement(license_valid,tick_management,bar_override,timeframe,0,last_times,settings,
                               shared,buy_levels,sell_levels,requests,options,deviation,false);
}
