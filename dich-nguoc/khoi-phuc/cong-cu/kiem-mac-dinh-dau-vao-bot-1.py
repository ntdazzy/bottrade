"""Generate startup input defaults from a verified real disabled-profile capture.

generate CAPTURE_RUN | run TEST_RUN --capture CAPTURE_RUN --build BUILD.
Only internal preparation fields and its empty comment are initialized;
the current symbol and all thirteen user-controlled fields are preserved.
"""
import argparse,hashlib,importlib.util,json,re,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];MAGIC=0x44493131;MASK=(1<<64)-1
spec=importlib.util.spec_from_file_location('startup_defaults_pub',ROOT/'cong-cu/kiem-ban-git-quan-ly.py')
pub=importlib.util.module_from_spec(spec);spec.loader.exec_module(pub)
require=pub.require
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def data(run):
    require(re.fullmatch('[a-z0-9-]{1,48}',run),'BAD_CAPTURE_RUN');folder=ROOT/'bot-cua-toi-1/bang-chung'/run
    path=folder/'observed-preparation-inputs.json';r=json.loads(path.read_text());record=json.loads((folder/'capture-run.json').read_text())
    require(r['run_record_sha256']==sha(folder/'capture-run.json') and r['profile_flags_zero']==8 and r['preparation_index']==0,'OBSERVATION_CHANGED')
    capture=ROOT/'bot-cua-toi-1/bang-chung/captures'/run/'capture.json';require(sha(capture)==r['capture_sha256'],'CAPTURE_CHANGED')
    cap=json.loads(capture.read_text());regions=[]
    for region in cap['regions']:
        file=capture.parent/region['file'];require(sha(file)==region['sha256'],'CAPTURE_REGION_CHANGED');regions.append((region,file.read_bytes()))
    code=[region for region,_ in regions if region['kind']=='executable' and region['protect']==0x20 and region['bytes']>=8192]
    require(len(code)==1 and hex(code[0]['base'])==r['code_base'],'CODE_BASE_CHANGED')
    require(record['test_completed'] and record['strategy_profiles_disabled'] and record['source_sha256']==r['original_ex5_sha256']=='a3b0de423a06e10ebedc279307b93d7cb9188ba2bb5de77131a913c865b0e922','WRONG_ORIGINAL')
    require(len(r['fields'])==54 and sum(not f['user_input'] for f in r['fields'])==41,'FIELD_COUNT_CHANGED')
    for f in r['fields']:
        address=code[0]['base']+int(f['rva'],16);size=struct.calcsize('<'+f['kind'])
        found=next((raw[address-region['base']:address-region['base']+size] for region,raw in regions if region['base']<=address and address+size<=region['base']+len(raw)),None)
        require(found is not None and found.hex()==f['raw_hex'] and struct.pack('<'+f['kind'],f['value'])==found,'OBSERVED_FIELD_CHANGED '+f['field'])
    comment=next(s for s in r['strings'] if s['field']=='preparation_comment');require(comment['observed'] and comment['value']=='','COMMENT_NOT_CONFIRMED')
    return r,path
