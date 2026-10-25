// Compile-only check using real API declarations. This script is not run.
#property strict
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealTimed.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealDistance.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealTake.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealSlippage.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealHighLow.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementVirtualFinishFlow.mqh"
input bool InvokeFunctions=false;
void OnStart()
{
   if(!InvokeFunctions) { Print("Bot3ManagementRealApiCompile: compile only");return; }
   Bot3ManagedPosition position;ZeroMemory(position);
   Bot3PendingRequestState state;ZeroMemory(state);
   Bot3TradeSendOptions options;ZeroMemory(options);
   Bot3VirtualStopState table;ZeroMemory(table);
   Bot3VirtualFinishSettings settings;ZeroMemory(settings);
   MqlTick tick;ZeroMemory(tick);
   string symbol="CHECK";double unit=1.,activation=1.,distance=2.,gap=.2,freeze=2.5;
   int seconds=60,counter=0;uint error_count=0,index=0;ulong ticket=7,deviation=1;
   double current=95.,take=120.,copied=.5,levels[9];ArrayInitialize(levels,100.);
   bool changed=false;
   int enabled=1,gap_count=1;uchar eligible=1,before_open=0,shift=0;
   Bot3AdvanceTimedBuyStop(symbol,unit,activation,distance,seconds,gap,freeze,position,tick,state,options,error_count,ticket);
   Bot3AdvanceTimedSellStop(symbol,unit,activation,distance,seconds,gap,freeze,position,tick,state,options,error_count,ticket);
   Bot3AdvanceDistanceBuyStop(symbol,unit,distance,distance,distance,distance,100.,gap,freeze,position,tick,
                              levels,index,changed,state,options,deviation,error_count,ticket);
   Bot3AdvanceDistanceSellStop(symbol,unit,distance,distance,distance,distance,100.,gap,freeze,position,tick,
                               levels,index,changed,state,options,deviation,error_count,ticket);
   Bot3AdvanceRealTakeBuy(symbol,unit,distance,distance,100.,gap,freeze,position,tick,levels,index,
                          changed,state,options,deviation,error_count,ticket);
   Bot3AdvanceRealTakeSell(symbol,unit,distance,distance,100.,gap,freeze,position,tick,levels,index,
                           changed,state,options,deviation,error_count,ticket);
   Bot3AdvanceSlippageRealBuyStop(symbol,unit,enabled,eligible,100.,distance,distance,distance,gap,
                                  freeze,position,tick,changed,state,options,error_count,ticket);
   Bot3AdvanceSlippageRealSellStop(symbol,unit,enabled,eligible,100.,distance,distance,distance,gap,
                                   freeze,position,tick,changed,state,options,error_count,ticket);
   Bot3AdvanceHighLowRealBuyStop(symbol,enabled,eligible,gap_count,unit,before_open,shift,gap,freeze,
                                 levels,index,position,tick,changed,state,options,error_count,ticket);
   Bot3AdvanceHighLowRealSellStop(symbol,enabled,eligible,gap_count,unit,before_open,shift,gap,freeze,
                                  levels,index,position,tick,changed,state,options,error_count,ticket);
   Bot3FinishVirtualManagement(true,symbol,settings,unit,gap,freeze,100.,copied,position,tick,levels,index,
                               current,take,changed,counter,95.,120.,(long)ticket,table,state,options,deviation);
}
