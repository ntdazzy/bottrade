// Bot1 full parent control-flow check with supplied service and child replies; no orders.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1PositionModify.mqh"
#include "../../Include/bot-cua-toi-1/Bot1PositionClose.mqh"
#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"
input string CheckRun="";
union FlowBits { double d;ulong u; };
struct FlowPosition
{
   ulong ticket;long type,magic,opened;
   double sl,tp,price,volume;string comment,symbol;
};
FlowPosition FPositions[3];
int FCase[20],FLive=0,FSelected=-1,FFault=0,FCalls=0,FTotalCalls=0,FDigitCalls=0;
uint FInitialErrors=0;
ulong FHash=0,FDeviation=(ulong)0x0123456789abcdef;
double FBid=0,FAsk=0,FStopReply=0,FMinimum=0;
void FAfterFirstTotal();
void FAfterDigits();
bool FCloseReferences(const ulong &deviation,const double &bid,const double &ask,const double &gap,const double &freeze);
void FFail(const int value) { if(FFault==0) FFault=value; }
ulong FBits(const double value) { FlowBits bits;bits.d=value;return bits.u; }
ulong FHashWord(ulong hash,const ulong value)
{
   for(int i=0;i<8;i++) { hash^=(value>>(i*8))&255;hash*=(ulong)0x100000001b3; }
   return hash;
}
ulong FText(const string value)
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
void FTrace(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0)
{
   ulong words[5];words[0]=(ulong)api;words[1]=a;words[2]=b;words[3]=c;words[4]=d;
   for(int i=0;i<5;i++) FHash=FHashWord(FHash,words[i]);FCalls++;
}
int FPositionsTotal()
{
   FTrace(17,(ulong)FLive,(ulong)FTotalCalls);FTotalCalls++;
   if(FTotalCalls==1) FAfterFirstTotal();
   return FLive;
}
ulong FPositionTicket(const int index)
{
   FSelected=index;ulong ticket=0;
   if(index>=0 && index<FLive) ticket=FPositions[index].ticket;
   else FSelected=-1;
   FTrace(2,(ulong)(long)index,0,ticket);return ticket;
}
double FPositionDouble(const ENUM_POSITION_PROPERTY_DOUBLE property)
{
   double value=0;
   if(property!=POSITION_SL && property!=POSITION_TP && property!=POSITION_PRICE_OPEN && property!=POSITION_VOLUME) FFail(20);
   if(FSelected>=0 && FSelected<FLive)
   {
      if(property==POSITION_SL) value=FPositions[FSelected].sl;
      else if(property==POSITION_TP) value=FPositions[FSelected].tp;
      else if(property==POSITION_PRICE_OPEN) value=FPositions[FSelected].price;
      else if(property==POSITION_VOLUME) value=FPositions[FSelected].volume;
   }
   FTrace(3,(ulong)property,0,FBits(value));return value;
}
long FPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   long value=0;
   if(property!=POSITION_TIME && property!=POSITION_TYPE && property!=POSITION_MAGIC) FFail(21);
   if(FSelected>=0 && FSelected<FLive)
   {
      if(property==POSITION_TIME) value=FPositions[FSelected].opened;
      else if(property==POSITION_TYPE) value=FPositions[FSelected].type;
      else if(property==POSITION_MAGIC) value=FPositions[FSelected].magic;
   }
   FTrace(4,(ulong)property,0,(ulong)value);return value;
}
string FPositionString(const ENUM_POSITION_PROPERTY_STRING property)
{
   string value=NULL;
   if(property!=POSITION_COMMENT && property!=POSITION_SYMBOL) FFail(22);
   if(FSelected>=0 && FSelected<FLive)
      value=property==POSITION_COMMENT ? FPositions[FSelected].comment : FPositions[FSelected].symbol;
   FTrace(5,(ulong)property,FText(value),(ulong)(value==NULL));return value;
}
long FSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(symbol!="CHECK" || property!=SYMBOL_DIGITS) FFail(23);
   FTrace(1,17,FText(symbol),(ulong)(long)FCase[13],(ulong)(symbol==NULL));
   FDigitCalls++;FAfterDigits();return (long)FCase[13];
}
double FSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(symbol!="CHECK" || (property!=SYMBOL_POINT && property!=SYMBOL_VOLUME_MIN)) FFail(24);
   double value=property==SYMBOL_POINT ? .01 : FMinimum;
   FTrace(18,(ulong)property,FBits(value));return value;
}
bool FSymbolTick(const string symbol,MqlTick &tick)
{
   if(symbol!="CHECK") FFail(25);
   FTrace(6,FText(symbol),(ulong)FCase[9],FBits(FBid),FBits(FAsk));
   if(FCase[9]!=0) { tick.bid=FBid;tick.ask=FAsk; }
   return FCase[9]!=0;
}
datetime FTimeCurrent() { FTrace(19,1061);return (datetime)1061; }
datetime FCandleTime(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   if(symbol!="CHECK" || (shift!=0 && shift!=1)) FFail(26);
   long value=shift==1 ? 900 : 1100;FTrace(10,(ulong)frame,(ulong)(long)shift,(ulong)value,FText(symbol));return (datetime)value;
}
double FCandleClose(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   if(symbol!="CHECK") FFail(27);
   double value=FCase[1]!=0 ? 90. : 110.;FTrace(11,(ulong)frame,(ulong)(long)shift,FBits(value),FText(symbol));return value;
}
double FCandleOpen(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   if(symbol!="CHECK") FFail(28);
   double value=FCase[1]!=0 ? 95. : 105.;FTrace(12,(ulong)frame,(ulong)(long)shift,FBits(value),FText(symbol));return value;
}
void FPrint(const string value) { FTrace(7,FText(value)); }
int FLastError() { return FCase[17]; }
bool FModify(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,const ulong ticket,const double sl,const double tp)
{
   FTrace(8,ticket,FBits(sl),FBits(tp),(ulong)FCase[10]);return FCase[10]!=0;
}
bool FTryClose(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,const ulong &deviation,
               const double &bid,const double &ask,const double &gap,const double &freeze,const ulong ticket)
{
   if(!FCloseReferences(deviation,bid,ask,gap,freeze)) FFail(29);
   FTrace(9,ticket,(ulong)FCase[11]);
   if(FCase[11]!=0 && FCase[2]!=7)
      for(int i=0;i<FLive;i++)
         if(FPositions[i].ticket==ticket)
         {
            for(int j=i;j<FLive-1;j++) FPositions[j]=FPositions[j+1];
            FLive--;FSelected=-1;break;
         }
   return FCase[11]!=0;
}
double FStopLevel(Bot1VirtualStopState &table,long &open_tickets[],const string &symbol,const double &unit,
                   const int side,const double price,const double distance,const long ticket)
{
   if(symbol!="CHECK") FFail(30);
   FTrace(20,(ulong)(long)side,FBits(price),FBits(distance),(ulong)ticket);return FStopReply;
}
bool FDelay(Bot1VirtualStopState &table,const int seconds,const long ticket)
{
   FTrace(22,(ulong)ticket,(ulong)(long)seconds,(ulong)FCase[12]);return FCase[12]!=0;
}
void FStamp(Bot1VirtualStopState &table,const long ticket) { FTrace(23,(ulong)ticket); }

