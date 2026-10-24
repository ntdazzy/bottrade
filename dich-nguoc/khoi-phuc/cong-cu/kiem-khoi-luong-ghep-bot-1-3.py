"""Check original volume calculation with both original currency helpers executed.

No converted-balance stubs. Terminal reads and successful string allocation supplied.
Withdrawal-history adjustment remains disabled. No margin/order-placement code.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file));m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
volume=module('volume_check','kiem-khoi-luong-bot-1-3.py')
currency=module('currency_check','kiem-doi-tien-bot-1-3.py')
MT=volume.MT
MAGIC=0x56474331
def cases(bot):
    out=volume.cases(bot)[:600]
    for i,c in enumerate(out):
        c.update(currency=currency.CURRENCIES[i%len(currency.CURRENCIES)],suffix=['','.a','đuôi'][i%3],prices=[[2.,2.,2.,2.],[0.,2.,2.,2.],[2.,0.,2.,2.]][i%3],tag='combined-mixed')
    for mode in ([999] if bot==1 else [999,1234]):
        for name in currency.CURRENCIES:
            for prices in [[2.,2.,2.,2.],[0.,2.,2.,2.],[2.,0.,2.,2.]]:
                c=volume.base_case(bot);c.update({'s.mode':mode,'currency':name,'suffix':'.a','prices':prices,'tag':'currency-to-volume'})
                if bot==3:c['r.weighted']=0
                out.append(c)
    for i,c in enumerate(out):c['id']=i
    return out
def encode(values,bot):
    raw=bytearray(struct.pack('<4i',MAGIC,1,bot,len(values)))
    for c in values:
        raw+=struct.pack('<i',c['id'])
        for n,k in [(n,k) for n,k,_ in volume.fields(volume.INPUTS,bot)]+volume.CONTEXT:raw+=struct.pack('<'+volume.pack_kind(k),c[n])
        raw+=currency.pack_text(c['currency'])+currency.pack_text(c['suffix'])+struct.pack('<4d',*c['prices'])
    return raw
class Original(volume.Original):
    def __init__(self,bot):
        super().__init__(bot)
        eb=next(a for a,api in self.apis.items() if api==1)-0x7d3c40
        extra={eb+0x797410:20,eb+0x7d3d40:21}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for addr in extra:self.m.mem_write(addr,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
        addr=self.base+self.volume_cfg['fn'];self.m.hook_add(self.uc.UC_HOOK_CODE,self.enter,begin=addr,end=addr)
    def enter(self,m,address,size,user):
        self.price_calls=[];self.price_hash=0xcbf29ce484222325
        m.mem_write(self.base+currency.CONFIG[self.bot]['suffix'],struct.pack('<IQ',0,self.string(self.case['suffix'])))
    def conversion(self,m,address,size,user):
        # The hook only records entry; native conversion instructions continue.
        self.conversions.append('native_currency')
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api==20:
            if m.reg_read(x.UC_X86_REG_RDX)!=36:raise ValueError('ACCOUNT_CURRENCY_PROPERTY')
            m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(self.case['currency'])));return
        if api==21:
            symbol=currency.Original.read_text(self,m.reg_read(x.UC_X86_REG_RDX));tf=m.reg_read(x.UC_X86_REG_R8)&0xffffffff;shift=m.reg_read(x.UC_X86_REG_R9)&0xffffffff
            n=len(self.price_calls)
            if n>=4:raise ValueError('TOO_MANY_PRICE_READS')
            value=self.case['prices'][n];self.price_calls.append([symbol,tf,shift,volume.bits(value)])
            for word in [currency.entry_check.text_hash(symbol),tf,shift,volume.bits(value)]:
                for byte in struct.pack('<Q',word):self.price_hash=((self.price_hash^byte)*0x100000001b3)&volume.MASK
            raw=struct.pack('<d',value);m.mem_write(self.base+self.cfg['slot'],raw);m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'));return
        return super().call(m,address,size,user)
    def run(self,c):return [*super().run(c),len(self.price_calls),self.price_hash]
def header(bot,count):
    old=volume.header(bot,count);return struct.pack('<4i',MAGIC,1,count,len(volume.fields(volume.OUTPUTS,bot))+5)+old[16:]
def read_cases(out,bot):
    values=json.loads((out/'cases.json').read_text())
    if encode(values,bot)!=(out/'cases.bin').read_bytes():raise ValueError('CASE_DATA_MISMATCH')
    return values
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-khoi-luong-ghep'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);values=cases(a.bot);(out/'cases.json').write_text(json.dumps(values,ensure_ascii=False),encoding='utf-8');(out/'cases.bin').write_bytes(encode(values,a.bot));print(json.dumps({'cases':len(values)}));return
    if a.mode=='original':
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        o=Original(a.bot);start=time.monotonic();rows=[];traces=[];errors=[]
        for c in read_cases(out,a.bot):
            rows.append(o.run(c));traces.append({'id':c['id'],'prices':o.price_calls})
            if o.error:errors.append({'id':c['id'],'error':hex(o.error)})
        target.write_bytes(header(a.bot,len(rows))+b''.join(struct.pack('<2i'+'Q'*(len(r)-2),*r) for r in rows))
        (out/'native-traces.json').write_text(json.dumps(traces,ensure_ascii=False),encoding='utf-8')
        record={'cases':len(rows),'seconds':round(time.monotonic()-start,2),'division_errors':errors,'tool_sha256':volume.sha(Path(__file__)),'dependencies_sha256':{p:volume.sha(Path(__file__).with_name(p)) for p in ['kiem-khoi-luong-bot-1-3.py','kiem-doi-tien-bot-1-3.py']},'result_sha256':volume.sha(target),'scope':__doc__}
        (out/'original-run.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps({'cases':len(rows),'division_errors':len(errors),'seconds':record['seconds']}));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        files=MT/f'MQL5/Files/bot{a.bot}-account-volume'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        params=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set';params.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-account-volume.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}AccountVolumeCheck\nScriptParameters={params.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0:raise RuntimeError('MQL5_CHECK_EXIT '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target);script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}AccountVolumeCheck.ex5'
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),'script_sha256':volume.sha(script),'results_sha256':volume.sha(target)},indent=2),encoding='utf-8');print('MQL5 results saved');return
    values=read_cases(out,a.bot);e=(out/'original-results.bin').read_bytes();v=(out/'mql5-results.bin').read_bytes()
    names=['id','success']+[n for n,_,_ in volume.fields(volume.OUTPUTS,a.bot)]+['warnings','alerts','peak_writes','price_calls','price_hash'];fmt='<2i'+'Q'*(len(names)-2);size=struct.calcsize(fmt)
    if e[:40]!=header(a.bot,len(values)) or v[:40]!=e[:40] or len(e)!=40+len(values)*size or len(v)!=len(e):raise ValueError('RESULT_SHAPE_MISMATCH')
    failures=[];groups={}
    for i,c in enumerate(values):
        x=struct.unpack_from(fmt,e,40+i*size);y=struct.unpack_from(fmt,v,40+i*size)
        g=groups.setdefault(c['tag'],{'cases':0,'matched':0});g['cases']+=1;g['matched']+=int(x==y)
        if x!=y:failures.append({'id':i,'currency':c['currency'],'differences':{n:[hex(a),hex(b)] for n,a,b in zip(names,x,y) if a!=b}})
    record={'cases':len(values),'matched':len(values)-len(failures),'failed':len(failures),'passed':not failures,'groups':groups,'first_failures':failures[:25],'hashes':{p:volume.sha(out/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']},'scope':__doc__}
    (out/'comparison.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));raise SystemExit(bool(failures))
if __name__=='__main__':main()
