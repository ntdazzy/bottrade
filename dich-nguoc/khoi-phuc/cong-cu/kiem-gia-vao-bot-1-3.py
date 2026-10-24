"""Compare entry-level and nearby-order components with captured native code.

Usage: python -I -B -X utf8 kiem-gia-vao-bot-1-3.py prepare|original|mql5|compare BOT RUN
The oracle executes native string copying and both levels of trading functions.
Only terminal APIs and successful runtime string allocation/free are supplied.
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
MAGIC=0x454e5431
ENUMS=[15,4,0,9,4,5,17]
spec=importlib.util.spec_from_file_location('price_check',Path(__file__).with_name('kiem-muc-gia-bot-1-3.py'))
price_check=importlib.util.module_from_spec(spec);spec.loader.exec_module(price_check)
CONFIG={
 1:dict(entry_buy=0x265a0,entry_sell=0x26960,guard_buy=0x3c670,guard_sell=0x3c8d0,
        older=0x62430,recent=0x62434,last=0x62438,gap_points=0x62440,confirm_tf=0x6227c,
        buy_offset=0x62448,sell_offset=0x62450,radius=0x62460,magic=0x6246c,unit=0x66d98,
        result_buy=0x67440,result_sell=0x67438,ticket=0x677f8,symbol=0x67918,string_result=0x6a43c),
 3:dict(entry_buy=0x31cd0,entry_sell=0x32090,guard_buy=0x47380,guard_sell=0x475e0,
        older=0x6d528,recent=0x6d52c,last=0x6d530,gap_points=0x6d538,confirm_tf=0x6d2b4,
        buy_offset=0x6d540,sell_offset=0x6d548,radius=0x6d558,magic=0x6d564,unit=0x73dd8,
        result_buy=0x74480,result_sell=0x74478,ticket=0x74838,symbol=0x74958,string_result=0x1d6e3c)}

def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def text_hash(value):
    h=0xcbf29ce484222325
    for byte in value.encode('utf-16-le'):h=((h^byte)*0x100000001b3)&MASK
    return h
def base_case(kind,buy):
    return dict(kind=kind,buy=buy,tf=15,confirm_tf=16385,older=1,recent=1,last=12,digits=3,
        magic=9001,prior_ticket=0x1122334455667788,quote=100.0,gap=1.0,unit=0.01,
        buy_offset=2.0,sell_offset=3.0,radius=5.0,level=100.0,symbol='XAUUSD',
        prices=[100.,100.,102.,100.,101.,103.,101.,100.,104.,100.,100.,100.,100.,100.,100.,100.],
        confirm=[100.]*24,orders=[])
def cases():
    rng=random.Random(2026102302);out=[]
    for buy in [0,1]:
        for kind in [0,1]:
            for _ in range(220):
                c=base_case(kind,buy);c.update(tf=rng.choice([5,15,16385]),confirm_tf=rng.choice([5,15,16385]),
                    older=rng.randrange(4),recent=rng.randrange(4),last=rng.randrange(20),digits=rng.choice([-1,0,2,3,8,11,12]),
                    magic=rng.choice([-2147483648,-1,0,9001,2147483647]),quote=rng.uniform(95,105),
                    unit=rng.choice([0.,0.001,0.01,1.,-1.]),gap=rng.choice([0.,1.,-1.,5.]),
                    radius=rng.choice([0.,0.1,1.,5.,100.,-1.]),symbol=rng.choice(['XAUUSD','XAUUSD.a','Vàng','']))
                c['prices']=[rng.uniform(95,105) for _ in range(32)];c['confirm']=[rng.uniform(95,105) for _ in range(32)]
                target=c['level']+(c['buy_offset'] if buy else -c['sell_offset'])*c['unit']
                for i in range(rng.randrange(6)):
                    c['orders'].append([rng.choice([0,i+1,0x100000002]),rng.choice([c['magic'],c['magic']+1,0x100000001]),
                        rng.choice([0,1,4,5,6]),target+rng.uniform(-0.2,0.2),rng.choice([c['symbol'],'OTHER','XAUUSD'])])
                out.append(c)
        for delta in [-1.001,-1.,-0.999,0.,0.999,1.,1.001]:
            for wrong in ['none','magic','symbol','type','ticket']:
                c=base_case(0,buy);target=100.+(2. if buy else -3.)*0.01
                order=[10,9001,4 if buy else 5,target+delta*0.05,'XAUUSD']
                if wrong=='magic':order[1]=9002
                if wrong=='symbol':order[4]='xauusd'
                if wrong=='type':order[2]=5 if buy else 4
                if wrong=='ticket':order[0]=0
                c['orders']=[order];c['tag']='guard-boundary-'+wrong;out.append(c)
        for text in ['','X','Vàng','XAUUSD.long.symbol.name']:
            c=base_case(0,buy);c['symbol']=text
            c['orders']=[[0,9001,4 if buy else 5,100.,text],[3,9001,4 if buy else 5,100.+(2 if buy else -3)*0.01,text]]
            out.append(c)
        for value in [float('nan'),float('inf'),-float('inf'),0.,-0.,1e19,-1e19,100.005]:
            for field in ['quote','gap','unit','radius','level']:
                c=base_case(0,buy);c[field]=value;c['orders']=[[1,9001,4 if buy else 5,100.,'XAUUSD']];out.append(c)
            for field in ['prices','confirm']:
                c=base_case(1,buy);c[field]=[value]*24;out.append(c)
        for broken in [False,True]:
            for blocked in [0,1,2,3]:
                c=base_case(1,buy)
                if not buy:c['prices']=[200.-p for p in c['prices']]
                c['confirm']=[105. if buy else 95.]*24 if broken else [100.]*24
                for i,level in enumerate(([102.,103.,104.] if buy else [98.,97.,96.])[:blocked]):
                    c['orders'].append([i+1,9001,4 if buy else 5,level+(2 if buy else -3)*0.01,'XAUUSD'])
                c['tag']='entry-broken-or-blocked';out.append(c)
        for size,older,recent,last in [(0,0,0,0),(2,4,4,15),(24,0,0,0),(24,2,2,0),(24,0,0,20)]:
            c=base_case(1,buy);c.update(prices=[100.]*size,confirm=[100.]*size,older=older,recent=recent,last=last);out.append(c)
    for i,c in enumerate(out):c['id']=i
    return out

def pack_text(value):
    raw=value.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def encode(cases_):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(cases_)))
    for c in cases_:
        raw+=struct.pack('<10iQ7d',*(c[k] for k in ['id','kind','buy','tf','confirm_tf','older','recent','last','digits','magic']),
            c['prior_ticket'],*(c[k] for k in ['quote','gap','unit','buy_offset','sell_offset','radius','level']))
        raw+=pack_text(c['symbol'])
        for k in ['prices','confirm']:raw+=struct.pack('<i',len(c[k]))+struct.pack('<'+'d'*len(c[k]),*c[k])
        raw+=struct.pack('<i',len(c['orders']))
        for ticket,magic,type_,price,symbol in c['orders']:raw+=struct.pack('<Qqid',ticket,magic,type_,price)+pack_text(symbol)
    return raw

class Original(price_check.Original):
    def __init__(self,bot):
        super().__init__(bot);self.cfg.update(CONFIG[bot]);self.bot=bot
        run='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        metadata=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/run/'metadata/import.json').read_text())
        entries={int(row['begin_rva'],16) for row in metadata['functions']}
        if any(self.cfg[name] not in entries for name in ['entry_buy','entry_sell','guard_buy','guard_sell']):
            raise ValueError('FUNCTION_NOT_IN_CAPTURED_RUNTIME_TABLE')
        eb=next(addr for addr,api in self.apis.items() if api==1)-0x7d3c40
        extra={eb+0x7d81a0:4,eb+0x7d81f0:5,eb+0x7d8310:6,eb+0x7d83a0:7,eb+0x7d8280:8,
               eb+0x7d1190:100,eb+0x7d1200:101}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for addr in extra:
            self.m.mem_write(addr,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
        self.m.mem_map(0x70000000,0x200000)
    def string(self,text):
        raw=text.encode('utf-16-le');address=self.cursor;self.cursor+=(12+len(raw)+2+15)&~15
        self.m.mem_write(address,struct.pack('<III',0,2,len(raw)//2)+raw+b'\0\0');return address+12
    def trace(self,api,first,second,value):
        self.count+=1
        if len(self.prefix)<80:self.prefix.append([api,first,second,value])
        for word in [api,first&MASK,second&MASK,value&MASK]:
            for byte in struct.pack('<Q',word):self.hash=((self.hash^byte)*0x100000001b3)&MASK
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address];c=self.case;first=second=0
        if api==100:
            n=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
            if n>10000:raise ValueError('UNEXPECTED_STRING_ALLOCATION')
            pointer=self.cursor;self.cursor+=(12+(n+1)*2+15)&~15
            if self.cursor>=0x70200000:raise MemoryError('CHECK_HEAP_LIMIT')
            m.mem_write(pointer,struct.pack('<III',n+1,0,0)+b'\0'*((n+1)*2));m.reg_write(x.UC_X86_REG_RAX,pointer);self.allocs+=1;return
        if api==101:self.frees+=1;return
        if api in [1,2]:
            first=struct.unpack('<i',struct.pack('<I',m.reg_read(x.UC_X86_REG_R9)&0xffffffff))[0]
            second=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            values=c['prices'] if second==c['tf'] else c['confirm'];v=values[first] if 0<=first<len(values) else 0.
            value=bits(v);m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value)
        elif api==3:
            first=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            if first!=17:raise ValueError('UNEXPECTED_SYMBOL_PROPERTY')
            value=c['digits']&MASK;m.reg_write(x.UC_X86_REG_RAX,value)
        elif api==4:value=len(c['orders']);m.reg_write(x.UC_X86_REG_RAX,value)
        elif api==5:
            first=struct.unpack('<i',struct.pack('<I',m.reg_read(x.UC_X86_REG_RDX)&0xffffffff))[0];value=0
            if 0<=first<len(c['orders']):self.selected=first;value=c['orders'][first][0]
            m.reg_write(x.UC_X86_REG_RAX,value)
        else:
            first=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
            if self.selected<0:raise ValueError('ORDER_READ_WITHOUT_SELECTION')
            order=c['orders'][self.selected]
            if api==6:
                if first not in [15,4]:raise ValueError('UNEXPECTED_ORDER_INTEGER')
                value=order[1 if first==15 else 2]&MASK;m.reg_write(x.UC_X86_REG_RAX,value)
            elif api==7:
                if first!=0:raise ValueError('UNEXPECTED_ORDER_STRING')
                pointer=self.string(order[4]);m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,pointer));value=text_hash(order[4])
            elif api==8:
                if first!=9:raise ValueError('UNEXPECTED_ORDER_DOUBLE')
                value=bits(order[3]);m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value)
            else:raise ValueError('UNEXPECTED_API')
        self.trace(api,first,second,value)
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.count=0;self.hash=0xcbf29ce484222325;self.prefix=[]
        self.selected=-1;self.cursor=0x70001000;self.allocs=self.frees=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        for field,value in [('bid',c['quote']),('ask',c['quote']),('unit',c['unit']),('gap_points',c['gap']),('buy_offset',c['buy_offset']),('sell_offset',c['sell_offset']),('radius',c['radius'])]:
            m.mem_write(self.base+self.cfg[field],struct.pack('<d',value))
        for field,key in [('older','older'),('recent','recent'),('last','last'),('confirm_tf','confirm_tf'),('magic','magic')]:m.mem_write(self.base+self.cfg[field],struct.pack('<i',c[key]))
        m.mem_write(self.base+self.cfg['ticket'],struct.pack('<Q',c['prior_ticket']))
        m.mem_write(self.base+self.cfg['symbol'],struct.pack('<IQ',0,self.string(c['symbol'])))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        suffix='buy' if c['buy'] else 'sell'
        if c['kind']==0:fn='guard_'+suffix;m.reg_write(x.UC_X86_REG_XMM0,bits(c['level']))
        else:fn='entry_'+suffix;m.reg_write(x.UC_X86_REG_RCX,c['tf']);m.mem_write(self.base+self.cfg['result_'+suffix],struct.pack('<d',123456.))
        try:m.emu_start(self.base+self.cfg[fn],0x60000000,timeout=5000000,count=4000000)
        except self.uc.UcError as error:raise RuntimeError(f'case={c["id"]} rip={m.reg_read(x.UC_X86_REG_RIP):x} {error}') from error
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise RuntimeError('ORIGINAL_DID_NOT_RETURN')
        if self.allocs!=self.frees:raise RuntimeError(f'STRING_ALLOCATION_IMBALANCE {c["id"]} {self.allocs}/{self.frees}')
        value=int(bool(m.reg_read(x.UC_X86_REG_RAX)&0xff)) if c['kind']==0 else struct.unpack('<Q',m.mem_read(self.base+self.cfg['result_'+suffix],8))[0]
        ticket=struct.unpack('<Q',m.mem_read(self.base+self.cfg['ticket'],8))[0]
        return (c['id'],value,ticket,self.count,self.hash)

def read_cases(out):
    values=json.loads((out/'cases.json').read_text(encoding='utf-8'))
    if encode(values)!=(out/'cases.bin').read_bytes():raise ValueError('CASE_JSON_BINARY_MISMATCH')
    return values
def header(count):return struct.pack('<4i',MAGIC,1,count,len(ENUMS))+struct.pack('<7i',*ENUMS)
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-gia-vao'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);values=cases();(out/'cases.json').write_text(json.dumps(values,ensure_ascii=False),encoding='utf-8');(out/'cases.bin').write_bytes(encode(values));print(json.dumps({'cases':len(values)}));return
    if a.mode=='original':
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        values=read_cases(out);original=Original(a.bot);start=time.monotonic();rows=[]
        for c in values:rows.append(original.run(c))
        target.write_bytes(header(len(rows))+b''.join(struct.pack('<iQQIQ',*r) for r in rows))
        record={'cases':len(rows),'seconds':round(time.monotonic()-start,2),'result_sha256':sha(target),'inputs_sha256':sha(out/'cases.bin'),'native_rvas':CONFIG[a.bot], 'string_allocator':'successful local allocations; native string copy/free callers executed unchanged'}
        (out/'original-run.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        files=MT/f'MQL5/Files/bot{a.bot}-entry-levels'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        params=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set';params.parent.mkdir(exist_ok=True);params.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-component.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}EntryLevelsCheck\nScriptParameters={params.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0:
            (out/'mql5-failure.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2)},indent=2),encoding='utf-8')
            raise RuntimeError('MQL5_CHECK_EXIT '+str(code))
        if not (files/'mql5-results.bin').exists():raise RuntimeError('MQL5_RESULTS_MISSING '+str(code))
        if not (files/'profiles.bin').exists():raise RuntimeError('MQL5_PROFILES_MISSING')
        shutil.copyfile(files/'profiles.bin',out/'profiles.bin')
        shutil.copyfile(files/'mql5-results.bin',target);script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}EntryLevelsCheck.ex5'
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),'script_sha256':sha(script),'results_sha256':sha(target),'parameters_sha256':sha(params)},indent=2),encoding='utf-8');print('MQL5 results saved');return
    values=read_cases(out);orig=(out/'original-results.bin').read_bytes();reco=(out/'mql5-results.bin').read_bytes();count=len(values)
    if orig[:44]!=header(count) or reco[:44]!=header(count) or len(orig)!=44+count*32 or len(reco)!=len(orig):raise ValueError('RESULT_SHAPE_OR_ENUM_MISMATCH')
    failures=[];groups={}
    for i,c in enumerate(values):
        x=struct.unpack_from('<iQQIQ',orig,44+32*i);y=struct.unpack_from('<iQQIQ',reco,44+32*i)
        name=('entry-' if c['kind'] else 'pending-')+('buy' if c['buy'] else 'sell');g=groups.setdefault(name,{'cases':0,'matched':0});g['cases']+=1;g['matched']+=int(x==y)
        if x!=y:failures.append({'case':i,'original':x,'mql5':y})
    record={'cases':count,'matched':count-len(failures),'failed':len(failures),'groups':groups,'first_failures':failures[:20],
        'hashes':{name:sha(out/name) for name in ['cases.bin','original-results.bin','mql5-results.bin']},
        'scope':'Four native functions per bot; result bits, last ticket, call count and ordered API trace hashes; mocked terminal data and successful allocations. Not a full EA check.'}
    if (out/'profiles.bin').exists():
        run='luot-20261023-data-v2' if a.bot==1 else 'luot-20261023-data'
        proof=json.loads((ROOT/f'bot-cua-toi-{a.bot}/phan-tich'/run/'kiem-tham-so-goc.json').read_text())
        profiles=sorted(proof['profiles'],key=lambda r:r['index']);expected=bytearray(struct.pack('<3i',0x50524631,1,len(profiles)))
        for row in profiles:
            v=row['values'];expected+=struct.pack('<6id',row['index'],v['confirm_tf'],v['entry_h1' if a.bot==1 else 'entry_tf'],v['older'],v['recent'],v['scan'],v['gap'])
        profiles_ok=(out/'profiles.bin').read_bytes()==expected
        record['raw_profiles']={'matched':len(profiles) if profiles_ok else 0,'total':len(profiles),'identical':profiles_ok,'sha256':sha(out/'profiles.bin')}
        if not profiles_ok:failures.append({'raw_profiles':'different'})
    record['passed']=not failures
    (out/'comparison.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));raise SystemExit(bool(failures))
if __name__=='__main__':main()
