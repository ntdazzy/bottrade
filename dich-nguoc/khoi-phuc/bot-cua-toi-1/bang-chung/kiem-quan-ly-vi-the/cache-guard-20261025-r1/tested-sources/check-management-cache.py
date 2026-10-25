"""Compare the 100x2 cache slice, not the rest of either management function.
Usage: check-management-cache.py prepare|original|mql5|compare RUN [--build BUILD]
MQL5 always uses .local/mt5-bot1-thread-20261025. No terminal API sends trades.
"""
import argparse
import copy
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess

HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
spec=importlib.util.spec_from_file_location('prelude_check',Path(__file__).with_name('check-management-prelude.py'))
pre=importlib.util.module_from_spec(spec);spec.loader.exec_module(pre)
MAGIC=0x4d434131;MT=(ROOT.parent/'.local/mt5-bot1-thread-20261025').resolve()
SOURCES=['Include/bot-cua-toi-1/'+n for n in ['Bot1ManagementPrelude.mqh','Bot1PriceLevels.mqh','Bot1VirtualStops.mqh']]+['Scripts/bot-cua-toi-1/Bot1ManagementCacheCheck.mq5']
HEADER=struct.Struct('<ii4Qi');SIZE=HEADER.size+1600
def identity():return dict(original_ex5_sha256=pre.validation.original_hash(1),tool_sha256=pre.sha(Path(__file__)),dependency_sha256=pre.sha(Path(__file__).with_name('check-management-prelude.py')),analysis_sha256=pre.sha(pre.ANALYSIS/'analysis.json'),sources_sha256={n:pre.sha(HOME/'source/MQL5'/n) for n in SOURCES})
def base():return dict(id=0,buy=1,digits=3,use_cached=1,ticket=7.,open=100.,unit=.1,step=1.25,threshold=10.,cache=[[0.,0.] for _ in range(100)])
def cases():
    rows=[]
    def add(c,group):c.update(id=len(rows),group=group);rows.append(c)
    for buy in [0,1]:
        for size in [0,1,99,100]:
            c=base();c['buy']=buy;c['cache'][:size]=[[float(100+i),float(200+i)] for i in range(size)];add(c,'empty-to-full')
        for location in [0,1,50,99]:
            for level in [-float('inf'),-1e19,-.0001,-0.,0.,.0001,1.,98.999,99.,100.,101.,101.001,1e19,float('inf'),float('nan')]:
                c=base();c['buy']=buy;c['cache'][location]=[7.,level];add(c,'cached-level-boundary')
        for ticket in [0.,-0.,float(1<<53),float((1<<53)+2),float(1<<63),-float(1<<63)]:
            for value in [0.,95.,105.]:
                c=base();c.update(buy=buy,ticket=ticket);c['cache'][0]=[ticket,value];add(c,'ticket-conversion')
        for flag in [0,1,2,255]:
            c=base();c.update(buy=buy,use_cached=flag);c['cache'][0]=[7.,95.];add(c,'cached-flag-byte')
        for digit in [-1,0,2,8,11,12]:
            c=base();c.update(buy=buy,digits=digit);c['cache'][0]=[7.,99.9995];add(c,'rounding')
        for field in ['open','unit','step','threshold']:
            for value in [-float('inf'),-1e19,-1.,-0.,0.,1.,1e19,float('inf'),float('nan')]:
                c=base();c.update(buy=buy);c[field]=value;c['cache'][0]=[7.,95.];add(c,'numeric-'+field)
        for pattern in ['nan-ticket','duplicate-ticket','first-empty','zero-level-existing','all-nan']:
            c=base();c['buy']=buy
            if pattern=='nan-ticket':c['cache'][0]=[float('nan'),10.];c['cache'][1]=[7.,105.]
            if pattern=='duplicate-ticket':c['cache'][0]=[7.,95.];c['cache'][1]=[7.,105.]
            if pattern=='first-empty':c['cache'][0]=[100.,999.];c['cache'][1]=[-0.,777.]
            if pattern=='zero-level-existing':c['cache'][0]=[7.,0.];c['cache'][1]=[100.,888.]
            if pattern=='all-nan':c['cache']=[[float('nan'),float('nan')] for _ in range(100)]
            add(c,pattern)
    return rows
def encode(rows):
    b=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        b+=struct.pack('<4i6d',*[c[k] for k in ['id','buy','digits','use_cached']],*[c[k] for k in ['ticket','open','unit','step','threshold']],123.25)
        b+=b''.join(struct.pack('<2d',*row) for row in c['cache'])
    return bytes(b)

