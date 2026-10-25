#property strict
#property script_show_inputs
#include "../../Include/bot-cua-toi-1/Bot1PositionClose.mqh"
#include "../../Include/bot-cua-toi-1/Bot1VirtualStops.mqh"
input string CheckRun="";
union B { double d; ulong u; };
int scenario=0,high_enabled=0,before_open=0,g_shift=0,mode=0,step_enabled=0,min_steps=0,g_digits=0,guard=0,close_tick=0;
double g_level=0.,g_point=0.,g_bid=0.,g_ask=0.,g_current=0.,close_bid=0.,close_ask=0.,g_gap=0.,g_freeze=0.; MqlTick g_tick; ulong hash=0; int fault=0,calls=0; int g_scenario=0;
ulong bits(double x){B b;b.d=x;return b.u;}
void trace(int api,ulong a=0,ulong b=0,ulong c=0,ulong d=0){ulong z[5];z[0]=api;z[1]=a;z[2]=b;z[3]=c;z[4]=d;for(int i=0;i<5;i++)for(int j=0;j<8;j++){hash^=(z[i]>>(8*j))&255;hash*=(ulong)0x100000001b3;}calls++;}
ulong text_hash(const string s){ulong h=(ulong)0xcbf29ce484222325;for(int i=0;i<StringLen(s);i++){ushort c=StringGetCharacter(s,i);h^=(ulong)(c&255);h*=(ulong)0x100000001b3;h^=(ulong)(c>>8);h*=(ulong)0x100000001b3;}return h;}
ulong table_hash(const Bot1VirtualStopState &t){ulong h=(ulong)0xcbf29ce484222325;for(int r=0;r<500;r++)for(int c=0;c<3;c++){B b;b.d=t.rows[r][c];for(int j=0;j<8;j++){h^=(b.u>>(8*j))&255;h*=(ulong)0x100000001b3;}}return h;}
void mutate(const int api){if(g_scenario==2 && api==4)g_current+=1.25;if(g_scenario==5 && api==4){g_current+=1.25;g_bid+=1.25;g_ask+=1.25;close_bid=g_bid;close_ask=g_ask;g_tick.bid=g_bid;g_tick.ask=g_ask;}if(g_scenario==6 && api==10){g_current+=1.25;g_bid+=1.25;g_ask+=1.25;close_bid=g_bid;close_ask=g_ask;g_tick.bid=g_bid;g_tick.ask=g_ask;}}
double SPoint(const string s,const ENUM_SYMBOL_INFO_DOUBLE p){if(s!="CHECK"||p!=SYMBOL_POINT)fault=2;trace(4,(ulong)p,bits(g_point));mutate(4);return g_point;}
long SDigits(const string s,const ENUM_SYMBOL_INFO_INTEGER p){if(s!="CHECK"||p!=SYMBOL_DIGITS)fault=3;trace(3,(ulong)g_digits);return g_digits;}
bool STick(const string s,MqlTick &t){if(s!="CHECK")fault=3;trace(7,text_hash(s),(ulong)close_tick,bits(g_bid),bits(g_ask));if(close_tick!=0){t.bid=close_bid;t.ask=close_ask;g_bid=t.bid;g_ask=t.ask;g_tick=t;}return close_tick!=0;}
void Close(Bot1PendingRequestState &st,Bot1TradeSendOptions &op,const ulong &dev,const double &a,const double &b,const double &ta,const double &tb,const ulong ticket){if(dev!=(ulong)0x0123456789abcdef || bits(a)!=bits(g_bid)||bits(b)!=bits(g_ask)||bits(ta)!=bits(g_gap)||bits(tb)!=bits(g_freeze))fault=4;trace(8,ticket);}
#define SymbolInfoDouble SPoint
#define SymbolInfoInteger SDigits
#define SymbolInfoTick STick
#define Bot1TryClosePosition Close
#include "../../Include/bot-cua-toi-1/Bot1ManagementVirtualFinish.mqh"
#undef SymbolInfoDouble
#undef SymbolInfoInteger
#undef SymbolInfoTick
#undef Bot1TryClosePosition

