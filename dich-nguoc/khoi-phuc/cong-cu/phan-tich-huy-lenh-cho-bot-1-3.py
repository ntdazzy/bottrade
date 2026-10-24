"""Save the scoped cancel/filter functions and exact floating-point guard code.

Usage: phan-tich-huy-lenh-cho-bot-1-3.py BOT NEW_RUN [--positions]
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
GUARDS={1:[(0x34220,0x34319),(0x34760,0x3477d)],3:[(0x32520,0x32619),(0x32a60,0x32a84)]}
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('new_run');parser.add_argument('--positions',action='store_true');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.new_run):raise ValueError('INVALID_RUN')
    digest=validation.original_hash(a.bot);o=entry.Original(a.bot)
    import capstone
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
    inventory_run='luot-20261024-r13' if a.positions else 'luot-20261024-r9'
    inventory_path=ROOT/f'ban-do-bot-1-3/{inventory_run}/bot-{a.bot}.json';inventory=json.loads(inventory_path.read_text())
    folder='luot-20261023-data-v2' if a.bot==1 else 'luot-20261023-data';home=ROOT/f'bot-cua-toi-{a.bot}';meta_path=home/'phan-tich'/folder/'metadata/import.json';meta=json.loads(meta_path.read_text())
    source=ROOT/inventory['c_source']
    if entry.sha(source)!=inventory['c_source_sha256']:raise ValueError('C_SOURCE_CHANGED')
    lines=source.read_text(encoding='utf-8-sig').splitlines();records=[];excerpts=[];guards=[]
    for rva in (CLOSE_RVA if a.positions else RVA)[a.bot]:
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
            if a.positions or any(lo<=offset<hi for lo,hi in GUARDS[a.bot]):guards.append(hex(offset)+' '+ins.mnemonic+' '+ins.op_str+(' ; memory='+str(literals) if literals else ''))
        segment='\n'.join(lines[known['line']-1:known['last_line']-1]);excerpts.append('// '+inventory['c_source']+':'+str(known['line'])+'\n'+segment)
        records.append(dict(rva=hex(rva),end_rva=hex(end),native_bytes_sha256=__import__('hashlib').sha256(raw).hexdigest(),source_line=known['line'],source_last_line=known['last_line']-1,observed_direct_calls=sorted(callees),instructions=instructions))
    out=home/('phan-tich/dong-vi-the' if a.positions else 'phan-tich/huy-lenh-cho')/a.new_run;out.mkdir(parents=True,exist_ok=False)
    (out/'functions.c').write_text('\n\n'.join(excerpts)+'\n',encoding='utf-8',newline='');(out/'native-guards.txt').write_text('\n'.join(guards)+'\n',encoding='utf-8',newline='')
    limits=['Code inventory only; exact SDK constants, argument types, guards and side effects require explicit confirmation.','No runtime comparison for this newly selected scope.'] if a.positions else ['Tick field names/layout still require known-source calibration.','Static extraction is not a runtime comparison.']
    report=dict(bot=a.bot,original_ex5_sha256=digest,inventory_sha256=entry.sha(inventory_path),metadata_sha256=entry.sha(meta_path),engine_sha256=meta['engine']['engine_sha256'],source=inventory['c_source'],source_sha256=entry.sha(source),functions=records,analysis_complete=False,runtime_verified=False,limits=limits)
    save(out/'analysis.json',report);save(out/'receipt.json',dict(tool_sha256=entry.sha(Path(__file__)),hashes={p.name:entry.sha(p) for p in out.iterdir() if p.is_file()}));print(json.dumps(dict(bot=a.bot,functions=len(records),guard_instructions=len(guards),runtime_verified=False)))

if __name__=='__main__':main()
