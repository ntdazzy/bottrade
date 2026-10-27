"""Compare complete native NFP calendar lookup with compiled MQL5.

prepare|original|mql5(--build)|compare|errors BOT RUN. Calendar replies and allocation supplied.
"""
import argparse,copy,hashlib,importlib.util,json,random,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x4e465031;MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
entry=module('nfp_entry','kiem-gia-vao-bot-1-3.py');pub=module('nfp_pub','kiem-ban-git-quan-ly.py');require=pub.require
validation=module('nfp_validation','kiem-khoi-luong-hop-le-bot-1-3.py')
CFG={1:dict(fn=0x61b0,end=0x65f3,sha='c0b3ee5403b7957c86efd5e90b42827068a7003096abb7ce92b0511ebbf9d1ed',error=0x6a410,type_tags=[0x23e5761278a,0x23e57610daa]),3:dict(fn=0x6ad0,end=0x6f13,sha='2dee9d0e2fda26923648e75141e15be6b6b055f60582c8c8fe6736006cd2d3d4',error=0x1d6e10,type_tags=[0x171514adbca,0x17156057baa])}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_nfp_calendar_executed=True,child_helpers_intercepted=False,terminal_calendar_replies_supplied=True,original_ex5_changed=False)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def text(s):
    if s is None:return struct.pack('<i',-1)
    raw=s.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def save(p,value):
    with p.open('x',encoding='utf-8',newline='\n') as f:json.dump(value,f,ensure_ascii=False,indent=2)
def signed(v):return (v+(1<<63))%(1<<64)-(1<<63)
def cases():
    out=[]
    def add(events,values,now=1793100000,event_return=None,value_return=None,fatal=0,tag=''):
        out.append(dict(id=len(out),fatal=fatal,now=now,last_error=65536+731,event_return=len(events) if event_return is None else event_return,value_return=len(values) if value_return is None else value_return,events=events,values=values,tag=tag))
    names=[None,'','Other','Nonfarm Payrolls','nonfarm Payrolls','USD Nonfarm Payrolls (monthly)','Nonfarm Payroll','Nonfarm Payrolls\0test','Tin 🚀 Nonfarm Payrolls','Nonfarm Payrolls'*30]
    for name in names:
        for eventid in [0,1,840030016,1<<63,(1<<64)-1]:add([[eventid,name]],[1793200000,1793300000],tag='name-id')
    for now in [0,1,-1,86400,1793100000,-(1<<63),(1<<63)-1]:
        start=signed(now-86400)
        for vals in [[],[start],[signed(start-1)],[signed(start+1)],[signed(start+1),signed(start+2)],[signed(start+2),signed(start+1)],[0,-1,1],[-(1<<63),(1<<63)-1]]:
            add([[11,'Nonfarm Payrolls']],vals,now=now,tag='time-boundary')
    for ret in [-2147483648,-1,0,1,2,3]:
        for vals in [[],[1793200000],[1793200000,1793300000]]:add([[11,'Other'],[22,'Nonfarm Payrolls'],[33,'Nonfarm Payrolls']],vals,event_return=ret,tag='returned-event-count')
    for ret in [-2147483648,-1,0,1,2]:add([[11,'Nonfarm Payrolls']],[1793200000,1793300000],value_return=ret,tag='returned-value-count')
    rng=random.Random(2026102707)
    for _ in range(350):
        now=rng.randrange(-100000,2000000000);events=[[rng.randrange(100),rng.choice(names)] for _ in range(rng.randrange(8))];values=[now+rng.randrange(-200000,6000000) for _ in range(rng.randrange(8))]
        add(events,values,now=now,tag='mixed-calendar')
    add([],[],event_return=1,fatal=1,tag='fatal-short-event-array')
    add([[1,'Nonfarm Payrolls']],[],value_return=1,fatal=1,tag='fatal-short-value-array')
    base=out;out=[]
    for event_series,value_series in [(0,0),(1,0),(0,1),(1,1)]:
        for old in base:
            c=copy.deepcopy(old);c.update(id=len(out),event_series=event_series,value_series=value_series);out.append(c)
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<2iq6i',c['id'],c['fatal'],c['now'],c['last_error'],c['event_return'],c['value_return'],c['event_series'],c['value_series'],len(c['events']))
        for eventid,name in c['events']:raw+=struct.pack('<Q',eventid)+text(name)
        raw+=struct.pack('<i',len(c['values']))+b''.join(struct.pack('<q',t) for t in c['values'])
    return bytes(raw)
