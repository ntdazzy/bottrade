"""Compare continuous news/Friday/spread/restoration and pending-order limit stages.
prepare|mql5(--build)|original|compare BOT RUN. Stops before the next entry gates.
"""
import argparse,copy,hashlib,importlib.util,json,math,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1
def module(name,file):
    spec=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
news=module('limits_restore','kiem-khoi-phuc-lenh-da-luu-bot-1-3.py');base=news.base
pub=base.pub;require=pub.require;sha=base.sha;save=base.save;MAGIC=base.MAGIC
CFG={1:dict(end=0x1c8c7,enabled=0x62428,maximum=0x62458),3:dict(end=0x26e3e,enabled=0x6d520,maximum=0x6d550)}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_news_through_pending_limits_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,numeric_conversion_measured_in_mt5=True,original_ex5_changed=False)
def cases():
    rows=news.cases()
    for c in rows:c.update(pending_enabled=0,maximum_pending=2,totals=[c['orders'] if c['orders']<0 else int(c['orders']!=0)]*8,limit_mode=0)
    prototype=copy.deepcopy(rows[0]);prototype.update(enabled=0,ir_settings=[0,0,0,10,10],cpi_settings=[0,0,0,10,10],friday=[0,20,0,1,1],wide_enabled=0,pending_enabled=1,maximum_pending=0,orders=1,position=0,order_magic=42,second_magic=42,order_select=1,accepted=1,accepted_replies=[1]*3,totals=[1]*8)
    def add(tag,**changes):
        c=copy.deepcopy(prototype);c.update(changes);c['tag']=tag;rows.append(c);return c
    for enabled in [-1,0,1,2,255]:
        for maximum in [-1,0,1,2]:
            for total in [-1,0,1,2]:
                for kind in [4,5]:add('limit-count-delete-gates',pending_enabled=enabled,maximum_pending=maximum,totals=[total]*8,first_type=kind,second_type=kind,prices=[110. if kind==4 else 90.]*6)
    for kind in [4,5]:
        for totals in [[1,-1,0,1,1,1,1,1],[1,0,1,1,1,1,1,1],[1,2,-1,1,0,1,1,1]]:add('total-changes-between-scans',first_type=kind,second_type=kind,totals=totals)
        for mode in [1,2,3,4,5]:add('live-enabled-maximum-and-replacement',first_type=kind,second_type=kind,limit_mode=mode,maximum_pending=1 if mode==3 else 0)
        for symbol in [0,1,2]:add('count-full-symbol',first_type=kind,second_type=kind,symbol_mode=symbol)
        for magic in [42,43,42+(1<<32)]:add('count-signed-magic',first_type=kind,second_type=kind,order_magic=magic,second_magic=magic)
    for i,c in enumerate(rows):c['id']=i
    return rows

def encode(rows):
    return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(news.encode([c])[12:]+struct.pack('<11q',c['pending_enabled'],c['maximum_pending'],*c['totals'],c['limit_mode']) for c in rows)
