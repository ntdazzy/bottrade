"""Confirm virtual-stop SDK calls against the existing known-source API probe.

Usage: kiem-api-bang-dung-ao.py BOT ANALYSIS_RUN
Reads saved captures only. Creates api-contract.json once inside the selected
virtual-stop analysis. Does not run MT5 or establish runtime equivalence.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct
import sys

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT.parent/'.local/claude-recovery-20261023/python'))
import capstone

ENGINE='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb'
SDK={0x7aa0e0:'ArrayResize',0x7d1c40:'TimeCurrent',0x7c2970:'SymbolInfoInteger',
     0x7d7da0:'PositionsTotal',0x7d7df0:'PositionGetTicket',0x7d7fc0:'PositionGetInteger',
     0x7b49f0:'Print dispatcher',0x3959a0:'runtime array fault'}

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def require(ok,message):
    if not ok:raise ValueError(message)

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('analysis_run')
    args=parser.parse_args()
    require(bool(re.fullmatch('[a-z0-9-]{1,48}',args.analysis_run)),'INVALID_ANALYSIS_RUN')
    folder=ROOT/f'bot-cua-toi-{args.bot}/phan-tich/dong-vi-the'/args.analysis_run
    output=folder/'api-contract.json'
    require(folder.is_dir() and not output.exists(),'ANALYSIS_MISSING_OR_CONTRACT_EXISTS')
    analysis=json.loads((folder/'analysis.json').read_text())
    calibration_path=ROOT/'ban-do-bot-1-3/luot-20261025-r4/api-calibration.json'
    calibration=json.loads(calibration_path.read_text())
    reference_path=Path(calibration['probe_analysis']);reference=json.loads(reference_path.read_text())
    source=Path(calibration['source'])
    require(sha(reference_path)==calibration['probe_analysis_sha256'] and sha(source)==calibration['source_sha256'],'KNOWN_SOURCE_REFERENCE_CHANGED')
    require(reference['engine_sha256'].lower()==analysis['engine_sha256']==calibration['engine_sha256']==ENGINE,'ENGINE_IDENTITY_DIFFERS')
    capture_path=reference_path.with_name('capture.json');capture=json.loads(capture_path.read_text())
    for region in capture['regions']:
        require(sha(capture_path.parent/region['file'])==region['sha256'],'PROBE_CAPTURE_CHANGED '+region['file'])
    code=max((r for r in capture['regions'] if r.get('kind')=='executable'),key=lambda r:r['bytes'])
    raw=(capture_path.parent/code['file']).read_bytes();md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64)
    functions=[f for f in reference['functions'] if f['markers']==['ArrayResizeDouble']]
    require(len(functions)==1,'ARRAY_RESIZE_REFERENCE_NOT_UNIQUE')
    fn=functions[0];lo,hi=int(fn['rva'],16),int(fn['end_rva'],16)
    instructions=list(md.disasm(raw[lo:hi],code['base']+lo))
    sdk_base=int(reference['engine_base'],16)
    resize=next(c for c in fn['calls'] if c['target_rva']=='0x7aa0e0')
    at=next(i for i,row in enumerate(instructions) if row.address-code['base']==int(resize['site_rva'],16))
    before=instructions[:at]
    require(instructions[at].mnemonic=='call' and instructions[at].op_str=='rax','RESIZE_CALL_SHAPE_CHANGED')
    require(any(r.mnemonic=='movabs' and r.op_str==f'rax, {sdk_base+0x7aa0e0:#x}' for r in before),'RESIZE_TARGET_CHANGED')
    for mnemonic,operands in [('movabs','rax, 0x800010058'),('mov','r8d, esi'),('xor','r9d, r9d'),('mov','rdx, rbx')]:
        require(any(r.mnemonic==mnemonic and r.op_str==operands for r in before),'RESIZE_ARGUMENT_SHAPE_CHANGED '+operands)
    source_text=source.read_text(encoding='utf-8-sig')
    require('double a[]; return ArrayResize(a,(int)k);' in source_text,'RESIZE_SOURCE_BODY_CHANGED')
    loader=importlib.util.spec_from_file_location('virtual_entry',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py')
    entry=importlib.util.module_from_spec(loader);loader.loader.exec_module(entry);original=entry.Original(args.bot)
    loader=importlib.util.spec_from_file_location('virtual_validation',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py')
    validation=importlib.util.module_from_spec(loader);loader.loader.exec_module(validation)
    require(validation.original_hash(args.bot)==analysis['original_ex5_sha256'],'ORIGINAL_EX5_CHANGED')
    meta_run='luot-20261023-data-v2' if args.bot==1 else 'luot-20261023-data'
    meta=json.loads((ROOT/f'bot-cua-toi-{args.bot}/phan-tich'/meta_run/'metadata/import.json').read_text())
    original_sdk_base=int(meta['engine']['engine_base'],16);targets=set()
    for function in analysis['functions']:
        begin,end=int(function['rva'],16),int(function['end_rva'],16)
        require(hashlib.sha256(bytes(original.m.mem_read(original.base+begin,end-begin))).hexdigest()==function['native_bytes_sha256'],'ORIGINAL_NATIVE_FUNCTION_CHANGED')
        for row in function['instructions']:
            if row['mnemonic']=='movabs':
                value=int(row['operands'].split(', ')[1],16)
                if original_sdk_base<=value<original_sdk_base+0x1000000:targets.add(value-original_sdk_base)
    require(targets==set(SDK),'ORIGINAL_SDK_TARGET_SET_DIFFERS '+str(sorted(hex(v) for v in targets)))
    array=0x6a3c0 if args.bot==1 else 0x1d6d10
    header=struct.unpack('<Q',original.m.mem_read(original.base+array,8))[0]
    require(header==0x800010055,'ORIGINAL_LONG_ARRAY_DESCRIPTOR_DIFFERS')
    time=next(f for f in reference['functions'] if f['markers']==['TimeCurrent'])
    require(any(c['target_rva']=='0x7d1c40' for c in time['calls']),'TIME_CURRENT_REFERENCE_DIFFERS')
    report=dict(bot=args.bot,engine_sha256=ENGINE,original_ex5_sha256=analysis['original_ex5_sha256'],
        analysis_sha256=sha(folder/'analysis.json'),calibration_sha256=sha(calibration_path),
        probe_analysis_sha256=sha(reference_path),probe_source_sha256=sha(source),probe_capture_sha256=sha(capture_path),
        array_resize_reference=dict(function_rva=fn['rva'],call_rva=resize['site_rva'],sdk_rva='0x7aa0e0',
            function_bytes_sha256=hashlib.sha256(raw[lo:hi]).hexdigest(),source_body='double a[]; return ArrayResize(a,(int)k);',
            arguments=['RCX=context','RDX=array descriptor','R8D=int32 requested length','R9D=0 reserve'],
            instructions=[dict(rva=hex(r.address-code['base']),bytes=r.bytes.hex(),text=r.mnemonic+' '+r.op_str) for r in instructions]),
        original_array=dict(descriptor_rva=hex(array),header=hex(header),element_bytes=8,element_type='0x55 signed int64',
            length_offset=8,data_pointer_offset=28,series_bit='0x10 in flags at +2'),
        sdk_targets={hex(k):v for k,v in SDK.items()},tool_sha256=sha(Path(__file__)),runtime_verified=False,
        limits=['Known-source call target/signature and original array header only; no fresh MT5 run.',
                'Array growth/failure effects, fatal errors and all four table algorithms still need original-versus-MQL5 checks.',
                'The reference resizes a double array; the original descriptor establishes the signed-int64 element type.'])
    with output.open('x',encoding='utf-8') as stream:json.dump(report,stream,ensure_ascii=False,indent=2)
    print(json.dumps(dict(bot=args.bot,sdk_targets=len(SDK),array_resize_confirmed=True,runtime_verified=False)))

if __name__=='__main__':main()
