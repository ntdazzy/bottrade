"""So sánh đoạn kết thúc quản lý vị thế ảo bot 1 với mã máy gốc.

Chỉ chạy phần sau 0x29de9/0x2d55a đến điểm quay vòng vị thế; không phải toàn EA.
"""
import argparse, importlib.util, itertools, json, re, shutil, struct, subprocess, hashlib, time
from pathlib import Path
HOME=Path(__file__).resolve().parents[1]; ROOT=HOME.parent
vspec=importlib.util.spec_from_file_location('vstart',Path(__file__).with_name('check-management-virtual-start.py')); v=importlib.util.module_from_spec(vspec);vspec.loader.exec_module(v)
MAGIC=0x4d564646; MASK=(1<<64)-1
MT=(ROOT.parent/'.local/mt5-bot1-thread-20261025').resolve()
NAMES=['Include/bot-cua-toi-1/'+n for n in ['Bot1ManagementPrelude.mqh','Bot1ManagementVirtualFinish.mqh','Bot1PriceLevels.mqh','Bot1PositionModify.mqh','Bot1PositionClose.mqh','Bot1VirtualStops.mqh']]+['Scripts/bot-cua-toi-1/Bot1ManagementVirtualFinishCheck.mq5']
RESULT=struct.Struct('<4i5Qi2Q2i')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,x):
    with Path(p).open('x',encoding='utf-8') as f:json.dump(x,f,ensure_ascii=False,indent=2)
