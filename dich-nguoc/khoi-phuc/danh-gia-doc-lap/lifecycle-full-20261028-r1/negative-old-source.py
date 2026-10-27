"""Prove that the new test rejects the old bool flag implementation.

prepare BOT: write a disposable recorder with the old body inlined, then compile it.
check BOT BUILD: run that private compiled recorder and require native mismatch.
The disposable source is removed only after its exact bytes have been saved here.
"""
import argparse,hashlib,importlib.util,json,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];OUT=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('lifecycle_full',ROOT/'cong-cu/kiem-vong-doi-day-du-bot-1-3.py')
check=importlib.util.module_from_spec(spec);spec.loader.exec_module(check)
OLD_REF='b9c7f77b5cec3a91d882d43d7d05a9fd296c5133'
def target(bot):return ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}LifecycleOldNegativeCheck.mq5'
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['prepare','check']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('build',nargs='?');a=p.parse_args()
    script=target(a.bot);saved=OUT/f'Bot{a.bot}LifecycleOldNegativeCheck.mq5.txt';original=Path(f'dich-nguoc/khoi-phuc/bot-cua-toi-{a.bot}/source/MQL5/Include/bot-cua-toi-{a.bot}/Bot{a.bot}Lifecycle.mqh')
    if a.mode=='prepare':
        old=subprocess.check_output(['git','show',OLD_REF+':'+original.as_posix()],cwd=ROOT.parents[1]).decode('utf-8')
        code=check.TEMPLATE.replace('@N@',str(a.bot)).replace(f'#include "../../Include/bot-cua-toi-{a.bot}/Bot{a.bot}Lifecycle.mqh"',old)
        check.require(not script.exists() and not saved.exists(),'NEGATIVE_SOURCE_EXISTS')
        script.write_text(code,encoding='utf-8',newline='\n');saved.write_bytes(script.read_bytes());print(script);return
    check.require(a.build and script.read_bytes()==saved.read_bytes(),'SOURCE_CHANGED')
    mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
    expected=script.relative_to(ROOT/f'bot-cua-toi-{a.bot}/source/MQL5').as_posix()
    check.require(build['target']==expected and build['errors']==build['warnings']==0,'NEGATIVE_BUILD_FAILED')
    check.require(build['sources_sha256'][expected]==check.sha(saved)==check.sha(mt/'MQL5'/expected),'SOURCE_NOT_BUILT')
    binary=mt/'MQL5'/Path(expected).with_suffix('.ex5');check.require(check.sha(binary)==build['binary_sha256']==check.sha(receipt.parent/binary.name),'BINARY_CHANGED')
    run=f'b{a.bot}-lifecycle-old-negative-20261028-r1';folder=mt/f'MQL5/Files/bot{a.bot}-lifecycle-full'/run;folder.mkdir(parents=True,exist_ok=False)
    case=dict(id=0,tag='old-bool-rejection',flag=2,indicator=42,errors=0,effects=[])
    (folder/'cases.bin').write_bytes(check.encode([case]));preset=mt/'MQL5/Presets'/(run+'.set');ini=mt/(run+'.ini');preset.write_text('CheckRun='+run+'\n',encoding='utf-16')
    ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}LifecycleOldNegativeCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=proc.wait(timeout=120)
    except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    check.require(code==0 and (folder/'script-status.bin').read_bytes()==struct.pack('<2i',0,1),'NEGATIVE_RECORD_FAILED')
    data=(folder/'mql5-results.bin').read_bytes();tape=check.records(data,1)[0];native=check.Native(a.bot)
    try:native.run(case,tape)
    except ValueError as error:
        message=str(error);check.require(message.startswith('SDK_ORDER '),'UNEXPECTED_NEGATIVE_FAILURE '+message)
    else:raise ValueError('OLD_SOURCE_FALSE_PASS')
    check.save(OUT/f'bot{a.bot}-negative.json',dict(old_ref=OLD_REF,case=case,source_sha256=check.sha(saved),
        binary_sha256=build['binary_sha256'],receipt_sha256=check.sha(receipt),measured_sha256=hashlib.sha256(data).hexdigest(),
        native_body_sha256=check.CFG[a.bot]['sha'],expected_mismatch=message,old_source_rejected=True))
    check.require(script.read_bytes()==saved.read_bytes(),'SOURCE_CHANGED_DURING_RUN');script.unlink()
    print(json.dumps(dict(bot=a.bot,old_source_rejected=True,mismatch=message)))
if __name__=='__main__':main()
