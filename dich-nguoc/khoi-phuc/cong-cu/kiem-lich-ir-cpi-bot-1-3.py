"""Compare original interest/CPI calendar algorithms, predicates and timeout behavior.

prepare|original|mql5(--build)|compare|errors BOT RUN. Logical terminal errors are
supplied at calendar boundaries; StringFind results/error effects use real MT5.
"""
import argparse,copy,hashlib,importlib.util,json,random,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x52434131;MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
base=module('remaining_calendar_base','kiem-lich-nfp-bot-1-3.py');pub=base.pub;require=pub.require;sha=base.sha;save=base.save
BINDINGS=json.loads((ROOT/'danh-gia-doc-lap/remaining-news-calendars-20261027-r1/native-bindings.json').read_text());CFG={(b['bot'],1 if b['kind']=='interest' else 2):b for b in BINDINGS}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_interest_cpi_calendars_executed=True,child_helpers_intercepted=False,terminal_replies_and_errors_supplied=True,original_ex5_changed=False)
def cases():
    out=[];now=1793100000
    def add(kind,title,eventid=123,**changes):
        c=dict(id=len(out),fatal=0,kind=kind,value_error=-1,now=now,last_error=0,event_return=1,value_return=3,event_series=0,value_series=0,events=[[eventid,title]],values=[now-86400,now+200,now+100]);c.update(changes);out.append(c);return c
    for kind,names in [(1,[None,'','Other','Fed Interest Rate Decision','fed Interest Rate Decision','X Fed Interest Rate Decision','Fed Interest Rate Decision 🐱']),
                       (2,[None,'','Other','Consumer Price Index','CPI ','CPI','(YoY)','ex Food','CPI ex Food','CPI ex Food (YoY)','CPI ex Food (MoM)','Consumer Price Index ex Food','Consumer Price Index (YoY)','CPI (YoY)','cpi (YoY)'])]:
        for title in names:
            for eventid in [0,123,1<<63,(1<<64)-1]:
                for flags in [(0,0),(1,0),(0,1),(1,1)]:add(kind,title,eventid,event_series=flags[0],value_series=flags[1])
        title='Fed Interest Rate Decision' if kind==1 else 'CPI (YoY)'
        for error in [0,4009,5035,5401,65536+731]:
            for reply_error in [-1,0,5401]:
                for count in [-1,0,1,3]:add(kind,title,last_error=error,value_error=reply_error,value_return=count)
        for count in [-1,0,1]:add(kind,title,event_return=count)
        for vals in [[],[now-86401],[now-86400],[now-86399],[0,-1,1],[now+300,now+100,now+200]]:add(kind,title,values=vals,value_return=len(vals))
        for flags in [(0,0),(1,0),(0,1),(1,1)]:
            add(kind,title,event_series=flags[0],value_series=flags[1],event_return=1,events=[],value_return=0,values=[],fatal=1)
            add(kind,title,event_series=flags[0],value_series=flags[1],value_return=1,values=[],fatal=1)
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:raw+=struct.pack('<4i',c['id'],c['fatal'],c['kind'],c['value_error'])+base.encode([c])[20:]
    return bytes(raw)
class Original(base.Original):
    def __init__(self,bot):
        super().__init__(bot);self.all_covered=set()
        for address,api in [(0x7ff683f20000+0x380260,606),(0x7ff683f20000+0x7b49f0,607)]:
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        for kind in [1,2]:
            b=CFG[(bot,kind)];lo,hi=int(b['begin'],16),int(b['end'],16);require(hashlib.sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==b['sha256'],'CALENDAR_BYTES_CHANGED');self.m.hook_add(self.uc.UC_HOOK_CODE,lambda m,a,s,u:self.all_covered.add(a-self.base),begin=self.base+lo,end=self.base+hi-1)
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;c=self.case
        if api==606:
            name=self.read_text(m.reg_read(x.UC_X86_REG_RDX));require(c['kind']==1 and name=='US','COUNTRY_QUERY_ARGUMENT');self.event(5,c['event_return'],len(c['events']),txt=name);records=[]
            for eventid,title in c['events']:
                raw=bytearray(128);struct.pack_into('<Q',raw,0,eventid);struct.pack_into('<IQ',raw,72,0,0 if title is None else self.string(title));records.append(raw)
            self.array(m.reg_read(x.UC_X86_REG_R8),records,c['event_series']);m.reg_write(x.UC_X86_REG_RAX,c['event_return']&MASK);return
        if api==607:
            sp=m.reg_read(x.UC_X86_REG_RSP);require(m.reg_read(x.UC_X86_REG_RDX)==2 and m.reg_read(x.UC_X86_REG_R8)==1,'CALENDAR_PRINT_SHAPE');message=self.read_text(struct.unpack('<Q',m.mem_read(sp+40,8))[0]);self.event(4,txt=message);return
        super().call(m,address,size,user)
        if api==603 and c['value_error']>=0:m.mem_write(self.base+self.nfp['error'],struct.pack('<I',c['value_error']))
    def run(self,c):
        bind=CFG[(self.bot,c['kind'])];self.nfp=dict(self.nfp,fn=int(bind['begin'],16),end=int(bind['end'],16));return super().run(c)
