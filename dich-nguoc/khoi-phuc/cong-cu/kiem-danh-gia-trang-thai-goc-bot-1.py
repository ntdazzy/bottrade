"""Compare the evaluator using its unchanged observed initialization flag.

generate; prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
No authorization helper executes and neither protected state byte is writable.
This is a business-body test, not reconstruction of account authorization.
"""
import hashlib,importlib.util,inspect,json,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];BASE=0x23e5aa10000
CAPTURE=ROOT/'bot-cua-toi-1/bang-chung/captures/luot-20261023-r1'
RUN=ROOT/'bot-cua-toi-1/bang-chung/luot-20261023-r1'
PROTECTED=[0x6216c,0x67470]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
d=module('observed_eval_display','kiem-danh-gia-co-thong-ke-bot-1-3.py')
require,sha=d.require,d.sha
TEMPLATE=ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1EvaluationWithDisplayCheck.mq5'
SCRIPT=TEMPLATE.with_name('Bot1ObservedEvaluationCheck.mq5')

def provenance():
    capture=json.loads((CAPTURE/'capture.json').read_text());record=json.loads((RUN/'capture-run.json').read_text());engine=json.loads((RUN/'engine-observed.json').read_text());jobs=json.loads((RUN/'jobs.json').read_text())
    require(capture['pid']==record['tester_pid']==engine['pid'],'CAPTURE_PROCESS_LINK')
    require(record['source_sha256']=='a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922','CAPTURE_EX5_LINK')
    require(record['tester_sha256']==engine['engine_sha256'] and record['engine_base']==engine['engine_base'],'CAPTURE_ENGINE_LINK')
    require(jobs==[record['job']] and set(jobs[0]['inputs'])=={'AutoGMT','Broker_GMT_OFFSET_Winter','Broker_GMT_OFFSET_Summer'},'CAPTURE_JOB_LINK')
    states={};inputs=[CAPTURE/'capture.json',RUN/'capture-run.json',RUN/'engine-observed.json',RUN/'jobs.json',RUN/'test-interrupted.json']
    for r in capture['regions']:
        if r.get('kind')!='mutable_program_data':continue
        path=CAPTURE/r['file'];raw=path.read_bytes();require(sha(path)==r['sha256'],'CAPTURE_DATA_CHANGED');inputs.append(path)
        for off in PROTECTED:
            at=BASE+off-r['base']
            if 0<=at<len(raw):states[hex(off)]=raw[at]
    require(states=={'0x6216c':1,'0x67470':1},'OBSERVED_STATE_CHANGED')
    code=CAPTURE/'0000023e5aa10000.bin';raw=code.read_bytes();inputs.append(code)
    code_region=next(r for r in capture['regions'] if r.get('kind')=='executable' and r['base']==BASE)
    require(code_region['file']==code.name and sha(code)==code_region['sha256'],'CAPTURE_CODE_CHANGED')
    require(raw[0xca8:0xcab]==bytes.fromhex('c60600') and raw[0xcba:0xcbc]==bytes.fromhex('84c0') and raw[0xcc6:0xcc8]==bytes.fromhex('743d') and raw[0xce1:0xce4]==bytes.fromhex('c60601'),'ONINIT_ACCEPTED_STATE_SEQUENCE')
    return dict(snapshot='luot-20261023-r1',code_base=hex(BASE),states=states,
      state_zero_rva='0xca8',authorization_call_rva='0xcb8',authorization_test_rva='0xcba',rejection_jump_rva='0xcc6',accepted_state_write_rva='0xce1',
      evidence_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in inputs},original_test_interrupted=True,authorization_execution_proven=False,account_identity_included=False)

OBSERVED=provenance()
source=inspect.getsource(d.parent.original);old="(0x67470,e['LicenceValid']),"
require(source.count(old)==1,'LICENCE_WRITE_PATTERN');source=source.replace(old,'')
TRANSFORM_SHA=hashlib.sha256(source.encode()).hexdigest();exec(compile(source,__file__,'exec'),d.parent.__dict__)
BASE_CASES=d.cases;BASE_ORIGINAL=d.original;BASE_IDENTITY=d.identity

