"""Execute all enabled bot1 setup bodies and statistics in one native run.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Evaluator and closed-history bodies are recorders; profile/context/preparation
and the native gates/statistics are real, with no reset between strategies.
"""
import argparse,copy,importlib.util,inspect,json,re,shutil,struct,subprocess,textwrap
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
setup=module('loop_setup_base','cong-cu/kiem-nap-chien-luoc-bot-1-3.py')
gate=module('loop_setup_gate','cong-cu/kiem-vong-chien-luoc-bot-1.py')
chain,full,data=setup.contract(1);BASE=setup.original_class(1,chain,full)
require,sha,save=setup.require,setup.sha,setup.save
SRC=ROOT/'bot-cua-toi-1/source/MQL5';SCRIPT=SRC/'Scripts/bot-cua-toi-1/Bot1RealSetupLoopCheck.mq5'
TEMPLATE=SCRIPT.with_name('Bot1StrategySetupCheck.mq5');MAGIC=0x4c535031;WIDTH=len(chain.NAMES)+len(setup.EXTRA_NAMES)
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
 native_enable_gates_contiguous=True,native_profile_context_preparation_executed=True,
 native_statistics_blocks=True,evaluator_executed=False,full_history_body=False,
 evaluator_and_history_replies_supplied=True,terminal_replies_supplied=True,
 allocation_success_supplied=True,authorization_executed=False,authorization_entry_guarded=True,
 original_ex5_changed=False,between_strategy_register_reset=False,caller_string_copy_register_supplied=True)

def cases():
    rows=[];seeds=data.cases()[:192:8]
    def add(seed,mask,hour,call=0,field=0,value=0):
        c=copy.deepcopy(seed);c.update(id=len(rows),index=0,mask=mask,hour=hour,effect_call=call,effect_field=field,effect_value=value);rows.append(c)
    for mask in [0,255,0x55,0xaa]+[1<<i for i in range(8)]+[255^(1<<i) for i in range(8)]:
        for hour in [0,1]:add(seeds[8],mask,hour)
    for seed in seeds:add(seed,255,len(rows)%2)
    for mask in [1,0x55,255]:
        for call in [1,4]:
            for field in [0,7]:
                for value in [0,1]:add(seeds[8],mask,1,call,field,value)
    return rows

def encode(rows):
    return struct.pack('<3i',data.MAGIC,1,len(rows))+b''.join(data.encode([c])[12:]+struct.pack('<5i',*[c[k] for k in ['mask','hour','effect_call','effect_field','effect_value']]) for c in rows)

