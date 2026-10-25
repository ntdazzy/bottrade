"""Compare the captured new-bar manager-call slice with the MQL5 helper.
prepare -> mql5 --build BUILD -> original -> compare RUN. Child replies are supplied.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
PRE_PATH=HOME/'tests/check-management-prelude.py';pre=module('bar3_pre',PRE_PATH)
CASE_PATH=HOME/'tests/bar_gate_cases.py';inputs=module('bar3_inputs',CASE_PATH)
PUB_PATH=ROOT/'cong-cu/kiem-ban-git-quan-ly.py';pub=module('bar3_closure',PUB_PATH)
sha,require,save=pre.sha,pre.require,pre.save
MT=(ROOT.parent/'.local/mt5-bot3-thread-20261025').resolve();MASK=(1<<64)-1
SCRIPT='Scripts/bot-cua-toi-3/Bot3ManagementBarGateCheck.mq5'
BINDINGS=HOME/'phan-tich/chuong-trinh-chinh/bar-gate-20261026-r1/native-bindings.json'
CONTRACT=ROOT/'claude-thuc-hien/bot3-newbar-check-20261026-r1/TASK.md'
RESULT=struct.Struct('<7iQ9q');FIELDS=['id','returned','timeframe','counter','mode','index','events','ordered_hash']+['bar'+str(i) for i in range(9)]
SCOPE=dict(whole_manager_complete=False,whole_bot_complete=False,full_ea=False,native_caller_slice_executed=True,child_helpers_intercepted=True,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Only the new-bar time check, second time write, ordered buy/sell calls and boolean branch are executed; not the complete coordinator or EA.',
 'Both manager bodies and iTime replies/effects are supplied; management bodies have separate scoped comparisons.',
 'Valid indices0..8 and the specified fixtures only; no claim about invalid indices, all broker data or full program lifecycle.']
def identity():
    base=HOME/'source/MQL5';names=sorted(p.relative_to(base.resolve()).as_posix() for p in pub.closure(base/SCRIPT,base))
    return dict(original_ex5_sha256=pre.validation.original_hash(3),tool_sha256=sha(Path(__file__)),contract_sha256=sha(CONTRACT),helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in [PRE_PATH,CASE_PATH,PUB_PATH,BINDINGS,ROOT/'bot-cua-toi-1/tests/check-management-prelude.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py']},sources_sha256={n:sha(base/n) for n in names})
def fnv(raw):
    value=0xcbf29ce484222325
    for byte in raw:value=((value^byte)*0x100000001b3)&MASK
    return value
class Original(pre.entry.Original):
    def __init__(self):
        super().__init__(3);require(self.base==0x17156250000,'BASE_DIFFERS');m=self.m
        binding=json.loads(BINDINGS.read_text());begin=int(binding['function']['begin'],16);end=int(binding['function']['end'],16)
        require(__import__('hashlib').sha256(bytes(m.mem_read(self.base+begin,end-begin))).hexdigest()==binding['function']['sha256'],'CALLER_BYTES_DIFFER')
        sdk=next(a for a,k in self.apis.items() if k==1)-0x7d3c40;address=sdk+0x7d3b50
        if address not in self.apis:
            if not any(lo<=address<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(address&~4095,4096)
            m.mem_write(address,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.apis[address]=200
        for off in [0x32f60,0x37590]:m.hook_add(self.uc.UC_HOOK_CODE,self.child,begin=self.base+off,end=self.base+off)
        m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x227c0,end=self.base+0x22875);self.covered=set()
    def event(self,*words):self.events.append([value&MASK for value in words])
    def integer(self,off):return struct.unpack('<i',self.m.mem_read(self.base+off,4))[0]
    def bar(self):return struct.unpack('<q',self.m.mem_read(self.base+0x73790+self.case['index']*8,8))[0]
    def set_bar(self,value):self.m.mem_write(self.base+0x73790+self.case['index']*8,struct.pack('<q',value))
    def text(self,descriptor):
        pointer=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0];require(pointer!=0,'NULL_SYMBOL');length=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(length<100,'SYMBOL_TOO_LONG');return bytes(self.m.mem_read(pointer,length*2)).decode('utf-16-le')
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        if off in [0x22851,0x22875]:self.stop=off;m.emu_stop()
    def call(self,m,address,size,user):
        require(self.apis[address]==200,'UNEXPECTED_API');x=self.x;c=self.case;r=lambda name:m.reg_read(getattr(x,'UC_X86_REG_'+name))
        require(self.time_calls<2 and self.text(r('RDX'))=='CHECK' and r('R9')==1,'BAD_TIME_CALL')
        value=c['observed'] if self.time_calls==0 else c['second'];self.event(1,r('R8')&0xffffffff,1,self.bar(),value)
        if self.time_calls==0:
            m.mem_write(self.base+0x6d584,struct.pack('<i',c['after_first_frame']))
            if c['change_first_bar']:self.set_bar(c['after_first_bar'])
        self.time_calls+=1;m.reg_write(x.UC_X86_REG_RAX,value&MASK)
    def child(self,m,address,size,user):
        c=self.case;x=self.x;buy=address==self.base+0x32f60;self.manager_calls+=1
        require(self.manager_calls==(1 if buy else 2),'BAD_MANAGER_ORDER')
        level=struct.unpack('<Q',m.mem_read(self.base+(0x74110 if buy else 0x73df0),8))[0]
        self.event(2 if buy else 3,self.integer(0x74430),self.integer(0x6d514),struct.unpack('<I',m.mem_read(self.base+0x74934,4))[0],level)
        if buy and c['change_buy']:
            m.mem_write(self.base+0x74430,struct.pack('<i',self.integer(0x74430)+1));m.mem_write(self.base+0x6d514,struct.pack('<i',self.integer(0x6d514)+1));m.mem_write(self.base+0x74934,struct.pack('<I',(self.integer(0x74934)+1)%9));self.set_bar(self.bar()+10)
        sp=m.reg_read(x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(sp,8))[0];m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret);m.reg_write(x.UC_X86_REG_RAX,c['buy_reply' if buy else 'sell_reply'])
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.events=[];self.time_calls=self.manager_calls=0;self.stop=None;self.cursor=0x70001000;self.allocs=self.frees=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.mem_write(0x50000000,b'\0'*0x20000)
        m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string('CHECK')));m.mem_write(self.base+0x73790,struct.pack('<9q',*[100+i for i in range(9)]));self.set_bar(c['previous'])
        for off,value in [(0x6d584,c['timeframe']),(0x74430,7),(0x6d514,1),(0x74934,(c['index']+1)%9)]:m.mem_write(self.base+off,struct.pack('<i',value))
        m.mem_write(self.base+0x74110,struct.pack('<9d',*[10.+i for i in range(9)]));m.mem_write(self.base+0x73df0,struct.pack('<9d',*[20.+i for i in range(9)]))
        top=0x50020000-0x108;m.reg_write(x.UC_X86_REG_RSP,top);m.mem_write(top+0xb0,struct.pack('<I',c['index']));m.emu_start(self.base+0x227c0,0x60000000,timeout=1000000,count=10000);require(self.stop is not None,'SLICE_DID_NOT_FINISH')
        raw=b''.join(struct.pack('<5Q',*event) for event in self.events);bars=struct.unpack('<9q',m.mem_read(self.base+0x73790,72))
        return RESULT.pack(c['id'],int(self.stop==0x22875),self.integer(0x6d584),self.integer(0x74430),self.integer(0x6d514),self.integer(0x74934),len(self.events),fnv(raw),*bars)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=inputs.cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(inputs.encode(rows));tested=folder/'tested-sources';tested.mkdir()
        for name in current['sources_sha256']:shutil.copyfile(HOME/'source/MQL5'/name,tested/Path(name).name)
        for source in [Path(__file__),CASE_PATH,BINDINGS]:shutil.copyfile(source,tested/source.name)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==value for k,value in current.items()) and (folder/'cases.bin').read_bytes()==inputs.encode(rows),'IDENTITY_OR_INPUTS_DIFFER')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/name)==build['sources_sha256'][name]==digest,'SOURCE_DIFFERS '+name)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-management-bar-gate'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/('b3-bar-gate-'+a.run+'.set');ini=MT/('b3-bar-gate-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementBarGateCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    if a.mode=='original':
        require(not (folder/'original-results.bin').exists(),'RESULT_EXISTS');runner=Original();raw=bytearray(struct.pack('<3i',inputs.MAGIC,1,len(rows)));traces=[]
        for c in rows:
            try:raw+=runner.run(c)
            except Exception as error:
                save(folder/'attempt-error.json',dict(case=c['id'],error=str(error),rva=hex(runner.m.reg_read(runner.x.UC_X86_REG_RIP)-runner.base),events=runner.events));raise
            traces.append(dict(id=c['id'],events=runner.events,stop_rva=hex(runner.stop)))
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-traces.json',traces);save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),instructions=sorted(hex(off) for off in runner.covered),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(runner.covered))));return
    for name in ['original-run.json','mql5-run.json']:
        rec=json.loads((folder/name).read_text());require(all(rec[k]==value for k,value in current.items()) and rec['result_sha256']==sha(folder/name.replace('-run.json','-results.bin')),'RUN_IDENTITY_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();require(native[:12]==actual[:12]==struct.pack('<3i',inputs.MAGIC,1,len(rows)) and len(native)==len(actual)==12+RESULT.size*len(rows),'BAD_RESULTS');failed=[]
    for c in rows:
        off=12+c['id']*RESULT.size;n=RESULT.unpack_from(native,off);r=RESULT.unpack_from(actual,off)
        if n!=r:failed.append(dict(id=c['id'],differences={k:[x,y] for k,x,y in zip(FIELDS,n,r) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:20],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS);save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
