"""Write two scoped values through the withdrawal component; restart MT5 and read them.

python -I -B -X utf8 kiem-luu-trang-thai-bot-1-3.py BOT RUN
Uses only the private portable terminal. History is supplied; actual terminal variable
writes/reads are used. The read phase deletes exactly the two newly created test keys.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import time
import shutil

ROOT=Path(__file__).resolve().parents[1]
MT=ROOT.parent/'.local/claude-recovery-20261023/mt5'
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,40}',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-luu-trang-thai'/a.run;out.mkdir(parents=True,exist_ok=False)
    files=MT/f'MQL5/Files/bot{a.bot}-withdrawal-storage'/a.run;files.mkdir(parents=True,exist_ok=False)
    script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}WithdrawalStorageCheck.ex5'
    if not script.is_file():raise FileNotFoundError(script)
    phases=[]
    for phase in ['write','read']:
        params=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}-{phase}.set'
        params.write_text('CheckRun='+a.run+'\nReadStored='+('true' if phase=='read' else 'false')+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-{phase}-storage.ini'
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}WithdrawalStorageCheck\nScriptParameters={params.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_STORAGE_TIMEOUT '+phase)
        if code!=0:raise RuntimeError('MQL5_STORAGE_EXIT '+phase+' '+str(code))
        target=out/(phase+'.bin');shutil.copyfile(files/(phase+'.bin'),target)
        raw=target.read_bytes()
        if len(raw)!=32:raise ValueError('STORAGE_RESULT_SHAPE')
        magic,read,correct,cleaned,peak,last_deal=struct.unpack('<4i2d',raw)
        if (magic,read,correct,cleaned,peak,last_deal)!=(0x53544731,int(phase=='read'),1,1,9000.,700.):raise ValueError('STORAGE_VALUES_DIFFER')
        phases.append({'phase':phase,'pid':p.pid,'exit_code':code,'seconds':round(time.monotonic()-start,2),'peak':peak,'last_deal':last_deal,'result_sha256':sha(target),'parameters_sha256':sha(params)})
    result={'bot':a.bot,'passed':True,'distinct_processes':phases[0]['pid']!=phases[1]['pid'],'phases':phases,'script_sha256':sha(script),'tool_sha256':sha(Path(__file__)),
        'test_keys_cleaned':True,'scope':__doc__}
    (out/'comparison.json').write_text(json.dumps(result,indent=2),encoding='utf-8');print(json.dumps(result))
if __name__=='__main__':main()
