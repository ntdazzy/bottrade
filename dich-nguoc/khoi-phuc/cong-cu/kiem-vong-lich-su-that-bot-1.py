"""Run real history and sorting across bot1's continuous strategy setup loop.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Only the evaluator remains a recorder. History SDK replies and successful
allocation are supplied; every cache/array state is compared at each service.
"""
import copy,importlib.util,inspect,json,re,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
p=module('history_loop_parent','kiem-vong-chuan-bi-that-bot-1.py')
h=module('history_loop_contract','kiem-lich-su-chien-luoc-bot-1-3.py')
require,sha=p.require,p.sha
SCRIPT=p.SCRIPT.with_name('Bot1RealHistoryLoopCheck.mq5')
BASE_CASES=p.cases;BASE_RENDER=p.render;BASE_ENCODE=p.encode;BASE_IDENTITY=p.identity;BASE_NATIVE=p.Native

def cases():
    rows=[];seed=BASE_CASES()[3]
    def add(tag,flags=(0,0),show=1,info=0,select=1,change=0,profit=10.,commission=-1.):
        c=copy.deepcopy(seed);c.update(id=len(rows),tag=tag,mask=255,hour=1,effect_call=0)
        magic=p.setup.fixture(c,8)['base_magic'];signed=lambda i:struct.unpack('<i',struct.pack('<I',(magic+i)&0xffffffff))[0]
        deals=[]
        for i in range(8):
            deals.extend([h.deal(ticket=100+2*i,position=1000-i,magic=signed(i+1),entry=0,profit=0.,commission=0.,swap=0.),
                          h.deal(ticket=101+2*i,position=1000-i,magic=0,entry=1,profit=profit+i,commission=commission,swap=-.5)])
        steps=[]
        for call in range(8):
            ds=copy.deepcopy(deals)
            if call>0 and change:
                for d in ds:
                    if d['entries']==[0]:d['magics']=[signed(8)]
                if change==2:ds.append(h.deal(ticket=999,position=77,magic=signed(8),entry=0))
            steps.append(h.step(ds,info=info,select=select))
        c['history']=dict(id=c['id'],show=show,count=0,total=-1,flags=list(flags),keys=[777,55],owners=[111,222],errors=1,steps=steps,effects=[])
        rows.append(c);return c
    for flags in [(0,0),(1,0),(0,1),(1,1)]:
        for change in [0,1,2]:add('cache-rebuild-and-reuse',flags=flags,change=change)
    for show in [0,1,255]:
        for info in [0,1]:add('tester-gate',show=show,info=info)
    add('history-select-fails',select=0)
    for value in [0.,1e16,float('inf'),float('-inf')]:add('sum-order',profit=value,commission=-value)
    for left,right in [(0x7ff8000000000041,0xfff8000000000042),(0xfff0000000000043,0x7ff0000000000044)]:
        add('nan-payload',profit=struct.unpack('<d',struct.pack('<Q',left))[0],commission=struct.unpack('<d',struct.pack('<Q',right))[0])
    add('disabled-hour')['hour']=0;add('disabled-strategies')['mask']=0
    return rows

def step_bytes(t):
    raw=bytearray(struct.pack('<3i',t['info'],t['select'],len(t['totals'])))
    raw+=struct.pack('<'+'i'*len(t['totals']),*t['totals'])+struct.pack('<2i',0,len(t['deals']))
    for d in t['deals']:
        raw+=struct.pack('<Q',d['ticket'])+h.text(d['symbol'])
        for name in ['types','entries','positions','magics']:raw+=struct.pack('<i',len(d[name]))+struct.pack('<'+'Q'*len(d[name]),*(v&h.MASK for v in d[name]))
        raw+=struct.pack('<3d',d['profit'],d['commission'],d['swap'])
    return raw

def encode(rows):
    raw=bytearray(struct.pack('<3i',p.data.MAGIC,1,len(rows)))
    for c in rows:
        r=c['history'];raw+=BASE_ENCODE([c])[12:]+struct.pack('<3i',r['show'],r['count'],r['total'])
        raw+=h.array(r['flags'][0],r['keys'],'Q')+h.array(r['flags'][1],r['owners'],'q')+struct.pack('<2i',r['errors'],len(r['steps']))
        for t in r['steps']:data=step_bytes(t);raw+=struct.pack('<i',len(data))+data
    return bytes(raw)

