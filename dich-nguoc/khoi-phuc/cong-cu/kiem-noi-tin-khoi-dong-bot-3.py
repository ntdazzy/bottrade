"""Compare continuous bot3 business startup after authorization/tester gate.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Original 0xd60..0x5f34; three calendar, two level and three panel children recorded.
"""
import importlib.util
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def load(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
port=load('news3_port','kiem-trang-thai-giao-dich-khoi-dong-bot-3.py')
PARENT_PATH=ROOT/'cong-cu/kiem-noi-tin-khoi-dong-bot-1.py'
source=port.port(PARENT_PATH.read_text(encoding='utf-8')).replace('kiem-noi-von-khoi-dong-bot-1.py','kiem-noi-von-khoi-dong-bot-3.py')
for old,new in {'0x6a3a8':'0x1d6cb8','0x61b0':'0x6ad0','0x6600':'0x6f20','0x6a90':'0x73b0','0x126c':'0x1279'}.items():source=source.replace(old,new)
source=source.replace(".replace('Counts[48]','Counts[57]')",'')
source=source.replace("marker='NewsSeed=FileReadLong(file);FileReadLong(file);'","marker='NewsSeed=FileReadLong(file);BankInfo=FileReadLong(file);'")
source=source.replace('code=inspect.getsource(getattr(temp,function))',"code=port.port(inspect.getsource(getattr(temp,function))).replace('table_cells=1800','table_cells=2800')")
source=source.replace("if __name__=='__main__':j.main()",'')
exec(compile(source,__file__,'exec'),globals())
BASE_NATIVE=Native;BASE_IDENTITY_FN=identity
class Native(BASE_NATIVE):
    def begin_preparation(self,m,address,size,user):
        first=not self.started;super().begin_preparation(m,address,size,user)
        if first:
            for name in ['R12','R13','R15']:m.reg_write(getattr(self.x,'UC_X86_REG_'+name),0)
    def start_account(self,m,address,size,user):
        expected={'R13':0x7ff6846ef6c0,'R15':self.base+0x5c0,'R14':0x7ff6846b73c0,'R12':self.print_api}
        require(all(m.reg_read(getattr(self.x,'UC_X86_REG_'+n))==v for n,v in expected.items()),'NEWS_ACCOUNT_LIVE_INS')
        super().start_account(m,address,size,user)
def identity():
    current=BASE_IDENTITY_FN();current['helpers_sha256'][PARENT_PATH.relative_to(ROOT).as_posix()]=sha(PARENT_PATH);return current
j.Native=Native;j.identity=identity
if __name__=='__main__':j.main()
