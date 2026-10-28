"""Run bot3 real time/currency selection, context, preparation and tail continuously.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Native 0x3840..0x5f34; two entry-level and three panel children remain recorders.
"""
import calendar,copy,hashlib,importlib.util,inspect,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
c=module('selection_full_context','kiem-noi-ngu-canh-khoi-dong-bot-3.py');sel=module('selection_full_contract','kiem-noi-chon-khoi-dong-bot-3.py');driver=module('selection_full_runner','kiem-noi-khoi-dong-bot-1.py')
j,boot,require,sha=c.j,c.boot,c.require,c.sha
OLD_CASES=c.cases();OLD_RENDER=j.render;OLD_ENCODE=j.encode;OLD_IDENTITY=c.identity
ALIASES={'Risk':'Inputs.native_1d7130','VariableValues':'Inputs.variable_distances','BootPanel.allowed_dd':'Panel.allowed_dd','BootPanel.frequency':'Panel.frequency'}
for n,k,r in sel.EXTRA:
    n=ALIASES.get(n,n);found=next((f for f in j.FIELDS if f[2]==r),None);require(found is None or found==(n,k,r),'SELECTION_SHARED_FIELD '+n)
    if found is None:j.FIELDS.append((n,k,r))
CALL=c.CALL.replace('Bot3InitializeStartupContextFlow(','Bot3InitializeStartupSelectionFlow(WinterHours,SummerHours,AdjustedTime,Frequency,Thresholds,Manual,Enabled,FrequencyDivisor,')
DST_SHA='89a100acb20d937bc0b7f9ec261baf1ec1c62d4c5a469f643cac144cb6b92db8';CURRENCY_SHA='7c425c07ba2bc4ff9bc68ac7082bec2e6278582e9189e1f0c9641c43005823b6'
def stamp(y,m,d):return calendar.timegm((y,m,d,12,0,0))
def cases():
    rows=[]
    def add(tag,changes=None,base=None,**reply):
        row=copy.deepcopy(base or OLD_CASES[0]);row.update(id=len(rows),tag=tag)
        if base is None:row['effects']=[];row['values'].update({'ChartName':'XAUUSD.a','ContextInputs.symbol_suffix':'','ContextInputs.comment_prefix':'The Gold Reaper'})
        defaults=dict(WinterHours=2,SummerHours=3,AdjustedTime=-9,Frequency=5,FrequencyDivisor=-7.)
        defaults.update({f'Thresholds[{i}]':1 for i in range(3)});defaults.update({f'Manual[{i}]':11+23*i for i in range(9)});defaults.update({f'Enabled[{i}]':17+13*i for i in range(9)})
        row['values'].update(defaults)
        if base is None:row['values'].update({'Inputs.native_1d7130':1234,'Inputs.variable_distances':1,'Panel.allowed_dd':30.})
        row['values'].update(changes or {});row['selection']=dict(clocks=[stamp(2026,6,1)]*4,balance=2000.,currencies=['USD'],prices=[2.]*4);row['selection'].update(reply);rows.append(row);return row
    for frequency in [-2147483648,-1,0,1,2,3,4,5,6,7,2147483647]:
        for risk in [0,1234]:
            for variable in [0,1,255]:add('frequency-risk-variable',{'Frequency':frequency,'Inputs.native_1d7130':risk,'Inputs.variable_distances':variable})
    for mask in range(8):
        for balance in [1099.5,1100.,1100.5,1866.5,1867.,2699.5,2700.,2700.5]:add('automatic-thresholds',{f'Thresholds[{i}]':(mask>>i)&1 for i in range(3)},balance=balance)
    for year in [1986,1987,2006,2007,2026]:
        for month,day in [(3,8),(3,9),(10,31),(11,1)]:add('summer-boundary',{'Frequency':0},clocks=[stamp(year,month,day)]*4)
    for currency in ['USD','usd','EUR','eur','JPY','CHF','CNH','CNY','XEM','VND','']:
        for suffix in ['', '.a']:
            add('currency-before-suffix-detection',{'ContextInputs.symbol_suffix':suffix},currencies=[currency],prices=[0.,2.,3.,4.] if currency in ['CNH','CNY'] else [2.,2.])
    for byte in [0,1,2,255]:add('raw-manual-flags',dict(Frequency=6,**{f'Manual[{i}]':byte for i in range(9)}))
    for value in [0.,-30.,float('nan'),float('inf'),-float('inf')]:add('drawdown-numbers',{'Panel.allowed_dd':value})
    for hour in [-2147483648,-1,0,24,2147483647]:add('clock-int32-product',{'WinterHours':hour,'SummerHours':hour,'Frequency':0})
    for old in OLD_CASES[::17]:add('carry-context-preparation-cases',{'Frequency':3},base=old)
    for api,name,value in [(40,'SummerHours',-7),(45,'Frequency',6),(46,'Panel.allowed_dd',27.),(46,'Inputs.variable_distances',0),(46,'Inputs.native_1d7130',0),(47,'Thresholds[2]',0)]:
        row=add('state-changes-in-selection',currencies=['EUR']);row['effects']=[[api,1,next(i for i,f in enumerate(j.FIELDS) if f[0]==name),value]]
    return rows
