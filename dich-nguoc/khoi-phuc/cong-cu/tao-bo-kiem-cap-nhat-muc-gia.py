"""Generate entry-cache recorders with real price-level algorithms and SDK tapes."""
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
template=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1EvaluationNewsAndOrdersCheck.mq5').read_text()
template=template.replace('Bot1','BotN').replace('bot1','botN').replace('bot-cua-toi-1','bot-cua-toi-N')
template=template.replace('BotNEvaluationNewsAndOrders.mqh','BotNEvaluationEntryLevels.mqh')
template=template.replace('int SourceError();','datetime MockBarTime(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift);\ndouble MockHigh(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift);\ndouble MockLow(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift);\nint SourceError();',1)
template=template.replace('#define MQLInfoInteger MockInfo','#define iTime MockBarTime\n#define iHigh MockHigh\n#define iLow MockLow\n#define MQLInfoInteger MockInfo')
template=template.replace('#undef MQLInfoInteger','#undef iTime\n#undef iHigh\n#undef iLow\n#undef MQLInfoInteger')
template=template.replace('bool Mutated=false,RecordFinal=false,NewsBlocked=false;','bool Mutated=false,RecordFinal=false;BotNEntryLevelDecision Decision=BOTN_LEVEL_STOP;')
template=template.replace('long LimitData[11];','long LimitData[11],LevelData[14],BarTimes[100];BotNLevelCacheSettings LevelSettings;uint CallerIndex=0,CurrentIndex=0;\ndouble CachedUpper[100],CachedLower[100],HighValues[16],LowValues[16];int TimeCalls=0,HighCalls=0,LowCalls=0,DigitCalls=0;')
template=template.replace('   if(RecordFinal) Word((ulong)NewsBlocked);','''   Word(LevelSettings.blocked);Word((ulong)(long)LevelSettings.timeframe);Word((ulong)(long)LevelSettings.aux_timeframe);
   Word((ulong)(long)LevelSettings.aux_older);Word((ulong)(long)LevelSettings.aux_recent);Word((ulong)(long)LevelSettings.last_shift);Word(Bits(LevelSettings.aux_offset));
   Word(CallerIndex);Word(CurrentIndex);
   for(int i=0;i<100;i++) Word((ulong)BarTimes[i]);
   for(int i=0;i<100;i++) Word(Bits(CachedUpper[i]));
   for(int i=0;i<100;i++) Word(Bits(CachedLower[i]));
   if(RecordFinal) Word((ulong)Decision);''')
needle='PendingEnabled=(int)LimitData[0];MaximumPending=(int)LimitData[1];TotalCalls=0;'
assert needle in template
template=template.replace(needle,needle+'''
      for(int i=0;i<14;i++) LevelData[i]=FileReadLong(file);ZeroMemory(LevelSettings);
      LevelSettings.blocked=(uchar)LevelData[0];LevelSettings.timeframe=(ENUM_TIMEFRAMES)LevelData[1];LevelSettings.aux_timeframe=(ENUM_TIMEFRAMES)LevelData[2];
      LevelSettings.aux_older=(int)LevelData[3];LevelSettings.aux_recent=(int)LevelData[4];LevelSettings.last_shift=(int)LevelData[5];LevelSettings.aux_offset=Number((ulong)LevelData[6]);
      CallerIndex=(uint)LevelData[7];CurrentIndex=(uint)LevelData[8];TimeCalls=0;HighCalls=0;LowCalls=0;DigitCalls=0;
      for(int i=0;i<100;i++) BarTimes[i]=FileReadLong(file);
      for(int i=0;i<100;i++) CachedUpper[i]=FileReadDouble(file);
      for(int i=0;i<100;i++) CachedLower[i]=FileReadDouble(file);
      for(int i=0;i<16;i++) HighValues[i]=FileReadDouble(file);
      for(int i=0;i<16;i++) LowValues[i]=FileReadDouble(file);''')
