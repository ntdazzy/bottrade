"""Run evaluator entry -> initial position stops -> real modify/send bodies.

prepare|original|mql5(--build)|compare BOT RUN. Only terminal replies and
successful allocation are supplied; no child return is substituted. Bot3 DL=0
skips the preceding order-cleanup path. Send log_level=0; no real order.
"""
import argparse,copy,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1;MAGIC=0x45535431
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
data=module('initial_stops_data',ROOT/'bot-cua-toi-3/tests/check-evaluation-prelude.py')
require=data.require;sha=data.sha;save=data.save;bits=data.bits;text=data.text;signed=data.signed
LAYOUT=ROOT/'doi-chung-mt5/thu-tu-truong-lenh-class-20261024/layout-class-r1/trade-layout.json'
LAYOUT_DATA=json.loads(LAYOUT.read_text());SCHEMAS=LAYOUT_DATA['layouts'];BASES=LAYOUT_DATA['relative_native_storage_bases']
CFG={1:dict(entry=0x18aa0,prefix=0x18eb1,end=0x1a152,flag=0x62418,magic=0x6246c,stop=0x62498,target=0x624a0,unit=0x66d98,
 modify=0x26d20,modify_end=0x271e7,request=0x674b0,context=0x67490,stored_magic=0x67725,stopped=0x6a414,symbol=0x67918,ctx=0x23e575eae78),
 3:dict(entry=0x20ef0,prefix=0x212ff,end=0x227c0,flag=0x6d510,magic=0x6d564,stop=0x6d588,target=0x6d590,unit=0x73dd8,
 modify=0x32a90,modify_end=0x32f57,request=0x744f0,context=0x744d0,stored_magic=0x74765,stopped=0x1d6e14,symbol=0x74958,ctx=0x171514ca538)}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,
 native_modify_and_send_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Evaluator entry, prelude and initial position-stop pass execute continuously through their native cleanup; modify26d20/32a90 and send950 execute without substituted child results.',
 'Bot3 caller DL=0 skips the preceding pending-order cleanup. Send log_level=0 excludes message-format branches in this joined run. No later manager or complete EA.',
 'Terminal query/selection/send replies, initial state and successful allocations are supplied. No broker execution, allocation-failure or arbitrary incoming-register proof.']
def prefix(bot):return module('stops_prefix_'+str(bot),ROOT/f'bot-cua-toi-{bot}/tests/check-evaluation-prelude.py')
def position(**kw):
    p=dict(ticket=11,magic=42,type=0,digits=3,sl=bits(0.),tp=bits(0.),open=bits(2000.125),symbol='XAUUSD');p.update(kw);return p
def base():
    return dict(enabled=1,magic=42,stop=bits(10.),target=bits(20.),unit=bits(.01),total=1,trade_magic=0x7654321076543210,
      stopped=0,select_ok=1,async_mode=0,accepted=1,write_result=1,mutation=0,positions=[position()],tag='')
