// Candidate only: not compiled, not run, not compared with the original EX5.
// Real lock (breakeven) SL step for buy and sell; no TP change, close, volume, panel or Stamp.
#ifndef BOT3_MANAGEMENT_REAL_LOCK_MQH
#define BOT3_MANAGEMENT_REAL_LOCK_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementMessages.mqh"

// Reads GetLastError once and never resets it; Bot3TradeErrorText increments counter.
void Bot3PrintRealLockError(uint &counter)
{
   int code=(int)GetLastError();
   string msg=Bot3TradeErrorText(code,counter);
   Print("error when setting breakeven: '"+msg+
         "' ..'Exit_BE_start_' to close to 'Exit_BE_extra_pips_' ..trying again!");
}

// Both functions: no mode check; every gate is an ordered comparison, so NaN fails it.
// changed keeps the caller's value on every exit before the modify; a written sl stays
// when the last gate fails.
void Bot3AdvanceRealLockBuyStop(const string &symbol,const double &start,const double &extra,
                                const double &unit,const double &gap,const double &freeze,
                                Bot3ManagedPosition &position,MqlTick &tick,bool &changed,
                                Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                uint &error_count,const ulong ticket)
{
   if(!(0.0<start)) return;
   // bid is taken before the digits query; start and unit are read after it.
   double quote1=tick.bid;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double gate1=Bot3RoundPrice(start*unit+position.open_price,digits1);
   if(!(gate1<quote1)) return;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   // Rounded before the point query; this gate does not read extra or unit again.
   double candidate=Bot3RoundPrice(extra*unit+position.open_price,digits2);
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(point+position.sl<candidate)) return;
   // bid is taken again before the digits query; extra, unit and gap are read after it.
   double quote2=tick.bid;
   uint digits3=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double gate2=Bot3RoundPrice((extra*unit+position.open_price)+gap,digits3);
   if(!(gate2<quote2)) return;
   if(!(tick.bid<position.tp-freeze)) return;
   uint digits4=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot3RoundPrice(extra*unit+position.open_price,digits4);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!(new_sl<tick.bid-gap)) return;
   bool ok=Bot3ModifyPosition(state,options,ticket,position.sl,position.tp);
   // Set right after the modify, before its result is checked.
   changed=true;
   if(!ok) Bot3PrintRealLockError(error_count);
}

void Bot3AdvanceRealLockSellStop(const string &symbol,const double &start,const double &extra,
                                 const double &unit,const double &gap,const double &freeze,
                                 Bot3ManagedPosition &position,MqlTick &tick,bool &changed,
                                 Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                 uint &error_count,const ulong ticket)
{
   if(!(0.0<start)) return;
   // unit is captured once for the trigger and the point gate; neither is rounded.
   double captured_unit=unit;
   double trigger=position.open_price-start*captured_unit;
   if(!(tick.ask<trigger)) return;
   double candidate=position.open_price-captured_unit*extra;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(candidate<position.sl-point)) return;
   // extra, unit and ask are read again after the point query; one quote serves both gates.
   double offset=extra*unit;
   double quote=tick.ask;
   if(!(quote<(position.open_price-offset)-gap)) return;
   if(!(freeze+position.tp<quote)) return;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double gate=Bot3RoundPrice(position.open_price-extra*unit,digits1);
   // Compared with the sl from the caller; nothing is written yet.
   if(!(gate<position.sl)) return;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot3RoundPrice(position.open_price-extra*unit,digits2);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!(tick.ask+gap<new_sl)) return;
   bool ok=Bot3ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
   if(!ok) Bot3PrintRealLockError(error_count);
}
#endif
