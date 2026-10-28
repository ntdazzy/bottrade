"""Run bot3 calendar, entry-level and nearby-order bodies in business startup.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Chart/order service replies supplied; no trades or authorization are executed.
"""
import importlib.util,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]

def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
port=module('entry3_port','kiem-trang-thai-giao-dich-khoi-dong-bot-3.py')
PARENT_PATH=ROOT/'cong-cu/kiem-noi-muc-gia-that-khoi-dong-bot-1.py'
source=port.port(PARENT_PATH.read_text(encoding='utf-8')).replace('kiem-noi-lich-that-khoi-dong-bot-1.py','kiem-noi-lich-that-khoi-dong-bot-3.py')
for old,new in {'0x3c670':'0x47380','0x3c8d0':'0x475e0','0x6a43c':'0x1d6e3c','luot-20261023-data-v2':'luot-20261023-data'}.items():source=source.replace(old,new)
# Keep entry service IDs separate from account 60..71 and calendar 81..86.
source=re.sub(r'\b7[0-7]\b',lambda m:str(int(m[0])+20),source)
source=source.replace("'Counts[66]','Counts[78]'","'Counts[87]','Counts[98]'").replace('range(90,78)','range(90,98)')
source=source.replace('code=inspect.getsource(getattr(temp,function))',"code=port.port(inspect.getsource(getattr(temp,function))).replace('table_cells=1800','table_cells=2800')")
source=source.replace("if __name__=='__main__':j.main()",'')
exec(compile(source,__file__,'exec'),globals())
BASE_IDENTITY_FN=identity

def identity():
    current=BASE_IDENTITY_FN();current['helpers_sha256'][PARENT_PATH.relative_to(ROOT).as_posix()]=sha(PARENT_PATH);return current
j.identity=identity
if __name__=='__main__':j.main()
