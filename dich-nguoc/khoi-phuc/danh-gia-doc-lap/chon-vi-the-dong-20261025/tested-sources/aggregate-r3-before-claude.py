"""Verify saved scanner/close evidence, source provenance and rejected bad traces.

Usage: kiem-chung-chon-vi-the-dong-bot-1-3.py NEW_JSON
No MT5 is started; output must be new and inside khoi-phuc.
"""
import argparse
import copy
import importlib.util
import json
from pathlib import Path
import struct
from types import SimpleNamespace

ROOT=Path(__file__).resolve().parents[1];COUNT=4600
spec=importlib.util.spec_from_file_location('position_selection',Path(__file__).with_name('kiem-chon-vi-the-dong-bot-1-3.py'))
selection=importlib.util.module_from_spec(spec);spec.loader.exec_module(selection)
sha=selection.sha

def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))

def require(ok,message):
    if not ok:raise ValueError(message)

def rejection_checks(rows,records):
    expected={'select-index','select-ticket','select-reply','magic-value','type-value','integer-property',
              'sl-index','sl-value','volume-index','volume-value','double-property',
              'symbol-property','symbol-index','symbol-null','symbol-text','price-property','price-index','price-value',
              'execution-value','flags-value','filling-property','send-mode','send-reply','send-result',
              'format-property','format-value','format-status','cast-metadata','total','scan-index','scan-ticket','scan-selection','helper-ticket'}
    tested=set();marker_row=None
    for row in rows:
        values=records[row['id']]
        if marker_row is None and any(api==80 for api,_ in values):marker_row=row
        for i,(api,value) in enumerate(values):
            changes=[]
            def change(label,index,mutation):
                changed=list(value);changed[index]=mutation(changed[index]);changes.append((label,tuple(changed)))
            if api==20:
                for index,label in enumerate(['select-index','select-ticket','select-reply']):change(label,index,lambda v:v^1)
            elif api==21:
                change('integer-property',0,lambda v:-1);change('magic-value' if value[0]==12 else 'type-value',2,lambda v:v^1)
            elif api==22:
                prefix='sl' if value[0]==6 else 'volume'
                change('double-property',0,lambda v:-1);change(prefix+'-index',1,lambda v:v^1);change(prefix+'-value',2,lambda v:v^1)
            elif api==23:
                for index,label in enumerate(['symbol-property','symbol-index','symbol-null']):change(label,index,lambda v:v^1)
                change('symbol-text',3,lambda v:v+'!')
            elif api==24:
                change('price-property',0,lambda v:-1);change('price-index',1,lambda v:v^1);change('price-value',4,lambda v:v^1)
            elif api==9:
                change('filling-property',0,lambda v:17);change('execution-value' if value[0]==33 else 'flags-value',2,lambda v:v^1)
            elif api==1:
                change('send-mode',0,lambda v:v^1);change('send-reply',1,lambda v:v^1);change('send-result',4,lambda v:bytes([v[0]^1])+v[1:])
            elif api==2:
                change('format-property',0,lambda v:-1);change('format-value',2,lambda v:v^1);change('format-status',3,lambda v:v^1)
            elif api==17:change('cast-metadata',0,lambda v:v+'!')
            elif api==70:change('total',0,lambda v:v^1)
            elif api==71:
                for index,label in enumerate(['scan-index','scan-ticket','scan-selection']):change(label,index,lambda v:v^1)
            elif api==80:change('helper-ticket',0,lambda v:v^1)
            for label,changed in changes:
                if label in tested:continue
                bad=copy.deepcopy(values);bad[i]=(api,changed)
                try:selection.validate_inputs(row,bad)
                except ValueError:tested.add(label)
                else:raise ValueError('CORRUPT_INPUT_ACCEPTED '+label)
        if tested==expected:break
    require(tested==expected and marker_row is not None,'REJECTION_TYPES_MISSING '+str(expected-tested))
    values=records[marker_row['id']]
    for label,api,duplicate in [('missing-helper-entry',80,False),('missing-helper-return',81,False),('duplicate-helper-entry',80,True)]:
        bad=copy.deepcopy(values);index=next(i for i,(a,_) in enumerate(bad) if a==api)
        if duplicate:bad.insert(index,bad[index])
        else:bad.pop(index)
        try:selection.validate_inputs(marker_row,bad)
        except ValueError:tested.add(label)
        else:raise ValueError('BAD_HELPER_TRACE_ACCEPTED '+label)
    return sorted(tested)

