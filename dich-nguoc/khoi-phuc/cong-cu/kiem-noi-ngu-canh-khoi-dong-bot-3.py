"""Compare bot3 startup context -> real preparation -> tail without resets.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Native range 0x3ce6..0x5f34, before earlier time/currency/frequency selection.
"""
import importlib.util
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def load(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
port=load('context3_port',ROOT/'cong-cu/kiem-trang-thai-giao-dich-khoi-dong-bot-3.py')
context_contract=load('context3_contract',ROOT/'cong-cu/kiem-ngu-canh-khoi-dong-bot-3.py')
PARENT_PATH=ROOT/'cong-cu/kiem-noi-ngu-canh-khoi-dong-bot-1.py'
source=port.port(PARENT_PATH.read_text(encoding='utf-8'))
source=source.replace('kiem-noi-chuan-bi-khoi-dong-bot-1.py','kiem-noi-chuan-bi-khoi-dong-bot-3.py')
source=source.replace('j,boot,require,sha=p.j,p.boot,p.require,p.sha','j,boot,require,sha=p.j,context_contract.b,p.require,p.sha')
source=source.replace('MinimumSpread,FridayClosed,TailBars','MinimumSpread,TailBars')
source=source.replace('0x3c9d','0x4580').replace('0x3827','0x3ce6').replace('0x5658','0x5f34').replace('0x6a43c','0x1d6e3c')
source=source.replace("            m.reg_write(self.x.UC_X86_REG_R9,self.base+0x5d6e8)\n",'')
source=source.replace("source=inspect.getsource(getattr(temp,function))","source=port.port(inspect.getsource(getattr(temp,function))).replace('table_cells=1800','table_cells=2800')")
source=source.replace('caller_xmm6_zero_supplied=True','caller_xmm6_zero_supplied=False')
source=source.replace("if __name__=='__main__':j.main()",'')
exec(compile(source,__file__,'exec'),globals())
BASE_RENDER=render;BASE_IDENTITY=identity
def render():
    return BASE_RENDER().replace('int Magic;','').replace('int Seed,LastHour;','int LastHour;').replace('string OrderComment;','')
def identity():
    current=BASE_IDENTITY()
    for path in [PARENT_PATH,Path(context_contract.__file__)]:current['helpers_sha256'][path.relative_to(ROOT).as_posix()]=sha(path)
    return current
j.render=render;j.identity=identity
if __name__=='__main__':j.main()
