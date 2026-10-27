"""Compare evaluator prelude -> pending cleanup -> initial stops, native children.

prepare|original|mql5(--build)|compare RUN. Only SDK replies and successful
allocation are supplied. All200 queue cells and full trade snapshots are compared.
"""
import argparse,copy,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
stops=module('pending_cleanup_stops',ROOT/'cong-cu/kiem-bo-sung-muc-dung-bot-1-3.py');p=stops.prefix(3)
require=stops.require;sha=stops.sha;save=stops.save;MASK=stops.MASK;text=stops.text;bits=stops.bits;signed=stops.signed
MAGIC=0x45504333;SCRIPT='Scripts/bot-cua-toi-3/Bot3EvaluationPendingCleanupCheck.mq5';SOURCE=HOME/'source/MQL5';MT=p.MT
SCOPE=dict(stops.SCOPE,native_pending_cleanup_executed=True,native_delete_child_executed=True)
LIMITS=['Native evaluator20ef0 -> session/tick prelude -> pending cleanup -> initial position levels to227c0. Native delete32450, modify32a90 and send950 execute; no child reply is substituted.',
 'Terminal replies, initial trade/queue state and successful allocation are supplied. Send log_level=0; no later manager, complete EA, actual broker order or allocation-fault proof.']
def order(**kwargs):
    r=dict(ticket=11,magic=42,type=4,symbol='XAUUSD',select_ok=1,point=bits(.01),bid=bits(100.),ask=bits(100.25),price=bits(110.),freeze=5,tick_ok=1);r.update(kwargs);return r
def base():
    row=stops.base();row.update(enabled=0,orders=[order()],order_total=1,table=[[bits(i+1000.),bits(-i-.25)] for i in range(100)],symbol='XAUUSD')
    row['table'][0]=[bits(11.),bits(-.0)];return row
