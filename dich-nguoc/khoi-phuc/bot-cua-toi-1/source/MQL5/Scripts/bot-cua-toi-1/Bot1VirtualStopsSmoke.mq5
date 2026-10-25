// Initial native-comparison sequence. No orders or actual position queries.
#property strict
#property script_show_inputs
input string CheckRun="";

int CheckCalls=0,CheckFault=0;
ulong CheckHash=0;
long CheckNow=1000;

void CheckTrace(const int api,const long first,const long second,const long value)
{
   ulong words[4];words[0]=(ulong)api;words[1]=(ulong)first;
   words[2]=(ulong)second;words[3]=(ulong)value;
   for(int i=0;i<4;i++)
      for(int byte=0;byte<8;byte++)
      {
         CheckHash^=(words[i]>>(8*byte))&0xff;
         CheckHash*=(ulong)0x100000001b3;
      }
   CheckCalls++;
}
long CheckInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   if(symbol!="CHECK" || (int)property!=17) CheckFault=1;
   CheckTrace(1,(long)property,3,0);
   return 3;
}
datetime CheckTime()
{
   CheckTrace(2,0,CheckNow,0);
   return (datetime)CheckNow;
}
int CheckResize(long &values[],const int count,const int reserve=0)
{
   int result=ArrayResize(values,count,reserve);
   CheckTrace(3,count,reserve,result);
   return result;
}
int CheckTotal() { CheckTrace(4,0,0,0);return 0; }
ulong CheckTicket(const int index) { CheckTrace(5,index,0,0);CheckFault=1;return 0; }
long CheckPosition(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   CheckTrace(6,(long)property,0,0);CheckFault=1;return 0;
}
void CheckWarning(const string first,const int slots,const string second,const int positions,
                  const string third,const long ticket,const string fourth)
{
   CheckTrace(7,slots,positions,ticket);CheckFault=1;
}
#define SymbolInfoInteger CheckInteger
#define TimeCurrent CheckTime
#define ArrayResize CheckResize
#define PositionsTotal CheckTotal
#define PositionGetTicket CheckTicket
#define PositionGetInteger CheckPosition
#define Print CheckWarning
#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"
#undef SymbolInfoInteger
#undef TimeCurrent
#undef ArrayResize
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef Print

union SmokeBits { double d;ulong u; };
Bot1VirtualStopState Table;
long OpenTickets[];
string CheckSymbol="CHECK";
double CheckUnit=0.1;
int CheckDelay=99;

void WriteState(const int file,const int id,const ulong value)
{
   FileWriteInteger(file,id);FileWriteLong(file,(long)value);
   FileWriteInteger(file,(int)Table.guard);FileWriteLong(file,Table.reported_ticket);
   FileWriteInteger(file,ArraySize(OpenTickets));FileWriteInteger(file,CheckCalls);
   FileWriteLong(file,(long)CheckHash);
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
      for(int column=0;column<3;column++) FileWriteDouble(file,Table.rows[row][column]);
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 2;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 2;
   }
   string folder="bot1-virtual-smoke\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin")) return 3;
   int file=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(file==INVALID_HANDLE) return 4;
   FileWriteInteger(file,0x56535431);FileWriteInteger(file,1);FileWriteInteger(file,7);
   ZeroMemory(Table);Table.guard=1;Table.reported_ticket=9;
   for(int id=0;id<7;id++)
   {
      CheckCalls=0;CheckHash=(ulong)0xcbf29ce484222325;
      SmokeBits result;result.u=0;
      if(id==0) result.d=Bot1VirtualStopLevel(Table,OpenTickets,CheckSymbol,CheckUnit,1,100.0,10.0,7);
      if(id==1) result.d=Bot1VirtualStopLevel(Table,OpenTickets,CheckSymbol,CheckUnit,2,100.0,100.0,7);
      if(id==2) result.u=(ulong)Bot1VirtualStopDelayPassed(Table,CheckDelay,7);
      if(id==3) Bot1VirtualStopStamp(Table,7);
      if(id==4) { CheckNow=1098;result.u=(ulong)Bot1VirtualStopDelayPassed(Table,CheckDelay,7); }
      if(id==5) { CheckNow=1099;result.u=(ulong)Bot1VirtualStopDelayPassed(Table,CheckDelay,7); }
      if(id==6) Bot1DropClosedVirtualStops(Table,OpenTickets);
      WriteState(file,id,result.u);
   }
   FileClose(file);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 5;
   FileWriteInteger(status,CheckFault);FileWriteInteger(status,7);FileClose(status);
   Print("Bot1VirtualStopsSmoke:",CheckFault,",7");
   return CheckFault;
}
