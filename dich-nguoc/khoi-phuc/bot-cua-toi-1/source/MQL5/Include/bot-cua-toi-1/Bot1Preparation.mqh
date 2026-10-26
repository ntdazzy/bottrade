// Preparation before one strategy evaluation. Native function RVA 0x7500.
#ifndef BOT1_PREPARATION_MQH
#define BOT1_PREPARATION_MQH
#include "Bot1EntryProfiles.mqh"

struct Bot1PreparationInputs
{
   string symbol,comment;
   int indicator_period;
   uchar indicator_day;
   double reference;
   uchar variable_distances,adjust_lots;
   Bot1EntryProfile entry;
   uchar feature_flag;
   double max_spread;
   uchar freeze_buffer_flag;
   double native_62218;
   uchar native_62220;
   double native_62228,native_62230,native_62238;
   uchar native_62240;
   int native_6a5d8;
   uchar omit_real_sl_tp,virtual_expiration,virtual_stops;
   int native_6a608;
   uchar check_free_margin,native_62268;
   double buy_offset,sell_offset;
   uchar native_622a8;
   double nearby_radius;
   int expiration_hours,native_622ec;
   uchar native_622f0;
   double stop_distance,target_distance,trail_distance,trail_start,trail_limit,trail_step;
   uchar aux_hour1,aux_scan50;
   int aux_older,aux_recent;
   double aux_offset,native_62390;
   uchar native_62398;
   double min_change,native_623a8,native_6a740,native_623b0;
   int native_6a748;
   double native_6a750;
   int native_6a768;
};

struct Bot1PreparationState
{
   int indicator_handle;
   double indicator_values[];
   uint strategy_index;
   MqlTick tick;
   MqlDateTime calendar;
   double scale,lot_scale,point,unit,spread;
   string comment;
   uchar feature_flag;
   double max_spread;
   int freeze_buffer;
   double native_623e8;
   int native_623f0;
   double native_623f8,native_62400,native_62408;
   uchar native_62410;
   int native_62414;
   uchar omit_real_sl_tp,virtual_expiration;
   int mode,native_62420;
   uchar check_free_margin;
   int native_62428,entry_frame,older_width,recent_width,last_shift;
   double gap_points,buy_offset,sell_offset;
   int native_62458;
   double nearby_radius;
   int expiration_hours,native_6248c;
   uchar native_62490;
   double stop_distance,target_distance,trail_distance,trail_start,trail_limit,trail_step;
   double trigger_distance,locked_distance;
   uchar native_624d8;
   int aux_frame,aux_scan,aux_older,aux_recent;
   uchar native_624ec;
   double aux_offset,native_624f8,native_62500;
   uchar native_62508;
   double native_62510;
   int native_62518;
   double min_change,native_62528,native_62530,native_62538;
   int native_62540;
   double native_62548;
   int native_62550;
   double stop_min_price,freeze_min_price;
   uint expiration_seconds;
   long expiration;
};

