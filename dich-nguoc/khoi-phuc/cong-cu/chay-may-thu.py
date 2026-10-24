"""Chạy từng lượt máy thử MT5 riêng (không tài khoản) và lưu nhật ký vào thư mục bằng chứng.

Dựa trên cong-cu-cu/run_market.py; khác: máy thử phải nằm trong dich-nguoc/.local,
đường dẫn EA tính từ MQL5/Experts, ghi mã băm EA/dữ liệu/chương trình vào ket-qua-chay.jsonl.

Dùng:
  python -I -B -X utf8 chay-may-thu.py <thu-muc-mt5-rieng> <jobs.json> <thu-muc-ra> [--only id1,id2]
Job: {"id","expert":"Market\\\\X.ex5","symbol","period","model","from","to","deposit"?,"leverage"?,"inputs":{...}}
--login/--server: tài khoản demo đã lưu trong config/accounts.dat của máy thử riêng (MT5 build 6230
không chạy máy thử khi chưa có tài khoản). Sau mỗi lượt đọc nhật ký terminal: ghi dòng xác nhận đăng nhập,
dừng ngay nếu nhật ký báo tài khoản thật hoặc không xác nhận được đúng tài khoản/máy chủ.
Không ghi đè nhật ký đã có; lượt đã có thì bỏ qua.
"""
import argparse
import hashlib
import json
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

