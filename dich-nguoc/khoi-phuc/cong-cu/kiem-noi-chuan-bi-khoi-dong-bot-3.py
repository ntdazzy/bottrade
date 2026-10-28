"""Run bot3 real first preparation continuously through normal OnInit return.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
errors RUN --build BUILD checks three fatal inputs separately.
"""
import importlib.util,inspect,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def load(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
port=load('prepare3_port',ROOT/'cong-cu/kiem-trang-thai-giao-dich-khoi-dong-bot-3.py')
driver=load('prepare3_runner_contract',ROOT/'cong-cu/kiem-noi-khoi-dong-bot-1.py')
PARENT_PATH=ROOT/'cong-cu/kiem-noi-chuan-bi-khoi-dong-bot-1.py'
source=port.port(PARENT_PATH.read_text(encoding='utf-8'))
source=source.replace('kiem-noi-khoi-dong-bot-1.py','kiem-noi-khoi-dong-bot-3.py')
for old,new in {'0x621c4':'0x6d170','0x621c8':'0x6d174','0x622d0':'0x6d308','0x67750':'0x74790','0x67790':'0x747d0','0x62190':'0x6d180','0x7500':'0xe0c0','0x831d':'0xef3f','0x3c9d':'0x4580'}.items():source=source.replace(old,new)
source=source.replace("('indicator_day','B'","('indicator_timeframe','i'").replace('Inputs.indicator_day','Inputs.indicator_timeframe').replace('native_6a740','native_1d7138')
source=source.replace('full.legacy.INPUTS,1','full.legacy.INPUTS,3').replace('full.legacy.OUTPUTS,1','full.legacy.OUTPUTS,3').replace('full.legacy.base_case(1)','full.legacy.base_case(3)')
source=source.replace("require(found[1]==k,'FIELD_TYPE_CHANGED '+n)","require(found[1]==k or (r==0x6d630 and found[1]=='I' and k=='i'),'FIELD_TYPE_CHANGED '+n)")
source=source.replace('8679070031fe7f3309378147c8afc4bf2d4ab596b3ee22a73e8e6386db6c9d0d','1e12d60da60e0727d7fc3eef9a05407e3ec6fb150cde4349f0fa1d50580bb0df')
source=source.replace('for day in [0,1,255]:','for day in [-1,0,15,16408,2147483647]:')
source=source.replace('sample=2000.,tick_ok=1','sample=2000.,open=2300.,tick_ok=1')
source=source.replace("struct.pack('<8Q',r['handle']","struct.pack('<9Q',r['handle']").replace("r['now']&j.MASK)","r['now']&j.MASK,boot.bits(r['open']))")
source=source.replace('datetime PrepTime(MqlDateTime &calendar);','double PrepOpen(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);\ndatetime PrepTime(MqlDateTime &calendar);',1)
source=source.replace('#define iATR PrepATR','#define iOpen PrepOpen\n#define iATR PrepATR',1).replace('#undef iATR','#undef iOpen\n#undef iATR',1)
source=source.replace('PrepIPos[3];double PrepSample;','PrepIPos[3];double PrepSample,PrepOpenReply;')
source=source.replace('int PrepATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period){Begin();',
 'double PrepOpen(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();End(38,(ulong)frame,(ulong)(long)shift,Bits(PrepOpenReply),0,symbol);Effect(38);return PrepOpenReply;}\nint PrepATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period){Begin();',1)
source=source.replace('Counts[38]','Counts[39]').replace('range(30,38)','range(30,39)')
source=source.replace('PrepNow=FileReadLong(file);','PrepNow=FileReadLong(file);PrepOpenReply=Value((ulong)FileReadLong(file));')
source=source.replace('0x7ff6846e2970:35}','0x7ff6846e2970:35,0x7ff6846f3bc0:38}')
source=source.replace('[0x7ff6846deec0,0x7ff6846e2c10]','[0x7ff6846deec0,0x7ff6846e2c10,0x7ff6846f3bc0]')
source=source.replace("args[:2]==[frame,period&j.MASK]","[args[0]&0xffffffff,args[1]]==[frame,period&j.MASK]")
source=source.replace("elif api==36:reply=args[0]","elif api==38:\n            require(args[:2]==[reg('R8'),reg('R9')]==[16408,1] and texts==[self.read_text(reg('RDX')),None],'PREP_OPEN_ARGS');reply=args[2];m.mem_write(self.base+0x1d6e48,struct.pack('<Q',reply))\n        elif api==36:reply=args[0]")
source=source.replace('if api!=34:m.reg_write','if api not in [34,38]:m.reg_write')
source=source.replace('code=inspect.getsource(getattr(j,name))',"code=port.port(inspect.getsource(getattr(driver,name))).replace('table_cells=1800','table_cells=2800')")
source=source.replace("if __name__=='__main__':\n    if len(sys.argv)>1 and sys.argv[1]=='errors':errors()\n    else:j.main()",'')
exec(compile(source,__file__,'exec'),globals())
BASE_RENDER=render;BASE_CASES=cases;BASE_IDENTITY=identity
def render():
    return BASE_RENDER().replace('P.native_6d630=Panel.mode;','P.native_6d630=(int)Panel.mode;')
def cases():
    rows=BASE_CASES();seed=rows[0]
    def add(tag,changes=None,**replies):
        c=copy.deepcopy(seed);c.update(id=len(rows),tag=tag,effects=[]);c['prep'].update(replies)
        for n,v in (changes or {}).items():c['values'][ALIASES.get(n,n)]=v
        rows.append(c);return c
    for handle,copied in [(-1,3),(17,0),(17,3)]:
        for raw_mode in [-2147483648,-1,0,1234,2147483647]:
            add('shared-mode-and-distinct-manual-lots',{'Inputs.native_1d7138':9.75,'P.native_6d620':.125,'P.native_6d630':raw_mode,'Inputs.native_1d7130':-1},handle=handle,copied=copied)
    for opened,sample in [(1000.,9000.),(2300.,.25),(5000.,3.),(0.,7000.)]:
        add('open-price-independent-from-indicator',{'Inputs.adjust_lots':0},open=opened,sample=sample)
    for api,n,value in [(30,'Inputs.native_1d7138',.75),(38,'Inputs.reference',2000.),(34,'P.native_6d630',-1),(20,'P.native_6d630',1234),(20,'Inputs.native_1d7138',.5)]:
        c=add('shared-fields-live-after-calls');c['effects']=[[api,1,next(i for i,f in enumerate(j.FIELDS) if f[0]==ALIASES.get(n,n)),value]]
    return rows
def identity():
    current=BASE_IDENTITY()
    for p in [PARENT_PATH,ROOT/'cong-cu/kiem-noi-khoi-dong-bot-1.py']:current['helpers_sha256'][p.relative_to(ROOT).as_posix()]=sha(p)
    return current
j.cases=cases;j.render=lambda:render().replace('bot3-startup-joined','bot3-startup-preparation-flow');j.identity=identity
if __name__=='__main__':
    if len(sys.argv)>1 and sys.argv[1]=='errors':errors()
    else:j.main()
