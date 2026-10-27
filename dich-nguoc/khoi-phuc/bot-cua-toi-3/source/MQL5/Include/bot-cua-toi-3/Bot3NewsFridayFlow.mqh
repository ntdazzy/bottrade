#ifndef BOT3_NEWS_FRIDAY_FLOW_MQH
#define BOT3_NEWS_FRIDAY_FLOW_MQH
#include "Bot3NewsFilterPipeline.mqh"
#include "Bot3FridayClose.mqh"

bool Bot3ProcessNewsAndFriday(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                              const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                              const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                              Bot3NewsEvents &events,const MqlDateTime &cached_calendar,
                              const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                              Bot3NfpExecution &execution,Bot3NewsSelection &selection,
                              const Bot3FridaySettings &friday,uchar &friday_closed)
{
   if(Bot3ProcessNewsFilters(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                             nfp_history,interest_history,cpi_history,execution,selection)) return true;
   return Bot3ProcessFridayClose(friday,cached_calendar,friday_closed,execution);
}

#endif
