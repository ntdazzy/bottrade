// Candidate only: not compiled, not run, not compared with the original EX5.
// Real distance-trailing stop for buy positions; full manager and EA remain separate.
#ifndef BOT3_DISTANCE_REAL_BUY_MQH
#define BOT3_DISTANCE_REAL_BUY_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementMessages.mqh"

bool Bot3AdvanceDistanceBuyStop(const string &symbol,const double &unit,const double &trail,
                                const double &step,const double &start,const double &limit,
                                const double anchor,const double &gap,const double &freeze,
                                Bot3ManagedPosition &position,MqlTick &tick,
                                const double &volumes[],const uint &strategy_index,bool &changed,
                                Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                const ulong &deviation,uint &error_count,const ulong ticket)
{
   if(!(0.0<trail)) return false;
   // quote and quote2 are taken before their digits query, quote3 after it.
   double quote=tick.bid;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double gate=Bot3RoundPrice((trail+step)*unit+(point+position.sl),digits1);
   if(!(gate<quote)) return false;
   double quote2=tick.bid;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double boundary=Bot3RoundPrice(start*unit+anchor,digits2);
   if(!(boundary<quote2)) return false;
   if(!(tick.bid<position.tp-freeze)) return false;
   uint digits3=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double cap=Bot3RoundPrice(limit*unit+position.open_price,digits3);
   if(!(position.sl<cap)) return false;
   uint digits4=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double quote3=tick.bid;
   double new_sl=Bot3RoundPrice(quote3-trail*unit,digits4);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!(new_sl<quote3-gap)) return false;
   bool ok=Bot3ModifyPosition(state,options,ticket,position.sl,position.tp);
   if(!ok)
   {
      string suffix="' when setting trailing Exit_stop_ loss.  Trying again!";
      Bot3PrintManagementError(suffix,error_count);
      changed=true;
      return false;
   }
   // Not folded to 0.0: an Inf or NaN volume makes the product NaN.
   double zero_volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2);
   changed=true;
   if(!(zero_volume<position.volume)) return false;
   double minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
   if(!(minimum<=zero_volume)) return false;
   // The passed tick is not refreshed; true only once the close attempt is reached.
   Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,gap,freeze,ticket);
   return true;
}
#endif
