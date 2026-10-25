// Candidate only: not compiled, not run, not compared with the original EX5.
// Real (non-virtual) timed trailing stop, sell side; the buy side reads and rounds differently.
#ifndef BOT3_TIMED_REAL_SELL_MQH
#define BOT3_TIMED_REAL_SELL_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementMessages.mqh"

// true once the modify request is reached, whatever its result; every earlier exit is false.
// Ordered compares: NaN makes every positive condition false.
bool Bot3AdvanceTimedSellStop(const string &symbol,const double &unit,const double &activation,
                              const double &distance,const int &delay_seconds,const double &gap,
                              const double &freeze,Bot3ManagedPosition &position,MqlTick &tick,
                              Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                              uint &error_count,const ulong ticket)
{
   if(!(0.0<activation)) return false;
   long now=(long)TimeCurrent();
   long delay=(long)delay_seconds;
   // 64-bit wrapping add through ulong, then a signed compare.
   long deadline=(long)((ulong)position.opened+(ulong)delay);
   if(now<deadline) return false;
   double quote=tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   // Sell gate: no digits query before POINT and no rounding.
   double offset=distance*unit;
   double gate=(position.sl-point)-offset;
   if(!(quote<gate)) return false;
   if(!((freeze+position.tp)<tick.ask)) return false;
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot3RoundPrice(distance*unit+tick.ask,digits);
   if(!(candidate<position.sl)) return false;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   quote=tick.ask;
   candidate=Bot3RoundPrice(distance*unit+quote,digits);
   // Written before the gap test and kept when that test fails.
   position.sl=candidate;
   if(!((quote+gap)<candidate)) return false;
   if(!Bot3ModifyPosition(state,options,ticket,position.sl,position.tp))
      Bot3PrintManagementError("' when setting trailing Exit_TrailSL_after_X_Minutes_size_ loss.  Trying again!",
                               error_count);
   return true;
}
#endif
