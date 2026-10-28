"""Compare bot-1 OnInit tail 0x4e77 through its real return.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Native strings and history loop execute. The three panel children are recorders;
their complete argument sets and mutations are checked, not their own bodies.
"""
import argparse,copy,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x54414931;MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
boot=module('tail_boot','kiem-ngu-canh-khoi-dong-bot-1.py');panel=module('tail_panel','kiem-tao-bang-bot-1-3.py')
base=boot.base;require,sha,save,pub,Reader=base.require,base.sha,base.save,base.pub,base.Reader
FIELDS=panel.fields(1)+[
 ('Index','I',0x678f4),('StartLots','d',0x62530),('Calendar.hour','i',0x6779c),
 ('LastHour','i',0x67448),('Show','B',0x6a528),('Tester','B',0x6a530),
 ('HistoryWindow','B',0x623c5),('Magic','i',0x6246c),('Seed','i',0x6a610),
 ('Balance','d',0x6a320),('LastTicket','Q',0x677f8),('Wins','d',0x67900),('Losses','d',0x67908),
 ('TradeComment','s',0x62470),('TradeSymbol','s',0x67918),
 ('State.buy_first','s',0x673f8),('State.buy_second','s',0x67408),
 ('State.sell_first','s',0x67418),('State.sell_second','s',0x67428)]+[(f'BarTimes[{i}]','q',0x66430+8*i) for i in range(8)]
CREATE_FIELDS=panel.fields(1)
OPEN_FIELDS=[('show','B',0x6a528),('tester','B',0x6a530),('seed','i',0x6a610),('symbol','s',0x67918),
 ('balance','d',0x6a320),('volume','d',0x66a80),('mode','i',0x6a748),('risk','d',0x6a750),
 ('strategy_risk','d',0x6a758),('step','i',0x6a768)]+[(n,k,r) for n,k,r in CREATE_FIELDS if not n.startswith('P.')]+[('ticket','Q',0x677f8)]
CLOSED_FIELDS=[('show','B',0x6a528),('tester','B',0x6a530),('seed','i',0x6a610),('symbol','s',0x67918),('wins','d',0x67900),('losses','d',0x67908)]
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
 native_startup_tail_executed=True,native_string_helpers_executed=True,native_history_scan_executed=True,
 panel_children_recorded=True,terminal_replies_supplied=True,allocation_success_supplied=True,original_ex5_changed=False)
