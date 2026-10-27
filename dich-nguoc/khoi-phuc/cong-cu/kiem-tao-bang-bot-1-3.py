"""Compare the whole original panel constructor with source executed in MT5.

generate BOT; prepare|mql5 --build BUILD|original|compare BOT RUN.
The full constructor, cell and news helpers execute unchanged in the native run.
"""
import argparse,copy,hashlib,importlib.util,json,random,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x50435231;MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('creation_analysis',ROOT/'cong-cu/phan-tich-tao-bang-bot-1-3.py')
analysis=importlib.util.module_from_spec(spec);spec.loader.exec_module(analysis)
cell=analysis.cell;shared=cell.shared;pub=shared.pub;require=pub.require;sha=shared.sha;save=shared.save;text=shared.text;Reader=shared.Reader
BODIES={1:(0x8320,0xe1ae,'7c540d0d6d2057502c8e57b66291ae617d1fb325ce677f2e066ac2ccd20bb8dc'),
        3:(0xef40,0x14f98,'889bf0b36cb6250816cadfa17e0e2e21beedbccf54ff84bd7c1b1ad9de042920')}
SCOPE=dict(full_ea=False,whole_bot_complete=False,whole_manager_complete=False,full_panel_constructor_executed=True,
           native_panel_cell_executed=True,native_news_selector_executed=True,child_helpers_intercepted=False,
           terminal_replies_supplied=True,text_formatting_measured_in_mt5=True,rendered_chart_verified=False,original_ex5_changed=False)

def fields(bot):
    common=[('P.font','i',0x6a540,0x1d6f50),('P.scale','d',0x6a538,0x1d6f48),('P.color_flag','B',0x678f8,0x74938),
            ('P.mode','i' if bot==1 else 'I',0x6a748,0x6d630),('P.strategy_risk','d',0x6a758,0x1d7150)]
    fs=[(n,k,a if bot==1 else b) for n,k,a,b in common]
    fs+=([('P.trade_risk','d',0x6a750),('P.balance_step','i',0x6a768)] if bot==1 else
         [('P.frequency','i',0x6d21c),('P.manual_lots','d',0x1d7138),('P.allowed_dd','d',0x1d7140)])
    cfg=cell.CFG[bot]
    fs += [('P.cell_x','d',cfg['x']),('P.cell_y','d',cfg['y']),('P.cell_font_flag','B',cfg['flag']),
           ('P.closed_star','B',0x623c4 if bot==1 else 0x6d43c),('P.rows_ready','B',0x67930 if bot==1 else 0x74970)]
    for name,base in zip(['closed','per_trade','lots'],analysis.CFG[bot]['arrays']):
        fs += [(f'P.{name}[{i}]','d',base+8*i) for i in range(8 if bot==1 else 9)]
    cfg=shared.selector.CFG[bot]
    for group,kind,prefix in [('times','q','Events.'),('flags','B','Windows.'),('minutes','i','Windows.')]:
        for i,name in enumerate(['nfp','interest','cpi']):
            fs.append((prefix+name+('_enabled' if group=='flags' else '_after' if group=='minutes' else ''),kind,cfg[group][i]))
    return fs+[('Selection.block_time','q',cfg['time']),('Selection.label','s',cfg['label'])]

def word(value,kind):return cell.bits(value) if kind=='d' else int(value)&MASK

