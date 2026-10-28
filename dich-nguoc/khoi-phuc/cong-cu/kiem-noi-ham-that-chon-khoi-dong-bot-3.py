"""Run bot 3 real DST and currency bodies inside startup 0x3840..0x4580.

prepare RUN; mql5 RUN --build BUILD; original RUN; compare RUN.
Run MQL5 first: only terminal calendar/math/string replies are supplied to native.
Every API argument, state before each call and final state must match exactly.
"""
import calendar,copy,hashlib,importlib.util,inspect,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,file):
    s=importlib.util.spec_from_file_location(name,ROOT/'cong-cu'/file);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
sel=module('live_selection_contract','kiem-noi-chon-khoi-dong-bot-3.py');b=sel.b
currency=module('live_selection_currency','kiem-doi-tien-bot-1-3.py')
require,sha=b.require,b.sha
DST_SHA='89a100acb20d937bc0b7f9ec261baf1ec1c62d4c5a469f643cac144cb6b92db8'
CURRENCY_SHA='7c425c07ba2bc4ff9bc68ac7082bec2e6278582e9189e1f0c9641c43005823b6'
OLD_IDENTITY=sel.identity;BASE_CASE=sel.cases()[0]
def stamp(y,m,d,seconds=43200):return calendar.timegm((y,m,d,0,0,0))+seconds
def cases():
    rows=[]
    def add(tag,changes=None,**inputs):
        c=copy.deepcopy(BASE_CASE);c.update(id=len(rows),tag=tag,error=len(rows)%2)
        c.pop('selection');c['texts']=['The Gold Reaper','','old comment','old symbol','XAUUSD.a']
        for name,value in (dict(Frequency=5,Risk=1234)|(changes or {})).items():c['values'][next(i for i,f in enumerate(b.FIELDS) if f[0]==name)]=value
        c['sdk']=dict(clocks=[stamp(2026,6,1)]*4,balance=2000.,currencies=['USD'],prices=[2.]*4);c['sdk'].update(inputs);rows.append(c);return c
    for year in [1986,1987,2006,2007,2024,2026,2100]:
        for month,day in [(1,1),(3,7),(3,8),(3,9),(4,1),(4,5),(4,6),(6,1),(10,25),(10,31),(11,1),(11,2),(12,31)]:add('clock-calendar',{'Frequency':0},clocks=[stamp(year,month,day)]*4)
    for times in [[stamp(2026,3,8,86399),stamp(2026,3,9,0),stamp(2026,3,9,1),stamp(2026,3,9,2)],
                  [stamp(2006,6,1),stamp(2007,6,1),stamp(2006,6,1),stamp(2026,6,1)],
                  [stamp(2026,10,31),stamp(2026,10,31),stamp(2026,11,1),stamp(2026,11,2)]]:add('clock-changes-between-reads',clocks=times)
    for unit in currency.CURRENCIES:
        for suffix in ['', '.a']:
            c=add('currency-routes',currencies=[unit]);c['texts'][1]=suffix
    for unit in ['EUR','JPY','CNH','CNY']:
        for rates in [[0.,2.,2.,2.],[-1.,2.,2.,2.],[0.,0.,2.,2.],[1.1,1.3,1.7,1.9]]:add('fresh-rate-and-fallback',currencies=[unit],prices=rates)
    for units in [['USD','EUR','eur','JPY','jpy','VND'],['EUR','USD','GBP','gbp','CNH','cnh','USD']]:add('fresh-currency-reads',currencies=units)
    for mask in range(8):
        for amount in [1099.49,1099.5,1100.,1100.5,1866.5,1867.,2699.5,2700.,2700.5]:
            add('rounded-selection-thresholds',{f'Thresholds[{i}]':(mask>>i)&1 for i in range(3)},balance=amount)
    for freq in [-2147483648,-1,0,1,2,3,4,5,6,7,2147483647]:
        for risk in [0,1234]:
            c=add('frequency-and-risk',{'Frequency':freq,'Risk':risk})
            for i in range(9):c['values'][next(j for j,f in enumerate(b.FIELDS) if f[0]==f'Manual[{i}]')]=11+23*i
    for amount in [-10000.5,-1.5,-.5,-0.,0.,.5,1.5,10000.5,float('nan'),float('inf'),-float('inf')]:add('amount-rounding-and-special',balance=amount)
    for dd in [0.,-30.,float('nan'),float('inf'),-float('inf')]:add('drawdown-special',{'BootPanel.allowed_dd':dd})
    return rows
