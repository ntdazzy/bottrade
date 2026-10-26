"""Run one original bot in the private Strategy Tester and capture its code/data.

Usage from project root: python -I -B -X utf8 dich-nguoc/khoi-phuc/cong-cu/chay-chup-bot-1-3.py 1 RUN
Bot must be 1, 2 or 3. RUN must be new. Existing evidence and originals are never overwritten.
The account is the already authorized demo used by this project's private tester.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys
import time

ap = argparse.ArgumentParser(description=__doc__)
ap.add_argument('bot', type=int, choices=(1, 2, 3))
ap.add_argument('run')
a = ap.parse_args()
if not re.fullmatch('[a-z0-9-]+', a.run):
    raise ValueError('INVALID_RUN')
root = Path(__file__).resolve().parents[1]
mt = root.parent / '.local/claude-recovery-20261023/mt5'
catalog = json.loads((root / 'tai-lieu-cu/catalog.json').read_text(encoding='utf-8'))
index, terminal_id = {1:(5, '820755052E4765D7D56E6DAAFBB28091'),2:(6,None),3:(16, 'D0E8209F77C8CF37AD8BF550E51FF075')}[a.bot]
entry = next(v for v in catalog if v['index'] == index)
if a.bot==2:
    original=Path('C:/Users/NTD/Desktop/BotTradeEA/local/market-demos-20261020/dich-nguoc-luot2/terminal/MQL5/Experts/Market')/entry['test']['ex5']
else:
    original = Path.home() / 'AppData/Roaming/MetaQuotes/Terminal' / terminal_id / 'MQL5/Experts/Market' / entry['test']['ex5']
def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()
if sha(original) != entry['sha256'].lower():
    raise ValueError('ORIGINAL_HASH_MISMATCH')
destination = mt / 'MQL5/Experts/Market' / original.name
if destination.exists() and sha(destination) != sha(original):
    raise ValueError('EXISTING_PRIVATE_COPY_DIFFERS')
out = root / f'bot-cua-toi-{a.bot}/bang-chung' / a.run
capture = out.parent / 'captures' / a.run
if out.exists() or capture.exists():
    raise FileExistsError('RUN_EXISTS')
out.mkdir(parents=True)
if not destination.exists():
    shutil.copyfile(original, destination)
job = {'id': f'b{a.bot}-{a.run}', 'expert': 'Market\\' + original.name,
       'symbol': 'XAUUSD_NOCOST_V2', 'period': entry['test']['period'],
       'model': 0, 'from': entry['test']['from'], 'to': entry['test']['to'], 'timeout': 300,
       'inputs': entry['test'].get('inputs', {})}
jobs = out / 'jobs.json'
jobs.write_text(json.dumps([job], indent=2), encoding='utf-8')
runner = [sys.executable, '-I', '-B', '-X', 'utf8', str(root / 'cong-cu/chay-may-thu.py'),
          str(mt), str(jobs), str(out), '--login', '279786616', '--server', 'Exness-MT5Trial8']
record = {'bot': a.bot, 'source': str(original), 'source_sha256': sha(original),
          'tester_sha256': sha(mt / 'metatester64.exe'), 'job': job}
with (out / 'runner.stdout.txt').open('x', encoding='utf-8') as stdout, (out / 'runner.stderr.txt').open('x', encoding='utf-8') as stderr:
    proc = subprocess.Popen(runner, stdout=stdout, stderr=stderr, creationflags=subprocess.CREATE_NO_WINDOW)
    print(f'START bot {a.bot}, runner PID {proc.pid}', flush=True)
    deadline = time.monotonic() + 90
    owned = None
    while time.monotonic() < deadline and proc.poll() is None:
        script = 'Get-Process metatester64 -ErrorAction SilentlyContinue | ForEach-Object { [pscustomobject]@{id=$_.Id;path=$_.Path;base=$_.MainModule.BaseAddress.ToInt64();started=$_.StartTime.Ticks} } | ConvertTo-Json -Compress'
        raw = subprocess.run(['powershell', '-NoProfile', '-Command', script], capture_output=True, text=True).stdout.strip()
        if raw:
            rows = json.loads(raw)
            if isinstance(rows, dict):
                rows = [rows]
            owned = next((r for r in rows if r.get('path') and Path(r['path']).resolve() == (mt / 'metatester64.exe').resolve()), None)
            if owned:
                break
        time.sleep(0.1)
    if owned:
        record['tester_pid'] = owned['id']
        record['engine_base'] = hex(owned['base'])
        (out / 'capture-run.json').write_text(json.dumps(record, indent=2), encoding='utf-8')
        capture_cmd = [sys.executable, '-I', '-B', '-X', 'utf8', str(root / 'cong-cu/chup-bot-1-3.py'),
                       '--bot', str(a.bot), '--pid', str(owned['id']), '--out', str(capture),
                       '--min-code-bytes', '8192', '--wait-seconds', '15', '--include-readonly', '--include-program-data']
        capture_result = subprocess.run(capture_cmd, capture_output=True, text=True, encoding='utf-8')
        record['capture_exit'] = capture_result.returncode
        (out / 'capture.stdout.txt').write_text(capture_result.stdout, encoding='utf-8')
        (out / 'capture.stderr.txt').write_text(capture_result.stderr, encoding='utf-8')
        print(capture_result.stdout.strip() or capture_result.stderr[-1500:], flush=True)
    else:
        record['capture_error'] = 'PRIVATE_TESTER_NOT_FOUND'
    record['runner_exit'] = proc.wait(timeout=1000)
    if owned:
        # The tester can outlive a timed-out terminal. Stop only the exact process observed above.
        cleanup = f"$ErrorActionPreference='Stop'; $p=Get-Process -Id {owned['id']} -ErrorAction SilentlyContinue; if ($p -and $p.StartTime.Ticks -eq {owned['started']}) {{ Stop-Process -Id $p.Id }}; exit 0"
        subprocess.run(['powershell', '-NoProfile', '-Command', cleanup], check=True)
    result_file = out / 'ket-qua-chay.jsonl'
    results = [json.loads(line) for line in result_file.read_text(encoding='utf-8').splitlines()] if result_file.exists() else []
    test = next((r for r in reversed(results) if r['id'] == job['id']), {})
    record['test_completed'] = test.get('exit_code') == 0 and test.get('report_created') is True
    record['test_exit_code'] = test.get('exit_code')
(out / 'capture-run.json').write_text(json.dumps(record, indent=2), encoding='utf-8')
print(json.dumps(record), flush=True)
if record.get('capture_exit') != 0 or record['runner_exit'] != 0 or not record['test_completed']:
    raise SystemExit(1)
