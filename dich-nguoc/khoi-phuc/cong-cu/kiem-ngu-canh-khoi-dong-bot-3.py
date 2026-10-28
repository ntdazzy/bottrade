"""Compare bot 3 startup context after selection, before first preparation.

generate | prepare|mql5 --build BUILD|original|compare RUN.
Native 0x3ce6..0x4580 runs its actual strings and four CPU multiplications.
Authorization and earlier time/account/frequency selection are not executed.
"""
import hashlib,importlib.util,inspect,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
s=importlib.util.spec_from_file_location('startup3_context_contract',ROOT/'cong-cu/kiem-ngu-canh-khoi-dong-bot-1.py');b=importlib.util.module_from_spec(s);s.loader.exec_module(b)
require,sha=b.require,b.sha
b.FIELDS=[('BootContext.magic','i',0x6d564),('BootContext.converted_value','d',0x76fa0),('BootInputs.base_magic','i',0x1d6ff0),
 ('BootInputs.keep_comment','B',0x1d7008),('BootDaily.peak','d',0x75348),('BootDaily.blocked','B',0x75320),('BootDaily.bars','i',0x75324),
 ('BootState.panel_bar','q',0x75338),('BootHistory.total','i',0x77358),('BootHistory.count','i',0x77354),('BootState.extended_cleanup','B',0x752d4),
 ('BootPanel.cell_font_flag','B',0x752e8),('BootState.cell_base_x','d',0x75328),('BootState.cell_base_y','d',0x75330),
 ('BootPanel.scale','d',0x1d6f48),('BootPanel.cell_x','d',0x752d8),('BootPanel.cell_y','d',0x752e0)]
b.TEXTS=[('BootInputs.comment_prefix',0x1d6ff8),('BootInputs.symbol_suffix',0x6d230),('BootContext.order_comment',0x6d568),
 ('BootPreparation.symbol',0x74958),('BootChartSymbol',0x1d6e28)]
b.INIT_SHA='66812ca6397edc00b872cfc3b38ca7606cc3dc7d5cf084433c579ea13e90771c'
b.TEMPLATE=b.TEMPLATE.replace('Bot1','Bot3').replace('bot1','bot3').replace('bot-cua-toi-1','bot-cua-toi-3')

