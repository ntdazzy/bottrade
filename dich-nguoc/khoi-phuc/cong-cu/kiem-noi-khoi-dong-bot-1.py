"""Compare continuous OnInit 0x3cab..0x5658 without resetting the join.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Reuses the two recorded-service harnesses. Entry-level and panel children are
recorders; original arithmetic, strings, history and the connecting code run.
"""
import argparse,copy,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1;MAGIC=0x4a4f4931

def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
tr=module('joined_trading','kiem-trang-thai-giao-dich-khoi-dong-bot-1.py')
tail=module('joined_tail','kiem-duoi-khoi-dong-bot-1.py')
boot,base=tr.boot,tr.base
require,sha,save,pub,Reader=tr.require,tr.sha,tr.save,tr.pub,tr.Reader
ALIASES={'Index':'P.strategy_index','StartLots':'P.native_62530','Calendar.hour':'P.calendar.hour',
         'TradeComment':'P.comment','TradeSymbol':'Inputs.symbol'}

def renamed(n):
    if n.startswith('P.'):return 'Panel.'+n[2:]
    if n.startswith('State.'):return 'TailState.'+n[6:]
    if n.startswith('BarTimes['):return 'TailBars'+n[8:]
    return ALIASES.get(n,n)
FIELDS=[(n,k,r) for n,k,r,_ in tr.FIELDS]
for n,k,r in tail.FIELDS:
    match=next((f for f in FIELDS if f[2]==r),None)
    require(match is None or match[:2]==(renamed(n),k),'SHARED_FIELD_TYPE')
    if match is None:FIELDS.append((renamed(n),k,r))
CREATE=[(renamed(n),k,r) for n,k,r in tail.CREATE_FIELDS]
OPEN,CLOSED=tail.OPEN_FIELDS,tail.CLOSED_FIELDS
TAIL_APIS={1:16,2:10,3:11,4:12,5:13,6:17,7:14,8:15,20:20,21:21,22:22}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
 native_continuous_post_preparation_executed=True,join_state_reset=False,
 entry_level_children_supplied=True,panel_children_recorded=True,
 terminal_replies_supplied=True,host_cpu_arithmetic=True,
 allocation_success_supplied=True,original_ex5_changed=False)

def cases():
    rows=[];trials=tr.cases();tails=tail.cases()
    def add(a,b,prefer_tail=False):
        c=copy.deepcopy(a);values={n:v for (n,_,_,_),v in zip(tr.FIELDS,a['fields'])}
        for n,_,r in tail.FIELDS:
            if prefer_tail or r not in {f[2] for f in tr.FIELDS}:values[renamed(n)]=b['values'][n]
        values['Inputs.symbol']=b['values']['TradeSymbol'] if prefer_tail else a['symbol']
        effects=[[api,num,next(i for i,f in enumerate(FIELDS) if f[2]==tr.FIELDS[index][2]),v] for api,num,index,v in a['effects']]
        effects += [[TAIL_APIS[api],num,next(i for i,f in enumerate(FIELDS) if f[2]==tail.FIELDS[index][2]),v] for api,num,index,v in b['effects']]
        c.update(id=len(rows),tag=('tail/' if prefer_tail else 'trading/')+(b['tag'] if prefer_tail else a['tag']),
                 values=values,effects=effects,info=b['info'],select=b['select'],total=b['total'],deals=copy.deepcopy(b['deals']),tail_times=b['times'])
        rows.append(c);return c
    default_tail=next(c for c in tails if c['values']['Show']==1 and c['values']['P.closed_star']==1 and c['info']==0 and c['values']['Tester']==1)
    for c in trials:add(c,default_tail)
    for c in tails:add(trials[0],c,True)
    for name,value in [('P.strategy_index',7),('P.native_62530',-.5),('LastTicket',0),('LastTicket',123456),
                       ('P.calendar.hour',23),('Magic',43),('Panel.lots[0]',9.75)]:
        c=add(trials[0],default_tail);c['tag']='join/live-'+name
        c['effects'].append([7,2,next(i for i,f in enumerate(FIELDS) if f[0]==name),value])
    for i in range(8):
        c=add(trials[0],default_tail);c['tag']='join/shared-volume-index'
        c['effects'].append([3,1,next(i for i,f in enumerate(FIELDS) if f[0]=='P.strategy_index'),i])
        c['values']['P.native_62530']=-.123
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<i',c['id'])
        for n,k,_ in FIELDS:raw+=boot.text(c['values'][n]) if k=='s' else struct.pack('<Q',tr.word(c['values'][n],k))
        for group in ['doubles','integers']:
            for row in c[group]:raw+=b''.join(struct.pack('<Q',boot.bits(v) if group=='doubles' else v&MASK) for v in row)
        for group in ['times','bars','bar_times']:raw+=b''.join(struct.pack('<Q',v&MASK) for v in c[group])
        raw+=struct.pack('<3Q',boot.bits(c['account']),*(boot.bits(v) for v in c['levels']))+struct.pack('<i',len(c['effects']))
        for api,n,f,v in c['effects']:raw+=struct.pack('<4Q',api,n,f,tr.word(v,FIELDS[f][1]))
        raw+=struct.pack('<4i',c['info'],c['select'],c['total'],len(c['deals']))
        for ticket,time,magic,volume in c['deals']:raw+=struct.pack('<4Q',ticket&MASK,time&MASK,magic&MASK,boot.bits(volume))
        raw+=struct.pack('<8Q',*(v&MASK for v in c['tail_times']))
    return bytes(raw)

