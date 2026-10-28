"""Execute both entry-level searches and their pending-order guards in startup.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Extends the real-calendar startup proof; only chart and order service replies
are supplied. No trade is placed and no entry-level result is supplied.
"""
import copy,hashlib,importlib.util,inspect,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
s=importlib.util.spec_from_file_location('entry_calendar_flow',ROOT/'cong-cu/kiem-noi-lich-that-khoi-dong-bot-1.py');cal=importlib.util.module_from_spec(s);s.loader.exec_module(cal)
j,require,sha=cal.j,cal.require,cal.sha
BASE_CASES=cal.cases();BASE_RENDER=cal.render;BASE_IDENTITY=cal.identity;BASE_ENCODE=cal.encode

def cases():
    rows=[]
    def add(tag,changes=None,**data):
        c=copy.deepcopy(BASE_CASES[7]);c.update(id=len(rows),tag=tag,effects=[])
        c['values'].update({'ChartName':'XAUUSD','ContextInputs.base_magic':9001,'Inputs.variable_distances':0,'Inputs.adjust_lots':0,
          'Inputs.entry.older_width':1,'Inputs.entry.recent_width':1,'Inputs.entry.last_shift':8,'Inputs.entry.gap_points':.1,
          'Inputs.buy_offset':2.,'Inputs.sell_offset':3.,'Inputs.nearby_radius':5.})
        c['entry_data']=dict(high=[2000.,2000.,2010.,2000.,2015.,2000.]+[2000.]*10,
          low=[2002.,2002.,1990.,2002.,1985.,2002.]+[2002.]*10,orders=[],digits=2)
        c['values'].update(changes or {});c['entry_data'].update(data);rows.append(c);return c
    for older in [0,1,3]:
        for recent in [0,1,3]:
            for last in [0,3,8]:add('entry-window-and-limits',{'Inputs.entry.older_width':older,'Inputs.entry.recent_width':recent,'Inputs.entry.last_shift':last})
    for size in [0,1,2,3,16]:add('entry-history-size',high=[2000.]*size,low=[2002.]*size)
    for digits in [-1,0,1,2,3,5,11,12]:add('entry-rounding',digits=digits)
    for buy in [True,False]:
        level,offset,kind=(2010.,.02,4) if buy else (1990.,-.03,5)
        for delta in [-1.001,-1.,-.999,0.,.999,1.,1.001]:
            add('nearby-boundary',orders=[[11,9001,kind,level+offset+delta*.05,'XAUUSD']])
        for mismatch in ['magic','symbol','type','zero-ticket']:
            order=[11,9001,kind,level+offset,'XAUUSD'];order[{'magic':1,'symbol':4,'type':2,'zero-ticket':0}[mismatch]]={'magic':9002,'symbol':'OTHER','type':0,'zero-ticket':0}[mismatch]
            add('nearby-filter-'+mismatch,orders=[order])
        for blocked in [1,2]:
            levels=([2010.,2015.] if buy else [1990.,1985.])[:blocked]
            add('entry-blocked-candidates',orders=[[i+1,9001,kind,value+offset,'XAUUSD'] for i,value in enumerate(levels)])
    for title in ['',None,'Vàng🚀']:
        add('entry-order-symbol',{'ChartName':title},orders=[[11,9001,4,2010.02,title]])
    for field in ['high','low']:
        for value in [float('nan'),float('inf'),-float('inf'),0.,-0.]:add('entry-special-price',**{field:[value]*16})
    for index in range(152,158):
        c=add('entry-after-calendar-error');c['calendars']=copy.deepcopy(BASE_CASES[index]['calendars'])
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',j.MAGIC,1,len(rows)))
    for c in rows:
        raw+=BASE_ENCODE([c])[12:];d=c['entry_data'];raw+=struct.pack('<q',d['digits'])
        for field in ['high','low']:raw+=struct.pack('<i',len(d[field]))+b''.join(struct.pack('<d',v) for v in d[field])
        raw+=struct.pack('<i',len(d['orders']))
        for ticket,magic,kind,price,symbol in d['orders']:raw+=struct.pack('<Qqid',ticket,magic,kind,price)+cal.cal.base.text(symbol)
    return bytes(raw)