def render():
    code=TEMPLATE.read_text(encoding='utf-8-sig')
    code=code.replace('   if(FXPriceReads>=4) { Fault=41;return 0.0; }\n','').replace('prices[FXPriceReads++]','prices[(FXPriceReads++)%4]')
    code=code.replace('ArrayResize(target,SampleCount);for(int j=0;j<SampleCount;j++) target[j]=Sample+250.0*j;',
       'bool series=ArrayGetAsSeries(target);ArraySetAsSeries(target,false);ArrayResize(target,SampleCount);for(int j=0;j<SampleCount;j++) target[j]=Sample+250.0*j;ArraySetAsSeries(target,series);')
    call='Bot1SetupStrategy((uint)index,hl!=0,adjustments,inputs,context_inputs,profile_state,context_state,state);'
    begin=code.index(call);end=code.index('\n   }\n   if(FileTell(source)',begin)
    writes=code[begin+len(call):end].replace('FileWriteInteger(output,id);FileWriteInteger(output,1);','FileWriteInteger(Output,(int)caller_index);').replace('(output,','(Output,')
    for old,new in [('inputs','LoopInputs'),('profile_state','LoopProfile'),('context_state','LoopContext'),('state','LoopPreparation')]:writes=re.sub(r'\b'+old+r'\b',new,writes)
    writes+='\n      int n=ArraySize(LoopPreparation.indicator_values);FileWriteInteger(Output,n);bool series=ArrayGetAsSeries(LoopPreparation.indicator_values);for(int i=0;i<n;i++)FileWriteLong(Output,(long)ValueBits(LoopPreparation.indicator_values[series ? n-1-i : i]));\n'
    eval_source=(SRC/'Include/bot-cua-toi-1/Bot1EvaluationWithDisplay.mqh').read_text();a=eval_source.index('Bot1EntryLevelDecision Bot1EvaluateWithDisplay(')
    signature=eval_source[a:eval_source.index('\n{',a)].replace('Bot1EvaluateWithDisplay','LoopEvaluate',1)
    setters=''.join(f'case {i}:LoopFlags.run_strategy_{c}=value;break;' for i,c in enumerate('abcdefgh'))
    getters=''.join(f'if(LoopFlags.run_strategy_{c})mask|={1<<i};' for i,c in enumerate('abcdefgh'))
    probe='''
#include "../../Include/bot-cua-toi-1/Bot1EvaluationWithDisplay.mqh"
#include "../../Include/bot-cua-toi-1/Bot1StrategyHistory.mqh"
#include "../../Include/bot-cua-toi-1/Bot1StrategySelection.mqh"
Bot1PreparationInputs LoopInputs;Bot1PreparationState LoopPreparation;Bot1ProfileRuntimeState LoopProfile;Bot1StrategyContextState LoopContext;
Bot1StrategySelectionInput LoopFlags;int Output,LoopCalls,HistoryCalls,EffectCall,EffectField,EffectValue;
void SetFlag(const int field,const bool value){switch(field){SETTERS}}
uint LoopMask(){uint mask=0;GETTERS return mask;}
SIGNATURE
{
WRITES
   LoopCalls++;if(LoopCalls==EffectCall)SetFlag(EffectField,EffectValue!=0);
   return BOT1_LEVEL_STOP;
}
double LoopHistory(const uchar &show_tester,const string &symbol,const int &magic,const uint &current,int &closed[],Bot1StrategyHistoryCache &cache)
{HistoryCalls++;closed[current]=(int)current+2;return 17.5*(double)(current+1);}
#define Bot1EvaluateWithDisplay LoopEvaluate
#define Bot1StrategyClosedProfit LoopHistory
#include "../../Include/bot-cua-toi-1/Bot1StrategyDispatcher.mqh"
#undef Bot1EvaluateWithDisplay
#undef Bot1StrategyClosedProfit
'''.replace('SETTERS',setters).replace('GETTERS',getters).replace('SIGNATURE',signature).replace('WRITES',writes)
    api=SCRIPT.with_name('Bot1StrategyLoopCheck.mq5').read_text();a=api.index('   Bot1NfpFilterSettings',api.index('int OnStart()'));z=api.index('   for(int k=0;',a);decl=api[a:z]
    for token in ['Bot1PreparationInputs preparation_inputs;','Bot1PreparationState preparation;','Bot1ProfileRuntimeState profile_state;','Bot1StrategyContextInputs context_inputs;','Bot1StrategyContextState context_state;','Bot1ProfileAdjustments adjustments;']:decl=decl.replace(token,'')
    for name in ['preparation_inputs','preparation','profile_state','context_inputs','context_state','adjustments']:decl=decl.replace('ZeroMemory('+name+');','')
    decl=decl.replace('preparation_inputs.symbol=_Symbol;context_inputs.base_magic=0;','');decl=re.sub(r'\bstate\b','evaluation_state',decl)
    a=api.index('   Bot1RunEnabledStrategies(');dispatch=api[a:api.index(';',a)+1].replace('LoopHL','hl!=0').replace('LoopHour','hour!=0');dispatch=re.sub(r'\bstate\b','evaluation_state',dispatch)
    for old,new in [('preparation_inputs','LoopInputs'),('preparation','LoopPreparation'),('profile_state','LoopProfile'),('context_state','LoopContext')]:dispatch=re.sub(r'\b'+old+r'\b',new,dispatch)
    tail='''
      int mask=FileReadInteger(source),hour=FileReadInteger(source);EffectCall=FileReadInteger(source);EffectField=FileReadInteger(source);EffectValue=FileReadInteger(source);
      for(int i=0;i<8;i++)SetFlag(i,(mask&(1<<i))!=0);LoopCalls=0;HistoryCalls=0;
DECL
      for(int i=0;i<8;i++){loop_closed[i]=10+i;loop_total[i]=10.25+i;loop_average[i]=-300.5-i;}
      long position=(long)FileTell(Output);FileWriteInteger(Output,id);FileWriteInteger(Output,0);
DISPATCH
      long finished=(long)FileTell(Output);FileSeek(Output,position+4,SEEK_SET);FileWriteInteger(Output,LoopCalls);FileSeek(Output,finished,SEEK_SET);
      FileWriteInteger(Output,(int)LoopMask());FileWriteInteger(Output,HistoryCalls);
      for(int i=0;i<8;i++)FileWriteInteger(Output,loop_closed[i]);
      for(int i=0;i<8;i++)FileWriteLong(Output,(long)ValueBits(loop_total[i]));
      for(int i=0;i<8;i++)FileWriteLong(Output,(long)ValueBits(loop_average[i]));
'''.replace('DECL',decl).replace('DISPATCH',dispatch)
    code=code[:begin]+tail+code[end:]
    for old,new,typ in [('inputs','LoopInputs','Bot1PreparationInputs'),('state','LoopPreparation','Bot1PreparationState'),('profile_state','LoopProfile','Bot1ProfileRuntimeState'),('context_state','LoopContext','Bot1StrategyContextState')]:
        code=code.replace(typ+' '+old+';','');code=re.sub(r'\b'+old+r'\b',new,code)
    code=code.replace('int output=FileOpen','Output=FileOpen');code=re.sub(r'\boutput\b','Output',code)
    code=code.replace('FileWriteInteger(Output,1398100017);',f'FileWriteInteger(Output,{MAGIC});')
    code=code.replace('count*56','count*76').replace('bot1-strategy-setup','bot1-real-setup-loop')
    code=code.replace('double ExtraDouble(',probe+'\ndouble ExtraDouble(',1)
    return code

