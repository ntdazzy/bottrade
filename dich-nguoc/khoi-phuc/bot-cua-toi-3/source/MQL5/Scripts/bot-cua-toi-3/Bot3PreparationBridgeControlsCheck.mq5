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
int FakeCopy(const int handle,const int buffer,const int start,const int count,double &target[]) { Event(2);if(handle!=17 || buffer!=0 || start!=0 || count!=100) Fault=22;ArrayResize(target,SampleCount);for(int j=0;j<SampleCount;j++) target[j]=Sample+250.0*j;return SampleCount; }
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
#include "../../Include/bot-cua-toi-3/Bot3EvaluationBridge.mqh"
double ExtraDouble(const int id,const int j) { return .5+(double)id*.125+(double)j*.25; }
int ExtraInt(const int id,const int j) { return (id%2==0 ? 1 : -1)*(id+j+1); }

int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++) { ushort ch=StringGetCharacter(CheckRun,i);if(!((ch>='a' && ch<='z') || (ch>='0' && ch<='9') || ch=='-')) return 4; }
   string folder="bot3-preparation-bridge-controls\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x52504633 || version!=1 || count<1 || count>10000 || FileSize(source)!=(ulong)12+(ulong)count*68) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE) { FileClose(source);return 8; }

   int bridge_output=FileOpen(folder+"bridge-results.bin",FILE_WRITE|FILE_BIN);if(bridge_output==INVALID_HANDLE) return 12;
   FileWriteInteger(bridge_output,1112688433);FileWriteInteger(bridge_output,1);FileWriteInteger(bridge_output,count);FileWriteInteger(bridge_output,69);
   FileWriteInteger(output,1398100019);FileWriteInteger(output,1);FileWriteInteger(output,count);FileWriteInteger(output,132);
   for(int id=0;id<count;id++)
   {
      int actual_id=FileReadInteger(source),index=FileReadInteger(source);uint seed=(uint)FileReadInteger(source);if(actual_id!=id || index<0 || index>=9) { Fault=9;break; }
      Bot3ProfileAdjustments adjustments;adjustments.randomization=FileReadDouble(source);adjustments.price_delta=FileReadDouble(source);adjustments.stop_delta=FileReadDouble(source);adjustments.target_delta=FileReadDouble(source);adjustments.trail_delta=FileReadDouble(source);adjustments.aux_delta=FileReadDouble(source);adjustments.lock_delta=FileReadDouble(source);
      Sample=2000.0+id*.5;CheckPoint=id%2!=0 ? .001 : .01;CheckDigits=id%2!=0 ? 3 : 2;Bid=2600.0;Ask=2600.25;Now=1792713600;Stops=30;Freeze=20;SampleCount=2+id%2;
      Bot3PreparationInputs inputs;ZeroMemory(inputs);inputs.symbol="XAUUSD";inputs.comment="case"+IntegerToString(id);inputs.reference=1000.;inputs.variable_distances=1;inputs.adjust_lots=1;inputs.max_spread=500.;inputs.feature_flag=1;inputs.freeze_buffer_flag=1;inputs.virtual_expiration=(uchar)(id%2);inputs.min_change=.1;
      inputs.native_6d250=ExtraDouble(id,0);
      inputs.native_6d258=(uchar)((id+1)%256);
      inputs.native_6d260=ExtraDouble(id,2);
      inputs.native_6d268=ExtraDouble(id,3);
      inputs.native_6d270=ExtraDouble(id,4);
      inputs.native_6d278=(uchar)((id+5)%256);
      inputs.native_1d6fa8=ExtraInt(id,6);
      inputs.native_1d6fc0=(uchar)((id+7)%256);
      inputs.virtual_stops=(uchar)((id+8)%256);
      inputs.native_1d6fe8=ExtraInt(id,9);
      inputs.native_1d7178=(uchar)((id+10)%256);
      inputs.native_6d2a3=(uchar)((id+11)%256);
      inputs.native_6d2e0=ExtraInt(id,12);
      inputs.management_timeframe=ExtraInt(id,13);
      inputs.native_6d3f8=(uchar)((id+14)%256);
      inputs.native_6d3f0=ExtraDouble(id,15);
      inputs.native_6d408=ExtraDouble(id,16);
      inputs.native_1d7138=ExtraDouble(id,17);
      inputs.native_6d410=ExtraDouble(id,18);
      inputs.native_1d7130=ExtraInt(id,19);
      inputs.native_6d418=ExtraDouble(id,20);
      inputs.native_6d420=(uchar)((id+21)%256);
      Bot3ProfileRuntimeState profile_state;ZeroMemory(profile_state);profile_state.random_seed=seed;
      Bot3PreparationState state;ZeroMemory(state);ArrayInitialize(Calls,0);PrintCalls=0;OrderHash=(ulong)0xcbf29ce484222325;ATRFrame=0;ATRPeriod=0;ATRSymbolHash=0;
      Bot3StrategyContextInputs context_inputs;ZeroMemory(context_inputs);
      int control=id/9;uchar keep[]={0,1,255};int magics[]={-2147483648,0,2147483647};
      context_inputs.keep_comment=keep[(id+2*control)%3];context_inputs.base_magic=magics[(id/3+control)%3];
      context_inputs.comment_prefix=id%2!=0 ? "Vàng 🚀" : "";context_inputs.symbol_suffix=id%2!=0 ? ".a" : "";
      context_inputs.native_1d6f28=(uchar)(255*((id+control)%2));
      Bot3StrategyContextState context_state;ZeroMemory(context_state);context_state.order_comment="cũ"+IntegerToString(id);context_state.converted_value=-987.5;
      string currencies[]={"USD","EUR","JPY","CHF","VND"};FXCurrency=currencies[(id/5+index)%5];FXAccountReads=0;FXPriceReads=0;
      CombinedHash=(ulong)0xcbf29ce484222325;FXServiceHash=(ulong)0xcbf29ce484222325;FXPriceHash=(ulong)0xcbf29ce484222325;
      Bot3SetupStrategy((uint)index,adjustments,inputs,context_inputs,profile_state,context_state,state);
      inputs.virtual_expiration=(uchar)((id+17)%256);
      Bot3NfpExecution execution;Bot3PendingRestoreSettings restore;Bot3EntryLoopSettings loop;Bot3LevelCacheSettings levels;
      ZeroMemory(execution);ZeroMemory(restore);ZeroMemory(loop);ZeroMemory(levels);
      Bot3ProjectPreparationToEvaluation(inputs,state,context_state,context_inputs.base_magic,execution,restore,loop,levels);
      Bot3SpreadSettings cfg_spread;Bot3VolumeSettings cfg_volume;Bot3VolumeState state_volume;Bot3EvaluationPrefixSettings cfg_prefix;
      ZeroMemory(cfg_spread);ZeroMemory(cfg_volume);ZeroMemory(state_volume);ZeroMemory(cfg_prefix);
      Bot3ProjectEvaluationControls(profile_state,context_state,state,cfg_spread,cfg_volume,state_volume,cfg_prefix);
      FileWriteInteger(bridge_output,id);
      FileWriteLong(bridge_output,(long)execution.strategy_magic);
      FileWriteLong(bridge_output,(long)execution.magic_base);
      FileWriteLong(bridge_output,(long)ValueBits(execution.tick.bid));
      FileWriteLong(bridge_output,(long)ValueBits(execution.tick.ask));
      FileWriteLong(bridge_output,(long)ValueBits(execution.threshold_a));
      FileWriteLong(bridge_output,(long)ValueBits(execution.gap));
      FileWriteLong(bridge_output,(long)ValueBits(restore.sl_distance));
      FileWriteLong(bridge_output,(long)ValueBits(restore.tp_distance));
      FileWriteLong(bridge_output,(long)restore.expiration_base);
      FileWriteLong(bridge_output,(long)restore.virtual_expiration);
      FileWriteLong(bridge_output,(long)loop.submission.check_free_margin);
      FileWriteLong(bridge_output,(long)loop.submission.omit_real_sl_tp);
      FileWriteLong(bridge_output,(long)loop.confirmation_frame);
      FileWriteLong(bridge_output,(long)loop.older_width);
      FileWriteLong(bridge_output,(long)loop.recent_width);
      FileWriteLong(bridge_output,(long)loop.last_shift);
      FileWriteLong(bridge_output,(long)loop.expiration_setting);
      FileWriteLong(bridge_output,(long)loop.expiration_seconds);
      FileWriteLong(bridge_output,(long)ValueBits(loop.gap_points));
      FileWriteLong(bridge_output,(long)ValueBits(loop.buy_offset));
      FileWriteLong(bridge_output,(long)ValueBits(loop.sell_offset));
      FileWriteLong(bridge_output,(long)ValueBits(loop.radius));
      FileWriteLong(bridge_output,(long)ValueBits(loop.step_reference));
      FileWriteLong(bridge_output,(long)levels.timeframe);
      FileWriteLong(bridge_output,(long)levels.aux_timeframe);
      FileWriteLong(bridge_output,(long)levels.aux_older);
      FileWriteLong(bridge_output,(long)levels.aux_recent);
      FileWriteLong(bridge_output,(long)levels.last_shift);
      FileWriteLong(bridge_output,(long)ValueBits(levels.aux_offset));
      FileWriteLong(bridge_output,(long)loop.delete_expired);
      FileWriteLong(bridge_output,(long)cfg_spread.enabled);
      FileWriteLong(bridge_output,(long)ValueBits(cfg_spread.maximum));
      FileWriteLong(bridge_output,(long)cfg_spread.distance_points);
      FileWriteLong(bridge_output,(long)ValueBits(cfg_volume.start_lots));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_volume.max_lots));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_volume.lot_scale));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_volume.manual_risk));
      FileWriteLong(bridge_output,(long)state_volume.mode);
      FileWriteLong(bridge_output,(long)state_volume.balance_step);
      FileWriteLong(bridge_output,(long)ValueBits(state_volume.strategy_loss));
      FileWriteLong(bridge_output,(long)cfg_prefix.management_timeframe);
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.anchor_limit));
      FileWriteLong(bridge_output,(long)cfg_prefix.management.use_anchor);
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.timed_activation));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.timed_distance));
      FileWriteLong(bridge_output,(long)cfg_prefix.management.virtual_delay_seconds);
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.trail));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.trail_step));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.trail_start));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.trail_limit));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.take_trail_distance));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.take_trail_start));
      FileWriteLong(bridge_output,(long)cfg_prefix.management.slippage_enabled);
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.slippage_trail));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.slippage_start));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.slippage_limit));
      FileWriteLong(bridge_output,(long)cfg_prefix.management.high_low_gap_count);
      FileWriteLong(bridge_output,(long)cfg_prefix.management.finish.high_low_enabled);
      FileWriteLong(bridge_output,(long)cfg_prefix.management.finish.high_low_before_open);
      FileWriteLong(bridge_output,(long)cfg_prefix.management.finish.high_low_shift);
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.finish.lock_start));
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.finish.lock_extra));
      FileWriteLong(bridge_output,(long)cfg_prefix.management.finish.mode);
      FileWriteLong(bridge_output,(long)cfg_prefix.management.finish.step_enabled);
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.finish.step_reference));
      FileWriteLong(bridge_output,(long)cfg_prefix.management.finish.min_steps);
      FileWriteLong(bridge_output,(long)ValueBits(cfg_prefix.management.finish.step_distance));
      FileWriteLong(bridge_output,(long)TextHash(execution.symbol));
      FileWriteLong(bridge_output,(long)TextHash(restore.comment));
