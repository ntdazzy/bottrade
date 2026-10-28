// All three product stages run; terminal services are supplied. No orders.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3EntryProfiles.mqh"
input string CheckRun="";
union Bits { double d;ulong u; };
ulong ValueBits(const double value) { Bits b;b.d=value;return b.u; }
double Sample,CheckPoint,Bid,Ask;long Now,Stops,Freeze;int CheckDigits,Fault,SampleCount;
ulong OrderHash,ATRSymbolHash;int Calls[7],PrintCalls,ATRFrame,ATRPeriod;
ulong TextHash(const string value) { ulong h=(ulong)0xcbf29ce484222325;for(int i=0;i<StringLen(value);i++) { ushort ch=StringGetCharacter(value,i);h^=(ulong)(ch&255);h*=(ulong)0x100000001b3;h^=(ulong)(ch>>8);h*=(ulong)0x100000001b3; }return h; }
ulong CombinedHash,FXServiceHash,FXPriceHash;int FXAccountReads,FXPriceReads;string FXCurrency;
void HashWord(ulong &hash,const ulong word) { for(int j=0;j<8;j++) { hash^=(word>>(j*8))&255;hash*=(ulong)0x100000001b3; } }
string SetupAccount(const ENUM_ACCOUNT_INFO_STRING property) { if(property!=ACCOUNT_CURRENCY) Fault=40;FXAccountReads++;HashWord(FXServiceHash,10);HashWord(FXServiceHash,TextHash(FXCurrency));HashWord(CombinedHash,10);HashWord(CombinedHash,TextHash(FXCurrency));return FXCurrency; }
double SetupClose(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   if(FXPriceReads>=4) { Fault=41;return 0.0; }
   double prices[]={2.,3.,4.,5.};double value=prices[FXPriceReads++];
   HashWord(FXPriceHash,TextHash(symbol));HashWord(FXPriceHash,(ulong)frame);HashWord(FXPriceHash,(ulong)shift);HashWord(FXPriceHash,ValueBits(value));
   HashWord(FXServiceHash,11);HashWord(CombinedHash,11);return value;
}
void Event(const int kind) { HashWord(CombinedHash,(ulong)(100+kind)); if(kind<=7) Calls[kind-1]++;else PrintCalls++;for(int i=0;i<8;i++) { OrderHash^=((ulong)kind>>(i*8))&255;OrderHash*=(ulong)0x100000001b3; } }
int FakeATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period) { Event(1);ATRFrame=(int)frame;ATRPeriod=period;ATRSymbolHash=TextHash(symbol);return 17; }
void LoopAtPreparation();
bool LoopPreparationFailed();
int FakeCopy(const int handle,const int buffer,const int start,const int count,double &target[]) { Event(2);LoopAtPreparation();if(LoopPreparationFailed()) return 0;if(handle!=17 || buffer!=0 || start!=0 || count!=100) Fault=22;ArrayResize(target,SampleCount);for(int j=0;j<SampleCount;j++) target[j]=Sample+250.0*j;return SampleCount; }
bool FakeTick(const string symbol,MqlTick &tick) { Event(4);if(symbol!="XAUUSD") Fault=23;tick.time=(datetime)Now;tick.bid=Bid;tick.ask=Ask;return true; }
datetime FakeTime(MqlDateTime &calendar) { Event(5);ZeroMemory(calendar);return (datetime)Now; }
datetime FakeTime() { Event(5);return (datetime)Now; }
double FakeDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property) { Event(6);if(symbol!="XAUUSD" || property!=SYMBOL_POINT) Fault=25;return CheckPoint; }
long FakeInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property) { Event(7);if(symbol!="XAUUSD") Fault=26;if(property==SYMBOL_DIGITS) return CheckDigits;if(property==SYMBOL_TRADE_STOPS_LEVEL) return Stops;if(property==SYMBOL_TRADE_FREEZE_LEVEL) return Freeze;Fault=27;return 0; }
int FakeLastError() { return 5017; }
void FakePrint(const string text) { Event(8); }
void FakePrint(const string text,const int code) { Event(8);if(code!=5017) Fault=30; }
double FakeOpen(const string symbol,const ENUM_TIMEFRAMES frame,const int shift) { Event(3);if(symbol!="XAUUSD" || frame!=PERIOD_D1 || shift!=1) Fault=24;return Sample; }
#define iOpen FakeOpen
#define Print FakePrint
#define GetLastError FakeLastError
#define iATR FakeATR
#define CopyBuffer FakeCopy
#define SymbolInfoTick FakeTick
#define TimeCurrent FakeTime
#define SymbolInfoDouble FakeDouble
#define SymbolInfoInteger FakeInteger
#define AccountInfoString SetupAccount
#define iClose SetupClose
#include "../../Include/bot-cua-toi-3/Bot3StrategySetup.mqh"
#undef AccountInfoString
#undef iClose
#undef iOpen
#undef Print
#undef GetLastError
#undef iATR
#undef CopyBuffer
#undef SymbolInfoTick
#undef TimeCurrent
#undef SymbolInfoDouble
#undef SymbolInfoInteger