NAMES=['TapeFile','ErrorMode','Counts','Calls','InfoReply','SelectReply','Totals','TotalCalls','Selected','LogicalError','Deal','Deals','Effect','Effects','Number','Bits','Text','KeysState','OwnersState','State','SetField','Begin','End','Record','MockInfo','MockSelect','MockTotal','MockTicket','MockInteger','MockString','MockDouble','MockResize','Next','LoadLongs','ReadEffect','ReadText']
ALIASES=dict(ShowTester='HShowTester',Index='HCurrent',Magic='LoopContext.magic',HistorySymbol='LoopInputs.symbol',ClosedTrades='HClosedTrades',Cache='HCache')
def rename(code):
    for name in NAMES:code=re.sub(r'\b'+name+r'\b','H'+name,code)
    for name,target in ALIASES.items():code=re.sub(r'\b'+name+r'\b',target,code)
    return code.replace('@N@','1').replace('@ROWS@','8')

def render():
    code=BASE_RENDER();template=h.TEMPLATE
    decl=template[template.index('int MockInfo('):template.index('uchar ShowTester;')]
    globals_end=template.index('ulong Bits(')
    globals=template[template.index('uchar ShowTester;'):globals_end]
    globals=globals.replace('uchar ShowTester;uint Index;int Magic;string HistorySymbol;int ClosedTrades[@ROWS@];Bot@N@StrategyHistoryCache Cache;',
       'uchar HShowTester;uint HCurrent;int HClosedTrades[8];Bot1StrategyHistoryCache HCache;')
    definitions=template[globals_end:template.index('int OnStart()')]
    step=template[template.index('         InfoReply=FileReadInteger(input_file);'):template.index('         TotalCalls=0;Selected=-1;double result=')]
    support=rename(globals)+'''\nint HInput;long HOffsets[8];
int HCurrentError(){return (int)HLogicalError;}
void HLoadStep(const int step){long saved=(long)FileTell(HInput);FileSeek(HInput,HOffsets[step],SEEK_SET);int n=0;
'''+rename(step.replace('input_file','HInput'))+'''HTotalCalls=0;HSelected=-1;FileSeek(HInput,saved,SEEK_SET);}
'''+rename(definitions)
    code=code.replace('int FakeLastError() { return 5017; }','int HCurrentError();\nint FakeLastError() { return HCurrentError(); }')
    code=code.replace('if(code!=5017) Fault=30;','if(code!=HCurrentError()) Fault=30;')
    code=code.replace('#include "../../Include/bot-cua-toi-1/Bot1StrategyHistory.mqh"',rename(decl),1)
    anchor='Bot1StrategySelectionInput LoopFlags;';code=code.replace(anchor,support+'\n'+anchor,1)
    old='{HistoryCalls++;closed[current]=(int)current+2;return 17.5*(double)(current+1);}'
    new='{HLoadStep(HistoryCalls);HistoryCalls++;double value=Bot1StrategyClosedProfit(show_tester,symbol,magic,current,closed,cache);HState();FileWriteLong(HTapeFile,(long)HBits(value));return value;}'
    require(old in code,'HISTORY_WRAPPER');code=code.replace(old,new)
    code=code.replace('uint current=0;','').replace('int loop_closed[8];','').replace('Bot1StrategyHistoryCache loop_cache;','')
    code=code.replace('show=0,tester=0,day_switch=0','show=0,day_switch=0')
    for old,new in [('current','HCurrent'),('loop_closed','HClosedTrades'),('loop_cache','HCache'),('tester','HShowTester')]:
        # Change only the entry point's variables, keeping wrapper references intact.
        at=code.index('int OnStart()');code=code[:at]+re.sub(r'\b'+old+r'\b',new,code[at:])
    code=code.replace(' || FileSize(source)!=(ulong)12+(ulong)count*76','')
    anchor='   FileWriteInteger(Output,'+str(p.MAGIC)+');'
    insert='''   HInput=source;HTapeFile=FileOpen(folder+"history-tape.bin",FILE_WRITE|FILE_BIN);if(HTapeFile==INVALID_HANDLE)return 12;
   FileWriteInteger(HTapeFile,1397244721);FileWriteInteger(HTapeFile,1);FileWriteInteger(HTapeFile,count);
'''
    require(anchor in code,'HISTORY_TAPE_HEADER');code=code.replace(anchor,insert+anchor,1)
    anchor='      for(int i=0;i<8;i++)SetFlag(i,(mask&(1<<i))!=0);'
    read='''      HShowTester=(uchar)FileReadInteger(source);HCache.count=FileReadInteger(source);HCache.total=FileReadInteger(source);HCurrent=0;
      int rev=FileReadInteger(source),n=FileReadInteger(source);ArraySetAsSeries(HCache.positions,false);ArrayResize(HCache.positions,n);for(int i=0;i<n;i++)HCache.positions[i]=(ulong)FileReadLong(source);ArraySetAsSeries(HCache.positions,rev!=0);
      rev=FileReadInteger(source);n=FileReadInteger(source);ArraySetAsSeries(HCache.magics,false);ArrayResize(HCache.magics,n);for(int i=0;i<n;i++)HCache.magics[i]=FileReadLong(source);ArraySetAsSeries(HCache.magics,rev!=0);
      HErrorMode=FileReadInteger(source);n=FileReadInteger(source);if(n!=8)return 13;for(int i=0;i<n;i++){int size=FileReadInteger(source);if(size<0 || size>1000000)return 14;HOffsets[i]=(long)FileTell(source);FileSeek(source,size,SEEK_CUR);}
      HCalls=0;HLogicalError=5017;ArrayInitialize(HCounts,0);ArrayResize(HEffects,0);
      FileWriteInteger(HTapeFile,id);long history_size_at=(long)FileTell(HTapeFile);FileWriteInteger(HTapeFile,0);long history_start=(long)FileTell(HTapeFile);
'''
    code=code.replace(anchor,read+anchor,1)
    anchor='      for(int i=0;i<8;i++)FileWriteLong(Output,(long)ValueBits(loop_average[i]));'
    finish='''
      HState();long history_end=(long)FileTell(HTapeFile);FileSeek(HTapeFile,history_size_at,SEEK_SET);FileWriteInteger(HTapeFile,(int)(history_end-history_start));FileSeek(HTapeFile,history_end,SEEK_SET);
'''
    require(anchor in code,'HISTORY_TAPE_END');code=code.replace(anchor,anchor+finish)
    code=code.replace('FileClose(source);FileClose(Output);','FileClose(source);FileClose(Output);FileClose(HTapeFile);')
    return '\n'.join(line.rstrip() for line in code.replace('bot1-real-setup-loop','bot1-real-history-loop').splitlines())+'\n'