def cases():
    out=[];prefix_cases=p.cases()
    def add(c,tag,caller=1):
        i=len(out);c['id']=i;c['tag']=tag;c['prelude']=copy.deepcopy(prefix_cases[[0,81,1475,1519][i%4]]);v=c['prelude'];v['id']=i;v['caller_flag']=caller
        v['symbol_kind']=int(c['symbol'] is not None);v['symbol']=c['symbol'] or '';v['other_kind']=1;v['other']='ALT';c['mutation']=0
        out.append(c)
    for caller in [0,1,255]:
        for total in [-2,-1,0,1,2,3]:
            c=base();c.update(order_total=total,orders=[order(),order(ticket=12,type=5),order(ticket=0)]);add(c,'caller-count',caller)
    for kind in [-1,0,1,2,3,4,5,6,7,8,0x100000000,0x100000001,0x100000002,0x100000004,-(1<<63),(1<<63)-1]:
        c=base();c['orders'][0]['type']=kind;add(c,'low32-type')
    for magic in [-2147483648,-1,0,42,2147483647]:
        for value in [magic,magic+(1<<32),-1,0,42]:
            c=base();c['magic']=magic;c['orders'][0]['magic']=value;add(c,'signed-magic')
    for symbol in [None,'','XAUUSD','xauusd','Vàng 🚀','X'*300]:
        for actual in [None,'','XAUUSD','xauusd','Vàng 🚀','X'*300]:
            c=base();c['symbol']=symbol;c['orders'][0]['symbol']=actual;add(c,'symbol-null-empty')
    for ticket in [0,1,11,(1<<53)-1,1<<53,(1<<53)+1,(1<<63)-1,1<<63,(1<<64)-1]:
        for index in [-1,0,1,50,99,100]:
            c=base();c['orders'][0]['ticket']=ticket
            recorded=bits(float(signed(ticket)))
            if 0<=index<100:c['table'][index]=[recorded,0x7ff8000000000123]
            if index==100:c['table'][0]=[recorded,bits(-1.)];c['table'][99]=[recorded,bits(-2.)]
            add(c,'table-signed-ticket')
    for index in [0,99]:
        for value in [bits(float('nan')),bits(float('inf')),bits(float('-inf')),bits(-0.),bits(11.),bits(10.999999999999998),bits(11.000000000000002)]:
            c=base();c['table'][0]=[bits(-100.),bits(-1.)];c['table'][index]=[value,0xfff8000000000456];add(c,'ordered-table-match')
    for selected in [0,1]:
        for stopped in [-1,0,1]:
            for accepted in [0,1]:
                for async_ in [0,255]:
                    c=base();c.update(stopped=stopped,accepted=accepted,write_result=1-accepted,async_mode=async_);c['orders'][0]['select_ok']=selected;add(c,'delete-send-branches')
    for kind in [2,3,4,5,6,7]:
        for price in [99.,100.,100.2,100.25,100.3,110.]:
            for point in [0.,.01,1.,float('nan')]:
                c=base();c['orders'][0].update(type=kind,price=bits(price),point=bits(point));add(c,'freeze-boundary')
    for i in range(8):
        c=base();c.update(enabled=1,total=2,positions=[stops.position(),stops.position(ticket=12,type=1)],order_total=4,
          orders=[order(),order(ticket=12,type=5,price=bits(90.)),order(ticket=13,magic=-1),order(ticket=0)],accepted=i%2,async_mode=255*((i//2)%2),write_result=(i//4)%2)
        c['table'][99]=[bits(12.),0xfff8000000000456];add(c,'cleanup-and-stops')
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=stops.encode([c],p)[12:]+struct.pack('<2i',c['order_total'],len(c['orders']))
        for v in c['orders']:
            raw+=struct.pack('<Qqqi5Qqi',v['ticket'],v['magic'],v['type'],v['select_ok'],v['point'],v['bid'],v['ask'],v['price'],0,v['freeze'],v['tick_ok'])+text(v['symbol'])
        for row in c['table']:raw+=struct.pack('<2Q',*row)
    return raw
BaseOriginal=stops.original_class(3,p)
class Original(BaseOriginal):
    def __init__(self):
        super().__init__();self.cancel_covered=set()
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+0x32450,0x32a84-0x32450))).hexdigest()=='9c734e0a55e2cbbe1b567281e7d9a93329834ecd8b29d5054e63ab2b7122eede','DELETE_BYTES_CHANGED')
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        for off,api in [(0x7d81a0,501),(0x7d81f0,502),(0x7d8310,503),(0x7d83a0,504),(0x7d8240,505),(0x7c2890,506),(0x7d8280,507)]:
            a=eb+off;existed=a in self.apis
            if not any(lo<=a<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(a&~4095,4096)
            self.apis[a]=api;self.m.mem_write(a,b'\xc3')
            if not existed:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=a,end=a)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x32450,end=self.base+0x32a83)
    def seed(self):
        super().seed();self.selected_order=-1
        self.m.mem_write(self.base+0x72e10,b''.join(struct.pack('<2Q',*row) for row in self.row['table']))
    def visit(self,m,address,size,user):
        rva=address-self.base
        if self.phase=='loop' and 0x32450<=rva<0x32a84:
            self.cancel_covered.add(rva)
            if rva==0x32450:self.extra_event(21,[m.reg_read(self.x.UC_X86_REG_RCX)],snapshot=True)
        if self.phase=='loop' and rva==0x214a3:self.extra_event(22,[m.reg_read(self.x.UC_X86_REG_RAX)&0xffffffff],snapshot=True)
        return super().visit(m,address,size,user)
    def call(self,m,address,size,user):
        if self.phase!='loop':return super().call(m,address,size,user)
        api=self.apis[address];x=self.x;c=self.row;r=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n));arg=r('RDX')
        def integer(v):m.reg_write(x.UC_X86_REG_RAX,v&MASK)
        def double(v):m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',v));m.reg_write(x.UC_X86_REG_XMM0,v)
        def current():require(0<=self.selected_order<len(c['orders']),'NO_SELECTED_ORDER');return c['orders'][self.selected_order]
        if api not in [501,502,503,504,505,506,507,308] and not(api==415 and r('R8')&0xffffffff==32):return super().call(m,address,size,user)
        require(r('RCX')==0x171514ca538,'SDK_CONTEXT_CHANGED')
        if api==501:self.extra_event(23,[c['order_total']]);integer(c['order_total'])
        elif api==502:
            i=signed(arg,32);ticket=c['orders'][i]['ticket'] if 0<=i<len(c['orders']) else 0
            if ticket:self.selected_order=i
            self.extra_event(24,[i,ticket,self.selected_order]);integer(ticket)
        elif api==503:
            prop=arg&0xffffffff;require(prop in [4,15],'ORDER_INTEGER_PROPERTY');value=current()['type' if prop==4 else 'magic']
            self.extra_event(25,[prop,value,self.selected_order]);integer(value)
        elif api==504:
            require(arg&0xffffffff==0,'ORDER_STRING_PROPERTY');value=current()['symbol'];self.extra_event(26,[0,self.selected_order],[value])
            m.mem_write(self.base+self.cfg['string_result'],struct.pack('<IQ',0,0 if value is None else self.string(value)))
        elif api==505:
            i=next((i for i,v in enumerate(c['orders']) if v['ticket']==arg),-1);ok=int(i>=0 and c['orders'][i]['select_ok']!=0)
            if ok:self.selected_order=i
            self.extra_event(27,[arg,ok,self.selected_order]);integer(ok)
        elif api==506:
            prop=r('R8')&0xffffffff;require(prop==16,'GUARD_DOUBLE_PROPERTY');value=current()['point'];self.extra_event(28,[prop,value],[self.read_text(arg)]);double(value)
        elif api==308:
            v=current();pointer=r('R8');m.mem_write(pointer+8,struct.pack('<2Q',v['bid'],v['ask']))
            self.extra_event(29,[v['tick_ok'],v['bid'],v['ask']],[self.read_text(arg)]);integer(v['tick_ok'])
        elif api==415:
            v=current()['freeze'];self.extra_event(30,[32,v],[self.read_text(arg)]);integer(v)
        else:
            require(arg&0xffffffff==9,'ORDER_DOUBLE_PROPERTY');v=current()['price'];self.extra_event(31,[9,v,self.selected_order]);double(v)
    def run_joined(self,c):
        before=super().run_joined(c)
        return before+struct.pack('<Q',self.selected_order&MASK)+bytes(self.m.mem_read(self.base+0x72e10,1600))
