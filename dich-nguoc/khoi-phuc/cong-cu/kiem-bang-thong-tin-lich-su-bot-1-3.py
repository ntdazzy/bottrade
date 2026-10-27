"""Compare full native closed-history text/position scan with isolated MQL5.

prepare|mql5 --build BUILD|original|compare BOT RUN.
SDK replies are recorded in MQL5, then supplied to the unchanged native body.
This checks text and ordered calls, not a rendered chart or a complete EA.
"""
import argparse,copy,hashlib,importlib.util,json,random,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x4f535031;MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
entry=module('open_panel_entry','kiem-gia-vao-bot-1-3.py')
selector=module('open_panel_selector','kiem-chon-tin-day-du-bot-1-3.py')
pub=selector.pub;require=pub.require
CFG={1:dict(fn=0xffb0,end=0x10f5f,sha='a983ce70a15371803f27f8a20cbc91deb5febd64f3e8ec84d9497270969cb623',error=0x6a410),
     3:dict(fn=0x16e80,end=0x17ef2,sha='3c3a1f367bb3b45b48d3f0d6d6711fdbaca824f702aea587d5f4ab0b2c215927',error=0x1d6e10)}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,
           native_closed_status_body_executed=True,child_helpers_intercepted=False,
           terminal_replies_supplied=True,text_formatting_replies_measured_in_mt5=True,rendered_chart_verified=False,original_ex5_changed=False)
def fields(bot):
    return [('Show','B',0x6a528 if bot==1 else 0x1d6f38),('Tester','B',0x6a530 if bot==1 else 0x1d6f40),('Seed','i',0x6a610 if bot==1 else 0x1d6ff0),('PanelSymbol','s',0x67918 if bot==1 else 0x74958),('Wins','d',0x67900 if bot==1 else 0x74940),('Losses','d',0x67908 if bot==1 else 0x74948)]
