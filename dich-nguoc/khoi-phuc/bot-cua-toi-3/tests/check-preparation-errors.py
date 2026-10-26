"""Run the 18 retained zero-division cases separately in private MT5.

Usage: check-preparation-errors.py RUN --build BUILD
Proves the observed fatal class and absence of a normal result, not all partial state.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess,time
from pathlib import Path

HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
FULL_PATH=Path(__file__).with_name('check-preparation-full.py')
spec=importlib.util.spec_from_file_location('preparation_error_full',FULL_PATH);full=importlib.util.module_from_spec(spec);spec.loader.exec_module(full)
MT,sha,require,save=full.MT,full.sha,full.require,full.save
CONTRACT=ROOT/'claude-thuc-hien/bot3-preparation-fault-check-20261026-r1/TASK.md'
CASES=full.BINDINGS.parent/'legacy-error-cases.json'

def log_sizes():
    return {p:p.stat().st_size for folder in [MT/'MQL5/Logs',MT/'logs'] if folder.is_dir() for p in folder.glob('*.log')}

def added_lines(before):
    out=[]
    for p,size in log_sizes().items():
        raw=p.read_bytes();start=before.get(p,0)
        text=raw[start if start<=len(raw) else 0:].decode('utf-16-le',errors='replace').replace('\ufeff','')
        out.extend(line for line in text.splitlines() if 'PREPARATION_CASE:' in line or 'zero divide' in line.lower() or 'array out of range' in line.lower() or 'Bot3Preparation' in line)
    return out

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('run');p.add_argument('--build',required=True);a=p.parse_args()
    require(all(re.fullmatch('[a-z0-9-]{1,40}',n) for n in [a.run,a.build]),'BAD_RUN_OR_BUILD')
    data=json.loads(CASES.read_bytes());rows=data['rows'];require(len(rows)==18 and all(c['id']==i for i,c in enumerate(rows)),'ERROR_COHORT_DIFFERS')
    current=full.identity();receipt_path=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    require(build['target']==full.SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
    for name,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/name)==build['sources_sha256'][name]==digest,'COMPILED_SOURCE_DIFFERS '+name)
    binary=MT/'MQL5'/Path(full.SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt_path.parent/binary.name),'BINARY_DIFFERS')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;folder.mkdir(parents=True,exist_ok=False)
    encoded=full.encode(rows);(folder/'cases.bin').write_bytes(encoded);checks=[];runner=full.Original()
    terminal_hash=sha(MT/'terminal64.exe')
    for c in rows:
        # Deliberately call the base runner: the ordinary-only wrapper rejects runtime errors.
        full.legacy.Original.run(runner,c)
        require(runner.error and runner.error&0xffffffff==0x1f7,'NATIVE_ZERO_DIVISION_MISSING')
        native=dict(code=hex(runner.error),class_low32=runner.error&0xffffffff,api_counts=runner.api_counts)
        namespace=a.run+'-f'+str(c['id']);require(len(namespace)<=50,'NAMESPACE_TOO_LONG')
        target=folder/('case-'+str(c['id']));target.mkdir();files=MT/'MQL5/Files/bot3-preparation'/namespace;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b3-prep-'+namespace+'.set');ini=MT/('b3-prep-'+namespace+'.ini')
        with preset.open('x',encoding='utf-16') as stream:stream.write('CheckRun='+namespace+'\nOnlyCase='+str(c['id'])+'\n')
        with ini.open('x',encoding='utf-16') as stream:stream.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3PreparationCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        before=log_sizes();started=time.monotonic();proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('FATAL_CASE_TIMEOUT')
        lines=added_lines(before);save(target/'execution.json',dict(case_id=c['id'],source_case_id=c['source_case_id'],namespace=namespace,exit_code=code,seconds=round(time.monotonic()-started,2)))
        (target/'runtime-lines.txt').write_bytes(('\n'.join(lines)+'\n').encode())
        require(any('PREPARATION_CASE:'+str(c['id']) in line for line in lines),'CASE_MARKER_MISSING')
        require(any('zero divide' in line.lower() for line in lines),'REAL_ZERO_DIVISION_NOT_OBSERVED')
        require(code in [-1,0xffffffff] and not (files/'script-status.bin').exists(),'ERROR_RETURNED_NORMALLY')
        raw=(files/'mql5-results.bin').read_bytes();require(raw==full.output_header(1),'ERROR_WROTE_NORMAL_RESULT');(target/'mql5-results.bin').write_bytes(raw)
        check=dict(case_id=c['id'],source_case_id=c['source_case_id'],native=native,mql5_fatal_class='zero divide',no_normal_record=True,partial_state_compared=False,hashes={n:sha(target/n) for n in ['mql5-results.bin','runtime-lines.txt']});save(target/'verification.json',check);checks.append(check)
        require(sha(MT/'terminal64.exe')==terminal_hash,'TERMINAL_CHANGED')
        print(json.dumps(dict(checked=len(checks),of=len(rows),source_case_id=c['source_case_id'])),flush=True)
    report=dict(checks=checks,cases=len(rows),matched_fatal_class_and_no_normal_result=len(checks),tool_sha256=sha(Path(__file__)),full_tool_sha256=sha(FULL_PATH),cases_sha256=sha(CASES),contract_sha256=sha(CONTRACT),build_receipt_sha256=sha(receipt_path),terminal_sha256=terminal_hash,identity=current,whole_bot_complete=False,limits=['Only the zero-division fatal class and absence of a normal record are compared. No complete partial-state or exact source-line/error-payload equivalence claim.', 'Indicator/tick and market replies are supplied successfully; no other service-failure, short-array, real broker or full-EA proof.'])
    save(folder/'error-comparison.json',report);print(json.dumps(dict(cases=len(rows),matched=len(checks),partial_state_compared=False,whole_bot_complete=False)))

if __name__=='__main__':main()
