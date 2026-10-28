"""Compare bot 3 time/frequency selection followed by startup context.

generate | prepare|mql5 --build BUILD|original|compare RUN.
The native selection and context execute continuously, 0x3840..0x4580.
DST and currency child replies are supplied business inputs, not authorization.
"""
import copy,ctypes,hashlib,importlib.util,inspect,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
s=importlib.util.spec_from_file_location('startup3_selection_context',ROOT/'cong-cu/kiem-ngu-canh-khoi-dong-bot-3.py');ctx=importlib.util.module_from_spec(s);s.loader.exec_module(ctx)
b=ctx.b;require,sha=b.require,b.sha
OLD_CASES=b.cases();OLD_ENCODE=b.encoded;OLD_IDENTITY=ctx.identity
EXTRA=[('WinterHours','i',0x1d7038),('SummerHours','i',0x1d7040),('AdjustedTime','q',0x75358),
 ('Frequency','i',0x1d6f90),('Risk','i',0x1d7130),('BootPanel.allowed_dd','d',0x1d7140),('VariableValues','B',0x1d6f28),
 ('BootPanel.frequency','i',0x6d21c),('FrequencyDivisor','d',0x76fa8)]
EXTRA += [(f'Thresholds[{i}]','B',0x75351+i) for i in range(3)]
EXTRA += [(f'Manual[{i}]','B',0x1d71a8+8*i) for i in range(9)]
EXTRA += [(f'Enabled[{i}]','B',0x6d220+i) for i in range(9)]
b.FIELDS += EXTRA
CALL='Bot3InitializeStartupSelectionContext(WinterHours,SummerHours,AdjustedTime,Frequency,Risk,VariableValues,Thresholds,Manual,Enabled,FrequencyDivisor,BootChartSymbol,BootInputs,BootContext,BootPreparation,BootHistory,BootPanel,BootDaily,BootState)'

def cases():
    rows=[]
    def add(tag,changes=None,**replies):
        c=copy.deepcopy(OLD_CASES[0]);c.update(id=len(rows),tag=tag,error=0)
        default=dict(WinterHours=2,SummerHours=3,AdjustedTime=-91,Frequency=5,Risk=1234,
          VariableValues=1,FrequencyDivisor=-7.,**{'BootPanel.allowed_dd':30.,'BootPanel.frequency':-17})
        for i in range(3):default[f'Thresholds[{i}]']=1
        for i in range(9):default[f'Manual[{i}]']=i%2;default[f'Enabled[{i}]']=(i+1)*17
        c['values'] += [default[n] for n,_,_ in EXTRA]
        for n,v in (changes or {}).items():c['values'][next(i for i,f in enumerate(b.FIELDS) if f[0]==n)]=v
        c['selection']=dict(summer=0,now=1790000000,balance=10000.,converted=2000.,effects=[]);c['selection'].update(replies);rows.append(c);return c
    for freq in [-2147483648,-1,0,1,2,3,4,5,6,7,2147483647]:
        for risk in [0,1234]:
            for variable in [0,1,255]:add('frequency-modes',{'Frequency':freq,'Risk':risk,'VariableValues':variable})
    for mask in range(8):
        for amount in [-1.,0.,1099.9999999999998,1100.,1100.0000000000002,1866.6666666666665,1866.6666666666667,2700.,2700.0000000000005,float('nan'),float('inf'),-float('inf')]:
            add('automatic-thresholds',{f'Thresholds[{i}]':(mask>>i)&1 for i in range(3)},converted=amount)
    for summer in [0,1]:
        for hour in [-2147483648,-1,0,24,2147483647]:
            for now in [-(1<<63),0,(1<<63)-1]:add('clock-width',{'WinterHours':hour,'SummerHours':hour,'Frequency':0},summer=summer,now=now)
    for byte in [0,1,2,255]:
        c=add('manual-byte-copies',{'Frequency':6});
        for i in range(9):c['values'][next(j for j,f in enumerate(b.FIELDS) if f[0]==f'Manual[{i}]')]=byte
    add('manual-distinct-byte-mapping',dict(Frequency=6,**{f'Manual[{i}]':11+23*i for i in range(9)}))
    for i in range(3):
        for byte in [2,255]:add('threshold-nonboolean-byte',{f'Thresholds[{i}]':byte},converted=[500.,1500.,2200.][i])
    for drawdown in [0.,-30.,float('nan'),float('inf'),-float('inf')]:add('drawdown-number-boundaries',{'BootPanel.allowed_dd':drawdown})
    for api,n,value in [(2,'SummerHours',-7),(2,'WinterHours',9),(3,'Frequency',6),(4,'BootPanel.allowed_dd',27.),(4,'VariableValues',0),(4,'Thresholds[2]',0)]:
        c=add('live-state-after-child',summer=1);c['selection']['effects']=[[api,next(i for i,f in enumerate(b.FIELDS) if f[0]==n),value]]
    c=add('live-winter-hours-after-time',summer=0);c['selection']['effects']=[[2,next(i for i,f in enumerate(b.FIELDS) if f[0]=='WinterHours'),9]]
    for old in OLD_CASES[::17]:
        c=add('selected-context-string-and-number',{'Frequency':3});c['values'][:17]=old['values'];c['texts']=old['texts']
    return rows

