"""Observe the original post-2026 NFP fallback StringToTime argument.

BOT OUTPUT_JSON. Only the string-building slice executes, ending before parsing.
"""
import argparse,calendar,hashlib,importlib.util,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
s=importlib.util.spec_from_file_location('nfp_manual_entry',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py');entry=importlib.util.module_from_spec(s);s.loader.exec_module(entry)
CFG={1:dict(start=0x1b8f4,day=0x67798,weekday=0x677a8,year_function=0x2ffb0,year_register='R13',context=0x23e575eae78,function=0x18aa0,end=0x1ef9c,sha='45d53270186b7019a8721e0cf3734a61aac8e8660c70f7e602849b1c298d7cbd'),
     3:dict(start=0x23f0a,day=0x747d8,weekday=0x747e8,year_function=0x3d5f0,year_register='R14',context=0x171514ca538,function=0x20ef0,end=0x2a1bc,sha='6bead161fa97b6568b546e8c86a4ff03fdda55d6fb226a52b58dd14ec050d920')}
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('output',type=Path);a=p.parse_args();o=entry.Original(a.bot);cfg=CFG[a.bot];base=o.base;m,x=o.m,o.x;events=[]
    assert hashlib.sha256(bytes(m.mem_read(base+cfg['function'],cfg['end']-cfg['function']))).hexdigest()==cfg['sha']
    eb=0x7ff683f20000;apis={eb+0x7d1c40:'TimeCurrent',eb+0x7cdfe0:'IntegerToString',eb+0x7cd370:'StringToTime'}
    def read(desc):
        ptr=struct.unpack('<Q',m.mem_read(desc+4,8))[0]
        if not ptr:return None
        n=struct.unpack('<I',m.mem_read(ptr-4,4))[0];assert n<1000;return bytes(m.mem_read(ptr,2*n)).decode('utf-16-le')
    def hook(emu,address,size,user):
        api=apis[address];r=lambda n:emu.reg_read(getattr(x,'UC_X86_REG_'+n));ret=struct.unpack('<Q',emu.mem_read(r('RSP'),8))[0]-base;assert r('RCX')==cfg['context']
        if api=='TimeCurrent':
            dt=[2027,1,1,0,0,0,5,0];ptr=r('RDX')
            if ptr:emu.mem_write(ptr,struct.pack('<8i',*dt))
            emu.reg_write(x.UC_X86_REG_RAX,calendar.timegm((2027,1,1,0,0,0)));events.append(dict(api=api,return_rva=hex(ret),out_struct=bool(ptr)))
        elif api=='IntegerToString':
            v=(r('RDX')+(1<<63))%(1<<64)-(1<<63);width=r('R8')&0xffffffff;fill=r('R9')&65535;assert width==0 and fill==32
            reply=str(v);emu.mem_write(base+o.cfg['string_result'],struct.pack('<IQ',0,o.string(reply)));events.append(dict(api=api,value=v,width=width,fill=fill,return_rva=hex(ret),result=reply))
        else:events.append(dict(api=api,text=read(r('RDX')),return_rva=hex(ret)));emu.emu_stop()
    for address in apis:
        if not any(lo<=address<=hi for lo,hi,_ in m.mem_regions()):m.mem_map(address&~4095,4096)
        m.mem_write(address,b'\xc3');m.hook_add(o.uc.UC_HOOK_CODE,hook,begin=address,end=address)
    o.case={};o.cursor=0x70001000;o.allocs=o.frees=0
    for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
    for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
    frame=0x5001f000;m.mem_write(frame,bytes(0x500));m.reg_write(x.UC_X86_REG_RSP,frame);m.reg_write(x.UC_X86_REG_RBP,base+0x5c0);m.reg_write(x.UC_X86_REG_R12,base+0x5c0);m.reg_write(getattr(x,'UC_X86_REG_'+cfg['year_register']),base+cfg['year_function']);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
    m.mem_write(base+cfg['day'],struct.pack('<i',1));m.mem_write(base+cfg['weekday'],struct.pack('<i',5));m.emu_start(base+cfg['start'],0x60000000,timeout=3000000,count=1000000)
    assert events[-1]['api']=='StringToTime' and events[-1]['text']=='202711 1230'
    result=dict(bot=a.bot,start_rva=hex(cfg['start']),evaluator_sha256=cfg['sha'],tool_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),events=events,scope='Manual fallback string-building slice only. Initial frame/cached calendar and TimeCurrent/IntegerToString SDK replies supplied; stop before StringToTime. Earlier DST/year branch and actions not executed.',whole_bot_complete=False)
    with a.output.open('x',encoding='utf-8',newline='\n') as f:json.dump(result,f,ensure_ascii=False,indent=2)
    print(json.dumps(result,ensure_ascii=False))
if __name__=='__main__':main()
