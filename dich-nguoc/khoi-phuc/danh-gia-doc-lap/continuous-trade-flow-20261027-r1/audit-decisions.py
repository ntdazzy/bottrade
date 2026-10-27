"""Record native exit addresses for the joined control cases. Usage: BOT RUN."""
import importlib.util,json,sys,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
spec=importlib.util.spec_from_file_location('joined_decision_audit',ROOT/'cong-cu/kiem-luong-danh-gia-giao-dich.py')
data=importlib.util.module_from_spec(spec);spec.loader.exec_module(data)
bot=int(sys.argv[1]);folder=ROOT/f'bot-cua-toi-{bot}/bang-chung/kiem-quan-ly-vi-the'/sys.argv[2]
tape=data.Reader((folder/'sdk-tape.bin').read_bytes());tape.take('3i')
original=data.Original(bot,data.PARTS[bot].news.news.news.news.cast_values(folder/'cast-values.bin'))
original.cast_calls=original.queue_clears=0;reports=[]
for case in data.cases(bot):
    assert tape.take('i')[0]==case['id'];block=tape.block()
    if not case['tag'].startswith('joined-'):continue
    result=original.run(case,block);decision=struct.unpack('<Q',result[-8:])[0]
    expected=1 if case['tag']=='joined-same-bar' else 0
    reports.append(dict(bot=bot,case=case['id'],tag=case['tag'],end_rva=hex(original.m.reg_read(original.x.UC_X86_REG_RIP)-original.base),decision=decision,fixture_reached_expected_branch=decision==expected))
assert all(row['fixture_reached_expected_branch'] for row in reports),'CONTROL_FIXTURE_DID_NOT_REACH_BRANCH'
target=folder/'decision-audit.json'
with target.open('x',encoding='utf-8',newline='\n') as file:json.dump(reports,file,ensure_ascii=False,indent=2)
print(json.dumps(reports))
