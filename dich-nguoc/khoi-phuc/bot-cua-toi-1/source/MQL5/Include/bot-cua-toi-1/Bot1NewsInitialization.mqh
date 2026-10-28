#ifndef BOT1_NEWS_INITIALIZATION_MQH
#define BOT1_NEWS_INITIALIZATION_MQH
#include "Bot1NfpCalendar.mqh"
#include "Bot1ReleaseCalendars.mqh"
#include "Bot1NewsSelector.mqh"

#ifndef BOT1_INITIALIZATION_TIME_TEXT_MQH
#define BOT1_INITIALIZATION_TIME_TEXT_MQH
string Bot1InitializationTimeText(const datetime value) { return (string)value; }
#endif

void Bot1InitializeNews(const Bot1NewsWindows &windows,Bot1NewsEvents &events,
                            Bot1NewsSelection &selection,long &nfp_last_query)
{
   nfp_last_query=0;
   if(windows.nfp_enabled!=0)
   {
      events.nfp=Bot1FindNfpTime();
      Print("Next NFP: "+Bot1InitializationTimeText((datetime)events.nfp));
   }
   if(windows.interest_enabled!=0)
   {
      events.interest=Bot1FindInterestRateTime();
      Print("Next Interest Rate decision: "+Bot1InitializationTimeText((datetime)events.interest));
   }
   if(windows.cpi_enabled!=0)
   {
      events.cpi=Bot1FindCpiTime();
      Print("Next CPI: "+Bot1InitializationTimeText((datetime)events.cpi));
   }
   Bot1UpdateNewsSelection(events,windows,selection);
}
#endif
