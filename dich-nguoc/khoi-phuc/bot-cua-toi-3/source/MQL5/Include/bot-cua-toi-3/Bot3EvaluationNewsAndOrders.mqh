#ifndef BOT3_EVALUATION_NEWS_AND_ORDERS_MQH
#define BOT3_EVALUATION_NEWS_AND_ORDERS_MQH
#include "Bot3NewsFridaySpreadRestoreFlow.mqh"
#include "Bot3PendingLimitStage.mqh"

bool Bot3EvaluateNewsAndPendingLimits(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                                      const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                                      const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                                      Bot3NewsEvents &events,const MqlDateTime &cached_calendar,
                                      const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                      Bot3NfpExecution &execution,Bot3NewsSelection &selection,
                                      const Bot3FridaySettings &friday,uchar &friday_closed,
                                      const Bot3SpreadSettings &spread_settings,const double &unit,double &spread,
                                      Bot3PendingQueue &queue,const Bot3PendingRestoreSettings &restore,
                                      const int &pending_enabled,const int &maximum_pending)
{
   if(Bot3ProcessNewsFridaySpreadRestore(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                                         nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
                                         spread_settings,unit,spread,queue,restore)) return true;
   Bot3ApplyPendingLimit(pending_enabled,maximum_pending,execution,queue);
   return false;
}

#endif
