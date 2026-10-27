"""Check full-header integration and actual objects against verified original calls.

Run after staging, optionally with --ref HEAD after committing. Read only.
"""
import argparse,ast,importlib.util,json,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];WORK=ROOT.parents[1];FOLDER=Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('panel_check',ROOT/'cong-cu/kiem-tao-bang-bot-1-3.py')
check=importlib.util.module_from_spec(s);s.loader.exec_module(check)
require=check.require;sha=check.sha

def read(path):return json.loads(path.read_text(encoding='utf-8-sig'))
def expected_objects(bot):
    run=ROOT/f'bot-cua-toi-{bot}/bang-chung/kiem-quan-ly-vi-the/b{bot}-panel-create-20261028-r4'
    original=read(run/'original-run.json');data=(run/'original-results.bin').read_bytes()
    require(sha(run/'original-results.bin')==original['result_sha256'],'ORIGINAL_RESULTS_CHANGED')
    count=original['cases'];require(data[:12]==struct.pack('<3i',check.MAGIC,1,count),'RESULT_HEADER')
    tapes=check.cell.records(struct.pack('<i',check.cell.MAGIC)+data[4:],count);r=check.Reader(tapes[0]);objects={};words=len(check.fields(bot))-1
    props={0x3f4:'x',0x3f5:'y',0x3fb:'width',0x3fc:'height',0x3ea:'font_size',0:'color',0x401:'background',0x40b:'border_color'}
    while True:
        r.take('Q'*words);r.text();r.take('Q')
        if r.pos==len(r.raw):break
        api,*args=r.take('i5Q');name=r.text();value=r.text();r.take('QI')
        if api==2:objects[name]=dict(type=args[1])
        elif api==3 and name in objects and args[1] in props:
            objects[name][props[args[1]]]=struct.unpack('<q',struct.pack('<Q',args[2]))[0]
        elif api==4 and name in objects and args[1] in [6,0x3e9]:objects[name]['text' if args[1]==6 else 'font']=value
    return objects

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--ref',default='');a=p.parse_args();out=[]
    for tool in ['phan-tich-tao-bang-bot-1-3.py','kiem-tao-bang-bot-1-3.py','kiem-hinh-bang-bot-1-3.py']:
        path=ROOT/'cong-cu'/tool;ast.parse(path.read_text(encoding='utf-8'),filename=str(path))
    for bot,headers in [(1,87),(3,94)]:
        home=ROOT/f'bot-cua-toi-{bot}';source=home/'source/MQL5';receipt=home/f'bang-chung/bien-dich/b{bot}-all-headers-api-20261028-r3/bien-nhan.json';build=read(receipt)
        require(build['errors']==build['warnings']==0,'ALL_HEADERS_NOT_CLEAN')
        script=source/f'Scripts/bot-cua-toi-{bot}/Bot{bot}AllHeadersAPICompile.mq5';closure=check.pub.closure(script,source)
        require(len(list((source/f'Include/bot-cua-toi-{bot}').glob('*.mqh')))==headers and len(closure)==headers+1,'HEADERS_MISSING')
        exact=0;newline=[]
        for path in closure:
            n=path.relative_to(source).as_posix();require(sha(path)==build['sources_sha256'][n],'ALL_HEADER_SOURCE_CHANGED')
            relative=path.relative_to(WORK).as_posix();stored=subprocess.check_output(['git','show',a.ref+':'+relative],cwd=WORK);actual=path.read_bytes()
            if stored==actual:exact+=1
            else:
                require(path.name in [f'Bot{bot}AccountInitialization.mqh',f'Bot{bot}AccountStateVolume.mqh',f'Bot{bot}AccountVolume.mqh',f'Bot{bot}Withdrawal.mqh'] and stored.replace(b'\r\n',b'\n')==actual.replace(b'\r\n',b'\n'),'GIT_CODE_DIFFERS '+relative)
                newline.append(relative)
        visual=home/f'bang-chung/kiem-quan-ly-vi-the/b{bot}-panel-visual-20261028-r2';measured=read(visual/'objects.json');vr=read(visual/'visual-run.json')
        require(sha(visual/'objects.bin')==vr['result_sha256'] and sha(visual/'panel.png')==vr['screenshot_sha256'],'VISUAL_DATA_CHANGED')
        require(sha(visual/'sdk-properties.bin')==vr['sdk_properties_sha256'],'PROPERTY_PROBE_CHANGED');probe=read(visual/'sdk-properties.json')
        magic,accepted,set_error,value,get_error=struct.unpack('<3iqi',(visual/'sdk-properties.bin').read_bytes())
        require(magic==0x50525031 and (bool(accepted),set_error,value,get_error)==(probe['accepted'],probe['set_error'],probe['value'],probe['get_error']),'PROPERTY_PROBE_JSON_DIFFERS')
        expected=expected_objects(bot);require(set(expected)==set(measured),'ACTUAL_OBJECT_NAMES_DIFFER');properties=0
        for name,values in expected.items():
            for key,value in values.items():
                if name=='infopanel_rectangle' and key=='border_color':
                    require(probe['property']==0x40b and probe['requested']==value and probe['get_error']==4203 and measured[name][key]==probe['value'],'UNREADABLE_PROPERTY_NOT_PROVEN')
                    continue
                require(measured[name][key]==value,'ACTUAL_OBJECT_PROPERTY_DIFFERS '+str((bot,name,key,value,measured[name][key])));properties+=1
        inspection=next(r for r in read(FOLDER/'visual-inspection.json') if r['bot']==bot)
        require(inspection['opened_by_codex'] and inspection['screenshot_sha256']==vr['screenshot_sha256'] and not inspection['original_rendering_compared'],'VISUAL_SCOPE')
        out.append(dict(bot=bot,headers=headers,errors=0,warnings=0,exact_files=exact,newline_only_equivalent_files=sorted(newline),actual_objects=len(expected),actual_properties_matching_verified_original_calls=properties,unreadable_property=dict(object='infopanel_rectangle',property=0x40b,get_error=4203),original_rendering_compared=False))
    print(json.dumps(dict(ref=a.ref or 'index',results=out,full_eas_complete=0),ensure_ascii=False))

if __name__=='__main__':main()
