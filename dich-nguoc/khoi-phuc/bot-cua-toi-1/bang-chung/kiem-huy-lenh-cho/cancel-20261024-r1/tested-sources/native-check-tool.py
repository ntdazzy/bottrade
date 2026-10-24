"""Compare the complete cancel guard -> request reset -> original send/messages.

Usage: kiem-huy-lenh-cho-bot-1-3.py prepare|mql5|original|compare BOT RUN [--build BUILD]
Original functions 0x34150/0x32450 execute to return, including 0x950. Only terminal
services are supplied; every supplied return is bound to serialized inputs.
No orders are sent. Bid/ask offsets and properties16/32 have known-source proof.
"""
import argparse
import copy
import importlib.util
import json
import math
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x43414e31
spec=importlib.util.spec_from_file_location('send_check',Path(__file__).with_name('kiem-gui-lenh-bot-1-3.py'))
send=importlib.util.module_from_spec(spec);spec.loader.exec_module(send)
pending=send.pending;MT=send.MT;sha=send.sha;save=send.save
TICK=ROOT/'doi-chung-mt5/huy-lenh-cho-20261024/cancel-tick-api-r1'
FN={1:0x34150,3:0x32450}
FIELDS=[('ticket','Q'),('select_ok','i'),('stopped','i'),('order_null','i'),('preferred','i'),('order_type','q'),('magic','Q'),('tick_ok','i'),('point','d'),('bid','d'),('ask','d'),('price','d'),('freeze','q')]

def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def from_bits(value):return struct.unpack('<d',struct.pack('<Q',value))[0]
def base():return dict(ticket=0x123456789abcdef0,select_ok=1,stopped=0,order_null=0,preferred=2,order_type=4,magic=0x7654321076543210,tick_ok=1,point=.25,bid=100.,ask=102.,price=104.,freeze=4,symbol='XAUUSD')
def cases():
    rows=[]
    def add(group,**changes):
        guard=base();env=send.base();i=len(rows);env.update(id=i,async_mode=[0,1,255][i%3],log_level=[-1,0,1,2,3][i%5],margin_mode=[0,2][i%2],accepted=i%2,write_result=int(i%7!=0))
        env['new_result']['retcode']=[0,10004,10009,10018,10041,0xffffffff][i%6]
        for key,value in changes.items():
            if key.startswith('send.'):
                key=key[5:]
                if key.startswith('result.'):env['new_result'][key[7:]]=value
                else:env[key]=value
            else:guard[key]=value
        rows.append(dict(id=i,group=group,guard=guard,send=env))
    types=[-1,0,1,2,3,4,5,6,7,8,9,*[0x100000000+i for i in range(2,8)],-0x8000000000000000,0x7fffffffffffffff]
    distances=[-math.inf,-1.,-0.,0.,math.nextafter(1.,0.),1.,math.nextafter(1.,math.inf),2.,math.inf,math.nan]
    for kind in types:
        for distance in distances:
            low=kind&0xffffffff;price=-distance if low in [2,5,7] else distance
            for stopped in [0,1]:add('type-and-distance-boundary',order_type=kind,bid=0.,ask=0.,point=1.,freeze=1,price=price,stopped=stopped)
    numbers=[-math.inf,-1.,-0.,0.,from_bits(1),.25,1.,math.inf,*[from_bits(v) for v in [0x7ff8000000000123,0xfff8000000000456,0x7ff0000000000789,0xfff0000000000abc]]]
    for point in numbers:
        for freeze in [-0x8000000000000000,-2,-1,0,1,4,(1<<53)+1,0x7fffffffffffffff]:
            for ok in [0,1]:add('point-product-and-tick-read',point=point,freeze=freeze,tick_ok=ok,bid=0.,ask=1.,price=2.)
    for bid,ask in [(0.,0.),(0.,1.),(1.,0.),(-math.inf,math.inf),(math.inf,math.inf),(math.nan,1.),(1.,math.nan),(-0.,0.)]:
        for kind in range(2,8):
            for price in [-1.,0.,1.,math.inf,math.nan]:add('spread-fallback',bid=bid,ask=ask,freeze=0,order_type=kind,price=price)
    for selected in [0,1]:
        for stopped in [-2147483648,-1,0,1,2]:
            for ticket in [0,1,(1<<53)+1,(1<<64)-1]:add('selection-stopped-and-ticket',select_ok=selected,stopped=stopped,ticket=ticket)
    for symbol,null in [('',0),('',1),('Vàng.💰',0),('XAUUSD.long.symbol',0)]:
        for magic in [0,1,0xffffffffffffffff,0x100000001]:add('symbol-null-and-stored-magic',symbol=symbol,order_null=null,magic=magic)
    for accepted in [0,1]:
        for async_mode in [0,1,2,255]:
            for log in [-1,0,1,2,3]:
                for write in [0,1]:add('send-after-cancel',select_ok=0,**{'send.accepted':accepted,'send.async_mode':async_mode,'send.log_level':log,'send.write_result':write})
    for ok in [[0,0],[0,1],[1,0],[1,1]]:
        for code in [10004,10009,10010,0xffffffff]:add('send-format-read-errors',select_ok=0,**{'send.log_level':2,'send.accepted':0,'send.digits_ok':ok,'send.execution_ok':ok,'send.result.retcode':code})
    return rows
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for row in rows:raw+=send.encode([row['send']])[12:]+b''.join(struct.pack('<'+kind,row['guard'][name]) for name,kind in FIELDS)+send.pack_text(row['guard']['symbol'])
    return raw
