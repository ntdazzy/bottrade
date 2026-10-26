"""Compare complete scalar profile loading with the captured assignment blocks.
prepare/original/mql5(--build)/compare RUN; private script, no terminal trade calls.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent;MASK=(1<<64)-1
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
pre=module('runtime_profile_pre',HOME/'tests/check-management-prelude.py')
data=module('runtime_profile_inputs',HOME/'tests/runtime_profile_cases.py')
pub=module('runtime_profile_pub',ROOT/'cong-cu/kiem-ban-git-quan-ly.py')
sha,require,save=pre.sha,pre.require,pre.save
MT=(ROOT.parent/'.local/mt5-bot3-thread-20261025').resolve()
SCRIPT='Scripts/bot-cua-toi-3/Bot3RuntimeProfileCheck.mq5'
ANALYSIS=HOME/'phan-tich/chuong-trinh-chinh/profile-parameters-20261026-r1'
BASELINE=HOME/'bang-chung/kiem-dieu-chinh/settings-20261023-r2/native-profiles.json'
ENTRY=HOME/'phan-tich/luot-20261023-data/kiem-tham-so-goc.json'
POSITIVE=ANALYSIS/'expressions-positive/native-profiles.json';ZERO=ANALYSIS/'expressions-zero/native-profiles.json'
CODE_BEGIN,CODE_END=(int(json.loads(POSITIVE.read_text())[k],16) for k in ['function_begin','function_end_exclusive'])
CODE_SHA=json.loads(POSITIVE.read_text())['function_sha256']
PROFILE_FIELDS=json.loads(BASELINE.read_text())['fields']
FIELDS=[('random_seed','I',0x1d6e78),('native_6d324','i',0x6d324),('native_6d3c0','i',0x6d3c0)]+PROFILE_FIELDS+[
 ('indicator_period','i',0x6d170),('indicator_timeframe','i',0x6d174),('native_6d2e0','i',0x6d2e0),('management_timeframe','i',0x6d324),('native_6d2e4','i',0x6d2e4)]
require(len(FIELDS)==33,'FIELD_COUNT_DIFFERS')
SCOPE=dict(whole_manager_complete=False,whole_bot_complete=False,full_ea=False,native_scalar_profile_executed=True,
 terminal_replies_supplied=False,child_helpers_intercepted=False,original_ex5_changed=False)
LIMITS=['Valid indices0..8; scalar profile loading only, before symbol/currency/magic selection and strategy preparation/main.',
 'Full arithmetic and uint32 random state run; only both-NaN SSE results are delegated to measured CPU instructions, not the whole original on CPU.',
 'MXCSR status flags, allocator/stack failures, initialization of the random seed, strategy selection and complete EAs are outside this comparison.']
def identity():
    base=HOME/'source/MQL5';names=sorted(p.relative_to(base.resolve()).as_posix() for p in pub.closure(base/SCRIPT,base))
    helpers=[Path(__file__),HOME/'tests/runtime_profile_cases.py',BASELINE,ENTRY,POSITIVE,ZERO,
      ROOT/'cong-cu/doi-chieu-nan-quan-ly.py',HOME/'tests/check-management-prelude.py',
      HOME/'tests/check-nan-cpu.py',HOME/'bang-chung/kiem-quan-ly-vi-the/cpu-nan-20261025-r1/probe.json',
      ROOT/'bot-cua-toi-1/tests/check-management-prelude.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',
      ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',
      ROOT/'claude-thuc-hien/bot3-runtime-profile-20261026-r1/TASK.md',ROOT/'claude-thuc-hien/bot3-runtime-profile-20261026-r1/functional-constants.json',ROOT/'claude-thuc-hien/bot3-runtime-profile-check-20261026-r1/TASK.md']
    return dict(original_ex5_sha256=pre.validation.original_hash(3),tool_sha256=sha(Path(__file__)),native_profile_function_sha256=CODE_SHA,
      helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers},sources_sha256={n:sha(base/n) for n in names})
class Original(pre.entry.Original):
    def __init__(self):
        super().__init__(3);require(self.base==0x17156250000,'CAPTURE_BASE_DIFFERS');m=self.m
        raw=bytes(m.mem_read(self.base+CODE_BEGIN,CODE_END-CODE_BEGIN));require(hashlib.sha256(raw).hexdigest()==CODE_SHA,'FUNCTION_BYTES_DIFFER')
        import capstone
        decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);self.instructions={i.address:i for i in decoder.disasm(raw,self.base+CODE_BEGIN)}
        self.starts={r['index']:int(r['start_rva'],16) for r in json.loads(ENTRY.read_text())['profiles']}
        self.stops={r['index']:int(r['stop_before_rva'],16) for r in json.loads(POSITIVE.read_text())['rows']}
        self.preloads={r['index']:r['immediate_load_rvas']+r['reaching_constant_definition_rvas'] for r in json.loads(ENTRY.read_text())['profiles']}
        self.allowed={}
        for report in [POSITIVE,ZERO]:
            for row in json.loads(report.read_text())['rows']:
                self.allowed.setdefault(row['index'],set()).update(self.base+int(w['rva'],16)+i for w in row['writes'] for i in range(w['size']))
        self.required={self.base+off+i for name,kind,off in FIELDS if name!='random_seed' for i in range(struct.calcsize('<'+kind))}
        cpu_module=module('runtime_profile_cpu',ROOT/'cong-cu/doi-chieu-nan-quan-ly.py');self.cpu=cpu_module.CpuFixture();self.cpu_probe=cpu_module.verify_probe(self.cpu,'bd633e156fa141d81718ecd96894b0f3d3ce403d430dff10d4c66f0d4dff5c7f')
        analysis={'functions':[{'instructions':[dict(rva=hex(i.address-self.base),mnemonic=i.mnemonic,bytes=i.bytes.hex()) for i in self.instructions.values()]}]}
        self.nan=cpu_module.BothNaN(self,analysis,self.cpu);self.covered=set()
        m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+CODE_BEGIN,end=self.base+CODE_END)
        m.hook_add(self.uc.UC_HOOK_MEM_WRITE,self.store);self.collecting=False
    def close(self):self.cpu.close()
    def visit(self,m,address,size,user):
        if not self.collecting:return
        if address==self.base+self.stops[self.case['index']]:self.stopped=True;m.emu_stop();return
        require(address in self.instructions and self.instructions[address].mnemonic!='call','LEFT_SCALAR_PROFILE');self.covered.add(address-self.base)
    def store(self,m,access,address,size,value,user):
        if not self.collecting:return
        if not any(r.get('kind')=='mutable_program_data' and r['base']<=address and address+size<=r['base']+len(raw) for r,raw in self.regions):return
        byte_range=set(range(address,address+size));self.written.update(byte_range)
        if not byte_range.issubset(self.allowed[self.case['index']]):self.unexpected.append([hex(address-self.base),size])
    def run(self,c):
        self.case=c;self.collecting=False;self.written=set();self.unexpected=[];self.stopped=False;m,x=self.m,self.x
        for r,raw in self.regions:
            if r.get('kind')=='mutable_program_data':m.mem_write(r['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
        m.reg_write(x.UC_X86_REG_RSP,0x50010000);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        controls=['randomization','price_delta','stop_delta','target_delta','trail_delta','aux_delta','lock_delta']
        for off,name in zip([0x1d6fd0,0x1d70e8,0x1d70f0,0x1d70f8,0x1d7100,0x1d7108,0x1d7110],controls):m.mem_write(self.base+off,struct.pack('<d',c[name]))
        m.mem_write(self.base+0x1d6e78,struct.pack('<I',c['seed']))
        for off in self.preloads[c['index']]:
            i=self.instructions[self.base+int(off,16)];m.emu_start(i.address,i.address+i.size,count=1)
        self.collecting=True
        try:m.emu_start(self.base+self.starts[c['index']],0x60000000,timeout=3000000,count=20000)
        finally:self.collecting=False
        require(self.stopped and self.required.issubset(self.written),'PROFILE_INCOMPLETE')
        words=[]
        for name,kind,off in FIELDS:
            raw=m.mem_read(self.base+off,struct.calcsize('<'+kind));value=struct.unpack('<Q' if kind=='d' else '<'+kind,raw)[0];words.append(value&MASK)
        return data.RESULT.pack(c['id'],0,int(bool(self.unexpected)),*words)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=data.cases();current=identity();header=struct.pack('<3i',data.MAGIC,1,len(rows))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(data.encode(rows));save(folder/'cases.json',rows)
        for group,base in [('sources_sha256',HOME/'source/MQL5'),('helpers_sha256',ROOT)]:
            for name in current[group]:
                target=folder/'tested-sources'/group/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(base/name,target)
        save(folder/'baseline.json',dict(**current,cases=len(rows),input_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==data.encode(rows),'IDENTITY_OR_INPUTS_DIFFER')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');runner=Original();result=bytearray(header)
        try:
            for c in rows:result+=runner.run(c)
            record=dict(**current,cases=len(rows),instructions=len(runner.covered),result_sha256=hashlib.sha256(result).hexdigest(),cpu_probe=runner.cpu_probe,nan=runner.nan.report(),**SCOPE)
        finally:runner.close()
        (folder/'original-results.bin').write_bytes(result);save(folder/'original-run.json',record);print(json.dumps(dict(cases=len(rows),instructions=record['instructions'],nan=record['nan'])));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/name)==build['sources_sha256'][name]==digest,'SOURCE_DIFFERS '+name)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS');files=MT/'MQL5/Files/bot3-runtime-profile'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b3-runtime-'+a.run+'.set');ini=MT/('b3-runtime-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3RuntimeProfileCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for name in ['original-run.json','mql5-run.json']:
        record=json.loads((folder/name).read_text());require(all(record[k]==v for k,v in current.items()) and record['result_sha256']==sha(folder/name.replace('-run.json','-results.bin')),'RUN_IDENTITY_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();require(native[:12]==actual[:12]==header and len(native)==len(actual)==12+data.RESULT.size*len(rows),'BAD_RESULTS');failures=[];names=['id','fault','untouched_changed']+[x[0] for x in FIELDS]
    for c in rows:
        off=12+c['id']*data.RESULT.size;n=data.RESULT.unpack_from(native,off);r=data.RESULT.unpack_from(actual,off)
        if n!=r:failures.append(dict(id=c['id'],group=c['group'],differences={k:[x,y] for k,x,y in zip(names,n,r) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:20],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS);save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failures))
if __name__=='__main__':main()
