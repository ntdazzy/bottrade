"""Compare the entire bot1 preparation body, with supplied MT5 replies.

The Script reader follows the explicit field contract below.
prepare/original/mql5(--build)/compare RUN keep separate, immutable evidence.
"""
import argparse, hashlib, importlib.util, json, re, shutil, struct, subprocess
from pathlib import Path

HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
pre=module('prep1_pre',HOME/'tests/check-management-prelude.py')
legacy=module('prep1_legacy',ROOT/'cong-cu/kiem-dieu-chinh-bot-1-3.py')
pub=module('prep1_pub',ROOT/'cong-cu/kiem-ban-git-quan-ly.py')
require,sha,save=pre.require,pre.sha,pre.save
MT=(ROOT.parent/'.local/mt5-bot1-thread-20261025').resolve()
SCRIPT='Scripts/bot-cua-toi-1/Bot1PreparationCheck.mq5'
SOURCE=HOME/'source/MQL5';LEGACY=HOME/'bang-chung/kiem-dieu-chinh/settings-20261023-r2'
MAGIC=0x50525031;MASK=(1<<64)-1
FUNCTION=(0x7500,0x831d,'8679070031fe7f3309378147c8afc4bf2d4ab596b3ee22a73e8e6386db6c9d0d')
# Input name/kind/RVA, state field/kind/RVA. Names without proven meaning retain their RVAs.
EXTRA=[
 ('native_62218','d',0x62218,'native_623e8','d',0x623e8),
 ('native_62220','B',0x62220,'native_623f0','i',0x623f0),
 ('native_62228','d',0x62228,'native_623f8','d',0x623f8),
 ('native_62230','d',0x62230,'native_62400','d',0x62400),
 ('native_62238','d',0x62238,'native_62408','d',0x62408),
 ('native_62240','B',0x62240,'native_62410','B',0x62410),
 ('native_6a5d8','i',0x6a5d8,'native_62414','i',0x62414),
 ('omit_real_sl_tp','B',0x6a5e0,'omit_real_sl_tp','B',0x62418),
 ('virtual_stops','B',0x6a600,'mode','i',0x6241c),
 ('native_6a608','i',0x6a608,'native_62420','i',0x62420),
 ('check_free_margin','B',0x6a788,'check_free_margin','B',0x62424),
 ('native_62268','B',0x62268,'native_62428','i',0x62428),
 ('native_622a8','B',0x622a8,'native_62458','i',0x62458),
 ('native_622ec','i',0x622ec,'native_6248c','i',0x6248c),
 ('native_622f0','B',0x622f0,'native_62490','B',0x62490),
 ('native_62390','d',0x62390,'native_62510','d',0x62510),
 ('native_62398','B',0x62398,'native_62518','i',0x62518),
 ('native_623a8','d',0x623a8,'native_62528','d',0x62528),
 ('native_6a740','d',0x6a740,'native_62530','d',0x62530),
 ('native_623b0','d',0x623b0,'native_62538','d',0x62538),
 ('native_6a748','i',0x6a748,'native_62540','i',0x62540),
 ('native_6a750','d',0x6a750,'native_62548','d',0x62548),
 ('native_6a768','i',0x6a768,'native_62550','i',0x62550)]
TAIL=[('native_624d8','B',0x624d8),('native_624ec','B',0x624ec),('native_624f8','d',0x624f8),
 ('native_62500','d',0x62500),('native_62508','B',0x62508),('expiration_hours','i',0x62468),
 ('point','d',0x67928),('strategy_index','I',0x678f4),('indicator_handle','i',0x62188)]
