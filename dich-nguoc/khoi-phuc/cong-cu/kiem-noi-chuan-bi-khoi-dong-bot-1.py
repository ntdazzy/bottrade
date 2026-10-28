"""Run the real first preparation and OnInit tail continuously, 0x3c9d..0x5658.

Extends the existing join recorder, preserving its service protocol and checks.
generate | prepare|mql5 --build BUILD|original|compare RUN.
"""
import argparse,copy,hashlib,importlib.util,json,re,shutil,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
j=module('preparation_join',ROOT/'cong-cu/kiem-noi-khoi-dong-bot-1.py')
full=module('preparation_contract',ROOT/'bot-cua-toi-1/tests/check-preparation-full.py')
require,sha,boot=j.require,j.sha,j.boot
OLD_FIELDS=list(j.FIELDS);OLD_CASES=j.cases;OLD_ENCODE=j.encode;OLD_RENDER=j.render;OLD_IDENTITY=j.identity
INPUTS=[('indicator_period','i',0x621c4),('indicator_day','B',0x621c8)]+full.legacy.fields(full.legacy.INPUTS,1)+[(n,k,r) for n,k,r,*_ in full.EXTRA]+[('comment','s',0x622d0)]
INPUTS=[('Inputs.'+('variable_distances' if n=='use_variable' else n),k,r) for n,k,r in INPUTS]
OUTPUTS=[('P.'+n,k,r) for n,k,r in full.legacy.fields(full.legacy.OUTPUTS,1)]+[('P.'+n,k,r) for _,_,_,n,k,r in full.EXTRA]+[('P.'+n,k,r) for n,k,r in full.TAIL]
OUTPUTS += [('P.tick.'+n,k,0x67750+off) for n,k,off in [('time','q',0),('last','d',24),('volume','Q',32),('time_msc','q',40),('flags','I',48),('volume_real','d',56)]]
OUTPUTS += [('P.calendar.'+n,'i',0x67790+i*4) for i,n in enumerate(['year','mon','day','hour','min','sec','day_of_week','day_of_year'])]
ALIASES={}
for n,k,r in INPUTS+OUTPUTS:
    found=next((f for f in j.FIELDS if f[2]==r),None)
    if found:
        require(found[1]==k,'FIELD_TYPE_CHANGED '+n)
        if found[0]!=n:ALIASES[n]=found[0]
    else:j.FIELDS.append((n,k,r))
PREP_SHA='8679070031fe7f3309378147c8afc4bf2d4ab596b3ee22a73e8e6386db6c9d0d'
BASE_CALL=j.CALL
CALL=BASE_CALL.replace('Bot1InitializeStartupPostPreparation','Bot1InitializeStartupPreparationFlow')

