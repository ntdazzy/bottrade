"""Compare OnInit 0x3827..0x3c9d before the first preparation call.

generate | prepare|mql5 --build BUILD|original|compare RUN.
The preceding account block guarantees XMM6=+0.0 and a non-null numeric
string-return buffer. These two live-in conditions are supplied explicitly.
Native string helpers execute; the four MULSD operations execute on the CPU.
"""
import argparse,ctypes,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x53433131;MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
base=module('startup_gate','kiem-cong-dieu-phoi-bot-1-3.py');history=module('startup_host','kiem-lich-su-chien-luoc-bot-1-3.py')
require,sha,save,pub=base.require,base.sha,base.save,base.pub
INIT_SHA='83265d19458eeaa76d297459c6e7929f98c8f74227a4c864967a519dd046c18d'
FIELDS=[('BootContext.magic','i',0x6246c),('BootContext.converted_value','d',0x69f70),('BootInputs.base_magic','i',0x6a610),
 ('BootInputs.keep_comment','B',0x6a628),('BootDaily.peak','d',0x68318),('BootDaily.blocked','B',0x682e0),('BootDaily.bars','i',0x682e4),
 ('BootState.panel_bar','q',0x68308),('BootHistory.total','i',0x6a318),('BootHistory.count','i',0x6a314),('BootState.extended_cleanup','B',0x68294),
 ('BootPanel.cell_font_flag','B',0x682a8),('BootState.cell_base_x','d',0x682f8),('BootState.cell_base_y','d',0x68300),
 ('BootPanel.scale','d',0x6a538),('BootPanel.cell_x','d',0x68298),('BootPanel.cell_y','d',0x682a0)]
TEXTS=[('BootInputs.comment_prefix',0x6a618),('BootInputs.symbol_suffix',0x62208),('BootContext.order_comment',0x62470),
       ('BootPreparation.symbol',0x67918),('BootChartSymbol',0x6a428)]
SCOPE=dict(full_ea=False,native_startup_context_executed=True,native_string_helpers_executed=True,
           mulsd_executed_on_host_cpu=True,caller_xmm6_zero_supplied=True,caller_string_return_buffer_primed=True,
           string_allocation_success_supplied=True,allocation_failures_tested=False,original_ex5_changed=False)
def bits(value):return struct.unpack('<Q',struct.pack('<d',value))[0]
def number(word):return struct.unpack('<d',struct.pack('<Q',word))[0]
def text(value):
    if value is None:return struct.pack('<i',-1)
    raw=value.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def cases():
    out=[]
    def add(symbol='XAUUSD.a',suffix='',comment='Gold Trade Pro',magic=9000,updates=None):
        values=[-123,3.5,magic,2,999.5,173,77,123456,33,44,173,1,1.,1.,1.,-1.,-2.]
        for index,value in (updates or {}).items():values[index]=value
        out.append(dict(id=len(out),values=values,texts=[comment,suffix,'old comment','old symbol',symbol],error=len(out)%2))
    symbols=[None,'','XAUUSD','XAUUSD.a','XAUUSD.α','XAUUSD🚀','GOLD','XAUUSD123456789','XAUUSD1234567890XYZ']
    for symbol in symbols:
        for suffix in [None,'','preset']:
            for comment in [None,'Vàng 🚀']:
                for magic in [-2147483648,0,2147483647]:add(symbol,suffix,comment,magic)
    values=[-0.,0.,-1.,.5,1.,1e-320,1e308,float('inf'),-float('inf'),float('nan')]
    for flag in [0,1,2,255]:
        for scale in values:
            for x,y in [(1.,1.),(-1.,0.),(float('inf'),float('nan'))]:add(suffix='preset',updates={11:flag,12:x,13:y,14:scale})
    special=[number(v) for v in [0x7ff8000000000041,0xfff8000000000042,0x7ff0000000000043,0xfff0000000000044]]
    for a in special:
        for b in special:add(suffix='preset',updates={12:a,13:b,14:b})
    return out
