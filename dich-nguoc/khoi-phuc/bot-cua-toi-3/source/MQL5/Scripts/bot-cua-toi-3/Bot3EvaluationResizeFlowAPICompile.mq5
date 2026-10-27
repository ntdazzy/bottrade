#property strict
#include "../../Include/bot-cua-toi-3/Bot3EvaluationResizeFlow.mqh"
void OnStart()
{
   Bot3VolumeSettings settings;Bot3VolumeState state;ZeroMemory(settings);ZeroMemory(state);
   Bot3PendingRequestState trade;Bot3TradeSendOptions options;ZeroMemory(trade);ZeroMemory(options);
   uchar flag=1,virtual_expiration=0;double stop=1500.,change=10.,previous=0.;
   double volumes[9],table[100][2];ArrayInitialize(volumes,.01);ArrayInitialize(table,0.);
   uint index=0;ulong ticket=0;int magic=42;long last_check=0,last_deal=0;
   string symbol="XAUUSD",suffix="",peak="compile-peak",time="compile-time";
   double denominator=1.0;uchar enabled[5];ArrayInitialize(enabled,1);
   Bot3RefreshEvaluationPending(flag,stop,settings,state,false,peak,time,last_check,last_deal,
                              denominator,enabled,magic,virtual_expiration,symbol,suffix,change,previous,
                              index,volumes,ticket,table,trade,options);
}
