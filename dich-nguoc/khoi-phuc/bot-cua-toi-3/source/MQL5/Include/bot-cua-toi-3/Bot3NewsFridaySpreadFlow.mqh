#ifndef BOT3_NEWS_FRIDAY_SPREAD_FLOW_MQH
#define BOT3_NEWS_FRIDAY_SPREAD_FLOW_MQH
#include "Bot3NewsFridayFlow.mqh"
#include "Bot3HighSpread.mqh"

bool Bot3ProcessNewsFridayAndHighSpread(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                                        const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                                        const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                                        Bot3NewsEvents &events,const MqlDateTime &cached_calendar,
                                        const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                        Bot3NfpExecution &execution,Bot3NewsSelection &selection,
                                        const Bot3FridaySettings &friday,uchar &friday_closed,
                                        const Bot3SpreadSettings &spread_settings,const double &unit,double &spread,
                                        Bot3PendingQueue &queue)
{
   if(Bot3ProcessNewsAndFriday(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                               nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed)) return true;
   return Bot3ProcessHighSpread(spread_settings,unit,spread,execution,queue);
}

#endif