class Original(pre.entry.Original):
    def __init__(self):
        super().__init__(1);self.covered=set();self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x27c51,end=self.base+0x2b85f)
        analysis=json.loads((pre.ANALYSIS/'analysis.json').read_text())
        for f in analysis['functions']:
            lo=int(f['rva'],16);hi=int(f['end_rva'],16)
            pre.require(__import__('hashlib').sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==f['native_bytes_sha256'],'CODE_CHANGED')
    def visit(self,m,address,size,user):
        self.covered.add(address-self.base)
        if address-self.base in [0x27e46,0x2b85f]:self.stopped=True;m.emu_stop()
    def call(self,m,address,size,user):
        x=self.x;pre.require(self.apis[address]==3,'UNEXPECTED_API')
        pre.require(m.reg_read(x.UC_X86_REG_R8)==17,'BAD_PROPERTY')
        self.calls+=1;m.reg_write(x.UC_X86_REG_RAX,self.case['digits']&pre.MASK)
    def run(self,c):
        self.case=c;self.calls=0;self.stopped=False;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        cache=b''.join(struct.pack('<2d',*row) for row in c['cache']);m.mem_write(self.base+0x65dd0,cache)
        for addr,value in [(0x62510,c['step']),(0x673e8,123.25),(0x66d98,c['unit']),(0x623e8,c['threshold'])]:m.mem_write(self.base+addr,struct.pack('<d',value))
        m.mem_write(self.base+0x62410,bytes([c['use_cached']]))
        m.reg_write(x.UC_X86_REG_RSI,0x23e575eae78);m.reg_write(x.UC_X86_REG_RDI,self.base+0x67918);m.reg_write(x.UC_X86_REG_R12,self.base+0x66410)
        m.reg_write(x.UC_X86_REG_XMM6,pre.bits(c['open']));m.reg_write(x.UC_X86_REG_XMM9,pre.bits(c['ticket']))
        m.reg_write(x.UC_X86_REG_RSP,0x50020000-0x208)
        m.emu_start(self.base+(0x27c51 if c['buy'] else 0x2b667),0x60000000,timeout=5000000,count=100000)
        pre.require(self.stopped and self.calls==1,'WRONG_BOUNDARY_OR_CALLS')
        reference=m.reg_read(x.UC_X86_REG_XMM14)&pre.MASK;anchor=m.reg_read(x.UC_X86_REG_XMM1 if c['buy'] else x.UC_X86_REG_XMM15)&pre.MASK
        sp=m.reg_read(x.UC_X86_REG_RSP);flag=m.mem_read(sp+(0x5c if c['buy'] else 0x6c),1)[0]
        copied=struct.unpack('<Q',m.mem_read(self.base+0x673e8,8))[0]
        # Only bool low byte is meaningful; upper bits contain incidental register data.
        return HEADER.pack(c['id'],self.calls,reference,anchor,copied,m.reg_read(x.UC_X86_REG_XMM11)&pre.MASK,flag)+bytes(m.mem_read(self.base+0x65dd0,1600))

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args()
    pre.require(bool(re.fullmatch('[a-z0-9-]{1,50}',a.run)),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));pre.save(folder/'cases.json',rows)
        tested=folder/'tested-sources';tested.mkdir()
        for n in SOURCES:shutil.copyfile(HOME/'source/MQL5'/n,tested/Path(n).name)
        shutil.copyfile(Path(__file__),tested/Path(__file__).name)
        pre.save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=pre.sha(folder/'cases.bin'),slice_only=True));print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((folder/'baseline.json').read_text());pre.require(all(baseline[k]==v for k,v in current.items()),'IDENTITY_CHANGED');pre.require((folder/'cases.bin').read_bytes()==encode(rows),'CASES_CHANGED')
    if a.mode=='original':
        target=folder/'original-results.bin';pre.require(not target.exists(),'RESULT_EXISTS');runner=Original()
        raw=struct.pack('<3i',MAGIC,1,len(rows))+b''.join(runner.run(c) for c in rows);target.write_bytes(raw)
        pre.save(folder/'original-run.json',dict(**current,result_sha256=pre.sha(target),cases=len(rows),executed_instructions=sorted(hex(v) for v in runner.covered),slice_only=True));print(json.dumps({'cases':len(rows),'instructions':len(runner.covered)}));return
    if a.mode=='mql5':
        pre.require(a.build is not None,'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        pre.require(build['target']==SOURCES[-1] and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,v in current['sources_sha256'].items():pre.require(build['sources_sha256'][n]==v==pre.sha(MT/'MQL5'/n),'SOURCE_CHANGED')
        binary=MT/'MQL5'/Path(SOURCES[-1]).with_suffix('.ex5');pre.require(pre.sha(binary)==build['binary_sha256']==pre.sha(receipt.parent/binary.name),'BINARY_CHANGED')
        files=MT/'MQL5/Files/bot1-management-cache'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b1-cache-{a.run}.set'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        ini=MT/f'b1-cache-{a.run}.ini'
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ManagementCacheCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        pre.require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_NOT_PASSED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        pre.save(folder/'mql5-run.json',dict(**current,cases=len(rows),exit_code=code,build_receipt_sha256=pre.sha(receipt),binary_sha256=pre.sha(binary),result_sha256=pre.sha(folder/'mql5-results.bin'),slice_only=True));print(json.dumps({'cases':len(rows),'exit_code':code}));return
    for n in ['original-run.json','mql5-run.json']:
        record=json.loads((folder/n).read_text());pre.require(all(record[k]==v for k,v in current.items()),'RUN_IDENTITY_DIFFERS')
    n=(folder/'original-results.bin').read_bytes();r=(folder/'mql5-results.bin').read_bytes();pre.require(n[:12]==r[:12]==struct.pack('<3i',MAGIC,1,len(rows)) and len(n)==len(r)==12+SIZE*len(rows),'BAD_RESULTS')
    failed=[]
    for c in rows:
        off=12+c['id']*SIZE
        if n[off:off+SIZE]!=r[off:off+SIZE]:failed.append(dict(id=c['id'],group=c['group'],native=HEADER.unpack_from(n,off),mql5=HEADER.unpack_from(r,off),table_same=n[off+HEADER.size:off+SIZE]==r[off+HEADER.size:off+SIZE]))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:10],slice_only=True,whole_bot_complete=False,hashes={p:pre.sha(folder/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']})
    pre.save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))

if __name__=='__main__':main()
