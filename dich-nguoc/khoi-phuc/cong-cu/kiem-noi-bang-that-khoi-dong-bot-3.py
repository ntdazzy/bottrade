"""Run all bot3 display bodies in continuous business startup.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Chart/position/history replies supplied; no authorization or actual chart rendering.
"""
import importlib.util,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]

def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
port=module('panel3_port','kiem-trang-thai-giao-dich-khoi-dong-bot-3.py')
PARENT_PATH=ROOT/'cong-cu/kiem-noi-bang-that-khoi-dong-bot-1.py'
source=port.port(PARENT_PATH.read_text(encoding='utf-8')).replace('kiem-noi-muc-gia-that-khoi-dong-bot-1.py','kiem-noi-muc-gia-that-khoi-dong-bot-3.py')
for old,new in {'0x8320':'0xef40','0xe1b0':'0x14fa0','0xffb0':'0x16e80','0x45b70':'0x53a10','0x47740':'0x555e0','0x6a43c':'0x1d6e3c','0x5880':'0x61a0','0x3d6c0':'0x485e0','0x4d260':'0x55bc0','luot-20261023-data-v2':'luot-20261023-data'}.items():source=source.replace(old,new)
# Panel service IDs must not overlap calendar 81..86 or entry 90..97.
source=re.sub(r'\b(?:8\d|9\d|100)\b',lambda m:str(int(m[0])+30),source)
source=source.replace('m.mem_read(sp+40,118)','m.mem_read(sp+40,88)')
source=source.replace("'Counts[78]','Counts[101]'","'Counts[98]','Counts[131]'").replace('range(110,101)','range(110,131)')
source=source.replace("'Panel.trade_risk':1.25,'Panel.balance_step':600","'Panel.strategy_risk':2.75,'Panel.manual_lots':.123,'Panel.allowed_dd':30.,'Inputs.native_1d7130':0,'Frequency':3")
source=source.replace("[-1,0,3,999,9999]:add('panel-risk-mode',{'Panel.mode':mode})","[-1,0,3,1234,9999]:add('panel-risk-mode',{'Inputs.native_1d7130':mode})")
source=source.replace('for group in [1,8,9]:','for group in [1,8,9,10]:')
source=source.replace('code=inspect.getsource(getattr(temp,function))',"code=port.port(inspect.getsource(getattr(temp,function))).replace('table_cells=1800','table_cells=2800')")
source=source.replace("if __name__=='__main__':j.main()",'')
exec(compile(source,__file__,'exec'),globals())
BASE_IDENTITY_FN=identity;BASE_CASES_FN=cases

def cases():
    rows=BASE_CASES_FN()
    for frequency in [-1,0,1,2,3,4,5,6,2147483647]:
        c=copy.deepcopy(rows[3]);c.update(id=len(rows),tag='bot3-frequency-label');c['values']['Frequency']=frequency;rows.append(c)
    for group in [9,10]:
        c=copy.deepcopy(rows[3]);c.update(id=len(rows),tag='bot3-last-closed-group')
        c['display']['history']=[[31,9001+group,10.,-1.,-.5,'XAUUSD']];c['total']=1;c['deals']=[[31,1790000000,9001+group,.1]];rows.append(c)
    return rows

def identity():
    current=BASE_IDENTITY_FN();current['helpers_sha256'][PARENT_PATH.relative_to(ROOT).as_posix()]=sha(PARENT_PATH);return current
j.identity=identity;j.cases=cases
if __name__=='__main__':j.main()
