"""Compare bot 3 OnInit 0x574c..0x5f34, including real strings and history.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
The three panel children record arguments and supplied mutations; no authorization.
"""
import copy,importlib.util,inspect,struct,textwrap
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
b=module('tail3_runner','kiem-duoi-khoi-dong-bot-1.py');ctx=module('tail3_context','kiem-ngu-canh-khoi-dong-bot-3.py')
require,sha=b.require,b.sha
b.CREATE_FIELDS=b.panel.fields(3)
b.FIELDS=b.CREATE_FIELDS+[
 ('Index','I',0x74934),('StartLots','d',0x6d620),('Calendar.hour','i',0x747dc),
 ('LastHour','i',0x74488),('Show','B',0x1d6f38),('Tester','B',0x1d6f40),
 ('HistoryWindow','B',0x6d43d),('Magic','i',0x6d564),('Seed','i',0x1d6ff0),
 ('Balance','d',0x1d6c60),('LastTicket','Q',0x74838),('Wins','d',0x74940),('Losses','d',0x74948),
 ('TradeComment','s',0x6d568),('TradeSymbol','s',0x74958),
 ('State.buy_first','s',0x74438),('State.buy_second','s',0x74448),
 ('State.sell_first','s',0x74458),('State.sell_second','s',0x74468),('State.flag_744a0','B',0x744a0)]
b.FIELDS += [(f'BarTimes[{i}]','q',0x73470+8*i) for i in range(9)]
b.OPEN_FIELDS=[('show','B',0x1d6f38),('tester','B',0x1d6f40),('seed','i',0x1d6ff0),('symbol','s',0x74958),
 ('balance','d',0x1d6c60),('frequency','i',0x6d21c),('mode','I',0x6d630),('manual_lots','d',0x1d7138),
 ('allowed_dd','d',0x1d7140),('strategy_risk','d',0x1d7150)]+[(n,k,r) for n,k,r in b.CREATE_FIELDS if not n.startswith('P.')]+[('ticket','Q',0x74838)]
b.CLOSED_FIELDS=[('show','B',0x1d6f38),('tester','B',0x1d6f40),('seed','i',0x1d6ff0),('symbol','s',0x74958),('wins','d',0x74940),('losses','d',0x74948)]
source=inspect.getsource(b.cases).replace('panel.cases(1)','panel.cases(3)').replace('range(8)','range(9)').replace('for info in [0,1,2]:','for info in [0]:').replace("(1,1,'Index',7)","(1,1,'Index',8)")
exec(compile(source,__file__,'exec'),b.__dict__);base_cases=b.cases
def cases():
    rows=base_cases()
    for c in rows:c['values']['State.flag_744a0']=[0,1,255][c['id']%3]
    for name,value in [('P.frequency',6),('P.manual_lots',.9),('P.allowed_dd',17.5)]:
        c=copy.deepcopy(rows[0]);c.update(id=len(rows),tag='live-bot3-panel-arguments');c['values'].update(Show=1)
        c['effects']=[[20,1,next(i for i,f in enumerate(b.FIELDS) if f[0]==name),value]];rows.append(c)
    return rows
b.SCRIPT=b.SCRIPT.replace('Bot1','Bot3').replace('bot1','bot3').replace('bot-cua-toi-1','bot-cua-toi-3').replace('BarTimes[8]','BarTimes[9]')
old='''const int &seed,const string &symbol,const double &balance,const double &volume,
              const int &mode,const double &risk,const double &strategy_risk,const int &step,const Bot3NewsEvents &events,'''
new='''const int &seed,const string &symbol,const double &balance,const int &frequency,
              const uint &mode,const double &manual_lots,const double &allowed_dd,const double &strategy_risk,const Bot3NewsEvents &events,'''
require(b.SCRIPT.count(old)==2,'OPEN_SIGNATURE_MARKERS');b.SCRIPT=b.SCRIPT.replace(old,new)
class Native(ctx.Native):
    def __init__(self):
        super().__init__();self.sdk={0x7ff6846e2970:1,0x7ff6846e0fd0:2,0x7ff6846f84f0:3,
          0x7ff6846f8810:4,0x7ff6846f8860:5,0x7ff6846f1c40:6,0x7ff6846f8940:7,0x7ff6846f88b0:8}
        self.children={self.base+0xef40:20,self.base+0x14fa0:21,self.base+0x16e80:22}
        for address in self.sdk:
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        for address in self.children:self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        require([bytes(self.m.mem_read(self.base+off,4)).decode('utf-16-le') for off in [0x5cc5c,0x5cc7c,0x5cc9c,0x5ccbc]]==['B1','B2','S1','S2'],'TAIL_SUFFIXES_CHANGED')
    def call(self,m,address,size,user):
        if address in getattr(self,'sdk',{}):return
        return super().call(m,address,size,user)
    values=b.Native.values
    def state(self):return self.values(b.FIELDS)+struct.pack('<Q',struct.unpack('<I',self.m.mem_read(self.base+0x1d6e10,4))[0])
for name in ['service','run']:
    source=textwrap.dedent(inspect.getsource(getattr(b.Native,name))).replace('0x6a410','0x1d6e10').replace('0x6a448','0x1d6e48').replace('0xe8','0xf8').replace('0x4e77','0x574c')
    old="[('RSP',sp),('RCX',sp+0x40),('RDX',self.base+0x62470),('R9',self.base+0x5e640),('R12',0x7ff6846e2970),('R14',self.base),('R15',self.base+0x5c0),('RBP',self.base+0x1d6e48)]"
    source=source.replace(old,"[('RSP',sp),('R12',0x7ff6846e2970),('R13',self.base+0x6d620),('R14',self.base+0x5c0)]")
    if name=='service':source=source.replace("if api<20:require", "require(api!=2,'UNEXPECTED_TESTER_GATE_IN_BOT3_TAIL')\n    if api<20:require")
    exec(compile(source,__file__,'exec'),b.__dict__);setattr(Native,name,b.__dict__[name])
old_identity=b.identity
def identity():
    current=ctx.identity();src=ROOT/'bot-cua-toi-3/source/MQL5';script=src/'Scripts/bot-cua-toi-3/Bot3StartupTailCheck.mq5'
    current['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in b.pub.closure(script,src)}
    current['helpers_sha256'].update(old_identity()['helpers_sha256']);current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__));return current
for name in ['generate','execute','main']:
    source=inspect.getsource(getattr(b,name)).replace('Bot1','Bot3').replace('bot1','bot3').replace('bot-cua-toi-1','bot-cua-toi-3')
    exec(compile(source,__file__,'exec'),b.__dict__)
b.cases=cases;b.Native=Native;b.identity=identity
b.SCOPE=dict(b.SCOPE,authorization_executed=False,authorization_entry_guarded=True,history_tester_gate_present=False,price_bar_array_rva='0x73470')
if __name__=='__main__':b.main()
