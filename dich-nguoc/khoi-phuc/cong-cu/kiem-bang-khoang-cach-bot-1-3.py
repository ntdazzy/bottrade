"""Recover the base distance profiles, including both bot 1 HL settings.
Does not validate enable selection, randomization or user adjustments.
"""
import importlib.util,json,struct,argparse,hashlib,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser(description="Verify base distance profiles with native instructions; adjustments and randomization are zero.")
parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('run');args=parser.parse_args()
if not re.fullmatch('[a-z0-9-]+',args.run):raise ValueError('INVALID_RUN')
target=ROOT/f'bot-cua-toi-{args.bot}/bang-chung/kiem-dieu-chinh'/args.run/'native-profiles.json'
if target.exists():raise FileExistsError(target)
s=importlib.util.spec_from_file_location('settings',ROOT/'cong-cu/kiem-dieu-chinh-bot-1-3.py');d=importlib.util.module_from_spec(s);s.loader.exec_module(d)
for bot in [args.bot]:
    o=d.Original(bot);m,x=o.m,o.x
    import capstone
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
    folder=ROOT/f'bot-cua-toi-{bot}/phan-tich'/('luot-20261023-data-v2' if bot==1 else 'luot-20261023-data')
    proof=json.loads((folder/'kiem-tham-so-goc.json').read_text());meta=json.loads((folder/'metadata/import.json').read_text())
    code=next(raw for region,raw in o.regions if region['base']==o.base)
    function=next(f for f in meta['functions'] if int(f['begin_rva'],16)<=int(proof['profiles'][0]['start_rva'],16)<int(f['end_rva'],16))
    lo,hi=int(function['begin_rva'],16),int(function['end_rva'],16)
    instructions=list(md.disasm(code[lo:hi],o.base+lo));ins={v.address:v for v in instructions}
    address_index={v.address:i for i,v in enumerate(instructions)}
    predecessors=[[] for _ in instructions]
    indirect_jump=False
    for i,v in enumerate(instructions):
        dest=[]
        if v.mnemonic.startswith('j'):
            if v.operands[0].type!=capstone.CS_OP_IMM:indirect_jump=True
            elif v.operands[0].imm in address_index:dest.append(address_index[v.operands[0].imm])
            if v.mnemonic!='jmp' and i+1<len(instructions):dest.append(i+1)
        elif not v.mnemonic.startswith('ret') and i+1<len(instructions):dest.append(i+1)
        for destination in dest:predecessors[destination].append(i)
    aliases={}
    for canonical,names in [('rax','eax ax al ah'),('rbx','ebx bx bl bh'),('rcx','ecx cx cl ch'),('rdx','edx dx dl dh'),('rsi','esi si sil'),('rdi','edi di dil'),('rbp','ebp bp bpl'),('rsp','esp sp spl')]:
        for name in [canonical,*names.split()]:aliases[name]=canonical
    for n in range(8,16):
        for suffix in ['','d','w','b']:aliases[f'r{n}{suffix}']=f'r{n}'
    def canonical(reg):
        name=md.reg_name(reg);return aliases.get(name,name)
    def definitions(at,register):
        if indirect_jump:raise ValueError('INDIRECT_JUMP_PREVENTS_DATAFLOW_PROOF')
        wanted=canonical(register);pending=list(predecessors[address_index[at]]);seen=set();found={}
        while pending:
            i=pending.pop()
            if i in seen:continue
            seen.add(i);v=instructions[i]
            if v.mnemonic=='call' and wanted in ['rax','rcx','rdx','r8','r9','r10','r11',*[f'xmm{n}' for n in range(6)]]:raise ValueError('UNKNOWN_CALL_VALUE '+wanted)
            if any(canonical(r)==wanted for r in v.regs_access()[1]):
                if v.mnemonic in ['mov','movabs'] and v.operands[0].type==capstone.CS_OP_REG and v.operands[1].type==capstone.CS_OP_IMM:
                    found[v.address]=v.operands[1].imm&((1<<(v.operands[0].size*8))-1);continue
                if v.mnemonic in ['xor','xorps','xorpd','pxor'] and v.operands[0].type==capstone.CS_OP_REG and v.operands[1].type==capstone.CS_OP_REG and v.operands[0].reg==v.operands[1].reg:
                    found[v.address]=0;continue
                raise ValueError('NON_CONSTANT_DEFINITION '+wanted+' '+hex(v.address-o.base))
            if not predecessors[i]:raise ValueError('FUNCTION_ENTRY_DEPENDENCY '+wanted)
            pending.extend(predecessors[i])
        if not found or len(set(found.values()))!=1:raise ValueError('MULTIPLE_REACHING_VALUES '+wanted+' '+str(found))
        return list(found)
    calls={addr for addr,v in ins.items() if v.mnemonic=='call'};rows=[]
    for p in proof['profiles']:
        for hl in [0,1] if bot==1 else [0]:
            for region,raw in o.regions:
                if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
            for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
            for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
            m.reg_write(x.UC_X86_REG_RSP,0x50010000)
            controls={0x6a5f0:0.,0x6a708:0.,0x6a710:0.,0x6a718:0.,0x6a720:0.} if bot==1 else {0x1d6fd0:0.,0x1d70e8:0.,0x1d70f0:0.,0x1d70f8:0.,0x1d7100:0.,0x1d7108:0.,0x1d7110:0.}
            for rva,value in controls.items():m.mem_write(o.base+rva,struct.pack('<d',value))
            m.mem_write(o.base+(0x6a628 if bot==1 else 0x1d7008),b'\1')
            if bot==1:m.mem_write(o.base+0x6a5d0,bytes([hl]))
            register={1:capstone.x86_const.X86_REG_R9,5:capstone.x86_const.X86_REG_R8}.get(p['index']) if bot==1 else None
            extra=definitions(o.base+int(p['start_rva'],16),register) if register else []
            for v in p['immediate_load_rvas']+p['reaching_constant_definition_rvas']+[hex(v-o.base) for v in extra[:1]]:
                addr=o.base+int(v,16);m.emu_start(addr,addr+ins[addr].size,count=1)
            seen=set();halt=[];trace=[];defined={'rsp'};live={}
            for v in p['immediate_load_rvas']+p['reaching_constant_definition_rvas']+[hex(v-o.base) for v in extra[:1]]:
                defined.update(canonical(reg) for reg in ins[o.base+int(v,16)].regs_access()[1])
            def stop(em,address,size,user):
                trace.append(address)
                if address in calls:halt.append(address);em.emu_stop();return
                v=ins[address];read,written=v.regs_access()
                zero=v.mnemonic in ['xor','xorps','xorpd','pxor'] and len(v.operands)==2 and all(op.type==capstone.CS_OP_REG for op in v.operands) and v.operands[0].reg==v.operands[1].reg
                for reg in read:
                    name=canonical(reg)
                    if not zero and name not in defined:live[name]=reg
                defined.update(canonical(reg) for reg in written)
            def write(em,access,address,size,value,user):seen.update(range(address,address+size))
            a=m.hook_add(o.uc.UC_HOOK_CODE,stop);b=m.hook_add(o.uc.UC_HOOK_MEM_WRITE,write)
            try:m.emu_start(o.base+int(p['start_rva'],16),0x60000000,count=20000)
            except o.uc.UcError as error:
                print('FAULT',bot,p['index'],hl,error)
                for addr in trace[-18:]:print(hex(addr-o.base),ins[addr].mnemonic,ins[addr].op_str)
                print({name:hex(m.reg_read(getattr(x,'UC_X86_REG_'+name))) for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']})
                raise
            finally:m.hook_del(a);m.hook_del(b)
            if not halt:raise ValueError('NO_CALL_STOP')
            actual={}
            for name,kind,rva in d.fields(d.INPUTS,bot):
                size=struct.calcsize('<'+kind)
                if all(o.base+rva+i in seen for i in range(size)):actual[name]=struct.unpack('<'+kind,m.mem_read(o.base+rva,size))[0]
            live_proof={name:[hex(v-o.base) for v in definitions(o.base+int(p['start_rva'],16),reg)] for name,reg in live.items()}
            if live_proof:raise ValueError('UNSEEDED_LIVE_IN '+str(live_proof))
            rows.append(dict(index=p['index'],hl=hl,first_call_rva=hex(halt[0]-o.base),live_in_definitions=live_proof,extra_definitions=[hex(v-o.base) for v in extra],values=actual))
    names=list(rows[0]['values'])
    if any(list(row['values'])!=names for row in rows):raise ValueError('PROFILE_FIELDS_DIFFER')
    previous={row['index']:row['values'] for row in proof['profiles']}
    for row in rows:
        for key,old in [('confirmation_frame','confirm_tf'),('older_width','older'),('recent_width','recent'),('last_shift','scan'),('gap_points','gap'),('hour1_flag' if bot==1 else 'entry_frame','entry_h1' if bot==1 else 'entry_tf')]:
            if row['values']['entry.'+key]!=previous[row['index']][old]:raise ValueError('PREVIOUS_PROFILE_PROOF_DIFFERS')
    result={'bot':bot,'rows':rows,'fields':[(n,k,rva) for n,k,rva in d.fields(d.INPUTS,bot) if n in names],
        'code_sha256':meta['code_sha256'],'data_sha256':meta['data_sha256'],
        'previous_proof_sha256':hashlib.sha256((folder/'kiem-tham-so-goc.json').read_bytes()).hexdigest(),
        'tool_sha256':hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        'scope':'Native parameter assignment blocks up to first call, zero adjustments/randomization, both HL branches for bot 1. All compared fields were written; all read registers initialized within block or proven by constant reaching definitions. Bot 3 reference is set later and excluded.'}
    target.parent.mkdir(parents=True,exist_ok=True)
    target.write_text(json.dumps(result,indent=2),encoding='utf-8')
    print(json.dumps({'bot':bot,'rows':len(rows),'fields_per_row':len(names),'unresolved_registers':0}))
