"""Controlled input captures: analyze names/values against native input storage.

Usage: python -I -B -X utf8 phan-tich-cai-dat-bot-1-3.py prepare|extend|capture|audit|compare BOT RUN [--case CASE]
The capture phase starts the original in the private demo Strategy Tester, reads
code/data, then intentionally stops only its observed private processes. It is not
a completed trading test. Compare requires every prepared case; never fills gaps.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
import time

ROOT=Path(__file__).resolve().parents[1]
MT=ROOT.parent/'.local/claude-recovery-20261023/mt5'
ENGINE_SHA='5033d9d45d669cebd735e8a6be20b54d74b75274f885c9a0e48e52d872104efb'
ORIGINALS={1:('820755052E4765D7D56E6DAAFBB28091','Gold Trade Pro MT5.ex5','a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922'),
           3:('D0E8209F77C8CF37AD8BF550E51FF075','The Gold Reaper MT5.ex5','ee063d3d87490afe24e2f4ce85f6b05659320e297b102efd70207f71ca2feb83')}
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def processes():
    script="Get-Process terminal64,metatester64 -ErrorAction SilentlyContinue | ForEach-Object { [pscustomobject]@{id=$_.Id;path=$_.Path;base=$_.MainModule.BaseAddress.ToInt64();started=$_.StartTime.Ticks} } | ConvertTo-Json -Compress"
    p=subprocess.run(['powershell','-NoProfile','-Command',script],capture_output=True,text=True)
    raw=p.stdout.strip()
    if not raw:return []
    rows=json.loads(raw);rows=rows if isinstance(rows,list) else [rows]
    return [r for r in rows if r.get('path') and Path(r['path']).resolve().parent==MT.resolve()]
def stop_owned(rows):
    for r in rows:
        expected_path=str(Path(r['path']).resolve()).replace("'","''")
        script=f"$p=Get-Process -Id {int(r['id'])} -ErrorAction SilentlyContinue; if ($p -and $p.StartTime.Ticks -eq {int(r['started'])} -and $p.Path -eq '{expected_path}') {{ try {{ Stop-Process -Id $p.Id -ErrorAction Stop }} catch {{ if (Get-Process -Id {int(r['id'])} -ErrorAction SilentlyContinue) {{ throw }} }} }}; exit 0"
        subprocess.run(['powershell','-NoProfile','-Command',script],check=True,capture_output=True,text=True)
def logged_inputs(offsets,names):
    values={}
    for path in MT.glob('Tester/**/*.log'):
        with path.open('rb') as stream:
            start=offsets.get(path,0)
            if path.stat().st_size<start:start=0
            stream.seek(start);raw=stream.read()
        for line in raw.decode('utf-16-le',errors='replace').splitlines():
            tail=line.split('\t')[-1].lstrip()
            if '=' in tail:
                name,value=tail.split('=',1)
                if name in names:values[name]=value
    return values
def parse_saved_inputs(path,names):
    values={}
    for line in path.read_text(encoding='utf-8').splitlines():
        tail=line.split('\t')[-1].lstrip()
        if '=' in tail:
            name,value=tail.split('=',1)
            if name in names:values[name]=value
    return values
def observed(bot):
    folder='luot-20261023-data-v2' if bot==1 else 'luot-20261023-data'
    source=ROOT/f'bot-cua-toi-{bot}/phan-tich'/folder/'tham-so-quan-sat.json'
    return source,json.loads(source.read_text())
def plan(bot):
    source,old=observed(bot);offset=0x6a518 if bot==1 else 0x1d6f18;fields=[];boolean=0;number=0
    original_journal=ROOT.parents[1]/old['source_log']
    original_values=parse_saved_inputs(original_journal,{s.split('=',1)[0] for s in old['inputs_observed']})
    if len(original_values)!=old['count']:raise ValueError('ORIGINAL_JOURNAL_INPUTS_INCOMPLETE')
    fixed_int={'BacktestSpeed','TradeFrequency','Risk','FakeOutFilter'}
    numeric={'InfoPanelSizeAdjust':'1.125','SetFontSize':'11','MaxSpread':'617.125','FridayStopHour':'23',
        'SetVSL_to_hardSL_sec_delay':'97','ST1_MagicNumber':str(53291+bot),
        'Broker_GMT_OFFSET_Winter':'2','Broker_GMT_OFFSET_Summer':'3','NFP_MinutesBefore':'13','NFP_MinutesAfter':'47',
        'IR_MinutesBefore':'17','IR_MinutesAfter':'43','CPI_MinutesBefore':'19','CPI_MinutesAfter':'41',
        'ManualBalance':'10417.125','StartLots':'0.023125','Manual_RiskPerTrade':'1.375','MaxRiskPerStrategy':'2.375',
        'MaxRiskPerStrategy_':'1.375','PropFirmMaxDailyDD':'2.125','LotPerBalance_step':'601','MaxAllowedDD':'27.125',
        'Randomization':'0.125'}
    cases=[{'id':'defaults','inputs':{}}]
    for text in old['inputs_observed']:
        name,_=text.split('=',1);value=original_values[name]
        kind='bool' if value in ['true','false'] else 'double' if re.fullmatch(r'-?\d+\.\d+',value) else 'integer_or_enum' if re.fullmatch(r'-?\d+',value) else 'string'
        row={'name':name,'observed':value,'representation':kind,'candidate_rva':hex(offset),'slot_bytes':16 if kind=='string' else 8}
        if kind=='bool':row['boolean_id']=boolean+1;boolean+=1
        elif kind=='double':row['marker']=numeric.get(name,str(3.125+number));number+=1
        elif kind=='integer_or_enum':row['marker']=value if name in fixed_int else numeric[name]
        else:row['marker']=f'CHECK_B{bot}_{name}'
        fields.append(row);offset+=row['slot_bytes']
    bits=max(1,boolean.bit_length())
    for bit in range(bits):
        values={}
        for f in fields:
            values[f['name']]=('true' if f['boolean_id']&(1<<bit) else 'false') if f['representation']=='bool' else f['marker']
        cases.append({'id':f'bits-{bit}','inputs':values})
    return {'bot':bot,'observed_source':source.relative_to(ROOT).as_posix(),'observed_source_sha256':sha(source),
        'original_journal':str(original_journal),'original_journal_sha256':sha(original_journal),
        'layout_status':'candidate by observed order; must be checked across all captures before using as binding',
        'fields':fields,'boolean_count':boolean,'candidate_end_rva':hex(offset),'cases':cases}
def read_capture(capdir):
    cap=json.loads((capdir/'capture.json').read_text());regions=[]
    for r in cap['regions']:
        path=capdir/r['file']
        if sha(path)!=r['sha256']:raise ValueError('CAPTURE_HASH_MISMATCH')
        regions.append((r,path.read_bytes()))
    code=max((r for r,_ in regions if r.get('kind')=='executable'),key=lambda r:r['bytes'])
    return cap,code,regions
def scalar(regions,address,size):
    for r,raw in regions:
        if r.get('kind')=='mutable_program_data' and r['base']<=address and address+size<=r['base']+len(raw):return raw[address-r['base']:address-r['base']+size]
    raise ValueError('INPUT_OUTSIDE_PROGRAM_DATA')
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('mode',choices=['prepare','extend','capture','audit','compare']);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--case');a=ap.parse_args()
    if not re.fullmatch('[a-z0-9-]+',a.run):raise ValueError('INVALID_RUN')
    out=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/phan-tich-cai-dat'/a.run
    if a.mode=='prepare':
        out.mkdir(parents=True,exist_ok=False);p=plan(a.bot);(out/'plan.json').write_text(json.dumps(p,ensure_ascii=False,indent=2),encoding='utf-8');print(json.dumps({'fields':len(p['fields']),'booleans':p['boolean_count'],'cases':[c['id'] for c in p['cases']]}));return
    p=json.loads((out/'plan.json').read_text())
    extra_path=out/'extra-cases.json'
    if a.mode=='extend':
        if extra_path.exists():raise FileExistsError(extra_path)
        values={f['name']:f['observed'] if f['representation']=='bool' else f['marker'] for f in p['fields']}
        extra=[]
        for name,changes in [('options-low',{'BacktestSpeed':'2','FakeOutFilter':'0','Risk':'3','TradeFrequency':'0'}),
                             ('options-high',{'BacktestSpeed':'3','FakeOutFilter':'3','Risk':'9999' if a.bot==1 else '0','TradeFrequency':'6'})]:
            row=dict(values);row.update({k:v for k,v in changes.items() if k in row});extra.append({'id':name,'inputs':row})
        extra_path.write_text(json.dumps(extra,ensure_ascii=False,indent=2),encoding='utf-8');print(json.dumps({'additional_cases':[c['id'] for c in extra]}));return
    if extra_path.exists():p['cases']+=json.loads(extra_path.read_text())
    if a.mode=='audit':
        if processes():raise RuntimeError('PRIVATE_MT5_IS_BUSY')
        case=next((c for c in p['cases'] if c['id']==a.case),None)
        if case is None:raise ValueError('UNKNOWN_CASE')
        folder=out/case['id'];target=folder/'capture-run.json'
        if target.exists():raise FileExistsError(target)
        capture=out.parents[1]/'captures'/f'inputs-{a.run}-{case["id"]}'
        cap,code,_=read_capture(capture);engine=json.loads((folder/'engine-observed.json').read_text())
        if cap['errors'] or cap['pid']!=engine['pid'] or engine['engine_sha256']!=ENGINE_SHA or code['bytes']<(323584 if a.bot==1 else 356352):raise ValueError('CAPTURE_AUDIT_FAILED')
        checks=cap['input_string_checks']
        if {c['name'] for c in checks}!={f['name'] for f in p['fields'] if f['representation']=='string'} or not all(c['matches_expected'] for c in checks):raise ValueError('STRING_AUDIT_FAILED')
        rows=[json.loads(s) for s in (folder/'ket-qua-chay.jsonl').read_text().splitlines()]
        test=next(r for r in rows if r['id']==f'b{a.bot}-{a.run}-{case["id"]}')
        if not test['login_confirmed'] or not test['demo_confirmed'] or test['expert_sha256']!=ORIGINALS[a.bot][2] or test['job']['inputs']!=case['inputs']:raise ValueError('RUN_AUDIT_FAILED')
        logged=parse_saved_inputs(folder/(test['id']+'.log'),{f['name'] for f in p['fields']})
        if set(logged)!={f['name'] for f in p['fields']}:raise ValueError('JOURNAL_AUDIT_FAILED')
        result={'case':case['id'],'capture_exit':None,'runner_exit':None,'capture_validated':True,'tester_run_exit':test['exit_code'],
            'capture':capture.relative_to(ROOT).as_posix(),'login_confirmed':True,'demo_confirmed':True,'input_rows_logged':len(logged),
            'audit_reason':'Captured files and final journal revalidated after cleanup reported an already exited tester. No historical wrapper exit code inferred.',
            'capture_json_sha256':sha(capture/'capture.json'),'journal_sha256':sha(folder/(test['id']+'.log'))}
        target.write_text(json.dumps(result,indent=2),encoding='utf-8');print(json.dumps(result));return
    if a.mode=='capture':
        case=next((c for c in p['cases'] if c['id']==a.case),None)
        if case is None:raise ValueError('UNKNOWN_CASE')
        if processes():raise RuntimeError('PRIVATE_MT5_IS_BUSY')
        if sha(MT/'metatester64.exe')!=ENGINE_SHA:raise ValueError('ENGINE_CHANGED')
        tid,name,expected=ORIGINALS[a.bot];original=Path.home()/'AppData/Roaming/MetaQuotes/Terminal'/tid/'MQL5/Experts/Market'/name
        if sha(original)!=expected:raise ValueError('ORIGINAL_HASH_MISMATCH')
        copied=MT/'MQL5/Experts/Market'/name
        if not copied.exists():shutil.copyfile(original,copied)
        if sha(copied)!=expected:raise ValueError('PRIVATE_EXPERT_COPY_DIFFERS')
        folder=out/case['id'];folder.mkdir(exist_ok=False)
        run_id=f'b{a.bot}-{a.run}-{case["id"]}'
        capture=out.parents[1]/'captures'/f'inputs-{a.run}-{case["id"]}'
        catalog=json.loads((ROOT/'tai-lieu-cu/catalog.json').read_text())
        entry=next(r for r in catalog if r['index']==(5 if a.bot==1 else 16))
        job={'id':run_id,'expert':'Market\\'+name,'symbol':'XAUUSD_NOCOST_V2','period':entry['test']['period'],'model':0,
            'from':'2026.09.29','to':'2026.10.20','timeout':120,'inputs':case['inputs']}
        (folder/'jobs.json').write_text(json.dumps([job],ensure_ascii=False,indent=2),encoding='utf-8')
        strings=[{'name':f['name'],'rva':f['candidate_rva'],'expected':case['inputs'].get(f['name'],f['observed'])} for f in p['fields'] if f['representation']=='string']
        (folder/'string-checks.json').write_text(json.dumps(strings,ensure_ascii=False),encoding='utf-8')
        args=[sys.executable,'-I','-B','-X','utf8',str(ROOT/'cong-cu/chay-may-thu.py'),str(MT),str(folder/'jobs.json'),str(folder),'--login','279786616','--server','Exness-MT5Trial8']
        start=time.monotonic();owned=[];capture_result=None;engine=None
        log_offsets={path:path.stat().st_size for path in MT.glob('Tester/**/*.log')}
        names={f['name'] for f in p['fields']};live_inputs={}
        with (folder/'runner.stdout.txt').open('x',encoding='utf-8') as stdout,(folder/'runner.stderr.txt').open('x',encoding='utf-8') as stderr:
            proc=subprocess.Popen(args,stdout=stdout,stderr=stderr,creationflags=subprocess.CREATE_NO_WINDOW)
            try:
                deadline=time.monotonic()+60
                while proc.poll() is None and time.monotonic()<deadline:
                    owned=processes();engine=next((r for r in owned if Path(r['path']).name.lower()=='metatester64.exe'),None)
                    if engine:break
                    time.sleep(0.1)
                if not engine:raise RuntimeError('PRIVATE_TESTER_NOT_OBSERVED')
                record={'bot':a.bot,'pid':engine['id'],'process':engine['path'],'engine_base':hex(engine['base']),'engine_sha256':ENGINE_SHA,'original_ex5_sha256':expected,'observed_processes':owned,'purpose':'Input storage analysis; intentional stop after capture, not a completed trading run.'}
                (folder/'engine-observed.json').write_text(json.dumps(record,indent=2),encoding='utf-8')
                capture_args=[sys.executable,'-I','-B','-X','utf8',str(ROOT/'cong-cu/chup-bot-1-3.py'),'--bot',str(a.bot),'--pid',str(engine['id']),'--out',str(capture),
                    '--min-code-bytes','323584' if a.bot==1 else '356352','--wait-seconds','30','--include-readonly','--include-program-data','--verify-input-strings',str(folder/'string-checks.json')]
                capture_result=subprocess.run(capture_args,capture_output=True,text=True,encoding='utf-8',timeout=45)
                (folder/'capture.stdout.txt').write_text(capture_result.stdout,encoding='utf-8');(folder/'capture.stderr.txt').write_text(capture_result.stderr,encoding='utf-8')
                # The tester buffers its journal. Do not stop it before its actual
                # named input list has reached disk; capture availability alone is earlier.
                deadline=time.monotonic()+30
                while proc.poll() is None and time.monotonic()<deadline:
                    live_inputs=logged_inputs(log_offsets,names)
                    if set(live_inputs)==names:break
                    time.sleep(0.1)
                (folder/'live-inputs.json').write_text(json.dumps(live_inputs,ensure_ascii=False,indent=2),encoding='utf-8')
            finally:
                stop_owned(owned)
                try:proc.wait(timeout=30)
                except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=15)
        records=folder/'ket-qua-chay.jsonl';rows=[json.loads(s) for s in records.read_text().splitlines()] if records.exists() else []
        test=rows[-1] if rows else {}
        final_inputs=parse_saved_inputs(folder/(run_id+'.log'),names)
        (folder/'saved-inputs.json').write_text(json.dumps(final_inputs,ensure_ascii=False,indent=2),encoding='utf-8')
        result={'case':case['id'],'capture_exit':capture_result.returncode if capture_result else None,'runner_exit':proc.returncode,'seconds':round(time.monotonic()-start,2),
                'capture':capture.relative_to(ROOT).as_posix(),'login_confirmed':test.get('login_confirmed',False),'demo_confirmed':test.get('demo_confirmed',False),
                'input_rows_logged_live':len(live_inputs),'input_rows_logged':len(final_inputs),'intentionally_stopped':True}
        (folder/'capture-run.json').write_text(json.dumps(result,indent=2),encoding='utf-8');print(json.dumps(result))
        if capture_result is None or capture_result.returncode!=0 or not result['login_confirmed'] or not result['demo_confirmed'] or set(final_inputs)!=names:raise RuntimeError('INPUT_CAPTURE_NOT_VERIFIED')
        return
    results=[];defaults=None
    for case in p['cases']:
        folder=out/case['id'];record=json.loads((folder/'capture-run.json').read_text())
        if not (record.get('capture_validated') or record['capture_exit']==0) or not record['login_confirmed'] or not record['demo_confirmed']:raise ValueError('UNVERIFIED_CAPTURE')
        cap,code,regions=read_capture(ROOT/record['capture'])
        logged=parse_saved_inputs(folder/f'b{a.bot}-{a.run}-{case["id"]}.log',{f['name'] for f in p['fields']})
        if set(logged)!={f['name'] for f in p['fields']}:raise ValueError('INCOMPLETE_INPUT_LOG '+case['id'])
        if case['id']=='defaults':defaults=logged
        checks={c['name']:c['matches_expected'] for c in cap['input_string_checks']}
        for f in p['fields']:
            value=logged[f['name']];rva=int(f['candidate_rva'],16);kind=f['representation']
            if kind=='string':actual=checks.get(f['name']);matched=actual is True
            elif kind=='bool':actual=scalar(regions,code['base']+rva,1)[0];matched=actual==int(value=='true')
            elif kind=='double':actual=struct.unpack('<d',scalar(regions,code['base']+rva,8))[0];matched=actual==float(value)
            else:actual=struct.unpack('<q',scalar(regions,code['base']+rva,8))[0];matched=actual==int(value)
            expected=case['inputs'].get(f['name'],value)
            if expected!=value:raise ValueError('REQUESTED_INPUT_NOT_APPLIED '+case['id']+' '+f['name'])
            results.append({'case':case['id'],'name':f['name'],'rva':hex(rva),'logged':value,'actual':actual,'matched':matched})
    failures=[r for r in results if not r['matched']]
    output={'bot':a.bot,'cases':len(p['cases']),'fields':len(p['fields']),'checks':len(results),'matched':len(results)-len(failures),'passed':not failures,'failures':failures,'rows':results,
        'bindings':[{**f,'default_from_fresh_log':defaults[f['name']],'status':'verified storage and logged value across prepared cases' if not any(r['name']==f['name'] for r in failures) else 'unverified'} for f in p['fields']],
        'tool_sha256':sha(Path(__file__)),'scope':'Input storage/value/order only; integer versus enum menu, labels and enum choices still need direct inspection. Controlled captures intentionally stopped.'}
    target=out/('comparison-extended.json' if extra_path.exists() else 'comparison.json')
    if target.exists():raise FileExistsError(target)
    target.write_text(json.dumps(output,ensure_ascii=False,indent=2),encoding='utf-8');print(json.dumps({k:output[k] for k in ['bot','cases','fields','checks','matched','passed','failures']}));raise SystemExit(bool(failures))
if __name__=='__main__':main()
