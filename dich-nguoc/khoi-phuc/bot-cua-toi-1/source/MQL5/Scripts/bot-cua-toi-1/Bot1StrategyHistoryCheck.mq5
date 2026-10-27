#property strict
input string CheckRun="";
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
#include "../../Include/bot-cua-toi-1/Bot1StrategyHistory.mqh"
#undef MQLInfoInteger
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef HistoryDealGetInteger
#undef HistoryDealGetString
#undef HistoryDealGetDouble
#undef ArrayResize
uchar ShowTester;uint Index;int Magic;string HistorySymbol;int ClosedTrades[8];Bot1StrategyHistoryCache Cache;
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
   FileWriteArray(TapeFile,words,0,5);Text(HistorySymbol);FileWriteInteger(TapeFile,8);FileWriteArray(TapeFile,ClosedTrades,0,8);
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
{ Begin(8,1,(ulong)(uint)count,(ulong)(uint)reserve,NULL);int reply=ArrayResize(values,count,reserve);KeysState();OwnersState();End(8,(ulong)(long)reply);return reply; }
int MockResize(long &values[],const int count,const int reserve)
{ Begin(8,2,(ulong)(uint)count,(ulong)(uint)reserve,NULL);int reply=ArrayResize(values,count,reserve);KeysState();OwnersState();End(8,(ulong)(long)reply);return reply; }
void LoadLongs(const int file,long &values[])
{ int n=FileReadInteger(file);ArrayResize(values,n);for(int i=0;i<n;i++)values[i]=FileReadLong(file); }
void ReadEffect(const int file,Effect &e)
{ e.api=FileReadInteger(file);e.n=FileReadInteger(file);e.field=FileReadInteger(file);e.word=0;e.text=NULL;if(e.field==5)e.text=ReadText(file);else e.word=(ulong)FileReadLong(file); }
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-strategy-history\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input_file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x53484331 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(input_file);
      for(int k=0;k<5;k++)SetField(k,(ulong)FileReadLong(input_file),NULL);HistorySymbol=ReadText(input_file);
      int n=FileReadInteger(input_file);if(n!=8)return 5;FileReadArray(input_file,ClosedTrades,0,n);
      int rev=FileReadInteger(input_file);n=FileReadInteger(input_file);ArraySetAsSeries(Cache.positions,false);ArrayResize(Cache.positions,n);
      for(int k=0;k<n;k++)Cache.positions[k]=(ulong)FileReadLong(input_file);ArraySetAsSeries(Cache.positions,rev!=0);
      rev=FileReadInteger(input_file);n=FileReadInteger(input_file);ArraySetAsSeries(Cache.magics,false);ArrayResize(Cache.magics,n);
      for(int k=0;k<n;k++)Cache.magics[k]=FileReadLong(input_file);ArraySetAsSeries(Cache.magics,rev!=0);
      ErrorMode=FileReadInteger(input_file);n=FileReadInteger(input_file);ArrayResize(Effects,n);for(int k=0;k<n;k++)ReadEffect(input_file,Effects[k]);
      int steps=FileReadInteger(input_file);Calls=0;LogicalError=0;ArrayInitialize(Counts,0);
      string name=folder+"events-"+IntegerToString(id)+".bin";TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE)return 6;
      for(int s=0;s<steps;s++)
      {
         InfoReply=FileReadInteger(input_file);SelectReply=FileReadInteger(input_file);n=FileReadInteger(input_file);ArrayResize(Totals,n);
         for(int k=0;k<n;k++)Totals[k]=FileReadInteger(input_file);
         n=FileReadInteger(input_file);for(int k=0;k<n;k++) { Effect e;ReadEffect(input_file,e);SetField(e.field,e.word,e.text); }
         n=FileReadInteger(input_file);ArrayResize(Deals,n);
         for(int k=0;k<n;k++)
         {
            Deals[k].ticket=(ulong)FileReadLong(input_file);Deals[k].symbol=ReadText(input_file);
            LoadLongs(input_file,Deals[k].types);LoadLongs(input_file,Deals[k].entries);LoadLongs(input_file,Deals[k].positions);LoadLongs(input_file,Deals[k].magics);
            Deals[k].profit=FileReadDouble(input_file);Deals[k].commission=FileReadDouble(input_file);Deals[k].swap=FileReadDouble(input_file);ArrayInitialize(Deals[k].reads,0);
         }
         TotalCalls=0;Selected=-1;double result=Bot1StrategyClosedProfit(ShowTester,HistorySymbol,Magic,Index,ClosedTrades,Cache);State();FileWriteLong(TapeFile,(long)Bits(result));
      }
      FileClose(TapeFile);int events=FileOpen(name,FILE_READ|FILE_BIN);if(events==INVALID_HANDLE)return 7;
      int size=(int)FileSize(events);uchar bytes[];ArrayResize(bytes,size);if(size>0)FileReadArray(events,bytes,0,size);FileClose(events);
      FileWriteInteger(output,id);FileWriteInteger(output,size);if(size>0)FileWriteArray(output,bytes,0,size);
   }
   FileClose(input_file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 8;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
