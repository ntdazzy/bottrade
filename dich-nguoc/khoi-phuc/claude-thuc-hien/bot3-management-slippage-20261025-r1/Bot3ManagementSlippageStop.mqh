// Candidate only: not compiled, not run, not compared with the original EX5.
// Slippage virtual-stop segments: buy 0x364e2..0x36667 in native 0x32f60
// (exits 0x3672c/0x36736/0x36813), sell 0x3a803..0x3a97d in native 0x37590.
// Not a complete management function; no Modify, Close or rounding here.
#ifndef BOT3_MANAGEMENT_SLIPPAGE_STOP_MQH
#define BOT3_MANAGEMENT_SLIPPAGE_STOP_MQH
#include "Bot3ManagementPrelude.mqh"

// Inputs: enabled int 0x6d4e8; distance_passed byte local 0x5c buy/0x54 sell;
// start/trail/limit doubles 0x6d4f0/0x6d4f8/0x6d500; freeze double 0x744a8.
// level and quote are read before the POINT call, unit once after it; trail distance,
// unit and tick are read again after Print. A NaN operand fails every ordered check.
void Bot3AdvanceSlippageVirtualStop(bool buy,const string &symbol,const double &unit,
                                    const int &enabled,const bool distance_passed,
                                    const double reference,const double &trail_distance,
                                    const double &start_distance,const double &limit_distance,
                                    const double &freeze_distance,const Bot3ManagedPosition &position,
                                    MqlTick &tick,double &current_level,bool &changed)
{
   if(enabled!=1 || !distance_passed || !(0.0<trail_distance)) return;
   double level=current_level;
   double quote=buy ? tick.bid : tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double unit_value=unit;
   double offset=trail_distance*unit_value;
   if(buy)
   {
      if(!(offset+(level+point)<quote)) return;
      if(!(reference+start_distance*unit_value<tick.bid)) return;
      if(!(tick.bid<(position.tp-freeze_distance))) return;
      if(!(current_level<(unit_value*limit_distance+position.open_price))) return;
      Print("Slippage control active");
   }
   else
   {
      if(!(quote<((level-point)-offset))) return;
      if(!(tick.ask<(reference-start_distance*unit_value))) return;
      if(!((freeze_distance+position.tp)<tick.ask)) return;
      if(!((position.open_price-unit_value*limit_distance)<current_level)) return;
      Print("Slippage controle active"); // original spelling
   }
   changed=true;
   current_level=buy ? tick.bid-trail_distance*unit : trail_distance*unit+tick.ask;
}
#endif
