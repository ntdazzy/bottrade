#ifndef BOT1_STARTUP_CONTEXT_FLOW_MQH
#define BOT1_STARTUP_CONTEXT_FLOW_MQH
#include "Bot1StartupContext.mqh"
#include "Bot1StartupPreparationFlow.mqh"

// OnInit 0x3827..0x5658. Keep the context's symbol, magic, comment and panel
// in the objects used by preparation and the final startup work.
int Bot1InitializeStartupContextFlow(const string &chart_symbol,
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
                                     const uchar &history_window,const double &effective_balance,
                                     Bot1PanelCreationState &panel,const Bot1NewsEvents &events,
                                     const Bot1NewsWindows &windows,Bot1NewsSelection &selection,
                                     ulong &last_ticket,int &last_hour,double &wins,double &losses,
                                     Bot1StartupTradingState &trading,Bot1StartupTailState &tail)
{
   Bot1InitializeStartupContext(chart_symbol,context_inputs,context,inputs,history,panel,daily,startup);
   return Bot1InitializeStartupPreparationFlow(inputs,p,context.magic,context.order_comment,
      entry,nfp,interest,cpi,management,queue,levels,minimum_spread,friday_closed,bar_times,
      show_panel,show_tester,history_window,context_inputs.base_magic,effective_balance,
      panel,events,windows,selection,last_ticket,last_hour,wins,losses,trading,tail);
}
#endif
