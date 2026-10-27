#property strict
input string CheckRun="";
int MockInfo(const ENUM_MQL_INFO_INTEGER property);
int MockTotal();
ulong MockTicket(const int index);
string MockPositionString(const ENUM_POSITION_PROPERTY_STRING property);
long MockPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property);
bool MockSelect(const ulong ticket);
double MockPositionDouble(const ENUM_POSITION_PROPERTY_DOUBLE property);
string MockDoubleText(const double value,const int digits);
string MockIntegerText(const long value,const int width,const ushort fill);
bool MockObjectText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value);
datetime MockServer();
void MockSetError(const ushort code);
string Bot3PanelDoubleText(const double value);
string Bot3PanelIntegerText(const int value);
string Bot3PanelTimeText(const datetime value);
#define BOT3_PANEL_TEXT_CASTS_MQH
#define MQLInfoInteger MockInfo
#define PositionsTotal MockTotal
#define PositionGetTicket MockTicket
#define PositionGetString MockPositionString
#define PositionGetInteger MockPositionInteger
#define PositionSelectByTicket MockSelect
#define PositionGetDouble MockPositionDouble
#define DoubleToString MockDoubleText
#define IntegerToString MockIntegerText
#define ObjectSetString MockObjectText
#define TimeTradeServer MockServer
#define SetUserError MockSetError
#include "../../Include/bot-cua-toi-3/Bot3OpenStatusPanel.mqh"
#undef MQLInfoInteger
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetString
#undef PositionGetInteger
#undef PositionSelectByTicket
#undef PositionGetDouble
#undef DoubleToString
#undef IntegerToString
#undef ObjectSetString
#undef TimeTradeServer
#undef SetUserError
uchar PanelShow;
uchar PanelTester;
int PanelSeed;
string PanelSymbol;
double PanelBalance;
uint PanelMode;
double PanelStrategyRisk;
int PanelFrequency;
double PanelManual;
double PanelDD;
Bot3NewsEvents Events;Bot3NewsWindows Windows;Bot3NewsSelection Selection;
ulong LastTicket;
int LogicalError,EventFile,CaseId,ErrorMode,InfoReply[2],ApiCounts[13];
long ServerReply;
struct PositionReply { ulong ticket;double profit,swap;int selected;string symbol;long magics[],types[]; };
PositionReply Positions[];
int Totals[],SelectedPosition,MagicCalls,TypeCalls;
struct Effect { int api,n,index;ulong word;string text; };
Effect Effects[];
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
   int size=168+4+2*StringLen(PanelSymbol)+4+2*StringLen(Selection.label);
   FileWriteInteger(file,size);
   Word(file,(ulong)(long)PanelShow);
   Word(file,(ulong)(long)PanelTester);
   Word(file,(ulong)(long)PanelSeed);
   WriteText(file,PanelSymbol);
   Word(file,Bits(PanelBalance));
   Word(file,(ulong)(long)PanelMode);
   Word(file,Bits(PanelStrategyRisk));
   Word(file,(ulong)(long)PanelFrequency);
   Word(file,Bits(PanelManual));
   Word(file,Bits(PanelDD));
   Word(file,(ulong)(long)Windows.nfp_enabled);
   Word(file,(ulong)(long)Windows.interest_enabled);
   Word(file,(ulong)(long)Windows.cpi_enabled);
   Word(file,(ulong)(long)Windows.nfp_after);
   Word(file,(ulong)(long)Windows.interest_after);
   Word(file,(ulong)(long)Windows.cpi_after);
   Word(file,(ulong)(long)Events.nfp);
   Word(file,(ulong)(long)Events.interest);
   Word(file,(ulong)(long)Events.cpi);
   Word(file,(ulong)(long)Selection.block_time);
   WriteText(file,Selection.label);
   Word(file,(ulong)(long)LastTicket);
   Word(file,(ulong)LogicalError);
}
void ApplyEffects(const int api)
{
   for(int i=0;i<ArraySize(Effects);i++)
      if(Effects[i].api==api && Effects[i].n==ApiCounts[api])
      {
         switch(Effects[i].index)
         {
         case 0: PanelShow=(uchar)Effects[i].word;break;
         case 1: PanelTester=(uchar)Effects[i].word;break;
         case 2: PanelSeed=(int)Effects[i].word;break;
         case 3: PanelSymbol=Effects[i].text;break;
         case 4: PanelBalance=Number(Effects[i].word);break;
         case 5: PanelMode=(uint)Effects[i].word;break;
         case 6: PanelStrategyRisk=Number(Effects[i].word);break;
         case 7: PanelFrequency=(int)Effects[i].word;break;
         case 8: PanelManual=Number(Effects[i].word);break;
         case 9: PanelDD=Number(Effects[i].word);break;
         case 10: Windows.nfp_enabled=(uchar)Effects[i].word;break;
         case 11: Windows.interest_enabled=(uchar)Effects[i].word;break;
         case 12: Windows.cpi_enabled=(uchar)Effects[i].word;break;
         case 13: Windows.nfp_after=(int)Effects[i].word;break;
         case 14: Windows.interest_after=(int)Effects[i].word;break;
         case 15: Windows.cpi_after=(int)Effects[i].word;break;
         case 16: Events.nfp=(long)Effects[i].word;break;
         case 17: Events.interest=(long)Effects[i].word;break;
         case 18: Events.cpi=(long)Effects[i].word;break;
         case 19: Selection.block_time=(long)Effects[i].word;break;
         case 20: Selection.label=Effects[i].text;break;
         case 21: LastTicket=(ulong)Effects[i].word;break;
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
{
   int reply=InfoReply[MathMin(ApiCounts[1],1)];Record(1,(ulong)property,0,0,0,NULL,NULL,NULL,NULL,(ulong)(long)reply);return reply;
}
int MockTotal()
{
   int reply=Totals[MathMin(ApiCounts[2],ArraySize(Totals)-1)];Record(2,0,0,0,0,NULL,NULL,NULL,NULL,(ulong)(long)reply);return reply;
}
ulong MockTicket(const int index)
{
   SelectedPosition=index;MagicCalls=0;TypeCalls=0;ulong reply=index>=0 && index<ArraySize(Positions) ? Positions[index].ticket : 0;
   Record(3,(ulong)(long)index,0,0,0,NULL,NULL,NULL,NULL,reply);return reply;
}
string MockPositionString(const ENUM_POSITION_PROPERTY_STRING property)
{
   string reply=Positions[SelectedPosition].symbol;Record(4,(ulong)property,0,0,0,reply,NULL,NULL,NULL,0);return reply;
}
long MockPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   long reply;
   if((int)property==12) { reply=Positions[SelectedPosition].magics[MathMin(MagicCalls,ArraySize(Positions[SelectedPosition].magics)-1)];MagicCalls++; }
   else { reply=Positions[SelectedPosition].types[MathMin(TypeCalls,ArraySize(Positions[SelectedPosition].types)-1)];TypeCalls++; }
   Record(5,(ulong)property,0,0,0,NULL,NULL,NULL,NULL,(ulong)reply);return reply;
}
bool MockSelect(const ulong ticket)
{
   bool reply=Positions[SelectedPosition].selected!=0;Record(6,ticket,0,0,0,NULL,NULL,NULL,NULL,(ulong)reply);return reply;
}
double MockPositionDouble(const ENUM_POSITION_PROPERTY_DOUBLE property)
{
   double reply=(int)property==10 ? Positions[SelectedPosition].profit : Positions[SelectedPosition].swap;
   Record(7,(ulong)property,0,0,0,NULL,NULL,NULL,NULL,Bits(reply));return reply;
}
string MockDoubleText(const double value,const int digits)
{
   string reply=DoubleToString(value,digits);Record(8,Bits(value),(ulong)(uint)digits,0,0,reply,NULL,NULL,NULL,0);return reply;
}
string MockIntegerText(const long value,const int width,const ushort fill)
{
   string reply=IntegerToString(value,width,fill);Record(9,(ulong)value,(ulong)(uint)width,(ulong)fill,0,reply,NULL,NULL,NULL,0);return reply;
}
bool MockObjectText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value)
{
   bool reply=(CaseId+ApiCounts[10])%2!=0;Record(10,(ulong)chart,(ulong)property,0,0,name,value,NULL,NULL,(ulong)reply);return reply;
}
datetime MockServer() { long reply=ServerReply;Record(11,0,0,0,0,NULL,NULL,NULL,NULL,(ulong)reply);return (datetime)reply; }
void MockSetError(const ushort code) { LogicalError=65536+(int)code; }
void SeedError() { ResetLastError();if(LogicalError>=65536) SetUserError((ushort)(LogicalError-65536)); }
string Bot3PanelDoubleText(const double value)
{
   SeedError();string reply=(string)value;int error=GetLastError();Record(12,Bits(value),0x58,0,0,reply,NULL,NULL,NULL,0,error);return reply;
}
string Bot3PanelIntegerText(const int value)
{
   SeedError();string reply=(string)value;int error=GetLastError();Record(12,(ulong)(long)value,0x52,0,0,reply,NULL,NULL,NULL,0,error);return reply;
}
string Bot3PanelTimeText(const datetime value)
{
   SeedError();string reply=(string)value;int error=GetLastError();Record(12,(ulong)value,0x54,0,0,reply,NULL,NULL,NULL,0,error);return reply;
}
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot3-open-panel\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4f535031 || version!=1 || count<1) return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE) return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int row=0;row<count;row++)
   {
      CaseId=FileReadInteger(file);
      PanelShow=(uchar)(ulong)FileReadLong(file);
      PanelTester=(uchar)(ulong)FileReadLong(file);
      PanelSeed=(int)(ulong)FileReadLong(file);
      PanelSymbol=ReadText(file);
      PanelBalance=Number((ulong)FileReadLong(file));
      PanelMode=(uint)(ulong)FileReadLong(file);
      PanelStrategyRisk=Number((ulong)FileReadLong(file));
      PanelFrequency=(int)(ulong)FileReadLong(file);
      PanelManual=Number((ulong)FileReadLong(file));
      PanelDD=Number((ulong)FileReadLong(file));
      Windows.nfp_enabled=(uchar)(ulong)FileReadLong(file);
      Windows.interest_enabled=(uchar)(ulong)FileReadLong(file);
      Windows.cpi_enabled=(uchar)(ulong)FileReadLong(file);
      Windows.nfp_after=(int)(ulong)FileReadLong(file);
      Windows.interest_after=(int)(ulong)FileReadLong(file);
      Windows.cpi_after=(int)(ulong)FileReadLong(file);
      Events.nfp=(long)(ulong)FileReadLong(file);
      Events.interest=(long)(ulong)FileReadLong(file);
      Events.cpi=(long)(ulong)FileReadLong(file);
      Selection.block_time=(long)(ulong)FileReadLong(file);
      Selection.label=ReadText(file);
      LastTicket=(ulong)(ulong)FileReadLong(file);
      InfoReply[0]=FileReadInteger(file);InfoReply[1]=FileReadInteger(file);ErrorMode=FileReadInteger(file);ServerReply=FileReadLong(file);
      int positions=FileReadInteger(file);ArrayResize(Positions,positions);
      for(int i=0;i<positions;i++)
      {
         Positions[i].ticket=(ulong)FileReadLong(file);Positions[i].profit=FileReadDouble(file);Positions[i].swap=FileReadDouble(file);
         Positions[i].selected=FileReadInteger(file);Positions[i].symbol=ReadText(file);
         int n=FileReadInteger(file);ArrayResize(Positions[i].magics,n);for(int j=0;j<n;j++) Positions[i].magics[j]=FileReadLong(file);
         n=FileReadInteger(file);ArrayResize(Positions[i].types,n);for(int j=0;j<n;j++) Positions[i].types[j]=FileReadLong(file);
      }
      int totals=FileReadInteger(file);ArrayResize(Totals,totals);for(int i=0;i<totals;i++) Totals[i]=FileReadInteger(file);
      int effects=FileReadInteger(file);ArrayResize(Effects,effects);
      for(int i=0;i<effects;i++)
      {
         Effects[i].api=FileReadInteger(file);Effects[i].n=FileReadInteger(file);Effects[i].index=FileReadInteger(file);
         if(Effects[i].index==3 || Effects[i].index==20) Effects[i].text=ReadText(file);else Effects[i].word=(ulong)FileReadLong(file);
      }
      ArrayInitialize(ApiCounts,0);LogicalError=0;SelectedPosition=-1;MagicCalls=0;TypeCalls=0;
      string name=folder+"events-"+IntegerToString(CaseId)+".bin";EventFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(EventFile==INVALID_HANDLE) return 5;
      Bot3UpdateOpenStatusPanel(PanelShow,PanelTester,PanelSeed,PanelSymbol,PanelBalance,PanelFrequency,PanelMode,PanelManual,PanelDD,PanelStrategyRisk,Events,Windows,Selection,LastTicket);
      State(EventFile);FileClose(EventFile);
      int events=FileOpen(name,FILE_READ|FILE_BIN);if(events==INVALID_HANDLE) return 6;
      int size=(int)FileSize(events);uchar bytes[];ArrayResize(bytes,size);if(size>0) FileReadArray(events,bytes,0,size);FileClose(events);
      FileWriteInteger(output,CaseId);FileWriteInteger(output,size);if(size>0) FileWriteArray(output,bytes,0,size);
   }
   FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
