"""Compare evaluator HEAD 20ef0..211ea and its two exits with compiled MQL5.

prepare|original|mql5(--build)|compare RUN. Original instructions and string
helper run; server time, TimeToStruct result and MQLInfoInteger(7) are supplied.
Initial calendar scratch is supplied, including unchanged data on SDK failure.
"""
import argparse,datetime,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
HOME=Path(__file__).resolve().parents[1];ROOT=HOME.parent;MASK=(1<<64)-1;MAGIC=0x45484433
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path);obj=importlib.util.module_from_spec(spec);spec.loader.exec_module(obj);return obj
entry=module('evaluation_head_entry',ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py')
validation=module('evaluation_head_original',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py')
pub=module('evaluation_head_pub',ROOT/'cong-cu/kiem-ban-git-quan-ly.py');require=pub.require
SOURCE=HOME/'source/MQL5';SCRIPT='Scripts/bot-cua-toi-3/Bot3EvaluationHeadCheck.mq5'
MT=ROOT.parent/'.local/mt5-bot3-thread-20261025'
FIELDS=['route','index','caller_flag','server_time']+['calendar.'+n for n in ['year','mon','day','hour','min','sec','day_of_week','day_of_year']]
FIELDS+=['calls.server','calls.struct','calls.info','call_hash','selected_null']
RECORD=struct.Struct('<i'+'Q'*len(FIELDS))
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,whole_evaluator_complete=False,full_ea=False,
 native_head_executed=True,string_helper_intercepted=False,terminal_replies_supplied=True,original_ex5_changed=False)
LIMITS=['Only HEAD from20ef0 to211ea/216e5 executes; no day/session/tick/order/position logic or complete EA.',
 'Server time, MQLInfo7, successful/failed calendar reply, initial calendar scratch and successful allocation are supplied.',
 'Native NULL, heap-empty and literal-empty inputs are distinct; MQL represents the two empty variants with empty text. Selection and complete UTF-16 output/null comparison are checked.']
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def save(path,value):
    with path.open('x',encoding='utf-8',newline='\n') as f:json.dump(value,f,ensure_ascii=False,indent=2)
def cases():
    rows=[]
    for kind,text in [(0,''),(1,''),(2,''),(1,'XAUUSD'),(1,'Vàng 🚀'),(1,'x'*300)]:
        for other_kind,other in [(0,''),(1,''),(1,'ALT'),(1,'Vàng.ALT')]:
            for flag in [0,1,255]:
                for info in [-1,0,1]:
                    for ok in [0,1]:
                        i=len(rows);rows.append(dict(id=i,index=[0,8,0xffffffff][i%3],caller_flag=[0,1,255][(i//3)%3],
                          flag=flag,info=info,struct_ok=ok,now=[0,1709164800,1792713600][(i//7)%3],symbol_kind=kind,symbol=text,
                          other_kind=other_kind,other=other,calendar=[(1 if i%2==0 else -1)*(1000+i*10+j) for j in range(8)]))
    return rows
def pack_text(value):
    raw=value.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
        raw+=struct.pack('<iI4iq2i8i',c['id'],c['index'],c['caller_flag'],c['flag'],c['info'],c['struct_ok'],c['now'],c['symbol_kind'],c['other_kind'],*c['calendar'])
        raw+=pack_text(c['symbol'])+pack_text(c['other'])
    return raw
def event(h,value):
    for b in struct.pack('<Q',value):h=((h^b)*0x100000001b3)&MASK
    return h
class Original(entry.Original):
    def __init__(self):
        super().__init__(3);self.covered=set()
        require(hashlib.sha256(bytes(self.m.mem_read(self.base+0x20ef0,0x211ea-0x20ef0))).hexdigest()=='5c7b757b6a0965ee4044679c7fa3138a99550e7dce7dfb08c0de47df027638f8','HEAD_BYTES_CHANGED')
        require(bytes(self.m.mem_read(self.base+0x59d14,4))==bytes(4),'EMPTY_LITERAL_CHANGED')
        eb=next(a for a,n in self.apis.items() if n==1)-0x7d3c40
        for address,api in [(eb+0x7d1ce0,300),(eb+0x7d1f60,301),(eb+0x7c0fd0,302)]:
            require(address not in self.apis,'SDK_ALREADY_REGISTERED')
            if not any(lo<=address<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(address&~4095,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
        self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x20ef0,end=self.base+0x216e5)
    def visit(self,m,address,size,user):
        rva=address-self.base
        if rva in [0x211ea,0x216e5]:self.exit=rva;m.emu_stop();return
        self.covered.add(rva)
    def call(self,m,address,size,user):
        api=self.apis[address];c=self.case;x=self.x
        if api in [100,101]:return super().call(m,address,size,user)
        require(api in [300,301,302],'UNEXPECTED_HEAD_API');self.calls.append(api-299)
        if api==300:
            require(m.reg_read(x.UC_X86_REG_RDX)==0,'SERVER_CALENDAR_OVERLOAD');m.reg_write(x.UC_X86_REG_RAX,c['now']&MASK)
        elif api==301:
            require(m.reg_read(x.UC_X86_REG_RDX)==c['now'] and m.reg_read(x.UC_X86_REG_R8)==self.frame+0x58,'STRUCT_ARGUMENTS')
            if c['struct_ok']:
                dt=datetime.datetime.fromtimestamp(c['now'],datetime.timezone.utc)
                values=[dt.year,dt.month,dt.day,dt.hour,dt.minute,dt.second,(dt.weekday()+1)%7,dt.timetuple().tm_yday-1]
                m.mem_write(self.frame+0x58,struct.pack('<8i',*values))
            m.reg_write(x.UC_X86_REG_RAX,c['struct_ok'])
        else:
            require(m.reg_read(x.UC_X86_REG_RDX)==7,'INFO_PROPERTY');m.reg_write(x.UC_X86_REG_RAX,c['info']&MASK)
    def run(self,c):
        self.case=c;self.cursor=0x70001000;self.allocs=self.frees=0;self.calls=[];self.exit=None;m,x=self.m,self.x
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
        for j in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(j)),0)
        sp=0x50020000-0x108;self.frame=sp-64-0x288;m.mem_write(self.frame,bytes(0x300));m.mem_write(sp,struct.pack('<Q',0x60000000))
        m.mem_write(self.frame+0x58,struct.pack('<8i',*c['calendar']));m.reg_write(x.UC_X86_REG_RSP,sp);m.reg_write(x.UC_X86_REG_RCX,c['index']);m.reg_write(x.UC_X86_REG_RDX,c['caller_flag'])
        m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
        for off,kind,text in [(0x74958,c['symbol_kind'],c['symbol']),(0x1d6e28,c['other_kind'],c['other'])]:
            pointer=0 if kind==0 else self.base+0x59d18 if kind==2 else self.string(text)
            m.mem_write(self.base+off,struct.pack('<IQ',0,pointer))
        m.mem_write(self.base+0x1d6d08,bytes([c['flag']]))
        m.emu_start(self.base+0x20ef0,0x60000000,timeout=3000000,count=100000)
        require(self.exit in [0x211ea,0x216e5],'HEAD_DID_NOT_REACH_EXIT')
        require(m.reg_read(x.UC_X86_REG_RSP)==self.frame,'FRAME_CHANGED')
        index=struct.unpack('<I',m.mem_read(self.frame+0xb0,4))[0];flag=bytes(m.mem_read(self.frame+0x88,1))[0]
        now=struct.unpack('<q',m.mem_read(self.frame+0xf8,8))[0];cal=struct.unpack('<8i',m.mem_read(self.frame+0x58,32))
        pointer=struct.unpack('<Q',m.mem_read(self.frame+0x114,8))[0];length=struct.unpack('<I',m.mem_read(pointer-4,4))[0] if pointer else 0
        require(length<=10000,'SELECTED_TEXT_LENGTH');selected=bytes(m.mem_read(pointer,length*2)).decode('utf-16-le') if pointer else ''
        h=0xcbf29ce484222325
        for k in self.calls:h=event(h,k)
        values=[int(self.exit==0x216e5),index,flag,now,*cal,*[self.calls.count(k) for k in [1,2,3]],h,int(pointer==0)]
        return RECORD.pack(c['id'],*[v&MASK for v in values])+pack_text(selected)
def identity():
    helpers=[Path(__file__),ROOT/'cong-cu/kiem-gia-vao-bot-1-3.py',ROOT/'cong-cu/kiem-muc-gia-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-hop-le-bot-1-3.py',ROOT/'cong-cu/kiem-khoi-luong-bot-1-3.py',ROOT/'cong-cu/kiem-ban-git-quan-ly.py',HOME/'phan-tich/luot-20261023-data/metadata/import.json']
    return dict(original_ex5_sha256=validation.original_hash(3),tool_sha256=sha(Path(__file__)),sources_sha256={p.relative_to(SOURCE).as_posix():sha(p) for p in pub.closure(SOURCE/SCRIPT,SOURCE)},helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in helpers})
def parse(raw,count):
    require(raw[:16]==struct.pack('<4i',MAGIC,1,count,len(FIELDS)),'RESULT_HEADER');at=16;out=[]
    for _ in range(count):
        values=list(RECORD.unpack_from(raw,at));at+=RECORD.size;n=struct.unpack_from('<i',raw,at)[0];at+=4;require(0<=n<=10000,'TEXT_SIZE')
        out.append(values+[raw[at:at+n*2].decode('utf-16-le')]);at+=n*2
    require(at==len(raw),'RESULT_SIZE');return out
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args();require(re.fullmatch('[a-z0-9-]{1,40}',a.run),'BAD_RUN')
    folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=identity();header=struct.pack('<4i',MAGIC,1,len(rows),len(FIELDS))
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),values=len(FIELDS))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==encode(rows),'IDENTITY_CHANGED')
    if a.mode=='original':
        require(not(folder/'original-results.bin').exists(),'RESULT_EXISTS');o=Original();raw=bytearray(header)
        for c in rows:raw+=o.run(c)
        (folder/'original-results.bin').write_bytes(raw);save(folder/'original-run.json',dict(**current,cases=len(rows),instructions=len(o.covered),result_sha256=sha(folder/'original-results.bin'),**SCOPE));print(json.dumps(dict(cases=len(rows),instructions=len(o.covered))));return
    if a.mode=='mql5':
        require(a.build and re.fullmatch('[a-z0-9-]{1,50}',a.build),'BUILD_REQUIRED');require(not(folder/'mql5-results.bin').exists(),'RESULT_EXISTS');receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']==SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for n,h in current['sources_sha256'].items():require(sha(MT/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_DIFFERS '+n)
        binary=MT/'MQL5'/Path(SCRIPT).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_DIFFERS')
        files=MT/'MQL5/Files/bot3-evaluation-head'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/('b3-head-'+a.run+'.set');ini=MT/('b3-head-'+a.run+'.ini')
        with preset.open('x',encoding='utf-16') as f:f.write('CheckRun='+a.run+'\n')
        with ini.open('x',encoding='utf-16') as f:f.write('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-3\\Bot3EvaluationHeadCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n')
        proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for n in ['mql5-results.bin','script-status.bin']:
            with (folder/n).open('xb') as f:f.write((files/n).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    for n in ['original-run.json','mql5-run.json']:
        value=json.loads((folder/n).read_text());require(all(value[k]==v for k,v in current.items()) and value['result_sha256']==sha(folder/n.replace('-run.json','-results.bin')),'RUN_CHANGED')
    native=parse((folder/'original-results.bin').read_bytes(),len(rows));actual=parse((folder/'mql5-results.bin').read_bytes(),len(rows));failed=[]
    for c,n,r in zip(rows,native,actual):
        if n!=r:failed.append(dict(id=c['id'],symbol_kind=c['symbol_kind'],symbol=c['symbol'],other_kind=c['other_kind'],other=c['other'],differences={k:[x,y] for k,x,y in zip(['id']+FIELDS+['selected_text'],n,r) if x!=y}))
    report=dict(cases=len(rows),matched=len(rows)-len(failed),failed=len(failed),first_failures=failed[:20],**SCOPE,limits=LIMITS);save(folder/'comparison.json',report);print(json.dumps(report,ensure_ascii=False));raise SystemExit(bool(failed))
if __name__=='__main__':main()
