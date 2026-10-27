"""Execute native balance gate -> volume/withdrawal/currency -> pending delete/open/send.

prepare|mql5(--build)|original|compare|errors BOT RUN. No reset at child boundaries.
Terminal replies, allocation and numeric text measured in isolated MT5 are supplied.
"""
import argparse,copy,hashlib,importlib.util,json,math,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x52464c31;MASK=(1<<64)-1
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
live=module('resize_flow_live',ROOT/'cong-cu/kiem-khoi-luong-thuc-bot-1-3.py');v=live.v;pub=live.pub;require=pub.require;sha=live.sha;save=live.save
gate=module('resize_flow_gate',ROOT/'cong-cu/kiem-cong-doi-von-bot-1-3.py')
PARTS={b:module('resize_flow_pending_'+str(b),ROOT/f'bot-cua-toi-{b}/tests/check-evaluation-pending-resize.py') for b in [1,3]}
CFG={1:dict(start=0x1a6e5,volume=0x34780,after=0x1a817,end=0x1b317,flag=0x62554,stop=0x62498,previous=0x67480,table=0x65dd0,last=0x677f8,fallback=0x6a428,headflag=0x6a3b4,virtual=0x6a5e8,percent=0x62528),
 3:dict(start=0x22920,volume=0x3f900,after=0x22a59,end=0x235f7,flag=0x6d644,stop=0x6d588,previous=0x744c0,table=0x72e10,last=0x74838,fallback=0x1d6e28,headflag=0x1d6d08,virtual=0x1d6fc8,percent=0x6d618)}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_balance_volume_resize_continuous=True,child_helpers_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
def bits(n):return live.bits(n)
def number(n):return struct.unpack('<d',struct.pack('<Q',n))[0]
def cases(bot):
    rows=[];p=PARTS[bot];default=live.flow.withdrawal.base_case()
    def add(pending,tag,variant=0):
        n=len(rows);pending=copy.deepcopy(pending);pending['id']=n;pending['prelude']['id']=n
        vol=v.base_case(bot);vol.update({k:default[k] for k in ['enabled','tester','select_ok','restore_ok','reported_count','last_check','last_deal','times','peak_key','time_key','deals']})
        vol.update(id=n,fatal=0,tag=tag,symbol=pending['symbol'] or '',suffix='.a',currency_values=[['USD','EUR','CHF','CNH'][n%4]],prices=[2.]*8,index=pending['index'],mutate_after=0,mutate_index=bot+4)
        vol['volumes']=[number(x) for x in pending['volumes']];vol['s.volume']=vol['volumes'][0];vol['s.mode']=[0,3,999,9999,2 if bot==1 else 1234][n%5]
        vol['r.use_equity']=n%2;vol['s.highest_balance']=15000. if n%7==0 else 10000.;vol['r.start_lots']=.2
        vol['replies']={26:[1.],34:[.01],35:[200.],36:[[.01],[.1,.01,.001],[.05,.001,.01]][n%3]}
        if bot==3:vol['r.weighted']=n%2
        current,previous=([12000.,9000.,10000.][variant%3],10000.)
        pending['percent']=bits(10.)
        c=dict(id=n,pending=pending,volume=vol,current=bits(current),previous=bits(previous),flag=[1,0,255][n%3],stop=bits(1500.),fatal=0,tag=tag)
        rows.append(c);return c
    for n,pending in enumerate(p.cases()):add(pending,'joined-'+pending['tag'],n%3)
    base=p.cases()[0]
    for flag in [0,1,255]:
        for mode in [0,3,999,9999,2 if bot==1 else 1234]:
            for direction in [0,1]:
                c=add(base,'mode-and-balance-direction',direction);c['flag']=flag;c['volume']['s.mode']=mode
    for current,previous,percent in [(math.nan,10000.,10.),(12000.,math.nan,10.),(math.inf,10000.,10.),(12000.,10000.,math.nan),(-1.,1.,-50.),(1.,-1.,0.)]:
        c=add(base,'balance-special');c['current']=bits(current);c['previous']=bits(previous);c['pending']['percent']=bits(percent)
    for n in [1,4]:
        c=add(base,'volume-changes-index');c['volume']['mutate_after']=n
    c=add(base,'fatal-gate');c.update(current=bits(0.),previous=bits(1.),fatal=1);c['pending']['percent']=bits(-100.)
    c=add(base,'fatal-volume');c['fatal']=1;c['flag']=1;c['volume']['s.mode']=9999;c['volume']['s.balance_step']=0;c['volume']['replies'][36]=[.01]
    return rows