def encoded(rows):
    raw=bytearray(struct.pack('<3i',b.MAGIC,1,len(rows)))
    for c in rows:
        raw+=OLD_ENCODE([c])[12:];r=c['selection'];raw+=struct.pack('<4Qi',r['summer'],r['now']&b.MASK,b.bits(r['balance']),b.bits(r['converted']),len(r['effects']))
        for api,index,value in r['effects']:
            kind=b.FIELDS[index][1];raw+=struct.pack('<2iQ',api,index,b.bits(value) if kind=='d' else int(value)&b.MASK)
    return bytes(raw)

DECL=r'''
#include "../../Include/bot-cua-toi-3/Bot3AmericanDST.mqh"
#include "../../Include/bot-cua-toi-3/Bot3VolumeCurrency.mqh"
bool SelectSummer();datetime SelectNow();double SelectBalance(const ENUM_ACCOUNT_INFO_DOUBLE property);
double SelectConvert(const double amount,const string &suffix,const bool to_usd);
#define Bot3AmericanDST SelectSummer
#define TimeCurrent SelectNow
#define AccountInfoDouble SelectBalance
#define Bot3VolumeCurrency SelectConvert
#include "../../Include/bot-cua-toi-3/Bot3StartupSelectionContext.mqh"
#undef Bot3AmericanDST
#undef TimeCurrent
#undef AccountInfoDouble
#undef Bot3VolumeCurrency
'''
GLOBALS='''
int WinterHours,SummerHours,Frequency,Risk;long AdjustedTime;uchar VariableValues,Thresholds[3],Manual[9],Enabled[9];double FrequencyDivisor;
int SelectSummerReply,SelectEffectCount;long SelectNowReply;double SelectBalanceReply,SelectConvertReply;ulong SelectEffects[16][3];
'''
MOCKS=r'''
void SelectionEffect(const int api){for(int i=0;i<SelectEffectCount;i++){if((int)SelectEffects[i][0]!=api)continue;ulong v=SelectEffects[i][2];switch((int)SelectEffects[i][1]){@EFFECTS@}}}
void SelectionRecord(const int api,const ulong argument,const string value,const ulong reply){BootSnapshot(GetLastError());FileWriteInteger(BootOutput,api);FileWriteLong(BootOutput,(long)argument);BootText(value);FileWriteLong(BootOutput,(long)reply);SelectionEffect(api);}
bool SelectSummer(){SelectionRecord(1,0,NULL,(ulong)SelectSummerReply);return SelectSummerReply!=0;}
datetime SelectNow(){SelectionRecord(2,0,NULL,(ulong)SelectNowReply);return (datetime)SelectNowReply;}
double SelectBalance(const ENUM_ACCOUNT_INFO_DOUBLE property){SelectionRecord(3,(ulong)property,NULL,BootBits(SelectBalanceReply));return SelectBalanceReply;}
double SelectConvert(const double amount,const string &suffix,const bool to_usd){SelectionRecord(4,BootBits(amount),suffix,BootBits(SelectConvertReply));if(!to_usd)SetUserError(900);return SelectConvertReply;}
'''

