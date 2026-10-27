"""Read-only decoded comparison: BOT RUN; no changes to existing evidence."""
import argparse,hashlib,importlib.util,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
path=ROOT/'cong-cu/kiem-bo-sung-muc-dung-bot-1-3.py'
spec=importlib.util.spec_from_file_location('inspect_stops',path);tool=importlib.util.module_from_spec(spec);spec.loader.exec_module(tool)
class Reader:
    def __init__(self,raw):self.raw=raw;self.at=0;self.fields=[]
    def take(self,fmt,name):
        lo=self.at;value=struct.unpack_from('<'+fmt,self.raw,lo)[0];self.at+=struct.calcsize('<'+fmt);self.fields.append((lo,self.at,name,value));return value
    def text(self,name):
        lo=self.at;k=self.take('i',name+'.kind');n=self.take('i',name+'.length');tool.require(k in [0,1] and 0<=n<=10000,'TEXT_FORMAT')
        value=self.raw[self.at:self.at+2*n].decode('utf-16-le') if k else None;self.at+=2*n;self.fields.append((lo,self.at,name,value));return value
    def snapshot(self,name):
        for key,schema in tool.SCHEMAS.items():
            for f in schema['fields']:
                label=name+'.'+key+'.'+f['name']
                if f['kind']=='s':self.text(label)
                else:self.take('Q',label)
        for f in ['stored_magic','preferred','async_mode','margin_mode','log_level']:self.take('Q',name+'.'+f)
    def events(self,name,extra):
        j=0
        while True:
            label=name+'.'+str(j);kind=self.take('i',label+'.kind')
            if kind==0:break
            tool.require(0<kind<=20 and j<400,'EVENT_FORMAT')
            for k in range(6):self.take('Q',label+'.word'+str(k))
            for k in range(3):self.text(label+'.text'+str(k))
            if extra and kind in [16,19,20]:self.snapshot(label+'.state')
            j+=1
    def row(self,fields):
        self.fields=[];lo=self.at;cid=self.take('i','id');self.events('prefix',False)
        for name in fields:self.take('Q','prefix-final.'+name)
        self.events('loop',True);self.snapshot('final')
        for name in ['enabled','magic','stop','target','unit','selected','stopped']:self.take('Q','context.'+name)
        self.text('context.symbol');return cid,lo,self.at,list(self.fields)
def main():
    ap=argparse.ArgumentParser();ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;p=tool.prefix(a.bot);inputs=tool.cases()
    readers=[Reader((folder/n).read_bytes()) for n in ['original-results.bin','mql5-results.bin']]
    for r in readers:
        for value,name in [(tool.MAGIC,'magic'),(1,'version'),(len(inputs),'count'),(len(p.FIELDS),'prefix-fields')]:tool.require(r.take('i',name)==value,'HEADER')
    failures=[];count=0
    for c in inputs:
        rows=[r.row(p.FIELDS) for r in readers];tool.require(rows[0][0]==rows[1][0]==c['id'],'ROW_ID')
        if readers[0].raw[rows[0][1]:rows[0][2]]==readers[1].raw[rows[1][1]:rows[1][2]]:count+=1;continue
        if len(failures)<8:
            left={name:value for _,_,name,value in rows[0][3]};right={name:value for _,_,name,value in rows[1][3]}
            diffs={k:[v,right.get(k)] for k,v in left.items() if v!=right.get(k)}
            failures.append(dict(id=c['id'],tag=c['tag'],input={k:v for k,v in c.items() if k!='prelude'},differences=diffs))
    for r in readers:tool.require(r.at==len(r.raw),'TRAILING_RESULT_BYTES')
    print(json.dumps(dict(cases=len(inputs),matched=count,failed=len(inputs)-count,first_failures=failures),ensure_ascii=False))
if __name__=='__main__':main()
