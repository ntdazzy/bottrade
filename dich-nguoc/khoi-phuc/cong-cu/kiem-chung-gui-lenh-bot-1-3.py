"""Verify saved send/combined evidence and current compiled sources; write a new receipt.

Usage: python -I -B -X utf8 kiem-chung-gui-lenh-bot-1-3.py NEW_JSON
NEW_JSON must be a new .json path inside khoi-phuc. No MT5 process is started.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('new_json',type=Path);args=parser.parse_args()
    output=args.new_json.resolve()
    require(output.is_relative_to(ROOT) and output.suffix=='.json','OUTPUT_MUST_BE_NEW_JSON_INSIDE_KHOI_PHUC')
    require(not output.exists() and output.parent.is_dir(),'OUTPUT_EXISTS_OR_PARENT_MISSING')
    spec=importlib.util.spec_from_file_location('combined',Path(__file__).with_name('kiem-ghep-dat-lenh-cho-bot-1-3.py'))
    combined=importlib.util.module_from_spec(spec);spec.loader.exec_module(combined)
    send=combined.send;checks=[]
    # This copy identifies the adapter used before the additional storage audit.
    initial_adapter=ROOT/'doi-chung-mt5/gui-lenh-20261024/combined-native-tool-before-storage-audit.py'
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5'
        original_hash=send.pending.fill.validation.original_hash(bot)
        for part,folder,run,build,module,count in [
            ('send-messages','kiem-gui-lenh','send-20261024-r3',f'b{bot}-trade-send-03',send,1201),
            ('combined-pending-send','kiem-ghep-dat-lenh-cho','open-pending-20261024-r1',f'b{bot}-open-pending-01',combined,1687)]:
            directory=home/'bang-chung'/folder/run
            comparison=read(directory/'comparison.json');baseline=read(directory/'baseline.json')
            native=read(directory/'original-run.json');mql5=read(directory/'mql5-run.json')
            receipt_path=home/'bang-chung/bien-dich'/build/'bien-nhan.json';receipt=read(receipt_path)
            require(baseline['original_ex5_sha256']==original_hash,'ORIGINAL_CHANGED')
            require(comparison['cases']==count and comparison['matched']==count and comparison['failed']==0,'COMPARISON_FAILED')
            for name,digest in comparison['hashes'].items():require(sha(directory/name)==digest,'EVIDENCE_CHANGED '+name)
            require(sha(directory/'cases.bin')==baseline['cases_sha256'],'CASES_CHANGED')
            require(sha(directory/'original-results.bin')==native['result_sha256'],'NATIVE_RESULTS_CHANGED')
            require(sha(directory/'api-fixtures.bin')==native['fixtures_sha256'],'NATIVE_FIXTURES_CHANGED')
            require((directory/'original-results.bin').read_bytes()==(directory/'mql5-results.bin').read_bytes(),'RESULT_BYTES_DIFFER')
            require(len(module.read_results(directory/'original-results.bin'))==count,'RESULT_SHAPE_DIFFERS')
            require(receipt['errors']==0 and receipt['warnings']==0,'BUILD_FAILED')
            require(sha(receipt_path)==mql5['build_receipt_sha256'],'BUILD_RECEIPT_CHANGED')
            require(receipt['binary_sha256']==mql5['script_sha256'],'TESTED_BINARY_DIFFERS')
            require(sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name)==receipt['binary_sha256'],'SAVED_BINARY_CHANGED')
            used=[f'Include/bot-cua-toi-{bot}/Bot{bot}{name}.mqh' for name in ['TradeMessages','TradeSend','PendingRequest','Filling']]
            used.append(f'Scripts/bot-cua-toi-{bot}/Bot{bot}TradeSendCheck.mq5')
            if part=='combined-pending-send':used.append(receipt['target'])
            for name in used:require(sha(source/name)==receipt['sources_sha256'][name],'CURRENT_SOURCE_DIFFERS '+name)
            expected_adapter=Path(module.__file__) if part=='send-messages' else initial_adapter
            require(sha(expected_adapter)==native['tool_sha256'],'NATIVE_ADAPTER_CHANGED')
            require(sha(send.LAYOUT)==baseline['layout_sha256'],'LAYOUT_CHANGED')
            for name,digest in mql5['hashes'].items():require(sha(directory/name)==digest,'MQL5_EVIDENCE_CHANGED '+name)
            check=dict(bot=bot,part=part,cases=count,matched=count,original_ex5_sha256=original_hash,
                       comparison=str((directory/'comparison.json').relative_to(ROOT)).replace('\\','/'),
                       comparison_sha256=sha(directory/'comparison.json'),build_receipt=str(receipt_path.relative_to(ROOT)).replace('\\','/'),
                       build_receipt_sha256=sha(receipt_path),binary_sha256=receipt['binary_sha256'],
                       sources_sha256={name:receipt['sources_sha256'][name] for name in used})
            if part=='combined-pending-send':
                audit=read(directory/'native-storage-audit.json')
                require(audit['passed'] and audit['cases']==count and audit['result_sha256']==native['result_sha256'],'STORAGE_AUDIT_FAILED')
                require(audit['tool_sha256']==sha(Path(combined.__file__)),'STORAGE_ADAPTER_CHANGED')
                check['storage_audit_sha256']=sha(directory/'native-storage-audit.json')
            checks.append(check)
    layout=read(send.LAYOUT)
    require(layout['runner_verified'] and layout['only_anchor_executed'],'LAYOUT_NOT_VERIFIED')
    require(layout['relative_native_storage_bases']=={'request':0,'result':240,'check':436} and layout['end_marker_offset']==628,'LAYOUT_BASES_DIFFER')
    for name,digest in layout['source_sha256'].items():require(sha(ROOT/name)==digest,'LAYOUT_SOURCE_CHANGED')
    report=dict(status='components-verified-with-stated-limits',checks=checks,whole_bot_complete=False,
                remaining=['Broker execution and real send outcomes','Deferred100-order queue and retry/error processing',
                           'MQL5 private padding and allocation failures','Full EA, all settings, display, restart and error paths'])
    with output.open('x',encoding='utf-8') as stream:json.dump(report,stream,ensure_ascii=False,indent=2)
    print(json.dumps(dict(checks=len(checks),cases_each_bot=[1201,1687],whole_bot_complete=False)))

if __name__=='__main__':main()
