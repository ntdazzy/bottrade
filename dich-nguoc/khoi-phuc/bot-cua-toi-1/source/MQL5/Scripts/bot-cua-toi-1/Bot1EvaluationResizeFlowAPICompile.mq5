#property strict
#include "../../Include/bot-cua-toi-1/Bot1EvaluationResizeFlow.mqh"
void OnStart()
{
   Bot1VolumeSettings settings;Bot1VolumeState state;ZeroMemory(settings);ZeroMemory(state);
   Bot1PendingRequestState trade;Bot1TradeSendOptions options;ZeroMemory(trade);ZeroMemory(options);
   uchar flag=1,virtual_expiration=0;double stop=1500.,change=10.,previous=0.;
   double volumes[8],table[100][2];ArrayInitialize(volumes,.01);ArrayInitialize(table,0.);
   uint index=0;ulong ticket=0;int magic=42;long last_check=0,last_deal=0;
   string symbol="XAUUSD",suffix="",peak="compile-peak",time="compile-time";
   Bot1RefreshEvaluationPending(flag,stop,settings,state,false,peak,time,last_check,last_deal,
                              magic,virtual_expiration,symbol,suffix,change,previous,
                              index,volumes,ticket,table,trade,options);
}
