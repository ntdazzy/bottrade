// Numeric part of native setup RVA 0x7500.
// Terminal/indicator reads are supplied in the context, not performed here.
// A false result means native division would fail; the caller must stop setup.
// Output values are usable only when this function returns true.
#ifndef BOT1_DISTANCE_SETTINGS_MQH
#define BOT1_DISTANCE_SETTINGS_MQH
#include "Bot1EntryProfiles.mqh"
struct Bot1DistanceInputs
{
   Bot1EntryProfile entry;
   double reference; // Native input 0x62180
   bool use_variable; // Native input 0x6a5c8
   bool adjust_lots; // Native input 0x6a798
   double max_spread; // Native input 0x6a5c0
   bool feature_flag; // Native input 0x62214
   bool freeze_buffer_flag; // Native input 0x62215
   double buy_offset; // Native input 0x62298
   double sell_offset; // Native input 0x622a0
   double nearby_radius; // Native input 0x622b0
   int expiration_hours; // Native input 0x622b8
   bool virtual_expiration; // Native input 0x6a5e8
   double stop_distance; // Native input 0x622f8
   double target_distance; // Native input 0x62300
   double trail_distance; // Native input 0x62318
   double trail_start; // Native input 0x62320
   double trail_limit; // Native input 0x62328
   double trail_step; // Native input 0x62330
   bool aux_hour1; // Native input 0x62354
   bool aux_scan50; // Native input 0x62355
   int aux_older; // Native input 0x62358
   int aux_recent; // Native input 0x6235c
   double aux_offset; // Native input 0x62368
   double min_change; // Native input 0x623a0
};
struct Bot1DistanceContext
{
   double sample;
   double point;
   int digits;
   long stops_level;
   long freeze_level;
   double bid;
   double ask;
   long now;
};
struct Bot1Distances
{
   double scale; // Native output 0x682e8
   double lot_scale; // Native output 0x682f0
   double unit; // Native output 0x66d98
   double spread; // Native output 0x62560
   double max_spread; // Native output 0x623d8
   bool feature_flag; // Native output 0x623d4
   int freeze_buffer; // Native output 0x623e0
   int entry_frame; // Native output 0x6242c
   int older_width; // Native output 0x62430
   int recent_width; // Native output 0x62434
   int last_shift; // Native output 0x62438
   double gap_points; // Native output 0x62440
   double buy_offset; // Native output 0x62448
   double sell_offset; // Native output 0x62450
   double nearby_radius; // Native output 0x62460
   double stop_distance; // Native output 0x62498
   double target_distance; // Native output 0x624a0
   double trail_distance; // Native output 0x624a8
   double trail_start; // Native output 0x624b0
   double trail_limit; // Native output 0x624b8
   double trail_step; // Native output 0x624c0
   double trigger_distance; // Native output 0x624c8
   double locked_distance; // Native output 0x624d0
   int aux_frame; // Native output 0x624dc
   int aux_scan; // Native output 0x624e0
   int aux_older; // Native output 0x624e4
   int aux_recent; // Native output 0x624e8
   double aux_offset; // Native output 0x624f0
   double min_change; // Native output 0x62520
   double stop_min_price; // Native output 0x66a70
   double freeze_min_price; // Native output 0x67468
   uint expiration_seconds; // Native output 0x66da0
   long expiration; // Native output 0x67450
};
bool Bot1PrepareDistances(const Bot1DistanceInputs &r,const Bot1DistanceContext &c,Bot1Distances &o)
{
   double ratio=1.0;
   if(r.reference>0.0) ratio=c.sample/r.reference;
   o.scale=r.use_variable ? ratio : 1.0;
   if(o.scale==0.0) o.scale=1.0;
   o.lot_scale=r.adjust_lots ? 1.0/o.scale : 1.0;
   o.unit=c.point;
   if(c.digits==3 || c.digits==5) o.unit=c.point*10.0;
   if(c.digits==1) o.unit=c.point/10.0;
   o.spread=c.ask-c.bid;
   o.max_spread=r.max_spread*o.scale;
   o.feature_flag=(double)r.feature_flag*o.scale!=0.0;
   o.freeze_buffer=(int)((r.freeze_buffer_flag ? 2.0 : 0.0)*o.scale);
   o.entry_frame=r.entry.hour1_flag!=0 ? PERIOD_H1 : PERIOD_CURRENT;
   o.older_width=r.entry.older_width;
   o.recent_width=r.entry.recent_width;
   o.last_shift=r.entry.last_shift;
   o.gap_points=r.entry.gap_points*o.scale;
   o.buy_offset=r.buy_offset*o.scale;
   o.sell_offset=r.sell_offset*o.scale;
   o.nearby_radius=r.nearby_radius*o.scale;
   o.stop_distance=r.stop_distance*o.scale;
   o.target_distance=r.target_distance*o.scale;
   o.trail_distance=r.trail_distance*o.scale;
   o.trail_start=r.trail_start*o.scale;
   o.trail_limit=r.trail_limit*o.scale;
   o.trail_step=r.trail_step*o.scale;
   o.trigger_distance=o.scale*0.0;
   o.locked_distance=o.trigger_distance;
   o.aux_frame=r.aux_hour1 ? PERIOD_H1 : PERIOD_CURRENT;
   o.aux_scan=r.aux_scan50 ? 50 : 0;
   o.aux_older=r.aux_older;
   o.aux_recent=r.aux_recent;
   o.aux_offset=r.aux_offset;
   o.min_change=r.min_change;
   if(o.min_change*o.unit<c.point)
   {
      if(o.unit==0.0) return false;
      o.min_change=c.point/o.unit;
   }
   o.stop_min_price=(double)c.stops_level*c.point;
   o.freeze_min_price=(double)c.freeze_level*c.point;
   if(o.stop_distance<=0.0) o.stop_distance=1.0;
   if(o.target_distance<=0.0) o.target_distance=1.0;
   if(o.trigger_distance<o.locked_distance) o.locked_distance=o.trigger_distance+0.1;
   if(o.unit==0.0) return false;
   double freeze_units=o.freeze_min_price/o.unit;
   if((double)o.freeze_buffer<freeze_units) o.freeze_buffer=(int)freeze_units;
   if(o.trail_distance!=0.0 && o.trail_distance<freeze_units) o.trail_distance=freeze_units;
   if(o.trail_distance!=0.0 && o.trail_distance<o.stop_min_price/o.unit)
      o.trail_distance=o.stop_min_price/o.unit;
   double twice_stop=(o.stop_min_price+o.stop_min_price)/o.unit;
   if(twice_stop>o.stop_distance) o.stop_distance=twice_stop;
   if(o.target_distance<twice_stop) o.target_distance=twice_stop;
   if(twice_stop>o.gap_points) o.gap_points=twice_stop;
   if(o.older_width<1) o.older_width=1;
   if(o.recent_width<1) o.recent_width=1;
   if(o.gap_points<0.1) o.gap_points=0.1;
   // Native multiplication wraps to 32 bits, then the sum uses unsigned seconds.
   o.expiration_seconds=(uint)r.expiration_hours*(uint)3600;
   o.expiration=r.expiration_hours<1 ? 0 : c.now+(long)o.expiration_seconds;
   if(r.virtual_expiration) o.expiration=0;
   return true;
}
#endif