def cases(bot):
    values={'P.font':7,'P.scale':1.,'P.color_flag':1,'P.mode':0 if bot==1 else 1234,'P.frequency':3,
            'P.strategy_risk':2.75,'P.trade_risk':1.25,'P.balance_step':600,'P.manual_lots':.125,'P.allowed_dd':30.,
            'P.cell_x':78.5,'P.cell_y':14.,'P.cell_font_flag':1,'P.closed_star':1,'P.rows_ready':0,
            'Selection.block_time':999,'Selection.label':'Previous'}
    for n,k,_ in fields(bot):
        if '[' in n:values[n]=.125 if '.lots' in n else -1.005 if '.per_trade' in n else 1.005
        elif n.startswith('Events.'):values[n]=1767355500
        elif n.startswith('Windows.'):values[n]=10 if n.endswith('_after') else 0
    out=[]
    def add(tag,updates=None,effects=None,find=0,errors=0,clock=1767355200):
        c=dict(id=len(out),tag=tag,values=copy.deepcopy(values),effects=effects or [],find=find,errors=errors,clock=clock)
        c['values'].update(updates or {});out.append(c)
    modes=[-1,0,3,999,9999] if bot==1 else [-1,0,3,1234,9999]
    for mode in modes:add('risk-label',{'P.mode':mode})
    if bot==3:
        for frequency in [-2147483648,-1,0,1,2,3,4,5,2147483647]:add('frequency',{'P.frequency':frequency})
    for font in [-2147483648,-1,0,1,2,7,2147483644,2147483645,2147483646,2147483647]:add('font-int32',{'P.font':font})
    for scale in [-0.,0.,-.75,.75,1.25,-1e19,1e19,float('nan'),float('inf'),-float('inf')]:add('scale-casts',{'P.scale':scale})
    for n in ['P.color_flag','P.cell_font_flag','P.closed_star']:
        for value in [0,1,2,3,254,255]:add('byte-flag', {n:value})
    numeric=[-0.,0.,.005,-.005,1.005,-1.005,1e19,-1e19,float('nan'),float('inf'),-float('inf')]
    for value in numeric:
        updates={n:value for n,k,_ in fields(bot) if k=='d' and (n.startswith('P.closed[') or n.startswith('P.per_trade[') or n.startswith('P.lots[') or n in ['P.strategy_risk','P.trade_risk','P.manual_lots','P.allowed_dd'])}
        for mode in modes:add('number-rounding-and-text',dict(updates,**{'P.mode':mode}),errors=1)
    for find in [-1,-2,0,1,2]:add('find-result',find=find,errors=1)
    for mask in range(8):add('news-priority',{f'Windows.{n}_enabled':(mask>>i)&1 for i,n in enumerate(['nfp','interest','cpi'])})
    for minutes in [-2147483648,-1,0,2147483647]:add('news-minute-wrap',{'Windows.nfp_enabled':255,'Windows.nfp_after':minutes})
    # Captured versus live reads: effects happen after individual SDK replies.
    for after,n,value in [(1,'P.font',19),(2,'P.scale',1.5),(3,'P.scale',1.75),(4,'P.scale',2.),
        (18,'P.color_flag',0),(19,'P.color_flag',0),(20,'P.color_flag',0),(26,'P.color_flag',2),
        (32,'P.color_flag',0),(39,'P.mode',3),(40,'P.mode',999),(41,'P.strategy_risk',9.),
        (42,'P.mode',1234),(43,'P.mode',3),(50,'P.color_flag',0),(51,'P.color_flag',1),
        (54,'P.cell_font_flag',2),(100,'P.closed_star',2),(115,'P.closed_star',0),
        (200,'P.cell_x',-2.75),(201,'P.cell_x',20.5),(202,'P.cell_y',-3.25),
        (250,'P.cell_font_flag',2),(400,'P.closed[2]',19.995),(500,'P.per_trade[3]',-19.995),
        (700,'P.lots[5]',.995),(1000,'P.rows_ready',17)]:
        add('live-after-sdk',effects=[dict(after=after,name=n,value=value)],errors=1)
    for n,value in [('Events.nfp',1767355800),('Selection.block_time',5),('Selection.label','Changed \U0001f600')]:
        add('live-after-clock',{'Windows.nfp_enabled':1},[dict(api=7,n=1,name=n,value=value)],errors=1)
    rng=random.Random(2026102829+bot)
    for _ in range(25):
        add('mixed',{'P.mode':rng.choice(modes),'P.frequency':rng.randrange(-1,6),'P.scale':rng.uniform(-1.,2.),
                     'P.font':rng.randrange(-1,20),'P.color_flag':rng.randrange(256),'P.closed_star':rng.randrange(3)},find=rng.choice([-1,0,2]),errors=1)
    return out

