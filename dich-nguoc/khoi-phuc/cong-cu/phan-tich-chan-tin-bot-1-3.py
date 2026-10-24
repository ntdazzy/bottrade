"""Compare the native news-window selector with a small MQL5 component.

Usage: python -I -B -X utf8 phan-tich-chan-tin-bot-1-3.py prepare|original|mql5|compare BOT RUN
Only the selector segment is tested. Calendar/network calls are outside this
segment; event times are supplied as data. No live order or real news setting
is changed.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import random
import re
import struct
import subprocess
import shutil
import time

ROOT=Path(__file__).resolve().parents[1]
MT=ROOT.parent/'.local/claude-recovery-20261023/mt5'
MAGIC=0x4e455731
CONFIG={
    1: {'fn':0x7310,'data':{'out':0x6a390,'nfp_flag':0x6a640,'nfp':0x6a360,'nfp_m':0x6a680,
        'ir_flag':0x6a698,'ir':0x6a368,'ir_m':0x6a6b8,'cpi_flag':0x6a6d0,'cpi':0x6a370,'cpi_m':0x6a6f0}},
    3: {'fn':0x7c30,'data':{'out':0x1d6ca0,'nfp_flag':0x1d7020,'nfp':0x1d6c70,'nfp_m':0x1d7060,
        'ir_flag':0x1d7078,'ir':0x1d6c78,'ir_m':0x1d7098,'cpi_flag':0x1d70b0,'cpi':0x1d6c80,'cpi_m':0x1d70d0}},
}


def load_price():
    path=Path(__file__).with_name('kiem-muc-gia-bot-1-3.py')
    spec=importlib.util.spec_from_file_location('price_news',path)
    mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod);return mod


price=load_price()
settings=importlib.util.module_from_spec(importlib.util.spec_from_file_location('settings_news',Path(__file__).with_name('phan-tich-cai-dat-bot-1-3.py')))
_settings_spec=importlib.util.spec_from_file_location('settings_news',Path(__file__).with_name('phan-tich-cai-dat-bot-1-3.py'))
_settings_spec.loader.exec_module(settings)


def cases():
    rng=random.Random(2026102401);out=[]
    fixed=[0,1,59,60,61,3600,100000]
    for now in [0,1,59,60,1000,1700000000,2147483647]:
        for nfp,ir,cpi in [(0,0,0),(900,1000,1100),(1000,900,1100),(-1,1000,1100),(1000,0,0)]:
            for flags in range(8):
                for minutes in fixed[:4]:
                    out.append({'now':now,'flags':flags,'nfp':nfp,'ir':ir,'cpi':cpi,
                                'nfp_m':minutes,'ir_m':minutes,'cpi_m':minutes,'tag':'boundary'})
    for _ in range(500):
        out.append({'now':rng.randrange(0,2147483647),'flags':rng.randrange(8),
                    'nfp':rng.choice([-1,0,1,59,60,1000,1700000000]),
                    'ir':rng.choice([-1,0,1,59,60,1001,1700000001]),
                    'cpi':rng.choice([-1,0,1,59,60,1002,1700000002]),
                    'nfp_m':rng.choice([-100,0,1,10,60,240,1000]),
                    'ir_m':rng.choice([-100,0,1,10,60,240,1000]),
                    'cpi_m':rng.choice([-100,0,1,10,60,240,1000]),'tag':'random'})
    for i,row in enumerate(out):row['id']=i
    return out


def expected(row):
    candidates=[]
    for bit,event,minutes in [(1,row['nfp'],row['nfp_m']),(2,row['ir'],row['ir_m']),(4,row['cpi'],row['cpi_m'])]:
        if row['flags']&bit and event>0 and event+minutes*60>row['now']:
            candidates.append(event)
    return min(candidates) if candidates else 0


def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for r in rows:
        raw+=struct.pack('<8i',r['id'],r['now'],r['flags'],r['nfp'],r['ir'],r['cpi'],r['nfp_m'],r['ir_m'])
        raw+=struct.pack('<i',r['cpi_m'])
    return raw


class Original:
    def __init__(self,bot):
        self.bot=bot;self.cfg=CONFIG[bot];self.oracle=price.Original(bot);self.m=self.oracle.m;self.x=self.oracle.x;self.uc=self.oracle.uc;self.base=self.oracle.base
        engine=json.loads((ROOT/f'bot-cua-toi-{bot}/bang-chung/luot-20261023-r1/engine-observed.json').read_text())
        self.engine_base=int(engine['engine_base'],16)
        api=self.engine_base+0x7d1ce0
        self.api=api
        for page in {api&~0xfff}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.m.mem_write(api,b'\xc3')
        self.m.hook_add(self.uc.UC_HOOK_CODE,self._time_hook,begin=api,end=api)
        # The first argument is a temporary string assignment helper. The
        # selector output timestamp is independent of its text content.
        self.internal=self.base+0x105c0
        self.m.mem_write(self.internal,b'\xc3')

    def _time_hook(self,m,address,size,user):
        m.reg_write(self.x.UC_X86_REG_RAX,self.row['now'] & ((1<<64)-1))
        stack=m.reg_read(self.x.UC_X86_REG_RSP)
        m.reg_write(self.x.UC_X86_REG_RIP,struct.unpack('<Q',m.mem_read(stack,8))[0])
        m.reg_write(self.x.UC_X86_REG_RSP,stack+8)

    def run(self,row):
        self.row=row;cfg=self.cfg['data'];m=self.m;x=self.x
        for region,raw in self.oracle.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for rva in [cfg['out'],cfg['nfp_flag'],cfg['nfp'],cfg['nfp_m'],cfg['ir_flag'],cfg['ir'],cfg['ir_m'],cfg['cpi_flag'],cfg['cpi'],cfg['cpi_m']]:
            m.mem_write(self.base+rva,b'\0'*8)
        for flag,name in [(1,'nfp_flag'),(2,'ir_flag'),(4,'cpi_flag')]:m.mem_write(self.base+cfg[name],bytes([1 if row['flags']&flag else 0]))
        for name in ['nfp','ir','cpi']:m.mem_write(self.base+cfg[name],struct.pack('<q',row[name]))
        for name in ['nfp_m','ir_m','cpi_m']:m.mem_write(self.base+cfg[name],struct.pack('<i',row[name]))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.emu_start(self.base+self.cfg['fn'],0x60000000,timeout=2000000,count=200000)
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise RuntimeError('NATIVE_SELECTOR_DID_NOT_RETURN '+hex(m.reg_read(x.UC_X86_REG_RIP)-self.base))
        return struct.unpack('<q',m.mem_read(self.base+cfg['out'],8))[0]


def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-chan-tin'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);rows=cases();(out/'cases.json').write_text(json.dumps(rows,ensure_ascii=False),encoding='utf-8');(out/'cases.bin').write_bytes(encode(rows));print(json.dumps({'cases':len(rows)}));return
    rows=json.loads((out/'cases.json').read_text());
    if encode(rows)!=(out/'cases.bin').read_bytes():raise ValueError('CASE_BYTES_CHANGED')
    if a.mode=='original':
        target=out/'original-results.bin';
        if target.exists():raise FileExistsError(target)
        o=Original(a.bot);started=time.monotonic();values=[o.run(r) for r in rows]
        target.write_bytes(struct.pack('<3i',MAGIC,1,len(values))+b''.join(struct.pack('<iq',r['id'],v) for r,v in zip(rows,values)))
        (out/'original-run.json').write_text(json.dumps({'cases':len(rows),'seconds':round(time.monotonic()-started,2),'result_sha256':price.sha(target),'scope':__doc__},indent=2),encoding='utf-8');print(json.dumps({'cases':len(rows)}));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin';
        if target.exists():raise FileExistsError(target)
        if settings.processes():raise RuntimeError('PRIVATE_MT5_IS_BUSY')
        files=MT/f'MQL5/Files/bot{a.bot}-news-block'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set';preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-news-block.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}NewsBlockCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0 or not (files/'mql5-results.bin').exists():raise RuntimeError('MQL5_CHECK_FAILED '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target);print('MQL5 news selector results saved');return
    data=(out/'mql5-results.bin').read_bytes();native_data=(out/'original-results.bin').read_bytes();n=len(rows);size=12
    if len(data)!=12+n*12 or native_data[:12]!=data[:12]:raise ValueError('RESULT_SIZE_MISMATCH')
    fail=[]
    for i in range(n):
        x=struct.unpack_from('<iq',native_data,12+i*12);y=struct.unpack_from('<iq',data,12+i*12)
        if x!=y:fail.append({'id':rows[i]['id'],'original':x,'mql5':y})
    result={'bot':a.bot,'cases':n,'matched':n-len(fail),'failed':len(fail),'passed':not fail,'first_failures':fail[:20],'original_sha256':price.sha(out/'original-results.bin'),'mql5_sha256':price.sha(out/'mql5-results.bin'),'scope':'Exact event timestamp selector only. Calendar loading, event names, network fallback and closing/cancelling actions remain separate.'}
    (out/'comparison.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf-8');print(json.dumps(result));raise SystemExit(bool(fail))


if __name__=='__main__':main()
