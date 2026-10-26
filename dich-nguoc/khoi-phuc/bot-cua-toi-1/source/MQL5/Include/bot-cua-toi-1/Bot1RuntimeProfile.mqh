// Runtime strategy profile loading from the verified native assignment blocks.
// Only profile fields and the supplied random seed are changed.
#ifndef BOT1_RUNTIME_PROFILE_MQH
#define BOT1_RUNTIME_PROFILE_MQH
#include "Bot1BaseDistances.mqh"

struct Bot1ProfileAdjustments
{
   double randomization;
   double price_delta;
   double stop_delta;
   double target_delta;
   double trail_delta;
};

struct Bot1ProfileRuntimeState
{
   uint random_seed;
};

double Bot1ProfileSum(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left+right;
}

double Bot1ProfileProduct(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left*right;
}

double Bot1ProfileDifference(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left-right;
}

uint Bot1ProfileNextSeed(const uint seed)
{
   return (uint)((ulong)seed*(ulong)214013+(ulong)2531011);
}

void Bot1LoadRuntimeProfile(const uint index,const bool use_hl_trailing,
                            const Bot1ProfileAdjustments &adjustments,
                            Bot1DistanceInputs &inputs,Bot1ProfileRuntimeState &state)
{
   if(index>=8) return;
   Bot1DistanceInputs base;
   ZeroMemory(base);
   if(!Bot1LoadBaseDistances((int)index,use_hl_trailing,base)) return;

   inputs.entry=base.entry;
   inputs.reference=base.reference;
   inputs.buy_offset=base.buy_offset;
   inputs.sell_offset=base.sell_offset;
   inputs.nearby_radius=base.nearby_radius;
   inputs.expiration_hours=base.expiration_hours;
   inputs.stop_distance=base.stop_distance;
   inputs.target_distance=base.target_distance;
   inputs.trail_distance=base.trail_distance;
   inputs.trail_start=base.trail_start;
   inputs.trail_limit=base.trail_limit;
   inputs.trail_step=base.trail_step;
   inputs.aux_hour1=base.aux_hour1;
   inputs.aux_scan50=base.aux_scan50;
   inputs.aux_older=base.aux_older;
   inputs.aux_recent=base.aux_recent;
   inputs.aux_offset=base.aux_offset;

   uint seed=state.random_seed;
   bool randomized=adjustments.randomization>0.0;
   double delta[8];
   ZeroMemory(delta);
   if(randomized)
   {
      double doubled=Bot1ProfileSum(adjustments.randomization,adjustments.randomization);
      double negative=Bot1ProfileDifference(0.0,adjustments.randomization);
      for(int n=1;n<=7;n++)
      {
         seed=Bot1ProfileNextSeed(seed);
         uint word=(seed>>16)&(uint)32767;
         double scaled=Bot1ProfileProduct((double)word,doubled);
         double fraction=Bot1ProfileProduct(scaled,0.000030517578125);
         delta[n]=Bot1ProfileSum(fraction,negative);
      }
   }
   state.random_seed=seed;

   if(randomized)
   {
      inputs.buy_offset=Bot1ProfileSum(Bot1ProfileSum(base.buy_offset,adjustments.price_delta),delta[1]);
      inputs.sell_offset=Bot1ProfileSum(Bot1ProfileSum(adjustments.price_delta,base.sell_offset),delta[2]);
      inputs.stop_distance=Bot1ProfileSum(Bot1ProfileSum(adjustments.stop_delta,base.stop_distance),delta[3]);
      inputs.target_distance=Bot1ProfileSum(delta[4],Bot1ProfileSum(adjustments.target_delta,base.target_distance));
      inputs.trail_distance=Bot1ProfileSum(delta[5],Bot1ProfileSum(adjustments.trail_delta,base.trail_distance));
      inputs.trail_start=Bot1ProfileSum(delta[6],base.trail_start);
      inputs.trail_limit=Bot1ProfileSum(delta[7],base.trail_limit);
   }
   else
   {
      inputs.buy_offset=Bot1ProfileSum(base.buy_offset,adjustments.price_delta);
      inputs.sell_offset=Bot1ProfileSum(Bot1ProfileSum(adjustments.price_delta,base.sell_offset),0.0);
      inputs.stop_distance=Bot1ProfileSum(adjustments.stop_delta,base.stop_distance);
      inputs.target_distance=Bot1ProfileSum(adjustments.target_delta,base.target_distance);
      inputs.trail_distance=Bot1ProfileSum(adjustments.trail_delta,base.trail_distance);
      inputs.trail_start=base.trail_start;
      inputs.trail_limit=base.trail_limit;
   }
}
#endif
