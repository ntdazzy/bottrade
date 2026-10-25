"""Run the real Bot1TryClosePosition from all three management call sites.
Supplied terminal answers and IsStopped=true prevent trade sends.
Expected query counts come from native close guard 0x3d010, already separately
compared with the original. This check verifies the caller links, not a whole EA.
Usage: check-management-close-link.py RUN --build BUILD
"""
import argparse,csv,hashlib,json,pathlib,re,shutil,struct,subprocess
HOME=pathlib.Path(__file__).resolve().parents[1]
ROOT=HOME.parent
MT=(ROOT.parent/'.local/mt5-bot1-thread-20261025').resolve()
TARGET='Scripts/bot-cua-toi-1/Bot1ManagementCloseLinkCheck.mq5'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def require(ok,message):
    if not ok:raise ValueError(message)
def save(p,value):
    with p.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('run');p.add_argument('--build',required=True);a=p.parse_args()
    require(bool(re.fullmatch('[a-z0-9-]{1,50}',a.run)),'BAD_RUN')
    receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json'
    build=json.loads(receipt.read_text(encoding='utf-8-sig'))
    require(build['errors']==build['warnings']==0 and build['target']==TARGET,'BUILD_NOT_CLEAN')
    for name,value in build['sources_sha256'].items():
        require(sha(HOME/'source/MQL5'/name)==value==sha(MT/'MQL5'/name),'SOURCE_DIFFERS:'+name)
    binary=MT/'MQL5'/pathlib.Path(TARGET).with_suffix('.ex5')
    require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
    out=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run
    out.mkdir(parents=True,exist_ok=False);tested=out/'tested-sources';tested.mkdir()
    required=[TARGET]+[n for n in build['sources_sha256'] if n.startswith('Include/')]
    for name in required:shutil.copyfile(HOME/'source/MQL5'/name,tested/pathlib.Path(name).name)
    shutil.copyfile(pathlib.Path(__file__),tested/pathlib.Path(__file__).name)
    baseline=dict(target=TARGET,build_receipt_sha256=sha(receipt),binary_sha256=sha(binary),tool_sha256=sha(pathlib.Path(__file__)),
                  sources_sha256={n:build['sources_sha256'][n] for n in required},expected_cases=36,
                  expected_basis='Native close guard 0x3d010 and separately verified Bot1PositionClose.mqh; counts verify real guard execution at callers.',
                  whole_bot_complete=False)
    save(out/'baseline.json',baseline)
    files=MT/'MQL5/Files/bot1-management-close-link'/a.run
    require(not files.exists(),'MT5_OUTPUT_EXISTS')
    preset=MT/'MQL5/Presets'/('b1-link-'+a.run+'.set')
    with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
    ini=MT/('b1-link-'+a.run+'.ini')
    with ini.open('x',encoding='utf-16') as f:
        f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ManagementCloseLinkCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
    process=subprocess.Popen('"'+str(MT/'terminal64.exe')+'" /portable /config:"'+str(ini)+'"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=process.wait(timeout=120)
    except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT_NOT_ZERO')
    for name in ['results.tsv','script-status.bin']:
        with (out/name).open('xb') as f:f.write((files/name).read_bytes())
    status=struct.unpack('<2i',(out/'script-status.bin').read_bytes())
    with (out/'results.tsv').open(encoding='utf-8',newline='') as f:rows=list(csv.DictReader(f,delimiter='\t'))
    failed=[r for r in rows if r['passed']!='1']
    report=dict(cases=len(rows),failed=len(failed),matched=len(rows)-len(failed),first_failures=failed[:6],
                script_status=list(status),result_sha256=sha(out/'results.tsv'),binary_sha256=sha(binary),
                real_close_guard_executed=True,is_stopped_always_true=True,whole_bot_complete=False,
                limits=['Checks caller links and supplied blocked/stopped guard paths; not a native full-manager run, send-path comparison or full EA.'])
    save(out/'comparison.json',report)
    print(json.dumps(report))
    require(len(rows)==36 and not failed and status==(0,36),'CLOSE_LINK_CHECK_FAILED')
if __name__=='__main__':main()
