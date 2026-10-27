#ifndef BOT3_NEWS_FRIDAY_SPREAD_RESTORE_FLOW_MQH
#define BOT3_NEWS_FRIDAY_SPREAD_RESTORE_FLOW_MQH
#include "Bot3NewsFridaySpreadFlow.mqh"
#include "Bot3PendingQueueLive.mqh"

bool Bot3ProcessNewsFridaySpreadRestore(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                                        const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                                        const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                                        Bot3NewsEvents &events,const MqlDateTime &cached_calendar,
                                        const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                        Bot3NfpExecution &execution,Bot3NewsSelection &selection,
                                        const Bot3FridaySettings &friday,uchar &friday_closed,
                                        const Bot3SpreadSettings &spread_settings,const double &unit,double &spread,
                                        Bot3PendingQueue &queue,const Bot3PendingRestoreSettings &restore)
{
   if(Bot3ProcessNewsFridayAndHighSpread(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                                         nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
                                         spread_settings,unit,spread,queue)) return true;
   if(spread_settings.enabled!=0 && Bot3QueueProduct(unit,spread_settings.minimum)>=spread)
   {
      if(!((friday.enabled&1)!=0 && cached_calendar.day_of_week==5 && cached_calendar.hour>=friday.hour))
         Bot3ProcessPendingQueueLive(queue,restore,unit,execution);
   }
   return false;
}

#endif
