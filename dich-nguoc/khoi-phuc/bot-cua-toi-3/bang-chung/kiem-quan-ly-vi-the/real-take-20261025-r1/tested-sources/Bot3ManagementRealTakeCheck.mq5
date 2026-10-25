// Supplied terminal, modify, report and close replies for the two real take functions; no live trading.
#property strict
#property script_show_inputs
// Included before the macros so the real prelude and message bodies keep their own calls.
#include "../../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ManagementMessages.mqh"
input string CheckRun="";
union TakeDoubleBits { double d;ulong u; };
int TakeCalls=0,TakeFault=0,TakeScenario=0,TakeModifyOk=0,TakeErrorCode=0,TakeDigits[3],TakeDigitIndex=0;
ulong TakeHash=0;
// By-reference inputs of the checked functions, plus the supplied point and minimum volume replies.
double TakeUnit=0,TakeDistance=0,TakeStart=0,TakeGap=0,TakeFreeze=0,TakeVolumes[9],TakePoint=0,TakeMinimum=0;
uint TakeIndex=0;
ulong TakeDeviation=0;
MqlTick TakeTick;
Bot3PendingRequestState TakeState;
Bot3TradeSendOptions TakeOptions;
ulong TakeBits(const double value) { TakeDoubleBits b;b.d=value;return b.u; }
ulong TakeText(const string value)
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
void TakeTrace(const int api,const ulong a=0,const ulong b=0,const ulong v=0,const ulong w=0)
{
   ulong words[5];words[0]=(ulong)api;words[1]=a;words[2]=b;words[3]=v;words[4]=w;
   for(int i=0;i<5;i++) for(int j=0;j<8;j++) { TakeHash^=(words[i]>>(8*j))&255;TakeHash*=(ulong)0x100000001b3; }
   TakeCalls++;
}
// Called after each API event. Targets: digits 1/3/4 by call order, point 2, modify 5, minimum volume 6,
// report 7, close 8. Volumes, point, minimum, anchor, position and the error counter never change here.
void TakeMutate(const int target)
{
   if(TakeScenario!=target) return;
   TakeUnit*=2.0;TakeDistance+=.5;TakeStart+=.25;TakeGap+=.125;TakeFreeze+=.25;
   TakeTick.bid+=.25;TakeTick.ask+=.5;TakeIndex=(TakeIndex+1)%9;TakeDeviation++;
}
long TakeSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(symbol!="CHECK" || property!=SYMBOL_DIGITS || TakeDigitIndex>=3) { TakeFault=1;return 0; }
   int index=TakeDigitIndex;int digit=TakeDigits[index];
   TakeTrace(3,17,(ulong)(long)digit,(ulong)index);TakeDigitIndex++;
   TakeMutate(index==0 ? 1 : (index==1 ? 3 : 4));return (long)digit;
}
double TakeSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(symbol!="CHECK" || (property!=SYMBOL_POINT && property!=SYMBOL_VOLUME_MIN)) { TakeFault=2;return 0.0; }
   if(property==SYMBOL_POINT) { TakeTrace(4,16,TakeBits(TakePoint));TakeMutate(2);return TakePoint; }
   TakeTrace(4,34,TakeBits(TakeMinimum));TakeMutate(6);return TakeMinimum;
}
bool TakeModify(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                const ulong ticket,const double sl,const double tp)
{
   TakeTrace(5,ticket,TakeBits(sl),TakeBits(tp),(ulong)(long)TakeModifyOk);TakeMutate(5);return TakeModifyOk!=0;
}
// Records the report call only; the real message body is checked separately.
void TakeReport(const string &suffix,uint &counter)
{
   if(suffix!="' when setting trailing Exit_TP.  Trying again!") TakeFault=3;
   TakeTrace(10,(ulong)(long)TakeErrorCode,(ulong)counter,TakeText(suffix));counter++;TakeMutate(7);
}
// True only when both arguments are the per-case globals; the flipped probe fields are restored.
bool TakeSuppliedReferences(Bot3PendingRequestState &state,Bot3TradeSendOptions &options)
{
   ulong magic=TakeState.magic;int level=TakeOptions.log_level;
   bool same=state.magic==magic && options.log_level==level;
   TakeState.magic=magic^1;TakeOptions.log_level=level^1;
   same=same && state.magic==(magic^1) && options.log_level==(level^1);
   TakeState.magic=magic;TakeOptions.log_level=level;
   return same;
}
// Records the received close arguments only: no price refresh and no request; callers ignore the result.
bool TakeTryClose(Bot3PendingRequestState &state,Bot3TradeSendOptions &options,
                  const ulong &deviation,const double &bid,const double &ask,
                  const double &gap,const double &freeze,const ulong ticket)
{
   if(!TakeSuppliedReferences(state,options)) TakeFault=12;
   TakeTrace(6,ticket,deviation,TakeBits(bid),TakeBits(ask));
   TakeTrace(7,TakeBits(gap),TakeBits(freeze));
   TakeMutate(8);return true;
}
#define SymbolInfoInteger TakeSymbolInteger
#define SymbolInfoDouble TakeSymbolDouble
#define Bot3ModifyPosition TakeModify
#define Bot3PrintManagementError TakeReport
#define Bot3TryClosePosition TakeTryClose
#include "../../Include/bot-cua-toi-3/Bot3ManagementRealTake.mqh"
#undef SymbolInfoInteger
#undef SymbolInfoDouble
#undef Bot3ModifyPosition
#undef Bot3PrintManagementError
#undef Bot3TryClosePosition

