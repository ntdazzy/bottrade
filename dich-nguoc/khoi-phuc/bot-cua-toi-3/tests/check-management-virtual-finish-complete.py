"""Compare final virtual high/low and lock/counter blocks with original instructions.
prepare|original|mql5|compare RUN [--build BUILD]. Uses the private bot3 terminal.
"""
import argparse,importlib.util,itertools,json,math,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
V_PATH=HOME/'tests/check-management-virtual-levels.py';V=module('finish3_verified_levels',V_PATH)
pre,cpu,MT,sha,require,save=V.pre,V.cpu,V.MT,V.sha,V.require,V.save
MAGIC=0x4d564633;MASK=V.MASK;ANALYSIS=V.ANALYSIS
CONTRACT=HOME/'phan-tich/dong-vi-the/management-virtual-finish-20261025-r1/contract.md'
INTS=['id','buy','stage','scenario','changed','index','high_enabled','before_open','shift','mode','step_enabled','min_steps','counter']
DOUBLES=['open','tp','level','unit','gap','freeze','lock','extra','reference','step_distance','anchor','copied','point']
CASE=struct.Struct('<13i24d');RESULT=struct.Struct('<6i8QiQ')
FIELDS=['id','stage','changed','counter','index','hit','level','bid','ask','unit','gap','freeze','extra','levels_hash','calls','ordered_hash']
NAMES=[n for n in V.NAMES if not n.endswith(('Bot3ManagementVirtualStart.mqh','Bot3ManagementVirtualTake.mqh','Bot3ManagementVirtualLevelsCheck.mq5'))]+['Include/bot-cua-toi-3/Bot3ManagementVirtualFinish.mqh','Scripts/bot-cua-toi-3/Bot3ManagementVirtualFinishCheck.mq5']
SCOPE=dict(slice_only=True,whole_manager_complete=False,whole_bot_complete=False,original_bytes_changed=False)
LIMITS=['Two final virtual calculation blocks only. Persistence is compared separately; no full manager, EA or paired terminal run.',
 'Symbol point replies and external API-time changes are supplied. Valid 0..8 indices are a precondition.',
 'A close boundary after the counter is recorded, not executed. No actual order or full close-helper composition.',
 'Two-NaN scalar arithmetic uses measured CPU fixtures only when both operands are NaN; remaining original instructions execute in Unicorn.']
def cases():
    rows=[];nan=lambda n:struct.unpack('<d',struct.pack('<Q',n))[0]
    values=[-math.inf,-1e19,-100.125,-0.,0.,.01,100.125,1e19,math.inf,nan(0x7ff8000000000123),nan(0xfff8000000000456)]
    def add(c,g):c.update(id=len(rows),group=g);rows.append(c)
    for buy,stage in itertools.product([0,1],[0,1]):
        b=dict(id=0,buy=buy,stage=stage,scenario=0,changed=0,index=2,high_enabled=1,before_open=0,shift=0,mode=2,
          step_enabled=1,min_steps=1,counter=0,open=100.,tp=130. if buy else 70.,level=97. if buy else 103.,unit=1.,gap=.2,
          freeze=2.5,lock=2.,extra=1.,reference=0.,step_distance=1.,anchor=100.,copied=.5,point=.01,
          bid=105. if buy else 94.,ask=106. if buy else 95.,levels=[98.+i for i in range(9)])
        add(dict(b),'normal')
        for field in DOUBLES+['bid','ask']:
            for value in values:c=dict(b);c[field]=value;add(c,'numeric-'+field)
        for changed,scenario in itertools.product([0,1],[0,1,2,3]):
            c=dict(b);c.update(changed=changed,scenario=scenario);add(c,'api-mutations')
        if stage==0:
            for enabled,before,shift in itertools.product([-1,0,1,2147483647],[0,1,2,255],[0,1,2,255]):
                c=dict(b);c.update(high_enabled=enabled,before_open=before,shift=shift);add(c,'high-low-flags')
            for level in [96.99,97.,97.21,99.,100.,100.01,103.,105.,math.nan]:
                c=dict(b);c['levels']=[level]*9;add(c,'high-low-level-gates')
            for index,scenario in itertools.product([0,2,8],[0,1,2,3]):
                c=dict(b);c.update(index=index,scenario=scenario);add(c,'fresh-index')
        else:
            for mode in [-1,0,1,2,3,2147483647]:c=dict(b);c['mode']=mode;add(c,'mode-int32')
            for enabled,ref,counter,minimum in itertools.product([0,1,2,255],[-0.,0.,1.,nan(0x7ff8000000000789)],[-2147483648,0,1,2147483647],[-1,1,2]):
                c=dict(b);c.update(lock=0.,step_enabled=enabled,reference=ref,counter=counter,min_steps=minimum);add(c,'counter-flags-overflow-anchor')
            for anchor,copied in itertools.product([90.,100.,110.],[-1.,0.,1.,math.inf,math.nan]):
                c=dict(b);c.update(lock=0.,reference=1.,anchor=anchor,copied=copied);add(c,'anchor-and-step')
        for pair in [('level','gap'),('unit','extra'),('open','extra')]:
            c=dict(b);c.update(zip(pair,[nan(0x7ff8000000000123),nan(0xfff8000000000456)]));add(c,'nan-operand-order')
    return rows
