"""Record actual MT5 panel-cell calls and compare with the unchanged native helper.

generate BOT; prepare|mql5(--build)|original|compare BOT RUN.
This does not claim full panel rendering or a complete EA.
"""
import argparse,copy,hashlib,importlib.util,json,random,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x50434c31;MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('panel_shared',ROOT/'cong-cu/kiem-bang-thong-tin-lich-su-bot-1-3.py')
shared=importlib.util.module_from_spec(spec);spec.loader.exec_module(shared)
pub=shared.pub;require=pub.require;sha=shared.sha;save=shared.save;Reader=shared.Reader
CFG={1:dict(fn=0x45b70,end=0x4773b,x=0x68298,y=0x682a0,flag=0x682a8,error=0x6a410,ctx=0x23e575eae78,
            sha='591e2758c7f444513368726b58fde8808a3f5d2e757b9d4e9a377075fe1e1f74'),
     3:dict(fn=0x53a10,end=0x555db,x=0x752d8,y=0x752e0,flag=0x752e8,error=0x1d6e10,ctx=0x171514ca538,
            sha='1174b2b906e77a28ad0b2105211b62eb4240227e3738e9a873c5a3715660aecd')}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,native_panel_cell_executed=True,
           child_helpers_intercepted=False,terminal_replies_supplied=True,rendered_chart_verified=False,original_ex5_changed=False)