def encoded(rows):
    raw=bytearray(struct.pack('<3i',b.MAGIC,1,len(rows)))
    for c in rows:
        raw+=sel.OLD_ENCODE([c])[12:];r=c['sdk'];raw+=struct.pack('<4qQ',*r['clocks'],b.bits(r['balance']))
        raw+=struct.pack('<i',len(r['currencies']))+b''.join(b.text(t) for t in r['currencies'])
        raw+=struct.pack('<i',len(r['prices']))+b''.join(struct.pack('<Q',b.bits(v)) for v in r['prices'])
    return bytes(raw)
def fixtures(raw,count):
    out=[]
    for record in b.records(raw,count):
        at=0;events=[]
        def take(fmt):
            nonlocal at
            result=struct.unpack_from('<'+fmt,record,at);at+=struct.calcsize('<'+fmt);return result
        def text():
            nonlocal at
            n=take('i')[0];require(-1<=n<=10000,'SDK_TEXT_SIZE');value=None if n<0 else record[at:at+2*n].decode('utf-16-le');at+=max(0,2*n);return value
        while at<len(record):
            take('Q'*(len(b.FIELDS)+1))
            for _ in b.TEXTS:text()
            start=at;api=take('i')[0]
            if at==len(record):break
            if api==99:args=(text(),);error=None
            elif api==101:args=take('q');error=take('Q')[0]
            elif api==102:args=(*take('qQ'),struct.pack('<8i',*take('8i')));error=take('Q')[0]
            elif api==103:args=take('3Q');error=take('Q')[0]
            elif api==104:args=(*take('2q'),text(),text(),text());error=take('Q')[0]
            elif api==105:args=(text(),take('q')[0]);error=take('Q')[0]
            elif api==106:args=take('2Q');error=take('Q')[0]
            elif api==107:args=(take('Q')[0],text());error=take('Q')[0]
            elif api==108:args=(text(),*take('QqQ'));error=take('Q')[0]
            else:raise RuntimeError('UNEXPECTED_SDK_RECORD '+str(api))
            events.append(dict(api=api,args=args,error=error,raw=record[start:at]))
        require(at==len(record),'SDK_RECORD_TRAILING');out.append(events)
    return out
