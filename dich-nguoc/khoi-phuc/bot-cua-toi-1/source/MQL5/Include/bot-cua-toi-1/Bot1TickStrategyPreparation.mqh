#ifndef BOT1_TICK_STRATEGY_PREPARATION_MQH
#define BOT1_TICK_STRATEGY_PREPARATION_MQH
#include "Bot1TickSymbolRouting.mqh"
#include "Bot1VirtualStops.mqh"

// Native order: symbol routing, optional virtual-table cleanup, then caller's
// direct evaluation or strategy loop. This helper does not evaluate a strategy.
bool Bot1PrepareTickStrategy(const string &chart_symbol,string &working_symbol,
                             const uchar &virtual_flag,Bot1VirtualStopState &virtual_state,
                             long &open_tickets[])
{
   if(!Bot1PrepareTickSymbol(chart_symbol,working_symbol)) return false;
   if(virtual_flag!=0) Bot1DropClosedVirtualStops(virtual_state,open_tickets);
   return true;
}
#endif
