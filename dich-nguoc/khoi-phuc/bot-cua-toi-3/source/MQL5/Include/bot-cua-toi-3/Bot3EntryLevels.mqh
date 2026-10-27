// Reconstructed components, not a complete EA. Bot 3 native RVAs:
// 0x31cd0/0x32090 (entry levels), 0x47380/0x475e0 (nearby pending orders).
#ifndef BOT3_ENTRY_LEVELS_MQH
#define BOT3_ENTRY_LEVELS_MQH
#include "Bot3PriceLevels.mqh"

bool Bot3NearbyPending(const bool buy,const double level,const string &symbol,const int &magic,
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

double Bot3EntryPrice(const bool buy,const string &symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   return buy ? iHigh(symbol,timeframe,shift) : iLow(symbol,timeframe,shift);
}

double Bot3EntryLevel(const bool buy,const string &symbol,const ENUM_TIMEFRAMES timeframe,
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
         double neighbor=Bot3EntryPrice(buy,symbol,timeframe,i);
         double candidate=Bot3EntryPrice(buy,symbol,timeframe,shift);
         if(buy ? candidate<neighbor : neighbor<candidate) { rejected=true; break; }
      }
      if(!rejected)
         for(int i=shift;i<=shift+older_width;i++)
         {
            double neighbor=Bot3EntryPrice(buy,symbol,timeframe,i);
            double candidate=Bot3EntryPrice(buy,symbol,timeframe,shift);
            if(buy ? candidate<neighbor : neighbor<candidate) { rejected=true; break; }
         }
      if(!rejected)
      {
         double candidate=Bot3EntryPrice(buy,symbol,timeframe,shift);
         if(buy ? gap_points*unit+quote<candidate : candidate<quote-gap_points*unit)
         {
            candidate=Bot3EntryPrice(buy,symbol,timeframe,shift);
            double extreme=Bot3EntryPrice(buy,symbol,confirm_timeframe,0);
            for(int i=1;i<=shift;i++)
            {
               double value=Bot3EntryPrice(buy,symbol,confirm_timeframe,i);
               if(buy ? (extreme<=value && value!=extreme) : (value<=extreme && extreme!=value))
                  extreme=Bot3EntryPrice(buy,symbol,confirm_timeframe,i);
            }
            if(buy ? extreme<=candidate : candidate<=extreme)
            {
               uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
               double value=Bot3EntryPrice(buy,symbol,timeframe,shift);
               double level=Bot3RoundPrice(value,digits);
               if(!Bot3NearbyPending(buy,level,symbol,magic,buy_offset,sell_offset,unit,radius,last_ticket))
               {
                  digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
                  value=Bot3EntryPrice(buy,symbol,timeframe,shift);
                  return Bot3RoundPrice(value,digits);
               }
            }
         }
      }
      shift++;
   } while(shift<=last_shift);
   return 0.0;
}
#endif
