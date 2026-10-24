"""Verify close-position constants, SDK call targets and the MathAbs mask.

Usage: kiem-api-dong-vi-the.py PROBE_RUN_DIRECTORY
Append a new api-contract.json to an Anchor-only known-source calibration.
No MT5 is started and no position/order is changed.
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

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def require(ok,message):
    if not ok:raise ValueError(message)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('probe',type=Path);a=parser.parse_args();out=a.probe.resolve()
    require(out.is_relative_to(ROOT/'doi-chung-mt5') and not (out/'api-contract.json').exists(),'OUTPUT_MUST_BE_NEW_PROOF_IN_PROBE')
    c=read(out/'calibration.json');capture=read(out/'captures/library/capture.json');engine=read(out/'engine-observed.json');build=read(out/'build.json')
    require(c['runner_verified'] and c['only_anchor_executed'] and c['engine_sha256']==engine['engine_sha256']=='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb','CALIBRATION_NOT_VERIFIED')
    require(capture['pid']==engine['pid'] and not capture['errors'],'CAPTURE_IDENTITY_DIFFERS')
    for item in build['builds']:
        require(item['errors']==item['warnings']==0 and sha(out/(item['name']+'.mq5'))==item['source_sha256'] and sha(out/(item['name']+'.ex5'))==item['binary_sha256'],'PROBE_BUILD_CHANGED')
    for name,digest in c['source_sha256'].items():require(sha(out/name)==digest,'PROBE_SOURCE_CHANGED')
    for region in capture['regions']:require(sha(out/'captures/library'/region['file'])==region['sha256'],'PROBE_CAPTURE_CHANGED')
    names=['TRADE_ACTION_DEAL','POSITION_MAGIC','POSITION_TYPE','POSITION_VOLUME','POSITION_SL','POSITION_TP','POSITION_PRICE_CURRENT','POSITION_SYMBOL','SYMBOL_BID','SYMBOL_ASK','POSITION_TYPE_BUY','POSITION_TYPE_SELL']
    expected=[1,12,2,3,6,7,5,0,1,4,0,1];journal=(out/'runner/api-close-api-r1.log').read_text()
    observed={tuple(map(int,m.split('|'))) for m in re.findall(r'CLOSE_ENUMS:([0-9|]+)',journal)}
    require(observed=={tuple(expected)},'SDK_CONSTANT_VALUES_DIFFER')
    checks={
        'CloseSelect':(0x7d7ee0,None,None),'CloseMagic':(0x7d7fc0,'rdx_constant',12),'CloseType':(0x7d7fc0,'rdx_constant',2),
        'CloseVolume':(0x7d7f70,'rdx_constant',3),'CloseSL':(0x7d7f70,'rdx_constant',6),'CloseTP':(0x7d7f70,'rdx_constant',7),
        'CloseCurrent':(0x7d7f70,'rdx_constant',5),'CloseSymbol':(0x7d8010,None,None),
        'CloseBid':(0x7c2890,'r8_constant',1),'CloseAsk':(0x7c2890,'r8_constant',4)}
    code=next(r for r in capture['regions'] if r['kind']=='executable' and r['bytes']>=8192);raw=(out/'captures/library'/code['file']).read_bytes()
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True;sites={}
    for name,(target,key,value) in checks.items():
        fn=next(f for f in c['functions'] if f['markers']==[name]);calls=[call for call in fn['calls'] if int(call['target_rva'],16)==target]
        require(len(calls)==1 and (key is None or calls[0][key]==value),'SDK_CALL_OR_PROPERTY_DIFFERS '+name)
        if name=='CloseSymbol':
            ins=list(md.disasm(raw[int(fn['rva'],16):int(fn['end_rva'],16)],code['base']+int(fn['rva'],16)));site=int(calls[0]['site_rva'],16)
            index=next(i for i,r in enumerate(ins) if r.address-code['base']==site)
            require(any(r.mnemonic=='xor' and r.op_str=='edx, edx' for r in ins[max(0,index-3):index]),'POSITION_SYMBOL_ZERO_NOT_CONFIRMED')
        sites[name]=dict(function_rva=fn['rva'],sdk_rva=hex(target),call_site=calls[0]['site_rva'],property=value)
    fn=next(f for f in c['functions'] if f['markers']==['CloseAbs']);ins=list(md.disasm(raw[int(fn['rva'],16):int(fn['end_rva'],16)],code['base']+int(fn['rva'],16)))
    index=next(i for i,r in enumerate(ins) if r.mnemonic=='andps' and r.op_str=='xmm6, xmmword ptr [rax]')
    require(ins[index-1].mnemonic=='movabs' and ins[index-1].operands[0].reg==capstone.x86_const.X86_REG_RAX,'MATH_ABS_SHAPE_CHANGED')
    mask_address=ins[index-1].operands[1].imm
    mask_region=next(r for r in capture['regions'] if r['base']<=mask_address and mask_address+16<=r['base']+r['bytes'])
    mask_raw=(out/'captures/library'/mask_region['file']).read_bytes();mask=mask_raw[mask_address-mask_region['base']:mask_address-mask_region['base']+16]
    require(mask==bytes.fromhex('ffffffffffffff7f'*2),'MATH_ABS_MASK_DIFFERS')
    spec=importlib.util.spec_from_file_location('close_entry',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py');entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
    spec=importlib.util.spec_from_file_location('close_validation',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py');validation=importlib.util.module_from_spec(spec);spec.loader.exec_module(validation)
    originals=[]
    for bot,mask_rva in [(1,0x50f10),(3,0x59170)]:
        analysis_path=ROOT/f'bot-cua-toi-{bot}/phan-tich/dong-vi-the/close-20261024-r1/analysis.json';analysis=read(analysis_path);o=entry.Original(bot)
        require(validation.original_hash(bot)==analysis['original_ex5_sha256'],'ORIGINAL_EX5_CHANGED')
        require(bytes(o.m.mem_read(o.base+mask_rva,16))==mask,'ORIGINAL_ABS_MASK_DIFFERS')
        sdk_targets=set();meta=read(ROOT/analysis['source'].rsplit('/',1)[0]/'metadata/import.json');sdk_base=int(meta['engine']['engine_base'],16)
        for function in analysis['functions']:
            begin=int(function['rva'],16);end=int(function['end_rva'],16)
            require(hashlib.sha256(bytes(o.m.mem_read(o.base+begin,end-begin))).hexdigest()==function['native_bytes_sha256'],'ORIGINAL_FUNCTION_BYTES_CHANGED')
            for row in function['instructions']:
                if row['mnemonic']=='movabs' and row['operands'].startswith('rax, '):
                    address=int(row['operands'].split(', ')[1],16)
                    if address>=sdk_base:sdk_targets.add(address-sdk_base)
        require({0x7d7ee0,0x7d7fc0,0x7d7f70,0x7d8010,0x7c2890}.issubset(sdk_targets),'ORIGINAL_SDK_TARGETS_NOT_CONFIRMED')
        originals.append(dict(bot=bot,analysis_sha256=sha(analysis_path),original_ex5_sha256=analysis['original_ex5_sha256'],abs_mask_rva=hex(mask_rva),sdk_targets=sorted(hex(v) for v in sdk_targets)))
    result=dict(constants=dict(zip(names,expected)),sdk_sites=sites,math_abs_mask_hex=mask.hex(),originals=originals,
                calibration_sha256=sha(out/'calibration.json'),build_sha256=sha(out/'build.json'),capture_sha256=sha(out/'captures/library/capture.json'),tool_sha256=sha(Path(__file__)),only_anchor_executed=True,runner_verified=True,
                limits=['SDK constants/call targets and MathAbs mask only; no original close algorithm or broker execution verified.'])
    with (out/'api-contract.json').open('x',encoding='utf-8') as f:json.dump(result,f,ensure_ascii=False,indent=2)
    print(json.dumps(dict(constants=len(names),sdk_wrappers=len(sites),originals=2,only_anchor_executed=True)))

if __name__=='__main__':main()
