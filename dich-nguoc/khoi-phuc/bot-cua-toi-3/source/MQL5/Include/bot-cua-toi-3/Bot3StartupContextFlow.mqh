#ifndef BOT3_STARTUP_CONTEXT_FLOW_MQH
#define BOT3_STARTUP_CONTEXT_FLOW_MQH
#include "Bot3StartupContext.mqh"
#include "Bot3StartupPreparationFlow.mqh"

// OnInit 0x3ce6..0x5f34. Keep the context's symbol, magic, comment and panel
// in the objects used by preparation and the final startup work.
int Bot3InitializeStartupContextFlow(const string &chart_symbol,
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
                                     const uchar &history_window,const double &effective_balance,
                                     Bot3PanelCreationState &panel,const Bot3NewsEvents &events,
                                     const Bot3NewsWindows &windows,Bot3NewsSelection &selection,
                                     ulong &last_ticket,int &last_hour,double &wins,double &losses,
                                     Bot3StartupTradingState &trading,Bot3StartupTailState &tail)
{
   Bot3InitializeStartupContext(chart_symbol,context_inputs,context,inputs,history,panel,daily,startup);
   return Bot3InitializeStartupPreparationFlow(inputs,p,context.magic,context.order_comment,
      entry,nfp,interest,cpi,management,queue,levels,minimum_spread,bar_times,
      show_panel,show_tester,history_window,context_inputs.base_magic,effective_balance,
      panel,events,windows,selection,last_ticket,last_hour,wins,losses,trading,tail);
}
#endif
