"""Compare complete evaluation prelude 20ef0..212ff, including session branches.

prepare|original|mql5(--build)|compare RUN. Native string helpers execute.
Terminal replies, initial scratch and successful allocation are supplied.
Event: int kind, 6 uint64 words, 3 texts. Text: int null-kind, int units, UTF16LE.
Each row: int id, events until kind0, 31 uint64 state words. See FIELDS/encode.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent;MASK=(1<<64)-1;MAGIC=0x45505233
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
head=module('prelude_head_check',HOME/'tests/check-evaluation-head.py')
pub=head.pub;require=pub.require;save=head.save;sha=head.sha
SOURCE=HOME/'source/MQL5';SCRIPT='Scripts/bot-cua-toi-3/Bot3EvaluationPreludeCheck.mq5';MT=head.MT
FIELDS=['index','caller_flag','server_time']+['head.'+n for n in ['year','mon','day','hour','min','sec','day_of_week','day_of_year']]
FIELDS+=['session_flag','native_1d6d08','selected_null']+['tick.'+n for n in ['time','bid','ask','last','volume','time_msc','flags','volume_real']]+['spread']
FIELDS+=['current.'+n for n in ['year','mon','day','hour','min','sec','day_of_week','day_of_year']]
require(len(FIELDS)==31,'FIELD_COUNT')
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,
 native_prelude_executed=True,string_helper_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Prelude only: native entry20ef0 through212ff including session reports/checks, tick and current calendar. No order/position scan or complete EA.',
 'Terminal replies, initial calendar/tick data and successful string allocation are supplied. Allocation failures and complete MT5 environment are outside this run.',
 'session_flag compares the live byte at frame+f8. The remaining bits of the scratch dword hold incidental register bits and are not called a fully initialized bool.']
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def signed(value,bits_=64):
    value&=(1<<bits_)-1;return value-(1<<bits_) if value>>(bits_-1) else value
def text(value):
    raw=(value or '').encode('utf-16-le');return struct.pack('<2i',int(value is not None),len(raw)//2)+raw
def tick_bytes(values):
    return struct.pack('<6QI4xQ',*[v&MASK for v in values[:6]],values[6]&0xffffffff,values[7]&MASK)
def tick_words(raw):
    return list(struct.unpack('<6QI4xQ',raw))
def base_case():
    return dict(index=0,caller_flag=0,flag=1,info=1,struct_ok=1,now=1792713600,symbol_kind=1,symbol='XAUUSD',other_kind=1,other='ALT',
      calendar=[2000,1,2,3,4,5,1,1],calendar_reply=[2026,10,23,12,13,14,1,295],tick_ok=1,tick_write=1,
      tick_initial=[1700000000,bits(100.),bits(101.),bits(100.5),10,1700000000000,6,bits(10.5)],
      tick_reply=[1792713600,bits(2000.),bits(2000.125),bits(2000.05),0x100000001,1792713600123,0xffffffff,bits(25.25)],
      current_time=1792713601,current_write=1,current_initial=[-10-i for i in range(8)],current_reply=[2026,10,23,13,14,15,5,295],
      time_texts=['09:15','17:45'],sessions=[[0,0,0] for _ in range(70)],tag='')
def cases():
    out=[]
    def add(c):
        c['id']=len(out);i=c['id'];c['index']=[0,8,0xffffffff][i%3];c['caller_flag']=[0,1,255][(i//3)%3]
        c['tick_ok']=i%2;c['tick_write']=(i//2)%2;c['current_write']=(i//4)%2
        c['calendar'][6]=c['calendar_reply'][6];c['struct_ok']=(i//8)%2
        out.append(c)
    for day in [0,1,2,3,4,5,6,-1,0x7fffffff]:
        for flag in [0,1,255]:
            for info in [-1,0,1]:
                c=base_case();c.update(flag=flag,info=info,tag='no-session');c['calendar_reply'][6]=day;add(c)
    # Distinguishes the to=0/86340..86400 adjustment, signed remainder,
    # and the unconditional overnight branch for a to beyond one day.
    endpoints=[-0x8000000000000000,-86401,-1,0,1,86339,86340,86341,86399,86400,86401,86402,172800,0x7fffffffffffffff]
    starts=[-0x8000000000000000,-86401,-1,0,1,3600,80000,86399,86400,86401,0x7fffffffffffffff]
    for begin in starts:
        for end in endpoints:
            for now in [begin-1 if begin>-(1<<63) else begin,begin,begin+1,0,86339,86340,86399,86400,-1]:
                if not -(1<<63)<=now<(1<<63):continue
                c=base_case();c.update(now=now,tag='session-boundary');c['sessions'][10]=[1,begin,end];add(c)
    # No match until a particular index, and all ten sessions exhausted.
    for count in range(11):
        for hit in [0,1]:
            c=base_case();c.update(now=5000,tag='session-index');c['sessions'][10:20]=[[int(j<count),6000,7000] for j in range(10)]
            if hit and count:c['sessions'][10+count-1]=[1,4999,5001]
            add(c)
    for count in range(11):
        for texts in [['09:15','17:45'],[None,''],['Vàng 🚀'*60,'Kết thúc'],['','']]:
            c=base_case();c.update(flag=0,info=0,time_texts=texts,tag='report-sessions')
            for day in range(7):
                for j in range(10):c['sessions'][10*day+j]=[int(j<count),j*3600,(j+1)*3600]
            add(c)
    for kind,symbol in [(0,''),(1,''),(2,''),(1,'Vàng 🚀'),(1,'x'*300)]:
        for other_kind,other in [(0,''),(1,''),(1,'ALT'),(1,'Đổi mã 🚀')]:
            for flag,info in [(0,0),(0,1),(255,0)]:
                c=base_case();c.update(symbol_kind=kind,symbol=symbol,other_kind=other_kind,other=other,flag=flag,info=info,tag='symbol-selection')
                c['sessions'][10]=[1,3000,4000];add(c)
    for bid,ask in [(bits(float('inf')),bits(float('inf'))),(bits(float('-inf')),bits(float('inf'))),
                    (0x7ff8000000000123,bits(1.)),(bits(1.),0xfff8000000000456),(bits(-0.),bits(0.))]:
        for ok,write in [(0,0),(0,1),(1,1)]:
            c=base_case();c.update(tag='tick-bits');add(c);c['tick_ok']=ok;c['tick_write']=write
            c['tick_initial'][1:3]=[bid,ask];c['tick_reply'][1:3]=[bid,ask]
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<iI4iq2i16i',c['id'],c['index'],c['caller_flag'],c['flag'],c['info'],c['struct_ok'],c['now'],c['symbol_kind'],c['other_kind'],*c['calendar'],*c['calendar_reply'])
        raw+=text(c['symbol'])+text(c['other'])+struct.pack('<2i',c['tick_ok'],c['tick_write'])
        raw+=struct.pack('<16Q',*c['tick_initial'],*c['tick_reply'])
        raw+=struct.pack('<qi16i',c['current_time'],c['current_write'],*c['current_initial'],*c['current_reply'])
        for value in c['time_texts']:raw+=text(value)
        for ok,start,end in c['sessions']:raw+=struct.pack('<iqq',ok,start,end)
    return raw
class Original(head.entry.Original):
    def __init__(self):
        super().__init__(3);self.covered=set();self.head_time=None
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+0x20ef0,0x2a1bc-0x20ef0))).hexdigest()=='6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920','EVALUATOR_BYTES_CHANGED')
        eb=next(a for a,n in self.apis.items() if n==1)-0x7d3c40
        for rva,api in [(0x7d1ce0,301),(0x7d1f60,302),(0x7c0fd0,303),(0x7b49f0,304),(0x7cdfe0,305),
                        (0x7c2cb0,306),(0x7ccc50,307),(0x7c2c10,308),(0x7d1c40,309)]:
            address=eb+rva;require(address not in self.apis,'SDK_ALREADY_REGISTERED')
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x20ef0,end=self.base+0x2a1bc)
    def visit(self,m,address,size,user):
        rva=address-self.base;self.covered.add(rva)
        if rva==0x211ea:self.head_time=struct.unpack('<q',m.mem_read(self.frame+0xf8,8))[0]
        if rva==0x212ff:self.exit=rva;m.emu_stop()
    def read_text(self,descriptor):
        pointer=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if not pointer:return None
        n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(n<=10000,'TEXT_TOO_LONG')
        return bytes(self.m.mem_read(pointer,2*n)).decode('utf-16-le')
    def event(self,kind,words=(),texts=()):
        flag=bytes(self.m.mem_read(self.base+0x1d6d08,1))[0]
        values=list(words)+[0]*(5-len(words))+[flag];require(len(values)==6 and len(texts)<=3,'EVENT_SIZE')
        self.events.append([kind,*[v&MASK for v in values],*list(texts),*[None]*(3-len(texts))])
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;c=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        require(301<=api<=309,'UNEXPECTED_PRELUDE_API '+str(api));sp=m.reg_read(x.UC_X86_REG_RSP)
        require(m.reg_read(x.UC_X86_REG_RCX)==0x171514ca538,'SDK_CONTEXT_CHANGED')
        arg=m.reg_read(x.UC_X86_REG_RDX);arg2=m.reg_read(x.UC_X86_REG_R8)
        def integer(value):m.reg_write(x.UC_X86_REG_RAX,value&MASK)
        def reply_string(value):m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,0 if value is None else self.string(value)))
        if api==301:
            require(arg==0,'SERVER_OVERLOAD');self.event(1,[c['now']]);integer(c['now'])
        elif api==302:
            require(arg==c['now']&MASK and arg2==self.frame+0x58,'STRUCT_ARGUMENTS')
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
            expected=(self.frame+0x208,self.frame+0x200) if ret in [0x215cf,0x216d6] else (self.frame+0x1f8,self.frame+0x1f0)
            require((from_pointer,to_pointer)==expected,'SESSION_POINTER_ORDER')
            ok,start,end=c['sessions'][10*day+index] if 0<=day<7 else [0,0,0]
            self.event(6,[day,index,ok,start if ok else 0,end if ok else 0],[self.read_text(arg)])
            if ok:m.mem_write(from_pointer,struct.pack('<q',start));m.mem_write(to_pointer,struct.pack('<q',end))
            integer(ok)
        elif api==307:
            value=c['time_texts'][self.time_calls%2];self.time_calls+=1
            self.event(7,[arg,arg2&0xffffffff],[value]);reply_string(value)
        elif api==308:
            require(arg2==self.base+0x74790,'TICK_POINTER');self.event(8,[c['tick_ok'],c['tick_write']],[self.read_text(arg)])
            if c['tick_write']:m.mem_write(arg2,tick_bytes(c['tick_reply']))
            integer(c['tick_ok'])
        else:
            require(arg==self.base+0x747d0,'CURRENT_CALENDAR_POINTER');self.event(9,[c['current_time'],c['current_write']])
            if c['current_write']:m.mem_write(arg,struct.pack('<8i',*c['current_reply']))
            integer(c['current_time'])
    def run(self,c):
        self.case=c;self.cursor=0x70001000;self.allocs=self.frees=0;self.events=[];self.time_calls=0;self.exit=None;self.head_time=None;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for j in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(j)),0)
        sp=0x50020000-0x108;self.frame=sp-64-0x288;m.mem_write(self.frame,bytes(0x300));m.mem_write(sp,struct.pack('<Q',0x60000000))
        m.mem_write(self.frame+0x58,struct.pack('<8i',*c['calendar']));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_RCX,c['index']);m.reg_write(x.UC_X86_REG_RDX,c['caller_flag'])
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        for off,kind,value in [(0x74958,c['symbol_kind'],c['symbol']),(0x1d6e28,c['other_kind'],c['other'])]:
            pointer=0 if kind==0 else self.base+0x59d18 if kind==2 else self.string(value)
            m.mem_write(self.base+off,struct.pack('<IQ',0,pointer))
        m.mem_write(self.base+0x1d6d08,bytes([c['flag']]));m.mem_write(self.base+0x74790,tick_bytes(c['tick_initial']))
        m.mem_write(self.base+0x747d0,struct.pack('<8i',*c['current_initial']))
        try:m.emu_start(self.base+0x20ef0,0x60000000,timeout=10000000,count=3000000)
        except Exception as error:raise RuntimeError('NATIVE_CASE '+str(c['id'])+' RIP '+hex(m.reg_read(x.UC_X86_REG_RIP))+' '+repr(error)) from error
        require(self.exit==0x212ff and self.head_time is not None,'PRELUDE_DID_NOT_REACH_EXIT')
        index=struct.unpack('<I',m.mem_read(self.frame+0xb0,4))[0];caller=bytes(m.mem_read(self.frame+0x88,1))[0]
        cal=struct.unpack('<8i',m.mem_read(self.frame+0x58,32));session_flag=bytes(m.mem_read(self.frame+0xf8,1))[0]
        flag=bytes(m.mem_read(self.base+0x1d6d08,1))[0];selected=self.read_text(self.frame+0x110)
        require(selected is None,'SELECTED_STRING_NOT_CLEANED')
        tick=tick_words(bytes(m.mem_read(self.base+0x74790,64)));spread=struct.unpack('<Q',m.mem_read(self.base+0x6d650,8))[0]
        current=struct.unpack('<8i',m.mem_read(self.base+0x747d0,32))
        values=[index,caller,self.head_time,*cal,session_flag,flag,int(selected is None),*tick,spread,*current]
        raw=bytearray(struct.pack('<i',c['id']))
        for event in self.events:
            raw+=struct.pack('<i6Q',*event[:7])
            for value in event[7:]:raw+=text(value)
        raw+=struct.pack('<i31Q',0,*[v&MASK for v in values]);return raw
def identity():
    helpers=dict(head.identity()['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=head.validation.original_hash(3),tool_sha256=sha(Path(__file__)),
      sources_sha256={p.relative_to(SOURCE).as_posix():sha(p) for p in pub.closure(SOURCE/SCRIPT,SOURCE)},helpers_sha256=helpers)
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
        values=list(struct.unpack_from('<31Q',raw,at));at+=31*8;rows.append(dict(id=id_,events=events,values=values))
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
        required={0x20ef0,0x211ea,0x211fe,0x21578,0x2166f,0x21680,0x2169e,0x216b5,0x216d3,0x216e0,0x216e5,0x217ab,0x21b3b,0x21e13,0x22253,0x22270,0x22aa6,0x2127f,0x212ff}
        require(required.issubset(o.covered),'BRANCH_COVERAGE_MISSING '+str([hex(v) for v in sorted(required-o.covered)]))
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',dict(**current,cases=len(rows),instructions=len(o.covered),required_branches=[hex(v) for v in sorted(required)],result_sha256=sha(folder/'original-results.bin'),**SCOPE))
        print(json.dumps(dict(cases=len(rows),instructions=len(o.covered))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');require(not(folder/'mql5-results.bin').exists(),'RESULT_EXISTS');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_DIFFERS '+n)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-evaluation-prelude'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b3-prelude-'+a.run+'.set');ini=MT/('b3-prelude-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3EvaluationPreludeCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
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
