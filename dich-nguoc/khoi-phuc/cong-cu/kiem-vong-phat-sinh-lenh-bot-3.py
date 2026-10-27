"""Execute bot3's entire new-bar entry loop, including native volume, guards and order send.
prepare|mql5(--build)|original|compare 3 RUN. Display/housekeeping and whole-EA lifecycle excluded.
"""
import argparse,copy,hashlib,importlib.util,json,math,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1
def module(name,file):
    spec=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
news=module('entry_loop_cache','kiem-cap-nhat-muc-gia-bot-1-3.py');base=news.base
pub=base.pub;require=pub.require;sha=base.sha;save=base.save;MAGIC=base.MAGIC;Reader=news.Reader
LOOP=[('buy_enabled','B',0x1d6f80),('sell_enabled','B',0x1d6f88),('volume_enabled','B',0x6d644),('delete_expired','B',0x6d511),('skip_position_gate','B',0x73aa8),('replace_at_equal','B',0x74950),('submission.check_free_margin','B',0x6d51c),('submission.omit_real_sl_tp','B',0x6d510),('confirmation_frame','i',0x6d2b4),('older_width','i',0x6d528),('recent_width','i',0x6d52c),('last_shift','i',0x6d530),('expiration_setting','i',0x6d560),('expiration_seconds','I',0x73de0),('gap_points','d',0x6d538),('buy_offset','d',0x6d540),('sell_offset','d',0x6d548),('radius','d',0x6d558),('step_reference','d',0x6d600)]
LOOP += [('maximum_positions','i',0x6d2e4),('maximum_group_pending','d',0x6d240)]
STATES=[('candidate_buy',0x74480),('candidate_sell',0x74478),('rounded_buy',0x6d660),('rounded_sell',0x6d668),('active_step',0x74428)]
VOLUME=[('use_equity','B',0x1d7180,0),('only_up','B',0x1d7160,1),('manual_balance','d',0x1d7128,0.),('start_lots','d',0x6d620,.1),('max_lots','d',0x6d628,.5),('lot_scale','d',0x6d1c8,1.),('manual_risk','d',0x6d638,1.2),('strategy_risk','d',0x1d7150,3.)]
VOLUME += [('max_total_dd','d',0x1d7140,30.),('weighted','B',0x1d7148,0),('frequency','i',0x6d21c,2)]
VS=[('effective_balance','d',0x1d6c60,0.),('highest_balance','d',0x1d6c68,10000.),('mode','I',0x6d630,0),('strategy_loss','d',0x76fa0,1400.),('balance_step','i',0x6d640,600)]
VS += [('adaptive_fraction','d',0x6d428,.125)]
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,native_complete_entry_loop_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,withdrawals_disabled=True,volume_mode_coverage=[0],original_ex5_changed=False)
def cases():
    prototype=copy.deepcopy(news.cases()[0]);prototype.update(maximum_pending=1,entry_mode=0,orders=0,position=0,totals=[0]*8,accepted=1,accepted_replies=[1]*3,order_select=1,first_type=4,second_type=4,order_magic=42,second_magic=42,high=[100.,100.,120.,100.,90.,80.,70.,60.,50.,40.,30.,20.,10.,0.,0.,0.],low=[100.,100.,80.,100.,110.,120.,130.,140.,150.,160.,170.,180.,190.,200.,200.,200.])
    defaults=[1,1,1,0,0,1,0,0,15,2,1,5,0,7200,0.,2.,2.,1.,1.,100,100.];prototype.update(loop=defaults,max_lots=.5,created=0,position_magic=42,account_limit=0)
    rows=[]
    def add(tag,**changes):
        c=copy.deepcopy(prototype);c.update(changes);c['tag']=tag;rows.append(c);return c
    for maximum in [-1,0,1,2,3]:
        for buy in [0,1,255]:
            for sell in [0,1,255]:
                c=add('entry-loop-directions-and-count',maximum_pending=maximum);c['loop'][0:2]=[buy,sell]
    for position in [0,1,2]:
        for magic in [42,43,42+(1<<32)]:
            for skip in [0,1]:
                c=add('same-direction-position-gate',position=position,position_magic=magic);c['loop'][4]=skip
    for kind in [4,5]:
        for price in [0.,78.,110.,122.,200.]:
            for replace in [0,1,2,255]:
                c=add('equal-count-replacement-and-nearby',orders=1,totals=[1]*8,first_type=kind,second_type=kind,prices=[price]*6);c['loop'][5]=replace
    for setting in [-1,0,1]:
        for seconds in [0,1,7200,0xffffffff]:
            for deleted in [0,1]:
                c=add('expiration-anchor-and-cleanup',orders=1,totals=[1]*8,created=base.stamp(2026,1,2)-7200);c['loop'][12:14]=[setting,seconds];c['loop'][3]=deleted;c['loop'][0:2]=[0,0]
    for margin in [0,1]:
        for omit in [0,1,255]:
            for virtual in [0,1,255]:
                c=add('actual-margin-send-and-expiration',virtual=virtual);c['loop'][6:8]=[margin,omit]
    for accepted,errors in [([1]*3,[0]*3),([0]*3,[3]*3),([0,1,1],[132,0,0]),([0,0,1],[132,132,0]),([0]*3,[999]*3)]:
        for async_mode in [0,1]:add('full-native-send-and-retry',accepted_replies=accepted,error_replies=errors,async_mode=async_mode)
    for enabled in [0,1,255]:
        for maximum in [.05,.1,.5]:
            c=add('volume-caller-and-cap',max_lots=maximum);c['loop'][2]=enabled
    for limit in [-1,0,1,2]:add('account-order-limit',account_limit=limit)
    for positions in [-1,0,1,2]:
        for group_limit in [-1.,0.,1.,2.,float('nan'),float('inf')]:
            for existing in [0,1,2]:
                c=add('bot3-risk-count-cancel',position=existing,orders=1,totals=[1]*8,order_magic=43,second_magic=43);c['loop'][19:21]=[positions,group_limit]
    for offset in list(range(1,16))+[0,16]:
        c=add('bot3-each-group-magic',orders=1,totals=[1]*8,order_magic=42+offset,second_magic=42+offset);c['loop'][20]=1.
    for seed in [2147483647,-2147483648,-1]:
        value=(seed+1)&0xffffffff;value=value if value<0x80000000 else value-0x100000000
        c=add('bot3-group-signed-wrap',seed=seed,orders=1,totals=[1]*8,order_magic=value,second_magic=value);c['loop'][20]=1.
    for i,c in enumerate(rows):c['id']=i
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=news.encode([c])[12:]+struct.pack('<'+str(len(LOOP))+'Q',*[base.bits(v) if k=='d' else v&MASK for v,(_,k,_) in zip(c['loop'],LOOP)])+struct.pack('<Q3q',base.bits(c['max_lots']),c['created'],c['position_magic'],c['account_limit'])
    return bytes(raw)