def bits(x):return struct.unpack('<Q',struct.pack('<d',x))[0]
def base():return dict(id=0,buy=1,scenario=0,ticket=7,open=100.,sl=95.,tp=120.,bid=99.,ask=101.,unit=.1,gap=.2,freeze=.1,level=95.,anchor=100.,cached=100.,copied=.5,point=.01,table_volume=1.,minimum=.01,high_enabled=1,before_open=1,shift=0,lock_start=0.,lock_extra=0.,mode=2,step_enabled=0,step_reference=0.,min_steps=1,step_distance=1.,counter=0,strategy_index=0,guard=1,close_tick=1,tick_ok=1,digits=2,changed=0,pattern=0)
def cases():
    rows=[]
    def add(c,g):c.update(id=len(rows),group=g);rows.append(c)
    vals=[-float('inf'),-0.,0.,.01,1.,100.,float('inf'),float('nan')]
    for buy in [0,1]:
      for level,bid,ask in [(95.,99.,101.),(99.,99.,101.),(100.,101.,99.),(float('nan'),99.,101.)]:
       for enabled in [0,1]:
        c=base();c.update(buy=buy,level=level,bid=bid,ask=ask,high_enabled=enabled);add(c,'high-low-boundary')
      for flag in [0,1,2,255]:
       for st in [0,1]:
        c=base();c.update(buy=buy,step_enabled=flag,step_reference=vals[st],lock_start=0.,counter=0);add(c,'counter-flags')
      for f in ['level','gap','freeze','unit','anchor','cached','copied','point','lock_start','lock_extra','step_distance']:
       for x in vals:
        c=base();c.update(buy=buy);c[f]=x;add(c,'numeric-'+f)
      for scen in range(1,8):
       c=base();c.update(buy=buy,scenario=scen,high_enabled=1,level=95. if buy else 105.,step_enabled=1,lock_start=1.,lock_extra=2.,counter=1);add(c,'api-reread-'+str(scen))
      for idx in [0,1,8]:
       c=base();c.update(buy=buy,strategy_index=idx,table_volume=0.);add(c,'index-volume')
      for guard in [0,1,2,255]:
       c=base();c.update(buy=buy,guard=guard,level=95. if buy else 105.);add(c,'guard')
      for ticket in [0,-1,(1<<53)+1,-(1<<63), (1<<63)-1]:
       c=base();c.update(buy=buy,ticket=ticket);add(c,'ticket')
      for counter in [-2147483648,-1,0,1,2147483647]:
       for minimum in [-1,0,1,2]:
        c=base();c.update(buy=buy,step_enabled=1,lock_start=0.,counter=counter,min_steps=minimum);add(c,'counter-overflow')
      for digits in [-1,0,2,8,15]:
       c=base();c.update(buy=buy,digits=digits,high_enabled=1,level=95. if buy else 105.);add(c,'digits')
      for open_,tp in [(0.,0.),(100.,120.),(-100.,-120.),(float('nan'),float('nan'))]:
       for quote in [(99.,101.),(100.,100.),(101.,99.)]:
        c=base();c.update(buy=buy,open=open_,tp=tp,bid=quote[0],ask=quote[1]);add(c,'quote-open-target')
      for gap in [-1.,0.,.01,.2,1.,float('nan')]:
       for freeze in [-1.,0.,.01,.1,1.]:
        c=base();c.update(buy=buy,gap=gap,freeze=freeze);add(c,'gap-freeze')
      for lev in [94.,95.,95.01,96.,99.,100.,101.,float('nan')]:
       for bid,ask in [(99.,101.),(95.,105.)]:
        c=base();c.update(buy=buy,level=lev,bid=bid,ask=ask);add(c,'level-quote')
      for idx in range(9):
       for vol in [0.,.01,1.,float('nan')]:
        c=base();c.update(buy=buy,strategy_index=idx,table_volume=vol);add(c,'all-index-volume')
    for buy in [0,1]:
      def extra(**changes):
        c=base();c.update(buy=buy,level=95. if buy else 105.,tp=130. if buy else 70.,bid=105. if buy else 94.,ask=106. if buy else 95.,step_enabled=1);c.update(changes);return c
      for pattern,guard,changed in itertools.product(range(6),[0,1,2],[0,1]):
        add(extra(pattern=pattern,guard=guard,changed=changed),'table-pattern-and-prior-flag')
      for enabled,lock,counter,hit in itertools.product([0,1],[0.,1.],[0,2147483647],[0,1]):
        c=extra(changed=1,high_enabled=enabled,lock_start=lock,counter=counter)
        if hit:c.update(high_enabled=0,lock_start=0.,level=110. if buy else 90.)
        add(c,'prior-flag-skips-counter')
      for before,shift,enabled in itertools.product([0,1,2,255],[0,1,2,255],[0,1]):
        add(extra(before_open=before,shift=shift,high_enabled=enabled),'high-low-byte-flags')
      for flag,reference,counter,minimum in itertools.product([0,1,2,255],[-0.,0.,1.,float('nan')],[-2147483648,0,1,2147483647],[-1,0,1,2147483647]):
        add(extra(high_enabled=0,lock_start=0.,step_enabled=flag,step_reference=reference,counter=counter,min_steps=minimum),'counter-without-high-low')
      for anchor,cached,reference in itertools.product([90.,100.,110.],[90.,100.,110.],[1.,float('nan')]):
        add(extra(high_enabled=0,lock_start=0.,anchor=anchor,cached=cached,step_reference=reference),'selected-vs-cached-anchor')
      for changed,mode,scenario in itertools.product([0,1],[-1,0,1,2,3],[0,2,5]):
        add(extra(high_enabled=0,lock_start=1.,lock_extra=2.,step_enabled=0,changed=changed,mode=mode,scenario=scenario),'lock-without-high-low')
    return rows
def table_values(c):
    values=[]
    for row in range(500):values.extend([10000.+row,20000.+row,-30000.-row])
    indices={0:[0],1:[250],2:[499],3:[1,17,499],4:[],5:[]}[c['pattern']]
    for row in indices:values[3*row]=float(c['ticket'])
    if c['pattern']==5:values[0]=struct.unpack('<d',struct.pack('<Q',0x7ff8000000000000))[0]
    return values
def encode(rows):
    b=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for c in rows:
      b+=struct.pack('<9iQ3q19d4i',c['id'],c['buy'],c['scenario'],c['high_enabled'],c['before_open'],c['shift'],c['mode'],c['changed'],c['pattern'],c['ticket']&MASK,c['counter'],c['strategy_index'],c['guard'],*[c[k] for k in ['open','sl','tp','bid','ask','unit','gap','freeze','level','anchor','cached','copied','point','table_volume','minimum','lock_start','lock_extra','step_reference','step_distance']],c['step_enabled'],c['min_steps'],c['digits'],c['close_tick'])
    return bytes(b)
