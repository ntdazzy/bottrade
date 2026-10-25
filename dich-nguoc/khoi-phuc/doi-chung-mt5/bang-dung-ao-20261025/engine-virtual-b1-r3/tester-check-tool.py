"""Run the queue checker inside the same tester engine as the captured original.

Usage: kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --queue-run RUN --build BUILD
       kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN --build BUILD --pipeline
       kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN --build BUILD --scan
       kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN --build BUILD --cancel
       kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN --build BUILD --selection
       kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN --build BUILD --close
       kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN --build BUILD --position-selection
       kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --component-run RUN --build BUILD --modify
       kiem-hang-doi-trong-may-thu.py 1 NEW_RUN --component-run RUN --build BUILD --virtual-stops
Creates a test EA from the checked script, changing only the file input path and
event entry. Queue source remains unchanged. All sends/sleeps remain test doubles.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('queue_check',Path(__file__).with_name('kiem-hang-doi-bot-1-3.py'))
queue=importlib.util.module_from_spec(spec);spec.loader.exec_module(queue)
MT=queue.MT;sha=queue.sha;save=queue.save

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('new_run');parser.add_argument('--queue-run','--component-run',dest='queue_run',required=True);parser.add_argument('--build',required=True)
    modes=parser.add_mutually_exclusive_group();modes.add_argument('--pipeline',action='store_true');modes.add_argument('--scan',action='store_true');modes.add_argument('--cancel',action='store_true');modes.add_argument('--selection',action='store_true');modes.add_argument('--close',action='store_true');modes.add_argument('--position-selection',action='store_true');modes.add_argument('--modify',action='store_true');modes.add_argument('--virtual-stops',action='store_true');a=parser.parse_args()
    if a.virtual_stops and a.bot!=1:parser.error('--virtual-stops currently requires bot1')
    for name in [a.new_run,a.queue_run,a.build]:
        if not re.fullmatch('[a-z0-9-]{1,40}',name):raise ValueError('INVALID_RUN_OR_BUILD')
    component=queue
    if a.pipeline:
        spec=importlib.util.spec_from_file_location('pipeline_check',Path(__file__).with_name('kiem-chuoi-dat-lenh-bot-1-3.py'));component=importlib.util.module_from_spec(spec);spec.loader.exec_module(component)
    if a.scan:
        spec=importlib.util.spec_from_file_location('scan_check',Path(__file__).with_name('kiem-quet-lenh-bot-1-3.py'));component=importlib.util.module_from_spec(spec);spec.loader.exec_module(component)
    if a.cancel:
        spec=importlib.util.spec_from_file_location('cancel_check',Path(__file__).with_name('kiem-huy-lenh-cho-bot-1-3.py'));component=importlib.util.module_from_spec(spec);spec.loader.exec_module(component)
    if a.selection:
        spec=importlib.util.spec_from_file_location('selection_check',Path(__file__).with_name('kiem-chon-lenh-huy-bot-1-3.py'));component=importlib.util.module_from_spec(spec);spec.loader.exec_module(component)
    if a.close:
        spec=importlib.util.spec_from_file_location('close_check',Path(__file__).with_name('kiem-dong-vi-the-bot-1-3.py'));component=importlib.util.module_from_spec(spec);spec.loader.exec_module(component)
    if a.position_selection:
        spec=importlib.util.spec_from_file_location('position_selection_check',Path(__file__).with_name('kiem-chon-vi-the-dong-bot-1-3.py'));component=importlib.util.module_from_spec(spec);spec.loader.exec_module(component)
    if a.modify:
        spec=importlib.util.spec_from_file_location('position_modify_check',Path(__file__).with_name('kiem-sua-vi-the-bot-1-3.py'));component=importlib.util.module_from_spec(spec);spec.loader.exec_module(component)
    if a.virtual_stops:
        spec=importlib.util.spec_from_file_location('virtual_stops_check',Path(__file__).with_name('kiem-bang-dung-ao-day-du-bot-1.py'));component=importlib.util.module_from_spec(spec);spec.loader.exec_module(component)
    label='Pipeline' if a.pipeline else 'Queue';part='kiem-chuoi-dat-lenh' if a.pipeline else 'kiem-hang-doi'
    if a.scan:label='OrderScan';part='kiem-quet-lenh'
    if a.cancel:label='OrderCancel';part='kiem-huy-lenh-cho'
    if a.selection:label='PendingSelection';part='kiem-chon-lenh-huy'
    if a.close:label='PositionClose';part='kiem-dong-vi-the'
    if a.position_selection:label='PositionSelection';part='kiem-chon-vi-the-dong'
    if a.modify:label='PositionModify';part='kiem-sua-vi-the'
    if a.virtual_stops:label='VirtualStops';part='kiem-bang-dung-ao'
    home=ROOT/f'bot-cua-toi-{a.bot}';prior=home/'bang-chung'/part/a.queue_run;baseline=json.loads((prior/'baseline.json').read_text())
    if a.virtual_stops:
        all_rows=component.cases();rows=[c for c in all_rows if not c['fatal']]
        if component.encode(all_rows)!=(prior/'cases.bin').read_bytes():raise ValueError('VIRTUAL_INPUTS_CHANGED')
        current=component.identity()
        for name in ['baseline.json','mql5-run.json','original-run.json']:component.check_identity(json.loads((prior/name).read_text()),current)
    else:rows=component.read_cases(prior/'cases.bin')
    if sha(prior/'cases.bin')!=baseline['cases_sha256'] or queue.send.pending.fill.validation.original_hash(a.bot)!=baseline['original_ex5_sha256']:raise ValueError('INPUTS_CHANGED')
    if a.modify:
        # The component records one identity on every stage; the tester run must reuse it unchanged.
        current=component.identity(a.bot,home)
        for record in ['baseline.json','mql5-run.json','original-run.json']:component.check_identity(json.loads((prior/record).read_text()),current,'COMPONENT')
    receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    script_name=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}Pending{label}Check.mq5'
    names=[script_name]+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PendingQueue','TradeErrors','TradeSend','TradeMessages','PendingRequest','Filling']]
    if a.scan:
        script_name=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}OrderScanCheck.mq5';names=[script_name,f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}OrderScan.mqh']
    if a.cancel:
        script_name=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}OrderCancelCheck.mq5';names=[script_name]+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['OrderCancel','TradeSend','TradeMessages','PendingRequest','Filling']]
    if a.selection:
        script_name=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PendingSelectionCheck.mq5';names=[script_name]+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PendingSelection','OrderCancel','TradeSend','TradeMessages','PendingRequest','Filling']]
    if a.close:
        script_name=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PositionCloseCheck.mq5';names=[script_name]+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PositionClose','TradeSend','TradeMessages','PendingRequest','Filling']]
    if a.position_selection:
        script_name=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PositionSelectionCheck.mq5';names=[script_name]+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PositionSelection','PositionClose','TradeSend','TradeMessages','PendingRequest','Filling']]
    if a.modify:
        script_name=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PositionModifyCheck.mq5';names=[script_name]+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PositionModify','TradeSend','TradeMessages','PendingRequest','Filling']]
    if a.virtual_stops:script_name=component.SOURCES[2];names=list(component.SOURCES)
    if a.pipeline or a.cancel or a.selection or a.close or a.position_selection or a.modify:names.append(f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PipelineApi.mqh')
    if receipt['target']!=script_name or receipt['errors']!=0 or receipt['warnings']!=0:raise ValueError('SOURCE_BUILD_NOT_VERIFIED')
    for name in names:
        expected=receipt['sources_sha256'][name]
        if sha(home/'source/MQL5'/name)!=expected or sha(MT/'MQL5'/name)!=expected:raise ValueError('CURRENT_OR_PRIVATE_SOURCE_DIFFERS '+name)
    if sha(MT/'metatester64.exe')!='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb':raise ValueError('TESTER_ENGINE_CHANGED')
    folder='chuoi-dat-lenh-20261024' if a.pipeline else 'hang-doi-20261024'
    if a.scan:folder='quet-lenh-20261024'
    if a.cancel:folder='huy-lenh-cho-20261024'
    if a.selection:folder='chon-lenh-huy-20261024'
    if a.close:folder='dong-vi-the-20261024'
    if a.position_selection:folder='chon-vi-the-dong-20261025'
    if a.modify:folder='sua-vi-the-20261025'
    if a.virtual_stops:folder='bang-dung-ao-20261025'
    out=ROOT/'doi-chung-mt5'/folder/a.new_run;out.mkdir(parents=True,exist_ok=False)
    if a.modify or a.virtual_stops:
        # Freeze the exact runner used for this run; later aggregates read this copy.
        with Path(__file__).open('rb') as reader,(out/'tester-check-tool.py').open('xb') as writer:shutil.copyfileobj(reader,writer)
    filename=f'b{a.bot}-{label.lower()}-{a.new_run}.bin';destination=MT/'MQL5/Files'/filename
    if destination.exists():raise FileExistsError('TESTER_INPUT_ALREADY_EXISTS')
    shutil.copyfile(prior/'cases.bin',destination)
    source=(home/'source/MQL5'/script_name).read_text(encoding='utf-8-sig')
    if a.virtual_stops:
        old='#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"'
        if source.count(old)!=1:raise ValueError('VIRTUAL_INCLUDE_NOT_UNIQUE')
        source=source.replace(old,'#include <bot-cua-toi-1/Bot1VirtualStops.mqh>')
    for old,new in [('#property script_show_inputs\n',''),('int OnStart()','int RunQueueCheck()'),('FileOpen(folder+"cases.bin",','FileOpen("'+filename+'",')]:
        if source.count(old)!=1:raise ValueError('SOURCE_WRAPPER_REPLACEMENT_NOT_UNIQUE')
        source=source.replace(old,new)
    source='#property strict\n#property tester_file "'+filename+'"\n'+source
    marker=label.upper()+'_NATIVE_CHECK_EXIT:'
    source+='\nint OnInit()\n{\n   int result=RunQueueCheck();\n   Print("'+marker+'",result);\n   return result==0 ? INIT_SUCCEEDED : INIT_FAILED;\n}\nvoid OnTick() { ExpertRemove(); }\n'
    target=MT/f'MQL5/Experts/Recovery{label}20261024/{a.new_run}';target.mkdir(parents=True,exist_ok=False)
    saved=out/(label+'EngineCheck.mq5');saved.write_text(source,encoding='utf-8',newline='');copied=target/saved.name;shutil.copyfile(saved,copied)
    if a.pipeline or a.cancel or a.selection or a.close or a.position_selection or a.modify:
        facade=home/f'source/MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PipelineApi.mqh'
        facade_text=facade.read_text(encoding='utf-8-sig');old=f'#include "../../Include/bot-cua-toi-{a.bot}/Bot{a.bot}TradeSend.mqh"'
        if facade_text.count(old)!=1:raise ValueError('PIPELINE_TESTER_INCLUDE_NOT_UNIQUE')
        facade_text=facade_text.replace(old,f'#include <bot-cua-toi-{a.bot}/Bot{a.bot}TradeSend.mqh>')
        (out/facade.name).write_text(facade_text,encoding='utf-8',newline='');shutil.copyfile(out/facade.name,target/facade.name)
    log=out/'compile.log';command=f'"{MT/"metaeditor64.exe"}" /compile:"{copied}" /log:"{log}" /inc:"{MT/"MQL5"}"'
    result=subprocess.run(command,cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW,timeout=60)
    match=re.search(r'Result: (\d+) errors?, (\d+) warnings?',log.read_text(encoding='utf-16'))
    binary=copied.with_suffix('.ex5')
    build=dict(exit_code=result.returncode,errors=int(match[1]) if match else None,warnings=int(match[2]) if match else None,source_sha256=sha(saved),binary_sha256=sha(binary) if binary.exists() else None,
               component_build_receipt_sha256=sha(receipt_path),component_sources_sha256={name:receipt['sources_sha256'][name] for name in names},test_input_sha256=sha(destination),tester_sha256=sha(MT/'metatester64.exe'),tool_sha256=sha(Path(__file__)))
    if a.pipeline or a.cancel or a.selection or a.close or a.position_selection or a.modify:build['adapted_api_include_sha256']=sha(out/facade.name)
    save(out/'build.json',build)
    if not match or match[1]!='0' or match[2]!='0' or not binary.is_file():raise ValueError('QUEUE_TESTER_EA_BUILD_FAILED')
    shutil.copyfile(binary,out/binary.name)
    output_run=a.new_run if a.selection or a.close or a.position_selection or a.modify or a.virtual_stops else a.queue_run
    if a.selection and (MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-pending-selection'/output_run).exists():raise FileExistsError('TESTER_OUTPUT_ALREADY_EXISTS')
    if a.close and (MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-position-close'/output_run).exists():raise FileExistsError('TESTER_OUTPUT_ALREADY_EXISTS')
    if a.position_selection and (MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-position-selection'/output_run).exists():raise FileExistsError('TESTER_OUTPUT_ALREADY_EXISTS')
    if a.modify and (MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-position-modify'/output_run).exists():raise FileExistsError('TESTER_OUTPUT_ALREADY_EXISTS')
    if a.virtual_stops and (MT/'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot1-virtual-matrix'/output_run).exists():raise FileExistsError('TESTER_OUTPUT_ALREADY_EXISTS')
    job=dict(id='q-engine-'+a.new_run,expert=f'Recovery{label}20261024\\{a.new_run}\\{label}EngineCheck.ex5',symbol='XAUUSD_NOCOST_V2',period='M15',model=0,**{'from':'2026.09.29','to':'2026.09.30'},timeout=120,inputs={'CheckRun':output_run})
    save(out/'jobs.json',[job]);runner=out/'runner';runner.mkdir();start=time.monotonic()
    with (out/'runner.stdout.txt').open('x',encoding='utf-8') as stdout,(out/'runner.stderr.txt').open('x',encoding='utf-8') as stderr:
        run=subprocess.run([sys.executable,'-I','-B','-X','utf8',str(ROOT/'cong-cu/chay-may-thu.py'),str(MT),str(out/'jobs.json'),str(runner),'--login','279786616','--server','Exness-MT5Trial8'],stdout=stdout,stderr=stderr,creationflags=subprocess.CREATE_NO_WINDOW,timeout=180)
    records=[json.loads(line) for line in (runner/'ket-qua-chay.jsonl').read_text().splitlines()];record=records[-1]
    if run.returncode or record['exit_code'] or not record['demo_confirmed'] or not record['login_confirmed'] or not record['report_created'] or record['expert_sha256']!=build['binary_sha256']:raise ValueError('QUEUE_TESTER_RUN_NOT_VERIFIED')
    journal=(runner/(job['id']+'.log')).read_text()
    if marker+'0' not in journal:raise ValueError('QUEUE_TESTER_SCRIPT_DID_NOT_PASS')
    files=MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-pending-{label.lower()}'/a.queue_run
    if a.scan:files=MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-order-scan'/a.queue_run
    if a.cancel:files=MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-order-cancel'/a.queue_run
    if a.selection:files=MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-pending-selection'/output_run
    if a.close:files=MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-position-close'/output_run
    if a.position_selection:files=MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-position-selection'/output_run
    if a.modify:files=MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-position-modify'/output_run
    if a.virtual_stops:files=MT/'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot1-virtual-matrix'/output_run
    output_names=['mql5-results.bin','api-fixtures.bin','script-status.bin'] if a.pipeline else ['mql5-results.bin','last-error-calibration.bin']
    if a.scan:output_names=['mql5-results.bin','script-status.bin']
    if a.cancel:output_names=['mql5-results.bin','api-fixtures.bin','script-status.bin']
    if a.selection:output_names=['mql5-results.bin','api-fixtures.bin','script-status.bin']
    if a.close:output_names=['mql5-results.bin','api-fixtures.bin','script-status.bin']
    if a.position_selection:output_names=['mql5-results.bin','api-fixtures.bin','script-status.bin']
    if a.modify:output_names=['mql5-results.bin','api-fixtures.bin','script-status.bin']
    if a.virtual_stops:output_names=['mql5-results.bin','api-fixtures.bin','script-status.bin']
    for name in output_names:
        source_file=files/name
        if not source_file.resolve().is_relative_to(MT.resolve()):raise ValueError('AGENT_FILE_OUTSIDE_PRIVATE_MT5')
        shutil.copyfile(source_file,out/name)
    if a.pipeline:
        import struct
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,len(rows)):raise ValueError('PIPELINE_TESTER_STATUS_DIFFERS')
        records,chart,digits=component.fixtures(out/'api-fixtures.bin',len(rows))
        for row in rows:component.validate_fixture_inputs(row,records[row['id']])
        if (out/'api-fixtures.bin').read_bytes()!=(prior/'api-fixtures.bin').read_bytes():raise ValueError('PIPELINE_TESTER_API_RECORDS_DIFFER_FROM_SCRIPT')
    if a.cancel or a.selection or a.close or a.position_selection or a.modify:
        import struct
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,len(rows)):raise ValueError('CANCEL_TESTER_STATUS_DIFFERS')
        records,chart,digits=component.fixtures(out/'api-fixtures.bin',len(rows))
        for row in rows:component.validate_inputs(row,records[row['id']])
        if (out/'api-fixtures.bin').read_bytes()!=(prior/'api-fixtures.bin').read_bytes():raise ValueError('CANCEL_TESTER_API_RECORDS_DIFFER_FROM_SCRIPT')
    if a.virtual_stops:
        import struct
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,len(rows)):raise ValueError('VIRTUAL_TESTER_STATUS_DIFFERS')
        component.read_fixtures(out/'api-fixtures.bin',all_rows)
        if (out/'api-fixtures.bin').read_bytes()!=(prior/'api-fixtures.bin').read_bytes():raise ValueError('VIRTUAL_TESTER_SERVICE_RECORDS_DIFFER_FROM_SCRIPT')
        original=list(component.read_results(prior/'original-results.bin',all_rows).values())
        actual=list(component.read_results(out/'mql5-results.bin',all_rows).values())
    else:
        original=component.read_results(prior/'original-results.bin',len(rows));actual=component.read_results(out/'mql5-results.bin',len(rows))
    failures=[]
    for i,(x,y) in enumerate(zip(original,actual)):
        if x!=y:
            pos=next((j for j,(a_,b_) in enumerate(zip(x,y)) if a_!=b_),min(len(x),len(y)));failures.append(dict(id=i,first_different_byte=pos,original=x[pos:pos+16].hex(),mql5=y[pos:pos+16].hex()))
    comparison=dict(bot=a.bot,cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:10],seconds=round(time.monotonic()-start,2),
                    source_comparison=str(prior.relative_to(ROOT)).replace('\\','/'),hashes={'cases.bin':sha(prior/'cases.bin'),'original-results.bin':sha(prior/'original-results.bin'),'tester-mql5-results.bin':sha(out/'mql5-results.bin'),'script-mql5-results.bin':sha(prior/'mql5-results.bin')},
                    whole_bot_complete=False,scope='Same queue source/check body inside identical tester engine, no orders. Test EA changes only event entry and input filename; supplied pending-builder and sleep/print boundaries remain. Exact queue records compared including NaN bits. Not a full EA/actual broker or queue+real-builder comparison.')
    if a.pipeline:
        comparison['scope']='Same full queue -> actual pending builder -> filling -> send -> messages check body inside identical tester engine. All500 queue doubles,35 trade fields,four full strings,actual builder bool and ordered API arguments/state compared. Terminal properties/send outcomes/errors supplied and input-bound; no actual broker/full EA/allocation-fault proof.'
        comparison['fixture_input_contract_checked_cases']=len(rows)
        comparison['hashes'].update({name:sha(out/name) for name in output_names if name!='mql5-results.bin'})
    if a.scan:
        import struct
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,len(rows)):raise ValueError('SCAN_TESTER_STATUS_DIFFERS')
        comparison['hashes']['script-status.bin']=sha(out/'script-status.bin')
        comparison['scope']='Same five scoped order-scan functions/check body in identical tester engine. Return,last ticket,all200 table doubles and ordered query/selection-model records compared. No orders. Queries and selection supplied; no full EA/actual account/CPU-allocation-fault proof.'
    if a.cancel:
        comparison['scope']='Same full cancel guard/request/send/messages check body inside identical tester engine.35fields,four strings,return and ordered typed query/send/format records compared. Terminal query/send results supplied and input-bound; formatting measured. No actual broker/full EA/allocation-failure proof.'
        comparison['input_contract_checked_cases']=len(rows);comparison['hashes'].update({name:sha(out/name) for name in output_names if name!='mql5-results.bin'})
    if a.selection:
        comparison['scope']='Same four pending selector functions through full cancel/send/messages and first-row table cleanup.35fields,four strings with null flags,all200 table doubles,last ticket,magic,symbol and ordered typed records compared. Query/send replies supplied; formatting measured. No actual account/broker/full EA/allocation-failure proof.'
        comparison['input_contract_checked_cases']=len(rows);comparison['hashes'].update({name:sha(out/name) for name in output_names if name!='mql5-results.bin'})
    if a.close:
        comparison['scope']='Same four position-close builder/guard functions through filling/send/messages.35 public fields,four strings/null flags,deviation,four shared doubles and public state at service boundaries compared. SDK replies supplied and input-bound; formatting measured. No actual account/broker/full EA/allocation-fault proof.'
        comparison['input_contract_checked_cases']=len(rows);comparison['hashes'].update({name:sha(out/name) for name in output_names if name!='mql5-results.bin'})
    if a.position_selection:
        comparison['scope']='Same four position scanners through actual close guard,close builder,filling,send and messages.35 public fields,four strings/null flags,deviation,four shared doubles,last ticket,signed32 identity seed,nullable symbol,selection model,helper count and state at service boundaries compared. Helper instrumentation resets reply counters only. SDK replies supplied/input-bound; formatting measured. No real account/broker/full EA/allocation-fault proof.'
        comparison['input_contract_checked_cases']=len(rows);comparison['hashes'].update({name:sha(out/name) for name in output_names if name!='mql5-results.bin'})
    if a.modify:
        comparison['scope']='Same position-modify-by-ticket helper through full send/messages check body inside identical tester engine. Return,35 public fields,four strings/null flags,stored magic/preferred/deviation,send options and public state at service boundaries compared. Stop/select/symbol/send replies supplied and input-bound; formatting measured. No callers,actual account/broker,full EA or allocation-fault proof.'
        comparison['input_contract_checked_cases']=len(rows);comparison['hashes'].update({name:sha(out/name) for name in output_names if name!='mql5-results.bin'})
    if a.virtual_stops:
        comparison['scope']='Same four virtual-stop functions/check body in identical tester engine. All1500 table doubles,guard,warning ticket,delay,unit,symbol,selection model,full physical ticket array and typed service records compared. Query/time replies supplied; real ArrayResize states observed and equal to script records. Fatal cases not run here; no actual account/LastError,lifecycle or full EA proof.'
        comparison['input_contract_checked_cases']=len(rows);comparison['hashes'].update({name:sha(out/name) for name in output_names if name!='mql5-results.bin'})
    save(out/'comparison.json',comparison);print(json.dumps(comparison));raise SystemExit(bool(failures))

if __name__=='__main__':main()