LOCAL = Path(__file__).resolve().parents[2] / '.local'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def busy(mt):
    out = subprocess.run(['powershell', '-NoProfile', '-Command',
                          "Get-Process terminal64,metatester64 -ErrorAction SilentlyContinue | ForEach-Object { $_.Path }"],
                         capture_output=True, text=True).stdout
    return [p for p in out.splitlines() if p.strip().lower().startswith(str(mt).lower() + '\\')]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('terminal')
    ap.add_argument('jobs')
    ap.add_argument('out')
    ap.add_argument('--only', default='')
    ap.add_argument('--login', type=int)
    ap.add_argument('--server')
    a = ap.parse_args()
    if (a.login is None) != (a.server is None) or (a.server and not re.fullmatch(r'[A-Za-z0-9_.-]+', a.server)):
        raise ValueError('LOGIN_AND_SERVER_REQUIRED_TOGETHER')
    mt = Path(a.terminal).resolve()
    if not mt.is_relative_to(LOCAL.resolve()):
        raise ValueError('TERMINAL_MUST_BE_INSIDE_DICH_NGUOC_LOCAL')
    if not (mt / 'terminal64.exe').is_file():
        raise FileNotFoundError('MISSING_ISOLATED_MT5')
    out = Path(a.out).resolve()
    out.mkdir(parents=True, exist_ok=True)
    jobs = json.loads(Path(a.jobs).read_text(encoding='utf-8-sig'))
    if a.only:
        jobs = [j for j in jobs if j['id'] in a.only.split(',')]
    for job in jobs:
        name = job['id']
        if not re.fullmatch(r'[A-Za-z0-9_-]+', name) or '..' in job['expert']:
            raise ValueError('INVALID_JOB')
        if (out / (name + '.log')).exists():
            print('SKIP existing ' + name, flush=True)
            continue
        # Tác tử máy thử của lượt trước có thể cần vài giây để thoát hẳn.
        for _ in range(30):
            if not busy(mt):
                break
            time.sleep(2)
        else:
            raise RuntimeError('ISOLATED_MT5_IS_BUSY')
        expert = mt / 'MQL5' / 'Experts' / job['expert']
        if not expert.is_file():
            raise FileNotFoundError('MISSING_EXPERT ' + job['expert'])
        lines = [f'{k}={v}' for k, v in job.get('inputs', {}).items()]
        (mt / 'MQL5/Profiles/Tester').mkdir(parents=True, exist_ok=True)
        (mt / 'MQL5/Profiles/Tester' / (name + '.set')).write_text('\n'.join(lines) + '\n', encoding='utf-16')
        common = f'Login={a.login}\nServer={a.server}' if a.login else 'Login=0'
        config = f'''[Common]
{common}
KeepPrivate=1
NewsEnable=0
[Experts]
Enabled=0
AllowLiveTrading=0
AllowDllImport=0
[Tester]
Expert={job['expert']}
ExpertParameters={name}.set
Symbol={job['symbol']}
Period={job['period']}
Model={job['model']}
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
        old = {p: p.stat().st_size for p in list(mt.glob('Tester/**/*.log')) + list(mt.glob('logs/*.log'))}
        history = mt / 'bases/Custom/history' / job['symbol']
        history_before = {p.name: sha(p) for p in sorted(history.glob('*.hcc'))}
        print('START ' + name, flush=True)
        started = time.monotonic()
        # Đường dẫn có dấu cách: phải viết /config:"..." (nếu để Python tự bọc cả tham số,
        # terminal đọc thừa dấu " và báo cannot load config).
        command = f'"{mt / "terminal64.exe"}" /portable /config:"{ini}"'
        proc = subprocess.Popen(command, cwd=mt, creationflags=subprocess.CREATE_NO_WINDOW)
        try:
            code = proc.wait(timeout=job.get('timeout', 900))
        except subprocess.TimeoutExpired:
            proc.terminate()
            proc.wait(timeout=30)
            code = -1
        chunks = []
        for path in sorted(mt.glob('Tester/**/*.log')):
            start = old.get(path, 0)
            if path.stat().st_size < start:
                start = 0
            with path.open('rb') as stream:
                stream.seek(start)
                data = stream.read()
            if data:
                chunks.append(f'##### {path.name} ({path.parent.parent.name})\n' + data.decode('utf-16-le', errors='replace'))
        (out / (name + '.log')).write_text('\n'.join(chunks), encoding='utf-8')
        terminal_chunks = []
        for path in sorted(mt.glob('logs/*.log')):
            start = old.get(path, 0)
            if path.stat().st_size < start:
                start = 0
            with path.open('rb') as stream:
                stream.seek(start)
                data = stream.read()
            if data:
                terminal_chunks.append(data.decode('utf-16-le', errors='replace'))
        terminal_text = '\n'.join(terminal_chunks)
        (out / (name + '.terminal.log')).write_text(terminal_text, encoding='utf-8')
        account_lines = [l.split('\t')[-1].strip() for l in terminal_text.splitlines()
                         if re.search(r'authorized on|demo account|real account|contest account|account is not specified', l)]
        login_confirmed = bool(a.login) and any(f"'{a.login}': authorized on {a.server}" in l for l in account_lines)
        demo_confirmed = any('demo account' in l for l in account_lines)
        real_seen = any('real account' in l for l in account_lines)
        report = mt / 'reports' / (name + '.htm')
        if report.exists():
            shutil.copyfile(report, out / (name + '.htm'))
        record = {
            'id': name, 'exit_code': code, 'seconds': round(time.monotonic() - started, 1),
            'report_created': report.exists(), 'report_sha256': sha(report) if report.exists() else None,
            'log_sha256': sha(out / (name + '.log')), 'account_lines': account_lines,
            'login_confirmed': login_confirmed, 'demo_confirmed': demo_confirmed,
            'expert': job['expert'], 'expert_sha256': sha(expert),
            'terminal_sha256': sha(mt / 'terminal64.exe'), 'tester_sha256': sha(mt / 'metatester64.exe'),
            'history_sha256_before': history_before,
            'history_sha256_after': {p.name: sha(p) for p in sorted(history.glob('*.hcc'))},
            'job': job,
        }
        with (out / 'ket-qua-chay.jsonl').open('a', encoding='utf-8') as stream:
            stream.write(json.dumps(record, ensure_ascii=False) + '\n')
        print(json.dumps({k: record[k] for k in ('id', 'exit_code', 'seconds', 'report_created',
                                                 'login_confirmed', 'demo_confirmed')}), flush=True)
        if real_seen:
            raise RuntimeError('REAL_ACCOUNT_SEEN_STOP')
        if a.login and not (login_confirmed and demo_confirmed):
            raise RuntimeError('DEMO_LOGIN_NOT_CONFIRMED_STOP')


if __name__ == '__main__':
    sys.exit(main())
