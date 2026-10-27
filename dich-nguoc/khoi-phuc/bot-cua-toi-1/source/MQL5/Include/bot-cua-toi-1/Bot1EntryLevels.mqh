// Reconstructed components, not a complete EA. Bot 1 native RVAs:
// 0x265a0/0x26960 (entry levels), 0x3c670/0x3c8d0 (nearby pending orders).
#ifndef BOT1_ENTRY_LEVELS_MQH
#define BOT1_ENTRY_LEVELS_MQH
#include "Bot1PriceLevels.mqh"

bool Bot1NearbyPending(const bool buy,const double level,const string &symbol,const int &magic,
                      const double &buy_offset,const double &sell_offset,const double &unit,
                      const double &radius,ulong &last_ticket)
{
   // The native loop deliberately starts at OrdersTotal(), including one invalid index.
   for(int i=OrdersTotal();i>=0;i--)
   {
      last_ticket=OrderGetTicket(i);
      if(last_ticket==0 || OrderGetInteger(ORDER_MAGIC)!=(long)magic) continue;
      string current=OrderGetString(ORDER_SYMBOL);
      if(current!=symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)!=(buy ? ORDER_TYPE_BUY_STOP : ORDER_TYPE_SELL_STOP)) continue;
      double price=OrderGetDouble(ORDER_PRICE_OPEN);
      double target=buy ? buy_offset*unit+level : level-sell_offset*unit;
      if(MathAbs(price-target)<unit*radius) return true;
   }
   return false;
}

double Bot1EntryPrice(const bool buy,const string &symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   return buy ? iHigh(symbol,timeframe,shift) : iLow(symbol,timeframe,shift);
}

double Bot1EntryLevel(const bool buy,const string &symbol,const ENUM_TIMEFRAMES timeframe,
                     const ENUM_TIMEFRAMES &confirm_timeframe,const int &older_width,
                     const int &recent_width,const int &last_shift,const double &quote,
                     const double &gap_points,const double &unit,const int &magic,
                     const double &buy_offset,const double &sell_offset,const double &radius,
                     ulong &last_ticket)
{
   int shift=recent_width+1;
   do
   {
      bool rejected=false;
      for(int i=shift;i>=shift-recent_width;i--)
      {
         double neighbor=Bot1EntryPrice(buy,symbol,timeframe,i);
         double candidate=Bot1EntryPrice(buy,symbol,timeframe,shift);
         if(buy ? candidate<neighbor : neighbor<candidate) { rejected=true; break; }
      }
      if(!rejected)
         for(int i=shift;i<=shift+older_width;i++)
         {
            double neighbor=Bot1EntryPrice(buy,symbol,timeframe,i);
            double candidate=Bot1EntryPrice(buy,symbol,timeframe,shift);
            if(buy ? candidate<neighbor : neighbor<candidate) { rejected=true; break; }
         }
      if(!rejected)
      {
         double candidate=Bot1EntryPrice(buy,symbol,timeframe,shift);
         if(buy ? gap_points*unit+quote<candidate : candidate<quote-gap_points*unit)
         {
            candidate=Bot1EntryPrice(buy,symbol,timeframe,shift);
            double extreme=Bot1EntryPrice(buy,symbol,confirm_timeframe,0);
            for(int i=1;i<=shift;i++)
            {
               double value=Bot1EntryPrice(buy,symbol,confirm_timeframe,i);
               if(buy ? (extreme<=value && value!=extreme) : (value<=extreme && extreme!=value))
                  extreme=Bot1EntryPrice(buy,symbol,confirm_timeframe,i);
            }
            if(buy ? extreme<=candidate : candidate<=extreme)
            {
               uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
               double value=Bot1EntryPrice(buy,symbol,timeframe,shift);
               double level=Bot1RoundPrice(value,digits);
               if(!Bot1NearbyPending(buy,level,symbol,magic,buy_offset,sell_offset,unit,radius,last_ticket))
               {
                  digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
                  value=Bot1EntryPrice(buy,symbol,timeframe,shift);
                  return Bot1RoundPrice(value,digits);
               }
            }
         }
      }
      shift++;
   } while(shift<=last_shift);
   return 0.0;
}
#endif
