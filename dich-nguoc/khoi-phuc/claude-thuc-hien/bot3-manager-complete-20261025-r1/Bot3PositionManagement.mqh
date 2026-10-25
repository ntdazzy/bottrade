// Bot 3 position manager assembled from the existing management helpers.
// Not compiled, not run and not compared with the original EX5.
#ifndef BOT3_POSITION_MANAGEMENT_MQH
#define BOT3_POSITION_MANAGEMENT_MQH
#include "Bot3ManagementPrelude.mqh"
#include "Bot3ManagementAnchor.mqh"
#include "Bot3ManagementRealStart.mqh"
#include "Bot3ManagementRealTimed.mqh"
#include "Bot3ManagementRealDistance.mqh"
#include "Bot3ManagementRealTake.mqh"
#include "Bot3ManagementRealSlippage.mqh"
#include "Bot3ManagementRealHighLow.mqh"
#include "Bot3ManagementRealLock.mqh"
#include "Bot3ManagementRealCounter.mqh"
#include "Bot3ManagementRealStore.mqh"
#include "Bot3ManagementVirtualStart.mqh"
#include "Bot3ManagementVirtual.mqh"
#include "Bot3ManagementVirtualTake.mqh"
#include "Bot3ManagementVirtualFinishFlow.mqh"

// Filled by the caller; the mode exists only as finish.mode. finish.high_low_buy_shift and
// finish.high_low_sell_shift are internal constants the caller sets to 10.0.
struct Bot3PositionManagementSettings
{
   string symbol;
   int magic;
   int enabled;
   double unit;
   double stop_distance;
   double take_distance;
   double emergency_offset;
   uchar candle_enabled[3];
   uchar candle_timeframe[3];
   uchar candle_shift;
   double anchor_limit;
   uchar use_anchor;
   uchar high_low_eligible;
   double timed_activation;
   double timed_distance;
   int timed_delay_seconds;
   int virtual_delay_seconds;
   double trail;
   double trail_step;
   double trail_start;
   double trail_limit;
   double take_trail_distance;
   double take_trail_start;
   int slippage_enabled;
   double slippage_trail;
   double slippage_start;
   double slippage_limit;
   int high_low_gap_count;
   // gap and freeze are separate values, not copies of finish fields.
   double gap;
   double freeze;
   Bot3VirtualFinishSettings finish;
};

// strategy_index is kept in 0..8 by the caller. tick is shared so a failed SymbolInfoTick
// keeps the previous quote; it is not reset per position.
struct Bot3PositionManagementState
{
   Bot3ManagementAnchorState anchor;
   Bot3VirtualStopState table;
   long open_tickets[];
   double current_stop;
   double current_take;
   double volumes[9];
   uint strategy_index;
   uint error_count;
   int counter;
   ulong last_ticket;
   MqlTick tick;
};

