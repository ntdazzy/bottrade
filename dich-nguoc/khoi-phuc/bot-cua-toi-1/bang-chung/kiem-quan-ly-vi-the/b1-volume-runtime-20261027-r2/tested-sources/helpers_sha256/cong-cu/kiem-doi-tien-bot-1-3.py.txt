"""Verify both currency-conversion functions against captured native code.

Only account currency, successful string allocation and iClose reads are supplied.
Compare result bits and the exact sequence of price symbols/timeframes/shifts/values.
"""
import argparse
import hashlib
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
MT=ROOT.parent/'.local/claude-recovery-20261023/mt5'
MASK=(1<<64)-1
MAGIC=0x43555231
spec=importlib.util.spec_from_file_location('entry_check',Path(__file__).with_name('kiem-gia-vao-bot-1-3.py'))
entry_check=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry_check)
CONFIG={1:dict(to_usd=0x36220,from_usd=0x47d20,suffix=0x62208),
        3:dict(to_usd=0x8300,from_usd=0x41780,suffix=0x6d230)}
CURRENCIES=['USD','usd','EUR','eur','GBP','gbp','AUD','aud','JPY','jpy','YEN','yen','CHF','chf','HKD','hkd',
 'RUB','rub','SGD','sgd','BTC','btc','ETH','eth','BCH','bch','BCC','bcc','XRP','xrp','LTC','ltc','XMR','xmr',
 'DSH','dsh','EOS','eos','TRX','trx','ADA','ada','BSV','bsv','XLM','xlm','GLD','gld','ZEC','zec','XEM','xem',
 'CZK','czk','CNH','cnh','CNY','cny','VND','Eur','']
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def pack_text(value):
    raw=value.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def cases():
    out=[];rng=random.Random(2026102305)
    for to_usd in [0,1]:
        for currency in CURRENCIES:
            for suffix in ['','.a']:
                for prices in [[2.,2.,2.,2.],[0.,2.,2.,2.],[-1.,2.,2.,2.],[2.,0.,2.,2.],[0.,0.,2.,2.]]:
                    out.append(dict(to_usd=to_usd,currency=currency,suffix=suffix,amount=9.5,prices=prices,tag='currency-route'))
        for amount in [-10000.5,-1.5,-0.5,-0.1,-0.,0.,0.1,0.5,1.5,10000.5,1e19]:
            for currency in ['USD','EUR','JPY','XEM','CNH']:
                out.append(dict(to_usd=to_usd,currency=currency,suffix='đuôi',amount=amount,prices=[1.,1.,1.,1.],tag='rounding'))
        for _ in range(100):
            out.append(dict(to_usd=to_usd,currency=rng.choice(CURRENCIES),suffix=rng.choice(['','m','.pro','đuôi']),
                amount=rng.uniform(-10000.,10000.),prices=[rng.uniform(0.001,30000.) for _ in range(4)],tag='mixed'))
    for i,c in enumerate(out):c['id']=i
    return out
def encode(values):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(values)))
    for c in values:raw+=struct.pack('<2id4d',c['id'],c['to_usd'],c['amount'],*c['prices'])+pack_text(c['currency'])+pack_text(c['suffix'])
    return raw

