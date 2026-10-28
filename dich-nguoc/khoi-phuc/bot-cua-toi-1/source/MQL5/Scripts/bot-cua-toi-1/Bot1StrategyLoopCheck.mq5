#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1StrategyCycle.mqh"
#include "../../Include/bot-cua-toi-1/Bot1StrategySelection.mqh"
Bot1StrategySelectionInput LoopFlags;
int LoopCalls,LoopIndexes[8],LoopEffectCall,LoopEffectField,LoopEffectValue,LoopFault;
bool LoopHL,LoopHour;
void SetLoopFlag(const int field,const bool value)
{
   switch(field)
   {
      case 0: LoopFlags.run_strategy_a=value;break;
      case 1: LoopFlags.run_strategy_b=value;break;
      case 2: LoopFlags.run_strategy_c=value;break;
      case 3: LoopFlags.run_strategy_d=value;break;
      case 4: LoopFlags.run_strategy_e=value;break;
      case 5: LoopFlags.run_strategy_f=value;break;
      case 6: LoopFlags.run_strategy_g=value;break;
      case 7: LoopFlags.run_strategy_h=value;break;
   }
}
uint LoopMask()
{
   uint mask=0;
   if(LoopFlags.run_strategy_a) mask|=(uint)1;
   if(LoopFlags.run_strategy_b) mask|=(uint)2;
   if(LoopFlags.run_strategy_c) mask|=(uint)4;
   if(LoopFlags.run_strategy_d) mask|=(uint)8;
   if(LoopFlags.run_strategy_e) mask|=(uint)16;
   if(LoopFlags.run_strategy_f) mask|=(uint)32;
   if(LoopFlags.run_strategy_g) mask|=(uint)64;
   if(LoopFlags.run_strategy_h) mask|=(uint)128;
   return mask;
}
Bot1EntryLevelDecision LoopProbe(const uint index,const bool use_hl,
                                            const Bot1ProfileAdjustments &adjustments,
                                            Bot1PreparationInputs &inputs,
                                            const Bot1StrategyContextInputs &context_inputs,
                                            Bot1ProfileRuntimeState &profile_state,
                                            Bot1StrategyContextState &context_state,
                                            Bot1PreparationState &preparation,
                                            Bot1NfpExecution &execution,
                                            const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                                            const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                                            const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                                            Bot1NewsEvents &events,MqlDateTime &cached_calendar,
                                            const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                            Bot1NewsSelection &selection,const Bot1FridaySettings &friday,uchar &friday_closed,
                                            Bot1SpreadSettings &spread_settings,double &spread,
                                            Bot1PendingQueue &queue,Bot1PendingRestoreSettings &restore,
                                            Bot1LevelCacheSettings &level_settings,
                                            uint &current_index,long &bar_times[],double &upper[],double &lower[],
                                            Bot1EntryLoopSettings &loop_settings,Bot1EntryLoopState &loop_state,
                                            Bot1VolumeSettings &volume_settings,Bot1VolumeState &volume_state,
                                            const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                                            long &last_check,long &last_deal_time,const string &suffix,double &volumes[],
                                            const uchar &panel_show,const uchar &panel_tester,const int &panel_mode,
                                            const double &panel_trade_risk,const int &panel_balance_step,
                                            const uchar &day_switch_filter,const double &balance_change_percent,
                                            double &previous_balance,Bot1EvaluationPrefixSettings &prefix,
                                            Bot1EvaluationPrefixState &state,Bot1DisplayState &display,
                                            const bool hour_changed,int &closed_trades[],
                                            Bot1StrategyHistoryCache &history_cache,
                                            double &strategy_totals[],double &strategy_average[])
{
   if(LoopCalls>=8 || use_hl!=LoopHL || hour_changed!=LoopHour){LoopFault|=1;return BOT1_LEVEL_STOP;}
   LoopIndexes[LoopCalls++]=(int)index;
   if(LoopCalls==LoopEffectCall)SetLoopFlag(LoopEffectField,LoopEffectValue!=0);
   return BOT1_LEVEL_STOP;
}
#define Bot1SetupEvaluateAndUpdateStatistics LoopProbe
#include "../../Include/bot-cua-toi-1/Bot1StrategyDispatcher.mqh"
#undef Bot1SetupEvaluateAndUpdateStatistics

