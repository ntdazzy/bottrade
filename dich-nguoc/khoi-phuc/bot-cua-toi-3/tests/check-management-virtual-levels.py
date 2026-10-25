"""Compare virtual-start and virtual-take segments, with supplied child/API replies.
prepare -> compile Bot3ManagementVirtualLevelsCheck -> original/mql5 -> compare.
Only the private bot3 terminal is used; this is not a full EA comparison.
"""
import argparse,copy,itertools,json,math,re,shutil,struct,subprocess
from pathlib import Path
import importlib.util
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
V_PATH=HOME/'tests/check-management-virtual.py'
v=module('levels3_virtual',V_PATH);pre=v.pre
CPU_PATH=ROOT/'cong-cu/doi-chieu-nan-quan-ly.py'
cpu=module('levels3_cpu',CPU_PATH)
MAGIC=0x4d564c33;MASK=(1<<64)-1
INTS=['id','buy','stage','scenario','delay_pass','modify_ok','tick_ok','changed','strategy_index','digits0','digits1','digits2','delay_seconds']
DOUBLES=['open','sl','tp','volume','unit','stop','distance','start','level','take','stop_level','take_level','point','minimum','bid','ask','tick_bid','tick_ask','table_volume','anchor','freeze']
CASE=struct.Struct('<13iq21d');RESULT=struct.Struct('<4i12QiQ')
FIELDS=['id','closed','changed','index','initial_stop','initial_take','current_stop','current_take','last_sl','tp','bid','ask','unit','stop','distance','freeze','calls','ordered_hash']
ANALYSIS=v.ANALYSIS;CONTRACT=HOME/'phan-tich/dong-vi-the/management-virtual-levels-20261025-r1/contract.md'
MT=v.MT
NAMES=[n for n in v.NAMES if not n.endswith(('Bot3ManagementVirtual.mqh','Bot3ManagementVirtualCheck.mq5'))]+[
 'Include/bot-cua-toi-3/'+n for n in ['Bot3ManagementVirtualStart.mqh','Bot3ManagementVirtualTake.mqh','Bot3VirtualStops.mqh']]+['Scripts/bot-cua-toi-3/Bot3ManagementVirtualLevelsCheck.mq5']
SCOPE=dict(slice_only=True,whole_manager_complete=False,whole_bot_complete=False,helper_children_intercepted=True,original_bytes_changed=False)
LIMITS=['Only virtual-start and virtual-take segments; no complete manager, EA or paired terminal comparison.',
 'Stop/take/delay/modify/stamp/close helpers are intercepted at their original call boundaries; API replies are supplied.',
 'Try-close forwarding values are verified on the MQL5 side. Valid volume indices are a precondition.',
 'Both-NaN scalar results use measured Windows SSE2 fixtures; all other original instructions execute in Unicorn. No full physical original run or MXCSR status comparison.']
