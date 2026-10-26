// Numeric preparation adapter. Market/indicator replies are supplied by the caller.
// This is a component, not the bot's event loop or trading code.
#ifndef BOT1_PREPARATION_NUMERIC_MQH
#define BOT1_PREPARATION_NUMERIC_MQH
#include "Bot1DistanceSettings.mqh"

struct Bot1PreparationMarket
{
   double indicator_values[];
   bool indicator_copy_ok;
   bool tick_ok;
   MqlTick tick;
   long now;
   double point;
   int digits;
   long stops_level;
   long freeze_level;
};

struct Bot1PreparationNumericState
{
   uint strategy_index;
   double scale,lot_scale,unit,spread;
   double stop_min_price,freeze_min_price;
   uint expiration_seconds;
   long expiration;
   Bot1Distances distances;
};

bool Bot1PrepareNumeric(const uint strategy_index,
                        const Bot1DistanceInputs &inputs,
                        const Bot1PreparationMarket &market,
                        Bot1PreparationNumericState &state)
{
   if(!market.indicator_copy_ok || !market.tick_ok) return false;
   if(ArraySize(market.indicator_values)<2)
   {
      double unused=market.indicator_values[1];
      state.scale=unused;
      return false;
   }
   Bot1DistanceContext context;
   context.sample=market.indicator_values[0];
   context.point=market.point;
   context.digits=market.digits;
   context.stops_level=market.stops_level;
   context.freeze_level=market.freeze_level;
   context.bid=market.tick.bid;
   context.ask=market.tick.ask;
   context.now=market.now;
   if(!Bot1PrepareDistances(inputs,context,state.distances)) return false;
   state.strategy_index=strategy_index;
   state.scale=state.distances.scale;
   state.lot_scale=state.distances.lot_scale;
   state.unit=state.distances.unit;
   state.spread=state.distances.spread;
   state.stop_min_price=state.distances.stop_min_price;
   state.freeze_min_price=state.distances.freeze_min_price;
   state.expiration_seconds=state.distances.expiration_seconds;
   state.expiration=state.distances.expiration;
   return true;
}
#endif
