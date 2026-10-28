#property strict
#include "../../Include/bot-cua-toi-3/Bot3DailyLossGuard.mqh"
void OnStart()
{
   Bot3DailyLossState state;Bot3NfpExecution execution;
   ZeroMemory(state);ZeroMemory(execution);
   double percent=0.0;
   Print(Bot3ProcessDailyLoss(percent,state,execution));
}
