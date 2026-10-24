"""Prove the new post-close cases reject two intentionally incorrect scanners.

Usage: kiem-doc-lai-sau-dong.py NEW_RUN
Creates private copies only. Production headers and all original files stay intact.
All trading/query calls remain mocked; terminal trading and DLLs are disabled.
"""
import argparse
import copy
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('selection',Path(__file__).with_name('kiem-chon-vi-the-dong-bot-1-3.py'))
selection=importlib.util.module_from_spec(spec);spec.loader.exec_module(selection)
sha=selection.sha;save=selection.save;MT=selection.MT

def replace_once(text,old,new):
    if text.count(old)!=1:raise ValueError('SOURCE_SHAPE_CHANGED '+old[:60])
    return text.replace(old,new)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('new_run');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,18}',a.new_run):raise ValueError('INVALID_RUN')
    out=ROOT/'danh-gia-doc-lap/chon-vi-the-dong-20261025'/a.new_run;out.mkdir(exist_ok=False)
    cases=copy.deepcopy(selection.cases()[-2:])
    for i,row in enumerate(cases):row['id']=i;row['send']['id']=i
    checks=[]
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';frozen=home/'bang-chung/kiem-chon-vi-the-dong/position-selection-20261025-r3/tested-sources'
        source=frozen/f'Bot{bot}PositionSelectionCheck.mq5';header=frozen/f'Bot{bot}PositionSelection.mqh';count=8 if bot==1 else 15
        original=header.read_text()
        cached=replace_once(original,'   string position_symbol;','   string position_symbol;\n   string cached_symbol;bool captured=false;')
        cached=replace_once(cached,'      if(position_symbol!=symbol) continue;','      if(!captured) { cached_symbol=symbol;captured=true; }\n      if(position_symbol!=cached_symbol) continue;')
        call=f'      Bot{bot}TryClosePosition(state,options,deviation,reference_a,reference_b,threshold_a,threshold_b,last_ticket);'
        recalc=replace_once(original,call,call+f'\n      for(int i=0;i<{count};i++) {{ uint low=(uint)magic_base+(uint)(i+1);accepted[i]=(long)(int)low; }}')
        for mutation,bad in [('cache-symbol',cached),('refresh-identities',recalc)]:
            tag=f'{a.new_run}-b{bot}-{mutation}';run=out/f'b{bot}-{mutation}';run.mkdir()
            target=MT/f'MQL5/Scripts/RecoveryPositionMutation/{tag}'
            if not target.resolve().is_relative_to(MT.resolve()):raise ValueError('TARGET_OUTSIDE_PRIVATE_MT5')
            target.mkdir(parents=True,exist_ok=False)
            bad=replace_once(bad,f'#include "Bot{bot}PositionClose.mqh"',f'#include <bot-cua-toi-{bot}/Bot{bot}PositionClose.mqh>')
            (run/'IncorrectPositionSelection.mqh').write_text(bad,encoding='utf-8',newline='');shutil.copyfile(run/'IncorrectPositionSelection.mqh',target/'IncorrectPositionSelection.mqh')
            text=replace_once(source.read_text(),f'#include <bot-cua-toi-{bot}/Bot{bot}PositionSelection.mqh>','#include "IncorrectPositionSelection.mqh"')
            facade=frozen/f'Bot{bot}PipelineApi.mqh';adapted=replace_once(facade.read_text(),f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}TradeSend.mqh"',f'#include <bot-cua-toi-{bot}/Bot{bot}TradeSend.mqh>')
            (run/facade.name).write_text(adapted,encoding='utf-8',newline='');shutil.copyfile(run/facade.name,target/facade.name)
            saved=run/'PositionMutationCheck.mq5';saved.write_text(text,encoding='utf-8',newline='');copied=target/saved.name;shutil.copyfile(saved,copied);log=run/'compile.log'
            compile_result=subprocess.run(f'"{MT/"metaeditor64.exe"}" /compile:"{copied}" /log:"{log}" /inc:"{MT/"MQL5"}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW,timeout=60)
            match=re.search(r'Result: (\d+) errors?, (\d+) warnings?',log.read_text(encoding='utf-16'));binary=copied.with_suffix('.ex5')
            if not match or match[1]!='0' or match[2]!='0' or not binary.exists():raise ValueError('MUTANT_BUILD_FAILED')
            files=MT/f'MQL5/Files/bot{bot}-position-selection'/tag;files.mkdir(parents=True,exist_ok=False);(files/'cases.bin').write_bytes(selection.encode(cases))
            preset=MT/'MQL5/Presets'/f'{tag}.set';preset.write_text(f'CheckRun={tag}\n',encoding='utf-16');ini=MT/f'{tag}.ini'
            ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=RecoveryPositionMutation\\{tag}\\PositionMutationCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
            terminal_before=sha(MT/'terminal64.exe');started=time.monotonic();process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
            try:exit_code=process.wait(timeout=120)
            except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MUTANT_MT5_TIMEOUT')
            if exit_code or sha(MT/'terminal64.exe')!=terminal_before:raise ValueError('MUTANT_RUN_NOT_VERIFIED')
            for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']:shutil.copyfile(files/name,run/name)
            if struct.unpack('<2i',(run/'script-status.bin').read_bytes())!=(0,2):raise ValueError('MUTANT_SCRIPT_INCOMPLETE')
            records,chart,digits=selection.fixtures(run/'api-fixtures.bin',2);selection.read_results(run/'mql5-results.bin',2);original_runner=selection.Original(bot,records,chart,digits);rejected=[]
            for row in cases:
                selection.validate_inputs(row,records[row['id']])
                try:original_runner.run_selection(row)
                except ValueError as error:
                    if not any(marker in str(error) for marker in ['API_ORDER_DIFFERS','EXTRA_NATIVE_API','STATE_DIFFERS','HELPER_ENTRY_DIFFERS','HELPER_RETURN_STATE_DIFFERS']):raise
                    rejected.append(dict(id=row['id'],error=str(error),native_rva=hex(original_runner.m.reg_read(original_runner.x.UC_X86_REG_RIP)-original_runner.base)))
                else:raise ValueError('INCORRECT_SCANNER_WAS_ACCEPTED '+mutation)
            result=dict(bot=bot,mutation=mutation,cases=2,rejected=rejected,compile_exit_code=compile_result.returncode,errors=0,warnings=0,terminal_exit_code=exit_code,terminal_sha256=terminal_before,source_sha256=sha(saved),incorrect_header_sha256=sha(run/'IncorrectPositionSelection.mqh'),binary_sha256=sha(binary),original_header_sha256=sha(header),cases_sha256=sha(files/'cases.bin'),fixture_sha256=sha(run/'api-fixtures.bin'),seconds=round(time.monotonic()-started,2))
            save(run/'result.json',result);checks.append(result)
    save(out/'summary.json',dict(checks=checks,tool_sha256=sha(Path(__file__)),comparison_tool_sha256=sha(Path(selection.__file__)),whole_bot_complete=False,scope='Two intentionally incorrect private headers are rejected by original native comparison on both new post-close cases per bot. Production source untouched.'))
    print(json.dumps(dict(mutants=4,rejected_cases=8,production_changed=False)))

if __name__=='__main__':main()
