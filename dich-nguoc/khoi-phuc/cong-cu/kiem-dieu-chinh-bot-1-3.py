"""Check distance preparation against the complete captured setup function.

python -I -B -X utf8 kiem-dieu-chinh-bot-1-3.py prepare|original|mql5|compare BOT RUN
Terminal reads are supplied. Native arithmetic/branches/string copies run unchanged.
Only numeric outputs listed below are compared, not indicator creation or the EA.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import random
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1]
MT=ROOT.parent/'.local/claude-recovery-20261023/mt5'
MAGIC=0x44535431
MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('entry_check',Path(__file__).with_name('kiem-gia-vao-bot-1-3.py'))
entry_check=importlib.util.module_from_spec(spec);spec.loader.exec_module(entry_check)

# Field, native storage type, RVA in bot 1, RVA in bot 3. None means absent.
INPUTS=[
 ('reference','d',0x62180,0x6d1b8),('use_variable','B',0x6a5c8,0x1d6f28),
 ('adjust_lots','B',0x6a798,0x1d6f30),('max_spread','d',0x6a5c0,0x1d6f98),
 ('feature_flag','B',0x62214,0x6d23c),('freeze_buffer_flag','B',0x62215,0x6d248),
 ('entry.confirmation_frame','i',0x6227c,0x6d2b4),
 ('entry.hour1_flag','B',0x62280,None),('entry.entry_frame','i',None,0x6d2b8),
 ('entry.older_width','i',0x62284,0x6d2bc),('entry.recent_width','i',0x62288,0x6d2c0),
 ('entry.last_shift','i',0x6228c,0x6d2c4),('entry.gap_points','d',0x62290,0x6d2c8),
 ('buy_offset','d',0x62298,0x6d2d0),('sell_offset','d',0x622a0,0x6d2d8),
 ('nearby_radius','d',0x622b0,0x6d2e8),('expiration_hours','i',0x622b8,0x6d2f0),
 ('virtual_expiration','B',0x6a5e8,0x1d6fc8),
 ('stop_distance','d',0x622f8,0x6d328),('target_distance','d',0x62300,0x6d330),
 ('trail_distance','d',0x62318,0x6d348),('trail_start','d',0x62320,0x6d350),
 ('trail_limit','d',0x62328,0x6d358),('trail_step','d',0x62330,0x6d360),
 ('native_6d368','d',None,0x6d368),('native_6d370','d',None,0x6d370),
 ('trigger_distance','d',None,0x6d398),('locked_distance','d',None,0x6d3a0),
 ('aux_hour1','B',0x62354,0x6d3b4),('aux_scan50','B',0x62355,0x6d3b5),
 ('aux_older','i',0x62358,0x6d3b8),('aux_recent','i',0x6235c,0x6d3bc),
 ('aux_offset','d',0x62368,0x6d3c8),('min_change','d',0x623a0,0x6d400)]
CONTEXT=[('sample','d'),('point','d'),('digits','i'),('stops_level','q'),
         ('freeze_level','q'),('bid','d'),('ask','d'),('now','q')]
OUTPUTS=[
 ('scale','d',0x682e8,0x6d1c0),('lot_scale','d',0x682f0,0x6d1c8),
 ('unit','d',0x66d98,0x73dd8),('spread','d',0x62560,0x6d650),
 ('max_spread','d',0x623d8,0x6d4d0),('feature_flag','B',0x623d4,0x6d4cc),
 ('freeze_buffer','i',0x623e0,0x6d4d8),('entry_frame','i',0x6242c,0x6d524),
 ('older_width','i',0x62430,0x6d528),('recent_width','i',0x62434,0x6d52c),
 ('last_shift','i',0x62438,0x6d530),('gap_points','d',0x62440,0x6d538),
 ('buy_offset','d',0x62448,0x6d540),('sell_offset','d',0x62450,0x6d548),
 ('nearby_radius','d',0x62460,0x6d558),('stop_distance','d',0x62498,0x6d588),
 ('target_distance','d',0x624a0,0x6d590),('trail_distance','d',0x624a8,0x6d598),
 ('trail_start','d',0x624b0,0x6d5a0),('trail_limit','d',0x624b8,0x6d5a8),
 ('trail_step','d',0x624c0,0x6d5b0),('trigger_distance','d',0x624c8,0x6d5b8),
 ('locked_distance','d',0x624d0,0x6d5c0),('native_6d378','d',None,0x6d378),
 ('native_6d380','d',None,0x6d380),('aux_frame','i',0x624dc,0x6d5cc),
 ('aux_scan','i',0x624e0,0x6d5d0),('aux_older','i',0x624e4,0x6d5d4),
 ('aux_recent','i',0x624e8,0x6d5d8),('aux_offset','d',0x624f0,0x6d5e0),
 ('min_change','d',0x62520,0x6d610),('stop_min_price','d',0x66a70,0x73ab0),
 ('freeze_min_price','d',0x67468,0x744a8),('expiration_seconds','I',0x66da0,0x73de0),
 ('expiration','q',0x67450,0x74490)]
NATIVE={1:dict(fn=0x7500,array=0x62190,comment_in=0x622d0,comment_out=0x62480),
        3:dict(fn=0xe0c0,array=0x6d180,comment_in=0x6d308,comment_out=0x6d578)}

def fields(rows,bot):return [(name,kind,a if bot==1 else b) for name,kind,a,b in rows if (a if bot==1 else b) is not None]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def pack_kind(kind):return 'i' if kind=='B' else kind
def base_case(bot):
    c={name:0 for name,_,_ in fields(INPUTS,bot)}
    c.update(reference=1000.,use_variable=1,adjust_lots=1,max_spread=500.,feature_flag=1,freeze_buffer_flag=1,
        buy_offset=10.,sell_offset=15.,nearby_radius=20.,expiration_hours=4,virtual_expiration=0,
        stop_distance=200.,target_distance=300.,trail_distance=40.,trail_start=80.,trail_limit=100.,trail_step=5.,
        aux_hour1=1,aux_scan50=1,aux_older=2,aux_recent=3,aux_offset=20.,min_change=0.1,
        sample=2000.,point=0.01,digits=2,stops_level=30,freeze_level=20,bid=2600.,ask=2600.25,now=1792713600)
    c.update({'entry.confirmation_frame':16408,'entry.older_width':4,'entry.recent_width':2,
              'entry.last_shift':160,'entry.gap_points':150.})
    c['entry.hour1_flag' if bot==1 else 'entry.entry_frame']=1 if bot==1 else 15
    return c

def cases(bot):
    rng=random.Random(2026102303);out=[]
    def add(tag,**changes):
        c=base_case(bot);c.update(changes);c['tag']=tag;out.append(c)
    for _ in range(400):
        c=base_case(bot)
        for name,kind,_ in fields(INPUTS,bot):
            if kind=='B':c[name]=rng.randrange(2)
            elif kind=='i':c[name]=rng.choice([-2,-1,0,1,2,3,10,100])
            else:c[name]=rng.choice([0.,-1.,0.1,1.,rng.uniform(0.01,2500.)])
        c.update(sample=rng.uniform(0.,4000.),point=rng.choice([0.00001,0.001,0.01,0.1,1.]),
                 digits=rng.randrange(9),stops_level=rng.randrange(1000),freeze_level=rng.randrange(1000),tag='mixed')
        out.append(c)
    for reference in [-1.,0.,0.1,999.999999,1000.,1000.000001,2000.]:
        for sample in [-1.,-0.,0.,0.01,1000.,2500.]:
            for use in [0,1]:
                for adjust in [0,1]:add('scale',reference=reference,sample=sample,use_variable=use,adjust_lots=adjust)
    for digits in [-1,0,1,2,3,4,5,6,8,12]:
        for point in [-0.01,0.,0.00001,0.001,0.01,0.1,1.]:add('price-unit',digits=digits,point=point)
    for name in ['entry.gap_points','stop_distance','target_distance','trail_distance','min_change']:
        for digits in [1,2,3,5]:
            for value in [-1.,-0.,0.,0.049999999,0.05,0.050000001,9.999999,10.,10.000001,29.999999,30.,30.000001]:
                add('distance-boundary',**{name:value,'digits':digits})
    for hours in [-2147483648,-1,0,1,596523,596524,1193046,1193047,2147483647]:
        for virtual in [0,1]:add('expiration-wrap',expiration_hours=hours,virtual_expiration=virtual)
    for name in ['entry.older_width','entry.recent_width','entry.last_shift','aux_older','aux_recent']:
        for value in [-2147483648,-1,0,1,2,2147483647]:add('integer-boundary',**{name:value})
    for flag in [0,1]:
        for scale in [-2.,0.,0.5,1.,1.5,2.]:add('buffer-flag',freeze_buffer_flag=flag,sample=scale*1000.)
    if bot==3:
        for trigger in [-1.,0.,1.,2.]:
            for locked in [-1.,0.,0.999999,1.,1.000001,2.]:add('paired-distance',trigger_distance=trigger,locked_distance=locked)
    # Combine each previously proved six-field profile with supplied broker data.
    folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
    proof=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'kiem-tham-so-goc.json').read_text())
    for p in proof['profiles']:
        for point,digits in [(0.01,2),(0.001,3)]:
            v=p['values'];c=base_case(bot);c.update(point=point,digits=digits,tag='entry-profile-'+str(p['index']))
            for key,source in [('confirmation_frame','confirm_tf'),('older_width','older'),('recent_width','recent'),('last_shift','scan'),('gap_points','gap')]:c['entry.'+key]=v[source]
            c['entry.hour1_flag' if bot==1 else 'entry.entry_frame']=v['entry_h1' if bot==1 else 'entry_tf'];out.append(c)
    for i,c in enumerate(out):c['id']=i
    return out

def encode(values,bot):
    raw=bytearray(struct.pack('<4i',MAGIC,1,bot,len(values)))
    for c in values:
        raw+=struct.pack('<i',c['id'])
        for name,kind in [(n,k) for n,k,_ in fields(INPUTS,bot)]+CONTEXT:raw+=struct.pack('<'+pack_kind(kind),c[name])
    return raw

class Original(entry_check.Original):
    def __init__(self,bot):
        super().__init__(bot);self.settings=NATIVE[bot]
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
        metadata=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        if self.settings['fn'] not in {int(f['begin_rva'],16) for f in metadata['functions']}:raise ValueError('SETUP_NOT_IN_RUNTIME_TABLE')
        eb=next(addr for addr,api in self.apis.items() if api==1)-0x7d3c40
        extra={eb+0x7b49f0:10,eb+0x7beec0:11,eb+0x7c2c10:12,eb+0x7d1c40:13,
               eb+0x7c2890:14,eb+0x7d3bc0:15,eb+0x3959a0:200}
        for page in {p&~0xfff for p in extra}:
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
        self.apis.update(extra)
        for addr in extra:
            self.m.mem_write(addr,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=addr,end=addr)
    def call(self,m,address,size,user):
        x=self.x;api=self.apis[address];c=self.case
        if api in [100,101]:return super().call(m,address,size,user)
        first=m.reg_read(x.UC_X86_REG_R8)&0xffffffff
        if api==3:
            if first not in [17,31,32]:raise ValueError('UNEXPECTED_SYMBOL_INTEGER')
            m.reg_write(x.UC_X86_REG_RAX,c[{17:'digits',31:'stops_level',32:'freeze_level'}[first]]&MASK)
        elif api==10:
            if m.reg_read(x.UC_X86_REG_RDX)!=0x53:raise ValueError('UNEXPECTED_DISPATCH')
            m.reg_write(x.UC_X86_REG_RAX,17)
        elif api==11:
            rsp=m.reg_read(x.UC_X86_REG_RSP)
            count=struct.unpack('<I',m.mem_read(rsp+0x28,4))[0]
            desc=struct.unpack('<Q',m.mem_read(rsp+0x30,8))[0]
            if count!=100 or desc!=self.base+self.settings['array']:raise ValueError('UNEXPECTED_COPY_BUFFER')
            # A valid two-element series array; the original sets its series flag.
            m.mem_write(desc+2,struct.pack('<H',1));m.mem_write(desc+8,struct.pack('<I',2))
            m.mem_write(desc+28,struct.pack('<Q',0x70100000))
            m.mem_write(0x70100000,struct.pack('<2d',c['sample'],c['sample']));m.reg_write(x.UC_X86_REG_RAX,2)
        elif api==12:
            pointer=m.reg_read(x.UC_X86_REG_R8)
            m.mem_write(pointer,struct.pack('<q2d',c['now'],c['bid'],c['ask']));m.reg_write(x.UC_X86_REG_RAX,1)
        elif api==13:m.reg_write(x.UC_X86_REG_RAX,c['now']&MASK)
        elif api in [14,15]:
            if api==14 and first!=16:raise ValueError('UNEXPECTED_SYMBOL_DOUBLE')
            if api==15 and (first!=16408 or m.reg_read(x.UC_X86_REG_R9)!=1):raise ValueError('UNEXPECTED_DAY_OPEN')
            value=c['point' if api==14 else 'sample'];raw=struct.pack('<d',value)
            m.mem_write(self.base+self.cfg['slot'],raw);m.reg_write(x.UC_X86_REG_XMM0,int.from_bytes(raw,'little'))
        elif api==200:
            self.error=m.reg_read(x.UC_X86_REG_RDX);m.emu_stop()
        else:raise ValueError('UNEXPECTED_API '+str(api))
        self.api_counts[api]=self.api_counts.get(api,0)+1
    def run(self,c):
        m,x=self.m,self.x;self.case=c;self.error=0;self.api_counts={};self.cursor=0x70001000;self.allocs=self.frees=0
        for region,raw in self.regions:
            if region.get('kind')=='mutable_program_data':m.mem_write(region['base'],raw)
        for name in ['RAX','RBX','RCX','RDX','RSI','RDI','RBP','R8','R9','R10','R11','R12','R13','R14','R15']:m.reg_write(getattr(x,'UC_X86_REG_'+name),0)
        for i in range(16):m.reg_write(getattr(x,'UC_X86_REG_XMM'+str(i)),0)
        for name,kind,rva in fields(INPUTS,self.bot):m.mem_write(self.base+rva,struct.pack('<'+kind,c[name]))
        # Empty comment input/output: native copy helper still runs, no allocation needed.
        for key in ['comment_in','comment_out']:m.mem_write(self.base+self.settings[key],b'\0'*12)
        m.mem_write(self.base+self.cfg['symbol'],struct.pack('<IQ',0,self.string('XAUUSD')))
        top=0x50020000-0x108;m.mem_write(top,struct.pack('<Q',0x60000000));m.reg_write(x.UC_X86_REG_RSP,top)
        try:m.emu_start(self.base+self.settings['fn'],0x60000000,timeout=5000000,count=1000000)
        except self.uc.UcError as error:raise RuntimeError(f'case={c["id"]} rip={m.reg_read(x.UC_X86_REG_RIP):x} {error}') from error
        if not self.error and m.reg_read(x.UC_X86_REG_RIP)!=0x60000000:raise RuntimeError('SETUP_DID_NOT_RETURN')
        if self.error and self.error not in ({0x230862000001f7,0x430854000001f7} if self.bot==1 else {0x23095a000001f7,0x43094c000001f7,0x1d0886000001f7}):
            raise RuntimeError('UNEXPECTED_NATIVE_ERROR '+hex(self.error))
        values=[]
        for _,kind,rva in fields(OUTPUTS,self.bot):
            raw=bytes(m.mem_read(self.base+rva,struct.calcsize('<'+kind)))
            values.append(0 if self.error else (int.from_bytes(raw,'little') if kind=='d' else struct.unpack('<'+kind,raw)[0]&MASK))
        return [c['id'],int(not self.error),*values]

def header(bot,count):return struct.pack('<4i',MAGIC,1,count,len(fields(OUTPUTS,bot)))
def read_cases(out,bot):
    values=json.loads((out/'cases.json').read_text())
    if encode(values,bot)!=(out/'cases.bin').read_bytes():raise ValueError('INPUT_BINARY_MISMATCH')
    return values

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','original','mql5','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-dieu-chinh'/a.run
    if a.mode=='prepare':
        if out.exists() and {p.name for p in out.iterdir()}!={'native-profiles.json'}:raise FileExistsError(out)
        out.mkdir(parents=True,exist_ok=True);values=cases(a.bot)
        if (out/'native-profiles.json').exists():
            proof=json.loads((out/'native-profiles.json').read_text())
            for row in proof['rows']:
                for scale in [0.5,1.,2.]:
                    for digits,point in [(2,0.01),(3,0.001)]:
                        c=base_case(a.bot);c.update(row['values']);c.update(digits=digits,point=point,sample=c['reference']*scale,
                            tag=f"full-base-profile-{row['index']}-hl{row['hl']}",id=len(values));values.append(c)
        (out/'cases.json').write_text(json.dumps(values,ensure_ascii=False),encoding='utf-8');(out/'cases.bin').write_bytes(encode(values,a.bot))
        (out/'fields.json').write_text(json.dumps({'input':fields(INPUTS,a.bot),'context':CONTEXT,'output':fields(OUTPUTS,a.bot)},indent=2),encoding='utf-8')
        print(json.dumps({'cases':len(values),'outputs':len(fields(OUTPUTS,a.bot))}));return
    if a.mode=='original':
        target=out/'original-results.bin'
        if target.exists():raise FileExistsError(target)
        values=read_cases(out,a.bot);original=Original(a.bot);start=time.monotonic();rows=[];errors=[]
        for c in values:
            rows.append(original.run(c))
            if original.error:errors.append({'id':c['id'],'tag':c['tag'],'native_error':hex(original.error)})
        target.write_bytes(header(a.bot,len(rows))+b''.join(struct.pack('<2i'+'Q'*(len(r)-2),*r) for r in rows))
        (out/'original-run.json').write_text(json.dumps({'cases':len(rows),'errors':errors,'seconds':round(time.monotonic()-start,2),
            'sha256':sha(target),'tool_sha256':sha(Path(__file__)),'native_function_rva':hex(NATIVE[a.bot]['fn']),
            'scope':'Complete native setup executed with successful mocked indicator/tick reads; only listed numeric outputs compared. Runtime division errors map to false; partial writes on errors excluded.'},indent=2),encoding='utf-8')
        print(json.dumps({'cases':len(rows),'runtime_errors':len(errors),'seconds':round(time.monotonic()-start,2)}));return
    if a.mode=='mql5':
        target=out/'mql5-results.bin'
        if target.exists():raise FileExistsError(target)
        files=MT/f'MQL5/Files/bot{a.bot}-distance-settings'/a.run;files.mkdir(parents=True,exist_ok=False)
        shutil.copyfile(out/'cases.bin',files/'cases.bin')
        params=MT/'MQL5/Presets'/f'b{a.bot}-{a.run}.set';params.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-{a.run}-settings.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}DistanceSettingsCheck\nScriptParameters={params.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MQL5_CHECK_TIMEOUT')
        if code!=0:raise RuntimeError('MQL5_CHECK_EXIT '+str(code))
        shutil.copyfile(files/'mql5-results.bin',target)
        if (out/'native-profiles.json').exists():shutil.copyfile(files/'profiles.bin',out/'profiles.bin')
        script=MT/f'MQL5/Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}DistanceSettingsCheck.ex5'
        (out/'mql5-run.json').write_text(json.dumps({'exit_code':code,'seconds':round(time.monotonic()-start,2),'script_sha256':sha(script),'results_sha256':sha(target),'parameters_sha256':sha(params)},indent=2),encoding='utf-8');print('MQL5 results saved');return
    values=read_cases(out,a.bot);expected=(out/'original-results.bin').read_bytes();actual=(out/'mql5-results.bin').read_bytes()
    count=len(values);names=['id','success']+[n for n,_,_ in fields(OUTPUTS,a.bot)];fmt='<2i'+'Q'*(len(names)-2);size=struct.calcsize(fmt)
    if expected[:16]!=header(a.bot,count) or actual[:16]!=header(a.bot,count) or len(expected)!=16+size*count or len(actual)!=len(expected):raise ValueError('OUTPUT_SHAPE_MISMATCH')
    failures=[];groups={}
    for i,c in enumerate(values):
        e=struct.unpack_from(fmt,expected,16+size*i);v=struct.unpack_from(fmt,actual,16+size*i)
        g=groups.setdefault(c['tag'],{'cases':0,'matched':0});g['cases']+=1;g['matched']+=int(e==v)
        if e!=v:failures.append({'id':i,'tag':c['tag'],'differences':{name:[hex(x),hex(y)] for name,x,y in zip(names,e,v) if x!=y}})
    numeric_failures=len(failures)
    profiles_result=None
    if (out/'native-profiles.json').exists():
        proof=json.loads((out/'native-profiles.json').read_text());rows=sorted(proof['rows'],key=lambda r:(r['index'],r['hl']))
        blob=bytearray(struct.pack('<4i',0x42504631,1,len(rows),len(proof['fields'])))
        for row in rows:
            blob+=struct.pack('<2i',row['index'],row['hl'])
            for name,kind,_ in proof['fields']:
                v=row['values'][name];blob+=struct.pack('<d',v) if kind=='d' else struct.pack('<Q',int(v)&MASK)
        profiles_ok=(out/'profiles.bin').read_bytes()==blob
        profiles_result={'rows':len(rows),'fields_per_row':len(proof['fields']),'matched':len(rows) if profiles_ok else 0,'identical':profiles_ok,'sha256':sha(out/'profiles.bin')}
        if not profiles_ok:failures.append({'base_profiles':'different'})
    record={'cases':count,'matched':count-numeric_failures,'failed':numeric_failures,'outputs_per_success':len(names)-2,'groups':groups,'first_failures':failures[:25],
        'hashes':{p:sha(out/p) for p in ['cases.bin','original-results.bin','mql5-results.bin']},'passed':not failures,
        'scope':'Numeric distance settings with supplied terminal data. Not full setup, indicator implementation, complete strategy profiles or complete EA.'}
    if profiles_result:record['base_profiles']=profiles_result
    (out/'comparison.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record));raise SystemExit(bool(failures))
if __name__=='__main__':main()
