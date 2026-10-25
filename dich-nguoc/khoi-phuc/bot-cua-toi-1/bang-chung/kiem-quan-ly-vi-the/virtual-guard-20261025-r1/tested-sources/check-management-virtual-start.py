"""Compare native virtual-management start slices; terminal/child replies supplied.
Usage: check-management-virtual-start.py prepare|original|mql5|compare RUN [--build BUILD]
Only .local/mt5-bot1-thread-20261025 is used. No orders are sent.
"""
import argparse
import importlib.util
import itertools
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess

HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
spec=importlib.util.spec_from_file_location('prelude_start',Path(__file__).with_name('check-management-prelude.py'));pre=importlib.util.module_from_spec(spec);spec.loader.exec_module(pre)
MAGIC=0x4d565331;MT=(ROOT.parent/'.local/mt5-bot1-thread-20261025').resolve()
NAMES=['Include/bot-cua-toi-1/'+n for n in ['Bot1ManagementPrelude.mqh','Bot1PriceLevels.mqh','Bot1PositionModify.mqh','Bot1PositionClose.mqh','Bot1VirtualStops.mqh']]+['Scripts/bot-cua-toi-1/Bot1ManagementVirtualStartCheck.mq5']
RESULT=struct.Struct('<iii6QiQ')
def identity():return dict(original_ex5_sha256=pre.validation.original_hash(1),tool_sha256=pre.sha(Path(__file__)),dependency_sha256=pre.sha(Path(__file__).with_name('check-management-prelude.py')),analysis_sha256=pre.sha(pre.ANALYSIS/'analysis.json'),sources_sha256={n:pre.sha(HOME/'source/MQL5'/n) for n in NAMES})
def base():return dict(id=0,buy=1,delay=1,modify=0,scenario=0,tick_ok=0,digits=[3,2],ticket=7,open=100.,sl=90.,tp=120.,bid=100.,ask=100.,unit=.1,stop=10.,level=95.,point=.01,stage=0,delay_seconds=20,now=1020,opened=1000,activation=1.,distance=3.,freeze=.1,changed=0,trail=3.,trail_step=.1,trail_start=-2.,trail_limit=0.,anchor=100.,volume=1.,table_volume=1.,minimum=.01,strategy_index=0,slippage_enabled=1,distance_passed=1)
def cases():
    rows=[]
    def add(c,group):c.update(id=len(rows),group=group);rows.append(c)
    for buy,delay,modified in itertools.product([0,1],[0,1],[0,1]):
        for sl,level in itertools.product([0.,90.,94.99,95.,95.01,105.,float('nan')],[0.,95.,100.,105.,float('nan'),float('inf')]):
            c=base();c.update(buy=buy,delay=delay,modify=modified,sl=sl,level=level);add(c,'level-sync-boundaries')
    for buy in [0,1]:
        for value in [-float('inf'),-0.,0.,.01,5.,float('inf'),float('nan')]:
            c=base();c.update(buy=buy,point=value,level=95. if buy else 105.,sl=90. if buy else 110.);add(c,'point-values')
        for scenario in [1,2,3]:
            c=base();c.update(buy=buy,scenario=scenario,level=95. if buy else 105.,sl=90. if buy else 110.);add(c,'rereads-and-write-order')
        for ticket in [0,-1,-(1<<63),(1<<53)+2]:
            c=base();c.update(buy=buy,ticket=ticket,level=95. if buy else 105.,sl=90. if buy else 110.);add(c,'ticket64')
        for now in [1019,1020,1021]:
            for activation in [-1.,0.,1.,float('nan')]:
                for changed in [0,1]:
                    c=base();c.update(stage=1,buy=buy,now=now,activation=activation,changed=changed,level=95. if buy else 105.,tp=120. if buy else 80.);add(c,'timed-activation-boundaries')
        for field in ['level','point','distance','unit','freeze','tp']:
            for v in [-float('inf'),-0.,0.,.01,1.,100.,float('inf'),float('nan')]:
                c=base();c.update(stage=1,buy=buy,level=95. if buy else 105.,tp=120. if buy else 80.);c[field]=v;add(c,'timed-numeric-'+field)
        for scenario in [4,5]:
            c=base();c.update(stage=1,buy=buy,level=95. if buy else 105.,tp=120. if buy else 80.,scenario=scenario);add(c,'timed-rereads')
        for opened,delay,now in [((1<<63)-2,20,-(1<<63)+18),(-(1<<63)+2,-20,(1<<63)-18),(1000,-20,980),(1000,0,1000)]:
            c=base();c.update(stage=1,buy=buy,opened=opened,delay_seconds=delay,now=now,level=95. if buy else 105.,tp=120. if buy else 80.);add(c,'timed-signed-addition')
        for field in ['trail','trail_step','trail_start','trail_limit','anchor','volume','table_volume','minimum','point','unit','level']:
            for value in [-float('inf'),-1.,-0.,0.,.01,1.,100.,float('inf'),float('nan')]:
                c=base();c.update(stage=2,buy=buy,level=95. if buy else 105.);c[field]=value;add(c,'distance-numeric-'+field)
        for minimum in [-.01,0.,.01]:
            for index in [0,1,7]:
                c=base();c.update(stage=2,buy=buy,level=95. if buy else 105.,minimum=minimum,strategy_index=index);add(c,'distance-zero-volume-close')
        for scenario in [0,5]:
            c=base();c.update(stage=2,buy=buy,level=95. if buy else 105.,scenario=scenario);add(c,'distance-rereads')
        for enabled,passed in itertools.product([-1,0,1,2],[0,1]):
            c=base();c.update(stage=3,buy=buy,level=95. if buy else 105.,tp=120. if buy else 80.,slippage_enabled=enabled,distance_passed=passed);add(c,'slippage-flags')
        for field in ['trail','trail_start','trail_limit','anchor','freeze','tp','point','unit','level']:
            for value in [-float('inf'),-1.,-0.,0.,.01,1.,100.,float('inf'),float('nan')]:
                c=base();c.update(stage=3,buy=buy,level=95. if buy else 105.,tp=120. if buy else 80.);c[field]=value;add(c,'slippage-numeric-'+field)
        for scenario in [0,5,6]:
            c=base();c.update(stage=3,buy=buy,level=95. if buy else 105.,tp=120. if buy else 80.,scenario=scenario);add(c,'slippage-rereads')
    return rows