int OnStart()
{
   string folder="bot1-management-virtual-finish\\"+CheckRun+"\\";
   int in=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN), out=INVALID_HANDLE;
   if(in==INVALID_HANDLE) return 6;
   int magic=FileReadInteger(in),version=FileReadInteger(in),count=FileReadInteger(in);
   if(magic!=0x4d564646 || version!=1 || count<1){FileClose(in);return 7;}
   out=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN);if(out==INVALID_HANDLE){FileClose(in);return 8;}
   FileWriteInteger(out,magic);FileWriteInteger(out,version);FileWriteInteger(out,count);
   for(int i=0;i<count;i++)
   {
      int id=FileReadInteger(in),buy=FileReadInteger(in),sc=FileReadInteger(in),he=FileReadInteger(in),bo=FileReadInteger(in),sh=FileReadInteger(in),md=FileReadInteger(in),initial_changed=FileReadInteger(in),pattern=FileReadInteger(in);
      long ticket=FileReadLong(in),counter_raw=FileReadLong(in),idx_raw=FileReadLong(in),guard_raw=FileReadLong(in);
      int counter=(int)counter_raw,idx=(int)idx_raw;uint strategy_idx=(uint)idx;guard=(int)guard_raw;
      double open=FileReadDouble(in),sl=FileReadDouble(in),tp=FileReadDouble(in),in_bid=FileReadDouble(in),in_ask=FileReadDouble(in);
      double unit=FileReadDouble(in),gap=FileReadDouble(in),freeze=FileReadDouble(in),in_level=FileReadDouble(in);
      double anchor=FileReadDouble(in),cached=FileReadDouble(in),copied=FileReadDouble(in);g_point=FileReadDouble(in);
      double table_volume=FileReadDouble(in),minimum=FileReadDouble(in),lock_start=FileReadDouble(in),lock_extra=FileReadDouble(in),ref=FileReadDouble(in),step_dist=FileReadDouble(in);
      step_enabled=FileReadInteger(in);min_steps=FileReadInteger(in);g_digits=FileReadInteger(in);close_tick=FileReadInteger(in);g_bid=in_bid;g_ask=in_ask;g_scenario=sc;g_current=in_level;
      ZeroMemory(g_tick);g_tick.bid=in_bid;g_tick.ask=in_ask;close_bid=in_bid;close_ask=in_ask;g_gap=gap;g_freeze=freeze;calls=0;hash=(ulong)0xcbf29ce484222325;
      Bot1ManagedPosition pos;ZeroMemory(pos);pos.open_price=open;pos.sl=sl;pos.tp=tp;pos.volume=table_volume;
      double levels[9];ArrayInitialize(levels,in_level);levels[idx]=in_level+(buy!=0 ? 0.5 : -0.5);bool changed=false;
      Bot1VirtualFinishSettings cfg;ZeroMemory(cfg);cfg.high_low_enabled=he;cfg.high_low_before_open=(uchar)bo;cfg.high_low_shift=(uchar)sh;cfg.high_low_buy_shift=10.;cfg.high_low_sell_shift=10.;cfg.lock_start=lock_start;cfg.lock_extra=lock_extra;cfg.mode=md;cfg.step_enabled=(uchar)step_enabled;cfg.step_reference=ref;cfg.min_steps=min_steps;cfg.step_distance=step_dist;
      Bot1VirtualStopState table;ZeroMemory(table);table.guard=(uchar)guard;
      for(int r=0;r<500;r++) { table.rows[r][0]=10000.0+r;table.rows[r][1]=20000.0+r;table.rows[r][2]=-30000.0-r; }
      if(pattern==0) table.rows[0][0]=(double)ticket;
      if(pattern==1) table.rows[250][0]=(double)ticket;
      if(pattern==2) table.rows[499][0]=(double)ticket;
      if(pattern==3) { table.rows[1][0]=(double)ticket;table.rows[17][0]=(double)ticket;table.rows[499][0]=(double)ticket; }
      if(pattern==5) { B invalid;invalid.u=(ulong)0x7ff8000000000000;table.rows[0][0]=invalid.d; }
      Bot1PendingRequestState state;ZeroMemory(state);Bot1TradeSendOptions options;ZeroMemory(options);
      changed=initial_changed!=0;bool closed=Bot1FinishVirtualManagement(buy!=0,"CHECK",cfg,unit,gap,freeze,anchor,cached,copied,pos,g_tick,levels,strategy_idx,g_current,changed,counter,in_level,ticket,table,state,options,(ulong)0x0123456789abcdef);
      FileWriteInteger(out,id);FileWriteInteger(out,(int)closed);FileWriteInteger(out,(int)changed);FileWriteInteger(out,(int)(closed||changed));FileWriteLong(out,(long)bits(g_current));FileWriteLong(out,(long)counter);FileWriteLong(out,(long)bits(tp));FileWriteLong(out,(long)bits(g_tick.bid));FileWriteLong(out,(long)bits(g_tick.ask));FileWriteInteger(out,calls);FileWriteLong(out,(long)hash);FileWriteLong(out,(long)table_hash(table));FileWriteInteger(out,(int)table.guard);FileWriteInteger(out,(int)strategy_idx);
   }
   FileClose(in);FileClose(out);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 11;FileWriteInteger(status,fault);FileWriteInteger(status,count);FileClose(status);return fault;
}