def bits(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def text(s):return shared.text(s)
def cases(bot):
    out=[];default=dict(base_y=20,index=4,row=2,column=3,color=0xb09a8b,x=120.,y=22.,flag=1,text='Strategy 1',errors=0,effects=[])
    def add(tag,**values):
        c=copy.deepcopy(default);c.update(values);c.update(id=len(out),tag=tag);out.append(c)
    for flag in [0,1,2,3,254,255]:
        for color in [0,0xc4b741,0xc4b740,0xffffffff]:add('font-and-color',flag=flag,color=color)
    for key in ['base_y','index','row','column']:
        for value in [-2147483648,-1,0,1,2147483647]:add('signed-int32',**{key:value})
    for key in ['x','y']:
        for value in [-0.,0.,-.75,.75,1.005,-1.005,1e19,-1e19,float('nan'),float('inf'),-float('inf')]:
            add('numeric-cast',**{key:value})
    for s in [None,'','Vàng','A\U0001f600B','e\u0301','L'*500]:add('utf16-and-null',text=s)
    # Mutate after conversions as well as property calls: catches capturing scales too late.
    for after in [1,2,3,4,5,6,7,16,17,18,21,22,23,24,25,26,27,28,29,30]:
        add('live-fields',errors=1,effects=[[after,13.5,-2.75,2,'Changed \U0001f600']])
    rng=random.Random(2026102801+bot)
    for _ in range(80):add('mixed',base_y=rng.randrange(-300,301),index=rng.randrange(-10,301),row=rng.randrange(-3,15),
        column=rng.randrange(-2,6),color=rng.randrange(1<<32),x=rng.uniform(-200,200),y=rng.uniform(-40,40),flag=rng.randrange(256),errors=1)
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<5iI2dI',*[c[k] for k in ['id','base_y','index','row','column','color','x','y','flag']])
        raw+=text(c['text'])+struct.pack('<2i',c['errors'],len(c['effects']))
        for after,x,y,flag,label in c['effects']:raw+=struct.pack('<i2dI',after,x,y,flag)+text(label)
    return bytes(raw)
TEMPLATE=r'''#property strict
input string CheckRun="";
string MockIntegerText(const long value,const int width=0,const ushort fill=' ');
bool MockCreate(const long chart,const string name,const ENUM_OBJECT type,const int window,const datetime time,const double price);
bool MockInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value);
bool MockText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value);
#define IntegerToString MockIntegerText
#define ObjectCreate MockCreate
#define ObjectSetInteger MockInteger
#define ObjectSetString MockText
#include "../../Include/bot-cua-toi-@N@/Bot@N@PanelCell.mqh"
#undef IntegerToString
#undef ObjectCreate
#undef ObjectSetInteger
#undef ObjectSetString
int TapeFile,Calls,ErrorMode;double X,Y;uchar Flag;string Label;uint LogicalError;
struct Effect { int after;double x,y;uchar flag;string text; };Effect Effects[];
union Number { double value;ulong word; };
ulong Bits(const double value) { Number n;n.value=value;return n.word; }
string ReadText(const int file)
{ int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n)); }
void Text(const string value)
{ if(value==NULL) { FileWriteInteger(TapeFile,-1);return; }int n=StringLen(value);FileWriteInteger(TapeFile,n);if(n>0) FileWriteString(TapeFile,value,n); }
void Snapshot()
{ FileWriteLong(TapeFile,(long)Bits(X));FileWriteLong(TapeFile,(long)Bits(Y));FileWriteLong(TapeFile,(long)Flag);Text(Label);FileWriteLong(TapeFile,(long)LogicalError); }
void Record(const int api,const ulong a,const ulong b,const ulong c,const ulong d,const ulong e,
            const string name,const string value,const ulong reply)
{
   Snapshot();FileWriteInteger(TapeFile,api);FileWriteLong(TapeFile,(long)a);FileWriteLong(TapeFile,(long)b);
   FileWriteLong(TapeFile,(long)c);FileWriteLong(TapeFile,(long)d);FileWriteLong(TapeFile,(long)e);Text(name);Text(value);FileWriteLong(TapeFile,(long)reply);
   Calls++;if(ErrorMode!=0) LogicalError=(uint)(9000+Calls);FileWriteInteger(TapeFile,(int)LogicalError);
   for(int i=0;i<ArraySize(Effects);i++) if(Effects[i].after==Calls)
   { X=Effects[i].x;Y=Effects[i].y;Flag=Effects[i].flag;Label=Effects[i].text; }
}
string MockIntegerText(const long value,const int width,const ushort fill)
{ string reply=IntegerToString(value,width,fill);Record(1,(ulong)value,(ulong)(uint)width,(ulong)fill,0,0,reply,NULL,0);return reply; }
bool MockCreate(const long chart,const string name,const ENUM_OBJECT type,const int window,const datetime time,const double price)
{ bool reply=Calls%2==0;Record(2,(ulong)chart,(ulong)type,(ulong)(uint)window,(ulong)time,Bits(price),name,NULL,(ulong)reply);return reply; }
bool MockInteger(const long chart,const string name,const ENUM_OBJECT_PROPERTY_INTEGER property,const long value)
{ bool reply=Calls%2!=0;Record(3,(ulong)chart,(ulong)property,(ulong)value,0,0,name,NULL,(ulong)reply);return reply; }
bool MockText(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value)
{ bool reply=Calls%2==0;Record(4,(ulong)chart,(ulong)property,0,0,0,name,value,(ulong)reply);return reply; }
int OnStart()
{
   if(CheckRun=="") return 1;string folder="bot@N@-panel-cell\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input_file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x50434c31 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(input_file),base_y=FileReadInteger(input_file),index=FileReadInteger(input_file),row=FileReadInteger(input_file),column=FileReadInteger(input_file);
      uint color_value=(uint)FileReadInteger(input_file);X=FileReadDouble(input_file);Y=FileReadDouble(input_file);Flag=(uchar)FileReadInteger(input_file);
      Label=ReadText(input_file);ErrorMode=FileReadInteger(input_file);int n=FileReadInteger(input_file);ArrayResize(Effects,n);
      for(int k=0;k<n;k++)
      { Effects[k].after=FileReadInteger(input_file);Effects[k].x=FileReadDouble(input_file);Effects[k].y=FileReadDouble(input_file);Effects[k].flag=(uchar)FileReadInteger(input_file);Effects[k].text=ReadText(input_file); }
      Calls=0;LogicalError=0;string name=folder+"events-"+IntegerToString(id)+".bin";TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE)return 5;
      Bot@N@CreatePanelCell(base_y,index,Label,row,column,color_value,X,Y,Flag);Snapshot();FileClose(TapeFile);
      int event_file=FileOpen(name,FILE_READ|FILE_BIN);if(event_file==INVALID_HANDLE)return 6;
      int size=(int)FileSize(event_file);uchar bytes[];ArrayResize(bytes,size);if(size>0)FileReadArray(event_file,bytes,0,size);FileClose(event_file);
      FileWriteInteger(output,id);FileWriteInteger(output,size);if(size>0)FileWriteArray(output,bytes,0,size);
   }
   FileClose(input_file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
def generate(bot):
    p=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}PanelCellCheck.mq5'
    p.write_text(TEMPLATE.replace('@N@',str(bot)),encoding='utf-8',newline='\n')
def records(raw,count):
    r=Reader(raw);require(r.take('3i')==(MAGIC,1,count),'RESULT_HEADER');out=[]
    for i in range(count):
        id_,n=r.take('2i');require(id_==i and 36<=n<=len(raw)-r.pos,'RECORD_BOUNDS');out.append(bytes(r.raw[r.pos:r.pos+n]));r.pos+=n
    require(r.pos==len(raw),'RESULT_TRAILING');return out
class Native(shared.entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.c=CFG[bot];self.m.mem_map(0x71000000,4096)
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+self.c['fn'],self.c['end']-self.c['fn']))).hexdigest()==self.c['sha'],'NATIVE_BODY_CHANGED')
        self.sdk={0x7ff683f20000+off:api for api,off in [(1,0x7cdfe0),(2,0x7b49f0),(3,0x7c3b30),(4,0x7c3c80)]}
        for address in self.sdk:
            existed=address in self.apis
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.covered=set();self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,a,s,u:self.covered.add(a-self.base),begin=self.base+self.c['fn'],end=self.base+self.c['end']-1)
    def read_text(self,desc):
        pointer=struct.unpack('<Q',self.m.mem_read(desc+4,8))[0]
        if not pointer:return None
        n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(n<100000,'NATIVE_TEXT_LENGTH');return bytes(self.m.mem_read(pointer,n*2)).decode('utf-16-le')
    def set_fields(self,x,y,flag,label):
        for key,value in [('x',x),('y',y)]:self.m.mem_write(self.base+self.c[key],struct.pack('<d',value))
        self.m.mem_write(self.base+self.c['flag'],bytes([flag]))
        self.m.mem_write(0x71000000,struct.pack('<IQ',0,0 if label is None else self.string(label)))
    def state(self):
        c=self.c;m=self.m;b=self.base
        return bytes(m.mem_read(b+c['x'],8))+bytes(m.mem_read(b+c['y'],8))+struct.pack('<Q',m.mem_read(b+c['flag'],1)[0])+text(self.read_text(0x71000000))+struct.pack('<Q',struct.unpack('<I',m.mem_read(b+c['error'],4))[0])
    def read_state(self):
        r=self.tape;return struct.pack('<3Q',*r.take('3Q'))+text(r.text())+struct.pack('<Q',r.take('Q')[0])
    def call(self,m,address,size,user):
        if address not in self.sdk:return super().call(m,address,size,user)
        r=self.tape;api=self.sdk[address];x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));sp=reg('RSP')
        require(self.read_state()==self.state(),'STATE_BEFORE_SDK '+str((self.case['id'],self.calls,api)))
        kind,*args=r.take('i5Q');name=r.text();value=r.text();reply,error=r.take('QI')
        require(kind==api and reg('RCX')==self.c['ctx'],'SDK_ORDER_OR_CONTEXT '+str((self.case['id'],self.calls,kind,api)))
        actual=[reg('RDX'),0,0,0,0]
        if api==1:actual[1:3]=[reg('R8')&0xffffffff,reg('R9')&65535]
        elif api==2:
            require((reg('RDX'),reg('R8'),reg('R9'))==(274,6,0x550005),'CREATE_DISPATCH')
            packet=struct.unpack('<11Q',m.mem_read(sp+40,88))
            require([packet[i] for i in [1,3,5,7,9]]==[0x590008,0x520004,0x520004,0x540005,0x580007],'CREATE_TYPES')
            actual=[packet[0],packet[4],packet[6],packet[8],packet[10]]
            require(self.read_text(packet[2])==name,'CREATE_NAME')
        else:
            actual[1]=reg('R9');require(self.read_text(reg('R8'))==name,'PROPERTY_NAME')
            extra=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
            if api==3:actual[2]=extra
            else:require(self.read_text(extra)==value,'PROPERTY_TEXT')
        require(actual==args,'SDK_ARGUMENTS '+str((self.case['id'],self.calls,api,actual,args)))
        if api==1:m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(name)))
        else:m.reg_write(x.UC_X86_REG_RAX,reply)
        m.mem_write(self.base+self.c['error'],struct.pack('<I',error));self.calls+=1
        for after,sx,sy,flag,label in self.case['effects']:
            if after==self.calls:self.set_fields(sx,sy,flag,label)
    def run(self,c,tape):
        self.case=c;self.tape=Reader(tape);self.calls=0;self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        self.set_fields(c['x'],c['y'],c['flag'],c['text']);m.mem_write(self.base+self.c['error'],bytes(4));m.mem_write(self.base+self.cfg['string_result'],bytes(12))
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        top=0x5001fef8;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        for name,value in [('RCX',c['base_y']&0xffffffff),('RDX',c['index']&0xffffffff),('R8',0x71000000),('R9',c['row']&0xffffffff)]:m.reg_write(getattr(x,'UC_X86_REG_'+name),value)
        m.mem_write(top+40,struct.pack('<2Q',c['column']&0xffffffff,c['color']))
        m.emu_start(self.base+self.c['fn'],0x60000000,timeout=5000000,count=1000000)
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_NO_RETURN')
        require(self.read_state()==self.state() and self.tape.pos==len(tape),'FINAL_STATE_OR_TRAILING')
        require(self.calls==30,'CELL_SDK_CALL_COUNT');return tape
def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}PanelCellCheck.mq5'
    helpers=[Path(__file__),ROOT/'cong-cu/kiem-bang-thong-tin-lich-su-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py']
    return dict(original_ex5_sha256=shared.selector.validation.original_hash(bot),native_body_sha256=CFG[bot]['sha'],sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases(a.bot);current=identity(a.bot);home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build,'BUILD_REQUIRED');mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PanelCellCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/f'MQL5/Files/bot{a.bot}-panel-cell'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=mt/'MQL5/Presets'/('panel-cell-'+a.run+'.set');ini=mt/('panel-cell-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PanelCellCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(folder/'mql5-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tapes=records((folder/'mql5-results.bin').read_bytes(),len(rows));o=Native(a.bot);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));count=0
        for c,tape in zip(rows,tapes):data=o.run(c,tape);raw+=struct.pack('<2i',c['id'],len(data))+data;count+=o.calls
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),sdk_calls=count,instructions=len(o.covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=count)));return
    for name in ['mql5','original']:
        r=json.loads((folder/(name+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    require((folder/'mql5-results.bin').read_bytes()==(folder/'original-results.bin').read_bytes(),'RESULTS_DIFFER');report=dict(cases=len(rows),matched=len(rows),failed=0,**SCOPE,limits=['Full native cell helper, 15 name conversions and 15 ordered object calls with live fields and terminal errors. Successful allocations and supplied SDK replies; no rendered chart or complete panel/EA.']);save(folder/'comparison.json',report);print(json.dumps(dict(cases=len(rows),matched=len(rows),failed=0)))
if __name__=='__main__':main()
