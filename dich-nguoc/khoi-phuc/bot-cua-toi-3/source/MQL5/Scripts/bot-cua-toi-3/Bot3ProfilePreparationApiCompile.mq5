#property strict
#include "../../Include/bot-cua-toi-3/Bot3RuntimeProfile.mqh"
input bool InvokeFunctions=false;
int OnStart()
{
   if(!InvokeFunctions) return 0;
   Bot3ProfileAdjustments adjustments;
   ZeroMemory(adjustments);
   Bot3PreparationInputs inputs;
   ZeroMemory(inputs);
   Bot3ProfileRuntimeState profile_state;
   ZeroMemory(profile_state);
   Bot3PreparationState preparation_state;
   ZeroMemory(preparation_state);
   Bot3LoadRuntimeProfile((uint)0, adjustments, inputs, profile_state);
   Bot3PrepareStrategy((uint)0, inputs, preparation_state);
   return 0;
}
