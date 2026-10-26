"""Compare the original bot1 management router slice with MQL5; no live orders.

prepare -> original -> mql5 --build BUILD -> compare RUN. Manager replies supplied.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent

def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
PRE_PATH=HOME/'tests/check-management-prelude.py';pre=module('router1_pre',PRE_PATH)
CASE_PATH=HOME/'tests/router_cases.py'
PUB_PATH=ROOT/'cong-cu/kiem-ban-git-quan-ly.py';pub=module('router1_closure',PUB_PATH)
sha,require,save=pre.sha,pre.require,pre.save
MT=(ROOT.parent/'.local/mt5-bot1-thread-20261025').resolve();MASK=(1<<64)-1
SCRIPT='Scripts/bot-cua-toi-1/Bot1ManagementRouterCheck.mq5'
BINDINGS=HOME/'phan-tich/chuong-trinh-chinh/management-router-20261026-r1/native-bindings.json'
CONTRACT=ROOT/'claude-thuc-hien/bot1-main-router-check-20261026-r1/TASK.md'
RESULT=struct.Struct('<12i2Q8q')
FIELDS=['id','returned','timeframe','counter','mode','index','events','selected','total_calls','buy_calls','sell_calls','live_count','last_ticket','ordered_hash']+['bar'+str(i) for i in range(8)]
SCOPE=dict(whole_manager_complete=False,whole_bot_complete=False,full_ea=False,native_caller_slice_executed=True,child_helpers_intercepted=True,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Only the existing validity-flag branch, route selection, ordered position counts, new-bar reads/write and manager-call ordering execute. This is not the complete coordinator or EA.',
 'The flag is supplied solely as a fixture input to the unchanged check. No license check is removed, forced valid, rewritten or patched.',
 'Both manager bodies and terminal replies/effects are supplied; management bodies have separate scoped comparisons.',
 'Valid indices0..7 and successful string allocation only. No all-broker/invalid-index/lifecycle/allocation-failure claim.']

def identity():
    base=HOME/'source/MQL5';names=sorted(p.relative_to(base.resolve()).as_posix() for p in pub.closure(base/SCRIPT,base))
    return dict(original_ex5_sha256=pre.validation.original_hash(1),tool_sha256=sha(Path(__file__)),contract_sha256=sha(CONTRACT),helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in [PRE_PATH,CASE_PATH,PUB_PATH,BINDINGS,ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py']},sources_sha256={n:sha(base/n) for n in names})

def fnv(raw):
    value=0xcbf29ce484222325
    for byte in raw:value=((value^byte)*0x100000001b3)&MASK
    return value

class Original(pre.entry.Original):
    def __init__(self):
        super().__init__(1);require(self.base==0x23e5aa10000,'BASE_DIFFERS');m=self.m
        binding=json.loads(BINDINGS.read_bytes());begin=int(binding['function']['rva'],16);end=int(binding['function']['end'],16)
        require(pre.validation.original_hash(1)==binding['original_ex5_sha256'],'ORIGINAL_EX5_DIFFERS')
        require(__import__('hashlib').sha256(bytes(m.mem_read(self.base+begin,end-begin))).hexdigest()==binding['function']['sha256'],'CALLER_BYTES_DIFFER')
        sdk=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        for off,api in {0x7d3b50:200,0x7d7da0:205,0x7d7df0:206,0x7d7fc0:207,0x7d8010:208,0x7b49f0:204}.items():
            address=sdk+off
            if address not in self.apis:
                if not any(lo<=address<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(address&~4095,4096)
                m.mem_write(address,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
            self.apis[address]=api
        for off in [0x271f0,0x2abc0]:m.hook_add(self.uc.UC_HOOK_CODE,self.child,begin=self.base+off,end=self.base+off)
        m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x1a152,end=self.base+0x1a63a);self.covered=set()
    def event(self,*words):
        require(len(words)==5,'BAD_EVENT_WIDTH');self.events.append([value&MASK for value in words])
    def integer(self,off):return struct.unpack('<i',self.m.mem_read(self.base+off,4))[0]
    def word(self,off):return struct.unpack('<Q',self.m.mem_read(self.base+off,8))[0]
    def bar(self):return struct.unpack('<q',self.m.mem_read(self.base+0x66750+self.case['index']*8,8))[0]
    def set_bar(self,value):self.m.mem_write(self.base+0x66750+self.case['index']*8,struct.pack('<q',value))
    def text(self,descriptor):
        pointer=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if not pointer:return ''
        length=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(length<4096,'STRING_TOO_LONG')
        return bytes(self.m.mem_read(pointer,length*2)).decode('utf-16-le')
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        if off in [0x1a620,0x1a63a]:self.stop=off;m.emu_stop()
    def call(self,m,address,size,user):
        api=self.apis[address]
        if api in [100,101]:return super().call(m,address,size,user)
        x=self.x;c=self.case;r=lambda name:m.reg_read(getattr(x,'UC_X86_REG_'+name));a=r('RDX')
        if api==200:
            require(self.time_calls<2 and self.text(a)=='CHECK' and r('R9')==1,'BAD_TIME_CALL')
            value=c['observed'] if self.time_calls==0 else c['second'];self.event(1,r('R8')&0xffffffff,1,self.bar(),value)
            if self.time_calls==0:
                m.mem_write(self.base+0x6248c,struct.pack('<i',c['after_first_frame']))
                if c['change_first_bar']:self.set_bar(c['after_first_bar'])
            self.time_calls+=1
        elif api==205:
            self.total_calls+=1;value=0 if c['profile']==7 and self.total_calls==2 else len(self.positions)
            self.event(5,self.total_calls,value,len(self.positions),0)
        elif api==206:
            index=a&0xffffffff;value=self.positions[index][0] if index<len(self.positions) else 0
            if value:self.selected=index
            self.event(6,index,value,self.selected,0)
        elif api in [207,208]:
            require(0<=self.selected<len(self.positions),'READ_WITHOUT_SELECTION');row=self.positions[self.selected]
            if api==207:
                require(a in [2,12],'BAD_POSITION_INTEGER');value=row[1 if a==12 else 2];self.event(7,a,value,self.selected,0)
            else:
                require(a==0,'BAD_POSITION_STRING');text=row[3];self.event(8,a,pre.entry.text_hash(text),self.selected,0)
                m.mem_write(self.base+0x6a43c,struct.pack('<IQ',0,self.string(text)));value=0
        elif api==204:
            require(a==2 and r('R8')==1 and r('R9')==0x590008,'BAD_PRINT_SIGNATURE')
            ptr=struct.unpack('<Q',m.mem_read(r('RSP')+0x28,8))[0];text=self.text(ptr);require(text=='Licence not valid!','BAD_GUARD_MESSAGE')
            self.event(4,pre.entry.text_hash(text),0,0,0);value=0
        else:raise ValueError('UNEXPECTED_API '+str(api))
        m.reg_write(x.UC_X86_REG_RAX,value&MASK)
    def child(self,m,address,size,user):
        c=self.case;x=self.x;buy=address==self.base+0x271f0
        if buy:self.buy_calls+=1;require(self.buy_calls==1 and self.sell_calls==0,'BAD_BUY_ORDER')
        else:self.sell_calls+=1;require(self.sell_calls==1,'BAD_SELL_ORDER')
        self.event(2 if buy else 3,self.integer(0x673f0),self.integer(0x6241c),self.integer(0x678f4),self.word(0x670d0 if buy else 0x66db0))
        if buy and c['change_buy']:
            for off in [0x673f0,0x6241c]:m.mem_write(self.base+off,struct.pack('<i',self.integer(off)+1))
            m.mem_write(self.base+0x678f4,struct.pack('<I',(self.integer(0x678f4)+1)%8));self.set_bar(self.bar()+10)
        if buy and c['shrink_after_buy']:self.positions=[];self.selected=-1
        sp=m.reg_read(x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(sp,8))[0]
        m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret);m.reg_write(x.UC_X86_REG_RAX,c['buy_reply' if buy else 'sell_reply'])
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.events=[];self.time_calls=self.buy_calls=self.sell_calls=self.total_calls=0;self.selected=-1;self.stop=None
        self.cursor=0x70001000;self.allocs=self.frees=0;k=c['magic']
        profiles=[[],[(101,k,0,'CHECK')],[(102,k,1,'CHECK')],[(0,k,0,'CHECK'),(202,k+1,0,'CHECK'),(203,k,2,'CHECK'),(204,k,0,'OTHER'),(205,k,0,'CHECK'),(206,k,1,'CHECK')],[(301,k+(1<<32),0,'CHECK'),(302,k+(1<<32),1,'CHECK')],[(401,k,1<<32,'CHECK'),(402,k,(1<<32)+1,'CHECK')],[(501,k,0,'OTHER'),(502,k,1,'OTHER')],[(601,k,0,'CHECK'),(602,k,1,'CHECK')]]
        self.positions=list(profiles[c['profile']])
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.mem_write(0x50000000,b'\0'*0x20000)
        m.mem_write(self.base+0x67918,struct.pack('<IQ',0,self.string('CHECK')));m.mem_write(self.base+0x66750,struct.pack('<8q',*[100+i for i in range(8)]));self.set_bar(c['previous'])
        for off,value in [(0x6248c,c['timeframe']),(0x673f0,7),(0x6241c,1),(0x678f4,(c['index']+1)%8),(0x6246c,k)]:m.mem_write(self.base+off,struct.pack('<i',value))
        for off,key in [(0x67470,'license_valid'),(0x62490,'tick_management'),(0x62000,'bar_override')]:m.mem_write(self.base+off,bytes([c[key]]))
        m.mem_write(self.base+0x677f8,struct.pack('<Q',999));m.mem_write(self.base+0x670d0,struct.pack('<8d',*[10.+i for i in range(8)]));m.mem_write(self.base+0x66db0,struct.pack('<8d',*[20.+i for i in range(8)]))
        top=0x50020000-0x108;m.reg_write(x.UC_X86_REG_RSP,top);m.mem_write(top+0xbc,struct.pack('<I',c['index']))
        m.emu_start(self.base+0x1a152,0x60000000,timeout=2000000,count=200000);require(self.stop is not None,'SLICE_DID_NOT_FINISH')
        raw=b''.join(struct.pack('<5Q',*event) for event in self.events);bars=struct.unpack('<8q',m.mem_read(self.base+0x66750,64))
        return RESULT.pack(c['id'],int(self.stop==0x1a63a),self.integer(0x6248c),self.integer(0x673f0),self.integer(0x6241c),self.integer(0x678f4),len(self.events),self.selected,self.total_calls,self.buy_calls,self.sell_calls,len(self.positions),self.word(0x677f8),fnv(raw),*bars)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN')
    inputs=module('router1_inputs',CASE_PATH);folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=inputs.cases();current=identity()
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
        files=MT/'MQL5/Files/bot1-management-router'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/('b1-router-'+a.run+'.set');ini=MT/('b1-router-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ManagementRouterCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
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
