"""Save the scoped cancel/filter functions and exact floating-point guard code.

Usage: phan-tich-huy-lenh-cho-bot-1-3.py BOT NEW_RUN [--positions|--position-scan|--position-references|--position-modify|--coordinator]
Read-only toward originals/captures/source. No execution of bot instructions/MT5.
This is an analysis inventory, not a behavioral-equivalence result.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import re

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('entry',Path(__file__).with_name('kiem-gia-vao-bot-1-3.py'))
entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
spec=importlib.util.spec_from_file_location('validation',Path(__file__).with_name('kiem-khoi-luong-hop-le-bot-1-3.py'))
validation=importlib.util.module_from_spec(spec);spec.loader.exec_module(validation)
RVA={1:[0x34150,0x32110,0x325b0],3:[0x32450,0x3da90,0x3dd60]}
CLOSE_RVA={1:[0x22c40,0x3d010],3:[0x2e370,0x47d20]}
POSITION_SCAN_RVA={1:[0x2fa00,0x2fce0],3:[0x3ce40,0x3d220]}
POSITION_MODIFY_RVA={1:[0x26d20],3:[0x32a90]}
COORDINATOR_RVA={1:[0x10f60],3:[0x17f00]}
GUARDS={1:[(0x34220,0x34319),(0x34760,0x3477d)],3:[(0x32520,0x32619),(0x32a60,0x32a84)]}
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2)

def reference_origins(a,o,meta,inventory,source,lines,md,digest):
    tick=0x67750 if a.bot==1 else 0x74790;symbol=0x67918 if a.bot==1 else 0x74958
    targets=[tick+8,tick+16,*( [0x66a70,0x67468] if a.bot==1 else [0x73ab0,0x744a8])]
    sdk_base=int(meta['engine']['engine_base'],16);sdk=sdk_base+0x7c2c10
    proof=ROOT/'doi-chung-mt5/huy-lenh-cho-20261024/cancel-tick-api-r1/tick-fields.json';known=json.loads(proof.read_text())
    if not known['runner_verified'] or known['fields']!={'bid':8,'ask':16}:raise ValueError('TICK_FIELDS_NOT_VERIFIED')
    native=[];c_calls=[];writes=[]
    for function in meta['functions']:
        lo=int(function['begin_rva'],16);hi=int(function['end_rva'],16)
        instructions=list(md.disasm(bytes(o.m.mem_read(o.base+lo,hi-lo)),o.base+lo))
        for i,row in enumerate(instructions):
            if row.mnemonic!='movabs' or row.op_str!=f'r8, {o.base+tick:#x}':continue
            window=instructions[max(0,i-4):i+11]
            confirmed=False
            for j,item in enumerate(window[:-1]):
                if item.mnemonic=='movabs' and item.op_str==f'rax, {sdk:#x}' and window[j+1].mnemonic=='call' and window[j+1].op_str=='rax':
                    between=[x for x in window if row.address<x.address<item.address]
                    symbol_load=any(x.address<row.address and x.mnemonic=='movabs' and x.op_str==f'rdx, {o.base+symbol:#x}' for x in window)
                    confirmed=symbol_load and not any(x.operands and x.operands[0].type==1 and x.reg_name(x.operands[0].reg)=='r8' for x in between)
            native.append(dict(function_rva=hex(lo),tick_argument_rva=hex(row.address-o.base),direct_sdk_and_symbol_confirmed=confirmed,instructions=[dict(rva=hex(x.address-o.base),bytes=x.bytes.hex(),mnemonic=x.mnemonic,operands=x.op_str) for x in window]))
    def owner(number):
        matches=[f['rva'] for f in inventory['functions'] if f['line']<=number<f['last_line']]
        if len(matches)!=1:raise ValueError('C_LINE_OWNER_UNRESOLVED '+str(number))
        return matches[0]
    for i,line in enumerate(lines,1):
        if 'MT5_SymbolInfoTick' in line and f'DAT_{o.base+tick:x}' in line:c_calls.append(dict(line=i,function_rva=owner(i),text=line.strip()))
        for rva in targets:
            if re.search(rf'\b_?DAT_{o.base+rva:x}\s*=(?!=)',line):
                writes.append(dict(rva=hex(rva),line=i,function_rva=owner(i),context='\n'.join(lines[max(0,i-7):i+2])))
    if not any(row['direct_sdk_and_symbol_confirmed'] for row in native):raise ValueError('NO_DIRECT_TICK_ORIGIN_CONFIRMED')
    out=ROOT/f'bot-cua-toi-{a.bot}/phan-tich/dong-vi-the'/a.new_run;out.mkdir(parents=True,exist_ok=False)
    result=dict(bot=a.bot,original_ex5_sha256=digest,source=source.relative_to(ROOT).as_posix(),source_sha256=entry.sha(source),tick_fields_proof_sha256=entry.sha(proof),tick_buffer_rva=hex(tick),symbol_descriptor_rva=hex(symbol),sdk_target_rva='0x7c2c10',reference_fields=[dict(rva=hex(tick+8),offset=8,field='bid'),dict(rva=hex(tick+16),offset=16,field='ask')],native_tick_argument_sites=native,c_tick_calls=c_calls,direct_c_assignments=writes,runtime_verified=False,analysis_complete=False,
                limits=['Direct observed global tick-buffer origin and field offsets only; not proof that all writes were found.','C assignment search omits indirect writes/aliases; cached fields can be written elsewhere.','Full control-flow initialization,refresh/failure handling and ordering against every close caller remain unverified.'])
    save(out/'reference-origins.json',result);save(out/'receipt.json',dict(tool_sha256=entry.sha(Path(__file__)),hashes={'reference-origins.json':entry.sha(out/'reference-origins.json')}))
    print(json.dumps(dict(bot=a.bot,native_tick_argument_sites=len(native),direct_confirmed=sum(x['direct_sdk_and_symbol_confirmed'] for x in native),c_tick_calls=len(c_calls),direct_c_assignments=len(writes),runtime_verified=False)))

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('new_run')
    modes=parser.add_mutually_exclusive_group();modes.add_argument('--positions',action='store_true');modes.add_argument('--position-scan',action='store_true');modes.add_argument('--position-references',action='store_true');modes.add_argument('--position-modify',action='store_true');modes.add_argument('--coordinator',action='store_true');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.new_run):raise ValueError('INVALID_RUN')
    digest=validation.original_hash(a.bot);o=entry.Original(a.bot)
    import capstone
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
    position_scope=a.positions or a.position_scan or a.position_modify
    full_scope=position_scope or a.coordinator
    inventory_run='luot-20261025-r2' if a.coordinator else 'luot-20261025-r1' if a.position_scan or a.position_references or a.position_modify else 'luot-20261024-r13' if a.positions else 'luot-20261024-r9'
    inventory_path=ROOT/f'ban-do-bot-1-3/{inventory_run}/bot-{a.bot}.json';inventory=json.loads(inventory_path.read_text())
    folder='luot-20261023-data-v2' if a.bot==1 else 'luot-20261023-data';home=ROOT/f'bot-cua-toi-{a.bot}';meta_path=home/'phan-tich'/folder/'metadata/import.json';meta=json.loads(meta_path.read_text())
    source=ROOT/inventory['c_source']
    if entry.sha(source)!=inventory['c_source_sha256']:raise ValueError('C_SOURCE_CHANGED')
    lines=source.read_text(encoding='utf-8-sig').splitlines();records=[];excerpts=[];guards=[]
    if a.position_references:return reference_origins(a,o,meta,inventory,source,lines,md,digest)
    for rva in (COORDINATOR_RVA if a.coordinator else POSITION_MODIFY_RVA if a.position_modify else POSITION_SCAN_RVA if a.position_scan else CLOSE_RVA if a.positions else RVA)[a.bot]:
        fn=next(f for f in meta['functions'] if int(f['begin_rva'],16)==rva);end=int(fn['end_rva'],16);known=next(f for f in inventory['functions'] if int(f['rva'],16)==rva)
        raw=bytes(o.m.mem_read(o.base+rva,end-rva));instructions=[];callees=set()
        for ins in md.disasm(raw,o.base+rva):
            offset=ins.address-o.base;row=dict(rva=hex(offset),bytes=ins.bytes.hex(),mnemonic=ins.mnemonic,operands=ins.op_str)
            if ins.mnemonic=='call' and ins.operands[0].type==capstone.CS_OP_IMM:
                target=ins.operands[0].imm;callees.add(hex(target-o.base) if o.base<=target<o.base+0x1000000 else hex(target))
            literals=[]
            for operand in ins.operands:
                if operand.type==capstone.CS_OP_MEM and operand.mem.base==capstone.x86_const.X86_REG_RIP:
                    address=ins.address+ins.size+operand.mem.disp
                    try:literals.append(dict(address=hex(address),bytes=bytes(o.m.mem_read(address,operand.size)).hex()))
                    except o.uc.UcError:pass
            if literals:row['rip_relative_memory']=literals
            instructions.append(row)
            if full_scope or any(lo<=offset<hi for lo,hi in GUARDS[a.bot]):guards.append(hex(offset)+' '+ins.mnemonic+' '+ins.op_str+(' ; memory='+str(literals) if literals else ''))
        segment='\n'.join(lines[known['line']-1:known['last_line']-1]);excerpts.append('// '+inventory['c_source']+':'+str(known['line'])+'\n'+segment)
        records.append(dict(rva=hex(rva),end_rva=hex(end),native_bytes_sha256=__import__('hashlib').sha256(raw).hexdigest(),source_line=known['line'],source_last_line=known['last_line']-1,observed_direct_calls=sorted(callees),instructions=instructions))
    out=home/('phan-tich/dieu-phoi' if a.coordinator else 'phan-tich/dong-vi-the' if position_scope else 'phan-tich/huy-lenh-cho')/a.new_run;out.mkdir(parents=True,exist_ok=False)
    (out/'functions.c').write_text('\n\n'.join(excerpts)+'\n',encoding='utf-8',newline='');(out/'native-guards.txt').write_text('\n'.join(guards)+'\n',encoding='utf-8',newline='')
    limits=['Code inventory only; exact SDK constants, argument types, guards and side effects require explicit confirmation.','No runtime comparison for this newly selected scope.'] if full_scope else ['Tick field names/layout still require known-source calibration.','Static extraction is not a runtime comparison.']
    report=dict(bot=a.bot,original_ex5_sha256=digest,inventory_sha256=entry.sha(inventory_path),metadata_sha256=entry.sha(meta_path),engine_sha256=meta['engine']['engine_sha256'],source=inventory['c_source'],source_sha256=entry.sha(source),functions=records,analysis_complete=False,runtime_verified=False,limits=limits)
    save(out/'analysis.json',report);save(out/'receipt.json',dict(tool_sha256=entry.sha(Path(__file__)),hashes={p.name:entry.sha(p) for p in out.iterdir() if p.is_file()}));print(json.dumps(dict(bot=a.bot,functions=len(records),guard_instructions=len(guards),runtime_verified=False)))

if __name__=='__main__':main()
