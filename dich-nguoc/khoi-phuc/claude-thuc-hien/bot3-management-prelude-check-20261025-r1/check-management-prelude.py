"""Run the bot3 management prefix to its documented native boundary; compare with MQL5.

python -I -B -X utf8 .../check-management-prelude.py prepare|original|mql5|compare RUN [--build BUILD]
Order: prepare -> bien-dich.ps1 Bot3ManagementPreludeCheck.mq5 -> mql5 --build -> original -> compare.
Original 0x32f60/0x37590 instructions execute unchanged with supplied terminal replies; only the
separately verified children 0x32a90 (modify) and 0x47d20 (try-close) are intercepted at their
call boundary. One position: read/filter, initial levels and all three candle groups, both sides.
This is a prefix comparison, not the outer loop, later management branches or the full EA.
"""
import argparse
import copy
import hashlib
import importlib.util
import itertools
import json
import math
from pathlib import Path
import random
import re
import shutil
import struct
import subprocess
import time

HOME=Path(__file__).resolve().parents[1]
ROOT=HOME.parent
MT=ROOT.parent/'.local/mt5-bot3-thread-20261025'
MAGIC=0x4d505233
MASK=(1<<64)-1
CODE_BASE=0x17156250000
ANALYSIS=HOME/'phan-tich/dong-vi-the/management-20261025-r1'
CONTRACT=HOME/'phan-tich/dong-vi-the/management-prelude-20261025-r2'
NAMES=['Include/bot-cua-toi-3/'+s for s in ['Bot3ManagementPrelude.mqh','Bot3PriceLevels.mqh','Bot3PositionModify.mqh','Bot3PositionClose.mqh',
       'Bot3TradeSend.mqh','Bot3TradeMessages.mqh','Bot3PendingRequest.mqh','Bot3Filling.mqh']]+['Scripts/bot-cua-toi-3/Bot3ManagementPreludeCheck.mq5']
HELPERS=['kiem-gia-vao-bot-1-3.py','kiem-muc-gia-bot-1-3.py','kiem-khoi-luong-hop-le-bot-1-3.py','kiem-khoi-luong-bot-1-3.py']
CASE=struct.Struct('<3iQ2q2i5i7d3i2dq6q7i9d')
RESULT=struct.Struct('<iiQi5Q3q2Q2i2QiQ')
FIELDS=['id','accepted','last_ticket','present','sl','tp','ticket_number','open','volume','opened','type','magic',
        'comment_hash','symbol_hash','comment_null','symbol_null','bid','ask','calls','ordered_hash']
SCOPE=dict(prefix_only=True,whole_manager_complete=False,whole_bot_complete=False)
LIMITS=['Native stops at the documented one-position prefix boundary; the outer loop and later management branches are not executed.',
        'Terminal replies are supplied; children 0x32a90/0x47d20 are intercepted at the call boundary and were verified separately.',
        'Try-close deviation, bid/ask and thresholds are checked only on the MQL5 side; native 0x47d20 reads them from globals.',
        'No real trades, full EA, allocation-failure or restart proof.']
# Engine RVAs of the shared captured engine (same as the bot1 prefix check); bot3 data from the r2 contract.
TARGETS={0x7c2970:1,0x7d7df0:2,0x7d7f70:3,0x7d7fc0:4,0x7d8010:5,0x7c2c10:6,0x7b49f0:7,0x7d3b50:10,0x7d3d40:11,0x7d3bc0:12,0x7d7da0:13}
CHILDREN={0x32a90:8,0x47d20:9}
SIDES={1:dict(function=0x32f60,accepted=0x33b73,rejected={0x330a0,0x330a3,0x330ca},symbol=0x80),
       0:dict(function=0x37590,accepted=0x38194,rejected={0x376d0,0x376d3,0x376f7},symbol=0x58)}
G=dict(magic=0x6d564,enabled=0x6d520,stop=0x6d588,take=0x6d590,unit=0x73dd8,flags=[0x6d29e,0x6d2a0,0x6d2a2],
       frames=[0x6d29d,0x6d29f,0x6d2a1],shift=0x6d29c,symbol=0x74958,ticket=0x74838,tick=0x74790,double=0x1d6e48,string=0x1d6e3c)
