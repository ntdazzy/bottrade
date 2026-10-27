#property strict
#include "../../Include/bot-cua-toi-3/Bot3Volume.mqh"
union V_DoubleBits { double value;ulong bits; };
ulong V_Bits(const double value) { V_DoubleBits u;u.value=value;return u.bits; }
string V_ReadText(const int h) { int n=FileReadInteger(h);return n>0 ? FileReadString(h,n) : ""; }
void V_WriteText(const int h,const string value)
{ int n=StringLen(value);FileWriteInteger(h,n);if(n>0) FileWriteString(h,value,n); }
Bot3VolumeSettings V_check_settings;Bot3VolumeContext V_check_context;Bot3VolumeState V_check_state;
uchar V_strategy_enabled[5];
long V_check_time,V_deal_time,V_times[3];string V_check_symbol,V_check_suffix,V_check_peak_key,V_check_time_key,V_currencies[];
bool V_withdrawal_enabled,V_select_ok,V_restore_ok;int V_tester,V_reported,V_mutate_after,V_mutate_index;
double V_prices[8],V_replies26[],V_replies34[],V_replies35[],V_replies36[];
ulong V_tickets[];long V_deal_types[],V_deal_times[];double V_profits[];
int V_counters26,V_counters34,V_counters35,V_counters36,V_symbol_calls,V_currency_calls,V_price_calls,V_clock_calls,V_select_calls;
int V_output,V_event_count;
void V_State()
{
   FileWriteLong(V_output,(long)V_Bits(V_check_state.effective_balance));
   FileWriteLong(V_output,(long)V_Bits(V_check_state.highest_balance));
   FileWriteLong(V_output,(long)V_check_state.mode);
   FileWriteLong(V_output,(long)V_Bits(V_check_state.strategy_loss));
   FileWriteLong(V_output,(long)V_check_state.balance_step);
   FileWriteLong(V_output,(long)V_Bits(V_check_state.adaptive_fraction));
   FileWriteLong(V_output,V_check_time);FileWriteLong(V_output,V_deal_time);FileWriteLong(V_output,(long)ResizeIndex);
   for(int i=0;i<9;i++) FileWriteLong(V_output,(long)V_Bits(ResizeVolumes[i]));
   FileWriteLong(V_output,(long)V_Bits(FlowPrevious));
}
void V_Event(const int api,const ulong first=0,const ulong second=0,const ulong value=0,const string text1="",const string text2="")
{
   FileWriteInteger(V_output,api);FileWriteLong(V_output,(long)first);FileWriteLong(V_output,(long)second);FileWriteLong(V_output,(long)value);
   V_WriteText(V_output,text1);V_WriteText(V_output,text2);V_State();V_event_count++;FileFlush(V_output);
}
double V_MockAccount(const ENUM_ACCOUNT_INFO_DOUBLE prop)
{ double value=prop==ACCOUNT_BALANCE ? V_check_context.balance : V_check_context.equity;V_Event(1,(ulong)prop,0,V_Bits(value));return value; }
double V_Reply(double &values[],int &count)
{ double value=values[MathMin(count,ArraySize(values)-1)];count++;return value; }
double V_MockSymbol(const string name,const ENUM_SYMBOL_INFO_DOUBLE prop)
{
   double value=0.0;
   if((int)prop==26) value=V_Reply(V_replies26,V_counters26);
   else if((int)prop==34) value=V_Reply(V_replies34,V_counters34);
   else if((int)prop==35) value=V_Reply(V_replies35,V_counters35);
   else if((int)prop==36) value=V_Reply(V_replies36,V_counters36);
   V_Event(2,(ulong)prop,0,V_Bits(value),name);V_symbol_calls++;
   if(V_mutate_after!=0 && V_symbol_calls==V_mutate_after) ResizeIndex=(uint)V_mutate_index;
   return value;
}
int V_MockMql(const ENUM_MQL_INFO_INTEGER prop) { V_Event(3,(ulong)prop,0,(ulong)(long)V_tester);return V_tester; }
datetime V_MockTime()
{ long value=V_times[MathMin(V_clock_calls,2)];V_clock_calls++;V_Event(4,0,0,(ulong)value);return (datetime)value; }
bool V_MockSelect(const datetime from,const datetime to)
{ bool value=V_select_calls==0 ? V_select_ok : V_restore_ok;V_select_calls++;V_Event(5,(ulong)from,(ulong)to,(ulong)value);return value; }
int V_MockTotal() { V_Event(6,0,0,(ulong)(long)V_reported);return V_reported; }
ulong V_MockTicket(const int index)
{ ulong value=index>=0 && index<ArraySize(V_tickets) ? V_tickets[index] : 0;V_Event(7,(ulong)index,0,value);return value; }
int V_Find(const ulong ticket) { for(int i=0;i<ArraySize(V_tickets);i++) if(V_tickets[i]==ticket) return i;return -1; }
long V_MockInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop)
{ int i=V_Find(ticket);long value=i<0 ? 0 : (prop==DEAL_TYPE ? V_deal_types[i] : V_deal_times[i]);V_Event(8,ticket,(ulong)prop,(ulong)value);return value; }
double V_MockDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop)
{ int i=V_Find(ticket);double value=i<0 ? 0.0 : V_profits[i];V_Event(9,ticket,(ulong)prop,V_Bits(value));return value; }
datetime V_MockSet(const string name,const double value) { V_Event(10,0,0,V_Bits(value),name);return 0; }
string V_MockCurrency(const ENUM_ACCOUNT_INFO_STRING prop)
{ string value=V_currencies[MathMin(V_currency_calls,ArraySize(V_currencies)-1)];V_currency_calls++;V_Event(11,(ulong)prop,0,0,value);return value; }
double V_MockClose(const string name,const ENUM_TIMEFRAMES tf,const int shift)
{ double value=V_prices[MathMin(V_price_calls,7)];V_price_calls++;V_Event(12,(ulong)tf,(ulong)shift,V_Bits(value),name);return value; }
void V_MockPrint(const string msg) { V_Event(13,2,1,0,msg); }
void V_MockPrint(const string msg,const double value) { V_Event(13,2,2,V_Bits(value),msg); }
void V_MockPrint(const string a,const string b,const string d,const string e,const string f,const string g)
{ V_Event(13,2,6,0,a+b+d+e+f+g); }
void V_MockAlert(const string msg) { V_Event(13,3,1,0,msg); }
string V_MockFixed(const double value,const int digits)
{ string reply=DoubleToString(value,digits);V_Event(15,V_Bits(value),(ulong)digits,0,reply);return reply; }
string Bot3VolumeNumber(const double value)
{ string reply=(string)value;V_Event(14,V_Bits(value),0x58,0,reply);return reply; }
#define BOT3_VOLUME_NUMBER_EXTERNAL
#define AccountInfoDouble V_MockAccount
#define SymbolInfoDouble V_MockSymbol
#define MQLInfoInteger V_MockMql
#define TimeCurrent V_MockTime
#define HistorySelect V_MockSelect
#define HistoryDealsTotal V_MockTotal
#define HistoryDealGetTicket V_MockTicket
#define HistoryDealGetInteger V_MockInteger
#define HistoryDealGetDouble V_MockDouble
#define GlobalVariableSet V_MockSet
#define AccountInfoString V_MockCurrency
#define iClose V_MockClose
#define Print V_MockPrint
#define Alert V_MockAlert
#define DoubleToString V_MockFixed
#include "../../Include/bot-cua-toi-3/Bot3VolumeRuntime.mqh"
#undef Print
#undef DoubleToString
void ReadValues(const int h,double &values[])
{ int total=FileReadInteger(h);ArrayResize(values,total);for(int i=0;i<total;i++) values[i]=FileReadDouble(h); }
void V_ReadCase(const int h)
{
   ZeroMemory(V_check_settings);ZeroMemory(V_check_context);ZeroMemory(V_check_state);
   V_check_settings.use_equity=FileReadInteger(h)!=0;
   V_check_settings.only_up=FileReadInteger(h)!=0;
   V_check_settings.manual_balance=FileReadDouble(h);
   V_check_settings.start_lots=FileReadDouble(h);
   V_check_settings.max_lots=FileReadDouble(h);
   V_check_settings.lot_scale=FileReadDouble(h);
   V_check_settings.manual_risk=FileReadDouble(h);
   V_check_settings.strategy_risk=FileReadDouble(h);
   V_check_settings.max_total_dd=FileReadDouble(h);
   V_check_settings.weighted=FileReadInteger(h)!=0;
   V_check_settings.frequency=FileReadInteger(h);
   V_check_state.mode=(uint)FileReadInteger(h);
   V_check_state.highest_balance=FileReadDouble(h);
   V_check_state.volume=FileReadDouble(h);
   V_check_state.strategy_loss=FileReadDouble(h);
   V_check_state.balance_step=FileReadInteger(h);
   V_check_state.adaptive_fraction=FileReadDouble(h);
   V_check_context.weight_denominator=FileReadDouble(h);
   V_check_context.balance=FileReadDouble(h);
   V_check_context.equity=FileReadDouble(h);
   V_check_context.converted_balance=FileReadDouble(h);
   V_check_context.converted_dd_balance=FileReadDouble(h);
   V_check_context.tick_value=FileReadDouble(h);
   V_check_context.minimum=FileReadDouble(h);
   V_check_context.maximum=FileReadDouble(h);
   V_check_context.step=FileReadDouble(h);
   V_check_context.stop_distance=FileReadDouble(h);
   V_check_context.multiplier=FileReadInteger(h);
   V_check_context.enabled_mask=(uint)FileReadInteger(h);
   V_withdrawal_enabled=FileReadInteger(h)!=0;V_tester=FileReadInteger(h);V_select_ok=FileReadInteger(h)!=0;V_restore_ok=FileReadInteger(h)!=0;V_reported=FileReadInteger(h);
   V_check_time=FileReadLong(h);V_deal_time=FileReadLong(h);for(int i=0;i<3;i++) V_times[i]=FileReadLong(h);
   V_check_symbol=V_ReadText(h);V_check_suffix=V_ReadText(h);V_check_peak_key=V_ReadText(h);V_check_time_key=V_ReadText(h);
   int total=FileReadInteger(h);ArrayResize(V_currencies,total);for(int i=0;i<total;i++) V_currencies[i]=V_ReadText(h);
   for(int i=0;i<8;i++) V_prices[i]=FileReadDouble(h);
   ResizeIndex=(uint)FileReadInteger(h);V_mutate_after=FileReadInteger(h);V_mutate_index=FileReadInteger(h);
   for(int i=0;i<9;i++) ResizeVolumes[i]=FileReadDouble(h);
   ReadValues(h,V_replies26);ReadValues(h,V_replies34);ReadValues(h,V_replies35);ReadValues(h,V_replies36);
   total=FileReadInteger(h);ArrayResize(V_tickets,total);ArrayResize(V_deal_types,total);ArrayResize(V_deal_times,total);ArrayResize(V_profits,total);
   for(int i=0;i<total;i++) { V_tickets[i]=(ulong)FileReadLong(h);V_deal_types[i]=FileReadLong(h);V_deal_times[i]=FileReadLong(h);V_profits[i]=FileReadDouble(h); }
   for(int i=0;i<5;i++) V_strategy_enabled[i]=(uchar)((V_check_context.enabled_mask>>i)&1);
   V_counters26=V_counters34=V_counters35=V_counters36=V_symbol_calls=V_currency_calls=V_price_calls=V_clock_calls=V_select_calls=V_event_count=0;
}
void V_Measure(const int h,const double value,const bool fixed)
{ FileWriteLong(h,(long)V_Bits(value));V_WriteText(h,fixed ? DoubleToString(value,2) : (string)value); }

#undef AccountInfoDouble
#undef SymbolInfoDouble
#undef MQLInfoInteger
#undef TimeCurrent
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef HistoryDealGetInteger
#undef HistoryDealGetDouble
#undef GlobalVariableSet
#undef AccountInfoString
#undef iClose
#undef Print
#undef Alert
#undef DoubleToString
