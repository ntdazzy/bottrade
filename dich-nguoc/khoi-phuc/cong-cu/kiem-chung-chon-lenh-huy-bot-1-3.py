"""Verify saved selection evidence, current sources and deliberately corrupt inputs.

Usage: kiem-chung-chon-lenh-huy-bot-1-3.py NEW_JSON
No MT5 is started. NEW_JSON must be new and inside khoi-phuc.
"""
import argparse
import copy
import importlib.util
import json
from pathlib import Path
import struct
from types import SimpleNamespace

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('selection',Path(__file__).with_name('kiem-chon-lenh-huy-bot-1-3.py'))
selection=importlib.util.module_from_spec(spec);spec.loader.exec_module(selection)
sha=selection.sha

def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)

def rejection_checks(rows,records):
    expected={*[f'guard-{i}' for i in range(10,17)],'send-mode','send-reply','send-result','format-value','format-status',
              'total','ticket-index','ticket-value','selected-order','order-integer','order-symbol-null','order-symbol-text',
              'price-read-index','price-value','selector-message','cast-metadata','selection-ticket'}
    tested=set()
    for row in rows:
        for i,(api,value) in enumerate(records[row['id']]):
            changes=[]
            def change(label,index,mutation):
                values=list(value);values[index]=mutation(values[index]);changes.append((label,tuple(values)))
            if 10<=api<=16:
                change(f'guard-{api}',-1,(lambda v:v+'!') if api==11 else (lambda v:v^1))
                if api==10:change('selection-ticket',0,lambda v:0)
            elif api==1:
                change('send-mode',0,lambda v:v^1);change('send-reply',1,lambda v:v^1)
                change('send-result',4,lambda v:bytes([v[0]^1])+v[1:])
            elif api==2:
                change('format-value',2,lambda v:v^1);change('format-status',3,lambda v:v^1)
            elif api==17:change('cast-metadata',0,lambda v:v+'!')
            elif api==20:change('total',0,lambda v:v^1)
            elif api==21:
                for index,label in enumerate(['ticket-index','ticket-value','selected-order']):change(label,index,lambda v:v^1)
            elif api==22:change('order-integer',1,lambda v:v^1)
            elif api==23:
                change('order-symbol-null',1,lambda v:v^1);change('order-symbol-text',2,lambda v:v+'!')
            elif api==24:
                change('price-read-index',1,lambda v:v^1);change('price-value',2,lambda v:v^1)
            elif api==25:change('selector-message',0,lambda v:v+'!')
            for label,changed in changes:
                if label in tested:continue
                bad=copy.deepcopy(records[row['id']]);bad[i]=(api,changed)
                try:selection.validate_inputs(row,bad)
                except ValueError:tested.add(label)
                else:raise ValueError('CORRUPTED_INPUT_WAS_ACCEPTED '+label)
        if tested==expected:break
    require(tested==expected,'REJECTION_CHECK_TYPES_MISSING '+str(expected-tested))
    return sorted(tested)

def message_arity_checks():
    x=SimpleNamespace(UC_X86_REG_RSP='sp',UC_X86_REG_RDX='op',UC_X86_REG_R8='argc',UC_X86_REG_R9='tag')
    class Boundary:
        def __init__(self,count):self.count=count
        def reg_read(self,reg):return {'sp':0x1000,'op':2,'argc':self.count,'tag':0x590008}[reg]
        def mem_read(self,address,size):return b'\0'*size
    results=[]
    for count in [0,1,2]:
        model=SimpleNamespace(apis={0:45},x=x,next=lambda api:(selection.MESSAGES[0],),text=lambda pointer:selection.MESSAGES[0],selector_prints=0,selector_hash=0)
        try:selection.Original.call(model,Boundary(count),0,0,None);accepted=True
        except ValueError as error:
            require(str(error)=='SELECTOR_PRINT_SHAPE_DIFFERS','UNEXPECTED_ARITY_FAILURE');accepted=False
        require(accepted==(count==1),'PRINT_ARITY_GATE_FAILED');results.append(dict(native_count=count,fixture_count=1,accepted=accepted))
    return results