class Original(v.Original):
    def __init__(self):
      super().__init__();self.covered=set();self.apis[self.base+0x3d010]=8
      self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+0x29de9,end=self.base+0x2ad04)
      for stop in [0x27333,0x2ad03]: self.m.hook_add(self.uc.UC_HOOK_CODE,self.visit,begin=self.base+stop,end=self.base+stop)
      self.m.hook_add(self.uc.UC_HOOK_MEM_INVALID,self.bad)
      # Finish branch calls the terminal tick thunk through this stable pointer.
      ext=0x7ff6846f7da0; self.m.mem_map(ext&~0xfff,0x1000); self.m.mem_write(ext,b'\xc3'); self.apis[ext]=7; self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=ext,end=ext)
    def bad(self,m,access,address,size,value,user):
      return False
    def call(self,m,address,size,user):
      if self.apis.get(address)==3:
       prop=m.reg_read(self.x.UC_X86_REG_R8)
       if prop==17:
        value=self.case['digits'][min(self.di,len(self.case['digits'])-1)];self.di+=1;m.reg_write(self.x.UC_X86_REG_RAX,value&v.pre.MASK);self.event(3,value);return
       if prop==16:
        value=self.case['point'];m.mem_write(self.base+0x6a448,struct.pack('<d',value));m.reg_write(self.x.UC_X86_REG_XMM0,v.pre.bits(value));self.event(4,prop,v.pre.bits(value));return
      if self.apis.get(address)==7:
       c=self.case;bb,aa=struct.unpack('<2d',m.mem_read(self.base+0x67758,16));self.event(7,v.pre.entry.text_hash('CHECK'),c.get('tick_ok',1),v.pre.bits(bb),v.pre.bits(aa));m.reg_write(self.x.UC_X86_REG_RAX,c.get('tick_ok',1));sp=m.reg_read(self.x.UC_X86_REG_RSP);ret=struct.unpack('<Q',m.mem_read(sp,8))[0];m.reg_write(self.x.UC_X86_REG_RSP,sp+8);m.reg_write(self.x.UC_X86_REG_RIP,ret);return
      return super().call(m,address,size,user)
    def visit(self,m,address,size,user):
      off=address-self.base;self.covered.add(off)
      if off in [0x27333,0x2ad03]:self.stopped=True;m.emu_stop()
    def run(self,c):
      m,x=self.m,self.x
      if isinstance(c.get('digits'),int): c=dict(c,digits=[c['digits'],c['digits']])
      self.case=c;self.events=[];self.closed=0;self.stopped=False;self.di=0;self.cursor=0x70001000
      m.mem_write(0x5001f000,b'\x00'*0x1000);m.reg_write(x.UC_X86_REG_EFLAGS,0x202);m.reg_write(x.UC_X86_REG_MXCSR,0x1f80)
      for region,raw in self.regions:
       if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
      for n in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+n),0)
      for n in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(n)),0)
      for rva,key in [(0x66d98,'unit'),(0x66a70,'gap'),(0x67468,'freeze'),(0x62580,'level'),(0x62510,'step_reference'),(0x62520,'step_distance'),(0x624c8,'lock_start'),(0x624d0,'lock_extra')]:m.mem_write(self.base+rva,struct.pack('<d',c[key]))
      for rva,val in [(0x624e4,c['high_enabled']),(0x6241c,c['mode']),(0x62508,c['step_enabled']),(0x62518,c['min_steps']),(0x673f0,c['counter']),(0x678f4,c['strategy_index']),(0x624d8,c['before_open']),(0x624ec,c['shift'])]:m.mem_write(self.base+rva,struct.pack('<i',val))
      m.mem_write(self.base+0x66410,bytes([c['guard']&255]));m.mem_write(self.base+0x673e8,struct.pack('<d',c['copied']))
      m.mem_write(self.base+0x62590,struct.pack('<1500d',*table_values(c)))
      m.mem_write(self.base+0x67758,struct.pack('<2d',c['bid'],c['ask']))
      m.mem_write(self.base+0x67918,struct.pack('<IQ',0,self.string('CHECK')))
      for i in range(9):m.mem_write(self.base+0x670d0+8*i,struct.pack('<d',c['level']+(0.5 if i==c['strategy_index'] else 0.0)));m.mem_write(self.base+0x66db0+8*i,struct.pack('<d',c['level']-(0.5 if i==c['strategy_index'] else 0.0)))
      m.reg_write(x.UC_X86_REG_RSI,0x23e575eae78);m.reg_write(x.UC_X86_REG_RDI,self.base+0x67918);m.reg_write(x.UC_X86_REG_R13,self.base+0x6a448);m.reg_write(x.UC_X86_REG_RBP,c['ticket']&MASK);m.reg_write(x.UC_X86_REG_R15, self.base+0x67758 if c['buy'] else self.base+0x67760)
      for reg,key in [(6,'open'),(7,'tp'),(8,'sl'),(9,'level')]:m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(reg)),bits(c[key]))
      m.reg_write(x.UC_X86_REG_XMM10,bits(0.0));m.reg_write(x.UC_X86_REG_XMM11,bits(float(c['ticket'])));m.reg_write(x.UC_X86_REG_XMM15,bits(c['cached']))
      sp=0x50020000-0x208;m.reg_write(x.UC_X86_REG_RSP,sp);m.mem_write(sp+0x30,struct.pack('<q',c['ticket']));m.mem_write(sp+0x88,struct.pack('<d',c['anchor']));m.mem_write(sp+0x98,struct.pack('<d',c['cached']));m.reg_write(x.UC_X86_REG_R12,c['changed']&MASK)
      m.emu_start(self.base+(0x29de9 if c['buy'] else 0x2d55a),0x60000000,timeout=5000000,count=2000000);v.pre.require(self.stopped,'BOUNDARY_MISSING')
      current=struct.unpack('<Q',m.mem_read(self.base+0x62580,8))[0];counter=struct.unpack('<i',m.mem_read(self.base+0x673f0,4))[0]&MASK;changed=m.reg_read(x.UC_X86_REG_R12)&255
      table_hash=0xcbf29ce484222325
      for z in bytes(m.mem_read(self.base+0x62590,12000)): table_hash=((table_hash^z)*0x100000001b3)&MASK
      h=0xcbf29ce484222325
      for e in self.events:
       for z in struct.pack('<5Q',*e):h=((h^z)*0x100000001b3)&MASK
      aggregate=1 if self.closed else int((m.reg_read(x.UC_X86_REG_RBX)&255)!=0)
      guard=int.from_bytes(m.mem_read(self.base+0x66410,1),'little');index=struct.unpack('<I',m.mem_read(self.base+0x678f4,4))[0]
      return RESULT.pack(c['id'],self.closed,changed,aggregate,current,counter,bits(c['tp']),*struct.unpack('<2Q',m.mem_read(self.base+0x67758,16)),len(self.events),h,table_hash,guard,index)
