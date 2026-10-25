"""Compare six real management blocks, including native error text and string building.
prepare|original|mql5|compare RUN [--build BUILD]. No orders are sent.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
V_PATH=HOME/'tests/check-management-virtual-levels.py';CASE_PATH=HOME/'tests/real_blocks_cases.py'
V=module('blocks3_levels',V_PATH);inputs=module('blocks3_cases',CASE_PATH)
pre,cpu,sha,require,save,MT=V.pre,V.cpu,V.sha,V.require,V.save,V.MT
MASK=V.MASK;MAGIC=inputs.MAGIC;ANALYSIS=V.ANALYSIS;RESULT=struct.Struct('<5iIIQ43QiQQ')
CONTRACT=ROOT/'claude-thuc-hien/bot3-real-blocks-check-20261025-r1/CONTRACT.md'
NAMES=[n for n in V.NAMES if not n.endswith(('Bot3ManagementVirtualStart.mqh','Bot3ManagementVirtualTake.mqh','Bot3ManagementVirtualLevelsCheck.mq5'))]+['Include/bot-cua-toi-3/'+n for n in ['Bot3ManagementVirtualFinish.mqh','Bot3ManagementMessages.mqh','Bot3TradeErrors.mqh','Bot3ManagementRealDistance.mqh','Bot3ManagementRealSlippage.mqh','Bot3ManagementRealHighLow.mqh','Bot3ManagementRealLock.mqh','Bot3ManagementRealCounter.mqh','Bot3ManagementRealStore.mqh']]+['Scripts/bot-cua-toi-3/Bot3ManagementRealBlocksCheck.mq5']
FIELDS=['id','returned','changed','counter','guard','index','error_count','deviation']+inputs.DOUBLES+['volume'+str(i) for i in range(9)]+['level'+str(i) for i in range(9)]+['calls','ordered_hash','table_hash']
SCOPE=dict(calculation_slices_only=True,whole_manager_complete=False,whole_bot_complete=False,modify_child_intercepted=True,close_child_intercepted=True,original_report_text_code_executed=True,error_text_helper_executed=True,successful_string_allocation_supplied=True,signed_decimal_cast_supplied=True,original_ex5_changed=False)
LIMITS=['Six separate real blocks; not a full manager, event loop, EA or paired terminals run.',
 'Modify and try-close receive supplied replies. The native close ticket is read from RCX; its other context values are checked as MQL5 forwarding only, not by executing the original close child.',
 'Native error-code selection/counter, string building and Print calls execute. Signed decimal conversion and successful string allocation/free are supplied, not allocation failures.',
 'Both-NaN arithmetic uses the measured Windows SSE2 fixtures; other native instructions execute in Unicorn. No physical whole-original or MXCSR-status comparison.']
SCALARS={0x73dd8:'unit',0x73ab0:'gap',0x744a8:'freeze',0x6d5b8:'lock_start',0x6d5c0:'lock_extra',0x6d610:'step_distance',0x74428:'copied_step',0x6d600:'step_reference',0x6d670:'current_stop'}
BY_STAGE={0:{0x6d598:'trail',0x6d5b0:'step',0x6d5a0:'start',0x6d5a8:'limit'},1:{0x6d4f8:'trail',0x6d4f0:'start',0x6d500:'limit'}}
STARTS={0:(0x34138,0x38776),1:(0x34b22,0x39064),2:(0x34fc6,0x393fa),3:(0x35458,0x397df),4:(0x358b1,0x39b32),5:(0x35b54,0x39de8)}
EXITS={0:[0x34564,0x34589,0x34593,0x34b22,0x38aaa,0x3905a,0x39064],1:[0x34fad,0x34fc6,0x34fda,0x393fa],2:[0x35458,0x35462,0x397df,0x397e9],3:[0x358b1,0x35b30,0x39b32,0x39dc0],4:[0x35b30,0x39dc0],5:[0x35d52,0x36844,0x39fe2,0x3aa3d]}
def identity():
    old=V.identity()
    return dict(original_ex5_sha256=old['original_ex5_sha256'],tool_sha256=sha(Path(__file__)),analysis_sha256=sha(ANALYSIS/'analysis.json'),contract_sha256=sha(CONTRACT),probe_sha256=sha(cpu.PROBE),helpers_sha256=old['helpers_sha256']|{str(p.relative_to(ROOT)):sha(p) for p in [V_PATH,CASE_PATH]},sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES})
def table(c):
    rows=[[10000.+i,20000.+i,-30000.-i] for i in range(500)];takes=[[40000.+i,-50000.-i] for i in range(500)]
    for row in {0:[0],1:[250],2:[499],3:[1,17,499],4:[],5:[499]}[c['table_pattern']]:rows[row][0]=c['ticket_number']
    if c['table_pattern']==5:rows[0][0]=struct.unpack('<d',struct.pack('<Q',0x7ff8000000000011))[0]
    return struct.pack('<1500d',*(n for r in rows for n in r)),struct.pack('<1000d',*(n for r in takes for n in r))
def fnv(raw):
    h=0xcbf29ce484222325
    for b in raw:h=((h^b)*0x100000001b3)&MASK
    return h
class Original(V.Original):
    def __init__(self,fixture):
        super().__init__(fixture)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x34138,end=self.base+0x35d54)
        eb=next(a for a,k in self.apis.items() if k==4)-0x7c2890;address=eb+0x7cf6c0
        if address not in self.apis:
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.apis[address]=46
        meta=json.loads((HOME/'phan-tich/luot-20261023-data/metadata/import.json').read_text());row=next(r for r in meta['functions'] if int(r['begin_rva'],16)==0x3ee80)
        self.error_end=int(row['end_rva'],16);self.error_bytes_sha256=sha_bytes=__import__('hashlib').sha256(bytes(self.m.mem_read(self.base+0x3ee80,self.error_end-0x3ee80))).hexdigest()
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.error_visit,begin=self.base+0x3ee80,end=self.base+self.error_end-1)
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
        for rva,delta in [(0x74798,.25),(0x747a0,.5)]:self.m.mem_write(self.base+rva,struct.pack('<d',struct.unpack('<d',self.m.mem_read(self.base+rva,8))[0]+delta))
        index=(struct.unpack('<I',self.m.mem_read(self.base+0x74934,4))[0]+1)%9;self.m.mem_write(self.base+0x74934,struct.pack('<I',index))
        q=self.level_base+index*8;self.m.mem_write(self.base+q,struct.pack('<d',struct.unpack('<d',self.m.mem_read(self.base+q,8))[0]+1.25))
        value=struct.unpack('<I',self.m.mem_read(self.base+0x74430,4))[0];self.m.mem_write(self.base+0x74430,struct.pack('<I',(value+1)&0xffffffff))
        guard=self.m.mem_read(self.base+0x73450,1)[0];self.m.mem_write(self.base+0x73450,bytes([(guard+1)%3]));self.deviation=(self.deviation+1)&MASK
    def changed(self,api):
        if api==5:self.mutate(7)
    def child(self,m,address,size,user):
        if self.apis[address]!=8:return super().child(m,address,size,user)
        self.event(6,m.reg_read(self.x.UC_X86_REG_RCX),self.deviation,self.read(0x74798),self.read(0x747a0));self.event(7,self.read(0x73ab0),self.read(0x744a8));self.mutate(11);self.closed=1;self.stopped=True;self.stop_rva=address-self.base;m.emu_stop()
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
            m.mem_write(self.base+0x1d6e48,struct.pack('<d',v));m.reg_write(x.UC_X86_REG_XMM0,pre.bits(v))
            if prop==16:self.point_count+=1;require(self.point_count<=2,'TOO_MANY_POINT_CALLS')
            self.mutate([2,6][i] if prop==16 else 10);return
        if api==10:
            require(m.reg_read(x.UC_X86_REG_RDX)==2 and m.reg_read(x.UC_X86_REG_R8)==1 and m.reg_read(x.UC_X86_REG_R9)==0x590008,'BAD_PRINT_SIGNATURE')
            sp=m.reg_read(x.UC_X86_REG_RSP);descriptor=struct.unpack('<Q',m.mem_read(sp+0x28,8))[0];value=self.text(descriptor)
            self.event(13,pre.entry.text_hash(value),struct.unpack('<I',m.mem_read(self.base+0x7448c,4))[0]);self.prints.append(value)
            self.mutate(8 if value.startswith(('TrailStop error','error:','error when')) else 9);m.reg_write(x.UC_X86_REG_RAX,0);return
        raise ValueError('UNEXPECTED_API '+str(api))
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.events=[];self.prints=[];self.stopped=False;self.closed=0;self.stop_rva=None;self.cursor=0x70001000;self.digit_count=0;self.point_count=0;self.deviation=c['deviation'];self.allocs=self.frees=self.cast_calls=0;self.error_covered=set()
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for reg in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+reg),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        self.mapping=SCALARS|BY_STAGE.get(c['stage'],{})
        for rva,key in self.mapping.items():m.mem_write(self.base+rva,struct.pack('<d',c[key]))
        for rva,key in [(0x6d4e8,'enabled'),(0x6d5d4,'enabled'),(0x6d3c0,'gap_count'),(0x6d608,'minimum_steps'),(0x74430,'counter'),(0x1d6e10,'error_code')]:m.mem_write(self.base+rva,struct.pack('<i',c[key]))
        m.mem_write(self.base+0x7448c,struct.pack('<I',c['error_count']));m.mem_write(self.base+0x1d6e3c,b'\0'*12)
        for rva,key in [(0x6d5c8,'before_open'),(0x6d5dc,'shift_setting'),(0x6d5f8,'step_enabled'),(0x73450,'guard')]:m.mem_write(self.base+rva,bytes([c[key]]))
        self.level_base=0x74110 if c['buy'] else 0x73df0
        m.mem_write(self.base+0x74934,struct.pack('<I',c['index']));m.mem_write(self.base+0x73ac0,struct.pack('<9d',*c['volumes']));m.mem_write(self.base+self.level_base,struct.pack('<9d',*c['levels']))
        stop,take=table(c);m.mem_write(self.base+0x6d680,stop);m.mem_write(self.base+0x70560,take)
        m.mem_write(self.base+0x74798,struct.pack('<2d',c['bid'],c['ask']));m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string('CHECK')))
        m.reg_write(x.UC_X86_REG_RDI,self.base+0x74958);m.reg_write(x.UC_X86_REG_R13,self.base+0x1d6e48);m.reg_write(x.UC_X86_REG_R14,self.base+0x1d6e48);m.reg_write(x.UC_X86_REG_R15,self.base+(0x74798 if c['buy'] else 0x747a0))
        for reg,key in [(6,'open_price'),(7,'tp'),(8,'sl'),(9,'initial_stop'),(12,'ticket_number'),(13,'volume'),(15,'reference')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(reg)),pre.bits(c[key]))
        r12={0:0x6d598 if c['buy'] else 0x74934,1:0x74934,2:0x74934,3:0,4:0,5:0}[c['stage']];m.reg_write(x.UC_X86_REG_R12,self.base+r12 if r12 else c['prior_changed'])
        sp=0x50020000-0x208;m.reg_write(x.UC_X86_REG_RSP,sp);self.sp=sp
        # Report blocks inherit this live caller value; the numeric-only checks did not use it.
        m.reg_write(x.UC_X86_REG_RBP,sp+0x68 if c['buy'] else self.base+0x4a0)
        m.mem_write(sp+(0x40 if c['buy'] else 0x48),struct.pack('<q',c['ticket']));m.mem_write(sp+(0x78 if c['buy'] else 0x88),struct.pack('<d',c['anchor']))
        m.mem_write(sp+(0x48 if c['buy'] else 0x68),struct.pack('<Q',c['prior_changed']));m.mem_write(sp+(0x5c if c['buy'] else 0x54),bytes([c['passed_flag']]));m.mem_write(sp+(0x3f if c['buy'] else 0x37),bytes([c['eligible_flag']]))
        start=STARTS[c['stage']][0 if c['buy'] else 1]
        m.emu_start(self.base+start,0x60000000,timeout=10000000,count=300000);require(self.stopped,'BOUNDARY_MISSING')
        if c['stage'] in [0,1,2]:changed=struct.unpack('<Q',m.mem_read(sp+(0x48 if c['buy'] else 0x68),8))[0]&255
        elif c['stage']==3 and self.stop_rva in [0x358b1,0x39b32]:changed=c['prior_changed']
        else:changed=(m.reg_read(x.UC_X86_REG_R12)&255) if c['stage'] in [3,4] else c['prior_changed']
        values={k:pre.bits(c[k]) for k in inputs.DOUBLES};values.update(sl=m.reg_read(x.UC_X86_REG_XMM8)&MASK,tp=m.reg_read(x.UC_X86_REG_XMM7)&MASK,bid=self.read(0x74798),ask=self.read(0x747a0))
        for rva,key in self.mapping.items():values[key]=self.read(rva)
        vector=list(struct.unpack('<9Q',m.mem_read(self.base+0x73ac0,72)))+list(struct.unpack('<9Q',m.mem_read(self.base+self.level_base,72)))
        raw=b''.join(struct.pack('<5Q',*e) for e in self.events);rows=bytes(m.mem_read(self.base+0x6d680,12000))+bytes(m.mem_read(self.base+0x70560,8000))
        return RESULT.pack(c['id'],self.closed if c['stage']==0 else 0,int(changed!=0),self.integer(0x74430),m.mem_read(self.base+0x73450,1)[0],struct.unpack('<I',m.mem_read(self.base+0x74934,4))[0],struct.unpack('<I',m.mem_read(self.base+0x7448c,4))[0],self.deviation,*(values[k] for k in inputs.DOUBLES),*vector,len(self.events),fnv(raw),fnv(rows))

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
        files=MT/'MQL5/Files/bot3-management-real-blocks'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b3-real-blocks-{a.run}.set';ini=MT/f'b3-real-blocks-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementRealBlocksCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
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
