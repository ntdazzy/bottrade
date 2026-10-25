// Supplied positions/time/digits; actual array resizing. No orders.
#property strict
#property script_show_inputs
input string CheckRun="";
input int OnlyCase=-1;

int Fixture=INVALID_HANDLE,EventCount=0;
long EventCountPosition=0;
int CaseKind,CaseSide,CaseDelay,Selected=-1,PositionTotal;
long CaseDigits,CaseTicket,CaseNow;
double CasePrice,CaseDistance,CurrentUnit;
string CaseSymbol;
long OpenTickets[],PositionTypes[];
ulong PositionTickets[];
int Hits[9],ControlApi,ControlHit,ControlKind,ControlRow,FailResizeCall;
long ControlInteger;
double ControlValues[3];
union MatrixBits { double d;long q; };

double ReadDouble(const int file)
{
   MatrixBits value;value.q=FileReadLong(file);return value.d;
}
void WriteDouble(const int file,const double number)
{
   MatrixBits value;value.d=number;FileWriteLong(file,value.q);
}
string ReadText(const int file)
{
   int size=FileReadInteger(file);
   if(size<0 || size>2048) return "";
   return size==0 ? "" : FileReadString(file,size);
}
void WriteText(const int file,const string text)
{
   int size=StringLen(text);FileWriteInteger(file,size);
   if(size>0) FileWriteString(file,text,size);
}
void WriteSnapshot(const int file);
void ApplyControl(const int api);
void BeginEvent(const int api)
{
   FileWriteInteger(Fixture,api);WriteSnapshot(Fixture);Hits[api]++;
}
void EndEvent(const int api)
{
   ApplyControl(api);WriteSnapshot(Fixture);
   EventCount++;
   long tail=(long)FileTell(Fixture);
   FileSeek(Fixture,EventCountPosition,SEEK_SET);FileWriteInteger(Fixture,EventCount);
   FileSeek(Fixture,tail,SEEK_SET);FileFlush(Fixture);
}
void WriteArray(const int file,const long &values[])
{
   int size=ArraySize(values);bool series=ArrayGetAsSeries(values);
   FileWriteInteger(file,size);FileWriteInteger(file,(int)series);
   for(int physical=0;physical<size;physical++)
      FileWriteLong(file,values[series ? size-1-physical : physical]);
}
long MatrixInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property)
{
   BeginEvent(1);FileWriteInteger(Fixture,(int)property);WriteText(Fixture,symbol);
   FileWriteLong(Fixture,CaseDigits);EndEvent(1);return CaseDigits;
}
datetime MatrixTime()
{
   BeginEvent(2);FileWriteLong(Fixture,CaseNow);EndEvent(2);return (datetime)CaseNow;
}
int MatrixResize(long &values[],const int count,const int reserve=0)
{
   BeginEvent(3);FileWriteInteger(Fixture,count);FileWriteInteger(Fixture,reserve);
   WriteArray(Fixture,values);
   int result=Hits[3]==FailResizeCall ? -1 : ArrayResize(values,count,reserve);
   FileWriteInteger(Fixture,result);WriteArray(Fixture,values);EndEvent(3);return result;
}
int MatrixTotal()
{
   BeginEvent(4);FileWriteInteger(Fixture,PositionTotal);EndEvent(4);return PositionTotal;
}
ulong MatrixTicket(const int index)
{
   BeginEvent(5);ulong value=0;
   if(index>=0 && index<ArraySize(PositionTickets))
   {
      value=PositionTickets[index];
      if(value!=0) Selected=index;
   }
   FileWriteInteger(Fixture,index);FileWriteLong(Fixture,(long)value);
   EndEvent(5);return value;
}
long MatrixPosition(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   BeginEvent(6);long value=Selected>=0 ? PositionTypes[Selected] : 0;
   FileWriteInteger(Fixture,(int)property);FileWriteLong(Fixture,value);
   EndEvent(6);return value;
}
void MatrixWarning(const string first,const int slots,const string second,const int positions,
                   const string third,const long ticket,const string fourth)
{
   BeginEvent(7);WriteText(Fixture,first);FileWriteInteger(Fixture,slots);
   WriteText(Fixture,second);FileWriteInteger(Fixture,positions);
   WriteText(Fixture,third);FileWriteLong(Fixture,ticket);WriteText(Fixture,fourth);
   EndEvent(7);
}
#define SymbolInfoInteger MatrixInteger
#define TimeCurrent MatrixTime
#define ArrayResize MatrixResize
#define PositionsTotal MatrixTotal
#define PositionGetTicket MatrixTicket
#define PositionGetInteger MatrixPosition
#define Print MatrixWarning
#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"
#undef SymbolInfoInteger
#undef TimeCurrent
#undef ArrayResize
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef Print

