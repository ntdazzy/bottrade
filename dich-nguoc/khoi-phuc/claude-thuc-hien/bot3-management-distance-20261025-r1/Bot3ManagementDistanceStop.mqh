// Candidate only: not compiled, not run, not compared with the original EX5.
// Native segments in 0x32f60/0x37590: buy 0x35fd3..0x36189, sell 0x3a2f7..0x3a4af.
// Segments only, not the complete managers; this part has no take-profit condition.
#ifndef BOT3_MANAGEMENT_DISTANCE_STOP_MQH
#define BOT3_MANAGEMENT_DISTANCE_STOP_MQH
#include "Bot3ManagementPrelude.mqh"

// Ordered compares: NaN fails every condition. Close helper is 0x47d20, not 0x2e370.
bool Bot3AdvanceDistanceVirtualStop(bool buy,const string &symbol,const double &unit,
                                    const double &trail_distance,const double &trail_step,
                                    const double &trail_start,const double &trail_limit,
                                    const double anchor,const Bot3ManagedPosition &position,
                                    MqlTick &tick,const double &volumes[],const uint &strategy_index,
                                    double &current_level,bool &changed,
                                    Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                    const ulong &deviation,const double &threshold_a,
                                    const double &threshold_b,const ulong ticket)
{
   if(!(0.0<trail_distance)) return false;
   double level=current_level;
   double quote=buy ? tick.bid : tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double trail=trail_distance;
   double u=unit;
   double offset=(trail_step+trail)*u;
   if(buy)
   {
      if(!(offset+(level+point)<quote)) return false;
      if(!(trail_start*u+anchor<tick.bid)) return false;
      if(!(current_level<trail_limit*u+position.open_price)) return false;
      current_level=tick.bid-trail*u;
   }
   else
   {
      if(!(quote<((level-point)-offset))) return false;
      if(!(tick.ask<(anchor-trail_start*u))) return false;
      if(!((position.open_price-trail_limit*u)<current_level)) return false;
      current_level=trail*u+tick.ask;
   }
   double volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2);
   changed=true;
   if(!(volume<position.volume)) return false;
   double minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
   if(!(minimum<=volume)) return false;
   Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,threshold_a,threshold_b,ticket);
   return true;
}
#endif
