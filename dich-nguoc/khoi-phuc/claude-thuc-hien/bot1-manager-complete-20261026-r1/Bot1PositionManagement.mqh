// Bot 1 position manager assembled from the existing management helpers.
// Candidate only: not compiled, not run, not compared with the original EX5.
#ifndef BOT1_POSITION_MANAGEMENT_MQH
#define BOT1_POSITION_MANAGEMENT_MQH
#include "Bot1ManagementPrelude.mqh"
#include "Bot1ManagementVirtualFinish.mqh"
#include "Bot1ManagementRealStart.mqh"
#include "Bot1ManagementRealTimed.mqh"
#include "Bot1ManagementRealDistance.mqh"
#include "Bot1ManagementRealSlippage.mqh"
#include "Bot1ManagementRealHighLow.mqh"
#include "Bot1ManagementRealLock.mqh"
#include "Bot1ManagementRealCounter.mqh"
#include "Bot1ManagementRealStore.mqh"

// Filled by the caller; the mode exists only as finish.mode. finish.high_low_buy_shift and
// finish.high_low_sell_shift are constants the caller sets to 10.0.
struct Bot1PositionManagementSettings
{
   string symbol;
   int magic;
   int enabled;
   double unit;
   double stop_distance;
   double take_distance;
   double emergency_offset;
   uchar candle_enabled[2];
   uchar candle_timeframe[2];
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
   int slippage_enabled;
   double slippage_trail;
   double slippage_start;
   double slippage_limit;
   int high_low_gap_count;
   double gap;
   double freeze;
   Bot1VirtualFinishSettings finish;
};

// strategy_index is kept in 0..7 by the caller and levels[] matches the managed direction.
// cache, table and tick are shared and never reset per position, so a failed
// SymbolInfoTick keeps the previous quote.
struct Bot1PositionManagementState
{
   double cache[100][2];
   double copied_step;
   Bot1VirtualStopState table;
   long open_tickets[];
   double current_stop;
   double volumes[8];
   uint strategy_index;
   uint error_count;
   int counter;
   ulong last_ticket;
   MqlTick tick;
};

