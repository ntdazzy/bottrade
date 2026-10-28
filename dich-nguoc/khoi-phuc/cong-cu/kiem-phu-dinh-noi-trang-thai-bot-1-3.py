"""Ensure the isolated handoff test rejects the previously published bridge.

generate BOT | run BOT RUN --build BUILD. The old source is copied from an
existing Git commit into a clearly named test file; no EX5 is modified.
"""
import argparse,hashlib,importlib.util,json,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];WORK=ROOT.parents[1]
def module(name,path):
    s=importlib.util.spec_from_file_location(name,ROOT/path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
pub=module('negative_bridge_pub','cong-cu/kiem-ban-git-quan-ly.py');require=pub.require
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def generate(bot):
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}';orig=f'dich-nguoc/khoi-phuc/bot-cua-toi-{bot}/source/MQL5/Include/bot-cua-toi-{bot}/Bot{bot}EvaluationBridge.mqh'
    old=subprocess.check_output(['git','show','be60026:'+orig],cwd=WORK).decode('utf-8-sig');snapshot=ROOT/f'danh-gia-doc-lap/bridge-source-20261028-r1/Bot{bot}SharedHandoffCheck.mq5.txt';src=snapshot.read_text(encoding='utf-8-sig')
    for name in ['StrategySetup','EntryLoop','EntryLevelCache','EvaluationWithDisplay']:
        before=f'#include "Bot{bot}{name}.mqh"';after=f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}{name}.mqh"';require(old.count(before)==1,'OLD_HEADER_INCLUDE_CHANGED');old=old.replace(before,after,1)
    before=f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}EvaluationBridge.mqh"';after=f'#include "Bot{bot}SharedHandoffNegative.mqh"';require(src.count(before)==1,'TEST_INCLUDE_CHANGED');src=src.replace(before,after,1).replace(f'bot{bot}-shared-handoff',f'bot{bot}-shared-handoff-negative')
    header=folder/f'Bot{bot}SharedHandoffNegative.mqh';script=folder/f'Bot{bot}SharedHandoffNegativeCheck.mq5';require(not header.exists() and not script.exists(),'NEGATIVE_SOURCE_EXISTS')
    header.write_text(old,encoding='utf-8',newline='\n');script.write_text(src,encoding='utf-8',newline='\n');print(json.dumps(dict(header=str(header),script=str(script))))
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','run']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run) and a.build and re.fullmatch('[a-z0-9-]{1,48}',a.build),'BAD_RUN');home=ROOT/f'bot-cua-toi-{a.bot}';source=home/'source/MQL5';mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';b=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}SharedHandoffNegativeCheck.mq5'
    require(b['target']==script and b['errors']==b['warnings']==0 and b['floating_point_dividers_check_requested'],'BUILD_NOT_CLEAN')
    for file in pub.closure(source/script,source):
        name=file.relative_to(source.resolve()).as_posix();require(sha(file)==sha(mt/'MQL5'/name)==b['sources_sha256'][name],'SOURCE_CHANGED')
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==b['binary_sha256']==sha(receipt.parent/binary.name),'BINARY_CHANGED');out=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;out.mkdir(parents=True,exist_ok=False);files=mt/f'MQL5/Files/bot{a.bot}-shared-handoff-negative'/a.run;files.mkdir(parents=True,exist_ok=False)
    preset=mt/'MQL5/Presets'/('handoff-negative-'+a.run+'.set');ini=mt/('handoff-negative-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}SharedHandoffNegativeCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=proc.wait(timeout=120)
    except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    import struct
    require(code==0 and (files/'result.bin').is_file(),'MT5_FAILED');raw=(files/'result.bin').read_bytes();require(len(raw)==8,'RESULT_SIZE');fail,calls=struct.unpack('<2i',raw)
    require(calls==2 and (fail&(2|4|8|16|32))!=0,'OLD_BRIDGE_WAS_NOT_REJECTED');(out/'result.bin').write_bytes(raw)
    report=dict(old_ref='be60026',test_case='successful setup followed by zero CopyBuffer',calls=calls,wrong_state_bits=fail,rejected=True,build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(out/'result.bin'),tool_sha256=sha(Path(__file__)),original_ex5_changed=False,full_ea=False)
    with (out/'comparison.json').open('x',encoding='utf-8') as f:json.dump(report,f,indent=2)
    print(json.dumps(report))
if __name__=='__main__':main()
