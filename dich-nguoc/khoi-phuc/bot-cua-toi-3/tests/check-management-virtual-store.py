"""Compare only final virtual stop/take persistence, with supplied digit replies.
prepare|original|mql5|compare RUN [--build BUILD]. No trading API is invoked.
"""
import argparse,importlib.util,itertools,json,math,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,p):
    s=importlib.util.spec_from_file_location(name,p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
LEVELS_PATH=HOME/'tests/check-management-virtual-levels.py';v=module('store3_levels',LEVELS_PATH)
sha,require,save,pre,MT=v.sha,v.require,v.save,v.pre,v.MT
MAGIC=0x4d565033;MASK=v.MASK;CASE=struct.Struct('<11i5d');RESULT=struct.Struct('<3i5Qi2Q')
INTS=['id','buy','scenario','guard','pattern','digits0','digits1','digits2','digits3','digits4','digits5']
DOUBLES=['initial_stop','initial_take','level','take','key']
ANALYSIS=v.ANALYSIS;CONTRACT=HOME/'phan-tich/dong-vi-the/management-virtual-finish-20261025-r1/contract.md'
NAMES=[n for n in v.NAMES if not n.endswith(('Bot3ManagementVirtualStart.mqh','Bot3ManagementVirtualTake.mqh','Bot3ManagementVirtualLevelsCheck.mq5'))]+['Include/bot-cua-toi-3/Bot3ManagementVirtualFinish.mqh','Scripts/bot-cua-toi-3/Bot3ManagementVirtualStoreCheck.mq5']
SCOPE=dict(persistence_only=True,whole_manager_complete=False,whole_bot_complete=False,original_bytes_changed=False)
LIMITS=['Only the final two-table persistence block; no price-level calculation, close check, full manager or EA.',
 'All 2500 double fields are compared by an ordered 64-bit hash, together with guard/shared levels/call count and ordered API hash.',
 'Digit replies and API-time mutations are supplied. Original scalar two-NaN arithmetic, if reached, uses measured CPU fixtures; no full physical original run.']
def cases():
    out=[];nan=lambda n:struct.unpack('<d',struct.pack('<Q',n))[0]
    values=[-math.inf,-1e19,-100.125,-0.,0.,.01,100.123456789,1e19,math.inf,nan(0x7ff8000000000123),nan(0xfff8000000000456)]
    def add(c,g):c.update(id=len(out),group=g);out.append(c)
    for buy in [0,1]:
        b=dict(id=0,buy=buy,scenario=0,guard=1,pattern=0,digits0=3,digits1=3,digits2=3,digits3=3,digits4=3,digits5=3,initial_stop=95.125,initial_take=120.125,level=96.25,take=121.25,key=7.)
        add(dict(b),'both-different')
        for key in DOUBLES:
            for value in values:c=dict(b);c[key]=value;add(c,'numeric-'+key)
        for guard,pattern in itertools.product([0,1,2,255],range(6)):
            c=dict(b);c.update(guard=guard,pattern=pattern);add(c,'guard-and-rows')
        for stop,take in itertools.product([0,1],repeat=2):
            c=dict(b);c.update(level=b['initial_stop'] if stop else b['level'],take=b['initial_take'] if take else b['take']);add(c,'equal-levels')
        for digits in [[0,1,2,3,4,5],[11,10,9,8,7,6],[-1,12,0,-2147483648,2147483647,3],[3,2,8,11,5,1]]:
            c=dict(b);c.update(zip(['digits'+str(i) for i in range(6)],digits));add(c,'six-digit-reads')
        for scenario in range(1,7):
            for pattern in [0,1,2,3,5]:c=dict(b);c.update(scenario=scenario,pattern=pattern);add(c,'api-changes')
        for key in [0.,-0.,float((1<<53)+1),float((1<<63)-1),float(-(1<<63)),nan(0x7ff8000000000789)]:
            for pattern in [0,2,3,4,5]:c=dict(b);c.update(key=key,pattern=pattern);add(c,'ticket-and-first-row')
    return out
def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(CASE.pack(*(c[n] for n in INTS),*(c[n] for n in DOUBLES)) for c in rows)
def tables(c):
    stop=[];take=[]
    for row in range(500):
        stop.extend([10000.+row,20000.+row,-30000.-row]);take.extend([40000.+row,50000.+row])
    points={0:[0],1:[499],2:[1,17,499],3:[],4:[0],5:[0]}[c['pattern']]
    for row in points:stop[3*row]=c['key'];take[2*row]=c['key']
    if c['pattern']==4:stop[0]=take[0]=math.nan
    if c['pattern']==5:stop[0]=take[0]=0.
    return stop,take
def identity():
    base=v.identity()
    return dict(original_ex5_sha256=base['original_ex5_sha256'],tool_sha256=sha(Path(__file__)),contract_sha256=sha(CONTRACT),analysis_sha256=sha(ANALYSIS/'analysis.json'),probe_sha256=sha(v.cpu.PROBE),
      helpers_sha256=base['helpers_sha256']|{str(LEVELS_PATH.relative_to(ROOT)):sha(LEVELS_PATH)},sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES})
