"""Compare the complete NFP evaluator branch and real calendar/cancel/close/send children.

prepare|mql5(--build)|original|compare BOT RUN. MT5 records only SDK replies.
Native algorithms run unchanged and must request the identical SDK arguments/state.
"""
import argparse,calendar,copy,hashlib,importlib.util,json,re,shutil,struct,subprocess
from datetime import datetime,timezone
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x4e465231;MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
entry=module('nfp_branch_entry','kiem-gia-vao-bot-1-3.py');pub=module('nfp_branch_pub','kiem-ban-git-quan-ly.py');require=pub.require
validation=module('nfp_branch_validation','kiem-khoi-luong-hop-le-bot-1-3.py')
LAYOUT=ROOT/'doi-chung-mt5/thu-tu-truong-lenh-class-20261024/layout-class-r1/trade-layout.json';LD=json.loads(LAYOUT.read_text());SCHEMAS=LD['layouts'];BASES=LD['relative_native_storage_bases']
FIELDS=['enabled','use_calendar','throttle','delete_pending','close_positions','before_minutes','after_minutes','initialization_notice','notice','blocked','last_query','utc_reference','nfp','server','current','release','info','calendar_status','orders','position','async_mode','accepted','order_select']
CFG={1:dict(start=0x1b44f,end=0x1bdfd,fn=0x18aa0,fn_end=0x1ef9c,sha='45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd',ctx=0x23e575eae78,flags=[0x6a640,0x6a648,0x6a3a4,0x6a670,0x6a668],minutes=[0x6a678,0x6a680],state=[0x67434,0x68c90,0x67488,0x6a3a8,0x68320],events=[0x6a360,0x6a368,0x6a370],cached=0x67790,history=0x68330,magic=0x6246c,seed=0x6a610,symbol=0x67918,variables=[0x67758,0x67760,0x66a70,0x67468],ticket=0x677f8,deviation=0x6772d,request=0x674b0,trade_ctx=0x67490,stored_magic=0x67725,stopped=0x6a414,error=0x6a410,type_tags=[0x23e5761278a,0x23e57610daa]),
 3:dict(start=0x2372b,end=0x24437,fn=0x20ef0,fn_end=0x2a1bc,sha='6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920',ctx=0x171514ca538,flags=[0x1d7020,0x1d7028,0x1d6cb4,0x1d7050,0x1d7048],minutes=[0x1d7058,0x1d7060],state=[0x74474,0x75cc0,0x744c8,0x1d6cb8,0x75358],events=[0x1d6c70,0x1d6c78,0x1d6c80],cached=0x747d0,history=0x75360,magic=0x6d564,seed=0x1d6ff0,symbol=0x74958,variables=[0x74798,0x747a0,0x73ab0,0x744a8],ticket=0x74838,deviation=0x7476d,request=0x744f0,trade_ctx=0x744d0,stored_magic=0x74765,stopped=0x1d6e14,error=0x1d6e10,type_tags=[0x171514adbca,0x17156057baa])}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_complete_nfp_branch_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def bits(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def text(s):
    if s is None:return struct.pack('<i',-1)
    raw=s.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def save(p,o):
    with p.open('x',encoding='utf-8',newline='\n') as f:json.dump(o,f,ensure_ascii=False,indent=2)
def stamp(y,m,d,h=12):return calendar.timegm((y,m,d,h,0,0))
def date_words(t):
    d=datetime.fromtimestamp(t,timezone.utc);return [d.year,d.month,d.day,d.hour,d.minute,d.second,(d.weekday()+1)%7,int(d.strftime('%j'))-1]
def cases():
    rows=[];history=json.loads((ROOT/'danh-gia-doc-lap/news-selector-20261027-r1/nfp-history-evidence.json').read_text())[0]['values']
    def add(tag,**changes):
        now=stamp(2026,1,2);c=dict(id=len(rows),tag=tag,enabled=1,use_calendar=1,throttle=1,delete_pending=1,close_positions=1,before_minutes=10,after_minutes=10,initialization_notice=255,notice=1,blocked=0,last_query=now-901,utc_reference=now+3600,nfp=0,server=now,current=now,release=now+300,info=0,calendar_status=1,orders=0,position=0,async_mode=0,accepted=0,order_select=0)
        c.update(changes);c['cached']=date_words(c['current']);c['history']=list(history);rows.append(c);return c
    for enabled in [0,1,255]:
        for calendar_enabled in [0,1]:
            for info in [0,1]:add('enable-calendar-tester',enabled=enabled,use_calendar=calendar_enabled,info=info)
    now=stamp(2026,1,2)
    for n in [0,1,2,3,255]:
        for time in [0,now+300]:add('notice-cached-time',notice=n,nfp=time,last_query=now)
    for throttle in [0,1,255]:
        for delta in [0,1,899,900,901]:add('refresh-strict-boundary',throttle=throttle,last_query=now-delta,nfp=now+300)
    for before,after in [(0,0),(5,5),(10,10),(-1,-1),(2147483647,2147483647),(-2147483648,-2147483648),(-35791395,35791395)]:
        for release in [now-600,now,now+600]:add('minutes-window-boundaries',before_minutes=before,after_minutes=after,release=release)
    for status in [-1,0,1,2,3,4]:add('calendar-result-and-fallback',calendar_status=status,release=now+300 if status else 0)
    for y,m,d in [(1970,1,1),(1986,6,1),(2006,6,1),(2026,1,2),(2026,6,5),(2027,1,1),(2027,6,4),(2030,1,4)]:
        cur=stamp(y,m,d);c=add('fallback-by-year',use_calendar=0,server=cur,current=cur,utc_reference=cur,nfp=777);c['history'][0]=cur
    for day,weekday in [(1,5),(7,5),(8,5),(1,4)]:
        c=add('manual-cached-calendar',use_calendar=0,server=stamp(2027,1,1),current=stamp(2027,1,1),utc_reference=0,nfp=777,blocked=2);c['cached'][2]=day;c['cached'][6]=weekday
    for offset in [-1,0,1]:
        c=add('history-window',use_calendar=0,utc_reference=now+3600+offset,before_minutes=0,after_minutes=0);c['history'][0]=now
    c=add('no-history-match',use_calendar=0);c['history']=[0]*300
    for order in [1,2]:
        for position in [0,1,2]:
            for async_mode in [0,1]:
                for accepted in [0,1]:add('full-cancel-close-send',orders=order,position=position,async_mode=async_mode,accepted=accepted,order_select=accepted)
    for close_positions,delete_pending in [(0,0),(0,1),(1,0)]:add('action-flags',orders=1,position=1,close_positions=close_positions,delete_pending=delete_pending)
    return rows
def encode(rows):
    return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<i'+len(FIELDS)*'q'+'8i300q',c['id'],*[c[n] for n in FIELDS],*c['cached'],*c['history']) for c in rows)
class Reader:
    def __init__(self,raw):self.raw=raw;self.pos=0
    def take(self,fmt):size=struct.calcsize('<'+fmt);v=struct.unpack_from('<'+fmt,self.raw,self.pos);self.pos+=size;return v
    def block(self):n,=self.take('i');require(0<=n<=10000000,'BAD_BLOCK');raw=self.raw[self.pos:self.pos+n];self.pos+=n;return raw
    def text(self):
        n,=self.take('i');require(-1<=n<100000,'BAD_TEXT');raw=self.raw[self.pos:self.pos+max(n,0)*2];self.pos+=max(n,0)*2;return None if n<0 else raw.decode('utf-16-le')
class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.bot=bot;self.nfp=CFG[bot];cfg=self.nfp;require(hashlib.sha256(bytes(self.m.mem_read(self.base+cfg['fn'],cfg['fn_end']-cfg['fn']))).hexdigest()==cfg['sha'],'NFP_EVALUATOR_BYTES_CHANGED')
        eb=0x7ff683f20000;offsets={1:0x7c0fd0,2:0x7d1ce0,3:0x7d1c40,4:0x7d1f60,5:0xaa9970,6:0x7cd370,7:0x7ccc50,8:0x7cdfe0,10:0x7b49f0,11:0x3802f0,12:0x380440,13:0x7d81a0,14:0x7d81f0,15:0x7d7da0,16:0x7d7df0,17:0x7d8310,18:0x7d83a0,19:0x7d8280,20:0x7d8240,21:0x7d8b70,22:0x7d7fc0,23:0x7d8010,24:0x7d7f70,25:0x7d7ee0,26:0x7c2970,27:0x7c2890,28:0x7c2c10,29:0x7c29d0,30:0x7d8be0}
        self.sdk={eb+off:api for api,off in offsets.items()};self.sdk[eb+0x7b6ef0]=0
        for a in self.sdk:
            existed=a in self.apis
            if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
            self.m.mem_write(a,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        for a in cfg['type_tags']:
            if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
            self.m.mem_write(a,b'\0\0')
        self.covered=set();self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+cfg['fn'],end=self.base+cfg['fn_end']-1)
        functions={'calendar':0x61b0 if bot==1 else 0x6ad0,'dst':0x17840 if bot==1 else 0x7e20,'year':0x2ffb0 if bot==1 else 0x3d5f0,'month':0x2ffe0 if bot==1 else 0x3d620,'cancel_buy':0x2f5c0 if bot==1 else 0x3ca00,'cancel_sell':0x2f7e0 if bot==1 else 0x3cc20,'filtered_buy':0x2fa00 if bot==1 else 0x3ce40,'filtered_sell':0x2fce0 if bot==1 else 0x3d220,'guard_close':0x3d010 if bot==1 else 0x47d20,'close':0x22c40 if bot==1 else 0x2e370,'filling':0x231c0 if bot==1 else 0x2e8f0,'send':0x950,'string_copy':0x5c0,'string_append':0x4a0,'array_cleanup':0x7e0}
        self.child_names={self.base+rva:name for name,rva in functions.items()};self.child_calls={name:0 for name in functions}
        for address in self.child_names:self.m.hook_add(self.uc.UC_HOOK_CODE,self.child_enter,begin=address,end=address)
    def child_enter(self,m,address,size,user):self.child_calls[self.child_names[address]]+=1
    def visit(self,m,address,size,user):
        self.covered.add(address-self.base)
        if address==self.base+self.nfp['end']:self.done=True;m.emu_stop()
    def read_text(self,desc):
        p=struct.unpack('<Q',self.m.mem_read(desc+4,8))[0]
        if not p:return None
        n=struct.unpack('<I',self.m.mem_read(p-4,4))[0];require(n<10000,'NATIVE_TEXT_SIZE');return bytes(self.m.mem_read(p,n*2)).decode('utf-16-le')
    def value(self,rva,kind='q'):return struct.unpack('<'+kind,self.m.mem_read(self.base+rva,struct.calcsize('<'+kind)))[0]
    def state(self):
        cfg=self.nfp;raw=bytearray()
        def word(v):raw.extend(struct.pack('<Q',v&MASK))
        for a in cfg['flags']:word(self.value(a,'B'))
        for a in cfg['minutes']:word(self.value(a,'i'))
        for i,a in enumerate(cfg['state']):word(self.value(a,'B' if i<3 else 'q'))
        for a in cfg['events']:word(self.value(a))
        for i in range(8):word(self.value(cfg['cached']+4*i,'i'))
        word(self.value(cfg['magic'],'i'));word(self.value(cfg['seed'],'i'));raw.extend(text(self.read_text(self.base+cfg['symbol'])))
        for a in cfg['variables']:word(self.value(a,'Q'))
        word(self.value(cfg['ticket'],'Q'));word(self.value(cfg['deviation'],'Q'))
        for key,schema in SCHEMAS.items():
            for f in schema['fields']:
                a=cfg['request']+BASES[key]+f['offset'];kind=f['kind']
                if kind=='s':raw.extend(text(self.read_text(self.base+a)))
                else:word(self.value(a,'Q' if kind=='d' else kind))
        word(self.value(cfg['stored_magic'],'Q'));word(self.value(cfg['stored_magic']+16,'i'));word(self.value(cfg['trade_ctx']+660,'B'));word(self.value(cfg['trade_ctx']+685,'i'));word(self.value(cfg['trade_ctx']+681,'i'));word(self.value(cfg['error'],'I'))
        return bytes(raw)
    def array(self,desc,records):
        require(struct.unpack('<I',self.m.mem_read(desc+4,4))[0]==128,'CALENDAR_ARRAY_STRIDE');n=len(records);self.m.mem_write(desc+8,struct.pack('<I',n));self.m.mem_write(desc+24,struct.pack('<I',n))
        if n:
            p=self.cursor+4;self.cursor+=(128*n+19)&~15;self.m.mem_write(p-4,struct.pack('<I',4));self.m.mem_write(p,b''.join(records));self.m.mem_write(desc+28,struct.pack('<Q',p))
    def call(self,m,address,size,user):
        if address not in self.sdk:
            require(self.apis.get(address) in [100,101],'UNBOUND_NFP_API');return super().call(m,address,size,user)
        api=self.sdk[address]
        if api==0:return
        rd=self.tape;before=rd.block();require(before==self.state(),'STATE_BEFORE_SDK '+str(self.case['id'])+' '+str(api));kind,*args=rd.take('i4Q');strings=[rd.text() for _ in range(4)];payload=rd.block();error,=rd.take('I')
        x=self.x;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));sp=r('RSP');a,b,c,d=args;cfg=self.nfp;require(r('RCX')==cfg['ctx'] or api==5,'NFP_SDK_CONTEXT')
        def integer(v):m.reg_write(x.UC_X86_REG_RAX,v&MASK)
        def double(v):m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',v));m.reg_write(x.UC_X86_REG_XMM0,v)
        if api==10 and r('RDX')==0x174:api=9
        require(kind==(21 if api==30 else api),'SDK_ORDER '+str((self.case['id'],kind,api)))
        if api==1:require(r('RDX')==a==6 and b==(self.case['info']&MASK),'MQL_INFO_ARGUMENT_OR_REPLY');integer(b)
        elif api==2:require(r('RDX')==0 and a==(self.case['server']&MASK),'SERVER_OVERLOAD_OR_REPLY');integer(a)
        elif api==3:
            require(int(r('RDX')!=0)==a and b==(self.case['current']&MASK),'CURRENT_OVERLOAD_OR_REPLY')
            if a:require(len(payload)==32,'CURRENT_CALENDAR');m.mem_write(r('RDX'),payload)
            integer(b)
        elif api==4:require(r('RDX')==a and len(payload)==32,'STRUCT_ARGUMENT');m.mem_write(r('R8'),payload);integer(b)
        elif api==5:require((r('XMM0')&MASK,r('XMM1')&MASK)==(a,b),'MATH_MOD_ARGUMENT');m.reg_write(x.UC_X86_REG_XMM0,c)
        elif api==6:require(self.read_text(r('RDX'))==strings[0],'PARSE_STRING_ARGUMENT');integer(a)
        elif api==7:require((r('RDX'),r('R8'))==(a,b),'FORMAT_TIME_ARGUMENT');m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(strings[0])))
        elif api==8:require((r('RDX'),r('R8')&0xffffffff,r('R9')&65535)==(a,b,c),'FORMAT_INTEGER_ARGUMENT');m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(strings[0])))
        elif api==9:
            require(r('R8')==3 and r('R9')==0x59000a,'CONCAT_SHAPE');ptr=struct.unpack('<Q',m.mem_read(sp+40,8))[0];year=struct.unpack('<i',m.mem_read(sp+56,4))[0];last=struct.unpack('<Q',m.mem_read(sp+72,8))[0]
            require((year&MASK)==a and self.read_text(ptr)==strings[0] and self.read_text(last)==strings[1],'CONCAT_ARGUMENT');m.mem_write(ptr,struct.pack('<IQ',0,self.string(strings[2])));integer(b)
        elif api==10:
            require(r('RDX')==2 and r('R8')==a,'PRINT_ARGUMENT_COUNT')
            for i in range(a):require(self.read_text(struct.unpack('<Q',m.mem_read(sp+40+16*i,8))[0])==strings[i],'PRINT_TEXT')
        elif api==11:
            require(self.read_text(r('RDX'))==strings[0]=='USD','CALENDAR_CURRENCY');rows=[]
            if self.case['calendar_status']>0:
                row=bytearray(128);struct.pack_into('<Q',row,0,0 if self.case['calendar_status']==3 else 77);name=None if self.case['calendar_status']==4 else 'Other' if self.case['calendar_status']==2 else 'Nonfarm Payrolls';struct.pack_into('<IQ',row,72,0,0 if name is None else self.string(name));rows.append(row)
            require(len(rows)==b,'EVENT_REPLY_COUNT');self.array(r('R8'),rows);integer(a)
        elif api==12:
            require((r('RDX'),r('R9'),struct.unpack('<Q',m.mem_read(sp+40,8))[0])==(a,b,c),'CALENDAR_HISTORY_ARGUMENT');row=bytearray(128);struct.pack_into('<q',row,16,self.case['release']);self.array(r('R8'),[row]);integer(d)
        elif api in [13,15]:require(a==int(self.case['orders' if api==13 else 'position']!=0),'TOTAL_REPLY');integer(a)
        elif api in [14,16]:
            require((r('RDX')&0xffffffff)==a and b==((11 if api==14 else 21) if self.case['orders' if api==14 else 'position']!=0 and a==0 else 0),'TICKET_INDEX_OR_REPLY');integer(b)
        elif api in [17,22]:require(r('RDX')==a,'INTEGER_PROPERTY');integer(b)
        elif api in [18,23]:require(r('RDX')==a,'STRING_PROPERTY');m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,0 if strings[0] is None else self.string(strings[0])))
        elif api in [19,24]:require(r('RDX')==a,'DOUBLE_PROPERTY');double(b)
        elif api in [20,25]:require(r('RDX')==a,'SELECT_TICKET');integer(b)
        elif api in [21,30]:require(a==int(api==30) and b==int(self.case['accepted']!=0) and r('RDX')==self.base+cfg['request'] and r('R8')==self.base+cfg['request']+240,'SEND_ARGUMENT_OR_REPLY');integer(b)
        elif api in [26,27,29]:
            require(self.read_text(r('RDX'))==strings[0] and r('R8')==a,'SYMBOL_PROPERTY')
            if api==26:integer(b)
            elif api==27:double(b)
            else:m.mem_write(r('R9'),struct.pack('<Q',b));integer(c)
        elif api==28:
            require(self.read_text(r('RDX'))==strings[0] and len(payload)==64,'TICK_ARGUMENT');m.mem_write(r('R8'),payload);integer(a)
        else:raise ValueError('NFP_API_UNHANDLED '+str(api))
        m.mem_write(self.base+cfg['error'],struct.pack('<I',error));self.api_count+=1
    def run(self,c,tape):
        self.case=c;self.tape=Reader(tape);self.api_count=0;self.done=False;self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x;cfg=self.nfp
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        for a,n in zip(cfg['flags'],FIELDS[:5]):m.mem_write(self.base+a,struct.pack('<B',c[n]))
        for a,n in zip(cfg['minutes'],FIELDS[5:7]):m.mem_write(self.base+a,struct.pack('<i',c[n]))
        for i,(a,n) in enumerate(zip(cfg['state'],FIELDS[7:12])):m.mem_write(self.base+a,struct.pack('<'+('B' if i<3 else 'q'),c[n]))
        for a,v in zip(cfg['events'],[c['nfp'],7777,8888]):m.mem_write(self.base+a,struct.pack('<q',v))
        m.mem_write(self.base+cfg['cached'],struct.pack('<8i',*c['cached']));m.mem_write(self.base+cfg['history'],struct.pack('<300q',*c['history']))
        m.mem_write(self.base+cfg['magic'],struct.pack('<i',42));m.mem_write(self.base+cfg['seed'],struct.pack('<i',42));m.mem_write(self.base+cfg['symbol'],struct.pack('<IQ',0,self.string('XAUUSD')))
        for a,v in zip(cfg['variables'],[100.,101.,1.,1.]):m.mem_write(self.base+a,struct.pack('<d',v))
        m.mem_write(self.base+cfg['request'],bytes(628));m.mem_write(self.base+cfg['stored_magic'],bytes(24));m.mem_write(self.base+cfg['ticket'],struct.pack('<Q',0x1122334455667788));m.mem_write(self.base+cfg['deviation'],struct.pack('<Q',99));m.mem_write(self.base+cfg['trade_ctx']+660,bytes([c['async_mode']]));m.mem_write(self.base+cfg['trade_ctx']+681,bytes(8));m.mem_write(self.base+cfg['stopped'],bytes(4));m.mem_write(self.base+cfg['error'],bytes(4))
        frame=0x5001f000;m.mem_write(frame,bytes(0x300));m.reg_write(x.UC_X86_REG_RSP,frame);m.reg_write(x.UC_X86_REG_RBP,self.base+0x5c0)
        if self.bot==1:m.reg_write(x.UC_X86_REG_R12,0x7ff683f20000+0x7c0fd0)
        else:m.reg_write(x.UC_X86_REG_R12,self.base+0x5c0);m.reg_write(x.UC_X86_REG_RSI,0x7ff683f20000+0x7c0fd0);m.reg_write(x.UC_X86_REG_RDI,self.base+cfg['state'][0])
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.emu_start(self.base+cfg['start'],0x60000000,timeout=15000000,count=4000000)
        require(self.done and self.tape.pos==len(self.tape.raw),'NFP_BRANCH_DID_NOT_CONSUME_TAPE '+str((c['id'],self.tape.pos,len(self.tape.raw))));return self.state()
