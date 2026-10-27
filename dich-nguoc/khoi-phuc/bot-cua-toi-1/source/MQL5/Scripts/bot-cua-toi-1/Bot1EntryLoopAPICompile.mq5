#property strict
#include "../../Include/bot-cua-toi-1/Bot1EntryLoop.mqh"
void OnStart()
{
   int maximum=0;Bot1EntryLoopSettings settings;Bot1EntryLoopState state;
   Bot1VolumeSettings volume_settings;Bot1VolumeState volume_state;
   Bot1PendingRestoreSettings restore;Bot1NfpExecution execution;Bot1PendingQueue queue;
   ZeroMemory(settings);ZeroMemory(state);ZeroMemory(volume_settings);ZeroMemory(volume_state);
   ZeroMemory(restore);ZeroMemory(execution);ZeroMemory(queue);
   bool reset=false;string peak="",time_key="",suffix="";long last_check=0,last_deal=0;
   double unit=0,volumes[8];ArrayInitialize(volumes,0);uint index=0;
   Bot1RunEntryLoop(maximum,settings,state,volume_settings,volume_state,reset,peak,time_key,
                     last_check,last_deal,suffix,unit,index,volumes,restore,execution,queue);
}
