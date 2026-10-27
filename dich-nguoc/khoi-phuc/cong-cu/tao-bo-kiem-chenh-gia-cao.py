"""Generate SDK recorders for news, Friday and high-spread storage."""
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
template=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1NewsFridayCheck.mq5').read_text()
template=template.replace('Bot1','BotN').replace('bot1','botN').replace('bot-cua-toi-1','bot-cua-toi-N')
template=template.replace('BotNNewsFridayFlow.mqh','BotNNewsFridaySpreadFlow.mqh')
template=template.replace('int OrderTypeReads=0;','int OrderTypeReads=0,MagicReads=0,PriceReads=0;long WideData[21];\nBotNSpreadSettings SpreadSettings;BotNPendingQueue Queue;double SpreadUnit,CurrentSpread;')
template=template.replace('   if(RecordFinal) Word((ulong)NewsBlocked);','''   Word(SpreadSettings.enabled);Word((ulong)(long)SpreadSettings.distance_points);Word(Queue.enabled);
   Word(Bits(SpreadSettings.maximum));Word(Bits(SpreadSettings.minimum));Word(Bits(SpreadUnit));Word(Bits(CurrentSpread));
   for(int row=0;row<100;row++) for(int col=0;col<3;col++) Word(Bits(Queue.orders[row][col]));
   for(int row=0;row<100;row++) for(int col=0;col<2;col++) Word(Bits(Queue.results[row][col]));
   if(RecordFinal) Word((ulong)NewsBlocked);''')
template=template.replace('for(int i=0;i<12;i++) FridayData[i]=FileReadLong(file);','''for(int i=0;i<12;i++) FridayData[i]=FileReadLong(file);
      for(int i=0;i<21;i++) WideData[i]=FileReadLong(file);
      ZeroMemory(SpreadSettings);ZeroMemory(Queue);SpreadSettings.enabled=(uchar)WideData[0];SpreadSettings.distance_points=(int)WideData[1];Queue.enabled=(uchar)WideData[2];
      SpreadSettings.maximum=Number((ulong)WideData[3]);SpreadSettings.minimum=Number((ulong)WideData[4]);SpreadUnit=Number((ulong)WideData[5]);CurrentSpread=Number((ulong)WideData[6]);
      for(int row=0;row<100;row++) for(int col=0;col<3;col++) Queue.orders[row][col]=FileReadDouble(file);
      for(int row=0;row<100;row++) for(int col=0;col<2;col++) Queue.results[row][col]=FileReadDouble(file);''')
