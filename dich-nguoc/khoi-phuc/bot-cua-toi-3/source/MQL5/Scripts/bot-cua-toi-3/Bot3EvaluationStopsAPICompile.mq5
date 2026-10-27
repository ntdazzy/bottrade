#property strict
#property script_show_inputs
input bool InvokeFunctions=false;
#include "../../Include/bot-cua-toi-3/Bot3EvaluationStops.mqh"
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot3EvaluationStopsAPICompile: compile only");return; }
   Bot3EvaluationStopInputs inputs;ZeroMemory(inputs);inputs.enabled=1;inputs.magic=0;inputs.stop_distance=1.0;inputs.target_distance=1.0;inputs.unit=0.01;
   Bot3PendingRequestState trade;ZeroMemory(trade);Bot3TradeSendOptions options;ZeroMemory(options);
   Bot3FillEvaluationStops(_Symbol,inputs,trade,options);
}
