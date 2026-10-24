"""Build/load a known-source library and match missing direct MT5 call addresses.

python -I -B -X utf8 doi-chung-loi-goi-bo-sung.py NEW_RUN
Only Anchor is called. Other exported wrappers are inspected as code, so no
global-variable/object deletion, message box or calendar request is performed.
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
import time

ROOT=Path(__file__).resolve().parents[1]
LOCAL=ROOT.parent/'.local/claude-recovery-20261023'
MT=LOCAL/'mt5'
AREA=ROOT/'doi-chung-mt5/api-bo-sung-20261023'
sys.path.insert(0,str(LOCAL/'python'))


def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    value=importlib.util.module_from_spec(spec)
    spec.loader.exec_module(value)
    return value


def analyze(out,engine,capture):
    old=module('probe_analyzer',ROOT/'cong-cu-cu/analyze-api-probes.py')
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64
    code=next(r for r in capture['regions'] if r['kind']=='executable' and r['bytes']>=8192)
    data_region=next(r for r in capture['regions'] if r['kind']=='mutable_program_data')
    capdir=out/'captures/library'
    code_bytes=(capdir/code['file']).read_bytes()
    data=(capdir/data_region['file']).read_bytes()
    data_rva=data_region['base']-code['base']
    runs=[]
    for offset in range(0,len(data)-11,4):
        begin,end,unwind=struct.unpack_from('<III',data,offset)
        if not (begin<end<=code['bytes'] and data_rva<=unwind<data_rva+len(data)
                and data[unwind-data_rva]&7==1):
            continue
        row={'offset':offset,'begin':begin,'end':end,'unwind':unwind}
        if runs and offset==runs[-1][-1]['offset']+12 and begin>=runs[-1][-1]['end']:
            runs[-1].append(row)
        else:
            runs.append([row])
    table=max(runs,key=len)
    if len(table)<20:raise ValueError('FUNCTION_TABLE_TOO_SHORT')
    references={}
    for match in re.finditer(rb'(?:[\x20-\x7e]\x00){4,}',data):
        text=match.group().decode('utf-16-le')
        if not text.startswith('EX5_API_PROBE:'):continue
        pointer=struct.pack('<Q',data_region['base']+match.start())
        pos=0
        while (pos:=data.find(pointer,pos))>=0:
            if pos>=4 and struct.unpack_from('<I',data,pos-4)[0]==0:
                references[data_region['base']+pos-4]=text.split(':',1)[1]
            pos+=1
    binary=(MT/'metatester64.exe').read_bytes()
    pe=struct.unpack_from('<I',binary,0x3c)[0]
    if binary[:2]!=b'MZ' or binary[pe:pe+4]!=b'PE\0\0':raise ValueError('INVALID_ENGINE_PE')
    image_size=struct.unpack_from('<I',binary,pe+24+56)[0]
    md=Cs(CS_ARCH_X86,CS_MODE_64);md.detail=True
    base=int(engine['engine_base'],16)
    functions=[]
    for row in table:
        calls,constants=old.trace_calls(md,code_bytes,code['base'],row['begin'],row['end'],base,image_size)
        functions.append({'rva':hex(row['begin']),'end_rva':hex(row['end']),
                          'markers':sorted({references[c] for c in constants if c in references}),'calls':calls})
    expected=set(re.findall(r'EX5_API_PROBE:([A-Za-z0-9_]+)',(AREA/'source/RecoveryApiLibrary.mq5').read_text()))
    single=[f for f in functions if len(f['markers'])==1]
    if {f['markers'][0] for f in single}!=expected:raise ValueError('PROBE_MARKER_COVERAGE_INCOMPLETE')
    bot_results=[]
    for bot in [1,3]:
        inventory_path=ROOT/f'ban-do-bot-1-3/luot-20261023-r3/bot-{bot}.json'
        inventory=json.loads(inventory_path.read_text())
        run='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/run/'metadata/import.json').read_text())
        if meta['engine']['engine_sha256']!=engine['engine_sha256']:raise ValueError('ENGINE_CALIBRATION_MISMATCH')
        original_base=int(meta['engine']['engine_base'],16)
        matches=[]
        for address in inventory['unlabelled_native_addresses']:
            rva=int(address,16)-original_base
            sites=[{'source_marker':f['markers'][0],'function_rva':f['rva'],'call':c}
                   for f in single for c in f['calls'] if int(c['target_rva'],16)==rva]
            matches.append({'original_address':address,'engine_rva':hex(rva),'known_source_sites':sites,
                            'mapped':bool(sites)})
        bot_results.append({'bot':bot,'inventory_sha256':settings.sha(inventory_path),'addresses':matches,
                            'mapped':sum(m['mapped'] for m in matches),'remaining':sum(not m['mapped'] for m in matches)})
    return {'engine_sha256':engine['engine_sha256'],'engine_base':engine['engine_base'],
            'code_sha256':code['sha256'],'data_sha256':data_region['sha256'],
            'functions':functions,'runtime_function_table':table,'source_markers_verified':sorted(expected),
            'bots':bot_results,'scope':'Known-source call-site calibration only. StringToLower identifies an internal helper used by that operation. No original EA branches or full business behavior are verified.'}


def main():
    global AREA
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('run');ap.add_argument('--area',type=Path);a=ap.parse_args()
    if a.area:
        area=a.area.resolve()
        if not area.is_relative_to((ROOT/'doi-chung-mt5').resolve()):raise ValueError('AREA_OUTSIDE_PROBE_DIRECTORY')
        if not (area/'source/RecoveryApiLibrary.mq5').is_file() or not (area/'source/RecoveryApiDriver.mq5').is_file():raise ValueError('PROBE_SOURCES_MISSING')
        AREA=area
    if not re.fullmatch('[a-z0-9-]{1,40}',a.run):raise ValueError('INVALID_RUN')
    if settings.processes():raise RuntimeError('PRIVATE_MT5_IS_BUSY')
    if settings.sha(MT/'metatester64.exe')!=settings.ENGINE_SHA:raise ValueError('ENGINE_CHANGED')
    out=AREA/a.run;out.mkdir(parents=True,exist_ok=False)
    target=MT/'MQL5/Experts/RecoveryApi20261023'/a.run
    target.mkdir(parents=True,exist_ok=False)
    for source in (AREA/'source').glob('*.mqh'):
        shutil.copyfile(source,target/source.name);shutil.copyfile(source,out/source.name)
    build=[]
    startup=subprocess.STARTUPINFO();startup.dwFlags|=subprocess.STARTF_USESHOWWINDOW;startup.wShowWindow=0
    for name in ['RecoveryApiLibrary','RecoveryApiDriver']:
        source=AREA/'source'/(name+'.mq5');copied=target/source.name;shutil.copyfile(source,copied)
        shutil.copyfile(source,out/source.name)
        log=out/(name+'-compile.log')
        command=f'"{MT/"metaeditor64.exe"}" /compile:"{copied}" /log:"{log}" /inc:"{MT/"MQL5"}"'
        result=subprocess.run(command,cwd=MT,startupinfo=startup,creationflags=subprocess.CREATE_NO_WINDOW,timeout=90)
        text=log.read_text(encoding='utf-16')
        match=re.search(r'Result: (\d+) errors?, (\d+) warnings?',text)
        binary=copied.with_suffix('.ex5')
        receipt={'name':name,'exit_code':result.returncode,'source_sha256':settings.sha(source),
                 'errors':int(match[1]) if match else None,'warnings':int(match[2]) if match else None,
                 'binary_sha256':settings.sha(binary) if binary.exists() else None}
        build.append(receipt)
        (out/'build.json').write_text(json.dumps({'metaeditor_sha256':settings.sha(MT/'metaeditor64.exe'),'builds':build},indent=2),encoding='utf-8')
        if not match or match[1]!='0' or match[2]!='0' or not binary.exists():raise RuntimeError('PROBE_COMPILE_FAILED '+name)
        shutil.copyfile(binary,out/binary.name)
    expert=f'RecoveryApi20261023\\{a.run}\\RecoveryApiDriver.ex5'
    job={'id':'api-'+a.run,'expert':expert,'symbol':'XAUUSD_NOCOST_V2','period':'M15','model':0,
         'from':'2026.09.29','to':'2026.09.30','timeout':120,'inputs':{}}
    (out/'jobs.json').write_text(json.dumps([job],indent=2),encoding='utf-8')
    runner=out/'runner';runner.mkdir()
    with (out/'runner.stdout.txt').open('x',encoding='utf-8') as stdout,(out/'runner.stderr.txt').open('x',encoding='utf-8') as stderr:
        proc=subprocess.Popen([sys.executable,'-I','-B','-X','utf8',str(ROOT/'cong-cu/chay-may-thu.py'),str(MT),str(out/'jobs.json'),str(runner),'--login','279786616','--server','Exness-MT5Trial8'],stdout=stdout,stderr=stderr,creationflags=subprocess.CREATE_NO_WINDOW)
        observed=[]
        try:
            deadline=time.monotonic()+45;engine=None
            while proc.poll() is None and time.monotonic()<deadline:
                observed=settings.processes()
                engine=next((p for p in observed if Path(p['path']).name=='metatester64.exe'),None)
                if engine:break
                time.sleep(0.1)
            if not engine:raise RuntimeError('PRIVATE_TESTER_NOT_OBSERVED')
            identity={'pid':engine['id'],'process':engine['path'],'engine_base':hex(engine['base']),
                      'engine_sha256':settings.ENGINE_SHA,'observed_processes':observed}
            (out/'engine-observed.json').write_text(json.dumps(identity,indent=2),encoding='utf-8')
            inspector=module('probe_capture',ROOT/'cong-cu-cu/inspect-ex5-running-code.py')
            inspector.ROOT=out;inspector.EXPECTED=MT/'metatester64.exe'
            saved_argv=sys.argv
            try:
                sys.argv=[str(Path(__file__)),'--pid',str(engine['id']),'--out',str(out/'captures/library'),'--min-code-bytes','8192','--wait-seconds','25','--include-readonly','--include-program-data']
                inspector.main()
            finally:sys.argv=saved_argv
            proc.wait(timeout=120)
        finally:
            settings.stop_owned(observed)
            if proc.poll() is None:proc.wait(timeout=30)
    run=[json.loads(line) for line in (runner/'ket-qua-chay.jsonl').read_text().splitlines()][-1]
    if proc.returncode or run['exit_code'] or not run['login_confirmed'] or not run['demo_confirmed'] or not run['report_created']:
        raise RuntimeError('PROBE_TESTER_RUN_NOT_VERIFIED')
    if run['expert_sha256']!=build[-1]['binary_sha256']:raise ValueError('DRIVER_BINARY_MISMATCH')
    journal=(runner/(job['id']+'.log')).read_text()
    if 'RECOVERY_API_DRIVER_BEGIN:42731' not in journal or 'RECOVERY_API_DRIVER_CAPTURE_WINDOW_END' not in journal:
        raise ValueError('DRIVER_EXECUTION_NOT_CONFIRMED')
    if set(re.findall(r'EX5_API_PROBE:([A-Za-z0-9_]+)',journal))!={'Anchor'}:
        raise ValueError('UNEXPECTED_PROBE_FUNCTION_EXECUTED')
    capture=json.loads((out/'captures/library/capture.json').read_text())
    if capture['pid']!=identity['pid'] or capture['errors']:raise ValueError('UNVERIFIED_PROBE_CAPTURE')
    for region in capture['regions']:
        if settings.sha(out/'captures/library'/region['file'])!=region['sha256']:raise ValueError('PROBE_CAPTURE_HASH_MISMATCH')
    result=analyze(out,identity,capture)
    result.update(tool_sha256=settings.sha(Path(__file__)),capture_tool_sha256=settings.sha(ROOT/'cong-cu-cu/inspect-ex5-running-code.py'),
                  source_sha256={p.name:settings.sha(p) for p in (AREA/'source').iterdir() if p.suffix in ['.mq5','.mqh']},
                  runner_verified=True,only_anchor_executed=True)
    (out/'calibration.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf-8')
    print(json.dumps({'source_markers':len(result['source_markers_verified']),'bots':[{k:b[k] for k in ['bot','mapped','remaining']} for b in result['bots']],'runner_verified':True,'only_anchor_executed':True}))


settings=module('settings_capture',Path(__file__).with_name('phan-tich-cai-dat-bot-1-3.py'))
if __name__=='__main__':main()