class Original(v.Original):
    def __init__(self,fixture):
        super().__init__(fixture)
        for rva in [0x330a3,0x376d3]:self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+rva,end=self.base+rva)
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        if off in [0x330a3,0x376d3]:self.stopped=True;m.emu_stop()
    def changed(self,api):
        if api!=3 or self.digit_count!=self.case['scenario']:return
        for rva,delta in [(0x6d670,1.25),(0x724a0,2.5)]:
            p=self.base+rva;value=struct.unpack('<d',self.m.mem_read(p,8))[0];self.m.mem_write(p,struct.pack('<d',value+delta))
        self.m.mem_write(self.base+0x73450,bytes([(self.case['guard']+1)%256]))
    def call(self,m,address,size,user):
        require(self.apis[address]==3,'UNEXPECTED_PERSISTENCE_API');require(m.reg_read(self.x.UC_X86_REG_R8)==17 and self.text(m.reg_read(self.x.UC_X86_REG_RDX))=='CHECK','BAD_DIGITS')
        require(self.digit_count<6,'TOO_MANY_DIGITS');value=self.case['digits'+str(self.digit_count)];self.event(3,17,value,self.digit_count);self.digit_count+=1;m.reg_write(self.x.UC_X86_REG_RAX,value&MASK);self.changed(3)
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.events=[];self.digit_count=0;self.stopped=False;self.cursor=0x70001000
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for reg in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+reg),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        stop,take=tables(c);m.mem_write(self.base+0x6d680,struct.pack('<1500d',*stop));m.mem_write(self.base+0x70560,struct.pack('<1000d',*take));m.mem_write(self.base+0x73450,bytes([c['guard']]))
        m.mem_write(self.base+0x6d670,struct.pack('<d',c['level']));m.mem_write(self.base+0x724a0,struct.pack('<d',c['take']));m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string('CHECK')))
        m.reg_write(x.UC_X86_REG_RDI,self.base+0x74958);m.reg_write(x.UC_X86_REG_RSP,0x50020000-0x208)
        for reg,key in [(10,'initial_stop'),(9,'initial_take'),(12,'key')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(reg)),pre.bits(c[key]))
        m.emu_start(self.base+(0x36b19 if c['buy'] else 0x3ad01),0x60000000,timeout=5000000,count=100000);require(self.stopped,'BOUNDARY_MISSING')
        def hash_bytes(raw):
            h=0xcbf29ce484222325
            for b in raw:h=((h^b)*0x100000001b3)&MASK
            return h
        state=bytes(m.mem_read(self.base+0x6d680,12000))+bytes(m.mem_read(self.base+0x70560,8000))
        events=b''.join(struct.pack('<5Q',*e) for e in self.events)
        read=lambda rva:struct.unpack('<Q',m.mem_read(self.base+rva,8))[0]
        return RESULT.pack(c['id'],int.from_bytes(m.mem_read(self.base+0x73450,1),'little'),0,pre.bits(c['initial_stop']),pre.bits(c['initial_take']),read(0x6d670),read(0x724a0),pre.bits(c['key']),len(self.events),hash_bytes(events),hash_bytes(state))
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));s=folder/'tested-sources';s.mkdir()
        for n in NAMES:shutil.copyfile(HOME/'source/MQL5'/n,s/Path(n).name)
        shutil.copyfile(Path(__file__),s/Path(__file__).name);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==value for k,value in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_OR_INPUT_DIFFERS')
    if a.mode=='original':
        require(not (folder/'original-results.bin').exists(),'RESULT_EXISTS');f=v.cpu.CpuFixture()
        try:
            v.cpu.verify_probe(f,current['probe_sha256']);r=Original(f);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));traces=[]
            for c in rows:
                try:raw+=r.run(c)
                except Exception as e:raise RuntimeError('case=%d rva=%#x %s'%(c['id'],r.m.reg_read(r.x.UC_X86_REG_RIP)-r.base,e)) from e
                traces.append(dict(id=c['id'],events=r.events))
            (folder/'original-results.bin').write_bytes(raw);save(folder/'original-traces.json',traces);save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),instructions=sorted(hex(n) for n in r.covered),nan_fixture=r.nan.report(),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(r.covered))))
        finally:f.close()
        return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==NAMES[-1] and type(build['errors']) is int and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,value in current['sources_sha256'].items():require(value==build['sources_sha256'][n]==sha(MT/'MQL5'/n),'SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-management-virtual-store'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b3-store-{a.run}.set';ini=MT/f'b3-store-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementVirtualStoreCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
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
        if left!=right:failed.append(dict(id=c['id'],group=c['group'],native=left,mql5=right))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:12],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
