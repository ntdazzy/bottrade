"""Initial seven-step original/MQL5 check of bot1 virtual-stop state.

Usage: kiem-bang-dung-ao-bot-1.py prepare|original|mql5|compare RUN [--build BUILD]
This is an initial sequence, not complete coverage of the four functions.
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
import time

ROOT=Path(__file__).resolve().parents[1]
MT=ROOT.parent/'.local/claude-recovery-20261023/mt5'
MASK=(1<<64)-1
MAGIC=0x56535431
RECORD_BYTES=40+12000
ANALYSIS=ROOT/'bot-cua-toi-1/phan-tich/dong-vi-the/virtual-stops-20261025-r1'
SEQUENCE=['new-level','cached-level','unstamped-delay','stamp','before-delay-boundary','at-delay-boundary','drop-empty-account']
SOURCES=['Include/bot-cua-toi-1/Bot1VirtualStops.mqh','Include/bot-cua-toi-1/Bot1PriceLevels.mqh',
         'Scripts/bot-cua-toi-1/Bot1VirtualStopsSmoke.mq5']
spec=importlib.util.spec_from_file_location('virtual_entry',Path(__file__).with_name('kiem-gia-vao-bot-1-3.py'))
entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
spec=importlib.util.spec_from_file_location('virtual_validation',Path(__file__).with_name('kiem-khoi-luong-hop-le-bot-1-3.py'))
validation=importlib.util.module_from_spec(spec);spec.loader.exec_module(validation)

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def save(path,value):
    with path.open('x',encoding='utf-8') as stream:json.dump(value,stream,ensure_ascii=False,indent=2)
def require(ok,message):
    if not ok:raise ValueError(message)
def identity():
    home=ROOT/'bot-cua-toi-1/source/MQL5'
    return dict(original_ex5_sha256=validation.original_hash(1),tool_sha256=sha(Path(__file__)),
        sources_sha256={name:sha(home/name) for name in SOURCES},
        dependencies_sha256={name:sha(ROOT/'cong-cu'/name) for name in
            ['kiem-gia-vao-bot-1-3.py','kiem-muc-gia-bot-1-3.py','kiem-khoi-luong-hop-le-bot-1-3.py']},
        analysis_sha256=sha(ANALYSIS/'analysis.json'),api_contract_sha256=sha(ANALYSIS/'api-contract.json'))
def check_identity(record,current):
    for key,value in current.items():require(record.get(key)==value,'CURRENT_IDENTITY_DIFFERS '+key)

class Original(entry.Original):
    def __init__(self):
        super().__init__(1);x=self.x;m=self.m
        analysis=json.loads((ANALYSIS/'analysis.json').read_text())
        require(analysis['original_ex5_sha256']==validation.original_hash(1),'ORIGINAL_EX5_DIFFERS')
        self.ranges={}
        for fn in analysis['functions']:
            lo,hi=int(fn['rva'],16),int(fn['end_rva'],16)
            require(hashlib.sha256(bytes(m.mem_read(self.base+lo,hi-lo))).hexdigest()==fn['native_bytes_sha256'],'NATIVE_CODE_DIFFERS')
            self.ranges[lo]=(hi,{int(v['rva'],16) for v in fn['instructions']})
        self.covered={lo:set() for lo in self.ranges}
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        targets={0x7c2970:1,0x7d1c40:2,0x7aa0e0:3,0x7d7da0:4,
                 0x7d7df0:5,0x7d7fc0:6,0x7b49f0:7,0x3959a0:8}
        prior=set(self.apis)
        self.apis.update({eb+rva:api for rva,api in targets.items()})
        for address in [eb+rva for rva in targets if eb+rva not in prior]:
            page=address&~0xfff
            if not any(lo<=page<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(page,4096)
            m.mem_write(address,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        m.mem_map(0x71000000,0x20000)
        m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base,end=self.base+0x50000)
    def visit(self,m,address,size,user):
        offset=address-self.base
        for lo,(hi,_) in self.ranges.items():
            if lo<=offset<hi:self.covered[lo].add(offset);break
    def trace(self,*words):
        self.calls+=1
        for word in words:
            for byte in struct.pack('<Q',word&MASK):self.hash=((self.hash^byte)*0x100000001b3)&MASK
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address]
        if api==1:
            require(m.reg_read(x.UC_X86_REG_R8)==17,'DIGITS_PROPERTY_DIFFERS')
            descriptor=m.reg_read(x.UC_X86_REG_RDX)
            pointer=struct.unpack('<Q',m.mem_read(descriptor+4,8))[0]
            length=struct.unpack('<I',m.mem_read(pointer-4,4))[0]
            require(bytes(m.mem_read(pointer,length*2)).decode('utf-16-le')=='CHECK','SYMBOL_DIFFERS')
            self.trace(1,17,3,0);m.reg_write(x.UC_X86_REG_RAX,3)
        elif api==2:
            require(m.reg_read(x.UC_X86_REG_RDX)==0,'TIME_CURRENT_OVERLOAD_DIFFERS')
            self.trace(2,0,self.now,0);m.reg_write(x.UC_X86_REG_RAX,self.now&MASK)
        elif api==3:
            descriptor=m.reg_read(x.UC_X86_REG_RDX);count=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            reserve=m.reg_read(x.UC_X86_REG_R9)&0xffffffff
            require(descriptor==self.base+0x6a3c0 and count==64 and reserve==0,'RESIZE_ARGUMENTS_DIFFER')
            m.mem_write(descriptor+8,struct.pack('<I',count))
            m.mem_write(descriptor+28,struct.pack('<Q',0x71000000))
            self.trace(3,count,reserve,count);m.reg_write(x.UC_X86_REG_RAX,count)
        elif api==4:self.trace(4,0,0,0);m.reg_write(x.UC_X86_REG_RAX,0)
        else:raise ValueError('UNEXPECTED_SDK_IN_INITIAL_SEQUENCE '+str(api))
    def run(self):
        m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        m.mem_write(self.base+0x62590,b'\0'*12000)
        m.mem_write(self.base+0x66410,b'\x01');m.mem_write(self.base+0x66418,struct.pack('<q',9))
        m.mem_write(self.base+0x62420,struct.pack('<i',99))
        m.mem_write(self.base+0x66d98,struct.pack('<d',0.1))
        m.mem_write(self.base+0x6a3c0,struct.pack('<Q',0x800010055)+b'\0'*44)
        self.cursor=0x70001000
        m.mem_write(self.base+0x67918,struct.pack('<IQ',0,self.string('CHECK')))
        self.now=1000;output=bytearray(struct.pack('<3i',MAGIC,1,7))
        for case in range(7):
            self.calls=0;self.hash=0xcbf29ce484222325
            for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
                m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
            for index in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(index)),0)
            top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
            fn=0x3d200 if case<2 else 0x3d5a0 if case in [2,4,5] else 0x3d640 if case==3 else 0x18790
            if case<2:
                m.reg_write(x.UC_X86_REG_RCX,case+1)
                m.reg_write(x.UC_X86_REG_XMM1,entry.bits(100.0))
                m.reg_write(x.UC_X86_REG_XMM2,entry.bits(10.0 if case==0 else 100.0))
                m.reg_write(x.UC_X86_REG_R9,7)
            elif case!=6:m.reg_write(x.UC_X86_REG_RCX,7)
            if case==4:self.now=1098
            if case==5:self.now=1099
            m.emu_start(self.base+fn,0x60000000,timeout=5000000,count=2000000)
            require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_DID_NOT_RETURN '+str(case))
            value=m.reg_read(x.UC_X86_REG_XMM0)&MASK if case<2 else m.reg_read(x.UC_X86_REG_RAX)&255 if case in [2,4,5] else 0
            guard=m.mem_read(self.base+0x66410,1)[0];warn=struct.unpack('<Q',m.mem_read(self.base+0x66418,8))[0]
            count=struct.unpack('<i',m.mem_read(self.base+0x6a3c8,4))[0]
            output+=struct.pack('<iQiQiiQ',case,value,guard,warn,count,self.calls,self.hash)+bytes(m.mem_read(self.base+0x62590,12000))
        return bytes(output)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('mode',choices=['prepare','original','mql5','compare'])
    parser.add_argument('run');parser.add_argument('--build');args=parser.parse_args()
    require(bool(re.fullmatch('[a-z0-9-]{1,40}',args.run)),'INVALID_RUN')
    home=ROOT/'bot-cua-toi-1';folder=home/'bang-chung/kiem-bang-dung-ao'/args.run;current=identity()
    if args.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);tested=folder/'tested-sources';tested.mkdir()
        for name in SOURCES:shutil.copyfile(home/'source/MQL5'/name,tested/Path(name).name)
        shutil.copyfile(Path(__file__),tested/'check-tool.py')
        save(folder/'baseline.json',dict(**current,sequence=SEQUENCE,cases=7));print(json.dumps({'cases':7}));return
    baseline=json.loads((folder/'baseline.json').read_text());check_identity(baseline,current)
    if args.mode=='original':
        target=folder/'original-results.bin';require(not target.exists(),'ORIGINAL_RESULT_EXISTS')
        runner=Original();raw=runner.run();target.write_bytes(raw)
        coverage={hex(lo):{'executed':len(runner.covered[lo]),'instructions':len(all_)} for lo,(_,all_) in runner.ranges.items()}
        save(folder/'original-run.json',dict(**current,cases=7,result_sha256=sha(target),coverage=coverage));print(json.dumps({'cases':7,'coverage':coverage}));return
    if args.mode=='mql5':
        require(bool(args.build and re.fullmatch('[a-z0-9-]{1,40}',args.build)),'BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/args.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
        require(receipt['target']==SOURCES[2] and receipt['errors']==receipt['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():
            require(receipt['sources_sha256'][name]==digest==sha(MT/'MQL5'/name),'PRIVATE_OR_COMPILED_SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(SOURCES[2]).with_suffix('.ex5')
        require(sha(binary)==receipt['binary_sha256']==sha(receipt_path.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot1-virtual-smoke'/args.run;files.mkdir(parents=True,exist_ok=False)
        preset=MT/'MQL5/Presets'/f'b1-virtual-smoke-{args.run}.set';ini=MT/f'b1-virtual-smoke-{args.run}.ini'
        with preset.open('x',encoding='utf-16') as stream:stream.write(f'CheckRun={args.run}\n')
        with ini.open('x',encoding='utf-16') as stream:stream.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1VirtualStopsSmoke\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        before=sha(MT/'terminal64.exe');started=time.monotonic()
        process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:
            process.terminate();process.wait(timeout=30);raise RuntimeError('PRIVATE_SCRIPT_TIMEOUT')
        require(code==0 and struct.unpack('<2i',(files/'script-status.bin').read_bytes())==(0,7),'PRIVATE_SCRIPT_DID_NOT_PASS')
        for name in ['mql5-results.bin','script-status.bin']:
            target=folder/name
            with (files/name).open('rb') as reader,target.open('xb') as writer:shutil.copyfileobj(reader,writer)
        save(folder/'mql5-run.json',dict(**current,cases=7,exit_code=code,seconds=round(time.monotonic()-started,2),
            build_receipt_sha256=sha(receipt_path),script_sha256=sha(binary),terminal_sha256_before=before,
            terminal_sha256_after=sha(MT/'terminal64.exe'),result_sha256=sha(folder/'mql5-results.bin')))
        print(json.dumps({'cases':7,'exit_code':code}));return
    for name in ['original-run.json','mql5-run.json']:check_identity(json.loads((folder/name).read_text()),current)
    original=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes()
    require(len(original)==len(actual)==12+7*RECORD_BYTES and original[:12]==actual[:12]==struct.pack('<3i',MAGIC,1,7),'RESULT_SHAPE_DIFFERS')
    failed=[i for i in range(7) if original[12+i*RECORD_BYTES:12+(i+1)*RECORD_BYTES]!=actual[12+i*RECORD_BYTES:12+(i+1)*RECORD_BYTES]]
    report=dict(cases=7,matched=7-len(failed),failed=len(failed),first_failures=failed,
        hashes={name:sha(folder/name) for name in ['baseline.json','original-results.bin','mql5-results.bin','script-status.bin']},
        whole_bot_complete=False,scope='Initial seven-step sequence only: meaningful return bits, all1500 table doubles,guard,reported ticket,array length and ordered SDK-call hashes. SDK values supplied. No positive-position scan,full-table path,array contents/failure,invalid numbers,source error locations,all branches,tester or full EA proof.')
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))

if __name__=='__main__':main()
