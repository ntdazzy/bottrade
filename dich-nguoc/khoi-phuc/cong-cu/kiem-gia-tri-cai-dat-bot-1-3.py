"""Run input recorders in isolated MT5; compare exact values with verified original .set exports.

run BOT RUN --build BUILD; compare BOT RUN. Does not claim trading or rendered-menu parity.
"""
import argparse,hashlib,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('input_generator',ROOT/'cong-cu/tao-khai-bao-cai-dat-bot-1-3.py')
generator=importlib.util.module_from_spec(spec);spec.loader.exec_module(generator)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def require(value,message):
    if not value:raise ValueError(message)
def save(path,value):
    with path.open('x',encoding='utf-8',newline='\n') as stream:json.dump(value,stream,ensure_ascii=False,indent=2);stream.write('\n')
def preset_values(path):
    raw=path.read_bytes();text=raw.decode('utf-16') if raw[:2] in [b'\xff\xfe',b'\xfe\xff'] else raw.decode('utf-8-sig')
    result={}
    for line in text.splitlines():
        if not line or line.startswith(';'):continue
        name,value=line.split('=',1);require(name not in result,'DUPLICATE_PRESET_INPUT '+name)
        result[name]=value.split('||',1)[0]
    return result
def complete_values(block,name):
    defaults=preset_values(generator.MENU.parent/block['defaults_set'])
    changes=preset_values(generator.MENU.parent/name)
    require(set(changes)<=set(defaults),'UNKNOWN_PRESET_INPUT')
    defaults.update(changes)
    return defaults
def identity(bot):
    source=ROOT/f'bot-cua-toi-{bot}/source/MQL5';menu=json.loads(generator.MENU.read_text(encoding='utf-8'))
    block=next(v for v in menu['bots'] if v['bot']==bot)
    generator.validate(block,generator.MENU.parent/block['defaults_set'])
    require(len(block['settings'])==block['default_count']==(72 if bot==1 else 80),'INPUT_COUNT')
    names=[block['defaults_set']]+sorted({choice['value_preset'] for m in block['menus'] for choice in m['choices']}-{block['defaults_set']})
    files=[generator.MENU,ROOT/block['binding_evidence']]+[generator.MENU.parent/name for name in names]
    require(sha(ROOT/block['binding_evidence'])==block['binding_evidence_sha256'],'BINDING_CHANGED')
    script=f'Scripts/bot-cua-toi-{bot}/Bot{bot}InputsCheck.mq5';header=f'Include/bot-cua-toi-{bot}/Bot{bot}Inputs.mqh'
    return block,names,dict(sources_sha256={n:sha(source/n) for n in [script,header]},
        evidence_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in files},
        helpers_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in [Path(__file__),Path(generator.__file__)]})
class Reader:
    def __init__(self,raw):self.raw=raw;self.pos=0
    def take(self,fmt):
        n=struct.calcsize('<'+fmt);require(self.pos+n<=len(self.raw),'TRUNCATED_INPUT_RECORD')
        v=struct.unpack_from('<'+fmt,self.raw,self.pos);self.pos+=n;return v
    def text(self):
        n,=self.take('i');require(-1<=n<=100000,'TEXT_LENGTH');size=max(n,0)*2
        require(self.pos+size<=len(self.raw),'TEXT_BOUNDS');raw=self.raw[self.pos:self.pos+size];self.pos+=size
        return None if n<0 else raw.decode('utf-16-le')
