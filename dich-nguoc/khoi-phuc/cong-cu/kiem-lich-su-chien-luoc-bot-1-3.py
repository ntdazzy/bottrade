"""Compare complete strategy-history aggregation/cache with unchanged original code.

generate BOT; prepare|mql5 --build BUILD|original|compare BOT RUN.
Includes repeated calls with a shared cache and actual MT5 ArrayResize responses.
"""
import argparse,copy,ctypes,hashlib,importlib.util,json,random,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x53484331;MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
shared=module('history_shared','kiem-bang-thong-tin-lich-su-bot-1-3.py');sorting=module('history_sorting','kiem-sap-xep-bot-1-3.py')
require=shared.require;sha=shared.sha;save=shared.save;Reader=shared.Reader;text=shared.text;pub=shared.pub
CFG={1:dict(fn=0x1efa0,end=0x1f5df,sha='0633072a80dec3ef6ecaa0abc0d2e6856d40ed66426c3418c165d13839cad07a',show=0x6a530,index=0x678f4,magic=0x6246c,counts=0x67940,total=0x6a318,count=0x6a314),
     3:dict(fn=0x2a1c0,end=0x2a7ff,sha='3089eaa5351ecd00d853e4ea8153bab82c3f5a2196c724371fb84513c3ecd3b3',show=0x1d6f40,index=0x74934,magic=0x6d564,counts=0x74980,total=0x77358,count=0x77354)}
SCOPE=dict(full_ea=False,whole_bot_complete=False,whole_manager_complete=False,full_strategy_history_executed=True,
           native_sort_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,
           array_resize_measured_in_mt5=True,addsd_executed_on_host_cpu=True,original_ex5_changed=False)

def fields(bot):
    c=CFG[bot];return [('ShowTester','B',c['show']),('Index','I',c['index']),('Magic','i',c['magic']),('Cache.count','i',c['count']),('Cache.total','i',c['total']),('Symbol','s',shared.entry.CONFIG[bot]['symbol'])]
