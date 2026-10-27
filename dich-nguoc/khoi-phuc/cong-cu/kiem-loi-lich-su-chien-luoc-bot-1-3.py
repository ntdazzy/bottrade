"""Check the four fatal cache-array paths on real MT5 and unchanged native code.

generate BOT; run BOT RUN --build BUILD. Uses isolated MT5 only.
"""
import argparse,copy,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
s=importlib.util.spec_from_file_location('full_history',ROOT/'cong-cu/kiem-lich-su-chien-luoc-bot-1-3.py')
h=importlib.util.module_from_spec(s);s.loader.exec_module(h)
require=h.require;sha=h.sha;save=h.save
FAULTS={1:[0x102dcd000001f6,0x102dce000001f6,0x132de1000001f6,0x1a2de2000001f6],
        3:[0x103804000001f6,0x103805000001f6,0x133818000001f6,0x1a3819000001f6]}
LINES=['cache.positions[cache.count]=position;','cache.magics[cache.count]=owner;',
       'const ulong key=cache.positions[middle];','if(key==position) { owner=cache.magics[middle];break; }']

def case(bot,kind):
    c=copy.deepcopy(h.cases(bot)[0]);c['values'].update({'ShowTester':1,'Cache.total':-1 if kind<2 else 1,'Cache.count':2 if kind<2 else 1})
    c['keys']=[42] if kind&1 else [];c['owners']=[] if kind&1 else [9001]
    c['steps']=[h.step([h.deal(entry=0 if kind<2 else 1)])];c['errors']=1
    return c

def generate(bot):
    code=h.TEMPLATE[:h.TEMPLATE.index('int OnStart()')]
    code=code.replace('input string CheckRun="";','input string CheckRun="";\ninput int FaultKind=0;\nstring FaultFolder;')
    code=code.replace('int reply=ArrayResize(values,count,reserve);','int reply=-1;')
    end='   for(int i=0;i<ArraySize(Effects);i++)if(Effects[i].api==api && Effects[i].n==Counts[api])SetField(Effects[i].field,Effects[i].word,Effects[i].text);'
    require(code.count(end)==1,'END_MARKER_NOT_UNIQUE')
    code=code.replace(end,end+r'''
   FileFlush(TapeFile);int old=TapeFile;int state=FileOpen(FaultFolder+"last-state.bin",FILE_WRITE|FILE_BIN);
   if(state==INVALID_HANDLE)return;TapeFile=state;State();FileClose(state);TapeFile=old;
''')
    code+=r'''int OnStart()
{
   if(CheckRun=="" || FaultKind<0 || FaultKind>3)return 1;
   FaultFolder="bot@N@-history-fault\\"+CheckRun+"\\kind-"+IntegerToString(FaultKind)+"\\";
   ShowTester=1;Index=0;Magic=9001;HistorySymbol="XAUUSD";
   for(int i=0;i<@ROWS@;i++)ClosedTrades[i]=100+i;
   Cache.total=FaultKind<2 ? -1 : 1;Cache.count=FaultKind<2 ? 2 : 1;
   ArraySetAsSeries(Cache.positions,false);ArraySetAsSeries(Cache.magics,false);
   ArrayResize(Cache.positions,(FaultKind&1)!=0 ? 1 : 0);ArrayResize(Cache.magics,(FaultKind&1)!=0 ? 0 : 1);
   if(ArraySize(Cache.positions)>0)Cache.positions[0]=42;if(ArraySize(Cache.magics)>0)Cache.magics[0]=9001;
   ArrayResize(Effects,0);InfoReply=0;SelectReply=1;ArrayResize(Totals,2);Totals[0]=Totals[1]=1;
   ArrayResize(Deals,1);Deals[0].ticket=101;Deals[0].symbol="XAUUSD";
   ArrayResize(Deals[0].types,1);ArrayResize(Deals[0].entries,1);ArrayResize(Deals[0].positions,1);ArrayResize(Deals[0].magics,1);
   Deals[0].types[0]=0;Deals[0].entries[0]=FaultKind<2 ? 0 : 1;Deals[0].positions[0]=42;Deals[0].magics[0]=9001;
   Deals[0].profit=10.;Deals[0].commission=-1.;Deals[0].swap=-.5;ArrayInitialize(Deals[0].reads,0);
   ErrorMode=1;LogicalError=0;Calls=TotalCalls=0;Selected=-1;ArrayInitialize(Counts,0);
   TapeFile=FileOpen(FaultFolder+"events.bin",FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE)return 2;
   double value=Bot@N@StrategyClosedProfit(ShowTester,HistorySymbol,Magic,Index,ClosedTrades,Cache);
   FileClose(TapeFile);int unexpected=FileOpen(FaultFolder+"unexpected-return.bin",FILE_WRITE|FILE_BIN);
   if(unexpected!=INVALID_HANDLE) {FileWriteLong(unexpected,(long)Bits(value));FileClose(unexpected);}return 99;
}
'''
    code=code.replace('@N@',str(bot)).replace('@ROWS@',str(8 if bot==1 else 9))
    path=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyHistoryFaultCheck.mq5';path.write_text(code,encoding='utf-8',newline='\n')

