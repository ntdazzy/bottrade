#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1EntryProfiles.mqh"
input string CheckRun="";
input int OnlyCase=-1;
input int ForceShortArray=-1;
union Bits { double d;ulong u; };
ulong ValueBits(const double value) { Bits b;b.d=value;return b.u; }
double Sample,CheckPoint,Bid,Ask;long Now,Stops,Freeze;int CheckDigits,Fault;
ulong OrderHash;int Calls[6];int PrepMode=-1,DigitReads=0,PointReads=0,PrintCalls=0;
void Event(const int k) { if(k<=6) Calls[k-1]++;else PrintCalls++;for(int i=0;i<8;i++) { OrderHash^=((ulong)k>>(i*8))&255;OrderHash*=(ulong)0x100000001b3; } }
int FakeATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period) { Event(1);if(symbol!="XAUUSD" || frame!=(PrepMode==7 ? PERIOD_CURRENT : PERIOD_D1) || period!=30) Fault=21;return PrepMode==0 ? -17 : 17; }
int FakeCopy(const int handle,const int buffer,const int start,const int count,double &target[]) { Event(2);if(handle!=17 || buffer!=0 || start!=0 || count!=100) Fault=22;if(PrepMode==1) return 0;int n=ForceShortArray>=0 ? ForceShortArray : PrepMode==3 ? 3 : PrepMode==4 ? 4 : 2;ArrayResize(target,n);for(int j=0;j<n;j++) target[j]=Sample+((PrepMode==2 || PrepMode==3 || PrepMode==4) ? j*.125 : 0.0);return ForceShortArray>=0 || PrepMode==2 ? -1 : n; }
bool FakeTick(const string symbol,MqlTick &tick) { Event(3);if(symbol!="XAUUSD") Fault=23;if(PrepMode==5) return false;tick.time=(datetime)Now;tick.bid=Bid;tick.ask=Ask;return PrepMode!=6; }
datetime FakeTime(MqlDateTime &calendar) { Event(4);ZeroMemory(calendar);return (datetime)Now; }
datetime FakeTime() { Event(4);return (datetime)Now; }
double FakeDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property) { Event(5);if(symbol!="XAUUSD" || property!=SYMBOL_POINT) Fault=25;if(PrepMode==18) { double replies[5]={.01,.002,.001,.03,.04};if(PointReads>=5) { Fault=28;return 0; }return replies[PointReads++]; }return CheckPoint; }
long FakeInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property) { Event(6);if(symbol!="XAUUSD") Fault=26;if(property==SYMBOL_DIGITS) { if(PrepMode==16) { int replies[3]={3,1,8};if(DigitReads>=3) { Fault=29;return 0; }return replies[DigitReads++]; }if(PrepMode==17) { int replies[4]={2,5,1,9};if(DigitReads>=4) { Fault=29;return 0; }return replies[DigitReads++]; }return CheckDigits; }if(property==SYMBOL_TRADE_STOPS_LEVEL) return Stops;if(property==SYMBOL_TRADE_FREEZE_LEVEL) return Freeze;Fault=27;return 0; }
int FakeLastError() { return 5017; }
void FakePrint(const string text) { Event(7); }
void FakePrint(const string text,const int code) { Event(7);if(code!=5017) Fault=30; }
#define Print FakePrint
#define GetLastError FakeLastError
#define iATR FakeATR
#define CopyBuffer FakeCopy
#define SymbolInfoTick FakeTick
#define TimeCurrent FakeTime
#define SymbolInfoDouble FakeDouble
#define SymbolInfoInteger FakeInteger
#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"
#undef Print
#undef GetLastError
#undef iATR
#undef CopyBuffer
#undef SymbolInfoTick
#undef TimeCurrent
#undef SymbolInfoDouble
#undef SymbolInfoInteger
double ExtraDouble(const int id,const int j) { return .5+(double)id*.125+(double)j*.25; }
int ExtraInt(const int id,const int j) { return (id%2==0 ? 1 : -1)*(id+j+1); }
ulong TextHash(const string value) { ulong h=(ulong)0xcbf29ce484222325;for(int i=0;i<StringLen(value);i++) { ushort c=StringGetCharacter(value,i);h^=(ulong)(c&255);h*=(ulong)0x100000001b3;h^=(ulong)(c>>8);h*=(ulong)0x100000001b3; } return h; }
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++) { ushort c=StringGetCharacter(CheckRun,i);if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4; }
   string folder="bot1-preparation\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),bot=FileReadInteger(source),count=FileReadInteger(source);

   if(magic!=0x44535431 || version!=1 || bot!=1 || count<1 || count>10000 || FileSize(source)!=(ulong)16+(ulong)count*236) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,1347571761);FileWriteInteger(output,1);FileWriteInteger(output,OnlyCase<0 ? count : 1);FileWriteInteger(output,87);
   for(int id=0;id<count;id++)
   {
      if(FileReadInteger(source)!=id) { Fault=9;break; }
      PrepMode=id>=1040 ? id-1040 : -1;DigitReads=0;PointReads=0;PrintCalls=0;
      Bot1PreparationInputs inputs;ZeroMemory(inputs);
      inputs.reference=FileReadDouble(source);
      inputs.variable_distances=(uchar)FileReadInteger(source);
      inputs.adjust_lots=(uchar)FileReadInteger(source);
      inputs.max_spread=FileReadDouble(source);
      inputs.feature_flag=(uchar)FileReadInteger(source);
      inputs.freeze_buffer_flag=(uchar)FileReadInteger(source);
      inputs.entry.confirmation_frame=FileReadInteger(source);
      inputs.entry.hour1_flag=(uchar)FileReadInteger(source);
      inputs.entry.older_width=FileReadInteger(source);
      inputs.entry.recent_width=FileReadInteger(source);
      inputs.entry.last_shift=FileReadInteger(source);
      inputs.entry.gap_points=FileReadDouble(source);
      inputs.buy_offset=FileReadDouble(source);
      inputs.sell_offset=FileReadDouble(source);
      inputs.nearby_radius=FileReadDouble(source);
      inputs.expiration_hours=FileReadInteger(source);
      inputs.virtual_expiration=(uchar)FileReadInteger(source);
      inputs.stop_distance=FileReadDouble(source);
      inputs.target_distance=FileReadDouble(source);
      inputs.trail_distance=FileReadDouble(source);
      inputs.trail_start=FileReadDouble(source);
      inputs.trail_limit=FileReadDouble(source);
      inputs.trail_step=FileReadDouble(source);
      inputs.aux_hour1=(uchar)FileReadInteger(source);
      inputs.aux_scan50=(uchar)FileReadInteger(source);
      inputs.aux_older=FileReadInteger(source);
      inputs.aux_recent=FileReadInteger(source);
      inputs.aux_offset=FileReadDouble(source);
      inputs.min_change=FileReadDouble(source);
      Sample=FileReadDouble(source);
      CheckPoint=FileReadDouble(source);
      CheckDigits=FileReadInteger(source);
      Stops=FileReadLong(source);
      Freeze=FileReadLong(source);
      Bid=FileReadDouble(source);
      Ask=FileReadDouble(source);
      Now=FileReadLong(source);
      inputs.native_62218=ExtraDouble(id,0);
      inputs.native_62220=(uchar)((id+1)%256);
      inputs.native_62228=ExtraDouble(id,2);
      inputs.native_62230=ExtraDouble(id,3);
      inputs.native_62238=ExtraDouble(id,4);
      inputs.native_62240=(uchar)((id+5)%256);
      inputs.native_6a5d8=ExtraInt(id,6);
      inputs.omit_real_sl_tp=(uchar)((id+7)%256);
      inputs.virtual_stops=(uchar)((id+8)%256);
      inputs.native_6a608=ExtraInt(id,9);
      inputs.check_free_margin=(uchar)((id+10)%256);
      inputs.native_62268=(uchar)((id+11)%256);
      inputs.native_622a8=(uchar)((id+12)%256);
      inputs.native_622ec=ExtraInt(id,13);
      inputs.native_622f0=(uchar)((id+14)%256);
      inputs.native_62390=ExtraDouble(id,15);
      inputs.native_62398=(uchar)((id+16)%256);
      inputs.native_623a8=ExtraDouble(id,17);
      inputs.native_6a740=ExtraDouble(id,18);
      inputs.native_623b0=ExtraDouble(id,19);
      inputs.native_6a748=ExtraInt(id,20);
      inputs.native_6a750=ExtraDouble(id,21);
      inputs.native_6a768=ExtraInt(id,22);
      inputs.symbol="XAUUSD";inputs.comment="case"+IntegerToString(id);inputs.indicator_period=30;inputs.indicator_day=PrepMode==7 ? 0 : PrepMode==8 ? 255 : 1;
      Bot1PreparationState state;ZeroMemory(state);ArrayInitialize(Calls,0);OrderHash=(ulong)0xcbf29ce484222325;
      if(OnlyCase>=0 && id!=OnlyCase) continue;
      Print("PREPARATION_CASE:",id);FileFlush(output);
      Bot1PrepareStrategy((uint)(id%8),inputs,state);FileWriteInteger(output,id);FileWriteInteger(output,1);
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
      FileWriteLong(output,(long)ValueBits(state.native_623e8));
      FileWriteLong(output,(long)state.native_623f0);
      FileWriteLong(output,(long)ValueBits(state.native_623f8));
      FileWriteLong(output,(long)ValueBits(state.native_62400));
      FileWriteLong(output,(long)ValueBits(state.native_62408));
      FileWriteLong(output,(long)state.native_62410);
      FileWriteLong(output,(long)state.native_62414);
      FileWriteLong(output,(long)state.omit_real_sl_tp);
      FileWriteLong(output,(long)state.mode);
      FileWriteLong(output,(long)state.native_62420);
      FileWriteLong(output,(long)state.check_free_margin);
      FileWriteLong(output,(long)state.native_62428);
      FileWriteLong(output,(long)state.native_62458);
      FileWriteLong(output,(long)state.native_6248c);
      FileWriteLong(output,(long)state.native_62490);
      FileWriteLong(output,(long)ValueBits(state.native_62510));
      FileWriteLong(output,(long)state.native_62518);
      FileWriteLong(output,(long)ValueBits(state.native_62528));
      FileWriteLong(output,(long)ValueBits(state.native_62530));
      FileWriteLong(output,(long)ValueBits(state.native_62538));
      FileWriteLong(output,(long)state.native_62540);
      FileWriteLong(output,(long)ValueBits(state.native_62548));
      FileWriteLong(output,(long)state.native_62550);
      FileWriteLong(output,(long)state.native_624d8);
      FileWriteLong(output,(long)state.native_624ec);
      FileWriteLong(output,(long)ValueBits(state.native_624f8));
      FileWriteLong(output,(long)ValueBits(state.native_62500));
      FileWriteLong(output,(long)state.native_62508);
      FileWriteLong(output,(long)state.expiration_hours);
      FileWriteLong(output,(long)ValueBits(state.point));
      FileWriteLong(output,(long)state.strategy_index);
      FileWriteLong(output,(long)state.indicator_handle);
      FileWriteLong(output,ArraySize(state.indicator_values));FileWriteLong(output,(long)ArrayGetAsSeries(state.indicator_values));FileWriteLong(output,(long)TextHash(state.comment));
      for(int j=0;j<6;j++) FileWriteLong(output,Calls[j]);
      FileWriteLong(output,(long)state.tick.time);FileWriteLong(output,(long)ValueBits(state.tick.bid));FileWriteLong(output,(long)ValueBits(state.tick.ask));
      FileWriteLong(output,state.calendar.year);
      FileWriteLong(output,state.calendar.mon);
      FileWriteLong(output,state.calendar.day);
      FileWriteLong(output,state.calendar.hour);
      FileWriteLong(output,state.calendar.min);
      FileWriteLong(output,state.calendar.sec);
      FileWriteLong(output,state.calendar.day_of_week);
      FileWriteLong(output,state.calendar.day_of_year);
      FileWriteLong(output,(long)OrderHash);FileWriteLong(output,PrintCalls);
   }
   if(FileTell(source)!=FileSize(source)) Fault=10;FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;FileWriteInteger(status,Fault);FileWriteInteger(status,OnlyCase<0 ? count : 1);FileClose(status);return Fault;
}
