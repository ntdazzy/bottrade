#property strict
#include "../../Include/bot-cua-toi-1/Bot1NfpFilter.mqh"
void OnStart()
{
   Bot1NfpFilterSettings settings;Bot1NfpFilterState state;Bot1NewsEvents events;
   MqlDateTime calendar;Bot1NfpExecution execution;long history[300];
   ZeroMemory(settings);ZeroMemory(state);ZeroMemory(events);ZeroMemory(calendar);ZeroMemory(execution);
   ArrayInitialize(history,0);
   Bot1ProcessNfpFilter(settings,state,events,calendar,history,execution);
}
