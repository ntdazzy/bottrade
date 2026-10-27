"""Run original evaluator into first real manager's zero-ticket test, no middle reset.

prepare|original|mql5(--build)|compare RUN. Varied ABI-aligned stacks and incoming
R12 byte are supplied only at the first evaluator instruction; licence is untouched.
"""
import argparse,copy,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
stops=module('first_zero_stops',ROOT/'cong-cu/kiem-bo-sung-muc-dung-bot-1-3.py');p=stops.prefix(1)
require=stops.require;sha=stops.sha;save=stops.save;MASK=stops.MASK;MAGIC=0x465a4331
SCRIPT='Scripts/bot-cua-toi-1/Bot1ManagementCallerContextCheck.mq5';SOURCE=HOME/'source/MQL5';MT=p.MT
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,
 native_evaluator_and_first_ticket_executed=True,terminal_replies_supplied=True,original_ex5_changed=False,license_flag_changed=False)
LIMITS=['Original evaluator18aa0 -> prelude -> initial position pass -> new-bar caller -> real manager271f0 ->27368; the actual first zero-ticket branch and CMOV execute. No middle register/stack reset.',
 'Initial ABI-aligned stack and R12 are supplied at entry, not recovered from every coordinator path. Ordinary coordinator preload69f70 is included; zero is an explicit alternate incoming fixture.',
 'Server/calendar/sessions/iTime and position queries are supplied. Initial position count is -1/0/1, manager count1 and first ticket0. Successful allocation and valid IntegerToString6 are supplied; later manager/EA and allocation failure excluded.']
def cases():
    rows=[]
    for day in [0,1,6]:
        for mode in [0,1,2]:
            for sessions in range(11):
                for enabled in [0,1,255]:
                    for total in [-1,0,1]:
                        for incoming in [0,0x70]:
                            for shift in [0,-240]:rows.append(dict(id=len(rows),enabled=enabled,total=total,day=day,mode=mode,sessions=sessions,incoming=incoming,shift=shift))
    for shift in range(0,-256,-16):
        for day in [0,1]:
            for mode in [0,2]:rows.append(dict(id=len(rows),enabled=0,total=0,day=day,mode=mode,sessions=1,incoming=0x70,shift=shift))
    return rows
def encode(rows):return struct.pack('<3i',MAGIC,1,len(rows))+b''.join(struct.pack('<8i',c['id'],c['enabled'],c['total'],c['day'],c['mode'],c['sessions'],c['incoming'],c['shift']) for c in rows)
def native_row(c):
    row=stops.base();row.update(id=c['id'],enabled=c['enabled'],total=c['total'],positions=[stops.position(ticket=0)])
    v=copy.deepcopy(p.case_data.base_case());v.update(id=c['id'],index=0,caller_flag=0,flag=1 if c['mode']==0 else 0,info=1 if c['mode']==1 else 0)
    v['calendar'][6]=v['calendar_reply'][6]=c['day']
    for j in range(10):v['sessions'][60+j]=[int(j<c['sessions']),3600,7200]
    row['prelude']=v;return row