def encoded(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<i',c['id'])
        for (_,kind,_),value in zip(FIELDS,c['values']):raw+=struct.pack('<Q',bits(value) if kind=='d' else int(value)&MASK)
        raw+=b''.join(text(v) for v in c['texts'])+struct.pack('<i',c['error'])
    return bytes(raw)

TEMPLATE=r'''#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1StrategyContext.mqh"
#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1StrategyHistory.mqh"
#include "../../Include/bot-cua-toi-1/Bot1PanelCreation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1DailyLossGuard.mqh"
void BootPrint(const string value);
#define Print BootPrint
#include "../../Include/bot-cua-toi-1/Bot1StartupContext.mqh"
#undef Print
Bot1StrategyContextInputs BootInputs;Bot1StrategyContextState BootContext;Bot1PreparationInputs BootPreparation;
Bot1StrategyHistoryCache BootHistory;Bot1PanelCreationState BootPanel;Bot1DailyLossState BootDaily;Bot1StartupContextState BootState;
string BootChartSymbol;int BootOutput,BootPrints;
union BootNumber { double value;ulong word; };
ulong BootBits(const double value){BootNumber n;n.value=value;return n.word;}
double BootValue(const ulong value){BootNumber n;n.word=value;return n.value;}
void BootText(const string value){int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(BootOutput,n);if(n>0)FileWriteString(BootOutput,value,n);}
string BootReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void BootSnapshot(const uint error)
{
@STATE@
   FileWriteLong(BootOutput,(long)error);
@TEXTS@
}
void BootPrint(const string value){uint error=GetLastError();BootSnapshot(error);BootText(value);BootPrints++;}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-startup-context\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x53433131 || version!=1 || count<1)return 3;
   BootOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(BootOutput==INVALID_HANDLE)return 4;
   FileWriteInteger(BootOutput,magic);FileWriteInteger(BootOutput,version);FileWriteInteger(BootOutput,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);
@READ@
@READ_TEXTS@
      int error=FileReadInteger(file);BootPrints=0;
      string primed=IntegerToString(12345);if(primed!="12345")return 5;
      FileWriteInteger(BootOutput,id);ulong at=FileTell(BootOutput);FileWriteInteger(BootOutput,0);ulong begin=FileTell(BootOutput);
      ResetLastError();if(error!=0)SetUserError(731);
      Bot1InitializeStartupContext(BootChartSymbol,BootInputs,BootContext,BootPreparation,BootHistory,BootPanel,BootDaily,BootState);
      uint final_error=GetLastError();BootSnapshot(final_error);FileWriteInteger(BootOutput,BootPrints);
      ulong end=FileTell(BootOutput);FileSeek(BootOutput,(long)at,SEEK_SET);FileWriteInteger(BootOutput,(int)(end-begin));FileSeek(BootOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 6;FileClose(file);FileClose(BootOutput);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
def generate():
    folder=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1';path=folder/'Bot1StartupContextCheck.mq5';require(not path.exists(),'SOURCE_EXISTS')
    writes='\n'.join('   FileWriteLong(BootOutput,(long)'+(f'BootBits({name})' if kind=='d' else name)+');' for name,kind,_ in FIELDS)
    reads='\n'.join('      '+name+'='+('BootValue((ulong)FileReadLong(file))' if kind=='d' else ('(uchar)' if kind=='B' else '(int)' if kind=='i' else '')+'FileReadLong(file)')+';' for name,kind,_ in FIELDS)
    code=TEMPLATE.replace('@STATE@',writes).replace('@TEXTS@','\n'.join('   BootText('+name+');' for name,_ in TEXTS)).replace('@READ@',reads).replace('@READ_TEXTS@','\n'.join('      '+name+'=BootReadText(file);' for name,_ in TEXTS))
    path.write_text(code,encoding='utf-8',newline='\n');print(path)

class HostProduct(history.HostAddition):
    def __init__(self):
        super().__init__();code=self.CODE.replace(bytes.fromhex('f20f58c1'),bytes.fromhex('f20f59c1'));p=self.address+256
        ctypes.memmove(p,code,len(code));self.mul=ctypes.WINFUNCTYPE(ctypes.c_uint64,ctypes.c_uint64,ctypes.c_uint64)(p)
        require(self.mul(bits(3.),bits(2.))==bits(6.),'HOST_MUL_CALIBRATION')

class Native(base.Original):
    def __init__(self):
        super().__init__(1);require(hashlib.sha256(bytes(self.m.mem_read(self.base+0xc30,0x5880-0xc30))).hexdigest()==INIT_SHA,'INIT_CHANGED')
        self.print_api=0x7ff683f20000+0x7b49f0
        if not any(lo<=self.print_api<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(self.print_api&~4095,4096)
        self.m.mem_write(self.print_api,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=self.print_api,end=self.print_api)
        self.host=HostProduct();self.mul_count=0
        self.products={0x38e9:('XMM1','mem','RAX'),0x38fb:('XMM1','reg','XMM0'),0x393e:('XMM6','mem','RAX'),0x394c:('XMM0','reg','XMM6')}
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        md=Cs(CS_ARCH_X86,CS_MODE_64)
        expected={0x38e9:'xmm1, qword ptr [rax]',0x38fb:'xmm1, xmm0',0x393e:'xmm6, qword ptr [rax]',0x394c:'xmm0, xmm6'}
        for off in self.products:
            i=next(md.disasm(bytes(self.m.mem_read(self.base+off,15)),self.base+off));require(i.mnemonic=='mulsd' and i.op_str==expected[off],'MULSD_CHANGED')
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.multiply,begin=self.base+off,end=self.base+off)
    def close(self):self.host.close()
    def multiply(self,m,address,size,user):
        dest,kind,right=self.products[address-self.base];x=self.x;left=m.reg_read(getattr(x,'UC_X86_REG_'+dest))
        value=struct.unpack('<Q',m.mem_read(m.reg_read(getattr(x,'UC_X86_REG_'+right)),8))[0] if kind=='mem' else m.reg_read(getattr(x,'UC_X86_REG_'+right))&MASK
        result=self.host.mul(left&MASK,value);m.reg_write(getattr(x,'UC_X86_REG_'+dest),(left&~MASK)|result);m.reg_write(x.UC_X86_REG_RIP,address+size);self.mul_count+=1
    def state(self):
        raw=bytearray()
        for _,kind,off in FIELDS:
            fmt='Q' if kind=='d' else kind;v=struct.unpack('<'+fmt,self.m.mem_read(self.base+off,struct.calcsize('<'+fmt)))[0];raw+=struct.pack('<Q',v&MASK)
        raw+=struct.pack('<Q',struct.unpack('<I',self.m.mem_read(self.base+0x6a410,4))[0])
        return bytes(raw)+b''.join(text(self.read_text(self.base+off)) for _,off in TEXTS)
    def call(self,m,address,size,user):
        if address!=self.print_api:return super().call(m,address,size,user)
        x=self.x;require(m.reg_read(x.UC_X86_REG_RCX)==self.gate['ctx'] and m.reg_read(x.UC_X86_REG_RDX)==2 and m.reg_read(x.UC_X86_REG_R8)==1 and m.reg_read(x.UC_X86_REG_R9)==0x590008,'PRINT_ARGUMENTS')
        sp=m.reg_read(x.UC_X86_REG_RSP);desc=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
        self.events+=self.state()+text(self.read_text(desc));self.prints+=1
    def put_text(self,off,value):self.m.mem_write(self.base+off,struct.pack('<IQ',0,0 if value is None else self.string(value)))
    def run(self,c):
        self.case,self.events,self.prints,self.cursor=c,bytearray(),0,0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for (_,kind,off),value in zip(FIELDS,c['values']):
            size=struct.calcsize('<'+kind);word=bits(value) if kind=='d' else int(value)&((1<<(8*size))-1);m.mem_write(self.base+off,word.to_bytes(size,'little'))
        for (_,off),value in zip(TEXTS,c['texts']):self.put_text(off,value)
        self.put_text(0x6a43c,'12345');m.mem_write(self.base+0x6a410,struct.pack('<I',65536+731 if c['error'] else 0))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        sp=0x5001fe00;m.mem_write(sp,bytes(0x100));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.reg_write(x.UC_X86_REG_R15,self.base+0x5c0);m.reg_write(x.UC_X86_REG_R12,self.print_api);m.reg_write(x.UC_X86_REG_R9,self.base+0x5d6e8)
        m.emu_start(self.base+0x3827,self.base+0x3c9d,timeout=2000000,count=200000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+0x3c9d,'STARTUP_CONTEXT_NOT_FINISHED')
        return bytes(self.events)+self.state()+struct.pack('<i',self.prints)

def identity():
    src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupContextCheck.mq5'
    helpers=[Path(__file__),Path(base.__file__),Path(history.__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',ROOT/'danh-gia-doc-lap/strategy-history-20261028-r1/nan-add-cpu-probe.json']
    return dict(original_ex5_sha256=base.base.validation.original_hash(1),native_init_sha256=INIT_SHA,sources_sha256={p.relative_to(src).as_posix():sha(p) for p in pub.closure(script,src)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def records(raw,count):
    require(raw[:12]==struct.pack('<3i',MAGIC,1,count),'RESULT_HEADER');at=12;out=[]
    for i in range(count):
        id_,size=struct.unpack_from('<2i',raw,at);at+=8;require(id_==i and 168<=size<=len(raw)-at,'RESULT_RECORD');out.append(raw[at:at+size]);at+=size
    require(at==len(raw),'RESULT_TRAILING');return out
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate();return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows,current=cases(),identity();home=ROOT/'bot-cua-toi-1';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;head=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encoded(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    before=json.loads((folder/'baseline.json').read_text());require(all(before[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encoded(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build,'BUILD_REQUIRED');mt=ROOT.parent/'.local/mt5-bot1-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script='Scripts/bot-cua-toi-1/Bot1StartupContextCheck.mq5';require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/'MQL5/Files/bot1-startup-context'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('startup-context-'+a.run+'.set');ini=mt/('startup-context-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1StartupContextCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as out:out.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        o=Native();raw=bytearray(head);prints=0
        try:
            for c in rows:data=o.run(c);raw+=struct.pack('<2i',c['id'],len(data))+data;prints+=o.prints
        finally:o.close()
        with (folder/'original-results.bin').open('xb') as out:out.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),prints=prints,host_mulsd=o.mul_count,result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),prints=prints,host_mulsd=o.mul_count)));return
    for name in ['original','mql5']:
        r=json.loads((folder/(name+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    x,y=[records((folder/(name+'-results.bin')).read_bytes(),len(rows)) for name in ['original','mql5']];fail=[]
    for c,v,w in zip(rows,x,y):
        if v!=w:fail.append(dict(case=c['id'],input=c,first_difference=next((i for i,(a,b) in enumerate(zip(v,w)) if a!=b),None),sizes=[len(v),len(w)]))
    r=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:8],**SCOPE,limits=['Startup context before first preparation only. Caller live-in XMM6=0 and non-null string-return buffer supplied; allocation failures, full static initializer, full OnInit and EA excluded.'])
    save(folder/'comparison.json',r);print(json.dumps(r,ensure_ascii=False));raise SystemExit(bool(fail))
if __name__=='__main__':main()
