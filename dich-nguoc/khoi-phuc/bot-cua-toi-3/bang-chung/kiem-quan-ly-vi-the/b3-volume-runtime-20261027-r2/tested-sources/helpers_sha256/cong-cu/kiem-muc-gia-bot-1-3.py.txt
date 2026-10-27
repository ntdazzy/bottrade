"""Compare reconstructed price-level functions with captured native instructions.

Usage: python -I -B -X utf8 kiem-muc-gia-bot-1-3.py prepare|original|mql5|compare BOT RUN
Only iHigh/iLow and symbol digits are supplied as test data. No orders are sent.
This proves component behavior for the cases, not the complete EA or profitability.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import re
import shutil
import struct
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[1]
LOCAL = ROOT.parent / '.local'
MT = LOCAL / 'claude-recovery-20261023/mt5'
MASK = (1 << 64) - 1
MAGIC = 0x50495631
CONFIG = {
    1: {'high': 0x32890, 'low': 0x32ac0, 'scan': 0x624e0, 'gap': 0x66a70,
        'bid': 0x67758, 'ask': 0x67760, 'slot': 0x6a448},
    3: {'high': 0x3e040, 'low': 0x3e270, 'scan': 0x6d5d0, 'gap': 0x73ab0,
        'bid': 0x74798, 'ask': 0x747a0, 'slot': 0x1d6e48},
}

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def make_cases():
    rng = random.Random(13012026)
    cases = []
    for lower in [0, 1]:
        for i in range(400):
            center = rng.choice([0.0, -100.0, 100.0, 2600.0, 9000.0])
            prices = [center + rng.uniform(-20, 20) for _ in range(48)]
            cases.append([lower, 15, rng.randrange(6), rng.randrange(6), rng.randrange(32),
                          rng.choice([-1,0,1,2,3,5,8,9,10,11,12]), center+rng.uniform(-25,25),
                          rng.choice([0.0,0.001,0.5,5.0,-1.0]), prices])
        for value in [0.0,-0.0,1.005,-1.005,853.015,-853.015,9999.0,1e19,-1e19,
                      float('nan'),float('inf'),-float('inf')]:
            for digits in [0,2,8,11]:
                for quote in [-1e20, 0.0, 1e20]:
                    cases.append([lower, 16385, 0, 0, 3, digits, quote, 0.0, [value]*8])
        for older,recent,last,size in [(0,0,0,8),(2,2,0,8),(2,2,2,8),(4,4,20,8),(0,0,3,0)]:
            cases.append([lower, 15, older, recent, last, 3, 10.0, 0.0, [10.0]*size])
        for delta in [-0.00000001,0.0,0.00000001]:
            cases.append([lower,15,1,1,4,8,10.0,0.5,[9.0,9.0,10.5+delta,9.0,9.0,9.0]])
    return cases

def encode_cases(cases):
    raw = bytearray(struct.pack('<3i', MAGIC, 1, len(cases)))
    for i, (lower,tf,older,recent,last,digits,quote,gap,prices) in enumerate(cases):
        raw += struct.pack('<8i2d', i,lower,tf,older,recent,last,digits,len(prices),quote,gap)
        raw += struct.pack('<'+'d'*len(prices), *prices)
    return raw

def read_cases(path):
    raw=path.read_bytes(); magic,version,count=struct.unpack_from('<3i',raw); pos=12; cases=[]
    if (magic,version)!=(MAGIC,1): raise ValueError('BAD_CASE_HEADER')
    for _ in range(count):
        row=struct.unpack_from('<8i2d',raw,pos);pos+=48
        prices=list(struct.unpack_from('<'+'d'*row[7],raw,pos));pos+=8*row[7]
        cases.append([*row[:7],row[8],row[9],prices])
    if pos!=len(raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return cases

class Original:
    def __init__(self,bot):
        sys.path.insert(0,str(LOCAL/'claude-recovery-20261023/python'))
        import unicorn as uc
        from unicorn import x86_const as x
        self.uc,self.x=uc,x;self.m=uc.Uc(uc.UC_ARCH_X86,uc.UC_MODE_64);self.cfg=CONFIG[bot]
        capdir=ROOT/f'bot-cua-toi-{bot}/bang-chung/captures/luot-20261023-r1'
        cap=json.loads((capdir/'capture.json').read_text())
        self.regions=[]
        for region in cap['regions']:
            path=capdir/region['file'];raw=path.read_bytes()
            if sha(path)!=region['sha256']:raise ValueError('CAPTURE_HASH_MISMATCH')
            self.m.mem_map(region['base'],region['bytes']);self.m.mem_write(region['base'],raw)
            self.regions.append((region,raw))
        code=max((v[0] for v in self.regions if v[0].get('kind')=='executable'),key=lambda v:v['bytes'])
        self.base=code['base']
        engine=json.loads((ROOT/f'bot-cua-toi-{bot}/bang-chung/luot-20261023-r1/engine-observed.json').read_text(encoding='utf-8-sig'))
        if engine['pid']!=cap['pid'] or engine['engine_sha256']!='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb':
            raise ValueError('UNVERIFIED_ENGINE')
        eb=int(engine['engine_base'],16)
        self.apis={eb+0x7d3c40:1,eb+0x7d3cc0:2,eb+0x7c2970:3}
        for page in {addr&~0xfff for addr in self.apis}:self.m.mem_map(page,4096)
        for addr in self.apis:
            self.m.mem_write(addr,b'\xc3');self.m.hook_add(uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
        self.m.mem_map(0x50000000,0x20000);self.m.mem_map(0x60000000,4096)
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address]
        if api in [1,2]:
            first=struct.unpack('<i',struct.pack('<I',m.reg_read(x.UC_X86_REG_R9)&0xffffffff))[0]
            second=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            value=self.case[-1][first] if 0<=first<len(self.case[-1]) else 0.0
            raw=struct.pack('<d',value);m.mem_write(self.base+self.cfg['slot'],raw)
            m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'))
        else:
            first=m.reg_read(x.UC_X86_REG_R8)&0xffffffff;second=0
            if first!=17:raise ValueError('UNEXPECTED_SYMBOL_PROPERTY')
            m.reg_write(x.UC_X86_REG_RAX,self.case[6]&MASK)
        self.count+=1
        for word in [api,first&MASK,second&MASK]:
            for byte in struct.pack('<Q',word):self.hash=((self.hash^byte)*0x100000001b3)&MASK
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.count=0;self.hash=0xcbf29ce484222325
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        _,lower,tf,older,recent,last,digits,quote,gap,prices=c
        for field,value in [('bid',quote),('ask',quote),('gap',gap)]:m.mem_write(self.base+self.cfg[field],struct.pack('<d',value))
        m.mem_write(self.base+self.cfg['scan'],struct.pack('<i',last))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.reg_write(x.UC_X86_REG_RCX,tf&0xffffffff);m.reg_write(x.UC_X86_REG_RDX,older&0xffffffff);m.reg_write(x.UC_X86_REG_R8,recent&0xffffffff)
        m.emu_start(self.base+self.cfg['low' if lower else 'high'],0x60000000,timeout=5000000,count=2000000)
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise RuntimeError('ORIGINAL_DID_NOT_RETURN '+str(c[0]))
        return (c[0],m.reg_read(x.UC_X86_REG_XMM0)&MASK,self.count,self.hash)

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-muc-gia'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);cases=make_cases();(out/'cases.bin').write_bytes(encode_cases(cases));print(json.dumps({'cases':len(cases)}));return
    if a.mode=='original':
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        cases=read_cases(out/'cases.bin');original=Original(a.bot);start=time.monotonic()
        rows=[original.run(c) for c in cases]
        target.write_bytes(struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<iQIQ',*r) for r in rows))
        record={'cases':len(rows),'seconds':round(time.monotonic()-start,2),'result_sha256':sha(target),'inputs_sha256':sha(out/'cases.bin'),'native_rvas':CONFIG[a.bot]}
        (out/'original-run.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        files=MT/f'MQL5/Files/bot{a.bot}-price-levels'
        if files.exists():raise FileExistsError('CHECK_FILES_DIRECTORY_EXISTS')
        files.mkdir();shutil.copyfile(out/'cases.bin',files/'cases.bin')
        ini=MT/f'bot{a.bot}-price-levels.ini'
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PriceLevelsCheck\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();proc=subprocess.Popen(f'"{MT / "terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:
            proc.terminate();proc.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if not (files/'mql5-results.bin').is_file():raise RuntimeError('MQL5_RESULTS_MISSING '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target)
        script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PriceLevelsCheck.ex5'
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),'script_sha256':sha(script),'results_sha256':sha(target)},indent=2),encoding='utf-8');print('MQL5 results saved');return
    orig=(out/'original-results.bin').read_bytes();reco=(out/'mql5-results.bin').read_bytes()
    count=struct.unpack_from('<3i',orig)[2]
    if orig[:12]!=reco[:12] or len(orig)!=12+24*count or len(reco)!=len(orig):raise ValueError('RESULT_SHAPE_MISMATCH')
    failures=[]
    for i in range(count):
        x=struct.unpack_from('<iQIQ',orig,12+24*i);y=struct.unpack_from('<iQIQ',reco,12+24*i)
        if x!=y:failures.append({'case':i,'original':x,'mql5':y})
    record={'cases':count,'matched':count-len(failures),'failed':len(failures),'first_failures':failures[:20],
            'hashes':{p:sha(out/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']},
            'scope':'Two price-level functions; supplied price-series/digits; return bits and ordered call hashes. Not a complete EA comparison.'}
    (out/'comparison.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));raise SystemExit(bool(failures))

if __name__=='__main__':main()