def bit(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def word(v,k):return int(v)&MASK
def deal(ticket=101,position=42,magic=9001,entry=0,type_=0,symbol='XAUUSD',profit=10.,commission=-1.,swap=-.5):
    return dict(ticket=ticket,symbol=symbol,types=type_ if isinstance(type_,list) else [type_],entries=entry if isinstance(entry,list) else [entry],positions=position if isinstance(position,list) else [position],magics=magic if isinstance(magic,list) else [magic],profit=profit,commission=commission,swap=swap)
def step(deals=None,info=0,select=1,totals=None,updates=None):
    if deals is None:deals=[deal(profit=0.),deal(ticket=102,magic=0,entry=1,profit=10.),deal(ticket=103,position=99,magic=9002,symbol='OTHER')]
    return dict(deals=deals,info=info,select=select,totals=totals if totals is not None else [len(deals),len(deals)],updates=updates or {})
def cases(bot):
    out=[];values=dict(ShowTester=1,Index=0,Magic=9001,Symbol='XAUUSD',**{'Cache.count':2,'Cache.total':-1})
    def add(tag,steps=None,updates=None,keys=None,owners=None,flags=(0,0),effects=None,errors=0):
        c=dict(id=len(out),tag=tag,values=copy.deepcopy(values),counts=[100+i for i in range(8 if bot==1 else 9)],
               keys=keys if keys is not None else [777,55,0,1<<63],owners=owners if owners is not None else [9005,9006,9007,9008],
               flags=list(flags),steps=steps or [step()],effects=effects or [],errors=errors)
        c['values'].update(updates or {});out.append(c);return c
    for info in [0,1,2,-1]:
        for show in [0,1,2,255]:
            for select in [0,1]:add('tester-and-selection',[step(info=info,select=select)],dict(ShowTester=show))
    for flags in [(0,0),(0,1),(1,0),(1,1)]:
        for count in [0,1,2,3,8,31]:
            ds=[deal(ticket=i+1,position=[0,1,1<<63,(1<<64)-1][i%4],magic=9001+i%3,entry=0 if i%3 else 1,type_=i%2) for i in range(count)]
            add('rebuild-sort-and-series',[step(ds)],flags=flags)
    for type_ in [0,1,2,3,-1,0x100000000,0x100000001]:
        for entry in [0,1,2,3,4,-1,0x100000000,0x100000003]:add('type-and-entry-low32',[step([deal(type_=type_,entry=entry)])])
    for symbol in [None,'','XAUUSD','OTHER','Vàng','A\U0001f600B']:
        for target in ['XAUUSD','',None]:add('symbol-and-null',[step([deal(symbol=symbol)])],dict(Symbol=target))
    for magic in [-2147483648,-1,0,9001,2147483647]:
        for owner in [magic,magic+(1<<32)]:add('signed-current-magic',[step([deal(magic=owner)])],dict(Magic=magic))
    for key in [0,1,(1<<63)-1,1<<63,(1<<64)-1]:
        for owner in [0,9001,9002]:
            add('cached-owner-and-fallback',[step([deal(position=key,magic=9001,entry=1)])],{'Cache.total':1,'Cache.count':2},keys=[0,1<<63],owners=[owner,owner])
    for count in [-1,0,1,3]:
        for second in [-1,0,1,3]:
            add('fresh-total-and-resize-failure',[step(totals=[count,second])],{'Cache.total':-2})
    for value in [-0.,0.,1.005,-1.005,1e16,-1e16,1e19,float('nan'),float('inf'),-float('inf')]:
        add('sum-order',[step([deal(profit=value,commission=-value,swap=1.),deal(ticket=102,entry=1,profit=1.,commission=0.,swap=0.)])],errors=1)
    for flags in [(0,0),(0,1),(1,0),(1,1)]:
        # Same length but changed opening owners must keep the existing cache.
        a=[deal(magic=9001,profit=0.),deal(ticket=102,magic=0,entry=1)]
        b=[deal(magic=9002,profit=0.),deal(ticket=102,magic=0,entry=1)]
        add('shared-cache-same-count',[step(a),step(b,updates={'Index':1,'Magic':9002}),step(b,updates={'Index':2,'Magic':9001})],flags=flags,errors=1)
        add('shared-cache-count-change',[step(a),step(b+[deal(ticket=103,position=99,magic=9002)],updates={'Index':1,'Magic':9002})],flags=flags)
    for entry in [[0,1],[0,3],[1,0]]:
        add('fresh-properties-across-scans',[step([deal(entry=entry,position=[42,99],magic=[9001,9002])])],errors=1)
    mutations=[(1,1,'ShowTester',0),(2,1,'Index',1),(3,1,'Cache.total',3),(3,1,'Cache.count',0),
               (5,1,'Magic',9002),(5,2,'Cache.count',1),(5,4,'Magic',-1),(6,1,'Symbol','OTHER'),
               (7,1,'Index',2),(7,1,'closed0',2147483647),(8,1,'keys_series',1),(8,2,'owners_series',1)]
    for api,n,name,value in mutations:add('live-fields',effects=[dict(api=api,n=n,name=name,value=value)],errors=1)
    rng=random.Random(2026102841+bot)
    for _ in range(50):
        ds=[deal(ticket=i+1,position=rng.choice([0,1,42,99,1<<63]),magic=rng.choice([0,9001,9002]),entry=rng.randrange(4),type_=rng.randrange(4),symbol=rng.choice(['XAUUSD','OTHER']),profit=rng.uniform(-100,100),commission=-.1,swap=.05) for i in range(rng.randrange(8))]
        add('mixed',[step(ds)],flags=(rng.randrange(2),rng.randrange(2)),errors=1)
    special=[0x7ff8000000000041,0xfff8000000000042,0x7ff0000000000043,0xfff0000000000044]
    for a in special:
        for b in special:
            left=struct.unpack('<d',struct.pack('<Q',a))[0];right=struct.unpack('<d',struct.pack('<Q',b))[0]
            add('nan-sign-and-payload',[step([deal(profit=left,commission=right,swap=0.)])])
    return out

def effect_names(bot):return [n for n,_,_ in fields(bot)]+['keys_series','owners_series','closed0']
def encoded_effect(e,bot):
    i=effect_names(bot).index(e['name']);return struct.pack('<3i',e.get('api',0),e.get('n',0),i)+(text(e['value']) if e['name']=='Symbol' else struct.pack('<Q',int(e['value'])&MASK))
def array(flag,items,kind):return struct.pack('<2i',flag,len(items))+struct.pack('<'+kind*len(items),*items)
def encode(rows,bot):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<i',c['id'])
        for n,k,_ in fields(bot):raw+=text(c['values'][n]) if k=='s' else struct.pack('<Q',word(c['values'][n],k))
        raw+=struct.pack('<i',len(c['counts']))+struct.pack('<'+'i'*len(c['counts']),*c['counts'])+array(c['flags'][0],c['keys'],'Q')+array(c['flags'][1],c['owners'],'q')
        raw+=struct.pack('<2i',c['errors'],len(c['effects']))+b''.join(encoded_effect(e,bot) for e in c['effects'])+struct.pack('<i',len(c['steps']))
        for t in c['steps']:
            raw+=struct.pack('<3i',t['info'],t['select'],len(t['totals']))+struct.pack('<'+'i'*len(t['totals']),*t['totals'])+struct.pack('<i',len(t['updates']))
            raw+=b''.join(encoded_effect(dict(api=0,n=0,name=n,value=v),bot) for n,v in t['updates'].items())+struct.pack('<i',len(t['deals']))
            for d in t['deals']:
                raw+=struct.pack('<Q',d['ticket'])+text(d['symbol'])
                for key in ['types','entries','positions','magics']:
                    raw+=struct.pack('<i',len(d[key]))+struct.pack('<'+'Q'*len(d[key]),*(v&MASK for v in d[key]))
                raw+=struct.pack('<3d',d['profit'],d['commission'],d['swap'])
    return raw

TEMPLATE=r'''#property strict
input string CheckRun="";
int MockInfo(const ENUM_MQL_INFO_INTEGER property);
bool MockSelect(const datetime from,const datetime to);
int MockTotal();ulong MockTicket(const int index);
long MockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property);
string MockString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property);
double MockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property);
int MockResize(ulong &values[],const int count,const int reserve=0);
int MockResize(long &values[],const int count,const int reserve=0);
#define MQLInfoInteger MockInfo
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define HistoryDealGetInteger MockInteger
#define HistoryDealGetString MockString
#define HistoryDealGetDouble MockDouble
#define ArrayResize MockResize
#include "../../Include/bot-cua-toi-@N@/Bot@N@StrategyHistory.mqh"
#undef MQLInfoInteger
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef HistoryDealGetInteger
#undef HistoryDealGetString
#undef HistoryDealGetDouble
#undef ArrayResize
uchar ShowTester;uint Index;int Magic;string HistorySymbol;int ClosedTrades[@ROWS@];Bot@N@StrategyHistoryCache Cache;
int TapeFile,ErrorMode,Counts[9],Calls,InfoReply,SelectReply,Totals[],TotalCalls,Selected;uint LogicalError;
struct Deal { ulong ticket;string symbol;long types[],entries[],positions[],magics[];int reads[4];double profit,commission,swap; };Deal Deals[];
struct Effect { int api,n,field;ulong word;string text; };Effect Effects[];
union Number { double value;ulong word; };
ulong Bits(const double value) { Number n;n.value=value;return n.word; }
string ReadText(const int file) { int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n)); }
void Text(const string value)
{ if(value==NULL) {FileWriteInteger(TapeFile,-1);return;}int n=StringLen(value);FileWriteInteger(TapeFile,n);if(n>0)FileWriteString(TapeFile,value,n); }
void KeysState()
{ bool rev=ArrayGetAsSeries(Cache.positions);int n=ArraySize(Cache.positions);FileWriteInteger(TapeFile,(int)rev);FileWriteInteger(TapeFile,n);for(int i=0;i<n;i++)FileWriteLong(TapeFile,(long)Cache.positions[rev ? n-1-i : i]); }
void OwnersState()
{ bool rev=ArrayGetAsSeries(Cache.magics);int n=ArraySize(Cache.magics);FileWriteInteger(TapeFile,(int)rev);FileWriteInteger(TapeFile,n);for(int i=0;i<n;i++)FileWriteLong(TapeFile,Cache.magics[rev ? n-1-i : i]); }
void State()
{
   ulong words[5];words[0]=(ulong)ShowTester;words[1]=(ulong)Index;words[2]=(ulong)(long)Magic;words[3]=(ulong)(long)Cache.count;words[4]=(ulong)(long)Cache.total;
   FileWriteArray(TapeFile,words,0,5);Text(HistorySymbol);FileWriteInteger(TapeFile,@ROWS@);FileWriteArray(TapeFile,ClosedTrades,0,@ROWS@);
   KeysState();OwnersState();FileWriteLong(TapeFile,(long)LogicalError);
}
void SetField(const int field,const ulong word,const string text)
{
   switch(field)
   {
      case 0: ShowTester=(uchar)word;break;case 1: Index=(uint)word;break;case 2: Magic=(int)word;break;
      case 3: Cache.count=(int)word;break;case 4: Cache.total=(int)word;break;case 5: HistorySymbol=text;break;
      case 6: ArraySetAsSeries(Cache.positions,word!=0);break;case 7: ArraySetAsSeries(Cache.magics,word!=0);break;
      case 8: ClosedTrades[0]=(int)word;break;
   }
}
void Begin(const int api,const ulong a,const ulong b,const ulong c,const string value)
{ State();FileWriteInteger(TapeFile,api);FileWriteLong(TapeFile,(long)a);FileWriteLong(TapeFile,(long)b);FileWriteLong(TapeFile,(long)c);Text(value); }
void End(const int api,const ulong reply)
{
   FileWriteLong(TapeFile,(long)reply);Calls++;Counts[api]++;if(ErrorMode!=0)LogicalError=(uint)(9000+Calls);FileWriteInteger(TapeFile,(int)LogicalError);
   for(int i=0;i<ArraySize(Effects);i++)if(Effects[i].api==api && Effects[i].n==Counts[api])SetField(Effects[i].field,Effects[i].word,Effects[i].text);
}
void Record(const int api,const ulong a,const ulong b,const string value,const ulong reply)
{ Begin(api,a,b,0,value);End(api,reply); }
int MockInfo(const ENUM_MQL_INFO_INTEGER property) { int reply=InfoReply;Record(1,(ulong)property,0,NULL,(ulong)(long)reply);return reply; }
bool MockSelect(const datetime from,const datetime to) { bool reply=SelectReply!=0;Record(2,(ulong)from,(ulong)to,NULL,(ulong)reply);return reply; }
int MockTotal() { int reply=Totals[MathMin(TotalCalls,ArraySize(Totals)-1)];TotalCalls++;Record(3,0,0,NULL,(ulong)(long)reply);return reply; }
ulong MockTicket(const int index) { Selected=index;ulong reply=index>=0 && index<ArraySize(Deals) ? Deals[index].ticket : 0;Record(4,(ulong)(uint)index,0,NULL,reply);return reply; }
long Next(const long &values[],int &read) { long value=values[MathMin(read,ArraySize(values)-1)];read++;return value; }
long MockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property)
{
   long reply=0;
   switch((int)property)
   {
      case 3: reply=Next(Deals[Selected].types,Deals[Selected].reads[0]);break;
      case 4: reply=Next(Deals[Selected].entries,Deals[Selected].reads[1]);break;
      case 12: reply=Next(Deals[Selected].positions,Deals[Selected].reads[2]);break;
      case 11: reply=Next(Deals[Selected].magics,Deals[Selected].reads[3]);break;
   }
   Record(5,ticket,(ulong)property,NULL,(ulong)reply);return reply;
}
string MockString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property)
{ string reply=Deals[Selected].symbol;Record(6,ticket,(ulong)property,reply,0);return reply; }
double MockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property)
{ double reply=(int)property==9 ? Deals[Selected].profit : (int)property==7 ? Deals[Selected].commission : Deals[Selected].swap;Record(7,ticket,(ulong)property,NULL,Bits(reply));return reply; }
int MockResize(ulong &values[],const int count,const int reserve)
{ Begin(8,1,(ulong)(uint)count,(ulong)(uint)reserve,NULL);int reply=ArrayResize(values,count,reserve);KeysState();OwnersState();End(8,(ulong)(long)reply);return reply; }
int MockResize(long &values[],const int count,const int reserve)
{ Begin(8,2,(ulong)(uint)count,(ulong)(uint)reserve,NULL);int reply=ArrayResize(values,count,reserve);KeysState();OwnersState();End(8,(ulong)(long)reply);return reply; }
void LoadLongs(const int file,long &values[])
{ int n=FileReadInteger(file);ArrayResize(values,n);for(int i=0;i<n;i++)values[i]=FileReadLong(file); }
void ReadEffect(const int file,Effect &e)
{ e.api=FileReadInteger(file);e.n=FileReadInteger(file);e.field=FileReadInteger(file);e.word=0;e.text=NULL;if(e.field==5)e.text=ReadText(file);else e.word=(ulong)FileReadLong(file); }
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot@N@-strategy-history\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input_file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x53484331 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(input_file);
      for(int k=0;k<5;k++)SetField(k,(ulong)FileReadLong(input_file),NULL);HistorySymbol=ReadText(input_file);
      int n=FileReadInteger(input_file);if(n!=@ROWS@)return 5;FileReadArray(input_file,ClosedTrades,0,n);
      int rev=FileReadInteger(input_file);n=FileReadInteger(input_file);ArraySetAsSeries(Cache.positions,false);ArrayResize(Cache.positions,n);
      for(int k=0;k<n;k++)Cache.positions[k]=(ulong)FileReadLong(input_file);ArraySetAsSeries(Cache.positions,rev!=0);
      rev=FileReadInteger(input_file);n=FileReadInteger(input_file);ArraySetAsSeries(Cache.magics,false);ArrayResize(Cache.magics,n);
      for(int k=0;k<n;k++)Cache.magics[k]=FileReadLong(input_file);ArraySetAsSeries(Cache.magics,rev!=0);
      ErrorMode=FileReadInteger(input_file);n=FileReadInteger(input_file);ArrayResize(Effects,n);for(int k=0;k<n;k++)ReadEffect(input_file,Effects[k]);
      int steps=FileReadInteger(input_file);Calls=0;LogicalError=0;ArrayInitialize(Counts,0);
      string name=folder+"events-"+IntegerToString(id)+".bin";TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE)return 6;
      for(int s=0;s<steps;s++)
      {
         InfoReply=FileReadInteger(input_file);SelectReply=FileReadInteger(input_file);n=FileReadInteger(input_file);ArrayResize(Totals,n);
         for(int k=0;k<n;k++)Totals[k]=FileReadInteger(input_file);
         n=FileReadInteger(input_file);for(int k=0;k<n;k++) { Effect e;ReadEffect(input_file,e);SetField(e.field,e.word,e.text); }
         n=FileReadInteger(input_file);ArrayResize(Deals,n);
         for(int k=0;k<n;k++)
         {
            Deals[k].ticket=(ulong)FileReadLong(input_file);Deals[k].symbol=ReadText(input_file);
            LoadLongs(input_file,Deals[k].types);LoadLongs(input_file,Deals[k].entries);LoadLongs(input_file,Deals[k].positions);LoadLongs(input_file,Deals[k].magics);
            Deals[k].profit=FileReadDouble(input_file);Deals[k].commission=FileReadDouble(input_file);Deals[k].swap=FileReadDouble(input_file);ArrayInitialize(Deals[k].reads,0);
         }
         TotalCalls=0;Selected=-1;double result=Bot@N@StrategyClosedProfit(ShowTester,HistorySymbol,Magic,Index,ClosedTrades,Cache);State();FileWriteLong(TapeFile,(long)Bits(result));
      }
      FileClose(TapeFile);int events=FileOpen(name,FILE_READ|FILE_BIN);if(events==INVALID_HANDLE)return 7;
      int size=(int)FileSize(events);uchar bytes[];ArrayResize(bytes,size);if(size>0)FileReadArray(events,bytes,0,size);FileClose(events);
      FileWriteInteger(output,id);FileWriteInteger(output,size);if(size>0)FileWriteArray(output,bytes,0,size);
   }
   FileClose(input_file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 8;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''

def generate(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';folder=source/f'Scripts/bot-cua-toi-{bot}';code=TEMPLATE.replace('@N@',str(bot)).replace('@ROWS@',str(8 if bot==1 else 9))
    (folder/f'Bot{bot}StrategyHistoryCheck.mq5').write_text(code,encoding='utf-8',newline='\n')
    (folder/f'Bot{bot}StrategyHistoryAPICompile.mq5').write_text(f'#property strict\n#include "../../Include/bot-cua-toi-{bot}/Bot{bot}StrategyHistory.mqh"\nvoid OnStart() {{Print("Bot{bot}StrategyHistoryAPICompile");}}\n',encoding='utf-8',newline='\n')

class HostAddition:
    # Actual SSE2 arithmetic: movq xmm0,rcx;movq xmm1,rdx;addsd xmm0,xmm1;movq rax,xmm0;ret.
    CODE=bytes.fromhex('66480f6ec1 66480f6eca f20f58c1 66480f7ec0 c3')
    def __init__(self):
        self.kernel=ctypes.WinDLL('kernel32',use_last_error=True);k=self.kernel
        k.VirtualAlloc.argtypes=[ctypes.c_void_p,ctypes.c_size_t,ctypes.c_uint32,ctypes.c_uint32];k.VirtualAlloc.restype=ctypes.c_void_p
        k.VirtualFree.argtypes=[ctypes.c_void_p,ctypes.c_size_t,ctypes.c_uint32];k.VirtualFree.restype=ctypes.c_int
        self.address=k.VirtualAlloc(None,4096,0x3000,0x40)
        if not self.address:raise ctypes.WinError(ctypes.get_last_error())
        ctypes.memmove(self.address,self.CODE,len(self.CODE));self.add=ctypes.WINFUNCTYPE(ctypes.c_uint64,ctypes.c_uint64,ctypes.c_uint64)(self.address)
        # STMXCSR writes to the caller-provided Win64 home area and returns the control/status word.
        control=bytes.fromhex('0fae5c2408 8b442408 c3');ctypes.memmove(self.address+128,control,len(control))
        self.control=ctypes.WINFUNCTYPE(ctypes.c_uint32)(self.address+128)
        require(self.control()&~63==0x1f80,'HOST_FLOAT_CONTROL_NOT_NEAREST_IEEE')
        evidence=json.loads((ROOT/'danh-gia-doc-lap/strategy-history-20261028-r1/nan-add-cpu-probe.json').read_text())
        require(evidence['code_hex']==self.CODE.hex(),'HOST_OPCODE_CHANGED')
        for row in evidence['rows']:require(self.add(int(row['left'],16),int(row['right'],16))==int(row['host'],16),'HOST_CPU_CALIBRATION_CHANGED')
    def close(self):
        if self.address:
            if not self.kernel.VirtualFree(self.address,0,0x8000):raise ctypes.WinError(ctypes.get_last_error())
            self.address=None

class Native(shared.entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.bot=bot;self.c=CFG[bot];self.fs=fields(bot);self.rows=8 if bot==1 else 9
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+self.c['fn'],self.c['end']-self.c['fn']))).hexdigest()==self.c['sha'],'NATIVE_BODY_CHANGED')
        self.m.mem_map(0x71000000,0x20000)
        self.sdk={0x7ff683f20000+offset:api for api,offset in {1:0x7c0fd0,2:0x7d84f0,3:0x7d8810,4:0x7d8860,5:0x7d8940,6:0x7d89d0,7:0x7d88b0,8:0x7aa0e0}.items()}
        for a in self.sdk:
            existed=a in self.apis
            if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
            self.m.mem_write(a,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        self.covered=set();self.sort_visits=0
        self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,a,s,u:self.covered.add(a-self.base),begin=self.base+self.c['fn'],end=self.base+self.c['end']-1)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.sort_entry,begin=self.base+sorting.FN[bot],end=self.base+sorting.FN[bot])
        self.host=HostAddition();self.host_additions=0
        self.additions=[self.c['fn']+offset for offset in [0x308,0x311,0x326]]
        expected=[bytes.fromhex('f2410f587500'),bytes.fromhex('f2410f587500'),bytes.fromhex('f2410f587500')]
        for a,opcode in zip(self.additions,expected):
            require(bytes(self.m.mem_read(self.base+a,len(opcode)))==opcode,'ADDSD_INSTRUCTION_CHANGED')
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.addition,begin=self.base+a,end=self.base+a)
    def addition(self,m,address,size,user):
        x=self.x;old=m.reg_read(x.UC_X86_REG_XMM6);right=struct.unpack('<Q',m.mem_read(m.reg_read(x.UC_X86_REG_R13),8))[0]
        result=self.host.add(old&MASK,right);m.reg_write(x.UC_X86_REG_XMM6,(old&~MASK)|result);m.reg_write(x.UC_X86_REG_RIP,address+size);self.host_additions+=1
    def close(self):self.host.close()
    def sort_entry(self,m,a,s,u):self.sort_visits+=1
    def read_text(self,desc):
        pointer=struct.unpack('<Q',self.m.mem_read(desc+4,8))[0]
        if pointer==0:return None
        n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(n<100000,'TEXT_BOUNDS');return bytes(self.m.mem_read(pointer,n*2)).decode('utf-16-le')
    def put(self,field,value):
        _,kind,rva=field;raw=struct.pack('<IQ',0,0 if value is None else self.string(value)) if kind=='s' else (int(value)&((1<<(8*struct.calcsize('<'+kind)))-1)).to_bytes(struct.calcsize('<'+kind),'little')
        self.m.mem_write(self.base+rva,raw)
    def place(self,index,flag,raw):
        rva=sorting.KEYS[self.bot] if index==1 else sorting.VALUES[self.bot];kind=sorting.KEY_TYPE if index==1 else sorting.VALUE_TYPE;pointer=0x71000000 if index==1 else 0x71010000
        n=len(raw)//8;require(len(raw)%8==0 and 0<=n<=4096,'ARRAY_SIZE')
        self.m.mem_write(self.base+rva,struct.pack('<Q',kind|(sorting.SERIES if flag else 0))+bytes(44));self.m.mem_write(self.base+rva+8,struct.pack('<i',n));self.m.mem_write(self.base+rva+28,struct.pack('<Q',pointer))
        if raw:self.m.mem_write(pointer,raw)
    def actual_array(self,index):
        rva=sorting.KEYS[self.bot] if index==1 else sorting.VALUES[self.bot];raw=bytes(self.m.mem_read(self.base+rva,52));head,n=struct.unpack_from('<Qi',raw);pointer=struct.unpack_from('<Q',raw,28)[0]
        require(0<=n<=4096,'NATIVE_ARRAY_SIZE');return struct.pack('<2i',int(bool(head&sorting.SERIES)),n)+(bytes(self.m.mem_read(pointer,8*n)) if n else b'')
    def read_array(self):
        flag,n=self.tape.take('2i');require(flag in [0,1] and 0<=n<=4096,'TAPE_ARRAY_SIZE');raw=bytes(self.tape.raw[self.tape.pos:self.tape.pos+n*8]);self.tape.pos+=n*8;require(len(raw)==n*8,'TAPE_ARRAY_TRUNCATED');return flag,raw
    def state(self):
        raw=bytearray()
        for _,k,a in self.fs:
            if k=='s':raw+=text(self.read_text(self.base+a))
            else:raw+=struct.pack('<Q',struct.unpack('<'+k,self.m.mem_read(self.base+a,struct.calcsize('<'+k)))[0]&MASK)
        raw+=struct.pack('<i',self.rows)+bytes(self.m.mem_read(self.base+self.c['counts'],4*self.rows))
        raw+=self.actual_array(1)+self.actual_array(2)+struct.pack('<Q',struct.unpack('<I',self.m.mem_read(self.base+shared.CFG[self.bot]['error'],4))[0]);return bytes(raw)
    def expected_state(self):
        raw=bytearray(struct.pack('<5Q',*self.tape.take('5Q')))+text(self.tape.text());n,=self.tape.take('i');require(n==self.rows,'COUNTS_LENGTH')
        raw+=struct.pack('<i',n)+struct.pack('<'+'i'*n,*self.tape.take('i'*n))
        for _ in range(2):flag,data=self.read_array();raw+=struct.pack('<2i',flag,len(data)//8)+data
        return bytes(raw)+struct.pack('<Q',self.tape.take('Q')[0])
    def effect(self,name,value):
        if name in ['keys_series','owners_series']:
            rva=sorting.KEYS[self.bot] if name=='keys_series' else sorting.VALUES[self.bot];h=struct.unpack('<Q',self.m.mem_read(self.base+rva,8))[0]
            self.m.mem_write(self.base+rva,struct.pack('<Q',(h|sorting.SERIES) if value else (h&~sorting.SERIES)))
        elif name=='closed0':self.m.mem_write(self.base+self.c['counts'],struct.pack('<I',value&0xffffffff))
        else:self.put(next(f for f in self.fs if f[0]==name),value)
    def call(self,m,address,size,user):
        if address not in self.sdk:return super().call(m,address,size,user)
        r=self.tape;api=self.sdk[address];x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))
        expected=self.expected_state();actual_state=self.state();require(expected==actual_state,'STATE_BEFORE_SDK '+str((self.case['id'],self.step_index,self.calls,api,next((i for i,(a,b) in enumerate(zip(expected,actual_state)) if a!=b),-1))))
        kind,*args=r.take('i3Q');label=r.text();require(kind==api,'SDK_ORDER '+str((self.case['id'],self.step_index,self.calls,kind,api)))
        actual=[0,0,0]
        if api==1:actual[0]=reg('RDX')&0xffffffff
        elif api==2:actual[:2]=[reg('RDX'),reg('R8')]
        elif api==4:actual[0]=reg('RDX')&0xffffffff
        elif api in [5,6,7]:actual[:2]=[reg('RDX'),reg('R8')&0xffffffff]
        elif api==8:
            descriptor=reg('RDX')-self.base;require(descriptor in [sorting.KEYS[self.bot],sorting.VALUES[self.bot]],'RESIZE_UNKNOWN_ARRAY')
            actual=[1 if descriptor==sorting.KEYS[self.bot] else 2,reg('R8')&0xffffffff,reg('R9')&0xffffffff]
        require(actual==args,'SDK_ARGUMENTS '+str((self.case['id'],self.calls,api,actual,args)))
        if api==8:
            for index in [1,2]:flag,data=self.read_array();self.place(index,flag,data)
        reply,error=r.take('QI');self.validate_reply(api,args,label,reply)
        if api==6:m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,0 if label is None else self.string(label)))
        elif api==7:m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',reply));m.reg_write(x.UC_X86_REG_XMM0,reply)
        else:m.reg_write(x.UC_X86_REG_RAX,reply)
        m.mem_write(self.base+shared.CFG[self.bot]['error'],struct.pack('<I',error));self.calls+=1;self.api_counts[api]=self.api_counts.get(api,0)+1
        for e in self.case['effects']:
            if e['api']==api and e['n']==self.api_counts[api]:self.effect(e['name'],e['value'])
    def validate_reply(self,api,args,label,reply):
        t=self.step;expected=reply
        if api==1:expected=t['info']&MASK
        elif api==2:expected=int(t['select']!=0)
        elif api==3:expected=t['totals'][min(self.total_calls,len(t['totals'])-1)]&MASK;self.total_calls+=1
        elif api==4:
            self.selected=args[0];expected=t['deals'][self.selected]['ticket'] if self.selected<len(t['deals']) else 0
        elif api in [5,6,7]:
            require(0<=self.selected<len(t['deals']),'NO_SELECTED_DEAL');d=t['deals'][self.selected];require(args[0]==d['ticket'],'REPLY_WRONG_TICKET')
            if api==5:
                name={3:'types',4:'entries',12:'positions',11:'magics'}[args[1]];key=(self.selected,name);n=self.reads.get(key,0);expected=d[name][min(n,len(d[name])-1)]&MASK;self.reads[key]=n+1
            elif api==6:require(label==d['symbol'],'WRONG_STRING_REPLY');expected=0
            else:expected=bit(d[{9:'profit',7:'commission',8:'swap'}[args[1]]])
        require(reply==expected,'SDK_REPLY_NOT_INPUT '+str((self.case['id'],api,reply,expected)))
    def run(self,c,tape):
        self.case=c;self.tape=Reader(tape);self.calls=0;self.api_counts={};self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for f in self.fs:self.put(f,c['values'][f[0]])
        m.mem_write(self.base+self.c['counts'],struct.pack('<'+'i'*self.rows,*c['counts']))
        self.place(1,c['flags'][0],struct.pack('<'+'Q'*len(c['keys']),*c['keys']));self.place(2,c['flags'][1],struct.pack('<'+'q'*len(c['owners']),*c['owners']))
        m.mem_write(self.base+self.cfg['string_result'],bytes(12));m.mem_write(self.base+shared.CFG[self.bot]['error'],bytes(4))
        for self.step_index,self.step in enumerate(c['steps']):
            for name,value in self.step['updates'].items():self.effect(name,value)
            self.selected=-1;self.reads={};self.total_calls=0
            for n in sorting.GPRS:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
            for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
            top=0x5001fef8;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
            m.emu_start(self.base+self.c['fn'],0x60000000,timeout=10000000,count=2000000);require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_NO_RETURN')
            require(self.expected_state()==self.state(),'FINAL_STATE '+str((c['id'],self.step_index)))
            require(self.tape.take('Q')[0]==m.reg_read(x.UC_X86_REG_XMM0)&MASK,'RETURN_BITS '+str((c['id'],self.step_index)))
        require(self.tape.pos==len(tape),'TRAILING_TAPE');return tape

def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyHistoryCheck.mq5'
    helpers=[Path(__file__),Path(shared.__file__),Path(sorting.__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py']
    helpers += [ROOT/'danh-gia-doc-lap/strategy-history-20261028-r1/nan-add-cpu-probe.py',ROOT/'danh-gia-doc-lap/strategy-history-20261028-r1/nan-add-cpu-probe.json']
    return dict(original_ex5_sha256=sorting.validation.original_hash(bot),native_body_sha256=CFG[bot]['sha'],sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def records(data,count):
    r=Reader(data);require(r.take('3i')==(MAGIC,1,count),'RESULT_HEADER');out=[]
    for i in range(count):
        id_,n=r.take('2i');require(id_==i and 36<=n<=len(data)-r.pos,'RESULT_BOUNDS');out.append(bytes(r.raw[r.pos:r.pos+n]));r.pos+=n
    require(r.pos==len(data),'RESULT_TRAILING');return out
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases(a.bot);current=identity(a.bot);home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows,a.bot));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    old=json.loads((folder/'baseline.json').read_text());require(all(old[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows,a.bot),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build,'BUILD_REQUIRED');mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}StrategyHistoryCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        def unchanged():
            for n,h in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
            binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        unchanged();files=mt/f'MQL5/Files/bot{a.bot}-strategy-history'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=mt/'MQL5/Presets'/('strategy-history-'+a.run+'.set');ini=mt/('strategy-history-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}StrategyHistoryCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED');unchanged()
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(folder/'mql5-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tapes=records((folder/'mql5-results.bin').read_bytes(),len(rows));o=Native(a.bot);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));count=0;failed=[]
        try:
            for c,tape in zip(rows,tapes):
                try:data=o.run(c,tape);raw+=struct.pack('<2i',c['id'],len(data))+data;count+=o.calls
                except (ValueError,o.uc.UcError) as e:failed.append(dict(case=c['id'],tag=c['tag'],error=str(e)))
        finally:o.close()
        if failed:save(folder/'native-failures.json',dict(cases=len(rows),failed=len(failed),failures=failed));print(json.dumps(dict(cases=len(rows),failed=len(failed),first=failed[:12])));raise SystemExit(1)
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),sdk_calls=count,native_sort_entries=o.sort_visits,host_cpu_additions=o.host_additions,instructions=len(o.covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=count,native_sort_entries=o.sort_visits,host_cpu_additions=o.host_additions)));return
    for name in ['mql5','original']:
        r=json.loads((folder/(name+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    require((folder/'mql5-results.bin').read_bytes()==(folder/'original-results.bin').read_bytes(),'RESULTS_DIFFER')
    result=dict(cases=len(rows),matched=len(rows),failed=0,**SCOPE,limits=['Valid caller strategy indexes, normal-return cases, successful string allocations. Full cache building/searching/sort and repeated calls; MT5 ArrayResize measured. Not fatal array faults, full dispatcher or a full EA pair.'])
    save(folder/'comparison.json',result);print(json.dumps(result))

if __name__=='__main__':main()
