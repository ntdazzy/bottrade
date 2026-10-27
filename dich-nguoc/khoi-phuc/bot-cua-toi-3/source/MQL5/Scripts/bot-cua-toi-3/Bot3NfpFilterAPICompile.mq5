#property strict
#include "../../Include/bot-cua-toi-3/Bot3NfpFilter.mqh"
void OnStart()
{
   Bot3NfpFilterSettings settings;Bot3NfpFilterState state;Bot3NewsEvents events;
   MqlDateTime calendar;Bot3NfpExecution execution;long history[300];
   ZeroMemory(settings);ZeroMemory(state);ZeroMemory(events);ZeroMemory(calendar);ZeroMemory(execution);
   ArrayInitialize(history,0);
   Bot3ProcessNfpFilter(settings,state,events,calendar,history,execution);
}
