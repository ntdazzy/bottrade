"""Compare continuous bot1 symbol routing -> optional real virtual-stop cleanup.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Stops before direct evaluator 0x12004 or configured strategy loop 0x12424.
"""
import copy,hashlib,importlib.util,inspect,struct,sys,textwrap
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
b=module('route_cleanup_matrix','kiem-bang-dung-ao-day-du-bot-1.py');route=module('route_cleanup_symbol','kiem-ma-gia-dieu-phoi-bot-1.py')
require,sha=b.require,b.sha;BASE_NATIVE=b.Original;BASE_ENCODE=b.encode;BASE_IDENTITY=b.identity;BASE_CASES=b.cases
b.MT=ROOT.parent/'.local/mt5-bot1-thread-20261025';b.MAGIC=0x54534d31;b.VERSION=3
SCRIPT_PATH=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1TickStrategyPreparationCheck.mq5'
TEMPLATE_PATH=SCRIPT_PATH.with_name('Bot1VirtualStopsCheck.mq5')
b.SOURCES[2]='Scripts/bot-cua-toi-1/Bot1TickStrategyPreparationCheck.mq5'
b.SOURCES += ['Include/bot-cua-toi-1/Bot1TickSymbolRouting.mqh','Include/bot-cua-toi-1/Bot1TickStrategyPreparation.mqh']
def cases():
    out=[]
    def add(c,chart,flag,error=0):
        c=copy.deepcopy(c);c.update(id=len(out),kind=0,fatal=0,group=c['group'] or 'symbol-routing-and-flags',symbol='old working 🚀',chart=chart,virtual_flag=flag,error=error);out.append(c)
    default=b.base();default.update(total=2,positions=[[1,0],[2,2]],rows=[b.row(0,1.),b.row(1,2.),b.row(499,3.)])
    for row in route.cases():
        for flag in [0,1,2,255]:add(default,row['symbol'],flag,row['error'])
    for c in BASE_CASES():
        if c['kind']==0 and not c['fatal']:add(c,'XAUUSD.a',1,65536+731)
    return out
def encode(rows):
    raw=bytearray(struct.pack('<4i',b.MAGIC,b.VERSION,len(rows),len(rows)))
    for c in rows:raw+=BASE_ENCODE([c])[16:]+struct.pack('<2I',c['error'],c['virtual_flag'])+route.boot.text(c['chart'])
    return bytes(raw)
class Reader(b.Reader):
    def snapshot(self,full=False):
        at=self.pos;super().snapshot(full);self.take('Q');return self.raw[at:self.pos]
    def nullable_text(self):
        n=self.take('i')[0];require(-1<=n<=2048,'NULLABLE_TEXT_SIZE');return None if n<0 else self.blob(n*2).decode('utf-16-le')
def read_results(path,rows):
    rd=Reader(path.read_bytes());require(rd.take('3i')==(b.MAGIC,b.VERSION,len(rows)),'RESULT_HEADER_DIFFERS');out={}
    for c in rows:
        at=rd.pos;cid,kind,value=rd.take('iiQ');require((cid,kind)==(c['id'],0) and value in [0,1],'RESULT_CASE_DIFFERS')
        rd.snapshot();rd.blob(12000);rd.array();rd.nullable_text();rd.nullable_text();out[cid]=rd.raw[at:rd.pos]
    rd.eof();return out
