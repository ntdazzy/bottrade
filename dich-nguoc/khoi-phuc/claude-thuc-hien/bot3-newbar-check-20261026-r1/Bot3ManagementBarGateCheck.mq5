// Bar-gate check: supplied iTime and Bot3ManagePositions around Bot3ManageOnBarChange; no orders.
#property strict
#property script_show_inputs
// Included before the macros for the types; its guard stops the bar-gate header from
// including it again, so the macros never reach the real manager.
#include "../../Include/bot-cua-toi-3/Bot3PositionManagement.mqh"
input string CheckRun="";
union GateDoubleBits { double d;ulong u; };
struct GateInput
{
   int id,index,timeframe,after_first_frame,buy_reply,sell_reply,change_first_bar,change_buy;
   long previous,observed,second,after_first_bar;
};
GateInput GateCase;
Bot3PositionManagementSettings GateCfg;
Bot3PositionManagementState GateShared;
Bot3PendingRequestState GateRequests;
Bot3TradeSendOptions GateOptions;
long GateBars[9];
double GateLevelsBuy[9],GateLevelsSell[9];
int GateFrame=0,GateFault=0,GateEvents=0,GateTimeCalls=0,GateManageCalls=0;
ulong GateHash=0,GateDeviation=0;
void GateFail(const int value) { if(GateFault==0) GateFault=value; }
ulong GateBits(const double value) { GateDoubleBits bits;bits.d=value;return bits.u; }
ulong GateHashWord(ulong hash,const ulong value)
{
   for(int i=0;i<8;i++) { hash^=(value>>(i*8))&255;hash*=(ulong)0x100000001b3; }
   return hash;
}
void GateEvent(const int api,const ulong a,const ulong b,const ulong c,const ulong d)
{
   ulong words[5];words[0]=(ulong)api;words[1]=a;words[2]=b;words[3]=c;words[4]=d;
   for(int i=0;i<5;i++) GateHash=GateHashWord(GateHash,words[i]);
   GateEvents++;
}
// Call 0 answers observed, later calls second. The event is written before call 0 moves
// GateFrame and, with change_first_bar, the bar slot of the case index.
datetime FakeiTime(const string symbol,const ENUM_TIMEFRAMES frame,const int shift)
{
   if(symbol!="CHECK") GateFail(20);
   if(shift!=1) GateFail(21);
   if(GateTimeCalls>=2) GateFail(22);
   const long value=GateTimeCalls==0 ? GateCase.observed : GateCase.second;
   GateEvent(1,(ulong)(long)(int)frame,1,(ulong)GateBars[GateCase.index],(ulong)value);
   if(GateTimeCalls==0)
   {
      GateFrame=GateCase.after_first_frame;
      if(GateCase.change_first_bar==1) GateBars[GateCase.index]=GateCase.after_first_bar;
   }
   GateTimeCalls++;
   return (datetime)value;
}
// Same signature as the real manager. The event reads the arguments, never the globals;
// after a buy event change_buy moves the globals they refer to. A sell call changes nothing.
bool FakeBot3ManagePositions(const bool buy,const Bot3PositionManagementSettings &settings,
                             Bot3PositionManagementState &shared,const double &levels[],
                             Bot3PendingRequestState &requests,Bot3TradeSendOptions &options,
                             const ulong &deviation)
{
   if(deviation!=GateDeviation) GateFail(30);
   if(settings.symbol!="CHECK") GateFail(31);
   if(GateManageCalls>=2) GateFail(32);
   else if(buy!=(GateManageCalls==0)) GateFail(33);
   GateEvent(buy ? 2 : 3,(ulong)(long)shared.counter,(ulong)(long)settings.finish.mode,
             (ulong)shared.strategy_index,GateBits(levels[0]));
   if(buy && GateCase.change_buy==1)
   {
      GateShared.counter++;GateCfg.finish.mode++;
      GateShared.strategy_index=(GateShared.strategy_index+1)%9;
      GateBars[GateCase.index]+=10;
   }
   GateManageCalls++;
   return buy ? GateCase.buy_reply!=0 : GateCase.sell_reply!=0;
}
#define iTime FakeiTime
#define Bot3ManagePositions FakeBot3ManagePositions
#include "../../Include/bot-cua-toi-3/Bot3ManagementBarGate.mqh"
#undef iTime
#undef Bot3ManagePositions

void GateInitialize()
{
   ZeroMemory(GateCfg);ZeroMemory(GateShared);ZeroMemory(GateRequests);ZeroMemory(GateOptions);
   GateCfg.symbol="CHECK";GateCfg.finish.mode=1;
   GateShared.counter=7;GateShared.strategy_index=(uint)((GateCase.index+1)%9);
   for(int i=0;i<9;i++) { GateBars[i]=100+i;GateLevelsBuy[i]=10.0+i;GateLevelsSell[i]=20.0+i; }
   GateBars[GateCase.index]=GateCase.previous;GateFrame=GateCase.timeframe;
   GateDeviation=(ulong)0x0123456789abcdef;GateHash=(ulong)0xcbf29ce484222325;
   GateEvents=0;GateTimeCalls=0;GateManageCalls=0;
}
bool GateFlag(const int value) { return value==0 || value==1; }
// Reads all 64 bytes of the case before any check.
bool GateReadCase(const int file,const int id)
{
   GateCase.id=FileReadInteger(file);GateCase.index=FileReadInteger(file);
   GateCase.timeframe=FileReadInteger(file);GateCase.after_first_frame=FileReadInteger(file);
   GateCase.buy_reply=FileReadInteger(file);GateCase.sell_reply=FileReadInteger(file);
   GateCase.change_first_bar=FileReadInteger(file);GateCase.change_buy=FileReadInteger(file);
   GateCase.previous=FileReadLong(file);GateCase.observed=FileReadLong(file);
   GateCase.second=FileReadLong(file);GateCase.after_first_bar=FileReadLong(file);
   return GateCase.id==id && GateCase.index>=0 && GateCase.index<=8 &&
          GateFlag(GateCase.buy_reply) && GateFlag(GateCase.sell_reply) &&
          GateFlag(GateCase.change_first_bar) && GateFlag(GateCase.change_buy);
}
void GateWriteResult(const int file,const int id,const bool returned)
{
   FileWriteInteger(file,id);FileWriteInteger(file,(int)returned);FileWriteInteger(file,GateFrame);
   FileWriteInteger(file,GateShared.counter);FileWriteInteger(file,GateCfg.finish.mode);
   FileWriteInteger(file,(int)GateShared.strategy_index);FileWriteInteger(file,GateEvents);
   FileWriteLong(file,(long)GateHash);
   for(int i=0;i<9;i++) FileWriteLong(file,GateBars[i]);
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot3-management-bar-gate\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d424733 || version!=1 || count<1 || count>10000 || FileSize(source)!=(ulong)12+(ulong)count*64)
   { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int id=0;id<count;id++)
   {
      if(!GateReadCase(source,id)) { GateFail(9);break; }
      GateInitialize();
      // The slot index is the captured case value, not GateShared.strategy_index.
      bool returned=Bot3ManageOnBarChange(GateCfg.symbol,GateFrame,(uint)GateCase.index,GateBars,
                                          GateCfg,GateShared,GateLevelsBuy,GateLevelsSell,
                                          GateRequests,GateOptions,GateDeviation);
      GateWriteResult(output,id,returned);
   }
   if(FileTell(source)!=FileSize(source)) GateFail(10);
   FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,GateFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot3ManagementBarGateCheck:",GateFault,",",count);return GateFault;
}
