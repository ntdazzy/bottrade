"""Compare bot3 virtual high/low and lock/counter branches.
This is a bounded native/MQL5 check; it is not a whole-EA test.
"""
import argparse,hashlib,importlib.util,itertools,json,math,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1]; ROOT=HOME.parent
def module(n,p):
 s=importlib.util.spec_from_file_location(n,p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
V=module('finish_levels',HOME/'tests/check-management-virtual-levels.py'); pre=V.pre; cpu=module('finish_cpu',ROOT/'cong-cu/doi-chieu-nan-quan-ly.py')
ANALYSIS=HOME/'phan-tich/dong-vi-the/management-20261025-r1'; CONTRACT=HOME/'phan-tich/dong-vi-the/management-virtual-finish-20261025-r1/contract.md'; MT=V.MT
MAGIC=0x4d564642; MASK=(1<<64)-1; CASE=struct.Struct('<8i20d'); RESULT=struct.Struct('<2iQ2iQ5QiQ')
INTS=['id','buy','stage','scenario','changed','index','digits0','digits1']; DOUBLES=['open','tp','level','unit','gap','freeze','lock','extra','reference','minimum','distance','anchor','bid','ask','table0','table1','shiftbuy','shiftsell','step','reserved']
NAMES=['Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh','Include/bot-cua-toi-3/Bot3VirtualStops.mqh','Include/bot-cua-toi-3/Bot3ManagementVirtualFinish.mqh','Scripts/bot-cua-toi-3/Bot3ManagementVirtualFinishBranchesCheck.mq5']
SCOPE=dict(slice_only=True,whole_manager_complete=False,whole_bot_complete=False,original_bytes_changed=False)
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def req(x,m):
 if not x: raise ValueError(m)
def save(p,o):p.write_text(json.dumps(o,ensure_ascii=False,indent=2),encoding='utf-8')
def cases():
 out=[]; vals=[-math.inf,-100.,-0.,0.,100.,math.inf,struct.unpack('<d',struct.pack('<Q',0x7ff8000000000123))[0]]
 for buy,stage in itertools.product([0,1],[0,1]):
  b=dict(id=0,buy=buy,stage=stage,scenario=0,changed=0,index=2,digits0=3,digits1=3,open=100.,tp=130. if buy else 70.,level=97. if buy else 103.,unit=1.,gap=1.25,freeze=2.5,lock=2.,extra=1.,reference=0.,minimum=.01,distance=2.,anchor=110. if buy else 90.,bid=100.,ask=101.,table0=98.,table1=102.,shiftbuy=0.,shiftsell=0.,step=1.,reserved=0.)
  def add(c,g):c['id']=len(out);c['group']=g;out.append(c)
  add(dict(b),'normal')
  for k in ['level','unit','gap','freeze','lock','extra','reference','distance','anchor','bid','ask']:
   for x in vals:c=dict(b);c[k]=x;add(c,'numeric-'+k)
  for s in [1,2,3,4,5,6,7,101,201,301]:
   for ch in [0,1]:c=dict(b);c['scenario']=s;c['changed']=ch;add(c,'api-'+str(s))
  for ds in [(0,1),(2,8),(11,-1),(-2147483648,2147483647)]:c=dict(b);c['digits0'],c['digits1']=ds;add(c,'digits')
  for flag in [0,1]:
   c=dict(b);c['reference']=0.0 if flag==0 else math.nan;add(c,'reference')
  for counter in [0,1,2147483647,-2147483648]:c=dict(b);c['step']=counter;add(c,'counter')
 return out
def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(CASE.pack(*(c[k] for k in INTS),*(c[k] for k in DOUBLES)) for c in rows)
def identity():return dict(original_ex5_sha256=pre.validation.original_hash(3),tool_sha256=sha(Path(__file__)),analysis_sha256=sha(ANALYSIS/'analysis.json'),contract_sha256=sha(CONTRACT),probe_sha256=sha(cpu.PROBE),sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES})
class Original(pre.entry.Original):
 def __init__(self,fixture):
  super().__init__(3);self.covered=set();self.events=[]
  data=json.loads((ANALYSIS/'analysis.json').read_text());req(pre.validation.original_hash(3)==data['original_ex5_sha256'],'EX5_DIFFERS')
  for f in data['functions']:
   lo,hi=int(f['rva'],16),int(f['end_rva'],16);req(hashlib.sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==f['native_bytes_sha256'],'NATIVE_CODE_DIFFERS')
  for a in [0x7c2970,0x7c2c10]: self.apis[self.base+a]=3;self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=self.base+a,end=self.base+a)
  self.m.mem_write(0x60000000,b'\xc3')
  self.m.hook_add(self.uc.UC_HOOK_CODE,lambda mm,aa,zz,uu:mm.emu_stop(),begin=0x60000000,end=0x60000000)
  self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x36667,end=self.base+0x3b1c7);self.nan=cpu.BothNaN(self,json.loads((ANALYSIS/'analysis.json').read_text()),fixture)
 def visit(self,m,a,z,u):
  o=a-self.base;self.covered.add(o)
  if o in ({0x36911,0x3691b,0x3aafe,0x3aafe} if self.case['stage']==0 else {0x36b19,0x3b1c7,0x3ad01}):self.stopped=True;m.emu_stop()
 def call(self,m,a,z,u):
  req(m.reg_read(self.x.UC_X86_REG_R8)==17 and self.text(m.reg_read(self.x.UC_X86_REG_RDX))=='CHECK','BAD_DIGITS');i=self.digit_count;req(i<2,'DIGITS');self.event(3,17,self.case['digits'+str(i)],i);self.digit_count+=1;m.reg_write(self.x.UC_X86_REG_RAX,self.case['digits'+str(i)]&MASK)
 def run(self,c):
  m,x=self.m,self.x;self.case=c;self.events=[];self.stopped=False;self.digit_count=0;self.cursor=0x70001000
  for r,raw in self.regions:
   if r.get('kind')=='mutable_program_data':m.mem_write(r['base'],raw)
  for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
  m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
  for r,k in [(0x6d670,'level'),(0x73dd8,'unit'),(0x73ab0,'gap'),(0x744a8,'freeze'),(0x74430,'step')]:m.mem_write(self.base+r,struct.pack('<d',c[k]))
  m.reg_write(x.UC_X86_REG_RDI,self.base+0x74958);m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string('CHECK')));m.reg_write(x.UC_X86_REG_R12,c['changed']);m.reg_write(x.UC_X86_REG_RSP,0x5001fdf8)
  m.mem_write(0x5001fdf8,struct.pack('<Q',0x60000000))
  for r,k in [(6,'open'),(7,'tp'),(9,'level'),(10,'level'),(11,'level'),(15,'anchor')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(r)),pre.bits(c[k]))
  m.mem_write(self.base+0x74798,struct.pack('<2d',c['bid'],c['ask']));m.mem_write(self.base+0x73df0,struct.pack('<9d',*([c['table0']+i for i in range(9)])));m.mem_write(self.base+0x74110,struct.pack('<9d',*([c['table1']+i for i in range(9)])))
  start=(0x36667,0x3a97d,0x3691b,0x3aafe)[c['stage']*2+c['buy']];end=(0x3691b,0x3aafe,0x36b19,0x3ad01)[c['stage']*2+c['buy']]
  try:m.emu_start(self.base+start,self.base+end,timeout=5000000,count=100000)
  except Exception as e:raise RuntimeError('native-rva=%#x'% (m.reg_read(x.UC_X86_REG_RIP)-self.base)) from e
  self.stopped=True
  evh=0xcbf29ce484222325
  for e in self.events:
   for b in struct.pack('<5Q',*e):evh=((evh^b)*0x100000001b3)&MASK
  read=lambda r:struct.unpack('<Q',m.mem_read(self.base+r,8))[0]
  return RESULT.pack(c['id'],int((m.reg_read(x.UC_X86_REG_R12)&255)!=0),read(0x6d670),struct.unpack('<i',m.mem_read(self.base+0x74430,4))[0],struct.unpack('<I',m.mem_read(self.base+0x74934,4))[0],evh,read(0x74798),read(0x747a0),read(0x73dd8),read(0x73ab0),read(0x744a8),0,0)
