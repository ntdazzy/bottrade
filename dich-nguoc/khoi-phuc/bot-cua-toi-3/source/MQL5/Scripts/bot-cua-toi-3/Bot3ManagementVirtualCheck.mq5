// Supplied terminal answers; the close guard is recorded at its call boundary.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh"
input string CheckRun="";
union VirtualBits { double d;ulong u; };
int VCalls=0,VFault=0,VScenario=0;
double VPoint=0.0,VMinimum=0.0,VCurrent=0.0,VFreeze=0.0;
long VNow=0;
ulong VHash=0,VDeviation=(ulong)0x0123456789abcdef;
double VThresholdA=1.25;
MqlTick VTickData;
ulong VBits(const double value) { VirtualBits b;b.d=value;return b.u; }
ulong VText(const string value)
{
   ulong h=(ulong)0xcbf29ce484222325;
   for(int i=0;i<StringLen(value);i++)
   {
      ushort c=StringGetCharacter(value,i);
      h^=(ulong)(c&255);h*=(ulong)0x100000001b3;
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
   if(VScenario==2 && api==4) VCurrent+=1.25;
   if((VScenario==4 && api==9) || (VScenario==5 && api==4) || (VScenario==6 && api==10))
   {
      VCurrent+=1.25;VTickData.bid+=1.25;VTickData.ask+=1.25;
   }
}
datetime VTime() { VTrace(9,(ulong)VNow);VChanged(9);return (datetime)VNow; }
double VSymbol(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(symbol!="CHECK" || (property!=SYMBOL_POINT && property!=SYMBOL_VOLUME_MIN)) VFault=1;
   double value=property==SYMBOL_POINT ? VPoint : VMinimum;
   VTrace(4,(ulong)property,VBits(value));VChanged(4);return value;
}
void VPrint(const string text) { VTrace(10,VText(text));VChanged(10); }
void VTryClose(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
               const ulong &deviation,const double &reference_a,const double &reference_b,
               const double &threshold_a,const double &threshold_b,const ulong ticket)
{
   if(deviation!=VDeviation || VBits(reference_a)!=VBits(VTickData.bid) ||
      VBits(reference_b)!=VBits(VTickData.ask) || VBits(threshold_a)!=VBits(VThresholdA) ||
      VBits(threshold_b)!=VBits(VFreeze)) VFault=2;
   VTrace(8,ticket);
}
void VDirectClose(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                  const ulong &deviation,const ulong ticket) { VFault=3;VTrace(18,ticket); }
#define TimeCurrent VTime
#define SymbolInfoDouble VSymbol
#define Print VPrint
#define Bot3TryClosePosition VTryClose
#define Bot3ClosePosition VDirectClose
#include "../../Include/bot-cua-toi-3/Bot3ManagementVirtual.mqh"
#undef TimeCurrent
#undef SymbolInfoDouble
#undef Print
#undef Bot3TryClosePosition
#undef Bot3ClosePosition

int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot3-management-virtual\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d565333 || version!=1 || count<1 || count>100000) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(source),buy=FileReadInteger(source);
      FileReadInteger(source);FileReadInteger(source); // shared-case delay/modify replies: stage 0 only
      VScenario=FileReadInteger(source);FileReadInteger(source); // unused tick reply
      FileReadInteger(source);FileReadInteger(source); // unused digit replies
      int stage=FileReadInteger(source),seconds=FileReadInteger(source);
      bool changed=FileReadInteger(source)!=0;uint strategy_index=(uint)FileReadInteger(source);
      int enabled=FileReadInteger(source);bool distance_passed=FileReadInteger(source)!=0;
      long ticket=FileReadLong(source);VNow=FileReadLong(source);long opened=FileReadLong(source);
      Bot3ManagedPosition position;ZeroMemory(position);position.ticket_number=(double)ticket;
      position.open_price=FileReadDouble(source);position.sl=FileReadDouble(source);position.tp=FileReadDouble(source);
      double bid=FileReadDouble(source),ask=FileReadDouble(source),unit=FileReadDouble(source);
      FileReadDouble(source); // stage-0 initial stop distance
      double initial=FileReadDouble(source);VPoint=FileReadDouble(source);
      double activation=FileReadDouble(source),distance=FileReadDouble(source);VFreeze=FileReadDouble(source);
      double trail=FileReadDouble(source),step=FileReadDouble(source),start=FileReadDouble(source),limit=FileReadDouble(source);
      double anchor=FileReadDouble(source);position.volume=FileReadDouble(source);
      double table_volume=FileReadDouble(source);VMinimum=FileReadDouble(source);
      if(id!=i || (buy!=0 && buy!=1) || stage<1 || stage>3 || strategy_index>=9) { VFault=9;break; }
      double volumes[9];ArrayInitialize(volumes,777.0);volumes[strategy_index]=table_volume;
      ZeroMemory(VTickData);VTickData.bid=bid;VTickData.ask=ask;position.opened=opened;
      Bot3PendingRequestState state;ZeroMemory(state);Bot3TradeSendOptions options;ZeroMemory(options);
      VCurrent=initial;VCalls=0;VHash=(ulong)0xcbf29ce484222325;bool closed=false;
      string symbol="CHECK";
      if(stage==1) Bot3AdvanceTimedVirtualStop(buy!=0,symbol,unit,activation,distance,seconds,VFreeze,position,VTickData,VCurrent,changed);
      else if(stage==2)
         closed=Bot3AdvanceDistanceVirtualStop(buy!=0,symbol,unit,trail,step,start,limit,anchor,
                                               position,VTickData,volumes,strategy_index,VCurrent,changed,
                                               state,options,VDeviation,VThresholdA,VFreeze,(ulong)ticket);
      else Bot3AdvanceSlippageVirtualStop(buy!=0,symbol,unit,enabled,distance_passed,anchor,
                                           trail,start,limit,VFreeze,position,VTickData,VCurrent,changed);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)closed);FileWriteInteger(output,(int)changed);
      FileWriteDouble(output,initial);FileWriteDouble(output,VCurrent);FileWriteDouble(output,position.sl);FileWriteDouble(output,position.tp);
      FileWriteDouble(output,VTickData.bid);FileWriteDouble(output,VTickData.ask);FileWriteInteger(output,VCalls);FileWriteLong(output,(long)VHash);
   }
   if(VFault==0 && FileTell(source)!=FileSize(source)) VFault=10;
   FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,VFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot3ManagementVirtualCheck:",VFault,",",count);return VFault;
}
