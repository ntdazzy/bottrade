// Candidate only: not compiled, not run, not compared with the original EX5.
// Real breakeven (profit lock) stop move and SLTP modify only; full manager and EA remain separate.
// Every gate is written !(a<b) so a NaN operand fails it.
#ifndef BOT1_MANAGEMENT_REAL_LOCK_MQH
#define BOT1_MANAGEMENT_REAL_LOCK_MQH
#include "Bot1ManagementPrelude.mqh"
#include "Bot1ManagementMessages.mqh"

// Reads GetLastError once and never resets it; Bot1TradeErrorText increments counter.
void Bot1PrintRealLockError(uint &counter)
{
   int code=(int)GetLastError();
   string msg=Bot1TradeErrorText(code,counter);
   Print("error when setting breakeven: '"+msg+"' ..'Exit_BE_start_' to close to 'Exit_BE_extra_pips_' ..trying again!");
}

void Bot1AdvanceRealLockBuyStop(const string &symbol,const double &start,const double &extra,
                                const double &unit,const double &gap,const double &freeze,
                                Bot1ManagedPosition &position,MqlTick &tick,bool &changed,
                                Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                uint &error_count,const ulong ticket)
{
   if(!(0.0<start)) return;
   // quote1 and quote2 are taken before their digits query; each level reads the refs again.
   double quote1=tick.bid;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double gate1=Bot1RoundPrice(start*unit+position.open_price,digits1);
   if(!(gate1<quote1)) return;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot1RoundPrice(extra*unit+position.open_price,digits2);
   // POINT is queried after the rounding; candidate is not recomputed after it.
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!((point+position.sl)<candidate)) return;
   double quote2=tick.bid;
   uint digits3=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double gate2=Bot1RoundPrice((extra*unit+position.open_price)+gap,digits3);
   if(!(gate2<quote2)) return;
   if(!(tick.bid<position.tp-freeze)) return;
   uint digits4=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot1RoundPrice(extra*unit+position.open_price,digits4);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!(new_sl<tick.bid-gap)) return;
   // changed keeps the caller's value on every exit above; it is set before ok is tested.
   bool ok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
   if(!ok) Bot1PrintRealLockError(error_count);
}

void Bot1AdvanceRealLockSellStop(const string &symbol,const double &start,const double &extra,
                                 const double &unit,const double &gap,const double &freeze,
                                 Bot1ManagedPosition &position,MqlTick &tick,bool &changed,
                                 Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                 uint &error_count,const ulong ticket)
{
   if(!(0.0<start)) return;
   // unit is captured once for trigger and candidate; neither is rounded.
   double captured_unit=unit;
   double trigger=position.open_price-start*captured_unit;
   if(!(tick.ask<trigger)) return;
   double candidate=position.open_price-captured_unit*extra;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(candidate<position.sl-point)) return;
   // extra, unit and ask are read again after POINT; the freeze gate reuses this quote.
   double offset=extra*unit;
   double quote=tick.ask;
   if(!(quote<(position.open_price-offset)-gap)) return;
   if(!((freeze+position.tp)<quote)) return;
   // Both rounded levels read extra and unit again; the first one does not write sl.
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double gate=Bot1RoundPrice(position.open_price-extra*unit,digits1);
   if(!(gate<position.sl)) return;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot1RoundPrice(position.open_price-extra*unit,digits2);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!((tick.ask+gap)<new_sl)) return;
   // changed keeps the caller's value on every exit above; it is set before ok is tested.
   bool ok=Bot1ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
   if(!ok) Bot1PrintRealLockError(error_count);
}
#endif
