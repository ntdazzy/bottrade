"""Check captured direct MT5 calls of compiled AmericanDST against original results.

Usage: kiem-ma-bien-dich-gio-mua-he.py BOT RUN PROBE_RUN
PROBE_RUN must be a verified known-source calibration. It never opens MT5.
Only the probe marker Print is omitted from comparison; all function API arguments
must consume the original test fixtures exactly, including final result and trace.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys
import time

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('direct_dst',Path(__file__).with_name('kiem-gio-mua-he-bot-1-3.py'))
dst=importlib.util.module_from_spec(spec);spec.loader.exec_module(dst)
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

class Direct(dst.Original):
    def __init__(self,bot,fixtures,probe):
        sys.path.insert(0,str(ROOT.parent/'.local/claude-recovery-20261023/python'))
        import unicorn
        from unicorn import x86_const
        self.uc,self.x=unicorn,x86_const;self.m=unicorn.Uc(unicorn.UC_ARCH_X86,unicorn.UC_MODE_64)
        self.bot=bot;self.fixtures=fixtures;self.marker='EX5_API_PROBE:AmericanDST'+str(bot)
        self.marker_count=0;self.regions=[]
        self.cal=json.loads((probe/'calibration.json').read_text());cap=json.loads((probe/'captures/library/capture.json').read_text())
        if not self.cal['runner_verified'] or not self.cal['only_anchor_executed'] or cap['errors']:raise ValueError('PROBE_NOT_VERIFIED')
        for region in cap['regions']:
            path=probe/'captures/library'/region['file'];raw=path.read_bytes()
            if sha(path)!=region['sha256']:raise ValueError('PROBE_REGION_CHANGED')
            self.m.mem_map(region['base'],region['bytes']);self.m.mem_write(region['base'],raw);self.regions.append((region,raw))
        self.base=next(r['base'] for r,_ in self.regions if r['kind']=='executable' and r['sha256']==self.cal['code_sha256'])
        target=next(f for f in self.cal['functions'] if f['markers']==['AmericanDST'+str(bot)])
        self.fn=int(target['rva'],16);dst.FN[bot]=self.fn
        self.ranges=[(int(f['rva'],16),int(f['end_rva'],16)) for f in self.cal['functions'] if not f['markers'] or f is target]
        eb=int(self.cal['engine_base'],16)
        self.apis={eb+0x7d1c40:21,eb+0x7d1f60:22,eb+0xaa9970:23,eb+0x7b49f0:24,eb+0x7cd370:25,
                   eb+0x7d1190:100,eb+0x7d1200:101}
        for page in {address&~0xfff for address in self.apis}:self.m.mem_map(page,4096)
        for address in self.apis:
            self.m.mem_write(address,b'\xc3');self.m.hook_add(unicorn.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.mem_map(0x50000000,0x20000);self.m.mem_map(0x60000000,4096);self.m.mem_map(0x70000000,0x200000)
        self.m.hook_add(unicorn.UC_HOOK_CODE,self.visit)
    def call(self,m,address,size,user):
        if self.apis[address]==24:
            x=self.x
            if (m.reg_read(x.UC_X86_REG_RDX),m.reg_read(x.UC_X86_REG_R8),m.reg_read(x.UC_X86_REG_R9))==(2,1,0x590008):
                sp=m.reg_read(x.UC_X86_REG_RSP);pointer=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
                if self.text(pointer)==self.marker:self.marker_count+=1;return
        return super().call(m,address,size,user)

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('probe',type=Path);a=ap.parse_args()
    if not __import__('re').fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    probe=a.probe.resolve()
    if not probe.is_relative_to((ROOT/'doi-chung-mt5').resolve()):raise ValueError('PROBE_OUTSIDE_PROJECT')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-gio-mua-he'/a.run
    if (out/'direct-compiled-run.json').exists():raise FileExistsError('DIRECT_RESULTS_EXIST')
    comparison=json.loads((out/'comparison.json').read_text())
    if comparison['failed'] or not comparison['ordered_traces_byte_equal']:raise ValueError('ORIGINAL_COMPARISON_NOT_VERIFIED')
    for name,digest in comparison['hashes'].items():
        if sha(out/name)!=digest:raise ValueError('ORIGINAL_CHECK_CHANGED '+name)
    source=ROOT/f'bot-cua-toi-{a.bot}/source/MQL5/Include/bot-cua-toi-{a.bot}/Bot{a.bot}AmericanDST.mqh'
    build=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/bien-dich/b{a.bot}-american-dst-01/bien-nhan.json'
    receipt=json.loads(build.read_text(encoding='utf-8-sig'));relative=f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}AmericanDST.mqh'
    if sha(source)!=receipt['sources_sha256'][relative]:raise ValueError('DIRECT_SOURCE_NOT_CURRENT_TESTED_SOURCE')
    rows=json.loads((out/'cases.json').read_text());original=Direct(a.bot,dst.read_fixtures(out/'api-fixtures.bin',len(rows)),probe)
    start=time.monotonic();values=[];traces=bytearray()
    for row in rows:
        try:values.append(original.run(row))
        except Exception as error:raise RuntimeError(f'case={row["id"]} {error}') from error
        traces.extend(original.trace_bytes)
    if original.marker_count!=len(rows):raise ValueError('DIRECT_MARKER_COUNT_DIFFERS')
    raw=struct.pack('<3i',dst.MAGIC,1,len(values))+b''.join(struct.pack('<3iQ',*r) for r in values)
    results_equal=raw==(out/'original-results.bin').read_bytes();trace_equal=bytes(traces)==(out/'original-trace.bin').read_bytes()
    (out/'direct-compiled-results.bin').write_bytes(raw);(out/'direct-compiled-trace.bin').write_bytes(traces)
    result=dict(cases=len(rows),results_byte_equal=results_equal,ordered_trace_byte_equal=trace_equal,
                seconds=round(time.monotonic()-start,2),compiled_function_rva=hex(original.fn),probe=str(probe.relative_to(ROOT)),
                probe_calibration_sha256=sha(probe/'calibration.json'),captured_code_sha256=original.cal['code_sha256'],
                source_sha256=sha(source),original_results_sha256=sha(out/'original-results.bin'),
                direct_results_sha256=sha(out/'direct-compiled-results.bin'),direct_trace_sha256=sha(out/'direct-compiled-trace.bin'),
                scope='Actual direct-call compiled body captured from the known-source library, original measured fixtures and cases. One probe marker Print omitted. First no-write date conversion, actual platform errors and allocation failures remain open.')
    with (out/'direct-compiled-run.json').open('x',encoding='utf-8') as f:json.dump(result,f,ensure_ascii=False,indent=2)
    print(json.dumps(result));raise SystemExit(not results_equal or not trace_equal)
if __name__=='__main__':main()
