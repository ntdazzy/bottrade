#ifndef BOT1_EVALUATION_NEWS_AND_ORDERS_MQH
#define BOT1_EVALUATION_NEWS_AND_ORDERS_MQH
#include "Bot1NewsFridaySpreadRestoreFlow.mqh"
#include "Bot1PendingLimitStage.mqh"

bool Bot1EvaluateNewsAndPendingLimits(const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                                      const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                                      const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                                      Bot1NewsEvents &events,const MqlDateTime &cached_calendar,
                                      const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                      Bot1NfpExecution &execution,Bot1NewsSelection &selection,
                                      const Bot1FridaySettings &friday,uchar &friday_closed,
                                      const Bot1SpreadSettings &spread_settings,const double &unit,double &spread,
                                      Bot1PendingQueue &queue,const Bot1PendingRestoreSettings &restore,
                                      const int &pending_enabled,const int &maximum_pending)
{
   if(Bot1ProcessNewsFridaySpreadRestore(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                                         nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
                                         spread_settings,unit,spread,queue,restore)) return true;
   Bot1ApplyPendingLimit(pending_enabled,maximum_pending,execution,queue);
   return false;
}

#endif
