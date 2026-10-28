"""Compare both unchanged bot2 currency bodies with compiled MQL5.

prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Only account/price replies and successful runtime allocation are supplied.
Exact result bits, ordered currency reads, price arguments/replies and error agree.
"""
import argparse,ctypes,hashlib,importlib.util,json,re,shutil,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];HOME=ROOT/'bot-cua-toi-2';SRC=HOME/'source/MQL5'
MT=ROOT.parent/'.local/mt5-bot1-thread-20261025';MAGIC=0x43553231;MASK=(1<<64)-1
SCRIPT='Scripts/bot-cua-toi-2/Bot2CurrencyConversionCheck.mq5'
BASE=0x253f2620000;CTX=0x253ee076f88;SDK=0x7ff79ff60000
FUNCTIONS={1:(0x371f0,0x3cfa5,'4050f3200cf58dbd9549c2de44578abbdc70ee25ef447daed32872243ebf596b'),0:(0x45400,0x4a936,'674cd1b5d38dd53b82fe03ccc412c287a1cfb39ee42fe79a99c968ca7999e7c3')}
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
dst=module('currency2_capture','kiem-gio-mua-he-bot-2.py');legacy=module('currency2_cases','kiem-doi-tien-bot-1-3.py');host=module('currency2_cpu','kiem-lich-su-chien-luoc-bot-1-3.py');pub=module('currency2_publication','kiem-ban-git-quan-ly.py')
require=pub.require
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(p,value):
    with p.open('x',encoding='utf-8',newline='\n') as f:json.dump(value,f,ensure_ascii=False,indent=2);f.write('\n')
def bits(v):return struct.unpack('<Q',struct.pack('<d',v))[0]
def number(v):return struct.unpack('<d',struct.pack('<Q',v))[0]
def text(value):
    raw=value.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
SCOPE=dict(full_ea=False,whole_bot_complete=False,whole_manager_complete=False,native_currency_bodies_executed=True,native_string_helpers_executed=True,native_code_bytes_unchanged=True,ordered_sdk_records_compared=True,host_cpu_arithmetic=True,terminal_replies_supplied=True,allocation_success_supplied=True,allocation_failures_tested=False,authorization_executed=False)
def cases():
    out=[]
    def add(group,direction,currencies,prices=None,amount=9.5,suffix=''):
        out.append(dict(id=len(out),group=group,to_usd=direction,amount=bits(amount),suffix=suffix,currencies=currencies,prices=[bits(v) for v in (prices or [2.,2.,2.,2.])],error=0 if len(out)%2==0 else 65536+731))
    for direction in [0,1]:
        for currency in legacy.CURRENCIES:
            for suffix in ['', '.a','đuôi🚀']:
                for rates in [[2.,2.],[0.,2.],[-1.,2.],[0.,0.,2.,2.]]:add('currency-and-price-routes',direction,[currency],rates,suffix=suffix)
        for currency in ['USD','EUR','JPY','CNH','XEM']:
            for amount in [-10000.5,-1.5,-.5,-0.,0.,.5,1.5,10000.5,1e19,float('inf'),-float('inf')]:add('amount-boundaries',direction,[currency],[1.,1.],amount,suffix='.a')
        for a in [0x7ff8000000000041,0xfff8000000000042,0x7ff0000000000043,0xfff0000000000044]:
            for p in [0x7ff8000000000051,0xfff8000000000052]:
                for currency in ['EUR','JPY']:add('nan-operand-order',direction,[currency],[2.,number(p)],number(a))
        for seq in [['USD','EUR','GBP','USD'],['EUR','USD','GBP','gbp','CNH','cnh','CNY','cny','USD'],['JPY','jpy','YEN','yen','SGD','sgd','BTC','btc','USD']]:add('fresh-currency-between-reads',direction,seq,[1.1,1.3,1.7,1.9,2.1,2.3])
        for currency in ['EUR','JPY','CNH','CNY']:
            for rates in [[1.1,1.3,1.7,1.9],[float('nan'),2.,2.,2.],[0.,2.,3.,4.]]:add('changing-rates-and-fallback',direction,[currency],rates)
        for currency in ['EUR','JPY']:
            add('negative-second-rate',direction,[currency],[2.,-2.])
        for currency in (['EUR','BTC'] if direction else ['JPY','CHF']):add('multiply-zero-second-rate',direction,[currency],[2.,0.])
        add('long-utf16-suffix',direction,['EUR'],suffix='m'*300+'🚀')
    prefix=['VND','USD']+['USD']*10
    for suffix in [['CHF','CZK','czk','USD'],['CZK','czk','CHF','USD'],['CHF','CHF','USD'],['chf','chf','CHF','USD']]:add('duplicated-chf-fresh-reads',0,prefix+suffix,[2.,3.,4.,5.])
    return out
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<2iQ',c['id'],c['to_usd'],c['amount'])+text(c['suffix'])+struct.pack('<i',len(c['currencies']))+b''.join(text(v) for v in c['currencies'])
        raw+=struct.pack('<i',len(c['prices']))+b''.join(struct.pack('<Q',v) for v in c['prices'])+struct.pack('<I',c['error'])
    return bytes(raw)
