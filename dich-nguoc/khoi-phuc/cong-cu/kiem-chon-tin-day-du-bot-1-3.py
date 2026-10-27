"""Compare complete news selector: native timestamps, labels, live server reads, int32 minute products.

prepare|original|mql5(--build)|compare BOT RUN. Original string helpers execute unchanged.
"""
import argparse,copy,hashlib,importlib.util,json,random,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x4e535331;MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
entry=module('selector_entry','kiem-gia-vao-bot-1-3.py');pub=module('selector_pub','kiem-ban-git-quan-ly.py');require=pub.require
validation=module('selector_validation','kiem-khoi-luong-hop-le-bot-1-3.py')
CFG={1:dict(fn=0x7310,end=0x74f8,sha='2f43b2c85e95e2b503ee320c49bcb2cb544666643e7a2376240a86ca6cc7ad99',time=0x6a390,label=0x6a398,times=[0x6a360,0x6a368,0x6a370],flags=[0x6a640,0x6a698,0x6a6d0],minutes=[0x6a680,0x6a6b8,0x6a6f0]),
 3:dict(fn=0x7c30,end=0x7e18,sha='1b0de407cffc2b1b89f6802fea31ee0be772e33796ebd0e3a1463eb03d0ca6ff',time=0x1d6ca0,label=0x1d6ca8,times=[0x1d6c70,0x1d6c78,0x1d6c80],flags=[0x1d7020,0x1d7078,0x1d70b0],minutes=[0x1d7060,0x1d7098,0x1d70d0])}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_full_news_selector_executed=True,child_helpers_intercepted=False,server_time_replies_supplied=True,original_ex5_changed=False)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def text(s):
    if s is None:return struct.pack('<i',-1)
    raw=s.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def save(p,o):
    with p.open('x',encoding='utf-8',newline='\n') as f:json.dump(o,f,ensure_ascii=False,indent=2)
def cases():
    out=[]
    def add(times=(900,1000,1100),flags=(1,1,1),minutes=(10,10,10),clocks=(1000,1000,1000),mutation=0,tag=''):
        out.append(dict(id=len(out),times=list(times),flags=list(flags),minutes=list(minutes),clocks=list(clocks),mutation=mutation,tag=tag))
    for flags in range(8):
        for times in [(0,0,0),(-1,1000,1100),(900,1000,1100),(1000,900,1100),(1000,1100,900),(1000,1000,1000)]:
            for minutes in [-2147483648,-2147483647,-71582789,-35791395,-1,0,1,35791394,35791395,71582788,2147483647]:
                add(times,[(flags>>i)&1 for i in range(3)],[minutes]*3,tag='int32-minutes-and-priority')
    for times in [(1,2,3),((1<<63)-2,(1<<63)-1,1),(-(1<<63),1,(1<<63)-1)]:
        for minute in [0,1,-1,2147483647]:add(times,minutes=[minute]*3,tag='long-time-wrap')
    for flags in [(255,255,255),(2,0,0),(0,2,0),(0,0,2)]:add(flags=flags,tag='nonzero-byte-flags')
    for clocks in [(1000,999,998),(1000,1600,900),(1499,1500,1700),(1500,1500,1500),(1501,1501,1501)]:add(clocks=clocks,tag='fresh-server-time')
    for mutation in range(1,7):
        for clocks in [(1000,1000,1000),(1000,900,800)]:add(mutation=mutation,clocks=clocks,tag='mutate-after-server-call')
    rng=random.Random(2026102711)
    for _ in range(400):add(times=[rng.choice([-1,0,1,rng.randrange(1,2000000000)]) for _ in range(3)],flags=[rng.choice([0,1,2,255]) for _ in range(3)],minutes=[rng.choice([-2147483648,2147483647,-100,0,1,10,35791395]) for _ in range(3)],clocks=[rng.randrange(2000000000)]*3,tag='mixed-selector')
    return out
