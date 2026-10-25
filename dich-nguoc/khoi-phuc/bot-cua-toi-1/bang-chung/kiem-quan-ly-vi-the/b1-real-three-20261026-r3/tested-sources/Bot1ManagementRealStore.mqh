// Real-stop table store only; mode checks, closing and current_stop writes stay with the caller.
#ifndef BOT1_MANAGEMENT_REAL_STORE_MQH
#define BOT1_MANAGEMENT_REAL_STORE_MQH
#include "Bot1ManagementPrelude.mqh"
#include "Bot1VirtualStops.mqh"

void Bot1StoreRealStop(const string &symbol,const double initial_stop,const double &current_stop,
                       const double cached_ticket_number,Bot1VirtualStopState &table)
{
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double previous=Bot1RoundPrice(initial_stop,digits);
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double current=Bot1RoundPrice(current_stop,digits);
   if(previous==current) return;
   // Third DIGITS query and fresh current_stop read happen before the guard read.
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   current=Bot1RoundPrice(current_stop,digits);
   if(table.guard!=1) return;
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
      if(table.rows[row][0]==cached_ticket_number)
      {
         table.rows[row][1]=current;
         break;
      }
}
#endif