DOUBLES={6:'sl',7:'tp',4:'open',3:'volume'};INTEGERS={1:'opened',2:'type',12:'magic'}
STRINGS={0:('position_symbol','position_null'),11:('comment','comment_null')}
GPRS=['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']
spec=importlib.util.spec_from_file_location('entry_prelude3',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py')
entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
spec=importlib.util.spec_from_file_location('validate_prelude3',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py')
validation=importlib.util.module_from_spec(spec);spec.loader.exec_module(validation)

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def require(ok,message):
    if not ok:raise ValueError(message)
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2)
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def from_bits(value):return struct.unpack('<d',struct.pack('<Q',value))[0]
def zero(value):return type(value) is int and value==0
def identity():
    return dict(original_ex5_sha256=validation.original_hash(3),tool_sha256=sha(Path(__file__)),analysis_sha256=sha(ANALYSIS/'analysis.json'),
                contract_sha256=sha(CONTRACT/'contract.md'),boundaries_sha256=sha(CONTRACT/'native-boundaries.json'),
                helpers_sha256={n:sha(ROOT/'cong-cu'/n) for n in HELPERS},sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES})
def check(record,current,stage):
    for key,value in current.items():require(record.get(key)==value,f'{stage}_IDENTITY_CHANGED {key}')

NAN_A,NAN_B,NAN_C=(from_bits(v) for v in [0x7ff8000000000123,0xfff8000000000456,0x7ff8000000000789])
NUMBERS=[-math.inf,-1e19,-100.005,-0.,0.,1.005,1e19,math.inf,NAN_A]
TICKETS=[0,1,(1<<53)+1,(1<<63)-1,1<<63,MASK]
LEVELS={1:dict(type=0,sl=95.,tp=110.),0:dict(type=1,sl=105.,tp=90.)}
OUTCOMES=['off','prev','cur','body','level','close']
SYMBOLS=[('CHECK','CHECK',0,0),('CHECK','OTHER',0,0),('CHECK','check',0,0),('CHECK','CHECK ',0,0),('CHECKX','CHECK',0,0),
         ('','',0,0),('','',1,0),('','',0,1),('','',1,1),('CHECK','',0,1),('','CHECK',1,0),('Vàng.💰','Vàng.💰',0,0),('Vàng.💰','Vang.💰',0,0)]

def candles(buy,outcomes):
    # Replies are consumed in call order by the enabled groups. With opened=1000 and open
    # price 100 each outcome stops at one contract step: prev, cur, body, level or close.
    times,closes,opens=[],[],[]
    for g,outcome in enumerate(outcomes):
        if outcome=='off':continue
        times.append(1001+g if outcome=='prev' else 900+g)
        if outcome=='prev':continue
        times.append(1000-g if outcome=='cur' else 1100+g)
        if outcome=='cur':continue
        open_=95.+g if buy else 105.-g
        closes.append((open_+1. if buy else open_-1.) if outcome=='body' else (90.+g if buy else 110.-g));opens.append(open_)
        if outcome=='body':continue
        closes.append((101.+g if outcome=='level' else 91.+g) if buy else (99.-g if outcome=='level' else 109.-g))
    return dict(candle_on=[int(o!='off') for o in outcomes],times=times+[7777]*(6-len(times)),
                closes=closes+[777.]*(6-len(closes)),opens=opens+[778.]*(3-len(opens)))
def base(buy):
    side=LEVELS[buy]
    return dict(id=0,group='',buy=buy,scenario=0,ticket=7,type=side['type'],magic=9001,expected_magic=9001,enabled=1,
                digits=[3]*5,sl=side['sl'],tp=side['tp'],open=100.,volume=.1,unit=.1,stop=10.,take=20.,tick_ok=1,bid=99.,ask=101.,
                opened=1000,timeframes=[15,1,1],shift=1,symbol='CHECK',symbol_null=0,position_symbol='CHECK',position_null=0,
                comment='note',comment_null=0)
