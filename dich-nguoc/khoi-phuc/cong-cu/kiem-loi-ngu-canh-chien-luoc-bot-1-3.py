"""Verify fatal conversion stops, including bot3's second conversion.

BOT RUN --build BUILD. Each case uses its own private-MT5 invocation.
Checks native error class, a runtime zero-division message and no normal result.
Does not claim identical partial state or exact runtime source-line payload.
"""
import argparse,importlib.util,json,re,struct
from pathlib import Path
spec=importlib.util.spec_from_file_location('context_errors_main',Path(__file__).with_name('kiem-ngu-canh-chien-luoc-bot-1-3.py'))
context=importlib.util.module_from_spec(spec);spec.loader.exec_module(context)
require,sha,save=context.require,context.sha,context.save
def log_sizes(mt):
    return {p:p.stat().st_size for folder in [mt/'MQL5/Logs',mt/'logs'] if folder.is_dir() for p in folder.glob('*.log')}
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('bot',type=int,choices=[1,3]);ap.add_argument('run');ap.add_argument('--build',required=True);a=ap.parse_args()
    require(all(re.fullmatch('[a-z0-9-]{1,35}',v) for v in [a.run,a.build]),'BAD_RUN_OR_BUILD')
    home=context.ROOT/f'bot-cua-toi-{a.bot}';mt=context.ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025'
    folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;folder.mkdir(parents=True,exist_ok=False)
    rows=context.error_cases(a.bot);raw=context.encode(rows);current=context.identity(a.bot);runner=context.Original(a.bot);checks=[]
    save(folder/'cases.json',rows);(folder/'cases.bin').write_bytes(raw)
    for c in rows:
        runner.run(c);require(runner.error and runner.error&0xffffffff==0x1f7,'NATIVE_DID_NOT_STOP_ON_DIVISION')
        native_error=runner.error;run=a.run+'-f'+str(c['id']);child=folder.parent/run;child.mkdir()
        (child/'cases.bin').write_bytes(raw);before=log_sizes(mt)
        code,files,receipt=context.run_mt(a.bot,home,run,a.build,current,only_case=c['id'])
        lines=[]
        for p,_ in log_sizes(mt).items():
            data=p.read_bytes();start=before.get(p,0)
            lines.extend(s for s in data[start if start<=len(data) else 0:].decode('utf-16-le',errors='replace').splitlines()
                         if 'STRATEGY_CONTEXT_CASE:' in s or 'zero divide' in s.lower())
        require(code in [-1,0xffffffff] and not(files/'script-status.bin').exists(),'FATAL_CASE_RETURNED_NORMALLY')
        require(any('STRATEGY_CONTEXT_CASE:'+str(c['id']) in s for s in lines) and any('zero divide' in s.lower() for s in lines),'FATAL_MESSAGE_MISSING')
        result=(files/'mql5-results.bin').read_bytes();require(result==struct.pack('<4i',context.MAGIC,2,1,len(context.NAMES)),'FATAL_CASE_WROTE_RESULT')
        (child/'runtime-lines.txt').write_text('\n'.join(lines)+'\n',encoding='utf-8');(child/'mql5-results.bin').write_bytes(result)
        check=dict(case_id=c['id'],tag=c['tag'],native_error=hex(native_error),native_class_low32=0x1f7,mql5_class='zero divide',
          exit_code=code,no_normal_result=True,partial_state_compared=False,runtime_lines_sha256=sha(child/'runtime-lines.txt'))
        save(child/'verification.json',check);checks.append(check);print(json.dumps(dict(checked=len(checks),of=len(rows))),flush=True)
    save(folder/'error-comparison.json',dict(cases=len(checks),matched_fatal_class_and_no_normal_result=len(checks),checks=checks,
      identity=current,tool_sha256=sha(Path(__file__)),build_receipt_sha256=sha(receipt),whole_bot_complete=False,
      limits=['Fatal class and absence of a normal record only. Partial state, runtime line/payload and allocation failures are not compared.']))
if __name__=='__main__':main()
