"""Bot1 native profile probe; no terminal calls and no MQL5."""
import argparse,hashlib,importlib.util,json,math,struct
from pathlib import Path
HOME=Path(__file__).resolve().parents[3]; ROOT=HOME.parent; TOOL=ROOT/'cong-cu'
def load(name,path):
 s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
entry=load('entry',TOOL/'kiem-gia-vao-bot-1-3.py'); settings=load('settings',TOOL/'kiem-dieu-chinh-bot-1-3.py')
def canon(md,aliases,r):
 n=md.reg_name(r);return aliases.get(n,n)
def main():
 p=argparse.ArgumentParser();p.add_argument('run');p.add_argument('--amount',type=float,required=True);p.add_argument('--seed',type=int,required=True);p.add_argument('--adjustments',nargs=4,type=float,default=[0.,0.,0.,0.]);p.add_argument('--hl',type=int,choices=[0,1],required=True);a=p.parse_args()
 out=Path(__file__).parent/a.run;out.mkdir()
 o=entry.Original(1);m,x,base=o.m,o.x,o.base
 import capstone
 md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
 folder=HOME/'phan-tich/luot-20261023-data-v2';meta=json.loads((folder/'metadata/import.json').read_text());proof=json.loads((folder/'kiem-tham-so-goc.json').read_text())
 fn=next(f for f in meta['functions'] if int(f['begin_rva'],16)<=0x12469<int(f['end_rva'],16));lo,hi=int(fn['begin_rva'],16),int(fn['end_rva'],16);code=bytes(m.mem_read(base+lo,hi-lo));ins={i.address:i for i in md.disasm(code,base+lo)}
 aliases={}
 for c,names in [('rax','eax ax al ah'),('rbx','ebx bx bl bh'),('rcx','ecx cx cl ch'),('rdx','edx dx dl dh'),('rsi','esi si sil'),('rdi','edi di dil'),('rbp','ebp bp bpl'),('rsp','esp sp spl')]:
  for n in [c,*names.split()]:aliases[n]=c
 for n in range(8,16):
  for s in ['','d','w','b']:aliases[f'r{n}{s}']=f'r{n}'
 fields=settings.fields(settings.INPUTS,1);fieldmap={base+r:(n,k,r) for n,k,r in fields}
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
  defined={'rsp'}
  prep=prof['immediate_load_rvas']+prof['reaching_constant_definition_rvas']
  if a.hl and False: prep=[]
  # The earlier proof contains the only constant preloads required by profiles 1 and 5.
  for rv in prep:
   i=ins[base+int(rv,16)];m.emu_start(i.address,i.address+i.size,count=1);defined.update(canon(md,aliases,r) for r in i.regs_access()[1])
  trace=[];writes=[];written=set();live={};stop=[];float_regs={};memory_expr={};random_order=[];calls={z for z,i in ins.items() if i.mnemonic=='call'}
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
   if address in calls:stop.append(address);em.emu_stop();return
   if address not in ins:raise ValueError('LEFT_FUNCTION '+hex(address-base))
   i=ins[address];trace.append(address);read,changed=i.regs_access();zero=i.mnemonic in ['xor','xorpd','xorps','pxor'] and len(i.operands)==2 and all(q.type==capstone.CS_OP_REG for q in i.operands) and i.operands[0].reg==i.operands[1].reg
   for r in read:
    n=canon(md,aliases,r)
    if not zero and n not in defined:live[n]=hex(address-base)
   defined.update(canon(md,aliases,r) for r in changed);step(i)
  def store(em,access,address,size,value,user):
   z=address-base
   if z in [r for _,_,r in fields] or (0x62200<=z<=0x62380):
    raw=bytes(m.mem_read(address,size));writes.append({'rva':hex(z),'size':size,'bits':raw.hex(),'instruction':hex(em.reg_read(x.UC_X86_REG_RIP)-base),'expression':memory_expr.get(address)});written.update(range(address,address+size))
  h1=m.hook_add(o.uc.UC_HOOK_CODE,visit);h2=m.hook_add(o.uc.UC_HOOK_MEM_WRITE,store)
  try:m.emu_start(base+int(prof['start_rva'],16),0x60000000,count=20000)
  finally:m.hook_del(h1);m.hook_del(h2)
  values={n:struct.unpack('<'+k,m.mem_read(base+r,struct.calcsize('<'+k)))[0] for n,k,r in fields if k in ['d','i','B'] and all(base+r+j in written for j in range(struct.calcsize('<'+k)))}
  rows.append(dict(index=prof['index'],hl=a.hl,start_rva=prof['start_rva'],first_call_rva=hex(stop[0]-base) if stop else None,seed_before=a.seed,seed_after=struct.unpack('<I',m.mem_read(base+0x6a478,4))[0],values=values,writes=writes,random_word_conversion_order=random_order,float_expressions={n:memory_expr.get(base+r) for n,k,r in fields if k=='d' and base+r in memory_expr},unresolved_registers=live,instructions=[hex(z-base) for z in trace]))
 report=dict(bot=1,run=a.run,amount=a.amount,seed=a.seed,hl=a.hl,adjustments=a.adjustments,function_begin=hex(lo),function_end_exclusive=hex(hi),function_sha256=hashlib.sha256(code).hexdigest(),tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),rows=rows,scope='Native profile blocks through first original call; no terminal calls and no expected-value injection.')
 (out/'native-profiles.json').write_text(json.dumps(report,indent=2,allow_nan=True),encoding='utf-8');(out/Path(__file__).name).write_bytes(Path(__file__).read_bytes());print(json.dumps({'rows':len(rows),'random_counts':[len(r['random_word_conversion_order']) for r in rows],'unresolved':[r['unresolved_registers'] for r in rows]}))
if __name__=='__main__':main()
