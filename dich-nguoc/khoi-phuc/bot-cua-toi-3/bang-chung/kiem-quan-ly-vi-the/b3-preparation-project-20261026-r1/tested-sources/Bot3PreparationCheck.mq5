// Preparation check: Bot3PrepareStrategy on the distance-settings cases with supplied indicator, tick,
// time and symbol replies; no orders and no market data.
#property strict
#property script_show_inputs
// Included first for Bot3DistanceInputs and Bot3DistanceContext; it calls no terminal service. Its
// Bot3EntryProfiles.mqh guard stops the preparation header from including that file again.
#include "../../Include/bot-cua-toi-3/Bot3DistanceSettings.mqh"
input string CheckRun="";
// -1 runs every case; 0..count-1 runs that case only, though every case is still read and checked.
input int OnlyCase=-1;
union DoubleBits { double value; ulong bits; };
ulong ValueBits(const double value) { DoubleBits v; v.value=value; return v.bits; }
// Market values of the current case; the supplied services answer from it.
Bot3DistanceContext PrepContext;
// Service calls of the current case, in the output order.
int PrepATRCalls=0,PrepCopyCalls=0,PrepOpenCalls=0,PrepTickCalls=0,PrepTimeCalls=0;
int PrepDoubleCalls=0,PrepIntegerCalls=0;
// First fault of the current case and of the run. Service codes: 2x iATR, 3x CopyBuffer, 4x iOpen,
// 5x SymbolInfoTick, 7x SymbolInfoDouble, 8x SymbolInfoInteger; the last digit is the argument position.
int PrepCaseFault=0,PrepFault=0;
void PrepFail(const int code) { if(PrepCaseFault==0) PrepCaseFault=code; }
void PrepRunFail(const int code) { if(PrepFault==0) PrepFault=code; }
// Supplied services: each counts its call, keeps the first argument fault and still answers the
// supplied value, so the case is written. None reads the state under test.
int FakeiATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period)
{
   PrepATRCalls++;
   if(symbol!="XAUUSD") PrepFail(21);
   if((int)frame!=15) PrepFail(22);
   if(period!=30) PrepFail(23);
   return 17;
}
// Two cells of the case sample; the series flag is left to the header.
int FakeCopyBuffer(const int handle,const int buffer,const int start,const int count,double &target[])
{
   PrepCopyCalls++;
   if(handle!=17) PrepFail(31);
   if(buffer!=0) PrepFail(32);
   if(start!=0) PrepFail(33);
   if(count!=100) PrepFail(34);
   ArrayResize(target,2);
   target[0]=PrepContext.sample;target[1]=PrepContext.sample;
   return 2;
}
double FakeiOpen(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   PrepOpenCalls++;
   if(symbol!="XAUUSD") PrepFail(41);
   if(frame!=PERIOD_D1) PrepFail(42);
   if(shift!=1) PrepFail(43);
   return PrepContext.sample;
}
// Time, bid and ask only; the other tick fields keep the zeroed state values.
bool FakeSymbolInfoTick(const string symbol,MqlTick &tick)
{
   PrepTickCalls++;
   if(symbol!="XAUUSD") PrepFail(51);
   tick.time=(datetime)PrepContext.now;tick.bid=PrepContext.bid;tick.ask=PrepContext.ask;
   return true;
}
// Both forms share one counter and answer the case time.
datetime FakeTimeCurrent(MqlDateTime &calendar)
{
   PrepTimeCalls++;
   ZeroMemory(calendar);
   return (datetime)PrepContext.now;
}
datetime FakeTimeCurrent()
{
   PrepTimeCalls++;
   return (datetime)PrepContext.now;
}
double FakeSymbolInfoDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   PrepDoubleCalls++;
   if(symbol!="XAUUSD") PrepFail(71);
   if(property!=SYMBOL_POINT) PrepFail(72);
   return PrepContext.point;
}
// Full long values; any other property is a fault and answers 0.
long FakeSymbolInfoInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   PrepIntegerCalls++;
   if(symbol!="XAUUSD") PrepFail(81);
   if(property==SYMBOL_DIGITS) return (long)PrepContext.digits;
   if(property==SYMBOL_TRADE_STOPS_LEVEL) return PrepContext.stops_level;
   if(property==SYMBOL_TRADE_FREEZE_LEVEL) return PrepContext.freeze_level;
   PrepFail(82);
   return 0;
}
// The macros reach only Bot3Preparation.mqh; its array functions, Print and GetLastError stay real.
#define iATR FakeiATR
#define CopyBuffer FakeCopyBuffer
#define iOpen FakeiOpen
#define SymbolInfoTick FakeSymbolInfoTick
#define TimeCurrent FakeTimeCurrent
#define SymbolInfoDouble FakeSymbolInfoDouble
#define SymbolInfoInteger FakeSymbolInfoInteger
#include "../../Include/bot-cua-toi-3/Bot3Preparation.mqh"
#undef iATR
#undef CopyBuffer
#undef iOpen
#undef SymbolInfoTick
#undef TimeCurrent
#undef SymbolInfoDouble
#undef SymbolInfoInteger

