#property strict
#property script_show_inputs
input string CheckRun="";

#define PRELUDE_MAGIC 0x45505233
#define PRELUDE_MAX_CASES 10000
#define PRELUDE_MAX_TEXT 10000

int InputFile=INVALID_HANDLE,OutputFile=INVALID_HANDLE,Fault=0;
int TimeTextCall=0;
union DoubleBits { double value; ulong bits; };

struct SessionInput
{
   int ok;
   long from;
   long to;
};
struct CaseInputs
{
   string symbol;
   string native_symbol;
   uchar native_1d6d08;
   int id;
   uint index;
   uchar caller_flag;
   int info;
   int struct_ok;
   long now;
   int calendar_initial[8];
   int calendar_reply[8];
   int tick_ok;
   int tick_write;
   ulong tick_initial[8];
   ulong tick_reply[8];
   long current_time;
   int current_write;
   int current_initial[8];
   int current_reply[8];
   string time_reply[2];
   SessionInput sessions[70];
};
CaseInputs CurrentCase;

void Fail(const int code) { if(Fault==0) Fault=code; }
uchar CurrentFlag();
void SetCalendar(MqlDateTime &calendar,const int &values[])
{
   calendar.year=values[0];calendar.mon=values[1];calendar.day=values[2];calendar.hour=values[3];
   calendar.min=values[4];calendar.sec=values[5];calendar.day_of_week=values[6];calendar.day_of_year=values[7];
}

void WriteText(const string value)
{
   const bool is_null=(value==NULL);
   FileWriteInteger(OutputFile,is_null ? 0 : 1);
   const int units=is_null ? 0 : StringLen(value);
   FileWriteInteger(OutputFile,units);
   if(units>0) FileWriteString(OutputFile,value,units);
}
void WriteEvent(const int kind,const ulong w1=0,const ulong w2=0,const ulong w3=0,
                const ulong w4=0,const ulong w5=0,const string a=NULL,
                const string b=NULL,const string c=NULL)
{
   FileWriteInteger(OutputFile,kind);
   FileWriteLong(OutputFile,(long)w1);FileWriteLong(OutputFile,(long)w2);
   FileWriteLong(OutputFile,(long)w3);FileWriteLong(OutputFile,(long)w4);
   FileWriteLong(OutputFile,(long)w5);FileWriteLong(OutputFile,(long)CurrentFlag());
   WriteText(a);WriteText(b);WriteText(c);
}
void EndEvents() { FileWriteInteger(OutputFile,0); }

string ReadText(const int file,bool &is_null)
{
   const int kind=FileReadInteger(file),units=FileReadInteger(file);
   if((kind!=0 && kind!=1) || units<0 || units>PRELUDE_MAX_TEXT || (kind==0 && units!=0)) { Fail(101);is_null=true;return NULL; }
   is_null=(kind==0);
   return is_null ? NULL : (units==0 ? "" : FileReadString(file,units));
}
bool ReadCase(const int file)
{
   CurrentCase.id=FileReadInteger(file);CurrentCase.index=(uint)FileReadInteger(file);
   CurrentCase.caller_flag=(uchar)FileReadInteger(file);
   CurrentCase.native_1d6d08=(uchar)FileReadInteger(file);
   CurrentCase.info=FileReadInteger(file);CurrentCase.struct_ok=FileReadInteger(file);
   CurrentCase.now=FileReadLong(file);
   const int symbol_kind=FileReadInteger(file),other_kind=FileReadInteger(file);
   for(int i=0;i<8;i++) CurrentCase.calendar_initial[i]=FileReadInteger(file);
   for(int i=0;i<8;i++) CurrentCase.calendar_reply[i]=FileReadInteger(file);
   bool null_symbol=false,null_other=false;
   CurrentCase.symbol=ReadText(file,null_symbol);
   CurrentCase.native_symbol=ReadText(file,null_other);
   if(symbol_kind==0) CurrentCase.symbol=NULL;
   if(other_kind==0) CurrentCase.native_symbol=NULL;
   if(symbol_kind<0 || symbol_kind>2 || other_kind<0 || other_kind>2) Fail(102);
   CurrentCase.tick_ok=FileReadInteger(file);CurrentCase.tick_write=FileReadInteger(file);
   for(int i=0;i<8;i++) CurrentCase.tick_initial[i]=(ulong)FileReadLong(file);
   for(int i=0;i<8;i++) CurrentCase.tick_reply[i]=(ulong)FileReadLong(file);
   CurrentCase.current_time=FileReadLong(file);CurrentCase.current_write=FileReadInteger(file);
   for(int i=0;i<8;i++) CurrentCase.current_initial[i]=FileReadInteger(file);
   for(int i=0;i<8;i++) CurrentCase.current_reply[i]=FileReadInteger(file);
   bool null_time0=false,null_time1=false;
   CurrentCase.time_reply[0]=ReadText(file,null_time0);CurrentCase.time_reply[1]=ReadText(file,null_time1);
   for(int i=0;i<70;i++)
   {
      CurrentCase.sessions[i].ok=FileReadInteger(file);
      CurrentCase.sessions[i].from=FileReadLong(file);CurrentCase.sessions[i].to=FileReadLong(file);
   }
   return FileTell(file)<=FileSize(file);
}

