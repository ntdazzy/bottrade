// All three product stages run; terminal services are supplied. No orders.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1EntryProfiles.mqh"
input string CheckRun="";
union Bits { double d;ulong u; };
ulong ValueBits(const double value) { Bits b;b.d=value;return b.u; }
double Sample,CheckPoint,Bid,Ask;long Now,Stops,Freeze;int CheckDigits,Fault,SampleCount;
ulong OrderHash,ATRSymbolHash;int Calls[6],PrintCalls,ATRFrame,ATRPeriod;
ulong TextHash(const string value) { ulong h=(ulong)0xcbf29ce484222325;for(int i=0;i<StringLen(value);i++) { ushort ch=StringGetCharacter(value,i);h^=(ulong)(ch&255);h*=(ulong)0x100000001b3;h^=(ulong)(ch>>8);h*=(ulong)0x100000001b3; }return h; }
ulong CombinedHash,FXServiceHash,FXPriceHash;int FXAccountReads,FXPriceReads;string FXCurrency;
void HashWord(ulong &hash,const ulong word) { for(int j=0;j<8;j++) { hash^=(word>>(j*8))&255;hash*=(ulong)0x100000001b3; } }
string SetupAccount(const ENUM_ACCOUNT_INFO_STRING property) { if(property!=ACCOUNT_CURRENCY) Fault=40;FXAccountReads++;HashWord(FXServiceHash,10);HashWord(FXServiceHash,TextHash(FXCurrency));HashWord(CombinedHash,10);HashWord(CombinedHash,TextHash(FXCurrency));return FXCurrency; }
double SetupClose(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   double prices[]={2.,3.,4.,5.};double value=prices[(FXPriceReads++)%4];
   HashWord(FXPriceHash,TextHash(symbol));HashWord(FXPriceHash,(ulong)frame);HashWord(FXPriceHash,(ulong)shift);HashWord(FXPriceHash,ValueBits(value));
   HashWord(FXServiceHash,11);HashWord(CombinedHash,11);return value;
}
void Event(const int kind) { HashWord(CombinedHash,(ulong)(100+kind)); if(kind<=6) Calls[kind-1]++;else PrintCalls++;for(int i=0;i<8;i++) { OrderHash^=((ulong)kind>>(i*8))&255;OrderHash*=(ulong)0x100000001b3; } }
int FakeATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period) { Event(1);ATRFrame=(int)frame;ATRPeriod=period;ATRSymbolHash=TextHash(symbol);return 17; }
int FakeCopy(const int handle,const int buffer,const int start,const int count,double &target[]) { Event(2);if(handle!=17 || buffer!=0 || start!=0 || count!=100) Fault=22;bool series=ArrayGetAsSeries(target);ArraySetAsSeries(target,false);ArrayResize(target,SampleCount);for(int j=0;j<SampleCount;j++) target[j]=Sample+250.0*j;ArraySetAsSeries(target,series);return SampleCount; }
bool FakeTick(const string symbol,MqlTick &tick) { Event(3);if(symbol!="XAUUSD") Fault=23;tick.time=(datetime)Now;tick.bid=Bid;tick.ask=Ask;return true; }
datetime FakeTime(MqlDateTime &calendar) { Event(4);ZeroMemory(calendar);return (datetime)Now; }
datetime FakeTime() { Event(4);return (datetime)Now; }
double FakeDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property) { Event(5);if(symbol!="XAUUSD" || property!=SYMBOL_POINT) Fault=25;return CheckPoint; }
long FakeInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property) { Event(6);if(symbol!="XAUUSD") Fault=26;if(property==SYMBOL_DIGITS) return CheckDigits;if(property==SYMBOL_TRADE_STOPS_LEVEL) return Stops;if(property==SYMBOL_TRADE_FREEZE_LEVEL) return Freeze;Fault=27;return 0; }
int HCurrentError();
int FakeLastError() { return HCurrentError(); }
void FakePrint(const string text) { Event(7); }
void FakePrint(const string text,const int code) { Event(7);if(code!=HCurrentError()) Fault=30; }
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
#include "../../Include/bot-cua-toi-1/Bot1StrategySetup.mqh"
#undef AccountInfoString
#undef iClose
#undef Print
#undef GetLastError
#undef iATR
#undef CopyBuffer
#undef SymbolInfoTick
#undef TimeCurrent
#undef SymbolInfoDouble
#undef SymbolInfoInteger

