#property strict
input string CheckRun="";
input int FaultKind=0;
string FaultFolder;
int MockInfo(const ENUM_MQL_INFO_INTEGER property);
bool MockSelect(const datetime from,const datetime to);
int MockTotal();ulong MockTicket(const int index);
long MockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property);
string MockString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property);
double MockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property);
int MockResize(ulong &values[],const int count,const int reserve=0);
int MockResize(long &values[],const int count,const int reserve=0);
#define MQLInfoInteger MockInfo
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define HistoryDealGetInteger MockInteger
#define HistoryDealGetString MockString
#define HistoryDealGetDouble MockDouble
#define ArrayResize MockResize
#include "../../Include/bot-cua-toi-3/Bot3StrategyHistory.mqh"
#undef MQLInfoInteger
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef HistoryDealGetInteger
#undef HistoryDealGetString
#undef HistoryDealGetDouble
#undef ArrayResize
uchar ShowTester;uint Index;int Magic;string HistorySymbol;int ClosedTrades[9];Bot3StrategyHistoryCache Cache;
int TapeFile,ErrorMode,Counts[9],Calls,InfoReply,SelectReply,Totals[],TotalCalls,Selected;uint LogicalError;
struct Deal { ulong ticket;string symbol;long types[],entries[],positions[],magics[];int reads[4];double profit,commission,swap; };Deal Deals[];
struct Effect { int api,n,field;ulong word;string text; };Effect Effects[];
union Number { double value;ulong word; };
ulong Bits(const double value) { Number n;n.value=value;return n.word; }
string ReadText(const int file) { int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n)); }
void Text(const string value)
{ if(value==NULL) {FileWriteInteger(TapeFile,-1);return;}int n=StringLen(value);FileWriteInteger(TapeFile,n);if(n>0)FileWriteString(TapeFile,value,n); }
void KeysState()
{ bool rev=ArrayGetAsSeries(Cache.positions);int n=ArraySize(Cache.positions);FileWriteInteger(TapeFile,(int)rev);FileWriteInteger(TapeFile,n);for(int i=0;i<n;i++)FileWriteLong(TapeFile,(long)Cache.positions[rev ? n-1-i : i]); }
void OwnersState()
{ bool rev=ArrayGetAsSeries(Cache.magics);int n=ArraySize(Cache.magics);FileWriteInteger(TapeFile,(int)rev);FileWriteInteger(TapeFile,n);for(int i=0;i<n;i++)FileWriteLong(TapeFile,Cache.magics[rev ? n-1-i : i]); }
void State()
{
   ulong words[5];words[0]=(ulong)ShowTester;words[1]=(ulong)Index;words[2]=(ulong)(long)Magic;words[3]=(ulong)(long)Cache.count;words[4]=(ulong)(long)Cache.total;
   FileWriteArray(TapeFile,words,0,5);Text(HistorySymbol);FileWriteInteger(TapeFile,9);FileWriteArray(TapeFile,ClosedTrades,0,9);
   KeysState();OwnersState();FileWriteLong(TapeFile,(long)LogicalError);
}
void SetField(const int field,const ulong word,const string text)
{
   switch(field)
   {
      case 0: ShowTester=(uchar)word;break;case 1: Index=(uint)word;break;case 2: Magic=(int)word;break;
      case 3: Cache.count=(int)word;break;case 4: Cache.total=(int)word;break;case 5: HistorySymbol=text;break;
      case 6: ArraySetAsSeries(Cache.positions,word!=0);break;case 7: ArraySetAsSeries(Cache.magics,word!=0);break;
      case 8: ClosedTrades[0]=(int)word;break;
   }
}
void Begin(const int api,const ulong a,const ulong b,const ulong c,const string value)
{ State();FileWriteInteger(TapeFile,api);FileWriteLong(TapeFile,(long)a);FileWriteLong(TapeFile,(long)b);FileWriteLong(TapeFile,(long)c);Text(value); }
void End(const int api,const ulong reply)
{
   FileWriteLong(TapeFile,(long)reply);Calls++;Counts[api]++;if(ErrorMode!=0)LogicalError=(uint)(9000+Calls);FileWriteInteger(TapeFile,(int)LogicalError);
   for(int i=0;i<ArraySize(Effects);i++)if(Effects[i].api==api && Effects[i].n==Counts[api])SetField(Effects[i].field,Effects[i].word,Effects[i].text);
   FileFlush(TapeFile);int old=TapeFile;int state=FileOpen(FaultFolder+"last-state.bin",FILE_WRITE|FILE_BIN);
   if(state==INVALID_HANDLE)return;TapeFile=state;State();FileClose(state);TapeFile=old;

}
void Record(const int api,const ulong a,const ulong b,const string value,const ulong reply)
{ Begin(api,a,b,0,value);End(api,reply); }
int MockInfo(const ENUM_MQL_INFO_INTEGER property) { int reply=InfoReply;Record(1,(ulong)property,0,NULL,(ulong)(long)reply);return reply; }
bool MockSelect(const datetime from,const datetime to) { bool reply=SelectReply!=0;Record(2,(ulong)from,(ulong)to,NULL,(ulong)reply);return reply; }
int MockTotal() { int reply=Totals[MathMin(TotalCalls,ArraySize(Totals)-1)];TotalCalls++;Record(3,0,0,NULL,(ulong)(long)reply);return reply; }
ulong MockTicket(const int index) { Selected=index;ulong reply=index>=0 && index<ArraySize(Deals) ? Deals[index].ticket : 0;Record(4,(ulong)(uint)index,0,NULL,reply);return reply; }
long Next(const long &values[],int &read) { long value=values[MathMin(read,ArraySize(values)-1)];read++;return value; }
long MockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property)
{
   long reply=0;
   switch((int)property)
   {
      case 3: reply=Next(Deals[Selected].types,Deals[Selected].reads[0]);break;
      case 4: reply=Next(Deals[Selected].entries,Deals[Selected].reads[1]);break;
      case 12: reply=Next(Deals[Selected].positions,Deals[Selected].reads[2]);break;
      case 11: reply=Next(Deals[Selected].magics,Deals[Selected].reads[3]);break;
   }
   Record(5,ticket,(ulong)property,NULL,(ulong)reply);return reply;
}
string MockString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property)
{ string reply=Deals[Selected].symbol;Record(6,ticket,(ulong)property,reply,0);return reply; }
double MockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property)
{ double reply=(int)property==9 ? Deals[Selected].profit : (int)property==7 ? Deals[Selected].commission : Deals[Selected].swap;Record(7,ticket,(ulong)property,NULL,Bits(reply));return reply; }
int MockResize(ulong &values[],const int count,const int reserve)
{ Begin(8,1,(ulong)(uint)count,(ulong)(uint)reserve,NULL);int reply=-1;KeysState();OwnersState();End(8,(ulong)(long)reply);return reply; }
int MockResize(long &values[],const int count,const int reserve)
{ Begin(8,2,(ulong)(uint)count,(ulong)(uint)reserve,NULL);int reply=-1;KeysState();OwnersState();End(8,(ulong)(long)reply);return reply; }
void LoadLongs(const int file,long &values[])
{ int n=FileReadInteger(file);ArrayResize(values,n);for(int i=0;i<n;i++)values[i]=FileReadLong(file); }
void ReadEffect(const int file,Effect &e)
{ e.api=FileReadInteger(file);e.n=FileReadInteger(file);e.field=FileReadInteger(file);e.word=0;e.text=NULL;if(e.field==5)e.text=ReadText(file);else e.word=(ulong)FileReadLong(file); }
int OnStart()
{
   if(CheckRun=="" || FaultKind<0 || FaultKind>3)return 1;
   FaultFolder="bot3-history-fault\\"+CheckRun+"\\kind-"+IntegerToString(FaultKind)+"\\";
   ShowTester=1;Index=0;Magic=9001;HistorySymbol="XAUUSD";
   for(int i=0;i<9;i++)ClosedTrades[i]=100+i;
   Cache.total=FaultKind<2 ? -1 : 1;Cache.count=FaultKind<2 ? 2 : 1;
   ArraySetAsSeries(Cache.positions,false);ArraySetAsSeries(Cache.magics,false);
   ArrayResize(Cache.positions,(FaultKind&1)!=0 ? 1 : 0);ArrayResize(Cache.magics,(FaultKind&1)!=0 ? 0 : 1);
   if(ArraySize(Cache.positions)>0)Cache.positions[0]=42;if(ArraySize(Cache.magics)>0)Cache.magics[0]=9001;
   ArrayResize(Effects,0);InfoReply=0;SelectReply=1;ArrayResize(Totals,2);Totals[0]=Totals[1]=1;
   ArrayResize(Deals,1);Deals[0].ticket=101;Deals[0].symbol="XAUUSD";
   ArrayResize(Deals[0].types,1);ArrayResize(Deals[0].entries,1);ArrayResize(Deals[0].positions,1);ArrayResize(Deals[0].magics,1);
   Deals[0].types[0]=0;Deals[0].entries[0]=FaultKind<2 ? 0 : 1;Deals[0].positions[0]=42;Deals[0].magics[0]=9001;
   Deals[0].profit=10.;Deals[0].commission=-1.;Deals[0].swap=-.5;ArrayInitialize(Deals[0].reads,0);
   ErrorMode=1;LogicalError=0;Calls=TotalCalls=0;Selected=-1;ArrayInitialize(Counts,0);
   TapeFile=FileOpen(FaultFolder+"events.bin",FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE)return 2;
   double value=Bot3StrategyClosedProfit(ShowTester,HistorySymbol,Magic,Index,ClosedTrades,Cache);
   FileClose(TapeFile);int unexpected=FileOpen(FaultFolder+"unexpected-return.bin",FILE_WRITE|FILE_BIN);
   if(unexpected!=INVALID_HANDLE) {FileWriteLong(unexpected,(long)Bits(value));FileClose(unexpected);}return 99;
}
