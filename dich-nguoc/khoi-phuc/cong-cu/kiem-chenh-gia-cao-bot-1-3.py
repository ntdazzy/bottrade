"""Compare continuous news -> Friday -> high-spread storage and actual trading children.
prepare|mql5(--build)|original|compare BOT RUN. The low-spread restoration branch is outside this scope.
"""
import argparse,copy,hashlib,importlib.util,json,math,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1
def module(name,file):
    spec=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
news=module('spread_friday','kiem-tin-va-cuoi-tuan-bot-1-3.py');base=news.base
pub=base.pub;require=pub.require;sha=base.sha;save=base.save;MAGIC=base.MAGIC
CFG={1:dict(pass_ends=[0x1c80c,0x1c85c],enabled=0x623d4,points=0x623e0,maximum=0x623d8,minimum=0x62558,unit=0x66d98,spread=0x62560,queue_enabled=0x66420,orders=0x65470,results=0x65dd0),
     3:dict(pass_ends=[0x269ab,0x269fb],enabled=0x6d4cc,points=0x6d4d8,maximum=0x6d4d0,minimum=0x6d648,unit=0x73dd8,spread=0x6d650,queue_enabled=0x73468,orders=0x724b0,results=0x72e10)}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_news_friday_high_spread_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,numeric_conversion_measured_in_mt5=True,original_ex5_changed=False)
def number(bits):return struct.unpack('<d',struct.pack('<Q',bits))[0]
def signed(v):return v if v<(1<<63) else v-(1<<64)
def cases():
    rows=news.cases()
    for c in rows:c.update(wide_enabled=0,points=20,maximum=.5,minimum=1.,unit=1.,spread=7777.,queue_enabled=1,ask=101.,bid=100.,gap=1.,ticket=11,prices=[90. if c['orders']==2 else 110.]*6,volume=.25,pattern=0,wide_mutation=0,second_magic=c['order_magic'])
    prototype=copy.deepcopy(rows[0]);prototype.update(enabled=0,ir_settings=[0,0,0,10,10],cpi_settings=[0,0,0,10,10],friday=[0,20,0,1,1],wide_enabled=1,orders=1,position=0,order_magic=42,second_magic=42,order_select=1,accepted=1)
    def add(tag,**changes):
        c=copy.deepcopy(prototype);c.update(changes);c['tag']=tag;rows.append(c);return c
    for enabled in [0,1,255]:
        for maximum in [-1.,0.,1.,math.nextafter(1.,0.),math.nan,math.inf,-math.inf]:
            for minimum in [-1.,0.,1.,math.nan]:add('spread-gate-and-minimum',wide_enabled=enabled,maximum=maximum,minimum=minimum)
    for direction in [4,5]:
        price=110. if direction==4 else 90.
        for flag in [0,1,2,255]:
            for minimum in [-1.,0.,1.,math.nan]:add('store-delete-flags',first_type=direction,second_type=direction,prices=[price]*6,queue_enabled=flag,minimum=minimum)
        for pattern in range(8):add('queue-and-result-slot',first_type=direction,second_type=direction,prices=[price]*6,pattern=pattern)
        for points in [-2147483648,-1,0,1,10,20,2147483647]:add('signed-distance-points',first_type=direction,second_type=direction,prices=[price]*6,points=points)
        for first in [math.nan,math.inf,-math.inf,80.,90.,100.,101.,110.,121.,122.]:add('first-price-strict-comparison',first_type=direction,second_type=direction,prices=[first,price,price,price,price,price])
        for second in [math.nan,math.inf,-math.inf,90.,100.,101.,102.,110.]:add('second-price-strict-comparison',first_type=direction,second_type=direction,prices=[price,second,price,price,price,price])
        for mode in range(1,9):add('high-spread-service-effects',first_type=direction,second_type=direction,prices=[price]*6,wide_mutation=mode,second_magic=0 if mode==6 else 42)
    for magic,second in [(42,42),(99,0),(99,99),(42+(1<<32),0)]:add('two-magic-reads',order_magic=magic,second_magic=second)
    for ticket in [0,11,999,0x100000002,0x7fffffffffffffff,0x8000000000000001,0xffffffffffffffff]:add('ticket-cast-and-result-comparison',ticket=ticket,pattern=6)
    for unit in [0.,-0.,-1.,math.nan,math.inf,-math.inf]:add('unit-special',unit=unit)
    for gap in [-1.,0.,1.,10.,math.nan,math.inf,-math.inf]:add('gap-special',gap=gap)
    for symbol in [0,1,2]:add('symbol-full-match',symbol_mode=symbol)
    for total in [-1,0,1,2]:add('total-and-inclusive-index',orders=total)
    for async_mode in [0,1]:
        for accepted in [0,1]:add('send-result',async_mode=async_mode,accepted=accepted,order_select=accepted)
    add('both-type-branches',first_type=4,second_type=5,prices=[110.,110.,111.,90.,90.,89.])
    for i,c in enumerate(rows):c['id']=i
    return rows

