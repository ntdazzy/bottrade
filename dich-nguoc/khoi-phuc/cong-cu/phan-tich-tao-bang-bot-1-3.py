"""Inspect the unchanged full panel constructor; analysis replies are synthetic.

BOT OUTPUT_DIRECTORY. This is evidence of control flow, not a passing MQL5 test.
"""
import argparse, hashlib, importlib.util, json, re, struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location('panel_cell', ROOT/'cong-cu/kiem-o-bang-hien-thi-bot-1-3.py')
cell = importlib.util.module_from_spec(spec); spec.loader.exec_module(cell)
require = cell.require
CFG = {
    1: dict(fn=0x8320, scale=0x6a538, font=0x6a540, mode=0x6a748, flag=0x678f8,
            frequency=None, constants=(0x4fd60,0x4fdd0), arrays=[0x69f80,0x67ad0,0x66a80]),
    3: dict(fn=0xef40, scale=0x1d6f48, font=0x1d6f50, mode=0x6d630, flag=0x74938,
            frequency=0x6d21c, constants=(0x57dc0,0x57e20), arrays=[0x76fc0,0x74b10,0x73ac0]),
}
SDK = {1:0x7cdfe0, 2:0x7b49f0, 3:0x7c3b30, 4:0x7c3c80,
       5:0x7c4840, 6:0x7cd7c0, 7:0x7d1ce0, 8:0x7cf6c0}

class Trace(cell.shared.entry.Original):
    def __init__(self, bot):
        super().__init__(bot); self.bot=bot; self.panel=CFG[bot]
        run='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich/{run}/metadata/import.json').read_text())
        fn=next(f for f in meta['functions'] if int(f['begin_rva'],16)==self.panel['fn'])
        self.end=int(fn['end_rva'],16)
        self.body_sha=hashlib.sha256(bytes(self.m.mem_read(self.base+self.panel['fn'],self.end-self.panel['fn']))).hexdigest()
        self.sdk={0x7ff683f20000+off:api for api,off in SDK.items()}
        for address in self.sdk:
            existed=address in self.apis
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.reads=set();self.writes=set();self.covered=set()
        for typ in ['READ','WRITE']:
            self.m.hook_add(getattr(self.uc,'UC_HOOK_MEM_'+typ),self.memory)
        self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,a,s,u:self.covered.add(a-self.base),
                        begin=self.base+self.panel['fn'],end=self.base+self.end-1)

    read_text=cell.Native.read_text

    def memory(self,m,access,address,size,value,user):
        if any(r.get('kind')=='mutable_program_data' and r['base']<=address<r['base']+r['bytes'] for r,_ in self.regions):
            (self.writes if access==self.uc.UC_MEM_WRITE else self.reads).add((address-self.base,size))

    def call(self,m,address,size,user):
        if address not in self.sdk:return super().call(m,address,size,user)
        api=self.sdk[address];x=self.x;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));sp=r('RSP')
        row=dict(api=api,caller=hex(struct.unpack('<Q',m.mem_read(sp,8))[0]-self.base))
        reply=None
        if api==1:
            value=struct.unpack('<q',struct.pack('<Q',r('RDX')))[0];width=r('R8')&0xffffffff;fill=r('R9')&65535
            row.update(value=value,width=width,fill=fill);reply=str(value)
        elif api==2:
            packet=struct.unpack('<11Q',m.mem_read(sp+40,88))
            require((r('RDX'),r('R8'),r('R9'))==(274,6,0x550005),'CREATE_PACKET')
            require([packet[i] for i in [1,3,5,7,9]]==[0x590008,0x520004,0x520004,0x540005,0x580007],'CREATE_TYPES')
            row.update(chart=packet[0],name=self.read_text(packet[2]),type=packet[4],window=packet[6],time=packet[8],price_bits=packet[10])
        elif api in [3,4]:
            extra=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
            row.update(chart=r('RDX'),name=self.read_text(r('R8')),property=r('R9'))
            row['value']=struct.unpack('<q',struct.pack('<Q',extra))[0] if api==3 else self.read_text(extra)
        elif api==5:row.update(chart=r('RDX'),name=self.read_text(r('R8')))
        elif api==6:
            v=struct.unpack('<d',struct.pack('<Q',r('XMM1')&cell.MASK))[0];digits=r('R8')&0xffffffff
            row.update(value=v,digits=digits);reply=format(v,'.'+str(digits)+'f')
        elif api==7:require(r('RDX')==0,'SERVER_OVERLOAD')
        elif api==8:
            value=r('RDX');kind=r('R8');row.update(value_bits=value,type=kind)
            reply=str(struct.unpack('<d',struct.pack('<Q',value))[0]) if kind==0x58 else str(struct.unpack('<q',struct.pack('<Q',value))[0])
        row['ordinal']=len(self.events)+1;self.events.append(row)
        if reply is not None:
            target=r('R9') if api==8 else self.base+self.cfg['string_result']
            m.mem_write(target,struct.pack('<IQ',0,self.string(reply)))
        else:m.reg_write(x.UC_X86_REG_RAX,1767355200 if api==7 else 0 if api==5 else 1)

    def run(self,mode=0,frequency=3):
        m,x=self.m,self.x;c=self.panel;self.events=[];self.case={};self.cursor=0x70001000;self.allocs=self.frees=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        m.mem_write(self.base+c['scale'],struct.pack('<d',1.0));m.mem_write(self.base+c['font'],struct.pack('<i',7))
        m.mem_write(self.base+c['mode'],struct.pack('<i',mode));m.mem_write(self.base+c['flag'],b'\x01')
        if c['frequency']:m.mem_write(self.base+c['frequency'],struct.pack('<i',frequency))
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        top=0x5001fef8;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        try:m.emu_start(self.base+c['fn'],0x60000000,timeout=10000000,count=4000000)
        except self.uc.UcError as e:raise RuntimeError(str(e)+' rip='+hex(m.reg_read(x.UC_X86_REG_RIP))+' last='+str(self.events[-3:])) from e
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_NO_RETURN')
        return dict(bot=self.bot,original_ex5_sha256=cell.shared.selector.validation.original_hash(self.bot),
                    body=dict(begin=hex(c['fn']),end=hex(self.end),sha256=self.body_sha),
                    mode=mode,frequency=frequency,events=self.events,
                    reads=[dict(rva=hex(a),size=s) for a,s in sorted(self.reads)],
                    writes=[dict(rva=hex(a),size=s) for a,s in sorted(self.writes)],
                    constants={hex(a):struct.unpack('<d',m.mem_read(self.base+a,8))[0] for a in range(*c['constants'],8)},
                    instructions=len(self.covered),full_ea=False,synthetic_analysis_replies=True,
                    mql5_equivalence_proven=False)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('output');p.add_argument('--mode',type=int,default=0);p.add_argument('--frequency',type=int,default=3);a=p.parse_args()
    require(re.fullmatch('[a-z0-9-]+',a.output),'BAD_OUTPUT')
    folder=ROOT/f'danh-gia-doc-lap/{a.output}';folder.mkdir(parents=True,exist_ok=True)
    result=Trace(a.bot).run(a.mode,a.frequency)
    cell.save(folder/f'bot{a.bot}-mode{a.mode}-frequency{a.frequency}.json',result)
    print(json.dumps(dict(bot=a.bot,body=result['body'],events=len(result['events']),instructions=result['instructions'])))

if __name__=='__main__':main()
