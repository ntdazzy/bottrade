"""Compare OnInit's three calendar queries, messages and shared news selector.

generate BOT | prepare|mql5 --build BUILD|original|compare BOT RUN.
Calendar results are supplied; datetime text replies are measured in MT5 and
supplied at the native cast boundary. Native string helpers and selector run.
"""
import argparse
import hashlib
import importlib.util
import json
import random
import re
import shutil
import struct
import subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x494e5331;MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('init_news_selector',ROOT/'cong-cu/kiem-chon-tin-day-du-bot-1-3.py')
selector=importlib.util.module_from_spec(spec);spec.loader.exec_module(selector)
require,sha,save,pub=selector.require,selector.sha,selector.save,selector.pub
CFG={1:dict(end=0x126c,init_end=0x5880,query=0x6a3a8,calendars=[0x61b0,0x6600,0x6a90],ctx=0x23e575eae78,sha='83265d19458eeaa76d297459c6e7929f98c8f74227a4c864967a519dd046c18d'),
     3:dict(end=0x1279,init_end=0x61a0,query=0x1d6cb8,calendars=[0x6ad0,0x6f20,0x73b0],ctx=0x171514ca538,sha='66812ca6397edc00b872cfc3b38ca7606cc3dc7d5cf084433c579ea13e90771c')}
SCOPE=dict(full_ea=False,native_news_initialization_and_selector_executed=True,calendar_bodies_replaced=True,
           native_string_helpers_executed=True,datetime_text_replies_measured_in_mt5=True,
           authorization_executed=False,allocation_failures_tested=False,original_ex5_changed=False)


