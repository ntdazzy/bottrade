"""Compare the continuous news -> Friday section and actual cancel/close/send bodies.
prepare|mql5(--build)|original|compare BOT RUN. Private MT5 only.
"""
import argparse,copy,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1
def module(name,file):
    spec=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
news=module('friday_news','kiem-chuoi-tin-bot-1-3.py');base=news.base
pub=base.pub;require=pub.require;sha=base.sha;save=base.save;MAGIC=base.MAGIC
CFG={1:dict(end=0x1c79a,fields=[0x62555,0x62414,0x67460],helper=(0x30010,0x30313,'a09b1a012a492440cf1d32c4b08a5e5bd424bf66289c295792ea2f1263bb9ae1')),
     3:dict(end=0x25040,fields=[0x6d645,0x6d50c,0x744a0,0x1d6fb0,0x1d6fb8],helper=(0x3d650,0x3da89,'4138bab79526496668a635dc4a7a5f61d0238e4e9f3641b825724af22a1e8e78'))}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_news_and_friday_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
def cases():
    rows=news.cases()
    for c in rows:c.update(friday=[0,20,0,1,1],seed=42,order_magic=42,symbol_mode=0,first_type=5 if c['orders']==2 else 4,second_type=5 if c['orders']==2 else 4,mutation=0,after_seed=43)
    prototype=copy.deepcopy(rows[0]);prototype.update(enabled=0,ir_settings=[0,0,0,10,10],cpi_settings=[0,0,0,10,10],friday=[1,20,0,1,1],orders=1,position=1,order_magic=43)
    prototype['cached'][6]=5;prototype['cached'][3]=20
    def add(tag,**changes):
        c=copy.deepcopy(prototype);c.update(changes);c['tag']=tag;rows.append(c);return c
    for enabled in [0,1,2,255]:
        for day in [4,5,6]:
            for hour in [19,20,21]:
                for closed in [0,1,2,255]:
                    c=add('friday-gate-and-reset',friday=[enabled,20,closed,1,1]);c['cached'][6]=day;c['cached'][3]=hour
    for pending in [0,1,2,255]:
        for positions in [0,1,2,255]:add('bot3-independent-actions',friday=[1,20,0,pending,positions])
    for order in [1,2]:
        for position in [0,1,2]:
            for async_mode in [0,1]:
                for accepted in [0,1]:add('friday-real-trade-bodies',orders=order,position=position,async_mode=async_mode,accepted=accepted,order_select=accepted,first_type=5 if order==2 else 4,second_type=5 if order==2 else 4)
    for seed in [42,2147483647,-2147483648,-1]:
        for offset in [-1,0,1,8,9,15,16]:
            low=(seed+offset)&0xffffffff;magic=low if low<0x80000000 else low-0x100000000
            add('accepted-magic-signed-wrap',seed=seed,order_magic=magic)
    for offset in range(1,16):add('each-magic-short-circuit',order_magic=42+offset)
    for magic in [43+(1<<32),-1,42]:add('reject-long-magic',order_magic=magic)
    for symbol in [0,1,2]:add('full-symbol-comparison',symbol_mode=symbol)
    for first,second in [(4,0),(5,5),(0,5),(5,4),(0,0),(4+(1<<32),5)]:add('two-type-reads',first_type=first,second_type=second)
    for order in [-1,0,1,2]:
        for position in [-1,0,1,2]:add('inclusive-or-negative-total',orders=order,position=position)
    for mutation in [1,2,3,4,5]:
        for order in [1,2]:add('service-side-effects',mutation=mutation,orders=order,first_type=5 if order==2 else 4,second_type=5 if order==2 else 4,order_magic=44 if mutation==1 else 43)
    for c in rows[:8]:
        c=copy.deepcopy(c);c.update(friday=[1,20,255,1,1],tag='news-exit-preserves-friday');rows.append(c)
    for i,c in enumerate(rows):c['id']=i
    return rows
def encode(rows):
    return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(news.encode([c])[12:]+struct.pack('<12q',*c['friday'],*[c[n] for n in ['seed','order_magic','symbol_mode','first_type','second_type','mutation','after_seed']]) for c in rows)
