"""Compare position scanners through the complete guard/close/filling/send path.

Usage: kiem-chon-vi-the-dong-bot-1-3.py prepare|mql5|original|compare BOT RUN [--build BUILD]
SDK replies are supplied and input-bound; formatting is measured in MT5.
Helper-entry instrumentation resets only test reply counters, not bot state.
No real orders, actual account selection, allocation faults or full-EA proof.
"""
import argparse
import copy
import importlib.util
import itertools
import json
import math
from pathlib import Path
import re
import shutil
import struct
import subprocess
import time

ROOT=Path(__file__).resolve().parents[1];MAGIC=0x50534c31
spec=importlib.util.spec_from_file_location('close_check',Path(__file__).with_name('kiem-dong-vi-the-bot-1-3.py'))
close=importlib.util.module_from_spec(spec);spec.loader.exec_module(close)
send=close.send;sha=close.sha;save=close.save;MT=close.MT
PROBE=ROOT/'doi-chung-mt5/chon-vi-the-dong-20261025/scan-api-r1'
CFG={1:dict(functions=[0x2fa00,0x2fce0],seed=0x6a610,ticket=0x677f8,symbol=0x67918),
     3:dict(functions=[0x3ce40,0x3d220],seed=0x1d6ff0,ticket=0x74838,symbol=0x74958)}

def signed32(value):return ((value+0x80000000)&0xffffffff)-0x80000000

def base(kind):
    row=close.base(1);row.update(kind=kind,scan_scenario=0,total=1,seed=42,prior_ticket=0x123456789abcdef0,target_null=0,selected=-1,target='XAUUSD',
                                positions=[[11,kind,.25,0,'XAUUSD',[43]*15]])
    return row

def cases():
    rows=[]
    def add(row,group):row.update(id=len(rows),group=group);row['send']['id']=row['id'];rows.append(row)
    for kind in [0,1]:
        for total in [-2147483648,-2,-1,0,1,2,3,4]:
            row=base(kind);row.update(total=total,positions=[[11+i,kind,.25,0,'XAUUSD',[43]*15] for i in range(4)]);add(row,'inclusive-indices')
        for seed,offset,variant in itertools.product([-2147483648,-1,0,42,2147483632,2147483640,2147483647],range(17),range(3)):
            actual=signed32(seed+offset);actual=actual if variant==0 else actual&0xffffffff if variant==1 else actual+(1<<32)
            row=base(kind);row.update(seed=seed);row['positions'][0][5]=[actual]*15;add(row,'signed32-identities-full64-query')
        for index in range(16):
            row=base(kind);values=[-999]*15
            if index<15:values[index]=signed32(42+index+1)
            row['positions'][0][5]=values;add(row,'reread-and-short-circuit-identities')
        symbols=[('',0),('',1),('XAUUSD',0),('xauusd',0),('Vàng.💰',0),('XAUUSD.long',0)]
        for (target,null),(actual,actual_null) in itertools.product(symbols,repeat=2):
            row=base(kind);row.update(target=target,target_null=null);row['positions'][0][3:5]=[actual_null,actual];add(row,'nullable-utf16-symbols')
        for actual in [-0x8000000000000000,-1,0,1,2,0x100000000,0x100000001,0x7fffffffffffffff]:
            row=base(kind);row['positions'][0][1]=actual;add(row,'full64-position-type')
        for ticket,volume in itertools.product([0,1,(1<<53)+1,(1<<63)+1,(1<<64)-1],[-math.inf,-0.,.25,math.inf,math.nan]):
            row=base(kind);row['positions'][0][0]=ticket;row['positions'][0][2]=volume;add(row,'ticket-width-and-unused-volume')
        for scenario in range(1,7):
            row=base(kind);row.update(scan_scenario=scenario,total=2,positions=[[11,kind,.25,0,'XAUUSD',[43]*15],[12,kind,.5,0,'Renamed',[43]*15]]);add(row,'controlled-scan-side-effects')
        for first,second,preferred in itertools.product([0,2,3],[0,2,3],[0,1,2,3]):
            for flags in [[1,0],[1,2],[2,1],[3,0],[0,3]]:
                row=base(kind);row.update(executions=[first,second],fillings=flags,preferred=preferred,types=[0,0,1,1]);add(row,'two-close-changing-filling-and-preference')
        for child in close.cases():
            if not (child['group'].startswith('full-send-') or child['group'] in ['guard-ordered-abs-boundaries','guard-two-close-paths','controlled-query-side-effects','state-null-versus-empty']):continue
            row=base(kind)
            for key in close.base(1):row[key]=copy.deepcopy(child[key])
            row['mode']=1;add(row,'full-close-'+child['group'])
    for kind in [0,1]:
        row=base(kind);row.update(scan_scenario=5,total=2,positions=[[12,kind,.5,0,'Renamed',[43]*15],[11,kind,.25,0,'XAUUSD',[43]*15]])
        add(row,'changed-globals-affect-next-candidate')
    return rows