def encode(rows,bot):
    fs=fields(bot);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<i',c['id'])
        for n,k,_ in fs:raw+=text(c['values'][n]) if k=='s' else struct.pack('<Q',word(c['values'][n],k))
        raw+=struct.pack('<2iqi',c['find'],c['errors'],c['clock'],len(c['effects']))
        for e in c['effects']:
            i=next(i for i,f in enumerate(fs) if f[0]==e['name']);kind=fs[i][1]
            raw+=struct.pack('<4i',e.get('after',0),e.get('api',0),e.get('n',0),i)
            raw+=text(e['value']) if kind=='s' else struct.pack('<Q',word(e['value'],kind))
    return raw

TEMPLATE=r'''#property strict
input string CheckRun="";
string MockIntegerText(const long value,const int width=0,const ushort fill=' ');
string MockDoubleText(const double value,const int digits=8);
bool MockCreate(const long chart,const string name,const ENUM_OBJECT type,const int window,const datetime time,const double price);
bool MockInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value);
bool MockText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value);
int MockFind(const long chart,const string name);
datetime MockServer();
string Bot@N@PanelDoubleText(const double value);
string Bot@N@PanelIntegerText(const int value);
string Bot@N@PanelTimeText(const datetime value);
#define BOT@N@_PANEL_TEXT_CASTS_MQH
#define IntegerToString MockIntegerText
#define DoubleToString MockDoubleText
#define ObjectCreate MockCreate
#define ObjectSetInteger MockInteger
#define ObjectSetString MockText
#define ObjectFind MockFind
#define TimeTradeServer MockServer
#include "../../Include/bot-cua-toi-@N@/Bot@N@PanelCreation.mqh"
#undef IntegerToString
#undef DoubleToString
#undef ObjectCreate
#undef ObjectSetInteger
#undef ObjectSetString
#undef ObjectFind
#undef TimeTradeServer
Bot@N@PanelCreationState P;Bot@N@NewsEvents Events;Bot@N@NewsWindows Windows;Bot@N@NewsSelection Selection;
int TapeFile,Calls,FindReply,ErrorMode,Counts[9];long Clock;uint LogicalError;
struct Effect { int after,api,n,field;ulong word;string text; };Effect Effects[];
union Number { double value;ulong word; };
ulong Bits(const double value) { Number n;n.value=value;return n.word; }
double FromBits(const ulong word) { Number n;n.word=word;return n.value; }
string ReadText(const int file)
{ int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n)); }
void Text(const string value)
{ if(value==NULL) { FileWriteInteger(TapeFile,-1);return; }int n=StringLen(value);FileWriteInteger(TapeFile,n);if(n>0)FileWriteString(TapeFile,value,n); }
void Snapshot()
{
   ulong words[@WORDS@];
@SNAPSHOT@
   FileWriteArray(TapeFile,words,0,@WORDS@);Text(Selection.label);FileWriteLong(TapeFile,(long)LogicalError);
}
void SetField(const int index,const ulong word,const string text)
{
   switch(index)
   {
@SET_FIELDS@
   }
}
void Record(const int api,const ulong a,const ulong b,const ulong c,const ulong d,const ulong e,const string name,const string value,const ulong reply)
{
   Snapshot();FileWriteInteger(TapeFile,api);ulong args[5];args[0]=a;args[1]=b;args[2]=c;args[3]=d;args[4]=e;
   FileWriteArray(TapeFile,args,0,5);Text(name);Text(value);FileWriteLong(TapeFile,(long)reply);
   Calls++;Counts[api]++;if(ErrorMode!=0)LogicalError=(uint)(9000+Calls);FileWriteInteger(TapeFile,(int)LogicalError);
   for(int i=0;i<ArraySize(Effects);i++)
      if((Effects[i].after>0 && Effects[i].after==Calls) || (Effects[i].api==api && Effects[i].n==Counts[api]))
         SetField(Effects[i].field,Effects[i].word,Effects[i].text);
}
string MockIntegerText(const long value,const int width,const ushort fill)
{ string reply=IntegerToString(value,width,fill);Record(1,(ulong)value,(ulong)(uint)width,(ulong)fill,0,0,reply,NULL,0);return reply; }
string MockDoubleText(const double value,const int digits)
{ string reply=DoubleToString(value,digits);Record(6,Bits(value),(ulong)(uint)digits,0,0,0,reply,NULL,0);return reply; }
bool MockCreate(const long chart,const string name,const ENUM_OBJECT type,const int window,const datetime time,const double price)
{ bool reply=Calls%2==0;Record(2,(ulong)chart,(ulong)type,(ulong)(uint)window,(ulong)time,Bits(price),name,NULL,(ulong)reply);return reply; }
bool MockInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value)
{ bool reply=Calls%2!=0;Record(3,(ulong)chart,(ulong)property,(ulong)value,0,0,name,NULL,(ulong)reply);return reply; }
bool MockText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value)
{ bool reply=Calls%2==0;Record(4,(ulong)chart,(ulong)property,0,0,0,name,value,(ulong)reply);return reply; }
int MockFind(const long chart,const string name)
{ Record(5,(ulong)chart,0,0,0,0,name,NULL,(ulong)(long)FindReply);return FindReply; }
datetime MockServer()
{ long reply=Clock;Record(7,0,0,0,0,0,NULL,NULL,(ulong)reply);return (datetime)reply; }
string Bot@N@PanelDoubleText(const double value)
{ string reply=(string)value;Record(8,Bits(value),0x58,0,0,0,reply,NULL,0);return reply; }
string Bot@N@PanelIntegerText(const int value)
{ string reply=(string)value;Record(8,(ulong)(long)value,0x52,0,0,0,reply,NULL,0);return reply; }
string Bot@N@PanelTimeText(const datetime value)
{ string reply=(string)value;Record(8,(ulong)value,0x54,0,0,0,reply,NULL,0);return reply; }
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot@N@-panel-create\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input_file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x50435231 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(input_file);
      for(int k=0;k<@WORDS@;k++) SetField(k,(ulong)FileReadLong(input_file),NULL);
      Selection.label=ReadText(input_file);FindReply=FileReadInteger(input_file);ErrorMode=FileReadInteger(input_file);Clock=FileReadLong(input_file);
      int n=FileReadInteger(input_file);ArrayResize(Effects,n);
      for(int k=0;k<n;k++)
      {
         Effects[k].after=FileReadInteger(input_file);Effects[k].api=FileReadInteger(input_file);Effects[k].n=FileReadInteger(input_file);Effects[k].field=FileReadInteger(input_file);
         Effects[k].word=0;Effects[k].text=NULL;
         if(Effects[k].field==@WORDS@)Effects[k].text=ReadText(input_file);else Effects[k].word=(ulong)FileReadLong(input_file);
      }
      Calls=0;LogicalError=0;ArrayInitialize(Counts,0);
      string name=folder+"events-"+IntegerToString(id)+".bin";TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE)return 5;
      Bot@N@CreateInfoPanel(P,Events,Windows,Selection);Snapshot();FileClose(TapeFile);
      int event_file=FileOpen(name,FILE_READ|FILE_BIN);if(event_file==INVALID_HANDLE)return 6;
      int size=(int)FileSize(event_file);uchar bytes[];ArrayResize(bytes,size);if(size>0)FileReadArray(event_file,bytes,0,size);FileClose(event_file);
      FileWriteInteger(output,id);FileWriteInteger(output,size);if(size>0)FileWriteArray(output,bytes,0,size);
   }
   FileClose(input_file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''

def generate(bot):
    fs=fields(bot);numeric=fs[:-1];require(fs[-1][1]=='s' and all(k!='s' for _,k,_ in numeric),'FIELD_ORDER')
    source=TEMPLATE.replace('@N@',str(bot)).replace('@WORDS@',str(len(numeric)))
    snapshots=[];setters=[]
    for i,(n,k,_) in enumerate(fs):
        if k!='s':snapshots.append(f'   words[{i}]='+('Bits('+n+')' if k=='d' else '(ulong)'+n)+';')
        cast={'i':'(int)word','I':'(uint)word','B':'(uchar)word','q':'(long)word','d':'FromBits(word)','s':'text'}[k]
        setters.append(f'      case {i}: {n}={cast};break;')
    source=source.replace('@SNAPSHOT@','\n'.join(snapshots)).replace('@SET_FIELDS@','\n'.join(setters))
    script=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}PanelCreationCheck.mq5';script.write_text(source,encoding='utf-8',newline='\n')
    api=script.with_name(f'Bot{bot}PanelCreationAPICompile.mq5')
    api.write_text(f'#property strict\n#include "../../Include/bot-cua-toi-{bot}/Bot{bot}PanelCreation.mqh"\nvoid OnStart() {{}}\n',encoding='utf-8',newline='\n')

class Native(analysis.Trace):
    def __init__(self,bot):
        shared.entry.Original.__init__(self,bot);self.bot=bot;self.panel=analysis.CFG[bot];self.fs=fields(bot);self.words=len(self.fs)-1
        begin,end,h=BODIES[bot]
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+begin,end-begin))).hexdigest()==h,'NATIVE_BODY_CHANGED')
        self.sdk={0x7ff683f20000+off:api for api,off in analysis.SDK.items()};self.covered=set()
        for address in self.sdk:
            existed=address in self.apis
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,a,s,u:self.covered.add(a-self.base),begin=self.base+begin,end=self.base+end-1)
    def put(self,field,value):
        _,kind,address=field
        raw=struct.pack('<IQ',0,0 if value is None else self.string(value)) if kind=='s' else struct.pack('<d',value) if kind=='d' else (int(value)&((1<<(struct.calcsize('<'+kind)*8))-1)).to_bytes(struct.calcsize('<'+kind),'little')
        self.m.mem_write(self.base+address,raw)
    def state(self):
        raw=bytearray()
        for _,kind,address in self.fs:
            if kind=='s':raw+=text(self.read_text(self.base+address))
            else:
                value=struct.unpack('<'+('Q' if kind=='d' else kind),self.m.mem_read(self.base+address,struct.calcsize('<'+kind)))[0]
                raw+=struct.pack('<Q',value&MASK)
        return bytes(raw)+bytes(self.m.mem_read(self.base+cell.CFG[self.bot]['error'],4))+bytes(4)
    def expected_state(self):
        r=self.tape;return struct.pack('<'+'Q'*self.words,*r.take('Q'*self.words))+text(r.text())+struct.pack('<Q',r.take('Q')[0])
    def call(self,m,address,size,user):
        if address not in self.sdk:return super().call(m,address,size,user)
        r=self.tape;x=self.x;api=self.sdk[address];reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));sp=reg('RSP')
        expected=self.expected_state();actual_state=self.state()
        require(expected==actual_state,'STATE_BEFORE_SDK '+str((self.case['id'],self.calls,api,next((i for i,(a,b) in enumerate(zip(expected,actual_state)) if a!=b),-1))))
        kind,*args=r.take('i5Q');name=r.text();value=r.text();reply,error=r.take('QI')
        require(kind==api and reg('RCX')==cell.CFG[self.bot]['ctx'],'SDK_ORDER_OR_CONTEXT '+str((self.case['id'],self.calls,kind,api)))
        actual=[0]*5
        if api==1:actual[:3]=[reg('RDX'),reg('R8')&0xffffffff,reg('R9')&65535]
        elif api==2:
            require((reg('RDX'),reg('R8'),reg('R9'))==(274,6,0x550005),'CREATE_DISPATCH')
            packet=struct.unpack('<11Q',m.mem_read(sp+40,88));require([packet[i] for i in [1,3,5,7,9]]==[0x590008,0x520004,0x520004,0x540005,0x580007],'CREATE_TYPES')
            actual=[packet[0],packet[4],packet[6],packet[8],packet[10]];require(self.read_text(packet[2])==name,'CREATE_NAME')
        elif api in [3,4]:
            actual[:2]=[reg('RDX'),reg('R9')];require(self.read_text(reg('R8'))==name,'PROPERTY_NAME')
            extra=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
            if api==3:actual[2]=extra
            else:require(self.read_text(extra)==value,'PROPERTY_TEXT '+str((self.case['id'],self.calls,self.read_text(extra),value)))
        elif api==5:actual[0]=reg('RDX');require(self.read_text(reg('R8'))==name,'FIND_NAME')
        elif api==6:actual[:2]=[reg('XMM1')&MASK,reg('R8')&0xffffffff]
        elif api==7:require(reg('RDX')==0,'CLOCK_OVERLOAD')
        elif api==8:actual[:2]=[reg('RDX'),reg('R8')]
        require(actual==args,'SDK_ARGUMENTS '+str((self.case['id'],self.calls,api,name,actual,args)))
        if api in [1,6,8]:m.mem_write(reg('R9') if api==8 else self.base+self.cfg['string_result'],struct.pack('<IQ',0,0 if name is None else self.string(name)))
        else:m.reg_write(x.UC_X86_REG_RAX,reply)
        m.mem_write(self.base+cell.CFG[self.bot]['error'],struct.pack('<I',error));self.calls+=1;self.counts[api]=self.counts.get(api,0)+1
        for e in self.case['effects']:
            if e.get('after',0)==self.calls or (e.get('api',0)==api and e.get('n',0)==self.counts[api]):self.put(next(f for f in self.fs if f[0]==e['name']),e['value'])
    def run(self,c,tape):
        self.case=c;self.tape=Reader(tape);self.calls=0;self.counts={};self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for f in self.fs:self.put(f,c['values'][f[0]])
        m.mem_write(self.base+self.cfg['string_result'],bytes(12));m.mem_write(self.base+cell.CFG[self.bot]['error'],bytes(4))
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        top=0x5001fef8;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.emu_start(self.base+self.panel['fn'],0x60000000,timeout=10000000,count=4000000)
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_NO_RETURN')
        require(self.expected_state()==self.state() and self.tape.pos==len(tape),'FINAL_STATE_OR_TRAILING')
        return tape

def identity(bot):
    original=cell.identity(bot);source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}PanelCreationCheck.mq5'
    original['sources_sha256']={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)}
    original['helpers_sha256'].update({p.relative_to(ROOT).as_posix():sha(p) for p in [Path(__file__),Path(analysis.__file__),Path(cell.__file__)]})
    return dict(**original,panel_body_sha256=BODIES[bot][2])

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases(a.bot);current=identity(a.bot);home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows,a.bot));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows,a.bot),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build,'BUILD_REQUIRED');mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PanelCreationCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        def check_build():
            for n,h in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
            binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        check_build();files=mt/f'MQL5/Files/bot{a.bot}-panel-create'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('panel-create-'+a.run+'.set');ini=mt/('panel-create-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PanelCreationCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED');check_build()
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(folder/'mql5-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        recorded=(folder/'mql5-results.bin').read_bytes();require(recorded[:12]==struct.pack('<3i',MAGIC,1,len(rows)),'RESULT_HEADER')
        tapes=cell.records(struct.pack('<i',cell.MAGIC)+recorded[4:],len(rows));o=Native(a.bot);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));count=0;failed=[]
        for c,tape in zip(rows,tapes):
            try:
                data=o.run(c,tape);raw+=struct.pack('<2i',c['id'],len(data))+data;count+=o.calls
            except (ValueError,o.uc.UcError) as e:failed.append(dict(case=c['id'],tag=c['tag'],error=str(e)))
        if failed:
            save(folder/'native-failures.json',dict(cases=len(rows),failed=len(failed),failures=failed));print(json.dumps(dict(cases=len(rows),failed=len(failed),first=failed[:12])));raise SystemExit(1)
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),sdk_calls=count,instructions=len(o.covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=count)));return
    for name in ['mql5','original']:
        r=json.loads((folder/(name+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    require((folder/'mql5-results.bin').read_bytes()==(folder/'original-results.bin').read_bytes(),'RESULTS_DIFFER')
    result=dict(cases=len(rows),matched=len(rows),failed=0,**SCOPE,limits=['Whole panel constructor with actual MQL5 casts, all object calls and state compared. Successful string allocations and supplied SDK replies. No rendered chart or full EA pair.'])
    save(folder/'comparison.json',result);print(json.dumps(result))

if __name__=='__main__':main()
