"""Generate complete spread/queue recorders with controlled SDK error replies."""
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
template=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1NewsFridaySpreadCheck.mq5').read_text()
template=template.replace('Bot1','BotN').replace('bot1','botN').replace('bot-cua-toi-1','bot-cua-toi-N')
template=template.replace('BotNNewsFridaySpreadFlow.mqh','BotNNewsFridaySpreadRestoreFlow.mqh')
template=template.replace('input string CheckRun="";','input string CheckRun="";\nint SourceError();void MockSleep(const int milliseconds);')
template=template.replace('#define MQLInfoInteger MockInfo','#define GetLastError SourceError\n#define Sleep MockSleep\n#define MQLInfoInteger MockInfo')
template=template.replace('#undef MQLInfoInteger','#undef GetLastError\n#undef Sleep\n#undef MQLInfoInteger')
template=template.replace('GetLastError()','SourceError()')
template=template.replace('double SpreadUnit,CurrentSpread;','double SpreadUnit,CurrentSpread;\nBotNPendingRestoreSettings Restore;long RestoreData[14],SyntheticError=-1;bool CastProofOk=true;int SendCalls=0,SleepCalls=0,RestorePrints=0;')
template=template.replace('   if(RecordFinal) Word((ulong)NewsBlocked);','''   Word(Bits(Restore.sl_distance));Word(Bits(Restore.tp_distance));Word((ulong)Restore.expiration_base);
   Word(Restore.virtual_expiration);Word(Queue.error_count);Text(Restore.comment);
   if(RecordFinal) Word((ulong)NewsBlocked);''')
needle='for(int row=0;row<100;row++) for(int col=0;col<2;col++) Queue.results[row][col]=FileReadDouble(file);'
template=template.replace(needle,needle+'''
      for(int i=0;i<14;i++) RestoreData[i]=FileReadLong(file);
      ZeroMemory(Restore);Restore.sl_distance=Number((ulong)RestoreData[0]);Restore.tp_distance=Number((ulong)RestoreData[1]);
      Restore.expiration_base=(datetime)RestoreData[2];Restore.virtual_expiration=(uchar)RestoreData[3];Queue.error_count=(uint)RestoreData[4];Restore.comment="restore";
      SyntheticError=-1;SendCalls=0;SleepCalls=0;RestorePrints=0;''')
