"""Compare original comment/magic/currency fragments with compiled MQL5.

prepare|original|mql5(--build)|compare BOT RUN. Native string and currency
bodies run unchanged; caller registers and successful allocation/SDK replies
are supplied. Stops before preparation; not a complete dispatcher or EA.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1;MAGIC=0x53435431
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
currency=module('strategy_currency',ROOT/'cong-cu/kiem-doi-tien-bot-1-3.py')
pub=module('strategy_publication',ROOT/'cong-cu/kiem-ban-git-quan-ly.py')
validation=module('strategy_identity',ROOT/'bot-cua-toi-1/tests/check-management-prelude.py').validation
require=pub.require
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(p,value):
    with p.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2)
CONFIG={
 1:dict(lo=0x10f60,hi=0x173e4,digest='f5edd0f5e9033ddddb289a3419406c06292ce22bff197bea6d10acea1756c721',
        starts=[0x12aec,0x136b5,0x13ecb,0x145da,0x14cdc,0x15607,0x15cea,0x1652c],
        stops=[0x12f49,0x1385d,0x1407e,0x14782,0x14ea3,0x157af,0x15e8f,0x166d1],
        keep=0x6a628,prefix=0x6a618,base_magic=0x6a610,comment=0x62470,value=0x69f70,magic=0x6246c,
        prior_cmp={2:0x13ec5,4:0x14cd6,6:0x15ce4,7:0x16526}),
 3:dict(lo=0x17f00,hi=0x1fcf9,digest='ad9ba21d686c6f054138072d755e4851473ddc903acc6f1fc3bf7fe0cad1f714',
        starts=[0x1ae06,0x1bf4f,0x1c7e9,0x1b6af,0x1d8e5,0x1d071,0x1ea03,0x1f28e,0x1e160],
        stops=[0x1affc,0x1c143,0x1c9e7,0x1b8ad,0x1dadc,0x1d268,0x1ebfd,0x1f492,0x1e35a],
        keep=0x1d7008,prefix=0x1d6ff8,base_magic=0x1d6ff0,comment=0x6d568,value=0x76fa0,magic=0x6d564,
        prior_cmp={4:0x1d8dd,5:0x1d069})}
NAMES=['magic','converted_value_bits','reference_bits','account_reads','price_reads','price_hash','service_order_hash']
RECORD=struct.Struct('<2i'+'Q'*len(NAMES))
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
 original_context_fragments_executed=True,original_conversion_and_string_bodies_executed=True,
 caller_registers_supplied=True,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Valid strategy indices, supplied caller registers/stack and successful allocation; not every path from the beginning of the dispatcher.',
 'Original comment construction, 32-bit magic and currency bodies execute through cleanup before preparation. UTF-16 comments are compared in full.',
 'Whole EA, settings/UI, restart, broker behavior and allocation failures remain unverified. Error cohort proves fatal class/no normal result only.']
def cases(bot):
    out=[]
    def add(index,**changes):
        c=dict(id=len(out),index=index,keep=0,alternate=0,base_magic=9000,reference=1234.25+index,
          prefix='EA',prior_comment='GIỮ 🚀',currency='USD',account_sequence=[],suffix='',prices=[2.,3.,4.,5.],tag='structure');c.update(changes);out.append(c)
    for index in range(len(CONFIG[bot]['starts'])):
        for prefix in ['','EA','Vàng 🚀','z'*300]:
            for keep in [0,1,255]:
                for alternate in ([0] if bot==1 else [0,1,255]):
                    add(index,prefix=prefix,keep=keep,alternate=alternate,base_magic=[-2147483648,0,2147483647][[0,1,255].index(keep)])
        for code in currency.CURRENCIES:
            for alternate in ([0] if bot==1 else [0,255]):
                add(index,currency=code,alternate=alternate,suffix='.a' if len(out)%2 else 'đuôi',tag='currency-route')
        for code in ['EUR','JPY','CHF','CZK']:
            for prices in [[0.,3.,4.,5.],[-1.,3.,4.,5.],[float('nan'),3.,4.,5.],
                           [2.,float('nan'),4.,5.],[2.,float('inf'),4.,5.]]:
                for alternate in ([0] if bot==1 else [0,1]):add(index,currency=code,prices=prices,alternate=alternate,tag='price-boundary')
        for sequence in [['USD','EUR']+['ZZZ']*110,['ZZZ']*12+['CHF','CHF']+['ZZZ']*100]:
            for alternate in ([0] if bot==1 else [0,1]):add(index,account_sequence=sequence,alternate=alternate,tag='changing-account-replies')
    return out
def error_cases(bot):
    rows=cases(bot)[:1];base=dict(rows[0],currency='EUR',prices=[2.,0.,2.,3.],tag='first-conversion-fatal')
    out=[base,dict(base,id=1,index=len(CONFIG[bot]['starts'])-1,keep=255)]
    if bot==3:out.append(dict(base,id=2,alternate=1,prices=[2.,3.,2.,0.],tag='second-conversion-fatal'))
    return out
def text_bytes(s):return currency.pack_text(s)
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,2,len(rows)))
    for c in rows:
        raw+=struct.pack('<5i5d',*[c[n] for n in ['id','index','keep','alternate','base_magic']],c['reference'],*c['prices'])
        for n in ['prefix','prior_comment','currency','suffix']:raw+=text_bytes(c[n])
        raw+=struct.pack('<i',len(c['account_sequence']))
        for value in c['account_sequence']:raw+=text_bytes(value)
    return raw
def event(h,kind):
    for byte in struct.pack('<Q',kind):h=((h^byte)*0x100000001b3)&MASK
    return h
class Original(currency.Original):
    def __init__(self,bot):
        super().__init__(bot);self.context_cfg=CONFIG[bot];c=self.context_cfg
        require(sha_native(self,c['lo'],c['hi'])==c['digest'],'DISPATCHER_BYTES_CHANGED')
        self.covered=set();self.stop=0;self.stopped=False
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+c['lo'],end=self.base+c['hi'])
    def visit(self,m,address,size,user):
        if address==self.stop:self.stopped=True;m.emu_stop();return
        self.covered.add(address-self.base)
    def call(self,m,address,size,user):
        kind=self.apis[address]
        if kind in [10,11]:self.service_hash=event(self.service_hash,kind)
        if kind==10:
            sequence=self.case['account_sequence'];n=self.account_reads
            value=sequence[n] if n<len(sequence) else self.case['currency']
            require(m.reg_read(self.x.UC_X86_REG_RDX)==36,'ACCOUNT_PROPERTY_DIFFERS')
            m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(value)))
            self.account_reads+=1;self.service_hash=event(self.service_hash,currency.entry_check.text_hash(value));return
        return super().call(m,address,size,user)
    def run(self,c):
        self.reset(dict(c,amount=0.,to_usd=0));m,x=self.m,self.x;k=self.context_cfg
        self.service_hash=0xcbf29ce484222325;self.stopped=False;self.stop=self.base+k['stops'][c['index']]
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        top=0x50020000-0x100;m.reg_write(x.UC_X86_REG_RSP,top);m.mem_write(top,bytes(0x80))
        m.mem_write(self.base+k['keep'],bytes([c['keep']]));m.mem_write(self.base+k['base_magic'],struct.pack('<i',c['base_magic']))
        for key,value in [('prefix',c['prefix']),('comment',c['prior_comment'])]:m.mem_write(self.base+k[key],struct.pack('<IQ',0,self.string(value)))
        m.mem_write(self.base+k['value'],struct.pack('<d',-987.5));m.reg_write(x.UC_X86_REG_RCX,self.base+k['keep'])
        if self.bot==1:
            m.reg_write(x.UC_X86_REG_RBP,self.base+0x5c0);m.reg_write(x.UC_X86_REG_RBX,self.base+0x47d20);m.reg_write(x.UC_X86_REG_R12,self.base+0x69f70)
        else:
            m.reg_write(x.UC_X86_REG_R12,self.base+0x5c0);m.mem_write(self.base+0x1d6f28,bytes([c['alternate']]))
            m.mem_write(self.base+0x6d1b8,struct.pack('<d',c['reference']))
        if c['index'] in k['prior_cmp']:
            addr=self.base+k['prior_cmp'][c['index']]
            require(bytes(m.mem_read(addr,3))==b'\x80\x39\x00','PRIOR_COMPARE_DIFFERS')
            m.emu_start(addr,addr+3,count=1)
        m.emu_start(self.base+k['starts'][c['index']],0x60000000,timeout=5000000,count=2000000)
        require(self.stopped or self.error,'CONTEXT_DID_NOT_STOP')
        if self.error:require(self.error&0xffffffff==0x1f7,'UNEXPECTED_NATIVE_ERROR')
        magic=struct.unpack('<i',m.mem_read(self.base+k['magic'],4))[0]&MASK
        value=struct.unpack('<Q',m.mem_read(self.base+k['value'],8))[0]
        reference=struct.unpack('<Q',m.mem_read(self.base+0x6d1b8,8))[0] if self.bot==3 else currency.bits(c['reference'])
        words=[magic,value,reference,self.account_reads,len(self.price_calls),self.price_hash,self.service_hash]
        text=self.read_text(self.base+k['comment'])
        return RECORD.pack(c['id'],int(not self.error),*words)+text_bytes(text)
def sha_native(o,lo,hi):return hashlib.sha256(bytes(o.m.mem_read(o.base+lo,hi-lo))).hexdigest()
def identity(bot):
    home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyContextCheck.mq5'
    helpers=[Path(__file__),ROOT/'cong-cu/kiem-doi-tien-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',
      ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py',
      ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'bot-cua-toi-1/tests/check-management-prelude.py']
    return dict(original_ex5_sha256=validation.original_hash(bot),tool_sha256=sha(Path(__file__)),
      sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},
      helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def parse(raw,count):
    require(raw[:16]==struct.pack('<4i',MAGIC,2,count,len(NAMES)),'RESULT_HEADER');out=[];at=16
    for _ in range(count):
        words=list(RECORD.unpack_from(raw,at));at+=RECORD.size;n=struct.unpack_from('<i',raw,at)[0];at+=4
        require(0<=n<=10000,'BAD_COMMENT_LENGTH');text=raw[at:at+n*2].decode('utf-16-le');at+=n*2;out.append(words+[text])
    require(at==len(raw),'RESULT_SIZE');return out
def run_mt(bot,home,run,build,current,only_case=-1):
    mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyContextCheck.mq5'
    receipt=home/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'))
    require(b['target']==script and b['errors']==b['warnings']==0 and b['floating_point_dividers_check_requested'],'BUILD_NOT_CLEAN')
    for n,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==digest,'BUILD_SOURCE_DIFFERS '+n)
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
    files=mt/f'MQL5/Files/bot{bot}-strategy-context'/run;files.mkdir(parents=True,exist_ok=False)
    folder=home/'bang-chung/kiem-quan-ly-vi-the'/run;shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/f'b{bot}-context-{run}.set';ini=mt/f'b{bot}-context-{run}.ini'
    with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+run+'\nOnlyCase='+str(only_case)+'\n')
    with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-'+str(bot)+'\\Bot'+str(bot)+'StrategyContextCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
    proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=proc.wait(timeout=120)
    except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    return code,files,receipt
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,40}',a.run),'BAD_RUN');home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run
    rows=cases(a.bot);current=identity(a.bot);header=struct.pack('<4i',MAGIC,2,len(rows),len(NAMES))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and encode(rows)==(folder/'cases.bin').read_bytes(),'IDENTITY_CHANGED')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');o=Original(a.bot);raw=bytearray(header);traces=[]
        for c in rows:
            raw+=o.run(c);require(not o.error,'UNEXPECTED_FATAL_CASE');traces.append(dict(id=c['id'],prices=o.price_calls,account_reads=o.account_reads))
        (folder/'original-results.bin').write_bytes(raw);save(folder/'native-traces.json',traces)
        cfg=CONFIG[a.bot];save(folder/'native-context.json',dict(dispatcher_sha256=cfg['digest'],instructions=sorted(hex(i) for i in o.covered),
          fragments=[dict(index=i,start=hex(lo),stop=hex(hi)) for i,(lo,hi) in enumerate(zip(cfg['starts'],cfg['stops']))],**SCOPE))
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(o.covered))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');require(not(folder/'mql5-results.bin').exists(),'RESULT_EXISTS')
        code,files,receipt=run_mt(a.bot,home,a.run,a.build,current)
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for name in ['original-run.json','mql5-run.json']:
        r=json.loads((folder/name).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/name.replace('-run.json','-results.bin')),'RUN_CHANGED')
    native=parse((folder/'original-results.bin').read_bytes(),len(rows));actual=parse((folder/'mql5-results.bin').read_bytes(),len(rows));failed=[]
    for c,n,r in zip(rows,native,actual):
        if n!=r:failed.append(dict(id=c['id'],tag=c['tag'],differences={k:[x,y] for k,x,y in zip(['id','returned']+NAMES+['comment'],n,r) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:20],**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report,ensure_ascii=False));raise SystemExit(bool(failed))
if __name__=='__main__':main()
