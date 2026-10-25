"""Compare real-take slices with captured instructions; child/API replies are supplied.
prepare|original|mql5|compare RUN [--build BUILD]. This is not a whole EA test.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
V_PATH=HOME/'tests/check-management-virtual-levels.py';CASE_PATH=HOME/'tests/real_take_cases.py'
V=module('take3_levels',V_PATH);inputs=module('take3_inputs',CASE_PATH)
pre,cpu,sha,require,save,MT=V.pre,V.cpu,V.sha,V.require,V.save,V.MT
MAGIC=inputs.MAGIC;MASK=V.MASK;RESULT=struct.Struct('<3iIIQ23QiQ');ANALYSIS=V.ANALYSIS
SUFFIX="' when setting trailing Exit_TP.  Trying again!"
CONTRACT=HOME/'phan-tich/dong-vi-the/management-real-take-20261025-r1/native-review.md'
NAMES=[n for n in V.NAMES if not n.endswith(('Bot3ManagementVirtualStart.mqh','Bot3ManagementVirtualTake.mqh','Bot3ManagementVirtualLevelsCheck.mq5'))]+['Include/bot-cua-toi-3/'+n for n in ['Bot3ManagementRealTake.mqh','Bot3ManagementMessages.mqh','Bot3TradeErrors.mqh']]+['Scripts/bot-cua-toi-3/Bot3ManagementRealTakeCheck.mq5']
FIELDS=['id','returned','changed','index','error_count','deviation']+inputs.DOUBLES+['volume'+str(i) for i in range(9)]+['calls','ordered_hash']
SCOPE=dict(calculation_slice_only=True,whole_manager_complete=False,whole_bot_complete=False,original_bytes_changed=False,modify_child_intercepted=True,close_child_intercepted=True,error_reporting_block_intercepted=True)
LIMITS=['Only real trailing-take calculations and their call boundaries, not the complete manager, EA or a paired original/restored terminal run.',
 'Modify32a90 and TryClose47d20 are intercepted. The close ticket comes from native RCX; other close values are supplied context and checked for MQL5 forwarding only, not by executing the original close child.',
 'The original failure-report blocks34923/38e4d are replaced by a report callback. Original string building/printing/error helper does not execute. The real message header has compile-only evidence.',
 'API replies and mutation cases are supplied; both-NaN arithmetic uses measured Windows SSE2 fixtures, other native instructions execute in Unicorn. No physical whole-original or MXCSR-status comparison.']
def identity():
    old=V.identity()
    return dict(original_ex5_sha256=old['original_ex5_sha256'],tool_sha256=sha(Path(__file__)),analysis_sha256=sha(ANALYSIS/'analysis.json'),contract_sha256=sha(CONTRACT),probe_sha256=sha(cpu.PROBE),helpers_sha256=old['helpers_sha256']|{str(p.relative_to(ROOT)):sha(p) for p in [V_PATH,CASE_PATH]},sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES})
class Original(V.Original):
    def __init__(self,fixture):
        super().__init__(fixture)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x34564,end=self.base+0x34b22)
        for rva in [0x34923,0x38e4d]:self.m.hook_add(self.uc.UC_HOOK_CODE,self.report,begin=self.base+rva,end=self.base+rva)
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        if off in [0x34b22,0x3905a,0x39064]:self.stopped=True;m.emu_stop()
    def mutate(self,target):
        if self.case['scenario']!=target:return
        for rva,delta in [(0x6d378,.5),(0x6d380,.25),(0x73ab0,.125),(0x744a8,.25),(0x74798,.25),(0x747a0,.5)]:
            p=self.base+rva;v=struct.unpack('<d',self.m.mem_read(p,8))[0];self.m.mem_write(p,struct.pack('<d',v+delta))
        p=self.base+0x73dd8;v=struct.unpack('<d',self.m.mem_read(p,8))[0];self.m.mem_write(p,struct.pack('<d',v*2.))
        p=self.base+0x74934;v=struct.unpack('<I',self.m.mem_read(p,4))[0];self.m.mem_write(p,struct.pack('<I',(v+1)%9));self.deviation=(self.deviation+1)&MASK
    def changed(self,api):
        target={5:5}.get(api)
        if api==3:target={1:1,2:3,3:4}[self.digit_count]
        if api==4:target=2 if self.last_property==16 else 6
        if target is not None:self.mutate(target)
    def report(self,m,address,size,user):
        self.event(10,self.case['error_code'],self.error_count,pre.entry.text_hash(SUFFIX));self.error_count=(self.error_count+1)&0xffffffff;self.mutate(7)
        sp=m.reg_read(self.x.UC_X86_REG_RSP);m.mem_write(sp+(0x48 if self.case['buy'] else 0x68),struct.pack('<Q',1));m.reg_write(self.x.UC_X86_REG_RIP,self.base+(0x34b22 if self.case['buy'] else 0x39064))
    def call(self,m,address,size,user):
        api=self.apis[address]
        if api==4:
            prop=m.reg_read(self.x.UC_X86_REG_R8);require(prop in [16,34] and self.text(m.reg_read(self.x.UC_X86_REG_RDX))=='CHECK','BAD_SYMBOL_DOUBLE')
            self.last_property=prop;value=self.case['point' if prop==16 else 'minimum'];self.event(4,prop,pre.bits(value))
            m.mem_write(self.base+0x1d6e48,struct.pack('<d',value));m.reg_write(self.x.UC_X86_REG_XMM0,pre.bits(value));self.changed(4);return
        return super().call(m,address,size,user)
    def child(self,m,address,size,user):
        if self.apis[address]!=8:return super().child(m,address,size,user)
        read=lambda rva:struct.unpack('<Q',m.mem_read(self.base+rva,8))[0]
        self.event(6,m.reg_read(self.x.UC_X86_REG_RCX),self.deviation,read(0x74798),read(0x747a0));self.event(7,read(0x73ab0),read(0x744a8));self.mutate(8);self.closed=1;self.stopped=True;m.emu_stop()
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.events=[];self.stopped=False;self.closed=0;self.cursor=0x70001000;self.digit_count=0;self.error_count=c['error_count'];self.deviation=c['deviation'];self.last_sl=pre.bits(c['sl'])
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for reg in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+reg),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        for rva,key in [(0x73dd8,'unit'),(0x6d378,'distance'),(0x6d380,'start'),(0x73ab0,'gap'),(0x744a8,'freeze')]:m.mem_write(self.base+rva,struct.pack('<d',c[key]))
        m.mem_write(self.base+0x74798,struct.pack('<2d',c['bid'],c['ask']));m.mem_write(self.base+0x74934,struct.pack('<I',c['index']));m.mem_write(self.base+0x73ac0,struct.pack('<9d',*c['volumes']))
        m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string('CHECK')));m.reg_write(x.UC_X86_REG_RDI,self.base+0x74958)
        m.reg_write(x.UC_X86_REG_R13,self.base+0x1d6e48);m.reg_write(x.UC_X86_REG_R14,self.base+0x1d6e48);m.reg_write(x.UC_X86_REG_R15,self.base+0x747a0)
        for reg,key in [(6,'open_price'),(7,'tp'),(8,'sl'),(13,'volume')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(reg)),pre.bits(c[key]))
        sp=0x50020000-0x208;m.reg_write(x.UC_X86_REG_RSP,sp)
        m.mem_write(sp+(0x40 if c['buy'] else 0x48),struct.pack('<q',c['ticket']));m.mem_write(sp+(0x78 if c['buy'] else 0x88),struct.pack('<d',c['anchor']));m.mem_write(sp+(0x48 if c['buy'] else 0x68),struct.pack('<Q',c['prior_changed']))
        m.emu_start(self.base+(0x34564 if c['buy'] else 0x38aaa),0x60000000,timeout=5000000,count=100000);require(self.stopped,'BOUNDARY_MISSING')
        read=lambda rva:struct.unpack('<Q',m.mem_read(self.base+rva,8))[0]
        values={k:pre.bits(c[k]) for k in inputs.DOUBLES};values.update(sl=m.reg_read(x.UC_X86_REG_XMM8)&MASK,tp=m.reg_read(x.UC_X86_REG_XMM7)&MASK)
        for rva,key in [(0x74798,'bid'),(0x747a0,'ask'),(0x73dd8,'unit'),(0x6d378,'distance'),(0x6d380,'start'),(0x73ab0,'gap'),(0x744a8,'freeze')]:values[key]=read(rva)
        index=struct.unpack('<I',m.mem_read(self.base+0x74934,4))[0];changed=struct.unpack('<Q',m.mem_read(sp+(0x48 if c['buy'] else 0x68),8))[0]&255
        h=0xcbf29ce484222325
        for e in self.events:
            for b in struct.pack('<5Q',*e):h=((h^b)*0x100000001b3)&MASK
        return RESULT.pack(c['id'],self.closed,int(changed!=0),index,self.error_count,self.deviation,*(values[k] for k in inputs.DOUBLES),*(read(0x73ac0+8*i) for i in range(9)),len(self.events),h)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=inputs.cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(inputs.encode(rows));s=folder/'tested-sources';s.mkdir()
        for n in NAMES:shutil.copyfile(HOME/'source/MQL5'/n,s/Path(n).name)
        for path in [Path(__file__),CASE_PATH]:shutil.copyfile(path,s/path.name)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==value for k,value in current.items()) and (folder/'cases.bin').read_bytes()==inputs.encode(rows),'IDENTITY_OR_INPUT_DIFFERS')
    if a.mode=='original':
        require(not (folder/'original-results.bin').exists(),'RESULT_EXISTS');f=cpu.CpuFixture()
        try:
            cpu.verify_probe(f,current['probe_sha256']);r=Original(f);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));traces=[]
            for c in rows:
                try:raw+=r.run(c)
                except Exception as e:raise RuntimeError('case=%d buy=%d rva=%#x %s'%(c['id'],c['buy'],r.m.reg_read(r.x.UC_X86_REG_RIP)-r.base,e)) from e
                traces.append(dict(id=c['id'],events=r.events))
            (folder/'original-results.bin').write_bytes(raw);save(folder/'original-traces.json',traces);save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),instructions=sorted(hex(n) for n in r.covered),nan_fixture=r.nan.report(),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(r.covered))))
        finally:f.close()
        return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==NAMES[-1] and type(build['errors']) is int and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,value in current['sources_sha256'].items():require(value==build['sources_sha256'][n]==sha(MT/'MQL5'/n),'SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-management-real-take'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b3-real-take-{a.run}.set';ini=MT/f'b3-real-take-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementRealTakeCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for name in ['original-run.json','mql5-run.json']:
        r=json.loads((folder/name).read_text());require(all(r[k]==value for k,value in current.items()) and r['result_sha256']==sha(folder/name.replace('-run.json','-results.bin')),'RUN_IDENTITY_DIFFERS')
    n=(folder/'original-results.bin').read_bytes();r=(folder/'mql5-results.bin').read_bytes();require(n[:12]==r[:12]==struct.pack('<3i',MAGIC,1,len(rows)) and len(n)==len(r)==12+RESULT.size*len(rows),'BAD_RESULTS');failed=[]
    for c in rows:
        off=12+RESULT.size*c['id'];left=RESULT.unpack_from(n,off);right=RESULT.unpack_from(r,off)
        if left!=right:failed.append(dict(id=c['id'],group=c['group'],buy=c['buy'],differences={k:[a,b] for k,a,b in zip(FIELDS,left,right) if a!=b}))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:15],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
