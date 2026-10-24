"""Compare queue -> original pending builder -> filling -> send -> messages.

Usage: kiem-chuoi-dat-lenh-bot-1-3.py prepare|mql5|original|compare BOT RUN [--build BUILD]
Run MQL5 first. The builder's bool/state are never supplied. Only terminal services
are supplied; number/string formatting is measured in MT5. No orders are sent.
"""
import argparse
import copy
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x51465331
spec=importlib.util.spec_from_file_location('queue_check',Path(__file__).with_name('kiem-hang-doi-bot-1-3.py'))
queue=importlib.util.module_from_spec(spec);spec.loader.exec_module(queue)
send=queue.send;pending=send.pending;MT=queue.MT;sha=queue.sha;save=queue.save
ENV_FIELDS=[(name,kind) for name,kind in pending.FIELDS if name in ['stopped','preferred','execution0','filling0','execution1','filling1','auto_expiration','order_flags','order_ok','expiration0','expiration_ok0','expiration1','expiration_ok1']]+[('property_error','i')]
RETURNS={1:{0x2e936,0x2eaff,0x2ef9b,0x2f17f},3:{0x3bd76,0x3bf3f,0x3c3db,0x3c5bf}}

def cases():
    rows=[]
    def add(q,group,**changes):
        i=len(rows);q=copy.deepcopy(q);q['id']=i;env=send.base();env['id']=i
        env.update(async_mode=[0,1,255][i%3],log_level=[-1,0,1,2,3][i%5],margin_mode=[0,2][i%2],write_result=int(i%7!=0))
        env['new_result']['retcode']=[0,10004,10009,10018,10041,0xffffffff][i%6]
        prep=pending.base();prep['property_error']=0
        for key,value in changes.items():
            if key.startswith('send.'):
                name=key[5:]
                if name.startswith('result.'):env['new_result'][name[7:]]=value
                else:env[name]=value
            elif key.startswith('queue.'):q[key[6:]]=value
            else:prep[key]=value
        # The seed agrees with the first queue reply. Later replies are selected
        # by builder-call index; this is not an independent accepted-value axis.
        env['accepted']=int(bool(q['replies'][0][0])) if q['replies'] else 1
        rows.append(dict(id=i,group=group,queue=q,send=env,prep={name:prep[name] for name,_ in ENV_FIELDS}))
    for q in queue.cases():add(q,'queue-'+q['group'])
    for direction in [4,5]:
        for stopped in [0,1]:
            for flag in [0,1,2,3,255]:add(queue.base(direction),'stopped-and-entry-flag',stopped=stopped,**{'queue.enabled':flag})
        for preferred in [-1,0,1,2]:
            for execution in [-1,0,1,2,3]:
                for mask in [0,1,2,3]:add(queue.base(direction),'first-filling',preferred=preferred,execution0=execution,filling0=mask)
        for execution in [-1,0,1,2,3]:
            for mask in [0,1,2,3]:add(queue.base(direction),'second-filling',execution1=execution,filling1=mask)
        for flags in [0,4,16,32,20,36,52,63,-1,0x100000004]:
            for ok in [0,1]:add(queue.base(direction),'order-flags',order_flags=flags,order_ok=ok,property_error=4302)
        for virtual in [0,1,2,255]:
            for flags in [0,1,2,3,4,8,15]:
                add(queue.base(direction),'zero-expiration',auto_expiration=flags,expiration0=flags,**{'queue.virtual':virtual,'queue.anchor':-172800})
        for ok in [0,1]:
            for flags in [0,1,2,4,8,15]:add(queue.base(direction),'expiration-read',expiration0=flags,expiration_ok0=ok,property_error=4302)
        for log in [-1,0,1,2,3]:
            for mode in [0,1,2,255]:
                for accepted in [0,1]:
                    q=queue.base(direction);q['replies']=[[accepted,3 if not accepted else 132]]
                    add(q,'send-after-builder',**{'send.log_level':log,'send.async_mode':mode,'send.write_result':1})
        for symbol in ['', 'Vàng', 'XAUUSD.long.symbol']:
            for digits_ok in [[0,0],[0,1],[1,0],[1,1]]:
                add(queue.base(direction),'symbol-and-format-reads',**{'queue.symbol':symbol,'send.log_level':2,'send.digits_ok':digits_ok,'send.execution_ok':digits_ok},property_error=4302)
    return rows
