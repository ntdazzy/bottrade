"""Extend joined evaluator recorders through closed history and hourly cleanup."""
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
for bot in [1,3]:
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    source=(folder/f'Bot{bot}EvaluationCheck.mq5').read_text()
    prototypes='''bool MockHistorySelect(const datetime from,const datetime to);
int MockHistoryTotal();ulong MockHistoryTicket(const int index);
long MockHistoryInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property);
string MockHistoryString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property);
double MockHistoryDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property);
'''
    source=source.replace('int SourceError();',prototypes+'int SourceError();',1)
    names={'HistorySelect':'MockHistorySelect','HistoryDealsTotal':'MockHistoryTotal','HistoryDealGetTicket':'MockHistoryTicket','HistoryDealGetInteger':'MockHistoryInteger','HistoryDealGetString':'MockHistoryString','HistoryDealGetDouble':'MockHistoryDouble'}
    source=source.replace('#define MQLInfoInteger MockInfo','\n'.join('#define '+a+' '+b for a,b in names.items())+'\n#define MQLInfoInteger MockInfo',1)
    source=source.replace('#undef MQLInfoInteger','\n'.join('#undef '+a for a in names)+'\n#undef MQLInfoInteger',1)
    source=source.replace(f'Bot{bot}Evaluation.mqh',f'Bot{bot}EvaluationWithDisplay.mqh')
    source=source.replace('int TapeFile,EndErrorOverride=-1;',f'Bot{bot}DisplayState Display;int HistorySelected=-1;\nint TapeFile,EndErrorOverride=-1;',1)
    source=source.replace('   if(RecordFinal) Word((ulong)Decision);','   Word(Bits(Display.wins));Word(Bits(Display.losses));Word((ulong)(long)Display.last_hour);\n   if(RecordFinal) Word((ulong)Decision);',1)
    source=source.replace('ZeroMemory(Prefix);ZeroMemory(PrefixState);ManagerTimeCalls=0;','ZeroMemory(Prefix);ZeroMemory(PrefixState);ZeroMemory(Display);HistorySelected=-1;ManagerTimeCalls=0;',1)
    functions='''bool MockHistorySelect(const datetime from,const datetime to)
{ Begin();End(47,(ulong)from,(ulong)to,1);return true; }
int MockHistoryTotal() { Begin();End(48,2);return 2; }
ulong MockHistoryTicket(const int index)
{ Begin();HistorySelected=index;ulong reply=(ulong)(101+index);End(49,(ulong)(uint)index,reply);return reply; }
long MockHistoryInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property)
{ Begin();long reply=(long)Execution.magic_base+1;End(50,ticket,(ulong)property,(ulong)reply);return reply; }
string MockHistoryString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property)
{ Begin();string reply="XAUUSD";End(51,ticket,(ulong)property,0,0,reply);return reply; }
double MockHistoryDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property)
{ Begin();double reply=(int)property==9 ? (HistorySelected==0 ? 1.25 : -2.5) : ((int)property==7 ? -.1 : -.05);End(52,ticket,(ulong)property,Bits(reply));return reply; }
'''
    source=source.replace('int OnStart()\n{',functions+'int OnStart()\n{',1)
    source=source.replace(f'Decision=Bot{bot}Evaluate(',f'Decision=Bot{bot}EvaluateWithDisplay(',1).replace(',Prefix,PrefixState);int final_error=',',Prefix,PrefixState,Display);int final_error=',1)
    source=source.replace(f'bot{bot}-evaluation\\\\',f'bot{bot}-evaluation-display\\\\')
    (folder/f'Bot{bot}EvaluationWithDisplayCheck.mq5').write_text(source,encoding='utf-8',newline='\n')
