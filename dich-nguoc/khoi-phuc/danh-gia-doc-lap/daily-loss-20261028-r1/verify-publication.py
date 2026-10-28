"""Verify current/staged source, exact binaries, negative controls and scoped results."""
import argparse,hashlib,importlib.util,json,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];WORK=ROOT.parents[1]
s=importlib.util.spec_from_file_location('pub_daily',ROOT/'cong-cu/kiem-lo-ngay-bot-1-3.py');daily=importlib.util.module_from_spec(s);s.loader.exec_module(daily)
s=importlib.util.spec_from_file_location('pub_gate',ROOT/'cong-cu/kiem-cong-dieu-phoi-bot-1-3.py');gate=importlib.util.module_from_spec(s);s.loader.exec_module(gate)
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--ref',default='');p.add_argument('--output',type=Path);a=p.parse_args();checks=0;headers={};cases={};negative=0
    def indexed(path):return subprocess.check_output(['git','show',a.ref+':'+path.relative_to(WORK).as_posix()],cwd=WORK)
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5'
        for module_,label in [(daily,'daily-loss'),(gate,'dispatch-gate')]:
            folder=home/'bang-chung/kiem-quan-ly-vi-the'/f'b{bot}-{label}-20261028-r2';native=read(folder/'original-run.json');actual=read(folder/'mql5-run.json');report=read(folder/'comparison.json');current=module_.identity(bot)
            daily.require(all(native[k]==actual[k]==v for k,v in current.items()),'CURRENT_IDENTITY_CHANGED')
            daily.require(not report['whole_bot_complete'] and not report['whole_manager_complete'] and report['failed']==0 and report['matched']==report['cases']>0,'SCOPE_OR_RESULT')
            daily.require(native['result_sha256']==actual['result_sha256']==daily.sha(folder/'original-results.bin')==daily.sha(folder/'mql5-results.bin'),'RESULT_BYTES')
            daily.require(native['sdk_tape_sha256']==actual['sdk_tape_sha256']==daily.sha(folder/'sdk-tape.bin'),'TAPE_BYTES')
            build=read(home/'bang-chung/bien-dich'/actual['build']/'bien-nhan.json');daily.require(build['errors']==build['warnings']==0,'CHECK_BUILD')
            binary=home/'bang-chung/bien-dich'/actual['build']/Path(build['target']).with_suffix('.ex5').name;daily.require(daily.sha(binary)==build['binary_sha256'],'CHECK_BINARY')
            evidence=ROOT/f'danh-gia-doc-lap/{label}-20261028-r1';neg=read(evidence/f'bot{bot}-negative.json')
            daily.require(neg['tape_sha256']==daily.sha(folder/'sdk-tape.bin') and neg['tool_sha256']==daily.sha(evidence/'negative-control.py'),'NEGATIVE_IDENTITY')
            daily.require(neg[('daily' if label=='daily-loss' else 'gate')+'_tool_sha256']==daily.sha(Path(module_.__file__)) and len(neg['checks'])==2 and all(n['rejected'] for n in neg['checks']),'NEGATIVE_NOT_REJECTED');negative+=2
            raw=read(evidence/f'bot{bot}-native.json');daily.require(raw['disassembly_sha256']==daily.sha(evidence/f'bot{bot}-raw.txt'),'RAW_BYTES')
            cases[f'{bot}:{label}']=report['matched']
        receipt=home/'bang-chung/bien-dich'/f'b{bot}-all-headers-api-20261028-r5/bien-nhan.json';build=read(receipt);daily.require(build['errors']==build['warnings']==0,'ALL_HEADERS_BUILD')
        closure=daily.pub.closure(source/build['target'],source);expected_headers=set((source/f'Include/bot-cua-toi-{bot}').glob('*.mqh'));daily.require(expected_headers<closure,'HEADERS_OMITTED');headers[bot]=len(expected_headers)
        for path in closure:
            rel=path.relative_to(source).as_posix();current=path.read_bytes();daily.require(hashlib.sha256(current).hexdigest()==build['sources_sha256'][rel],'BUILD_SOURCE_BYTES')
            staged=indexed(path)
            if staged!=current:
                # Four unchanged historical headers use CRLF in this checkout, LF in Git.
                legacy={f'Bot{bot}{name}.mqh' for name in ['AccountInitialization','AccountStateVolume','AccountVolume','Withdrawal']}
                daily.require(path.name in legacy and staged==current.replace(b'\r\n',b'\n'),'INDEX_SOURCE_BYTES '+rel)
            checks+=1
        binary=receipt.parent/Path(build['target']).with_suffix('.ex5').name;daily.require(daily.sha(binary)==build['binary_sha256'],'ALL_HEADERS_BINARY')
    result=dict(ref=a.ref or 'index',exact_or_documented_newline_source_checks=checks,production_headers=headers,matched_cases=cases,negative_controls_rejected=negative,original_files_unchanged=2,whole_eas_complete=0,
                whole_dispatchers_complete=0,goal_complete=False,remaining=['complete initialization and events','remaining outer dispatcher and shared-state connections','original menu/panel images and resources','paired complete EA execution on identical MT5 data','remaining unverified branches and old NaN checks'])
    if a.output:daily.save(a.output,result)
    print(json.dumps(result))
if __name__=='__main__':main()
