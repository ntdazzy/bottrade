"""Compare full native send routing and all request/result message functions.

Usage: kiem-gui-lenh-bot-1-3.py prepare|mql5|original|compare BOT RUN [--build BUILD]
Run MQL5 first. Send calls are supplied; real MT5 number/string formatting outputs
are recorded, then native arguments/order are checked against them. No order sent.
Original send/format/owned-string helper code executes; allocation faults excluded.
"""
import argparse
import hashlib
import importlib.util
import json
import math
from pathlib import Path
import re
import struct
import shutil
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
MAGIC=0x534e4431
MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('send_pending',Path(__file__).with_name('kiem-tao-yeu-cau-cho-bot-1-3.py'))
pending=importlib.util.module_from_spec(spec);spec.loader.exec_module(pending)
MT=pending.MT
LAYOUT=pending.LAYOUT
RANGES={1:[0,0x60,0x4a0,0x5c0,0x950,0x235c0,0x23fa0,0x26060,0x26360],
        3:[0,0x60,0x4a0,0x5c0,0x950,0x2ecf0,0x2f6d0,0x31790,0x31a90]}
CFG={1:dict(context=0x67490,request=0x674b0,result=0x675a0,slot=0x6a43c,chart=0x6a428,digits=0x6a420),
     3:dict(context=0x744d0,request=0x744f0,result=0x745e0,slot=0x1d6e3c,chart=0x1d6e28,digits=0x1d6e20)}

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2,allow_nan=False)
def pack_text(value):
    raw=value.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def text_hash(value):return pending.fill.entry.text_hash(value)
def layout():return json.loads(LAYOUT.read_text())['layouts']
def base():
    request={f['name']:f['value'] for f in layout()['request']['fields']}
    result={f['name']:f['value'] for f in layout()['result']['fields']}
    request.update(action=1,type=0,symbol='XAUUSD',volume=0.12,price=2600.25,stoplimit=0.,sl=2500.,tp=2700.,position=0,position_by=0)
    current=dict(result);current.update(retcode=10009,volume=0.12,price=2600.5,bid=2600.4,ask=2600.6,comment='broker result')
    return dict(id=0,async_mode=0,log_level=2,margin_mode=0,accepted=1,write_result=1,
                digits=[3,3],executions=[0,0],digits_ok=[1,1],execution_ok=[1,1],
                symbol_null=0,request=request,result=result,new_result=current)
def cases():
    rows=[]
    def add(group,**changes):
        r=base()
        for key,value in changes.items():
            if '.' in key:a,b=key.split('.');r[a][b]=value
            else:r[key]=value
        r.update(id=len(rows),group=group);rows.append(r)
    for async_mode in [0,1,2,255]:
        for accepted in [0,1]:
            for log in [-2,-1,0,1,2,3,2147483647]:
                for write in [0,1]:add('routing-log-and-result-write',async_mode=async_mode,accepted=accepted,log_level=log,write_result=write)
    for code in [0,*range(10000,10043),0xffffffff]:
        for action,execution in [(1,0),(1,3),(5,0)]:add('retcode-branches',executions=[execution,execution],**{'new_result.retcode':code,'request.action':action})
    for action in [-1,*range(12),2147483647]:
        for execution in [-1,0,1,2,3,4]:
            for margin,position in [(0,0),(2,0),(2,0x10000000200001)]:
                add('request-action-execution-position',executions=[execution,execution],margin_mode=margin,**{'request.action':action,'request.position':position,'request.position_by':0xffffffffffffffff})
    for kind in [-1,*range(9),2147483647]:
        for action in [1,5]:add('order-type-text',**{'request.type':kind,'request.action':action,'request.stoplimit':2601.5})
    for field in ['volume','price','stoplimit','sl','tp']:
        for value in [-0.,0.,-1.005,1.005,math.nan,math.inf,-math.inf,1e19]:
            add('number-representation',**{'request.action':5,'request.sl':0.,'request.tp':0.,'request.'+field:value})
    for field in ['volume','price','bid','ask']:
        for value in [-0.,0.,-1.005,math.nan,math.inf,-math.inf]:
            for code in [10004,10010]:add('result-number-representation',**{'new_result.retcode':code,'new_result.'+field:value})
    for symbol,none in [('',0),('',1),('Vàng',0),('XAUUSD.long.symbol',0)]:
        for dok in [[0,0],[0,1],[1,0],[1,1]]:
            for eok in [[0,0],[1,0],[0,1],[1,1]]:
                add('symbol-defaults-and-read-errors',symbol_null=none,digits=[2,8],executions=[2,3],digits_ok=dok,execution_ok=eok,**{'request.symbol':symbol,'new_result.retcode':10010})
    for digits in [-8,-1,0,2,8,16]:
        for action in [1,5,6,7]:add('digits-and-scientific',digits=[digits,digits],margin_mode=2,**{'request.action':action,'request.position':0xffffffffffffffff,'request.stoplimit':1.005})
    return rows
