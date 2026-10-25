"""Run the verified bot3 component in its private MT5 tester, without orders.

Usage: kiem-bang-dung-ao-may-thu-bot-3.py MATRIX_RUN NEW_RUN --build BUILD
Only the event entry, include path and input filename differ from the script.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
spec=importlib.util.spec_from_file_location('bot3_matrix',Path(__file__).with_name('kiem-bang-dung-ao-day-du-bot-3.py'))
matrix=importlib.util.module_from_spec(spec);spec.loader.exec_module(matrix)
MT=matrix.MT;sha=matrix.sha;save=matrix.save;require=matrix.require

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('matrix_run');parser.add_argument('new_run');parser.add_argument('--build',required=True)
    a=parser.parse_args()
    require(all(re.fullmatch('[a-z0-9-]{1,40}',v) for v in [a.matrix_run,a.new_run,a.build]),'INVALID_RUN')
    home=ROOT/'bot-cua-toi-3';prior=home/'bang-chung/kiem-bang-dung-ao'/a.matrix_run
    current=matrix.identity()
    for name in ['baseline.json','mql5-run.json','original-run.json']:
        matrix.check_identity(json.loads((prior/name).read_text()),current)
    comparison=json.loads((prior/'comparison.json').read_text())
    require(comparison['cases']==comparison['matched'] and comparison['failed']==0,'COMPONENT_NOT_PASSED')
    for name,digest in comparison['hashes'].items():require(sha(prior/name)==digest,'COMPONENT_EVIDENCE_CHANGED '+name)
    all_rows=matrix.cases();rows=[c for c in all_rows if not c['fatal']]
    require(matrix.encode(all_rows)==(prior/'cases.bin').read_bytes(),'CASES_CHANGED')
    receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json'
    receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    require(receipt['target']==matrix.SOURCES[2] and receipt['errors']==receipt['warnings']==0,'BUILD_NOT_CLEAN')
    for name,digest in current['sources_sha256'].items():
        require(receipt['sources_sha256'][name]==digest==sha(MT/'MQL5'/name),'SOURCE_CHANGED '+name)
    engine=sha(MT/'metatester64.exe')
    expected_engine=json.loads((matrix.ANALYSIS/'analysis.json').read_text())['engine_sha256']
    require(engine==expected_engine,'TESTER_ENGINE_DIFFERS_FROM_CAPTURE')
    out=home/'bang-chung/kiem-bang-dung-ao-may-thu'/a.new_run;out.mkdir(parents=True,exist_ok=False)
    shutil.copyfile(Path(__file__),out/'tester-check-tool.py')
    filename=f'b3-virtual-{a.new_run}.bin';destination=MT/'MQL5/Files'/filename
    require(not destination.exists(),'TESTER_INPUT_EXISTS');shutil.copyfile(prior/'cases.bin',destination)
    source=(home/'source/MQL5'/matrix.SOURCES[2]).read_text(encoding='utf-8-sig')
    replacements=[('#include "../../Include/bot-cua-toi-3/Bot3VirtualStops.mqh"','#include <bot-cua-toi-3/Bot3VirtualStops.mqh>'),
        ('#property script_show_inputs\n',''),('int OnStart()','int RunComponentCheck()'),
        ('FileOpen(folder+"cases.bin",','FileOpen("'+filename+'",')]
    for old,new in replacements:
        require(source.count(old)==1,'WRAPPER_REPLACEMENT_NOT_UNIQUE '+old);source=source.replace(old,new)
    marker='BOT3_VIRTUAL_CHECK_EXIT:'
    source='#property strict\n#property tester_file "'+filename+'"\n'+source
    source+='\nint CheckTicks=0;\nint OnInit()\n{\n   int result=RunComponentCheck();\n   Print("'+marker+'",result);\n   return result==0 ? INIT_SUCCEEDED : INIT_FAILED;\n}\nvoid OnTick() { CheckTicks++; }\ndouble OnTester()\n{\n   Print("BOT3_VIRTUAL_TEST_TICKS:",CheckTicks);\n   return (double)CheckTicks;\n}\n'
    target=MT/'MQL5/Experts/RecoveryBot3Virtual20261025'/a.new_run;target.mkdir(parents=True,exist_ok=False)
    saved=out/'Bot3VirtualStopsEngineCheck.mq5';saved.write_text(source,encoding='utf-8',newline='')
    copied=target/saved.name;shutil.copyfile(saved,copied);log=out/'compile.log'
    command=f'"{MT/"metaeditor64.exe"}" /compile:"{copied}" /log:"{log}" /inc:"{MT/"MQL5"}"'
    result=subprocess.run(command,cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW,timeout=60)
    match=re.search(r'Result: (\d+) errors?, (\d+) warnings?',log.read_text(encoding='utf-16'))
    binary=copied.with_suffix('.ex5')
    build=dict(exit_code=result.returncode,errors=int(match[1]) if match else None,warnings=int(match[2]) if match else None,
        source_sha256=sha(saved),binary_sha256=sha(binary) if binary.exists() else None,
        component_receipt_sha256=sha(receipt_path),sources_sha256=current['sources_sha256'],
        tester_sha256=engine,input_sha256=sha(destination),tool_sha256=sha(Path(__file__)),
        runner_sha256=sha(ROOT/'cong-cu/chay-may-thu.py'))
    save(out/'build.json',build)
    require(match is not None and match[1]==match[2]=='0' and binary.is_file(),'TESTER_BUILD_FAILED')
    shutil.copyfile(binary,out/binary.name)
    job=dict(id='b3-engine-'+a.new_run,expert=f'RecoveryBot3Virtual20261025\\{a.new_run}\\{binary.name}',
        symbol='XAUUSD_NOCOST_V2',period='M15',model=0,**{'from':'2026.09.29','to':'2026.09.30'},
        timeout=120,inputs={'CheckRun':a.new_run,'OnlyCase':-1})
    save(out/'jobs.json',[job]);runner=out/'runner';runner.mkdir()
    (MT/'reports').mkdir(exist_ok=True)
    with (out/'runner.stdout.txt').open('x',encoding='utf-8') as stdout,(out/'runner.stderr.txt').open('x',encoding='utf-8') as stderr:
        run=subprocess.run([sys.executable,'-I','-B','-X','utf8',str(ROOT/'cong-cu/chay-may-thu.py'),str(MT),str(out/'jobs.json'),str(runner),
            '--login','279786616','--server','Exness-MT5Trial8'],stdout=stdout,stderr=stderr,creationflags=subprocess.CREATE_NO_WINDOW,timeout=180)
    record=json.loads((runner/'ket-qua-chay.jsonl').read_text().splitlines()[-1])
    require(run.returncode==0 and record['exit_code']==0 and record['demo_confirmed'] and record['login_confirmed'] and
        record['report_created'] and record['expert_sha256']==build['binary_sha256'],'TESTER_RUN_NOT_VERIFIED')
    journal=(runner/(job['id']+'.log')).read_text()
    require(marker+'0' in journal,'TESTER_CHECK_DID_NOT_FINISH')
    candidates=list((MT/'Tester').glob('Agent-*/MQL5/Files/bot3-virtual-matrix/'+a.new_run))
    require(len(candidates)==1,'TESTER_OUTPUT_NOT_UNIQUE');files=candidates[0]
    for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']:shutil.copyfile(files/name,out/name)
    require(struct.unpack('<2i',(out/'script-status.bin').read_bytes())==(0,len(rows)),'TESTER_STATUS_DIFFERS')
    matrix.read_fixtures(out/'api-fixtures.bin',all_rows)
    require((out/'api-fixtures.bin').read_bytes()==(prior/'api-fixtures.bin').read_bytes(),'TESTER_API_RECORDS_DIFFER')
    expected=matrix.read_results(prior/'original-results.bin',all_rows);actual=matrix.read_results(out/'mql5-results.bin',all_rows)
    failed=[c['id'] for c in rows if expected[c['id']]!=actual[c['id']]]
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:10],
        original_ex5_sha256=current['original_ex5_sha256'],engine_sha256=engine,source_matrix=a.matrix_run,
        hashes={name:sha(out/name) for name in ['build.json','mql5-results.bin','api-fixtures.bin','script-status.bin']},
        whole_bot_complete=False,scope='Same five bot3 functions/check body in the original tester-engine version; all2500 table doubles,both warning tickets,guard,return bits,settings,selection and full physical ticket array match. API records equal to the script; query/time replies supplied and ArrayResize measured. No orders; no complete EA,lifecycle,actual account state or exhaustive allocation-failure proof.')
    save(out/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))

if __name__=='__main__':main()