def main():
 p=argparse.ArgumentParser();p.add_argument('mode',choices=['prepare','original','mql5','compare']);p.add_argument('run');p.add_argument('--build');a=p.parse_args();v.pre.require(re.fullmatch('[a-z0-9-]{1,50}',a.run),'BAD_RUN');folder=HOME/'bang-chung/kiem-quan-ly-vi-the'/a.run;rows=cases();current=dict(original_ex5_sha256=v.pre.validation.original_hash(1),tool_sha256=sha(Path(__file__)),sources_sha256={n:sha(HOME/'source/MQL5'/n) for n in NAMES},analysis_sha256=sha(HOME/'phan-tich/dong-vi-the/management-20261025-r1/analysis.json'),contract_sha256=sha(HOME/'phan-tich/dong-vi-the/management-virtual-finish-20261025-r1/contract.md'),helpers_sha256={n:sha(HOME/'tests'/n) for n in ['check-management-prelude.py','check-management-virtual-start.py']});
 if a.mode=='prepare':
  folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(encode(rows));v.pre.save(folder/'cases.json',rows);t=folder/'tested-sources';t.mkdir();[shutil.copyfile(HOME/'source/MQL5'/n,t/Path(n).name) for n in NAMES];shutil.copyfile(Path(__file__),t/Path(__file__).name);v.pre.save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin')));print(json.dumps({'cases':len(rows)}));return
 baseline=json.loads((folder/'baseline.json').read_text());v.pre.require(all(baseline[k]==v for k,v in current.items()),'IDENTITY_CHANGED');v.pre.require((folder/'cases.bin').read_bytes()==encode(rows),'INPUTS_CHANGED')
 if a.mode=='original':
  v.pre.require(not (folder/'original-results.bin').exists(),'ORIGINAL_RESULT_EXISTS')
  r=Original();raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
  traces=[]
  for c in rows:
   try:
    raw.extend(r.run(c))
    if c['id'] in [104,105]: traces.append({'id':c['id'],'events':r.events[:]})
   except Exception as e: raise RuntimeError('NATIVE_CASE_'+str(c['id'])+': '+str(e)) from e
  (folder/'original-results.bin').write_bytes(raw);v.pre.save(folder/'native-traces.json',traces);v.pre.save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),instructions=len(r.covered)));print(json.dumps({'cases':len(rows),'instructions':len(r.covered)}));return
 if a.mode=='mql5':
  v.pre.require(a.build is not None,'BUILD_REQUIRED'); receipt=HOME/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));v.pre.require(build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN');
  for n,d in current['sources_sha256'].items():v.pre.require(build['sources_sha256'][n]==d==sha(MT/'MQL5'/n),'SOURCE_DIFFERS')
  binary=MT/'MQL5'/Path(NAMES[-1]).with_suffix('.ex5');v.pre.require(sha(binary)==build['binary_sha256'],'BINARY_DIFFERS')
  files=MT/'MQL5/Files/bot1-management-virtual-finish'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/('b1-finish-'+a.run+'.set');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini=MT/('b1-finish-'+a.run+'.ini');ini.write_text('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1ManagementVirtualFinishCheck\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16');proc=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW);code=proc.wait(timeout=120);v.pre.require(code==0,'MT5_EXIT');v.pre.require((files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'SCRIPT_STATUS');shutil.copyfile(files/'mql5-results.bin',folder/'mql5-results.bin');shutil.copyfile(files/'script-status.bin',folder/'script-status.bin');v.pre.save(folder/'mql5-run.json',dict(**current,cases=len(rows),exit_code=code,result_sha256=sha(folder/'mql5-results.bin'),binary_sha256=sha(binary)));print(json.dumps({'cases':len(rows),'exit_code':code}));return
 if a.mode=='compare':
  for name in ['original-run.json','mql5-run.json']:
   record=json.loads((folder/name).read_text());v.pre.require(all(record[k]==value for k,value in current.items()),'RUN_IDENTITY_DIFFERS');v.pre.require(record['result_sha256']==sha(folder/name.replace('-run.json','-results.bin')),'RUN_RESULT_DIFFERS')
  native=(folder/'original-results.bin').read_bytes();actual=(folder/'mql5-results.bin').read_bytes();v.pre.require(native[:12]==actual[:12]==struct.pack('<3i',MAGIC,1,len(rows)) and len(native)==len(actual)==12+RESULT.size*len(rows),'BAD_RESULTS');fails=[]
  for c in rows:
   off=12+c['id']*RESULT.size;n=RESULT.unpack_from(native,off);r=RESULT.unpack_from(actual,off)
   if n!=r:fails.append({'id':c['id'],'group':c['group'],'native':list(n),'mql5':list(r)})
  report={'cases':len(rows),'matched':len(rows)-len(fails),'failed':len(fails),'first_failures':fails[:12],'slice_only':True,'whole_bot_complete':False,'hashes':{'original':sha(folder/'original-results.bin'),'mql5':sha(folder/'mql5-results.bin')}};v.pre.save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(fails))
if __name__=='__main__':main()
