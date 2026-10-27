"""Generate an isolated MT5 recorder for the complete bot1 entry loop."""
import importlib.util
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('entry_loop_schema',ROOT/'cong-cu/kiem-vong-phat-sinh-lenh-bot-1.py')
data=importlib.util.module_from_spec(spec);spec.loader.exec_module(data)
template=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1EvaluationEntryLevelsCheck.mq5').read_text()
protos='''void MockPrint(const string a,const string b,const string c,const string d,const string e,const string f);
double MockAccountDouble(const ENUM_ACCOUNT_INFO_DOUBLE property);
datetime MockGlobalSet(const string name,const double value);
string MockAccountString(const ENUM_ACCOUNT_INFO_STRING property);
long MockAccountInteger(const ENUM_ACCOUNT_INFO_INTEGER property);
bool MockMargin(const ENUM_ORDER_TYPE type,const string symbol,const double volume,const double price,double &margin);
'''
template=template.replace('int SourceError();',protos+'int SourceError();',1)
template=template.replace('#define MQLInfoInteger MockInfo','''#define AccountInfoDouble MockAccountDouble
#define GlobalVariableSet MockGlobalSet
#define AccountInfoString MockAccountString
#define AccountInfoInteger MockAccountInteger
#define OrderCalcMargin MockMargin
#define MQLInfoInteger MockInfo''')
include='#include "../../Include/bot-cua-toi-1/Bot1EvaluationEntryLevels.mqh"'
template=template.replace(include,include+'\n#include "../../Include/bot-cua-toi-1/Bot1EntryLoop.mqh"')
template=template.replace('#undef MQLInfoInteger','''#undef AccountInfoDouble
#undef GlobalVariableSet
#undef AccountInfoString
#undef AccountInfoInteger
#undef OrderCalcMargin
#undef MQLInfoInteger''')
template=template.replace('int TimeCalls=0,HighCalls=0,LowCalls=0,DigitCalls=0;','''int TimeCalls=0,HighCalls=0,LowCalls=0,DigitCalls=0;
Bot1EntryLoopSettings LoopSettings;Bot1EntryLoopState LoopState;Bot1VolumeSettings VolumeSettings;Bot1VolumeState VolumeState;
long LoopData[23];double Volumes[8];long VolumeLastCheck=0,VolumeLastDeal=0;string VolumePeak="peak",VolumeTime="time",VolumeSuffix="";''')
fields=[]
for name,kind,_ in data.LOOP:
    target='LoopSettings.'+name;fields.append('   '+('Word(Bits('+target+'));' if kind=='d' else 'Word((ulong)(long)'+target+');'))
for name,_ in data.STATES:fields.append('   Word(Bits(LoopState.'+name+'));')
for struct,entries in [('VolumeSettings',data.VOLUME),('VolumeState',data.VS)]:
    for name,kind,_,_ in entries:
        target=struct+'.'+name;fields.append('   '+('Word(Bits('+target+'));' if kind=='d' else 'Word((ulong)(long)'+target+');'))
fields.append('   for(int i=0;i<8;i++) Word(Bits(Volumes[i]));')
template=template.replace('   if(RecordFinal) Word((ulong)Decision);','\n'.join(fields)+'\n   if(RecordFinal) Word((ulong)Decision);')
assign=[]
for i,(name,kind,_) in enumerate(data.LOOP):
    cast='Number((ulong)LoopData[%d])'%i if kind=='d' else '('+('uchar' if kind=='B' else 'uint' if kind=='I' else 'ENUM_TIMEFRAMES' if name=='confirmation_frame' else 'int')+')LoopData[%d]'%i
    assign.append('      LoopSettings.'+name+'='+cast+';')
for struct,entries in [('VolumeSettings',data.VOLUME),('VolumeState',data.VS)]:
    for name,kind,_,value in entries:assign.append('      '+struct+'.'+name+'='+('Number((ulong)LoopData[19])' if name=='max_lots' else str(value).lower())+';')
