#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1EntryLoop.mqh"
#include "../../Include/bot-cua-toi-1/Bot1EntryLevelCache.mqh"
#include "../../Include/bot-cua-toi-1/Bot1PositionManagement.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ReleaseFilters.mqh"
Bot1PreparationInputs Inputs;Bot1PreparationState P;Bot1EntryLoopState Entry;Bot1PositionManagementState Manager;
Bot1NfpFilterState Nfp;Bot1ReleaseFilterState Interest,Cpi;Bot1PendingQueue Queue;Bot1LevelCacheSettings Levels;
int Magic;double MinimumSpread,Volumes[8];uchar FridayClosed;ulong LastTicket;
union Number {double value;ulong word;};
ulong Bits(const double value){Number n;n.value=value;return n.word;}
double Value(const ulong word){Number n;n.word=word;return n.value;}
void Word(const ulong v);void Text(const string v);void Begin();void Effect(const int api);
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,const string t=NULL,const string u=NULL);
double MockDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop);
long MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);
int MockBars(const string symbol,const ENUM_TIMEFRAMES frame);
datetime MockTime();datetime MockBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
double MockAccount(const ENUM_ACCOUNT_INFO_DOUBLE prop);
double MockLevel(const bool buy,const string &symbol,const ENUM_TIMEFRAMES frame,const ENUM_TIMEFRAMES &confirmation,
                 const int &older,const int &recent,const int &last,const double &quote,const double &gap,const double &unit,
                 const int &magic,const double &buy_offset,const double &sell_offset,const double &radius,ulong &ticket);
