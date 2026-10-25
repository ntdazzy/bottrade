"""Verify saved position-modify evidence across original code, MQL5 script and tester runs.

Usage: kiem-chung-sua-vi-the-bot-1-3.py NEW_JSON
Starts no MT5. Re-executes a small original subset, recomputes paths/requests from
fixtures and results, and rejects deliberately corrupt typed inputs and truncated
files. The tester runner is checked through its frozen tester-check-tool.py copy.
Output must be a new JSON inside khoi-phuc.
"""
import argparse
import copy
import importlib.util
import json
from pathlib import Path
import struct
from types import SimpleNamespace

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('position_modify',Path(__file__).with_name('kiem-sua-vi-the-bot-1-3.py'))
modify=importlib.util.module_from_spec(spec);spec.loader.exec_module(modify)
sha=modify.sha;MT=modify.MT;send=modify.send
COUNT=1596;PATHS={'stopped':83,'select_failed':33,'sent':1480};INSTRUCTIONS=196
RUN='position-modify-20261025-r1';AREA=ROOT/'doi-chung-mt5/sua-vi-the-20261025'
ENGINE_RUN={1:'engine-modify-b1-r1',3:'engine-modify-b3-r1'};BUILD={1:'b1-position-modify-01',3:'b3-position-modify-01'}
FORMAT='%s: MQL5 program is stopped. Trading is disabled';METHOD='CTrade::PositionModify'
REQUEST='<iQQQdddddQiiiqQQQ';RESULT='<IQQddddQIi'
SCHEMAS=dict(
    baseline={'cases','cases_sha256','original_ex5_sha256','engine_sha256','tool_sha256','dependencies_sha256','sources_sha256'},
    mql5={'cases','exit_code','seconds','script_sha256','terminal_sha256_before','terminal_sha256_after','build_receipt','build_receipt_sha256','metaeditor_sha256',
          'original_ex5_sha256','engine_sha256','tool_sha256','dependencies_sha256','sources_sha256','hashes','tested_sources_sha256'},
    native={'cases','seconds','result_sha256','fixture_sha256','original_ex5_sha256','engine_sha256','tool_sha256','dependencies_sha256','sources_sha256',
            'native_rva','paths','coverage','observed_literals','input_contract_checked_cases','scope'},
    comparison={'cases','matched','failed','first_failures','paths','coverage','observed_literals','hashes','whole_bot_complete','scope'},
    receipt={'run','target','metaeditor_sha256','exit_code','errors','warnings','result_line','sources_sha256','trade_mqh_sha256','binary_sha256'},
    build={'exit_code','errors','warnings','source_sha256','binary_sha256','component_build_receipt_sha256','component_sources_sha256','test_input_sha256',
           'tester_sha256','tool_sha256','adapted_api_include_sha256'},
    tester={'bot','cases','matched','failed','first_failures','seconds','source_comparison','hashes','whole_bot_complete','scope','input_contract_checked_cases'},
    job={'id','expert','symbol','period','model','from','to','timeout','inputs'})
RUNNER_KEYS={'id','exit_code','report_created','login_confirmed','demo_confirmed','expert','expert_sha256','terminal_sha256','tester_sha256','job'}

def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)
def zero(value):return type(value) is int and value==0

def summary(raw):
    rd=modify.Reader(raw);case,ret=rd.take('iI');state=modify.state_block(rd);counters=rd.take('8iQ')
    require(rd.pos==len(raw),'RESULT_SUMMARY_BYTES_DIFFER')
    return dict(id=case,ret=ret,retcode=struct.unpack_from('<I',state,132)[0],entries=counters[0],selects=counters[1],strings=counters[2],sends=counters[3],early_prints=counters[5])

def expected_path(row):return 'stopped' if row['stopped'] else 'select_failed' if not row['select_ok'] else 'sent'

def expected_send(row):
    # Analysis order: reset after selection, action/position before the symbol query,
    # stored magic read after it, sl/tp written last; scenario writes show each boundary.
    scenario=row['scenario'];action,price,position,filling,expiration,magic=6,0.,row['ticket'],0,0,row['magic']
    if scenario==1:magic=0x1111222233334444
    if scenario==2:magic=0xfedcba9876543210
    if scenario==3:action,price,position,filling,expiration=7,33.25,0x55,3,1234567
    symbol='' if row['symbol_null'] else row['symbol']
    request=struct.pack(REQUEST,action,magic,0,send.text_hash(symbol),0.,price,0.,row['sl'],row['tp'],0,0,filling,0,expiration,send.text_hash(''),position,0)
    old=struct.pack(RESULT,0,99 if scenario==3 else 0,0,0.,0.,0.,0.,send.text_hash(''),0,0)
    return request,old

