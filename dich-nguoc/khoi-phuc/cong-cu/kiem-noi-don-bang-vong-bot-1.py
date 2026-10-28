"""Compare live symbol routing, real table cleanup and eight strategy gates.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Direct evaluation and complete strategy bodies remain outside this proof.
"""
import copy,importlib.util,inspect,struct,sys,textwrap
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]

def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
route=module('tick_loop_route','kiem-noi-ma-gia-don-bang-bot-1.py')
loop=module('tick_loop_gates','kiem-vong-chien-luoc-bot-1.py')
b=route.b;require,sha=b.require,b.sha
BASE_ENCODE=route.encode;BASE_IDENTITY=route.identity
SCRIPT=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1TickStrategyDispatchCheck.mq5'
HEADER=ROOT/'bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1TickStrategyDispatch.mqh'
b.SOURCES[2]=SCRIPT.relative_to(ROOT/'bot-cua-toi-1/source/MQL5').as_posix()

def cases():
    rows=route.cases()
    for c in rows:c['loop']=[c['id']*17%256,0,0,0,c['id']%2,(c['id']//2)%2,0,0]
    def add(tag,mask,call=0,field=0,value=0,api=0):
        c=copy.deepcopy(rows[0]);c.update(id=len(rows),group=tag,chart='XAUUSD.a',virtual_flag=1 if api else 0)
        c['loop']=[mask,call,field,value,c['id']%2,(c['id']//2)%2,api,1];rows.append(c)
    for mask in range(256):add('all-enable-masks-after-routing',mask)
    for mask in [1,0x55,0xff]:
        for call in [1,4,8]:
            for field in [0,4,7]:
                for value in [0,1]:add('live-gates-between-strategies',mask,call,field,value)
    for api in [3,4,5,6]:
        for mask in [0,0xff]:
            for field in [0,4,7]:add('cleanup-changes-enable-gate',mask,0,field,int(mask==0),api)
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<4i',b.MAGIC,b.VERSION,len(rows),len(rows)))
    for c in rows:raw+=BASE_ENCODE([c])[16:]+struct.pack('<8i',*c['loop'])
    return bytes(raw)

def generated_source():
    folder=SCRIPT.parent;inc=HEADER.parent
    dispatcher=(inc/'Bot1StrategyDispatcher.mqh').read_text(encoding='utf-8-sig')
    begin=dispatcher.index('void Bot1RunEnabledStrategies(');end=dispatcher.index('\n{',begin)
    signature=dispatcher[begin:end].replace('void Bot1RunEnabledStrategies(',
       'bool Bot1RunConfiguredTick(const string &chart_symbol,const uchar &virtual_flag,long &open_tickets[],\n                           ',1)
    import re
    parameters=re.findall(r'\b(\w+)\s*(?:\[\])?\s*(?=,|\))',dispatcher[begin:end])
    require(parameters[0]=='settings' and parameters[-1]=='strategy_average','DISPATCH_PARAMETERS')
    header='#ifndef BOT1_TICK_STRATEGY_DISPATCH_MQH\n#define BOT1_TICK_STRATEGY_DISPATCH_MQH\n#include "Bot1TickStrategyPreparation.mqh"\n#include "Bot1StrategyDispatcher.mqh"\n\n// Native 0x11f3f..0x16730. False leaves the direct evaluator to the caller.\n'+signature+'\n{\n   if(!Bot1PrepareTickStrategy(chart_symbol,inputs.symbol,virtual_flag,state.management.table,open_tickets)) return false;\n   Bot1RunEnabledStrategies('+','.join(parameters)+');\n   return true;\n}\n#endif\n'
    code=route.SCRIPT_PATH.read_text(encoding='utf-8-sig')
    code=code.replace('string CaseSymbol;','')
    cycle=(inc/'Bot1StrategyCycle.mqh').read_text(encoding='utf-8-sig');start=cycle.index('Bot1EntryLevelDecision Bot1SetupEvaluateAndUpdateStatistics(')
    probe=cycle[start:cycle.index('\n{',start)].replace('Bot1SetupEvaluateAndUpdateStatistics','LoopProbe',1)
    globals='''#include "../../Include/bot-cua-toi-1/Bot1StrategyCycle.mqh"
#include "../../Include/bot-cua-toi-1/Bot1StrategySelection.mqh"
Bot1PreparationInputs JoinInputs;Bot1EvaluationPrefixState JoinState;
#define Table JoinState.management.table
#define CaseSymbol JoinInputs.symbol
Bot1StrategySelectionInput LoopFlags;int LoopCalls,LoopIndexes[8],LoopEffectCall,LoopEffectField,LoopEffectValue,LoopFault,LoopCleanupApi,LoopCleanupHit;bool LoopHL,LoopHour;
void SetLoopFlag(const int field,const bool value){switch(field){SETTERS}}
uint LoopMask(){uint mask=0;GETTERS return mask;}
'''
    globals=globals.replace('SETTERS',''.join(f'case {i}:LoopFlags.run_strategy_{c}=value;break;' for i,c in enumerate('abcdefgh')))
    globals=globals.replace('GETTERS',''.join(f'if(LoopFlags.run_strategy_{c})mask|={1<<i};' for i,c in enumerate('abcdefgh')))
    globals+=probe+'''
{
   BeginEvent(8);FileWriteInteger(Fixture,(int)index);FileWriteInteger(Fixture,(int)LoopMask());FileWriteInteger(Fixture,(int)use_hl);FileWriteInteger(Fixture,(int)hour_changed);
   for(int r=0;r<500;r++)for(int c=0;c<3;c++)WriteDouble(Fixture,state.management.table.rows[r][c]);
   WriteArray(Fixture,OpenTickets);WriteRouteText(Fixture,inputs.symbol);
   if(LoopCalls>=8 || use_hl!=LoopHL || hour_changed!=LoopHour)LoopFault|=1;
   else LoopIndexes[LoopCalls++]=(int)index;
   if(LoopCalls==LoopEffectCall && LoopCleanupApi==0)SetLoopFlag(LoopEffectField,LoopEffectValue!=0);
   EndEvent(8);return BOT1_LEVEL_STOP;
}
#define Bot1SetupEvaluateAndUpdateStatistics LoopProbe
#include "../../Include/bot-cua-toi-1/Bot1TickStrategyDispatch.mqh"
#undef Bot1SetupEvaluateAndUpdateStatistics
'''
    globals='void WriteRouteText(const int file,const string value);\n'+globals
    code=code.replace('Bot1VirtualStopState Table;',globals)
    code=code.replace('void ApplyControl(const int api)\n{','void ApplyControl(const int api)\n{\n   if(api==LoopCleanupApi && Hits[api]==LoopCleanupHit)SetLoopFlag(LoopEffectField,LoopEffectValue!=0);',1)
    api=(folder/'Bot1StrategyLoopCheck.mq5').read_text(encoding='utf-8-sig')
    start=api.index('int OnStart()');decl_start=api.index('   Bot1NfpFilterSettings',start);decl_end=api.index('   for(int k=0;',decl_start)
    declarations=api[decl_start:decl_end].replace('Bot1PreparationInputs preparation_inputs;','').replace('Bot1EvaluationPrefixState state;','')
    declarations=re.sub(r'\bpreparation_inputs\b','JoinInputs',declarations);declarations=re.sub(r'\bstate\b','JoinState',declarations)
    call_start=api.index('   Bot1RunEnabledStrategies(',start);call=api[call_start:api.index(';',call_start)+1]
    call=re.sub(r'\bpreparation_inputs\b','JoinInputs',call);call=re.sub(r'\bstate\b','JoinState',call)
    call=call.replace('Bot1RunEnabledStrategies(','result.q=(long)Bot1RunConfiguredTick(chart,virtual_flag,OpenTickets,',1)
    code=code.replace('   int processed=0;',declarations+'\n   int processed=0;',1)
    marker='string chart=ReadChart(handle_in);'
    reads='''
      int mask=FileReadInteger(handle_in);LoopEffectCall=FileReadInteger(handle_in);LoopEffectField=FileReadInteger(handle_in);LoopEffectValue=FileReadInteger(handle_in);LoopHL=FileReadInteger(handle_in)!=0;LoopHour=FileReadInteger(handle_in)!=0;LoopCleanupApi=FileReadInteger(handle_in);LoopCleanupHit=FileReadInteger(handle_in);
      for(int i=0;i<8;i++)SetLoopFlag(i,(mask&(1<<i))!=0);LoopCalls=0;LoopFault=0;ArrayInitialize(LoopIndexes,-1);
'''
    code=code.replace(marker,marker+reads)
    code=code.replace('result.q=(long)Bot1PrepareTickStrategy(chart,CaseSymbol,virtual_flag,Table,OpenTickets);',call.strip())
    code=code.replace('WriteRouteText(output,CaseSymbol);processed++;','WriteRouteText(output,CaseSymbol);FileWriteInteger(output,LoopCalls);FileWriteInteger(output,(int)LoopMask());FileWriteInteger(output,LoopFault);for(int i=0;i<8;i++)FileWriteInteger(output,LoopIndexes[i]);processed++;')
    return header,code.replace('bot1-tick-cleanup','bot1-tick-dispatch')

def generate():
    for path,content in zip([HEADER,SCRIPT],generated_source()):
        require(not path.exists() or path.read_text(encoding='utf-8-sig')==content,'SOURCE_EXISTS '+str(path))
        if not path.exists():path.write_text(content,encoding='utf-8',newline='\n')
    print(SCRIPT)

source=inspect.getsource(route.read_results).replace('b.MAGIC','MAGIC').replace('b.VERSION','VERSION').replace('out[cid]=rd.raw[at:rd.pos]',"rd.take('11i');out[cid]=rd.raw[at:rd.pos]")
b.Reader=route.Reader;exec(compile(source,__file__,'exec'),b.__dict__)
source=inspect.getsource(b.read_fixtures).replace("else:raise ValueError('UNKNOWN_API_RECORD '+str(api))", "elif api==8:payload=(rd.take('4i'),rd.blob(12000),rd.array(),rd.nullable_text())\n            else:raise ValueError('UNKNOWN_API_RECORD '+str(api))")
exec(compile(source,__file__,'exec'),b.__dict__)

class Native(route.Native):
    def __init__(self,fixtures):
        super().__init__(fixtures);self.m.hook_add(self.uc.UC_HOOK_CODE,self.strategy,begin=self.base+loop.START,end=self.base+loop.END)
    def visit(self,m,address,size,user):
        if loop.START<=address-self.base<=loop.END:return b.smoke.Original.visit(self,m,address,size,user)
        return super().visit(m,address,size,user)
    def mask(self):return sum(int(self.m.mem_read(self.base+0x6a580+8*i,1)[0]!=0)<<i for i in range(8))
    def before_route(self,c):
        super().before_route(c);self.loop_calls=[]
        for i in range(8):self.m.mem_write(self.base+0x6a580+8*i,bytes([(c['loop'][0]>>i)&1]))
    def control(self,api):
        super().control(api);_,_,field,value,_,_,effect_api,hit=self.case['loop']
        if api==effect_api and self.hits[api]==hit:self.m.mem_write(self.base+0x6a580+8*field,bytes([value]))
    def strategy(self,m,address,size,user):
        off=address-self.base
        if off not in loop.PROFILE:return
        index=loop.PROFILE.index(off);api,before,payload,after=self.records[self.event];self.event+=1
        require(api==8 and self.snapshot()==before,'STRATEGY_BEFORE_STATE')
        words,table,tickets,symbol=payload;row=self.case['loop']
        require(words==(index,self.mask(),row[4],row[5]),'STRATEGY_GATE_ARGUMENTS')
        require(table==bytes(m.mem_read(self.base+0x62590,12000)) and tickets==self.array() and symbol==self.read_nullable(0x67918),'STRATEGY_SHARED_DATA')
        self.loop_calls.append(index)
        if len(self.loop_calls)==row[1] and row[6]==0:m.mem_write(self.base+0x6a580+8*row[2],bytes([row[3]]))
        require(self.snapshot()==after,'STRATEGY_AFTER_STATE');m.reg_write(self.x.UC_X86_REG_RIP,self.base+loop.NEXT[index])

source=textwrap.dedent(inspect.getsource(route.BASE_NATIVE.run_case))
source=source.replace("m.emu_start(self.base+FN[c['kind']],0x60000000,timeout=10000000,count=20000000)","self.before_route(c)\n    m.emu_start(self.base+0x11f3f,self.base+0x16730,timeout=10000000,count=20000000)")
source=source.replace("require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_DID_NOT_RETURN')","require(m.reg_read(x.UC_X86_REG_RIP)==self.base+(0x12004 if self.route==0 else 0x16730),'NATIVE_BRANCH_END')\n    require(self.cleanup_calls==int(self.route==1 and c['virtual_flag']!=0),'CLEANUP_CALL_COUNT')")
source=source.replace('n,series,data=self.array()','value=self.route\n    n,series,data=self.array()')
source=source.replace("+struct.pack('<2i',n,series)+data","+struct.pack('<2i',n,series)+data+route.boot.text(self.read_nullable(0x6a428))+route.boot.text(self.read_nullable(0x67918))+struct.pack('<11i',len(self.loop_calls),self.mask(),0,*(self.loop_calls+[-1]*(8-len(self.loop_calls))))")
exec(compile(source,__file__,'exec'),b.__dict__);Native.run_case=b.run_case

def identity():
    current=BASE_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5'
    current['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in route.route.pub.closure(SCRIPT,src)}
    for path in [Path(__file__),Path(loop.__file__),route.SCRIPT_PATH,SCRIPT.with_name('Bot1StrategyLoopCheck.mq5'),SCRIPT.with_name('Bot1EvaluationBridgeAPICompile.mq5')]:current['helpers_sha256'][path.relative_to(ROOT).as_posix()]=sha(path)
    current['tool_sha256']=sha(Path(__file__));return current
source=route.source.replace('bot1-tick-cleanup','bot1-tick-dispatch').replace('Bot1TickStrategyPreparationCheck','Bot1TickStrategyDispatchCheck').replace('kiem-noi-ma-gia-don-bang-bot-1.py','kiem-noi-don-bang-vong-bot-1.py')
source=source.replace('strategy_loop_executed=False','strategy_loop_executed=True,full_strategy_bodies=False,strategy_calls_replaced_by_recorder=True')
source=source.replace('Continuous bot1 symbol routing and optional real cleanup only.','Continuous bot1 symbol routing, real cleanup and live eight-strategy gates; strategy bodies replaced by recorders.')
exec(compile(source,__file__,'exec'),b.__dict__)
b.cases=cases;b.encode=encode;b.Original=Native;b.identity=identity
if __name__=='__main__':
    if len(sys.argv)>1 and sys.argv[1]=='generate':generate()
    else:b.main()
