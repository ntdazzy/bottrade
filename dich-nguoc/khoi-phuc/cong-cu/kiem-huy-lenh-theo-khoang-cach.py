"""Compare both original buy/sell pending distance scans through real delete/send.

prepare|original|mql5(--build)|compare BOT RUN. No real order, no child result stubs.
"""
import argparse,copy,hashlib,importlib.util,json,math,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x44434131;MASK=(1<<64)-1
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
pub=module('distance_pub',ROOT/'cong-cu/kiem-ban-git-quan-ly.py');require=pub.require
PARTS={b:module('distance_pending_'+str(b),ROOT/f'bot-cua-toi-{b}/tests/check-evaluation-pending-resize.py') for b in [1,3]}
CFG={1:dict(buy=0x2f5c0,buy_end=0x2f7dd,buy_sha='01d72da0e079969614793876b5980284cb253defde41f75f9811e4b3372f0268',sell=0x2f7e0,sell_end=0x2f9fd,sell_sha='b8b370d5defab96f03e578f0a34b3016a16d86ee934c709621ff4e63bdaa767b',quote_buy=0x67760,quote_sell=0x67758,gap=0x67468,last=0x677f8,magic=0x6246c),
 3:dict(buy=0x3ca00,buy_end=0x3cc1d,buy_sha='2ca1558cfb8ab905c4c570da4c7f3f63a5f9d68a1e1c5edef85a62f969d95677',sell=0x3cc20,sell_end=0x3ce3d,sell_sha='94661a0c5afa9b3973e86b1b28552ba724f6eabe9a8bedd08437002927943646',quote_buy=0x747a0,quote_sell=0x74798,gap=0x744a8,last=0x74838,magic=0x6d564)}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_distance_scan_and_delete_send_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(p,value):
    with p.open('x',encoding='utf-8',newline='\n') as f:json.dump(value,f,ensure_ascii=False,indent=2)