def word(v,k):return boot.bits(v) if k=='d' else int(v)&MASK
def cases():
    defaults=copy.deepcopy(panel.cases(1)[0]['values']);defaults.update({'P.mode':0,'Index':0,'StartLots':.25,'Calendar.hour':17,
      'LastHour':99,'Show':1,'Tester':1,'HistoryWindow':1,'Magic':42,'Seed':9000,'Balance':12345.5,'LastTicket':777,
      'Wins':12.,'Losses':3.,'TradeComment':'Gold','TradeSymbol':'XAUUSD.a','State.buy_first':'oldB1','State.buy_second':None,
      'State.sell_first':'oldS1','State.sell_second':''})
    for i in range(8):defaults[f'BarTimes[{i}]']=100+i;defaults[f'P.lots[{i}]']=(i+1)*.125
    now=1790000000;out=[]
    def add(tag,updates=None,**kwargs):
        c=dict(id=len(out),tag=tag,values=copy.deepcopy(defaults),info=0,select=1,total=2,
               deals=[[10,now-100,42,.5],[11,now,42,.75]],times=[now]*8,effects=[])
        c['values'].update(updates or {});c.update(kwargs);out.append(c);return c
    for show in [0,1,2,255]:
        for star in [0,1,2,255]:
            for info in [0,1,2]:
                for tester in [0,1,255]:add('panel-history-gates',{'Show':show,'P.closed_star':star,'Tester':tester},info=info)
    for window in [0,1,2,255]:
        for delta in [-1,0,1]:
            for magic in [41,42,43]:
                for ticket in [0,11]:
                    boundary=now-(7776000 if window else 0)
                    add('history-cutoff-and-zero-ticket',{'HistoryWindow':window},total=1,deals=[[ticket,boundary+delta,magic,.5]])
    for total in [-2147483648,-2,-1,0,1,2,3]:
        add('history-total-width',total=total,deals=[[1,0,42,.25],[2,now,43,.5],[3,now+1,42,.75]])
    for select in [0,1]:add('history-selection',select=select)
    for comment in [None,'','Gold','Vàng🚀','x'*300]:
        for symbol in [None,'','XAUUSD.a']:add('utf16-and-empty',{'TradeComment':comment,'TradeSymbol':symbol,'Show':0})
    for index in range(8):
        for lots in [-1.,-0.,0.,.25,100.,boot.number(0x7ff8000000000041)]:
            add('volume-clamp-and-index',{'Index':index,'StartLots':lots,'Show':0})
    for hour in [-2147483648,-1,0,23,2147483647]:add('cached-hour',{'Calendar.hour':hour,'Show':0})
    for clock in [-(1<<63),-(1<<63)+7775999,(1<<63)-1]:
        add('time-subtraction-wrap',times=[clock]*8,total=1,deals=[[0,clock,42,.5]])
    for api,n,name,value in [(1,1,'Index',7),(1,1,'StartLots',.99),(1,1,'P.closed_star',0),
                            (2,1,'Tester',0),(6,1,'HistoryWindow',0),(7,2,'Magic',43),
                            (20,1,'Show',0),(20,1,'Seed',101),(20,1,'P.mode',999),
                            (20,1,'P.lots[0]',9.75),(20,1,'Selection.block_time',123),
                            (21,1,'Wins',19.),(22,1,'Losses',23.)]:
        c=add('live-state-between-calls');c['effects']=[[api,n,next(i for i,f in enumerate(FIELDS) if f[0]==name),value]]
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<i',c['id'])
        for n,k,_ in FIELDS:raw+=boot.text(c['values'][n]) if k=='s' else struct.pack('<Q',word(c['values'][n],k))
        raw+=struct.pack('<4i',c['info'],c['select'],c['total'],len(c['deals']))
        for ticket,time,magic,volume in c['deals']:raw+=struct.pack('<4Q',ticket&MASK,time&MASK,magic&MASK,boot.bits(volume))
        raw+=struct.pack('<8Q',*(v&MASK for v in c['times']))+struct.pack('<i',len(c['effects']))
        for api,n,f,v in c['effects']:raw+=struct.pack('<4Q',api,n,f,word(v,FIELDS[f][1]))
    return bytes(raw)