def length_checks(folder,n):
    checks=[]
    for name,reader in [('cases.bin',selection.read_cases),('api-fixtures.bin',lambda p:selection.fixtures(p,n)),('original-results.bin',lambda p:selection.read_results(p,n))]:
        raw=(folder/name).read_bytes()
        for removed in [1,2,4]:
            try:reader(SimpleNamespace(read_bytes=lambda:raw[:-removed]))
            except (ValueError,struct.error,UnicodeError):checks.append(dict(file=name,removed_tail_bytes=removed,rejected=True))
            else:raise ValueError('TRUNCATED_FILE_ACCEPTED '+name)
    return checks

def summaries(values):
    result=[]
    for value in values:
        rd=selection.send.Reader(value);cid=rd.take('i')[0];selection.close.state_block(rd);last,seed,null,selected,helpers=rd.take('Q4i');symbol=rd.text();stats=rd.take('6iQ')
        if rd.pos!=len(rd.raw):raise ValueError('RESULT_SUMMARY_BYTES_DIFFER')
        result.append(dict(id=cid,last_ticket=last,seed=seed,symbol_null=null,selected=selected,helpers=helpers,close_calls=stats[0],sends=stats[1]))
    return result

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('new_json',type=Path);a=parser.parse_args();target=a.new_json.resolve()
    require(target.is_relative_to(ROOT) and target.suffix=='.json' and target.parent.is_dir() and not target.exists(),'OUTPUT_MUST_BE_NEW_JSON_INSIDE_KHOI_PHUC')
    checks=[]
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';folder=home/'bang-chung/kiem-chon-vi-the-dong/position-selection-20261025-r3'
        baseline=read(folder/'baseline.json');comparison=read(folder/'comparison.json');mql=read(folder/'mql5-run.json');native=read(folder/'original-run.json')
        require(baseline['original_ex5_sha256']==selection.close.pending.fill.validation.original_hash(bot),'ORIGINAL_EX5_CHANGED')
        require(comparison['cases']==comparison['matched']==COUNT and comparison['failed']==0 and not comparison['whole_bot_complete'],'COMPARISON_FAILED')
        for hashes in [comparison['hashes'],mql['hashes']]:
            for name,digest in hashes.items():require(sha(folder/name)==digest,'EVIDENCE_CHANGED '+name)
        require(selection.encode(selection.cases())==(folder/'cases.bin').read_bytes() and baseline['cases_sha256']==sha(folder/'cases.bin'),'GENERATED_INPUT_CHANGED')
        require(baseline['tool_sha256']==mql['tool_sha256']==native['tool_sha256']==sha(Path(selection.__file__))==sha(folder/'tested-sources/native-check-tool.py'),'NATIVE_TOOL_CHANGED')
        require(native['dependencies_sha256']==selection.dependencies(bot),'NATIVE_DEPENDENCIES_CHANGED')
        require(native['result_sha256']==sha(folder/'original-results.bin') and native['fixture_sha256']==sha(folder/'api-fixtures.bin'),'NATIVE_RESULT_CHANGED')
        require(mql['terminal_sha256']==sha(selection.MT/'terminal64.exe'),'TERMINAL_CHANGED')
        receipt_path=ROOT/mql['build_receipt'];receipt=read(receipt_path);script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}PositionSelectionCheck.mq5'
        expected_sources={script,f'Scripts/bot-cua-toi-{bot}/Bot{bot}PipelineApi.mqh',*[f'Include/bot-cua-toi-{bot}/Bot{bot}{name}.mqh' for name in ['PositionSelection','PositionClose','TradeSend','TradeMessages','PendingRequest','Filling']]}
        require(receipt['target']==script and set(mql['sources_sha256'])==expected_sources,'TARGET_OR_SOURCE_SET_CHANGED')
        require(receipt['errors']==receipt['warnings']==0 and sha(receipt_path)==mql['build_receipt_sha256'],'SCRIPT_BUILD_CHANGED')
        require(receipt['binary_sha256']==mql['script_sha256']==sha(receipt_path.parent/Path(script).with_suffix('.ex5').name),'SCRIPT_BINARY_CHANGED')
        require(receipt['metaeditor_sha256']==sha(selection.MT/'metaeditor64.exe'),'COMPILER_CHANGED')
        for name,digest in mql['sources_sha256'].items():require(digest==receipt['sources_sha256'][name]==sha(home/'source/MQL5'/name)==sha(folder/'tested-sources'/Path(name).name),'CURRENT_OR_TESTED_SOURCE_CHANGED '+name)
        rows=selection.read_cases(folder/'cases.bin');records,_,_=selection.fixtures(folder/'api-fixtures.bin',len(rows))
        require(len(rows)==native['input_contract_checked_cases']==COUNT and all(sum(r['kind']==kind for r in rows)==2300 for kind in [0,1]),'CASE_SCOPE_CHANGED')
        for row in rows:selection.validate_inputs(row,records[row['id']])
        summary=summaries(selection.read_results(folder/'original-results.bin',COUNT))
        require(any(r['helpers']>=2 and r['close_calls']>=2 and r['sends']>=2 for r in summary),'MULTIPLE_HELPER_CLOSE_PATH_NOT_CHECKED')
        require(all(summary[i]['helpers']==2 and summary[i]['close_calls']==2 and summary[i]['sends']==2 and summary[i]['seed']==-1 and summary[i]['last_ticket']==12 for i in [4598,4599]),'POST_HELPER_CHANGE_NOT_EXERCISED')
        engine=ROOT/f'doi-chung-mt5/chon-vi-the-dong-20261025/engine-position-selection-b{bot}-r3'
        build=read(engine/'build.json');ec=read(engine/'comparison.json');job=read(engine/'jobs.json')[0];runner=[json.loads(line) for line in (engine/'runner/ket-qua-chay.jsonl').read_text().splitlines()][-1]
        require(ec['cases']==ec['matched']==COUNT and ec['failed']==0 and not ec['whole_bot_complete'] and build['errors']==build['warnings']==0,'TESTER_COMPARISON_OR_BUILD_FAILED')
        require(build['component_build_receipt_sha256']==sha(receipt_path) and build['tool_sha256']==sha(folder/'tested-sources/tester-check-tool.py'),'TESTER_PROVENANCE_CHANGED')
        require(build['tester_sha256']==sha(selection.MT/'metatester64.exe')=='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb' and build['test_input_sha256']==sha(folder/'cases.bin'),'TESTER_ENGINE_OR_INPUT_CHANGED')
        require(build['component_sources_sha256']==mql['sources_sha256'],'TESTER_COMPONENT_SOURCE_CHANGED')
        require(sha(engine/'PositionSelectionEngineCheck.mq5')==build['source_sha256'] and sha(engine/f'Bot{bot}PipelineApi.mqh')==build['adapted_api_include_sha256'],'TESTER_WRAPPER_CHANGED')
        filename=f'b{bot}-positionselection-{engine.name}.bin';source=(home/'source/MQL5'/script).read_text(encoding='utf-8-sig')
        for old,new in [('#property script_show_inputs\n',''),('int OnStart()','int RunQueueCheck()'),('FileOpen(folder+"cases.bin",','FileOpen("'+filename+'",')]:
            require(source.count(old)==1,'WRAPPER_SOURCE_SHAPE_CHANGED');source=source.replace(old,new)
        source='#property strict\n#property tester_file "'+filename+'"\n'+source
        source+='\nint OnInit()\n{\n   int result=RunQueueCheck();\n   Print("POSITIONSELECTION_NATIVE_CHECK_EXIT:",result);\n   return result==0 ? INIT_SUCCEEDED : INIT_FAILED;\n}\nvoid OnTick() { ExpertRemove(); }\n'
        require(source==(engine/'PositionSelectionEngineCheck.mq5').read_text(encoding='utf-8'),'WRAPPER_IS_NOT_EXPECTED_CHECK_BODY')
        facade=(home/f'source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}PipelineApi.mqh').read_text(encoding='utf-8-sig');old=f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}TradeSend.mqh"'
        require(facade.count(old)==1,'FACADE_SHAPE_CHANGED');facade=facade.replace(old,f'#include <bot-cua-toi-{bot}/Bot{bot}TradeSend.mqh>')
        require(facade==(engine/f'Bot{bot}PipelineApi.mqh').read_text(encoding='utf-8'),'ADAPTED_INCLUDE_CHANGED')
        require(job['inputs']['CheckRun']==engine.name,'TESTER_OUTPUT_NOT_ISOLATED')
        require(sha(engine/'PositionSelectionEngineCheck.ex5')==build['binary_sha256']==runner['expert_sha256'],'TESTER_BINARY_CHANGED')
        require(runner['demo_confirmed'] and runner['login_confirmed'] and runner['report_created'] and not runner['exit_code'],'TESTER_RUN_NOT_VERIFIED')
        require('POSITIONSELECTION_NATIVE_CHECK_EXIT:0' in (engine/'runner'/(job['id']+'.log')).read_text(),'TESTER_DID_NOT_COMPLETE')
        for directory in [folder,engine]:require(struct.unpack('<2i',(directory/'script-status.bin').read_bytes())==(0,COUNT),'SCRIPT_STATUS_DIFFERS')
        require((folder/'api-fixtures.bin').read_bytes()==(engine/'api-fixtures.bin').read_bytes(),'TESTER_FIXTURES_DIFFER')
        require((folder/'original-results.bin').read_bytes()==(folder/'mql5-results.bin').read_bytes()==(engine/'mql5-results.bin').read_bytes(),'SCRIPT_NATIVE_TESTER_BYTES_DIFFER')
        require(len(selection.read_results(engine/'mql5-results.bin',COUNT))==COUNT,'TESTER_RECORDS_DIFFER')
        checks.append(dict(bot=bot,cases=COUNT,each_direction=2300,post_helper_change_case_ids=[4598,4599],max_helper_calls=max(r['helpers'] for r in summary),max_close_calls=max(r['close_calls'] for r in summary),rejected_corrupt_input_types=rejection_checks(rows,records),length_checks=length_checks(folder,COUNT),comparison_sha256=sha(folder/'comparison.json'),tester_comparison_sha256=sha(engine/'comparison.json'),sources_sha256=mql['sources_sha256'],dependencies_sha256=native['dependencies_sha256'],result_sha256=sha(engine/'mql5-results.bin')))
    report=dict(status='four-position-scanners-through-close-verified-with-stated-limits',checks=checks,tool_sha256=sha(Path(__file__)),whole_bot_complete=False,
                limits=['SDK query/send replies and selection model supplied/input-bound; formatting measured in MT5.', 'Helper instrumentation resets test reply counters only. Public state and ordered calls compared before queries and after send/helper.', 'No real account/LastError/broker,full EA,all settings,display,restart or allocation-fault proof.','4600 finite cases per bot are not a completion percentage.'])
    selection.save(target,report);print(json.dumps(dict(bots=2,cases_each=COUNT,rejected_corrupt_types_each=len(checks[0]['rejected_corrupt_input_types']),whole_bot_complete=False)))

if __name__=='__main__':main()
