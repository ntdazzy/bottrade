"""Compare profile loading followed by preparation in the same native emulator.

Both original instruction bodies run, with explicit native constant preloads.
The scalar prefix stops before the original symbol/currency/comment work; the
same supplied common inputs and MT5 replies then feed the complete preparation.
"""
import argparse,hashlib,json,re,shutil,struct,subprocess
from pathlib import Path
import importlib.util
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
full=module('profile_prep_full',HOME/'tests/check-preparation-full.py')
data=module('profile_prep_data',HOME/'tests/runtime_profile_cases.py')
profile=module('profile_prep_contract',HOME/'tests/check-runtime-profile.py')
sha,require,save,MT=full.sha,full.require,full.save,full.MT
SOURCE=HOME/'source/MQL5';SCRIPT='Scripts/bot-cua-toi-1/Bot1ProfilePreparationCheck.mq5'
ANALYSIS=HOME/'phan-tich/chuong-trinh-chinh/profile-parameters-20261026-r1'
NATIVE_PROFILE=ANALYSIS/'b1-full-inputs-20261027-r1/native-profiles.json'
ENTRY=HOME/'phan-tich/luot-20261023-data-v2/kiem-tham-so-goc.json'
PROFILE_EXTRA=[('indicator_period','i',0x621c4),('indicator_day','B',0x621c8),
 ('native_622a8','B',0x622a8),('native_622ec','i',0x622ec),('native_622f0','B',0x622f0),('native_62360','i',0x62360)]
OLD_FIELDS={n:(k,off) for n,k,off in full.legacy.fields(full.legacy.INPUTS,1)}
PROFILE_FIELDS=[(n,*OLD_FIELDS[n]) for n,_ in profile.FIELDS]+PROFILE_EXTRA
NAMES=['profile.random_seed']+['profile.'+n for n,_,_ in PROFILE_FIELDS]+full.FIELDS+['ATR.frame','ATR.period','ATR.symbol_hash']
MAGIC=0x50535031;RESULT=struct.Struct('<2i'+'Q'*len(NAMES))
require(len(NAMES)==119,'RESULT_FIELD_COUNT')
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
 native_profile_and_preparation_bodies_executed=True,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Valid indices 0..7. Both captured scalar profile prefix and full preparation execute in the same emulator; common inputs and MT5 replies are supplied.',
 'The original currency/symbol/comment work between these blocks is excluded; no claim about the complete dispatcher, seed initialization, EA or real broker.',
 '432 input cases, successful string allocation and valid arrays. Error-stop proof remains in the separate preparation tests.']

def context(row):
    c=full.legacy.base_case(1)
    c.update(id=row['id'],sample=2000.+row['id']*.5,point=.001 if row['id']%2 else .01,
             digits=3 if row['id']%2 else 2,virtual_expiration=row['id']%2)
    return c

