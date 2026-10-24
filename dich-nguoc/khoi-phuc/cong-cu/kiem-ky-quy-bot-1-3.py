"""Compare guarded/direct margin checks, supplied terminal data, no orders sent.

python -I -B -X utf8 kiem-ky-quy-bot-1-3.py prepare|original|mql5|compare BOT RUN
Compare return bool and ordered account/tick/margin call arguments. Message text
excluded; runtime division faults map to false. Tick bytes supplied even on failed read.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import random
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
entry=module('entry_check','kiem-gia-vao-bot-1-3.py');currency=module('currency_check','kiem-doi-tien-bot-1-3.py')
MT=entry.MT
MAGIC=0x4d524731
ENUMS=[36,40,42,0,1]
CONFIG={1:dict(guard=0x3cb30,direct=0x457d0,error=0x6a410),3:dict(guard=0x47840,direct=0x53670,error=0x1d6e10)}
def base_case():return dict(guard=1,type=0,volume=0.01,currency='USD',symbol='XAUUSD',bid=2600.,ask=2600.5,
    equity=10000.,free=9000.,required=100.,tick_ok=1,calc_ok=1)
def cases():
    out=[];rng=random.Random(2026102307)
    def add(tag,**changes):c=base_case();c.update(changes);c['tag']=tag;out.append(c)
    for _ in range(500):
        c=base_case();c.update(guard=rng.randrange(2),type=rng.randrange(10),volume=rng.choice([-1.,0.,0.001,0.01,0.1,1.]),
            currency=rng.choice(['USD','BTC','btc','ETH','eth','Btc','VND','']),symbol=rng.choice(['XAUUSD','Vàng','', 'EURUSD.a']),
            equity=rng.uniform(-1.,10000.),free=rng.uniform(-1.,10000.),required=rng.uniform(-1.,10000.),
            tick_ok=rng.randrange(2),calc_ok=rng.randrange(2),tag='mixed');out.append(c)
    for name in ['USD','BTC','btc','ETH','eth','Btc','Eth','VND','']:
        for volume in [-1.,-0.,0.,0.01,1.]:
            for equity in [69.999999,70.,70.000001]:
                for free in [69.999999,70.,70.000001]:add('funds-boundary',currency=name,volume=volume,equity=equity,free=free,required=0.)
    for guard in [0,1]:
        for kind in range(10):
            for required in [8999.999999,9000.,9000.000001,0.,-1.]:
                for ok in [0,1]:add('margin-boundary',guard=guard,type=kind,required=required,calc_ok=ok)
    for guard in [0,1]:
        for field in ['volume','required','free','equity','bid','ask']:
            for value in [float('nan'),float('inf'),-float('inf')]:add('non-finite',guard=guard,**{field:value})
    for i,c in enumerate(out):c['id']=i
    return out
def encode(values):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(values)))
    for c in values:
        raw+=struct.pack('<5i6d',c['id'],c['guard'],c['type'],c['tick_ok'],c['calc_ok'],*(c[n] for n in ['volume','bid','ask','equity','free','required']))
        raw+=currency.pack_text(c['currency'])+currency.pack_text(c['symbol'])
    return raw
class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.margin_cfg=CONFIG[bot]
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        for n in ['guard','direct']:
            if self.margin_cfg[n] not in {int(f['begin_rva'],16) for f in meta['functions']}:raise ValueError('UNVERIFIED_FUNCTION '+n)
        eb=next(a for a,api in self.apis.items() if api==1)-0x7d3c40
        extra={eb+0x797410:10,eb+0x797370:11,eb+0x7c2c10:12,eb+0x7d8d40:13,eb+0x7b49f0:14,eb+0x3959a0:200}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for addr in extra:self.m.mem_write(addr,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
    def mix(self,words):
        self.count+=1
        if len(self.prefix)<80:self.prefix.append(words)
        for word in words:
            for byte in struct.pack('<Q',word&entry.MASK):self.hash=((self.hash^byte)*0x100000001b3)&entry.MASK
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;c=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        if api==10:
            prop=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
            if prop!=36:raise ValueError('ACCOUNT_STRING_PROPERTY')
            m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(c['currency'])))
            self.mix([10,prop,entry.text_hash(c['currency'])])
        elif api==11:
            prop=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
            if prop not in [40,42]:raise ValueError('ACCOUNT_DOUBLE_PROPERTY')
            value=c['equity' if prop==40 else 'free'];raw=struct.pack('<d',value);m.mem_write(self.base+self.cfg['slot'],raw)
            m.reg_write(x.UC_X86_REG_XMM0,entry.bits(value));self.mix([11,prop,entry.bits(value)])
        elif api==12:
            symbol=currency.Original.read_text(self,m.reg_read(x.UC_X86_REG_RDX));ptr=m.reg_read(x.UC_X86_REG_R8)
            m.mem_write(ptr,struct.pack('<q2d',0,c['bid'],c['ask']));m.reg_write(x.UC_X86_REG_RAX,c['tick_ok'])
            self.mix([12,entry.text_hash(symbol),entry.bits(c['bid']),entry.bits(c['ask']),c['tick_ok']])
        elif api==13:
            kind=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;symbol=currency.Original.read_text(self,m.reg_read(x.UC_X86_REG_R8))
            amount=m.reg_read(x.UC_X86_REG_XMM3)&entry.MASK;rsp=m.reg_read(x.UC_X86_REG_RSP)
            price=struct.unpack('<Q',m.mem_read(rsp+0x28,8))[0];ptr=struct.unpack('<Q',m.mem_read(rsp+0x30,8))[0]
            m.mem_write(ptr,struct.pack('<d',c['required']));m.reg_write(x.UC_X86_REG_RAX,c['calc_ok'])
            self.mix([13,kind,entry.text_hash(symbol),amount,price,c['calc_ok'],entry.bits(c['required'])])
        elif api==14:self.messages+=1
        elif api==200:self.error=m.reg_read(x.UC_X86_REG_RDX);m.emu_stop()
        else:raise ValueError('UNEXPECTED_API '+str(api))
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.cursor=0x70001000;self.allocs=self.frees=0;self.count=self.messages=0;self.error=0;self.hash=0xcbf29ce484222325;self.prefix=[]
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        desc=0x70000000;m.mem_write(desc,struct.pack('<IQ',0,self.string(c['symbol'])))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_RCX,desc)
        if c['guard']:m.reg_write(x.UC_X86_REG_RDX,c['type']);m.reg_write(x.UC_X86_REG_XMM2,entry.bits(c['volume']))
        else:m.reg_write(x.UC_X86_REG_XMM1,entry.bits(c['volume']));m.reg_write(x.UC_X86_REG_R8,c['type'])
        m.emu_start(self.base+self.margin_cfg['guard' if c['guard'] else 'direct'],0x60000000,timeout=5000000,count=2000000)
        if not self.error and m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise RuntimeError('NATIVE_DID_NOT_RETURN')
        if not self.error and self.allocs!=self.frees:raise RuntimeError('STRING_ALLOCATION_IMBALANCE')
        return [c['id'],0 if self.error else int(bool(m.reg_read(x.UC_X86_REG_RAX)&0xff)),self.count,self.hash,self.messages]
def header(count):return struct.pack('<3i5i',MAGIC,1,count,*ENUMS)
def read_cases(out):
    values=json.loads((out/'cases.json').read_text())
    if encode(values)!=(out/'cases.bin').read_bytes():raise ValueError('CASE_DATA_MISMATCH')
    return values
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-ky-quy'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);values=cases();(out/'cases.json').write_text(json.dumps(values,ensure_ascii=False),encoding='utf-8');(out/'cases.bin').write_bytes(encode(values));print(json.dumps({'cases':len(values)}));return
    if a.mode=='original':
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        o=Original(a.bot);start=time.monotonic();rows=[];errors=[];traces=[]
        for c in read_cases(out):
            rows.append(o.run(c));traces.append({'id':c['id'],'trace':o.prefix})
            if o.error:errors.append({'id':c['id'],'error':hex(o.error)})
        target.write_bytes(header(len(rows))+b''.join(struct.pack('<3iQI',*r) for r in rows));(out/'native-traces.json').write_text(json.dumps(traces),encoding='utf-8')
        (out/'original-run.json').write_text(json.dumps({'cases':len(rows),'runtime_errors':errors,'seconds':round(time.monotonic()-start,2),'tool_sha256':entry.sha(Path(__file__)),'result_sha256':entry.sha(target),'scope':__doc__},indent=2),encoding='utf-8');print(json.dumps({'cases':len(rows),'runtime_errors':len(errors),'seconds':round(time.monotonic()-start,2)}));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        files=MT/f'MQL5/Files/bot{a.bot}-margin'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        params=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set';params.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-margin.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}MarginCheck\nScriptParameters={params.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0:raise RuntimeError('MQL5_CHECK_EXIT '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target);script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}MarginCheck.ex5'
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),'script_sha256':entry.sha(script),'results_sha256':entry.sha(target)},indent=2),encoding='utf-8');print('MQL5 results saved');return
    values=read_cases(out);e=(out/'original-results.bin').read_bytes();v=(out/'mql5-results.bin').read_bytes()
    if e[:32]!=header(len(values)) or v[:32]!=e[:32] or len(e)!=32+24*len(values) or len(v)!=len(e):raise ValueError('RESULT_SHAPE_MISMATCH')
    failures=[];groups={}
    for i,c in enumerate(values):
        x=struct.unpack_from('<3iQI',e,32+i*24);y=struct.unpack_from('<3iQI',v,32+i*24);g=groups.setdefault(c['tag'],{'cases':0,'matched':0});g['cases']+=1;g['matched']+=int(x==y)
        if x!=y:failures.append({'id':i,'tag':c['tag'],'original':x,'mql5':y})
    record={'cases':len(values),'matched':len(values)-len(failures),'failed':len(failures),'passed':not failures,'groups':groups,'first_failures':failures[:25],'hashes':{p:entry.sha(out/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']},'scope':__doc__}
    (out/'comparison.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));raise SystemExit(bool(failures))
if __name__=='__main__':main()
