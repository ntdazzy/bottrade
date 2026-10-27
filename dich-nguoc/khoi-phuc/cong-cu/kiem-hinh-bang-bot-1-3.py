"""Render the source panel in isolated MT5 and inspect actual chart objects.

generate BOT; run BOT RUN --build BUILD. This does not compare original screenshots.
"""
import argparse,importlib.util,json,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
s=importlib.util.spec_from_file_location('creation_check',ROOT/'cong-cu/kiem-tao-bang-bot-1-3.py')
check=importlib.util.module_from_spec(s);s.loader.exec_module(check)
require=check.require;sha=check.sha;save=check.save
TEMPLATE=r'''#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-@N@/Bot@N@PanelCreation.mqh"
Bot@N@PanelCreationState P;Bot@N@NewsEvents Events;Bot@N@NewsWindows Windows;Bot@N@NewsSelection Selection;
union Number { double value;ulong word; };
double FromBits(const ulong word) { Number n;n.word=word;return n.value; }
void Text(const int file,const string value)
{ int n=StringLen(value);FileWriteInteger(file,n);if(n>0)FileWriteString(file,value,n); }
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot@N@-panel-visual\\"+CheckRun+"\\";
   string names[]={"infopanel_rectangle","line1","linec","line2","lines","linet","lineopl0","linea0","linetp0","linenfp0"};
   for(int i=0;i<ArraySize(names);i++)ObjectDelete(0,names[i]);
   ObjectsDeleteAll(0,"info_ea");
@INITIALIZE@
   Bot@N@CreateInfoPanel(P,Events,Windows,Selection);ChartRedraw(0);
   int output=FileOpen(folder+"objects.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE)return 2;
   int count=ObjectsTotal(0,-1,-1);FileWriteInteger(output,0x50564931);FileWriteInteger(output,1);FileWriteInteger(output,count);
   ENUM_OBJECT_PROPERTY_INTEGER properties[]={OBJPROP_TYPE,OBJPROP_XDISTANCE,OBJPROP_YDISTANCE,OBJPROP_XSIZE,OBJPROP_YSIZE,
      OBJPROP_FONTSIZE,OBJPROP_COLOR,OBJPROP_BGCOLOR,OBJPROP_BORDER_COLOR,OBJPROP_SELECTABLE,OBJPROP_HIDDEN};
   for(int i=0;i<count;i++)
   {
      string name=ObjectName(0,i,-1,-1);Text(output,name);
      for(int j=0;j<ArraySize(properties);j++)FileWriteLong(output,ObjectGetInteger(0,name,properties[j]));
      Text(output,ObjectGetString(0,name,OBJPROP_TEXT));Text(output,ObjectGetString(0,name,OBJPROP_FONT));
   }
   FileClose(output);
   ResetLastError();bool border_set=ObjectSetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x40b,0x3a2a1e);
   int set_error=GetLastError();ResetLastError();long border=ObjectGetInteger(0,"infopanel_rectangle",(ENUM_OBJECT_PROPERTY_INTEGER)0x40b);
   int get_error=GetLastError();int probe=FileOpen(folder+"sdk-properties.bin",FILE_WRITE|FILE_BIN);if(probe==INVALID_HANDLE)return 5;
   FileWriteInteger(probe,0x50525031);FileWriteInteger(probe,border_set ? 1 : 0);FileWriteInteger(probe,set_error);
   FileWriteLong(probe,border);FileWriteInteger(probe,get_error);FileClose(probe);
   bool shot=ChartScreenShot(0,folder+"panel.png",1200,720,ALIGN_RIGHT);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 3;
   FileWriteInteger(status,shot ? 0 : 4);FileWriteInteger(status,count);FileWriteInteger(status,(int)P.rows_ready);FileClose(status);
   return shot ? 0 : 4;
}
'''

