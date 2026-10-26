// Real distance-stop move, SLTP modify and close check only; full manager and EA remain separate.
// Every gate is written !(a<b) or !(a<=b) so a NaN operand fails it.
#ifndef BOT1_MANAGEMENT_REAL_DISTANCE_MQH
#define BOT1_MANAGEMENT_REAL_DISTANCE_MQH
#include "Bot1ManagementPrelude.mqh"
#include "Bot1ManagementMessages.mqh"

bool Bot1AdvanceDistanceBuyStop(const string &symbol,const double &unit,const double &trail,
                                const double &step,const double &start,const double &limit,
                                const double anchor,const double &gap,const double &freeze,
                                Bot1ManagedPosition &position,MqlTick &tick,
                                const double &volumes[],const uint &strategy_index,bool &changed,
                                Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                const ulong &deviation,uint &error_count,const ulong ticket)
{
   if(!(0.0<trail)) return false;
   // quote and quote2 are taken before their digits query, quote3 after it.
   double quote=tick.bid;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double gate=Bot1RoundPrice((trail+step)*unit+(point+position.sl),digits1);
   if(!(gate<quote)) return false;
   double quote2=tick.bid;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double boundary=Bot1RoundPrice(start*unit+anchor,digits2);
   if(!(boundary<quote2)) return false;
   if(!(tick.bid<position.tp-freeze)) return false;
   uint digits3=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double cap=Bot1RoundPrice(limit*unit+position.open_price,digits3);
   if(!(position.sl<cap)) return false;
   uint digits4=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double quote3=tick.bid;
   double new_sl=Bot1RoundPrice(quote3-trail*unit,digits4);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!(new_sl<quote3-gap)) return false;
   // changed keeps the caller's value on every exit above; every exit below sets it.
   bool ok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp);
   if(!ok)
   {
      string suffix="' when setting trailing Exit_stop_ loss.  Trying again!";
      Bot1PrintManagementError(suffix,error_count);
      changed=true;
      return false;
   }
   // Kept as a product: an Inf or NaN volume gives NaN here, not 0.0.
   double zero_volume=Bot1RoundPrice(volumes[strategy_index]*0.0,2);
   changed=true;
   if(!(zero_volume<position.volume)) return false;
   double minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
   if(!(minimum<=zero_volume)) return false;
   // The passed tick is not refreshed; true only once the close attempt is reached.
   Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket);
   return true;
}

bool Bot1AdvanceDistanceSellStop(const string &symbol,const double &unit,const double &trail,
                                 const double &step,const double &start,const double &limit,
                                 const double anchor,const double &gap,const double &freeze,
                                 Bot1ManagedPosition &position,MqlTick &tick,
                                 const double &volumes[],const uint &strategy_index,bool &changed,
                                 Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                 const ulong &deviation,uint &error_count,const ulong ticket)
{
   if(!(0.0<trail)) return false;
   // No digits query before POINT; unit is captured once after it for gate, boundary and cap.
   double quote=tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double captured_unit=unit;
   double gate=(position.sl-point)-(trail+step)*captured_unit;
   if(!(quote<gate)) return false;
   quote=tick.ask;
   double boundary=anchor-start*captured_unit;
   if(!(quote<boundary)) return false;
   if(!((freeze+position.tp)<quote)) return false;
   double cap=position.open_price-captured_unit*limit;
   if(!(cap<position.sl)) return false;
   // Both rounded candidates read unit again instead of captured_unit.
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot1RoundPrice(trail*unit+tick.ask,digits1);
   if(!(candidate<position.sl)) return false;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   quote=tick.ask;
   candidate=Bot1RoundPrice(trail*unit+quote,digits2);
   // Written before the gap test and kept when that test fails.
   position.sl=candidate;
   if(!((quote+gap)<candidate)) return false;
   // changed keeps the caller's value on every exit above; every exit below sets it.
   bool ok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp);
   if(!ok)
   {
      string suffix="' when setting trailing Exit_stop_ loss.  Trying again!";
      Bot1PrintManagementError(suffix,error_count);
      changed=true;
      return false;
   }
   // Kept as a product: an Inf or NaN volume gives NaN here, not 0.0.
   double zero_volume=Bot1RoundPrice(volumes[strategy_index]*0.0,2);
   changed=true;
   if(!(zero_volume<position.volume)) return false;
   double minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
   if(!(minimum<=zero_volume)) return false;
   // The passed tick is not refreshed; true only once the close attempt is reached.
   Bot1TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket);
   return true;
}
#endif
