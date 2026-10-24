"""Compare the complete100-row queue with supplied pending-builder outcomes.

Usage: kiem-hang-doi-bot-1-3.py prepare|mql5|original|compare BOT RUN [--build BUILD]
MQL5 first. No trading or actual sleep. Native queue/error/string helpers execute.
Pending-builder, Print and Sleep boundaries are recorded with exact typed arguments;
controlled input changes test re-reads. This is not the full queue+broker/EA proof.
Native memset is supplied only for its verified(queue-address,0,2400) contract.
"""
import argparse
import hashlib
import importlib.util
import json
import math
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x51554531
spec=importlib.util.spec_from_file_location('errors',Path(__file__).with_name('kiem-chuoi-loi-bot-1-3.py'))
errors=importlib.util.module_from_spec(spec);spec.loader.exec_module(errors)
send=errors.send;MT=send.MT;sha=send.sha;save=send.save;pack_text=send.pack_text
CFG={1:dict(fn=0x2e6d0,enabled=0x66420,orders=0x65470,results=0x65dd0,ask=0x67760,bid=0x67758,gap=0x66a70,sl=0x62498,tp=0x624a0,unit=0x66d98,anchor=0x67450,symbol=0x67918,comment=0x62470,last_error=0x6a410),
     3:dict(fn=0x3bb10,enabled=0x73468,orders=0x724b0,results=0x72e10,ask=0x747a0,bid=0x74798,gap=0x73ab0,sl=0x6d588,tp=0x6d590,unit=0x73dd8,anchor=0x74490,symbol=0x74958,comment=0x6d568,last_error=0x1d6e10)}
CONTEXT=['ask','bid','gap','sl','tp','unit']

def base(type_=4,index=0):
    row=dict(id=0,scenario=0,focus=index,enabled=1,error_count=0,last_error=0,ask=100.,bid=100.,gap=.1,sl=20.,tp=100.,unit=.01,anchor=1700000000,magic=-1,virtual=1,symbol='XAUUSD',comment='Recovery',orders=[[0.,0.,0.] for _ in range(100)],results=[[0.,-17.] for _ in range(100)],replies=[])
    row['orders'][index]=[101. if type_==4 else 99.,float(type_),.12];return row
def cases():
    out=[]
    def add(row,group):row.update(id=len(out),group=group);out.append(row)
    for flag in [0,1,2,3,255]:
        for direction in [4,5]:r=base(direction);r['enabled']=flag;add(r,'entry-guard')
    for direction in [4,5]:
        for index in [0,1,50,99]:add(base(direction,index),'row-order-boundary')
        for field in ['price','selector','volume','ask','bid','gap','sl','tp','unit']:
            values=[-math.inf,-1.,-0.,0.,math.nan,math.inf,1e19]
            if field=='selector':values += [4.,5.,math.nextafter(4.,0.),math.nextafter(4.,5.),math.nextafter(5.,4.),math.nextafter(5.,6.)]
            for value in values:
                r=base(direction)
                if field in ['price','selector','volume']:r['orders'][0][['price','selector','volume'].index(field)]=value
                else:r[field]=value
                add(r,'ordered-double-and-representation-'+field)
        for delta in [-1e-12,0.,1e-12]:
            r=base(direction);r['gap']=1.;r['orders'][0][0]=(101. if direction==4 else 99.)+delta;add(r,'strict-price-threshold')
        for pattern in range(8):
            r=base(direction)
            for i in range(100):r['results'][i]=[math.nan if pattern in [3,4] else (i+1.),-float(i)]
            if pattern==0:r['results'][0][0]=0.
            if pattern==1:r['results'][99][0]=-0.
            if pattern==2:r['results'][1][0]=0.
            if pattern==3:r['results'][99][0]=0.
            if pattern==5:r['results'][0][0]=math.inf
            if pattern==6:r['results'][0][0]=-math.inf
            if pattern==7:r['results'][0][0]=-1.
            add(r,'result-slot-scan-'+str(pattern))
        for accepted,error in [(1,132),(0,0),(0,3),(0,131),(0,-1)]:
            for counter in [0,0xffffffff]:
                r=base(direction);r.update(error_count=counter,replies=[[accepted,error]]);add(r,'initial-result-and-error')
        for replies in [[[0,132],[1,0]],[[0,132],[1,132],[0,0]],[[0,132],[0,132],[1,3]]]:
            r=base(direction);r['replies']=replies;add(r,'retry-ignores-return-after-first')
        for scenario in range(1,12):
            r=base(direction);r['scenario']=scenario
            if scenario in [5,9,11]:r['replies']=[[0,132],[1,132],[1,0]]
            if scenario in [2,10]:r['orders'][0][1]=4.;r['orders'][0][0]=201.;r['ask']=200.;r['gap']=0.;r['bid']=101.
            add(r,'mutation-boundary-'+str(scenario))
        for anchor in [0,-172801,9223372036854775807,-9223372036854775808]:
            r=base(direction);r['anchor']=anchor;add(r,'expiration-add64')
    r=base();r['orders']=[[101.+i,float(4 if i%2==0 else 5),.01*(i+1)] for i in range(100)];r['bid']=1000.;add(r,'all100-orders')
    r=base();r['orders']=[[101.+i,4.,.1] for i in range(100)];r['results']=[[i+1.,i+2.] for i in range(100)];add(r,'all100-no-result-space')
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for r in rows:
        raw+=struct.pack('<4iIi6dq2i',r['id'],r['scenario'],r['focus'],r['enabled'],r['error_count'],r['last_error'],*(r[k] for k in CONTEXT),r['anchor'],r['magic'],r['virtual'])
        raw+=pack_text(r['symbol'])+pack_text(r['comment'])
        raw+=struct.pack('<500d',*(v for name in ['orders','results'] for row in r[name] for v in row))
        raw+=struct.pack('<i',len(r['replies']))+b''.join(struct.pack('<2i',*v) for v in r['replies'])
    return raw