// Settings the distance cases do not hold; j is the row of the extra-settings table.
double PrepExtraDouble(const int id,const int j) { return 0.5+(double)id*0.125+(double)j*0.25; }
int PrepExtraInt(const int id,const int j) { return (id%2==0 ? 1 : -1)*(id+j+1); }
uchar PrepExtraByte(const int id,const int j) { return (uchar)((id+j)%256); }
// FNV-1a 64 over the UTF-16LE bytes of a text, without a terminating zero.
ulong PrepText(const string value)
{
   ulong hash=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      ushort c=StringGetCharacter(value,i);
      hash^=(ulong)(c&255);hash*=(ulong)0x100000001b3;
      hash^=(ulong)(c>>8);hash*=(ulong)0x100000001b3;
   }
   return hash;
}
// Reads one 268-byte case with the reads of Bot3DistanceSettingsCheck.mq5, in its order; returns the id.
int PrepReadCase(const int h,Bot3DistanceInputs &r)
{
   int id=FileReadInteger(h);
   r.reference=FileReadDouble(h);
   r.use_variable=FileReadInteger(h)!=0;
   r.adjust_lots=FileReadInteger(h)!=0;
   r.max_spread=FileReadDouble(h);
   r.feature_flag=FileReadInteger(h)!=0;
   r.freeze_buffer_flag=FileReadInteger(h)!=0;
   r.entry.confirmation_frame=FileReadInteger(h);
   r.entry.entry_frame=FileReadInteger(h);
   r.entry.older_width=FileReadInteger(h);
   r.entry.recent_width=FileReadInteger(h);
   r.entry.last_shift=FileReadInteger(h);
   r.entry.gap_points=FileReadDouble(h);
   r.buy_offset=FileReadDouble(h);
   r.sell_offset=FileReadDouble(h);
   r.nearby_radius=FileReadDouble(h);
   r.expiration_hours=FileReadInteger(h);
   r.virtual_expiration=FileReadInteger(h)!=0;
   r.stop_distance=FileReadDouble(h);
   r.target_distance=FileReadDouble(h);
   r.trail_distance=FileReadDouble(h);
   r.trail_start=FileReadDouble(h);
   r.trail_limit=FileReadDouble(h);
   r.trail_step=FileReadDouble(h);
   r.native_6d368=FileReadDouble(h);
   r.native_6d370=FileReadDouble(h);
   r.trigger_distance=FileReadDouble(h);
   r.locked_distance=FileReadDouble(h);
   r.aux_hour1=FileReadInteger(h)!=0;
   r.aux_scan50=FileReadInteger(h)!=0;
   r.aux_older=FileReadInteger(h);
   r.aux_recent=FileReadInteger(h);
   r.aux_offset=FileReadDouble(h);
   r.min_change=FileReadDouble(h);
   PrepContext.sample=FileReadDouble(h);
   PrepContext.point=FileReadDouble(h);
   PrepContext.digits=FileReadInteger(h);
   PrepContext.stops_level=FileReadLong(h);
   PrepContext.freeze_level=FileReadLong(h);
   PrepContext.bid=FileReadDouble(h);
   PrepContext.ask=FileReadDouble(h);
   PrepContext.now=FileReadLong(h);
   return id;
}
// Copies the read case and the extra settings in the declaration order of Bot3PreparationInputs.
void PrepFillInputs(const int id,const Bot3DistanceInputs &r,Bot3PreparationInputs &inputs)
{
   inputs.symbol="XAUUSD";
   inputs.comment="case"+IntegerToString(id);
   inputs.indicator_timeframe=15;
   inputs.indicator_period=30;
   inputs.reference=r.reference;
   inputs.variable_distances=(uchar)r.use_variable;
   inputs.adjust_lots=(uchar)r.adjust_lots;
   inputs.entry=r.entry;
   inputs.feature_flag=(uchar)r.feature_flag;
   inputs.max_spread=r.max_spread;
   inputs.freeze_buffer_flag=(uchar)r.freeze_buffer_flag;
   inputs.native_6d250=PrepExtraDouble(id,0);
   inputs.native_6d258=PrepExtraByte(id,1);
   inputs.native_6d260=PrepExtraDouble(id,2);
   inputs.native_6d268=PrepExtraDouble(id,3);
   inputs.native_6d270=PrepExtraDouble(id,4);
   inputs.native_6d278=PrepExtraByte(id,5);
   inputs.native_1d6fa8=PrepExtraInt(id,6);
   inputs.native_1d6fc0=PrepExtraByte(id,7);
   inputs.virtual_expiration=(uchar)r.virtual_expiration;
   inputs.virtual_stops=PrepExtraByte(id,8);
   inputs.native_1d6fe8=PrepExtraInt(id,9);
   inputs.native_1d7178=PrepExtraByte(id,10);
   inputs.native_6d2a3=PrepExtraByte(id,11);
   inputs.buy_offset=r.buy_offset;
   inputs.sell_offset=r.sell_offset;
   inputs.native_6d2e0=PrepExtraInt(id,12);
   inputs.nearby_radius=r.nearby_radius;
   inputs.expiration_hours=r.expiration_hours;
   inputs.management_timeframe=PrepExtraInt(id,13);
   inputs.stop_distance=r.stop_distance;
   inputs.target_distance=r.target_distance;
   inputs.trail_distance=r.trail_distance;
   inputs.trail_start=r.trail_start;
   inputs.native_6d368=r.native_6d368;
   inputs.native_6d370=r.native_6d370;
   inputs.trail_limit=r.trail_limit;
   inputs.trail_step=r.trail_step;
   inputs.trigger_distance=r.trigger_distance;
   inputs.locked_distance=r.locked_distance;
   inputs.aux_hour1=(uchar)r.aux_hour1;
   inputs.aux_scan50=(uchar)r.aux_scan50;
   inputs.aux_older=r.aux_older;
   inputs.aux_recent=r.aux_recent;
   inputs.aux_offset=r.aux_offset;
   inputs.native_6d3f8=PrepExtraByte(id,14);
   inputs.native_6d3f0=PrepExtraDouble(id,15);
   inputs.min_change=r.min_change;
   inputs.native_6d408=PrepExtraDouble(id,16);
   inputs.native_1d7138=PrepExtraDouble(id,17);
   inputs.native_6d410=PrepExtraDouble(id,18);
   inputs.native_1d7130=PrepExtraInt(id,19);
   inputs.native_6d418=PrepExtraDouble(id,20);
   inputs.native_6d420=PrepExtraByte(id,21);
}
// One 616-byte record: id, success and 76 words read straight from the state. Doubles keep their
// bits, int values sign-extend through long, uint and uchar values are kept.
void PrepWriteResult(const int output,const int id,const Bot3PreparationState &state)
{
   // Success is written only after Bot3PrepareStrategy returned.
   FileWriteInteger(output,id);FileWriteInteger(output,1);
   // 35 words in the output order of Bot3DistanceSettingsCheck.mq5.
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
   // 22 words: the state fields of the extra settings, rows j=0..21.
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
   // 12 words: the fixed writes, the kept fields and the indicator, index and comment results.
   FileWriteLong(output,(long)state.native_6d5c8);
   FileWriteLong(output,(long)ValueBits(state.native_6d5f0));
   FileWriteLong(output,(long)state.native_6d5dc);
   FileWriteLong(output,(long)ValueBits(state.native_6d5e8));
   FileWriteLong(output,(long)state.native_6d5f8);
   FileWriteLong(output,(long)state.expiration_hours);
   FileWriteLong(output,(long)ValueBits(state.point));
   FileWriteLong(output,(long)state.strategy_index);
   FileWriteLong(output,(long)state.indicator_handle);
   FileWriteLong(output,(long)ArraySize(state.indicator_values));
   FileWriteLong(output,(long)(int)ArrayGetAsSeries(state.indicator_values));
   FileWriteLong(output,(long)PrepText(state.comment));
   // 7 words: service calls of this case.
   FileWriteLong(output,(long)PrepATRCalls);
   FileWriteLong(output,(long)PrepCopyCalls);
   FileWriteLong(output,(long)PrepOpenCalls);
   FileWriteLong(output,(long)PrepTickCalls);
   FileWriteLong(output,(long)PrepTimeCalls);
   FileWriteLong(output,(long)PrepDoubleCalls);
   FileWriteLong(output,(long)PrepIntegerCalls);
}
// One call on fresh settings and a fresh state, with the counters and the case fault at zero.
void PrepRunCase(const int output,const int id,const Bot3DistanceInputs &r)
{
   Bot3PreparationInputs inputs;
   ZeroMemory(inputs);
   PrepFillInputs(id,r,inputs);
   Bot3PreparationState state;
   ZeroMemory(state);
   ArrayResize(state.indicator_values,0);
   PrepATRCalls=0;PrepCopyCalls=0;PrepOpenCalls=0;PrepTickCalls=0;PrepTimeCalls=0;
   PrepDoubleCalls=0;PrepIntegerCalls=0;PrepCaseFault=0;
   // A runtime error stops the script inside this call, before any word of this case is written.
   Bot3PrepareStrategy((uint)(id%9),inputs,state);
   if(PrepCaseFault!=0) PrepRunFail(PrepCaseFault);
   PrepWriteResult(output,id,state);
}

