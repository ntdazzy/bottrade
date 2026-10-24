"""Bind position-scan SDK calls and distance constants to an Anchor-only probe.

Usage: kiem-api-chon-vi-the.py PROBE_RUN_DIRECTORY
Writes a new api-contract.json; starts no MT5 and changes no original files.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import re

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('close_api',Path(__file__).with_name('kiem-api-dong-vi-the.py'))
api=importlib.util.module_from_spec(spec);spec.loader.exec_module(api)
sha=api.sha;read=api.read;require=api.require

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
    journal=(out/f'runner/api-{out.name}.log').read_text()
    expected=dict(SYMBOL_TRADE_STOPS_LEVEL=31,SYMBOL_TRADE_FREEZE_LEVEL=32,SYMBOL_POINT=16)
    require({tuple(map(int,v.split('|'))) for v in re.findall(r'SCAN_ENUMS:([0-9|]+)',journal)}=={tuple(expected.values())},'DISTANCE_ENUMS_DIFFER')
    checks={'ScanTotal':(0x7d7da0,None,None),'ScanTicket':(0x7d7df0,None,None),'ScanStops':(0x7c2970,'r8_constant',31),
            'CloseMagic':(0x7d7fc0,'rdx_constant',12),'CloseType':(0x7d7fc0,'rdx_constant',2),'CloseVolume':(0x7d7f70,'rdx_constant',3),'CloseSymbol':(0x7d8010,None,None)}
    sites={}
    for name,(target,key,value) in checks.items():
        fn=next(f for f in c['functions'] if f['markers']==[name]);calls=[call for call in fn['calls'] if int(call['target_rva'],16)==target]
        require(len(calls)==1 and (key is None or calls[0][key]==value),'SDK_TARGET_OR_PROPERTY_DIFFERS '+name)
        sites[name]=dict(function_rva=fn['rva'],sdk_rva=hex(target),call_site=calls[0]['site_rva'],property=value)
    originals=[]
    for bot in [1,3]:
        path=ROOT/f'bot-cua-toi-{bot}/phan-tich/dong-vi-the/scan-20261025-r1/analysis.json';analysis=read(path)
        folder=ROOT/analysis['source'].rsplit('/',1)[0];meta=read(folder/'metadata/import.json');sdk_base=int(meta['engine']['engine_base'],16)
        targets=set()
        for function in analysis['functions']:
            for row in function['instructions']:
                if row['mnemonic']=='movabs':
                    target=int(row['operands'].split(', ')[1],16)
                    if sdk_base<=target<sdk_base+0x1000000:targets.add(target-sdk_base)
        require({0x7d7da0,0x7d7df0,0x7d7fc0,0x7d7f70,0x7d8010}.issubset(targets),'ORIGINAL_SCAN_TARGETS_NOT_FOUND')
        require(sha(ROOT/analysis['source'])==analysis['source_sha256'],'ORIGINAL_C_CHANGED')
        originals.append(dict(bot=bot,analysis_sha256=sha(path),original_ex5_sha256=analysis['original_ex5_sha256'],sdk_targets=sorted(hex(v) for v in targets)))
    result=dict(constants=expected,sdk_sites=sites,originals=originals,calibration_sha256=sha(out/'calibration.json'),build_sha256=sha(out/'build.json'),capture_sha256=sha(out/'captures/library/capture.json'),tool_sha256=sha(Path(__file__)),only_anchor_executed=True,runner_verified=True,
                limits=['SDK call addresses/constants only; original selector behavior and real account selection still require separate verification.'])
    with (out/'api-contract.json').open('x',encoding='utf-8') as f:json.dump(result,f,ensure_ascii=False,indent=2);f.write('\n')
    print(json.dumps(dict(constants=len(expected),sdk_wrappers=len(sites),originals=2,only_anchor_executed=True)))

if __name__=='__main__':main()
