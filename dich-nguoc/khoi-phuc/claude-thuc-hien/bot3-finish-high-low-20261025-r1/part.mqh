// Proposed part only: not compiled, not run, not compared with the original EX5.
// Part A (high/low) of native 0x32f60: buy entries 0x36667/0x36736/0x36813, body 0x36749..0x36911;
// 0x37590: sell entry 0x3a97d, body 0x3a990..0x3aafe. Interleaved blocks are not part A.
#ifndef BOT3_VIRTUAL_HIGH_LOW_MQH
#define BOT3_VIRTUAL_HIGH_LOW_MQH
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
// strategy_index uint 0x74934, levels buy 0x74110/sell 0x73df0 (valid 0..8).
// Ordered compares: NaN fails every check. shift==0 still computes 0.0*unit.
// changed is only set, never reset; position is read only; no Modify, Print, Stamp or close.
void Bot3AdvanceVirtualHighLow(const bool buy,const string &symbol,
                               const Bot3VirtualFinishSettings &settings,const double &unit,
                               const double &gap,const double &freeze,
                               const Bot3ManagedPosition &position,MqlTick &tick,
                               const double &levels[],const uint &strategy_index,
                               double &current_level,bool &changed)
{
   if(settings.high_low_enabled<=0) return;
   double level=current_level;
   double first=levels[strategy_index];
   double limit=buy ? level+gap : level-gap;
   double point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(buy ? limit+point<first : first<limit-point)) return;
   double second=levels[strategy_index];
   if(!(buy ? second<position.open_price : position.open_price<second)
      && (settings.high_low_before_open&1)!=0) return;
   double shift=settings.high_low_shift==0 ? 0.0
                : (buy ? settings.high_low_buy_shift : settings.high_low_sell_shift);
   double offset=shift*unit;
   double quote=buy ? tick.bid : tick.ask;
   limit=buy ? (quote-offset)-gap : (offset+quote)+gap;
   point=SymbolInfoDouble(symbol,SYMBOL_POINT);
   if(!(buy ? second<limit-point : limit+point<second)) return;
   if(!(buy ? tick.bid<(position.tp-freeze) : (freeze+position.tp)<tick.ask)) return;
   changed=true;
   current_level=levels[strategy_index];
}
#endif