FIELDS=[n for n,_,_ in legacy.fields(legacy.OUTPUTS,1)]+[r[3] for r in EXTRA]+[n for n,_,_ in TAIL]
FIELDS+=['array_size','array_series','comment_hash']+['calls_'+n for n in ['ATR','Copy','Tick','Time','Double','Integer']]
FIELDS+=['tick.time','tick.bid','tick.ask']+['calendar.'+n for n in ['year','mon','day','hour','min','sec','day_of_week','day_of_year']]+['call_order_hash']
FIELDS+=['print_calls']
RESULT=struct.Struct('<2i'+'Q'*len(FIELDS))
SCOPE=dict(whole_manager_complete=False,whole_bot_complete=False,full_ea=False,
 full_preparation_body_executed=True,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['The full captured preparation body runs with supplied indicator, tick, time and symbol replies; not a complete EA.',
 '1,040 ordinary cases plus 20 service/nonfinite cases. Short arrays, zero divisions and mutations of settings during SDK calls require separate cohorts.',
 'Successful string allocations; seed/profile initialization, UI, lifecycle and real broker behavior remain outside this comparison.']

def cases():
    rows=json.loads((LEGACY/'cases.json').read_text());raw=(LEGACY/'original-results.bin').read_bytes()
    require(hashlib.sha256(raw).hexdigest()=='3d6037d44f0de2d1a3c96695a3bbb00d7f271954354320592e3f49685d3efcc1','LEGACY_ORACLE_CHANGED')
    magic,version,count,width=struct.unpack_from('<4i',raw);require(count==len(rows)==1050 and width==33,'LEGACY_COHORT_SHAPE')
    selected=[]
    for i,c in enumerate(rows):
        source_id,success=struct.unpack_from('<2i',raw,16+i*(8+8*width));require(source_id==i,'LEGACY_ID_DIFFERS')
        if success: selected.append(dict(c,source_case_id=i,id=len(selected)))
    require(len(selected)==1040,'ORDINARY_COHORT_CHANGED')
    for mode in range(20):
        c=legacy.base_case(1);c.update(id=len(selected),source_case_id=-1,tag='service-'+str(mode))
        if mode==9:c.update(use_variable=255,adjust_lots=255,feature_flag=255,freeze_buffer_flag=255,aux_hour1=255,aux_scan50=255)
        if mode==10:c.update(reference=float('nan'))
        if mode in [11,12,13,14]:c.update(sample={11:float('nan'),12:float('inf'),13:float('-inf'),14:float('inf')}[mode])
        if mode==14:c.update(feature_flag=0)
        if mode==15:c.update(sample=0.0)
        if mode==19:c.update(virtual_expiration=255)
        selected.append(c)
    return selected

def identity():
    paths=[Path(__file__),ROOT/'cong-cu/kiem-dieu-chinh-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',
      HOME/'tests/check-management-prelude.py',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',
      ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py',LEGACY/'cases.json',LEGACY/'original-run.json']
    return dict(original_ex5_sha256=pre.validation.original_hash(1),tool_sha256=sha(Path(__file__)),
      helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in paths},
      sources_sha256={p.relative_to(SOURCE).as_posix():sha(p) for p in pub.closure(SOURCE/SCRIPT,SOURCE)})

def scalar_extra(case_id,j,kind):
    if kind=='d':return .5+case_id*.125+j*.25
    return (case_id+j)%256 if kind=='B' else (1 if case_id%2==0 else -1)*(case_id+j+1)

class Original(legacy.Original):
    def __init__(self):
        super().__init__(1);lo,hi,digest=FUNCTION
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==digest,'NATIVE_FUNCTION_DIFFERS')
        self.covered=set();self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+lo,end=self.base+hi)
    def visit(self,m,address,size,user):
        self.covered.add(address-self.base)
        if address!=self.base+FUNCTION[0]:return
        c=self.case;m.reg_write(self.x.UC_X86_REG_RCX,c['id']%8)
        for _,k,off in legacy.fields(legacy.OUTPUTS,1)+[(r[3],r[4],r[5]) for r in EXTRA]+TAIL:
            m.mem_write(self.base+off,bytes(struct.calcsize('<'+k)))
        m.mem_write(self.base+0x62190,bytes(36));m.mem_write(self.base+0x62480,bytes(12))
        m.mem_write(self.base+0x67750,bytes(56));m.mem_write(self.base+0x67790,bytes(32))
        m.mem_write(self.base+0x6a410,struct.pack('<i',5017))
        for j,(_,kind,off,*_) in enumerate(EXTRA):m.mem_write(self.base+off,struct.pack('<'+kind,scalar_extra(c['id'],j,kind)))
        m.mem_write(self.base+0x621c4,struct.pack('<iB',30,0 if self.mode==7 else 255 if self.mode==8 else 1))
        m.mem_write(self.base+0x622d0,struct.pack('<IQ',0,self.string('case'+str(c['id']))))
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api in [100,101]:return super().call(m,address,size,user)
        if api==10 and m.reg_read(x.UC_X86_REG_RDX)==2:
            self.calls.append(7);m.reg_write(x.UC_X86_REG_RAX,0);return
        if api in [10,11,12,13,14,3]:self.calls.append([10,11,12,13,14,3].index(api)+1)
        if api==10:
            sp=m.reg_read(self.x.UC_X86_REG_RSP)
            require(m.reg_read(self.x.UC_X86_REG_RDX)==0x53,'BAD_ATR_DISPATCH')
            require(struct.unpack('<i',m.mem_read(sp+0x38,4))[0]==(0 if self.mode==7 else 16408) and struct.unpack('<i',m.mem_read(sp+0x48,4))[0]==30,'BAD_ATR_ARGUMENTS')
            if self.mode==0:m.reg_write(x.UC_X86_REG_RAX,(-17)&MASK);return
        if api==11 and self.mode==1:m.reg_write(x.UC_X86_REG_RAX,0);return
        if api==11 and self.mode in [2,3,4]:
            n=3 if self.mode==3 else 4 if self.mode==4 else 2;desc=self.base+0x62190
            m.mem_write(desc+2,struct.pack('<H',1));m.mem_write(desc+8,struct.pack('<I',n));m.mem_write(desc+28,struct.pack('<Q',0x70100000))
            m.mem_write(0x70100000,struct.pack('<'+'d'*n,*[self.case['sample']+j*.125 for j in range(n)]))
            m.reg_write(x.UC_X86_REG_RAX,(-1 if self.mode==2 else n)&MASK);return
        if api==12 and self.mode==5:m.reg_write(x.UC_X86_REG_RAX,0);return
        if api==3 and m.reg_read(x.UC_X86_REG_R8)==17 and self.mode in [16,17]:
            values=[3,1,8] if self.mode==16 else [2,5,1,9]
            value=values[self.digit_calls];self.digit_calls+=1
            m.reg_write(x.UC_X86_REG_RAX,value);return
        if api==14 and self.mode==18:
            value=[.01,.002,.001,.03,.04][self.point_calls];self.point_calls+=1
            raw=struct.pack('<d',value);m.mem_write(self.base+self.cfg['slot'],raw);m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'));return
        if api==13:
            pointer=m.reg_read(self.x.UC_X86_REG_RDX)
            if pointer:m.mem_write(pointer,bytes(32))
        result=super().call(m,address,size,user)
        if api==12 and self.mode==6:m.reg_write(x.UC_X86_REG_RAX,0)
        return result
    def value(self,off,kind):
        raw=self.m.mem_read(self.base+off,struct.calcsize('<'+kind))
        return int.from_bytes(raw,'little') if kind=='d' else struct.unpack('<'+kind,raw)[0]&MASK
    def run(self,c):
        self.mode=c['id']-1040 if c['id']>=1040 else -1;self.calls=[];self.digit_calls=0;self.point_calls=0
        old=super().run(c);require(old[1]==1,'ORDINARY_CASE_STOPPED')
        words=old[2:]+[self.value(r[5],r[4]) for r in EXTRA]+[self.value(off,k) for _,k,off in TAIL]
        desc=self.base+0x62190;words.extend([struct.unpack('<i',self.m.mem_read(desc+8,4))[0],int(bool(struct.unpack('<H',self.m.mem_read(desc+2,2))[0]&16))])
        p=struct.unpack('<Q',self.m.mem_read(self.base+0x62484,8))[0];n=struct.unpack('<I',self.m.mem_read(p-4,4))[0] if p else 0
        require(n<100,'COMMENT_SIZE');text=bytes(self.m.mem_read(p,n*2)).decode('utf-16-le') if p else ''
        words.append(pre.entry.text_hash(text));words.extend(self.calls.count(k) for k in range(1,7))
        words.extend(self.value(off,k) for off,k in [(0x67750,'q'),(0x67758,'d'),(0x67760,'d')])
        words.extend(self.value(0x67790+i*4,'i') for i in range(8))
        h=0xcbf29ce484222325
        for call in self.calls:
            for byte in struct.pack('<Q',call):h=((h^byte)*0x100000001b3)&MASK
        words.extend([h,self.calls.count(7)]);require(len(words)==len(FIELDS),'RESULT_WIDTH');return RESULT.pack(c['id'],1,*words)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    require(a.run and re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run
    rows=cases();current=identity();header=struct.pack('<4i',MAGIC,1,len(rows),len(FIELDS))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(legacy.encode(rows,1));save(folder/'cases.json',rows)
        for n in current['sources_sha256']:
            dest=folder/'tested-sources'/n;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(SOURCE/n,dest)
        save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),words=len(FIELDS))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==legacy.encode(rows,1),'IDENTITY_DIFFERS')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');runner=Original();raw=bytearray(header)
        for c in rows:raw+=runner.run(c)
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',dict(**current,cases=len(rows),instructions=len(runner.covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(runner.covered))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,digest in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==digest,'BUILD_SOURCE_DIFFERS '+n)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot1-preparation'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b1-preparation-'+a.run+'.set');ini=MT/('b1-preparation-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1PreparationCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for n in ['original-run.json','mql5-run.json']:
        record=json.loads((folder/n).read_text());require(all(record[k]==v for k,v in current.items()) and record['result_sha256']==sha(folder/n.replace('-run.json','-results.bin')),'RUN_IDENTITY_DIFFERS')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();require(native[:16]==actual[:16]==header and len(native)==len(actual)==16+RESULT.size*len(rows),'BAD_RESULT_SIZE')
    failures=[]
    for c in rows:
        off=16+c['id']*RESULT.size;n=RESULT.unpack_from(native,off);r=RESULT.unpack_from(actual,off)
        if n!=r:failures.append(dict(id=c['id'],differences={k:[x,y] for k,x,y in zip(['id','success']+FIELDS,n,r) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failures),failed=len(failures),first_failures=failures[:20],result_sha256=dict(original=sha(folder/'original-results.bin'),mql5=sha(folder/'mql5-results.bin')),**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failures))
if __name__=='__main__':main()
