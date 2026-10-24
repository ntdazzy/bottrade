"""List native call sites of position modify 0x26d20/0x32a90 in the captured code.

Usage: phan-tich-goi-sua-vi-the-bot-1-3.py BOT NEW_RUN
Read-only toward originals/captures/C; no bot instruction or MT5 is executed.
Per site: the instruction loading the target (same block, or an earlier load into a
preserved register followed linearly), the last write of RCX/XMM1/XMM2 (and of the
unused RDX/R8/XMM0) inside the same straight-line block, and the first use of RAX
after the call. Unresolved indirect calls are counted. Linear evidence only, not CFG.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('entry',Path(__file__).with_name('kiem-gia-vao-bot-1-3.py'))
entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
spec=importlib.util.spec_from_file_location('validation',Path(__file__).with_name('kiem-khoi-luong-hop-le-bot-1-3.py'))
validation=importlib.util.module_from_spec(spec);spec.loader.exec_module(validation)
FN={1:0x26d20,3:0x32a90}
ARGUMENTS=dict(ticket_rcx={'rcx','ecx','cx','cl','ch'},sl_xmm1={'xmm1'},tp_xmm2={'xmm2'},
               unused_rdx={'rdx','edx','dx','dl','dh'},unused_r8={'r8','r8d','r8w','r8b'},unused_xmm0={'xmm0'})
RETURN={'rax','eax','ax','al','ah'};ZEROING={'xor','sub','pxor','xorps','xorpd'}
PRESERVED={'rbx','rbp','rdi','rsi','r12','r13','r14','r15'}
def save(path,value):
    with path.open('x',encoding='utf-8') as f:json.dump(value,f,ensure_ascii=False,indent=2)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('new_run');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.new_run):raise ValueError('INVALID_RUN')
    digest=validation.original_hash(a.bot);o=entry.Original(a.bot)
    import capstone
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
    home=ROOT/f'bot-cua-toi-{a.bot}';folder='luot-20261023-data-v2' if a.bot==1 else 'luot-20261023-data'
    meta_path=home/'phan-tich'/folder/'metadata/import.json';meta=json.loads(meta_path.read_text())
    inventory_path=ROOT/f'ban-do-bot-1-3/luot-20261025-r2/bot-{a.bot}.json';inventory=json.loads(inventory_path.read_text());source=ROOT/inventory['c_source']
    if entry.sha(source)!=inventory['c_source_sha256']:raise ValueError('C_SOURCE_CHANGED')
    analysis_path=home/'phan-tich/dong-vi-the/modify-20261025-r1/analysis.json';analysis=json.loads(analysis_path.read_text());fn=analysis['functions'][0]
    if analysis['original_ex5_sha256']!=digest or int(fn['rva'],16)!=FN[a.bot]:raise ValueError('MODIFY_ANALYSIS_DIFFERS')
    end=int(fn['end_rva'],16)
    if hashlib.sha256(bytes(o.m.mem_read(o.base+FN[a.bot],end-FN[a.bot]))).hexdigest()!=fn['native_bytes_sha256']:raise ValueError('MODIFY_NATIVE_BYTES_CHANGED')
    target=o.base+FN[a.bot];lines=source.read_text(encoding='utf-8-sig').splitlines();sites=[];by_function={};unresolved={}
    def describe(ins):return dict(rva=hex(ins.address-o.base),bytes=ins.bytes.hex(),text=(ins.mnemonic+' '+ins.op_str).strip())
    def control(ins):return any(ins.group(g) for g in [capstone.CS_GRP_JUMP,capstone.CS_GRP_RET,capstone.CS_GRP_INT,capstone.CS_GRP_IRET])
    def written(ins):
        names={ins.reg_name(r) for r in ins.regs_access()[1]}
        return names
    def read(ins):
        ops=ins.operands
        if ins.mnemonic in ZEROING and len(ops)==2 and all(op.type==capstone.CS_OP_REG for op in ops) and ops[0].reg==ops[1].reg:return set()
        return {ins.reg_name(r) for r in ins.regs_access()[0]}
    for function in meta['functions']:
        lo=int(function['begin_rva'],16);hi=int(function['end_rva'],16)
        code=list(md.disasm(bytes(o.m.mem_read(o.base+lo,hi-lo)),o.base+lo))
        targets={ins.operands[0].imm for ins in code if ins.group(capstone.CS_GRP_JUMP) and ins.operands and ins.operands[0].type==capstone.CS_OP_IMM}
        for k,ins in enumerate(code):
            if ins.mnemonic!='call' or not ins.operands:continue
            op=ins.operands[0];load=None;load_kind='direct'
            if op.type==capstone.CS_OP_IMM:
                if op.imm!=target:continue
            elif op.type==capstone.CS_OP_REG:
                # A preserved register may hold a target loaded once earlier in the function;
                # follow it linearly across calls/blocks. Volatile registers stop at the block.
                register=ins.reg_name(op.reg);load_kind='same_block';status='unresolved'
                for j in range(k-1,-1,-1):
                    p=code[j]
                    if register in written(p):
                        if p.mnemonic=='movabs' and p.operands[1].type==capstone.CS_OP_IMM:
                            status='target' if p.operands[1].imm==target else 'other'
                            if status=='target':load=p
                        break
                    if control(p) or p.group(capstone.CS_GRP_CALL) or p.address in targets:
                        if register not in PRESERVED:break
                        load_kind='preserved_register_linear'
                if status=='unresolved':unresolved[hex(lo)]=unresolved.get(hex(lo),0)+1
                if load is None:continue
            else:
                unresolved[hex(lo)]=unresolved.get(hex(lo),0)+1
                continue
            def definition(names):
                for j in range(k-1,max(-1,k-64),-1):
                    p=code[j]
                    if control(p):return dict(kind='defined_before_block',block_start=hex(code[j+1].address-o.base))
                    if p.group(capstone.CS_GRP_CALL):return dict(kind='clobbered_by_earlier_call',**describe(p))
                    if written(p)&names:return dict(kind='written_in_block',**describe(p))
                    if p.address in targets:return dict(kind='defined_before_block',block_start=hex(p.address-o.base))
                return dict(kind='window_limit')
            use=dict(kind='window_limit')
            for p in code[k+1:k+33]:
                if read(p)&RETURN:use=dict(kind='read',registers=sorted(read(p)&RETURN),**describe(p));break
                if written(p)&RETURN:use=dict(kind='overwritten_before_read',**describe(p));break
                if control(p) or p.group(capstone.CS_GRP_CALL):use=dict(kind='not_read_in_block',**describe(p));break
            start=max(0,k-24)
            sites.append(dict(function_rva=hex(lo),call_rva=hex(ins.address-o.base),target_load=describe(load) if load else None,target_load_kind=load_kind,
                              arguments={name:definition(names) for name,names in ARGUMENTS.items()},return_use=use,
                              window=[describe(p) for p in code[start:k+9]]))
            by_function.setdefault(hex(lo),dict(native_sites=0,c_call_lines=[]))['native_sites']+=1
    pattern=f'FUN_{target:x}(';listed=[]
    for known in inventory['functions']:
        if int(known['rva'],16)==FN[a.bot]:listed=sorted(known.get('callers',[]))
        hits=[i for i in range(known['line'],known['last_line']) if pattern in lines[i-1] and not lines[i-1].lstrip().startswith(('undefined','void','bool','ulonglong'))]
        if hits:by_function.setdefault(hex(int(known['rva'],16)),dict(native_sites=0,c_call_lines=[]))['c_call_lines']=hits
    if not sites:raise ValueError('NO_NATIVE_CALL_SITE_FOUND')
    out=home/'phan-tich/dong-vi-the'/a.new_run;out.mkdir(parents=True,exist_ok=False)
    result=dict(bot=a.bot,original_ex5_sha256=digest,analysis_sha256=entry.sha(analysis_path),metadata_sha256=entry.sha(meta_path),inventory_sha256=entry.sha(inventory_path),
                c_source=inventory['c_source'],c_source_sha256=entry.sha(source),target_rva=hex(FN[a.bot]),target_absolute=hex(target),sites=sites,by_function=by_function,
                native_site_count=len(sites),c_call_line_count=sum(len(v['c_call_lines']) for v in by_function.values()),inventory_callers=listed,
                native_callers_match_inventory=sorted({s['function_rva'] for s in sites})==listed,
                counts_match_c={rva:v['native_sites']==len(v['c_call_lines']) for rva,v in by_function.items()},
                unresolved_indirect_calls_any_target=unresolved,runtime_verified=False,analysis_complete=False,
                limits=['Straight-line block evidence only: a definition before the block start or an indirect call target is not resolved.',
                        'Function boundaries come from the captured runtime table; code outside it is not scanned.',
                        'C line counts are text matches in the decompiled source and may differ from native sites.'])
    save(out/'caller-sites.json',result);save(out/'receipt.json',dict(tool_sha256=entry.sha(Path(__file__)),hashes={'caller-sites.json':entry.sha(out/'caller-sites.json')}))
    print(json.dumps(dict(bot=a.bot,native_sites=len(sites),functions=len(by_function),c_call_lines=result['c_call_line_count'],runtime_verified=False)))

if __name__=='__main__':main()
