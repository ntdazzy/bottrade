"""Compare OnInit after preparation through initial order/virtual-stop tables.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Original 0x3cab..0x4e77 executes unchanged, including its out-of-line branches.
Only the two entry-level children and terminal replies are supplied.
"""
import argparse,ctypes,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1;MAGIC=0x54533131
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
boot=module('trading_startup_host','kiem-ngu-canh-khoi-dong-bot-1.py');base=boot.base
require,sha,save,pub,Reader=base.require,base.sha,base.save,base.pub,base.Reader
FIELDS=[
 ('P.native_62414','i',0x62414,1),('State.native_62555','B',0x62555,173),('P.strategy_index','I',0x678f4,7),
 ('P.entry_frame','i',0x6242c,16385),('P.native_6248c','i',0x6248c,1),
 ('P.tick.ask','d',0x67760,2002.),('P.tick.bid','d',0x67758,2000.),('P.spread','d',0x62560,-99.),
 ('P.native_62530','d',0x62530,.123),('P.unit','d',0x66d98,.1),('P.min_change','d',0x62520,.01),
 ('P.stop_min_price','d',0x66a70,77.),('P.freeze_min_price','d',0x67468,88.),
 ('P.stop_distance','d',0x62498,20.),('P.target_distance','d',0x624a0,30.),
 ('P.trigger_distance','d',0x624c8,5.),('P.locked_distance','d',0x624d0,8.),
 ('P.freeze_buffer','i',0x623e0,1),('P.trail_distance','d',0x624a8,1.),
 ('P.native_624f8','d',0x624f8,1.),('P.native_62500','d',0x62500,1.),
 ('P.gap_points','d',0x62440,1.),('P.older_width','i',0x62430,0),('P.recent_width','i',0x62434,-2),
 ('P.expiration_hours','i',0x62468,24),('P.virtual_expiration','B',0x62419,0),
 ('P.expiration_seconds','I',0x66da0,77),('P.expiration','q',0x67450,88),
 ('Nfp.notice','B',0x67434,173),('Nfp.blocked','B',0x67488,173),
 ('Interest.blocked','B',0x67489,173),('Cpi.blocked','B',0x6748a,173),
 ('State.week_bar','q',0x67478,77),('P.max_spread','d',0x623d8,.6),('MinimumSpread','d',0x62558,77.),
 ('Inputs.entry.confirmation_frame','i',0x6227c,15),('Magic','i',0x6246c,42),
 ('P.last_shift','i',0x62438,20),('P.buy_offset','d',0x62448,.3),('P.sell_offset','d',0x62450,.4),
 ('P.nearby_radius','d',0x62460,.5),('LastTicket','Q',0x677f8,999),
 ('Entry.candidate_buy','d',0x67440,91.),('Entry.candidate_sell','d',0x67438,92.),
 ('Entry.rounded_buy','d',0x62570,9.),('Entry.rounded_sell','d',0x62578,8.),
 ('Levels.blocked','B',0x67458,173),('Manager.counter','i',0x673f0,77),
 ('State.timed_delay_seconds','i',0x6745c,88),('Manager.current_stop','d',0x62580,66.),
 ('P.native_62538','d',0x62538,99.),('Manager.table.guard','B',0x66410,1),
 ('Queue.enabled','B',0x66420,1),('FridayClosed','B',0x67460,173)]
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
 native_post_preparation_executed=True,entry_level_children_supplied=True,
 terminal_replies_supplied=True,host_cpu_arithmetic=True,original_ex5_changed=False)
