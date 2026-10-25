// Compile-only check against actual MT5 API declarations; do not run this script.
#property strict
#include "../../Include/bot-cua-toi-1/Bot1PositionManagement.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot1PositionManagementApiCompile: compile only");return; }
   Bot1PositionManagementSettings settings;ZeroMemory(settings);
   Bot1PositionManagementState shared;ZeroMemory(shared);
   Bot1PendingRequestState requests;ZeroMemory(requests);
   Bot1TradeSendOptions options;ZeroMemory(options);
   double levels[8];ArrayInitialize(levels,0.0);ulong deviation=1;
   Bot1ManagePositions(true,settings,shared,levels,requests,options,deviation);
   Bot1ManagePositions(false,settings,shared,levels,requests,options,deviation);
}
