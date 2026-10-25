"""Print captured instructions, annotating program addresses with correct RVAs.
Usage: xem-quan-ly-goc.py BOT BEGIN END [BEGIN END ...] (hexadecimal numbers).
Default reads the manager analysis. --full-snapshot reads other stored native functions.
No EX5, terminal or source is modified.
"""
import argparse,json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
BASES={1:0x23e5aa10000,3:0x17156250000}
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('bounds',nargs='+');p.add_argument('--full-snapshot',action='store_true');a=p.parse_args()
    if len(a.bounds)%2:p.error('BEGIN/END must be supplied in pairs')
    ranges=[tuple(int(x,16) for x in a.bounds[n:n+2]) for n in range(0,len(a.bounds),2)]
    if not all(0<=lo<hi<0x4000000 for lo,hi in ranges):p.error('Invalid instruction range')
    path=ROOT/('bot-cua-toi-'+str(a.bot))/'phan-tich/dong-vi-the/management-20261025-r1/analysis.json'
    data=json.loads(path.read_text());base=BASES[a.bot]
    rows=[r for f in data['functions'] for r in f['instructions']]
    if a.full_snapshot:
        import hashlib,importlib.util
        source=ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py';spec=importlib.util.spec_from_file_location('view_snapshot_entry',source)
        entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry);runner=entry.Original(a.bot)
        if runner.base!=base:raise ValueError('CAPTURE_BASE_DIFFERS')
        import capstone
        folder='luot-20261023-data-v2' if a.bot==1 else 'luot-20261023-data'
        metadata=ROOT/('bot-cua-toi-'+str(a.bot))/'phan-tich'/folder/'metadata/import.json'
        functions=json.loads(metadata.read_text())['functions'];decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);rows=[]
        for fn in functions:
            start,end=int(fn['begin_rva'],16),int(fn['end_rva'],16)
            if not any(start<hi and lo<end for lo,hi in ranges):continue
            raw=bytes(runner.m.mem_read(base+start,end-start))
            print('FUNCTION %#x..%#x snapshot_sha256=%s'%(start,end,hashlib.sha256(raw).hexdigest()))
            rows.extend(dict(rva=hex(ins.address-base),mnemonic=ins.mnemonic,operands=ins.op_str) for ins in decoder.disasm(raw,base+start))
    if any(not any(lo<=int(row['rva'],16)<hi for row in rows) for lo,hi in ranges):p.error('Range has no captured instructions; check its bounds or use --full-snapshot')
    def annotate(match):
        value=int(match.group(),16)
        return match.group()+('[RVA=%#x]'%(value-base) if base<=value<base+0x4000000 else '')
    for lo,hi in ranges:
        print('RANGE %#x..%#x (end excluded); base=%#x'%(lo,hi,base))
        for row in rows:
            if lo<=int(row['rva'],16)<hi:
                print(row['rva'],row['mnemonic'],re.sub('0x[0-9a-fA-F]+',annotate,row['operands']))
if __name__=='__main__':main()
