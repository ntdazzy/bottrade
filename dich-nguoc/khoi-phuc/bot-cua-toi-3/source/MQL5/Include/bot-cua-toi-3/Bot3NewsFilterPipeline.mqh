#ifndef BOT3_NEWS_FILTER_PIPELINE_MQH
#define BOT3_NEWS_FILTER_PIPELINE_MQH
#include "Bot3ReleaseFilters.mqh"
bool Bot3ProcessNewsFilters(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                            const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                            const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                            Bot3NewsEvents &events,const MqlDateTime &cached_calendar,
                            const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                            Bot3NfpExecution &execution,Bot3NewsSelection &selection)
{
   Bot3ProcessNfpFilter(nfp_settings,nfp,events,cached_calendar,nfp_history,execution);
   Bot3ProcessReleaseFilter(true,nfp_settings.use_calendar,nfp_settings.throttle,nfp.utc_reference,
                            interest_settings,interest,events.interest,interest_history,execution);
   Bot3ProcessReleaseFilter(false,nfp_settings.use_calendar,nfp_settings.throttle,nfp.utc_reference,
                            cpi_settings,cpi,events.cpi,cpi_history,execution);
   Bot3UpdateNewsSelectionFields(nfp_settings.enabled,events.nfp,nfp_settings.after_minutes,
                                  interest_settings.enabled,events.interest,interest_settings.after_minutes,
                                  cpi_settings.enabled,events.cpi,cpi_settings.after_minutes,selection);
   return nfp.blocked!=0 || (interest.blocked&1)!=0 || (cpi.blocked&1)!=0;
}
#endif
