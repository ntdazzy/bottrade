// Compile the complete preparation helper with real API declarations; do not run.
#property strict
#include "../../Include/bot-cua-toi-3/Bot3Preparation.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot3PreparationApiCompile: compile only");return; }
   Bot3PreparationInputs settings;ZeroMemory(settings);
   Bot3PreparationState state;ZeroMemory(state);
   Bot3PrepareStrategy((uint)0,settings,state);
}
