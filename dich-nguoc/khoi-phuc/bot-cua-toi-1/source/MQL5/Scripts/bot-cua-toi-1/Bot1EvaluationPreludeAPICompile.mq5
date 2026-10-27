#property strict
#property script_show_inputs
input bool InvokeFunctions=false;
#include "../../Include/bot-cua-toi-1/Bot1EvaluationPrelude.mqh"
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot1EvaluationPreludeAPICompile: compile only");return; }
   Bot1EvaluationPreludeInputs inputs;inputs.symbol=_Symbol;inputs.native_6a428=_Symbol;inputs.native_6a3b4=1;
   Bot1EvaluationPreludeState state;ZeroMemory(state);Bot1PrepareEvaluation(0,inputs,state);
}
