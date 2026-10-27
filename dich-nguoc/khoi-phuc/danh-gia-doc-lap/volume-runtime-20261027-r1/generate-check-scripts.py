"""Generate the two volume check scripts from their existing field declarations."""
from pathlib import Path
import importlib.util,re
R=Path(__file__).resolve().parents[2]
s=importlib.util.spec_from_file_location('volume_fields',R/'cong-cu/kiem-khoi-luong-bot-1-3.py');v=importlib.util.module_from_spec(s);s.loader.exec_module(v)
TEMPLATE=r'''#property strict
input string CheckRun="";
input int OnlyCase=-1;
#include "../../Include/bot-cua-toi-N/BotNVolume.mqh"
union DoubleBits { double value;ulong bits; };
ulong Bits(const double value) { DoubleBits u;u.value=value;return u.bits; }
string ReadText(const int h) { int n=FileReadInteger(h);return n>0 ? FileReadString(h,n) : ""; }
void WriteText(const int h,const string value)
{ int n=StringLen(value);FileWriteInteger(h,n);if(n>0) FileWriteString(h,value,n); }
BotNVolumeSettings r;BotNVolumeContext c;BotNVolumeState s;
uint strategy_index;double volumes[ARRAY_COUNT];uchar strategy_enabled[5];
long last_check,last_deal,times[3];string symbol,suffix,peak_key,time_key,currencies[];
bool enabled,select_ok,restore_ok;int tester,reported,mutate_after,mutate_index;
double prices[8],replies26[],replies34[],replies35[],replies36[];
ulong tickets[];long deal_types[],deal_times[];double profits[];
int counters26,counters34,counters35,counters36,symbol_calls,currency_calls,price_calls,clock_calls,select_calls;
int output,event_count;
void State()
{
STATE_WRITES
   FileWriteLong(output,last_check);FileWriteLong(output,last_deal);FileWriteLong(output,(long)strategy_index);
   for(int i=0;i<ARRAY_COUNT;i++) FileWriteLong(output,(long)Bits(volumes[i]));
}
void Event(const int api,const ulong first=0,const ulong second=0,const ulong value=0,const string text1="",const string text2="")
{
   FileWriteInteger(output,api);FileWriteLong(output,(long)first);FileWriteLong(output,(long)second);FileWriteLong(output,(long)value);
   WriteText(output,text1);WriteText(output,text2);State();event_count++;FileFlush(output);
}
double MockAccount(const ENUM_ACCOUNT_INFO_DOUBLE prop)
{ double value=prop==ACCOUNT_BALANCE ? c.balance : c.equity;Event(1,(ulong)prop,0,Bits(value));return value; }
double Reply(double &values[],int &count)
{ double value=values[MathMin(count,ArraySize(values)-1)];count++;return value; }
double MockSymbol(const string name,const ENUM_SYMBOL_INFO_DOUBLE prop)
{
   double value=0.0;
   if((int)prop==26) value=Reply(replies26,counters26);
   else if((int)prop==34) value=Reply(replies34,counters34);
   else if((int)prop==35) value=Reply(replies35,counters35);
   else if((int)prop==36) value=Reply(replies36,counters36);
   Event(2,(ulong)prop,0,Bits(value),name);symbol_calls++;
   if(mutate_after!=0 && symbol_calls==mutate_after) strategy_index=(uint)mutate_index;
   return value;
}
int MockMql(const ENUM_MQL_INFO_INTEGER prop) { Event(3,(ulong)prop,0,(ulong)(long)tester);return tester; }
datetime MockTime()
{ long value=times[MathMin(clock_calls,2)];clock_calls++;Event(4,0,0,(ulong)value);return (datetime)value; }
bool MockSelect(const datetime from,const datetime to)
{ bool value=select_calls==0 ? select_ok : restore_ok;select_calls++;Event(5,(ulong)from,(ulong)to,(ulong)value);return value; }
int MockTotal() { Event(6,0,0,(ulong)(long)reported);return reported; }
ulong MockTicket(const int index)
{ ulong value=index>=0 && index<ArraySize(tickets) ? tickets[index] : 0;Event(7,(ulong)index,0,value);return value; }
int Find(const ulong ticket) { for(int i=0;i<ArraySize(tickets);i++) if(tickets[i]==ticket) return i;return -1; }
long MockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop)
{ int i=Find(ticket);long value=i<0 ? 0 : (prop==DEAL_TYPE ? deal_types[i] : deal_times[i]);Event(8,ticket,(ulong)prop,(ulong)value);return value; }
double MockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop)
{ int i=Find(ticket);double value=i<0 ? 0.0 : profits[i];Event(9,ticket,(ulong)prop,Bits(value));return value; }
datetime MockSet(const string name,const double value) { Event(10,0,0,Bits(value),name);return 0; }
string MockCurrency(const ENUM_ACCOUNT_INFO_STRING prop)
{ string value=currencies[MathMin(currency_calls,ArraySize(currencies)-1)];currency_calls++;Event(11,(ulong)prop,0,0,value);return value; }
double MockClose(const string name,const ENUM_TIMEFRAMES tf,const int shift)
{ double value=prices[MathMin(price_calls,7)];price_calls++;Event(12,(ulong)tf,(ulong)shift,Bits(value),name);return value; }
void MockPrint(const string msg) { Event(13,2,1,0,msg); }
void MockPrint(const string msg,const double value) { Event(13,2,2,Bits(value),msg); }
void MockPrint(const string a,const string b,const string d,const string e,const string f,const string g)
{ Event(13,2,6,0,a+b+d+e+f+g); }
void MockAlert(const string msg) { Event(13,3,1,0,msg); }
string MockFixed(const double value,const int digits)
{ string reply=DoubleToString(value,digits);Event(15,Bits(value),(ulong)digits,0,reply);return reply; }
string BotNVolumeNumber(const double value)
{ string reply=(string)value;Event(14,Bits(value),0x58,0,reply);return reply; }
#define BOTN_VOLUME_NUMBER_EXTERNAL
#define AccountInfoDouble MockAccount
#define SymbolInfoDouble MockSymbol
#define MQLInfoInteger MockMql
#define TimeCurrent MockTime
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define HistoryDealGetInteger MockInteger
#define HistoryDealGetDouble MockDouble
#define GlobalVariableSet MockSet
#define AccountInfoString MockCurrency
#define iClose MockClose
#define Print MockPrint
#define Alert MockAlert
#define DoubleToString MockFixed
#include "../../Include/bot-cua-toi-N/BotNVolumeRuntime.mqh"
#undef Print
#undef DoubleToString
void ReadValues(const int h,double &values[])
{ int total=FileReadInteger(h);ArrayResize(values,total);for(int i=0;i<total;i++) values[i]=FileReadDouble(h); }
void ReadCase(const int h)
{
   ZeroMemory(r);ZeroMemory(c);ZeroMemory(s);
FIELD_READS
   enabled=FileReadInteger(h)!=0;tester=FileReadInteger(h);select_ok=FileReadInteger(h)!=0;restore_ok=FileReadInteger(h)!=0;reported=FileReadInteger(h);
   last_check=FileReadLong(h);last_deal=FileReadLong(h);for(int i=0;i<3;i++) times[i]=FileReadLong(h);
   symbol=ReadText(h);suffix=ReadText(h);peak_key=ReadText(h);time_key=ReadText(h);
   int total=FileReadInteger(h);ArrayResize(currencies,total);for(int i=0;i<total;i++) currencies[i]=ReadText(h);
   for(int i=0;i<8;i++) prices[i]=FileReadDouble(h);
   strategy_index=(uint)FileReadInteger(h);mutate_after=FileReadInteger(h);mutate_index=FileReadInteger(h);
   for(int i=0;i<ARRAY_COUNT;i++) volumes[i]=FileReadDouble(h);
   ReadValues(h,replies26);ReadValues(h,replies34);ReadValues(h,replies35);ReadValues(h,replies36);
   total=FileReadInteger(h);ArrayResize(tickets,total);ArrayResize(deal_types,total);ArrayResize(deal_times,total);ArrayResize(profits,total);
   for(int i=0;i<total;i++) { tickets[i]=(ulong)FileReadLong(h);deal_types[i]=FileReadLong(h);deal_times[i]=FileReadLong(h);profits[i]=FileReadDouble(h); }
   for(int i=0;i<5;i++) strategy_enabled[i]=(uchar)((c.enabled_mask>>i)&1);
   counters26=counters34=counters35=counters36=symbol_calls=currency_calls=price_calls=clock_calls=select_calls=event_count=0;
}
void Measure(const int h,const double value,const bool fixed)
{ FileWriteLong(h,(long)Bits(value));WriteText(h,fixed ? DoubleToString(value,2) : (string)value); }
int OnStart()
{
   if(CheckRun=="") return 1;
   string folder="botN-volume-runtime\\"+CheckRun+"\\";
   int input=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(input==INVALID_HANDLE) return 2;
   int magic=FileReadInteger(input),version=FileReadInteger(input),bot=FileReadInteger(input),count=FileReadInteger(input);
   if(magic!=0x56525431 || version!=1 || bot!=N || count<1) { FileClose(input);return 3; }
   int cast=FileOpen(folder+"cast-results.bin",FILE_WRITE|FILE_BIN),fixed=FileOpen(folder+"fixed-results.bin",FILE_WRITE|FILE_BIN);
   if(cast==INVALID_HANDLE || fixed==INVALID_HANDLE) { FileClose(input);return 4; }
   FileWriteInteger(cast,magic);FileWriteInteger(cast,version);FileWriteInteger(cast,0);
   FileWriteInteger(fixed,magic);FileWriteInteger(fixed,version);FileWriteInteger(fixed,0);
   int normal=0,cast_count=0,fixed_count=0;
   for(int i=0;i<count;i++)
   {
      FileReadInteger(input);int fatal=FileReadInteger(input);ReadCase(input);if(fatal==0) normal++;
      for(int j=0;j<ArraySize(replies34);j++) { Measure(cast,replies34[j],false);cast_count++; }
      for(int j=0;j<ArraySize(replies35);j++) { Measure(cast,replies35[j],false);cast_count++; }
      Measure(fixed,c.balance,true);Measure(fixed,c.equity,true);Measure(fixed,s.highest_balance,true);fixed_count+=3;
      double withdrawn=0.0;
      for(int j=0;j<ArraySize(tickets);j++)
         if(tickets[j]!=0 && (int)deal_types[j]==2 && deal_times[j]>last_deal && profits[j]<0.0) withdrawn+=profits[j];
      Measure(fixed,-withdrawn,true);fixed_count++;
   }
   FileSeek(cast,8,SEEK_SET);FileWriteInteger(cast,cast_count);FileClose(cast);
   FileSeek(fixed,8,SEEK_SET);FileWriteInteger(fixed,fixed_count);FileClose(fixed);
   FileSeek(input,16,SEEK_SET);output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);
   if(output==INVALID_HANDLE) { FileClose(input);return 5; }
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,normal);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(input),fatal=FileReadInteger(input);ReadCase(input);
      if(OnlyCase<0 ? fatal!=0 : id!=OnlyCase) continue;
      Print("VOLUME_RUNTIME_CASE:",id);
      ulong start=FileTell(output);FileWriteInteger(output,id);FileWriteInteger(output,0);FileWriteInteger(output,0);FileFlush(output);
      CALL_RUNTIME
      ulong end=FileTell(output);State();ulong next=FileTell(output);
      FileSeek(output,(long)start+4,SEEK_SET);FileWriteInteger(output,event_count);FileWriteInteger(output,(int)(end-start-12));FileSeek(output,(long)next,SEEK_SET);
   }
   FileClose(output);FileClose(input);
   int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE) return 6;
   FileWriteInteger(status,0);FileWriteInteger(status,normal);FileClose(status);return 0;
}
'''
for bot in [1,3]:
    field_reads=[]
    for n,k,_ in v.fields(v.INPUTS,bot):
        method='FileReadDouble' if k=='d' else 'FileReadInteger';suffix='!=0' if k=='B' else '';cast='(uint)' if k=='I' else ''
        field_reads.append(f'   {n}={cast}{method}(h){suffix};')
    for n,k in v.CONTEXT:field_reads.append(f'   c.{n}='+('(uint)' if k=='I' else '')+('FileReadDouble' if k=='d' else 'FileReadInteger')+'(h);')
    state=[]
    for n,k,_ in v.fields(v.OUTPUTS,bot):
        if n=='volume':continue
        value=f'Bits(s.{n})' if k=='d' else f's.{n}'
        state.append(f'   FileWriteLong(output,(long){value});')
    extra='c.weight_denominator,strategy_enabled,' if bot==3 else ''
    call=f'Bot{bot}PrepareVolumeRuntime(c.stop_distance,c.multiplier,symbol,suffix,r,s,enabled,peak_key,time_key,last_check,last_deal,{extra}strategy_index,volumes);'
    source=TEMPLATE.replace('FIELD_READS','\n'.join(field_reads)).replace('STATE_WRITES','\n'.join(state)).replace('CALL_RUNTIME',call).replace('ARRAY_COUNT',str(8 if bot==1 else 9)).replace('BOTN',f'BOT{bot}').replace('BotN',f'Bot{bot}').replace('botN',f'bot{bot}').replace('bot-cua-toi-N',f'bot-cua-toi-{bot}').replace('bot!=N',f'bot!={bot}')
    head,tail=source.split('int OnStart()',1);source=head+'int OnStart()'+re.sub(r'\binput\b','case_file',tail)
    for old,new in {'r':'check_settings','s':'check_state','c':'check_context','volumes':'check_volumes','enabled':'withdrawal_enabled','last_check':'check_time','last_deal':'deal_time','symbol':'check_symbol','suffix':'check_suffix','peak_key':'check_peak_key','time_key':'check_time_key'}.items():
        source=re.sub(r'\b'+old+r'\b',new,source)
    home=R/f'bot-cua-toi-{bot}/source/MQL5/Scripts/bot-cua-toi-{bot}'
    (home/f'Bot{bot}VolumeRuntimeCheck.mq5').write_text(source,encoding='utf-8',newline='\n')
    api=f'''#property strict
#include "../../Include/bot-cua-toi-{bot}/Bot{bot}VolumeRuntime.mqh"
void OnStart()
{{
   Bot{bot}VolumeSettings r;Bot{bot}VolumeState s;ZeroMemory(r);ZeroMemory(s);
   double volumes[{8 if bot==1 else 9}];ArrayInitialize(volumes,0.01);uint index=0;
   long last_check=0,last_deal=0;string symbol="XAUUSD",suffix="",peak="compile-peak",time="compile-time";
'''+('   double denominator=1.0;uchar enabled[5];ArrayInitialize(enabled,1);\n' if bot==3 else '')+f'   Bot{bot}PrepareVolumeRuntime(100.,100,symbol,suffix,r,s,false,peak,time,last_check,last_deal,'+('denominator,enabled,' if bot==3 else '')+'index,volumes);\n}\n'
    (home/f'Bot{bot}VolumeRuntimeAPICompile.mq5').write_text(api,encoding='utf-8',newline='\n')
