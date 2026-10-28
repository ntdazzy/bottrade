#ifndef BOT3_STARTUP_NEWS_FLOW_MQH
#define BOT3_STARTUP_NEWS_FLOW_MQH
#include "Bot3NewsInitialization.mqh"
#include "Bot3StartupAccountFlow.mqh"

// OnInit 0xd60..0x5f34, after the authorization/tester gate. Keep the context's symbol, magic, comment and panel
// in the objects used by preparation and the final startup work.
int Bot3InitializeStartupNewsFlow(const uchar &use_equity,const uchar &reset_highest,
                                     const double &manual_balance,double &highest_balance,
                                     string &peak_key,string &time_key,long &last_deal_time,
                                     uchar &news_flag0,uchar &news_flag1,long &nfp_history[],
                                     long &interest_history[],long &cpi_history[],
                                     const int &winter_hours,const int &summer_hours,
                                     long &adjusted_time,const int &frequency,
                                     const uchar &thresholds[],const uchar &manual[],
                                     uchar &enabled[],double &divisor,const string &chart_symbol,
                                     Bot3StrategyContextInputs &context_inputs,
                                     Bot3StrategyContextState &context,
                                     Bot3StrategyHistoryCache &history,Bot3DailyLossState &daily,
                                     Bot3StartupContextState &startup,
                                     Bot3PreparationInputs &inputs,Bot3PreparationState &p,
                                     Bot3EntryLoopState &entry,Bot3NfpFilterState &nfp,
                                     Bot3ReleaseFilterState &interest,Bot3ReleaseFilterState &cpi,
                                     Bot3PositionManagementState &management,Bot3PendingQueue &queue,
                                     Bot3LevelCacheSettings &levels,double &minimum_spread,
                                     long &bar_times[],
                                     const uchar &show_panel,const uchar &show_tester,
                                     const uchar &history_window,double &effective_balance,
                                     Bot3PanelCreationState &panel,Bot3NewsEvents &events,
                                     const Bot3NewsWindows &windows,Bot3NewsSelection &selection,
                                     ulong &last_ticket,int &last_hour,double &wins,double &losses,
                                     Bot3StartupTradingState &trading,Bot3StartupTailState &tail)
{
   Bot3InitializeNews(windows,events,selection,nfp.last_query);
   return Bot3InitializeStartupAccountFlow(use_equity,reset_highest,manual_balance,highest_balance,
      peak_key,time_key,last_deal_time,news_flag0,news_flag1,nfp_history,interest_history,cpi_history,
      winter_hours,summer_hours,adjusted_time,frequency,thresholds,manual,enabled,divisor,chart_symbol,
      context_inputs,context,history,daily,startup,inputs,p,entry,nfp,interest,cpi,management,queue,
      levels,minimum_spread,bar_times,show_panel,show_tester,history_window,effective_balance,
      panel,events,windows,selection,last_ticket,last_hour,wins,losses,trading,tail);
}
#endif