needle='for(int i=0;i<16;i++) LowValues[i]=FileReadDouble(file);'
assert needle in template
template=template.replace(needle,needle+'\n      for(int i=0;i<23;i++) LoopData[i]=FileReadLong(file);ZeroMemory(LoopSettings);ZeroMemory(LoopState);ZeroMemory(VolumeSettings);ZeroMemory(VolumeState);\n'+'\n'.join(assign)+'\n      ArrayInitialize(Volumes,.1);VolumeLastCheck=0;VolumeLastDeal=0;VolumePeak="peak";VolumeTime="time";VolumeSuffix="";')
old='Decision=Bot1EvaluateThroughEntryLevels(Settings,State,InterestSettings,InterestState,CpiSettings,CpiState,Events,Cached,History,History,History,Execution,Selection,Friday,FridayClosed,SpreadSettings,SpreadUnit,CurrentSpread,Queue,Restore,PendingEnabled,MaximumPending,LevelSettings,CallerIndex,CurrentIndex,BarTimes,CachedUpper,CachedLower);'
assert old in template
template=template.replace(old,'Decision=BOT1_LEVEL_NEW_BAR;Bot1RunEntryLoop(MaximumPending,LoopSettings,LoopState,VolumeSettings,VolumeState,false,VolumePeak,VolumeTime,VolumeLastCheck,VolumeLastDeal,VolumeSuffix,SpreadUnit,CurrentIndex,Volumes,Restore,Execution,Queue);')
template=template.replace('bot1-entry-level-cache','bot1-entry-loop').replace('ENTRY_LEVEL_CASE','ENTRY_LOOP_CASE')
start=template.index('long MockOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)\n{');end=template.index('\nstring MockOrderString',start)
template=template[:start]+'''long MockOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{
   Begin();long value=property==ORDER_MAGIC ? (MagicReads++==0 ? FridayData[6] : WideData[12]) : (property==(ENUM_ORDER_PROPERTY_INTEGER)1 ? LoopData[20] : (OrderTypeReads++==0 ? FridayData[8] : FridayData[9]));
   ServiceEffect(17,NULL,(long)property);WideEffect(17,NULL,(long)property);End(17,(ulong)property,(ulong)value);return value;
}
'''+template[end:]
template=template.replace('property==POSITION_MAGIC ? 43 :','property==POSITION_MAGIC ? LoopData[21] :')
old='double value=property==SYMBOL_POINT ? .01 : (property==SYMBOL_BID ? 100. : 101.);'
new='double value=property==SYMBOL_TRADE_TICK_VALUE ? 1. : (property==SYMBOL_VOLUME_MIN || property==SYMBOL_VOLUME_STEP || property==SYMBOL_POINT ? .01 : (property==SYMBOL_VOLUME_MAX ? 100. : (property==SYMBOL_BID ? 100. : 101.)));'
assert old in template;template=template.replace(old,new)
functions='''void MockPrint(const string a,const string b,const string c,const string d,const string e,const string f)
{
   Begin();uint error=SourceError();int size=8+2*(StringLen(e)+StringLen(f));
   Header(10,6,0,0,0,a,b,c,d,size);Text(e);Text(f);FileWriteInteger(TapeFile,(int)error);
}
double MockAccountDouble(const ENUM_ACCOUNT_INFO_DOUBLE property)
{ Begin();double value=property==ACCOUNT_EQUITY ? 11000. : 10000.;End(38,(ulong)property,Bits(value));return value; }
datetime MockGlobalSet(const string name,const double value)
{ Begin();End(39,Bits(value),0,0,0,name);return 0; }
string MockAccountString(const ENUM_ACCOUNT_INFO_STRING property)
{ Begin();string value="USD";End(40,(ulong)property,0,0,0,value);return value; }
long MockAccountInteger(const ENUM_ACCOUNT_INFO_INTEGER property)
{ Begin();long value=LoopData[22];End(41,(ulong)property,(ulong)value);return value; }
bool MockMargin(const ENUM_ORDER_TYPE type,const string symbol,const double volume,const double price,double &margin)
{
   Begin();margin=100.;uint error=SourceError();Header(42,(ulong)type,Bits(volume),Bits(price),1,symbol,NULL,NULL,NULL,8);
   Word(Bits(margin));FileWriteInteger(TapeFile,(int)error);return true;
}
'''
template=template.replace('int OnStart()',functions+'int OnStart()')
start=template.index('void Snapshot()');end=template.index('void Begin()',start)
old_snapshot=template[start:end];first=old_snapshot.index('   Word((ulong)(long)Execution.strategy_magic)');last=old_snapshot.index('Word(error);',first)+len('Word(error);')
execution_snapshot=old_snapshot[first:last]
body=['void Snapshot()','{','   uint error=EndErrorOverride>=0 ? (uint)EndErrorOverride : SourceError();',execution_snapshot,'   Word((ulong)(long)MaximumPending);']+fields[:-1]+[fields[-1],
   '   Word(Bits(SpreadUnit));Word(CurrentIndex);',
   '   Word(Bits(Restore.sl_distance));Word(Bits(Restore.tp_distance));Word((ulong)Restore.expiration_base);',
   '   Word(Restore.virtual_expiration);Text(Restore.comment);Word(Queue.error_count);',
   '   for(int row=0;row<100;row++) for(int col=0;col<2;col++) Word(Bits(Queue.results[row][col]));',
   '   if(RecordFinal) Word((ulong)Decision);','}']
template=template[:start]+'\n'.join(body)+'\n'+template[end:]
target=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1EntryLoopCheck.mq5'
target.write_text('\n'.join(line.rstrip() for line in template.splitlines())+'\n',encoding='utf-8',newline='\n')