def read_cases(path):
    rd=send.Reader(path.read_bytes());magic,version,n=rd.take('3i')
    if (magic,version)!=(MAGIC,1):raise ValueError('CASE_HEADER_DIFFERS')
    out=[]
    for _ in range(n):
        values=rd.take('4iIi6dq2i');r=dict(zip(['id','scenario','focus','enabled','error_count','last_error',*CONTEXT,'anchor','magic','virtual'],values))
        r.update(symbol=rd.text(),comment=rd.text(),orders=[list(rd.take('3d')) for _ in range(100)],results=[list(rd.take('2d')) for _ in range(100)])
        count=rd.take('i')[0]
        if not 0<=count<=20:raise ValueError('INVALID_REPLY_COUNT')
        r['replies']=[list(rd.take('2i')) for _ in range(count)];out.append(r)
    if rd.pos!=len(rd.raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return out
def read_results(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('RESULT_HEADER_DIFFERS')
    out=[]
    for i in range(n):
        start=rd.pos;cid=rd.take('i')[0]
        if cid!=i:raise ValueError('RESULT_ID_DIFFERS')
        while True:
            api=rd.take('i')[0]
            if api==0:break
            if api==1:rd.text()
            elif api==2:rd.take('3i4dq');rd.text();rd.text()
            elif api==3:rd.take('i')
            else:raise ValueError('UNKNOWN_RESULT_EVENT')
        rd.take('iIi3i');rd.take('500d');rd.take('6dq2i');rd.text();rd.text();out.append(rd.raw[start:rd.pos])
    if rd.pos!=len(rd.raw):raise ValueError('RESULT_BYTES_NOT_EXACT')
    return out

class Original(errors.Original):
    def __init__(self,bot,casts):
        super().__init__(bot,[]);self.queue_cfg=CFG[bot];self.signed_casts=casts;self.pending_cfg=send.pending.CFG[bot];self.bit=False
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data';meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        fn=next(f for f in meta['functions'] if int(f['begin_rva'],16)==self.queue_cfg['fn']);self.ranges.append((self.queue_cfg['fn'],int(fn['end_rva'],16)))
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40;extra={eb+0x7b17c0:48,eb+0xacad20:49,self.base+self.pending_cfg['fn']:50}
        for page in {a&~0xfff for a in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for address,kind in extra.items():
            if kind in [48,49]:self.m.mem_write(address,b'\xc3')
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
    def read(self,key,kind):return struct.unpack('<'+kind,self.m.mem_read(self.base+self.queue_cfg[key],struct.calcsize('<'+kind)))[0]
    def write(self,key,kind,value):self.m.mem_write(self.base+self.queue_cfg[key],struct.pack('<'+kind,value))
    def write_guard(self,m,access,address,size,value,user):
        if self.executing:
            for key,n in [('enabled',1),('orders',2400),('results',1600)]:
                start=self.base+self.queue_cfg[key]
                if start<=address and address+size<=start+n:return
        return super().write_guard(m,access,address,size,value,user)
    def patch(self,api):
        s=self.case['scenario'];focus=self.base+self.queue_cfg['orders']+24*self.case['focus'];self.executing=False
        try:
            if api==2 and self.sends==1:
                if s==1:self.m.mem_write(focus,struct.pack('<d',struct.unpack('<d',self.m.mem_read(focus,8))[0]+.375))
                if s in [2,10]:self.m.mem_write(focus,struct.pack('<2d',99. if s==2 else -7.5,5.));self.write('bid','d',101. if s==2 else 0.)
                if s in [3,4]:self.write('enabled','B',2 if s==3 else 3)
                if s==7:self.m.mem_write(self.base+self.queue_cfg['results'],struct.pack('<4d',17.,111.,0.,222.))
            if (api==1 and self.prints==1 and s==6) or (api==3 and self.sleeps==1 and s==5):
                self.m.mem_write(focus,struct.pack('<3d',-7.5,6. if s==5 else 4.,.333))
                for key,value in [('sl',-2.5),('tp',3.75),('unit',.125),('ask',-99.),('bid',100.),('gap',10000.)]:self.write(key,'d',value)
                self.write('anchor','q',-172801);self.supply(self.base+self.queue_cfg['symbol'],'Vàng.x');self.supply(self.base+self.queue_cfg['comment'],'Vé mới')
            if (api==1 and self.prints==1 and s==8) or (api==3 and self.sleeps==1 and s==9):self.write('enabled','B',0)
            if api==3 and self.sleeps==1 and s==11:self.write('last_error','i',0)
        finally:self.executing=True
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;sp=m.reg_read(x.UC_X86_REG_RSP)
        if api==50:
            type_=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;volume=struct.pack('<Q',m.reg_read(x.UC_X86_REG_XMM2)&send.MASK);price=struct.pack('<Q',m.reg_read(x.UC_X86_REG_XMM3)&send.MASK)
            sl,tp,comment,expiry=struct.unpack('<2dQq',m.mem_read(sp+40,32));symbol=self.text(m.reg_read(x.UC_X86_REG_RCX));text=self.text(comment)
            magic=struct.unpack('<i',m.mem_read(self.base+self.pending_cfg['magic_input'],4))[0];virtual=m.mem_read(self.base+self.pending_cfg['virtual'],1)[0]
            self.trace+=struct.pack('<4i',2,type_,magic,virtual)+volume+price+struct.pack('<2dq',sl,tp,expiry)+pack_text(symbol)+pack_text(text)
            if self.case['replies']:
                if self.sends>=len(self.case['replies']):raise ValueError('EXTRA_NATIVE_SEND')
                accepted,error=self.case['replies'][self.sends]
            else:accepted,error=1,0
            self.sends+=1;self.executing=False;self.write('last_error','i',error);self.executing=True;self.patch(2)
            target=struct.unpack('<Q',m.mem_read(sp,8))[0];m.reg_write(x.UC_X86_REG_RAX,accepted);m.reg_write(x.UC_X86_REG_RSP,sp+8);m.reg_write(x.UC_X86_REG_RIP,target);return
        if api==48:
            ms=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff
            if ms!=2500:raise ValueError('SLEEP_DURATION_DIFFERS')
            self.trace+=struct.pack('<2i',3,ms);self.sleeps+=1;self.patch(3);return
        if api==49:
            destination=m.reg_read(x.UC_X86_REG_RCX)
            if destination!=self.base+self.queue_cfg['orders'] or m.reg_read(x.UC_X86_REG_RDX)!=0 or m.reg_read(x.UC_X86_REG_R8)!=2400:raise ValueError('QUEUE_MEMORY_FILL_ARGUMENTS_DIFFER')
            m.mem_write(destination,b'\0'*2400);m.reg_write(x.UC_X86_REG_RAX,destination);self.clears+=1;return
        if api==45:
            if m.reg_read(x.UC_X86_REG_RDX)!=2 or m.reg_read(x.UC_X86_REG_R8)!=1 or m.reg_read(x.UC_X86_REG_R9)!=0x590008:raise ValueError('QUEUE_PRINT_SHAPE_DIFFERS')
            text=self.text(struct.unpack('<Q',m.mem_read(sp+40,8))[0]);self.trace+=struct.pack('<i',1)+pack_text(text);self.prints+=1;self.patch(1);return
        if api==46:
            code=struct.unpack('<i',struct.pack('<I',m.reg_read(x.UC_X86_REG_RDX)&0xffffffff))[0]
            if m.reg_read(x.UC_X86_REG_R8)!=0x52 or code not in self.signed_casts:raise ValueError('QUEUE_SIGNED_CAST_NOT_MEASURED')
            self.supply(m.reg_read(x.UC_X86_REG_R9),self.signed_casts[code]);return
        return super().call(m,address,size,user)
    def run(self,row):
        self.executing=False;self.case=row;self.cursor=0x70001000;self.allocs=self.frees=0;self.sends=self.sleeps=self.prints=self.clears=0;self.trace=bytearray();m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.mem_write(0x50000000,b'\0'*0x20000);m.mem_write(self.base+self.send_cfg['slot'],b'\0'*12)
        for key,kind in [('enabled','B'),('last_error','i'),('anchor','q')]+[(key,'d') for key in CONTEXT]:self.write(key,kind,row[key])
        for key in ['orders','results']:m.mem_write(self.base+self.queue_cfg[key],b''.join(struct.pack('<'+'d'*len(values),*values) for values in row[key]))
        for key in ['symbol','comment']:self.supply(self.base+self.queue_cfg[key],row[key])
        m.mem_write(self.base+self.error_cfg['counter'],struct.pack('<I',row['error_count']));m.mem_write(self.base+self.pending_cfg['magic_input'],struct.pack('<i',row['magic']));m.mem_write(self.base+self.pending_cfg['virtual'],bytes([row['virtual']]))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top);self.executing=True
        try:m.emu_start(self.base+self.queue_cfg['fn'],0x60000000,timeout=5000000,count=3000000)
        finally:self.executing=False
        if m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise ValueError('QUEUE_DID_NOT_RETURN')
        if row['replies'] and self.sends!=len(row['replies']):raise ValueError('UNCONSUMED_SEND_REPLIES')
        if self.clears!=int(row['enabled']==1 and bool(self.read('enabled','B')&1)):raise ValueError('QUEUE_MEMORY_FILL_CALL_COUNT_DIFFERS')
        self.supply(self.base+self.send_cfg['slot'],'')
        if self.allocs!=self.frees:raise ValueError('QUEUE_OWNED_STRING_IMBALANCE '+str((self.allocs,self.frees)))
        counter=struct.unpack('<I',m.mem_read(self.base+self.error_cfg['counter'],4))[0]
        raw=struct.pack('<i',row['id'])+self.trace+struct.pack('<2iIi3i',0,self.read('enabled','B'),counter,self.read('last_error','i'),self.sends,self.sleeps,self.prints)
        for key,n in [('orders',2400),('results',1600)]:raw+=bytes(m.mem_read(self.base+self.queue_cfg[key],n))
        raw+=struct.pack('<6dq2i',*(self.read(key,'d') for key in CONTEXT),self.read('anchor','q'),row['magic'],row['virtual'])
        return raw+pack_text(self.text(self.base+self.queue_cfg['symbol']))+pack_text(self.text(self.base+self.queue_cfg['comment']))

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('mode',choices=['prepare','mql5','original','compare']);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('run');parser.add_argument('--build');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    home=ROOT/f'bot-cua-toi-{a.bot}';out=home/'bang-chung/kiem-hang-doi'/a.run
    if a.mode=='prepare':
        digest=send.pending.fill.validation.original_hash(a.bot);out.mkdir(parents=True,exist_ok=False);rows=cases();(out/'cases.bin').write_bytes(encode(rows))
        descriptions=json.loads(json.dumps(rows,allow_nan=True))
        for r in descriptions:
            for key in CONTEXT:r[key]=struct.pack('<d',r[key]).hex()
            for key in ['orders','results']:r[key]=[[struct.pack('<d',v).hex() for v in values] for values in r[key]]
        save(out/'cases.json',descriptions);save(out/'baseline.json',dict(cases=len(rows),original_ex5_sha256=digest,cases_sha256=sha(out/'cases.bin'),tool_sha256=sha(Path(__file__)),native_rvas=CFG[a.bot]))
        print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((out/'baseline.json').read_text());rows=read_cases(out/'cases.bin');n=len(rows)
    if sha(out/'cases.bin')!=baseline['cases_sha256'] or send.pending.fill.validation.original_hash(a.bot)!=baseline['original_ex5_sha256']:raise ValueError('INPUTS_CHANGED')
    if a.mode=='mql5':
        if not a.build or not re.fullmatch('[a-z0-9-]+',a.build):raise ValueError('BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PendingQueueCheck.mq5';binary=MT/'MQL5'/target.replace('.mq5','.ex5')
        if receipt['target']!=target or receipt['errors'] or receipt['warnings'] or sha(binary)!=receipt['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
        names=[target]+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PendingQueue','TradeSend','TradeMessages','PendingRequest','Filling','TradeErrors']]
        for name in names:
            if sha(home/'source/MQL5'/name)!=receipt['sources_sha256'][name]:raise ValueError('SOURCE_CHANGED '+name)
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-pending-queue'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-queue-{a.run}.set';preset.write_text(f'CheckRun={a.run}\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-queue-{a.run}.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PendingQueueCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        if code:raise RuntimeError('MT5_QUEUE_CHECK_FAILED '+str(code))
        for name in ['mql5-results.bin','last-error-calibration.bin']:shutil.copyfile(files/name,out/name)
        first,second=struct.unpack('<2I',(out/'last-error-calibration.bin').read_bytes())
        if first==0 or first!=second:raise ValueError('GET_LAST_ERROR_CHANGED_ON_SECOND_READ')
        save(out/'mql5-run.json',dict(exit_code=code,seconds=round(time.monotonic()-start,2),script_sha256=sha(binary),build_receipt_sha256=sha(receipt_path),last_error_read_twice=[first,second],hashes={name:sha(out/name) for name in ['mql5-results.bin','last-error-calibration.bin']}))
        print(json.dumps({'cases':len(read_results(out/'mql5-results.bin',n))}));return
    if a.mode=='original':
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        directory=home/'bang-chung/kiem-chuoi-loi/errors-20261024-r2';prior=json.loads((directory/'comparison.json').read_text())
        if prior['failed'] or any(sha(directory/name)!=digest for name,digest in prior['hashes'].items()):raise ValueError('ERROR_HELPER_FIXTURES_NOT_VERIFIED')
        prior_cases=errors.read_cases(directory/'cases.bin');rd=send.Reader((directory/'cast-values.bin').read_bytes())
        if rd.take('3i')!=(errors.MAGIC,1,len(prior_cases)):raise ValueError('CAST_FIXTURE_HEADER_DIFFERS')
        casts={row['code']:rd.text() for row in prior_cases}
        if rd.pos!=len(rd.raw):raise ValueError('CAST_FIXTURE_LENGTH_DIFFERS')
        o=Original(a.bot,casts);start=time.monotonic();values=[]
        for row in rows:
            try:values.append(o.run(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,1,n)+b''.join(values))
        save(out/'original-run.json',dict(cases=n,seconds=round(time.monotonic()-start,2),result_sha256=sha(out/'original-results.bin'),tool_sha256=sha(Path(__file__)),cast_source_comparison_sha256=sha(directory/'comparison.json'),scope=__doc__))
        print(json.dumps({'cases':n}));return
    original=read_results(out/'original-results.bin',n);actual=read_results(out/'mql5-results.bin',n);failures=[]
    for i,(x,y) in enumerate(zip(original,actual)):
        if x!=y:
            pos=next((j for j,(a_,b_) in enumerate(zip(x,y)) if a_!=b_),min(len(x),len(y)));failures.append(dict(id=i,first_different_byte=pos,original=x[pos:pos+16].hex(),mql5=y[pos:pos+16].hex()))
    result=dict(cases=n,matched=n-len(failures),failed=len(failures),first_failures=failures[:10],hashes={name:sha(out/name) for name in ['cases.bin','original-results.bin','mql5-results.bin']},scope='Complete100-row queue, ordered typed builder/Print/Sleep boundaries, all500 queue/result doubles, context, flag, error/count; finite132 retry sequences and controlled boundary changes. Builder results supplied; not full combined queue+builder/terminal/EA.')
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))

if __name__=='__main__':main()
