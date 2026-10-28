"""Compare initialization flag changes with captured OnInit instructions.

generate BOT | prepare|mql5 --build BUILD|original|compare BOT RUN.
The authorization result is supplied only inside the isolated comparison;
the real EX5 and its authorization checks are never modified or invoked.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x49475431;MASK=(1<<64)-1
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,ROOT/path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
gate=module('init_gate_native','cong-cu/kiem-cong-dieu-phoi-bot-1-3.py');pub=gate.pub;require=gate.require;sha=gate.sha;save=gate.save
CFG={1:dict(auth=0x5880,end=0x587a,active=0x67470,mode=0x621e0,m1=0x621c9,speed=0x6a558,ctx=0x23e575eae78,sha='c92ebab3485312da42f4d2e83d9c0be8614f65d3784e2551825eb741cc220fe8'),
     3:dict(auth=0x61a0,end=0x6196,active=0x744b0,mode=0x6d1e8,m1=0x6d1d0,speed=0x1d6f68,ctx=0x171514ca538,sha='642bcd6f0ed0711c9be71a4d73efe9772b2a2b09a53eb9dfdfa86f5ba2bd6356')}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
           native_init_prefix_executed=True,authorization_result_supplied=True,
           authorization_function_executed=False,real_network_called=False,
           services_and_active_before_authorization_compared=False,original_ex5_changed=False)
def cases():
    out=[]
    for authorized in [0,1]:
        for tester in [-1,0,1,2]:
            for speed in [-2147483648,-1,0,1,2,3,4,2147483647]:
                for prior_mode in [0,1,2,255]:
                    for prior_m1 in [0,1,2,255]:
                        out.append((len(out),authorized,tester,speed,173,prior_mode,prior_m1))
    return out
def encoded(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<7i',*r) for r in rows)
SCRIPT=r'''#property strict
#include "../../Include/bot-cua-toi-N/BotNInitializationGate.mqh"
input string CheckRun="";
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="botN-init-gate\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);
   if(magic!=0x49475431 || version!=1 || count<1)return 3;
   int result=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(result==INVALID_HANDLE)return 4;
   FileWriteInteger(result,magic);FileWriteInteger(result,version);FileWriteInteger(result,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(file),auth=FileReadInteger(file),tester=FileReadInteger(file),speed=FileReadInteger(file);
      BotNInitializationGateState state;state.active=(uchar)FileReadInteger(file);state.dispatch_mode=(uchar)FileReadInteger(file);state.m1_enabled=(uchar)FileReadInteger(file);
      bool allowed=BotNInitializeGate(auth!=0,tester,speed,state);
      FileWriteInteger(result,id);FileWriteInteger(result,(int)allowed);FileWriteInteger(result,(int)state.active);FileWriteInteger(result,(int)state.dispatch_mode);FileWriteInteger(result,(int)state.m1_enabled);
   }
   if(FileTell(file)!=FileSize(file))return 5;FileClose(file);FileClose(result);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
def generate(bot):
    path=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}InitializationGateCheck.mq5'
    require(not path.exists(),'SOURCE_EXISTS');path.write_text(SCRIPT.replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}'),encoding='utf-8',newline='\n');print(path)
class Native(gate.base.entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.c=CFG[bot];self.bot=bot;c=self.c
        raw=bytes(self.m.mem_read(self.base+0xc30,c['end']-0xc30));require(hashlib.sha256(raw).hexdigest()==c['sha'],'INIT_FUNCTION_CHANGED')
        self.sdk={0x7ff683f20000+0x7973c0:'account',0x7ff683f20000+0x7c0fd0:'tester'}
        for a in self.sdk:
            require(a not in self.apis,'SDK_HOOK_ALREADY_REGISTERED')
            if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
            self.m.mem_write(a,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.sdk_call,begin=a,end=a)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.authorization_reply,begin=self.base+c['auth'],end=self.base+c['auth'])
        for rva in [0xd05,0xd60]:self.m.hook_add(self.uc.UC_HOOK_CODE,self.stop,begin=self.base+rva,end=self.base+rva)
    def byte(self,name):return self.m.mem_read(self.base+self.c[name],1)[0]
    def authorization_reply(self,m,address,size,user):
        # Return one supplied authorization result to the caller in this
        # isolated test. The original EX5, its bytes and real state stay intact.
        require(self.byte('active')==0 and self.events==['account'],'AUTH_CALLED_IN_WRONG_STATE');self.events.append('authorization')
        x=self.x;sp=m.reg_read(x.UC_X86_REG_RSP);return_to=struct.unpack('<Q',m.mem_read(sp,8))[0]
        require(return_to==self.base+0xcba,'AUTH_RETURN_ADDRESS');m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RAX,self.row[1]);m.reg_write(x.UC_X86_REG_RIP,return_to)
    def sdk_call(self,m,address,size,user):
        x=self.x;api=self.sdk[address];require(m.reg_read(x.UC_X86_REG_RCX)==self.c['ctx'],'CONTEXT_CHANGED')
        if api=='account':require(m.reg_read(x.UC_X86_REG_RDX)==32 and self.byte('active')==0 and not self.events,'ACCOUNT_CALL_ORDER');value=0
        else:require(m.reg_read(x.UC_X86_REG_RDX)==6 and self.byte('active')==1 and self.events==['account','authorization'],'TESTER_CALL_ORDER');value=self.row[2]
        self.events.append(api);m.reg_write(x.UC_X86_REG_RAX,value&MASK)
    def stop(self,m,address,size,user):self.allowed=address==self.base+0xd60;self.done=True;m.emu_stop()
    def run(self,row):
        self.row=row;self.done=False;self.events=[];m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name,value in [('active',row[4]),('mode',row[5]),('m1',row[6])]:m.mem_write(self.base+self.c[name],bytes([value]))
        m.mem_write(self.base+self.c['speed'],struct.pack('<i',row[3]))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_RSP,0x5001fef8);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.emu_start(self.base+0xc30,0x60000000,timeout=1000000,count=10000)
        require(self.done and self.events==(['account','authorization','tester'] if row[1] else ['account','authorization']),'INIT_PREFIX_NOT_FINISHED')
        return (row[0],int(self.allowed),self.byte('active'),self.byte('mode'),self.byte('m1'))
def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}InitializationGateCheck.mq5';helpers=[Path(__file__),Path(gate.__file__),ROOT/'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py']
    return dict(original_ex5_sha256=gate.base.validation.original_hash(bot),native_init_sha256=CFG[bot]['sha'],sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases();current=identity(a.bot);folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encoded(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encoded(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        home=ROOT/f'bot-cua-toi-{a.bot}';mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}InitializationGateCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/f'MQL5/Files/bot{a.bot}-init-gate'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('init-gate-'+a.run+'.set');ini=mt/('init-gate-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}InitializationGateCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        runner=Native(a.bot);raw=bytearray(header)
        for row in rows:raw+=struct.pack('<5i',*runner.run(row))
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    for name in ['mql5','original']:
        result=json.loads((folder/(name+'-run.json')).read_text());require(all(result[k]==v for k,v in current.items()) and result['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    left=(folder/'original-results.bin').read_bytes();right=(folder/'mql5-results.bin').read_bytes();require(left[:12]==right[:12]==header and len(left)==len(right)==12+20*len(rows),'RESULT_LAYOUT');failed=[];old_mismatches=0
    for i,row in enumerate(rows):
        original=struct.unpack_from('<5i',left,12+i*20);actual=struct.unpack_from('<5i',right,12+i*20)
        if original!=actual:failed.append(dict(case=i,input=row,original=original,actual=actual))
        if row[1] and row[2]==1 and row[3] not in [2,3] and row[6]!=1 and original[4]!=1:old_mismatches+=1
    require(old_mismatches>0,'PRIOR_DEFECT_NOT_COVERED');report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:8],prior_wrong_m1_cases=old_mismatches,**SCOPE,limits=['Initial-state changes only; account and authorization calls in OnInit are supplied, actual authorization body and denied-branch alert are excluded. No full OnInit/EA or live trading.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
