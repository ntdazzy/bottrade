"""Generate full-news SDK recorders without executing the old generator."""
import ast,importlib.util
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
parsed=ast.parse((ROOT/'cong-cu/tao-bo-kiem-nfp-toan-nhanh.py').read_text());values={}
for node in parsed.body:
    if isinstance(node,ast.Assign) and len(node.targets)==1 and isinstance(node.targets[0],ast.Name) and node.targets[0].id in ['T','protos']:values[node.targets[0].id]=ast.literal_eval(node.value)
s=importlib.util.spec_from_file_location('news_fields',ROOT/'cong-cu/kiem-chuoi-tin-bot-1-3.py');data=importlib.util.module_from_spec(s);s.loader.exec_module(data)
template=values['T'].replace('BotNNfpFilter.mqh','BotNNewsFilterPipeline.mqh')
template=template.replace('#define CalendarEventByCurrency MockEvents','#define CalendarEventByCurrency MockEvents\n#define CalendarEventByCountry MockCountry')
template=template.replace('BotNNfpFilterSettings Settings;BotNNfpFilterState State;BotNNewsEvents Events;BotNNfpExecution Execution;', 'BotNNfpFilterSettings Settings;BotNNfpFilterState State;BotNNewsEvents Events;BotNNfpExecution Execution;\nBotNReleaseFilterSettings InterestSettings,CpiSettings;BotNReleaseFilterState InterestState,CpiState;BotNNewsSelection Selection;\nlong Extra[18];bool RecordFinal=false,NewsBlocked=false;')
extra='''
   Word(InterestSettings.enabled);Word(InterestSettings.delete_pending);Word(InterestSettings.close_positions);Word((ulong)(long)InterestSettings.before_minutes);Word((ulong)(long)InterestSettings.after_minutes);Word(InterestState.notice);Word(InterestState.blocked);Word((ulong)InterestState.last_query);
   Word(CpiSettings.enabled);Word(CpiSettings.delete_pending);Word(CpiSettings.close_positions);Word((ulong)(long)CpiSettings.before_minutes);Word((ulong)(long)CpiSettings.after_minutes);Word(CpiState.notice);Word(CpiState.blocked);Word((ulong)CpiState.last_query);
   Word((ulong)Selection.block_time);Text(Selection.label);'''
