// Evaluator 26f9e..29c88: a complete entry loop, before display/housekeeping.
#ifndef BOT3_ENTRY_LOOP_MQH
#define BOT3_ENTRY_LOOP_MQH
#include "Bot3EntrySubmissionLive.mqh"
#include "Bot3EntryLevels.mqh"
#include "Bot3PendingLimitStage.mqh"
#include "Bot3VolumeRuntime.mqh"

struct Bot3EntryLoopSettings
{
   uchar buy_enabled,sell_enabled,volume_enabled,delete_expired;
   uchar skip_position_gate,replace_at_equal;
   Bot3EntrySubmissionFlags submission;
   ENUM_TIMEFRAMES confirmation_frame;
   int older_width,recent_width,last_shift,expiration_setting;
   uint expiration_seconds;
   double gap_points,buy_offset,sell_offset,radius,step_reference;
   int maximum_positions;
   double maximum_group_pending;
};
struct Bot3EntryLoopState
{
   double candidate_buy,candidate_sell,rounded_buy,rounded_sell,active_step;
};

void Bot3DeleteExpiredEntryOrders(const uint &seconds,Bot3NfpExecution &execution)
{
   const int total=OrdersTotal();
   for(int index=total;index>=0;index--)
   {
      execution.last_ticket=OrderGetTicket(index);
      if(execution.last_ticket==0) continue;
      if(OrderGetInteger(ORDER_MAGIC)!=(long)execution.strategy_magic) continue;
      if(OrderGetString(ORDER_SYMBOL)!=execution.symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)!=4 && OrderGetInteger(ORDER_TYPE)!=5) continue;
      const long now=(long)TimeCurrent();
      const long created=OrderGetInteger((ENUM_ORDER_PROPERTY_INTEGER)1);
      if(now>=created+(long)seconds)
         Bot3DeletePending(execution.trade,execution.options,execution.last_ticket);
   }
}

bool Bot3EntryPositionExists(const bool buy,Bot3NfpExecution &execution)
{
   if(PositionsTotal()<=0) return false;
   int index=0;
   do
   {
      execution.last_ticket=PositionGetTicket(index);
      if(execution.last_ticket!=0 &&
         PositionGetInteger(POSITION_TYPE)==(buy ? 0 : 1) &&
         PositionGetInteger(POSITION_MAGIC)==(long)execution.strategy_magic &&
         PositionGetString(POSITION_SYMBOL)==execution.symbol) return true;
      index++;
   } while(index<PositionsTotal());
   return false;
}

double Bot3EntryPendingExtreme(const bool buy,Bot3NfpExecution &execution)
{
   double extreme=buy ? 9999.0 : 0.0;
   for(int index=OrdersTotal();index>=0;index--)
   {
      execution.last_ticket=OrderGetTicket(index);
      if(execution.last_ticket==0) continue;
      if(OrderGetInteger(ORDER_MAGIC)!=(long)execution.strategy_magic) continue;
      if(OrderGetString(ORDER_SYMBOL)!=execution.symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)!=(buy ? 4 : 5)) continue;
      const double price=OrderGetDouble(ORDER_PRICE_OPEN);
      if(buy ? price<extreme : extreme<price) extreme=OrderGetDouble(ORDER_PRICE_OPEN);
   }
   return extreme;
}

bool Bot3EntryPriceBlocked(const bool buy,const double price,Bot3NfpExecution &execution)
{
   for(int index=OrdersTotal();index>=0;index--)
   {
      execution.last_ticket=OrderGetTicket(index);
      if(execution.last_ticket==0) continue;
      if(OrderGetInteger(ORDER_MAGIC)!=(long)execution.strategy_magic) continue;
      if(OrderGetString(ORDER_SYMBOL)!=execution.symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)!=(buy ? 4 : 5)) continue;
      const double existing=OrderGetDouble(ORDER_PRICE_OPEN);
      if(buy ? existing<=price : price<=existing) return true;
   }
   return false;
}

int Bot3CountEntryPositions(const bool buy,Bot3NfpExecution &execution)
{
   int count=0;
   for(int index=PositionsTotal();index>=0;index--)
   {
      execution.last_ticket=PositionGetTicket(index);
      if(execution.last_ticket==0) continue;
      if(PositionGetInteger(POSITION_MAGIC)!=(long)execution.strategy_magic) continue;
      if(PositionGetString(POSITION_SYMBOL)!=execution.symbol) continue;
      if(PositionGetInteger(POSITION_TYPE)==(buy ? 0 : 1)) count++;
   }
   return count;
}

int Bot3CountEntryGroupOrders(const bool buy,const long &accepted[],Bot3NfpExecution &execution)
{
   int count=0;
   for(int index=OrdersTotal();index>=0;index--)
   {
      execution.last_ticket=OrderGetTicket(index);
      if(execution.last_ticket==0) continue;
      bool matched=false;
      for(int i=0;i<15;i++)
         if(OrderGetInteger(ORDER_MAGIC)==accepted[i]) { matched=true;break; }
      if(!matched) continue;
      if(OrderGetString(ORDER_SYMBOL)!=execution.symbol) continue;
      if(OrderGetInteger(ORDER_TYPE)==(buy ? 4 : 5)) count++;
   }
   return count;
}

bool Bot3EntryRiskLimitReached(const bool buy,const Bot3EntryLoopSettings &settings,
                               const long &accepted[],Bot3NfpExecution &execution)
{
   const int positions=Bot3CountEntryPositions(buy,execution);
   if(positions>=settings.maximum_positions) return true;
   const int orders=Bot3CountEntryGroupOrders(buy,accepted,execution);
   return !((double)orders<settings.maximum_group_pending);
}

