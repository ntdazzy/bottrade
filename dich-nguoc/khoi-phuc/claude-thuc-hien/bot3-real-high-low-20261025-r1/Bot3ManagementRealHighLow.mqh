// Candidate only: not compiled, not run, not compared with the original EX5.
// Real high/low SL step for buy and sell; no TP change, close, volume, panel or Stamp.
#ifndef BOT3_MANAGEMENT_REAL_HIGH_LOW_MQH
#define BOT3_MANAGEMENT_REAL_HIGH_LOW_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementMessages.mqh"

// Reads GetLastError once and never resets it; Bot3TradeErrorText increments counter.
void Bot3PrintHighLowError(uint &counter)
{
   int code=(int)GetLastError();
   string message=Bot3TradeErrorText(code,counter);
   Print("error: '"+message+"' when modifying stoploss");
}

// Both functions: every gate is an ordered comparison, so NaN fails it. changed keeps the
// caller's value on every exit before the modify; a written sl stays when the last gate fails.
void Bot3AdvanceHighLowRealBuyStop(const string &symbol,const int &enabled,
                                   const uchar eligible_flag,const int &gap_count,
                                   const double &unit,const uchar &before_open,
                                   const uchar &shift_setting,const double &gap,
                                   const double &freeze,const double &levels[],
                                   const uint &strategy_index,Bot3ManagedPosition &position,
                                   MqlTick &tick,bool &changed,Bot3PendingRequestState &state,
                                   Bot3TradeSendOptions &options,uint &error_count,
                                   const ulong ticket)
{
   if(enabled<=0 || eligible_flag==0) return;
   // level1 is taken before the digits query, the gap+sl sum before the point query.
   double level1=levels[strategy_index];
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double gate_base=gap+position.sl;
   double point1=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double gate=Bot3RoundPrice(gate_base+point1,digits1);
   if(!(gate<level1)) return;
   // level2 is read after POINT and kept across the next DIGITS and POINT queries.
   double level2=levels[strategy_index];
   double quote=tick.bid;
   double count=(double)gap_count;
   double captured_unit=unit;
   if(!(level2<quote-count*captured_unit)) return;
   if(!(level2<position.open_price) && (before_open&1)!=0) return;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   // shift, bid, unit and gap are read after the digits query, before the point query.
   double shift=shift_setting!=0 ? 10.0 : 0.0;
   double boundary_base=(tick.bid-shift*unit)-gap;
   double point2=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double boundary=Bot3RoundPrice(boundary_base-point2,digits2);
   if(!(level2<boundary)) return;
   if(!(tick.bid<position.tp-freeze)) return;
   uint digits3=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot3RoundPrice(levels[strategy_index],digits3);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!(new_sl<tick.bid-gap)) return;
   bool ok=Bot3ModifyPosition(state,options,ticket,position.sl,position.tp);
   // Set right after the modify, before its result is checked.
   changed=true;
   if(!ok) Bot3PrintHighLowError(error_count);
}

void Bot3AdvanceHighLowRealSellStop(const string &symbol,const int &enabled,
                                    const uchar eligible_flag,const int &gap_count,
                                    const double &unit,const uchar &before_open,
                                    const uchar &shift_setting,const double &gap,
                                    const double &freeze,const double &levels[],
                                    const uint &strategy_index,Bot3ManagedPosition &position,
                                    MqlTick &tick,bool &changed,Bot3PendingRequestState &state,
                                    Bot3TradeSendOptions &options,uint &error_count,
                                    const ulong ticket)
{
   if(enabled<=0 || eligible_flag==0) return;
   // No digits query or rounding in the first gate.
   double level1=levels[strategy_index];
   double gate_base=position.sl-gap;
   double point1=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(level1<gate_base-point1)) return;
   // unit, level2 and ask are captured once after POINT and reused up to the POINT2 gate.
   double captured_unit=unit;
   double level2=levels[strategy_index];
   double quote=tick.ask;
   if(!(((double)gap_count*captured_unit+quote)<level2)) return;
   if(!(position.open_price<level2) && (before_open&1)!=0) return;
   double shift=shift_setting!=0 ? 10.0 : 0.0;
   double boundary_base=(quote+captured_unit*shift)+gap;
   double point2=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!((boundary_base+point2)<level2)) return;
   if(!((freeze+position.tp)<tick.ask)) return;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot3RoundPrice(levels[strategy_index],digits1);
   // Compared with the sl from the caller; nothing is written yet.
   if(!(candidate<position.sl)) return;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot3RoundPrice(levels[strategy_index],digits2);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!((tick.ask+gap)<new_sl)) return;
   bool ok=Bot3ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
   if(!ok) Bot3PrintHighLowError(error_count);
}
#endif
