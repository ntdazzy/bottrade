"""Generate the two isolated MT5 open-status recorders and API compile scripts."""
import importlib.util
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
s=importlib.util.spec_from_file_location('panel_schema',ROOT/'cong-cu/kiem-bang-thong-tin-mo-bot-1-3.py')
data=importlib.util.module_from_spec(s);s.loader.exec_module(data)
TEMPLATE=r'''#property strict
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
string Bot@N@PanelDoubleText(const double value);
string Bot@N@PanelIntegerText(const int value);
string Bot@N@PanelTimeText(const datetime value);
#define BOT@N@_PANEL_TEXT_CASTS_MQH
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
#include "../../Include/bot-cua-toi-@N@/Bot@N@OpenStatusPanel.mqh"
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
@GLOBALS@
Bot@N@NewsEvents Events;Bot@N@NewsWindows Windows;Bot@N@NewsSelection Selection;
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
   int size=@STATE_SIZE@;
   FileWriteInteger(file,size);
@STATE@
   Word(file,(ulong)LogicalError);
}
void ApplyEffects(const int api)
{
   for(int i=0;i<ArraySize(Effects);i++)
      if(Effects[i].api==api && Effects[i].n==ApiCounts[api])
      {
         switch(Effects[i].index)
         {
@EFFECTS@
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
string Bot@N@PanelDoubleText(const double value)
{
   SeedError();string reply=(string)value;int error=GetLastError();Record(12,Bits(value),0x58,0,0,reply,NULL,NULL,NULL,0,error);return reply;
}
string Bot@N@PanelIntegerText(const int value)
{
   SeedError();string reply=(string)value;int error=GetLastError();Record(12,(ulong)(long)value,0x52,0,0,reply,NULL,NULL,NULL,0,error);return reply;
}
string Bot@N@PanelTimeText(const datetime value)
{
   SeedError();string reply=(string)value;int error=GetLastError();Record(12,(ulong)value,0x54,0,0,reply,NULL,NULL,NULL,0,error);return reply;
}
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="bot@N@-open-panel\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4f535031 || version!=1 || count<1) return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE) return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int row=0;row<count;row++)
   {
      CaseId=FileReadInteger(file);
@LOAD@
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
         if(@STRING_EFFECT@) Effects[i].text=ReadText(file);else Effects[i].word=(ulong)FileReadLong(file);
      }
      ArrayInitialize(ApiCounts,0);LogicalError=0;SelectedPosition=-1;MagicCalls=0;TypeCalls=0;
      string name=folder+"events-"+IntegerToString(CaseId)+".bin";EventFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(EventFile==INVALID_HANDLE) return 5;
      @CALL@
      State(EventFile);FileClose(EventFile);
      int events=FileOpen(name,FILE_READ|FILE_BIN);if(events==INVALID_HANDLE) return 6;
      int size=(int)FileSize(events);uchar bytes[];ArrayResize(bytes,size);if(size>0) FileReadArray(events,bytes,0,size);FileClose(events);
      FileWriteInteger(output,CaseId);FileWriteInteger(output,size);if(size>0) FileWriteArray(output,bytes,0,size);
   }
   FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);
   if(status==INVALID_HANDLE) return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
def generate(bot):
    fs=data.fields(bot);types={'B':'uchar','i':'int','Q':'ulong','q':'long','d':'double','s':'string'}
    globals_='\n'.join(types[k]+' '+n+';' for n,k,_ in fs if '.' not in n and n!='LastTicket')
    def value(kind,expression):return expression if kind=='s' else 'Number('+expression+')' if kind=='d' else '('+types[kind]+')'+expression
    state='\n'.join('   '+('WriteText(file,'+n+');' if k=='s' else 'Word(file,'+('Bits('+n+')' if k=='d' else '(ulong)(long)'+n)+');') for n,k,_ in fs)
    size=str(8*(1+sum(k!='s' for _,k,_ in fs)))+''.join('+4+2*StringLen('+n+')' for n,k,_ in fs if k=='s')
    load='\n'.join('      '+n+'='+value(k,'ReadText(file)' if k=='s' else '(ulong)FileReadLong(file)')+';' for n,k,_ in fs)
    effects='\n'.join('         case '+str(i)+': '+n+'='+value(k,'Effects[i].text' if k=='s' else 'Effects[i].word')+';break;' for i,(n,k,_) in enumerate(fs))
    string_effect=' || '.join('Effects[i].index=='+str(i) for i,(_,k,_) in enumerate(fs) if k=='s')
    params='PanelShow,PanelTester,PanelSeed,PanelSymbol,PanelBalance,'+('PanelVolume,PanelMode,PanelTradeRisk,PanelStrategyRisk,PanelStep' if bot==1 else 'PanelFrequency,PanelMode,PanelManual,PanelDD,PanelStrategyRisk')+',Events,Windows,Selection,LastTicket'
    call='Bot'+str(bot)+'UpdateOpenStatusPanel('+params+');'
    source=TEMPLATE
    for old,new in {'@N@':str(bot),'@GLOBALS@':globals_,'@STATE_SIZE@':size,'@STATE@':state,'@EFFECTS@':effects,'@LOAD@':load,'@STRING_EFFECT@':string_effect,'@CALL@':call}.items():source=source.replace(old,new)
    home=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    (home/f'Bot{bot}OpenStatusPanelCheck.mq5').write_text(source,encoding='utf-8',newline='\n')
    api='#property strict\n#include "../../Include/bot-cua-toi-'+str(bot)+'/Bot'+str(bot)+'OpenStatusPanel.mqh"\n'+globals_+'\nBot'+str(bot)+'NewsEvents Events;Bot'+str(bot)+'NewsWindows Windows;Bot'+str(bot)+'NewsSelection Selection;ulong LastTicket;\nvoid OnStart() { '+call+' }\n'
    (home/f'Bot{bot}OpenStatusPanelAPICompile.mq5').write_text(api,encoding='utf-8',newline='\n')
if __name__=='__main__':
    for bot in [1,3]:generate(bot)