datetime FakeServer() { WriteEvent(1,(ulong)CurrentCase.now);return (datetime)CurrentCase.now; }
bool FakeStruct(const datetime value,MqlDateTime &calendar)
{
   WriteEvent(2,(ulong)(long)value,(ulong)CurrentCase.struct_ok);
   if(CurrentCase.struct_ok!=0) SetCalendar(calendar,CurrentCase.calendar_reply);
   return CurrentCase.struct_ok!=0;
}
int FakeInfo(const ENUM_MQL_INFO_INTEGER property)
{
   WriteEvent(3,(ulong)property,(ulong)(long)CurrentCase.info);if((int)property!=7) Fail(103);return CurrentCase.info;
}
void FakePrint(const string a) { WriteEvent(4,1,0,0,0,0,a); }
void FakePrint(const string a,const string b,const string c) { WriteEvent(4,3,0,0,0,0,a,b,c); }
string FakeIntegerToString(const long number,const int digits=0,const ushort separator=' ')
{
   string value=IntegerToString(number,digits,separator);
   WriteEvent(5,(ulong)number,(ulong)digits,(ulong)separator,0,0,value);return value;
}
bool FakeSessionTrade(const string symbol,const ENUM_DAY_OF_WEEK day,const uint index,datetime &from,datetime &to)
{
   const int d=(int)day,i=(int)index;int slot=(d>=0 && d<7 && i<10) ? d*10+i : -1;
   SessionInput row;row.ok=0;row.from=0;row.to=0;if(slot>=0) row=CurrentCase.sessions[slot];
   WriteEvent(6,(ulong)(long)d,(ulong)i,(ulong)row.ok,row.ok ? (ulong)row.from : 0,row.ok ? (ulong)row.to : 0,symbol);
   if(row.ok!=0) { from=(datetime)row.from;to=(datetime)row.to; }
   return row.ok!=0;
}
string FakeTimeToString(const datetime value,const int format=TIME_DATE|TIME_MINUTES)
{
   const int slot=TimeTextCall%2;TimeTextCall++;string value_text=CurrentCase.time_reply[slot];
   WriteEvent(7,(ulong)(long)value,(ulong)format,0,0,0,value_text);return value_text;
}
bool FakeTick(const string symbol,MqlTick &tick)
{
   WriteEvent(8,(ulong)CurrentCase.tick_ok,(ulong)CurrentCase.tick_write,0,0,0,symbol);
   if(CurrentCase.tick_write!=0)
   {
      tick.time=(datetime)CurrentCase.tick_reply[0];DoubleBits b;
      b.bits=CurrentCase.tick_reply[1];tick.bid=b.value;b.bits=CurrentCase.tick_reply[2];tick.ask=b.value;
      b.bits=CurrentCase.tick_reply[3];tick.last=b.value;tick.volume=CurrentCase.tick_reply[4];
      tick.time_msc=(long)CurrentCase.tick_reply[5];tick.flags=(uint)CurrentCase.tick_reply[6];
      b.bits=CurrentCase.tick_reply[7];tick.volume_real=b.value;
   }
   return CurrentCase.tick_ok!=0;
}
datetime FakeCurrent(MqlDateTime &calendar)
{
   WriteEvent(9,(ulong)CurrentCase.current_time,(ulong)CurrentCase.current_write);
   if(CurrentCase.current_write!=0) SetCalendar(calendar,CurrentCase.current_reply);
   return (datetime)CurrentCase.current_time;
}

#define TimeTradeServer FakeServer
#define TimeToStruct FakeStruct
#define MQLInfoInteger FakeInfo
#define Print FakePrint
#define IntegerToString FakeIntegerToString
#define SymbolInfoSessionTrade FakeSessionTrade
#define TimeToString FakeTimeToString
#define SymbolInfoTick FakeTick
#define TimeCurrent FakeCurrent
#include "../../Include/bot-cua-toi-3/Bot3EvaluationPrelude.mqh"
#undef TimeTradeServer
#undef TimeToStruct
#undef MQLInfoInteger
#undef Print
#undef IntegerToString
#undef SymbolInfoSessionTrade
#undef TimeToString
#undef SymbolInfoTick
#undef TimeCurrent

