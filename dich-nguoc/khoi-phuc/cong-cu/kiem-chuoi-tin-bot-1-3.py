"""Run original NFP -> interest -> CPI -> selector, comparing SDK arguments and state.
prepare|mql5(--build)|original|compare BOT RUN. No child algorithm results supplied.
"""
import argparse,copy,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
base=module('news_pipeline_base','kiem-nfp-toan-nhanh-bot-1-3.py');pub=base.pub;require=pub.require;sha=base.sha;save=base.save;MAGIC=base.MAGIC
CFG={1:dict(pass_end=0x1c6f1,blocked_end=0x1a63a,ir_flags=[0x6a698,0x6a6a8,0x6a6a0],ir_minutes=[0x6a6b0,0x6a6b8],ir_state=[0x6a388,0x67489,0x6a378],ir_history=0x68ca0,cpi_flags=[0x6a6d0,0x6a6e0,0x6a6d8],cpi_minutes=[0x6a6e8,0x6a6f0],cpi_state=[0x6a389,0x6748a,0x6a380],cpi_history=0x69600,selection=0x6a390,label=0x6a398),
3:dict(pass_end=0x24f8d,blocked_end=0x22875,ir_flags=[0x1d7078,0x1d7088,0x1d7080],ir_minutes=[0x1d7090,0x1d7098],ir_state=[0x1d6c98,0x744c9,0x1d6c88],ir_history=0x75cd0,cpi_flags=[0x1d70b0,0x1d70c0,0x1d70b8],cpi_minutes=[0x1d70c8,0x1d70d0],cpi_state=[0x1d6c99,0x744ca,0x1d6c90],cpi_history=0x76630,selection=0x1d6ca0,label=0x1d6ca8)}
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_complete_news_pipeline_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
def cases():
    rows=base.cases()
    for c in rows:c.update(ir_settings=[1,0,0,10,10],cpi_settings=[1,0,0,10,10],ir_state=[0,0,0],cpi_state=[0,0,0])
    prototype=copy.deepcopy(rows[0]);prototype.update(enabled=1,use_calendar=1,info=0,orders=1,position=1)
    for flags in range(8):
        c=copy.deepcopy(prototype);c.update(enabled=flags&1,ir_settings=[int(bool(flags&2)),1,1,10,10],cpi_settings=[int(bool(flags&4)),1,1,10,10],tag='three-enabled-combinations');rows.append(c)
    for active in ['ir','cpi']:
        for blocked in [0,1,2,3,255]:
            c=copy.deepcopy(prototype);c.update(enabled=0,use_calendar=0,server=base.stamp(2027,1,1),current=base.stamp(2027,1,1),tag='preserve-byte-block-flags');c['cached']=base.date_words(c['current']);c['ir_settings'][0]=int(active=='ir');c['cpi_settings'][0]=int(active=='cpi');c[active+'_state'][1]=blocked;rows.append(c)
    for order in [1,2]:
        for position in [1,2]:
            for early in ['ir','cpi']:
                c=copy.deepcopy(prototype);c.update(orders=order,position=position,ir_settings=[1,1,1,10,10],cpi_settings=[1,1,1,10,10],ir_release=prototype['server']+(100 if early=='ir' else 200),cpi_release=prototype['server']+(200 if early=='ir' else 100),tag='earliest-and-three-action-contexts');rows.append(c)
    for i,c in enumerate(rows):c.update(id=i,ir_release=c.get('ir_release',c['release']),cpi_release=c.get('cpi_release',c['release']))
    return rows
