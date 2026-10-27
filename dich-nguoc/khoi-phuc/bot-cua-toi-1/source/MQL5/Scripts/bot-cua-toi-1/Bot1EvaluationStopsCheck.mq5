#property strict
#define OnStart PreludeComponentStart
#include "Bot1EvaluationPreludeCheck.mq5"
#undef OnStart
#define STOP_MAGIC 0x45535431
struct StopPosition { ulong ticket;long magic,type,digits;ulong sl,tp,open;string symbol; };
struct StopEnvironment
{
   int enabled,magic,total,stopped,select_ok,async_mode,accepted,write_result,mutation;
   ulong stop,target,unit,trade_magic;
};
StopEnvironment StopCase;
StopPosition StopPositions[];
int SelectedPosition=-1;
bool StopChanged=false;
void WriteStopTrade();
void SupplyStopResult(MqlTradeResult &result);
void StopMutation(const int kind);
void StopEvent(const int kind,const ulong a=0,const ulong b=0,const ulong c=0,
               const ulong d=0,const ulong e=0,const string s0=NULL,
               const string s1=NULL,const string s2=NULL,const bool snapshot=false)
{
   WriteEvent(kind,a,b,c,d,e,s0,s1,s2);
   if(snapshot) WriteStopTrade();
   StopMutation(kind);
}
bool StopIsStopped() { return StopCase.stopped!=0; }
int StopTotal() { StopEvent(10,(ulong)(long)StopCase.total);return StopCase.total; }
ulong StopTicket(const int index)
{
   ulong ticket=(index>=0 && index<ArraySize(StopPositions)) ? StopPositions[index].ticket : 0;
   if(ticket!=0) SelectedPosition=index;
   StopEvent(11,(ulong)(long)index,ticket,(ulong)(long)SelectedPosition);return ticket;
}
bool HavePosition()
{
   if(SelectedPosition<0 || SelectedPosition>=ArraySize(StopPositions)) { Fail(301);return false; }
   return true;
}
long StopInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   if(!HavePosition()) return 0;
   if(property!=POSITION_MAGIC && property!=POSITION_TYPE) Fail(302);
   long value=(property==POSITION_MAGIC ? StopPositions[SelectedPosition].magic : StopPositions[SelectedPosition].type);
   StopEvent(12,(ulong)property,(ulong)value,(ulong)(long)SelectedPosition);return value;
}
string StopString(const ENUM_POSITION_PROPERTY_STRING property)
{
   if(!HavePosition()) return NULL;
   if(property!=POSITION_SYMBOL) Fail(303);
   string value=StopPositions[SelectedPosition].symbol;
   StopEvent(13,(ulong)property,(ulong)(long)SelectedPosition,0,0,0,value);return value;
}
double StopDouble(const ENUM_POSITION_PROPERTY_DOUBLE property)
{
   if(!HavePosition()) return 0;
   if(property!=POSITION_SL && property!=POSITION_TP && property!=POSITION_PRICE_OPEN) Fail(304);
   ulong value=(property==POSITION_SL ? StopPositions[SelectedPosition].sl :
               (property==POSITION_TP ? StopPositions[SelectedPosition].tp : StopPositions[SelectedPosition].open));
   StopEvent(14,(ulong)property,value,(ulong)(long)SelectedPosition);
   DoubleBits number;number.bits=value;return number.value;
}
long StopSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(!HavePosition()) return 0;
   if(property!=SYMBOL_DIGITS) Fail(305);
   long value=StopPositions[SelectedPosition].digits;
   StopEvent(15,(ulong)property,(ulong)value,0,0,0,symbol);return value;
}
bool StopSymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property,long &value)
{
   value=StopSymbolInteger(symbol,property);return true;
}
bool StopSelect(const ulong ticket)
{
   int found=-1;
   for(int i=0;i<ArraySize(StopPositions);i++)
      if(StopPositions[i].ticket==ticket) { found=i;break; }
   bool ok=StopCase.select_ok!=0 && found>=0;
   if(ok) SelectedPosition=found;
   StopEvent(17,ticket,(ulong)ok,(ulong)(long)SelectedPosition);return ok;
}
void StopPrintFormat(const string format,const string name)
{
   StopEvent(18,2,0,0,0,0,format,name);
}
void StopPrintFormat(const string format,const string a,const string b)
{
   Fail(306);StopEvent(18,3,0,0,0,0,format,a,b);
}
bool StopSendCommon(const int async_mode,const MqlTradeRequest &request,MqlTradeResult &result)
{
   StopEvent(19,(ulong)async_mode,(ulong)StopCase.accepted,0,0,0,NULL,NULL,NULL,true);
   if(StopCase.write_result!=0) SupplyStopResult(result);
   StopEvent(20,0,0,0,0,0,NULL,NULL,NULL,true);return StopCase.accepted!=0;
}
bool StopSend(const MqlTradeRequest &request,MqlTradeResult &result) { return StopSendCommon(0,request,result); }
bool StopAsync(const MqlTradeRequest &request,MqlTradeResult &result) { return StopSendCommon(1,request,result); }
#define IsStopped StopIsStopped
#define PositionsTotal StopTotal
#define PositionGetTicket StopTicket
#define PositionGetInteger StopInteger
#define PositionGetString StopString
#define PositionGetDouble StopDouble
#define SymbolInfoInteger StopSymbolInteger
#define PositionSelectByTicket StopSelect
#define PrintFormat StopPrintFormat
#define OrderSend StopSend
#define OrderSendAsync StopAsync
#include "../../Include/bot-cua-toi-1/Bot1PositionModify.mqh"
bool ObservedModify(Bot1PendingRequestState &trade,Bot1TradeSendOptions &options,
                    const ulong ticket,const double sl,const double tp);
