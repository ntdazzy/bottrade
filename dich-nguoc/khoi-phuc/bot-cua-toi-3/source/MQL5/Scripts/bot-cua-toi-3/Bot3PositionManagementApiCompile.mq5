// Compile actual API declarations for both complete management paths. Do not run.
#property strict
#include "../../Include/bot-cua-toi-3/Bot3PositionManagement.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot3PositionManagementApiCompile: compile only");return; }
   Bot3PositionManagementSettings settings;ZeroMemory(settings);
   Bot3PositionManagementState shared;ZeroMemory(shared);
   Bot3PendingRequestState requests;ZeroMemory(requests);
   Bot3TradeSendOptions options;ZeroMemory(options);
   double levels[9];ArrayInitialize(levels,100.);ulong deviation=1;
   Bot3ManagePositions(true,settings,shared,levels,requests,options,deviation);
   Bot3ManagePositions(false,settings,shared,levels,requests,options,deviation);
}
