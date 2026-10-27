#property strict
#include "../../Include/bot-cua-toi-3/Bot3EvaluationHead.mqh"

input bool InvokeFunctions=false;

int OnStart()
{
   if(!InvokeFunctions) return 0;
   Bot3EvaluationHeadInputs inputs; ZeroMemory(inputs);
   Bot3EvaluationHeadState state; ZeroMemory(state);
   Bot3BeginEvaluation((uint)0,(uchar)0,inputs,state);
   return 0;
}
