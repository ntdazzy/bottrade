"""Extend the spread/restoration recorder through the pending-order limit stage."""
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
template=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1NewsFridaySpreadRestoreCheck.mq5').read_text()
template=template.replace('Bot1','BotN').replace('bot1','botN').replace('bot-cua-toi-1','bot-cua-toi-N')
template=template.replace('BotNNewsFridaySpreadRestoreFlow.mqh','BotNEvaluationNewsAndOrders.mqh')
template=template.replace('int SendCalls=0,SleepCalls=0,RestorePrints=0;','int SendCalls=0,SleepCalls=0,RestorePrints=0;\nint PendingEnabled=0,MaximumPending=0,TotalCalls=0;long LimitData[11];')
template=template.replace('   if(RecordFinal) Word((ulong)NewsBlocked);','   Word((ulong)(long)PendingEnabled);Word((ulong)(long)MaximumPending);\n   if(RecordFinal) Word((ulong)NewsBlocked);')
template=template.replace('for(int i=0;i<14;i++) RestoreData[i]=FileReadLong(file);','for(int i=0;i<14;i++) RestoreData[i]=FileReadLong(file);\n      for(int i=0;i<11;i++) LimitData[i]=FileReadLong(file);PendingEnabled=(int)LimitData[0];MaximumPending=(int)LimitData[1];TotalCalls=0;')
template=template.replace('BotNProcessNewsFridaySpreadRestore(','BotNEvaluateNewsAndPendingLimits(').replace('CurrentSpread,Queue,Restore);','CurrentSpread,Queue,Restore,PendingEnabled,MaximumPending);')
template=template.replace('botN-news-friday-spread-restore','botN-news-orders').replace('SPREAD_RESTORE_CASE','NEWS_ORDERS_CASE')
start=template.index('int MockOrders() { Begin();');end=template.index('\n',start)
template=template[:start]+'''void LimitEffect(const int api)
{
   const int mode=(int)LimitData[10];
   if(mode==1 && api==13 && TotalCalls==1) PendingEnabled=2;
   if(mode==2 && api==13 && TotalCalls==2) MaximumPending=2;
   if(mode==3 && api==18) MaximumPending=0;
   if(mode==4 && api==21 && SendCalls==1) PendingEnabled=0;
   if(mode==5 && api==14) MaximumPending=2;
}
int MockOrders() { Begin();int index=TotalCalls<8 ? TotalCalls : 7;int total=(int)LimitData[2+index];TotalCalls++;ServiceEffect(13);LimitEffect(13);End(13,(ulong)(long)total);return total; }'''+template[end:]
template=template.replace('PriceReads=0;End(14,','PriceReads=0;LimitEffect(14);End(14,')
template=template.replace('WideEffect(18);End(18,','WideEffect(18);LimitEffect(18);End(18,')
template=template.replace('RestoreEffect(21);End(21,','RestoreEffect(21);LimitEffect(21);End(21,')
template=template.replace('(OrderTypeReads++==0 ? FridayData[8] : FridayData[9]);ServiceEffect(17,','((LimitData[10]==4 && SendCalls>0) ? 5 : (OrderTypeReads++==0 ? FridayData[8] : FridayData[9]));ServiceEffect(17,')
api=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1NewsFridaySpreadRestoreAPICompile.mq5').read_text().replace('Bot1','BotN').replace('bot-cua-toi-1','bot-cua-toi-N').replace('BotNNewsFridaySpreadRestoreFlow.mqh','BotNEvaluationNewsAndOrders.mqh')
api=api.replace('BotNPendingRestoreSettings restore;','int pending_enabled=0,maximum_pending=0;\n   BotNPendingRestoreSettings restore;').replace('BotNProcessNewsFridaySpreadRestore(','BotNEvaluateNewsAndPendingLimits(').replace('unit,spread,queue,restore);','unit,spread,queue,restore,pending_enabled,maximum_pending);')
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
        (folder/f'Bot{bot}EvaluationNewsAndOrders{suffix}.mq5').write_text('\n'.join(line.rstrip() for line in source.splitlines())+'\n',encoding='utf-8',newline='\n')