def cases():
    defaults=full.legacy.base_case(1);out=[];seed=OLD_CASES()[0]
    def add(tag,changes=None,**replies):
        c=copy.deepcopy(seed);c.update(id=len(out),tag=tag,effects=[])
        for n,k,r in INPUTS:
            name=n.removeprefix('Inputs.');name='use_variable' if name=='variable_distances' else name
            value=defaults.get(name,1 if k=='B' else .25 if k=='d' else 1)
            if n=='Inputs.comment':value='prepared'
            if n=='Inputs.indicator_period':value=30
            if n=='Inputs.native_6a740':value=.123
            c['values'][ALIASES.get(n,n)]=value
        for n,k,r in OUTPUTS:
            key=ALIASES.get(n,n)
            if key not in c['values']:c['values'][key]=-.75 if k=='d' else 7
        c['values']['P.indicator_handle']=-91
        c['values']['OrderComment']='orders'
        c['values']['Show']=1;c['values']['Panel.closed_star']=1
        c['prep']=dict(handle=17,copied=3,count=3,sample=2000.,tick_ok=1,tick_write=1,hour=13,now=1790000123)
        c['prep'].update(replies)
        for n,v in (changes or {}).items():c['values'][ALIASES.get(n,n)]=v
        out.append(c);return c
    for day in [0,1,255]:
        for variable in [0,1,255]:
            for adjust in [0,1]:
                for digits in [1,2,3,5]:
                    c=add('preparation-scale-and-digits',{'Inputs.indicator_day':day,'Inputs.variable_distances':variable,'Inputs.adjust_lots':adjust})
                    c['integers'][2]=[digits]*8
    for n,values in [('Inputs.reference',[-1.,0.,.5,1000.]),('Inputs.native_6a740',[-.123,-0.,.01,.199,100.]),
                     ('Inputs.stop_distance',[-1.,0.,.1,1.]),('Inputs.target_distance',[-1.,0.,.1,1.]),
                     ('Inputs.expiration_hours',[-2147483648,-1,0,1,2147483647]),('Inputs.virtual_expiration',[0,1,255]),
                     ('Inputs.entry.older_width',[-1,0,1,5]),('Inputs.entry.recent_width',[-1,0,1,5])]:
        for v in values:add('preparation-boundary-'+n,{n:v})
    for handle in [-17,-1]:add('preparation-indicator-failure',handle=handle)
    add('preparation-copy-zero',copied=0)
    for copied in [-1,2,3,4]:add('preparation-array-size',copied=copied,count=max(copied,2))
    for ok,write in [(0,0),(0,1),(1,1)]:add('preparation-tick-failure',tick_ok=ok,tick_write=write)
    for order in [None,'','Order','Vàng🚀']:
        for comment in [None,'','Prepared','Khác🚀']:add('three-comment-locations',{'OrderComment':order,'Inputs.comment':comment,'P.comment':'old'})
    for guard in [0,1,2,255]:
        for queue in [0,1,2,255]:add('preparation-table-flags',{'Manager.table.guard':guard,'Queue.enabled':queue})
    for show in [0,1,255]:
        for star in [0,1,2]:add('preparation-panel-gates',{'Show':show,'Panel.closed_star':star})
    for api,n,v in [(30,'Inputs.native_6a740',.199),(31,'Inputs.variable_distances',0),(32,'Inputs.comment',None),
                    (33,'P.calendar.hour',23),(34,'Inputs.min_change',.5),(35,'P.strategy_index',7)]:
        if isinstance(v,str) or v is None:continue
        c=add('preparation-live-field');c['effects']=[[api,1,next(i for i,f in enumerate(j.FIELDS) if f[0]==ALIASES.get(n,n)),v]]
    return out

def encode(rows):
    raw=bytearray(struct.pack('<3i',j.MAGIC,1,len(rows)))
    for c in rows:
        raw+=OLD_ENCODE([c])[12:];r=c['prep']
        raw+=struct.pack('<8Q',r['handle']&j.MASK,r['copied']&j.MASK,r['count'],boot.bits(r['sample']),r['tick_ok'],r['tick_write'],r['hour']&j.MASK,r['now']&j.MASK)
    return bytes(raw)