def encode(rows):
    raw=bytearray(struct.pack('<3i',j.MAGIC,1,len(rows)))
    for row in rows:
        raw+=OLD_ENCODE([row])[12:];r=row['selection'];raw+=struct.pack('<4qQ',*r['clocks'],boot.bits(r['balance']))
        raw+=struct.pack('<i',len(r['currencies']))+b''.join(boot.text(v) for v in r['currencies'])
        raw+=struct.pack('<i',len(r['prices']))+b''.join(struct.pack('<Q',boot.bits(v)) for v in r['prices'])
    return bytes(raw)
DECL_EARLY='datetime SelNow();\nbool SelStruct(datetime value,MqlDateTime &result);\ndouble SelMod(double left,double right);\nint SelConcat(string &output,int year,const string &suffix);\ndatetime SelDate(string value);\ndouble SelBalance(ENUM_ACCOUNT_INFO_DOUBLE property);\nstring SelCurrency(ENUM_ACCOUNT_INFO_STRING property);\ndouble SelClose(string symbol,ENUM_TIMEFRAMES timeframe,int shift);\nvoid SelPrint(string message);\n\n#define TimeCurrent SelNow\n#define TimeToStruct SelStruct\n#define MathMod SelMod\n#define StringConcatenate SelConcat\n#define StringToTime SelDate\n#define AccountInfoString SelCurrency\n#define iClose SelClose\n#define Print SelPrint\n\n#include "../../Include/bot-cua-toi-3/Bot3AmericanDST.mqh"\n#include "../../Include/bot-cua-toi-3/Bot3VolumeCurrency.mqh"\n\n#undef TimeCurrent\n#undef TimeToStruct\n#undef MathMod\n#undef StringConcatenate\n#undef StringToTime\n#undef AccountInfoString\n#undef iClose\n#undef Print\n'

DECL_CALL='#define TimeCurrent SelNow\n#define AccountInfoDouble SelBalance\n#include "../../Include/bot-cua-toi-3/Bot3StartupSelectionContext.mqh"\n#undef AccountInfoDouble\n#undef TimeCurrent\n#include "../../Include/bot-cua-toi-3/Bot3StartupSelectionFlow.mqh"\n'

GLOBALS='long SelClocks[4];\nint SelClockIndex;\ndouble SelBalanceReply;\nstring SelCurrencies[64];\nint SelCurrencyCount;\nint SelCurrencyIndex;\ndouble SelPrices[64];\nint SelPriceCount;\nint SelPriceIndex;\n'