class Original(full.Original):
    def __init__(self):
        super().__init__()
        report=json.loads(NATIVE_PROFILE.read_text());require(report['function_sha256']=='f5edd0f5e9033ddddb289a3419406c06292ce22bff197bea6d10acea1756c721','PREFIX_IDENTITY')
        lo,hi=int(report['function_begin'],16),int(report['function_end_exclusive'],16)
        raw=bytes(self.m.mem_read(self.base+lo,hi-lo));require(hashlib.sha256(raw).hexdigest()==report['function_sha256'],'PREFIX_BYTES_CHANGED')
        import capstone
        md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
        self.instructions={i.address:i for i in md.disasm(raw,self.base+lo)}
        self.profiles={p['index']:p for p in json.loads(ENTRY.read_text())['profiles']}
        self.stops={p['index']:int(p['stop_details']['rva'],16) for p in report['rows']}
        self.required={self.base+off+i for _,kind,off in PROFILE_FIELDS for i in range(struct.calcsize('<'+kind))}
        self.prefix_covered=set();self.phase='idle'
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.prefix_visit,begin=self.base+lo,end=self.base+hi)
        self.m.hook_add(self.uc.UC_HOOK_MEM_WRITE,self.store)
    def visit(self,m,address,size,user):
        self.covered.add(address-self.base)
    def prefix_visit(self,m,address,size,user):
        if self.phase!='profile':return
        if address==self.base+self.stops[self.index]:self.stopped=True;m.emu_stop();return
        require(address in self.instructions and self.instructions[address].mnemonic!='call','LEFT_PROFILE_PREFIX')
        self.prefix_covered.add(address-self.base)
    def store(self,m,access,address,size,value,user):
        if self.phase=='profile':self.written.update(range(address,address+size))
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api==10 and m.reg_read(x.UC_X86_REG_RDX)==0x53:
            self.calls.append(1);sp=m.reg_read(x.UC_X86_REG_RSP)
            frame=struct.unpack('<i',m.mem_read(sp+0x38,4))[0];period=struct.unpack('<i',m.mem_read(sp+0x48,4))[0]
            desc=struct.unpack('<Q',m.mem_read(sp+0x28,8))[0]
            ptr=struct.unpack('<Q',m.mem_read(desc+4,8))[0];n=struct.unpack('<I',m.mem_read(ptr-4,4))[0]
            require(n<100,'ATR_SYMBOL_LENGTH');text=bytes(m.mem_read(ptr,n*2)).decode('utf-16-le')
            self.atr=[frame&full.MASK,period&full.MASK,full.pre.entry.text_hash(text)]
            m.reg_write(x.UC_X86_REG_RAX,17);return
        if api==11:
            self.calls.append(2);n=2+self.case['id']%2;desc=self.base+0x62190
            sp=m.reg_read(x.UC_X86_REG_RSP)
            require(struct.unpack('<I',m.mem_read(sp+0x28,4))[0]==100 and struct.unpack('<Q',m.mem_read(sp+0x30,8))[0]==desc,'BAD_COPY_ARGUMENTS')
            m.mem_write(desc+2,struct.pack('<H',1));m.mem_write(desc+8,struct.pack('<I',n));m.mem_write(desc+28,struct.pack('<Q',0x70100000))
            m.mem_write(0x70100000,struct.pack('<'+'d'*n,*[self.case['sample']+250.*j for j in range(n)]))
            m.reg_write(x.UC_X86_REG_RAX,n);return
        return super().call(m,address,size,user)
    def run(self,row):
        self.index=row['index'];self.case=c=context(row);self.mode=-1;self.calls=[];self.atr=[];self.digit_calls=self.point_calls=0
        self.error=0;self.api_counts={};self.cursor=0x70001000;self.allocs=self.frees=0;m,x=self.m,self.x
        self.phase='idle'
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        for n,k,off in full.legacy.fields(full.legacy.INPUTS,1):m.mem_write(self.base+off,struct.pack('<'+k,c[n]))
        for j,(_,k,off,*_) in enumerate(full.EXTRA):m.mem_write(self.base+off,struct.pack('<'+k,full.scalar_extra(c['id'],j,k)))
        for _,k,off in full.legacy.fields(full.legacy.OUTPUTS,1)+[(r[3],r[4],r[5]) for r in full.EXTRA]+full.TAIL:
            m.mem_write(self.base+off,bytes(struct.calcsize('<'+k)))
        for off,size in [(0x62190,36),(0x62480,12),(0x67750,56),(0x67790,32)]:m.mem_write(self.base+off,bytes(size))
        m.mem_write(self.base+0x6a410,struct.pack('<i',5017))
        m.mem_write(self.base+self.cfg['symbol'],struct.pack('<IQ',0,self.string('XAUUSD')))
        m.mem_write(self.base+0x622d0,struct.pack('<IQ',0,self.string('case'+str(c['id']))))
        m.mem_write(self.base+0x6a478,struct.pack('<I',row['seed']));m.mem_write(self.base+0x6a5d0,bytes([row['hl']]))
        for off,n in zip([0x6a5f0,0x6a708,0x6a710,0x6a718,0x6a720],['randomization','price_delta','stop_delta','target_delta','trail_delta']):m.mem_write(self.base+off,struct.pack('<d',row[n]))
        top=0x50020000-0x108;m.reg_write(x.UC_X86_REG_RSP,top)
        p=self.profiles[self.index];preloads=p['immediate_load_rvas']+p['reaching_constant_definition_rvas']
        preloads+=['0x12f54'] if self.index==1 else ['0x14eb1'] if self.index==5 else []
        for off in preloads:
            i=self.instructions[self.base+int(off,16)];require(i.mnemonic in ['mov','movabs'],'UNPROVEN_PRELOAD')
            m.emu_start(i.address,i.address+i.size,count=1)
        self.phase='profile';self.written=set();self.stopped=False
        m.emu_start(self.base+int(p['start_rva'],16),0x60000000,timeout=3000000,count=20000)
        require(self.stopped and self.required.issubset(self.written),'PREFIX_INCOMPLETE')
        words=[self.value(0x6a478,'I')]+[self.value(off,k) for _,k,off in PROFILE_FIELDS]
        self.phase='preparation';m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);m.reg_write(x.UC_X86_REG_RCX,self.index)
        m.emu_start(self.base+0x7500,0x60000000,timeout=3000000,count=100000)
        require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000 and not self.error,'PREPARATION_DID_NOT_RETURN')
        words.extend(self.value(off,k) for _,k,off in full.legacy.fields(full.legacy.OUTPUTS,1))
        words.extend(self.value(r[5],r[4]) for r in full.EXTRA);words.extend(self.value(off,k) for _,k,off in full.TAIL)
        desc=self.base+0x62190;words.extend([struct.unpack('<i',m.mem_read(desc+8,4))[0],int(bool(struct.unpack('<H',m.mem_read(desc+2,2))[0]&16))])
        ptr=struct.unpack('<Q',m.mem_read(self.base+0x62484,8))[0];n=struct.unpack('<I',m.mem_read(ptr-4,4))[0] if ptr else 0
        require(n<100,'COMMENT_LENGTH');text=bytes(m.mem_read(ptr,n*2)).decode('utf-16-le') if ptr else ''
        words.append(full.pre.entry.text_hash(text));words.extend(self.calls.count(k) for k in range(1,7))
        words.extend(self.value(off,k) for off,k in [(0x67750,'q'),(0x67758,'d'),(0x67760,'d')]);words.extend(self.value(0x67790+i*4,'i') for i in range(8))
        h=0xcbf29ce484222325
        for kind in self.calls:
            for byte in struct.pack('<Q',kind):h=((h^byte)*0x100000001b3)&full.MASK
        words.extend([h,self.calls.count(7),*self.atr]);require(len(words)==len(NAMES),'RESULT_WIDTH')
        return RESULT.pack(row['id'],1,*words)

