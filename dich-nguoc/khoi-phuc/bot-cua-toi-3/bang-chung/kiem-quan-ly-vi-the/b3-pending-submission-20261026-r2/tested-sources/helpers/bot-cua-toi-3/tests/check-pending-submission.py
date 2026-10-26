"""Execute the original caller after base-price calculation; child replies supplied.
prepare/original/mql5(--build)/compare RUN. Never sends an account order.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent;MASK=(1<<64)-1
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
pre=module('pending_pre',HOME/'tests/check-management-prelude.py')
data=module('pending_inputs',HOME/'tests/pending_submission_cases.py')
pub=module('pending_pub',ROOT/'cong-cu/kiem-ban-git-quan-ly.py')
sha,require,save=pre.sha,pre.require,pre.save
MT=(ROOT.parent/'.local/mt5-bot3-thread-20261025').resolve()
SCRIPT='Scripts/bot-cua-toi-3/Bot3PendingSubmissionCheck.mq5'
CONTRACT=ROOT/'claude-thuc-hien/bot3-pending-check-20261026-r2/TASK.md'
PRODUCT_CONTRACT=ROOT/'claude-thuc-hien/bot3-pending-submission-20261026-r2/TASK.md'
FUNCTION_SHA='6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920'
FIELDS=dict(check_free_margin=(0x6d51c,'B'),omit_real_sl_tp=(0x6d510,'B'),virtual_expiration=(0x1d6fc8,'B'),
 strategy_magic=(0x6d564,'i'),expiration=(0x74490,'q'),unit=(0x73dd8,'d'),stop_distance=(0x6d588,'d'),
 take_distance=(0x6d590,'d'),minimum_stop_price=(0x73ab0,'d'),minimum_freeze_price=(0x744a8,'d'),ask=(0x747a0,'d'),bid=(0x74798,'d'))
SCOPE=dict(whole_manager_complete=False,whole_bot_complete=False,full_ea=False,native_caller_slice_executed=True,child_helpers_intercepted=True,
 terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Only the caller after a supplied base price, not the earlier entry conditions or whole main program.',
 'Margin/volume/limit/pending-send/error-text children and terminal replies are supplied; RoundPrice and caller instructions execute.',
 'Valid 9-volume/100-row arrays and successful native string allocations only; no claim for all allocations, infinite retries, real accounts or lifecycle.']
def bits(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def fnv(raw):
    value=0xcbf29ce484222325
    for byte in raw:value=((value^byte)*0x100000001b3)&MASK
    return value
def text_hash(v):return fnv(v.encode('utf-16-le'))
def identity():
    source=HOME/'source/MQL5';names=sorted(p.relative_to(source.resolve()).as_posix() for p in pub.closure(source/SCRIPT,source))
    helpers=[Path(__file__),HOME/'tests/pending_submission_cases.py',HOME/'tests/check-management-prelude.py',
      ROOT/'bot-cua-toi-1/tests/check-management-prelude.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',
      ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',
      ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',CONTRACT,PRODUCT_CONTRACT,
      HOME/'phan-tich/chuong-trinh-chinh/pending-submission-20261026-r2/native-bindings.json']
    return dict(original_ex5_sha256=pre.validation.original_hash(3),tool_sha256=sha(Path(__file__)),
      helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers},
      sources_sha256={n:sha(source/n) for n in names},native_main_sha256=FUNCTION_SHA)
class Original(pre.entry.Original):
    def __init__(self):
        super().__init__(3);require(self.base==0x17156250000,'CAPTURE_BASE_DIFFERS');m=self.m
        require(hashlib.sha256(bytes(m.mem_read(self.base+0x20ef0,0x2a1bc-0x20ef0))).hexdigest()==FUNCTION_SHA,'MAIN_BYTES_DIFFER')
        engine=next(addr for addr,kind in self.apis.items() if kind==1)-0x7d3c40
        for off,kind in [(0x7c2970,200),(0x7b49f0,201),(0x7b17c0,202)]:
            addr=engine+off
            if addr not in self.apis:
                if not any(lo<=addr<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(addr&~4095,4096)
                m.mem_write(addr,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
            self.apis[addr]=kind
        for off in [0x47840,0x46ca0,0x47330,0x3e580,0x3ee80]:m.hook_add(self.uc.UC_HOOK_CODE,self.child,begin=self.base+off,end=self.base+off)
        m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x280c6,end=self.base+0x29c85);self.covered=set()
    def read(self,off,fmt):return struct.unpack('<'+fmt,self.m.mem_read(self.base+off,struct.calcsize('<'+fmt)))[0]
    def write(self,off,fmt,value):self.m.mem_write(self.base+off,struct.pack('<'+fmt,value))
    def text(self,descriptor):
        ptr=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if not ptr:return ''
        n=struct.unpack('<I',self.m.mem_read(ptr-4,4))[0];require(n<=4096,'BAD_STRING_LENGTH')
        return bytes(self.m.mem_read(ptr,n*2)).decode('utf-16-le')
    def set_text(self,off,value):self.m.mem_write(self.base+off,struct.pack('<IQ',0,self.string(value)))
    def event(self,kind,*words):self.events.append([kind]+[w&MASK for w in words])
    def mutate(self,trigger):
        if self.case['mutation_at']!=trigger or self.mutations:return
        self.event(9,trigger);self.mutations+=1
        changes=dict(unit=.25,stop_distance=7.25,take_distance=9.5,expiration=9876543210,strategy_magic=-77,
          omit_real_sl_tp=255 if self.read(0x6d510,'B')==0 else 0,virtual_expiration=255,
          ask=self.case['base_price']-5.,bid=self.case['base_price']+5.,minimum_freeze_price=2.125,minimum_stop_price=1.25)
        for key,value in changes.items():off,fmt=FIELDS[key];self.write(off,fmt,value)
        self.set_text(0x74958,'NEXT');self.set_text(0x6d568,'changed');self.write(0x74934,'I',(self.read(0x74934,'I')+1)%9)
        for i in range(9):self.write(0x73ac0+i*8,'d',.25*(i+5))
        self.opts=[0xfedcba9876543210,5,-2,2]
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        if off in [0x284be,0x295b9]:self.stop=off;m.emu_stop()
    def call(self,m,address,size,user):
        kind=self.apis[address];x=self.x;c=self.case;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))
        if kind in [100,101]:return super().call(m,address,size,user)
        if kind==200:
            prop=r('R8')&0xffffffff;require(prop==17 and self.digits<3,'BAD_DIGITS_QUERY')
            v=c['digit'+str(self.digits)];self.event(1,prop,text_hash(self.text(r('RDX'))),v);self.digits+=1;self.mutate(self.digits);m.reg_write(x.UC_X86_REG_RAX,v&MASK)
        elif kind==201:
            require(r('RDX')==2 and r('R8')==1 and r('R9')==0x590008,'BAD_PRINT_SIGNATURE')
            desc=struct.unpack('<Q',m.mem_read(r('RSP')+0x28,8))[0];message=self.text(desc)
            self.event(8,text_hash(message));self.prints+=1;self.messages.append(message);m.reg_write(x.UC_X86_REG_RAX,0)
        elif kind==202:
            self.event(6,r('RDX')&0xffffffff);self.sleeps+=1
            if self.sleeps==1:self.mutate(8)
        else:raise ValueError('UNEXPECTED_SDK '+str(kind))
    def child(self,m,address,size,user):
        off=address-self.base;x=self.x;c=self.case;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));sp=r('RSP')
        if off==0x47840:
            reply=c['margin_reply'];self.event(2,text_hash(self.text(r('RCX'))),r('RDX')&0xffffffff,r('XMM2')&MASK,reply);self.margin+=1;self.mutate(4)
        elif off==0x46ca0:
            reply=c['volume_reply'];self.event(3,text_hash(self.text(self.base+0x74958)),r('XMM0')&MASK,reply);self.volume+=1;self.mutate(5)
        elif off==0x47330:
            reply=c['limit_reply'];self.event(4,reply);self.limit+=1;self.mutate(6)
        elif off==0x3e580:
            ordinal=self.sends;require(ordinal<4,'NONFINITE_RETRY_FIXTURE')
            reply=c['initial_accept'] if ordinal==0 else (c['retry_accept_mask']>>(ordinal-1))&1
            sl,tp,comment,expiry=struct.unpack('<4Q',m.mem_read(sp+0x28,32))
            self.event(5,r('RDX')&0xffffffff,r('XMM2')&MASK,r('XMM3')&MASK,sl,tp,expiry,
              self.read(0x6d564,'i'),self.read(0x1d6fc8,'B'),text_hash(self.text(r('RCX'))),text_hash(self.text(comment)),*self.opts,reply)
            self.sends+=1;error=c['initial_error'] if ordinal==0 else (c['final_error'] if ordinal>=c['retry_count'] else 132)
            self.write(0x1d6e10,'i',error)
            if ordinal in [0,1]:self.mutate(7 if ordinal==0 else 9)
        elif off==0x3ee80:
            code=struct.unpack('<i',struct.pack('<I',r('RCX')&0xffffffff))[0];old=self.errors;self.errors=(old+1)&0xffffffff;text='error-'+str(code)
            self.event(7,code,old,self.errors,text_hash(text));self.error_calls+=1;self.set_text(0x1d6e3c,text);reply=0
        else:raise ValueError('UNEXPECTED_CHILD')
        ret=struct.unpack('<Q',m.mem_read(sp,8))[0];m.reg_write(x.UC_X86_REG_RAX,reply);m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret)
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.events=[];self.messages=[];self.stop=None
        self.digits=self.margin=self.volume=self.limit=self.sends=self.sleeps=self.prints=self.error_calls=self.mutations=0
        self.errors=c['error_count']&0xffffffff;self.opts=[0x0123456789abcdef,2,3,1];self.cursor=0x70001000;self.allocs=self.frees=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        m.mem_write(0x50000000,b'\0'*0x20000)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_XMM10,bits(c['base_price']))
        for key,(off,fmt) in FIELDS.items():self.write(off,fmt,c[key])
        self.set_text(0x74958,c['symbol']);self.set_text(0x6d568,c['comment']);self.write(0x74934,'I',c['strategy_index']);self.write(0x1d6e10,'i',0)
        for i in range(9):self.write(0x73ac0+i*8,'d',.125*(i+1))
        for i,row in enumerate(data.table(c['cache_mode'])):
            for j,v in enumerate(row):self.write(0x72e10+i*16+j*8,'d',v)
        top=0x50020000-0x108;m.reg_write(x.UC_X86_REG_RSP,top);m.mem_write(top,struct.pack('<Q',0x60000000))
        m.emu_start(self.base+(0x280d7 if c['buy'] else 0x291c6),0x60000000,timeout=3000000,count=100000)
        require(self.stop==(0x284be if c['buy'] else 0x295b9),'SLICE_DID_NOT_FINISH')
        event_bytes=b''.join(struct.pack('<'+'Q'*len(v),*v) for v in self.events)
        words=[len(self.events),fnv(event_bytes),self.digits,self.margin,self.volume,self.limit,self.sends,self.sleeps,self.prints,self.error_calls,self.mutations,self.errors,self.read(0x1d6e10,'i')&MASK,self.read(0x74934,'I')]
        for key,(off,fmt) in FIELDS.items():v=self.read(off,fmt);words.append(bits(v) if fmt=='d' else v&MASK)
        words.extend([text_hash(self.text(self.base+0x74958)),text_hash(self.text(self.base+0x6d568)),*[v&MASK for v in self.opts]])
        words.extend(self.read(0x73ac0+i*8,'Q') for i in range(9));words.extend(self.read(0x72e10+i*8,'Q') for i in range(200))
        require(len(words)==241,'BAD_OBSERVATION_SIZE');return data.RESULT.pack(c['id'],0,*words)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=data.cases();current=identity()
    header=struct.pack('<3i',data.MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(data.encode(rows));save(folder/'cases.json',rows)
        tested=folder/'tested-sources';tested.mkdir()
        for group,base in [('sources_sha256',HOME/'source/MQL5'),('helpers_sha256',ROOT)]:
            for name in current[group]:
                target=tested/('sources' if group=='sources_sha256' else 'helpers')/name
                target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(base/name,target)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==data.encode(rows),'IDENTITY_OR_INPUTS_DIFFER')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');runner=Original();raw=bytearray(header);traces=[]
        for c in rows:
            try:raw+=runner.run(c)
            except Exception as error:
                save(folder/'attempt-error.json',dict(case=c['id'],error=str(error),rva=hex(runner.m.reg_read(runner.x.UC_X86_REG_RIP)-runner.base),events=runner.events));raise
            traces.append(dict(id=c['id'],events=runner.events,messages=runner.messages,stop_rva=hex(runner.stop)))
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-traces.json',traces);save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),instructions=sorted(hex(x) for x in runner.covered),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(runner.covered))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/name)==build['sources_sha256'][name]==digest,'SOURCE_DIFFERS '+name)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-pending-submission'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b3-submission-'+a.run+'.set');ini=MT/('b3-submission-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3PendingSubmissionCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for name in ['original-run.json','mql5-run.json']:
        record=json.loads((folder/name).read_text());require(all(record[k]==v for k,v in current.items()) and record['result_sha256']==sha(folder/name.replace('-run.json','-results.bin')),'RUN_IDENTITY_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();require(native[:12]==actual[:12]==header and len(native)==len(actual)==12+data.RESULT.size*len(rows),'BAD_RESULTS');failures=[]
    names=['id','fault']+data.RESULT_NAMES
    for c in rows:
        off=12+c['id']*data.RESULT.size;first=data.RESULT.unpack_from(native,off);second=data.RESULT.unpack_from(actual,off)
        if first!=second:failures.append(dict(id=c['id'],group=c['group'],differences={k:[x,y] for k,x,y in zip(names,first,second) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:20],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failures))
if __name__=='__main__':main()
