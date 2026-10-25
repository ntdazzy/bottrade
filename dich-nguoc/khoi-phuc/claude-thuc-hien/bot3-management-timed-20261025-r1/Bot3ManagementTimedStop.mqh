// Candidate only: not compiled, not run, not compared with the original EX5.
// Part A of native 0x32f60 (buy 0x35f8f..0x35fd3, body 0x3667f..0x36727) and 0x37590
// (sell 0x3a21a..0x3a2f7); a segment only. Settings: activation 0x6d5e8, distance 0x6d5f0,
// delay_seconds int32 0x7449c, freeze_distance 0x744a8. Ordered < checks: NaN changes nothing.
#ifndef BOT3_MANAGEMENT_TIMED_STOP_MQH
#define BOT3_MANAGEMENT_TIMED_STOP_MQH
#include "Bot3ManagementPrelude.mqh"

void Bot3AdvanceTimedVirtualStop(const bool buy,const string &symbol,const double &unit,
                                 const double &activation,const double &distance,
                                 const int &delay_seconds,const double &freeze_distance,
                                 const Bot3ManagedPosition &position,MqlTick &tick,
                                 double &current_level,bool &changed)
{
   if(!(0.0<activation)) return;
   long now=(long)TimeCurrent();
   if(now<position.opened+(long)delay_seconds) return;
   double level=current_level;
   double quote=buy ? tick.bid : tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double offset=distance*unit;
   if(!(buy ? ((level+point)+offset)<quote
            : quote<((level-point)-offset))) return;
   if(!(buy ? tick.bid<(position.tp-freeze_distance)
            : (freeze_distance+position.tp)<tick.ask)) return;
   changed=true;
   current_level=buy ? tick.bid-offset : offset+tick.ask;
}
#endif