def encode_struct(value,fields,case=None):
    raw=bytearray()
    for f in fields:
        k,name=f['kind'],f['name'];v=value[name]
        if k=='s':
            if name=='symbol':raw+=struct.pack('<i',case['symbol_null'])
            raw+=pack_text(v)
        else:raw+=struct.pack('<'+k,v)
    return raw
def encode(rows):
    layouts=layout();raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for r in rows:
        raw+=struct.pack('<6i',*(r[k] for k in ['id','async_mode','log_level','margin_mode','accepted','write_result']))
        raw+=struct.pack('<4q4i',*r['digits'],*r['executions'],*r['digits_ok'],*r['execution_ok'])
        raw+=encode_struct(r['request'],layouts['request']['fields'],r)
        raw+=encode_struct(r['result'],layouts['result']['fields']);raw+=encode_struct(r['new_result'],layouts['result']['fields'])
    return raw
def json_cases(rows):
    out=[]
    for row in rows:
        copy=json.loads(json.dumps(row,allow_nan=True))
        for key in ['request','result','new_result']:
            for f in layout()['request' if key=='request' else 'result']['fields']:
                if f['kind']=='d':copy[key][f['name']]=struct.pack('<d',row[key][f['name']]).hex()
        out.append(copy)
    return out
class Reader:
    def __init__(self,raw):self.raw=raw;self.pos=0
    def take(self,fmt):
        size=struct.calcsize('<'+fmt);out=struct.unpack_from('<'+fmt,self.raw,self.pos);self.pos+=size;return out
    def text(self):
        n=self.take('i')[0]
        if not 0<=n<=4096:raise ValueError('BAD_STRING_LENGTH')
        raw=self.raw[self.pos:self.pos+2*n];self.pos+=2*n;return raw.decode('utf-16-le')
    def block(self,n):raw=self.raw[self.pos:self.pos+n];self.pos+=n;return raw