def text(value):
    if value is None:return struct.pack('<i',-1)
    data=value.encode('utf-16-le');return struct.pack('<i',len(data)//2)+data


def fields(bot):
    c=selector.CFG[bot]
    return [('B',v) for v in c['flags']]+[('i',v) for v in c['minutes']]+[('q',v) for v in c['times']]+[('q',c['time']),('q',CFG[bot]['query'])]


def cases():
    out=[]
    def add(flags=(1,1,1),replies=(900,1000,1100),minutes=(10,10,10),clocks=(1000,1000,1000),effects=()):
        out.append(dict(id=len(out),values=list(flags)+list(minutes)+[33,44,55,777,-123],label='old',replies=list(replies),clocks=list(clocks),effects=list(effects)))
    for mask in range(8):
        for replies in [(0,0,0),(900,1000,1100),(1100,900,1000),(1000,1100,900),(-1,1,0)]:
            for m in [-2147483648,-1,0,10,35791395,2147483647]:add([(mask>>i)&1 for i in range(3)],replies,[m]*3)
    for flags in [(255,255,255),(2,0,0),(0,128,255)]:add(flags)
    for value in [-1,0,1,2147483647,2147483648,32535215999]:add(replies=[value]*3)
    for api in range(1,7):
        for n in [1,2]:
            for field in range(11):
                for value in [0,255]:add(effects=[(api,n,field,value)])
            for value in [None,'changed 🐱']:add(effects=[(api,n,11,value)])
    rng=random.Random(2026102852)
    for _ in range(100):
        add(flags=[rng.choice([0,1,2,255]) for _ in range(3)],replies=[rng.choice([-1,0,1,1793100000+rng.randrange(100000)]) for _ in range(3)],
            minutes=[rng.choice([-2147483648,-1,0,1,10,2147483647]) for _ in range(3)],clocks=[1793100000+rng.randrange(100000) for _ in range(3)])
    return out


def encoded(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<i11q',c['id'],*c['values'])+text(c['label'])+struct.pack('<6qi',*c['replies'],*c['clocks'],len(c['effects']))
        for api,n,field,value in c['effects']:raw+=struct.pack('<3i',api,n,field)+(text(value) if field==11 else struct.pack('<q',value))
    return bytes(raw)


SCRIPT=r'''#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-N/BotNNfpCalendar.mqh"
#include "../../Include/bot-cua-toi-N/BotNReleaseCalendars.mqh"
datetime InitServer();
#define TimeTradeServer InitServer
#include "../../Include/bot-cua-toi-N/BotNNewsSelector.mqh"
#undef TimeTradeServer
BotNNewsWindows InitWindows;BotNNewsEvents InitEvents;BotNNewsSelection InitSelection;
long InitQuery,InitReplies[3],InitClocks[3];int InitCounts[7],InitOutput;
struct InitEffect { int api,n,field;long value;string label; };InitEffect InitEffects[];
void InitText(const string value)
{
   int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(InitOutput,n);if(n>0)FileWriteString(InitOutput,value,n);
}
string InitReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void InitState()
{
   FileWriteLong(InitOutput,(long)InitWindows.nfp_enabled);FileWriteLong(InitOutput,(long)InitWindows.interest_enabled);FileWriteLong(InitOutput,(long)InitWindows.cpi_enabled);
   FileWriteLong(InitOutput,(long)InitWindows.nfp_after);FileWriteLong(InitOutput,(long)InitWindows.interest_after);FileWriteLong(InitOutput,(long)InitWindows.cpi_after);
   FileWriteLong(InitOutput,InitEvents.nfp);FileWriteLong(InitOutput,InitEvents.interest);FileWriteLong(InitOutput,InitEvents.cpi);
   FileWriteLong(InitOutput,InitSelection.block_time);FileWriteLong(InitOutput,InitQuery);InitText(InitSelection.label);
}
void InitEffectNow(const int api,const int n)
{
   for(int i=0;i<ArraySize(InitEffects);i++)
   {
      if(InitEffects[i].api!=api || InitEffects[i].n!=n)continue;
      long v=InitEffects[i].value;
      switch(InitEffects[i].field)
      {
         case 0:InitWindows.nfp_enabled=(uchar)v;break;case 1:InitWindows.interest_enabled=(uchar)v;break;case 2:InitWindows.cpi_enabled=(uchar)v;break;
         case 3:InitWindows.nfp_after=(int)v;break;case 4:InitWindows.interest_after=(int)v;break;case 5:InitWindows.cpi_after=(int)v;break;
         case 6:InitEvents.nfp=v;break;case 7:InitEvents.interest=v;break;case 8:InitEvents.cpi=v;break;
         case 9:InitSelection.block_time=v;break;case 10:InitQuery=v;break;case 11:InitSelection.label=InitEffects[i].label;break;
      }
   }
}
void InitRecord(const int api,const long argument,const string value=NULL)
{
   InitState();FileWriteInteger(InitOutput,api);FileWriteLong(InitOutput,argument);InitText(value);int n=++InitCounts[api];InitEffectNow(api,n);
}
long InitNfp(){long reply=InitReplies[0];InitRecord(1,reply);return reply;}
long InitInterest(){long reply=InitReplies[1];InitRecord(2,reply);return reply;}
long InitCpi(){long reply=InitReplies[2];InitRecord(3,reply);return reply;}
datetime InitServer(){int n=InitCounts[6];long reply=InitClocks[n<3 ? n : 2];InitRecord(6,reply);return (datetime)reply;}
void InitPrint(const string value){InitRecord(5,0,value);}
string BotNInitializationTimeText(const datetime value){string reply=(string)value;InitRecord(4,(long)value,reply);return reply;}
#define BOTN_INITIALIZATION_TIME_TEXT_MQH
#define BotNFindNfpTime InitNfp
#define BotNFindInterestRateTime InitInterest
#define BotNFindCpiTime InitCpi
#define Print InitPrint
#include "../../Include/bot-cua-toi-N/BotNNewsInitialization.mqh"
#undef Print
#undef BotNFindNfpTime
#undef BotNFindInterestRateTime
#undef BotNFindCpiTime
int OnStart()
{
   if(CheckRun=="")return 1;string folder="botN-news-initialization\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x494e5331 || version!=1 || count<1)return 3;
   InitOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(InitOutput==INVALID_HANDLE)return 4;
   FileWriteInteger(InitOutput,magic);FileWriteInteger(InitOutput,version);FileWriteInteger(InitOutput,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);InitWindows.nfp_enabled=(uchar)FileReadLong(file);InitWindows.interest_enabled=(uchar)FileReadLong(file);InitWindows.cpi_enabled=(uchar)FileReadLong(file);
      InitWindows.nfp_after=(int)FileReadLong(file);InitWindows.interest_after=(int)FileReadLong(file);InitWindows.cpi_after=(int)FileReadLong(file);
      InitEvents.nfp=FileReadLong(file);InitEvents.interest=FileReadLong(file);InitEvents.cpi=FileReadLong(file);InitSelection.block_time=FileReadLong(file);InitQuery=FileReadLong(file);InitSelection.label=InitReadText(file);
      for(int i=0;i<3;i++)InitReplies[i]=FileReadLong(file);for(int i=0;i<3;i++)InitClocks[i]=FileReadLong(file);
      int effects=FileReadInteger(file);if(effects<0 || effects>128)return 5;ArrayResize(InitEffects,effects);
      for(int i=0;i<effects;i++){InitEffects[i].api=FileReadInteger(file);InitEffects[i].n=FileReadInteger(file);InitEffects[i].field=FileReadInteger(file);InitEffects[i].value=0;InitEffects[i].label=NULL;if(InitEffects[i].field==11)InitEffects[i].label=InitReadText(file);else InitEffects[i].value=FileReadLong(file);}
      ArrayInitialize(InitCounts,0);FileWriteInteger(InitOutput,id);ulong at=FileTell(InitOutput);FileWriteInteger(InitOutput,0);ulong begin=FileTell(InitOutput);
      BotNInitializeNews(InitWindows,InitEvents,InitSelection,InitQuery);InitState();
      ulong end=FileTell(InitOutput);FileSeek(InitOutput,(long)at,SEEK_SET);FileWriteInteger(InitOutput,(int)(end-begin));FileSeek(InitOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 6;FileClose(file);FileClose(InitOutput);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''


def generate(bot):
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}';path=folder/f'Bot{bot}NewsInitializationCheck.mq5';require(not path.exists(),'SOURCE_EXISTS')
    code=SCRIPT.replace('BOTN_',f'BOT{bot}_').replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}')
    path.write_text(code,encoding='utf-8',newline='\n')
    api=folder/f'Bot{bot}NewsInitializationAPICompile.mq5';require(not api.exists(),'API_EXISTS')
    api.write_text(f'#property strict\n#include "../../Include/bot-cua-toi-{bot}/Bot{bot}NewsInitialization.mqh"\nvoid OnStart(){{Bot{bot}NewsWindows windows;Bot{bot}NewsEvents events;Bot{bot}NewsSelection selection;long query=0;ZeroMemory(windows);ZeroMemory(events);Bot{bot}InitializeNews(windows,events,selection,query);}}\n',encoding='utf-8',newline='\n')
    print(path)


class Reader:
    def __init__(self,raw):self.raw,self.pos=raw,0
    def take(self,fmt):
        n=struct.calcsize('<'+fmt);require(self.pos+n<=len(self.raw),'TAPE_TRUNCATED');out=struct.unpack_from('<'+fmt,self.raw,self.pos);self.pos+=n;return out
    def text(self):
        n,=self.take('i');require(-1<=n<10000,'TAPE_TEXT_SIZE')
        if n<0:return None
        require(self.pos+2*n<=len(self.raw),'TAPE_TEXT_TRUNCATED');out=self.raw[self.pos:self.pos+2*n].decode('utf-16-le');self.pos+=2*n;return out
    def state(self):
        begin=self.pos;self.take('11Q');self.text();return self.raw[begin:self.pos]


class Native(selector.Original):
    def __init__(self,bot):
        super().__init__(bot);self.bot,self.c,self.fs=bot,CFG[bot],fields(bot)
        body=bytes(self.m.mem_read(self.base+0xc30,self.c['init_end']-0xc30));require(hashlib.sha256(body).hexdigest()==self.c['sha'],'INIT_BYTES_CHANGED')
        self.sdk={0x7ff683f20000+0x7cf6c0:4,0x7ff683f20000+0x7b49f0:5,0x7ff683f20000+0x7d1ce0:6}
        for addr in self.sdk:
            existed=addr in self.apis
            if not any(lo<=addr<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(addr&~4095,4096)
            self.m.mem_write(addr,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
        for off in self.c['calendars']:self.m.hook_add(self.uc.UC_HOOK_CODE,self.calendar,begin=self.base+off,end=self.base+off)

    def state(self):
        result=bytearray()
        for kind,off in self.fs:
            value=struct.unpack('<'+kind,self.m.mem_read(self.base+off,struct.calcsize('<'+kind)))[0];result+=struct.pack('<Q',value&MASK)
        return bytes(result)+text(self.read_text(self.base+self.selector['label']))

    def effect(self,api):
        for a,n,index,value in self.case['effects']:
            if a!=api or n!=self.counts[api]:continue
            if index==11:self.m.mem_write(self.base+self.selector['label'],struct.pack('<IQ',0,0 if value is None else self.string(value)))
            else:
                kind,off=self.fs[index];nbytes=struct.calcsize('<'+kind)
                self.m.mem_write(self.base+off,(int(value)&((1<<(8*nbytes))-1)).to_bytes(nbytes,'little'))

    def event(self,api):
        expected=self.tape.state();actual=self.state();require(expected==actual,'STATE_BEFORE_EVENT '+str((self.case['id'],api,self.counts,next((i for i,(a,b) in enumerate(zip(expected,actual)) if a!=b),None))))
        kind,argument=self.tape.take('iQ');label=self.tape.text();require(kind==api,'EVENT_ORDER '+str((self.case['id'],api,kind)))
        self.counts[api]+=1;return argument,label

    def calendar(self,m,address,size,user):
        api=self.c['calendars'].index(address-self.base)+1;argument,label=self.event(api);reply=self.case['replies'][api-1]
        require(argument==reply&MASK and label is None,'CALENDAR_REPLY_NOT_INPUT')
        self.effect(api);x=self.x;sp=m.reg_read(x.UC_X86_REG_RSP);target=struct.unpack('<Q',m.mem_read(sp,8))[0]
        require(self.base+0xd60<target<self.base+self.c['end'],'CALENDAR_RETURN_OUTSIDE_SEGMENT')
        m.reg_write(x.UC_X86_REG_RAX,reply&MASK);m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,target)

    def call(self,m,address,size,user):
        if address not in self.sdk:return super().call(m,address,size,user)
        api=self.sdk[address];argument,label=self.event(api);x=self.x
        require(m.reg_read(x.UC_X86_REG_RCX)==self.c['ctx'],'BAD_CONTEXT')
        if api==4:
            require(m.reg_read(x.UC_X86_REG_RDX)==argument and m.reg_read(x.UC_X86_REG_R8)==0x54,'CAST_ARGUMENT_CHANGED')
            out=m.reg_read(x.UC_X86_REG_R9);m.mem_write(out,struct.pack('<IQ',0,0 if label is None else self.string(label)))
        elif api==5:
            require(m.reg_read(x.UC_X86_REG_RDX)==2 and m.reg_read(x.UC_X86_REG_R8)==1 and m.reg_read(x.UC_X86_REG_R9)==0x590008,'PRINT_SHAPE_CHANGED')
            sp=m.reg_read(x.UC_X86_REG_RSP);descriptor=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
            require(argument==0 and self.read_text(descriptor)==label,'PRINT_TEXT_CHANGED '+str((self.case['id'],self.read_text(descriptor),label)))
        else:
            reply=self.case['clocks'][min(self.counts[6]-1,2)];require(argument==reply&MASK and label is None,'SERVER_REPLY_NOT_INPUT');m.reg_write(x.UC_X86_REG_RAX,reply&MASK)
        self.effect(api)

    def run(self,row,tape):
        self.case,self.tape,self.counts=row,Reader(tape),[0]*7;self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for (kind,off),value in zip(self.fs,row['values']):m.mem_write(self.base+off,(value&((1<<(8*struct.calcsize('<'+kind)))-1)).to_bytes(struct.calcsize('<'+kind),'little'))
        m.mem_write(self.base+self.selector['label'],struct.pack('<IQ',0,self.string(row['label'])))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        sp=0x5001fe00;m.mem_write(sp,bytes(0x100));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.emu_start(self.base+0xd60,self.base+self.c['end'],timeout=3000000,count=200000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+self.c['end'],'INIT_NEWS_NOT_FINISHED')
        require(self.tape.state()==self.state() and self.tape.pos==len(tape),'FINAL_STATE_CHANGED '+str(row['id']));return tape


def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}NewsInitializationCheck.mq5'
    helpers=[Path(__file__),Path(selector.__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py']
    return dict(original_ex5_sha256=selector.validation.original_hash(bot),native_init_sha256=CFG[bot]['sha'],sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})


def records(raw,count):
    require(raw[:12]==struct.pack('<3i',MAGIC,1,count),'RESULT_HEADER');at=12;out=[]
    for i in range(count):
        id_,n=struct.unpack_from('<2i',raw,at);at+=8;require(id_==i and 92<=n<=len(raw)-at,'RESULT_RECORD');out.append(raw[at:at+n]);at+=n
    require(at==len(raw),'RESULT_TRAILING');return out


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows,current=cases(),identity(a.bot);home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encoded(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encoded(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BUILD_REQUIRED');mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}NewsInitializationCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/f'MQL5/Files/bot{a.bot}-news-initialization'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('news-init-'+a.run+'.set');ini=mt/('news-init-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}NewsInitializationCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as out:out.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        native=Native(a.bot);tapes=records((folder/'mql5-results.bin').read_bytes(),len(rows));raw=bytearray(header);calls=0
        for row,tape in zip(rows,tapes):
            try:result=native.run(row,tape)
            except Exception as exc:save(folder/'failure.json',dict(case=row['id'],reason=str(exc),position=native.tape.pos,counts=native.counts));raise
            raw+=struct.pack('<2i',row['id'],len(result))+result;calls+=sum(native.counts)
        with (folder/'original-results.bin').open('xb') as out:out.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),calls=calls,result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),calls=calls)));return
    for name in ['original','mql5']:
        report=json.loads((folder/(name+'-run.json')).read_text());require(all(report[k]==v for k,v in current.items()) and report['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    x=(folder/'original-results.bin').read_bytes();y=(folder/'mql5-results.bin').read_bytes();require(x==y,'RESULTS_DIFFER')
    report=dict(cases=len(rows),matched=len(rows),failed=0,**SCOPE,limits=['OnInit news section only. Calendar bodies and datetime primitive replies supplied; native string helpers and full selector execute. Authorization, allocation failures, later initialization and complete EA are excluded.'])
    save(folder/'comparison.json',report);print(json.dumps(report))


if __name__=='__main__':main()
