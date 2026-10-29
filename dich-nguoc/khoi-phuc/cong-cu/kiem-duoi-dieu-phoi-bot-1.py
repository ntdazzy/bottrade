"""Compare bot1 dispatcher tail, rows and balance refresh with original code.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Open/closed panel children are recorded; row setter and native strings run.
"""
import copy,hashlib,importlib.util,inspect,struct,textwrap
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
b=module('dispatch_tail_base','kiem-duoi-khoi-dong-bot-1.py')
require,sha=b.require,b.sha;BASE_CASES=b.cases;BASE_ENCODE=b.encode;BASE_RENDER=b.render;BASE_IDENTITY=b.identity;BASE_NATIVE=b.Native
SCRIPT=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1DispatchTailCheck.mq5'
b.FIELDS += [('PreviousM5','q',0x68308),('BalanceCalls','i',0x68310),('CachedBalance','d',0x67480)]

def cases():
    seed=BASE_CASES()[0];rows=[]
    def add(tag,changes=None,info=0,times=None,bank=23456.75,ok=1,error=0):
        c=copy.deepcopy(seed);c.update(id=len(rows),tag=tag,info=info,effects=[],times=times or [900,901,902,903,904,905,906,907],bank=bank,object_ok=ok,object_error=error)
        c['values'].update({'Show':1,'Tester':1,'P.rows_ready':1,'PreviousM5':100,'BalanceCalls':0,'CachedBalance':-12.5})
        for i in range(8):c['values'][f'P.closed[{i}]']=i+1.005;c['values'][f'P.per_trade[{i}]']=-i-1.005;c['values'][f'P.lots[{i}]']=(i+1)*.015
        c['values'].update(changes or {});rows.append(c);return c
    for show in [0,1,2,255]:
        for tester in [0,1,255]:
            for info in [-1,0,1,2]:add('row-gates',{'Show':show,'Tester':tester},info=info)
    for counter in [-2147483648,-2,-1,0,1,2,2147483646,2147483647]:
        for previous in [100,900]:add('counter-and-bar',{'BalanceCalls':counter,'PreviousM5':previous})
    for flag in [0,1,2,255]:add('row-index-base',{'P.rows_ready':flag})
    for field in ['closed','per_trade','lots']:
        for value in [-1.005,-.005,-0.,.005,1.005,1e20,float('inf'),float('-inf'),b.boot.number(0x7ff8000000000041)]:add('round-and-format',{f'P.{field}[0]':value})
    for ok,error in [(0,4202),(1,0),(0,4001)]:add('object-reply',ok=ok,error=error)
    for api,n,name,value in [(21,1,'Show',0),(23,1,'PreviousM5',900),(23,2,'PreviousM5',999),(27,1,'P.rows_ready',255),(27,1,'P.closed[0]',123.456),(27,3,'P.lots[0]',.555),(24,1,'BalanceCalls',99),(24,1,'CachedBalance',987.)]:
        c=add('live-state',{'BalanceCalls':1});c['effects']=[[api,n,next(i for i,f in enumerate(b.FIELDS) if f[0]==name),value]]
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',b.MAGIC,1,len(rows)))
    for c in rows:raw+=BASE_ENCODE([c])[12:]+struct.pack('<Q2i',b.boot.bits(c['bank']),c['object_ok'],c['object_error'])
    return bytes(raw)

