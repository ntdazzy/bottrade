// Compile the pending submission block with real API declarations; do not run.
#property strict
#include "../../Include/bot-cua-toi-3/Bot3PendingSubmission.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot3PendingSubmissionApiCompile: compile only");return; }
   Bot3PendingSubmissionSettings settings;ZeroMemory(settings);
   double volumes[9];ArrayInitialize(volumes,0.0);
   uint strategy_index=0,error_count=0;
   double results[][2];
   if(ArrayResize(results,100)!=100) return;
   ArrayInitialize(results,0.0);
   Bot3PendingRequestState trade;ZeroMemory(trade);
   Bot3TradeSendOptions options;ZeroMemory(options);
   Bot3SubmitPendingAfterPrice(true,0.0,settings,volumes,strategy_index,results,error_count,trade,options);
}
