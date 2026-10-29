"""Bot2 arithmetic comparison runner."""
import argparse,hashlib,importlib.util,json,random,re,struct,sys,subprocess,shutil,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MT=ROOT.parent/'.local/mt5-bot3-thread-20261025';MAGIC=0x564f4c32;MASK=(1<<64)-1
EX5_SHA='390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795';NATIVE_SHA='9638c651c1c79db6dd85d00e356f004473ff844081991567ba380e5c7167ed78'
FIELDS=[('use_equity','B'),('only_up','B'),('manual_balance','d'),('start_lots','d'),('max_lots','d'),('lot_scale','d'),('manual_risk','d'),('strategy_risk','d'),('mode','I'),('highest_balance','d'),('volume','d'),('strategy_loss','d'),('balance_step','i'),('balance','d'),('equity','d'),('converted_balance','d'),('tick_value','d'),('minimum','d'),('maximum','d'),('step','d'),('stop_distance','d'),('multiplier','i')]
OUTPUTS=[('volume','d',0x649c0),('effective_balance','d',0x68260),('highest_balance','d',0x68268),('mode','I',0x5e538),('strategy_loss','d',0x67eb0),('balance_step','i',0x5e548)]
ADDR={'use_equity':0x68780,'only_up':0x68760,'manual_balance':0x68730,'start_lots':0x5e528,'max_lots':0x5e530,'lot_scale':0x66230,'manual_risk':0x5e540,'strategy_risk':0x68748,'mode':0x5e538,'highest_balance':0x68268,'volume':0x649c0,'strategy_loss':0x67eb0,'balance_step':0x5e548}
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def bits(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def fk(k):return 'i' if k=='B' else k
def base():return dict(use_equity=0,only_up=1,manual_balance=0.,start_lots=.01,max_lots=99.,lot_scale=1.,manual_risk=1.2,strategy_risk=6.,mode=0,highest_balance=10000.,volume=.37,strategy_loss=100.,balance_step=1000,balance=12000.,equity=11000.,converted_balance=12000.,tick_value=1.,minimum=.01,maximum=200.,step=.01,stop_distance=100.,multiplier=100)
def cases():
 r=random.Random(2026102902);out=[]
 def add(tag,**x):c=base();c.update(x);c['tag']=tag;out.append(c)
 for _ in range(600):
  c=base();c.update(tag='mixed',use_equity=r.randrange(2),only_up=r.randrange(2),manual_balance=r.choice([0.,-1.,1.,10000.]),start_lots=r.choice([0.,.01,.1,1.]),max_lots=r.choice([0.,.01,.1,99.]),lot_scale=r.choice([0.,.5,1.,2.]),manual_risk=r.uniform(-2,20),strategy_risk=r.uniform(-2,20),mode=r.choice([0,1,3,998,999,1000,9999,0xffffffff]),highest_balance=r.uniform(-1,30000),volume=r.uniform(-1,3),strategy_loss=r.choice([0.,1.,100.]),balance_step=r.choice([0,1,1000]),balance=r.uniform(-1,30000),equity=r.uniform(-1,30000),converted_balance=r.uniform(-1,30000),tick_value=r.choice([0.,.1,1.,10.,float('nan'),float('inf')]),minimum=r.choice([0.,.001,.01,.1]),maximum=r.choice([0.,.01,.1,200.]),step=r.choice([0.,.001,.01,.1,.05,1.]),stop_distance=r.choice([0.,1.,100.,float('nan'),float('inf')]),multiplier=r.choice([0,1,100]));out.append(c)
 for mode in [0,1,3,998,999,1000,9999,0xffffffff]:
  for step in [0.,.001,.01,.1,.05,1.]:
   for mult in [0,1,100]:add('modes-and-steps',mode=mode,step=step,multiplier=mult)
 for mode in [0,3,999,9999]:
  for v in [-1.,-0.,0.,1.,10000.,10000.0001]:add('balance-boundary',mode=mode,balance=v,highest_balance=10000.,only_up=1)
 for i,c in enumerate(out):c['id']=i;c['index']=(0,3,7)[i%3]
 return out
def encode(cs):
 b=bytearray(struct.pack('<4i',MAGIC,1,len(cs),len(OUTPUTS)+3))
 for c in cs:
  b+=struct.pack('<2i',c['id'],c['index'])
  for n,k in FIELDS:b+=struct.pack('<'+fk(k),c[n])
 return bytes(b)
def read_cases(out):
 cs=json.loads((out/'cases.json').read_text())
 if encode(cs)!=(out/'cases.bin').read_bytes():raise ValueError('CASE_BYTES_MISMATCH')
 return cs
loader_spec=importlib.util.spec_from_file_location('arithmetic2_loader',ROOT/'cong-cu/kiem-gio-mua-he-bot-2.py');loader=importlib.util.module_from_spec(loader_spec);loader_spec.loader.exec_module(loader)
class Native(loader.Original):
 def __init__(self):
  super().__init__({});self.all_currency=[];self.errors=[];eb=0x7ff79ff60000
  if self.base!=0x253f2620000 or hashlib.sha256(bytes(self.m.mem_read(self.base+0x35810,0x19e0))).hexdigest()!=NATIVE_SHA:raise ValueError('NATIVE_BODY_IDENTITY')
  self.ranges=[(0,0x57),(0x60,0x1d8),(0x1e0,0x3bd),(0x5c0,0x7d8),(0x16ff0,0x17440),(0x35810,0x371f1)]
  for a,api in {eb+0x797370:10,eb+0x7c2890:11,eb+0x7b49f0:12,eb+0x7bdc90:13,eb+0x7cf6c0:14,eb+0x3959a0:200}.items():
   existed=a in self.apis;self.apis[a]=api
   if existed:continue
   pg=a&~0xfff
   if not any(lo<=pg<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(pg,4096)
   self.m.mem_write(a,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
  self.currency=self.base+0x371f0;self.m.hook_add(self.uc.UC_HOOK_CODE,self.currency_call,begin=self.currency,end=self.currency)
 def currency_call(self,m,a,size,user):
  amount=m.reg_read(self.x.UC_X86_REG_XMM0)&MASK
  if amount!=int.from_bytes(m.mem_read(self.base+0x68260,8),'little'):raise ValueError('CURRENCY_AMOUNT')
  self.currency_trace.append(amount);self.all_currency.append({'case':self.c['id'],'amount_bits':amount,'converted_bits':bits(self.c['converted_balance'])});v=bits(self.c['converted_balance']);m.reg_write(self.x.UC_X86_REG_XMM0,v);m.reg_write(self.x.UC_X86_REG_RAX,v);self.ret(m)
 def ret(self,m):
  rsp=m.reg_read(self.x.UC_X86_REG_RSP);r=struct.unpack('<Q',m.mem_read(rsp,8))[0];m.reg_write(self.x.UC_X86_REG_RSP,rsp+8);m.reg_write(self.x.UC_X86_REG_RIP,r)
 def call(self,m,a,size,user):
  x=self.x;api=self.apis[a];c=self.c
  if api in [100,101]:return super().call(m,a,size,user)
  if m.reg_read(x.UC_X86_REG_RCX)!=0x253ee076f88:raise ValueError('SDK_CONTEXT')
  if api==10:q=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;v=c['balance' if q==37 else 'equity']
  elif api==11:q=m.reg_read(x.UC_X86_REG_R8)&0xffffffff;v=c[{26:'tick_value',34:'minimum',35:'maximum',36:'step'}[q]]
  elif api==12:q=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;self.warnings+=int(q==2);self.alerts+=int(q==3);self.ret(m);return
  elif api==13:self.peak+=1;self.ret(m);return
  elif api==14:m.mem_write(m.reg_read(x.UC_X86_REG_R9),b'\0'*12);self.ret(m);return
  elif api==200:
   self.error=m.reg_read(x.UC_X86_REG_RDX)
   if (self.error&0xffffffff)!=0x1f7:raise ValueError('UNEXPECTED_FATAL '+hex(self.error))
   m.emu_stop();return
  raw=struct.pack('<d',v);m.mem_write(self.base+0x68448,raw);m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'));self.ret(m)
 def run(self,c):
  m,x=self.m,self.x;self.c=c;self.cursor=0x70001000;self.live_allocs=set();self.allocs=self.frees=self.warnings=self.alerts=self.peak=0;self.error=0;self.currency_trace=[]
  for r,raw in self.regions:
   if r.get('kind')=='mutable_program_data':m.mem_write(r['base'],raw)
  for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
  for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
  for n,k in FIELDS[:13]:m.mem_write(self.base+ADDR[n],bytes([int(c[n])&1]) if k=='B' else struct.pack('<'+fk(k),c[n]))
  m.mem_write(self.base+0x65834,struct.pack('<I',c['index']));m.mem_write(self.base+ADDR['volume']+c['index']*8,struct.pack('<d',c['volume']))
  m.mem_write(self.base+0x68770,b'\0');self.supply_text(self.base+0x65858,'XAUUSD');before=[bytes(m.mem_read(self.base+0x649c0+i*8,8)) for i in range(8)];top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_XMM0,bits(c['stop_distance']));m.reg_write(x.UC_X86_REG_RDX,c['multiplier']&0xffffffff);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
  try:m.emu_start(self.base+0x35810,0x60000000,timeout=5000000,count=3000000)
  except self.uc.UcError as e:raise RuntimeError(f'case={c["id"]} rip={m.reg_read(x.UC_X86_REG_RIP):x} {e}')
  if self.error:self.errors.append({'case':c['id'],'error_code':self.error,'low32':self.error&0xffffffff,'division_class':(self.error&0xffffffff)==0x1f7})
  vals=[]
  for n,k,rva in OUTPUTS:
   if n=='volume':rva+=c['index']*8
   raw=m.mem_read(self.base+rva,struct.calcsize('<'+k));vals.append(0 if self.error else (int.from_bytes(raw,'little') if k=='d' else struct.unpack('<'+k,raw)[0]&MASK))
  for i,raw in enumerate(before):
   if i!=c['index'] and bytes(m.mem_read(self.base+0x649c0+i*8,8))!=raw:raise RuntimeError(f'VOLUME_ARRAY_SIDE_EFFECT index={c["id"]} changed={i}')
  return [c['id'],int(not self.error),*vals,self.warnings,self.alerts,self.peak]
HOME=ROOT/'bot-cua-toi-2';SRC=HOME/'source/MQL5';SCRIPT='Scripts/bot-cua-toi-2/ScriptBot2VolumeArithmeticCheck.mq5'
SCOPE=dict(full_ea=False,arithmetic_only=True,currency_body_executed=False,currency_result_supplied=True,withdrawal_setting_disabled=True,diagnostic_text_compared=False,diagnostic_counters_compared=True,exact_fault_state=False,mql_runtime_fatal_executed=False,other_volume_slots_checked=True)
def save(path,data):
 text=json.dumps(data,ensure_ascii=False,indent=2,allow_nan=True)+'\n'
 if path.exists():
  if path.read_text(encoding='utf-8')!=text:raise ValueError('EVIDENCE_EXISTS '+str(path))
  return
 with path.open('x',encoding='utf-8',newline='\n') as f:f.write(text)
def identity():
 ex5=Path('C:/Users/NTD/Desktop/BotTradeEA/local/market-demos-20261020/dich-nguoc-luot2/terminal/MQL5/Experts/Market/Goldbot One MT5.ex5')
 if sha(ex5)!=EX5_SHA:raise ValueError('ORIGINAL_EX5_CHANGED')
 sources={n:sha(SRC/n) for n in ['Include/bot-cua-toi-2/Bot2VolumeArithmetic.mqh',SCRIPT]}
 helpers={str(p.relative_to(ROOT)).replace('\\','/'):sha(p) for p in [Path(__file__),Path(loader.__file__)]}
 return dict(original_ex5_sha256=EX5_SHA,native_body_sha256=NATIVE_SHA,sources_sha256=sources,helpers_sha256=helpers)
def verify_build(build,current):
 p=HOME/'bang-chung/bien-dich'/build/'bien-nhan.json';r=json.loads(p.read_text(encoding='utf-8-sig'))
 if r['target']!=SCRIPT or r['errors']!=0 or r['warnings']!=0:raise ValueError('BUILD_NOT_CLEAN')
 for n,digest in current['sources_sha256'].items():
  if r['sources_sha256'][n]!=digest or sha(MT/'MQL5'/n)!=digest:raise ValueError('BUILD_SOURCE_CHANGED')
 binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5')
 if sha(binary)!=r['binary_sha256'] or sha(p.parent/binary.name)!=r['binary_sha256']:raise ValueError('BUILD_BINARY_CHANGED')
 return p

def main():
 ap=argparse.ArgumentParser();ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('run');ap.add_argument('--build',default='');a=ap.parse_args()
 if not re.fullmatch('[a-z0-9-]{1,48}',a.run) or (a.build and not re.fullmatch('[a-z0-9-]{1,64}',a.build)):raise ValueError('BAD_RUN_OR_BUILD')
 out=HOME/'bang-chung/kiem-khoi-luong'/a.run;current=identity()
 if a.mode=='prepare':
  out.mkdir(parents=True,exist_ok=False);cs=cases();save(out/'cases.json',cs);(out/'cases.bin').write_bytes(encode(cs));save(out/'baseline.json',dict(**current,cases=len(cs),cases_sha256=sha(out/'cases.bin'),**SCOPE));print(json.dumps({'cases':len(cs)}));return
 cs=read_cases(out);baseline=json.loads((out/'baseline.json').read_text())
 if any(baseline.get(k)!=v for k,v in current.items()) or baseline['cases_sha256']!=sha(out/'cases.bin'):raise ValueError('IDENTITY_CHANGED')
 if a.mode=='original':
  if (out/'original-results.bin').exists():raise FileExistsError('OLD_ORIGINAL_RUN')
  n=Native();rows=[n.run(c) for c in cs]
  with (out/'original-results.bin').open('xb') as f:f.write(struct.pack('<5i',MAGIC,1,len(rows),len(OUTPUTS)+3,0)+b''.join(struct.pack('<2i'+'Q'*(len(r)-2),*r) for r in rows))
  save(out/'currency-trace.json',n.all_currency);save(out/'native-errors.json',n.errors)
  save(out/'original-run.json',dict(**current,cases=len(rows),currency_calls=len(n.all_currency),native_division_faults=len(n.errors),result_sha256=sha(out/'original-results.bin'),currency_trace_sha256=sha(out/'currency-trace.json'),native_errors_sha256=sha(out/'native-errors.json'),**SCOPE))
  print(json.dumps(dict(cases=len(rows),currency_calls=len(n.all_currency),native_division_faults=len(n.errors))));return
 if a.mode=='mql5':
  if not a.build:raise ValueError('BUILD_REQUIRED')
  receipt=verify_build(a.build,current)
  probe=subprocess.run(['powershell','-NoProfile','-Command',f'Get-Process terminal64,metaeditor64 -ErrorAction SilentlyContinue | Where-Object {{$_.Path -like "{MT}*"}} | Select-Object -ExpandProperty Id'],capture_output=True,text=True,creationflags=subprocess.CREATE_NO_WINDOW)
  if probe.stdout.strip():raise RuntimeError('PRIVATE_MT5_BUSY')
  if (out/'mql5-results.bin').exists():raise FileExistsError('OLD_MQL5_RUN')
  files=MT/'MQL5/Files/bot2-volume-arithmetic'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
  preset=MT/'MQL5/Presets'/f'b2-{a.run}.set';preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini=MT/f'b2-arithmetic-{a.run}.ini'
  ini.write_text('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-2\\ScriptBot2VolumeArithmeticCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
  process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
  try:code=process.wait(timeout=120)
  except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MQL5_TIMEOUT')
  result=files/'mql5-results.bin'
  if code!=0 or not result.is_file():raise RuntimeError('MQL5_RESULTS_MISSING '+str(code))
  verify_build(a.build,current)
  with (out/'mql5-results.bin').open('xb') as f:f.write(result.read_bytes())
  save(out/'mql5-run.json',dict(**current,cases=len(cs),exit_code=code,build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(out/'mql5-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(cs),exit_code=code)));return
 e=(out/'original-results.bin').read_bytes();v=(out/'mql5-results.bin').read_bytes();head=struct.pack('<5i',MAGIC,1,len(cs),len(OUTPUTS)+3,0);fmt='<2i'+'Q'*9;size=struct.calcsize(fmt);fails=[]
 for name,raw in [('original',e),('mql5',v)]:
  record=json.loads((out/(name+'-run.json')).read_text())
  if any(record.get(k)!=value for k,value in current.items()) or record['result_sha256']!=hashlib.sha256(raw).hexdigest():raise ValueError('RUN_CHANGED')
 orig=json.loads((out/'original-run.json').read_text())
 if orig['currency_trace_sha256']!=sha(out/'currency-trace.json') or orig['native_errors_sha256']!=sha(out/'native-errors.json'):raise ValueError('TRACE_CHANGED')
 if e[:20]!=head or v[:20]!=head or len(e)!=20+len(cs)*size or len(v)!=len(e):raise ValueError('RESULT_LAYOUT')
 native_false=[];mql_false=[]
 for i,c in enumerate(cs):
  x=struct.unpack_from(fmt,e,20+i*size);y=struct.unpack_from(fmt,v,20+i*size)
  if x[0]!=c['id'] or y[0]!=c['id']:raise ValueError('CASE_ID')
  if x[1]==0:native_false.append(c['id'])
  if y[1]==0:mql_false.append(c['id'])
  if x!=y:fails.append({'id':c['id'],'tag':c['tag'],'native':list(x),'mql5':list(y)})
 errors=json.loads((out/'native-errors.json').read_text())
 if native_false!=[r['case'] for r in errors] or any((r['error_code']&0xffffffff)!=0x1f7 or r['low32']!=0x1f7 for r in errors):raise ValueError('NATIVE_FAULT_KIND')
 rec=dict(cases=len(cs),normal_cases=len(cs)-len(native_false),native_division_faults=len(native_false),component_false_results=len(mql_false),matched=len(cs)-len(fails),failed=len(fails),first_failures=fails[:10],hashes={n:sha(out/n) for n in ['cases.bin','original-results.bin','mql5-results.bin','native-errors.json','currency-trace.json']},**SCOPE)
 save(out/'comparison.json',rec);print(json.dumps(rec));raise SystemExit(bool(fails))
if __name__=='__main__':main()