def bits(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def word(v,kind):return bits(v) if kind=='d' else int(v)&MASK
def text(value):
    if value is None:return struct.pack('<i',-1)
    raw=value.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def save(p,v):
    with p.open('x',encoding='utf-8',newline='\n') as f:json.dump(v,f,ensure_ascii=False,indent=2);f.write('\n')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def cases(bot):
    out=[];defaults=dict(Show=1,Tester=1,Seed=9000,PanelSymbol='XAUUSD',Wins=7.,Losses=8.)
    def deal(magic=9001,profit=10.,commission=-1.,swap=-.5,ticket=21,symbol='XAUUSD'):
        return dict(ticket=ticket,symbol=symbol,magics=[magic],profit=[profit],commission=[commission],swap=[swap])
    def add(tag,values=None,deals=None,infos=(0,0),select=1,total=None,effects=None,error_mode=0):
        c=dict(id=len(out),tag=tag,values=copy.deepcopy(defaults),deals=deals or [],info=list(infos),select=select,total=len(deals or []) if total is None else total,effects=effects or [],error_mode=error_mode)
        c['values'].update(values or {});out.append(c);return c
    for show in [0,1,255]:
        for tester in [0,1,255]:
            for info in [(0,0),(0,1),(1,0),(1,1),(2,2)]:add('display-gates',dict(Show=show,Tester=tester),[deal()],infos=info)
    for select in [0,1]:
        for total in [-1,0,1,2]:add('history-selection-count',deals=[deal(),deal(ticket=22,profit=-10.)],select=select,total=total)
    for group in range(1,16 if bot==3 else 9):
        for profit in [-10.,0.,10.]:add('group-magic-and-direction',deals=[deal(magic=9000+group,profit=profit)])
    for ticket in [0,1,0x100000002]:
        for symbol in ['XAUUSD','OTHER','','Vàng']:add('ticket-zero-and-symbol',deals=[deal(ticket=ticket,symbol=symbol)],error_mode=1)
    for seed in [-2147483648,2147483647,-1]:
        for offset in [1,8,15]:
            magic=struct.unpack('<i',struct.pack('<I',(seed+offset)&0xffffffff))[0];add('signed-magic-wrap',dict(Seed=seed),[deal(magic=magic)])
    for profit in [0.,-0.,1.005,-1.005,1e19,-1e19,float('nan'),float('inf'),-float('inf')]:
        for commission,swap in [(0.,0.),(-1.,-.5),(float('inf'),-float('inf'))]:add('numeric-profit',deals=[deal(profit=profit,commission=commission,swap=swap)])
    d=deal();d['profit']=[10.,1.,-5.];d['commission']=[-2.,1.];d['swap']=[-.5,2.];add('fresh-double-reads',deals=[d])
    d=deal();d['magics']=[-1,9002];add('fresh-magic-reads',deals=[d])
    for a,b,c in [(1e16,1.,-1e16),(-0.,-0.,-0.),(float('inf'),-float('inf'),1.)]:add('addition-and-reverse-order',deals=[deal(profit=a,commission=0.,swap=0.),deal(profit=b,commission=0.,swap=0.,ticket=22),deal(profit=c,commission=0.,swap=0.,ticket=23)])
    for value in [7.,-7.,1e19,float('nan'),float('inf')]:add('preserved-numeric-counts',dict(Tester=0,Wins=value,Losses=value),infos=(0,1))
    mutations=[(1,1,'Tester',0),(1,2,'Tester',1),(3,1,'Seed',9001),(5,1,'Seed',9999),(6,1,'PanelSymbol','OTHER'),(9,1,'Losses',99.),(10,1,'Wins',88.)]
    for api,n,name,value in mutations:add('live-fields-'+name,deals=[deal()],effects=[dict(api=api,n=n,name=name,value=value)],error_mode=1)
    rng=random.Random(2026102790+bot)
    for _ in range(80):
        deals=[deal(magic=rng.randrange(8999,9017),profit=rng.uniform(-100.,100.),commission=rng.uniform(-3.,1.),swap=rng.uniform(-2.,2.),ticket=i+1,symbol=rng.choice(['XAUUSD','OTHER'])) for i in range(rng.randrange(5))];add('mixed-history',deals=deals,error_mode=rng.randrange(2))
    return out

def encode(rows,bot):
    fs=fields(bot);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<i',c['id'])
        for n,k,_ in fs:raw+=text(c['values'][n]) if k=='s' else struct.pack('<Q',word(c['values'][n],k))
        raw+=struct.pack('<6i',*c['info'],c['error_mode'],c['select'],c['total'],len(c['deals']))
        for d in c['deals']:
            raw+=struct.pack('<Q',d['ticket'])+text(d['symbol'])
            for key in ['magics','profit','commission','swap']:raw+=struct.pack('<i',len(d[key]))+struct.pack('<'+('q' if key=='magics' else 'd')*len(d[key]),*d[key])
        raw+=struct.pack('<i',len(c['effects']))
        for e in c['effects']:
            index=next(i for i,f in enumerate(fs) if f[0]==e['name']);kind=fs[index][1];raw+=struct.pack('<3i',e['api'],e['n'],index)+(text(e['value']) if kind=='s' else struct.pack('<Q',word(e['value'],kind)))
    return raw
class Reader:
    def __init__(self,raw):self.raw=memoryview(raw);self.pos=0
    def take(self,fmt):
        out=struct.unpack_from('<'+fmt,self.raw,self.pos);self.pos+=struct.calcsize('<'+fmt);return out
    def block(self):n,=self.take('i');require(0<=n<=len(self.raw)-self.pos,'BLOCK_BOUNDS');raw=bytes(self.raw[self.pos:self.pos+n]);self.pos+=n;return raw
    def text(self):
        n,=self.take('i');require(-1<=n<=100000,'TEXT_BOUNDS');raw=bytes(self.raw[self.pos:self.pos+max(0,n)*2]);self.pos+=max(0,n)*2;return None if n<0 else raw.decode('utf-16-le')
class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.panel=CFG[bot];self.fs=fields(bot);cfg=self.panel
        require(sha_bytes(self.m.mem_read(self.base+cfg['fn'],cfg['end']-cfg['fn']))==cfg['sha'],'OPEN_PANEL_BYTES_CHANGED')
        offsets={1:0x7c0fd0,2:0x7d84f0,3:0x7d8810,4:0x7d8860,5:0x7d8940,6:0x7d89d0,7:0x7d88b0,8:0x7cd7c0,9:0x7cdfe0,10:0x7c3c80}
        self.sdk={0x7ff683f20000+offset:api for api,offset in offsets.items()};self.covered=set()
        for address in self.sdk:
            existed=address in self.apis
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,a,s,u:self.covered.add(a-self.base),begin=self.base+cfg['fn'],end=self.base+cfg['end']-1)
    def read_text(self,desc):
        pointer=struct.unpack('<Q',self.m.mem_read(desc+4,8))[0]
        if pointer==0:return None
        n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(n<100000,'NATIVE_TEXT_LENGTH')
        return bytes(self.m.mem_read(pointer,n*2)).decode('utf-16-le')
    def put(self,n,kind,address,v):
        if kind=='s':raw=struct.pack('<IQ',0,0 if not v else self.string(v))
        elif kind=='d':raw=struct.pack('<d',v)
        else:raw=(int(v)&((1<<(8*struct.calcsize('<'+kind)))-1)).to_bytes(struct.calcsize('<'+kind),'little')
        self.m.mem_write(self.base+address,raw)
    def state(self):
        raw=bytearray()
        for n,k,a in self.fs:
            if k=='s':raw+=text(self.read_text(self.base+a))
            else:
                value=struct.unpack('<'+('Q' if k=='d' else k),self.m.mem_read(self.base+a,struct.calcsize('<'+k)))[0]
                raw+=struct.pack('<Q',value&MASK)
        raw+=struct.pack('<Q',struct.unpack('<I',self.m.mem_read(self.base+self.panel['error'],4))[0]);return bytes(raw)
    def call(self,m,address,size,user):
        if address not in self.sdk:return super().call(m,address,size,user)
        api=self.sdk[address];rd=self.tape;x=self.x;r=lambda name:m.reg_read(getattr(x,'UC_X86_REG_'+name));sp=r('RSP')
        before=rd.block();require(before==self.state(),'STATE_BEFORE_SDK '+str((self.case['id'],api,self.calls)))
        kind,*args=rd.take('i4Q');texts=[rd.text() for _ in range(4)];reply,error=rd.take('QI')
        require(kind==api,'SDK_ORDER '+str((self.case['id'],kind,api,self.calls)))
        actual=[0,0,0,0];strings=[None]*4
        if api==1:actual[0]=r('RDX')
        elif api==2:actual[:2]=[r('RDX'),r('R8')]
        elif api==3:pass
        elif api==4:actual[0]=r('RDX')&0xffffffff
        elif api in [5,6,7]:actual[:2]=[r('RDX'),r('R8')]
        elif api==8:actual[:2]=[r('XMM1')&MASK,r('R8')&0xffffffff]
        elif api==9:actual[:3]=[r('RDX'),r('R8')&0xffffffff,r('R9')&65535]
        elif api==10:
            actual[:2]=[r('RDX'),r('R9')];strings[:2]=[self.read_text(r('R8')),self.read_text(struct.unpack('<Q',m.mem_read(sp+40,8))[0])]
        require(actual==args,'SDK_ARGUMENTS '+str((self.case['id'],api,actual,args)))
        if api==10:require(strings[:2]==texts[:2],'OBJECT_TEXT '+str((self.case['id'],strings[:2],texts[:2])))
        if api in [6,8,9]:
            m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,0 if not texts[0] else self.string(texts[0])))
        elif api==7:m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',reply));m.reg_write(x.UC_X86_REG_XMM0,reply)
        else:m.reg_write(x.UC_X86_REG_RAX,reply)
        m.mem_write(self.base+self.panel['error'],struct.pack('<I',error));self.counts[api]=self.counts.get(api,0)+1;self.calls+=1
        for effect in self.case['effects']:
            if effect['api']==api and effect['n']==self.counts[api]:
                f=next(f for f in self.fs if f[0]==effect['name']);self.put(*f,effect['value'])
    def run(self,c,tape):
        self.case=c;self.tape=Reader(tape);self.counts={};self.calls=0;self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for field in self.fs:self.put(*field,c['values'][field[0]])
        m.mem_write(self.base+self.cfg['string_result'],bytes(12));m.mem_write(self.base+self.panel['error'],bytes(4))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        top=0x5001fef8;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        try:m.emu_start(self.base+self.panel['fn'],0x60000000,timeout=3000000,count=1000000)
        except self.uc.UcError as e:raise RuntimeError('NATIVE_EXECUTION '+str((c['id'],hex(m.reg_read(x.UC_X86_REG_RIP)),e))) from e
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_NO_RETURN')
        final=self.tape.block();require(self.tape.pos==len(tape),'UNCONSUMED_TAPE '+str(c['id']));require(final==self.state(),'FINAL_STATE '+str(c['id']))
        return struct.pack('<2i',c['id'],len(tape))+tape