#include "../../Include/bot-cua-toi-1/Bot1EvaluationWithDisplay.mqh"
int HMockInfo(const ENUM_MQL_INFO_INTEGER property);
bool HMockSelect(const datetime from,const datetime to);
int HMockTotal();ulong HMockTicket(const int index);
long HMockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property);
string HMockString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property);
double HMockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property);
int HMockResize(ulong &values[],const int count,const int reserve=0);
int HMockResize(long &values[],const int count,const int reserve=0);
#define MQLInfoInteger HMockInfo
#define HistorySelect HMockSelect
#define HistoryDealsTotal HMockTotal
#define HistoryDealGetTicket HMockTicket
#define HistoryDealGetInteger HMockInteger
#define HistoryDealGetString HMockString
#define HistoryDealGetDouble HMockDouble
#define ArrayResize HMockResize
#include "../../Include/bot-cua-toi-1/Bot1StrategyHistory.mqh"
#undef MQLInfoInteger
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef HistoryDealGetInteger
#undef HistoryDealGetString
#undef HistoryDealGetDouble
#undef ArrayResize

#include "../../Include/bot-cua-toi-1/Bot1StrategySelection.mqh"
Bot1PreparationInputs LoopInputs;Bot1PreparationState LoopPreparation;Bot1ProfileRuntimeState LoopProfile;Bot1StrategyContextState LoopContext;
uchar HShowTester;uint HCurrent;int HClosedTrades[8];Bot1StrategyHistoryCache HCache;
int HTapeFile,HErrorMode,HCounts[9],HCalls,HInfoReply,HSelectReply,HTotals[],HTotalCalls,HSelected;uint HLogicalError;
struct HDeal { ulong ticket;string symbol;long types[],entries[],positions[],magics[];int reads[4];double profit,commission,swap; };HDeal HDeals[];
struct HEffect { int api,n,field;ulong word;string text; };HEffect HEffects[];
union HNumber { double value;ulong word; };