template=template.replace('BotNProcessNewsFridayAndHighSpread(','BotNProcessNewsFridaySpreadRestore(').replace('FridayClosed,SpreadSettings,SpreadUnit,CurrentSpread,Queue);','FridayClosed,SpreadSettings,SpreadUnit,CurrentSpread,Queue,Restore);')
template=template.replace('botN-news-friday-spread','botN-news-friday-spread-restore').replace('HIGH_SPREAD_CASE','SPREAD_RESTORE_CASE')
marker='void MockPrint(const string value) { Begin();ServiceEffect(10,value);WideEffect(10,value);End(10,1,0,0,0,value); }'
assert marker in template
template=template.replace(marker,'''int SourceError() { return SyntheticError>=0 ? (int)SyntheticError : GetLastError(); }
void SetSdkError(const int error)
{
   if(error==0) { SyntheticError=-1;ResetLastError(); }
   else SyntheticError=error;
}
void RestoreEffect(const int api,const string text=NULL)
{
   const int mode=(int)RestoreData[5];bool first=false;
   if(api==10 && (text=="Restoring pending buy-order" || text=="Restoring pending sell-order"))
   { RestorePrints++;first=RestorePrints==1; }
   if((mode==1 && first) || (mode==2 && api==21 && SendCalls==1) || (mode==3 && api==33 && SleepCalls==1))
   {
      Restore.sl_distance=12.;Restore.tp_distance=7.;SpreadUnit=.5;Execution.strategy_magic=77;Restore.comment="updated";
      if(mode==3) { int row=(int)RestoreData[6];Queue.orders[row][0]=RestoreData[7]==4 ? 112. : 88.;Queue.orders[row][1]=(double)RestoreData[7];Queue.orders[row][2]=.5; }
   }
   if((mode==4 || mode==5) && api==21 && SendCalls==1) Queue.enabled=(uchar)(mode==4 ? 0 : 2);
   if(mode==6 && first) { int row=(int)RestoreData[6];Queue.orders[row][0]=90.;Queue.orders[row][1]=5.;Queue.orders[row][2]=.25; }
   if(mode==8 && first) Execution.threshold_a=1000.;
   if(mode==9 && api==33 && SleepCalls==1) SetSdkError(0);
}
void MockSleep(const int milliseconds) { Begin();SleepCalls++;RestoreEffect(33);End(33,(ulong)(long)milliseconds); }
void MockPrint(const string value) { Begin();ServiceEffect(10,value);WideEffect(10,value);RestoreEffect(10,value);End(10,1,0,0,0,value); }''')
template=template.replace('bool ok=P[p_accepted]!=0;End(21,0,(ulong)ok);return ok;','int index=SendCalls<3 ? SendCalls : 2;bool ok=RestoreData[8+index]!=0;SetSdkError((int)RestoreData[11+index]);SendCalls++;RestoreEffect(21);End(21,0,(ulong)ok);return ok;')
template=template.replace('bool ok=P[p_accepted]!=0;End(21,1,(ulong)ok);return ok;','int index=SendCalls<3 ? SendCalls : 2;bool ok=RestoreData[8+index]!=0;SetSdkError((int)RestoreData[11+index]);SendCalls++;RestoreEffect(21);End(21,1,(ulong)ok);return ok;')
template=template.replace('Begin();value=63;End(29,','Begin();value=(RestoreData[5]==7 && property==SYMBOL_ORDER_MODE) ? 0 : 63;if(RestoreData[5]==7 && property==SYMBOL_ORDER_MODE) SetSdkError(3);End(29,')
start=template.index('void DoubleCast(');end=template.index('int OnStart()',start)
template=template[:start]+'''void DoubleCast(const int file,const double value)
{
   ResetLastError();string text=(string)value;SetUserError(7);uint before=GetLastError();string second=(string)value;uint after=GetLastError();
   if(before!=after || text!=second) CastProofOk=false;WriteCast(file,0x58,Bits(value),0xffffffff,text);
}
void TicketCast(const int file,const ulong value)
{
   ResetLastError();string text=(string)value;SetUserError(7);uint before=GetLastError();string second=(string)value;uint after=GetLastError();
   if(before!=after || text!=second) CastProofOk=false;WriteCast(file,0x55,value,0xffffffff,text);
}
void SignedCast(const int file,const int value)
{
   ResetLastError();string text=(string)value;SetUserError(7);uint before=GetLastError();string second=(string)value;uint after=GetLastError();
   if(before!=after || text!=second) CastProofOk=false;WriteCast(file,0x52,(ulong)(uint)value,0xffffffff,text);
}
'''+template[end:]
template=template.replace('FileWriteInteger(casts,count*5);','FileWriteInteger(casts,count*9);')
needle='TicketCast(casts,(ulong)0x1122334455667788);'
template=template.replace(needle,needle+'SignedCast(casts,0);SignedCast(casts,3);SignedCast(casts,132);SignedCast(casts,999);if(!CastProofOk) return 9;')
api=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1NewsFridaySpreadAPICompile.mq5').read_text().replace('Bot1','BotN').replace('bot-cua-toi-1','bot-cua-toi-N').replace('BotNNewsFridaySpreadFlow.mqh','BotNNewsFridaySpreadRestoreFlow.mqh')
api=api.replace('BotNSpreadSettings spread_settings;','BotNPendingRestoreSettings restore;ZeroMemory(restore);\n   BotNSpreadSettings spread_settings;').replace('BotNProcessNewsFridayAndHighSpread(','BotNProcessNewsFridaySpreadRestore(').replace('unit,spread,queue);','unit,spread,queue,restore);')
for bot in [1,3]:
    script=template
    if bot==3:
        script=script.replace('Word(FridayClosed);','Word(FridayClosed);Word(Friday.delete_pending);Word(Friday.close_positions);')
        script=script.replace('FridayClosed=(uchar)FridayData[2];','FridayClosed=(uchar)FridayData[2];Friday.delete_pending=(uchar)FridayData[3];Friday.close_positions=(uchar)FridayData[4];')
        needle='if(mode==4 && api==10 && text=="Weekend starting! closing trades..") { FridayClosed=2;Mutated=true; }'
        script=script.replace(needle,needle+'\n   if(mode==5 && api==15 && !Mutated) { Friday.delete_pending=0;Mutated=true; }')
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    for suffix,source in [('Check',script),('APICompile',api)]:
        source=source.replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}')
        (folder/f'Bot{bot}NewsFridaySpreadRestore{suffix}.mq5').write_text('\n'.join(line.rstrip() for line in source.splitlines())+'\n',encoding='utf-8',newline='\n')