class History(h.Native):
    def __init__(self,parent):
        self.parent=parent;self.m=parent.m;self.x=parent.x;self.uc=parent.uc;self.base=parent.base;self.cfg=parent.cfg
        self.bot=1;self.c=h.CFG[1];self.fs=h.fields(1);self.rows=8;self.host=h.HostAddition();self.host_additions=0;self.sort_visits=0
        require(__import__('hashlib').sha256(bytes(self.m.mem_read(self.base+self.c['fn'],self.c['end']-self.c['fn']))).hexdigest()==self.c['sha'],'HISTORY_CODE_CHANGED')
        self.m.mem_map(0x71000000,0x20000)
        self.sdk={0x7ff683f20000+off:api for api,off in {1:0x7c0fd0,2:0x7d84f0,3:0x7d8810,4:0x7d8860,5:0x7d8940,6:0x7d89d0,7:0x7d88b0,8:0x7aa0e0}.items()}
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.sort_entry,begin=self.base+h.sorting.FN[1],end=self.base+h.sorting.FN[1])
        for offset in [0x308,0x311,0x326]:
            address=self.base+self.c['fn']+offset;require(bytes(self.m.mem_read(address,6))==bytes.fromhex('f2410f587500'),'HISTORY_ADD_CHANGED');self.m.hook_add(self.uc.UC_HOOK_CODE,self.addition,begin=address,end=address)
    def string(self,value):return self.parent.string(value)
    def initialize(self,row,tape):
        self.case=row['history'];self.tape=h.Reader(tape);self.calls=0;self.api_counts={};self.step_index=0
        self.m.mem_write(self.base+0x6a530,bytes([self.case['show']]))
        self.m.mem_write(self.base+0x6246c,bytes(4))
        self.m.mem_write(self.base+0x6a314,struct.pack('<2i',self.case['count'],self.case['total']))
        self.place(1,self.case['flags'][0],struct.pack('<'+'Q'*len(self.case['keys']),*self.case['keys']))
        self.place(2,self.case['flags'][1],struct.pack('<'+'q'*len(self.case['owners']),*self.case['owners']))

