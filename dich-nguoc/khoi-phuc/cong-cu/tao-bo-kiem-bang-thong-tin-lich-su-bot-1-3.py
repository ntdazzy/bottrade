"""Generate isolated recorders for the full closed-history status helper."""
import importlib.util
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
data=module('closed_schema',ROOT/'cong-cu/kiem-bang-thong-tin-lich-su-bot-1-3.py')
shared=module('closed_recorder_utilities',ROOT/'cong-cu/tao-bo-kiem-bang-thong-tin-mo-bot-1-3.py')
UTILITIES=shared.TEMPLATE[shared.TEMPLATE.index('union NumberWords'):shared.TEMPLATE.index('int MockInfo(const ENUM_MQL_INFO_INTEGER property)\n{')]
HEADER=r'''#property strict
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
#include "../../Include/bot-cua-toi-@N@/Bot@N@ClosedStatusPanel.mqh"
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
@GLOBALS@
int LogicalError,EventFile,CaseId,ErrorMode,InfoReply[2],ApiCounts[13],SelectReply,TotalReply,Selected,MagicCalls,ProfitCalls,CommissionCalls,SwapCalls;
struct DealReply { ulong ticket;string symbol;long magics[];double profit[],commission[],swap[]; };
DealReply Deals[];
struct Effect { int api,n,index;ulong word;string text; };Effect Effects[];
'''
MOCKS=r'''int MockInfo(const ENUM_MQL_INFO_INTEGER property)
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
   string folder="bot@N@-closed-panel\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4f535031 || version!=1 || count<1) return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE) return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int row=0;row<count;row++)
   {
      CaseId=FileReadInteger(file);
@LOAD@
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
      { Effects[i].api=FileReadInteger(file);Effects[i].n=FileReadInteger(file);Effects[i].index=FileReadInteger(file);if(@STRING_EFFECT@) Effects[i].text=ReadText(file);else Effects[i].word=(ulong)FileReadLong(file); }
      ArrayInitialize(ApiCounts,0);LogicalError=0;Selected=-1;
      string name=folder+"events-"+IntegerToString(CaseId)+".bin";EventFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(EventFile==INVALID_HANDLE) return 5;
      Bot@N@UpdateClosedStatusPanel(Show,Tester,Seed,PanelSymbol,Wins,Losses);State(EventFile);FileClose(EventFile);
      int events=FileOpen(name,FILE_READ|FILE_BIN);if(events==INVALID_HANDLE) return 6;
      int size=(int)FileSize(events);uchar bytes[];ArrayResize(bytes,size);if(size>0) FileReadArray(events,bytes,0,size);FileClose(events);
      FileWriteInteger(output,CaseId);FileWriteInteger(output,size);if(size>0) FileWriteArray(output,bytes,0,size);
   }
   FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
def generate(bot):
    fs=data.fields(bot);types={'B':'uchar','i':'int','d':'double','s':'string'}
    def value(k,x):return x if k=='s' else 'Number('+x+')' if k=='d' else '('+types[k]+')'+x
    globals_='\n'.join(types[k]+' '+n+';' for n,k,_ in fs)
    source=HEADER+UTILITIES+MOCKS
    replacements={'@N@':str(bot),'@GLOBALS@':globals_,
      '@STATE_SIZE@':str(8*(1+sum(k!='s' for _,k,_ in fs)))+''.join('+4+2*StringLen('+n+')' for n,k,_ in fs if k=='s'),
      '@STATE@':'\n'.join('   '+('WriteText(file,'+n+');' if k=='s' else 'Word(file,'+('Bits('+n+')' if k=='d' else '(ulong)(long)'+n)+');') for n,k,_ in fs),
      '@EFFECTS@':'\n'.join('         case '+str(i)+': '+n+'='+value(k,'Effects[i].text' if k=='s' else 'Effects[i].word')+';break;' for i,(n,k,_) in enumerate(fs)),
      '@LOAD@':'\n'.join('      '+n+'='+value(k,'ReadText(file)' if k=='s' else '(ulong)FileReadLong(file)')+';' for n,k,_ in fs),
      '@STRING_EFFECT@':' || '.join('Effects[i].index=='+str(i) for i,(_,k,_) in enumerate(fs) if k=='s')}
    for a,b in replacements.items():source=source.replace(a,b)
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    (folder/f'Bot{bot}ClosedStatusPanelCheck.mq5').write_text(source,encoding='utf-8',newline='\n')
    api=f'#property strict\n#include "../../Include/bot-cua-toi-{bot}/Bot{bot}ClosedStatusPanel.mqh"\n'+globals_+f'\nvoid OnStart() {{ Bot{bot}UpdateClosedStatusPanel(Show,Tester,Seed,PanelSymbol,Wins,Losses); }}\n'
    (folder/f'Bot{bot}ClosedStatusPanelAPICompile.mq5').write_text(api,encoding='utf-8',newline='\n')
if __name__=='__main__':
    for bot in [1,3]:generate(bot)