def render():
    code=BASE_RENDER()
    marker='#include "../../Include/bot-cua-toi-1/Bot1PanelCreation.mqh"'
    code=code.replace(marker,marker+'\n#include "../../Include/bot-cua-toi-1/Bot1StartupTail.mqh"',1)
    marker='#include "../../Include/bot-cua-toi-1/Bot1StartupTail.mqh"'
    at=code.rindex(marker)
    declarations='''datetime TailBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
double TailBalance(const ENUM_ACCOUNT_INFO_DOUBLE property);
string TailDouble(const double value,const int digits=8);
string TailInteger(const long value,const int width=0,const ushort fill=32);
bool TailObject(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value);
#define iTime TailBar
#define AccountInfoDouble TailBalance
#define DoubleToString TailDouble
#define IntegerToString TailInteger
#define ObjectSetString TailObject
#include "../../Include/bot-cua-toi-1/Bot1DispatchTail.mqh"
#undef iTime
#undef AccountInfoDouble
#undef DoubleToString
#undef IntegerToString
#undef ObjectSetString'''
    code=code[:at]+declarations+code[at+len(marker):]
    code=code.replace('Counts[23]','Counts[28]').replace('int Tape,ErrorOverride=-1,','long PreviousM5;int BalanceCalls;double CachedBalance,BankReply;int ObjectReply,ObjectError;uint LogicalError;\nint Tape,ErrorOverride=-1,')
    code=code.replace('GetLastError()', 'LogicalError').replace('int error=LogicalError','int error=(int)LogicalError')
    marker='ArrayInitialize(Counts,0);Selected=-1;'
    code=code.replace(marker,'BankReply=Value((ulong)FileReadLong(file));ObjectReply=FileReadInteger(file);ObjectError=FileReadInteger(file);LogicalError=0;'+marker)
    start=code.index('Result=Bot1InitializeStartupTail(');end=code.index(';',start)+1
    code=code[:start]+'Bot1FinishDispatch(Show,Tester,Seed,TradeSymbol,Balance,P,Events,Windows,Selection,LastTicket,Wins,Losses,PreviousM5,BalanceCalls,CachedBalance);Result=0;'+code[end:]
    mocks='''datetime TailBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();long value=Times[Counts[23]%8];End(23,(ulong)frame,(ulong)(long)shift,(ulong)value,symbol);Effect(23);return (datetime)value;}
double TailBalance(const ENUM_ACCOUNT_INFO_DOUBLE property){Begin();double value=BankReply;End(24,(ulong)property,Bits(value));Effect(24);return value;}
string TailDouble(const double value,const int digits){Begin();string result=DoubleToString(value,digits);End(25,Bits(value),(ulong)(long)digits,0,result);Effect(25);return result;}
string TailInteger(const long value,const int width,const ushort fill){Begin();string result=IntegerToString(value,width,fill);End(26,(ulong)value,(ulong)(long)width,(ulong)fill,result);Effect(26);return result;}
bool TailObject(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value){Begin();LogicalError=(uint)ObjectError;End(27,(ulong)chart,(ulong)property,(ulong)ObjectReply,name);Text(value);Effect(27);return ObjectReply!=0;}
'''
    code=code.replace('int OnStart()',mocks+'\nint OnStart()',1).replace('bot1-startup-tail','bot1-dispatch-tail')
    return '\n'.join(line.rstrip() for line in code.splitlines())+'\n'

def generate():
    code=render();require(not SCRIPT.exists() or SCRIPT.read_text(encoding='utf-8-sig')==code,'SOURCE_EXISTS')
    if not SCRIPT.exists():SCRIPT.write_text(code,encoding='utf-8',newline='\n')
    print(SCRIPT)