def encodings(rows,bot):
    flow=struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<2i2QiQ',c['id'],c['fatal'],c['current'],c['previous'],c['flag'],c['stop']) for c in rows)
    return {'cases.bin':flow,'pending-cases.bin':PARTS[bot].encode([c['pending'] for c in rows]),'volume-cases.bin':live.encode([c['volume'] for c in rows],bot)}
def original_class(bot):
    p=PARTS[bot];cfg=CFG[bot];vc=live.CFG[bot]
    class Adapter(live.Original):
        def state(self):return super().state()+bytes(self.m.mem_read(self.base+cfg['previous'],8))
    class Original(p.Original):
        def __init__(self,cast_values,fixed_values):
            # Independent SDK adapter shares the caller's existing native memory; no boundary reset.
            self.adapter=Adapter(bot,cast_values,fixed_values);super().__init__({})
            self.adapter.m=self.m;self.volume_active=False;self.volume_called=False;self.flow_error=0;self.flow_covered=set()
            self.volume_apis=dict(self.adapter.apis)
            for address,api in self.volume_apis.items():
                if address in self.apis:continue
                if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
                self.apis[address]=700+api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+vc['fn'],end=self.base+vc['end']-1)
            g=gate.CFG[bot];require(hashlib.sha256(bytes(self.m.mem_read(self.base+g['function'],g['end']-g['function']))).hexdigest()==g['sha'],'EVALUATOR_BYTES_CHANGED')
        def visit(self,m,address,size,user):
            if self.phase=='loop':
                rva=address-self.base;self.flow_covered.add(rva)
                if rva==cfg['volume']:self.volume_active=True;self.volume_called=True
                if rva==cfg['after']:self.volume_active=False
            return super().visit(m,address,size,user)
        def call(self,m,address,size,user):
            if self.phase=='loop' and address in self.volume_apis and self.volume_apis[address]==200:
                self.flow_error=m.reg_read(self.x.UC_X86_REG_RDX);m.emu_stop();return
            if self.phase=='loop' and self.volume_active:
                a=self.adapter
                for key in ['cursor','allocs','frees']:setattr(a,key,getattr(self,key))
                a.call(m,address,size,user)
                for key in ['cursor','allocs','frees']:setattr(self,key,getattr(a,key))
                self.current_index=struct.unpack('<I',m.mem_read(self.base+vc['index'],4))[0]
                return
            return super().call(m,address,size,user)
        def run_flow(self,c):
            self.row=copy.deepcopy(c['pending']);self.case=self.row['prelude'];self.changed=False;self.phase='idle'
            self.current_index=self.row['index'];self.live_symbol=self.row['symbol'];self.resize_changed=False;self.extra=bytearray();self.resize_exit=False;self.flow_error=0;self.volume_called=False;self.volume_active=False
            m,x=self.m,self.x;self.cursor=0x70001000;self.allocs=self.frees=0;self.selected=-1
            for region,raw in self.regions:
                if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
            for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
            for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
            self.seed();self.frame=0x5001f000;m.mem_write(self.frame,bytes(0x300));m.reg_write(x.UC_X86_REG_RSP,self.frame)
            if bot==1:m.reg_write(x.UC_X86_REG_RBP,self.base+0x5c0)
            m.reg_write(x.UC_X86_REG_R12,self.base+0x5c0);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
            for off,value in [(self.cfg['symbol'],self.row['symbol']),(cfg['fallback'],'XAUUSD_NOCOST_V2')]:m.mem_write(self.base+off,struct.pack('<IQ',0,0 if value is None else self.string(value)))
            a=self.adapter;value=c['volume'];a.case=value;a.events=bytearray();a.events_count=0;a.counters={};a.symbol_calls=a.account_calls=a.clock_calls=a.select_calls=0;a.error=0
            for n,k,rva in v.fields(v.INPUTS,bot):m.mem_write(self.base+rva,struct.pack('<'+k,value[n]))
            m.mem_write(self.base+vc['array'],struct.pack('<'+'Q'*vc['count'],*self.row['volumes']));m.mem_write(self.base+vc['index'],struct.pack('<I',self.row['index']))
            w=a.withdrawal_cfg
            for name,k,key in [('enabled','B','enabled'),('last_check','q','last_check'),('last_deal','q','last_deal')]:m.mem_write(self.base+w[name],struct.pack('<'+k,value[key]))
            for name in ['peak_key','time_key']:m.mem_write(self.base+w[name],struct.pack('<IQ',0,self.string(value[name])))
            m.mem_write(self.base+live.flow.currency.CONFIG[bot]['suffix'],struct.pack('<IQ',0,self.string(value['suffix'])))
            m.mem_write(self.base+cfg['headflag'],b'\0');m.mem_write(self.base+cfg['virtual'],bytes([self.row['virtual']]));m.mem_write(self.base+cfg['percent'],struct.pack('<Q',self.row['percent']));m.mem_write(self.base+cfg['last'],struct.pack('<Q',0x1122334455667788))
            g=gate.CFG[bot]
            for rva,raw in [(g['current'],struct.pack('<Q',c['current'])),(cfg['previous'],struct.pack('<Q',c['previous'])),(cfg['flag'],bytes([c['flag']])),(cfg['stop'],struct.pack('<Q',c['stop']))]:m.mem_write(self.base+rva,raw)
            self.casts={c['id']:(self.row['percent'],a.cast_values[self.row['percent']])}
            self.phase='loop';m.emu_start(self.base+cfg['start'],0x60000000,timeout=10000000,count=3000000)
            require(bool(self.flow_error)==bool(c['fatal']),'FLOW_FATAL_CLASS '+str(c['id']));require(self.resize_exit or self.flow_error,'FLOW_NO_EXIT')
            pending=struct.pack('<i',c['id'])+bytes(self.extra)+struct.pack('<i',0)+self.snapshot()
            pending+=struct.pack('<2Q',self.selected_order&MASK,struct.unpack('<Q',m.mem_read(self.base+cfg['last'],8))[0])+bytes(m.mem_read(self.base+cfg['table'],1600))
            pending+=struct.pack('<Q',struct.unpack('<I',m.mem_read(self.base+vc['index'],4))[0])+bytes(m.mem_read(self.base+vc['array'],8*vc['count']))+p.text(self.read_text(self.base+self.cfg['symbol']))
            return struct.pack('<2iQ',c['id'],int(self.volume_called),struct.unpack('<Q',m.mem_read(self.base+cfg['previous'],8))[0])+struct.pack('<i',len(a.events))+a.events+a.state()+struct.pack('<i',len(pending))+pending
    return Original
