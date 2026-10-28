#property strict
#include "../../Include/bot-cua-toi-1/Bot1DailyLossGuard.mqh"
void OnStart()
{
   Bot1DailyLossState state;Bot1NfpExecution execution;
   ZeroMemory(state);ZeroMemory(execution);
   double percent=0.0;
   Print(Bot1ProcessDailyLoss(percent,state,execution));
}
