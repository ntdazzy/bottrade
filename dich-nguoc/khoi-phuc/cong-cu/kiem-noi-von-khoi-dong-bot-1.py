"""Compare account, built-in calendars, context, preparation and startup tail.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Runs original 0x126c..0x5658 continuously. Account and persistent storage are
supplied, never the real account or terminal variables.
"""
import copy,importlib.util,inspect,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def load(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
c=load('account_context_flow','kiem-noi-ngu-canh-khoi-dong-bot-1.py');j=c.j
require,sha,boot=j.require,j.sha,c.boot
BASE_CASES=c.cases();BASE_RENDER=c.render;BASE_IDENTITY=c.identity
ACCOUNT_FIELDS=[('UseEquity','B',0x6a790),('ResetHighest','B',0x6a778),('ManualBalance','d',0x6a738),
 ('HighestBalance','d',0x6a328),('PeakKey','s',0x6a330),('TimeKey','s',0x6a340),('AccountLastTime','q',0x6a350),
 ('NewsFlag0','B',0x69f60),('NewsFlag1','B',0x69f61)]
for f in ACCOUNT_FIELDS:require(not any(r==f[2] for _,_,r in j.FIELDS),'ACCOUNT_FIELD_DUPLICATE');j.FIELDS.append(f)
CALL=c.CALL.replace('Bot1InitializeStartupContextFlow(ChartName,','Bot1InitializeStartupAccountFlow(UseEquity!=0,ResetHighest!=0,ManualBalance,HighestBalance,PeakKey,TimeKey,AccountLastTime,NewsFlag0,NewsFlag1,NewsNfp,NewsInterest,NewsCpi,ChartName,',1)
CALENDARS=[0x68330,0x68ca0,0x69600]

def cases():
    rows=[]
    def add(tag,use=0,reset=0,manual=0.,peak=15000.,exists=1,**updates):
        row=copy.deepcopy(BASE_CASES[0]);row.update(id=len(rows),tag=tag,effects=[],account=10000.)
        row['values'].update(UseEquity=use,ResetHighest=reset,ManualBalance=manual,HighestBalance=-987.,PeakKey='old peak',TimeKey='old time',AccountLastTime=-9,NewsFlag0=173,NewsFlag1=255)
        row['bank']=dict(login=1234567,balance=10000.,equity=9000.,has_peak=1,peak=peak,has_time=exists,time=1700000012.75,now=1790000000,news_seed=77)
        row['bank'].update(updates);rows.append(row);return row
    for use in [0,1,255]:
        for reset in [0,1,255]:
            for exists in [0,1]:
                for manual in [-1.,0.,25000.]:add('account-branches',use,reset,manual,exists=exists)
    for peak in [-1.,0.,5000.,10000.,15000.,float('nan'),float('inf')]:add('stored-peak',peak=peak)
    add('missing-peak',has_peak=0)
    for login in [0,-1,2147483647,9223372036854775807]:add('account-id-width',login=login)
    for field in ['balance','equity','time']:
        for value in [-0.,-100.,float('nan'),float('inf'),float('-inf'),float(1<<63)]:add('account-number-boundary',use=1,**{field:value})
    for seed in [-1,0,1793100000]:add('calendar-prefix-and-tail',news_seed=seed)
    for ctx in [BASE_CASES[0],BASE_CASES[105],BASE_CASES[106],BASE_CASES[107],BASE_CASES[161],BASE_CASES[-1]]:
        row=add('account-context-preparation');row['values'].update({n:v for n,v in ctx['values'].items() if n not in {f[0] for f in ACCOUNT_FIELDS}});row['prep']=copy.deepcopy(ctx['prep'])
    return rows

BASE_ENCODE=j.encode
def encode(rows):
    raw=bytearray(struct.pack('<3i',j.MAGIC,1,len(rows)))
    for row in rows:
        raw+=BASE_ENCODE([row])[12:];b=row['bank']
        raw+=struct.pack('<10Q',b['login']&j.MASK,boot.bits(b['balance']),boot.bits(b['equity']),b['has_peak'],boot.bits(b['peak']),b['has_time'],boot.bits(b['time']),b['now']&j.MASK,b['news_seed']&j.MASK,0)
    return bytes(raw)

DECL=r'''
double InitAccountDouble(const ENUM_ACCOUNT_INFO_DOUBLE property);
long InitAccountInteger(const ENUM_ACCOUNT_INFO_INTEGER property);
double InitGlobalGet(const string name);datetime InitGlobalSet(const string name,const double value);
bool InitGlobalCheck(const string name);void InitSleep(const int milliseconds);
datetime InitAccountTime();void InitAccountPrint(const string message);
#define AccountInfoDouble InitAccountDouble
#define AccountInfoInteger InitAccountInteger
#define GlobalVariableGet InitGlobalGet
#define GlobalVariableSet InitGlobalSet
#define GlobalVariableCheck InitGlobalCheck
#define Sleep InitSleep
#define TimeCurrent InitAccountTime
#define Print InitAccountPrint
#include "../../Include/bot-cua-toi-1/Bot1AccountInitialization.mqh"
#undef AccountInfoDouble
#undef AccountInfoInteger
#undef GlobalVariableGet
#undef GlobalVariableSet
#undef GlobalVariableCheck
#undef Sleep
#undef TimeCurrent
#undef Print
'''
GLOBALS=r'''
uchar UseEquity,ResetHighest,NewsFlag0,NewsFlag1;
double ManualBalance,HighestBalance;string PeakKey,TimeKey;long AccountLastTime;
long NewsNfp[300],NewsInterest[300],NewsCpi[300];
long BankLogin,BankNow,NewsSeed;double BankBalance,BankEquity,BankPeak,BankTime;bool BankHasPeak,BankHasTime;
string BankPeakKey,BankTimeKey;
void NewsSnapshot(){ulong h=0xcbf29ce484222325;for(int i=0;i<300;i++)h=(h^(ulong)NewsNfp[i])*0x100000001b3;for(int i=0;i<300;i++)h=(h^(ulong)NewsInterest[i])*0x100000001b3;for(int i=0;i<300;i++)h=(h^(ulong)NewsCpi[i])*0x100000001b3;Word(h);}
void NewsFinal(){for(int i=0;i<300;i++)Word((ulong)NewsNfp[i]);for(int i=0;i<300;i++)Word((ulong)NewsInterest[i]);for(int i=0;i<300;i++)Word((ulong)NewsCpi[i]);}
'''
MOCKS=r'''
double InitAccountDouble(const ENUM_ACCOUNT_INFO_DOUBLE property){Begin();double v=property==ACCOUNT_BALANCE ? BankBalance : BankEquity;End(40,(ulong)property,Bits(v));Effect(40);return v;}
long InitAccountInteger(const ENUM_ACCOUNT_INFO_INTEGER property){Begin();End(41,(ulong)property,(ulong)BankLogin);Effect(41);return BankLogin;}
double InitGlobalGet(const string name){Begin();double v=name==BankPeakKey ? (BankHasPeak ? BankPeak : 0.) : (BankHasTime ? BankTime : 0.);End(42,Bits(v),0,0,0,name);Effect(42);return v;}
datetime InitGlobalSet(const string name,const double value){Begin();End(43,Bits(value),0,0,0,name);if(name==BankPeakKey){BankPeak=value;BankHasPeak=true;}else{BankTime=value;BankHasTime=true;}Effect(43);return 0;}
bool InitGlobalCheck(const string name){Begin();End(44,(ulong)BankHasTime,0,0,0,name);Effect(44);return BankHasTime;}
void InitSleep(const int milliseconds){Begin();End(45,(ulong)(long)milliseconds);Effect(45);}
datetime InitAccountTime(){Begin();End(46,(ulong)BankNow);Effect(46);return (datetime)BankNow;}
void InitAccountPrint(const string message){Begin();End(47,0,0,0,0,message);Effect(47);}
'''

def render():
    code=BASE_RENDER().replace('input string CheckRun="";','input string CheckRun="";\n'+DECL,1)
    code=code.replace('#include "../../Include/bot-cua-toi-1/Bot1StartupContextFlow.mqh"','#include "../../Include/bot-cua-toi-1/Bot1StartupAccountFlow.mqh"')
    code=code.replace('Counts[38]','Counts[48]')
    code=code.replace('void PrepArraySnapshot();',GLOBALS+'\nvoid PrepArraySnapshot();',1)
    code=code.replace('PrepArraySnapshot();Word(TablesHash());','PrepArraySnapshot();NewsSnapshot();Word(TablesHash());',1)
    code=code.replace('Word((ulong)(long)Result);}}','Word((ulong)(long)Result);NewsFinal();}}',1)
    code=code.replace('int OnStart()',MOCKS+'\nint OnStart()',1)
    marker='PrepNow=FileReadLong(file);'
    reads='BankLogin=FileReadLong(file);BankBalance=Value((ulong)FileReadLong(file));BankEquity=Value((ulong)FileReadLong(file));BankHasPeak=FileReadLong(file)!=0;BankPeak=Value((ulong)FileReadLong(file));BankHasTime=FileReadLong(file)!=0;BankTime=Value((ulong)FileReadLong(file));BankNow=FileReadLong(file);NewsSeed=FileReadLong(file);FileReadLong(file);\n'
    reads+='BankPeakKey="HighestBalance"+IntegerToString(BankLogin);BankTimeKey="LastBalanceOp"+IntegerToString(BankLogin);for(int i=0;i<300;i++){NewsNfp[i]=NewsSeed+i*17;NewsInterest[i]=NewsSeed+10000+i*17;NewsCpi[i]=NewsSeed+20000+i*17;}\n'
    require(marker in code and c.CALL in code,'ACCOUNT_RENDER_MARKER')
    return code.replace(marker,marker+'\n'+reads).replace(c.CALL,CALL).replace('bot1-startup-context-flow','bot1-startup-account-flow')

class Native(c.Native):
    def __init__(self):
        super().__init__();self.account_phase=False
        self.account_sdk={0x7ff6846b7370:40,0x7ff6846b73c0:41,0x7ff6846ddbe0:42,0x7ff6846ddc90:43,0x7ff6846ddda0:44,0x7ff6846d17c0:45,0x7ff6846f1c40:46,0x7ff6846d49f0:47,
                          0x7ff6846edfe0:48,0x7ff6846ee4f0:49,0x7ff6846ef6c0:50}
        for address,api in self.account_sdk.items():
            if address not in self.sdk:
                if not any(a<=address<=b for a,b,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
                self.m.mem_write(address,b'\xc3');self.sdk[address]=api;self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.finish_account,begin=self.base+0x1941,end=self.base+0x1941)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.start_context,begin=self.base+0x3827,end=self.base+0x3827)
    def begin_preparation(self,m,address,size,user):
        first=not self.started;super().begin_preparation(m,address,size,user)
        if first:
            for api in range(40,48):self.counts.setdefault(api,0)
            self.account_phase=True;self.context_phase=False;self.prep_phase=False
            m.reg_write(self.x.UC_X86_REG_R13,0x7ff6846b73c0)
            self.put_text(0x6a43c,None)
            b=self.case['bank'];self.bank_store={}
            if b['has_peak']:self.bank_store['HighestBalance'+str(b['login'])]=boot.bits(b['peak'])
            if b['has_time']:self.bank_store['LastBalanceOp'+str(b['login'])]=boot.bits(b['time'])
            for a,offset in enumerate(CALENDARS):m.mem_write(self.base+offset,struct.pack('<300q',*(b['news_seed']+a*10000+i*17 for i in range(300))))
            m.reg_write(self.x.UC_X86_REG_RIP,self.base+0x126c)
    def finish_account(self,m,address,size,user):self.account_phase=False
    def start_context(self,m,address,size,user):
        require(m.reg_read(self.x.UC_X86_REG_XMM6)&j.MASK==0,'ACCOUNT_DID_NOT_ESTABLISH_ZERO')
        require(self.read_text(self.base+0x6a43c) is not None,'ACCOUNT_STRING_BUFFER_MISSING')
        self.context_phase=True
    def calendar_bytes(self):return b''.join(bytes(self.m.mem_read(self.base+r,2400)) for r in CALENDARS)
    def values(self,fields):
        raw=super().values(fields)
        if fields is j.FIELDS:
            h=0xcbf29ce484222325
            for (v,) in struct.iter_unpack('<Q',self.calendar_bytes()):h=((h^v)*0x100000001b3)&j.MASK
            raw+=struct.pack('<Q',h)
        return raw
    def state(self,final=False):return super().state(final)+(self.calendar_bytes() if final else b'')
    def service(self,m,address,size,user):
        if not self.account_phase:return super().service(m,address,size,user)
        require(address in self.account_sdk,'UNKNOWN_ACCOUNT_API '+hex(address));api=self.account_sdk[address];x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));arg=reg('RDX')
        require(reg('RCX')==self.gate['ctx'],'ACCOUNT_CONTEXT')
        if api==48:
            require(reg('R8')==0 and reg('R9')&65535==32,'ACCOUNT_INTEGER_FORMAT')
            self.put_text(0x6a43c,str(struct.unpack('<q',struct.pack('<Q',arg))[0]));return
        if api==49:
            m.reg_write(x.UC_X86_REG_RAX,int(self.read_text(arg))&j.MASK);return
        if api==50:
            kind=reg('R8')
            if kind==0x55:value=str(struct.unpack('<q',struct.pack('<Q',arg))[0])
            else:
                require(kind==0x58 and arg==self.last_bank_get,'ACCOUNT_DOUBLE_FORMAT_VALUE')
                peek=j.Reader(self.tape.raw);peek.pos=self.tape.pos;peek.block();next_api,*_=peek.take('i4Q');message=peek.text();prefix='HighestBalance value found: '
                require(next_api==47 and message.startswith(prefix),'ACCOUNT_FORMAT_PRINT_SEQUENCE');value=message[len(prefix):]
            self.put_text(reg('R9')-self.base,value);return
        r=self.tape;expected=r.block();actual=self.state()
        require(expected==actual,'ACCOUNT_STATE '+str((self.case['id'],api,next((i for i,(a,b) in enumerate(zip(expected,actual)) if a!=b),None))))
        kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I');require(kind==api,'ACCOUNT_API_ORDER');reply=0;b=self.case['bank']
        if api==40:require(arg==args[0] and arg in [37,40] and args[1]==boot.bits(b['balance' if arg==37 else 'equity']),'ACCOUNT_DOUBLE_ARGS');reply=args[1]
        elif api==41:require(arg==args[0]==0 and args[1]==b['login']&j.MASK,'ACCOUNT_LOGIN_ARGS');reply=args[1]
        elif api in [42,43,44]:
            key=self.read_text(arg);require(texts==[key,None] and key in ['HighestBalance'+str(b['login']),'LastBalanceOp'+str(b['login'])],'ACCOUNT_STORAGE_KEY')
            if api==42:require(args[0]==self.bank_store.get(key,boot.bits(0.)),'ACCOUNT_GET_VALUE');reply=args[0];self.last_bank_get=reply
            elif api==43:require(args[0]==reg('XMM2')&j.MASK,'ACCOUNT_SET_VALUE');self.bank_store[key]=args[0]
            else:require(args[0]==int(key in self.bank_store),'ACCOUNT_CHECK_VALUE');reply=args[0]
        elif api==45:require(arg==args[0]==5000,'ACCOUNT_SLEEP_ARGS')
        elif api==46:require(arg==0 and args[0]==b['now']&j.MASK,'ACCOUNT_TIME_ARGS');reply=args[0]
        elif api==47:
            sp=reg('RSP');desc=struct.unpack('<Q',m.mem_read(sp+40,8))[0];require((arg,reg('R8'),reg('R9'))==(2,1,0x590008) and texts==[self.read_text(desc),None],'ACCOUNT_PRINT_ARGS')
        self.counts[api]+=1;self.effect(api);self.calls+=1
        m.mem_write(self.base+0x6a410,struct.pack('<I',error))
        if api in [40,42]:m.mem_write(self.base+0x6a448,struct.pack('<Q',reply))
        else:m.reg_write(x.UC_X86_REG_RAX,reply)