def encode(rows):
    raw=bytearray(struct.pack('<3i',MAGIC,1,len(rows)))
    for row in rows:
        raw+=close.encode([row])[12:]+struct.pack('<4iQ2i',row['kind'],row['scan_scenario'],row['total'],row['seed'],row['prior_ticket'],row['target_null'],row['selected'])+send.pack_text(row['target'])
        raw+=struct.pack('<i',len(row['positions']))
        for ticket,kind,volume,null,symbol,magics in row['positions']:
            raw+=struct.pack('<Qqdi',ticket,kind,volume,null)+send.pack_text(symbol)+struct.pack('<15q',*magics)
    return raw

def read_cases(path):
    rd=send.Reader(path.read_bytes())
    if rd.take('2i')!=(MAGIC,1):raise ValueError('BAD_POSITION_SELECTION_HEADER')
    n=rd.take('i')[0];rows=[];schemas=send.layout()
    if not 1<=n<=30000:raise ValueError('BAD_POSITION_SELECTION_COUNT')
    for i in range(n):
        env=dict(zip(['id','async_mode','log_level','margin_mode','accepted','write_result'],rd.take('6i')));env.update(digits=list(rd.take('2q')),executions=list(rd.take('2q')))
        ok=rd.take('4i');env.update(digits_ok=list(ok[:2]),execution_ok=list(ok[2:]))
        for key in ['request','result','new_result']:
            values={}
            for field in schemas['request' if key=='request' else 'result']['fields']:
                if field['kind']=='s':
                    if field['name']=='symbol':env['symbol_null']=rd.take('i')[0]
                    values[field['name']]=rd.text()
                else:values[field['name']]=rd.take(field['kind'])[0]
            env[key]=values
        row=dict(zip(['mode','scenario','ticket','magic','deviation','stopped','preferred','position_magic'],rd.take('2i3Q2iq')));row.update(id=i,send=env)
        for name,fmt in [('select_ok','3i'),('types','4q'),('sl','4d'),('volumes','2d'),('prices','2d')]:row[name]=list(rd.take(fmt))
        row['symbols']=[[rd.take('i')[0],rd.text()] for _ in range(2)];row['executions']=list(rd.take('2q'));row['fillings']=list(rd.take('2q'));row['variables']=list(rd.take('4d'))
        row.update(zip(['kind','scan_scenario','total','seed','prior_ticket','target_null','selected'],rd.take('4iQ2i')));row['target']=rd.text();size=rd.take('i')[0]
        if not 0<=size<=16 or row['total']>32:raise ValueError('BAD_POSITION_SELECTION_SIZE')
        row['positions']=[]
        for _ in range(size):
            ticket,kind,volume,null=rd.take('Qqdi');row['positions'].append([ticket,kind,volume,null,rd.text(),list(rd.take('15q'))])
        if env['id']!=i or row['mode']!=1 or not 0<=row['scenario']<=5 or row['kind'] not in [0,1] or not 0<=row['scan_scenario']<=6 or not -1<=row['selected']<size:raise ValueError('BAD_POSITION_SELECTION_CASE')
        rows.append(row)
    if rd.pos!=len(rd.raw):raise ValueError('CASE_BYTES_NOT_EXACT')
    return rows

def state_block(rd):
    start=rd.pos;close.state_block(rd);rd.take('Q4i');rd.text();return rd.raw[start:rd.pos]

