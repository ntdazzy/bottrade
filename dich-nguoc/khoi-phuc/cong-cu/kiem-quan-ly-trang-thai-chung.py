"""Generate/check manager Fields APIs using detached, deliberately invalid legacy state.

generate|prepare|mql5(--build)|original|compare BOT RUN. Reuses the existing native
manager matrix with real table/trade children and a separate private terminal per bot.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
def module(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
def generate(bot):
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    source=(folder/f'Bot{bot}PositionManagementFlowCheck.mq5').read_text(encoding='utf-8-sig')
    fields={'FShared.volumes':'FVolumes','FShared.strategy_index':'FIndex','FShared.error_count':'FErrors','FShared.last_ticket':'FLast','FShared.tick':'FTick'}
    if bot==1:fields.update({'FShared.cache':'FCache','FShared.copied_step':'FStep'})
    else:fields.update({'FShared.anchor.rows':'FCache','FShared.anchor.step_reference':'FStep'})
    core={'FCfg.symbol':'FSymbol','FCfg.magic':'FMagic','FCfg.unit':'FUnit','FCfg.stop_distance':'FStopDistance',
          'FCfg.take_distance':'FTakeDistance','FCfg.gap':'FGap','FCfg.freeze':'FFreeze',
          'FCfg.finish.high_low_enabled':'FHighLowEnabled','FCfg.finish.step_reference':'FStepSetting'}
    for old,new in sorted((fields|core).items(),key=lambda item:-len(item[0])):source=source.replace(old,new)
    marker=f'Bot{bot}PositionManagementState FShared;';assert source.count(marker)==1
    source=source.replace(marker,marker+f'\ndouble FCache[100][2],FVolumes[{8 if bot==1 else 9}],FStep;uint FIndex,FErrors;ulong FLast;MqlTick FTick;\nstring FSymbol;int FMagic,FHighLowEnabled;double FUnit,FStopDistance,FTakeDistance,FGap,FFreeze,FStepSetting;',1)
    marker='ZeroMemory(FShared);';assert source.count(marker)==1
    source=source.replace(marker,marker+'ZeroMemory(FTick);ArrayInitialize(FCache,0.0);ArrayInitialize(FVolumes,0.0);FStep=0;FIndex=0;FErrors=0;FLast=0;FSymbol=NULL;FMagic=0;FHighLowEnabled=0;FUnit=0;FStopDistance=0;FTakeDistance=0;FGap=0;FFreeze=0;FStepSetting=0;',1)
    name=f'Bot{bot}ManagePositions';at=source.rindex(name+'(');start=at+len(name);depth=0;end=None
    for i in range(start,len(source)):
        if source[i]=='(':depth+=1
        elif source[i]==')':
            depth-=1
            if depth==0:end=i;break
    assert end is not None
    source=source[:end]+',FStep,FCache,FVolumes,FIndex,FErrors,FLast,FTick,FSymbol,FMagic,FUnit,FStopDistance,FTakeDistance,FGap,FFreeze,FHighLowEnabled,FStepSetting'+source[end:]
    source=source[:at]+name+'Fields'+source[at+len(name):]
    # These legacy members must remain irrelevant to the Fields path. All mock
    # effects, reference checks and exported results now use external storage.
    marker='      bool returned=ExecuteManagementRouter' if bot==1 else '      bool returned=Bot3ManagePositionsFields'
    assert marker in source
    poison='''      FShared.strategy_index=99;FShared.error_count=0xffffffff;FShared.last_ticket=0xffffffffffffffff;
      FShared.tick.bid=-123456;FShared.tick.ask=123456;ArrayInitialize(FShared.volumes,-777.0);
'''
    poison+=('      FShared.copied_step=-98765;ArrayInitialize(FShared.cache,-777.0);\n' if bot==1 else '      FShared.anchor.step_reference=-98765;ArrayInitialize(FShared.anchor.rows,-777.0);\n')
    poison+='      FCfg.symbol="DETACHED";FCfg.magic=-777;FCfg.unit=-777;FCfg.stop_distance=-777;FCfg.take_distance=-777;FCfg.gap=-777;FCfg.freeze=-777;FCfg.finish.high_low_enabled=-777;FCfg.finish.step_reference=-777;\n'
    source=source.replace(marker,poison+marker,1)
    if bot==1:
        # Caller-router mode is intentionally outside this direct-manager test.
        source=source.replace('if(CheckRun=="") return 1;','if(CheckRun=="" || ExecuteManagementRouter) return 1;',1)
    source=source.replace(f'bot{bot}-position-management-flow',f'bot{bot}-position-management-fields')
    target=folder/f'Bot{bot}PositionManagementFieldsCheck.mq5';target.write_text(source,encoding='utf-8',newline='\n')
    args='false,settings,shared,levels,requests,options,deviation'+(',false' if bot==1 else '')+',step,cache,volumes,index,errors,last,tick,settings.symbol,settings.magic,settings.unit,settings.stop_distance,settings.take_distance,settings.gap,settings.freeze,settings.finish.high_low_enabled,settings.finish.step_reference'
    api=f'''#property strict
#include "../../Include/bot-cua-toi-{bot}/Bot{bot}PositionManagement.mqh"
void OnStart()
{{
   Bot{bot}PositionManagementSettings settings;Bot{bot}PositionManagementState shared;
   Bot{bot}PendingRequestState requests;Bot{bot}TradeSendOptions options;
   ZeroMemory(settings);ZeroMemory(shared);ZeroMemory(requests);ZeroMemory(options);
   double step=0,cache[100][2],volumes[{8 if bot==1 else 9}],levels[100];MqlTick tick;ZeroMemory(tick);
   ArrayInitialize(cache,0.0);ArrayInitialize(volumes,0.0);ArrayInitialize(levels,0.0);
   uint index=0,errors=0;ulong last=0,deviation=0;
   Bot{bot}ManagePositionsFields({args});
}}
'''
    (folder/f'Bot{bot}PositionManagementFieldsAPICompile.mq5').write_text(api,encoding='utf-8',newline='\n')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','prepare','mql5','original','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);print(json.dumps(dict(bot=a.bot,generated=True)));return
    if not a.run or not re.fullmatch('[a-z0-9-]{1,50}',a.run):p.error('RUN is required')
    home=ROOT/f'bot-cua-toi-{a.bot}';m=module('manager_fields_'+str(a.bot),home/'tests/check-position-management-flow.py')
    m.SCRIPT=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PositionManagementFieldsCheck.mq5'
    m.MT=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025'
    old=m.identity
    def identity():
        value=old();value['helpers_sha256'][Path(__file__).relative_to(ROOT).as_posix()]=hashlib.sha256(Path(__file__).read_bytes()).hexdigest();return value
    m.identity=identity
    m.SCOPE.update(external_shared_fields_executed=True,unused_legacy_members_poisoned=True)
    if a.mode=='mql5':
        # The existing CLI hard-codes its old startup script. Use an explicit
        # startup contract for this different script and its private file path.
        m.TABLE_MODE=m.TRADE_MODE=True
        current=m.identity();folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run
        require=m.require;baseline=json.loads((folder/'baseline.json').read_text())
        require(all(baseline[k]==v for k,v in current.items()),'IDENTITY_CHANGED')
        rows=m.inputs.cases();require((folder/'cases.bin').read_bytes()==m.inputs.encode(rows),'INPUT_CHANGED')
        receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        require(build['target']==m.SCRIPT and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(m.sha(m.MT/'MQL5'/name)==build['sources_sha256'][name]==digest,'BUILD_SOURCE_CHANGED')
        binary=m.MT/'MQL5'/Path(m.SCRIPT).with_suffix('.ex5');require(m.sha(binary)==build['binary_sha256']==m.sha(receipt.parent/binary.name),'BINARY_CHANGED')
        files=m.MT/f'MQL5/Files/bot{a.bot}-position-management-fields'/a.run;files.mkdir(parents=True,exist_ok=False);shutil.copyfile(folder/'cases.bin',files/'cases.bin')
        preset=m.MT/'MQL5/Presets'/('manager-fields-'+a.run+'.set');ini=m.MT/('manager-fields-'+a.run+'.ini')
        preset.write_text('CheckRun='+a.run+'\nExecuteTableChildren=true\nExecuteTradeChildren=true\n'+('FirstZeroTicketChanged=false\nExecuteManagementRouter=false\n' if a.bot==1 else ''),encoding='utf-16')
        ini.write_text('[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript='+m.SCRIPT.removeprefix('Scripts/').removesuffix('.mq5').replace('/','\\')+'\nScriptParameters='+preset.name+'\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
        process=subprocess.Popen(f'"{m.MT/"terminal64.exe"}" /portable /config:"{ini}"',cwd=m.MT,creationflags=subprocess.CREATE_NO_WINDOW)
        try:code=process.wait(timeout=120)
        except subprocess.TimeoutExpired:process.terminate();process.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
        require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,len(rows)),'MT5_FAILED')
        for name in ['mql5-results.bin','cast-values.bin','script-status.bin']:
            with (folder/name).open('xb') as f:f.write((files/name).read_bytes())
        m.casts(folder/'cast-values.bin',len(rows))
        scope=dict(m.SCOPE,virtual_table_children_executed=True,trade_children_executed=True,child_helpers_intercepted=False,modify_child_intercepted=False,close_child_intercepted=False,terminal_send_replies_supplied=True)
        m.save(folder/'mql5-run.json',dict(**current,cases=len(rows),result_sha256=m.sha(folder/'mql5-results.bin'),casts_sha256=m.sha(folder/'cast-values.bin'),build=a.build,build_receipt_sha256=m.sha(receipt),**scope))
        print(json.dumps(dict(cases=len(rows),exit_code=code)));return
    sys.argv=[str(m.__file__),a.mode,a.run,'--trade-children']+(['--build',a.build] if a.build else [])
    m.main()
if __name__=='__main__':main()
