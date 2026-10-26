"""Measure actual MT5 division behavior in the dedicated bot3 terminal.

probe-division-behavior.py RUN --build BUILD. No orders or market reads.
"""
import argparse,importlib.util,json,re,struct,subprocess,time
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
spec=importlib.util.spec_from_file_location('division_full',Path(__file__).with_name('check-preparation-full.py'));full=importlib.util.module_from_spec(spec);spec.loader.exec_module(full)
MT,sha,require,save=full.MT,full.sha,full.require,full.save

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('run');p.add_argument('--build',required=True);a=p.parse_args();require(all(re.fullmatch('[a-z0-9-]{1,40}',s) for s in [a.run,a.build]),'BAD_RUN_OR_BUILD')
    source=HOME/'source/MQL5/Scripts/bot-cua-toi-3/Bot3DivisionBehaviorCheck.mq5';receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));relative=source.relative_to(HOME/'source/MQL5').as_posix()
    require(build['errors']==build['warnings']==0 and build['target']==relative and sha(source)==build['sources_sha256'][relative],'BUILD_DIFFERS')
    binary=MT/'MQL5'/Path(relative).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
    folder=HOME/'phan-tich/chuong-trinh-chinh'/a.run;folder.mkdir(parents=True,exist_ok=False);results=[]
    for index,(mode,denominator) in enumerate([(i,0.0) for i in range(4)]+[(3,2.0),(3,-0.0)]):
        namespace=a.run+'-'+str(index);preset=MT/'MQL5/Presets'/(namespace+'.set');ini=MT/(namespace+'.ini')
        with preset.open('x',encoding='utf-16') as stream:stream.write('CheckMode='+str(mode)+'\nDenominator='+repr(denominator)+'\n')
        with ini.open('x',encoding='utf-16') as stream:stream.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3DivisionBehaviorCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        paths=lambda:[p for d in [MT/'MQL5/Logs',MT/'logs'] if d.is_dir() for p in d.glob('*.log')]
        before={p:p.stat().st_size for p in paths()};started=time.monotonic();proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('PROBE_TIMEOUT')
        lines=[]
        for log in paths():
            raw=log.read_bytes();off=before.get(log,0);text=raw[off if off<=len(raw) else 0:].decode('utf-16-le',errors='replace')
            lines.extend(line for line in text.splitlines() if 'DIVISION_' in line or 'zero divide' in line.lower() or 'Bot3DivisionBehaviorCheck' in line)
        require(any('DIVISION_BEGIN:'+str(mode) in line for line in lines),'PROBE_NOT_STARTED')
        (folder/('case-'+str(index)+'.txt')).write_bytes(('\n'.join(lines)+'\n').encode())
        row=dict(index=index,mode=mode,denominator_bits=hex(struct.unpack('<Q',struct.pack('<d',denominator))[0]),exit_code=code,seconds=round(time.monotonic()-started,2),zero_divide=any('zero divide' in line.lower() for line in lines),returned=any('DIVISION_RETURNED:'+str(mode) in line for line in lines));results.append(row);print(json.dumps(row),flush=True)
    save(folder/'probe.json',dict(results=results,source_sha256=sha(source),build_receipt_sha256=sha(receipt),binary_sha256=build['binary_sha256'],tool_sha256=sha(Path(__file__)),terminal_sha256=sha(MT/'terminal64.exe'),metaeditor_sha256=build['metaeditor_sha256'],whole_bot_complete=False,scope='Measured division/error class for six tiny calibration runs; no whole-bot or all-partial-state claim.'))

if __name__=='__main__':main()