class Native(dst.Original):
    def __init__(self):
        dst.verify_pins();super().__init__({});require(self.base==BASE,'CAPTURE_BASE_CHANGED')
        meta=json.loads((HOME/'phan-tich/luot-20261026-data-r2/metadata/import.json').read_text())
        self.ranges=[(int(f['begin_rva'],16),int(f['end_rva'],16)) for f in meta['functions'] if int(f['begin_rva'],16) in [0,0x60,0x1e0,0x5c0,0x371f0,0x45400]]
        require(len(self.ranges)==6,'CURRENCY_RUNTIME_RANGES_MISSING')
        for lo,hi,digest in FUNCTIONS.values():require(hashlib.sha256(bytes(self.m.mem_read(BASE+lo,hi-lo))).hexdigest()==digest,'CURRENCY_BODY_CHANGED')
        self.helpers=bytes(self.m.mem_read(BASE,0x7d8));self.host=host.HostAddition();self.cpu={};self.arithmetic={};self.cpu_calls=0
        for k,(op,code) in enumerate([('addsd','f20f58c1'),('subsd','f20f5cc1'),('mulsd','f20f59c1'),('divsd','f20f5ec1')]):
            address=self.host.address+512+64*k;raw=self.host.CODE.replace(bytes.fromhex('f20f58c1'),bytes.fromhex(code));ctypes.memmove(address,raw,len(raw));self.cpu[op]=ctypes.WINFUNCTYPE(ctypes.c_uint64,ctypes.c_uint64,ctypes.c_uint64)(address)
        require(self.cpu['mulsd'](bits(3.),bits(2.))==bits(6.) and self.cpu['divsd'](bits(6.),bits(2.))==bits(3.),'CPU_CALIBRATION')
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        md=Cs(CS_ARCH_X86,CS_MODE_64)
        for lo,hi,_ in FUNCTIONS.values():
            for i in md.disasm(bytes(self.m.mem_read(BASE+lo,hi-lo)),BASE+lo):
                if i.mnemonic in self.cpu:self.arithmetic[i.address]=(i.mnemonic,i.op_str);self.m.hook_add(self.uc.UC_HOOK_CODE,self.calculate,begin=i.address,end=i.address)
        for address,api in {SDK+0x797410:110,SDK+0x7d3d40:111,SDK+0x3959a0:200}.items():
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
    def close(self):self.host.close()
    def calculate(self,m,address,size,user):
        op,args=self.arithmetic[address];left,right=args.split(', ');reg=getattr(self.x,'UC_X86_REG_'+left.upper());value=m.reg_read(reg)
        if right.startswith('xmm'):operand=m.reg_read(getattr(self.x,'UC_X86_REG_'+right.upper()))&MASK
        else:
            target=0
            for term in right.removeprefix('qword ptr [').removesuffix(']').split(' + '):
                if '*' in term:a,b=term.split('*');target+=m.reg_read(getattr(self.x,'UC_X86_REG_'+a.upper()))*int(b,0)
                elif term.startswith('0x'):target+=int(term,16)
                else:target+=m.reg_read(getattr(self.x,'UC_X86_REG_'+term.upper()))
            operand=struct.unpack('<Q',m.mem_read(target,8))[0]
        m.reg_write(reg,(value&~MASK)|self.cpu[op](value&MASK,operand));m.reg_write(self.x.UC_X86_REG_RIP,address+size);self.cpu_calls+=1
    def supply(self,descriptor,value):
        raw=value.encode('utf-16-le');n=len(raw)//2;ptr=self.cursor;self.cursor+=(12+len(raw)+2+15)&~15
        require(self.cursor<0x70200000,'SDK_HEAP_LIMIT');self.m.mem_write(ptr,struct.pack('<3I',n+1,1,n)+raw+b'\0\0');self.live_allocs.add(ptr);self.m.mem_write(descriptor,struct.pack('<IQ',n+1,ptr+12))
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address];reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))
        require(reg('RCX')==CTX,'CURRENCY_SDK_CONTEXT')
        if api==100:
            n=reg('RDX')&0xffffffff;require(n<=16384,'STRING_ALLOCATION_SIZE');capacity=max(1,n);ptr=self.cursor;self.cursor+=(12+2*(capacity+1)+15)&~15;require(self.cursor<0x70200000,'NATIVE_HEAP_LIMIT')
            m.mem_write(ptr,struct.pack('<3I',capacity,0,0)+bytes(2*(capacity+1)));self.live_allocs.add(ptr);self.native_allocs.add(ptr);m.reg_write(x.UC_X86_REG_RAX,ptr);return
        if api==101:
            ptr=reg('RDX');require(ptr in self.live_allocs,'FREE_NOT_LIVE');self.live_allocs.remove(ptr);self.native_allocs.discard(ptr);return
        if api==110:
            require(reg('RDX')==36,'CURRENCY_PROPERTY');values=self.case['currencies'];reply=values[min(self.currency_index,len(values)-1)];self.currency_index+=1
            self.events+=struct.pack('<2i',1,36)+text(reply);self.supply(BASE+0x6843c,reply);return
        if api==111:
            symbol=self.text(reg('RDX'));frame=reg('R8')&0xffffffff;shift=reg('R9')&0xffffffff;require((frame,shift)==(16408,1),'CURRENCY_PRICE_ARGS')
            values=self.case['prices'];reply=values[min(self.price_index,len(values)-1)];self.price_index+=1;self.events+=struct.pack('<i',2)+text(symbol)+struct.pack('<2iQ',frame,shift,reply)
            m.mem_write(BASE+0x68448,struct.pack('<Q',reply));m.reg_write(x.UC_X86_REG_XMM0,reply);return
        if api==200:self.fatal=reg('RDX');m.emu_stop();return
        raise RuntimeError('UNEXPECTED_CURRENCY_API '+str(api))
    def run(self,c):
        self.case=c;self.events=bytearray();self.currency_index=self.price_index=0;self.fatal=0;self.cursor=0x70001000;self.live_allocs=set();self.native_allocs=set();m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        self.supply(BASE+0x5e1f0,c['suffix']);m.mem_write(BASE+0x68410,struct.pack('<I',c['error']))
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        m.mem_write(0x50000000,bytes(0x20000));sp=0x5001fef8;m.mem_write(sp,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_XMM0,c['amount']);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        lo,hi,digest=FUNCTIONS[c['to_usd']];m.emu_start(BASE+lo,0x60000000,timeout=5000000,count=3000000)
        require(not self.fatal,'UNEXPECTED_CURRENCY_FAULT '+hex(self.fatal));require(m.reg_read(x.UC_X86_REG_RIP)==0x60000000,'CURRENCY_NOT_RETURNED');require(not self.native_allocs,'NATIVE_TEMPORARY_STRING_LEAK')
        require(bytes(m.mem_read(BASE,0x7d8))==self.helpers and hashlib.sha256(bytes(m.mem_read(BASE+lo,hi-lo))).hexdigest()==digest,'NATIVE_CODE_WAS_MODIFIED')
        self.events+=struct.pack('<iQI',0,m.reg_read(x.UC_X86_REG_XMM0)&MASK,struct.unpack('<I',m.mem_read(BASE+0x68410,4))[0]);return bytes(self.events)
