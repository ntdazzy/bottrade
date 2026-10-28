#ifndef BOT1_STARTUP_TRADING_STATE_MQH
#define BOT1_STARTUP_TRADING_STATE_MQH
#include "Bot1Preparation.mqh"
#include "Bot1EntryLoop.mqh"
#include "Bot1EntryLevelCache.mqh"
#include "Bot1PositionManagement.mqh"
#include "Bot1ReleaseFilters.mqh"

struct Bot1StartupTradingState
{
   uchar native_62555;
   long week_bar;
   int timed_delay_seconds;
};

#ifndef BOT1_STARTUP_NUMBER_EXTERNAL
string Bot1StartupNumber(const double value) { return (string)value; }
#endif

// OnInit after the first preparation, 0x3cab..0x4e77. The entry-level
// children use their own source; object names and the panel follow later.
void Bot1InitializeTradingState(const Bot1PreparationInputs &inputs,Bot1PreparationState &p,
                                const int &magic,Bot1EntryLoopState &entry,
                                Bot1NfpFilterState &nfp,Bot1ReleaseFilterState &interest,
                                Bot1ReleaseFilterState &cpi,Bot1PositionManagementState &management,
                                Bot1PendingQueue &queue,Bot1LevelCacheSettings &levels,
                                double &minimum_spread,uchar &friday_closed,
                                double &volumes[],ulong &last_ticket,Bot1StartupTradingState &state)
{
   if(p.native_62414<0) state.native_62555=0;
   p.strategy_index=0;
   Bars(inputs.symbol,(ENUM_TIMEFRAMES)p.entry_frame);
   Bars(inputs.symbol,(ENUM_TIMEFRAMES)p.native_6248c);
   TimeCurrent();
   p.spread=Bot1QueueDifference(p.tick.ask,p.tick.bid);
   volumes[p.strategy_index]=Bot1RoundPrice(MathFloor(p.native_62530*100.0)/100.0,2);
   const double step=SymbolInfoDouble(inputs.symbol,SYMBOL_VOLUME_STEP);
   double volume=volumes[p.strategy_index];
   if(step==0.1)
   {
      volume=Bot1RoundPrice(MathFloor(p.native_62530*10.0)/10.0,1);
      volumes[p.strategy_index]=volume;
      if(volume<0.1) { volumes[p.strategy_index]=0.1;volume=0.1; }
   }
   if(volume<SymbolInfoDouble(inputs.symbol,SYMBOL_VOLUME_MIN))
   {
      const string value=Bot1StartupNumber(SymbolInfoDouble(inputs.symbol,SYMBOL_VOLUME_MIN));
      Print("Minimum lotsize for this broker is "+value+"lots!!");
      volumes[p.strategy_index]=SymbolInfoDouble(inputs.symbol,SYMBOL_VOLUME_MIN);
   }
   volume=volumes[p.strategy_index];
   if(SymbolInfoDouble(inputs.symbol,SYMBOL_VOLUME_MAX)<volume)
   {
      const string value=Bot1StartupNumber(SymbolInfoDouble(inputs.symbol,SYMBOL_VOLUME_MAX));
      Print("Maximum lotsize for this broker is "+value+"lots!!");
      volumes[p.strategy_index]=SymbolInfoDouble(inputs.symbol,SYMBOL_VOLUME_MAX);
   }
   double change=Bot1QueueProduct(p.min_change,p.unit);
   if(SymbolInfoDouble(inputs.symbol,SYMBOL_POINT)>change)
      p.min_change=SymbolInfoDouble(inputs.symbol,SYMBOL_POINT)/p.unit;
   AccountInfoDouble(ACCOUNT_BALANCE);
   const long stops=SymbolInfoInteger(inputs.symbol,SYMBOL_TRADE_STOPS_LEVEL);
   p.stop_min_price=Bot1QueueProduct((double)stops,SymbolInfoDouble(inputs.symbol,SYMBOL_POINT));
   const long freeze=SymbolInfoInteger(inputs.symbol,SYMBOL_TRADE_FREEZE_LEVEL);
   p.freeze_min_price=Bot1QueueProduct((double)freeze,SymbolInfoDouble(inputs.symbol,SYMBOL_POINT));
   double stop=p.stop_distance;
   if(stop<=0.0) { p.stop_distance=1.0;stop=1.0; }
   double target=p.target_distance;
   if(target<=0.0) { p.target_distance=1.0;target=1.0; }
   if(p.trigger_distance<p.locked_distance) p.locked_distance=Bot1QueueSum(p.trigger_distance,0.1);
   const double freeze_units=p.freeze_min_price/p.unit;
   if((double)p.freeze_buffer<freeze_units) p.freeze_buffer=(int)freeze_units;
   if(p.trail_distance!=0.0 && p.trail_distance<freeze_units) p.trail_distance=freeze_units;
   if(p.trail_distance!=0.0 && p.trail_distance<p.stop_min_price/p.unit)
      p.trail_distance=p.stop_min_price/p.unit;
   if(p.native_624f8>0.0)
   {
      if(p.native_62500<freeze_units) p.native_62500=freeze_units;
      if(p.native_62500<p.stop_min_price/p.unit) p.native_62500=p.stop_min_price/p.unit;
   }
   const double twice_stop=Bot1QueueSum(p.stop_min_price,p.stop_min_price)/p.unit;
   if(stop<twice_stop) p.stop_distance=twice_stop;
   if(target<twice_stop) p.target_distance=twice_stop;
   if(p.gap_points<twice_stop) p.gap_points=twice_stop;
   if(p.older_width<1) p.older_width=1;
   if(p.recent_width<1) p.recent_width=1;
   if(p.gap_points<0.1) p.gap_points=0.1;
   p.expiration_seconds=(uint)p.expiration_hours*(uint)3600;
   long expiry=0;
   if(p.expiration_hours>=1) expiry=(long)TimeCurrent()+(long)p.expiration_seconds;
   p.expiration= p.virtual_expiration!=0 ? 0 : expiry;
   interest.blocked=0;
   nfp.blocked=0;
   cpi.blocked=0;
   TimeCurrent();
   state.week_bar=(long)iTime(inputs.symbol,PERIOD_W1,1);
   iTime(inputs.symbol,PERIOD_M1,1);
   iTime(inputs.symbol,PERIOD_M1,1);
   if(p.max_spread<minimum_spread) minimum_spread=p.max_spread;
   ENUM_TIMEFRAMES confirmation=(ENUM_TIMEFRAMES)inputs.entry.confirmation_frame;
   entry.candidate_buy=Bot1EntryLevel(true,inputs.symbol,confirmation,
                                      confirmation,p.older_width,p.recent_width,p.last_shift,
                                      p.tick.ask,p.gap_points,p.unit,magic,p.buy_offset,p.sell_offset,
                                      p.nearby_radius,last_ticket);
   confirmation=(ENUM_TIMEFRAMES)inputs.entry.confirmation_frame;
   entry.candidate_sell=Bot1EntryLevel(false,inputs.symbol,confirmation,
                                       confirmation,p.older_width,p.recent_width,p.last_shift,
                                       p.tick.bid,p.gap_points,p.unit,magic,p.buy_offset,p.sell_offset,
                                       p.nearby_radius,last_ticket);
   const uint buy_digits=(uint)SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS);
   entry.rounded_buy=Bot1RoundPrice(entry.candidate_buy,buy_digits);
   const uint sell_digits=(uint)SymbolInfoInteger(inputs.symbol,SYMBOL_DIGITS);
   entry.rounded_sell=Bot1RoundPrice(entry.candidate_sell,sell_digits);
   levels.blocked=1;
   management.counter=0;
   nfp.notice=0;
   state.timed_delay_seconds=(int)Bot1QueueProduct(p.native_624f8,60.0);
   const long last_freeze=SymbolInfoInteger(inputs.symbol,SYMBOL_TRADE_FREEZE_LEVEL);
   const double point=SymbolInfoDouble(inputs.symbol,SYMBOL_POINT);
   const double maximum=p.native_62538;
   levels.blocked=0;
   management.current_stop=0.0;
   p.freeze_min_price=Bot1QueueProduct((double)last_freeze,point);
   if(p.native_62530<0.0) p.native_62530=0.01;
   if(SymbolInfoDouble(inputs.symbol,SYMBOL_VOLUME_MAX)<maximum)
      p.native_62538=SymbolInfoDouble(inputs.symbol,SYMBOL_VOLUME_MAX);
   if(management.table.guard==1) ArrayInitialize(management.table.rows,0.0);
   if(queue.enabled==1) ArrayInitialize(queue.orders,0.0);
   for(int i=0;i<100;i++) { queue.orders[i][1]=0.0;queue.orders[i][0]=0.0; }
   friday_closed=0;
}
#endif