Base=stops.original_class(1,p)
class Original(Base):
    def __init__(self):
        super().__init__();self.observed=[]
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40;a=eb+0x7d3b50
        if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
        require(a not in self.apis,'ITIME_ALREADY_BOUND');self.apis[a]=701;self.m.mem_write(a,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.observe_context,begin=self.base+0x1a152,end=self.base+0x2abbd)
    def seed(self):
        super().seed();m,x=self.m,self.x;c=self.context_case
        sp=m.reg_read(x.UC_X86_REG_RSP)+c['shift'];self.frame=sp-64-0x228
        require(self.frame%16==0 and 0x50000000<=self.frame and sp+8<=0x50020000,'STACK_ALIGNMENT_RANGE')
        m.mem_write(self.frame,bytes(0x300));m.mem_write(sp,struct.pack('<Q',0x60000000));m.mem_write(self.frame+0x50,struct.pack('<8i',*self.row['prelude']['calendar']))
        m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_R12,self.base+0x69f70 if c['incoming'] else 0)
        # Only trading-mode/time inputs are supplied. The existing licence1 byte is read-only.
        m.mem_write(self.base+0x62490,b'\0');m.mem_write(self.base+0x62000,b'\0');m.mem_write(self.base+0x6248c,struct.pack('<i',1))
        m.mem_write(self.base+0x66750,struct.pack('<8q',*[10+i for i in range(8)]))
        self.license_before=bytes(m.mem_read(self.base+0x67470,1));require(self.license_before==b'\1','CAPTURE_LICENSE_NOT_VALID')
    def call(self,m,address,size,user):
        if self.phase!='router':return super().call(m,address,size,user)
        x=self.x;api=self.apis[address]
        if api in [100,101]:return p.head.entry.Original.call(self,m,address,size,user)
        if api==410:self.router_events.append([api,1]);m.reg_write(x.UC_X86_REG_RAX,1)
        elif api==411:self.router_events.append([api,m.reg_read(x.UC_X86_REG_RDX),0]);m.reg_write(x.UC_X86_REG_RAX,0)
        elif api==701:
            require(m.reg_read(x.UC_X86_REG_R9)==1,'ITIME_SHIFT');self.router_events.append([api,m.reg_read(x.UC_X86_REG_R8),1792713600]);m.reg_write(x.UC_X86_REG_RAX,1792713600)
        else:raise ValueError('UNEXPECTED_ROUTER_API '+str(api))
    def observe_context(self,m,address,size,user):
        if self.phase!='router':return
        rva=address-self.base;x=self.x
        if rva in [0x1a245,0x271f0,0x27357]:self.marks.append(dict(rva=hex(rva),r12=hex(m.reg_read(x.UC_X86_REG_R12)),low=m.reg_read(x.UC_X86_REG_R12)&255))
        if rva==0x27368:self.changed=m.reg_read(x.UC_X86_REG_RBX)&0xffffffff;m.emu_stop()
    def run_context(self,c):
        self.context_case=c;self.marks=[];self.router_events=[];self.changed=None
        super().run_joined(native_row(c));require(self.m.reg_read(self.x.UC_X86_REG_RIP)==self.base+0x1a152,'INITIAL_PASS_EXIT')
        self.phase='router';self.m.emu_start(self.base+0x1a152,0x60000000,timeout=5000000,count=100000)
        require(self.changed in [0,1] and len(self.marks)==3,'FIRST_TICKET_NOT_REACHED')
        require(bytes(self.m.mem_read(self.base+0x67470,1))==self.license_before,'LICENSE_FLAG_CHANGED')
        self.observed.append(dict(**c,marks=self.marks,changed=self.changed,frame=hex(self.frame),router_events=self.router_events))
        return struct.pack('<iQ',c['id'],self.changed)
def identity():
    helpers=dict(stops.identity(1,p)['helpers_sha256']);helpers[Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__))
    return dict(original_ex5_sha256=p.head.validation.original_hash(1),tool_sha256=sha(Path(__file__)),helpers_sha256=helpers,
      sources_sha256={f.relative_to(SOURCE).as_posix():sha(f) for f in p.pub.closure(SOURCE/SCRIPT,SOURCE)})
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,40}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity();header=struct.pack('<4i',MAGIC,1,len(rows),1)
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');o=Original();raw=bytearray(header)
        for c in rows:
            try:raw+=o.run_context(c)
            except Exception as e:raise RuntimeError('CASE '+str(c['id'])+' RIP '+hex(o.m.reg_read(o.x.UC_X86_REG_RIP))+' '+repr(e)) from e
        (folder/'original-results.bin').write_bytes(raw);save(folder/'observations.json',o.observed)
        save(folder/'original-run.json',dict(**current,cases=len(rows),false_count=sum(v['changed']==0 for v in o.observed),observations_sha256=sha(folder/'observations.json'),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),false_count=sum(v['changed']==0 for v in o.observed))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');require(not(folder/'mql5-results.bin').exists(),'RESULT_EXISTS');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));require(b['target']==SCRIPT and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot1-first-zero-context'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('context-'+a.run+'.set');ini=MT/('context-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ManagementCallerContextCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for name in ['original','mql5']:
        r=json.loads((folder/(name+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();require(native[:16]==actual[:16]==header and len(native)==len(actual)==16+12*len(rows),'RESULT_FORMAT');failed=[]
    for i,c in enumerate(rows):
        n=struct.unpack_from('<iQ',native,16+12*i);r=struct.unpack_from('<iQ',actual,16+12*i);require(n[0]==r[0]==i,'RESULT_ID')
        if n!=r:failed.append(dict(**c,native=n[1],mql5=r[1]))
    result=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:20],**SCOPE,limits=LIMITS);save(folder/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failed))
if __name__=='__main__':main()