def name(f):return 'variable_distances' if f['field']=='use_variable' else f['field']
def text(value):
    if value is None:return struct.pack('<i',-1)
    raw=value.encode('utf-16-le');return struct.pack('<i',len(raw)//2)+raw
def literal(f):
    if f['kind']!='d':return str(f['value'])
    result=format(f['value'],'.17g');return result if any(ch in result for ch in '.eE') else result+'.0'
def generate(capture):
    r,path=data(capture);base=ROOT/'bot-cua-toi-1/source/MQL5';header=base/'Include/bot-cua-toi-1/Bot1StartupInputs.mqh';script=base/'Scripts/bot-cua-toi-1/Bot1StartupInputsCheck.mq5';require(not header.exists() and not script.exists(),'SOURCE_EXISTS')
    code='#ifndef BOT1_STARTUP_INPUTS_MQH\n#define BOT1_STARTUP_INPUTS_MQH\n#include "Bot1Preparation.mqh"\n\n// Call when loading program state, before the first preparation.\n// User inputs and the current symbol belong to their own bindings.\nvoid Bot1InitializeStartupInputs(Bot1PreparationInputs &inputs)\n{\n'
    code+=''.join(f'   inputs.{name(f)}={literal(f)};\n' for f in r['fields'] if not f['user_input'])
    code+='   inputs.comment="";\n}\n#endif\n';header.write_text(code,encoding='utf-8',newline='\n')
    reads='\n'.join('      Inputs.'+name(f)+'='+('Value((ulong)FileReadLong(file))' if f['kind']=='d' else ('(uchar)' if f['kind']=='B' else '(int)')+'FileReadLong(file)')+';' for f in r['fields'])
    writes='\n'.join('      FileWriteLong(output,(long)'+('Bits(Inputs.'+name(f)+')' if f['kind']=='d' else 'Inputs.'+name(f))+');' for f in r['fields'])
    template=r'''#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1StartupInputs.mqh"
union Number{double value;ulong word;};
ulong Bits(const double value){Number n;n.value=value;return n.word;}
double Value(const ulong word){Number n;n.word=word;return n.value;}
void Text(const int output,const string value){int n=value==NULL ? -1 : StringLen(value);FileWriteInteger(output,n);if(n>0)FileWriteString(output,value,n);}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-startup-inputs\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x44493131 || version!=1 || count!=4)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);Bot1PreparationInputs Inputs;
@READ@
      Inputs.symbol="XAUUSD.test";Inputs.comment="must change";
      Bot1InitializeStartupInputs(Inputs);
      FileWriteInteger(output,id);
@WRITE@
      Text(output,Inputs.symbol);Text(output,Inputs.comment);
   }
   if(FileTell(file)!=FileSize(file))return 5;FileClose(file);FileClose(output);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
'''
    script.write_text(template.replace('@READ@',reads).replace('@WRITE@',writes),encoding='utf-8',newline='\n');print(json.dumps(dict(internal_fields=41,user_fields_preserved=13,source=str(header))))
def inputs(r):
    rows=[]
    for i in range(4):
        words=[]
        for f in r['fields']:
            if f['kind']=='d':value=[-0.,1.25,-1.,12345.5][i];raw=struct.pack('<d',value)
            elif f['kind']=='B':raw=struct.pack('<Q',[0,1,2,255][i])
            else:raw=struct.pack('<Q',[-2147483648,0,3,9999][i]&MASK)
            words.append(int.from_bytes(raw,'little'))
        rows.append(words)
    return rows
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','run']);p.add_argument('run');p.add_argument('--capture');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.run);return
    require(a.capture and a.build and re.fullmatch('[a-z0-9-]{1,48}',a.run) and re.fullmatch('[a-z0-9-]{1,48}',a.build),'RUN_ARGUMENTS_REQUIRED')
    r,capture_path=data(a.capture);home=ROOT/'bot-cua-toi-1';src=home/'source/MQL5';script=src/'Scripts/bot-cua-toi-1/Bot1StartupInputsCheck.mq5';sources={p.relative_to(src).as_posix():sha(p) for p in pub.closure(script,src)}
    receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'));require(build['target']=='Scripts/bot-cua-toi-1/Bot1StartupInputsCheck.mq5' and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
    mt=ROOT.parent/'.local/mt5-bot1-thread-20261025'
    for path,h in sources.items():require(sha(mt/'MQL5'/path)==build['sources_sha256'][path]==h,'BUILD_SOURCE_CHANGED')
    binary=mt/'MQL5/Scripts/bot-cua-toi-1/Bot1StartupInputsCheck.ex5';require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
    folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;folder.mkdir(parents=True,exist_ok=False);files=mt/'MQL5/Files/bot1-startup-inputs'/a.run;files.mkdir(parents=True,exist_ok=False)
    rows=inputs(r);header=struct.pack('<3i',MAGIC,1,4);raw=header+b''.join(struct.pack('<i54Q',i,*words) for i,words in enumerate(rows));(folder/'cases.bin').write_bytes(raw);(files/'cases.bin').write_bytes(raw)
    preset=mt/'MQL5/Presets'/('startup-inputs-'+a.run+'.set');ini=mt/('startup-inputs-'+a.run+'.ini');preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16');ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-1\\Bot1StartupInputsCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=proc.wait(timeout=120)
    except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<2i',0,4),'MT5_FAILED')
    actual=(files/'mql5-results.bin').read_bytes();expected=bytearray(header)
    for i,words in enumerate(rows):
        result=[int.from_bytes(bytes.fromhex(f['raw_hex']),'little') if not f['user_input'] else v for f,v in zip(r['fields'],words)]
        # Integer fields are written as signed 64-bit values by MQL5.
        for j,f in enumerate(r['fields']):
            if f['kind']=='i' and result[j]&0x80000000:result[j]|=0xffffffff00000000
        expected+=struct.pack('<i54Q',i,*result)+text('XAUUSD.test')+text('')
    (folder/'mql5-results.bin').write_bytes(actual);(folder/'observed-expected.bin').write_bytes(expected)
    report=dict(cases=4,matched=4 if actual==expected else 0,failed=0 if actual==expected else 1,sources_sha256=sources,tool_sha256=sha(Path(__file__)),capture=a.capture,capture_observation_sha256=sha(capture_path),
                build=a.build,build_receipt_sha256=sha(receipt),result_sha256=sha(folder/'mql5-results.bin'),expected_sha256=sha(folder/'observed-expected.bin'),
                internal_fields=41,user_fields_preserved=13,symbol_preserved=True,full_ea=False,original_ex5_changed=False,
                scope='Input defaults observed from the real original after initialization with profiles disabled; raw constructor output state and full EA remain unverified.')
    with (folder/'comparison.json').open('x',encoding='utf-8') as out:json.dump(report,out,indent=2)
    print(json.dumps({k:v for k,v in report.items() if k!='sources_sha256'}));require(actual==expected,'INPUT_DEFAULTS_DIFFER')
if __name__=='__main__':main()
