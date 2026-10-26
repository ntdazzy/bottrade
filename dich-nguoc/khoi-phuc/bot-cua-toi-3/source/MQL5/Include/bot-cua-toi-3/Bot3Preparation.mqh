// Strategy preparation run before one strategy is evaluated.
// Indicator and terminal services are called in a fixed order; the caller supplies loaded settings.
// Short indicator data and zero divisions are left to stop the program as MQL5 runtime errors.
#ifndef BOT3_PREPARATION_MQH
#define BOT3_PREPARATION_MQH
#include "Bot3EntryProfiles.mqh"
struct Bot3PreparationInputs
{
   string symbol;
   string comment;
   int indicator_timeframe;
   int indicator_period;
   double reference;
   uchar variable_distances;
   uchar adjust_lots;
   Bot3EntryProfile entry;
   // Read by the first settings table.
   uchar feature_flag;
   double max_spread;
   uchar freeze_buffer_flag;
   double native_6d250;
   uchar native_6d258;
   double native_6d260;
   double native_6d268;
   double native_6d270;
   uchar native_6d278;
   int native_1d6fa8;
   uchar native_1d6fc0;
   uchar virtual_expiration;
   uchar virtual_stops;
   int native_1d6fe8;
   uchar native_1d7178;
   uchar native_6d2a3;
   double buy_offset;
   double sell_offset;
   int native_6d2e0;
   double nearby_radius;
   int expiration_hours;
   int management_timeframe;
   double stop_distance;
   double target_distance;
   double trail_distance;
   double trail_start;
   double native_6d368;
   double native_6d370;
   double trail_limit;
   double trail_step;
   double trigger_distance;
   double locked_distance;
   uchar aux_hour1;
   uchar aux_scan50;
   int aux_older;
   int aux_recent;
   double aux_offset;
   uchar native_6d3f8;
   double native_6d3f0;
   double min_change;
   // Read after the comment is copied.
   double native_6d408;
   double native_1d7138;
   double native_6d410;
   int native_1d7130;
   double native_6d418;
   uchar native_6d420;
};
struct Bot3PreparationState
{
   int indicator_handle;
   double indicator_values[];
   uint strategy_index;
   MqlTick tick;
   MqlDateTime calendar;
   double scale;
   double lot_scale;
   double point;
   double unit;
   double spread;
   string comment;
   // Written by the first settings table.
   uchar feature_flag;
   double max_spread;
   int freeze_buffer;
   double native_6d4e0;
   int native_6d4e8;
   double native_6d4f0;
   double native_6d4f8;
   double native_6d500;
   uchar native_6d508;
   int native_6d50c;
   uchar native_6d510;
   uchar virtual_expiration;
   int mode;
   int native_6d518;
   uchar native_6d51c;
   int native_6d520;
   int entry_frame;
   int older_width;
   int recent_width;
   int last_shift;
   double gap_points;
   double buy_offset;
   double sell_offset;
   int native_6d550;
   double nearby_radius;
   int expiration_hours;
   int management_timeframe;
   double stop_distance;
   double target_distance;
   double trail_distance;
   double trail_start;
   double native_6d378;
   double native_6d380;
   double trail_limit;
   double trail_step;
   uchar native_6d5c8;
   double trigger_distance;
   double locked_distance;
   double native_6d5f0;
   int aux_frame;
   int aux_scan;
   int aux_older;
   int aux_recent;
   double aux_offset;
   uchar native_6d5dc;
   double native_6d5e8;
   int native_6d608;
   uchar native_6d5f8;
   double native_6d600;
   double min_change;
   // Written after the comment.
   double native_6d618;
   double native_6d620;
   double native_6d628;
   int native_6d630;
   double native_6d638;
   int native_6d640;
   // Broker limits and expiration.
   double stop_min_price;
   double freeze_min_price;
   uint expiration_seconds;
   long expiration;
};
// `input` is reserved in MQL5, so the settings parameter is named inputs.
void Bot3PrepareStrategy(const uint strategy_index,
                        const Bot3PreparationInputs &inputs,
                        Bot3PreparationState &state)
{
   // A. Indicator and scale.
   const int frame=inputs.indicator_timeframe;
   const int period=inputs.indicator_period;
   state.indicator_handle=iATR(inputs.symbol,(ENUM_TIMEFRAMES)frame,period);
   if(state.indicator_handle<0)
   {
      Print("The creation of iATR has failed: Runtime error =",GetLastError());
      return;
   }
   const int copied=CopyBuffer(state.indicator_handle,0,0,100,state.indicator_values);
   if(copied==0) return;
   ArraySetAsSeries(state.indicator_values,true);
   if(ArraySize(state.indicator_values)<2)
   {
      // The out-of-range read stops the program before state.scale is written.
      state.scale=state.indicator_values[1];
      return;
   }
   double ratio=1.0;
   if(inputs.reference>=1000.0)
   {
      const double sample=iOpen(inputs.symbol,PERIOD_D1,1);
      ratio=sample/inputs.reference;
   }
   state.scale=inputs.variable_distances!=0 ? ratio : 1.0;
   double lot=1.0;
   if(inputs.adjust_lots!=0) lot=1.0/state.scale;
   state.lot_scale=lot;
   if(state.scale==0.0) state.scale=1.0;
   // B. Prices and unit.
   state.strategy_index=strategy_index;
   if(!SymbolInfoTick(inputs.symbol,state.tick)) Print("Tick not ok");
   TimeCurrent(state.calendar);
   const double point=SymbolInfoDouble(inputs.symbol,SYMBOL_POINT);
   state.point=point;
   state.unit=point;
   if(SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS)==3) state.unit=state.point*10.0;
   else if(SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS)==5) state.unit=state.point*10.0;
   if(SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS)==1) state.unit=state.point/10.0;
   state.spread=state.tick.ask-state.tick.bid;
   // The digits are read once more and the result is not used.
   SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS);
   // C. Settings copied in write order.
   const double scale=state.scale;
   state.feature_flag=inputs.feature_flag;
   state.max_spread=inputs.max_spread*scale;
   state.freeze_buffer=(int)((uint)inputs.freeze_buffer_flag*2);
   state.native_6d4e0=inputs.native_6d250;
   state.native_6d4e8=inputs.native_6d258;
   state.native_6d4f0=inputs.native_6d260;
   state.native_6d4f8=inputs.native_6d268;
   state.native_6d500=inputs.native_6d270;
   state.native_6d508=inputs.native_6d278;
   state.native_6d50c=inputs.native_1d6fa8;
   state.native_6d510=inputs.native_1d6fc0;
   state.virtual_expiration=inputs.virtual_expiration;
   state.mode=inputs.virtual_stops==0 ? 1 : 2;
   state.native_6d518=inputs.native_1d6fe8;
   state.native_6d51c=inputs.native_1d7178;
   state.native_6d520=inputs.native_6d2a3;
   state.entry_frame=inputs.entry.entry_frame;
   state.older_width=inputs.entry.older_width;
   state.recent_width=inputs.entry.recent_width;
   state.last_shift=inputs.entry.last_shift;
   state.gap_points=inputs.entry.gap_points*scale;
   state.buy_offset=inputs.buy_offset*scale;
   state.sell_offset=inputs.sell_offset*scale;
   state.native_6d550=inputs.native_6d2e0;
   state.nearby_radius=inputs.nearby_radius*scale;
   state.expiration_hours=inputs.expiration_hours;
   state.management_timeframe=inputs.management_timeframe;
   state.stop_distance=inputs.stop_distance*scale;
   state.target_distance=inputs.target_distance*scale;
   state.trail_distance=inputs.trail_distance*scale;
   state.trail_start=inputs.trail_start*scale;
   state.native_6d378=inputs.native_6d368*scale;
   state.native_6d380=inputs.native_6d370*scale;
   state.trail_limit=inputs.trail_limit*scale;
   state.trail_step=inputs.trail_step*scale;
   state.native_6d5c8=0;
   state.trigger_distance=inputs.trigger_distance*scale;
   state.locked_distance=scale*inputs.locked_distance;
   state.native_6d5f0=0.0;
   state.aux_frame=inputs.aux_hour1!=0 ? (int)PERIOD_H1 : 0;
   state.aux_scan=inputs.aux_scan50!=0 ? 50 : 0;
   state.aux_older=inputs.aux_older;
   state.aux_recent=inputs.aux_recent;
   state.aux_offset=inputs.aux_offset;
   state.native_6d5dc=0;
   state.native_6d5e8=0.0;
   state.native_6d608=inputs.native_6d3f8;
   state.native_6d5f8=0;
   state.native_6d600=inputs.native_6d3f0;
   state.min_change=inputs.min_change;
   state.comment=inputs.comment;
   const double candidate=state.min_change*state.unit;
   state.native_6d618=inputs.native_6d408;
   state.native_6d620=inputs.native_1d7138;
   state.native_6d628=inputs.native_6d410;
   state.native_6d630=inputs.native_1d7130;
   state.native_6d638=inputs.native_6d418;
   state.native_6d640=inputs.native_6d420!=0 ? 600 : 0;
   // D. Broker limits and normalisation.
   if(candidate<SymbolInfoDouble(inputs.symbol,SYMBOL_POINT))
   {
      const double current_point=SymbolInfoDouble(inputs.symbol,SYMBOL_POINT);
      state.min_change=current_point/state.unit;
   }
   const long stops_level=SymbolInfoInteger(inputs.symbol,SYMBOL_TRADE_STOPS_LEVEL);
   state.stop_min_price=(double)stops_level*SymbolInfoDouble(inputs.symbol,SYMBOL_POINT);
   const long freeze_level=SymbolInfoInteger(inputs.symbol,SYMBOL_TRADE_FREEZE_LEVEL);
   state.freeze_min_price=(double)freeze_level*SymbolInfoDouble(inputs.symbol,SYMBOL_POINT);
   double stop=state.stop_distance;
   if(stop<=0.0)
   {
      state.stop_distance=1.0;
      stop=1.0;
   }
   double target=state.target_distance;
   if(target<=0.0)
   {
      state.target_distance=1.0;
      target=1.0;
   }
   if(state.trigger_distance<state.locked_distance)
      state.locked_distance=state.trigger_distance+0.1;
   const double unit=state.unit;
   const double freeze_units=state.freeze_min_price/unit;
   if((double)state.freeze_buffer<freeze_units) state.freeze_buffer=(int)freeze_units;
   if(state.trail_distance!=0.0 && state.trail_distance<freeze_units)
      state.trail_distance=freeze_units;
   if(state.trail_distance!=0.0 && state.trail_distance<state.stop_min_price/unit)
      state.trail_distance=state.stop_min_price/unit;
   // Kept although native_6d5e8 was set to +0.0 above.
   if(state.native_6d5e8>0.0)
   {
      if(state.native_6d5f0<freeze_units) state.native_6d5f0=freeze_units;
      if(state.native_6d5f0<state.stop_min_price/unit)
         state.native_6d5f0=state.stop_min_price/unit;
   }
   const double twice_stop=(state.stop_min_price+state.stop_min_price)/unit;
   if(twice_stop>stop) state.stop_distance=twice_stop;
   if(target<twice_stop) state.target_distance=twice_stop;
   if(twice_stop>state.gap_points) state.gap_points=twice_stop;
   if(state.older_width<1) state.older_width=1;
   if(state.recent_width<1) state.recent_width=1;
   if(state.gap_points<0.1) state.gap_points=0.1;
   // The multiplication wraps to 32 bits.
   state.expiration_seconds=(uint)state.expiration_hours*(uint)3600;
   long expiry=0;
   if(state.expiration_hours>=1)
   {
      const datetime now=TimeCurrent();
      expiry=(long)now+(long)state.expiration_seconds;
   }
   if(state.virtual_expiration==0) state.expiration=expiry;
   else state.expiration=0;
}
#endif
