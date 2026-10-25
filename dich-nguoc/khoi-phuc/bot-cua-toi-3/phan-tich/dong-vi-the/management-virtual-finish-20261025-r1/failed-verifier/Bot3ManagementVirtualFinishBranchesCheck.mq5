// Bounded supplied-input check for the final virtual branches; no live trading.
#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-3/Bot3ManagementPrelude.mqh"
#include "../../Include/bot-cua-toi-3/Bot3VirtualStops.mqh"
input string CheckRun="";
union Bits { double d; ulong u; };
int fault=0,scenario=0,digit_count=0,digits0=3,digits1=3,index0=2; double point=.01;
double level=0,unit=1,gap=1.25,freeze=2.5,bid=100,ask=101; ulong hash=0xcbf29ce484222325;
ulong bits(double x){Bits b;b.d=x;return b.u;}
void trace(int api){hash^=(ulong)api;hash*=0x100000001b3;}
long FSymbolInfoInteger(const string s,const ENUM_SYMBOL_INFO_INTEGER p){if(s!="CHECK"||p!=SYMBOL_DIGITS)fault=1;trace(3);return digit_count++==0?digits0:digits1;}
double FSymbolInfoDouble(const string s,const ENUM_SYMBOL_INFO_DOUBLE p){if(s!="CHECK"||p!=SYMBOL_POINT)fault=2;trace(4);return point;}
#define SymbolInfoInteger FSymbolInfoInteger
#define SymbolInfoDouble FSymbolInfoDouble
#include "../../Include/bot-cua-toi-3/Bot3ManagementVirtualFinish.mqh"
#undef SymbolInfoInteger
#undef SymbolInfoDouble
void setup(const bool buy,const int stage,double &open,double &tp,double &anchor,double &reference,double &extra,double &lock,double &distance,double &step)
{open=100.;tp=buy?130.:70.;anchor=buy?110.:90.;reference=0.;extra=1.;lock=2.;distance=2.;step=1.;level=buy?97.:103.;unit=1.;gap=1.25;freeze=2.5;bid=100.;ask=101.;}
int OnStart()
{
 string folder="bot3-management-virtual-finish-branches\\"+CheckRun+"\\";int h=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(h==INVALID_HANDLE)return 2;
 int magic=FileReadInteger(h),version=FileReadInteger(h),count=FileReadInteger(h);if(magic!=0x4d564642||version!=1||count<1)return 3;
 int out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(out==INVALID_HANDLE)return 4;FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
 for(int i=0;i<count;i++)
 {
  int id=FileReadInteger(h),buyi=FileReadInteger(h),stage=FileReadInteger(h),sc=FileReadInteger(h),changedi=FileReadInteger(h),idx=FileReadInteger(h),d0=FileReadInteger(h),d1=FileReadInteger(h);
  double v[20];for(int k=0;k<20;k++)v[k]=FileReadDouble(h);scenario=sc;digits0=d0;digits1=d1;index0=idx;bool buy=buyi!=0,changed=changedi!=0;
  double open=v[0],tp=v[1],anchor=v[11],reference=v[8],extra=v[7],lock=v[6],distance=v[10],step=v[19];setup(buy,stage,open,tp,anchor,reference,extra,lock,distance,step);level=v[2];unit=v[3];gap=v[4];freeze=v[5];bid=v[12];ask=v[13];
  Bot3ManagedPosition p;ZeroMemory(p);p.open_price=open;p.tp=tp;p.ticket_number=7;MqlTick tick;ZeroMemory(tick);tick.bid=bid;tick.ask=ask;double levels[9];for(int k=0;k<9;k++)levels[k]=(buy?v[14]:v[15])+k;
  Bot3VirtualFinishSettings s;ZeroMemory(s);s.high_low_enabled=1;s.high_low_before_open=0;s.high_low_shift=0;s.high_low_buy_shift=v[16];s.high_low_sell_shift=v[17];s.lock_start=lock;s.lock_extra=extra;s.mode=2;s.step_enabled=1;s.step_reference=reference;s.min_steps=1;s.step_distance=step;
  bool c=changed;digit_count=0;hash=0xcbf29ce484222325;uint ui=(uint)idx;int counter=0;
  if(stage==0) Bot3AdvanceVirtualHighLow(buy,"CHECK",s,unit,gap,freeze,p,tick,levels,ui,level,c);
  else Bot3AdvanceVirtualBreakEvenCounter(buy,"CHECK",s,unit,gap,freeze,anchor,step,p,tick,level,c,counter);
  FileWriteInteger(out,id);FileWriteInteger(out,(int)c);FileWriteDouble(out,level);FileWriteInteger(out,counter);FileWriteInteger(out,(int)ui);FileWriteLong(out,(long)hash);FileWriteDouble(out,tick.bid);FileWriteDouble(out,tick.ask);FileWriteDouble(out,unit);FileWriteDouble(out,gap);FileWriteDouble(out,freeze);FileWriteInteger(out,0);FileWriteLong(out,0);
 }
 FileClose(h);FileClose(out);int st=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(st==INVALID_HANDLE)return 5;FileWriteInteger(st,fault);FileWriteInteger(st,count);FileClose(st);return fault;
}
