"""Measure the host CPU and Unicorn on identical, standalone ADDSD bytes.

Only this arithmetic function executes. It never calls or modifies the EX5.
"""
import argparse,ctypes,json,platform,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];FOLDER=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT.parent/'.local/claude-recovery-20261023/python'))
import unicorn as uc
from unicorn import x86_const as x
p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',default='nan-add-cpu-probe.json');a=p.parse_args()
output=(FOLDER/a.output).resolve()
if output.parent!=FOLDER or output.exists():raise ValueError('OUTPUT_MUST_BE_NEW_FILE_IN_EVIDENCE_FOLDER')
CODE=bytes.fromhex('66480f6ec1 66480f6eca f20f58c1 66480f7ec0 c3')
kernel=ctypes.WinDLL('kernel32',use_last_error=True)
kernel.VirtualAlloc.argtypes=[ctypes.c_void_p,ctypes.c_size_t,ctypes.c_uint32,ctypes.c_uint32];kernel.VirtualAlloc.restype=ctypes.c_void_p
kernel.VirtualFree.argtypes=[ctypes.c_void_p,ctypes.c_size_t,ctypes.c_uint32];kernel.VirtualFree.restype=ctypes.c_int
address=kernel.VirtualAlloc(None,4096,0x3000,0x40)
if not address:raise ctypes.WinError(ctypes.get_last_error())
try:
    ctypes.memmove(address,CODE,len(CODE));host=ctypes.WINFUNCTYPE(ctypes.c_uint64,ctypes.c_uint64,ctypes.c_uint64)(address)
    guest=uc.Uc(uc.UC_ARCH_X86,uc.UC_MODE_64)
    guest.mem_map(0x100000,4096);guest.mem_write(0x100000,CODE);guest.mem_map(0x200000,4096);guest.mem_map(0x300000,4096)
    values=[0,0x3ff0000000000000,0x7ff0000000000000,0xfff0000000000000,
            0x7ff8000000000000,0xfff8000000000000,0x7ff8000000000041,0xfff8000000000042,0x7ff0000000000043,0xfff0000000000044]
    rows=[]
    for left in values:
        for right in values:
            guest.mem_write(0x200ff8,struct.pack('<Q',0x300000));guest.reg_write(x.UC_X86_REG_RSP,0x200ff8)
            guest.reg_write(x.UC_X86_REG_RCX,left);guest.reg_write(x.UC_X86_REG_RDX,right);guest.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
            guest.emu_start(0x100000,0x300000,count=20)
            rows.append(dict(left=hex(left),right=hex(right),host=hex(host(left,right)),unicorn=hex(guest.reg_read(x.UC_X86_REG_RAX))))
    result=dict(machine=platform.machine(),code_hex=CODE.hex(),rows=rows,different=[r for r in rows if r['host']!=r['unicorn']],original_ex5_modified=False)
    with output.open('x',encoding='utf-8',newline='\n') as f:json.dump(result,f,ensure_ascii=False,indent=2);f.write('\n')
    print(json.dumps(dict(cases=len(rows),different=len(result['different']),examples=result['different'][:8])))
finally:
    if not kernel.VirtualFree(address,0,0x8000):raise ctypes.WinError(ctypes.get_last_error())
