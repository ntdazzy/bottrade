"""Run the queue checker inside the same tester engine as the captured original.

Usage: kiem-hang-doi-trong-may-thu.py BOT NEW_RUN --queue-run RUN --build BUILD
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
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('new_run');parser.add_argument('--queue-run',required=True);parser.add_argument('--build',required=True);a=parser.parse_args()
    for name in [a.new_run,a.queue_run,a.build]:
        if not re.fullmatch('[a-z0-9-]{1,40}',name):raise ValueError('INVALID_RUN_OR_BUILD')
    home=ROOT/f'bot-cua-toi-{a.bot}';prior=home/'bang-chung/kiem-hang-doi'/a.queue_run;baseline=json.loads((prior/'baseline.json').read_text());rows=queue.read_cases(prior/'cases.bin')
    if sha(prior/'cases.bin')!=baseline['cases_sha256'] or queue.send.pending.fill.validation.original_hash(a.bot)!=baseline['original_ex5_sha256']:raise ValueError('INPUTS_CHANGED')
    receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    script_name=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PendingQueueCheck.mq5'
    names=[script_name]+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PendingQueue','TradeErrors','TradeSend','TradeMessages','PendingRequest','Filling']]
    if receipt['target']!=script_name or receipt['errors'] or receipt['warnings']:raise ValueError('SOURCE_BUILD_NOT_VERIFIED')
    for name in names:
        expected=receipt['sources_sha256'][name]
        if sha(home/'source/MQL5'/name)!=expected or sha(MT/'MQL5'/name)!=expected:raise ValueError('CURRENT_OR_PRIVATE_SOURCE_DIFFERS '+name)
    if sha(MT/'metatester64.exe')!='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb':raise ValueError('TESTER_ENGINE_CHANGED')
    out=ROOT/'doi-chung-mt5/hang-doi-20261024'/a.new_run;out.mkdir(parents=True,exist_ok=False)
    filename=f'b{a.bot}-queue-{a.new_run}.bin';destination=MT/'MQL5/Files'/filename
    if destination.exists():raise FileExistsError('TESTER_INPUT_ALREADY_EXISTS')
    shutil.copyfile(prior/'cases.bin',destination)
    source=(home/'source/MQL5'/script_name).read_text(encoding='utf-8-sig')
    for old,new in [('#property script_show_inputs\n',''),('int OnStart()','int RunQueueCheck()'),('FileOpen(folder+"cases.bin",','FileOpen("'+filename+'",')]:
        if source.count(old)!=1:raise ValueError('SOURCE_WRAPPER_REPLACEMENT_NOT_UNIQUE')
        source=source.replace(old,new)
    source='#property strict\n#property tester_file "'+filename+'"\n'+source
    source+='\nint OnInit()\n{\n   int result=RunQueueCheck();\n   Print("QUEUE_NATIVE_CHECK_EXIT:",result);\n   return result==0 ? INIT_SUCCEEDED : INIT_FAILED;\n}\nvoid OnTick() { ExpertRemove(); }\n'
    target=MT/f'MQL5/Experts/RecoveryQueue20261024/{a.new_run}';target.mkdir(parents=True,exist_ok=False)
    saved=out/'QueueEngineCheck.mq5';saved.write_text(source,encoding='utf-8',newline='');copied=target/saved.name;shutil.copyfile(saved,copied)
    log=out/'compile.log';command=f'"{MT/"metaeditor64.exe"}" /compile:"{copied}" /log:"{log}" /inc:"{MT/"MQL5"}"'
    result=subprocess.run(command,cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW,timeout=60)
    match=re.search(r'Result: (\d+) errors?, (\d+) warnings?',log.read_text(encoding='utf-16'))
    binary=copied.with_suffix('.ex5')
    build=dict(exit_code=result.returncode,errors=int(match[1]) if match else None,warnings=int(match[2]) if match else None,source_sha256=sha(saved),binary_sha256=sha(binary) if binary.exists() else None,
               component_build_receipt_sha256=sha(receipt_path),component_sources_sha256={name:receipt['sources_sha256'][name] for name in names},test_input_sha256=sha(destination),tester_sha256=sha(MT/'metatester64.exe'))
    save(out/'build.json',build)
    if not match or match[1]!='0' or match[2]!='0' or not binary.is_file():raise ValueError('QUEUE_TESTER_EA_BUILD_FAILED')
    shutil.copyfile(binary,out/binary.name)
    job=dict(id='q-engine-'+a.new_run,expert=f'RecoveryQueue20261024\\{a.new_run}\\QueueEngineCheck.ex5',symbol='XAUUSD_NOCOST_V2',period='M15',model=0,**{'from':'2026.09.29','to':'2026.09.30'},timeout=120,inputs={'CheckRun':a.queue_run})
    save(out/'jobs.json',[job]);runner=out/'runner';runner.mkdir();start=time.monotonic()
    with (out/'runner.stdout.txt').open('x',encoding='utf-8') as stdout,(out/'runner.stderr.txt').open('x',encoding='utf-8') as stderr:
        run=subprocess.run([sys.executable,'-I','-B','-X','utf8',str(ROOT/'cong-cu/chay-may-thu.py'),str(MT),str(out/'jobs.json'),str(runner),'--login','279786616','--server','Exness-MT5Trial8'],stdout=stdout,stderr=stderr,creationflags=subprocess.CREATE_NO_WINDOW,timeout=180)
    records=[json.loads(line) for line in (runner/'ket-qua-chay.jsonl').read_text().splitlines()];record=records[-1]
    if run.returncode or record['exit_code'] or not record['demo_confirmed'] or not record['login_confirmed'] or not record['report_created'] or record['expert_sha256']!=build['binary_sha256']:raise ValueError('QUEUE_TESTER_RUN_NOT_VERIFIED')
    journal=(runner/(job['id']+'.log')).read_text()
    if 'QUEUE_NATIVE_CHECK_EXIT:0' not in journal:raise ValueError('QUEUE_TESTER_SCRIPT_DID_NOT_PASS')
    files=MT/f'Tester/Agent-127.0.0.1-3000/MQL5/Files/bot{a.bot}-pending-queue'/a.queue_run
    for name in ['mql5-results.bin','last-error-calibration.bin']:
        source_file=files/name
        if not source_file.resolve().is_relative_to(MT.resolve()):raise ValueError('AGENT_FILE_OUTSIDE_PRIVATE_MT5')
        shutil.copyfile(source_file,out/name)
    original=queue.read_results(prior/'original-results.bin',len(rows));actual=queue.read_results(out/'mql5-results.bin',len(rows));failures=[]
    for i,(x,y) in enumerate(zip(original,actual)):
        if x!=y:
            pos=next((j for j,(a_,b_) in enumerate(zip(x,y)) if a_!=b_),min(len(x),len(y)));failures.append(dict(id=i,first_different_byte=pos,original=x[pos:pos+16].hex(),mql5=y[pos:pos+16].hex()))
    comparison=dict(bot=a.bot,cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:10],seconds=round(time.monotonic()-start,2),
                    source_comparison=str(prior.relative_to(ROOT)).replace('\\','/'),hashes={'cases.bin':sha(prior/'cases.bin'),'original-results.bin':sha(prior/'original-results.bin'),'tester-mql5-results.bin':sha(out/'mql5-results.bin'),'script-mql5-results.bin':sha(prior/'mql5-results.bin')},
                    whole_bot_complete=False,scope='Same queue source/check body inside identical tester engine, no orders. Test EA changes only event entry and input filename; supplied pending-builder and sleep/print boundaries remain. Exact queue records compared including NaN bits. Not a full EA/actual broker or queue+real-builder comparison.')
    save(out/'comparison.json',comparison);print(json.dumps(comparison));raise SystemExit(bool(failures))

if __name__=='__main__':main()