env=dict(setup.__dict__,chain=chain,full=full,bot=1)
original_source=textwrap.dedent(inspect.getsource(BASE.run))
initialize=original_source[:original_source.index('    p=self.profiles[self.index];preloads=')].replace('def run(self,row):','def initialize(self,row):',1)
exec(compile(initialize,__file__,'exec'),env)
capture='def capture(self):\n    c=self.case;k=self.ctx_cfg;m=self.m;array=0x62190;prep_comment=0x62480;tick=0x67750;calendar=0x67790\n'+original_source[original_source.index('    words=self.loaded+'):]
exec(compile(capture,__file__,'exec'),env)

class Native(BASE):
    initialize=env['initialize'];capture=env['capture']
    def __init__(self):
        super().__init__()
        for off in [0xc30,0x5880,0x3d6c0,0x4d260]:self.m.hook_add(self.uc.UC_HOOK_CODE,self.protected,begin=self.base+off,end=self.base+off)
        for off in [0x18aa0,0x1efa0]:self.m.hook_add(self.uc.UC_HOOK_CODE,self.boundary,begin=self.base+off,end=self.base+off)
    def protected(self,m,address,size,user):raise RuntimeError('AUTHORIZATION_OUTSIDE_SETUP_LOOP')
    def prefix_visit(self,m,address,size,user):
        off=address-self.base
        if off in gate.PROFILE:
            self.index=gate.PROFILE.index(off);self.phase='profile';self.written=set();self.prep_calls=0;self.after=self.base+self.ctx_cfg['stops'][self.index]+self.call_size
        if self.phase=='profile' and address==self.base+self.stops[self.index]:
            require(self.required.issubset(self.written),'PROFILE_FIELDS_MISSING');self.phase='context'
        if self.phase=='preparation' and address==self.after:self.phase='after-prepare'
    def call(self,m,address,size,user):
        if self.apis[address]!=1001:return super().call(m,address,size,user)
        x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));n=self.price_reads;self.price_reads+=1;value=[2.,3.,4.,5.][n%4]
        symbol=setup.text(self,reg('RDX'));raw=struct.pack('<d',value);m.mem_write(self.base+self.cfg['slot'],raw);m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'))
        for word in [setup.cx.currency.entry_check.text_hash(symbol),reg('R8')&0xffffffff,reg('R9')&0xffffffff,setup.cx.currency.bits(value)]:self.fx_price_hash=setup.cx.event(self.fx_price_hash,word)
        self.fx_service_hash=setup.cx.event(self.fx_service_hash,11);self.all_service_hash=setup.cx.event(self.all_service_hash,11)
    def mask(self):return sum(int(self.m.mem_read(self.base+0x6a580+8*i,1)[0]!=0)<<i for i in range(8))
    def boundary(self,m,address,size,user):
        x=self.x;sp=m.reg_read(x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(sp,8))[0]
        require(self.base+0x12424<=ret<self.base+0x16730,'CHILD_RETURN_OUTSIDE_LOOP')
        if address==self.base+0x18aa0:
            require(self.phase=='after-prepare' and m.reg_read(x.UC_X86_REG_RCX)==self.index and self.prep_calls==1,'EVALUATOR_BOUNDARY')
            words,comment=self.capture();self.records.append((self.index,words,comment,self.array_values()))
            if len(self.records)==self.row['effect_call']:m.mem_write(self.base+0x6a580+8*self.row['effect_field'],bytes([self.row['effect_value']]))
            self.phase='after-evaluation'
        else:
            current=self.value(0x678f4,'I');require(current<8,'HISTORY_INDEX');self.history_calls+=1
            m.mem_write(self.base+0x67940+4*current,struct.pack('<i',current+2));m.reg_write(x.UC_X86_REG_XMM0,setup.cx.currency.bits(17.5*(current+1)))
        m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret)
    def array_values(self):
        n=struct.unpack('<I',self.m.mem_read(self.base+0x62198,4))[0];ptr=struct.unpack('<Q',self.m.mem_read(self.base+0x621ac,8))[0]
        return struct.pack('<i',n)+bytes(self.m.mem_read(ptr,8*n))
    def run(self,row):
        self.initialize(row);self.row=row;self.records=[];self.history_calls=0;m,x=self.m,self.x
        for i in range(8):m.mem_write(self.base+0x6a580+8*i,bytes([(row['mask']>>i)&1]))
        m.reg_write(x.UC_X86_REG_RBP,self.base+0x5c0);m.reg_write(x.UC_X86_REG_RSI,row['hour'])
        m.mem_write(self.base+0x67940,struct.pack('<8i',*[10+i for i in range(8)]))
        m.mem_write(self.base+0x69f80,struct.pack('<8d',*[10.25+i for i in range(8)]))
        m.mem_write(self.base+0x67ad0,struct.pack('<8d',*[-300.5-i for i in range(8)]))
        m.emu_start(self.base+0x12424,self.base+0x16730,timeout=10000000,count=4000000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+0x16730 and not self.error,'LOOP_NOT_FINISHED')
        result=bytearray(struct.pack('<2i',row['id'],len(self.records)))
        for index,words,comment,array in self.records:result+=struct.pack('<i'+'Q'*WIDTH,index,*words)+setup.cx.text_bytes(comment)+array
        return bytes(result)+struct.pack('<2i',self.mask(),self.history_calls)+bytes(m.mem_read(self.base+0x67940,32))+bytes(m.mem_read(self.base+0x69f80,64))+bytes(m.mem_read(self.base+0x67ad0,64))

