#property strict
#include "../../Include/bot-cua-toi-3/Bot3EvaluationBridge.mqh"
void OnStart()
{
   uchar strategy_enabled=1;
   Bot3NfpFilterSettings nfp_settings;Bot3NfpFilterState nfp;Bot3ReleaseFilterSettings interest_settings,cpi_settings;Bot3ReleaseFilterState interest,cpi;Bot3NewsEvents events;Bot3NewsSelection selection;Bot3NfpExecution execution;MqlDateTime cached;
   Bot3LevelCacheSettings levels;uint current=0;long bars[100];double upper[100],lower[100];Bot3EntryLoopSettings loop;Bot3EntryLoopState loop_state;Bot3VolumeSettings volume;Bot3VolumeState volume_state;
   string peak="",time="",suffix="";long last_check=0,last_deal=0;double volumes[9],denominator=1;uchar enabled[5],show=0,tester=0,day_switch=0;double manual=0,change=0,previous=0,spread=0;
   Bot3PendingRestoreSettings restore;Bot3SpreadSettings spread_settings;Bot3PendingQueue queue;Bot3FridaySettings friday;uchar friday_closed=0;long nfp_history[300],interest_history[300],cpi_history[300];Bot3EvaluationPrefixSettings prefix;Bot3EvaluationPrefixState state;Bot3DisplayState display;
   Bot3PreparationInputs preparation_inputs;Bot3PreparationState preparation;Bot3ProfileRuntimeState profile_state;Bot3ProfileAdjustments adjustments;Bot3StrategyContextInputs context_inputs;Bot3StrategyContextState context_state;
   ZeroMemory(nfp_settings);ZeroMemory(nfp);ZeroMemory(interest_settings);ZeroMemory(cpi_settings);ZeroMemory(interest);ZeroMemory(cpi);ZeroMemory(events);ZeroMemory(selection);ZeroMemory(execution);ZeroMemory(cached);ZeroMemory(levels);ZeroMemory(loop);ZeroMemory(loop_state);ZeroMemory(volume);ZeroMemory(volume_state);ZeroMemory(restore);ZeroMemory(spread_settings);ZeroMemory(queue);ZeroMemory(friday);ZeroMemory(prefix);ZeroMemory(state);ZeroMemory(display);ZeroMemory(preparation_inputs);ZeroMemory(preparation);ZeroMemory(profile_state);ZeroMemory(adjustments);ZeroMemory(context_inputs);ZeroMemory(context_state);
   ArrayInitialize(bars,0);ArrayInitialize(upper,0);ArrayInitialize(lower,0);ArrayInitialize(volumes,0);ArrayInitialize(enabled,0);ArrayInitialize(nfp_history,0);ArrayInitialize(interest_history,0);ArrayInitialize(cpi_history,0);preparation_inputs.symbol=_Symbol;context_inputs.base_magic=0;
   Bot3SetupAndEvaluate(0,strategy_enabled,adjustments,preparation_inputs,context_inputs,profile_state,context_state,preparation,execution,nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,nfp_history,interest_history,cpi_history,selection,friday,friday_closed,spread_settings,spread,queue,restore,levels,current,bars,upper,lower,loop,loop_state,volume,volume_state,false,peak,time,last_check,last_deal,suffix,denominator,enabled,volumes,show,tester,manual,day_switch,change,previous,prefix,state,display);
}