DECL=r'''
int PrepATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period);
int PrepCopy(const int handle,const int buffer,const int start,const int count,double &values[]);
bool PrepTick(const string symbol,MqlTick &tick);
datetime PrepTime(MqlDateTime &calendar);datetime PrepTime();
double PrepDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop);
long PrepInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);
void PrepPrint(const string value);void PrepPrint(const string value,const int error);
#define iATR PrepATR
#define CopyBuffer PrepCopy
#define SymbolInfoTick PrepTick
#define TimeCurrent PrepTime
#define SymbolInfoDouble PrepDouble
#define SymbolInfoInteger PrepInteger
#define Print PrepPrint
#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"
#undef iATR
#undef CopyBuffer
#undef SymbolInfoTick
#undef TimeCurrent
#undef SymbolInfoDouble
#undef SymbolInfoInteger
#undef Print
'''
MOCKS=r'''
int PrepHandle,PrepCopied,PrepCount,PrepTickOk,PrepTickWrite,PrepHour,PrepDPos,PrepIPos[3];double PrepSample;long PrepNow;
void PrepArraySnapshot(){int n=ArraySize(P.indicator_values);Word((ulong)n);Word((ulong)ArrayGetAsSeries(P.indicator_values));for(int i=0;i<n;i++)Word(Bits(P.indicator_values[i]));}
int PrepATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period){Begin();End(30,(ulong)frame,(ulong)(long)period,(ulong)(long)PrepHandle,0,symbol);Effect(30);return PrepHandle;}
int PrepCopy(const int handle,const int buffer,const int start,const int count,double &values[]){Begin();End(31,(ulong)(long)handle,(ulong)(long)buffer,(ulong)(long)start,(ulong)(long)count);Word((ulong)(long)PrepCopied);Word((ulong)PrepCount);Word(Bits(PrepSample));if(PrepCopied!=0){ArraySetAsSeries(values,false);ArrayResize(values,PrepCount);for(int i=0;i<PrepCount;i++)values[i]=PrepSample+(double)i*.125;}Effect(31);return PrepCopied;}
bool PrepTick(const string symbol,MqlTick &tick){Begin();End(32,(ulong)PrepTickOk,(ulong)PrepTickWrite,0,0,symbol);if(PrepTickWrite!=0){tick.time=(datetime)PrepNow;tick.bid=2000.;tick.ask=2002.;tick.last=2001.;tick.volume=31;tick.time_msc=PrepNow*1000;tick.flags=7;tick.volume_real=31.5;}Effect(32);return PrepTickOk!=0;}
datetime PrepTime(MqlDateTime &calendar){Begin();End(33,(ulong)PrepNow,(ulong)(long)PrepHour);calendar.year=2026;calendar.mon=10;calendar.day=28;calendar.hour=PrepHour;calendar.min=17;calendar.sec=19;calendar.day_of_week=3;calendar.day_of_year=300;Effect(33);return (datetime)PrepNow;}
datetime PrepTime(){Begin();End(36,(ulong)PrepNow);Effect(36);return (datetime)PrepNow;}
double PrepDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop){Begin();int n=PrepDPos++;double value=Doubles[0][n<8 ? n : 7];End(34,(ulong)prop,Bits(value),0,0,symbol);Effect(34);return value;}
long PrepInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();int p=prop==SYMBOL_TRADE_STOPS_LEVEL ? 0 : (prop==SYMBOL_TRADE_FREEZE_LEVEL ? 1 : 2);int n=PrepIPos[p]++;long value=Integers[p][n<8 ? n : 7];End(35,(ulong)prop,(ulong)value,0,0,symbol);Effect(35);return value;}
void PrepPrint(const string value){Begin();End(37,1,0,0,0,value);Effect(37);}
void PrepPrint(const string value,const int error){Begin();End(37,2,(ulong)(long)error,0,0,value);Effect(37);}
'''

def render():
    code=OLD_RENDER().replace('#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"',DECL,1)
    code=code.replace('Counts[23]','Counts[38]')
    code=code.replace('#include "../../Include/bot-cua-toi-1/Bot1StartupPostPreparation.mqh"','#include "../../Include/bot-cua-toi-1/Bot1StartupPreparationFlow.mqh"')
    code=code.replace('void Snapshot()', 'void PrepArraySnapshot();\nvoid Snapshot()',1).replace('Word(TablesHash());','PrepArraySnapshot();Word(TablesHash());',1)
    code=code.replace('int OnStart()',MOCKS+'\nint OnStart()',1)
    marker='for(int i=0;i<8;i++)TailTimes[i]=FileReadLong(file);Selected=-1;'
    require(marker in code,'PREPARATION_READ_MARKER')
    reads='PrepHandle=(int)FileReadLong(file);PrepCopied=(int)FileReadLong(file);PrepCount=(int)FileReadLong(file);PrepSample=Value((ulong)FileReadLong(file));PrepTickOk=(int)FileReadLong(file);PrepTickWrite=(int)FileReadLong(file);PrepHour=(int)FileReadLong(file);PrepNow=FileReadLong(file);\n'
    reads+='ArraySetAsSeries(P.indicator_values,false);ArrayResize(P.indicator_values,2);P.indicator_values[0]=-11.;P.indicator_values[1]=-12.;PrepDPos=0;ArrayInitialize(PrepIPos,0);\n'
    reads+=''.join(a+'='+b+';\n' for a,b in ALIASES.items())
    code=code.replace(marker,marker+'\n'+reads).replace(BASE_CALL,CALL)
    code=code.replace('P.tick.time=FileReadLong(file)','P.tick.time=(datetime)FileReadLong(file)').replace('P.tick.time=(long)v','P.tick.time=(datetime)v')
    return code

