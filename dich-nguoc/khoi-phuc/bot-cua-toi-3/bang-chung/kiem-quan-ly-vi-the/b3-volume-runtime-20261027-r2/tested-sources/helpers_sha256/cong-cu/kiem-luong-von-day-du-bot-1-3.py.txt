"""Execute original volume preparation with original withdrawal and currency helpers.

Compare numeric state even on division faults, completed withdrawal timestamps,
history/persistence call hashes and currency-price call hashes. Terminal data mocked;
formatting and message content excluded. Not the full EA or startup restoration.
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
account=module('account_check','kiem-khoi-luong-ghep-bot-1-3.py')
withdrawal=module('withdrawal_check','kiem-rut-tien-bot-1-3.py')
volume,currency=account.volume,account.currency
MT=account.MT
MAGIC=0x53564c31
def cases(bot):
    out=account.cases(bot)
    default=withdrawal.base_case()
    keys=['enabled','tester','select_ok','restore_ok','reported_count','last_check','last_deal','times','peak_key','time_key','deals']
    for c in out:
        c.update({k:default[k] for k in keys});c['enabled']=0;c['tag']='previous-account-flow'
    for i,w in enumerate(withdrawal.cases()):
        c=volume.base_case(bot);c.update({k:w[k] for k in keys})
        c.update({'s.highest_balance':w['peak'],'balance':w['balance'],'equity':w['balance']+1000.,
                  'r.use_equity':i%2,'s.mode':[0,3,999,9999,1234][i%5],'r.lot_scale':[0.5,1.,2.][i%3],
                  'currency':['USD','EUR','CHF','CZK','CNH'][i%5],'suffix':'.a',
                  'prices':[2.,0.,2.,2.] if i%3==0 else [2.,2.,2.,2.],'tag':'withdrawal-to-volume'})
        if bot==3:c['r.weighted']=i%2
        out.append(c)
    for mode in [999,1234]:
        c=volume.base_case(bot);c.update({k:default[k] for k in keys})
        c.update({'s.mode':mode,'s.highest_balance':9000.,'balance':12000.,'currency':'EUR','suffix':'',
                  'prices':[2.,0.,2.,2.],'tag':'partial-state-on-fault'})
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
        raw+=struct.pack('<5i2q3q',*(c[n] for n in ['enabled','tester','select_ok','restore_ok','reported_count','last_check','last_deal']),*c['times'])
        raw+=currency.pack_text(c['peak_key'])+currency.pack_text(c['time_key'])+struct.pack('<i',len(c['deals']))
        for row in c['deals']:raw+=struct.pack('<Qqqd',*row)
    return raw
class Original(account.Original):
    def __init__(self,bot):
        super().__init__(bot);self.withdrawal_cfg=withdrawal.CONFIG[bot]
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        main=next(f for f in meta['functions'] if int(f['begin_rva'],16)==self.volume_cfg['fn'])
        self.main_range=(int(main['begin_rva'],16),int(main['end_rva'],16))
        eb=next(a for a,api in self.apis.items() if api==1)-0x7d3c40
        extra={eb+0x7c0fd0:30,eb+0x7d1c40:31,eb+0x7d84f0:32,eb+0x7d8810:33,
               eb+0x7d8860:34,eb+0x7d8940:35,eb+0x7d88b0:36,eb+0x7cd7c0:38}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for addr in extra:self.m.mem_write(addr,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
    def enter(self,m,address,size,user):
        super().enter(m,address,size,user);c=self.case;cfg=self.withdrawal_cfg
        self.clock_calls=self.select_calls=self.history_count=0;self.history_hash=0xcbf29ce484222325;self.history_prefix=[];self.writes=[]
        for n,k,key in [('enabled','B','enabled'),('last_check','q','last_check'),('last_deal','q','last_deal')]:m.mem_write(self.base+cfg[n],struct.pack('<'+k,c[key]))
        for n in ['peak_key','time_key']:m.mem_write(self.base+cfg[n],struct.pack('<IQ',0,self.string(c[n])))
    def trace(self,api,first,second,value):
        self.history_count+=1
        if len(self.history_prefix)<100:self.history_prefix.append([api,first,second,value])
        for word in [api,first,second,value]:
            for byte in struct.pack('<Q',word&volume.MASK):self.history_hash=((self.history_hash^byte)*0x100000001b3)&volume.MASK
    def call(self,m,address,size,user):
        api=self.apis[address]
        mapped=api-20 if api in [30,31,32,33,34,35,36,38] else None
        if api==13:
            x=self.x;ret=struct.unpack('<Q',m.mem_read(m.reg_read(x.UC_X86_REG_RSP),8))[0]-self.base
            if self.main_range[0]<=ret<self.main_range[1]:self.peak_writes+=1
            mapped=17
        if api==12:
            ret=struct.unpack('<Q',m.mem_read(m.reg_read(self.x.UC_X86_REG_RSP),8))[0]-self.base
            if not self.main_range[0]<=ret<self.main_range[1]:mapped=19
        if mapped is not None:
            self.apis[address]=mapped
            try:return withdrawal.Original.call(self,m,address,size,user)
            finally:self.apis[address]=api
        return super().call(m,address,size,user)
    def run(self,c):
        row=super().run(c)
        # Keep all native numeric globals on faults; earlier component tests zeroed them.
        for i,(_,k,rva) in enumerate(volume.fields(volume.OUTPUTS,self.bot)):
            raw=bytes(self.m.mem_read(self.base+rva,struct.calcsize('<'+k)))
            row[2+i]=int.from_bytes(raw,'little') if k=='d' else struct.unpack('<'+k,raw)[0]&volume.MASK
        cfg=self.withdrawal_cfg
        check=struct.unpack('<Q',self.m.mem_read(self.base+cfg['last_check'],8))[0]
        deal=struct.unpack('<Q',self.m.mem_read(self.base+cfg['last_deal'],8))[0]
        return [*row,check,deal,self.history_count,self.history_hash]
def header(bot,count):return struct.pack('<4i',MAGIC,1,count,len(volume.fields(volume.OUTPUTS,bot))+9)+struct.pack('<10i',*volume.ENUMS,*withdrawal.ENUMS)
def read_cases(out,bot):
    values=json.loads((out/'cases.json').read_text())
    if encode(values,bot)!=(out/'cases.bin').read_bytes():raise ValueError('CASE_DATA_MISMATCH')
    return values
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-luong-von-day-du'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);values=cases(a.bot);(out/'cases.json').write_text(json.dumps(values,ensure_ascii=False),encoding='utf-8');(out/'cases.bin').write_bytes(encode(values,a.bot));print(json.dumps({'cases':len(values)}));return
    if a.mode=='original':
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        start=time.monotonic();o=Original(a.bot);rows=[];traces=[];errors=[]
        for c in read_cases(out,a.bot):
            rows.append(o.run(c));traces.append({'id':c['id'],'history':o.history_prefix,'writes':o.writes,'prices':o.price_calls})
            if o.error:errors.append({'id':c['id'],'error':hex(o.error)})
        target.write_bytes(header(a.bot,len(rows))+b''.join(struct.pack('<2i'+'Q'*(len(r)-2),*r) for r in rows))
        (out/'native-traces.json').write_text(json.dumps(traces,ensure_ascii=False),encoding='utf-8');(out/'original-run.json').write_text(json.dumps({'cases':len(rows),'division_errors':errors,'seconds':round(time.monotonic()-start,2),'tool_sha256':volume.sha(Path(__file__)),'result_sha256':volume.sha(target),'scope':__doc__},indent=2),encoding='utf-8');print(json.dumps({'cases':len(rows),'division_errors':len(errors),'seconds':round(time.monotonic()-start,2)}));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        files=MT/f'MQL5/Files/bot{a.bot}-state-volume'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        params=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set';params.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-state-volume.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}AccountStateVolumeCheck\nScriptParameters={params.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0:raise RuntimeError('MQL5_CHECK_EXIT '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target);script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}AccountStateVolumeCheck.ex5'
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),'script_sha256':volume.sha(script),'results_sha256':volume.sha(target)},indent=2),encoding='utf-8');print('MQL5 results saved');return
    values=read_cases(out,a.bot);e=(out/'original-results.bin').read_bytes();v=(out/'mql5-results.bin').read_bytes()
    names=['id','success']+[n for n,_,_ in volume.fields(volume.OUTPUTS,a.bot)]+['warnings','alerts','peak_writes','price_calls','price_hash','last_check','last_deal','history_calls','history_hash'];fmt='<2i'+'Q'*(len(names)-2);size=struct.calcsize(fmt)
    if e[:56]!=header(a.bot,len(values)) or v[:56]!=e[:56] or len(e)!=56+len(values)*size or len(v)!=len(e):raise ValueError('RESULT_SHAPE_MISMATCH')
    failures=[];groups={}
    for i,c in enumerate(values):
        x=struct.unpack_from(fmt,e,56+i*size);y=struct.unpack_from(fmt,v,56+i*size);g=groups.setdefault(c['tag'],{'cases':0,'matched':0});g['cases']+=1;g['matched']+=int(x==y)
        if x!=y:failures.append({'id':i,'tag':c['tag'],'differences':{n:[hex(a),hex(b)] for n,a,b in zip(names,x,y) if a!=b}})
    record={'cases':len(values),'matched':len(values)-len(failures),'failed':len(failures),'passed':not failures,'groups':groups,'first_failures':failures[:25],'hashes':{p:volume.sha(out/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']},'scope':__doc__}
    (out/'comparison.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));raise SystemExit(bool(failures))
if __name__=='__main__':main()
