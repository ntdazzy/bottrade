"""Compare complete pending selectors through cancel/send and table cleanup.

Usage: kiem-chon-lenh-huy-bot-1-3.py prepare|mql5|original|compare BOT RUN [--build BUILD]
Native selectors and cancellation execute to return. Query/send replies are supplied
and bound to inputs; formatting is measured in MT5. No actual orders or full EA.
Compare 35 public fields, four full strings with null flags, all200 table doubles
and the ordered typed API records. Build and runner provenance must be explicit.
"""
import argparse
import copy
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

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x53454c31;RESULT_VERSION=2
spec=importlib.util.spec_from_file_location('cancel_check',Path(__file__).with_name('kiem-huy-lenh-cho-bot-1-3.py'))
cancel=importlib.util.module_from_spec(spec);spec.loader.exec_module(cancel)
send=cancel.send;pending=cancel.pending;sha=cancel.sha;save=cancel.save;MT=cancel.MT
CFG={1:dict(functions=[0x32110,0x325b0],table=0x65dd0,magic=0x6246c,ticket=0x677f8,symbol=0x67918),
     3:dict(functions=[0x3da90,0x3dd60],table=0x72e10,magic=0x6d564,ticket=0x74838,symbol=0x74958)}
MESSAGES=['Max number of pending buy orders reached... deleting highest buystop order!',
          'Max number of pending sell orders reached... deleting lowest sellstop order!']

def base(kind):
    guard=cancel.base();guard.pop('ticket');guard['select_ok']=0
    return dict(id=0,kind=kind,scenario=0,total=1,magic=42,symbol_null=0,selected=-1,prior_ticket=0xfedcba9876543210,symbol='XAUUSD',
                orders=[[11,42,4+kind,0,100.,100.,'XAUUSD']],results=[[float(i+1000),-i-.25] for i in range(100)],guard=guard,send=send.base())

