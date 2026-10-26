#property strict
#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"
input bool InvokeFunctions=false;
int OnStart()
{
   if(!InvokeFunctions) return 0;
   Bot1PreparationInputs inputs;ZeroMemory(inputs);
   Bot1PreparationState state;ZeroMemory(state);
   Bot1PrepareStrategy((uint)0,inputs,state);
   return 0;
}