// Internal step of Bot3ManagePositions for the position at index. Returns true when a close
// path is reached; changed collects the updates reported for this position.
bool Bot3ManageOnePosition(const bool buy,const Bot3PositionManagementSettings &settings,
                           Bot3PositionManagementState &shared,const double &levels[],
                           Bot3PendingRequestState &requests,Bot3TradeSendOptions &options,
                           const ulong &deviation,const int index,const uchar eligible,
                           bool &changed)
{
   Bot3ManagedPosition position;
   if(!Bot3ReadManagementPosition(index,buy,settings.magic,settings.enabled,settings.symbol,
                                  shared.last_ticket,shared.tick,position))
      return false;
   Bot3FillManagementInitialLevels(buy,settings.symbol,settings.unit,settings.stop_distance,
                                   settings.take_distance,position,requests,options);
   // Candle groups 0, 1, 2 in order; they neither return nor set changed.
   for(int group=0;group<3;group++)
      Bot3CloseManagementCandle(buy,settings.symbol,group,settings.candle_enabled[group],
                                settings.candle_timeframe[group],settings.candle_shift,
                                position,shared.tick,requests,options,deviation,settings.gap,
                                settings.freeze);
   Bot3PrepareManagementAnchor(shared.anchor,settings.symbol,settings.unit,
                               settings.finish.step_reference,settings.anchor_limit,
                               settings.use_anchor,buy,position.ticket_number,
                               position.open_price);
   // Copied once; later API calls do not refresh these locals.
   const long ticket=shared.anchor.ticket;
   const double anchor=shared.anchor.reference;
   const double raw_reference=shared.anchor.level;
   const bool passed=shared.anchor.gap_passed;
   const double ticket_number=(double)ticket;

   // Emergency close without a message; last_ticket is read after the two ignored calls.
   const double u=settings.unit;
   const double distance=settings.stop_distance;
   const double trigger=buy ? (position.open_price-u*(distance+0.0))-settings.emergency_offset
                            : (u*(distance+0.0)+position.open_price)+settings.emergency_offset;
   if(buy ? shared.tick.bid<trigger : trigger<shared.tick.ask)
   {
      SymbolInfoTick(settings.symbol,shared.tick);
      PositionGetDouble(POSITION_VOLUME);
      Bot3TryClosePosition(requests,options,deviation,shared.tick.bid,shared.tick.ask,
                           settings.gap,settings.freeze,shared.last_ticket);
      return true;
   }

   if(settings.finish.mode!=2)
   {
      double initial_real_stop=0.0;
      if(Bot3StartRealManagement(buy,settings.symbol,settings.unit,settings.stop_distance,
                                 ticket,position,shared.tick,shared.table,shared.open_tickets,
                                 initial_real_stop,shared.current_stop,requests,options,
                                 deviation,settings.gap,settings.freeze))
         return true;
      // buy cannot change during the call: both blocks run timed, distance, take, slippage,
      // high/low, lock and counter in the same order.
      if(buy)
      {
         // The timed result is the flag itself, false included.
         changed=Bot3AdvanceTimedBuyStop(settings.symbol,settings.unit,settings.timed_activation,
                                         settings.timed_distance,settings.timed_delay_seconds,
                                         settings.gap,settings.freeze,position,shared.tick,
                                         requests,options,shared.error_count,(ulong)ticket);
         if(Bot3AdvanceDistanceBuyStop(settings.symbol,settings.unit,settings.trail,
                                       settings.trail_step,settings.trail_start,
                                       settings.trail_limit,anchor,settings.gap,settings.freeze,
                                       position,shared.tick,shared.volumes,shared.strategy_index,
                                       changed,requests,options,deviation,shared.error_count,
                                       (ulong)ticket))
            return true;
         if(Bot3AdvanceRealTakeBuy(settings.symbol,settings.unit,settings.take_trail_distance,
                                   settings.take_trail_start,anchor,settings.gap,settings.freeze,
                                   position,shared.tick,shared.volumes,shared.strategy_index,
                                   changed,requests,options,deviation,shared.error_count,
                                   (ulong)ticket))
            return true;
         Bot3AdvanceSlippageRealBuyStop(settings.symbol,settings.unit,settings.slippage_enabled,
                                        (uchar)passed,raw_reference,settings.slippage_trail,
                                        settings.slippage_start,settings.slippage_limit,
                                        settings.gap,settings.freeze,position,shared.tick,changed,
                                        requests,options,shared.error_count,(ulong)ticket);
         Bot3AdvanceHighLowRealBuyStop(settings.symbol,settings.finish.high_low_enabled,eligible,
                                       settings.high_low_gap_count,settings.unit,
                                       settings.finish.high_low_before_open,
                                       settings.finish.high_low_shift,settings.gap,
                                       settings.freeze,levels,shared.strategy_index,position,
                                       shared.tick,changed,requests,options,shared.error_count,
                                       (ulong)ticket);
         Bot3AdvanceRealLockBuyStop(settings.symbol,settings.finish.lock_start,
                                    settings.finish.lock_extra,settings.unit,settings.gap,
                                    settings.freeze,position,shared.tick,changed,requests,
                                    options,shared.error_count,(ulong)ticket);
         Bot3AdvanceRealCounterBuyStop(settings.symbol,settings.finish.step_enabled,
                                       settings.finish.step_reference,settings.finish.min_steps,
                                       settings.finish.step_distance,settings.unit,
                                       shared.anchor.step_reference,anchor,settings.gap,
                                       settings.freeze,shared.counter,position,shared.tick,
                                       changed,requests,options,(ulong)ticket);
      }
      else
      {
         changed=Bot3AdvanceTimedSellStop(settings.symbol,settings.unit,settings.timed_activation,
                                          settings.timed_distance,settings.timed_delay_seconds,
                                          settings.gap,settings.freeze,position,shared.tick,
                                          requests,options,shared.error_count,(ulong)ticket);
         if(Bot3AdvanceDistanceSellStop(settings.symbol,settings.unit,settings.trail,
                                        settings.trail_step,settings.trail_start,
                                        settings.trail_limit,anchor,settings.gap,settings.freeze,
                                        position,shared.tick,shared.volumes,shared.strategy_index,
                                        changed,requests,options,deviation,shared.error_count,
                                        (ulong)ticket))
            return true;
         if(Bot3AdvanceRealTakeSell(settings.symbol,settings.unit,settings.take_trail_distance,
                                    settings.take_trail_start,anchor,settings.gap,settings.freeze,
                                    position,shared.tick,shared.volumes,shared.strategy_index,
                                    changed,requests,options,deviation,shared.error_count,
                                    (ulong)ticket))
            return true;
         Bot3AdvanceSlippageRealSellStop(settings.symbol,settings.unit,settings.slippage_enabled,
                                         (uchar)passed,raw_reference,settings.slippage_trail,
                                         settings.slippage_start,settings.slippage_limit,
                                         settings.gap,settings.freeze,position,shared.tick,changed,
                                         requests,options,shared.error_count,(ulong)ticket);
         Bot3AdvanceHighLowRealSellStop(settings.symbol,settings.finish.high_low_enabled,eligible,
                                        settings.high_low_gap_count,settings.unit,
                                        settings.finish.high_low_before_open,
                                        settings.finish.high_low_shift,settings.gap,
                                        settings.freeze,levels,shared.strategy_index,position,
                                        shared.tick,changed,requests,options,shared.error_count,
                                        (ulong)ticket);
         Bot3AdvanceRealLockSellStop(settings.symbol,settings.finish.lock_start,
                                     settings.finish.lock_extra,settings.unit,settings.gap,
                                     settings.freeze,position,shared.tick,changed,requests,
                                     options,shared.error_count,(ulong)ticket);
         Bot3AdvanceRealCounterSellStop(settings.symbol,settings.finish.step_enabled,
                                        settings.finish.step_reference,settings.finish.min_steps,
                                        settings.finish.step_distance,settings.unit,
                                        shared.anchor.step_reference,anchor,settings.gap,
                                        settings.freeze,shared.counter,position,shared.tick,
                                        changed,requests,options,(ulong)ticket);
      }
      // Strict compares: a quote equal to the stop is not a hit.
      const bool hit=buy ? shared.tick.bid<position.sl : position.sl<shared.tick.ask;
      shared.current_stop=position.sl;
      if(hit)
      {
         Bot3CloseRealStopHit(buy,settings.symbol,shared.current_stop,shared.tick,requests,
                              options,deviation,settings.gap,settings.freeze,ticket);
         return true;
      }
      Bot3StoreRealStop(settings.symbol,initial_real_stop,shared.current_stop,ticket_number,
                        shared.table);
      // mode is read again after the store; 2 continues into the virtual part, changed kept.
      if(settings.finish.mode!=2) return false;
   }

   double initial_stop=0.0,initial_take=0.0;
   if(Bot3StartVirtualManagement(buy,settings.symbol,settings.unit,settings.stop_distance,
                                 settings.virtual_delay_seconds,ticket,position,shared.tick,
                                 shared.table,shared.open_tickets,initial_stop,initial_take,
                                 shared.current_stop,shared.current_take,requests,options,
                                 deviation,settings.gap,settings.freeze))
      return true;
   Bot3AdvanceTimedVirtualStop(buy,settings.symbol,settings.unit,settings.timed_activation,
                               settings.timed_distance,settings.timed_delay_seconds,
                               settings.freeze,position,shared.tick,shared.current_stop,changed);
   if(Bot3AdvanceDistanceVirtualStop(buy,settings.symbol,settings.unit,settings.trail,
                                     settings.trail_step,settings.trail_start,
                                     settings.trail_limit,anchor,position,shared.tick,
                                     shared.volumes,shared.strategy_index,shared.current_stop,
                                     changed,requests,options,deviation,settings.gap,
                                     settings.freeze,(ulong)ticket))
      return true;
   if(Bot3AdvanceVirtualTake(buy,settings.symbol,settings.unit,settings.take_trail_distance,
                             settings.take_trail_start,anchor,position,shared.tick,
                             shared.volumes,shared.strategy_index,shared.current_take,
                             changed,requests,options,deviation,settings.gap,settings.freeze,
                             (ulong)ticket))
      return true;
   Bot3AdvanceSlippageVirtualStop(buy,settings.symbol,settings.unit,settings.slippage_enabled,
                                  passed,raw_reference,settings.slippage_trail,
                                  settings.slippage_start,settings.slippage_limit,
                                  settings.freeze,position,shared.tick,shared.current_stop,
                                  changed);
   // The finish flow is the last virtual step; mode is not read again here.
   bool closed=Bot3FinishVirtualManagement(buy,settings.symbol,settings.finish,settings.unit,
                                           settings.gap,settings.freeze,anchor,
                                           shared.anchor.step_reference,position,shared.tick,
                                           levels,shared.strategy_index,shared.current_stop,
                                           shared.current_take,changed,shared.counter,
                                           initial_stop,initial_take,ticket,shared.table,
                                           requests,options,deviation);
   return closed;
}

// Manages the open positions of one direction. Returns true as soon as a close path is
// reached, otherwise whether any position reported a change.
bool Bot3ManagePositions(const bool buy,const Bot3PositionManagementSettings &settings,
                         Bot3PositionManagementState &shared,const double &levels[],
                         Bot3PendingRequestState &requests,Bot3TradeSendOptions &options,
                         const ulong &deviation)
{
   int total=PositionsTotal();
   if(total<1) return false;
   // Read once per pass after the first API call; every position uses this copy.
   const uchar eligible=settings.high_low_eligible;
   bool any_changed=false;
   int index=0;
   do
   {
      bool changed=false;
      if(Bot3ManageOnePosition(buy,settings,shared,levels,requests,options,deviation,index,
                               eligible,changed))
         return true;
      any_changed=any_changed || changed;
      index++;
      total=PositionsTotal();
   }
   while(index<total);
   return any_changed;
}
#endif
