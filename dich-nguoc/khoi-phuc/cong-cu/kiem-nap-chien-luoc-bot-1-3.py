"""Compare contiguous profile -> context -> preparation with MQL5 setup.

prepare|original|mql5(--build)|compare BOT RUN. Original preparation is called
by the captured dispatcher and returns naturally; no middle register reset.
Caller constant preloads, stack, successful allocation and SDK replies are
supplied. Stops before evaluation; this does not prove a complete EA.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
cx=module('setup_context_contract',ROOT/'cong-cu/kiem-ngu-canh-chien-luoc-bot-1-3.py')
require,sha,save=cx.require,cx.sha,cx.save
EXTRA_NAMES=['context.magic','context.converted_value','context.reference','context.account_reads','context.price_reads',
             'context.price_hash','context.service_hash','combined_service_hash']
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
 original_three_bodies_contiguous=True,native_preparation_call_and_return_checked=True,
 caller_constant_preloads_and_stack_supplied=True,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Valid strategy indices; native scalar prefix, context and actual preparation call/return run continuously without a middle register reset.',
 'Caller constant preloads, stack, successful string allocation and common inputs/SDK replies are supplied. Not every path from dispatcher entry.',
 'The evaluator, startup/symbol selection, allocation failures, combined error cases, full EA/UI/restart and real broker behavior remain unverified.',
 'Bot3 retains the separately measured CPU fixture for both-NaN arithmetic; no claim that the whole original ran on the CPU.']
COMMON_PRELOADS={1:[(0x123fd,'rbp',0x5c0),(0x12438,'rbx',0x47d20),(0x12442,'r12',0x69f70),
                    (0x1244c,'r13',0x7500),(0x12456,'r15',0x18aa0)],3:[(0x1a7d7,'r12',0x5c0)]}
def fixture(row,n):
    i=row['id'];control=i//n
    return dict(keep=[0,1,255][(i+2*control)%3],alternate=(255*((i+control)%2)),
      base_magic=[-2147483648,0,2147483647][(i//3+control)%3],prefix='Vàng 🚀' if i%2 else '',
      prior_comment='cũ'+str(i),currency=['USD','EUR','JPY','CHF','VND'][(i//5+row['index'])%5],suffix='.a' if i%2 else '')
def text(o,descriptor):
    ptr=struct.unpack('<Q',o.m.mem_read(descriptor+4,8))[0]
    if not ptr:return ''
    n=struct.unpack('<I',o.m.mem_read(ptr-4,4))[0];require(n<10000,'TEXT_TOO_LONG')
    return bytes(o.m.mem_read(ptr,n*2)).decode('utf-16-le')
def contract(bot):
    chain=module('setup_chain_'+str(bot),ROOT/f'bot-cua-toi-{bot}/tests/check-profile-preparation.py')
    return chain,chain.full,chain.data
def original_class(bot,chain,full):
    class Original(chain.Original):
        def __init__(self):
            super().__init__();self.ctx_cfg=cx.CONFIG[bot];self.context_covered=set();self.phase='idle'
            require(all(self.stops[i]==v for i,v in enumerate(self.ctx_cfg['starts'])),'CONTEXT_BOUNDARY_DIFFERS')
            self.prep=0x7500 if bot==1 else 0xe0c0;self.call_size=3 if bot==1 else 2
            for off,reg,target in COMMON_PRELOADS[bot]:
                instruction=self.instructions[self.base+off]
                require(instruction.mnemonic=='movabs' and instruction.op_str==reg+', '+hex(self.base+target),'CALLER_CONSTANT_DIFFERS')
            for off in self.ctx_cfg['stops']:
                instruction=self.instructions[self.base+off];require(instruction.mnemonic=='call' and instruction.size==self.call_size,'PREPARATION_CALL_DIFFERS')
            functions=json.loads((ROOT/'danh-gia-doc-lap/strategy-context-20261027-r1/native-account-conditions.json').read_text())
            fn=next(f for f in functions if f['bot']==bot);lo=int(fn['currency_function_begin'],16);hi=int(fn['currency_function_end_exclusive'],16)
            require(cx.sha_native(self,lo,hi)==fn['currency_function_sha256'],'CURRENCY_BODY_DIFFERS')
            eb=next(addr for addr,api in self.apis.items() if api==1)-0x7d3c40
            for addr,api in [(eb+0x797410,1000),(eb+0x7d3d40,1001)]:
                existed=addr in self.apis
                if not any(lo<=addr<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(addr&~0xfff,4096)
                self.apis[addr]=api;self.m.mem_write(addr,b'\xc3')
                if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
        def prefix_visit(self,m,address,size,user):
            if self.phase=='profile':
                if address==self.base+self.stops[self.index]:
                    require(self.required.issubset(self.written),'PROFILE_FIELDS_MISSING');self.phase='context'
                else:
                    require(address in self.instructions and self.instructions[address].mnemonic!='call','LEFT_PROFILE_PREFIX')
                    self.prefix_covered.add(address-self.base);return
            if self.phase=='preparation' and address==self.after:
                require(self.prep_calls==1,'PREPARATION_CALL_COUNT');self.stopped=True;self.phase='done';m.emu_stop();return
            if self.phase=='context':self.context_covered.add(address-self.base)
        def visit(self,m,address,size,user):
            self.covered.add(address-self.base)
            if address!=self.base+self.prep:return
            require(self.phase=='context' and m.reg_read(self.x.UC_X86_REG_RCX)==self.index,'BAD_PREPARATION_ENTRY')
            sp=m.reg_read(self.x.UC_X86_REG_RSP);require(struct.unpack('<Q',m.mem_read(sp,8))[0]==self.after,'BAD_NATIVE_RETURN_ADDRESS')
            self.phase='preparation';self.prep_calls+=1
            self.loaded=([self.value(0x6a478,'I')]+[self.value(off,k) for _,k,off in chain.PROFILE_FIELDS]) if bot==1 else [self.value(off,k) for _,k,off in chain.runtime.FIELDS]
        def call(self,m,address,size,user):
            api=self.apis[address];x=self.x
            if api==1000:
                require(m.reg_read(x.UC_X86_REG_RDX)==36,'ACCOUNT_PROPERTY_DIFFERS');self.account_reads+=1
                m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,self.string(self.fx['currency'])))
                for word in [10,cx.currency.entry_check.text_hash(self.fx['currency'])]:
                    self.fx_service_hash=cx.event(self.fx_service_hash,word);self.all_service_hash=cx.event(self.all_service_hash,word)
                return
            if api==1001:
                n=self.price_reads;require(n<4,'TOO_MANY_FX_PRICES');self.price_reads+=1
                symbol=text(self,m.reg_read(x.UC_X86_REG_RDX));frame=m.reg_read(x.UC_X86_REG_R8)&0xffffffff;shift=m.reg_read(x.UC_X86_REG_R9)&0xffffffff
                value=[2.,3.,4.,5.][n];raw=struct.pack('<d',value)
                m.mem_write(self.base+self.cfg['slot'],raw);m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'))
                for word in [cx.currency.entry_check.text_hash(symbol),frame,shift,cx.currency.bits(value)]:self.fx_price_hash=cx.event(self.fx_price_hash,word)
                self.fx_service_hash=cx.event(self.fx_service_hash,11);self.all_service_hash=cx.event(self.all_service_hash,11);return
            before=len(self.calls);result=super().call(m,address,size,user)
            for kind in self.calls[before:]:self.all_service_hash=cx.event(self.all_service_hash,100+kind)
            return result
        def run(self,row):
            self.index=row['index'];self.case=c=chain.context(row);self.fx=fixture(row,len(self.ctx_cfg['starts']))
            self.mode=-1;self.calls=[];self.atr=[];self.digit_calls=self.point_calls=0;self.api_counts={};self.error=0
            self.account_reads=self.price_reads=self.prep_calls=0;self.loaded=None
            self.fx_service_hash=self.fx_price_hash=self.all_service_hash=0xcbf29ce484222325
            self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x;self.phase='idle'
            for region,raw in self.regions:
                if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
            for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
            for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
            m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
            for n,k,off in full.legacy.fields(full.legacy.INPUTS,bot):m.mem_write(self.base+off,struct.pack('<'+k,c[n]))
            scalar=full.scalar_extra if bot==1 else chain.scalar_extra
            for j,(_,k,off,*_) in enumerate(full.EXTRA):m.mem_write(self.base+off,struct.pack('<'+k,scalar(c['id'],j,k)))
            for _,k,off in full.legacy.fields(full.legacy.OUTPUTS,bot)+[(r[3],r[4],r[5]) for r in full.EXTRA]+full.TAIL:m.mem_write(self.base+off,bytes(struct.calcsize('<'+k)))
            array,prep_comment,tick,calendar=(0x62190,0x62480,0x67750,0x67790) if bot==1 else (0x6d180,0x6d578,0x74790,0x747d0)
            for off,size in [(array,36),(prep_comment,12),(tick,56),(calendar,32)]:m.mem_write(self.base+off,bytes(size))
            m.mem_write(self.base+self.cfg['symbol'],struct.pack('<IQ',0,self.string('XAUUSD')))
            m.mem_write(self.base+(0x622d0 if bot==1 else 0x6d308),struct.pack('<IQ',0,self.string('case'+str(c['id']))))
            if bot==1:
                m.mem_write(self.base+0x6a410,struct.pack('<i',5017));m.mem_write(self.base+0x6a478,struct.pack('<I',row['seed']));m.mem_write(self.base+0x6a5d0,bytes([row['hl']]))
                offsets=[0x6a5f0,0x6a708,0x6a710,0x6a718,0x6a720];names=['randomization','price_delta','stop_delta','target_delta','trail_delta']
            else:
                m.mem_write(self.base+0x1d6e78,struct.pack('<I',row['seed']));offsets=[0x1d6fd0,0x1d70e8,0x1d70f0,0x1d70f8,0x1d7100,0x1d7108,0x1d7110]
                names=['randomization','price_delta','stop_delta','target_delta','trail_delta','aux_delta','lock_delta'];m.mem_write(self.base+0x1d6f28,bytes([self.fx['alternate']]))
            for off,n in zip(offsets,names):m.mem_write(self.base+off,struct.pack('<d',row[n]))
            k=self.ctx_cfg;m.mem_write(self.base+k['keep'],bytes([self.fx['keep']]));m.mem_write(self.base+k['base_magic'],struct.pack('<i',self.fx['base_magic']))
            for off,value in [(k['prefix'],self.fx['prefix']),(k['comment'],self.fx['prior_comment']),
                              (cx.currency.CONFIG[bot]['suffix'],self.fx['suffix'])]:m.mem_write(self.base+off,struct.pack('<IQ',0,self.string(value)))
            m.mem_write(self.base+k['value'],struct.pack('<d',-987.5));top=0x50020000-0x100;m.mem_write(top,bytes(0x80));m.reg_write(x.UC_X86_REG_RSP,top)
            p=self.profiles[self.index];preloads=[hex(off) for off,_,_ in COMMON_PRELOADS[bot]]+p['immediate_load_rvas']+p['reaching_constant_definition_rvas']
            if bot==1:preloads+=['0x12f54'] if self.index==1 else ['0x14eb1'] if self.index==5 else []
            for off in preloads:
                i=self.instructions[self.base+int(off,16)];require(i.mnemonic in ['mov','movabs'],'BAD_PRELOAD');m.emu_start(i.address,i.address+i.size,count=1)
            self.phase='profile';self.written=set();self.stopped=False;self.after=self.base+k['stops'][self.index]+self.call_size
            m.emu_start(self.base+int(p['start_rva'],16),0x60000000,timeout=5000000,count=500000)
            require(self.stopped and self.prep_calls==1 and self.error==0 and self.loaded is not None,'SETUP_DID_NOT_COMPLETE')
            words=self.loaded+[self.value(off,k) for _,k,off in full.legacy.fields(full.legacy.OUTPUTS,bot)]
            words.extend(self.value(r[5],r[4]) for r in full.EXTRA);words.extend(self.value(off,k) for _,k,off in full.TAIL)
            desc=self.base+array;words.extend([struct.unpack('<i',m.mem_read(desc+8,4))[0],int(bool(struct.unpack('<H',m.mem_read(desc+2,2))[0]&16))])
            words.append(cx.currency.entry_check.text_hash(text(self,self.base+prep_comment)));words.extend(self.calls.count(k) for k in range(1,7 if bot==1 else 8))
            words.extend(self.value(off,k) for off,k in [(tick,'q'),(tick+8,'d'),(tick+16,'d')]);words.extend(self.value(calendar+j*4,'i') for j in range(8))
            h=0xcbf29ce484222325
            for kind in self.calls:h=cx.event(h,kind)
            words.append(h)
            if bot==1:words.append(self.calls.count(7))
            words.extend(self.atr);require(len(words)==len(chain.NAMES),'OLD_RESULT_WIDTH')
            reference=next(off for n,_,off in full.legacy.fields(full.legacy.INPUTS,bot) if n=='reference')
            words.extend([self.value(k['magic'],'i'),self.value(k['value'],'d'),self.value(reference,'d'),self.account_reads,self.price_reads,self.fx_price_hash,self.fx_service_hash,self.all_service_hash])
            return words,text(self,self.base+k['comment'])
    return Original
def identity(bot,chain):
    current=chain.identity();source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}StrategySetupCheck.mq5'
    current['sources_sha256']={p.relative_to(source).as_posix():sha(p) for p in cx.pub.closure(script,source)}
    helpers=[Path(__file__),Path(chain.__file__),Path(cx.__file__),ROOT/'cong-cu/kiem-doi-tien-bot-1-3.py',
             ROOT/'danh-gia-doc-lap/strategy-context-20261027-r1/native-account-conditions.json']
    current['helpers_sha256'].update({p.relative_to(ROOT).as_posix():sha(p) for p in helpers});current['tool_sha256']=sha(Path(__file__));return current
def parse(raw,magic,count,width):
    require(raw[:16]==struct.pack('<4i',magic,1,count,width),'RESULT_HEADER');record=struct.Struct('<2i'+'Q'*width);at=16;out=[]
    for _ in range(count):
        words=list(record.unpack_from(raw,at));at+=record.size;n=struct.unpack_from('<i',raw,at)[0];at+=4;require(0<=n<10000,'BAD_TEXT_SIZE')
        out.append(words+[raw[at:at+n*2].decode('utf-16-le')]);at+=n*2
    require(at==len(raw),'RESULT_SIZE');return out
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,40}',a.run),'BAD_RUN');chain,full,data=contract(a.bot);rows=data.cases();n=len(cx.CONFIG[a.bot]['starts']);current=identity(a.bot,chain)
    home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;names=chain.NAMES+EXTRA_NAMES;magic=0x53555030+a.bot;header=struct.pack('<4i',magic,1,len(rows),len(names));record=struct.Struct('<2i'+'Q'*len(names))
    if a.mode=='prepare':
        coverage=[]
        for index in range(n):
            fx=[fixture(row,n) for row in rows if row['index']==index];entry={key:sorted({r[key] for r in fx}) for key in ['keep','alternate','base_magic','currency']}
            require(entry['keep']==[0,1,255] and entry['base_magic']==[-2147483648,0,2147483647] and len(entry['currency'])==5,'CONTEXT_INPUT_COVERAGE')
            if a.bot==3:require(entry['alternate']==[0,255],'ALTERNATE_COVERAGE')
            coverage.append(dict(index=index,**entry))
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(data.encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),context_input_coverage=coverage,**SCOPE));print(json.dumps(dict(cases=len(rows),words=len(names))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==data.encode(rows),'IDENTITY_CHANGED')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');runner=original_class(a.bot,chain,full)();raw=bytearray(header)
        try:
            for row in rows:
                words,comment=runner.run(row);require(len(words)==len(names),'RESULT_WIDTH');raw+=record.pack(row['id'],1,*words)+cx.text_bytes(comment)
            report=dict(**current,cases=len(rows),profile_instructions=len(runner.prefix_covered),context_instructions=len(runner.context_covered),preparation_instructions=len(runner.covered),result_sha256=hashlib.sha256(raw).hexdigest(),**SCOPE)
            if a.bot==3:report.update(nan=runner.nan.report(),cpu_probe=runner.cpu_probe)
        finally:
            if a.bot==3:runner.close()
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',report);print(json.dumps(dict(cases=len(rows),profile=report['profile_instructions'],context=report['context_instructions'],preparation=report['preparation_instructions'])));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');require(not(folder/'mql5-results.bin').exists(),'RESULT_EXISTS');mt=chain.MT;script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}StrategySetupCheck.mq5'
        receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==script and build['errors']==build['warnings']==0 and build['floating_point_dividers_check_requested'],'BUILD_NOT_CLEAN')
        for key,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/key)==build['sources_sha256'][key]==digest,'BUILD_SOURCE_DIFFERS '+key)
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
        files=mt/f'MQL5/Files/bot{a.bot}-strategy-setup'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/f'b{a.bot}-setup-{a.run}.set';ini=mt/f'b{a.bot}-setup-{a.run}.ini'
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-'+str(a.bot)+'\\Bot'+str(a.bot)+'StrategySetupCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for key in ['mql5-results.bin','script-status.bin']:
            with (folder/key).open('xb') as f:f.write((files/key).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for key in ['original-run.json','mql5-run.json']:
        report=json.loads((folder/key).read_text());require(all(report[k]==v for k,v in current.items()) and report['result_sha256']==sha(folder/key.replace('-run.json','-results.bin')),'RUN_CHANGED')
    native=parse((folder/'original-results.bin').read_bytes(),magic,len(rows),len(names));actual=parse((folder/'mql5-results.bin').read_bytes(),magic,len(rows),len(names));failures=[]
    for row,left,right in zip(rows,native,actual):
        if left!=right:failures.append(dict(id=row['id'],index=row['index'],differences={k:[x,y] for k,x,y in zip(['id','returned']+names+['context.comment'],left,right) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:20],values_per_case=len(names),**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report,ensure_ascii=False));raise SystemExit(bool(failures))
if __name__=='__main__':main()
