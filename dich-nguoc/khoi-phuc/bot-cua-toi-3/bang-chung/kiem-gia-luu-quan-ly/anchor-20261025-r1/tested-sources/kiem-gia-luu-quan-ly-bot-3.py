"""Compare the two original anchor segments, not the full position managers.

Usage: kiem-gia-luu-quan-ly-bot-3.py prepare|mql5|original|compare RUN [--build BUILD]
Only supplied SymbolInfoInteger is called; no trade functions or real positions.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess

ROOT=Path(__file__).resolve().parents[2]
def module(name):
    spec=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/name)
    result=importlib.util.module_from_spec(spec);spec.loader.exec_module(result);return result
entry=module('kiem-gia-vao-bot-1-3.py');validation=module('kiem-khoi-luong-hop-le-bot-1-3.py')
HOME=ROOT/'bot-cua-toi-3';MT=ROOT.parent/'.local/mt5-bot3-thread-20261025'
ANALYSIS=HOME/'phan-tich/dong-vi-the/management-20261025-r1'
MAGIC=0x414e4333;MASK=(1<<64)-1;RECORD_BYTES=4952
SEGMENTS={1:(0x33b73,0x33d76,0x40,0x5c,0x78),0:(0x38194,0x3839c,0x48,0x54,0x88)}
SOURCES=['Include/bot-cua-toi-3/Bot3ManagementAnchor.mqh','Include/bot-cua-toi-3/Bot3PriceLevels.mqh',
         'Scripts/bot-cua-toi-3/Bot3ManagementAnchorCheck.mq5']

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def require(ok,message):
    if not ok:raise ValueError(message)
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2)

def cases():
    result=[]
    def add(group,side,**changes):
        c=dict(id=len(result),group=group,side=side,flag=1,fill=0,digits=3,ticket=bits(7001.),
            opened=bits(100.),unit=bits(.1),step=bits(3.),limit=bits(2.),initial_step=bits(-999.),
            rows=[],control=0,control_row=0,control_values=[0,0]);c.update(changes);result.append(c)
    for side in [0,1]:
        for fill in range(4):add('missing-ticket-fill',side,fill=fill)
        for ticket in [0.,-0.,1.,-1.,float((1<<53)+1),float(-(1<<63)),float((1<<63)-1),1e30,-1e30,float('nan'),float('inf'),-float('inf')]:
            add('ticket-conversion',side,ticket=bits(ticket),fill=1)
        for flag in [0,1,2,255]:
            add('reference-byte',side,flag=flag,rows=[[0,bits(7001.),bits(99.)]])
        for value in [0.,-0.,1.005,-1.005,99.123456,1e30,-1e30,float('nan'),float('inf'),-float('inf')]:
            add('cached-level-rounding',side,rows=[[3,bits(7001.),bits(value)]])
            add('new-opened-price',side,opened=bits(value))
        for unit in [0.,-0.,-.1,.1,float('nan'),float('inf'),-float('inf')]:
            for level in [0.,99.,float('nan')]:
                add('unit-negative-zero-NaN',side,unit=bits(unit),rows=[[3,bits(7001.),bits(level)]])
        for digits in [-1,0,2,8,10,11,12,(1<<32)+3,-(1<<63),(1<<63)-1]:
            add('digits-low32',side,digits=digits,rows=[[0,bits(7001.),bits(99.1234567)]])
        for delta in [-.000001,0.,.000001]:
            value=99. if side else 101.
            add('distance-boundary',side,limit=bits(10.+delta),rows=[[0,bits(7001.),bits(value)]])
        for limit in [-1.,0.,float('nan'),float('inf'),-float('inf')]:
            add('distance-unordered',side,limit=bits(limit),rows=[[0,bits(7001.),bits(99. if side else 101.)]])
        add('duplicate-first-match',side,rows=[[1,bits(7001.),bits(99.)],[4,bits(7001.),bits(88.)]])
        add('free-last-row',side,fill=1,rows=[[99,bits(-0.),bits(333.)]])
        add('zero-ticket-cached-value',side,ticket=bits(-0.),rows=[[0,bits(0.),bits(99.)]])
        for value in [0.,-0.,1.,float('nan'),float('inf'),-float('inf')]:
            add('step-copied-before-api',side,step=bits(value))
        for control,value in [(1,.25),(1,float('inf')),(2,1000.),(3,9999.),(4,0.),(4,255.)]:
            add('service-state-change',side,rows=[[0,bits(7001.),bits(99.)]],control=control,control_values=[bits(value),0])
        add('service-changes-matched-row',side,control=5,control_row=0,control_values=[bits(7001.),bits(99.)])
    return result

def table(c):
    raw=bytearray(1600)
    for i in range(100):
        if c['fill'] in [1,3]:struct.pack_into('<2d',raw,i*16,(i+1)*(1 if c['fill']==1 else -1),100.+i*.125)
        if c['fill']==2:struct.pack_into('<2Q',raw,i*16,0x7ff8000000000001,bits(111.25))
    for i,a,b in c['rows']:struct.pack_into('<2Q',raw,i*16,a,b)
    return bytes(raw)

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<4iq6Qi',c['id'],c['side'],c['flag'],c['fill'],c['digits'],
            *(c[k] for k in ['ticket','opened','unit','step','limit','initial_step']),len(c['rows']))
        raw+=b''.join(struct.pack('<i2Q',*r) for r in c['rows'])
        raw+=struct.pack('<2i2Q',c['control'],c['control_row'],*c['control_values'])
    return bytes(raw)

class Original(entry.Original):
    def __init__(self):
        super().__init__(3);self.covered={side:set() for side in SEGMENTS}
        analysis=json.loads((ANALYSIS/'analysis.json').read_text())
        require(analysis['original_ex5_sha256']==validation.original_hash(3),'EX5_IDENTITY_DIFFERS')
        for fn in analysis['functions']:
            lo,hi=int(fn['rva'],16),int(fn['end_rva'],16)
            require(hashlib.sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==fn['native_bytes_sha256'],'NATIVE_FUNCTION_CHANGED')
        self.sdk=next(a for a,k in self.apis.items() if k==3)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x32f60,end=self.base+0x3bb10)
    def visit(self,m,address,size,user):
        offset=address-self.base
        for side,(lo,hi,*_) in SEGMENTS.items():
            if lo<=offset<hi:self.covered[side].add(offset)
    def snapshot(self):
        m=self.m
        return (bytes(m.mem_read(self.base+0x74428,8))+bytes(m.mem_read(self.base+0x73dd8,8))+
            bytes(m.mem_read(self.base+0x6d600,8))+bytes(m.mem_read(self.base+0x6d4e0,8))+
            struct.pack('<i',m.mem_read(self.base+0x6d508,1)[0])+bytes(m.mem_read(self.base+0x72e10,1600)))
    def call(self,m,address,size,user):
        x=self.x;c=self.case
        require(address==self.sdk and m.reg_read(x.UC_X86_REG_R8)==17,'UNEXPECTED_API')
        descriptor=m.reg_read(x.UC_X86_REG_RDX)
        pointer=struct.unpack('<Q',m.mem_read(descriptor+4,8))[0]
        n=struct.unpack('<I',m.mem_read(pointer-4,4))[0]
        require(bytes(m.mem_read(pointer,n*2)).decode('utf-16-le')=='CHECK','SYMBOL_DIFFERS')
        self.events+=self.snapshot();self.calls+=1
        control=c['control'];first,second=c['control_values']
        if control in [1,2,3]:m.mem_write(self.base+{1:0x73dd8,2:0x6d600,3:0x6d4e0}[control],struct.pack('<Q',first))
        if control==4:m.mem_write(self.base+0x6d508,bytes([int(struct.unpack('<d',struct.pack('<Q',first))[0])&255]))
        if control==5:m.mem_write(self.base+0x72e10+c['control_row']*16,struct.pack('<2Q',first,second))
        self.events+=self.snapshot();m.reg_write(x.UC_X86_REG_RAX,c['digits']&MASK)
    def run(self,c):
        self.case=c;self.events=bytearray();self.calls=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for rva,key in [(0x74428,'initial_step'),(0x73dd8,'unit'),(0x6d600,'step'),(0x6d4e0,'limit')]:m.mem_write(self.base+rva,struct.pack('<Q',c[key]))
        m.mem_write(self.base+0x6d508,bytes([c['flag']]));m.mem_write(self.base+0x72e10,table(c))
        self.cursor=0x70001000;m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string('CHECK')))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        top=0x50010000;m.reg_write(x.UC_X86_REG_RSP,top)
        m.reg_write(x.UC_X86_REG_RSI,0x171514ca538);m.reg_write(x.UC_X86_REG_RDI,self.base+0x74958)
        m.reg_write(x.UC_X86_REG_R12,self.base+0x73450)
        m.reg_write(x.UC_X86_REG_XMM6,c['opened']);m.reg_write(x.UC_X86_REG_XMM9,c['ticket'])
        start,end,ticket_slot,flag_slot,reference_slot=SEGMENTS[c['side']]
        m.emu_start(self.base+start,self.base+end,timeout=5000000,count=1000000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+end and self.calls==1,'SEGMENT_DID_NOT_FINISH')
        result=(struct.pack('<2i',c['id'],c['side'])+self.events+bytes(m.mem_read(top+ticket_slot,8))+
            struct.pack('<Q',m.reg_read(x.UC_X86_REG_XMM15)&MASK)+bytes(m.mem_read(top+reference_slot,8))+
            struct.pack('<i',m.mem_read(top+flag_slot,1)[0])+self.snapshot()+struct.pack('<2i',1,0))
        require(len(result)==RECORD_BYTES,'RECORD_LENGTH_DIFFERS');return result

def identity():
    return dict(original_ex5_sha256=validation.original_hash(3),tool_sha256=sha(Path(__file__)),
        sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in SOURCES},analysis_sha256=sha(ANALYSIS/'analysis.json'),
        dependencies_sha256={n:sha(ROOT/'cong-cu'/n) for n in ['kiem-gia-vao-bot-1-3.py','kiem-muc-gia-bot-1-3.py','kiem-khoi-luong-hop-le-bot-1-3.py']})
def check_identity(record,current):
    for k,v in current.items():require(record.get(k)==v,'IDENTITY_CHANGED '+k)

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','mql5','original','compare']);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    require(bool(re.fullmatch('[a-z0-9-]{1,40}',a.run)),'INVALID_RUN')
    out=HOME/'bang-chung/kiem-gia-luu-quan-ly'/a.run;rows=cases();current=identity();header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);tested=out/'tested-sources';tested.mkdir()
        for n in SOURCES:shutil.copyfile(HOME/'source/MQL5'/n,tested/Path(n).name)
        shutil.copyfile(Path(__file__),tested/Path(__file__).name)
        for n in current['dependencies_sha256']:shutil.copyfile(ROOT/'cong-cu'/n,tested/n)
        (out/'cases.bin').write_bytes(encode(rows));save(out/'cases.json',rows)
        save(out/'baseline.json',dict(**current,cases=len(rows),cases_sha256=sha(out/'cases.bin')));print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((out/'baseline.json').read_text());check_identity(baseline,current)
    require((out/'cases.bin').read_bytes()==encode(rows),'CASES_CHANGED')
    if a.mode=='mql5':
        require(bool(a.build and re.fullmatch('[a-z0-9-]{1,40}',a.build)),'BUILD_REQUIRED')
        receipt_path=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
        require(receipt['target']==SOURCES[2] and receipt['errors']==receipt['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(receipt['sources_sha256'][n]==h==sha(MT/'MQL5'/n),'COMPILED_SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(SOURCES[2]).with_suffix('.ex5');require(sha(binary)==receipt['binary_sha256']==sha(receipt_path.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-management-anchor'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b3-anchor-{a.run}.set';ini=MT/f'b3-anchor-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementAnchorCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        run=subprocess.run(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW,timeout=120)
        require(run.returncode==0 and struct.unpack('<2i',(files/'script-status.bin').read_bytes())==(0,len(rows)),'MQL5_RUN_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (files/n).open('rb') as src,(out/n).open('xb') as dst:shutil.copyfileobj(src,dst)
        save(out/'mql5-run.json',dict(**current,cases=len(rows),build=a.build,build_receipt_sha256=sha(receipt_path),result_sha256=sha(out/'mql5-results.bin')))
        print(json.dumps({'cases':len(rows),'exit_code':run.returncode}));return
    if a.mode=='original':
        require(not (out/'original-results.bin').exists(),'ORIGINAL_RESULT_EXISTS');runner=Original();raw=bytearray(header)
        for c in rows:raw+=runner.run(c)
        (out/'original-results.bin').write_bytes(raw)
        save(out/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(out/'original-results.bin'),
            executed_instructions={str(s):len(v) for s,v in runner.covered.items()},
            segments={str(s):dict(start=hex(v[0]),end_exclusive=hex(v[1])) for s,v in SEGMENTS.items()}))
        print(json.dumps({'cases':len(rows),'executed_instructions':{str(s):len(v) for s,v in runner.covered.items()}}));return
    for name,target in [('mql5-run.json','mql5-results.bin'),('original-run.json','original-results.bin')]:
        r=json.loads((out/name).read_text());check_identity(r,current);require(r['result_sha256']==sha(out/target),'RESULT_CHANGED')
    original=(out/'original-results.bin').read_bytes();actual=(out/'mql5-results.bin').read_bytes()
    require(len(original)==len(actual)==12+len(rows)*RECORD_BYTES and original[:12]==actual[:12]==header,'OUTPUT_SHAPE_DIFFERS')
    failures=[]
    for c in rows:
        i=c['id'];left=12+i*RECORD_BYTES;expected=original[left:left+RECORD_BYTES];got=actual[left:left+RECORD_BYTES]
        if expected!=got:
            at=next(j for j,(x,y) in enumerate(zip(expected,got)) if x!=y)
            failures.append(dict(id=i,group=c['group'],side=c['side'],first_byte=at,original=expected[at:at+16].hex(),mql5=got[at:at+16].hex()))
    report=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:12],
        hashes={n:sha(out/n) for n in ['baseline.json','cases.bin','original-results.bin','mql5-results.bin','script-status.bin']},
        whole_manager_complete=False,whole_bot_complete=False,
        scope='Only the two anchor segments: all200 table doubles,copied setting,converted ticket,anchor,reference,gap bool and before/after supplied digits service state. Other management branches,callers,trades,real account,lifecycle and full EA remain unverified.')
    save(out/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failures))

if __name__=='__main__':main()