def inspect(raw,settings,expected):
    r=Reader(raw);require(r.take('3i')==(0x494e5031,1,len(settings)),'INPUT_RECORD_HEADER');values=[]
    require(set(expected)=={s['name'] for s in settings},'PRESET_INPUT_SET_CHANGED')
    for setting in settings:
        name=r.text();kind,=r.take('i');representation=setting['representation']
        want={'bool':1,'integer_or_enum':2,'double':3,'string':4}[representation]
        require(name==setting['name'] and kind==want,'INPUT_NAME_ORDER_OR_KIND '+str((name,kind)))
        value=r.take('i')[0] if kind in [1,2] else r.take('d')[0] if kind==3 else r.text()
        text=expected[name]
        correct=(value==int(text=='true')) if kind==1 else value==int(text) if kind==2 else struct.pack('<d',value)==struct.pack('<d',float(text)) if kind==3 else value==text
        require(correct,'INPUT_VALUE '+str((name,value,text)));values.append(dict(name=name,kind=kind,value=value))
    require(r.pos==len(raw),'INPUT_RECORD_TRAILING');return values
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['run','compare']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run');p.add_argument('--build');a=p.parse_args()
    require(re.fullmatch('[a-z0-9-]{1,36}',a.run),'BAD_RUN');block,names,current=identity(a.bot)
    home=ROOT/f'bot-cua-toi-{a.bot}';folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run
    if a.mode=='run':
        require(a.build,'BUILD_REQUIRED');receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
        mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025';script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}InputsCheck.mq5'
        require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
        for name,digest in current['sources_sha256'].items():require(sha(mt/'MQL5'/name)==digest==build['sources_sha256'][name],'BUILD_SOURCE_CHANGED')
        binary=mt/'MQL5'/Path(script).with_suffix('.ex5');require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
        folder.mkdir(parents=True,exist_ok=False);save(folder/'baseline.json',dict(**current,build=a.build,build_receipt_sha256=sha(receipt),presets=names,whole_bot_complete=False))
        runs=[]
        for index,name in enumerate(names):
            require(sha(binary)==build['binary_sha256'],'BINARY_CHANGED_BETWEEN_PRESETS')
            for source,digest in current['sources_sha256'].items():
                require(sha(mt/'MQL5'/source)==digest,'SOURCE_CHANGED_BETWEEN_PRESETS')
            run=a.run+'-'+str(index);files=mt/f'MQL5/Files/bot{a.bot}-inputs'/run;files.mkdir(parents=True,exist_ok=False)
            preset=mt/'MQL5/Presets'/('inputs-'+run+'.set');ini=mt/('inputs-'+run+'.ini')
            values=complete_values(block,name)
            # Observed option presets contain only changed fields. Supply the original
            # defaults for all others so no cached terminal input influences this run.
            text='\r\n'.join(setting['name']+'='+values[setting['name']] for setting in block['settings'])
            preset.write_text(text+'\r\nCheckRun='+run+'\r\n',encoding='utf-16',newline='')
            ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}InputsCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
            proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
            try:code=proc.wait(timeout=120)
            except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
            require(code==0 and (files/'values.bin').is_file(),'MT5_VALUES_MISSING '+name)
            result=folder/(str(index)+'-values.bin');shutil.copyfile(files/'values.bin',result)
            measured=inspect(result.read_bytes(),block['settings'],values)
            save(folder/(str(index)+'-values.json'),measured)
            require(sha(binary)==build['binary_sha256'],'BINARY_CHANGED_DURING_PRESET')
            runs.append(dict(preset=name,sha256=sha(result),file=result.name,values=len(measured),exit_code=code,binary_sha256=sha(binary)))
        save(folder/'mql5-run.json',dict(**current,build=a.build,runs=runs,whole_bot_complete=False))
        print(json.dumps(dict(presets=len(runs),values=sum(r['values'] for r in runs))));return
    baseline=json.loads((folder/'baseline.json').read_text());run=json.loads((folder/'mql5-run.json').read_text())
    require(all(baseline[k]==v==run[k] for k,v in current.items()),'IDENTITY_CHANGED')
    require([r['preset'] for r in run['runs']]==names,'PRESET_LIST_CHANGED')
    receipt=home/'bang-chung/bien-dich'/baseline['build']/'bien-nhan.json'
    require(sha(receipt)==baseline['build_receipt_sha256'],'BUILD_RECEIPT_CHANGED')
    build=json.loads(receipt.read_text(encoding='utf-8-sig'))
    for record in run['runs']:
        path=folder/record['file'];require(sha(path)==record['sha256'],'MEASURED_VALUES_CHANGED')
        require(record['binary_sha256']==build['binary_sha256'],'PRESET_BINARY_CHANGED')
        inspect(path.read_bytes(),block['settings'],complete_values(block,record['preset']))
    total=sum(r['values'] for r in run['runs']);report=dict(presets=len(names),values=total,matched=total,failed=0,whole_bot_complete=False,
        scope='Exact input names, order, values, all observed enum choices and original set loading in MT5. Original exported settings are evidence; no claim for full trading effects, hidden label text or rendered UI.')
    save(folder/'comparison.json',report);print(json.dumps(report))
if __name__=='__main__':main()