def path_checks(rows,records,results):
    counts=dict.fromkeys(PATHS,0)
    for row,raw in zip(rows,results):
        path=expected_path(row);s=summary(raw);trace=records[row['id']];apis=[api for api,_ in trace];counts[path]+=1
        require(s['id']==row['id'] and s['entries']==1,'RESULT_CASE_OR_ENTRY_DIFFERS')
        if path=='stopped':
            require((s['early_prints'],s['selects'],s['strings'],s['sends'],s['ret'],s['retcode'])==(1,0,0,0,0,10027) and apis==[17,18,8],'STOP_PATH_DIFFERS')
            require(trace[2][1]==(FORMAT,METHOD,FORMAT.replace('%s',METHOD,1)),'STOP_MESSAGE_DIFFERS')
        elif path=='select_failed':
            require((s['early_prints'],s['selects'],s['strings'],s['sends'],s['ret'])==(0,1,0,0,0) and apis==[17,18,20],'SELECT_FAILED_PATH_DIFFERS')
        else:
            require((s['early_prints'],s['selects'],s['strings'],s['sends'])==(0,1,1,1) and s['ret']==int(row['send']['accepted']!=0) and apis[:7]==[17,18,20,18,23,1,18],'SEND_PATH_DIFFERS')
            mode,accepted,request,old,new=trace[5][1]
            require((request,old)==expected_send(row),'SEND_REQUEST_ORDER_OR_FIELDS_DIFFER '+str(row['id']))
    require(counts==PATHS,'PATH_COUNTS_DIFFER '+json.dumps(counts))
    return counts

def replay(bot,rows,records,chart,digits,results,groups):
    picks=sorted({groups.index(name) for name in dict.fromkeys(groups)}|{i for i,group in enumerate(groups) if group=='controlled-boundary-changes'})
    runner=modify.Original(bot,records,chart,digits)
    for i in picks:require(runner.run_modify(rows[i])==results[i],'NATIVE_REPLAY_DIFFERS '+str(i))
    require(runner.covered==runner.instructions and len(runner.instructions)==INSTRUCTIONS,'NATIVE_REPLAY_COVERAGE_INCOMPLETE')
    return picks

def rejected(label,row,bad,tested):
    try:modify.validate_inputs(row,bad)
    except ValueError:tested.add(label);return
    raise ValueError('CORRUPT_INPUT_ACCEPTED '+label)

def rejection_checks(rows,records):
    expected={'cast-sltp-constant','cast-retcode','select-index','select-ticket','select-reply','symbol-property','symbol-index','symbol-null','symbol-text',
              'send-mode','send-reply','send-result','format-property','format-value','format-status',
              'missing-cast-record','duplicate-select','duplicate-symbol','duplicate-send','format-before-send','symbol-before-select','unexpected-record'}
    tested=set();row=next(r for r in rows if expected_path(r)=='sent' and any(api==2 for api,_ in records[r['id']]));values=records[row['id']]
    for i,(api,value) in enumerate(values):
        changes=[]
        def change(label,index,mutation):
            changed=list(value);changed[index]=mutation(changed[index]);changes.append((label,tuple(changed)))
        if api==17:change('cast-sltp-constant',0,lambda v:v+'!');change('cast-retcode',3,lambda v:v+'!')
        elif api==20:
            for index,label in enumerate(['select-index','select-ticket','select-reply']):change(label,index,lambda v:v^1)
        elif api==23:
            for index,label in enumerate(['symbol-property','symbol-index','symbol-null']):change(label,index,lambda v:v^1)
            change('symbol-text',3,lambda v:v+'!')
        elif api==1:
            change('send-mode',0,lambda v:v^1);change('send-reply',1,lambda v:v^1);change('send-result',4,lambda v:bytes([v[0]^1])+v[1:])
        elif api==2:
            change('format-property',0,lambda v:-1);change('format-value',2,lambda v:v^1);change('format-status',3,lambda v:v^1)
        for label,changed in changes:
            if label not in tested:
                bad=copy.deepcopy(values);bad[i]=(api,changed);rejected(label,row,bad,tested)
    def index(trace,api):return next(i for i,(kind,_) in enumerate(trace) if kind==api)
    bad=copy.deepcopy(values);bad.pop(0);rejected('missing-cast-record',row,bad,tested)
    for label,api in [('duplicate-select',20),('duplicate-symbol',23),('duplicate-send',1)]:
        bad=copy.deepcopy(values);at=index(bad,api);bad.insert(at,bad[at]);rejected(label,row,bad,tested)
    bad=copy.deepcopy(values);item=bad.pop(index(bad,2));bad.insert(index(bad,1),item);rejected('format-before-send',row,bad,tested)
    bad=copy.deepcopy(values);first,second=index(bad,20),index(bad,23);bad[first],bad[second]=bad[second],bad[first];rejected('symbol-before-select',row,bad,tested)
    bad=copy.deepcopy(values);bad.insert(1,(9,(33,'XAUUSD',0)));rejected('unexpected-record',row,bad,tested)
    require(tested==expected,'REJECTION_TYPES_MISSING '+str(sorted(expected-tested)))
    return sorted(tested)