sha,require,save=v.sha,v.require,v.save
def cases():
    out=[]
    nan=lambda n:struct.unpack('<d',struct.pack('<Q',n))[0]
    numbers=[-math.inf,-1e19,-100.125,-0.,0.,.01,100.123456789,1e19,math.inf,nan(0x7ff8000000000123),nan(0xfff8000000000456)]
    def add(c,group):c.update(id=len(out),group=group);out.append(c)
    for buy,stage in itertools.product([0,1],[0,4]):
        b=dict(id=0,buy=buy,stage=stage,scenario=0,delay_pass=1,modify_ok=1,tick_ok=1,changed=0,strategy_index=2,
          digits0=3,digits1=3,digits2=3,delay_seconds=7,ticket=7,open=100.,sl=95. if buy else 105.,tp=130. if buy else 70.,volume=.1,
          unit=1.,stop=10.,distance=3.,start=2.,level=97. if buy else 103.,take=120. if buy else 80.,
          stop_level=98. if buy else 102.,take_level=120. if buy else 80.,point=.01,minimum=.01,
          bid=100.,ask=101.,tick_bid=100.25,tick_ask=101.5,table_volume=.1,anchor=115. if buy else 85.,freeze=2.5)
        add(dict(b),'normal')
        for key in (['stop_level','take_level','sl','point','bid','ask'] if stage==0 else ['distance','start','unit','take','anchor','table_volume','volume','minimum','point','bid','ask']):
            for number in numbers:c=dict(b);c[key]=number;add(c,'numeric-'+key)
        for key in ['stop_level','take_level'] if stage==0 else ['take','anchor']:
            for number in [99.99,100.,100.01,100.99,101.,101.01]:c=dict(b);c[key]=number;add(c,'gate-'+key)
        for digits in [[0,1,2],[2,8,3],[11,10,9],[-1,0,1],[-2147483648,2147483647,12]]:
            c=dict(b);c.update(zip(['digits0','digits1','digits2'],digits));c['stop_level']+=.123456789;add(c,'digits-separate')
        for scenario in [1,2,3,4,5,6,7,11,103,203,303]:
            for changed in [0,1]:c=dict(b);c.update(scenario=scenario,changed=changed);add(c,'api-mutation')
        for ticket in [0,1,(1<<53)+1,(1<<63)-1,-(1<<63),-1]:c=dict(b);c['ticket']=ticket;add(c,'ticket64')
        if stage==0:
            for delay,modify,tick in itertools.product([0,1],repeat=3):
                c=dict(b);c.update(delay_pass=delay,modify_ok=modify,tick_ok=tick);add(c,'helper-replies')
            for hit in ['stop','take']:
                for ok,scenario in itertools.product([0,1],[0,7,11]):
                    c=dict(b);c.update(tick_ok=ok,scenario=scenario)
                    c['stop_level' if hit=='stop' else 'take_level']=101. if buy else 100.
                    add(c,'hit-'+hit)
            for seconds in [-2147483648,-1,0,2147483647]:c=dict(b);c['delay_seconds']=seconds;add(c,'delay-int32')
        else:
            for minimum,volume,tvol in itertools.product([-.01,-0.,0.,.01],[0.,.1,math.inf],[.1,math.inf,nan(0x7ff8000000000789)]):
                c=dict(b);c.update(minimum=minimum,volume=volume,table_volume=tvol);add(c,'zero-volume-gates')
            for scenario in [0,3,4,103,203,303]:
                c=dict(b);c.update(scenario=scenario,minimum=0.);add(c,'close-after-update')
            for keys in [('start','anchor'),('unit','distance'),('unit','start')]:
                c=dict(b);c.update(zip(keys,[nan(0x7ff8000000000123),nan(0xfff8000000000456)]));add(c,'nan-operand-order')
    return out
def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(CASE.pack(*(c[n] for n in INTS),c['ticket'],*(c[n] for n in DOUBLES)) for c in rows)
def identity():
    old=v.identity()
    return dict(original_ex5_sha256=old['original_ex5_sha256'],tool_sha256=sha(Path(__file__)),analysis_sha256=sha(ANALYSIS/'analysis.json'),
     contract_sha256=sha(CONTRACT),probe_sha256=sha(cpu.PROBE),helpers_sha256={str(p.relative_to(ROOT)):sha(p) for p in [CPU_PATH,V_PATH,ROOT/'bot-cua-toi-3/tests/check-management-prelude.py',ROOT/'bot-cua-toi-1/tests/check-management-prelude.py',ROOT/'bot-cua-toi-1/tests/check-management-virtual-start.py']}|old['helpers_sha256'],
     sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES})
