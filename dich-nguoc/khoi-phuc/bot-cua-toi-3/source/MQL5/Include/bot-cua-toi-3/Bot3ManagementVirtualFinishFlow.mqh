// Reconstructed virtual-finish flow only; not a complete manager or EA.
// Compile and runtime comparison with the original EX5 are still required.
#ifndef BOT3_MANAGEMENT_VIRTUAL_FINISH_FLOW_MQH
#define BOT3_MANAGEMENT_VIRTUAL_FINISH_FLOW_MQH
#include "Bot3ManagementVirtualFinish.mqh"

// Both advance blocks always run; the ordered hit test then reads current_level and tick.
// Hit: tick refresh, Bot3TryClosePosition, true. No hit: table store, false.
bool Bot3FinishVirtualManagementFields(const bool buy,const string &symbol,
                                 const Bot3VirtualFinishSettings &settings,const double &unit,
                                 const double &gap,const double &freeze,
                                 const double selected_anchor,const double &copied_step,
                                 const Bot3ManagedPosition &position,MqlTick &tick,
                                 const double &levels[],const uint &strategy_index,
                                 double &current_level,double &current_take,bool &changed,int &counter,
                                 const double initial_stop,const double initial_take,const long ticket,
                                 Bot3VirtualStopState &table,Bot3PendingRequestState &state,
                                 Bot3TradeSendOptions &options,const ulong &deviation,
                                 const int &high_low_enabled,const double &step_reference)
{
   Bot3AdvanceVirtualHighLowFields(buy,symbol,settings,unit,gap,freeze,position,tick,
                                   levels,strategy_index,current_level,changed,
                                   high_low_enabled);
   Bot3AdvanceVirtualBreakEvenCounterFields(buy,symbol,settings,unit,gap,freeze,
                                            selected_anchor,copied_step,position,tick,
                                            current_level,changed,counter,step_reference);
   if(buy ? current_level>=tick.bid : tick.ask>=current_level)
   {
      SymbolInfoTick(symbol,tick);
      Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket);
      return true;
   }
   Bot3StoreVirtualLevels(symbol,initial_stop,initial_take,current_level,current_take,
                          (double)ticket,table);
   return false;
}

bool Bot3FinishVirtualManagement(const bool buy,const string &symbol,
                                 const Bot3VirtualFinishSettings &settings,const double &unit,
                                 const double &gap,const double &freeze,
                                 const double selected_anchor,const double &copied_step,
                                 const Bot3ManagedPosition &position,MqlTick &tick,
                                 const double &levels[],const uint &strategy_index,
                                 double &current_level,double &current_take,bool &changed,int &counter,
                                 const double initial_stop,const double initial_take,const long ticket,
                                 Bot3VirtualStopState &table,Bot3PendingRequestState &state,
                                 Bot3TradeSendOptions &options,const ulong &deviation)
{
   return Bot3FinishVirtualManagementFields(buy,symbol,settings,unit,gap,freeze,
                                             selected_anchor,copied_step,position,tick,levels,
                                             strategy_index,current_level,current_take,changed,counter,
                                             initial_stop,initial_take,ticket,table,state,options,deviation,
                                             settings.high_low_enabled,settings.step_reference);
}
#endif