def word(value,kind):return boot.bits(value) if kind=='d' else int(value)&MASK
def cases():
    out=[]
    def add(tag,changes=None,**kw):
        c=dict(id=len(out),tag=tag,fields=[d for _,_,_,d in FIELDS],symbol='XAUUSD.α',
               doubles=[[.01]*8,[.01]*8,[100.]*8,[.01]*8],integers=[[2]*8,[3]*8,[2]*8],
               times=[1790000000+i for i in range(8)],bars=[100,101],bar_times=[200,201,202],
               account=5000.,levels=[2010.12345,1990.12345],effects=[])
        for name,value in (changes or {}).items():c['fields'][next(i for i,r in enumerate(FIELDS) if r[0]==name)]=value
        c.update(kw);out.append(c);return c
    for guard in [0,1,2,255]:
        for queue in [0,1,2,255]:
            for valid in [-1,0,1]:add('guards-and-preparation-result',{'Manager.table.guard':guard,'Queue.enabled':queue,'P.native_62414':valid})
    for step in [.1,.01,.001,.02,0.]:
        for lot in [-1.,-0.,0.,.009999999,.01,.099999999,.1,.123,12345.5]:
            c=add('volume-floor-and-step',{'P.native_62530':lot});c['doubles'][3]=[step]*8
    for minimum,maximum in [(.2,10.),(.01,.05),(0.,0.),(.3,.2)]:
        c=add('volume-limits-multiple-reads');c['doubles'][1]=([minimum,minimum+.001,minimum+.002]*3)[:8];c['doubles'][2]=[maximum]*8
    for hours in [-2147483648,-1,0,1,24,2147483647]:
        for virtual in [0,1,255]:add('expiration-width-and-flags',{'P.expiration_hours':hours,'P.virtual_expiration':virtual})
    for field in ['P.stop_distance','P.target_distance','P.trail_distance','P.trigger_distance','P.locked_distance','P.native_624f8','P.native_62500','P.gap_points','P.max_spread','P.native_62538','P.min_change']:
        for value in [-10.,-0.,0.,.1,10.,100.]:add('distance-and-threshold-boundaries',{field:value})
    for unit in [-1.,.0001,.1,10.]:
        for stops in [0,1,100]:
            c=add('units-and-broker-levels',{'P.unit':unit});c['integers'][0]=[stops]*8;c['integers'][1]=[stops+1,stops+2]*4
    for digits in [-1,0,1,2,3,5,11,12,2147483647]:
        c=add('digit-limit-and-repeat');c['integers'][2]=[digits,digits+1]*4
    for index in [0,1,3,7]:
        c=add('live-index-after-first-step-query');c['effects']=[[3,1,next(i for i,f in enumerate(FIELDS) if f[0]=='P.strategy_index'),index]]
    for symbol in [None,'','Vàng🚀']:add('symbol-text',symbol=symbol)
    for field in ['P.native_62530','P.unit','P.min_change','P.stop_distance','P.target_distance','P.trigger_distance','P.locked_distance','P.trail_distance','P.native_624f8','P.native_62500','P.gap_points','P.max_spread','MinimumSpread','P.native_62538']:
        for raw in [0x7ff0000000000000,0xfff0000000000000,0x7ff8000000000041,0xfff8000000000042]:
            add('special-floating-values',{field:boot.number(raw)})
    for step in [.1,.01,.001,.02,0.]:
        c=add('negative-fraction-floor',{'P.native_62530':-.123});c['doubles'][3]=[step]*8
    special=[boot.number(v) for v in [0x7ff8000000000041,0xfff8000000000042,0x7ff0000000000043,0xfff0000000000044]]
    for a in special:
        for b in special:
            add('both-nan-spread',{'P.tick.ask':a,'P.tick.bid':b})
            add('both-nan-change',{'P.min_change':a,'P.unit':b})
    for flag in [-1.,0.,1.,boot.number(0x7ff8000000000041)]:
        add('timed-distance-positive-guard',{'P.native_624f8':flag,'P.native_62500':-10.})
    for api,n,name,value in [(1,1,'P.native_6248c',15),(2,2,'P.expiration_seconds',7200),
                             (3,1,'P.native_62530',.199),(3,5,'P.unit',2.),
                             (4,3,'Entry.candidate_buy',1234.567),(4,4,'Entry.candidate_sell',-1234.567),
                             (7,1,'Inputs.entry.confirmation_frame',60),(7,1,'P.tick.bid',1998.),
                             (4,5,'P.native_62538',.05)]:
        c=add('live-state-after-services');c['effects']=[[api,n,next(i for i,f in enumerate(FIELDS) if f[0]==name),value]]
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<i',c['id'])+b''.join(struct.pack('<Q',word(v,f[1])) for f,v in zip(FIELDS,c['fields']))+boot.text(c['symbol'])
        for group in ['doubles','integers']:
            for row in c[group]:
                require(len(row)==8,'REPLY_SEQUENCE_SIZE');raw+=b''.join(struct.pack('<Q',boot.bits(v) if group=='doubles' else v&MASK) for v in row)
        for group in ['times','bars','bar_times']:raw+=b''.join(struct.pack('<Q',v&MASK) for v in c[group])
        raw+=struct.pack('<3Q',boot.bits(c['account']),*(boot.bits(v) for v in c['levels']))+struct.pack('<i',len(c['effects']))
        for api,n,f,v in c['effects']:raw+=struct.pack('<4Q',api,n,f,word(v,FIELDS[f][1]))
    return bytes(raw)