int OnStart()
{
   if(CheckRun=="")return 1;
   string folder="bot1-strategy-loop\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4c503131 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);

   Bot1NfpFilterSettings nfp_settings;Bot1NfpFilterState nfp;Bot1ReleaseFilterSettings interest_settings,cpi_settings;Bot1ReleaseFilterState interest,cpi;Bot1NewsEvents events;Bot1NewsSelection selection;Bot1NfpExecution execution;MqlDateTime cached;
   Bot1LevelCacheSettings levels;uint current=0;long bars[100];double upper[100],lower[100];Bot1EntryLoopSettings loop;Bot1EntryLoopState loop_state;Bot1VolumeSettings volume;Bot1VolumeState volume_state;
   string peak="",time="",suffix="";long last_check=0,last_deal=0;double volumes[8];uchar show=0,tester=0,day_switch=0;int mode=0,balance_step=0;double risk=0,change=0,previous=0,spread=0;
   Bot1PendingRestoreSettings restore;Bot1SpreadSettings spread_settings;Bot1PendingQueue queue;Bot1FridaySettings friday;uchar friday_closed=0;long nfp_history[300],interest_history[300],cpi_history[300];Bot1EvaluationPrefixSettings prefix;Bot1EvaluationPrefixState state;Bot1DisplayState display;
   Bot1PreparationInputs preparation_inputs;Bot1PreparationState preparation;Bot1ProfileRuntimeState profile_state;Bot1ProfileAdjustments adjustments;Bot1StrategyContextInputs context_inputs;Bot1StrategyContextState context_state;
   ZeroMemory(nfp_settings);ZeroMemory(nfp);ZeroMemory(interest_settings);ZeroMemory(cpi_settings);ZeroMemory(interest);ZeroMemory(cpi);ZeroMemory(events);ZeroMemory(selection);ZeroMemory(execution);ZeroMemory(cached);ZeroMemory(levels);ZeroMemory(loop);ZeroMemory(loop_state);ZeroMemory(volume);ZeroMemory(volume_state);ZeroMemory(restore);ZeroMemory(spread_settings);ZeroMemory(queue);ZeroMemory(friday);ZeroMemory(prefix);ZeroMemory(state);ZeroMemory(display);ZeroMemory(preparation_inputs);ZeroMemory(preparation);ZeroMemory(profile_state);ZeroMemory(adjustments);ZeroMemory(context_inputs);ZeroMemory(context_state);
   ArrayInitialize(bars,0);ArrayInitialize(upper,0);ArrayInitialize(lower,0);ArrayInitialize(volumes,0);ArrayInitialize(nfp_history,0);ArrayInitialize(interest_history,0);ArrayInitialize(cpi_history,0);preparation_inputs.symbol=_Symbol;context_inputs.base_magic=0;

   int loop_closed[8];double loop_total[8],loop_average[8];Bot1StrategyHistoryCache loop_cache;
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file),mask=FileReadInteger(file);
      LoopEffectCall=FileReadInteger(file);LoopEffectField=FileReadInteger(file);LoopEffectValue=FileReadInteger(file);
      LoopHL=FileReadInteger(file)!=0;LoopHour=FileReadInteger(file)!=0;
      for(int i=0;i<8;i++)SetLoopFlag(i,(mask&(1<<i))!=0);
      LoopCalls=0;LoopFault=0;ArrayInitialize(LoopIndexes,-1);
   Bot1RunEnabledStrategies(LoopFlags,LoopHL,adjustments,preparation_inputs,context_inputs,profile_state,context_state,preparation,execution,nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,nfp_history,interest_history,cpi_history,selection,friday,friday_closed,spread_settings,spread,queue,restore,levels,current,bars,upper,lower,loop,loop_state,volume,volume_state,false,peak,time,last_check,last_deal,suffix,volumes,show,tester,mode,risk,balance_step,day_switch,change,previous,prefix,state,display,LoopHour,loop_closed,loop_cache,loop_total,loop_average);
      FileWriteInteger(output,id);FileWriteInteger(output,LoopCalls);FileWriteInteger(output,(int)LoopMask());FileWriteInteger(output,LoopFault);
      for(int i=0;i<8;i++)FileWriteInteger(output,LoopIndexes[i]);
   }
   if(FileTell(file)!=FileSize(file))return 5;
   FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
