"""Compare bot1 distance, slippage and store slices with captured native instructions.
prepare|original|mql5|compare RUN [--build BUILD]. No orders are sent.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent

def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
V_PATH=HOME/'tests/check-management-virtual-start.py';CASE_PATH=HOME/'tests/real_blocks_cases.py'
v=module('blocks1_start',V_PATH);pre=v.pre;inputs=module('blocks1_cases',CASE_PATH)
CPU_PATH=ROOT/'cong-cu/doi-chieu-nan-quan-ly.py';cpu=module('blocks1_cpu',CPU_PATH)
sha,require,save=pre.sha,pre.require,pre.save
MT=(ROOT.parent/'.local/mt5-bot1-thread-20261025').resolve();MASK=(1<<64)-1
MAGIC=inputs.MAGIC;ANALYSIS=pre.ANALYSIS;RESULT=struct.Struct('<5iIIQ41QiQQ')
CONTRACT=ROOT/'claude-thuc-hien/bot1-real-three-check-20261026-r1/TASK.md'
BINDINGS=HOME/'phan-tich/dong-vi-the/management-real-three-20261026-r1/native-bindings.json'
NAMES=['Include/bot-cua-toi-1/'+n for n in ['Bot1ManagementPrelude.mqh','Bot1PriceLevels.mqh','Bot1PositionModify.mqh','Bot1PositionClose.mqh','Bot1VirtualStops.mqh','Bot1TradeErrors.mqh','Bot1ManagementMessages.mqh','Bot1TradeSend.mqh','Bot1TradeMessages.mqh','Bot1PendingRequest.mqh','Bot1Filling.mqh','Bot1ManagementRealDistance.mqh','Bot1ManagementRealSlippage.mqh','Bot1ManagementRealStore.mqh']]+['Scripts/bot-cua-toi-1/Bot1ManagementRealBlocksCheck.mq5']
FIELDS=['id','returned','changed','counter','guard','index','error_count','deviation']+inputs.DOUBLES+['volume'+str(i) for i in range(8)]+['level'+str(i) for i in range(8)]+['calls','ordered_hash','table_hash']
SCOPE=dict(calculation_slices_only=True,whole_manager_complete=False,whole_bot_complete=False,modify_child_intercepted=True,close_child_intercepted=True,original_report_text_code_executed=True,error_text_helper_executed=True,successful_string_allocation_supplied=True,signed_decimal_cast_supplied=True,original_ex5_changed=False)
LIMITS=['Three separate real blocks in both directions; not a full manager, event loop, EA or paired terminals run.',
 'Modify and try-close receive supplied replies. Original close ticket comes from RCX; forwarding context fields are supplied and checked only on the MQL5 side.',
 'Native error-code/counter/string/Print code executes. Signed decimal conversion and successful allocation/free are supplied, not allocation failure.',
 'Both-NaN results use measured Windows SSE2 fixtures; remaining native instructions execute in Unicorn. No physical whole-original or MXCSR-status proof.',
 'All API-triggered mutations are supplied provider effects. Unread protocol fields are checked only as provider state: counter/levels/lock fields in all three slices; trail/step/start/limit in store; step in slippage; current_stop outside store. They do not prove calculations in other bot1 blocks.']
SCALARS={0x66d98:'unit',0x66a70:'gap',0x67468:'freeze',0x62580:'current_stop'}
BY_STAGE={0:{0x624a8:'trail',0x624c0:'step',0x624b0:'start',0x624b8:'limit'},1:{0x62400:'trail',0x623f8:'start',0x62408:'limit'}}
STARTS={0:(0x28220,0x2bc82),1:(0x2865c,0x2bfdf),5:(0x29675,0x2cdba)}
EXITS={0:[0x2865c,0x2bfdf],1:[0x28aed,0x2c36e],5:[0x29878,0x2cfb8,0x2a3e5,0x2db64]}

def identity():
    helpers=[V_PATH,CASE_PATH,CPU_PATH,HOME/'tests/check-management-prelude.py',ROOT/'bot-cua-toi-3/tests/real_blocks_cases.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py',BINDINGS]
    return dict(original_ex5_sha256=pre.validation.original_hash(1),tool_sha256=sha(Path(__file__)),analysis_sha256=sha(ANALYSIS/'analysis.json'),contract_sha256=sha(CONTRACT),probe_sha256=sha(cpu.PROBE),helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers},sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES})

def table(c):
    rows=[[10000.+i,20000.+i,-30000.-i] for i in range(500)]
    for row in {0:[0],1:[250],2:[499],3:[1,17,499],4:[],5:[499]}[c['table_pattern']]:rows[row][0]=c['ticket_number']
    if c['table_pattern']==5:rows[0][0]=struct.unpack('<d',struct.pack('<Q',0x7ff8000000000011))[0]
    return struct.pack('<1500d',*(n for row in rows for n in row))

def fnv(raw):
    h=0xcbf29ce484222325
    for b in raw:h=((h^b)*0x100000001b3)&MASK
    return h
class Original(v.Original):
    def __init__(self,fixture):
        super().__init__();m=self.m
        require(self.base==0x23e5aa10000,'B1_BASE_DIFFERS')
        for fn in json.loads(BINDINGS.read_text())['functions']:
            raw=bytes(m.mem_read(self.base+int(fn['begin'],16),int(fn['end'],16)-int(fn['begin'],16)))
            require(__import__('hashlib').sha256(raw).hexdigest()==fn['sha256'],'NATIVE_BINDING_DIFFERS')
        for region in json.loads((ANALYSIS/'analysis.json').read_text())['functions']:
            m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+int(region['rva'],16),end=self.base+int(region['end_rva'],16)-1)
        eb=next(a for a,k in self.apis.items() if k==4)-0x7c2890;address=eb+0x7cf6c0
        if address not in self.apis:
            if not any(lo<=address<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(address&~4095,4096)
            m.mem_write(address,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.apis[address]=46
        self.error_end=0x34148;self.error_bytes_sha256=__import__('hashlib').sha256(bytes(m.mem_read(self.base+0x336d0,self.error_end-0x336d0))).hexdigest()
        m.hook_add(self.uc.UC_HOOK_CODE,self.error_visit,begin=self.base+0x336d0,end=self.base+self.error_end-1)
        self.nan=cpu.BothNaN(self,json.loads((ANALYSIS/'analysis.json').read_text()),fixture)
    def error_visit(self,m,address,size,user):self.error_covered.add(address-self.base)
    def text(self,descriptor):
        ptr=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if not ptr:return ''
        n=struct.unpack('<I',self.m.mem_read(ptr-4,4))[0];require(n<=4096,'BAD_TEXT_LENGTH')
        return bytes(self.m.mem_read(ptr,n*2)).decode('utf-16-le')
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        if off in EXITS[self.case['stage']]:self.stop_rva=off;self.stopped=True;m.emu_stop()
    def read(self,rva):return struct.unpack('<Q',self.m.mem_read(self.base+rva,8))[0]
    def integer(self,rva):return struct.unpack('<i',self.m.mem_read(self.base+rva,4))[0]
    def mutate(self,target):
        if self.case['scenario']!=target:return
        changes=dict(trail=.5,step=.125,start=.25,limit=.75,gap=.125,freeze=.25,lock_start=.5,lock_extra=.25,step_distance=.25,copied_step=.125,current_stop=1.25)
        for rva,key in self.mapping.items():
            if key not in changes and key!='unit':continue
            value=struct.unpack('<d',self.m.mem_read(self.base+rva,8))[0];value=value*2. if key=='unit' else value+changes[key];self.m.mem_write(self.base+rva,struct.pack('<d',value))
        for rva,delta in [(0x67758,.25),(0x67760,.5)]:self.m.mem_write(self.base+rva,struct.pack('<d',struct.unpack('<d',self.m.mem_read(self.base+rva,8))[0]+delta))
        for key,delta in changes.items():
            if key not in self.mapping.values():self.shadow[key]+=delta
        index=(struct.unpack('<I',self.m.mem_read(self.base+0x678f4,4))[0]+1)%8;self.m.mem_write(self.base+0x678f4,struct.pack('<I',index));self.levels[index]+=1.25
        self.counter=(self.counter+1+(1<<31))%(1<<32)-(1<<31)
        guard=self.m.mem_read(self.base+0x66410,1)[0];self.m.mem_write(self.base+0x66410,bytes([(guard+1)%3]));self.deviation=(self.deviation+1)&MASK
    def child(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api==5:
            self.event(5,m.reg_read(x.UC_X86_REG_RCX),m.reg_read(x.UC_X86_REG_XMM1)&MASK,m.reg_read(x.UC_X86_REG_XMM2)&MASK,self.case['modify_ok']);self.mutate(7)
            sp=m.reg_read(x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(sp,8))[0]
            m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret);m.reg_write(x.UC_X86_REG_RAX,self.case['modify_ok']);return
        require(api==8,'UNEXPECTED_CHILD '+str(api))
        self.event(6,m.reg_read(x.UC_X86_REG_RCX),self.deviation,self.read(0x67758),self.read(0x67760));self.event(7,self.read(0x66a70),self.read(0x67468));self.mutate(11);self.closed=1;self.stopped=True;self.stop_rva=address-self.base;m.emu_stop()
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;c=self.case
        if api in [100,101]:return pre.entry.Original.call(self,m,address,size,user)
        if api==46:
            require(m.reg_read(x.UC_X86_REG_R8)==0x52,'ONLY_SIGNED_INT_CAST_SUPPLIED');v=m.reg_read(x.UC_X86_REG_RDX);v=(v+(1<<63))%(1<<64)-(1<<63)
            require(v==c['error_code'],'UNEXPECTED_CAST_VALUE');descriptor=m.reg_read(x.UC_X86_REG_R9);m.mem_write(descriptor,struct.pack('<IQ',0,self.string(str(v))));self.cast_calls+=1;return
        if api==3:
            require(m.reg_read(x.UC_X86_REG_R8)==17 and self.text(m.reg_read(x.UC_X86_REG_RDX))=='CHECK' and self.digit_count<4,'BAD_DIGITS')
            i=self.digit_count;v=c['digits'+str(i)];self.digit_count+=1;self.event(3,17,v,i);m.reg_write(x.UC_X86_REG_RAX,v&MASK);self.mutate([1,3,4,5][i]);return
        if api==4:
            prop=m.reg_read(x.UC_X86_REG_R8);require(prop in [16,34] and self.text(m.reg_read(x.UC_X86_REG_RDX))=='CHECK','BAD_DOUBLE')
            v=c['point' if prop==16 else 'minimum'];i=self.point_count if prop==16 else 0;self.event(4,prop,pre.bits(v),i)
            m.mem_write(self.base+0x6a448,struct.pack('<d',v));m.reg_write(x.UC_X86_REG_XMM0,pre.bits(v))
            if prop==16:self.point_count+=1;require(self.point_count<=2,'TOO_MANY_POINT_CALLS')
            self.mutate([2,6][i] if prop==16 else 10);return
        if api==10:
            require(m.reg_read(x.UC_X86_REG_RDX)==2 and m.reg_read(x.UC_X86_REG_R8)==1 and m.reg_read(x.UC_X86_REG_R9)==0x590008,'BAD_PRINT_SIGNATURE')
            sp=m.reg_read(x.UC_X86_REG_RSP);descriptor=struct.unpack('<Q',m.mem_read(sp+0x28,8))[0];value=self.text(descriptor)
            self.event(13,pre.entry.text_hash(value),struct.unpack('<I',m.mem_read(self.base+0x6a43c,4))[0]);self.prints.append(value)
            self.mutate(8 if value.startswith(('TrailStop error','error:','error when')) else 9);m.reg_write(x.UC_X86_REG_RAX,0);return
        raise ValueError('UNEXPECTED_API '+str(api))
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.events=[];self.prints=[];self.stopped=False;self.closed=0;self.stop_rva=None;self.cursor=0x70001000;self.digit_count=0;self.point_count=0;self.deviation=c['deviation'];self.allocs=self.frees=self.cast_calls=0;self.error_covered=set();self.counter=c['counter'];self.levels=list(c['levels'])
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for reg in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+reg),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        # Both parents clear XMM10 before their loop: 0x27316 / 0x2ace6.
        m.reg_write(x.UC_X86_REG_XMM10,0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        self.mapping=SCALARS|BY_STAGE[0]
        if c['stage']==1:self.mapping={r:k for r,k in self.mapping.items() if k not in BY_STAGE[1].values()}|BY_STAGE[1]
        self.shadow={k:c[k] for k in ['lock_start','lock_extra','step_distance','copied_step']}
        for rva,key in self.mapping.items():m.mem_write(self.base+rva,struct.pack('<d',c[key]))
        m.mem_write(self.base+0x623f0,struct.pack('<i',c['enabled']));m.mem_write(self.base+0x6a410,struct.pack('<i',c['error_code']));m.mem_write(self.base+0x6a43c,struct.pack('<I',c['error_count']));m.mem_write(self.base+0x6a438,b'\0'*4);m.mem_write(self.base+0x6a440,b'\0'*12)
        m.mem_write(self.base+0x66410,bytes([c['guard']]));m.mem_write(self.base+0x678f4,struct.pack('<I',c['index']));m.mem_write(self.base+0x66a80,struct.pack('<8d',*c['volumes']));m.mem_write(self.base+0x62590,table(c));m.mem_write(self.base+0x67758,struct.pack('<2d',c['bid'],c['ask']));m.mem_write(self.base+0x67918,struct.pack('<IQ',0,self.string('CHECK')))
        m.reg_write(x.UC_X86_REG_RSI,0x23e575eae78);m.reg_write(x.UC_X86_REG_RDI,self.base+0x67918);m.reg_write(x.UC_X86_REG_R13,self.base+0x6a448);m.reg_write(x.UC_X86_REG_R14,self.base+0x677f8);m.reg_write(x.UC_X86_REG_R15,self.base+(0x67758 if c['buy'] else 0x67760));m.reg_write(x.UC_X86_REG_R12,self.base+(0x624a8 if c['stage']==0 and c['buy'] else 0x678f4))
        for reg,key in [(6,'open_price'),(7,'tp'),(8,'sl'),(9,'initial_stop'),(11,'ticket_number'),(12,'volume'),(14,'reference'),(15,'anchor')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(reg)),pre.bits(c[key]))
        sp=0x50020000-0x208;m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_RBP,sp+0xa0 if c['buy'] else c['ticket']&MASK)
        m.mem_write(sp+0x30,struct.pack('<q',c['ticket']));m.mem_write(sp+0x88,struct.pack('<d',c['anchor']));m.mem_write(sp+0xa8,struct.pack('<d',c['volume']));m.mem_write(sp+(0x50 if c['buy'] else 0x58),struct.pack('<Q',c['prior_changed']));m.mem_write(sp+(0x5c if c['buy'] else 0x6c),bytes([c['passed_flag']]))
        m.emu_start(self.base+STARTS[c['stage']][0 if c['buy'] else 1],0x60000000,timeout=10000000,count=300000);require(self.stopped,'BOUNDARY_MISSING')
        changed=(struct.unpack('<Q',m.mem_read(sp+(0x50 if c['buy'] else 0x58),8))[0]&255) if c['stage']!=5 else c['prior_changed']
        values={k:pre.bits(c[k]) for k in inputs.DOUBLES};values.update(sl=m.reg_read(x.UC_X86_REG_XMM8)&MASK,tp=m.reg_read(x.UC_X86_REG_XMM7)&MASK,bid=self.read(0x67758),ask=self.read(0x67760))
        for rva,key in self.mapping.items():values[key]=self.read(rva)
        for key,value in self.shadow.items():values[key]=pre.bits(value)
        vector=list(struct.unpack('<8Q',m.mem_read(self.base+0x66a80,64)))+[pre.bits(v) for v in self.levels];raw=b''.join(struct.pack('<5Q',*e) for e in self.events)
        return RESULT.pack(c['id'],self.closed if c['stage']==0 else 0,int(changed!=0),self.counter,m.mem_read(self.base+0x66410,1)[0],struct.unpack('<I',m.mem_read(self.base+0x678f4,4))[0],struct.unpack('<I',m.mem_read(self.base+0x6a43c,4))[0],self.deviation,*(values[k] for k in inputs.DOUBLES),*vector,len(self.events),fnv(raw),fnv(bytes(m.mem_read(self.base+0x62590,12000))))

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
                traces.append(dict(id=c['id'],stage=c['stage'],buy=c['buy'],events=r.events,prints=r.prints,error_native_sites=len(r.error_covered),signed_casts=r.cast_calls))
            (folder/'original-results.bin').write_bytes(raw);save(folder/'original-traces.json',traces);save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),instructions=sorted(hex(n) for n in r.covered),error_helper_bytes_sha256=r.error_bytes_sha256,nan_fixture=r.nan.report(),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(r.covered))))
        finally:f.close()
        return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==NAMES[-1] and type(build['errors']) is int and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,value in current['sources_sha256'].items():require(value==build['sources_sha256'][n]==sha(MT/'MQL5'/n),'SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot1-management-real-blocks'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b1-real-blocks-{a.run}.set';ini=MT/f'b1-real-blocks-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ManagementRealBlocksCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
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
        if left!=right:failed.append(dict(id=c['id'],group=c['group'],buy=c['buy'],stage=c['stage'],differences={k:[a,b] for k,a,b in zip(FIELDS,left,right) if a!=b}))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:15],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
