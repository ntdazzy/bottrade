#ifndef BOT3_STARTUP_PREPARATION_FLOW_MQH
#define BOT3_STARTUP_PREPARATION_FLOW_MQH
#include "Bot3StartupPostPreparation.mqh"

// The panel keeps mode unsigned while preparation state stores the same value signed.
// manual_lots is the input value; native_6d620 is the separately prepared value.
int Bot3InitializeStartupPreparationFlow(Bot3PreparationInputs &inputs,
                                         Bot3PreparationState &p,const int &magic,
                                         const string &order_comment,
                                         Bot3EntryLoopState &entry,Bot3NfpFilterState &nfp,
                                         Bot3ReleaseFilterState &interest,Bot3ReleaseFilterState &cpi,
                                         Bot3PositionManagementState &management,Bot3PendingQueue &queue,
                                         Bot3LevelCacheSettings &levels,double &minimum_spread,
                                         long &bar_times[],
                                         const uchar &show_panel,const uchar &show_tester,
                                         const uchar &history_window,const int &magic_base,
                                         const double &effective_balance,Bot3PanelCreationState &panel,
                                         const Bot3NewsEvents &events,const Bot3NewsWindows &windows,
                                         Bot3NewsSelection &selection,ulong &last_ticket,int &last_hour,
                                         double &wins,double &losses,Bot3StartupTradingState &trading,
                                         Bot3StartupTailState &tail)
{
   panel.manual_lots=inputs.native_1d7138;
   p.native_6d630=(int)panel.mode;
   Bot3PrepareStrategyWithSharedFields(0,inputs,p,panel.manual_lots,panel.mode);
   inputs.native_1d7138=panel.manual_lots;
   p.native_6d630=(int)panel.mode;
   // Source coordinator 0x4580..0x5f34 continues after preparation returns early.
   const int result=Bot3InitializeStartupPostPreparation(inputs,p,magic,order_comment,entry,nfp,
                                                         interest,cpi,management,queue,levels,
                                                         minimum_spread,bar_times,show_panel,
                                                         show_tester,history_window,magic_base,
                                                         effective_balance,panel,events,windows,
                                                         selection,last_ticket,last_hour,wins,losses,
                                                         trading,tail);
   inputs.native_1d7138=panel.manual_lots;
   p.native_6d630=(int)panel.mode;
   return result;
}
#endif
