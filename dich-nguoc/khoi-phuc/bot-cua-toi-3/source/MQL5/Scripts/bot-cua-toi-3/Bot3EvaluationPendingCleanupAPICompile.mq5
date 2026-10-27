#property strict
#property script_show_inputs

input bool InvokeFunctions=false;
#include "../../Include/bot-cua-toi-3/Bot3EvaluationPendingCleanup.mqh"

void OnStart()
{
   if(!InvokeFunctions) return;
   Bot3PendingRequestState trade;
   Bot3TradeSendOptions options;
   ZeroMemory(trade);
   ZeroMemory(options);
   double results[][2];
   ArrayResize(results,100);
   Bot3CleanEvaluationPending((uchar)0,0,_Symbol,results,trade,options);
}
