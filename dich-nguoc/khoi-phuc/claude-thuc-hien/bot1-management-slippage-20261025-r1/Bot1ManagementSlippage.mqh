// One native virtual-stop segment: bot1 0x29c64..0x29de9 / 0x2d3d1..0x2d55a.
// Candidate written from virtual-slippage-contract.md; runtime comparison is pending.
#ifndef BOT1_MANAGEMENT_SLIPPAGE_MQH
#define BOT1_MANAGEMENT_SLIPPAGE_MQH

void Bot1AdvanceSlippageVirtualStop(const bool buy,const string &symbol,
                                    const int enabled,const bool distance_passed,
                                    const double &reference_level,const double &trail_distance,
                                    const double &start_distance,const double &limit_distance,
                                    const double &freeze_distance,const double &unit,
                                    const double &open_price,const double &take_profit,
                                    MqlTick &tick,double &current_level,bool &changed)
{
   if(enabled!=1 || !distance_passed || !(0.0<trail_distance)) return;
   double level=current_level;
   double quote=buy ? tick.bid : tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double offset=trail_distance*unit;
   if(buy)
   {
      if(!(level+point+offset<quote)) return;
      if(!(reference_level+start_distance*unit<tick.bid)) return;
      if(!(tick.bid<take_profit-freeze_distance)) return;
      if(!(current_level<unit*limit_distance+open_price)) return;
      Print("Slippage control active");
      quote=tick.bid;
      double refreshed_distance=trail_distance;
      double refreshed_unit=unit;
      changed=true;
      current_level=quote-refreshed_distance*refreshed_unit;
      return;
   }
   if(!(quote<(level-point)-offset)) return;
   if(!(tick.ask<reference_level-start_distance*unit)) return;
   if(!(freeze_distance+take_profit<tick.ask)) return;
   if(!(open_price-unit*limit_distance<current_level)) return;
   Print("Slippage controle active");
   quote=tick.ask;
   double refreshed_distance=trail_distance;
   double refreshed_unit=unit;
   changed=true;
   current_level=refreshed_distance*refreshed_unit+quote;
}

#endif