def read_cases(path):
    rd=Reader(path.read_bytes());magic,version,n=rd.take('3i')
    if (magic,version)!=(MAGIC,1):raise ValueError('BAD_CASE_HEADER')
    out=[];layouts=layout()
    for _ in range(n):
        row=dict(zip(['id','async_mode','log_level','margin_mode','accepted','write_result'],rd.take('6i')))
        digits,execution,ok=rd.take('2q'),rd.take('2q'),rd.take('4i');row.update(digits=list(digits),executions=list(execution),digits_ok=list(ok[:2]),execution_ok=list(ok[2:]))
        for key in ['request','result','new_result']:
            val={}
            for f in layouts['request' if key=='request' else 'result']['fields']:
                kind=f['kind'];name=f['name']
                if kind=='s':
                    if name=='symbol':row['symbol_null']=rd.take('i')[0]
                    val[name]=rd.text()
                else:val[name]=rd.take(kind)[0]
            row[key]=val
        out.append(row)
    if rd.pos!=len(rd.raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return out
def read_fixtures(path,count):
    rd=Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,count):raise ValueError('BAD_FIXTURE_HEADER')
    chart=rd.text();digits=rd.take('i')[0];out={i:[] for i in range(count)};casts={}
    while rd.pos<len(rd.raw):
        cid,api=rd.take('2i')
        if cid not in out:raise ValueError('UNEXPECTED_CASE_ID')
        if api==0:casts[cid]=[rd.text() for _ in range(4)];continue
        if api==1:value=(*rd.take('2i'),rd.block(120),rd.block(68),rd.block(68))
        elif api==2:value=(rd.take('i')[0],rd.text(),*rd.take('qi'))
        elif api==3:value=(*rd.take('Qi'),rd.text())
        elif api==5:
            n=rd.take('i')[0];args=[]
            if not 1<=n<=6:raise ValueError('BAD_FORMAT_ARG_COUNT')
            for _ in range(n):
                tag=rd.take('I')[0]
                if tag==0x590008:value=rd.text()
                elif tag==0x560015:value=rd.take('Q')[0]
                else:raise ValueError('UNKNOWN_FORMAT_TAG')
                args.append((tag,value))
            value=(args,rd.text())
        elif api==6:value=tuple(rd.text() for _ in range(4))
        else:raise ValueError('UNKNOWN_FIXTURE_API '+str(api))
        out[cid].append((api,value))
    if len(casts)!=count or rd.pos!=len(rd.raw):raise ValueError('FIXTURE_NOT_EXACT')
    return out,casts,chart,digits
def read_results(path):
    raw=path.read_bytes();magic,version,n=struct.unpack_from('<3i',raw)
    if (magic,version)!=(MAGIC,1) or len(raw)!=12+212*n:raise ValueError('BAD_RESULTS_SHAPE')
    return [raw[12+212*i:12+212*(i+1)] for i in range(n)]

