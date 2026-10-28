"""Execute all three display bodies inside startup after the authorization gate.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Does not execute or substitute account authorization. Chart/position/history
services are recorded test boundaries; every panel body executes unchanged.
"""
import copy,hashlib,importlib.util,inspect,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
s=importlib.util.spec_from_file_location('panel_entry_flow',ROOT/'cong-cu/kiem-noi-muc-gia-that-khoi-dong-bot-1.py');entry=importlib.util.module_from_spec(s);s.loader.exec_module(entry)
j,require,sha=entry.j,entry.require,entry.sha
BASE_CASES=entry.cases();BASE_RENDER=entry.render;BASE_ENCODE=entry.encode;BASE_IDENTITY=entry.identity

def cases():
    out=[]
    def add(tag,changes=None,**panel):
        c=copy.deepcopy(BASE_CASES[0]);c.update(id=len(out),tag=tag,effects=[])
        c['values'].update({'Panel.font':8,'Panel.scale':1.,'Panel.mode':0,'Panel.trade_risk':1.25,'Panel.balance_step':600,'ContextInputs.base_magic':9001,'ChartName':'XAUUSD','Show':1,'Tester':1})
        c['values'].update(changes or {})
        c['display']=dict(info=0,find=-1,ok=1,error=0,clock=1790000000,history_select=1,
          positions=[[21,9002,0,10.,-.5,1,'XAUUSD']],history=[[31,9002,10.,-1.,-.5,'XAUUSD'],[32,9009,-4.,-.5,0.,'XAUUSD']])
        c['display'].update(panel);c['info']=c['display']['info'];c['select']=c['display']['history_select'];c['total']=len(c['display']['history'])
        c['deals']=[[r[0],1790000000,r[1],.1] for r in c['display']['history']];out.append(c);return c
    for show,tester,info in [(0,0,0),(1,0,1),(1,1,1),(1,0,0),(255,255,0)]:add('panel-gates',{'Show':show,'Tester':tester},info=info)
    for mode in [-1,0,3,999,9999]:add('panel-risk-mode',{'Panel.mode':mode})
    for font,scale,flag in [(0,0.,0),(7,.75,1),(19,1.25,255),(-1,-.75,2),(2147483647,1.,1)]:add('panel-layout',{'Panel.font':font,'Panel.scale':scale,'Panel.color_flag':flag})
    for group in [1,8,9]:
        for side in [0,1,2]:add('open-position-filter',positions=[[21,9001+group,side,12.,-.5,1,'XAUUSD']])
    for positions in [[],[[0,9002,0,10.,0.,1,'XAUUSD']],[[21,9002,0,10.,0.,1,'OTHER']],[[21,9002,0,10.,0.,0,'XAUUSD']],
                      [[21,9002,0,1e16,-1e16,1,'XAUUSD'],[22,9009,1,1.,0.,1,'XAUUSD']]]:add('open-position-cases',positions=positions)
    for history in [[],[[0,9002,10.,-1.,-.5,'XAUUSD']],[[31,9002,0.,-1.,-.5,'XAUUSD']],[[31,9002,-10.,1.,.5,'XAUUSD']],
                    [[31,9002,10.,-1.,-.5,'OTHER']],[[31,9010,10.,-1.,-.5,'XAUUSD']]]:add('closed-history-cases',history=history)
    for find,ok,error in [(-1,0,4202),(0,1,0),(2,0,4001)]:add('chart-service-replies',find=find,ok=ok,error=error)
    add('history-select-failed',history_select=0)
    for flag in [0,2,255]:add('closed-history-flag',{'Panel.closed_star':flag})
    return out

