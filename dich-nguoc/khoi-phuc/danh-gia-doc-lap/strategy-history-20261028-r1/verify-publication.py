"""Verify staged/committed history source integration and replay recorded fatal prefixes."""
import argparse,ast,importlib.util,json,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];WORK=ROOT.parents[1];FOLDER=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('history_fault',ROOT/'cong-cu/kiem-loi-lich-su-chien-luoc-bot-1-3.py')
fault=importlib.util.module_from_spec(s);s.loader.exec_module(fault)
h=fault.h;require=h.require;sha=h.sha
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--ref',default='');a=p.parse_args();results=[]
    for path in [ROOT/'cong-cu/kiem-lich-su-chien-luoc-bot-1-3.py',ROOT/'cong-cu/kiem-loi-lich-su-chien-luoc-bot-1-3.py',FOLDER/'nan-add-cpu-probe.py',FOLDER/'negative-control.py',Path(__file__)]:ast.parse(path.read_text(encoding='utf-8'),filename=str(path))
    require((FOLDER/'nan-add-cpu-probe.json').read_bytes()==(FOLDER/'nan-add-cpu-probe-r2.json').read_bytes(),'CPU_PROBE_NOT_REPRODUCED')
    for bot,nheaders in [(1,88),(3,95)]:
        home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';build=read(home/f'bang-chung/bien-dich/b{bot}-all-headers-api-20261028-r4/bien-nhan.json')
        require(build['errors']==build['warnings']==0,'ALL_HEADERS_NOT_CLEAN')
        closure=h.pub.closure(source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}AllHeadersAPICompile.mq5',source)
        require(len(closure)==nheaders+1 and len(list((source/f'Include/bot-cua-toi-{bot}').glob('*.mqh')))==nheaders,'MISSING_HEADER')
        exact=0;newline=[]
        for path in closure:
            n=path.relative_to(source).as_posix();require(sha(path)==build['sources_sha256'][n],'BUILD_SOURCE_CHANGED')
            relative=path.relative_to(WORK).as_posix();stored=subprocess.check_output(['git','show',a.ref+':'+relative],cwd=WORK);raw=path.read_bytes()
            if stored==raw:exact+=1
            else:
                require(path.name in [f'Bot{bot}AccountInitialization.mqh',f'Bot{bot}AccountStateVolume.mqh',f'Bot{bot}AccountVolume.mqh',f'Bot{bot}Withdrawal.mqh'] and stored.replace(b'\r\n',b'\n')==raw.replace(b'\r\n',b'\n'),'GIT_CODE_DIFFERS '+relative);newline.append(relative)
        folder=home/f'bang-chung/kiem-quan-ly-vi-the/b{bot}-strategy-history-fault-20261028-r2';report=read(folder/'fault-comparison.json')
        require(report['cases']==report['matched']==4 and report['failed']==0 and not report['full_ea'],'FAULT_SCOPE')
        require(report['shared_identity']==h.identity(bot) and report['tool_sha256']==sha(ROOT/'cong-cu/kiem-loi-lich-su-chien-luoc-bot-1-3.py'),'FAULT_HELPERS_CHANGED')
        for n,digest in report['sources_sha256'].items():require(sha(source/n)==digest,'FAULT_SOURCE_CHANGED')
        for kind,r in enumerate(report['results']):
            current=folder/f'kind-{kind}';require(sha(current/'events.bin')==r['prefix_sha256'] and sha(current/'last-state.bin')==r['last_state_sha256'],'FAULT_DATA_CHANGED')
            require('array out of range' in r['mql5_error'] and r['mt5_exit_code']==4294967295,'WRONG_FAULT_CLASS')
            o=fault.FaultNative(bot)
            try:checked=o.check(fault.case(bot,kind),(current/'events.bin').read_bytes(),(current/'last-state.bin').read_bytes(),fault.FAULTS[bot][kind])
            finally:o.close()
            require(checked['state_sha256']==r['state_sha256'] and checked['native_fault']==r['native_fault'],'FAULT_RECHECK_DIFFERS')
        negative=read(FOLDER/f'bot{bot}-negative.json');require(negative['rejected'] and negative['old_mql5_return']!=negative['original_return_with_host_addsd'],'NEGATIVE_NOT_REJECTED')
        results.append(dict(bot=bot,headers=nheaders,errors=0,warnings=0,exact_files=exact,newline_only_equivalent_files=sorted(newline),normal_cases=270,fatal_prefixes=4,negative_control_rejected=True))
    print(json.dumps(dict(ref=a.ref or 'index',results=results,host_calibration_cases=100,full_eas_complete=0)))
if __name__=='__main__':main()