def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<i3q3i3i3qi',c['id'],*c['times'],*c['flags'],*c['minutes'],*c['clocks'],c['mutation']) for c in rows)
class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.selector=CFG[bot];cfg=self.selector;require(hashlib.sha256(bytes(self.m.mem_read(self.base+cfg['fn'],cfg['end']-cfg['fn']))).hexdigest()==cfg['sha'],'SELECTOR_BYTES_CHANGED')
        a=0x7ff683f20000+0x7d1ce0;require(a not in self.apis,'SERVER_ALREADY_BOUND')
        if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
        self.apis[a]=601;self.m.mem_write(a,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        self.covered=set();self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,a,s,u:self.covered.add(a-self.base),begin=self.base+cfg['fn'],end=self.base+cfg['end']-1)
    def read_text(self,desc):
        p=struct.unpack('<Q',self.m.mem_read(desc+4,8))[0]
        if not p:return None
        n=struct.unpack('<I',self.m.mem_read(p-4,4))[0];require(n<1000,'SELECTOR_TEXT_SIZE');return bytes(self.m.mem_read(p,n*2)).decode('utf-16-le')
    def state(self):
        m=self.m;cfg=self.selector;raw=bytes(m.mem_read(self.base+cfg['time'],8))+text(self.read_text(self.base+cfg['label']))
        for key,kind in [('times','q'),('flags','B'),('minutes','i')]:
            for a in cfg[key]:raw+=struct.pack('<Q',struct.unpack('<'+kind,m.mem_read(self.base+a,struct.calcsize('<'+kind)))[0]&MASK)
        return raw
    def mutate(self):
        cfg=self.selector;m=self.m;mode=self.case['mutation'];n=self.clock_calls
        if mode==1 and n==1:m.mem_write(self.base+cfg['times'][0],struct.pack('<q',1700))
        elif mode==2 and n==2:m.mem_write(self.base+cfg['times'][1],struct.pack('<q',50))
        elif mode==3 and n==2:m.mem_write(self.base+cfg['times'][2],struct.pack('<q',20))
        elif mode==4 and n==1:m.mem_write(self.base+cfg['flags'][1],b'\0')
        elif mode==5 and n==1:m.mem_write(self.base+cfg['minutes'][1],struct.pack('<i',2147483647))
        elif mode==6 and n==2:m.mem_write(self.base+cfg['time'],struct.pack('<q',5));m.mem_write(self.base+cfg['label'],struct.pack('<IQ',0,self.string('Changed')))
    def call(self,m,address,size,user):
        if self.apis[address]!=601:return super().call(m,address,size,user)
        value=self.case['clocks'][min(self.clock_calls,2)];self.events+=struct.pack('<q',value)+self.state();self.clock_calls+=1;self.mutate();m.reg_write(self.x.UC_X86_REG_RAX,value&MASK)
    def run(self,c):
        self.case=c;self.events=bytearray();self.clock_calls=0;self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x;cfg=self.selector
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        for key,kind in [('times','q'),('flags','B'),('minutes','i')]:
            for a,v in zip(cfg[key],c[key]):m.mem_write(self.base+a,struct.pack('<'+kind,v))
        m.mem_write(self.base+cfg['time'],struct.pack('<q',999));m.mem_write(self.base+cfg['label'],struct.pack('<IQ',0,self.string('Previous')))
        top=0x5001fef8;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.emu_start(self.base+cfg['fn'],0x60000000,timeout=2000000,count=100000);require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000 and self.allocs==self.frees,'SELECTOR_NO_CLEAN_RETURN')
        return struct.pack('<2i',c['id'],len(self.events))+self.events+self.state()
def identity(bot):
    home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NewsSelectorCheck.mq5';return dict(original_ex5_sha256=validation.original_hash(bot),sources_sha256={f.relative_to(source).as_posix():sha(f) for f in pub.closure(source/script,source)},helpers_sha256={f.relative_to(ROOT).as_posix():sha(f) for f in [Path(__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py']})
def execute(bot,folder,build):
    home=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NewsSelectorCheck.mq5';receipt=home/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,h in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/f'MQL5/Files/bot{bot}-news-selector'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    ini=mt/('selector-'+folder.name+'.ini');preset=mt/'MQL5/Presets'/('selector-'+folder.name+'.set');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}NewsSelectorCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');rows=cases();folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==n for k,n in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='original':
        o=Original(a.bot);raw=header+b''.join(o.run(c) for c in rows)
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),instructions=len(o.covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(o.covered))));return
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','script-status.bin','numeric-regression.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),numeric_regression_sha256=sha(folder/'numeric-regression.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    for name in ['original','mql5']:
        r=json.loads((folder/(name+'-run.json')).read_text());require(all(r[k]==n for k,n in current.items()) and r['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    raw=[(folder/(n+'-results.bin')).read_bytes() for n in ['original','mql5']];require(all(b[:12]==header for b in raw),'RESULT_HEADER');positions=[12,12];failed=[];selected=[]
    def state_end(data,at):
        n,=struct.unpack_from('<i',data,at+8);require(-1<=n<1000,'STATE_LABEL_SIZE');return at+12+2*max(n,0)+72
    for c in rows:
        blocks=[]
        for i,data in enumerate(raw):
            start=positions[i];id_,length=struct.unpack_from('<2i',data,start);require(id_==c['id'],'RECORD_ID');state_at=start+8+length;positions[i]=state_end(data,state_at);blocks.append(data[start:positions[i]])
            if i==0:selected.append(struct.unpack_from('<q',data,state_at)[0])
        if blocks[0]!=blocks[1]:failed.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*blocks)) if x!=y),None),sizes=list(map(len,blocks))))
    require(all(at==len(data) for at,data in zip(positions,raw)),'RESULT_TRAILING');require(sha(folder/'numeric-regression.bin')==json.loads((folder/'mql5-run.json').read_text())['numeric_regression_sha256'],'NUMERIC_REGRESSION_CHANGED');reg=(folder/'numeric-regression.bin').read_bytes();require(len(reg)%12==0,'NUMERIC_REGRESSION_SIZE');numeric=[]
    for at in range(0,len(reg),12):
        id_,time=struct.unpack_from('<iq',reg,at);require(rows[id_]['mutation']==0 and len(set(rows[id_]['clocks']))==1,'NUMERIC_REGRESSION_CONTEXT');numeric.append(id_)
        if time!=selected[id_]:failed.append(dict(id=id_,tag='legacy-numeric-regression',native=selected[id_],source=time))
    report=dict(cases=len(rows),matched=len(rows)-len({f['id'] for f in failed}),failed=len({f['id'] for f in failed}),first_failures=failed[:15],numeric_regression_cases=len(numeric),**SCOPE,limits=['Full selector including labels and ordered server reads; data from earlier calendar/close branches and server replies supplied. No complete evaluator or EA.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