def table(c):
    orders=[[0.,0.,0.] for _ in range(100)];results=[[0.,-float(i)-.25] for i in range(100)];pattern=c['pattern']
    if pattern in [1,2,3,4]:
        for i in range(100):orders[i]=[math.nan if pattern==4 else 1000.+i,7.,.5]
        if pattern in [1,2,4]:orders[[1,99,99][[1,2,4].index(pattern)]][0]=-0.
    ticket=float(signed(c['ticket']));results[0]=[ticket,3.];results[1]=[ticket,4.]
    if pattern==5:results[0]=[math.nan,9.];results[99]=[ticket,8.]
    if pattern==7:results=[[float(i+10000),-float(i)] for i in range(100)]
    return orders,results

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=news.encode([c])[12:]+struct.pack('<3q7Q3q8Q',c['wide_enabled'],c['points'],c['queue_enabled'],*[base.bits(c[n]) for n in ['maximum','minimum','unit','spread','ask','bid','gap']],c['pattern'],c['wide_mutation'],c['second_magic'],c['ticket'],*[base.bits(v) for v in c['prices']],base.bits(c['volume']))
        orders,results=table(c);raw+=struct.pack('<500d',*[v for row in orders+results for v in row])
    return bytes(raw)
def cast_values(path):
    r=base.Reader(path.read_bytes());require(r.take('2i')==(MAGIC,1),'CAST_HEADER');out={}
    for _ in range(r.take('i')[0]):
        kind,value,error=r.take('iQI');text=r.text();key=(kind,value)
        require(key not in out or out[key]==(text,error),'CAST_REPLY_CHANGED');out[key]=(text,error)
    require(r.pos==len(r.raw),'CAST_TRAILING');return out
class Original(news.Original):
    def __init__(self,bot,casts):
        super().__init__(bot);self.wide=CFG[bot];self.nfp=dict(self.nfp,end=self.wide['pass_ends'][-1]);self.casts=casts;a=0x7ff683f20000+0x7cf6c0
        if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
        self.sdk[a]=32;self.m.mem_write(a,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        if bot==1:require(hashlib.sha256(bytes(self.m.mem_read(self.base+0x30320,0x31f35-0x30320))).hexdigest()=='21c60f7b2f2e21bce92f1840b8025e4a1c921074b32834404439021aca11df55','STORAGE_HELPER_CHANGED')
    def state(self):
        raw=super().state();c=self.wide
        raw+=struct.pack('<3Q',self.value(c['enabled'],'B'),self.value(c['points'],'i')&MASK,self.value(c['queue_enabled'],'B'))
        raw+=b''.join(bytes(self.m.mem_read(self.base+c[n],8)) for n in ['maximum','minimum','unit','spread'])
        raw+=bytes(self.m.mem_read(self.base+c['orders'],2400))+bytes(self.m.mem_read(self.base+c['results'],1600));return raw
    def visit(self,m,address,size,user):
        if address==self.base+self.nfp['start'] and not self.wide_seeded:
            self.wide_seeded=True;c=self.case;w=self.wide
            for n,k in [('enabled','B'),('points','i'),('queue_enabled','B')]:m.mem_write(self.base+w[n],struct.pack('<'+k,c['wide_enabled' if n=='enabled' else n]))
            for n in ['maximum','minimum','unit','spread']:m.mem_write(self.base+w[n],struct.pack('<d',c[n]))
            for a,v in zip(self.nfp['variables'],[c['bid'],c['ask'],1.,c['gap']]):m.mem_write(self.base+a,struct.pack('<d',v))
            orders,results=table(c);m.mem_write(self.base+w['orders'],struct.pack('<300d',*[v for row in orders for v in row]));m.mem_write(self.base+w['results'],struct.pack('<200d',*[v for row in results for v in row]))
        if address-self.base in self.wide['pass_ends']:self.done=True;m.emu_stop();return
        return super().visit(m,address,size,user)
    def call(self,m,address,size,user):
        api=self.sdk.get(address)
        if api==32:
            x=self.x;kind=m.reg_read(x.UC_X86_REG_R8)&0xffffffff;value=m.reg_read(x.UC_X86_REG_RDX);require(m.reg_read(x.UC_X86_REG_RCX)==self.nfp['ctx'] and (kind,value) in self.casts,'UNMEASURED_NUMERIC_CONVERSION '+str((self.case['id'],kind,value)))
            text,error=self.casts[(kind,value)];m.mem_write(m.reg_read(x.UC_X86_REG_R9),struct.pack('<IQ',0,self.string(text)));m.mem_write(self.base+self.nfp['error'],struct.pack('<I',error));self.cast_calls+=1;return
        if not api:return super().call(m,address,size,user)
        peek=base.Reader(self.tape.raw[self.tape.pos:]);peek.block();kind,*args=peek.take('i4Q');strings=[peek.text() for _ in range(4)]
        if api==14:
            rd=self.tape;require(rd.block()==self.state(),'SPREAD_STATE_BEFORE_TICKET');kind,*args=rd.take('i4Q');texts=[rd.text() for _ in range(4)];payload=rd.block();error,=rd.take('I');index=m.reg_read(self.x.UC_X86_REG_RDX)&0xffffffff
            expected=self.case['ticket'] if self.case['orders']!=0 and index==0 else 0
            require(kind==14 and args==[index,expected,0,0] and texts==[None]*4 and payload==b'' and m.reg_read(self.x.UC_X86_REG_RCX)==self.nfp['ctx'],'SPREAD_TICKET_ARGUMENT_OR_REPLY');m.reg_write(self.x.UC_X86_REG_RAX,expected);m.mem_write(self.base+self.nfp['error'],struct.pack('<I',error));self.api_count+=1;self.price_reads=0;self.magic_reads=0
        else:super().call(m,address,size,user)
        c=self.case;w=self.wide;mode=c['wide_mutation'];target=None;value=None;fmt='d'
        if api==19 and args[0]==9:
            self.price_reads+=1
            if mode==1 and self.price_reads==1:target=self.nfp['variables'][1];value=105.
            elif mode==2 and self.price_reads==2:target=self.nfp['variables'][1];value=1000.
        if mode==3 and api==10 and strings[0] and strings[0].startswith('Spread too high..('):target=w['queue_enabled'];value=0;fmt='B'
        elif mode==4 and api==10 and strings[0] and strings[0].startswith('Storing pending order nr '):target=self.nfp['ticket'];value=999;fmt='Q'
        elif mode==5 and api==19 and args[0]==7:m.mem_write(self.base+w['results'],struct.pack('<2d',float(signed(self.value(self.nfp['ticket'],'Q'))),3.))
        elif mode==6 and api==17 and args[0]==15:
            self.magic_reads+=1
            if self.magic_reads==1:target=self.nfp['magic'];value=43;fmt='i'
        elif mode==7 and api==10 and strings[0] and strings[0].startswith('Spread too high..('):target=w['minimum'];value=-1.
        elif mode==8 and api==18:target=self.nfp['symbol'];m.mem_write(self.base+target,struct.pack('<IQ',0,self.string('OTHER')));target=None
        if target is not None:m.mem_write(self.base+target,struct.pack('<'+fmt,value))
    def run(self,c,tape):
        self.wide_seeded=False;self.price_reads=self.magic_reads=0;return super().run(c,tape)

def identity(bot):
    h=ROOT/f'bot-cua-toi-{bot}';source=h/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NewsFridaySpreadCheck.mq5';helpers=dict(news.identity(bot)['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=base.validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256=helpers)