def cases():
    rows=[]
    def add(row,group):
        row.update(id=len(rows),group=group);row['send']['id']=row['id'];rows.append(row)
    prices=[-math.inf,-1.,-0.,0.,cancel.from_bits(1),1.,9998.,math.nextafter(9999.,0.),9999.,math.nextafter(9999.,math.inf),10000.,math.inf,
            *[cancel.from_bits(v) for v in [0x7ff8000000000123,0xfff8000000000456,0x7ff0000000000789,0xfff0000000000abc]]]
    for kind in [0,1]:
        for total in [-2,-1,0,1,2,3,4]:
            row=base(kind);row.update(total=total,orders=[[11+i,42,4+kind,0,100.+i,100.+i,'XAUUSD'] for i in range(4)]);add(row,'inclusive-indices')
        for first in prices:
            for second in [first,-1.,0.,1.,9999.,math.inf,math.nan]:
                row=base(kind);row['total']=2;row['orders']=[[11,42,4+kind,0,50.,50.,'XAUUSD'],[12,42,4+kind,0,first,second,'XAUUSD']];add(row,'first-and-second-price')
        for values in [*itertools.permutations([1.,100.,5000.]),(100.,100.,100.),(100.,50.,100.),(50.,100.,50.)]:
            row=base(kind);row.update(total=3,orders=[[11+i,42,4+kind,0,p,p,'XAUUSD'] for i,p in enumerate(values)]);add(row,'order-and-ties')
        for magic in [-2147483648,-1,0,42,2147483647]:
            for actual in [magic,magic+(1<<32),-1,0,42]:
                row=base(kind);row['magic']=magic;row['orders'][0][1]=actual;add(row,'signed-magic-width')
        for actual in [-1,0,1,2,3,4,5,6,7,0x100000004,0x100000005,-0x8000000000000000,0x7fffffffffffffff]:
            row=base(kind);row['orders'][0][2]=actual;add(row,'full-width-order-type')
        symbols=[('',0),('',1),('XAUUSD',0),('xauusd',0),('Vàng.💰',0),('XAUUSD.long',0)]
        for symbol,null in symbols:
            for actual,actual_null in symbols:
                row=base(kind);row.update(symbol=symbol,symbol_null=null);row['orders'][0][3]=actual_null;row['orders'][0][-1]=actual;add(row,'nullable-symbols')
        for ticket in [0,1,11,(1<<53)-1,1<<53,(1<<53)+1,(1<<63)-1,1<<63,(1<<63)+1,(1<<64)-1]:
            for position in [-1,0,1,50,99,100]:
                row=base(kind);row['orders'][0][0]=ticket;signed=ticket if ticket<(1<<63) else ticket-(1<<64)
                if 0<=position<100:row['results'][position]=[float(signed),-0.]
                if position==100:
                    row['results'][0]=[float(signed),-7.5];row['results'][99]=[float(signed),math.nan]
                add(row,'signed-ticket-table-match')
        for value in [math.inf,-math.inf,math.nan,-0.,11.,math.nextafter(11.,0.),math.nextafter(11.,math.inf)]:
            row=base(kind);row['results'][0]=[value,math.nan];row['results'][99]=[11.,-0.];add(row,'table-equality-boundary')
        for scenario in [1,2,3,4]:
            row=base(kind);row.update(scenario=scenario,orders=[[11,42,4+kind,0,100.,100.,'XAUUSD'],[12,-1,4+kind,0,200.,200.,'Renamed']]);row['total']=2;add(row,'query-time-state-change')
        for null,phase,write,log in itertools.product([0,1],range(3),[0,1],[0,2]):
            row=base(kind);row['send'].update(symbol_null=null,write_result=write,log_level=log)
            for key in ['request','result','new_result']:row['send'][key]['comment']=''
            row['send']['request']['symbol']=''
            if phase==0:row['guard'].update(select_ok=1,point=1.,freeze=1,tick_ok=1,order_type=4,bid=100.,ask=102.,price=102.)
            elif phase==1:row['guard'].update(stopped=1)
            add(row,'null-versus-empty-state')
        for child in cancel.cases():
            row=base(kind);row['guard']=copy.deepcopy(child['guard']);row['guard'].pop('ticket');row['send']=copy.deepcopy(child['send']);row['results'][0]=[11.,-7.5];row['results'][99]=[11.,-.5]
            add(row,'full-cancel-'+child['group'])
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for row in rows:
        raw+=send.encode([row['send']])[12:]+b''.join(struct.pack('<'+kind,row['guard'][name]) for name,kind in cancel.FIELDS[1:])+send.pack_text(row['guard']['symbol'])
        raw+=struct.pack('<6iQ',*(row[k] for k in ['kind','scenario','total','magic','symbol_null','selected']),row['prior_ticket'])+send.pack_text(row['symbol'])+struct.pack('<i',len(row['orders']))
        for ticket,magic,kind,null,p1,p2,symbol in row['orders']:raw+=struct.pack('<Qqqi2d',ticket,magic,kind,null,p1,p2)+send.pack_text(symbol)
        raw+=b''.join(struct.pack('<2d',*values) for values in row['results'])
    return raw

def read_cases(path):
    rd=send.Reader(path.read_bytes())
    if rd.take('2i')!=(MAGIC,1):raise ValueError('BAD_SELECTION_HEADER')
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
        guard={name:rd.take(kind)[0] for name,kind in cancel.FIELDS[1:]};guard['symbol']=rd.text()
        row=dict(zip(['kind','scenario','total','magic','symbol_null','selected','prior_ticket'],rd.take('6iQ')));row.update(id=i,guard=guard,send=env,symbol=rd.text());count=rd.take('i')[0]
        if env['id']!=i or not 0<=count<=100 or row['kind'] not in [0,1] or not 0<=row['scenario']<=4:raise ValueError('BAD_SELECTION_CASE')
        row['orders']=[[*rd.take('Qqqi2d'),rd.text()] for _ in range(count)];row['results']=[list(rd.take('2d')) for _ in range(100)];rows.append(row)
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
        elif api==20:value=rd.take('i')
        elif api==21:value=rd.take('iQi')
        elif api==22:value=rd.take('iq')
        elif api==23:value=(*rd.take('2i'),rd.text())
        elif api==24:value=rd.take('2iQ')
        elif api==25:value=(rd.text(),)
        else:raise ValueError('UNKNOWN_SELECTION_FIXTURE '+str(api))
        records[cid].append((api,value))
    if rd.pos!=len(rd.raw):raise ValueError('FIXTURE_BYTES_NOT_EXACT')
    return records,chart,digits

