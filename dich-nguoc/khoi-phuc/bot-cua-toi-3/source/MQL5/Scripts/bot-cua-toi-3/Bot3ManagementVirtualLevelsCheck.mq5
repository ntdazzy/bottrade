// Supplied helper/API replies for two bounded original segments; no live trading.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh"
#include "../../Include/bot-cua-toi-3/Bot3VirtualStops.mqh"
input string CheckRun="";
union LevelsBits { double d;ulong u; };
int LCalls=0,LFault=0,LScenario=0,LDigitCount=0,LDigits[3];
bool LDelay=false,LModify=false,LTickOk=false;
double LCurrent=0,LTake=0,LUnit=0,LStop=0,LDistance=0,LPoint=0,LMinimum=0;
double LStopReply=0,LTakeReply=0,LThresholdA=1.25,LFreeze=2.5;
double LNextBid=0,LNextAsk=0;
uint LIndex=0;
ulong LHash=0,LDeviation=(ulong)0x0123456789abcdef;
MqlTick LTick;
ulong LBits(const double value) { LevelsBits b;b.d=value;return b.u; }
void LTrace(const int api,const ulong a=0,const ulong b=0,const ulong v=0,const ulong w=0)
{
   ulong words[5];words[0]=(ulong)api;words[1]=a;words[2]=b;words[3]=v;words[4]=w;
   for(int i=0;i<5;i++) for(int j=0;j<8;j++) { LHash^=(words[i]>>(8*j))&255;LHash*=(ulong)0x100000001b3; }
   LCalls++;
}
void LChanged(const int api)
{
   if(LScenario%100!=api) return;
   if(LScenario>=100 && LDigitCount!=LScenario/100) return;
   LCurrent+=1.25;LTake+=2.5;LTick.bid+=.125;LTick.ask+=.25;
   LDistance+=.5;LStop+=.5;LUnit*=2.0;LIndex=(LIndex+1)%9;
}
long LSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(symbol!="CHECK" || property!=SYMBOL_DIGITS || LDigitCount>=3) { LFault=1;return 0; }
   int value=LDigits[LDigitCount];LTrace(3,(ulong)property,(ulong)(long)value,(ulong)LDigitCount);
   LDigitCount++;LChanged(3);return (long)value;
}
double LSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(symbol!="CHECK" || (property!=SYMBOL_POINT && property!=SYMBOL_VOLUME_MIN)) LFault=2;
   double value=property==SYMBOL_POINT ? LPoint : LMinimum;
   LTrace(4,(ulong)property,LBits(value));LChanged(4);return value;
}
bool LSymbolTick(const string symbol,MqlTick &tick)
{
   if(symbol!="CHECK") LFault=3;
   LTrace(7,(ulong)LTickOk);tick.bid=LNextBid;tick.ask=LNextAsk;LChanged(7);return LTickOk;
}
double LStopLevel(Bot3VirtualStopState &table,long &open_tickets[],const string &symbol,
                  const double &unit,const int side,const double price,const double distance,const long ticket)
{
   if(symbol!="CHECK" || LBits(unit)!=LBits(LUnit)) LFault=4;
   LTrace(1,(ulong)side,(ulong)ticket,LBits(price),LBits(distance));LChanged(1);return LStopReply;
}
double LTakeLevel(Bot3VirtualStopState &table,long &open_tickets[],const double level,const long ticket)
{
   LTrace(11,(ulong)ticket,LBits(level),LBits(LCurrent));LChanged(11);return LTakeReply;
}
bool LDelayPassed(const Bot3VirtualStopState &table,const int &seconds,const long ticket)
{
   LTrace(2,(ulong)ticket,(ulong)(long)seconds,(ulong)LDelay);LChanged(2);return LDelay;
}
bool LModifyPosition(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                     const ulong ticket,const double sl,const double tp)
{
   LTrace(5,ticket,LBits(sl),LBits(tp),(ulong)LModify);LChanged(5);return LModify;
}
void LStamp(Bot3VirtualStopState &table,const long ticket) { LTrace(6,(ulong)ticket);LChanged(6); }
void LTryClose(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                const ulong &deviation,const double &reference_a,const double &reference_b,
                const double &threshold_a,const double &threshold_b,const ulong ticket)
{
   if(deviation!=LDeviation || LBits(reference_a)!=LBits(LTick.bid) || LBits(reference_b)!=LBits(LTick.ask) ||
      LBits(threshold_a)!=LBits(LThresholdA) || LBits(threshold_b)!=LBits(LFreeze)) LFault=5;
   LTrace(8,ticket);LChanged(8);
}
#define SymbolInfoInteger LSymbolInteger
#define SymbolInfoDouble LSymbolDouble
#define SymbolInfoTick LSymbolTick
#define Bot3VirtualStopLevel LStopLevel
#define Bot3VirtualTakeLevel LTakeLevel
#define Bot3VirtualStopDelayPassed LDelayPassed
#define Bot3ModifyPosition LModifyPosition
#define Bot3VirtualStopStamp LStamp
#define Bot3TryClosePosition LTryClose
#include "../../Include/bot-cua-toi-3/Bot3ManagementVirtualStart.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementVirtualTake.mqh"
#undef SymbolInfoInteger
#undef SymbolInfoDouble
#undef SymbolInfoTick
#undef Bot3VirtualStopLevel
#undef Bot3VirtualTakeLevel
#undef Bot3VirtualStopDelayPassed
#undef Bot3ModifyPosition
#undef Bot3VirtualStopStamp
#undef Bot3TryClosePosition
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot3-management-virtual-levels\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d564c33 || version!=1 || count<1 || count>100000) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(source),buy=FileReadInteger(source),stage=FileReadInteger(source);
      LScenario=FileReadInteger(source);LDelay=FileReadInteger(source)!=0;LModify=FileReadInteger(source)!=0;
      LTickOk=FileReadInteger(source)!=0;bool changed=FileReadInteger(source)!=0;
      LIndex=(uint)FileReadInteger(source);
      for(int k=0;k<3;k++) LDigits[k]=FileReadInteger(source);
      int seconds=FileReadInteger(source);long ticket=FileReadLong(source);
      Bot3ManagedPosition position;ZeroMemory(position);position.ticket_number=(double)ticket;
      position.open_price=FileReadDouble(source);position.sl=FileReadDouble(source);position.tp=FileReadDouble(source);position.volume=FileReadDouble(source);
      LUnit=FileReadDouble(source);LStop=FileReadDouble(source);LDistance=FileReadDouble(source);double start=FileReadDouble(source);
      LCurrent=FileReadDouble(source);LTake=FileReadDouble(source);LStopReply=FileReadDouble(source);LTakeReply=FileReadDouble(source);
      LPoint=FileReadDouble(source);LMinimum=FileReadDouble(source);ZeroMemory(LTick);
      LTick.bid=FileReadDouble(source);LTick.ask=FileReadDouble(source);LNextBid=FileReadDouble(source);LNextAsk=FileReadDouble(source);
      double table_volume=FileReadDouble(source),anchor=FileReadDouble(source);LFreeze=FileReadDouble(source);
      if(id!=i || (buy!=0 && buy!=1) || (stage!=0 && stage!=4) || LIndex>=9) { LFault=9;break; }
      double volumes[9];ArrayInitialize(volumes,777.0);volumes[LIndex]=table_volume;
      Bot3PendingRequestState state;ZeroMemory(state);Bot3TradeSendOptions options;ZeroMemory(options);
      Bot3VirtualStopState table;long open_tickets[];
      double initial_stop=LStopReply,initial_take=LTakeReply;
      LCalls=0;LDigitCount=0;LHash=(ulong)0xcbf29ce484222325;bool closed=false;string symbol="CHECK";
      if(stage==0) closed=Bot3StartVirtualManagement(buy!=0,symbol,LUnit,LStop,seconds,ticket,position,LTick,
                                                    table,open_tickets,initial_stop,initial_take,LCurrent,LTake,
                                                    state,options,LDeviation,LThresholdA,LFreeze);
      else closed=Bot3AdvanceVirtualTake(buy!=0,symbol,LUnit,LDistance,start,anchor,position,LTick,
                                         volumes,LIndex,LTake,changed,state,options,LDeviation,LThresholdA,LFreeze,(ulong)ticket);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)closed);FileWriteInteger(output,(int)changed);FileWriteInteger(output,(int)LIndex);
      FileWriteDouble(output,initial_stop);FileWriteDouble(output,initial_take);FileWriteDouble(output,LCurrent);FileWriteDouble(output,LTake);
      FileWriteDouble(output,position.sl);FileWriteDouble(output,position.tp);FileWriteDouble(output,LTick.bid);FileWriteDouble(output,LTick.ask);
      FileWriteDouble(output,LUnit);FileWriteDouble(output,LStop);FileWriteDouble(output,LDistance);FileWriteDouble(output,LFreeze);
      FileWriteInteger(output,LCalls);FileWriteLong(output,(long)LHash);
   }
   if(LFault==0 && FileTell(source)!=FileSize(source)) LFault=10;
   FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,LFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot3ManagementVirtualLevelsCheck:",LFault,",",count);return LFault;
}