def cases():
    out=[];rng=random.Random(20261025)
    def add(row,group):row.update(id=len(out),group=group);out.append(row)
    for buy in [0,1]:
        side=LEVELS[buy];closing=['close']*3
        def make(outcomes=('off','off','off'),**changes):
            c=base(buy);c.update(candles(buy,list(outcomes)));c.update(changes);return c
        for sl,tp,ticket in itertools.product([0.,side['sl']],[0.,side['tp']],TICKETS):
            add(make(['close','off','off'],sl=sl,tp=tp,ticket=ticket),'initial-levels-ticket64')
        for value in [-1,0,1,2,1<<32,(1<<32)+1,-(1<<32)]:add(make(closing,type=value),'filter-type-low32')
        for expected,magic in [(9001,9001),(9001,9002),(9001,9001+(1<<32)),(9001,9001-(1<<32)),(9001,9001+(1<<31)),(9001,-9001),
                               (-1,(1<<32)-1),(-1,-1),(-2147483648,1<<31),(0,1<<32),(0,1)]:
            add(make(closing,expected_magic=expected,magic=magic),'filter-magic-low32')
        for value in [-2147483648,-1,0,1,2,2147483647]:add(make(closing,enabled=value),'filter-enabled')
        for a,b,an,bn in SYMBOLS:add(make(closing,symbol=a,position_symbol=b,symbol_null=an,position_null=bn),'symbol-null-and-unicode')
        for text,null in [('',0),('',1),('Ghi chú vàng 💰',0),('x'*300,0)]:add(make(comment=text,comment_null=null),'comment-null-and-unicode')
        for field in ['sl','tp','open','unit','stop','take']:
            for value in NUMBERS:
                c=make(['close','off','off'],sl=0.,tp=0.);c[field]=value;add(c,'numeric-'+field)
        for value in [NAN_A,-0.,math.inf]:add(make(volume=value),'numeric-volume')
        # Two or three NaN payloads expose the operand order of each formula.
        for fields in [('open','stop'),('open','take'),('stop','unit'),('take','unit'),('open','stop','unit'),('open','take','unit')]:
            c=make(sl=0.,tp=0.);c.update(zip(fields,[NAN_A,NAN_B,NAN_C]));add(c,'nan-payload-operand-order')
        fraction=dict(open=100.123456789,unit=.0123456789,stop=10.987654321,take=20.123456789)
        for digit in [-2147483648,-1,0,11,12,2147483647]:
            add(make(sl=side['sl']+.123456789,tp=0.,digits=[digit,3,3,3,3],**fraction),'digits-low32-clamp')
        for sl,tp in [(0.,0.),(side['sl']+.123456789,0.),(0.,side['tp']+.987654321)]:
            for digits in [[3,2,8,11,5],[5,11,8,2,3],[0,1,2,3,4],[11,10,9,8,7]]:
                add(make(sl=sl,tp=tp,digits=digits,**fraction),'digits-five-reads')
        # Each group has its own flag/timeframe bytes and mapping, so every boundary is repeated per group.
        for g in range(3):
            only=['close' if k==g else 'off' for k in range(3)]
            for flag in [0,2,255]:
                c=make(only,timeframes=[255]*3,shift=255);c['candle_on'][g]=flag;add(c,'candle-flag-byte')
            for frame,shift in [(0,1),(1,1),(2,1),(255,1),(1,0),(1,2),(1,255)]:
                c=make(only,shift=shift);c['timeframes'][g]=frame;add(c,'candle-frame-shift')
            for opened in [899,900,901,1099,1100,1101]:
                c=make(only,opened=opened);c['times'][:2]=[900,1100];add(c,'candle-time-boundaries')
            for opened,previous,current in [(-1,-(1<<63),0),(0,1,(1<<63)-1),((1<<63)-1,0,(1<<63)-1)]:
                c=make(only,opened=opened);c['times'][:2]=[previous,current];add(c,'candle-time-signed')
            for close,open_ in [(99.,101.),(101.,99.),(100.,100.),(-0.,0.),(0.,-0.),(NAN_A,100.),(100.,NAN_A),(-math.inf,math.inf),(math.inf,-math.inf)]:
                c=make(only);c['closes'][0]=close;c['opens'][0]=open_;add(c,'candle-body-boundaries')
            for level in [math.nextafter(100.,-math.inf),100.,math.nextafter(100.,math.inf),NAN_A,math.inf,-math.inf]:
                c=make(only);c['closes'][1]=level;add(c,'candle-level-boundaries')
            for first,second in ([(90.,110.),(110.,90.),(90.,90.5),(90.,NAN_A),(NAN_A,90.)] if buy else [(110.,90.),(90.,110.),(110.,109.5),(110.,NAN_A),(NAN_A,110.)]):
                c=make(only);c['closes'][:2]=[first,second];add(c,'close-reread')
        for shift,frames in itertools.product([0,1,2,255],[[15,1,1],[0,0,0],[255,2,255]]):
            add(make(closing,shift=shift,timeframes=list(frames)),'three-groups-all-close')
        for g in range(3):
            for outcome in OUTCOMES[:-1]:
                outcomes=['close']*3;outcomes[g]=outcome;add(make(outcomes),'group-exit-independent')
            for flag in [2,255]:
                outcomes=['close']*3;outcomes[g]='off';c=make(outcomes);c['candle_on'][g]=flag;add(c,'group-flag-independent')
        for _ in range(12):
            add(make([rng.choice(OUTCOMES) for _ in range(3)],shift=rng.choice([0,1,2,255]),
                     timeframes=[rng.choice([0,1,2,15,255]) for _ in range(3)]),'group-random-outcomes')
        for ok in [0,1]:
            for change in [{},dict(type=2),dict(magic=9002),dict(enabled=0),dict(position_symbol='OTHER')]:
                add(make(closing,tick_ok=ok,**change),'tick-failure-continues')
    return out

