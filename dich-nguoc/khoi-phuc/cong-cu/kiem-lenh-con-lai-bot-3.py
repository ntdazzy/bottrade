"""Compare the complete native sixteen-byte strategy-presence scan with MQL5.

generate | prepare|mql5 --build BUILD|original|compare RUN.
All six terminal services are supplied; every call, reply, seed and all twenty
observed bytes are compared directly. Only the first sixteen are cleared.
"""
import argparse
import importlib.util
import json
import random
import re
import shutil
import struct
import subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x50523331;MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('presence_hour',ROOT/'cong-cu/kiem-gio-chien-luoc-bot-1-3.py')
hour=importlib.util.module_from_spec(spec);spec.loader.exec_module(hour)
require,sha,save,pub=hour.require,hour.sha,hour.save,hour.pub
SCOPE=dict(full_ea=False,native_presence_scan_executed=True,terminal_replies_supplied=True,
           full_call_order_and_flag_states_compared=True,original_ex5_changed=False)


def signed(value):return (value+(1<<63))%(1<<64)-(1<<63)


def cases():
    out=[]
    def add(seed=42,positions=(),orders=(),effects=(),pos_total=None,ord_total=None):
        out.append(dict(id=len(out),seed=seed,positions=list(positions),orders=list(orders),effects=list(effects),
                        pos_total=len(positions) if pos_total is None else pos_total,
                        ord_total=len(orders) if ord_total is None else ord_total,
                        initial=[(len(out)+17*i)%256 for i in range(20)]))
    for seed in [-2147483648,-1,0,42,2147483647]:
        for offset in [-2,-1,0,1,2,7,8,14,15,16,17,1<<32,-(1<<32)]:
            magic=signed(seed+offset)
            for ticket in [0,101]:add(seed,[(ticket,magic)],[(ticket+1 if ticket else 0,magic)])
        add(seed,[(i+1,seed+i+1) for i in range(15)],[(i+100,seed+i+1) for i in range(15)])
    for p in [-1,0,1,2]:
        for o in [-1,0,1,2]:add(positions=[(1,43),(2,44)],orders=[(3,45),(4,46)],pos_total=p,ord_total=o)
    for api in range(1,7):
        for n in [1,2]:
            for value in [-2147483648,-1,0,42,900,2147483647]:
                add(positions=[(1,43),(2,44),(3,901)],orders=[(4,43),(5,44),(6,901)],effects=[(api,n,-1,value)])
            for index in range(20):
                add(positions=[(1,43),(2,44)],orders=[(3,45),(4,46)],effects=[(api,n,index,255)])
    rng=random.Random(2026102871)
    for _ in range(80):
        seed=rng.choice([-2147483648,-1,0,42,2147483647])
        def trades():return [(0 if rng.randrange(5)==0 else i+1,signed(seed+rng.choice([-1,0,1,2,8,15,16,1<<32]))) for i in range(rng.randrange(9))]
        effects=[(rng.randrange(1,7),rng.randrange(1,4),rng.randrange(-1,20),rng.randrange(256))] if rng.randrange(2) else []
        add(seed,trades(),trades(),effects)
    return out


