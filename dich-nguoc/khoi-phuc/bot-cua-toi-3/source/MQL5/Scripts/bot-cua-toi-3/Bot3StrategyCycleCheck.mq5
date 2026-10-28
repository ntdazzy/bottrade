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
int IntegrationInvocation=0;
int FakeCopy(const int handle,const int buffer,const int start,const int count,double &target[]) { Event(2);if(IntegrationInvocation==2) return 0;if(handle!=17 || buffer!=0 || start!=0 || count!=100) Fault=22;ArrayResize(target,SampleCount);for(int j=0;j<SampleCount;j++) target[j]=Sample+250.0*j;return SampleCount; }
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
int ProbeCalls=0;double SeenUnit[2],SeenSpread[2],SeenBid[2];uint SeenIndex[2],SeenCaller[2];int SeenHour[2],SeenMode[2],SeenStep[2],SeenPending[2],SeenMaximum[2],SeenBaseMagic[2];ulong SeenDeviation[2];long SeenExpiration[2];
Bot3EntryLevelDecision Bot3ProbeEvaluate(const Bot3NfpFilterSettings &nfp_settings,Bot3NfpFilterState &nfp,
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
   int i=ProbeCalls++;if(i>=2)return BOT3_LEVEL_STOP;
   SeenUnit[i]=unit;SeenSpread[i]=spread;SeenBid[i]=execution.tick.bid;SeenIndex[i]=current_index;SeenCaller[i]=caller_index;SeenHour[i]=cached_calendar.hour;
   SeenMode[i]=(int)volume_state.mode;SeenStep[i]=volume_state.balance_step;SeenPending[i]=pending_enabled;SeenMaximum[i]=maximum_pending;SeenExpiration[i]=(long)restore.expiration_base;SeenBaseMagic[i]=execution.magic_base;SeenDeviation[i]=execution.deviation;
   if(i==0) { execution.tick.bid=321.0;execution.tick.ask=322.0;execution.deviation=654321;spread=9.5;current_index=7;cached_calendar.hour=19;restore.expiration_base=(datetime)123456;volume_state.mode=9999;volume_state.balance_step=44; }
   return i==1 ? BOT3_LEVEL_STOP : BOT3_LEVEL_NEW_BAR;
}
#include "../../Include/bot-cua-toi-3/Bot3StrategyHistory.mqh"
Bot3PreparationInputs CycleInputs;Bot3PreparationState CyclePreparation;
Bot3StrategyContextState CycleContext;Bot3NfpExecution CycleExecution;uint CycleCurrent=0;
int StrategyHistoryCalls=0,HistoryCurrent=-1,HistoryMagic=0;uchar HistoryTester=0;string HistorySymbol="";
double Bot3ProbeHistory(const uchar &show_tester,const string &symbol,const int &magic,
                           const uint &current_index,int &closed[],Bot3StrategyHistoryCache &cache)
{
   StrategyHistoryCalls++;HistoryCurrent=(int)current_index;HistoryMagic=magic;
   HistoryTester=show_tester;HistorySymbol=symbol;closed[current_index]=2;
   CycleInputs.symbol="AFTER";CycleContext.magic=777;CycleCurrent=3;
   return 12.0;
}
#define Bot3StrategyClosedProfit Bot3ProbeHistory
#define Bot3EvaluateWithDisplay Bot3ProbeEvaluate
#include "../../Include/bot-cua-toi-3/Bot3StrategyCycle.mqh"
#undef Bot3EvaluateWithDisplay
#undef Bot3StrategyClosedProfit


