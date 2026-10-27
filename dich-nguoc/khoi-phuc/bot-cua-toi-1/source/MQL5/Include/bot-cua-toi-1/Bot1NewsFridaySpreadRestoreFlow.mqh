#ifndef BOT1_NEWS_FRIDAY_SPREAD_RESTORE_FLOW_MQH
#define BOT1_NEWS_FRIDAY_SPREAD_RESTORE_FLOW_MQH
#include "Bot1NewsFridaySpreadFlow.mqh"
#include "Bot1PendingQueueLive.mqh"

bool Bot1ProcessNewsFridaySpreadRestore(const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                                        const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                                        const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                                        Bot1NewsEvents &events,const MqlDateTime &cached_calendar,
                                        const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                        Bot1NfpExecution &execution,Bot1NewsSelection &selection,
                                        const Bot1FridaySettings &friday,uchar &friday_closed,
                                        const Bot1SpreadSettings &spread_settings,const double &unit,double &spread,
                                        Bot1PendingQueue &queue,const Bot1PendingRestoreSettings &restore)
{
   if(Bot1ProcessNewsFridayAndHighSpread(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached_calendar,
                                         nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,
                                         spread_settings,unit,spread,queue)) return true;
   if(spread_settings.enabled!=0 && Bot1QueueProduct(unit,spread_settings.minimum)>=spread)
   {
      if(!((friday.enabled&1)!=0 && cached_calendar.day_of_week==5 && cached_calendar.hour>=friday.hour))
         Bot1ProcessPendingQueueLive(queue,restore,unit,execution);
   }
   return false;
}

#endif
