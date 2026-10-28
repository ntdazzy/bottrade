#ifndef BOT3_NEWS_INITIALIZATION_MQH
#define BOT3_NEWS_INITIALIZATION_MQH
#include "Bot3NfpCalendar.mqh"
#include "Bot3ReleaseCalendars.mqh"
#include "Bot3NewsSelector.mqh"

#ifndef BOT3_INITIALIZATION_TIME_TEXT_MQH
#define BOT3_INITIALIZATION_TIME_TEXT_MQH
string Bot3InitializationTimeText(const datetime value) { return (string)value; }
#endif

void Bot3InitializeNews(const Bot3NewsWindows &windows,Bot3NewsEvents &events,
                            Bot3NewsSelection &selection,long &nfp_last_query)
{
   nfp_last_query=0;
   if(windows.nfp_enabled!=0)
   {
      events.nfp=Bot3FindNfpTime();
      Print("Next NFP: "+Bot3InitializationTimeText((datetime)events.nfp));
   }
   if(windows.interest_enabled!=0)
   {
      events.interest=Bot3FindInterestRateTime();
      Print("Next Interest Rate decision: "+Bot3InitializationTimeText((datetime)events.interest));
   }
   if(windows.cpi_enabled!=0)
   {
      events.cpi=Bot3FindCpiTime();
      Print("Next CPI: "+Bot3InitializationTimeText((datetime)events.cpi));
   }
   Bot3UpdateNewsSelection(events,windows,selection);
}
#endif
