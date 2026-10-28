"""Compare complete native AmericanDST functions with reconstructed MQL5.

Usage: kiem-gio-mua-he-bot-2.py prepare|mql5|original|compare RUN [--build BUILD]
Run mql5 before original: actual MT5 math/calendar/string outputs are supplied at
native API boundaries. Every argument and call order is checked independently.
The original arithmetic, branches, string-copy/destruction and final result run.
Clock values and explicit conversion-failure injections are test data. No orders.
"""
import argparse
import calendar
from datetime import datetime, timedelta, timezone
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
MT=ROOT.parent/'.local/mt5-bot1-thread-20261025'
MAGIC=0x44535431
MASK=(1<<64)-1
BOT=2
FN=0x17440
CODE_SHA='ae4e9020f7f5f08d49774728bed14c17eb2bd26b6271c20da51bd3aaa446014f'
DST_SHA='387ac43a69b29852283f875ee393710e7cca3fb785dcfddbff71d48ce953e3a7'
EX5_SHA='390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795'
spec=importlib.util.spec_from_file_location('dst_entry',Path(__file__).with_name('kiem-gia-vao-bot-1-3.py'))
entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
spec=importlib.util.spec_from_file_location('dst_validation',Path(__file__).with_name('kiem-khoi-luong-hop-le-bot-1-3.py'))
validation=importlib.util.module_from_spec(spec);spec.loader.exec_module(validation)

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def save(path,value):
    with path.open('x',encoding='utf-8') as stream:json.dump(value,stream,ensure_ascii=False,indent=2)
def hash_bytes(raw):
    h=0xcbf29ce484222325
    for byte in raw:h=((h^byte)*0x100000001b3)&MASK
    return h
def text_hash(value):return hash_bytes(value.encode('utf-16-le'))
def verify_pins():
    capdir=ROOT/'bot-cua-toi-2/bang-chung/captures/luot-20261026-r1';cap=json.loads((capdir/'capture.json').read_text())
    code=next(r for r in cap['regions'] if r['kind']=='executable' and r['base']==0x253f2620000)
    raw=(capdir/code['file']).read_bytes()
    if sha(capdir/code['file'])!=CODE_SHA:raise ValueError('CAPTURE_CODE_SHA_MISMATCH')
    if hashlib.sha256(raw[FN:0x17917]).hexdigest()!=DST_SHA:raise ValueError('DST_FUNCTION_SHA_MISMATCH')
    if not Path(r'C:\Users\NTD\Desktop\BotTradeEA\local\market-demos-20261020\dich-nguoc-luot2\terminal\MQL5\Experts\Market\Goldbot One MT5.ex5').is_file():raise ValueError('INSTALLED_EX5_MISSING')
    if sha(Path(r'C:\Users\NTD\Desktop\BotTradeEA\local\market-demos-20261020\dich-nguoc-luot2\terminal\MQL5\Experts\Market\Goldbot One MT5.ex5'))!=EX5_SHA:raise ValueError('INSTALLED_EX5_SHA_MISMATCH')
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def stamp(year,month,day,seconds=43200):
    return calendar.timegm((year,month,day,0,0,0))+seconds