void Bot3ProcessEntryDirection(const bool buy,const int &maximum_pending,
                               const Bot3EntryLoopSettings &settings,Bot3EntryLoopState &state,
                               const Bot3PendingRestoreSettings &restore,const double &unit,
                               Bot3NfpExecution &execution,const double &volumes[],
                               const uint &strategy_index,Bot3PendingQueue &queue)
{
   if(settings.skip_position_gate==0 && Bot3EntryPositionExists(buy,execution)) return;
   double candidate;
   if(buy)
      candidate=Bot3EntryLevel(true,execution.symbol,settings.confirmation_frame,
                               settings.confirmation_frame,settings.older_width,
                               settings.recent_width,settings.last_shift,execution.reference_b,
                               settings.gap_points,unit,execution.strategy_magic,
                               settings.buy_offset,settings.sell_offset,settings.radius,
                               execution.last_ticket);
   else
      candidate=Bot3EntryLevel(false,execution.symbol,settings.confirmation_frame,
                               settings.confirmation_frame,settings.older_width,
                               settings.recent_width,settings.last_shift,execution.reference_a,
                               settings.gap_points,unit,execution.strategy_magic,
                               settings.buy_offset,settings.sell_offset,settings.radius,
                               execution.last_ticket);
   if(buy) state.candidate_buy=candidate;
   else state.candidate_sell=candidate;
   if(Bot3NearbyPending(buy,buy ? state.candidate_buy : state.candidate_sell,
                        execution.symbol,execution.strategy_magic,settings.buy_offset,
                        settings.sell_offset,unit,settings.radius,execution.last_ticket)) return;

   const int count=Bot3CountPendingForLimit(buy,execution.strategy_magic,execution.symbol,execution.last_ticket);
   const double saved_candidate=buy ? state.candidate_buy : state.candidate_sell;
   if(count==maximum_pending)
   {
      const double extreme=Bot3EntryPendingExtreme(buy,execution);
      if((buy ? extreme<saved_candidate : saved_candidate<extreme) ||
         (settings.replace_at_equal&1)==0) return;
   }
   uint digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   if(buy) state.rounded_buy=Bot3RoundPrice(state.candidate_buy,digits);
   else state.rounded_sell=Bot3RoundPrice(state.candidate_sell,digits);
   if((buy ? state.rounded_buy : state.rounded_sell)==0.0) return;
   state.active_step=settings.step_reference;
   digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   const double shifted=buy
      ? Bot3QueueSum(Bot3QueueProduct(settings.buy_offset,unit),state.rounded_buy)
      : Bot3SubmissionDifference(state.rounded_sell,Bot3QueueProduct(settings.sell_offset,unit));
   const double base_price=Bot3RoundPrice(shifted,digits);
   if(Bot3EntryPriceBlocked(buy,base_price,execution)) return;
   Bot3SubmitEntryAfterPriceLive(buy,base_price,settings.submission,restore,unit,
                                execution,volumes,strategy_index,queue);
}

void Bot3RunEntryLoop(const int &maximum_pending,const Bot3EntryLoopSettings &settings,
                      Bot3EntryLoopState &state,const Bot3VolumeSettings &volume_settings,
                      Bot3VolumeState &volume_state,const bool reset_on_withdrawal,
                      const string &peak_key,const string &time_key,long &last_check,
                      long &last_deal_time,const string &suffix,const double &weight_denominator,
                      const uchar &enabled[],const double &unit,
                      const uint &strategy_index,double &volumes[],
                      Bot3PendingRestoreSettings &restore,Bot3NfpExecution &execution,
                      Bot3PendingQueue &queue)
{
   if(maximum_pending<=0) return;
   const int seed=execution.magic_base;long accepted[15];
   for(int i=0;i<15;i++) accepted[i]=(long)(int)((uint)seed+(uint)(i+1));
   const uchar buy_enabled=settings.buy_enabled,sell_enabled=settings.sell_enabled;
   int iteration=0;
   do
   {
      Bot3PrepareVolumeRuntime(restore.sl_distance,settings.volume_enabled!=0 ? 100 : 0,
                               execution.symbol,suffix,volume_settings,volume_state,
                               reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,
                               weight_denominator,enabled,strategy_index,volumes);
      if(volumes[strategy_index]>volume_settings.max_lots)
         volumes[strategy_index]=volume_settings.max_lots;
      if(settings.expiration_setting>0)
      {
         const long now=(long)TimeCurrent();
         restore.expiration_base=(datetime)(now+(long)settings.expiration_seconds);
      }
      if(settings.delete_expired!=0)
      {
         restore.expiration_base=0;
         Bot3DeleteExpiredEntryOrders(settings.expiration_seconds,execution);
      }
      if(Bot3EntryRiskLimitReached(true,settings,accepted,execution))
         Bot3CancelDistantPending(1,true,execution.strategy_magic,execution.symbol,
                                  execution.reference_b,execution.gap,execution.last_ticket,
                                  execution.trade,execution.options);
      else if(buy_enabled!=0)
         Bot3ProcessEntryDirection(true,maximum_pending,settings,state,restore,unit,
                                   execution,volumes,strategy_index,queue);
      if(Bot3EntryRiskLimitReached(false,settings,accepted,execution))
         Bot3CancelDistantPending(1,false,execution.strategy_magic,execution.symbol,
                                  execution.reference_a,execution.gap,execution.last_ticket,
                                  execution.trade,execution.options);
      else if(sell_enabled!=0)
         Bot3ProcessEntryDirection(false,maximum_pending,settings,state,restore,unit,
                                   execution,volumes,strategy_index,queue);
      iteration++;
   } while(iteration<maximum_pending);
}
#endif
