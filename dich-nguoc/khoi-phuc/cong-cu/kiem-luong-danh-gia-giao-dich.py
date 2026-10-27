"""Compare continuous NFP/calendar gates through new-bar cache and actual entry loops.
prepare|mql5(--build)|original|compare BOT RUN. Earlier evaluator and UI/lifecycle remain outside scope.
"""
import argparse,copy,hashlib,importlib.util,json,math,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1
def module(name,file):
    spec=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
PARTS={bot:module('trade_flow_'+str(bot),f'kiem-vong-phat-sinh-lenh-bot-{bot}.py') for bot in [1,3]}
base=PARTS[1].base;pub=base.pub;require=pub.require;sha=base.sha;save=base.save;MAGIC=base.MAGIC;Reader=PARTS[1].Reader
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_continuous_news_to_entry_loop=True,child_helpers_intercepted=False,terminal_replies_supplied=True,withdrawals_disabled=True,volume_mode_coverage=[0],original_ex5_changed=False)
def cases(bot):
    rows=PARTS[bot].cases()
    for c in rows:c.update(enabled=0,ir_settings=[0,0,0,10,10],cpi_settings=[0,0,0,10,10],pending_enabled=1,entry_blocked=0,wide_enabled=0,friday=[0,20,0,1,1])
    prototype=copy.deepcopy(rows[22])
    for mode in ['same-bar','entry-blocked','disabled','friday-closed','nfp-block','interest-block','cpi-block']:
        c=copy.deepcopy(prototype);c['tag']='joined-'+mode
        if mode=='same-bar':c['stored_time']=c['first_time']
        elif mode=='entry-blocked':c['entry_blocked']=1
        elif mode=='disabled':c['pending_enabled']=0
        elif mode=='friday-closed':c['friday'][2]=1
        elif mode=='nfp-block':c['enabled']=1
        elif mode=='interest-block':c['ir_settings'][0]=1
        else:c['cpi_settings'][0]=1
        if mode in ['nfp-block','interest-block','cpi-block']:
            c.update(use_calendar=1,throttle=1,info=0,last_query=c['server']-901,calendar_status=1,release=c['current']+300,ir_release=c['current']+300,cpi_release=c['current']+300)
            c['ir_state']=[0,0,0];c['cpi_state']=[0,0,0]
        rows.append(c)
    for i,c in enumerate(rows):c['id']=i
    return rows

def encode(rows,bot):return PARTS[bot].encode(rows)
def Original(bot,casts):
    part=PARTS[bot];cache=part.news;end=0x1e94f if bot==1 else 0x29c88;bar_end=0x1ca24 if bot==1 else 0x26f9e
    class Joined(part.Original):
        def __init__(self):
            super().__init__(bot,casts);self.nfp=dict(self.nfp,start=part.base.CFG[bot]['start'],end=end)
        def state(self):return cache.Original.state(self)+part.Original.state(self)
        def visit(self,m,address,size,user):
            rva=address-self.base
            if rva==end:self.entry_decision=2 if self.saw_new_bar else 1;self.done=True;m.emu_stop();return
            if rva==bar_end:self.saw_new_bar=True
            return super().visit(m,address,size,user)
        def run(self,c,tape):self.saw_new_bar=False;return super().run(c,tape)
    return Joined()
def identity(bot):
    h=ROOT/f'bot-cua-toi-{bot}';source=h/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EvaluationTradeFlowCheck.mq5';helpers=dict(PARTS[bot].identity(bot)['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=base.validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256=helpers)

def execute(bot,folder,build):
    h=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';receipt=h/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EvaluationTradeFlowCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,v in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==v,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/f'MQL5/Files/bot{bot}-evaluation-trade-flow'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('friday-'+folder.name+'.set');ini=mt/('friday-'+folder.name+'.ini');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}EvaluationTradeFlowCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');rows=cases(a.bot);folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows,a.bot));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows,a.bot),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','sdk-tape.bin','script-status.bin','cast-values.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),casts_sha256=sha(folder/'cast-values.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tape=Reader((folder/'sdk-tape.bin').read_bytes());require(tape.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Original(a.bot,PARTS[a.bot].news.news.news.news.cast_values(folder/'cast-values.bin'));o.cast_calls=o.queue_clears=0;raw=bytearray(header);calls=0
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
    require(all(r.pos==len(r.raw) for r in data),'RESULT_TRAILING');result=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:12],**SCOPE,limits=['Continuous NFP through all trade gates and entry loops, actual children. Volume mode0/withdrawals disabled in this suite. Earlier evaluator and display/housekeeping excluded. Initial frame/state, terminal replies, logical SDK errors, successful allocation and measured number conversions supplied. No full evaluator or EA.'])
    save(folder/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(fail))
if __name__=='__main__':main()
