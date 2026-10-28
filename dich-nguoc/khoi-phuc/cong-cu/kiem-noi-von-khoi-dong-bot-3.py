"""Compare bot3 business account initialization, literal calendars and startup return.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Runs 0x1279..0x5f34; account/storage/time replies are supplied, no authorization.
"""
import importlib.util,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def load(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
port=load('account3_port','kiem-trang-thai-giao-dich-khoi-dong-bot-3.py')
PARENT_PATH=ROOT/'cong-cu/kiem-noi-von-khoi-dong-bot-1.py'
source=port.port(PARENT_PATH.read_text(encoding='utf-8'))
source=source.replace('kiem-noi-ngu-canh-khoi-dong-bot-1.py','kiem-noi-chon-toan-khoi-dong-bot-3.py')
for old,new in {'0x6a790':'0x1d7180','0x6a778':'0x1d7168','0x6a738':'0x1d7128','0x6a328':'0x1d6c68','0x6a330':'0x1d6cc8','0x6a340':'0x1d6cd8','0x6a350':'0x1d6ce8','0x69f60':'0x76f90','0x69f61':'0x76f91','0x68330':'0x75360','0x68ca0':'0x75cd0','0x69600':'0x76630','0x6a43c':'0x1d6e3c','0x126c':'0x1279','0x1941':'0x193f','0x3827':'0x3840'}.items():source=source.replace(old,new)
source=source.replace("CALL=c.CALL.replace('Bot3InitializeStartupContextFlow(ChartName,','Bot3InitializeStartupAccountFlow(UseEquity!=0,ResetHighest!=0,ManualBalance,HighestBalance,PeakKey,TimeKey,AccountLastTime,NewsFlag0,NewsFlag1,NewsNfp,NewsInterest,NewsCpi,ChartName,',1)","CALL=c.CALL.replace('Bot3InitializeStartupSelectionFlow(','Bot3InitializeStartupAccountFlow(UseEquity,ResetHighest,ManualBalance,HighestBalance,PeakKey,TimeKey,AccountLastTime,NewsFlag0,NewsFlag1,NewsNfp,NewsInterest,NewsCpi,',1)")
source=re.sub(r'(?<=:)(4[0-9]|50)\b',lambda m:str(int(m[0])+20),source)
source=re.sub(r'((?:End|Effect)\()(4[0-9]|50)\b',lambda m:m[1]+str(int(m[2])+20),source)
source=re.sub(r'\bapi==(4[0-9]|50)\b',lambda m:'api=='+str(int(m[1])+20),source)
source=source.replace('next_api==47','next_api==67').replace('range(40,48)','range(60,68)').replace('api in [42,43,44]','api in [62,63,64]').replace('api in [40,42]','api in [60,62]')
source=source.replace("code=code.replace('Counts[38]','Counts[48]')","code=code.replace('Counts[49]','Counts[72]')")
source=source.replace('Bot3StartupContextFlow.mqh','Bot3StartupSelectionFlow.mqh').replace('bot3-startup-context-flow','bot3-startup-selection-flow')
source=source.replace("marker='PrepNow=FileReadLong(file);'","marker='SelPriceIndex=0;'")
source=source.replace('source=inspect.getsource(getattr(temp,function))',"source=port.port(inspect.getsource(getattr(temp,function))).replace('table_cells=1800','table_cells=2800')")
source=source.replace("        require(m.reg_read(self.x.UC_X86_REG_XMM6)&j.MASK==0,'ACCOUNT_DID_NOT_ESTABLISH_ZERO')\n",'')
source=source.replace("if __name__=='__main__':j.main()",'')
exec(compile(source,__file__,'exec'),globals())
BASE_CASES[0]=next(row for row in BASE_CASES if row['values']['Frequency']==5 and row['values']['Inputs.native_1d7130']==1234 and row['values']['Inputs.variable_distances']==1)
BASE_CASE_FN=cases;BASE_RENDER_FN=render;BASE_NATIVE=Native;BASE_IDENTITY_FN=identity
DECL='long InitCalendarInfo(const ENUM_MQL_INFO_INTEGER property);\n'+DECL
DECL=DECL.replace('#include "../../Include/bot-cua-toi-3/Bot3AccountInitialization.mqh"','#include "../../Include/bot-cua-toi-3/Bot3AccountInitialization.mqh"\n#define MQLInfoInteger InitCalendarInfo\n#include "../../Include/bot-cua-toi-3/Bot3BuiltInNewsHistory.mqh"\n#undef MQLInfoInteger')
GLOBALS+='\nlong BankInfo;\n'
MOCKS+='\nlong InitCalendarInfo(const ENUM_MQL_INFO_INTEGER property){Begin();End(71,(ulong)property,(ulong)BankInfo);Effect(71);return BankInfo;}\n'
def cases():
    rows=BASE_CASE_FN()
    for row in rows:
        row['bank']['info']=1;row['selection']['balance']=row['bank']['balance']
    seed=rows[0]
    def add(tag,changes=None,**bank):
        row=copy.deepcopy(seed);row.update(id=len(rows),tag=tag,effects=[]);row['values'].update(changes or {});row['bank'].update(bank);row['selection']['balance']=row['bank']['balance'];rows.append(row);return row
    for reply in [-1,0,1,2]:
        for flag in ['NewsFlag0','NewsFlag1']:
            row=add('calendar-info-order',info=reply);row['effects']=[[71,1,next(i for i,f in enumerate(j.FIELDS) if f[0]==flag),87]]
    for api,hit,name,value,initial in [(60,1,'UseEquity',1,{'UseEquity':0}),(61,1,'ResetHighest',1,{'ResetHighest':0}),(63,1,'ResetHighest',0,{'ResetHighest':1}),(62,1,'ManualBalance',27000.,{'ManualBalance':0.}),(67,1,'HighestBalance',-77.,{}),(63,2,'ManualBalance',-1.,{'ManualBalance':27000.})]:
        row=add('live-account-setting-'+name,initial);row['effects']=[[api,hit,next(i for i,f in enumerate(j.FIELDS) if f[0]==name),value]]
    add('manual-balance-distinct-from-selection-balance',{'ManualBalance':25000.},balance=2000.)
    return rows
def encode(rows):
    raw=bytearray(struct.pack('<3i',j.MAGIC,1,len(rows)))
    for row in rows:
        raw+=BASE_ENCODE([row])[12:];b=row['bank'];raw+=struct.pack('<10Q',b['login']&j.MASK,boot.bits(b['balance']),boot.bits(b['equity']),b['has_peak'],boot.bits(b['peak']),b['has_time'],boot.bits(b['time']),b['now']&j.MASK,b['news_seed']&j.MASK,b['info']&j.MASK)
    return bytes(raw)
def render():
    return BASE_RENDER_FN().replace('NewsSeed=FileReadLong(file);FileReadLong(file);','NewsSeed=FileReadLong(file);BankInfo=FileReadLong(file);')
class Native(BASE_NATIVE):
    def __init__(self):
        super().__init__();self.calendar_phase=False;self.calendar_api=0x7ff6846e0fd0
    def begin_preparation(self,m,address,size,user):
        first=not self.started;super().begin_preparation(m,address,size,user)
        self.counts.setdefault(71,0)
        if first:
            self.selection_phase=False;self.calendar_phase=False;x=self.x
            for name in ['RAX','RBP','RDI']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
            for name,value in [('R13',0x7ff6846ef6c0),('R15',self.base+0x5c0),('R14',0x7ff6846b73c0),('R12',self.print_api)]:m.reg_write(getattr(x,'UC_X86_REG_'+name),value)
    def finish_account(self,m,address,size,user):self.account_phase=False;self.calendar_phase=True
    def start_context(self,m,address,size,user):
        require(self.calendar_phase,'CALENDAR_NOT_ENTERED')
        require(m.reg_read(self.x.UC_X86_REG_RAX)==self.base+0x7e20 and m.reg_read(self.x.UC_X86_REG_RBP)==0x7ff6846f1c40 and m.reg_read(self.x.UC_X86_REG_RDI)==self.gate['ctx'],'ACCOUNT_CALENDAR_LIVE_INS')
        require(self.read_text(self.base+0x1d6e3c) is not None,'ACCOUNT_STRING_BUFFER_MISSING');self.calendar_phase=False;self.selection_phase=True;self.context_phase=True
    def service(self,m,address,size,user):
        if not self.calendar_phase:return super().service(m,address,size,user)
        require(address==self.calendar_api,'UNEXPECTED_CALENDAR_API');r=self.tape;require(r.block()==self.state(),'CALENDAR_STATE');kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I')
        require(kind==71 and m.reg_read(self.x.UC_X86_REG_RCX)==self.gate['ctx'] and m.reg_read(self.x.UC_X86_REG_RDX)==args[0]==6 and args[1]==(self.case['bank']['info']&j.MASK) and texts==[None,None],'CALENDAR_INFO_ARGS')
        m.reg_write(self.x.UC_X86_REG_RAX,args[1]);m.mem_write(self.base+0x1d6e10,struct.pack('<I',error));self.counts[71]+=1;self.effect(71);self.calls+=1
def identity():
    current=BASE_IDENTITY_FN();current['helpers_sha256'][PARENT_PATH.relative_to(ROOT).as_posix()]=sha(PARENT_PATH);return current
j.cases=cases;j.encode=encode;j.render=render;j.Native=Native;j.identity=identity
j.SCOPE=dict(j.SCOPE,caller_xmm6_zero_supplied=False,caller_string_return_buffer_primed=False,calendar_info_call_recorded=True)
if __name__=='__main__':j.main()
