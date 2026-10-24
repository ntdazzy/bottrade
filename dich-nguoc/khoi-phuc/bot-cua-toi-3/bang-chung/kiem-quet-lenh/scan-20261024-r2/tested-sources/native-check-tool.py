"""Compare original order counters,100-row cleanup and account order limit.

Usage: kiem-quet-lenh-bot-1-3.py prepare|original|mql5|compare BOT RUN [--build BUILD]
Queries are supplied, not real account data; no send/modify/close calls exist.
All200 table doubles,return,last ticket,selection model and ordered API records
are compared. Native conversion executes unchanged, including NaN/inf cases.
"""
import argparse
import copy
import importlib.util
import json
import math
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x53434e31;ENUMS=[15,4,0,47,4,5]
spec=importlib.util.spec_from_file_location('entry',Path(__file__).with_name('kiem-gia-vao-bot-1-3.py'))
entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
spec=importlib.util.spec_from_file_location('validation',Path(__file__).with_name('kiem-khoi-luong-hop-le-bot-1-3.py'))
validation=importlib.util.module_from_spec(spec);spec.loader.exec_module(validation)
MT=entry.MT;sha=entry.sha;pack_text=entry.pack_text;MASK=(1<<64)-1
CFG={1:dict(functions={0:0x31f40,1:0x323e0,2:0x32ce0},results=0x65dd0,magic=0x6246c,ticket=0x677f8,symbol=0x67918,slot=0x6a43c),
     3:dict(functions={2:0x3e490,3:0x47330},results=0x72e10,magic=0x6d564,ticket=0x74838,symbol=0x74958,slot=0x1d6e3c)}

def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2,allow_nan=False)
def dependencies(bot):
    home=ROOT/f'bot-cua-toi-{bot}';folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
    capture=home/'bang-chung/captures/luot-20261023-r1/capture.json'
    paths=[Path(__file__),Path(entry.__file__),Path(entry.price_check.__file__),Path(validation.__file__),Path(validation.volume.__file__),home/'phan-tich'/folder/'metadata/import.json',capture,home/'bang-chung/luot-20261023-r1/engine-observed.json']
    paths.extend(capture.parent/region['file'] for region in json.loads(capture.read_text())['regions'])
    runtime=ROOT.parent/'.local/claude-recovery-20261023/python/unicorn'
    paths.extend(path for path in runtime.rglob('*') if path.is_file() and path.suffix in ['.py','.dll'])
    return {(path.relative_to(ROOT).as_posix() if path.is_relative_to(ROOT) else '../'+path.relative_to(ROOT.parent).as_posix()):sha(path) for path in paths}
def from_bits(bits):return struct.unpack('<d',struct.pack('<Q',bits))[0]
def base(kind):
    return dict(id=0,kind=kind,scenario=0,magic=42,symbol_null=0,selected_order=-1,selected_position=-1,prior_ticket=0x1234567890abcdef,limit=0,symbol='XAUUSD',
                totals=[2]*100 if kind==2 else [2],orders=[[11,42,4,0,'XAUUSD'],[12,42,5,0,'XAUUSD']],positions=[1,2,3],results=[[float(i+1),-i-.25] for i in range(100)])
