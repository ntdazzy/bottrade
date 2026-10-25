"""Print fixed management instruction ranges, annotating program addresses with correct RVAs.
Usage: xem-quan-ly-goc.py BOT BEGIN END [BEGIN END ...] (hexadecimal numbers).
Reads the existing analysis only; no EX5, terminal or code is modified.
"""
import argparse,json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
BASES={1:0x23e5aa10000,3:0x17156250000}
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('bounds',nargs='+');a=p.parse_args()
    if len(a.bounds)%2:p.error('BEGIN/END must be supplied in pairs')
    ranges=[tuple(int(x,16) for x in a.bounds[n:n+2]) for n in range(0,len(a.bounds),2)]
    if not all(0<=lo<hi<0x4000000 for lo,hi in ranges):p.error('Invalid instruction range')
    path=ROOT/('bot-cua-toi-'+str(a.bot))/'phan-tich/dong-vi-the/management-20261025-r1/analysis.json'
    data=json.loads(path.read_text());base=BASES[a.bot]
    def annotate(match):
        value=int(match.group(),16)
        return match.group()+('[RVA=%#x]'%(value-base) if base<=value<base+0x4000000 else '')
    for lo,hi in ranges:
        print('RANGE %#x..%#x (end excluded); base=%#x'%(lo,hi,base))
        for f in data['functions']:
            for row in f['instructions']:
                if lo<=int(row['rva'],16)<hi:
                    print(row['rva'],row['mnemonic'],re.sub('0x[0-9a-fA-F]+',annotate,row['operands']))
if __name__=='__main__':main()
