"""Đối chiếu hàm kiểm khối lượng bot2 với mã máy gốc và MT5 riêng."""
import argparse,hashlib,importlib.util,json,math,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];HOME=ROOT/'bot-cua-toi-2';MT=ROOT.parent/'.local/mt5-bot3-thread-20261025'
MAGIC=0x56414c31;MASK=(1<<64)-1;BASE=0x253f2620000;SDK=0x7ff79ff60000;CTX=0x253ee076f88;FN=0x3cfb0;END=0x3d63a
CODE_SHA='ae4e9020f7f5f08d49774728bed14c17eb2bd26b6271c20da51bd3aaa446014f';BODY_SHA='0f1ee410718814fe9908848d05ae3303b2350483c0dda0292e3d9d75eed489b3';EX5_SHA='390d8ab14fc213ff4b8cbe5084bec545526e62c6028516fe21219a59398ce795'
spec=importlib.util.spec_from_file_location('dst',ROOT/'cong-cu/kiem-gio-mua-he-bot-2.py');dst=importlib.util.module_from_spec(spec);spec.loader.exec_module(dst)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def bits(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def save(p,v):
 raw=json.dumps(v,ensure_ascii=False,indent=2)+'\n'
 if p.exists():
  if p.read_text(encoding='utf-8')!=raw:raise ValueError('EVIDENCE_EXISTS '+str(p))
  return
 with p.open('x',encoding='utf-8') as f:f.write(raw)
def identity():
 paths={
  'source_mqh':HOME/'source/MQL5/Include/bot-cua-toi-2/Bot2VolumeValidation.mqh',
  'source_mq5':HOME/'source/MQL5/Scripts/bot-cua-toi-2/Bot2VolumeValidationCheck.mq5',
  'helper':Path(__file__),
  'native_loader':Path(dst.__file__),
  'capture':HOME/'bang-chung/captures/luot-20261026-r1/00000253f2620000.bin',
  'metadata':HOME/'phan-tich/luot-20261026-data-r2/metadata/import.json',
 }
 return {k:sha(v) for k,v in paths.items()}
def th(raw):
 h=0xcbf29ce484222325
 for b in raw:h=((h^b)*0x100000001b3)&MASK
 return h
def cases():
 out=[];vals=[-1.,-0.,0.,.001,.005,.0099999,.01,.0100001,.015,.025,.05,.0999999,.1,.1000001,.15,.25,1.,1.005,1.01,10.,float('nan'),float('inf'),-float('inf')]
 def add(g,v,lo,hi,s):out.append(dict(id=len(out),group=g,volume=bits(v),minimum=bits(lo),maximum=bits(hi),step=bits(s)))
 for lo,hi in [(.01,1.),(.1,1.),(1.,100.),(0.,0.),(1.,.1)]:
  for s in [0.,.001,.01,.1,.05,1.,float('nan')]:
   for v in vals:add('bounds-and-steps',v,lo,hi,s)
 for s in [.001,.01,.1,.25,.3]:
  for n in range(-3,31):
   for d in [-1e-7,-1e-8,0.,1e-8,1e-7]:add('tolerance',n*s+d,0.,100.,s)
 for lo,hi in [(-float('inf'),float('inf')),(float('nan'),1.),(0.,float('nan')),(float('nan'),float('nan')),(-10.,10.)]:
  for s in [-1.,-.1,float('inf'),-float('inf'),.01]:
   for v in [-1.5,-.5,-0.,.5,float('nan')]:add('unordered-negative',v,lo,hi,s)
 for s in [.01,.1,1.]:
  for q in [2147483646.,2147483647.,2147483648.,4294967296.,-2147483648.,-2147483649.]:
   for d in [-.5,0.,.5]:add('int32-conversion',(q+d)*s,-float('inf'),float('inf'),s)
 return out
def encode(rs):return struct.pack('<3i',MAGIC,3,len(rs))+b''.join(struct.pack('<i4Q',r['id'],r['volume'],r['minimum'],r['maximum'],r['step']) for r in rs)
def read_cases(p):
 raw=p.read_bytes();m,v,n=struct.unpack_from('<3i',raw)
 if (m,v)!=(MAGIC,3) or len(raw)!=12+n*36:raise ValueError('BAD_CASE_FILE')
 return [dict(zip(['id','volume','minimum','maximum','step'],x)) for x in struct.iter_unpack('<i4Q',raw[12:])]
def read_results(p):
 raw=p.read_bytes();m,v,n=struct.unpack_from('<3i',raw)
 if (m,v)!=(MAGIC,3) or len(raw)!=12+n*24:raise ValueError('BAD_RESULT_FILE')
 return list(struct.iter_unpack('<3iQI',raw[12:]))
def read_formats(p):
 rows={}
 for line in p.read_text(encoding='mbcs').splitlines():
  parts=line.split('|')
  if len(parts)!=4:raise ValueError('BAD_FORMAT_FILE')
  rows[int(parts[0])]=dict(minimum=parts[1],maximum=parts[2],step=parts[3])
 return rows
def native_fault_case(r):
 v=struct.unpack('<d',struct.pack('<Q',r['volume']))[0];lo=struct.unpack('<d',struct.pack('<Q',r['minimum']))[0];hi=struct.unpack('<d',struct.pack('<Q',r['maximum']))[0];step=struct.unpack('<d',struct.pack('<Q',r['step']))[0]
 return not (lo>v) and not (v>hi) and step==0.0
class Native(dst.Original):
 def __init__(self,formats):
  super().__init__({});self.ranges=[(0,0x57),(0x60,0x1d8),(0x1e0,0x3bd),(0x5c0,0x7d8),(FN,END)]
  for address,api in {SDK+0x7c2890:11,SDK+0x7b49f0:12,SDK+0x7cf6c0:14,SDK+0x3959a0:200}.items():
   existed=address in self.apis;self.apis[address]=api
   if existed:continue
   page=address&~0xfff
   if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
   self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
  self.formats=formats
  if hashlib.sha256(bytes(self.m.mem_read(BASE+FN,END-FN))).hexdigest()!=BODY_SHA:raise ValueError('VOLUME_BODY_CHANGED')
 def trace(self,*w):self.trace_bytes.extend(struct.pack('<3Q',*(x&MASK for x in w)))
 def call(self,m,address,size,user):
  x=self.x;api=self.apis[address];reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))
  if api in (100,101):return super().call(m,address,size,user)
  if api==11:
   if reg('RCX')!=CTX:raise ValueError('SYMBOL_CONTEXT')
   if self.text(reg('RDX'))!='XAUUSD':raise ValueError('SYMBOL_NAME')
   p=reg('R8')&0xffffffff
   if p not in (34,35,36):raise ValueError('SYMBOL_PROPERTY')
   q=self.row[['minimum','maximum','step'][p-34]];self.last_value=q;m.mem_write(BASE+0x68448,struct.pack('<Q',q));m.reg_write(x.UC_X86_REG_XMM0,q);self.trace(1,p,q);return
  if api==14:
   if reg('RCX')!=CTX or reg('R8')!=0x58:raise ValueError('FORMAT_ARGS')
   q=reg('RDX')&MASK
   if q not in self.formats or q!=self.last_value:raise ValueError('FORMAT_VALUE')
   raw=self.formats[q].encode('utf-16-le');ptr=self.cursor;self.cursor+=(12+len(raw)+2+15)&~15
   m.mem_write(ptr,struct.pack('<3I',len(self.formats[q])+1,1,len(self.formats[q]))+raw+b'\0\0');self.live_allocs.add(ptr);self.m.mem_write(reg('R9'),struct.pack('<IQ',len(self.formats[q])+1,ptr+12));return
  if api==12:
   if (reg('RCX'),reg('RDX'),reg('R8'),reg('R9'))!=(CTX,2,1,0x590008):raise ValueError('PRINT_ARGS')
   sp=reg('RSP');ptr=struct.unpack('<Q',m.mem_read(sp+40,8))[0];text=self.text(ptr);pre=['Volume is less than the minimal allowed SYMBOL_VOLUME_MIN=','Volume is greater than the maximal allowed SYMBOL_VOLUME_MAX=','Volume is not a multiple of the minimal step SYMBOL_VOLUME_STEP='];k=next((i+1 for i,p in enumerate(pre) if text.startswith(p)),0)
   expected=self.formats.get(self.last_value)
   if not k or expected is None or text!=pre[k-1]+expected:raise ValueError('PRINT_TEXT')
   self.trace(2,k,self.last_value);return
  if api==200:
   if reg('RCX')!=CTX or reg('RDX')!=0x220f10000001f7:raise ValueError('FATAL_ARGUMENTS')
   self.fatal=reg('RDX');m.emu_stop();return
  raise ValueError('UNEXPECTED_API '+hex(address))
 def run(self,row):
  self.row=row;self.fatal=0;self.trace_bytes=bytearray();self.cursor=0x70001000;self.live_allocs=set();self.allocs=self.frees=0
  for region,raw in self.regions:
   if region.get('kind')=='mutable_program_data':self.m.mem_write(region['base'],raw)
  for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:self.m.reg_write(getattr(self.x,'UC_X86_REG_'+n),0)
  for i in range(16):self.m.reg_write(getattr(self.x,'UC_X86_REG_XMM'+str(i)),0)
  self.supply_text(BASE+0x65858,'XAUUSD')
  self.m.mem_write(BASE+0x68410,bytes(4));self.m.reg_write(self.x.UC_X86_REG_EFLAGS,0x202);self.m.reg_write(self.x.UC_X86_REG_MXCSR,0x1f80)
  top=0x50020000-0x108;self.m.mem_write(top,struct.pack('<Q',0x60000000));self.m.reg_write(self.x.UC_X86_REG_RSP,top);self.m.reg_write(self.x.UC_X86_REG_XMM0,row['volume']);self.m.emu_start(BASE+FN,0x60000000,timeout=5000000,count=2000000)
  if self.fatal:
   if self.fatal&0xffffffff!=0x1f7:raise ValueError('UNEXPECTED_NATIVE_ERROR '+hex(self.fatal))
   return row['id'],-1,len(self.trace_bytes)//24,th(self.trace_bytes),struct.unpack('<I',self.m.mem_read(BASE+0x68410,4))[0]
  if self.m.reg_read(self.x.UC_X86_REG_RIP)!=0x60000000:raise ValueError('NATIVE_DID_NOT_RETURN')
  return row['id'],int(bool(self.m.reg_read(self.x.UC_X86_REG_RAX)&255)),len(self.trace_bytes)//24,th(self.trace_bytes),struct.unpack('<I',self.m.mem_read(BASE+0x68410,4))[0]
