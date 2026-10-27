"""Compare native pending resize caller1a817..1b317 and real delete/open/send.

prepare|mql5(--build)|original|compare RUN. Volume-call output and live frame at
1a817 are supplied. Full source32dd0 calls950; it is not only request preparation.
String casts are measured in isolated MT5; their native input/arguments are checked.
"""
import argparse,copy,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
cleanup=module('resize_cleanup',ROOT/'bot-cua-toi-3/tests/check-evaluation-pending-cleanup.py');stops=cleanup.stops;p=stops.prefix(1)
require=cleanup.require;sha=cleanup.sha;save=cleanup.save;bits=cleanup.bits;text=cleanup.text;signed=cleanup.signed;MASK=cleanup.MASK
MAGIC=0x45525331;SCRIPT='Scripts/bot-cua-toi-1/Bot1EvaluationPendingResizeCheck.mq5';SOURCE=HOME/'source/MQL5';MT=p.MT
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,
 native_pending_resize_caller_executed=True,native_delete_open_send_executed=True,child_helpers_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Only resize caller1a817..1b317 with its original delete34150, complete open32dd0, filling/expiration helpers and send950. Initial post-volume frame/arrays/registers are supplied; no earlier management/volume gate or complete EA.',
 'Terminal queries, selection, send replies and successful allocation are supplied. Numeric cast text is measured in isolated MT5 and matched to native value/type. Send log_level=0; no live order or allocation-fault proof.']
shared_cases=module('bot1_resize_shared_cases',ROOT/'bot-cua-toi-3/tests/check-evaluation-pending-resize.py')
def cases():
    rows=shared_cases.cases()
    for row in rows:row['volumes']=row['volumes'][:8]
    return rows
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=cleanup.encode([c])[12:]+struct.pack('<2iQ8Q8qi',c['index'],c['virtual'],c['percent'],*c['volumes'],
          *[c[k] for k in ['execution','filling','order_flags','order_ok','expiration_flags','expiration_ok','auto_expiration','resize_mutation']],len(c['orders']))
        for v in c['orders']:raw+=struct.pack('<3Qq',v['sl'],v['tp'],v['volume'],v['expiration'])+text(v['comment'])
    return raw
def read_casts(path,count):
    raw=path.read_bytes();require(struct.unpack_from('<3i',raw)==(MAGIC,1,count),'CAST_HEADER');at=12;out={}
    for i in range(count):
        cid,value,n=struct.unpack_from('<iQi',raw,at);at+=16;require(cid==i and 0<=n<1000,'CAST_RECORD');out[i]=(value,raw[at:at+2*n].decode('utf-16-le'));at+=2*n
    require(at==len(raw),'CAST_TRAILING');return out