SCRIPT=r'''#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1PanelCreation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ClosedStatusPanel.mqh"
void MockCreate(Bot1PanelCreationState &p,const Bot1NewsEvents &events,const Bot1NewsWindows &windows,Bot1NewsSelection &selection);
void MockOpen(const uchar &show,const uchar &tester,const int &seed,const string &symbol,const double &balance,const double &volume,
              const int &mode,const double &risk,const double &strategy_risk,const int &step,const Bot1NewsEvents &events,
              const Bot1NewsWindows &windows,Bot1NewsSelection &selection,ulong &ticket);
void MockClosed(const uchar &show,const uchar &tester,const int &seed,const string &symbol,double &wins,double &losses);
long MockSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);int MockInfo(const ENUM_MQL_INFO_INTEGER prop);
bool MockSelect(const datetime from,const datetime to);int MockTotal();ulong MockTicket(const int index);
datetime MockTime();long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop);
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop);
#define Bot1CreateInfoPanel MockCreate
#define Bot1UpdateOpenStatusPanel MockOpen
#define Bot1UpdateClosedStatusPanel MockClosed
#define SymbolInfoInteger MockSymbol
#define MQLInfoInteger MockInfo
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define TimeCurrent MockTime
#define HistoryDealGetInteger MockDealInteger
#define HistoryDealGetDouble MockDealDouble
#include "../../Include/bot-cua-toi-1/Bot1StartupTail.mqh"
#undef Bot1CreateInfoPanel
#undef Bot1UpdateOpenStatusPanel
#undef Bot1UpdateClosedStatusPanel
#undef SymbolInfoInteger
#undef MQLInfoInteger
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef TimeCurrent
#undef HistoryDealGetInteger
#undef HistoryDealGetDouble
Bot1PanelCreationState P;Bot1NewsEvents Events;Bot1NewsWindows Windows;Bot1NewsSelection Selection;Bot1StartupTailState State;
MqlDateTime Calendar;uint Index;double StartLots,Balance,Wins,Losses;int LastHour,Magic,Seed;uchar Show,Tester,HistoryWindow;
string TradeComment,TradeSymbol;ulong LastTicket;long BarTimes[8];
union Number{double value;ulong word;};
ulong Bits(const double v){Number n;n.value=v;return n.word;}double Value(const ulong v){Number n;n.word=v;return n.value;}
int Tape,ErrorOverride=-1,Counts[23],InfoReply,SelectReply,TotalReply,DealCount,Selected,EffectCount,Result;
ulong Deals[32][4],Effects[32][4];long Times[8];bool Final=false;
void Word(const ulong v){FileWriteLong(Tape,(long)v);}
void Text(const string v){int n=v==NULL ? -1 : StringLen(v);FileWriteInteger(Tape,n);if(n>0)FileWriteString(Tape,v,n);}
string ReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void Snapshot(){@STATE@ Word(ErrorOverride<0 ? GetLastError() : (uint)ErrorOverride);if(Final)Word((ulong)(long)Result);}
void Begin(){ulong at=FileTell(Tape);FileWriteInteger(Tape,0);Snapshot();ulong end=FileTell(Tape);FileSeek(Tape,(long)at,SEEK_SET);FileWriteInteger(Tape,(int)(end-at-4));FileSeek(Tape,(long)end,SEEK_SET);}
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const string value=NULL){FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Text(value);FileWriteInteger(Tape,(int)GetLastError());}
void Effect(const int api){int n=++Counts[api];for(int i=0;i<EffectCount;i++){if((int)Effects[i][0]!=api || (int)Effects[i][1]!=n)continue;ulong v=Effects[i][3];switch((int)Effects[i][2]){@EFFECT@}}}
long MockSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();End(1,(ulong)prop,2,0,symbol);Effect(1);return 2;}
int MockInfo(const ENUM_MQL_INFO_INTEGER prop){Begin();End(2,(ulong)prop,(ulong)(long)InfoReply);Effect(2);return InfoReply;}
bool MockSelect(const datetime from,const datetime to){Begin();End(3,(ulong)from,(ulong)to,(ulong)SelectReply);Effect(3);return SelectReply!=0;}
int MockTotal(){Begin();End(4,(ulong)(long)TotalReply);Effect(4);return TotalReply;}
ulong MockTicket(const int index){Begin();Selected=index;ulong v=index>=0 && index<DealCount ? Deals[index][0] : 0;End(5,(ulong)(long)index,v);Effect(5);return v;}
datetime MockTime(){Begin();long v=Times[Counts[6]%8];End(6,(ulong)v);Effect(6);return (datetime)v;}
long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop){Begin();long v=Selected>=0 && Selected<DealCount ? (long)Deals[Selected][prop==2 ? 1 : 2] : 0;End(7,ticket,(ulong)prop,(ulong)v);Effect(7);return v;}
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop){Begin();double v=Selected>=0 && Selected<DealCount ? Value(Deals[Selected][3]) : 0.;End(8,ticket,(ulong)prop,Bits(v));Effect(8);return v;}
void MockCreate(Bot1PanelCreationState &p,const Bot1NewsEvents &events,const Bot1NewsWindows &windows,Bot1NewsSelection &selection){Begin();End(20);@CREATE@ Effect(20);}
void MockOpen(const uchar &show,const uchar &tester,const int &seed,const string &symbol,const double &balance,const double &volume,
              const int &mode,const double &risk,const double &strategy_risk,const int &step,const Bot1NewsEvents &events,
              const Bot1NewsWindows &windows,Bot1NewsSelection &selection,ulong &ticket){Begin();End(21);@OPEN@ Effect(21);}
void MockClosed(const uchar &show,const uchar &tester,const int &seed,const string &symbol,double &wins,double &losses){Begin();End(22);@CLOSED@ Effect(22);}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-startup-tail\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x54414931 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),tapes=FileOpen(folder+"sdk-tape.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE || tapes==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);FileWriteInteger(tapes,magic);FileWriteInteger(tapes,version);FileWriteInteger(tapes,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);@READ@
      InfoReply=FileReadInteger(file);SelectReply=FileReadInteger(file);TotalReply=FileReadInteger(file);DealCount=FileReadInteger(file);if(DealCount<0 || DealCount>32)return 8;
      for(int i=0;i<DealCount;i++)for(int j=0;j<4;j++)Deals[i][j]=(ulong)FileReadLong(file);
      for(int i=0;i<8;i++)Times[i]=FileReadLong(file);EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>32)return 8;
      for(int i=0;i<EffectCount;i++)for(int j=0;j<4;j++)Effects[i][j]=(ulong)FileReadLong(file);
      ArrayInitialize(Counts,0);Selected=-1;string part=folder+"tape-"+IntegerToString(id)+".bin";Tape=FileOpen(part,FILE_WRITE|FILE_BIN);if(Tape==INVALID_HANDLE)return 5;
      ResetLastError();ErrorOverride=-1;Final=false;
      Result=Bot1InitializeStartupTail(TradeComment,TradeSymbol,Index,StartLots,Calendar,BarTimes,Show,Tester,HistoryWindow,Magic,Seed,Balance,P,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,State);
      int error=GetLastError();FileClose(Tape);int section=FileOpen(part,FILE_READ|FILE_BIN);if(section==INVALID_HANDLE)return 6;int size=(int)FileSize(section);uchar raw[];ArrayResize(raw,size);if(size>0)FileReadArray(section,raw);FileClose(section);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0)FileWriteArray(tapes,raw);
      FileWriteInteger(output,id);Tape=output;ErrorOverride=error;Final=true;Begin();
   }
   if(FileTell(file)!=FileSize(file))return 9;FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
def statements(fields):
    return '\n'.join('Text('+n+');' if k=='s' else 'Word('+('Bits('+n+')' if k=='d' else '(ulong)(long)'+n)+');' for n,k,_ in fields)
def render():
    reads='\n'.join(n+'='+('ReadText(file)' if k=='s' else 'Value((ulong)FileReadLong(file))' if k=='d' else ('(uchar)' if k=='B' else '(int)' if k=='i' else '(uint)' if k=='I' else '(ulong)' if k=='Q' else '')+'FileReadLong(file)')+';' for n,k,_ in FIELDS)
    effects=''.join('case '+str(i)+':'+n+'='+('Value(v)' if k=='d' else '(uchar)v' if k=='B' else '(int)v' if k=='i' else '(uint)v' if k=='I' else '(long)v' if k=='q' else 'v')+';break;' for i,(n,k,_) in enumerate(FIELDS) if k!='s')
    code=SCRIPT.replace('@STATE@',statements(FIELDS)).replace('@READ@',reads).replace('@EFFECT@',effects)
    for token,fields in [('CREATE',CREATE_FIELDS),('OPEN',OPEN_FIELDS),('CLOSED',CLOSED_FIELDS)]:
        args=[]
        for n,k,r in fields:
            for a,b in [('P.','p.'),('Events.','events.'),('Windows.','windows.'),('Selection.','selection.')]:
                if n.startswith(a):n=b+n[len(a):];break
            args.append((n,k,r))
        code=code.replace('@'+token+'@',statements(args))
    return code
def generate():
    path=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1StartupTailCheck.mq5';require(not path.exists(),'SOURCE_EXISTS')
    path.write_text(render(),encoding='utf-8',newline='\n');print(path)
class Native(boot.Native):
    def __init__(self):
        super().__init__();self.sdk={0x7ff6846e2970:1,0x7ff6846e0fd0:2,0x7ff6846f84f0:3,
          0x7ff6846f8810:4,0x7ff6846f8860:5,0x7ff6846f1c40:6,0x7ff6846f8940:7,0x7ff6846f88b0:8}
        self.children={self.base+0x8320:20,self.base+0xe1b0:21,self.base+0xffb0:22}
        for address in self.sdk:
            if not any(a<=address<=b for a,b,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        for address in self.children:self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
    def call(self,m,address,size,user):
        if address in getattr(self,'sdk',{}):return
        return super().call(m,address,size,user)
    def values(self,fields):
        raw=bytearray()
        for _,kind,off in fields:
            if kind=='s':raw+=boot.text(self.read_text(self.base+off))
            else:
                fmt='Q' if kind=='d' else kind;v=struct.unpack('<'+fmt,self.m.mem_read(self.base+off,struct.calcsize('<'+fmt)))[0];raw+=struct.pack('<Q',v&MASK)
        return bytes(raw)
    def state(self):return self.values(FIELDS)+struct.pack('<Q',struct.unpack('<I',self.m.mem_read(self.base+0x6a410,4))[0])
    def service(self,m,address,size,user):
        api=self.children.get(address,self.sdk.get(address));r=self.tape;expected=r.block();actual=self.state()
        require(actual==expected,'STATE_BEFORE_TAIL_API '+str((self.case['id'],api,next((i for i,(a,b) in enumerate(zip(actual,expected)) if a!=b),None))))
        kind,*args=r.take('i3Q');text=r.text();error,=r.take('I');require(kind==api,'TAIL_API_ORDER');x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))
        if api<20:require(reg('RCX')==self.gate['ctx'],'TAIL_CONTEXT')
        if api==1:require(reg('R8')==args[0]==17 and text==self.read_text(reg('RDX')),'SYMBOL_ARGS');reply=args[1]
        elif api==2:require(reg('RDX')==args[0]==6 and text is None,'MQL_INFO_ARGS');reply=args[1]
        elif api==3:require([reg('RDX'),reg('R8')]==args[:2]==[0,0x7fffffff],'HISTORY_SELECT_ARGS');reply=args[2]
        elif api==4:reply=args[0]
        elif api==5:require((reg('RDX')&0xffffffff)==(args[0]&0xffffffff),'HISTORY_TICKET_ARGS');reply=args[1]
        elif api==6:require(reg('RDX')==0,'TIME_ARGS');reply=args[0]
        elif api in [7,8]:require([reg('RDX'),reg('R8')]==args[:2],'HISTORY_PROPERTY_ARGS');reply=args[2]
        else:
            fields={20:CREATE_FIELDS,21:OPEN_FIELDS,22:CLOSED_FIELDS}[api];packed=bytearray()
            for _,k,_ in fields:packed+=boot.text(r.text()) if k=='s' else struct.pack('<Q',r.take('Q')[0])
            require(bytes(packed)==self.values(fields),'PANEL_CHILD_ARGS '+str(api));reply=0
        self.counts[api]+=1
        for a,n,f,v in self.case['effects']:
            if a==api and n==self.counts[api]:
                _,k,off=FIELDS[f];size_=struct.calcsize('<'+k);m.mem_write(self.base+off,(word(v,k)&((1<<(8*size_))-1)).to_bytes(size_,'little'))
        if api==8:m.mem_write(self.base+0x6a448,struct.pack('<Q',reply))
        else:m.reg_write(x.UC_X86_REG_RAX,reply)
        m.mem_write(self.base+0x6a410,struct.pack('<I',error));self.calls+=1
        if api>=20:
            sp=reg('RSP');dest=struct.unpack('<Q',m.mem_read(sp,8))[0];m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,dest)
    def run(self,c,tape):
        self.case=c;self.tape=Reader(tape);self.counts={i:0 for i in list(range(1,9))+[20,21,22]};self.calls=0;self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n,k,off in FIELDS:
            v=c['values'][n]
            if k=='s':self.put_text(off,v)
            else:
                size_=struct.calcsize('<'+k);m.mem_write(self.base+off,(word(v,k)&((1<<(8*size_))-1)).to_bytes(size_,'little'))
        m.mem_write(self.base+0x6a410,bytes(4))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        sp=0x5001fc00;m.mem_write(sp,bytes(0x300));m.mem_write(sp+0xe8,struct.pack('<Q',0x60000000))
        for n,v in [('RSP',sp),('RCX',sp+0x40),('RDX',self.base+0x62470),('R9',self.base+0x5e640),('R12',0x7ff6846e2970),('R14',self.base),('R15',self.base+0x5c0),('RBP',self.base+0x6a448)]:m.reg_write(getattr(x,'UC_X86_REG_'+n),v)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.emu_start(self.base+0x4e77,0x60000000,timeout=3000000,count=1000000)
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000 and self.tape.pos==len(tape),'TAIL_NOT_FINISHED');return self.state()+struct.pack('<Q',m.reg_read(x.UC_X86_REG_RAX))
def identity():
    src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupTailCheck.mq5'
    helpers=[Path(__file__),Path(boot.__file__),Path(panel.__file__),Path(base.__file__),Path(boot.history.__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py']
    return dict(original_ex5_sha256=base.base.validation.original_hash(1),native_init_sha256=boot.INIT_SHA,sources_sha256={p.relative_to(src).as_posix():sha(p) for p in pub.closure(script,src)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def execute(folder,build):
    mt=ROOT.parent/'.local/mt5-bot1-thread-20261025';receipt=ROOT/'bot-cua-toi-1/bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script='Scripts/bot-cua-toi-1/Bot1StartupTailCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,h in identity()['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/'MQL5/Files/bot1-startup-tail'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('startup-tail-'+folder.name+'.set');ini=mt/('startup-tail-'+folder.name+'.ini');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1StartupTailCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(cases())),'SCRIPT_FAILED');return files,receipt
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);ap.add_argument('run',nargs='?');ap.add_argument('--build');a=ap.parse_args()
    if a.mode=='generate':generate();return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases();current=identity();folder=ROOT/'bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the'/a.run;head=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    before=json.loads((folder/'baseline.json').read_text());require(all(before[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build,'BUILD_REQUIRED');files,receipt=execute(folder,a.build)
        for name in ['mql5-results.bin','sdk-tape.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        r=Reader((folder/'sdk-tape.bin').read_bytes());require(r.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Native();raw=bytearray(head);calls=0
        try:
            for c in rows:
                require(r.take('i')[0]==c['id'],'TAPE_CASE');v=o.run(c,r.block());raw+=struct.pack('<2i',c['id'],len(v))+v;calls+=o.calls
        finally:o.close()
        require(r.pos==len(r.raw),'TAPE_TRAILING')
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),sdk_calls=calls,**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=calls)));return
    readers=[]
    for name in ['original','mql5']:
        run=json.loads((folder/(name+'-run.json')).read_text());require(all(run[k]==v for k,v in current.items()) and run['result_sha256']==sha(folder/(name+'-results.bin')) and run['sdk_tape_sha256']==sha(folder/'sdk-tape.bin'),'RUN_CHANGED');r=Reader((folder/(name+'-results.bin')).read_bytes());require(r.take('3i')==(MAGIC,1,len(rows)),'RESULT_HEADER');readers.append(r)
    bad=[]
    for c in rows:
        values=[]
        for r in readers:require(r.take('i')[0]==c['id'],'RESULT_CASE');values.append(r.block())
        if values[0]!=values[1]:bad.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*values)) if x!=y),None)))
    require(all(r.pos==len(r.raw) for r in readers),'RESULT_TRAILING');report=dict(cases=len(rows),matched=len(rows)-len(bad),failed=len(bad),first_failures=bad[:12],fields=len(FIELDS),**SCOPE,limits=['Tail only. Initial temporary strings empty and allocation successful. Three panel children recorded with supplied changes; their bodies have separate evidence. Not full initialization or EA.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(bad))
if __name__=='__main__':main()
