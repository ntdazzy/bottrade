// Real take-profit trailing for sell positions and post-modify close check only.
// Candidate only: not compiled, not run, not compared with the original EX5.
#ifndef BOT3_REAL_TAKE_SELL_MQH
#define BOT3_REAL_TAKE_SELL_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementMessages.mqh"

bool Bot3AdvanceRealTakeSell(const string &symbol,const double &unit,const double &distance,
                             const double &start,const double anchor,const double &gap,
                             const double &freeze,Bot3ManagedPosition &position,MqlTick &tick,
                             const double &volumes[],const uint &strategy_index,bool &changed,
                             Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                             const ulong &deviation,uint &error_count,const ulong ticket)
{
   if(!(0.0<distance)) return false;
   // Bid on every sell gate; quote/quote2 precede their digits query, quote3 follows it.
   double quote=tick.bid;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double gate=Bot3RoundPrice(distance*unit+(point+position.tp),digits1);
   if(!(gate<quote)) return false;
   double quote2=tick.bid;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double boundary=Bot3RoundPrice(start*unit+anchor,digits2);
   if(!(boundary<quote2)) return false;
   if(!((freeze+position.tp)<tick.bid)) return false;
   uint digits3=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double quote3=tick.bid;
   double new_tp=Bot3RoundPrice(quote3-distance*unit,digits3);
   // Written before the gap test and kept when that test fails.
   position.tp=new_tp;
   if(!(new_tp<quote3-gap)) return false;
   // changed keeps the caller's value on every exit above; every exit below sets it.
   if(!Bot3ModifyPosition(state,options,ticket,position.sl,position.tp))
   {
      string suffix="' when setting trailing Exit_TP.  Trying again!";
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