def cases():
    rows=[]
    def add(group,values,fail=0,zero=0,year=0):
        rows.append(dict(id=len(rows),group=group,clock=values,fail_mask=fail,zero_mask=zero,year_override=year))
    for year in [1986,1987,1999,2000,2006,2007,2024,2026,2099,2100,2400,3000]:
        start=datetime(year,1,1,tzinfo=timezone.utc)
        for day in range(366 if calendar.isleap(year) else 365):
            value=int((start+timedelta(days=day,hours=12)).timestamp())
            add('each-day',[value]*3)
        months=(4,10) if year<2007 else (3,11)
        for month in months:
            sundays=[day for day in range(1,calendar.monthrange(year,month)[1]+1) if calendar.weekday(year,month,day)==6]
            day=(sundays[0] if month in (4,11) else sundays[1] if month==3 else sundays[-1])
            base=stamp(year,month,day,0)
            for delta in [-86400,-1,0,1,7199,7200,7201,86399,86400]:add('boundary-time',[base+delta]*3)
    for year in [1987,2006,2007,2024,2026]:
        for month,day in [(3,1),(6,1),(11,1)]:
            values=[stamp(year,month,day)]*3
            for fail in [2,4,8,16,30]:add('conversion-failure-after-first',values,fail=fail)
            for zero in [1,2,3]:add('date-string-return-zero',values,zero=zero)
    for values in [
        [stamp(2026,10,31),stamp(2026,10,31),stamp(2026,11,1)],
        [stamp(2024,6,1),stamp(2026,6,1),stamp(2024,6,1)],
        [stamp(2006,6,1),stamp(2007,6,1),stamp(2006,6,1)],
        [stamp(2026,12,31),stamp(2027,1,1),stamp(2027,1,1)],
        [stamp(1986,12,31),stamp(1987,6,1),stamp(1987,6,1)],
        [stamp(2026,3,8,86399),stamp(2026,3,9,0),stamp(2026,3,9,1)],
        [stamp(2026,11,1,0),stamp(2026,11,1,0),stamp(2026,10,31,86399)],
    ]:add('clock-changes-between-reads',values)
    for year in [1986,1987,2006,2007,429496729,429496730,536870912,858993459,858993460,1073741823,2147483647]:
        add('supplied-int32-year',[stamp(2026,6,1)]*3,year=year)
    return rows

def encode(rows):
    return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<i3q3i',r['id'],*r['clock'],r['fail_mask'],r['zero_mask'],r['year_override']) for r in rows)
def read_results(path):
    raw=path.read_bytes();magic,version,n=struct.unpack_from('<3i',raw)
    if (magic,version)!=(MAGIC,1) or len(raw)!=12+n*20:raise ValueError('BAD_RESULT_SHAPE')
    return list(struct.iter_unpack('<3iQ',raw[12:]))

def read_fixtures(path,count):
    raw=path.read_bytes();pos=12;rows={i:[] for i in range(count)}
    if raw[:12]!=struct.pack('<3i',MAGIC,1,count):raise ValueError('BAD_FIXTURE_HEADER')
    def take(fmt):
        nonlocal pos
        values=struct.unpack_from('<'+fmt,raw,pos);pos+=struct.calcsize('<'+fmt);return values
    def text():
        nonlocal pos
        n=take('i')[0]
        if not 0<=n<=1000:raise ValueError('BAD_FIXTURE_TEXT_SIZE')
        value=raw[pos:pos+2*n].decode('utf-16-le');pos+=2*n;return value
    while pos<len(raw):
        cid,api=take('2i')
        if cid not in rows:raise ValueError('UNEXPECTED_FIXTURE_CASE')
        if api==1:value=take('q')
        elif api==2:value=(*take('q2i'),struct.pack('<8i',*take('8i')))
        elif api==3:value=take('3Q')
        elif api==4:value=(*take('2i'),text(),text(),text())
        elif api==5:value=(text(),take('q')[0])
        elif api==6:value=(text(),)
        else:raise ValueError('UNEXPECTED_FIXTURE_API')
        rows[cid].append((api,value))
    if pos!=len(raw):raise ValueError('FIXTURE_BYTES_NOT_EXACT')
    return rows

