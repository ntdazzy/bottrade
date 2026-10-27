#property strict
#property script_show_inputs
input bool InvokeFunctions=false;
#include "../../Include/bot-cua-toi-1/Bot1EvaluationStops.mqh"
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot1EvaluationStopsAPICompile: compile only");return; }
   Bot1EvaluationStopInputs inputs;ZeroMemory(inputs);inputs.enabled=1;inputs.magic=0;inputs.stop_distance=1.0;inputs.target_distance=1.0;inputs.unit=0.01;
   Bot1PendingRequestState trade;ZeroMemory(trade);Bot1TradeSendOptions options;ZeroMemory(options);
   Bot1FillEvaluationStops(_Symbol,inputs,trade,options);
}
