// Real stop store slice. Not compiled; verification is pending.
#ifndef BOT3_MANAGEMENT_REAL_STORE_MQH
#define BOT3_MANAGEMENT_REAL_STORE_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3VirtualStops.mqh"

// Digits are queried before each current_stop read; ordered == treats NaN as unequal.
void Bot3StoreRealStop(const string &symbol,const double initial_stop,const double &current_stop,
                       const double cached_ticket_number,Bot3VirtualStopState &table)
{
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double previous=Bot3RoundPrice(initial_stop,digits);
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double current=Bot3RoundPrice(current_stop,digits);
   if(previous==current) return;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   current=Bot3RoundPrice(current_stop,digits);
   if(table.guard!=1) return;
   for(int row=0;row<BOT3_VIRTUAL_STOP_ROWS;row++)
   {
      if(table.rows[row][0]==cached_ticket_number)
      {
         table.rows[row][1]=current;
         break;
      }
   }
}

#endif
