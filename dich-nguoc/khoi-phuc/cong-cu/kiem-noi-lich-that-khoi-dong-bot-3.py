"""Run all three real bot3 calendar bodies in continuous business startup.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Calendar SDK arrays/errors supplied; authorization is outside this range.
"""
import importlib.util,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
port=module('calendar3_port','kiem-trang-thai-giao-dich-khoi-dong-bot-3.py')
PARENT_PATH=ROOT/'cong-cu/kiem-noi-lich-that-khoi-dong-bot-1.py'
source=port.port(PARENT_PATH.read_text(encoding='utf-8')).replace('kiem-noi-tin-khoi-dong-bot-1.py','kiem-noi-tin-khoi-dong-bot-3.py')
source=source.replace('cal.base.CFG[1]','cal.base.CFG[3]').replace('cal.CFG[(1,k)]','cal.CFG[(3,k)]')
source=re.sub(r'(?<=:)(6[1-6])\b',lambda m:str(int(m[0])+20),source)
source=re.sub(r'((?:End|Effect|FillCalendarEvents)\()(6[1-6])\b',lambda m:m[1]+str(int(m[2])+20),source)
source=re.sub(r'\bapi==(6[1-6])\b',lambda m:'api=='+str(int(m[1])+20),source)
source=source.replace('api=61','api=81').replace('api=65','api=85').replace('api in [62,63]','api in [82,83]').replace('range(61,66)','range(81,86)')
source=source.replace("code=code.replace('Counts[57]','Counts[66]')","code=code.replace('Counts[72]','Counts[87]')")
source=source.replace('code=inspect.getsource(getattr(temp,function))',"code=port.port(inspect.getsource(getattr(temp,function))).replace('table_cells=1800','table_cells=2800')")
source=source.replace("if __name__=='__main__':j.main()",'')
exec(compile(source,__file__,'exec'),globals())
BASE_IDENTITY_FN=identity;BASE_RENDER_FN=render
DECL=DECL.replace('int InjectedCalendarError=-1;int CalendarError();','int InjectedCalendarError=-1;int CalendarError();\nstring CalendarStringSubstr(const string value,const int start,const int length=-1);\n#define StringSubstr CalendarStringSubstr')
def render():
    return BASE_RENDER_FN()+'\n#undef StringSubstr\nstring CalendarStringSubstr(const string value,const int start,const int length){int previous=CalendarError();ResetLastError();string result=StringSubstr(value,start,length);int error=GetLastError();InjectedCalendarError=error==0 ? previous : error;return result;}\n'
def identity():
    current=BASE_IDENTITY_FN();current['helpers_sha256'][PARENT_PATH.relative_to(ROOT).as_posix()]=sha(PARENT_PATH);return current
j.identity=identity;j.render=render
if __name__=='__main__':j.main()