// Internal step of Bot1ManagePositions for the position at index. Returns true only when a
// close path ends the whole pass; changed collects the updates of this position.
bool Bot1ManageOnePosition(const bool buy,const Bot1PositionManagementSettings &settings,
                           Bot1PositionManagementState &shared,const double &levels[],
                           Bot1PendingRequestState &requests,Bot1TradeSendOptions &options,
                           const ulong &deviation,const int index,const uchar eligible,
                           bool &changed)
{
   Bot1ManagedPosition position;
   if(!Bot1ReadManagementPosition(index,buy,settings.magic,settings.enabled,settings.symbol,
                                  shared.last_ticket,shared.tick,position))
      return false;
   // Modify results are ignored here and do not set changed.
   Bot1FillManagementInitialLevels(buy,settings.symbol,settings.unit,settings.stop_distance,
                                   settings.take_distance,position,requests,options);
   // Candle groups 0 and 1: a close attempt neither returns nor sets changed, and the later
   // steps keep this local position.
   Bot1CloseManagementCandle(buy,settings.symbol,settings.candle_enabled[0],
                             settings.candle_timeframe[0],false,position,requests,options,
                             deviation,shared.tick,settings.gap,settings.freeze);
   Bot1CloseManagementCandle(buy,settings.symbol,settings.candle_enabled[1],
                             settings.candle_timeframe[1],true,position,requests,options,
                             deviation,shared.tick,settings.gap,settings.freeze);
   bool passed;
   double anchor;
   double raw_reference=Bot1ManagementCachedReference(buy,settings.symbol,position.ticket_number,
                                                      position.open_price,settings.unit,
                                                      settings.finish.step_reference,
                                                      settings.anchor_limit,settings.use_anchor,
                                                      shared.copied_step,shared.cache,
                                                      passed,anchor);
   // Captured after the cache lookup. ticket, ticket_number, passed, anchor and raw_reference
   // keep these values for the rest of this position.
   const long ticket=(long)position.ticket_number;
   const double ticket_number=(double)ticket;

   // Emergency close without a message; last_ticket is read after the two ignored calls.
   const double u=settings.unit;
   const double distance=settings.stop_distance;
   const double trigger=buy ? (position.open_price-u*(distance+0.0))-settings.emergency_offset
                            : (u*(distance+0.0)+position.open_price)+settings.emergency_offset;
   const double quote=buy ? shared.tick.bid : shared.tick.ask;
   if(buy ? quote<trigger : trigger<quote)
   {
      SymbolInfoTick(settings.symbol,shared.tick);
      SymbolInfoDouble(settings.symbol,SYMBOL_VOLUME);
      Bot1TryClosePosition(requests,options,deviation,shared.tick.bid,shared.tick.ask,
                           settings.gap,settings.freeze,shared.last_ticket);
      return true;
   }

   if(settings.finish.mode!=2)
   {
      double initial_stop;
      if(Bot1StartRealManagement(buy,settings.symbol,settings.unit,settings.stop_distance,ticket,
                                 position,shared.tick,shared.table,shared.open_tickets,
                                 initial_stop,shared.current_stop,requests,options,deviation,
                                 settings.gap,settings.freeze))
         return true;
      // buy cannot change during the call: both blocks run timed, distance, slippage,
      // high/low, lock and counter in the same order. A true timed result sets changed and
      // false keeps it; counter is called even when changed is already true.
      if(buy)
      {
         if(Bot1AdvanceTimedBuyStop(settings.symbol,settings.unit,settings.timed_activation,
                                    settings.timed_distance,settings.timed_delay_seconds,
                                    settings.gap,settings.freeze,position,shared.tick,requests,
                                    options,shared.error_count,(ulong)ticket))
            changed=true;
         if(Bot1AdvanceDistanceBuyStop(settings.symbol,settings.unit,settings.trail,
                                       settings.trail_step,settings.trail_start,
                                       settings.trail_limit,anchor,settings.gap,settings.freeze,
                                       position,shared.tick,shared.volumes,shared.strategy_index,
                                       changed,requests,options,deviation,shared.error_count,
                                       (ulong)ticket))
            return true;
         Bot1AdvanceSlippageRealBuyStop(settings.symbol,settings.unit,settings.slippage_enabled,
                                        (uchar)passed,raw_reference,settings.slippage_trail,
                                        settings.slippage_start,settings.slippage_limit,
                                        settings.gap,settings.freeze,position,shared.tick,changed,
                                        requests,options,shared.error_count,(ulong)ticket);
         Bot1AdvanceHighLowRealBuyStop(settings.symbol,settings.finish.high_low_enabled,eligible,
                                       settings.high_low_gap_count,settings.unit,
                                       settings.finish.high_low_before_open,
                                       settings.finish.high_low_shift,settings.gap,
                                       settings.freeze,levels,shared.strategy_index,position,
                                       shared.tick,changed,requests,options,shared.error_count,
                                       (ulong)ticket);
         Bot1AdvanceRealLockBuyStop(settings.symbol,settings.finish.lock_start,
                                    settings.finish.lock_extra,settings.unit,settings.gap,
                                    settings.freeze,position,shared.tick,changed,requests,
                                    options,shared.error_count,(ulong)ticket);
         Bot1AdvanceRealCounterBuyStop(settings.symbol,settings.finish.step_enabled,
                                       settings.finish.step_reference,settings.finish.min_steps,
                                       settings.finish.step_distance,settings.unit,
                                       shared.copied_step,anchor,settings.gap,settings.freeze,
                                       shared.counter,position,shared.tick,changed,requests,
                                       options,(ulong)ticket);
      }
      else
      {
         if(Bot1AdvanceTimedSellStop(settings.symbol,settings.unit,settings.timed_activation,
                                     settings.timed_distance,settings.timed_delay_seconds,
                                     settings.gap,settings.freeze,position,shared.tick,requests,
                                     options,shared.error_count,(ulong)ticket))
            changed=true;
         if(Bot1AdvanceDistanceSellStop(settings.symbol,settings.unit,settings.trail,
                                        settings.trail_step,settings.trail_start,
                                        settings.trail_limit,anchor,settings.gap,settings.freeze,
                                        position,shared.tick,shared.volumes,shared.strategy_index,
                                        changed,requests,options,deviation,shared.error_count,
                                        (ulong)ticket))
            return true;
         Bot1AdvanceSlippageRealSellStop(settings.symbol,settings.unit,settings.slippage_enabled,
                                         (uchar)passed,raw_reference,settings.slippage_trail,
                                         settings.slippage_start,settings.slippage_limit,
                                         settings.gap,settings.freeze,position,shared.tick,changed,
                                         requests,options,shared.error_count,(ulong)ticket);
         Bot1AdvanceHighLowRealSellStop(settings.symbol,settings.finish.high_low_enabled,eligible,
                                        settings.high_low_gap_count,settings.unit,
                                        settings.finish.high_low_before_open,
                                        settings.finish.high_low_shift,settings.gap,
                                        settings.freeze,levels,shared.strategy_index,position,
                                        shared.tick,changed,requests,options,shared.error_count,
                                        (ulong)ticket);
         Bot1AdvanceRealLockSellStop(settings.symbol,settings.finish.lock_start,
                                     settings.finish.lock_extra,settings.unit,settings.gap,
                                     settings.freeze,position,shared.tick,changed,requests,
                                     options,shared.error_count,(ulong)ticket);
         Bot1AdvanceRealCounterSellStop(settings.symbol,settings.finish.step_enabled,
                                        settings.finish.step_reference,settings.finish.min_steps,
                                        settings.finish.step_distance,settings.unit,
                                        shared.copied_step,anchor,settings.gap,settings.freeze,
                                        shared.counter,position,shared.tick,changed,requests,
                                        options,(ulong)ticket);
      }
      // Written before the strict hit test; a quote equal to the stop is not a hit.
      shared.current_stop=position.sl;
      if(buy ? shared.tick.bid<position.sl : position.sl<shared.tick.ask)
      {
         Bot1CloseRealStopHit(buy,settings.symbol,shared.current_stop,shared.tick,requests,
                              options,deviation,settings.gap,settings.freeze,ticket);
         return true;
      }
      // Stored whether changed is set or not.
      Bot1StoreRealStop(settings.symbol,initial_stop,shared.current_stop,ticket_number,
                        shared.table);
      // mode is read again after the store; 2 continues into the virtual part with changed kept.
      if(settings.finish.mode!=2) return false;
   }

   double initial_level;
   // Table level, current_stop write, hit test with equality, real-stop move and stamp all
   // stay inside the helper.
   if(Bot1StartVirtualManagement(buy,settings.symbol,settings.unit,settings.stop_distance,
                                 settings.virtual_delay_seconds,position,shared.tick,
                                 shared.table,shared.open_tickets,initial_level,
                                 shared.current_stop,requests,options,deviation,settings.gap,
                                 settings.freeze))
      return true;
   Bot1AdvanceTimedVirtualStop(buy,settings.symbol,settings.unit,settings.timed_activation,
                               settings.timed_distance,settings.timed_delay_seconds,
                               settings.freeze,position,shared.tick,shared.current_stop,changed);
   if(Bot1AdvanceDistanceVirtualStop(buy,settings.symbol,settings.unit,settings.trail,
                                     settings.trail_step,settings.trail_start,
                                     settings.trail_limit,anchor,position,shared.tick,
                                     shared.volumes,shared.strategy_index,shared.current_stop,
                                     changed,requests,options,deviation,settings.gap,
                                     settings.freeze))
      return true;
   Bot1AdvanceSlippageVirtualStop(buy,settings.symbol,settings.unit,settings.slippage_enabled,
                                  passed,raw_reference,settings.slippage_trail,
                                  settings.slippage_start,settings.slippage_limit,
                                  settings.freeze,position,shared.tick,shared.current_stop,
                                  changed);
   // Last virtual step: mode is not read again and neither chain is entered again.
   return Bot1FinishVirtualManagement(buy,settings.symbol,settings.finish,settings.unit,
                                      settings.gap,settings.freeze,anchor,raw_reference,
                                      shared.copied_step,position,shared.tick,levels,
                                      shared.strategy_index,shared.current_stop,changed,
                                      shared.counter,initial_level,ticket,shared.table,
                                      requests,options,deviation);
}

// Manages the open positions of one direction. Returns true as soon as a close path is
// reached, otherwise whether any position reported a change.
bool Bot1ManagePositions(const bool buy,const Bot1PositionManagementSettings &settings,
                         Bot1PositionManagementState &shared,const double &levels[],
                         Bot1PendingRequestState &requests,Bot1TradeSendOptions &options,
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
      if(Bot1ManageOnePosition(buy,settings,shared,levels,requests,options,deviation,index,
                               eligible,changed))
         return true;
      any_changed=any_changed || changed;
      index++;
      // Read again after each position; skips and candle closes do not move index or total.
      total=PositionsTotal();
   }
   while(index<total);
   return any_changed;
}
#endif
