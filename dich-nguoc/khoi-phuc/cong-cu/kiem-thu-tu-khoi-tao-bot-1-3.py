"""Compare initialization flag changes and service order with captured code.

generate BOT | prepare|mql5 --build BUILD|original|compare BOT RUN.
Authorization results and service-side mutations are supplied only in this
isolated test. The real authorization body and its alert are not executed.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x49535131;MASK=(1<<64)-1
def module(name,path):
    s=importlib.util.spec_from_file_location(name,ROOT/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
base=module('init_order_base','cong-cu/kiem-cong-khoi-tao-bot-1-3.py');pub=base.pub;require=base.require;sha=base.sha;save=base.save
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,native_init_prefix_executed=True,
           account_call_and_tester_call_compared=True,authorization_result_supplied=True,authorization_body_executed=False,
           denied_alert_executed=False,service_mutations_supplied=True,real_network_called=False,original_ex5_changed=False)
def cases():
    rows=[r+(0,0) for r in base.cases()]
    for auth in [0,1]:
        for tester in [0,1]:
            for speed in [1,2,3]:
                for stage in [1,2,3]:
                    for field in [1,2,3,4]:
                        for value in [0,1,2,255]:rows.append((len(rows),auth,tester,speed,173,17,23,stage*10+field,value))
    return rows
def encoded(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<9i',*r) for r in rows)
SCRIPT=r'''#property strict
long MockAccount(const ENUM_ACCOUNT_INFO_INTEGER property);
long MockMqlInfo(const ENUM_MQL_INFO_INTEGER property);
#define AccountInfoInteger MockAccount
#define MQLInfoInteger MockMqlInfo
#include "../../Include/bot-cua-toi-N/BotNInitializationGate.mqh"
#undef AccountInfoInteger
#undef MQLInfoInteger
input string CheckRun="";
BotNInitializationGateState State;int Speed,Tester,Effect,EffectValue,AccountCalls,TesterCalls,Errors;
void ApplyEffect(const int stage)
{
   if(Effect/10!=stage)return;
   int field=Effect%10;
   if(field==1)State.active=(uchar)EffectValue;
   else if(field==2)State.dispatch_mode=(uchar)EffectValue;
   else if(field==3)State.m1_enabled=(uchar)EffectValue;
   else if(field==4)Speed=EffectValue;
}
long MockAccount(const ENUM_ACCOUNT_INFO_INTEGER property)
{
   if((int)property!=32 || State.active!=0 || AccountCalls!=0 || TesterCalls!=0)Errors|=1;
   AccountCalls++;ApplyEffect(1);return 0;
}
long MockMqlInfo(const ENUM_MQL_INFO_INTEGER property)
{
   if((int)property!=6 || State.active!=1 || AccountCalls!=1 || TesterCalls!=0)Errors|=2;
   TesterCalls++;ApplyEffect(3);return Tester;
}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="botN-init-sequence\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x49535131 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(file),auth=FileReadInteger(file);Tester=FileReadInteger(file);Speed=FileReadInteger(file);
      State.active=(uchar)FileReadInteger(file);State.dispatch_mode=(uchar)FileReadInteger(file);State.m1_enabled=(uchar)FileReadInteger(file);
      Effect=FileReadInteger(file);EffectValue=FileReadInteger(file);AccountCalls=0;TesterCalls=0;Errors=0;
      BotNStartInitializationGate(State);ApplyEffect(2);bool allowed=BotNFinishInitializationGate(auth!=0,Speed,State);
      FileWriteInteger(output,id);FileWriteInteger(output,(int)allowed);FileWriteInteger(output,(int)State.active);FileWriteInteger(output,(int)State.dispatch_mode);FileWriteInteger(output,(int)State.m1_enabled);FileWriteInteger(output,AccountCalls);FileWriteInteger(output,TesterCalls);FileWriteInteger(output,Errors);
   }
   if(FileTell(file)!=FileSize(file))return 5;FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
def generate(bot):
    path=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}InitializationSequenceCheck.mq5';require(not path.exists(),'SOURCE_EXISTS');path.write_text(SCRIPT.replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}'),encoding='utf-8',newline='\n');print(path)
class Native(base.Native):
    def effect(self,stage):
        if self.row[7]//10!=stage:return
        field,value=self.row[7]%10,self.row[8];name={1:'active',2:'mode',3:'m1',4:'speed'}[field];size=4 if field==4 else 1
        self.m.mem_write(self.base+self.c[name],(value&((1<<(size*8))-1)).to_bytes(size,'little'))
    def authorization_reply(self,m,address,size,user):
        require(self.events==['account'],'AUTH_CALL_ORDER');self.events.append('authorization');self.effect(2)
        x=self.x;sp=m.reg_read(x.UC_X86_REG_RSP);return_to=struct.unpack('<Q',m.mem_read(sp,8))[0];require(return_to==self.base+0xcba,'AUTH_RETURN_ADDRESS')
        m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RAX,self.row[1]);m.reg_write(x.UC_X86_REG_RIP,return_to)
    def sdk_call(self,m,address,size,user):
        x=self.x;api=self.sdk[address];require(m.reg_read(x.UC_X86_REG_RCX)==self.c['ctx'],'CONTEXT_CHANGED')
        if api=='account':require(m.reg_read(x.UC_X86_REG_RDX)==32 and self.byte('active')==0 and not self.events,'ACCOUNT_CALL_ORDER');value=0;stage=1
        else:require(m.reg_read(x.UC_X86_REG_RDX)==6 and self.byte('active')==1 and self.events==['account','authorization'],'TESTER_CALL_ORDER');value=self.row[2];stage=3
        self.events.append(api);self.effect(stage);m.reg_write(x.UC_X86_REG_RAX,value&MASK)
    def run(self,row):
        output=super().run(row);return (*output,self.events.count('account'),self.events.count('tester'),0)
def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}InitializationSequenceCheck.mq5';helpers=[Path(__file__),Path(base.__file__),ROOT/'cong-cu/kiem-cong-dieu-phoi-bot-1-3.py',ROOT/'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py']
    return dict(original_ex5_sha256=base.gate.base.validation.original_hash(bot),native_init_sha256=base.CFG[bot]['sha'],sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases();current=identity(a.bot);folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encoded(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encoded(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BUILD_REQUIRED');home=ROOT/f'bot-cua-toi-{a.bot}';mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}InitializationSequenceCheck.mq5';require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/f'MQL5/Files/bot{a.bot}-init-sequence'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('init-sequence-'+a.run+'.set');ini=mt/('init-sequence-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}InitializationSequenceCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        runner=Native(a.bot);raw=bytearray(header)
        for row in rows:raw+=struct.pack('<8i',*runner.run(row))
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    for name in ['mql5','original']:
        result=json.loads((folder/(name+'-run.json')).read_text());require(all(result[k]==v for k,v in current.items()) and result['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    left=(folder/'original-results.bin').read_bytes();right=(folder/'mql5-results.bin').read_bytes();require(left[:12]==right[:12]==header and len(left)==len(right)==12+32*len(rows),'RESULT_LAYOUT');failed=[]
    for i,row in enumerate(rows):
        x=struct.unpack_from('<8i',left,12+i*32);y=struct.unpack_from('<8i',right,12+i*32)
        if x!=y:failed.append(dict(case=i,input=row,original=x,actual=y))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:8],**SCOPE,limits=['Initialization prefix only. Authorization body and denied alert are excluded; result and service-side effects are supplied. No complete OnInit/EA or live trading.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
