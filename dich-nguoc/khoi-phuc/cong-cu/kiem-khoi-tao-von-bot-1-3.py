"""Compare MQL5 initialization with the retained, bounded original-code analysis.

python -I -B -X utf8 kiem-khoi-tao-von-bot-1-3.py prepare|mql5|compare BOT NEW_RUN [--build BUILD]
Account, clock and global storage are supplied in the MQL5 script. String/number
conversions use actual MQL5. No live trades or real global variables are changed.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('native_init',Path(__file__).with_name('phan-tich-khoi-tao-von-bot-1-3.py'))
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
settings=native.module('settings','phan-tich-cai-dat-bot-1-3.py')
MAGIC=0x494e4931


def trace_result(events):
    value=0xcbf29ce484222325
    codes={'account_double':1,'account_integer':2,'set':3,'sleep':4,'get':5,'check':6,'time_current':7}
    for event in events:
        kind=event[0]
        first=native.entry.text_hash(event[1]) if kind in ['get','set','check'] else event[1]
        last=int(event[2]) if len(event)==3 else 0
        for word in [codes[kind],first,last]:
            for byte in struct.pack('<Q',word&native.entry.MASK):value=((value^byte)*0x100000001b3)&native.entry.MASK
    return len(events),value


def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','mql5','compare'])
    ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-khoi-tao-von'/a.run
    ref=ROOT/f'bot-cua-toi-{a.bot}/phan-tich/khoi-tao-von/init-state-20261023-r1'
    summary=json.loads((ref/'summary.json').read_text())
    if not summary['passed'] or summary['tool_sha256']!=settings.sha(Path(native.__file__)) or summary['results_sha256']!=settings.sha(ref/'results.jsonl'):
        raise ValueError('NATIVE_REFERENCE_NOT_VERIFIED')
    rows=[json.loads(line) for line in (ref/'results.jsonl').read_text().splitlines()]
    raw=struct.pack('<3i',MAGIC,1,len(rows))
    for row in rows:
        c=row['inputs']
        raw+=struct.pack('<iqii3dididq',row['case'],c['login'],c['reset'],c['use_equity'],
            c['manual'],c['balance'],c['equity'],int(c['stored_peak'] is not None),
            c['stored_peak'] if c['stored_peak'] is not None else 0.,c['time_exists'],c['stored_time'],c['now'])
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);(out/'cases.bin').write_bytes(raw)
        (out/'original-reference.json').write_text(json.dumps({'path':ref.relative_to(ROOT).as_posix(),
            'summary_sha256':settings.sha(ref/'summary.json'),'results_sha256':settings.sha(ref/'results.jsonl'),
            'cases':len(rows),'purpose':'Same 616 inputs and original segment results; no expected output from reconstructed MQL5.'},indent=2),encoding='utf-8')
        print(json.dumps({'bot':a.bot,'cases':len(rows)}));return
    if (out/'cases.bin').read_bytes()!=raw:raise ValueError('INPUT_BYTES_CHANGED')
    target=out/'mql5-results.bin'
    if a.mode=='mql5':
        if target.exists():raise FileExistsError(target)
        if settings.processes():raise RuntimeError('PRIVATE_MT5_IS_BUSY')
        if not a.build or not re.fullmatch('[a-z0-9-]+',a.build):raise ValueError('EXPLICIT_BUILD_REQUIRED')
        build_path=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/bien-dich'/a.build/'bien-nhan.json'
        receipt=json.loads(build_path.read_text(encoding='utf-8-sig'))
        script=settings.MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}AccountInitializationCheck.ex5'
        if receipt['errors'] or receipt['warnings'] or receipt['binary_sha256']!=settings.sha(script):raise ValueError('BUILD_NOT_VERIFIED')
        for path,sha in receipt['sources_sha256'].items():
            if settings.sha(ROOT/f'bot-cua-toi-{a.bot}/source/MQL5'/path)!=sha:raise ValueError('SOURCE_CHANGED_AFTER_BUILD')
        files=settings.MT/f'MQL5/Files/bot{a.bot}-initial-state'/a.run;files.mkdir(parents=True,exist_ok=False)
        shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=settings.MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set'
        if preset.exists():raise FileExistsError(preset)
        preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=settings.MT/f'b{a.bot}-{a.run}-initial-state.ini'
        if ini.exists():raise FileExistsError(ini)
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}AccountInitializationCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{settings.MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=settings.MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0 or not (files/'mql5-results.bin').is_file():raise RuntimeError('MQL5_CHECK_FAILED '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target)
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),
            'build':build_path.relative_to(ROOT).as_posix(),'build_sha256':settings.sha(build_path),
            'script_sha256':settings.sha(script),'results_sha256':settings.sha(target),'inputs_sha256':settings.sha(out/'cases.bin')},indent=2),encoding='utf-8')
        print('MQL5 initialization results saved');return
    data=target.read_bytes();run=json.loads((out/'mql5-run.json').read_text())
    if run['exit_code'] or run['results_sha256']!=settings.sha(target) or run['inputs_sha256']!=settings.sha(out/'cases.bin'):
        raise ValueError('MQL5_RESULT_NOT_VERIFIED')
    if data[:12]!=struct.pack('<3i',MAGIC,1,len(rows)):raise ValueError('BAD_RESULT_HEADER')
    pos=12;failures=[];fmt='<iiQQqiQ';size=struct.calcsize(fmt)
    for row in rows:
        actual=struct.unpack_from(fmt,data,pos);pos+=size;texts=[]
        for _ in range(2):
            n=struct.unpack_from('<i',data,pos)[0];pos+=4
            if not 0<=n<=1000:raise ValueError('BAD_RESULT_STRING_LENGTH')
            texts.append(data[pos:pos+2*n].decode('utf-16-le'));pos+=2*n
        expected=row['original'];count,hash_=trace_result(expected['trace'])
        wanted=(row['case'],0,expected['current_bits'],expected['peak_bits'],expected['last_time'],count,hash_)
        if actual!=wanted or texts!=[expected['peak_key'],expected['time_key']]:
            failures.append({'case':row['case'],'actual':actual,'expected':wanted,'actual_keys':texts,'expected_keys':[expected['peak_key'],expected['time_key']]})
    if pos!=len(data):raise ValueError('RESULT_BYTES_NOT_EXACT')
    result={'bot':a.bot,'cases':len(rows),'matched':len(rows)-len(failures),'failed':len(failures),'passed':not failures,
        'first_failures':failures[:8],'tool_sha256':settings.sha(Path(__file__)),'native_reference_sha256':settings.sha(ref/'summary.json'),
        'inputs_sha256':settings.sha(out/'cases.bin'),'mql5_result_sha256':settings.sha(target),
        'scope':'Source initialization versus original bounded segment: both numeric states, exact key strings, timestamp and ordered account/storage/clock/sleep calls. Diagnostics, last-error codes, allocation failures and whole OnInit/EA excluded. MQL5 uses real number/string conversions; storage/account APIs are supplied.'}
    with (out/'comparison.json').open('x',encoding='utf-8') as f:json.dump(result,f,ensure_ascii=False,indent=2)
    print(json.dumps(result));raise SystemExit(bool(failures))


if __name__=='__main__':main()