def read_cases(path):
    rd=send.Reader(path.read_bytes());magic,version,n=rd.take('3i')
    if (magic,version)!=(MAGIC,1):raise ValueError('BAD_CANCEL_CASE_HEADER')
    rows=[];schemas=send.layout()
    for i in range(n):
        env=dict(zip(['id','async_mode','log_level','margin_mode','accepted','write_result'],rd.take('6i')));env.update(digits=list(rd.take('2q')),executions=list(rd.take('2q')))
        ok=rd.take('4i');env.update(digits_ok=list(ok[:2]),execution_ok=list(ok[2:]))
        for key in ['request','result','new_result']:
            values={}
            for field in schemas['request' if key=='request' else 'result']['fields']:
                if field['kind']=='s':
                    if field['name']=='symbol':env['symbol_null']=rd.take('i')[0]
                    values[field['name']]=rd.text()
                else:values[field['name']]=rd.take(field['kind'])[0]
            env[key]=values
        guard={name:rd.take(kind)[0] for name,kind in FIELDS};guard['symbol']=rd.text()
        if env['id']!=i:raise ValueError('CANCEL_IDS_DIFFER')
        rows.append(dict(id=i,guard=guard,send=env))
    if rd.pos!=len(rd.raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return rows
def fixtures(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('FIXTURE_HEADER_DIFFERS')
    chart=rd.text();digits=rd.take('i')[0];records={i:[] for i in range(n)}
    while rd.pos<len(rd.raw):
        cid,api=rd.take('2i')
        if cid not in records:raise ValueError('FIXTURE_ID_DIFFERS')
        if api==1:value=(*rd.take('2i'),rd.block(120),rd.block(68),rd.block(68))
        elif api==2:value=(rd.take('i')[0],rd.text(),*rd.take('qi'))
        elif api==3:value=(*rd.take('Qi'),rd.text())
        elif api==5:
            count=rd.take('i')[0];args=[]
            if not 1<=count<=6:raise ValueError('FORMAT_COUNT_DIFFERS')
            for _ in range(count):
                tag=rd.take('I')[0]
                if tag==0x590008:item=rd.text()
                elif tag==0x560015:item=rd.take('Q')[0]
                else:raise ValueError('FORMAT_TAG_DIFFERS')
                args.append((tag,item))
            value=(args,rd.text())
        elif api==6:value=tuple(rd.text() for _ in range(4))
        elif api==8:value=tuple(rd.text() for _ in range(3))
        elif api==10:value=rd.take('Qi')
        elif api==11:value=(*rd.take('2i'),rd.text())
        elif api in [12,13,14]:
            null=rd.take('i')[0];symbol=rd.text();value=(null,symbol,*rd.take({12:'iQ',13:'i2Q',14:'iq'}[api]))
        elif api in [15,16]:value=rd.take('iQ' if api==15 else 'iq')
        elif api==17:value=tuple(rd.text() for _ in range(4))
        else:raise ValueError('UNKNOWN_CANCEL_FIXTURE '+str(api))
        records[cid].append((api,value))
    return records,chart,digits
def validate_inputs(row,records):
    guard=row['guard'];env=row['send'];indexes={17:0,33:0};sent=False
    result=b''.join(struct.pack('<Q',send.text_hash(env['new_result'][f['name']])) if f['kind']=='s' else struct.pack('<'+f['kind'],env['new_result'][f['name']]) for f in send.layout()['result']['fields'])
    for api,value in records:
        if api==10:expected=(guard['ticket'],int(guard['select_ok']!=0))
        elif api==11:expected=(0,guard['order_null'],guard['symbol'])
        elif api==12:expected=(guard['order_null'],guard['symbol'],16,bits(guard['point']))
        elif api==13:expected=(guard['order_null'],guard['symbol'],int(guard['tick_ok']!=0),bits(guard['bid']),bits(guard['ask']))
        elif api==14:expected=(guard['order_null'],guard['symbol'],32,guard['freeze'])
        elif api==15:expected=(9,bits(guard['price']))
        elif api==16:expected=(4,guard['order_type'])
        elif api==1:
            mode,accepted,request,old,new=value
            if sent or (mode,accepted)!=(int(env['async_mode']!=0),int(env['accepted']!=0)) or new!=(result if env['write_result'] else old):raise ValueError('SEND_SUPPLIED_INPUT_DIFFERS')
            sent=True;continue
        elif api==2:
            prop,symbol,actual,ok=value
            if prop not in indexes or indexes[prop]>=2:raise ValueError('UNEXPECTED_FORMAT_PROPERTY')
            index=indexes[prop];indexes[prop]+=1;key='digits' if prop==17 else 'executions';flags='digits_ok' if prop==17 else 'execution_ok'
            if (actual,ok)!=(env[key][index],env[flags][index]):raise ValueError('FORMAT_PROPERTY_INPUT_DIFFERS')
            continue
        else:continue
        if value!=expected:raise ValueError('GUARD_SUPPLIED_INPUT_DIFFERS '+str(api))
def read_results(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('RESULT_HEADER_DIFFERS')
    rows=[]
    for i in range(n):
        start=rd.pos
        if rd.take('i')[0]!=i:raise ValueError('RESULT_ID_DIFFERS')
        rd.take('i');rd.block(260)
        for _ in range(4):rd.text()
        rd.take('5iQ');rows.append(rd.raw[start:rd.pos])
    if rd.pos!=len(rd.raw):raise ValueError('RESULT_BYTES_NOT_EXACT')
    return rows
def dependencies(bot):
    home=ROOT/f'bot-cua-toi-{bot}';folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data';capture=home/'bang-chung/captures/luot-20261023-r1/capture.json'
    paths=[Path(__file__),Path(send.__file__),Path(pending.__file__),Path(pending.fill.__file__),Path(pending.fill.validation.__file__),Path(pending.fill.validation.volume.__file__),Path(pending.fill.entry.__file__),Path(pending.fill.entry.price_check.__file__),send.LAYOUT,home/'phan-tich'/folder/'metadata/import.json',capture,home/'bang-chung/luot-20261023-r1/engine-observed.json']
    paths.extend(ROOT/name for name in json.loads(send.LAYOUT.read_text())['source_sha256']);paths.extend(capture.parent/region['file'] for region in json.loads(capture.read_text())['regions'])
    paths.extend(TICK/name for name in ['tick-fields.json','tick-fields-native.txt','calibration.json','build.json','engine-observed.json','RecoveryApiLibrary.mq5','RecoveryApiDriver.mq5'])
    probe=TICK/'captures/library/capture.json';paths.append(probe);paths.extend(probe.parent/region['file'] for region in json.loads(probe.read_text())['regions'])
    runtime=ROOT.parent/'.local/claude-recovery-20261023/python/unicorn';paths.extend(p for p in runtime.rglob('*') if p.is_file() and p.suffix in ['.py','.dll'])
    return {(p.relative_to(ROOT).as_posix() if p.is_relative_to(ROOT) else '../'+p.relative_to(ROOT.parent).as_posix()):sha(p) for p in paths}

class Original(send.Original):
    def __init__(self,bot,records,chart,digits):
        super().__init__(bot,records,{},chart,digits);self.bot=bot;self.fill_cfg=pending.fill.CFG[bot];self.pending_cfg=pending.CFG[bot];self.layout=json.loads(send.LAYOUT.read_text());self.guard_rows=None
        tick=json.loads((TICK/'tick-fields.json').read_text())
        if not tick['runner_verified'] or not tick['only_anchor_executed'] or tick['fields']!={'bid':8,'ask':16} or tick['calibration_sha256']!=sha(TICK/'calibration.json'):raise ValueError('TICK_LAYOUT_NOT_VERIFIED')
        for name,digest in self.layout['source_sha256'].items():
            if sha(ROOT/name)!=digest:raise ValueError('TRADE_LAYOUT_SOURCE_CHANGED')
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data';meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text());self.ranges.append((FN[bot],int(next(f['end_rva'] for f in meta['functions'] if int(f['begin_rva'],16)==FN[bot]),16)))
        eb=next(address for address,api in self.apis.items() if api==1)-0x7d3c40
        for address,api in {eb+0x7d8240:51,eb+0x7c2890:52,eb+0x7c2c10:53}.items():
            page=address&~4095
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
    def state_record(self):
        start=self.base+self.fill_cfg['request'];return pending.Original.state_bytes(self)+b''.join(send.pack_text(self.text(start+offset)) for offset in [20,100,292,488])
    def write_guard(self,m,access,address,size,value,user):
        if self.executing:
            for start,length in [(self.base+self.fill_cfg['request'],628),(self.base+self.pending_cfg['magic'],8),(self.base+self.fill_cfg['preferred'],4)]:
                if start<=address and address+size<=start+length:return
        return super().write_guard(m,access,address,size,value,user)
    def string_argument(self,expected):
        pointer=self.m.reg_read(self.x.UC_X86_REG_RDX);null=int(struct.unpack('<Q',self.m.mem_read(pointer+4,8))[0]==0)
        if (null,self.text(pointer))!=expected:raise ValueError('GUARD_SYMBOL_ARGUMENT_DIFFERS')
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;sp=m.reg_read(x.UC_X86_REG_RSP)
        if api==51:
            ticket,ok=self.next(10)
            if m.reg_read(x.UC_X86_REG_RDX)!=ticket:raise ValueError('SELECT_TICKET_DIFFERS')
            m.reg_write(x.UC_X86_REG_RAX,ok);return
        if api==7:
            prop,null,symbol=self.next(11)
            if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=prop:raise ValueError('ORDER_SYMBOL_PROPERTY_DIFFERS')
            self.shared(symbol)
            if null:m.mem_write(self.base+self.send_cfg['slot'],b'\0'*12)
            return
        if api in [52,3]:
            record=self.next(12 if api==52 else 14);null,symbol,prop,value=record;self.string_argument((null,symbol))
            if m.reg_read(x.UC_X86_REG_R8)&0xffffffff!=prop:raise ValueError('SYMBOL_PROPERTY_DIFFERS')
            if api==52:
                m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value)
            else:m.reg_write(x.UC_X86_REG_RAX,value&send.MASK)
            return
        if api==53:
            null,symbol,ok,bid,ask=self.next(13);self.string_argument((null,symbol));pointer=m.reg_read(x.UC_X86_REG_R8)
            if pointer!=sp+0x68 or not 0x50000000<=pointer<pointer+24<=0x50020000:raise ValueError('TICK_OUTPUT_POINTER_DIFFERS')
            m.mem_write(pointer+8,struct.pack('<2Q',bid,ask));m.reg_write(x.UC_X86_REG_RAX,ok);return
        if api in [8,6]:
            prop,value=self.next(15 if api==8 else 16)
            if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=prop:raise ValueError('ORDER_PROPERTY_DIFFERS')
            if api==8:m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value)
            else:m.reg_write(x.UC_X86_REG_RAX,value&send.MASK)
            return
        if api in [41,42]:self.actual_sends+=1;return super().call(m,address,size,user)
        if api==43:
            record=self.records[self.position]
            if record[0]!=2:raise ValueError('FORMAT_PROPERTY_RECORD_DIFFERS')
            self.format_failures+=int(not record[1][-1]);return super().call(m,address,size,user)
        if api==45 and m.reg_read(x.UC_X86_REG_RDX)==13 and m.reg_read(x.UC_X86_REG_R8)==2:
            expected=self.next(8)
            if m.reg_read(x.UC_X86_REG_R9)!=0x590008 or struct.unpack('<I',m.mem_read(sp+48,4))[0]!=0x590008:raise ValueError('STOPPED_MESSAGE_TAG_DIFFERS')
            actual=[self.text(struct.unpack('<Q',m.mem_read(sp+40+16*i,8))[0]) for i in range(2)]
            if actual!=list(expected[:2]):raise ValueError('STOPPED_MESSAGE_ARGUMENTS_DIFFER')
            self.early_prints+=1;return
        return super().call(m,address,size,user)
    def run_cancel(self,row):
        self.executing=False;m,x=self.m,self.x;env=row['send'];guard=row['guard'];self.case=dict(env);self.case.update(request={'action':8,'type':0},result={'retcode':0});self.cursor=0x70001000;self.allocs=self.frees=0;self.position=0;self.records=self.records_by_id[row['id']];self.print_count=self.print_hash=self.actual_sends=self.format_failures=self.early_prints=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000);cfg=self.send_cfg;start=self.base+self.fill_cfg['request'];context=self.base+cfg['context']
        m.mem_write(start,b'\x5a'*628);m.mem_write(self.base+cfg['slot'],b'\0'*12);self.populate('request',start,env['request'],bool(env['symbol_null']));self.populate('result',start+240,env['result']);self.populate('check',start+436,{f['name']:f['value'] for f in self.schemas['check']['fields']})
        m.mem_write(self.base+self.pending_cfg['magic'],struct.pack('<Q',guard['magic']));m.mem_write(self.base+self.fill_cfg['preferred'],struct.pack('<i',guard['preferred']));m.mem_write(self.base+self.pending_cfg['stopped'],struct.pack('<i',guard['stopped']))
        m.mem_write(context+660,bytes([env['async_mode']]));m.mem_write(context+681,struct.pack('<i',env['margin_mode']));m.mem_write(context+685,struct.pack('<i',env['log_level']));self.supply(self.base+cfg['chart'],self.chart);m.mem_write(self.base+cfg['digits'],struct.pack('<i',self.default_digits));self.casts[row['id']]=self.next(17)
        old=bytes(m.mem_read(start,628));top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_RCX,guard['ticket']);self.executing=True
        try:m.emu_start(self.base+FN[self.bot],0x60000000,timeout=5000000,count=4000000)
        finally:self.executing=False
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000 or self.position!=len(self.records) or self.allocs!=self.frees:raise ValueError('CANCEL_EXECUTION_NOT_COMPLETE_OR_MEMORY_BALANCED')
        if not self.actual_sends:
            expected=bytearray(old)
            if self.early_prints:expected[240:244]=struct.pack('<I',10027)
            if bytes(m.mem_read(start,628))!=bytes(expected):raise ValueError('EARLY_CANCEL_CHANGED_UNEXPECTED_STORAGE')
        else:
            for offset,length in [(128,112),(312,124),(500,128)]:
                if bytes(m.mem_read(start+offset,length))!=b'\0'*length:raise ValueError('CANCEL_RESERVED_STORAGE_NOT_CLEARED')
        value=0 if self.bot==1 else int(bool(m.reg_read(x.UC_X86_REG_RAX)&255))
        return struct.pack('<2i',row['id'],value)+self.state_record()+struct.pack('<5iQ',self.actual_sends,self.format_failures,self.early_prints,self.position,self.print_count,self.print_hash)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('mode',choices=['prepare','mql5','original','compare']);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('run');parser.add_argument('--build');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    home=ROOT/f'bot-cua-toi-{a.bot}';out=home/'bang-chung/kiem-huy-lenh-cho'/a.run
    if a.mode=='prepare':
        digest=pending.fill.validation.original_hash(a.bot);out.mkdir(parents=True,exist_ok=False);rows=cases();(out/'cases.bin').write_bytes(encode(rows));descriptions=copy.deepcopy(rows)
        for row in descriptions:
            for name in ['point','bid','ask','price']:row['guard'][name]=struct.pack('<d',row['guard'][name]).hex()
            row['send']=send.json_cases([row['send']])[0]
        save(out/'cases.json',descriptions);save(out/'baseline.json',dict(cases=len(rows),cases_sha256=sha(out/'cases.bin'),original_ex5_sha256=digest,tool_sha256=sha(Path(__file__))));print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((out/'baseline.json').read_text());rows=read_cases(out/'cases.bin');n=len(rows)
    if baseline['cases_sha256']!=sha(out/'cases.bin') or baseline['original_ex5_sha256']!=pending.fill.validation.original_hash(a.bot):raise ValueError('INPUT_OR_ORIGINAL_CHANGED')
    if a.mode=='mql5':
        if not a.build or not re.fullmatch('[a-z0-9-]+',a.build):raise ValueError('BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}OrderCancelCheck.mq5';binary=MT/'MQL5'/target.replace('.mq5','.ex5')
        if receipt['target']!=target or receipt['errors'] or receipt['warnings'] or sha(binary)!=receipt['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
        names=[target,f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PipelineApi.mqh']+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['OrderCancel','TradeSend','TradeMessages','PendingRequest','Filling']]
        for name in names:
            if sha(home/'source/MQL5'/name)!=receipt['sources_sha256'][name] or sha(MT/'MQL5'/name)!=receipt['sources_sha256'][name]:raise ValueError('TESTED_SOURCE_CHANGED')
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-order-cancel'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b{a.bot}-cancel-{a.run}.set';preset.write_text(f'CheckRun={a.run}\n',encoding='utf-16');ini=MT/f'b{a.bot}-cancel-{a.run}.ini'
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}OrderCancelCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');started=time.monotonic();process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MT5_CANCEL_TIMEOUT')
        if code:raise RuntimeError('MT5_CANCEL_FAILED '+str(code))
        for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']:shutil.copyfile(files/name,out/name)
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,n):raise ValueError('CANCEL_SCRIPT_INCOMPLETE')
        save(out/'mql5-run.json',dict(cases=n,exit_code=code,seconds=round(time.monotonic()-started,2),script_sha256=sha(binary),build_receipt=receipt_path.relative_to(ROOT).as_posix(),build_receipt_sha256=sha(receipt_path),sources_sha256={name:receipt['sources_sha256'][name] for name in names},hashes={name:sha(out/name) for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']}));print(json.dumps({'cases':n}));return
    if a.mode=='original':
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        records,chart,digits=fixtures(out/'api-fixtures.bin',n)
        for row in rows:validate_inputs(row,records[row['id']])
        o=Original(a.bot,records,chart,digits);started=time.monotonic();values=[]
        for row in rows:
            try:values.append(o.run_cancel(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,1,n)+b''.join(values));save(out/'original-run.json',dict(cases=n,seconds=round(time.monotonic()-started,2),result_sha256=sha(out/'original-results.bin'),fixture_sha256=sha(out/'api-fixtures.bin'),tool_sha256=sha(Path(__file__)),dependencies_sha256=dependencies(a.bot),input_contract_checked_cases=n,scope=__doc__));print(json.dumps({'cases':n}));return
    mql=json.loads((out/'mql5-run.json').read_text());native=json.loads((out/'original-run.json').read_text());receipt_path=ROOT/mql['build_receipt'];receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    if receipt['errors'] or receipt['warnings'] or sha(receipt_path)!=mql['build_receipt_sha256'] or receipt['binary_sha256']!=mql['script_sha256'] or sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name)!=mql['script_sha256']:raise ValueError('BUILD_EVIDENCE_CHANGED')
    for name,digest in mql['sources_sha256'].items():
        if sha(home/'source/MQL5'/name)!=digest:raise ValueError('CURRENT_SOURCE_CHANGED')
    for name,digest in mql['hashes'].items():
        if sha(out/name)!=digest:raise ValueError('MQL_EVIDENCE_CHANGED')
    if sha(out/'original-results.bin')!=native['result_sha256'] or sha(out/'api-fixtures.bin')!=native['fixture_sha256'] or native['dependencies_sha256']!=dependencies(a.bot) or native['tool_sha256']!=baseline['tool_sha256'] or encode(cases())!=(out/'cases.bin').read_bytes():raise ValueError('NATIVE_OR_GENERATED_INPUT_CHANGED')
    records,chart,digits=fixtures(out/'api-fixtures.bin',n)
    for row in rows:validate_inputs(row,records[row['id']])
    original=read_results(out/'original-results.bin',n);actual=read_results(out/'mql5-results.bin',n);failures=[]
    for i,(left,right) in enumerate(zip(original,actual)):
        if left!=right:
            at=next((j for j,(x,y) in enumerate(zip(left,right)) if x!=y),min(len(left),len(right)));failures.append(dict(id=i,first_different_byte=at,original=left[at:at+20].hex(),mql5=right[at:at+20].hex()))
    result=dict(cases=n,matched=n-len(failures),failed=len(failures),first_failures=failures[:12],hashes={name:sha(out/name) for name in ['cases.bin','original-results.bin','mql5-results.bin','api-fixtures.bin','script-status.bin']},whole_bot_complete=False,scope=__doc__)
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))

if __name__=='__main__':main()
