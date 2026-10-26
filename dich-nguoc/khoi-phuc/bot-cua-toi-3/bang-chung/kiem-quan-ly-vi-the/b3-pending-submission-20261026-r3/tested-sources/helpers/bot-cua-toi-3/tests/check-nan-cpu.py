"""Compare captured scalar SSE2 opcodes on this Windows CPU and Unicorn.
No EX5, process or system file is modified. Tiny standalone fixtures read two
64-bit operands and return result bits. All executable pages are released.
Usage: check-nan-cpu.py RUN
"""
import argparse,ctypes,hashlib,json,pathlib,platform,re,struct,sys
HOME=pathlib.Path(__file__).resolve().parents[1]
ROOT=HOME.parent
sys.path.insert(0,str(ROOT.parent/'.local/claude-recovery-20261023/python'))
import unicorn
from unicorn import x86_const as x
def require(ok,message):
    if not ok:raise ValueError(message)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('run');a=p.parse_args()
    require(sys.platform=='win32' and platform.machine().upper() in ['AMD64','X86_64'],'WINDOWS_X64_REQUIRED')
    require(bool(re.fullmatch('[a-z0-9-]{1,50}',a.run)),'BAD_RUN')
    out=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;out.mkdir(parents=True,exist_ok=False)
    kernel=ctypes.WinDLL('kernel32',use_last_error=True)
    kernel.VirtualAlloc.restype=ctypes.c_void_p
    kernel.VirtualAlloc.argtypes=[ctypes.c_void_p,ctypes.c_size_t,ctypes.c_uint32,ctypes.c_uint32]
    kernel.VirtualProtect.argtypes=[ctypes.c_void_p,ctypes.c_size_t,ctypes.c_uint32,ctypes.POINTER(ctypes.c_uint32)]
    kernel.VirtualFree.argtypes=[ctypes.c_void_p,ctypes.c_size_t,ctypes.c_uint32]
    kernel.GetCurrentProcess.restype=ctypes.c_void_p
    kernel.FlushInstructionCache.argtypes=[ctypes.c_void_p,ctypes.c_void_p,ctypes.c_size_t]
    # MOVSD xmm0,[rcx]; OP xmm0,[rdx]; MOVQ rax,xmm0; RET (Windows x64 ABI).
    codes={n:bytes.fromhex('f20f1001f20f'+op+'0266480f7ec0c3') for n,op in [('mul','59'),('add','58'),('sub','5c')]}
    codes.update(mxcsr_get=bytes.fromhex('0fae19c3'),mxcsr_set=bytes.fromhex('0fae11c3'))
    ptr=kernel.VirtualAlloc(None,4096,0x3000,0x04);require(bool(ptr),'ALLOC_FAILED')
    mxcsr=ctypes.c_uint32();saved=False;rows=[]
    try:
        offsets={n:i*32 for i,n in enumerate(codes)}
        for name,raw in codes.items():ctypes.memmove(ptr+offsets[name],raw,len(raw))
        old=ctypes.c_uint32()
        require(kernel.VirtualProtect(ptr,4096,0x20,ctypes.byref(old))!=0,'PROTECT_FAILED')
        require(kernel.FlushInstructionCache(kernel.GetCurrentProcess(),ptr,4096)!=0,'FLUSH_FAILED')
        fn_type=ctypes.WINFUNCTYPE(ctypes.c_uint64,ctypes.POINTER(ctypes.c_uint64),ctypes.POINTER(ctypes.c_uint64))
        mx_type=ctypes.WINFUNCTYPE(None,ctypes.POINTER(ctypes.c_uint32))
        get_mx=mx_type(ptr+offsets['mxcsr_get']);set_mx=mx_type(ptr+offsets['mxcsr_set'])
        get_mx(ctypes.byref(mxcsr));saved=True;target=ctypes.c_uint32(0x1f80);set_mx(ctypes.byref(target))
        values=[0,0x8000000000000000,0x3ff0000000000000,0xbff0000000000000,0x7ff0000000000000,0xfff0000000000000,
                0x7ff8000000000123,0xfff8000000000456,0x7ff8000000000789,0x7ff0000000000123,0xfff0000000000456]
        for name in ['mul','add','sub']:
            raw=codes[name];fn=fn_type(ptr+offsets[name])
            u=unicorn.Uc(unicorn.UC_ARCH_X86,unicorn.UC_MODE_64);u.mem_map(0x100000,4096);u.mem_map(0x200000,4096)
            u.mem_write(0x100000,raw)
            for left in values:
                for right in values:
                    l=ctypes.c_uint64(left);r=ctypes.c_uint64(right)
                    physical=int(fn(ctypes.byref(l),ctypes.byref(r)))
                    u.mem_write(0x200000,struct.pack('<2Q',left,right));u.reg_write(x.UC_X86_REG_RCX,0x200000);u.reg_write(x.UC_X86_REG_RDX,0x200008)
                    u.reg_write(x.UC_X86_REG_MXCSR,0x1f80);u.reg_write(x.UC_X86_REG_XMM0,0)
                    u.emu_start(0x100000,0x100000+len(raw)-1)
                    emulated=int(u.reg_read(x.UC_X86_REG_RAX))
                    rows.append(dict(operation=name,left=f'{left:016x}',right=f'{right:016x}',cpu=f'{physical:016x}',unicorn=f'{emulated:016x}',matched=physical==emulated))
    finally:
        if saved:set_mx(ctypes.byref(mxcsr))
        require(kernel.VirtualFree(ptr,0,0x8000)!=0,'FREE_FAILED')
    failures=[r for r in rows if not r['matched']]
    report=dict(tool_sha256=hashlib.sha256(pathlib.Path(__file__).read_bytes()).hexdigest(),unicorn_version=unicorn.__version__,
                mxcsr_used='0x1f80',original_mxcsr=f'{mxcsr.value:#x}',opcodes={n:v.hex() for n,v in codes.items()},
                cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),differences=failures,rows=rows,
                original_ex5_modified=False,whole_bot_complete=False,
                limits=['Standalone CPU/Unicorn arithmetic conformance, not a full original EA run or trade comparison.'])
    with (out/'probe.json').open('x',encoding='utf-8') as f:json.dump(report,f,indent=2)
    print(json.dumps(dict(cases=len(rows),matched=report['matched'],failed=len(failures),first_differences=failures[:8])))
if __name__=='__main__':main()