class Original(news.Original):
    def __init__(self,bot,casts):
        super().__init__(bot,casts);self.limit=CFG[bot];self.wide=dict(self.wide,pass_ends=[self.limit['end']]);self.nfp=dict(self.nfp,end=self.limit['end'])
    def state(self):
        return super().state()+struct.pack('<2Q',self.value(self.limit['enabled'],'i')&MASK,self.value(self.limit['maximum'],'i')&MASK)
    def visit(self,m,address,size,user):
        result=super().visit(m,address,size,user)
        if address==self.base+self.nfp['start'] and not self.limit_seeded:
            self.limit_seeded=True
            for key,name in [('enabled','pending_enabled'),('maximum','maximum_pending')]:m.mem_write(self.base+self.limit[key],struct.pack('<i',self.case[name]))
        return result
    def call(self,m,address,size,user):
        api=self.sdk.get(address)
        if api==13:
            rd=self.tape;require(rd.block()==self.state(),'LIMIT_STATE_BEFORE_TOTAL '+str(self.case['id']));kind,*args=rd.take('i4Q');texts=[rd.text() for _ in range(4)];payload=rd.block();error,=rd.take('I');total=self.case['totals'][min(self.total_calls,7)];require(kind==13 and args==[total&MASK,0,0,0] and texts==[None]*4 and payload==b'' and m.reg_read(self.x.UC_X86_REG_RCX)==self.nfp['ctx'],'LIMIT_TOTAL_ARGS_OR_REPLY');m.reg_write(self.x.UC_X86_REG_RAX,total&MASK);m.mem_write(self.base+self.nfp['error'],struct.pack('<I',error));self.total_calls+=1;self.api_count+=1
            # Preserve the earlier Friday fixture's mutation after its first OrdersTotal.
            if self.case['mutation']==1 and not self.mutated:m.mem_write(self.base+self.nfp['seed'],struct.pack('<i',self.case['after_seed']));self.mutated=True
        else:super().call(m,address,size,user)
        mode=self.case['limit_mode'];field=None;value=None
        if mode==1 and api==13 and self.total_calls==1:field='enabled';value=2
        elif mode==2 and api==13 and self.total_calls==2:field='maximum';value=2
        elif mode==3 and api==18:field='maximum';value=0
        elif mode==4 and api in [21,30] and self.send_calls==1:field='enabled';value=0
        elif mode==5 and api==14:field='maximum';value=2
        if field:m.mem_write(self.base+self.limit[field],struct.pack('<i',value))
    def run(self,c,tape):
        self.limit_seeded=False;self.total_calls=0;return super().run(c,tape)

def identity(bot):
    h=ROOT/f'bot-cua-toi-{bot}';source=h/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EvaluationNewsAndOrdersCheck.mq5';helpers=dict(news.identity(bot)['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=base.validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256=helpers)
def execute(bot,folder,build):
    h=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';receipt=h/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EvaluationNewsAndOrdersCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,v in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==v,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/f'MQL5/Files/bot{bot}-news-orders'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('friday-'+folder.name+'.set');ini=mt/('friday-'+folder.name+'.ini');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}EvaluationNewsAndOrdersCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');rows=cases();folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','sdk-tape.bin','script-status.bin','cast-values.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),casts_sha256=sha(folder/'cast-values.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tape=base.Reader((folder/'sdk-tape.bin').read_bytes());require(tape.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Original(a.bot,news.news.cast_values(folder/'cast-values.bin'));o.cast_calls=o.queue_clears=0;raw=bytearray(header);calls=0
        for c in rows:
            require(tape.take('i')[0]==c['id'],'TAPE_CASE_ID');state=o.run(c,tape.block());raw+=struct.pack('<2i',c['id'],len(state))+state;calls+=o.api_count
        require(tape.pos==len(tape.raw),'TAPE_TRAILING')
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),sdk_calls=calls,cast_calls=o.cast_calls,queue_clears=o.queue_clears,casts_sha256=sha(folder/'cast-values.bin'),parent_instructions=len(o.covered),**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=calls)));return
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')) and r['sdk_tape_sha256']==sha(folder/'sdk-tape.bin') and r['casts_sha256']==sha(folder/'cast-values.bin'),'RUN_CHANGED')
    data=[base.Reader((folder/(n+'-results.bin')).read_bytes()) for n in ['original','mql5']];require(all(r.take('3i')==(MAGIC,1,len(rows)) for r in data),'RESULT_HEADER');fail=[]
    for c in rows:
        states=[]
        for r in data:require(r.take('i')[0]==c['id'],'RESULT_ID');states.append(r.block())
        if states[0]!=states[1]:fail.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*states)) if x!=y),None),sizes=list(map(len,states))))
    require(all(r.pos==len(r.raw) for r in data),'RESULT_TRAILING');result=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:12],**SCOPE,limits=['Continuous news, Friday, high/low spread and pending limits; stops before following entry gates. Initial frame/state, terminal replies, logical SDK errors, successful allocation and measured number conversions supplied. No full evaluator or EA.'])
    save(folder/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(fail))
if __name__=='__main__':main()