def identity():
    helpers=stops.identity(3,p)['helpers_sha256']
    for f in [Path(__file__),HOME/'phan-tich/huy-lenh-cho/cancel-20261024-r1/analysis.json']:
        helpers[f.relative_to(ROOT).as_posix()]=sha(f)
    return dict(original_ex5_sha256=p.head.validation.original_hash(3),tool_sha256=sha(Path(__file__)),
      helpers_sha256=helpers,sources_sha256={f.relative_to(SOURCE).as_posix():sha(f) for f in p.pub.closure(SOURCE/SCRIPT,SOURCE)})
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,40}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity();header=struct.pack('<4i',MAGIC,1,len(rows),len(p.FIELDS))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    b=json.loads((folder/'baseline.json').read_text());require(all(b[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');o=Original();raw=bytearray(header)
        for c in rows:
            try:raw+=o.run_joined(c)
            except Exception as e:raise RuntimeError('CASE '+str(c['id'])+' RIP '+hex(o.m.reg_read(o.x.UC_X86_REG_RIP))+' '+repr(e)) from e
        require(0x32450 in o.cancel_covered and 0x950 in o.helper_covered and 0x32a90 in o.helper_covered,'CHILD_NOT_EXECUTED')
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',dict(**current,cases=len(rows),delete_instructions=len(o.cancel_covered),joined_instructions=len(o.joined),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),delete_instructions=len(o.cancel_covered))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');require(not(folder/'mql5-results.bin').exists(),'RESULT_EXISTS');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));require(b['target']==SCRIPT and b['errors']==b['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==b['sources_sha256'][n]==h,'BUILD_SOURCE_DIFFERS')
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-evaluation-pending-cleanup'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('cleanup-'+a.run+'.set');ini=MT/('cleanup-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3EvaluationPendingCleanupCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for name in ['original','mql5']:
        r=json.loads((folder/(name+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    left=(folder/'original-results.bin').read_bytes();right=(folder/'mql5-results.bin').read_bytes();ok=left==right;at=next((i for i,(x,y) in enumerate(zip(left,right)) if x!=y),min(len(left),len(right)))
    result=dict(cases=len(rows),matched=len(rows) if ok else None,failed=0 if ok else None,identical=ok,first_different_byte=None if ok else at,bytes=[len(left),len(right)],**SCOPE,limits=LIMITS)
    save(folder/'comparison.json',result);print(json.dumps(result));raise SystemExit(not ok)
if __name__=='__main__':main()
