"""Compare OnInit context, first preparation and tail in one native run.

generate | prepare|mql5 --build BUILD|original|compare RUN.
The already verified preparation recorder is extended only at its start.
"""
import copy,importlib.util,inspect,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('context_preparation_flow',ROOT/'cong-cu/kiem-noi-chuan-bi-khoi-dong-bot-1.py')
p=importlib.util.module_from_spec(spec);spec.loader.exec_module(p)
j,boot,require,sha=p.j,p.boot,p.require,p.sha
PREP_CASES=p.cases();PREP_RENDER=j.render;PREP_IDENTITY=p.identity
RENAMES={'Magic':'Context.magic','OrderComment':'Context.order_comment','Seed':'ContextInputs.base_magic'}
def name(value):
    for old,new in [('BootContext.','Context.'),('BootInputs.','ContextInputs.'),('BootDaily.','Daily.'),
                    ('BootState.','Startup.'),('BootHistory.','History.'),('BootPanel.','Panel.'),('BootPreparation.','Inputs.')]:
        if value.startswith(old):return new+value[len(old):]
    return 'ChartName' if value=='BootChartSymbol' else value
for i,(n,k,r) in enumerate(j.FIELDS):j.FIELDS[i]=(RENAMES.get(n,n),k,r)
CONTEXT_FIELDS=[(name(n),k,r) for n,k,r in boot.FIELDS]+[(name(n),'s',r) for n,r in boot.TEXTS]
for f in CONTEXT_FIELDS:
    found=next((item for item in j.FIELDS if item[2]==f[2]),None)
    require(found is None or found==f,'CONTEXT_ALIAS_MISMATCH '+str(f))
    if found is None:j.FIELDS.append(f)
CALL='Bot1InitializeStartupContextFlow(ChartName,ContextInputs,Context,History,Daily,Startup,Inputs,P,Entry,Nfp,Interest,Cpi,Manager,Queue,Levels,MinimumSpread,FridayClosed,TailBars,Show,Tester,HistoryWindow,Balance,Panel,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,State,TailState)'

def add_context(c,context):
    c=copy.deepcopy(c)
    for old,new in RENAMES.items():c['values'][new]=c['values'].pop(old)
    for (n,_,_),v in zip(boot.FIELDS,context['values']):c['values'][name(n)]=v
    for (n,_),v in zip(boot.TEXTS,context['texts']):c['values'][name(n)]=v
    return c

def cases():
    initial=boot.cases()[0];base=PREP_CASES;out=[]
    for c in base:out.append(add_context(c,initial))
    for ctx in boot.cases():
        c=add_context(base[0],ctx);c['tag']='context-then-preparation';out.append(c)
    for i,c in enumerate(out):c['id']=i
    return out

def render():
    code=PREP_RENDER()
    include='#include "../../Include/bot-cua-toi-1/Bot1StartupPreparationFlow.mqh"'
    replacement=include+'\n#include "../../Include/bot-cua-toi-1/Bot1StrategyContext.mqh"\n#include "../../Include/bot-cua-toi-1/Bot1StrategyHistory.mqh"\n#include "../../Include/bot-cua-toi-1/Bot1DailyLossGuard.mqh"\n#define Print MockPrint\n#include "../../Include/bot-cua-toi-1/Bot1StartupContext.mqh"\n#undef Print\n#include "../../Include/bot-cua-toi-1/Bot1StartupContextFlow.mqh"'
    require(include in code,'CONTEXT_INCLUDE_MARKER');code=code.replace(include,replacement,1)
    declarations='Bot1StrategyContextInputs ContextInputs;Bot1StrategyContextState Context;Bot1StrategyHistoryCache History;Bot1DailyLossState Daily;Bot1StartupContextState Startup;string ChartName;\n'
    code=code.replace('Bot1StartupTradingState State;',declarations+'Bot1StartupTradingState State;',1)
    require(p.CALL in code,'CONTEXT_CALL_MARKER');code=code.replace(p.CALL,CALL)
    return code.replace('bot1-startup-preparation-flow','bot1-startup-context-flow')

class Native(p.Native):
    def __init__(self):
        super().__init__();self.context_phase=False
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.end_context,begin=self.base+0x3c9d,end=self.base+0x3c9d)
    def begin_preparation(self,m,address,size,user):
        first=not self.started;super().begin_preparation(m,address,size,user)
        if first:
            self.context_phase=True;self.prep_phase=False
            self.put_text(0x6a43c,'12345')
            m.reg_write(self.x.UC_X86_REG_R9,self.base+0x5d6e8)
            m.reg_write(self.x.UC_X86_REG_RIP,self.base+0x3827)
    def end_context(self,m,address,size,user):
        require(self.context_phase,'CONTEXT_ENTERED_TWICE');self.context_phase=False;self.prep_phase=True
    def multiply(self,m,address,size,user):
        super().multiply(m,address,size,user);self.cpu_calls+=1

def identity():
    current=PREP_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupContextFlowCheck.mq5'
    current['sources_sha256']={f.relative_to(src).as_posix():sha(f) for f in j.pub.closure(script,src)}
    current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return current

# Use the original runner source for names only; test behavior remains in the
# inherited recorder and native classes. Old evidence and tools are unchanged.
original_path=ROOT/'cong-cu/kiem-noi-khoi-dong-bot-1.py'
temp_spec=importlib.util.spec_from_file_location('context_runner_original',original_path)
temp=importlib.util.module_from_spec(temp_spec);temp_spec.loader.exec_module(temp)
for function in ['execute','main']:
    source=inspect.getsource(getattr(temp,function))
    source=source.replace('Bot1StartupPostPreparationCheck','Bot1StartupContextFlowCheck').replace('bot1-startup-joined','bot1-startup-context-flow').replace('startup-joined-','startup-context-flow-')
    source=source.replace('Continuous after first preparation through normal return only.','Continuous context, first preparation and tail through normal OnInit return.').replace('earlier OnInit and full EA remain unverified.','OnInit before context, exact fatal state and full EA remain unverified.')
    exec(compile(source,__file__,'exec'),j.__dict__)
j.cases=cases;j.render=render;j.identity=identity;j.Native=Native
j.SCOPE=dict(j.SCOPE,native_startup_context_executed=True,caller_xmm6_zero_supplied=True,caller_string_return_buffer_primed=True)
if __name__=='__main__':j.main()
