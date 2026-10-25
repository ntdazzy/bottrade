"""Compare bot3 virtual-stop branches with original instructions and observed SDK replies.

Usage: kiem-bang-dung-ao-day-du-bot-1.py prepare|mql5|original|compare RUN [--build BUILD]
ArrayResize runs in MQL5; its exact before/after arrays are input-bound service
records for the native run. Other query replies are checked against case inputs.
Fatal cases are kept in the input inventory and run separately.
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

ROOT=Path(__file__).resolve().parents[2]
def module(name):
    spec=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/name)
    result=importlib.util.module_from_spec(spec);spec.loader.exec_module(result);return result
entry=module('kiem-gia-vao-bot-1-3.py')
validation=module('kiem-khoi-luong-hop-le-bot-1-3.py')
MT=ROOT.parent/'.local/mt5-bot3-thread-20261025'
ANALYSIS=ROOT/'bot-cua-toi-3/phan-tich/dong-vi-the/virtual-stops-20261025-r1'
MASK=(1<<64)-1;MAGIC=0x56534d33;VERSION=3
SOURCES=['Include/bot-cua-toi-3/Bot3VirtualStops.mqh','Include/bot-cua-toi-3/Bot3PriceLevels.mqh',
         'Scripts/bot-cua-toi-3/Bot3VirtualStopsCheck.mq5']
FN={0:0x20bc0,1:0x47f10,2:0x484c0,3:0x48560,4:0x482b0}
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def text(value):
    raw=value.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def require(ok,message):
    if not ok:raise ValueError(message)
def save(path,value):
    with path.open('x',encoding='utf-8') as stream:json.dump(value,stream,ensure_ascii=False,indent=2)
def base():
    return dict(id=0,group='',kind=1,fatal=0,guard=1,side=1,delay=99,digits=3,ticket=7001,warn=0,now=1099,
        price=bits(100.),distance=bits(10.),unit=bits(.1),symbol='CHECK',series=0,array=[],
        total=0,positions=[],fill=0,rows=[],take_fill=0,take_rows=[],warn_take=0,control_api=0,control_hit=1,control_kind=0,control_row=0,
        control_integer=0,control_values=[0,0,0],fail_resize=0)
def row(index,ticket,level=99.,stamp=1000.):
    return [index,bits(ticket),bits(level),bits(stamp)]
def cases():
    out=[]
    def add(group,**changes):
        c=base();c.update(changes);c.update(id=len(out),group=group);out.append(c);return c
    for guard in [0,1,2,255]:
        for kind in range(4):add('guard-byte',guard=guard,kind=kind,rows=[row(0,7001.)])
    for ticket in [0,-1,1,7001,(1<<53)-1,(1<<53)+1,-(1<<63),(1<<63)-1]:
        add('first-existing-ticket',ticket=ticket,rows=[row(499,float(ticket),123.25,0.)])
        add('duplicate-first-match',ticket=ticket,rows=[row(3,float(ticket),123.25),row(9,float(ticket),456.5)])
    values=[0.,-0.,1.005,-1.005,1e19,-1e19,float('inf'),-float('inf'),float('nan')]
    for side in [-2147483648,-1,0,1,2,3,2147483647]:
        add('side-int32',side=side)
    for side in [1,2]:
        for value in values:
            for field in ['price','distance','unit']:
                add('float-arguments',side=side,**{field:bits(value)})
    for digits in [-1,0,2,8,10,11,12,2147483647,(1<<32)+3,-(1<<63),(1<<63)-1]:
        add('digits-low32',digits=digits,price=bits(100.005),distance=bits(0.))
    for fill in [1,2,3]:
        add('no-free-row-cleanup',fill=fill)
    for fill in [0,1]:
        add('find-free-last',fill=fill,rows=[row(499,0.,333.,44.)])
    full_positions=[[i+1,i%2] for i in range(500)]
    add('full-table-warning',fill=1,total=500,positions=full_positions)
    add('full-table-warning-once',fill=1,total=500,positions=full_positions,warn=7001)
    add('disabled-table-warning',guard=2,warn=0)
    add('zero-guard-warning',guard=0,warn=0)
    add('warning-rereads-guard',guard=2,control_api=4,control_hit=2,control_kind=3,control_integer=0)
    add('digits-reread-unit',control_api=1,control_kind=1,control_values=[bits(.25),0,0])
    add('digits-enable-and-fill-row',guard=0,control_api=1,control_kind=7,control_integer=1,
        control_values=[bits(7001.),bits(1234.),bits(42.)])
    add('cleanup-rereads-guard',fill=1,total=0,control_api=4,control_kind=3,control_integer=0)
    for size in [0,1,63,64,65,128]:
        for series in [0,1]:
            add('array-initial-size',kind=0,array=[-1000-i for i in range(size)],series=series,
                rows=[row(0,1.),row(4,-1.),row(10,float('nan'))])
    positions=[[0,0],[1,0],[2,1],[3,2],[4,-1],[5,1<<32],[1<<63,0],[(1<<64)-1,1]]
    for total in [-1,0,1,len(positions),len(positions)+3]:
        for series in [0,1]:
            add('position-types-and-selection',kind=0,total=total,positions=positions,series=series,
                rows=[row(0,1.),row(1,2.),row(2,3.),row(3,float(1<<63)),row(4,float('inf')),row(5,-1.)])
    for count in [63,64,65,70]:
        for series in [0,1]:
            add('array-growth',kind=0,total=count,positions=[[i+1,i%2] for i in range(count)],
                series=series,array=[-i-1 for i in range(64)],
                rows=[row(0,1.),row(1,float(count)),row(2,1000.)])
    add('resize-fails-empty-account',kind=0,fail_resize=1,rows=[row(0,1.)])
    stamp_values=[0.,-0.,.5,-.5,1.,1000.,float('inf'),-float('inf'),float('nan')]
    for stamp in stamp_values:
        for now in [0,1098,1099,-(1<<63),(1<<63)-1]:
            add('delay-conversion-and-boundary',kind=2,now=now,rows=[row(499,7001.,99.,stamp)],control_row=499)
    for delay in [-2147483648,-1,0,1,99,2147483647]:
        add('delay-int32',kind=2,delay=delay,rows=[row(0,7001.,99.,1000.)])
    add('delay-rereads-setting',kind=2,rows=[row(0,7001.)],control_api=2,control_kind=2,control_integer=100)
    add('delay-caches-stamp',kind=2,rows=[row(0,7001.)],control_api=2,control_kind=4,
        control_values=[bits(7001.),bits(99.),bits(10000.)])
    add('delay-no-ticket',kind=2)
    for now in [0,-1,1000,(1<<53)+1,-(1<<63),(1<<63)-1]:
        add('stamp-int64-to-double',kind=3,now=now,rows=[row(499,7001.)],control_row=499)
    add('stamp-keeps-found-row',kind=3,rows=[row(4,7001.)],control_row=4,control_api=2,control_kind=4,
        control_values=[bits(123.),bits(88.),bits(99.)])
    add('stamp-no-ticket',kind=3)
    add('initial-resize-retry',kind=0,total=1,positions=[[1,0]],fail_resize=1)
    for series in [0,1]:
        add('old-tail-is-not-open',kind=0,total=1,positions=[[1,0]],series=series,
            array=[7777]*64,rows=[row(0,1.),row(1,7777.)])
    add('negative-zero-ticket-cache',ticket=0,rows=[row(0,-0.,123.456789,0.)])
    add('negative-zero-free-slot',fill=1,rows=[row(499,-0.,333.,44.)])
    add('cached-level-not-rounded',rows=[row(0,7001.,123.456789,0.)])
    for symbol in ['', 'Vàng_金']:
        add('symbol-forwarding',symbol=symbol)
    factor=10000000000.1;product=factor*factor
    add('separate-multiply-add',side=2,digits=11,price=bits(-product),distance=bits(factor),unit=bits(factor))
    add('separate-multiply-subtract',side=1,digits=11,price=bits(product),distance=bits(factor),unit=bits(factor))
    add('initial-resize-fatal',kind=0,fatal=1,total=1,positions=[[1,0]],fail_resize=-1)
    add('growth-resize-fatal',kind=0,fatal=1,total=65,positions=[[i+1,0] for i in range(65)],
        array=[0]*64,fail_resize=1)
    for guard in [0,1,2,255]:
        for value in [0.,-0.,-1.,1.,123.456789,float('nan'),float('inf'),-float('inf')]:
            add('take-level-guard-float',kind=4,guard=guard,price=bits(value))
    for ticket in [0,-1,1,7001,(1<<53)-1,(1<<53)+1,-(1<<63),(1<<63)-1]:
        add('take-cached-before-invalid-input',kind=4,ticket=ticket,price=bits(-1.),
            take_rows=[[499,bits(float(ticket)),bits(123.456789)]])
        add('take-duplicate-first-match',kind=4,ticket=ticket,
            take_rows=[[3,bits(float(ticket)),bits(12.5)],[9,bits(float(ticket)),bits(77.)]])
    for fill in [1,2,3]:
        add('take-full-cleanup',kind=4,take_fill=fill,fill=1,price=bits(123.456789))
    for kind in [0,1,4]:
        add('cleanup-both-tables',kind=kind,fill=1,take_fill=1,total=3,positions=[[1,0],[2,1],[3,2]])
    for series in [0,1]:
        add('cleanup-mixed-stop-take',kind=0,series=series,total=2,positions=[[1,0],[2,1]],
            rows=[row(0,1.),row(1,3.),row(499,float('nan'))],
            take_rows=[[0,bits(3.),bits(100.)],[1,bits(2.),bits(101.)],[499,bits(float('nan')),bits(99.)]])
        add('cleanup-take-long-conversion',kind=0,series=series,total=1,positions=[[1<<63,0]],
            take_rows=[[0,bits(float('inf')),bits(1.)],[1,bits(2.),bits(2.)],[2,bits(-1.),bits(3.)]])
    for value in [0.,-0.,float('nan'),float('inf'),-float('inf'),-1.]:
        add('take-ticket-special',kind=4,price=bits(99.),take_rows=[[0,bits(value),bits(123.)]])
    add('take-free-last',kind=4,price=bits(123.456789),take_fill=1,take_rows=[[499,bits(-0.),bits(333.)]])
    for warn in [0,7001]:
        add('take-full-warning-once',kind=4,price=bits(111.),take_fill=1,total=500,
            positions=full_positions,warn_take=warn)
    add('take-warning-rereads-guard',kind=4,guard=2,price=bits(111.),control_api=4,
        control_hit=2,control_kind=3,control_integer=0)
    add('take-cleanup-rereads-guard',kind=4,take_fill=1,price=bits(111.),control_api=4,
        control_kind=3,control_integer=0)
    add('take-cleanup-enables-table',kind=4,guard=0,price=bits(111.),control_api=4,
        control_kind=9,control_integer=1,control_values=[bits(999.),bits(888.),0])
    add('take-warning-ticket-after-total',kind=4,guard=0,price=bits(111.),control_api=4,
        control_hit=2,control_kind=10,control_integer=9000)
    return out
def encode(rows):
    data=bytearray(struct.pack('<4i',MAGIC,VERSION,len(rows),sum(not c['fatal'] for c in rows)))
    for c in rows:
        data+=struct.pack('<6i5q3Q',*(c[k] for k in ['id','kind','fatal','guard','side','delay']),
            *(c[k] for k in ['digits','ticket','warn','warn_take','now']),*(c[k] for k in ['price','distance','unit']))+text(c['symbol'])
        data+=struct.pack('<2i',c['series'],len(c['array']))+b''.join(struct.pack('<q',v) for v in c['array'])
        data+=struct.pack('<2i',c['total'],len(c['positions']))
        data+=b''.join(struct.pack('<Qq',*p) for p in c['positions'])
        data+=struct.pack('<2i',c['fill'],len(c['rows']))
        data+=b''.join(struct.pack('<i3Q',*r) for r in c['rows'])
        data+=struct.pack('<2i',c['take_fill'],len(c['take_rows']))
        data+=b''.join(struct.pack('<i2Q',*r) for r in c['take_rows'])
        data+=struct.pack('<4iq3Qi',*(c[k] for k in ['control_api','control_hit','control_kind','control_row']),
                          c['control_integer'],*c['control_values'],c['fail_resize'])
    return bytes(data)

class Reader:
    def __init__(self,raw):self.raw=raw;self.pos=0
    def take(self,fmt):
        size=struct.calcsize('<'+fmt);require(self.pos+size<=len(self.raw),'TRUNCATED_RECORD')
        values=struct.unpack_from('<'+fmt,self.raw,self.pos);self.pos+=size;return values
    def blob(self,size):
        require(0<=size<=len(self.raw)-self.pos,'TRUNCATED_BYTES')
        raw=self.raw[self.pos:self.pos+size];self.pos+=size;return raw
    def text(self):
        n=self.take('i')[0];require(0<=n<=2048,'INVALID_TEXT_LENGTH')
        return self.blob(n*2).decode('utf-16-le')
    def array(self):
        size,series=self.take('2i');require(0<=size<=4096 and series in [0,1],'INVALID_ARRAY')
        return size,series,self.blob(size*8)
    def snapshot(self,full=False):
        start=self.pos;self.take('iqqiQ');self.text();self.take('3i5Q')
        if full:self.blob(20000)
        return self.raw[start:self.pos]
    def eof(self):require(self.pos==len(self.raw),'TRAILING_BYTES')
def read_fixtures(path,rows,selected=None):
    rd=Reader(path.read_bytes());magic,version,count=rd.take('3i')
    selected=[c for c in rows if not c['fatal']] if selected is None else selected
    require((magic,version,count)==(MAGIC,VERSION,len(selected)),'FIXTURE_HEADER_DIFFERS')
    result={}
    for c in selected:
        id,n,full=rd.take('3i');require(id==c['id'] and 0<=n<=10000 and full==int(bool(c['fatal'])),'FIXTURE_CASE_DIFFERS');events=[]
        for _ in range(n):
            api=rd.take('i')[0];before=rd.snapshot(bool(full))
            if api==1:payload=(rd.take('i')[0],rd.text(),rd.take('q')[0])
            elif api==2:payload=rd.take('q')
            elif api==3:payload=(rd.take('2i'),rd.array(),rd.take('i')[0],rd.array())
            elif api==4:payload=rd.take('i')
            elif api==5:payload=(rd.take('i')[0],rd.take('Q')[0])
            elif api==6:payload=(rd.take('i')[0],rd.take('q')[0])
            elif api==7:payload=(rd.text(),rd.take('i')[0],rd.text(),rd.take('i')[0],rd.text(),rd.take('q')[0],rd.text())
            else:raise ValueError('UNKNOWN_API_RECORD '+str(api))
            events.append((api,before,payload,rd.snapshot(bool(full))))
        result[id]=events
    rd.eof();return result
def read_results(path,rows):
    rd=Reader(path.read_bytes());selected=[c for c in rows if not c['fatal']]
    require(rd.take('3i')==(MAGIC,VERSION,len(selected)),'RESULT_HEADER_DIFFERS');result={}
    for c in selected:
        start=rd.pos;id,kind,value=rd.take('iiQ')
        require((id,kind)==(c['id'],c['kind']),'RESULT_CASE_DIFFERS')
        rd.snapshot();rd.blob(20000);rd.array();result[id]=rd.raw[start:rd.pos]
    rd.eof();return result

class Original(entry.Original):
    def __init__(self,fixtures):
        super().__init__(3);self.fixtures=fixtures;self.full_snapshot=False
        self.ranges={};self.covered={};m=self.m
        analysis=json.loads((ANALYSIS/'analysis.json').read_text())
        require(analysis['original_ex5_sha256']==validation.original_hash(3),'ORIGINAL_EX5_DIFFERS')
        for fn in analysis['functions']:
            lo,hi=int(fn['rva'],16),int(fn['end_rva'],16)
            require(hashlib.sha256(bytes(m.mem_read(self.base+lo,hi-lo))).hexdigest()==fn['native_bytes_sha256'],'NATIVE_CODE_DIFFERS')
            self.ranges[lo]=(hi,{int(v['rva'],16) for v in fn['instructions']});self.covered[lo]=set()
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        targets={0x7c2970:1,0x7d1c40:2,0x7aa0e0:3,0x7d7da0:4,
                 0x7d7df0:5,0x7d7fc0:6,0x7b49f0:7,0x3959a0:8}
        prior=set(self.apis);self.apis.update({eb+rva:api for rva,api in targets.items()})
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
    def array(self):
        m=self.m;descriptor=self.base+0x1d6d10
        n=struct.unpack('<i',m.mem_read(descriptor+8,4))[0]
        series=int(bool(struct.unpack('<H',m.mem_read(descriptor+2,2))[0]&0x10))
        require(0<=n<=4096,'NATIVE_ARRAY_LENGTH_INVALID')
        pointer=struct.unpack('<Q',m.mem_read(descriptor+28,8))[0]
        return n,series,bytes(m.mem_read(pointer,n*8)) if n else b''
    def set_array(self,value):
        n,series,raw=value;descriptor=self.base+0x1d6d10
        self.m.mem_write(descriptor,struct.pack('<Q',0x800010055|(0x100000 if series else 0))+b'\0'*44)
        self.m.mem_write(descriptor+8,struct.pack('<I',n));self.m.mem_write(descriptor+28,struct.pack('<Q',0x71000000))
        if raw:self.m.mem_write(0x71000000,raw)
    def symbol(self,descriptor=None):
        descriptor=self.base+0x74958 if descriptor is None else descriptor
        pointer=struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]
        if not pointer:return ''
        n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(n<=2048,'NATIVE_TEXT_TOO_LONG')
        return bytes(self.m.mem_read(pointer,n*2)).decode('utf-16-le')
    def set_symbol(self,value):
        self.m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string(value)))
    def snapshot(self):
        m=self.m;n,series,_=self.array();c=self.case
        result=(struct.pack('<i',m.mem_read(self.base+0x73450,1)[0])+bytes(m.mem_read(self.base+0x73458,8))+
            bytes(m.mem_read(self.base+0x73460,8))+
            bytes(m.mem_read(self.base+0x6d518,4))+bytes(m.mem_read(self.base+0x73dd8,8))+text(self.symbol())+
            struct.pack('<3i',self.selected,n,series)+bytes(m.mem_read(self.base+0x6d680+c['control_row']*24,24))+
            bytes(m.mem_read(self.base+0x70560+c['control_row']*16,16)))
        return result+bytes(m.mem_read(self.base+0x6d680,12000))+bytes(m.mem_read(self.base+0x70560,8000)) if self.full_snapshot else result
    def control(self,api):
        c=self.case
        if api!=c['control_api'] or self.hits[api]!=c['control_hit']:return
        k=c['control_kind'];m=self.m
        if k==1:m.mem_write(self.base+0x73dd8,struct.pack('<Q',c['control_values'][0]))
        if k==2:m.mem_write(self.base+0x6d518,struct.pack('<i',c['control_integer']))
        if k in [3,7,9]:m.mem_write(self.base+0x73450,bytes([c['control_integer']&255]))
        if k in [4,7]:m.mem_write(self.base+0x6d680+c['control_row']*24,struct.pack('<3Q',*c['control_values']))
        if k==5:m.mem_write(self.base+0x73458,struct.pack('<q',c['control_integer']))
        if k in [8,9]:m.mem_write(self.base+0x70560+c['control_row']*16,struct.pack('<2Q',*c['control_values'][:2]))
        if k==10:m.mem_write(self.base+0x73460,struct.pack('<q',c['control_integer']))
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;c=self.case
        require(self.event<len(self.records),'EXTRA_NATIVE_API '+str(api))
        expected,before,payload,after=self.records[self.event];self.event+=1
        require(api==expected,'API_ORDER_DIFFERS '+str((api,expected)))
        require(self.snapshot()==before,'BEFORE_SERVICE_STATE_DIFFERS '+str((c['id'],api,self.event)))
        self.hits[api]+=1
        if api==1:
            prop,symbol,value=payload
            require(prop==m.reg_read(x.UC_X86_REG_R8)==17 and symbol==self.symbol(m.reg_read(x.UC_X86_REG_RDX)) and value==c['digits'],'DIGITS_INPUT_DIFFERS')
            m.reg_write(x.UC_X86_REG_RAX,value&MASK)
        elif api==2:
            require(m.reg_read(x.UC_X86_REG_RDX)==0 and payload==(c['now'],),'TIME_INPUT_DIFFERS')
            m.reg_write(x.UC_X86_REG_RAX,c['now']&MASK)
        elif api==3:
            (count,reserve),old,ret,new=payload
            require(m.reg_read(x.UC_X86_REG_RDX)==self.base+0x1d6d10 and (m.reg_read(x.UC_X86_REG_R8)&0xffffffff)==count and m.reg_read(x.UC_X86_REG_R9)==reserve==0,'RESIZE_ARGUMENTS_DIFFER')
            require(old==self.array(),'RESIZE_OLD_ARRAY_DIFFERS')
            if c['fail_resize']<0 or self.hits[3]==c['fail_resize']:require(ret==-1 and old==new,'FAILED_RESIZE_REPLY_DIFFERS')
            else:require(ret==count==new[0] and ret>=0,'SUCCESSFUL_RESIZE_REPLY_DIFFERS')
            self.set_array(new);m.reg_write(x.UC_X86_REG_RAX,ret&0xffffffff)
        elif api==4:
            require(payload==(c['total'],),'TOTAL_REPLY_DIFFERS');m.reg_write(x.UC_X86_REG_RAX,c['total']&0xffffffff)
        elif api==5:
            index,value=payload
            native=struct.unpack('<i',struct.pack('<I',m.reg_read(x.UC_X86_REG_RDX)&0xffffffff))[0]
            require(index==native,'TICKET_INDEX_DIFFERS')
            wanted=c['positions'][index][0] if 0<=index<len(c['positions']) else 0
            require(value==wanted,'TICKET_REPLY_DIFFERS')
            if value:self.selected=index
            m.reg_write(x.UC_X86_REG_RAX,value)
        elif api==6:
            prop,value=payload
            require(prop==m.reg_read(x.UC_X86_REG_RDX)==2,'POSITION_PROPERTY_DIFFERS')
            wanted=c['positions'][self.selected][1] if self.selected>=0 else 0
            require(value==wanted,'POSITION_TYPE_REPLY_DIFFERS');m.reg_write(x.UC_X86_REG_RAX,value&MASK)
        elif api==7:
            require(m.reg_read(x.UC_X86_REG_RDX)==2 and m.reg_read(x.UC_X86_REG_R8)==7,'PRINT_OPERATION_DIFFERS')
            sp=m.reg_read(x.UC_X86_REG_RSP)
            tags=[m.reg_read(x.UC_X86_REG_R9)&0xffffffff]+[struct.unpack('<I',m.mem_read(sp+0x30+16*i,4))[0] for i in range(6)]
            require(tags==[0x590008,0x520004,0x590008,0x520004,0x590008,0x550005,0x590008],'PRINT_TAGS_DIFFER')
            values=[struct.unpack('<Q',m.mem_read(sp+0x28+16*i,8))[0] for i in range(7)]
            actual=(self.symbol(values[0]),struct.unpack('<i',struct.pack('<I',values[1]&0xffffffff))[0],
                self.symbol(values[2]),struct.unpack('<i',struct.pack('<I',values[3]&0xffffffff))[0],
                self.symbol(values[4]),struct.unpack('<q',struct.pack('<Q',values[5]))[0],self.symbol(values[6]))
            require(actual==payload,'PRINT_ARGUMENTS_DIFFER '+str(actual))
        else:raise ValueError('UNEXPECTED_RUNTIME_FAULT_IN_NORMAL_CASE')
        self.control(api);require(self.snapshot()==after,'AFTER_SERVICE_STATE_DIFFERS '+str((c['id'],api,self.event)))
    def run_case(self,c):
        self.case=c;self.records=self.fixtures[c['id']];self.event=0;self.hits=[0]*9;self.selected=-1
        m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        table=bytearray(12000)
        for i in range(500):
            if c['fill'] in [1,3]:struct.pack_into('<3d',table,i*24,(i+1)*(1 if c['fill']==1 else -1),100.+i*.125,2000.+i)
            if c['fill']==2:struct.pack_into('<3Q',table,i*24,0x7ff8000000000001,bits(111.25),0)
        for i,a,b,d in c['rows']:struct.pack_into('<3Q',table,i*24,a,b,d)
        take=bytearray(8000)
        for i in range(500):
            if c['take_fill'] in [1,3]:struct.pack_into('<2d',take,i*16,(i+1)*(1 if c['take_fill']==1 else -1),300.+i*.25)
            if c['take_fill']==2:struct.pack_into('<2Q',take,i*16,0x7ff8000000000001,bits(111.25))
        for i,a,b in c['take_rows']:struct.pack_into('<2Q',take,i*16,a,b)
        m.mem_write(self.base+0x70560,bytes(take));m.mem_write(self.base+0x73460,struct.pack('<q',c['warn_take']))
        m.mem_write(self.base+0x6d680,bytes(table));m.mem_write(self.base+0x73450,bytes([c['guard']]))
        m.mem_write(self.base+0x73458,struct.pack('<q',c['warn']));m.mem_write(self.base+0x6d518,struct.pack('<i',c['delay']))
        m.mem_write(self.base+0x73dd8,struct.pack('<Q',c['unit']));self.cursor=0x70001000;self.set_symbol(c['symbol'])
        self.set_array((len(c['array']),c['series'],b''.join(struct.pack('<q',v) for v in c['array'])))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        if c['kind']==1:
            m.reg_write(x.UC_X86_REG_RCX,(0xdeadbeef<<32)|(c['side']&0xffffffff))
            m.reg_write(x.UC_X86_REG_XMM1,c['price']);m.reg_write(x.UC_X86_REG_XMM2,c['distance']);m.reg_write(x.UC_X86_REG_R9,c['ticket']&MASK)
        elif c['kind']==4:
            m.reg_write(x.UC_X86_REG_XMM0,c['price']);m.reg_write(x.UC_X86_REG_RDX,c['ticket']&MASK)
        else:m.reg_write(x.UC_X86_REG_RCX,c['ticket']&MASK)
        m.emu_start(self.base+FN[c['kind']],0x60000000,timeout=10000000,count=20000000)
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_DID_NOT_RETURN')
        require(self.event==len(self.records),'UNUSED_API_RECORDS')
        value=m.reg_read(x.UC_X86_REG_XMM0)&MASK if c['kind'] in [1,4] else m.reg_read(x.UC_X86_REG_RAX)&255 if c['kind']==2 else 0
        n,series,data=self.array()
        return struct.pack('<iiQ',c['id'],c['kind'],value)+self.snapshot()+bytes(m.mem_read(self.base+0x6d680,12000))+bytes(m.mem_read(self.base+0x70560,8000))+struct.pack('<2i',n,series)+data

def identity():
    home=ROOT/'bot-cua-toi-3/source/MQL5'
    return dict(original_ex5_sha256=validation.original_hash(3),tool_sha256=sha(Path(__file__)),
        sources_sha256={name:sha(home/name) for name in SOURCES},
        dependencies_sha256={name:sha(ROOT/'cong-cu'/name) for name in
            ['kiem-gia-vao-bot-1-3.py','kiem-muc-gia-bot-1-3.py','kiem-khoi-luong-hop-le-bot-1-3.py']},
        analysis_sha256=sha(ANALYSIS/'analysis.json'),api_contract_sha256=sha(ANALYSIS/'api-contract.json'))
def check_identity(record,current):
    for key,value in current.items():require(record.get(key)==value,'IDENTITY_CHANGED '+key)
def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mode',choices=['prepare','mql5','original','compare']);parser.add_argument('run')
    parser.add_argument('--build');args=parser.parse_args()
    require(bool(re.fullmatch('[a-z0-9-]{1,40}',args.run)),'INVALID_RUN')
    home=ROOT/'bot-cua-toi-3';folder=home/'bang-chung/kiem-bang-dung-ao'/args.run
    rows=cases();normal=[c for c in rows if not c['fatal']];current=identity();encoded=encode(rows)
    if args.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);tested=folder/'tested-sources';tested.mkdir()
        (folder/'cases.bin').write_bytes(encoded);save(folder/'cases.json',rows)
        for name in SOURCES:shutil.copyfile(home/'source/MQL5'/name,tested/Path(name).name)
        shutil.copyfile(Path(__file__),tested/'check-tool.py')
        for name in current['dependencies_sha256']:shutil.copyfile(ROOT/'cong-cu'/name,tested/name)
        save(folder/'baseline.json',dict(**current,cases=len(rows),normal_cases=len(normal),
            fatal_case_ids=[c['id'] for c in rows if c['fatal']],cases_sha256=sha(folder/'cases.bin')))
        print(json.dumps({'cases':len(rows),'normal':len(normal),'fatal':len(rows)-len(normal)}));return
    baseline=json.loads((folder/'baseline.json').read_text());check_identity(baseline,current)
    require((folder/'cases.bin').read_bytes()==encoded and baseline['cases_sha256']==sha(folder/'cases.bin'),'CASES_CHANGED')
    if args.mode=='mql5':
        require(bool(args.build and re.fullmatch('[a-z0-9-]{1,40}',args.build)),'BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/args.build/'bien-nhan.json'
        receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
        require(receipt['target']==SOURCES[2] and receipt['errors']==receipt['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():
            require(receipt['sources_sha256'][name]==digest==sha(MT/'MQL5'/name),'PRIVATE_OR_COMPILED_SOURCE_CHANGED')
        binary=MT/'MQL5'/Path(SOURCES[2]).with_suffix('.ex5')
        require(sha(binary)==receipt['binary_sha256']==sha(receipt_path.parent/binary.name),'BINARY_CHANGED')
        require(sha(MT/'metaeditor64.exe')==receipt['metaeditor_sha256'],'COMPILER_CHANGED')
        files=MT/'MQL5/Files/bot3-virtual-matrix'/args.run;files.mkdir(parents=True,exist_ok=False)
        shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b3-virtual-matrix-{args.run}.set';ini=MT/f'b3-virtual-matrix-{args.run}.ini'
        with preset.open('x',encoding='utf-16') as stream:stream.write(f'CheckRun={args.run}\nOnlyCase=-1\n')
        with ini.open('x',encoding='utf-16') as stream:stream.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3VirtualStopsCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        before=sha(MT/'terminal64.exe');started=time.monotonic()
        process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:
            process.terminate();process.wait(timeout=30);raise RuntimeError('MQL5_MATRIX_TIMEOUT')
        require(code==0 and struct.unpack('<2i',(files/'script-status.bin').read_bytes())==(0,len(normal)),'MQL5_MATRIX_DID_NOT_PASS')
        for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']:
            with (files/name).open('rb') as reader,(folder/name).open('xb') as writer:shutil.copyfileobj(reader,writer)
        read_results(folder/'mql5-results.bin',rows);read_fixtures(folder/'api-fixtures.bin',rows)
        after=sha(MT/'terminal64.exe');require(before==after,'TERMINAL_CHANGED_DURING_RUN')
        save(folder/'mql5-run.json',dict(**current,cases=len(normal),exit_code=code,seconds=round(time.monotonic()-started,2),
            build_receipt=args.build,build_receipt_sha256=sha(receipt_path),binary_sha256=sha(binary),
            terminal_sha256_before=before,terminal_sha256_after=after,
            hashes={name:sha(folder/name) for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']}))
        print(json.dumps({'cases':len(normal),'exit_code':code}));return
    mql=json.loads((folder/'mql5-run.json').read_text());check_identity(mql,current)
    for name,digest in mql['hashes'].items():require(sha(folder/name)==digest,'MQL_EVIDENCE_CHANGED '+name)
    if args.mode=='original':
        target=folder/'original-results.bin';require(not target.exists(),'ORIGINAL_OUTPUT_EXISTS')
        records=read_fixtures(folder/'api-fixtures.bin',rows);runner=Original(records)
        read_results(folder/'mql5-results.bin',rows);raw=bytearray(struct.pack('<3i',MAGIC,VERSION,len(normal)))
        try:
            for c in normal:raw+=runner.run_case(c)
        except Exception as error:
            save(folder/'original-failure.json',dict(case_id=c['id'],group=c['group'],error=str(error),
                fixture_sha256=sha(folder/'api-fixtures.bin'),tool_sha256=current['tool_sha256']))
            raise
        target.write_bytes(raw);coverage={hex(lo):{'executed':len(runner.covered[lo]),'instructions':len(all_)} for lo,(_,all_) in runner.ranges.items()}
        save(folder/'original-run.json',dict(**current,cases=len(normal),result_sha256=sha(target),
            fixture_sha256=sha(folder/'api-fixtures.bin'),coverage=coverage,input_contract_checked_cases=len(normal)))
        print(json.dumps({'cases':len(normal),'coverage':coverage}));return
    original=json.loads((folder/'original-run.json').read_text());check_identity(original,current)
    require(original['result_sha256']==sha(folder/'original-results.bin') and original['fixture_sha256']==sha(folder/'api-fixtures.bin'),'NATIVE_EVIDENCE_CHANGED')
    expected=read_results(folder/'original-results.bin',rows);actual=read_results(folder/'mql5-results.bin',rows)
    failed=[];groups={}
    for c in normal:
        id=c['id'];groups.setdefault(c['group'],dict(cases=0,matched=0));groups[c['group']]['cases']+=1
        if expected[id]==actual[id]:groups[c['group']]['matched']+=1;continue
        a,b=expected[id],actual[id];at=next((i for i,(x,y) in enumerate(zip(a,b)) if x!=y),min(len(a),len(b)))
        failed.append(dict(id=id,group=c['group'],first_byte=at,original=a[at:at+16].hex(),mql5=b[at:at+16].hex()))
    report=dict(cases=len(normal),matched=len(normal)-len(failed),failed=len(failed),first_failures=failed[:12],
        groups=groups,coverage=original['coverage'],hashes={name:sha(folder/name) for name in
            ['cases.bin','baseline.json','mql5-results.bin','api-fixtures.bin','original-results.bin','script-status.bin']},
        whole_bot_complete=False,scope='Five bot3 virtual-stop/take functions. Return bits, all2500 table doubles,guard,both warning tickets,delay,unit,symbol,selected-position model,full physical ticket array and exact typed SDK records compared. ArrayResize post-state measured in MQL5 and input-bound; query replies supplied. Fatal cases,actual account/LastError,all allocation outcomes,error locations,tester and whole EA remain unverified.')
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))

if __name__=='__main__':main()
