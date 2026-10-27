"""Compare bot deinitialization object cleanup against the unchanged EX5 body."""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x4c594331;MASK=(1<<64)-1

def module(name,path):
 s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
price=module('lifecycle_price',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py')

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf-8',newline='\n')
def require(ok,msg):
 if not ok:raise ValueError(msg)
def cases():
 return [dict(id=i,extended=int(ext),indicator=ind) for i,(ext,ind) in enumerate([(0,-1),(0,42),(1,-1),(1,42)])]
def encode(rows):
 raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
 for c in rows:raw+=struct.pack('<3i',c['id'],c['extended'],c['indicator'])
 return bytes(raw)
class Native:
 def __init__(self,bot):
  self.bot=bot;self.o=price.Original(bot);self.m=self.o.m;self.x=self.o.x;self.eb=0x7ff683f20000;self.events=[];self.cursor=0x70001000
  self.m.mem_map(0x70000000,0x200000);self._mapped=set()
  for off,api in [(0x7c4ce0,4),(0x7cdfe0,5),(0x7bee30,6),(0x7d1190,100),(0x7d1200,101),(0x7c4d40,7)]:self.add_api(off,api)
 def add_api(self,off,api):
  addr=self.eb+off
  if (addr&~0xfff) not in self._mapped:self.m.mem_map(addr&~0xfff,4096);self._mapped.add(addr&~0xfff)
  self.m.mem_write(addr,b'\xc3');self.o.apis[addr]=api
  def hook(mu,address,size,user):
   reg=lambda n:mu.reg_read(getattr(self.x,'UC_X86_REG_'+n))
   if api==4:self.events.append([1,reg('RDX'),0,0,self.read_desc(reg('R8'))]);mu.reg_write(self.x.UC_X86_REG_RAX,1)
   elif api==5:
    value=reg('RDX');self.events.append([2,value,reg('R8'),reg('R9'),""]);txt=str(value);raw=txt.encode('utf-16-le');a=self.cursor;self.cursor+=256;mu.mem_write(a,struct.pack('<III',0,2,len(txt))+raw+b'\0\0');slot=0x6a43c if self.bot==1 else 0x1d6e3c;mu.mem_write(self.o.base+slot,struct.pack('<IQ',0,a+12));mu.reg_write(self.x.UC_X86_REG_RAX,a+12)
   elif api==6:self.events.append([3,reg('RDX'),0,0,""]);mu.reg_write(self.x.UC_X86_REG_RAX,1)
   elif api==7:
    signed=lambda v: v-(1<<32) if v&0xffffffff>=0x80000000 else v
    self.events.append([4,reg('RDX'),signed(reg('R8')),signed(reg('R9')),""]);mu.reg_write(self.x.UC_X86_REG_RAX,0)
   elif api==100:
    n=reg('RDX')&0xffffffff;a=self.cursor;self.cursor+=(12+(n+1)*2+15)&~15;mu.mem_write(a,struct.pack('<III',n+1,0,0)+b'\0'*((n+1)*2));mu.reg_write(self.x.UC_X86_REG_RAX,a)
   elif api==101:pass
  self.m.hook_add(self.o.uc.UC_HOOK_CODE,hook,begin=addr,end=addr)
 def read_desc(self,p):
  try:
   ptr=int.from_bytes(self.m.mem_read(p+4,8),'little');n=int.from_bytes(self.m.mem_read(ptr-4,4),'little');return bytes(self.m.mem_read(ptr,n*2)).decode('utf-16-le')
  except Exception:return None
 def run(self,c):
  m,x=self.m,self.x;self.events=[];self.cursor=0x70001000
  for region,raw in self.o.regions:
   if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
  if self.bot==1:cond,ind=0x68294,0x62188
  else:cond,ind=0x752d4,0x6d178
  m.mem_write(self.o.base+cond,bytes([c['extended']]));m.mem_write(self.o.base+ind,struct.pack('<q',c['indicator']))
  for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
  for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
  top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
  fn=0x1f5e0 if self.bot==1 else 0x2a800
  m.emu_start(self.o.base+fn,0x60000000,timeout=30000000,count=20000000)
  require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_NO_RETURN')
  return self.events

def identity(bot,script):
 home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';helpers=[Path(__file__),root_tool:=ROOT/'cong-cu/bien-dich.ps1']
 return {'original_ex5_sha256':('a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922' if bot==1 else 'ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83'),'sources_sha256':{script.as_posix():sha(source/script)},'helpers_sha256':{Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))}}
def read_events(raw):
 out=[];pos=0
 while pos<len(raw):
  api,a,b,c,n=struct.unpack_from('<iqqqi',raw,pos);pos+=struct.calcsize('<iqqqi');text=raw[pos:pos+n*2].decode('utf-16-le');pos+=n*2;out.append([api,a,b,text])
 return out
def main():
 p=argparse.ArgumentParser();p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');rows=cases();home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;script=Path(f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}LifecycleCheck.mq5');cur=identity(a.bot,script)
 if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**cur,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),whole_bot_complete=False));print(json.dumps({'cases':len(rows)}));return
 b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in cur.items()),'IDENTITY_CHANGED')
 if a.mode=='mql5':
  receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==script.as_posix() and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN');mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';require(sha(mt/'MQL5'/script)==build['sources_sha256'][script.as_posix()] == cur['source_sha256'],'BUILD_CHANGED');binary=mt/'MQL5'/script.with_suffix('.ex5');require(sha(binary)==build['binary_sha256'],'BINARY_CHANGED');files=mt/f'MQL5/Files/bot{a.bot}-lifecycle'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=mt/'MQL5/Presets'/('lifecycle-'+a.run+'.set');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini=mt/('lifecycle-'+a.run+'.ini');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}LifecycleCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW);code=proc.wait(timeout=120);require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED');
  for name in ['mql5-results.bin','script-status.bin']:(folder/name).write_bytes((files/name).read_bytes())
  save(folder/'mql5-run.json',dict(**cur,cases=len(rows),build=a.build,result_sha256=sha(folder/'mql5-results.bin')));print(json.dumps({'cases':len(rows)}));return
 if a.mode=='original':
  n=Native(a.bot);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));all_events=[]
  for c in rows:
   ev=n.run(c);all_events.append(ev);data=bytearray();
   for api,x,y,z,text in ev:data+=struct.pack('<qqqqi',api,x,y,z,len(text))+text.encode('utf-16-le')
   raw+=struct.pack('<ii',c['id'],len(data))+data
  (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',dict(**cur,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),events=[len(e) for e in all_events]));print(json.dumps({'cases':len(rows),'events':[len(e) for e in all_events]}));return
 left=(folder/'original-results.bin').read_bytes();right=(folder/'mql5-results.bin').read_bytes();require(left==right,'RESULTS_DIFFER');save(folder/'comparison.json',dict(cases=len(rows),matched=len(rows),failed=0,whole_bot_complete=False,scope='Deinitialization object order, conditional 300-row cleanup, indicator release and ObjectsDeleteAll; full initialization and EA excluded'));print(json.dumps({'cases':len(rows),'matched':len(rows),'failed':0}))
if __name__=='__main__':main()
