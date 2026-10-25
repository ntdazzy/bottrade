"""Compare the two-array history sort of bot 1/3 with the original EX5 code.

Usage: kiem-sap-xep-bot-1-3.py prepare|mql5|original|compare BOT NEW_RUN [--build BUILD]
Order: prepare -> compile BotNHistorySortCheck.mq5 -> mql5 --build BUILD -> original -> compare;
original needs only prepare. Normal-return cases only: every index the described algorithm
reads lies inside both arrays. The original RVA runs unchanged on two private data regions
behind the captured global descriptors; no SDK reply is supplied, execution may not leave
the function and only the stack and the two arrays may be written. Answers come from that
run: both physical arrays, lengths and as-series flags are compared byte for byte.
Not covered: error cases, callers, history data, the tester and the whole EA.
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
def load(name,file):
    spec=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file))
    module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module);return module
entry=load('entry_levels','kiem-gia-vao-bot-1-3.py')
validation=load('volume_validation','kiem-khoi-luong-hop-le-bot-1-3.py')

MAGIC=0x48535231;VERSION=1;MAX_ELEMENTS=4096
FN={1:0x47950,3:0x557f0};KEYS={1:0x6a2a0,3:0x772e0};VALUES={1:0x6a2e0,3:0x77320}
KEY_TYPE=0x800010056;VALUE_TYPE=0x800010055;SERIES=1<<20
KEY_DATA=0x71000000;VALUE_DATA=0x71010000;DATA_SIZE=0x20000
STACK=0x50000000;STACK_SIZE=0x20000;TOP=STACK+STACK_SIZE-0x108;RETURN=0x60000000
GPRS=['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']
DEPENDENCIES=['kiem-gia-vao-bot-1-3.py','kiem-muc-gia-bot-1-3.py','kiem-khoi-luong-hop-le-bot-1-3.py',
              'kiem-khoi-luong-bot-1-3.py','bien-dich.ps1']
OUTPUTS=['mql5-results.bin','script-status.bin']
INT_MIN=-(1<<31);INT_MAX=(1<<31)-1;U64=(1<<64)-1;HIGH=1<<63;LONG_MIN=-(1<<63);LONG_MAX=(1<<63)-1
LENGTHS=[1,2,3,8,31,64,100,128];FLAGS=[(0,0),(0,1),(1,0),(1,1)]
PATTERNS=['random','sign-boundary','duplicates','ascending','descending','equal','alternating']
# Original results measured by Codex (PHAN-TICH-SAP-XEP-BOT-1-3.md): normal flags, left=0, right=4.
PILOTS=[([U64,0,1,HIGH,1],[11,-22,33,-44,55],[0,1,1,HIGH,U64],[-22,55,33,-44,11]),
        ([7]*5,[1,2,3,4,5],[7]*5,[4,5,3,1,2])]
SCOPE=('History sort helper only (bot1 0x47950, bot3 0x557f0), normal-return cases: both physical arrays, '
       'lengths and as-series flags byte for byte against the original code run. Error cases, callers, '
       'history data, the tester and the whole EA are not verified.')

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def require(ok,message):
    if not ok:raise ValueError(message)
def save(path,value,indent=2):
    with path.open('x',encoding='utf-8') as stream:json.dump(value,stream,ensure_ascii=False,indent=indent,allow_nan=False)
def copy_new(source,target):
    with source.open('rb') as reader,target.open('xb') as writer:shutil.copyfileobj(reader,writer)
def zero_count(value):return type(value) is int and value==0
def names(bot):
    return [f'Scripts/bot-cua-toi-{bot}/Bot{bot}HistorySortCheck.mq5',f'Include/bot-cua-toi-{bot}/Bot{bot}HistorySort.mqh']
def runtime_table(bot):
    return ROOT/f'bot-cua-toi-{bot}/phan-tich'/('luot-20261023-data-v2' if bot==1 else 'luot-20261023-data')/'metadata/import.json'
def native_inputs(bot):
    home=ROOT/f'bot-cua-toi-{bot}';analysis=home/'phan-tich/sap-xep/sort-20261025-r1'
    return [*(analysis/name for name in ['analysis.json','native.txt','function.c','native-pilot.json']),runtime_table(bot),
            home/'bang-chung/captures/luot-20261023-r1/capture.json',home/'bang-chung/luot-20261023-r1/engine-observed.json']
def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5'
    return dict(original_ex5_sha256=validation.original_hash(bot),tool_sha256=sha(Path(__file__)),
        dependencies_sha256={name:sha(Path(__file__).with_name(name)) for name in DEPENDENCIES},
        native_inputs_sha256={path.relative_to(ROOT).as_posix():sha(path) for path in native_inputs(bot)},
        sources_sha256={name:sha(source/name) for name in names(bot)})
def check_identity(record,current,stage):
    for key,value in current.items():require(record.get(key)==value,f'{stage}_IDENTITY_CHANGED {key}')

def middle(left,right):
    total=left+right;return total//2 if total>=0 else -(-total//2)
def in_bounds(c):
    # Described algorithm: middle is read first; with left<=right every access stays in [left,right].
    left,right,keys,values=c['left'],c['right'],c['keys'],c['values']
    if not (INT_MIN<=left<=INT_MAX and INT_MIN<=right<=INT_MAX and INT_MIN<=left+right<=INT_MAX):return False
    if not 0<=middle(left,right)<len(keys):return False
    return left>right or (left>=0 and right<len(keys) and right<len(values))
def cases():
    rng=random.Random(20261025);rows=[]
    def add(group,key_items,value_items,left,right):
        for keys_series,values_series in FLAGS:
            row=dict(id=len(rows),group=group,left=left,right=right,keys_series=keys_series,values_series=values_series,
                     keys=list(key_items),values=list(value_items))
            require(in_bounds(row) and 1<=len(key_items)<=MAX_ELEMENTS and 1<=len(value_items)<=MAX_ELEMENTS,'CASE_NOT_NORMAL '+group)
            rows.append(row)
    def companions(n):
        # Distinct signed values with both extremes, so every move of a companion is visible.
        values=[LONG_MIN,LONG_MAX,-1,0][:n]
        while len(values)<n:
            value=rng.randrange(LONG_MIN,LONG_MAX+1)
            if value not in values:values.append(value)
        rng.shuffle(values);return values
    def pattern_keys(pattern,n):
        if pattern=='random':return [rng.getrandbits(64) for _ in range(n)]
        if pattern=='sign-boundary':return [rng.choice([0,1,HIGH-2,HIGH-1,HIGH,HIGH+1,U64-1,U64]) for _ in range(n)]
        if pattern=='duplicates':
            pool=[rng.getrandbits(64) for _ in range(3)]+[HIGH,U64];return [rng.choice(pool) for _ in range(n)]
        if pattern=='ascending':return sorted(rng.getrandbits(64) for _ in range(n))
        if pattern=='descending':return sorted((rng.getrandbits(64) for _ in range(n)),reverse=True)
        if pattern=='equal':return [HIGH+7]*n
        require(pattern=='alternating','UNKNOWN_PATTERN '+pattern);return [U64 if i%2==0 else 0 for i in range(n)]
    for n in LENGTHS:
        for pattern in PATTERNS:add('full-'+pattern,pattern_keys(pattern,n),companions(n),0,n-1)
    for n in [3,8,31,64,100,128]:
        if n==3:spans=[(0,1),(1,2)]
        else:
            low=rng.randrange(1,n//2)
            spans=[(low,rng.randrange(low+1,n-1)),(0,rng.randrange(1,n-1)),(rng.randrange(1,n-1),n-1)]
        for (left,right),pattern in zip(spans,['duplicates','sign-boundary','random']):
            add('subrange',pattern_keys(pattern,n),companions(n),left,right)
    for n in [1,2,3,8,64,128]:
        for index in sorted({0,n//2,n-1}):add('left-equals-right',pattern_keys('random',n),companions(n),index,index)
    for n in [1,2,8,128]:
        pairs=[(1,0),(0,-1),(1,-2),(INT_MAX,INT_MIN),(INT_MAX,INT_MIN+1),(n,n-2),(n+1,n-2),(2*n-2,0),(INT_MAX,2*n-2-INT_MAX)]
        for left,right in dict.fromkeys(pairs):
            if left>right and 0<=middle(left,right)<n:add('left-above-right',pattern_keys('random',n),companions(n),left,right)
    for pilot_keys,pilot_values,_,_ in PILOTS:add('documented-pilot',pilot_keys,pilot_values,0,4)
    for key_count,value_count,left,right in [(10,13,0,9),(13,10,0,9),(31,64,3,30),(64,31,0,30),(8,9,2,7)]:
        add('unequal-lengths',pattern_keys('duplicates',key_count),companions(value_count),left,right)
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,VERSION,len(rows)))
    for c in rows:
        keys,values=c['keys'],c['values']
        raw+=struct.pack('<7i',c['id'],c['left'],c['right'],c['keys_series'],c['values_series'],len(keys),len(values))
        raw+=struct.pack(f'<{len(keys)}Q',*keys)+struct.pack(f'<{len(values)}q',*values)
    return bytes(raw)
def array_bytes(series,items,kind):return struct.pack('<2i',series,len(items))+struct.pack(f'<{len(items)}{kind}',*items)
class Reader:
    def __init__(self,raw):self.raw=raw;self.pos=0
    def take(self,fmt):
        size=struct.calcsize('<'+fmt);require(self.pos+size<=len(self.raw),'TRUNCATED_FILE')
        values=struct.unpack_from('<'+fmt,self.raw,self.pos);self.pos+=size;return values
    def array(self,kind):
        series,count=self.take('2i');require(series in (0,1) and 0<=count<=MAX_ELEMENTS,'ARRAY_HEADER_INVALID')
        return series,count,self.take(f'{count}{kind}')
def read_results(path,rows):
    # Exact layout: header, then per case id, keys (flag, length, ulong data), values (flag, length, long data).
    rd=Reader(path.read_bytes());require(rd.take('3i')==(MAGIC,VERSION,len(rows)),'RESULT_HEADER_DIFFERS');out=[]
    for c in rows:
        start=rd.pos;require(rd.take('i')[0]==c['id'],'RESULT_CASE_ID_DIFFERS')
        arrays=(rd.array('Q'),rd.array('q'));out.append((rd.raw[start:rd.pos],arrays))
    require(rd.pos==len(rd.raw),'RESULT_TRAILING_BYTES');return out
def difference(native,mql5):
    for name,(a_series,a_count,a_items),(b_series,b_count,b_items) in zip(['keys','values'],native,mql5):
        if a_series!=b_series:return dict(field=name+'.series',original=a_series,mql5=b_series)
        if a_count!=b_count:return dict(field=name+'.length',original=a_count,mql5=b_count)
        for index,(x,y) in enumerate(zip(a_items,b_items)):
            if x!=y:return dict(field=f'{name}[physical {index}]',original=x,mql5=y)
    raise ValueError('RESULT_BYTES_DIFFER_WITHOUT_FIELD')

class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot)
        ends={int(f['begin_rva'],16):int(f['end_rva'],16) for f in json.loads(runtime_table(bot).read_text(encoding='utf-8'))['functions']}
        require(FN[bot] in ends,'SORT_FUNCTION_NOT_IN_CAPTURED_RUNTIME_TABLE')
        self.fn=FN[bot];self.fn_end=ends[self.fn];self.covered=set();self.allowed=[]
        self.captured={name:bytes(self.m.mem_read(self.base+rva,52)).hex() for name,rva in [('keys',KEYS[bot]),('values',VALUES[bot])]}
        self.m.mem_map(KEY_DATA,DATA_SIZE)
        self.m.hook_add(self.uc.UC_HOOK_BLOCK,self.block)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+self.fn,end=self.base+self.fn_end-1)
        self.m.hook_add(self.uc.UC_HOOK_MEM_WRITE,self.write)
    def call(self,m,address,size,user):raise ValueError(f'UNEXPECTED_SDK_CALL {self.apis[address]}')
    def block(self,m,address,size,user):
        # Only the function itself (with its recursive calls) and the final return may run.
        if address!=RETURN and not self.fn<=address-self.base<self.fn_end:raise ValueError(f'EXECUTION_LEFT_SORT_FUNCTION {address-self.base:#x}')
    def visit(self,m,address,size,user):self.covered.add(address-self.base)
    def write(self,m,access,address,size,value,user):
        if not any(low<=address and address+size<=high for low,high in self.allowed):raise ValueError(f'UNEXPECTED_NATIVE_WRITE {address:#x}/{size}')
    def place(self,rva,kind,series,address,items,fmt):
        descriptor=self.base+rva;m=self.m
        m.mem_write(descriptor,struct.pack('<Q',kind|(SERIES if series else 0))+b'\0'*44)
        m.mem_write(descriptor+8,struct.pack('<i',len(items)));m.mem_write(descriptor+28,struct.pack('<Q',address))
        m.mem_write(address,struct.pack(f'<{len(items)}{fmt}',*items))
    def physical(self,rva):
        raw=bytes(self.m.mem_read(self.base+rva,52));head,count=struct.unpack_from('<Qi',raw);pointer=struct.unpack_from('<Q',raw,28)[0]
        require(0<=count<=MAX_ELEMENTS,'NATIVE_ARRAY_LENGTH_INVALID')
        return struct.pack('<2i',int(bool(head&SERIES)),count)+(bytes(self.m.mem_read(pointer,8*count)) if count else b'')
    def run_case(self,c):
        m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        m.mem_write(STACK,b'\0'*STACK_SIZE);m.mem_write(KEY_DATA,b'\0'*DATA_SIZE)
        self.place(KEYS[self.bot],KEY_TYPE,c['keys_series'],KEY_DATA,c['keys'],'Q')
        self.place(VALUES[self.bot],VALUE_TYPE,c['values_series'],VALUE_DATA,c['values'],'q')
        self.allowed=[(STACK,STACK+STACK_SIZE),(KEY_DATA,KEY_DATA+8*len(c['keys'])),(VALUE_DATA,VALUE_DATA+8*len(c['values']))]
        for name in GPRS:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,f'UC_X86_REG_XMM{i}'),0)
        m.mem_write(TOP,struct.pack('<Q',RETURN));m.reg_write(x.UC_X86_REG_RSP,TOP)
        m.reg_write(x.UC_X86_REG_RCX,c['left']&0xffffffff);m.reg_write(x.UC_X86_REG_RDX,c['right']&0xffffffff)
        m.emu_start(self.base+self.fn,RETURN,timeout=5000000,count=2000000)
        require(m.reg_read(x.UC_X86_REG_RIP)==RETURN,'ORIGINAL_DID_NOT_RETURN')
        require(m.reg_read(x.UC_X86_REG_RSP)==TOP+8,'ORIGINAL_STACK_NOT_BALANCED')
        return struct.pack('<i',c['id'])+self.physical(KEYS[self.bot])+self.physical(VALUES[self.bot])

def verify_receipt(receipt,path,bot,sources):
    target=names(bot)[0];digest=receipt.get('binary_sha256');compiled=receipt.get('sources_sha256')
    require(receipt.get('target')==target and zero_count(receipt.get('errors')) and zero_count(receipt.get('warnings')),'BUILD_NOT_CLEAN_OR_TARGET_DIFFERS')
    require(type(digest) is str and re.fullmatch('[0-9a-f]{64}',digest) is not None and
            sha(path.parent/Path(target).with_suffix('.ex5').name)==digest,'BUILD_BINARY_DIFFERS')
    require(type(compiled) is dict and all(compiled.get(name)==sources[name] for name in names(bot)),'COMPILED_SOURCE_DIFFERS')
    return digest

def prepare(out,rows,current):
    out.mkdir(parents=True,exist_ok=False)
    with (out/'cases.bin').open('xb') as stream:stream.write(encode(rows))
    save(out/'cases.json',rows,None);groups={}
    for c in rows:groups[c['group']]=groups.get(c['group'],0)+1
    save(out/'baseline.json',dict(cases=len(rows),groups=groups,cases_sha256=sha(out/'cases.bin'),cases_json_sha256=sha(out/'cases.json'),
         **current,whole_bot_complete=False,scope=SCOPE))
    print(json.dumps(dict(cases=len(rows),groups=groups)))

def run_mql5(bot,run,build,out,rows,current,baseline):
    require(build is not None and re.fullmatch('[a-z0-9-]{1,48}',build) is not None,'BUILD_REQUIRED')
    require(not any((out/name).exists() for name in [*OUTPUTS,'mql5-run.json','mql5-failure.json','tested-sources']),'MQL5_RESULTS_EXIST')
    home=ROOT/f'bot-cua-toi-{bot}';n=len(rows)
    receipt_path=home/'bang-chung/bien-dich'/build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    digest=verify_receipt(receipt,receipt_path,bot,current['sources_sha256']);binary=MT/'MQL5'/Path(names(bot)[0]).with_suffix('.ex5')
    require(sha(binary)==digest and all(sha(MT/'MQL5'/name)==value for name,value in current['sources_sha256'].items()),'TERMINAL_COPY_DIFFERS_FROM_BUILD')
    require(sha(MT/'metaeditor64.exe')==receipt.get('metaeditor_sha256'),'COMPILER_CHANGED')
    files=MT/'MQL5/Files'/f'bot{bot}-history-sort'/run;files.mkdir(parents=True,exist_ok=False);copy_new(out/'cases.bin',files/'cases.bin')
    preset=MT/'MQL5/Presets'/f'b{bot}-history-sort-{run}.set';ini=MT/f'b{bot}-history-sort-{run}.ini';preset.parent.mkdir(exist_ok=True)
    with preset.open('x',encoding='utf-16') as stream:stream.write(f'CheckRun={run}\n')
    with ini.open('x',encoding='utf-16') as stream:
        stream.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}HistorySortCheck\n'
                     f'ScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
    before=sha(MT/'terminal64.exe');started=time.monotonic()
    process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=process.wait(timeout=120)
    except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);code=None
    seconds=round(time.monotonic()-started,2);after=sha(MT/'terminal64.exe')
    complete=all((files/name).is_file() for name in OUTPUTS) and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,n)
    if code!=0 or before!=after or not complete:
        save(out/'mql5-failure.json',dict(exit_code=code,timed_out=code is None,seconds=seconds,terminal_sha256_before=before,terminal_sha256_after=after,
             output_bytes={name:(files/name).stat().st_size if (files/name).is_file() else None for name in OUTPUTS},**current,whole_bot_complete=False))
        raise RuntimeError(f'MT5_HISTORY_SORT_FAILED exit={code}')
    require(sha(binary)==digest and sha(files/'cases.bin')==baseline['cases_sha256'],'TERMINAL_INPUT_CHANGED_DURING_RUN')
    for name in OUTPUTS:copy_new(files/name,out/name)
    read_results(out/'mql5-results.bin',rows)
    tested=out/'tested-sources';tested.mkdir()
    copies={Path(name).name:(home/'source/MQL5'/name,current['sources_sha256'][name]) for name in names(bot)}
    copies['check-tool.py']=(Path(__file__),current['tool_sha256'])
    copies.update({name:(Path(__file__).with_name(name),current['dependencies_sha256'][name]) for name in DEPENDENCIES})
    for name,(source,expected) in copies.items():
        copy_new(source,tested/name);require(sha(tested/name)==expected,'TESTED_SOURCE_DIFFERS '+name)
    save(out/'mql5-run.json',dict(cases=n,exit_code=code,seconds=seconds,build=build,build_receipt_sha256=sha(receipt_path),binary_sha256=digest,
         metaeditor_sha256=receipt['metaeditor_sha256'],terminal_sha256_before=before,terminal_sha256_after=after,**current,
         hashes={name:sha(out/name) for name in OUTPUTS},tested_sources_sha256={p.name:sha(p) for p in sorted(tested.iterdir())},
         whole_bot_complete=False))
    print(json.dumps(dict(cases=n,exit_code=code,seconds=seconds)))

def run_original(bot,out,rows,current):
    require(not (out/'original-results.bin').exists() and not (out/'original-run.json').exists(),'ORIGINAL_RESULTS_EXIST')
    runner=Original(bot);started=time.monotonic();results=[]
    for c in rows:
        try:results.append(runner.run_case(c))
        except Exception as error:
            rip=runner.m.reg_read(runner.x.UC_X86_REG_RIP)-runner.base
            raise RuntimeError(f'case={c["id"]} group={c["group"]} rip={rip:#x} {error}') from error
    pilots=0
    for c in rows:
        if c['group']=='documented-pilot' and (c['keys_series'],c['values_series'])==(0,0):
            _,_,sorted_keys,moved_values=next(p for p in PILOTS if (p[0],p[1])==(c['keys'],c['values']))
            expected=struct.pack('<i',c['id'])+array_bytes(0,sorted_keys,'Q')+array_bytes(0,moved_values,'q')
            require(results[c['id']]==expected,f'DOCUMENTED_PILOT_DIFFERS {c["id"]}');pilots+=1
    require(pilots==len(PILOTS),'DOCUMENTED_PILOT_MISSING')
    with (out/'original-results.bin').open('xb') as stream:stream.write(struct.pack('<3i',MAGIC,VERSION,len(rows))+b''.join(results))
    read_results(out/'original-results.bin',rows)
    coverage=dict(executed_instructions=len(runner.covered),offsets=[hex(v) for v in sorted(runner.covered)])
    save(out/'original-run.json',dict(cases=len(rows),seconds=round(time.monotonic()-started,2),result_sha256=sha(out/'original-results.bin'),
         **current,native_rva=hex(FN[bot]),function_end_rva=hex(runner.fn_end),descriptor_rvas=dict(keys=hex(KEYS[bot]),values=hex(VALUES[bot])),
         captured_descriptors=runner.captured,documented_pilot_cases=pilots,coverage=coverage,whole_bot_complete=False,scope=SCOPE))
    print(json.dumps(dict(cases=len(rows),documented_pilot_cases=pilots,executed_instructions=len(runner.covered))))

def compare(bot,out,rows,current):
    home=ROOT/f'bot-cua-toi-{bot}';n=len(rows)
    mql=json.loads((out/'mql5-run.json').read_text(encoding='utf-8'));native=json.loads((out/'original-run.json').read_text(encoding='utf-8'))
    check_identity(mql,current,'MQL5_RUN');check_identity(native,current,'ORIGINAL_RUN')
    require(not (out/'comparison.json').exists(),'COMPARISON_EXISTS')
    for name,digest in mql['hashes'].items():require(sha(out/name)==digest,'MQL5_EVIDENCE_CHANGED '+name)
    tested=out/'tested-sources'
    require(sorted(p.name for p in tested.iterdir())==sorted(mql['tested_sources_sha256']),'TESTED_SOURCE_SET_CHANGED')
    for name,digest in mql['tested_sources_sha256'].items():require(sha(tested/name)==digest,'TESTED_SOURCE_CHANGED '+name)
    require(re.fullmatch('[a-z0-9-]{1,48}',mql['build']) is not None,'BUILD_NAME_INVALID')
    receipt_path=home/'bang-chung/bien-dich'/mql['build']/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    require(sha(receipt_path)==mql['build_receipt_sha256'] and
            verify_receipt(receipt,receipt_path,bot,current['sources_sha256'])==mql['binary_sha256'],'BUILD_EVIDENCE_CHANGED')
    require(mql['terminal_sha256_before']==mql['terminal_sha256_after']==sha(MT/'terminal64.exe'),'MT5_PROGRAM_CHANGED')
    require(mql['cases']==native['cases']==n and native['result_sha256']==sha(out/'original-results.bin'),'NATIVE_EVIDENCE_CHANGED')
    expected=read_results(out/'original-results.bin',rows);actual=read_results(out/'mql5-results.bin',rows);failures=[];groups={}
    for c,(native_raw,native_arrays),(mql_raw,mql_arrays) in zip(rows,expected,actual):
        group=groups.setdefault(c['group'],dict(cases=0,matched=0));group['cases']+=1
        if native_raw==mql_raw:group['matched']+=1;continue
        failures.append(dict(id=c['id'],group=c['group'],left=c['left'],right=c['right'],keys_series=c['keys_series'],
                             values_series=c['values_series'],**difference(native_arrays,mql_arrays)))
    hashes={name:sha(out/name) for name in ['cases.bin','cases.json','baseline.json','mql5-run.json',*OUTPUTS,'original-run.json','original-results.bin']}
    result=dict(cases=n,matched=n-len(failures),failed=len(failures),first_failures=failures[:20],groups=groups,
                documented_pilot_cases=native['documented_pilot_cases'],coverage=native['coverage'],hashes=hashes,
                whole_bot_complete=False,scope=SCOPE)
    save(out/'comparison.json',result)
    print(json.dumps(dict(cases=n,matched=result['matched'],failed=len(failures),first_failures=failures[:5],groups=groups),ensure_ascii=False))
    raise SystemExit(bool(failures))

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode',choices=['prepare','mql5','original','compare']);parser.add_argument('bot',type=int,choices=[1,3])
    parser.add_argument('run');parser.add_argument('--build');a=parser.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,40}',a.run) is not None,'INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-sap-xep'/a.run;current=identity(a.bot);rows=cases()
    if a.mode=='prepare':return prepare(out,rows,current)
    baseline=json.loads((out/'baseline.json').read_text(encoding='utf-8'));check_identity(baseline,current,'BASELINE')
    require(baseline['cases']==len(rows) and (out/'cases.bin').read_bytes()==encode(rows) and
            sha(out/'cases.bin')==baseline['cases_sha256'],'CASES_CHANGED')
    require(json.loads((out/'cases.json').read_text(encoding='utf-8'))==rows and sha(out/'cases.json')==baseline['cases_json_sha256'],'CASE_JSON_CHANGED')
    if a.mode=='mql5':return run_mql5(a.bot,a.run,a.build,out,rows,current,baseline)
    if a.mode=='original':return run_original(a.bot,out,rows,current)
    compare(a.bot,out,rows,current)

if __name__=='__main__':main()