int HInput;long HOffsets[8];
int HCurrentError(){return (int)HLogicalError;}
void HLoadStep(const int step){long saved=(long)FileTell(HInput);FileSeek(HInput,HOffsets[step],SEEK_SET);int n=0;
         HInfoReply=FileReadInteger(HInput);HSelectReply=FileReadInteger(HInput);n=FileReadInteger(HInput);ArrayResize(HTotals,n);
         for(int k=0;k<n;k++)HTotals[k]=FileReadInteger(HInput);
         n=FileReadInteger(HInput);for(int k=0;k<n;k++) { HEffect e;HReadEffect(HInput,e);HSetField(e.field,e.word,e.text); }
         n=FileReadInteger(HInput);ArrayResize(HDeals,n);
         for(int k=0;k<n;k++)
         {
            HDeals[k].ticket=(ulong)FileReadLong(HInput);HDeals[k].symbol=HReadText(HInput);
            HLoadLongs(HInput,HDeals[k].types);HLoadLongs(HInput,HDeals[k].entries);HLoadLongs(HInput,HDeals[k].positions);HLoadLongs(HInput,HDeals[k].magics);
            HDeals[k].profit=FileReadDouble(HInput);HDeals[k].commission=FileReadDouble(HInput);HDeals[k].swap=FileReadDouble(HInput);ArrayInitialize(HDeals[k].reads,0);
         }
HTotalCalls=0;HSelected=-1;FileSeek(HInput,saved,SEEK_SET);}
ulong HBits(const double value) { HNumber n;n.value=value;return n.word; }
string HReadText(const int file) { int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n)); }
void HText(const string value)
{ if(value==NULL) {FileWriteInteger(HTapeFile,-1);return;}int n=StringLen(value);FileWriteInteger(HTapeFile,n);if(n>0)FileWriteString(HTapeFile,value,n); }
void HKeysState()
{ bool rev=ArrayGetAsSeries(HCache.positions);int n=ArraySize(HCache.positions);FileWriteInteger(HTapeFile,(int)rev);FileWriteInteger(HTapeFile,n);for(int i=0;i<n;i++)FileWriteLong(HTapeFile,(long)HCache.positions[rev ? n-1-i : i]); }
void HOwnersState()
{ bool rev=ArrayGetAsSeries(HCache.magics);int n=ArraySize(HCache.magics);FileWriteInteger(HTapeFile,(int)rev);FileWriteInteger(HTapeFile,n);for(int i=0;i<n;i++)FileWriteLong(HTapeFile,HCache.magics[rev ? n-1-i : i]); }
void HState()
{
   ulong words[5];words[0]=(ulong)HShowTester;words[1]=(ulong)HCurrent;words[2]=(ulong)(long)LoopContext.magic;words[3]=(ulong)(long)HCache.count;words[4]=(ulong)(long)HCache.total;
   FileWriteArray(HTapeFile,words,0,5);HText(LoopInputs.symbol);FileWriteInteger(HTapeFile,8);FileWriteArray(HTapeFile,HClosedTrades,0,8);
   HKeysState();HOwnersState();FileWriteLong(HTapeFile,(long)HLogicalError);
}
void HSetField(const int field,const ulong word,const string text)
{
   switch(field)
   {
      case 0: HShowTester=(uchar)word;break;case 1: HCurrent=(uint)word;break;case 2: LoopContext.magic=(int)word;break;
      case 3: HCache.count=(int)word;break;case 4: HCache.total=(int)word;break;case 5: LoopInputs.symbol=text;break;
      case 6: ArraySetAsSeries(HCache.positions,word!=0);break;case 7: ArraySetAsSeries(HCache.magics,word!=0);break;
      case 8: HClosedTrades[0]=(int)word;break;
   }
}
void HBegin(const int api,const ulong a,const ulong b,const ulong c,const string value)
{ HState();FileWriteInteger(HTapeFile,api);FileWriteLong(HTapeFile,(long)a);FileWriteLong(HTapeFile,(long)b);FileWriteLong(HTapeFile,(long)c);HText(value); }
void HEnd(const int api,const ulong reply)
{
   FileWriteLong(HTapeFile,(long)reply);HCalls++;HCounts[api]++;if(HErrorMode!=0)HLogicalError=(uint)(9000+HCalls);FileWriteInteger(HTapeFile,(int)HLogicalError);
   for(int i=0;i<ArraySize(HEffects);i++)if(HEffects[i].api==api && HEffects[i].n==HCounts[api])HSetField(HEffects[i].field,HEffects[i].word,HEffects[i].text);
}
void HRecord(const int api,const ulong a,const ulong b,const string value,const ulong reply)
{ HBegin(api,a,b,0,value);HEnd(api,reply); }
int HMockInfo(const ENUM_MQL_INFO_INTEGER property) { int reply=HInfoReply;HRecord(1,(ulong)property,0,NULL,(ulong)(long)reply);return reply; }
bool HMockSelect(const datetime from,const datetime to) { bool reply=HSelectReply!=0;HRecord(2,(ulong)from,(ulong)to,NULL,(ulong)reply);return reply; }
int HMockTotal() { int reply=HTotals[MathMin(HTotalCalls,ArraySize(HTotals)-1)];HTotalCalls++;HRecord(3,0,0,NULL,(ulong)(long)reply);return reply; }
ulong HMockTicket(const int index) { HSelected=index;ulong reply=index>=0 && index<ArraySize(HDeals) ? HDeals[index].ticket : 0;HRecord(4,(ulong)(uint)index,0,NULL,reply);return reply; }
long HNext(const long &values[],int &read) { long value=values[MathMin(read,ArraySize(values)-1)];read++;return value; }
long HMockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property)
{
   long reply=0;
   switch((int)property)
   {
      case 3: reply=HNext(HDeals[HSelected].types,HDeals[HSelected].reads[0]);break;
      case 4: reply=HNext(HDeals[HSelected].entries,HDeals[HSelected].reads[1]);break;
      case 12: reply=HNext(HDeals[HSelected].positions,HDeals[HSelected].reads[2]);break;
      case 11: reply=HNext(HDeals[HSelected].magics,HDeals[HSelected].reads[3]);break;
   }
   HRecord(5,ticket,(ulong)property,NULL,(ulong)reply);return reply;
}
string HMockString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property)
{ string reply=HDeals[HSelected].symbol;HRecord(6,ticket,(ulong)property,reply,0);return reply; }
double HMockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property)
{ double reply=(int)property==9 ? HDeals[HSelected].profit : (int)property==7 ? HDeals[HSelected].commission : HDeals[HSelected].swap;HRecord(7,ticket,(ulong)property,NULL,HBits(reply));return reply; }
int HMockResize(ulong &values[],const int count,const int reserve)
{ HBegin(8,1,(ulong)(uint)count,(ulong)(uint)reserve,NULL);int reply=ArrayResize(values,count,reserve);HKeysState();HOwnersState();HEnd(8,(ulong)(long)reply);return reply; }
int HMockResize(long &values[],const int count,const int reserve)
{ HBegin(8,2,(ulong)(uint)count,(ulong)(uint)reserve,NULL);int reply=ArrayResize(values,count,reserve);HKeysState();HOwnersState();HEnd(8,(ulong)(long)reply);return reply; }
void HLoadLongs(const int file,long &values[])
{ int n=FileReadInteger(file);ArrayResize(values,n);for(int i=0;i<n;i++)values[i]=FileReadLong(file); }
void HReadEffect(const int file,HEffect &e)
{ e.api=FileReadInteger(file);e.n=FileReadInteger(file);e.field=FileReadInteger(file);e.word=0;e.text=NULL;if(e.field==5)e.text=HReadText(file);else e.word=(ulong)FileReadLong(file); }

