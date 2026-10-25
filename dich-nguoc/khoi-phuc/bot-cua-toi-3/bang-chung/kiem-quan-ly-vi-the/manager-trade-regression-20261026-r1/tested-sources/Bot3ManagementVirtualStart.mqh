// Reconstructed virtual-start segment; verification scope is recorded separately.
// Native segments in 0x32f60/0x37590: buy 0x35d65..0x35f8f, sell 0x39ff5..0x3a21a.
// Start of the virtual branch only; the virtual take update and outer managers are elsewhere.
#ifndef BOT3_MANAGEMENT_VIRTUAL_START_MQH
#define BOT3_MANAGEMENT_VIRTUAL_START_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3VirtualStops.mqh"

// current_stop 0x6d670, current_take 0x724a0, unit 0x73dd8, stop_distance 0x6d588,
// delay_seconds 0x6d518 (not 0x7449c); initial_stop/initial_take are xmm10/xmm9.
// Ordered compares: NaN makes every positive condition false.
// true only on close target 0x36fd4/0x3b1c7: tick refresh, helper 0x47d20 (not 0x2e370).
bool Bot3StartVirtualManagement(const bool buy,const string &symbol,const double &unit,
                                const double &stop_distance,const int &delay_seconds,const long ticket,
                                Bot3ManagedPosition &position,MqlTick &tick,
                                Bot3VirtualStopState &table,long &open_tickets[],
                                double &initial_stop,double &initial_take,
                                double &current_stop,double &current_take,
                                Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                const ulong &deviation,const double &threshold_a,
                                const double &threshold_b)
{
   initial_stop=Bot3VirtualStopLevel(table,open_tickets,symbol,unit,buy ? 1 : 2,
                                     position.open_price,stop_distance,ticket);
   current_stop=initial_stop;
   initial_take=Bot3VirtualTakeLevel(table,open_tickets,position.tp,ticket);
   current_take=initial_take;
   bool hit=buy ? (current_stop>=tick.bid || (0.0<initial_take && tick.bid>=initial_take))
                : (tick.ask>=current_stop || (0.0<initial_take && initial_take>=tick.ask));
   if(hit)
   {
      SymbolInfoTick(symbol,tick);
      Bot3TryClosePosition(state,options,deviation,tick.bid,tick.ask,threshold_a,threshold_b,
                           (ulong)ticket);
      return true;
   }
   if(!Bot3VirtualStopDelayPassed(table,delay_seconds,ticket)) return false;
   uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot3RoundPrice(current_stop,digits);
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(buy ? position.sl+point<candidate : candidate<position.sl-point)) return false;
   digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   position.sl=Bot3RoundPrice(current_stop,digits);
   Bot3ModifyPosition(state,options,(ulong)ticket,position.sl,position.tp);
   Bot3VirtualStopStamp(table,ticket);
   return false;
}
#endif
