#property strict
#include "../../Include/bot-cua-toi-3/Bot3EntryLoop.mqh"
void OnStart()
{
   int maximum=0;Bot3EntryLoopSettings settings;Bot3EntryLoopState state;
   Bot3VolumeSettings volume_settings;Bot3VolumeState volume_state;
   Bot3PendingRestoreSettings restore;Bot3NfpExecution execution;Bot3PendingQueue queue;
   ZeroMemory(settings);ZeroMemory(state);ZeroMemory(volume_settings);ZeroMemory(volume_state);
   ZeroMemory(restore);ZeroMemory(execution);ZeroMemory(queue);
   bool reset=false;string peak="",time_key="",suffix="";long last_check=0,last_deal=0;
   double denominator=1;uchar enabled[5];ArrayInitialize(enabled,0);
   double unit=0,volumes[9];ArrayInitialize(volumes,0);uint index=0;
   Bot3RunEntryLoop(maximum,settings,state,volume_settings,volume_state,reset,peak,time_key,
                     last_check,last_deal,suffix,denominator,enabled,unit,index,volumes,restore,execution,queue);
}