void MockPrint(const string value);string Bot1StartupNumber(const double value);
#define BOT1_STARTUP_NUMBER_EXTERNAL
#define SymbolInfoDouble MockDouble
#define SymbolInfoInteger MockInteger
#define Bars MockBars
#define TimeCurrent MockTime
#define iTime MockBar
#define AccountInfoDouble MockAccount
#define Bot1EntryLevel MockLevel
#define Print MockPrint
#include "../../Include/bot-cua-toi-1/Bot1StartupTradingState.mqh"
#undef SymbolInfoDouble
#undef SymbolInfoInteger
#undef Bars
#undef TimeCurrent
#undef iTime
#undef AccountInfoDouble
#undef Bot1EntryLevel
#undef Print
Bot1StartupTradingState State;
int Tape,ErrorOverride=-1,Counts[10],DPos[4],IPos[3];bool Final=false;
double Doubles[4][8],AccountReply,LevelReply[2];long Integers[3][8],Times[8],BarsReply[2],BarTimes[3];ulong Effects[32][4];int EffectCount;
void Word(const ulong v){FileWriteLong(Tape,(long)v);}
void Text(const string v){int n=v==NULL ? -1 : StringLen(v);FileWriteInteger(Tape,n);if(n>0)FileWriteString(Tape,v,n);}
string ReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
ulong TablesHash(){ulong h=0xcbf29ce484222325;for(int i=0;i<500;i++)for(int j=0;j<3;j++)h=(h^Bits(Manager.table.rows[i][j]))*0x100000001b3;for(int i=0;i<100;i++)for(int j=0;j<3;j++)h=(h^Bits(Queue.orders[i][j]))*0x100000001b3;return h;}
void Snapshot()
{
   Word((ulong)P.native_62414);
   Word((ulong)State.native_62555);
   Word((ulong)P.strategy_index);
   Word((ulong)P.entry_frame);
   Word((ulong)P.native_6248c);
   Word(Bits(P.tick.ask));
   Word(Bits(P.tick.bid));
   Word(Bits(P.spread));
   Word(Bits(P.native_62530));
   Word(Bits(P.unit));
   Word(Bits(P.min_change));
   Word(Bits(P.stop_min_price));
   Word(Bits(P.freeze_min_price));
   Word(Bits(P.stop_distance));
   Word(Bits(P.target_distance));
   Word(Bits(P.trigger_distance));
   Word(Bits(P.locked_distance));
   Word((ulong)P.freeze_buffer);
   Word(Bits(P.trail_distance));
   Word(Bits(P.native_624f8));
   Word(Bits(P.native_62500));
   Word(Bits(P.gap_points));
   Word((ulong)P.older_width);
   Word((ulong)P.recent_width);
   Word((ulong)P.expiration_hours);
   Word((ulong)P.virtual_expiration);
   Word((ulong)P.expiration_seconds);
   Word((ulong)P.expiration);
   Word((ulong)Nfp.notice);
   Word((ulong)Nfp.blocked);
   Word((ulong)Interest.blocked);
   Word((ulong)Cpi.blocked);
   Word((ulong)State.week_bar);
   Word(Bits(P.max_spread));
   Word(Bits(MinimumSpread));
   Word((ulong)Inputs.entry.confirmation_frame);
   Word((ulong)Magic);
   Word((ulong)P.last_shift);
   Word(Bits(P.buy_offset));
   Word(Bits(P.sell_offset));
   Word(Bits(P.nearby_radius));
   Word((ulong)LastTicket);
   Word(Bits(Entry.candidate_buy));
   Word(Bits(Entry.candidate_sell));
   Word(Bits(Entry.rounded_buy));
   Word(Bits(Entry.rounded_sell));
   Word((ulong)Levels.blocked);
   Word((ulong)Manager.counter);
   Word((ulong)State.timed_delay_seconds);
   Word(Bits(Manager.current_stop));
   Word(Bits(P.native_62538));
   Word((ulong)Manager.table.guard);
   Word((ulong)Queue.enabled);
   Word((ulong)FridayClosed);
   for(int i=0;i<8;i++)Word(Bits(Volumes[i]));Text(Inputs.symbol);Word(TablesHash());Word(ErrorOverride<0 ? GetLastError() : (uint)ErrorOverride);
   if(Final){for(int i=0;i<500;i++)for(int j=0;j<3;j++)Word(Bits(Manager.table.rows[i][j]));for(int i=0;i<100;i++)for(int j=0;j<3;j++)Word(Bits(Queue.orders[i][j]));}
}
void Begin(){ulong at=FileTell(Tape);FileWriteInteger(Tape,0);Snapshot();ulong end=FileTell(Tape);FileSeek(Tape,(long)at,SEEK_SET);FileWriteInteger(Tape,(int)(end-at-4));FileSeek(Tape,(long)end,SEEK_SET);}
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,const string t=NULL,const string u=NULL){FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Word(d);Text(t);Text(u);FileWriteInteger(Tape,(int)GetLastError());}
void Effect(const int api){int n=++Counts[api];for(int i=0;i<EffectCount;i++){if((int)Effects[i][0]!=api || (int)Effects[i][1]!=n)continue;ulong v=Effects[i][3];switch((int)Effects[i][2]){case 0:P.native_62414=(int)v;break;case 1:State.native_62555=(uchar)v;break;case 2:P.strategy_index=(uint)v;break;case 3:P.entry_frame=(int)v;break;case 4:P.native_6248c=(int)v;break;case 5:P.tick.ask=Value(v);break;case 6:P.tick.bid=Value(v);break;case 7:P.spread=Value(v);break;case 8:P.native_62530=Value(v);break;case 9:P.unit=Value(v);break;case 10:P.min_change=Value(v);break;case 11:P.stop_min_price=Value(v);break;case 12:P.freeze_min_price=Value(v);break;case 13:P.stop_distance=Value(v);break;case 14:P.target_distance=Value(v);break;case 15:P.trigger_distance=Value(v);break;case 16:P.locked_distance=Value(v);break;case 17:P.freeze_buffer=(int)v;break;case 18:P.trail_distance=Value(v);break;case 19:P.native_624f8=Value(v);break;case 20:P.native_62500=Value(v);break;case 21:P.gap_points=Value(v);break;case 22:P.older_width=(int)v;break;case 23:P.recent_width=(int)v;break;case 24:P.expiration_hours=(int)v;break;case 25:P.virtual_expiration=(uchar)v;break;case 26:P.expiration_seconds=(uint)v;break;case 27:P.expiration=(long)v;break;case 28:Nfp.notice=(uchar)v;break;case 29:Nfp.blocked=(uchar)v;break;case 30:Interest.blocked=(uchar)v;break;case 31:Cpi.blocked=(uchar)v;break;case 32:State.week_bar=(long)v;break;case 33:P.max_spread=Value(v);break;case 34:MinimumSpread=Value(v);break;case 35:Inputs.entry.confirmation_frame=(int)v;break;case 36:Magic=(int)v;break;case 37:P.last_shift=(int)v;break;case 38:P.buy_offset=Value(v);break;case 39:P.sell_offset=Value(v);break;case 40:P.nearby_radius=Value(v);break;case 41:LastTicket=v;break;case 42:Entry.candidate_buy=Value(v);break;case 43:Entry.candidate_sell=Value(v);break;case 44:Entry.rounded_buy=Value(v);break;case 45:Entry.rounded_sell=Value(v);break;case 46:Levels.blocked=(uchar)v;break;case 47:Manager.counter=(int)v;break;case 48:State.timed_delay_seconds=(int)v;break;case 49:Manager.current_stop=Value(v);break;case 50:P.native_62538=Value(v);break;case 51:Manager.table.guard=(uchar)v;break;case 52:Queue.enabled=(uchar)v;break;case 53:FridayClosed=(uchar)v;break;}}}
int MockBars(const string symbol,const ENUM_TIMEFRAMES frame){Begin();int v=(int)BarsReply[Counts[1]%2];Effect(1);End(1,(ulong)frame,(ulong)(long)v,0,0,symbol);return v;}
datetime MockTime(){Begin();long v=Times[Counts[2]%8];Effect(2);End(2,(ulong)v);return (datetime)v;}
double MockDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop){Begin();int p=prop==SYMBOL_POINT ? 0 : (prop==SYMBOL_VOLUME_MIN ? 1 : (prop==SYMBOL_VOLUME_MAX ? 2 : 3));int i=DPos[p]++;double v=Doubles[p][i<8 ? i : 7];Effect(3);End(3,(ulong)prop,Bits(v),0,0,symbol);return v;}
long MockInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();int p=prop==SYMBOL_TRADE_STOPS_LEVEL ? 0 : (prop==SYMBOL_TRADE_FREEZE_LEVEL ? 1 : 2);int i=IPos[p]++;long v=Integers[p][i<8 ? i : 7];Effect(4);End(4,(ulong)prop,(ulong)v,0,0,symbol);return v;}
double MockAccount(const ENUM_ACCOUNT_INFO_DOUBLE prop){Begin();double v=AccountReply;Effect(5);End(5,(ulong)prop,Bits(v));return v;}
datetime MockBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();long v=BarTimes[Counts[6]%3];Effect(6);End(6,(ulong)frame,(ulong)(long)shift,(ulong)v,0,symbol);return (datetime)v;}
double MockLevel(const bool buy,const string &symbol,const ENUM_TIMEFRAMES frame,const ENUM_TIMEFRAMES &confirmation,
                 const int &older,const int &recent,const int &last,const double &quote,const double &gap,const double &unit,
                 const int &magic,const double &buy_offset,const double &sell_offset,const double &radius,ulong &ticket)
{Begin();ulong passed[11]={(ulong)(long)older,(ulong)(long)recent,(ulong)(long)last,Bits(quote),Bits(gap),Bits(unit),(ulong)(long)magic,Bits(buy_offset),Bits(sell_offset),Bits(radius),ticket};double v=LevelReply[buy ? 0 : 1];Effect(7);End(7,(ulong)buy,(ulong)frame,(ulong)confirmation,Bits(v),symbol);for(int i=0;i<11;i++)Word(passed[i]);return v;}
string Bot1StartupNumber(const double value){Begin();string v=(string)value;Effect(8);End(8,Bits(value),0,0,0,v);return v;}
void MockPrint(const string value){Begin();Effect(9);End(9,0,0,0,0,value);}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-startup-trading\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x54533131 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),tapes=FileOpen(folder+"sdk-tape.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE || tapes==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);FileWriteInteger(tapes,magic);FileWriteInteger(tapes,version);FileWriteInteger(tapes,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);
      P.native_62414=(int)FileReadLong(file);
      State.native_62555=(uchar)FileReadLong(file);
      P.strategy_index=(uint)FileReadLong(file);
      P.entry_frame=(int)FileReadLong(file);
      P.native_6248c=(int)FileReadLong(file);
      P.tick.ask=Value((ulong)FileReadLong(file));
      P.tick.bid=Value((ulong)FileReadLong(file));
      P.spread=Value((ulong)FileReadLong(file));
      P.native_62530=Value((ulong)FileReadLong(file));
      P.unit=Value((ulong)FileReadLong(file));
      P.min_change=Value((ulong)FileReadLong(file));
      P.stop_min_price=Value((ulong)FileReadLong(file));
      P.freeze_min_price=Value((ulong)FileReadLong(file));
      P.stop_distance=Value((ulong)FileReadLong(file));
      P.target_distance=Value((ulong)FileReadLong(file));
      P.trigger_distance=Value((ulong)FileReadLong(file));
      P.locked_distance=Value((ulong)FileReadLong(file));
      P.freeze_buffer=(int)FileReadLong(file);
      P.trail_distance=Value((ulong)FileReadLong(file));
      P.native_624f8=Value((ulong)FileReadLong(file));
      P.native_62500=Value((ulong)FileReadLong(file));
      P.gap_points=Value((ulong)FileReadLong(file));
      P.older_width=(int)FileReadLong(file);
      P.recent_width=(int)FileReadLong(file);
      P.expiration_hours=(int)FileReadLong(file);
      P.virtual_expiration=(uchar)FileReadLong(file);
      P.expiration_seconds=(uint)FileReadLong(file);
      P.expiration=FileReadLong(file);
      Nfp.notice=(uchar)FileReadLong(file);
      Nfp.blocked=(uchar)FileReadLong(file);
      Interest.blocked=(uchar)FileReadLong(file);
      Cpi.blocked=(uchar)FileReadLong(file);
      State.week_bar=FileReadLong(file);
      P.max_spread=Value((ulong)FileReadLong(file));
      MinimumSpread=Value((ulong)FileReadLong(file));
      Inputs.entry.confirmation_frame=(int)FileReadLong(file);
      Magic=(int)FileReadLong(file);
      P.last_shift=(int)FileReadLong(file);
      P.buy_offset=Value((ulong)FileReadLong(file));
      P.sell_offset=Value((ulong)FileReadLong(file));
      P.nearby_radius=Value((ulong)FileReadLong(file));
      LastTicket=(ulong)FileReadLong(file);
      Entry.candidate_buy=Value((ulong)FileReadLong(file));
      Entry.candidate_sell=Value((ulong)FileReadLong(file));
      Entry.rounded_buy=Value((ulong)FileReadLong(file));
      Entry.rounded_sell=Value((ulong)FileReadLong(file));
      Levels.blocked=(uchar)FileReadLong(file);
      Manager.counter=(int)FileReadLong(file);
      State.timed_delay_seconds=(int)FileReadLong(file);
      Manager.current_stop=Value((ulong)FileReadLong(file));
      P.native_62538=Value((ulong)FileReadLong(file));
      Manager.table.guard=(uchar)FileReadLong(file);
      Queue.enabled=(uchar)FileReadLong(file);
      FridayClosed=(uchar)FileReadLong(file);
      Inputs.symbol=ReadText(file);
      for(int i=0;i<4;i++)for(int j=0;j<8;j++)Doubles[i][j]=Value((ulong)FileReadLong(file));
      for(int i=0;i<3;i++)for(int j=0;j<8;j++)Integers[i][j]=FileReadLong(file);
      for(int i=0;i<8;i++)Times[i]=FileReadLong(file);for(int i=0;i<2;i++)BarsReply[i]=FileReadLong(file);for(int i=0;i<3;i++)BarTimes[i]=FileReadLong(file);
      AccountReply=Value((ulong)FileReadLong(file));for(int i=0;i<2;i++)LevelReply[i]=Value((ulong)FileReadLong(file));
      EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>32)return 8;for(int i=0;i<EffectCount;i++)for(int j=0;j<4;j++)Effects[i][j]=(ulong)FileReadLong(file);
      for(int i=0;i<8;i++)Volumes[i]=(double)(i+1)*.125;
      for(int i=0;i<500;i++)for(int j=0;j<3;j++)Manager.table.rows[i][j]=(double)(3*i+j+1)*.125;
      for(int i=0;i<100;i++)for(int j=0;j<3;j++)Queue.orders[i][j]=(double)(3*i+j+1)*.25;
      ArrayInitialize(Counts,0);ArrayInitialize(DPos,0);ArrayInitialize(IPos,0);string part=folder+"tape-"+IntegerToString(id)+".bin";Tape=FileOpen(part,FILE_WRITE|FILE_BIN);if(Tape==INVALID_HANDLE)return 5;
      ResetLastError();Final=false;ErrorOverride=-1;
      Bot1InitializeTradingState(Inputs,P,Magic,Entry,Nfp,Interest,Cpi,Manager,Queue,Levels,MinimumSpread,FridayClosed,Volumes,LastTicket,State);
      int error=GetLastError();FileClose(Tape);int section=FileOpen(part,FILE_READ|FILE_BIN);if(section==INVALID_HANDLE)return 6;int size=(int)FileSize(section);uchar raw[];ArrayResize(raw,size);if(size>0)FileReadArray(section,raw);FileClose(section);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0)FileWriteArray(tapes,raw);
      FileWriteInteger(output,id);Tape=output;Final=true;ErrorOverride=error;Begin();
   }
   if(FileTell(file)!=FileSize(file))return 9;FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