class Original(entry_check.Original):
    def __init__(self,bot):
        super().__init__(bot);self.currency_cfg=CONFIG[bot]
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        if any(self.currency_cfg[n] not in {int(f['begin_rva'],16) for f in meta['functions']} for n in ['to_usd','from_usd']):raise ValueError('UNVERIFIED_FUNCTION')
        eb=next(a for a,api in self.apis.items() if api==1)-0x7d3c40
        extra={eb+0x797410:10,eb+0x7d3d40:11,eb+0x3959a0:200}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for addr in extra:self.m.mem_write(addr,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
    def read_text(self,descriptor):
        ptr=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if not ptr:return ''
        length=struct.unpack('<I',self.m.mem_read(ptr-4,4))[0]
        if length>10000:raise ValueError('INVALID_STRING_LENGTH')
        return bytes(self.m.mem_read(ptr,length*2)).decode('utf-16-le')
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api in [100,101]:return super().call(m,address,size,user)
        if api==10:
            if m.reg_read(x.UC_X86_REG_RDX)!=36:raise ValueError('UNEXPECTED_ACCOUNT_STRING')
            m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(self.case['currency'])))
            self.account_reads+=1
        elif api==11:
            symbol=self.read_text(m.reg_read(x.UC_X86_REG_RDX));tf=m.reg_read(x.UC_X86_REG_R8)&0xffffffff;shift=m.reg_read(x.UC_X86_REG_R9)&0xffffffff
            n=len(self.price_calls)
            if n>=4:raise ValueError('TOO_MANY_PRICE_READS')
            value=self.case['prices'][n];self.price_calls.append([symbol,tf,shift,bits(value)])
            for word in [entry_check.text_hash(symbol),tf,shift,bits(value)]:
                for byte in struct.pack('<Q',word):self.price_hash=((self.price_hash^byte)*0x100000001b3)&MASK
            raw=struct.pack('<d',value);m.mem_write(self.base+self.cfg['slot'],raw);m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'))
        elif api==200:self.error=m.reg_read(x.UC_X86_REG_RDX);m.emu_stop()
        else:raise ValueError('UNEXPECTED_API '+str(api))
    def reset(self,c):
        m,x=self.m,self.x;self.case=c;self.cursor=0x70001000;self.allocs=self.frees=0;self.error=0
        self.price_calls=[];self.price_hash=0xcbf29ce484222325;self.account_reads=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.mem_write(self.base+self.currency_cfg['suffix'],struct.pack('<IQ',0,self.string(c['suffix'])))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.reg_write(x.UC_X86_REG_XMM0,bits(c['amount']))
    def run(self,c):
        self.reset(c);m,x=self.m,self.x
        m.emu_start(self.base+self.currency_cfg['to_usd' if c['to_usd'] else 'from_usd'],0x60000000,timeout=5000000,count=2000000)
        if not self.error and m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise RuntimeError('NATIVE_DID_NOT_RETURN')
        if self.error and (self.error&0xffffffff)!=0x1f7:raise RuntimeError('NATIVE_NON_DIVISION_ERROR '+hex(self.error))
        if not self.error and self.allocs!=self.frees:raise RuntimeError('STRING_ALLOCATION_IMBALANCE')
        return [c['id'],int(not self.error),0 if self.error else m.reg_read(x.UC_X86_REG_XMM0)&MASK,len(self.price_calls),self.price_hash]

def read_cases(out):
    values=json.loads((out/'cases.json').read_text())
    if encode(values)!=(out/'cases.bin').read_bytes():raise ValueError('CASE_DATA_MISMATCH')
    return values
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-doi-tien'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);values=cases();(out/'cases.json').write_text(json.dumps(values,ensure_ascii=False),encoding='utf-8');(out/'cases.bin').write_bytes(encode(values));print(json.dumps({'cases':len(values)}));return
    if a.mode=='original':
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        o=Original(a.bot);start=time.monotonic();rows=[];traces=[]
        for c in read_cases(out):
            rows.append(o.run(c));traces.append({'id':c['id'],'account_reads':o.account_reads,'prices':o.price_calls,'error':hex(o.error) if o.error else None})
        target.write_bytes(struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<2iQIQ',*r) for r in rows))
        (out/'native-traces.json').write_text(json.dumps(traces,ensure_ascii=False),encoding='utf-8')
        (out/'original-run.json').write_text(json.dumps({'cases':len(rows),'seconds':round(time.monotonic()-start,2),'tool_sha256':sha(Path(__file__)),'result_sha256':sha(target),'scope':__doc__},indent=2),encoding='utf-8');print(json.dumps({'cases':len(rows),'seconds':round(time.monotonic()-start,2)}));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        files=MT/f'MQL5/Files/bot{a.bot}-currency'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        params=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set';params.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-currency.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}CurrencyCheck\nScriptParameters={params.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0:raise RuntimeError('MQL5_CHECK_EXIT '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target);script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}CurrencyCheck.ex5'
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),'script_sha256':sha(script),'results_sha256':sha(target)},indent=2),encoding='utf-8');print('MQL5 results saved');return
    values=read_cases(out);e=(out/'original-results.bin').read_bytes();v=(out/'mql5-results.bin').read_bytes();count=len(values)
    if e[:12]!=struct.pack('<3i',MAGIC,1,count) or v[:12]!=e[:12] or len(e)!=12+count*28 or len(v)!=len(e):raise ValueError('RESULT_SHAPE_MISMATCH')
    failures=[];groups={}
    for i,c in enumerate(values):
        x=struct.unpack_from('<2iQIQ',e,12+i*28);y=struct.unpack_from('<2iQIQ',v,12+i*28)
        g=groups.setdefault(c['tag'],{'cases':0,'matched':0});g['cases']+=1;g['matched']+=int(x==y)
        if x!=y:failures.append({'id':i,'currency':c['currency'],'to_usd':c['to_usd'],'original':x,'mql5':y})
    record={'cases':count,'matched':count-len(failures),'failed':len(failures),'passed':not failures,'groups':groups,'first_failures':failures[:25],
        'hashes':{p:sha(out/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']},'scope':__doc__}
    (out/'comparison.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));raise SystemExit(bool(failures))
if __name__=='__main__':main()