Bot3EvaluationHeadInputs ActiveInputs;
uchar CurrentFlag() { return ActiveInputs.native_1d6d08; }

void WriteFinal(Bot3EvaluationPreludeState &state)
{
   DoubleBits bits;FileWriteLong(OutputFile,(long)state.head.strategy_index);FileWriteLong(OutputFile,(long)state.head.caller_flag);
   FileWriteLong(OutputFile,(long)state.head.server_time);
   const int head_calendar[8]={state.head.calendar.year,state.head.calendar.mon,state.head.calendar.day,state.head.calendar.hour,state.head.calendar.min,state.head.calendar.sec,state.head.calendar.day_of_week,state.head.calendar.day_of_year};
   for(int i=0;i<8;i++) FileWriteLong(OutputFile,(long)head_calendar[i]);
   FileWriteLong(OutputFile,(long)state.session_flag);FileWriteLong(OutputFile,(long)CurrentFlag());FileWriteLong(OutputFile,(long)(state.head.selected_symbol==NULL));
   FileWriteLong(OutputFile,(long)state.tick.time);bits.value=state.tick.bid;FileWriteLong(OutputFile,(long)bits.bits);bits.value=state.tick.ask;FileWriteLong(OutputFile,(long)bits.bits);bits.value=state.tick.last;FileWriteLong(OutputFile,(long)bits.bits);
   FileWriteLong(OutputFile,(long)state.tick.volume);FileWriteLong(OutputFile,(long)state.tick.time_msc);FileWriteLong(OutputFile,(long)state.tick.flags);bits.value=state.tick.volume_real;FileWriteLong(OutputFile,(long)bits.bits);
   bits.value=state.spread;FileWriteLong(OutputFile,(long)bits.bits);
   const int current[8]={state.current_calendar.year,state.current_calendar.mon,state.current_calendar.day,state.current_calendar.hour,state.current_calendar.min,state.current_calendar.sec,state.current_calendar.day_of_week,state.current_calendar.day_of_year};
   for(int i=0;i<8;i++) FileWriteLong(OutputFile,(long)current[i]);
}

int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 4;
   for(int i=0;i<StringLen(CheckRun);i++) { ushort c=StringGetCharacter(CheckRun,i);if(!((c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='-')) return 4; }
   string folder="bot3-evaluation-prelude\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   InputFile=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(InputFile==INVALID_HANDLE) return 6;
   const int magic=FileReadInteger(InputFile),version=FileReadInteger(InputFile),count=FileReadInteger(InputFile);
   if(magic!=PRELUDE_MAGIC || version!=1 || count<1 || count>PRELUDE_MAX_CASES) { FileClose(InputFile);return 7; }
   OutputFile=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(OutputFile==INVALID_HANDLE) { FileClose(InputFile);return 8; }
   FileWriteInteger(OutputFile,PRELUDE_MAGIC);FileWriteInteger(OutputFile,1);FileWriteInteger(OutputFile,count);FileWriteInteger(OutputFile,31);
   for(int row=0;row<count;row++)
   {
      if(!ReadCase(InputFile)) { Fail(104);break; }
      FileWriteInteger(OutputFile,CurrentCase.id);ZeroMemory(ActiveInputs);
      ActiveInputs.symbol=CurrentCase.symbol;ActiveInputs.native_1d6e28=CurrentCase.native_symbol;ActiveInputs.native_1d6d08=CurrentCase.native_1d6d08;
      Bot3EvaluationPreludeState state;ZeroMemory(state);SetCalendar(state.head.calendar,CurrentCase.calendar_initial);
      state.tick.time=(datetime)CurrentCase.tick_initial[0];DoubleBits b;
      b.bits=CurrentCase.tick_initial[1];state.tick.bid=b.value;b.bits=CurrentCase.tick_initial[2];state.tick.ask=b.value;b.bits=CurrentCase.tick_initial[3];state.tick.last=b.value;state.tick.volume=CurrentCase.tick_initial[4];state.tick.time_msc=(long)CurrentCase.tick_initial[5];state.tick.flags=(uint)CurrentCase.tick_initial[6];b.bits=CurrentCase.tick_initial[7];state.tick.volume_real=b.value;
      SetCalendar(state.current_calendar,CurrentCase.current_initial);
      TimeTextCall=0;Bot3PrepareEvaluation(CurrentCase.index,CurrentCase.caller_flag,ActiveInputs,state);EndEvents();WriteFinal(state);
   }
   if(FileTell(InputFile)!=FileSize(InputFile)) Fail(105);
   FileClose(InputFile);FileClose(OutputFile);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 9;FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);return Fault;
}