def template():
    source=b.TEMPLATE
    # StartupContext is already bound to BootPrint in the base template.
    anchor='#undef Print\n';require(anchor in source,'SELECTION_INCLUDE_MARKER');source=source.replace(anchor,anchor+DECL,1)
    source=source.replace('string BootChartSymbol;',GLOBALS+'\nstring BootChartSymbol;',1)
    effects=''.join('case '+str(i)+':'+name+'='+('BootValue(v)' if kind=='d' else '(uchar)v' if kind=='B' else '(int)v' if kind=='i' else '(long)v')+';break;' for i,(name,kind,_) in enumerate(b.FIELDS))
    source=source.replace('int OnStart()',MOCKS.replace('@EFFECTS@',effects)+'\nint OnStart()',1)
    marker='int error=FileReadInteger(file);BootPrints=0;';require(marker in source,'SELECTION_READ_MARKER')
    reads='SelectSummerReply=(int)FileReadLong(file);SelectNowReply=FileReadLong(file);SelectBalanceReply=BootValue((ulong)FileReadLong(file));SelectConvertReply=BootValue((ulong)FileReadLong(file));SelectEffectCount=FileReadInteger(file);if(SelectEffectCount<0 || SelectEffectCount>16)return 8;for(int i=0;i<SelectEffectCount;i++){SelectEffects[i][0]=(ulong)FileReadInteger(file);SelectEffects[i][1]=(ulong)FileReadInteger(file);SelectEffects[i][2]=(ulong)FileReadLong(file);}'
    source=source.replace(marker,marker+reads)
    old='Bot3InitializeStartupContext(BootChartSymbol,BootInputs,BootContext,BootPreparation,BootHistory,BootPanel,BootDaily,BootState)'
    require(old in source,'SELECTION_CALL_MARKER');return source.replace(old,CALL).replace('bot3-startup-context','bot3-startup-selection-context')