class Native(sel.Native):
    def __init__(self,records):
        super().__init__();self.fixtures=records;self.sdk_calls=0;self.dst_entries=0;self.currency_entries=0
        for start,end,digest in [(0x7e20,0x82f7,DST_SHA),(0x8300,0xe0b5,CURRENCY_SHA)]:require(hashlib.sha256(bytes(self.m.mem_read(self.base+start,end-start))).hexdigest()==digest,'BUSINESS_CHILD_CHANGED')
        self.sdk_apis={0x7ff6846f1c40:101,0x7ff6846f1f60:102,0x7ff6849c9970:103,self.print_api:104,0x7ff6846ed370:105,0x7ff6846b7370:106,0x7ff6846b7410:107,0x7ff6846f3d40:108,0x7ff6842b59a0:200}
        hooked=set(self.apis)|set(self.selection_apis)|{self.print_api}
        for address in self.sdk_apis:
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.m.mem_write(address,b'\xc3')
            if address not in hooked:self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.currency_muls=[0x87a3,0x8a9f,0x8d9f,0xae1f,0xb11f,0xb41f,0xb71f,0xba1f,0xbd1f,0xc01f,0xc31f,0xc61f,0xc91f,0xcc1f,0xcf1f,0xd21f,0xd51f,0xd81f]
        self.currency_divs=[0x9212,0x9522,0x9832,0x9b42,0x9e52,0xa332,0xa812,0xab22]
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        md=Cs(CS_ARCH_X86,CS_MODE_64)
        for off in self.currency_muls+self.currency_divs+[0xdb11]:
            ins=next(md.disasm(bytes(self.m.mem_read(self.base+off,15)),self.base+off))
            expected=('mulsd','xmm7, xmm6') if off in self.currency_muls else ('divsd','xmm7, xmm0') if off in self.currency_divs else ('mulsd','xmm6, qword ptr [rbx]')
            require((ins.mnemonic,ins.op_str)==expected,'CURRENCY_ARITHMETIC_CHANGED')
            self.m.hook_add(self.uc.UC_HOOK_CODE,self.currency_math,begin=self.base+off,end=self.base+off)
    def currency_math(self,m,address,size,user):
        off=address-self.base;x=self.x;dest=x.UC_X86_REG_XMM6 if off==0xdb11 else x.UC_X86_REG_XMM7;left=m.reg_read(dest)
        right=struct.unpack('<Q',m.mem_read(m.reg_read(x.UC_X86_REG_RBX),8))[0] if off==0xdb11 else m.reg_read(x.UC_X86_REG_XMM0 if off in self.currency_divs else x.UC_X86_REG_XMM6)&b.MASK
        if off in self.currency_divs:value=self.divide(left&b.MASK,right);self.div_count+=1
        else:value=self.host.mul(left&b.MASK,right);self.mul_count+=1
        m.reg_write(dest,(left&~b.MASK)|value);m.reg_write(x.UC_X86_REG_RIP,address+size)
    def next(self,api):
        require(self.sdk_position<len(self.records),'EXTRA_SDK_CALL '+str(api));r=self.records[self.sdk_position];self.sdk_position+=1
        require(r['api']==api,'SDK_ORDER '+str((self.case['id'],r['api'],api)))
        self.events+=self.state()+r['raw'];self.sdk_calls+=1;return r
    def call(self,m,address,size,user):
        if address==self.base+0x7e20:self.dst_entries+=1;return
        if address==self.base+0x8300:self.currency_entries+=1;return
        api=self.sdk_apis.get(address)
        if api is None:return sel.ctx.Native.call(self,m,address,size,user)
        x=self.x;reg=lambda n:m.reg_read(getattr(x,'UC_X86_REG_'+n))
        if api==200:raise RuntimeError('UNEXPECTED_NATIVE_RUNTIME_ERROR '+hex(reg('RDX')))
        if api==104 and reg('RDX')==2:api=99
        r=self.next(api);v=r['args']
        if api!=103:require(reg('RCX')==self.gate['ctx'],'SDK_CONTEXT')
        if api==101:
            require(reg('RDX')==0 and v[0]==self.case['sdk']['clocks'][min(self.clock_index,3)],'SDK_CLOCK');self.clock_index+=1;m.reg_write(x.UC_X86_REG_RAX,v[0]&b.MASK)
        elif api==102:
            require(reg('RDX')==(v[0]&b.MASK),'SDK_TIME_STRUCT_ARGUMENT');m.mem_write(reg('R8'),v[2]);m.reg_write(x.UC_X86_REG_RAX,v[1])
        elif api==103:
            require((reg('XMM0')&b.MASK,reg('XMM1')&b.MASK)==v[:2],'SDK_MOD_ARGUMENTS');m.reg_write(x.UC_X86_REG_XMM0,v[2])
        elif api in [99,104]:
            sp=reg('RSP');desc=struct.unpack('<Q',m.mem_read(sp+40,8))[0]
            if api==99:
                require((reg('R8'),reg('R9'))==(1,0x590008) and (self.read_text(desc) or '')==v[0],'SDK_PRINT');self.prints+=1
            else:
                require((reg('RDX'),reg('R8'),reg('R9'))==(0x174,3,0x59000a),'SDK_CONCAT_CALL')
                year=struct.unpack('<i',m.mem_read(sp+56,4))[0];literal=struct.unpack('<Q',m.mem_read(sp+72,8))[0]
                require((year,self.read_text(desc) or '',self.read_text(literal) or '')==(v[0],v[2],v[3]),'SDK_CONCAT_ARGUMENTS')
                require(struct.unpack('<I',m.mem_read(sp+48,4))[0]==0x520004 and struct.unpack('<I',m.mem_read(sp+64,4))[0]==0x590008,'SDK_CONCAT_TYPES')
                m.mem_write(desc,struct.pack('<IQ',0,self.string(v[4])));m.reg_write(x.UC_X86_REG_RAX,v[1]&b.MASK)
        elif api==105:
            require((self.read_text(reg('RDX')) or '')==v[0],'SDK_DATE_TEXT');m.reg_write(x.UC_X86_REG_RAX,v[1]&b.MASK)
        elif api==106:
            require(reg('RDX')==v[0]==37 and v[1]==b.bits(self.case['sdk']['balance']),'SDK_BALANCE');m.mem_write(self.base+0x1d6e48,struct.pack('<Q',v[1]))
        elif api==107:
            require(reg('RDX')==v[0]==36,'SDK_CURRENCY');values=self.case['sdk']['currencies'];require(v[1]==values[min(self.currency_index,len(values)-1)],'SDK_CURRENCY_REPLY');self.currency_index+=1
            m.mem_write(self.base+0x1d6e3c,struct.pack('<IQ',0,self.string(v[1])))
        elif api==108:
            require((self.read_text(reg('RDX')) or '',reg('R8')&0xffffffff,reg('R9')&0xffffffff)==(v[0],v[1],v[2]&0xffffffff),'SDK_PRICE_ARGUMENTS')
            values=self.case['sdk']['prices'];require(v[3]==b.bits(values[min(self.price_index,len(values)-1)]),'SDK_PRICE_REPLY');self.price_index+=1
            m.mem_write(self.base+0x1d6e48,struct.pack('<Q',v[3]));m.reg_write(x.UC_X86_REG_XMM0,v[3])
        if r['error'] is not None:m.mem_write(self.base+0x1d6e10,struct.pack('<I',r['error']))
    def run(self,c):
        self.records=self.fixtures[c['id']];self.sdk_position=self.clock_index=self.currency_index=self.price_index=0
        dst_before,currency_before=self.dst_entries,self.currency_entries
        inputs={n:v for (n,_,_),v in zip(b.FIELDS,c['values'])};expected_currency=int(inputs['Frequency']==5 and inputs['Risk']==1234)
        result=super().run(c);require(self.sdk_position==len(self.records),'SDK_NOT_CONSUMED')
        require(self.dst_entries-dst_before==1 and self.currency_entries-currency_before==expected_currency,'BUSINESS_CHILD_NOT_EXECUTED_EXACTLY')
        return result
