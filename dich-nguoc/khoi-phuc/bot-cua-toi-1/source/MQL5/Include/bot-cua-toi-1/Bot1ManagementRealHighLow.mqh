// Candidate only: not compiled, not run, not compared with the original EX5.
// Real high/low stop move and SLTP modify only; levels come from the caller.
// Every < test is written !(a<b) so a NaN operand fails it.
#ifndef BOT1_MANAGEMENT_REAL_HIGH_LOW_MQH
#define BOT1_MANAGEMENT_REAL_HIGH_LOW_MQH
#include "Bot1ManagementPrelude.mqh"
#include "Bot1ManagementMessages.mqh"

// Reads GetLastError once and never resets it; Bot1TradeErrorText increments counter.
void Bot1PrintHighLowError(uint &counter)
{
   int code=GetLastError();
   string message=Bot1TradeErrorText(code,counter);
   Print("error: '"+message+"' when modifying stoploss");
}

void Bot1AdvanceHighLowRealBuyStop(const string &symbol,const int &enabled,const uchar eligible_flag,
                                   const int &gap_count,const double &unit,const uchar &before_open,
                                   const uchar &shift_setting,const double &gap,const double &freeze,
                                   const double &levels[],const uint &strategy_index,
                                   Bot1ManagedPosition &position,MqlTick &tick,bool &changed,
                                   Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                   uint &error_count,const ulong ticket)
{
   if(enabled<=0 || eligible_flag==0) return;
   // level1 is read before the digits query, gate_base before the point query.
   double level1=levels[strategy_index];
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double gate_base=gap+position.sl;
   double point1=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double gate=Bot1RoundPrice(gate_base+point1,digits1);
   if(!(gate<level1)) return;
   double quote=tick.bid;
   double level2=levels[strategy_index];
   double count=(double)gap_count;
   double captured_unit=unit;
   if(!(level2<quote-count*captured_unit)) return;
   // Only the low before_open bit enables this exit; with it clear, a failed or NaN test continues.
   if(!(level2<position.open_price) && (before_open&1)!=0) return;
   // shift_setting, bid, unit and gap are read fresh between DIGITS and POINT; level2 is kept.
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double shift=shift_setting!=0 ? 10.0 : 0.0;
   double boundary_base=(tick.bid-shift*unit)-gap;
   double point2=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double boundary=Bot1RoundPrice(boundary_base-point2,digits2);
   if(!(level2<boundary)) return;
   if(!(tick.bid<position.tp-freeze)) return;
   uint digits3=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot1RoundPrice(levels[strategy_index],digits3);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!(new_sl<tick.bid-gap)) return;
   // changed keeps the caller's value on every exit above; it is set before ok is checked.
   bool ok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
   if(!ok) Bot1PrintHighLowError(error_count);
}

void Bot1AdvanceHighLowRealSellStop(const string &symbol,const int &enabled,const uchar eligible_flag,
                                    const int &gap_count,const double &unit,const uchar &before_open,
                                    const uchar &shift_setting,const double &gap,const double &freeze,
                                    const double &levels[],const uint &strategy_index,
                                    Bot1ManagedPosition &position,MqlTick &tick,bool &changed,
                                    Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                    uint &error_count,const ulong ticket)
{
   if(enabled<=0 || eligible_flag==0) return;
   // No digits query or rounding before the freeze test; level1 and gate_base precede POINT.
   double level1=levels[strategy_index];
   double gate_base=position.sl-gap;
   double point1=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(level1<gate_base-point1)) return;
   double captured_unit=unit;
   double level2=levels[strategy_index];
   double quote=tick.ask;
   if(!(((double)gap_count*captured_unit+quote)<level2)) return;
   // Only the low before_open bit enables this exit; with it clear, a failed or NaN test continues.
   if(!(position.open_price<level2) && (before_open&1)!=0) return;
   // shift_setting and gap are read fresh before POINT; quote, captured_unit and level2 are kept.
   double shift=shift_setting!=0 ? 10.0 : 0.0;
   double boundary_base=(quote+captured_unit*shift)+gap;
   double point2=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!((boundary_base+point2)<level2)) return;
   if(!((freeze+position.tp)<tick.ask)) return;
   // candidate and new_sl each read strategy_index and levels again after their DIGITS query.
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot1RoundPrice(levels[strategy_index],digits1);
   if(!(candidate<position.sl)) return;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot1RoundPrice(levels[strategy_index],digits2);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!((tick.ask+gap)<new_sl)) return;
   // changed keeps the caller's value on every exit above; it is set before ok is checked.
   bool ok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
   if(!ok) Bot1PrintHighLowError(error_count);
}
#endif
