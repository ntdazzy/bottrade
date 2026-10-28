"""Run all three original calendar bodies inside the continuous startup flow.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Only terminal calendar services supply event/value arrays; calendar selection,
fallback IDs, predicates and timeout handling execute in both implementations.
"""
import copy,hashlib,importlib.util,inspect,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def load(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
n=load('real_calendar_news','kiem-noi-tin-khoi-dong-bot-1.py');cal=load('real_calendar_contract','kiem-lich-ir-cpi-bot-1-3.py')
j,require,sha=n.j,n.require,n.sha
BASE_CASES=n.cases();BASE_RENDER=n.render;BASE_ENCODE=n.encode;BASE_IDENTITY=n.identity

def cases():
    rows=[];now=1790000000
    names=['Nonfarm Payrolls','Fed Interest Rate Decision','CPI (YoY)']
    def add(tag,kind=None,changes=None,flags=(1,1,1)):
        c=copy.deepcopy(BASE_CASES[0]);c.update(id=len(rows),tag=tag,effects=[])
        for field,flag in zip(['nfp','interest','cpi'],flags):c['values']['Windows.'+field+'_enabled']=flag;c['values']['Windows.'+field+'_after']=10
        c['calendars']=[dict(now=now,events=[[100+i,title]],values=[now-86400,now+200+i,now+100+i],event_return=1,value_return=3,event_series=0,value_series=0,value_error=-1) for i,title in enumerate(names)]
        if kind is not None:c['calendars'][kind].update(changes or {})
        c['news']['clocks']=[now]*3;rows.append(c);return c
    for mask in range(8):add('calendar-on-off',flags=[(mask>>i)&1 for i in range(3)])
    for kind in range(3):
        for name in [None,'','Other',names[kind],names[kind]+' 🚀',names[kind].lower(),'CPI ex Food','CPI ex Food (YoY)','Consumer Price Index']:
            for ident in [0,123,(1<<64)-1]:add('calendar-title-id',kind,dict(events=[[ident,name]]))
        for es,vs in [(0,0),(1,0),(0,1),(1,1)]:add('calendar-series',kind,dict(events=[[1,'Other'],[2,names[kind]]],event_return=2,event_series=es,value_series=vs))
        for count in [-1,0,1]:add('calendar-event-count',kind,dict(event_return=count))
        for count in [-1,0,1,3]:add('calendar-value-count',kind,dict(value_return=count))
        for values in [[],[now-86401],[now-86400],[now-86399],[0,-1,1],[now+300,now+100,now+200]]:add('calendar-time-window',kind,dict(values=values,value_return=len(values)))
        for error in [0,5401,65536+731]:add('calendar-value-error',kind,dict(value_error=error))
    for use,reset,manual in [(0,0,0.),(1,0,0.),(0,1,25000.)]:
        c=add('calendar-account-join');c['values'].update(UseEquity=use,ResetHighest=reset,ManualBalance=manual)
    for first in [0,1]:
        for title in [None,'','Other']:
            c=add('calendar-error-carries-to-next',first,dict(value_error=5401))
            c['calendars'][first+1]['events']=[[123,title]]
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',j.MAGIC,1,len(rows)))
    for c in rows:
        raw+=BASE_ENCODE([c])[12:]
        for q in c['calendars']:
            raw+=struct.pack('<7q',q['now'],q['event_return'],q['value_return'],q['event_series'],q['value_series'],q['value_error'],len(q['events']))
            for eventid,title in q['events']:raw+=struct.pack('<Q',eventid)+cal.base.text(title)
            raw+=struct.pack('<q',len(q['values']))+b''.join(struct.pack('<q',v) for v in q['values'])
    return bytes(raw)

DECL=r'''
int InjectedCalendarError=-1;int CalendarError();
int CalendarStringFind(const string value,const string needle,const int start=0);
#define GetLastError CalendarError
datetime RealCalendarServer();
int RealEventsCurrency(const string currency,MqlCalendarEvent &events[]);
int RealEventsCountry(const string country,MqlCalendarEvent &events[]);
int RealCalendarValues(const ulong event_id,MqlCalendarValue &values[],const datetime from,const datetime to=0);
void RealCalendarPrint(const string value);
#define TimeTradeServer RealCalendarServer
#define CalendarEventByCurrency RealEventsCurrency
#define CalendarEventByCountry RealEventsCountry
#define CalendarValueHistoryByEvent RealCalendarValues
#define Print RealCalendarPrint
#define StringFind CalendarStringFind
#include "../../Include/bot-cua-toi-1/Bot1NfpCalendar.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ReleaseCalendars.mqh"
#undef TimeTradeServer
#undef CalendarEventByCurrency
#undef CalendarEventByCountry
#undef CalendarValueHistoryByEvent
#undef Print
#undef StringFind
'''
GLOBALS='''
int CalendarKind=-1;
struct CalendarReply {long now;int event_return,value_return,event_series,value_series,value_error;ulong ids[];string names[];long times[];};
CalendarReply CalendarReplies[3];
'''
MOCKS=r'''
datetime RealCalendarServer(){Begin();long value=CalendarReplies[CalendarKind].now;End(61,(ulong)value,(ulong)CalendarKind);Effect(61);return (datetime)value;}
int FillCalendarEvents(const int api,const string query,MqlCalendarEvent &events[]){Begin();int count=ArraySize(CalendarReplies[CalendarKind].ids);End(api,(ulong)(long)CalendarReplies[CalendarKind].event_return,(ulong)count,(ulong)CalendarReplies[CalendarKind].event_series,(ulong)CalendarKind,query);ArrayResize(events,count);ArraySetAsSeries(events,false);for(int i=0;i<count;i++){ZeroMemory(events[i]);events[i].id=CalendarReplies[CalendarKind].ids[i];events[i].name=CalendarReplies[CalendarKind].names[i];}ArraySetAsSeries(events,CalendarReplies[CalendarKind].event_series!=0);Effect(api);return CalendarReplies[CalendarKind].event_return;}
int RealEventsCurrency(const string currency,MqlCalendarEvent &events[]){return FillCalendarEvents(62,currency,events);}
int RealEventsCountry(const string country,MqlCalendarEvent &events[]){return FillCalendarEvents(63,country,events);}
int RealCalendarValues(const ulong event_id,MqlCalendarValue &values[],const datetime from,const datetime to=0){Begin();End(64,event_id,(ulong)from,(ulong)to,(ulong)(long)CalendarReplies[CalendarKind].value_return);Word((ulong)(long)CalendarReplies[CalendarKind].value_error);int count=ArraySize(CalendarReplies[CalendarKind].times);ArrayResize(values,count);ArraySetAsSeries(values,false);for(int i=0;i<count;i++){ZeroMemory(values[i]);values[i].time=(datetime)CalendarReplies[CalendarKind].times[i];}ArraySetAsSeries(values,CalendarReplies[CalendarKind].value_series!=0);if(CalendarReplies[CalendarKind].value_error>=0)InjectedCalendarError=CalendarReplies[CalendarKind].value_error;Effect(64);return CalendarReplies[CalendarKind].value_return;}
void RealCalendarPrint(const string value){Begin();End(65,0,0,0,0,value);Effect(65);}
'''

def render():
    code=BASE_RENDER().replace('input string CheckRun="";','input string CheckRun="";\n'+DECL,1)
    for name,kind,actual in [('StartupNfp',0,'Bot1FindNfpTime'),('StartupInterest',1,'Bot1FindInterestRateTime'),('StartupCpi',2,'Bot1FindCpiTime')]:
        old=f'long {name}(){{Begin();End({51+kind},(ulong)StartupReplies[{kind}]);Effect({51+kind});return StartupReplies[{kind}];}}'
        require(old in code,'CALENDAR_BODY_MARKER');code=code.replace(old,f'long {name}(){{CalendarKind={kind};return {actual}();}}')
    code=code.replace('Counts[57]','Counts[66]').replace('long StartupReplies[3],StartupClocks[3];',GLOBALS+'\nlong StartupReplies[3],StartupClocks[3];',1)
    marker='for(int i=0;i<3;i++)StartupClocks[i]=FileReadLong(file);'
    reads='''
for(int k=0;k<3;k++){CalendarReplies[k].now=FileReadLong(file);CalendarReplies[k].event_return=(int)FileReadLong(file);CalendarReplies[k].value_return=(int)FileReadLong(file);CalendarReplies[k].event_series=(int)FileReadLong(file);CalendarReplies[k].value_series=(int)FileReadLong(file);CalendarReplies[k].value_error=(int)FileReadLong(file);int count=(int)FileReadLong(file);if(count<0 || count>32)return 8;ArrayResize(CalendarReplies[k].ids,count);ArrayResize(CalendarReplies[k].names,count);for(int i=0;i<count;i++){CalendarReplies[k].ids[i]=(ulong)FileReadLong(file);CalendarReplies[k].names[i]=ReadText(file);}count=(int)FileReadLong(file);if(count<0 || count>32)return 8;ArrayResize(CalendarReplies[k].times,count);for(int i=0;i<count;i++)CalendarReplies[k].times[i]=FileReadLong(file);}InjectedCalendarError=-1;CalendarKind=-1;
'''
    require(marker in code,'CALENDAR_READ_MARKER');code=code.replace(marker,marker+reads)
    code=code.replace('int OnStart()',MOCKS+'\nint OnStart()',1)
    code+='\n#undef GetLastError\nint CalendarError(){return InjectedCalendarError<0 ? GetLastError() : InjectedCalendarError;}\n'
    code+='int CalendarStringFind(const string value,const string needle,const int start=0){int previous=CalendarError();ResetLastError();int result=StringFind(value,needle,start);int error=GetLastError();InjectedCalendarError=error==0 ? previous : error;return result;}\n'
    return code.replace('bot1-startup-news-flow','bot1-startup-real-calendars')

class Native(n.Native):
    array=cal.base.Original.array
    def __init__(self):
        super().__init__();self.calendar_kind=-1
        binds=[cal.base.CFG[1]]+[cal.CFG[(1,k)] for k in [1,2]]
        self.calendar_ranges=[]
        for b in binds:
            lo=b['fn'] if 'fn' in b else int(b['begin'],16);hi=b['end'] if isinstance(b['end'],int) else int(b['end'],16);digest=b.get('sha',b.get('sha256'))
            require(hashlib.sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==digest,'REAL_CALENDAR_BYTES_CHANGED');self.calendar_ranges.append((lo,hi))
        for address in cal.base.CFG[1]['type_tags']:
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,struct.pack('<H',17))
        self.calendar_sdk={0x7ff683f20000+0x3802f0:62,0x7ff683f20000+0x380260:63,0x7ff683f20000+0x380440:64,0x7ff683f20000+0x7b6ef0:66}
        for address,api in self.calendar_sdk.items():
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3');self.sdk[address]=api;self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
    def begin_preparation(self,m,address,size,user):
        super().begin_preparation(m,address,size,user)
        for api in range(61,66):self.counts.setdefault(api,0)
    def service(self,m,address,size,user):
        if address in self.news_children:
            self.calendar_kind=self.news_children[address]-51;return
        api=self.calendar_sdk.get(address);x=self.x;reg=lambda name:m.reg_read(getattr(x,'UC_X86_REG_'+name));sp=reg('RSP')
        ret=struct.unpack('<Q',m.mem_read(sp,8))[0]-self.base
        inside=any(lo<=ret<hi for lo,hi in self.calendar_ranges)
        if inside and address==0x7ff6846f1ce0:api=61
        if inside and address==0x7ff6846d49f0:api=65
        if api is None:return super().service(m,address,size,user)
        if api==66:return
        require(0<=self.calendar_kind<3,'CALENDAR_KIND_MISSING');q=self.case['calendars'][self.calendar_kind];r=self.tape
        expected=r.block();actual=self.state();require(expected==actual,'CALENDAR_STATE '+str((self.case['id'],api,next((i for i,(u,v) in enumerate(zip(expected,actual)) if u!=v),None))))
        kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I');require(kind==api and reg('RCX')==self.gate['ctx'],'CALENDAR_API_ORDER_OR_CONTEXT');reply=0
        if api==61:require(args[:2]==[q['now']&j.MASK,self.calendar_kind],'CALENDAR_TIME_REPLY');reply=args[0]
        elif api in [62,63]:
            query='US' if api==63 else 'USD';require(texts==[query,None] and self.read_text(reg('RDX'))==query,'CALENDAR_QUERY');require(args==[q['event_return']&j.MASK,len(q['events']),q['event_series'],self.calendar_kind],'CALENDAR_EVENTS_REPLY')
            records=[]
            for ident,title in q['events']:
                raw=bytearray(128);struct.pack_into('<Q',raw,0,ident);struct.pack_into('<IQ',raw,72,0,0 if title is None else self.string(title));records.append(raw)
            self.array(reg('R8'),records,q['event_series']);reply=args[0]
        elif api==64:
            to=struct.unpack('<Q',m.mem_read(sp+40,8))[0];require(args[:3]==[reg('RDX'),reg('R9'),to] and args[3]==q['value_return']&j.MASK,'CALENDAR_VALUE_ARGS')
            injected,=r.take('Q');require(injected==q['value_error']&j.MASK,'CALENDAR_ERROR_REPLY');records=[]
            for value in q['values']:
                raw=bytearray(128);struct.pack_into('<q',raw,16,value);records.append(raw)
            self.array(reg('R8'),records,q['value_series']);reply=args[3]
            if q['value_error']>=0:error=q['value_error']
        else:
            desc=struct.unpack('<Q',m.mem_read(sp+40,8))[0];require((reg('RDX'),reg('R8'),reg('R9'))==(2,1,0x590008) and texts==[self.read_text(desc),None],'CALENDAR_PRINT_ARGS')
        self.counts[api]+=1;self.effect(api);self.calls+=1;m.mem_write(self.base+0x6a410,struct.pack('<I',error));m.reg_write(x.UC_X86_REG_RAX,reply)