def cases():
    rows=[];presets=data.cases()
    def add(c,tag):
        c['id']=len(rows);c['tag']=tag;c['prelude']=copy.deepcopy(presets[[0,1,2,81,1453,1475,1519,1522][c['id']%8]])
        p=c['prelude'];p['id']=c['id'];p['caller_flag']=0;p['symbol_kind']=0 if c.get('symbol',p['symbol']) is None else 1
        p['symbol']=c.get('symbol','XAUUSD') or '';p['other_kind']=1;p['other']='ALT'
        rows.append(c)
    for enabled in [0,1,255]:
        for total in [-2,-1,0,1,2,3]:
            c=base();c.update(enabled=enabled,total=total,positions=[position(),position(ticket=12,type=1)]);add(c,'enabled-count')
    for stopped in [-2147483648,-1,0,1,2]:
        for selected in [0,1]:
            for accepted in [0,1]:
                for async_ in [0,255]:
                    c=base();c.update(stopped=stopped,select_ok=selected,accepted=accepted,async_mode=async_,write_result=accepted);add(c,'real-child-branches')
    values=[bits(v) for v in [-0.,0.,-1.,1.,2000.,float('inf'),float('-inf')]]+[0x7ff8000000000123,0xfff8000000000456]
    for kind in [0,1,2,0x100000000,-(1<<63)]:
        for sl in values:
            for tp in values:
                c=base();c['positions']=[position(type=kind,sl=sl,tp=tp)];add(c,'existing-levels-type')
    for kind in [0,1]:
        for value in values+[bits(1e19),bits(-(1<<63)),bits(1.005),bits(.000005)]:
            for field in ['stop','target','unit','open']:
                for digits in [-1,0,2,11,12,0x100000003]:
                    c=base();c['positions'][0].update(type=kind,digits=digits)
                    if field=='open':c['positions'][0]['open']=value
                    else:c[field]=value
                    add(c,'calculation-boundary')
    for magic in [-2147483648,-1,0,42,2147483647]:
        for actual in [magic,magic+(1<<32),-1,0,42]:
            c=base();c['magic']=magic;c['positions'][0]['magic']=actual;add(c,'magic-width')
    symbols=[None,'','XAUUSD','xauusd','Vàng 🚀','X'*300]
    for symbol in symbols:
        for actual in symbols:
            c=base();c['symbol']=symbol;c['positions'][0]['symbol']=actual;add(c,'symbol-null-empty')
    for ticket in [0,1,(1<<53)+1,(1<<63)-1,1<<63,(1<<64)-1]:
        for kind in [0,1]:
            c=base();c['positions'][0].update(ticket=ticket,type=kind);add(c,'ticket64')
    for mutation in range(6):
        for accepted in [0,1]:
            c=base();c.update(mutation=mutation,accepted=accepted,total=4,positions=[position(ticket=1),position(ticket=2,type=1),position(ticket=0),position(ticket=4)])
            add(c,'multiple-and-service-change')
    return rows
def encode(rows,p):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=p.encode([c['prelude']])[12:]
        raw+=struct.pack('<2i3QiQ7i',c['enabled'],c['magic'],c['stop'],c['target'],c['unit'],c['total'],c['trade_magic'],
          c['stopped'],c['select_ok'],c['async_mode'],c['accepted'],c['write_result'],c['mutation'],len(c['positions']))
        for v in c['positions']:
            raw+=struct.pack('<Q3q3Q',*[v[k] for k in ['ticket','magic','type','digits','sl','tp','open']])+text(v['symbol'])
    return raw
def result_values(cid):
    return dict(retcode=10009+cid%3,deal=0x12340000+cid,order=0x56780000+cid,volume=.25,price=2600.5,
      bid=2600.25,ask=2600.75,comment=None if cid%2 else 'Đã gửi 🚀',request_id=cid+1,retcode_external=-7)