def bits(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def cases(bot):
    p=PARTS[bot];out=[]
    def add(c,buy,tag,enabled=1,quote=100.,gap=1.,mutation=0):
        c=copy.deepcopy(c);c.update(id=len(out),buy=buy,distance_enabled=enabled,quote=bits(quote),gap=bits(gap),distance_mutation=mutation,tag=tag,resize_mutation=0)
        c['prelude']['id']=c['id'];out.append(c);return c
    for buy in [0,1]:
        for c in p.cases():add(c,buy,'inherited-'+c['tag'])
        base=p.cases()[0]
        for enabled in [-2147483648,-1,0,1,2,255]:
            for total in [-2,-1,0,1,2,3]:
                c=add(base,buy,'exact-enable-inclusive-total',enabled=enabled);c['order_total']=total
        for value in [99.,100.,101.,math.nextafter(101.,-math.inf),math.nextafter(101.,math.inf),-0.,0.,math.nan,math.inf,-math.inf]:
            for field in ['quote','gap','price']:
                c=add(base,buy,'comparison-boundary');c['orders'][0]['type']=4 if buy else 5;c['orders'][0]['select_ok']=0
                if field=='price':c['orders'][0]['price']=bits(value)
                else:c[field]=bits(value)
        for mutation in range(1,6):
            c=add(base,buy,'fresh-state-after-api',mutation=mutation);c.update(order_total=2)
            c['orders']=[copy.deepcopy(base['orders'][0]),copy.deepcopy(base['orders'][0])]
            for i,o in enumerate(c['orders']):o.update(ticket=i+11,type=4 if buy else 5,price=bits(110. if buy else 90.),select_ok=0)
    return out
def encode(rows,bot):
    p=PARTS[bot];return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(p.encode([c])[12:]+struct.pack('<2i2Qi',c['distance_enabled'],c['buy'],c['quote'],c['gap'],c['distance_mutation']) for c in rows)
def original_class(bot):
    p=PARTS[bot];cfg=CFG[bot]
    class Original(p.Original):
        def __init__(self):
            super().__init__({})
            for direction in ['buy','sell']:
                lo,hi=cfg[direction],cfg[direction+'_end'];require(hashlib.sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==cfg[direction+'_sha'],'DISTANCE_SCAN_BYTES_CHANGED');self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+lo,end=self.base+hi-1)
        def mutate_distance(self,api,prop):
            if self.distance_changed:return
            mode=self.row['distance_mutation'];m=self.m;quote=cfg['quote_buy' if self.row['buy'] else 'quote_sell']
            if api==507 and prop==9:
                if mode==1:m.mem_write(self.base+quote,struct.pack('<d',1000. if self.row['buy'] else -1000.))
                elif mode==2:m.mem_write(self.base+cfg['gap'],struct.pack('<d',100.))
                elif mode==5:m.mem_write(self.base+cfg['last'],struct.pack('<Q',777))
                else:return
            elif api==503 and prop==15 and mode==3:m.mem_write(self.base+cfg['magic'],struct.pack('<i',self.row['magic']+1))
            elif api==504 and prop==0 and mode==4:
                m.mem_write(self.base+self.cfg['symbol'],struct.pack('<IQ',0,self.string('Đổi mã')));self.live_symbol='Đổi mã'
            else:return
            self.distance_changed=True
        def call(self,m,address,size,user):
            api=self.apis[address];prop=m.reg_read(self.x.UC_X86_REG_RDX)&0xffffffff
            super().call(m,address,size,user)
            if self.phase=='loop':self.mutate_distance(api,prop)
        def run_distance(self,c):
            self.row=copy.deepcopy(c);self.case=self.row['prelude'];self.changed=False;self.phase='idle'
            self.current_index=c['index'];self.live_symbol=c['symbol'];self.resize_changed=False;self.distance_changed=False;self.extra=bytearray();m,x=self.m,self.x;self.cursor=0x70001000;self.allocs=self.frees=0;self.selected=-1
            for region,raw in self.regions:
                if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
            for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
            for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
            self.seed();m.mem_write(self.base+(0x6a3b4 if bot==1 else 0x1d6d08),b'\0')
            for off,val in [(self.cfg['symbol'],c['symbol'])]:m.mem_write(self.base+off,struct.pack('<IQ',0,0 if val is None else self.string(val)))
            m.mem_write(self.base+cfg['quote_buy' if c['buy'] else 'quote_sell'],struct.pack('<Q',c['quote']));m.mem_write(self.base+cfg['gap'],struct.pack('<Q',c['gap']));m.mem_write(self.base+cfg['last'],struct.pack('<Q',0x1122334455667788))
            top=0x5001fef8;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_RCX,c['distance_enabled']&0xffffffff);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
            self.phase='loop';m.emu_start(self.base+cfg['buy' if c['buy'] else 'sell'],0x60000000,timeout=5000000,count=1000000);require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'DISTANCE_SCAN_NO_RETURN')
            raw=struct.pack('<i',c['id'])+bytes(self.extra)+struct.pack('<i',0)+self.snapshot()+struct.pack('<2Q',self.selected_order&MASK,struct.unpack('<Q',m.mem_read(self.base+cfg['last'],8))[0])
            for rva,kind in [(cfg['quote_buy' if c['buy'] else 'quote_sell'],'Q'),(cfg['gap'],'Q'),(cfg['magic'],'i')]:raw+=struct.pack('<Q',struct.unpack('<'+kind,m.mem_read(self.base+rva,struct.calcsize('<'+kind)))[0]&MASK)
            raw+=p.text(self.read_text(self.base+self.cfg['symbol']));return raw
    return Original
def identity(bot):
    p=PARTS[bot];home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}PendingDistanceCancelCheck.mq5';helpers=dict(p.identity()['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=p.p.head.validation.original_hash(bot),sources_sha256={f.relative_to(source).as_posix():sha(f) for f in pub.closure(source/script,source)},helpers_sha256=helpers)
def execute(bot,folder,build):
    home=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}PendingDistanceCancelCheck.mq5';receipt=home/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,h in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');run=folder.name;files=mt/f'MQL5/Files/bot{bot}-pending-distance'/run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    ini=mt/('distance-'+run+'.ini');preset=mt/'MQL5/Presets'/('distance-'+run+'.set');preset.write_text('CheckRun='+run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}PendingDistanceCancelCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');rows=cases(a.bot);folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows,a.bot));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==n for k,n in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows,a.bot),'IDENTITY_CHANGED')
    if a.mode=='original':
        o=original_class(a.bot)();raw=header+b''.join(o.run_distance(c) for c in rows)
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),instructions=len(o.resize_covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(o.resize_covered))));return
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAULT')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(folder/'mql5-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    raw=[(folder/(n+'-results.bin')).read_bytes() for n in ['original','mql5']]
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==n for k,n in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')),'RUN_CHANGED')
    require(all(b[:12]==header for b in raw),'RESULT_HEADER');same=raw[0]==raw[1];report=dict(cases=len(rows),matched=len(rows) if same else 0,failed=0 if same else len(rows),first_different_byte=next((i for i,(x,y) in enumerate(zip(*raw)) if x!=y),None),bytes=list(map(len,raw)),**SCOPE,limits=['Native buy/sell scan through full original delete/send bodies, log_level=0. Terminal replies and successful allocation supplied. No complete NFP evaluator, actual broker order or allocation-failure proof.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(not same)
if __name__=='__main__':main()
