"""Compare complete preparation on the 1,016 ordinary legacy inputs.

prepare -> original -> mql5 --build BUILD -> compare RUN. Terminal replies supplied.
18 legacy runtime-error inputs are retained outside this ordinary cohort, not swallowed.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent

def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
PRE_PATH=ROOT/'bot-cua-toi-1/tests/check-management-prelude.py';pre=module('prep3_pre',PRE_PATH)
LEGACY_TOOL=ROOT/'cong-cu/kiem-dieu-chinh-bot-1-3.py';legacy=module('prep3_legacy',LEGACY_TOOL)
PUB_PATH=ROOT/'cong-cu/kiem-ban-git-quan-ly.py';pub=module('prep3_closure',PUB_PATH)
sha,require,save=pre.sha,pre.require,pre.save
MT=(ROOT.parent/'.local/mt5-bot3-thread-20261025').resolve();MASK=(1<<64)-1;MAGIC=0x50525033
SCRIPT='Scripts/bot-cua-toi-3/Bot3PreparationCheck.mq5'
CONTRACT=ROOT/'claude-thuc-hien/bot3-preparation-check-20261026-r1/TASK.md'
BINDINGS=HOME/'phan-tich/chuong-trinh-chinh/preparation-complete-20261026-r1/native-bindings.json'
LEGACY=HOME/'bang-chung/kiem-dieu-chinh/settings-20261023-r2'
# Input name/type/address, output name/type/address, in the fixed test contract order.
EXTRA=[
 ('native_6d250','d',0x6d250,'native_6d4e0','d',0x6d4e0),
 ('native_6d258','B',0x6d258,'native_6d4e8','i',0x6d4e8),
 ('native_6d260','d',0x6d260,'native_6d4f0','d',0x6d4f0),
 ('native_6d268','d',0x6d268,'native_6d4f8','d',0x6d4f8),
 ('native_6d270','d',0x6d270,'native_6d500','d',0x6d500),
 ('native_6d278','B',0x6d278,'native_6d508','B',0x6d508),
 ('native_1d6fa8','i',0x1d6fa8,'native_6d50c','i',0x6d50c),
 ('native_1d6fc0','B',0x1d6fc0,'native_6d510','B',0x6d510),
 ('virtual_stops','B',0x1d6fe0,'mode','i',0x6d514),
 ('native_1d6fe8','i',0x1d6fe8,'native_6d518','i',0x6d518),
 ('native_1d7178','B',0x1d7178,'native_6d51c','B',0x6d51c),
 ('native_6d2a3','B',0x6d2a3,'native_6d520','i',0x6d520),
 ('native_6d2e0','i',0x6d2e0,'native_6d550','i',0x6d550),
 ('management_timeframe','i',0x6d324,'management_timeframe','i',0x6d584),
 ('native_6d3f8','B',0x6d3f8,'native_6d608','i',0x6d608),
 ('native_6d3f0','d',0x6d3f0,'native_6d600','d',0x6d600),
 ('native_6d408','d',0x6d408,'native_6d618','d',0x6d618),
 ('native_1d7138','d',0x1d7138,'native_6d620','d',0x6d620),
 ('native_6d410','d',0x6d410,'native_6d628','d',0x6d628),
 ('native_1d7130','i',0x1d7130,'native_6d630','i',0x6d630),
 ('native_6d418','d',0x6d418,'native_6d638','d',0x6d638),
 ('native_6d420','B',0x6d420,'native_6d640','i',0x6d640)]
TAIL=[('native_6d5c8','B',0x6d5c8),('native_6d5f0','d',0x6d5f0),('native_6d5dc','B',0x6d5dc),('native_6d5e8','d',0x6d5e8),('native_6d5f8','B',0x6d5f8),('expiration_hours','i',0x6d560),('point','d',0x74968),('strategy_index','I',0x74934),('indicator_handle','i',0x6d178)]
API_ORDER=[10,11,15,12,13,14,3]
FIELDS=['id','success']+[n for n,_,_ in legacy.fields(legacy.OUTPUTS,3)]+[r[3] for r in EXTRA]+[n for n,_,_ in TAIL]+['array_size','array_series','comment_hash']+['calls_'+n for n in ['iATR','CopyBuffer','iOpen','SymbolInfoTick','TimeCurrent','SymbolInfoDouble','SymbolInfoInteger']]
RESULT=struct.Struct('<2i76Q');require(len(FIELDS)==78,'RESULT_SCHEMA_DIFFERS')
SCOPE=dict(whole_manager_complete=False,whole_bot_complete=False,full_ea=False,full_preparation_body_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['The full captured preparation function executes with supplied successful indicator/tick/market replies. All 76 listed words are compared, not the EA.',
 'Only the 1,016 legacy successful finite cases run here; the 18 prior runtime-error cases are retained outside this cohort. No handle failure, CopyBuffer zero/negative, short-array, allocation-failure or new runtime-error proof.',
 'Seven SDK call counts are compared. Tick/calendar contents beyond the listed outputs and mutations of settings during SDK calls are not compared in this cohort.',
 'String allocation succeeds. The indicator has two supplied samples and its size/series are compared; no complete indicator or broker/lifecycle claim.']

def cases():
    data=json.loads((BINDINGS.parent/'legacy-cohort.json').read_bytes());rows=data['rows']
    require(data['origin']['selected']==len(rows)==1016 and all(c['id']==i for i,c in enumerate(rows)),'COHORT_IDENTITY_DIFFERS')
    require(data['origin']['result_sha256']=='c103310e06497ba4db2364965d861f54bfdf62b1f7d460dd35c6254b4013dc54','LEGACY_ORACLE_IDENTITY_DIFFERS')
    return rows

def encode(rows):return legacy.encode(rows,3)
def output_header(count):return struct.pack('<4i',MAGIC,1,count,76)

def identity():
    base=HOME/'source/MQL5';names=sorted(p.relative_to(base.resolve()).as_posix() for p in pub.closure(base/SCRIPT,base))
    paths=[PRE_PATH,LEGACY_TOOL,PUB_PATH,BINDINGS,CONTRACT,BINDINGS.parent/'legacy-cohort.json',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py']
    return dict(original_ex5_sha256=pre.validation.original_hash(3),tool_sha256=sha(Path(__file__)),contract_sha256=sha(CONTRACT),helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in paths},sources_sha256={n:sha(base/n) for n in names})

class Original(legacy.Original):
    def __init__(self):
        super().__init__(3);b=json.loads(BINDINGS.read_bytes());require(self.base==int(b['base'],16),'BASE_DIFFERS')
        require(pre.validation.original_hash(3)==b['original_ex5_sha256'],'EX5_DIFFERS')
        lo,hi=int(b['function']['rva'],16),int(b['function']['end'],16)
        require(__import__('hashlib').sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==b['function']['sha256'],'FUNCTION_BYTES_DIFFER')
        self.covered=set();self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+lo,end=self.base+hi)
    def visit(self,m,address,size,user):
        self.covered.add(address-self.base)
        if address!=self.base+0xe0c0:return
        c=self.case;m.reg_write(self.x.UC_X86_REG_RCX,c['id']%9)
        for j,(_,kind,off,*_) in enumerate(EXTRA):
            value=0.5+c['id']*0.125+j*0.25 if kind=='d' else ((c['id']+j)%256 if kind=='B' else (1 if c['id']%2==0 else -1)*(c['id']+j+1))
            m.mem_write(self.base+off,struct.pack('<'+kind,value))
        m.mem_write(self.base+0x6d170,struct.pack('<2i',30,15));m.mem_write(self.base+0x6d308,struct.pack('<IQ',0,self.string('case'+str(c['id']))))
    def call(self,m,address,size,user):
        if self.apis[address]==10:
            x=self.x;sp=m.reg_read(x.UC_X86_REG_RSP)
            require(m.reg_read(x.UC_X86_REG_RDX)==0x53 and m.reg_read(x.UC_X86_REG_R8)==3,'BAD_INDICATOR_DISPATCH')
            require(struct.unpack('<i',m.mem_read(sp+0x38,4))[0]==15 and struct.unpack('<i',m.mem_read(sp+0x48,4))[0]==30,'BAD_INDICATOR_ARGUMENTS')
        return super().call(m,address,size,user)
    def value(self,off,kind):
        raw=bytes(self.m.mem_read(self.base+off,struct.calcsize('<'+kind)))
        return int.from_bytes(raw,'little') if kind=='d' else struct.unpack('<'+kind,raw)[0]&MASK
    def run(self,c):
        old=super().run(c);require(old[1]==1 and self.error==0,'ORDINARY_COHORT_BECAME_RUNTIME_ERROR')
        words=old[2:]+[self.value(row[5],row[4]) for row in EXTRA]+[self.value(off,kind) for _,kind,off in TAIL]
        descriptor=self.base+0x6d180;words.extend([struct.unpack('<i',self.m.mem_read(descriptor+8,4))[0]&MASK,int(bool(struct.unpack('<H',self.m.mem_read(descriptor+2,2))[0]&0x10))])
        pointer=struct.unpack('<Q',self.m.mem_read(self.base+0x6d578+4,8))[0];n=struct.unpack('<I',self.m.mem_read(pointer-4,4))[0] if pointer else 0;require(n<100,'BAD_COMMENT_SIZE')
        text=bytes(self.m.mem_read(pointer,n*2)).decode('utf-16-le') if pointer else '';words.append(pre.entry.text_hash(text));words.extend(self.api_counts.get(api,0) for api in API_ORDER)
        require(len(words)==76,'RESULT_WIDTH_DIFFERS');return RESULT.pack(c['id'],1,*words)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','mql5','original','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity()
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));tested=folder/'tested-sources';tested.mkdir()
        for name in current['sources_sha256']:shutil.copyfile(HOME/'source/MQL5'/name,tested/Path(name).name)
        for source in [Path(__file__),BINDINGS]:shutil.copyfile(source,tested/source.name)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==value for k,value in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_OR_INPUTS_DIFFER')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/name)==build['sources_sha256'][name]==digest,'SOURCE_DIFFERS '+name)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-preparation'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/('b3-preparation-'+a.run+'.set');ini=MT/('b3-preparation-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3PreparationCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    if a.mode=='original':
        require(not (folder/'original-results.bin').exists(),'RESULT_EXISTS');runner=Original();raw=bytearray(output_header(len(rows)));traces=[]
        for c in rows:
            try:raw+=runner.run(c)
            except Exception as error:
                save(folder/'attempt-error.json',dict(case=c['id'],error=str(error),rva=hex(runner.m.reg_read(runner.x.UC_X86_REG_RIP)-runner.base),api_counts=runner.api_counts));raise
            traces.append(dict(id=c['id'],source_case_id=c['source_case_id'],api_counts=runner.api_counts))
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-traces.json',traces);save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),instructions=sorted(hex(off) for off in runner.covered),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(runner.covered))));return
    for name in ['original-run.json','mql5-run.json']:
        rec=json.loads((folder/name).read_text());require(all(rec[k]==value for k,value in current.items()) and rec['result_sha256']==sha(folder/name.replace('-run.json','-results.bin')),'RUN_IDENTITY_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();require(native[:16]==actual[:16]==output_header(len(rows)) and len(native)==len(actual)==16+RESULT.size*len(rows),'BAD_RESULTS');failed=[]
    for c in rows:
        off=16+c['id']*RESULT.size;n=RESULT.unpack_from(native,off);r=RESULT.unpack_from(actual,off)
        if n!=r:failed.append(dict(id=c['id'],differences={k:[x,y] for k,x,y in zip(FIELDS,n,r) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:20],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS);save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':main()
