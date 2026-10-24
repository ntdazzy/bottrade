"""Compare the complete position-modify-by-ticket path with the original EX5 code.

Usage: kiem-sua-vi-the-bot-1-3.py prepare|mql5|original|compare BOT RUN [--build BUILD]
Order: prepare -> compile BotNPositionModifyCheck.mq5 -> mql5 --build -> original -> compare.
IsStopped, PositionSelectByTicket/PositionGetString replies and the send reply are
supplied and input-bound; formatting/casts are measured in MT5. Original 0x26d20/0x32a90
executes to return with 0x950, message and string helpers. Public state, four strings,
NULL flags, stored values and send options are compared before each service call,
after send and on return. Final state is frozen before separate original output-string
cleanup; memory balance is checked afterwards. Every analysed instruction must run.
No real orders, callers, full EA, broker/account behavior or allocation-fault proof.
"""
import argparse
import copy
import hashlib
import importlib.util
import itertools
import json
import math
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x4d4f4431
spec=importlib.util.spec_from_file_location('modify_close',Path(__file__).with_name('kiem-dong-vi-the-bot-1-3.py'))
close=importlib.util.module_from_spec(spec);spec.loader.exec_module(close)
cancel=close.cancel;send=close.send;pending=close.pending;sha=close.sha;save=close.save;MT=close.MT
FN={1:0x26d20,3:0x32a90};RESET={1:0x26dfb,3:0x32b6b};CODE_BASE={1:0x23e5aa10000,3:0x17156250000}
LITERALS={1:[0x541c0,0x52eb0],3:[0x5c970,0x5b660]};SDK={0x7b49f0:45,0x7d7ee0:60,0x7d8010:63}
ENGINE='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb'
PADDING=[(128,112),(312,124),(500,128)];STRINGS=[20,100,292,488]
TEXTS=['request.symbol','request.comment','result.comment','check.comment']
COUNTERS=['entries','selects','strings','sends','format_failures','early_prints','events','print_count']
GPRS=['RAX','RBX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']
CALLEE_SAVED=['RBX','RBP','RDI','RSI','R12','R13','R14','R15',*[f'XMM{i}' for i in range(6,16)]]
OUTPUTS=['mql5-results.bin','api-fixtures.bin','script-status.bin']
NUMBERS=[-math.inf,-1.,-0.,0.,cancel.from_bits(1),.25,1.005,2600.125,1e19,math.inf,
         *[cancel.from_bits(v) for v in [0x7ff8000000000123,0xfff8000000000456,0x7ff0000000000789,0xfff0000000000abc]]]
TICKETS=[0,1,(1<<53)+1,1<<63,(1<<64)-1]

class Reader(send.Reader):
    # Every read is bounded so a truncated tail can never be accepted.
    def take(self,fmt):
        if self.pos+struct.calcsize('<'+fmt)>len(self.raw):raise ValueError('TRUNCATED_INPUT')
        return super().take(fmt)
    def block(self,n):
        if n<0 or self.pos+n>len(self.raw):raise ValueError('TRUNCATED_INPUT')
        return super().block(n)
    def text(self):
        n=self.take('i')[0]
        if not 0<=n<=4096:raise ValueError('BAD_STRING_LENGTH')
        return self.block(2*n).decode('utf-16-le')

def analysis_dir(bot):return ROOT/f'bot-cua-toi-{bot}/phan-tich/dong-vi-the/modify-20261025-r1'
def names(bot):
    return [f'Scripts/bot-cua-toi-{bot}/Bot{bot}PositionModifyCheck.mq5',f'Scripts/bot-cua-toi-{bot}/Bot{bot}PipelineApi.mqh']+[f'Include/bot-cua-toi-{bot}/Bot{bot}{name}.mqh' for name in ['PositionModify','TradeSend','TradeMessages','PendingRequest','Filling']]

def base():
    return dict(id=0,group='',scenario=0,ticket=0x123456789abcdef0,magic=0x7654321076543210,deviation=0xfedcba9876543210,
                stopped=0,preferred=2,select_ok=1,symbol_null=0,symbol='XAUUSD',sl=2500.5,tp=2700.25,send=send.base())

