// Compile-only use of actual terminal API declarations. Do not run this script.
#property strict
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealTimed.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealDistance.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealStore.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealSlippage.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealHighLow.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealLock.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealCounter.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot1ManagementRealApiCompile: compile only");return; }
   Bot1ManagedPosition position;ZeroMemory(position);
   Bot1PendingRequestState state;ZeroMemory(state);
   Bot1TradeSendOptions options;ZeroMemory(options);
   MqlTick tick;ZeroMemory(tick);
   string symbol="CHECK";double unit=1.,activation=1.,distance=2.,gap=.2,freeze=2.5;
   int seconds=60;uint error_count=0;ulong ticket=7;
   Bot1AdvanceTimedBuyStop(symbol,unit,activation,distance,seconds,gap,freeze,position,tick,state,options,error_count,ticket);
   Bot1AdvanceTimedSellStop(symbol,unit,activation,distance,seconds,gap,freeze,position,tick,state,options,error_count,ticket);
   double trail=2.,step=.5,start=1.,limit=4.,anchor=100.,volumes[9];ArrayInitialize(volumes,.1);
   uint strategy_index=2;bool changed=false;ulong deviation=1;
   Bot1AdvanceDistanceBuyStop(symbol,unit,trail,step,start,limit,anchor,gap,freeze,position,tick,volumes,strategy_index,changed,state,options,deviation,error_count,ticket);
   Bot1AdvanceDistanceSellStop(symbol,unit,trail,step,start,limit,anchor,gap,freeze,position,tick,volumes,strategy_index,changed,state,options,deviation,error_count,ticket);
   int slippage_enabled=1;
   Bot1AdvanceSlippageRealBuyStop(symbol,unit,slippage_enabled,(uchar)1,anchor,trail,start,limit,gap,freeze,position,tick,changed,state,options,error_count,ticket);
   Bot1AdvanceSlippageRealSellStop(symbol,unit,slippage_enabled,(uchar)1,anchor,trail,start,limit,gap,freeze,position,tick,changed,state,options,error_count,ticket);
   int high_low_enabled=1,gap_count=1,counter=1,minimum_steps=2;
   uchar before_open=0,shift_setting=0,step_enabled=1;double levels[8];ArrayInitialize(levels,95.);
   double lock_start=1.,lock_extra=.5,step_reference=0.,step_distance=1.,copied_step=.5;
   Bot1AdvanceHighLowRealBuyStop(symbol,high_low_enabled,(uchar)1,gap_count,unit,before_open,shift_setting,gap,freeze,levels,strategy_index,position,tick,changed,state,options,error_count,ticket);
   Bot1AdvanceHighLowRealSellStop(symbol,high_low_enabled,(uchar)1,gap_count,unit,before_open,shift_setting,gap,freeze,levels,strategy_index,position,tick,changed,state,options,error_count,ticket);
   Bot1AdvanceRealLockBuyStop(symbol,lock_start,lock_extra,unit,gap,freeze,position,tick,changed,state,options,error_count,ticket);
   Bot1AdvanceRealLockSellStop(symbol,lock_start,lock_extra,unit,gap,freeze,position,tick,changed,state,options,error_count,ticket);
   Bot1AdvanceRealCounterBuyStop(symbol,step_enabled,step_reference,minimum_steps,step_distance,unit,copied_step,anchor,gap,freeze,counter,position,tick,changed,state,options,ticket);
   Bot1AdvanceRealCounterSellStop(symbol,step_enabled,step_reference,minimum_steps,step_distance,unit,copied_step,anchor,gap,freeze,counter,position,tick,changed,state,options,ticket);
   Bot1VirtualStopState table;ZeroMemory(table);double current_stop=95.;
   Bot1StoreRealStop(symbol,95.,current_stop,7.,table);
}
