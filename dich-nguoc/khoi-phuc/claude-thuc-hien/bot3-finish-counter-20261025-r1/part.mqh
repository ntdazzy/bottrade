// Proposed part only: not compiled, not run, not compared with the original EX5.
// Part B (break-even lock and step counter) of native 0x32f60: buy 0x3691b..0x36b19 with split
// body 0x36f72..0x36fd4; 0x37590: sell 0x3aafe..0x3ad01 with split body 0x3b162..0x3b1c7.
// The touch/close test and the two-table store that follow belong to the caller.
#ifndef BOT3_VIRTUAL_BREAK_EVEN_COUNTER_MQH
#define BOT3_VIRTUAL_BREAK_EVEN_COUNTER_MQH
#include "Bot3ManagementPrelude.mqh"

#ifndef BOT3_VIRTUAL_FINISH_SETTINGS_MQH
#define BOT3_VIRTUAL_FINISH_SETTINGS_MQH
// Fields in order: 0x6d5d4,0x6d5c8,0x6d5dc,0x58488,0x584b0,0x6d5b8,0x6d5c0,0x6d514,
// 0x6d5f8,0x6d600,0x6d608,0x6d610. The two shifts are captured constants, not unit.
struct Bot3VirtualFinishSettings
{
   int high_low_enabled;
   uchar high_low_before_open;
   uchar high_low_shift;
   double high_low_buy_shift;
   double high_low_sell_shift;
   double lock_start;
   double lock_extra;
   int mode;
   uchar step_enabled;
   double step_reference;
   int min_steps;
   double step_distance;
};
#endif

// current_level 0x6d670, unit 0x73dd8, gap 0x73ab0, freeze 0x744a8, tick 0x74798/0x747a0,
// copied_step 0x74428, counter int 0x74430; selected_anchor is stack buy+0x78/sell+0x88.
// open_price/tp are captured once: native keeps them in nonvolatile xmm6/xmm7 across the API call.
// Ordered compares: NaN fails every check. The only API call is SYMBOL_POINT in the lock block.
// No Modify, Print, rounding or close; position is never written.
void Bot3AdvanceVirtualBreakEvenCounter(const bool buy,const string &symbol,
                                        const Bot3VirtualFinishSettings &settings,const double &unit,
                                        const double &gap,const double &freeze,const double selected_anchor,
                                        const double &copied_step,const Bot3ManagedPosition &position,
                                        MqlTick &tick,double &current_level,bool &changed,int &counter)
{
   double open_price=position.open_price;
   double tp=position.tp;
   double start=settings.lock_start;
   if(0.0<start && settings.mode==2)
   {
      double u=unit;
      double quote=buy ? tick.bid : tick.ask;
      double activation=start*u;
      double trigger=buy ? activation+open_price : open_price-activation;
      if(buy ? trigger<quote : quote<trigger)
      {
         double offset=u*settings.lock_extra;
         double candidate=buy ? offset+open_price : open_price-offset;
         double old=current_level;
         double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
         if(buy ? old+point<candidate : candidate<old-point)
         {
            // lock_extra, tick and unit are read again after the API call.
            double extra=settings.lock_extra;
            quote=buy ? tick.bid : tick.ask;
            offset=extra*unit;
            candidate=buy ? open_price+offset : open_price-offset;
            if(buy ? (gap+candidate<quote && quote<tp-freeze)
                   : (quote<candidate-gap && freeze+tp<quote))
            {
               current_level=candidate;
               changed=true;
            }
         }
      }
   }
   // A true flag (this lock or an earlier block) skips the counter. Below it the flag is false,
   // so the native clears at 0x36b08/0x36f82 and 0x3acf0/0x3b175 leave it unchanged.
   if(changed) return;
   double quote=buy ? tick.bid : tick.ask;
   double old=current_level;
   if(settings.step_enabled!=1) return;
   uint wrapped=(uint)counter; // int32 increment wraps like native inc eax
   wrapped++;
   int steps=(int)wrapped;
   counter=steps;
   double u=unit;
   double step=settings.step_distance*u;
   double next=buy ? step+old : old-step;
   if(!(buy ? gap+next<quote : quote<next-gap)) return;
   if(!(buy ? quote<tp-freeze : freeze+tp<quote)) return;
   // +0 and -0 skip the anchor test; any other value, NaN included, requires it on both sides.
   if(settings.step_reference!=0.0)
   {
      double distance=u*copied_step;
      if(!(buy ? selected_anchor+distance<quote : quote<selected_anchor-distance)) return;
   }
   if(steps<settings.min_steps) return;
   counter=0;
   current_level=next;
   changed=true;
}
#endif
