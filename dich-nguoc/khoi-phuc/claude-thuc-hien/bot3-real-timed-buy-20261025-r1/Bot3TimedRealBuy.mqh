// Reconstructed timed real-stop segment for buy positions, written from the fixed spec.
// Segment only: outer manager, sell side and EA are elsewhere.
#ifndef BOT3_TIMED_REAL_BUY_MQH
#define BOT3_TIMED_REAL_BUY_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementMessages.mqh"

// Ordered compares: NaN makes every positive condition false.
// position.sl is set before the gap check and kept when that check fails.
// true only once the modify request is reached, whatever Bot3ModifyPosition returns.
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
#endif
