// Recovered function bodies, not the complete EA. Names are analysis names.
// Native source RVAs: 0xc080 (trend), 0xba40/0xc690 (closed candle).
#ifndef TWISTER_RECOVERED_FILTERS_MQH
#define TWISTER_RECOVERED_FILTERS_MQH

int TwisterRecoveredTrend(const double bid,const double &fast[],const double &slow[],
                         const double &long_fast[],const double &long_slow[],
                         const bool enabled,const bool both_groups,const bool slope)
{
   if(!enabled) return 1;
   if(ArraySize(fast)<3 || ArraySize(slow)<3 ||
      ArraySize(long_fast)<2 || ArraySize(long_slow)<2) return 0;
   bool first_buy=fast[0]<bid && slow[0]<fast[0];
   bool first_sell=bid<fast[0] && fast[0]<slow[0];
   if(slope)
   {
      first_buy=first_buy && fast[1]<fast[0];
      first_sell=first_sell && fast[0]<fast[1];
   }
   bool second_buy=long_slow[0]<long_fast[0] && long_fast[0]<bid;
   bool second_sell=long_fast[0]<long_slow[0] && bid<long_fast[0];
   if(both_groups)
   {
      if(first_buy && second_buy) return 1;
      return first_sell && second_sell ? -1 : 0;
   }
   if(first_buy || second_buy) return 1;
   return first_sell || second_sell ? -1 : 0;
}

bool TwisterRecoveredCandle(const bool buy,const double open,const double high,
                           const double low,const double close,const double point,
                           const double min_range_points,const double min_body_ratio,
                           const double max_wick_ratio)
{
   double range=high-low;
   if(range<0.0001) return false;
   if(buy ? close<=open : open<=close) return false;
   if(min_range_points>0.0 && range/point<min_range_points) return false;
   if(min_body_ratio>0.0 && MathAbs(close-open)/range<min_body_ratio) return false;
   if(max_wick_ratio>0.0)
   {
      double wick=buy ? MathMin(open,close)-low : high-MathMax(open,close);
      if(max_wick_ratio<wick/range) return false;
   }
   return true;
}

// RVA 0xc880, after CopyTickVolume(symbol,timeframe,1,3,volumes).
// Original init fixes v_223c0=1 and the local array has series indexing.
// Preserve the original behavior: a short/failed copy passes this filter.
bool TwisterRecoveredVolume(const bool enabled,const int copied,
                           const long current,const long previous,const double ratio)
{
   if(!enabled || copied<3) return true;
   return previous>0 && (long)((double)previous*ratio)<=current;
}
#endif
