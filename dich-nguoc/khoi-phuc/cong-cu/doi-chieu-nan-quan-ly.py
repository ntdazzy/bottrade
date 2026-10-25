"""Use measured Windows SSE2 result bits only for two-NaN scalar arithmetic.
Instruction bytes stay unchanged. Caller owns the fixture lifetime and reports counts.
Used by the current bot1/bot3 management comparisons; this does not execute a full EA.
"""
import importlib.util
from pathlib import Path
import struct
ROOT=Path(__file__).resolve().parents[1]
CPU_TOOL=ROOT/'bot-cua-toi-3/tests/check-management-prelude.py'
spec=importlib.util.spec_from_file_location('management_cpu_nan_shared',CPU_TOOL)
cpu_module=importlib.util.module_from_spec(spec);spec.loader.exec_module(cpu_module)
CpuFixture=cpu_module.CpuFixture
PROBE=cpu_module.PROBE
verify_probe=cpu_module.verify_probe
MASK=(1<<64)-1
class BothNaN:
    def __init__(self,runner,analysis,cpu):
        import capstone
        self.runner=runner;self.cpu=cpu;self.counts={};self.cases=set();self.sites={}
        self.cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);self.cs.detail=True
        for function in analysis['functions']:
            for row in function['instructions']:
                if row['mnemonic'] not in ['mulsd','addsd','subsd']:continue
                rva=int(row['rva'],16);raw=bytes.fromhex(row['bytes']);address=runner.base+rva
                if bytes(runner.m.mem_read(address,len(raw)))!=raw:raise ValueError('NAN_SITE_BYTES_DIFFERS')
                decoded=list(self.cs.disasm(raw,address))
                if len(decoded)!=1 or decoded[0].size!=len(raw):raise ValueError('NAN_SITE_DECODE_FAILED')
                i=decoded[0]
                if i.mnemonic!=row['mnemonic'] or i.operands[0].type!=capstone.CS_OP_REG:raise ValueError('NAN_SITE_OPERANDS_FAILED')
                target=getattr(runner.x,'UC_X86_REG_'+i.reg_name(i.operands[0].reg).upper())
                self.sites[address]=(i,target)
                runner.m.hook_add(runner.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
    def call(self,m,address,size,user):
        import capstone
        r=self.runner;i,target=self.sites[address];full=m.reg_read(target);left=full&MASK
        if not cpu_module.is_nan(left):return
        operand=i.operands[1]
        if operand.type==capstone.CS_OP_REG:
            right=m.reg_read(getattr(r.x,'UC_X86_REG_'+i.reg_name(operand.reg).upper()))&MASK
        elif operand.type==capstone.CS_OP_MEM:
            value=operand.mem
            if value.segment:raise ValueError('NAN_SEGMENT_REGISTER_UNSUPPORTED')
            p=value.disp
            for reg,scale in [(value.base,1),(value.index,value.scale)]:
                if not reg:continue
                name=i.reg_name(reg).upper()
                p+=(address+size if name=='RIP' else m.reg_read(getattr(r.x,'UC_X86_REG_'+name)))*scale
            right=struct.unpack('<Q',m.mem_read(p&MASK,8))[0]
        else:raise ValueError('NAN_SOURCE_OPERAND_UNSUPPORTED')
        if not cpu_module.is_nan(right):return
        if m.reg_read(r.x.UC_X86_REG_MXCSR)&~0x3f!=0x1f80:raise ValueError('NAN_GUEST_MXCSR_DIFFERS')
        result=self.cpu.compute(i.mnemonic[:-2],left,right)
        m.reg_write(target,(full&~MASK)|result);m.reg_write(r.x.UC_X86_REG_RIP,address+size)
        key=hex(address-r.base);self.counts[key]=self.counts.get(key,0)+1;self.cases.add(r.case['id'])
    def report(self):
        return dict(delegated_instructions=sum(self.counts.values()),by_rva=self.counts,
                    cases=sorted(self.cases),original_bytes_changed=False,whole_original_on_cpu=False,
                    mxcsr_status_flags_compared=False)