class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.nfp=CFG[bot];cfg=self.nfp
        raw=bytes(self.m.mem_read(self.base+cfg['fn'],cfg['end']-cfg['fn']));self.function_sha=hashlib.sha256(raw).hexdigest()
        if 'sha' in cfg:require(self.function_sha==cfg['sha'],'NFP_BYTES_CHANGED')
        eb=0x7ff683f20000;extra={eb+0x7d1ce0:601,eb+0x3802f0:602,eb+0x380440:603,eb+0x7b6ef0:604,eb+0x3959a0:605}
        for address,api in extra.items():
            require(address not in self.apis,'NFP_API_ALREADY_BOUND')
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        # Opaque array type IDs live outside the capture. Their words are copied to
        # calendar SDK descriptors, never used by the algorithm or array cleanup.
        # Supply/validate them under the mocked typed-calendar allocation boundary.
        for address in cfg['type_tags']:
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
        self.covered=set();self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,a,s,u:self.covered.add(a-self.base),begin=self.base+cfg['fn'],end=self.base+cfg['end']-1)
    def read_text(self,desc):
        pointer=struct.unpack('<Q',self.m.mem_read(desc+4,8))[0]
        if not pointer:return None
        length=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(length<10000,'BAD_TEXT_LENGTH');return bytes(self.m.mem_read(pointer,2*length)).decode('utf-16-le')
    def array(self,desc,records,series):
        require(struct.unpack('<I',self.m.mem_read(desc+4,4))[0]==128,'CALENDAR_RECORD_STRIDE')
        self.m.mem_write(desc+2,struct.pack('<H',1|(16 if series else 0)))
        count=len(records);self.m.mem_write(desc+8,struct.pack('<I',count));self.m.mem_write(desc+24,struct.pack('<I',count))
        if count:
            pointer=self.cursor+4;self.cursor+=(count*128+4+15)&~15;require(self.cursor<0x70200000,'ARRAY_HEAP_LIMIT');self.m.mem_write(pointer-4,struct.pack('<I',4));self.m.mem_write(pointer,b''.join(records));self.m.mem_write(desc+28,struct.pack('<Q',pointer))
    def event(self,api,a=0,b=0,c=0,d=0,txt=''):
        self.events+=struct.pack('<i4Q',api,a&MASK,b&MASK,c&MASK,d&MASK)+text(txt)
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));c=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        if api==601:self.event(1,c['now']);m.reg_write(x.UC_X86_REG_RAX,c['now']&MASK);return
        if api==602:
            name=self.read_text(r('RDX'));require(name=='USD','CURRENCY_CHANGED');self.event(2,c['event_return'],len(c['events']),txt=name);records=[]
            for eventid,name in c['events']:
                raw=bytearray(128);struct.pack_into('<Q',raw,0,eventid);struct.pack_into('<IQ',raw,72,0,0 if name is None else self.string(name));records.append(raw)
            self.array(r('R8'),records,c['event_series']);m.reg_write(x.UC_X86_REG_RAX,c['event_return']&MASK);return
        if api==603:
            to=struct.unpack('<Q',m.mem_read(r('RSP')+40,8))[0];self.event(3,r('RDX'),r('R9'),to,c['value_return']);records=[]
            for t in c['values']:
                raw=bytearray(128);struct.pack_into('<q',raw,16,t);records.append(raw)
            self.array(r('R8'),records,c['value_series']);m.reg_write(x.UC_X86_REG_RAX,c['value_return']&MASK);return
        if api==604:self.arrays_freed+=1;return
        if api==605:self.error=r('RDX');m.emu_stop();return
        raise ValueError('UNEXPECTED_NFP_API '+str(api))
    def run(self,c):
        self.case=c;self.events=bytearray();self.error=0;self.arrays_freed=0;self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        for n,address in enumerate(self.nfp['type_tags']):m.mem_write(address,struct.pack('<H',(c['id']+n)&65535))
        m.mem_write(self.base+self.nfp['error'],struct.pack('<i',c['last_error']));top=0x5001fef8;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.emu_start(self.base+self.nfp['fn'],0x60000000,timeout=3000000,count=1000000);require(bool(self.error)==bool(c['fatal']),'NFP_FATAL_CLASS')
        if not self.error:require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NFP_NO_RETURN')
        value=m.reg_read(x.UC_X86_REG_RAX);last_error=struct.unpack('<I',m.mem_read(self.base+self.nfp['error'],4))[0]
        return struct.pack('<iQ2I',c['id'],value,last_error,len(self.events))+self.events