#define Bot1ModifyPosition ObservedModify
#include "../../Include/bot-cua-toi-1/Bot1EvaluationStops.mqh"
#undef Bot1ModifyPosition
#undef IsStopped
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef PositionGetString
#undef PositionGetDouble
#undef SymbolInfoInteger
#undef PositionSelectByTicket
#undef PrintFormat
#undef OrderSend
#undef OrderSendAsync
Bot1EvaluationStopInputs ActiveStop;
Bot1PendingRequestState ActiveTrade;
Bot1TradeSendOptions ActiveOptions;
#include "Bot1EvaluationStopsState.mqh"
bool ObservedModify(Bot1PendingRequestState &trade,Bot1TradeSendOptions &options,
                    const ulong ticket,const double sl,const double tp)
{
   DoubleBits a,b;a.value=sl;b.value=tp;
   StopEvent(16,ticket,a.bits,b.bits,0,0,NULL,NULL,NULL,true);
   return Bot1ModifyPosition(trade,options,ticket,sl,tp);
}
void StopMutation(const int kind)
{
   if(StopChanged) return;
   if(StopCase.mutation==1 && kind==11) ActiveStop.magic++;
   else if(StopCase.mutation==2 && kind==13) ActiveInputs.symbol="Đổi mã";
   else if(StopCase.mutation==3 && kind==15)
   { ActiveStop.stop_distance=37.25;ActiveStop.target_distance=-9.;ActiveStop.unit=.05; }
   else if(StopCase.mutation==4 && kind==20) ActiveStop.enabled=0;
   else if(StopCase.mutation==5 && kind==17) StopCase.stopped=1;
   else return;
   StopChanged=true;
}
bool ReadStopCase(const int file)
{
   StopCase.enabled=FileReadInteger(file);StopCase.magic=FileReadInteger(file);
   StopCase.stop=(ulong)FileReadLong(file);StopCase.target=(ulong)FileReadLong(file);StopCase.unit=(ulong)FileReadLong(file);
   StopCase.total=FileReadInteger(file);StopCase.trade_magic=(ulong)FileReadLong(file);
   StopCase.stopped=FileReadInteger(file);StopCase.select_ok=FileReadInteger(file);StopCase.async_mode=FileReadInteger(file);
   StopCase.accepted=FileReadInteger(file);StopCase.write_result=FileReadInteger(file);StopCase.mutation=FileReadInteger(file);
   int count=FileReadInteger(file);if(count<0 || count>8) { Fail(307);return false; }
   if(ArrayResize(StopPositions,count)!=count) { Fail(308);return false; }
   for(int i=0;i<count;i++)
   {
      StopPositions[i].ticket=(ulong)FileReadLong(file);StopPositions[i].magic=FileReadLong(file);
      StopPositions[i].type=FileReadLong(file);StopPositions[i].digits=FileReadLong(file);
      StopPositions[i].sl=(ulong)FileReadLong(file);StopPositions[i].tp=(ulong)FileReadLong(file);StopPositions[i].open=(ulong)FileReadLong(file);
      bool is_null=false;StopPositions[i].symbol=ReadText(file,is_null);
   }
   return FileTell(file)<=FileSize(file);
}
void InitPrefix(Bot1EvaluationPreludeState &state)
{
   ZeroMemory(state);SetCalendar(state.calendar,CurrentCase.calendar_initial);
   SetCalendar(state.current_calendar,CurrentCase.current_initial);
   state.tick.time=(datetime)CurrentCase.tick_initial[0];DoubleBits n;
   n.bits=CurrentCase.tick_initial[1];state.tick.bid=n.value;n.bits=CurrentCase.tick_initial[2];state.tick.ask=n.value;
   n.bits=CurrentCase.tick_initial[3];state.tick.last=n.value;state.tick.volume=CurrentCase.tick_initial[4];
   state.tick.time_msc=(long)CurrentCase.tick_initial[5];state.tick.flags=(uint)CurrentCase.tick_initial[6];
   n.bits=CurrentCase.tick_initial[7];state.tick.volume_real=n.value;
}
void WriteStopContext()
{
   FileWriteLong(OutputFile,(long)ActiveStop.enabled);FileWriteLong(OutputFile,(long)ActiveStop.magic);
   DoubleBits n;n.value=ActiveStop.stop_distance;FileWriteLong(OutputFile,(long)n.bits);
   n.value=ActiveStop.target_distance;FileWriteLong(OutputFile,(long)n.bits);n.value=ActiveStop.unit;FileWriteLong(OutputFile,(long)n.bits);
   FileWriteLong(OutputFile,(long)SelectedPosition);FileWriteLong(OutputFile,(long)StopCase.stopped);WriteText(ActiveInputs.symbol);
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 4;
   for(int i=0;i<StringLen(CheckRun);i++)
   { ushort c=StringGetCharacter(CheckRun,i);if(!((c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='-')) return 4; }
   string folder="bot1-evaluation-stops\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   InputFile=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(InputFile==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(InputFile),version=FileReadInteger(InputFile),count=FileReadInteger(InputFile);
   if(magic!=STOP_MAGIC || version!=1 || count<1 || count>10000) { FileClose(InputFile);return 7; }
   OutputFile=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(OutputFile==INVALID_HANDLE) { FileClose(InputFile);return 8; }
   FileWriteInteger(OutputFile,STOP_MAGIC);FileWriteInteger(OutputFile,1);FileWriteInteger(OutputFile,count);FileWriteInteger(OutputFile,30);
   for(int row=0;row<count;row++)
   {
      if(!ReadCase(InputFile) || !ReadStopCase(InputFile)) { Fail(309);break; }
      if(CurrentCase.id!=row) Fail(310);
      FileWriteInteger(OutputFile,CurrentCase.id);SelectedPosition=-1;StopChanged=false;TimeTextCall=0;
      ZeroMemory(ActiveInputs);ActiveInputs.symbol=CurrentCase.symbol;ActiveInputs.native_6a428=CurrentCase.native_symbol;
      ActiveInputs.native_6a3b4=CurrentCase.native_6a3b4;
      ActiveStop.enabled=(uchar)StopCase.enabled;ActiveStop.magic=StopCase.magic;DoubleBits n;
      n.bits=StopCase.stop;ActiveStop.stop_distance=n.value;n.bits=StopCase.target;ActiveStop.target_distance=n.value;
      n.bits=StopCase.unit;ActiveStop.unit=n.value;SeedStopTrade();
      Bot1EvaluationPreludeState state;InitPrefix(state);
      Bot1PrepareEvaluation(CurrentCase.index,ActiveInputs,state);
      EndEvents();WriteFinal(state);
      Bot1FillEvaluationStops(ActiveInputs.symbol,ActiveStop,ActiveTrade,ActiveOptions);
      EndEvents();WriteStopTrade();WriteStopContext();
   }
   if(FileTell(InputFile)!=FileSize(InputFile)) Fail(311);
   FileClose(InputFile);FileClose(OutputFile);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);return Fault;
}
