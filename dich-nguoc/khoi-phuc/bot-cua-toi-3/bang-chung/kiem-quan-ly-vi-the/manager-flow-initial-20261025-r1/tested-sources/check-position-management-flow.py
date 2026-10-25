"""Compare both complete management parents, with supplied terminal and child replies.
prepare -> compile -> mql5 -> original -> compare. This is not a complete EA or broker test.
"""
import argparse,copy,importlib.util,json,math,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
B_PATH=HOME/'tests/check-management-real-blocks.py';CASE_PATH=HOME/'tests/manager_flow_cases.py'
B=module('flow3_blocks',B_PATH);inputs=module('flow3_cases',CASE_PATH)
pre,cpu,sha,require,save,MT=B.pre,B.cpu,B.sha,B.require,B.save,B.MT
MASK=B.MASK;MAGIC=inputs.MAGIC;RESULT=struct.Struct('<7iIIQ5Qi4Q');ANALYSIS=B.ANALYSIS
PUB_PATH=ROOT/'cong-cu/kiem-ban-git-quan-ly.py';pub=module('flow3_closure',PUB_PATH)
SCRIPT='Scripts/bot-cua-toi-3/Bot3PositionManagementFlowCheck.mq5'
CONTRACT=ROOT/'claude-thuc-hien/bot3-manager-flow-check-20261025-r1/CONTRACT.md'
FLOAT_PROOF=ROOT/'doi-chung-mt5/cast-double-20261025/double-cast-native-r1/double-cast-contract.json'
FIELDS=['id','returned','counter','mode','live_count','eligible','guard','index','error_count','last_ticket','current_stop','current_take','bid','ask','copied_step','calls','ordered_hash','cache_hash','table_hash','positions_hash']
SCOPE=dict(full_management_parents_executed=True,whole_manager_complete=False,whole_bot_complete=False,full_ea=False,child_helpers_intercepted=True,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Both original management parent functions run to return, including their loop and real/virtual transitions. This is not an EA, paired terminal comparison or complete manager integration proof.',
 'Modify, try-close, virtual stop/take/delay/stamp child replies and their specified provider-side effects are supplied at original call boundaries; child internals do not run here. They have separate component evidence.',
 'Native error-code/string/Print code executes. Successful string allocation and signed decimal conversion are supplied; double text is measured separately in MT5 and supplied by value bits.',
 'CPU both-NaN fixtures only correct measured two-NaN arithmetic. Other native instructions run in Unicorn; no physical original-run, allocation-failure or complete error coverage claim.']
DOUBLE_CFG={0x73dd8:'unit',0x6d588:'stop_distance',0x6d590:'take_distance',0x6d650:'emergency_offset',0x73ab0:'gap',0x744a8:'freeze',0x6d4e0:'anchor_limit',0x6d5e8:'timed_activation',0x6d5f0:'timed_distance',0x6d598:'trail',0x6d5b0:'trail_step',0x6d5a0:'trail_start',0x6d5a8:'trail_limit',0x6d378:'take_trail_distance',0x6d380:'take_trail_start',0x6d4f8:'slippage_trail',0x6d4f0:'slippage_start',0x6d500:'slippage_limit',0x6d5b8:'lock_start',0x6d5c0:'lock_extra',0x6d600:'step_reference',0x6d610:'step_distance'}
INT_CFG={0x6d564:'magic',0x6d520:'enabled',0x6d514:'mode',0x7449c:'timed_delay_seconds',0x6d518:'virtual_delay_seconds',0x6d4e8:'slippage_enabled',0x6d3c0:'high_low_gap_count',0x6d5d4:'high_low_enabled',0x6d608:'min_steps'}
BYTE_CFG={0x6d508:'use_anchor',0x1d6fa0:'high_low_eligible',0x6d5c8:'high_low_before_open',0x6d5dc:'high_low_shift',0x6d5f8:'step_enabled',0x6d29c:'candle_shift'}
def identity():
    old=B.identity();base=HOME/'source/MQL5';names=sorted(p.relative_to(base.resolve()).as_posix() for p in pub.closure(base/SCRIPT,base))
    return dict(original_ex5_sha256=old['original_ex5_sha256'],tool_sha256=sha(Path(__file__)),analysis_sha256=sha(ANALYSIS/'analysis.json'),contract_sha256=sha(CONTRACT),probe_sha256=sha(cpu.PROBE),helpers_sha256=old['helpers_sha256']|{str(p.relative_to(ROOT)):sha(p) for p in [B_PATH,CASE_PATH,PUB_PATH,FLOAT_PROOF]},sources_sha256={n:sha(base/n) for n in names})