def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<14i3q20d',*[c[k] for k in ['id','buy','delay','modify','scenario','tick_ok']],*c['digits'],c['stage'],c['delay_seconds'],c['changed'],c['strategy_index'],c['slippage_enabled'],c['distance_passed'],*[c[k] for k in ['ticket','now','opened']],*[c[k] for k in ['open','sl','tp','bid','ask','unit','stop','level','point','activation','distance','freeze','trail','trail_step','trail_start','trail_limit','anchor','volume','table_volume','minimum']]) for c in rows)

class Original(pre.entry.Original):
    def __init__(self):
        super().__init__(1);self.covered=set();m=self.m;eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        for rva,api in [(0x7c2970,3),(0x7c2890,4),(0x7c2c10,7),(0x7d1c40,9),(0x7b49f0,10)]:
            address=eb+rva
            if address in self.apis:self.apis[address]=api;continue
            if not any(lo<=address<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(address&~4095,4096)
            self.apis[address]=api;m.mem_write(address,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        for rva,api in [(0x3d200,1),(0x3d5a0,2),(0x26d20,5),(0x3d640,6),(0x3d010,8)]:
            self.apis[self.base+rva]=api;m.hook_add(self.uc.UC_HOOK_CODE,self.child,begin=self.base+rva,end=self.base+rva)
        m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x2988b,end=self.base+0x2e453)
        for f in json.loads((pre.ANALYSIS/'analysis.json').read_text())['functions']:
            lo=int(f['rva'],16);hi=int(f['end_rva'],16)
            pre.require(__import__('hashlib').sha256(bytes(m.mem_read(self.base+lo,hi-lo))).hexdigest()==f['native_bytes_sha256'],'NATIVE_CODE_DIFFERS')
    def event(self,api,a=0,b=0,v=0,w=0):self.events.append([api,a&pre.MASK,b&pre.MASK,v&pre.MASK,w&pre.MASK])
    def changed(self,api):
        if (self.case['scenario'],api) in [(1,2),(2,4),(3,5)]:
            value=struct.unpack('<d',self.m.mem_read(self.base+0x62580,8))[0]
            self.m.mem_write(self.base+0x62580,struct.pack('<d',value+1.25))
        if (self.case['scenario'],api) in [(4,9),(5,4),(6,10)]:
            for rva in [0x62580,0x67758,0x67760]:
                value=struct.unpack('<d',self.m.mem_read(self.base+rva,8))[0];self.m.mem_write(self.base+rva,struct.pack('<d',value+1.25))
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        exits={0:[0x29a67,0x2d1b6],1:[0x29aab,0x2a38b,0x2d1fd,0x2db0a],2:[0x29c64,0x2d3d1],3:[0x29de9,0x29eb8,0x29eae,0x2a3b4,0x2d55a,0x2d629,0x2d61f,0x2db33]}[self.case['stage']]
        if off in exits:self.stopped=True;m.emu_stop()
    def child(self,m,address,size,user):
        x=self.x;c=self.case;api=self.apis[address];rcx=m.reg_read(x.UC_X86_REG_RCX);value=0
        if api==1:
            self.event(api,rcx,m.reg_read(x.UC_X86_REG_XMM1)&pre.MASK,m.reg_read(x.UC_X86_REG_XMM2)&pre.MASK,m.reg_read(x.UC_X86_REG_R9))
            m.reg_write(x.UC_X86_REG_XMM0,pre.bits(c['level']))
        elif api==2:self.event(api,rcx,c['delay']);value=c['delay']
        elif api==5:self.event(api,rcx,m.reg_read(x.UC_X86_REG_XMM1)&pre.MASK,m.reg_read(x.UC_X86_REG_XMM2)&pre.MASK,c['modify']);value=c['modify']
        elif api in [6,8]:self.event(api,rcx)
        else:raise ValueError('UNEXPECTED_CHILD')
        self.changed(api)
        if api==8:self.closed=1;self.stopped=True;m.emu_stop();return
        sp=m.reg_read(x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(sp,8))[0]
        m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret);m.reg_write(x.UC_X86_REG_RAX,value)
    def call(self,m,address,size,user):
        c=self.case;x=self.x;api=self.apis[address];prop=m.reg_read(x.UC_X86_REG_R8)
        if api==3:
            pre.require(prop==17 and self.di<2,'BAD_DIGITS_QUERY');value=c['digits'][self.di];self.di+=1;self.event(api,value);m.reg_write(x.UC_X86_REG_RAX,value&pre.MASK)
        elif api==4:
            pre.require(prop in [16,34],'BAD_SYMBOL_DOUBLE_QUERY');value=c['point' if prop==16 else 'minimum'];self.event(api,prop,pre.bits(value));m.mem_write(self.base+0x6a448,struct.pack('<d',value));m.reg_write(x.UC_X86_REG_XMM0,pre.bits(value))
        elif api==7:
            self.event(api,pre.entry.text_hash('CHECK'),c['tick_ok'],pre.bits(c['bid']),pre.bits(c['ask']));m.reg_write(x.UC_X86_REG_RAX,c['tick_ok'])
            if c['tick_ok']:m.mem_write(self.base+0x67758,struct.pack('<2d',c['bid'],c['ask']))
        elif api==9:
            pre.require(m.reg_read(x.UC_X86_REG_RDX)==0,'BAD_TIME_OVERLOAD');self.event(api,c['now']);m.reg_write(x.UC_X86_REG_RAX,c['now']&pre.MASK)
        elif api==10:
            pre.require(m.reg_read(x.UC_X86_REG_RDX)==2 and prop==1 and m.reg_read(x.UC_X86_REG_R9)==0x590008,'BAD_PRINT')
            descriptor=struct.unpack('<Q',m.mem_read(m.reg_read(x.UC_X86_REG_RSP)+0x28,8))[0]
            pointer=struct.unpack('<Q',m.mem_read(descriptor+4,8))[0];length=struct.unpack('<I',m.mem_read(pointer-4,4))[0]
            pre.require(length<200,'PRINT_TOO_LONG');text=bytes(m.mem_read(pointer,length*2)).decode('utf-16-le')
            self.event(api,pre.entry.text_hash(text));m.reg_write(x.UC_X86_REG_RAX,0)
        else:raise ValueError('UNEXPECTED_API '+str(api))
        self.changed(api)
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.closed=0;self.stopped=False;self.events=[];self.di=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        for rva,value in [(0x62498,c['stop']),(0x66d98,c['unit']),(0x62580,666. if c['stage']==0 else c['level']),(0x624f8,c['activation']),(0x62500,c['distance']),(0x67468,c['freeze'])]:m.mem_write(self.base+rva,struct.pack('<d',value))
        m.mem_write(self.base+0x6745c,struct.pack('<i',c['delay_seconds']))
        for rva,key in [(0x624a8,'trail'),(0x624c0,'trail_step'),(0x624b0,'trail_start'),(0x624b8,'trail_limit')]:m.mem_write(self.base+rva,struct.pack('<d',c[key]))
        for rva,key in [(0x62400,'trail'),(0x623f8,'trail_start'),(0x62408,'trail_limit')]:m.mem_write(self.base+rva,struct.pack('<d',c[key]))
        m.mem_write(self.base+0x623f0,struct.pack('<i',c['slippage_enabled']))
        m.mem_write(self.base+0x678f4,struct.pack('<I',c['strategy_index']));m.mem_write(self.base+0x66a80+8*c['strategy_index'],struct.pack('<d',c['table_volume']))
        m.mem_write(self.base+0x67758,struct.pack('<2d',c['bid'],c['ask']))
        m.reg_write(x.UC_X86_REG_RSI,0x23e575eae78);m.reg_write(x.UC_X86_REG_RDI,self.base+0x67918);m.reg_write(x.UC_X86_REG_R13,self.base+0x6a448)
        m.reg_write(x.UC_X86_REG_R15,self.base+(0x67758 if c['buy'] else 0x67760));m.reg_write(x.UC_X86_REG_RBP,c['ticket']&pre.MASK)
        for reg,key in [(6,'open'),(7,'tp'),(8,'sl')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(reg)),pre.bits(c[key]))
        sp=0x50020000-0x208;m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_R12,c['changed'])
        m.mem_write(sp+(0x70 if c['buy'] else 0x80),struct.pack('<q',c['opened']))
        m.mem_write(sp+0x88,struct.pack('<d',c['anchor']));m.mem_write(sp+0xa8,struct.pack('<d',c['volume']))
        m.mem_write(sp+(0x5c if c['buy'] else 0x6c),struct.pack('<i',c['distance_passed']))
        m.reg_write(x.UC_X86_REG_XMM12,pre.bits(c['volume']));m.reg_write(x.UC_X86_REG_XMM15,pre.bits(c['anchor']))
        m.reg_write(x.UC_X86_REG_XMM14,pre.bits(c['anchor']))
        start={0:(0x2988b,0x2cfcb),1:(0x29a67,0x2d1b6),2:(0x29aab,0x2d1fd),3:(0x29c64,0x2d3d1)}[c['stage']][0 if c['buy'] else 1]
        m.emu_start(self.base+start,0x60000000,timeout=5000000,count=100000)
        pre.require(self.stopped,'BOUNDARY_MISSING '+str(c['id']))
        h=0xcbf29ce484222325
        for event in self.events:
            for b in struct.pack('<5Q',*event):h=((h^b)*0x100000001b3)&pre.MASK
        current=struct.unpack('<Q',m.mem_read(self.base+0x62580,8))[0];tick=struct.unpack('<2Q',m.mem_read(self.base+0x67758,16))
        # XMM8 is a comparison scratch register at this boundary (sl +/- point).
        # The meaningful stop output is the last stop actually passed to modify.
        modifications=[event for event in self.events if event[0]==5]
        requested_sl=modifications[-1][2] if modifications else pre.bits(c['sl'])
        changed=c['changed'] if c['stage']==0 else int((m.reg_read(x.UC_X86_REG_R12)&255)!=0)
        return RESULT.pack(c['id'],self.closed,changed,pre.bits(c['level']),current,requested_sl,pre.bits(c['tp']),*tick,len(self.events),h)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();pre.require(bool(re.fullmatch('[a-z0-9-]{1,50}',a.run)),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));pre.save(folder/'cases.json',rows);tested=folder/'tested-sources';tested.mkdir()
        for n in NAMES:shutil.copyfile(HOME/'source/MQL5'/n,tested/Path(n).name)
        shutil.copyfile(Path(__file__),tested/Path(__file__).name);pre.save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=pre.sha(folder/'cases.bin'),slice_only=True));print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((folder/'baseline.json').read_text());pre.require(all(baseline[k]==v for k,v in current.items()),'IDENTITY_DIFFERS');pre.require((folder/'cases.bin').read_bytes()==encode(rows),'INPUTS_DIFFERS')
    if a.mode=='original':
        target=folder/'original-results.bin';pre.require(not target.exists(),'RESULT_EXISTS');runner=Original();data=struct.pack('<3i',MAGIC,1,len(rows))+b''.join(runner.run(c) for c in rows);target.write_bytes(data)
        pre.save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=pre.sha(target),executed_instructions=sorted(hex(v) for v in runner.covered),slice_only=True));print(json.dumps({'cases':len(rows),'instructions':len(runner.covered)}));return
    if a.mode=='mql5':
        pre.require(a.build is not None,'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));pre.require(build['target']==NAMES[-1] and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,v in current['sources_sha256'].items():pre.require(build['sources_sha256'][n]==v==pre.sha(MT/'MQL5'/n),'SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5');pre.require(pre.sha(binary)==build['binary_sha256']==pre.sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot1-management-virtual-start'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b1-virtual-start-{a.run}.set'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        ini=MT/f'b1-virtual-start-{a.run}.ini'
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ManagementVirtualStartCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        pre.require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_NOT_PASSED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        pre.save(folder/'mql5-run.json',dict(**current,cases=len(rows),exit_code=code,binary_sha256=pre.sha(binary),build_receipt_sha256=pre.sha(receipt),result_sha256=pre.sha(folder/'mql5-results.bin'),slice_only=True));print(json.dumps({'cases':len(rows),'exit_code':code}));return
    for n in ['original-run.json','mql5-run.json']:
        record=json.loads((folder/n).read_text());pre.require(all(record[k]==v for k,v in current.items()),'RUN_IDENTITY_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();pre.require(native[:12]==actual[:12]==struct.pack('<3i',MAGIC,1,len(rows)) and len(native)==len(actual)==12+RESULT.size*len(rows),'BAD_RESULTS')
    failed=[]
    for c in rows:
        off=12+c['id']*RESULT.size;n=RESULT.unpack_from(native,off);r=RESULT.unpack_from(actual,off)
        if n!=r:failed.append(dict(id=c['id'],group=c['group'],native=n,mql5=r))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:10],slice_only=True,whole_bot_complete=False,hashes={n:pre.sha(folder/n) for n in ['cases.bin','original-results.bin','mql5-results.bin']},limits=['Only native virtual-start slices; remaining virtual trailing and outer management not executed.','Virtual-table, delay, stamp, modify and close children supplied at call boundary; children separately verified.'])
    pre.save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