def identity():
    current=OLD_IDENTITY();src=ROOT/'bot-cua-toi-3/source/MQL5';script=src/'Scripts/bot-cua-toi-3/Bot3StartupSelectionLiveCheck.mq5'
    current['sources_sha256']={p.relative_to(src).as_posix():sha(p) for p in b.pub.closure(script,src)}
    for p in [Path(__file__),Path(currency.__file__)]:current['helpers_sha256'][p.relative_to(ROOT).as_posix()]=sha(p)
    current.update(native_dst_sha256=DST_SHA,native_currency_sha256=CURRENCY_SHA);return current
runner=module('live_selection_runner','kiem-ngu-canh-khoi-dong-bot-1.py')
source=inspect.getsource(runner.main).replace("['generate','prepare','mql5','original','compare']","['prepare','mql5','original','compare']")
source=source.replace('Bot1StartupContextCheck','Bot3StartupSelectionLiveCheck').replace('Bot1','Bot3').replace('bot1-startup-context','bot3-startup-selection-live').replace('bot1','bot3').replace('bot-cua-toi-1','bot-cua-toi-3')
source=source.replace('o=Native();',"o=Native(fixtures((folder/'mql5-results.bin').read_bytes(),len(rows)));")
source=source.replace('host_mulsd=o.mul_count','host_mulsd=o.mul_count,host_divsd=o.div_count,sdk_calls=o.sdk_calls,dst_entries=o.dst_entries,currency_entries=o.currency_entries')
source=source.replace('Caller live-in XMM6=0 and non-null string-return buffer supplied','Actual DST/currency bodies run; terminal SDK replies and non-null string-return buffer supplied')
exec(compile(source,__file__,'exec'),b.__dict__)
b.cases=cases;b.encoded=encoded;b.Native=Native;b.identity=identity;b.fixtures=fixtures
b.SCOPE=dict(b.SCOPE,dst_child_reply_supplied=False,currency_child_reply_supplied=False,native_dst_body_executed=True,native_currency_body_executed=True,terminal_sdk_replies_supplied=True,currency_division_errors_tested=False)
if __name__=='__main__':b.main()