def identity():
    dst.verify_pins();helpers=[Path(__file__),Path(dst.__file__),Path(legacy.__file__),Path(host.__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',HOME/'bang-chung/captures/luot-20261026-r1/capture.json',HOME/'phan-tich/luot-20261026-data-r2/metadata/import.json']
    return dict(original_ex5_sha256=dst.EX5_SHA,native_code_sha256=dst.CODE_SHA,native_functions={str(k):dict(start=hex(v[0]),end=hex(v[1]),sha256=v[2]) for k,v in FUNCTIONS.items()},sources_sha256={p.relative_to(SRC).as_posix():sha(p) for p in pub.closure(SRC/SCRIPT,SRC)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def records(raw,count):
    require(raw[:12]==struct.pack('<3i',MAGIC,1,count),'RESULT_HEADER');at=12;out=[]
    for i in range(count):
        cid,size=struct.unpack_from('<2i',raw,at);at+=8;require(cid==i and 16<=size<=len(raw)-at,'RESULT_BLOCK');out.append(raw[at:at+size]);at+=size
    require(at==len(raw),'RESULT_TRAILING');return out
def errors():
    ap=argparse.ArgumentParser();ap.add_argument('mode');ap.add_argument('run');ap.add_argument('--build',required=True);a=ap.parse_args();require(re.fullmatch('[a-z0-9-]{1,40}',a.run) and re.fullmatch('[a-z0-9-]+',a.build),'BAD_ERROR_RUN')
    current=identity();receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
    require(build['target']==SCRIPT and build['errors']==build['warnings']==0 and build['floating_point_dividers_check_requested'],'ERROR_BUILD_NOT_CLEAN')
    for n,h in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==h,'ERROR_SOURCE_CHANGED')
    binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'ERROR_BINARY_CHANGED')
    folder=HOME/'bang-chung/kiem-doi-tien'/a.run;folder.mkdir(parents=True,exist_ok=False);checks=[]
    for tag,direction,currency,rates in [('to-usd-jpy',1,'JPY',[2.,0.]),('to-usd-cnh-fallback',1,'CNH',[0.,2.,0.]),('from-usd-eur',0,'EUR',[2.,0.]),('from-usd-btc',0,'BTC',[2.,0.])]:
        c=dict(id=0,group=tag,to_usd=direction,amount=bits(9.5),suffix='.a',currencies=[currency],prices=[bits(v) for v in rates],error=0)
        out=folder/tag;out.mkdir();(out/'cases.bin').write_bytes(encode([c]));save(out/'cases.json',[c]);namespace=a.run+'-'+tag
        files=MT/'MQL5/Files/bot2-currency-full'/namespace;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('currency2-error-'+namespace+'.set');ini=MT/('currency2-error-'+namespace+'.ini')
        preset.write_text('CheckRun='+namespace+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-2\\Bot2CurrencyConversionCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        logs={p:p.stat().st_size for d in [MT/'MQL5/Logs',MT/'logs'] if d.is_dir() for p in d.glob('*.log')}
        process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('ERROR_MT5_TIMEOUT')
        lines=[]
        for d in [MT/'MQL5/Logs',MT/'logs']:
            for p in d.glob('*.log'):
                raw=p.read_bytes();at=logs.get(p,0);lines.extend(v for v in raw[at if at<=len(raw) else 0:].decode('utf-16-le',errors='replace').splitlines() if 'zero divide' in v.lower())
        require(code in [-1,0xffffffff] and not (files/'script-status.bin').exists() and bool(lines),'DIVISION_FAULT_NOT_OBSERVED')
        actual=(files/'mql5-results.bin').read_bytes();require(actual[:20]==struct.pack('<5i',MAGIC,1,1,0,0),'ERROR_RESULT_HEADER')
        native=Native()
        try:
            try:native.run(c)
            except ValueError as e:require(str(e).startswith('UNEXPECTED_CURRENCY_FAULT '),'UNEXPECTED_NATIVE_ERROR '+str(e))
            require(native.fatal&0xffffffff==0x1f7 and bytes(native.events)==actual[20:],'FAULT_CALL_SEQUENCE_DIFFERS')
            result=dict(tag=tag,native_code=hex(native.fatal),fatal_class='zero divide',exit_code=code,account_reads=native.currency_index,price_reads=native.price_index,ordered_calls_before_fault_byte_equal=True,no_normal_result=True,exact_final_fault_state_compared=False)
        finally:native.close()
        (out/'mql5-partial.bin').write_bytes(actual);(out/'runtime-lines.txt').write_text('\n'.join(lines)+'\n',encoding='utf-8');result.update(partial_sha256=sha(out/'mql5-partial.bin'),runtime_lines_sha256=sha(out/'runtime-lines.txt'));save(out/'verification.json',result);checks.append(result);print(json.dumps(result),flush=True)
    save(folder/'error-comparison.json',dict(cases=4,matched=4,failed=0,checks=checks,identity=current,build=a.build,build_receipt_sha256=sha(receipt),whole_bot_complete=False,full_ea=False,limits=['Four division faults only. Ordered SDK records before the fault and fatal class compared; exact fault state and allocator failure paths excluded.']))
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','mql5','original','compare']);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args();require(re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN')
    rows=cases();current=identity();folder=HOME/'bang-chung/kiem-doi-tien'/a.run;head=struct.pack('<3i',MAGIC,1,len(rows))
    if a.mode=='prepare':folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'cases.json',rows);save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    before=json.loads((folder/'baseline.json').read_text());require(all(before[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]+',a.build),'BUILD_REQUIRED');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_CHANGED')
        files=MT/'MQL5/Files/bot2-currency-full'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/('currency2-'+a.run+'.set');ini=MT/('currency2-'+a.run+'.ini')
        preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-2\\Bot2CurrencyConversionCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        records((folder/'mql5-results.bin').read_bytes(),len(rows));save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        native=Native();raw=bytearray(head);accounts=prices=0
        try:
            for c in rows:
                try:value=native.run(c)
                except Exception as e:raise RuntimeError('case='+str(c['id'])+' '+c['group']+' '+str(e)) from e
                raw+=struct.pack('<2i',c['id'],len(value))+value;accounts+=native.currency_index;prices+=native.price_index
        finally:native.close()
        with (folder/'original-results.bin').open('xb') as f:f.write(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),account_reads=accounts,price_reads=prices,cpu_arithmetic_calls=native.cpu_calls,result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),account_reads=accounts,price_reads=prices)));return
    data=[]
    for n in ['original','mql5']:
        r=json.loads((folder/(n+'-run.json')).read_text());require(all(r[k]==v for k,v in current.items()) and r['result_sha256']==sha(folder/(n+'-results.bin')),'RUN_CHANGED');data.append(records((folder/(n+'-results.bin')).read_bytes(),len(rows)))
    failed=[]
    for c,x,y in zip(rows,*data):
        if x!=y:failed.append(dict(id=c['id'],group=c['group'],first_difference=next((i for i,(v,w) in enumerate(zip(x,y)) if v!=w),min(len(x),len(y))),sizes=[len(x),len(y)]))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:12],**SCOPE,limits=['Both currency bodies only. SDK-owned string buffers and successful allocation supplied; allocation failures, division-fault cases and whole EA excluded.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(failed))
if __name__=='__main__':
    if len(sys.argv)>1 and sys.argv[1]=='errors':errors()
    else:main()
