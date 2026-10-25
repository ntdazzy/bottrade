"""Compare volume validation, ordered reads, messages and native division faults.

Usage: kiem-khoi-luong-hop-le-bot-1-3.py prepare|original|mql5|faults|compare BOT RUN [--build BUILD] [--case ID]
Only the private MT5 runs the check script. No trading API is called.
Native number-to-text formatting is supplied; message prefixes/value bits are checked.
"""
import argparse
import hashlib
import importlib.util
import json
import math
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
MT=ROOT.parent/'.local/claude-recovery-20261023/mt5'
MAGIC=0x56414c31
MASK=(1<<64)-1
FN={1:0x3bfe0,3:0x46ca0}
PREFIXES=["Volume is less than the minimal allowed SYMBOL_VOLUME_MIN=",
          "Volume is greater than the maximal allowed SYMBOL_VOLUME_MAX=",
          "Volume is not a multiple of the minimal step SYMBOL_VOLUME_STEP="]
spec=importlib.util.spec_from_file_location('volume',Path(__file__).with_name('kiem-khoi-luong-bot-1-3.py'))
volume=importlib.util.module_from_spec(spec);spec.loader.exec_module(volume)

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def bits(value):return int.from_bytes(struct.pack('<d',value),'little')
def save(path,data):
    with path.open('x',encoding='utf-8') as stream:json.dump(data,stream,ensure_ascii=False,indent=2,allow_nan=False)
def hash_trace(raw):
    value=0xcbf29ce484222325
    for byte in raw:value=((value^byte)*0x100000001b3)&MASK
    return value

def cases():
    rows=[]
    def add(group,value,minimum,maximum,step):
        rows.append(dict(id=len(rows),group=group,volume=value,minimum=minimum,maximum=maximum,step=step))
    values=[-1.0,-0.0,0.0,0.001,0.005,0.0099999,0.01,0.0100001,0.015,0.025,
            0.05,0.0999999,0.1,0.1000001,0.15,0.25,1.0,1.005,1.01,10.0,
            math.nan,math.inf,-math.inf]
    for minimum,maximum in [(0.01,1.0),(0.1,1.0),(1.0,100.0),(0.0,0.0),(1.0,0.1)]:
        for step in [0.0,0.001,0.01,0.1,0.05,1.0,math.nan]:
            for value in values:add('bounds-and-steps',value,minimum,maximum,step)
    for step in [0.001,0.01,0.1,0.25,0.3]:
        for n in range(-3,31):
            for delta in [-1e-7,-1e-8,0.0,1e-8,1e-7]:add('tolerance',n*step+delta,0.0,100.0,step)
    for minimum,maximum in [(-math.inf,math.inf),(math.nan,1.0),(0.0,math.nan),(math.nan,math.nan),(-10.0,10.0)]:
        for step in [-1.0,-0.1,math.inf,-math.inf,0.01]:
            for value in [-1.5,-0.5,-0.0,0.5,math.nan]:add('unordered-negative',value,minimum,maximum,step)
    for step in [0.01,0.1,1.0]:
        for ratio in [2147483646.0,2147483647.0,2147483648.0,4294967296.0,-2147483648.0,-2147483649.0]:
            for offset in [-0.5,0.0,0.5]:add('int32-conversion',(ratio+offset)*step,-math.inf,math.inf,step)
    return rows

def encode(rows):
    return struct.pack('<3i',MAGIC,2,len(rows))+b''.join(struct.pack('<i4d',r['id'],r['volume'],r['minimum'],r['maximum'],r['step']) for r in rows)
def read_cases(path):
    raw=path.read_bytes();magic,version,count=struct.unpack_from('<3i',raw)
    if (magic,version)!=(MAGIC,2) or len(raw)!=12+count*36:raise ValueError('BAD_CASE_FILE')
    return [dict(zip(['id','volume','minimum','maximum','step'],r)) for r in struct.iter_unpack('<i4d',raw[12:])]
def read_results(path):
    raw=path.read_bytes();magic,version,count=struct.unpack_from('<3i',raw)
    if (magic,version)!=(MAGIC,2) or len(raw)!=12+count*20:raise ValueError('BAD_RESULT_FILE')
    return list(struct.iter_unpack('<3iQ',raw[12:]))