def identity(bot):
    h=ROOT/f'bot-cua-toi-{bot}';source=h/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}ReleaseCalendarsCheck.mq5'
    helpers=[Path(__file__),Path(base.__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'danh-gia-doc-lap/remaining-news-calendars-20261027-r1/native-bindings.json']
    return dict(original_ex5_sha256=base.validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def execute(bot,folder,build,only=-1):
    h=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';receipt=h/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}ReleaseCalendarsCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for name,digest in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/name)==b['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');run=folder.name+('' if only<0 else '-e'+str(only));files=mt/f'MQL5/Files/bot{bot}-release-calendars'/run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('release-'+run+'.set');ini=mt/('release-'+run+'.ini');preset.write_text('CheckRun='+run+'\nOnlyCase='+str(only)+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}ReleaseCalendarsCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');logs=mt/'MQL5/Logs';before={p:p.stat().st_size for p in logs.glob('*.log')};p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    log='\n'.join(p.read_bytes()[before.get(p,0):].decode('utf-16-le',errors='replace') for p in logs.glob('*.log'));return files,receipt,code,log
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare','errors']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();normal=[c for c in rows if not c['fatal']];current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(normal))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(normal),fatal_cases=len(rows)-len(normal),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(normal),fatal_cases=len(rows)-len(normal))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='original':
        o=Original(a.bot);raw=bytearray(header);errors=[]
        for c in rows:
            result=o.run(c)
            if c['fatal']:errors.append(dict(id=c['id'],error=hex(o.error),events_sha256=hashlib.sha256(o.events).hexdigest()))
            else:raw+=result
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'native-errors.json',errors);save(folder/'original-run.json',dict(**current,cases=len(normal),fatal_cases=len(errors),instructions=len(o.all_covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(normal),fatal_cases=len(errors),instructions=len(o.all_covered))));return
    if a.mode=='mql5':
        files,receipt,code,log=execute(a.bot,folder,a.build);require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(normal)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(normal),build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(folder/'mql5-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(normal))));return
    if a.mode=='errors':
        errors=json.loads((folder/'native-errors.json').read_text());results=[]
        for e in errors:
            files,receipt,code,log=execute(a.bot,folder,a.build,e['id']);require(code!=0 and 'array out of range' in log.lower() and 'RELEASE_CALENDAR_CASE:'+str(e['id']) in log and not(files/'script-status.bin').exists(),'FATAL_NOT_OBSERVED');require(sha(files/f'events-{e["id"]}.bin')==e['events_sha256'],'FATAL_EVENT_TRACE');results.append(dict(**e,matched=True,terminal_exit_code=code,log_sha256=hashlib.sha256(log.encode()).hexdigest()))
        save(folder/'errors.json',dict(cases=len(results),matched=len(results),results=results,**SCOPE));print(json.dumps(dict(cases=len(results),matched=len(results))));return
    raw=[(folder/(n+'-results.bin')).read_bytes() for n in ['original','mql5']]
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')),'RUN_CHANGED')
    require(all(v[:12]==header for v in raw),'RESULT_HEADER');pos=[12,12];fail=[]
    for c in normal:
        records=[]
        for i,b in enumerate(raw):
            start=pos[i];id_,value,err,size=struct.unpack_from('<iQ2I',b,start);require(id_==c['id'],'RECORD_ID');pos[i]+=20+size;records.append(b[start:pos[i]])
        if records[0]!=records[1]:fail.append(dict(id=c['id'],kind=c['kind'],first_difference=next((i for i,(x,y) in enumerate(zip(*records)) if x!=y),None),head=[list(struct.unpack_from('<iQ2I',r)) for r in records]))
    require(all(p==len(b) for p,b in zip(pos,raw)),'RESULT_TRAILING');report=dict(cases=len(normal),matched=len(normal)-len(fail),failed=len(fail),first_failures=fail[:15],**SCOPE,limits=['Calendar helpers only, including country/currency queries, exact predicates, stale/injected timeout and series arrays. Calendar/error/allocation replies supplied; StringFind return/error effects measured in MT5. No IR/CPI evaluator or actual calendar network.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(fail))
if __name__=='__main__':main()
