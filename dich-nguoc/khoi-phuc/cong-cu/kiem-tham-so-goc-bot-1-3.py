"""Verify observed strategy constants by executing native assignment prefixes.

Usage: python -I -B -X utf8 kiem-tham-so-goc-bot-1-3.py
Only straight-line parameter assignments are executed, with no external calls.
This does not validate strategy selection, dynamic scaling or full entry rules.
"""
import importlib.util
import argparse
import json
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('price_check',Path(__file__).with_name('kiem-muc-gia-bot-1-3.py'))
check=importlib.util.module_from_spec(spec);spec.loader.exec_module(check)
SPECS=[(1,'luot-20261023-data-v2',0x7500,{'confirm_tf':0x6227c,'entry_h1':0x62280,'older':0x62284,'recent':0x62288,'scan':0x6228c,'gap':0x62290}),
       (3,'luot-20261023-data',0xe0c0,{'confirm_tf':0x6d2b4,'entry_tf':0x6d2b8,'older':0x6d2bc,'recent':0x6d2c0,'scan':0x6d2c4,'gap':0x6d2c8})]

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--bot',type=int,choices=[1,3]);args=parser.parse_args()
    for bot,run,setup,fields in SPECS:
        if args.bot is not None and args.bot!=bot:continue
        folder=ROOT/f'bot-cua-toi-{bot}/phan-tich'/run
        output=folder/'kiem-tham-so-goc.json'
        if output.exists():raise FileExistsError(output)
        table=json.loads((folder/'noi-tham-so-muc-gia.json').read_text())
        expected_rows=[r for r in table['rows'] if r['fields']]
        original=check.Original(bot);machine,x=original.m,original.x;base=original.base
        import capstone
        code=next(raw for region,raw in original.regions if region['base']==base)
        metadata=json.loads((folder/'metadata/import.json').read_text())
        md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
        parents=[]
        for function in metadata['functions']:
            lo,hi=int(function['begin_rva'],16),int(function['end_rva'],16)
            instructions=list(md.disasm(code[lo:hi],base+lo))
            loads=[(i,v.operands[0].reg) for i,v in enumerate(instructions) if v.mnemonic=='movabs' and v.operands[-1].type==capstone.CS_OP_IMM and v.operands[-1].imm==base+setup]
            function_calls=set()
            for init,register in loads:
                calls=[]
                for i in range(init+1,len(instructions)):
                    v=instructions[i]
                    if register in v.regs_access()[1]:break
                    if v.mnemonic=='call' and v.operands[0].type==capstone.CS_OP_REG and v.operands[0].reg==register:calls.append(i)
                function_calls.update(calls)
            if len(function_calls)>=8:parents.append((instructions,sorted(function_calls)))
        if len(parents)!=1:raise ValueError('AMBIGUOUS_SETUP_CALLER')
        instructions,calls=parents[0]
        if len(calls)!=len(expected_rows):raise ValueError('STRATEGY_COUNT_MISMATCH')
        address_index={v.address:i for i,v in enumerate(instructions)}
        predecessors=[[] for _ in instructions]
        indirect_jump=False
        for i,v in enumerate(instructions):
            destinations=[]
            if v.mnemonic.startswith('j'):
                if v.operands[0].type!=capstone.CS_OP_IMM:indirect_jump=True
                elif v.operands[0].imm in address_index:destinations.append(address_index[v.operands[0].imm])
                if v.mnemonic!='jmp' and i+1<len(instructions):destinations.append(i+1)
            elif not v.mnemonic.startswith('ret') and i+1<len(instructions):destinations.append(i+1)
            for dest in destinations:predecessors[dest].append(i)
        aliases={}
        for canonical,names in [('rax',['eax','ax','al','ah']),('rbx',['ebx','bx','bl','bh']),('rcx',['ecx','cx','cl','ch']),('rdx',['edx','dx','dl','dh']),('rsi',['esi','si','sil']),('rdi',['edi','di','dil']),('rbp',['ebp','bp','bpl']),('rsp',['esp','sp','spl'])]:
            for name in [canonical,*names]:aliases[name]=canonical
        for number in range(8,16):
            for suffix in ['', 'd','w','b']:aliases[f'r{number}{suffix}']=f'r{number}'
        def canonical(register):
            name=md.reg_name(register);return aliases.get(name,name)
        def reaching_immediates(at,register):
            if indirect_jump:raise ValueError('INDIRECT_JUMP_PREVENTS_DATAFLOW_PROOF')
            wanted=canonical(register);pending=list(predecessors[at]);seen=set();definitions={}
            while pending:
                i=pending.pop()
                if i in seen:continue
                seen.add(i);v=instructions[i]
                if v.mnemonic=='call' and (wanted in ['rax','rcx','rdx','r8','r9','r10','r11'] or wanted in [f'xmm{n}' for n in range(6)]):
                    raise ValueError('VOLATILE_REGISTER_HAS_UNKNOWN_CALL_RESULT')
                if any(canonical(r)==wanted for r in v.regs_access()[1]):
                    if v.mnemonic in ['mov','movabs'] and len(v.operands)==2 and v.operands[0].type==capstone.CS_OP_REG and v.operands[1].type==capstone.CS_OP_IMM and v.operands[0].size in [4,8]:
                        definitions[i]=v.operands[1].imm&((1<<(v.operands[0].size*8))-1);continue
                    raise ValueError('REGISTER_DEFINITION_IS_NOT_AN_IMMEDIATE '+hex(v.address-base))
                if not predecessors[i]:raise ValueError('REGISTER_VALUE_DEPENDS_ON_FUNCTION_ENTRY')
                pending.extend(predecessors[i])
            if not definitions or len(set(definitions.values()))!=1:raise ValueError('REGISTER_HAS_MULTIPLE_POSSIBLE_CONSTANTS')
            return sorted(definitions)
        previous=0;results=[]
        for call,row in zip(calls,expected_rows):
            markers=[i for i in range(previous,call) if instructions[i].mnemonic=='movabs' and instructions[i].operands[-1].type==capstone.CS_OP_IMM and instructions[i].operands[-1].imm==base+fields['older']]
            if not markers:raise ValueError('ASSIGNMENT_NOT_FOUND')
            marker=markers[-1]
            branches=[i for i in range(previous,marker) if instructions[i].mnemonic.startswith('j') and instructions[i].mnemonic!='jmp']
            if not branches:raise ValueError('ASSIGNMENT_START_NOT_FOUND')
            gate=branches[-1]
            start=gate+1
            # JIT may load a constant immediately before the enable comparison.
            # Execute those original immediate loads; never seed registers from expected values.
            preloads=[];k=gate-2
            while k>=previous:
                v=instructions[k]
                if v.mnemonic not in ['movabs','mov'] or len(v.operands)!=2 or v.operands[0].type!=capstone.CS_OP_REG or v.operands[1].type!=capstone.CS_OP_IMM:break
                preloads.append(v);k-=1
            end=next(i for i in range(marker+1,call) if instructions[i].mnemonic.startswith('j') and instructions[i].mnemonic!='jmp')
            if any(v.mnemonic=='call' for v in instructions[start:end]):raise ValueError('PREFIX_HAS_EXTERNAL_DEPENDENCY')
            for region,raw in original.regions:
                if region.get('kind')=='mutable_program_data':machine.mem_write(region['base'],raw)
            for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:machine.reg_write(getattr(x,'UC_X86_REG_'+name),0)
            for i in range(16):machine.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
            machine.reg_write(x.UC_X86_REG_RSP,0x50010000)
            formats={name:('<d' if name=='gap' else '<B' if name=='entry_h1' else '<i') for name in fields}
            for field,rva in fields.items():machine.mem_write(base+rva,b'\xa5'*struct.calcsize(formats[field]))
            for v in reversed(preloads):machine.emu_start(v.address,v.address+v.size,count=1)
            stores=[]
            hook=machine.hook_add(original.uc.UC_HOOK_MEM_WRITE,lambda emu,access,address,size,value,user:stores.append(emu.reg_read(x.UC_X86_REG_RIP)),begin=base+fields['gap'],end=base+fields['gap']+7)
            machine.emu_start(instructions[start].address,instructions[end].address,count=20000)
            machine.hook_del(hook)
            if machine.reg_read(x.UC_X86_REG_RIP)!=instructions[end].address:raise ValueError('PREFIX_NOT_COMPLETED')
            actual={name:struct.unpack(formats[name],machine.mem_read(base+rva,struct.calcsize(formats[name])))[0] for name,rva in fields.items()}
            expected={name:row['fields'][name]['value'] for name in fields}
            recovered_definitions=[]
            if actual.get('gap')!=expected.get('gap') and all(actual[k]==expected[k] for k in fields if k!='gap'):
                if len(stores)!=1:raise ValueError('AMBIGUOUS_GAP_WRITE')
                store=address_index[stores[0]];operand=instructions[store].operands[-1]
                if operand.type!=capstone.CS_OP_REG:raise ValueError('GAP_WRITE_NOT_FROM_REGISTER')
                if any(any(canonical(r)==canonical(operand.reg) for r in v.regs_access()[1]) for v in instructions[start:store]):raise ValueError('GAP_DEPENDENCY_IS_INSIDE_PREFIX')
                recovered_definitions=reaching_immediates(start,operand.reg)
                # Every incoming path reaches an original immediate load with the same value.
                # Execute one such load, then the assignment prefix again; no expected-value injection.
                definition=instructions[recovered_definitions[0]]
                machine.emu_start(definition.address,definition.address+definition.size,count=1)
                machine.emu_start(instructions[start].address,instructions[end].address,count=20000)
                actual={name:struct.unpack(formats[name],machine.mem_read(base+rva,struct.calcsize(formats[name])))[0] for name,rva in fields.items()}
            if actual!=expected:raise ValueError(f'CONSTANTS_DIFFER bot={bot} index={row["index"]} actual={actual} expected={expected}')
            results.append({'index':row['index'],'immediate_load_rvas':[hex(v.address-base) for v in reversed(preloads)],'reaching_constant_definition_rvas':[hex(instructions[i].address-base) for i in recovered_definitions],'start_rva':hex(instructions[start].address-base),'end_rva_exclusive':hex(instructions[end].address-base),'values':actual,'matched':True})
            previous=call+1
        result={'bot':bot,'profiles_matched':len(results),'fields_per_profile':len(fields),'profiles':results,
                'code_sha256':metadata['code_sha256'],'data_sha256':metadata['data_sha256'],
                'scope':'Straight-line native parameter assignments only; no terminal API calls; not strategy enable/frequency/scaling or complete entry behavior.'}
        output.write_text(json.dumps(result,indent=2),encoding='utf-8');print(json.dumps(result))

if __name__=='__main__':main()