Bot1StrategySelectionInput LoopFlags;int Output,LoopCalls,HistoryCalls,EffectCall,EffectField,EffectValue;
void SetFlag(const int field,const bool value){switch(field){case 0:LoopFlags.run_strategy_a=value;break;case 1:LoopFlags.run_strategy_b=value;break;case 2:LoopFlags.run_strategy_c=value;break;case 3:LoopFlags.run_strategy_d=value;break;case 4:LoopFlags.run_strategy_e=value;break;case 5:LoopFlags.run_strategy_f=value;break;case 6:LoopFlags.run_strategy_g=value;break;case 7:LoopFlags.run_strategy_h=value;break;}}
uint LoopMask(){uint mask=0;if(LoopFlags.run_strategy_a)mask|=1;if(LoopFlags.run_strategy_b)mask|=2;if(LoopFlags.run_strategy_c)mask|=4;if(LoopFlags.run_strategy_d)mask|=8;if(LoopFlags.run_strategy_e)mask|=16;if(LoopFlags.run_strategy_f)mask|=32;if(LoopFlags.run_strategy_g)mask|=64;if(LoopFlags.run_strategy_h)mask|=128; return mask;}
Bot1EntryLevelDecision LoopEvaluate(const Bot1NfpFilterSettings &nfp_settings,Bot1NfpFilterState &nfp,
                                             const Bot1ReleaseFilterSettings &interest_settings,Bot1ReleaseFilterState &interest,
                                             const Bot1ReleaseFilterSettings &cpi_settings,Bot1ReleaseFilterState &cpi,
                                             Bot1NewsEvents &events,MqlDateTime &cached_calendar,
                                             const long &nfp_history[],const long &interest_history[],const long &cpi_history[],
                                             Bot1NfpExecution &execution,Bot1NewsSelection &selection,
                                             const Bot1FridaySettings &friday,uchar &friday_closed,
                                             const Bot1SpreadSettings &spread_settings,const double &unit,double &spread,
                                             Bot1PendingQueue &queue,Bot1PendingRestoreSettings &restore,
                                             const int &pending_enabled,const int &maximum_pending,
                                             const Bot1LevelCacheSettings &level_settings,const uint caller_index,
                                             uint &current_index,long &bar_times[],double &upper[],double &lower[],
                                             const Bot1EntryLoopSettings &loop_settings,Bot1EntryLoopState &loop_state,
                                             const Bot1VolumeSettings &volume_settings,Bot1VolumeState &volume_state,
                                             const bool reset_on_withdrawal,const string &peak_key,const string &time_key,
                                             long &last_check,long &last_deal_time,const string &suffix,double &volumes[],
                                             const uchar &panel_show,const uchar &panel_tester,const int &panel_mode,
                                             const double &panel_trade_risk,const int &panel_balance_step,
                                             const uchar &day_switch_filter,
                                             const double &balance_change_percent,double &previous_balance,
                                             Bot1EvaluationPrefixSettings &prefix,Bot1EvaluationPrefixState &state,Bot1DisplayState &display)
{
FileWriteInteger(Output,(int)caller_index);
      FileWriteLong(Output,(long)LoopProfile.random_seed);
      FileWriteLong(Output,(long)ValueBits(LoopInputs.reference));
      FileWriteLong(Output,(long)LoopInputs.entry.confirmation_frame);
      FileWriteLong(Output,(long)LoopInputs.entry.hour1_flag);
      FileWriteLong(Output,(long)LoopInputs.entry.older_width);
      FileWriteLong(Output,(long)LoopInputs.entry.recent_width);
      FileWriteLong(Output,(long)LoopInputs.entry.last_shift);
      FileWriteLong(Output,(long)ValueBits(LoopInputs.entry.gap_points));
      FileWriteLong(Output,(long)ValueBits(LoopInputs.buy_offset));
      FileWriteLong(Output,(long)ValueBits(LoopInputs.sell_offset));
      FileWriteLong(Output,(long)ValueBits(LoopInputs.nearby_radius));
      FileWriteLong(Output,(long)LoopInputs.expiration_hours);
      FileWriteLong(Output,(long)ValueBits(LoopInputs.stop_distance));
      FileWriteLong(Output,(long)ValueBits(LoopInputs.target_distance));
      FileWriteLong(Output,(long)ValueBits(LoopInputs.trail_distance));
      FileWriteLong(Output,(long)ValueBits(LoopInputs.trail_start));
      FileWriteLong(Output,(long)ValueBits(LoopInputs.trail_limit));
      FileWriteLong(Output,(long)ValueBits(LoopInputs.trail_step));
      FileWriteLong(Output,(long)LoopInputs.aux_hour1);
      FileWriteLong(Output,(long)LoopInputs.aux_scan50);
      FileWriteLong(Output,(long)LoopInputs.aux_older);
      FileWriteLong(Output,(long)LoopInputs.aux_recent);
      FileWriteLong(Output,(long)ValueBits(LoopInputs.aux_offset));
      FileWriteLong(Output,(long)LoopInputs.indicator_period);
      FileWriteLong(Output,(long)LoopInputs.indicator_day);
      FileWriteLong(Output,(long)LoopInputs.native_622a8);
      FileWriteLong(Output,(long)LoopInputs.native_622ec);
      FileWriteLong(Output,(long)LoopInputs.native_622f0);
      FileWriteLong(Output,(long)LoopProfile.native_62360);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.scale));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.lot_scale));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.unit));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.spread));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.max_spread));
      FileWriteLong(Output,(long)LoopPreparation.feature_flag);
      FileWriteLong(Output,(long)LoopPreparation.freeze_buffer);
      FileWriteLong(Output,(long)LoopPreparation.entry_frame);
      FileWriteLong(Output,(long)LoopPreparation.older_width);
      FileWriteLong(Output,(long)LoopPreparation.recent_width);
      FileWriteLong(Output,(long)LoopPreparation.last_shift);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.gap_points));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.buy_offset));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.sell_offset));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.nearby_radius));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.stop_distance));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.target_distance));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.trail_distance));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.trail_start));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.trail_limit));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.trail_step));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.trigger_distance));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.locked_distance));
      FileWriteLong(Output,(long)LoopPreparation.aux_frame);
      FileWriteLong(Output,(long)LoopPreparation.aux_scan);
      FileWriteLong(Output,(long)LoopPreparation.aux_older);
      FileWriteLong(Output,(long)LoopPreparation.aux_recent);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.aux_offset));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.min_change));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.stop_min_price));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.freeze_min_price));
      FileWriteLong(Output,(long)LoopPreparation.expiration_seconds);
      FileWriteLong(Output,(long)LoopPreparation.expiration);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_623e8));
      FileWriteLong(Output,(long)LoopPreparation.native_623f0);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_623f8));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_62400));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_62408));
      FileWriteLong(Output,(long)LoopPreparation.native_62410);
      FileWriteLong(Output,(long)LoopPreparation.native_62414);
      FileWriteLong(Output,(long)LoopPreparation.omit_real_sl_tp);
      FileWriteLong(Output,(long)LoopPreparation.mode);
      FileWriteLong(Output,(long)LoopPreparation.native_62420);
      FileWriteLong(Output,(long)LoopPreparation.check_free_margin);
      FileWriteLong(Output,(long)LoopPreparation.native_62428);
      FileWriteLong(Output,(long)LoopPreparation.native_62458);
      FileWriteLong(Output,(long)LoopPreparation.native_6248c);
      FileWriteLong(Output,(long)LoopPreparation.native_62490);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_62510));
      FileWriteLong(Output,(long)LoopPreparation.native_62518);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_62528));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_62530));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_62538));
      FileWriteLong(Output,(long)LoopPreparation.native_62540);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_62548));
      FileWriteLong(Output,(long)LoopPreparation.native_62550);
      FileWriteLong(Output,(long)LoopPreparation.native_624d8);
      FileWriteLong(Output,(long)LoopPreparation.native_624ec);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_624f8));
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.native_62500));
      FileWriteLong(Output,(long)LoopPreparation.native_62508);
      FileWriteLong(Output,(long)LoopPreparation.expiration_hours);
      FileWriteLong(Output,(long)ValueBits(LoopPreparation.point));
      FileWriteLong(Output,(long)LoopPreparation.strategy_index);
      FileWriteLong(Output,(long)LoopPreparation.indicator_handle);
      FileWriteLong(Output,ArraySize(LoopPreparation.indicator_values));FileWriteLong(Output,(long)ArrayGetAsSeries(LoopPreparation.indicator_values));FileWriteLong(Output,(long)TextHash(LoopPreparation.comment));
      for(int j=0;j<6;j++) FileWriteLong(Output,Calls[j]);
      FileWriteLong(Output,(long)LoopPreparation.tick.time);FileWriteLong(Output,(long)ValueBits(LoopPreparation.tick.bid));FileWriteLong(Output,(long)ValueBits(LoopPreparation.tick.ask));
      FileWriteLong(Output,LoopPreparation.calendar.year);
      FileWriteLong(Output,LoopPreparation.calendar.mon);
      FileWriteLong(Output,LoopPreparation.calendar.day);
      FileWriteLong(Output,LoopPreparation.calendar.hour);
      FileWriteLong(Output,LoopPreparation.calendar.min);
      FileWriteLong(Output,LoopPreparation.calendar.sec);
      FileWriteLong(Output,LoopPreparation.calendar.day_of_week);
      FileWriteLong(Output,LoopPreparation.calendar.day_of_year);
      FileWriteLong(Output,(long)OrderHash);FileWriteLong(Output,PrintCalls);
      FileWriteLong(Output,ATRFrame);FileWriteLong(Output,ATRPeriod);FileWriteLong(Output,(long)ATRSymbolHash);
      FileWriteLong(Output,(long)LoopContext.magic);FileWriteLong(Output,(long)ValueBits(LoopContext.converted_value));FileWriteLong(Output,(long)ValueBits(LoopInputs.reference));
      FileWriteLong(Output,FXAccountReads);FileWriteLong(Output,FXPriceReads);FileWriteLong(Output,(long)FXPriceHash);FileWriteLong(Output,(long)FXServiceHash);FileWriteLong(Output,(long)CombinedHash);
      int comment_length=StringLen(LoopContext.order_comment);FileWriteInteger(Output,comment_length);if(comment_length>0) FileWriteString(Output,LoopContext.order_comment,comment_length);
      int n=ArraySize(LoopPreparation.indicator_values);FileWriteInteger(Output,n);bool series=ArrayGetAsSeries(LoopPreparation.indicator_values);for(int i=0;i<n;i++)FileWriteLong(Output,(long)ValueBits(LoopPreparation.indicator_values[series ? n-1-i : i]));

   LoopCalls++;if(LoopCalls==EffectCall)SetFlag(EffectField,EffectValue!=0);
   return BOT1_LEVEL_STOP;
}
double LoopHistory(const uchar &show_tester,const string &symbol,const int &magic,const uint &current,int &closed[],Bot1StrategyHistoryCache &cache)
{HLoadStep(HistoryCalls);HistoryCalls++;double value=Bot1StrategyClosedProfit(show_tester,symbol,magic,current,closed,cache);HState();FileWriteLong(HTapeFile,(long)HBits(value));return value;}
#define Bot1EvaluateWithDisplay LoopEvaluate
#define Bot1StrategyClosedProfit LoopHistory
#include "../../Include/bot-cua-toi-1/Bot1StrategyDispatcher.mqh"
#undef Bot1EvaluateWithDisplay
#undef Bot1StrategyClosedProfit

