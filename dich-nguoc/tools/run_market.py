"""Run MQL5 Market demo EAs in a portable MT5 tester, one job at a time.

Usage: python run_market.py <terminal_dir> <jobs.json> [--only id1,id2]
Job: {"id","ex5","symbol","period","from","to","set_file"?,"inputs":{name:value}} (inputs override set_file lines)
Each run writes <terminal>/reports/<id>.htm and market-logs/<id>.log; never overwrites a report.
"""
import argparse
import json
import subprocess
import time
import sys
import re
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project_paths import EVIDENCE, TERMINAL, PROJECT
root = EVIDENCE
parser = argparse.ArgumentParser()
parser.add_argument('terminal')
parser.add_argument('jobs')
parser.add_argument('--only', default='')
args = parser.parse_args()
mt = Path(args.terminal).resolve()
if mt != TERMINAL.resolve():
    raise ValueError('USE_ONLY_DICH_NGUOC_LOCAL_TERMINAL')
if not (mt / 'terminal64.exe').is_file():
    raise FileNotFoundError('MISSING_ISOLATED_MT5: see dich-nguoc/tools/README.md')
job_path = Path(args.jobs).resolve()
if not job_path.is_relative_to(PROJECT):
    raise ValueError('JOBS_OUTSIDE_PROJECT')
jobs = json.loads(job_path.read_text(encoding='utf-8-sig'))
if args.only:
    jobs = [j for j in jobs if j['id'] in args.only.split(',')]
logs = root / 'market-logs'
logs.mkdir(exist_ok=True)
status_file = logs / f'status_{mt.name}.jsonl'

for job in jobs:
    name = job['id']
    if not re.fullmatch(r'[A-Za-z0-9_-]+', name) or Path(job['ex5']).name != job['ex5']:
        raise ValueError('INVALID_JOB_NAME_OR_EXPERT')
    report = mt / 'reports' / (name + '.htm')
    if report.exists():
        print('SKIP existing ' + name, flush=True)
        continue
    set_line = ''
    if job.get('inputs') or job.get('set_file'):
        lines = []
        if job.get('set_file'):
            raw = Path(job['set_file']).read_bytes()
            text = raw.decode('utf-16' if raw[:2] in (b'\xff\xfe', b'\xfe\xff') else 'utf-8-sig', errors='strict')
            lines = [l for l in text.splitlines() if l.split('=', 1)[0] not in job.get('inputs', {})]
        lines += [f'{k}={v}' for k, v in job.get('inputs', {}).items()]
        (mt / 'MQL5/Profiles/Tester' / (name + '.set')).write_text('\n'.join(lines) + '\n', encoding='utf-16')
        set_line = f'ExpertParameters={name}.set\n'
    config = f'''[Experts]
Enabled=0
AllowLiveTrading=0
AllowDllImport=0
[Tester]
Expert=Market\\{job['ex5']}
{set_line}Symbol={job.get('symbol', 'XAUUSD_NOCOST_V2')}
Period={job['period']}
Model={job.get('model', 4)}
FromDate={job['from']}
ToDate={job['to']}
Deposit={job.get('deposit', 10000)}
Currency=USD
Leverage=1:{job.get('leverage', 500)}
ExecutionMode=0
Optimization=0
Visual=0
UseLocal=1
UseRemote=0
UseCloud=0
Report=reports\\{name}
ReplaceReport=0
ShutdownTerminal=1
'''
    ini = mt / (name + '.ini')
    ini.write_text(config, encoding='utf-16')
    old = {p: p.stat().st_size for p in mt.glob('Tester/**/*.log')}
    print('START ' + name, flush=True)
    started = time.monotonic()
    proc = subprocess.Popen([str(mt / 'terminal64.exe'), '/portable', f'/config:{ini}'], cwd=mt,
                            creationflags=subprocess.CREATE_NO_WINDOW)
    try:
        code = proc.wait(timeout=job.get('timeout', 3600))
    except subprocess.TimeoutExpired:
        proc.terminate()
        proc.wait(timeout=30)
        code = -1
    chunks = []
    for path in mt.glob('Tester/**/*.log'):
        start = old.get(path, 0)
        if path.stat().st_size < start:
            start = 0
        with path.open('rb') as stream:
            stream.seek(start)
            data = stream.read()
        if data:
            chunks.append(f'##### {path.name} ({path.parent.parent.name})\n' + data.decode('utf-16-le', errors='replace'))
    (logs / (name + '.log')).write_text('\n'.join(chunks), encoding='utf-8')
    record = {'id': name, 'exit_code': code, 'seconds': round(time.monotonic() - started, 1), 'report': report.exists()}
    with status_file.open('a', encoding='utf-8') as stream:
        stream.write(json.dumps(record) + '\n')
    print(json.dumps(record), flush=True)
