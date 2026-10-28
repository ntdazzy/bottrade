#ifndef BOT1_STARTUP_POST_PREPARATION_MQH
#define BOT1_STARTUP_POST_PREPARATION_MQH
#include "Bot1StartupTradingState.mqh"
#include "Bot1StartupTail.mqh"

// OnInit 0x3cab..0x5658. Both parts use the same native state and lot array.
int Bot1InitializeStartupPostPreparation(const Bot1PreparationInputs &inputs,
                                         Bot1PreparationState &p,const int &magic,
                                         Bot1EntryLoopState &entry,Bot1NfpFilterState &nfp,
                                         Bot1ReleaseFilterState &interest,Bot1ReleaseFilterState &cpi,
                                         Bot1PositionManagementState &management,Bot1PendingQueue &queue,
                                         Bot1LevelCacheSettings &levels,double &minimum_spread,
                                         uchar &friday_closed,long &bar_times[],
                                         const uchar &show_panel,const uchar &show_tester,
                                         const uchar &history_window,const int &magic_base,
                                         const double &effective_balance,Bot1PanelCreationState &panel,
                                         const Bot1NewsEvents &events,const Bot1NewsWindows &windows,
                                         Bot1NewsSelection &selection,ulong &last_ticket,int &last_hour,
                                         double &wins,double &losses,Bot1StartupTradingState &trading,
                                         Bot1StartupTailState &tail)
{
   Bot1InitializeTradingState(inputs,p,magic,entry,nfp,interest,cpi,management,queue,levels,
                              minimum_spread,friday_closed,panel.lots,last_ticket,trading);
   return Bot1InitializeStartupTail(p.comment,inputs.symbol,p.strategy_index,p.native_62530,
                                    p.calendar,bar_times,show_panel,show_tester,history_window,
                                    magic,magic_base,effective_balance,panel,events,windows,
                                    selection,last_ticket,last_hour,wins,losses,tail);
}
#endif