def generate():
    code=TEMPLATE_PATH.read_text(encoding='utf-8')
    code=code.replace('#undef Print','#undef Print\n#include "../../Include/bot-cua-toi-1/Bot1TickStrategyPreparation.mqh"',1)
    code=code.replace('void WriteSnapshot(const int file)\n{','void WriteSnapshot(const int file)\n{\n   uint error=GetLastError();',1)
    marker='WriteDouble(file,Table.rows[row][column]);\n}'
    require(code.count(marker)==1,'ERROR_SNAPSHOT_MARKER');code=code.replace(marker,'WriteDouble(file,Table.rows[row][column]);\n   FileWriteLong(file,(long)error);\n}')
    extra='''string ReadChart(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void WriteRouteText(const int file,const string value){int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(file,n);if(n>0)FileWriteString(file,value,n);}
'''
    code=code.replace('int OnStart()',extra+'\nint OnStart()',1)
    marker='if(!LoadCase(handle_in,id,fatal) || id!=index) return 7;';require(marker in code,'LOAD_ROUTE_MARKER')
    code=code.replace(marker,marker+'\n      uint route_error=(uint)FileReadInteger(handle_in);uchar virtual_flag=(uchar)FileReadInteger(handle_in);string chart=ReadChart(handle_in);')
    code=code.replace('if(CaseKind==0) Bot1DropClosedVirtualStops(Table,OpenTickets);','ResetLastError();if(route_error!=0)SetUserError((ushort)(route_error-65536));\n      if(CaseKind==0) result.q=(long)Bot1PrepareTickStrategy(chart,CaseSymbol,virtual_flag,Table,OpenTickets);')
    code=code.replace('WriteArray(output,OpenTickets);processed++;','WriteArray(output,OpenTickets);WriteRouteText(output,chart);WriteRouteText(output,CaseSymbol);processed++;')
    code=code.replace('bot1-virtual-matrix','bot1-tick-cleanup').replace('version!=2','version!=3').replace('0x56534d31','0x54534d31')
    SCRIPT_PATH.write_text(code,encoding='utf-8',newline='\n');print(SCRIPT_PATH)
class Native(BASE_NATIVE):
    def __init__(self,fixtures):
        super().__init__(fixtures)
        require(self.base==route.BASE,'BASE_CHANGED')
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+0x10f60,0x173e4-0x10f60))).hexdigest()==route.OUTER_SHA,'DISPATCHER_CHANGED')
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        ins={i.address-self.base:i for i in Cs(CS_ARCH_X86,CS_MODE_64).disasm(bytes(self.m.mem_read(self.base+0x10f60,0x173e4-0x10f60)),self.base+0x10f60)}
        self.route_offsets=set();pending=[0x11f3f]
        while pending:
            off=pending.pop()
            if off in self.route_offsets:continue
            self.route_offsets.add(off)
            if off in [0x12004,0x12409]:continue
            require(off in ins,'ROUTE_INSTRUCTION_MISSING');i=ins[off]
            if i.mnemonic.startswith('j'):
                require(i.op_str.startswith('0x'),'INDIRECT_ROUTE_JUMP');pending.append(int(i.op_str,16)-self.base)
            if i.mnemonic not in ['jmp','ret']:pending.append(off+i.size)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.stop_direct,begin=self.base+0x12004,end=self.base+0x12004)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.configured,begin=self.base+0x12409,end=self.base+0x12409)
    def visit(self,m,address,size,user):
        off=address-self.base
        require(off not in [0xc30,0x5880,0x3d6c0,0x4d260],'AUTHORIZATION_OUTSIDE_ROUTE_CLEANUP')
        allowed=0<=off<0xc30 or off in self.route_offsets or 0x12409<=off<=0x12424 or 0x18790<=off<self.ranges[0x18790][0]
        require(allowed,'CODE_OUTSIDE_ROUTE_CLEANUP '+hex(off))
        if off==0x18790:self.cleanup_calls+=1
        return super().visit(m,address,size,user)
    def stop_direct(self,m,address,size,user):self.route=0;m.emu_stop()
    def configured(self,m,address,size,user):self.route=1
    def read_nullable(self,off):
        p=struct.unpack('<Q',self.m.mem_read(self.base+off+4,8))[0]
        return None if not p else self.symbol(self.base+off)
    def snapshot(self):return super().snapshot()+bytes(self.m.mem_read(self.base+0x6a410,4))+bytes(4)
    def call(self,m,address,size,user):
        api=self.apis[address]
        if api in [100,101]:return b.smoke.entry.Original.call(self,m,address,size,user)
        require(m.reg_read(self.x.UC_X86_REG_RCX)==0x23e575eae78,'CLEANUP_CONTEXT')
        return super().call(m,address,size,user)
    def before_route(self,c):
        self.route=-1;self.cleanup_calls=0;self.allocs=self.frees=0
        sp=0x5001fc00;self.m.mem_write(sp,bytes(0x300));self.m.reg_write(self.x.UC_X86_REG_RSP,sp);self.m.reg_write(self.x.UC_X86_REG_RCX,0)
        self.m.mem_write(self.base+0x6a428,struct.pack('<IQ',0,0 if c['chart'] is None else self.string(c['chart'])))
        self.m.mem_write(self.base+0x6a600,bytes([c['virtual_flag']]))
        self.m.mem_write(self.base+0x6a410,struct.pack('<I',c['error']))
        self.m.reg_write(self.x.UC_X86_REG_EFLAGS,0x202);self.m.reg_write(self.x.UC_X86_REG_MXCSR,0x1f80)