def validate_inputs(row,records):
    selected=row['selected'];price_reads=[0]*len(row['orders']);index=row['total'];totals=0;cancel_calls=0;prints=0;old=[]
    for api,value in records:
        if api==20:
            if totals or value!=(row['total'],):raise ValueError('TOTAL_INPUT_DIFFERS')
            totals+=1
        elif api==21:
            actual,ticket,after=value;expected=row['orders'][actual][0] if 0<=actual<len(row['orders']) else 0
            if not totals or actual!=index or index<0 or ticket!=expected:raise ValueError('TICKET_INPUT_DIFFERS')
            index-=1
            if ticket:selected=actual
            if after!=selected:raise ValueError('SELECTION_STATE_INPUT_DIFFERS')
        elif api in [22,23,24]:
            if cancel_calls or not 0<=selected<len(row['orders']):raise ValueError('INVALID_SELECTION_QUERY')
            order=row['orders'][selected]
            if api==22:
                prop,actual=value
                if prop not in [15,4] or actual!=order[1 if prop==15 else 2]:raise ValueError('INTEGER_INPUT_DIFFERS')
            elif api==23:
                if value!=(0,order[3],order[6]):raise ValueError('SYMBOL_INPUT_DIFFERS')
            else:
                prop,count,actual=value;read=price_reads[selected]
                if prop!=9 or count!=read or read>=2 or actual!=cancel.bits(order[4+read]):raise ValueError('PRICE_INPUT_DIFFERS')
                price_reads[selected]+=1
        elif api==25:
            if value!=(MESSAGES[row['kind']],) or not cancel_calls or prints:raise ValueError('SELECTOR_MESSAGE_DIFFERS')
            prints+=1
        elif api==10:
            ticket,ok=value;cancel_calls+=1
            if cancel_calls!=1 or not ticket or ticket not in [o[0] for o in row['orders']] or ok!=int(row['guard']['select_ok']!=0):raise ValueError('CANCEL_SELECTION_INPUT_DIFFERS')
        else:
            if api==17 and value!=('8','0','0',str(row['send']['new_result']['retcode'])):raise ValueError('CAST_METADATA_DIFFERS')
            old.append((api,value))
    if totals!=1 or index>=0 or prints!=cancel_calls:raise ValueError('SELECTION_TRACE_INCOMPLETE')
    cancel.validate_inputs(dict(guard={**row['guard'],'ticket':0},send=row['send']),old)

def read_results(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,RESULT_VERSION,n):raise ValueError('RESULT_HEADER_DIFFERS')
    rows=[]
    for i in range(n):
        start=rd.pos
        if rd.take('i')[0]!=i:raise ValueError('RESULT_ID_DIFFERS')
        rd.block(260)
        for _ in range(4):rd.text()
        rd.take('4i');rd.take('Q3i');rd.text();rd.take('5iQ2iQ');rd.block(1600);rows.append(rd.raw[start:rd.pos])
    if rd.pos!=len(rd.raw):raise ValueError('RESULT_BYTES_NOT_EXACT')
    return rows

def dependencies(bot):
    result=cancel.dependencies(bot)
    for path in [Path(__file__),ROOT/f'bot-cua-toi-{bot}/phan-tich/huy-lenh-cho/selection-20261024-r1/analysis.json',ROOT/f'bot-cua-toi-{bot}/phan-tich/huy-lenh-cho/selection-20261024-r1/native.txt']:
        result[path.relative_to(ROOT).as_posix()]=sha(path)
    return result

