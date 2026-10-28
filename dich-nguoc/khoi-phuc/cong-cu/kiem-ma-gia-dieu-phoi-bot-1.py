"""Compare the dispatcher chart-symbol routing and working-symbol assignment.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Starts after the authorization and daily-loss portions. Stops before virtual
table cleanup, strategy loading or direct evaluation; no permission is supplied.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x53594d31;BASE=0x23e5aa10000
s=importlib.util.spec_from_file_location('symbol_route_boot',ROOT/'cong-cu/kiem-ngu-canh-khoi-dong-bot-1.py');boot=importlib.util.module_from_spec(s);s.loader.exec_module(boot)
require,sha,save,pub=boot.require,boot.sha,boot.save,boot.pub
PATTERNS=['XAUUSD','xauusd','GOLD','gold','Gold','XAU','xau','XAG','xag','GC','gc']
OUTER_SHA='f5edd0f5e9033ddddb289a3419406c06292ce22bff197bea6d10acea1756c721'
SCOPE=dict(full_ea=False,whole_bot_complete=False,whole_manager_complete=False,native_symbol_routing_executed=True,
 native_string_searches_executed=True,native_string_copy_executed=True,authorization_executed=False,
 authorization_entry_guarded=True,allocation_success_supplied=True,direct_evaluator_executed=False,strategy_loop_executed=False)

def cases():
    rows=[]
    def add(symbol,error=0):rows.append(dict(id=len(rows),symbol=symbol,working='old working 🚀',error=error))
    for symbol in [None,'','EURUSD','SILVER','GC','gc','xag','XAG','XaUuSd','GoLd','abc','x','g','G','xagGC','prefixGConly']:
        for error in [0,65536+731]:add(symbol,error)
    for word in PATTERNS:
        for prefix,suffix in [('', ''),('m.',''),('', '.a'),('Vàng🚀','試'),('not-', '-symbol')]:add(prefix+word+suffix)
    for word in ['xaG','Xag','gC','Gc','Gold','gold','GOLD']:
        for suffix in ['',' ']:add(word+suffix)
    for n in [1,2,7,31,260]:
        for word in ['XAG','GC','gc','USD']:add('a'*n+word+'z'*n)
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for row in rows:raw+=struct.pack('<iI',row['id'],row['error'])+boot.text(row['symbol'])+boot.text(row['working'])
    return bytes(raw)

SCRIPT=r'''#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1TickSymbolRouting.mqh"
string ReadText(const int h){int n=FileReadInteger(h);return n<0 ? NULL : (n==0 ? "" : FileReadString(h,n));}
void Text(const int h,const string value){int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(h,n);if(n>0)FileWriteString(h,value,n);}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-tick-symbol\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x53594d31 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(file);uint error=(uint)FileReadInteger(file);string chart_name=ReadText(file),working=ReadText(file);
      ResetLastError();if(error!=0)SetUserError((ushort)(error-65536));
      bool configured=Bot1PrepareTickSymbol(chart_name,working);uint final_error=GetLastError();
      FileWriteInteger(output,id);FileWriteInteger(output,(int)configured);FileWriteInteger(output,(int)final_error);Text(output,chart_name);Text(output,working);
   }
   if(FileTell(file)!=FileSize(file))return 5;FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''

class Native(boot.Native):
    def __init__(self):
        super().__init__();m=self.m
        require(hashlib.sha256(bytes(m.mem_read(self.base+0x10f60,0x173e4-0x10f60))).hexdigest()==OUTER_SHA,'DISPATCHER_CHANGED')
        for index,expected in enumerate(PATTERNS):
            at=self.base+0x529fc+index*0x20;n=struct.unpack('<I',m.mem_read(at-4,4))[0]
            require(bytes(m.mem_read(at,2*n)).decode('utf-16-le')==expected,'SYMBOL_LITERAL_CHANGED')
        for at in [0x12004,0x12409]:m.hook_add(self.uc.UC_HOOK_CODE,self.stop_route,begin=self.base+at,end=self.base+at)
        for at in [0xc30,0x5880,0x3d6c0,0x4d260]:m.hook_add(self.uc.UC_HOOK_CODE,self.protected,begin=self.base+at,end=self.base+at)
    def protected(self,m,address,size,user):raise RuntimeError('AUTHORIZATION_OUTSIDE_SYMBOL_SCOPE')
    def stop_route(self,m,address,size,user):self.route=int(address==self.base+0x12409);m.emu_stop()
    def run(self,row):
        self.case=row;self.route=-1;self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        self.put_text(0x6a428,row['symbol']);self.put_text(0x67918,row['working']);m.mem_write(self.base+0x6a410,struct.pack('<I',row['error']))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        sp=0x5001fc00;m.mem_write(sp,bytes(0x300));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.emu_start(self.base+0x11f3f,self.base+0x12424,timeout=3000000,count=1000000)
        require(self.route in [0,1],'SYMBOL_ROUTE_NOT_FINISHED')
        err=struct.unpack('<I',m.mem_read(self.base+0x6a410,4))[0]
        return struct.pack('<2iI',row['id'],self.route,err)+boot.text(self.read_text(self.base+0x6a428))+boot.text(self.read_text(self.base+0x67918))

def identity():
    src=ROOT/'bot-cua-toi-1/source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1TickSymbolRoutingCheck.mq5'
    helpers=[Path(__file__),Path(boot.__file__),Path(boot.base.__file__),Path(boot.history.__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py']
    return dict(original_ex5_sha256=boot.base.base.validation.original_hash(1),native_outer_sha256=OUTER_SHA,
      sources_sha256={p.relative_to(src).as_posix():sha(p) for p in pub.closure(script,src)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':
        path=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1TickSymbolRoutingCheck.mq5';require(not path.exists(),'SOURCE_EXISTS');path.write_text(SCRIPT,encoding='utf-8',newline='\n');print(path);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases();current=identity();folder=ROOT/'bot-cua-toi-1/bang-chung/kiem-quan-ly-vi-the'/a.run;head=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    before=json.loads((folder/'baseline.json').read_text());require(all(before[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,64}',a.build),'BUILD_REQUIRED');mt=ROOT.parent/'.local/mt5-bot1-thread-20261025';receipt=ROOT/'bot-cua-toi-1/bang-chung/bien-dich'/a.build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script='Scripts/bot-cua-toi-1/Bot1TickSymbolRoutingCheck.mq5'
        require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/'MQL5/Files/bot1-tick-symbol'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('tick-symbol-'+a.run+'.set');ini=mt/('tick-symbol-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1TickSymbolRoutingCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        o=Native();raw=bytearray(head)
        try:
            for row in rows:raw+=o.run(row)
        finally:o.close()
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    for n in ['original','mql5']:
        record=json.loads((folder/(n+'-run.json')).read_text());require(all(record[k]==v for k,v in current.items()) and record['result_sha256']==sha(folder/(n+'-results.bin')),'RUN_CHANGED')
    reader=boot.base.Reader
    readers=[reader((folder/(n+'-results.bin')).read_bytes()) for n in ['original','mql5']]
    for r in readers:require(r.take('3i')==(MAGIC,1,len(rows)),'RESULT_HEADER')
    bad=[]
    for row in rows:
        values=[(r.take('2iI'),r.text(),r.text()) for r in readers]
        if values[0]!=values[1]:bad.append(dict(id=row['id'],symbol=row['symbol'],original=values[0],mql5=values[1]))
    require(all(r.pos==len(r.raw) for r in readers),'RESULT_TRAILING');report=dict(cases=len(rows),matched=len(rows)-len(bad),failed=len(bad),first_failures=bad[:12],**SCOPE)
    save(folder/'comparison.json',report);print(json.dumps(report,ensure_ascii=False));raise SystemExit(bool(bad))
if __name__=='__main__':main()