template=template.replace('Mutated=false;OrderTypeReads=0;','Mutated=false;OrderTypeReads=0;MagicReads=0;PriceReads=0;')
template=template.replace('Execution.reference_a=100.;Execution.reference_b=101.;','Execution.reference_a=Number((ulong)WideData[8]);Execution.reference_b=Number((ulong)WideData[7]);')
template=template.replace('Execution.gap=1.;','Execution.gap=Number((ulong)WideData[9]);')
template=template.replace('BotNProcessNewsAndFriday(Settings,State,InterestSettings,InterestState,CpiSettings,CpiState,Events,Cached,History,History,History,Execution,Selection,Friday,FridayClosed);','BotNProcessNewsFridayAndHighSpread(Settings,State,InterestSettings,InterestState,CpiSettings,CpiState,Events,Cached,History,History,History,Execution,Selection,Friday,FridayClosed,SpreadSettings,SpreadUnit,CurrentSpread,Queue);')
template=template.replace('botN-news-friday','botN-news-friday-spread').replace('NEWS_FRIDAY_CASE','HIGH_SPREAD_CASE')
template=template.replace('void MockPrint(const string value) { Begin();ServiceEffect(10,value);End(10,1,0,0,0,value); }','''void WideEffect(const int api,const string text=NULL,const long property=-1)
{
   const int mode=(int)WideData[11];
   if(api==19 && property==9)
   {
      PriceReads++;
      if(mode==1 && PriceReads==1) Execution.reference_b=105.;
      if(mode==2 && PriceReads==2) Execution.reference_b=1000.;
   }
   if(mode==3 && api==10 && StringFind(text,"Spread too high..(")==0) Queue.enabled=0;
   if(mode==4 && api==10 && StringFind(text,"Storing pending order nr ")==0) Execution.last_ticket=999;
   if(mode==5 && api==19 && property==7) { Queue.results[0][0]=(double)(long)Execution.last_ticket;Queue.results[0][1]=3.; }
   if(mode==6 && api==17 && property==15 && MagicReads==1) Execution.strategy_magic=43;
   if(mode==7 && api==10 && StringFind(text,"Spread too high..(")==0) SpreadSettings.minimum=-1.;
   if(mode==8 && api==18) Execution.symbol="OTHER";
}
void MockPrint(const string value) { Begin();ServiceEffect(10,value);WideEffect(10,value);End(10,1,0,0,0,value); }''')
template=template.replace('ulong value=P[p_orders]!=0 && index==0 ? 11 : 0;OrderTypeReads=0;','ulong value=P[p_orders]!=0 && index==0 ? (ulong)WideData[13] : 0;OrderTypeReads=0;MagicReads=0;PriceReads=0;')
template=template.replace('property==ORDER_MAGIC ? FridayData[6] :','property==ORDER_MAGIC ? (MagicReads++==0 ? FridayData[6] : WideData[12]) :')
template=template.replace('ServiceEffect(17,NULL,(long)property);End(17,','ServiceEffect(17,NULL,(long)property);WideEffect(17,NULL,(long)property);End(17,')
template=template.replace('End(18,(ulong)property,','WideEffect(18);End(18,(ulong)property,')
template=template.replace('double value=P[p_orders]==2 ? 90. : 110.;End(19,','double value=property==ORDER_PRICE_OPEN ? Number((ulong)WideData[14+(PriceReads<6 ? PriceReads : 5)]) : Number((ulong)WideData[20]);WideEffect(19,NULL,(long)property);End(19,')
marker='int OnStart()'
formats='''double Number(const ulong bits) { NumberBits value;value.bits=bits;return value.value; }
void WriteCast(const int file,const int kind,const ulong bits,const uint error,const string text)
{
   FileWriteInteger(file,kind);FileWriteLong(file,(long)bits);FileWriteInteger(file,(int)error);
   int length=StringLen(text);FileWriteInteger(file,length);if(length>0) FileWriteString(file,text,length);
}
void DoubleCast(const int file,const double value)
{ ResetLastError();string text=(string)value;uint error=GetLastError();WriteCast(file,0x58,Bits(value),error,text); }
void TicketCast(const int file,const ulong value)
{ ResetLastError();string text=(string)value;uint error=GetLastError();WriteCast(file,0x55,value,error,text); }
'''
template=template.replace(marker,formats+marker)
template=template.replace('if(output==INVALID_HANDLE || tapes==INVALID_HANDLE)', 'int casts=FileOpen(folder+"cast-values.bin",FILE_WRITE|FILE_BIN);if(casts==INVALID_HANDLE) return 8;\n   FileWriteInteger(casts,magic);FileWriteInteger(casts,version);FileWriteInteger(casts,count*5);\n   if(output==INVALID_HANDLE || tapes==INVALID_HANDLE)')
template=template.replace('string name=folder+"tape-"','DoubleCast(casts,CurrentSpread);DoubleCast(casts,Execution.reference_b-Execution.reference_a);TicketCast(casts,(ulong)WideData[13]);TicketCast(casts,999);TicketCast(casts,(ulong)0x1122334455667788);\n      string name=folder+"tape-"')
template=template.replace('FileClose(file);FileClose(output);FileClose(tapes);int status=', 'FileClose(file);FileClose(output);FileClose(tapes);FileClose(casts);int status=')
api=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1NewsFridayAPICompile.mq5').read_text().replace('Bot1','BotN').replace('bot-cua-toi-1','bot-cua-toi-N').replace('BotNNewsFridayFlow.mqh','BotNNewsFridaySpreadFlow.mqh')
api=api.replace('BotNFridaySettings friday;','BotNSpreadSettings spread_settings;BotNPendingQueue queue;double unit=0,spread=0;ZeroMemory(spread_settings);ZeroMemory(queue);\n   BotNFridaySettings friday;').replace('BotNProcessNewsAndFriday(','BotNProcessNewsFridayAndHighSpread(').replace('selection,friday,friday_closed);','selection,friday,friday_closed,spread_settings,unit,spread,queue);')
for bot in [1,3]:
    script=template
    if bot==3:
        script=script.replace('Word(FridayClosed);','Word(FridayClosed);Word(Friday.delete_pending);Word(Friday.close_positions);')
        script=script.replace('FridayClosed=(uchar)FridayData[2];','FridayClosed=(uchar)FridayData[2];Friday.delete_pending=(uchar)FridayData[3];Friday.close_positions=(uchar)FridayData[4];')
        # Bot1's empty line was stripped by its generator; insert the Bot3 flag effect explicitly.
        needle='if(mode==4 && api==10 && text=="Weekend starting! closing trades..") { FridayClosed=2;Mutated=true; }'
        script=script.replace(needle,needle+'\n   if(mode==5 && api==15 && !Mutated) { Friday.delete_pending=0;Mutated=true; }')
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    for suffix,source in [('Check',script),('APICompile',api)]:
        source=source.replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}')
        (folder/f'Bot{bot}NewsFridaySpread{suffix}.mq5').write_text('\n'.join(line.rstrip() for line in source.splitlines())+'\n',encoding='utf-8',newline='\n')