def original_hash(bot):
    catalog=json.loads((ROOT/'tai-lieu-cu/catalog.json').read_text(encoding='utf-8'))
    index,tid=(5,'820755052E4765D7D56E6DAAFBB28091') if bot==1 else (16,'D0E8209F77C8CF37AD8BF550E51FF075')
    entry=next(x for x in catalog if x['index']==index)
    path=Path.home()/'AppData/Roaming/MetaQuotes/Terminal'/tid/'MQL5/Experts/Market'/entry['test']['ex5']
    value=sha(path)
    if value!=entry['sha256'].lower():raise ValueError('ORIGINAL_EX5_CHANGED')
    return value

class Original(volume.Original):
    def __init__(self,bot):
        super().__init__(bot);self.bot=bot
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        self.metadata=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        self.function=next(f for f in self.metadata['functions'] if int(f['begin_rva'],16)==FN[bot])
    def trace(self,*words):self.trace_bytes.extend(struct.pack('<3Q',*words))
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api==11:
            prop=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            if prop not in (34,35,36):raise ValueError('UNEXPECTED_SYMBOL_PROPERTY')
            self.last=self.case[{34:'minimum',35:'maximum',36:'step'}[prop]]
            raw=struct.pack('<d',self.last);m.mem_write(self.base+self.cfg['slot'],raw)
            m.reg_write(x.UC_X86_REG_XMM0,bits(self.last));self.trace(1,prop,bits(self.last));return
        if api==12:
            if m.reg_read(x.UC_X86_REG_RDX)!=2 or m.reg_read(x.UC_X86_REG_R8)!=1:raise ValueError('UNEXPECTED_MESSAGE')
            sp=m.reg_read(x.UC_X86_REG_RSP);ptr=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
            text_ptr=struct.unpack('<Q',m.mem_read(ptr+4,8))[0]
            n=struct.unpack('<I',m.mem_read(text_ptr-4,4))[0]
            text=bytes(m.mem_read(text_ptr,n*2)).decode('utf-16-le')
            if text not in PREFIXES:raise ValueError('MESSAGE_PREFIX_DIFFERS '+repr(text))
            self.trace(2,PREFIXES.index(text)+1,bits(self.last));return
        if api==14:
            # Numeric string conversion is an explicit supplied boundary.
            m.mem_write(m.reg_read(x.UC_X86_REG_R9),b'\0'*12);return
        if api==200:self.error=m.reg_read(x.UC_X86_REG_RDX);m.emu_stop();return
        if api in (100,101):return super().call(m,address,size,user)
        raise ValueError('UNEXPECTED_API '+str(api))
    def run_validator(self,row):
        m,x=self.m,self.x;self.case=row;self.error=0;self.cursor=0x70001000;self.allocs=self.frees=0
        self.trace_bytes=bytearray()
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.reg_write(x.UC_X86_REG_XMM0,bits(row['volume']))
        m.emu_start(self.base+FN[self.bot],0x60000000,timeout=5000000,count=2000000)
        if self.error:
            if self.error&0xffffffff!=0x1f7:raise ValueError('UNEXPECTED_NATIVE_ERROR '+hex(self.error))
            outcome=-1
        else:
            if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise RuntimeError('NATIVE_DID_NOT_RETURN')
            outcome=int((m.reg_read(x.UC_X86_REG_RAX)&0xff)!=0)
        return row['id'],outcome,len(self.trace_bytes)//24,hash_trace(self.trace_bytes)