def identity():
    current=BASE_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupAccountFlowCheck.mq5'
    current['sources_sha256']={f.relative_to(src).as_posix():sha(f) for f in j.pub.closure(script,src)}
    current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__));return current

temp=load('account_runner_original','kiem-noi-khoi-dong-bot-1.py')
for function in ['execute','main']:
    source=inspect.getsource(getattr(temp,function)).replace('Bot1StartupPostPreparationCheck','Bot1StartupAccountFlowCheck').replace('bot1-startup-joined','bot1-startup-account-flow').replace('startup-joined-','startup-account-flow-')
    source=source.replace('Continuous after first preparation through normal return only.','Continuous account, 900 calendar cells, context, preparation and tail.').replace('earlier OnInit and full EA remain unverified.','OnInit before account and full EA remain unverified.')
    exec(compile(source,__file__,'exec'),j.__dict__)
j.cases=cases;j.encode=encode;j.render=render;j.identity=identity;j.Native=Native
j.SCOPE=dict(j.SCOPE,native_account_initialization_executed=True,native_literal_calendars_executed=True,
 caller_xmm6_zero_supplied=False,caller_string_return_buffer_primed=False,account_prefix_establishes_context_conditions=True,
 account_and_storage_replies_supplied=True,diagnostic_double_format_supplied_from_mql5=True)
if __name__=='__main__':j.main()