def identity():
    current=setup.identity(1,chain);current['sources_sha256']={p.relative_to(SRC).as_posix():sha(p) for p in setup.cx.pub.closure(SCRIPT,SRC)}
    for p in [Path(__file__),Path(gate.__file__),TEMPLATE,SCRIPT.with_name('Bot1StrategyLoopCheck.mq5')]:current['helpers_sha256'][p.relative_to(ROOT).as_posix()]=sha(p)
    current['tool_sha256']=sha(Path(__file__));return current

def parse(raw,count):
    require(raw[:16]==struct.pack('<4i',MAGIC,1,count,WIDTH),'HEADER');pos=16;out=[]
    for i in range(count):
        start=pos;cid,n=struct.unpack_from('<2i',raw,pos);pos+=8;require(cid==i and 0<=n<=8,'CASE_HEADER')
        for _ in range(n):
            pos+=4+8*WIDTH;length=struct.unpack_from('<i',raw,pos)[0];pos+=4+2*length
            size=struct.unpack_from('<i',raw,pos)[0];require(0<=size<=100,'ARRAY_LENGTH');pos+=4+8*size
        pos+=168;out.append(raw[start:pos])
    require(pos==len(raw),'TRAILING_OUTPUT');return out

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':
        code=render();require(not SCRIPT.exists() or SCRIPT.read_text(encoding='utf-8-sig')==code,'SOURCE_EXISTS');SCRIPT.write_text(code,encoding='utf-8',newline='\n');print(SCRIPT);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases();current=identity();folder=ROOT/'bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the'/a.run;header=struct.pack('<4i',MAGIC,1,len(rows),WIDTH)
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),width=WIDTH)));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build,'BUILD_REQUIRED');mt=ROOT.parent/'.local/mt5-bot1-thread-20261025';receipt=ROOT/'bot-cua-toi-1/bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=SCRIPT.relative_to(SRC)
        require(build['target']==script.as_posix() and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/script.with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/'MQL5/Files/bot1-real-setup-loop'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('real-setup-'+a.run+'.set');ini=mt/('real-setup-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1RealSetupLoopCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        parse((folder/'mql5-results.bin').read_bytes(),len(rows));save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        native=Native();raw=bytearray(header);calls=0
        try:
            for c in rows:raw+=native.run(c);calls+=len(native.records)
        except Exception as e:save(folder/'original-failure.json',dict(case=c['id'],error=str(e)));raise
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        parse(raw,len(rows));save(folder/'original-run.json',dict(**current,cases=len(rows),preparation_calls=calls,result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),preparation_calls=calls)));return
    a_raw,b_raw=[(folder/(name+'-results.bin')).read_bytes() for name in ['original','mql5']]
    for name,raw in [('original',a_raw),('mql5',b_raw)]:
        report=json.loads((folder/(name+'-run.json')).read_text());require(all(report[k]==v for k,v in current.items()) and report['result_sha256']==__import__('hashlib').sha256(raw).hexdigest(),'RUN_CHANGED')
    failed=[dict(case=i,first_byte=next((j for j,(u,v) in enumerate(zip(x,y)) if u!=v),min(len(x),len(y)))) for i,(x,y) in enumerate(zip(parse(a_raw,len(rows)),parse(b_raw,len(rows)))) if x!=y]
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:8],**SCOPE);save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
