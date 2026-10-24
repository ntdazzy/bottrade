"""Create new scan checks from the frozen r4 close check; never edit the old check.

Usage: tao-kiem-chon-vi-the-dong.py
Writes exactly two new PositionSelectionCheck.mq5 files; rejects existing output.
"""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]

GLOBALS="""
struct ScanPosition { ulong ticket;long kind;double volume;int symbol_null;string symbol;long magics[15]; };
ScanPosition ScanPositions[];
int ScanKind=0,ScanScenario=0,ScanTotalValue=0,ScanSeed=0,ScanSelected=-1;
int ScanMagicIndex=0,ScanTicketCalls=0,ScanHelperCalls=0;
ulong ScanLastTicket=0;
string ScanSymbol;
bool ScanInHelper=false;
long ScanInteger(const ENUM_POSITION_PROPERTY_INTEGER property);
double ScanDouble(const ENUM_POSITION_PROPERTY_DOUBLE property);
string ScanString(const ENUM_POSITION_PROPERTY_STRING property);
"""
STATE="""
   FileWriteLong(file,(long)ScanLastTicket);FileWriteInteger(file,ScanSeed);
   FileWriteInteger(file,(int)(ScanSymbol==NULL));FileWriteInteger(file,ScanSelected);FileWriteInteger(file,ScanHelperCalls);Text(file,ScanSymbol);
"""
FUNCTIONS="""
void ScanChange(const int api)
{
   if(api==70 && ScanScenario==1) ScanSeed=-1;
   if(api==71 && ScanTicketCalls==1 && ScanScenario==2) ScanSeed=-1;
   if(api==21 && ScanMagicIndex==1 && ScanScenario==3) ScanSymbol="Renamed";
   if(api==23 && ScanScenario==6) ScanSymbol="Renamed";
   if(api==22 && ScanScenario==4) ScanLastTicket=(ulong)0xdeadbeef12345678;
   if(api==81 && ScanHelperCalls==1 && ScanScenario==5) { ScanSeed=-1;ScanSymbol="Renamed"; }
}
int ScanTotal()
{
   CloseSnapshot();Event(70);FileWriteInteger(fixture,ScanTotalValue);ScanChange(70);return ScanTotalValue;
}
ulong ScanTicket(const int index)
{
   CloseSnapshot();ulong ticket=0;
   if(index>=0 && index<ArraySize(ScanPositions)) ticket=ScanPositions[index].ticket;
   if(ticket!=0) ScanSelected=index;
   ScanTicketCalls++;ScanMagicIndex=0;
   Event(71);FileWriteInteger(fixture,index);FileWriteLong(fixture,(long)ticket);FileWriteInteger(fixture,ScanSelected);
   ScanChange(71);return ticket;
}
long ScanInteger(const ENUM_POSITION_PROPERTY_INTEGER property)
{
   CloseSnapshot();int index=0;long value=0;
   if(ScanSelected<0 || ScanSelected>=ArraySize(ScanPositions)) api_error=true;
   else if(property==POSITION_MAGIC)
   { index=ScanMagicIndex++;if(index<15) value=ScanPositions[ScanSelected].magics[index];else api_error=true; }
   else if(property==POSITION_TYPE) value=ScanPositions[ScanSelected].kind;
   else api_error=true;
   Event(21);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,index);FileWriteLong(fixture,value);ScanChange(21);return value;
}
double ScanDouble(const ENUM_POSITION_PROPERTY_DOUBLE property)
{
   CloseSnapshot();double value=0.0;
   if(property!=POSITION_VOLUME || ScanSelected<0 || ScanSelected>=ArraySize(ScanPositions)) api_error=true;
   else value=ScanPositions[ScanSelected].volume;
   Event(22);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,0);FileWriteDouble(fixture,value);ScanChange(22);return value;
}
string ScanString(const ENUM_POSITION_PROPERTY_STRING property)
{
   CloseSnapshot();string value;
   if(property!=POSITION_SYMBOL || ScanSelected<0 || ScanSelected>=ArraySize(ScanPositions)) api_error=true;
   else if(ScanPositions[ScanSelected].symbol_null!=0) value=NULL;else value=ScanPositions[ScanSelected].symbol;
   Event(23);FileWriteInteger(fixture,(int)property);FileWriteInteger(fixture,0);FileWriteInteger(fixture,(int)(value==NULL));Text(fixture,value);
   ScanChange(23);return value;
}
void ScanTryClose(BotNPendingRequestState &state,BotNTradeSendOptions &options,const ulong &deviation,
                   const double &a,const double &b,const double &t1,const double &t2,const ulong ticket)
{
   ScanHelperCalls++;CloseTicket=ticket;ScanInHelper=true;
   CloseSelectIndex=0;CloseTypeIndex=0;CloseSLIndex=0;CloseVolumeIndex=0;CloseSymbolIndex=0;ClosePriceIndex=0;
   property_index[0]=0;property_index[1]=0;pending_execution_index=0;pending_filling_index=0;
   Event(80);FileWriteLong(fixture,(long)ticket);WriteCloseState(fixture);
   BotNTryClosePosition(state,options,deviation,a,b,t1,t2,ticket);
   Event(81);WriteCloseState(fixture);ScanInHelper=false;ScanChange(81);
}
#define PositionsTotal ScanTotal
#define PositionGetTicket ScanTicket
#define PositionGetInteger CloseInteger
#define PositionGetDouble CloseDouble
#define PositionGetString CloseString
#define BotNTryClosePosition ScanTryClose
#include <bot-cua-toi-N/BotNPositionSelection.mqh>
#undef PositionsTotal
#undef PositionGetTicket
#undef PositionGetInteger
#undef PositionGetDouble
#undef PositionGetString
#undef BotNTryClosePosition
"""
READ="""
      ScanKind=FileReadInteger(file);ScanScenario=FileReadInteger(file);ScanTotalValue=FileReadInteger(file);ScanSeed=FileReadInteger(file);
      ScanLastTicket=(ulong)FileReadLong(file);int symbol_null=FileReadInteger(file);ScanSelected=FileReadInteger(file);ScanSymbol=ReadText(file);if(symbol_null!=0) ScanSymbol=NULL;
      int size=FileReadInteger(file);if(size<0 || size>16 || ScanTotalValue>32) { FileClose(file);FileClose(output);FileClose(fixture);return 6; }
      if(ArrayResize(ScanPositions,size)!=size) { FileClose(file);FileClose(output);FileClose(fixture);return 6; }
      for(int j=0;j<size;j++)
      {
         ScanPositions[j].ticket=(ulong)FileReadLong(file);ScanPositions[j].kind=FileReadLong(file);ScanPositions[j].volume=FileReadDouble(file);
         ScanPositions[j].symbol_null=FileReadInteger(file);ScanPositions[j].symbol=ReadText(file);
         for(int k=0;k<15;k++) ScanPositions[j].magics[k]=FileReadLong(file);
      }
      if(ScanKind<0 || ScanKind>1 || ScanScenario<0 || ScanScenario>6 || ScanSelected<-1 || ScanSelected>=size)
      { FileClose(file);FileClose(output);FileClose(fixture);return 6; }
      ScanMagicIndex=0;ScanTicketCalls=0;ScanHelperCalls=0;ScanInHelper=false;
"""

