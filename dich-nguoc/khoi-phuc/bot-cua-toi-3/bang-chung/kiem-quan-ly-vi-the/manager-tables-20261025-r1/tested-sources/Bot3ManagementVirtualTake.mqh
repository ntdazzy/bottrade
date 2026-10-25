// Reconstructed segment only; full management and EA are elsewhere.
#ifndef BOT3_MANAGEMENT_VIRTUAL_TAKE_MQH
#define BOT3_MANAGEMENT_VIRTUAL_TAKE_MQH
#include "Bot3ManagementPrelude.mqh"

// Native buy 0x36189..0x364e2; sell 0x3a4af..0x3a803.
// current_take is 0x724a0. Both original new-price formulas use tick.bid.
bool Bot3AdvanceVirtualTake(const bool buy,const string &symbol,const double &unit,
                            const double &distance,const double &start_distance,const double anchor,
                            const Bot3ManagedPosition &position,MqlTick &tick,
                            const double &volumes[],const uint &strategy_index,
                            double &current_take,bool &changed,
                            Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                            const ulong &deviation,const double &threshold_a,const double &threshold_b,
                            const ulong ticket)
{
   if(!(0.0<distance) || !(0.0<current_take)) return false;
   double quote=buy ? tick.ask : tick.bid;
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double take=current_take;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double gate=buy ? (take-point)-distance*unit : distance*unit+(take+point);
   gate=Bot3RoundPrice(gate,digits);
   if(!(buy ? quote<gate : gate<quote)) return false;
   quote=buy ? tick.ask : tick.bid;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double boundary=buy ? anchor-start_distance*unit : start_distance*unit+anchor;
   boundary=Bot3RoundPrice(boundary,digits);
   if(!(buy ? quote<boundary : boundary<quote)) return false;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double level=buy ? distance*unit+tick.bid : tick.bid-distance*unit;
   current_take=Bot3RoundPrice(level,digits);
   double volume=Bot3RoundPrice(volumes[strategy_index]*0.0,2);
   changed=true;
   if(!(volume<position.volume)) return false;
   double minimum=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
   if(!(minimum<=volume)) return false;
   Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,threshold_a,threshold_b,ticket);
   return true;
}
#endif