int OnStart()
{
   uchar strategy_enabled=1;
   Bot3NfpFilterSettings nfp_settings;Bot3NfpFilterState nfp;Bot3ReleaseFilterSettings interest_settings,cpi_settings;Bot3ReleaseFilterState interest,cpi;Bot3NewsEvents events;Bot3NewsSelection selection;MqlDateTime cached;
   Bot3LevelCacheSettings levels;long bars[100];double upper[100],lower[100];Bot3EntryLoopSettings loop;Bot3EntryLoopState loop_state;Bot3VolumeSettings volume;Bot3VolumeState volume_state;
   string peak="",time="",suffix="";long last_check=0,last_deal=0;double volumes[9],denominator=1;uchar enabled[5],show=0,tester=0,day_switch=0;double manual=0,change=0,previous=0,spread=0;
   Bot3PendingRestoreSettings restore;Bot3SpreadSettings spread_settings;Bot3PendingQueue queue;Bot3FridaySettings friday;uchar friday_closed=0;long nfp_history[300],interest_history[300],cpi_history[300];Bot3EvaluationPrefixSettings prefix;Bot3EvaluationPrefixState state;Bot3DisplayState display;
   Bot3ProfileRuntimeState profile_state;Bot3ProfileAdjustments adjustments;Bot3StrategyContextInputs context_inputs;
   ZeroMemory(nfp_settings);ZeroMemory(nfp);ZeroMemory(interest_settings);ZeroMemory(cpi_settings);ZeroMemory(interest);ZeroMemory(cpi);ZeroMemory(events);ZeroMemory(selection);ZeroMemory(CycleExecution);ZeroMemory(cached);ZeroMemory(levels);ZeroMemory(loop);ZeroMemory(loop_state);ZeroMemory(volume);ZeroMemory(volume_state);ZeroMemory(restore);ZeroMemory(spread_settings);ZeroMemory(queue);ZeroMemory(friday);ZeroMemory(prefix);ZeroMemory(state);ZeroMemory(display);ZeroMemory(CycleInputs);ZeroMemory(CyclePreparation);ZeroMemory(profile_state);ZeroMemory(adjustments);ZeroMemory(context_inputs);ZeroMemory(CycleContext);
   ArrayInitialize(bars,0);ArrayInitialize(upper,0);ArrayInitialize(lower,0);ArrayInitialize(volumes,0);ArrayInitialize(enabled,0);ArrayInitialize(nfp_history,0);ArrayInitialize(interest_history,0);ArrayInitialize(cpi_history,0);Sample=2000;CheckPoint=0.01;CheckDigits=2;Bid=100;Ask=101;Now=1792713600;Stops=30;Freeze=20;SampleCount=2;FXCurrency="USD";
   CycleInputs.symbol="XAUUSD";CycleInputs.variable_distances=1;CycleInputs.adjust_lots=1;CycleInputs.min_change=0.1;context_inputs.base_magic=42;CycleExecution.deviation=123456;

   int strategy_closed[9];double strategy_totals[9],strategy_average[9];
   Bot3StrategyHistoryCache strategy_history;
   ArrayInitialize(strategy_closed,0);ArrayInitialize(strategy_totals,-5.0);ArrayInitialize(strategy_average,-5.0);
   strategy_closed[1]=3;
   if(CheckRun=="")return 1;
   IntegrationInvocation=1;
   Bot3SetupEvaluateAndUpdateStatistics(0,strategy_enabled,adjustments,CycleInputs,context_inputs,profile_state,CycleContext,CyclePreparation,CycleExecution,nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,nfp_history,interest_history,cpi_history,selection,friday,friday_closed,spread_settings,spread,queue,restore,levels,CycleCurrent,bars,upper,lower,loop,loop_state,volume,volume_state,false,peak,time,last_check,last_deal,suffix,denominator,enabled,volumes,show,tester,manual,day_switch,change,previous,prefix,state,display,false,strategy_closed,strategy_history,strategy_totals,strategy_average);
   int calls_after_first=StrategyHistoryCalls;
   IntegrationInvocation=2;
   Bot3EntryLevelDecision second_result=Bot3SetupEvaluateAndUpdateStatistics(1,strategy_enabled,adjustments,CycleInputs,context_inputs,profile_state,CycleContext,CyclePreparation,CycleExecution,nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,nfp_history,interest_history,cpi_history,selection,friday,friday_closed,spread_settings,spread,queue,restore,levels,CycleCurrent,bars,upper,lower,loop,loop_state,volume,volume_state,false,peak,time,last_check,last_deal,suffix,denominator,enabled,volumes,show,tester,manual,day_switch,change,previous,prefix,state,display,true,strategy_closed,strategy_history,strategy_totals,strategy_average);
   uint failures=0;
   if(ProbeCalls!=2) failures|=1;
   if(SeenUnit[0]!=0.01 || SeenUnit[1]!=0.01) failures|=2;
   if(SeenSpread[0]!=1.0 || SeenSpread[1]!=9.5) failures|=4;
   if(SeenBid[0]!=100.0 || SeenBid[1]!=321.0) failures|=8;
   if(SeenIndex[0]!=0 || SeenIndex[1]!=7 || SeenCaller[0]!=0 || SeenCaller[1]!=1 || SeenHour[0]!=0 || SeenHour[1]!=19) failures|=16;
   if(SeenExpiration[1]!=123456 || SeenMode[1]!=9999 || SeenStep[1]!=44) failures|=32;
   if(SeenPending[0]==-12345 || SeenMaximum[0]==-12345) failures|=64;
   if(CyclePreparation.tick.bid!=321.0 || CyclePreparation.spread!=9.5 || CyclePreparation.strategy_index!=3 || CyclePreparation.calendar.hour!=19 || CyclePreparation.expiration!=123456) failures|=128;
   if(SeenBaseMagic[0]!=42 || SeenBaseMagic[1]!=42 || SeenDeviation[0]!=123456 || SeenDeviation[1]!=654321) failures|=256;
   if(calls_after_first!=0 || StrategyHistoryCalls!=1) failures|=512;
   if(HistoryCurrent!=7 || HistoryMagic!=47 || HistoryTester!=0 || HistorySymbol!="XAUUSD") failures|=1024;
   if(strategy_closed[7]!=2 || strategy_closed[1]!=3 || strategy_totals[1]!=12.0 || strategy_average[1]!=4.0 || strategy_totals[0]!=-5.0) failures|=2048;
   if(second_result!=BOT3_LEVEL_STOP) failures|=4096;
   if(CyclePreparation.strategy_index!=3 || CycleExecution.symbol!="AFTER" || CycleExecution.strategy_magic!=777) failures|=8192;
   string file="bot3-strategy-cycle\\"+CheckRun+"\\result.bin";int out=FileOpen(file,FILE_WRITE|FILE_BIN);if(out==INVALID_HANDLE)return 2;
   FileWriteInteger(out,(int)failures);FileWriteInteger(out,ProbeCalls);FileClose(out);return 0;
}