SCRIPT=r'''#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1EntryLoop.mqh"
#include "../../Include/bot-cua-toi-1/Bot1EntryLevelCache.mqh"
#include "../../Include/bot-cua-toi-1/Bot1PositionManagement.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ReleaseFilters.mqh"
Bot1PreparationInputs Inputs;Bot1PreparationState P;Bot1EntryLoopState Entry;Bot1PositionManagementState Manager;
Bot1NfpFilterState Nfp;Bot1ReleaseFilterState Interest,Cpi;Bot1PendingQueue Queue;Bot1LevelCacheSettings Levels;
int Magic;double MinimumSpread,Volumes[8];uchar FridayClosed;ulong LastTicket;
union Number {double value;ulong word;};
ulong Bits(const double value){Number n;n.value=value;return n.word;}
double Value(const ulong word){Number n;n.word=word;return n.value;}
void Word(const ulong v);void Text(const string v);void Begin();void Effect(const int api);
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,const string t=NULL,const string u=NULL);
double MockDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop);
long MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);
int MockBars(const string symbol,const ENUM_TIMEFRAMES frame);
datetime MockTime();datetime MockBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
double MockAccount(const ENUM_ACCOUNT_INFO_DOUBLE prop);
double MockLevel(const bool buy,const string &symbol,const ENUM_TIMEFRAMES frame,const ENUM_TIMEFRAMES &confirmation,
                 const int &older,const int &recent,const int &last,const double &quote,const double &gap,const double &unit,
                 const int &magic,const double &buy_offset,const double &sell_offset,const double &radius,ulong &ticket);
void MockPrint(const string value);string Bot1StartupNumber(const double value);
#define BOT1_STARTUP_NUMBER_EXTERNAL
#define SymbolInfoDouble MockDouble
#define SymbolInfoInteger MockInteger
#define Bars MockBars
#define TimeCurrent MockTime
#define iTime MockBar
#define AccountInfoDouble MockAccount
#define Bot1EntryLevel MockLevel
#define Print MockPrint
#include "../../Include/bot-cua-toi-1/Bot1StartupTradingState.mqh"
#undef SymbolInfoDouble
#undef SymbolInfoInteger
#undef Bars
#undef TimeCurrent
#undef iTime
#undef AccountInfoDouble
#undef Bot1EntryLevel
#undef Print
Bot1StartupTradingState State;
int Tape,ErrorOverride=-1,Counts[10],DPos[4],IPos[3];bool Final=false;
double Doubles[4][8],AccountReply,LevelReply[2];long Integers[3][8],Times[8],BarsReply[2],BarTimes[3];ulong Effects[32][4];int EffectCount;
void Word(const ulong v){FileWriteLong(Tape,(long)v);}
void Text(const string v){int n=v==NULL ? -1 : StringLen(v);FileWriteInteger(Tape,n);if(n>0)FileWriteString(Tape,v,n);}
string ReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
ulong TablesHash(){ulong h=0xcbf29ce484222325;for(int i=0;i<500;i++)for(int j=0;j<3;j++)h=(h^Bits(Manager.table.rows[i][j]))*0x100000001b3;for(int i=0;i<100;i++)for(int j=0;j<3;j++)h=(h^Bits(Queue.orders[i][j]))*0x100000001b3;return h;}
void Snapshot()
{
@WRITE@
   for(int i=0;i<8;i++)Word(Bits(Volumes[i]));Text(Inputs.symbol);Word(TablesHash());Word(ErrorOverride<0 ? GetLastError() : (uint)ErrorOverride);
   if(Final){for(int i=0;i<500;i++)for(int j=0;j<3;j++)Word(Bits(Manager.table.rows[i][j]));for(int i=0;i<100;i++)for(int j=0;j<3;j++)Word(Bits(Queue.orders[i][j]));}
}
void Begin(){ulong at=FileTell(Tape);FileWriteInteger(Tape,0);Snapshot();ulong end=FileTell(Tape);FileSeek(Tape,(long)at,SEEK_SET);FileWriteInteger(Tape,(int)(end-at-4));FileSeek(Tape,(long)end,SEEK_SET);}
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,const string t=NULL,const string u=NULL){FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Word(d);Text(t);Text(u);FileWriteInteger(Tape,(int)GetLastError());}
void Effect(const int api){int n=++Counts[api];for(int i=0;i<EffectCount;i++){if((int)Effects[i][0]!=api || (int)Effects[i][1]!=n)continue;ulong v=Effects[i][3];switch((int)Effects[i][2]){@EFFECT@}}}
int MockBars(const string symbol,const ENUM_TIMEFRAMES frame){Begin();int v=(int)BarsReply[Counts[1]%2];Effect(1);End(1,(ulong)frame,(ulong)(long)v,0,0,symbol);return v;}
datetime MockTime(){Begin();long v=Times[Counts[2]%8];Effect(2);End(2,(ulong)v);return (datetime)v;}
double MockDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop){Begin();int p=prop==SYMBOL_POINT ? 0 : (prop==SYMBOL_VOLUME_MIN ? 1 : (prop==SYMBOL_VOLUME_MAX ? 2 : 3));int i=DPos[p]++;double v=Doubles[p][i<8 ? i : 7];Effect(3);End(3,(ulong)prop,Bits(v),0,0,symbol);return v;}
long MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();int p=prop==SYMBOL_TRADE_STOPS_LEVEL ? 0 : (prop==SYMBOL_TRADE_FREEZE_LEVEL ? 1 : 2);int i=IPos[p]++;long v=Integers[p][i<8 ? i : 7];Effect(4);End(4,(ulong)prop,(ulong)v,0,0,symbol);return v;}
double MockAccount(const ENUM_ACCOUNT_INFO_DOUBLE prop){Begin();double v=AccountReply;Effect(5);End(5,(ulong)prop,Bits(v));return v;}
datetime MockBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();long v=BarTimes[Counts[6]%3];Effect(6);End(6,(ulong)frame,(ulong)(long)shift,(ulong)v,0,symbol);return (datetime)v;}
double MockLevel(const bool buy,const string &symbol,const ENUM_TIMEFRAMES frame,const ENUM_TIMEFRAMES &confirmation,
                 const int &older,const int &recent,const int &last,const double &quote,const double &gap,const double &unit,
                 const int &magic,const double &buy_offset,const double &sell_offset,const double &radius,ulong &ticket)
{Begin();ulong passed[11]={(ulong)(long)older,(ulong)(long)recent,(ulong)(long)last,Bits(quote),Bits(gap),Bits(unit),(ulong)(long)magic,Bits(buy_offset),Bits(sell_offset),Bits(radius),ticket};double v=LevelReply[buy ? 0 : 1];Effect(7);End(7,(ulong)buy,(ulong)frame,(ulong)confirmation,Bits(v),symbol);for(int i=0;i<11;i++)Word(passed[i]);return v;}
string Bot1StartupNumber(const double value){Begin();string v=(string)value;Effect(8);End(8,Bits(value),0,0,0,v);return v;}
void MockPrint(const string value){Begin();Effect(9);End(9,0,0,0,0,value);}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-startup-trading\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x54533131 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),tapes=FileOpen(folder+"sdk-tape.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE || tapes==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);FileWriteInteger(tapes,magic);FileWriteInteger(tapes,version);FileWriteInteger(tapes,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);
@READ@
      Inputs.symbol=ReadText(file);
      for(int i=0;i<4;i++)for(int j=0;j<8;j++)Doubles[i][j]=Value((ulong)FileReadLong(file));
      for(int i=0;i<3;i++)for(int j=0;j<8;j++)Integers[i][j]=FileReadLong(file);
      for(int i=0;i<8;i++)Times[i]=FileReadLong(file);for(int i=0;i<2;i++)BarsReply[i]=FileReadLong(file);for(int i=0;i<3;i++)BarTimes[i]=FileReadLong(file);
      AccountReply=Value((ulong)FileReadLong(file));for(int i=0;i<2;i++)LevelReply[i]=Value((ulong)FileReadLong(file));
      EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>32)return 8;for(int i=0;i<EffectCount;i++)for(int j=0;j<4;j++)Effects[i][j]=(ulong)FileReadLong(file);
      for(int i=0;i<8;i++)Volumes[i]=(double)(i+1)*.125;
      for(int i=0;i<500;i++)for(int j=0;j<3;j++)Manager.table.rows[i][j]=(double)(3*i+j+1)*.125;
      for(int i=0;i<100;i++)for(int j=0;j<3;j++)Queue.orders[i][j]=(double)(3*i+j+1)*.25;
      ArrayInitialize(Counts,0);ArrayInitialize(DPos,0);ArrayInitialize(IPos,0);string part=folder+"tape-"+IntegerToString(id)+".bin";Tape=FileOpen(part,FILE_WRITE|FILE_BIN);if(Tape==INVALID_HANDLE)return 5;
      ResetLastError();Final=false;ErrorOverride=-1;
      Bot1InitializeTradingState(Inputs,P,Magic,Entry,Nfp,Interest,Cpi,Manager,Queue,Levels,MinimumSpread,FridayClosed,Volumes,LastTicket,State);
      int error=GetLastError();FileClose(Tape);int section=FileOpen(part,FILE_READ|FILE_BIN);if(section==INVALID_HANDLE)return 6;int size=(int)FileSize(section);uchar raw[];ArrayResize(raw,size);if(size>0)FileReadArray(section,raw);FileClose(section);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0)FileWriteArray(tapes,raw);
      FileWriteInteger(output,id);Tape=output;Final=true;ErrorOverride=error;Begin();
   }
   if(FileTell(file)!=FileSize(file))return 9;FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
def generate():
    path=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1StartupTradingStateCheck.mq5';require(not path.exists(),'SOURCE_EXISTS')
    writes='\n'.join('   Word('+('Bits('+name+')' if kind=='d' else '(ulong)'+name)+');' for name,kind,_,_ in FIELDS)
    reads='\n'.join('      '+name+'='+('Value((ulong)FileReadLong(file))' if kind=='d' else ('(uchar)' if kind=='B' else '(uint)' if kind=='I' else '(int)' if kind=='i' else '(ulong)' if kind=='Q' else '')+'FileReadLong(file)')+';' for name,kind,_,_ in FIELDS)
    effects=''.join('case '+str(i)+':'+name+'='+('Value(v)' if kind=='d' else '(uchar)v' if kind=='B' else '(int)v' if kind=='i' else '(uint)v' if kind=='I' else '(long)v' if kind=='q' else 'v')+';break;' for i,(name,kind,_,_) in enumerate(FIELDS))
    path.write_text(SCRIPT.replace('@WRITE@',writes).replace('@READ@',reads).replace('@EFFECT@',effects),encoding='utf-8',newline='\n');print(path)

class Native(boot.Native):
    def __init__(self):
        super().__init__();self.sdk={0x7ff6846f2a30:1,0x7ff6846f1c40:2,0x7ff6846e2890:3,0x7ff6846e2970:4,0x7ff6846b7370:5,0x7ff6846f3b50:6,self.print_api:9,0x7ff6846ef6c0:8}
        for address in self.sdk:
            if not any(a<=address<=b for a,b,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=self.base+0x265a0,end=self.base+0x265a0)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=self.base+0x26960,end=self.base+0x26960)
        address=0x7ff6849ead20
        if not any(a<=address<=b for a,b,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
        self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.zero,begin=address,end=address)
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        md=Cs(CS_ARCH_X86,CS_MODE_64);self.arithmetic={};self.cpu={}
        for k,op in enumerate(['addsd','subsd','mulsd','divsd']):
            code=boot.history.HostAddition.CODE.replace(bytes.fromhex('f20f58c1'),bytes.fromhex({'addsd':'f20f58c1','subsd':'f20f5cc1','mulsd':'f20f59c1','divsd':'f20f5ec1'}[op]));address=self.host.address+512+64*k
            ctypes.memmove(address,code,len(code));self.cpu[op]=ctypes.WINFUNCTYPE(ctypes.c_uint64,ctypes.c_uint64,ctypes.c_uint64)(address)
        for i in md.disasm(bytes(self.m.mem_read(self.base+0x3cab,0x4f4b-0x3cab)),self.base+0x3cab):
            if i.mnemonic in self.cpu:self.arithmetic[i.address]=(i.mnemonic,i.op_str);self.m.hook_add(self.uc.UC_HOOK_CODE,self.calculate,begin=i.address,end=i.address)
    def call(self,m,address,size,user):
        if address in getattr(self,'sdk',{}):return
        return super().call(m,address,size,user)
    def calculate(self,m,address,size,user):
        op,args=self.arithmetic[address];left,right=args.split(', ');reg=getattr(self.x,'UC_X86_REG_'+left.upper());lv=m.reg_read(reg)
        if right.startswith('xmm'):rv=m.reg_read(getattr(self.x,'UC_X86_REG_'+right.upper()))&MASK
        else:
            expr=right.removeprefix('qword ptr [').removesuffix(']');target=0
            for term in expr.split(' + '):
                if '*' in term:a,b=term.split('*');target+=m.reg_read(getattr(self.x,'UC_X86_REG_'+a.upper()))*int(b,0)
                elif term.startswith('0x'):target+=int(term,16)
                else:target+=m.reg_read(getattr(self.x,'UC_X86_REG_'+term.upper()))
            rv=struct.unpack('<Q',m.mem_read(target,8))[0]
        m.reg_write(reg,(lv&~MASK)|self.cpu[op](lv&MASK,rv));m.reg_write(self.x.UC_X86_REG_RIP,address+size);self.cpu_calls+=1
    def zero(self,m,address,size,user):
        x=self.x;dest=m.reg_read(x.UC_X86_REG_RCX);count=m.reg_read(x.UC_X86_REG_R8);require((dest-self.base,count) in [(0x62590,12000),(0x65470,2400)] and m.reg_read(x.UC_X86_REG_RDX)==0,'WRONG_ZERO_RANGE');m.mem_write(dest,bytes(count));m.reg_write(x.UC_X86_REG_RAX,dest)
    def state(self,final=False):
        raw=bytearray();table=bytes(self.m.mem_read(self.base+0x62590,12000))+bytes(self.m.mem_read(self.base+0x65470,2400));h=0xcbf29ce484222325
        for name,kind,off,_ in FIELDS:
            fmt='Q' if kind=='d' else kind;v=struct.unpack('<'+fmt,self.m.mem_read(self.base+off,struct.calcsize('<'+fmt)))[0];raw+=struct.pack('<Q',int(v)&MASK)
        raw+=bytes(self.m.mem_read(self.base+0x66a80,64))+boot.text(self.read_text(self.base+0x67918))
        for (v,) in struct.iter_unpack('<Q',table):h=((h^v)*0x100000001b3)&MASK
        raw+=struct.pack('<QQ',h,struct.unpack('<I',self.m.mem_read(self.base+0x6a410,4))[0])
        return bytes(raw)+(table if final else b'')
    def service(self,m,address,size,user):
        api=7 if address in [self.base+0x265a0,self.base+0x26960] else self.sdk[address];r=self.tape;expected=r.block();actual=self.state()
        require(expected==actual,'STATE_BEFORE_STARTUP_API '+str((self.case['id'],api,next((i for i,(a,b) in enumerate(zip(expected,actual)) if a!=b),None))))
        kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I');require(kind==api,'STARTUP_API_ORDER');x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));symbol=self.read_text(self.base+0x67918)
        if api!=7:require(reg('RCX')==self.gate['ctx'],'STARTUP_API_CONTEXT')
        if api==1:require(args[0]==reg('R8') and texts==[symbol,None] and reg('RDX')==self.base+0x67918,'BARS_ARGS');m.reg_write(x.UC_X86_REG_RAX,args[1])
        elif api==2:require(reg('RDX')==0 and texts==[None,None],'TIME_ARGS');m.reg_write(x.UC_X86_REG_RAX,args[0])
        elif api in [3,4]:require(args[0]==reg('R8') and texts==[symbol,None] and reg('RDX')==self.base+0x67918,'PROPERTY_ARGS');m.reg_write(x.UC_X86_REG_RAX,args[1]) if api==4 else m.mem_write(self.base+0x6a448,struct.pack('<Q',args[1]))
        elif api==5:require(args[0]==reg('RDX')==37 and texts==[None,None],'ACCOUNT_ARGS');m.mem_write(self.base+0x6a448,struct.pack('<Q',args[1]))
        elif api==6:require(args[:2]==[reg('R8'),reg('R9')] and texts==[symbol,None],'ITIME_ARGS');m.reg_write(x.UC_X86_REG_RAX,args[2])
        elif api==7:
            buy=address==self.base+0x265a0;frame=struct.unpack('<I',m.mem_read(self.base+0x6227c,4))[0];require(args[:3]==[int(buy),reg('RCX'),frame] and texts==[symbol,None],'ENTRY_CHILD_ARGS')
            actual=[]
            for fmt,off in [('i',0x62430),('i',0x62434),('i',0x62438),('Q',0x67760 if buy else 0x67758),('Q',0x62440),('Q',0x66d98),('i',0x6246c),('Q',0x62448),('Q',0x62450),('Q',0x62460),('Q',0x677f8)]:
                actual.append(struct.unpack('<'+fmt,m.mem_read(self.base+off,struct.calcsize('<'+fmt)))[0]&MASK)
            require(list(r.take('11Q'))==actual,'ENTRY_CHILD_FIELD_ARGS')
        elif api==8:require(args[0]==reg('RDX') and reg('R8')==0x58 and texts[1] is None,'NUMBER_ARGS');self.put_text(reg('R9')-self.base,texts[0])
        else:
            sp=reg('RSP');desc=struct.unpack('<Q',m.mem_read(sp+40,8))[0];require((reg('RDX'),reg('R8'),reg('R9'))==(2,1,0x590008) and texts==[self.read_text(desc),None],'PRINT_ARGS')
        self.counts[api]+=1
        for a,n,f,v in self.case['effects']:
            if a==api and n==self.counts[api]:
                _,k,off,_=FIELDS[f];size_=struct.calcsize('<'+k);m.mem_write(self.base+off,(word(v,k)&((1<<(8*size_))-1)).to_bytes(size_,'little'))
        if api==7:
            m.mem_write(self.base+(0x67440 if buy else 0x67438),struct.pack('<Q',args[3]));sp=reg('RSP');dest=struct.unpack('<Q',m.mem_read(sp,8))[0];m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,dest)
        m.mem_write(self.base+0x6a410,struct.pack('<I',error));self.calls+=1
    def run(self,c,tape):
        self.case=c;self.tape=Reader(tape);self.calls=self.cpu_calls=0;self.counts={i:0 for i in range(1,10)};self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for (_,kind,off,_),v in zip(FIELDS,c['fields']):
            size=struct.calcsize('<'+kind);m.mem_write(self.base+off,(word(v,kind)&((1<<(8*size))-1)).to_bytes(size,'little'))
        for off,count,scale in [(0x66a80,8,.125),(0x62590,1500,.125),(0x65470,300,.25)]:m.mem_write(self.base+off,b''.join(struct.pack('<d',(i+1)*scale) for i in range(count)))
        self.put_text(0x67918,c['symbol']);m.mem_write(self.base+0x6a410,bytes(4))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        sp=0x5001fc00;m.mem_write(sp,bytes(0x300));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        for name,value in [('RBP',self.base+0x6a448),('R12',self.print_api),('R14',0x7ff6846f1c40),('R15',self.base+0x5c0)]:m.reg_write(getattr(x,'UC_X86_REG_'+name),value)
        m.emu_start(self.base+0x3cab,self.base+0x4e77,timeout=3000000,count=1000000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+0x4e77 and self.tape.pos==len(tape),'STARTUP_TRADING_NOT_FINISHED');return self.state(True)
def identity():
    src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupTradingStateCheck.mq5'
    helpers=[Path(__file__),Path(boot.__file__),Path(base.__file__),Path(boot.history.__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',ROOT/'danh-gia-doc-lap/strategy-history-20261028-r1/nan-add-cpu-probe.json']
    return dict(original_ex5_sha256=base.base.validation.original_hash(1),native_init_sha256=boot.INIT_SHA,sources_sha256={p.relative_to(src).as_posix():sha(p) for p in pub.closure(script,src)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def execute(folder,build):
    mt=ROOT.parent/'.local/mt5-bot1-thread-20261025';receipt=ROOT/'bot-cua-toi-1/bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script='Scripts/bot-cua-toi-1/Bot1StartupTradingStateCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,h in identity()['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/'MQL5/Files/bot1-startup-trading'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('startup-trading-'+folder.name+'.set');ini=mt/('startup-trading-'+folder.name+'.ini');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1StartupTradingStateCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(cases())),'SCRIPT_FAILED')
    return files,receipt
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);ap.add_argument('run',nargs='?');ap.add_argument('--build');a=ap.parse_args()
    if a.mode=='generate':generate();return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases();current=identity();folder=ROOT/'bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the'/a.run;header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    before=json.loads((folder/'baseline.json').read_text());require(all(before[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build,'BUILD_REQUIRED');files,receipt=execute(folder,a.build)
        for name in ['mql5-results.bin','sdk-tape.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        r=Reader((folder/'sdk-tape.bin').read_bytes());require(r.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Native();raw=bytearray(header);calls=cpu=0
        try:
            for c in rows:
                require(r.take('i')[0]==c['id'],'TAPE_CASE');v=o.run(c,r.block());raw+=struct.pack('<2i',c['id'],len(v))+v;calls+=o.calls;cpu+=o.cpu_calls
        finally:o.close()
        require(r.pos==len(r.raw),'TAPE_TRAILING')
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),sdk_calls=calls,cpu_arithmetic_calls=cpu,**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=calls,cpu_arithmetic_calls=cpu)));return
    readers=[]
    for name in ['original','mql5']:
        run=json.loads((folder/(name+'-run.json')).read_text());require(all(run[k]==v for k,v in current.items()) and run['result_sha256']==sha(folder/(name+'-results.bin')) and run['sdk_tape_sha256']==sha(folder/'sdk-tape.bin'),'RUN_CHANGED');r=Reader((folder/(name+'-results.bin')).read_bytes());require(r.take('3i')==(MAGIC,1,len(rows)),'RESULT_HEADER');readers.append(r)
    failures=[]
    for c in rows:
        values=[]
        for r in readers:require(r.take('i')[0]==c['id'],'RESULT_CASE');values.append(r.block())
        if values[0]!=values[1]:failures.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*values)) if x!=y),None)))
    require(all(r.pos==len(r.raw) for r in readers),'RESULT_TRAILING');report=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:12],fields=len(FIELDS),table_cells=1800,**SCOPE,limits=['After first preparation only. Entry-level children and terminal replies supplied. Zero-unit errors, allocation failures, object names, history/panel tail and full EA remain unverified.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failures))
if __name__=='__main__':main()