def cases():
    rows=[]
    def add(row,group):row.update(id=len(rows),group=group);row['send']['id']=row['id'];rows.append(row)
    for stopped,selected,ticket in itertools.product([-2147483648,-1,0,1,2],[0,1],TICKETS):
        row=base();row.update(stopped=stopped,select_ok=selected,ticket=ticket);add(row,'stop-select-ticket64')
    for sl,tp in itertools.product(NUMBERS,repeat=2):
        row=base();row.update(sl=sl,tp=tp);add(row,'sl-tp-bit-patterns')
    for (symbol,null),magic in itertools.product([('',0),('',1),('Vàng.💰',0),('XAUUSD',0),('XAUUSD.long.symbol.name',0)],[0,1,(1<<53)+1,1<<63,(1<<64)-1]):
        row=base();row.update(symbol=symbol,symbol_null=null,magic=magic);add(row,'symbol-null-empty-and-magic64')
    # Printed request text must stay within the 4096-character fixture/native reader limit.
    for length in [1,15,16,17,255,256,1023,2048]:
        row=base();row.update(symbol='S'*length);add(row,'symbol-lengths')
    for margin,ticket in itertools.product([-1,0,1,2,3],[0,1,1<<63,(1<<64)-1]):
        row=base();row.update(ticket=ticket);row['send']['margin_mode']=margin;add(row,'message-margin-and-position')
    for preferred,deviation in itertools.product([-1,0,1,2,3],[0,(1<<64)-1]):
        row=base();row.update(preferred=preferred,deviation=deviation);add(row,'unused-stored-values')
    for child in send.cases():
        row=base();row['send']=copy.deepcopy(child);request=child['request']
        row.update(symbol='' if child['symbol_null'] else request['symbol'],symbol_null=child['symbol_null'],sl=request['sl'],tp=request['tp'],ticket=request['position'])
        add(row,'full-send-'+child['group'])
    for scenario,selected,stopped in itertools.product(range(1,8),[0,1],[0,1]):
        row=base();row.update(scenario=scenario,select_ok=selected,stopped=stopped);row['send']['log_level']=0 if scenario==1 else 2
        add(row,'controlled-boundary-changes')
    for stopped,null,write,log in itertools.product([0,1],[0,1],[0,1],[0,2]):
        row=base();row.update(stopped=stopped);row['send'].update(symbol_null=null,write_result=write,log_level=log);row['send']['request']['symbol']=''
        for key in ['request','result','new_result']:row['send'][key]['comment']=''
        add(row,'state-null-versus-empty')
    for child,(stopped,selected) in itertools.product(send.cases()[::60],[(1,1),(0,0)]):
        row=base();row['send']=copy.deepcopy(child);row.update(stopped=stopped,select_ok=selected);add(row,'early-exit-keeps-initial-state')
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for row in rows:
        raw+=send.encode([row['send']])[12:]+struct.pack('<iQQQiii',row['scenario'],row['ticket'],row['magic'],row['deviation'],row['stopped'],row['preferred'],row['select_ok'])
        raw+=struct.pack('<i',row['symbol_null'])+send.pack_text(row['symbol'])+struct.pack('<2d',row['sl'],row['tp'])
    return bytes(raw)

