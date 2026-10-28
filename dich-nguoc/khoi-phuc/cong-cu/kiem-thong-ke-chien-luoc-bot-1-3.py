"""Compare each native post-evaluation statistics block with MQL5.

generate BOT; prepare|mql5 --build BUILD|original|compare BOT RUN.
The history function's result and count mutation are supplied at its boundary.
This does not run a complete strategy, dispatcher, or EA.
"""
import argparse
import importlib.util
import json
import re
import shutil
import struct
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MASK = (1 << 64) - 1
MAGIC = 0x53544132
spec = importlib.util.spec_from_file_location('statistics_hour', ROOT / 'cong-cu/kiem-gio-chien-luoc-bot-1-3.py')
hour = importlib.util.module_from_spec(spec)
spec.loader.exec_module(hour)
require, sha, save, pub = hour.require, hour.sha, hour.save, hour.pub
CFG = {
    1: dict(starts=[0x12f51,0x13868,0x14089,0x1478d,0x14eae,0x157ba,0x15e9a,0x166dc],
            ends=[0x12fb9,0x138bc,0x140f1,0x147e1,0x14f16,0x1580e,0x15eee,0x16730],
            counts=0x67940,totals=0x69f80,average=0x67ad0,current=0x678f4,history=0x1efa0),
    3: dict(starts=[0x1b012,0x1c15c,0x1ca00,0x1b8c6,0x1daf5,0x1d281,0x1ec16,0x1f4ab,0x1e373],
            ends=[0x1b068,0x1c1b2,0x1ca56,0x1b91c,0x1db4b,0x1d2d7,0x1ec6c,0x1f501,0x1e3c9],
            counts=0x74980,totals=0x76fc0,average=0x74b10,current=0x74934,history=0x2a1c0),
}
SCOPE = dict(full_ea=False,full_history_body=False,native_statistics_blocks=True,
             history_return_supplied=True,history_count_mutation_supplied=True,original_ex5_changed=False)


def bit(value):
    return struct.unpack('<Q', struct.pack('<d', value))[0]


def cases(bot):
    n = len(CFG[bot]['starts'])
    amounts = [bit(0.0),bit(-0.0),bit(1.0),bit(-1.0),bit(123.5),bit(-123.5),
               bit(float('inf')),bit(float('-inf')),0x7ff8000000000041,0xfff8000000000042,
               0x7ff0000000000043,0xfff0000000000044]
    result = []
    for changed in [0,1]:
        for caller in range(n):
            for current in [caller,(caller+1)%n]:
                for amount in amounts:
                    for count in [-1,0,1,2,2147483647]:
                        new_count = count if current==caller else 3
                        result.append((len(result),changed,caller,current,amount,count,new_count))
    return result


def encoded(rows):
    return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<4iQ2i',*row) for row in rows)


