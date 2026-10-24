"""Verify the saved full pending-order pipeline evidence and current sources.

Usage: kiem-chung-chuoi-dat-lenh-bot-1-3.py NEW_JSON
No MT5 or orders. Checks the script, original code and tester artifacts from
pipeline-20261024-r3 / engine-bN-r5, including input-bound supplied API values.
"""
import argparse
import copy
import importlib.util
import json
from pathlib import Path
import struct
from types import SimpleNamespace

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('pipeline',Path(__file__).with_name('kiem-chuoi-dat-lenh-bot-1-3.py'))
pipeline=importlib.util.module_from_spec(spec);spec.loader.exec_module(pipeline)
sha=pipeline.sha

def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)
def verify_hashes(folder,hashes):
    for name,digest in hashes.items():require(sha(folder/name)==digest,'EVIDENCE_CHANGED '+str(folder/name))

def rejection_checks(row,records):
    """Prove environment corruption is rejected even if both sides saw it."""
    tested=[]
    for label,api,index in [('send-mode',1,0),('send-reply',1,1),('reference-property-value',2,2),('reference-property-status',2,3),('direct-property-value',9,2)]:
        match=next((i for i,(kind,value) in enumerate(records) if kind==api),None)
        if match is None:continue
        changed=copy.deepcopy(records);values=list(changed[match][1]);values[index]+=1;changed[match]=(api,tuple(values))
        try:pipeline.validate_fixture_inputs(row,changed)
        except ValueError:tested.append(label)
        else:raise ValueError('CORRUPTED_INPUT_WAS_ACCEPTED '+label)
    match=next((i for i,(kind,value) in enumerate(records) if kind==1),None)
    if match is not None:
        changed=copy.deepcopy(records);values=list(changed[match][1]);result=bytearray(values[4]);result[0]^=1;values[4]=bytes(result);changed[match]=(1,tuple(values))
        try:pipeline.validate_fixture_inputs(row,changed)
        except ValueError:tested.append('send-result')
        else:raise ValueError('CORRUPTED_SEND_RESULT_WAS_ACCEPTED')
    return tested