def refused(label,reader,raw,checks):
    try:reader(SimpleNamespace(read_bytes=lambda:raw))
    except (ValueError,struct.error,UnicodeError):checks.append(label);return
    raise ValueError('CORRUPT_FILE_ACCEPTED '+label)

def file_rejections(folder,n):
    checks=[];generated=modify.cases()
    for label,mutate in [('case-scenario-range',lambda r:r[0].update(scenario=8)),('case-select-reply-range',lambda r:r[0].update(select_ok=2)),
                         ('case-null-symbol-with-text',lambda r:r[0].update(symbol_null=1,symbol='X')),('case-null-flag-range',lambda r:r[0].update(symbol_null=2)),
                         ('case-id-order',lambda r:r[1]['send'].update(id=7)),('case-async-byte-range',lambda r:r[0]['send'].update(async_mode=256))]:
        rows=copy.deepcopy(generated[:3]);mutate(rows);refused(label,modify.read_cases,modify.encode(rows),checks)
    raw=(folder/'cases.bin').read_bytes();refused('case-header-magic',modify.read_cases,bytes([raw[0]^1])+raw[1:],checks)
    raw=(folder/'api-fixtures.bin').read_bytes();rd=modify.Reader(raw);rd.take('3i');rd.text();rd.take('i');first=rd.pos
    for label,changed in [('fixture-header-count',raw[:8]+struct.pack('<i',n+1)+raw[12:]),('fixture-unknown-api',raw[:first+4]+struct.pack('<i',99)+raw[first+8:]),
                          ('fixture-case-id',raw[:first]+struct.pack('<i',n+5)+raw[first+4:])]:
        refused(label,lambda p:modify.fixtures(p,n),changed,checks)
    raw=(folder/'original-results.bin').read_bytes()
    for label,changed in [('result-header-count',raw[:8]+struct.pack('<i',n+1)+raw[12:]),('result-case-id',raw[:12]+struct.pack('<i',1)+raw[16:])]:
        refused(label,lambda p:modify.read_results(p,n),changed,checks)
    return checks

def length_checks(folder,engine,n):
    checks=[]
    for path,reader in [(folder/'cases.bin',modify.read_cases),(folder/'api-fixtures.bin',lambda p:modify.fixtures(p,n)),(folder/'original-results.bin',lambda p:modify.read_results(p,n)),
                        (folder/'mql5-results.bin',lambda p:modify.read_results(p,n)),(engine/'api-fixtures.bin',lambda p:modify.fixtures(p,n)),(engine/'mql5-results.bin',lambda p:modify.read_results(p,n))]:
        raw=path.read_bytes()
        for removed in [1,2,4]:
            labels=[];refused(path.name,reader,raw[:-removed],labels)
            checks.append(dict(file=path.relative_to(ROOT).as_posix(),removed_tail_bytes=removed,rejected=bool(labels)))
    return checks

def wrapper(script,filename):
    source=script
    for old,new in [('#property script_show_inputs\n',''),('int OnStart()','int RunQueueCheck()'),('FileOpen(folder+"cases.bin",','FileOpen("'+filename+'",')]:
        require(source.count(old)==1,'WRAPPER_SOURCE_SHAPE_CHANGED');source=source.replace(old,new)
    return '#property strict\n#property tester_file "'+filename+'"\n'+source+'\nint OnInit()\n{\n   int result=RunQueueCheck();\n   Print("POSITIONMODIFY_NATIVE_CHECK_EXIT:",result);\n   return result==0 ? INIT_SUCCEEDED : INIT_FAILED;\n}\nvoid OnTick() { ExpertRemove(); }\n'

