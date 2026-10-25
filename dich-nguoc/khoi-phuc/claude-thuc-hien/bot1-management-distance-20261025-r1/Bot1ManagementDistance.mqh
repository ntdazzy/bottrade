// Native bot 1 virtual distance trailing: buy 0x29aab..0x29c64, sell 0x2d1fd..0x2d3d1.
// One segment of the virtual stop branch, not a complete management function.
// trail_distance 0x624a8, trail_step 0x624c0, trail_start 0x624b0, trail_limit 0x624b8,
// unit 0x66d98, current_level 0x62580, volumes 0x66a80, strategy_index 0x678f4.
#ifndef BOT1_MANAGEMENT_DISTANCE_MQH
#define BOT1_MANAGEMENT_DISTANCE_MQH
#include "Bot1PriceLevels.mqh"
#include "Bot1PositionClose.mqh"
#include "Bot1ManagementPrelude.mqh"

// Returns true when the close call was made; current_level and changed are set before it.
bool Bot1AdvanceDistanceVirtualStop(const bool buy,const string &symbol,const double &unit,
                                    const double &trail_distance,const double &trail_step,
                                    const double &trail_start,const double &trail_limit,
                                    const double anchor,const Bot1ManagedPosition &position,
                                    MqlTick &tick,const double &volumes[],const uint &strategy_index,
                                    double &current_level,bool &changed,
                                    Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                    const ulong &deviation)
{
   if(!(0.0<trail_distance)) return false;
   double level=current_level;
   double quote=buy ? tick.bid : tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double distance=(trail_step+trail_distance)*unit;
   if(buy)
   {
      if(!(level+point+distance<quote)) return false;
      if(!(trail_start*unit+anchor<tick.bid)) return false;
      if(!(current_level<trail_limit*unit+position.open_price)) return false;
      current_level=tick.bid-trail_distance*unit;
   }
   else
   {
      if(!(quote<(level-point)-distance)) return false;
      if(!(tick.ask<anchor-trail_start*unit)) return false;
      if(!(position.open_price-trail_limit*unit<current_level)) return false;
      current_level=trail_distance*unit+tick.ask;
   }
   // Keep the multiply: NaN or infinite table values must stay NaN.
   double volume=Bot1RoundPrice(volumes[strategy_index]*0.0,2);
   changed=true;
   if(!(volume<position.volume)) return false;
   double minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
   if(!(minimum<=volume)) return false;
   Bot1ClosePosition(state,options,deviation,(ulong)(long)position.ticket_number);
   return true;
}
#endif