#define PositionsTotal FPositionsTotal
#define PositionGetTicket FPositionTicket
#define PositionGetDouble FPositionDouble
#define PositionGetInteger FPositionInteger
#define PositionGetString FPositionString
#define SymbolInfoInteger FSymbolInteger
#define SymbolInfoDouble FSymbolDouble
#define SymbolInfoTick FSymbolTick
#define TimeCurrent FTimeCurrent
#define iTime FCandleTime
#define iClose FCandleClose
#define iOpen FCandleOpen
#define GetLastError FLastError
#define Print FPrint
#define Bot1ModifyPosition FModify
#define Bot1TryClosePosition FTryClose
#define Bot1VirtualStopLevel FStopLevel
#define Bot1VirtualStopDelayPassed FDelay
#define Bot1VirtualStopStamp FStamp
#include "../../Include/bot-cua-toi-1/Bot1PositionManagement.mqh"
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetDouble
#undef PositionGetInteger
#undef PositionGetString
#undef SymbolInfoInteger
#undef SymbolInfoDouble
#undef SymbolInfoTick
#undef TimeCurrent
#undef iTime
#undef iClose
#undef iOpen
#undef GetLastError
#undef Print
#undef Bot1ModifyPosition
#undef Bot1TryClosePosition
#undef Bot1VirtualStopLevel
#undef Bot1VirtualStopDelayPassed
#undef Bot1VirtualStopStamp