class Native(j.Native):
    def __init__(self):
        super().__init__();self.prep_phase=False;self.started=False;self.prep_calls=0
        raw=bytes(self.m.mem_read(self.base+0x7500,0x831d-0x7500));require(hashlib.sha256(raw).hexdigest()==PREP_SHA,'PREPARATION_CHANGED')
        self.prep_sdk={0x7ff6846d49f0:30,0x7ff6846deec0:31,0x7ff6846e2c10:32,0x7ff6846f1c40:33,0x7ff6846e2890:34,0x7ff6846e2970:35}
        for address in [0x7ff6846deec0,0x7ff6846e2c10]:
            if not any(a<=address<=b for a,b,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3');self.sdk[address]=self.prep_sdk[address]
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.begin_preparation,begin=self.base+0x3cab,end=self.base+0x3cab)
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        for i in Cs(CS_ARCH_X86,CS_MODE_64).disasm(raw,self.base+0x7500):
            if i.mnemonic in self.cpu:
                self.arithmetic[i.address]=(i.mnemonic,i.op_str);self.m.hook_add(self.uc.UC_HOOK_CODE,self.calculate,begin=i.address,end=i.address)
    def begin_preparation(self,m,address,size,user):
        for api in range(30,38):self.counts.setdefault(api,0)
        if not self.started:
            self.started=True;self.prep_phase=True
            m.reg_write(self.x.UC_X86_REG_RIP,self.base+0x3c9d)
            desc=self.base+0x62190;m.mem_write(desc,bytes(36));m.mem_write(desc+2,struct.pack('<H',1));m.mem_write(desc+8,struct.pack('<I',2));m.mem_write(desc+28,struct.pack('<Q',0x70100000));m.mem_write(0x70100000,struct.pack('<2d',-11.,-12.))
        else:self.prep_phase=False
    def values(self,fields):
        raw=super().values(fields)
        if fields is j.FIELDS:
            m=self.m;desc=self.base+0x62190;n=struct.unpack('<I',m.mem_read(desc+8,4))[0];flags=struct.unpack('<H',m.mem_read(desc+2,2))[0];pointer=struct.unpack('<Q',m.mem_read(desc+28,8))[0]
            require(n<=4,'PREP_ARRAY_SIZE');values=[bytes(m.mem_read(pointer+8*i,8)) for i in range(n)]
            if flags&16:values.reverse()
            raw+=struct.pack('<2Q',n,int(bool(flags&16)))+b''.join(values)
        return raw
    def service(self,m,address,size,user):
        if not self.prep_phase:return super().service(m,address,size,user)
        require(address in self.prep_sdk,'UNKNOWN_PREP_API '+hex(address));api=self.prep_sdk[address];x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));sp=reg('RSP')
        if api==30 and reg('RDX')==2:api=37
        if api==33 and reg('RDX')==0:api=36
        r=self.tape;expected=r.block();actual=self.state()
        require(expected==actual,'PREP_STATE '+str((self.case['id'],api,next((i for i,(a,b) in enumerate(zip(expected,actual)) if a!=b),None))))
        kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I');require(kind==api,'PREP_API_ORDER')
        require(reg('RCX')==self.gate['ctx'],'PREP_CONTEXT');reply=0
        if api==30:
            desc=struct.unpack('<Q',m.mem_read(sp+0x28,8))[0];frame=struct.unpack('<I',m.mem_read(sp+0x38,4))[0];period=struct.unpack('<i',m.mem_read(sp+0x48,4))[0]
            require(reg('RDX')==0x53 and args[:2]==[frame,period&j.MASK] and texts==[self.read_text(desc),None],'ATR_ARGS');reply=args[2]
        elif api==31:
            count=struct.unpack('<I',m.mem_read(sp+0x28,4))[0];desc=struct.unpack('<Q',m.mem_read(sp+0x30,8))[0]
            require(args==[reg('RDX')&0xffffffff,reg('R8'),reg('R9'),count] and desc==self.base+0x62190,'COPY_ARGS')
            reply,n,sample=r.take('3Q');require(n<=4,'COPY_SIZE')
            if reply:
                m.mem_write(desc+2,struct.pack('<H',1));m.mem_write(desc+8,struct.pack('<I',n));m.mem_write(desc+28,struct.pack('<Q',0x70100000))
                m.mem_write(0x70100000,b''.join(struct.pack('<d',boot.number(sample)+i*.125) for i in range(n)))
        elif api==32:
            require(reg('R8')==self.base+0x67750 and texts==[self.read_text(reg('RDX')),None],'TICK_ARGS');reply=args[0]
            if args[1]:
                now=self.case['prep']['now'];m.mem_write(reg('R8'),struct.pack('<q3dQqI4xd',now,2000.,2002.,2001.,31,now*1000,7,31.5))
        elif api==33:
            require(reg('RDX')==self.base+0x67790,'CALENDAR_ARGS');reply=args[0];m.mem_write(reg('RDX'),struct.pack('<8i',2026,10,28,struct.unpack('<i',struct.pack('<I',args[1]&0xffffffff))[0],17,19,3,300))
        elif api in [34,35]:
            require(reg('R8')==args[0] and texts==[self.read_text(reg('RDX')),None],'PREP_PROPERTY_ARGS');reply=args[1]
            if api==34:require(args[0]==16,'PREP_POINT_PROPERTY');m.mem_write(self.base+0x6a448,struct.pack('<Q',reply))
        elif api==36:reply=args[0]
        elif api==37:
            desc=struct.unpack('<Q',m.mem_read(sp+0x28,8))[0]
            require((reg('RDX'),reg('R8'),reg('R9'))==(2,args[0],0x590008) and texts==[self.read_text(desc),None],'PREP_PRINT_ARGS')
            if args[0]==2:require(struct.unpack('<I',m.mem_read(sp+0x38,4))[0]==args[1]&0xffffffff,'PREP_PRINT_ERROR')
        self.counts[api]+=1;self.effect(api);self.calls+=1;self.prep_calls+=1
        m.mem_write(self.base+0x6a410,struct.pack('<I',error))
        if api!=34:m.reg_write(x.UC_X86_REG_RAX,reply)
    def effect(self,api):
        self.counts.setdefault(api,0)
        return super().effect(api)
    def run(self,c,tape):
        self.started=False;self.prep_phase=False;self.prep_calls=0
        # Parent creates counters at run start; the first native hook adds the new IDs.
        return super().run(c,tape)