class Native(b.base.Original):
    def __init__(self):
        super().__init__(3);require(self.base==0x17156250000,'BOT3_BASE_CHANGED')
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+0xc30,0x61a0-0xc30))).hexdigest()==b.INIT_SHA,'BOT3_INIT_CHANGED')
        self.print_api=0x7ff6846d49f0
        if not any(lo<=self.print_api<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(self.print_api&~4095,4096)
        self.m.mem_write(self.print_api,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=self.print_api,end=self.print_api)
        self.host=b.HostProduct();self.mul_count=0
        self.products={0x3db9:('XMM2','mem','RAX'),0x3dcb:('XMM2','reg','XMM1'),0x3e0e:('XMM0','mem','RAX'),0x3e1c:('XMM1','reg','XMM0')}
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        md=Cs(CS_ARCH_X86,CS_MODE_64)
        expected={0x3db9:'xmm2, qword ptr [rax]',0x3dcb:'xmm2, xmm1',0x3e0e:'xmm0, qword ptr [rax]',0x3e1c:'xmm1, xmm0'}
        for off in self.products:
            ins=next(md.disasm(bytes(self.m.mem_read(self.base+off,15)),self.base+off));require(ins.mnemonic=='mulsd' and ins.op_str==expected[off],'BOT3_MULTIPLICATION_CHANGED')
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.multiply,begin=self.base+off,end=self.base+off)
        require(struct.unpack('<2d',self.m.mem_read(self.base+0x57d00,16))==(175.,24.5),'BOT3_PANEL_FACTORS_CHANGED')
        for off in [0xc30,0x61a0,0x485e0,0x55bc0]:self.m.hook_add(self.uc.UC_HOOK_CODE,self.protected,begin=self.base+off,end=self.base+off)
    def protected(self,m,address,size,user):raise RuntimeError('AUTHORIZATION_OUTSIDE_CONTEXT_SCOPE')
    def close(self):self.host.close()
    def multiply(self,m,address,size,user):
        dest,kind,right=self.products[address-self.base];x=self.x;left=m.reg_read(getattr(x,'UC_X86_REG_'+dest))
        value=struct.unpack('<Q',m.mem_read(m.reg_read(getattr(x,'UC_X86_REG_'+right)),8))[0] if kind=='mem' else m.reg_read(getattr(x,'UC_X86_REG_'+right))&b.MASK
        result=self.host.mul(left&b.MASK,value);m.reg_write(getattr(x,'UC_X86_REG_'+dest),(left&~b.MASK)|result);m.reg_write(x.UC_X86_REG_RIP,address+size);self.mul_count+=1
    def put_text(self,off,value):self.m.mem_write(self.base+off,struct.pack('<IQ',0,0 if value is None else self.string(value)))
    def state(self):
        raw=bytearray()
        for _,kind,off in b.FIELDS:
            fmt='Q' if kind=='d' else kind;v=struct.unpack('<'+fmt,self.m.mem_read(self.base+off,struct.calcsize('<'+fmt)))[0];raw+=struct.pack('<Q',v&b.MASK)
        raw+=struct.pack('<Q',struct.unpack('<I',self.m.mem_read(self.base+0x1d6e10,4))[0])
        return bytes(raw)+b''.join(b.text(self.read_text(self.base+off)) for _,off in b.TEXTS)
    def call(self,m,address,size,user):
        if address!=self.print_api:return super().call(m,address,size,user)
        x=self.x;require(m.reg_read(x.UC_X86_REG_RCX)==self.gate['ctx'] and m.reg_read(x.UC_X86_REG_RDX)==2 and m.reg_read(x.UC_X86_REG_R8)==1 and m.reg_read(x.UC_X86_REG_R9)==0x590008,'BOT3_PRINT_ARGUMENTS')
        sp=m.reg_read(x.UC_X86_REG_RSP);desc=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
        self.events+=self.state()+b.text(self.read_text(desc));self.prints+=1
    def run(self,c):
        self.case,self.events,self.prints,self.cursor=c,bytearray(),0,0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for (_,kind,off),value in zip(b.FIELDS,c['values']):
            size=struct.calcsize('<'+kind);word=b.bits(value) if kind=='d' else int(value)&((1<<(8*size))-1);m.mem_write(self.base+off,word.to_bytes(size,'little'))
        for (_,off),value in zip(b.TEXTS,c['texts']):self.put_text(off,value)
        self.put_text(0x1d6e3c,'12345');m.mem_write(self.base+0x1d6e10,struct.pack('<I',65536+731 if c['error'] else 0))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        sp=0x5001fc00;m.mem_write(sp,bytes(0x300));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        m.reg_write(x.UC_X86_REG_R15,self.base+0x5c0);m.reg_write(x.UC_X86_REG_R12,self.print_api)
        m.emu_start(self.base+0x3ce6,self.base+0x4580,timeout=3000000,count=300000)
        require(m.reg_read(x.UC_X86_REG_RIP)==self.base+0x4580,'BOT3_CONTEXT_NOT_FINISHED')
        return bytes(self.events)+self.state()+struct.pack('<i',self.prints)

def identity():
    src=ROOT/'bot-cua-toi-3/source/MQL5';script=src/'Scripts/bot-cua-toi-3/Bot3StartupContextCheck.mq5'
    helpers=[Path(__file__),Path(b.__file__),Path(b.base.__file__),Path(b.history.__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-nfp-toan-nhanh-bot-1-3.py',ROOT/'danh-gia-doc-lap/strategy-history-20261028-r1/nan-add-cpu-probe.json']
    return dict(original_ex5_sha256=b.base.base.validation.original_hash(3),native_init_sha256=b.INIT_SHA,
      sources_sha256={p.relative_to(src).as_posix():sha(p) for p in b.pub.closure(script,src)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})

for function in ['generate','main']:
    source=inspect.getsource(getattr(b,function)).replace('Bot1','Bot3').replace('bot1','bot3').replace('bot-cua-toi-1','bot-cua-toi-3')
    source=source.replace('Caller live-in XMM6=0 and non-null string-return buffer supplied','Earlier time/currency/frequency selection is excluded; non-null string-return buffer supplied')
    exec(compile(source,__file__,'exec'),b.__dict__)
b.identity=identity;b.Native=Native
b.SCOPE=dict(b.SCOPE,whole_bot_complete=False,whole_manager_complete=False,caller_xmm6_zero_supplied=False,
 authorization_executed=False,authorization_entry_guarded=True,frequency_selection_executed=False,first_preparation_executed=False)
if __name__=='__main__':b.main()