def replace_once(text,old,new):
    if text.count(old)!=1:raise ValueError('FROZEN_SOURCE_SHAPE_CHANGED '+old[:60])
    return text.replace(old,new)

def main():
    outputs=[]
    for bot in [1,3]:
        home=ROOT/f'bot-cua-toi-{bot}';old=home/f'bang-chung/kiem-dong-vi-the/close-20261025-r4/tested-sources/Bot{bot}PositionCloseCheck.mq5'
        receipt=json.loads((old.parent.parent/'mql5-run.json').read_text());name=f'Scripts/bot-cua-toi-{bot}/Bot{bot}PositionCloseCheck.mq5'
        if hashlib.sha256(old.read_bytes()).hexdigest()!=receipt['sources_sha256'][name]:raise ValueError('FROZEN_CHECK_CHANGED')
        text=old.read_text()
        text=replace_once(text,'void SeedCheck(',GLOBALS+'\nvoid SeedCheck(')
        end='   for(int i=0;i<4;i++) { DoubleBits v;v.value=CloseVariables[i];FileWriteLong(file,(long)v.bits); }\n'
        text=replace_once(text,end,end+STATE)
        for kind,ret in [('Integer','long'),('Double','double'),('String','string')]:
            signature=f'{ret} Close{kind}(const ENUM_POSITION_PROPERTY_{"INTEGER" if kind=="Integer" else "DOUBLE" if kind=="Double" else "STRING"} property)\n{{\n'
            text=replace_once(text,signature,signature+f'   if(!ScanInHelper) return Scan{kind}(property);\n')
        text=replace_once(text,'int OnStart()',FUNCTIONS.replace('BotN',f'Bot{bot}').replace('toi-N',f'toi-{bot}')+'\nint OnStart()')
        text=text.replace('0x50434c31','0x50534c31').replace(f'bot{bot}-position-close',f'bot{bot}-position-selection')
        marker='      for(int j=0;j<4;j++) CloseVariables[j]=FileReadDouble(file);\n'
        text=replace_once(text,marker,marker+READ)
        old_call=f'      if(CloseMode==0) Bot{bot}ClosePosition(CloseState,CloseOptions,CloseDeviation,CloseTicket);\n      else Bot{bot}TryClosePosition(CloseState,CloseOptions,CloseDeviation,CloseVariables[0],CloseVariables[1],CloseVariables[2],CloseVariables[3],CloseTicket);'
        args='ScanSeed,ScanSymbol,ScanLastTicket,CloseState,CloseOptions,CloseDeviation,CloseVariables[0],CloseVariables[1],CloseVariables[2],CloseVariables[3]'
        text=replace_once(text,old_call,f'      if(ScanKind==0) Bot{bot}CloseFilteredBuyPositions({args});\n      else Bot{bot}CloseFilteredSellPositions({args});')
        target=home/f'source/MQL5/Scripts/bot-cua-toi-{bot}/Bot{bot}PositionSelectionCheck.mq5';outputs.append((target,text))
    if any(p.exists() for p,_ in outputs):raise FileExistsError('POSITION_SELECTION_CHECK_ALREADY_EXISTS')
    for path,text in outputs:
        with path.open('x',encoding='utf-8',newline='') as f:f.write(text)
    print(json.dumps(dict(created=[str(p.relative_to(ROOT)) for p,_ in outputs])))

if __name__=='__main__':main()
