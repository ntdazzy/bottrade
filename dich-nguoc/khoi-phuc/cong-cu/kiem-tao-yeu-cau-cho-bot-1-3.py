"""Compare request preparation with native code stopped before the send wrapper.

Usage: kiem-tao-yeu-cau-cho-bot-1-3.py prepare|original|mql5|compare BOT RUN [--build BUILD]
Tests all35 known-source-calibrated request/result/check fields, magic, filling
preference and ordered API/message arguments. Ready means preparation reached the
send boundary, never that a trade was sent. Terminal properties are supplied.
"""
import argparse
import hashlib
import importlib.util
import json
import math
from pathlib import Path
import random
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
MAGIC=0x504e4431
MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('pending_fill',Path(__file__).with_name('kiem-kieu-khop-lenh-bot-1-3.py'))
fill=importlib.util.module_from_spec(spec);spec.loader.exec_module(fill)
MT=fill.MT
CFG={1:dict(fn=0x32dd0,send=0x950,stopped=0x6a414,virtual=0x6a5e8,magic_input=0x6246c,magic=0x67725),
     3:dict(fn=0x3e580,send=0x950,stopped=0x1d6e14,virtual=0x1d6fc8,magic_input=0x6d564,magic=0x74765)}
FIELDS=[('id','i'),('stopped','i'),('virtual','i'),('strategy_magic','i'),('type','i'),('preferred','i'),
        ('execution0','q'),('filling0','q'),('execution1','q'),('filling1','q'),('auto_expiration','q'),
        ('order_flags','q'),('order_ok','i'),('expiration0','q'),('expiration_ok0','i'),('expiration1','q'),
        ('expiration_ok1','i'),('volume','d'),('price','d'),('sl','d'),('tp','d'),('expiration','q'),
        ('symbol_kind','i'),('comment_kind','i')]
LAYOUT=ROOT/'doi-chung-mt5/thu-tu-truong-lenh-class-20261024/layout-class-r1/trade-layout.json'

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def save(path,value):
    with path.open('x',encoding='utf-8') as stream:json.dump(value,stream,ensure_ascii=False,indent=2,allow_nan=False)
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def base():return dict(stopped=0,virtual=1,strategy_magic=9001,type=4,preferred=0,
                       execution0=2,filling0=3,execution1=2,filling1=3,auto_expiration=15,
                       order_flags=63,order_ok=1,expiration0=15,expiration_ok0=1,expiration1=15,
                       expiration_ok1=1,volume=0.1,price=2600.25,sl=2500.,tp=2700.,expiration=0,
                       symbol_kind=0,comment_kind=0)
def cases():
    out=[]
    def add(group,**changes):r=base();r.update(changes);r.update(id=len(out),group=group);out.append(r)
    for stopped in [0,1,-1]:
        for magic in [-2147483648,-1,0,9001,2147483647]:add('stopped-and-magic',stopped=stopped,strategy_magic=magic)
    for virtual in [0,1,2,255]:
        for expiry in [-1,0,1,2147483647,0x100000001]:
            for flags in [0,1,2,3,4,8,15,-1]:add('virtual-and-expiration',virtual=virtual,expiration=expiry,auto_expiration=flags,expiration0=flags,expiration1=flags)
    for kind in [-1,0,1,2,3,4,5,6,7,8,2147483647]:
        for flags in range(64):add('order-types-and-protection',type=kind,order_flags=flags)
    for first in [0,1,2,3,-1]:
        for second in [0,1,2,3,-1]:
            for preferred in [-1,0,1,2,3]:
                for flags in [0,1,2,3]:add('two-filling-reads',execution0=first,execution1=second,preferred=preferred,filling0=flags,filling1=3-flags)
    for symbol in range(4):
        for comment in range(4):
            for ok in [0,1]:add('text-and-order-read-failure',symbol_kind=symbol,comment_kind=comment,order_ok=ok)
    for first in [0,1,2,4,8,15]:
        for second in [0,1,2,4,8,15]:
            for ok in [0,1]:add('expiration-repeated-read',execution0=3,execution1=3,expiration0=first,expiration1=second,expiration_ok0=ok,expiration_ok1=1-ok)
    for field in ['volume','price','sl','tp']:
        for value in [-1.,-0.,0.,math.nan,math.inf,-math.inf]:add('numeric-edge',**{field:value})
    rng=random.Random(2026102409)
    for _ in range(100):add('mixed',execution0=rng.randrange(4),execution1=rng.randrange(4),filling0=rng.randrange(4),filling1=rng.randrange(4),type=rng.randrange(8),preferred=rng.randrange(4),virtual=rng.randrange(2),expiration=rng.choice([0,1,1700000000]),order_flags=rng.randrange(64),expiration0=rng.randrange(16),expiration1=rng.randrange(16),expiration_ok0=rng.randrange(2),expiration_ok1=rng.randrange(2),symbol_kind=rng.randrange(4))
    return out