FileWriteInteger(output,id);FileWriteInteger(output,1);
      FileWriteLong(output,(long)profile_state.random_seed);
      FileWriteLong(output,(long)profile_state.native_6d324);
      FileWriteLong(output,(long)profile_state.native_6d3c0);
      FileWriteLong(output,(long)inputs.entry.confirmation_frame);
      FileWriteLong(output,(long)inputs.entry.entry_frame);
      FileWriteLong(output,(long)inputs.entry.older_width);
      FileWriteLong(output,(long)inputs.entry.recent_width);
      FileWriteLong(output,(long)inputs.entry.last_shift);
      FileWriteLong(output,(long)ValueBits(inputs.entry.gap_points));
      FileWriteLong(output,(long)ValueBits(inputs.buy_offset));
      FileWriteLong(output,(long)ValueBits(inputs.sell_offset));
      FileWriteLong(output,(long)ValueBits(inputs.nearby_radius));
      FileWriteLong(output,(long)inputs.expiration_hours);
      FileWriteLong(output,(long)ValueBits(inputs.stop_distance));
      FileWriteLong(output,(long)ValueBits(inputs.target_distance));
      FileWriteLong(output,(long)ValueBits(inputs.trail_distance));
      FileWriteLong(output,(long)ValueBits(inputs.trail_start));
      FileWriteLong(output,(long)ValueBits(inputs.trail_limit));
      FileWriteLong(output,(long)ValueBits(inputs.trail_step));
      FileWriteLong(output,(long)ValueBits(inputs.native_6d368));
      FileWriteLong(output,(long)ValueBits(inputs.native_6d370));
      FileWriteLong(output,(long)ValueBits(inputs.trigger_distance));
      FileWriteLong(output,(long)ValueBits(inputs.locked_distance));
      FileWriteLong(output,(long)inputs.aux_hour1);
      FileWriteLong(output,(long)inputs.aux_scan50);
      FileWriteLong(output,(long)inputs.aux_older);
      FileWriteLong(output,(long)inputs.aux_recent);
      FileWriteLong(output,(long)ValueBits(inputs.aux_offset));
      FileWriteLong(output,(long)inputs.indicator_period);
      FileWriteLong(output,(long)inputs.indicator_timeframe);
      FileWriteLong(output,(long)inputs.native_6d2e0);
      FileWriteLong(output,(long)inputs.management_timeframe);
      FileWriteLong(output,(long)inputs.native_6d2e4);
      FileWriteLong(output,(long)ValueBits(state.scale));
      FileWriteLong(output,(long)ValueBits(state.lot_scale));
      FileWriteLong(output,(long)ValueBits(state.unit));
      FileWriteLong(output,(long)ValueBits(state.spread));
      FileWriteLong(output,(long)ValueBits(state.max_spread));
      FileWriteLong(output,(long)state.feature_flag);
      FileWriteLong(output,(long)state.freeze_buffer);
      FileWriteLong(output,(long)state.entry_frame);
      FileWriteLong(output,(long)state.older_width);
      FileWriteLong(output,(long)state.recent_width);
      FileWriteLong(output,(long)state.last_shift);
      FileWriteLong(output,(long)ValueBits(state.gap_points));
      FileWriteLong(output,(long)ValueBits(state.buy_offset));
      FileWriteLong(output,(long)ValueBits(state.sell_offset));
      FileWriteLong(output,(long)ValueBits(state.nearby_radius));
      FileWriteLong(output,(long)ValueBits(state.stop_distance));
      FileWriteLong(output,(long)ValueBits(state.target_distance));
      FileWriteLong(output,(long)ValueBits(state.trail_distance));
      FileWriteLong(output,(long)ValueBits(state.trail_start));
      FileWriteLong(output,(long)ValueBits(state.trail_limit));
      FileWriteLong(output,(long)ValueBits(state.trail_step));
      FileWriteLong(output,(long)ValueBits(state.trigger_distance));
      FileWriteLong(output,(long)ValueBits(state.locked_distance));
      FileWriteLong(output,(long)ValueBits(state.native_6d378));
      FileWriteLong(output,(long)ValueBits(state.native_6d380));
      FileWriteLong(output,(long)state.aux_frame);
      FileWriteLong(output,(long)state.aux_scan);
      FileWriteLong(output,(long)state.aux_older);
      FileWriteLong(output,(long)state.aux_recent);
      FileWriteLong(output,(long)ValueBits(state.aux_offset));
      FileWriteLong(output,(long)ValueBits(state.min_change));
      FileWriteLong(output,(long)ValueBits(state.stop_min_price));
      FileWriteLong(output,(long)ValueBits(state.freeze_min_price));
      FileWriteLong(output,(long)state.expiration_seconds);
      FileWriteLong(output,(long)state.expiration);
      FileWriteLong(output,(long)ValueBits(state.native_6d4e0));
      FileWriteLong(output,(long)state.native_6d4e8);
      FileWriteLong(output,(long)ValueBits(state.native_6d4f0));
      FileWriteLong(output,(long)ValueBits(state.native_6d4f8));
      FileWriteLong(output,(long)ValueBits(state.native_6d500));
      FileWriteLong(output,(long)state.native_6d508);
      FileWriteLong(output,(long)state.native_6d50c);
      FileWriteLong(output,(long)state.native_6d510);
      FileWriteLong(output,(long)state.mode);
      FileWriteLong(output,(long)state.native_6d518);
      FileWriteLong(output,(long)state.native_6d51c);
      FileWriteLong(output,(long)state.native_6d520);
      FileWriteLong(output,(long)state.native_6d550);
      FileWriteLong(output,(long)state.management_timeframe);
      FileWriteLong(output,(long)state.native_6d608);
      FileWriteLong(output,(long)ValueBits(state.native_6d600));
      FileWriteLong(output,(long)ValueBits(state.native_6d618));
      FileWriteLong(output,(long)ValueBits(state.native_6d620));
      FileWriteLong(output,(long)ValueBits(state.native_6d628));
      FileWriteLong(output,(long)state.native_6d630);
      FileWriteLong(output,(long)ValueBits(state.native_6d638));
      FileWriteLong(output,(long)state.native_6d640);
      FileWriteLong(output,(long)state.native_6d5c8);
      FileWriteLong(output,(long)ValueBits(state.native_6d5f0));
      FileWriteLong(output,(long)state.native_6d5dc);
      FileWriteLong(output,(long)ValueBits(state.native_6d5e8));
      FileWriteLong(output,(long)state.native_6d5f8);
      FileWriteLong(output,(long)state.expiration_hours);
      FileWriteLong(output,(long)ValueBits(state.point));
      FileWriteLong(output,(long)state.strategy_index);
      FileWriteLong(output,(long)state.indicator_handle);
      FileWriteLong(output,ArraySize(state.indicator_values));FileWriteLong(output,(long)ArrayGetAsSeries(state.indicator_values));FileWriteLong(output,(long)TextHash(state.comment));
      for(int j=0;j<7;j++) FileWriteLong(output,Calls[j]);
      FileWriteLong(output,(long)state.tick.time);FileWriteLong(output,(long)ValueBits(state.tick.bid));FileWriteLong(output,(long)ValueBits(state.tick.ask));
      FileWriteLong(output,state.calendar.year);
      FileWriteLong(output,state.calendar.mon);
      FileWriteLong(output,state.calendar.day);
      FileWriteLong(output,state.calendar.hour);
      FileWriteLong(output,state.calendar.min);
      FileWriteLong(output,state.calendar.sec);
      FileWriteLong(output,state.calendar.day_of_week);
      FileWriteLong(output,state.calendar.day_of_year);
      FileWriteLong(output,(long)OrderHash);FileWriteLong(output,ATRFrame);FileWriteLong(output,ATRPeriod);FileWriteLong(output,(long)ATRSymbolHash);
      FileWriteLong(output,(long)context_state.magic);FileWriteLong(output,(long)ValueBits(context_state.converted_value));FileWriteLong(output,(long)ValueBits(inputs.reference));
      FileWriteLong(output,FXAccountReads);FileWriteLong(output,FXPriceReads);FileWriteLong(output,(long)FXPriceHash);FileWriteLong(output,(long)FXServiceHash);FileWriteLong(output,(long)CombinedHash);
      int comment_length=StringLen(context_state.order_comment);FileWriteInteger(output,comment_length);if(comment_length>0) FileWriteString(output,context_state.order_comment,comment_length);
   }
   if(FileTell(source)!=FileSize(source)) Fault=10;FileClose(source);FileClose(output);FileClose(bridge_output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);return Fault;
}