template=template.replace('Execution.threshold_a=1.;','Execution.threshold_a=Number((ulong)LevelData[13]);')
template=template.replace('NewsBlocked=BotNEvaluateNewsAndPendingLimits(','Decision=BotNEvaluateThroughEntryLevels(').replace('Queue,Restore,PendingEnabled,MaximumPending);','Queue,Restore,PendingEnabled,MaximumPending,LevelSettings,CallerIndex,CurrentIndex,BarTimes,CachedUpper,CachedLower);')
template=template.replace('botN-news-orders','botN-entry-level-cache').replace('NEWS_ORDERS_CASE','ENTRY_LEVEL_CASE')
marker='int OnStart()'
functions='''void EntryEffect(const int api,const long property=-1)
{
   const int mode=(int)LevelData[12];
   if(api==35)
   {
      if(mode==1 && TimeCalls==1) BarTimes[CallerIndex]=LevelData[10];
      if(mode==2 && TimeCalls==1) { LevelSettings.timeframe=PERIOD_M30;Execution.symbol="OTHER"; }
      if(mode==8 && TimeCalls==1) LevelSettings.aux_older=0;
   }
   if(api==36 && HighCalls==1)
   {
      if(mode==3) CurrentIndex=3;
      if(mode==4) { LevelSettings.last_shift=1;Execution.reference_b=999.; }
      if(mode==10) Execution.symbol="OTHER";
   }
   if(api==37 && LowCalls==1 && mode==5) { Execution.reference_a=-999.;Execution.threshold_a=2.; }
   if(api==26 && property==17)
   {
      DigitCalls++;
      if(mode==6) { CurrentIndex=DigitCalls==1 ? 4 : 5;LevelSettings.aux_offset=7.;SpreadUnit=2.;CurrentSpread=3.; }
      if(mode==7) { HighValues[2]=123.456789;LowValues[2]=78.123456; }
   }
   if(api==36 && DigitCalls>0 && mode==9) { LevelSettings.aux_timeframe=PERIOD_M30;LevelSettings.aux_older=1;LevelSettings.aux_recent=0; }
}
datetime MockBarTime(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   Begin();datetime value=(datetime)LevelData[TimeCalls==0 ? 10 : 11];TimeCalls++;
   End(35,(ulong)(long)timeframe,(ulong)(long)shift,(ulong)value,0,symbol);EntryEffect(35);return value;
}
double MockHigh(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   Begin();double value=shift>=0 && shift<16 ? HighValues[shift] : 0.;HighCalls++;
   End(36,(ulong)(long)timeframe,(ulong)(long)shift,Bits(value),0,symbol);EntryEffect(36);return value;
}
double MockLow(const string symbol,const ENUM_TIMEFRAMES timeframe,const int shift)
{
   Begin();double value=shift>=0 && shift<16 ? LowValues[shift] : 0.;LowCalls++;
   End(37,(ulong)(long)timeframe,(ulong)(long)shift,Bits(value),0,symbol);EntryEffect(37);return value;
}
'''
# Forward declaration: the existing SDK wrapper precedes the new callback bodies.
template=template.replace('int SourceError();','void EntryEffect(const int api,const long property=-1);\nint SourceError();',1)
template=template.replace(marker,functions.replace('const long property=-1','const long property')+marker)
template=template.replace('long value=property==SYMBOL_TRADE_FREEZE_LEVEL ? 5 : (property==SYMBOL_FILLING_MODE ? 3 : 0);End(26,','long value=property==SYMBOL_DIGITS ? LevelData[9] : (property==SYMBOL_TRADE_FREEZE_LEVEL ? 5 : (property==SYMBOL_FILLING_MODE ? 3 : 0));EntryEffect(26,(long)property);End(26,')
api=(ROOT/'bot-cua-toi-1/source/MQL5/Scripts/bot-cua-toi-1/Bot1EvaluationNewsAndOrdersAPICompile.mq5').read_text().replace('Bot1','BotN').replace('bot-cua-toi-1','bot-cua-toi-N').replace('BotNEvaluationNewsAndOrders.mqh','BotNEvaluationEntryLevels.mqh')
api=api.replace('int pending_enabled=0,maximum_pending=0;','BotNLevelCacheSettings level_settings;ZeroMemory(level_settings);uint caller_index=0,current_index=0;long bar_times[100];double upper[100],lower[100];\n   ArrayInitialize(bar_times,0);ArrayInitialize(upper,0);ArrayInitialize(lower,0);\n   int pending_enabled=0,maximum_pending=0;').replace('BotNEvaluateNewsAndPendingLimits(','BotNEvaluateThroughEntryLevels(').replace('pending_enabled,maximum_pending);','pending_enabled,maximum_pending,level_settings,caller_index,current_index,bar_times,upper,lower);')
for bot in [1,3]:
    script=template
    if bot==3:
        script=script.replace('Word(FridayClosed);','Word(FridayClosed);Word(Friday.delete_pending);Word(Friday.close_positions);')
        script=script.replace('FridayClosed=(uchar)FridayData[2];','FridayClosed=(uchar)FridayData[2];Friday.delete_pending=(uchar)FridayData[3];Friday.close_positions=(uchar)FridayData[4];')
        needle='if(mode==4 && api==10 && text=="Weekend starting! closing trades..") { FridayClosed=2;Mutated=true; }'
        script=script.replace(needle,needle+'\n   if(mode==5 && api==15 && !Mutated) { Friday.delete_pending=0;Mutated=true; }')
    folder=ROOT/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    for suffix,source in [('Check',script),('APICompile',api)]:
        source=source.replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('BOTN',f'BOT{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}')
        (folder/f'Bot{bot}EvaluationEntryLevels{suffix}.mq5').write_text('\n'.join(line.rstrip() for line in source.splitlines())+'\n',encoding='utf-8',newline='\n')