MOCKS='datetime SelNow()\n{\n   Begin();\n   int index=SelClockIndex;\n   if(index<4) SelClockIndex++;\n   else index=3;\n   datetime value=(datetime)SelClocks[index];\n   End(40,(ulong)value);\n   Effect(40);\n   return value;\n}\n\nbool SelStruct(datetime value,MqlDateTime &result)\n{\n   Begin();\n   bool ok=TimeToStruct(value,result);\n   End(41,(ulong)value,(ulong)ok);\n   FileWriteInteger(Tape,result.year);\n   FileWriteInteger(Tape,result.mon);\n   FileWriteInteger(Tape,result.day);\n   FileWriteInteger(Tape,result.hour);\n   FileWriteInteger(Tape,result.min);\n   FileWriteInteger(Tape,result.sec);\n   FileWriteInteger(Tape,result.day_of_week);\n   FileWriteInteger(Tape,result.day_of_year);\n   Effect(41);\n   return ok;\n}\n\ndouble SelMod(double left,double right)\n{\n   Begin();\n   double value=MathMod(left,right);\n   End(42,Bits(left),Bits(right),Bits(value));\n   Effect(42);\n   return value;\n}\n\nint SelConcat(string &output,int year,const string &suffix)\n{\n   Begin();\n   if(output!="") SetUserError(900);\n   int value=StringConcatenate(output,year,suffix);\n   End(43,(ulong)(long)year,(ulong)(long)value,0,0,suffix,output);\n   Effect(43);\n   return value;\n}\n\ndatetime SelDate(string value)\n{\n   Begin();\n   datetime result=StringToTime(value);\n   End(44,(ulong)result,0,0,0,value);\n   Effect(44);\n   return result;\n}\n\ndouble SelBalance(ENUM_ACCOUNT_INFO_DOUBLE property)\n{\n   Begin();\n   if(property!=ACCOUNT_BALANCE) SetUserError(901);\n   double value=SelBalanceReply;\n   End(45,(ulong)property,Bits(value));\n   Effect(45);\n   return value;\n}\n\nstring SelCurrency(ENUM_ACCOUNT_INFO_STRING property)\n{\n   Begin();\n   if(property!=ACCOUNT_CURRENCY) SetUserError(901);\n   int index=SelCurrencyIndex;\n   if(index<SelCurrencyCount) SelCurrencyIndex++;\n   else index=SelCurrencyCount-1;\n   string value=SelCurrencies[index];\n   End(46,(ulong)property,0,0,0,value);\n   Effect(46);\n   return value;\n}\n\ndouble SelClose(string symbol,ENUM_TIMEFRAMES timeframe,int shift)\n{\n   Begin();\n   if(timeframe!=PERIOD_D1 || shift!=1) SetUserError(901);\n   int index=SelPriceIndex;\n   if(index<SelPriceCount) SelPriceIndex++;\n   else index=SelPriceCount-1;\n   double value=SelPrices[index];\n   End(47,(ulong)timeframe,(ulong)(long)shift,Bits(value),0,symbol);\n   Effect(47);\n   return value;\n}\n\nvoid SelPrint(string message)\n{\n   Begin();\n   End(48,0,0,0,0,message);\n   Effect(48);\n}\n'

READS='   for(int i=0;i<4;i++) SelClocks[i]=FileReadLong(file);\n   SelBalanceReply=Value((ulong)FileReadLong(file));\n   SelCurrencyCount=FileReadInteger(file);\n   if(SelCurrencyCount<1 || SelCurrencyCount>64) return 8;\n   for(int i=0;i<SelCurrencyCount;i++) SelCurrencies[i]=ReadText(file);\n   SelPriceCount=FileReadInteger(file);\n   if(SelPriceCount<1 || SelPriceCount>64) return 8;\n   for(int i=0;i<SelPriceCount;i++) SelPrices[i]=Value((ulong)FileReadLong(file));\n   SelClockIndex=0;\n   SelCurrencyIndex=0;\n   SelPriceIndex=0;\n'
def render():
    code=OLD_RENDER();code=code.replace('input string CheckRun="";','input string CheckRun="";\n'+DECL_EARLY,1)
    marker='#include "../../Include/bot-cua-toi-3/Bot3StartupContextFlow.mqh"';require(marker in code,'SELECTION_INCLUDE_MARKER');code=code.replace(marker,marker+'\n'+DECL_CALL,1)
    globals_='int WinterHours,SummerHours,Frequency;long AdjustedTime;uchar Thresholds[3],Manual[9],Enabled[9];double FrequencyDivisor;\n'+GLOBALS
    code=code.replace('Bot3StartupTradingState State;',globals_+'\nBot3StartupTradingState State;',1).replace('Counts[39]','Counts[49]')
    code=code.replace('int OnStart()',MOCKS+'\nint OnStart()',1)
    marker='PrepOpenReply=Value((ulong)FileReadLong(file));';require(marker in code,'SELECTION_INPUT_MARKER');code=code.replace(marker,marker+'\n'+READS,1)
    require(c.CALL in code,'SELECTION_FLOW_CALL');return code.replace(c.CALL,CALL).replace('bot3-startup-context-flow','bot3-startup-selection-flow')
