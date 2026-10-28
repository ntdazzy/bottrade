"""Check the preparation/context -> evaluator bridge against the proven layout."""
import argparse
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()
def require(ok,msg):
    if not ok: raise ValueError(msg)

MAP={
 1:dict(bridge='bot-cua-toi-1/source/MQL5/Include/bot-cua-toi-1/Bot1EvaluationBridge.mqh',api='bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1EvaluationBridgeAPICompile.mq5',receipt='bot-cua-toi-1/bang-chung/bien-dich/b1-eval-bridge-api-20261028-r3/bien-nhan.json',setup='bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the/b1-strategy-setup-20261028-r1/comparison.json',cases=432,fields=['execution.strategy_magic=context.magic','execution.magic_base=magic_base','execution.symbol=inputs.symbol','execution.tick=preparation.tick','execution.threshold_a=preparation.stop_min_price','execution.gap=preparation.freeze_min_price','restore.sl_distance=preparation.stop_distance','restore.tp_distance=preparation.target_distance','restore.expiration_base=(datetime)preparation.expiration','restore.comment=context.order_comment','restore.virtual_expiration=preparation.virtual_expiration','loop.submission.check_free_margin=preparation.check_free_margin','loop.submission.omit_real_sl_tp=preparation.omit_real_sl_tp','levels.timeframe=(ENUM_TIMEFRAMES)preparation.entry_frame','levels.aux_timeframe=(ENUM_TIMEFRAMES)preparation.aux_frame']),
 3:dict(bridge='bot-cua-toi-3/source/MQL5/Include/bot-cua-toi-3/Bot3EvaluationBridge.mqh',api='bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3EvaluationBridgeAPICompile.mq5',receipt='bot-cua-toi-3/bang-chung/bien-dich/b3-eval-bridge-api-20261028-r3/bien-nhan.json',setup='bot-cua-toi-3/bang-chung/kiem-quan-ly-vi-the/b3-strategy-setup-20261028-r1/comparison.json',cases=2106,fields=['execution.strategy_magic=context.magic','execution.magic_base=magic_base','execution.symbol=inputs.symbol','execution.tick=preparation.tick','execution.threshold_a=preparation.stop_min_price','execution.gap=preparation.freeze_min_price','restore.sl_distance=preparation.stop_distance','restore.tp_distance=preparation.target_distance','restore.expiration_base=(datetime)preparation.expiration','restore.comment=context.order_comment','restore.virtual_expiration=preparation.virtual_expiration','loop.submission.check_free_margin=preparation.native_6d51c','loop.submission.omit_real_sl_tp=preparation.native_6d510','levels.timeframe=(ENUM_TIMEFRAMES)preparation.entry_frame','levels.aux_timeframe=(ENUM_TIMEFRAMES)preparation.aux_frame'])}

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path);a=p.parse_args();out={}
    for bot,c in MAP.items():
        bridge=ROOT/c['bridge'];api=ROOT/c['api'];receipt=ROOT/c['receipt'];setup=ROOT/c['setup'];source=bridge.read_text(encoding='utf-8-sig');build=json.loads(receipt.read_text(encoding='utf-8-sig'));comparison=json.loads(setup.read_text(encoding='utf-8-sig'))
        require(all(x in source for x in c['fields']),f'BRIDGE_FIELD_MISSING_{bot}');require(build['errors']==build['warnings']==0,'BRIDGE_BUILD_NOT_CLEAN');require(build['target'].endswith(Path(c['api']).name),'BRIDGE_TARGET');require(comparison['cases']==c['cases'] and comparison['matched']==c['cases'] and comparison['failed']==0,'SETUP_COMPARISON_NOT_CLEAN')
        out[str(bot)]={'bridge_sha256':sha(bridge),'api_sha256':sha(api),'receipt_sha256':sha(receipt),'setup_cases':comparison['cases'],'setup_matched':comparison['matched'],'setup_failed':comparison['failed'],'build_errors':build['errors'],'build_warnings':build['warnings'],'mapped_fields':len(c['fields'])}
    result={'bots':out,'native_setup_scope':'profile -> context -> preparation only','whole_ea_complete':False,'remaining':['OnInit exact ordering and account/license gate','OnTick/event bindings and outer dispatcher remainder','complete paired MT5 EA comparison','UI/resource and restart evidence']}
    if a.output:a.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(result,ensure_ascii=False))
if __name__=='__main__':main()
