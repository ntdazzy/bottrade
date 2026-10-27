"""Extend the tested news recorder for Friday settings, state and service effects."""
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
template=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1NewsPipelineCheck.mq5').read_text()
template=template.replace('Bot1','BotN').replace('bot1','botN').replace('bot-cua-toi-1','bot-cua-toi-N')
template=template.replace('BotNNewsFilterPipeline.mqh','BotNNewsFridayFlow.mqh')
template=template.replace('long Extra[18];bool RecordFinal=false,NewsBlocked=false;','long Extra[18],FridayData[12];BotNFridaySettings Friday;uchar FridayClosed;\nbool Mutated=false,RecordFinal=false,NewsBlocked=false;int OrderTypeReads=0;')
template=template.replace('   if(RecordFinal) Word((ulong)NewsBlocked);','   FRIDAY_SNAPSHOT\n   if(RecordFinal) Word((ulong)NewsBlocked);')
template=template.replace('for(int i=0;i<18;i++) Extra[i]=FileReadLong(file);','for(int i=0;i<18;i++) Extra[i]=FileReadLong(file);\n      for(int i=0;i<12;i++) FridayData[i]=FileReadLong(file);\n      ZeroMemory(Friday);Friday.enabled=(uchar)FridayData[0];Friday.hour=(int)FridayData[1];FridayClosed=(uchar)FridayData[2];FRIDAY_FLAGS\n      Mutated=false;OrderTypeReads=0;')
template=template.replace('Execution.magic_base=42;','Execution.magic_base=(int)FridayData[5];')
template=template.replace('BotNProcessNewsFilters(Settings,State,InterestSettings,InterestState,CpiSettings,CpiState,Events,Cached,History,History,History,Execution,Selection);','BotNProcessNewsAndFriday(Settings,State,InterestSettings,InterestState,CpiSettings,CpiState,Events,Cached,History,History,History,Execution,Selection,Friday,FridayClosed);')
template=template.replace('botN-news-pipeline','botN-news-friday').replace('NEWS_PIPELINE_CASE','NEWS_FRIDAY_CASE')
marker='void MockPrint(const string value) { Begin();End(10,1,0,0,0,value); }'
assert marker in template
template=template.replace(marker,'''void ServiceEffect(const int api,const string text=NULL,const long property=-1)
{
   const int mode=(int)FridayData[10];
   if(((mode==1 && api==13) || (mode==2 && api==17 && property==15)) && !Mutated)
   { Execution.magic_base=(int)FridayData[11];Mutated=true; }
   if(mode==3 && api==10 && text=="deleting pending order") { Execution.last_ticket=999;Mutated=true; }
   if(mode==4 && api==10 && text=="Weekend starting! closing trades..") { FridayClosed=2;Mutated=true; }
   FRIDAY_EFFECT
}
void MockPrint(const string value) { Begin();ServiceEffect(10,value);End(10,1,0,0,0,value); }''')
template=template.replace('int MockOrders() { Begin();int total=P[p_orders]!=0 ? 1 : 0;End(13,(ulong)total);return total; }','int MockOrders() { Begin();int total=P[p_orders]<0 ? -1 : (P[p_orders]!=0 ? 1 : 0);ServiceEffect(13);End(13,(ulong)(long)total);return total; }')
template=template.replace('int MockPositions() { Begin();int total=P[p_position]!=0 ? 1 : 0;End(15,(ulong)total);return total; }','int MockPositions() { Begin();int total=P[p_position]<0 ? -1 : (P[p_position]!=0 ? 1 : 0);ServiceEffect(15);End(15,(ulong)(long)total);return total; }')
template=template.replace('ulong value=P[p_orders]!=0 && index==0 ? 11 : 0;End(14,','ulong value=P[p_orders]!=0 && index==0 ? 11 : 0;OrderTypeReads=0;End(14,')
template=template.replace('long value=property==ORDER_MAGIC ? 42 : (P[p_orders]==2 ? 5 : 4);End(17,','long value=property==ORDER_MAGIC ? FridayData[6] : (OrderTypeReads++==0 ? FridayData[8] : FridayData[9]);ServiceEffect(17,NULL,(long)property);End(17,')
template=template.replace('string value="XAUUSD";End(18,','string value=FridayData[7]==1 ? "xauusd" : (FridayData[7]==2 ? "OTHER" : "XAUUSD");End(18,')
api=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1NewsPipelineAPICompile.mq5').read_text().replace('Bot1','BotN').replace('bot-cua-toi-1','bot-cua-toi-N').replace('BotNNewsFilterPipeline.mqh','BotNNewsFridayFlow.mqh')
api=api.replace('long nfp_history[300]','BotNFridaySettings friday;uchar friday_closed=0;ZeroMemory(friday);\n   long nfp_history[300]').replace('BotNProcessNewsFilters(','BotNProcessNewsAndFriday(').replace('execution,selection);','execution,selection,friday,friday_closed);')
for bot in [1,3]:
    snapshot='Word(Friday.enabled);Word((ulong)(long)Friday.hour);Word(FridayClosed);'
    flags='';effect=''
    if bot==3:
        snapshot+='Word(Friday.delete_pending);Word(Friday.close_positions);'
        flags='Friday.delete_pending=(uchar)FridayData[3];Friday.close_positions=(uchar)FridayData[4];'
        effect='if(mode==5 && api==15 && !Mutated) { Friday.delete_pending=0;Mutated=true; }'
    script=template.replace('FRIDAY_SNAPSHOT',snapshot).replace('FRIDAY_FLAGS',flags).replace('FRIDAY_EFFECT',effect)
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    for suffix,source in [('Check',script),('APICompile',api)]:
        source=source.replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}')
        (folder/f'Bot{bot}NewsFriday{suffix}.mq5').write_text('\n'.join(line.rstrip() for line in source.splitlines())+'\n',encoding='utf-8',newline='\n')