class Original(cancel.Original):
    def __init__(self,bot,records,chart,digits):
        super().__init__(bot,records,chart,digits);self.scan=CFG[bot]
        analysis=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich/huy-lenh-cho/selection-20261024-r1/analysis.json').read_text())
        for fn in analysis['functions']:
            begin=int(fn['rva'],16);end=int(fn['end_rva'],16);self.ranges.append((begin,end))
            import hashlib
            if hashlib.sha256(bytes(self.m.mem_read(self.base+begin,end-begin))).hexdigest()!=fn['native_bytes_sha256']:raise ValueError('SELECTOR_NATIVE_BYTES_CHANGED')
    def write_guard(self,m,access,address,size,value,user):
        if self.executing:
            for begin,length in [(self.base+self.scan['table'],1600),(self.base+self.scan['ticket'],8)]:
                if begin<=address and address+size<=begin+length:return
        return super().write_guard(m,access,address,size,value,user)
    def state_record(self):
        start=self.base+self.fill_cfg['request']
        nulls=[int(struct.unpack('<Q',self.m.mem_read(start+offset+4,8))[0]==0) for offset in [20,100,292,488]]
        return super().state_record()+struct.pack('<4i',*nulls)
    def change(self,api,ticket=0):
        row=self.selection;m=self.m;cfg=self.scan;self.executing=False
        try:
            if api==21 and self.ticket_calls==1 and row['scenario']==1:
                m.mem_write(self.base+cfg['magic'],struct.pack('<i',-1));self.supply(self.base+cfg['symbol'],'Renamed')
            if api==22 and self.integer_calls==1 and row['scenario']==2:m.mem_write(self.base+cfg['magic'],struct.pack('<i',43))
            if api==23 and self.string_calls==1 and row['scenario']==3:self.supply(self.base+cfg['symbol'],'Renamed')
            if api==10 and row['scenario']==4:
                signed=ticket if ticket<(1<<63) else ticket-(1<<64);m.mem_write(self.base+cfg['ticket'],struct.pack('<Q',0xdeadbeef12345678));m.mem_write(self.base+cfg['table'],struct.pack('<2d',float(signed),-7.5))
        finally:self.executing=True
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api==4:
            total,=self.next(20);m.reg_write(x.UC_X86_REG_RAX,total&send.MASK);return
        if api==5:
            index,ticket,selected=self.next(21)
            if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=index&0xffffffff:raise ValueError('TICKET_INDEX_DIFFERS')
            self.selected=selected;m.reg_write(x.UC_X86_REG_RAX,ticket);self.ticket_calls+=1;self.change(21);return
        if api in [6,7,8] and not self.cancelling:
            record=self.next({6:22,7:23,8:24}[api]);prop=record[0]
            if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=prop:raise ValueError('SELECTOR_PROPERTY_DIFFERS')
            if api==6:
                m.reg_write(x.UC_X86_REG_RAX,record[1]&send.MASK);self.integer_calls+=1;self.change(22)
            elif api==7:
                self.shared(record[2])
                if record[1]:m.mem_write(self.base+self.send_cfg['slot'],b'\0'*12)
                self.string_calls+=1;self.change(23)
            else:m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',record[2]));m.reg_write(x.UC_X86_REG_XMM0,record[2])
            return
        if api==51:
            self.cancelling=True;self.cancel_calls+=1;ticket=m.reg_read(x.UC_X86_REG_RDX);result=super().call(m,address,size,user)
            if self.selection['guard']['select_ok']:
                self.selected=next(i for i,o in enumerate(self.selection['orders']) if o[0]==ticket)
            self.change(10,ticket);return result
        if api==45 and m.reg_read(x.UC_X86_REG_RDX)==2:
            expected,=self.next(25);sp=m.reg_read(x.UC_X86_REG_RSP)
            if m.reg_read(x.UC_X86_REG_R8)!=1 or m.reg_read(x.UC_X86_REG_R9)!=0x590008:raise ValueError('SELECTOR_PRINT_SHAPE_DIFFERS')
            actual=self.text(struct.unpack('<Q',m.mem_read(sp+40,8))[0])
            if actual!=expected:raise ValueError('SELECTOR_PRINT_ARGUMENT_DIFFERS')
            self.selector_prints+=1;self.selector_hash=send.text_hash(actual);return
        return super().call(m,address,size,user)
    def run_selection(self,row):
        self.executing=False;m,x=self.m,self.x;self.selection=row;env=row['send'];guard=row['guard'];self.case=dict(env);self.case.update(request={'action':8,'type':0},result={'retcode':0})
        self.cursor=0x70001000;self.allocs=self.frees=0;self.position=0;self.records=self.records_by_id[row['id']];self.print_count=self.print_hash=self.actual_sends=self.format_failures=self.early_prints=0
        self.cancelling=False;self.ticket_calls=self.integer_calls=self.string_calls=self.cancel_calls=self.selector_prints=self.selector_hash=0;self.selected=row['selected']
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        cfg=self.send_cfg;start=self.base+self.fill_cfg['request'];context=self.base+cfg['context'];scan=self.scan
        m.mem_write(start,b'\x5a'*628);m.mem_write(self.base+cfg['slot'],b'\0'*12);self.populate('request',start,env['request'],bool(env['symbol_null']));self.populate('result',start+240,env['result']);self.populate('check',start+436,{f['name']:f['value'] for f in self.schemas['check']['fields']})
        m.mem_write(self.base+self.pending_cfg['magic'],struct.pack('<Q',guard['magic']));m.mem_write(self.base+self.fill_cfg['preferred'],struct.pack('<i',guard['preferred']));m.mem_write(self.base+self.pending_cfg['stopped'],struct.pack('<i',guard['stopped']))
        m.mem_write(context+660,bytes([env['async_mode']]));m.mem_write(context+681,struct.pack('<i',env['margin_mode']));m.mem_write(context+685,struct.pack('<i',env['log_level']));self.supply(self.base+cfg['chart'],self.chart);m.mem_write(self.base+cfg['digits'],struct.pack('<i',self.default_digits));self.casts[row['id']]=self.next(17)
        m.mem_write(self.base+scan['magic'],struct.pack('<i',row['magic']));m.mem_write(self.base+scan['ticket'],struct.pack('<Q',row['prior_ticket']));self.supply(self.base+scan['symbol'],row['symbol'])
        if row['symbol_null']:m.mem_write(self.base+scan['symbol'],b'\0'*12)
        m.mem_write(self.base+scan['table'],b''.join(struct.pack('<2d',*v) for v in row['results']));old=bytes(m.mem_read(start,628))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);self.executing=True
        try:m.emu_start(self.base+scan['functions'][row['kind']],0x60000000,timeout=5000000,count=4000000)
        finally:self.executing=False
        self.supply(self.base+cfg['slot'],'')
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000 or self.position!=len(self.records) or self.allocs!=self.frees:raise ValueError('SELECTION_EXECUTION_OR_MEMORY_NOT_COMPLETE')
        if not self.actual_sends:
            expected=bytearray(old)
            if self.early_prints:expected[240:244]=struct.pack('<I',10027)
            if bytes(m.mem_read(start,628))!=bytes(expected):raise ValueError('EARLY_CANCEL_CHANGED_UNEXPECTED_STORAGE')
        else:
            for offset,length in [(128,112),(312,124),(500,128)]:
                if bytes(m.mem_read(start+offset,length))!=b'\0'*length:raise ValueError('CANCEL_RESERVED_STORAGE_NOT_CLEARED')
        last,=struct.unpack('<Q',m.mem_read(self.base+scan['ticket'],8));magic,=struct.unpack('<i',m.mem_read(self.base+scan['magic'],4));ptr,=struct.unpack('<Q',m.mem_read(self.base+scan['symbol']+4,8))
        return struct.pack('<i',row['id'])+self.state_record()+struct.pack('<Q3i',last,self.selected,magic,int(ptr==0))+send.pack_text(self.text(self.base+scan['symbol']))+struct.pack('<5iQ2iQ',self.actual_sends,self.format_failures,self.early_prints,self.position,self.print_count,self.print_hash,self.cancel_calls,self.selector_prints,self.selector_hash)+bytes(m.mem_read(self.base+scan['table'],1600))

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('mode',choices=['prepare','mql5','original','compare']);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('run');parser.add_argument('--build');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    home=ROOT/f'bot-cua-toi-{a.bot}';out=home/'bang-chung/kiem-chon-lenh-huy'/a.run
    if a.mode=='prepare':
        digest=pending.fill.validation.original_hash(a.bot);rows=cases();out.mkdir(parents=True,exist_ok=False);(out/'cases.bin').write_bytes(encode(rows));descriptions=copy.deepcopy(rows)
        for row in descriptions:
            for name in ['point','bid','ask','price']:row['guard'][name]=struct.pack('<d',row['guard'][name]).hex()
            row['send']=send.json_cases([row['send']])[0];row['results']=[[struct.pack('<d',v).hex() for v in pair] for pair in row['results']]
            for order in row['orders']:
                order[4]=struct.pack('<d',order[4]).hex();order[5]=struct.pack('<d',order[5]).hex()
        save(out/'cases.json',descriptions);save(out/'baseline.json',dict(cases=len(rows),cases_sha256=sha(out/'cases.bin'),original_ex5_sha256=digest,tool_sha256=sha(Path(__file__))));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((out/'baseline.json').read_text());rows=read_cases(out/'cases.bin');n=len(rows)
    if baseline['cases_sha256']!=sha(out/'cases.bin') or baseline['original_ex5_sha256']!=pending.fill.validation.original_hash(a.bot):raise ValueError('INPUT_OR_ORIGINAL_CHANGED')
    if baseline['tool_sha256']!=sha(Path(__file__)):raise ValueError('CHECK_TOOL_CHANGED')
    if a.mode=='mql5':
        if not a.build or not re.fullmatch('[a-z0-9-]+',a.build):raise ValueError('BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PendingSelectionCheck.mq5';binary=MT/'MQL5'/target.replace('.mq5','.ex5')
        if receipt['target']!=target or receipt['errors']!=0 or receipt['warnings']!=0 or sha(binary)!=receipt['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
        names=[target,f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PipelineApi.mqh']+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PendingSelection','OrderCancel','TradeSend','TradeMessages','PendingRequest','Filling']]
        for name in names:
            if sha(home/'source/MQL5'/name)!=receipt['sources_sha256'][name] or sha(MT/'MQL5'/name)!=receipt['sources_sha256'][name]:raise ValueError('TESTED_SOURCE_CHANGED')
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-pending-selection'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b{a.bot}-selection-{a.run}.set';preset.write_text(f'CheckRun={a.run}\n',encoding='utf-16');ini=MT/f'b{a.bot}-selection-{a.run}.ini'
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PendingSelectionCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');started=time.monotonic();process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MT5_SELECTION_TIMEOUT')
        if code:raise RuntimeError('MT5_SELECTION_FAILED '+str(code))
        for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']:shutil.copyfile(files/name,out/name)
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,n):raise ValueError('SELECTION_SCRIPT_INCOMPLETE')
        save(out/'mql5-run.json',dict(cases=n,exit_code=code,seconds=round(time.monotonic()-started,2),script_sha256=sha(binary),tool_sha256=sha(Path(__file__)),build_receipt=receipt_path.relative_to(ROOT).as_posix(),build_receipt_sha256=sha(receipt_path),sources_sha256={name:receipt['sources_sha256'][name] for name in names},hashes={name:sha(out/name) for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']}));print(json.dumps(dict(cases=n)));return
    if a.mode=='original':
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        records,chart,digits=fixtures(out/'api-fixtures.bin',n)
        for row in rows:validate_inputs(row,records[row['id']])
        o=Original(a.bot,records,chart,digits);started=time.monotonic();values=[]
        for row in rows:
            try:values.append(o.run_selection(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,RESULT_VERSION,n)+b''.join(values));save(out/'original-run.json',dict(cases=n,seconds=round(time.monotonic()-started,2),result_sha256=sha(out/'original-results.bin'),fixture_sha256=sha(out/'api-fixtures.bin'),tool_sha256=sha(Path(__file__)),dependencies_sha256=dependencies(a.bot),input_contract_checked_cases=n,scope=__doc__));print(json.dumps(dict(cases=n)));return
    mql=json.loads((out/'mql5-run.json').read_text());native=json.loads((out/'original-run.json').read_text());receipt_path=ROOT/mql['build_receipt'];receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    if receipt['errors']!=0 or receipt['warnings']!=0 or sha(receipt_path)!=mql['build_receipt_sha256'] or receipt['binary_sha256']!=mql['script_sha256'] or sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name)!=mql['script_sha256']:raise ValueError('BUILD_EVIDENCE_CHANGED')
    if mql['tool_sha256']!=baseline['tool_sha256']:raise ValueError('MQL_CHECK_TOOL_CHANGED')
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
