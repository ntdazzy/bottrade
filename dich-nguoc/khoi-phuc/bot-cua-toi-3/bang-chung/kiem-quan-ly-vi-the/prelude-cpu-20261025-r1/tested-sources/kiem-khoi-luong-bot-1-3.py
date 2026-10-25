"""Compare volume preparation with captured native arithmetic and branches.

Usage: python -I -B -X utf8 kiem-khoi-luong-bot-1-3.py prepare|original|mql5|compare BOT RUN
Currency-converted balances are supplied at the two conversion boundaries.
Withdrawal-history adjustment is disabled; highest-balance selection still executes.
This checks volume preparation, not margin checks, order placement or the whole EA.
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
MAGIC=0x564f4c31
ENUMS=[37,40,26,34,35,36]
spec=importlib.util.spec_from_file_location('entry_check',Path(__file__).with_name('kiem-gia-vao-bot-1-3.py'))
entry_check=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry_check)
INPUTS=[
 ('r.use_equity','B',0x6a790,0x1d7180),('r.only_up','B',0x6a770,0x1d7160),
 ('r.manual_balance','d',0x6a738,0x1d7128),('r.start_lots','d',0x62530,0x6d620),
 ('r.max_lots','d',0x62538,0x6d628),('r.lot_scale','d',0x682f0,0x6d1c8),
 ('r.manual_risk','d',0x62548,0x6d638),('r.strategy_risk','d',0x6a758,0x1d7150),
 ('r.max_total_dd','d',None,0x1d7140),('r.weighted','B',None,0x1d7148),
 ('r.frequency','i',None,0x6d21c),('s.mode','I',0x62540,0x6d630),
 ('s.highest_balance','d',0x6a328,0x1d6c68),('s.volume','d',0x66a80,0x73ac0),
 ('s.strategy_loss','d',0x69f70,0x76fa0),('s.balance_step','i',0x62550,0x6d640),
 ('s.adaptive_fraction','d',None,0x6d428),('c.weight_denominator','d',None,0x76fa8)]
CONTEXT=[('balance','d'),('equity','d'),('converted_balance','d'),('converted_dd_balance','d'),
         ('tick_value','d'),('minimum','d'),('maximum','d'),('step','d'),
         ('stop_distance','d'),('multiplier','i'),('enabled_mask','I')]
OUTPUTS=[('volume','d',0x66a80,0x73ac0),('effective_balance','d',0x6a320,0x1d6c60),
 ('highest_balance','d',0x6a328,0x1d6c68),('mode','I',0x62540,0x6d630),
 ('strategy_loss','d',0x69f70,0x76fa0),('balance_step','i',0x62550,0x6d640),
 ('adaptive_fraction','d',None,0x6d428)]
CONFIG={1:dict(fn=0x34780,convert=0x36220,history_flag=0x6a780),
        3:dict(fn=0x3f900,convert=0x41780,convert_dd=0x8300,history_flag=0x1d7170,enabled=0x75350)}

def fields(rows,bot):return [(n,k,a if bot==1 else b) for n,k,a,b in rows if (a if bot==1 else b) is not None]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def pack_kind(kind):return 'i' if kind=='B' else kind
def base_case(bot):
    c={n:0 for n,_,_ in fields(INPUTS,bot)}
    c.update({'r.only_up':1,'r.manual_balance':0.,'r.start_lots':0.01,'r.max_lots':100.,'r.lot_scale':1.,
        'r.manual_risk':1.2,'r.strategy_risk':3.,'s.mode':0,'s.highest_balance':10000.,'s.volume':0.37,
        's.strategy_loss':1400.,'s.balance_step':600,'balance':12000.,'equity':11000.,'converted_balance':12000.,
        'converted_dd_balance':12000.,'tick_value':1.,'minimum':0.01,'maximum':200.,'step':0.01,
        'stop_distance':1500.,'multiplier':100,'enabled_mask':31})
    if bot==3:c.update({'r.max_total_dd':30.,'r.weighted':1,'r.frequency':2,'s.adaptive_fraction':0.125,'c.weight_denominator':10.})
    return c
def cases(bot):
    rng=random.Random(2026102304);out=[]
    def add(tag,**changes):c=base_case(bot);c.update(changes);c['tag']=tag;out.append(c)
    modes=[0,1,2,3,4,99,997,998,999,1000,1234,9999,0xffffffff]
    for _ in range(600):
        c=base_case(bot)
        for n,k,_ in fields(INPUTS,bot):
            if k=='B':c[n]=rng.randrange(2)
            elif k in ['i','I']:continue
            else:c[n]=rng.choice([0.,-1.,0.01,0.1,1.,rng.uniform(0.,3000.)])
        c.update(balance=rng.uniform(1.,30000.),equity=rng.uniform(1.,30000.),converted_balance=rng.uniform(1.,30000.),
            converted_dd_balance=rng.uniform(1.,30000.),tick_value=rng.choice([0.,0.1,1.,10.]),
            minimum=rng.choice([0.001,0.01,0.1]),maximum=rng.choice([0.,0.01,0.1,1.,100.]),
            step=rng.choice([0.,0.001,0.01,0.1,0.05,1.]),stop_distance=rng.choice([0.,1.,100.,1500.]),
            multiplier=rng.choice([0,1,100]),enabled_mask=rng.randrange(32),tag='mixed')
        c['s.mode']=rng.choice(modes);c['s.balance_step']=rng.choice([0,1,600,2000])
        if bot==3:c['r.frequency']=rng.randrange(7)
        out.append(c)
    for mode in modes:
        for step in [0.,0.001,0.01,0.1,0.05,1.]:
            for multiplier in [0,1,100]:add('modes-and-steps',**{'s.mode':mode,'step':step,'multiplier':multiplier})
    for mode in [0,3,999,9999,1234]:
        for field in ['balance','equity','r.manual_balance','s.highest_balance']:
            for value in [-1.,-0.,0.,1.,9999.9999,10000.,10000.0001,12000.,12000.0001]:
                for only_up in [0,1]:add('balance-selection',**{'s.mode':mode,field:value,'r.only_up':only_up,'r.use_equity':int(field=='equity')})
    for mode in [0,3,999,9999,1234]:
        for field in ['minimum','maximum','r.start_lots','r.max_lots','r.lot_scale']:
            for value in [-1.,0.,0.009999999,0.01,0.010000001,0.099999999,0.1,0.100000001,0.37,1.]:
                add('volume-boundary',**{'s.mode':mode,field:value})
    for mode in [1,3,999,9999,1234]:
        for field in ['tick_value','stop_distance','s.strategy_loss','s.balance_step']:
            add('zero-divisor',**{'s.mode':mode,field:0 if field=='s.balance_step' else 0.})
    if bot==3:
        for freq in [-1,0,1,2,3,4,5,6]:
            for mask in [0,1,2,4,8,16,31]:
                for weighted in [0,1]:add('adaptive-weighting',**{'s.mode':1234,'r.frequency':freq,'enabled_mask':mask,'r.weighted':weighted})
    for i,c in enumerate(out):c['id']=i
    return out
def encode(values,bot):
    raw=bytearray(struct.pack('<4i',MAGIC,1,bot,len(values)))
    for c in values:
        raw+=struct.pack('<i',c['id'])
        for n,k in [(n,k) for n,k,_ in fields(INPUTS,bot)]+CONTEXT:raw+=struct.pack('<'+pack_kind(k),c[n])
    return raw

class Original(entry_check.Original):
    def __init__(self,bot):
        super().__init__(bot);self.volume_cfg=CONFIG[bot]
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        entries={int(f['begin_rva'],16) for f in meta['functions']}
        if any(self.volume_cfg[n] not in entries for n in ['fn','convert']+(['convert_dd'] if bot==3 else [])):raise ValueError('UNVERIFIED_FUNCTION')
        eb=next(a for a,api in self.apis.items() if api==1)-0x7d3c40
        extra={eb+0x797370:10,eb+0x7c2890:11,eb+0x7b49f0:12,eb+0x7bdc90:13,eb+0x7cf6c0:14,eb+0x3959a0:200}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for addr in extra:
            self.m.mem_write(addr,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
        for name in ['convert']+(['convert_dd'] if bot==3 else []):
            addr=self.base+self.volume_cfg[name];self.m.hook_add(self.uc.UC_HOOK_CODE,self.conversion,begin=addr,end=addr)
    def conversion(self,m,address,size,user):
        x=self.x;name='converted_balance' if address==self.base+self.volume_cfg['convert'] else 'converted_dd_balance'
        value=bits(self.case[name]);m.reg_write(x.UC_X86_REG_XMM0,value);m.reg_write(x.UC_X86_REG_RAX,value)
        self.conversions.append(name)
        rsp=m.reg_read(x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(rsp,8))[0]
        m.reg_write(x.UC_X86_REG_RSP,rsp+8);m.reg_write(x.UC_X86_REG_RIP,ret)
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address];c=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        if api==10:
            prop=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
            if prop not in [37,40]:raise ValueError('ACCOUNT_PROPERTY')
            value=c['balance' if prop==37 else 'equity']
        elif api==11:
            prop=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            if prop not in [26,34,35,36]:raise ValueError('SYMBOL_PROPERTY')
            value=c[{26:'tick_value',34:'minimum',35:'maximum',36:'step'}[prop]]
        elif api==12:
            opcode=m.reg_read(x.UC_X86_REG_RDX)
            if opcode not in [2,3]:raise ValueError('DISPATCH_OPCODE')
            self.warnings+=int(opcode==2);self.alerts+=int(opcode==3);return
        elif api==13:self.peak_writes+=1;return
        elif api==14:
            # Formatting diagnostics excluded; empty formatted string supplied.
            m.mem_write(m.reg_read(x.UC_X86_REG_R9),b'\0'*12);return
        elif api==200:self.error=m.reg_read(x.UC_X86_REG_RDX);m.emu_stop();return
        else:raise ValueError('UNEXPECTED_API '+str(api))
        raw=struct.pack('<d',value);m.mem_write(self.base+self.cfg['slot'],raw);m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'))
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.cursor=0x70001000;self.allocs=self.frees=0
        self.error=self.warnings=self.alerts=self.peak_writes=0;self.conversions=[]
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        for n,k,rva in fields(INPUTS,self.bot):m.mem_write(self.base+rva,struct.pack('<'+k,c[n]))
        m.mem_write(self.base+self.volume_cfg['history_flag'],b'\0')
        if self.bot==3:
            m.mem_write(self.base+self.volume_cfg['enabled'],bytes(int(bool(c['enabled_mask']&(1<<i))) for i in range(5)))
        # Strategy index zero points to the tested element in the native volume array.
        m.mem_write(self.base+(0x678f4 if self.bot==1 else 0x74934),b'\0'*4)
        m.mem_write(self.base+self.cfg['symbol'],struct.pack('<IQ',0,self.string('XAUUSD')))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.reg_write(x.UC_X86_REG_XMM0,bits(c['stop_distance']));m.reg_write(x.UC_X86_REG_RDX,c['multiplier']&0xffffffff)
        try:m.emu_start(self.base+self.volume_cfg['fn'],0x60000000,timeout=5000000,count=2000000)
        except self.uc.UcError as error:raise RuntimeError(f'case={c["id"]} rip={m.reg_read(x.UC_X86_REG_RIP):x} {error}') from error
        if not self.error and m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise RuntimeError('NATIVE_DID_NOT_RETURN')
        if self.error and (self.error&0xffffffff)!=0x1f7:raise RuntimeError('NON_DIVISION_NATIVE_ERROR '+hex(self.error))
        if not self.error and self.allocs!=self.frees:raise RuntimeError('STRING_ALLOCATION_IMBALANCE')
        values=[]
        for _,k,rva in fields(OUTPUTS,self.bot):
            raw=bytes(m.mem_read(self.base+rva,struct.calcsize('<'+k)))
            values.append(0 if self.error else int.from_bytes(raw,'little') if k=='d' else struct.unpack('<'+k,raw)[0]&MASK)
        return [c['id'],int(not self.error),*values,*([0,0,0] if self.error else [self.warnings,self.alerts,self.peak_writes])]

def header(bot,count):return struct.pack('<4i',MAGIC,1,count,len(fields(OUTPUTS,bot))+3)+struct.pack('<6i',*ENUMS)
def read_cases(out,bot):
    values=json.loads((out/'cases.json').read_text())
    if encode(values,bot)!=(out/'cases.bin').read_bytes():raise ValueError('CASE_DATA_MISMATCH')
    return values
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-khoi-luong'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);values=cases(a.bot);(out/'cases.json').write_text(json.dumps(values),encoding='utf-8');(out/'cases.bin').write_bytes(encode(values,a.bot))
        (out/'fields.json').write_text(json.dumps({'inputs':fields(INPUTS,a.bot),'context':CONTEXT,'outputs':fields(OUTPUTS,a.bot)},indent=2),encoding='utf-8');print(json.dumps({'cases':len(values)}));return
    if a.mode=='original':
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        o=Original(a.bot);start=time.monotonic();rows=[];errors=[];conversions={}
        for c in read_cases(out,a.bot):
            rows.append(o.run(c))
            if o.error:errors.append({'id':c['id'],'native_error':hex(o.error)})
            for name in o.conversions:conversions[name]=conversions.get(name,0)+1
        target.write_bytes(header(a.bot,len(rows))+b''.join(struct.pack('<2i'+'Q'*(len(r)-2),*r) for r in rows))
        record={'cases':len(rows),'division_errors':errors,'conversions_supplied':conversions,'seconds':round(time.monotonic()-start,2),
            'tool_sha256':sha(Path(__file__)),'result_sha256':sha(target),'scope':__doc__}
        (out/'original-run.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps({k:record[k] for k in ['cases','conversions_supplied','seconds']}));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        files=MT/f'MQL5/Files/bot{a.bot}-volume'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        params=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set';params.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-volume.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}VolumeCheck\nScriptParameters={params.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0:raise RuntimeError('MQL5_CHECK_EXIT '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target);script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}VolumeCheck.ex5'
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),'script_sha256':sha(script),'results_sha256':sha(target)},indent=2),encoding='utf-8');print('MQL5 results saved');return
    values=read_cases(out,a.bot);expected=(out/'original-results.bin').read_bytes();actual=(out/'mql5-results.bin').read_bytes()
    names=['id','success']+[n for n,_,_ in fields(OUTPUTS,a.bot)]+['warnings','alerts','peak_writes'];fmt='<2i'+'Q'*(len(names)-2);size=struct.calcsize(fmt)
    if expected[:40]!=header(a.bot,len(values)) or actual[:40]!=expected[:40] or len(expected)!=40+len(values)*size or len(actual)!=len(expected):raise ValueError('RESULT_OR_ENUM_SHAPE_MISMATCH')
    failures=[];groups={}
    for i,c in enumerate(values):
        e=struct.unpack_from(fmt,expected,40+i*size);v=struct.unpack_from(fmt,actual,40+i*size)
        g=groups.setdefault(c['tag'],{'cases':0,'matched':0});g['cases']+=1;g['matched']+=int(e==v)
        if e!=v:failures.append({'id':i,'tag':c['tag'],'differences':{n:[hex(x),hex(y)] for n,x,y in zip(names,e,v) if x!=y}})
    record={'cases':len(values),'matched':len(values)-len(failures),'failed':len(failures),'passed':not failures,'groups':groups,'first_failures':failures[:30],
        'hashes':{p:sha(out/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']},'scope':__doc__}
    (out/'comparison.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));raise SystemExit(bool(failures))
if __name__=='__main__':main()