def identity(bot):
    p=PARTS[bot];h=ROOT/f'bot-cua-toi-{bot}';source=h/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EvaluationResizeFlowCheck.mq5'
    helpers=dict(p.identity()['helpers_sha256']);helpers.update(live.identity(bot)['helpers_sha256'])
    for f in [Path(__file__),Path(gate.__file__)]:helpers[f.relative_to(ROOT).as_posix()]=sha(f)
    return dict(original_ex5_sha256=live.validation.original_hash(bot),sources_sha256={f.relative_to(source).as_posix():sha(f) for f in pub.closure(source/script,source)},helpers_sha256=helpers)
def execute(bot,folder,build,only=-1):
    h=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';receipt=h/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EvaluationResizeFlowCheck.mq5'
    require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,digest in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==digest,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
    run=folder.name+('' if only<0 else '-e'+str(only));files=mt/f'MQL5/Files/bot{bot}-resize-flow'/run;files.mkdir(parents=True,exist_ok=False)
    for n in ['cases.bin','pending-cases.bin','volume-cases.bin']:shutil.copyfile(folder/n,files/n)
    ini=mt/('resize-flow-'+run+'.ini');preset=mt/'MQL5/Presets'/('resize-flow-'+run+'.set');preset.write_text('CheckRun='+run+'\nFlowOnlyCase='+str(only)+'\n',encoding='utf-16')
    ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}EvaluationResizeFlowCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    logs=mt/'MQL5/Logs';before={p:p.stat().st_size for p in logs.glob('*.log')};p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    log='\n'.join(p.read_bytes()[before.get(p,0):].decode('utf-16-le',errors='replace') for p in logs.glob('*.log'));return files,receipt,code,log
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare','errors']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN')
    folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases(a.bot);normal=[c for c in rows if not c['fatal']];current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(normal))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False)
        for n,raw in encodings(rows,a.bot).items():(folder/n).write_bytes(raw)
        save(folder/'baseline.json',dict(**current,cases=len(normal),fatal_cases=len(rows)-len(normal),input_sha256={n:sha(folder/n) for n in encodings(rows,a.bot)},**SCOPE));print(json.dumps(dict(cases=len(normal),fatal_cases=len(rows)-len(normal))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==x for k,x in current.items()) and all((folder/n).read_bytes()==raw for n,raw in encodings(rows,a.bot).items()),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        files,receipt,code,log=execute(a.bot,folder,a.build);require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(normal)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','script-status.bin','cast-results.bin','fixed-results.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(normal),result_sha256=sha(folder/'mql5-results.bin'),cast_results_sha256=sha(folder/'cast-results.bin'),fixed_results_sha256=sha(folder/'fixed-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(normal),exit_code=code)));return
    if a.mode=='original':
        o=original_class(a.bot)(live.casts(folder/'cast-results.bin'),live.casts(folder/'fixed-results.bin'));raw=bytearray(header);errors=[]
        for c in rows:
            r=o.run_flow(c)
            if c['fatal']:
                errors.append(dict(id=c['id'],error=hex(o.flow_error),volume_events_sha256=hashlib.sha256(o.adapter.events).hexdigest(),pending_events_sha256=hashlib.sha256(o.extra).hexdigest()))
            else:raw+=r
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'native-errors.json',errors);save(folder/'original-run.json',dict(**current,cases=len(normal),fatal_cases=len(errors),result_sha256=sha(folder/'original-results.bin'),cast_results_sha256=sha(folder/'cast-results.bin'),fixed_results_sha256=sha(folder/'fixed-results.bin'),instructions=len(o.flow_covered),**SCOPE));print(json.dumps(dict(cases=len(normal),fatal_cases=len(errors),instructions=len(o.flow_covered))));return
    if a.mode=='errors':
        errors=json.loads((folder/'native-errors.json').read_text());out=[]
        for e in errors:
            files,receipt,code,log=execute(a.bot,folder,a.build,e['id']);require(code!=0 and 'zero divide' in log.lower() and 'RESIZE_FLOW_CASE:'+str(e['id']) in log,'FATAL_NOT_OBSERVED');require(not(files/'script-status.bin').exists() and (files/'mql5-results.bin').read_bytes()==header,'FATAL_COMPLETED')
            require(sha(files/f'volume-events-{e["id"]}.bin')==e['volume_events_sha256'],'FATAL_VOLUME_EVENTS');require(hashlib.sha256((files/f'pending-events-{e["id"]}.bin').read_bytes()[4:]).hexdigest()==e['pending_events_sha256'],'FATAL_PENDING_EVENTS');out.append(dict(**e,matched=True,terminal_exit_code=code,log_sha256=hashlib.sha256(log.encode()).hexdigest()))
        save(folder/'errors.json',dict(cases=len(out),matched=len(out),results=out,**SCOPE,limits=['Fault class, completed SDK events and their pre-call state; no final state after the last SDK call on a terminated script.']));print(json.dumps(dict(cases=len(out),matched=len(out))));return
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==x for k,x in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')) and r['cast_results_sha256']==sha(folder/'cast-results.bin') and r['fixed_results_sha256']==sha(folder/'fixed-results.bin'),'RUN_CHANGED')
    records=[live.Reader((folder/(n+'-results.bin')).read_bytes()) for n in ['original','mql5']];require(all(r.data[:12]==header for r in records),'RESULT_HEADER');[setattr(r,'p',12) for r in records];size=8*(len(v.fields(v.OUTPUTS,a.bot))-1+3+live.CFG[a.bot]['count']+1);failed=[]
    for c in normal:
        values=[]
        for r in records:
            start=r.p;id_,changed,previous,length=r.take('<2iQi');require(id_==c['id'],'RESULT_ID');r.p+=length+size;length,=r.take('<i');r.p+=length;values.append(r.data[start:r.p])
        if values[0]!=values[1]:failed.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*values)) if x!=y),None),sizes=list(map(len,values))))
    require(all(r.p==len(r.data) for r in records),'RESULT_TRAILING');report=dict(cases=len(normal),matched=len(normal)-len(failed),failed=len(failed),first_failures=failed[:20],**SCOPE,limits=['Evaluator balance gate through complete volume/withdrawal/currency and pending delete/open/send. Initial earlier evaluator frame/state and terminal replies supplied; no complete evaluator or EA.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
