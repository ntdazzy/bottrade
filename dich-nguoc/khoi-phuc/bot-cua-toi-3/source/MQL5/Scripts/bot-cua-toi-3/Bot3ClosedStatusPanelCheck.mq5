#property strict
input string CheckRun="";
int MockInfo(const ENUM_MQL_INFO_INTEGER property);
bool MockSelect(const datetime from,const datetime to);
int MockTotal();ulong MockTicket(const int index);
long MockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property);
string MockString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property);
double MockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property);
string MockDoubleText(const double value,const int digits);
string MockIntegerText(const long value,const int width,const ushort fill);
bool MockObjectText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value);
#define MQLInfoInteger MockInfo
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define HistoryDealGetInteger MockInteger
#define HistoryDealGetString MockString
#define HistoryDealGetDouble MockDouble
#define DoubleToString MockDoubleText
#define IntegerToString MockIntegerText
#define ObjectSetString MockObjectText
#include "../../Include/bot-cua-toi-3/Bot3ClosedStatusPanel.mqh"
#undef MQLInfoInteger
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef HistoryDealGetInteger
#undef HistoryDealGetString
#undef HistoryDealGetDouble
#undef DoubleToString
#undef IntegerToString
#undef ObjectSetString
uchar Show;
uchar Tester;
int Seed;
string PanelSymbol;
double Wins;
double Losses;
int LogicalError,EventFile,CaseId,ErrorMode,InfoReply[2],ApiCounts[13],SelectReply,TotalReply,Selected,MagicCalls,ProfitCalls,CommissionCalls,SwapCalls;
struct DealReply { ulong ticket;string symbol;long magics[];double profit[],commission[],swap[]; };
DealReply Deals[];
struct Effect { int api,n,index;ulong word;string text; };Effect Effects[];
union NumberWords { double number;ulong word; };
ulong Bits(const double value) { NumberWords v;v.number=value;return v.word; }
double Number(const ulong value) { NumberWords v;v.word=value;return v.number; }
void Word(const int file,const ulong value) { FileWriteLong(file,(long)value); }
void WriteText(const int file,const string value)
{
   if(value==NULL) { FileWriteInteger(file,-1);return; }
   int n=StringLen(value);FileWriteInteger(file,n);if(n>0) FileWriteString(file,value,n);
}
string ReadText(const int file) { int n=FileReadInteger(file);return n>0 ? FileReadString(file,n) : NULL; }
void State(const int file)
{
   int size=48+4+2*StringLen(PanelSymbol);
   FileWriteInteger(file,size);
   Word(file,(ulong)(long)Show);
   Word(file,(ulong)(long)Tester);
   Word(file,(ulong)(long)Seed);
   WriteText(file,PanelSymbol);
   Word(file,Bits(Wins));
   Word(file,Bits(Losses));
   Word(file,(ulong)LogicalError);
}
void ApplyEffects(const int api)
{
   for(int i=0;i<ArraySize(Effects);i++)
      if(Effects[i].api==api && Effects[i].n==ApiCounts[api])
      {
         switch(Effects[i].index)
         {
         case 0: Show=(uchar)Effects[i].word;break;
         case 1: Tester=(uchar)Effects[i].word;break;
         case 2: Seed=(int)Effects[i].word;break;
         case 3: PanelSymbol=Effects[i].text;break;
         case 4: Wins=Number(Effects[i].word);break;
         case 5: Losses=Number(Effects[i].word);break;
         }
      }
}
void Record(const int api,const ulong a,const ulong b,const ulong c,const ulong d,
            const string t0,const string t1,const string t2,const string t3,const ulong reply,const int error_override=-1)
{
   State(EventFile);FileWriteInteger(EventFile,api);Word(EventFile,a);Word(EventFile,b);Word(EventFile,c);Word(EventFile,d);
   WriteText(EventFile,t0);WriteText(EventFile,t1);WriteText(EventFile,t2);WriteText(EventFile,t3);Word(EventFile,reply);
   ApiCounts[api]++;
   if(error_override>=0) LogicalError=error_override;
   else if(ErrorMode!=0) LogicalError=((ApiCounts[api]+api)%3==0 ? 0 : 65543);
   FileWriteInteger(EventFile,LogicalError);ApplyEffects(api);
}
int MockInfo(const ENUM_MQL_INFO_INTEGER property)
{ int reply=InfoReply[MathMin(ApiCounts[1],1)];Record(1,(ulong)property,0,0,0,NULL,NULL,NULL,NULL,(ulong)(long)reply);return reply; }
bool MockSelect(const datetime from,const datetime to)
{ bool reply=SelectReply!=0;Record(2,(ulong)from,(ulong)to,0,0,NULL,NULL,NULL,NULL,(ulong)reply);return reply; }
int MockTotal() { int reply=TotalReply;Record(3,0,0,0,0,NULL,NULL,NULL,NULL,(ulong)(long)reply);return reply; }
ulong MockTicket(const int index)
{ Selected=index;MagicCalls=ProfitCalls=CommissionCalls=SwapCalls=0;ulong reply=Deals[index].ticket;Record(4,(ulong)(uint)index,0,0,0,NULL,NULL,NULL,NULL,reply);return reply; }
long MockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property)
{ long reply=Deals[Selected].magics[MathMin(MagicCalls,ArraySize(Deals[Selected].magics)-1)];MagicCalls++;Record(5,ticket,(ulong)property,0,0,NULL,NULL,NULL,NULL,(ulong)reply);return reply; }
string MockString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property)
{ string reply=Deals[Selected].symbol;Record(6,ticket,(ulong)property,0,0,reply,NULL,NULL,NULL,0);return reply; }
double MockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property)
{
   double reply=0;
   if((int)property==9) { reply=Deals[Selected].profit[MathMin(ProfitCalls,ArraySize(Deals[Selected].profit)-1)];ProfitCalls++; }
   else if((int)property==7) { reply=Deals[Selected].commission[MathMin(CommissionCalls,ArraySize(Deals[Selected].commission)-1)];CommissionCalls++; }
   else { reply=Deals[Selected].swap[MathMin(SwapCalls,ArraySize(Deals[Selected].swap)-1)];SwapCalls++; }
   Record(7,ticket,(ulong)property,0,0,NULL,NULL,NULL,NULL,Bits(reply));return reply;
}
string MockDoubleText(const double value,const int digits)
{ string reply=DoubleToString(value,digits);Record(8,Bits(value),(ulong)(uint)digits,0,0,reply,NULL,NULL,NULL,0);return reply; }
string MockIntegerText(const long value,const int width,const ushort fill)
{ string reply=IntegerToString(value,width,fill);Record(9,(ulong)value,(ulong)(uint)width,(ulong)fill,0,reply,NULL,NULL,NULL,0);return reply; }
bool MockObjectText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value)
{ bool reply=(CaseId+ApiCounts[10])%2!=0;Record(10,(ulong)chart,(ulong)property,0,0,name,value,NULL,NULL,(ulong)reply);return reply; }
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-closed-panel\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4f535031 || version!=1 || count<1) return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE) return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int row=0;row<count;row++)
   {
      CaseId=FileReadInteger(file);
      Show=(uchar)(ulong)FileReadLong(file);
      Tester=(uchar)(ulong)FileReadLong(file);
      Seed=(int)(ulong)FileReadLong(file);
      PanelSymbol=ReadText(file);
      Wins=Number((ulong)FileReadLong(file));
      Losses=Number((ulong)FileReadLong(file));
      InfoReply[0]=FileReadInteger(file);InfoReply[1]=FileReadInteger(file);ErrorMode=FileReadInteger(file);SelectReply=FileReadInteger(file);TotalReply=FileReadInteger(file);
      int deals=FileReadInteger(file);ArrayResize(Deals,deals);
      for(int i=0;i<deals;i++)
      {
         Deals[i].ticket=(ulong)FileReadLong(file);Deals[i].symbol=ReadText(file);
         int n=FileReadInteger(file);ArrayResize(Deals[i].magics,n);for(int j=0;j<n;j++) Deals[i].magics[j]=FileReadLong(file);
         n=FileReadInteger(file);ArrayResize(Deals[i].profit,n);for(int j=0;j<n;j++) Deals[i].profit[j]=FileReadDouble(file);
         n=FileReadInteger(file);ArrayResize(Deals[i].commission,n);for(int j=0;j<n;j++) Deals[i].commission[j]=FileReadDouble(file);
         n=FileReadInteger(file);ArrayResize(Deals[i].swap,n);for(int j=0;j<n;j++) Deals[i].swap[j]=FileReadDouble(file);
      }
      int effects=FileReadInteger(file);ArrayResize(Effects,effects);
      for(int i=0;i<effects;i++)
      { Effects[i].api=FileReadInteger(file);Effects[i].n=FileReadInteger(file);Effects[i].index=FileReadInteger(file);if(Effects[i].index==3) Effects[i].text=ReadText(file);else Effects[i].word=(ulong)FileReadLong(file); }
      ArrayInitialize(ApiCounts,0);LogicalError=0;Selected=-1;
      string name=folder+"events-"+IntegerToString(CaseId)+".bin";EventFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(EventFile==INVALID_HANDLE) return 5;
      Bot3UpdateClosedStatusPanel(Show,Tester,Seed,PanelSymbol,Wins,Losses);State(EventFile);FileClose(EventFile);
      int events=FileOpen(name,FILE_READ|FILE_BIN);if(events==INVALID_HANDLE) return 6;
      int size=(int)FileSize(events);uchar bytes[];ArrayResize(bytes,size);if(size>0) FileReadArray(events,bytes,0,size);FileClose(events);
      FileWriteInteger(output,CaseId);FileWriteInteger(output,size);if(size>0) FileWriteArray(output,bytes,0,size);
   }
   FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
