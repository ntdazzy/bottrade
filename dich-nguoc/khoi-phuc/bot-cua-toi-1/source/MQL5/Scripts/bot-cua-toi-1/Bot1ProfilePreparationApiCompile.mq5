#property strict
#include "../../Include/bot-cua-toi-1/Bot1RuntimeProfile.mqh"
input bool InvokeFunctions=false;
int OnStart()
{
   if(!InvokeFunctions) return 0;
   Bot1PreparationInputs inputs;ZeroMemory(inputs);
   Bot1PreparationState state;ZeroMemory(state);
   Bot1ProfileAdjustments adjustments;ZeroMemory(adjustments);
   Bot1ProfileRuntimeState profile_state;ZeroMemory(profile_state);
   profile_state.random_seed=1;
   Bot1LoadRuntimeProfile((uint)0,false,adjustments,inputs,profile_state);
   Bot1PrepareStrategy((uint)0,inputs,state);
   return 0;
}