DECL=r'''
double EntryHigh(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
double EntryLow(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
int EntryOrdersTotal();ulong EntryOrderTicket(const int index);
long EntryOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property);
string EntryOrderString(const ENUM_ORDER_PROPERTY_STRING property);
double EntryOrderDouble(const ENUM_ORDER_PROPERTY_DOUBLE property);
long EntrySymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property);
#define iHigh EntryHigh
#define iLow EntryLow
#define OrdersTotal EntryOrdersTotal
#define OrderGetTicket EntryOrderTicket
#define OrderGetInteger EntryOrderInteger
#define OrderGetString EntryOrderString
#define OrderGetDouble EntryOrderDouble
#define SymbolInfoInteger EntrySymbolInteger
#include "../../Include/bot-cua-toi-1/Bot1EntryLevels.mqh"
#undef iHigh
#undef iLow
#undef OrdersTotal
#undef OrderGetTicket
#undef OrderGetInteger
#undef OrderGetString
#undef OrderGetDouble
#undef SymbolInfoInteger
'''
GLOBALS='double EntryHighValues[],EntryLowValues[];long EntryDigits;int EntrySelected=-1;\nstruct EntryOrderData{ulong ticket;long magic;int kind;double price;string symbol;};EntryOrderData EntryOrders[];\n'
MOCKS=r'''
double EntryHigh(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();double value=shift>=0 && shift<ArraySize(EntryHighValues) ? EntryHighValues[shift] : 0.;End(70,(ulong)frame,(ulong)(long)shift,Bits(value),0,symbol);Effect(70);return value;}
double EntryLow(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();double value=shift>=0 && shift<ArraySize(EntryLowValues) ? EntryLowValues[shift] : 0.;End(71,(ulong)frame,(ulong)(long)shift,Bits(value),0,symbol);Effect(71);return value;}
int EntryOrdersTotal(){Begin();int value=ArraySize(EntryOrders);End(72,(ulong)value);Effect(72);return value;}
ulong EntryOrderTicket(const int index){Begin();EntrySelected=index;ulong value=index>=0 && index<ArraySize(EntryOrders) ? EntryOrders[index].ticket : 0;End(73,(ulong)(long)index,value);Effect(73);return value;}
long EntryOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property){Begin();long value=property==ORDER_MAGIC ? EntryOrders[EntrySelected].magic : EntryOrders[EntrySelected].kind;End(74,(ulong)property,(ulong)value);Effect(74);return value;}
string EntryOrderString(const ENUM_ORDER_PROPERTY_STRING property){Begin();string value=EntryOrders[EntrySelected].symbol;End(75,(ulong)property,0,0,0,value);Effect(75);return value;}
double EntryOrderDouble(const ENUM_ORDER_PROPERTY_DOUBLE property){Begin();double value=EntryOrders[EntrySelected].price;End(76,(ulong)property,Bits(value));Effect(76);return value;}
long EntrySymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property){Begin();End(77,(ulong)property,(ulong)EntryDigits,0,0,symbol);Effect(77);return EntryDigits;}
'''

def render():
    code=BASE_RENDER().replace('input string CheckRun="";','input string CheckRun="";\n'+DECL,1)
    code=code.replace('#define Bot1EntryLevel MockLevel\n','').replace('#undef Bot1EntryLevel\n','')
    code=code.replace('Counts[66]','Counts[78]').replace('int CalendarKind=-1;',GLOBALS+'\nint CalendarKind=-1;',1)
    code=code.replace('int OnStart()',MOCKS+'\nint OnStart()',1)
    marker='InjectedCalendarError=-1;CalendarKind=-1;';require(marker in code,'ENTRY_READ_MARKER')
    reads='''
EntryDigits=FileReadLong(file);int entry_count=(int)FileReadInteger(file);if(entry_count<0 || entry_count>128)return 8;ArrayResize(EntryHighValues,entry_count);for(int i=0;i<entry_count;i++)EntryHighValues[i]=FileReadDouble(file);entry_count=FileReadInteger(file);if(entry_count<0 || entry_count>128)return 8;ArrayResize(EntryLowValues,entry_count);for(int i=0;i<entry_count;i++)EntryLowValues[i]=FileReadDouble(file);entry_count=FileReadInteger(file);if(entry_count<0 || entry_count>32)return 8;ArrayResize(EntryOrders,entry_count);for(int i=0;i<entry_count;i++){EntryOrders[i].ticket=(ulong)FileReadLong(file);EntryOrders[i].magic=FileReadLong(file);EntryOrders[i].kind=FileReadInteger(file);EntryOrders[i].price=FileReadDouble(file);EntryOrders[i].symbol=ReadText(file);}EntrySelected=-1;
'''
    return code.replace(marker,marker+reads).replace('bot1-startup-real-calendars','bot1-startup-real-entry')

