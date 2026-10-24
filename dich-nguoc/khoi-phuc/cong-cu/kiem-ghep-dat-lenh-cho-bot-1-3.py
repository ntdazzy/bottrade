"""Compare original pending builder through send/result/message handling as one path.

Usage: kiem-ghep-dat-lenh-cho-bot-1-3.py prepare|mql5|original|compare|audit BOT RUN [--build BUILD]
No trading request is sent. Send results and terminal properties are supplied;
real MT5 formatting is measured. All35 state fields, magic/preference and complete
typed API order/arguments are compared through the native return, not a stop marker.
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
MAGIC=0x4f504e31
MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('open_send',Path(__file__).with_name('kiem-gui-lenh-bot-1-3.py'))
send=importlib.util.module_from_spec(spec);spec.loader.exec_module(send)
pending=send.pending;MT=send.MT
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2,allow_nan=False)
def cases():
    source=pending.cases();out=[];schemas=send.layout()
    for original in source:
        row=send.base();i=original['id'];row['id']=i;row['group']=original['group'];row['prep']=original
        row['request']={f['name']:f['value'] for f in schemas['request']['fields']}
        row['result']={f['name']:f['value'] for f in schemas['result']['fields']}
        row.update(async_mode=[0,1,255][i%3],accepted=i%2,log_level=[-1,0,1,2,3][i%5],write_result=int(i%7!=0))
        row['new_result']['retcode']=[10004,10009,10010,10018,10039,10040,10041][i%7]
        out.append(row)
    # Cross every send/log combination on a preparation path guaranteed to reach it.
    for async_mode in [0,1,2,255]:
        for accepted in [0,1]:
            for log in [-1,0,1,2,3]:
                for write in [0,1]:
                    row=send.base();row.update(id=len(out),group='send-after-successful-preparation',async_mode=async_mode,accepted=accepted,log_level=log,write_result=write)
                    row['request']={f['name']:f['value'] for f in schemas['request']['fields']}
                    row['result']={f['name']:f['value'] for f in schemas['result']['fields']}
                    row['prep']=dict(pending.base(),id=row['id']);out.append(row)
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for r in rows:
        raw+=send.encode([r])[12:]
        raw+=b''.join(struct.pack('<'+kind,r['prep'][name]) for name,kind in pending.FIELDS if name!='id')
    return raw
def read_cases(path):
    rd=send.Reader(path.read_bytes());magic,version,n=rd.take('3i')
    if (magic,version)!=(MAGIC,1):raise ValueError('BAD_CASE_HEADER')
    rows=[];schemas=send.layout()
    for _ in range(n):
        row=dict(zip(['id','async_mode','log_level','margin_mode','accepted','write_result'],rd.take('6i')))
        row.update(digits=list(rd.take('2q')),executions=list(rd.take('2q')))
        ok=rd.take('4i');row.update(digits_ok=list(ok[:2]),execution_ok=list(ok[2:]))
        for key in ['request','result','new_result']:
            values={}
            for f in schemas['request' if key=='request' else 'result']['fields']:
                if f['kind']=='s':
                    if f['name']=='symbol':row['symbol_null']=rd.take('i')[0]
                    values[f['name']]=rd.text()
                else:values[f['name']]=rd.take(f['kind'])[0]
            row[key]=values
        row['prep']={'id':row['id']}
        for name,kind in pending.FIELDS:
            if name!='id':row['prep'][name]=rd.take(kind)[0]
        rows.append(row)
    if rd.pos!=len(rd.raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return rows
def read_results(path):
    raw=path.read_bytes();magic,version,n=struct.unpack_from('<3i',raw)
    if (magic,version)!=(MAGIC,1) or len(raw)!=12+284*n:raise ValueError('BAD_RESULT_SHAPE')
    return [raw[12+284*i:12+284*(i+1)] for i in range(n)]

class Original(send.Original):
    def __init__(self,bot,fixtures,casts,chart,digits):
        super().__init__(bot,fixtures,casts,chart,digits)
        self.pending_cfg=pending.CFG[bot];self.fill_cfg=pending.fill.CFG[bot];self.layout=json.loads(send.LAYOUT.read_text())
        if not self.layout['runner_verified'] or not self.layout['only_anchor_executed']:raise ValueError('LAYOUT_CALIBRATION_NOT_VERIFIED')
        if self.layout['relative_native_storage_bases']!={'request':0,'result':240,'check':436} or self.layout['end_marker_offset']!=628:raise ValueError('CLASS_LAYOUT_NOT_EXPECTED')
        for name,digest in self.layout['source_sha256'].items():
            if sha(ROOT/name)!=digest:raise ValueError('LAYOUT_SOURCE_CHANGED')
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        for fn in [self.pending_cfg['fn'],self.fill_cfg['fn']]:
            row=next(f for f in meta['functions'] if int(f['begin_rva'],16)==fn)
            self.ranges.append((fn,int(row['end_rva'],16)))
        # The inherited base already registered this direct-symbol call address.
        address=next(a for a,k in self.apis.items() if k==3);self.apis[address]=47
    def write_guard(self,m,access,address,size,value,user):
        if not self.executing:return
        start=self.base+self.send_cfg['request']
        if start<=address and address+size<=start+628:return
        for rva,n in [(self.pending_cfg['magic'],8),(self.fill_cfg['preferred'],4)]:
            if self.base+rva<=address and address+size<=self.base+rva+n:return
        return super().write_guard(m,access,address,size,value,user)
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api==47:
            prop,text,value=self.next(9)
            if (m.reg_read(x.UC_X86_REG_R8)&0xffffffff)!=prop or self.text(m.reg_read(x.UC_X86_REG_RDX))!=text:raise ValueError('DIRECT_SYMBOL_ARGUMENTS_DIFFER')
            m.reg_write(x.UC_X86_REG_RAX,value&MASK);return
        if api==45:
            opcode=m.reg_read(x.UC_X86_REG_RDX);count=m.reg_read(x.UC_X86_REG_R8);sp=m.reg_read(x.UC_X86_REG_RSP)
            if opcode==2 or (opcode==13 and count==2):
                if m.reg_read(x.UC_X86_REG_R9)!=0x590008:raise ValueError('MESSAGE_FIRST_TYPE_DIFFERS')
                actual=[]
                for i in range(count):
                    if i and struct.unpack('<I',m.mem_read(sp+32+16*i,4))[0]!=0x590008:raise ValueError('MESSAGE_TYPE_DIFFERS')
                    actual.append(self.text(struct.unpack('<Q',m.mem_read(sp+40+16*i,8))[0]))
                expected=self.next(7 if opcode==2 else 8)
                if actual!=list(expected[:count]):raise ValueError('PREPARATION_MESSAGE_ARGUMENTS_DIFFER')
                return
        return super().call(m,address,size,user)
    def run(self,row):
        self.executing=False;m,x=self.m,self.x;self.case=dict(row);p=row['prep']
        # Caster fixture describes the produced action/type and zeroed result.
        self.case['request']={'action':5,'type':p['type']};self.case['result']={'retcode':0}
        self.cursor=0x70001000;self.allocs=self.frees=0;self.position=0;self.print_count=0;self.print_hash=0;self.records=self.records_by_id[row['id']]
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.mem_write(0x50000000,b'\0'*0x20000)
        cfg=self.send_cfg;ctx=self.base+cfg['context'];req=self.base+cfg['request'];res=self.base+cfg['result']
        m.mem_write(req,b'\x5a'*628);self.populate('request',req,row['request'],bool(row['symbol_null']));self.populate('result',res,row['result'])
        check={f['name']:f['value'] for f in self.schemas['check']['fields']};self.populate('check',req+436,check)
        m.mem_write(self.base+cfg['slot'],b'\0'*12);self.supply(self.base+cfg['chart'],self.chart);m.mem_write(self.base+cfg['digits'],struct.pack('<i',self.default_digits))
        m.mem_write(ctx+660,bytes([row['async_mode']]));m.mem_write(ctx+681,struct.pack('<i',row['margin_mode']));m.mem_write(ctx+685,struct.pack('<i',row['log_level']))
        pcfg=self.pending_cfg
        for key,name in [('stopped','stopped'),('magic_input','strategy_magic')]:m.mem_write(self.base+pcfg[key],struct.pack('<i',p[name]))
        m.mem_write(self.base+pcfg['virtual'],bytes([p['virtual']]));m.mem_write(self.base+pcfg['magic'],struct.pack('<Q',0x7654321076543210))
        m.mem_write(self.base+self.fill_cfg['preferred'],struct.pack('<i',p['preferred']))
        symbol=0x70000000;comment=0x70000020
        if p['symbol_kind']==2:m.mem_write(symbol,b'\0'*12)
        else:self.supply(symbol,pending.fill.symbol_text(p['symbol_kind']))
        if p['comment_kind']==2:m.mem_write(comment,b'\0'*12)
        else:self.supply(comment,['Recovery','','','Vé kiểm'][p['comment_kind']])
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.reg_write(x.UC_X86_REG_RCX,symbol);m.reg_write(x.UC_X86_REG_RDX,p['type']&0xffffffff)
        m.reg_write(x.UC_X86_REG_XMM2,send.bits(p['volume']));m.reg_write(x.UC_X86_REG_XMM3,send.bits(p['price']))
        m.mem_write(top+40,struct.pack('<2dQq',p['sl'],p['tp'],comment,p['expiration']))
        self.executing=True
        initial_storage=bytes(m.mem_read(req,628))
        try:m.emu_start(self.base+pcfg['fn'],0x60000000,timeout=5000000,count=700000)
        finally:self.executing=False
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000 or self.position!=len(self.records):raise ValueError('COMPLETE_NATIVE_PATH_NOT_CONSUMED '+str((self.position,len(self.records))))
        self.supply(self.base+cfg['slot'],'')
        if self.allocs!=self.frees:raise ValueError('OWNED_STRING_ALLOCATION_IMBALANCE')
        if p['stopped']:
            expected=bytearray(initial_storage);expected[240:244]=struct.pack('<I',10027)
            if bytes(m.mem_read(req,628))!=bytes(expected):raise ValueError('STOPPED_PROGRAM_CHANGED_OTHER_CLASS_BYTES')
        else:
            for offset,n in [(128,112),(312,124),(500,128)]:
                if bytes(m.mem_read(req+offset,n))!=b'\0'*n:raise ValueError('NATIVE_RESERVED_STORAGE_NOT_CLEARED')
        state=pending.Original.state_bytes(self)
        return struct.pack('<2i',row['id'],int(bool(m.reg_read(x.UC_X86_REG_RAX)&255)))+state+struct.pack('<2iQ',self.position,self.print_count,self.print_hash)

def verify_build(bot,build):
    if not build or not re.fullmatch('[a-z0-9-]+',build):raise ValueError('BUILD_REQUIRED')
    p=ROOT/f'bot-cua-toi-{bot}/bang-chung/bien-dich'/build/'bien-nhan.json';d=json.loads(p.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{bot}/Bot{bot}OpenPendingCheck.mq5';script=MT/'MQL5'/target.replace('.mq5','.ex5')
    if d['target']!=target or d['errors'] or d['warnings'] or sha(script)!=d['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
    names=[target,f'Scripts/bot-cua-toi-{bot}/Bot{bot}TradeSendCheck.mq5']+[f'Include/bot-cua-toi-{bot}/Bot{bot}{n}.mqh' for n in ['TradeSend','TradeMessages','PendingRequest','Filling']]
    for name in names:
        if sha(ROOT/f'bot-cua-toi-{bot}/source/MQL5'/name)!=d['sources_sha256'][name]:raise ValueError('SOURCE_CHANGED '+name)
    return p,script
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','mql5','original','compare','audit']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-ghep-dat-lenh-cho'/a.run
    if a.mode=='prepare':
        digest=pending.fill.validation.original_hash(a.bot);out.mkdir(parents=True,exist_ok=False);rows=cases();(out/'cases.bin').write_bytes(encode(rows))
        descriptions=send.json_cases(rows)
        for target,row in zip(descriptions,rows):
            for name in ['volume','price','sl','tp']:target['prep'][name]=struct.pack('<d',row['prep'][name]).hex()
        save(out/'cases.json',descriptions);save(out/'baseline.json',dict(original_ex5_sha256=digest,cases=len(rows),cases_sha256=sha(out/'cases.bin'),tool_sha256=sha(Path(__file__)),layout_sha256=sha(send.LAYOUT)))
        print(json.dumps({'cases':len(rows)}));return
    rows=read_cases(out/'cases.bin');baseline=json.loads((out/'baseline.json').read_text())
    if sha(out/'cases.bin')!=baseline['cases_sha256'] or sha(send.LAYOUT)!=baseline['layout_sha256']:raise ValueError('INPUTS_CHANGED')
    if a.mode=='mql5':
        receipt,script=verify_build(a.bot,a.build)
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-open-pending'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}-open.set'
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        ini=MT/f'b{a.bot}-{a.run}-open.ini'
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\n'+f'Script=bot-cua-toi-{a.bot}\\Bot{a.bot}OpenPendingCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        if code:raise RuntimeError('MT5_CHECK_FAILED '+str(code))
        for name in ['mql5-results.bin','api-fixtures.bin']:shutil.copyfile(files/name,out/name)
        save(out/'mql5-run.json',dict(exit_code=code,seconds=round(time.monotonic()-start,2),script_sha256=sha(script),build_receipt_sha256=sha(receipt),hashes={n:sha(out/n) for n in ['mql5-results.bin','api-fixtures.bin']}))
        print(json.dumps({'cases':len(read_results(out/'mql5-results.bin'))}));return
    if a.mode in ['original','audit']:
        if pending.fill.validation.original_hash(a.bot)!=baseline['original_ex5_sha256']:raise ValueError('ORIGINAL_CHANGED')
        if a.mode=='original' and (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        if a.mode=='audit' and (out/'native-storage-audit.json').exists():raise FileExistsError('STORAGE_AUDIT_EXISTS')
        fixtures,casts,chart,digits=send.read_fixtures(out/'api-fixtures.bin',len(rows),MAGIC);o=Original(a.bot,fixtures,casts,chart,digits);start=time.monotonic();values=[]
        for row in rows:
            try:values.append(o.run(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
        raw=struct.pack('<3i',MAGIC,1,len(values))+b''.join(values)
        if a.mode=='audit':
            comparison=json.loads((out/'comparison.json').read_text())
            for name,digest in comparison['hashes'].items():
                if sha(out/name)!=digest:raise ValueError('EXISTING_COMPARISON_CHANGED')
            if comparison['failed'] or raw!=(out/'original-results.bin').read_bytes() or raw!=(out/'mql5-results.bin').read_bytes():raise ValueError('STORAGE_AUDIT_RESULTS_DIFFER')
            save(out/'native-storage-audit.json',dict(cases=len(values),passed=True,seconds=round(time.monotonic()-start,2),tool_sha256=sha(Path(__file__)),layout_sha256=sha(send.LAYOUT),result_sha256=hashlib.sha256(raw).hexdigest(),scope='Original full628-byte class storage: after ordinary preparation all364 reserved bytes zero; stopped path changes only retcode in those628 bytes. Public35 fields and magic/preference still equal both previous native/MQL5 results. MQL5 private padding bytes not compared.'))
        else:
            (out/'original-results.bin').write_bytes(raw);save(out/'original-run.json',dict(cases=len(values),seconds=round(time.monotonic()-start,2),result_sha256=sha(out/'original-results.bin'),fixtures_sha256=sha(out/'api-fixtures.bin'),tool_sha256=sha(Path(__file__)),scope=__doc__))
        print(json.dumps({'cases':len(values)}));return
    original=read_results(out/'original-results.bin');actual=read_results(out/'mql5-results.bin')
    if len(original)!=len(rows) or len(actual)!=len(rows):raise ValueError('RESULT_COUNT_MISMATCH')
    failures=[]
    for i,(x,y) in enumerate(zip(original,actual)):
        if x!=y:
            n=next(j for j in range(284) if x[j]!=y[j]);failures.append(dict(id=i,first_different_byte=n,original=x[n:n+8].hex(),mql5=y[n:n+8].hex()))
    result=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:20],hashes={n:sha(out/n) for n in ['cases.bin','original-results.bin','mql5-results.bin','api-fixtures.bin']},scope='Complete original pending-builder through both filling checks and full send/message functions versus restored combined source.35 state fields plus magic/preferred, return bool and ordered typed API calls/text. Send outcomes/properties supplied, formatting measured. No broker execution/allocation-failure/whole EA claim.')
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))
if __name__=='__main__':main()
