// Native buy 0x29a67/0x29e01..0x29ea9, sell 0x2d1b6/0x2d572..0x2d61a: timed virtual-stop move.
// One segment of the virtual-stop branch, not a management function. Verification is pending.
#ifndef BOT1_MANAGEMENT_TIMED_MQH
#define BOT1_MANAGEMENT_TIMED_MQH

struct Bot1TimedVirtualStopParams
{
   double activation;      // 0x624f8
   int delay_seconds;      // 0x6745c
   long opened;            // position.opened
   double distance;        // 0x62500
   double unit;            // 0x66d98
   double tp;              // position.tp
   double freeze_distance; // 0x67468
};

void Bot1AdvanceTimedVirtualStop(const bool buy,const string &symbol,
                                 const Bot1TimedVirtualStopParams &params,
                                 MqlTick &tick,double &current_level,bool &changed)
{
   if(!(0.0<params.activation)) return;
   long now=(long)TimeCurrent();
   if(now<params.opened+(long)params.delay_seconds) return;
   double level=current_level;
   double quote=buy ? tick.bid : tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double offset=params.distance*params.unit;
   if(buy)
   {
      if(!(level+point+offset<quote)) return;
      if(!(tick.bid<params.tp-params.freeze_distance)) return;
      changed=true;current_level=tick.bid-offset;
   }
   else
   {
      if(!(quote<(level-point)-offset)) return;
      if(!(params.freeze_distance+params.tp<tick.ask)) return;
      changed=true;current_level=offset+tick.ask;
   }
}
#endif
