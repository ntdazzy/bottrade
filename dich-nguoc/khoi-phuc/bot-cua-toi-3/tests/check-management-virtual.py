"""Compare three Bot3 virtual trailing segments with original instructions.
Usage: check-management-virtual.py prepare|original|mql5|compare RUN [--build BUILD]
Only dedicated .local/mt5-bot3-thread-20261025 is used. Close guard is intercepted.
The 560 cases reuse the verified Bot1 matrix schema, with stage 0 excluded.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
PRE_PATH=ROOT/'bot-cua-toi-1/tests/check-management-prelude.py'
CASES_PATH=ROOT/'bot-cua-toi-1/tests/check-management-virtual-start.py'
pre=module('virtual3_helpers',PRE_PATH);matrix=module('virtual3_case_matrix',CASES_PATH)
MAGIC=0x4d565333;RESULT=struct.Struct('<iii6QiQ');MASK=(1<<64)-1
ANALYSIS=HOME/'phan-tich/dong-vi-the/management-20261025-r1'
CONTRACT=HOME/'phan-tich/dong-vi-the/management-virtual-20261025-r1/contract.md'
MT=(ROOT.parent/'.local/mt5-bot3-thread-20261025').resolve()
NAMES=['Include/bot-cua-toi-3/'+n for n in ['Bot3ManagementVirtual.mqh','Bot3ManagementPrelude.mqh',
       'Bot3PriceLevels.mqh','Bot3PositionModify.mqh','Bot3PositionClose.mqh','Bot3TradeSend.mqh',
       'Bot3TradeMessages.mqh','Bot3PendingRequest.mqh','Bot3Filling.mqh']]+['Scripts/bot-cua-toi-3/Bot3ManagementVirtualCheck.mq5']
SCOPE=dict(slice_only=True,whole_manager_complete=False,whole_bot_complete=False,helper_children_intercepted=True)
LIMITS=['Only three virtual trailing segments, not the initial virtual stop/take, remaining manager or EA.',
        'Terminal replies are supplied. Close guard 0x47d20 is recorded but not executed; MQL5 verifies its forwarded values.',
        'Inputs use valid volume indices; no out-of-range or allocation-failure proof.']
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def require(ok,message):
    if not ok:raise ValueError(message)
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2)
def cases():
    rows=[dict(c) for c in matrix.cases() if c['stage'] in [1,2,3]]
    for i,c in enumerate(rows):
        c['id']=i
        require(c['distance_passed'] in [0,1] and 0<=c['strategy_index']<9,'CASE_OUTSIDE_CONTRACT')
    return rows
def encode(rows):return struct.pack('<i',MAGIC)+matrix.encode(rows)[4:]
def identity():
    return dict(original_ex5_sha256=pre.validation.original_hash(3),tool_sha256=sha(Path(__file__)),
                analysis_sha256=sha(ANALYSIS/'analysis.json'),contract_sha256=sha(CONTRACT),
                helpers_sha256={str(p.relative_to(ROOT)):sha(p) for p in [PRE_PATH,CASES_PATH,ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',
                ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py']},
                sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES})
class Original(pre.entry.Original):
    def __init__(self):
        super().__init__(3);m=self.m;self.covered=set()
        data=json.loads((ANALYSIS/'analysis.json').read_text())
        require(pre.validation.original_hash(3)==data['original_ex5_sha256'],'EX5_DIFFERS')
        for f in data['functions']:
            lo,hi=int(f['rva'],16),int(f['end_rva'],16)
            require(hashlib.sha256(bytes(m.mem_read(self.base+lo,hi-lo))).hexdigest()==f['native_bytes_sha256'],'NATIVE_CODE_DIFFERS')
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        for a,k in list(self.apis.items()):
            if k not in [100,101]:self.apis[a]=0
        for rva,api in [(0x7c2890,4),(0x7d1c40,9),(0x7b49f0,10)]:
            a=eb+rva
            if a in self.apis:self.apis[a]=api;continue
            if not any(lo<=a<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(a&~4095,4096)
            self.apis[a]=api;m.mem_write(a,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        a=self.base+0x47d20;self.apis[a]=8;m.hook_add(self.uc.UC_HOOK_CODE,self.child,begin=a,end=a)
        m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x35f8f,end=self.base+0x3b864)
    def event(self,api,a=0,b=0,v=0,w=0):self.events.append([api,a&MASK,b&MASK,v&MASK,w&MASK])
    def changed(self,api):
        targets=[0x6d670] if (self.case['scenario'],api)==(2,4) else []
        if (self.case['scenario'],api) in [(4,9),(5,4),(6,10)]:targets=[0x6d670,0x74798,0x747a0]
        for rva in targets:
            p=self.base+rva;value=struct.unpack('<d',self.m.mem_read(p,8))[0];self.m.mem_write(p,struct.pack('<d',value+1.25))
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        exits={1:[0x35fd3,0x367f4,0x3a2f7],2:[0x36189,0x3a4af],3:[0x36667,0x3672c,0x36736,0x36813,0x3a97d]}[self.case['stage']]
        if off in exits:self.stopped=True;m.emu_stop()
    def child(self,m,address,size,user):
        self.event(8,m.reg_read(self.x.UC_X86_REG_RCX));self.closed=1;self.stopped=True;m.emu_stop()
    def text(self,descriptor):
        ptr=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0];require(ptr!=0,'NULL_SYMBOL')
        count=struct.unpack('<I',self.m.mem_read(ptr-4,4))[0];require(count<=200,'TEXT_TOO_LONG')
        return bytes(self.m.mem_read(ptr,count*2)).decode('utf-16-le')
    def call(self,m,address,size,user):
        c=self.case;x=self.x;api=self.apis[address];prop=m.reg_read(x.UC_X86_REG_R8)
        if api in [100,101]:return super().call(m,address,size,user)
        if api==4:
            require(prop in [16,34] and self.text(m.reg_read(x.UC_X86_REG_RDX))=='CHECK','BAD_SYMBOL_DOUBLE')
            value=c['point' if prop==16 else 'minimum'];self.event(api,prop,pre.bits(value))
            m.mem_write(self.base+0x1d6e48,struct.pack('<d',value));m.reg_write(x.UC_X86_REG_XMM0,pre.bits(value))
        elif api==9:
            require(m.reg_read(x.UC_X86_REG_RDX)==0,'BAD_TIME_OVERLOAD')
            self.event(api,c['now']);m.reg_write(x.UC_X86_REG_RAX,c['now']&MASK)
        elif api==10:
            require(m.reg_read(x.UC_X86_REG_RDX)==2 and prop==1 and m.reg_read(x.UC_X86_REG_R9)==0x590008,'BAD_PRINT')
            descriptor=struct.unpack('<Q',m.mem_read(m.reg_read(x.UC_X86_REG_RSP)+0x28,8))[0]
            text=self.text(descriptor);require(text in ['Slippage control active','Slippage controle active'],'UNEXPECTED_MESSAGE')
            self.event(api,pre.entry.text_hash(text));m.reg_write(x.UC_X86_REG_RAX,0)
        else:raise ValueError('UNEXPECTED_API '+str(api))
        self.changed(api)
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.closed=0;self.stopped=False;self.events=[];self.cursor=0x70001000
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        settings=[(0x73dd8,'unit'),(0x6d670,'level'),(0x6d5e8,'activation'),(0x6d5f0,'distance'),(0x744a8,'freeze'),
                  (0x6d598,'trail'),(0x6d5b0,'trail_step'),(0x6d5a0,'trail_start'),(0x6d5a8,'trail_limit'),
                  (0x6d4f8,'trail'),(0x6d4f0,'trail_start'),(0x6d500,'trail_limit')]
        for rva,key in settings:m.mem_write(self.base+rva,struct.pack('<d',c[key]))
        m.mem_write(self.base+0x7449c,struct.pack('<i',c['delay_seconds']));m.mem_write(self.base+0x6d4e8,struct.pack('<i',c['slippage_enabled']))
        m.mem_write(self.base+0x74934,struct.pack('<I',c['strategy_index']));m.mem_write(self.base+0x73ac0+8*c['strategy_index'],struct.pack('<d',c['table_volume']))
        m.mem_write(self.base+0x73ab0,struct.pack('<d',1.25));m.mem_write(self.base+0x74798,struct.pack('<2d',c['bid'],c['ask']))
        m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string('CHECK')))
        m.reg_write(x.UC_X86_REG_RDI,self.base+0x74958);m.reg_write(x.UC_X86_REG_R13,self.base+0x1d6e48)
        m.reg_write(x.UC_X86_REG_R14,self.base+0x1d6e48);m.reg_write(x.UC_X86_REG_R12,c['changed'])
        for reg,key in [(6,'open'),(7,'tp'),(8,'sl'),(13,'volume'),(15,'anchor')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(reg)),pre.bits(c[key]))
        sp=0x50020000-0x208;m.reg_write(x.UC_X86_REG_RSP,sp)
        m.mem_write(sp+(0x60 if c['buy'] else 0x70),struct.pack('<q',c['opened']))
        m.mem_write(sp+(0x78 if c['buy'] else 0x88),struct.pack('<d',c['anchor']))
        m.mem_write(sp+(0x5c if c['buy'] else 0x54),struct.pack('<i',c['distance_passed']))
        m.mem_write(sp+(0x40 if c['buy'] else 0x48),struct.pack('<Q',c['ticket']&MASK))
        start={1:(0x35f8f,0x3a21a),2:(0x35fd3,0x3a2f7),3:(0x364e2,0x3a803)}[c['stage']][0 if c['buy'] else 1]
        m.emu_start(self.base+start,0x60000000,timeout=5000000,count=100000)
        require(self.stopped,'BOUNDARY_MISSING '+str(c['id']))
        h=0xcbf29ce484222325
        for event in self.events:
            for b in struct.pack('<5Q',*event):h=((h^b)*0x100000001b3)&MASK
        current=struct.unpack('<Q',m.mem_read(self.base+0x6d670,8))[0];tick=struct.unpack('<2Q',m.mem_read(self.base+0x74798,16))
        return RESULT.pack(c['id'],self.closed,int((m.reg_read(x.UC_X86_REG_R12)&255)!=0),
                           pre.bits(c['level']),current,pre.bits(c['sl']),pre.bits(c['tp']),*tick,len(self.events),h)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args()
    require(bool(re.fullmatch('[a-z0-9-]{1,50}',a.run)),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));tested=folder/'tested-sources';tested.mkdir()
        for n in NAMES:shutil.copyfile(HOME/'source/MQL5'/n,tested/Path(n).name)
        for path in [Path(__file__),PRE_PATH,CASES_PATH]:shutil.copyfile(path,tested/path.name)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()),'IDENTITY_DIFFERS')
    require(baseline['inputs_sha256']==sha(folder/'cases.bin') and (folder/'cases.bin').read_bytes()==encode(rows),'INPUTS_DIFFERS')
    if a.mode=='original':
        require(not (folder/'original-results.bin').exists(),'RESULT_EXISTS');runner=Original()
        data=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));traces=[]
        for c in rows:
            try:data+=runner.run(c)
            except Exception as e:raise RuntimeError('case=%d stage=%d buy=%d rva=%#x %s'%(c['id'],c['stage'],c['buy'],runner.m.reg_read(runner.x.UC_X86_REG_RIP)-runner.base,e)) from e
            if c['id']<6:traces.append(dict(id=c['id'],events=runner.events))
        (folder/'original-results.bin').write_bytes(data);save(folder/'original-traces.json',traces)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),executed_instructions=sorted(hex(v) for v in runner.covered),**SCOPE))
        print(json.dumps({'cases':len(rows),'instructions':len(runner.covered)}));return
    if a.mode=='mql5':
        require(bool(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build)),'BUILD_REQUIRED')
        receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==NAMES[-1] and type(build['errors']) is int and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,value in current['sources_sha256'].items():require(build['sources_sha256'][n]==value==sha(MT/'MQL5'/n),'SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-management-virtual'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b3-virtual-{a.run}.set';ini=MT/f'b3-virtual-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementVirtualCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),
             binary_sha256=sha(binary),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps({'cases':len(rows),'exit_code':code}));return
    for n in ['original-run.json','mql5-run.json']:
        record=json.loads((folder/n).read_text());require(all(record[k]==v for k,v in current.items()),'RUN_IDENTITY_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes()
    require(native[:12]==actual[:12]==struct.pack('<3i',MAGIC,1,len(rows)) and len(native)==len(actual)==12+RESULT.size*len(rows),'BAD_RESULTS')
    failed=[];groups={}
    for c in rows:
        g=groups.setdefault(str(c['stage']),dict(cases=0,matched=0));g['cases']+=1
        off=12+c['id']*RESULT.size;n=RESULT.unpack_from(native,off);r=RESULT.unpack_from(actual,off)
        if n==r:g['matched']+=1
        else:failed.append(dict(id=c['id'],group=c['group'],stage=c['stage'],buy=c['buy'],native=n,mql5=r))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),groups=groups,first_failures=failed[:12],
                hashes={n:sha(folder/n) for n in ['cases.bin','original-results.bin','mql5-results.bin']},**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
