#ifndef BOT3_STARTUP_POST_PREPARATION_MQH
#define BOT3_STARTUP_POST_PREPARATION_MQH
#include "Bot3StartupTradingState.mqh"
#include "Bot3StartupTail.mqh"

// OnInit 0x458e..0x5f34. Both parts use the same native state and lot array.
int Bot3InitializeStartupPostPreparation(const Bot3PreparationInputs &inputs,
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
   Bot3InitializeTradingState(inputs,p,magic,entry,nfp,interest,cpi,management,queue,levels,
                              minimum_spread,panel.lots,last_ticket,trading);
   return Bot3InitializeStartupTail(order_comment,inputs.symbol,p.strategy_index,p.native_6d620,
                                    p.calendar,bar_times,show_panel,show_tester,history_window,
                                    magic,magic_base,effective_balance,panel,events,windows,
                                    selection,last_ticket,last_hour,wins,losses,tail);
}
#endif
