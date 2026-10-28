"""Compare the nine native bot-3 gates and caller flags after preparation.

generate | prepare|mql5 --build BUILD|original|compare RUN.
The source executes actual profile/context/preparation; its evaluator is a
recorder. Native profile/context/preparation bodies are skipped at declared boundaries.
Native gate instructions and real prepare/evaluate call sites run continuously.
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
MAGIC=0x4c503331
spec=importlib.util.spec_from_file_location('bot3_loop_hour',ROOT/'cong-cu/kiem-gio-chien-luoc-bot-1-3.py')
hour=importlib.util.module_from_spec(spec);spec.loader.exec_module(hour)
require,sha,save,pub=hour.require,hour.sha,hour.save,hour.pub
START,END=0x1a68e,0x1f501
PROFILE=[0x1a80a,0x1b93b,0x1c1d1,0x1b087,0x1d2f6,0x1ca75,0x1e3e8,0x1ec8b,0x1db6a]
PREP_CALL=[0x1affc,0x1c143,0x1c9e7,0x1b8ad,0x1dadc,0x1d268,0x1ebfd,0x1f492,0x1e35a]
EVAL_CALL=[0x1b010,0x1c15a,0x1c9fe,0x1b8c4,0x1daf3,0x1d27f,0x1ec14,0x1f4a9,0x1e371]
RESIDENT=[1,5,8,2,9,12,13,14,15]
SCOPE=dict(full_ea=False,native_enable_gates_contiguous=True,native_prepare_and_evaluate_calls_executed=True,
           native_profile_context_preparation_replaced=True,source_profile_context_preparation_executed=True,
           native_and_source_presence_scan_executed=True,
           evaluator_replaced_by_recorder=True,shared_state_outside_flags_compared=False,
           terminal_replies_and_mutations_supplied=True,original_ex5_changed=False)


def cases():
    out=[]
    def add(flags,retained,stage=0,n=0,kind=0,index=0,value=0,early=0):
        out.append((len(out),flags,retained,stage,n,kind,index,value,early))
    for mask in range(512):
        add(mask,0);add(mask,511)
    for mask in range(512):add(0,mask)
    for flags,retained in [(511,0),(0,511),(0,1),(1,0),(341,170)]:
        for stage in [1,2]:
            for n in [1,2,5,9]:
                for kind,size in [(1,9),(2,16)]:
                    for index in range(size):
                        for value in [0,1,2,255]:add(flags,retained,stage,n,kind,index,value)
    for early in range(1,10):
        for flags,retained in [(511,0),(0,511),(341,170)]:
            add(flags,retained,1,early,1,early-1,0,early)
    return out


def encoded(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<9i',*row) for row in rows)


def one(text,old,new):
    require(text.count(old)==1,'SOURCE_PATTERN_CHANGED '+old[:80]);return text.replace(old,new,1)


def generate():
    source=ROOT/'bot-cua-toi-3/source/MQL5';folder=source/'Scripts/bot-cua-toi-3'
    template=(folder/'Bot3SharedHandoffCheck.mq5').read_text(encoding='utf-8-sig')
    marker='#include "../../Include/bot-cua-toi-3/Bot3EvaluationWithDisplay.mqh"'
    prefix=template[:template.index(marker)]
    prefix=one(prefix,'int IntegrationInvocation=0;','void LoopAtPreparation();')
    prefix=one(prefix,'Event(2);if(IntegrationInvocation==2) return 0;','Event(2);LoopAtPreparation();if(LoopPreparationFailed()) return 0;')
    prefix=one(prefix,'void LoopAtPreparation();','void LoopAtPreparation();\nbool LoopPreparationFailed();')
    header=(source/'Include/bot-cua-toi-3/Bot3EvaluationWithDisplay.mqh').read_text(encoding='utf-8-sig')
    a=header.index('Bot3EntryLevelDecision Bot3EvaluateWithDisplay(');z=header.index('\n{',a)
    signature=header[a:z].replace('Bot3EvaluateWithDisplay','LoopEvaluationProbe',1)
    probe=f'''
{marker}
#include "../../Include/bot-cua-toi-3/Bot3StrategyHistory.mqh"
uchar LoopFlags[9],LoopRetained[16];
int LoopCalls,LoopPreparations,LoopHistoryCalls,LoopIndexes[9],LoopCallerFlags[9];
int LoopPresenceCounts[6],LoopPositionCount,LoopOrderCount,LoopSelectedPosition,LoopSelectedOrder;
long LoopPositionMagic[9],LoopOrderMagic[9];
int LoopPositions(){{LoopPresenceCounts[0]++;return LoopPositionCount;}}
ulong LoopPositionTicket(const int index){{LoopPresenceCounts[1]++;LoopSelectedPosition=index;return (ulong)(index+1);}}
long LoopPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{{LoopPresenceCounts[2]++;if((int)property!=12)Fault=53;return LoopPositionMagic[LoopSelectedPosition];}}
int LoopOrders(){{LoopPresenceCounts[3]++;return LoopOrderCount;}}
ulong LoopOrderTicket(const int index){{LoopPresenceCounts[4]++;LoopSelectedOrder=index;return (ulong)(index+1);}}
long LoopOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{{LoopPresenceCounts[5]++;if((int)property!=15)Fault=54;return LoopOrderMagic[LoopSelectedOrder];}}
#define PositionsTotal LoopPositions
#define PositionGetTicket LoopPositionTicket
#define PositionGetInteger LoopPositionInteger
#define OrdersTotal LoopOrders
#define OrderGetTicket LoopOrderTicket
#define OrderGetInteger LoopOrderInteger
#include "../../Include/bot-cua-toi-3/Bot3StrategyPresence.mqh"
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef OrdersTotal
#undef OrderGetTicket
#undef OrderGetInteger
int LoopStage,LoopEffectN,LoopEffectKind,LoopEffectIndex,LoopEffectValue,LoopEarly;
void LoopEffect(const int stage,const int n)
{{
   if(stage!=LoopStage || n!=LoopEffectN)return;
   if(LoopEffectKind==1)LoopFlags[LoopEffectIndex]=(uchar)LoopEffectValue;
   else if(LoopEffectKind==2)LoopRetained[LoopEffectIndex]=(uchar)LoopEffectValue;
}}
void LoopAtPreparation(){{LoopPreparations++;LoopEffect(1,LoopPreparations);}}
bool LoopPreparationFailed(){{return LoopEarly!=0 && LoopPreparations==LoopEarly;}}
{signature}
{{
   if(LoopCalls>=9){{Fault=51;return BOT3_LEVEL_STOP;}}
   LoopIndexes[LoopCalls]=(int)caller_index;LoopCallerFlags[LoopCalls]=(int)prefix.caller_flag;
   LoopCalls++;LoopEffect(2,LoopCalls);return BOT3_LEVEL_STOP;
}}
double LoopHistoryProbe(const uchar &show_tester,const string &symbol,const int &magic,
                         const uint &current_index,int &closed[],Bot3StrategyHistoryCache &cache)
{{LoopHistoryCalls++;return 0.0;}}
#define Bot3EvaluateWithDisplay LoopEvaluationProbe
#define Bot3StrategyClosedProfit LoopHistoryProbe
#include "../../Include/bot-cua-toi-3/Bot3StrategyDispatcher.mqh"
#undef Bot3EvaluateWithDisplay
#undef Bot3StrategyClosedProfit
'''
    api=(folder/'Bot3EvaluationBridgeAPICompile.mq5').read_text(encoding='utf-8-sig')
    a=api.index('void OnStart()');z=api.index('   Bot3SetupAndEvaluate(',a)
    declarations=api[api.index('{',a)+1:z]
    declarations=one(declarations,'\n   uchar strategy_enabled=1;','')
    declarations=one(declarations,'preparation_inputs.symbol=_Symbol;context_inputs.base_magic=0;',
                     'preparation_inputs.symbol="XAUUSD";context_inputs.base_magic=42;')
    call=api[z:api.index(';',z)+1]
    call=one(call,'Bot3SetupAndEvaluate(0,strategy_enabled,','Bot3RunSelectedStrategies(LoopFlags,LoopRetained,')
    require(call.endswith(',display);'),'CALL_TAIL_CHANGED')
    call=call[:-len(',display);')]+',display,false,loop_closed,loop_cache,loop_total,loop_average);'
    body='''
int OnStart()
{
   if(CheckRun=="")return 1;
   string folder="bot3-strategy-loop\\\\"+CheckRun+"\\\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x4c503331 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
DECLARATIONS
   int loop_closed[9];double loop_total[9],loop_average[9];Bot3StrategyHistoryCache loop_cache;
   const int resident_slots[]={1,5,8,2,9,12,13,14,15};const uchar byte_values[]={1,2,128,255};
   Sample=2000;CheckPoint=0.01;CheckDigits=2;Bid=100;Ask=101;Now=1792713600;Stops=30;Freeze=20;SampleCount=2;FXCurrency="USD";
   preparation_inputs.adjust_lots=1;preparation_inputs.min_change=0.1;
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file),flags_mask=FileReadInteger(file),retained_mask=FileReadInteger(file);
      LoopStage=FileReadInteger(file);LoopEffectN=FileReadInteger(file);LoopEffectKind=FileReadInteger(file);
      LoopEffectIndex=FileReadInteger(file);LoopEffectValue=FileReadInteger(file);LoopEarly=FileReadInteger(file);
      ArrayInitialize(LoopRetained,255);
      for(int i=0;i<9;i++)
      {
         uchar value=byte_values[(id+i)%4];LoopFlags[i]=(flags_mask&(1<<i))!=0 ? value : 0;
         LoopRetained[resident_slots[i]]=(retained_mask&(1<<i))!=0 ? value : 0;
      }
      LoopPositionCount=0;LoopOrderCount=0;
      for(int i=0;i<9;i++)
      {
         if((retained_mask&(1<<i))==0)continue;
         long magic=42+resident_slots[i];
         if(i%2==0)LoopPositionMagic[LoopPositionCount++]=magic;
         else LoopOrderMagic[LoopOrderCount++]=magic;
      }
      LoopCalls=0;LoopPreparations=0;LoopHistoryCalls=0;Fault=0;ArrayInitialize(LoopPresenceCounts,0);
      ArrayInitialize(LoopIndexes,-1);ArrayInitialize(LoopCallerFlags,-1);
CALL
      if(LoopPresenceCounts[0]!=1 || LoopPresenceCounts[3]!=1)Fault=52;
      FileWriteInteger(output,id);FileWriteInteger(output,LoopCalls);FileWriteInteger(output,LoopPreparations);
      FileWriteInteger(output,LoopHistoryCalls);FileWriteInteger(output,Fault);
      for(int i=0;i<6;i++)FileWriteInteger(output,LoopPresenceCounts[i]);
      for(int i=0;i<9;i++)FileWriteInteger(output,(int)LoopFlags[i]);
      for(int i=0;i<16;i++)FileWriteInteger(output,(int)LoopRetained[i]);
      for(int i=0;i<9;i++)FileWriteInteger(output,LoopIndexes[i]);
      for(int i=0;i<9;i++)FileWriteInteger(output,LoopCallerFlags[i]);
   }
   if(FileTell(file)!=FileSize(file))return 5;
   FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''.replace('DECLARATIONS',declarations).replace('CALL',call)
    path=folder/'Bot3StrategyLoopCheck.mq5';require(not path.exists(),'SOURCE_EXISTS')
    path.write_text(prefix+probe+body,encoding='utf-8',newline='\n');print(path)


class Native(hour.parent.Original):
    def __init__(self):
        super().__init__(3)
        self.sdk={0x7ff683f20000+offset:api for api,offset in enumerate([0x7d7da0,0x7d7df0,0x7d7fc0,0x7d81a0,0x7d81f0,0x7d8310])}
        for addr in self.sdk:
            existed=addr in self.apis
            if not any(lo<=addr<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(addr&~4095,4096)
            self.m.mem_write(addr,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.profile,begin=self.base+START,end=self.base+END)
        for off,hook in [(0xe0c0,self.prepare),(0x20ef0,self.evaluate)]:
            self.m.hook_add(self.uc.UC_HOOK_CODE,hook,begin=self.base+off,end=self.base+off)

    def call(self,m,address,size,user):
        require(address in self.sdk,'UNEXPECTED_SDK_CALL');api=self.sdk[address];x=self.x
        require(m.reg_read(x.UC_X86_REG_RCX)==self.gate['ctx'],'BAD_PRESENCE_CONTEXT')
        self.presence_counts[api]+=1
        if api in [0,3]:reply=len(self.positions if api==0 else self.orders)
        elif api in [1,4]:
            index=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;self.selected[api]=index;items=self.positions if api==1 else self.orders
            require(index<len(items),'BAD_TICKET_INDEX');reply=index+1
        else:
            require(m.reg_read(x.UC_X86_REG_RDX)==(12 if api==2 else 15),'BAD_MAGIC_PROPERTY')
            items=self.positions if api==2 else self.orders;index=self.selected[1 if api==2 else 4];reply=items[index]
        m.reg_write(x.UC_X86_REG_RAX,reply)

    def profile(self,m,address,size,user):
        off=address-self.base
        if off not in PROFILE:return
        self.selected_index=PROFILE.index(off);x=self.x
        m.reg_write(x.UC_X86_REG_RCX,self.selected_index);m.reg_write(x.UC_X86_REG_RAX,self.base+0xe0c0)
        m.reg_write(x.UC_X86_REG_RIP,self.base+PREP_CALL[self.selected_index])

    def effect(self,stage,n):
        if self.row[3]!=stage or self.row[4]!=n:return
        kind,index,value=self.row[5:8]
        require(kind in [1,2] and 0<=index<(9 if kind==1 else 16),'BAD_EFFECT')
        self.m.mem_write(self.base+(0x6d220 if kind==1 else 0x1d6cf8)+index,bytes([value]))

    def returned(self,expected_return):
        m,x=self.m,self.x;sp=m.reg_read(x.UC_X86_REG_RSP);target=struct.unpack('<Q',m.mem_read(sp,8))[0]
        require(target==self.base+expected_return,'BAD_NATIVE_RETURN')
        m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,target)

    def prepare(self,m,address,size,user):
        require(m.reg_read(self.x.UC_X86_REG_RCX)==self.selected_index,'BAD_PREPARATION_INDEX')
        self.preparations+=1;self.effect(1,self.preparations);self.returned(PREP_CALL[self.selected_index]+2)

    def evaluate(self,m,address,size,user):
        x=self.x;index=m.reg_read(x.UC_X86_REG_RCX)&0xffffffff;flag=m.reg_read(x.UC_X86_REG_RDX)&255
        require(index==self.selected_index and len(self.calls)<9,'BAD_EVALUATION_INDEX')
        self.calls.append(index);self.flags.append(flag);self.effect(2,len(self.calls));self.returned(EVAL_CALL[index]+2)

    def run(self,row):
        self.row,self.calls,self.flags,self.preparations=row,[],[],0;m,x=self.m,self.x
        self.presence_counts=[0]*6;self.selected={1:-1,4:-1}
        self.positions=[42+RESIDENT[i] for i in range(9) if row[2]&(1<<i) and i%2==0]
        self.orders=[42+RESIDENT[i] for i in range(9) if row[2]&(1<<i) and i%2!=0]
        m.mem_write(self.base+0x1d6ff0,struct.pack('<i',42))
        m.mem_write(self.base+0x1d6cf8,bytes([255])*16)
        values=[1,2,128,255]
        for i in range(9):
            value=values[(row[0]+i)%4]
            m.mem_write(self.base+0x6d220+i,bytes([value if row[1]&(1<<i) else 0]))
            m.mem_write(self.base+0x1d6cf8+RESIDENT[i],bytes([value if row[2]&(1<<i) else 0]))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        sp=0x5001fe00;m.mem_write(sp,bytes(0x100));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_EFLAGS,0x202)
        m.emu_start(self.base+START,self.base+END,timeout=1000000,count=100000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+END,'LOOP_NOT_FINISHED')
        enabled=list(m.mem_read(self.base+0x6d220,9));retained=list(m.mem_read(self.base+0x1d6cf8,16))
        output=[row[0],len(self.calls),self.preparations,0,0]+self.presence_counts+enabled+retained+self.calls+[-1]*(9-len(self.calls))+self.flags+[-1]*(9-len(self.flags))
        require(len(output)==54,'OUTPUT_WIDTH');return struct.pack('<54i',*output)


def identity():
    source=ROOT/'bot-cua-toi-3/source/MQL5';script=source/'Scripts/bot-cua-toi-3/Bot3StrategyLoopCheck.mq5'
    helpers=[Path(__file__),Path(hour.__file__),Path(hour.parent.__file__),ROOT/'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py']
    return dict(original_ex5_sha256=hour.parent.base.validation.original_hash(3),native_outer_sha256=hour.parent.CFG[3]['sha'],
                sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},
                helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate();return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN')
    rows,current=cases(),identity();home=ROOT/'bot-cua-toi-3';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encoded(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encoded(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BUILD_REQUIRED')
        mt=ROOT.parent/'.local/mt5-bot3-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script='Scripts/bot-cua-toi-3/Bot3StrategyLoopCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0 and build['floating_point_dividers_check_requested'],'BUILD_NOT_CLEAN')
        def unchanged():
            for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED '+name)
            binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        unchanged();files=mt/'MQL5/Files/bot3-strategy-loop'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('strategy-loop-'+a.run+'.set');ini=mt/('strategy-loop-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3StrategyLoopCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED');unchanged()
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as out:out.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        native=Native();raw=bytearray(header);calls=0
        for row in rows:raw+=native.run(row);calls+=len(native.calls)
        with (folder/'original-results.bin').open('xb') as out:out.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),evaluation_calls=calls,result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),evaluation_calls=calls)));return
    for name in ['original','mql5']:
        report=json.loads((folder/(name+'-run.json')).read_text());require(all(report[k]==v for k,v in current.items()) and report['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    original,actual=[(folder/(name+'-results.bin')).read_bytes() for name in ['original','mql5']]
    require(original[:12]==actual[:12]==header and len(original)==len(actual)==12+216*len(rows),'RESULT_LAYOUT');failed=[]
    for i,row in enumerate(rows):
        x,y=struct.unpack_from('<54i',original,12+i*216),struct.unpack_from('<54i',actual,12+i*216)
        if x!=y:failed.append(dict(case=i,input=row,original=x,actual=y))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:8],**SCOPE,
                limits=['Presence scan, nine gates and caller flags. Native profile/context/preparation skipped; source profile/context/preparation run with supplied terminal responses. Evaluator is a recorder; full EA and common-state equivalence are excluded.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))


if __name__=='__main__':main()