def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(b''.join(struct.pack('<'+kind,r[name]) for name,kind in FIELDS) for r in rows)
def read_cases(path):
    raw=path.read_bytes();magic,version,n=struct.unpack_from('<3i',raw);fmt='<'+''.join(k for _,k in FIELDS)
    if (magic,version)!=(MAGIC,1) or struct.calcsize(fmt)!=148 or len(raw)!=12+n*148:raise ValueError('BAD_CASE_SHAPE')
    return [dict(zip([name for name,_ in FIELDS],v)) for v in struct.iter_unpack(fmt,raw[12:])]
def read_results(path):
    raw=path.read_bytes();magic,version,n=struct.unpack_from('<3i',raw)
    if (magic,version)!=(MAGIC,1) or len(raw)!=12+n*280:raise ValueError('BAD_RESULT_SHAPE')
    return [raw[12+i*280:12+(i+1)*280] for i in range(n)]

class Original(fill.Original):
    def __init__(self,bot):
        super().__init__(bot);self.pending_cfg=CFG[bot];self.layout=json.loads(LAYOUT.read_text())
        for name,digest in self.layout['source_sha256'].items():
            if sha(ROOT/name)!=digest:raise ValueError('CALIBRATION_SOURCE_CHANGED')
        if not self.layout['runner_verified'] or not self.layout['only_anchor_executed']:raise ValueError('CALIBRATION_NOT_VERIFIED')
        if self.layout['relative_native_storage_bases']!={'request':0,'result':240,'check':436} or self.layout['end_marker_offset']!=628:raise ValueError('CLASS_LAYOUT_NOT_EXPECTED')
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        function=next(f for f in meta['functions'] if int(f['begin_rva'],16)==self.pending_cfg['fn'])
        self.ranges.append((self.pending_cfg['fn'],int(function['end_rva'],16)))
        send=self.base+self.pending_cfg['send'];self.m.hook_add(self.uc.UC_HOOK_CODE,self.before_send,begin=send,end=send)
    def visit(self,m,address,size,user):
        if address==self.base+self.pending_cfg['send']:return
        return super().visit(m,address,size,user)
    def before_send(self,m,address,size,user):
        x=self.x;start=self.base+self.fill_cfg['request']
        if (m.reg_read(x.UC_X86_REG_RCX),m.reg_read(x.UC_X86_REG_RDX),m.reg_read(x.UC_X86_REG_R8))!=(start-32,start,start+240):raise ValueError('SEND_BOUNDARY_ARGUMENTS_DIFFER')
        self.ready=True;m.emu_stop()
    def write(self,m,access,address,size,value,user):
        if not self.executing:return
        start=self.base+self.fill_cfg['request']
        if start<=address and address+size<=start+628:return
        for key,n in [('magic',8)]:
            if self.base+self.pending_cfg[key]<=address and address+size<=self.base+self.pending_cfg[key]+n:return
        return super().write(m,access,address,size,value,user)
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;r=self.case
        if api in [100,101]:return fill.entry.Original.call(self,m,address,size,user)
        if api in [31,32]:
            prop=m.reg_read(x.UC_X86_REG_R8)&0xffffffff;text=self.text(m.reg_read(x.UC_X86_REG_RDX))
            if api==31:
                if prop==33:
                    if self.execution_index>=2:raise ValueError('EXTRA_EXECUTION_READ')
                    value=r['execution'+str(self.execution_index)];self.execution_index+=1
                elif prop==50:
                    if self.filling_index>=2:raise ValueError('EXTRA_FILLING_READ')
                    value=r['filling'+str(self.filling_index)];self.filling_index+=1
                elif prop==49:value=r['auto_expiration']
                else:raise ValueError('UNEXPECTED_DIRECT_PROPERTY '+str(prop))
                m.reg_write(x.UC_X86_REG_RAX,value&MASK);self.mix(1,prop,fill.entry.text_hash(text),value,1)
            else:
                if prop==71:value,ok=r['order_flags'],r['order_ok']
                elif prop==49:
                    if self.expiration_index>=2:raise ValueError('EXTRA_EXPIRATION_READ')
                    value=r['expiration'+str(self.expiration_index)];ok=r['expiration_ok'+str(self.expiration_index)];self.expiration_index+=1
                else:raise ValueError('UNEXPECTED_REF_PROPERTY '+str(prop))
                m.mem_write(m.reg_read(x.UC_X86_REG_R9),struct.pack('<q',value));m.reg_write(x.UC_X86_REG_RAX,ok);self.mix(2,prop,fill.entry.text_hash(text),value,ok)
        elif api==33:
            opcode=m.reg_read(x.UC_X86_REG_RDX);count=m.reg_read(x.UC_X86_REG_R8);tag=m.reg_read(x.UC_X86_REG_R9);sp=m.reg_read(x.UC_X86_REG_RSP)
            if tag!=0x590008:raise ValueError('UNEXPECTED_MESSAGE_TYPE')
            first=self.text(struct.unpack('<Q',m.mem_read(sp+40,8))[0]);second=''
            if count==2:
                if struct.unpack('<I',m.mem_read(sp+48,4))[0]!=0x590008:raise ValueError('SECOND_MESSAGE_TYPE')
                second=self.text(struct.unpack('<Q',m.mem_read(sp+56,8))[0])
            if opcode==2 and count==1:self.mix(3,0,fill.entry.text_hash(first),0,0)
            elif opcode==2 and count==2:self.mix(4,0,fill.entry.text_hash(first),fill.entry.text_hash(second),0)
            elif opcode==13 and count==2:self.mix(5,0,fill.entry.text_hash(first),fill.entry.text_hash(second),0)
            else:raise ValueError('UNEXPECTED_MESSAGE '+str((opcode,count)))
        else:raise ValueError('UNEXPECTED_API '+str(api))
    def state_bytes(self):
        start=self.base+self.fill_cfg['request'];out=bytearray(self.m.mem_read(self.base+self.pending_cfg['magic'],8))
        out+=bytes(self.m.mem_read(self.base+self.fill_cfg['preferred'],4))
        for key,offset in self.layout['relative_native_storage_bases'].items():
            for field in self.layout['layouts'][key]['fields']:
                pointer=start+offset+field['offset'];kind=field['kind']
                if kind=='s':out+=struct.pack('<Q',fill.entry.text_hash(self.text(pointer)))
                else:out+=bytes(self.m.mem_read(pointer,struct.calcsize('<'+kind)))
        if len(out)!=260:raise ValueError('STATE_SERIALIZATION_SIZE '+str(len(out)))
        return out
    def run(self,row):
        self.executing=False;m,x=self.m,self.x;self.case=row;self.cursor=0x70001000;self.allocs=self.frees=0;self.count=0;self.hash=0xcbf29ce484222325;self.trace=[];self.ready=False
        self.execution_index=self.filling_index=self.expiration_index=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.mem_write(0x50000000,b'\0'*0x20000)
        start=self.base+self.fill_cfg['request'];m.mem_write(start,b'\x5a'*628)
        for key,offset in self.layout['relative_native_storage_bases'].items():
            for field in self.layout['layouts'][key]['fields']:
                pointer=start+offset+field['offset'];kind=field['kind'];value=field['value']
                raw=struct.pack('<IQ',0,self.string(value)) if kind=='s' else struct.pack('<'+kind,value)
                m.mem_write(pointer,raw)
        m.mem_write(self.base+self.fill_cfg['preferred'],struct.pack('<i',row['preferred']))
        m.mem_write(self.base+self.fill_cfg['chart'],struct.pack('<IQ',0,self.string('XAUUSD_NOCOST_V2')))
        cfg=self.pending_cfg
        m.mem_write(self.base+cfg['stopped'],struct.pack('<i',row['stopped']));m.mem_write(self.base+cfg['virtual'],bytes([row['virtual']]))
        m.mem_write(self.base+cfg['magic_input'],struct.pack('<i',row['strategy_magic']));m.mem_write(self.base+cfg['magic'],struct.pack('<Q',0x7654321076543210))
        symbol=0x70000000;comment=0x70000020
        m.mem_write(symbol,struct.pack('<IQ',0,0 if row['symbol_kind']==2 else self.string(fill.symbol_text(row['symbol_kind']))))
        comment_text=['Recovery','','','Vé kiểm'][row['comment_kind']]
        m.mem_write(comment,struct.pack('<IQ',0,0 if row['comment_kind']==2 else self.string(comment_text)))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.reg_write(x.UC_X86_REG_RCX,symbol);m.reg_write(x.UC_X86_REG_RDX,row['type']&0xffffffff)
        m.reg_write(x.UC_X86_REG_XMM2,bits(row['volume']));m.reg_write(x.UC_X86_REG_XMM3,bits(row['price']))
        m.mem_write(top+40,struct.pack('<2dQq',row['sl'],row['tp'],comment,row['expiration']))
        self.executing=True
        try:m.emu_start(self.base+cfg['fn'],0x60000000,timeout=5000000,count=200000)
        finally:self.executing=False
        if not self.ready and m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise ValueError('NATIVE_DID_NOT_RETURN_OR_REACH_SEND')
        if not self.ready and m.reg_read(x.UC_X86_REG_RAX)&255:raise ValueError('RETURNED_SUCCESS_WITHOUT_SEND')
        if self.allocs or self.frees:raise ValueError('UNEXPECTED_ALLOCATED_STRING')
        if not row['stopped']:
            for offset,size in [(128,112),(312,124),(500,128)]:
                if bytes(m.mem_read(start+offset,size))!=b'\0'*size:raise ValueError('NATIVE_RESERVED_STORAGE_NOT_CLEARED')
        return struct.pack('<2i',row['id'],int(self.ready))+self.state_bytes()+struct.pack('<iQ',self.count,self.hash)