def pack_text(text,null):
    require(null in [0,1] and not (null and text),'BAD_TEXT_CASE')
    raw=text.encode('utf-16-le');return struct.pack('<2i',null,len(raw)//2)+raw
def encode(rows):
    b=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        b+=CASE.pack(c['id'],c['buy'],c['scenario'],c['ticket'],c['type'],c['magic'],c['expected_magic'],c['enabled'],*c['digits'],
                     *[c[k] for k in ['sl','tp','open','volume','unit','stop','take']],c['tick_ok'],0,0,c['bid'],c['ask'],c['opened'],
                     *c['times'],*c['candle_on'],*c['timeframes'],c['shift'],*c['closes'],*c['opens'])
        for text,null in [('symbol','symbol_null'),('position_symbol','position_null'),('comment','comment_null')]:b+=pack_text(c[text],c[null])
    return bytes(b)
def describe(rows):
    out=copy.deepcopy(rows)
    for c in out:
        for key,value in c.items():
            if type(value) is float:c[key]='%016x'%bits(value)
            elif type(value) is list and value and type(value[0]) is float:c[key]=['%016x'%bits(v) for v in value]
    return out
def groups(rows):
    out={}
    for c in rows:out[c['group']]=out.get(c['group'],0)+1
    return out

class Original(entry.Original):
    def __init__(self):
        super().__init__(3);m=self.m
        require(self.base==CODE_BASE,'CAPTURED_CODE_BASE_DIFFERS')
        analysis=json.loads((ANALYSIS/'analysis.json').read_text(encoding='utf-8'))
        bounds=json.loads((CONTRACT/'native-boundaries.json').read_text(encoding='utf-8'))
        require(analysis['original_ex5_sha256']==bounds['original_ex5_sha256']==validation.original_hash(3),'EX5_DIFFERS')
        require(bounds['bot']==3 and bounds['analysis_sha256']==sha(ANALYSIS/'analysis.json') and bounds['contract_sha256']==sha(CONTRACT/'contract.md'),'BOUNDARY_EVIDENCE_DIFFERS')
        for f in analysis['functions']:
            lo,hi=int(f['rva'],16),int(f['end_rva'],16)
            require(hashlib.sha256(bytes(m.mem_read(self.base+lo,hi-lo))).hexdigest()==f['native_bytes_sha256'],'NATIVE_FUNCTION_CHANGED')
        self.segments={}
        for seg in bounds['segments']:
            parent,lo,hi=(int(seg[k],16) for k in ['parent_rva','begin','end_exclusive'])
            buy={v['function']:k for k,v in SIDES.items()}.get(parent);require(buy is not None and buy not in self.segments,'UNKNOWN_SEGMENT')
            raw=bytes(m.mem_read(self.base+lo,hi-lo));pos=lo
            for row in seg['instructions']:
                require(int(row['rva'],16)==pos,'SEGMENT_NOT_CONTIGUOUS');pos+=len(bytes.fromhex(row['bytes']))
            require(pos==hi==SIDES[buy]['accepted'] and len(seg['instructions'])==seg['instruction_count'],'SEGMENT_BOUNDARY_DIFFERS')
            require(b''.join(bytes.fromhex(r['bytes']) for r in seg['instructions'])==raw and hashlib.sha256(raw).hexdigest()==seg['native_sha256'],'NATIVE_SEGMENT_CHANGED')
            self.segments[buy]=dict(begin=lo,end=hi,instructions={int(r['rva'],16) for r in seg['instructions']})
        require(set(self.segments)=={0,1},'SEGMENT_MISSING')
        self.messages={int(s['descriptor_rva'],16):s['text'] for s in bounds['strings']}
        require(set(self.messages.values())=={'Tick not ok','closing candle confirmation'},'MESSAGE_SET_DIFFERS')
        for rva,text in self.messages.items():require(self.text(self.base+rva)==(text,0),'NATIVE_MESSAGE_DIFFERS')
        for row in bounds['rounding']:require(bytes(m.mem_read(self.base+int(row['rva'],16),16)).hex()==row['bytes'],'ROUNDING_CONSTANT_DIFFERS')
        eb=next(addr for addr,api in self.apis.items() if api==1)-0x7d3c40
        # Inherited entry/price hooks are not part of this prefix: any call to them fails.
        for addr,api in list(self.apis.items()):
            if api not in [100,101]:self.apis[addr]=0
        for rva,api in TARGETS.items():
            addr=eb+rva
            if addr in self.apis:self.apis[addr]=api;continue
            if not any(lo<=addr<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(addr&~4095,4096)
            self.apis[addr]=api;m.mem_write(addr,b'\xc3');m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
        for rva,api in CHILDREN.items():
            self.apis[self.base+rva]=api;m.hook_add(self.uc.UC_HOOK_CODE,self.child,begin=self.base+rva,end=self.base+rva)
        self.covered=set();m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x32f60,end=self.base+0x38194)
    def text(self,desc):
        p=struct.unpack('<Q',self.m.mem_read(desc+4,8))[0]
        if not p:return '',1
        n=struct.unpack('<I',self.m.mem_read(p-4,4))[0];require(n<=4096,'BAD_STRING_LENGTH')
        return bytes(self.m.mem_read(p,n*2)).decode('utf-16-le'),0
    def event(self,api,a=0,b=0,v=0,w=0):
        self.events.append([api,a&MASK,b&MASK,v&MASK,w&MASK])
    def child(self,m,address,size,user):
        # Record the register arguments, then return 0 without executing the child.
        x=self.x;api=self.apis[address];sp=m.reg_read(x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(sp,8))[0]
        seg=self.segments[self.case['buy']];require(seg['begin']<=ret-self.base<seg['end'],'CHILD_CALL_OUTSIDE_SEGMENT')
        values=[m.reg_read(x.UC_X86_REG_XMM1)&MASK,m.reg_read(x.UC_X86_REG_XMM2)&MASK] if api==8 else []
        self.event(api,m.reg_read(x.UC_X86_REG_RCX),*values)
        m.reg_write(x.UC_X86_REG_RAX,0);m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret)
    def visit(self,m,address,size,user):
        off=address-self.base;self.covered.add(off)
        if off==self.side['accepted']:self.accepted=1;m.emu_stop()
        elif off in self.side['rejected']:
            require(any(e[0]==2 for e in self.events),'BOUNDARY_BEFORE_TICKET');self.accepted=0;m.emu_stop()
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address];c=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        a=m.reg_read(x.UC_X86_REG_RDX);b=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
        if api==1:
            require(b==17 and self.di<5,'BAD_DIGITS_CALL');text,null=self.text(a)
            value=c['digits'][self.di];self.di+=1
            self.event(api,b,entry.text_hash(text),value,null);m.reg_write(x.UC_X86_REG_RAX,value&MASK)
        elif api==2:
            require(a==0 and not any(e[0]==2 for e in self.events),'BAD_TICKET_CALL')
            self.event(api,a,0,c['ticket']);m.reg_write(x.UC_X86_REG_RAX,c['ticket'])
        elif api==3:
            require(a in DOUBLES,'BAD_POSITION_DOUBLE');value=bits(c[DOUBLES[a]])
            m.mem_write(self.base+G['double'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value);self.event(api,a,0,value)
        elif api==4:
            require(a in INTEGERS,'BAD_POSITION_INTEGER');value=c[INTEGERS[a]]
            self.event(api,a,0,value);m.reg_write(x.UC_X86_REG_RAX,value&MASK)
        elif api==5:
            require(a in STRINGS,'BAD_POSITION_STRING');key,flag=STRINGS[a];text,null=c[key],c[flag]
            m.mem_write(self.base+G['string'],struct.pack('<IQ',0,0 if null else self.string(text)))
            self.event(api,a,entry.text_hash(text),null)
        elif api==6:
            require(m.reg_read(x.UC_X86_REG_R8)==self.base+G['tick'],'BAD_TICK_OUTPUT');text,null=self.text(a)
            self.event(api,entry.text_hash(text),c['tick_ok'],bits(c['bid']),bits(c['ask']))
            if c['tick_ok']:m.mem_write(self.base+G['tick']+8,struct.pack('<2d',c['bid'],c['ask']))
            m.reg_write(x.UC_X86_REG_RAX,c['tick_ok'])
        elif api==7:
            require(a==2 and b==1 and m.reg_read(x.UC_X86_REG_R9)==0x590008,'BAD_PRINT_SIGNATURE')
            descriptor=struct.unpack('<Q',m.mem_read(m.reg_read(x.UC_X86_REG_RSP)+0x28,8))[0]
            require(descriptor-self.base in self.messages,'UNEXPECTED_PRINT_TEXT');text,null=self.text(descriptor)
            self.event(api,entry.text_hash(text));m.reg_write(x.UC_X86_REG_RAX,0)
        elif api in [10,11,12]:
            text,null=self.text(a);shift=m.reg_read(x.UC_X86_REG_R9)&0xffffffff
            if api==10:
                require(self.ti<6,'TOO_MANY_TIME_READS');raw=c['times'][self.ti]&MASK;self.ti+=1;m.reg_write(x.UC_X86_REG_RAX,raw)
            else:
                if api==11:require(self.ci<6,'TOO_MANY_CLOSE_READS');raw=bits(c['closes'][self.ci]);self.ci+=1
                else:require(self.oi<3,'TOO_MANY_OPEN_READS');raw=bits(c['opens'][self.oi]);self.oi+=1
                m.mem_write(self.base+G['double'],struct.pack('<Q',raw));m.reg_write(x.UC_X86_REG_XMM0,raw)
            self.event(api,b,shift,raw,entry.text_hash(text))
        elif api==13:m.reg_write(x.UC_X86_REG_RAX,1)
        else:raise ValueError('UNEXPECTED_API '+str(api))
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.side=SIDES[c['buy']];self.events=[];self.accepted=-1
        self.di=self.ti=self.ci=self.oi=0;self.cursor=0x70001000;self.allocs=self.frees=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in GPRS:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        for key,fmt in [('magic','<i'),('enabled','<i'),('stop','<d'),('take','<d'),('unit','<d')]:
            m.mem_write(self.base+G[key],struct.pack(fmt,c['expected_magic' if key=='magic' else key]))
        for rva,value in zip(G['flags']+G['frames']+[G['shift']],c['candle_on']+c['timeframes']+[c['shift']]):m.mem_write(self.base+rva,bytes([value]))
        m.mem_write(self.base+G['symbol'],struct.pack('<IQ',0,0 if c['symbol_null'] else self.string(c['symbol'])))
        m.mem_write(self.base+G['tick']+8,struct.pack('<2d',-100.,-101.))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.emu_start(self.base+self.side['function'],0x60000000,timeout=5000000,count=2000000)
        require(self.accepted in [0,1],'PREFIX_BOUNDARY_NOT_REACHED')
        last=struct.unpack('<Q',m.mem_read(self.base+G['ticket'],8))[0];present=int(last!=0);sp=m.reg_read(x.UC_X86_REG_RSP)
        if present:
            values=[m.reg_read(getattr(x,'UC_X86_REG_XMM'+str(n)))&MASK for n in [8,7,9,6,13]]
            comment=self.text(sp+0x90);symbol=self.text(sp+self.side['symbol']);integers=[c['opened'],c['type'],c['magic']]
        else:values=[0]*5;comment=symbol=('',1);integers=[0,0,0]
        h=0xcbf29ce484222325
        for event in self.events:
            for byte in struct.pack('<5Q',*event):h=((h^byte)*0x100000001b3)&MASK
        tick=struct.unpack('<2Q',m.mem_read(self.base+G['tick']+8,16))
        return RESULT.pack(c['id'],self.accepted,last,present,*values,*integers,entry.text_hash(comment[0]),entry.text_hash(symbol[0]),
                           comment[1],symbol[1],*tick,len(self.events),h)

def read_results(raw,n):
    require(raw[:12]==struct.pack('<3i',MAGIC,1,n) and len(raw)==12+RESULT.size*n,'BAD_RESULT_SHAPE')
    rows=[RESULT.unpack_from(raw,12+i*RESULT.size) for i in range(n)]
    require(all(r[0]==i for i,r in enumerate(rows)),'RESULT_ID_DIFFERS');return rows
def verify_receipt(path,current):
    receipt=json.loads(path.read_text(encoding='utf-8-sig'));target=NAMES[-1];digest=receipt.get('binary_sha256');compiled=receipt.get('sources_sha256')
    require(receipt.get('target')==target and zero(receipt.get('errors')) and zero(receipt.get('warnings')),'BUILD_NOT_CLEAN_OR_TARGET_DIFFERS')
    require(type(digest) is str and re.fullmatch('[0-9a-f]{64}',digest) is not None and type(compiled) is dict,'BUILD_RECEIPT_INCOMPLETE')
    require(sha(path.parent/Path(target).with_suffix('.ex5').name)==digest,'PRIVATE_BINARY_COPY_DIFFERS')
    for name,value in current['sources_sha256'].items():require(compiled.get(name)==value,'COMPILED_SOURCE_DIFFERS '+name)
    return digest

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args()
    require(bool(re.fullmatch('[a-z0-9-]{1,50}',a.run)),'INVALID_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity();rows=cases();n=len(rows)
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False)
        with (folder/'cases.bin').open('xb') as f:f.write(encode(rows))
        save(folder/'cases.json',describe(rows));tested=folder/'tested-sources';tested.mkdir()
        for name in NAMES:shutil.copyfile(HOME/'source/MQL5'/name,tested/Path(name).name)
        for name in HELPERS:shutil.copyfile(ROOT/'cong-cu'/name,tested/name)
        shutil.copyfile(Path(__file__),tested/Path(__file__).name)
        save(folder/'baseline.json',dict(**current,cases=n,inputs_sha256=sha(folder/'cases.bin'),groups=groups(rows),**SCOPE))
        print(json.dumps({'cases':n,'groups':groups(rows)}));return
    baseline=json.loads((folder/'baseline.json').read_text(encoding='utf-8'));check(baseline,current,'BASELINE')
    require(baseline['cases']==n and baseline['inputs_sha256']==sha(folder/'cases.bin') and (folder/'cases.bin').read_bytes()==encode(rows),'INPUTS_CHANGED')
    if a.mode=='original':
        require(not any((folder/x).exists() for x in ['original-results.bin','original-run.json','original-traces.json']),'ORIGINAL_EXISTS')
        runner=Original();raw=bytearray(struct.pack('<3i',MAGIC,1,n));traces=[];seen=set();paths={};started=time.monotonic()
        for c in rows:
            try:raw+=runner.run(c)
            except Exception as error:raise RuntimeError(f'case={c["id"]} group={c["group"]} rva={runner.m.reg_read(runner.x.UC_X86_REG_RIP)-runner.base:#x} {error}') from error
            path=('buy-' if c['buy'] else 'sell-')+('accepted' if runner.accepted else 'rejected');paths[path]=paths.get(path,0)+1
            if (c['buy'],c['group']) not in seen:seen.add((c['buy'],c['group']));traces.append(dict(id=c['id'],group=c['group'],buy=c['buy'],events=runner.events))
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-traces.json',traces)
        coverage={hex(SIDES[k]['function']):dict(instructions=len(s['instructions']),executed=len(s['instructions']&runner.covered),
                  missing=[hex(v) for v in sorted(s['instructions']-runner.covered)]) for k,s in runner.segments.items()}
        save(folder/'original-run.json',dict(**current,cases=n,seconds=round(time.monotonic()-started,2),result_sha256=sha(folder/'original-results.bin'),
             paths=paths,coverage=coverage,**SCOPE))
        print(json.dumps(dict(cases=n,paths=paths,coverage={k:[v['executed'],v['instructions']] for k,v in coverage.items()})));return
    if a.mode=='mql5':
        require(bool(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build)),'BUILD_REQUIRED')
        require(not any((folder/x).exists() for x in ['mql5-results.bin','script-status.bin','mql5-run.json']),'MQL5_EXISTS')
        receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';digest=verify_receipt(receipt,current)
        require(sha(MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5'))==digest,'TERMINAL_BINARY_DIFFERS')
        for name,value in current['sources_sha256'].items():require(sha(MT/'MQL5'/name)==value,'TERMINAL_SOURCE_DIFFERS '+name)
        files=MT/'MQL5/Files/bot3-management-prelude'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b3-prelude-{a.run}.set';preset.parent.mkdir(exist_ok=True);ini=MT/f'b3-prelude-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write(f'CheckRun={a.run}\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementPreludeCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        before=sha(MT/'terminal64.exe');started=time.monotonic()
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MQL5_TIMEOUT')
        after=sha(MT/'terminal64.exe');require(code==0 and before==after,f'MQL5_RUN_FAILED_OR_TERMINAL_CHANGED {code}')
        require((files/'script-status.bin').is_file(),'SCRIPT_STATUS_MISSING')
        require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,n),'SCRIPT_STATUS_DIFFERS '+(files/'script-status.bin').read_bytes().hex())
        for name in ['mql5-results.bin','script-status.bin']:
            with (files/name).open('rb') as src,(folder/name).open('xb') as dst:shutil.copyfileobj(src,dst)
        save(folder/'mql5-run.json',dict(**current,cases=n,exit_code=code,seconds=round(time.monotonic()-started,2),build=a.build,build_receipt_sha256=sha(receipt),
             binary_sha256=digest,terminal_sha256=after,result_sha256=sha(folder/'mql5-results.bin'),status_sha256=sha(folder/'script-status.bin'),**SCOPE))
        print(json.dumps({'cases':n,'exit_code':code}));return
    for name,target in [('original-run.json','original-results.bin'),('mql5-run.json','mql5-results.bin')]:
        record=json.loads((folder/name).read_text(encoding='utf-8'));check(record,current,name.split('-')[0].upper()+'_RUN')
        require(record['cases']==n and record['result_sha256']==sha(folder/target),'RESULT_CHANGED '+target)
    mql=json.loads((folder/'mql5-run.json').read_text(encoding='utf-8'));receipt=HOME/'bang-chung/bien-dich'/mql['build']/'bien-nhan.json'
    require(sha(receipt)==mql['build_receipt_sha256'] and verify_receipt(receipt,current)==mql['binary_sha256'],'BUILD_EVIDENCE_CHANGED')
    require((folder/'script-status.bin').read_bytes()==struct.pack('<2i',0,n) and sha(folder/'script-status.bin')==mql['status_sha256'],'STATUS_CHANGED')
    native=read_results((folder/'original-results.bin').read_bytes(),n);actual=read_results((folder/'mql5-results.bin').read_bytes(),n)
    failures=[];summary={}
    for c,left,right in zip(rows,native,actual):
        g=summary.setdefault(c['group'],dict(cases=0,matched=0));g['cases']+=1
        if left==right:g['matched']+=1;continue
        failures.append(dict(id=c['id'],group=c['group'],buy=c['buy'],fields=[f for f,x,y in zip(FIELDS,left,right) if x!=y],original=list(left),mql5=list(right)))
    coverage=json.loads((folder/'original-run.json').read_text(encoding='utf-8'))['coverage']
    report=dict(cases=n,matched=n-len(failures),failed=len(failures),groups=summary,first_failures=failures[:12],
                coverage={k:[v['executed'],v['instructions']] for k,v in coverage.items()},
                hashes={x:sha(folder/x) for x in ['baseline.json','cases.bin','original-results.bin','mql5-results.bin','script-status.bin']},**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report,ensure_ascii=False));raise SystemExit(bool(failures))

if __name__=='__main__':main()