def fixtures(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('FIXTURE_HEADER_DIFFERS')
    chart=rd.text();digits=rd.take('i')[0];records={i:[] for i in range(n)}
    while rd.pos<len(rd.raw):
        cid,api=rd.take('2i')
        if cid not in records:raise ValueError('FIXTURE_ID_DIFFERS')
        if api==1:value=(*rd.take('2i'),rd.block(120),rd.block(68),rd.block(68))
        elif api==2:value=(rd.take('i')[0],rd.text(),*rd.take('qi'))
        elif api==3:value=(*rd.take('Qi'),rd.text())
        elif api==5:
            count=rd.take('i')[0];args=[]
            if not 1<=count<=6:raise ValueError('FORMAT_COUNT_DIFFERS')
            for _ in range(count):
                tag=rd.take('I')[0]
                if tag==0x590008:item=rd.text()
                elif tag==0x560015:item=rd.take('Q')[0]
                else:raise ValueError('FORMAT_TAG_DIFFERS')
                args.append((tag,item))
            value=(args,rd.text())
        elif api==6:value=tuple(rd.text() for _ in range(4))
        elif api==8:value=tuple(rd.text() for _ in range(3))
        elif api==9:value=(rd.take('i')[0],rd.text(),rd.take('q')[0])
        elif api==17:value=tuple(rd.text() for _ in range(4))
        elif api in [18,81]:value=state_block(rd)
        elif api==20:value=rd.take('iQi')
        elif api==21:value=rd.take('2iq')
        elif api==22:value=rd.take('2iQ')
        elif api==23:value=(*rd.take('3i'),rd.text())
        elif api==24:value=(*rd.take('3i'),rd.text(),rd.take('Q')[0])
        elif api==26:value=(rd.take('i')[0],rd.text())
        elif api==70:value=rd.take('i')
        elif api==71:value=rd.take('iQi')
        elif api==80:value=(rd.take('Q')[0],state_block(rd))
        else:raise ValueError('UNKNOWN_SCAN_FIXTURE '+str(api))
        records[cid].append((api,value))
    if rd.pos!=len(rd.raw):raise ValueError('FIXTURE_BYTES_NOT_EXACT')
    return records,chart,digits

def validate_inputs(row,records):
    index=row['total'];selected=row['selected'];magic_index=0;total_calls=0;ticket=0;helper=None;segment=[];casts=None
    for api,value in records:
        if api==17:
            close.validate_inputs(row,[(api,value)]);casts=(api,value);continue
        if api==80:
            if helper is not None or value[0]!=ticket:raise ValueError('HELPER_TICKET_INPUT_DIFFERS')
            helper=dict(row,ticket=value[0],mode=1);segment=[casts];continue
        if api==81:
            if helper is None:raise ValueError('HELPER_RETURN_WITHOUT_ENTRY')
            close.validate_inputs(helper,segment);helper=None;continue
        if helper is not None:segment.append((api,value));continue
        if api==18:continue
        if api==70:
            total_calls+=1
            if value!=(row['total'],):raise ValueError('TOTAL_INPUT_DIFFERS')
        elif api==71:
            actual,ticket,reply_selected=value;expected=row['positions'][index][0] if 0<=index<len(row['positions']) else 0
            if actual!=index or ticket!=expected:raise ValueError('SCAN_TICKET_INPUT_DIFFERS')
            if ticket:selected=index
            if reply_selected!=selected:raise ValueError('SCAN_SELECTION_INPUT_DIFFERS')
            index-=1;magic_index=0
        elif api in [21,22,23]:
            if not 0<=selected<len(row['positions']):raise ValueError('SCAN_QUERY_WITHOUT_SELECTION')
            p=row['positions'][selected]
            if api==21:
                prop,i,actual=value
                if prop==12:
                    if i!=magic_index or i>=15 or actual!=p[5][i]:raise ValueError('SCAN_MAGIC_INPUT_DIFFERS')
                    magic_index+=1
                elif prop==2:
                    if i!=0 or actual!=p[1]:raise ValueError('SCAN_TYPE_INPUT_DIFFERS')
                else:raise ValueError('SCAN_INTEGER_PROPERTY_DIFFERS')
            elif api==22:
                if value!=(3,0,close.cancel.bits(p[2])):raise ValueError('SCAN_VOLUME_INPUT_DIFFERS')
                if row['scan_scenario']==4:ticket=0xdeadbeef12345678
            elif value!=(0,0,p[3],p[4]):raise ValueError('SCAN_SYMBOL_INPUT_DIFFERS')
        else:raise ValueError('UNEXPECTED_SCANNER_RECORD '+str(api))
    if total_calls!=1 or index>=0 or helper is not None or casts is None:raise ValueError('SCAN_TRACE_INCOMPLETE')

def read_results(path,n):
    rd=send.Reader(path.read_bytes())
    if rd.take('3i')!=(MAGIC,1,n):raise ValueError('RESULT_HEADER_DIFFERS')
    rows=[]
    for i in range(n):
        start=rd.pos
        if rd.take('i')[0]!=i:raise ValueError('RESULT_ID_DIFFERS')
        state_block(rd);rd.take('6iQ');rows.append(rd.raw[start:rd.pos])
    if rd.pos!=len(rd.raw):raise ValueError('RESULT_BYTES_NOT_EXACT')
    return rows

def dependencies(bot):
    result=close.dependencies(bot);paths=[Path(__file__),ROOT/'cong-cu/kiem-api-chon-vi-the.py',ROOT/'cong-cu/tao-kiem-chon-vi-the-dong.py']
    paths.extend(PROBE/name for name in ['api-contract.json','calibration.json','build.json','engine-observed.json','RecoveryApiLibrary.mq5','RecoveryApiDriver.mq5'])
    cap=PROBE/'captures/library/capture.json';paths.append(cap);paths.extend(cap.parent/r['file'] for r in json.loads(cap.read_text())['regions'])
    paths.extend(ROOT/f'bot-cua-toi-{bot}/phan-tich/dong-vi-the/scan-20261025-r1'/name for name in ['analysis.json','semantics.json','native-guards.txt'])
    for path in paths:result[path.relative_to(ROOT).as_posix()]=sha(path)
    return result

class Original(close.Original):
    def __init__(self,bot,records,chart,digits):
        super().__init__(bot,records,chart,digits);self.scan=CFG[bot];self.close={**self.close,'functions':self.close['functions']+self.scan['functions']}
        contract=json.loads((PROBE/'api-contract.json').read_text())
        if not contract['runner_verified'] or not contract['only_anchor_executed'] or contract['calibration_sha256']!=sha(PROBE/'calibration.json'):raise ValueError('SCAN_API_NOT_VERIFIED')
        analysis=json.loads((ROOT/f'bot-cua-toi-{bot}/phan-tich/dong-vi-the/scan-20261025-r1/analysis.json').read_text())
        for fn in analysis['functions']:
            begin=int(fn['rva'],16);end=int(fn['end_rva'],16);self.ranges.append((begin,end))
            if __import__('hashlib').sha256(bytes(self.m.mem_read(self.base+begin,end-begin))).hexdigest()!=fn['native_bytes_sha256']:raise ValueError('SCAN_NATIVE_BYTES_CHANGED')
        eb=next(a for a,k in self.apis.items() if k==1)-0x7d3c40
        for name,rva,api in [('ScanTotal',0x7d7da0,70),('ScanTicket',0x7d7df0,71)]:
            if contract['sdk_sites'][name]['sdk_rva']!=hex(rva):raise ValueError('SCAN_SDK_TARGET_DIFFERS')
            address=eb+rva;page=address&~4095
            if address in self.apis:raise ValueError('SCAN_SDK_HOOK_ALREADY_EXISTS')
            if not any(lo<=page<=hi for lo,hi,_ in self.m.mem_regions()):self.m.mem_map(page,4096)
            self.apis[address]=api;self.m.mem_write(address,b'\xc3');self.m.hook_add(self.uc.UC_HOOK_CODE,self.call,begin=address,end=address)
    def write_guard(self,m,access,address,size,value,user):
        if self.executing and self.base+self.scan['ticket']<=address and address+size<=self.base+self.scan['ticket']+8:return
        return super().write_guard(m,access,address,size,value,user)
    def state_record(self):
        m=self.m;cfg=self.scan;pointer=struct.unpack('<Q',m.mem_read(self.base+cfg['symbol']+4,8))[0]
        return super().state_record()+bytes(m.mem_read(self.base+cfg['ticket'],8))+bytes(m.mem_read(self.base+cfg['seed'],4))+struct.pack('<3i',int(pointer==0),self.selected,self.helper_calls)+send.pack_text(self.text(self.base+cfg['symbol']))
    def scan_change(self,api):
        row=self.scan_row;m=self.m;cfg=self.scan;self.executing=False
        try:
            if (api==70 and row['scan_scenario']==1) or (api==71 and self.scan_ticket_calls==1 and row['scan_scenario']==2):m.mem_write(self.base+cfg['seed'],struct.pack('<i',-1))
            if (api==21 and self.scan_magic_index==1 and row['scan_scenario']==3) or (api==23 and row['scan_scenario']==6):self.supply(self.base+cfg['symbol'],'Renamed')
            if api==22 and row['scan_scenario']==4:m.mem_write(self.base+cfg['ticket'],struct.pack('<Q',0xdeadbeef12345678))
            if api==81 and self.helper_calls==1 and row['scan_scenario']==5:m.mem_write(self.base+cfg['seed'],struct.pack('<i',-1));self.supply(self.base+cfg['symbol'],'Renamed')
        finally:self.executing=True
    def visit(self,m,address,size,user):
        if not self.entered and address in [self.base+r for r in self.scan['functions']]:
            self.executing=False;row=self.scan_row;cfg=self.scan
            m.mem_write(self.base+cfg['seed'],struct.pack('<i',row['seed']));m.mem_write(self.base+cfg['ticket'],struct.pack('<Q',row['prior_ticket']));self.supply(self.base+cfg['symbol'],row['target'])
            if row['target_null']:m.mem_write(self.base+cfg['symbol'],b'\0'*12)
            self.entered=True;self.executing=True
        if self.in_helper and address==self.helper_return:
            if m.reg_read(self.x.UC_X86_REG_RSP)!=self.helper_rsp+8:raise ValueError('HELPER_STACK_NOT_RESTORED')
            if self.next(81)!=self.state_record():raise ValueError('HELPER_RETURN_STATE_DIFFERS')
            self.in_helper=False;self.scan_change(81)
        if address==self.base+self.close['functions'][1]:
            if self.in_helper:raise ValueError('UNEXPECTED_NESTED_CLOSE_GUARD')
            self.helper_calls+=1;self.in_helper=True;self.select_calls=self.sl_calls=self.volume_calls=0
            ticket,state=self.next(80);self.helper_rsp=m.reg_read(self.x.UC_X86_REG_RSP);self.helper_return=struct.unpack('<Q',m.mem_read(self.helper_rsp,8))[0]
            if m.reg_read(self.x.UC_X86_REG_RCX)!=ticket or state!=self.state_record():raise ValueError('HELPER_ENTRY_DIFFERS')
        return super().visit(m,address,size,user)
    def call(self,m,address,size,user):
        api=self.apis[address];x=self.x
        if api==70:
            self.snapshot();total,=self.next(70);m.reg_write(x.UC_X86_REG_RAX,total&send.MASK);self.scan_change(70);return
        if api==71:
            self.snapshot();index,ticket,selected=self.next(71)
            if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=index&0xffffffff:raise ValueError('SCAN_TICKET_ARGUMENT_DIFFERS')
            self.selected=selected;self.scan_ticket_calls+=1;self.scan_magic_index=0;m.reg_write(x.UC_X86_REG_RAX,ticket);self.scan_change(71);return
        if not self.in_helper and api in [61,62,63]:
            if api==62:
                self.snapshot();prop,index,value=self.next(22)
                if m.reg_read(x.UC_X86_REG_RDX)&0xffffffff!=prop:raise ValueError('SCAN_DOUBLE_PROPERTY_DIFFERS')
                m.mem_write(self.base+self.cfg['slot'],struct.pack('<Q',value));m.reg_write(x.UC_X86_REG_XMM0,value);self.scan_change(22);return
            prop=m.reg_read(x.UC_X86_REG_RDX)&0xffffffff;result=super().call(m,address,size,user)
            if api==61 and prop==12:self.scan_magic_index+=1
            self.scan_change(21 if api==61 else 23);return result
        return super().call(m,address,size,user)
    def run_selection(self,row):
        self.scan_row=row;self.entered=False;self.in_helper=False;self.helper_return=None;self.helper_rsp=None;self.helper_calls=0;self.scan_ticket_calls=0;self.scan_magic_index=0;self.selected=row['selected']
        result=super().run_close(dict(row,mode=2+row['kind']))
        if self.in_helper:raise ValueError('CLOSE_GUARD_DID_NOT_RETURN_TO_SCAN')
        return result

def names(bot):
    return [f'Scripts/bot-cua-toi-{bot}/Bot{bot}PositionSelectionCheck.mq5',f'Scripts/bot-cua-toi-{bot}/Bot{bot}PipelineApi.mqh']+[f'Include/bot-cua-toi-{bot}/Bot{bot}{name}.mqh' for name in ['PositionSelection','PositionClose','TradeSend','TradeMessages','PendingRequest','Filling']]

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('mode',choices=['prepare','mql5','original','compare']);parser.add_argument('bot',type=int,choices=[1,3]);parser.add_argument('run');parser.add_argument('--build');a=parser.parse_args()
    if not re.fullmatch('[a-z0-9-]{1,40}',a.run):raise ValueError('INVALID_RUN')
    home=ROOT/f'bot-cua-toi-{a.bot}';out=home/'bang-chung/kiem-chon-vi-the-dong'/a.run
    if a.mode=='prepare':
        digest=close.pending.fill.validation.original_hash(a.bot);rows=cases();out.mkdir(parents=True,exist_ok=False);(out/'cases.bin').write_bytes(encode(rows));descriptions=copy.deepcopy(rows)
        for row in descriptions:
            for key in ['sl','volumes','prices','variables']:row[key]=[struct.pack('<d',v).hex() for v in row[key]]
            for position in row['positions']:position[2]=struct.pack('<d',position[2]).hex()
            row['send']=send.json_cases([row['send']])[0]
        save(out/'cases.json',descriptions);save(out/'baseline.json',dict(cases=len(rows),cases_sha256=sha(out/'cases.bin'),original_ex5_sha256=digest,tool_sha256=sha(Path(__file__))));print(json.dumps(dict(cases=len(rows))));return
    baseline=json.loads((out/'baseline.json').read_text());rows=read_cases(out/'cases.bin');n=len(rows)
    if baseline['cases_sha256']!=sha(out/'cases.bin') or baseline['original_ex5_sha256']!=close.pending.fill.validation.original_hash(a.bot) or baseline['tool_sha256']!=sha(Path(__file__)):raise ValueError('INPUT_OR_ORIGINAL_OR_TOOL_CHANGED')
    if a.mode=='mql5':
        if not a.build or not re.fullmatch('[a-z0-9-]+',a.build):raise ValueError('BUILD_REQUIRED')
        receipt_path=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'));target=names(a.bot)[0];binary=MT/'MQL5'/target.replace('.mq5','.ex5')
        if receipt['target']!=target or receipt['errors']!=0 or receipt['warnings']!=0 or sha(binary)!=receipt['binary_sha256']:raise ValueError('BUILD_NOT_VERIFIED')
        for name in names(a.bot):
            if sha(home/'source/MQL5'/name)!=receipt['sources_sha256'][name] or sha(MT/'MQL5'/name)!=receipt['sources_sha256'][name]:raise ValueError('TESTED_SOURCE_CHANGED')
        if (out/'mql5-results.bin').exists():raise FileExistsError('MQL5_RESULTS_EXIST')
        files=MT/f'MQL5/Files/bot{a.bot}-position-selection'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(out/'cases.bin',files/'cases.bin');preset=MT/'MQL5/Presets'/f'b{a.bot}-ps-{a.run}.set';preset.write_text(f'CheckRun={a.run}\n',encoding='utf-16');ini=MT/f'b{a.bot}-ps-{a.run}.ini'
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PositionSelectionCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        before=sha(MT/'terminal64.exe');started=time.monotonic();process=subprocess.Popen(f'"{MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MT5_POSITION_SELECTION_TIMEOUT')
        if code or before!=sha(MT/'terminal64.exe'):raise RuntimeError('MT5_RUN_FAILED_OR_TERMINAL_CHANGED')
        for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']:shutil.copyfile(files/name,out/name)
        if struct.unpack('<2i',(out/'script-status.bin').read_bytes())!=(0,n):raise ValueError('SCAN_SCRIPT_INCOMPLETE')
        save(out/'mql5-run.json',dict(cases=n,exit_code=code,seconds=round(time.monotonic()-started,2),script_sha256=sha(binary),terminal_sha256=before,tool_sha256=sha(Path(__file__)),build_receipt=receipt_path.relative_to(ROOT).as_posix(),build_receipt_sha256=sha(receipt_path),sources_sha256={name:receipt['sources_sha256'][name] for name in names(a.bot)},hashes={name:sha(out/name) for name in ['mql5-results.bin','api-fixtures.bin','script-status.bin']}));print(json.dumps(dict(cases=n)));return
    if a.mode=='original':
        if (out/'original-results.bin').exists():raise FileExistsError('NATIVE_RESULTS_EXIST')
        records,chart,digits=fixtures(out/'api-fixtures.bin',n)
        for row in rows:validate_inputs(row,records[row['id']])
        o=Original(a.bot,records,chart,digits);started=time.monotonic();values=[]
        for row in rows:
            try:values.append(o.run_selection(row))
            except Exception as error:raise RuntimeError(f'case={row["id"]} rva={o.m.reg_read(o.x.UC_X86_REG_RIP)-o.base:#x} {error}') from error
        (out/'original-results.bin').write_bytes(struct.pack('<3i',MAGIC,1,n)+b''.join(values));save(out/'original-run.json',dict(cases=n,seconds=round(time.monotonic()-started,2),result_sha256=sha(out/'original-results.bin'),fixture_sha256=sha(out/'api-fixtures.bin'),tool_sha256=sha(Path(__file__)),dependencies_sha256=dependencies(a.bot),input_contract_checked_cases=n,scope=__doc__));print(json.dumps(dict(cases=n)));return
    mql=json.loads((out/'mql5-run.json').read_text());native=json.loads((out/'original-run.json').read_text());receipt_path=ROOT/mql['build_receipt'];receipt=json.loads(receipt_path.read_text(encoding='utf-8-sig'))
    if receipt['target']!=names(a.bot)[0] or set(mql['sources_sha256'])!=set(names(a.bot)) or mql['terminal_sha256']!=sha(MT/'terminal64.exe'):raise ValueError('MQL_TARGET_OR_TERMINAL_CHANGED')
    if receipt['errors']!=0 or receipt['warnings']!=0 or sha(receipt_path)!=mql['build_receipt_sha256'] or receipt['binary_sha256']!=mql['script_sha256'] or sha(receipt_path.parent/Path(receipt['target']).with_suffix('.ex5').name)!=mql['script_sha256'] or mql['tool_sha256']!=baseline['tool_sha256']:raise ValueError('BUILD_OR_TOOL_EVIDENCE_CHANGED')
    for name,digest in mql['sources_sha256'].items():
        if receipt['sources_sha256'][name]!=digest or sha(home/'source/MQL5'/name)!=digest:raise ValueError('CURRENT_OR_COMPILED_SOURCE_CHANGED')
    for name,digest in mql['hashes'].items():
        if sha(out/name)!=digest:raise ValueError('MQL_EVIDENCE_CHANGED')
    if sha(out/'original-results.bin')!=native['result_sha256'] or sha(out/'api-fixtures.bin')!=native['fixture_sha256'] or native['dependencies_sha256']!=dependencies(a.bot) or native['tool_sha256']!=baseline['tool_sha256'] or encode(cases())!=(out/'cases.bin').read_bytes():raise ValueError('NATIVE_OR_GENERATED_INPUT_CHANGED')
    records,_,_=fixtures(out/'api-fixtures.bin',n)
    for row in rows:validate_inputs(row,records[row['id']])
    expected=read_results(out/'original-results.bin',n);actual=read_results(out/'mql5-results.bin',n);failures=[]
    for i,(left,right) in enumerate(zip(expected,actual)):
        if left!=right:
            at=next((j for j,(x,y) in enumerate(zip(left,right)) if x!=y),min(len(left),len(right)));failures.append(dict(id=i,first_different_byte=at,original=left[at:at+20].hex(),mql5=right[at:at+20].hex()))
    result=dict(cases=n,matched=n-len(failures),failed=len(failures),first_failures=failures[:12],hashes={name:sha(out/name) for name in ['cases.bin','original-results.bin','mql5-results.bin','api-fixtures.bin','script-status.bin']},whole_bot_complete=False,scope=__doc__)
    save(out/'comparison.json',result);print(json.dumps(result));raise SystemExit(bool(failures))

if __name__=='__main__':main()