def encode(rows):
    raw=bytearray(struct.pack('<3i',j.MAGIC,1,len(rows)))
    for c in rows:
        raw+=BASE_ENCODE([c])[12:];p=c['display'];raw+=struct.pack('<6q',p['info'],p['find'],p['ok'],p['error'],p['clock'],p['history_select'])
        raw+=struct.pack('<i',len(p['positions']))
        for ticket,magic,kind,profit,swap,selected,symbol in p['positions']:raw+=struct.pack('<Qqi2di',ticket,magic,kind,profit,swap,selected)+entry.cal.cal.base.text(symbol)
        raw+=struct.pack('<i',len(p['history']))
        for ticket,magic,profit,commission,swap,symbol in p['history']:raw+=struct.pack('<Qq3d',ticket,magic,profit,commission,swap)+entry.cal.cal.base.text(symbol)
    return bytes(raw)

DECL=r'''
string PanelIntegerText(const long value,const int width=0,const ushort fill=32);
string PanelDoubleText(const double value,const int digits=8);
string Bot1PanelDoubleText(const double value);string Bot1PanelIntegerText(const int value);string Bot1PanelTimeText(const datetime value);
bool PanelObjectCreate(const long chart,const string name,const ENUM_OBJECT kind,const int window,const datetime time,const double price);
bool PanelObjectInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value);
bool PanelObjectText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value);
int PanelObjectFind(const long chart,const string name);
datetime PanelServer();int PanelInfo(const ENUM_MQL_INFO_INTEGER property);
int PanelPositions();ulong PanelPositionTicket(const int index);string PanelPositionString(const ENUM_POSITION_PROPERTY_STRING property);
long PanelPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property);bool PanelPositionSelect(const ulong ticket);double PanelPositionDouble(const ENUM_POSITION_PROPERTY_DOUBLE property);
bool PanelHistorySelect(const datetime from,const datetime to);int PanelHistoryTotal();ulong PanelHistoryTicket(const int index);
long PanelHistoryInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property);string PanelHistoryString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property);double PanelHistoryDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property);
void PanelUserError(const ushort code);
'''
INCLUDES=r'''
#define BOT1_PANEL_TEXT_CASTS_MQH
#define IntegerToString PanelIntegerText
#define DoubleToString PanelDoubleText
#define ObjectCreate PanelObjectCreate
#define ObjectSetInteger PanelObjectInteger
#define ObjectSetString PanelObjectText
#define ObjectFind PanelObjectFind
#define TimeTradeServer PanelServer
#define MQLInfoInteger PanelInfo
#define PositionsTotal PanelPositions
#define PositionGetTicket PanelPositionTicket
#define PositionGetString PanelPositionString
#define PositionGetInteger PanelPositionInteger
#define PositionSelectByTicket PanelPositionSelect
#define PositionGetDouble PanelPositionDouble
#define HistorySelect PanelHistorySelect
#define HistoryDealsTotal PanelHistoryTotal
#define HistoryDealGetTicket PanelHistoryTicket
#define HistoryDealGetInteger PanelHistoryInteger
#define HistoryDealGetString PanelHistoryString
#define HistoryDealGetDouble PanelHistoryDouble
#define SetUserError PanelUserError
#include "../../Include/bot-cua-toi-1/Bot1PanelCreation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ClosedStatusPanel.mqh"
#undef IntegerToString
#undef DoubleToString
#undef ObjectCreate
#undef ObjectSetInteger
#undef ObjectSetString
#undef ObjectFind
#undef TimeTradeServer
#undef MQLInfoInteger
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetString
#undef PositionGetInteger
#undef PositionSelectByTicket
#undef PositionGetDouble
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef HistoryDealGetInteger
#undef HistoryDealGetString
#undef HistoryDealGetDouble
#undef SetUserError
'''
GLOBALS=r'''
int DisplayInfo,DisplayFind,DisplayOk,DisplayError,DisplayHistorySelect,DisplaySelected=-1,DisplayDeal=-1;long DisplayClock;
struct DisplayPosition{ulong ticket;long magic;int kind;double profit,swap;int selected;string symbol;};DisplayPosition DisplayPositions[];
struct DisplayDealRow{ulong ticket;long magic;double profit,commission,swap;string symbol;};DisplayDealRow DisplayDeals[];
'''
MOCKS=r'''
void PanelEnd(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,const ulong e=0,const string name=NULL,const string value=NULL,const ulong reply=0){FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Word(d);Text(name);Text(value);FileWriteInteger(Tape,(int)GetLastError());Word(e);Word(reply);Effect(api);}
string PanelIntegerText(const long value,const int width=0,const ushort fill=32){Begin();string text=IntegerToString(value,width,fill);PanelEnd(80,(ulong)value,(ulong)(uint)width,(ulong)fill,0,0,text);return text;}
string PanelDoubleText(const double value,const int digits=8){Begin();string text=DoubleToString(value,digits);PanelEnd(81,Bits(value),(ulong)(uint)digits,0,0,0,text);return text;}
string Bot1PanelDoubleText(const double value){Begin();string text=(string)value;PanelEnd(82,Bits(value),0x58,0,0,0,text);return text;}
string Bot1PanelIntegerText(const int value){Begin();string text=(string)value;PanelEnd(82,(ulong)(long)value,0x52,0,0,0,text);return text;}
string Bot1PanelTimeText(const datetime value){Begin();string text=(string)value;PanelEnd(82,(ulong)value,0x54,0,0,0,text);return text;}
bool PanelObjectCreate(const long chart,const string name,const ENUM_OBJECT kind,const int window,const datetime time,const double price){Begin();InjectedCalendarError=DisplayError;PanelEnd(83,(ulong)chart,(ulong)kind,(ulong)(uint)window,(ulong)time,Bits(price),name,NULL,(ulong)DisplayOk);return DisplayOk!=0;}
bool PanelObjectInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value){Begin();InjectedCalendarError=DisplayError;PanelEnd(84,(ulong)chart,(ulong)property,(ulong)value,0,0,name,NULL,(ulong)DisplayOk);return DisplayOk!=0;}
bool PanelObjectText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value){Begin();InjectedCalendarError=DisplayError;PanelEnd(85,(ulong)chart,(ulong)property,0,0,0,name,value,(ulong)DisplayOk);return DisplayOk!=0;}
int PanelObjectFind(const long chart,const string name){Begin();InjectedCalendarError=DisplayError;PanelEnd(86,(ulong)chart,0,0,0,0,name,NULL,(ulong)(long)DisplayFind);return DisplayFind;}
datetime PanelServer(){Begin();PanelEnd(87,0,0,0,0,0,NULL,NULL,(ulong)DisplayClock);return (datetime)DisplayClock;}
int PanelInfo(const ENUM_MQL_INFO_INTEGER property){Begin();PanelEnd(88,(ulong)property,0,0,0,0,NULL,NULL,(ulong)(long)DisplayInfo);return DisplayInfo;}
int PanelPositions(){Begin();int value=ArraySize(DisplayPositions);PanelEnd(89,0,0,0,0,0,NULL,NULL,(ulong)value);return value;}
ulong PanelPositionTicket(const int index){Begin();DisplaySelected=index;ulong value=index>=0 && index<ArraySize(DisplayPositions) ? DisplayPositions[index].ticket : 0;PanelEnd(90,(ulong)(long)index,0,0,0,0,NULL,NULL,value);return value;}
string PanelPositionString(const ENUM_POSITION_PROPERTY_STRING property){Begin();string value=DisplayPositions[DisplaySelected].symbol;PanelEnd(91,(ulong)property,0,0,0,0,value);return value;}
long PanelPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property){Begin();long value=property==12 ? DisplayPositions[DisplaySelected].magic : DisplayPositions[DisplaySelected].kind;PanelEnd(92,(ulong)property,0,0,0,0,NULL,NULL,(ulong)value);return value;}
bool PanelPositionSelect(const ulong ticket){Begin();bool value=DisplayPositions[DisplaySelected].selected!=0;PanelEnd(93,ticket,0,0,0,0,NULL,NULL,(ulong)value);return value;}
double PanelPositionDouble(const ENUM_POSITION_PROPERTY_DOUBLE property){Begin();double value=property==10 ? DisplayPositions[DisplaySelected].swap : DisplayPositions[DisplaySelected].profit;PanelEnd(94,(ulong)property,0,0,0,0,NULL,NULL,Bits(value));return value;}
bool PanelHistorySelect(const datetime from,const datetime to){Begin();PanelEnd(95,(ulong)from,(ulong)to,0,0,0,NULL,NULL,(ulong)DisplayHistorySelect);return DisplayHistorySelect!=0;}
int PanelHistoryTotal(){Begin();int value=ArraySize(DisplayDeals);PanelEnd(96,0,0,0,0,0,NULL,NULL,(ulong)value);return value;}
ulong PanelHistoryTicket(const int index){Begin();DisplayDeal=index;ulong value=index>=0 && index<ArraySize(DisplayDeals) ? DisplayDeals[index].ticket : 0;PanelEnd(97,(ulong)(uint)index,0,0,0,0,NULL,NULL,value);return value;}
long PanelHistoryInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER property){Begin();long value=DisplayDeals[DisplayDeal].magic;PanelEnd(98,ticket,(ulong)property,0,0,0,NULL,NULL,(ulong)value);return value;}
string PanelHistoryString(const ulong ticket,const ENUM_DEAL_PROPERTY_STRING property){Begin();string value=DisplayDeals[DisplayDeal].symbol;PanelEnd(99,ticket,(ulong)property,0,0,0,value);return value;}
double PanelHistoryDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE property){Begin();double value=property==9 ? DisplayDeals[DisplayDeal].profit : (property==7 ? DisplayDeals[DisplayDeal].commission : DisplayDeals[DisplayDeal].swap);PanelEnd(100,ticket,(ulong)property,0,0,0,NULL,NULL,Bits(value));return value;}
'''