def read_cases(path):
    rd=Reader(path.read_bytes())
    if rd.take('2i')!=(MAGIC,1):raise ValueError('BAD_MODIFY_HEADER')
    n=rd.take('i')[0];rows=[];schemas=send.layout()
    if not 1<=n<=30000:raise ValueError('BAD_MODIFY_COUNT')
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
        row=dict(zip(['scenario','ticket','magic','deviation','stopped','preferred','select_ok'],rd.take('iQQQiii')));row.update(id=i,send=env)
        row['symbol_null']=rd.take('i')[0];row['symbol']=rd.text();row['sl'],row['tp']=rd.take('2d')
        if env['id']!=i or not 0<=row['scenario']<=7 or row['select_ok'] not in [0,1] or row['symbol_null'] not in [0,1] or (row['symbol_null'] and row['symbol']) or not 0<=env['async_mode']<=255:raise ValueError('BAD_MODIFY_CASE')
        rows.append(row)
    if rd.pos!=len(rd.raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return rows

def state_block(rd):
    start=rd.pos;rd.block(260)
    for _ in range(4):rd.text()
    rd.take('4iQ3i');return rd.raw[start:rd.pos]

def state_segments(raw,pos=0):
    out=[(pos,pos+8,'stored.magic'),(pos+8,pos+12,'stored.preferred')];pos+=12;layouts=send.layout()
    for key in ['request','result','check']:
        for field in layouts[key]['fields']:
            size=8 if field['kind']=='s' else struct.calcsize('<'+field['kind']);out.append((pos,pos+size,key+'.'+field['name']+(' hash' if field['kind']=='s' else '')));pos+=size
    for name in TEXTS:
        if pos+4>len(raw):return out,pos
        size=4+2*max(0,struct.unpack_from('<i',raw,pos)[0]);out.append((pos,pos+size,name+' text'));pos+=size
    for name in TEXTS:out.append((pos,pos+4,name+' null'));pos+=4
    for name,size in [('stored.deviation',8),('options.async_mode',4),('options.margin_mode',4),('options.log_level',4)]:out.append((pos,pos+size,name));pos+=size
    return out,pos

def result_segments(raw):
    out,pos=state_segments(raw,8);out=[(0,4,'id'),(4,8,'return'),*out]
    for name in COUNTERS:out.append((pos,pos+4,'counter.'+name));pos+=4
    return out+[(pos,pos+8,'counter.print_hash')]

def difference(left,right,segments):
    at=next((j for j,(x,y) in enumerate(zip(left,right)) if x!=y),min(len(left),len(right)))
    field=next((name for lo,hi,name in segments if lo<=at<hi),'length')
    return dict(first_different_byte=at,field=field,original=left[at:at+20].hex(),mql5=right[at:at+20].hex())

def fixtures(path,n):
    rd=Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('FIXTURE_HEADER_DIFFERS')
    chart=rd.text();digits=rd.take('i')[0];records={i:[] for i in range(n)};last=-1
    while rd.pos<len(rd.raw):
        cid,api=rd.take('2i')
        if cid not in records or cid<last:raise ValueError('FIXTURE_ID_DIFFERS')
        last=cid
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
        elif api==17:value=tuple(rd.text() for _ in range(4))
        elif api==18:value=state_block(rd)
        elif api==20:value=rd.take('iQi')
        elif api==23:value=(*rd.take('3i'),rd.text())
        else:raise ValueError('UNEXPECTED_MODIFY_FIXTURE '+str(api))
        records[cid].append((api,value))
    if rd.pos!=len(rd.raw):raise ValueError('FIXTURE_BYTES_NOT_EXACT')
    return records,chart,digits

def validate_inputs(row,records):
    env=row['send'];indexes={17:0,33:0};selects=strings=sends=casts=0
    result=b''.join(struct.pack('<Q',send.text_hash(env['new_result'][f['name']])) if f['kind']=='s' else struct.pack('<'+f['kind'],env['new_result'][f['name']]) for f in send.layout()['result']['fields'])
    if not records or records[0][0]!=17:raise ValueError('CAST_RECORD_NOT_FIRST')
    for api,value in records:
        if api==17:
            casts+=1
            if casts!=1 or value!=('6','0','0',str(env['new_result']['retcode'])):raise ValueError('CAST_OR_SLTP_CONSTANT_DIFFERS')
        elif api==20:
            index,ticket,ok=value
            if index!=selects or index!=0 or ticket!=row['ticket'] or ok!=row['select_ok']:raise ValueError('SELECT_INPUT_DIFFERS')
            selects+=1
        elif api==23:
            prop,index,null,symbol=value
            if prop!=0 or index!=strings or index!=0 or selects!=1 or (null,symbol)!=(row['symbol_null'],row['symbol']):raise ValueError('POSITION_SYMBOL_INPUT_DIFFERS')
            strings+=1
        elif api==1:
            mode,accepted,request,old,new=value
            if sends or strings!=1 or (mode,accepted)!=(int(env['async_mode']!=0),int(env['accepted']!=0)) or new!=(result if env['write_result'] else old):raise ValueError('SEND_INPUT_DIFFERS')
            sends+=1;indexes={17:0,33:0}
        elif api==2:
            prop,symbol,actual,ok=value
            if not sends or prop not in indexes or indexes[prop]>=2:raise ValueError('FORMAT_PROPERTY_COUNT_DIFFERS')
            index=indexes[prop];indexes[prop]+=1;key='digits' if prop==17 else 'executions';flags='digits_ok' if prop==17 else 'execution_ok'
            if (actual,ok)!=(env[key][index],env[flags][index]):raise ValueError('FORMAT_INPUT_DIFFERS')
        elif api not in [3,5,6,8,18]:raise ValueError('UNEXPECTED_MODIFY_RECORD '+str(api))

def read_results(path,n):
    rd=Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('RESULT_HEADER_DIFFERS')
    rows=[]
    for i in range(n):
        start=rd.pos
        if rd.take('i')[0]!=i:raise ValueError('RESULT_ID_DIFFERS')
        rd.take('I');state_block(rd);rd.take('8iQ');rows.append(rd.raw[start:rd.pos])
    if rd.pos!=len(rd.raw):raise ValueError('RESULT_BYTES_NOT_EXACT')
    return rows

def dependencies(bot):
    result=close.dependencies(bot);folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data';home=analysis_dir(bot)
    receipt=json.loads((home/'receipt.json').read_text())
    for name,digest in receipt['hashes'].items():
        if sha(home/name)!=digest:raise ValueError('MODIFY_ANALYSIS_RECEIPT_DIFFERS '+name)
    paths=[Path(__file__),*(home/name for name in ['analysis.json','functions.c','native-guards.txt','receipt.json','semantics.json']),ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/strings.tsv']
    for path in paths:
        if not path.is_file():raise FileNotFoundError('MODIFY_DEPENDENCY_MISSING '+path.relative_to(ROOT).as_posix())
        result[path.relative_to(ROOT).as_posix()]=sha(path)
    return result

def engine_hash(bot):
    engine=json.loads((ROOT/f'bot-cua-toi-{bot}/bang-chung/luot-20261023-r1/engine-observed.json').read_text(encoding='utf-8-sig'))
    if engine.get('engine_sha256')!=ENGINE:raise ValueError('CAPTURE_ENGINE_CHANGED')
    return engine['engine_sha256']

def identity(bot,home):
    return dict(original_ex5_sha256=pending.fill.validation.original_hash(bot),engine_sha256=engine_hash(bot),tool_sha256=sha(Path(__file__)),
                dependencies_sha256=dependencies(bot),sources_sha256={name:sha(home/'source/MQL5'/name) for name in names(bot)})

def check_identity(record,current,stage):
    for key,value in current.items():
        if record.get(key)!=value:raise ValueError(f'{stage}_IDENTITY_CHANGED {key}')

def zero_count(value):return type(value) is int and value==0

def verify_receipt(receipt,path,bot,home,sources):
    target=names(bot)[0];digest=receipt.get('binary_sha256');compiled=receipt.get('sources_sha256')
    if receipt.get('target')!=target or not zero_count(receipt.get('errors')) or not zero_count(receipt.get('warnings')):raise ValueError('BUILD_NOT_CLEAN_OR_TARGET_DIFFERS')
    if type(digest) is not str or not re.fullmatch('[0-9a-f]{64}',digest) or sha(path.parent/Path(target).with_suffix('.ex5').name)!=digest:raise ValueError('BUILD_BINARY_DIFFERS')
    if type(compiled) is not dict:raise ValueError('BUILD_SOURCE_LIST_MISSING')
    for name in names(bot):
        if compiled.get(name)!=sources[name] or sha(home/'source/MQL5'/name)!=sources[name]:raise ValueError('COMPILED_SOURCE_DIFFERS '+name)
    return digest

def copy_new(source,target):
    with source.open('rb') as reader,target.open('xb') as writer:shutil.copyfileobj(reader,writer)

class Original(close.Original):
    def __init__(self,bot,records,chart,digits):
        super().__init__(bot,records,chart,digits)
        if self.base!=CODE_BASE[bot]:raise ValueError('CAPTURED_CODE_BASE_DIFFERS')
        analysis=json.loads((analysis_dir(bot)/'analysis.json').read_text());functions=analysis['functions']
        if analysis['original_ex5_sha256']!=pending.fill.validation.original_hash(bot) or analysis['engine_sha256']!=ENGINE or len(functions)!=1 or int(functions[0]['rva'],16)!=FN[bot]:raise ValueError('MODIFY_ANALYSIS_DIFFERS')
        fn=functions[0];self.fn=FN[bot];self.fn_end=int(fn['end_rva'],16)
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text());ends={int(f['begin_rva'],16):int(f['end_rva'],16) for f in meta['functions']}
        if ends.get(self.fn)!=self.fn_end:raise ValueError('MODIFY_FUNCTION_BOUNDARY_DIFFERS')
        if hashlib.sha256(bytes(self.m.mem_read(self.base+self.fn,self.fn_end-self.fn))).hexdigest()!=fn['native_bytes_sha256']:raise ValueError('MODIFY_NATIVE_BYTES_CHANGED')
        self.instructions={int(row['rva'],16) for row in fn['instructions']}
        if len(self.instructions)!=len(fn['instructions']) or len(self.instructions)!=196:raise ValueError('MODIFY_INSTRUCTION_LIST_DIFFERS')
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40;targets=set()
        for row in fn['instructions']:
            if row['mnemonic']=='movabs':
                value=int(row['operands'].split(', ')[1],16)
                if value>=eb:targets.add(value-eb)
        if targets!=set(SDK) or any(self.apis.get(eb+rva)!=api for rva,api in SDK.items()):raise ValueError('MODIFY_SDK_TARGETS_DIFFER')
        self.ranges=[(rva,ends[rva]) for rva in send.RANGES[bot]]+[(self.fn,self.fn_end)]
        self.covered=set();self.entries=self.reset_reached=0;self.literals={hex(rva):self.text(self.base+rva) for rva in LITERALS[bot]}
    def visit(self,m,address,size,user):
        offset=address-self.base
        if self.fn<=offset<self.fn_end:
            self.covered.add(offset)
            if offset==self.fn:self.entries+=1
            if offset==RESET[self.bot]:self.reset_reached+=1
        return send.Original.visit(self,m,address,size,user)
    def write_guard(self,m,access,address,size,value,user):
        # Only the 628-byte trade storage may change; magic, deviation, filling preference,
        # send options and the stop flag are read-only for this function.
        start=self.base+self.fill_cfg['request']
        if self.executing and start<=address and address+size<=start+628:return
        return send.Original.write_guard(self,m,access,address,size,value,user)
    def state_record(self):
        m=self.m;start=self.base+self.fill_cfg['request'];context=self.base+self.send_cfg['context']
        nulls=[int(struct.unpack('<Q',m.mem_read(start+offset+4,8))[0]==0) for offset in STRINGS]
        return cancel.Original.state_record(self)+struct.pack('<4i',*nulls)+bytes(m.mem_read(self.base+self.close['deviation'],8))+struct.pack('<i',m.mem_read(context+660,1)[0])+bytes(m.mem_read(context+681,8))
    def snapshot(self):
        expected=self.next(18);actual=self.state_record()
        if expected!=actual:raise ValueError('SERVICE_BOUNDARY_STATE_DIFFERS '+json.dumps(difference(actual,expected,state_segments(actual)[0])))
    def record_write(self,address,raw):
        self.m.mem_write(address,raw);self.harness_writes.append((address,bytes(raw)))
    def set_field(self,key,name,value):
        field=next(f for f in self.schemas[key]['fields'] if f['name']==name)
        address=self.base+self.fill_cfg['request']+self.layout['relative_native_storage_bases'][key]+field['offset']
        if field['kind']=='s':self.supply(address,value);self.harness_writes.append((address,bytes(self.m.mem_read(address,12))))
        else:self.record_write(address,struct.pack('<'+field['kind'],value))
    def change(self,api):
        scenario=self.row['scenario'];magic=self.base+self.pending_cfg['magic'];self.executing=False
        try:
            if api==20 and self.select_calls==1:
                if scenario==1:
                    self.record_write(magic,struct.pack('<Q',0x1111222233334444));self.record_write(self.base+self.close['deviation'],struct.pack('<Q',77))
                    self.set_field('request','price',11.5);self.set_field('result','retcode',4242);self.set_field('check','balance',-3.5)
                    self.record_write(self.base+self.send_cfg['context']+685,struct.pack('<i',2))
                if scenario==7:
                    stopped=self.base+self.pending_cfg['stopped'];self.record_write(stopped,struct.pack('<i',1 if struct.unpack('<i',self.m.mem_read(stopped,4))[0]==0 else 0))
            if api==23 and self.string_calls==1:
                if scenario==2:self.record_write(magic,struct.pack('<Q',0xfedcba9876543210))
                if scenario==3:
                    for name,value in [('price',33.25),('action',7),('position',0x55),('type_filling',3),('expiration',1234567)]:self.set_field('request',name,value)
                    self.set_field('result','deal',99);self.set_field('check','margin',8.5)
                if scenario==4:
                    for name,value in [('sl',1.),('tp',2.),('magic',3),('symbol','changed')]:self.set_field('request',name,value)
            if api==1 and self.actual_sends==1 and scenario==5:self.record_write(magic,struct.pack('<Q',0x0123456789abcdef));self.set_field('request','tp',-7.5)
            if api==8 and self.early_prints==1 and scenario==6:
                self.set_field('result','retcode',777);self.set_field('request','price',55.5);self.record_write(magic,struct.pack('<Q',42))
        finally:self.executing=True
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api==60:
            self.snapshot();index,ticket,ok=self.next(20)
            if m.reg_read(x.UC_X86_REG_RDX)!=ticket:raise ValueError('POSITION_SELECT_TICKET_DIFFERS')
            self.select_calls+=1;m.reg_write(x.UC_X86_REG_RAX,ok);self.change(20);return
        if api==63:
            self.snapshot();prop,index,null,symbol=self.next(23)
            if m.reg_read(x.UC_X86_REG_RDX)!=prop:raise ValueError('POSITION_STRING_PROPERTY_DIFFERS')
            self.string_calls+=1;self.shared(symbol)
            if null:m.mem_write(self.base+self.send_cfg['slot'],b'\0'*12)
            self.change(23);return
        if api in [41,42]:
            result=cancel.Original.call(self,m,address,size,user);self.change(1);self.snapshot();return result
        if api==45 and m.reg_read(x.UC_X86_REG_RDX)==13 and m.reg_read(x.UC_X86_REG_R8)==2:
            self.snapshot();result=cancel.Original.call(self,m,address,size,user);self.change(8);return result
        if api==46:
            value=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;kind=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            if kind==0x53 and value==0:text=self.cast_strings[1]
            elif kind==0x53 and value==self.row['send']['new_result']['retcode']:text=self.cast_strings[3]
            else:raise ValueError(f'UNEXPECTED_MODIFY_NUMERIC_CAST {kind:#x} {value}')
            self.supply(m.reg_read(x.UC_X86_REG_R9),text);return
        if api in [43,44,45,100,101,200]:return cancel.Original.call(self,m,address,size,user)
        raise ValueError('UNEXPECTED_MODIFY_API '+str(api))
    def sentinels(self,case_id):
        # Distinct non-argument values prove the function reads only RCX/XMM1/XMM2 low halves.
        values={name:0xa5a5000000000000|(case_id<<12)|(i<<4)|5 for i,name in enumerate(GPRS)}
        values.update({f'XMM{i}':((0x7ff4000000000000|(case_id<<8)|i)<<64)|(0xfff4000000000000|(case_id<<8)|i) for i in range(16)});return values
    def run_modify(self,row):
        self.executing=False;m,x=self.m,self.x;self.row=row;env=row['send'];self.case=dict(env);self.case.update(request={'action':6,'type':0},result={'retcode':0})
        self.cursor=0x70001000;self.allocs=self.frees=0;self.position=0;self.records=self.records_by_id[row['id']];self.harness_writes=[]
        self.entries=self.reset_reached=self.select_calls=self.string_calls=self.actual_sends=self.format_failures=self.early_prints=self.print_count=self.print_hash=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        cfg=self.send_cfg;start=self.base+self.fill_cfg['request'];context=self.base+cfg['context'];m.mem_write(0x50000000,b'\0'*0x20000)
        m.mem_write(start,b'\x5a'*628);m.mem_write(self.base+cfg['slot'],b'\0'*12)
        self.populate('request',start,env['request'],bool(env['symbol_null']));self.populate('result',start+240,env['result']);self.populate('check',start+436,{f['name']:f['value'] for f in self.schemas['check']['fields']})
        m.mem_write(self.base+self.pending_cfg['magic'],struct.pack('<Q',row['magic']));m.mem_write(self.base+self.fill_cfg['preferred'],struct.pack('<i',row['preferred']))
        m.mem_write(self.base+self.pending_cfg['stopped'],struct.pack('<i',row['stopped']));m.mem_write(self.base+self.close['deviation'],struct.pack('<Q',row['deviation']))
        m.mem_write(context+660,bytes([env['async_mode']]));m.mem_write(context+681,struct.pack('<i',env['margin_mode']));m.mem_write(context+685,struct.pack('<i',env['log_level']))
        self.supply(self.base+cfg['chart'],self.chart);m.mem_write(self.base+cfg['digits'],struct.pack('<i',self.default_digits));self.cast_strings=self.next(17)
        old=bytes(m.mem_read(start,628));values=self.sentinels(row['id'])
        for name,value in values.items():m.reg_write(getattr(x,'UC_X86_REG_'+name),value)
        m.reg_write(x.UC_X86_REG_XMM1,(values['XMM1']>>64<<64)|cancel.bits(row['sl']));m.reg_write(x.UC_X86_REG_XMM2,(values['XMM2']>>64<<64)|cancel.bits(row['tp']))
        m.reg_write(x.UC_X86_REG_RCX,row['ticket']);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);self.executing=True
        try:m.emu_start(self.base+self.fn,0x60000000,timeout=5000000,count=4000000)
        finally:self.executing=False
        rax=m.reg_read(x.UC_X86_REG_RAX)
        # Consume the caller-owned transient return exactly as the close/send checks do.
        self.supply(self.base+cfg['slot'],'')
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000 or self.position!=len(self.records) or self.entries!=1:raise ValueError('MODIFY_EXECUTION_NOT_COMPLETE')
        changed=[name for name in CALLEE_SAVED if m.reg_read(getattr(x,'UC_X86_REG_'+name))!=values[name]]
        if m.reg_read(x.UC_X86_REG_RSP)!=top+8 or changed:raise ValueError('MODIFY_ABI_STATE_NOT_RESTORED '+','.join(changed))
        if rax>>32:raise ValueError('MODIFY_RETURN_UPPER_BITS_SET')
        if self.reset_reached:
            for offset,length in PADDING:
                if bytes(m.mem_read(start+offset,length))!=b'\0'*length:raise ValueError('MODIFY_PRIVATE_STORAGE_NOT_CLEARED')
        else:
            expected=bytearray(old)
            for address,raw in self.harness_writes:
                if start<=address<start+628:expected[address-start:address-start+len(raw)]=raw
            if self.early_prints:expected[240:244]=struct.pack('<I',10027)
            if bytes(m.mem_read(start,628))!=bytes(expected):raise ValueError('EARLY_MODIFY_CHANGED_UNEXPECTED_STORAGE')
        result=struct.pack('<iI',row['id'],rax&0xffffffff)+self.state_record()+struct.pack('<8iQ',self.entries,self.select_calls,self.string_calls,self.actual_sends,self.format_failures,self.early_prints,self.position,self.print_count,self.print_hash)
        # The modify function has returned and its output is frozen. Release the four
        # live output strings through the original RVA 0 helper, then check balance.
        for offset in STRINGS:
            m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_RCX,start+offset);self.executing=True
            try:m.emu_start(self.base,0x60000000,timeout=5000000,count=4000000)
            finally:self.executing=False
            if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise ValueError('OUTPUT_STRING_CLEANUP_NOT_COMPLETE')
        if self.allocs!=self.frees:raise ValueError('MODIFY_MEMORY_NOT_BALANCED_AFTER_OUTPUT_CLEANUP')
        return result

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('mode',choices=['prepare','mql5','original','compare']);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('run');parser.add_argument('--build');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,40}',a.run):raise ValueError('INVALID_RUN')
    home=ROOT/f'bot-cua-toi-{a.bot}';out=home/'bang-chung/kiem-sua-vi-the'/a.run;current=identity(a.bot,home);generated=cases()
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False)
        with (out/'cases.bin').open('xb') as stream:stream.write(encode(generated))
        descriptions=copy.deepcopy(generated)
        for row in descriptions:
            row['sl'],row['tp']=(struct.pack('<d',row['sl']).hex(),struct.pack('<d',row['tp']).hex());row['send']=send.json_cases([row['send']])[0]
        save(out/'cases.json',descriptions);save(out/'baseline.json',dict(cases=len(generated),cases_sha256=sha(out/'cases.bin'),**current))
        print(json.dumps(dict(cases=len(generated))));return
    baseline=json.loads((out/'baseline.json').read_text());check_identity(baseline,current,'BASELINE');rows=read_cases(out/'cases.bin');n=len(rows)
    if baseline['cases_sha256']!=sha(out/'cases.bin') or baseline['cases']!=n or encode(generated)!=(out/'cases.bin').read_bytes():raise ValueError('CASES_CHANGED')
    groups=[row['group'] for row in generated]
    if a.mode=='mql5':
        if not a.build or not re.fullmatch('[a-z0-9-]{1,48}',a.build):raise ValueError('BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'));binary=MT/'MQL5'/names(a.bot)[0].replace('.mq5','.ex5')
        digest=verify_receipt(receipt,receipt_path,a.bot,home,current['sources_sha256'])
        if sha(binary)!=digest or any(sha(MT/'MQL5'/name)!=value for name,value in current['sources_sha256'].items()):raise ValueError('TERMINAL_COPY_DIFFERS_FROM_BUILD')
        if any((out/name).exists() for name in [*OUTPUTS,'mql5-run.json','tested-sources']):raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-position-modify'/a.run;files.mkdir(parents=True,exist_ok=False);copy_new(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-modify-{a.run}.set';ini=MT/f'b{a.bot}-modify-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as stream:stream.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as stream:stream.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PositionModifyCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        before=sha(MT/'terminal64.exe');started=time.monotonic();process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MT5_POSITION_MODIFY_TIMEOUT')
        after=sha(MT/'terminal64.exe')
        if code or before!=after:raise RuntimeError(f'MT5_RUN_FAILED_OR_TERMINAL_CHANGED {code}')
        for name in OUTPUTS:copy_new(files/name,out/name)
        if (out/'script-status.bin').read_bytes()!=struct.pack('<2i',0,n):raise ValueError('MODIFY_SCRIPT_INCOMPLETE')
        tested=out/'tested-sources';tested.mkdir(exist_ok=False)
        for name in names(a.bot):copy_new(home/'source/MQL5'/name,tested/Path(name).name)
        copy_new(Path(__file__),tested/'check-tool.py')
        save(out/'mql5-run.json',dict(cases=n,exit_code=code,seconds=round(time.monotonic()-started,2),script_sha256=digest,terminal_sha256_before=before,terminal_sha256_after=after,
             build_receipt=receipt_path.relative_to(ROOT).as_posix(),build_receipt_sha256=sha(receipt_path),metaeditor_sha256=receipt.get('metaeditor_sha256'),**current,
             hashes={name:sha(out/name) for name in OUTPUTS},tested_sources_sha256={p.name:sha(p) for p in sorted(tested.iterdir())}))
        print(json.dumps(dict(cases=n)));return
    mql=json.loads((out/'mql5-run.json').read_text());check_identity(mql,current,'MQL5_RUN')
    for name,digest in mql['hashes'].items():
        if sha(out/name)!=digest:raise ValueError('MQL_EVIDENCE_CHANGED '+name)
    for name,digest in mql['tested_sources_sha256'].items():
        if sha(out/'tested-sources'/name)!=digest:raise ValueError('TESTED_SOURCE_COPY_CHANGED '+name)
    if a.mode=='original':
        if (out/'original-results.bin').exists() or (out/'original-run.json').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        records,chart,digits=fixtures(out/'api-fixtures.bin',n)
        for row in rows:validate_inputs(row,records[row['id']])
        o=Original(a.bot,records,chart,digits);started=time.monotonic();values=[];paths=dict(stopped=0,select_failed=0,sent=0)
        for row in rows:
            try:values.append(o.run_modify(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} group={groups[row["id"]]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
            paths['stopped' if o.early_prints else 'sent' if o.actual_sends else 'select_failed']+=1
        missing=sorted(o.instructions-o.covered)
        if missing or o.covered-o.instructions:raise ValueError('MODIFY_INSTRUCTION_COVERAGE_INCOMPLETE '+','.join(hex(v) for v in missing[:24]))
        with (out/'original-results.bin').open('xb') as stream:stream.write(struct.pack('<3i',MAGIC,1,n)+b''.join(values))
        save(out/'original-run.json',dict(cases=n,seconds=round(time.monotonic()-started,2),result_sha256=sha(out/'original-results.bin'),fixture_sha256=sha(out/'api-fixtures.bin'),**current,
             native_rva=hex(FN[a.bot]),paths=paths,coverage=dict(instructions=len(o.instructions),executed=len(o.covered)),observed_literals=o.literals,input_contract_checked_cases=n,scope=__doc__))
        print(json.dumps(dict(cases=n,paths=paths)));return
    native=json.loads((out/'original-run.json').read_text());check_identity(native,current,'ORIGINAL_RUN');receipt_path=ROOT/mql['build_receipt'];receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    if sha(receipt_path)!=mql['build_receipt_sha256'] or verify_receipt(receipt,receipt_path,a.bot,home,current['sources_sha256'])!=mql['script_sha256']:raise ValueError('BUILD_EVIDENCE_CHANGED')
    if set(mql['sources_sha256'])!=set(names(a.bot)) or mql['terminal_sha256_before']!=mql['terminal_sha256_after'] or mql['terminal_sha256_after']!=sha(MT/'terminal64.exe'):raise ValueError('MQL_SOURCE_SET_OR_TERMINAL_CHANGED')
    if sha(out/'original-results.bin')!=native['result_sha256'] or sha(out/'api-fixtures.bin')!=native['fixture_sha256'] or native['cases']!=n or native['coverage']['executed']!=native['coverage']['instructions']:raise ValueError('NATIVE_EVIDENCE_CHANGED')
    records,_,_=fixtures(out/'api-fixtures.bin',n)
    for row in rows:validate_inputs(row,records[row['id']])
    expected=read_results(out/'original-results.bin',n);actual=read_results(out/'mql5-results.bin',n);failures=[]
    for i,(left,right) in enumerate(zip(expected,actual)):
        if left!=right:failures.append(dict(id=i,group=groups[i],**difference(left,right,result_segments(left))))
    result=dict(cases=n,matched=n-len(failures),failed=len(failures),first_failures=failures[:12],paths=native['paths'],coverage=native['coverage'],observed_literals=native['observed_literals'],
                hashes={name:sha(out/name) for name in ['cases.bin','original-results.bin',*OUTPUTS]},whole_bot_complete=False,scope=__doc__)
    save(out/'comparison.json',result);print(json.dumps(result,ensure_ascii=False));raise SystemExit(bool(failures))

if __name__=='__main__':main()