def sha_bytes(raw):return hashlib.sha256(bytes(raw)).hexdigest()
def identity(bot):
    home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}ClosedStatusPanelCheck.mq5'
    helpers=[Path(__file__),ROOT/'cong-cu/tao-bo-kiem-bang-thong-tin-lich-su-bot-1-3.py',ROOT/'cong-cu/tao-bo-kiem-bang-thong-tin-mo-bot-1-3.py',ROOT/'cong-cu/kiem-bang-thong-tin-mo-bot-1-3.py',ROOT/'cong-cu/kiem-chon-tin-day-du-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py']
    return dict(original_ex5_sha256=selector.validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def execute(bot,folder,build):
    home=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}ClosedStatusPanelCheck.mq5'
    receipt=home/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for name,digest in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/name)==b['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
    files=mt/f'MQL5/Files/bot{bot}-closed-panel'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    ini=mt/('closed-panel-'+folder.name+'.ini');preset=mt/'MQL5/Presets'/('closed-panel-'+folder.name+'.set');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16')
    ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}ClosedStatusPanelCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def records(raw,count):
    rd=Reader(raw);require(rd.take('3i')==(MAGIC,1,count),'RESULT_HEADER');out=[]
    for i in range(count):id_,n=rd.take('2i');require(id_==i and 0<=n<=len(raw)-rd.pos,'RECORD_BOUNDS');out.append(bytes(rd.raw[rd.pos:rd.pos+n]));rd.pos+=n
    require(rd.pos==len(raw),'TRAILING_RECORDS');return out
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN')
    rows=cases(a.bot);home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot)
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows,a.bot));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows,a.bot),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tapes=records((folder/'mql5-results.bin').read_bytes(),len(rows));o=Original(a.bot);raw=struct.pack('<3i',MAGIC,1,len(rows));calls=0
        for c,tape in zip(rows,tapes):raw+=o.run(c,tape);calls+=o.calls
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),instructions=len(o.covered),sdk_calls=calls,result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=calls,instructions=len(o.covered))));return
    runs=[json.loads((folder/(n+'-run.json')).read_text()) for n in ['original','mql5']]
    for name,run in zip(['original','mql5'],runs):require(all(run[k]==v for k,v in current.items()) and run['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    left,right=[records((folder/(n+'-results.bin')).read_bytes(),len(rows)) for n in ['original','mql5']];failed=[c['id'] for c,x,y in zip(rows,left,right) if x!=y]
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:10],sdk_calls=runs[0]['sdk_calls'],**SCOPE,limits=['Full closed-history panel, native deal loop and text, ordered SDK calls, supplied history replies and actual MT5 formatting. No chart rendering, lifecycle or complete EA.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