class Native(ctx.Native):
    def __init__(self):
        super().__init__();self.selection_calls=0;self.div_count=0
        self.selection_apis={self.base+0x7e20:1,0x7ff6846f1c40:2,0x7ff6846b7370:3,self.base+0x8300:4}
        for address in [0x7ff6846b7370]:
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        for address in [self.base+0x7e20,self.base+0x8300]:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.start_selection,begin=self.base+0x3ce6,end=self.base+0x3ce6)
        self.div_address=self.host.address+512;code=b.history.HostAddition.CODE.replace(bytes.fromhex('f20f58c1'),bytes.fromhex('f20f5ec1'));ctypes.memmove(self.div_address,code,len(code));self.divide=ctypes.WINFUNCTYPE(ctypes.c_uint64,ctypes.c_uint64,ctypes.c_uint64)(self.div_address)
        require(self.divide(b.bits(6.),b.bits(2.))==b.bits(3.),'HOST_DIV_CALIBRATION')
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.budget_math,begin=self.base+0x390d,end=self.base+0x390d);self.m.hook_add(self.uc.UC_HOOK_CODE,self.budget_math,begin=self.base+0x3911,end=self.base+0x3911)
        self.products[0x3911]=('XMM1','reg','XMM0')
        require(struct.unpack('<4d',self.m.mem_read(self.base+0x57ca0,32))==(100.,810.,560.,330.),'SELECTION_THRESHOLDS_CHANGED')
    def start_selection(self,m,address,size,user):
        if self.selection_started:return
        self.selection_started=True;x=self.x
        m.reg_write(x.UC_X86_REG_RAX,self.base+0x7e20);m.reg_write(x.UC_X86_REG_RBP,0x7ff6846f1c40);m.reg_write(x.UC_X86_REG_RDI,self.gate['ctx']);m.reg_write(x.UC_X86_REG_RIP,self.base+0x3840)
    def budget_math(self,m,address,size,user):
        if address==self.base+0x3911:return self.multiply(m,address,size,user)
        left=m.reg_read(self.x.UC_X86_REG_XMM1);right=struct.unpack('<Q',m.mem_read(m.reg_read(self.x.UC_X86_REG_RDI),8))[0]
        m.reg_write(self.x.UC_X86_REG_XMM1,(left&~b.MASK)|self.divide(left&b.MASK,right));m.reg_write(self.x.UC_X86_REG_RIP,address+size);self.div_count+=1
    def call(self,m,address,size,user):
        api=self.selection_apis.get(address)
        if api is None:return super().call(m,address,size,user)
        x=self.x;reg=lambda name:m.reg_read(getattr(x,'UC_X86_REG_'+name));r=self.case['selection'];reply=r[{1:'summer',2:'now',3:'balance',4:'converted'}[api]]
        if api in [2,3]:require(reg('RCX')==self.gate['ctx'],'SELECTION_CONTEXT')
        if api==2:require(reg('RDX')==0,'SELECTION_TIME_OVERLOAD')
        if api==3:require(reg('RDX')==37,'SELECTION_BALANCE_PROPERTY')
        argument=0 if api in [1,2] else 37 if api==3 else reg('XMM0')&b.MASK
        if api==4:require(argument==b.bits(r['balance']),'SELECTION_CONVERSION_AMOUNT')
        value=None if api!=4 else self.read_text(self.base+0x6d230);word=b.bits(reply) if api in [3,4] else int(reply)&b.MASK
        self.events+=self.state()+struct.pack('<iQ',api,argument)+b.text(value)+struct.pack('<Q',word);self.selection_calls+=1
        for target,index,new in r['effects']:
            if target==api:
                _,kind,off=b.FIELDS[index];size_=struct.calcsize('<'+kind);bits=b.bits(new) if kind=='d' else int(new)&((1<<(8*size_))-1);m.mem_write(self.base+off,bits.to_bytes(size_,'little'))
        if api==3:m.mem_write(self.base+0x1d6e48,struct.pack('<Q',word))
        elif api==4:m.reg_write(x.UC_X86_REG_XMM0,word)
        else:m.reg_write(x.UC_X86_REG_RAX,word)
        if api in [1,4]:
            sp=reg('RSP');target=struct.unpack('<Q',m.mem_read(sp,8))[0];m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,target)
    def run(self,c):self.selection_started=False;return super().run(c)

def identity():
    current=OLD_IDENTITY();src=ROOT/'bot-cua-toi-3/source/MQL5';script=src/'Scripts/bot-cua-toi-3/Bot3StartupSelectionContextCheck.mq5'
    current['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in b.pub.closure(script,src)};current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__));return current

original=importlib.util.spec_from_file_location('selection_runner_original',ROOT/'cong-cu/kiem-ngu-canh-khoi-dong-bot-1.py');runner=importlib.util.module_from_spec(original);original.loader.exec_module(runner)
for function in ['generate','main']:
    source=inspect.getsource(getattr(runner,function)).replace('Bot1StartupContextCheck','Bot3StartupSelectionContextCheck').replace('Bot1','Bot3').replace('bot1-startup-context','bot3-startup-selection-context').replace('bot1','bot3').replace('bot-cua-toi-1','bot-cua-toi-3')
    source=source.replace('Caller live-in XMM6=0 and non-null string-return buffer supplied','DST/currency child results and a non-null string-return buffer supplied')
    source=source.replace('host_mulsd=o.mul_count','host_mulsd=o.mul_count,host_divsd=o.div_count,selection_calls=o.selection_calls')
    exec(compile(source,__file__,'exec'),b.__dict__)
b.TEMPLATE=template();b.cases=cases;b.encoded=encoded;b.Native=Native;b.identity=identity
b.SCOPE=dict(b.SCOPE,frequency_selection_executed=True,adjusted_time_computation_executed=True,dst_child_reply_supplied=True,currency_child_reply_supplied=True)
if __name__=='__main__':b.main()
