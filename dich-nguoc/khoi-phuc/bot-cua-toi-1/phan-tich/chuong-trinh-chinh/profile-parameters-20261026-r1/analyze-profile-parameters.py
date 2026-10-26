"""Bot1 native profile probe; no terminal calls and no MQL5."""
import argparse,hashlib,importlib.util,json,math,struct
from pathlib import Path
HOME=Path(__file__).resolve().parents[3]; ROOT=HOME.parent; TOOL=ROOT/'cong-cu'
def load(name,path):
 s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
entry=load('entry',TOOL/'kiem-gia-vao-bot-1-3.py'); settings=load('settings',TOOL/'kiem-dieu-chinh-bot-1-3.py')
# Keep this list identical to tests/check-runtime-profile.py.  The probe must
# not import that executable (or any MQL5 runtime) just to define its scope.
FIELDS=[
 ('reference','d'),('entry.confirmation_frame','i'),('entry.hour1_flag','i'),
 ('entry.older_width','i'),('entry.recent_width','i'),('entry.last_shift','i'),
 ('entry.gap_points','d'),('buy_offset','d'),('sell_offset','d'),
 ('nearby_radius','d'),('expiration_hours','i'),('stop_distance','d'),
 ('target_distance','d'),('trail_distance','d'),('trail_start','d'),
 ('trail_limit','d'),('trail_step','d'),('aux_hour1','i'),('aux_scan50','i'),
 ('aux_older','i'),('aux_recent','i'),('aux_offset','d')]
def canon(md,aliases,r):
 n=md.reg_name(r);return aliases.get(n,n)