def cases(bot):
    rows=[]
    def add(row,group):row.update(id=len(rows),group=group);rows.append(row)
    if bot==1:
        for kind in [0,1]:
            for total in [-2,-1,0,1,2,3]:
                row=base(kind);row['totals']=[total];add(row,'count-index-boundary')
            for magic in [-2147483648,-1,0,42,2147483647]:
                for actual in [magic,magic+(1<<32),-1,0,42]:
                    row=base(kind);row['magic']=magic;row['orders']=[[11,actual,4+kind,0,'XAUUSD']];row['totals']=[1];add(row,'signed-magic-width')
            for symbol,null in [('',0),('',1),('Vàng',0),('XAUUSD',0),('xauusd',0)]:
                for actual,actual_null in [('',0),('',1),('Vàng',0),('XAUUSD',0),('xauusd',0)]:
                    row=base(kind);row.update(symbol=symbol,symbol_null=null,orders=[[11,42,4+kind,actual_null,actual]],totals=[1]);add(row,'symbol-and-null')
            for ticket in [0,1,(1<<53)+1,(1<<64)-1]:
                for type_ in [-1,0,1,4,5,6,0x100000004]:
                    row=base(kind);row['orders']=[[ticket,42,type_,0,'XAUUSD']];row['totals']=[1];add(row,'ticket-and-order-type')
            for scenario in [3,4,5]:
                row=base(kind);row.update(scenario=scenario,orders=[[11,-1 if scenario==3 else 42,4+kind,0,'Renamed' if scenario==3 else 'XAUUSD']],totals=[1]);add(row,'count-rereads')
            row=base(kind);row.update(orders=[[11,42,4+kind,0,'XAUUSD']]*5,totals=[4]);add(row,'count-all-indices-inclusive')
    special=[0.,-0.,12.9,-12.9,math.nextafter(float(1<<63),0.),float(1<<63),-float(1<<63),math.nextafter(-float(1<<63),-math.inf),float((1<<53)+1),math.inf,-math.inf]
    special += [from_bits(x) for x in [0x7ff8000000000123,0xfff8000000000456,0x7ff0000000000789,0xfff0000000000abc]]
    for total in [-2,-1,0,1,2,4]:
        for positions in [[],[0],[12],[12,7,0],[7,0,12],[0x8000000000000000]]:
            row=base(2);row.update(totals=[total]*100,positions=positions);row['results'][0]=[12.9,-0.];add(row,'cleanup-count-and-no-early-break')
    for value in special:
        for position in [0,12,0x8000000000000000,0x7fffffffffffffff,(1<<53)+1,1<<53]:
            row=base(2);row.update(positions=[position],totals=[0]*100);row['results'][0]=[value,from_bits(0xfff8000000000456)];row['results'][99]=[value,-0.];add(row,'cleanup-number-conversion')
    for totals in [[-1,2]*50,[2,-1]*50,[-1,0,1,2]*25]:
        row=base(2);row.update(totals=totals,positions=[1,2,3]);add(row,'cleanup-total-read-each-row')
    for scenario in [1,2]:
        row=base(2);row.update(scenario=scenario,positions=[12],totals=[0]+[-1]*99);row['results'][0]=[12.9,-7.5];add(row,'cleanup-convert-before-api-mutation')
    if bot==3:
        for limit in [-1,0,1,2,2147483647,-2147483648,0x100000000,0x100000001,0x1ffffffff,-0x100000001,0x7fffffffffffffff,-0x8000000000000000]:
            narrowed=struct.unpack('<i',struct.pack('<I',limit&0xffffffff))[0]
            for total in [-2147483648,-1,0,1,2,3,2147483647]:
                row=base(3);row.update(limit=limit,totals=[] if narrowed==0 else [total]);add(row,'account-limit-low-signed32')
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for row in rows:
        raw+=struct.pack('<7iQq',*(row[k] for k in ['id','kind','scenario','magic','symbol_null','selected_order','selected_position']),row['prior_ticket'],row['limit'])+pack_text(row['symbol'])
        raw+=struct.pack('<i',len(row['totals']))+struct.pack('<'+'i'*len(row['totals']),*row['totals'])+struct.pack('<i',len(row['orders']))
        for ticket,magic,type_,null,symbol in row['orders']:raw+=struct.pack('<Qqqi',ticket,magic,type_,null)+pack_text(symbol)
        raw+=struct.pack('<i',len(row['positions']))+struct.pack('<'+'Q'*len(row['positions']),*row['positions'])
        raw+=b''.join(struct.pack('<2d',*values) for values in row['results'])
    return raw
class Reader:
    def __init__(self,raw):self.raw=raw;self.pos=0
    def take(self,fmt):
        value=struct.unpack_from('<'+fmt,self.raw,self.pos);self.pos+=struct.calcsize('<'+fmt);return value
    def block(self,n):
        if n<0 or self.pos+n>len(self.raw):raise ValueError('TRUNCATED_RECORD')
        value=self.raw[self.pos:self.pos+n];self.pos+=n;return value
    def text(self):
        n=self.take('i')[0]
        if not 0<=n<=4096:raise ValueError('BAD_STRING_LENGTH')
        return self.block(2*n).decode('utf-16-le')
