"""Analyze and compare the original error-text helper, including its u32 counter.

Usage: kiem-chuoi-loi-bot-1-3.py analyze|prepare|mql5|original|compare BOT RUN [--build BUILD]
Analyze before writing source; prepare after analysis. Run MQL5 before original.
No orders are sent. Native string helpers run; only signed decimal casts and
successful allocation/free are supplied. Allocation failures are not tested.
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

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x45525231
spec=importlib.util.spec_from_file_location('send',Path(__file__).with_name('kiem-gui-lenh-bot-1-3.py'))
send=importlib.util.module_from_spec(spec);spec.loader.exec_module(send)
MT=send.MT
CFG={1:dict(fn=0x336d0,counter=0x6744c),3:dict(fn=0x3ee80,counter=0x7448c)}
sha=send.sha;save=send.save;pack_text=send.pack_text

def analyze(bot):
    o=send.pending.fill.entry.Original(bot);o.cursor=0x70001000
    folder=ROOT/f'bot-cua-toi-{bot}/phan-tich'/('luot-20261023-data-v2' if bot==1 else 'luot-20261023-data')
    source=folder/('ma-trung-gian.c' if bot==1 else 'ma-trung-gian-day-du.c')
    name=f'FUN_{o.base+CFG[bot]["fn"]:x}';text=source.read_text();start=text.index('void '+name+'(')
    stop=text.index('\n/* Address:',start);body=text[start:stop];pending=[];mapping={};evidence=[]
    for match in re.finditer(r'case (0x[0-9a-f]+|[0-9]+):|pMVar3 = &string_ref_([0-9a-f]+);|default:|break;',body):
        if match[1]:pending.append(int(match[1],0));continue
        if not match[2]:pending=[];continue
        address=int(match[2],16);pointer=struct.unpack('<Q',o.m.mem_read(address+4,8))[0]
        length=struct.unpack('<I',o.m.mem_read(pointer-4,4))[0]
        if not 0<length<1000:raise ValueError('INVALID_LITERAL_HEADER')
        value=bytes(o.m.mem_read(pointer,2*length)).decode('utf-16-le')
        if not pending:raise ValueError('NO_CASE_FOR_LITERAL')
        for code in pending:
            if str(code) in mapping:raise ValueError('DUPLICATE_CASE')
            mapping[str(code)]=value
        evidence.append(dict(codes=pending,descriptor_rva=hex(address-o.base),descriptor_hex=bytes(o.m.mem_read(address,12)).hex(),text=value))
        pending=[]
    if len(mapping)!=92:raise ValueError('EXPECTED_92_CASES '+str(len(mapping)))
    return dict(bot=bot,original_ex5_sha256=send.pending.fill.validation.original_hash(bot),function_rva=hex(CFG[bot]['fn']),
                counter_rva=hex(CFG[bot]['counter']),string_slot_rva=hex(send.CFG[bot]['slot']),source_sha256=sha(source),
                c_body_sha256=hashlib.sha256(body.encode()).hexdigest(),map=mapping,literals=evidence,
                default_prefix='unknown error ',default_numeric_kind='signed int32',counter='u32 increment before switch; wraps',
                scope='Literal analysis; native execution and MQL5 comparison must follow.')

def cases(mapping):
    codes={-2147483648,-2147483647,-10000,-1,2147483646,2147483647,10004,10009}
    for code in map(int,mapping):codes.update([code-1,code,code+1])
    rows=[]
    for code in sorted(codes):
        for counter in [0,1,0x7fffffff,0xfffffffe,0xffffffff]:
            for old_kind in [0,1,2]:rows.append(dict(id=len(rows),code=code,counter=counter,old_kind=old_kind))
    return rows

def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<2iIi',r['id'],r['code'],r['counter'],r['old_kind']) for r in rows)
def read_cases(path):
    raw=path.read_bytes();magic,version,n=struct.unpack_from('<3i',raw)
    if (magic,version)!=(MAGIC,1) or len(raw)!=12+16*n:raise ValueError('CASE_SHAPE_DIFFERS')
    return [dict(zip(['id','code','counter','old_kind'],struct.unpack_from('<2iIi',raw,12+16*i))) for i in range(n)]
def read_output(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('OUTPUT_HEADER_DIFFERS')
    out=[]
    for i in range(n):
        cid,counter=rd.take('iI');text=rd.text()
        if cid!=i:raise ValueError('OUTPUT_ID_DIFFERS')
        out.append((cid,counter,text))
    if rd.pos!=len(rd.raw):raise ValueError('OUTPUT_LENGTH_DIFFERS')
    return out
def old_text(kind):return ['', 'old text', 'Vé cũ '+('x'*300)][kind]

class Original(send.Original):
    def __init__(self,bot,casts):
        super().__init__(bot,{}, {},'',3);self.error_cfg=CFG[bot];self.cast_values=casts
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        row=next(f for f in meta['functions'] if int(f['begin_rva'],16)==self.error_cfg['fn'])
        self.ranges=[r for r in self.ranges if r[0] in [0,0x60,0x4a0,0x5c0]]+[(self.error_cfg['fn'],int(row['end_rva'],16))]
    def write_guard(self,m,access,address,size,value,user):
        if self.executing and self.base+self.error_cfg['counter']<=address and address+size<=self.base+self.error_cfg['counter']+4:return
        return super().write_guard(m,access,address,size,value,user)
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api==46:
            if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=self.case['code']&0xffffffff or m.reg_read(x.UC_X86_REG_R8)!=0x52:raise ValueError('SIGNED_CAST_ARGUMENTS_DIFFER')
            self.cast_calls+=1;self.supply(m.reg_read(x.UC_X86_REG_R9),self.cast_values[self.case['id']]);return
        if api not in [100,101,200]:raise ValueError('UNEXPECTED_ERROR_HELPER_API '+str(api))
        return super().call(m,address,size,user)
    def run(self,row):
        self.executing=False;self.case=row;self.cursor=0x70001000;self.allocs=self.frees=self.cast_calls=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.mem_write(0x50000000,b'\0'*0x20000)
        slot=self.base+self.send_cfg['slot'];m.mem_write(slot,b'\0'*12)
        if row['old_kind']==1:self.supply(slot,old_text(1))
        elif row['old_kind']==2:
            raw=old_text(2).encode('utf-16-le');pointer=self.cursor;self.cursor+=(12+len(raw)+2+15)&~15
            m.mem_write(pointer,struct.pack('<III',len(raw)//2+1,1,len(raw)//2)+raw+b'\0\0')
            m.mem_write(slot,struct.pack('<IQ',1,pointer+12));self.allocs+=1
        m.mem_write(self.base+self.error_cfg['counter'],struct.pack('<I',row['counter']))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_RCX,row['code']&0xffffffff)
        self.executing=True
        try:m.emu_start(self.base+self.error_cfg['fn'],0x60000000,timeout=5000000,count=300000)
        finally:self.executing=False
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise ValueError('ERROR_HELPER_DID_NOT_RETURN')
        counter=struct.unpack('<I',m.mem_read(self.base+self.error_cfg['counter'],4))[0];text=self.text(slot);self.supply(slot,'')
        if self.allocs!=self.frees:raise ValueError('ERROR_HELPER_OWNED_STRING_IMBALANCE')
        return (row['id'],counter,text)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('mode',choices=['analyze','prepare','mql5','original','compare']);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('run');parser.add_argument('--build');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    home=ROOT/f'bot-cua-toi-{a.bot}';out=home/'bang-chung/kiem-chuoi-loi'/a.run
    if a.mode=='analyze':out.mkdir(parents=True,exist_ok=False);save(out/'analysis.json',analyze(a.bot));print('{"mapped_codes":92}');return
    analysis=json.loads((out/'analysis.json').read_text());digest=send.pending.fill.validation.original_hash(a.bot)
    if digest!=analysis['original_ex5_sha256']:raise ValueError('ORIGINAL_CHANGED')
    if a.mode=='prepare':
        rows=cases(analysis['map'])
        with (out/'cases.bin').open('xb') as f:f.write(encode(rows))
        save(out/'cases.json',rows);save(out/'baseline.json',dict(cases=len(rows),cases_sha256=sha(out/'cases.bin'),analysis_sha256=sha(out/'analysis.json'),original_ex5_sha256=digest,tool_sha256=sha(Path(__file__))))
        print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((out/'baseline.json').read_text());rows=read_cases(out/'cases.bin');n=len(rows)
    if sha(out/'cases.bin')!=baseline['cases_sha256'] or sha(out/'analysis.json')!=baseline['analysis_sha256']:raise ValueError('INPUTS_CHANGED')
    if a.mode=='mql5':
        if not a.build or not re.fullmatch('[a-z0-9-]+',a.build):raise ValueError('BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}TradeErrorsCheck.mq5';binary=MT/'MQL5'/target.replace('.mq5','.ex5')
        if receipt['target']!=target or receipt['errors'] or receipt['warnings'] or sha(binary)!=receipt['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
        for name in [target,f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}TradeErrors.mqh']:
            if sha(home/'source/MQL5'/name)!=receipt['sources_sha256'][name]:raise ValueError('SOURCE_CHANGED')
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-trade-errors'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-trade-errors-{a.run}.set';preset.write_text(f'CheckRun={a.run}\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-trade-errors-{a.run}.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}TradeErrorsCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        if code:raise RuntimeError('MT5_CHECK_FAILED '+str(code))
        for name in ['mql5-results.bin','cast-values.bin']:shutil.copyfile(files/name,out/name)
        save(out/'mql5-run.json',dict(exit_code=code,seconds=round(time.monotonic()-start,2),script_sha256=sha(binary),build_receipt_sha256=sha(receipt_path),hashes={name:sha(out/name) for name in ['mql5-results.bin','cast-values.bin']}))
        print(json.dumps({'cases':len(read_output(out/'mql5-results.bin',n))}));return
    if a.mode=='original':
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        reader=send.Reader((out/'cast-values.bin').read_bytes())
        if reader.take('3i')!=(MAGIC,1,n):raise ValueError('CAST_FIXTURE_HEADER_DIFFERS')
        casts=[reader.text() for _ in rows]
        if reader.pos!=len(reader.raw):raise ValueError('CAST_FIXTURE_LENGTH_DIFFERS')
        o=Original(a.bot,casts);start=time.monotonic();values=[];calls=[]
        for row in rows:
            try:values.append(o.run(row));calls.append(o.cast_calls)
            except Exception as error:raise RuntimeError(f'case={row["id"]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
            if o.cast_calls!=int(str(row['code']) not in analysis['map']):raise ValueError('CAST_CALL_COUNT_DIFFERS')
        raw=struct.pack('<3i',MAGIC,1,n)+b''.join(struct.pack('<iI',cid,counter)+pack_text(text) for cid,counter,text in values)
        with (out/'original-results.bin').open('xb') as f:f.write(raw)
        save(out/'original-run.json',dict(cases=n,seconds=round(time.monotonic()-start,2),result_sha256=sha(out/'original-results.bin'),casts_sha256=sha(out/'cast-values.bin'),cast_calls=sum(calls),tool_sha256=sha(Path(__file__)),scope=__doc__))
        print(json.dumps({'cases':n}));return
    original=read_output(out/'original-results.bin',n);actual=read_output(out/'mql5-results.bin',n);failures=[dict(id=i,original=x,mql5=y) for i,(x,y) in enumerate(zip(original,actual)) if x!=y]
    result=dict(cases=n,matched=n-len(failures),failed=len(failures),first_failures=failures[:10],hashes={name:sha(out/name) for name in ['analysis.json','cases.bin','original-results.bin','mql5-results.bin','cast-values.bin']},scope='All92 explicit codes, adjacent unmapped codes, int32 extremes; u32 increment/wrap and old shared text replacement, including native owned old string. Cast text measured in MT5. No allocation failures or full EA claim.')
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))

if __name__=='__main__':main()