def encode(rows):
    return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(CASE.pack(*(c[k] for k in INTS),*(c[k] for k in DOUBLES),c['bid'],c['ask'],*c['levels']) for c in rows)
def levels(c):return list(c['levels'])
def identity():
    old=V.identity()
    return dict(original_ex5_sha256=old['original_ex5_sha256'],tool_sha256=sha(Path(__file__)),analysis_sha256=sha(ANALYSIS/'analysis.json'),contract_sha256=sha(CONTRACT),probe_sha256=sha(cpu.PROBE),
      helpers_sha256=old['helpers_sha256']|{str(V_PATH.relative_to(ROOT)):sha(V_PATH)},sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES})
class Original(V.Original):
    def __init__(self,fixture):
        super().__init__(fixture)
        require(bytes(self.m.mem_read(self.base+0x58488,8))==bytes(self.m.mem_read(self.base+0x584b0,8))==struct.pack('<d',10.),'SHIFT_CONSTANTS_DIFFERS')
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        exits=[0x3691b,0x3aafe] if self.case['stage']==0 else [0x36b19,0x3ad01,0x36fd4,0x3b1c7]
        if off in exits:self.boundary=off;self.stopped=True;m.emu_stop()
    def changed(self,api):
        if api!=4:return
        self.point_count+=1;c=self.case
        if not (c['scenario']==3 or c['scenario']==self.point_count):return
        for rva,delta in [(0x6d670,.125),(0x74798,.25),(0x747a0,.5),(0x73ab0,.125),(0x744a8,.25),(0x6d5c0,.25)]:
            p=self.base+rva;value=struct.unpack('<d',self.m.mem_read(p,8))[0];self.m.mem_write(p,struct.pack('<d',value+delta))
        p=self.base+0x73dd8;u=struct.unpack('<d',self.m.mem_read(p,8))[0];self.m.mem_write(p,struct.pack('<d',u*2.))
        p=self.base+0x74934;index=(struct.unpack('<I',self.m.mem_read(p,4))[0]+1)%9;self.m.mem_write(p,struct.pack('<I',index))
        p=self.base+(0x74110 if c['buy'] else 0x73df0)+8*index;value=struct.unpack('<d',self.m.mem_read(p,8))[0];self.m.mem_write(p,struct.pack('<d',value+1.5))
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.events=[];self.stopped=False;self.point_count=0;self.cursor=0x70001000
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for reg in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+reg),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        for rva,key in [(0x6d670,'level'),(0x73dd8,'unit'),(0x73ab0,'gap'),(0x744a8,'freeze'),(0x6d5b8,'lock'),(0x6d5c0,'extra'),(0x6d600,'reference'),(0x6d610,'step_distance'),(0x74428,'copied')]:m.mem_write(self.base+rva,struct.pack('<d',c[key]))
        for rva,key in [(0x6d5d4,'high_enabled'),(0x6d514,'mode'),(0x6d608,'min_steps'),(0x74430,'counter')]:m.mem_write(self.base+rva,struct.pack('<i',c[key]))
        for rva,key in [(0x6d5c8,'before_open'),(0x6d5dc,'shift'),(0x6d5f8,'step_enabled')]:m.mem_write(self.base+rva,bytes([c[key]&255]))
        m.mem_write(self.base+0x74934,struct.pack('<I',c['index']));m.mem_write(self.base+0x74798,struct.pack('<2d',c['bid'],c['ask']))
        m.mem_write(self.base+(0x74110 if c['buy'] else 0x73df0),struct.pack('<9d',*levels(c)))
        m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string('CHECK')));m.reg_write(x.UC_X86_REG_RDI,self.base+0x74958)
        m.reg_write(x.UC_X86_REG_R13,self.base+0x1d6e48);m.reg_write(x.UC_X86_REG_R14,self.base+0x1d6e48);m.reg_write(x.UC_X86_REG_R12,c['changed'])
        for reg,key in [(6,'open'),(7,'tp')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(reg)),pre.bits(c[key]))
        sp=0x50020000-0x208;m.reg_write(x.UC_X86_REG_RSP,sp);m.mem_write(sp+(0x78 if c['buy'] else 0x88),struct.pack('<d',c['anchor']))
        start={0:(0x36667,0x3a97d),1:(0x3691b,0x3aafe)}[c['stage']][0 if c['buy'] else 1]
        m.emu_start(self.base+start,0x60000000,timeout=5000000,count=100000);require(self.stopped,'BOUNDARY_MISSING')
        def hash_bytes(raw):
            h=0xcbf29ce484222325
            for b in raw:h=((h^b)*0x100000001b3)&MASK
            return h
        read=lambda rva:struct.unpack('<Q',m.mem_read(self.base+rva,8))[0]
        current,bid,ask=[struct.unpack('<d',m.mem_read(self.base+rva,8))[0] for rva in [0x6d670,0x74798,0x747a0]]
        hit=(current>=bid if c['buy'] else ask>=current) if c['stage']==0 else self.boundary in [0x36fd4,0x3b1c7]
        return RESULT.pack(c['id'],c['stage'],int((m.reg_read(x.UC_X86_REG_R12)&255)!=0),struct.unpack('<i',m.mem_read(self.base+0x74430,4))[0],struct.unpack('<I',m.mem_read(self.base+0x74934,4))[0],int(hit),
          read(0x6d670),read(0x74798),read(0x747a0),read(0x73dd8),read(0x73ab0),read(0x744a8),read(0x6d5c0),hash_bytes(bytes(m.mem_read(self.base+(0x74110 if c['buy'] else 0x73df0),72))),len(self.events),hash_bytes(b''.join(struct.pack('<5Q',*e) for e in self.events)))
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));s=folder/'tested-sources';s.mkdir()
        for n in NAMES:shutil.copyfile(HOME/'source/MQL5'/n,s/Path(n).name)
        shutil.copyfile(Path(__file__),s/Path(__file__).name);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==value for k,value in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_OR_INPUT_DIFFERS')
    if a.mode=='original':
        require(not (folder/'original-results.bin').exists(),'RESULT_EXISTS');f=cpu.CpuFixture()
        try:
            cpu.verify_probe(f,current['probe_sha256']);r=Original(f);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));traces=[]
            for c in rows:
                try:raw+=r.run(c)
                except Exception as e:raise RuntimeError('case=%d stage=%d buy=%d rva=%#x %s'%(c['id'],c['stage'],c['buy'],r.m.reg_read(r.x.UC_X86_REG_RIP)-r.base,e)) from e
                traces.append(dict(id=c['id'],events=r.events))
            (folder/'original-results.bin').write_bytes(raw);save(folder/'original-traces.json',traces);save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),instructions=sorted(hex(n) for n in r.covered),nan_fixture=r.nan.report(),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(r.covered))))
        finally:f.close()
        return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==NAMES[-1] and type(build['errors']) is int and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,value in current['sources_sha256'].items():require(value==build['sources_sha256'][n]==sha(MT/'MQL5'/n),'SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-management-virtual-finish'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b3-finish-{a.run}.set';ini=MT/f'b3-finish-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementVirtualFinishCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for name in ['original-run.json','mql5-run.json']:
        r=json.loads((folder/name).read_text());require(all(r[k]==value for k,value in current.items()) and r['result_sha256']==sha(folder/name.replace('-run.json','-results.bin')),'RUN_IDENTITY_DIFFERS')
    n=(folder/'original-results.bin').read_bytes();r=(folder/'mql5-results.bin').read_bytes();require(n[:12]==r[:12]==struct.pack('<3i',MAGIC,1,len(rows)) and len(n)==len(r)==12+RESULT.size*len(rows),'BAD_RESULTS');failed=[];groups={}
    for c in rows:
        off=12+RESULT.size*c['id'];left=RESULT.unpack_from(n,off);right=RESULT.unpack_from(r,off);g=groups.setdefault(str(c['stage']),dict(cases=0,matched=0));g['cases']+=1
        if left==right:g['matched']+=1
        else:failed.append(dict(id=c['id'],group=c['group'],buy=c['buy'],stage=c['stage'],differences={k:[a,b] for k,a,b in zip(FIELDS,left,right) if a!=b}))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),groups=groups,first_failures=failed[:15],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