def signed64(n):return ((n+(1<<63))&MASK)-(1<<63)
def normalized(n):
    value=float(signed64(n));return float(-(1<<63) if value>=1<<63 or value<-(1<<63) else int(value))
def casts(path,count):
    raw=path.read_bytes();require(struct.unpack_from('<3i',raw)==(MAGIC,1,count),'BAD_CAST_HEADER');pos=12;out={}
    for cid in range(count):
        ident,n=struct.unpack_from('<2i',raw,pos);pos+=8;require(ident==cid and 0<n<100,'BAD_CAST_CASE');values={}
        for _ in range(n):
            bits,length=struct.unpack_from('<Qi',raw,pos);pos+=12;require(0<=length<1000,'BAD_CAST_TEXT');text=raw[pos:pos+length*2].decode('utf-16-le');pos+=length*2;require(bits not in values,'DUPLICATE_CAST_VALUE');values[bits]=text
        out[cid]=values
    require(pos==len(raw),'CAST_TRAILING_BYTES');return out
class Original(B.Original):
    def __init__(self,fixture,formats):
        super().__init__(fixture);self.formats=formats
        eb=next(a for a,k in self.apis.items() if k==4)-0x7c2890
        for rva,api in {0x7d7df0:102,0x7d7f70:103,0x7d7fc0:104,0x7d8010:105,0x7d7da0:106,0x7d3b50:107,0x7d3d40:108,0x7d3bc0:109}.items():
            address=eb+rva
            if address not in self.apis:
                if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
                self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
            self.apis[address]=api
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x32f60,end=self.base+0x3badf)
    def visit(self,m,address,size,user):self.covered.add(address-self.base)
    def text_null(self,descriptor):return int(struct.unpack('<Q',self.m.mem_read(descriptor+4,8))[0]==0)
    def selected_row(self):return self.positions[self.selected] if 0<=self.selected<len(self.positions) else None
    def remove(self,ticket):
        if not self.case['close_ok'] or self.case['profile']==7:return
        for i,row in enumerate(self.positions):
            if row['ticket']==ticket:self.positions.pop(i);self.selected=-1;break
    def child(self,m,address,size,user):
        x=self.x;c=self.case;api=self.apis[address];r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))&MASK;value=0
        if api==1:self.event(20,r('RCX'),r('XMM1'),r('XMM2'),r('R9'));m.reg_write(x.UC_X86_REG_XMM0,pre.bits(self.stop_reply))
        elif api==11:self.event(21,r('RDX'),r('XMM0'));m.reg_write(x.UC_X86_REG_XMM0,pre.bits(self.take_reply))
        elif api==2:self.event(22,r('RCX'),self.integer(0x6d518),c['delay_pass']);value=c['delay_pass']
        elif api==6:self.event(23,r('RCX'))
        elif api==5:self.event(8,r('RCX'),r('XMM1'),r('XMM2'),c['modify_ok']);value=c['modify_ok']
        elif api==8:
            self.event(9,r('RCX'),c['close_ok']);self.remove(r('RCX'));value=c['close_ok']
        else:raise ValueError('BAD_CHILD '+str(api))
        sp=r('RSP');ret=struct.unpack('<Q',m.mem_read(sp,8))[0];m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,ret);m.reg_write(x.UC_X86_REG_RAX,value)
    def call(self,m,address,size,user):
        api=self.apis[address];c=self.case;x=self.x;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))&MASK;a=r('RDX');b=r('R8')&0xffffffff
        if api in [100,101]:return pre.entry.Original.call(self,m,address,size,user)
        if api==46:
            require(b in [0x52,0x58],'BAD_CAST_KIND');text=str(signed64(a)) if b==0x52 else self.formats[c['id']].get(a)
            require(text is not None,'DOUBLE_CAST_FIXTURE_MISSING '+hex(a));m.mem_write(r('R9'),struct.pack('<IQ',0,self.string(text)));return
        if api==106:
            self.event(17,len(self.positions),self.total_calls);self.total_calls+=1
            if self.total_calls==1:m.mem_write(self.base+0x1d6fa0,bytes([c['eligible_after_total']]))
            m.reg_write(x.UC_X86_REG_RAX,len(self.positions));return
        if api==102:
            self.selected=signed64(a);row=self.selected_row();ticket=row['ticket'] if row else 0
            self.event(2,a,0,ticket);m.reg_write(x.UC_X86_REG_RAX,ticket);return
        if api in [103,104,105]:
            row=self.selected_row()
            if api==103:
                require(a in [3,4,6,7],'BAD_POSITION_DOUBLE');key={3:'volume',4:'open',6:'sl',7:'tp'}[a];value=(row.get('open_price',row.get('open',0.)) if key=='open' else row[key]) if row else 0.;raw=pre.bits(value)
                self.event(3,a,0,raw);m.mem_write(self.base+0x1d6e48,struct.pack('<Q',raw));m.reg_write(x.UC_X86_REG_XMM0,raw)
            elif api==104:
                require(a in [1,2,12],'BAD_POSITION_INTEGER');value=row[{1:'opened',2:'type',12:'magic'}[a]] if row else 0;self.event(4,a,0,value);m.reg_write(x.UC_X86_REG_RAX,value&MASK)
            else:
                require(a in [0,11],'BAD_POSITION_STRING');text=row['symbol' if a==0 else 'comment'] if row else None;self.event(5,a,pre.entry.text_hash(text or ''),int(text is None));m.mem_write(self.base+0x1d6e3c,struct.pack('<IQ',0,0 if text is None else self.string(text)))
            return
        if api==3:
            require(b==17 and self.text(a)=='CHECK','BAD_DIGITS');self.event(1,17,pre.entry.text_hash(self.text(a)),c['digits'],self.text_null(a));self.digit_count+=1
            if c['flip_digit']>0 and self.digit_count==c['flip_digit']:m.mem_write(self.base+0x6d514,struct.pack('<i',c['flip_mode']))
            m.reg_write(x.UC_X86_REG_RAX,c['digits']&MASK);return
        if api==4:
            require(b in [16,34] and self.text(a)=='CHECK','BAD_SYMBOL_DOUBLE');value=.01 if b==16 else self.minimum;raw=pre.bits(value);self.event(18,b,raw);m.mem_write(self.base+0x1d6e48,struct.pack('<Q',raw));m.reg_write(x.UC_X86_REG_XMM0,raw);return
        if api==7:
            require(self.text(a)=='CHECK' and r('R8')==self.base+0x74790,'BAD_TICK');self.event(6,pre.entry.text_hash(self.text(a)),c['tick_ok'],pre.bits(self.bid),pre.bits(self.ask))
            if c['tick_ok']:m.mem_write(self.base+0x74798,struct.pack('<2d',self.bid,self.ask))
            m.reg_write(x.UC_X86_REG_RAX,c['tick_ok']);return
        if api==9:require(a==0,'BAD_TIME_OVERLOAD');self.event(19,1061);m.reg_write(x.UC_X86_REG_RAX,1061);return
        if api==10:
            require(a==2 and b==1 and r('R9')==0x590008,'BAD_PRINT_SIGNATURE');descriptor=struct.unpack('<Q',m.mem_read(r('RSP')+0x28,8))[0];text=self.text(descriptor);self.event(7,pre.entry.text_hash(text));self.prints.append(text);m.reg_write(x.UC_X86_REG_RAX,0);return
        if api in [107,108,109]:
            tf=b;shift=r('R9')&0xffffffff;require(self.text(a)=='CHECK','BAD_CANDLE_SYMBOL')
            if api==107:require(shift in [0,1],'BAD_TIME_SHIFT');value=900 if shift else 1100;raw=value;m.reg_write(x.UC_X86_REG_RAX,value)
            else:
                value=(90. if c['buy'] else 110.) if api==108 else (95. if c['buy'] else 105.);raw=pre.bits(value);m.mem_write(self.base+0x1d6e48,struct.pack('<Q',raw));m.reg_write(x.UC_X86_REG_XMM0,raw)
            self.event({107:10,108:11,109:12}[api],tf,shift,raw,pre.entry.text_hash(self.text(a)));return
        raise ValueError('UNEXPECTED_FLOW_API '+str(api))
    def run(self,c):
        m,x=self.m,self.x;self.case=c;cfg=inputs.settings(c);self.positions=copy.deepcopy(inputs.positions(c));self.selected=-1;self.events=[];self.prints=[];self.cursor=0x70001000;self.allocs=self.frees=0;self.total_calls=self.digit_count=0;self.error_covered=set()
        self.bid,self.ask=inputs.tick_reply(c);self.stop_reply,self.take_reply=inputs.levels_reply(c);self.minimum=inputs.minimum_reply(c)
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for reg in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+reg),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80);m.mem_write(0x50000000,b'\0'*0x20000)
        for rva,key in DOUBLE_CFG.items():m.mem_write(self.base+rva,struct.pack('<d',cfg[key]))
        for rva,key in INT_CFG.items():m.mem_write(self.base+rva,struct.pack('<i',cfg[key]))
        for rva,key in BYTE_CFG.items():m.mem_write(self.base+rva,bytes([cfg[key]]))
        for rva,value in [(0x6d29e+i*2,cfg['candle_enabled'][i]) for i in range(3)]+[(0x6d29d+i*2,cfg['candle_timeframe'][i]) for i in range(3)]:m.mem_write(self.base+rva,bytes([value]))
        m.mem_write(self.base+0x74958,struct.pack('<IQ',0,self.string(cfg['symbol'])));m.mem_write(self.base+0x74838,struct.pack('<Q',123456));m.mem_write(self.base+0x74798,struct.pack('<2d',-100.,-101.))
        m.mem_write(self.base+0x74934,struct.pack('<I',c['index']));m.mem_write(self.base+0x7448c,struct.pack('<I',c['error_count']));m.mem_write(self.base+0x74430,struct.pack('<i',c['counter']));m.mem_write(self.base+0x1d6e10,struct.pack('<i',c['error_code']));m.mem_write(self.base+0x1d6e3c,b'\0'*12)
        for rva,value in [(0x6d670,333.),(0x724a0,444.),(0x74428,7.5)]:m.mem_write(self.base+rva,struct.pack('<d',value))
        m.mem_write(self.base+0x73ac0,struct.pack('<9d',*([.1+i*.01 for i in range(9)])))
        for rva in [0x74110,0x73df0]:m.mem_write(self.base+rva,struct.pack('<9d',*([95. if c['buy'] else 105.]*9)))
        m.mem_write(self.base+0x72e10,b'\0'*1600);m.mem_write(self.base+0x73450,b'\1');stop=[[0.]*3 for _ in range(500)];take=[[0.]*2 for _ in range(500)]
        for i,row in enumerate(self.positions):
            if row['ticket']!=0:stop[i]=[normalized(row['ticket']),self.stop_reply,0.];take[i]=[normalized(row['ticket']),self.take_reply]
        m.mem_write(self.base+0x6d680,struct.pack('<1500d',*(v for row in stop for v in row)));m.mem_write(self.base+0x70560,struct.pack('<1000d',*(v for row in take for v in row)))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.emu_start(self.base+(0x32f60 if c['buy'] else 0x37590),0x60000000,timeout=15000000,count=2000000);require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'MANAGER_DID_NOT_RETURN')
        raw=b''.join(struct.pack('<5Q',*e) for e in self.events);rows=bytes(m.mem_read(self.base+0x6d680,12000))+bytes(m.mem_read(self.base+0x70560,8000));remaining=b''.join(struct.pack('<Q',r['ticket']) for r in self.positions)
        return RESULT.pack(c['id'],m.reg_read(x.UC_X86_REG_RAX)&255,self.integer(0x74430),self.integer(0x6d514),len(self.positions),m.mem_read(self.base+0x1d6fa0,1)[0],m.mem_read(self.base+0x73450,1)[0],struct.unpack('<I',m.mem_read(self.base+0x74934,4))[0],struct.unpack('<I',m.mem_read(self.base+0x7448c,4))[0],self.read(0x74838),self.read(0x6d670),self.read(0x724a0),self.read(0x74798),self.read(0x747a0),self.read(0x74428),len(self.events),B.fnv(raw),B.fnv(bytes(m.mem_read(self.base+0x72e10,1600))),B.fnv(rows),B.fnv(remaining))
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=inputs.cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(inputs.encode(rows));tested=folder/'tested-sources';tested.mkdir()
        for n in current['sources_sha256']:shutil.copyfile(HOME/'source/MQL5'/n,tested/Path(n).name)
        for path in [Path(__file__),CASE_PATH]:shutil.copyfile(path,tested/path.name)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==inputs.encode(rows),'IDENTITY_OR_INPUTS_DIFFER')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==digest,'SOURCE_DIFFERS '+n)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-position-management-flow'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/('b3-full-flow-'+a.run+'.set');ini=MT/('b3-full-flow-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3PositionManagementFlowCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','cast-values.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        casts(folder/'cast-values.bin',len(rows));save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),casts_sha256=sha(folder/'cast-values.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    if a.mode=='original':
        require(not (folder/'original-results.bin').exists(),'RESULT_EXISTS');formats=casts(folder/'cast-values.bin',len(rows));fixture=cpu.CpuFixture()
        try:
            cpu.verify_probe(fixture,current['probe_sha256']);runner=Original(fixture,formats);raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)));traces=[]
            for c in rows:
                try:raw+=runner.run(c)
                except Exception as error:
                    value=dict(case=c['id'],profile=c['profile'],buy=c['buy'],rva=hex(runner.m.reg_read(runner.x.UC_X86_REG_RIP)-runner.base),error=str(error),events=runner.events[-30:])
                    save(folder/'attempt-error.json',value);raise RuntimeError(json.dumps(value)) from error
                traces.append(dict(id=c['id'],profile=c['profile'],buy=c['buy'],events=runner.events,prints=runner.prints))
            (folder/'original-results.bin').write_bytes(raw);save(folder/'original-traces.json',traces);save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),casts_sha256=sha(folder/'cast-values.bin'),instructions=sorted(hex(n) for n in runner.covered),nan_fixture=runner.nan.report(),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(runner.covered))))
        finally:fixture.close()
        return
    for n in ['original-run.json','mql5-run.json']:
        rec=json.loads((folder/n).read_text());require(all(rec[k]==v for k,v in current.items()) and rec['result_sha256']==sha(folder/n.replace('-run.json','-results.bin')) and rec['casts_sha256']==sha(folder/'cast-values.bin'),'RUN_IDENTITY_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();require(native[:12]==actual[:12]==struct.pack('<3i',MAGIC,1,len(rows)) and len(native)==len(actual)==12+RESULT.size*len(rows),'BAD_RESULTS');failed=[]
    for c in rows:
        off=12+c['id']*RESULT.size;n=RESULT.unpack_from(native,off);r=RESULT.unpack_from(actual,off)
        if n!=r:failed.append(dict(id=c['id'],buy=c['buy'],profile=c['profile'],group=c['group'],differences={k:[x,y] for k,x,y in zip(FIELDS,n,r) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:25],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS);save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
