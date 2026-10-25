// Start of bot 3 real management: SL level from the virtual SL table, close at once on a hit.
// The caller owns the stop, quote and request state passed by reference.
#ifndef BOT3_MANAGEMENT_REAL_START_MQH
#define BOT3_MANAGEMENT_REAL_START_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3VirtualStops.mqh"

// The label and value both follow the selected side.
bool Bot3CloseRealStopHit(const bool buy,const string &symbol,const double &current_stop,
                          MqlTick &tick,Bot3PendingRequestState &state,
                          Bot3TradeSendOptions &options,const ulong &deviation,
                          const double &gap,const double &freeze,const long ticket)
{
   Print("Closing with virtual SL");
   Print("Virtual_SL: "+(string)current_stop);
   Print((buy ? "Last Bid: " : "Last Ask: ")+(string)(buy ? tick.bid : tick.ask));
   SymbolInfoTick(symbol,tick);
   Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket);
   return true;
}

// SELL stores initial_stop before the hit check, BUY only when there is no hit.
// Strict ordered < means a NaN level or quote is never a hit.
bool Bot3StartRealManagement(const bool buy,const string &symbol,const double &unit,
                             const double &stop_distance,const long ticket,
                             Bot3ManagedPosition &position,MqlTick &tick,
                             Bot3VirtualStopState &table,long &open_tickets[],
                             double &initial_stop,double &current_stop,
                             Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                             const ulong &deviation,const double &gap,const double &freeze)
{
   double level=Bot3VirtualStopLevel(table,open_tickets,symbol,unit,buy ? 1 : 2,
                                     position.open_price,stop_distance,ticket);
   current_stop=level;
   if(!buy) initial_stop=level;
   if(buy ? tick.bid<level : level<tick.ask)
      return Bot3CloseRealStopHit(buy,symbol,current_stop,tick,state,options,deviation,
                                  gap,freeze,ticket);
   if(buy) initial_stop=level;
   return false;
}
#endif