class Native(c.Native):
    def __init__(self):
        super().__init__();self.selection_phase=False
        self.selection_sdk={0x7ff6846f1c40:40,0x7ff6846f1f60:41,0x7ff6849c9970:42,self.print_api:43,0x7ff6846ed370:44,0x7ff6846b7370:45,0x7ff6846b7410:46,0x7ff6846f3d40:47}
        for address,api in self.selection_sdk.items():
            if address in self.sdk:continue
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3');self.sdk[address]=api;self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.end_selection,begin=self.base+0x3ce6,end=self.base+0x3ce6)
        for off in [0x7e20,0x8300]:self.m.hook_add(self.uc.UC_HOOK_CODE,self.enter_child,begin=self.base+off,end=self.base+off)
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        md=Cs(CS_ARCH_X86,CS_MODE_64)
        for lo,hi,digest in [(0x3840,0x3ce6,None),(0x7e20,0x82f7,DST_SHA),(0x8300,0xe0b5,CURRENCY_SHA)]:
            raw=bytes(self.m.mem_read(self.base+lo,hi-lo))
            if digest:require(hashlib.sha256(raw).hexdigest()==digest,'SELECTION_CHILD_CHANGED')
            for ins in md.disasm(raw,self.base+lo):
                if ins.mnemonic in self.cpu:self.arithmetic[ins.address]=(ins.mnemonic,ins.op_str);self.m.hook_add(self.uc.UC_HOOK_CODE,self.calculate,begin=ins.address,end=ins.address)
    def begin_preparation(self,m,address,size,user):
        first=not self.started;super().begin_preparation(m,address,size,user)
        for api in range(40,49):self.counts.setdefault(api,0)
        if first:
            self.selection_phase=True;x=self.x;m.reg_write(x.UC_X86_REG_RAX,self.base+0x7e20);m.reg_write(x.UC_X86_REG_RBP,0x7ff6846f1c40);m.reg_write(x.UC_X86_REG_RDI,self.gate['ctx']);m.reg_write(x.UC_X86_REG_RIP,self.base+0x3840)
    def end_selection(self,m,address,size,user):require(self.selection_phase,'SELECTION_ENTERED_TWICE');self.selection_phase=False;self.selection_joins+=1
    def enter_child(self,m,address,size,user):
        require(self.selection_phase,'CHILD_OUTSIDE_SELECTION')
        if address==self.base+0x7e20:self.dst_entries+=1
        else:self.currency_entries+=1
    def service(self,m,address,size,user):
        if not self.selection_phase:return super().service(m,address,size,user)
        require(address in self.selection_sdk,'UNKNOWN_SELECTION_SDK');api=self.selection_sdk[address];x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));sp=reg('RSP')
        if api==43 and reg('RDX')==2:api=48
        r=self.tape;before=r.block();actual=self.state();require(before==actual,'SELECTION_STATE '+str((self.case['id'],api,next((i for i,(a,b) in enumerate(zip(before,actual)) if a!=b),None))))
        kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I');require(kind==api,'SELECTION_SDK_ORDER')
        if api!=42:require(reg('RCX')==self.gate['ctx'],'SELECTION_SDK_CONTEXT')
        replies=self.case['selection']
        if api==40:
            require(reg('RDX')==0 and args[0]==(replies['clocks'][min(self.counts[40],3)]&j.MASK),'SELECTION_CLOCK');m.reg_write(x.UC_X86_REG_RAX,args[0])
        elif api==41:
            require(reg('RDX')==args[0],'SELECTION_STRUCT_ARG');m.mem_write(reg('R8'),struct.pack('<8i',*r.take('8i')));m.reg_write(x.UC_X86_REG_RAX,args[1])
        elif api==42:
            require([reg('XMM0')&j.MASK,reg('XMM1')&j.MASK]==args[:2],'SELECTION_MOD_ARGS');m.reg_write(x.UC_X86_REG_XMM0,args[2])
        elif api==43:
            desc=struct.unpack('<Q',m.mem_read(sp+40,8))[0];literal=struct.unpack('<Q',m.mem_read(sp+72,8))[0];year=struct.unpack('<i',m.mem_read(sp+56,4))[0]
            require((reg('RDX'),reg('R8'),reg('R9'))==(0x174,3,0x59000a) and (year&j.MASK)==args[0] and not self.read_text(desc) and self.read_text(literal)==texts[0],'SELECTION_CONCAT_ARGS')
            require(struct.unpack('<I',m.mem_read(sp+48,4))[0]==0x520004 and struct.unpack('<I',m.mem_read(sp+64,4))[0]==0x590008,'SELECTION_CONCAT_TYPES');self.put_text(desc-self.base,texts[1]);m.reg_write(x.UC_X86_REG_RAX,args[1])
        elif api==44:require(self.read_text(reg('RDX'))==texts[0],'SELECTION_DATE_ARG');m.reg_write(x.UC_X86_REG_RAX,args[0])
        elif api==45:require(reg('RDX')==args[0]==37 and args[1]==boot.bits(replies['balance']),'SELECTION_BALANCE');m.mem_write(self.base+0x1d6e48,struct.pack('<Q',args[1]))
        elif api==46:
            values=replies['currencies'];require(reg('RDX')==args[0]==36 and (texts[0] or '')==values[min(self.counts[46],len(values)-1)],'SELECTION_CURRENCY');self.put_text(0x1d6e3c,texts[0])
        elif api==47:
            values=replies['prices'];require(args[:2]==[reg('R8'),reg('R9')]==[16408,1] and self.read_text(reg('RDX'))==texts[0] and args[2]==boot.bits(values[min(self.counts[47],len(values)-1)]),'SELECTION_PRICE');m.mem_write(self.base+0x1d6e48,struct.pack('<Q',args[2]));m.reg_write(x.UC_X86_REG_XMM0,args[2])
        elif api==48:
            desc=struct.unpack('<Q',m.mem_read(sp+40,8))[0];require((reg('RDX'),reg('R8'),reg('R9'))==(2,1,0x590008) and self.read_text(desc)==texts[0],'SELECTION_PRINT')
        self.counts[api]+=1;self.effect(api);self.calls+=1;m.mem_write(self.base+0x1d6e10,struct.pack('<I',error))
    def run(self,row,tape):
        self.selection_phase=False;self.selection_joins=self.dst_entries=self.currency_entries=0
        expected=int(row['values']['Frequency']==5 and row['values']['Inputs.native_1d7130']==1234)
        value=super().run(row,tape);require(self.selection_joins==self.dst_entries==1 and self.currency_entries==expected,'SELECTION_ENTRY_COUNTS');return value