def execute(bot,folder,build):
    h=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';receipt=h/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NewsFridaySpreadCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,v in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==v,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/f'MQL5/Files/bot{bot}-news-friday-spread'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('friday-'+folder.name+'.set');ini=mt/('friday-'+folder.name+'.ini');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}NewsFridaySpreadCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');rows=cases();folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','sdk-tape.bin','script-status.bin','cast-values.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),casts_sha256=sha(folder/'cast-values.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tape=base.Reader((folder/'sdk-tape.bin').read_bytes());require(tape.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Original(a.bot,cast_values(folder/'cast-values.bin'));o.cast_calls=0;raw=bytearray(header);calls=0
        for c in rows:
            require(tape.take('i')[0]==c['id'],'TAPE_CASE_ID');state=o.run(c,tape.block());raw+=struct.pack('<2i',c['id'],len(state))+state;calls+=o.api_count
        require(tape.pos==len(tape.raw),'TAPE_TRAILING')
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),sdk_calls=calls,cast_calls=o.cast_calls,casts_sha256=sha(folder/'cast-values.bin'),parent_instructions=len(o.covered),**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=calls)));return
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')) and r['sdk_tape_sha256']==sha(folder/'sdk-tape.bin') and r['casts_sha256']==sha(folder/'cast-values.bin'),'RUN_CHANGED')
    data=[base.Reader((folder/(n+'-results.bin')).read_bytes()) for n in ['original','mql5']];require(all(r.take('3i')==(MAGIC,1,len(rows)) for r in data),'RESULT_HEADER');fail=[]
    for c in rows:
        states=[]
        for r in data:require(r.take('i')[0]==c['id'],'RESULT_ID');states.append(r.block())
        if states[0]!=states[1]:fail.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*states)) if x!=y),None),sizes=list(map(len,states))))
    require(all(r.pos==len(r.raw) for r in data),'RESULT_TRAILING');result=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:12],**SCOPE,limits=['News, Friday and high-spread storage only; stops before low-spread restoration and limits. Initial frame/state, terminal replies, successful allocation and measured number-to-text conversions supplied. No full evaluator or EA.'])
    save(folder/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(fail))
if __name__=='__main__':main()