class Original(pending.fill.entry.Original):
    def __init__(self,bot,fixtures,casts,chart,digits):
        super().__init__(bot);self.bot=bot;self.send_cfg=CFG[bot];self.records_by_id=fixtures;self.casts=casts;self.chart=chart;self.default_digits=digits;self.schemas=layout()
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        self.ranges=[(int(f['begin_rva'],16),int(f['end_rva'],16)) for f in meta['functions'] if int(f['begin_rva'],16) in RANGES[bot]]
        if len(self.ranges)!=len(RANGES[bot]):raise ValueError('NATIVE_FUNCTION_NOT_FOUND')
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        extra={eb+0x7d8b70:41,eb+0x7d8be0:42,eb+0x7c29d0:43,eb+0x7cd7c0:44,eb+0x7b49f0:45,eb+0x7cf6c0:46,eb+0x3959a0:200}
        for page in {a&~0xfff for a in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for address in extra:self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit)
        self.m.hook_add(self.uc.UC_HOOK_MEM_WRITE,self.write_guard)
    def visit(self,m,address,size,user):
        if address not in self.apis and not any(self.base+a<=address<self.base+b for a,b in self.ranges):raise ValueError('NATIVE_LEFT_CHECKED_FUNCTIONS '+hex(address))
    def write_guard(self,m,access,address,size,value,user):
        if not self.executing:return
        if 0x50000000<=address and address+size<=0x50020000:return
        if 0x70000000<=address and address+size<=0x70200000:return
        start=self.base+self.send_cfg['slot']
        if start<=address and address+size<=start+12:return
        raise ValueError('UNEXPECTED_PROGRAM_STATE_WRITE '+hex(address-self.base))
    def text(self,descriptor):
        ptr=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if ptr==0:return ''
        n=struct.unpack('<I',self.m.mem_read(ptr-4,4))[0]
        if n>4096:raise ValueError('NATIVE_STRING_TOO_LONG')
        return bytes(self.m.mem_read(ptr,n*2)).decode('utf-16-le')
    def supply(self,descriptor,value):self.m.mem_write(descriptor,struct.pack('<IQ',0,self.string(value)))
    def shared(self,value):self.supply(self.base+self.send_cfg['slot'],value)
    def next(self,api):
        if self.position>=len(self.records):raise ValueError('EXTRA_NATIVE_API '+str(api))
        kind,value=self.records[self.position];self.position+=1
        if kind!=api:raise ValueError('API_ORDER_DIFFERS '+str((kind,api)))
        return value
    def struct_bytes(self,key,pointer):
        raw=bytearray()
        for f in self.schemas[key]['fields']:
            address=pointer+f['offset']
            raw+=struct.pack('<Q',text_hash(self.text(address))) if f['kind']=='s' else bytes(self.m.mem_read(address,struct.calcsize('<'+f['kind'])))
        return bytes(raw)
    def populate(self,key,pointer,values,null_symbol=False):
        for f in self.schemas[key]['fields']:
            address=pointer+f['offset'];kind=f['kind'];value=values[f['name']]
            if kind=='s':
                if null_symbol and f['name']=='symbol':self.m.mem_write(address,b'\0'*12)
                else:self.supply(address,value)
            else:self.m.mem_write(address,struct.pack('<'+kind,value))
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;r=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        if api in [41,42]:
            async_mode,accepted,request,old,new=self.next(1);req=m.reg_read(x.UC_X86_REG_RDX);result=m.reg_read(x.UC_X86_REG_R8)
            if int(api==42)!=async_mode or self.struct_bytes('request',req)!=request or self.struct_bytes('result',result)!=old:raise ValueError('SEND_ARGUMENTS_DIFFER')
            self.executing=False
            try:
                if r['write_result']:self.populate('result',result,r['new_result'])
            finally:self.executing=True
            if self.struct_bytes('result',result)!=new:raise ValueError('SUPPLIED_SEND_RESULT_DIFFERS')
            m.reg_write(x.UC_X86_REG_RAX,accepted)
        elif api==43:
            prop,text,value,ok=self.next(2)
            if (m.reg_read(x.UC_X86_REG_R8)&0xffffffff)!=prop or self.text(m.reg_read(x.UC_X86_REG_RDX))!=text:raise ValueError('SYMBOL_ARGUMENTS_DIFFER')
            m.mem_write(m.reg_read(x.UC_X86_REG_R9),struct.pack('<q',value));m.reg_write(x.UC_X86_REG_RAX,ok)
        elif api==44:
            value,digits,result=self.next(3)
            if (m.reg_read(x.UC_X86_REG_XMM1)&MASK)!=value or (m.reg_read(x.UC_X86_REG_R8)&0xffffffff)!=(digits&0xffffffff):raise ValueError('DOUBLE_TO_STRING_ARGUMENTS_DIFFER')
            self.shared(result)
        elif api==45:
            opcode=m.reg_read(x.UC_X86_REG_RDX);argc=m.reg_read(x.UC_X86_REG_R8);first_tag=m.reg_read(x.UC_X86_REG_R9);sp=m.reg_read(x.UC_X86_REG_RSP)
            if opcode==216:
                expected,result=self.next(5)
                if argc!=len(expected):raise ValueError('STRING_FORMAT_ARG_COUNT_DIFFERS')
                actual=[]
                for i in range(argc):
                    tag=first_tag if i==0 else struct.unpack('<I',m.mem_read(sp+32+16*i,4))[0]
                    value=struct.unpack('<Q',m.mem_read(sp+40+16*i,8))[0]
                    if tag==0x590008:value=self.text(value)
                    elif tag!=0x560015:raise ValueError('UNEXPECTED_NATIVE_FORMAT_TYPE '+hex(tag))
                    actual.append((tag,value))
                if actual!=expected:raise ValueError('STRING_FORMAT_ARGUMENTS_DIFFER '+repr((actual,expected)))
                self.shared(result)
            elif opcode==13:
                fmt,request,result,output=self.next(6)
                if argc!=3 or first_tag!=0x590008:raise ValueError('PRINT_FORMAT_SHAPE_DIFFERS')
                actual=[self.text(struct.unpack('<Q',m.mem_read(sp+40+16*i,8))[0]) for i in range(3)]
                if actual!=[fmt,request,result]:raise ValueError('PRINT_FORMAT_ARGUMENTS_DIFFER '+repr((actual,[fmt,request,result])))
                self.print_count+=1;self.print_hash=text_hash(output)
            else:raise ValueError('UNEXPECTED_DISPATCH '+str(opcode))
        elif api==46:
            value=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;kind=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            if kind==0x52 and value==(r['request']['action']&0xffffffff):text=self.casts[r['id']][0]
            elif kind==0x53 and value==(r['request']['type']&0xffffffff):text=self.casts[r['id']][1]
            elif kind==0x53 and value==r['result']['retcode']:text=self.casts[r['id']][2]
            elif kind==0x53 and value==r['new_result']['retcode']:text=self.casts[r['id']][3]
            else:raise ValueError('UNEXPECTED_NUMERIC_CAST')
            self.supply(m.reg_read(x.UC_X86_REG_R9),text)
        elif api==200:raise ValueError('NATIVE_RUNTIME_FAULT '+hex(m.reg_read(x.UC_X86_REG_RDX)))
        else:raise ValueError('UNEXPECTED_API '+str(api))
    def run(self,row):
        self.executing=False;m,x=self.m,self.x;self.case=row;self.cursor=0x70001000;self.allocs=self.frees=0;self.position=0;self.print_count=0;self.print_hash=0;self.records=self.records_by_id[row['id']]
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.mem_write(0x50000000,b'\0'*0x20000)
        cfg=self.send_cfg;ctx=self.base+cfg['context'];req=self.base+cfg['request'];res=self.base+cfg['result']
        self.populate('request',req,row['request'],bool(row['symbol_null']));self.populate('result',res,row['result'])
        m.mem_write(ctx+660,bytes([row['async_mode']]));m.mem_write(ctx+681,struct.pack('<i',row['margin_mode']));m.mem_write(ctx+685,struct.pack('<i',row['log_level']))
        m.mem_write(self.base+cfg['digits'],struct.pack('<i',self.default_digits));self.supply(self.base+cfg['chart'],self.chart)
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.reg_write(x.UC_X86_REG_RCX,ctx);m.reg_write(x.UC_X86_REG_RDX,req);m.reg_write(x.UC_X86_REG_R8,res)
        self.executing=True
        try:m.emu_start(self.base+0x950,0x60000000,timeout=5000000,count=500000)
        finally:self.executing=False
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000 or self.position!=len(self.records):raise ValueError('NATIVE_SEQUENCE_NOT_COMPLETE '+str((self.position,len(self.records))))
        if self.allocs!=self.frees:raise ValueError('NATIVE_OWNED_STRING_LEAK '+str((self.allocs,self.frees)))
        return struct.pack('<2i',row['id'],int(bool(m.reg_read(x.UC_X86_REG_RAX)&255)))+self.struct_bytes('request',req)+self.struct_bytes('result',res)+struct.pack('<2iQ',self.position,self.print_count,self.print_hash)

