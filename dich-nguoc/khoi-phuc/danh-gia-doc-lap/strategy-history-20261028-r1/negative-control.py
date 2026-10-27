"""Reject the measured old += implementation against the real-CPU arithmetic backend."""
import importlib.util,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];FOLDER=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('history',ROOT/'cong-cu/kiem-lich-su-chien-luoc-bot-1-3.py')
h=importlib.util.module_from_spec(s);s.loader.exec_module(h)
for bot in [1,3]:
    home=ROOT/f'bot-cua-toi-{bot}';run=home/f'bang-chung/kiem-quan-ly-vi-the/b{bot}-strategy-history-20261028-r1';build=home/f'bang-chung/bien-dich/b{bot}-strategy-history-check-20261028-r2'
    base=json.loads((run/'baseline.json').read_text());actual=json.loads((run/'mql5-run.json').read_text());receipt=json.loads((build/'bien-nhan.json').read_text(encoding='utf-8-sig'))
    old=FOLDER/f'Bot{bot}StrategyHistory.original-add.mqh.txt';name=f'Include/bot-cua-toi-{bot}/Bot{bot}StrategyHistory.mqh'
    h.require(h.sha(old)==base['sources_sha256'][name]==receipt['sources_sha256'][name],'OLD_SOURCE_NOT_MEASURED')
    h.require(h.sha(build/'bien-nhan.json')==actual['build_receipt_sha256'] and h.sha(build/f'Bot{bot}StrategyHistoryCheck.ex5')==receipt['binary_sha256'],'OLD_BUILD_CHANGED')
    h.require(h.sha(run/'mql5-results.bin')==actual['result_sha256'],'OLD_RESULTS_CHANGED')
    tapes=h.records((run/'mql5-results.bin').read_bytes(),base['cases']);case=h.cases(bot)[178];o=h.Native(bot)
    try:
        try:o.run(case,tapes[178])
        except ValueError as e:
            h.require(str(e)=='RETURN_BITS (178, 0)','WRONG_REJECTION '+str(e));reason=str(e)
        else:raise AssertionError('BAD_IMPLEMENTATION_ACCEPTED')
        result=dict(bot=bot,case=178,rejected=True,reason=reason,old_source_sha256=h.sha(old),old_mql5_return=hex(struct.unpack('<Q',tapes[178][-8:])[0]),
                    original_return_with_host_addsd=hex(o.m.reg_read(o.x.UC_X86_REG_XMM0)&h.MASK),host_cpu_calibrated_pairs=100,full_ea=False)
    finally:o.close()
    h.save(FOLDER/f'bot{bot}-negative.json',result);print(json.dumps(result))
