"""Extract and compare OnInit's literal fallback calendars and two flag resets.

generate BOT | prepare|mql5 --build BUILD|original|compare BOT RUN.
Only fixed 300-element arrays are used. Bot 3's tester-info reply/effect is
supplied; every array cell, both flags and service ordering are compared.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x49484331;MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('history_init_news',ROOT/'cong-cu/kiem-khoi-tao-tin-bot-1-3.py')
news=importlib.util.module_from_spec(spec);spec.loader.exec_module(news)
require,sha,save,pub=news.require,news.sha,news.save,news.pub
CFG={1:dict(start=0x1941,end=0x3827,flags=[0x69f60,0x69f61],arrays=[0x68330,0x68ca0,0x69600]),
     3:dict(start=0x193f,end=0x3840,flags=[0x76f90,0x76f91],arrays=[0x75360,0x75cd0,0x76630])}
SCOPE=dict(full_ea=False,native_literal_initialization_executed=True,all_900_array_cells_compared=True,
           two_native_flags_compared=True,tester_reply_and_effect_supplied=True,original_ex5_changed=False)

def signed(v):return (v+(1<<63))%(1<<64)-(1<<63)
def cases():
    out=[]
    for seed in [-1,0,1793100000]:
        for reply in [-1,0,1,2]:
            for effect in range(9):out.append(dict(id=len(out),seed=seed,reply=reply,effect=effect,flags=[173,255]))
    return out
def initial(c):return [[signed(c['seed']+j*10000+i*17) for i in range(300)] for j in range(3)]
def encoded(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<3iqi',c['id'],*c['flags'],c['reply'],c['effect'])
        for values in initial(c):raw+=struct.pack('<300q',*values)
    return bytes(raw)

class Native(news.selector.entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.bot,self.c=bot,CFG[bot];self.info=0x7ff683f20000+0x7c0fd0
        init=news.CFG[bot];require(hashlib.sha256(bytes(self.m.mem_read(self.base+0xc30,init['init_end']-0xc30))).hexdigest()==init['sha'],'INIT_BYTES_CHANGED')
        if not any(lo<=self.info<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(self.info&~4095,4096)
        self.m.mem_write(self.info,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=self.info,end=self.info)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.instruction,begin=self.base+self.c['start'],end=self.base+self.c['end'])
        self.m.hook_add(self.uc.UC_HOOK_MEM_WRITE,self.write)
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        self.md=Cs(CS_ARCH_X86,CS_MODE_64);self.md.detail=True
    def instruction(self,m,address,size,user):self.pc=address
    def write(self,m,access,address,size,value,user):
        off=address-self.base
        if off in self.c['flags']:self.writes.append((off,size,value&255,self.pc-self.base));return
        for start in self.c['arrays']:
            if start<=off<start+2400:self.writes.append((off,size,value&MASK,self.pc-self.base));return
        if self.base<=address<self.base+0x200000:raise ValueError('UNEXPECTED_PROGRAM_WRITE '+hex(off))
    def state(self):
        raw=b''.join(struct.pack('<Q',self.m.mem_read(self.base+off,1)[0]) for off in self.c['flags'])
        return raw+b''.join(bytes(self.m.mem_read(self.base+off,2400)) for off in self.c['arrays'])
    def effect(self):
        mode=self.case['effect'];m=self.m;c=self.c
        if mode in [1,2]:m.mem_write(self.base+c['flags'][mode-1],bytes([7 if mode==1 else 255]))
        elif mode in [3,4,5]:
            array,index,value={3:(0,299,-11),4:(1,250,123456789),5:(2,299,17)}[mode]
            m.mem_write(self.base+c['arrays'][array]+index*8,struct.pack('<q',value))
        elif mode in [6,7,8]:m.mem_write(self.base+c['arrays'][mode-6],struct.pack('<q',999))
    def call(self,m,address,size,user):
        require(address==self.info,'UNEXPECTED_SERVICE');x=self.x
        require(m.reg_read(x.UC_X86_REG_RCX)==news.CFG[self.bot]['ctx'] and m.reg_read(x.UC_X86_REG_RDX)==6,'TESTER_INFO_ARGUMENT')
        self.events+=self.state()+struct.pack('<iQ',6,self.case['reply']&MASK);self.calls+=1;self.effect();m.reg_write(x.UC_X86_REG_RAX,self.case['reply']&MASK)
    def run(self,c):
        self.case,self.events,self.calls,self.writes,self.pc=c,bytearray(),0,[],0;m,x=self.m,self.x
        for off,value in zip(self.c['flags'],c['flags']):m.mem_write(self.base+off,bytes([value]))
        for off,values in zip(self.c['arrays'],initial(c)):m.mem_write(self.base+off,struct.pack('<300q',*values))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        m.reg_write(x.UC_X86_REG_RSP,0x5001fe00);m.reg_write(x.UC_X86_REG_EFLAGS,0x202)
        m.emu_start(self.base+self.c['start'],self.base+self.c['end'],timeout=1000000,count=10000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+self.c['end'],'DATA_INIT_NOT_FINISHED')
        return bytes(self.events)+self.state()+struct.pack('<i',self.calls)
    def literal_data(self):
        c=dict(id=0,seed=-1,reply=0,effect=0,flags=[173,255]);self.run(c);arrays=[]
        from capstone import CS_OP_IMM
        for start,count in zip(self.c['arrays'],[240,89,134]):
            stores=[(a,s,v,pc) for a,s,v,pc in self.writes if start<=a<start+2400]
            require([a for a,_,_,_ in stores]==[start+8*i for i in range(count)] and all(s==8 for _,s,_,_ in stores),'ARRAY_STORE_LAYOUT')
            for _,_,value,pc in stores:
                i=next(self.md.disasm(bytes(self.m.mem_read(self.base+pc,15)),self.base+pc))
                require(i.mnemonic=='mov' and i.operands[-1].type==CS_OP_IMM and (i.operands[-1].imm&MASK)==value,'DATE_NOT_A_LITERAL')
            arrays.append([signed(v) for _,_,v,_ in stores])
        flag_stores=[(a,s,v) for a,s,v,_ in self.writes if a in self.c['flags']]
        require(len(flag_stores)==2 and all(s==1 and v==0 for a,s,v in flag_stores),'FLAG_INITIALIZATION_CHANGED')
        return arrays

SCRIPT=r'''#property strict
input string CheckRun="";
uchar HistoryFlag0,HistoryFlag1;long HistoryNfp[300],HistoryInterest[300],HistoryCpi[300],HistoryReply;
int HistoryEffect,HistoryCalls,HistoryOutput;
void HistoryState()
{
   FileWriteLong(HistoryOutput,(long)HistoryFlag0);FileWriteLong(HistoryOutput,(long)HistoryFlag1);
   for(int i=0;i<300;i++)FileWriteLong(HistoryOutput,HistoryNfp[i]);
   for(int i=0;i<300;i++)FileWriteLong(HistoryOutput,HistoryInterest[i]);
   for(int i=0;i<300;i++)FileWriteLong(HistoryOutput,HistoryCpi[i]);
}
long HistoryInfo(const ENUM_MQL_INFO_INTEGER property)
{
   HistoryState();FileWriteInteger(HistoryOutput,(int)property);FileWriteLong(HistoryOutput,HistoryReply);HistoryCalls++;
   if(HistoryEffect==1)HistoryFlag0=7;else if(HistoryEffect==2)HistoryFlag1=255;
   else if(HistoryEffect==3)HistoryNfp[299]=-11;else if(HistoryEffect==4)HistoryInterest[250]=123456789;
   else if(HistoryEffect==5)HistoryCpi[299]=17;else if(HistoryEffect==6)HistoryNfp[0]=999;
   else if(HistoryEffect==7)HistoryInterest[0]=999;else if(HistoryEffect==8)HistoryCpi[0]=999;
   return HistoryReply;
}
#define MQLInfoInteger HistoryInfo
#include "../../Include/bot-cua-toi-N/BotNBuiltInNewsHistory.mqh"
#undef MQLInfoInteger
int OnStart()
{
   if(CheckRun=="")return 1;string folder="botN-builtin-news-history\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x49484331 || version!=1 || count<1)return 3;
   HistoryOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(HistoryOutput==INVALID_HANDLE)return 4;
   FileWriteInteger(HistoryOutput,magic);FileWriteInteger(HistoryOutput,version);FileWriteInteger(HistoryOutput,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);HistoryFlag0=(uchar)FileReadInteger(file);HistoryFlag1=(uchar)FileReadInteger(file);HistoryReply=FileReadLong(file);HistoryEffect=FileReadInteger(file);
      for(int i=0;i<300;i++)HistoryNfp[i]=FileReadLong(file);for(int i=0;i<300;i++)HistoryInterest[i]=FileReadLong(file);for(int i=0;i<300;i++)HistoryCpi[i]=FileReadLong(file);
      HistoryCalls=0;FileWriteInteger(HistoryOutput,id);ulong at=FileTell(HistoryOutput);FileWriteInteger(HistoryOutput,0);ulong begin=FileTell(HistoryOutput);
      BotNInitializeBuiltInNewsHistory(HistoryFlag0,HistoryFlag1,HistoryNfp,HistoryInterest,HistoryCpi);HistoryState();FileWriteInteger(HistoryOutput,HistoryCalls);
      ulong end=FileTell(HistoryOutput);FileSeek(HistoryOutput,(long)at,SEEK_SET);FileWriteInteger(HistoryOutput,(int)(end-begin));FileSeek(HistoryOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 5;FileClose(file);FileClose(HistoryOutput);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''

def generate(bot):
    root=ROOT/f'bot-cua-toi-{bot}/source/MQL5';header=root/f'Include/bot-cua-toi-{bot}/Bot{bot}BuiltInNewsHistory.mqh';script=root/f'Scripts/bot-cua-toi-{bot}/Bot{bot}BuiltInNewsHistoryCheck.mq5'
    require(not header.exists() and not script.exists(),'SOURCE_EXISTS');native=Native(bot);values=native.literal_data()
    code=f'#ifndef BOT{bot}_BUILTIN_NEWS_HISTORY_MQH\n#define BOT{bot}_BUILTIN_NEWS_HISTORY_MQH\n\n// Fixed 300-cell arrays; only the native initialized prefixes are overwritten.\nvoid Bot{bot}InitializeBuiltInNewsHistory(uchar &native_flag0,uchar &native_flag1,\n                                          long &nfp_history[],long &interest_history[],long &cpi_history[])\n{{\n'
    for name,items in zip(['nfp','interest','cpi'],values):
        code+=f'   const long {name}_values[{len(items)}]={{\n'
        code+=',\n'.join('      '+','.join(str(v) for v in items[i:i+8]) for i in range(0,len(items),8))+'\n   };\n'
    if bot==1:code+='   native_flag1=0;\n   nfp_history[0]=nfp_values[0];\n   native_flag0=0;\n   for(int i=1;i<240;i++)nfp_history[i]=nfp_values[i];\n'
    else:code+='   native_flag0=0;\n   native_flag1=0;\n   MQLInfoInteger((ENUM_MQL_INFO_INTEGER)6);\n   for(int i=0;i<240;i++)nfp_history[i]=nfp_values[i];\n'
    code+='   for(int i=0;i<89;i++)interest_history[i]=interest_values[i];\n   for(int i=0;i<134;i++)cpi_history[i]=cpi_values[i];\n}\n#endif\n'
    header.write_text(code,encoding='utf-8',newline='\n');script.write_text(SCRIPT.replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}'),encoding='utf-8',newline='\n')
    folder=ROOT/'danh-gia-doc-lap/builtin-news-initialization-20261028-r1';folder.mkdir(parents=True,exist_ok=True)
    save(folder/f'bot{bot}-native.json',dict(original_ex5_sha256=news.selector.validation.original_hash(bot),native_init_sha256=news.CFG[bot]['sha'],span=[hex(CFG[bot]['start']),hex(CFG[bot]['end'])],array_rvas=list(map(hex,CFG[bot]['arrays'])),flag_rvas=list(map(hex,CFG[bot]['flags'])),initialized_counts=list(map(len,values)),values=values,all_dates_verified_as_native_immediate_stores=True))
    print(json.dumps(dict(bot=bot,counts=list(map(len,values)))))

def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}BuiltInNewsHistoryCheck.mq5'
    helpers=[Path(__file__),Path(news.__file__),ROOT/'cong-cu/kiem-chon-tin-day-du-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py']
    return dict(original_ex5_sha256=news.selector.validation.original_hash(bot),native_init_sha256=news.CFG[bot]['sha'],sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})

def records(raw,count):
    require(raw[:12]==struct.pack('<3i',MAGIC,1,count),'RESULT_HEADER');at=12;out=[]
    for i in range(count):
        id_,size=struct.unpack_from('<2i',raw,at);at+=8;require(id_==i and size in [7220,14448] and size<=len(raw)-at,'RESULT_RECORD');out.append(raw[at:at+size]);at+=size
    require(at==len(raw),'RESULT_TRAILING');return out

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows,current=cases(),identity(a.bot);home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;head=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encoded(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encoded(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BUILD_REQUIRED');mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}BuiltInNewsHistoryCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/f'MQL5/Files/bot{a.bot}-builtin-news-history'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=mt/'MQL5/Presets'/('builtin-news-'+a.run+'.set');ini=mt/('builtin-news-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}BuiltInNewsHistoryCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as out:out.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        native=Native(a.bot);raw=bytearray(head);calls=0
        for row in rows:
            data=native.run(row);raw+=struct.pack('<2i',row['id'],len(data))+data;calls+=native.calls
        with (folder/'original-results.bin').open('xb') as out:out.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),calls=calls,result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),calls=calls)));return
    for name in ['original','mql5']:
        report=json.loads((folder/(name+'-run.json')).read_text());require(all(report[k]==v for k,v in current.items()) and report['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    x,y=[records((folder/(name+'-results.bin')).read_bytes(),len(rows)) for name in ['original','mql5']];fail=[]
    for c,a,b in zip(rows,x,y):
        if a!=b:fail.append(dict(case=c['id'],first_difference=next((i for i,(v,w) in enumerate(zip(a,b)) if v!=w),None),sizes=[len(a),len(b)]))
    report=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:8],**SCOPE,limits=['Literal calendar initialization and two flags only. Fixed 300-element arrays; source allocation failure and full EA are excluded.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(fail))
if __name__=='__main__':main()
