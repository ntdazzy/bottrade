"""Compare native deinitialization with MT5 MQL5, exact byte flags and live changes.

generate BOT; prepare|mql5 --build BUILD|original|compare BOT RUN.
Uses new append-only runs. The original EX5 is never changed.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x4c594332;MASK=(1<<64)-1
def module(name,file):
    spec=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file)
    result=importlib.util.module_from_spec(spec);spec.loader.exec_module(result);return result
shared=module('lifecycle_shared','kiem-bang-thong-tin-lich-su-bot-1-3.py')
entry=shared.entry;pub=shared.pub;require=pub.require;Reader=shared.Reader
sha=shared.sha;save=shared.save
CFG={1:dict(fn=0x1f5e0,end=0x2094e,flag=0x68294,indicator=0x62188,error=0x6a410,
            sha='dad002852f8f36b22f555f14cab4dc55ad9e8b281f08f4368f39bbdb66215098'),
     3:dict(fn=0x2a800,end=0x2bb7f,flag=0x752d4,indicator=0x6d178,error=0x1d6e10,
            sha='23474cc8839a9d85146e838efdbbaa603edc25ffd5c8c0bfa393a24e8f85d31a')}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
           native_deinitialization_body_executed=True,child_helpers_intercepted=False,
           terminal_replies_supplied=True,rendered_chart_verified=False,original_ex5_changed=False)
def cases(bot):
    rows=[]
    def add(tag,flag,indicator,errors=0,effects=None):
        rows.append(dict(id=len(rows),tag=tag,flag=flag,indicator=indicator,errors=errors,effects=effects or []))
    for flag in [0,1,2,255]:
        for indicator in [-2147483648,-1,0,42,2147483647]:
            for errors in [0,1]:add('exact-byte-and-int32-handle',flag,indicator,errors)
    before=3048 if bot==1 else 3049
    for ordinal in [1,before,before+2,before+4,before+4*298]:
        for flag in [0,2,255]:add('live-flag-disable',1,42,1,[[ordinal,flag,0,0]])
    for flag in [0,2,255]:add('live-flag-enable',flag,-1,1,[[1,1,0,0]])
    for initial,replacement in [(-1,42),(42,-1),(42,-2147483648)]:
        add('live-handle-before-release',0,initial,1,[[before,-1,1,replacement]])
    add('write-minus-one-after-release',0,42,1,[[before+1,-1,1,99]])
    return rows
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<5i',c['id'],c['flag'],c['indicator'],c['errors'],len(c['effects']))
        raw+=b''.join(struct.pack('<4i',*e) for e in c['effects'])
    return bytes(raw)
TEMPLATE=r'''#property strict
input string CheckRun="";
bool MockDelete(const long chart,const string name);
string MockIntegerText(const long value,const int width=0,const ushort fill=' ');
bool MockRelease(const int handle);
int MockDeleteAll(const long chart,const int window=-1,const int type=-1);
#define ObjectDelete MockDelete
#define IntegerToString MockIntegerText
#define IndicatorRelease MockRelease
#define ObjectsDeleteAll MockDeleteAll
#include "../../Include/bot-cua-toi-@N@/Bot@N@Lifecycle.mqh"
#undef ObjectDelete
#undef IntegerToString
#undef IndicatorRelease
#undef ObjectsDeleteAll
uchar Flag;int Indicator,TapeFile,Calls,ErrorMode;uint LogicalError;
struct Effect { int after,flag,set_indicator,indicator; };Effect Effects[];
void Text(const string value)
{
   if(value==NULL) { FileWriteInteger(TapeFile,-1);return; }
   int n=StringLen(value);FileWriteInteger(TapeFile,n);
   if(n>0) FileWriteString(TapeFile,value,n);
}
void Snapshot()
{ FileWriteLong(TapeFile,(long)Flag);FileWriteLong(TapeFile,(long)Indicator);FileWriteLong(TapeFile,(long)LogicalError); }
void Record(const int api,const ulong a,const ulong b,const ulong c,const ulong d,const string text,const ulong reply)
{
   Snapshot();FileWriteInteger(TapeFile,api);FileWriteLong(TapeFile,(long)a);FileWriteLong(TapeFile,(long)b);
   FileWriteLong(TapeFile,(long)c);FileWriteLong(TapeFile,(long)d);Text(text);FileWriteLong(TapeFile,(long)reply);
   Calls++;if(ErrorMode!=0) LogicalError=(uint)(7000+Calls);FileWriteInteger(TapeFile,(int)LogicalError);
   for(int i=0;i<ArraySize(Effects);i++) if(Effects[i].after==Calls)
   {
      if(Effects[i].flag>=0) Flag=(uchar)Effects[i].flag;
      if(Effects[i].set_indicator!=0) Indicator=Effects[i].indicator;
   }
}
bool MockDelete(const long chart,const string name)
{ bool reply=Calls%2==0;Record(1,(ulong)chart,0,0,0,name,(ulong)reply);return reply; }
string MockIntegerText(const long value,const int width,const ushort fill)
{ string reply=IntegerToString(value,width,fill);Record(2,(ulong)value,(ulong)(uint)width,(ulong)fill,0,reply,0);return reply; }
bool MockRelease(const int handle)
{ bool reply=Calls%2!=0;Record(3,(ulong)(uint)handle,0,0,0,NULL,(ulong)reply);return reply; }
int MockDeleteAll(const long chart,const int window,const int type)
{ int reply=-1;Record(4,(ulong)chart,(ulong)(uint)window,(ulong)(uint)type,0,NULL,(ulong)(long)reply);return reply; }
int OnStart()
{
   if(CheckRun=="") return 1;string folder="bot@N@-lifecycle-full\\"+CheckRun+"\\";
   int input_file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input_file==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(input_file),version=FileReadInteger(input_file),count=FileReadInteger(input_file);
   if(magic!=0x4c594332 || version!=1 || count<1) return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE) return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int row=0;row<count;row++)
   {
      int id=FileReadInteger(input_file);Flag=(uchar)FileReadInteger(input_file);Indicator=FileReadInteger(input_file);
      ErrorMode=FileReadInteger(input_file);int n=FileReadInteger(input_file);ArrayResize(Effects,n);
      for(int i=0;i<n;i++)
      { Effects[i].after=FileReadInteger(input_file);Effects[i].flag=FileReadInteger(input_file);
        Effects[i].set_indicator=FileReadInteger(input_file);Effects[i].indicator=FileReadInteger(input_file); }
      LogicalError=0;Calls=0;string name=folder+"events-"+IntegerToString(id)+".bin";
      TapeFile=FileOpen(name,FILE_WRITE|FILE_BIN);if(TapeFile==INVALID_HANDLE) return 5;
      Bot@N@DeinitializePanel(Flag,Indicator);Snapshot();FileClose(TapeFile);
      int event_file=FileOpen(name,FILE_READ|FILE_BIN);if(event_file==INVALID_HANDLE) return 6;
      int size=(int)FileSize(event_file);uchar bytes[];ArrayResize(bytes,size);
      if(size>0) FileReadArray(event_file,bytes,0,size);FileClose(event_file);
      FileWriteInteger(output,id);FileWriteInteger(output,size);if(size>0) FileWriteArray(output,bytes,0,size);
   }
   FileClose(input_file);FileClose(output);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
def generate(bot):
    path=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}LifecycleFullCheck.mq5'
    path.write_text(TEMPLATE.replace('@N@',str(bot)),encoding='utf-8',newline='\n')
def records(raw,count):
    r=Reader(raw);require(r.take('3i')==(MAGIC,1,count),'RESULT_HEADER');out=[]
    for i in range(count):
        id_,n=r.take('2i');require(id_==i and 24<=n<=len(raw)-r.pos,'RESULT_RECORD')
        out.append(bytes(r.raw[r.pos:r.pos+n]));r.pos+=n
    require(r.pos==len(raw),'RESULT_TRAILING');return out
class Native(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.c=CFG[bot]
        raw=bytes(self.m.mem_read(self.base+self.c['fn'],self.c['end']-self.c['fn']))
        require(hashlib.sha256(raw).hexdigest()==self.c['sha'],'NATIVE_BODY_CHANGED')
        self.sdk={0x7ff683f20000+off:api for api,off in [(1,0x7c4ce0),(2,0x7cdfe0),(3,0x7bee30),(4,0x7c4d40)]}
        for address in self.sdk:
            existed=address in self.apis
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.covered=set();self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,a,s,u:self.covered.add(a-self.base),begin=self.base+self.c['fn'],end=self.base+self.c['end']-1)
    def state(self):
        m=self.m;b=self.base;c=self.c
        return (m.mem_read(b+c['flag'],1)[0],struct.unpack('<i',m.mem_read(b+c['indicator'],4))[0]&MASK,
                struct.unpack('<I',m.mem_read(b+c['error'],4))[0])
    def read_text(self,desc):
        pointer=struct.unpack('<Q',self.m.mem_read(desc+4,8))[0]
        if not pointer:return None
        n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0];require(n<100000,'NATIVE_TEXT_LENGTH')
        return bytes(self.m.mem_read(pointer,n*2)).decode('utf-16-le')
    def call(self,m,address,size,user):
        if address not in self.sdk:return super().call(m,address,size,user)
        r=self.tape;api=self.sdk[address];x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))
        require(r.take('3Q')==self.state(),'STATE_BEFORE_SDK '+str((self.case['id'],self.calls,api)))
        kind,*args=r.take('i4Q');text=r.text();reply,error=r.take('QI')
        require(kind==api,'SDK_ORDER '+str((self.case['id'],self.calls,kind,api)))
        actual=[reg('RDX'),0,0,0]
        if api==1:require(self.read_text(reg('R8'))==text,'OBJECT_NAME '+str((self.case['id'],self.calls)))
        elif api==2:actual[1:3]=[reg('R8')&0xffffffff,reg('R9')&65535]
        elif api==3:actual[0]&=0xffffffff
        else:actual[1:3]=[reg('R8')&0xffffffff,reg('R9')&0xffffffff]
        require(actual==args,'SDK_ARGUMENTS '+str((self.case['id'],self.calls,api,actual,args)))
        if api==2:m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(text)))
        else:m.reg_write(x.UC_X86_REG_RAX,reply)
        m.mem_write(self.base+self.c['error'],struct.pack('<I',error));self.calls+=1
        for ordinal,flag,set_handle,handle in self.case['effects']:
            if ordinal!=self.calls:continue
            if flag>=0:m.mem_write(self.base+self.c['flag'],bytes([flag]))
            if set_handle:m.mem_write(self.base+self.c['indicator'],struct.pack('<i',handle))
    def run(self,case,tape):
        self.case=case;self.tape=Reader(tape);self.calls=0;self.cursor=0x70001000;self.allocs=self.frees=0
        m,x=self.m,self.x;c=self.c
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        m.mem_write(self.base+c['flag'],bytes([case['flag']]))
        m.mem_write(self.base+c['indicator'],struct.pack('<i',case['indicator']))
        m.mem_write(self.base+c['error'],bytes(4));m.mem_write(self.base+self.cfg['string_result'],bytes(12))
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        top=0x5001fef8;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.emu_start(self.base+c['fn'],0x60000000,timeout=10000000,count=4000000)
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_NO_RETURN')
        require(self.tape.take('3Q')==self.state() and self.tape.pos==len(tape),'FINAL_STATE_OR_TRAILING_TAPE')
        return tape
def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}LifecycleFullCheck.mq5'
    helpers=[Path(__file__),ROOT/'cong-cu/kiem-bang-thong-tin-lich-su-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/bien-dich.ps1']
    return dict(original_ex5_sha256=shared.selector.validation.original_hash(bot),native_body_sha256=CFG[bot]['sha'],
        sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},
        helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN')
    rows=cases(a.bot);current=identity(a.bot);home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build,'BUILD_REQUIRED');receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}LifecycleFullCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN');mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025'
        for n,h in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/f'MQL5/Files/bot{a.bot}-lifecycle-full'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('lifecycle-full-'+a.run+'.set');ini=mt/('lifecycle-full-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}LifecycleFullCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as stream:stream.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(folder/'mql5-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tapes=records((folder/'mql5-results.bin').read_bytes(),len(rows));native=Native(a.bot);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));counts=[]
        for c,tape in zip(rows,tapes):
            data=native.run(c,tape);raw+=struct.pack('<2i',c['id'],len(data))+data;counts.append(native.calls)
        with (folder/'original-results.bin').open('xb') as stream:stream.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),sdk_calls=sum(counts),events=counts,instructions=len(native.covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=sum(counts))));return
    for name in ['mql5','original']:
        run=json.loads((folder/(name+'-run.json')).read_text());require(all(run[k]==v for k,v in current.items()) and run['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    require((folder/'original-results.bin').read_bytes()==(folder/'mql5-results.bin').read_bytes(),'RESULTS_DIFFER')
    save(folder/'comparison.json',dict(cases=len(rows),matched=len(rows),failed=0,**SCOPE,limits=['Exact-byte flags, int32 handles, live mutations, error state and ordered SDK calls. Successful allocations; initialization, real chart rendering and full paired EA runs remain unverified.']))
    print(json.dumps(dict(cases=len(rows),matched=len(rows),failed=0)))
if __name__=='__main__':main()