def identity():
    helpers=[Path(__file__),HOME/'tests/check-preparation-full.py',HOME/'tests/check-runtime-profile.py',HOME/'tests/runtime_profile_cases.py',NATIVE_PROFILE,ENTRY,
      ROOT/'cong-cu/kiem-dieu-chinh-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',HOME/'tests/check-management-prelude.py',
      ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py']
    return dict(original_ex5_sha256=full.pre.validation.original_hash(1),tool_sha256=sha(Path(__file__)),
      sources_sha256={p.relative_to(SOURCE).as_posix():sha(p) for p in full.pub.closure(SOURCE/SCRIPT,SOURCE)},
      helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=data.cases();current=identity();header=struct.pack('<4i',MAGIC,1,len(rows),len(NAMES))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(data.encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),words=len(NAMES))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==data.encode(rows),'IDENTITY_OR_INPUTS_CHANGED')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');runner=Original();raw=bytearray(header)
        for c in rows:raw+=runner.run(c)
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',dict(**current,cases=len(rows),profile_instructions=len(runner.prefix_covered),preparation_instructions=len(runner.covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),profile_instructions=len(runner.prefix_covered),preparation_instructions=len(runner.covered))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==digest,'BUILD_SOURCE_DIFFERS '+n)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot1-profile-preparation'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b1-profile-prep-'+a.run+'.set');ini=MT/('b1-profile-prep-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ProfilePreparationCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
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