void Bot1PrepareStrategy(const uint strategy_index,const Bot1PreparationInputs &inputs,
                         Bot1PreparationState &state)
{
   const int period=inputs.indicator_period;
   const int frame=inputs.indicator_day!=0 ? (int)PERIOD_D1 : (int)PERIOD_CURRENT;
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
      state.scale=state.indicator_values[1];
      return;
   }
   double ratio=1.0;
   if(inputs.reference>0.0) ratio=state.indicator_values[1]/inputs.reference;
   double scale=inputs.variable_distances!=0 ? ratio : 1.0;
   if(scale==0.0) scale=1.0;
   state.scale=scale;
   double lot=1.0;
   if(inputs.adjust_lots!=0) lot=1.0/state.scale;
   state.lot_scale=lot;
   state.strategy_index=strategy_index;
   if(!SymbolInfoTick(inputs.symbol,state.tick)) Print("Tick not ok");
   TimeCurrent(state.calendar);
   const double point=SymbolInfoDouble(inputs.symbol,SYMBOL_POINT);
   state.point=point;state.unit=point;
   if(SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS)==3) state.unit=state.point*10.0;
   else if(SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS)==5) state.unit=state.point*10.0;
   if(SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS)==1) state.unit=state.point/10.0;
   state.spread=state.tick.ask-state.tick.bid;
   SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS);

   const double current_scale=state.scale;
   state.feature_flag=(uchar)((double)inputs.feature_flag*current_scale!=0.0);
   state.max_spread=inputs.max_spread*current_scale;
   double freeze_buffer=inputs.freeze_buffer_flag!=0 ? 2.0 : 0.0;
   freeze_buffer=freeze_buffer*current_scale;
   double zero_distance=0.0*current_scale;
   state.locked_distance=zero_distance;
   state.freeze_buffer=(int)freeze_buffer;
   state.native_623e8=inputs.native_62218;
   state.native_623f0=inputs.native_62220;
   state.native_623f8=inputs.native_62228;
   state.native_62400=inputs.native_62230;
   state.native_62408=inputs.native_62238;
   state.native_62410=inputs.native_62240;
   state.native_62414=inputs.native_6a5d8;
   state.omit_real_sl_tp=inputs.omit_real_sl_tp;
   state.virtual_expiration=inputs.virtual_expiration;
   state.mode=inputs.virtual_stops==0 ? 1 : 2;
   state.native_62420=inputs.native_6a608;
   state.check_free_margin=inputs.check_free_margin;
   state.native_62428=inputs.native_62268;
   state.entry_frame=inputs.entry.hour1_flag!=0 ? (int)PERIOD_H1 : (int)PERIOD_CURRENT;
   state.older_width=inputs.entry.older_width;
   state.recent_width=inputs.entry.recent_width;
   state.last_shift=inputs.entry.last_shift;
   state.gap_points=inputs.entry.gap_points*current_scale;
   state.buy_offset=inputs.buy_offset*current_scale;
   state.sell_offset=inputs.sell_offset*current_scale;
   state.native_62458=inputs.native_622a8;
   state.nearby_radius=inputs.nearby_radius*current_scale;
   state.expiration_hours=inputs.expiration_hours;
   state.native_6248c=inputs.native_622ec;
   state.native_62490=inputs.native_622f0;
   state.stop_distance=inputs.stop_distance*current_scale;
   state.target_distance=inputs.target_distance*current_scale;
   state.trail_distance=inputs.trail_distance*current_scale;
   state.trail_start=inputs.trail_start*current_scale;
   state.trigger_distance=zero_distance;
   state.trail_limit=inputs.trail_limit*current_scale;
   state.native_624d8=0;
   state.trail_step=inputs.trail_step*current_scale;
   state.aux_frame=inputs.aux_hour1!=0 ? (int)PERIOD_H1 : (int)PERIOD_CURRENT;
   state.aux_scan=inputs.aux_scan50!=0 ? 50 : 0;
   state.native_62500=0.0;
   state.aux_older=inputs.aux_older;
   state.aux_recent=inputs.aux_recent;
   state.aux_offset=inputs.aux_offset;
   state.native_624ec=0;
   state.native_624f8=0.0;
   state.native_62508=0;
   state.native_62510=inputs.native_62390;
   state.native_62518=inputs.native_62398;
   state.min_change=inputs.min_change;
   state.comment=inputs.comment;
   const double candidate=state.min_change*state.unit;
   state.native_62528=inputs.native_623a8;
   state.native_62530=inputs.native_6a740;
   state.native_62538=inputs.native_623b0;
   state.native_62540=inputs.native_6a748;
   state.native_62548=inputs.native_6a750;
   state.native_62550=inputs.native_6a768;
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
   if(stop<=0.0) { state.stop_distance=1.0;stop=1.0; }
   double target=state.target_distance;
   if(target<=0.0) { state.target_distance=1.0;target=1.0; }
   if(state.locked_distance>state.trigger_distance) state.locked_distance=state.trigger_distance+0.1;
   const double freeze_units=state.freeze_min_price/state.unit;
   if(freeze_units>(double)state.freeze_buffer) state.freeze_buffer=(int)freeze_units;
   if(state.trail_distance!=0.0 && freeze_units>state.trail_distance) state.trail_distance=freeze_units;
   if(state.trail_distance!=0.0 && state.stop_min_price/state.unit>state.trail_distance)
      state.trail_distance=state.stop_min_price/state.unit;
   if(state.native_624f8>0.0)
   {
      if(freeze_units>state.native_62500) state.native_62500=freeze_units;
      if(state.stop_min_price/state.unit>state.native_62500) state.native_62500=state.stop_min_price/state.unit;
   }
   const double twice_stop=(state.stop_min_price+state.stop_min_price)/state.unit;
   if(twice_stop>stop) state.stop_distance=twice_stop;
   if(twice_stop>target) state.target_distance=twice_stop;
   if(twice_stop>state.gap_points) state.gap_points=twice_stop;
   if(state.older_width<=0) state.older_width=1;
   if(state.recent_width<=0) state.recent_width=1;
   if(0.1>state.gap_points) state.gap_points=0.1;
   state.expiration_seconds=(uint)state.expiration_hours*(uint)3600;
   long expiration=0;
   if(state.expiration_hours>0) expiration=(long)TimeCurrent()+(long)state.expiration_seconds;
   state.expiration=state.virtual_expiration==0 ? expiration : 0;
}
#endif