def generate(bot):
    c=check.cases(bot)[0];lines=[]
    for n,k,_ in check.fields(bot):
        value=c['values'][n]
        literal=json.dumps(value,ensure_ascii=False) if k=='s' else f'FromBits({check.word(value,k)})' if k=='d' else str(value)
        lines.append('   '+n+'='+literal+';')
    code=TEMPLATE.replace('@N@',str(bot)).replace('@INITIALIZE@','\n'.join(lines))
    path=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}PanelCreationVisualCheck.mq5'
    path.write_text(code,encoding='utf-8',newline='\n')

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('mode',choices=['generate','run']);p.add_argument('bot',type=int,choices=[1,3]);p.add_argument('run',nargs='?');p.add_argument('--build');a=p.parse_args()
    if a.mode=='generate':generate(a.bot);return
    require(a.run and re.fullmatch('[a-z0-9-]{1,48}',a.run) and a.build,'BAD_RUN_OR_BUILD')
    home=ROOT/f'bot-cua-toi-{a.bot}';source=home/'source/MQL5';mt=ROOT.parent/f'.local/mt5-bot{a.bot}-thread-20261025'
    script=f'Scripts/bot-cua-toi-{a.bot}/Bot{a.bot}PanelCreationVisualCheck.mq5';receipt=home/'bang-chung/bien-dich'/a.build/'bien-nhan.json';build=json.loads(receipt.read_text(encoding='utf-8-sig'))
    require(build['target']==script and build['errors']==build['warnings']==0,'BUILD_NOT_CLEAN')
    sources={p.relative_to(source).as_posix():sha(p) for p in check.pub.closure(source/script,source)}
    binary=mt/'MQL5'/Path(script).with_suffix('.ex5')
    def unchanged():
        for n,h in sources.items():require(sha(mt/'MQL5'/n)==build['sources_sha256'][n]==h,'BUILD_SOURCE_CHANGED')
        require(sha(binary)==build['binary_sha256']==sha(receipt.parent/binary.name),'BUILD_BINARY_CHANGED')
    unchanged();folder=home/'bang-chung/kiem-quan-ly-vi-the'/a.run;folder.mkdir(parents=True,exist_ok=False)
    files=mt/f'MQL5/Files/bot{a.bot}-panel-visual'/a.run;files.mkdir(parents=True,exist_ok=False)
    preset=mt/'MQL5/Presets'/('panel-visual-'+a.run+'.set');ini=mt/('panel-visual-'+a.run+'.ini')
    preset.write_text('CheckRun='+a.run+'\n',encoding='utf-16')
    ini.write_text(f'[Experts]\nEnabled=0\nAllowLiveTrading=0\nAllowDllImport=0\n[StartUp]\nScript=bot-cua-toi-{a.bot}\\Bot{a.bot}PanelCreationVisualCheck\nScriptParameters={preset.name}\nSymbol=XAUUSD_NOCOST_V2\nPeriod=M15\nShutdownTerminal=1\n',encoding='utf-16')
    proc=subprocess.Popen(f'"{mt/"terminal64.exe"}" /portable /config:"{ini}"',cwd=mt,creationflags=subprocess.CREATE_NO_WINDOW)
    try:code=proc.wait(timeout=120)
    except subprocess.TimeoutExpired:proc.terminate();proc.wait(timeout=30);raise RuntimeError('MT5_TIMEOUT')
    unchanged();expected=45 if a.bot==1 else 50
    require(code==0 and (files/'script-status.bin').read_bytes()==struct.pack('<3i',0,expected,1),'SCRIPT_STATUS')
    for n in ['objects.bin','script-status.bin','panel.png','sdk-properties.bin']:shutil.copyfile(files/n,folder/n)
    r=check.Reader((folder/'objects.bin').read_bytes());require(r.take('3i')==(0x50564931,1,expected),'OBJECT_HEADER')
    names=['type','x','y','width','height','font_size','color','background','border_color','selectable','hidden'];objects={}
    for _ in range(expected):
        name=r.text();require(name not in objects,'DUPLICATE_OBJECT');objects[name]=dict(zip(names,r.take('q'*len(names))),text=r.text(),font=r.text())
    require(r.pos==len(r.raw),'OBJECT_TRAILING')
    require(sum(n.startswith('info_ea') for n in objects)==(36 if a.bot==1 else 40),'CELL_COUNT')
    require(objects['line1']['text']==('Gold Trade Pro V7.1' if a.bot==1 else 'The Gold Reaper V5.5'),'TITLE')
    require(objects['infopanel_rectangle']['width']==350 and objects['infopanel_rectangle']['height']==(320 if a.bot==1 else 350),'FRAME')
    save(folder/'objects.json',objects)
    magic,accepted,set_error,value,get_error=struct.unpack('<3iqi',(folder/'sdk-properties.bin').read_bytes());require(magic==0x50525031,'PROBE_HEADER')
    save(folder/'sdk-properties.json',dict(object='infopanel_rectangle',type=110,property=0x40b,requested=0x3a2a1e,accepted=bool(accepted),set_error=set_error,value=value,get_error=get_error))
    result=dict(bot=a.bot,objects=expected,cells=36 if a.bot==1 else 40,sources_sha256=sources,build=a.build,
                build_receipt_sha256=sha(receipt),helpers_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},
                result_sha256=sha(folder/'objects.bin'),screenshot_sha256=sha(folder/'panel.png'),sdk_properties_sha256=sha(folder/'sdk-properties.bin'),full_ea=False,
                actual_mt5_objects_verified=True,original_rendering_compared=False,visual_inspection_pending=True)
    save(folder/'visual-run.json',result);print(json.dumps(dict(bot=a.bot,objects=expected,cells=result['cells'],screenshot=str(folder/'panel.png'))))

if __name__=='__main__':main()
