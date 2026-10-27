"""Join existing SDK recorders for continuous news -> cached levels -> entry loops."""
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
for bot in [1,3]:
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    source=(folder/f'Bot{bot}EntryLoopCheck.mq5').read_text()
    prefix=(folder/f'Bot{bot}EvaluationEntryLevelsCheck.mq5').read_text()
    def snapshot_body(text):
        a=text.index('void Snapshot()');b=text.index('void Begin()',a);body=text[a:b];body=body[body.index('{')+1:body.rfind('}')]
        return '\n'.join(line for line in body.splitlines() if 'uint error=' not in line and 'if(RecordFinal)' not in line)
    parent=snapshot_body(prefix).replace('Word(Bits(CachedLower[i]))','Word(Bits(i==99 ? LoopState.active_step : CachedLower[i]))')
    direct=snapshot_body(source)
    a=source.index('void Snapshot()');b=source.index('void Begin()',a)
    merged='void Snapshot()\n{\n   uint error=EndErrorOverride>=0 ? (uint)EndErrorOverride : SourceError();\n'+parent+'\n'+direct+'\n   if(RecordFinal) Word((ulong)Decision);\n}\n'
    source=source[:a]+merged+source[b:]
    old=f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}EntryLoop.mqh"';source=source.replace(old,f'#include "../../Include/bot-cua-toi-{bot}/Bot{bot}EvaluationTradeFlow.mqh"')
    a=source.index(f'Decision=BOT{bot}_LEVEL_NEW_BAR;Bot{bot}RunEntryLoop(');b=source.index(';int final_error=',a)
    args='Settings,State,InterestSettings,InterestState,CpiSettings,CpiState,Events,Cached,History,History,History,Execution,Selection,Friday,FridayClosed,SpreadSettings,SpreadUnit,CurrentSpread,Queue,Restore,PendingEnabled,MaximumPending,LevelSettings,CallerIndex,CurrentIndex,BarTimes,CachedUpper,CachedLower,LoopSettings,LoopState,VolumeSettings,VolumeState,false,VolumePeak,VolumeTime,VolumeLastCheck,VolumeLastDeal,VolumeSuffix'
    if bot==3:args+=',WeightDenominator,VolumeEnabled'
    source=source[:a]+f'Decision=Bot{bot}EvaluateTradeFlow('+args+',Volumes)'+source[b:]
    source=source.replace(f'bot{bot}-entry-loop',f'bot{bot}-evaluation-trade-flow').replace('ENTRY_LOOP_CASE','EVALUATION_TRADE_FLOW_CASE')
    (folder/f'Bot{bot}EvaluationTradeFlowCheck.mq5').write_text('\n'.join(line.rstrip() for line in source.splitlines())+'\n',encoding='utf-8',newline='\n')

    api=(folder/f'Bot{bot}EvaluationEntryLevelsAPICompile.mq5').read_text().replace(f'Bot{bot}EvaluationEntryLevels.mqh',f'Bot{bot}EvaluationTradeFlow.mqh')
    marker='   int pending_enabled=0,maximum_pending=0;'
    extra=f'''   Bot{bot}EntryLoopSettings loop_settings;Bot{bot}EntryLoopState loop_state;
   Bot{bot}VolumeSettings volume_settings;Bot{bot}VolumeState volume_state;
   ZeroMemory(loop_settings);ZeroMemory(loop_state);ZeroMemory(volume_settings);ZeroMemory(volume_state);
   string peak_key="",time_key="",suffix="";long last_check=0,last_deal=0;double volumes[{8 if bot==1 else 9}];ArrayInitialize(volumes,0);
'''
    if bot==3:extra+='   double denominator=1;uchar enabled[5];ArrayInitialize(enabled,0);\n'
    assert marker in api;api=api.replace(marker,extra+marker)
    api=api.replace(f'Bot{bot}EvaluateThroughEntryLevels(',f'Bot{bot}EvaluateTradeFlow(')
    more=',loop_settings,loop_state,volume_settings,volume_state,false,peak_key,time_key,last_check,last_deal,suffix'
    if bot==3:more+=',denominator,enabled'
    api=api.replace('current_index,bar_times,upper,lower);','current_index,bar_times,upper,lower'+more+',volumes);')
    (folder/f'Bot{bot}EvaluationTradeFlowAPICompile.mq5').write_text(api,encoding='utf-8',newline='\n')
