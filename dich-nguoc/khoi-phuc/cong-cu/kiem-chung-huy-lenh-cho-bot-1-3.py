"""Verify saved cancel evidence, current sources and deliberately corrupt inputs.

Usage: kiem-chung-huy-lenh-cho-bot-1-3.py NEW_JSON
No MT5 is started. NEW_JSON must be new and inside khoi-phuc.
"""
import argparse
import copy
import importlib.util
import json
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('cancel',Path(__file__).with_name('kiem-huy-lenh-cho-bot-1-3.py'))
cancel=importlib.util.module_from_spec(spec);spec.loader.exec_module(cancel)
sha=cancel.sha

def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)

def rejection_checks(rows,records):
    tested=set()
    for row in rows:
        for i,(api,value) in enumerate(records[row['id']]):
            changes=[]
            if 10<=api<=16:
                values=list(value)
                if api==11:values[-1]+='!'
                else:values[-1]^=1
                changes.append((f'guard-{api}',tuple(values)))
            elif api==1:
                for index,label in [(0,'send-mode'),(1,'send-reply')]:
                    values=list(value);values[index]^=1;changes.append((label,tuple(values)))
                values=list(value);result=bytearray(values[4]);result[0]^=1;values[4]=bytes(result)
                changes.append(('send-result',tuple(values)))
            elif api==2:
                for index,label in [(2,'format-value'),(3,'format-status')]:
                    values=list(value);values[index]^=1;changes.append((label,tuple(values)))
            for label,changed in changes:
                if label in tested:continue
                bad=copy.deepcopy(records[row['id']]);bad[i]=(api,changed)
                try:cancel.validate_inputs(row,bad)
                except ValueError:tested.add(label)
                else:raise ValueError('CORRUPTED_INPUT_WAS_ACCEPTED '+label)
        if len(tested)==12:break
    require(len(tested)==12,'REJECTION_CHECK_TYPES_MISSING')
    return sorted(tested)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('new_json',type=Path);a=parser.parse_args();target=a.new_json.resolve()
    require(target.is_relative_to(ROOT) and target.suffix=='.json' and target.parent.is_dir() and not target.exists(),'OUTPUT_MUST_BE_NEW_JSON_INSIDE_KHOI_PHUC')
    checks=[]
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';folder=home/'bang-chung/kiem-huy-lenh-cho/cancel-20261024-r2'
        baseline=read(folder/'baseline.json');comparison=read(folder/'comparison.json');mql=read(folder/'mql5-run.json');native=read(folder/'original-run.json')
        require(cancel.pending.fill.validation.original_hash(bot)==baseline['original_ex5_sha256'],'ORIGINAL_EX5_CHANGED')
        require(comparison['cases']==comparison['matched']==964 and comparison['failed']==0,'CANCEL_COMPARISON_FAILED')
        for hashes in [comparison['hashes'],mql['hashes']]:
            for name,digest in hashes.items():require(sha(folder/name)==digest,'EVIDENCE_CHANGED '+name)
        require(cancel.encode(cancel.cases())==(folder/'cases.bin').read_bytes() and baseline['cases_sha256']==sha(folder/'cases.bin'),'INPUT_GENERATOR_OR_BYTES_CHANGED')
        require(baseline['tool_sha256']==native['tool_sha256']==sha(Path(cancel.__file__))==sha(folder/'tested-sources/native-check-tool.py'),'NATIVE_TOOL_CHANGED')
        require(native['dependencies_sha256']==cancel.dependencies(bot),'NATIVE_DEPENDENCIES_CHANGED')
        require(native['result_sha256']==sha(folder/'original-results.bin') and native['fixture_sha256']==sha(folder/'api-fixtures.bin'),'NATIVE_RESULT_CHANGED')
        receipt_path=ROOT/mql['build_receipt'];receipt=read(receipt_path)
        require(receipt['errors']==receipt['warnings']==0 and sha(receipt_path)==mql['build_receipt_sha256'],'SCRIPT_BUILD_CHANGED')
        require(receipt['binary_sha256']==mql['script_sha256']==sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name),'SCRIPT_BINARY_CHANGED')
        for name,digest in mql['sources_sha256'].items():
            require(digest==receipt['sources_sha256'][name]==sha(home/'source/MQL5'/name)==sha(folder/'tested-sources'/Path(name).name),'CURRENT_OR_TESTED_SOURCE_CHANGED '+name)
        rows=cancel.read_cases(folder/'cases.bin');records,chart,digits=cancel.fixtures(folder/'api-fixtures.bin',len(rows))
        for row in rows:cancel.validate_inputs(row,records[row['id']])
        require(len(rows)==native['input_contract_checked_cases']==964,'INPUT_CONTRACT_NOT_CHECKED')
        rejected=rejection_checks(rows,records)
        engine=ROOT/f'doi-chung-mt5/huy-lenh-cho-20261024/engine-cancel-b{bot}-r2'
        build=read(engine/'build.json');ec=read(engine/'comparison.json');job=read(engine/'jobs.json')[0]
        runner=[json.loads(line) for line in (engine/'runner/ket-qua-chay.jsonl').read_text().splitlines()][-1]
        require(ec['cases']==ec['matched']==964 and ec['failed']==0 and build['errors']==build['warnings']==0,'TESTER_COMPARISON_OR_BUILD_FAILED')
        require(build['component_build_receipt_sha256']==sha(receipt_path) and build['tool_sha256']==sha(folder/'tested-sources/tester-check-tool.py'),'TESTER_PROVENANCE_CHANGED')
        require(build['tester_sha256']=='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb' and build['test_input_sha256']==sha(folder/'cases.bin'),'TESTER_ENGINE_OR_INPUT_CHANGED')
        for name,digest in mql['sources_sha256'].items():require(build['component_sources_sha256'][name]==digest,'TESTER_COMPONENT_SOURCE_CHANGED')
        require(sha(engine/'OrderCancelEngineCheck.mq5')==build['source_sha256'] and sha(engine/f'Bot{bot}PipelineApi.mqh')==build['adapted_api_include_sha256'],'TESTER_WRAPPER_CHANGED')
        require(sha(engine/'OrderCancelEngineCheck.ex5')==build['binary_sha256']==runner['expert_sha256'],'TESTER_BINARY_CHANGED')
        require(runner['demo_confirmed'] and runner['login_confirmed'] and runner['report_created'] and not runner['exit_code'],'TESTER_RUN_NOT_VERIFIED')
        require('ORDERCANCEL_NATIVE_CHECK_EXIT:0' in (engine/'runner'/(job['id']+'.log')).read_text(),'TESTER_DID_NOT_COMPLETE')
        for directory in [folder,engine]:require(struct.unpack('<2i',(directory/'script-status.bin').read_bytes())==(0,964),'SCRIPT_STATUS_DIFFERS')
        require((folder/'api-fixtures.bin').read_bytes()==(engine/'api-fixtures.bin').read_bytes(),'TESTER_FIXTURES_DIFFER')
        original=(folder/'original-results.bin').read_bytes()
        require(original==(folder/'mql5-results.bin').read_bytes()==(engine/'mql5-results.bin').read_bytes(),'SCRIPT_NATIVE_TESTER_BYTES_DIFFER')
        require(len(cancel.read_results(engine/'mql5-results.bin',964))==964,'TESTER_RECORDS_DIFFER')
        checks.append(dict(bot=bot,cases=964,rejected_corrupt_input_types=rejected,comparison_sha256=sha(folder/'comparison.json'),tester_comparison_sha256=sha(engine/'comparison.json'),sources_sha256=mql['sources_sha256'],dependencies_sha256=native['dependencies_sha256'],result_sha256=sha(engine/'mql5-results.bin')))
    report=dict(status='two-cancel-functions-verified-with-stated-limits',checks=checks,tool_sha256=sha(Path(__file__)),whole_bot_complete=False,
                limits=['35 public fields and four full strings compared; private MQL padding bytes are not compared.',
                        'Terminal queries and send replies are supplied and input-bound; formatting is measured in MT5.',
                        'No full EA,selector callers,all settings,display,restart,broker or allocation-failure proof.',
                        '964 finite cases per bot are not a percentage of whole-bot completion.'])
    cancel.save(target,report);print(json.dumps(dict(bots=2,cases_each=964,rejected_corrupt_input_types_each=12,whole_bot_complete=False)))

if __name__=='__main__':main()
