// Candidate only: not compiled, not run, not compared with the original EX5.
// Real trailing take-profit for buy positions; full manager and EA remain separate.
#ifndef BOT3_REAL_TAKE_BUY_MQH
#define BOT3_REAL_TAKE_BUY_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementMessages.mqh"

bool Bot3AdvanceRealTakeBuy(const string &symbol,const double &unit,const double &distance,
                            const double &start,const double anchor,const double &gap,
                            const double &freeze,Bot3ManagedPosition &position,MqlTick &tick,
                            const double &volumes[],const uint &strategy_index,bool &changed,
                            Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                            const ulong &deviation,uint &error_count,const ulong ticket)
{
   if(!(0.0<distance)) return false;
   // quote and quote2 are taken before their digits query; the last gate rereads tick.ask.
   double quote=tick.ask;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double gate=Bot3RoundPrice((position.tp-point)-distance*unit,digits1);
   if(!(quote<gate)) return false;
   double quote2=tick.ask;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double boundary=Bot3RoundPrice(anchor-start*unit,digits2);
   if(!(quote2<boundary)) return false;
   // position.tp is still the caller's value at this gate.
   if(!(tick.bid<position.tp-freeze)) return false;
   uint digits3=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_tp=Bot3RoundPrice(distance*unit+tick.bid,digits3);
   // Written before the gap test and kept when that test fails.
   position.tp=new_tp;
   if(!(tick.ask+gap<new_tp)) return false;
   // changed keeps the caller's value on every exit above; every exit below sets it.
   if(!Bot3ModifyPosition(state,options,ticket,position.sl,position.tp))
   {
      string suffix="' when setting trailing Exit_TP.  Trying again!";
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