def cases(bot):
    require(bot==1,'BOT1_ONLY');rows=[]
    for c in BASE_CASES(bot):
        if c['extra']['LicenceValid']!=OBSERVED['states']['0x67470']:continue
        c['id']=len(rows);rows.append(c)
    return rows

def original(bot,casts):
    o=BASE_ORIGINAL(bot,casts);require(o.base==BASE,'BOT1_BASE_CHANGED');write=o.m.mem_write
    protected=[BASE+off for off in PROTECTED];restores={r['base']:raw for r,raw in o.regions if r.get('kind')=='mutable_program_data'}
    for off in PROTECTED:require(bytes(o.m.mem_read(BASE+off,1))==bytes([OBSERVED['states'][hex(off)]]),'INITIAL_OBSERVED_BYTE_CHANGED')
    o.observed_restores=0
    def guarded_write(address,data):
        if any(address<=value<address+len(data) for value in protected):
            require(address in restores and bytes(data)==restores[address],'PROTECTED_STATE_WRITE '+hex(address-BASE));o.observed_restores+=1
        return write(address,data)
    o.m.mem_write=guarded_write
    def protected_entry(m,address,size,user):raise ValueError('AUTHORIZATION_OUTSIDE_EVALUATOR '+hex(address-BASE))
    def protected_cpu_write(m,access,address,size,value,user):
        if any(address<=point<address+size for point in protected):raise ValueError('CPU_CHANGED_PROTECTED_STATE')
    for off in [0xc30,0x5880,0x3d6c0,0x4d260]:o.m.hook_add(o.uc.UC_HOOK_CODE,protected_entry,begin=BASE+off,end=BASE+off)
    o.m.hook_add(o.uc.UC_HOOK_MEM_WRITE,protected_cpu_write)
    run=o.run
    def guarded_run(c,tape):
        require(c['extra']['LicenceValid']==OBSERVED['states']['0x67470'],'CASE_PERMISSION_DIFFERS')
        result=run(c,tape)
        for off in PROTECTED:require(bytes(o.m.mem_read(BASE+off,1))==bytes([OBSERVED['states'][hex(off)]]),'OBSERVED_STATE_CHANGED_DURING_RUN')
        return result
    o.run=guarded_run;return o

def generate():
    code=TEMPLATE.read_text(encoding='utf-8-sig').replace('bot1-evaluation-display','bot1-observed-evaluation')
    marker='Prefix.license_valid=(uchar)PrefixData[6];';require(code.count(marker)==1,'SOURCE_PERMISSION_PATTERN')
    code=code.replace(marker,'if(PrefixData[6]!='+str(OBSERVED['states']['0x67470'])+') return 14;\n      '+marker)
    require(not SCRIPT.exists() or SCRIPT.read_text(encoding='utf-8-sig')==code,'SOURCE_EXISTS')
    if not SCRIPT.exists():SCRIPT.write_text(code,encoding='utf-8',newline='\n')
    print(SCRIPT)

def identity(bot):
    current=BASE_IDENTITY(bot);src=ROOT/'bot-cua-toi-1/source/MQL5'
    current['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in d.pub.closure(SCRIPT,src)}
    for path in [Path(__file__),TEMPLATE]:current['helpers_sha256'][path.relative_to(ROOT).as_posix()]=sha(path)
    current['observed_state_provenance']=provenance();current['native_setup_transform_sha256']=TRANSFORM_SHA;return current

source=inspect.getsource(d.main).replace("p.add_argument('bot',type=int,choices=[1,3]);","p.set_defaults(bot=1);")
source=source.replace('EvaluationWithDisplayCheck','ObservedEvaluationCheck').replace('evaluation-display','observed-evaluation')
source=source.replace('sdk_calls=calls,parent_instructions=', 'sdk_calls=calls,verified_snapshot_restores=o.observed_restores,parent_instructions=')
exec(compile(source,__file__,'exec'),d.__dict__)
d.cases=cases;d.identity=identity;d.original=original
d.SCOPE=dict(d.SCOPE,authorization_executed=False,authorization_entry_guarded=True,observed_permission_state_unchanged=True,permission_reply_supplied=False,protected_state_writes_guarded=True)
if __name__=='__main__':
    if len(sys.argv)>1 and sys.argv[1]=='generate':generate()
    else:d.main()
