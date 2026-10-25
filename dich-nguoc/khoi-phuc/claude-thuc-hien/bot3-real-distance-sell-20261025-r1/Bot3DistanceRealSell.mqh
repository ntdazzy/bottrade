// Candidate only: not compiled, not run, not compared with the original EX5.
// Sell distance-trailing real stop with its post-modify close check; full manager and EA remain separate.
#ifndef BOT3_DISTANCE_REAL_SELL_MQH
#define BOT3_DISTANCE_REAL_SELL_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementMessages.mqh"

bool Bot3AdvanceDistanceSellStop(const string &symbol,const double &unit,const double &trail,
                                 const double &step,const double &start,const double &limit,
                                 const double anchor,const double &gap,const double &freeze,
                                 Bot3ManagedPosition &position,MqlTick &tick,
                                 const double &volumes[],const uint &strategy_index,bool &changed,
                                 Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                 const ulong &deviation,uint &error_count,const ulong ticket)
{
   if(!(0.0<trail)) return false;
   double quote=tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   // Captured once after POINT for gate, boundary and cap; the rounded formulas reread unit.
   double captured_unit=unit;
   double gate=(position.sl-point)-(trail+step)*captured_unit;
   if(!(quote<gate)) return false;
   quote=tick.ask;
   double boundary=anchor-start*captured_unit;
   if(!(quote<boundary)) return false;
   if(!((freeze+position.tp)<quote)) return false;
   double cap=position.open_price-captured_unit*limit;
   if(!(cap<position.sl)) return false;
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot3RoundPrice(trail*unit+tick.ask,digits);
   if(!(candidate<position.sl)) return false;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   quote=tick.ask;
   candidate=Bot3RoundPrice(trail*unit+quote,digits);
   // Written before the gap test and kept when that test fails.
   position.sl=candidate;
   if(!((quote+gap)<candidate)) return false;
   // changed keeps the caller's value on every exit above; every exit below sets it.
   if(!Bot3ModifyPosition(state,options,ticket,position.sl,position.tp))
   {
      string suffix="' when setting trailing Exit_stop_ loss.  Trying again!";
      Bot3PrintManagementError(suffix,error_count);
      changed=true;
      return false;
   }
   // Kept as a product: Inf or NaN volumes give NaN here, not 0.0.
   double zero_volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2);
   changed=true;
   if(!(zero_volume<position.volume)) return false;
   double minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
   if(!(minimum<=zero_volume)) return false;
   // No tick refresh before the close attempt; reaching it is the only true exit.
   Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket);
   return true;
}
#endif
