"""Compare preparation-to-evaluator projected fields against native storage.

generate BOT | prepare|mql5 --build BUILD|original|compare BOT RUN.
Native profile, context and preparation execute continuously. After return,
the virtual-expiration input is deliberately changed on both sides to prove
the bridge reads the original input rather than a stale prepared copy.
This covers the projected fields, not execution of the entire evaluator.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MASK=(1<<64)-1;MAGIC=0x42524731
def module(name,path):
    spec=importlib.util.spec_from_file_location(name,ROOT/path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
setup=module('bridge_setup','cong-cu/kiem-nap-chien-luoc-bot-1-3.py');pub=setup.cx.pub;require=setup.require;sha=setup.sha;save=setup.save
FIELDS=[
 ('execution.strategy_magic','i',0x6246c,0x6d564),('execution.magic_base','i',0x6a610,0x1d6ff0),
 ('execution.tick.bid','d',0x67758,0x74798),('execution.tick.ask','d',0x67760,0x747a0),
 ('execution.threshold_a','d',0x66a70,0x73ab0),('execution.gap','d',0x67468,0x744a8),
 ('restore.sl_distance','d',0x62498,0x6d588),('restore.tp_distance','d',0x624a0,0x6d590),
 ('restore.expiration_base','q',0x67450,0x74490),('restore.virtual_expiration','B',0x6a5e8,0x1d6fc8),
 ('loop.submission.check_free_margin','B',0x62424,0x6d51c),('loop.submission.omit_real_sl_tp','B',0x62418,0x6d510),
 ('loop.confirmation_frame','i',0x6227c,0x6d2b4),('loop.older_width','i',0x62430,0x6d528),
 ('loop.recent_width','i',0x62434,0x6d52c),('loop.last_shift','i',0x62438,0x6d530),
 ('loop.expiration_setting','i',0x62468,0x6d560),('loop.expiration_seconds','I',0x66da0,0x73de0),
 ('loop.gap_points','d',0x62440,0x6d538),('loop.buy_offset','d',0x62448,0x6d540),
 ('loop.sell_offset','d',0x62450,0x6d548),('loop.radius','d',0x62460,0x6d558),
 ('loop.step_reference','d',0x62510,0x6d600),('levels.timeframe','i',0x6242c,0x6d524),
 ('levels.aux_timeframe','i',0x624dc,0x6d5cc),('levels.aux_older','i',0x624e4,0x6d5d4),
 ('levels.aux_recent','i',0x624e8,0x6d5d8),('levels.last_shift','i',0x624e0,0x6d5d0),
 ('levels.aux_offset','d',0x624f0,0x6d5e0)]
FIELDS += [
 ('loop.delete_expired','B',0x62419,0x6d511),
 ('cfg_spread.enabled','B',0x623d4,0x6d4cc),('cfg_spread.maximum','d',0x623d8,0x6d4d0),('cfg_spread.distance_points','i',0x623e0,0x6d4d8),
 ('cfg_volume.start_lots','d',0x62530,0x6d620),('cfg_volume.max_lots','d',0x62538,0x6d628),
 ('cfg_volume.lot_scale','d',0x682f0,0x6d1c8),('cfg_volume.manual_risk','d',0x62548,0x6d638),
 ('state_volume.mode','I',0x62540,0x6d630),('state_volume.balance_step','i',0x62550,0x6d640),('state_volume.strategy_loss','d',0x69f70,0x76fa0),
 ('cfg_prefix.management_timeframe','i',0x6248c,0x6d584),
 ('cfg_prefix.management.anchor_limit','d',0x623e8,0x6d4e0),('cfg_prefix.management.use_anchor','B',0x62410,0x6d508),
 ('cfg_prefix.management.high_low_eligible','B',0x6a5d0,None),
 ('cfg_prefix.management.timed_activation','d',0x624f8,0x6d5e8),('cfg_prefix.management.timed_distance','d',0x62500,0x6d5f0),
 ('cfg_prefix.management.virtual_delay_seconds','i',0x62420,0x6d518),
 ('cfg_prefix.management.trail','d',0x624a8,0x6d598),('cfg_prefix.management.trail_step','d',0x624c0,0x6d5b0),
 ('cfg_prefix.management.trail_start','d',0x624b0,0x6d5a0),('cfg_prefix.management.trail_limit','d',0x624b8,0x6d5a8),
 ('cfg_prefix.management.take_trail_distance','d',None,0x6d378),('cfg_prefix.management.take_trail_start','d',None,0x6d380),
 ('cfg_prefix.management.slippage_enabled','i',0x623f0,0x6d4e8),('cfg_prefix.management.slippage_trail','d',0x62400,0x6d4f8),
 ('cfg_prefix.management.slippage_start','d',0x623f8,0x6d4f0),('cfg_prefix.management.slippage_limit','d',0x62408,0x6d500),
 ('cfg_prefix.management.high_low_gap_count','i',0x62360,0x6d3c0),
 ('cfg_prefix.management.finish.high_low_enabled','i',0x624e4,0x6d5d4),('cfg_prefix.management.finish.high_low_before_open','B',0x624d8,0x6d5c8),
 ('cfg_prefix.management.finish.high_low_shift','B',0x624ec,0x6d5dc),('cfg_prefix.management.finish.lock_start','d',0x624c8,0x6d5b8),
 ('cfg_prefix.management.finish.lock_extra','d',0x624d0,0x6d5c0),('cfg_prefix.management.finish.mode','i',0x6241c,0x6d514),
 ('cfg_prefix.management.finish.step_enabled','B',0x62508,0x6d5f8),('cfg_prefix.management.finish.step_reference','d',0x62510,0x6d600),
 ('cfg_prefix.management.finish.min_steps','i',0x62518,0x6d608),('cfg_prefix.management.finish.step_distance','d',0x62520,0x6d610)]
TEXT_FIELDS=[('execution.symbol',0x67918,0x74958),('restore.comment',0x62470,0x6d568)]
SCOPE=dict(whole_bot_complete=False,whole_manager_complete=False,full_ea=False,
           native_profile_context_preparation_executed=True,projected_values_compared=True,
           after_preparation_input_mutation_supplied=True,evaluator_executed=False,
           early_return_cases_excluded=True,terminal_replies_supplied=True,original_ex5_changed=False)
def fields(bot):return [(n,k,a if bot==1 else b) for n,k,a,b in FIELDS if (a if bot==1 else b) is not None]
def texts(bot):return [(n,a if bot==1 else b) for n,a,b in TEXT_FIELDS]
def replace_once(src,old,new):require(src.count(old)==1,'GENERATOR_PATTERN_CHANGED '+old[:80]);return src.replace(old,new,1)
def generate(bot):
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}';src=(folder/f'Bot{bot}StrategySetupCheck.mq5').read_text(encoding='utf-8-sig');target=folder/f'Bot{bot}PreparationBridgeControlsCheck.mq5';require(not target.exists(),'SOURCE_EXISTS')
    src=replace_once(src,'#undef SymbolInfoInteger',f'#undef SymbolInfoInteger\n#include "../../Include/bot-cua-toi-{bot}/Bot{bot}EvaluationBridge.mqh"')
    src=src.replace(f'bot{bot}-strategy-setup',f'bot{bot}-preparation-bridge-controls')
    anchor='   FileWriteInteger(output,13981000'+('17' if bot==1 else '19')+');'
    require(anchor in src,'MQL_OUTPUT_HEADER_NOT_FOUND')
    add=f'   int bridge_output=FileOpen(folder+"bridge-results.bin",FILE_WRITE|FILE_BIN);if(bridge_output==INVALID_HANDLE) return 12;\n   FileWriteInteger(bridge_output,{MAGIC});FileWriteInteger(bridge_output,1);FileWriteInteger(bridge_output,count);FileWriteInteger(bridge_output,{len(fields(bot))+len(TEXT_FIELDS)});\n'
    src=replace_once(src,anchor,add+anchor)
    call=f'Bot{bot}SetupStrategy((uint)index,'+('hl!=0,' if bot==1 else '')+'adjustments,inputs,context_inputs,profile_state,context_state,state);'
    writes='\n'.join('      FileWriteLong(bridge_output,(long)'+(f'ValueBits({n})' if k=='d' else n)+');' for n,k,_ in fields(bot))
    writes+='\n'+'\n'.join(f'      FileWriteLong(bridge_output,(long)TextHash({n}));' for n,_ in texts(bot))
    injection=f'''{call}
      inputs.virtual_expiration=(uchar)((id+17)%256);
      Bot{bot}NfpExecution execution;Bot{bot}PendingRestoreSettings restore;Bot{bot}EntryLoopSettings loop;Bot{bot}LevelCacheSettings levels;
      ZeroMemory(execution);ZeroMemory(restore);ZeroMemory(loop);ZeroMemory(levels);
      Bot{bot}ProjectPreparationToEvaluation(inputs,state,context_state,context_inputs.base_magic,execution,restore,loop,levels);
      Bot{bot}SpreadSettings cfg_spread;Bot{bot}VolumeSettings cfg_volume;Bot{bot}VolumeState state_volume;Bot{bot}EvaluationPrefixSettings cfg_prefix;
      ZeroMemory(cfg_spread);ZeroMemory(cfg_volume);ZeroMemory(state_volume);ZeroMemory(cfg_prefix);
      Bot{bot}ProjectEvaluationControls({('hl!=0,' if bot==1 else '')}profile_state,context_state,state,cfg_spread,cfg_volume,state_volume,cfg_prefix);
      FileWriteInteger(bridge_output,id);
{writes}
'''
    src=replace_once(src,call,injection)
    src=replace_once(src,'FileClose(source);FileClose(output);','FileClose(source);FileClose(output);FileClose(bridge_output);')
    target.write_text(src,encoding='utf-8',newline='\n');print(target)
def identity(bot,chain):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}PreparationBridgeControlsCheck.mq5';current=setup.identity(bot,chain)
    current['sources_sha256']={p.relative_to(source).as_posix():sha(p) for p in pub.closure(script,source)};current['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=sha(Path(__file__));current['bridge_tool_sha256']=sha(Path(__file__));return current
def header(bot,count):return struct.pack('<4i',MAGIC,1,count,len(fields(bot))+len(TEXT_FIELDS))
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run),'BAD_RUN');chain,full,data=setup.contract(a.bot);rows=data.cases();current=identity(a.bot,chain);folder=ROOT/f'bot-cua-toi-{a.bot}/bang-chung/kiem-quan-ly-vi-the'/a.run
    if a.mode=='prepare':
        folder.mkdir(parents=True,exist_ok=False);(folder/'cases.bin').write_bytes(data.encode(rows));save(folder/'baseline.json',dict(**current,cases=len(rows),inputs_sha256=sha(folder/'cases.bin'),field_names=[n for n,_,_ in fields(a.bot)]+[n for n,_ in texts(a.bot)],**SCOPE));print(json.dumps(dict(cases=len(rows),fields=len(fields(a.bot))+len(TEXT_FIELDS))));return
    baseline=json.loads((folder/'baseline.json').read_text());require(all(baseline[k]==v for k,v in current.items()) and (folder/'cases.bin').read_bytes()==data.encode(rows),'IDENTITY_CHANGED')
    if a.mode=='mql5':
        home=ROOT/f'bot-cua-toi-{a.bot}';mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PreparationBridgeControlsCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0 and build['floating_point_dividers_check_requested'],'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED '+name)
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        files=mt/f'MQL5/Files/bot{a.bot}-preparation-bridge-controls'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=mt/'MQL5/Presets'/('prep-bridge-'+a.run+'.set');ini=mt/('prep-bridge-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PreparationBridgeControlsCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=proc.wait(timeout=120)
        except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['bridge-results.bin','script-status.bin']:
            with (folder/('mql5-results.bin' if name=='bridge-results.bin' else name)).open('xb') as f:f.write((files/name).read_bytes())
        save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'mql5-results.bin'),build=a.build,build_receipt_sha256=sha(receipt),**SCOPE));print(json.dumps(dict(cases=len(rows))));return
    if a.mode=='original':
        runner=setup.original_class(a.bot,chain,full)();raw=bytearray(header(a.bot,len(rows)));old=[0,0,0,0]
        try:
            for row in rows:
                runner.run(row);m=runner.m;v=(row['id']+17)%256;virtual_input=0x6a5e8 if a.bot==1 else 0x1d6fc8;m.mem_write(runner.base+virtual_input,bytes([v]))
                words=[runner.value(off,k)&MASK for _,k,off in fields(a.bot)]
                words += [setup.cx.currency.entry_check.text_hash(setup.text(runner,runner.base+off)) for _,off in texts(a.bot)]
                checks=[(0x6227c,0x6242c,'i') if a.bot==1 else (0x6d2b4,0x6d524,'i'),(0x62510,0x66d98,'d') if a.bot==1 else (0x6d600,0x73dd8,'d'),(0x624e0,0x62438,'i') if a.bot==1 else (0x6d5d0,0x6d530,'i'),(virtual_input,0x62419,'B') if a.bot==1 else (virtual_input,0x6d511,'B')]
                for i,(expected,previous,k) in enumerate(checks):old[i]+=runner.value(expected,k)!=runner.value(previous,k)
                raw+=struct.pack('<i'+'Q'*len(words),row['id'],*words)
        finally:
            if a.bot==3:runner.close()
        require(all(n>0 for n in old),'OLD_MAPPING_NOT_DISTINGUISHED');(folder/'original-results.bin').write_bytes(raw)
        save(folder/'original-run.json',dict(**current,cases=len(rows),result_sha256=sha(folder/'original-results.bin'),old_mapping_differences=dict(confirmation_frame=old[0],step_reference=old[1],aux_last_shift=old[2],expiration_input=old[3]),**SCOPE));print(json.dumps(dict(cases=len(rows),old_mapping_differences=old)));return
    for name in ['original','mql5']:
        report=json.loads((folder/(name+'-run.json')).read_text());require(all(report[k]==v for k,v in current.items()) and report['result_sha256']==sha(folder/(name+'-results.bin')),'RUN_CHANGED')
    left=(folder/'original-results.bin').read_bytes();right=(folder/'mql5-results.bin').read_bytes();record=struct.Struct('<i'+'Q'*(len(fields(a.bot))+len(TEXT_FIELDS)));require(left[:16]==right[:16]==header(a.bot,len(rows)) and len(left)==len(right)==16+record.size*len(rows),'RESULT_LAYOUT');fail=[];names=[n for n,_,_ in fields(a.bot)]+[n for n,_ in texts(a.bot)]
    for i,row in enumerate(rows):
        x=record.unpack_from(left,16+i*record.size);y=record.unpack_from(right,16+i*record.size)
        if x!=y:fail.append(dict(id=row['id'],differences={n:[v,w] for n,v,w in zip(['id']+names,x,y) if v!=w}))
    report=dict(cases=len(rows),matched=len(rows)-len(fail),failed=len(fail),first_failures=fail[:8],fields=len(names),string_comparison='UTF-16 FNV-1a hashes',**SCOPE,
       limits=['Native setup and projected fields only; supplied service replies and post-preparation expiration change. Early return, full evaluator, all shared-state mutations and complete EA are excluded.'])
    save(folder/'comparison.json',report);print(json.dumps(report));raise SystemExit(bool(fail))
if __name__=='__main__':main()