def identity():
    current=OLD_IDENTITY();src=ROOT/'bot-cua-toi-3/source/MQL5';script=src/'Scripts/bot-cua-toi-3/Bot3StartupSelectionFlowCheck.mq5'
    current['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in j.pub.closure(script,src)}
    for p in [Path(__file__),Path(sel.__file__),Path(driver.__file__)]:current['helpers_sha256'][p.relative_to(ROOT).as_posix()]=sha(p)
    current.update(native_dst_sha256=DST_SHA,native_currency_sha256=CURRENCY_SHA);return current
for name in ['execute','main']:
    source=c.port.port(inspect.getsource(getattr(driver,name))).replace('Bot3StartupPostPreparationCheck','Bot3StartupSelectionFlowCheck').replace('bot3-startup-joined','bot3-startup-selection-flow').replace('startup-joined-','startup-selection-flow-').replace('table_cells=1800','table_cells=2800')
    source=source.replace('calls=cpu=joins=0','calls=cpu=joins=dst=currency=0').replace('joins+=o.joins','joins+=o.joins;dst+=o.dst_entries;currency+=o.currency_entries').replace('joins=joins','joins=joins,dst_entries=dst,currency_entries=currency')
    source=source.replace('Continuous after first preparation through normal return only.','Continuous time/currency selection, context, first preparation and tail.').replace('earlier OnInit and full EA remain unverified.','OnInit before selection and full EA remain unverified.')
    exec(compile(source,__file__,'exec'),j.__dict__)
j.cases=cases;j.encode=encode;j.render=render;j.Native=Native;j.identity=identity
j.SCOPE=dict(j.SCOPE,native_frequency_selection_executed=True,native_dst_body_executed=True,native_currency_body_executed=True,dst_child_reply_supplied=False,currency_child_reply_supplied=False)
if __name__=='__main__':j.main()