class Original(stops.original_class(1,p)):
    def __init__(self,casts):
        super().__init__();self.casts=casts;self.resize_covered=set();self.open_covered=set()
        for lo,hi,digest in [(0x32dd0,0x336c8,'8d666c1808a0c8d2090eb04e957a383f26fd51f6a8bcee6edeb9d3875b0a7217'),
          (0x231c0,0x235b6,'8ff1c9b76c8c8629560f30307f42944a05858e1cb103c54d62fa0ff7c371d23a')]:
            require(hashlib.sha256(bytes(self.m.mem_read(self.base+lo,hi-lo))).hexdigest()==digest,'OPEN_FILL_BYTES_CHANGED')
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+lo,end=self.base+hi-1)
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+0x34150,0x3477d-0x34150))).hexdigest()=='c10c5f706bb77a27a0e692307c8848c63fcfcbeb65e72d9f5ce30784fceec10b','DELETE_BYTES_CHANGED')
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x34150,end=self.base+0x3477c)
        for off,api in [(0x7d81a0,501),(0x7d81f0,502),(0x7d8310,503),(0x7d83a0,504),(0x7d8240,505),(0x7c2890,506),(0x7d8280,507)]:
            a=eb+off;existed=a in self.apis
            if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
            self.apis[a]=api;self.m.mem_write(a,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        for off,api in [(0x7c29d0,602),(0x7cf6c0,603),(0x7b17c0,604)]:
            a=eb+off;require(a not in self.apis,'RESIZE_SDK_ALREADY_BOUND')
            if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
            self.apis[a]=api;self.m.mem_write(a,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
    def seed(self):
        super().seed();self.selected_order=-1
        self.m.mem_write(self.base+0x65dd0,b''.join(struct.pack('<2Q',*row) for row in self.row['table']))
    def mutate_resize(self):
        if self.resize_changed:return
        m=self.m;c=self.row;mode=c['resize_mutation']
        if mode==1:m.mem_write(self.base+0x66a80+8*self.current_index,struct.pack('<d',.75));c['volumes'][self.current_index]=bits(.75)
        elif mode==2:self.current_index=7;m.mem_write(self.base+0x678f4,struct.pack('<I',7))
        elif mode==3:
            m.mem_write(self.base+0x67918,struct.pack('<IQ',0,self.string('Đổi mã')));self.live_symbol='Đổi mã'
        elif mode==4:
            if self.selected_order>=0:c['orders'][self.selected_order]['type']=5
        else:return
        self.resize_changed=True
    def extra_event(self,kind,words=(),texts=(),snapshot=False):
        super().extra_event(kind,words,texts,snapshot)
        if kind==20:self.mutate_resize()
    def visit(self,m,address,size,user):
        if self.phase!='loop':return
        rva=address-self.base;self.resize_covered.add(rva)
        if rva==0x34150:self.extra_event(21,[m.reg_read(self.x.UC_X86_REG_RCX)],snapshot=True)
        if rva==0x1b317:self.resize_exit=True;m.emu_stop();return
        if rva in [0x32dd0,0x3363d]:
            if rva==0x32dd0:
                sp=m.reg_read(self.x.UC_X86_REG_RSP);args=[m.reg_read(self.x.UC_X86_REG_RDX)&0xffffffff,m.reg_read(self.x.UC_X86_REG_XMM2)&MASK,m.reg_read(self.x.UC_X86_REG_XMM3)&MASK]
                sl,tp,comment,expiration=struct.unpack('<4Q',m.mem_read(sp+40,32));self.extra_event(40,args+[sl,tp],[self.read_text(m.reg_read(self.x.UC_X86_REG_RCX)),self.read_text(comment)],True)
            else:self.open_covered.add(rva)
        if 0x32dd0<=rva<0x336c8:self.open_covered.add(rva)
        # Only observe; the parent stop point227c0 is outside this slice.
        return super().visit(m,address,size,user)
    def call(self,m,address,size,user):
        if self.phase!='loop':return super().call(m,address,size,user)
        api=self.apis[address];x=self.x;c=self.row;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));arg=r('RDX');prop=arg&0xffffffff
        def integer(v):m.reg_write(x.UC_X86_REG_RAX,v&MASK)
        def current():require(0<=self.selected_order<len(c['orders']),'NO_RESIZE_SELECTION');return c['orders'][self.selected_order]
        if api==501:self.extra_event(23,[c['order_total']]);integer(c['order_total']);return
        if api==502:
            i=signed(arg,32);ticket=c['orders'][i]['ticket'] if 0<=i<len(c['orders']) else 0
            if ticket:self.selected_order=i
            self.extra_event(24,[i,ticket,self.selected_order]);integer(ticket);return
        if api==505:
            i=next((i for i,v in enumerate(c['orders']) if v['ticket']==arg),-1);ok=int(i>=0 and c['orders'][i]['select_ok']!=0)
            if ok:self.selected_order=i
            self.extra_event(27,[arg,ok,self.selected_order]);integer(ok);return
        if api==506:
            prop=r('R8')&0xffffffff;require(prop==16,'GUARD_DOUBLE_PROPERTY');v=current()['point']
            self.extra_event(28,[prop,v],[self.read_text(arg)]);m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',v));m.reg_write(x.UC_X86_REG_XMM0,v);return
        if api==308:
            v=current();m.mem_write(r('R8')+8,struct.pack('<2Q',v['bid'],v['ask']));self.extra_event(29,[v['tick_ok'],v['bid'],v['ask']],[self.read_text(arg)]);integer(v['tick_ok']);return
        if api==415 and r('R8')&0xffffffff==32:
            value=current()['freeze'];self.extra_event(30,[32,value],[self.read_text(arg)]);integer(value);return
        if api==503:
            require(prop in [2,4,15],'RESIZE_ORDER_INT');value=current()[{2:'expiration',4:'type',15:'magic'}[prop]]
            self.extra_event(25,[prop,value,self.selected_order]);integer(value);return
        if api==504:
            require(prop in [0,16],'RESIZE_ORDER_STRING');value=current()['symbol' if prop==0 else 'comment'];self.extra_event(26,[prop,self.selected_order],[value])
            m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,0 if value is None else self.string(value)));return
        if api==507:
            require(prop in [7,9,12,13],'RESIZE_ORDER_DOUBLE');value=current()[{7:'volume',9:'price',12:'sl',13:'tp'}[prop]]
            self.extra_event(31,[prop,value,self.selected_order]);m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value);return
        if api==415 and r('R8')&0xffffffff in [33,50,49]:
            prop=r('R8')&0xffffffff;value=c[{33:'execution',50:'filling',49:'auto_expiration'}[prop]]
            self.extra_event(41,[prop,value],[self.read_text(arg)]);integer(value);return
        if api==602:
            prop=r('R8')&0xffffffff;require(prop in [71,49],'RESIZE_REF_PROPERTY');key='order' if prop==71 else 'expiration';value=c[key+'_flags'];ok=c[key+'_ok']
            self.extra_event(42,[prop,value,ok],[self.read_text(arg)]);m.mem_write(r('R9'),struct.pack('<q',value));integer(ok);return
        if api==603:
            require(r('R8')&0xffffffff==0x58,'CAST_TYPE');value,reply=self.casts[c['id']];require(arg==value==c['percent'],'CAST_VALUE')
            self.extra_event(43,[arg,0x58],[reply]);m.mem_write(r('R9'),struct.pack('<IQ',0,self.string(reply)));return
        if api==604:self.extra_event(44,[prop]);require(prop==1000,'SLEEP_TIME');return
        if api==304 and arg==2:
            sp=r('RSP');count=r('R8')&0xffffffff;require(1<=count<=3,'PRINT_COUNT');values=[]
            for j in range(count):
                tag=r('R9')&0xffffffff if j==0 else struct.unpack('<I',m.mem_read(sp+32+16*j,4))[0];require(tag==0x590008,'PRINT_TYPE')
                values.append(self.read_text(struct.unpack('<Q',m.mem_read(sp+40+16*j,8))[0]))
            self.extra_event(32,[count],values);return
        return super().call(m,address,size,user)
    def run_resize(self,c):
        self.row=copy.deepcopy(c);self.case=self.row['prelude'];self.changed=False;self.phase='idle'
        self.current_index=c['index'];self.live_symbol=c['symbol'];self.resize_changed=False;self.extra=bytearray();self.resize_exit=False
        m,x=self.m,self.x;self.cursor=0x70001000;self.allocs=self.frees=0;self.selected=-1
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        self.seed();self.frame=0x5001f000;m.mem_write(self.frame,bytes(0x300));m.reg_write(x.UC_X86_REG_RSP,self.frame)
        m.mem_write(self.base+0x6a3b4,b'\0')
        m.reg_write(x.UC_X86_REG_RBP,self.base+0x5c0);m.reg_write(x.UC_X86_REG_R12,self.base+0x5c0);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        for off,value in [(0x67918,c['symbol']),(0x6a428,'XAUUSD_NOCOST_V2')]:m.mem_write(self.base+off,struct.pack('<IQ',0,0 if value is None else self.string(value)))
        m.mem_write(self.base+0x66a80,struct.pack('<8Q',*c['volumes']));m.mem_write(self.base+0x678f4,struct.pack('<I',c['index']))
        m.mem_write(self.base+0x6a5e8,bytes([c['virtual']]));m.mem_write(self.base+0x62528,struct.pack('<Q',c['percent']));m.mem_write(self.base+0x677f8,struct.pack('<Q',0x1122334455667788))
        self.phase='loop';m.emu_start(self.base+0x1a817,0x60000000,timeout=10000000,count=2000000);require(self.resize_exit,'RESIZE_NO_EXIT')
        raw=struct.pack('<i',c['id'])+bytes(self.extra)+struct.pack('<i',0)+self.snapshot()
        raw+=struct.pack('<2Q',self.selected_order&MASK,struct.unpack('<Q',m.mem_read(self.base+0x677f8,8))[0])+bytes(m.mem_read(self.base+0x65dd0,1600))
        raw+=struct.pack('<Q',self.current_index)+bytes(m.mem_read(self.base+0x66a80,64))+text(self.read_text(self.base+0x67918))
        return raw
