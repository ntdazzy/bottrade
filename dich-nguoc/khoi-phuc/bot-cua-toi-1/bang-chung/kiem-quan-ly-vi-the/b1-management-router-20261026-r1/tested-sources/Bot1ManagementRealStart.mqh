// Real stop-hit path; verification scope is recorded in the associated evidence.
// Real-management start (table stop read, shared stop write, hit close); manager and EA stay separate.
// The hit test is written a<b so a NaN operand or an equal price does not hit.
#ifndef BOT1_MANAGEMENT_REAL_START_MQH
#define BOT1_MANAGEMENT_REAL_START_MQH
#include "Bot1ManagementPrelude.mqh"
#include "Bot1VirtualStops.mqh"

// Each value is read on its own Print line; the tick is refreshed only after the third line.
bool Bot1CloseRealStopHit(const bool buy,const string &symbol,const double &current_stop,
                          MqlTick &tick,Bot1PendingRequestState &state,
                          Bot1TradeSendOptions &options,const ulong &deviation,
                          const double &gap,const double &freeze,const long ticket)
{
   Print("Closing with virtual SL");
   Print("Virtual_SL: "+(string)current_stop);
   Print((buy ? "Last Bid: " : "Last Ask: ")+(string)(buy ? tick.bid : tick.ask));
   // Result ignored; nothing here resets tick when the refresh fails.
   SymbolInfoTick(symbol,tick);
   Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,(ulong)ticket);
   return true;
}

bool Bot1StartRealManagement(const bool buy,const string &symbol,const double &unit,
                             const double &stop_distance,const long ticket,
                             Bot1ManagedPosition &position,MqlTick &tick,
                             Bot1VirtualStopState &table,long &open_tickets[],
                             double &initial_stop,double &current_stop,
                             Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                             const ulong &deviation,const double &gap,const double &freeze)
{
   double level=Bot1VirtualStopLevel(table,open_tickets,symbol,unit,buy ? 1 : 2,
                                     position.open_price,stop_distance,ticket);
   current_stop=level;
   // Sell writes initial_stop before the price test; buy writes it only when not hit.
   if(!buy) initial_stop=level;
   // The passed tick is not refreshed before this test.
   if(buy ? tick.bid<level : level<tick.ask)
      return Bot1CloseRealStopHit(buy,symbol,current_stop,tick,state,options,deviation,
                                  gap,freeze,ticket);
   if(buy) initial_stop=level;
   return false;
}
#endif
