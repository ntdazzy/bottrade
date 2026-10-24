"""Analyze native account-state initialization, including exact storage key names.

python -I -B -X utf8 phan-tich-khoi-tao-von-bot-1-3.py BOT NEW_RUN
Runs only the bounded initialization segment. Account/clock/storage/string-format
APIs are supplied boundaries; native concatenation/selection code runs unchanged.
No MT5 process or real terminal variable is changed. Diagnostic text is excluded.
"""
import argparse
import importlib.util
import itertools
import json
import math
from pathlib import Path
import re
import struct

ROOT=Path(__file__).resolve().parents[1]


def module(name,file):
    s=importlib.util.spec_from_file_location(name,Path(__file__).with_name(file))
    v=importlib.util.module_from_spec(s);s.loader.exec_module(v);return v


entry=module('entry','kiem-gia-vao-bot-1-3.py')
currency=module('currency','kiem-doi-tien-bot-1-3.py')
CONFIG={
    1:dict(start=0x126c,end=0x1941,preloads=[0xc57,0xd74,0xd7e],current=0x6a320,
           peak=0x6a328,peak_key=0x6a330,time_key=0x6a340,last_time=0x6a350),
    3:dict(start=0x1279,end=0x193f,preloads=[0xd74,0xd7e,0xef2,0x1235],current=0x1d6c60,
           peak=0x1d6c68,peak_key=0x1d6cc8,time_key=0x1d6cd8,last_time=0x1d6ce8),
}


def signed64(value):
    return value if value<1<<63 else value-(1<<64)


def native_integer(value):
    if not math.isfinite(value) or value<-(1<<63) or value>=1<<63:return -(1<<63)
    return int(value)


def cases():
    for login,reset,equity,manual,peak,exists in itertools.product(
            [0,279786616,(1<<63)-1],[0,1],[0,1],[0.,25000.,-1.],
            [None,-1.,5000.,10000.,15000.,float('nan'),float('inf')],[0,1]):
        yield dict(login=login,reset=reset,use_equity=equity,manual=manual,balance=10000.,
                   equity=9000.,stored_peak=peak,time_exists=exists,stored_time=1700000012.75,now=1700001000)
    for field,value,reset,equity in itertools.product(
            ['balance','equity','manual','stored_time'],
            [-0.,0.,-100.,float('nan'),float('inf'),-float('inf'),float(1<<63)], [0,1],[0,1]):
        c=dict(login=279786616,reset=reset,use_equity=equity,manual=0.,balance=10000.,
               equity=9000.,stored_peak=15000.,time_exists=1,stored_time=1700000012.75,now=1700001000)
        c[field]=value;yield c


def hypothesis(c):
    peak_key='HighestBalance'+str(c['login']);time_key='LastBalanceOp'+str(c['login'])
    current=c['equity'] if c['use_equity'] else c['balance']
    trace=[['account_double',37,entry.bits(c['balance'])]]
    if c['use_equity']:trace.append(['account_double',40,entry.bits(c['equity'])])
    trace.append(['account_integer',0,c['login']])
    stored=0. if c['stored_peak'] is None else c['stored_peak']
    if c['reset']:
        stored=0.;trace += [['set',peak_key,entry.bits(0.)],['sleep',5000]]
    trace.append(['get',peak_key,entry.bits(stored)])
    peak=stored if current<stored else current
    trace += [['set',peak_key,entry.bits(peak)],['account_integer',0,c['login']],['check',time_key,bool(c['time_exists'])]]
    if not c['reset'] and c['time_exists']:
        trace.append(['get',time_key,entry.bits(c['stored_time'])]);when=native_integer(c['stored_time'])
    else:
        trace.append(['time_current',c['now']]);when=c['now']
    trace.append(['set',time_key,entry.bits(float(when))])
    if c['manual']>0.:current=c['manual']
    return dict(current_bits=entry.bits(current),peak_bits=entry.bits(peak),last_time=when,
                peak_key=peak_key,time_key=time_key,trace=trace)


