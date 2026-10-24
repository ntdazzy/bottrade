"""Verify Tick bid/ask offsets and POINT/FREEZE constants from known-source code.

Usage: kiem-truong-gia-tick.py PROBE_RUN_DIRECTORY
Append tick-fields.json to a completed Anchor-only calibration. No MT5 or orders.
Reject code shapes not explicitly understood; do not infer offsets from names.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sys

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT.parent/'.local/claude-recovery-20261023/python'))
import capstone

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)
def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('probe',type=Path);a=parser.parse_args();out=a.probe.resolve()
    require(out.is_relative_to(ROOT/'doi-chung-mt5') and not (out/'tick-fields.json').exists(),'OUTPUT_MUST_BE_NEW_PROOF_IN_PROBE')
    c=read(out/'calibration.json');capture=read(out/'captures/library/capture.json');engine=read(out/'engine-observed.json');build=read(out/'build.json')
    require(c['runner_verified'] and c['only_anchor_executed'] and c['engine_sha256']==engine['engine_sha256']=='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb','CALIBRATION_NOT_VERIFIED')
    require(capture['pid']==engine['pid'] and not capture['errors'],'CAPTURE_IDENTITY_DIFFERS')
    for row in build['builds']:
        require(row['errors']==row['warnings']==0 and sha(out/(row['name']+'.mq5'))==row['source_sha256'] and sha(out/(row['name']+'.ex5'))==row['binary_sha256'],'BUILD_CHANGED')
    for name,digest in c['source_sha256'].items():require(sha(out/name)==digest,'SOURCE_CHANGED')
    for region in capture['regions']:require(sha(out/'captures/library'/region['file'])==region['sha256'],'CAPTURE_BYTES_CHANGED')
    code=next(r for r in capture['regions'] if r['kind']=='executable' and r['bytes']>=8192);raw=(out/'captures/library'/code['file']).read_bytes();md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64)
    fields={};details={};all_lines=[]
    for marker in ['TickBid','TickAsk','CancelPoint','CancelFreeze']:
        fn=next(f for f in c['functions'] if f['markers']==[marker]);begin=int(fn['rva'],16);end=int(fn['end_rva'],16);instructions=list(md.disasm(raw[begin:end],code['base']+begin));lines=[f'{i.address-code["base"]:#x} {i.mnemonic} {i.op_str}' for i in instructions];all_lines.extend([marker,*lines,''])
        target='0x7c2c10' if marker.startswith('Tick') else ('0x7c2890' if marker=='CancelPoint' else '0x7c2970')
        call=next(call for call in fn['calls'] if call['target_rva']==target);at=next(i for i,v in enumerate(instructions) if v.address-code['base']==int(call['site_rva'],16))
        if marker.startswith('Tick'):
            prior=[(i,re.fullmatch(r'r8, \[rsp \+ (0x[0-9a-f]+)\]',v.op_str)) for i,v in enumerate(instructions[:at]) if v.mnemonic=='lea']
            prior=[(i,m) for i,m in prior if m];require(len(prior)==1,'TICK_OUTPUT_POINTER_NOT_UNIQUE');base_index,match=prior[0];base=int(match[1],16)
            require(instructions[at+1].mnemonic=='test' and instructions[at+1].op_str=='al, al' and instructions[at+2].mnemonic=='je','TICK_SUCCESS_BRANCH_NOT_RECOGNIZED')
            load=instructions[at+3];match=re.fullmatch(r'(xmm\d+), qword ptr \[rsp \+ (0x[0-9a-f]+)\]',load.op_str)
            require(load.mnemonic=='movsd' and match is not None,'TICK_FIELD_LOAD_NOT_RECOGNIZED');field=int(match[2],16)
            require(all(not (v.mnemonic in ['push','pop'] or (v.op_str.startswith('rsp,') and v.mnemonic in ['add','sub','mov','lea'])) for v in instructions[base_index:at+4]),'STACK_CHANGED_AROUND_TICK_FIELD')
            require(instructions[at+4].mnemonic=='movaps' and instructions[at+4].op_str=='xmm0, '+match[1],'TICK_FIELD_NOT_RETURNED')
            name='bid' if marker=='TickBid' else 'ask';fields[name]=field-base;details[marker]=dict(function_rva=fn['rva'],call_site=call['site_rva'],api_target_rva=target,tick_stack_offset=base,field_stack_offset=field,field_offset=field-base)
        else:
            value=16 if marker=='CancelPoint' else 32;require(call['r8_constant']==value,'PROPERTY_CONSTANT_DIFFERS')
            details[marker]=dict(function_rva=fn['rva'],call_site=call['site_rva'],api_target_rva=target,property=value)
    require(fields=={'bid':8,'ask':16},'ORIGINAL_TICK_FIELD_MATCH_NOT_ESTABLISHED')
    originals=[]
    for bot,fn in [(1,'0x34150'),(3,'0x32450')]:
        path=ROOT/f'bot-cua-toi-{bot}/phan-tich/huy-lenh-cho/cancel-20261024-r1/analysis.json';analysis=read(path);row=next(v for v in analysis['functions'] if v['rva']==fn);ins=row['instructions'];ops=[v['mnemonic']+' '+v['operands'] for v in ins]
        require('lea r8, [rsp + 0x60]' in ops and 'movsd xmm0, qword ptr [rsp + 0x70]' in ops and 'subsd xmm0, qword ptr [rsp + 0x68]' in ops,'ORIGINAL_TICK_READ_SHAPE_DIFFERS')
        originals.append(dict(bot=bot,native_rva=fn,analysis_sha256=sha(path),tick_output_stack_offset=96,bid_stack_offset=104,ask_stack_offset=112,relative_offsets=fields))
    (out/'tick-fields-native.txt').write_text('\n'.join(all_lines),encoding='utf-8',newline='')
    result=dict(fields=fields,details=details,originals=originals,calibration_sha256=sha(out/'calibration.json'),tool_sha256=sha(Path(__file__)),native_listing_sha256=sha(out/'tick-fields-native.txt'),runner_verified=True,only_anchor_executed=True,scope='Known-source compiled wrappers establish MqlTick bid/ask offsets and enum constants 16/32. Original stack reads match these offsets. No original cancel runtime or broker behavior proof.')
    with (out/'tick-fields.json').open('x',encoding='utf-8') as file:json.dump(result,file,ensure_ascii=False,indent=2)
    print(json.dumps(dict(fields=fields,point_property=16,freeze_property=32,runner_verified=True)))

if __name__=='__main__':main()
