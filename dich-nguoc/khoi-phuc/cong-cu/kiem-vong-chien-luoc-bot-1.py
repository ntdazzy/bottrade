"""Compare all eight live enable gates in the native bot-1 strategy loop.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Each complete strategy is replaced by a recorder on both sides. The native
gates execute continuously, without resetting registers between strategies.
"""
import argparse
import importlib.util
import json
import re
import shutil
import struct
import subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
MAGIC=0x4c503131
spec=importlib.util.spec_from_file_location('loop_hour',ROOT/'cong-cu/kiem-gio-chien-luoc-bot-1-3.py')
hour=importlib.util.module_from_spec(spec);spec.loader.exec_module(hour)
require,sha,save,pub=hour.require,hour.sha,hour.save,hour.pub
START=0x12424
END=0x16730
PROFILE=[0x12469,0x12fd5,0x138d9,0x14104,0x147fe,0x14f29,0x15821,0x15f01]
NEXT=[0x12fb9,0x138bc,0x140f1,0x147e1,0x14f16,0x1580e,0x15eee,0x16730]
SCOPE=dict(full_ea=False,full_strategy_bodies=False,native_enable_gates_contiguous=True,
           strategy_calls_replaced_by_recorder=True,input_mutations_supplied=True,original_ex5_changed=False)