def identity(bot):
    home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NfpCalendarCheck.mq5'
    return dict(original_ex5_sha256=validation.original_hash(bot),sources_sha256={f.relative_to(source).as_posix():sha(f) for f in pub.closure(source/script,source)},helpers_sha256={f.relative_to(ROOT).as_posix():sha(f) for f in [Path(__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py']})
def execute(bot,folder,build,only=-1):
    home=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NfpCalendarCheck.mq5';receipt=home/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));require(b['errors']==b['warnings']==0 and b['target']==script,'BUILD_NOT_CLEAN')
    for n,h in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
    run=folder.name+('' if only<0 else '-e'+str(only));files=mt/f'MQL5/Files/bot{bot}-nfp-calendar'/run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    ini=mt/('nfp-'+run+'.ini');preset=mt/'MQL5/Presets'/('nfp-'+run+'.set');preset.write_text('CheckRun='+run+'\nOnlyCase='+str(only)+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}NfpCalendarCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    logs=mt/'MQL5/Logs';before={p:p.stat().st_size for p in logs.glob('*.log')};p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    log='\n'.join(p.read_bytes()[before.get(p,0):].decode('utf-16-le',errors='replace') for p in logs.glob('*.log'));return files,receipt,code,log
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare','errors']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN')
    folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();normal=[c for c in rows if not c['fatal']];current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(normal))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(normal),fatal_cases=len(rows)-len(normal),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(normal),fatal_cases=len(rows)-len(normal))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==n for k,n in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='original':
        o=Original(a.bot);raw=bytearray(header);errors=[]
        for c in rows:
            record=o.run(c)
            if c['fatal']:errors.append(dict(id=c['id'],error=hex(o.error),events_sha256=hashlib.sha256(o.events).hexdigest()))
            else:raw+=record
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'native-errors.json',errors);save(folder/'original-run.json',dict(**current,cases=len(normal),fatal_cases=len(errors),function_sha256=o.function_sha,instructions=len(o.covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(normal),instructions=len(o.covered),function_sha256=o.function_sha)));return
    if a.mode=='mql5':
        files,receipt,code,log=execute(a.bot,folder,a.build);require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(normal)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(normal),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(normal),exit_code=code)));return
    if a.mode=='errors':
        errors=json.loads((folder/'native-errors.json').read_text());results=[]
        for e in errors:
            files,receipt,code,log=execute(a.bot,folder,a.build,e['id']);require(code!=0 and 'array out of range' in log.lower() and 'NFP_CALENDAR_CASE:'+str(e['id']) in log and not(files/'script-status.bin').exists(),'FATAL_NOT_OBSERVED');require(sha(files/f'events-{e["id"]}.bin')==e['events_sha256'],'ERROR_EVENTS_CHANGED');results.append(dict(**e,matched=True,terminal_exit_code=code,log_sha256=hashlib.sha256(log.encode()).hexdigest()))
        save(folder/'errors.json',dict(cases=len(results),matched=len(results),results=results,**SCOPE));print(json.dumps(dict(cases=len(results),matched=len(results))));return
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==n for k,n in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')),'RUN_CHANGED')
    data=[(folder/(n+'-results.bin')).read_bytes() for n in ['original','mql5']];require(all(raw[:12]==header for raw in data),'RESULT_HEADER');positions=[12,12];fail=[]
    for c in normal:
        records=[]
        for i,raw in enumerate(data):
            start=positions[i];id_,value,err,length=struct.unpack_from('<iQ2I',raw,start);require(id_==c['id'],'RECORD_ID');positions[i]+=20+length;records.append(raw[start:positions[i]])
        if records[0]!=records[1]:fail.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*records)) if x!=y),None),head=[list(struct.unpack_from('<iQ2I',r)) for r in records]))
    require(all(p==len(raw) for p,raw in zip(positions,data)),'RESULT_TRAILING');report=dict(cases=len(normal),matched=len(normal)-len(fail),failed=len(fail),first_failures=fail[:20],**SCOPE,limits=['Complete NFP lookup only; calendar replies and successful allocation supplied. No calendar network or evaluator close/cancel branches.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(fail))
if __name__=='__main__':main()