def read_cases(path):
    rd=Reader(path.read_bytes());magic,version,n=rd.take('3i')
    if (magic,version)!=(MAGIC,1):raise ValueError('BAD_CASE_HEADER')
    rows=[]
    for i in range(n):
        row=dict(zip(['id','kind','scenario','magic','symbol_null','selected_order','selected_position','prior_ticket','limit'],rd.take('7iQq')));row['symbol']=rd.text()
        count=rd.take('i')[0]
        if not 0<=count<=100:raise ValueError('BAD_TOTAL_COUNT')
        row['totals']=list(rd.take('i'*count));count=rd.take('i')[0]
        if not 0<=count<=100:raise ValueError('BAD_ORDER_COUNT')
        row['orders']=[[*rd.take('Qqqi'),rd.text()] for _ in range(count)];count=rd.take('i')[0]
        if not 0<=count<=100:raise ValueError('BAD_POSITION_COUNT')
        row['positions']=list(rd.take('Q'*count));row['results']=[list(rd.take('2d')) for _ in range(100)]
        if row['id']!=i:raise ValueError('CASE_IDS_DIFFER')
        rows.append(row)
    if rd.pos!=len(rd.raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return rows
def header(n):return struct.pack('<4i6i',MAGIC,1,n,6,*ENUMS)
def read_results(path,n):
    rd=Reader(path.read_bytes())
    if rd.block(40)!=header(n):raise ValueError('RESULT_HEADER_OR_ENUM_DIFFERS')
    rows=[]
    for i in range(n):
        start=rd.pos
        if rd.take('i')[0]!=i:raise ValueError('RESULT_IDS_DIFFER')
        while True:
            api=rd.take('i')[0]
            if api==0:break
            if api==1:rd.take('i')
            elif api in [2,5]:rd.take('iQi')
            elif api in [3,6]:rd.take('iq')
            elif api==4:rd.take('i');rd.text()
            else:raise ValueError('UNKNOWN_TRACE_EVENT')
        rd.take('iQ4i');rd.text();rd.block(1600);rows.append(rd.raw[start:rd.pos])
    if rd.pos!=len(rd.raw):raise ValueError('RESULT_BYTES_NOT_EXACT')
    return rows

class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.bot=bot;self.scan=CFG[bot]
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data';self.meta_path=ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json';meta=json.loads(self.meta_path.read_text())
        self.ranges=[(rva,int(next(f['end_rva'] for f in meta['functions'] if int(f['begin_rva'],16)==rva),16)) for rva in [0,0x60,0x4a0,0x5c0,*self.scan['functions'].values()]]
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40;extra={eb+0x7d7df0:9,eb+0x7973c0:10}
        for address,api in extra.items():
            page=address&~4095
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit);self.m.hook_add(self.uc.UC_HOOK_MEM_WRITE,self.write_guard)
    def visit(self,m,address,size,user):
        if address not in self.apis and not any(self.base+a<=address<self.base+b for a,b in self.ranges):raise ValueError('NATIVE_LEFT_CHECKED_FUNCTIONS '+hex(address-self.base))
    def write_guard(self,m,access,address,size,value,user):
        if not self.executing:return
        for begin,length in [(0x50000000,0x20000),(0x70000000,0x200000),(self.base+self.scan['ticket'],8),(self.base+self.scan['slot'],12),(self.base+self.scan['results'],1600)]:
            if begin<=address and address+size<=begin+length:return
        raise ValueError('UNEXPECTED_NATIVE_STATE_WRITE '+hex(address-self.base))
    def change(self,api):
        row=self.case;self.executing=False
        try:
            if (api==1 and self.total_index==1 and row['scenario']==1) or (api==5 and self.position_calls==1 and row['scenario']==2):
                values=(99.9,-7.5) if api==1 else (88.75,.125);self.m.mem_write(self.base+self.scan['results'],struct.pack('<2d',*values))
            if api==2 and self.order_calls==1 and row['scenario']==3:
                self.m.mem_write(self.base+self.scan['magic'],struct.pack('<i',-1));self.m.mem_write(self.base+self.scan['symbol'],struct.pack('<IQ',0,self.string('Renamed')))
            if api==3 and self.integer_calls==1 and row['scenario']==4:self.m.mem_write(self.base+self.scan['magic'],struct.pack('<i',43))
            if api==4 and self.string_calls==1 and row['scenario']==5:self.m.mem_write(self.base+self.scan['symbol'],struct.pack('<IQ',0,self.string('Renamed')))
        finally:self.executing=True
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;row=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        if api==4:
            if self.total_index>=len(row['totals']):raise ValueError('EXTRA_ORDERS_TOTAL')
            value=row['totals'][self.total_index];self.total_index+=1;m.reg_write(x.UC_X86_REG_RAX,value&MASK);self.trace_bytes+=struct.pack('<2i',1,value);self.change(1);return
        if api in [5,9]:
            index=struct.unpack('<i',struct.pack('<I',m.reg_read(x.UC_X86_REG_RDX)&0xffffffff))[0];values=row['orders'] if api==5 else row['positions'];value=0
            if 0<=index<len(values):value=values[index][0] if api==5 else values[index]
            if value:
                if api==5:self.selected=index
                else:self.selected_position=index
            m.reg_write(x.UC_X86_REG_RAX,value);event=2 if api==5 else 5;selected=self.selected if api==5 else self.selected_position
            self.trace_bytes+=struct.pack('<2iQi',event,index,value,selected)
            if api==5:self.order_calls+=1
            else:self.position_calls+=1
            self.change(event);return
        prop=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
        if api==10:
            if prop!=47:raise ValueError('ACCOUNT_PROPERTY_DIFFERS')
            value=row['limit'];m.reg_write(x.UC_X86_REG_RAX,value&MASK);self.trace_bytes+=struct.pack('<2iq',6,prop,value);return
        if api not in [6,7] or self.selected<0:raise ValueError('INVALID_SELECTED_ORDER_OR_API')
        order=row['orders'][self.selected]
        if api==6:
            if prop not in [15,4]:raise ValueError('ORDER_INTEGER_PROPERTY_DIFFERS')
            value=order[1 if prop==15 else 2];m.reg_write(x.UC_X86_REG_RAX,value&MASK);self.trace_bytes+=struct.pack('<2iq',3,prop,value);self.integer_calls+=1;self.change(3)
        else:
            if prop!=0:raise ValueError('ORDER_STRING_PROPERTY_DIFFERS')
            pointer=0 if order[3] else self.string(order[4]);m.mem_write(self.base+self.scan['slot'],struct.pack('<IQ',0,pointer));self.trace_bytes+=struct.pack('<2i',4,prop)+pack_text(order[4]);self.string_calls+=1;self.change(4)
    def run_scan(self,row):
        m,x=self.m,self.x;self.case=row;self.executing=False;self.cursor=0x70001000;self.allocs=self.frees=0;self.total_index=self.order_calls=self.integer_calls=self.string_calls=self.position_calls=0
        self.selected=row['selected_order'];self.selected_position=row['selected_position'];self.trace_bytes=bytearray()
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        m.mem_write(self.base+self.scan['slot'],b'\0'*12);m.mem_write(self.base+self.scan['magic'],struct.pack('<i',row['magic']));m.mem_write(self.base+self.scan['ticket'],struct.pack('<Q',row['prior_ticket']))
        m.mem_write(self.base+self.scan['symbol'],struct.pack('<IQ',0,0 if row['symbol_null'] else self.string(row['symbol'])))
        m.mem_write(self.base+self.scan['results'],b''.join(struct.pack('<2d',*values) for values in row['results']))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);self.executing=True
        try:m.emu_start(self.base+self.scan['functions'][row['kind']],0x60000000,timeout=5000000,count=4000000)
        finally:self.executing=False
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000 or self.allocs!=self.frees or self.total_index!=len(row['totals']):raise ValueError('NATIVE_RUN_NOT_COMPLETE_OR_MEMORY_BALANCED')
        value=0 if row['kind']==2 else (int(bool(m.reg_read(x.UC_X86_REG_RAX)&255)) if row['kind']==3 else struct.unpack('<i',struct.pack('<I',m.reg_read(x.UC_X86_REG_EAX)))[0])
        pointer=struct.unpack('<Q',m.mem_read(self.base+self.scan['symbol']+4,8))[0];symbol='' if not pointer else bytes(m.mem_read(pointer,struct.unpack('<I',m.mem_read(pointer-4,4))[0]*2)).decode('utf-16-le')
        ticket=struct.unpack('<Q',m.mem_read(self.base+self.scan['ticket'],8))[0];magic=struct.unpack('<i',m.mem_read(self.base+self.scan['magic'],4))[0]
        return struct.pack('<i',row['id'])+self.trace_bytes+struct.pack('<2iQ4i',0,value,ticket,self.selected,self.selected_position,self.total_index,magic)+pack_text(symbol)+bytes(m.mem_read(self.base+self.scan['results'],1600))

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    home=ROOT/f'bot-cua-toi-{a.bot}';out=home/'bang-chung/kiem-quet-lenh'/a.run
    if a.mode=='prepare':
        digest=validation.original_hash(a.bot);out.mkdir(parents=True,exist_ok=False);rows=cases(a.bot);(out/'cases.bin').write_bytes(encode(rows));description=copy.deepcopy(rows)
        for row in description:row['results']=[[struct.pack('<d',value).hex() for value in values] for values in row['results']]
        save(out/'cases.json',description);save(out/'baseline.json',dict(cases=len(rows),cases_sha256=sha(out/'cases.bin'),original_ex5_sha256=digest,tool_sha256=sha(Path(__file__))));print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((out/'baseline.json').read_text());rows=read_cases(out/'cases.bin');n=len(rows)
    if baseline['cases_sha256']!=sha(out/'cases.bin') or baseline['original_ex5_sha256']!=validation.original_hash(a.bot):raise ValueError('INPUT_OR_ORIGINAL_CHANGED')
    if a.mode=='original':
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        o=Original(a.bot);start=time.monotonic();values=[]
        for row in rows:
            try:values.append(o.run_scan(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
        (out/'original-results.bin').write_bytes(header(n)+b''.join(values));save(out/'original-run.json',dict(cases=n,seconds=round(time.monotonic()-start,2),result_sha256=sha(out/'original-results.bin'),tool_sha256=sha(Path(__file__)),dependencies_sha256=dependencies(a.bot),metadata_sha256=sha(o.meta_path),scope=__doc__));print(json.dumps({'cases':n}));return
    if a.mode=='mql5':
        if not a.build or not re.fullmatch('[a-z0-9-]+',a.build):raise ValueError('BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}OrderScanCheck.mq5';binary=MT/'MQL5'/target.replace('.mq5','.ex5')
        if receipt['target']!=target or receipt['errors'] or receipt['warnings'] or sha(binary)!=receipt['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
        names=[target,f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}OrderScan.mqh']
        for name in names:
            if sha(home/'source/MQL5'/name)!=receipt['sources_sha256'][name] or sha(MT/'MQL5'/name)!=receipt['sources_sha256'][name]:raise ValueError('TESTED_SOURCE_CHANGED')
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-order-scan'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-scan-{a.run}.set';preset.write_text(f'CheckRun={a.run}\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-scan-{a.run}.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}OrderScanCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_SCAN_TIMEOUT')
        if code:raise RuntimeError('MT5_SCAN_FAILED '+str(code))
        for name in ['mql5-results.bin','script-status.bin']:shutil.copyfile(files/name,out/name)
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,n):raise ValueError('SCRIPT_DID_NOT_COMPLETE')
        save(out/'mql5-run.json',dict(cases=n,exit_code=code,seconds=round(time.monotonic()-start,2),script_sha256=sha(binary),build_receipt=receipt_path.relative_to(ROOT).as_posix(),build_receipt_sha256=sha(receipt_path),sources_sha256={name:receipt['sources_sha256'][name] for name in names},hashes={name:sha(out/name) for name in ['mql5-results.bin','script-status.bin']}));print(json.dumps({'cases':n}));return
    mql=json.loads((out/'mql5-run.json').read_text());native=json.loads((out/'original-run.json').read_text());receipt_path=ROOT/mql['build_receipt'];receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    if sha(receipt_path)!=mql['build_receipt_sha256'] or receipt['errors'] or receipt['warnings'] or receipt['binary_sha256']!=mql['script_sha256'] or sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name)!=mql['script_sha256']:raise ValueError('BUILD_EVIDENCE_CHANGED')
    for name,digest in mql['sources_sha256'].items():
        if sha(home/'source/MQL5'/name)!=digest:raise ValueError('CURRENT_SOURCE_CHANGED')
    for name,digest in mql['hashes'].items():
        if sha(out/name)!=digest:raise ValueError('MQL5_EVIDENCE_CHANGED')
    if sha(out/'original-results.bin')!=native['result_sha256'] or sha(Path(__file__))!=native['tool_sha256']:raise ValueError('NATIVE_EVIDENCE_CHANGED')
    if native['dependencies_sha256']!=dependencies(a.bot):raise ValueError('NATIVE_DEPENDENCIES_CHANGED')
    if baseline['tool_sha256']!=native['tool_sha256'] or encode(cases(a.bot))!=(out/'cases.bin').read_bytes():raise ValueError('CASE_GENERATOR_OR_PREPARATION_TOOL_CHANGED')
    actual=read_results(out/'mql5-results.bin',n);expected=read_results(out/'original-results.bin',n);failures=[]
    for i,(x,y) in enumerate(zip(expected,actual)):
        if x!=y:
            pos=next((i for i,(a_,b_) in enumerate(zip(x,y)) if a_!=b_),min(len(x),len(y)));failures.append(dict(id=i,first_different_byte=pos,original=x[pos:pos+20].hex(),mql5=y[pos:pos+20].hex()))
    groups={}
    for row in rows:
        group=groups.setdefault(str(row['kind']),dict(cases=0,matched=0));group['cases']+=1;group['matched']+=int(expected[row['id']]==actual[row['id']])
    result=dict(cases=n,matched=n-len(failures),failed=len(failures),groups=groups,first_failures=failures[:12],hashes={name:sha(out/name) for name in ['cases.bin','original-results.bin','mql5-results.bin','script-status.bin']},whole_bot_complete=False,scope=__doc__)
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))

if __name__=='__main__':main()
