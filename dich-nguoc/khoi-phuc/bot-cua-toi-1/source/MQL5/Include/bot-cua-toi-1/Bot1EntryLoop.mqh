// Evaluator 1ca24..1e94f: a complete entry loop, before display/housekeeping.
#ifndef BOT1_ENTRY_LOOP_MQH
#define BOT1_ENTRY_LOOP_MQH
#include "Bot1EntrySubmissionLive.mqh"
#include "Bot1EntryLevels.mqh"
#include "Bot1OrderScan.mqh"
#include "Bot1VolumeRuntime.mqh"

struct Bot1EntryLoopSettings
{
   uchar buy_enabled,sell_enabled,volume_enabled,delete_expired;
   uchar skip_position_gate,replace_at_equal;
   Bot1EntrySubmissionFlags submission;
   ENUM_TIMEFRAMES confirmation_frame;
   int older_width,recent_width,last_shift,expiration_setting;
   uint expiration_seconds;
   double gap_points,buy_offset,sell_offset,radius,step_reference;
};
struct Bot1EntryLoopState
{
   double candidate_buy,candidate_sell,rounded_buy,rounded_sell,active_step;
};

void Bot1DeleteExpiredEntryOrders(const uint &seconds,Bot1NfpExecution &execution)
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
         Bot1DeletePending(execution.trade,execution.options,execution.last_ticket);
   }
}

bool Bot1EntryPositionExists(const bool buy,Bot1NfpExecution &execution)
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

double Bot1EntryPendingExtreme(const bool buy,Bot1NfpExecution &execution)
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

void Bot1ProcessEntryDirection(const bool buy,const int &maximum_pending,
                               const Bot1EntryLoopSettings &settings,Bot1EntryLoopState &state,
                               const Bot1PendingRestoreSettings &restore,const double &unit,
                               Bot1NfpExecution &execution,const double &volumes[],
                               const uint &strategy_index,Bot1PendingQueue &queue)
{
   if(settings.skip_position_gate==0 && Bot1EntryPositionExists(buy,execution)) return;
   double candidate;
   if(buy)
      candidate=Bot1EntryLevel(true,execution.symbol,settings.confirmation_frame,
                               settings.confirmation_frame,settings.older_width,
                               settings.recent_width,settings.last_shift,execution.reference_b,
                               settings.gap_points,unit,execution.strategy_magic,
                               settings.buy_offset,settings.sell_offset,settings.radius,
                               execution.last_ticket);
   else
      candidate=Bot1EntryLevel(false,execution.symbol,settings.confirmation_frame,
                               settings.confirmation_frame,settings.older_width,
                               settings.recent_width,settings.last_shift,execution.reference_a,
                               settings.gap_points,unit,execution.strategy_magic,
                               settings.buy_offset,settings.sell_offset,settings.radius,
                               execution.last_ticket);
   if(buy) state.candidate_buy=candidate;
   else state.candidate_sell=candidate;
   if(Bot1NearbyPending(buy,buy ? state.candidate_buy : state.candidate_sell,
                        execution.symbol,execution.strategy_magic,settings.buy_offset,
                        settings.sell_offset,unit,settings.radius,execution.last_ticket)) return;

   const int count=Bot1CountPendingKind(execution.strategy_magic,execution.symbol,
                                       execution.last_ticket,buy ? ORDER_TYPE_BUY_STOP : ORDER_TYPE_SELL_STOP);
   const double saved_candidate=buy ? state.candidate_buy : state.candidate_sell;
   if(count==maximum_pending)
   {
      const double extreme=Bot1EntryPendingExtreme(buy,execution);
      if((buy ? extreme<saved_candidate : saved_candidate<extreme) ||
         (settings.replace_at_equal&1)==0) return;
   }
   uint digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   if(buy) state.rounded_buy=Bot1RoundPrice(state.candidate_buy,digits);
   else state.rounded_sell=Bot1RoundPrice(state.candidate_sell,digits);
   if((buy ? state.rounded_buy : state.rounded_sell)==0.0) return;
   state.active_step=settings.step_reference;
   digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   const double shifted=buy
      ? Bot1QueueSum(Bot1QueueProduct(settings.buy_offset,unit),state.rounded_buy)
      : Bot1SubmissionDifference(state.rounded_sell,Bot1QueueProduct(settings.sell_offset,unit));
   const double base_price=Bot1RoundPrice(shifted,digits);
   Bot1SubmitEntryAfterPriceLive(buy,base_price,settings.submission,restore,unit,
                                execution,volumes,strategy_index,queue);
}

void Bot1RunEntryLoop(const int &maximum_pending,const Bot1EntryLoopSettings &settings,
                      Bot1EntryLoopState &state,const Bot1VolumeSettings &volume_settings,
                      Bot1VolumeState &volume_state,const bool reset_on_withdrawal,
                      const string &peak_key,const string &time_key,long &last_check,
                      long &last_deal_time,const string &suffix,const double &unit,
                      const uint &strategy_index,double &volumes[],
                      Bot1PendingRestoreSettings &restore,Bot1NfpExecution &execution,
                      Bot1PendingQueue &queue)
{
   if(maximum_pending<=0) return;
   const uchar buy_enabled=settings.buy_enabled,sell_enabled=settings.sell_enabled;
   int iteration=0;
   do
   {
      Bot1PrepareVolumeRuntime(restore.sl_distance,settings.volume_enabled!=0 ? 100 : 0,
                               execution.symbol,suffix,volume_settings,volume_state,
                               reset_on_withdrawal,peak_key,time_key,last_check,last_deal_time,
                               strategy_index,volumes);
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
         Bot1DeleteExpiredEntryOrders(settings.expiration_seconds,execution);
      }
      if(buy_enabled!=0)
         Bot1ProcessEntryDirection(true,maximum_pending,settings,state,restore,unit,
                                   execution,volumes,strategy_index,queue);
      if(sell_enabled!=0)
         Bot1ProcessEntryDirection(false,maximum_pending,settings,state,restore,unit,
                                   execution,volumes,strategy_index,queue);
      iteration++;
   } while(iteration<maximum_pending);
}
#endif
