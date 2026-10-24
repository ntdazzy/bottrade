// Base strategy distances, from native assignment blocks.
// Applies only when randomization and additional distance adjustments are zero.
// Updates listed profile fields only; caller supplies the remaining global inputs.
#ifndef BOT1_BASE_DISTANCES_MQH
#define BOT1_BASE_DISTANCES_MQH
#include "Bot1DistanceSettings.mqh"
bool Bot1LoadBaseDistances(const int index,const bool use_hl_trailing,Bot1DistanceInputs &r)
{
   if(!Bot1LoadEntryProfile(index,r.entry)) return false;
   double reference[8]={26.0,25.5,37.5,34.5,28.0,33.0,27.5,22.0};
   r.reference=reference[index];
   double buy_offset[8]={-140.0,-50.0,-130.0,-250.0,-170.0,20.0,-40.0,-130.0};
   r.buy_offset=buy_offset[index];
   double sell_offset[8]={-290.0,-130.0,-30.0,-130.0,-70.0,-70.0,-140.0,-120.0};
   r.sell_offset=sell_offset[index];
   double nearby_radius[8]={680.0,230.0,980.0,680.0,480.0,30.0,280.0,980.0};
   r.nearby_radius=nearby_radius[index];
   int expiration_hours[8]={408,384,408,48,480,384,240,432};
   r.expiration_hours=expiration_hours[index];
   double stop_distance_0[8]={1300.0,1000.0,1200.0,1300.0,600.0,1000.0,1200.0,600.0};
   double stop_distance_1[8]={1500.0,1600.0,1800.0,1600.0,1100.0,1600.0,1200.0,700.0};
   r.stop_distance=use_hl_trailing ? stop_distance_1[index] : stop_distance_0[index];
   double target_distance[8]={1700.0,3900.0,1800.0,1700.0,1700.0,1900.0,1600.0,4900.0};
   r.target_distance=target_distance[index];
   double trail_distance_0[8]={800.0,950.0,750.0,800.0,500.0,600.0,600.0,600.0};
   double trail_distance_1[8]={600.0,950.0,750.0,800.0,500.0,600.0,600.0,600.0};
   r.trail_distance=use_hl_trailing ? trail_distance_1[index] : trail_distance_0[index];
   double trail_start_0[8]={500.0,100.0,600.0,500.0,300.0,500.0,200.0,350.0};
   double trail_start_1[8]={550.0,100.0,600.0,500.0,300.0,500.0,200.0,350.0};
   r.trail_start=use_hl_trailing ? trail_start_1[index] : trail_start_0[index];
   double trail_limit[8]={200.0,1600.0,200.0,200.0,200.0,1000.0,4400.0,2000.0};
   r.trail_limit=trail_limit[index];
   double trail_step[8]={0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
   r.trail_step=trail_step[index];
   bool aux_hour1[8]={true,true,true,true,true,true,true,true};
   r.aux_hour1=aux_hour1[index];
   bool aux_scan50[8]={true,true,true,true,true,true,true,true};
   r.aux_scan50=aux_scan50[index];
   int aux_older[8]={2,3,1,5,1,1,5,17};
   r.aux_older=aux_older[index];
   int aux_recent[8]={3,3,6,6,4,2,2,1};
   r.aux_recent=aux_recent[index];
   double aux_offset[8]={20.0,20.0,5.0,0.0,6.0,0.0,14.0,38.0};
   r.aux_offset=aux_offset[index];
   return true;
}
#endif
