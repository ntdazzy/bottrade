"""Read-only native profile-parameter probe, ending after all declared scalar writes.
RUN --amount VALUE --seed UINT [--adjustments PRICE STOP TARGET TRAIL AUX LOCK]
No terminal API or full strategy is executed; each run has a new evidence directory.
"""
import argparse,hashlib,importlib.util,json,re,struct
from pathlib import Path
HOME=Path(__file__).resolve().parents[3];ROOT=HOME.parent
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
entry=module('profile_original',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py')
settings=module('profile_fields',ROOT/'cong-cu/kiem-dieu-chinh-bot-1-3.py')
def require(value,message):
    if not value:raise ValueError(message)
def sha(raw):return hashlib.sha256(raw).hexdigest()
def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('run');parser.add_argument('--amount',type=float,required=True);parser.add_argument('--seed',type=int,required=True);parser.add_argument('--adjustments',nargs=6,type=float,default=[0.]*6);parser.add_argument('--expressions',action='store_true');args=parser.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,50}',args.run) and 0<=args.seed<=0xffffffff,'BAD_RUN_OR_SEED')
    output=Path(__file__).parent/args.run;require(not output.exists(),'OUTPUT_EXISTS')
    oracle=entry.Original(3);m,x,base=oracle.m,oracle.x,oracle.base;require(base==0x17156250000,'CAPTURE_BASE_DIFFERS')
    import capstone
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
    folder=HOME/'phan-tich/luot-20261023-data';metadata=json.loads((folder/'metadata/import.json').read_text());proof=json.loads((folder/'kiem-tham-so-goc.json').read_text())
    function=next(f for f in metadata['functions'] if int(f['begin_rva'],16)==0x17f00);lo,hi=int(function['begin_rva'],16),int(function['end_rva'],16)
    code=bytes(m.mem_read(base+lo,hi-lo));instructions={i.address:i for i in md.disasm(code,base+lo)}
    aliases={}
    for canonical,names in [('rax','eax ax al ah'),('rbx','ebx bx bl bh'),('rcx','ecx cx cl ch'),('rdx','edx dx dl dh'),('rsi','esi si sil'),('rdi','edi di dil'),('rbp','ebp bp bpl'),('rsp','esp sp spl')]:
        for name in [canonical,*names.split()]:aliases[name]=canonical
    for n in range(8,16):
        for suffix in ['','d','w','b']:aliases['r'+str(n)+suffix]='r'+str(n)
    canonical=lambda reg:aliases.get(md.reg_name(reg),md.reg_name(reg))
    rows=[];fields=settings.fields(settings.INPUTS,3)
    baseline=json.loads((HOME/'bang-chung/kiem-dieu-chinh/settings-20261023-r2/native-profiles.json').read_text())
    required={base+off+i for name,kind,off in baseline['fields'] for i in range(struct.calcsize('<'+kind))}
    required.update(base+off+i for off in [0x6d170,0x6d174,0x6d2e0,0x6d2e4,0x6d324,0x6d3c0] for i in range(4))
    controls=dict(zip([0x1d6fd0,0x1d70e8,0x1d70f0,0x1d70f8,0x1d7100,0x1d7108,0x1d7110],[args.amount,*args.adjustments]))
    variable_names=dict(zip(controls,['randomization','price_delta','stop_delta','target_delta','trail_delta','aux_delta','lock_delta']))
    random_words={};working_seed=args.seed
    for ordinal in range(1,12):
        working_seed=(working_seed*214013+2531011)&0xffffffff;word=(working_seed>>16)&32767
        require(not args.expressions or word not in random_words,'EXPRESSION_PROBE_REQUIRES_DISTINCT_RANDOM_WORDS');random_words[word]=ordinal
    for profile in proof['profiles']:
        for region,raw in oracle.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        m.reg_write(x.UC_X86_REG_RSP,0x50010000);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        for off,value in controls.items():m.mem_write(base+off,struct.pack('<d',value))
        m.mem_write(base+0x1d6e78,struct.pack('<I',args.seed))
        # These original immediate loads were proven in the earlier six-field inventory.
        defined={'rsp'}
        for off in profile['immediate_load_rvas']+profile['reaching_constant_definition_rvas']:
            i=instructions[base+int(off,16)];m.emu_start(i.address,i.address+i.size,count=1);defined.update(canonical(r) for r in i.regs_access()[1])
        trace=[];writes=[];written=set();live={};stop=[];stop_next=[False];float_regs={};memory_expr={};converted=[]
        def address_of(operand):
            value=operand.mem;require(not value.segment,'SEGMENTED_EXPRESSION_MEMORY')
            address=value.disp
            for reg,scale in [(value.base,1),(value.index,value.scale)]:
                if reg:address+=m.reg_read(getattr(x,'UC_X86_REG_'+md.reg_name(reg).upper()))*scale
            return address
        def operand_expr(operand):
            if operand.type==capstone.CS_OP_REG:
                name=md.reg_name(operand.reg);require(name in float_regs,'UNKNOWN_FLOAT_EXPRESSION '+name);return float_regs[name]
            require(operand.type==capstone.CS_OP_MEM,'UNSUPPORTED_FLOAT_EXPRESSION')
            address=address_of(operand);off=address-base
            if off in variable_names:return ['v',variable_names[off]]
            return memory_expr.get(address,['k',bytes(m.mem_read(address,8)).hex()])
        def expression_step(i):
            operands=i.operands
            if not operands:return
            if i.mnemonic in ['xorps','xorpd'] and operands[0].type==capstone.CS_OP_REG and operands[1].type==capstone.CS_OP_REG and operands[0].reg==operands[1].reg:
                float_regs[md.reg_name(operands[0].reg)]=['k','0000000000000000'];return
            if i.mnemonic in ['addsd','subsd','mulsd']:
                left,right=operand_expr(operands[0]),operand_expr(operands[1]);float_regs[md.reg_name(operands[0].reg)]=[{'addsd':'+','subsd':'-','mulsd':'*'}[i.mnemonic],left,right];return
            if i.mnemonic=='cvtsi2sd':
                source=operands[1];require(source.type==capstone.CS_OP_REG,'NONREGISTER_RANDOM_CONVERSION');value=m.reg_read(getattr(x,'UC_X86_REG_'+md.reg_name(source.reg).upper()));require(value in random_words,'UNRECOGNIZED_RANDOM_WORD');ordinal=random_words[value];converted.append(ordinal);float_regs[md.reg_name(operands[0].reg)]=['r',ordinal];return
            if i.mnemonic in ['movsd','movapd']:
                if operands[0].type==capstone.CS_OP_REG:float_regs[md.reg_name(operands[0].reg)]=operand_expr(operands[1])
                else:memory_expr[address_of(operands[0])]=operand_expr(operands[1])
                return
            if i.mnemonic in ['mov','movabs'] and operands[0].type==capstone.CS_OP_MEM and operands[0].size==8:
                source=operands[1]
                if source.type==capstone.CS_OP_IMM:value=source.imm
                elif source.type==capstone.CS_OP_REG:value=m.reg_read(getattr(x,'UC_X86_REG_'+md.reg_name(source.reg).upper()))
                else:raise ValueError('UNSUPPORTED_LITERAL_STORE')
                memory_expr[address_of(operands[0])]=['k',struct.pack('<Q',value&0xffffffffffffffff).hex()]
        def visit(em,address,size,user):
            if stop_next[0]:stop.append(address);em.emu_stop();return
            require(address in instructions,'LEFT_PROFILE_CALLER');i=instructions[address]
            require(i.mnemonic!='call','CALL_BEFORE_SCALAR_SETTINGS_COMPLETE');trace.append(address)
            read,changed=i.regs_access();zero=i.mnemonic in ['xor','xorpd','xorps','pxor'] and len(i.operands)==2 and all(o.type==capstone.CS_OP_REG for o in i.operands) and i.operands[0].reg==i.operands[1].reg
            for reg in read:
                name=canonical(reg)
                if not zero and name not in defined:live[name]=hex(address-base)
            defined.update(canonical(r) for r in changed)
            if args.expressions:expression_step(i)
        def store(em,access,address,size,value,user):
            off=address-base
            if 0x6d000<=off<0x6d660 or off==0x1d6e78:
                writes.append(dict(rva=hex(off),size=size,value_bits=hex(value&((1<<(size*8))-1)),instruction=hex(em.reg_read(x.UC_X86_REG_RIP)-base)));written.update(range(address,address+size))
            if required.issubset(written):stop_next[0]=True
        a=m.hook_add(oracle.uc.UC_HOOK_CODE,visit);b=m.hook_add(oracle.uc.UC_HOOK_MEM_WRITE,store)
        try:m.emu_start(base+int(profile['start_rva'],16),0x60000000,count=20000)
        finally:m.hook_del(a);m.hook_del(b)
        require(stop and not live,'UNRESOLVED_PROFILE_CONTEXT '+str(live))
        values={name:struct.unpack('<'+kind,m.mem_read(base+off,struct.calcsize('<'+kind)))[0] for name,kind,off in fields if all(base+off+i in written for i in range(struct.calcsize('<'+kind)))}
        raw_fields={}
        for item in writes:
            off,size=int(item['rva'],16),item['size'];raw=bytes(m.mem_read(base+off,size));raw_fields[item['rva']+':'+str(size)]={'bits':raw.hex(),'as_unsigned':int.from_bytes(raw,'little'),'as_double':struct.unpack('<d',raw)[0] if size==8 else None}
        expressions={name:memory_expr[base+off] for name,kind,off in fields if kind=='d' and base+off in memory_expr}
        if args.expressions:require(sorted(converted)==(list(range(1,12)) if args.amount>0 else []),'RANDOM_WORD_CONVERSIONS_DIFFER')
        rows.append(dict(index=profile['index'],start_rva=profile['start_rva'],stop_before_rva=hex(stop[0]-base),seed_before=args.seed,seed_after=struct.unpack('<I',m.mem_read(base+0x1d6e78,4))[0],values=values,raw_fields=raw_fields,writes=writes,instructions=[hex(v-base) for v in trace],unresolved_registers=live,float_expressions=expressions,random_word_conversion_order=converted))
    report=dict(bot=3,run=args.run,randomization=args.amount,seed=args.seed,adjustments=args.adjustments,controls={hex(k):v for k,v in controls.items()},function_begin=hex(lo),function_end_exclusive=hex(hi),function_sha256=sha(code),coefficient_bits=bytes(m.mem_read(base+0x57f28,8)).hex(),coefficient=struct.unpack('<d',m.mem_read(base+0x57f28,8))[0],tool_sha256=sha(Path(__file__).read_bytes()),prior_entry_proof_sha256=sha((folder/'kiem-tham-so-goc.json').read_bytes()),required_scalar_bytes=len(required),rows=rows,whole_bot_complete=False,scope='Native profile assignments through the25 original distance fields and6 additional scalar fields; no terminal calls or symbol/currency/magic selection, preparation or strategy main. Controls fixed during each call. No expected outputs calculated.')
    output.mkdir()
    with (output/'native-profiles.json').open('x',encoding='utf-8') as f:json.dump(report,f,indent=2)
    with (output/Path(__file__).name).open('xb') as f:f.write(Path(__file__).read_bytes())
    print(json.dumps(dict(profiles=len(rows),seed_after=[r['seed_after'] for r in rows],fields=[len(r['values']) for r in rows],stop=[r['stop_before_rva'] for r in rows])))
if __name__=='__main__':main()