def cases():
    rows=[]
    def add(mask,call=0,field=0,value=0):
        i=len(rows);rows.append((i,mask,call,field,value,i%2,(i//2)%2))
    for mask in range(256):add(mask)
    for mask in [0,1,0x55,0x80,0xff]:
        for call in range(1,9):
            for field in range(8):
                for value in [0,1]:add(mask,call,field,value)
    return rows


def encoded(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<7i',*row) for row in rows)


def generate():
    source=ROOT/'bot-cua-toi-1/source/MQL5';folder=source/'Scripts/bot-cua-toi-1'
    cycle=(source/'Include/bot-cua-toi-1/Bot1StrategyCycle.mqh').read_text(encoding='utf-8-sig')
    start=cycle.index('Bot1EntryLevelDecision Bot1SetupEvaluateAndUpdateStatistics(')
    end=cycle.index('\n{',start)
    signature=cycle[start:end].replace('Bot1SetupEvaluateAndUpdateStatistics','LoopProbe',1)
    setters='\n'.join(f'      case {i}: LoopFlags.run_strategy_{c}=value;break;' for i,c in enumerate('abcdefgh'))
    getters='\n'.join(f'   if(LoopFlags.run_strategy_{c}) mask|=(uint){1<<i};' for i,c in enumerate('abcdefgh'))
    pre=f'''#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1StrategyCycle.mqh"
#include "../../Include/bot-cua-toi-1/Bot1StrategySelection.mqh"
Bot1StrategySelectionInput LoopFlags;
int LoopCalls,LoopIndexes[8],LoopEffectCall,LoopEffectField,LoopEffectValue,LoopFault;
bool LoopHL,LoopHour;
void SetLoopFlag(const int field,const bool value)
{{
   switch(field)
   {{
{setters}
   }}
}}
uint LoopMask()
{{
   uint mask=0;
{getters}
   return mask;
}}
{signature}
{{
   if(LoopCalls>=8 || use_hl!=LoopHL || hour_changed!=LoopHour){{LoopFault|=1;return BOT1_LEVEL_STOP;}}
   LoopIndexes[LoopCalls++]=(int)index;
   if(LoopCalls==LoopEffectCall)SetLoopFlag(LoopEffectField,LoopEffectValue!=0);
   return BOT1_LEVEL_STOP;
}}
#define Bot1SetupEvaluateAndUpdateStatistics LoopProbe
#include "../../Include/bot-cua-toi-1/Bot1StrategyDispatcher.mqh"
#undef Bot1SetupEvaluateAndUpdateStatistics
'''
    api=(folder/'Bot1EvaluationBridgeAPICompile.mq5').read_text(encoding='utf-8-sig')
    a=api.index('void OnStart()');b=api.index('   Bot1SetupAndEvaluate(',a)
    declarations=api[api.index('{',a)+1:b]
    require(declarations.count('ZeroMemory(')>10,'API_DECLARATIONS_CHANGED')
    call=api[b:api.index(';',b)+1];require(call.startswith('   Bot1SetupAndEvaluate(0,false,'),'API_CALL_CHANGED')
    call=call.replace('Bot1SetupAndEvaluate(0,false,','Bot1RunEnabledStrategies(LoopFlags,LoopHL,',1)
    require(call.endswith(',display);'),'API_CALL_TAIL_CHANGED')
    call=call[:-len(',display);')]+',display,LoopHour,loop_closed,loop_cache,loop_total,loop_average);'
    body='''
int OnStart()
{
   if(CheckRun=="")return 1;
   string folder="bot1-strategy-loop\\\\"+CheckRun+"\\\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4c503131 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
DECLARATIONS
   int loop_closed[8];double loop_total[8],loop_average[8];Bot1StrategyHistoryCache loop_cache;
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file),mask=FileReadInteger(file);
      LoopEffectCall=FileReadInteger(file);LoopEffectField=FileReadInteger(file);LoopEffectValue=FileReadInteger(file);
      LoopHL=FileReadInteger(file)!=0;LoopHour=FileReadInteger(file)!=0;
      for(int i=0;i<8;i++)SetLoopFlag(i,(mask&(1<<i))!=0);
      LoopCalls=0;LoopFault=0;ArrayInitialize(LoopIndexes,-1);
CALL
      FileWriteInteger(output,id);FileWriteInteger(output,LoopCalls);FileWriteInteger(output,(int)LoopMask());FileWriteInteger(output,LoopFault);
      for(int i=0;i<8;i++)FileWriteInteger(output,LoopIndexes[i]);
   }
   if(FileTell(file)!=FileSize(file))return 5;
   FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''.replace('DECLARATIONS',declarations).replace('CALL',call)
    path=folder/'Bot1StrategyLoopCheck.mq5';require(not path.exists(),'SOURCE_EXISTS')
    path.write_text(pre+body,encoding='utf-8',newline='\n');print(path)


class Native(hour.parent.Original):
    def __init__(self):
        super().__init__(1)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.strategy,begin=self.base+START,end=self.base+END)

    def strategy(self,m,address,size,user):
        offset=address-self.base
        if offset not in PROFILE:return
        index=PROFILE.index(offset);require(len(self.calls)<8,'TOO_MANY_STRATEGIES');self.calls.append(index)
        if len(self.calls)==self.row[2]:
            m.mem_write(self.base+0x6a580+8*self.row[3],bytes([self.row[4]]))
        m.reg_write(self.x.UC_X86_REG_RIP,self.base+NEXT[index])

    def run(self,row):
        self.row,self.calls=row,[];m,x=self.m,self.x
        for i in range(8):m.mem_write(self.base+0x6a580+8*i,bytes([(row[1]>>i)&1]))
        for reg in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+reg),0)
        m.reg_write(x.UC_X86_REG_RSP,0x5001fe00);m.reg_write(x.UC_X86_REG_EFLAGS,0x202)
        m.emu_start(self.base+START,self.base+END,timeout=1000000,count=10000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+END,'LOOP_NOT_FINISHED')
        mask=sum(int(m.mem_read(self.base+0x6a580+8*i,1)[0]!=0)<<i for i in range(8))
        return struct.pack('<12i',row[0],len(self.calls),mask,0,*(self.calls+[-1]*(8-len(self.calls))))


def identity():
    source=ROOT/'bot-cua-toi-1/source/MQL5';script=source/'Scripts/bot-cua-toi-1/Bot1StrategyLoopCheck.mq5'
    helpers=[Path(__file__),Path(hour.__file__),Path(hour.parent.__file__),ROOT/'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py']
    return dict(original_ex5_sha256=hour.parent.base.validation.original_hash(1),native_outer_sha256=hour.parent.CFG[1]['sha'],
                sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},
                helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate();return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN')
    rows,current=cases(),identity();home=ROOT/'bot-cua-toi-1';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encoded(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encoded(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BUILD_REQUIRED')
        mt=ROOT.parent/'.local/mt5-bot1-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        script='Scripts/bot-cua-toi-1/Bot1StrategyLoopCheck.mq5';require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED '+name)
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/'MQL5/Files/bot1-strategy-loop'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('strategy-loop-'+a.run+'.set');ini=mt/('strategy-loop-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1StrategyLoopCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as out:out.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        native=Native();raw=bytearray(header);calls=0
        for row in rows:raw+=native.run(row);calls+=len(native.calls)
        with (folder/'original-results.bin').open('xb') as out:out.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),strategy_calls=calls,result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),strategy_calls=calls)));return
    for name in ['original','mql5']:
        report=json.loads((folder/(name+'-run.json')).read_text());require(all(report[k]==v for k,v in current.items()) and report['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    original,actual=[(folder/(name+'-results.bin')).read_bytes() for name in ['original','mql5']]
    require(original[:12]==actual[:12]==header and len(original)==len(actual)==12+48*len(rows),'RESULT_LAYOUT');failed=[]
    for i,row in enumerate(rows):
        x,y=struct.unpack_from('<12i',original,12+i*48),struct.unpack_from('<12i',actual,12+i*48)
        if x!=y:failed.append(dict(case=i,input=row,original=x,actual=y))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:8],**SCOPE,
                limits=['Enable gates and invocation order only. All eight strategy bodies are replaced by recorders; actual full EA is not executed.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))


if __name__=='__main__':main()
