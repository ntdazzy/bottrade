#ifndef BOT1_NEWS_FILTER_PIPELINE_MQH
#define BOT1_NEWS_FILTER_PIPELINE_MQH
#include "Bot1ReleaseFilters.mqh"
bool Bot1ProcessNewsFilters(const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                            const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                            const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                            Bot1NewsEvents &events,const MqlDateTime &cached_calendar,
                            const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                            Bot1NfpExecution &execution,Bot1NewsSelection &selection)
{
   Bot1ProcessNfpFilter(nfp_settings,nfp,events,cached_calendar,nfp_history,execution);
   Bot1ProcessReleaseFilter(true,nfp_settings.use_calendar,nfp_settings.throttle,nfp.utc_reference,
                            interest_settings,interest,events.interest,interest_history,execution);
   Bot1ProcessReleaseFilter(false,nfp_settings.use_calendar,nfp_settings.throttle,nfp.utc_reference,
                            cpi_settings,cpi,events.cpi,cpi_history,execution);
   Bot1UpdateNewsSelectionFields(nfp_settings.enabled,events.nfp,nfp_settings.after_minutes,
                                  interest_settings.enabled,events.interest,interest_settings.after_minutes,
                                  cpi_settings.enabled,events.cpi,cpi_settings.after_minutes,selection);
   return nfp.blocked!=0 || (interest.blocked&1)!=0 || (cpi.blocked&1)!=0;
}
#endif
