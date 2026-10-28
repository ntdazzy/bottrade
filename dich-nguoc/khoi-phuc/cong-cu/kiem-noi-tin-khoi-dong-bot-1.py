"""Compare the continuous successful startup path after its authorization gate.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Native 0xd60..0x5658 executes, with calendar, broker and storage replies supplied.
"""
import copy,importlib.util,inspect,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
s=importlib.util.spec_from_file_location('news_account_flow',ROOT/'cong-cu/kiem-noi-von-khoi-dong-bot-1.py');a=importlib.util.module_from_spec(s);s.loader.exec_module(a)
j,require,sha=a.j,a.require,a.sha
BASE_CASES=a.cases();BASE_RENDER=a.render;BASE_IDENTITY=a.identity;BASE_ENCODE=a.encode
j.FIELDS.append(('Nfp.last_query','q',0x6a3a8))
CALL=a.CALL.replace('Bot1InitializeStartupAccountFlow','Bot1InitializeStartupNewsFlow',1).replace('UseEquity!=0,ResetHighest!=0','UseEquity,ResetHighest')

def cases():
    rows=[]
    def add(tag,flags=(1,1,1),replies=(1790000010,1790000020,1790000030),minutes=(10,10,10),clocks=(1790000000,)*3):
        r=copy.deepcopy(BASE_CASES[0]);r.update(id=len(rows),tag=tag,effects=[]);r['values']['Nfp.last_query']=-123
        for field,v in zip(['nfp','interest','cpi'],flags):r['values']['Windows.'+field+'_enabled']=v
        for field,v in zip(['nfp','interest','cpi'],minutes):r['values']['Windows.'+field+'_after']=v
        r['news']=dict(replies=list(replies),clocks=list(clocks));rows.append(r);return r
    for mask in range(8):
        for reply in [(0,0,0),(1790000010,1790000020,1790000030),(1790000030,1790000010,1790000020),(-1,1,0)]:
            for minutes in [-1,0,10,2147483647]:add('news-gates-and-selection',[(mask>>i)&1 for i in range(3)],reply,[minutes]*3)
    for flags in [(255,255,255),(2,0,128)]:add('news-nonboolean-flags',flags)
    for value in [-1,0,1,2147483647,2147483648,32535215999]:add('news-date-text',replies=[value]*3)
    for bank_case in BASE_CASES:
        row=add('news-account-boundary');row['bank']=copy.deepcopy(bank_case['bank']);row['prep']=copy.deepcopy(bank_case['prep'])
        for n in ['UseEquity','ResetHighest','ManualBalance']:row['values'][n]=bank_case['values'][n]
    for api,name,value in [(51,'Windows.interest_enabled',0),(52,'Events.nfp',1790000001),(53,'Windows.cpi_after',0),
                           (54,'Windows.nfp_enabled',0),(55,'Windows.interest_enabled',255),(56,'Events.cpi',0),
                           (55,'ManualBalance',7777.),(56,'ContextInputs.base_magic',42),
                           (55,'UseEquity',255),(56,'ResetHighest',1)]:
        row=add('news-live-state');row['effects']=[[api,1,next(i for i,f in enumerate(j.FIELDS) if f[0]==name),value]]
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',j.MAGIC,1,len(rows)))
    for row in rows:raw+=BASE_ENCODE([row])[12:]+struct.pack('<6Q',*(n&j.MASK for n in row['news']['replies']+row['news']['clocks']))
    return bytes(raw)

DECL=r'''
datetime StartupNewsServer();
#define TimeTradeServer StartupNewsServer
#include "../../Include/bot-cua-toi-1/Bot1NewsSelector.mqh"
#undef TimeTradeServer
#include "../../Include/bot-cua-toi-1/Bot1NfpCalendar.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ReleaseCalendars.mqh"
long StartupNfp();long StartupInterest();long StartupCpi();
string Bot1InitializationTimeText(const datetime value);
void StartupNewsPrint(const string value);
#define BOT1_INITIALIZATION_TIME_TEXT_MQH
#define Bot1FindNfpTime StartupNfp
#define Bot1FindInterestRateTime StartupInterest
#define Bot1FindCpiTime StartupCpi
#define Print StartupNewsPrint
#include "../../Include/bot-cua-toi-1/Bot1NewsInitialization.mqh"
#undef Bot1FindNfpTime
#undef Bot1FindInterestRateTime
#undef Bot1FindCpiTime
#undef Print
'''
MOCKS=r'''
long StartupNfp(){Begin();End(51,(ulong)StartupReplies[0]);Effect(51);return StartupReplies[0];}
long StartupInterest(){Begin();End(52,(ulong)StartupReplies[1]);Effect(52);return StartupReplies[1];}
long StartupCpi(){Begin();End(53,(ulong)StartupReplies[2]);Effect(53);return StartupReplies[2];}
string Bot1InitializationTimeText(const datetime value){Begin();string text=(string)value;End(54,(ulong)value,0,0,0,text);Effect(54);return text;}
void StartupNewsPrint(const string value){Begin();End(55,0,0,0,0,value);Effect(55);}
datetime StartupNewsServer(){Begin();int i=Counts[56];long value=StartupClocks[i<3 ? i : 2];End(56,(ulong)value);Effect(56);return (datetime)value;}
'''
def render():
    code=BASE_RENDER().replace('input string CheckRun="";','input string CheckRun="";\n'+DECL,1)
    code=code.replace('#include "../../Include/bot-cua-toi-1/Bot1StartupAccountFlow.mqh"','#include "../../Include/bot-cua-toi-1/Bot1StartupNewsFlow.mqh"')
    code=code.replace('Counts[48]','Counts[57]').replace('void NewsSnapshot(){','long StartupReplies[3],StartupClocks[3];\nvoid NewsSnapshot(){',1)
    code=code.replace('int OnStart()',MOCKS+'\nint OnStart()',1)
    marker='NewsSeed=FileReadLong(file);FileReadLong(file);';require(marker in code and a.CALL in code,'NEWS_RENDER_MARKER')
    code=code.replace(marker,marker+'for(int i=0;i<3;i++)StartupReplies[i]=FileReadLong(file);for(int i=0;i<3;i++)StartupClocks[i]=FileReadLong(file);')
    return code.replace(a.CALL,CALL).replace('bot1-startup-account-flow','bot1-startup-news-flow')