class Native(cal.Native):
    def __init__(self):
        super().__init__();self.entry_selected=-1
        meta=json.loads((ROOT/'bot-cua-toi-1/phan-tich/luot-20261023-data-v2/metadata/import.json').read_text())
        starts=[0x265a0,0x26960,0x3c670,0x3c8d0];self.entry_ranges=[];self.entry_hashes={}
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        decoder=Cs(CS_ARCH_X86,CS_MODE_64)
        for begin in starts:
            end=int(next(f['end_rva'] for f in meta['functions'] if int(f['begin_rva'],16)==begin),16);raw=bytes(self.m.mem_read(self.base+begin,end-begin));self.entry_ranges.append((begin,end));self.entry_hashes[hex(begin)]=hashlib.sha256(raw).hexdigest()
            for ins in decoder.disasm(raw,self.base+begin):
                if ins.mnemonic in self.cpu:self.arithmetic[ins.address]=(ins.mnemonic,ins.op_str);self.m.hook_add(self.uc.UC_HOOK_CODE,self.calculate,begin=ins.address,end=ins.address)
        self.entry_sdk={0x7ff6846f3c40:70,0x7ff6846f3cc0:71,0x7ff6846f81a0:72,0x7ff6846f81f0:73,0x7ff6846f8310:74,0x7ff6846f83a0:75,0x7ff6846f8280:76}
        for address,api in self.entry_sdk.items():
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3');self.sdk[address]=api
            # These SDK addresses already have the original base-class call hook;
            # it returns for self.sdk. Add the recorder hook once here.
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
    def begin_preparation(self,m,address,size,user):
        first=not self.started;super().begin_preparation(m,address,size,user)
        for api in range(70,78):self.counts.setdefault(api,0)
        if first:self.entry_selected=-1
    def service(self,m,address,size,user):
        if address in [self.base+0x265a0,self.base+0x26960]:return
        api=self.entry_sdk.get(address);x=self.x;reg=lambda name:m.reg_read(getattr(x,'UC_X86_REG_'+name));sp=reg('RSP')
        ret=struct.unpack('<Q',m.mem_read(sp,8))[0]-self.base
        if address==0x7ff6846e2970 and any(lo<=ret<hi for lo,hi in self.entry_ranges):api=77
        if api is None:return super().service(m,address,size,user)
        r=self.tape;expected=r.block();actual=self.state();require(expected==actual,'ENTRY_STATE '+str((self.case['id'],api,next((i for i,(u,v) in enumerate(zip(expected,actual)) if u!=v),None))))
        kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I');require(kind==api and reg('RCX')==self.gate['ctx'],'ENTRY_API_ORDER_OR_CONTEXT');data=self.case['entry_data'];reply=0
        if api in [70,71]:
            shift=struct.unpack('<i',struct.pack('<I',reg('R9')&0xffffffff))[0];values=data['high' if api==70 else 'low'];value=values[shift] if 0<=shift<len(values) else 0.
            require(args[:2]==[reg('R8'),shift&j.MASK] and texts==[self.read_text(reg('RDX')),None] and args[2]==cal.n.a.boot.bits(value),'ENTRY_PRICE_ARGS');reply=args[2]
        elif api==72:require(args[0]==len(data['orders']),'ENTRY_ORDER_COUNT');reply=args[0]
        elif api==73:
            index=struct.unpack('<i',struct.pack('<I',reg('RDX')&0xffffffff))[0];self.entry_selected=index;value=data['orders'][index][0] if 0<=index<len(data['orders']) else 0
            require(args[:2]==[index&j.MASK,value],'ENTRY_ORDER_TICKET');reply=value
        elif api in [74,75,76]:
            require(0<=self.entry_selected<len(data['orders']),'ENTRY_ORDER_NOT_SELECTED');order=data['orders'][self.entry_selected];prop=reg('RDX');require(args[0]==prop,'ENTRY_ORDER_PROPERTY')
            if api==74:require(prop in [15,4] and args[1]==order[1 if prop==15 else 2]&j.MASK,'ENTRY_ORDER_INTEGER');reply=args[1]
            elif api==75:require(prop==0 and texts==[order[4],None],'ENTRY_ORDER_SYMBOL');self.put_text(0x6a43c,texts[0])
            else:require(prop==9 and args[1]==cal.n.a.boot.bits(order[3]),'ENTRY_ORDER_PRICE');reply=args[1]
        else:require(reg('R8')==args[0]==17 and texts==[self.read_text(reg('RDX')),None] and args[1]==data['digits']&j.MASK,'ENTRY_DIGITS');reply=args[1]
        self.counts[api]+=1;self.effect(api);self.calls+=1;m.mem_write(self.base+0x6a410,struct.pack('<I',error))
        if api in [70,71,76]:m.mem_write(self.base+0x6a448,struct.pack('<Q',reply))
        else:m.reg_write(x.UC_X86_REG_RAX,reply)

def identity():
    current=BASE_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupRealEntryCheck.mq5'
    current['sources_sha256']={f.relative_to(src).as_posix():sha(f) for f in j.pub.closure(script,src)}
    current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return current

temp=cal.n.a.load('real_entry_runner','kiem-noi-khoi-dong-bot-1.py')
for function in ['execute','main']:
    code=inspect.getsource(getattr(temp,function)).replace('Bot1StartupPostPreparationCheck','Bot1StartupRealEntryCheck').replace('bot1-startup-joined','bot1-startup-real-entry').replace('startup-joined-','startup-real-entry-')
    code=code.replace('Continuous after first preparation through normal return only.','Continuous startup after authorization, including actual calendar and entry-level/nearby-order bodies.').replace('Two entry-level and three panel children recorded;','Three panel children recorded;').replace('earlier OnInit and full EA remain unverified.','authorization, exact final fault states and full EA remain unverified.')
    exec(compile(code,__file__,'exec'),j.__dict__)
j.cases=cases;j.encode=encode;j.render=render;j.identity=identity;j.Native=Native
j.SCOPE=dict(j.SCOPE,entry_level_children_supplied=False,native_entry_level_bodies_executed=True,native_nearby_order_bodies_executed=True,bar_price_and_order_replies_supplied=True)
if __name__=='__main__':j.main()