class Original(entry.Original):
    def __init__(self,fixtures):
        # Bot2 uses the 2026-10-26 capture; no bot1/bot3 capture is reused.
        self.fixtures=fixtures
        capdir=ROOT/'bot-cua-toi-2/bang-chung/captures/luot-20261026-r1'
        cap=json.loads((capdir/'capture.json').read_text())
        import sys
        sys.path.insert(0,str(ROOT.parent/'.local/claude-recovery-20261023/python'))
        import unicorn as uc
        from unicorn import x86_const as x
        self.uc,self.x=uc,x;self.m=uc.Uc(uc.UC_ARCH_X86,uc.UC_MODE_64)
        self.regions=[]
        for region in cap['regions']:
            path=capdir/region['file'];raw=path.read_bytes()
            if sha(path)!=region['sha256']:raise ValueError('CAPTURE_HASH_MISMATCH')
            self.m.mem_map(region['base'],region['bytes']);self.m.mem_write(region['base'],raw);self.regions.append((region,raw))
        code=next(v for v in cap['regions'] if v['kind']=='executable' and v['base']==0x253f2620000)
        self.base=code['base']
        metadata=json.loads((ROOT/'bot-cua-toi-2/phan-tich/luot-20261026-data-r2/metadata/import.json').read_text())
        eb=0x7ff79ff60000
        self.apis={eb+0x7d3c40:1,eb+0x7d3cc0:2,eb+0x7c2970:3}
        starts=[0,0x5c0,FN]
        self.ranges=[(int(f['begin_rva'],16),int(f['end_rva'],16)) for f in metadata['functions'] if int(f['begin_rva'],16) in starts]
        if len(self.ranges)!=3:raise ValueError('NATIVE_FUNCTION_MISSING')
        eb=next(p for p,k in self.apis.items() if k==1)-0x7d3c40
        extra={eb+0x7d1c40:21,eb+0x7d1f60:22,eb+0xaa9970:23,eb+0x7b49f0:24,eb+0x7cd370:25,
               eb+0x7d1190:100,eb+0x7d1200:101}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for address in extra:
            self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit)
        self.m.mem_map(0x50000000,0x20000);self.m.mem_map(0x60000000,4096);self.m.mem_map(0x70000000,0x200000)
    def visit(self,m,address,size,user):
        if address not in self.apis and not any(self.base+a<=address<self.base+b for a,b in self.ranges):
            raise ValueError('EXECUTION_OUTSIDE_CHECKED_FUNCTIONS '+hex(address))
    def text(self,descriptor):
        pointer=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if not pointer:return ''
        n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0]
        if n>1000:raise ValueError('BAD_NATIVE_STRING')
        return bytes(self.m.mem_read(pointer,2*n)).decode('utf-16-le')
    def supply_text(self,descriptor,value):
        raw=value.encode('utf-16-le');pointer=self.cursor;self.cursor+=(len(raw)+29)&~15
        self.m.mem_write(pointer,struct.pack('<3I',len(value)+1,1,len(value))+raw+b'\0\0')
        self.live_allocs.add(pointer);self.allocs+=1
        self.m.mem_write(descriptor,struct.pack('<IQ',len(value)+1,pointer+12))
    def next(self,kind):
        if self.position>=len(self.records):raise ValueError('NATIVE_REQUESTED_EXTRA_API '+str(kind))
        api,value=self.records[self.position];self.position+=1
        if api!=kind:raise ValueError(f'API_ORDER_MISMATCH expected_fixture={api} native={kind}')
        return value
    def trace(self,*words):
        raw=struct.pack('<4Q',*(v&MASK for v in words));self.trace_bytes.extend(struct.pack('<i',self.row['id'])+raw)
        for byte in raw:self.call_hash=((self.call_hash^byte)*0x100000001b3)&MASK
        self.call_count+=1
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address]
        if api==100:
            if m.reg_read(x.UC_X86_REG_RCX)!=0x253ee076f88:raise ValueError('STRING_ALLOC_CONTEXT_MISMATCH')
            n=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
            if n>10000:raise ValueError('UNEXPECTED_STRING_ALLOCATION')
            pointer=self.cursor;self.cursor+=(12+(n+1)*2+15)&~15
            if self.cursor>=0x70200000:raise MemoryError('CHECK_HEAP_LIMIT')
            m.mem_write(pointer,struct.pack('<III',n+1,0,0)+b'\0'*((n+1)*2));m.reg_write(x.UC_X86_REG_RAX,pointer);self.live_allocs.add(pointer);self.allocs+=1;return
        if api==101:
            if m.reg_read(x.UC_X86_REG_RCX)!=0x253ee076f88:raise ValueError('STRING_FREE_CONTEXT_MISMATCH')
            pointer=m.reg_read(x.UC_X86_REG_RDX)
            if pointer not in self.live_allocs:raise ValueError('STRING_FREE_POINTER_NOT_LIVE')
            self.live_allocs.remove(pointer)
            self.frees+=1;return
        if api==21:
            if m.reg_read(x.UC_X86_REG_RCX)!=0x253ee076f88:raise ValueError('TIMECURRENT_CONTEXT_MISMATCH')
            value=self.next(1)[0]
            if m.reg_read(x.UC_X86_REG_RDX)!=0 or value!=self.row['clock'][self.now_index]:raise ValueError('CLOCK_INPUT_MISMATCH')
            m.reg_write(x.UC_X86_REG_RAX,value&MASK);self.trace(1,self.now_index,value,0);self.now_index+=1
        elif api==22:
            if m.reg_read(x.UC_X86_REG_RCX)!=0x253ee076f88:raise ValueError('TIMETOSTRUCT_CONTEXT_MISMATCH')
            value,forced,ok,result=self.next(2);pointer=m.reg_read(x.UC_X86_REG_R8)
            if m.reg_read(x.UC_X86_REG_RDX)!=(value&MASK):raise ValueError('TIME_TO_STRUCT_ARGUMENT_MISMATCH')
            if forced:
                if bytes(m.mem_read(pointer,32))!=result:raise ValueError('FAILED_CONVERSION_CHANGED_STRUCT')
            else:m.mem_write(pointer,result)
            m.reg_write(x.UC_X86_REG_RAX,ok);self.trace(2,value,ok,hash_bytes(result))
        elif api==23:
            a,b,result=self.next(3)
            if (m.reg_read(x.UC_X86_REG_XMM0)&MASK,m.reg_read(x.UC_X86_REG_XMM1)&MASK)!=(a,b):raise ValueError('MATH_MOD_ARGUMENT_MISMATCH')
            m.reg_write(x.UC_X86_REG_XMM0,result);self.trace(3,a,b,result)
        elif api==24:
            if m.reg_read(x.UC_X86_REG_RCX)!=0x253ee076f88:raise ValueError('DISPATCH_CONTEXT_MISMATCH')
            opcode=m.reg_read(x.UC_X86_REG_RDX);count=m.reg_read(x.UC_X86_REG_R8);tag=m.reg_read(x.UC_X86_REG_R9)
            sp=m.reg_read(x.UC_X86_REG_RSP)
            pointer=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
            if (opcode,count,tag)==(2,1,0x590008):
                value=self.next(6)[0]
                if self.text(pointer)!=value:raise ValueError('PRINT_TEXT_MISMATCH')
                self.trace(6,text_hash(value),0,0)
            elif (opcode,count,tag)==(0x174,3,0x59000a):
                year,ret,before,suffix,result=self.next(4)
                if struct.unpack('<i',m.mem_read(sp+56,4))[0]!=year:raise ValueError('CONCAT_YEAR_MISMATCH')
                if struct.unpack('<I',m.mem_read(sp+48,4))[0]!=0x520004 or struct.unpack('<I',m.mem_read(sp+64,4))[0]!=0x590008:raise ValueError('CONCAT_TYPES_MISMATCH')
                literal=struct.unpack('<Q',m.mem_read(sp+72,8))[0]
                if self.text(pointer)!=before or self.text(literal)!=suffix:raise ValueError('CONCAT_TEXT_MISMATCH')
                self.supply_text(pointer,result);m.reg_write(x.UC_X86_REG_RAX,ret&MASK)
                self.trace(4,year,text_hash(suffix),text_hash(result))
            else:raise ValueError('UNEXPECTED_DISPATCH '+str((opcode,count,tag)))
        elif api==25:
            if m.reg_read(x.UC_X86_REG_RCX)!=0x253ee076f88:raise ValueError('STRINGTOTIME_CONTEXT_MISMATCH')
            value,result=self.next(5)
            if self.text(m.reg_read(x.UC_X86_REG_RDX))!=value:raise ValueError('STRING_TO_TIME_ARGUMENT_MISMATCH')
            m.reg_write(x.UC_X86_REG_RAX,result&MASK);self.trace(5,text_hash(value),result,self.string_index);self.string_index+=1
        else:raise ValueError('UNEXPECTED_NATIVE_API '+str(api))
    def run(self,row):
        self.row=row;self.case={};self.records=self.fixtures[row['id']];self.position=0
        self.now_index=self.string_index=self.call_count=0;self.call_hash=0xcbf29ce484222325
        self.live_allocs=set();self.allocs=self.frees=0
        self.cursor=0x70001000;self.allocs=self.frees=0;self.trace_bytes=bytearray()
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':self.m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            self.m.reg_write(getattr(self.x,'UC_X86_REG_'+name),0)
        for i in range(16):self.m.reg_write(getattr(self.x,'UC_X86_REG_XMM'+str(i)),0)
        self.m.reg_write(self.x.UC_X86_REG_EFLAGS,0x202)
        self.m.mem_write(0x50000000,b'\0'*0x20000)
        top=0x50020000-0x108;self.m.mem_write(top,struct.pack('<Q',0x60000000));self.m.reg_write(self.x.UC_X86_REG_RSP,top)
        self.m.emu_start(self.base+FN,0x60000000,timeout=5000000,count=100000)
        if self.m.reg_read(self.x.UC_X86_REG_RIP)!=0x60000000 or self.position!=len(self.records):raise ValueError('NATIVE_DID_NOT_CONSUME_EXACT_API_SEQUENCE')
        if self.live_allocs or self.allocs!=self.frees:raise ValueError(f'UNEXPECTED_STRING_LIFETIME alloc={self.allocs} free={self.frees} live={sorted(self.live_allocs)}')
        return row['id'],int(bool(self.m.reg_read(self.x.UC_X86_REG_RAX)&255)),self.call_count,self.call_hash

