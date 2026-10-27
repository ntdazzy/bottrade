#property strict
#include "../../Include/bot-cua-toi-3/Bot3NewsFilterPipeline.mqh"
void OnStart()
{
   Bot3NfpFilterSettings nfp_settings;Bot3NfpFilterState nfp;
   Bot3ReleaseFilterSettings interest_settings,cpi_settings;Bot3ReleaseFilterState interest,cpi;
   Bot3NewsEvents events;Bot3NewsSelection selection;Bot3NfpExecution execution;MqlDateTime cached;
   long nfp_history[300],interest_history[300],cpi_history[300];
   ZeroMemory(nfp_settings);ZeroMemory(nfp);ZeroMemory(interest_settings);ZeroMemory(cpi_settings);
   ZeroMemory(interest);ZeroMemory(cpi);ZeroMemory(events);ZeroMemory(execution);ZeroMemory(cached);
   ArrayInitialize(nfp_history,0);ArrayInitialize(interest_history,0);ArrayInitialize(cpi_history,0);
   Bot3ProcessNewsFilters(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,
                            nfp_history,interest_history,cpi_history,execution,selection);
}