class Original(entry.Original):
    def __init__(self,bot):
        super().__init__(bot);self.state_cfg=CONFIG[bot]
        self.binding_path=ROOT/f'bot-cua-toi-{bot}/phan-tich/cai-dat-20261023/cai-dat-da-kiem.json'
        self.bindings={f['name']:f for f in json.loads(self.binding_path.read_text())['bindings']}
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        self.meta_path=ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json'
        self.meta=json.loads(self.meta_path.read_text())
        import capstone
        md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64)
        function=next(f for f in self.meta['functions'] if f['begin_rva']=='0xc30')
        raw=next(raw for region,raw in self.regions if region['base']==self.base)
        self.instructions={i.address-self.base:i for i in md.disasm(raw[0xc30:int(function['end_rva'],16)],self.base+0xc30)}
        for rva in [self.state_cfg['start'],self.state_cfg['end'],*self.state_cfg['preloads']]:
            if rva not in self.instructions:raise ValueError('NOT_AN_INSTRUCTION_BOUNDARY')
        for rva in self.state_cfg['preloads']:
            if self.instructions[rva].mnemonic!='movabs':raise ValueError('PRELOAD_NOT_ORIGINAL_IMMEDIATE')
        eb=int(self.meta['engine']['engine_base'],16)
        extra={eb+rva:name for rva,name in [(0x797370,'account_double'),(0x7973c0,'account_integer'),
            (0x7cdfe0,'integer_string'),(0x7ce4f0,'string_integer'),(0x7cf6c0,'cast_string'),
            (0x7bdbe0,'get'),(0x7bdc90,'set'),(0x7bdda0,'check'),(0x7d1c40,'time_current'),
            (0x7b17c0,'sleep'),(0x7b49f0,'print'),(0x3959a0,'error')]}
        for page in {address&~4095 for address in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for address in extra:
            self.m.mem_write(address,b'\xc3')
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,*_:m.emu_stop(),
                        begin=self.base+self.state_cfg['end'],end=self.base+self.state_cfg['end'])

    def put_string(self,address,text):
        self.m.mem_write(address,struct.pack('<IQ',0,self.string(text)))

    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;c=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        arg=m.reg_read(x.UC_X86_REG_RDX)
        if api=='account_double':
            if arg not in [37,40]:raise ValueError('UNEXPECTED_ACCOUNT_DOUBLE')
            value=c['balance' if arg==37 else 'equity'];raw=struct.pack('<d',value)
            m.mem_write(self.base+self.cfg['slot'],raw)
            m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'))
            self.events.append([api,arg,entry.bits(value)])
        elif api=='account_integer':
            if arg!=0:raise ValueError('UNEXPECTED_ACCOUNT_INTEGER')
            m.reg_write(x.UC_X86_REG_RAX,c['login']);self.events.append([api,0,c['login']])
        elif api=='integer_string':
            if m.reg_read(x.UC_X86_REG_R8)!=0:raise ValueError('UNEXPECTED_INTEGER_STRING_WIDTH')
            self.put_string(self.base+self.cfg['string_result'],str(signed64(arg)))
        elif api=='string_integer':
            text=currency.Original.read_text(self,arg)
            m.reg_write(x.UC_X86_REG_RAX,int(text)&entry.MASK)
        elif api=='cast_string':
            kind=m.reg_read(x.UC_X86_REG_R8)
            if kind not in [0x55,0x58]:raise ValueError('UNEXPECTED_STRING_CAST_TYPE')
            # Integer formatting affects storage names. Double formatting here
            # is used only by the diagnostic message and is outside this check.
            self.put_string(m.reg_read(x.UC_X86_REG_R9),str(arg) if kind==0x55 else '')
        elif api in ['get','set','check']:
            key=currency.Original.read_text(self,arg)
            if api=='get':
                value=self.store.get(key,0.);raw=struct.pack('<d',value)
                m.mem_write(self.base+self.cfg['slot'],raw);m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'))
                self.events.append([api,key,entry.bits(value)])
            elif api=='set':
                bits=m.reg_read(x.UC_X86_REG_XMM2)&entry.MASK
                self.store[key]=struct.unpack('<d',struct.pack('<Q',bits))[0]
                m.reg_write(x.UC_X86_REG_RAX,0);self.events.append([api,key,bits])
            else:
                present=key in self.store;m.reg_write(x.UC_X86_REG_RAX,int(present))
                self.events.append([api,key,present])
        elif api=='time_current':
            m.reg_write(x.UC_X86_REG_RAX,c['now']&entry.MASK);self.events.append([api,c['now']])
        elif api=='sleep':self.events.append([api,arg])
        elif api=='print':
            if arg!=2:raise ValueError('UNEXPECTED_DISPATCH')
        else:raise ValueError('UNEXPECTED_NATIVE_API '+str(api))

    def run(self,c):
        m,x=self.m,self.x;cfg=self.state_cfg;self.case=c;self.cursor=0x70001000
        self.allocs=self.frees=0;self.events=[];self.count=0;self.hash=0;self.prefix=[]
        self.store={}
        if c['stored_peak'] is not None:self.store['HighestBalance'+str(c['login'])]=c['stored_peak']
        if c['time_exists']:self.store['LastBalanceOp'+str(c['login'])]=c['stored_time']
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        m.mem_write(0x50000000,b'\0'*0x20000)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:
            m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        for name in ['peak_key','time_key']:m.mem_write(self.base+cfg[name],b'\0'*12)
        m.mem_write(self.base+self.cfg['string_result'],b'\0'*12)
        for name,value,fmt in [('UseEquity',c['use_equity'],'B'),('ResetHighestBalance',c['reset'],'B'),('ManualBalance',c['manual'],'d')]:
            binding=self.bindings[name]
            if not binding['original_memory_binding_verified']:raise ValueError('UNVERIFIED_INPUT_BINDING')
            m.mem_write(self.base+int(binding['candidate_rva'],16),struct.pack('<'+fmt,value))
        m.reg_write(x.UC_X86_REG_RSP,0x50010000)
        for rva in cfg['preloads']:
            instruction=self.instructions[rva]
            m.emu_start(instruction.address,instruction.address+instruction.size,count=1)
        try:m.emu_start(self.base+cfg['start'],self.base+cfg['end'],count=100000,timeout=2000000)
        except self.uc.UcError as e:
            raise RuntimeError(f'PREFIX_ERROR rip={m.reg_read(x.UC_X86_REG_RIP):x} events={self.events}') from e
        if m.reg_read(x.UC_X86_REG_RIP)!=self.base+cfg['end']:raise ValueError('PREFIX_NOT_COMPLETED')
        return dict(current_bits=struct.unpack('<Q',m.mem_read(self.base+cfg['current'],8))[0],
                    peak_bits=struct.unpack('<Q',m.mem_read(self.base+cfg['peak'],8))[0],
                    last_time=struct.unpack('<q',m.mem_read(self.base+cfg['last_time'],8))[0],
                    peak_key=currency.Original.read_text(self,self.base+cfg['peak_key']),
                    time_key=currency.Original.read_text(self,self.base+cfg['time_key']),trace=self.events)


