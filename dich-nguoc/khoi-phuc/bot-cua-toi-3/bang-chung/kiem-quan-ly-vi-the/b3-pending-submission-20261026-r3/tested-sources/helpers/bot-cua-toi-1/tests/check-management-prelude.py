"""Run the bot1 management prefix to an explicit native boundary; compare with MQL5.

python -I -B -X utf8 .../check-management-prelude.py prepare|original|mql5|compare RUN
MQL5 mode requires --build BUILD and --terminal the dedicated bot1 thread terminal.
Original management instructions execute unchanged, with supplied terminal replies.
Only calls to the already separately tested modify/close children are intercepted.
This is a prefix comparison, not a full management-function or full-EA comparison.
"""
import argparse
import copy
import hashlib
import importlib.util
import itertools
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

HOME=Path(__file__).resolve().parents[1]
ROOT=HOME.parent
MAGIC=0x4d505231
MASK=(1<<64)-1
ANALYSIS=HOME/'phan-tich/dong-vi-the/management-20261025-r1'
NAMES=['Include/bot-cua-toi-1/'+s for s in ['Bot1ManagementPrelude.mqh','Bot1PriceLevels.mqh','Bot1PositionModify.mqh','Bot1PositionClose.mqh','Bot1VirtualStops.mqh']]+['Scripts/bot-cua-toi-1/Bot1ManagementPreludeCheck.mq5']
RESULT=struct.Struct('<iiQi5Q3q2Q2i2QiQ')
spec=importlib.util.spec_from_file_location('entry_prelude',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py')
entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
spec=importlib.util.spec_from_file_location('validate_prelude',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py')
validation=importlib.util.module_from_spec(spec);spec.loader.exec_module(validation)

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def require(ok,message):
    if not ok:raise ValueError(message)
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2)
def signed(value):return struct.unpack('<q',struct.pack('<Q',value&MASK))[0]
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def identity():
    return dict(original_ex5_sha256=validation.original_hash(1),tool_sha256=sha(Path(__file__)),analysis_sha256=sha(ANALYSIS/'analysis.json'),sources_sha256={name:sha(HOME/'source/MQL5'/name) for name in NAMES})
def base():
    return dict(id=0,buy=1,scenario=0,ticket=7,type=0,magic=9001,expected_magic=9001,enabled=1,
                digits=[3]*5,sl=95.,tp=110.,open=100.,volume=.1,unit=.1,stop=10.,take=20.,
                tick_ok=1,bid=99.,ask=101.,opened=1000,times=[900,1100,900,1100],
                candle_on=[0,0],timeframes=[15,1],closes=[90.,91.,92.,93.],opens=[95.,96.],
                symbol='CHECK',symbol_null=0,position_symbol='CHECK',position_null=0,comment='note')
def cases():
    out=[]
    def add(row,group):row.update(id=len(out),group=group);out.append(row)
    for buy in [0,1]:
        for sl,tp,ticket in itertools.product([0.,95.],[0.,110.],[0,1,(1<<53)+1,1<<63,MASK]):
            c=base();c.update(buy=buy,type=1-buy,sl=sl,tp=tp,ticket=ticket);add(c,'initial-levels-ticket64')
        for field,values in [('type',[-1,0,1,2,1<<32,(1<<32)+1]),('magic',[-1,9000,9001,9001+(1<<32)]),('enabled',[-1,0,1,2])]:
            for v in values:
                c=base();c.update(buy=buy,type=1-buy);c[field]=v;add(c,'filter-'+field)
        for a,b,an,bn in [('CHECK','OTHER',0,0),('','',0,0),('','',1,0),('','',0,1),('','',1,1),('Vàng.💰','Vàng.💰',0,0)]:
            c=base();c.update(buy=buy,type=1-buy,symbol=a,position_symbol=b,symbol_null=an,position_null=bn);add(c,'symbol-null-and-unicode')
        for field in ['sl','tp','open','unit','stop','take']:
            for value in [-float('inf'),-1e19,-100.005,-0.,0.,1.005,1e19,float('inf'),float('nan')]:
                c=base();c.update(buy=buy,type=1-buy,sl=0.,tp=0.);c[field]=value;add(c,'numeric-'+field)
        for digit in [-1,0,2,8,11,12]:
            c=base();c.update(buy=buy,type=1-buy,sl=0.,tp=0.,digits=[digit,2,8,11,3]);add(c,'digits-rereads')
        for flag,toggle in itertools.product([0,1,2,255],[0,1,2,255]):
            c=base();c.update(buy=buy,type=1-buy,candle_on=[flag,flag],timeframes=[255,toggle]);add(c,'candle-byte-conditions')
        for opened in [899,900,901,1000,1099,1100,1101]:
            for close,open_ in [(99.,101.),(101.,99.),(100.,100.),(99.,100.),(101.,100.),(float('nan'),100.),(100.,float('nan'))]:
                c=base();c.update(buy=buy,type=1-buy,opened=opened,candle_on=[1,1],closes=[close]*4,opens=[open_]*2);add(c,'candle-boundaries')
        for closes in [[90.,110.,110.,90.],[110.,90.,90.,110.],[float('nan'),90.,90.,110.]]:
            c=base();c.update(buy=buy,type=1-buy,candle_on=[1,1],closes=closes,opens=[100.,100.]);add(c,'close-reread')
        for ok in [0,1]:
            c=base();c.update(buy=buy,type=1-buy,tick_ok=ok,candle_on=[1,1]);add(c,'tick-failure-continues')
    return out

def pack_text(text,null=0):
    raw=text.encode('utf-16-le');return struct.pack('<2i',null,len(raw)//2)+raw
def encode(rows):
    b=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        b+=struct.pack('<3iQ2q2i5i7d3i2dq4q4i6d',c['id'],c['buy'],c['scenario'],c['ticket'],c['type'],c['magic'],c['expected_magic'],c['enabled'],*c['digits'],*[c[k] for k in ['sl','tp','open','volume','unit','stop','take']],c['tick_ok'],0,0,c['bid'],c['ask'],c['opened'],*c['times'],*c['candle_on'],*c['timeframes'],*c['closes'],*c['opens'])
        b+=pack_text(c['symbol'],c['symbol_null'])+pack_text(c['position_symbol'],c['position_null'])+pack_text(c['comment'])
    return bytes(b)

class Original(entry.Original):
    def __init__(self):
        super().__init__(1);m=self.m
        require(validation.original_hash(1)==json.loads((ANALYSIS/'analysis.json').read_text())['original_ex5_sha256'],'EX5_DIFFERS')
        self.covered=set();self.rows=json.loads((ANALYSIS/'analysis.json').read_text())['functions']
        for f in self.rows:
            lo=int(f['rva'],16);hi=int(f['end_rva'],16)
            require(hashlib.sha256(bytes(m.mem_read(self.base+lo,hi-lo))).hexdigest()==f['native_bytes_sha256'],'NATIVE_BYTES_DIFFERS')
        eb=next(addr for addr,api in self.apis.items() if api==1)-0x7d3c40
        targets={0x7c2970:1,0x7d7df0:2,0x7d7f70:3,0x7d7fc0:4,0x7d8010:5,0x7c2c10:6,0x7b49f0:7,0x7d3b50:10,0x7d3d40:11,0x7d3bc0:12,0x7d7da0:13}
        for rva,api in targets.items():
            addr=eb+rva
            if addr in self.apis:self.apis[addr]=api;continue
            if not any(lo<=addr<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(addr&~4095,4096)
            self.apis[addr]=api;m.mem_write(addr,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
        m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x271f0,end=self.base+0x2e6c1)
        for rva,api in [(0x26d20,8),(0x3d010,9)]:
            m.hook_add(self.uc.UC_HOOK_CODE,self.child,begin=self.base+rva,end=self.base+rva);self.apis[self.base+rva]=api
    def text(self,desc):
        p=struct.unpack('<Q',self.m.mem_read(desc+4,8))[0]
        if not p:return '',1
        n=struct.unpack('<I',self.m.mem_read(p-4,4))[0];require(n<=4096,'BAD_STRING_LENGTH')
        return bytes(self.m.mem_read(p,n*2)).decode('utf-16-le'),0
    def event(self,api,a=0,b=0,v=0,w=0):
        self.events.append([api,a&MASK,b&MASK,v&MASK,w&MASK])
    def child(self,m,address,size,user):
        x=self.x;api=self.apis[address];ticket=m.reg_read(x.UC_X86_REG_RCX)
        self.event(api,ticket,m.reg_read(x.UC_X86_REG_XMM1)&MASK if api==8 else 0,m.reg_read(x.UC_X86_REG_XMM2)&MASK if api==8 else 0)
        sp=m.reg_read(x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(sp,8))[0]
        m.reg_write(x.UC_X86_REG_RAX,0);m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret)
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        if off in [0x27c51,0x2b667]:self.accepted=1;m.emu_stop()
        if off in [0x27333,0x2ad03,0x27357,0x2ad25]:self.accepted=0;m.emu_stop()
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address];c=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        a=m.reg_read(x.UC_X86_REG_RDX);b=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
        if api==1:
            require(b==17,'BAD_SYMBOL_PROPERTY');text,null=self.text(a)
            value=c['digits'][self.di];self.di+=1
            self.event(api,b,entry.text_hash(text),value,null);m.reg_write(x.UC_X86_REG_RAX,value&MASK)
        elif api==2:
            require(a==0,'BAD_INDEX');self.event(api,a,0,c['ticket']);m.reg_write(x.UC_X86_REG_RAX,c['ticket'])
        elif api in [3,4,5]:
            if api==3:
                require(a in [6,7,4,3],'BAD_POSITION_DOUBLE');value=c[{6:'sl',7:'tp',4:'open',3:'volume'}[a]]
                m.mem_write(self.base+0x6a448,struct.pack('<d',value));m.reg_write(x.UC_X86_REG_XMM0,bits(value));self.event(api,a,0,bits(value))
            elif api==4:
                require(a in [1,2,12],'BAD_POSITION_INTEGER');value=c[{1:'opened',2:'type',12:'magic'}[a]]
                self.event(api,a,0,value);m.reg_write(x.UC_X86_REG_RAX,value&MASK)
            else:
                require(a in [0,11],'BAD_POSITION_STRING');text=c['position_symbol'] if a==0 else c['comment'];null=c['position_null'] if a==0 else 0
                m.mem_write(self.base+0x6a43c,struct.pack('<IQ',0,0 if null else self.string(text)))
                self.event(api,a,entry.text_hash(text),null)
        elif api==6:
            require(m.reg_read(x.UC_X86_REG_R8)==self.base+0x67750,'BAD_TICK_OUTPUT')
            text,null=self.text(a);self.event(api,entry.text_hash(text),c['tick_ok'],bits(c['bid']),bits(c['ask']))
            if c['tick_ok']:m.mem_write(self.base+0x67758,struct.pack('<2d',c['bid'],c['ask']))
            m.reg_write(x.UC_X86_REG_RAX,c['tick_ok'])
        elif api==7:
            require(a==2 and b==1 and m.reg_read(x.UC_X86_REG_R9)==0x590008,'BAD_PRINT_SIGNATURE')
            ptr=struct.unpack('<Q',m.mem_read(m.reg_read(x.UC_X86_REG_RSP)+0x28,8))[0];text,null=self.text(ptr)
            self.event(api,entry.text_hash(text));m.reg_write(x.UC_X86_REG_RAX,0)
        elif api in [10,11,12]:
            text,null=self.text(a);shift=m.reg_read(x.UC_X86_REG_R9)&0xffffffff
            if api==10:value=c['times'][self.ti];self.ti+=1
            elif api==11:value=c['closes'][self.ci];self.ci+=1
            else:value=c['opens'][self.oi];self.oi+=1
            raw=value if api==10 else bits(value);self.event(api,b,shift,raw,entry.text_hash(text))
            if api==10:m.reg_write(x.UC_X86_REG_RAX,value&MASK)
            else:m.mem_write(self.base+0x6a448,struct.pack('<Q',raw));m.reg_write(x.UC_X86_REG_XMM0,raw)
        elif api==13:m.reg_write(x.UC_X86_REG_RAX,1)
        else:raise ValueError('UNEXPECTED_API '+str(api))
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.events=[];self.accepted=-1;self.di=self.ti=self.ci=self.oi=0
        self.cursor=0x70001000;self.allocs=self.frees=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        for addr,value in [(0x6246c,c['expected_magic']),(0x62428,c['enabled'])]:m.mem_write(self.base+addr,struct.pack('<i',value))
        for addr,key in [(0x62498,'stop'),(0x624a0,'take'),(0x66d98,'unit')]:m.mem_write(self.base+addr,struct.pack('<d',c[key]))
        for addr,value in [(0x62265,c['candle_on'][0]),(0x62267,c['candle_on'][1]),(0x62264,c['timeframes'][0]),(0x62266,c['timeframes'][1])]:m.mem_write(self.base+addr,bytes([value]))
        m.mem_write(self.base+0x67918,struct.pack('<IQ',0,0 if c['symbol_null'] else self.string(c['symbol'])))
        m.mem_write(self.base+0x67758,struct.pack('<2d',-100.,-101.))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.emu_start(self.base+(0x271f0 if c['buy'] else 0x2abc0),0x60000000,timeout=5000000,count=2000000)
        require(self.accepted in [0,1],'PREFIX_BOUNDARY_NOT_REACHED '+str(c['id']))
        present=int(c['ticket']!=0);sp=m.reg_read(x.UC_X86_REG_RSP)
        if present:
            values=[m.reg_read(getattr(x,'UC_X86_REG_XMM'+str(n)))&MASK for n in [8,7,9,6]]+[bits(c['volume'])]
            comment=self.text(sp+(0x90 if c['buy'] else 0x98));symbol=self.text(sp+(0x78 if c['buy'] else 0x88))
        else:values=[0]*5;comment=('',1);symbol=('',1)
        h=0xcbf29ce484222325
        for event in self.events:
            for byte in struct.pack('<5Q',*event):h=((h^byte)*0x100000001b3)&MASK
        tick=struct.unpack('<2Q',m.mem_read(self.base+0x67758,16))
        return RESULT.pack(c['id'],self.accepted,c['ticket'],present,*values,*([c['opened'],c['type'],c['magic']] if present else [0,0,0]),entry.text_hash(comment[0]),entry.text_hash(symbol[0]),comment[1],symbol[1],*tick,len(self.events),h)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');p.add_argument('--terminal',type=Path);a=p.parse_args()
    require(bool(re.fullmatch('[a-z0-9-]{1,50}',a.run)),'INVALID_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity();rows=cases()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows)
        tested=folder/'tested-sources';tested.mkdir()
        for name in NAMES:shutil.copyfile(HOME/'source/MQL5'/name,tested/Path(name).name)
        shutil.copyfile(Path(__file__),tested/Path(__file__).name)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),prefix_only=True));print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((folder/'baseline.json').read_text())
    require(all(baseline[k]==v for k,v in current.items()),'IDENTITY_CHANGED')
    require((folder/'cases.bin').read_bytes()==encode(rows),'INPUTS_CHANGED')
    if a.mode=='original':
        require(not (folder/'original-results.bin').exists(),'ORIGINAL_EXISTS');runner=Original();raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
        trace=[]
        for c in rows:
            raw+=runner.run(c)
            if c['id'] in [0,4,20,50,80,100,200,300]:trace.append(dict(id=c['id'],events=copy.deepcopy(runner.events)))
        (folder/'original-results.bin').write_bytes(raw)
        save(folder/'original-traces.json',trace)
        coverage={f['rva']:len({int(v['rva'],16) for v in f['instructions']}&runner.covered) for f in runner.rows}
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),executed_instructions=coverage,prefix_only=True))
        print(json.dumps({'cases':len(rows),'coverage':coverage,'prefix_only':True}));return
    if a.mode=='mql5':
        require(a.terminal is not None and a.build is not None,'BUILD_AND_TERMINAL_REQUIRED')
        terminal=a.terminal.resolve();expected=(ROOT.parent/'.local/mt5-bot1-thread-20261025').resolve()
        require(terminal==expected,'WRONG_PRIVATE_TERMINAL')
        receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==NAMES[-1] and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(build['sources_sha256'][name]==digest==sha(terminal/'MQL5'/name),'SOURCE_DIFFERS')
        binary=terminal/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5')
        require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=terminal/'MQL5/Files/bot1-management-prelude'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=terminal/'MQL5/Presets'/f'b1-prelude-{a.run}.set';preset.parent.mkdir(exist_ok=True)
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        ini=terminal/f'b1-prelude-{a.run}.ini'
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ManagementPreludeCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        before=sha(terminal/'terminal64.exe');start=time.monotonic()
        proc=subprocess.Popen(f'"{terminal/"terminal64.exe"}" /portable /config:"{ini}"',cwd=terminal,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MQL5_TIMEOUT')
        require(code==0,'MQL5_EXIT_NONZERO')
        require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_STATUS_DIFFERS')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,exit_code=code,cases=len(rows),seconds=round(time.monotonic()-start,2),build_receipt_sha256=sha(receipt),binary_sha256=sha(binary),terminal_sha256_before=before,terminal_sha256_after=sha(terminal/'terminal64.exe'),result_sha256=sha(folder/'mql5-results.bin'),prefix_only=True));print(json.dumps({'cases':len(rows),'exit_code':code}));return
    for name in ['original-run.json','mql5-run.json']:
        record=json.loads((folder/name).read_text());require(all(record[k]==v for k,v in current.items()),'RUN_IDENTITY_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes()
    require(native[:12]==actual[:12]==struct.pack('<3i',MAGIC,1,len(rows)),'BAD_HEADER')
    require(len(native)==len(actual)==12+RESULT.size*len(rows),'BAD_RESULT_SIZE')
    failures=[]
    for c in rows:
        offset=12+c['id']*RESULT.size;n=RESULT.unpack_from(native,offset);r=RESULT.unpack_from(actual,offset)
        if n!=r:failures.append(dict(id=c['id'],group=c['group'],native=list(n),mql5=list(r)))
    report=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:12],prefix_only=True,whole_bot_complete=False,hashes={n:sha(folder/n) for n in ['cases.bin','original-results.bin','mql5-results.bin']},limits=['Native stopped at documented prefix boundary; later management branches not executed.','Terminal replies supplied; modify/close children intercepted, separately verified in earlier runs.','No real trades, full EA, allocation-failure or restart proof.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failures))

if __name__=='__main__':main()