def identity():
    old=OLD_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupPreparationFlowCheck.mq5'
    old['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in j.pub.closure(script,src)}
    old['helpers_sha256'].update({Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__)),Path(full.__file__).relative_to(ROOT).as_posix():sha(Path(full.__file__)),Path(full.legacy.__file__).relative_to(ROOT).as_posix():sha(Path(full.legacy.__file__))})
    old['native_preparation_sha256']=PREP_SHA;return old

# Keep the established runner and immutable evidence format; change only the
# script/folder names needed for this continuous range, in this module instance.
for name in ['execute','main']:
    import inspect
    code=inspect.getsource(getattr(j,name)).replace('Bot1StartupPostPreparationCheck','Bot1StartupPreparationFlowCheck').replace('bot1-startup-joined','bot1-startup-preparation-flow').replace('startup-joined-','startup-preparation-flow-')
    code=code.replace('Continuous after first preparation through normal return only.','Continuous first preparation through normal OnInit return.').replace('earlier OnInit and full EA remain unverified.','OnInit before the first preparation and full EA remain unverified.')
    exec(compile(code,__file__,'exec'),j.__dict__)
j.cases=cases;j.encode=encode;j.render=lambda:render().replace('bot1-startup-joined','bot1-startup-preparation-flow')
j.identity=identity;j.Native=Native
j.SCOPE=dict(j.SCOPE,native_first_preparation_executed=True,native_continuous_post_preparation_executed=True,preparation_returns_do_not_stop_oninit=True)

class FatalNative(Native):
    def __init__(self):
        super().__init__();self.fatal=0;address=0x7ff683f20000+0x3959a0
        if not any(a<=address<=b for a,b,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.stop_fatal,begin=address,end=address)
    def stop_fatal(self,m,address,size,user):
        self.fatal=m.reg_read(self.x.UC_X86_REG_RDX);m.emu_stop()

