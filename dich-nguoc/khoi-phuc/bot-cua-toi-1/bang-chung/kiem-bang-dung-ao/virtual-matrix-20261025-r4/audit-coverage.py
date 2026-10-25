"""Recheck the recorded virtual-stop run and intersect executed instruction sets."""
import hashlib
import importlib.util
import json
from pathlib import Path
import struct

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[3]
spec=importlib.util.spec_from_file_location('matrix',ROOT/'cong-cu/kiem-bang-dung-ao-day-du-bot-1.py')
matrix=importlib.util.module_from_spec(spec);spec.loader.exec_module(matrix)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
baseline=json.loads((HERE/'baseline.json').read_text())
matrix.check_identity(baseline,matrix.identity())
rows=matrix.cases()
assert (HERE/'cases.bin').read_bytes()==matrix.encode(rows)
records=matrix.read_fixtures(HERE/'api-fixtures.bin',rows)
runner=matrix.Original(records)
normal=[c for c in rows if not c['fatal']]
raw=bytearray(struct.pack('<3i',matrix.MAGIC,matrix.VERSION,len(normal)))
for case in normal:raw+=runner.run_case(case)
assert raw==(HERE/'original-results.bin').read_bytes()==(HERE/'mql5-results.bin').read_bytes()
fault_path=HERE/'fatal-checks/virtual-faults-20261025-r3/summary.json'
fault=json.loads(fault_path.read_text())
assert fault['matrix_tool_sha256']==baseline['tool_sha256']
assert fault['matrix_baseline_sha256']==sha(HERE/'baseline.json')
checks=[];extra=[];missing_rows=[]
analysis=json.loads((matrix.smoke.ANALYSIS/'analysis.json').read_text())
for lo,(_,instructions) in runner.ranges.items():
    normal_seen=runner.covered[lo]
    fatal_seen={int(v,16) for v in fault['covered_original_instructions'].get(hex(lo),[])}
    seen=normal_seen|fatal_seen
    extra.extend(sorted(seen-instructions))
    missing=instructions-seen
    checks.append(dict(rva=hex(lo),instructions=len(instructions),normal_executed=len(normal_seen&instructions),
        with_fatal_executed=len(seen&instructions),missing=[hex(v) for v in sorted(missing)]))
    function=next(x for x in analysis['functions'] if int(x['rva'],16)==lo)
    missing_rows.extend(x for x in function['instructions'] if int(x['rva'],16) in missing)
assert not extra
report=dict(checks=checks,fresh_full_native_result_sha256=hashlib.sha256(raw).hexdigest(),
    matrix_tool_sha256=baseline['tool_sha256'],fatal_summary_sha256=sha(fault_path),
    audit_tool_sha256=sha(Path(__file__)),extra_addresses=[],whole_bot_complete=False,
    limits=['Instruction coverage is scoped to four captured helper bodies and these cases.',
        'Unexecuted instructions remain listed; no full-function or whole-EA completeness claim.'])
with (HERE/'coverage-audit.json').open('x',encoding='utf-8') as stream:json.dump(report,stream,indent=2)
with (HERE/'missing-native.txt').open('x',encoding='utf-8') as stream:
    for row in missing_rows:stream.write(row['rva']+' '+row['mnemonic']+' '+row['operands']+'\n')
print(json.dumps(dict(normal_cases=len(normal),executed_with_faults=sum(c['with_fatal_executed'] for c in checks),
    captured_instructions=sum(c['instructions'] for c in checks),missing=len(missing_rows),extra_addresses=0)))
