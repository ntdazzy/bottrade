#property strict
// Pure calculation check. No order functions or live account changes.
#include "../../Include/bot-cua-toi-3/Bot3BaseDistances.mqh"
input string CheckRun="";
union DoubleBits { double value; ulong bits; };
ulong ValueBits(const double value) { DoubleBits v; v.value=value; return v.bits; }
int OnStart()
{
   if(CheckRun=="") { Print("CheckRun is required"); return 1; }
   string folder="bot3-distance-settings\\"+CheckRun+"\\";
   int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(h==INVALID_HANDLE) return 1;
   int magic=FileReadInteger(h),version=FileReadInteger(h),bot=FileReadInteger(h),count=FileReadInteger(h);
   if(magic!=0x44535431 || version!=1 || bot!=3 || count<1) { FileClose(h); return 1; }
   if(FileSize(h)!=(ulong)16+(ulong)count*268) { FileClose(h); return 1; }
   int profiles=FileOpen(folder+"profiles.bin",FILE_WRITE|FILE_BIN);
   if(profiles==INVALID_HANDLE) { FileClose(h); return 1; }
   FileWriteInteger(profiles,0x42504631);FileWriteInteger(profiles,1);
   FileWriteInteger(profiles,9);FileWriteInteger(profiles,25);
   Bot3DistanceInputs base;
   ZeroMemory(base);
   if(Bot3LoadBaseDistances(-1,base) || Bot3LoadBaseDistances(9,base))
   { FileClose(h);FileClose(profiles);return 1; }
   for(int index=0;index<9;index++)
   for(int hl=0;hl<1;hl++)
   {
      if(!Bot3LoadBaseDistances(index,base)) { FileClose(h);FileClose(profiles);return 1; }
      FileWriteInteger(profiles,index);FileWriteInteger(profiles,hl);
      FileWriteLong(profiles,(long)base.entry.confirmation_frame);
      FileWriteLong(profiles,(long)base.entry.entry_frame);
      FileWriteLong(profiles,(long)base.entry.older_width);
      FileWriteLong(profiles,(long)base.entry.recent_width);
      FileWriteLong(profiles,(long)base.entry.last_shift);
      FileWriteLong(profiles,(long)ValueBits(base.entry.gap_points));
      FileWriteLong(profiles,(long)ValueBits(base.buy_offset));
      FileWriteLong(profiles,(long)ValueBits(base.sell_offset));
      FileWriteLong(profiles,(long)ValueBits(base.nearby_radius));
      FileWriteLong(profiles,(long)base.expiration_hours);
      FileWriteLong(profiles,(long)ValueBits(base.stop_distance));
      FileWriteLong(profiles,(long)ValueBits(base.target_distance));
      FileWriteLong(profiles,(long)ValueBits(base.trail_distance));
      FileWriteLong(profiles,(long)ValueBits(base.trail_start));
      FileWriteLong(profiles,(long)ValueBits(base.trail_limit));
      FileWriteLong(profiles,(long)ValueBits(base.trail_step));
      FileWriteLong(profiles,(long)ValueBits(base.native_6d368));
      FileWriteLong(profiles,(long)ValueBits(base.native_6d370));
      FileWriteLong(profiles,(long)ValueBits(base.trigger_distance));
      FileWriteLong(profiles,(long)ValueBits(base.locked_distance));
      FileWriteLong(profiles,(long)base.aux_hour1);
      FileWriteLong(profiles,(long)base.aux_scan50);
      FileWriteLong(profiles,(long)base.aux_older);
      FileWriteLong(profiles,(long)base.aux_recent);
      FileWriteLong(profiles,(long)ValueBits(base.aux_offset));
   }
   FileClose(profiles);
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(h); return 1; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);
   FileWriteInteger(output,count);FileWriteInteger(output,35);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(h);
      Bot3DistanceInputs r; Bot3DistanceContext c; Bot3Distances o;
      r.reference=FileReadDouble(h);
      r.use_variable=FileReadInteger(h)!=0;
      r.adjust_lots=FileReadInteger(h)!=0;
      r.max_spread=FileReadDouble(h);
      r.feature_flag=FileReadInteger(h)!=0;
      r.freeze_buffer_flag=FileReadInteger(h)!=0;
      r.entry.confirmation_frame=FileReadInteger(h);
      r.entry.entry_frame=FileReadInteger(h);
      r.entry.older_width=FileReadInteger(h);
      r.entry.recent_width=FileReadInteger(h);
      r.entry.last_shift=FileReadInteger(h);
      r.entry.gap_points=FileReadDouble(h);
      r.buy_offset=FileReadDouble(h);
      r.sell_offset=FileReadDouble(h);
      r.nearby_radius=FileReadDouble(h);
      r.expiration_hours=FileReadInteger(h);
      r.virtual_expiration=FileReadInteger(h)!=0;
      r.stop_distance=FileReadDouble(h);
      r.target_distance=FileReadDouble(h);
      r.trail_distance=FileReadDouble(h);
      r.trail_start=FileReadDouble(h);
      r.trail_limit=FileReadDouble(h);
      r.trail_step=FileReadDouble(h);
      r.native_6d368=FileReadDouble(h);
      r.native_6d370=FileReadDouble(h);
      r.trigger_distance=FileReadDouble(h);
      r.locked_distance=FileReadDouble(h);
      r.aux_hour1=FileReadInteger(h)!=0;
      r.aux_scan50=FileReadInteger(h)!=0;
      r.aux_older=FileReadInteger(h);
      r.aux_recent=FileReadInteger(h);
      r.aux_offset=FileReadDouble(h);
      r.min_change=FileReadDouble(h);
      c.sample=FileReadDouble(h);
      c.point=FileReadDouble(h);
      c.digits=FileReadInteger(h);
      c.stops_level=FileReadLong(h);
      c.freeze_level=FileReadLong(h);
      c.bid=FileReadDouble(h);
      c.ask=FileReadDouble(h);
      c.now=FileReadLong(h);
      bool ok=Bot3PrepareDistances(r,c,o);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)ok);
      FileWriteLong(output,ok ? (long)ValueBits(o.scale) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.lot_scale) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.unit) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.spread) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.max_spread) : 0);
      FileWriteLong(output,ok ? (long)o.feature_flag : 0);
      FileWriteLong(output,ok ? (long)o.freeze_buffer : 0);
      FileWriteLong(output,ok ? (long)o.entry_frame : 0);
      FileWriteLong(output,ok ? (long)o.older_width : 0);
      FileWriteLong(output,ok ? (long)o.recent_width : 0);
      FileWriteLong(output,ok ? (long)o.last_shift : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.gap_points) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.buy_offset) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.sell_offset) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.nearby_radius) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.stop_distance) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.target_distance) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.trail_distance) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.trail_start) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.trail_limit) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.trail_step) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.trigger_distance) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.locked_distance) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.native_6d378) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.native_6d380) : 0);
      FileWriteLong(output,ok ? (long)o.aux_frame : 0);
      FileWriteLong(output,ok ? (long)o.aux_scan : 0);
      FileWriteLong(output,ok ? (long)o.aux_older : 0);
      FileWriteLong(output,ok ? (long)o.aux_recent : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.aux_offset) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.min_change) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.stop_min_price) : 0);
      FileWriteLong(output,ok ? (long)ValueBits(o.freeze_min_price) : 0);
      FileWriteLong(output,ok ? (long)o.expiration_seconds : 0);
      FileWriteLong(output,ok ? (long)o.expiration : 0);
   }
   bool exact=FileTell(h)==FileSize(h);
   FileClose(h);FileClose(output);
   if(!exact) { Print("Unexpected input length"); return 1; }
   Print("Distance settings: ",count," cases written");
   return 0;
}