int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot3-preparation\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source);
   int bot=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x44535431 || version!=1 || bot!=3 || count<1 || count>10000 ||
      FileSize(source)!=(ulong)16+(ulong)count*268) { FileClose(source);return 7; }
   // OnlyCase is checked against the count of the file, before any output exists.
   if(OnlyCase<-1 || OnlyCase>=count) { FileClose(source);return 12; }
   int selected_count=OnlyCase<0 ? count : 1;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,0x50525033);FileWriteInteger(output,1);
   FileWriteInteger(output,selected_count);FileWriteInteger(output,76);
   for(int i=0;i<count;i++)
   {
      // The whole case is read before the id check; a wrong id stops the run before its call.
      Bot3DistanceInputs r;
      if(PrepReadCase(source,r)!=i) { PrepRunFail(9);break; }
      // Any other case is only read and checked; the loop still reads to the end of the file.
      if(OnlyCase>=0 && i!=OnlyCase) continue;
      // The case number reaches the log and the written words reach the file before the call.
      Print("PREPARATION_CASE:",i);
      FileFlush(output);
      PrepRunCase(output,i,r);
   }
   if(FileTell(source)!=FileSize(source)) PrepRunFail(10);
   FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,PrepFault);FileWriteInteger(status,selected_count);FileClose(status);
   // The macros are undefined above, so this is the terminal Print.
   Print("Bot3PreparationCheck:",PrepFault,",",selected_count);
   return PrepFault;
}
