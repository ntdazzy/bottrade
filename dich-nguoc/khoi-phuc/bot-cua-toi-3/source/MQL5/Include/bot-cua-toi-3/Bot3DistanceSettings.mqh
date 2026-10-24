// Numeric part of native setup RVA 0xe0c0.
// Terminal/indicator reads are supplied in the context, not performed here.
// A false result means native division would fail; the caller must stop setup.
// Output values are usable only when this function returns true.
#ifndef BOT3_DISTANCE_SETTINGS_MQH
#define BOT3_DISTANCE_SETTINGS_MQH
#include "Bot3EntryProfiles.mqh"
struct Bot3DistanceInputs
{
   Bot3EntryProfile entry;
   double reference; // Native input 0x6d1b8
   bool use_variable; // Native input 0x1d6f28
   bool adjust_lots; // Native input 0x1d6f30
   double max_spread; // Native input 0x1d6f98
   bool feature_flag; // Native input 0x6d23c
   bool freeze_buffer_flag; // Native input 0x6d248
   double buy_offset; // Native input 0x6d2d0
   double sell_offset; // Native input 0x6d2d8
   double nearby_radius; // Native input 0x6d2e8
   int expiration_hours; // Native input 0x6d2f0
   bool virtual_expiration; // Native input 0x1d6fc8
   double stop_distance; // Native input 0x6d328
   double target_distance; // Native input 0x6d330
   double trail_distance; // Native input 0x6d348
   double trail_start; // Native input 0x6d350
   double trail_limit; // Native input 0x6d358
   double trail_step; // Native input 0x6d360
   double native_6d368; // Native input 0x6d368
   double native_6d370; // Native input 0x6d370
   double trigger_distance; // Native input 0x6d398
   double locked_distance; // Native input 0x6d3a0
   bool aux_hour1; // Native input 0x6d3b4
   bool aux_scan50; // Native input 0x6d3b5
   int aux_older; // Native input 0x6d3b8
   int aux_recent; // Native input 0x6d3bc
   double aux_offset; // Native input 0x6d3c8
   double min_change; // Native input 0x6d400
};
struct Bot3DistanceContext
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
struct Bot3Distances
{
   double scale; // Native output 0x6d1c0
   double lot_scale; // Native output 0x6d1c8
   double unit; // Native output 0x73dd8
   double spread; // Native output 0x6d650
   double max_spread; // Native output 0x6d4d0
   bool feature_flag; // Native output 0x6d4cc
   int freeze_buffer; // Native output 0x6d4d8
   int entry_frame; // Native output 0x6d524
   int older_width; // Native output 0x6d528
   int recent_width; // Native output 0x6d52c
   int last_shift; // Native output 0x6d530
   double gap_points; // Native output 0x6d538
   double buy_offset; // Native output 0x6d540
   double sell_offset; // Native output 0x6d548
   double nearby_radius; // Native output 0x6d558
   double stop_distance; // Native output 0x6d588
   double target_distance; // Native output 0x6d590
   double trail_distance; // Native output 0x6d598
   double trail_start; // Native output 0x6d5a0
   double trail_limit; // Native output 0x6d5a8
   double trail_step; // Native output 0x6d5b0
   double trigger_distance; // Native output 0x6d5b8
   double locked_distance; // Native output 0x6d5c0
   double native_6d378; // Native output 0x6d378
   double native_6d380; // Native output 0x6d380
   int aux_frame; // Native output 0x6d5cc
   int aux_scan; // Native output 0x6d5d0
   int aux_older; // Native output 0x6d5d4
   int aux_recent; // Native output 0x6d5d8
   double aux_offset; // Native output 0x6d5e0
   double min_change; // Native output 0x6d610
   double stop_min_price; // Native output 0x73ab0
   double freeze_min_price; // Native output 0x744a8
   uint expiration_seconds; // Native output 0x73de0
   long expiration; // Native output 0x74490
};
bool Bot3PrepareDistances(const Bot3DistanceInputs &r,const Bot3DistanceContext &c,Bot3Distances &o)
{
   double ratio=1.0;
   if(r.reference>=1000.0) ratio=c.sample/r.reference;
   o.scale=r.use_variable ? ratio : 1.0;
   o.lot_scale=1.0;
   if(r.adjust_lots)
   {
      // Native code divides before replacing a zero scale with one.
      if(o.scale==0.0) return false;
      o.lot_scale=1.0/o.scale;
   }
   if(o.scale==0.0) o.scale=1.0;
   o.unit=c.point;
   if(c.digits==3 || c.digits==5) o.unit=c.point*10.0;
   if(c.digits==1) o.unit=c.point/10.0;
   o.spread=c.ask-c.bid;
   o.max_spread=r.max_spread*o.scale;
   o.feature_flag=r.feature_flag;
   o.freeze_buffer=r.freeze_buffer_flag ? 2 : 0;
   o.entry_frame=r.entry.entry_frame;
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
   o.trigger_distance=r.trigger_distance*o.scale;
   o.locked_distance=o.scale*r.locked_distance;
   o.native_6d378=r.native_6d368*o.scale;
   o.native_6d380=r.native_6d370*o.scale;
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