def render():
    code=BASE_RENDER().replace('input string CheckRun="";','input string CheckRun="";\n'+DECL,1)
    # The selector was already included with its news-clock recorder. The panel
    # calls that same selector, so its server events keep their existing ID 56.
    anchor='#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"'
    require(anchor in code,'PANEL_INCLUDE_ANCHOR');code=code.replace(anchor,INCLUDES+'\n'+anchor,1)
    for name in ['Bot1CreateInfoPanel','Bot1UpdateOpenStatusPanel','Bot1UpdateClosedStatusPanel']:
        import re
        code=re.sub(r'^#define '+name+r' \w+\n','',code,flags=re.M);code=code.replace('#undef '+name+'\n','')
    code=code.replace('Counts[78]','Counts[101]').replace('int CalendarKind=-1;',GLOBALS+'\nint CalendarKind=-1;',1)
    code=code.replace('int OnStart()',MOCKS+'\nint OnStart()',1)
    marker='EntryOrders[i].symbol=ReadText(file);}EntrySelected=-1;\n';require(code.count(marker)==1,'PANEL_READ_MARKER')
    reads='''
DisplayInfo=(int)FileReadLong(file);DisplayFind=(int)FileReadLong(file);DisplayOk=(int)FileReadLong(file);DisplayError=(int)FileReadLong(file);DisplayClock=FileReadLong(file);DisplayHistorySelect=(int)FileReadLong(file);int display_count=FileReadInteger(file);if(display_count<0 || display_count>32)return 8;ArrayResize(DisplayPositions,display_count);for(int i=0;i<display_count;i++){DisplayPositions[i].ticket=(ulong)FileReadLong(file);DisplayPositions[i].magic=FileReadLong(file);DisplayPositions[i].kind=FileReadInteger(file);DisplayPositions[i].profit=FileReadDouble(file);DisplayPositions[i].swap=FileReadDouble(file);DisplayPositions[i].selected=FileReadInteger(file);DisplayPositions[i].symbol=ReadText(file);}display_count=FileReadInteger(file);if(display_count<0 || display_count>32)return 8;ArrayResize(DisplayDeals,display_count);for(int i=0;i<display_count;i++){DisplayDeals[i].ticket=(ulong)FileReadLong(file);DisplayDeals[i].magic=FileReadLong(file);DisplayDeals[i].profit=FileReadDouble(file);DisplayDeals[i].commission=FileReadDouble(file);DisplayDeals[i].swap=FileReadDouble(file);DisplayDeals[i].symbol=ReadText(file);}DisplaySelected=-1;DisplayDeal=-1;
'''
    code=code.replace(marker,marker+reads,1)
    code+='\nvoid PanelUserError(const ushort code){SetUserError(code);InjectedCalendarError=GetLastError();}\n'
    return code.replace('bot1-startup-real-entry','bot1-startup-real-panels')