def main():
 p=argparse.ArgumentParser();p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();req(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();cur=identity()
 if a.mode=='prepare':
  folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));(folder/'tested-sources').mkdir();save(folder/'baseline.json',dict(**cur,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps({'cases':len(rows)}));return
 b=json.loads((folder/'baseline.json').read_text());req(all(b[k]==v for k,v in cur.items()) and b['inputs_sha256']==sha(folder/'cases.bin'),'IDENTITY')
 if a.mode=='original':
  f=cpu.CpuFixture();raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
  try:
   cpu.verify_probe(f,cur['probe_sha256']);r=Original(f)
   for c in rows:raw+=r.run(c)
  finally:f.close()
  (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',dict(**cur,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps({'cases':len(rows)}));return
 if a.mode=='mql5':
  req(a.build,'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));req(build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
  files=MT/'MQL5/Files/bot3-management-virtual-finish-branches'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
  preset=MT/'MQL5/Presets'/('b3-finish-'+a.run+'.set');ini=MT/('b3-finish-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ManagementVirtualFinishBranchesCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
  proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW);code=proc.wait(timeout=120);req(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
  for n in ['mql5-results.bin','script-status.bin']:(folder/n).write_bytes((files/n).read_bytes())
  save(folder/'mql5-run.json',dict(**cur,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,**SCOPE));print(json.dumps({'cases':len(rows)}));return
 n=(folder/'original-results.bin').read_bytes();m=(folder/'mql5-results.bin').read_bytes();req(n==m,'RESULTS_DIFFER');print(json.dumps({'cases':len(rows),'matched':len(rows)}))
if __name__=='__main__':main()