def identity():
    current=BASE_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupRealCalendarsCheck.mq5'
    current['sources_sha256']={f.relative_to(src).as_posix():sha(f) for f in j.pub.closure(script,src)}
    for p in [Path(__file__),Path(cal.__file__),Path(cal.base.__file__),ROOT/'danh-gia-doc-lap/remaining-news-calendars-20261027-r1/native-bindings.json']:current['helpers_sha256'][p.relative_to(ROOT).as_posix()]=sha(p)
    return current

temp=n.a.load('real_calendar_runner','kiem-noi-khoi-dong-bot-1.py')
for function in ['execute','main']:
    code=inspect.getsource(getattr(temp,function)).replace('Bot1StartupPostPreparationCheck','Bot1StartupRealCalendarsCheck').replace('bot1-startup-joined','bot1-startup-real-calendars').replace('startup-joined-','startup-real-calendars-')
    code=code.replace('Continuous after first preparation through normal return only.','Continuous startup after authorization, including all three actual calendar bodies.').replace('earlier OnInit and full EA remain unverified.','calendar array faults within this flow, authorization and full EA remain unverified.')
    exec(compile(code,__file__,'exec'),j.__dict__)
j.cases=cases;j.encode=encode;j.render=render;j.identity=identity;j.Native=Native
j.SCOPE=dict(j.SCOPE,calendar_bodies_replaced=False,native_all_three_calendar_bodies_executed=True,terminal_calendar_array_and_error_replies_supplied=True)
if __name__=='__main__':j.main()