def fixture_length_checks(folder,n):
    raw=(folder/'api-fixtures.bin').read_bytes();checks=[]
    for removed in [1,2,4]:
        try:selection.fixtures(SimpleNamespace(read_bytes=lambda:raw[:-removed]),n)
        except (ValueError,struct.error,UnicodeError):checks.append(dict(removed_tail_bytes=removed,rejected=True))
        else:raise ValueError('TRUNCATED_FIXTURE_WAS_ACCEPTED')
    return checks

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('new_json',type=Path);a=parser.parse_args();target=a.new_json.resolve()
    require(target.is_relative_to(ROOT) and target.suffix=='.json' and target.parent.is_dir() and not target.exists(),'OUTPUT_MUST_BE_NEW_JSON_INSIDE_KHOI_PHUC')
    checks=[]
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';folder=home/'bang-chung/kiem-chon-lenh-huy/selection-20261024-r2'
        baseline=read(folder/'baseline.json');comparison=read(folder/'comparison.json');mql=read(folder/'mql5-run.json');native=read(folder/'original-run.json')
        require(selection.pending.fill.validation.original_hash(bot)==baseline['original_ex5_sha256'],'ORIGINAL_EX5_CHANGED')
        require(comparison['cases']==comparison['matched']==2522 and comparison['failed']==0,'CANCEL_COMPARISON_FAILED')
        for hashes in [comparison['hashes'],mql['hashes']]:
            for name,digest in hashes.items():require(sha(folder/name)==digest,'EVIDENCE_CHANGED '+name)
        require(selection.encode(selection.cases())==(folder/'cases.bin').read_bytes() and baseline['cases_sha256']==sha(folder/'cases.bin'),'INPUT_GENERATOR_OR_BYTES_CHANGED')
        require(baseline['tool_sha256']==mql['tool_sha256']==native['tool_sha256']==sha(Path(selection.__file__))==sha(folder/'tested-sources/native-check-tool.py'),'NATIVE_TOOL_CHANGED')
        require(native['dependencies_sha256']==selection.dependencies(bot),'NATIVE_DEPENDENCIES_CHANGED')
        require(native['result_sha256']==sha(folder/'original-results.bin') and native['fixture_sha256']==sha(folder/'api-fixtures.bin'),'NATIVE_RESULT_CHANGED')
        receipt_path=ROOT/mql['build_receipt'];receipt=read(receipt_path)
        require(receipt['errors']==receipt['warnings']==0 and sha(receipt_path)==mql['build_receipt_sha256'],'SCRIPT_BUILD_CHANGED')
        require(receipt['binary_sha256']==mql['script_sha256']==sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name),'SCRIPT_BINARY_CHANGED')
        for name,digest in mql['sources_sha256'].items():
            require(digest==receipt['sources_sha256'][name]==sha(home/'source/MQL5'/name)==sha(folder/'tested-sources'/Path(name).name),'CURRENT_OR_TESTED_SOURCE_CHANGED '+name)
        expected_sources={f'Scripts/bot-cua-toi-{bot}/Bot{bot}PendingSelectionCheck.mq5',f'Scripts/bot-cua-toi-{bot}/Bot{bot}PipelineApi.mqh',
                          *[f'Include/bot-cua-toi-{bot}/Bot{bot}{name}.mqh' for name in ['PendingSelection','OrderCancel','TradeSend','TradeMessages','PendingRequest','Filling']]}
        require(set(mql['sources_sha256'])==expected_sources,'COMPILED_SOURCE_SET_DIFFERS')
        rows=selection.read_cases(folder/'cases.bin');records,chart,digits=selection.fixtures(folder/'api-fixtures.bin',len(rows))
        for row in rows:selection.validate_inputs(row,records[row['id']])
        require(len(rows)==native['input_contract_checked_cases']==2522,'INPUT_CONTRACT_NOT_CHECKED')
        rejected=rejection_checks(rows,records)
        engine=ROOT/f'doi-chung-mt5/chon-lenh-huy-20261024/engine-selection-b{bot}-r2'
        build=read(engine/'build.json');ec=read(engine/'comparison.json');job=read(engine/'jobs.json')[0]
        runner=[json.loads(line) for line in (engine/'runner/ket-qua-chay.jsonl').read_text().splitlines()][-1]
        require(ec['cases']==ec['matched']==2522 and ec['failed']==0 and build['errors']==build['warnings']==0,'TESTER_COMPARISON_OR_BUILD_FAILED')
        require(build['component_build_receipt_sha256']==sha(receipt_path) and build['tool_sha256']==sha(folder/'tested-sources/tester-check-tool.py'),'TESTER_PROVENANCE_CHANGED')
        require(build['tester_sha256']=='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb' and build['test_input_sha256']==sha(folder/'cases.bin'),'TESTER_ENGINE_OR_INPUT_CHANGED')
        for name,digest in mql['sources_sha256'].items():require(build['component_sources_sha256'][name]==digest,'TESTER_COMPONENT_SOURCE_CHANGED')
        require(sha(engine/'PendingSelectionEngineCheck.mq5')==build['source_sha256'] and sha(engine/f'Bot{bot}PipelineApi.mqh')==build['adapted_api_include_sha256'],'TESTER_WRAPPER_CHANGED')
        filename=f'b{bot}-pendingselection-{engine.name}.bin';source=(home/f'source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}PendingSelectionCheck.mq5').read_text(encoding='utf-8-sig')
        for old,new in [('#property script_show_inputs\n',''),('int OnStart()','int RunQueueCheck()'),('FileOpen(folder+"cases.bin",','FileOpen("'+filename+'",')]:
            require(source.count(old)==1,'WRAPPER_SOURCE_SHAPE_DIFFERS');source=source.replace(old,new)
        source='#property strict\n#property tester_file "'+filename+'"\n'+source
        source+='\nint OnInit()\n{\n   int result=RunQueueCheck();\n   Print("PENDINGSELECTION_NATIVE_CHECK_EXIT:",result);\n   return result==0 ? INIT_SUCCEEDED : INIT_FAILED;\n}\nvoid OnTick() { ExpertRemove(); }\n'
        require(source==(engine/'PendingSelectionEngineCheck.mq5').read_text(encoding='utf-8'),'WRAPPER_IS_NOT_EXPECTED_CHECK_BODY')
        facade=(home/f'source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}PipelineApi.mqh').read_text(encoding='utf-8-sig')
        facade=facade.replace(f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}TradeSend.mqh"',f'#include <bot-cua-toi-{bot}/Bot{bot}TradeSend.mqh>')
        require(facade==(engine/f'Bot{bot}PipelineApi.mqh').read_text(encoding='utf-8'),'ADAPTED_INCLUDE_IS_NOT_EXPECTED_SOURCE')
        require(job['inputs']['CheckRun']==engine.name,'TESTER_OUTPUT_NAMESPACE_NOT_UNIQUE')
        require(sha(engine/'PendingSelectionEngineCheck.ex5')==build['binary_sha256']==runner['expert_sha256'],'TESTER_BINARY_CHANGED')
        require(runner['demo_confirmed'] and runner['login_confirmed'] and runner['report_created'] and not runner['exit_code'],'TESTER_RUN_NOT_VERIFIED')
        require('PENDINGSELECTION_NATIVE_CHECK_EXIT:0' in (engine/'runner'/(job['id']+'.log')).read_text(),'TESTER_DID_NOT_COMPLETE')
        for directory in [folder,engine]:require(struct.unpack('<2i',(directory/'script-status.bin').read_bytes())==(0,2522),'SCRIPT_STATUS_DIFFERS')
        require((folder/'api-fixtures.bin').read_bytes()==(engine/'api-fixtures.bin').read_bytes(),'TESTER_FIXTURES_DIFFER')
        original=(folder/'original-results.bin').read_bytes()
        require(original==(folder/'mql5-results.bin').read_bytes()==(engine/'mql5-results.bin').read_bytes(),'SCRIPT_NATIVE_TESTER_BYTES_DIFFER')
        require(len(selection.read_results(engine/'mql5-results.bin',2522))==2522,'TESTER_RECORDS_DIFFER')
        checks.append(dict(bot=bot,cases=2522,rejected_corrupt_input_types=rejected,fixture_length_checks=fixture_length_checks(folder,len(rows)),comparison_sha256=sha(folder/'comparison.json'),tester_comparison_sha256=sha(engine/'comparison.json'),sources_sha256=mql['sources_sha256'],dependencies_sha256=native['dependencies_sha256'],result_sha256=sha(engine/'mql5-results.bin')))
    negative_path=ROOT/'danh-gia-doc-lap/chon-lenh-huy-20261024/negative-cli-r2.json';negative=read(negative_path)
    saved_runners=[ROOT/f'bot-cua-toi-{bot}/bang-chung/kiem-chon-lenh-huy/selection-20261024-r2/tested-sources/tester-check-tool.py' for bot in [1,3]]
    require(negative['check_tool_sha256']==sha(Path(selection.__file__)) and all(negative['tester_tool_sha256']==sha(path) for path in saved_runners),'NEGATIVE_CLI_TOOL_CHANGED')
    require(len(negative['rejected'])==7 and all(r['returncode'] and r['expected_error'] in r['last_error'] for r in negative['rejected']),'NEGATIVE_CLI_CHECKS_FAILED')
    report=dict(status='four-pending-selector-functions-verified-with-stated-limits',checks=checks,message_arity_checks=message_arity_checks(),negative_cli_sha256=sha(negative_path),tool_sha256=sha(Path(__file__)),whole_bot_complete=False,
                limits=['35 public fields,four full strings with null flags,all200 table doubles,last ticket,magic,symbol and typed records compared; MQL padding bytes not compared.',
                        'Terminal queries and send replies are supplied and input-bound; formatting is measured in MT5.',
                        'No full EA,all settings,display,restart,actual account selection,broker or allocation-failure proof.',
                        '2522 finite cases per bot are not a percentage of whole-bot completion.'])
    selection.save(target,report);print(json.dumps(dict(bots=2,cases_each=2522,rejected_corrupt_input_types_each=24,whole_bot_complete=False)))

if __name__=='__main__':main()