def verify_build(build):
    if not build or not re.fullmatch('[a-z0-9-]+',build):raise ValueError('BUILD_REQUIRED')
    receipt=ROOT/'bot-cua-toi-2/bang-chung/bien-dich'/build/'bien-nhan.json'
    data=json.loads(receipt.read_text(encoding='utf-8-sig'));target='Scripts/bot-cua-toi-2/Bot2AmericanDSTCheck.mq5'
    script=MT/'MQL5'/target.replace('.mq5','.ex5')
    if data['target']!=target or data['errors']!=0 or data['warnings']!=0 or sha(script)!=data['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
    for name in [target,'Include/bot-cua-toi-2/Bot2AmericanDST.mqh']:
        if sha(ROOT/'bot-cua-toi-2/source/MQL5'/name)!=data['sources_sha256'][name]:raise ValueError('SOURCE_CHANGED_AFTER_BUILD')
    return receipt,script

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','mql5','original','compare']);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/'bot-cua-toi-2/bang-chung/kiem-gio-mua-he'/a.run
    if a.mode=='prepare':
        verify_pins();digest=EX5_SHA;out.mkdir(parents=True,exist_ok=False);rows=cases()
        (out/'cases.bin').write_bytes(encode(rows));save(out/'cases.json',rows)
        save(out/'baseline.json',dict(original_ex5_sha256=digest,capture_code_sha256=CODE_SHA,dst_function_sha256=DST_SHA,cases=len(rows),cases_sha256=sha(out/'cases.bin'),tool_sha256=sha(Path(__file__))))
        print(json.dumps({'cases':len(rows)}));return
    rows=json.loads((out/'cases.json').read_text());baseline=json.loads((out/'baseline.json').read_text())
    verify_pins()
    if sha(Path(__file__))!=baseline['tool_sha256']:raise ValueError('TOOL_CHANGED_AFTER_PREPARE')
    if encode(rows)!=(out/'cases.bin').read_bytes() or sha(out/'cases.bin')!=baseline['cases_sha256']:raise ValueError('CASE_INPUTS_CHANGED')
    if a.mode=='mql5':
        receipt,script=verify_build(a.build)
        probe=subprocess.run(['powershell','-NoProfile','-Command',f'Get-Process terminal64,metaeditor64 -ErrorAction SilentlyContinue | Where-Object {{$_.Path -like "{MT}*"}} | Select-Object -ExpandProperty Id'],capture_output=True,text=True,creationflags=subprocess.CREATE_NO_WINDOW)
        if probe.stdout.strip():raise RuntimeError('PRIVATE_MT5_BUSY')
        files=MT/'MQL5/Files/bot2-american-dst'/a.run;files.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b2-{a.run}-dst.set'
        preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b2-{a.run}-dst.ini'
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-2\\Bot2AmericanDSTCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        started=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0:raise RuntimeError('MQL5_CHECK_FAILED '+str(code))
        names=['mql5-results.bin','api-fixtures.bin','mql5-trace.bin']
        for name in names:
            if (out/name).exists():raise FileExistsError(out/name)
            shutil.copyfile(files/name,out/name)
        save(out/'mql5-run.json',dict(exit_code=code,seconds=round(time.monotonic()-started,2),script_sha256=sha(script),build_receipt_sha256=sha(receipt),hashes={name:sha(out/name) for name in names}))
        print(json.dumps({'cases':len(read_results(out/'mql5-results.bin'))}));return
    if a.mode=='original':
        # The repository EX5 is not the metadata source (0b501b... versus 390d8a...).
        # Native execution is therefore limited to the separately hashed capture.
        if baseline['original_ex5_sha256']!='390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795':raise ValueError('ORIGINAL_METADATA_HASH_CHANGED')
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        original=Original(read_fixtures(out/'api-fixtures.bin',len(rows)));started=time.monotonic();values=[];traces=bytearray()
        for row in rows:
            try:values.append(original.run(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} group={row["group"]} {error}') from error
            traces.extend(original.trace_bytes)
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,1,len(values))+b''.join(struct.pack('<3iQ',*r) for r in values))
        (out/'original-trace.bin').write_bytes(traces)
        save(out/'original-run.json',dict(cases=len(values),seconds=round(time.monotonic()-started,2),native_rva=hex(FN),tool_sha256=sha(Path(__file__)),result_sha256=sha(out/'original-results.bin'),trace_sha256=sha(out/'original-trace.bin'),api_fixtures_sha256=sha(out/'api-fixtures.bin'),scope=__doc__))
        print(json.dumps({'cases':len(values)}));return
    expected=read_results(out/'original-results.bin');actual=read_results(out/'mql5-results.bin')
    if len(expected)!=len(rows) or len(actual)!=len(rows):raise ValueError('RESULT_COUNT_MISMATCH')
    fail=[{'id':i,'original':x,'mql5':y} for i,(x,y) in enumerate(zip(expected,actual)) if x!=y or x[0]!=i or x[1] not in (0,1)]
    traces_equal=(out/'original-trace.bin').read_bytes()==(out/'mql5-trace.bin').read_bytes()
    result=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),ordered_traces_byte_equal=traces_equal,first_failures=fail[:20],hashes={name:sha(out/name) for name in ['cases.bin','original-results.bin','mql5-results.bin','original-trace.bin','mql5-trace.bin','api-fixtures.bin']},scope='Complete native AmericanDST function and reconstructed MQL5, same supplied clocks; measured real MT5 math/calendar/string boundary outputs. First TimeToStruct no-write failure, allocation failures and whole-EA integration remain unproved.')
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(fail) or not traces_equal)

if __name__=='__main__':main()
