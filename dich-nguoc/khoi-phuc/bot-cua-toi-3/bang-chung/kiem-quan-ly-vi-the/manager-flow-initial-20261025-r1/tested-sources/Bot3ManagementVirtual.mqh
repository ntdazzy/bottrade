// Reconstructed virtual-management segments only; not complete managers or EA.
// Validation scope is recorded under kiem-quan-ly-vi-the.
#ifndef BOT3_MANAGEMENT_VIRTUAL_MQH
#define BOT3_MANAGEMENT_VIRTUAL_MQH
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
