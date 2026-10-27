"""Compare complete evaluation prelude 18aa0..18eb1, including session branches.

prepare|original|mql5(--build)|compare RUN. Native string helpers execute.
Terminal replies, initial scratch and successful allocation are supplied.
Event: int kind, 6 uint64 words, 3 texts. Text: int null-kind, int units, UTF16LE.
Each row: int id, events until kind0, 30 uint64 state words. See FIELDS/encode.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent;MASK=(1<<64)-1;MAGIC=0x45505231
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
head=module('prelude_head_check',ROOT/'bot-cua-toi-3/tests/check-evaluation-head.py')
pub=head.pub;require=pub.require;save=head.save;sha=head.sha
SOURCE=HOME/'source/MQL5';SCRIPT='Scripts/bot-cua-toi-1/Bot1EvaluationPreludeCheck.mq5';MT=ROOT.parent/'.local/mt5-bot1-thread-20261025'
FIELDS=['index','server_time']+['calendar.'+n for n in ['year','mon','day','hour','min','sec','day_of_week','day_of_year']]
FIELDS+=['session_flag','native_6a3b4','selected_null']+['tick.'+n for n in ['time','bid','ask','last','volume','time_msc','flags','volume_real']]+['spread']
FIELDS+=['current.'+n for n in ['year','mon','day','hour','min','sec','day_of_week','day_of_year']]
require(len(FIELDS)==30,'FIELD_COUNT')
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,
 native_prelude_executed=True,string_helper_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Prelude only: native entry18aa0 through18eb1 including session reports/checks, tick and current calendar. No order/position scan or complete EA.',
 'Terminal replies, initial calendar/tick data and successful string allocation are supplied. Allocation failures and complete MT5 environment are outside this run.',
 'session_flag compares the live byte at frame+c0. The remaining bits of the scratch dword hold incidental register bits and are not called a fully initialized bool.']
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def signed(value,bits_=64):
    value&=(1<<bits_)-1;return value-(1<<bits_) if value>>(bits_-1) else value
def text(value):
    raw=(value or '').encode('utf-16-le');return struct.pack('<2i',int(value is not None),len(raw)//2)+raw
def tick_bytes(values):
    return struct.pack('<6QI4xQ',*[v&MASK for v in values[:6]],values[6]&0xffffffff,values[7]&MASK)
def tick_words(raw):
    return list(struct.unpack('<6QI4xQ',raw))
case_data=module('bot1_prelude_case_data',ROOT/'bot-cua-toi-3/tests/check-evaluation-prelude.py')
def cases():return case_data.cases()
def encode(rows):
    # The common input corpus keeps a DL seed; bot 1 does not consume it.
    return struct.pack('<i',MAGIC)+case_data.encode(rows)[4:]
class Original(head.entry.Original):
    def __init__(self):
        super().__init__(1);self.covered=set();self.head_time=None
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+0x18aa0,0x1ef9c-0x18aa0))).hexdigest()=='45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd','EVALUATOR_BYTES_CHANGED')
        eb=next(a for a,n in self.apis.items() if n==1)-0x7d3c40
        for rva,api in [(0x7d1ce0,301),(0x7d1f60,302),(0x7c0fd0,303),(0x7b49f0,304),(0x7cdfe0,305),
                        (0x7c2cb0,306),(0x7ccc50,307),(0x7c2c10,308),(0x7d1c40,309)]:
            address=eb+rva;require(address not in self.apis,'SDK_ALREADY_REGISTERED')
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x18aa0,end=self.base+0x1ef9c)
    def visit(self,m,address,size,user):
        rva=address-self.base;self.covered.add(rva)
        if rva==0x18d99:self.head_time=struct.unpack('<q',m.mem_read(self.frame+0xf8,8))[0]
        if rva==0x18eb1:self.exit=rva;m.emu_stop()
    def read_text(self,descriptor):
        pointer=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if not pointer:return None
        n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(n<=10000,'TEXT_TOO_LONG')
        return bytes(self.m.mem_read(pointer,2*n)).decode('utf-16-le')
    def event(self,kind,words=(),texts=()):
        flag=bytes(self.m.mem_read(self.base+0x6a3b4,1))[0]
        values=list(words)+[0]*(5-len(words))+[flag];require(len(values)==6 and len(texts)<=3,'EVENT_SIZE')
        self.events.append([kind,*[v&MASK for v in values],*list(texts),*[None]*(3-len(texts))])
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;c=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        require(301<=api<=309,'UNEXPECTED_PRELUDE_API '+str(api));sp=m.reg_read(x.UC_X86_REG_RSP)
        require(m.reg_read(x.UC_X86_REG_RCX)==0x23e575eae78,'SDK_CONTEXT_CHANGED')
        arg=m.reg_read(x.UC_X86_REG_RDX);arg2=m.reg_read(x.UC_X86_REG_R8)
        def integer(value):m.reg_write(x.UC_X86_REG_RAX,value&MASK)
        def reply_string(value):m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,0 if value is None else self.string(value)))
        if api==301:
            require(arg==0,'SERVER_OVERLOAD');self.event(1,[c['now']]);integer(c['now'])
        elif api==302:
            require(arg==c['now']&MASK and arg2==self.frame+0x50,'STRUCT_ARGUMENTS')
            self.event(2,[arg,c['struct_ok']])
            if c['struct_ok']:m.mem_write(arg2,struct.pack('<8i',*c['calendar_reply']))
            integer(c['struct_ok'])
        elif api==303:
            self.event(3,[arg&0xffffffff,c['info']]);require(arg&0xffffffff==7,'INFO_PROPERTY');integer(c['info'])
        elif api==304:
            count=arg2&0xffffffff;require(arg==2 and count in [1,3],'PRINT_ARGUMENTS');values=[]
            for j in range(count):
                tag=m.reg_read(x.UC_X86_REG_R9)&0xffffffff if j==0 else struct.unpack('<I',m.mem_read(sp+32+16*j,4))[0]
                require(tag==0x590008,'PRINT_TYPE');pointer=struct.unpack('<Q',m.mem_read(sp+40+16*j,8))[0];values.append(self.read_text(pointer))
            self.event(4,[count],values)
        elif api==305:
            number=signed(arg);width=arg2&0xffffffff;fill=m.reg_read(x.UC_X86_REG_R9)&0xffff;require(width==0 and fill==32,'INTEGER_FORMAT')
            value=str(number);self.event(5,[number,width,fill],[value]);reply_string(value)
        elif api==306:
            day=signed(arg2,32);index=m.reg_read(x.UC_X86_REG_R9)&0xffffffff;require(index<10,'SESSION_INDEX')
            from_pointer=struct.unpack('<Q',m.mem_read(sp+0x28,8))[0];to_pointer=struct.unpack('<Q',m.mem_read(sp+0x30,8))[0]
            ret=struct.unpack('<Q',m.mem_read(sp,8))[0]-self.base
            expected=(self.frame+0x1a8,self.frame+0x1a0) if ret in [0x18f91,0x19095] else (self.frame+0x198,self.frame+0x190)
            require((from_pointer,to_pointer)==expected,'SESSION_POINTER_ORDER')
            ok,start,end=c['sessions'][10*day+index] if 0<=day<7 else [0,0,0]
            self.event(6,[day,index,ok,start if ok else 0,end if ok else 0],[self.read_text(arg)])
            if ok:m.mem_write(from_pointer,struct.pack('<q',start));m.mem_write(to_pointer,struct.pack('<q',end))
            integer(ok)
        elif api==307:
            value=c['time_texts'][self.time_calls%2];self.time_calls+=1
            self.event(7,[arg,arg2&0xffffffff],[value]);reply_string(value)
        elif api==308:
            require(arg2==self.base+0x67750,'TICK_POINTER');self.event(8,[c['tick_ok'],c['tick_write']],[self.read_text(arg)])
            if c['tick_write']:m.mem_write(arg2,tick_bytes(c['tick_reply']))
            integer(c['tick_ok'])
        else:
            require(arg==self.base+0x67790,'CURRENT_CALENDAR_POINTER');self.event(9,[c['current_time'],c['current_write']])
            if c['current_write']:m.mem_write(arg,struct.pack('<8i',*c['current_reply']))
            integer(c['current_time'])
    def run(self,c):
        self.case=c;self.cursor=0x70001000;self.allocs=self.frees=0;self.events=[];self.time_calls=0;self.exit=None;self.head_time=None;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for j in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(j)),0)
        sp=0x50020000-0x108;self.frame=sp-64-0x228;m.mem_write(self.frame,bytes(0x300));m.mem_write(sp,struct.pack('<Q',0x60000000))
        m.mem_write(self.frame+0x50,struct.pack('<8i',*c['calendar']));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_RCX,c['index']);m.reg_write(x.UC_X86_REG_RDX,c['caller_flag'])
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        for off,kind,value in [(0x67918,c['symbol_kind'],c['symbol']),(0x6a428,c['other_kind'],c['other'])]:
            pointer=0 if kind==0 else self.base+0x517d8 if kind==2 else self.string(value)
            m.mem_write(self.base+off,struct.pack('<IQ',0,pointer))
        m.mem_write(self.base+0x6a3b4,bytes([c['flag']]));m.mem_write(self.base+0x67750,tick_bytes(c['tick_initial']))
        m.mem_write(self.base+0x67790,struct.pack('<8i',*c['current_initial']))
        try:m.emu_start(self.base+0x18aa0,0x60000000,timeout=10000000,count=3000000)
        except Exception as error:raise RuntimeError('NATIVE_CASE '+str(c['id'])+' RIP '+hex(m.reg_read(x.UC_X86_REG_RIP))+' '+repr(error)) from error
        require(self.exit==0x18eb1 and self.head_time is not None,'PRELUDE_DID_NOT_REACH_EXIT')
        index=struct.unpack('<I',m.mem_read(self.frame+0xbc,4))[0]
        cal=struct.unpack('<8i',m.mem_read(self.frame+0x50,32));session_flag=bytes(m.mem_read(self.frame+0xc0,1))[0]
        flag=bytes(m.mem_read(self.base+0x6a3b4,1))[0];selected=self.read_text(self.frame+0x110)
        require(selected is None,'SELECTED_STRING_NOT_CLEANED')
        tick=tick_words(bytes(m.mem_read(self.base+0x67750,64)));spread=struct.unpack('<Q',m.mem_read(self.base+0x62560,8))[0]
        current=struct.unpack('<8i',m.mem_read(self.base+0x67790,32))
        values=[index,self.head_time,*cal,session_flag,flag,int(selected is None),*tick,spread,*current]
        raw=bytearray(struct.pack('<i',c['id']))
        for event in self.events:
            raw+=struct.pack('<i6Q',*event[:7])
            for value in event[7:]:raw+=text(value)
        raw+=struct.pack('<i30Q',0,*[v&MASK for v in values]);return raw
def identity():
    helpers=[Path(__file__),HOME.parent/'bot-cua-toi-3/tests/check-evaluation-prelude.py',HOME.parent/'bot-cua-toi-3/tests/check-evaluation-head.py',
      ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',
      ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',HOME/'phan-tich/luot-20261023-data-v2/metadata/import.json']
    return dict(original_ex5_sha256=head.validation.original_hash(1),tool_sha256=sha(Path(__file__)),
      sources_sha256={p.relative_to(SOURCE).as_posix():sha(p) for p in pub.closure(SOURCE/SCRIPT,SOURCE)},
      helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def parse(raw,count):
    require(raw[:16]==struct.pack('<4i',MAGIC,1,count,len(FIELDS)),'RESULT_HEADER');at=16;rows=[]
    for _ in range(count):
        id_=struct.unpack_from('<i',raw,at)[0];at+=4;events=[]
        while True:
            kind=struct.unpack_from('<i',raw,at)[0];at+=4
            if kind==0:break
            require(1<=kind<=9 and len(events)<300,'EVENT_KIND_COUNT');values=list(struct.unpack_from('<6Q',raw,at));at+=48;strings=[]
            for j in range(3):
                k,n=struct.unpack_from('<2i',raw,at);at+=8;require(k in [0,1] and 0<=n<=10000 and (k or n==0),'TEXT_FORMAT')
                strings.append(raw[at:at+2*n].decode('utf-16-le') if k else None);at+=2*n
            events.append([kind,*values,*strings])
        values=list(struct.unpack_from('<30Q',raw,at));at+=30*8;rows.append(dict(id=id_,events=events,values=values))
    require(at==len(raw),'RESULT_SIZE');return rows
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,40}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity();header=struct.pack('<4i',MAGIC,1,len(rows),len(FIELDS))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE))
        print(json.dumps(dict(cases=len(rows),values=len(FIELDS))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');o=Original();raw=bytearray(header)
        for c in rows:raw+=o.run(c)
        required={0x18aa0,0x18d99,0x18dad,0x18e31,0x18eb1,0x18f3b,0x1902f,0x19040,0x1905e,0x19075,0x19093,0x1909f,0x190a4,0x1916b,0x194fb,0x197a9,0x19bd2,0x19bf0,0x1a2eb}
        require(required.issubset(o.covered),'BRANCH_COVERAGE_MISSING '+str([hex(v) for v in sorted(required-o.covered)]))
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',dict(**current,cases=len(rows),instructions=len(o.covered),required_branches=[hex(v) for v in sorted(required)],result_sha256=sha(folder/'original-results.bin'),**SCOPE))
        print(json.dumps(dict(cases=len(rows),instructions=len(o.covered))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');require(not(folder/'mql5-results.bin').exists(),'RESULT_EXISTS');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_DIFFERS '+n)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot1-evaluation-prelude'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b1-prelude-'+a.run+'.set');ini=MT/('b1-prelude-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1EvaluationPreludeCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for n in ['original-run.json','mql5-run.json']:
        value=json.loads((folder/n).read_text());require(all(value[k]==v for k,v in current.items()) and value['result_sha256']==sha(folder/n.replace('-run.json','-results.bin')),'RUN_CHANGED')
    native=parse((folder/'original-results.bin').read_bytes(),len(rows));actual=parse((folder/'mql5-results.bin').read_bytes(),len(rows));failed=[]
    for c,n,r in zip(rows,native,actual):
        if n!=r:
            diff=dict(id=c['id'],tag=c['tag'],values={k:[x,y] for k,x,y in zip(FIELDS,n['values'],r['values']) if x!=y})
            if n['events']!=r['events']:
                j=next((j for j,(x,y) in enumerate(zip(n['events'],r['events'])) if x!=y),min(len(n['events']),len(r['events'])))
                diff['first_event']=dict(index=j,native=n['events'][j:j+1],mql5=r['events'][j:j+1],counts=[len(n['events']),len(r['events'])])
            failed.append(diff)
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:12],**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report,ensure_ascii=False));raise SystemExit(bool(failed))
if __name__=='__main__':main()
