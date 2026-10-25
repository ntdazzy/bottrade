// Candidate only: not compiled, not run, not compared with the original EX5.
// Real slippage-stop move and SLTP modify only; full manager and EA remain separate.
// Every gate is written !(a<b) so a NaN operand fails it.
#ifndef BOT1_MANAGEMENT_REAL_SLIPPAGE_MQH
#define BOT1_MANAGEMENT_REAL_SLIPPAGE_MQH
#include "Bot1ManagementPrelude.mqh"
#include "Bot1ManagementMessages.mqh"

void Bot1AdvanceSlippageRealBuyStop(const string &symbol,const double &unit,const int &enabled,
                                    const uchar passed_flag,const double reference,
                                    const double &trail,const double &start,const double &limit,
                                    const double &gap,const double &freeze,Bot1ManagedPosition &position,
                                    MqlTick &tick,bool &changed,Bot1PendingRequestState &state,
                                    Bot1TradeSendOptions &options,uint &error_count,const ulong ticket)
{
   if(enabled!=1 || (passed_flag&1)!=1 || !(0.0<trail)) return;
   // quote and quote2 are taken before their digits query, quote3 after it.
   double quote=tick.bid;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double gate=Bot1RoundPrice(trail*unit+(point+position.sl),digits1);
   if(!(gate<quote)) return;
   double quote2=tick.bid;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double boundary=Bot1RoundPrice(start*unit+reference,digits2);
   if(!(boundary<quote2)) return;
   if(!(tick.bid<position.tp-freeze)) return;
   uint digits3=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double limit_price=Bot1RoundPrice(limit*unit+position.open_price,digits3);
   if(!(position.sl<limit_price)) return;
   uint digits4=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double quote3=tick.bid;
   double new_sl=Bot1RoundPrice(quote3-trail*unit,digits4);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!(new_sl<quote3-gap)) return;
   // changed keeps the caller's value on every exit above; it is set after either message.
   if(Bot1ModifyPosition(state,options,ticket,position.sl,position.tp))
      Print("Slippage control active");
   else
      Bot1PrintManagementError("' when setting Slip TL.  Trying again!",error_count);
   changed=true;
}

void Bot1AdvanceSlippageRealSellStop(const string &symbol,const double &unit,const int &enabled,
                                     const uchar passed_flag,const double reference,
                                     const double &trail,const double &start,const double &limit,
                                     const double &gap,const double &freeze,Bot1ManagedPosition &position,
                                     MqlTick &tick,bool &changed,Bot1PendingRequestState &state,
                                     Bot1TradeSendOptions &options,uint &error_count,const ulong ticket)
{
   if(enabled!=1 || (passed_flag&1)!=1 || !(0.0<trail)) return;
   // No digits query before POINT; unit is captured once after it for gate, boundary and limit.
   double quote=tick.ask;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   double captured_unit=unit;
   double gate=(position.sl-point)-trail*captured_unit;
   if(!(quote<gate)) return;
   double quote2=tick.ask;
   double boundary=reference-start*captured_unit;
   if(!(quote2<boundary)) return;
   if(!((freeze+position.tp)<quote2)) return;
   double limit_price=position.open_price-captured_unit*limit;
   if(!(limit_price<position.sl)) return;
   // Both rounded candidates read unit again instead of captured_unit.
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot1RoundPrice(trail*unit+tick.ask,digits1);
   if(!(candidate<position.sl)) return;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double quote3=tick.ask;
   double new_sl=Bot1RoundPrice(trail*unit+quote3,digits2);
   // Written before the gap test and kept when that test fails.
   position.sl=new_sl;
   if(!((quote3+gap)<new_sl)) return;
   // changed keeps the caller's value on every exit above; it is set after either message.
   if(Bot1ModifyPosition(state,options,ticket,position.sl,position.tp))
      Print("Slippage controle active");
   else
      Bot1PrintManagementError("' when setting Slip TL.  Trying again!",error_count);
   changed=true;
}
#endif