Bot1VirtualStopState Table;

void WriteSnapshot(const int file)
{
   FileWriteInteger(file,(int)Table.guard);FileWriteLong(file,Table.reported_ticket);
   FileWriteInteger(file,CaseDelay);WriteDouble(file,CurrentUnit);WriteText(file,CaseSymbol);
   FileWriteInteger(file,Selected);FileWriteInteger(file,ArraySize(OpenTickets));
   FileWriteInteger(file,(int)ArrayGetAsSeries(OpenTickets));
   for(int column=0;column<3;column++) WriteDouble(file,Table.rows[ControlRow][column]);
}
void ApplyControl(const int api)
{
   if(api!=ControlApi || Hits[api]!=ControlHit) return;
   if(ControlKind==1) CurrentUnit=ControlValues[0];
   if(ControlKind==2) CaseDelay=(int)ControlInteger;
   if(ControlKind==3 || ControlKind==7) Table.guard=(uchar)ControlInteger;
   if(ControlKind==4 || ControlKind==7)
      for(int column=0;column<3;column++) Table.rows[ControlRow][column]=ControlValues[column];
   if(ControlKind==5) Table.reported_ticket=ControlInteger;
}
bool LoadCase(const int file,int &id,bool &fatal)
{
   ZeroMemory(Table);
   id=FileReadInteger(file);CaseKind=FileReadInteger(file);fatal=FileReadInteger(file)!=0;
   int guard=FileReadInteger(file);CaseSide=FileReadInteger(file);CaseDelay=FileReadInteger(file);
   CaseDigits=FileReadLong(file);CaseTicket=FileReadLong(file);
   Table.reported_ticket=FileReadLong(file);CaseNow=FileReadLong(file);
   CasePrice=ReadDouble(file);CaseDistance=ReadDouble(file);CurrentUnit=ReadDouble(file);CaseSymbol=ReadText(file);
   int series=FileReadInteger(file),size=FileReadInteger(file);
   if(size<0 || size>4096 || CaseKind<0 || CaseKind>3 || guard<0 || guard>255 || (series!=0 && series!=1)) return false;
   ArrayFree(OpenTickets);ArraySetAsSeries(OpenTickets,false);
   if(ArrayResize(OpenTickets,size,0)!=size) return false;
   for(int index=0;index<size;index++) OpenTickets[index]=FileReadLong(file);
   ArraySetAsSeries(OpenTickets,series!=0);
   PositionTotal=FileReadInteger(file);int count=FileReadInteger(file);
   if(count<0 || count>1024) return false;
   if(ArrayResize(PositionTickets,count)!=count || ArrayResize(PositionTypes,count)!=count) return false;
   for(int index=0;index<count;index++)
   {
      PositionTickets[index]=(ulong)FileReadLong(file);PositionTypes[index]=FileReadLong(file);
   }
   int fill=FileReadInteger(file);
   MatrixBits nan;nan.q=(long)0x7ff8000000000001;
   for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
   {
      if(fill==1 || fill==3)
      {
         Table.rows[row][0]=(fill==1 ? 1.0 : -1.0)*(double)(row+1);
         Table.rows[row][1]=100.0+(double)row*0.125;
         Table.rows[row][2]=2000.0+(double)row;
      }
      if(fill==2) { Table.rows[row][0]=nan.d;Table.rows[row][1]=111.25; }
   }
   count=FileReadInteger(file);
   if(count<0 || count>500) return false;
   for(int index=0;index<count;index++)
   {
      int row=FileReadInteger(file);if(row<0 || row>=BOT1_VIRTUAL_STOP_ROWS) return false;
      for(int column=0;column<3;column++) Table.rows[row][column]=ReadDouble(file);
   }
   ControlApi=FileReadInteger(file);ControlHit=FileReadInteger(file);
   ControlKind=FileReadInteger(file);ControlRow=FileReadInteger(file);
   ControlInteger=FileReadLong(file);
   for(int column=0;column<3;column++) ControlValues[column]=ReadDouble(file);
   FailResizeCall=FileReadInteger(file);
   if(ControlRow<0 || ControlRow>=BOT1_VIRTUAL_STOP_ROWS || ControlApi<0 || ControlApi>7 ||
      ControlKind<0 || ControlKind>7 || ControlKind==6 || fill<0 || fill>3) return false;
   Table.guard=(uchar)guard;Selected=-1;ArrayInitialize(Hits,0);
   return true;
}
int OnStart()
{
   if(StringLen(CheckRun)<1 || StringLen(CheckRun)>40) return 2;
   for(int i=0;i<StringLen(CheckRun);i++)
   {
      ushort c=StringGetCharacter(CheckRun,i);
      if(!((c>='a' && c<='z') || (c>='0' && c<='9') || c=='-')) return 2;
   }
   string folder="bot1-virtual-matrix\\"+CheckRun+"\\";
   if(FileIsExist(folder+"mql5-results.bin") || FileIsExist(folder+"api-fixtures.bin")) return 3;
   int handle_in=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN|FILE_UNICODE);
   if(handle_in==INVALID_HANDLE) return 4;
   int magic=FileReadInteger(handle_in),version=FileReadInteger(handle_in);
   int count=FileReadInteger(handle_in),normal=FileReadInteger(handle_in);
   if(magic!=0x56534d31 || version!=1 || count<1 || normal<1 || OnlyCase>=count) return 5;
   int expected=OnlyCase>=0 ? 1 : normal;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   Fixture=FileOpen(folder+"api-fixtures.bin",FILE_WRITE|FILE_BIN|FILE_UNICODE);
   if(output==INVALID_HANDLE || Fixture==INVALID_HANDLE) return 6;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,expected);
   FileWriteInteger(Fixture,magic);FileWriteInteger(Fixture,version);FileWriteInteger(Fixture,expected);
   int processed=0;
   for(int index=0;index<count;index++)
   {
      int id=0;bool fatal=false;
      if(!LoadCase(handle_in,id,fatal) || id!=index) return 7;
      if((OnlyCase<0 && fatal) || (OnlyCase>=0 && OnlyCase!=id)) continue;
      FileWriteInteger(Fixture,id);EventCountPosition=(long)FileTell(Fixture);
      FileWriteInteger(Fixture,0);EventCount=0;
      Print("VIRTUAL_MATRIX_CASE:",id);FileFlush(Fixture);FileFlush(output);
      MatrixBits result;result.q=0;
      if(CaseKind==0) Bot1DropClosedVirtualStops(Table,OpenTickets);
      if(CaseKind==1) result.d=Bot1VirtualStopLevel(Table,OpenTickets,CaseSymbol,CurrentUnit,CaseSide,CasePrice,CaseDistance,CaseTicket);
      if(CaseKind==2) result.q=(long)Bot1VirtualStopDelayPassed(Table,CaseDelay,CaseTicket);
      if(CaseKind==3) Bot1VirtualStopStamp(Table,CaseTicket);
      FileWriteInteger(output,id);FileWriteInteger(output,CaseKind);FileWriteLong(output,result.q);
      WriteSnapshot(output);
      for(int row=0;row<BOT1_VIRTUAL_STOP_ROWS;row++)
         for(int column=0;column<3;column++) WriteDouble(output,Table.rows[row][column]);
      WriteArray(output,OpenTickets);processed++;
   }
   if(FileTell(handle_in)!=FileSize(handle_in) || processed!=expected) return 8;
   FileClose(handle_in);FileClose(output);FileClose(Fixture);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 9;
   FileWriteInteger(status,0);FileWriteInteger(status,processed);FileClose(status);
   Print("Bot1VirtualStopsCheck:0,",processed);return 0;
}