def encoded(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<4i20i',c['id'],c['seed'],c['pos_total'],c['ord_total'],*c['initial'])
        for key in ['positions','orders']:
            raw+=struct.pack('<i',len(c[key]))
            for ticket,magic in c[key]:raw+=struct.pack('<Qq',ticket,magic)
        raw+=struct.pack('<i',len(c['effects']))
        for e in c['effects']:raw+=struct.pack('<4i',*e)
    return bytes(raw)


SCRIPT=r'''#property strict
input string CheckRun="";
int PresenceSeed,PresencePositionTotal,PresenceOrderTotal,PresencePositionCount,PresenceOrderCount;
ulong PresencePositionTickets[32],PresenceOrderTickets[32];long PresencePositionMagic[32],PresenceOrderMagic[32];
uchar PresenceFlags[20];int PresenceCounts[7],PresenceEffects[128][4],PresenceEffectCount,PresenceSelectedPosition,PresenceSelectedOrder,PresenceOutput;
void PresenceRecord(const int api,const int argument,const ulong reply)
{
   FileWriteInteger(PresenceOutput,api);FileWriteInteger(PresenceOutput,argument);FileWriteLong(PresenceOutput,(long)reply);
   FileWriteInteger(PresenceOutput,PresenceSeed);for(int i=0;i<20;i++)FileWriteInteger(PresenceOutput,(int)PresenceFlags[i]);
   int n=++PresenceCounts[api];
   for(int i=0;i<PresenceEffectCount;i++)
   {
      if(PresenceEffects[i][0]!=api || PresenceEffects[i][1]!=n)continue;
      int field=PresenceEffects[i][2],value=PresenceEffects[i][3];
      if(field==-1)PresenceSeed=value;else PresenceFlags[field]=(uchar)value;
   }
}
int MockPositions(){PresenceRecord(1,0,(ulong)(long)PresencePositionTotal);return PresencePositionTotal;}
ulong MockPositionTicket(const int index)
{
   PresenceSelectedPosition=index;ulong value=index>=0 && index<PresencePositionCount ? PresencePositionTickets[index] : 0;
   PresenceRecord(2,index,value);return value;
}
long MockPositionInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   long value=PresencePositionMagic[PresenceSelectedPosition];PresenceRecord(3,(int)property,(ulong)value);return value;
}
int MockOrders(){PresenceRecord(4,0,(ulong)(long)PresenceOrderTotal);return PresenceOrderTotal;}
ulong MockOrderTicket(const int index)
{
   PresenceSelectedOrder=index;ulong value=index>=0 && index<PresenceOrderCount ? PresenceOrderTickets[index] : 0;
   PresenceRecord(5,index,value);return value;
}
long MockOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property)
{
   long value=PresenceOrderMagic[PresenceSelectedOrder];PresenceRecord(6,(int)property,(ulong)value);return value;
}
#define PositionsTotal MockPositions
#define PositionGetTicket MockPositionTicket
#define PositionGetInteger MockPositionInteger
#define OrdersTotal MockOrders
#define OrderGetTicket MockOrderTicket
#define OrderGetInteger MockOrderInteger
#include "../../Include/bot-cua-toi-3/Bot3StrategyPresence.mqh"
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef OrdersTotal
#undef OrderGetTicket
#undef OrderGetInteger
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-strategy-presence\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x50523331 || version!=1 || count<1)return 3;
   PresenceOutput=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(PresenceOutput==INVALID_HANDLE)return 4;
   FileWriteInteger(PresenceOutput,magic);FileWriteInteger(PresenceOutput,version);FileWriteInteger(PresenceOutput,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);PresenceSeed=FileReadInteger(file);PresencePositionTotal=FileReadInteger(file);PresenceOrderTotal=FileReadInteger(file);
      for(int i=0;i<20;i++)PresenceFlags[i]=(uchar)FileReadInteger(file);
      PresencePositionCount=FileReadInteger(file);if(PresencePositionCount<0 || PresencePositionCount>32)return 5;
      for(int i=0;i<PresencePositionCount;i++){PresencePositionTickets[i]=(ulong)FileReadLong(file);PresencePositionMagic[i]=FileReadLong(file);}
      PresenceOrderCount=FileReadInteger(file);if(PresenceOrderCount<0 || PresenceOrderCount>32)return 5;
      for(int i=0;i<PresenceOrderCount;i++){PresenceOrderTickets[i]=(ulong)FileReadLong(file);PresenceOrderMagic[i]=FileReadLong(file);}
      PresenceEffectCount=FileReadInteger(file);if(PresenceEffectCount<0 || PresenceEffectCount>128)return 5;
      for(int i=0;i<PresenceEffectCount;i++)for(int j=0;j<4;j++)PresenceEffects[i][j]=FileReadInteger(file);
      ArrayInitialize(PresenceCounts,0);PresenceSelectedPosition=-1;PresenceSelectedOrder=-1;
      FileWriteInteger(PresenceOutput,id);ulong length_at=FileTell(PresenceOutput);FileWriteInteger(PresenceOutput,0);ulong begin=FileTell(PresenceOutput);
      Bot3CollectStrategyPresence(PresenceSeed,PresenceFlags);
      FileWriteInteger(PresenceOutput,0);FileWriteInteger(PresenceOutput,PresenceSeed);
      for(int i=0;i<20;i++)FileWriteInteger(PresenceOutput,(int)PresenceFlags[i]);
      for(int i=1;i<=6;i++)FileWriteInteger(PresenceOutput,PresenceCounts[i]);
      ulong end=FileTell(PresenceOutput);FileSeek(PresenceOutput,(long)length_at,SEEK_SET);FileWriteInteger(PresenceOutput,(int)(end-begin));FileSeek(PresenceOutput,(long)end,SEEK_SET);
   }
   if(FileTell(file)!=FileSize(file))return 6;
   FileClose(file);FileClose(PresenceOutput);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''


def generate():
    path=ROOT/'bot-cua-toi-3/source/MQL5/Scripts/bot-cua-toi-3/Bot3StrategyPresenceCheck.mq5'
    require(not path.exists(),'SOURCE_EXISTS');path.write_text(SCRIPT,encoding='utf-8',newline='\n');print(path)


class Native(hour.parent.Original):
    def __init__(self):
        super().__init__(3)
        self.sdk={0x7ff683f20000+offset:api for api,offset in enumerate([0x7d7da0,0x7d7df0,0x7d7fc0,0x7d81a0,0x7d81f0,0x7d8310],1)}
        for addr in self.sdk:
            existed=addr in self.apis
            if not any(lo<=addr<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(addr&~4095,4096)
            self.m.mem_write(addr,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)

    def seed(self):return struct.unpack('<i',self.m.mem_read(self.base+0x1d6ff0,4))[0]

    def call(self,m,address,size,user):
        require(address in self.sdk,'UNEXPECTED_SERVICE');api=self.sdk[address];x=self.x
        require(m.reg_read(x.UC_X86_REG_RCX)==self.gate['ctx'],'BAD_CONTEXT')
        argument=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
        if api in [1,4]:argument=0;reply=self.row['pos_total' if api==1 else 'ord_total']
        elif api in [2,5]:
            require(argument<32,'TICKET_INDEX_OUTSIDE_FIXTURE');self.selected[api]=argument;items=self.row['positions' if api==2 else 'orders'];reply=items[argument][0] if argument<len(items) else 0
        else:
            require(argument==(12 if api==3 else 15),'WRONG_PROPERTY');items=self.row['positions' if api==3 else 'orders'];selected=self.selected[2 if api==3 else 5]
            require(0<=selected<len(items),'MISSING_SELECTED_TICKET');reply=items[selected][1]
        flags=list(m.mem_read(self.base+0x1d6cf8,20))
        self.trace+=struct.pack('<2iQi20i',api,argument,reply&MASK,self.seed(),*flags)
        self.counts[api]+=1
        for a,n,field,value in self.row['effects']:
            if a!=api or n!=self.counts[api]:continue
            if field==-1:m.mem_write(self.base+0x1d6ff0,struct.pack('<i',value))
            else:m.mem_write(self.base+0x1d6cf8+field,bytes([value&255]))
        m.reg_write(x.UC_X86_REG_RAX,reply&MASK)

    def run(self,row):
        self.row,self.trace,self.counts,self.selected=row,bytearray(),[0]*7,{2:-1,5:-1};m,x=self.m,self.x
        m.mem_write(self.base+0x1d6ff0,struct.pack('<i',row['seed']));m.mem_write(self.base+0x1d6cf8,bytes(row['initial']))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        m.reg_write(x.UC_X86_REG_RSP,0x5001fe00);m.reg_write(x.UC_X86_REG_EFLAGS,0x202)
        m.emu_start(self.base+0x1a68e,self.base+0x1a7c3,timeout=1000000,count=100000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+0x1a7c3,'PRESENCE_SCAN_NOT_FINISHED')
        self.trace+=struct.pack('<2i20i6i',0,self.seed(),*list(m.mem_read(self.base+0x1d6cf8,20)),*self.counts[1:])
        return bytes(self.trace)


def identity():
    source=ROOT/'bot-cua-toi-3/source/MQL5';script=source/'Scripts/bot-cua-toi-3/Bot3StrategyPresenceCheck.mq5'
    helpers=[Path(__file__),Path(hour.__file__),Path(hour.parent.__file__),ROOT/'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py']
    return dict(original_ex5_sha256=hour.parent.base.validation.original_hash(3),native_outer_sha256=hour.parent.CFG[3]['sha'],
                sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})


def records(raw,count):
    require(raw[:12]==struct.pack('<3i',MAGIC,1,count),'RESULT_HEADER');offset=12;result=[]
    for i in range(count):
        index,size=struct.unpack_from('<2i',raw,offset);offset+=8;require(index==i and 112<=size<=len(raw)-offset,'RESULT_RECORD')
        result.append(raw[offset:offset+size]);offset+=size
    require(offset==len(raw),'TRAILING_RESULT');return result


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate();return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN')
    rows,current=cases(),identity();home=ROOT/'bot-cua-toi-3';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encoded(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encoded(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BUILD_REQUIRED')
        mt=ROOT.parent/'.local/mt5-bot3-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script='Scripts/bot-cua-toi-3/Bot3StrategyPresenceCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/'MQL5/Files/bot3-strategy-presence'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('strategy-presence-'+a.run+'.set');ini=mt/('strategy-presence-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3StrategyPresenceCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as out:out.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        native=Native();raw=bytearray(header);calls=0
        for row in rows:
            result=native.run(row);raw+=struct.pack('<2i',row['id'],len(result))+result;calls+=sum(native.counts)
        with (folder/'original-results.bin').open('xb') as out:out.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),terminal_calls=calls,result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),terminal_calls=calls)));return
    for name in ['original','mql5']:
        report=json.loads((folder/(name+'-run.json')).read_text());require(all(report[k]==v for k,v in current.items()) and report['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    original,actual=[records((folder/(name+'-results.bin')).read_bytes(),len(rows)) for name in ['original','mql5']];failed=[]
    for i,(x,y) in enumerate(zip(original,actual)):
        if x!=y:failed.append(dict(case=i,input=rows[i],first_difference=next((j for j,(a,b) in enumerate(zip(x,y)) if a!=b),None),original_size=len(x),actual_size=len(y)))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:8],**SCOPE,
                limits=['The complete presence scan only. Terminal replies and mutations supplied; counts are bounded fixtures, invalid huge counts and arrays shorter than sixteen are excluded. Full EA and real account are not tested.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))


if __name__=='__main__':main()
