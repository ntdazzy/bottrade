"""Read35 seeded MQL5 trade fields from a verified known-source class capture.

Usage: kiem-thu-tu-truong-lenh.py CAPTURE_RUN_DIRECTORY
Reads only the probe directory and reference seed. Creates trade-layout.json once.
Does not read a terminal process or send a request.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[1]
REFERENCE=ROOT/'doi-chung-mt5/thu-tu-truong-lenh-20261024/layout-dst-r1/trade-layout.json'
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('run',type=Path);a=ap.parse_args()
    out=a.run.resolve()
    if not out.is_relative_to((ROOT/'doi-chung-mt5').resolve()):raise ValueError('PROBE_OUTSIDE_EVIDENCE_DIRECTORY')
    if (out/'trade-layout.json').exists():raise FileExistsError('LAYOUT_ALREADY_EXISTS')
    capdir=out/'captures/library';cap=json.loads((capdir/'capture.json').read_text());cal=json.loads((out/'calibration.json').read_text())
    if not cal['runner_verified'] or not cal['only_anchor_executed'] or cap['errors']:raise ValueError('CAPTURE_NOT_VERIFIED')
    regions=[]
    for region in cap['regions']:
        path=capdir/region['file']
        if sha(path)!=region['sha256']:raise ValueError('CAPTURE_REGION_CHANGED')
        regions.append((region,path.read_bytes()))
    region,raw=next((r,d) for r,d in regions if r['kind']=='mutable_program_data')
    def unique(needle):
        locations=[];start=0
        while (start:=raw.find(needle,start))>=0:locations.append(start);start+=1
        if len(locations)!=1:raise ValueError('SEED_NOT_UNIQUE '+str(locations))
        return locations[0]-4
    positions={'request':unique(struct.pack('<Q',0x1122334455667788)),
               'result':unique(struct.pack('<Q',0x1234567812345678)),
               'check':unique(struct.pack('<d',1301.25))}
    def read(address,n):
        for r,data in regions:
            if r['base']<=address and address+n<=r['base']+len(data):return data[address-r['base']:address-r['base']+n]
        raise ValueError('READ_OUTSIDE_CAPTURE')
    reference=json.loads(REFERENCE.read_text());layouts={}
    for key,start in positions.items():
        fields=[]
        for field in reference['layouts'][key]['fields']:
            offset=field['offset'];kind=field['kind']
            if kind=='s':
                ptr=struct.unpack_from('<Q',raw,start+offset+4)[0];n=struct.unpack('<I',read(ptr-4,4))[0]
                if n>1000:raise ValueError('SEED_STRING_TOO_LONG')
                value=read(ptr,2*n).decode('utf-16-le')
            else:value=struct.unpack_from('<'+kind,raw,start+offset)[0]
            if value!=field['value']:raise ValueError('FIELD_NOT_MATCHED '+key+'.'+field['name'])
            fields.append(dict(field))
        layouts[key]={'captured_address':hex(region['base']+start),'fields':fields}
    sources={}
    for name,digest in cal['source_sha256'].items():
        path=out/name
        if sha(path)!=digest:raise ValueError('PROBE_SOURCE_CHANGED '+name)
        sources[str(path.relative_to(ROOT)).replace('\\','/')]=digest
    request=positions['request'];check=positions['check']
    end_candidates=[n for n in range(check+64,min(check+512,len(raw))) if raw[n]==0xab]
    if len(end_candidates)!=1:raise ValueError('END_MARKER_NOT_UNIQUE')
    proof=dict(status='known-source-class-seed-executed-capture-verified',capture_pid=cap['pid'],
               only_anchor_executed=True,runner_verified=True,engine_sha256=cal['engine_sha256'],
               source_sha256=sources,data_region=region,reference_seed_sha256=sha(REFERENCE),
               relative_native_storage_bases={k:v-request for k,v in positions.items()},
               end_marker_offset=end_candidates[0]-request,layouts=layouts,
               scope='35 actual seeded fields and relative class-member positions. No trading request sent; native storage offsets are not logical sizeof.')
    with (out/'trade-layout.json').open('x',encoding='utf-8') as f:json.dump(proof,f,ensure_ascii=False,indent=2)
    print(json.dumps({'fields':sum(len(v['fields']) for v in layouts.values()),'member_bases':proof['relative_native_storage_bases'],'end_marker':proof['end_marker_offset']}))
if __name__=='__main__':main()
