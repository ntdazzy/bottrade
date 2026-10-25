"""Run the two inventoried resize-failure cases separately in private MT5.

Usage: kiem-loi-bang-dung-ao-bot-1.py MATRIX_RUN --build BUILD --check-run NEW_RUN
Requires a successful normal matrix run. Keeps each fatal run in a new folder.
Compares the last complete full-state service record and native fatal class;
source line/column metadata is recorded as different, not claimed identical.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('virtual_matrix',Path(__file__).with_name('kiem-bang-dung-ao-day-du-bot-1.py'))
matrix=importlib.util.module_from_spec(spec);spec.loader.exec_module(matrix)
MT=matrix.MT;require=matrix.require;sha=matrix.sha;save=matrix.save

class ObservedArrayFault(Exception):pass
class Original(matrix.Original):
    def __init__(self,records):
        super().__init__(records);self.full_snapshot=True;self.fault=None
    def call(self,m,address,size,user):
        if self.apis[address]!=8:return super().call(m,address,size,user)
        require(self.event==len(self.records),'FATAL_BEFORE_EXPECTED_API_RECORDS')
        require(self.records and self.snapshot()==self.records[-1][3],'FATAL_FINAL_STATE_DIFFERS')
        code=m.reg_read(self.x.UC_X86_REG_RDX)
        require(code&0xffffffff==0x1f6,'UNEXPECTED_FATAL_CLASS')
        require(self.records[-1][0]==3 and self.array()==self.records[-1][2][3],'FATAL_ARRAY_CHANGED_AFTER_LAST_SERVICE')
        stack=m.reg_read(self.x.UC_X86_REG_RSP)
        return_address=struct.unpack('<Q',m.mem_read(stack,8))[0]
        self.fault=dict(code=hex(code),class_low32=code&0xffffffff,
            return_rva=hex(return_address-self.base),state_sha256=hashlib.sha256(self.snapshot()).hexdigest(),
            array_sha256=hashlib.sha256(self.array()[2]).hexdigest(),service_records_consumed=self.event)
        raise ObservedArrayFault()

def log_offsets():
    result={}
    for folder in [MT/'MQL5/Logs',MT/'logs']:
        if folder.is_dir():
            for path in folder.glob('*.log'):result[path]=path.stat().st_size
    return result
def added_logs(before):
    lines=[]
    for path,size in log_offsets().items():
        offset=before.get(path,0);raw=path.read_bytes()
        if len(raw)<offset:offset=0
        text=raw[offset:].decode('utf-16-le',errors='replace').replace('\ufeff','')
        lines.extend(line for line in text.splitlines() if
            'VIRTUAL_MATRIX_CASE:' in line or 'array out of range' in line.lower() or
            'Bot1VirtualStops' in line or 'shutdown' in line.lower())
    return lines
def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('matrix_run');parser.add_argument('--build',required=True);parser.add_argument('--check-run',required=True)
    args=parser.parse_args()
    require(all(re.fullmatch('[a-z0-9-]{1,40}',v) for v in [args.matrix_run,args.build,args.check_run]),'INVALID_RUN_OR_BUILD')
    home=ROOT/'bot-cua-toi-1';folder=home/'bang-chung/kiem-bang-dung-ao'/args.matrix_run
    current=matrix.identity();baseline=json.loads((folder/'baseline.json').read_text())
    matrix.check_identity(baseline,current)
    comparison=json.loads((folder/'comparison.json').read_text())
    require(comparison['failed']==0 and comparison['cases']==comparison['matched'],'NORMAL_MATRIX_NOT_PASSED')
    rows=matrix.cases();require((folder/'cases.bin').read_bytes()==matrix.encode(rows),'MATRIX_INPUT_CHANGED')
    receipt_path=home/'bang-chung/bien-dich'/args.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    require(receipt['target']==matrix.SOURCES[2] and receipt['errors']==receipt['warnings']==0,'BUILD_NOT_CLEAN')
    for name,digest in current['sources_sha256'].items():
        require(receipt['sources_sha256'][name]==digest==sha(MT/'MQL5'/name),'COMPILED_OR_PRIVATE_SOURCE_CHANGED')
    binary=MT/'MQL5'/Path(matrix.SOURCES[2]).with_suffix('.ex5')
    require(sha(binary)==receipt['binary_sha256']==sha(receipt_path.parent/binary.name),'BINARY_CHANGED')
    out=folder/'fatal-checks'/args.check_run;out.mkdir(parents=True,exist_ok=False);checks=[];covered={}
    for case in [c for c in rows if c['fatal']]:
        namespace=args.check_run+'-f'+str(case['id'])
        require(len(namespace)<=40,'FATAL_NAMESPACE_TOO_LONG')
        target=out/f"case-{case['id']}";target.mkdir()
        files=MT/'MQL5/Files/bot1-virtual-matrix'/namespace;files.mkdir(parents=True,exist_ok=False)
        shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b1-{namespace}.set';ini=MT/f'b1-{namespace}.ini'
        with preset.open('x',encoding='utf-16') as stream:stream.write(f"CheckRun={namespace}\nOnlyCase={case['id']}\n")
        with ini.open('x',encoding='utf-16') as stream:stream.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1VirtualStopsCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        before=log_offsets();terminal_before=sha(MT/'terminal64.exe');started=time.monotonic()
        process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:
            process.terminate();process.wait(timeout=30);raise RuntimeError('FATAL_CASE_TIMEOUT')
        lines=added_logs(before)
        save(target/'execution.json',dict(exit_code=code,namespace=namespace,case_id=case['id'],seconds=round(time.monotonic()-started,2)))
        (target/'runtime-lines.txt').write_text('\n'.join(lines)+'\n',encoding='utf-8')
        require(code in [-1,0xffffffff] and any(f"VIRTUAL_MATRIX_CASE:{case['id']}" in line for line in lines),'FATAL_CASE_DID_NOT_START_OR_EXIT_AS_OBSERVED')
        require(any('array out of range' in line.lower() for line in lines),'REAL_ARRAY_ERROR_NOT_OBSERVED')
        require(not (files/'script-status.bin').exists(),'FATAL_CASE_RETURNED_NORMALLY')
        raw=(files/'mql5-results.bin').read_bytes()
        require(raw==struct.pack('<3i',matrix.MAGIC,matrix.VERSION,1),'FATAL_CASE_WROTE_NORMAL_RESULT')
        for name in ['mql5-results.bin','api-fixtures.bin']:
            shutil.copyfile(files/name,target/name)
        records=matrix.read_fixtures(target/'api-fixtures.bin',rows,selected=[case])
        runner=Original(records)
        try:runner.run_case(case)
        except ObservedArrayFault:pass
        else:raise ValueError('ORIGINAL_DID_NOT_RAISE_ARRAY_FAULT')
        require(runner.fault is not None,'NATIVE_FAULT_MISSING')
        terminal_after=sha(MT/'terminal64.exe');require(terminal_before==terminal_after,'TERMINAL_CHANGED')
        check=dict(case_id=case['id'],group=case['group'],exit_code=code,seconds=round(time.monotonic()-started,2),
            native=runner.fault,mql5_error_class='array out of range',no_normal_result=True,
            hashes={name:sha(target/name) for name in ['mql5-results.bin','api-fixtures.bin','runtime-lines.txt']},
            terminal_sha256_before=terminal_before,terminal_sha256_after=terminal_after)
        save(target/'verification.json',check);checks.append(check)
        for lo,values in runner.covered.items():covered.setdefault(hex(lo),set()).update(values)
    report=dict(checks=checks,tool_sha256=sha(Path(__file__)),matrix_tool_sha256=current['tool_sha256'],
        matrix_baseline_sha256=sha(folder/'baseline.json'),build_receipt_sha256=sha(receipt_path),
        covered_original_instructions={key:sorted(hex(v) for v in values) for key,values in covered.items()},
        whole_bot_complete=False,limits=['Resize failures are supplied to trigger the original error branch; physical out-of-memory behavior is not asserted.',
            'Native fatal low code0x1f6 and MQL5 array-error class/state agree; source line/column payloads differ and are not claimed identical.',
            'No tester,actual account,LastError,lifecycle or whole-EA proof.'])
    save(out/'summary.json',report);print(json.dumps({'fatal_cases':len(checks),'matched_error_class_and_state':len(checks),'whole_bot_complete':False}))

if __name__=='__main__':main()