def errors():
    p=argparse.ArgumentParser();p.add_argument('mode');p.add_argument('run');p.add_argument('--build',required=True);a=p.parse_args()
    require(all(re.fullmatch('[a-z0-9-]{1,40}',v) for v in [a.run,a.build]),'BAD_ERROR_RUN')
    home=ROOT/'bot-cua-toi-1';src=home/'source/MQL5';mt=ROOT.parent/'.local/mt5-bot1-thread-20261025'
    receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));current=identity()
    script='Scripts/bot-cua-toi-1/Bot1StartupPreparationFlowCheck.mq5'
    require(build['target']==script and build['errors']==build['warnings']==0 and build['floating_point_dividers_check_requested'],'ERROR_BUILD_NOT_CLEAN')
    for n,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==digest,'ERROR_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'ERROR_BINARY_CHANGED')
    out=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;out.mkdir(parents=True,exist_ok=False);checks=[]
    for tag,short in [('short-zero',0),('short-one',1),('zero-unit',-1)]:
        c=cases()[0];c['tag']=tag
        if short>=0:c['prep'].update(copied=-1,count=short)
        else:c['doubles'][0]=[0.]*8
        namespace=a.run+'-'+tag;folder=out/tag;folder.mkdir();raw=encode([c]);(folder/'cases.bin').write_bytes(raw);j.save(folder/'cases.json',[c])
        files=mt/'MQL5/Files/bot1-startup-preparation-flow'/namespace;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('prep-flow-error-'+namespace+'.set');ini=mt/('prep-flow-error-'+namespace+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+namespace+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1StartupPreparationFlowCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        logs={p:p.stat().st_size for d in [mt/'MQL5/Logs',mt/'logs'] if d.is_dir() for p in d.glob('*.log')}
        process=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('ERROR_MT5_TIMEOUT')
        lines=[]
        for d in [mt/'MQL5/Logs',mt/'logs']:
            for p in d.glob('*.log'):
                rawlog=p.read_bytes();start=logs.get(p,0);lines.extend(v for v in rawlog[start if start<=len(rawlog) else 0:].decode('utf-16-le',errors='replace').splitlines() if 'array out of range' in v.lower() or 'zero divide' in v.lower())
        expected='array out of range' if short>=0 else 'zero divide'
        require(code in [-1,0xffffffff] and not (files/'script-status.bin').exists() and any(expected in v.lower() for v in lines),'ERROR_CLASS_NOT_OBSERVED')
        require((files/'mql5-results.bin').read_bytes()==struct.pack('<3i',j.MAGIC,1,1),'ERROR_WROTE_NORMAL_RESULT')
        tape=(files/'tape-0.bin').read_bytes();native=FatalNative()
        try:
            try:native.run(c,tape)
            except ValueError as error:require(str(error)=='JOIN_NOT_FINISHED' and native.fatal,'UNEXPECTED_NATIVE_ERROR '+str(error))
            require(native.fatal&0xffffffff==(0x1f6 if short>=0 else 0x1f7) and native.tape.pos==len(tape) and native.joins==0,'NATIVE_ERROR_DIFFERS')
            result=dict(tag=tag,native_code=hex(native.fatal),fatal_class=expected,exit_code=code,recorded_services_compared=native.calls,tail_not_entered=True,no_normal_result=True,exact_final_fault_state_compared=False)
        finally:native.close()
        for n in ['tape-0.bin','mql5-results.bin']:shutil.copyfile(files/n,folder/n)
        (folder/'runtime-lines.txt').write_text('\n'.join(lines)+'\n',encoding='utf-8');result['tape_sha256']=sha(folder/'tape-0.bin');result['runtime_lines_sha256']=sha(folder/'runtime-lines.txt');checks.append(result)
        j.save(folder/'verification.json',result);print(json.dumps(result),flush=True)
    j.save(out/'error-comparison.json',dict(cases=len(checks),matched=len(checks),failed=0,checks=checks,identity=current,build=a.build,build_receipt_sha256=sha(receipt),whole_bot_complete=False,full_ea=False,
      limits=['Three fatal cases only; ordered service snapshots before the fault and fatal class compared. Exact state at the fault, allocation failures and full EA remain unverified.']))

if __name__=='__main__':
    if len(sys.argv)>1 and sys.argv[1]=='errors':errors()
    else:j.main()
