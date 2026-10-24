"""Verify scoped order-scan sources,original/script/tester results and provenance.

Usage: kiem-chung-quet-lenh-bot-1-3.py NEW_JSON
No MT5 is started. NEW_JSON must be new and inside khoi-phuc.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('scan',Path(__file__).with_name('kiem-quet-lenh-bot-1-3.py'))
scan=importlib.util.module_from_spec(spec);spec.loader.exec_module(scan)
sha=scan.sha
def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('new_json',type=Path);a=parser.parse_args();target=a.new_json.resolve()
    require(target.is_relative_to(ROOT) and target.suffix=='.json' and target.parent.is_dir() and not target.exists(),'OUTPUT_MUST_BE_NEW_JSON_INSIDE_KHOI_PHUC')
    checks=[]
    for bot,n in [(1,307),(3,215)]:
        home=ROOT/f'bot-cua-toi-{bot}';folder=home/'bang-chung/kiem-quet-lenh/scan-20261024-r2';comparison=read(folder/'comparison.json');baseline=read(folder/'baseline.json');mql=read(folder/'mql5-run.json');native=read(folder/'original-run.json')
        require(comparison['matched']==comparison['cases']==n and comparison['failed']==0,'SCAN_COMPARISON_FAILED')
        require(scan.validation.original_hash(bot)==baseline['original_ex5_sha256'],'ORIGINAL_EX5_CHANGED')
        for name,digest in comparison['hashes'].items():require(sha(folder/name)==digest,'EVIDENCE_CHANGED '+name)
        require(scan.encode(scan.cases(bot))==(folder/'cases.bin').read_bytes() and baseline['cases_sha256']==sha(folder/'cases.bin'),'INPUT_GENERATOR_OR_BYTES_CHANGED')
        require(native['tool_sha256']==baseline['tool_sha256']==sha(Path(scan.__file__)) and native['dependencies_sha256']==scan.dependencies(bot),'NATIVE_DEPENDENCIES_CHANGED')
        require(native['result_sha256']==sha(folder/'original-results.bin'),'NATIVE_RESULT_CHANGED')
        receipt_path=ROOT/mql['build_receipt'];receipt=read(receipt_path)
        require(receipt['errors']==receipt['warnings']==0 and sha(receipt_path)==mql['build_receipt_sha256'],'SCRIPT_BUILD_CHANGED')
        require(receipt['binary_sha256']==mql['script_sha256']==sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name),'SCRIPT_BINARY_CHANGED')
        for name,digest in mql['sources_sha256'].items():require(digest==receipt['sources_sha256'][name]==sha(home/'source/MQL5'/name),'CURRENT_SOURCE_CHANGED '+name)
        for name,digest in mql['hashes'].items():require(sha(folder/name)==digest,'MQL_EVIDENCE_CHANGED')
        engine=ROOT/f'doi-chung-mt5/quet-lenh-20261024/engine-scan-b{bot}-r2';build=read(engine/'build.json');ec=read(engine/'comparison.json');job=read(engine/'jobs.json')[0];run=[json.loads(line) for line in (engine/'runner/ket-qua-chay.jsonl').read_text().splitlines()][-1]
        require(ec['matched']==ec['cases']==n and ec['failed']==0 and build['errors']==build['warnings']==0,'TESTER_BUILD_OR_COMPARISON_FAILED')
        require(build['component_build_receipt_sha256']==sha(receipt_path) and build['tool_sha256']==sha(Path(__file__).with_name('kiem-hang-doi-trong-may-thu.py')),'TESTER_PROVENANCE_CHANGED')
        require(build['tester_sha256']=='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb' and build['test_input_sha256']==sha(folder/'cases.bin'),'TESTER_ENGINE_OR_INPUT_CHANGED')
        for name,digest in mql['sources_sha256'].items():require(build['component_sources_sha256'][name]==digest,'TESTER_SOURCE_CHANGED')
        require(sha(engine/'OrderScanEngineCheck.mq5')==build['source_sha256'] and sha(engine/'OrderScanEngineCheck.ex5')==build['binary_sha256']==run['expert_sha256'],'TESTER_WRAPPER_OR_BINARY_CHANGED')
        require(run['demo_confirmed'] and run['login_confirmed'] and run['report_created'] and not run['exit_code'],'TESTER_RUN_NOT_VERIFIED')
        require('ORDERSCAN_NATIVE_CHECK_EXIT:0' in (engine/'runner'/(job['id']+'.log')).read_text(),'TESTER_DID_NOT_COMPLETE')
        require(struct.unpack('<2i',(engine/'script-status.bin').read_bytes())==(0,n),'TESTER_STATUS_DIFFERS')
        raw=(folder/'original-results.bin').read_bytes();require(raw==(folder/'mql5-results.bin').read_bytes()==(engine/'mql5-results.bin').read_bytes(),'SCRIPT_NATIVE_TESTER_BYTES_DIFFER')
        require(len(scan.read_results(engine/'mql5-results.bin',n))==n,'TESTER_RECORDS_DIFFER')
        checks.append(dict(bot=bot,cases=n,groups=comparison['groups'],comparison_sha256=sha(folder/'comparison.json'),tester_comparison_sha256=sha(engine/'comparison.json'),sources_sha256=mql['sources_sha256'],dependencies_sha256=native['dependencies_sha256'],result_sha256=sha(engine/'mql5-results.bin')))
    report=dict(status='five-scoped-functions-verified-with-stated-limits',checks=checks,tool_sha256=sha(Path(__file__)),whole_bot_complete=False,
                limits=['Terminal queries and selection are supplied models; actual account selection on failed reads is not separately measured.',
                        'Input arrays/strings are bounded by the checker; finite cases do not prove whole-bot completion.',
                        'No full EA,all settings,display,restart,broker or allocation-failure proof.'])
    scan.save(target,report);print(json.dumps(dict(bots=2,bot1_cases=307,bot3_cases=215,whole_bot_complete=False)))

if __name__=='__main__':main()