Bot1PositionManagementSettings FCfg;
Bot1PositionManagementState FShared;
Bot1PendingRequestState FRequests;
Bot1TradeSendOptions FOptions;
double FLevels[8];
void FAfterFirstTotal() { FCfg.high_low_eligible=(uchar)FCase[8]; }
void FAfterDigits()
{
   if(FCase[5]>0 && FDigitCalls==FCase[5]) FCfg.finish.mode=FCase[6];
}
bool FCloseReferences(const ulong &deviation,const double &bid,const double &ask,const double &gap,const double &freeze)
{
   return deviation==FDeviation && FBits(bid)==FBits(FShared.tick.bid) && FBits(ask)==FBits(FShared.tick.ask) &&
          FBits(gap)==FBits(FCfg.gap) && FBits(freeze)==FBits(FCfg.freeze);
}
// Bot1 has no take trailing: profile 16 is rejected in FReadCase and profile 21 sets no take fields.
void FSetProfile(const int profile)
{
   if(profile==14 || profile==21) { FCfg.timed_activation=1.;FCfg.timed_distance=2.; }
   if(profile==15 || profile==21 || profile==22)
   { FCfg.trail=2.;FCfg.trail_step=.5;FCfg.trail_start=1.;FCfg.trail_limit=4.; }
   if(profile==17 || profile==21)
   { FCfg.slippage_enabled=1;FCfg.slippage_trail=2.;FCfg.slippage_start=-12.;FCfg.slippage_limit=4.;FCfg.anchor_limit=-1.; }
   if(profile==18 || profile==21) { FCfg.finish.high_low_enabled=1;FCfg.high_low_gap_count=1; }
   if(profile==19 || profile==21) { FCfg.finish.lock_start=2.;FCfg.finish.lock_extra=1.; }
   if(profile==20 || profile==21) { FCfg.finish.step_enabled=1;FCfg.finish.step_distance=1.; }
}
// Bot1 has no take reply, so profile 13 starts like profile 0; the table is seeded with stop rows only.
void FInitialize()
{
   ZeroMemory(FCfg);ZeroMemory(FShared);ZeroMemory(FRequests);ZeroMemory(FOptions);
   ZeroMemory(FPositions);FSelected=-1;FTotalCalls=0;FDigitCalls=0;FCalls=0;FHash=(ulong)0xcbf29ce484222325;
   bool buy=FCase[1]!=0;int profile=FCase[2];FLive=FCase[3];
   FCfg.symbol="CHECK";FCfg.magic=FCase[16];FCfg.enabled=FCase[15];FCfg.unit=1.;
   FCfg.stop_distance=10.;FCfg.take_distance=20.;FCfg.emergency_offset=.5;FCfg.gap=.2;FCfg.freeze=2.5;
   FCfg.finish.mode=FCase[4];FCfg.high_low_eligible=(uchar)FCase[7];
   FCfg.finish.high_low_buy_shift=10.;FCfg.finish.high_low_sell_shift=10.;FCfg.finish.min_steps=2;
   FCfg.timed_delay_seconds=60;FCfg.virtual_delay_seconds=7;FCfg.anchor_limit=1.;
   FShared.strategy_index=(uint)FCase[14];FShared.error_count=FInitialErrors;FShared.counter=FCase[18];
   FShared.current_stop=333.;FShared.copied_step=7.5;
   FShared.last_ticket=123456;FShared.tick.bid=-100.;FShared.tick.ask=-101.;FShared.table.guard=1;
   for(int i=0;i<8;i++) { FShared.volumes[i]=.1+i*.01;FLevels[i]=buy ? 95. : 105.; }
   FBid=buy ? 105. : 95.;FAsk=buy ? 106. : 96.;FStopReply=buy ? 95. : 105.;
   FMinimum=profile==22 ? 0. : .01;
   if(profile==5) FCfg.enabled=0;
   if(profile==7 || profile==8) { FCfg.candle_enabled[0]=1;FCfg.candle_timeframe[0]=15; }
   if(profile==9) { FCfg.emergency_offset=0.;FCfg.stop_distance=.1;FBid=buy ? 95. : 104.;FAsk=buy ? 96. : 105.; }
   if(profile==10) FStopReply=buy ? 106. : 95.;
   if(profile==12) FStopReply=buy ? FBid : FAsk;
   FSetProfile(profile);
   ulong big[3];big[0]=(ulong)9007199254740993;big[1]=(ulong)9223372036854775807;big[2]=(ulong)0xffffffffffffffff;
   for(int i=0;i<FLive;i++)
   {
      FPositions[i].ticket=FCase[19]==0 ? (ulong)(7+i) : big[i];
      FPositions[i].type=buy ? 0 : 1;FPositions[i].magic=(long)FCase[16];FPositions[i].opened=1000;
      FPositions[i].sl=buy ? 90. : 110.;FPositions[i].tp=buy ? 130. : 70.;
      FPositions[i].price=100.;FPositions[i].volume=.1;FPositions[i].comment="note";FPositions[i].symbol="CHECK";
      if(profile==1 && i==0) FPositions[i].ticket=0;
      if(profile==2 && i==0) FPositions[i].type=buy ? 1 : 0;
      if(profile==3 && i==0) FPositions[i].magic=(long)FCase[16]+1;
      if(profile==4 && i==0) FPositions[i].symbol="OTHER";
      if(profile==6) { FPositions[i].sl=0.;FPositions[i].tp=0.; }
      if(profile==11) FPositions[i].sl=buy ? 106. : 95.;
      if(FPositions[i].ticket!=0)
      {
         double key=(double)(long)(double)(long)FPositions[i].ticket;
         FShared.table.rows[i][0]=key;FShared.table.rows[i][1]=FStopReply;
      }
   }
}
bool FReadCase(const int file,const int id)
{
   for(int i=0;i<20;i++) FCase[i]=FileReadInteger(file);
   FInitialErrors=(uint)FileReadInteger(file);
   if(FCase[0]!=id || FCase[1]<0 || FCase[1]>1 || FCase[2]<0 || FCase[2]>22 || FCase[2]==16 ||
      FCase[3]<0 || FCase[3]>3 || FCase[4]<-1 || FCase[4]>3 || FCase[5]<0 || FCase[5]>30 ||
      FCase[6]<-1 || FCase[6]>3 || FCase[7]<0 || FCase[7]>255 || FCase[8]<0 || FCase[8]>255 ||
      FCase[14]<0 || FCase[14]>7 || FCase[19]<0 || FCase[19]>1) return false;
   for(int i=9;i<=12;i++) if(FCase[i]<0 || FCase[i]>1) return false;
   return true;
}
void FWriteCasts(const int file,const int id)
{
   double values[]={0.,333.,444.,-100.,-101.,.01,.2,.5,1.,2.,4.,7.5,10.,20.,90.,91.,93.,95.,96.,98.,99.,100.,101.,103.,104.,105.,106.,107.,109.,110.,120.,130.};
   FileWriteInteger(file,id);FileWriteInteger(file,ArraySize(values));
   for(int i=0;i<ArraySize(values);i++)
   {
      FileWriteLong(file,(long)FBits(values[i]));string value=(string)values[i];FileWriteInteger(file,StringLen(value));
      for(int j=0;j<StringLen(value);j++) FileWriteInteger(file,(int)StringGetCharacter(value,j),SHORT_VALUE);
   }
}
// 112 bytes <7iIIQ4di4Q: cache_hash covers shared.cache 100x2, table_hash only the 500x3 stop rows.
void FWriteResult(const int file,const int id,const bool returned)
{
   ulong cache=(ulong)0xcbf29ce484222325,table=cache,positions=cache;
   for(int i=0;i<100;i++) for(int j=0;j<2;j++) cache=FHashWord(cache,FBits(FShared.cache[i][j]));
   for(int i=0;i<500;i++) for(int j=0;j<3;j++) table=FHashWord(table,FBits(FShared.table.rows[i][j]));
   for(int i=0;i<FLive;i++) positions=FHashWord(positions,FPositions[i].ticket);
   FileWriteInteger(file,id);FileWriteInteger(file,(int)returned);FileWriteInteger(file,FShared.counter);
   FileWriteInteger(file,FCfg.finish.mode);FileWriteInteger(file,FLive);FileWriteInteger(file,(int)FCfg.high_low_eligible);
   FileWriteInteger(file,(int)FShared.table.guard);FileWriteInteger(file,(int)FShared.strategy_index);
   FileWriteInteger(file,(int)FShared.error_count);FileWriteLong(file,(long)FShared.last_ticket);
   FileWriteDouble(file,FShared.current_stop);
   FileWriteDouble(file,FShared.tick.bid);FileWriteDouble(file,FShared.tick.ask);FileWriteDouble(file,FShared.copied_step);
   FileWriteInteger(file,FCalls);FileWriteLong(file,(long)FHash);FileWriteLong(file,(long)cache);
   FileWriteLong(file,(long)table);FileWriteLong(file,(long)positions);
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot1-position-management-flow\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"cast-values.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d504d31 || version!=1 || count<1 || count>10000 || FileSize(source)!=(ulong)12+(ulong)count*84) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   int formats=FileOpen(folder+"cast-values.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE || formats==INVALID_HANDLE) { FileClose(source);if(output!=INVALID_HANDLE) FileClose(output);if(formats!=INVALID_HANDLE) FileClose(formats);return 8; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   FileWriteInteger(formats,magic);FileWriteInteger(formats,version);FileWriteInteger(formats,count);
   for(int id=0;id<count;id++)
   {
      if(!FReadCase(source,id)) { FFail(9);break; }
      FInitialize();FWriteCasts(formats,id);
      bool returned=Bot1ManagePositions(FCase[1]!=0,FCfg,FShared,FLevels,FRequests,FOptions,FDeviation);
      FWriteResult(output,id,returned);
   }
   if(FileTell(source)!=FileSize(source)) FFail(10);
   FileClose(source);FileClose(output);FileClose(formats);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,FFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot1PositionManagementFlowCheck:",FFault,",",count);return FFault;
}