class Original(news.Original):
    def __init__(self,bot,casts):
        require(bot==3,'BOT3_ONLY');super().__init__(bot,casts);self.entry=dict(self.entry,end=0x29c88);self.wide=dict(self.wide,pass_ends=[0x29c88]);self.nfp=dict(self.nfp,start=0x26f9e,end=0x29c88)
        for api,off in [(38,0x797370),(39,0x7bdc90),(40,0x797410),(41,0x7973c0),(42,0x7d8d40)]:
            a=0x7ff683f20000+off;existed=a in self.apis or a in self.sdk
            if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
            self.sdk[a]=api;self.m.mem_write(a,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
    def state(self):
        raw=bytearray();cfg=self.nfp
        def word(v):raw.extend(struct.pack('<Q',v&MASK))
        word(self.value(cfg['magic'],'i'));word(self.value(cfg['seed'],'i'));raw.extend(base.text(self.read_text(self.base+cfg['symbol'])))
        for address in cfg['variables']:word(self.value(address,'Q'))
        word(self.value(cfg['ticket'],'Q'));word(self.value(cfg['deviation'],'Q'))
        for key,schema in base.SCHEMAS.items():
            for field in schema['fields']:
                address=cfg['request']+base.BASES[key]+field['offset'];kind=field['kind']
                if kind=='s':raw.extend(base.text(self.read_text(self.base+address)))
                else:word(self.value(address,'Q' if kind=='d' else kind))
        word(self.value(cfg['stored_magic'],'Q'));word(self.value(cfg['stored_magic']+16,'i'));word(self.value(cfg['trade_ctx']+660,'B'));word(self.value(cfg['trade_ctx']+685,'i'));word(self.value(cfg['trade_ctx']+681,'i'));word(self.value(cfg['error'],'I'))
        word(self.value(self.limit['maximum'],'i'))
        for _,kind,address in LOOP:word(self.value(address,'Q' if kind=='d' else kind))
        for _,address in STATES:word(self.value(address,'Q'))
        for _,kind,address,_ in VOLUME+VS:word(self.value(address,'Q' if kind=='d' else kind))
        raw.extend(self.m.mem_read(self.base+0x73ac0,72));word(self.value(self.wide['unit'],'Q'));word(self.value(self.entry['index'],'I'))
        r=self.restore
        for name in ['sl','tp','anchor']:word(self.value(r[name],'Q'))
        word(self.value(r['virtual'],'B'));raw.extend(base.text(self.read_text(self.base+r['comment'])));word(self.value(r['counter'],'I'));raw.extend(self.m.mem_read(self.base+self.wide['results'],1600))
        word(self.value(0x76fa8,'Q'));raw.extend(struct.pack('<5Q',*[self.value(0x75350+i,'B') for i in range(5)]));return bytes(raw)
    def visit(self,m,address,size,user):
        result=super().visit(m,address,size,user)
        if address==self.base+self.nfp['start'] and not self.loop_seeded:
            self.loop_seeded=True;c=self.case
            for (_,k,a),v in zip(LOOP,c['loop']):m.mem_write(self.base+a,struct.pack('<'+k,v))
            for _,a in STATES:m.mem_write(self.base+a,bytes(8))
            for n,k,a,v in VOLUME+VS:m.mem_write(self.base+a,struct.pack('<'+k,c['max_lots'] if n=='max_lots' else v))
            m.mem_write(self.base+0x73ac0,struct.pack('<9d',*[.1]*9));m.mem_write(self.base+0x1d7170,bytes(1));m.mem_write(self.base+0x1d6cc8,struct.pack('<IQ',0,self.string('peak')));m.mem_write(self.base+0x1d6cd8,struct.pack('<IQ',0,self.string('time')))
            for a in [0x1d6ce8,0x1d6cf0]:m.mem_write(self.base+a,bytes(8))
            m.mem_write(self.base+0x76fa8,struct.pack('<d',10.));m.mem_write(self.base+0x75350,bytes([1]*5))
        return result
    def call(self,m,address,size,user):
        api=self.sdk.get(address)
        if api==10:
            peek=base.Reader(self.tape.raw[self.tape.pos:]);peek.block();kind,*args=peek.take('i4Q')
            if args[0]==6:
                rd=self.tape;require(rd.block()==self.state(),'ENTRY_SIX_PRINT_STATE');kind,*args=rd.take('i4Q');texts=[rd.text() for _ in range(4)];extra=base.Reader(rd.block());texts.extend([extra.text(),extra.text()]);error,=rd.take('I');x=self.x;sp=m.reg_read(x.UC_X86_REG_RSP)
                require(kind==10 and m.reg_read(x.UC_X86_REG_RDX)==2 and m.reg_read(x.UC_X86_REG_R8)==6 and extra.pos==len(extra.raw),'ENTRY_SIX_PRINT_SHAPE')
                for i,text in enumerate(texts):require(self.read_text(struct.unpack('<Q',m.mem_read(sp+40+16*i,8))[0])==text,'ENTRY_SIX_PRINT_TEXT')
                m.mem_write(self.base+self.nfp['error'],struct.pack('<I',error));self.api_count+=1;return
        if api not in [38,39,40,41,42]:return super().call(m,address,size,user)
        rd=self.tape;require(rd.block()==self.state(),'ENTRY_LOOP_STATE '+str((self.case['id'],api)));kind,*args=rd.take('i4Q');strings=[rd.text() for _ in range(4)];payload=rd.block();error,=rd.take('I');x=self.x;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));require(kind==api and r('RCX')==self.nfp['ctx'],'ENTRY_LOOP_CONTEXT')
        def integer(v):m.reg_write(x.UC_X86_REG_RAX,v&MASK)
        def double(v):m.reg_write(x.UC_X86_REG_XMM0,v);m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',v))
        a,b,c,d=args
        if api==38:
            expected=10000. if a in [37,42] else 11000.;require(r('RDX')==a and a in [37,40,42] and b==base.bits(expected),'ENTRY_ACCOUNT_DOUBLE');double(b)
        elif api==39:require(self.read_text(r('RDX'))==strings[0] and (r('XMM2')&MASK)==a,'ENTRY_GLOBAL_SET');integer(b)
        elif api==40:require(r('RDX')==a==36 and strings[0]=='USD','ENTRY_ACCOUNT_CURRENCY');m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string('USD')))
        elif api==41:require(r('RDX')==a==47 and b==(self.case['account_limit']&MASK),'ENTRY_ACCOUNT_LIMIT');integer(b)
        else:
            sp=r('RSP');price=struct.unpack('<Q',m.mem_read(sp+40,8))[0];target=struct.unpack('<Q',m.mem_read(sp+48,8))[0];require(r('RDX')==a and self.read_text(r('R8'))==strings[0] and (r('XMM3')&MASK)==b and price==c and d==1 and payload==struct.pack('<d',100.),'ENTRY_MARGIN_ARGUMENTS');m.mem_write(target,payload);integer(d)
        m.mem_write(self.base+self.nfp['error'],struct.pack('<I',error));self.api_count+=1
    def run(self,c,tape):self.loop_seeded=False;return super().run(c,tape)