def main():
 p=argparse.ArgumentParser();p.add_argument('run');p.add_argument('--amount',type=float,required=True);p.add_argument('--seed',type=int,required=True);p.add_argument('--adjustments',nargs=4,type=float,default=[0.,0.,0.,0.]);p.add_argument('--hl',type=int,choices=[0,1],required=True);a=p.parse_args()
 out=Path(__file__).parent/a.run;out.mkdir()
 o=entry.Original(1);m,x,base=o.m,o.x,o.base
 import capstone
 md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
 folder=HOME/'phan-tich/luot-20261023-data-v2';meta=json.loads((folder/'metadata/import.json').read_text());proof=json.loads((folder/'kiem-tham-so-goc.json').read_text())
 installed_ex5=Path.home()/'AppData/Roaming/MetaQuotes/Terminal/820755052E4765D7D56E6DAAFBB28091/MQL5/Experts/Market/Gold Trade Pro MT5.ex5'
 installed_ex5_sha256='a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922'
 if not installed_ex5.exists():raise FileNotFoundError('INSTALLED_EX5_NOT_FOUND '+str(installed_ex5))
 if hashlib.sha256(installed_ex5.read_bytes()).hexdigest()!=installed_ex5_sha256:raise ValueError('INSTALLED_EX5_SHA256_MISMATCH')
 fn=next(f for f in meta['functions'] if int(f['begin_rva'],16)<=0x12469<int(f['end_rva'],16));lo,hi=int(fn['begin_rva'],16),int(fn['end_rva'],16);code=bytes(m.mem_read(base+lo,hi-lo));ins={i.address:i for i in md.disasm(code,base+lo)}
 aliases={}
 for c,names in [('rax','eax ax al ah'),('rbx','ebx bx bl bh'),('rcx','ecx cx cl ch'),('rdx','edx dx dl dh'),('rsi','esi si sil'),('rdi','edi di dil'),('rbp','ebp bp bpl'),('rsp','esp sp spl')]:
  for n in [c,*names.split()]:aliases[n]=c
 for n in range(8,16):
  for s in ['','d','w','b']:aliases[f'r{n}{s}']=f'r{n}'
 settings_fields=settings.fields(settings.INPUTS,1)
 setting_by_name={n:(k,r) for n,k,r in settings_fields}
 fields=[(n,setting_by_name[n][0],setting_by_name[n][1]) for n,k in FIELDS]
 fieldmap={base+r:(n,k,r) for n,k,r in fields}
 required_bytes={base+r+j for n,k,r in fields for j in range(struct.calcsize('<'+k))}
 controls={0x6a5f0:a.amount,0x6a708:a.adjustments[0],0x6a710:a.adjustments[1],0x6a718:a.adjustments[2],0x6a720:a.adjustments[3]}
 rows=[]
 for prof in proof['profiles']:
  for region,raw in o.regions:
   if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
  for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
  for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
  m.reg_write(x.UC_X86_REG_RSP,0x50010000);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
  for r,v in controls.items():m.mem_write(base+r,struct.pack('<d',v))
  m.mem_write(base+0x6a478,struct.pack('<I',a.seed));m.mem_write(base+0x6a5d0,bytes([a.hl]))
  defined={'rsp','eflags','mxcsr'}
  prep=prof['immediate_load_rvas']+prof['reaching_constant_definition_rvas']
  # The earlier proof contains the only constant preloads required by profiles 1 and 5.
  preload_details=[]
  def preload(rva,reg,imm):
   i=ins[base+rva];q=i.operands
   if i.mnemonic not in ('mov','movabs') or len(q)!=2 or q[0].type!=capstone.CS_OP_REG or q[1].type!=capstone.CS_OP_IMM or md.reg_name(q[0].reg).lower()!=reg or q[1].imm!=imm:
    raise ValueError('BAD_NATIVE_PRELOAD '+hex(rva))
   m.emu_start(i.address,i.address+i.size,count=1)
   changed=[canon(md,aliases,r) for r in i.regs_access()[1]]
   defined.update(changed)
   preload_details.append({'rva':hex(rva),'opcode':i.mnemonic,'operands':i.op_str,'defined':changed})
  for rv in prep:
   i=ins[base+int(rv,16)];m.emu_start(i.address,i.address+i.size,count=1);defined.update(canon(md,aliases,r) for r in i.regs_access()[1])
  if prof['index']==1: preload(0x12f54,'r9',0x4034000000000000)
  if prof['index']==5: preload(0x14eb1,'r8',base+0x4ff00)
  trace=[];writes=[];written=set();scope_written=set();live={};read_before_write=[];stop=[];stop_details=None;float_regs={};memory_expr={};random_order=[];calls={z for z,i in ins.items() if i.mnemonic=='call'};pending_stop=False
  def addr(op):
   v=op.mem;z=v.disp
   for r,scale in [(v.base,1),(v.index,v.scale)]:
    if r:z+=m.reg_read(getattr(x,'UC_X86_REG_'+md.reg_name(r).upper()))*scale
   return z
  def expr(op):
   if op.type==capstone.CS_OP_REG:return float_regs.get(md.reg_name(op.reg),['u',md.reg_name(op.reg)])
   z=addr(op)
   if z in fieldmap and fieldmap[z][1]=='d':return ['v',fieldmap[z][0]]
   if z in memory_expr:return memory_expr[z]
   try:raw=bytes(m.mem_read(z,8)).hex()
   except Exception:raw='unmapped:'+hex(z)
   return ['k',raw]
  def step(i):
   q=i.operands
   if not q:return
   if i.mnemonic in ['xorps','xorpd'] and q[0].type==q[1].type==capstone.CS_OP_REG and q[0].reg==q[1].reg:float_regs[md.reg_name(q[0].reg)]=['k','0000000000000000'];return
   if i.mnemonic in ['addsd','subsd','mulsd']:
    float_regs[md.reg_name(q[0].reg)]=[{'addsd':'+','subsd':'-','mulsd':'*'}[i.mnemonic],expr(q[0]),expr(q[1])];return
   if i.mnemonic=='cvtsi2sd':
    random_order.append({'ordinal':len(random_order)+1,'word':m.reg_read(getattr(x,'UC_X86_REG_'+md.reg_name(q[1].reg).upper()))});float_regs[md.reg_name(q[0].reg)]=['r',len(random_order)];return
   if i.mnemonic in ['movsd','movapd']:
    if q[0].type==capstone.CS_OP_REG:float_regs[md.reg_name(q[0].reg)]=expr(q[1])
    else:memory_expr[addr(q[0])]=expr(q[1])
   if i.mnemonic in ['mov','movabs'] and q[0].type==capstone.CS_OP_MEM and q[0].size==8:
    src=q[1];value=src.imm if src.type==capstone.CS_OP_IMM else m.reg_read(getattr(x,'UC_X86_REG_'+md.reg_name(src.reg).upper())) if src.type==capstone.CS_OP_REG else 0
    memory_expr[addr(q[0])]=['k',struct.pack('<Q',value&0xffffffffffffffff).hex()]
  def visit(em,address,size,user):
   nonlocal pending_stop,stop_details
   if pending_stop:
    stop_details={'reason':'required_fields_complete','rva':hex(address-base),'ordinal':len(trace)+1};em.emu_stop();return
   if address in calls:stop.append(address);stop_details={'reason':'first_call','rva':hex(address-base),'ordinal':len(trace)+1};em.emu_stop();return
   if address not in ins:raise ValueError('LEFT_FUNCTION '+hex(address-base))
   i=ins[address];trace.append(address);read,changed=i.regs_access();zero=i.mnemonic in ['xor','xorpd','xorps','pxor'] and len(i.operands)==2 and all(q.type==capstone.CS_OP_REG for q in i.operands) and i.operands[0].reg==i.operands[1].reg
   for r in read:
    n=canon(md,aliases,r)
    if not zero and n not in defined:
     event={'register':n,'rva':hex(address-base),'ordinal':len(trace)};read_before_write.append(event);live.setdefault(n,hex(address-base));raise ValueError('READ_BEFORE_WRITE '+json.dumps(event))
   defined.update(canon(md,aliases,r) for r in changed);step(i)
  def store(em,access,address,size,value,user):
   z=address-base
   if z in [r for _,_,r in fields] or (0x62200<=z<=0x62380):
    ordinal=len(trace);before=bytes(m.mem_read(address,size));new_bits=((value & ((1<<(size*8))-1)).to_bytes(size,'little').hex() if size<=8 else None);writes.append({'rva':hex(z),'size':size,'before_bits':before.hex(),'bits':new_bits,'instruction':hex(em.reg_read(x.UC_X86_REG_RIP)-base),'instruction_ordinal':ordinal,'expression':memory_expr.get(address)});written.update(range(address,address+size))
    scope_written.update(range(address,address+size))
    if required_bytes.issubset(written):
     nonlocal pending_stop
     pending_stop=True
  h1=m.hook_add(o.uc.UC_HOOK_CODE,visit);h2=m.hook_add(o.uc.UC_HOOK_MEM_WRITE,store)
  try:m.emu_start(base+int(prof['start_rva'],16),0x60000000,count=20000)
  finally:m.hook_del(h1);m.hook_del(h2)
  missing=sorted(hex(z-base) for z in required_bytes-set(written))
  if missing: raise ValueError('MISSING_REQUIRED_FIELD_BYTES '+','.join(missing))
  values={n:struct.unpack('<'+k,m.mem_read(base+r,struct.calcsize('<'+k)))[0] for n,k,r in fields if k in ['d','i','B'] and all(base+r+j in written for j in range(struct.calcsize('<'+k)))}
  raw_fields={n:bytes(m.mem_read(base+r,struct.calcsize('<'+k))).hex() for n,k,r in fields if all(base+r+j in written for j in range(struct.calcsize('<'+k)))}
  field_write_ordinals=[w['instruction_ordinal'] for w in writes if any(base+int(w['rva'],16)+j in required_bytes for j in range(w['size']))]
  last_profile_write=max(field_write_ordinals) if field_write_ordinals else -1
  unresolved_before={event['register']:event['rva'] for event in read_before_write if event['ordinal']<=last_profile_write}
  rows.append(dict(index=prof['index'],hl=a.hl,start_rva=prof['start_rva'],first_call_rva=hex(stop[0]-base) if stop else None,stop_details=stop_details,seed_before=a.seed,seed_after=struct.unpack('<I',m.mem_read(base+0x6a478,4))[0],values=values,raw_fields=raw_fields,writes=writes,required_field_count=len(FIELDS),required_field_bytes_written=len(required_bytes & written),scope_write_bytes=len(scope_written),preload_details=preload_details,read_before_write_events=read_before_write,random_word_conversion_order=random_order,float_expressions={n:memory_expr.get(base+r) for n,k,r in fields if k=='d' and base+r in memory_expr},unresolved_registers=live,unresolved_before_last_profile_write=unresolved_before,last_profile_write_ordinal=last_profile_write,instructions=[hex(z-base) for z in trace]))
 report=dict(bot=1,run=a.run,amount=a.amount,seed=a.seed,hl=a.hl,adjustments=a.adjustments,input_controls={'amount':a.amount,'seed':a.seed,'hl':a.hl,'adjustments':a.adjustments},function_begin=hex(lo),function_end_exclusive=hex(hi),function_sha256=hashlib.sha256(code).hexdigest(),native_code_sha256=meta['code_sha256'],installed_ex5_sha256=hashlib.sha256(installed_ex5.read_bytes()).hexdigest(),tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),rows=rows,scope='Native profile blocks through first original call or the next instruction after all 22 required fields are written; no terminal calls and no expected-value injection.')
 (out/'native-profiles.json').write_text(json.dumps(report,indent=2,allow_nan=True),encoding='utf-8');(out/Path(__file__).name).write_bytes(Path(__file__).read_bytes());print(json.dumps({'rows':len(rows),'random_counts':[len(r['random_word_conversion_order']) for r in rows],'unresolved':[r['unresolved_registers'] for r in rows]}))
if __name__=='__main__':main()