def check_bot(bot):
    home=ROOT/f'bot-cua-toi-{bot}';folder=home/'bang-chung/kiem-sua-vi-the'/RUN;engine=AREA/ENGINE_RUN[bot]
    baseline=read(folder/'baseline.json');mql=read(folder/'mql5-run.json');native=read(folder/'original-run.json');comparison=read(folder/'comparison.json')
    for name,record in [('baseline',baseline),('mql5',mql),('native',native),('comparison',comparison)]:require(set(record)==SCHEMAS[name],'COMPONENT_SCHEMA_CHANGED '+name)
    current=modify.identity(bot,home);names=modify.names(bot)
    for stage,record in [('BASELINE',baseline),('MQL5_RUN',mql),('ORIGINAL_RUN',native)]:modify.check_identity(record,current,stage)
    require(list(current['sources_sha256'])==names and len(names)==7,'SOURCE_LIST_CHANGED')
    require(current['engine_sha256']==modify.ENGINE==sha(MT/'metatester64.exe'),'ENGINE_CHANGED')
    require(current['tool_sha256']==sha(Path(modify.__file__))==sha(folder/'tested-sources/check-tool.py'),'COMPONENT_TOOL_CHANGED')
    require(modify.encode(modify.cases())==(folder/'cases.bin').read_bytes() and baseline['cases']==COUNT and baseline['cases_sha256']==sha(folder/'cases.bin'),'GENERATED_INPUT_CHANGED')
    receipt_path=home/'bang-chung/bien-dich'/BUILD[bot]/'bien-nhan.json';receipt=read(receipt_path)
    require(set(receipt)==SCHEMAS['receipt'] and mql['build_receipt']==receipt_path.relative_to(ROOT).as_posix() and mql['build_receipt_sha256']==sha(receipt_path),'BUILD_RECEIPT_CHANGED')
    # MetaEditor can exit 1 after a clean compile here; the counts, binary and execution decide.
    require(receipt['target']==names[0] and zero(receipt['errors']) and zero(receipt['warnings']),'SCRIPT_BUILD_NOT_CLEAN')
    require(receipt['binary_sha256']==mql['script_sha256']==sha(receipt_path.parent/Path(names[0]).with_suffix('.ex5').name),'SCRIPT_BINARY_CHANGED')
    require(receipt['metaeditor_sha256']==mql['metaeditor_sha256']==sha(MT/'metaeditor64.exe'),'COMPILER_CHANGED')
    require(set(mql['tested_sources_sha256'])=={Path(name).name for name in names}|{'check-tool.py'},'TESTED_SOURCE_SET_CHANGED')
    for name in names:
        digest=current['sources_sha256'][name]
        require(receipt['sources_sha256'][name]==mql['sources_sha256'][name]==digest==mql['tested_sources_sha256'][Path(name).name]==sha(folder/'tested-sources'/Path(name).name),'CURRENT_OR_TESTED_SOURCE_CHANGED '+name)
    for name,digest in mql['tested_sources_sha256'].items():require(sha(folder/'tested-sources'/name)==digest,'TESTED_SOURCE_COPY_CHANGED '+name)
    terminal=sha(MT/'terminal64.exe')
    require(mql['cases']==COUNT and mql['exit_code']==0 and mql['terminal_sha256_before']==mql['terminal_sha256_after']==terminal,'SCRIPT_RUN_OR_TERMINAL_CHANGED')
    for hashes in [mql['hashes'],comparison['hashes']]:
        for name,digest in hashes.items():require(sha(folder/name)==digest,'EVIDENCE_CHANGED '+name)
    literals={hex(rva):text for rva,text in zip(modify.LITERALS[bot],[FORMAT,METHOD])};coverage={'instructions':INSTRUCTIONS,'executed':INSTRUCTIONS}
    require(native['cases']==native['input_contract_checked_cases']==COUNT and native['native_rva']==hex(modify.FN[bot]) and native['scope']==modify.__doc__,'NATIVE_RUN_CHANGED')
    require(native['result_sha256']==sha(folder/'original-results.bin') and native['fixture_sha256']==sha(folder/'api-fixtures.bin'),'NATIVE_RESULT_CHANGED')
    for record in [native,comparison]:require(record['paths']==PATHS and record['coverage']==coverage and record['observed_literals']==literals,'RECORDED_PATHS_COVERAGE_OR_LITERALS_DIFFER')
    require(comparison['cases']==comparison['matched']==COUNT and comparison['failed']==0 and comparison['first_failures']==[] and comparison['whole_bot_complete'] is False and comparison['scope']==modify.__doc__,'COMPARISON_RECORD_DIFFERS')
    require(struct.unpack('<2i',(folder/'script-status.bin').read_bytes())==(0,COUNT),'SCRIPT_STATUS_DIFFERS')
    rows=modify.read_cases(folder/'cases.bin');records,chart,digits=modify.fixtures(folder/'api-fixtures.bin',COUNT)
    for row in rows:modify.validate_inputs(row,records[row['id']])
    original=(folder/'original-results.bin').read_bytes();results=modify.read_results(folder/'original-results.bin',COUNT)
    require(original==(folder/'mql5-results.bin').read_bytes() and results==modify.read_results(folder/'mql5-results.bin',COUNT),'SCRIPT_NATIVE_BYTES_DIFFER')
    counts=path_checks(rows,records,results);groups=[row['group'] for row in modify.cases()];picks=replay(bot,rows,records,chart,digits,results,groups)
    require(engine.is_dir(),'TESTER_EVIDENCE_MISSING '+engine.relative_to(ROOT).as_posix())
    build=read(engine/'build.json');tester=read(engine/'comparison.json');jobs=read(engine/'jobs.json')
    require(set(build)==SCHEMAS['build'] and set(tester)==SCHEMAS['tester'] and len(jobs)==1 and set(jobs[0])==SCHEMAS['job'],'TESTER_SCHEMA_CHANGED')
    job=jobs[0];runner=[json.loads(line) for line in (engine/'runner/ket-qua-chay.jsonl').read_text().splitlines()][-1];saved=engine/'tester-check-tool.py'
    require(RUNNER_KEYS<=set(runner),'TESTER_RUNNER_SCHEMA_CHANGED')
    require(zero(build['errors']) and zero(build['warnings']) and type(build['binary_sha256']) is str,'TESTER_BUILD_NOT_CLEAN')
    saved_text=saved.read_text(encoding='utf-8')
    require(build['tool_sha256']==sha(saved) and "if a.modify:label='PositionModify';part='kiem-sua-vi-the'" in saved_text and "comparison['scope']='"+tester['scope']+"'" in saved_text,'FROZEN_TESTER_TOOL_DIFFERS')
    require(build['tester_sha256']==runner['tester_sha256']==current['engine_sha256'] and build['test_input_sha256']==sha(folder/'cases.bin'),'TESTER_ENGINE_OR_INPUT_CHANGED')
    require(build['component_build_receipt_sha256']==sha(receipt_path) and build['component_sources_sha256']==mql['sources_sha256'] and set(build['component_sources_sha256'])==set(names),'TESTER_COMPONENT_SOURCE_CHANGED')
    filename=f'b{bot}-positionmodify-{engine.name}.bin';frozen=folder/'tested-sources'
    expected_wrapper=wrapper((frozen/Path(names[0]).name).read_text(encoding='utf-8-sig'),filename)
    require(expected_wrapper==wrapper((home/'source/MQL5'/names[0]).read_text(encoding='utf-8-sig'),filename)==(engine/'PositionModifyEngineCheck.mq5').read_text(encoding='utf-8'),'WRAPPER_IS_NOT_EXPECTED_CHECK_BODY')
    facade=(frozen/f'Bot{bot}PipelineApi.mqh').read_text(encoding='utf-8-sig');old=f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}TradeSend.mqh"'
    require(facade.count(old)==1 and facade.replace(old,f'#include <bot-cua-toi-{bot}/Bot{bot}TradeSend.mqh>')==(engine/f'Bot{bot}PipelineApi.mqh').read_text(encoding='utf-8'),'ADAPTED_INCLUDE_CHANGED')
    require(sha(engine/'PositionModifyEngineCheck.mq5')==build['source_sha256'] and sha(engine/f'Bot{bot}PipelineApi.mqh')==build['adapted_api_include_sha256'],'TESTER_WRAPPER_HASH_CHANGED')
    require(job==dict(id='q-engine-'+engine.name,expert=f'RecoveryPositionModify20261024\\{engine.name}\\PositionModifyEngineCheck.ex5',symbol='XAUUSD_NOCOST_V2',period='M15',model=0,
                      **{'from':'2026.09.29','to':'2026.09.30'},timeout=120,inputs={'CheckRun':engine.name}),'TESTER_JOB_OR_OUTPUT_NOT_ISOLATED')
    require(runner['id']==job['id'] and runner['job']==job and runner['expert']==job['expert'],'TESTER_RUNNER_JOB_DIFFERS')
    require(sha(engine/'PositionModifyEngineCheck.ex5')==build['binary_sha256']==runner['expert_sha256'],'TESTER_BINARY_CHANGED')
    require(runner['exit_code']==0 and runner['demo_confirmed'] is True and runner['login_confirmed'] is True and runner['report_created'] is True and runner['terminal_sha256']==terminal,'TESTER_RUN_NOT_VERIFIED')
    require('POSITIONMODIFY_NATIVE_CHECK_EXIT:0' in (engine/'runner'/(job['id']+'.log')).read_text(),'TESTER_DID_NOT_COMPLETE')
    require(struct.unpack('<2i',(engine/'script-status.bin').read_bytes())==(0,COUNT) and (engine/'api-fixtures.bin').read_bytes()==(folder/'api-fixtures.bin').read_bytes(),'TESTER_STATUS_OR_FIXTURES_DIFFER')
    require((engine/'mql5-results.bin').read_bytes()==original and modify.read_results(engine/'mql5-results.bin',COUNT)==results,'SCRIPT_NATIVE_TESTER_BYTES_DIFFER')
    tester_files={'cases.bin':folder/'cases.bin','original-results.bin':folder/'original-results.bin','tester-mql5-results.bin':engine/'mql5-results.bin',
                  'script-mql5-results.bin':folder/'mql5-results.bin','api-fixtures.bin':engine/'api-fixtures.bin','script-status.bin':engine/'script-status.bin'}
    require(set(tester['hashes'])==set(tester_files) and all(sha(path)==tester['hashes'][name] for name,path in tester_files.items()),'TESTER_HASHES_DIFFER')
    require(tester['bot']==bot and tester['cases']==tester['matched']==tester['input_contract_checked_cases']==COUNT and tester['failed']==0 and tester['first_failures']==[]
            and tester['whole_bot_complete'] is False and tester['source_comparison']==folder.relative_to(ROOT).as_posix(),'TESTER_COMPARISON_DIFFERS')
    return dict(bot=bot,cases=COUNT,paths=counts,coverage=coverage,replayed_original_case_ids=picks,rejected_corrupt_input_types=rejection_checks(rows,records),
                rejected_corrupt_files=file_rejections(folder,COUNT),length_checks=length_checks(folder,engine,COUNT),
                sources_sha256=mql['sources_sha256'],dependencies_sha256=current['dependencies_sha256'],tool_sha256=current['tool_sha256'],
                tester_tool_sha256=build['tool_sha256'],result_sha256=sha(engine/'mql5-results.bin'),comparison_sha256=sha(folder/'comparison.json'),tester_comparison_sha256=sha(engine/'comparison.json'))

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('new_json',type=Path);a=parser.parse_args();target=a.new_json.resolve()
    require(target.is_relative_to(ROOT) and target.suffix=='.json' and target.parent.is_dir() and not target.exists(),'OUTPUT_MUST_BE_NEW_JSON_INSIDE_KHOI_PHUC')
    checks=[check_bot(bot) for bot in [1,3]]
    for check in checks:require(all(row['rejected'] for row in check['length_checks']),'TRUNCATED_FILE_ACCEPTED')
    report=dict(status='position-modify-helper-verified-with-stated-limits',checks=checks,tool_sha256=sha(Path(__file__)),whole_bot_complete=False,
                limits=['IsStopped, selection, symbol and send replies are supplied and input-bound; formatting/casts measured in MT5.',
                        'Return, 35 public fields, four strings/null flags, stored values/options and state at service boundaries compared; MQL padding not compared.',
                        'Original replay covers a subset; the full original run is checked through its frozen hashes and recomputed paths/requests.',
                        'Callers, argument origins in callers, full EA, settings, display, restart, actual account/broker, _LastError and allocation faults still require proof.',
                        '1596 finite cases per bot are not a percentage of whole-bot completion.'])
    modify.save(target,report);print(json.dumps(dict(bots=2,cases_each=COUNT,paths=PATHS,rejected_corrupt_types_each=len(checks[0]['rejected_corrupt_input_types']),whole_bot_complete=False)))

if __name__=='__main__':main()
