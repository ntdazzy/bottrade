"""Symbolic construction traces, not behavioral test results."""
import importlib.util,json
from pathlib import Path
HOME=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('panel_trace',HOME/'trace-native.py')
t=importlib.util.module_from_spec(s);s.loader.exec_module(t)
rows=[]
for bot in [1,3]:
    variants=[('default',{})]
    if bot==1:
        for mode in [3,999,9999]:variants.append(('mode-'+str(mode),dict(words={'6a748':mode})))
    else:
        for mode in [3,1234]:variants.append(('mode-'+str(mode),dict(words={'6d630':mode})))
        for freq in [-1,0,1,2,3,4,5]:variants.append(('frequency-'+str(freq),dict(words={'6d21c':freq})))
    for info in [0,1]:
        for show in [0,1]:variants.append(('info-%s-show-%s'%(info,show),dict(info=info,bytes={('6a530' if bot==1 else '1d6f40'):show})))
    flags=['6a640','6a698','6a6d0'] if bot==1 else ['1d7020','1d7078','1d70b0']
    times=['6a360','6a368','6a370'] if bot==1 else ['1d6c70','1d6c78','1d6c80']
    for i in range(3):variants.append(('news-'+str(i),dict(bytes={flags[i]:1},longs={times[i]:1767355500})))
    for name,options in variants:
        result=t.Trace(bot,options).run();rows.append(dict(bot=bot,name=name,options=options,events=result['events']))
        print(json.dumps(rows[-1],ensure_ascii=False))
path=HOME/'symbolic-variants.json'
with path.open('x',encoding='utf-8') as f:json.dump(rows,f,ensure_ascii=False,indent=2)