def original_class(bot,p):
    cfg=CFG[bot]
    class Original(p.Original):
        def __init__(self):
            self.phase='idle';super().__init__();self.joined=set();self.helper_covered=set()
            binding=ROOT/f'bot-cua-toi-{bot}/phan-tich/dong-vi-the/management-trade-native-20261026-r1/native-bindings.json'
            known=json.loads(binding.read_text());functions={int(f['rva'],16):f for f in known['functions']}
            for lo,hi in [(cfg['modify'],cfg['modify_end']),(0x950,0xb5e)]:
                f=functions[lo];require(int(f['end_rva'],16)==hi and hashlib.sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==f['native_bytes_sha256'],'CHILD_BYTES_CHANGED')
                self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+lo,end=self.base+hi-1)
            eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
            for off,api in [(0x7d7da0,410),(0x7d7df0,411),(0x7d7fc0,412),(0x7d8010,413),(0x7d7f70,414),(0x7c2970,415),(0x7d7ee0,416),(0x7d8b70,419),(0x7d8be0,420)]:
                a=eb+off;existed=a in self.apis
                if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
                self.apis[a]=api;self.m.mem_write(a,b'\xc3')
                if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        def write_field(self,key,field,value):
            address=self.base+cfg['request']+BASES[key]+field['offset'];kind=field['kind']
            if kind=='s':self.m.mem_write(address,struct.pack('<IQ',0,0 if value is None else self.string(value)))
            else:self.m.mem_write(address,struct.pack('<'+kind,value))
        def seed(self):
            m=self.m;c=self.row;m.mem_write(self.base+cfg['request'],bytes(628))
            for key,schema in SCHEMAS.items():
                for f in schema['fields']:self.write_field(key,f,f['value'])
            self.settings={k:c[k] for k in ['enabled','magic','stop','target','unit']}
            for k,fmt in [('enabled','B'),('magic','i'),('stop','Q'),('target','Q'),('unit','Q')]:
                m.mem_write(self.base+cfg['flag' if k=='enabled' else k],struct.pack('<'+fmt,c[k]))
            m.mem_write(self.base+cfg['stored_magic'],struct.pack('<Q',c['trade_magic']))
            m.mem_write(self.base+cfg['stored_magic']+16,struct.pack('<i',2));m.mem_write(self.base+cfg['stopped'],struct.pack('<i',c['stopped']))
            m.mem_write(self.base+cfg['context']+660,bytes([c['async_mode']]))
            m.mem_write(self.base+cfg['context']+681,struct.pack('<2i',0,0))
        def snapshot(self):
            raw=bytearray();m=self.m
            for key,schema in SCHEMAS.items():
                for f in schema['fields']:
                    a=self.base+cfg['request']+BASES[key]+f['offset'];kind=f['kind']
                    if kind=='s':raw+=text(self.read_text(a))
                    else:
                        v=struct.unpack('<Q' if kind=='d' else '<'+kind,m.mem_read(a,8 if kind in ['d','Q','q'] else 4))[0];raw+=struct.pack('<Q',v&MASK)
            raw+=bytes(m.mem_read(self.base+cfg['stored_magic'],8))
            for a,fmt in [(cfg['stored_magic']+16,'i'),(cfg['context']+660,'B'),(cfg['context']+681,'i'),(cfg['context']+685,'i')]:
                raw+=struct.pack('<Q',struct.unpack('<'+fmt,m.mem_read(self.base+a,struct.calcsize(fmt)))[0]&MASK)
            return bytes(raw)
        def extra_event(self,kind,words=(),texts=(),snapshot=False):
            flag=bytes(self.m.mem_read(self.base+(0x6a3b4 if bot==1 else 0x1d6d08),1))[0]
            raw=bytearray(struct.pack('<i6Q',kind,*[v&MASK for v in [*words,*[0]*(5-len(words)),flag]]))
            for v in [*texts,*[None]*(3-len(texts))]:raw+=text(v)
            if snapshot:raw+=self.snapshot()
            self.extra+=raw
        def mutate(self,kind):
            if self.changed:return
            c=self.row;mutation=c['mutation'];m=self.m
            if mutation==1 and kind==11:
                value=signed(self.settings['magic']+1,32);self.settings['magic']=value;m.mem_write(self.base+cfg['magic'],struct.pack('<i',value))
            elif mutation==2 and kind==13:m.mem_write(self.base+cfg['symbol'],struct.pack('<IQ',0,self.string('Đổi mã')))
            elif mutation==3 and kind==15:
                for k,value in [('stop',37.25),('target',-9.),('unit',.05)]:self.settings[k]=bits(value);m.mem_write(self.base+cfg[k],struct.pack('<d',value))
            elif mutation==4 and kind==20:
                self.settings['enabled']=0;m.mem_write(self.base+cfg['flag'],b'\0')
            elif mutation==5 and kind==17:m.mem_write(self.base+cfg['stopped'],struct.pack('<i',1))
            else:return
            self.changed=True
        def visit(self,m,address,size,user):
            rva=address-self.base
            if self.phase=='prefix':
                if rva==cfg['entry']:self.seed()
                return super().visit(m,address,size,user)
            if self.phase!='loop':return
            self.joined.add(rva)
            if cfg['modify']<=rva<cfg['modify_end'] or 0x950<=rva<0xb5e:self.helper_covered.add(rva)
            if rva==cfg['modify']:
                self.extra_event(16,[m.reg_read(self.x.UC_X86_REG_RCX),m.reg_read(self.x.UC_X86_REG_XMM1)&MASK,m.reg_read(self.x.UC_X86_REG_XMM2)&MASK],snapshot=True)
            if rva==cfg['end']:self.loop_exit=rva;m.emu_stop()
        def call(self,m,address,size,user):
            if self.phase!='loop':return super().call(m,address,size,user)
            x=self.x;api=self.apis[address];c=self.row
            if api in [100,101]:return super().call(m,address,size,user)
            r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));arg=r('RDX');prop=arg&0xffffffff
            require(r('RCX')==cfg['ctx'],'SDK_CONTEXT_CHANGED')
            def integer(value):m.reg_write(x.UC_X86_REG_RAX,value&MASK)
            def current():require(0<=self.selected<len(c['positions']),'NO_SELECTED_POSITION');return c['positions'][self.selected]
            if api==410:self.extra_event(10,[c['total']]);integer(c['total'])
            elif api==411:
                i=signed(arg,32);v=c['positions'][i]['ticket'] if 0<=i<len(c['positions']) else 0
                if v:self.selected=i
                self.extra_event(11,[i,v,self.selected]);integer(v);self.mutate(11)
            elif api==412:
                require(prop in [2,12],'POSITION_INTEGER_PROPERTY');value=current()['type' if prop==2 else 'magic']
                self.extra_event(12,[prop,value,self.selected]);integer(value)
            elif api==413:
                require(prop==0,'POSITION_STRING_PROPERTY');value=current()['symbol'];self.extra_event(13,[prop,self.selected],[value])
                m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,0 if value is None else self.string(value)));self.mutate(13)
            elif api==414:
                require(prop in [4,6,7],'POSITION_DOUBLE_PROPERTY');value=current()[{4:'open',6:'sl',7:'tp'}[prop]]
                self.extra_event(14,[prop,value,self.selected]);m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value)
            elif api==415:
                prop=r('R8')&0xffffffff;require(prop==17,'SYMBOL_INTEGER_PROPERTY');value=current()['digits']
                self.extra_event(15,[prop,value],[self.read_text(arg)]);integer(value);self.mutate(15)
            elif api==416:
                found=next((i for i,v in enumerate(c['positions']) if v['ticket']==arg),-1);ok=int(bool(c['select_ok']) and found>=0)
                if ok:self.selected=found
                self.extra_event(17,[arg,ok,self.selected]);integer(ok);self.mutate(17)
            elif api in [419,420]:
                require(arg==self.base+cfg['request'] and r('R8')==self.base+cfg['request']+240,'SEND_POINTERS')
                self.extra_event(19,[int(api==420),c['accepted']],snapshot=True)
                if c['write_result']:
                    values=result_values(c['id'])
                    for f in SCHEMAS['result']['fields']:self.write_field('result',f,values[f['name']])
                self.extra_event(20,snapshot=True);integer(c['accepted']);self.mutate(20)
            elif api==304:
                require(arg==13 and r('R8')==2,'UNEXPECTED_DISPATCH');sp=r('RSP');values=[]
                for j in range(2):
                    tag=r('R9')&0xffffffff if j==0 else struct.unpack('<I',m.mem_read(sp+32+16*j,4))[0]
                    require(tag==0x590008,'FORMAT_TYPE');ptr=struct.unpack('<Q',m.mem_read(sp+40+16*j,8))[0];values.append(self.read_text(ptr))
                self.extra_event(18,[2],values)
            else:raise ValueError('UNEXPECTED_LOOP_API '+str(api))
        def run_joined(self,row):
            self.row=row;self.selected=-1;self.changed=False;self.phase='prefix';self.extra=bytearray();self.loop_exit=None
            before=super().run(row['prelude']);start=self.m.reg_read(self.x.UC_X86_REG_RIP);require(start==self.base+cfg['prefix'],'PREFIX_JOIN_DIFFERS')
            self.phase='loop';self.m.emu_start(start,0x60000000,timeout=5000000,count=1000000)
            require(self.loop_exit==cfg['end'],'LOOP_DID_NOT_REACH_END')
            ctx=bytearray()
            for k,fmt in [('enabled','B'),('magic','i'),('stop','Q'),('target','Q'),('unit','Q')]:
                a=self.base+cfg['flag' if k=='enabled' else k];v=struct.unpack('<'+fmt,self.m.mem_read(a,struct.calcsize(fmt)))[0];ctx+=struct.pack('<Q',v&MASK)
            ctx+=struct.pack('<2Q',self.selected&MASK,struct.unpack('<i',self.m.mem_read(self.base+cfg['stopped'],4))[0]&MASK)+text(self.read_text(self.base+cfg['symbol']))
            return before+bytes(self.extra)+struct.pack('<i',0)+self.snapshot()+ctx
    return Original
