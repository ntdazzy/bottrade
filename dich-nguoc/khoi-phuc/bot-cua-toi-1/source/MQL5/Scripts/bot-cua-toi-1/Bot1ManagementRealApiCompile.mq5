// Compile-only use of actual terminal API declarations. Do not run this script.
#property strict
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealTimed.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealDistance.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealStore.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealSlippage.mqh"
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
   Bot1VirtualStopState table;ZeroMemory(table);double current_stop=95.;
   Bot1StoreRealStop(symbol,95.,current_stop,7.,table);
}