class FaultNative(h.Native):
    def __init__(self,bot):
        super().__init__(bot);address=0x7ff683f20000+0x3959a0
        if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
        self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.fault,begin=address,end=address)
    def fault(self,m,address,size,user):
        self.fault_code=m.reg_read(self.x.UC_X86_REG_RDX);self.fault_state=self.state();m.emu_stop()
    def check(self,c,prefix,last,expected):
        self.fault_code=None;self.fault_state=None
        try:self.run(c,prefix)
        except ValueError as e:require(str(e)=='NATIVE_NO_RETURN' and self.fault_code==expected,'WRONG_NATIVE_FAILURE '+str((str(e),self.fault_code)))
        else:raise AssertionError('FAULT_NOT_TAKEN')
        require(self.tape.pos==len(prefix) and self.fault_state==last,'FAULT_PREFIX_OR_STATE_DIFFERS')
        return dict(native_fault=hex(self.fault_code),sdk_calls=self.calls,state_sha256=h.hashlib.sha256(last).hexdigest(),state_before_fault_matched=True)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','run']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run) and a.build,'BAD_RUN_OR_BUILD')
    home=ROOT/f'bot-cua-toi-{a.bot}';source=home/'source/MQL5';mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025'
    script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}StrategyHistoryFaultCheck.mq5';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
    hashes={p.relative_to(source).as_posix():sha(p) for p in h.pub.closure(source/script,source)};binary=mt/'MQL5'/Path(script).with_suffix('.ex5')
    def unchanged():
        for n,digest in hashes.items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==digest,'FAULT_SOURCE_CHANGED')
        require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'FAULT_BINARY_CHANGED')
    unchanged();folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;folder.mkdir(parents=True,exist_ok=False);results=[]
    for kind in range(4):
        files=mt/f'MQL5/Files/bot{a.bot}-history-fault'/a.run/f'kind-{kind}';files.mkdir(parents=True,exist_ok=False)
        target=folder/f'kind-{kind}';target.mkdir();preset=mt/'MQL5/Presets'/f'history-fault-{a.run}-{kind}.set';ini=mt/f'history-fault-{a.run}-{kind}.ini';preset.write_text(f'CheckRun={a.run}\nFaultKind={kind}\n',encoding='utf-16')
        logdir=mt/'MQL5/Logs';before={p:p.stat().st_size for p in logdir.glob('*.log')}
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}StrategyHistoryFaultCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_FAULT_TIMEOUT')
        unchanged();require(not (files/'unexpected-return.bin').exists(),'UNEXPECTED_NORMAL_RETURN')
        for name in ['events.bin','last-state.bin']:shutil.copyfile(files/name,target/name)
        lines=[]
        for path in logdir.glob('*.log'):lines+=path.read_bytes()[before.get(path,0):].decode('utf-16-le',errors='replace').splitlines()
        errors=[line for line in lines if f'Bot{a.bot}StrategyHistoryFaultCheck' in line and 'array out of range' in line and f'Bot{a.bot}StrategyHistory.mqh' in line]
        require(len(errors)==1,'EXPECTED_ONE_ARRAY_ERROR '+str(errors))
        header=source/f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}StrategyHistory.mqh';line=next(i for i,s in enumerate(header.read_text().splitlines(),1) if LINES[kind] in s)
        require(re.search(r'\('+str(line)+r',\d+\)',errors[0]),'WRONG_MQL5_FAULT_LINE '+errors[0])
        o=FaultNative(a.bot)
        try:result=o.check(case(a.bot,kind),(target/'events.bin').read_bytes(),(target/'last-state.bin').read_bytes(),FAULTS[a.bot][kind])
        finally:o.close()
        result.update(kind=kind,source_line=line,mql5_error=errors[0],mt5_exit_code=code,prefix_sha256=sha(target/'events.bin'),last_state_sha256=sha(target/'last-state.bin'));save(target/'comparison.json',result);results.append(result)
    result=dict(bot=a.bot,cases=4,matched=4,failed=0,results=results,sources_sha256=hashes,build=a.build,build_receipt_sha256=sha(receipt),tool_sha256=sha(Path(__file__)),shared_identity=h.identity(a.bot),full_ea=False,limits=['Compare exact calls and state immediately before four array-bound failures. Post-failure runtime state/messages are not claimed identical.'])
    save(folder/'fault-comparison.json',result);print(json.dumps(dict(bot=a.bot,cases=4,matched=4,failed=0)))

if __name__=='__main__':main()
