// Compile the pending submission block with real API declarations; do not run.
#property strict
#include "../../Include/bot-cua-toi-1/Bot1PendingSubmission.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot1PendingSubmissionApiCompile: compile only");return; }
   Bot1PendingSubmissionSettings settings;ZeroMemory(settings);
   double volumes[8];ArrayInitialize(volumes,0.0);
   uint strategy_index=0,error_count=0;
   double results[][2];
   if(ArrayResize(results,100)!=100) return;
   ArrayInitialize(results,0.0);
   Bot1PendingRequestState trade;ZeroMemory(trade);
   Bot1TradeSendOptions options;ZeroMemory(options);
   Bot1SubmitPendingAfterPrice(true,0.0,settings,volumes,strategy_index,results,error_count,trade,options);
}