def identity():
    helpers=dict(stops.identity(1,p)['helpers_sha256'])
    for f in [Path(__file__),Path(shared_cases.__file__),Path(cleanup.__file__)]:helpers[f.relative_to(ROOT).as_posix()]=sha(f)
    return dict(original_ex5_sha256=p.head.validation.original_hash(1),tool_sha256=sha(Path(__file__)),helpers_sha256=helpers,
      sources_sha256={f.relative_to(SOURCE).as_posix():sha(f) for f in p.pub.closure(SOURCE/SCRIPT,SOURCE)})
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','mql5','original','compare']);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,40}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity();header=struct.pack('<4i',MAGIC,1,len(rows),200)
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');require(not(folder/'mql5-results.bin').exists(),'RESULT_EXISTS');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));require(b['target']==SCRIPT and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot1-evaluation-pending-resize'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('resize-'+a.run+'.set');ini=MT/('resize-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1EvaluationPendingResizeCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin','cast-results.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),cast_results_sha256=sha(folder/'cast-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');casts=read_casts(folder/'cast-results.bin',len(rows));o=Original(casts);raw=bytearray(header)
        for c in rows:
            try:raw+=o.run_resize(c)
            except Exception as e:raise RuntimeError('CASE '+str(c['id'])+' RIP '+hex(o.m.reg_read(o.x.UC_X86_REG_RIP))+' '+repr(e)) from e
        require(0x3363d in o.open_covered,'OPEN_DID_NOT_SEND');(folder/'original-results.bin').write_bytes(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),resize_instructions=len(o.resize_covered),open_instructions=len(o.open_covered),cast_results_sha256=sha(folder/'cast-results.bin'),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),resize_instructions=len(o.resize_covered))));return
    for name in ['original','mql5']:
        r=json.loads((folder/(name+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(name+'-results.bin')) and r['cast_results_sha256']==sha(folder/'cast-results.bin'),'RUN_CHANGED')
    left=(folder/'original-results.bin').read_bytes();right=(folder/'mql5-results.bin').read_bytes();ok=left==right;at=next((i for i,(x,y) in enumerate(zip(left,right)) if x!=y),min(len(left),len(right)))
    result=dict(cases=len(rows),matched=len(rows) if ok else None,failed=0 if ok else None,identical=ok,first_different_byte=None if ok else at,bytes=[len(left),len(right)],**SCOPE,limits=LIMITS);save(folder/'comparison.json',result);print(json.dumps(result));raise SystemExit(not ok)
if __name__=='__main__':main()
