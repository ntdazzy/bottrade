"""Execute the bot3 scalar profile prefix followed by full preparation.

Both native bodies share one emulator and memory state. The intervening
symbol/currency/comment work is excluded; common inputs and MT5 replies
are supplied identically to the MQL5 check.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
full=module('profile_prep3_full',HOME/'tests/check-preparation-full.py')
runtime=module('profile_prep3_runtime',HOME/'tests/check-runtime-profile.py')
data=module('profile_prep3_cases',HOME/'tests/runtime_profile_cases.py')
sha,require,save,MT=full.sha,full.require,full.save,full.MT
SOURCE=HOME/'source/MQL5';SCRIPT='Scripts/bot-cua-toi-3/Bot3ProfilePreparationCheck.mq5'
NAMES=['profile.'+n for n,_,_ in runtime.FIELDS]+full.FIELDS[2:]+['tick.time','tick.bid','tick.ask']
NAMES+=['calendar.'+n for n in ['year','mon','day','hour','min','sec','day_of_week','day_of_year']]+['call_order_hash','ATR.frame','ATR.period','ATR.symbol_hash']
MAGIC=0x50535033;RESULT=struct.Struct('<2i'+'Q'*len(NAMES));require(len(NAMES)==124,'FIELD_COUNT')
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
 native_profile_and_preparation_bodies_executed=True,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Valid indices 0..8. Both captured profile prefix and preparation body run in the same emulator; common inputs and SDK replies are supplied.',
 'Only two-NaN scalar SSE arithmetic is delegated to measured CPU instructions. Original bytes stay unchanged; CPU status flags are not compared.',
 'The original symbol/currency/comment work between the blocks, seed initialization, full dispatcher/EA, allocation failures and real broker behavior remain outside this comparison.']

def context(row):
    c=full.legacy.base_case(3);c.update(id=row['id'],sample=2000.+row['id']*.5,
      point=.001 if row['id']%2 else .01,digits=3 if row['id']%2 else 2,virtual_expiration=row['id']%2)
    return c

def scalar_extra(case_id,j,kind):
    return .5+case_id*.125+j*.25 if kind=='d' else (case_id+j)%256 if kind=='B' else (1 if case_id%2==0 else -1)*(case_id+j+1)

class Original(full.Original):
    def __init__(self):
        super().__init__();m=self.m
        raw=bytes(m.mem_read(self.base+runtime.CODE_BEGIN,runtime.CODE_END-runtime.CODE_BEGIN));require(hashlib.sha256(raw).hexdigest()==runtime.CODE_SHA,'PREFIX_BYTES_CHANGED')
        import capstone
        md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64)
        self.instructions={i.address:i for i in md.disasm(raw,self.base+runtime.CODE_BEGIN)}
        prep_bytes=bytes(m.mem_read(self.base+0xe0c0,0xef3f-0xe0c0))
        prep_instructions=list(md.disasm(prep_bytes,self.base+0xe0c0))
        self.profiles={p['index']:p for p in json.loads(runtime.ENTRY.read_text())['profiles']}
        self.stops={p['index']:int(p['stop_before_rva'],16) for p in json.loads(runtime.POSITIVE.read_text())['rows']}
        self.required={self.base+off+i for n,k,off in runtime.FIELDS if n!='random_seed' for i in range(struct.calcsize('<'+k))}
        cpu=module('profile_prep3_cpu',ROOT/'cong-cu/doi-chieu-nan-quan-ly.py');self.cpu=cpu.CpuFixture()
        self.cpu_probe=cpu.verify_probe(self.cpu,'bd633e156fa141d81718ecd96894b0f3d3ce403d430dff10d4c66f0d4dff5c7f')
        analysis={'functions':[{'instructions':[dict(rva=hex(i.address-self.base),mnemonic=i.mnemonic,bytes=i.bytes.hex()) for i in list(self.instructions.values())+prep_instructions]}]}
        self.nan=cpu.BothNaN(self,analysis,self.cpu)
        self.phase='idle';self.prefix_covered=set()
        m.hook_add(self.uc.UC_HOOK_CODE,self.prefix_visit,begin=self.base+runtime.CODE_BEGIN,end=self.base+runtime.CODE_END)
        m.hook_add(self.uc.UC_HOOK_MEM_WRITE,self.store)
    def close(self):self.cpu.close()
    def visit(self,m,address,size,user):self.covered.add(address-self.base)
    def prefix_visit(self,m,address,size,user):
        if self.phase!='profile':return
        if address==self.base+self.stops[self.index]:self.stopped=True;m.emu_stop();return
        require(address in self.instructions and self.instructions[address].mnemonic!='call','LEFT_PROFILE_PREFIX')
        self.prefix_covered.add(address-self.base)
    def store(self,m,access,address,size,value,user):
        if self.phase=='profile':self.written.update(range(address,address+size))
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api in full.API_ORDER:self.calls.append(full.API_ORDER.index(api)+1)
        if api==10:
            sp=m.reg_read(x.UC_X86_REG_RSP);require(m.reg_read(x.UC_X86_REG_RDX)==0x53 and m.reg_read(x.UC_X86_REG_R8)==3,'ATR_DISPATCH_DIFFERS')
            frame=struct.unpack('<i',m.mem_read(sp+0x38,4))[0];period=struct.unpack('<i',m.mem_read(sp+0x48,4))[0]
            desc=struct.unpack('<Q',m.mem_read(sp+0x28,8))[0];ptr=struct.unpack('<Q',m.mem_read(desc+4,8))[0]
            n=struct.unpack('<I',m.mem_read(ptr-4,4))[0];require(n<100,'ATR_SYMBOL_LENGTH')
            text=bytes(m.mem_read(ptr,n*2)).decode('utf-16-le');self.atr=[frame&full.MASK,period&full.MASK,full.pre.entry.text_hash(text)]
            m.reg_write(x.UC_X86_REG_RAX,17);return
        if api==11:
            n=2+self.case['id']%2;desc=self.base+0x6d180;sp=m.reg_read(x.UC_X86_REG_RSP)
            require(struct.unpack('<I',m.mem_read(sp+0x28,4))[0]==100 and struct.unpack('<Q',m.mem_read(sp+0x30,8))[0]==desc,'COPY_ARGUMENTS_DIFFERS')
            m.mem_write(desc+2,struct.pack('<H',1));m.mem_write(desc+8,struct.pack('<I',n));m.mem_write(desc+28,struct.pack('<Q',0x70100000))
            m.mem_write(0x70100000,struct.pack('<'+'d'*n,*[self.case['sample']+250.*j for j in range(n)]));m.reg_write(x.UC_X86_REG_RAX,n);return
        if api==13:
            ptr=m.reg_read(x.UC_X86_REG_RDX)
            if ptr:m.mem_write(ptr,bytes(32))
        return full.legacy.Original.call(self,m,address,size,user)
    def run(self,row):
        self.index=row['index'];self.case=c=context(row);self.calls=[];self.atr=[];self.phase='idle'
        self.error=0;self.api_counts={};self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        for n,k,off in full.legacy.fields(full.legacy.INPUTS,3):m.mem_write(self.base+off,struct.pack('<'+k,c[n]))
        for j,(_,k,off,*_) in enumerate(full.EXTRA):m.mem_write(self.base+off,struct.pack('<'+k,scalar_extra(c['id'],j,k)))
        for _,k,off in full.legacy.fields(full.legacy.OUTPUTS,3)+[(r[3],r[4],r[5]) for r in full.EXTRA]+full.TAIL:m.mem_write(self.base+off,bytes(struct.calcsize('<'+k)))
        for off,size in [(0x6d180,36),(0x6d578,12),(0x74790,56),(0x747d0,32)]:m.mem_write(self.base+off,bytes(size))
        m.mem_write(self.base+self.cfg['symbol'],struct.pack('<IQ',0,self.string('XAUUSD')))
        m.mem_write(self.base+0x6d308,struct.pack('<IQ',0,self.string('case'+str(c['id']))))
        m.mem_write(self.base+0x1d6e78,struct.pack('<I',row['seed']))
        for off,n in zip([0x1d6fd0,0x1d70e8,0x1d70f0,0x1d70f8,0x1d7100,0x1d7108,0x1d7110],['randomization','price_delta','stop_delta','target_delta','trail_delta','aux_delta','lock_delta']):m.mem_write(self.base+off,struct.pack('<d',row[n]))
        top=0x50020000-0x108;m.reg_write(x.UC_X86_REG_RSP,top);p=self.profiles[self.index]
        for off in p['immediate_load_rvas']+p['reaching_constant_definition_rvas']:
            i=self.instructions[self.base+int(off,16)];require(i.mnemonic!='call','PRELOAD_IS_CALL');m.emu_start(i.address,i.address+i.size,count=1)
        self.phase='profile';self.written=set();self.stopped=False
        m.emu_start(self.base+int(p['start_rva'],16),0x60000000,timeout=3000000,count=20000)
        require(self.stopped and self.required.issubset(self.written),'PREFIX_INCOMPLETE')
        words=[self.value(off,k) for _,k,off in runtime.FIELDS]
        self.phase='preparation';m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_RCX,self.index)
        m.emu_start(self.base+0xe0c0,0x60000000,timeout=3000000,count=100000)
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000 and not self.error,'PREPARATION_DID_NOT_RETURN')
        words.extend(self.value(off,k) for _,k,off in full.legacy.fields(full.legacy.OUTPUTS,3))
        words.extend(self.value(r[5],r[4]) for r in full.EXTRA);words.extend(self.value(off,k) for _,k,off in full.TAIL)
        desc=self.base+0x6d180;words.extend([struct.unpack('<i',m.mem_read(desc+8,4))[0],int(bool(struct.unpack('<H',m.mem_read(desc+2,2))[0]&16))])
        ptr=struct.unpack('<Q',m.mem_read(self.base+0x6d57c,8))[0];n=struct.unpack('<I',m.mem_read(ptr-4,4))[0] if ptr else 0;require(n<100,'COMMENT_LENGTH')
        text=bytes(m.mem_read(ptr,n*2)).decode('utf-16-le') if ptr else '';words.append(full.pre.entry.text_hash(text));words.extend(self.calls.count(k) for k in range(1,8))
        words.extend(self.value(off,k) for off,k in [(0x74790,'q'),(0x74798,'d'),(0x747a0,'d')]);words.extend(self.value(0x747d0+j*4,'i') for j in range(8))
        h=0xcbf29ce484222325
        for kind in self.calls:
            for byte in struct.pack('<Q',kind):h=((h^byte)*0x100000001b3)&full.MASK
        words.extend([h,*self.atr]);require(len(words)==len(NAMES),'RESULT_WIDTH');return RESULT.pack(row['id'],1,*words)

def identity():
    helpers=[Path(__file__),HOME/'tests/check-preparation-full.py',HOME/'tests/check-runtime-profile.py',HOME/'tests/runtime_profile_cases.py',runtime.POSITIVE,runtime.ENTRY,
      ROOT/'cong-cu/doi-chieu-nan-quan-ly.py',HOME/'tests/check-management-prelude.py',HOME/'tests/check-nan-cpu.py',HOME/'bang-chung/kiem-quan-ly-vi-the/cpu-nan-20261025-r1/probe.json',
      ROOT/'cong-cu/kiem-dieu-chinh-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',ROOT/'bot-cua-toi-1/tests/check-management-prelude.py',
      ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py']
    return dict(original_ex5_sha256=full.pre.validation.original_hash(3),tool_sha256=sha(Path(__file__)),
      sources_sha256={p.relative_to(SOURCE).as_posix():sha(p) for p in full.pub.closure(SOURCE/SCRIPT,SOURCE)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=data.cases();current=identity();header=struct.pack('<4i',MAGIC,1,len(rows),len(NAMES))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(data.encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),words=len(NAMES))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==data.encode(rows),'IDENTITY_OR_INPUTS_CHANGED')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');runner=Original();raw=bytearray(header)
        try:
            for c in rows:raw+=runner.run(c)
            record=dict(**current,cases=len(rows),profile_instructions=len(runner.prefix_covered),preparation_instructions=len(runner.covered),nan=runner.nan.report(),cpu_probe=runner.cpu_probe,result_sha256=hashlib.sha256(raw).hexdigest(),**SCOPE)
        finally:runner.close()
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',record);print(json.dumps(dict(cases=len(rows),profile_instructions=record['profile_instructions'],preparation_instructions=record['preparation_instructions'],delegated_nan=record['nan']['delegated_instructions'])));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==digest,'BUILD_SOURCE_DIFFERS '+n)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-profile-preparation'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b3-profile-prep-'+a.run+'.set');ini=MT/('b3-profile-prep-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3ProfilePreparationCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for n in ['original-run.json','mql5-run.json']:
        r=json.loads((folder/n).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/n.replace('-run.json','-results.bin')),'RUN_IDENTITY_CHANGED')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();require(native[:16]==actual[:16]==header and len(native)==len(actual)==16+len(rows)*RESULT.size,'RESULT_SIZE')
    failures=[]
    for c in rows:
        off=16+c['id']*RESULT.size;n=RESULT.unpack_from(native,off);r=RESULT.unpack_from(actual,off)
        if n!=r:failures.append(dict(id=c['id'],differences={k:[x,y] for k,x,y in zip(['id','returned']+NAMES,n,r) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:20],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failures))
if __name__=='__main__':main()
