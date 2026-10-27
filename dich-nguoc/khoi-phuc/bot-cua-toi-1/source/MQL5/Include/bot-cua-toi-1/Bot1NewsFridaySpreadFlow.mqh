#ifndef BOT1_NEWS_FRIDAY_SPREAD_FLOW_MQH
#define BOT1_NEWS_FRIDAY_SPREAD_FLOW_MQH
#include "Bot1NewsFridayFlow.mqh"
#include "Bot1HighSpread.mqh"

bool Bot1ProcessNewsFridayAndHighSpread(const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                                        const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                                        const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                                        Bot1NewsEvents &events,const MqlDateTime &cached_calendar,
                                        const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                        Bot1NfpExecution &execution,Bot1NewsSelection &selection,
                                        const Bot1FridaySettings &friday,uchar &friday_closed,
                                        const Bot1SpreadSettings &spread_settings,const double &unit,double &spread,
                                        Bot1PendingQueue &queue)
{
   if(Bot1ProcessNewsAndFriday(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                               nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed)) return true;
   return Bot1ProcessHighSpread(spread_settings,unit,spread,execution,queue);
}

#endif