SCRIPT = r'''#property strict
input string CheckRun="";
union Number { double value;ulong word; };
ulong ReplyBits;int ReplyCount,Calls,CalledIndex;
#include "../../Include/bot-cua-toi-N/BotNStrategyHistory.mqh"
double MockClosed(const uchar &show_tester,const string &symbol,const int &magic,const uint &current,
                  int &closed[],BotNStrategyHistoryCache &cache)
{
   Calls++;CalledIndex=(int)current;closed[current]=ReplyCount;
   Number value;value.word=ReplyBits;return value.value;
}
#define BotNStrategyClosedProfit MockClosed
#include "../../Include/bot-cua-toi-N/BotNStrategyStatistics.mqh"
#undef BotNStrategyClosedProfit
int OnStart()
{
   if(CheckRun=="")return 1;
   string folder="botN-strategy-statistics\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x53544132 || version!=1 || count<1)return 3;
   int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(out==INVALID_HANDLE)return 4;
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(file),changed=FileReadInteger(file),caller=FileReadInteger(file),current=FileReadInteger(file);
      ReplyBits=(ulong)FileReadLong(file);int initial_count=FileReadInteger(file);ReplyCount=FileReadInteger(file);
      int closed[ROWS];double total[ROWS],average[ROWS];
      for(int j=0;j<ROWS;j++){closed[j]=10+j;total[j]=10.25+(double)j;average[j]=-300.5-(double)j;}
      closed[caller]=initial_count;Calls=0;CalledIndex=-1;
      uchar show=1;string symbol="XAUUSD";int owner=9001;uint current_index=(uint)current;
      BotNStrategyHistoryCache cache;
      BotNUpdateStrategyStatistics(changed!=0,(uint)caller,show,symbol,owner,current_index,closed,cache,total,average);
      FileWriteInteger(out,id);FileWriteInteger(out,Calls);FileWriteInteger(out,CalledIndex);
      for(int j=0;j<ROWS;j++)FileWriteInteger(out,closed[j]);
      for(int j=0;j<ROWS;j++){Number x;x.value=total[j];FileWriteLong(out,(long)x.word);}
      for(int j=0;j<ROWS;j++){Number x;x.value=average[j];FileWriteLong(out,(long)x.word);}
   }
   if(FileTell(file)!=FileSize(file))return 5;
   FileClose(file);FileClose(out);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''


def generate(bot):
    path = ROOT / f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyStatisticsCheck.mq5'
    code = SCRIPT.replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}').replace('ROWS',str(len(CFG[bot]['starts'])))
    path.write_text(code,encoding='utf-8',newline='\n')
    print(path)


class Native(hour.parent.Original):
    def __init__(self,bot):
        super().__init__(bot)
        self.bot,self.c,self.n=bot,CFG[bot],len(CFG[bot]['starts'])
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.history,begin=self.base+self.c['history'],end=self.base+self.c['history'])

    def history(self,m,address,size,user):
        x=self.x
        current=struct.unpack('<I',m.mem_read(self.base+self.c['current'],4))[0]
        require(current==self.row[3] and not self.calls,'BAD_HISTORY_CALL')
        self.calls+=1;self.called_index=current
        m.mem_write(self.base+self.c['counts']+4*current,struct.pack('<i',self.row[6]))
        m.reg_write(x.UC_X86_REG_XMM0,self.row[4])
        sp=m.reg_read(x.UC_X86_REG_RSP);return_to=struct.unpack('<Q',m.mem_read(sp,8))[0]
        require(self.base+self.start<return_to<self.base+self.end,'BAD_HISTORY_RETURN')
        m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,return_to)

    def run(self,row):
        self.row,self.calls,self.called_index=row,0,-1
        _,changed,caller,current,_,count,_=row
        self.start,self.end=self.c['starts'][caller],self.c['ends'][caller]
        m,x=self.m,self.x
        counts=[10+i for i in range(self.n)];counts[caller]=count
        m.mem_write(self.base+self.c['current'],struct.pack('<I',current))
        m.mem_write(self.base+self.c['counts'],struct.pack('<'+'i'*self.n,*counts))
        m.mem_write(self.base+self.c['totals'],struct.pack('<'+'d'*self.n,*(10.25+i for i in range(self.n))))
        m.mem_write(self.base+self.c['average'],struct.pack('<'+'d'*self.n,*(-300.5-i for i in range(self.n))))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        sp=0x5001fe00;m.mem_write(sp,bytes(0x100));m.reg_write(x.UC_X86_REG_RSP,sp)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.reg_write(x.UC_X86_REG_RSI,changed)
        m.emu_start(self.base+self.start,self.base+self.end,timeout=1000000,count=10000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+self.end,'STATISTICS_BLOCK_DID_NOT_FINISH')
        return (struct.pack('<3i',row[0],self.calls,self.called_index)+
                bytes(m.mem_read(self.base+self.c['counts'],4*self.n))+
                bytes(m.mem_read(self.base+self.c['totals'],8*self.n))+
                bytes(m.mem_read(self.base+self.c['average'],8*self.n)))


def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5'
    script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}StrategyStatisticsCheck.mq5'
    helpers=[Path(__file__),Path(hour.__file__),Path(hour.parent.__file__),
             ROOT/'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py']
    return dict(original_ex5_sha256=hour.parent.base.validation.original_hash(bot),native_outer_sha256=hour.parent.CFG[bot]['sha'],
                sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},
                helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('mode',choices=['generate','prepare','mql5','original','compare'])
    p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN')
    rows,current=cases(a.bot),identity(a.bot);home=ROOT/f'bot-cua-toi-{a.bot}'
    folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encoded(rows))
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE))
        print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text())
    require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encoded(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BUILD_REQUIRED')
        mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json'
        build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}StrategyStatisticsCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        def unchanged():
            for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
            binary=mt/'MQL5'/Path(script).with_suffix('.ex5')
            require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        unchanged();files=mt/f'MQL5/Files/bot{a.bot}-strategy-statistics'/a.run;files.mkdir(parents=True,exist_ok=False)
        shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('strategy-statistics-'+a.run+'.set');ini=mt/('strategy-statistics-'+a.run+'.ini')
        preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-to-{a.bot}\\Bot{a.bot}StrategyStatisticsCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n'.replace('bot-cua-to-','bot-cua-toi-'),encoding='utf-16')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED');unchanged()
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as out:out.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE))
        print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        native=Native(a.bot);raw=bytearray(header);calls=0
        for row in rows:raw+=native.run(row);calls+=native.calls
        with (folder/'original-results.bin').open('xb') as out:out.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),calls=calls,result_sha256=sha(folder/'original-results.bin'),**SCOPE))
        print(json.dumps(dict(cases=len(rows),calls=calls)));return
    for name in ['original','mql5']:
        report=json.loads((folder/(name+'-run.json')).read_text())
        require(all(report[k]==v for k,v in current.items()) and report['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    original,actual=[(folder/(name+'-results.bin')).read_bytes() for name in ['original','mql5']]
    n=len(CFG[a.bot]['starts']);size=12+20*n
    require(original[:12]==actual[:12]==header and len(original)==len(actual)==12+size*len(rows),'RESULT_LAYOUT')
    failed=[]
    for i,row in enumerate(rows):
        x=original[12+i*size:12+(i+1)*size];y=actual[12+i*size:12+(i+1)*size]
        if x!=y:failed.append(dict(case=i,input=row,original=x.hex(),actual=y.hex()))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:8],**SCOPE,
                limits=['Post-evaluation statistics blocks only. History result and count mutation supplied; full history body tested separately.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))


if __name__=='__main__':main()