def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(base.encode([c])[12:]+struct.pack('<18q',*c['ir_settings'],*c['ir_state'],*c['cpi_settings'],*c['cpi_state'],c['ir_release'],c['cpi_release']) for c in rows)
class Original(base.Original):
    def __init__(self,bot):
        super().__init__(bot);self.news=CFG[bot];self.nfp=dict(self.nfp,end=self.news['pass_end']);a=0x7ff683f20000+0x380260
        if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
        self.sdk[a]=31;self.m.mem_write(a,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
    def state(self):
        raw=super().state();extra=bytearray();cfg=self.news
        for prefix in ['ir','cpi']:
            for a in cfg[prefix+'_flags']:extra+=struct.pack('<Q',self.value(a,'B'))
            for a in cfg[prefix+'_minutes']:extra+=struct.pack('<Q',self.value(a,'i')&MASK)
            for i,a in enumerate(cfg[prefix+'_state']):extra+=struct.pack('<Q',self.value(a,'B' if i<2 else 'q')&MASK)
        extra+=struct.pack('<Q',self.value(cfg['selection'],'Q'))+base.text(self.read_text(self.base+cfg['label']))
        return raw[:96]+extra+raw[96:]
    def visit(self,m,address,size,user):
        if address==self.base+self.nfp['start'] and not self.seeded:
            self.seeded=True
            for prefix in ['ir','cpi']:
                for a,v in zip(self.news[prefix+'_flags'],self.case[prefix+'_settings'][:3]):m.mem_write(self.base+a,struct.pack('<B',v))
                for a,v in zip(self.news[prefix+'_minutes'],self.case[prefix+'_settings'][3:]):m.mem_write(self.base+a,struct.pack('<i',v))
                for i,(a,v) in enumerate(zip(self.news[prefix+'_state'],self.case[prefix+'_state'])):m.mem_write(self.base+a,struct.pack('<'+('B' if i<2 else 'q'),v))
                m.mem_write(self.base+self.news[prefix+'_history'],struct.pack('<300q',*self.case['history']))
            m.mem_write(self.base+self.news['selection'],bytes(8));m.mem_write(self.base+self.news['label'],bytes(12))
        if address==self.base+self.news['blocked_end']:self.blocked=True;self.done=True;m.emu_stop();return
        return super().visit(m,address,size,user)
    def call(self,m,address,size,user):
        api=self.sdk.get(address)
        if api not in [11,12,31]:return super().call(m,address,size,user)
        rd=self.tape;require(rd.block()==self.state(),'NEWS_STATE_BEFORE_SDK '+str((self.case['id'],api)));kind,*args=rd.take('i4Q');strings=[rd.text() for _ in range(4)];rd.block();error,=rd.take('I');a,b,c,d=args;x=self.x;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));require(kind==api,'NEWS_SDK_KIND');require(r('RCX')==self.nfp['ctx'],'NEWS_SDK_CONTEXT')
        if api in [11,31]:
            require(self.read_text(r('RDX'))==strings[0]==('US' if api==31 else 'USD'),'NEWS_CALENDAR_CODE');status=self.case['calendar_status'];names=[(99,'Fed Interest Rate Decision')] if api==31 else [(77,'Nonfarm Payrolls'),(88,'CPI (YoY)')];records=[]
            if status>0:
                for identifier,name in names:
                    raw=bytearray(128);struct.pack_into('<Q',raw,0,0 if status==3 else identifier);title=None if status==4 else 'Other' if status==2 else name;struct.pack_into('<IQ',raw,72,0,0 if title is None else self.string(title));records.append(raw)
            require(b==len(records) and a==((-1&MASK) if status<0 else len(records)),'NEWS_EVENT_REPLY');self.array(r('R8'),records);m.reg_write(x.UC_X86_REG_RAX,a)
        else:
            require((r('RDX'),r('R9'),struct.unpack('<Q',m.mem_read(r('RSP')+40,8))[0])==(a,b,c),'NEWS_HISTORY_ARGS');row=bytearray(128);key='ir_release' if a in [99,0x3212255e] else 'cpi_release' if a in [88,0x3211d735] else 'release';struct.pack_into('<q',row,16,self.case[key]);self.array(r('R8'),[row]);require(d==1,'NEWS_VALUES_REPLY');m.reg_write(x.UC_X86_REG_RAX,d)
        m.mem_write(self.base+self.nfp['error'],struct.pack('<I',error));self.api_count+=1
    def run(self,c,tape):
        self.seeded=False;self.blocked=False;return super().run(c,tape)+struct.pack('<Q',int(self.blocked))
def identity(bot):
    h=ROOT/f'bot-cua-toi-{bot}';source=h/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NewsPipelineCheck.mq5';helpers=dict(base.identity(bot)['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=base.validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256=helpers)
def execute(bot,folder,build):
    h=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';receipt=h/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}NewsPipelineCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,v in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==v,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/f'MQL5/Files/bot{bot}-news-pipeline'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('news-'+folder.name+'.set');ini=mt/('news-'+folder.name+'.ini');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}NewsPipelineCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');rows=cases();folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','sdk-tape.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tape=base.Reader((folder/'sdk-tape.bin').read_bytes());require(tape.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Original(a.bot);raw=bytearray(header);calls=0
        for c in rows:
            require(tape.take('i')[0]==c['id'],'TAPE_CASE_ID');state=o.run(c,tape.block());raw+=struct.pack('<2i',c['id'],len(state))+state;calls+=o.api_count
        require(tape.pos==len(tape.raw),'TAPE_TRAILING')
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),sdk_calls=calls,parent_instructions=len(o.covered),**SCOPE));print(json.dumps(dict(cases=len(rows),sdk_calls=calls)));return
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')) and r['sdk_tape_sha256']==sha(folder/'sdk-tape.bin'),'RUN_CHANGED')
    data=[base.Reader((folder/(n+'-results.bin')).read_bytes()) for n in ['original','mql5']];require(all(r.take('3i')==(MAGIC,1,len(rows)) for r in data),'RESULT_HEADER');fail=[]
    for c in rows:
        states=[]
        for r in data:require(r.take('i')[0]==c['id'],'RESULT_ID');states.append(r.block())
        if states[0]!=states[1]:fail.append(dict(id=c['id'],tag=c['tag'],first_difference=next((i for i,(x,y) in enumerate(zip(*states)) if x!=y),None),sizes=list(map(len,states))))
    require(all(r.pos==len(r.raw) for r in data),'RESULT_TRAILING');result=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:12],**SCOPE,limits=['Complete news section only; initial frame/state and terminal replies supplied. No full EA, live broker or allocation-fault proof.'])
    save(folder/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(fail))
if __name__=='__main__':main()