#include "../../Include/bot-cua-toi-3/Bot3EvaluationWithDisplay.mqh"
#include "../../Include/bot-cua-toi-3/Bot3StrategyHistory.mqh"
uchar LoopFlags[9],LoopRetained[16];
int LoopCalls,LoopPreparations,LoopHistoryCalls,LoopIndexes[9],LoopCallerFlags[9];
int LoopPresenceCounts[6],LoopPositionCount,LoopOrderCount,LoopSelectedPosition,LoopSelectedOrder;
long LoopPositionMagic[9],LoopOrderMagic[9];
int LoopPositions(){LoopPresenceCounts[0]++;return LoopPositionCount;}
ulong LoopPositionTicket(const int index){LoopPresenceCounts[1]++;LoopSelectedPosition=index;return (ulong)(index+1);}
long LoopPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{LoopPresenceCounts[2]++;if((int)property!=12)Fault=53;return LoopPositionMagic[LoopSelectedPosition];}
int LoopOrders(){LoopPresenceCounts[3]++;return LoopOrderCount;}
ulong LoopOrderTicket(const int index){LoopPresenceCounts[4]++;LoopSelectedOrder=index;return (ulong)(index+1);}
long LoopOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{LoopPresenceCounts[5]++;if((int)property!=15)Fault=54;return LoopOrderMagic[LoopSelectedOrder];}
#define PositionsTotal LoopPositions
#define PositionGetTicket LoopPositionTicket
#define PositionGetInteger LoopPositionInteger
#define OrdersTotal LoopOrders
#define OrderGetTicket LoopOrderTicket
#define OrderGetInteger LoopOrderInteger
#include "../../Include/bot-cua-toi-3/Bot3StrategyPresence.mqh"
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef OrdersTotal
#undef OrderGetTicket
#undef OrderGetInteger
int LoopStage,LoopEffectN,LoopEffectKind,LoopEffectIndex,LoopEffectValue,LoopEarly;
void LoopEffect(const int stage,const int n)
{
   if(stage!=LoopStage || n!=LoopEffectN)return;
   if(LoopEffectKind==1)LoopFlags[LoopEffectIndex]=(uchar)LoopEffectValue;
   else if(LoopEffectKind==2)LoopRetained[LoopEffectIndex]=(uchar)LoopEffectValue;
}
void LoopAtPreparation(){LoopPreparations++;LoopEffect(1,LoopPreparations);}
bool LoopPreparationFailed(){return LoopEarly!=0 && LoopPreparations==LoopEarly;}
Bot3EntryLevelDecision LoopEvaluationProbe(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
                                             const Bot3ReleaseFilterSettings &interest_settings,Bot3ReleaseFilterState &interest,
                                             const Bot3ReleaseFilterSettings &cpi_settings,Bot3ReleaseFilterState &cpi,
                                             Bot3NewsEvents &events,MqlDateTime &cached_calendar,
                                             const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                             Bot3NfpExecution &execution,Bot3NewsSelection &selection,
                                             const Bot3FridaySettings &friday,uchar &friday_closed,
                                             const Bot3SpreadSettings &spread_settings,const double &unit,double &spread,
                                             Bot3PendingQueue &queue,Bot3PendingRestoreSettings &restore,
                                             const int &pending_enabled,const int &maximum_pending,
                                             const Bot3LevelCacheSettings &level_settings,const uint caller_index,
                                             uint &current_index,long &bar_times[],double &upper[],double &lower[],
                                             const Bot3EntryLoopSettings &loop_settings,Bot3EntryLoopState &loop_state,
                                             const Bot3VolumeSettings &volume_settings,Bot3VolumeState &volume_state,
                                             const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                                             long &last_check,long &last_deal_time,const string &suffix,
                                             const double &weight_denominator,const uchar &enabled[],double &volumes[],
                                             const uchar &panel_show,const uchar &panel_tester,const double &panel_manual_lots,
                                             const uchar &day_switch_filter,
                                             const double &balance_change_percent,double &previous_balance,
                                             Bot3EvaluationPrefixSettings &prefix,Bot3EvaluationPrefixState &state,Bot3DisplayState &display)
{
   if(LoopCalls>=9){Fault=51;return BOT3_LEVEL_STOP;}
   LoopIndexes[LoopCalls]=(int)caller_index;LoopCallerFlags[LoopCalls]=(int)prefix.caller_flag;
   LoopCalls++;LoopEffect(2,LoopCalls);return BOT3_LEVEL_STOP;
}
double LoopHistoryProbe(const uchar &show_tester,const string &symbol,const int &magic,
                         const uint &current_index,int &closed[],Bot3StrategyHistoryCache &cache)
{LoopHistoryCalls++;return 0.0;}
#define Bot3EvaluateWithDisplay LoopEvaluationProbe
#define Bot3StrategyClosedProfit LoopHistoryProbe
#include "../../Include/bot-cua-toi-3/Bot3StrategyDispatcher.mqh"
#undef Bot3EvaluateWithDisplay
#undef Bot3StrategyClosedProfit

