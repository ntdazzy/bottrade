"""Compare complete native filling-policy selection with restored MQL5.

Usage: kiem-kieu-khop-lenh-bot-1-3.py prepare|original|mql5|compare BOT RUN [--build BUILD]
Symbol properties and read success are supplied. Native string helpers execute;
return byte, four mutated fields and ordered API/message arguments are compared.
No request is sent; only the private MT5 executes a component check script.
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
MAGIC=0x46494c31
MASK=(1<<64)-1
CFG={1:dict(fn=0x231c0,request=0x674b0,fill=0x67504,time=0x67508,code=0x675a0,preferred=0x67735,chart=0x6a428),
     3:dict(fn=0x2e8f0,request=0x744f0,fill=0x74544,time=0x74548,code=0x745e0,preferred=0x74775,chart=0x1d6e28)}
spec=importlib.util.spec_from_file_location('fill_entry',Path(__file__).with_name('kiem-gia-vao-bot-1-3.py'))
entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
spec=importlib.util.spec_from_file_location('fill_validation',Path(__file__).with_name('kiem-khoi-luong-hop-le-bot-1-3.py'))
validation=importlib.util.module_from_spec(spec);spec.loader.exec_module(validation)
FIELDS=['id','execution','flags','expiration_flags','expiration_ok','action','type','time','preferred','fill','code','symbol_kind']
WARNING='CTrade::ExpirationCheck: Unknown expiration type'

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def save(path,value):
    with path.open('x',encoding='utf-8') as stream:json.dump(value,stream,ensure_ascii=False,indent=2)
def cases():
    rows=[]
    def add(group,**changes):
        r=dict(id=len(rows),execution=3,flags=0,expiration_flags=0,expiration_ok=1,action=5,type=4,
               time=0,preferred=0,fill=77,code=123456,symbol_kind=0,group=group);r.update(changes);rows.append(r)
    for execution in [0,1,2,3,-1,0x100000000,0x100000002]:
        for action in [0,1,5]:
            for preferred in [-1,0,1,2,3]:
                for flags in range(8):add('execution-and-policy',execution=execution,action=action,preferred=preferred,flags=flags)
    for preferred in [0,1]:
        for kind in [-1,0,1,2,3,4,5,6,7,8]:
            for time_mode in [-1,0,1,2,3,4]:
                for flags in range(16):
                    add('pending-expiration',preferred=preferred,type=kind,time=time_mode,expiration_flags=flags,flags=(kind+flags)%4)
    for symbol in [0,1,2,3]:
        for ok in [0,1]:
            for time_mode in [-1,0,1,2,3,4]:
                for preferred in [0,1]:add('symbol-and-read-failure',symbol_kind=symbol,expiration_ok=ok,time=time_mode,preferred=preferred,expiration_flags=15,flags=3)
    rng=random.Random(2026102408)
    for _ in range(240):
        add('wide-integers',execution=rng.choice([-2147483648,2147483647,0x100000001,-4294967294,3]),
            flags=rng.choice([-1,-2147483648,0x100000001,0x100000002,4]),
            expiration_flags=rng.choice([-1,-2147483648,0x100000008,0x100000000,15]),
            expiration_ok=rng.randrange(2),action=rng.choice([-1,0,1,5,2147483647]),
            preferred=rng.choice([-2147483648,-1,0,1,2,3,2147483647]),fill=rng.choice([-1,0,1,2,3,77]),
            type=rng.choice([-2147483648,-1,0,2,4,5,6,2147483647]),time=rng.choice([-1,0,1,2,3,2147483647]),
            code=rng.choice([0,10009,10030,2147483647]),symbol_kind=rng.randrange(4))
    return rows
def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<i3q8i',*(r[k] for k in FIELDS)) for r in rows)
def read_results(path):
    raw=path.read_bytes();magic,version,n=struct.unpack_from('<3i',raw)
    if (magic,version)!=(MAGIC,1) or len(raw)!=12+n*36:raise ValueError('BAD_RESULT_SHAPE')
    return list(struct.iter_unpack('<7iQ',raw[12:]))
def symbol_text(kind):return ['XAUUSD','','','Vàng'][kind]

class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.fill_cfg=CFG[bot]
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        metadata=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        starts={0,0x5c0,self.fill_cfg['fn']}
        self.ranges=[(int(f['begin_rva'],16),int(f['end_rva'],16)) for f in metadata['functions'] if int(f['begin_rva'],16) in starts]
        if len(self.ranges)!=3:raise ValueError('NATIVE_FUNCTION_NOT_LISTED')
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        extra={eb+0x7c2970:31,eb+0x7c29d0:32,eb+0x7b49f0:33}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        for address,kind in extra.items():
            # The base harness already has the direct symbol-property hook.
            if address not in self.apis:
                self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
            self.apis[address]=kind
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit)
        self.m.hook_add(self.uc.UC_HOOK_MEM_WRITE,self.write)
    def visit(self,m,address,size,user):
        if address not in self.apis and not any(self.base+a<=address<self.base+b for a,b in self.ranges):raise ValueError('NATIVE_LEFT_CHECKED_FUNCTIONS '+hex(address))
    def write(self,m,access,address,size,value,user):
        if not self.executing:return
        if 0x50000000<=address and address+size<=0x50020000:return
        if 0x70000000<=address and address+size<=0x70200000:return
        if any(self.base+self.fill_cfg[k]<=address and address+size<=self.base+self.fill_cfg[k]+4 for k in ['fill','time','code','preferred']):return
        raise ValueError('UNEXPECTED_NATIVE_STATE_WRITE '+hex(address-self.base))
    def text(self,descriptor):
        pointer=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if not pointer:return ''
        n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0]
        if n>1000:raise ValueError('NATIVE_STRING_TOO_LONG')
        return bytes(self.m.mem_read(pointer,2*n)).decode('utf-16-le')
    def mix(self,*words):
        self.count+=1;self.trace.append(list(words))
        for word in words:
            for byte in struct.pack('<Q',word&MASK):self.hash=((self.hash^byte)*0x100000001b3)&MASK
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;r=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        if api in [31,32]:
            prop=m.reg_read(x.UC_X86_REG_R8)&0xffffffff;text=self.text(m.reg_read(x.UC_X86_REG_RDX))
            if api==31:
                if prop not in [33,50]:raise ValueError('UNEXPECTED_DIRECT_PROPERTY')
                value=r['execution' if prop==33 else 'flags'];m.reg_write(x.UC_X86_REG_RAX,value&MASK)
                self.mix(1,prop,entry.text_hash(text),value,1)
            else:
                if prop!=49:raise ValueError('UNEXPECTED_REF_PROPERTY')
                value=r['expiration_flags'];m.mem_write(m.reg_read(x.UC_X86_REG_R9),struct.pack('<q',value))
                m.reg_write(x.UC_X86_REG_RAX,r['expiration_ok']);self.mix(2,prop,entry.text_hash(text),value,r['expiration_ok'])
        elif api==33:
            if (m.reg_read(x.UC_X86_REG_RDX),m.reg_read(x.UC_X86_REG_R8),m.reg_read(x.UC_X86_REG_R9))!=(2,1,0x590008):raise ValueError('UNEXPECTED_DISPATCH')
            sp=m.reg_read(x.UC_X86_REG_RSP);text=self.text(struct.unpack('<Q',m.mem_read(sp+40,8))[0])
            if text!=WARNING:raise ValueError('WARNING_TEXT_DIFFERS')
            self.mix(3,0,entry.text_hash(text),0,0)
        else:raise ValueError('UNEXPECTED_API '+str(api))
    def run(self,row):
        self.executing=False;m,x=self.m,self.x;self.case=row;self.cursor=0x70001000;self.allocs=self.frees=0;self.count=0;self.hash=0xcbf29ce484222325;self.trace=[]
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.mem_write(0x50000000,b'\0'*0x20000)
        cfg=self.fill_cfg
        for key in ['fill','time','code','preferred']:m.mem_write(self.base+cfg[key],struct.pack('<i',row[key]))
        m.mem_write(self.base+cfg['request'],struct.pack('<i',row['action']))
        m.mem_write(self.base+cfg['request']+80,struct.pack('<i',row['type']))
        desc=0x70000000;ptr=0 if row['symbol_kind']==2 else self.string(symbol_text(row['symbol_kind']))
        m.mem_write(desc,struct.pack('<IQ',0,ptr));m.mem_write(self.base+cfg['chart'],struct.pack('<IQ',0,self.string('XAUUSD_NOCOST_V2')))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_RCX,desc)
        self.executing=True
        try:m.emu_start(self.base+cfg['fn'],0x60000000,timeout=5000000,count=100000)
        finally:self.executing=False
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise ValueError('NATIVE_DID_NOT_RETURN')
        if self.allocs or self.frees:raise ValueError('UNEXPECTED_STRING_ALLOCATION')
        values=[struct.unpack('<i',m.mem_read(self.base+cfg[k],4))[0] for k in ['preferred','fill','time','code']]
        return [row['id'],int(bool(m.reg_read(x.UC_X86_REG_RAX)&255)),*values,self.count,self.hash]

def verify_build(bot,build):
    if not build or not re.fullmatch('[a-z0-9-]+',build):raise ValueError('BUILD_REQUIRED')
    receipt=ROOT/f'bot-cua-toi-{bot}/bang-chung/bien-dich'/build/'bien-nhan.json';d=json.loads(receipt.read_text(encoding='utf-8-sig'))
    target=f'Scripts/bot-cua-toi-{bot}/Bot{bot}FillingCheck.mq5';script=MT/'MQL5'/target.replace('.mq5','.ex5')
    if d['target']!=target or d['errors'] or d['warnings'] or sha(script)!=d['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
    for name in [target,f'Include/bot-cua-toi-{bot}/Bot{bot}Filling.mqh']:
        if sha(ROOT/f'bot-cua-toi-{bot}/source/MQL5'/name)!=d['sources_sha256'][name]:raise ValueError('SOURCE_CHANGED')
    return receipt,script
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-kieu-khop-lenh'/a.run
    if a.mode=='prepare':
        original=validation.original_hash(a.bot);rows=cases();out.mkdir(parents=True,exist_ok=False);save(out/'cases.json',rows);(out/'cases.bin').write_bytes(encode(rows))
        save(out/'baseline.json',dict(original_ex5_sha256=original,cases=len(rows),cases_sha256=sha(out/'cases.bin'),tool_sha256=sha(Path(__file__))))
        print(json.dumps({'cases':len(rows)}));return
    rows=json.loads((out/'cases.json').read_text());base=json.loads((out/'baseline.json').read_text())
    if encode(rows)!=(out/'cases.bin').read_bytes() or sha(out/'cases.bin')!=base['cases_sha256']:raise ValueError('INPUTS_CHANGED')
    if a.mode=='original':
        if validation.original_hash(a.bot)!=base['original_ex5_sha256']:raise ValueError('ORIGINAL_EX5_CHANGED')
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        o=Original(a.bot);start=time.monotonic();values=[];prefix=[]
        for row in rows:
            try:values.append(o.run(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} group={row["group"]} {error}') from error
            if row['group']=='symbol-and-read-failure':prefix.append(dict(id=row['id'],calls=o.trace))
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,1,len(values))+b''.join(struct.pack('<7iQ',*v) for v in values))
        save(out/'native-symbol-traces.json',prefix)
        save(out/'original-run.json',dict(cases=len(values),seconds=round(time.monotonic()-start,2),native_rva=hex(CFG[a.bot]['fn']),result_sha256=sha(out/'original-results.bin'),tool_sha256=sha(Path(__file__)),scope=__doc__))
        print(json.dumps({'cases':len(values)}));return
    if a.mode=='mql5':
        receipt,script=verify_build(a.bot,a.build)
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-filling'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}-fill.set'
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        ini=MT/f'b{a.bot}-{a.run}-fill.ini'
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\n'+f'Script=bot-cua-toi-{a.bot}\\Bot{a.bot}FillingCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_CHECK_TIMEOUT')
        if code or not (files/'mql5-results.bin').exists():raise RuntimeError('MT5_CHECK_FAILED '+str(code))
        shutil.copyfile(files/'mql5-results.bin',out/'mql5-results.bin')
        save(out/'mql5-run.json',dict(exit_code=code,seconds=round(time.monotonic()-start,2),script_sha256=sha(script),build_receipt_sha256=sha(receipt),results_sha256=sha(out/'mql5-results.bin')))
        print(json.dumps({'cases':len(read_results(out/'mql5-results.bin'))}));return
    original=read_results(out/'original-results.bin');actual=read_results(out/'mql5-results.bin')
    if len(original)!=len(rows) or len(actual)!=len(rows):raise ValueError('RESULT_COUNT_MISMATCH')
    fail=[dict(id=i,original=x,mql5=y) for i,(x,y) in enumerate(zip(original,actual)) if x!=y or x[0]!=i or x[1] not in [0,1]]
    result=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:20],hashes={name:sha(out/name) for name in ['cases.bin','original-results.bin','mql5-results.bin']},scope='Complete filling-policy selection: low-byte return, four state fields and ordered symbol properties/message arguments; original write guard rejects any other global mutation. Terminal read results supplied, no actual request or whole EA tested.')
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(fail))
if __name__=='__main__':main()
