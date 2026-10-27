#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3EvaluationPendingResize.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot3EvaluationPendingResizeAPICompile: compile only");return; }
   Bot3PendingRequestState trade;ZeroMemory(trade);
   Bot3TradeSendOptions options;ZeroMemory(options);
   double volumes[9];ArrayInitialize(volumes,0.01);
   double results[100][2];ArrayInitialize(results,0.0);
   ulong last_ticket=0;
   int magic=0;uchar expiration=0;string symbol=_Symbol;double change=0.0;
   uint index=0;
   Bot3ResizeEvaluationPending(magic,expiration,symbol,change,volumes,index,last_ticket,results,trade,options);
}
