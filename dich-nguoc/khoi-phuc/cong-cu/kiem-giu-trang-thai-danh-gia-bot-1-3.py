"""Check setup/evaluator state handoff when the second preparation returns early.

generate BOT | run BOT RUN --build BUILD. The evaluator is replaced by a
recorder; no orders, original EA or real account are used. Native value
mapping and evaluator bodies require their separate comparisons.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,path):
    s=importlib.util.spec_from_file_location(name,ROOT/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
pub=module('handoff_pub','cong-cu/kiem-ban-git-quan-ly.py');require=pub.require
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def one(text,old,new):require(text.count(old)==1,'SOURCE_PATTERN_CHANGED '+old[:80]);return text.replace(old,new,1)
def generate(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';folder=source/f'Scripts/bot-cua-toi-{bot}'
    template=(folder/f'Bot{bot}StrategySetupCheck.mq5').read_text(encoding='utf-8-sig');prefix=template[:template.index('double ExtraDouble(')]
    prefix=one(prefix,'int FakeCopy(const int handle,','int IntegrationInvocation=0;\nint FakeCopy(const int handle,')
    prefix=one(prefix,'Event(2);if(handle!=17','Event(2);if(IntegrationInvocation==2) return 0;if(handle!=17')
    header=(source/f'Include/bot-cua-toi-{bot}/Bot{bot}EvaluationWithDisplay.mqh').read_text(encoding='utf-8-sig');begin=header.index(f'Bot{bot}EntryLevelDecision Bot{bot}EvaluateWithDisplay(');end=header.index('\n{',begin)
    signature=header[begin:end].replace(f'Bot{bot}EvaluateWithDisplay',f'Bot{bot}ProbeEvaluate')
    probe=f'''
#include "../../Include/bot-cua-toi-{bot}/Bot{bot}EvaluationWithDisplay.mqh"
int ProbeCalls=0;double SeenUnit[2],SeenSpread[2],SeenBid[2];uint SeenIndex[2],SeenCaller[2];int SeenHour[2],SeenMode[2],SeenStep[2],SeenPending[2],SeenMaximum[2],SeenBaseMagic[2];ulong SeenDeviation[2];long SeenExpiration[2];
{signature}
{{
   int i=ProbeCalls++;if(i>=2)return BOT{bot}_LEVEL_STOP;
   SeenUnit[i]=unit;SeenSpread[i]=spread;SeenBid[i]=execution.tick.bid;SeenIndex[i]=current_index;SeenCaller[i]=caller_index;SeenHour[i]=cached_calendar.hour;
   SeenMode[i]=(int)volume_state.mode;SeenStep[i]=volume_state.balance_step;SeenPending[i]=pending_enabled;SeenMaximum[i]=maximum_pending;SeenExpiration[i]=(long)restore.expiration_base;SeenBaseMagic[i]=execution.magic_base;SeenDeviation[i]=execution.deviation;
   if(i==0) {{ execution.tick.bid=321.0;execution.tick.ask=322.0;execution.deviation=654321;spread=9.5;current_index=7;cached_calendar.hour=19;restore.expiration_base=(datetime)123456;volume_state.mode=9999;volume_state.balance_step=44; }}
   return BOT{bot}_LEVEL_NEW_BAR;
}}
#define Bot{bot}EvaluateWithDisplay Bot{bot}ProbeEvaluate
#include "../../Include/bot-cua-toi-{bot}/Bot{bot}EvaluationBridge.mqh"
#undef Bot{bot}EvaluateWithDisplay
'''
    api=(folder/f'Bot{bot}EvaluationBridgeAPICompile.mq5').read_text(encoding='utf-8-sig');api=one(api,f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}EvaluationBridge.mqh"','')
    api=api.replace('#property strict','',1).replace('void OnStart()','int OnStart()',1)
    api=one(api,'preparation_inputs.symbol=_Symbol;context_inputs.base_magic=0;',
       'Sample=2000;CheckPoint=0.01;CheckDigits=2;Bid=100;Ask=101;Now=1792713600;Stops=30;Freeze=20;SampleCount=2;FXCurrency="USD";\n   preparation_inputs.symbol="XAUUSD";preparation_inputs.variable_distances=1;preparation_inputs.adjust_lots=1;preparation_inputs.min_change=0.1;context_inputs.base_magic=42;execution.deviation=123456;')
    marker=f'   Bot{bot}SetupAndEvaluate(0,';idx=api.index(marker);end_call=api.index(';',idx)+1;call=api[idx:end_call]
    second=call.replace('Evaluate(0,','Evaluate(1,',1)
    check='''
   if(CheckRun=="")return 1;
   IntegrationInvocation=1;
CALL_FIRST
   IntegrationInvocation=2;
CALL_SECOND
   uint failures=0;
   if(ProbeCalls!=2) failures|=1;
   if(SeenUnit[0]!=0.01 || SeenUnit[1]!=0.01) failures|=2;
   if(SeenSpread[0]!=1.0 || SeenSpread[1]!=9.5) failures|=4;
   if(SeenBid[0]!=100.0 || SeenBid[1]!=321.0) failures|=8;
   if(SeenIndex[0]!=0 || SeenIndex[1]!=7 || SeenCaller[0]!=0 || SeenCaller[1]!=1 || SeenHour[0]!=0 || SeenHour[1]!=19) failures|=16;
   if(SeenExpiration[1]!=123456 || SeenMode[1]!=9999 || SeenStep[1]!=44) failures|=32;
   if(SeenPending[0]==-12345 || SeenMaximum[0]==-12345) failures|=64;
   if(preparation.tick.bid!=321.0 || preparation.spread!=9.5 || preparation.strategy_index!=7 || preparation.calendar.hour!=19 || preparation.expiration!=123456) failures|=128;
   if(SeenBaseMagic[0]!=42 || SeenBaseMagic[1]!=42 || SeenDeviation[0]!=123456 || SeenDeviation[1]!=654321) failures|=256;
   string file="botN-shared-handoff\\\\"+CheckRun+"\\\\result.bin";int out=FileOpen(file,FILE_WRITE|FILE_BIN);if(out==INVALID_HANDLE)return 2;
   FileWriteInteger(out,(int)failures);FileWriteInteger(out,ProbeCalls);FileClose(out);return 0;
'''.replace('CALL_FIRST',call).replace('CALL_SECOND',second).replace('botN',f'bot{bot}')
    api=api[:idx]+check+'}\n';target=folder/f'Bot{bot}SharedHandoffCheck.mq5';require(not target.exists(),'SOURCE_EXISTS');target.write_text(prefix+probe+api,encoding='utf-8',newline='\n');print(target)
def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}SharedHandoffCheck.mq5'
    return dict(tool_sha256=sha(Path(__file__)),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)})
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','run']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run) and a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BAD_RUN');home=ROOT/f'bot-cua-toi-{a.bot}';mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';current=identity(a.bot);receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}SharedHandoffCheck.mq5'
    require(b['target']==script and b['errors']==b['warnings']==0 and b['floating_point_dividers_check_requested'],'BUILD_NOT_CLEAN')
    for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==b['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;folder.mkdir(parents=True,exist_ok=False);files=mt/f'MQL5/Files/bot{a.bot}-shared-handoff'/a.run;files.mkdir(parents=True,exist_ok=False)
    preset=mt/'MQL5/Presets'/('handoff-'+a.run+'.set');ini=mt/('handoff-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}SharedHandoffCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=proc.wait(timeout=120)
    except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0 and (files/'result.bin').is_file(),'MT5_FAILED');raw=(files/'result.bin').read_bytes();require(len(raw)==8,'RESULT_SIZE');fail,calls=struct.unpack('<2i',raw);require(fail==0 and calls==2,'SHARED_HANDOFF_FAILED '+str((fail,calls)))
    (folder/'result.bin').write_bytes(raw);report=dict(**current,build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(folder/'result.bin'),calls=calls,failed=fail,original_ex5_changed=False,whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
       scope='Actual setup source and state handoff run twice, with second CopyBuffer returning zero. Evaluator body and terminal services are supplied; this checks handoff only, not full evaluator or EA.')
    with (folder/'comparison.json').open('x',encoding='utf-8') as f:json.dump(report,f,indent=2)
    print(json.dumps(report))
if __name__=='__main__':main()