int OnStart()
{
   if(CheckRun=="")return 1;
   string folder="bot3-strategy-loop\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4c503331 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);

   Bot3NfpFilterSettings nfp_settings;Bot3NfpFilterState nfp;Bot3ReleaseFilterSettings interest_settings,cpi_settings;Bot3ReleaseFilterState interest,cpi;Bot3NewsEvents events;Bot3NewsSelection selection;Bot3NfpExecution execution;MqlDateTime cached;
   Bot3LevelCacheSettings levels;uint current=0;long bars[100];double upper[100],lower[100];Bot3EntryLoopSettings loop;Bot3EntryLoopState loop_state;Bot3VolumeSettings volume;Bot3VolumeState volume_state;
   string peak="",time="",suffix="";long last_check=0,last_deal=0;double volumes[9],denominator=1;uchar enabled[5],show=0,tester=0,day_switch=0;double manual=0,change=0,previous=0,spread=0;
   Bot3PendingRestoreSettings restore;Bot3SpreadSettings spread_settings;Bot3PendingQueue queue;Bot3FridaySettings friday;uchar friday_closed=0;long nfp_history[300],interest_history[300],cpi_history[300];Bot3EvaluationPrefixSettings prefix;Bot3EvaluationPrefixState state;Bot3DisplayState display;
   Bot3PreparationInputs preparation_inputs;Bot3PreparationState preparation;Bot3ProfileRuntimeState profile_state;Bot3ProfileAdjustments adjustments;Bot3StrategyContextInputs context_inputs;Bot3StrategyContextState context_state;
   ZeroMemory(nfp_settings);ZeroMemory(nfp);ZeroMemory(interest_settings);ZeroMemory(cpi_settings);ZeroMemory(interest);ZeroMemory(cpi);ZeroMemory(events);ZeroMemory(selection);ZeroMemory(execution);ZeroMemory(cached);ZeroMemory(levels);ZeroMemory(loop);ZeroMemory(loop_state);ZeroMemory(volume);ZeroMemory(volume_state);ZeroMemory(restore);ZeroMemory(spread_settings);ZeroMemory(queue);ZeroMemory(friday);ZeroMemory(prefix);ZeroMemory(state);ZeroMemory(display);ZeroMemory(preparation_inputs);ZeroMemory(preparation);ZeroMemory(profile_state);ZeroMemory(adjustments);ZeroMemory(context_inputs);ZeroMemory(context_state);
   ArrayInitialize(bars,0);ArrayInitialize(upper,0);ArrayInitialize(lower,0);ArrayInitialize(volumes,0);ArrayInitialize(enabled,0);ArrayInitialize(nfp_history,0);ArrayInitialize(interest_history,0);ArrayInitialize(cpi_history,0);preparation_inputs.symbol="XAUUSD";context_inputs.base_magic=42;

   int loop_closed[9];double loop_total[9],loop_average[9];Bot3StrategyHistoryCache loop_cache;
   const int resident_slots[]={1,5,8,2,9,12,13,14,15};const uchar byte_values[]={1,2,128,255};
   Sample=2000;CheckPoint=0.01;CheckDigits=2;Bid=100;Ask=101;Now=1792713600;Stops=30;Freeze=20;SampleCount=2;FXCurrency="USD";
   preparation_inputs.adjust_lots=1;preparation_inputs.min_change=0.1;
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file),flags_mask=FileReadInteger(file),retained_mask=FileReadInteger(file);
      LoopStage=FileReadInteger(file);LoopEffectN=FileReadInteger(file);LoopEffectKind=FileReadInteger(file);
      LoopEffectIndex=FileReadInteger(file);LoopEffectValue=FileReadInteger(file);LoopEarly=FileReadInteger(file);
      ArrayInitialize(LoopRetained,255);
      for(int i=0;i<9;i++)
      {
         uchar value=byte_values[(id+i)%4];LoopFlags[i]=(flags_mask&(1<<i))!=0 ? value : 0;
         LoopRetained[resident_slots[i]]=(retained_mask&(1<<i))!=0 ? value : 0;
      }
      LoopPositionCount=0;LoopOrderCount=0;
      for(int i=0;i<9;i++)
      {
         if((retained_mask&(1<<i))==0)continue;
         long magic=42+resident_slots[i];
         if(i%2==0)LoopPositionMagic[LoopPositionCount++]=magic;
         else LoopOrderMagic[LoopOrderCount++]=magic;
      }
      LoopCalls=0;LoopPreparations=0;LoopHistoryCalls=0;Fault=0;ArrayInitialize(LoopPresenceCounts,0);
      ArrayInitialize(LoopIndexes,-1);ArrayInitialize(LoopCallerFlags,-1);
   Bot3RunSelectedStrategies(LoopFlags,LoopRetained,adjustments,preparation_inputs,context_inputs,profile_state,context_state,preparation,execution,nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,nfp_history,interest_history,cpi_history,selection,friday,friday_closed,spread_settings,spread,queue,restore,levels,current,bars,upper,lower,loop,loop_state,volume,volume_state,false,peak,time,last_check,last_deal,suffix,denominator,enabled,volumes,show,tester,manual,day_switch,change,previous,prefix,state,display,false,loop_closed,loop_cache,loop_total,loop_average);
      if(LoopPresenceCounts[0]!=1 || LoopPresenceCounts[3]!=1)Fault=52;
      FileWriteInteger(output,id);FileWriteInteger(output,LoopCalls);FileWriteInteger(output,LoopPreparations);
      FileWriteInteger(output,LoopHistoryCalls);FileWriteInteger(output,Fault);
      for(int i=0;i<6;i++)FileWriteInteger(output,LoopPresenceCounts[i]);
      for(int i=0;i<9;i++)FileWriteInteger(output,(int)LoopFlags[i]);
      for(int i=0;i<16;i++)FileWriteInteger(output,(int)LoopRetained[i]);
      for(int i=0;i<9;i++)FileWriteInteger(output,LoopIndexes[i]);
      for(int i=0;i<9;i++)FileWriteInteger(output,LoopCallerFlags[i]);
   }
   if(FileTell(file)!=FileSize(file))return 5;
   FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
