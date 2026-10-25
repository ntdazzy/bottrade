// Real step-counter stop move and SLTP modify only; full manager and EA remain separate.
// Every gate is written !(a<b) so a NaN operand fails it.
#ifndef BOT1_MANAGEMENT_REAL_COUNTER_MQH
#define BOT1_MANAGEMENT_REAL_COUNTER_MQH
#include "Bot1ManagementPrelude.mqh"

void Bot1AdvanceRealCounterBuyStop(const string &symbol,const uchar &enabled,
                                   const double &reference_setting,const int &minimum_steps,
                                   const double &step_distance,const double &unit,
                                   const double &copied_step,const double selected_anchor,
                                   const double &gap,const double &freeze,int &counter,
                                   Bot1ManagedPosition &position,MqlTick &tick,bool &changed,
                                   Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                   const ulong ticket)
{
   if(changed) return;
   if(enabled!=1) return;
   // Wrapping 32-bit increment; kept when any later gate returns.
   counter=(int)((uint)counter+1);
   // No digits or point query in these gates; quote and u are reused by the anchor gate.
   double quote=tick.bid;
   double u=unit;
   double product=step_distance*u;
   if(!(((product+position.sl)+gap)<quote)) return;
   if(!(quote<position.tp-freeze)) return;
   // +0.0 and -0.0 skip the anchor gate; any other value, NaN included, applies it.
   if(reference_setting!=0.0)
   {
      double offset=u*copied_step;
      if(!(selected_anchor+offset<quote)) return;
   }
   if(counter<minimum_steps) return;
   // step_distance, unit and position.sl are read again after each digits query.
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot1RoundPrice(step_distance*unit+position.sl,digits1);
   if(!(position.sl<candidate)) return;
   // Reset before the second digits query; a value written during that query is kept.
   counter=0;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   // position.sl is the left operand here, unlike in the candidate above.
   double new_sl=Bot1RoundPrice(position.sl+step_distance*unit,digits2);
   position.sl=new_sl;
   // No gap test after the write; the modify result is ignored and changed is set even on failure.
   Bot1ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
}

void Bot1AdvanceRealCounterSellStop(const string &symbol,const uchar &enabled,
                                    const double &reference_setting,const int &minimum_steps,
                                    const double &step_distance,const double &unit,
                                    const double &copied_step,const double selected_anchor,
                                    const double &gap,const double &freeze,int &counter,
                                    Bot1ManagedPosition &position,MqlTick &tick,bool &changed,
                                    Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                                    const ulong ticket)
{
   if(changed) return;
   if(enabled!=1) return;
   // Wrapping 32-bit increment; kept when any later gate returns.
   counter=(int)((uint)counter+1);
   // No digits or point query in these gates; quote and u are reused by the anchor gate.
   double quote=tick.ask;
   double u=unit;
   double product=step_distance*u;
   if(!(quote<(position.sl-product)-gap)) return;
   if(!((freeze+position.tp)<quote)) return;
   // +0.0 and -0.0 skip the anchor gate; any other value, NaN included, applies it.
   if(reference_setting!=0.0)
   {
      double offset=u*copied_step;
      if(!(quote<selected_anchor-offset)) return;
   }
   if(counter<minimum_steps) return;
   // step_distance, unit and position.sl are read again after each digits query.
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot1RoundPrice(position.sl-step_distance*unit,digits1);
   if(!(candidate<position.sl)) return;
   // Reset before the second digits query; a value written during that query is kept.
   counter=0;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot1RoundPrice(position.sl-step_distance*unit,digits2);
   position.sl=new_sl;
   // No gap test after the write; the modify result is ignored and changed is set even on failure.
   Bot1ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
}
#endif