double ExtraDouble(const int id,const int j) { return .5+(double)id*.125+(double)j*.25; }
int ExtraInt(const int id,const int j) { return (id%2==0 ? 1 : -1)*(id+j+1); }
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++) { ushort ch=StringGetCharacter(CheckRun,i);if(!((ch>='a' && ch<='z') || (ch>='0' && ch<='9') || ch=='-')) return 4; }
   string folder="bot1-real-history-loop\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x52504631 || version!=1 || count<1 || count>10000) { FileClose(source);return 7; }
   Output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(Output==INVALID_HANDLE) { FileClose(source);return 8; }

   HInput=source;HTapeFile=FileOpen(folder+"history-tape.bin",FILE_WRITE|FILE_BIN);if(HTapeFile==INVALID_HANDLE)return 12;
   FileWriteInteger(HTapeFile,1397244721);FileWriteInteger(HTapeFile,1);FileWriteInteger(HTapeFile,count);
   FileWriteInteger(Output,1280528433);FileWriteInteger(Output,1);FileWriteInteger(Output,count);FileWriteInteger(Output,127);
   for(int id=0;id<count;id++)
   {
      int actual_id=FileReadInteger(source),index=FileReadInteger(source),hl=FileReadInteger(source);uint seed=(uint)FileReadInteger(source);
      if(actual_id!=id || index<0 || index>=8 || (hl!=0 && hl!=1)) { Fault=9;break; }
      Bot1ProfileAdjustments adjustments;adjustments.randomization=FileReadDouble(source);adjustments.price_delta=FileReadDouble(source);adjustments.stop_delta=FileReadDouble(source);adjustments.target_delta=FileReadDouble(source);adjustments.trail_delta=FileReadDouble(source);
      Sample=2000.0+id*.5;CheckPoint=id%2!=0 ? .001 : .01;CheckDigits=id%2!=0 ? 3 : 2;Bid=2600.0;Ask=2600.25;Now=1792713600;Stops=30;Freeze=20;SampleCount=2+id%2;
      ZeroMemory(LoopInputs);LoopInputs.symbol="XAUUSD";LoopInputs.comment="case"+IntegerToString(id);LoopInputs.variable_distances=1;LoopInputs.adjust_lots=1;LoopInputs.max_spread=500.;LoopInputs.feature_flag=1;LoopInputs.freeze_buffer_flag=1;LoopInputs.virtual_expiration=(uchar)(id%2);LoopInputs.min_change=.1;
      LoopInputs.native_62218=ExtraDouble(id,0);
      LoopInputs.native_62220=(uchar)((id+1)%256);
      LoopInputs.native_62228=ExtraDouble(id,2);
      LoopInputs.native_62230=ExtraDouble(id,3);
      LoopInputs.native_62238=ExtraDouble(id,4);
      LoopInputs.native_62240=(uchar)((id+5)%256);
      LoopInputs.native_6a5d8=ExtraInt(id,6);
      LoopInputs.omit_real_sl_tp=(uchar)((id+7)%256);
      LoopInputs.virtual_stops=(uchar)((id+8)%256);
      LoopInputs.native_6a608=ExtraInt(id,9);
      LoopInputs.check_free_margin=(uchar)((id+10)%256);
      LoopInputs.native_62268=(uchar)((id+11)%256);
      LoopInputs.native_622a8=(uchar)((id+12)%256);
      LoopInputs.native_622ec=ExtraInt(id,13);
      LoopInputs.native_622f0=(uchar)((id+14)%256);
      LoopInputs.native_62390=ExtraDouble(id,15);
      LoopInputs.native_62398=(uchar)((id+16)%256);
      LoopInputs.native_623a8=ExtraDouble(id,17);
      LoopInputs.native_6a740=ExtraDouble(id,18);
      LoopInputs.native_623b0=ExtraDouble(id,19);
      LoopInputs.native_6a748=ExtraInt(id,20);
      LoopInputs.native_6a750=ExtraDouble(id,21);
      LoopInputs.native_6a768=ExtraInt(id,22);
      ZeroMemory(LoopProfile);LoopProfile.random_seed=seed;LoopProfile.native_62360=70001;
      ZeroMemory(LoopPreparation);ArrayInitialize(Calls,0);PrintCalls=0;OrderHash=(ulong)0xcbf29ce484222325;ATRFrame=0;ATRPeriod=0;ATRSymbolHash=0;
      Bot1StrategyContextInputs context_inputs;ZeroMemory(context_inputs);
      int control=id/8;uchar keep[]={0,1,255};int magics[]={-2147483648,0,2147483647};
      context_inputs.keep_comment=keep[(id+2*control)%3];context_inputs.base_magic=magics[(id/3+control)%3];
      context_inputs.comment_prefix=id%2!=0 ? "Vàng 🚀" : "";context_inputs.symbol_suffix=id%2!=0 ? ".a" : "";
      ZeroMemory(LoopContext);LoopContext.order_comment="cũ"+IntegerToString(id);LoopContext.converted_value=-987.5;
      string currencies[]={"USD","EUR","JPY","CHF","VND"};FXCurrency=currencies[(id/5+index)%5];FXAccountReads=0;FXPriceReads=0;
      CombinedHash=(ulong)0xcbf29ce484222325;FXServiceHash=(ulong)0xcbf29ce484222325;FXPriceHash=(ulong)0xcbf29ce484222325;

      int mask=FileReadInteger(source),hour=FileReadInteger(source);EffectCall=FileReadInteger(source);EffectField=FileReadInteger(source);EffectValue=FileReadInteger(source);
      HShowTester=(uchar)FileReadInteger(source);HCache.count=FileReadInteger(source);HCache.total=FileReadInteger(source);HCurrent=0;
      int rev=FileReadInteger(source),n=FileReadInteger(source);ArraySetAsSeries(HCache.positions,false);ArrayResize(HCache.positions,n);for(int i=0;i<n;i++)HCache.positions[i]=(ulong)FileReadLong(source);ArraySetAsSeries(HCache.positions,rev!=0);
      rev=FileReadInteger(source);n=FileReadInteger(source);ArraySetAsSeries(HCache.magics,false);ArrayResize(HCache.magics,n);for(int i=0;i<n;i++)HCache.magics[i]=FileReadLong(source);ArraySetAsSeries(HCache.magics,rev!=0);
      HErrorMode=FileReadInteger(source);n=FileReadInteger(source);if(n!=8)return 13;for(int i=0;i<n;i++){int size=FileReadInteger(source);if(size<0 || size>1000000)return 14;HOffsets[i]=(long)FileTell(source);FileSeek(source,size,SEEK_CUR);}
      HCalls=0;HLogicalError=5017;ArrayInitialize(HCounts,0);ArrayResize(HEffects,0);
      FileWriteInteger(HTapeFile,id);long history_size_at=(long)FileTell(HTapeFile);FileWriteInteger(HTapeFile,0);long history_start=(long)FileTell(HTapeFile);
      for(int i=0;i<8;i++)SetFlag(i,(mask&(1<<i))!=0);LoopCalls=0;HistoryCalls=0;
   Bot1NfpFilterSettings nfp_settings;Bot1NfpFilterState nfp;Bot1ReleaseFilterSettings interest_settings,cpi_settings;Bot1ReleaseFilterState interest,cpi;Bot1NewsEvents events;Bot1NewsSelection selection;Bot1NfpExecution execution;MqlDateTime cached;
   Bot1LevelCacheSettings levels;long bars[100];double upper[100],lower[100];Bot1EntryLoopSettings loop;Bot1EntryLoopState loop_state;Bot1VolumeSettings volume;Bot1VolumeState volume_state;
   string peak="",time="",suffix="";long last_check=0,last_deal=0;double volumes[8];uchar show=0,day_switch=0;int mode=0,balance_step=0;double risk=0,change=0,previous=0,spread=0;
   Bot1PendingRestoreSettings restore;Bot1SpreadSettings spread_settings;Bot1PendingQueue queue;Bot1FridaySettings friday;uchar friday_closed=0;long nfp_history[300],interest_history[300],cpi_history[300];Bot1EvaluationPrefixSettings prefix;Bot1EvaluationPrefixState evaluation_state;Bot1DisplayState display;

   ZeroMemory(nfp_settings);ZeroMemory(nfp);ZeroMemory(interest_settings);ZeroMemory(cpi_settings);ZeroMemory(interest);ZeroMemory(cpi);ZeroMemory(events);ZeroMemory(selection);ZeroMemory(execution);ZeroMemory(cached);ZeroMemory(levels);ZeroMemory(loop);ZeroMemory(loop_state);ZeroMemory(volume);ZeroMemory(volume_state);ZeroMemory(restore);ZeroMemory(spread_settings);ZeroMemory(queue);ZeroMemory(friday);ZeroMemory(prefix);ZeroMemory(evaluation_state);ZeroMemory(display);
   ArrayInitialize(bars,0);ArrayInitialize(upper,0);ArrayInitialize(lower,0);ArrayInitialize(volumes,0);ArrayInitialize(nfp_history,0);ArrayInitialize(interest_history,0);ArrayInitialize(cpi_history,0);

   double loop_total[8],loop_average[8];

      for(int i=0;i<8;i++){HClosedTrades[i]=10+i;loop_total[i]=10.25+i;loop_average[i]=-300.5-i;}
      long position=(long)FileTell(Output);FileWriteInteger(Output,id);FileWriteInteger(Output,0);
   Bot1RunEnabledStrategies(LoopFlags,hl!=0,adjustments,LoopInputs,context_inputs,LoopProfile,LoopContext,LoopPreparation,execution,nfp_settings,nfp,interest_settings,interest,cpi_settings,cpi,events,cached,nfp_history,interest_history,cpi_history,selection,friday,friday_closed,spread_settings,spread,queue,restore,levels,HCurrent,bars,upper,lower,loop,loop_state,volume,volume_state,false,peak,time,last_check,last_deal,suffix,volumes,show,HShowTester,mode,risk,balance_step,day_switch,change,previous,prefix,evaluation_state,display,hour!=0,HClosedTrades,HCache,loop_total,loop_average);
      long finished=(long)FileTell(Output);FileSeek(Output,position+4,SEEK_SET);FileWriteInteger(Output,LoopCalls);FileSeek(Output,finished,SEEK_SET);
      FileWriteInteger(Output,(int)LoopMask());FileWriteInteger(Output,HistoryCalls);
      for(int i=0;i<8;i++)FileWriteInteger(Output,HClosedTrades[i]);
      for(int i=0;i<8;i++)FileWriteLong(Output,(long)ValueBits(loop_total[i]));
      for(int i=0;i<8;i++)FileWriteLong(Output,(long)ValueBits(loop_average[i]));
      HState();long history_end=(long)FileTell(HTapeFile);FileSeek(HTapeFile,history_size_at,SEEK_SET);FileWriteInteger(HTapeFile,(int)(history_end-history_start));FileSeek(HTapeFile,history_end,SEEK_SET);


   }
   if(FileTell(source)!=FileSize(source)) Fault=10;FileClose(source);FileClose(Output);FileClose(HTapeFile);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);return Fault;
}
