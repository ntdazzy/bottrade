#ifndef BOT1_STARTUP_ACCOUNT_FLOW_MQH
#define BOT1_STARTUP_ACCOUNT_FLOW_MQH
#include "Bot1AccountInitialization.mqh"
#include "Bot1BuiltInNewsHistory.mqh"
#include "Bot1StartupContextFlow.mqh"

// OnInit 0x126c..0x5658, after the initial news-selection call.
int Bot1InitializeStartupAccountFlow(const bool use_equity,const bool reset_highest,const double manual_balance,
                                     double &highest_balance,string &peak_key,string &time_key,
                                     long &last_deal_time,uchar &news_flag0,uchar &news_flag1,
                                     long &nfp_history[],long &interest_history[],long &cpi_history[],
                                     const string &chart_symbol,
                                     Bot1StrategyContextInputs &context_inputs,
                                     Bot1StrategyContextState &context,
                                     Bot1StrategyHistoryCache &history,Bot1DailyLossState &daily,
                                     Bot1StartupContextState &startup,
                                     Bot1PreparationInputs &inputs,Bot1PreparationState &p,
                                     Bot1EntryLoopState &entry,Bot1NfpFilterState &nfp,
                                     Bot1ReleaseFilterState &interest,Bot1ReleaseFilterState &cpi,
                                     Bot1PositionManagementState &management,Bot1PendingQueue &queue,
                                     Bot1LevelCacheSettings &levels,double &minimum_spread,
                                     uchar &friday_closed,long &bar_times[],
                                     const uchar &show_panel,const uchar &show_tester,
                                     const uchar &history_window,double &effective_balance,
                                     Bot1PanelCreationState &panel,const Bot1NewsEvents &events,
                                     const Bot1NewsWindows &windows,Bot1NewsSelection &selection,
                                     ulong &last_ticket,int &last_hour,double &wins,double &losses,
                                     Bot1StartupTradingState &trading,Bot1StartupTailState &tail)
{
   Bot1InitializeAccountState(use_equity,reset_highest,manual_balance,effective_balance,
                              highest_balance,peak_key,time_key,last_deal_time);
   Bot1InitializeBuiltInNewsHistory(news_flag0,news_flag1,nfp_history,interest_history,cpi_history);
   return Bot1InitializeStartupContextFlow(chart_symbol,context_inputs,context,history,daily,startup,
      inputs,p,entry,nfp,interest,cpi,management,queue,levels,minimum_spread,friday_closed,bar_times,
      show_panel,show_tester,history_window,effective_balance,panel,events,windows,selection,
      last_ticket,last_hour,wins,losses,trading,tail);
}
#endif