class Native(entry.Native):
    def __init__(self):
        super().__init__();self.panel_phase=False;self.panel_kind=0;self.position_index=-1;self.deal_index=-1
        # This test starts after authorization. Abort rather than supply an
        # account identity, tester flag or remote response to protected code.
        for begin in [0xc30,0x5880,0x3d6c0,0x4d260]:
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.protected_boundary,begin=self.base+begin,end=self.base+begin)
        offsets=[0x7cdfe0,0x7cd7c0,0x7cf6c0,0x7b49f0,0x7c3b30,0x7c3c80,0x7c4840,0x7d1ce0,0x7c0fd0,0x7d7da0,0x7d7df0,0x7d8010,0x7d7fc0,0x7d7ee0,0x7d7f70,0x7d84f0,0x7d8810,0x7d8860,0x7d8940,0x7d89d0,0x7d88b0]
        self.panel_sdk={0x7ff683f20000+off:80+i for i,off in enumerate(offsets)}
        for address,api in self.panel_sdk.items():
            if address not in self.sdk:
                if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
                self.m.mem_write(address,b'\xc3');self.sdk[address]=api;self.m.hook_add(self.uc.UC_HOOK_CODE,self.service,begin=address,end=address)
        meta=json.loads((ROOT/'bot-cua-toi-1/phan-tich/luot-20261023-data-v2/metadata/import.json').read_text());self.panel_hashes={}
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        for begin in [0x8320,0xe1b0,0xffb0,0x45b70,0x47740]:
            end=int(next(f['end_rva'] for f in meta['functions'] if int(f['begin_rva'],16)==begin),16);raw=bytes(self.m.mem_read(self.base+begin,end-begin));self.panel_hashes[hex(begin)]=hashlib.sha256(raw).hexdigest()
            for ins in Cs(CS_ARCH_X86,CS_MODE_64).disasm(raw,self.base+begin):
                if ins.mnemonic in self.cpu:self.arithmetic[ins.address]=(ins.mnemonic,ins.op_str);self.m.hook_add(self.uc.UC_HOOK_CODE,self.calculate,begin=ins.address,end=ins.address)
    def protected_boundary(self,m,address,size,user):
        raise RuntimeError('AUTHORIZATION_OUTSIDE_PANEL_SCOPE '+hex(address-self.base))
    def begin_preparation(self,m,address,size,user):
        first=not self.started;super().begin_preparation(m,address,size,user)
        for api in range(80,101):self.counts.setdefault(api,0)
        if first:self.panel_phase=False;self.panel_kind=0;self.position_index=self.deal_index=-1
    def service(self,m,address,size,user):
        if address in [self.base+0x8320,self.base+0xe1b0,self.base+0xffb0]:
            self.panel_phase=True;self.panel_kind=[0x8320,0xe1b0,0xffb0].index(address-self.base)+1;return
        if not self.panel_phase:return super().service(m,address,size,user)
        require(address in self.panel_sdk,'UNKNOWN_PANEL_API '+hex(address));api=self.panel_sdk[address];x=self.x;reg=lambda name:m.reg_read(getattr(x,'UC_X86_REG_'+name));sp=reg('RSP');r=self.tape
        expected=r.block();actual=self.state();require(expected==actual,'PANEL_STATE '+str((self.case['id'],self.panel_kind,api,next((i for i,(u,v) in enumerate(zip(expected,actual)) if u!=v),None))))
        kind,*args=r.take('i4Q');texts=[r.text(),r.text()];error,=r.take('I')
        # The shared selector still emits its inherited news-server event.
        if api==87 and kind==56:
            require(reg('RCX')==self.gate['ctx'] and reg('RDX')==0 and args[0]==self.case['news']['clocks'][min(self.counts[56],2)]&j.MASK,'PANEL_SELECTOR_CLOCK');self.counts[56]+=1;self.effect(56);self.calls+=1;m.reg_write(x.UC_X86_REG_RAX,args[0]);m.mem_write(self.base+0x6a410,struct.pack('<I',error));return
        extra,reply=r.take('2Q');args.append(extra);require(kind==api and reg('RCX')==self.gate['ctx'],'PANEL_API_ORDER_OR_CONTEXT');actual=[0]*5;p=self.case['display']
        if api==80:actual[:3]=[reg('RDX'),reg('R8')&0xffffffff,reg('R9')&65535]
        elif api==81:actual[:2]=[reg('XMM1')&j.MASK,reg('R8')&0xffffffff]
        elif api==82:actual[:2]=[reg('RDX'),reg('R8')]
        elif api==83:
            require((reg('RDX'),reg('R8'),reg('R9'))==(274,6,0x550005),'PANEL_CREATE_DISPATCH');packet=struct.unpack('<11Q',m.mem_read(sp+40,88))
            # The native call writes 32-bit type tags and integer arguments;
            # their upper stack words retain caller data in a continuous run.
            require([packet[i]&0xffffffff for i in [1,3,5,7,9]]==[0x590008,0x520004,0x520004,0x540005,0x580007],'PANEL_CREATE_TYPES')
            actual=[packet[0],packet[4]&0xffffffff,packet[6]&0xffffffff,packet[8],packet[10]];require(self.read_text(packet[2])==texts[0],'PANEL_CREATE_NAME')
        elif api in [84,85]:
            actual[:2]=[reg('RDX'),reg('R9')];require(self.read_text(reg('R8'))==texts[0],'PANEL_OBJECT_NAME');value=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
            if api==84:actual[2]=value
            else:require(self.read_text(value)==texts[1],'PANEL_OBJECT_TEXT')
        elif api==86:actual[0]=reg('RDX');require(self.read_text(reg('R8'))==texts[0],'PANEL_FIND_NAME')
        elif api==87:require(reg('RDX')==0,'PANEL_CLOCK_OVERLOAD')
        elif api in [88,90,91,92,93,94]:actual[0]=reg('RDX')
        elif api==95:actual[:2]=[reg('RDX'),reg('R8')]
        elif api==97:actual[0]=reg('RDX')&0xffffffff
        elif api in [98,99,100]:actual[:2]=[reg('RDX'),reg('R8')]
        require(actual==args,'PANEL_ARGUMENTS '+str((self.case['id'],api)))
        if api in [83,84,85]:require(reply==p['ok'],'PANEL_OBJECT_REPLY')
        elif api==86:require(reply==p['find']&j.MASK,'PANEL_FIND_REPLY')
        elif api==87:require(reply==p['clock']&j.MASK,'PANEL_CLOCK_REPLY')
        elif api==88:require(args[0]==6 and reply==p['info']&j.MASK,'PANEL_INFO_REPLY')
        elif api==89:require(reply==len(p['positions']),'PANEL_POSITION_TOTAL')
        elif api==90:
            index=args[0];self.position_index=index;require(reply==(p['positions'][index][0] if index<len(p['positions']) else 0),'PANEL_POSITION_TICKET')
        elif api in [91,92,93,94]:
            require(0<=self.position_index<len(p['positions']),'PANEL_POSITION_SELECTION');pos=p['positions'][self.position_index]
            if api==91:require(args[0]==0 and texts[0]==pos[6],'PANEL_POSITION_SYMBOL')
            elif api==92:require(args[0] in [12,2] and reply==pos[1 if args[0]==12 else 2]&j.MASK,'PANEL_POSITION_INTEGER')
            elif api==93:require(args[0]==pos[0] and reply==pos[5],'PANEL_POSITION_SELECT')
            else:require(args[0] in [9,10] and reply==entry.cal.n.a.boot.bits(pos[3 if args[0]==9 else 4]),'PANEL_POSITION_DOUBLE')
        elif api==95:require(args[:2]==[0,2147483647] and reply==p['history_select'],'PANEL_HISTORY_SELECT')
        elif api==96:require(reply==len(p['history']),'PANEL_HISTORY_TOTAL')
        elif api==97:self.deal_index=args[0];require(reply==p['history'][self.deal_index][0],'PANEL_HISTORY_TICKET')
        elif api in [98,99,100]:
            require(0<=self.deal_index<len(p['history']),'PANEL_HISTORY_SELECTION');deal=p['history'][self.deal_index];require(args[0]==deal[0],'PANEL_DEAL_TICKET')
            if api==98:require(args[1]==11 and reply==deal[1]&j.MASK,'PANEL_DEAL_MAGIC')
            elif api==99:require(args[1]==0 and texts[0]==deal[5],'PANEL_DEAL_SYMBOL')
            else:require(args[1] in [9,7,8] and reply==entry.cal.n.a.boot.bits(deal[{9:2,7:3,8:4}[args[1]]]),'PANEL_DEAL_DOUBLE')
        if api in [80,81,82,91,99]:self.put_text((reg('R9')-self.base) if api==82 else 0x6a43c,texts[0])
        elif api in [94,100]:m.mem_write(self.base+0x6a448,struct.pack('<Q',reply))
        else:m.reg_write(x.UC_X86_REG_RAX,reply)
        self.counts[api]+=1;self.effect(api);self.calls+=1;m.mem_write(self.base+0x6a410,struct.pack('<I',error))

