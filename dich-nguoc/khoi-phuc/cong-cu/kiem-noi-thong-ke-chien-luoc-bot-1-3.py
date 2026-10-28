"""Check strategy setup/evaluation followed by the statistics call.

generate BOT | run BOT RUN --build BUILD. The evaluator and history function
are replaced by recorders; this does not execute the complete original EA.
"""
import argparse
import hashlib
import importlib.util
import json
import re
import subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('cycle_handoff',ROOT/'cong-cu/kiem-giu-trang-thai-danh-gia-bot-1-3.py')
handoff=importlib.util.module_from_spec(spec);spec.loader.exec_module(handoff)
require,pub=handoff.require,handoff.pub


def one(text,old,new):
    require(text.count(old)==1,'SOURCE_PATTERN_CHANGED '+old[:80])
    return text.replace(old,new,1)


def generate(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';folder=source/f'Scripts/bot-cua-toi-{bot}'
    script=(folder/f'Bot{bot}SharedHandoffCheck.mq5').read_text(encoding='utf-8-sig')
    script=one(script,f'Bot{bot}NfpExecution execution;','')
    script=one(script,'uint current=0;','')
    local=f'Bot{bot}PreparationInputs preparation_inputs;Bot{bot}PreparationState preparation;Bot{bot}ProfileRuntimeState profile_state;Bot{bot}ProfileAdjustments adjustments;Bot{bot}StrategyContextInputs context_inputs;Bot{bot}StrategyContextState context_state;'
    replacement=f'Bot{bot}ProfileRuntimeState profile_state;Bot{bot}ProfileAdjustments adjustments;Bot{bot}StrategyContextInputs context_inputs;'
    script=one(script,local,replacement)
    script=one(script,f'return BOT{bot}_LEVEL_NEW_BAR;',f'return i==1 ? BOT{bot}_LEVEL_STOP : BOT{bot}_LEVEL_NEW_BAR;')
    probe=f'''#include "../../Include/bot-cua-toi-{bot}/Bot{bot}StrategyHistory.mqh"
Bot{bot}PreparationInputs CycleInputs;Bot{bot}PreparationState CyclePreparation;
Bot{bot}StrategyContextState CycleContext;Bot{bot}NfpExecution CycleExecution;uint CycleCurrent=0;
int StrategyHistoryCalls=0,HistoryCurrent=-1,HistoryMagic=0;uchar HistoryTester=0;string HistorySymbol="";
double Bot{bot}ProbeHistory(const uchar &show_tester,const string &symbol,const int &magic,
                           const uint &current_index,int &closed[],Bot{bot}StrategyHistoryCache &cache)
{{
   StrategyHistoryCalls++;HistoryCurrent=(int)current_index;HistoryMagic=magic;
   HistoryTester=show_tester;HistorySymbol=symbol;closed[current_index]=2;
   CycleInputs.symbol="AFTER";CycleContext.magic=777;CycleCurrent=3;
   return 12.0;
}}
#define Bot{bot}StrategyClosedProfit Bot{bot}ProbeHistory
'''
    script=one(script,f'#define Bot{bot}EvaluateWithDisplay Bot{bot}ProbeEvaluate',probe+f'#define Bot{bot}EvaluateWithDisplay Bot{bot}ProbeEvaluate')
    script=one(script,f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}EvaluationBridge.mqh"',f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}StrategyCycle.mqh"')
    script=one(script,f'#undef Bot{bot}EvaluateWithDisplay',f'#undef Bot{bot}EvaluateWithDisplay\n#undef Bot{bot}StrategyClosedProfit')
    rows=8 if bot==1 else 9
    setup=f'''   int strategy_closed[{rows}];double strategy_totals[{rows}],strategy_average[{rows}];
   Bot{bot}StrategyHistoryCache strategy_history;
   ArrayInitialize(strategy_closed,0);ArrayInitialize(strategy_totals,-5.0);ArrayInitialize(strategy_average,-5.0);
   strategy_closed[1]=3;
'''
    script=one(script,'   if(CheckRun=="")return 1;\n   IntegrationInvocation=1;',setup+'   if(CheckRun=="")return 1;\n   IntegrationInvocation=1;')
    for index in [0,1]:
        marker=f'   Bot{bot}SetupAndEvaluate({index},';start=script.index(marker);end=script.index(';',start)+1;old=script[start:end]
        require(old.endswith(',display);'),'CALL_FORMAT_CHANGED')
        new=old.replace('SetupAndEvaluate(', 'SetupEvaluateAndUpdateStatistics(',1)[:-len(',display);')]
        new+=',display,'+('false' if index==0 else 'true')+',strategy_closed,strategy_history,strategy_totals,strategy_average);'
        if index==0:new+='\n   int calls_after_first=StrategyHistoryCalls;'
        else:new=new.replace(f'   Bot{bot}SetupEvaluateAndUpdateStatistics(',f'   Bot{bot}EntryLevelDecision second_result=Bot{bot}SetupEvaluateAndUpdateStatistics(',1)
        script=script[:start]+new+script[end:]
    script=one(script,'preparation.strategy_index!=7 ||','preparation.strategy_index!=3 ||')
    anchor='   string file="bot'+str(bot)+'-shared-handoff\\\\"+CheckRun+"\\\\result.bin";'
    checks='''   if(calls_after_first!=0 || StrategyHistoryCalls!=1) failures|=512;
   if(HistoryCurrent!=7 || HistoryMagic!=EXPECTED_MAGIC || HistoryTester!=0 || HistorySymbol!="XAUUSD") failures|=1024;
   if(strategy_closed[7]!=2 || strategy_closed[1]!=3 || strategy_totals[1]!=12.0 || strategy_average[1]!=4.0 || strategy_totals[0]!=-5.0) failures|=2048;
   if(second_result!=BOTN_LEVEL_STOP) failures|=4096;
   if(preparation.strategy_index!=3 || execution.symbol!="AFTER" || execution.strategy_magic!=777) failures|=8192;
'''.replace('EXPECTED_MAGIC','44' if bot==1 else '47').replace('BOTN_',f'BOT{bot}_')
    script=one(script,anchor,checks+anchor.replace('shared-handoff','strategy-cycle'))
    prefix,main=script.split('int OnStart()',1)
    for name,replacement in [('preparation_inputs','CycleInputs'),('preparation','CyclePreparation'),
                             ('context_state','CycleContext'),('execution','CycleExecution'),('current','CycleCurrent')]:
        main=re.sub(r'\b'+name+r'\b',replacement,main)
    script=prefix+'int OnStart()'+main
    target=folder/f'Bot{bot}StrategyCycleCheck.mq5';require(not target.exists(),'SOURCE_EXISTS')
    target.write_text(script,encoding='utf-8',newline='\n');print(target)


def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyCycleCheck.mq5'
    return dict(tool_sha256=sha(Path(__file__)),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)})


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','run']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run) and a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BAD_RUN')
    bot=a.bot;home=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';current=identity(bot)
    receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
    script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyCycleCheck.mq5'
    require(build['target']==script and build['errors']==build['warnings']==0 and build['floating_point_dividers_check_requested'],'BUILD_NOT_CLEAN')
    for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
    folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;folder.mkdir(parents=True,exist_ok=False)
    files=mt/f'MQL5/Files/bot{bot}-strategy-cycle'/a.run;files.mkdir(parents=True,exist_ok=False)
    preset=mt/'MQL5/Presets'/('strategy-cycle-'+a.run+'.set');ini=mt/('strategy-cycle-'+a.run+'.ini')
    preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
    ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}StrategyCycleCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=proc.wait(timeout=120)
    except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0 and (files/'result.bin').is_file(),'MT5_FAILED')
    import struct
    raw=(files/'result.bin').read_bytes();require(len(raw)==8,'RESULT_SIZE');fail,calls=struct.unpack('<2i',raw)
    require(fail==0 and calls==2,'STRATEGY_CYCLE_FAILED '+str((fail,calls)))
    (folder/'result.bin').write_bytes(raw)
    report=dict(**current,build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(folder/'result.bin'),
                evaluation_calls=2,history_calls=1,failed=fail,full_ea=False,original_ex5_changed=False,
                scope='Setup runs twice; second preparation returns early. Evaluator and history bodies are replaced with recorders. Full dispatcher and EA are not tested.')
    with (folder/'comparison.json').open('x',encoding='utf-8') as out:json.dump(report,out,indent=2)
    print(json.dumps(report))


if __name__=='__main__':main()