source=textwrap.dedent(inspect.getsource(BASE_NATIVE.run_case))
source=source.replace("m.emu_start(self.base+FN[c['kind']],0x60000000,timeout=10000000,count=20000000)","self.before_route(c)\n    m.emu_start(self.base+0x11f3f,self.base+0x12424,timeout=10000000,count=20000000)")
source=source.replace("require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'NATIVE_DID_NOT_RETURN')","require(m.reg_read(x.UC_X86_REG_RIP)==self.base+(0x12004 if self.route==0 else 0x12424),'NATIVE_DID_NOT_REACH_BRANCH')\n    require(self.route in [0,1] and self.cleanup_calls==int(self.route==1 and c['virtual_flag']!=0),'CLEANUP_CALL_COUNT')\n    require(self.read_nullable(0x6a428)==c['chart'],'CHART_CHANGED')")
source=source.replace("n,series,data=self.array()","value=self.route\n    n,series,data=self.array()")
source=source.replace("+struct.pack('<2i',n,series)+data","+struct.pack('<2i',n,series)+data+route.boot.text(self.read_nullable(0x6a428))+route.boot.text(self.read_nullable(0x67918))")
b.route=route;exec(compile(source,__file__,'exec'),b.__dict__);Native.run_case=b.__dict__['run_case']
def identity():
    current=BASE_IDENTITY();src=ROOT/'bot-cua-toi-1/source/MQL5'
    current['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in route.pub.closure(SCRIPT_PATH,src)}
    helpers=[Path(__file__),Path(b.__file__),Path(route.__file__),TEMPLATE_PATH,b.smoke.ANALYSIS/'analysis.json',b.smoke.ANALYSIS/'api-contract.json']
    current['helpers_sha256']={p.relative_to(ROOT).as_posix():sha(p) for p in helpers}
    current['helpers_sha256'].update(route.identity()['helpers_sha256'])
    current['helpers_sha256'].update({'cong-cu/'+n:h for n,h in current['dependencies_sha256'].items()})
    current['tool_sha256']=sha(Path(__file__));current['native_outer_sha256']=route.OUTER_SHA;return current
source=inspect.getsource(b.main).replace('bot1-virtual-matrix','bot1-tick-cleanup').replace('Bot1VirtualStopsCheck','Bot1TickStrategyPreparationCheck').replace("bang-chung/kiem-bang-dung-ao","bang-chung/kiem-quan-ly-vi-the")
source=source.replace("shutil.copyfile(Path(__file__),tested/'check-tool.py')","shutil.copyfile(ROOT/'cong-cu/kiem-noi-ma-gia-don-bang-bot-1.py',tested/'check-tool.py')")
source=source.replace("for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']}))","for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']},result_sha256=sha(folder/'mql5-results.bin')))" )
source=source.replace('whole_bot_complete=False,scope=',"whole_bot_complete=False,whole_manager_complete=False,full_ea=False,authorization_executed=False,authorization_entry_guarded=True,native_route_cleanup_continuous=True,direct_evaluator_executed=False,strategy_loop_executed=False,scope=")
source=source.replace('Four bot1 virtual-stop functions.','Continuous bot1 symbol routing and optional real cleanup only.')
exec(compile(source,__file__,'exec'),b.__dict__)
b.cases=cases;b.encode=encode;b.Reader=Reader;b.read_results=read_results;b.Original=Native;b.identity=identity
if __name__=='__main__':
    if len(sys.argv)>1 and sys.argv[1]=='generate':generate()
    else:b.main()