class Original(v.Original):
    def __init__(self,fixture):
        super().__init__();m=self.m
        eb=next(a for a,k in self.apis.items() if k==4)-0x7c2890
        for rva,api in [(0x7c2970,3),(0x7c2c10,7)]:
            a=eb+rva
            if a in self.apis:self.apis[a]=api
            else:
                if not any(lo<=a<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(a&~4095,4096)
                self.apis[a]=api;m.mem_write(a,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        for rva,api in [(0x47f10,1),(0x482b0,11),(0x484c0,2),(0x32a90,5),(0x48560,6)]:
            a=self.base+rva;self.apis[a]=api;m.hook_add(self.uc.UC_HOOK_CODE,self.child,begin=a,end=a)
        m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x35d65,end=self.base+0x35f8e)
        self.nan=cpu.BothNaN(self,json.loads((ANALYSIS/'analysis.json').read_text()),fixture)
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        if off in {0:[0x35f8f,0x3a21a],4:[0x364e2,0x3a803]}[self.case['stage']]:self.stopped=True;m.emu_stop()
    def changed(self,api):
        scenario=self.case['scenario'];target=scenario%100
        if target!=api:return
        if scenario>=100:
            if self.digit_count!=scenario//100:return
        for rva,delta in [(0x6d670,1.25),(0x724a0,2.5),(0x74798,.125),(0x747a0,.25),(0x6d378,.5),(0x6d588,.5)]:
            p=self.base+rva;value=struct.unpack('<d',self.m.mem_read(p,8))[0];self.m.mem_write(p,struct.pack('<d',value+delta))
        p=self.base+0x73dd8;value=struct.unpack('<d',self.m.mem_read(p,8))[0];self.m.mem_write(p,struct.pack('<d',value*2.))
        p=self.base+0x74934;value=struct.unpack('<I',self.m.mem_read(p,4))[0];self.m.mem_write(p,struct.pack('<I',(value+1)%9))
    def child(self,m,address,size,user):
        c=self.case;x=self.x;api=self.apis[address];r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))&MASK
        if api==1:self.event(1,r('RCX'),r('R9'),r('XMM1'),r('XMM2'));m.reg_write(x.UC_X86_REG_XMM0,pre.bits(c['stop_level']))
        elif api==11:self.event(11,r('RDX'),r('XMM0'),struct.unpack('<Q',m.mem_read(self.base+0x6d670,8))[0]);m.reg_write(x.UC_X86_REG_XMM0,pre.bits(c['take_level']))
        elif api==2:self.event(2,r('RCX'),c['delay_seconds'],c['delay_pass']);m.reg_write(x.UC_X86_REG_RAX,c['delay_pass'])
        elif api==5:
            self.last_sl=r('XMM1');self.event(5,r('RCX'),self.last_sl,r('XMM2'),c['modify_ok']);m.reg_write(x.UC_X86_REG_RAX,c['modify_ok'])
        elif api==6:self.event(6,r('RCX'))
        elif api==8:self.event(8,r('RCX'));self.closed=1;self.stopped=True;m.emu_stop();return
        else:raise ValueError('BAD_CHILD '+str(api))
        self.changed(api)
        sp=m.reg_read(x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(sp,8))[0]
        require(any(int(f['rva'],16)<=ret-self.base<int(f['end_rva'],16) for f in json.loads((ANALYSIS/'analysis.json').read_text())['functions']),'CHILD_RETURN_OUTSIDE_MANAGER')
        m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret)
    def call(self,m,address,size,user):
        c=self.case;x=self.x;api=self.apis[address]
        if api==3:
            require(m.reg_read(x.UC_X86_REG_R8)==17 and self.text(m.reg_read(x.UC_X86_REG_RDX))=='CHECK','BAD_DIGITS')
            require(self.digit_count<3,'TOO_MANY_DIGITS');value=c['digits'+str(self.digit_count)]
            self.event(3,17,value,self.digit_count);self.digit_count+=1;m.reg_write(x.UC_X86_REG_RAX,value&MASK)
        elif api==7:
            require(self.text(m.reg_read(x.UC_X86_REG_RDX))=='CHECK' and m.reg_read(x.UC_X86_REG_R8)==self.base+0x74790,'BAD_TICK')
            self.event(7,c['tick_ok']);m.mem_write(self.base+0x74798,struct.pack('<2d',c['tick_bid'],c['tick_ask']));m.reg_write(x.UC_X86_REG_RAX,c['tick_ok'])
        else:return super().call(m,address,size,user)
        self.changed(api)
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.closed=0;self.stopped=False;self.events=[];self.cursor=0x70001000;self.digit_count=0;self.last_sl=pre.bits(c['sl'])
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        for rva,key in [(0x73dd8,'unit'),(0x6d670,'level'),(0x724a0,'take'),(0x6d588,'stop'),(0x6d378,'distance'),(0x6d380,'start'),(0x744a8,'freeze')]:m.mem_write(self.base+rva,struct.pack('<d',c[key]))
        m.mem_write(self.base+0x6d518,struct.pack('<i',c['delay_seconds']));m.mem_write(self.base+0x74934,struct.pack('<I',c['strategy_index']))
        m.mem_write(self.base+0x73ac0,struct.pack('<9d',*([777.]*9)));m.mem_write(self.base+0x73ac0+8*c['strategy_index'],struct.pack('<d',c['table_volume']))
        m.mem_write(self.base+0x73ab0,struct.pack('<d',1.25));m.mem_write(self.base+0x74798,struct.pack('<2d',c['bid'],c['ask']))
        m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string('CHECK')))
        m.reg_write(x.UC_X86_REG_RDI,self.base+0x74958);m.reg_write(x.UC_X86_REG_R13,self.base+0x1d6e48);m.reg_write(x.UC_X86_REG_R14,self.base+0x1d6e48);m.reg_write(x.UC_X86_REG_R12,c['changed'])
        for reg,key in [(6,'open'),(7,'tp'),(8,'sl'),(9,'take_level'),(10,'stop_level'),(13,'volume'),(15,'anchor')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(reg)),pre.bits(c[key]))
        sp=0x50020000-0x208;m.reg_write(x.UC_X86_REG_RSP,sp)
        m.mem_write(sp+(0x40 if c['buy'] else 0x48),struct.pack('<q',c['ticket']));m.mem_write(sp+(0x78 if c['buy'] else 0x88),struct.pack('<d',c['anchor']))
        start={0:(0x35d65,0x39ff5),4:(0x36189,0x3a4af)}[c['stage']][0 if c['buy'] else 1]
        m.emu_start(self.base+start,0x60000000,timeout=5000000,count=100000);require(self.stopped,'BOUNDARY_MISSING')
        h=0xcbf29ce484222325
        for event in self.events:
            for b in struct.pack('<5Q',*event):h=((h^b)*0x100000001b3)&MASK
        read=lambda rva:struct.unpack('<Q',m.mem_read(self.base+rva,8))[0]
        index=struct.unpack('<I',m.mem_read(self.base+0x74934,4))[0]
        return RESULT.pack(c['id'],self.closed,int((m.reg_read(x.UC_X86_REG_R12)&255)!=0),index,
          m.reg_read(x.UC_X86_REG_XMM10)&MASK,m.reg_read(x.UC_X86_REG_XMM9)&MASK,read(0x6d670),read(0x724a0),self.last_sl,pre.bits(c['tp']),
          read(0x74798),read(0x747a0),read(0x73dd8),read(0x6d588),read(0x6d378),read(0x744a8),len(self.events),h)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args()
    require(bool(re.fullmatch('[a-z0-9-]{1,50}',a.run)),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));tested=folder/'tested-sources';tested.mkdir()
        for n in NAMES:shutil.copyfile(HOME/'source/MQL5'/n,tested/Path(n).name)
        for path in [Path(__file__),CPU_PATH,V_PATH]:shutil.copyfile(path,tested/path.name)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==value for k,value in current.items()),'IDENTITY_DIFFERS')
    require(baseline['inputs_sha256']==sha(folder/'cases.bin') and (folder/'cases.bin').read_bytes()==encode(rows),'INPUTS_DIFFERS')
    if a.mode=='original':
        require(not (folder/'original-results.bin').exists(),'RESULT_EXISTS');fixture=cpu.CpuFixture()
        try:
            cpu.verify_probe(fixture,current['probe_sha256']);runner=Original(fixture);data=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));traces=[]
            for c in rows:
                try:data+=runner.run(c)
                except Exception as e:raise RuntimeError('case=%d stage=%d buy=%d rva=%#x %s'%(c['id'],c['stage'],c['buy'],runner.m.reg_read(runner.x.UC_X86_REG_RIP)-runner.base,e)) from e
                traces.append(dict(id=c['id'],events=runner.events))
            (folder/'original-results.bin').write_bytes(data);save(folder/'original-traces.json',traces)
            save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),executed_instructions=sorted(hex(n) for n in runner.covered),nan_fixture=runner.nan.report(),**SCOPE))
            print(json.dumps(dict(cases=len(rows),instructions=len(runner.covered),nan_fixture=runner.nan.report())))
        finally:fixture.close()
        return
    if a.mode=='mql5':
        require(bool(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build)),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==NAMES[-1] and type(build['errors']) is int and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,value in current['sources_sha256'].items():require(build['sources_sha256'][n]==value==sha(MT/'MQL5'/n),'SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-management-virtual-levels'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b3-levels-{a.run}.set';ini=MT/f'b3-levels-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementVirtualLevelsCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),binary_sha256=sha(binary),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for n in ['original-run.json','mql5-run.json']:
        record=json.loads((folder/n).read_text());require(all(record[k]==value for k,value in current.items()),'RUN_IDENTITY_DIFFERS')
        require(record['result_sha256']==sha(folder/n.replace('-run.json','-results.bin')),'RUN_RESULT_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes()
    require(native[:12]==actual[:12]==struct.pack('<3i',MAGIC,1,len(rows)) and len(native)==len(actual)==12+RESULT.size*len(rows),'BAD_RESULTS');failed=[];groups={}
    for c in rows:
        group=groups.setdefault(str(c['stage']),dict(cases=0,matched=0));group['cases']+=1;off=12+c['id']*RESULT.size
        n=RESULT.unpack_from(native,off);r=RESULT.unpack_from(actual,off)
        if n==r:group['matched']+=1
        else:failed.append(dict(id=c['id'],group=c['group'],stage=c['stage'],buy=c['buy'],differences={key:[left,right] for key,left,right in zip(FIELDS,n,r) if left!=right}))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),groups=groups,first_failures=failed[:20],hashes={n:sha(folder/n) for n in ['cases.bin','original-results.bin','mql5-results.bin']},**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
