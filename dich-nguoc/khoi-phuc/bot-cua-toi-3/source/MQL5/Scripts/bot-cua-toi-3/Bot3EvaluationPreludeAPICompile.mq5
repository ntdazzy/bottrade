#property strict
#property script_show_inputs
input bool InvokeFunctions=false;
#include "../../Include/bot-cua-toi-3/Bot3EvaluationPrelude.mqh"

void OnStart()
{
   if(!InvokeFunctions)
   {
      Print("Bot3EvaluationPreludeAPICompile: compile only");
      return;
   }
   Bot3EvaluationHeadInputs inputs;
   inputs.symbol=_Symbol;
   inputs.native_1d6e28=_Symbol;
   inputs.native_1d6d08=1;
   Bot3EvaluationPreludeState state;
   Bot3PrepareEvaluation(0,0,inputs,state);
}
