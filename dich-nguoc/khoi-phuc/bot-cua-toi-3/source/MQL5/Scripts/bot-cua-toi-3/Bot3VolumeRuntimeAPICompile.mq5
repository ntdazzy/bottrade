#property strict
#include "../../Include/bot-cua-toi-3/Bot3VolumeRuntime.mqh"
void OnStart()
{
   Bot3VolumeSettings r;Bot3VolumeState s;ZeroMemory(r);ZeroMemory(s);
   double volumes[9];ArrayInitialize(volumes,0.01);uint index=0;
   long last_check=0,last_deal=0;string symbol="XAUUSD",suffix="",peak="compile-peak",time="compile-time";
   double denominator=1.0;uchar enabled[5];ArrayInitialize(enabled,1);
   Bot3PrepareVolumeRuntime(100.,100,symbol,suffix,r,s,false,peak,time,last_check,last_deal,denominator,enabled,index,volumes);
}