def identity(bot):
    h=ROOT/f'bot-cua-toi-{bot}';source=h/'source/MQL5';script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EntryLoopCheck.mq5';helpers=dict(news.identity(bot)['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=base.validation.original_hash(bot),sources_sha256={p.relative_to(source).as_posix():sha(p) for p in pub.closure(source/script,source)},helpers_sha256=helpers)
def execute(bot,folder,build):
    h=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';receipt=h/'bang-chung/bien-dich'/build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}EntryLoopCheck.mq5';require(b['target']==script and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
    for n,v in identity(bot)['sources_sha256'].items():require(sha(mt/'MQL5'/n)==b['sources_sha256'][n]==v,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED');files=mt/f'MQL5/Files/bot{bot}-entry-loop'/folder.name;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
    preset=mt/'MQL5/Presets'/('friday-'+folder.name+'.set');ini=mt/('friday-'+folder.name+'.ini');preset.write_text('CheckRun='+folder.name+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}EntryLoopCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=p.wait(timeout=120)
    except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0,'MT5_EXIT');return files,receipt
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,32}',a.run),'BAD_RUN');rows=cases();folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run;current=identity(a.bot);header=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        files,receipt=execute(a.bot,folder,a.build);require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','sdk-tape.bin','script-status.bin','cast-values.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),sdk_tape_sha256=sha(folder/'sdk-tape.bin'),casts_sha256=sha(folder/'cast-values.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        tape=Reader((folder/'sdk-tape.bin').read_bytes());require(tape.take('3i')==(MAGIC,1,len(rows)),'TAPE_HEADER');o=Original(a.bot,news.news.news.news.cast_values(folder/'cast-values.bin'));o.cast_calls=o.queue_clears=0;raw=bytearray(header);calls=0
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
    require(all(r.pos==len(r.raw) for r in data),'RESULT_TRAILING');result=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:12],**SCOPE,limits=['Complete bot3 entry loop including actual child bodies; volume mode0 and withdrawals disabled in this integration suite. Preceding evaluator and display/housekeeping excluded. Initial frame/state, terminal replies, logical SDK errors, successful allocation and measured number conversions supplied. No full evaluator or EA.'])
    save(folder/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(fail))
if __name__=='__main__':main()