TAIL_MOCKS=r'''
int InfoReply,SelectReply,TotalReply,DealCount,Selected,Result;ulong Deals[32][4];long TailTimes[8];
long MockTailSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();End(16,(ulong)prop,2,0,0,symbol);Effect(16);return 2;}
int MockInfo(const ENUM_MQL_INFO_INTEGER prop){Begin();End(10,(ulong)prop,(ulong)(long)InfoReply);Effect(10);return InfoReply;}
bool MockSelect(const datetime from,const datetime to){Begin();End(11,(ulong)from,(ulong)to,(ulong)SelectReply);Effect(11);return SelectReply!=0;}
int MockTotal(){Begin();End(12,(ulong)(long)TotalReply);Effect(12);return TotalReply;}
ulong MockTicket(const int index){Begin();Selected=index;ulong v=index>=0 && index<DealCount ? Deals[index][0] : 0;End(13,(ulong)(long)index,v);Effect(13);return v;}
datetime MockTailTime(){Begin();long v=TailTimes[Counts[17]%8];End(17,(ulong)v);Effect(17);return (datetime)v;}
long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop){Begin();long v=Selected>=0 && Selected<DealCount ? (long)Deals[Selected][prop==2 ? 1 : 2] : 0;End(14,ticket,(ulong)prop,(ulong)v);Effect(14);return v;}
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop){Begin();double v=Selected>=0 && Selected<DealCount ? Value(Deals[Selected][3]) : 0.;End(15,ticket,(ulong)prop,Bits(v));Effect(15);return v;}
void MockCreate(Bot1PanelCreationState &p,const Bot1NewsEvents &events,const Bot1NewsWindows &windows,Bot1NewsSelection &selection){Begin();End(20);@CREATE@ Effect(20);}
void MockOpen(const uchar &show,const uchar &tester,const int &seed,const string &symbol,const double &balance,const double &volume,
              const int &mode,const double &risk,const double &strategy_risk,const int &step,const Bot1NewsEvents &events,
              const Bot1NewsWindows &windows,Bot1NewsSelection &selection,ulong &ticket){Begin();End(21);@OPEN@ Effect(21);}
void MockClosed(const uchar &show,const uchar &tester,const int &seed,const string &symbol,double &wins,double &losses){Begin();End(22);@CLOSED@ Effect(22);}
'''
CALL='Bot1InitializeStartupPostPreparation(Inputs,P,Magic,Entry,Nfp,Interest,Cpi,Manager,Queue,Levels,MinimumSpread,FridayClosed,TailBars,Show,Tester,HistoryWindow,Seed,Balance,Panel,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,State,TailState)'