def identity(bot,p):
    home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EvaluationStopsCheck.mq5';helpers=dict(p.identity()['helpers_sha256'])
    for file in [Path(__file__),LAYOUT,home/'phan-tich/dong-vi-the/management-trade-native-20261026-r1/native-bindings.json']:
        helpers[file.relative_to(ROOT).as_posix()]=sha(file)
    return dict(original_ex5_sha256=p.head.validation.original_hash(bot),tool_sha256=sha(Path(__file__)),sources_sha256={f.relative_to(source).as_posix():sha(f) for f in p.pub.closure(source/script,source)},helpers_sha256=helpers)
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,40}',a.run),'BAD_RUN');p=prefix(a.bot);home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run
    rows=cases();current=identity(a.bot,p);header=struct.pack('<4i',MAGIC,1,len(rows),len(p.FIELDS));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}EvaluationStopsCheck.mq5'
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows,p));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows,p),'IDENTITY_CHANGED')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');o=original_class(a.bot,p)();raw=bytearray(header)
        for c in rows:
            try:raw+=o.run_joined(c)
            except Exception as e:raise RuntimeError('CASE '+str(c['id'])+' RIP '+hex(o.m.reg_read(o.x.UC_X86_REG_RIP))+' '+repr(e)) from e
        require(CFG[a.bot]['modify'] in o.helper_covered and 0x950 in o.helper_covered,'REAL_CHILD_NOT_EXECUTED')
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',dict(**current,cases=len(rows),joined_instructions=len(o.joined),child_instructions=len(o.helper_covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),joined_instructions=len(o.joined),child_instructions=len(o.helper_covered))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
        mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025'
        for n,h in current['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_DIFFERS')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
        files=mt/f'MQL5/Files/bot{a.bot}-evaluation-stops'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('stops-'+a.run+'.set');ini=mt/('stops-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-'+str(a.bot)+'\\Bot'+str(a.bot)+'EvaluationStopsCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for name in ['original','mql5']:
        r=json.loads((folder/(name+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and sha(folder/(name+'-results.bin'))==r['result_sha256'],'RUN_CHANGED')
    left=(folder/'original-results.bin').read_bytes();right=(folder/'mql5-results.bin').read_bytes();ok=left==right;at=next((i for i,(x,y) in enumerate(zip(left,right)) if x!=y),min(len(left),len(right)))
    report=dict(cases=len(rows),matched=len(rows) if ok else None,failed=0 if ok else None,identical=ok,first_different_byte=None if ok else at,bytes=[len(left),len(right)],**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(not ok)
if __name__=='__main__':main()