def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for row in rows:
        raw+=queue.encode([row['queue']])[12:]+send.encode([row['send']])[12:]
        raw+=b''.join(struct.pack('<'+kind,row['prep'][name]) for name,kind in ENV_FIELDS)
    return raw
def read_cases(path):
    # Input records are generated alongside JSON with all double bits explicit.
    # Decode each independent variable-size record using the same primitive reader.
    rd=send.Reader(path.read_bytes())
    magic,version,n=rd.take('3i')
    if (magic,version)!=(MAGIC,1):raise ValueError('BAD_PIPELINE_CASE_HEADER')
    rows=[];schemas=send.layout()
    for _ in range(n):
        q=dict(zip(['id','scenario','focus','enabled','error_count','last_error',*queue.CONTEXT,'anchor','magic','virtual'],rd.take('4iIi6dq2i')))
        q.update(symbol=rd.text(),comment=rd.text(),orders=[list(rd.take('3d')) for _ in range(100)],results=[list(rd.take('2d')) for _ in range(100)])
        count=rd.take('i')[0]
        if not 0<=count<=20:raise ValueError('BAD_REPLY_COUNT')
        q['replies']=[list(rd.take('2i')) for _ in range(count)]
        env=dict(zip(['id','async_mode','log_level','margin_mode','accepted','write_result'],rd.take('6i')))
        env.update(digits=list(rd.take('2q')),executions=list(rd.take('2q')))
        ok=rd.take('4i');env.update(digits_ok=list(ok[:2]),execution_ok=list(ok[2:]))
        for key in ['request','result','new_result']:
            values={}
            for field in schemas['request' if key=='request' else 'result']['fields']:
                if field['kind']=='s':
                    if field['name']=='symbol':env['symbol_null']=rd.take('i')[0]
                    values[field['name']]=rd.text()
                else:values[field['name']]=rd.take(field['kind'])[0]
            env[key]=values
        prep={name:rd.take(kind)[0] for name,kind in ENV_FIELDS}
        if q['id']!=env['id'] or q['id']!=len(rows):raise ValueError('PIPELINE_CASE_IDS_DIFFER')
        if env['accepted']!=(int(bool(q['replies'][0][0])) if q['replies'] else 1):raise ValueError('SEND_SEED_DIFFERS_FROM_FIRST_QUEUE_REPLY')
        rows.append(dict(id=q['id'],queue=q,send=env,prep=prep))
    if rd.pos!=len(rd.raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return rows
def trade_record(rd):return rd.block(260),[rd.text() for _ in range(4)]
def fixtures(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('FIXTURE_HEADER_DIFFERS')
    chart=rd.text();digits=rd.take('i')[0];out={i:[] for i in range(n)}
    while rd.pos<len(rd.raw):
        cid,api=rd.take('2i')
        if cid not in out:raise ValueError('FIXTURE_CASE_ID_DIFFERS')
        if api==1:value=(*rd.take('2i'),rd.block(120),rd.block(68),rd.block(68))
        elif api==2:value=(rd.take('i')[0],rd.text(),*rd.take('qi'))
        elif api==3:value=(*rd.take('Qi'),rd.text())
        elif api==5:
            count=rd.take('i')[0];args=[]
            if not 1<=count<=6:raise ValueError('BAD_FORMAT_ARGUMENT_COUNT')
            for _ in range(count):
                tag=rd.take('I')[0]
                if tag==0x590008:item=rd.text()
                elif tag==0x560015:item=rd.take('Q')[0]
                else:raise ValueError('UNKNOWN_FORMAT_TAG')
                args.append((tag,item))
            value=(args,rd.text())
        elif api==6:value=tuple(rd.text() for _ in range(4))
        elif api==7:
            count=rd.take('i')[0]
            if count not in [1,2]:raise ValueError('BAD_PRINT_ARGUMENT_COUNT')
            value=tuple(rd.text() for _ in range(count))
        elif api==8:value=tuple(rd.text() for _ in range(3))
        elif api==9:value=(rd.take('i')[0],rd.text(),rd.take('q')[0])
        elif api==10:value=([rd.text() for _ in range(4)],trade_record(rd))
        elif api==11:value=(rd.take('I')[0],trade_record(rd))
        elif api==12:
            count=rd.take('i')[0]
            if not 2<=count<=22:raise ValueError('BAD_SIGNED_CAST_METADATA_COUNT')
            value=[(rd.take('i')[0],rd.text()) for _ in range(count)]
        else:raise ValueError('UNKNOWN_PIPELINE_FIXTURE '+str(api))
        out[cid].append((api,value))
    return out,chart,digits

def validate_fixture_inputs(row,records):
    """Bind supplied API values to input bytes, independently of MQL decoding.

    Native argument/order/state checks remain separate. Uncalled property slots
    need not be consumed: stopped/error branches can return before reading them.
    """
    prep=row['prep'];env=row['send'];replies=row['queue']['replies']
    builder=-1;inside=False;counts={};sent=False
    result_fields=send.layout()['result']['fields']
    supplied_result=b''.join(struct.pack('<Q',send.text_hash(env['new_result'][f['name']])) if f['kind']=='s' else struct.pack('<'+f['kind'],env['new_result'][f['name']]) for f in result_fields)
    def take(key,values):
        index=counts.get(key,0)
        if index>=len(values):raise ValueError('EXTRA_SUPPLIED_PROPERTY '+key)
        counts[key]=index+1;return values[index]
    for api,value in records:
        if api==12:
            expected=[row['queue']['last_error'],prep['property_error'],*[reply[1] for reply in replies]]
            if [code for code,text in value]!=expected:raise ValueError('SIGNED_CAST_CODES_DIFFER_FROM_INPUT')
        elif api==10:
            if inside:raise ValueError('NESTED_FIXTURE_BUILDER')
            builder+=1;inside=True;counts={};sent=False
        elif api==11:
            if not inside:raise ValueError('FIXTURE_BUILDER_RETURN_WITHOUT_ENTRY')
            inside=False
        elif api in [1,2,9]:
            if not inside:raise ValueError('SUPPLIED_API_OUTSIDE_BUILDER')
            if api==1:
                async_mode,accepted,request,old,new=value
                if replies and builder>=len(replies):raise ValueError('SEND_OUTSIDE_REPLY_RANGE')
                expected=int(bool(replies[builder][0])) if replies else 1
                if sent or accepted!=expected or async_mode!=int(env['async_mode']!=0):raise ValueError('SEND_MODE_OR_REPLY_DIFFERS_FROM_INPUT')
                if new!=(supplied_result if env['write_result'] else old):raise ValueError('SEND_RESULT_DIFFERS_FROM_INPUT')
                sent=True
            elif api==9:
                prop,symbol,actual=value
                if prop==33:expected=take('direct-execution',[prep['execution0'],prep['execution1']])
                elif prop==50:expected=take('direct-filling',[prep['filling0'],prep['filling1']])
                elif prop==49:expected=prep['auto_expiration']
                else:raise ValueError('UNKNOWN_DIRECT_PROPERTY '+str(prop))
                if actual!=expected:raise ValueError('DIRECT_PROPERTY_VALUE_DIFFERS_FROM_INPUT '+str(prop))
            else:
                prop,symbol,actual,ok=value
                if prop==71:expected=(prep['order_flags'],prep['order_ok'])
                elif prop==49:expected=take('ref-expiration',[(prep['expiration0'],prep['expiration_ok0']),(prep['expiration1'],prep['expiration_ok1'])])
                elif prop==17:expected=take('ref-digits',list(zip(env['digits'],env['digits_ok'])))
                elif prop==33:expected=take('ref-execution',list(zip(env['executions'],env['execution_ok'])))
                else:raise ValueError('UNKNOWN_REFERENCE_PROPERTY '+str(prop))
                if (actual,ok)!=expected:raise ValueError('REFERENCE_PROPERTY_VALUE_OR_STATUS_DIFFERS_FROM_INPUT '+str(prop))
    if inside:raise ValueError('FIXTURE_BUILDER_NOT_RETURNED')

def dependencies(bot):
    paths=[Path(__file__),Path(queue.__file__),Path(queue.errors.__file__),Path(send.__file__),Path(pending.__file__),Path(pending.fill.__file__),Path(pending.fill.validation.__file__),Path(pending.fill.validation.volume.__file__),Path(pending.fill.entry.__file__),Path(pending.fill.entry.price_check.__file__),send.LAYOUT]
    paths.extend(ROOT/name for name in json.loads(send.LAYOUT.read_text())['source_sha256'])
    folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
    home=ROOT/f'bot-cua-toi-{bot}';capture=home/'bang-chung/captures/luot-20261023-r1/capture.json'
    paths.extend([home/'phan-tich'/folder/'metadata/import.json',capture,home/'bang-chung/luot-20261023-r1/engine-observed.json'])
    paths.extend(capture.parent/region['file'] for region in json.loads(capture.read_text())['regions'])
    paths.extend(ROOT/'doi-chung-mt5/hang-doi-20261024/arithmetic-runtime-r2'/name for name in ['results.json','results.bin'])
    runtime=ROOT.parent/'.local/claude-recovery-20261023/python'
    paths.extend(path for package in ['unicorn','capstone'] for path in (runtime/package).rglob('*') if path.is_file() and path.suffix in ['.py','.dll'])
    return {(path.relative_to(ROOT).as_posix() if path.is_relative_to(ROOT) else '../'+path.relative_to(ROOT.parent).as_posix()):sha(path) for path in paths}
def read_results(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('RESULT_HEADER_DIFFERS')
    out=[]
    for i in range(n):
        start=rd.pos
        if rd.take('i')[0]!=i:raise ValueError('RESULT_CASE_ID_DIFFERS')
        while True:
            api=rd.take('i')[0]
            if api==0:break
            if api==1:rd.text()
            elif api==2:rd.take('3i4dq');rd.text();rd.text()
            elif api==3:rd.take('i')
            else:raise ValueError('BAD_QUEUE_TRACE_EVENT')
        rd.take('iIi3i');rd.take('500d');rd.take('6dq2i');rd.text();rd.text()
        trade_record(rd);rd.take('3iQ');out.append(rd.raw[start:rd.pos])
    if rd.pos!=len(rd.raw):raise ValueError('RESULT_BYTES_NOT_EXACT')
    return out

class Original(queue.Original):
    def __init__(self,bot,records,chart,digits):
        super().__init__(bot,{});self.bot=bot;self.records_by_id=records;self.chart=chart;self.default_digits=digits;self.casts={};self.fill_cfg=pending.fill.CFG[bot];self.layout=json.loads(send.LAYOUT.read_text())
        if not self.layout['runner_verified'] or not self.layout['only_anchor_executed'] or self.layout['relative_native_storage_bases']!={'request':0,'result':240,'check':436} or self.layout['end_marker_offset']!=628:raise ValueError('LAYOUT_NOT_VERIFIED')
        for name,digest in self.layout['source_sha256'].items():
            if sha(ROOT/name)!=digest:raise ValueError('LAYOUT_SOURCE_CHANGED')
        folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data';meta=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'metadata/import.json').read_text())
        required=[*send.RANGES[bot],self.pending_cfg['fn'],self.fill_cfg['fn']]
        for fn in required:
            if any(start==fn for start,end in self.ranges):continue
            row=next(f for f in meta['functions'] if int(f['begin_rva'],16)==fn);self.ranges.append((fn,int(row['end_rva'],16)))
        self.apis[self.base+self.pending_cfg['fn']]=51
        for address,kind in list(self.apis.items()):
            if kind==3:self.apis[address]=47
    def state(self):return pending.Original.state_bytes(self)
    def strings(self):
        start=self.base+self.fill_cfg['request']
        return [self.text(start+offset) for offset in [20,100,240+52,436+52]]
    def state_record(self):return self.state()+b''.join(send.pack_text(value) for value in self.strings())
    def assert_trade_record(self,expected):
        if expected!=(self.state(),self.strings()):raise ValueError('TRADE_STATE_OR_FULL_STRINGS_DIFFER')
    def initialize_trade(self):
        self.executing=False;env=self.pipeline_row['send'];prep=self.pipeline_row['prep'];m=self.m;cfg=self.send_cfg;start=self.base+self.fill_cfg['request'];context=self.base+cfg['context']
        m.mem_write(start,b'\x5a'*628);self.populate('request',start,env['request'],bool(env['symbol_null']));self.populate('result',start+240,env['result'])
        self.populate('check',start+436,{f['name']:f['value'] for f in self.schemas['check']['fields']})
        m.mem_write(context+660,bytes([env['async_mode']]));m.mem_write(context+681,struct.pack('<i',env['margin_mode']));m.mem_write(context+685,struct.pack('<i',env['log_level']))
        self.supply(self.base+cfg['chart'],self.chart);m.mem_write(self.base+cfg['digits'],struct.pack('<i',self.default_digits))
        m.mem_write(self.base+self.pending_cfg['stopped'],struct.pack('<i',prep['stopped']));m.mem_write(self.base+self.pending_cfg['magic'],struct.pack('<Q',0x7654321076543210));m.mem_write(self.base+self.fill_cfg['preferred'],struct.pack('<i',prep['preferred']))
        self.signed_casts={}
        for code,text in self.next(12):
            if code in self.signed_casts and self.signed_casts[code]!=text:raise ValueError('SIGNED_CAST_METADATA_INCONSISTENT')
            self.signed_casts[code]=text
        self.trade_initialized=True;self.executing=True
    def visit(self,m,address,size,user):
        if address==self.base+self.queue_cfg['fn'] and not self.trade_initialized:self.initialize_trade()
        if self.builder_frame and address==self.builder_frame['return'] and m.reg_read(self.x.UC_X86_REG_RSP)==self.builder_frame['rsp']+8:
            actual=m.reg_read(self.x.UC_X86_REG_EAX);expected,state=self.next(11)
            if actual!=expected:raise ValueError('BUILDER_ACTUAL_EAX_DIFFERS '+str((actual,expected)))
            self.assert_trade_record(state);start=self.base+self.fill_cfg['request']
            if self.pipeline_row['prep']['stopped']:
                storage=bytearray(self.builder_frame['storage']);storage[240:244]=struct.pack('<I',10027)
                if bytes(m.mem_read(start,628))!=bytes(storage):raise ValueError('STOPPED_BUILDER_CHANGED_OTHER_STORAGE')
            else:
                for offset,length in [(128,112),(312,124),(500,128)]:
                    if bytes(m.mem_read(start+offset,length))!=b'\0'*length:raise ValueError('BUILDER_RESERVED_STORAGE_NOT_CLEARED')
            self.builder_frame=None;self.sends+=1;self.patch(2)
        return super().visit(m,address,size,user)
    def write_guard(self,m,access,address,size,value,user):
        if self.executing:
            for rva,length in [(self.fill_cfg['request'],628),(self.pending_cfg['magic'],8),(self.fill_cfg['preferred'],4)]:
                if self.base+rva<=address and address+size<=self.base+rva+length:return
        return super().write_guard(m,access,address,size,value,user)
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x;sp=m.reg_read(x.UC_X86_REG_RSP)
        if api==51:
            if self.builder_frame:raise ValueError('NESTED_BUILDER_UNEXPECTED')
            target=struct.unpack('<Q',m.mem_read(sp,8))[0]
            if target-self.base not in RETURNS[self.bot]:raise ValueError('BUILDER_RETURN_NOT_QUEUE_CALLSITE')
            type_=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;volume=m.reg_read(x.UC_X86_REG_XMM2)&send.MASK;price=m.reg_read(x.UC_X86_REG_XMM3)&send.MASK
            sl,tp,comment,expiry=struct.unpack('<2dQq',m.mem_read(sp+40,32));symbol=self.text(m.reg_read(x.UC_X86_REG_RCX));text=self.text(comment)
            magic=struct.unpack('<i',m.mem_read(self.base+self.pending_cfg['magic_input'],4))[0];virtual=m.mem_read(self.base+self.pending_cfg['virtual'],1)[0]
            self.trace+=struct.pack('<4i2Q2dq',2,type_,magic,virtual,volume,price,sl,tp,expiry)+send.pack_text(symbol)+send.pack_text(text)
            casts,before=self.next(10);self.assert_trade_record(before);self.casts[self.case['id']]=casts
            env=self.pipeline_row['send'];self.case.update(write_result=env['write_result'],new_result=env['new_result'],request={'action':5,'type':type_},result={'retcode':0})
            self.builder_frame={'return':target,'rsp':sp,'storage':bytes(m.mem_read(self.base+self.fill_cfg['request'],628))}
            return
        if api in [41,42]:
            replies=self.case['replies']
            if replies and self.sends>=len(replies):raise ValueError('EXTRA_SEND_REPLY')
            supplied=self.records[self.position]
            if supplied[0]!=1 or supplied[1][1]!=(replies[self.sends][0] if replies else 1):raise ValueError('SUPPLIED_SEND_BOOL_DIFFERS_FROM_CASE')
            send.Original.call(self,m,address,size,user)
            error=replies[self.sends][1] if replies else 0;self.executing=False;self.write('last_error','i',error);self.executing=True;self.actual_send_calls+=1;return
        if api==43:
            record=self.records[self.position]
            send.Original.call(self,m,address,size,user)
            if not record[1][-1]:
                self.executing=False;self.write('last_error','i',self.pipeline_row['prep']['property_error']);self.executing=True
            return
        if api==47:
            prop,text,value=self.next(9)
            if m.reg_read(x.UC_X86_REG_R8)&0xffffffff!=prop or self.text(m.reg_read(x.UC_X86_REG_RDX))!=text:raise ValueError('DIRECT_PROPERTY_ARGUMENTS_DIFFER')
            m.reg_write(x.UC_X86_REG_RAX,value&send.MASK);return
        if api==45 and self.builder_frame:
            opcode=m.reg_read(x.UC_X86_REG_RDX);count=m.reg_read(x.UC_X86_REG_R8)
            if opcode==2 or (opcode==13 and count==2):
                if m.reg_read(x.UC_X86_REG_R9)!=0x590008:raise ValueError('PREPARATION_MESSAGE_TYPE_DIFFERS')
                actual=[]
                for i in range(count):
                    if i and struct.unpack('<I',m.mem_read(sp+32+16*i,4))[0]!=0x590008:raise ValueError('PREPARATION_MESSAGE_TYPE_DIFFERS')
                    actual.append(self.text(struct.unpack('<Q',m.mem_read(sp+40+16*i,8))[0]))
                expected=self.next(7 if opcode==2 else 8)
                if count!=(len(expected) if opcode==2 else 2) or actual!=list(expected[:count]):raise ValueError('PREPARATION_MESSAGE_ARGUMENTS_DIFFER')
                return
            return send.Original.call(self,m,address,size,user)
        if api==46 and m.reg_read(x.UC_X86_REG_R8)==0x53:return send.Original.call(self,m,address,size,user)
        if api in [44]:return send.Original.call(self,m,address,size,user)
        return super().call(m,address,size,user)
    def run(self,row):
        self.pipeline_row=row;self.trade_initialized=False;self.builder_frame=None;self.position=0;self.records=self.records_by_id[row['id']];self.print_count=self.print_hash=self.actual_send_calls=0
        raw=super().run(dict(row['queue']))
        if self.builder_frame or self.position!=len(self.records):raise ValueError('PIPELINE_RECORDS_NOT_CONSUMED '+str((self.position,len(self.records))))
        return raw+self.state_record()+struct.pack('<3iQ',self.position,self.actual_send_calls,self.print_count,self.print_hash)

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','mql5','original','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,48}',a.run):raise ValueError('INVALID_RUN')
    home=ROOT/f'bot-cua-toi-{a.bot}';out=home/'bang-chung/kiem-chuoi-dat-lenh'/a.run
    if a.mode=='prepare':
        digest=pending.fill.validation.original_hash(a.bot);out.mkdir(parents=True,exist_ok=False);rows=cases();(out/'cases.bin').write_bytes(encode(rows));descriptions=copy.deepcopy(rows)
        for row in descriptions:
            q=row['queue']
            for name in queue.CONTEXT:q[name]=struct.pack('<d',q[name]).hex()
            for key in ['orders','results']:q[key]=[[struct.pack('<d',v).hex() for v in values] for values in q[key]]
            row['send']=send.json_cases([row['send']])[0]
        save(out/'cases.json',descriptions);save(out/'baseline.json',dict(cases=len(rows),original_ex5_sha256=digest,cases_sha256=sha(out/'cases.bin'),tool_sha256=sha(Path(__file__))))
        print(json.dumps({'cases':len(rows)}));return
    baseline=json.loads((out/'baseline.json').read_text());rows=read_cases(out/'cases.bin');n=len(rows)
    if sha(out/'cases.bin')!=baseline['cases_sha256'] or pending.fill.validation.original_hash(a.bot)!=baseline['original_ex5_sha256']:raise ValueError('INPUTS_CHANGED')
    if a.mode=='mql5':
        if not a.build or not re.fullmatch('[a-z0-9-]+',a.build):raise ValueError('BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'));target=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PendingPipelineCheck.mq5';binary=MT/'MQL5'/target.replace('.mq5','.ex5')
        if receipt['target']!=target or receipt['errors'] or receipt['warnings'] or sha(binary)!=receipt['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
        names=[target,f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PipelineApi.mqh']+[f'Include/bot-cua-toi-{a.bot}/Bot{a.bot}{name}.mqh' for name in ['PendingQueue','TradeErrors','TradeSend','TradeMessages','PendingRequest','Filling']]
        for name in names:
            if sha(home/'source/MQL5'/name)!=receipt['sources_sha256'][name] or sha(MT/'MQL5'/name)!=receipt['sources_sha256'][name]:raise ValueError('TESTED_SOURCE_CHANGED '+name)
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-pending-pipeline'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin')
        preset=MT/'MQL5/Presets'/f'b{a.bot}-pipeline-{a.run}.set';preset.write_text(f'CheckRun={a.run}\n',encoding='utf-16')
        ini=MT/f'b{a.bot}-pipeline-{a.run}.ini';ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PendingPipelineCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        start=time.monotonic();p=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=120)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=30);raise RuntimeError('MT5_PIPELINE_TIMEOUT')
        if code:raise RuntimeError('MT5_PIPELINE_FAILED '+str(code))
        for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']:shutil.copyfile(files/name,out/name)
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,n):raise ValueError('SCRIPT_DID_NOT_COMPLETE')
        if sha(binary)!=receipt['binary_sha256']:raise ValueError('BINARY_CHANGED_DURING_RUN')
        save(out/'mql5-run.json',dict(exit_code=code,seconds=round(time.monotonic()-start,2),script_sha256=sha(binary),build_receipt=receipt_path.relative_to(ROOT).as_posix(),build_receipt_sha256=sha(receipt_path),sources_sha256={name:receipt['sources_sha256'][name] for name in names},hashes={name:sha(out/name) for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']}))
        print(json.dumps({'cases':len(read_results(out/'mql5-results.bin',n))}));return
    if a.mode=='original':
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        records,chart,digits=fixtures(out/'api-fixtures.bin',n)
        for row in rows:validate_fixture_inputs(row,records[row['id']])
        o=Original(a.bot,records,chart,digits);start=time.monotonic();values=[]
        for row in rows:
            try:values.append(o.run(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,1,n)+b''.join(values));save(out/'original-run.json',dict(cases=n,seconds=round(time.monotonic()-start,2),result_sha256=sha(out/'original-results.bin'),fixtures_sha256=sha(out/'api-fixtures.bin'),tool_sha256=sha(Path(__file__)),dependencies_sha256=dependencies(a.bot),fixture_input_contract_checked_cases=n,cpu_nan_reference_sha256=o.nan_reference_sha256,scope=__doc__))
        print(json.dumps({'cases':n}));return
    mql5=json.loads((out/'mql5-run.json').read_text());native=json.loads((out/'original-run.json').read_text());receipt_path=ROOT/mql5['build_receipt'];receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    if sha(receipt_path)!=mql5['build_receipt_sha256'] or receipt['binary_sha256']!=mql5['script_sha256'] or sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name)!=mql5['script_sha256']:raise ValueError('BUILD_EVIDENCE_CHANGED')
    for name,digest in mql5['sources_sha256'].items():
        if sha(home/'source/MQL5'/name)!=digest:raise ValueError('CURRENT_SOURCE_CHANGED '+name)
    for name,digest in mql5['hashes'].items():
        if sha(out/name)!=digest:raise ValueError('MQL5_EVIDENCE_CHANGED')
    if sha(out/'original-results.bin')!=native['result_sha256'] or sha(out/'api-fixtures.bin')!=native['fixtures_sha256'] or sha(Path(__file__))!=native['tool_sha256']:raise ValueError('NATIVE_EVIDENCE_CHANGED')
    if native['dependencies_sha256']!=dependencies(a.bot) or native['fixture_input_contract_checked_cases']!=n:raise ValueError('NATIVE_DEPENDENCIES_OR_INPUT_CONTRACT_CHANGED')
    if baseline['tool_sha256']!=native['tool_sha256'] or encode(cases())!=(out/'cases.bin').read_bytes():raise ValueError('CASE_GENERATOR_OR_PREPARATION_TOOL_CHANGED')
    records,chart,digits=fixtures(out/'api-fixtures.bin',n)
    for row in rows:validate_fixture_inputs(row,records[row['id']])
    original=read_results(out/'original-results.bin',n);actual=read_results(out/'mql5-results.bin',n);failures=[]
    for i,(x,y) in enumerate(zip(original,actual)):
        if x!=y:
            at=next((j for j,(a_,b_) in enumerate(zip(x,y)) if a_!=b_),min(len(x),len(y)));failures.append(dict(id=i,first_different_byte=at,original=x[at:at+16].hex(),mql5=y[at:at+16].hex()))
    result=dict(cases=n,matched=n-len(failures),failed=len(failures),fixture_input_contract_checked_cases=n,first_failures=failures[:10],hashes={name:sha(out/name) for name in ['cases.bin','original-results.bin','mql5-results.bin','api-fixtures.bin','script-status.bin']},whole_bot_complete=False,
                scope='Original queue runs the actual pending builder, filling, send wrapper and message/error functions. Real builder bool and35-field+four-full-string state checked before/after every call; all500 table doubles and terminal call order/arguments compared. Terminal properties/send outcomes/errors are supplied, formatting measured. No actual broker/full EA or allocation/CPU-fault claim.')
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))

if __name__=='__main__':main()
