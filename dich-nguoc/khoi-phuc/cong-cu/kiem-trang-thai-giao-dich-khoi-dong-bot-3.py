"""Compare bot 3 post-preparation 0x458e..0x574c and its out-of-line branches.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Entry-level children and terminal replies supplied; all 2,800 table cells checked.
"""
import importlib.util,inspect,textwrap
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
b=module('trading3_runner','kiem-trang-thai-giao-dich-khoi-dong-bot-1.py');ctx=module('trading3_context','kiem-ngu-canh-khoi-dong-bot-3.py')
require,sha=b.require,b.sha
NAMES={'native_62414':'native_6d50c','native_62555':'native_6d645','native_6248c':'management_timeframe','native_62530':'native_6d620','native_62538':'native_6d628','native_624f8':'native_6d5e8','native_62500':'native_6d5f0'}
RVA={0x62414:0x6d50c,0x62555:0x6d645,0x678f4:0x74934,0x6242c:0x6d524,0x6248c:0x6d584,
 0x67760:0x747a0,0x67758:0x74798,0x62560:0x6d650,0x62530:0x6d620,0x66d98:0x73dd8,0x62520:0x6d610,
 0x66a70:0x73ab0,0x67468:0x744a8,0x62498:0x6d588,0x624a0:0x6d590,0x624c8:0x6d5b8,0x624d0:0x6d5c0,
 0x623e0:0x6d4d8,0x624a8:0x6d598,0x624f8:0x6d5e8,0x62500:0x6d5f0,0x62440:0x6d538,
 0x62430:0x6d528,0x62434:0x6d52c,0x62468:0x6d560,0x62419:0x6d511,0x66da0:0x73de0,0x67450:0x74490,
 0x67434:0x74474,0x67488:0x744c8,0x67489:0x744c9,0x6748a:0x744ca,0x67478:0x744b8,
 0x623d8:0x6d4d0,0x62558:0x6d648,0x6227c:0x6d2b4,0x6246c:0x6d564,0x62438:0x6d530,
 0x62448:0x6d540,0x62450:0x6d548,0x62460:0x6d558,0x677f8:0x74838,0x67440:0x74480,0x67438:0x74478,
 0x62570:0x6d660,0x62578:0x6d668,0x67458:0x74498,0x673f0:0x74430,0x6745c:0x7449c,
 0x62580:0x6d670,0x62538:0x6d628,0x66410:0x73450,0x66420:0x73468,
 0x62590:0x6d680,0x65470:0x724b0,0x66a80:0x73ac0,0x67918:0x74958,0x6a410:0x1d6e10,0x6a448:0x1d6e48,
 0x265a0:0x31cd0,0x26960:0x32090,0x3cab:0x458e,0x4e77:0x574c,0x4f4b:0x5873}
def port(source):
    for old,new in NAMES.items():source=source.replace(old,new)
    for old,new in RVA.items():source=source.replace(hex(old),hex(new))
    return source.replace('Bot1','Bot3').replace('BOT1','BOT3').replace('bot1','bot3').replace('bot-cua-toi-1','bot-cua-toi-3')
b.FIELDS=[(port(n),k,RVA[r],d) for n,k,r,d in b.FIELDS if n!='FridayClosed']
b.SCRIPT=port(b.SCRIPT).replace('Volumes[8]','Volumes[9]').replace('uchar FridayClosed;','').replace('MinimumSpread,FridayClosed,Volumes','MinimumSpread,Volumes')
b.SCRIPT=b.SCRIPT.replace('for(int i=0;i<8;i++)Word(Bits(Volumes[i]));','for(int i=0;i<9;i++)Word(Bits(Volumes[i]));').replace('for(int i=0;i<8;i++)Volumes[i]','for(int i=0;i<9;i++)Volumes[i]')
for marker,prefix in [
 ('for(int i=0;i<100;i++)for(int j=0;j<3;j++)h=', 'for(int i=0;i<500;i++)for(int j=0;j<2;j++)h=(h^Bits(Manager.table.take_rows[i][j]))*0x100000001b3;'),
 ('for(int i=0;i<100;i++)for(int j=0;j<3;j++)Word', 'for(int i=0;i<500;i++)for(int j=0;j<2;j++)Word(Bits(Manager.table.take_rows[i][j]));'),
 ('for(int i=0;i<100;i++)for(int j=0;j<3;j++)Queue.orders', 'for(int i=0;i<500;i++)for(int j=0;j<2;j++)Manager.table.take_rows[i][j]=(double)(2*i+j+1)*.375;\n      ')]:
    require(b.SCRIPT.count(marker)==1,'TAKE_TABLE_MARKER');b.SCRIPT=b.SCRIPT.replace(marker,prefix+marker)
source=port(inspect.getsource(b.cases)).replace('for index in [0,1,3,7]:','for index in [0,1,3,8]:')
exec(compile(source,__file__,'exec'),b.__dict__)
class Native(ctx.Native):pass
b.ctx=ctx
for name in ['__init__','calculate','zero','state','service','run']:
    source=port(textwrap.dedent(inspect.getsource(getattr(b.Native,name))))
    if name=='__init__':source=source.replace('super().__init__()','ctx.Native.__init__(self)')
    source=source.replace('[(0x6d680,12000),(0x724b0,2400)]','[(0x6d680,12000),(0x70560,8000),(0x724b0,2400)]')
    source=source.replace('bytes(self.m.mem_read(self.base+0x6d680,12000))+','bytes(self.m.mem_read(self.base+0x6d680,12000))+bytes(self.m.mem_read(self.base+0x70560,8000))+')
    source=source.replace('self.base+0x73ac0,64','self.base+0x73ac0,72')
    source=source.replace('[(0x73ac0,8,.125),(0x6d680,1500,.125),(0x724b0,300,.25)]','[(0x73ac0,9,.125),(0x6d680,1500,.125),(0x70560,1000,.375),(0x724b0,300,.25)]')
    source=source.replace("[('RBP',self.base+0x1d6e48),('R12',self.print_api),('R14',0x7ff6846f1c40),('R15',self.base+0x5c0)]","[('RBP',0x7ff6846f1c40),('R12',self.print_api),('R13',0x7ff6846ef6c0),('R15',self.base+0x5c0)]")
    exec(compile(source,__file__,'exec'),b.__dict__);setattr(Native,name,b.__dict__[name])
def native_call(self,m,address,size,user):
    if address in getattr(self,'sdk',{}):return
    return ctx.Native.call(self,m,address,size,user)
Native.call=native_call
old_identity=b.identity
def identity():
    current=ctx.identity();src=ROOT/'bot-cua-toi-3/source/MQL5';script=src/'Scripts/bot-cua-toi-3/Bot3StartupTradingStateCheck.mq5'
    current['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in b.pub.closure(script,src)}
    current['helpers_sha256'].update(old_identity()['helpers_sha256']);current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__));return current
for name in ['generate','execute','main']:
    source=port(inspect.getsource(getattr(b,name))).replace('table_cells=1800','table_cells=2800')
    exec(compile(source,__file__,'exec'),b.__dict__)
b.Native=Native;b.identity=identity
b.SCOPE=dict(b.SCOPE,authorization_executed=False,authorization_entry_guarded=True,virtual_take_table_checked=True)
if __name__=='__main__':b.main()
