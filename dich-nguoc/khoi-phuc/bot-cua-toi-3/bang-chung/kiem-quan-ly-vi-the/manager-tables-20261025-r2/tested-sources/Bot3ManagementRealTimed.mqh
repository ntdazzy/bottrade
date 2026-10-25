// Timed real-stop calculation and modification only; full manager and EA remain separate.
#ifndef BOT3_MANAGEMENT_REAL_TIMED_MQH
#define BOT3_MANAGEMENT_REAL_TIMED_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementMessages.mqh"

bool Bot3AdvanceTimedBuyStop(const string &symbol,const double &unit,const double &activation,
                             const double &distance,const int &delay_seconds,const double &gap,
                             const double &freeze,Bot3ManagedPosition &position,MqlTick &tick,
                             Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                             uint &error_count,const ulong ticket)
{
   if(!(0.0<activation)) return false;
   long now=(long)TimeCurrent();
   long due=(long)((ulong)position.opened+(ulong)(long)delay_seconds); // wrapping 64-bit add
   if(now<due) return false;
   double quote=tick.bid;
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double gate=distance*unit+(point+position.sl);
   gate=Bot3RoundPrice(gate,digits);
   if(!(gate<quote)) return false;
   if(!(tick.bid<position.tp-freeze)) return false;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   quote=tick.bid;
   double candidate=Bot3RoundPrice(quote-distance*unit,digits);
   position.sl=candidate;
   if(!(candidate<quote-gap)) return false;
   if(!Bot3ModifyPosition(state,options,ticket,position.sl,position.tp))
   {
      string suffix="' when setting trailing Exit_TrailSL_after_X_Minutes_size_ loss.  Trying again!";
      Bot3PrintManagementError(suffix,error_count);
   }
   return true;
}

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
