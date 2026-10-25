#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1PositionModify.mqh"
#include "../../Include/bot-cua-toi-1/Bot1PositionClose.mqh"
#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"
input string CheckRun="";
union VirtualStartBits { double d;ulong u; };
int VCalls=0,VFault=0,VDigitsIndex=0,VDigits[2],VDelay=0,VModify=0,VScenario=0,VTickOk=0;
double VLevel=0.0,VPoint=0.0,VBid=0.0,VAsk=0.0,VCurrent=0.0,VMinimum=0.0;
long VNow=0;
MqlTick VTickData;
ulong VExpectedDeviation=(ulong)0x0123456789abcdef;
double VThresholdA=1.25,VThresholdB=2.5;
ulong VHash=0;
ulong VBits(const double value) { VirtualStartBits b;b.d=value;return b.u; }
ulong VText(const string value)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      ushort c=StringGetCharacter(value,i);h^=(ulong)(c&255);h*=(ulong)0x100000001b3;
      h^=(ulong)(c>>8);h*=(ulong)0x100000001b3;
   }
   return h;
}
void VTrace(const int api,const ulong a=0,const ulong b=0,const ulong v=0,const ulong w=0)
{
   ulong words[5];words[0]=(ulong)api;words[1]=a;words[2]=b;words[3]=v;words[4]=w;
   for(int i=0;i<5;i++) for(int j=0;j<8;j++) { VHash^=(words[i]>>(8*j))&255;VHash*=(ulong)0x100000001b3; }
   VCalls++;
}
void VChanged(const int api)
{
   if((VScenario==1 && api==2) || (VScenario==2 && api==4) || (VScenario==3 && api==5)) VCurrent+=1.25;
   if((VScenario==4 && api==9) || (VScenario==5 && api==4) || (VScenario==6 && api==10))
   {
      VCurrent+=1.25;VTickData.bid+=1.25;VTickData.ask+=1.25;
   }
}
datetime VTime() { VTrace(9,(ulong)VNow);VChanged(9);return (datetime)VNow; }
void VPrint(const string text) { VTrace(10,VText(text));VChanged(10); }
double VGetLevel(Bot1VirtualStopState &table,long &tickets[],const string &symbol,const double &unit,
                  const int side,const double price,const double distance,const long ticket)
{
   if(symbol!="CHECK") VFault=1;
   VTrace(1,(ulong)side,VBits(price),VBits(distance),(ulong)ticket);return VLevel;
}
bool VWait(const Bot1VirtualStopState &table,const int &delay,const long ticket)
{
   VTrace(2,(ulong)ticket,(ulong)VDelay);VChanged(2);return VDelay!=0;
}
void VStamp(Bot1VirtualStopState &table,const long ticket) { VTrace(6,(ulong)ticket); }
bool VModifyPosition(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                      const ulong ticket,const double sl,const double tp)
{
   VTrace(5,ticket,VBits(sl),VBits(tp),(ulong)VModify);VChanged(5);return VModify!=0;
}
void VTryClosePosition(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
                        const ulong &deviation,const double &reference_a,const double &reference_b,
                        const double &threshold_a,const double &threshold_b,const ulong ticket)
{
   if(deviation!=VExpectedDeviation || VBits(reference_a)!=VBits(VTickData.bid) ||
      VBits(reference_b)!=VBits(VTickData.ask) || VBits(threshold_a)!=VBits(VThresholdA) ||
      VBits(threshold_b)!=VBits(VThresholdB)) VFault=14;
   VTrace(8,ticket);
}
long VSymbolDigits(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(symbol!="CHECK" || property!=SYMBOL_DIGITS || VDigitsIndex>=2) { VFault=2;return 0; }
   long value=(long)VDigits[VDigitsIndex++];VTrace(3,(ulong)value);return value;
}
double VSymbolPoint(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(symbol!="CHECK" || (property!=SYMBOL_POINT && property!=SYMBOL_VOLUME_MIN)) VFault=3;
   double value=property==SYMBOL_POINT ? VPoint : VMinimum;
   VTrace(4,(ulong)property,VBits(value));VChanged(4);return value;
}
bool VTick(const string symbol,MqlTick &tick)
{
   VTrace(7,VText(symbol),(ulong)VTickOk,VBits(VBid),VBits(VAsk));
   if(VTickOk!=0) { tick.bid=VBid;tick.ask=VAsk; }return VTickOk!=0;
}
#define Bot1VirtualStopLevel VGetLevel
#define Bot1VirtualStopDelayPassed VWait
#define Bot1VirtualStopStamp VStamp
#define Bot1ModifyPosition VModifyPosition
#define Bot1TryClosePosition VTryClosePosition
#define SymbolInfoInteger VSymbolDigits
#define SymbolInfoDouble VSymbolPoint
#define SymbolInfoTick VTick
#define TimeCurrent VTime
#define Print VPrint
#include "../../Include/bot-cua-toi-1/Bot1ManagementPrelude.mqh"
#undef Bot1VirtualStopLevel
#undef Bot1VirtualStopDelayPassed
#undef Bot1VirtualStopStamp
#undef Bot1ModifyPosition
#undef Bot1TryClosePosition
#undef SymbolInfoInteger
#undef SymbolInfoDouble
#undef SymbolInfoTick
#undef TimeCurrent
#undef Print
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot1-management-virtual-start\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d565331 || version!=1 || count<1 || count>100000) { FileClose(source);return 7; }
   int result=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(result==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(result,magic);FileWriteInteger(result,version);FileWriteInteger(result,count);
   string symbol="CHECK";int delay=99;long tickets[];
   Bot1VirtualStopState table;ZeroMemory(table);
   Bot1PendingRequestState state;ZeroMemory(state);Bot1TradeSendOptions options;ZeroMemory(options);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(source),buy=FileReadInteger(source);VDelay=FileReadInteger(source);
      VModify=FileReadInteger(source);VScenario=FileReadInteger(source);VTickOk=FileReadInteger(source);
      VDigits[0]=FileReadInteger(source);VDigits[1]=FileReadInteger(source);
      int stage=FileReadInteger(source),seconds=FileReadInteger(source);bool changed=FileReadInteger(source)!=0;
      uint strategy_index=(uint)FileReadInteger(source);
      int slippage_enabled=FileReadInteger(source);bool distance_passed=FileReadInteger(source)!=0;
      long ticket=FileReadLong(source);VNow=FileReadLong(source);long opened=FileReadLong(source);
      Bot1ManagedPosition position;ZeroMemory(position);position.ticket_number=(double)ticket;
      position.open_price=FileReadDouble(source);position.sl=FileReadDouble(source);position.tp=FileReadDouble(source);
      VBid=FileReadDouble(source);VAsk=FileReadDouble(source);double unit=FileReadDouble(source),distance=FileReadDouble(source);
      VLevel=FileReadDouble(source);VPoint=FileReadDouble(source);
      double activation=FileReadDouble(source),timed_distance=FileReadDouble(source),freeze_distance=FileReadDouble(source);
      double trail=FileReadDouble(source),trail_step=FileReadDouble(source),trail_start=FileReadDouble(source),trail_limit=FileReadDouble(source);
      double anchor=FileReadDouble(source);position.volume=FileReadDouble(source);double table_volume=FileReadDouble(source);VMinimum=FileReadDouble(source);
      double volumes[8];ArrayInitialize(volumes,777.0);
      if(strategy_index>=8) { VFault=13;break; }volumes[strategy_index]=table_volume;
      if(id!=i || (buy!=0 && buy!=1)) { VFault=9;break; }
      ZeroMemory(VTickData);VTickData.bid=VBid;VTickData.ask=VAsk;position.opened=opened;
      double initial=VLevel;VCurrent=stage==0 ? 666. : VLevel;VCalls=VDigitsIndex=0;VHash=(ulong)0xcbf29ce484222325;
      bool closed=false;
      if(stage==0) closed=Bot1StartVirtualManagement(buy!=0,symbol,unit,distance,delay,position,VTickData,table,tickets,initial,VCurrent,state,options,VExpectedDeviation,VThresholdA,VThresholdB);
      else if(stage==1) Bot1AdvanceTimedVirtualStop(buy!=0,symbol,unit,activation,timed_distance,seconds,freeze_distance,position,VTickData,VCurrent,changed);
      else if(stage==2) closed=Bot1AdvanceDistanceVirtualStop(buy!=0,symbol,unit,trail,trail_step,trail_start,trail_limit,anchor,position,VTickData,volumes,strategy_index,VCurrent,changed,state,options,VExpectedDeviation,VThresholdA,VThresholdB);
      else if(stage==3) Bot1AdvanceSlippageVirtualStop(buy!=0,symbol,unit,slippage_enabled,distance_passed,anchor,trail,trail_start,trail_limit,freeze_distance,position,VTickData,VCurrent,changed);
      else VFault=12;
      FileWriteInteger(result,id);FileWriteInteger(result,(int)closed);FileWriteInteger(result,(int)changed);
      FileWriteDouble(result,initial);FileWriteDouble(result,VCurrent);FileWriteDouble(result,position.sl);FileWriteDouble(result,position.tp);
      FileWriteDouble(result,VTickData.bid);FileWriteDouble(result,VTickData.ask);FileWriteInteger(result,VCalls);FileWriteLong(result,(long)VHash);
   }
   if(FileTell(source)!=FileSize(source)) VFault=10;
   FileClose(source);FileClose(result);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,VFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot1ManagementVirtualStartCheck:",VFault,",",count);return VFault;
}
