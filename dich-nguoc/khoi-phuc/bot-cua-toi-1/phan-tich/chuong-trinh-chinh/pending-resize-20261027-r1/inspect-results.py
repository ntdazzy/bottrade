"""Read-only decoded resize comparison RUN."""
import argparse,importlib.util,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[4]
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
base=module('resize_decode_base',ROOT/'danh-gia-doc-lap/evaluation-stops-20261027-r1/inspect-results.py')
tool=module('resize_decode_tool',ROOT/'bot-cua-toi-1/tests/check-evaluation-pending-resize.py')
class Reader(base.Reader):
    def row(self):
        self.fields=[];lo=self.at;cid=self.take('i','id');j=0
        while True:
            label='event.'+str(j);kind=self.take('i',label+'.kind')
            if kind==0:break
            tool.require(0<kind<=44 and j<600,'EVENT_FORMAT')
            for k in range(6):self.take('Q',label+'.word'+str(k))
            for k in range(3):self.text(label+'.text'+str(k))
            if kind in [19,20,21,40]:self.snapshot(label+'.state')
            j+=1
        self.snapshot('final')
        self.take('Q','selected_order');self.take('Q','last_ticket')
        for i in range(100):
            for k in range(2):self.take('Q',f'table.{i}.{k}')
        self.take('Q','strategy_index')
        for i in range(8):self.take('Q','volume.'+str(i))
        self.text('symbol');return cid,lo,self.at,list(self.fields)
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('run');a=ap.parse_args();inputs=tool.cases()
    folder=ROOT/'bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the'/a.run;readers=[Reader((folder/n).read_bytes()) for n in ['original-results.bin','mql5-results.bin']]
    for r in readers:
        for value,name in [(tool.MAGIC,'magic'),(1,'version'),(len(inputs),'count'),(200,'table-fields')]:tool.require(r.take('i',name)==value,'HEADER')
    failed=[];matched=0
    for c in inputs:
        rows=[r.row() for r in readers];tool.require(rows[0][0]==rows[1][0]==c['id'],'ROW_ID')
        if readers[0].raw[rows[0][1]:rows[0][2]]==readers[1].raw[rows[1][1]:rows[1][2]]:matched+=1;continue
        if len(failed)<8:
            left={n:v for _,_,n,v in rows[0][3]};right={n:v for _,_,n,v in rows[1][3]}
            failed.append(dict(id=c['id'],tag=c['tag'],differences={n:[v,right.get(n)] for n,v in left.items() if v!=right.get(n)}))
    for r in readers:tool.require(r.at==len(r.raw),'TRAILING_BYTES')
    print(json.dumps(dict(cases=len(inputs),matched=matched,failed=len(inputs)-matched,first_failures=failed),ensure_ascii=False))
if __name__=='__main__':main()
