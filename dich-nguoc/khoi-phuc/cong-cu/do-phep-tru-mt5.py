"""Measure real CPU subtraction through the captured known-source MT5 library.

Usage: do-phep-tru-mt5.py NEW_RUN [--probe queue-native-r2]
Only numeric functions execute, in the isolated demo tester. No trading.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('q',Path(__file__).with_name('kiem-hang-doi-bot-1-3.py'))
q=importlib.util.module_from_spec(spec);spec.loader.exec_module(q)
MT=q.MT;sha=q.sha;save=q.save

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('new_run');ap.add_argument('--probe',default='queue-native-r2');a=ap.parse_args()
    if any(not re.fullmatch('[a-z0-9-]{1,40}',v) for v in [a.new_run,a.probe]):raise ValueError('INVALID_RUN')
    area=ROOT/'doi-chung-mt5/hang-doi-20261024';probe=area/a.probe;calibration=json.loads((probe/'calibration.json').read_text());build=json.loads((probe/'build.json').read_text())
    if not calibration['runner_verified'] or not calibration['only_anchor_executed'] or calibration['engine_sha256']!=sha(MT/'metatester64.exe'):raise ValueError('PROBE_NOT_VERIFIED')
    library=MT/f'MQL5/Experts/RecoveryApi20261023/{a.probe}/RecoveryApiLibrary.ex5'
    expected=next(r['binary_sha256'] for r in build['builds'] if r['name']=='RecoveryApiLibrary')
    if sha(library)!=expected:raise ValueError('LIBRARY_CHANGED')
    out=area/a.new_run;out.mkdir(exist_ok=False)
    values={'number':0x4059400000000000,'positive_qnan':0x7ff8000000000123,'negative_qnan':0xfff8000000000456,'positive_snan':0x7ff0000000000789,'negative_snan':0xfff0000000000abc}
    rows=[dict(left_name=left,right_name=right,left=hex(x),right=hex(y)) for left,x in values.items() for right,y in values.items()]
    save(out/'cases.json',rows);filename=a.new_run+'-input.bin';input_file=MT/'MQL5/Files'/filename
    with input_file.open('xb') as f:f.write(struct.pack('<2i',0x53554231,len(rows))+b''.join(struct.pack('<2Q',int(r['left'],16),int(r['right'],16)) for r in rows))
    output_name=a.new_run+'-output.bin'
    source='''#property strict
#property tester_file "INPUT_FILE"
#import "RecoveryApiLibrary.ex5"
double P_Subtract(const double left,const double right);
double P_SubtractCompound(const double left,const double right);
#import
union DoubleBits { double value;ulong bits; };
int OnInit()
{
   int input_file=FileOpen("INPUT_FILE",FILE_READ|FILE_BIN);
   if(input_file==INVALID_HANDLE) return INIT_FAILED;
   int magic=FileReadInteger(input_file,INT_VALUE),n=FileReadInteger(input_file,INT_VALUE);
   if(magic!=0x53554231 || n!=25) { FileClose(input_file);return INIT_FAILED; }
   int output_file=FileOpen("OUTPUT_FILE",FILE_WRITE|FILE_BIN);
   if(output_file==INVALID_HANDLE) { FileClose(input_file);return INIT_FAILED; }
   FileWriteInteger(output_file,magic,INT_VALUE);FileWriteInteger(output_file,n,INT_VALUE);
   for(int i=0;i<n;i++)
   {
      DoubleBits left,right,ordinary,compound,direct,sum,product;
      left.bits=(ulong)FileReadLong(input_file);right.bits=(ulong)FileReadLong(input_file);
      ordinary.value=P_Subtract(left.value,right.value);
      compound.value=P_SubtractCompound(left.value,right.value);
      direct.value=left.value-right.value;
      sum.value=left.value+right.value;
      product.value=left.value*right.value;
      FileWriteLong(output_file,(long)ordinary.bits);FileWriteLong(output_file,(long)compound.bits);FileWriteLong(output_file,(long)direct.bits);
      FileWriteLong(output_file,(long)sum.bits);FileWriteLong(output_file,(long)product.bits);
   }
   FileClose(input_file);FileClose(output_file);Print("SUBTRACTION_MEASURED:25");return INIT_SUCCEEDED;
}
void OnTick() { ExpertRemove(); }
'''.replace('INPUT_FILE',filename).replace('OUTPUT_FILE',output_name)
    saved=out/'ArithmeticRuntimeCheck.mq5';saved.write_text(source,encoding='utf-8',newline='');copied=library.parent/(a.new_run+'.mq5');shutil.copyfile(saved,copied);binary=copied.with_suffix('.ex5');log=out/'compile.log'
    subprocess.run(f'"{MT/"metaeditor64.exe"}" /compile:"{copied}" /log:"{log}" /inc:"{MT/"MQL5"}"',cwd=MT,creationflags=subprocess.CREATE_NO_WINDOW,timeout=60)
    match=re.search(r'Result: (\d+) errors?, (\d+) warnings?',log.read_text(encoding='utf-16'))
    receipt=dict(source_sha256=sha(saved),library_sha256=sha(library),binary_sha256=sha(binary) if binary.exists() else None,engine_sha256=sha(MT/'metatester64.exe'),errors=int(match[1]) if match else None,warnings=int(match[2]) if match else None)
    save(out/'build.json',receipt)
    if not match or match[1]!='0' or match[2]!='0':raise ValueError('SUBTRACTION_BUILD_FAILED')
    job=dict(id=a.new_run,expert=f'RecoveryApi20261023\\{a.probe}\\{a.new_run}.ex5',symbol='XAUUSD_NOCOST_V2',period='M15',model=0,**{'from':'2026.09.29','to':'2026.09.30'},timeout=120,inputs={});save(out/'jobs.json',[job])
    runner=out/'runner';runner.mkdir()
    with (out/'runner.stdout.txt').open('x',encoding='utf-8') as stdout,(out/'runner.stderr.txt').open('x',encoding='utf-8') as stderr:
        run=subprocess.run([sys.executable,'-I','-B','-X','utf8',str(ROOT/'cong-cu/chay-may-thu.py'),str(MT),str(out/'jobs.json'),str(runner),'--login','279786616','--server','Exness-MT5Trial8'],stdout=stdout,stderr=stderr,creationflags=subprocess.CREATE_NO_WINDOW,timeout=180)
    record=json.loads((runner/'ket-qua-chay.jsonl').read_text().splitlines()[-1]);journal=(runner/(a.new_run+'.log')).read_text()
    if run.returncode or record['exit_code'] or not record['demo_confirmed'] or not record['login_confirmed'] or not record['report_created'] or 'SUBTRACTION_MEASURED:25' not in journal:raise ValueError('SUBTRACTION_RUN_NOT_VERIFIED')
    shutil.copyfile(MT/'Tester/Agent-127.0.0.1-3000/MQL5/Files'/output_name,out/'results.bin');raw=(out/'results.bin').read_bytes()
    if len(raw)!=8+40*25 or struct.unpack_from('<2i',raw)!=(0x53554231,25):raise ValueError('SUBTRACTION_RESULTS_SHAPE_DIFFERS')
    for i,row in enumerate(rows):row['result_bits']={k:hex(v) for k,v in zip(['library_subtract','library_compound','direct','sum','product'],struct.unpack_from('<5Q',raw,8+40*i))}
    save(out/'results.json',dict(cases=rows,results_sha256=sha(out/'results.bin'),build_sha256=sha(out/'build.json'),runner_verified=True,scope='Actual known-source SUBSD functions and direct MQL subtraction; bit-union output. Not an original EA run.'))
    print(json.dumps(rows))

if __name__=='__main__':main()