def identity():
    current=BASE_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupRealPanelsCheck.mq5'
    current['sources_sha256']={f.relative_to(src).as_posix():sha(f) for f in j.pub.closure(script,src)}
    current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__));return current

temp=entry.cal.n.a.load('real_panel_runner','kiem-noi-khoi-dong-bot-1.py')
for function in ['execute','main']:
    code=inspect.getsource(getattr(temp,function)).replace('Bot1StartupPostPreparationCheck','Bot1StartupRealPanelsCheck').replace('bot1-startup-joined','bot1-startup-real-panels').replace('startup-joined-','startup-real-panels-')
    code=code.replace('Continuous after first preparation through normal return only.','Continuous startup after authorization with all calendar, entry-level and panel bodies.').replace('Two entry-level and three panel children recorded;','No panel or entry-level child result supplied;').replace('earlier OnInit and full EA remain unverified.','authorization, rendered chart, final fault states and full EA remain unverified.')
    exec(compile(code,__file__,'exec'),j.__dict__)
j.cases=cases;j.encode=encode;j.render=render;j.identity=identity;j.Native=Native
j.SCOPE=dict(j.SCOPE,panel_children_recorded=False,native_all_three_panel_bodies_executed=True,chart_position_history_replies_supplied=True,rendered_chart_verified=False,authorization_entry_guarded=True)
if __name__=='__main__':j.main()
