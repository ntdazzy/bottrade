"""Compare the 10 retained zero divisions and two short-array faults.

Runs each case separately in the private MT5. Checks fatal class and absence
of a normal result; this is not a claim about every partial state before error.
"""
import argparse, importlib.util, json, re, shutil, struct, subprocess, time
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
SPEC=importlib.util.spec_from_file_location('prep1_error_full',HOME/'tests/check-preparation-full.py')
full=importlib.util.module_from_spec(SPEC);SPEC.loader.exec_module(full)
MT,sha,require,save=full.MT,full.sha,full.require,full.save

def cases():
    rows=json.loads((full.LEGACY/'cases.json').read_text());raw=(full.LEGACY/'original-results.bin').read_bytes()
    import hashlib
    require(hashlib.sha256(raw).hexdigest()=='3d6037d44f0de2d1a3c96695a3bbb00d7f271954354320592e3f49685d3efcc1','LEGACY_RESULTS_CHANGED')
    chosen=[]
    for i,c in enumerate(rows):
        source_id,success=struct.unpack_from('<2i',raw,16+i*272)
        require(source_id==i,'LEGACY_ID_CHANGED')
        if not success:chosen.append(dict(c,source_case_id=i,id=len(chosen),short_size=-1,fatal_class='zero divide'))
    require(len(chosen)==10,'ERROR_COHORT_CHANGED')
    for n in [0,1]:
        c=full.legacy.base_case(1);chosen.append(dict(c,id=len(chosen),source_case_id=-1,short_size=n,fatal_class='array out of range'))
    return chosen

class Original(full.Original):
    def call(self,m,address,size,user):
        if self.apis[address]==11 and self.case['short_size']>=0:
            n=self.case['short_size'];desc=self.base+0x62190
            self.calls.append(2);m.mem_write(desc+2,struct.pack('<H',1));m.mem_write(desc+8,struct.pack('<I',n))
            m.mem_write(desc+28,struct.pack('<Q',0x70100000));m.mem_write(0x70100000,struct.pack('<2d',1000.,2000.))
            m.reg_write(self.x.UC_X86_REG_RAX,full.MASK);return
        return super().call(m,address,size,user)

def log_sizes():
    return {p:p.stat().st_size for folder in [MT/'MQL5/Logs',MT/'logs'] if folder.is_dir() for p in folder.glob('*.log')}

def added_lines(before):
    lines=[]
    for p,size in log_sizes().items():
        raw=p.read_bytes();start=before.get(p,0)
        lines.extend(line for line in raw[start if start<=len(raw) else 0:].decode('utf-16-le',errors='replace').splitlines()
                     if 'PREPARATION_CASE:' in line or 'zero divide' in line.lower() or 'array out of range' in line.lower())
    return lines

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('run');p.add_argument('--build',required=True);a=p.parse_args()
    require(all(re.fullmatch('[a-z0-9-]{1,40}',s) for s in [a.run,a.build]),'BAD_RUN_OR_BUILD')
    current=full.identity();receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
    require(build['target']==full.SCRIPT and build['errors']==build['warnings']==0 and build['floating_point_dividers_check_requested'],'BUILD_NOT_CLEAN_OR_DIVISION_CHECK_DISABLED')
    for n,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==digest,'BUILD_SOURCE_DIFFERS '+n)
    binary=MT/'MQL5'/Path(full.SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
    rows=cases();folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;folder.mkdir(parents=True,exist_ok=False)
    (folder/'cases.bin').write_bytes(full.legacy.encode(rows,1));save(folder/'cases.json',rows)
    runner=Original();checks=[]
    for c in rows:
        runner.mode=-1;runner.calls=[];runner.digit_calls=runner.point_calls=0
        try:full.legacy.Original.run(runner,c)
        except RuntimeError as error:
            require(c['short_size']>=0 and str(error).startswith('UNEXPECTED_NATIVE_ERROR ') and runner.error==0xd078e000001f6,'UNEXPECTED_NATIVE_FAILURE '+str(error))
        expected=0x1f6 if c['short_size']>=0 else 0x1f7
        require(runner.error and runner.error&0xffffffff==expected,'NATIVE_FATAL_CLASS_DIFFERS')
        native=dict(code=hex(runner.error),class_low32=expected)
        namespace=a.run+'-f'+str(c['id']);target=folder/('case-'+str(c['id']));target.mkdir()
        files=MT/'MQL5/Files/bot1-preparation'/namespace;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b1-prep-'+namespace+'.set');ini=MT/('b1-prep-'+namespace+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+namespace+'\nOnlyCase='+str(c['id'])+'\nForceShortArray='+str(c['short_size'])+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1PreparationCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        before=log_sizes();started=time.monotonic();proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        lines=added_lines(before);(target/'runtime-lines.txt').write_text('\n'.join(lines)+'\n',encoding='utf-8')
        require(code in [-1,0xffffffff] and not (files/'script-status.bin').exists(),'FATAL_CASE_RETURNED_NORMALLY')
        require(any('PREPARATION_CASE:'+str(c['id']) in line for line in lines),'CASE_MARKER_MISSING')
        require(any(c['fatal_class'] in line.lower() for line in lines),'FATAL_CLASS_NOT_OBSERVED')
        raw=(files/'mql5-results.bin').read_bytes();require(raw==struct.pack('<4i',full.MAGIC,1,1,len(full.FIELDS)),'FATAL_CASE_WROTE_RESULT')
        (target/'mql5-results.bin').write_bytes(raw)
        check=dict(case_id=c['id'],source_case_id=c['source_case_id'],short_size=c['short_size'],native=native,
          mql5_fatal_class=c['fatal_class'],exit_code=code,no_normal_result=True,partial_state_compared=False,
          seconds=round(time.monotonic()-started,2),runtime_lines_sha256=sha(target/'runtime-lines.txt'))
        save(target/'verification.json',check);checks.append(check);print(json.dumps(dict(checked=len(checks),of=len(rows),fatal_class=c['fatal_class'])),flush=True)
    save(folder/'error-comparison.json',dict(cases=len(checks),matched_fatal_class_and_no_normal_result=len(checks),checks=checks,
      identity=current,tool_sha256=sha(Path(__file__)),build_receipt_sha256=sha(receipt),whole_bot_complete=False,
      limits=['Fatal class and absence of a normal record only. Partial state and exact error source line/payload are not compared.']))
if __name__=='__main__':main()
