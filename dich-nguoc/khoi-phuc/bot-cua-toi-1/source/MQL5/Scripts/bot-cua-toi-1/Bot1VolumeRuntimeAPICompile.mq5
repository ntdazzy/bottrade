#property strict
#include "../../Include/bot-cua-toi-1/Bot1VolumeRuntime.mqh"
void OnStart()
{
   Bot1VolumeSettings r;Bot1VolumeState s;ZeroMemory(r);ZeroMemory(s);
   double volumes[8];ArrayInitialize(volumes,0.01);uint index=0;
   long last_check=0,last_deal=0;string symbol="XAUUSD",suffix="",peak="compile-peak",time="compile-time";
   Bot1PrepareVolumeRuntime(100.,100,symbol,suffix,r,s,false,peak,time,last_check,last_deal,index,volumes);
}