def verify_build(bot,build):
    if not build or not re.fullmatch('[a-z0-9-]+',build):raise ValueError('BUILD_REQUIRED')
    p=ROOT/f'bot-cua-toi-{bot}/bang-chung/bien-dich'/build/'bien-nhan.json'
    receipt=json.loads(p.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{bot}/Bot{bot}VolumeValidationCheck.mq5'
    script=MT/'MQL5'/target.replace('.mq5','.ex5')
    if receipt['target']!=target or receipt['errors']!=0 or receipt['warnings']!=0 or sha(script)!=receipt['binary_sha256']:
        raise ValueError('BUILD_NOT_VERIFIED')
    for name,value in receipt['sources_sha256'].items():
        if sha(ROOT/f'bot-cua-toi-{bot}/source/MQL5'/name)!=value:raise ValueError('SOURCE_CHANGED_AFTER_BUILD '+name)
    return p,script

def run_mt5(bot,run,rows,case_id=-1):
    files=MT/f'MQL5/Files/bot{bot}-volume-validation'/run;files.mkdir(parents=True,exist_ok=False)
    (files/'cases.bin').write_bytes(encode(rows))
    preset=MT/'MQL5/Presets'/f'b{bot}-{run}.set'
    if preset.exists():raise FileExistsError(preset)
    preset.write_text(f'CheckRun={run}\nCheckCase={case_id}\n',encoding='utf-16')
    ini=MT/f'b{bot}-{run}-volume-validation.ini'
    if ini.exists():raise FileExistsError(ini)
    ini.write_text('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\n'
                   f'Script=bot-cua-toi-{bot}\\Bot{bot}VolumeValidationCheck\nScriptParameters={preset.name}\n'
                   'Symbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    logs=[MT/'MQL5/Logs',MT/'logs']
    before={p:p.stat().st_size for folder in logs for p in folder.glob('*.log')}
    started=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:
        p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
    lines=[]
    for log in (p for folder in logs for p in folder.glob('*.log')):
        complete=log.read_bytes();raw=complete[before.get(log,0):]
        encoding='utf-16-le' if complete[:2]==b'\xff\xfe' else 'utf-8-sig'
        if raw:lines.extend(raw.decode(encoding,errors='replace').splitlines())
    return files,code,round(time.monotonic()-started,2),lines

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('mode',choices=['prepare','original','mql5','faults','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');ap.add_argument('--case',type=int);a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-khoi-luong-hop-le'/a.run
    if a.mode=='prepare':
        digest=original_hash(a.bot);out.mkdir(parents=True,exist_ok=False);rows=cases();(out/'cases.bin').write_bytes(encode(rows))
        # Hex bits keep NaN and infinity cases valid JSON and exactly reproducible.
        save(out/'cases.json',[{'id':r['id'],'group':r['group'],**{k:struct.pack('<d',r[k]).hex() for k in ['volume','minimum','maximum','step']}} for r in rows])
        save(out/'baseline.json',{'original_ex5_sha256':digest,'cases':len(rows),'cases_sha256':sha(out/'cases.bin'),'tool_sha256':sha(Path(__file__)),'json_double_format':'IEEE-754 little-endian hexadecimal bytes'})
        print(json.dumps({'cases':len(rows)}));return
    rows=read_cases(out/'cases.bin');baseline=json.loads((out/'baseline.json').read_text())
    if baseline['cases_sha256']!=sha(out/'cases.bin'):raise ValueError('INPUTS_CHANGED')
    if a.mode=='original':
        if baseline['original_ex5_sha256']!=original_hash(a.bot):raise ValueError('ORIGINAL_EX5_CHANGED')
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        o=Original(a.bot);started=time.monotonic();values=[o.run_validator(r) for r in rows]
        target.write_bytes(struct.pack('<3i',MAGIC,2,len(values))+b''.join(struct.pack('<3iQ',*r) for r in values))
        save(out/'original-run.json',{'cases':len(values),'faults':sum(r[1]==-1 for r in values),'seconds':round(time.monotonic()-started,2),'result_sha256':sha(target),'native_rva':hex(FN[a.bot]),'tool_sha256':sha(Path(__file__)),'formatting_boundary':'Native double-to-string supplied empty; original prefix and numeric source value checked.'})
        import capstone
        md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);end=int(o.function['end_rva'],16)
        code=bytes(o.m.mem_read(o.base+FN[a.bot],end-FN[a.bot]))
        (out/'native-instructions.txt').write_text('\n'.join(f'{i.address-o.base:#x} {i.mnemonic} {i.op_str}' for i in md.disasm(code,o.base+FN[a.bot])),encoding='utf-8')
        print(json.dumps({'cases':len(values),'faults':sum(r[1]==-1 for r in values)}));return
    expected=read_results(out/'original-results.bin')
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        receipt,script=verify_build(a.bot,a.build);normal_ids={r[0] for r in expected if r[1]!=-1}
        files,code,seconds,_=run_mt5(a.bot,a.run,[r for r in rows if r['id'] in normal_ids])
        if code!=0 or not (files/'mql5-results.bin').is_file():raise RuntimeError('MQL5_CHECK_FAILED '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target)
        save(out/'mql5-run.json',{'exit_code':code,'seconds':seconds,'script_sha256':sha(script),'build_receipt_sha256':sha(receipt),'results_sha256':sha(target),'normal_cases':len(normal_ids),'native_fault_cases':len(expected)-len(normal_ids)})
        print(json.dumps({'normal_cases':len(normal_ids),'native_fault_cases':len(expected)-len(normal_ids)}));return
    if a.mode=='faults':
        receipt,script=verify_build(a.bot,a.build);by_id={r['id']:r for r in rows};faults=[r for r in expected if r[1]==-1]
        if a.case is not None:
            faults=[r for r in faults if r[0]==a.case]
            if not faults:raise ValueError('CASE_IS_NOT_NATIVE_DIVISION_FAULT')
        for native in faults:
            folder=out/'faults'/str(native[0]);result_path=folder/'result.json'
            if result_path.exists():
                record=json.loads(result_path.read_text())
                if not record['passed'] or record['script_sha256']!=sha(script):raise ValueError('PREVIOUS_FAULT_CHECK_NOT_VERIFIED')
                continue
            folder.mkdir(parents=True,exist_ok=False)
            files,code,seconds,logs=run_mt5(a.bot,a.run+'-fault-'+str(native[0]),[by_id[native[0]]],native[0])
            trace=(files/'fault-trace.bin').read_bytes();partial=(files/'mql5-results.bin').read_bytes()
            messages=[line for line in logs if 'zero divide' in line.lower() and f'Bot{a.bot}VolumeValidation' in line]
            observed=[native[0],-1,len(trace)//24,hash_trace(trace)]
            passed=bool(messages) and observed==list(native) and len(partial)==16 and struct.unpack_from('<i',partial,12)[0]==native[0]
            (folder/'fault-trace.bin').write_bytes(trace)
            save(result_path,{'id':native[0],'passed':passed,'original':list(native),'mql5':observed,'exit_code':code,'seconds':seconds,'messages':messages,'script_sha256':sha(script),'trace_sha256':sha(folder/'fault-trace.bin'),'partial_results_bytes':len(partial)})
            print(json.dumps({'fault_case':native[0],'passed':passed}),flush=True)
            if not passed:raise RuntimeError('FAULT_NOT_MATCHED '+str(native[0]))
        return
    comparison=out/'comparison.json'
    if comparison.exists():raise FileExistsError(comparison)
    actual={r[0]:list(r) for r in read_results(out/'mql5-results.bin')};missing=[]
    for native in expected:
        if native[1]==-1:
            p=out/'faults'/str(native[0])/'result.json'
            if not p.is_file():missing.append(native[0]);continue
            record=json.loads(p.read_text())
            if not record['passed']:missing.append(native[0]);continue
            actual[native[0]]=record['mql5']
    failures=[{'id':r[0],'original':list(r),'mql5':actual.get(r[0])} for r in expected if list(r)!=actual.get(r[0])]
    record={'cases':len(expected),'matched':len(expected)-len(failures),'failed':len(failures),'fault_cases':sum(r[1]==-1 for r in expected),'missing_fault_cases':missing,'first_failures':failures[:20],'hashes':{p:sha(out/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']},'scope':'Native complete validation function versus MQL5: ordered symbol reads, return result, message prefix/value bits; every division fault run separately. Exact numeric suffix formatting not compared to native runtime.'}
    if missing:print(json.dumps(record));raise SystemExit(1)
    save(comparison,record);print(json.dumps(record));raise SystemExit(bool(failures))

if __name__=='__main__':main()
