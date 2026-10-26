// Runtime strategy profile loading from the verified native assignment blocks.
// This function changes only the listed profile fields and the supplied seed/state fields.
#ifndef BOT3_RUNTIME_PROFILE_MQH
#define BOT3_RUNTIME_PROFILE_MQH
#include "Bot3Preparation.mqh"
#include "Bot3BaseDistances.mqh"

struct Bot3ProfileAdjustments
{
   double randomization;
   double price_delta;
   double stop_delta;
   double target_delta;
   double trail_delta;
   double aux_delta;
   double lock_delta;
};

struct Bot3ProfileRuntimeState
{
   uint random_seed;
   int native_6d324;
   int native_6d3c0;
};

double Bot3ProfileSum(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left+right;
}

double Bot3ProfileProduct(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left*right;
}

double Bot3ProfileDifference(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left-right;
}

uint Bot3ProfileNextSeed(const uint seed)
{
   return (uint)((ulong)seed*(ulong)214013+(ulong)2531011);
}

void Bot3LoadRuntimeProfile(const uint index,const Bot3ProfileAdjustments &adjustments,
                            Bot3PreparationInputs &inputs,Bot3ProfileRuntimeState &state)
{
   if(index>=9) return;

   Bot3DistanceInputs base;
   ZeroMemory(base);
   if(!Bot3LoadBaseDistances((int)index,base)) return;

   int indicator_period[9]={16,41,5,16,24,20,28,11,12};
   int indicator_timeframe[9]={16408,16408,16408,16408,16408,16408,16385,16408,16408};
   int native_6d2e0[9]={5,1,1,2,3,5,5,5,3};
   int management_timeframe[9]={5,99,99,99,99,5,5,20,99};
   int native_6d324[9]={1,1,1,5,1,1,1,1,1};
   int native_6d3c0[9]={300,700,100,400,100,100,1000,1200,1500};

   inputs.entry=base.entry;
   inputs.nearby_radius=base.nearby_radius;
   inputs.expiration_hours=base.expiration_hours;
   inputs.trail_step=base.trail_step;
   inputs.aux_hour1=(uchar)(base.aux_hour1 ? 1 : 0);
   inputs.aux_scan50=(uchar)(base.aux_scan50 ? 1 : 0);
   inputs.aux_older=base.aux_older;
   inputs.aux_recent=base.aux_recent;
   inputs.aux_offset=base.aux_offset;
   inputs.indicator_period=indicator_period[index];
   inputs.indicator_timeframe=indicator_timeframe[index];
   inputs.native_6d2e0=native_6d2e0[index];
   inputs.management_timeframe=management_timeframe[index];
   state.native_6d324=native_6d324[index];
   state.native_6d3c0=native_6d3c0[index];

   uint seed=state.random_seed;
   bool randomized=adjustments.randomization>0.0;
   double delta[12];
   ZeroMemory(delta);
   if(randomized)
   {
      double doubled=Bot3ProfileSum(adjustments.randomization,adjustments.randomization);
      double negative=Bot3ProfileDifference(0.0,adjustments.randomization);
      for(int n=1;n<=11;n++)
      {
         seed=Bot3ProfileNextSeed(seed);
         uint word=(seed>>16)&(uint)32767;
         double scaled=Bot3ProfileProduct((double)word,doubled);
         double fraction=Bot3ProfileProduct(scaled,0.000030517578125);
         delta[n]=Bot3ProfileSum(fraction,negative);
      }
      state.random_seed=seed;
   }
   else
   {
      state.random_seed=seed;
   }

   if(randomized)
   {
      inputs.buy_offset=Bot3ProfileSum(Bot3ProfileSum(base.buy_offset,adjustments.price_delta),delta[1]);
      inputs.sell_offset=Bot3ProfileSum(Bot3ProfileSum(adjustments.price_delta,base.sell_offset),delta[2]);
      inputs.stop_distance=Bot3ProfileSum(Bot3ProfileSum(adjustments.stop_delta,base.stop_distance),delta[3]);
      if(index==2 || index==3)
         inputs.target_distance=Bot3ProfileSum(Bot3ProfileSum(adjustments.target_delta,base.target_distance),delta[4]);
      else
         inputs.target_distance=Bot3ProfileSum(delta[4],Bot3ProfileSum(adjustments.target_delta,base.target_distance));
      inputs.trail_distance=Bot3ProfileSum(delta[5],Bot3ProfileSum(adjustments.trail_delta,base.trail_distance));
      inputs.trail_start=Bot3ProfileSum(delta[6],base.trail_start);
      inputs.trail_limit=Bot3ProfileSum(delta[7],base.trail_limit);
      inputs.native_6d370=Bot3ProfileSum(delta[8],base.native_6d370);
      inputs.native_6d368=Bot3ProfileSum(delta[9],Bot3ProfileSum(adjustments.aux_delta,base.native_6d368));
      inputs.trigger_distance=Bot3ProfileSum(delta[10],base.trigger_distance);
      if(index==2 || index==7)
         inputs.locked_distance=Bot3ProfileSum(Bot3ProfileSum(base.locked_distance,adjustments.lock_delta),delta[11]);
      else
         inputs.locked_distance=Bot3ProfileSum(Bot3ProfileSum(adjustments.lock_delta,base.locked_distance),delta[11]);
   }
   else
   {
      inputs.buy_offset=Bot3ProfileSum(base.buy_offset,adjustments.price_delta);
      inputs.sell_offset=Bot3ProfileSum(Bot3ProfileSum(adjustments.price_delta,base.sell_offset),0.0);
      inputs.stop_distance=Bot3ProfileSum(adjustments.stop_delta,base.stop_distance);
      inputs.target_distance=Bot3ProfileSum(adjustments.target_delta,base.target_distance);
      inputs.trail_distance=Bot3ProfileSum(adjustments.trail_delta,base.trail_distance);
      inputs.trail_start=base.trail_start;
      inputs.trail_limit=base.trail_limit;
      inputs.native_6d368=Bot3ProfileSum(adjustments.aux_delta,base.native_6d368);
      inputs.native_6d370=base.native_6d370;
      inputs.trigger_distance=base.trigger_distance;
      if(index==2 || index==7)
         inputs.locked_distance=Bot3ProfileSum(Bot3ProfileSum(base.locked_distance,adjustments.lock_delta),0.0);
      else
         inputs.locked_distance=Bot3ProfileSum(Bot3ProfileSum(adjustments.lock_delta,base.locked_distance),0.0);
   }
}
#endif
