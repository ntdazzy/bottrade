// Supplied terminal and modify replies for the two timed real-stop functions; no live trading.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1ManagementPrelude.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ManagementMessages.mqh"
input string CheckRun="";
union TimedBits { double d;ulong u; };
int TCalls=0,TFault=0,TScenario=0,TModifyOk=0,TErrorCode=0,TDigits[2],TDigitIndex=0,TDelay=0;
double TUnit=0,TDistance=0,TGap=0,TFreeze=0,TPoint=0;
long TNow=0;
ulong THash=0;
MqlTick TTick;
ulong TBits(const double value) { TimedBits b;b.d=value;return b.u; }
ulong TText(const string value)
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
void TTrace(const int api,const ulong a=0,const ulong b=0,const ulong v=0,const ulong w=0)
{
   ulong words[5];words[0]=(ulong)api;words[1]=a;words[2]=b;words[3]=v;words[4]=w;
   for(int i=0;i<5;i++) for(int j=0;j<8;j++) { THash^=(words[i]>>(8*j))&255;THash*=(ulong)0x100000001b3; }
   TCalls++;
}
// Called after an event; changes the by-reference inputs only when the case scenario names that call.
void TMutate(const int target)
{
   if(TScenario!=target) return;
   TUnit*=2.0;TDistance+=.5;TGap+=.125;TFreeze+=.25;TTick.bid+=.25;TTick.ask+=.5;
   TDelay=(int)((uint)TDelay+1);
}
datetime TTime() { TTrace(9,(ulong)TNow);TMutate(1);return (datetime)TNow; }
long TSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(symbol!="CHECK" || property!=SYMBOL_DIGITS || TDigitIndex>=2) { TFault=1;return 0; }
   int index=TDigitIndex;int digit=TDigits[index];
   TTrace(3,17,(ulong)(long)digit,(ulong)index);TDigitIndex++;
   TMutate(index==0 ? 2 : 4);return (long)digit;
}
double TSymbolDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE property)
{
   if(symbol!="CHECK" || property!=SYMBOL_POINT) TFault=2;
   TTrace(4,16,TBits(TPoint));TMutate(3);return TPoint;
}
bool TModify(Bot1PendingRequestState &state,Bot1TradeSendOptions &options,
             const ulong ticket,const double sl,const double tp)
{
   TTrace(5,ticket,TBits(sl),TBits(tp),(ulong)(long)TModifyOk);TMutate(5);return TModifyOk!=0;
}
// Records the report call only; the real message body is checked separately.
void TReport(const string &suffix,uint &counter)
{
   if(suffix!="' when setting trailing Exit_TrailSL_after_X_Minutes_size_ loss.  Trying again!") TFault=3;
   TTrace(10,(ulong)(long)TErrorCode,(ulong)counter,TText(suffix));counter++;
}
#define TimeCurrent TTime
#define SymbolInfoInteger TSymbolInteger
#define SymbolInfoDouble TSymbolDouble
#define Bot1ModifyPosition TModify
#define Bot1PrintManagementError TReport
#include "../../Include/bot-cua-toi-1/Bot1ManagementRealTimed.mqh"
#undef TimeCurrent
#undef SymbolInfoInteger
#undef SymbolInfoDouble
#undef Bot1ModifyPosition
#undef Bot1PrintManagementError

int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4;
   }
   string folder="bot1-management-real-timed\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);
   if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x4d525431 || version!=1 || count<1 || count>100000 ||
      FileSize(source)!=(ulong)12+(ulong)count*140) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(source),buy=FileReadInteger(source);TScenario=FileReadInteger(source);
      TModifyOk=FileReadInteger(source);TErrorCode=FileReadInteger(source);
      TDigits[0]=FileReadInteger(source);TDigits[1]=FileReadInteger(source);TDelay=FileReadInteger(source);
      long ticket=FileReadLong(source);TNow=FileReadLong(source);long opened=FileReadLong(source);
      uint error_count=(uint)FileReadInteger(source);
      Bot1ManagedPosition position;ZeroMemory(position);position.open_price=100.0;position.opened=opened;
      position.sl=FileReadDouble(source);position.tp=FileReadDouble(source);
      ZeroMemory(TTick);TTick.bid=FileReadDouble(source);TTick.ask=FileReadDouble(source);
      TUnit=FileReadDouble(source);double activation=FileReadDouble(source);TDistance=FileReadDouble(source);
      TGap=FileReadDouble(source);TFreeze=FileReadDouble(source);TPoint=FileReadDouble(source);
      if(id!=i || (buy!=0 && buy!=1) || TScenario<0 || TScenario>5) { TFault=9;break; }
      Bot1PendingRequestState state;ZeroMemory(state);Bot1TradeSendOptions options;ZeroMemory(options);
      TCalls=0;TDigitIndex=0;THash=(ulong)0xcbf29ce484222325;bool requested=false;
      if(buy!=0) requested=Bot1AdvanceTimedBuyStop("CHECK",TUnit,activation,TDistance,TDelay,TGap,TFreeze,
                                                   position,TTick,state,options,error_count,(ulong)ticket);
      else requested=Bot1AdvanceTimedSellStop("CHECK",TUnit,activation,TDistance,TDelay,TGap,TFreeze,
                                              position,TTick,state,options,error_count,(ulong)ticket);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)requested);FileWriteInteger(output,TDelay);
      FileWriteInteger(output,(int)error_count);
      FileWriteDouble(output,position.sl);FileWriteDouble(output,position.tp);
      FileWriteDouble(output,TTick.bid);FileWriteDouble(output,TTick.ask);
      FileWriteDouble(output,TUnit);FileWriteDouble(output,activation);FileWriteDouble(output,TDistance);
      FileWriteDouble(output,TGap);FileWriteDouble(output,TFreeze);FileWriteDouble(output,TPoint);
      FileWriteInteger(output,TCalls);FileWriteLong(output,(long)THash);
   }
   if(TFault==0 && FileTell(source)!=FileSize(source)) TFault=10;
   FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 11;
   FileWriteInteger(status,TFault);FileWriteInteger(status,count);FileClose(status);
   Print("Bot1ManagementRealTimedCheck:",TFault,",",count);return TFault;
}
