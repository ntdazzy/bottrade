"""Compare full position-close builders/guards, filling, send and messages.

Usage: kiem-dong-vi-the-bot-1-3.py prepare|mql5|original|compare BOT RUN [--build BUILD]
SDK replies are input-bound; original instructions execute the algorithms. Public
state/null flags are compared before queries and after send, as well as on return.
No real orders, broker/account-selection, full-EA or allocation-fault proof.
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

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x50434c31
spec=importlib.util.spec_from_file_location('close_cancel',Path(__file__).with_name('kiem-huy-lenh-cho-bot-1-3.py'))
cancel=importlib.util.module_from_spec(spec);spec.loader.exec_module(cancel)
send=cancel.send;pending=cancel.pending;sha=cancel.sha;save=cancel.save;MT=cancel.MT
PROBE=ROOT/'doi-chung-mt5/dong-vi-the-20261024/close-api-r1'
CFG={1:dict(functions=[0x22c40,0x3d010],filling=0x231c0,deviation=0x6772d,variables=[0x67758,0x67760,0x66a70,0x67468]),
     3:dict(functions=[0x2e370,0x47d20],filling=0x2e8f0,deviation=0x7476d,variables=[0x74798,0x747a0,0x73ab0,0x744a8])}

def base(mode):
    return dict(id=0,mode=mode,scenario=0,ticket=0x123456789abcdef0,magic=0x7654321076543210,deviation=0xfedcba9876543210,
                stopped=0,preferred=2,position_magic=-123,select_ok=[1,1,1],types=[0,0,0,0],sl=[0.]*4,volumes=[.25,.5],prices=[100.,102.],
                symbols=[[0,'XAUUSD'],[0,'XAUUSD']],executions=[0,0],fillings=[0,0],variables=[100.,102.,1.,1.],send=send.base())

def cases():
    rows=[]
    def add(row,group):row.update(id=len(rows),group=group);row['send']['id']=row['id'];rows.append(row)
    for stopped,selected,ticket in itertools.product([-2147483648,-1,0,1,2],[0,1],[0,1,(1<<53)+1,(1<<64)-1]):
        row=base(0);row.update(stopped=stopped,select_ok=[selected]*3,ticket=ticket);add(row,'direct-stop-select-ticket')
    for execution,flags,preferred in itertools.product([-1,0,1,2,3,4,0x100000000,0x100000002,-0x8000000000000000,0x7fffffffffffffff],[-1,0,1,2,3,0x100000000,0x7fffffffffffffff],[-1,0,1,2,3]):
        row=base(0);row.update(executions=[execution]*2,fillings=[flags]*2,preferred=preferred);add(row,'direct-filling-before-action')
    for kind in [-0x8000000000000000,-1,0,1,2,0x100000000,0x100000001,0x7fffffffffffffff]:
        for number in [-math.inf,-1.,-0.,0.,cancel.from_bits(1),.25,math.inf,math.nan]:
            row=base(0);row.update(types=[kind]*4,prices=[number]*2,volumes=[number]*2);add(row,'direct-low32-type-and-double-bits')
    for symbol,null in [('',0),('',1),('Vàng.💰',0),('XAUUSD.long',0)]:
        for value in [0,1,(1<<53)+1,1<<63,(1<<64)-1]:
            row=base(0);row.update(symbols=[[null,symbol]]*2,magic=value,deviation=value);add(row,'direct-null-symbol-magic-deviation')
    for child in send.cases():
        row=base(0);row['send']=copy.deepcopy(child);add(row,'full-send-'+child.get('group','case'))
    for first,second in itertools.product([-1,0,1,2,0x100000000,0x100000001],repeat=2):
        row=base(1);row['types']=[first,second,second,second];add(row,'guard-full64-type-reread')
    for types in [[0,0,0,0],[1,1,1,1],[0,0,1,1],[0,1,1,0],[1,0,0,0],[0,1,0,0]]:
        for selected in [[0,1,1],[1,0,1],[1,1,0],[1,1,1]]:
            row=base(1);row.update(types=types,select_ok=selected);add(row,'guard-two-close-paths')
    numbers=[-math.inf,-1.,-0.,0.,cancel.from_bits(1),math.nextafter(1.,0.),1.,math.nextafter(1.,math.inf),2.,math.inf,
             *[cancel.from_bits(v) for v in [0x7ff8000000000123,0xfff8000000000456,0x7ff0000000000789,0xfff0000000000abc]]]
    for kind,level,threshold in itertools.product([0,1],numbers,numbers):
        row=base(1);row.update(types=[kind]*4,sl=[level]*4,variables=[0.,0.,threshold,threshold]);add(row,'guard-ordered-abs-boundaries')
    for first,second in itertools.product(numbers,repeat=2):
        row=base(1);row.update(sl=[first,second,first,second],variables=[10.,100.,1.,2.]);add(row,'guard-sl-reread-and-reference-choice')
    for mode,scenario,types in itertools.product([0,1],range(1,6),[[0,0,0,0],[1,1,1,1],[0,0,1,1]]):
        row=base(mode);row.update(scenario=scenario,types=types);add(row,'controlled-query-side-effects')
    for mode,null,write,log in itertools.product([0,1],[0,1],[0,1],[0,2]):
        row=base(mode);row['send'].update(symbol_null=null,write_result=write,log_level=log)
        row['send']['request']['symbol']=''
        for key in ['request','result','new_result']:row['send'][key]['comment']=''
        add(row,'state-null-versus-empty')
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for row in rows:
        raw+=send.encode([row['send']])[12:]+struct.pack('<2i3Q2iq',row['mode'],row['scenario'],row['ticket'],row['magic'],row['deviation'],row['stopped'],row['preferred'],row['position_magic'])
        raw+=struct.pack('<3i4q4d2d2d',*row['select_ok'],*row['types'],*row['sl'],*row['volumes'],*row['prices'])
        for null,symbol in row['symbols']:raw+=struct.pack('<i',null)+send.pack_text(symbol)
        raw+=struct.pack('<4q4d',*row['executions'],*row['fillings'],*row['variables'])
    return raw

def read_cases(path):
    rd=send.Reader(path.read_bytes())
    if rd.take('2i')!=(MAGIC,1):raise ValueError('BAD_CLOSE_HEADER')
    n=rd.take('i')[0];rows=[];schemas=send.layout()
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
        row=dict(zip(['mode','scenario','ticket','magic','deviation','stopped','preferred','position_magic'],rd.take('2i3Q2iq')));row.update(id=i,send=env)
        for name,fmt in [('select_ok','3i'),('types','4q'),('sl','4d'),('volumes','2d'),('prices','2d')]:row[name]=list(rd.take(fmt))
        row['symbols']=[[rd.take('i')[0],rd.text()] for _ in range(2)];row['executions']=list(rd.take('2q'));row['fillings']=list(rd.take('2q'));row['variables']=list(rd.take('4d'))
        if env['id']!=i or row['mode'] not in [0,1] or not 0<=row['scenario']<=5:raise ValueError('BAD_CLOSE_CASE')
        rows.append(row)
    if rd.pos!=len(rd.raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return rows

def state_block(rd):
    start=rd.pos;rd.block(260)
    for _ in range(4):rd.text()
    rd.take('4iQ4d');return rd.raw[start:rd.pos]

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
        elif api==9:value=(rd.take('i')[0],rd.text(),rd.take('q')[0])
        elif api==17:value=tuple(rd.text() for _ in range(4))
        elif api==18:value=state_block(rd)
        elif api==20:value=rd.take('iQi')
        elif api==21:value=rd.take('2iq')
        elif api==22:value=rd.take('2iQ')
        elif api==23:value=(*rd.take('3i'),rd.text())
        elif api==24:value=(*rd.take('3i'),rd.text(),rd.take('Q')[0])
        elif api==26:value=(rd.take('i')[0],rd.text())
        else:raise ValueError('UNKNOWN_CLOSE_FIXTURE '+str(api))
        records[cid].append((api,value))
    if rd.pos!=len(rd.raw):raise ValueError('FIXTURE_BYTES_NOT_EXACT')
    return records,chart,digits

def validate_inputs(row,records):
    counters=dict(select=0,type=0,sl=0,volume=0,symbol=0,price=0,execution=0,filling=0);indexes={17:0,33:0};env=row['send']
    result=b''.join(struct.pack('<Q',send.text_hash(env['new_result'][f['name']])) if f['kind']=='s' else struct.pack('<'+f['kind'],env['new_result'][f['name']]) for f in send.layout()['result']['fields'])
    for api,value in records:
        if api==17:
            if value!=('1','0','1',str(env['new_result']['retcode'])):raise ValueError('CAST_METADATA_DIFFERS')
        elif api==20:
            index,ticket,ok=value
            if index!=counters['select'] or index>=3 or ticket!=row['ticket'] or ok!=int(row['select_ok'][index]!=0):raise ValueError('SELECT_INPUT_DIFFERS')
            counters['select']+=1
        elif api==21:
            prop,index,actual=value
            if prop==12:
                if index!=0 or actual!=row['position_magic']:raise ValueError('MAGIC_INPUT_DIFFERS')
            elif prop==2:
                if index!=counters['type'] or index>=4 or actual!=row['types'][index]:raise ValueError('TYPE_INPUT_DIFFERS')
                counters['type']+=1
            else:raise ValueError('UNKNOWN_POSITION_INTEGER')
        elif api==22:
            prop,index,actual=value;key='sl' if prop==6 else 'volume';source='sl' if prop==6 else 'volumes'
            if prop not in [3,6] or index!=counters[key] or index>=len(row[source]) or actual!=cancel.bits(row[source][index]):raise ValueError('POSITION_DOUBLE_INPUT_DIFFERS')
            counters[key]+=1
        elif api==23:
            prop,index,null,symbol=value
            if prop!=0 or index!=counters['symbol'] or index>=2 or [null,symbol]!=row['symbols'][index]:raise ValueError('POSITION_SYMBOL_INPUT_DIFFERS')
            counters['symbol']+=1
        elif api==24:
            prop,index,null,symbol,actual=value
            if prop not in [1,4] or index!=counters['price'] or index>=2 or actual!=cancel.bits(row['prices'][index]):raise ValueError('CLOSE_PRICE_INPUT_DIFFERS')
            counters['price']+=1
        elif api==9:
            prop,symbol,actual=value;key='execution' if prop==33 else 'filling';source='executions' if prop==33 else 'fillings';index=counters[key]
            if prop not in [33,50] or index>=2 or actual!=row[source][index]:raise ValueError('FILLING_INPUT_DIFFERS')
            counters[key]+=1
        elif api==1:
            mode,accepted,request,old,new=value
            if (mode,accepted)!=(int(env['async_mode']!=0),int(env['accepted']!=0)) or new!=(result if env['write_result'] else old):raise ValueError('SEND_INPUT_DIFFERS')
            indexes={17:0,33:0}
        elif api==2:
            prop,symbol,actual,ok=value
            if prop not in indexes or indexes[prop]>=2:raise ValueError('FORMAT_PROPERTY_COUNT_DIFFERS')
            index=indexes[prop];indexes[prop]+=1;key='digits' if prop==17 else 'executions';flags='digits_ok' if prop==17 else 'execution_ok'
            if (actual,ok)!=(env[key][index],env[flags][index]):raise ValueError('FORMAT_INPUT_DIFFERS')

def read_results(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('RESULT_HEADER_DIFFERS')
    rows=[]
    for i in range(n):
        start=rd.pos
        if rd.take('i')[0]!=i:raise ValueError('RESULT_ID_DIFFERS')
        state_block(rd);rd.take('6iQ');rows.append(rd.raw[start:rd.pos])
    if rd.pos!=len(rd.raw):raise ValueError('RESULT_BYTES_NOT_EXACT')
    return rows

def dependencies(bot):
    result=cancel.dependencies(bot);paths=[Path(__file__),ROOT/'cong-cu/kiem-api-dong-vi-the.py']
    paths.extend(PROBE/name for name in ['api-contract.json','calibration.json','build.json','engine-observed.json','RecoveryApiLibrary.mq5','RecoveryApiDriver.mq5'])
    cap=PROBE/'captures/library/capture.json';paths.append(cap);paths.extend(cap.parent/r['file'] for r in json.loads(cap.read_text())['regions'])
    paths.extend(ROOT/f'bot-cua-toi-{bot}/phan-tich/dong-vi-the/close-20261024-r1'/name for name in ['analysis.json','semantics.json','native-guards.txt'])
    for path in paths:result[path.relative_to(ROOT).as_posix()]=sha(path)
    return result

class Original(cancel.Original):
    def __init__(self,bot,records,chart,digits):
        super().__init__(bot,records,chart,digits);self.close=CFG[bot]
        contract=json.loads((PROBE/'api-contract.json').read_text())
        if not contract['runner_verified'] or not contract['only_anchor_executed'] or contract['constants']['POSITION_SL']!=6 or contract['calibration_sha256']!=sha(PROBE/'calibration.json'):raise ValueError('CLOSE_API_NOT_VERIFIED')
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data';meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        for rva in [*self.close['functions'],self.close['filling']]:self.ranges.append((rva,int(next(f['end_rva'] for f in meta['functions'] if int(f['begin_rva'],16)==rva),16)))
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        for address,api in {eb+0x7d7ee0:60,eb+0x7d7fc0:61,eb+0x7d7f70:62,eb+0x7d8010:63}.items():
            page=address&~4095
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
    def visit(self,m,address,size,user):
        if address==self.base+self.close['functions'][0]:self.close_calls+=1
        if address==self.base+self.close['filling']:self.filling_entered=True
        return super().visit(m,address,size,user)
    def state_record(self):
        start=self.base+self.fill_cfg['request'];nulls=[int(struct.unpack('<Q',self.m.mem_read(start+off+4,8))[0]==0) for off in [20,100,292,488]]
        return super().state_record()+struct.pack('<4i',*nulls)+bytes(self.m.mem_read(self.base+self.close['deviation'],8))+b''.join(bytes(self.m.mem_read(self.base+off,8)) for off in self.close['variables'])
    def snapshot(self):
        if self.next(18)!=self.state_record():raise ValueError('SERVICE_BOUNDARY_STATE_DIFFERS')
    def change(self,api):
        row=self.row;m=self.m;self.executing=False;cfg=self.close
        try:
            if api==20 and self.select_calls==1 and row['scenario']==1:
                m.mem_write(self.base+self.pending_cfg['magic'],struct.pack('<Q',0x1111222233334444));m.mem_write(self.base+cfg['deviation'],struct.pack('<Q',77))
            if api==22 and self.sl_calls==1 and row['scenario'] in [2,3]:
                values=[120.,130.,3.,4.] if row['scenario']==2 else [120.,130.,math.inf,4.]
                for off,value in zip(cfg['variables'],values):m.mem_write(self.base+off,struct.pack('<d',value))
            if api==22 and self.volume_calls==1 and row['scenario']==4:
                m.mem_write(self.base+self.pending_cfg['magic'],struct.pack('<Q',0xfedcba9876543210));m.mem_write(self.base+cfg['deviation'],struct.pack('<Q',0xdeadbeef12345678))
            if api==1 and self.actual_sends==1 and row['scenario']==5:
                for off,value in zip(cfg['variables'][:2],[200.,300.]):m.mem_write(self.base+off,struct.pack('<d',value))
        finally:self.executing=True
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api in [60,61,62,63,52,3]:self.snapshot()
        if api==60:
            index,ticket,ok=self.next(20)
            if m.reg_read(x.UC_X86_REG_RDX)!=ticket:raise ValueError('POSITION_SELECT_TICKET_DIFFERS')
            self.select_calls+=1;m.reg_write(x.UC_X86_REG_RAX,ok);self.change(20);return
        if api==61:
            prop,index,value=self.next(21)
            if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=prop:raise ValueError('POSITION_INTEGER_PROPERTY_DIFFERS')
            m.reg_write(x.UC_X86_REG_RAX,value&send.MASK);return
        if api==62:
            prop,index,value=self.next(22)
            if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=prop:raise ValueError('POSITION_DOUBLE_PROPERTY_DIFFERS')
            if prop==6:self.sl_calls+=1
            else:self.volume_calls+=1
            m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value);self.change(22);return
        if api==63:
            prop,index,null,symbol=self.next(23)
            if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=prop:raise ValueError('POSITION_STRING_PROPERTY_DIFFERS')
            self.shared(symbol)
            if null:m.mem_write(self.base+self.send_cfg['slot'],b'\0'*12)
            return
        if api==52:
            prop,index,null,symbol,value=self.next(24);self.string_argument((null,symbol))
            if m.reg_read(x.UC_X86_REG_R8)&0xffffffff!=prop:raise ValueError('CLOSE_PRICE_PROPERTY_DIFFERS')
            m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value);return
        if api==3:
            null,symbol=self.next(26);self.string_argument((null,symbol))
            prop,symbol,value=self.next(9)
            if m.reg_read(x.UC_X86_REG_R8)&0xffffffff!=prop or self.text(m.reg_read(x.UC_X86_REG_RDX))!=symbol:raise ValueError('FILLING_SYMBOL_ARGUMENT_DIFFERS')
            m.reg_write(x.UC_X86_REG_RAX,value&send.MASK);return
        if api in [41,42]:
            result=super().call(m,address,size,user);self.change(1);self.snapshot();return result
        if api==45 and m.reg_read(x.UC_X86_REG_RDX)==13 and m.reg_read(x.UC_X86_REG_R8)==2:self.snapshot()
        if api==46:
            value=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;kind=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
            if kind==0x52 and value==1:text=self.cast_strings[0]
            elif kind==0x53 and value in [0,1,self.row['send']['new_result']['retcode']]:
                text=self.cast_strings[1 if value==0 else 2 if value==1 else 3]
            else:raise ValueError('UNEXPECTED_CLOSE_NUMERIC_CAST')
            self.supply(m.reg_read(x.UC_X86_REG_R9),text);return
        return super().call(m,address,size,user)
    def run_close(self,row):
        self.executing=False;m,x=self.m,self.x;self.row=row;env=row['send'];self.case=env;self.cursor=0x70001000;self.allocs=self.frees=0;self.position=0;self.records=self.records_by_id[row['id']]
        self.close_calls=self.select_calls=self.sl_calls=self.volume_calls=self.actual_sends=self.format_failures=self.early_prints=self.print_count=self.print_hash=0;self.filling_entered=False
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        cfg=self.send_cfg;start=self.base+self.fill_cfg['request'];context=self.base+cfg['context'];m.mem_write(start,b'\x5a'*628);m.mem_write(self.base+cfg['slot'],b'\0'*12)
        self.populate('request',start,env['request'],bool(env['symbol_null']));self.populate('result',start+240,env['result']);self.populate('check',start+436,{f['name']:f['value'] for f in self.schemas['check']['fields']})
        m.mem_write(self.base+self.pending_cfg['magic'],struct.pack('<Q',row['magic']));m.mem_write(self.base+self.fill_cfg['preferred'],struct.pack('<i',row['preferred']));m.mem_write(self.base+self.pending_cfg['stopped'],struct.pack('<i',row['stopped']));m.mem_write(self.base+self.close['deviation'],struct.pack('<Q',row['deviation']))
        for off,value in zip(self.close['variables'],row['variables']):m.mem_write(self.base+off,struct.pack('<d',value))
        m.mem_write(context+660,bytes([env['async_mode']]));m.mem_write(context+681,struct.pack('<i',env['margin_mode']));m.mem_write(context+685,struct.pack('<i',env['log_level']));self.supply(self.base+cfg['chart'],self.chart);m.mem_write(self.base+cfg['digits'],struct.pack('<i',self.default_digits));self.cast_strings=self.next(17)
        old=bytes(m.mem_read(start,628));top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_RCX,row['ticket']);self.executing=True
        try:m.emu_start(self.base+self.close['functions'][row['mode']],0x60000000,timeout=5000000,count=4000000)
        finally:self.executing=False
        self.supply(self.base+cfg['slot'],'')
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000 or self.position!=len(self.records) or self.allocs!=self.frees:raise ValueError('CLOSE_EXECUTION_OR_MEMORY_NOT_COMPLETE')
        if self.filling_entered:
            for off,length in [(128,112),(312,124),(500,128)]:
                if bytes(m.mem_read(start+off,length))!=b'\0'*length:raise ValueError('CLOSE_RESERVED_STORAGE_NOT_CLEARED')
        else:
            expected=bytearray(old)
            if self.early_prints:expected[240:244]=struct.pack('<I',10027)
            if bytes(m.mem_read(start,628))!=expected:raise ValueError('EARLY_CLOSE_CHANGED_UNEXPECTED_STORAGE')
        return struct.pack('<i',row['id'])+self.state_record()+struct.pack('<6iQ',self.close_calls,self.actual_sends,self.format_failures,self.early_prints,self.position,self.print_count,self.print_hash)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('mode',choices=['prepare','mql5','original','compare']);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('run');parser.add_argument('--build');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    home=ROOT/f'bot-cua-toi-{a.bot}';out=home/'bang-chung/kiem-dong-vi-the'/a.run
    if a.mode=='prepare':
        digest=pending.fill.validation.original_hash(a.bot);rows=cases();out.mkdir(parents=True,exist_ok=False);(out/'cases.bin').write_bytes(encode(rows));descriptions=copy.deepcopy(rows)
        for row in descriptions:
            for key in ['sl','volumes','prices','variables']:row[key]=[struct.pack('<d',v).hex() for v in row[key]]
            row['send']=send.json_cases([row['send']])[0]
        save(out/'cases.json',descriptions);save(out/'baseline.json',dict(cases=len(rows),cases_sha256=sha(out/'cases.bin'),original_ex5_sha256=digest,tool_sha256=sha(Path(__file__))));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((out/'baseline.json').read_text());rows=read_cases(out/'cases.bin');n=len(rows)
    if baseline['cases_sha256']!=sha(out/'cases.bin') or baseline['original_ex5_sha256']!=pending.fill.validation.original_hash(a.bot) or baseline['tool_sha256']!=sha(Path(__file__)):raise ValueError('INPUT_OR_ORIGINAL_OR_TOOL_CHANGED')
    if a.mode=='mql5':
        if not a.build or not re.fullmatch('[a-z0-9-]+',a.build):raise ValueError('BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PositionCloseCheck.mq5';binary=MT/'MQL5'/target.replace('.mq5','.ex5')
        if receipt['target']!=target or receipt['errors']!=0 or receipt['warnings']!=0 or sha(binary)!=receipt['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
        names=[target,f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PipelineApi.mqh']+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PositionClose','TradeSend','TradeMessages','PendingRequest','Filling']]
        for name in names:
            if sha(home/'source/MQL5'/name)!=receipt['sources_sha256'][name] or sha(MT/'MQL5'/name)!=receipt['sources_sha256'][name]:raise ValueError('TESTED_SOURCE_CHANGED')
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-position-close'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b{a.bot}-close-{a.run}.set';preset.write_text(f'CheckRun={a.run}\n',encoding='utf-16');ini=MT/f'b{a.bot}-close-{a.run}.ini'
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PositionCloseCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');started=time.monotonic();process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MT5_CLOSE_TIMEOUT')
        if code:raise RuntimeError('MT5_CLOSE_FAILED '+str(code))
        for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']:shutil.copyfile(files/name,out/name)
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,n):raise ValueError('CLOSE_SCRIPT_INCOMPLETE')
        save(out/'mql5-run.json',dict(cases=n,exit_code=code,seconds=round(time.monotonic()-started,2),script_sha256=sha(binary),tool_sha256=sha(Path(__file__)),build_receipt=receipt_path.relative_to(ROOT).as_posix(),build_receipt_sha256=sha(receipt_path),sources_sha256={name:receipt['sources_sha256'][name] for name in names},hashes={name:sha(out/name) for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']}));print(json.dumps(dict(cases=n)));return
    if a.mode=='original':
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        records,chart,digits=fixtures(out/'api-fixtures.bin',n)
        for row in rows:validate_inputs(row,records[row['id']])
        o=Original(a.bot,records,chart,digits);started=time.monotonic();values=[]
        for row in rows:
            try:values.append(o.run_close(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,1,n)+b''.join(values));save(out/'original-run.json',dict(cases=n,seconds=round(time.monotonic()-started,2),result_sha256=sha(out/'original-results.bin'),fixture_sha256=sha(out/'api-fixtures.bin'),tool_sha256=sha(Path(__file__)),dependencies_sha256=dependencies(a.bot),input_contract_checked_cases=n,scope=__doc__));print(json.dumps(dict(cases=n)));return
    mql=json.loads((out/'mql5-run.json').read_text());native=json.loads((out/'original-run.json').read_text());receipt_path=ROOT/mql['build_receipt'];receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    if receipt['errors']!=0 or receipt['warnings']!=0 or sha(receipt_path)!=mql['build_receipt_sha256'] or receipt['binary_sha256']!=mql['script_sha256'] or sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name)!=mql['script_sha256'] or mql['tool_sha256']!=baseline['tool_sha256']:raise ValueError('BUILD_OR_TOOL_EVIDENCE_CHANGED')
    for name,digest in mql['sources_sha256'].items():
        if sha(home/'source/MQL5'/name)!=digest:raise ValueError('CURRENT_SOURCE_CHANGED')
    for name,digest in mql['hashes'].items():
        if sha(out/name)!=digest:raise ValueError('MQL_EVIDENCE_CHANGED')
    if sha(out/'original-results.bin')!=native['result_sha256'] or sha(out/'api-fixtures.bin')!=native['fixture_sha256'] or native['dependencies_sha256']!=dependencies(a.bot) or native['tool_sha256']!=baseline['tool_sha256'] or encode(cases())!=(out/'cases.bin').read_bytes():raise ValueError('NATIVE_OR_GENERATED_INPUT_CHANGED')
    records,chart,digits=fixtures(out/'api-fixtures.bin',n)
    for row in rows:validate_inputs(row,records[row['id']])
    expected=read_results(out/'original-results.bin',n);actual=read_results(out/'mql5-results.bin',n);failures=[]
    for i,(left,right) in enumerate(zip(expected,actual)):
        if left!=right:
            at=next((j for j,(x,y) in enumerate(zip(left,right)) if x!=y),min(len(left),len(right)));failures.append(dict(id=i,first_different_byte=at,original=left[at:at+20].hex(),mql5=right[at:at+20].hex()))
    result=dict(cases=n,matched=n-len(failures),failed=len(failures),first_failures=failures[:12],hashes={name:sha(out/name) for name in ['cases.bin','original-results.bin','mql5-results.bin','api-fixtures.bin','script-status.bin']},whole_bot_complete=False,scope=__doc__)
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))

if __name__=='__main__':main()
