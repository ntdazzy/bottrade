"""Compare withdrawal-state updates and ordered terminal calls with native code.

python -I -B -X utf8 kiem-rut-tien-bot-1-3.py prepare|original|mql5|compare BOT RUN
History, clock and variable writes are isolated test data; no real MT5 variables written.
Diagnostic formatting/content excluded; native string-copy instructions still execute.
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
entry=module('entry_check','kiem-gia-vao-bot-1-3.py')
currency=module('currency_check','kiem-doi-tien-bot-1-3.py')
MT=entry.MT
MAGIC=0x57445431
ENUMS=[6,3,2,9]
CONFIG={1:dict(fn=0x173f0,enabled=0x6a780,last_check=0x6a358,last_deal=0x6a350,peak=0x6a328,peak_key=0x6a330,time_key=0x6a340),
        3:dict(fn=0x1fd00,enabled=0x1d7170,last_check=0x1d6cf0,last_deal=0x1d6ce8,peak=0x1d6c68,peak_key=0x1d6cc8,time_key=0x1d6cd8)}
def base_case():return dict(enabled=1,tester=0,select_ok=1,restore_ok=1,reported_count=2,last_check=900,last_deal=500,
    peak=10000.,balance=9000.,times=[1000,1001,1002],peak_key='bot.peak',time_key='bot.time',deals=[[1,2,600,-100.],[2,2,700,100.]])
def cases():
    rng=random.Random(2026102306);out=[]
    def add(tag,**changes):c=base_case();c.update(changes);c['tag']=tag;out.append(c)
    for _ in range(600):
        c=base_case();c.update(enabled=rng.randrange(2),tester=rng.randrange(3),select_ok=rng.randrange(2),restore_ok=rng.randrange(2),
            peak=rng.choice([0.,-1.,9000.,10000.,12000.]),balance=rng.choice([0.,-1.,9000.,10000.,12000.]),
            times=[rng.choice([899,900,959,960,961,1000]),1001,1002],tag='mixed')
        c['deals']=[[0 if rng.random()<0.1 else i+1,rng.choice([0,1,2,3,0x100000002]),rng.choice([499,500,501,600,700]),rng.choice([-100.,-0.,0.,100.])] for i in range(rng.randrange(7))]
        c['reported_count']=rng.choice([-1,0,len(c['deals']),len(c['deals'])+2]);out.append(c)
    for enabled in [0,1]:
        for tester in [0,1,2]:
            for delta in [-1,0,59,60,61]:
                for ok in [0,1]:add('timing-and-gates',enabled=enabled,tester=tester,times=[900+delta,1001,1002],select_ok=ok)
    for kind in [0,1,2,3,0x100000002]:
        for when in [499,500,501,700]:
            for profit in [-100.,-0.,0.,100.]:
                for balance in [9000.,10000.,12000.]:add('deal-classification',reported_count=1,deals=[[1,kind,when,profit]],balance=balance)
    for deals in [[],[[1,2,600,-100.],[2,2,600,-200.]],[[1,2,700,200.],[2,2,600,-100.]],[[0,2,700,-100.]],[[1,2,700,100.]],[[1,1,800,-100.],[2,2,600,-100.]]]:
        add('order-and-duplicates',reported_count=len(deals),deals=deals)
    for count in [-1,0,1,2,3,100]:add('reported-count',reported_count=count)
    for key in ['','Vốn.cao','a'*100]:add('stored-key',peak_key=key,time_key=key+'.time')
    for i,c in enumerate(out):c['id']=i
    return out
def encode(values):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(values)))
    for c in values:
        raw+=struct.pack('<6i2q2d3q',*(c[n] for n in ['id','enabled','tester','select_ok','restore_ok','reported_count','last_check','last_deal','peak','balance']),*c['times'])
        raw+=currency.pack_text(c['peak_key'])+currency.pack_text(c['time_key'])+struct.pack('<i',len(c['deals']))
        for row in c['deals']:raw+=struct.pack('<Qqqd',*row)
    return raw
class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.withdrawal_cfg=CONFIG[bot]
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        if self.withdrawal_cfg['fn'] not in {int(f['begin_rva'],16) for f in meta['functions']}:raise ValueError('UNVERIFIED_FUNCTION')
        eb=next(a for a,api in self.apis.items() if api==1)-0x7d3c40
        extra={eb+0x7c0fd0:10,eb+0x7d1c40:11,eb+0x7d84f0:12,eb+0x7d8810:13,eb+0x7d8860:14,
               eb+0x7d8940:15,eb+0x7d88b0:16,eb+0x7bdc90:17,eb+0x7cd7c0:18,eb+0x7b49f0:19,eb+0x3959a0:200}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for addr in extra:self.m.mem_write(addr,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address];c=self.case;first=second=value=0
        if api in [100,101]:return super().call(m,address,size,user)
        if api==10:
            first=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
            if first!=6:raise ValueError('MQL_PROPERTY')
            value=c['tester'];m.reg_write(x.UC_X86_REG_RAX,value)
        elif api==11:
            value=c['times'][min(self.clock_calls,2)];self.clock_calls+=1;m.reg_write(x.UC_X86_REG_RAX,value&entry.MASK)
        elif api==12:
            first=m.reg_read(x.UC_X86_REG_RDX);second=m.reg_read(x.UC_X86_REG_R8)
            value=c['select_ok' if self.select_calls==0 else 'restore_ok'];self.select_calls+=1;m.reg_write(x.UC_X86_REG_RAX,value)
        elif api==13:value=c['reported_count'];m.reg_write(x.UC_X86_REG_RAX,value&entry.MASK)
        elif api==14:
            first=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
            value=c['deals'][first][0] if first<len(c['deals']) else 0;m.reg_write(x.UC_X86_REG_RAX,value)
        elif api in [15,16]:
            first=m.reg_read(x.UC_X86_REG_RDX);second=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            row=next((r for r in c['deals'] if r[0]==first),None)
            if row is None:raise ValueError('UNKNOWN_DEAL_TICKET')
            if api==15:
                if second not in [2,3]:raise ValueError('DEAL_INTEGER_PROPERTY')
                value=row[1 if second==3 else 2];m.reg_write(x.UC_X86_REG_RAX,value&entry.MASK)
            else:
                if second!=9:raise ValueError('DEAL_DOUBLE_PROPERTY')
                value=entry.bits(row[3]);m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value)
        elif api==17:
            name=currency.Original.read_text(self,m.reg_read(x.UC_X86_REG_RDX));first=entry.text_hash(name)
            value=m.reg_read(x.UC_X86_REG_XMM2)&entry.MASK;self.writes.append([name,value]);m.reg_write(x.UC_X86_REG_RAX,0)
        elif api==18:
            m.mem_write(self.base+self.cfg['string_result'],b'\0'*12);return
        elif api==19:
            if m.reg_read(x.UC_X86_REG_RDX)!=2:raise ValueError('DIAGNOSTIC_OPCODE')
        else:raise ValueError('NATIVE_RUNTIME_ERROR '+hex(m.reg_read(x.UC_X86_REG_RDX)))
        self.trace(api,first,second,value)
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.cursor=0x70001000;self.allocs=self.frees=0;self.clock_calls=self.select_calls=0;self.writes=[]
        self.count=0;self.hash=0xcbf29ce484222325;self.prefix=[]
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        cfg=self.withdrawal_cfg
        for name,kind,value in [('enabled','B',c['enabled']),('last_check','q',c['last_check']),('last_deal','q',c['last_deal']),('peak','d',c['peak'])]:m.mem_write(self.base+cfg[name],struct.pack('<'+kind,value))
        for name in ['peak_key','time_key']:m.mem_write(self.base+cfg[name],struct.pack('<IQ',0,self.string(c[name])))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_XMM0,entry.bits(c['balance']))
        m.emu_start(self.base+cfg['fn'],0x60000000,timeout=5000000,count=2000000)
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise RuntimeError('NATIVE_DID_NOT_RETURN')
        if self.allocs!=self.frees:raise RuntimeError('STRING_ALLOCATION_IMBALANCE')
        check=struct.unpack('<q',m.mem_read(self.base+cfg['last_check'],8))[0];deal=struct.unpack('<q',m.mem_read(self.base+cfg['last_deal'],8))[0];peak=struct.unpack('<Q',m.mem_read(self.base+cfg['peak'],8))[0]
        return [c['id'],check,deal,peak,self.count,self.hash]
def header(count):return struct.pack('<3i4i',MAGIC,1,count,*ENUMS)
def read_cases(out):
    values=json.loads((out/'cases.json').read_text())
    if encode(values)!=(out/'cases.bin').read_bytes():raise ValueError('CASE_DATA_MISMATCH')
    return values
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-rut-tien'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);values=cases();(out/'cases.json').write_text(json.dumps(values,ensure_ascii=False),encoding='utf-8');(out/'cases.bin').write_bytes(encode(values));print(json.dumps({'cases':len(values)}));return
    if a.mode=='original':
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        start=time.monotonic();o=Original(a.bot);rows=[];traces=[]
        for c in read_cases(out):rows.append(o.run(c));traces.append({'id':c['id'],'writes':o.writes,'trace':o.prefix})
        target.write_bytes(header(len(rows))+b''.join(struct.pack('<iqqQIQ',*r) for r in rows))
        (out/'native-traces.json').write_text(json.dumps(traces,ensure_ascii=False),encoding='utf-8');(out/'original-run.json').write_text(json.dumps({'cases':len(rows),'seconds':round(time.monotonic()-start,2),'tool_sha256':entry.sha(Path(__file__)),'native_rva':hex(CONFIG[a.bot]['fn']),'result_sha256':entry.sha(target),'scope':__doc__},indent=2),encoding='utf-8');print(json.dumps({'cases':len(rows),'seconds':round(time.monotonic()-start,2)}));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        files=MT/f'MQL5/Files/bot{a.bot}-withdrawal'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        params=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set';params.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-withdrawal.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}WithdrawalCheck\nScriptParameters={params.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0:raise RuntimeError('MQL5_CHECK_EXIT '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target);script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}WithdrawalCheck.ex5'
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),'script_sha256':entry.sha(script),'results_sha256':entry.sha(target)},indent=2),encoding='utf-8');print('MQL5 results saved');return
    values=read_cases(out);e=(out/'original-results.bin').read_bytes();v=(out/'mql5-results.bin').read_bytes()
    if e[:28]!=header(len(values)) or v[:28]!=e[:28] or len(e)!=28+40*len(values) or len(v)!=len(e):raise ValueError('RESULT_OR_ENUM_SHAPE_MISMATCH')
    failures=[];groups={}
    for i,c in enumerate(values):
        x=struct.unpack_from('<iqqQIQ',e,28+i*40);y=struct.unpack_from('<iqqQIQ',v,28+i*40);g=groups.setdefault(c['tag'],{'cases':0,'matched':0});g['cases']+=1;g['matched']+=int(x==y)
        if x!=y:failures.append({'id':i,'original':x,'mql5':y})
    record={'cases':len(values),'matched':len(values)-len(failures),'failed':len(failures),'passed':not failures,'groups':groups,'first_failures':failures[:25],'hashes':{p:entry.sha(out/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']},'scope':__doc__}
    (out/'comparison.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));raise SystemExit(bool(failures))
if __name__=='__main__':main()
