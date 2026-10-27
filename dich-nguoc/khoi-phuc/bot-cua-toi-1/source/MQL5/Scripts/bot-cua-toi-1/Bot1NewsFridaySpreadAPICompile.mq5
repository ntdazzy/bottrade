#property strict
#include "../../Include/bot-cua-toi-1/Bot1NewsFridaySpreadFlow.mqh"
void OnStart()
{
   Bot1NfpFilterSettings nfp_settings;Bot1NfpFilterState nfp;
   Bot1ReleaseFilterSettings interest_settings,cpi_settings;Bot1ReleaseFilterState interest,cpi;
   Bot1NewsEvents events;Bot1NewsSelection selection;Bot1NfpExecution execution;MqlDateTime cached;
   Bot1SpreadSettings spread_settings;Bot1PendingQueue queue;double unit=0,spread=0;ZeroMemory(spread_settings);ZeroMemory(queue);
   Bot1FridaySettings friday;uchar friday_closed=0;ZeroMemory(friday);
   long nfp_history[300],interest_history[300],cpi_history[300];
   ZeroMemory(nfp_settings);ZeroMemory(nfp);ZeroMemory(interest_settings);ZeroMemory(cpi_settings);
   ZeroMemory(interest);ZeroMemory(cpi);ZeroMemory(events);ZeroMemory(execution);ZeroMemory(cached);
   ArrayInitialize(nfp_history,0);ArrayInitialize(interest_history,0);ArrayInitialize(cpi_history,0);
   Bot1ProcessNewsFridayAndHighSpread(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,
                            nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,spread_settings,unit,spread,queue);
}
