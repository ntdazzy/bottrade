"""Verify queue/error sources and saved evidence, then re-run the original queue.

Usage: kiem-chung-hang-doi-bot-1-3.py NEW_JSON
No MT5 is started. NEW_JSON must not exist and must be inside khoi-phuc.
The fresh native audit uses supplied builder results and the measured CPU NaN rule.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('queue_check',Path(__file__).with_name('kiem-hang-doi-bot-1-3.py'))
queue=importlib.util.module_from_spec(spec);spec.loader.exec_module(queue)
errors=queue.errors;sha=queue.sha

def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)
def verify_hashes(directory,hashes):
    for name,digest in hashes.items():require(sha(directory/name)==digest,'EVIDENCE_CHANGED '+str(directory/name))
def verify_build(home,build,used,mql5):
    path=home/'bang-chung/bien-dich'/build/'bien-nhan.json';receipt=read(path)
    require(not receipt['errors'] and not receipt['warnings'],'BUILD_NOT_CLEAN')
    require(sha(path)==mql5['build_receipt_sha256'],'BUILD_RECEIPT_CHANGED')
    require(receipt['binary_sha256']==mql5['script_sha256'],'TESTED_BINARY_DIFFERS')
    require(sha(path.parent/Path(receipt['target']).with_suffix('.ex5').name)==receipt['binary_sha256'],'SAVED_BINARY_CHANGED')
    for name in used:require(sha(home/'source/MQL5'/name)==receipt['sources_sha256'][name],'CURRENT_SOURCE_CHANGED '+name)
    return dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),binary_sha256=receipt['binary_sha256'],sources_sha256={name:receipt['sources_sha256'][name] for name in used})

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('new_json',type=Path);a=ap.parse_args();target=a.new_json.resolve()
    require(target.is_relative_to(ROOT) and target.suffix=='.json' and not target.exists() and target.parent.is_dir(),'OUTPUT_MUST_BE_NEW_JSON_INSIDE_KHOI_PHUC')
    checks=[]
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';digest=queue.send.pending.fill.validation.original_hash(bot)
        directory=home/'bang-chung/kiem-chuoi-loi/errors-20261024-r3';comparison=read(directory/'comparison.json');baseline=read(directory/'baseline.json');mql5=read(directory/'mql5-run.json');native=read(directory/'original-run.json')
        require(baseline['original_ex5_sha256']==digest and comparison['cases']==5826 and comparison['matched']==5826 and not comparison['failed'],'ERROR_TEXT_COMPARISON_NOT_VERIFIED')
        verify_hashes(directory,comparison['hashes']);verify_hashes(directory,mql5['hashes'])
        require(native['result_sha256']==sha(directory/'original-results.bin') and native['casts_sha256']==sha(directory/'cast-values.bin'),'ERROR_NATIVE_EVIDENCE_CHANGED')
        require(native['tool_sha256']==sha(Path(errors.__file__)) and native['counter_before_string_copy_verified_cases']==5826,'ERROR_NATIVE_TOOL_OR_ORDER_CHANGED')
        require((directory/'original-results.bin').read_bytes()==(directory/'mql5-results.bin').read_bytes(),'ERROR_RESULT_BYTES_DIFFER')
        rows=errors.read_cases(directory/'cases.bin');require(set(range(-1,4208)).issubset({r['code'] for r in rows}),'ERROR_INTEGER_INTERVAL_NOT_COVERED')
        used=[f'Scripts/bot-cua-toi-{bot}/Bot{bot}TradeErrorsCheck.mq5',f'Include/bot-cua-toi-{bot}/Bot{bot}TradeErrors.mqh']
        checks.append(dict(bot=bot,part='error-text',cases=5826,comparison_sha256=sha(directory/'comparison.json'),build=verify_build(home,f'b{bot}-trade-errors-02',used,mql5)))
        directory=home/'bang-chung/kiem-hang-doi/queue-20261024-r3';comparison=read(directory/'comparison.json');baseline=read(directory/'baseline.json');mql5=read(directory/'mql5-run.json');native=read(directory/'original-run.json')
        require(baseline['original_ex5_sha256']==digest and comparison['cases']==374 and comparison['matched']==374 and not comparison['failed'],'QUEUE_COMPARISON_NOT_VERIFIED')
        verify_hashes(directory,comparison['hashes']);verify_hashes(directory,mql5['hashes'])
        require(sha(directory/'original-results.bin')==native['result_sha256'] and sha(Path(queue.__file__))==native['tool_sha256'],'QUEUE_NATIVE_EVIDENCE_CHANGED')
        used=[f'Scripts/bot-cua-toi-{bot}/Bot{bot}PendingQueueCheck.mq5']+[f'Include/bot-cua-toi-{bot}/Bot{bot}{name}.mqh' for name in ['PendingQueue','TradeErrors','TradeSend','TradeMessages','PendingRequest','Filling']]
        build=verify_build(home,f'b{bot}-pending-queue-03',used,mql5)
        engine=ROOT/f'doi-chung-mt5/hang-doi-20261024/engine-b{bot}-r3';engine_comparison=read(engine/'comparison.json');engine_build=read(engine/'build.json');runner=read(engine/'jobs.json')[0]['id']
        run=read(engine/'runner/ket-qua-chay.jsonl')
        require(run['demo_confirmed'] and run['login_confirmed'] and run['report_created'] and not run['exit_code'],'QUEUE_TESTER_RUN_NOT_VERIFIED')
        require(engine_comparison['cases']==374 and engine_comparison['matched']==374 and not engine_comparison['failed'],'QUEUE_TESTER_COMPARISON_NOT_VERIFIED')
        require(not engine_build['errors'] and not engine_build['warnings'] and sha(engine/'QueueEngineCheck.mq5')==engine_build['source_sha256'],'QUEUE_TESTER_SOURCE_CHANGED')
        require(sha(engine/'QueueEngineCheck.ex5')==engine_build['binary_sha256']==run['expert_sha256'],'QUEUE_TESTER_BINARY_CHANGED')
        require('QUEUE_NATIVE_CHECK_EXIT:0' in (engine/'runner'/(runner+'.log')).read_text(encoding='utf-8-sig'),'QUEUE_TESTER_DID_NOT_FINISH')
        for name in used:require(engine_build['component_sources_sha256'][name]==build['sources_sha256'][name],'QUEUE_TESTER_COMPONENT_CHANGED')
        original=(directory/'original-results.bin').read_bytes();require(original==(directory/'mql5-results.bin').read_bytes()==(engine/'mql5-results.bin').read_bytes(),'QUEUE_RECORD_BYTES_DIFFER')
        # Re-run after the error-checker improvements, recording the current
        # complete dependency set instead of assuming inherited code is unchanged.
        old=home/'bang-chung/kiem-chuoi-loi/errors-20261024-r2';old_comparison=read(old/'comparison.json');verify_hashes(old,old_comparison['hashes'])
        require(sha(old/'comparison.json')==native['cast_source_comparison_sha256'],'QUEUE_CAST_SOURCE_CHANGED')
        cast_rows=errors.read_cases(old/'cases.bin');reader=queue.send.Reader((old/'cast-values.bin').read_bytes())
        require(reader.take('3i')==(errors.MAGIC,1,len(cast_rows)),'CAST_HEADER_DIFFERS');casts={row['code']:reader.text() for row in cast_rows}
        require(reader.pos==len(reader.raw),'CAST_LENGTH_DIFFERS');o=queue.Original(bot,casts);rows=queue.read_cases(directory/'cases.bin')
        fresh=struct.pack('<3i',queue.MAGIC,1,len(rows))+b''.join(o.run(row) for row in rows)
        require(fresh==original,'FRESH_NATIVE_QUEUE_RECORDS_DIFFER')
        checks.append(dict(bot=bot,part='queue',cases=374,comparison_sha256=sha(directory/'comparison.json'),build=build,
                           tester_comparison_sha256=sha(engine/'comparison.json'),fresh_native_result_sha256=hashlib.sha256(fresh).hexdigest(),cpu_nan_reference_sha256=o.nan_reference_sha256))
    dependencies=[Path(__file__),Path(queue.__file__),Path(errors.__file__),Path(queue.send.__file__),Path(queue.send.pending.__file__),Path(queue.send.pending.fill.__file__),Path(queue.send.pending.fill.entry.__file__),Path(queue.send.pending.fill.entry.price_check.__file__)]
    report=dict(status='components-verified-with-stated-limits',checks=checks,dependencies_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in dependencies},whole_bot_complete=False,
                limits=['Queue pending-builder results and Print/Sleep effects supplied; full queue+builder+send still needs a combined comparison',
                        'Native memory-fill service supplied with checked address/zero/2400-byte contract',
                        'Two-NaN CPU priority measured in MT5 and corrected in the emulator; CPU FP faults not covered',
                        'Old shared string replacement checked on original only; allocation failures excluded',
                        'No full EA, all settings, display, restart or actual broker proof'])
    queue.save(target,report);print(json.dumps(dict(checks=len(checks),error_text_cases_each=5826,queue_cases_each=374,whole_bot_complete=False)))

if __name__=='__main__':main()