def message_arity_checks():
    # Exercise the actual call dispatcher with a corrupt Print boundary. These
    # synthetic boundary checks are separate from the full native comparisons.
    x=SimpleNamespace(UC_X86_REG_RSP='sp',UC_X86_REG_RDX='op',UC_X86_REG_R8='argc',UC_X86_REG_R9='tag')
    class Boundary:
        def __init__(self,count):self.count=count
        def reg_read(self,reg):return {'sp':0x1000,'op':2,'argc':self.count,'tag':0x590008}[reg]
        def mem_read(self,address,size):return struct.pack('<I',0x590008) if size==4 else struct.pack('<Q',(address-0x1000-40)//16)
    results=[]
    for count in [0,1,2,3]:
        model=SimpleNamespace(apis={0:45},x=x,builder_frame=True,text=lambda pointer:['a','b','c'][pointer],next=lambda api:('a','b'))
        try:pipeline.Original.call(model,Boundary(count),0,0,None);accepted=True
        except ValueError as error:
            require(str(error)=='PREPARATION_MESSAGE_ARGUMENTS_DIFFER','UNEXPECTED_ARITY_FAILURE '+str(error));accepted=False
        require(accepted==(count==2),'PRINT_ARITY_GATE_FAILED '+str(count));results.append(dict(native_count=count,fixture_count=2,accepted=accepted))
    return results

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('new_json',type=Path);a=ap.parse_args();target=a.new_json.resolve()
    require(target.is_relative_to(ROOT) and target.suffix=='.json' and target.parent.is_dir() and not target.exists(),'OUTPUT_MUST_BE_NEW_JSON_INSIDE_KHOI_PHUC')
    checks=[]
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';folder=home/'bang-chung/kiem-chuoi-dat-lenh/pipeline-20261024-r3'
        baseline=read(folder/'baseline.json');comparison=read(folder/'comparison.json');mql=read(folder/'mql5-run.json');native=read(folder/'original-run.json')
        require(pipeline.pending.fill.validation.original_hash(bot)==baseline['original_ex5_sha256'],'ORIGINAL_EX5_CHANGED')
        require(comparison['cases']==comparison['matched']==818 and comparison['failed']==0,'PIPELINE_COMPARISON_FAILED')
        verify_hashes(folder,comparison['hashes']);verify_hashes(folder,mql['hashes'])
        require(sha(folder/'cases.bin')==baseline['cases_sha256'] and baseline['tool_sha256']==native['tool_sha256'] and pipeline.encode(pipeline.cases())==(folder/'cases.bin').read_bytes(),'PREPARATION_EVIDENCE_CHANGED')
        require(native['dependencies_sha256']==pipeline.dependencies(bot) and native['tool_sha256']==sha(Path(pipeline.__file__)),'ORIGINAL_DEPENDENCIES_CHANGED')
        require(sha(folder/'original-results.bin')==native['result_sha256'] and sha(folder/'api-fixtures.bin')==native['fixtures_sha256'],'ORIGINAL_RESULTS_CHANGED')
        receipt_path=ROOT/mql['build_receipt'];receipt=read(receipt_path)
        require(sha(receipt_path)==mql['build_receipt_sha256'] and receipt['errors']==receipt['warnings']==0,'SCRIPT_BUILD_CHANGED')
        require(receipt['binary_sha256']==mql['script_sha256']==sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name),'SCRIPT_BINARY_CHANGED')
        for name,digest in mql['sources_sha256'].items():require(digest==receipt['sources_sha256'][name]==sha(home/'source/MQL5'/name),'CURRENT_SOURCE_CHANGED '+name)
        rows=pipeline.read_cases(folder/'cases.bin');records,chart,digits=pipeline.fixtures(folder/'api-fixtures.bin',len(rows))
        for row in rows:pipeline.validate_fixture_inputs(row,records[row['id']])
        require(native['fixture_input_contract_checked_cases']==comparison['fixture_input_contract_checked_cases']==len(rows),'INPUT_CONTRACT_NOT_CHECKED')
        rejected=set()
        for row in rows:
            rejected.update(rejection_checks(row,records[row['id']]))
            if len(rejected)==6:break
        require(len(rejected)==6,'REJECTION_CHECK_TYPES_MISSING')
        engine=ROOT/f'doi-chung-mt5/chuoi-dat-lenh-20261024/engine-b{bot}-r5';ec=read(engine/'comparison.json');build=read(engine/'build.json');job=read(engine/'jobs.json')[0]
        runner=[json.loads(line) for line in (engine/'runner/ket-qua-chay.jsonl').read_text().splitlines()][-1]
        require(ec['cases']==ec['matched']==818 and ec['failed']==0 and build['errors']==build['warnings']==0,'TESTER_COMPARISON_OR_BUILD_FAILED')
        require(build['component_build_receipt_sha256']==sha(receipt_path) and build['tool_sha256']==sha(folder/'tested-sources/tester-check-tool.py'),'TESTER_BUILD_PROVENANCE_CHANGED')
        for name,digest in mql['sources_sha256'].items():require(build['component_sources_sha256'][name]==digest,'TESTER_COMPONENT_SOURCE_CHANGED')
        require(sha(engine/'PipelineEngineCheck.mq5')==build['source_sha256'] and sha(engine/f'Bot{bot}PipelineApi.mqh')==build['adapted_api_include_sha256'],'TESTER_WRAPPER_CHANGED')
        require(sha(engine/'PipelineEngineCheck.ex5')==build['binary_sha256']==runner['expert_sha256'],'TESTER_BINARY_CHANGED')
        require(runner['demo_confirmed'] and runner['login_confirmed'] and runner['report_created'] and not runner['exit_code'],'TESTER_RUN_NOT_VERIFIED')
        require('PIPELINE_NATIVE_CHECK_EXIT:0' in (engine/'runner'/(job['id']+'.log')).read_text(),'TESTER_SCRIPT_DID_NOT_COMPLETE')
        require(struct.unpack('<2i',(engine/'script-status.bin').read_bytes())==(0,len(rows)),'TESTER_STATUS_DIFFERS')
        require((folder/'api-fixtures.bin').read_bytes()==(engine/'api-fixtures.bin').read_bytes(),'TESTER_API_FIXTURES_DIFFER')
        original=(folder/'original-results.bin').read_bytes()
        require(original==(folder/'mql5-results.bin').read_bytes()==(engine/'mql5-results.bin').read_bytes(),'PIPELINE_RESULT_BYTES_DIFFER')
        require(len(pipeline.read_results(engine/'mql5-results.bin',len(rows)))==len(rows),'TESTER_RECORD_COUNT_DIFFERS')
        checks.append(dict(bot=bot,cases=818,comparison_sha256=sha(folder/'comparison.json'),tester_comparison_sha256=sha(engine/'comparison.json'),sources_sha256=mql['sources_sha256'],original_dependencies_sha256=native['dependencies_sha256'],fixture_input_contract_checked_cases=818,rejected_corrupt_input_types=sorted(rejected),result_sha256=sha(engine/'mql5-results.bin')))
    arity=message_arity_checks()
    report=dict(status='pipeline-verified-with-stated-limits',checks=checks,message_arity_checks=arity,verification_tool_sha256=sha(Path(__file__)),whole_bot_complete=False,
                limits=['Terminal properties/send outcomes/errors are supplied; formatting is measured in MT5.',
                        'No actual broker,full EA,all settings,display,restart or allocation/CPU-fault proof.',
                        '818 finite cases per bot are not a percentage of whole-bot completion.'])
    pipeline.save(target,report);print(json.dumps(dict(bots=len(checks),cases_each=818,rejected_corrupt_input_types_each=6,whole_bot_complete=False)))

if __name__=='__main__':main()