marker='   Word(State.initialization_notice);Word(State.notice);Word(State.blocked);Word((ulong)State.last_query);Word((ulong)State.utc_reference);'
assert marker in template;template=template.replace(marker,marker+extra)
template=template.replace('Word((ulong)(long)Execution.options.log_level);Word((ulong)(long)Execution.options.margin_mode);Word(error);','Word((ulong)(long)Execution.options.log_level);Word((ulong)(long)Execution.options.margin_mode);Word(error);\n   if(RecordFinal) Word((ulong)NewsBlocked);')
a=template.index('int MockEvents(');z=template.index('int MockValues(',a)
template=template[:a]+'''int MockEvents(const string currency,MqlCalendarEvent &events[])
{
   Begin();int status=(int)P[p_calendar_status],count=status>0 ? 2 : 0;ArrayResize(events,count);
   if(count>0)
   {
      ZeroMemory(events[0]);ZeroMemory(events[1]);events[0].id=status==3 ? 0 : 77;events[1].id=status==3 ? 0 : 88;
      events[0].name=status==4 ? NULL : (status==2 ? "Other" : "Nonfarm Payrolls");
      events[1].name=status==4 ? NULL : (status==2 ? "Other" : "CPI (YoY)");
   }
   int reply=status<0 ? -1 : count;End(11,(ulong)(long)reply,(ulong)count,0,0,currency);return reply;
}
int MockCountry(const string country,MqlCalendarEvent &events[])
{
   Begin();int status=(int)P[p_calendar_status],count=status>0 ? 1 : 0;ArrayResize(events,count);
   if(count>0) { ZeroMemory(events[0]);events[0].id=status==3 ? 0 : 99;events[0].name=status==4 ? NULL : (status==2 ? "Other" : "Fed Interest Rate Decision"); }
   int reply=status<0 ? -1 : count;End(31,(ulong)(long)reply,(ulong)count,0,0,country);return reply;
}
'''+template[z:]
template=template.replace('values[0].time=(datetime)P[p_release];','values[0].time=(datetime)(event_id==99 || event_id==0x3212255e ? Extra[16] : (event_id==88 || event_id==0x3211d735 ? Extra[17] : P[p_release]));')
template=template.replace('for(int i=0;i<300;i++) History[i]=FileReadLong(file);','for(int i=0;i<300;i++) History[i]=FileReadLong(file);\n      for(int i=0;i<18;i++) Extra[i]=FileReadLong(file);')
template=template.replace('ZeroMemory(Settings);ZeroMemory(State);ZeroMemory(Events);ZeroMemory(Execution);','ZeroMemory(Settings);ZeroMemory(State);ZeroMemory(Events);ZeroMemory(Execution);ZeroMemory(InterestSettings);ZeroMemory(InterestState);ZeroMemory(CpiSettings);ZeroMemory(CpiState);ZeroMemory(Selection);\n      InterestSettings.enabled=(uchar)Extra[0];InterestSettings.delete_pending=(uchar)Extra[1];InterestSettings.close_positions=(uchar)Extra[2];InterestSettings.before_minutes=(int)Extra[3];InterestSettings.after_minutes=(int)Extra[4];InterestState.notice=(uchar)Extra[5];InterestState.blocked=(uchar)Extra[6];InterestState.last_query=Extra[7];\n      CpiSettings.enabled=(uchar)Extra[8];CpiSettings.delete_pending=(uchar)Extra[9];CpiSettings.close_positions=(uchar)Extra[10];CpiSettings.before_minutes=(int)Extra[11];CpiSettings.after_minutes=(int)Extra[12];CpiState.notice=(uchar)Extra[13];CpiState.blocked=(uchar)Extra[14];CpiState.last_query=Extra[15];')
template=template.replace('BotNProcessNfpFilter(Settings,State,Events,Cached,History,Execution);','NewsBlocked=BotNProcessNewsFilters(Settings,State,InterestSettings,InterestState,CpiSettings,CpiState,Events,Cached,History,History,History,Execution,Selection);')
template=template.replace('EndErrorOverride=-1;NewsBlocked=','RecordFinal=false;EndErrorOverride=-1;NewsBlocked=').replace('TapeFile=output;EndErrorOverride=final_error;Begin();','TapeFile=output;EndErrorOverride=final_error;RecordFinal=true;Begin();')
template=template.replace('botN-nfp-filter','botN-news-pipeline').replace('NFP_FILTER_CASE','NEWS_PIPELINE_CASE')
protos=values['protos']+'\nint MockCountry(const string country,MqlCalendarEvent &events[]);'
for bot in [1,3]:
    fields=[]
    for key,schema in data.base.SCHEMAS.items():
        for f in schema['fields']:
            n=f'Execution.trade.{key}.{f["name"]}';fields.append('   '+(f'Text({n});' if f['kind']=='s' else f'Word(Bits({n}));' if f['kind']=='d' else f'Word((ulong){n});'))
    undef='\n'.join('#undef '+line.split()[1] for line in template.splitlines() if line.startswith('#define '))
    source=template.replace('PROTOTYPES',protos).replace('UNDEFS',undef).replace('ENUM_FIELDS',','.join('p_'+n for n in data.base.FIELDS)).replace('FIELD_COUNT',str(len(data.base.FIELDS))).replace('TRADE_STATE','\n'.join(fields))
    split=source.index('enum Parameter');head,tail=source[:split],source[split:];tail=tail.replace('const int flags=TIME_DATE|TIME_MINUTES','const int flags').replace("const int length=0,const ushort fill=' '","const int length,const ushort fill").replace('const datetime to=0','const datetime to')
    source=(head+tail).replace('BOTN',f'BOT{bot}').replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}')
    (ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}NewsPipelineCheck.mq5').write_text(source,encoding='utf-8',newline='\n')