class Native(BASE_NATIVE):
    def __init__(self,folder):
        super().__init__();self.history=History(self);self.history_return=0;self.tapes=h.records((folder/'history-tape.bin').read_bytes(),len(cases()));self.history_service_calls=0
        for address in self.history.sdk:
            if address not in self.apis:
                if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
                self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.history_finished,begin=self.base+0x12424,end=self.base+0x16730)
    def initialize(self,row):
        super().initialize(row);self.history.initialize(row,self.tapes[row['id']])
    def boundary(self,m,address,size,user):
        if address!=self.base+0x1efa0:return super().boundary(m,address,size,user)
        require(self.history_return==0,'NESTED_HISTORY');self.history_return=struct.unpack('<Q',m.mem_read(m.reg_read(self.x.UC_X86_REG_RSP),8))[0]
        self.history.step_index=self.history_calls;self.history.step=self.row['history']['steps'][self.history_calls];self.history_calls+=1
        self.history.selected=-1;self.history.reads={};self.history.total_calls=0
    def history_finished(self,m,address,size,user):
        if address!=self.history_return:return
        require(self.history.expected_state()==self.history.state(),'HISTORY_RETURN_STATE')
        require(self.history.tape.take('Q')[0]==m.reg_read(self.x.UC_X86_REG_XMM0)&h.MASK,'HISTORY_RETURN_VALUE');self.history_return=0
    def call(self,m,address,size,user):
        if getattr(self,'history_return',0) and address in self.history.sdk:return self.history.call(m,address,size,user)
        return super().call(m,address,size,user)
    def run(self,row):
        result=super().run(row);require(self.history_return==0,'HISTORY_NOT_RETURNED')
        require(self.history.expected_state()==self.history.state(),'HISTORY_FINAL_CACHE');require(self.history.tape.pos==len(self.tapes[row['id']]),'UNUSED_HISTORY_TAPE')
        self.history_service_calls+=self.history.calls;return result

def identity():
    current=BASE_IDENTITY();current['sources_sha256']={f.relative_to(p.SRC).as_posix():sha(f) for f in p.setup.cx.pub.closure(SCRIPT,p.SRC)}
    current['helpers_sha256'].update(h.identity(1)['helpers_sha256']);current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    current['tool_sha256']=sha(Path(__file__));return current

source=inspect.getsource(p.main).replace('bot1-real-setup-loop','bot1-real-history-loop').replace('Bot1RealSetupLoopCheck','Bot1RealHistoryLoopCheck')
source=source.replace("['mql5-results.bin','script-status.bin']","['mql5-results.bin','script-status.bin','history-tape.bin']")
source=source.replace('native=Native();','native=Native(folder);')
source=source.replace('preparation_calls=calls,result_sha256=',"preparation_calls=calls,history_sdk_calls=native.history_service_calls,native_sort_entries=native.history.sort_visits,host_cpu_additions=native.history.host_additions,history_tape_sha256=sha(folder/'history-tape.bin'),result_sha256=")
source=source.replace("result_sha256=sha(folder/'mql5-results.bin'),build=a.build", "result_sha256=sha(folder/'mql5-results.bin'),history_tape_sha256=sha(folder/'history-tape.bin'),build=a.build")
source=source.replace('native=Native(folder);', "require(json.loads((folder/'mql5-run.json').read_text())['history_tape_sha256']==sha(folder/'history-tape.bin'),'HISTORY_TAPE_CHANGED');native=Native(folder);")
source=source.replace("report=json.loads((folder/(name+'-run.json')).read_text());require(", "report=json.loads((folder/(name+'-run.json')).read_text());require(report['history_tape_sha256']==sha(folder/'history-tape.bin'),'HISTORY_TAPE_CHANGED');require(")
source=source.replace("parse(raw,len(rows));save(folder/'original-run.json'","parse(raw,len(rows));native.history.close();save(folder/'original-run.json'")
exec(compile(source,__file__,'exec'),p.__dict__)
p.SCRIPT=SCRIPT;p.render=render;p.cases=cases;p.encode=encode;p.identity=identity;p.Native=Native
p.SCOPE=dict(p.SCOPE,full_history_body=True,native_sort_executed=True,history_cache_preserved_between_strategies=True,history_additions_on_host_cpu=True,evaluator_and_history_replies_supplied=False,evaluator_replies_supplied=True)
if __name__=='__main__':p.main()