class Native(BASE_NATIVE):
    def __init__(self):
        super().__init__();require(hashlib.sha256(bytes(self.m.mem_read(self.base+0x10f60,0x173e4-0x10f60))).hexdigest()=='f5edd0f5e9033ddddb289a3419406c06292ce22bff197bea6d10acea1756c721','DISPATCHER_CHANGED')
        require(bytes(self.m.mem_read(self.base+0x517c0,12))==bytes(12),'NULL_SYMBOL_CHANGED')
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+0x47740,0x4794b-0x47740))).hexdigest()=='1f063e2f13a8e5742dafee2b70de1ad0c6419448ba27c60cc84cb28b33a9ebab','CELL_SETTER_CHANGED')
        self.extra={0x7ff6846f3b50:23,0x7ff6846b7370:24,0x7ff6846ed7c0:25,0x7ff6846edfe0:26,0x7ff6846e3c80:27}
        for address,api in self.extra.items():
            existed=address in self.sdk;self.sdk[address]=api
            if not existed:
                if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
                self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        for off in [0xc30,0x5880,0x3d6c0,0x4d260]:self.m.hook_add(self.uc.UC_HOOK_CODE,self.protected,begin=self.base+off,end=self.base+off)
    def protected(self,m,address,size,user):raise ValueError('AUTHORIZATION_OUTSIDE_DISPATCH_TAIL')
    def visit(self,m,address,size,user):
        # The inherited dispatcher-gate test stops before this epilogue.
        # Here the original epilogue must return naturally to the caller.
        self.covered.add(address-self.base)
    def service(self,m,address,size,user):
        api=self.extra.get(address)
        if api is None:return super().service(m,address,size,user)
        r=self.tape;x=self.x;reg=lambda name:m.reg_read(getattr(x,'UC_X86_REG_'+name))
        expected=r.block();actual=self.state();require(expected==actual,'TAIL_STATE '+str((self.case['id'],api,next((i for i,(a,b) in enumerate(zip(expected,actual)) if a!=b),None))))
        kind,*args=r.take('i3Q');text=r.text();error,=r.take('I');require(kind==api and reg('RCX')==0x23e575eae78,'TAIL_SDK_CONTEXT')
        if api==23:require(args[:2]==[reg('R8'),reg('R9')] and args[:2]==[5,1] and text is None and self.read_text(reg('RDX')) is None,'TAIL_BAR_ARGUMENTS');m.reg_write(x.UC_X86_REG_RAX,args[2])
        elif api==24:require(args[0]==reg('RDX')==37 and args[1]==b.boot.bits(self.case['bank']),'TAIL_BALANCE_ARGUMENTS');m.mem_write(self.base+0x6a448,struct.pack('<Q',args[1]))
        elif api==25:require(args[:2]==[reg('XMM1')&b.MASK,reg('R8')&0xffffffff] and args[1]==2,'TAIL_DOUBLE_ARGUMENTS');self.put_text(0x6a43c,text)
        elif api==26:require(args==[reg('RDX'),reg('R8')&0xffffffff,reg('R9')&65535],'TAIL_INTEGER_ARGUMENTS');self.put_text(0x6a43c,text)
        else:
            value=r.text();sp=reg('RSP');pointer=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
            require(reg('RDX')==args[0]==0 and reg('R9')==args[1]==6 and self.read_text(reg('R8'))==text and self.read_text(pointer)==value and args[2]==self.case['object_ok'],'TAIL_OBJECT_ARGUMENTS')
            require(error==self.case['object_error'],'TAIL_OBJECT_ERROR');m.reg_write(x.UC_X86_REG_RAX,args[2])
        self.counts[api]+=1
        for a,n,f,v in self.case['effects']:
            if a==api and n==self.counts[api]:
                _,k,off=b.FIELDS[f];size_=struct.calcsize('<'+k);m.mem_write(self.base+off,(b.word(v,k)&((1<<(8*size_))-1)).to_bytes(size_,'little'))
        m.mem_write(self.base+0x6a410,struct.pack('<I',error));self.calls+=1

code=textwrap.dedent(inspect.getsource(BASE_NATIVE.run))
code=code.replace('list(range(1,9))+[20,21,22]','list(range(1,9))+[20,21,22,23,24,25,26,27]').replace('sp+0xe8','sp+0x138').replace('self.base+0x4e77','self.base+0x16730')
begin=code.index("    for n,v in [('RSP',sp)");end=code.index('\n',begin)
code=code[:begin]+"    for n,v in [('RSP',sp),('R14',0x7ff6846f3b50),('RBP',self.base+0x5c0)]:m.reg_write(getattr(x,'UC_X86_REG_'+n),v)"+code[end:]
code=code.replace("struct.pack('<Q',m.reg_read(x.UC_X86_REG_RAX))","struct.pack('<Q',0)")
exec(compile(code,__file__,'exec'),b.__dict__);Native.run=b.run

def identity():
    current=BASE_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5';current['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in b.pub.closure(SCRIPT,src)}
    current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    current['native_dispatcher_sha256']='f5edd0f5e9033ddddb289a3419406c06292ce22bff197bea6d10acea1756c721'
    current['native_cell_setter_sha256']='1f063e2f13a8e5742dafee2b70de1ad0c6419448ba27c60cc84cb28b33a9ebab';return current
for name in ['execute','main']:
    code=inspect.getsource(getattr(b,name)).replace('Bot1StartupTailCheck','Bot1DispatchTailCheck').replace('bot1-startup-tail','bot1-dispatch-tail').replace('startup-tail-','dispatch-tail-')
    code=code.replace('Three panel children recorded with supplied changes; their bodies have separate evidence. Not full initialization or EA.','Open/closed panel bodies recorded with supplied changes; row setter and formatting arguments run. Caller string-copy/time registers supplied. Not a complete dispatcher or EA.')
    exec(compile(code,__file__,'exec'),b.__dict__)
b.cases=cases;b.encode=encode;b.render=render;b.generate=generate;b.Native=Native;b.identity=identity
b.SCOPE=dict(b.SCOPE,native_startup_tail_executed=False,native_dispatcher_tail_executed=True,native_history_scan_executed=False,native_panel_row_setter_executed=True,authorization_executed=False,authorization_entry_guarded=True)
if __name__=='__main__':b.main()
