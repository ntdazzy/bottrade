#property strict
#property script_show_inputs
input string CheckRun="";
datetime GivenTime;int GivenInfo,StructOK,Fault,Calls[3];ulong CallHash;
void Event(const int kind) { Calls[kind-1]++;for(int j=0;j<8;j++) { CallHash^=((ulong)kind>>(j*8))&255;CallHash*=(ulong)0x100000001b3; } }
datetime SupplyServer() { Event(1);return GivenTime; }
bool SupplyStruct(const datetime value,MqlDateTime &target)
{
   Event(2);if(value!=GivenTime) Fault=20;
   if(StructOK==0) return false;
   bool ok=TimeToStruct(value,target);if(!ok) Fault=21;return ok;
}
int SupplyInfo(const ENUM_MQL_INFO_INTEGER property) { Event(3);if((int)property!=7) Fault=22;return GivenInfo; }
#define TimeTradeServer SupplyServer
#define TimeToStruct SupplyStruct
#define MQLInfoInteger SupplyInfo
#include "../../Include/bot-cua-toi-3/Bot3EvaluationHead.mqh"
#undef TimeTradeServer
#undef TimeToStruct
#undef MQLInfoInteger
string ReadText(const int file) { int n=FileReadInteger(file);if(n<0 || n>10000) { Fault=23;return ""; }return n==0 ? "" : FileReadString(file,n); }
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>50) return 4;
   for(int j=0;j<StringLen(CheckRun);j++) { ushort c=StringGetCharacter(CheckRun,j);if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 4; }
   string folder="bot3-evaluation-head\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"script-status.bin")) return 5;
   int source=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(source==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(source),version=FileReadInteger(source),count=FileReadInteger(source);
   if(magic!=0x45484433 || version!=1 || count<1 || count>10000) { FileClose(source);return 7; }
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE) { FileClose(source);return 8; }
   FileWriteInteger(output,0x45484433);FileWriteInteger(output,1);FileWriteInteger(output,count);FileWriteInteger(output,17);
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(source);uint index=(uint)FileReadInteger(source);uchar caller=(uchar)FileReadInteger(source);
      Bot3EvaluationHeadInputs inputs;ZeroMemory(inputs);inputs.native_1d6d08=(uchar)FileReadInteger(source);
      GivenInfo=FileReadInteger(source);StructOK=FileReadInteger(source);GivenTime=(datetime)FileReadLong(source);
      int kind=FileReadInteger(source),other_kind=FileReadInteger(source);
      Bot3EvaluationHeadState state;ZeroMemory(state);
      state.calendar.year=FileReadInteger(source);state.calendar.mon=FileReadInteger(source);state.calendar.day=FileReadInteger(source);
      state.calendar.hour=FileReadInteger(source);state.calendar.min=FileReadInteger(source);state.calendar.sec=FileReadInteger(source);
      state.calendar.day_of_week=FileReadInteger(source);state.calendar.day_of_year=FileReadInteger(source);
      inputs.symbol=ReadText(source);inputs.native_1d6e28=ReadText(source);
      if(kind==0) inputs.symbol=NULL;
      if(other_kind==0) inputs.native_1d6e28=NULL;
      state.selected_symbol="OLD";ArrayInitialize(Calls,0);CallHash=(ulong)0xcbf29ce484222325;
      Bot3EvaluationHeadResult route=Bot3BeginEvaluation(index,caller,inputs,state);
      FileWriteInteger(output,id);FileWriteLong(output,(long)route);FileWriteLong(output,(long)state.strategy_index);FileWriteLong(output,(long)state.caller_flag);FileWriteLong(output,(long)state.server_time);
      FileWriteLong(output,state.calendar.year);FileWriteLong(output,state.calendar.mon);FileWriteLong(output,state.calendar.day);FileWriteLong(output,state.calendar.hour);
      FileWriteLong(output,state.calendar.min);FileWriteLong(output,state.calendar.sec);FileWriteLong(output,state.calendar.day_of_week);FileWriteLong(output,state.calendar.day_of_year);
      for(int j=0;j<3;j++) FileWriteLong(output,Calls[j]);FileWriteLong(output,(long)CallHash);FileWriteLong(output,(long)(state.selected_symbol==NULL));
      int n=StringLen(state.selected_symbol);FileWriteInteger(output,n);if(n>0) FileWriteString(output,state.selected_symbol,n);
   }
   if(FileTell(source)!=FileSize(source)) Fault=24;FileClose(source);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 9;FileWriteInteger(status,Fault);FileWriteInteger(status,count);FileClose(status);return Fault;
}
