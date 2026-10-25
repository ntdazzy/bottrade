// Counter-gated real-stop step and modification only; full manager and EA remain separate.
#ifndef BOT3_MANAGEMENT_REAL_COUNTER_MQH
#define BOT3_MANAGEMENT_REAL_COUNTER_MQH
#include "Bot3ManagementPrelude.mqh"

void Bot3AdvanceRealCounterBuyStop(const string &symbol,const uchar &enabled,
                                   const double &reference_setting,const int &minimum_steps,
                                   const double &step_distance,const double &unit,
                                   const double &copied_step,const double selected_anchor,
                                   const double &gap,const double &freeze,int &counter,
                                   Bot3ManagedPosition &position,MqlTick &tick,bool &changed,
                                   Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                   const ulong ticket)
{
   if(changed) return;
   if(enabled!=1) return;
   counter=(int)((uint)counter+1); // 32-bit wrap; kept when a later gate fails
   // Copies taken before any API call; the rounding steps re-read step_distance/unit.
   double quote=tick.bid;
   double u=unit;
   double product=step_distance*u;
   if(!((product+position.sl)+gap<quote)) return;
   if(!(quote<position.tp-freeze)) return;
   // +0/-0 skips the anchor gate; any other value, NaN included, applies it.
   if(reference_setting!=0.0)
   {
      double offset=u*copied_step;
      if(!(selected_anchor+offset<quote)) return;
   }
   if(counter<minimum_steps) return;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot3RoundPrice(step_distance*unit+position.sl,digits1);
   if(!(position.sl<candidate)) return;
   // Reset once before DIGITS2; a value written during that call is kept.
   counter=0;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot3RoundPrice(position.sl+step_distance*unit,digits2);
   position.sl=new_sl;
   // Result ignored: a failed modify keeps counter, new SL and changed=true.
   Bot3ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
}

// Sell mirror: ask quote, reversed gates, SL minus step in both roundings.
void Bot3AdvanceRealCounterSellStop(const string &symbol,const uchar &enabled,
                                    const double &reference_setting,const int &minimum_steps,
                                    const double &step_distance,const double &unit,
                                    const double &copied_step,const double selected_anchor,
                                    const double &gap,const double &freeze,int &counter,
                                    Bot3ManagedPosition &position,MqlTick &tick,bool &changed,
                                    Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                                    const ulong ticket)
{
   if(changed) return;
   if(enabled!=1) return;
   counter=(int)((uint)counter+1); // 32-bit wrap; kept when a later gate fails
   double quote=tick.ask;
   double u=unit;
   double product=step_distance*u;
   if(!(quote<(position.sl-product)-gap)) return;
   if(!(freeze+position.tp<quote)) return;
   if(reference_setting!=0.0)
   {
      double offset=u*copied_step;
      if(!(quote<selected_anchor-offset)) return;
   }
   if(counter<minimum_steps) return;
   uint digits1=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double candidate=Bot3RoundPrice(position.sl-step_distance*unit,digits1);
   if(!(candidate<position.sl)) return;
   counter=0;
   uint digits2=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
   double new_sl=Bot3RoundPrice(position.sl-step_distance*unit,digits2);
   position.sl=new_sl;
   Bot3ModifyPosition(state,options,ticket,position.sl,position.tp);
   changed=true;
}
#endif