def verify_build(bot,build):
    if not build or not re.fullmatch('[a-z0-9-]+',build):raise ValueError('BUILD_REQUIRED')
    path=ROOT/f'bot-cua-toi-{bot}/bang-chung/bien-dich'/build/'bien-nhan.json';d=json.loads(path.read_text(encoding='utf-8-sig'))
    target=f'Scripts/bot-cua-toi-{bot}/Bot{bot}PendingRequestCheck.mq5';script=MT/'MQL5'/target.replace('.mq5','.ex5')
    if d['target']!=target or d['errors'] or d['warnings'] or sha(script)!=d['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
    for name in [target,f'Include/bot-cua-toi-{bot}/Bot{bot}PendingRequest.mqh',f'Include/bot-cua-toi-{bot}/Bot{bot}Filling.mqh']:
        if sha(ROOT/f'bot-cua-toi-{bot}/source/MQL5'/name)!=d['sources_sha256'][name]:raise ValueError('SOURCE_CHANGED '+name)
    return path,script
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-tao-yeu-cau-cho'/a.run
    if a.mode=='prepare':
        digest=fill.validation.original_hash(a.bot);out.mkdir(parents=True,exist_ok=False);rows=cases();(out/'cases.bin').write_bytes(encode(rows))
        save(out/'cases.json',[{**r,**{k:struct.pack('<d',r[k]).hex() for k in ['volume','price','sl','tp']}} for r in rows])
        save(out/'baseline.json',dict(original_ex5_sha256=digest,cases=len(rows),cases_sha256=sha(out/'cases.bin'),tool_sha256=sha(Path(__file__)),layout_sha256=sha(LAYOUT)))
        print(json.dumps({'cases':len(rows)}));return
    rows=read_cases(out/'cases.bin');baseline=json.loads((out/'baseline.json').read_text())
    if sha(out/'cases.bin')!=baseline['cases_sha256'] or sha(LAYOUT)!=baseline['layout_sha256']:raise ValueError('INPUT_OR_LAYOUT_CHANGED')
    if a.mode=='original':
        if fill.validation.original_hash(a.bot)!=baseline['original_ex5_sha256']:raise ValueError('ORIGINAL_CHANGED')
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        o=Original(a.bot);started=time.monotonic();values=[];traces=[]
        for row in rows:
            try:values.append(o.run(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} {error}') from error
            if row['id']<20 or row['id']>=len(rows)-20:traces.append(dict(id=row['id'],calls=o.trace))
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,1,len(values))+b''.join(values));save(out/'native-trace-sample.json',traces)
        save(out/'original-run.json',dict(cases=len(values),seconds=round(time.monotonic()-started,2),native_rva=hex(CFG[a.bot]['fn']),send_boundary_rva=hex(CFG[a.bot]['send']),result_sha256=sha(out/'original-results.bin'),tool_sha256=sha(Path(__file__)),scope=__doc__))
        print(json.dumps({'cases':len(values)}));return
    if a.mode=='mql5':
        receipt,script=verify_build(a.bot,a.build)
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-pending-request'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}-pending.set'
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        ini=MT/f'b{a.bot}-{a.run}-pending.ini'
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\n'+f'Script=bot-cua-toi-{a.bot}\\Bot{a.bot}PendingRequestCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        started=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_CHECK_TIMEOUT')
        if code or not (files/'mql5-results.bin').exists():raise RuntimeError('MT5_CHECK_FAILED '+str(code))
        shutil.copyfile(files/'mql5-results.bin',out/'mql5-results.bin')
        save(out/'mql5-run.json',dict(exit_code=code,seconds=round(time.monotonic()-started,2),script_sha256=sha(script),build_receipt_sha256=sha(receipt),results_sha256=sha(out/'mql5-results.bin')))
        print(json.dumps({'cases':len(read_results(out/'mql5-results.bin'))}));return
    original=read_results(out/'original-results.bin');actual=read_results(out/'mql5-results.bin')
    if len(original)!=len(rows) or len(actual)!=len(rows):raise ValueError('RESULT_COUNT_MISMATCH')
    failures=[]
    for i,(x,y) in enumerate(zip(original,actual)):
        if x!=y:
            n=next(k for k in range(280) if x[k]!=y[k]);failures.append(dict(id=i,first_differing_byte=n,original=x[n:n+8].hex(),mql5=y[n:n+8].hex()))
    result=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:20],hashes={n:sha(out/n) for n in ['cases.bin','original-results.bin','mql5-results.bin']},scope='Preparation up to the send wrapper, not actual order submission:35 calibrated struct fields plus magic/preferred and ordered API/messages. Both native filling checks and string helpers execute. Initial struct strings supplied as non-owning literals; allocation failures and send/result/queue behavior remain open.')
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))
if __name__=='__main__':main()
