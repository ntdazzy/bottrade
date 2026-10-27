"""Inspect the first unequal native/MQL5 boundary of one recorded case."""
import importlib.util,json,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
s=importlib.util.spec_from_file_location('panel_check',ROOT/'cong-cu/kiem-bang-thong-tin-mo-bot-1-3.py')
t=importlib.util.module_from_spec(s);s.loader.exec_module(t)
bot=int(sys.argv[1]);run=sys.argv[2];index=int(sys.argv[3]);folder=ROOT/f'bot-cua-toi-{bot}/bang-chung/kiem-quan-ly-vi-the'/run
rows=t.cases(bot);tapes=t.records((folder/'mql5-results.bin').read_bytes(),len(rows))
def decode(raw):
    r=t.Reader(raw);out={}
    for name,kind,_ in t.fields(bot):out[name]=r.text() if kind=='s' else hex(r.take('Q')[0])
    out['error']=hex(r.take('Q')[0]);return out
class Inspect(t.Original):
    def call(self,m,address,size,user):
        start=self.tape.pos if hasattr(self,'tape') else 0
        try:return super().call(m,address,size,user)
        except ValueError as e:
            if str(e).startswith('STATE_BEFORE_SDK'):
                expected=t.Reader(self.tape.raw[start:]).block();actual=self.state();want=decode(expected);got=decode(actual)
                print(json.dumps(dict(case=index,call=self.calls,lengths=[len(expected),len(actual)],first_difference=next((i for i,(a,b) in enumerate(zip(expected,actual)) if a!=b),None),tails=[expected[-24:].hex(),actual[-24:].hex()],differences={k:[want[k],got[k]] for k in want if want[k]!=got[k]}),ensure_ascii=False))
            raise
o=Inspect(bot)
try:o.run(rows[index],tapes[index])
except ValueError as e:print(str(e));raise SystemExit(1)
print('MATCHED')