def verify_build(bot,build):
    if not build or not re.fullmatch('[a-z0-9-]+',build):raise ValueError('BUILD_REQUIRED')
    p=ROOT/f'bot-cua-toi-{bot}/bang-chung/bien-dich'/build/'bien-nhan.json';d=json.loads(p.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{bot}/Bot{bot}TradeSendCheck.mq5';script=MT/'MQL5'/target.replace('.mq5','.ex5')
    if d['target']!=target or d['errors'] or d['warnings'] or sha(script)!=d['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
    names=[target]+[f'Include/bot-cua-toi-{bot}/Bot{bot}{n}.mqh' for n in ['TradeSend','TradeMessages','PendingRequest','Filling']]
    for name in names:
        if sha(ROOT/f'bot-cua-toi-{bot}/source/MQL5'/name)!=d['sources_sha256'][name]:raise ValueError('SOURCE_CHANGED')
    return p,script
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','mql5','original','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-gui-lenh'/a.run
    if a.mode=='prepare':
        digest=pending.fill.validation.original_hash(a.bot);out.mkdir(parents=True,exist_ok=False);rows=cases();(out/'cases.bin').write_bytes(encode(rows));save(out/'cases.json',json_cases(rows))
        save(out/'baseline.json',dict(original_ex5_sha256=digest,cases=len(rows),cases_sha256=sha(out/'cases.bin'),layout_sha256=sha(LAYOUT),tool_sha256=sha(Path(__file__))))
        print(json.dumps({'cases':len(rows)}));return
    rows=read_cases(out/'cases.bin');baseline=json.loads((out/'baseline.json').read_text())
    if sha(out/'cases.bin')!=baseline['cases_sha256'] or sha(LAYOUT)!=baseline['layout_sha256']:raise ValueError('INPUTS_CHANGED')
    if a.mode=='mql5':
        receipt,script=verify_build(a.bot,a.build)
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-trade-send'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}-send.set'
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        ini=MT/f'b{a.bot}-{a.run}-send.ini'
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\n'+f'Script=bot-cua-toi-{a.bot}\\Bot{a.bot}TradeSendCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        if code:raise RuntimeError('MT5_FAILED '+str(code))
        for name in ['mql5-results.bin','api-fixtures.bin']:shutil.copyfile(files/name,out/name)
        save(out/'mql5-run.json',dict(exit_code=code,seconds=round(time.monotonic()-start,2),script_sha256=sha(script),build_receipt_sha256=sha(receipt),hashes={n:sha(out/n) for n in ['mql5-results.bin','api-fixtures.bin']}))
        print(json.dumps({'cases':len(read_results(out/'mql5-results.bin'))}));return
    if a.mode=='original':
        if pending.fill.validation.original_hash(a.bot)!=baseline['original_ex5_sha256']:raise ValueError('ORIGINAL_CHANGED')
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        fixtures,casts,chart,digits=read_fixtures(out/'api-fixtures.bin',len(rows));o=Original(a.bot,fixtures,casts,chart,digits);start=time.monotonic();values=[]
        for row in rows:
            try:values.append(o.run(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} rip_rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,1,len(values))+b''.join(values))
        save(out/'original-run.json',dict(cases=len(values),seconds=round(time.monotonic()-start,2),result_sha256=sha(out/'original-results.bin'),fixtures_sha256=sha(out/'api-fixtures.bin'),tool_sha256=sha(Path(__file__)),scope=__doc__))
        print(json.dumps({'cases':len(values)}));return
    original=read_results(out/'original-results.bin');actual=read_results(out/'mql5-results.bin')
    if len(original)!=len(rows) or len(actual)!=len(rows):raise ValueError('RESULT_COUNT_DIFFERS')
    failures=[]
    for i,(x,y) in enumerate(zip(original,actual)):
        if x!=y:
            n=next(j for j in range(212) if x[j]!=y[j]);failures.append(dict(id=i,first_different_byte=n,original=x[n:n+8].hex(),mql5=y[n:n+8].hex()))
    result=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:20],hashes={n:sha(out/n) for n in ['cases.bin','original-results.bin','mql5-results.bin','api-fixtures.bin']},scope='Full send wrapper and request/result message functions, ordered typed send/property/format calls, request/result fields, printed arguments and text. Send outcome is supplied and formatting/casts measured in MT5. No real or demo broker order submission, allocation-failure or whole EA claim.')
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))
if __name__=='__main__':main()
