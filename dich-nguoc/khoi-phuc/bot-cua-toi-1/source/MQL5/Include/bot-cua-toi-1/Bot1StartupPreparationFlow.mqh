#ifndef BOT1_STARTUP_PREPARATION_FLOW_MQH
#define BOT1_STARTUP_PREPARATION_FLOW_MQH
#include "Bot1StartupPostPreparation.mqh"

// OnInit 0x3c9d..0x5658 calls preparation with index zero, then continues
// even when preparation returns early. Do not reset its outputs here.
int Bot1InitializeStartupPreparationFlow(const Bot1PreparationInputs &inputs,
                                         Bot1PreparationState &p,const int &magic,
                                         const string &order_comment,
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
   Bot1PrepareStrategy(0,inputs,p);
   return Bot1InitializeStartupPostPreparation(inputs,p,magic,order_comment,entry,nfp,interest,cpi,
      management,queue,levels,minimum_spread,friday_closed,bar_times,show_panel,show_tester,
      history_window,magic_base,effective_balance,panel,events,windows,selection,last_ticket,
      last_hour,wins,losses,trading,tail);
}
#endif
