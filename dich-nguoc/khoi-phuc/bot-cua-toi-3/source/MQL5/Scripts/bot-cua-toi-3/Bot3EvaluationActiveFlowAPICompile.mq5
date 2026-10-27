#property strict
#include "../../Include/bot-cua-toi-3/Bot3EvaluationActiveFlow.mqh"
void OnStart()
{
   Bot3NfpFilterSettings nfp_settings;Bot3NfpFilterState nfp;
   Bot3ReleaseFilterSettings interest_settings,cpi_settings;Bot3ReleaseFilterState interest,cpi;
   Bot3NewsEvents events;Bot3NewsSelection selection;Bot3NfpExecution execution;MqlDateTime cached;
   Bot3LevelCacheSettings level_settings;ZeroMemory(level_settings);uint caller_index=0,current_index=0;long bar_times[100];double upper[100],lower[100];
   ArrayInitialize(bar_times,0);ArrayInitialize(upper,0);ArrayInitialize(lower,0);
   Bot3EntryLoopSettings loop_settings;Bot3EntryLoopState loop_state;
   Bot3VolumeSettings volume_settings;Bot3VolumeState volume_state;
   ZeroMemory(loop_settings);ZeroMemory(loop_state);ZeroMemory(volume_settings);ZeroMemory(volume_state);
   string peak_key="",time_key="",suffix="";long last_check=0,last_deal=0;double volumes[9];ArrayInitialize(volumes,0);
   double denominator=1;uchar enabled[5];ArrayInitialize(enabled,0);
   uchar PanelShow=0;
   uchar PanelTester=0;
   uchar DaySwitch=0;
   double ChangePercent=0;
   double PreviousBalance=0;
   int BlockFlags=0;
   double PanelManual=0;
   int pending_enabled=0,maximum_pending=0;
   Bot3PendingRestoreSettings restore;ZeroMemory(restore);
   Bot3SpreadSettings spread_settings;Bot3PendingQueue queue;double unit=0,spread=0;ZeroMemory(spread_settings);ZeroMemory(queue);
   Bot3FridaySettings friday;uchar friday_closed=0;ZeroMemory(friday);
   long nfp_history[300],interest_history[300],cpi_history[300];
   ZeroMemory(nfp_settings);ZeroMemory(nfp);ZeroMemory(interest_settings);ZeroMemory(cpi_settings);
   ZeroMemory(interest);ZeroMemory(cpi);ZeroMemory(events);ZeroMemory(execution);ZeroMemory(cached);
   ArrayInitialize(nfp_history,0);ArrayInitialize(interest_history,0);ArrayInitialize(cpi_history,0);
   Bot3EvaluateActiveFlow(nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,
                            nfp_history,interest_history,cpi_history,execution,selection,friday,friday_closed,spread_settings,unit,spread,queue,restore,pending_enabled,maximum_pending,level_settings,caller_index,current_index,bar_times,upper,lower,loop_settings,loop_state,volume_settings,volume_state,false,peak_key,time_key,last_check,last_deal,suffix,denominator,enabled,volumes,PanelShow,PanelTester,PanelManual,BlockFlags!=0,DaySwitch,ChangePercent,PreviousBalance);
}