def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/phan-tich/khoi-tao-von'/a.run;out.mkdir(parents=True,exist_ok=False)
    o=Original(a.bot);values=list(cases());failures=[]
    with (out/'results.jsonl').open('x',encoding='utf-8') as stream:
        for i,c in enumerate(values):
            actual=o.run(c);expected=hypothesis(c)
            row={'case':i,'inputs':c,'original':actual,'hypothesis':expected,'matched':actual==expected}
            stream.write(json.dumps(row,ensure_ascii=False)+'\n')
            if not row['matched']:failures.append(row)
    result={'bot':a.bot,'passed':not failures,'cases':len(values),'matched':len(values)-len(failures),
            'failed':len(failures),'first_failures':failures[:5],'segment':CONFIG[a.bot],
            'preload_instructions':[f'{rva:#x} {o.instructions[rva].mnemonic} {o.instructions[rva].op_str}' for rva in CONFIG[a.bot]['preloads']],
            'tool_sha256':entry.sha(Path(__file__)),'binding_evidence_sha256':entry.sha(o.binding_path),
            'metadata_sha256':entry.sha(o.meta_path),'code_sha256':o.meta['code_sha256'],'data_sha256':o.meta['data_sha256'],
            'results_sha256':entry.sha(out/'results.jsonl'),
            'scope':'Bounded native initialization segment against an explicit hypothesis. Native string concatenation and state updates; account/clock/storage/format APIs supplied. Original immediate loads supply caller register preconditions. No license checks modified or exercised, no entire OnInit verification, diagnostic text/last-error codes/allocation failures excluded; not MQL5 or complete EA comparison.'}
    (out/'summary.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf-8')
    print(json.dumps({k:result[k] for k in ['bot','passed','cases','matched','failed','first_failures']}))
    raise SystemExit(bool(failures))


if __name__=='__main__':main()