// Reads one 244-byte case; only valid fields reach the function, then one 224-byte result is written.
bool TakeRunCase(const int source,const int output,const int index)
{
   int id=FileReadInteger(source),buy=FileReadInteger(source);TakeScenario=FileReadInteger(source);
   TakeModifyOk=FileReadInteger(source);TakeErrorCode=FileReadInteger(source);
   for(int i=0;i<3;i++) TakeDigits[i]=FileReadInteger(source);
   long ticket=FileReadLong(source);TakeDeviation=(ulong)FileReadLong(source);
   TakeIndex=(uint)FileReadInteger(source);
   uint error_count=(uint)FileReadInteger(source),prior_changed=(uint)FileReadInteger(source);
   Bot3ManagedPosition position;ZeroMemory(position);
   position.sl=FileReadDouble(source);position.tp=FileReadDouble(source);
   position.open_price=FileReadDouble(source);position.volume=FileReadDouble(source);
   ZeroMemory(TakeTick);TakeTick.bid=FileReadDouble(source);TakeTick.ask=FileReadDouble(source);
   TakeUnit=FileReadDouble(source);TakeDistance=FileReadDouble(source);TakeStart=FileReadDouble(source);
   double anchor=FileReadDouble(source);TakeGap=FileReadDouble(source);TakeFreeze=FileReadDouble(source);
   TakePoint=FileReadDouble(source);TakeMinimum=FileReadDouble(source);
   for(int i=0;i<9;i++) TakeVolumes[i]=FileReadDouble(source);
   if(id!=index || (buy!=0 && buy!=1) || TakeScenario<0 || TakeScenario>8 ||
      TakeIndex>8 || prior_changed>1) return false;
   TakeCalls=0;TakeDigitIndex=0;TakeHash=(ulong)0xcbf29ce484222325;
   ZeroMemory(TakeState);ZeroMemory(TakeOptions);
   bool changed=prior_changed!=0,returned=false;
   if(buy!=0) returned=Bot3AdvanceRealTakeBuy("CHECK",TakeUnit,TakeDistance,TakeStart,anchor,TakeGap,
                                              TakeFreeze,position,TakeTick,TakeVolumes,TakeIndex,changed,
                                              TakeState,TakeOptions,TakeDeviation,error_count,(ulong)ticket);
   else returned=Bot3AdvanceRealTakeSell("CHECK",TakeUnit,TakeDistance,TakeStart,anchor,TakeGap,
                                         TakeFreeze,position,TakeTick,TakeVolumes,TakeIndex,changed,
                                         TakeState,TakeOptions,TakeDeviation,error_count,(ulong)ticket);
   FileWriteInteger(output,id);FileWriteInteger(output,(int)returned);FileWriteInteger(output,(int)changed);
   FileWriteInteger(output,(int)TakeIndex);FileWriteInteger(output,(int)error_count);
   FileWriteLong(output,(long)TakeDeviation);
   FileWriteDouble(output,position.sl);FileWriteDouble(output,position.tp);
   FileWriteDouble(output,position.open_price);FileWriteDouble(output,position.volume);
   FileWriteDouble(output,TakeTick.bid);FileWriteDouble(output,TakeTick.ask);
   FileWriteDouble(output,TakeUnit);FileWriteDouble(output,TakeDistance);FileWriteDouble(output,TakeStart);
   FileWriteDouble(output,anchor);FileWriteDouble(output,TakeGap);FileWriteDouble(output,TakeFreeze);
   FileWriteDouble(output,TakePoint);FileWriteDouble(output,TakeMinimum);
   for(int i=0;i<9;i++) FileWriteDouble(output,TakeVolumes[i]);
   FileWriteInteger(output,TakeCalls);FileWriteLong(output,(long)TakeHash);
   return true;
}
// Writes the result header and every case in order; a bad case stops the run before its call.
void TakeRunCases(const int source,const string path,const int magic,const int version,const int count)
{
   int output=FileOpen(path,FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { TakeFault=8;return; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
      if(!TakeRunCase(source,output,i)) { TakeFault=9;break; }
   FileClose(output);
   if(TakeFault==0 && FileTell(source)!=FileSize(source)) TakeFault=10;
}

int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot3-management-real-take\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d525033 || version!=1 || count<1 || count>100000 ||
      FileSize(source)!=(ulong)12+(ulong)count*244) TakeFault=7;
   else TakeRunCases(source,folder+"mql5-results.bin",magic,version,count);
   FileClose(source);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,TakeFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot3ManagementRealTakeCheck:",TakeFault,",",count);return TakeFault;
}