def verify_build(build):
 p=HOME/'bang-chung/bien-dich'/build/'bien-nhan.json';r=json.loads(p.read_text(encoding='utf-8-sig'));target='Scripts/bot-cua-toi-2/Bot2VolumeValidationCheck.mq5';script=MT/'MQL5'/target.replace('.mq5','.ex5')
 if r['target']!=target or r['errors']!=0 or r['warnings']!=0 or sha(script)!=r['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
 for name in ['Include/bot-cua-toi-2/Bot2VolumeValidation.mqh',target]:
  if sha(HOME/'source/MQL5'/name)!=r['sources_sha256'][name] or sha(MT/'MQL5'/name)!=r['sources_sha256'][name]:raise ValueError('BUILD_SOURCE_CHANGED')
 if sha(p.parent/script.name)!=r['binary_sha256']:raise ValueError('ARCHIVED_BINARY_CHANGED')
 return p,script
def run_mt5(run,rs,case=-1):
 files=MT/'MQL5/Files/bot2-volume-validation'/run;files.mkdir(parents=True,exist_ok=False);(files/'cases.bin').write_bytes(encode(rs));preset=MT/'MQL5/Presets'/('b2-'+run+'.set');preset.write_text('CheckRun='+run+'\nCheckCase='+str(case)+'\n',encoding='utf-16');ini=MT/('b2-'+run+'.ini');ini.write_text('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-2\\Bot2VolumeValidationCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');logs={p:p.stat().st_size for d in [MT/'MQL5/Logs',MT/'logs'] if d.is_dir() for p in d.glob('*.log')};p=subprocess.run(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW,timeout=120);lines=[]
 for d in [MT/'MQL5/Logs',MT/'logs']:
  for log in d.glob('*.log'):
   raw=log.read_bytes();start=logs.get(log,0);lines.extend(raw[start:].decode('utf-16-le',errors='replace').splitlines())
 return files,p.returncode,lines
def main():
 ap=argparse.ArgumentParser();ap.add_argument('mode',choices=['prepare','original','mql5','faults','compare']);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args();out=HOME/'bang-chung/kiem-khoi-luong-hop-le'/a.run
 if not re.fullmatch('[a-z0-9-]{1,48}',a.run) or (a.build is not None and not re.fullmatch('[a-z0-9-]{1,64}',a.build)):raise ValueError('BAD_RUN_OR_BUILD')
 if a.mode=='prepare':
  out.mkdir(parents=True,exist_ok=False);rs=cases();(out/'cases.bin').write_bytes(encode(rs));save(out/'cases.json',rs);save(out/'baseline.json',dict(original_ex5_sha256=EX5_SHA,capture_code_sha256=CODE_SHA,native_body_sha256=BODY_SHA,cases=len(rs),cases_sha256=sha(out/'cases.bin'),tool_sha256=sha(Path(__file__)),identity=identity()));print(json.dumps({'cases':len(rs)}));return
 rs=read_cases(out/'cases.bin');base=json.loads((out/'baseline.json').read_text())
 if base['cases_sha256']!=sha(out/'cases.bin') or base['tool_sha256']!=sha(Path(__file__)) or base.get('identity')!=identity():raise ValueError('INPUTS_CHANGED')
 if a.mode=='original':
  if (out/'original-results.bin').exists():raise ValueError('ORIGINAL_OUTPUT_EXISTS')
  measured=json.loads((out/'mql5-run.json').read_text())
  if measured['formatted_sha256']!=sha(out/'formatted.txt') or measured['identity']!=identity():raise ValueError('FORMAT_IDENTITY_CHANGED')
  fm=read_formats(out/'formatted.txt');formats={}
  for r in rs:
   if r['id'] not in fm:continue
   for n in ['minimum','maximum','step']:formats[r[n]]=fm[r['id']][n]
  o=Native(formats);vals=[];fault_traces={};trace_dir=out/'native-fault-traces';trace_dir.mkdir(exist_ok=False)
  for r in rs:
   v=o.run(r);vals.append(v)
   if v[1]==-1:
    trace_path=trace_dir/(str(r['id'])+'.bin')
    with trace_path.open('xb') as f:f.write(o.trace_bytes)
    fault_traces[str(r['id'])]=sha(trace_path)
  with (out/'original-results.bin').open('xb') as f:f.write(struct.pack('<3i',MAGIC,3,len(vals))+b''.join(struct.pack('<3iQI',*v) for v in vals))
  save(out/'original-run.json',dict(cases=len(vals),faults=sum(v[1]==-1 for v in vals),result_sha256=sha(out/'original-results.bin'),native_rva=hex(FN),tool_sha256=sha(Path(__file__)),identity=identity(),formatted_sha256=sha(out/'formatted.txt'),fault_trace_sha256=fault_traces,fatal_code='0x220f10000001f7'))
  print(json.dumps({'cases':len(vals),'faults':sum(v[1]==-1 for v in vals)}))
  return
 if a.mode=='mql5':
  if (out/'mql5-results.bin').exists() or (out/'formatted.txt').exists():raise ValueError('MQL5_OUTPUT_EXISTS')
  normal=[r for r in rs if not native_fault_case(r)];receipt,script=verify_build(a.build);files,code,lines=run_mt5(a.run,normal)
  if code!=0 or not(files/'mql5-results.bin').is_file():raise RuntimeError('MQL5_CHECK_FAILED '+str(code))
  shutil.copyfile(files/'mql5-results.bin',out/'mql5-results.bin');shutil.copyfile(files/'formatted.txt',out/'formatted.txt');save(out/'mql5-run.json',dict(exit_code=code,cases=len(normal),script_sha256=sha(script),build_receipt_sha256=sha(receipt),result_sha256=sha(out/'mql5-results.bin'),formatted_sha256=sha(out/'formatted.txt'),identity=identity()));print(json.dumps({'cases':len(normal)}));return
 expected=read_results(out/'original-results.bin')
 if a.mode=='faults':
  _,script=verify_build(a.build);by={r['id']:r for r in rs};done=[]
  for v in expected:
   if v[1]!=-1:continue
   folder=out/'faults'/str(v[0]);folder.mkdir(parents=True,exist_ok=False);files,code,lines=run_mt5(a.run+'-fault-'+str(v[0]),[by[v[0]]],v[0])
   part=(files/'mql5-results.bin').read_bytes();trace=(files/'fault-trace.bin').read_bytes();native_trace=out/'native-fault-traces'/(str(v[0])+'.bin')
   header_ok=part==struct.pack('<4i',MAGIC,3,1,v[0]);trace_ok=trace==native_trace.read_bytes() and len(trace)==v[2]*24 and th(trace)==v[3]
   error_lines=[x for x in lines if 'zero divide' in x.lower() and 'Bot2VolumeValidationCheck' in x and 'Bot2VolumeValidation.mqh' in x]
   with (folder/'partial.bin').open('xb') as f:f.write(part)
   with (folder/'fault-trace.bin').open('xb') as f:f.write(trace)
   with (folder/'terminal.log').open('x',encoding='utf-8') as f:f.write('\n'.join(lines)+'\n')
   save(folder/'result.json',dict(id=v[0],original=list(v),partial_sha256=sha(folder/'partial.bin'),trace_sha256=sha(folder/'fault-trace.bin'),journal_sha256=sha(folder/'terminal.log'),error_lines=error_lines,exit_code=code,header_ok=header_ok,trace_ok=trace_ok,journal_ok=bool(error_lines),passed=header_ok and trace_ok and bool(error_lines) and code==4294967295,script_sha256=sha(script),exact_fault_state=False));done.append(v[0])
  print(json.dumps({'fault_cases':len(done)}));return
 run=json.loads((out/'mql5-run.json').read_text());orig=json.loads((out/'original-run.json').read_text())
 if run['result_sha256']!=sha(out/'mql5-results.bin') or run['formatted_sha256']!=sha(out/'formatted.txt') or orig['formatted_sha256']!=sha(out/'formatted.txt') or orig['result_sha256']!=sha(out/'original-results.bin') or run['identity']!=identity() or orig['identity']!=identity():raise ValueError('RESULT_IDENTITY_CHANGED')
 actual={v[0]:list(v) for v in read_results(out/'mql5-results.bin')};failed=[]
 for v in expected:
  if v[1]==-1:
   folder=out/'faults'/str(v[0]);p=folder/'result.json'
   if not p.is_file():failed.append(v[0]);continue
   fault=json.loads(p.read_text());part=folder/'partial.bin';trace=folder/'fault-trace.bin';journal=folder/'terminal.log';native_trace=out/'native-fault-traces'/(str(v[0])+'.bin')
   if (not fault['passed'] or fault['original']!=list(v) or fault['script_sha256']!=run['script_sha256'] or
       fault['partial_sha256']!=sha(part) or part.read_bytes()!=struct.pack('<4i',MAGIC,3,1,v[0]) or
       fault['trace_sha256']!=sha(trace) or sha(native_trace)!=orig['fault_trace_sha256'][str(v[0])] or trace.read_bytes()!=native_trace.read_bytes() or
       fault['journal_sha256']!=sha(journal) or not all(line in journal.read_text(encoding='utf-8').splitlines() for line in fault['error_lines'])):failed.append(v[0])
  elif list(v)!=actual.get(v[0]):failed.append(v[0])
 report=dict(cases=len(expected),matched=len(expected)-len(failed),failed=len(failed),fault_cases=sum(v[1]==-1 for v in expected),first_failures=failed[:20],normal_last_error_compared=True,full_print_text_checked=True,fatal_sdk_prefix_compared=True,exact_fault_state=False,scope='Bot2 native 0x3cfb0 versus MQL5; whole EA not covered.');save(out/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