def render():
    code=tr.SCRIPT
    deps='#include "../../Include/bot-cua-toi-1/Bot1PanelCreation.mqh"\n#include "../../Include/bot-cua-toi-1/Bot1ClosedStatusPanel.mqh"\n'
    code=code.replace('Bot1PreparationInputs Inputs;',deps+'Bot1PreparationInputs Inputs;',1)
    code=code.replace('MinimumSpread,Volumes[8]','MinimumSpread')
    at=tail.SCRIPT.index('void MockCreate(');end=tail.SCRIPT.index('Bot1PanelCreationState P;')
    tail_headers=tail.SCRIPT[at:end].replace('MockSymbol','MockTailSymbol').replace('MockTime','MockTailTime')
    joined='#include "../../Include/bot-cua-toi-1/Bot1StartupPostPreparation.mqh"\n'
    globals_='Bot1PanelCreationState Panel;Bot1NewsEvents Events;Bot1NewsWindows Windows;Bot1NewsSelection Selection;Bot1StartupTailState TailState;\nint Seed,LastHour;double Balance,Wins,Losses;uchar Show,Tester,HistoryWindow;long TailBars[8];\n'
    code=code.replace('Bot1StartupTradingState State;',tail_headers+joined+globals_+'Bot1StartupTradingState State;')
    code=code.replace('Counts[10]','Counts[23]').replace('Volumes[i]','Panel.lots[i]')
    start=code.index('void Snapshot()');end=code.index('void Begin(){',start)
    snapshot='void Snapshot(){\n'+tail.statements(FIELDS)+'\nWord(TablesHash());Word(ErrorOverride<0 ? GetLastError() : (uint)ErrorOverride);\nif(Final){for(int i=0;i<500;i++)for(int j=0;j<3;j++)Word(Bits(Manager.table.rows[i][j]));for(int i=0;i<100;i++)for(int j=0;j<3;j++)Word(Bits(Queue.orders[i][j]));Word((ulong)(long)Result);}}\n'
    code=code[:start]+snapshot+code[end:]
    mocks=TAIL_MOCKS
    for token,fields in [('CREATE',tail.CREATE_FIELDS),('OPEN',OPEN),('CLOSED',CLOSED)]:
        passed=[]
        for n,k,r in fields:
            for old,new in [('P.','p.'),('Events.','events.'),('Windows.','windows.'),('Selection.','selection.')]:
                if n.startswith(old):n=new+n[len(old):];break
            passed.append((n,k,r))
        mocks=mocks.replace('@'+token+'@',tail.statements(passed))
    # Declarations must precede Snapshot; definitions can follow the recorder.
    declaration,definitions=mocks.split('long MockTailSymbol',1)
    code=code.replace('void Snapshot()',declaration+'\nvoid Snapshot()',1)
    code=code.replace('int OnStart()', 'long MockTailSymbol'+definitions+'\nint OnStart()',1)
    reads='\n'.join(n+'='+('ReadText(file)' if k=='s' else 'Value((ulong)FileReadLong(file))' if k=='d' else ('(uchar)' if k=='B' else '(uint)' if k=='I' else '(int)' if k=='i' else '(ulong)' if k=='Q' else '')+'FileReadLong(file)')+';' for n,k,_ in FIELDS)
    effects=''.join('case '+str(i)+':'+n+'='+('Value(v)' if k=='d' else '(uchar)v' if k=='B' else '(uint)v' if k=='I' else '(int)v' if k=='i' else '(long)v' if k=='q' else 'v')+';break;' for i,(n,k,_) in enumerate(FIELDS) if k!='s')
    code=code.replace('@READ@',reads).replace('@EFFECT@',effects).replace('      Inputs.symbol=ReadText(file);','')
    code=code.replace('      for(int i=0;i<8;i++)Panel.lots[i]=(double)(i+1)*.125;',
      '      InfoReply=FileReadInteger(file);SelectReply=FileReadInteger(file);TotalReply=FileReadInteger(file);DealCount=FileReadInteger(file);if(DealCount<0 || DealCount>32)return 8;\n      for(int i=0;i<DealCount;i++)for(int j=0;j<4;j++)Deals[i][j]=(ulong)FileReadLong(file);\n      for(int i=0;i<8;i++)TailTimes[i]=FileReadLong(file);Selected=-1;')
    old='Bot1InitializeTradingState(Inputs,P,Magic,Entry,Nfp,Interest,Cpi,Manager,Queue,Levels,MinimumSpread,FridayClosed,Volumes,LastTicket,State);'
    require(old in code,'JOIN_CALL_MARKER');code=code.replace(old,'Result='+CALL+';')
    code=code.replace('bot1-startup-trading','bot1-startup-joined').replace('0x54533131','0x4a4f4931')
    require('@' not in code,'UNEXPANDED_TEMPLATE');return code