class Original(news.Original):
    def __init__(self,bot):
        super().__init__(bot);self.friday=CFG[bot];self.nfp=dict(self.nfp,end=self.friday['end']);lo,hi,digest=self.friday['helper']
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==digest,'FRIDAY_HELPER_CHANGED')
    def state(self):
        raw=super().state()
        return raw+b''.join(struct.pack('<Q',self.value(a,'i' if i==1 else 'B')&MASK) for i,a in enumerate(self.friday['fields']))
    def visit(self,m,address,size,user):
        if address==self.base+self.nfp['start'] and not self.friday_seeded:
            self.friday_seeded=True
            for i,(a,v) in enumerate(zip(self.friday['fields'],self.case['friday'])):m.mem_write(self.base+a,struct.pack('<'+('i' if i==1 else 'B'),v))
            m.mem_write(self.base+self.nfp['seed'],struct.pack('<i',self.case['seed']))
        return super().visit(m,address,size,user)
    def call(self,m,address,size,user):
        api=self.sdk.get(address)
        if not api:return super().call(m,address,size,user)
        peek=base.Reader(self.tape.raw[self.tape.pos:]);peek.block();kind,*args=peek.take('i4Q');strings=[peek.text() for _ in range(4)]
        if api in [13,15]:
            rd=self.tape;require(rd.block()==self.state(),'FRIDAY_STATE_BEFORE_TOTAL');kind,*args=rd.take('i4Q');texts=[rd.text() for _ in range(4)];payload=rd.block();error,=rd.take('I');value=self.case['orders' if api==13 else 'position'];expected=value if value<0 else int(value!=0)
            require(kind==api and args==[expected&MASK,0,0,0] and texts==[None]*4 and payload==b'' and m.reg_read(self.x.UC_X86_REG_RCX)==self.nfp['ctx'],'FRIDAY_TOTAL_REPLY')
            m.reg_write(self.x.UC_X86_REG_RAX,expected&MASK);m.mem_write(self.base+self.nfp['error'],struct.pack('<I',error));self.api_count+=1
        else:super().call(m,address,size,user)
        mode=self.case['mutation'];x=self.nfp;f=self.friday['fields'];target=None;value=None;fmt='i'
        if mode==1 and api==13 and not self.mutated:target=x['seed'];value=self.case['after_seed']
        elif mode==2 and api==17 and args[0]==15 and not self.mutated:target=x['seed'];value=self.case['after_seed']
        elif mode==3 and api==10 and strings[0]=='deleting pending order':target=x['ticket'];value=999;fmt='Q'
        elif mode==4 and api==10 and strings[0]=='Weekend starting! closing trades..':target=f[2];value=2;fmt='B'
        elif mode==5 and api==15 and self.bot==3 and not self.mutated:target=f[3];value=0;fmt='B'
        if target is not None:m.mem_write(self.base+target,struct.pack('<'+fmt,value));self.mutated=True
    def run(self,c,tape):
        self.friday_seeded=False;self.mutated=False;return super().run(c,tape)
def identity(bot):
    h=ROOT/f'bot-cua-toi-{bot}';source=h/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NewsFridayCheck.mq5';helpers=dict(news.identity(bot)['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=base.validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256=helpers)
def execute(bot,folder,build):
    h=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';receipt=h/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NewsFridayCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,v in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==v,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/f'MQL5/Files/bot{bot}-news-friday'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('friday-'+folder.name+'.set');ini=mt/('friday-'+folder.name+'.ini');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}NewsFridayCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');rows=cases();folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','sdk-tape.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tape=base.Reader((folder/'sdk-tape.bin').read_bytes());require(tape.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Original(a.bot);raw=bytearray(header);calls=0
        for c in rows:
            require(tape.take('i')[0]==c['id'],'TAPE_CASE_ID');state=o.run(c,tape.block());raw+=struct.pack('<2i',c['id'],len(state))+state;calls+=o.api_count
        require(tape.pos==len(tape.raw),'TAPE_TRAILING')
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),sdk_calls=calls,parent_instructions=len(o.covered),**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=calls)));return
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')) and r['sdk_tape_sha256']==sha(folder/'sdk-tape.bin'),'RUN_CHANGED')
    data=[base.Reader((folder/(n+'-results.bin')).read_bytes()) for n in ['original','mql5']];require(all(r.take('3i')==(MAGIC,1,len(rows)) for r in data),'RESULT_HEADER');fail=[]
    for c in rows:
        states=[]
        for r in data:require(r.take('i')[0]==c['id'],'RESULT_ID');states.append(r.block())
        if states[0]!=states[1]:fail.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*states)) if x!=y),None),sizes=list(map(len,states))))
    require(all(r.pos==len(r.raw) for r in data),'RESULT_TRAILING');result=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:12],**SCOPE,limits=['News and first Friday action only; initial frame/state and terminal replies supplied. No complete evaluator, EA, live broker or allocation-fault proof.'])
    save(folder/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(fail))
if __name__=='__main__':main()
