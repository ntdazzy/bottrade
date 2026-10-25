// Supplied point replies; only two bounded virtual calculation blocks are called.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh"
#include "../../Include/bot-cua-toi-3/Bot3VirtualStops.mqh"
double FPoint(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property);
#define SymbolInfoDouble FPoint
#include "../../Include/bot-cua-toi-3/Bot3ManagementVirtualFinish.mqh"
#undef SymbolInfoDouble
input string CheckRun="";
union FinishBits { double d;ulong u; };
Bot3VirtualFinishSettings FCfg;
MqlTick FTick;
double FCurrent=0,FUnit=0,FGap=0,FFreeze=0,FLevels[9],FPointReply=0;
uint FIndex=0;
int FScenario=0,FPointCount=0,FFault=0,FCalls=0;
ulong FHash=0;
ulong FBits(const double value) { FinishBits b;b.d=value;return b.u; }
void FWord(ulong &hash,const ulong word)
{
   for(int i=0;i<8;i++) { hash^=(word>>(8*i))&255;hash*=(ulong)0x100000001b3; }
}
double FPoint(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(symbol!="CHECK" || property!=SYMBOL_POINT) FFault=1;
   FWord(FHash,4);FWord(FHash,(ulong)property);FWord(FHash,FBits(FPointReply));FWord(FHash,0);FWord(FHash,0);
   FCalls++;FPointCount++;
   if(FScenario==3 || FScenario==FPointCount)
   {
      FCurrent+=.125;FTick.bid+=.25;FTick.ask+=.5;FGap+=.125;FFreeze+=.25;FCfg.lock_extra+=.25;
      FUnit*=2.0;FIndex=(FIndex+1)%9;FLevels[FIndex]+=1.5;
   }
   return FPointReply;
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot3-management-virtual-finish\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d564633 || version!=1 || count<1 || count>100000) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(source),buy=FileReadInteger(source),stage=FileReadInteger(source);FScenario=FileReadInteger(source);
      bool changed=FileReadInteger(source)!=0;FIndex=(uint)FileReadInteger(source);
      ZeroMemory(FCfg);FCfg.high_low_enabled=FileReadInteger(source);FCfg.high_low_before_open=(uchar)FileReadInteger(source);
      FCfg.high_low_shift=(uchar)FileReadInteger(source);FCfg.mode=FileReadInteger(source);FCfg.step_enabled=(uchar)FileReadInteger(source);
      FCfg.min_steps=FileReadInteger(source);int counter=FileReadInteger(source);
      Bot3ManagedPosition position;ZeroMemory(position);position.open_price=FileReadDouble(source);position.tp=FileReadDouble(source);
      FCurrent=FileReadDouble(source);FUnit=FileReadDouble(source);FGap=FileReadDouble(source);FFreeze=FileReadDouble(source);
      FCfg.lock_start=FileReadDouble(source);FCfg.lock_extra=FileReadDouble(source);FCfg.step_reference=FileReadDouble(source);FCfg.step_distance=FileReadDouble(source);
      double anchor=FileReadDouble(source),copied=FileReadDouble(source);FPointReply=FileReadDouble(source);
      ZeroMemory(FTick);FTick.bid=FileReadDouble(source);FTick.ask=FileReadDouble(source);
      for(int k=0;k<9;k++) FLevels[k]=FileReadDouble(source);
      if(id!=i || (buy!=0 && buy!=1) || stage<0 || stage>1 || FIndex>=9) { FFault=9;break; }
      FCfg.high_low_buy_shift=10.0;FCfg.high_low_sell_shift=10.0;
      FPointCount=0;FCalls=0;FHash=(ulong)0xcbf29ce484222325;
      if(stage==0) Bot3AdvanceVirtualHighLow(buy!=0,"CHECK",FCfg,FUnit,FGap,FFreeze,position,FTick,FLevels,FIndex,FCurrent,changed);
      else Bot3AdvanceVirtualBreakEvenCounter(buy!=0,"CHECK",FCfg,FUnit,FGap,FFreeze,anchor,copied,position,FTick,FCurrent,changed,counter);
      bool hit=buy!=0 ? FCurrent>=FTick.bid : FTick.ask>=FCurrent;
      ulong levels_hash=(ulong)0xcbf29ce484222325;
      for(int k=0;k<9;k++) FWord(levels_hash,FBits(FLevels[k]));
      FileWriteInteger(output,id);FileWriteInteger(output,stage);FileWriteInteger(output,(int)changed);FileWriteInteger(output,counter);
      FileWriteInteger(output,(int)FIndex);FileWriteInteger(output,(int)hit);
      FileWriteDouble(output,FCurrent);FileWriteDouble(output,FTick.bid);FileWriteDouble(output,FTick.ask);
      FileWriteDouble(output,FUnit);FileWriteDouble(output,FGap);FileWriteDouble(output,FFreeze);FileWriteDouble(output,FCfg.lock_extra);
      FileWriteLong(output,(long)levels_hash);FileWriteInteger(output,FCalls);FileWriteLong(output,(long)FHash);
   }
   if(FFault==0 && FileTell(source)!=FileSize(source)) FFault=10;
   FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,FFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot3ManagementVirtualFinishCheck:",FFault,",",count);return FFault;
}
