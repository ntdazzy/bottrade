// Base strategy distances, from native assignment blocks.
// Applies only when randomization and additional distance adjustments are zero.
// Updates listed profile fields only; caller supplies the remaining global inputs.
#ifndef BOT3_BASE_DISTANCES_MQH
#define BOT3_BASE_DISTANCES_MQH
#include "Bot3DistanceSettings.mqh"
bool Bot3LoadBaseDistances(const int index,Bot3DistanceInputs &r)
{
   if(!Bot3LoadEntryProfile(index,r.entry)) return false;
   double buy_offset[9]={-275.0,-170.0,-130.0,-40.0,-120.0,-115.0,-10.0,-140.0,-150.0};
   r.buy_offset=buy_offset[index];
   double sell_offset[9]={-160.0,-70.0,-120.0,-100.0,-110.0,-145.0,-145.0,-170.0,-145.0};
   r.sell_offset=sell_offset[index];
   double nearby_radius[9]={30.0,480.0,980.0,130.0,55.0,55.0,90.0,5.0,5.0};
   r.nearby_radius=nearby_radius[index];
   int expiration_hours[9]={35,480,432,192,30,20,60,55,15};
   r.expiration_hours=expiration_hours[index];
   double stop_distance[9]={6100.0,1000.0,700.0,800.0,5300.0,10100.0,2250.0,1900.0,3900.0};
   r.stop_distance=stop_distance[index];
   double target_distance[9]={1450.0,4100.0,3300.0,4900.0,900.0,800.0,1450.0,1200.0,1350.0};
   r.target_distance=target_distance[index];
   double trail_distance[9]={1800.0,450.0,500.0,1300.0,495.0,500.0,450.0,1250.0,445.0};
   r.trail_distance=trail_distance[index];
   double trail_start[9]={1800.0,1400.0,400.0,1450.0,400.0,1200.0,900.0,650.0,355.0};
   r.trail_start=trail_start[index];
   double trail_limit[9]={5000.0,5000.0,5000.0,2000.0,5000.0,5000.0,5000.0,5000.0,5000.0};
   r.trail_limit=trail_limit[index];
   double trail_step[9]={0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
   r.trail_step=trail_step[index];
   double native_6d368[9]={700.0,400.0,2000.0,200.0,250.0,350.0,350.0,250.0,250.0};
   r.native_6d368=native_6d368[index];
   double native_6d370[9]={1600.0,1600.0,1000.0,1400.0,1900.0,1950.0,2800.0,1950.0,1850.0};
   r.native_6d370=native_6d370[index];
   double trigger_distance[9]={930.0,500.0,400.0,500.0,260.0,330.0,340.0,270.0,160.0};
   r.trigger_distance=trigger_distance[index];
   double locked_distance[9]={120.0,100.0,0.0,200.0,80.0,80.0,30.0,0.0,50.0};
   r.locked_distance=locked_distance[index];
   bool aux_hour1[9]={true,true,true,true,true,true,true,true,true};
   r.aux_hour1=aux_hour1[index];
   bool aux_scan50[9]={true,true,true,true,true,true,true,true,true};
   r.aux_scan50=aux_scan50[index];
   int aux_older[9]={14,1,7,14,0,0,12,15,1};
   r.aux_older=aux_older[index];
   int aux_recent[9]={12,5,4,6,0,0,17,3,9};
   r.aux_recent=aux_recent[index];
   double aux_offset[9]={22.0,22.0,0.0,32.0,0.0,0.0,45.0,16.0,46.0};
   r.aux_offset=aux_offset[index];
   return true;
}
#endif
