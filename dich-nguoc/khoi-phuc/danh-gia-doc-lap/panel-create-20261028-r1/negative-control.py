"""Recheck a measured bad implementation: nonzero byte versus its low bit."""
import hashlib,importlib.util,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
s=importlib.util.spec_from_file_location('full_panel',ROOT/'cong-cu/kiem-tao-bang-bot-1-3.py')
check=importlib.util.module_from_spec(s);s.loader.exec_module(check)
folder=Path(__file__).resolve().parent
for bot,index in [(1,27),(3,36)]:
    home=ROOT/f'bot-cua-toi-{bot}';run=home/f'bang-chung/kiem-quan-ly-vi-the/b{bot}-panel-create-20261028-r2'
    build=home/f'bang-chung/bien-dich/b{bot}-panel-create-check-20261028-r2'
    baseline=json.loads((run/'baseline.json').read_text());actual=json.loads((run/'mql5-run.json').read_text())
    receipt=json.loads((build/'bien-nhan.json').read_text(encoding='utf-8-sig'))
    source=home/f'source/MQL5/Include/bot-cua-toi-{bot}/Bot{bot}PanelCreation.mqh';current=source.read_bytes()
    good=b'(flag&1)!=0 ? 0x8b0000 : 0';bad=b'flag!=0 ? 0x8b0000 : 0'
    check.require(current.count(good)==1,'NEGATIVE_CHANGE_NOT_UNIQUE')
    rejected=current.replace(good,bad)
    name=f'Include/bot-cua-toi-{bot}/Bot{bot}PanelCreation.mqh'
    digest=hashlib.sha256(rejected).hexdigest()
    check.require(digest==baseline['sources_sha256'][name]==receipt['sources_sha256'][name],'REJECTED_SOURCE_NOT_MEASURED')
    binary=build/f'Bot{bot}PanelCreationCheck.ex5'
    check.require(check.sha(binary)==receipt['binary_sha256'] and check.sha(build/'bien-nhan.json')==actual['build_receipt_sha256'],'REJECTED_BUILD_CHANGED')
    check.require(check.sha(run/'mql5-results.bin')==actual['result_sha256'],'REJECTED_RESULTS_CHANGED')
    data=(run/'mql5-results.bin').read_bytes();rows=check.cases(bot)
    check.require(data[:12]==struct.pack('<3i',check.MAGIC,1,len(rows)),'RESULT_HEADER')
    tapes=check.cell.records(struct.pack('<i',check.cell.MAGIC)+data[4:],len(rows))
    original=check.Native(bot)
    try:original.run(rows[index],tapes[index])
    except ValueError as e:
        reason=str(e);check.require(reason.startswith('SDK_ARGUMENTS ') and 'lineopl0' in reason,'WRONG_REJECTION')
    else:raise AssertionError('BAD_SOURCE_ACCEPTED')
    with (folder/f'Bot{bot}PanelCreation.rejected.mqh.txt').open('xb') as f:f.write(rejected)
    result=dict(bot=bot,case=index,rejected=True,reason=reason,rejected_source_sha256=digest,
                current_source_sha256=check.sha(source),original_body_sha256=check.BODIES[bot][2],
                rejected_build_sha256=check.sha(binary),recorded_result_sha256=check.sha(run/'mql5-results.bin'),
                source_patch='Replace bit-0 comparison with nonzero comparison only',full_ea=False)
    check.save(folder/f'bot{bot}-negative.json',result);print(json.dumps(result))