class Native(tr.Native):
    values=tail.Native.values
    def __init__(self):
        super().__init__();self.tail_phase=False
        self.extra={0x7ff6846e0fd0:10,0x7ff6846f84f0:11,0x7ff6846f8810:12,0x7ff6846f8860:13,0x7ff6846f8940:14,0x7ff6846f88b0:15,
                    self.base+0x8320:20,self.base+0xe1b0:21,self.base+0xffb0:22}
        for address,api in self.extra.items():
            if api<20:
                if not any(a<=address<=b for a,b,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
                self.m.mem_write(address,b'\xc3');self.sdk[address]=api
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.at_join,begin=self.base+0x4e77,end=self.base+0x4e77)
    def at_join(self,m,address,size,user):self.tail_phase=True;self.joins+=1
    def state(self,final=False):
        table=bytes(self.m.mem_read(self.base+0x62590,12000))+bytes(self.m.mem_read(self.base+0x65470,2400));h=0xcbf29ce484222325
        for (v,) in struct.iter_unpack('<Q',table):h=((h^v)*0x100000001b3)&MASK
        raw=self.values(FIELDS)+struct.pack('<QQ',h,struct.unpack('<I',self.m.mem_read(self.base+0x6a410,4))[0])
        return raw+(table+struct.pack('<Q',self.m.reg_read(self.x.UC_X86_REG_RAX)) if final else b'')
    def effect(self,api):
        for a,n,f,v in self.effects:
            if a==api and n==self.counts[api]:
                _,k,off=FIELDS[f];size=struct.calcsize('<'+k);self.m.mem_write(self.base+off,(tr.word(v,k)&((1<<(size*8))-1)).to_bytes(size,'little'))
    def service(self,m,address,size,user):
        api=self.extra.get(address)
        if self.tail_phase and address in [0x7ff6846e2970,0x7ff6846f1c40]:api=16 if address==0x7ff6846e2970 else 17
        if api is None:
            api=7 if address in [self.base+0x265a0,self.base+0x26960] else self.sdk[address]
            super().service(m,address,size,user);self.effect(api);return
        r=self.tape;expected=r.block();actual=self.state()
        require(expected==actual,'JOIN_STATE '+str((self.case['id'],api,next((i for i,(a,b) in enumerate(zip(expected,actual)) if a!=b),None))))
        kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I');require(kind==api,'JOIN_API_ORDER')
        x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))
        if api<20:require(reg('RCX')==self.gate['ctx'],'JOIN_CONTEXT')
        if api==16:require(reg('R8')==args[0]==17 and texts==[self.read_text(reg('RDX')),None],'TAIL_SYMBOL_ARGS');reply=args[1]
        elif api==10:require(reg('RDX')==args[0]==6,'TAIL_INFO_ARGS');reply=args[1]
        elif api==11:require([reg('RDX'),reg('R8')]==args[:2]==[0,0x7fffffff],'TAIL_SELECT_ARGS');reply=args[2]
        elif api==12:reply=args[0]
        elif api==13:require(reg('RDX')&0xffffffff==args[0]&0xffffffff,'TAIL_TICKET_ARGS');reply=args[1]
        elif api==17:require(reg('RDX')==0,'TAIL_TIME_ARGS');reply=args[0]
        elif api in [14,15]:require([reg('RDX'),reg('R8')]==args[:2],'TAIL_PROPERTY_ARGS');reply=args[2]
        else:
            fields={20:CREATE,21:OPEN,22:CLOSED}[api];packed=bytearray()
            for _,k,_ in fields:packed+=boot.text(r.text()) if k=='s' else struct.pack('<Q',r.take('Q')[0])
            require(bytes(packed)==self.values(fields),'JOIN_PANEL_ARGS');reply=0
        self.counts[api]+=1;self.effect(api);self.calls+=1
        if api==15:m.mem_write(self.base+0x6a448,struct.pack('<Q',reply))
        else:m.reg_write(x.UC_X86_REG_RAX,reply)
        m.mem_write(self.base+0x6a410,struct.pack('<I',error))
        if api>=20:
            sp=reg('RSP');dest=struct.unpack('<Q',m.mem_read(sp,8))[0];m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,dest)
    def run(self,c,tape):
        self.case=dict(c,effects=[]);self.effects=c['effects'];self.tape=Reader(tape);self.counts={i:0 for i in range(23)}
        self.calls=self.cpu_calls=self.joins=0;self.tail_phase=False;self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n,k,off in FIELDS:
            v=c['values'][n]
            if k=='s':self.put_text(off,v)
            else:
                size=struct.calcsize('<'+k);m.mem_write(self.base+off,(tr.word(v,k)&((1<<(size*8))-1)).to_bytes(size,'little'))
        for off,count,scale in [(0x62590,1500,.125),(0x65470,300,.25)]:m.mem_write(self.base+off,b''.join(struct.pack('<d',(i+1)*scale) for i in range(count)))
        m.mem_write(self.base+0x6a410,bytes(4))
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        sp=0x5001fc00;m.mem_write(sp,bytes(0x300));m.mem_write(sp+0xe8,struct.pack('<Q',0x60000000))
        for n,v in [('RSP',sp),('RBP',self.base+0x6a448),('R12',self.print_api),('R14',0x7ff6846f1c40),('R15',self.base+0x5c0)]:m.reg_write(getattr(x,'UC_X86_REG_'+n),v)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.emu_start(self.base+0x3cab,0x60000000,timeout=5000000,count=1500000)
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000 and self.tape.pos==len(tape) and self.joins==1,'JOIN_NOT_FINISHED')
        return self.state(True)