class Native(a.Native):
    def __init__(self):
        super().__init__();self.news_phase=False
        self.news_children={self.base+0x61b0:51,self.base+0x6600:52,self.base+0x6a90:53}
        for address in self.news_children:self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        address=0x7ff6846f1ce0
        if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
        self.m.mem_write(address,b'\xc3');self.sdk[address]=56;self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.start_account,begin=self.base+0x126c,end=self.base+0x126c)
    def begin_preparation(self,m,address,size,user):
        first=not self.started;super().begin_preparation(m,address,size,user)
        if first:
            for api in range(51,57):self.counts.setdefault(api,0)
            self.news_phase=True;self.account_phase=False
            m.reg_write(self.x.UC_X86_REG_RIP,self.base+0xd60)
    def start_account(self,m,address,size,user):self.news_phase=False;self.account_phase=True
    def service(self,m,address,size,user):
        if not self.news_phase:return super().service(m,address,size,user)
        api=self.news_children.get(address,{0x7ff6846ef6c0:54,0x7ff6846d49f0:55,0x7ff6846f1ce0:56}.get(address))
        require(api is not None,'UNKNOWN_NEWS_API '+hex(address));r=self.tape;expected=r.block();actual=self.state()
        require(expected==actual,'NEWS_STATE '+str((self.case['id'],api,next((i for i,(x,y) in enumerate(zip(expected,actual)) if x!=y),None))))
        kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I');require(kind==api,'NEWS_API_ORDER')
        x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));reply=0
        if api in [51,52,53]:require(args[0]==self.case['news']['replies'][api-51]&j.MASK and texts==[None,None],'NEWS_CALENDAR_REPLY');reply=args[0]
        else:
            require(reg('RCX')==self.gate['ctx'],'NEWS_CONTEXT')
            if api==54:
                require(reg('RDX')==args[0] and reg('R8')==0x54,'NEWS_DATE_ARGUMENT');self.put_text(reg('R9')-self.base,texts[0])
            elif api==55:
                sp=reg('RSP');desc=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
                require((reg('RDX'),reg('R8'),reg('R9'))==(2,1,0x590008) and texts==[self.read_text(desc),None],'NEWS_PRINT_ARGUMENT')
            else:
                require(args[0]==self.case['news']['clocks'][min(self.counts[56],2)]&j.MASK,'NEWS_SERVER_REPLY');reply=args[0]
        self.counts[api]+=1;self.effect(api);self.calls+=1
        m.mem_write(self.base+0x6a410,struct.pack('<I',error));m.reg_write(x.UC_X86_REG_RAX,reply)
        if api in [51,52,53]:
            sp=reg('RSP');ret=struct.unpack('<Q',m.mem_read(sp,8))[0];require(self.base+0xd60<ret<self.base+0x126c,'NEWS_CHILD_RETURN')
            m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret)

def identity():
    current=BASE_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupNewsFlowCheck.mq5'
    current['sources_sha256']={f.relative_to(src).as_posix():sha(f) for f in j.pub.closure(script,src)}
    current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__));return current

temp=a.load('news_runner_original','kiem-noi-khoi-dong-bot-1.py')
for function in ['execute','main']:
    code=inspect.getsource(getattr(temp,function)).replace('Bot1StartupPostPreparationCheck','Bot1StartupNewsFlowCheck').replace('bot1-startup-joined','bot1-startup-news-flow').replace('startup-joined-','startup-news-flow-')
    code=code.replace('Continuous after first preparation through normal return only.','Continuous news initialization, account, calendars, context, preparation and tail after authorization gate.').replace('earlier OnInit and full EA remain unverified.','authorization gate, actual calendar child bodies and full EA remain unverified.')
    exec(compile(code,__file__,'exec'),j.__dict__)
j.cases=cases;j.encode=encode;j.render=render;j.identity=identity;j.Native=Native
j.SCOPE=dict(j.SCOPE,native_news_initialization_and_selector_executed=True,calendar_bodies_replaced=True,
 datetime_text_replies_measured_in_mt5=True,authorization_executed=False)
if __name__=='__main__':j.main()
