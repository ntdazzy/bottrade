"""Confirm the new boundary fixture rejects the previously built incorrect buy offset.
Runs only the saved private test binary; never an original/licensed EA or live account.
"""
import importlib.util,json,subprocess,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
s=importlib.util.spec_from_file_location('negative_evaluation',ROOT/'cong-cu/kiem-danh-gia-lien-tuc-bot-1-3.py')
t=importlib.util.module_from_spec(s);s.loader.exec_module(t)
out=[]
for bot in [1,3]:
    home=ROOT/f'bot-cua-toi-{bot}';mt=ROOT.parent/f'.local/mt5-bot{bot}-thread-20261025';build=f'b{bot}-evaluation-check-20261027-r5'
    receipt=home/'bang-chung/bien-dich'/build/'bien-nhan.json';record=json.loads(receipt.read_text(encoding='utf-8-sig'))
    binary=mt/f'MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}EvaluationCheck.ex5'
    t.require(t.sha(binary)==record['binary_sha256']==t.sha(receipt.parent/binary.name),'OLD_BINARY_CHANGED')
    rows=[c for c in t.cases(bot) if c['tag']=='evaluator-buy-emergency-shared-spread' and c['bid']==-20.5]
    t.require(len(rows)==1,'BOUNDARY_CASE_MISSING');rows[0]['id']=0
    run=f'b{bot}-old-buy-offset-negative';folder=mt/f'MQL5/Files/bot{bot}-evaluation'/run
    if folder.exists():t.require((folder/'cases.bin').read_bytes()==t.encode(rows,bot),'NEGATIVE_INPUT_CHANGED');code=0
    else:
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(t.encode(rows,bot))
        preset=mt/'MQL5/Presets'/(run+'.set');preset.write_text('CheckRun='+run+'\n',encoding='utf-16');ini=mt/(run+'.ini')
        ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{bot}\\Bot{bot}EvaluationCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        p=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=p.wait(timeout=60)
        except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=15);raise RuntimeError('NEGATIVE_MT5_TIMEOUT')
    t.require(code==0 and (folder/'script-status.bin').read_bytes()==struct.pack('<2i',0,1),'NEGATIVE_SCRIPT_FAILED')
    tape=t.Reader((folder/'sdk-tape.bin').read_bytes());t.require(tape.take('3i')==(t.MAGIC,1,1) and tape.take('i')==(0,),'NEGATIVE_TAPE')
    native=t.original(bot,t.active.PARTS[bot].news.news.news.news.cast_values(folder/'cast-values.bin'));native.cast_calls=native.queue_clears=0
    error=None
    try:native.run(rows[0],tape.block())
    except ValueError as e:error=str(e)
    t.require(error is not None and error.startswith(('EVALUATOR_STATE','EVALUATOR_SDK_ORDER')),'NEGATIVE_DID_NOT_DETECT_EXPECTED_DIFFERENCE '+str(error))
    out.append(dict(bot=bot,old_build=build,old_binary_sha256=record['binary_sha256'],cases_sha256=t.sha(folder/'cases.bin'),sdk_tape_sha256=t.sha(folder/'sdk-tape.bin'),difference=error,detected=True))
    print(json.dumps(out[-1]))
with (Path(__file__).parent/'negative-old-binary.json').open('x',encoding='utf-8') as f:json.dump(out,f,indent=2);f.write('\n')
