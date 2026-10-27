"""Read native open-status text construction with symbolic formatting replies.
Usage: BOT OUTPUT_JSON. This is analysis, not a behavioral pass or a live UI run.
"""
import importlib.util,json,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
spec=importlib.util.spec_from_file_location('panel_entry',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py')
entry=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry)
CFG={1:dict(fn=0xe1b0,enabled=0x6a528,tester=0x6a530,nfp=0x6a640,ir=0x6a698,cpi=0x6a6d0,symbol=0x67918,error=0x6a410),3:dict(fn=0x14fa0,enabled=0x1d6f38,tester=0x1d6f40,nfp=0x1d7020,ir=0x1d7078,cpi=0x1d70b0,symbol=0x74958,error=0x1d6e10)}
class Trace(entry.Original):
    def __init__(self,bot,options=None):
        super().__init__(bot);self.panel=CFG[bot];self.events=[];self.cfg.update(self.panel);self.options=options or {}
        offsets={0x7c0fd0:'info',0x7d7da0:'positions',0x7cd7c0:'double-text',0x7cdfe0:'integer-text',0x7ccc50:'time-text',0x7c3c80:'set-text',0x7d1ce0:'server',0x7cf6c0:'cast-text'}
        self.extra={0x7ff683f20000+k:v for k,v in offsets.items()}
        for address in self.extra:
            existed=address in self.apis
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
    def read_text(self,pointer):
        value=struct.unpack('<Q',self.m.mem_read(pointer+4,8))[0]
        if not value:return None
        n=struct.unpack('<I',self.m.mem_read(value-4,4))[0]
        return bytes(self.m.mem_read(value,n*2)).decode('utf-16-le')
    def supply(self,text):self.m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(text)))
    def call(self,m,address,size,user):
        if address not in self.extra:return super().call(m,address,size,user)
        name=self.extra[address];x=self.x;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));event=dict(api=name)
        if name=='info':event['property']=r('RDX');m.reg_write(x.UC_X86_REG_RAX,self.options.get('info',0))
        elif name=='positions':m.reg_write(x.UC_X86_REG_RAX,0)
        elif name=='double-text':
            value=struct.unpack('<d',struct.pack('<Q',r('XMM1')&((1<<64)-1)))[0];event.update(value=value,digits=r('R8')&0xffffffff);self.supply('<D'+str(len(self.events))+'>')
        elif name=='integer-text':event.update(value=r('RDX'),width=r('R8')&0xffffffff,fill=r('R9')&65535);self.supply(str(r('RDX')))
        elif name=='time-text':event.update(value=r('RDX'),flags=r('R8'));self.supply('<TIME>')
        elif name=='cast-text':
            event.update(value=r('RDX'),kind=r('R8'));m.mem_write(r('R9'),struct.pack('<IQ',0,self.string('<CAST'+str(len(self.events))+'>')))
        elif name=='set-text':
            argument=struct.unpack('<Q',m.mem_read(r('RSP')+40,8))[0];event.update(chart=r('RDX'),name=self.read_text(r('R8')),property=r('R9'),text=self.read_text(argument));m.reg_write(x.UC_X86_REG_RAX,1)
        else:event['time']=1767355200;m.reg_write(x.UC_X86_REG_RAX,1767355200)
        self.events.append(event)
    def run(self):
        m,x=self.m,self.x;self.case={};self.cursor=0x70001000;self.allocs=self.frees=0
        for key in ['enabled','tester']:m.mem_write(self.base+self.panel[key],bytes([1]))
        for key in ['nfp','ir','cpi']:m.mem_write(self.base+self.panel[key],bytes([0]))
        for address,value in self.options.get('words',{}).items():m.mem_write(self.base+int(address,16),struct.pack('<I',value&0xffffffff))
        for address,value in self.options.get('longs',{}).items():m.mem_write(self.base+int(address,16),struct.pack('<q',value))
        for address,value in self.options.get('doubles',{}).items():m.mem_write(self.base+int(address,16),struct.pack('<d',value))
        for address,value in self.options.get('bytes',{}).items():m.mem_write(self.base+int(address,16),bytes([value]))
        m.mem_write(self.base+self.panel['error'],bytes(4));m.mem_write(self.base+self.cfg['string_result'],bytes(12));m.mem_write(self.base+self.panel['symbol'],struct.pack('<IQ',0,self.string('XAUUSD')))
        for register in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+register),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        top=0x5001f000;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        try:m.emu_start(self.base+self.panel['fn'],0x60000000,timeout=15000000,count=2000000)
        except self.uc.UcError as error:raise RuntimeError('RIP=%x EVENTS=%s %s'%(m.reg_read(x.UC_X86_REG_RIP),json.dumps(self.events),error)) from error
        assert m.reg_read(x.UC_X86_REG_RIP)==0x60000000
        return dict(bot=self.bot,events=self.events,scope='symbolic SDK text replies; zero positions; analysis only')
if __name__=='__main__':
    bot=int(sys.argv[1]);options=json.loads(Path(sys.argv[3]).read_text(encoding='utf-8')) if len(sys.argv)>3 else {};result=Trace(bot,options).run();Path(sys.argv[2]).write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps(result,ensure_ascii=False))
