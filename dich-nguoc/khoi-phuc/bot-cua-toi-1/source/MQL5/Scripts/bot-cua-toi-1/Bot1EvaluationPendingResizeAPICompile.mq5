#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1EvaluationPendingResize.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot1EvaluationPendingResizeAPICompile: compile only");return; }
   Bot1PendingRequestState trade;ZeroMemory(trade);
   Bot1TradeSendOptions options;ZeroMemory(options);
   double volumes[8];ArrayInitialize(volumes,0.01);
   double results[100][2];ArrayInitialize(results,0.0);
   ulong last_ticket=0;
   int magic=0;uchar expiration=0;string symbol=_Symbol;double change=0.0;
   uint index=0;
   Bot1ResizeEvaluationPending(magic,expiration,symbol,change,volumes,index,last_ticket,results,trade,options);
}