def identity():
    src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupPostPreparationCheck.mq5'
    helpers=dict(tr.identity()['helpers_sha256']);helpers.update(tail.identity()['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=base.base.validation.original_hash(1),native_init_sha256=boot.INIT_SHA,
                sources_sha256={p.relative_to(src).as_posix():sha(p) for p in pub.closure(script,src)},helpers_sha256=helpers)

def execute(folder,build):
    mt=ROOT.parent/'.local/mt5-bot1-thread-20261025';receipt=ROOT/'bot-cua-toi-1/bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script='Scripts/bot-cua-toi-1/Bot1StartupPostPreparationCheck.mq5'
    require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,h in identity()['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
    files=mt/'MQL5/Files/bot1-startup-joined'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('startup-joined-'+folder.name+'.set');ini=mt/('startup-joined-'+folder.name+'.ini');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16')
    ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1StartupPostPreparationCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(cases())),'SCRIPT_FAILED');return files,receipt

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':
        path=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1StartupPostPreparationCheck.mq5';require(not path.exists(),'SOURCE_EXISTS');path.write_text(render(),encoding='utf-8',newline='\n');print(path);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases();current=identity();folder=ROOT/'bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the'/a.run;head=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),fields=len(FIELDS))));return
    before=json.loads((folder/'baseline.json').read_text());require(all(before[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build,'BUILD_REQUIRED');files,receipt=execute(folder,a.build)
        for name in ['mql5-results.bin','sdk-tape.bin','script-status.bin']:
            with (folder/name).open('xb') as out:out.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        r=Reader((folder/'sdk-tape.bin').read_bytes());require(r.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Native();raw=bytearray(head);calls=cpu=joins=0
        try:
            for c in rows:
                require(r.take('i')[0]==c['id'],'TAPE_CASE');v=o.run(c,r.block());raw+=struct.pack('<2i',c['id'],len(v))+v;calls+=o.calls;cpu+=o.cpu_calls;joins+=o.joins
        finally:o.close()
        require(r.pos==len(r.raw),'TAPE_TRAILING')
        with (folder/'original-results.bin').open('xb') as out:out.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),sdk_calls=calls,cpu_arithmetic_calls=cpu,joins=joins,**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=calls,cpu_arithmetic_calls=cpu,joins=joins)));return
    readers=[]
    for name in ['original','mql5']:
        record=json.loads((folder/(name+'-run.json')).read_text());require(all(record[k]==v for k,v in current.items()) and record['result_sha256']==sha(folder/(name+'-results.bin')) and record['sdk_tape_sha256']==sha(folder/'sdk-tape.bin'),'RUN_CHANGED')
        r=Reader((folder/(name+'-results.bin')).read_bytes());require(r.take('3i')==(MAGIC,1,len(rows)),'RESULT_HEADER');readers.append(r)
    bad=[]
    for c in rows:
        values=[]
        for r in readers:require(r.take('i')[0]==c['id'],'RESULT_CASE');values.append(r.block())
        if values[0]!=values[1]:bad.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*values)) if x!=y),None)))
    require(all(r.pos==len(r.raw) for r in readers),'RESULT_TRAILING')
    report=dict(cases=len(rows),matched=len(rows)-len(bad),failed=len(bad),first_failures=bad[:12],fields=len(FIELDS),table_cells=1800,**SCOPE,
      limits=['Continuous after first preparation through normal return only. Two entry-level and three panel children recorded; terminal replies and allocation success supplied. Zero-unit, allocation failures, earlier OnInit and full EA remain unverified.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(bad))
if __name__=='__main__':main()