def identity(bot):
    home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NfpFilterCheck.mq5'
    helpers=[Path(__file__),LAYOUT,ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'danh-gia-doc-lap/news-selector-20261027-r1/nfp-history-evidence.json']
    return dict(original_ex5_sha256=validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def execute(bot,folder,build):
    h=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';receipt=h/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NfpFilterCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,v in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==v,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/f'MQL5/Files/bot{bot}-nfp-filter'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    ini=mt/('nfp-filter-'+folder.name+'.ini');preset=mt/'MQL5/Presets'/('nfp-filter-'+folder.name+'.set');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}NfpFilterCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','sdk-tape.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tape=Reader((folder/'sdk-tape.bin').read_bytes());require(tape.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Original(a.bot);raw=bytearray(header);counts=[]
        for c in rows:
            id_,=tape.take('i');require(id_==c['id'],'TAPE_ID');events=tape.block();state=o.run(c,events);raw+=struct.pack('<i',c['id'])+struct.pack('<i',len(state))+state;counts.append(o.api_count)
        require(tape.pos==len(tape.raw),'TAPE_TRAILING')
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        require(all(n>0 for n in o.child_calls.values()),'UNEXECUTED_NFP_CHILD');save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),parent_instructions=len(o.covered),sdk_calls=sum(counts),child_calls=o.child_calls,**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=sum(counts),parent_instructions=len(o.covered),child_calls=o.child_calls)));return
    for n in ['original','mql5']:
        record=json.loads((folder/(n+'-run.json')).read_text());require(all(record[k]==v for k,v in current.items()) and record['result_sha256']==sha(folder/(n+'-results.bin')) and record['sdk_tape_sha256']==sha(folder/'sdk-tape.bin'),'RUN_CHANGED')
    data=[Reader((folder/(n+'-results.bin')).read_bytes()) for n in ['original','mql5']];require(all(r.take('3i')==(MAGIC,1,len(rows)) for r in data),'RESULT_HEADER');fail=[]
    for c in rows:
        records=[]
        for r in data:require(r.take('i')[0]==c['id'],'RESULT_ID');records.append(r.block())
        if records[0]!=records[1]:fail.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*records)) if x!=y),None),bytes=list(map(len,records))))
    require(all(r.pos==len(r.raw) for r in data),'RESULT_TRAILING');report=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:12],**SCOPE,limits=['Complete NFP branch and calendar/DST/cancel/filtered-close/send children; earlier evaluator inputs, initial frame, calendar/broker replies, allocation and genuine MT5 conversion results supplied. Send logging0, controlled simple order/position lists. No whole evaluator/EA, actual broker execution or allocation-fault proof.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(fail))
if __name__=='__main__':main()
