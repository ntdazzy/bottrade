#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-3/Bot3PanelCreation.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ClosedStatusPanel.mqh"
void MockCreate(Bot3PanelCreationState &p,const Bot3NewsEvents &events,const Bot3NewsWindows &windows,Bot3NewsSelection &selection);
void MockOpen(const uchar &show,const uchar &tester,const int &seed,const string &symbol,const double &balance,const int &frequency,
              const uint &mode,const double &manual_lots,const double &allowed_dd,const double &strategy_risk,const Bot3NewsEvents &events,
              const Bot3NewsWindows &windows,Bot3NewsSelection &selection,ulong &ticket);
void MockClosed(const uchar &show,const uchar &tester,const int &seed,const string &symbol,double &wins,double &losses);
long MockSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);int MockInfo(const ENUM_MQL_INFO_INTEGER prop);
bool MockSelect(const datetime from,const datetime to);int MockTotal();ulong MockTicket(const int index);
datetime MockTime();long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop);
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop);
#define Bot3CreateInfoPanel MockCreate
#define Bot3UpdateOpenStatusPanel MockOpen
#define Bot3UpdateClosedStatusPanel MockClosed
#define SymbolInfoInteger MockSymbol
#define MQLInfoInteger MockInfo
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define TimeCurrent MockTime
#define HistoryDealGetInteger MockDealInteger
#define HistoryDealGetDouble MockDealDouble
#include "../../Include/bot-cua-toi-3/Bot3StartupTail.mqh"
#undef Bot3CreateInfoPanel
#undef Bot3UpdateOpenStatusPanel
#undef Bot3UpdateClosedStatusPanel
#undef SymbolInfoInteger
#undef MQLInfoInteger
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef TimeCurrent
#undef HistoryDealGetInteger
#undef HistoryDealGetDouble
Bot3PanelCreationState P;Bot3NewsEvents Events;Bot3NewsWindows Windows;Bot3NewsSelection Selection;Bot3StartupTailState State;
MqlDateTime Calendar;uint Index;double StartLots,Balance,Wins,Losses;int LastHour,Magic,Seed;uchar Show,Tester,HistoryWindow;
string TradeComment,TradeSymbol;ulong LastTicket;long BarTimes[9];
union Number{double value;ulong word;};
ulong Bits(const double v){Number n;n.value=v;return n.word;}double Value(const ulong v){Number n;n.word=v;return n.value;}
int Tape,ErrorOverride=-1,Counts[23],InfoReply,SelectReply,TotalReply,DealCount,Selected,EffectCount,Result;
ulong Deals[32][4],Effects[32][4];long Times[8];bool Final=false;
void Word(const ulong v){FileWriteLong(Tape,(long)v);}
void Text(const string v){int n=v==NULL ? -1 : StringLen(v);FileWriteInteger(Tape,n);if(n>0)FileWriteString(Tape,v,n);}
string ReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void Snapshot(){Word((ulong)(long)P.font);
Word(Bits(P.scale));
Word((ulong)(long)P.color_flag);
Word((ulong)(long)P.mode);
Word(Bits(P.strategy_risk));
Word((ulong)(long)P.frequency);
Word(Bits(P.manual_lots));
Word(Bits(P.allowed_dd));
Word(Bits(P.cell_x));
Word(Bits(P.cell_y));
Word((ulong)(long)P.cell_font_flag);
Word((ulong)(long)P.closed_star);
Word((ulong)(long)P.rows_ready);
Word(Bits(P.closed[0]));
Word(Bits(P.closed[1]));
Word(Bits(P.closed[2]));
Word(Bits(P.closed[3]));
Word(Bits(P.closed[4]));
Word(Bits(P.closed[5]));
Word(Bits(P.closed[6]));
Word(Bits(P.closed[7]));
Word(Bits(P.closed[8]));
Word(Bits(P.per_trade[0]));
Word(Bits(P.per_trade[1]));
Word(Bits(P.per_trade[2]));
Word(Bits(P.per_trade[3]));
Word(Bits(P.per_trade[4]));
Word(Bits(P.per_trade[5]));
Word(Bits(P.per_trade[6]));
Word(Bits(P.per_trade[7]));
Word(Bits(P.per_trade[8]));
Word(Bits(P.lots[0]));
Word(Bits(P.lots[1]));
Word(Bits(P.lots[2]));
Word(Bits(P.lots[3]));
Word(Bits(P.lots[4]));
Word(Bits(P.lots[5]));
Word(Bits(P.lots[6]));
Word(Bits(P.lots[7]));
Word(Bits(P.lots[8]));
Word((ulong)(long)Events.nfp);
Word((ulong)(long)Events.interest);
Word((ulong)(long)Events.cpi);
Word((ulong)(long)Windows.nfp_enabled);
Word((ulong)(long)Windows.interest_enabled);
Word((ulong)(long)Windows.cpi_enabled);
Word((ulong)(long)Windows.nfp_after);
Word((ulong)(long)Windows.interest_after);
Word((ulong)(long)Windows.cpi_after);
Word((ulong)(long)Selection.block_time);
Text(Selection.label);
Word((ulong)(long)Index);
Word(Bits(StartLots));
Word((ulong)(long)Calendar.hour);
Word((ulong)(long)LastHour);
Word((ulong)(long)Show);
Word((ulong)(long)Tester);
Word((ulong)(long)HistoryWindow);
Word((ulong)(long)Magic);
Word((ulong)(long)Seed);
Word(Bits(Balance));
Word((ulong)(long)LastTicket);
Word(Bits(Wins));
Word(Bits(Losses));
Text(TradeComment);
Text(TradeSymbol);
Text(State.buy_first);
Text(State.buy_second);
Text(State.sell_first);
Text(State.sell_second);
Word((ulong)(long)State.flag_744a0);
Word((ulong)(long)BarTimes[0]);
Word((ulong)(long)BarTimes[1]);
Word((ulong)(long)BarTimes[2]);
Word((ulong)(long)BarTimes[3]);
Word((ulong)(long)BarTimes[4]);
Word((ulong)(long)BarTimes[5]);
Word((ulong)(long)BarTimes[6]);
Word((ulong)(long)BarTimes[7]);
Word((ulong)(long)BarTimes[8]); Word(ErrorOverride<0 ? GetLastError() : (uint)ErrorOverride);if(Final)Word((ulong)(long)Result);}
void Begin(){ulong at=FileTell(Tape);FileWriteInteger(Tape,0);Snapshot();ulong end=FileTell(Tape);FileSeek(Tape,(long)at,SEEK_SET);FileWriteInteger(Tape,(int)(end-at-4));FileSeek(Tape,(long)end,SEEK_SET);}
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const string value=NULL){FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Text(value);FileWriteInteger(Tape,(int)GetLastError());}
void Effect(const int api){int n=++Counts[api];for(int i=0;i<EffectCount;i++){if((int)Effects[i][0]!=api || (int)Effects[i][1]!=n)continue;ulong v=Effects[i][3];switch((int)Effects[i][2]){case 0:P.font=(int)v;break;case 1:P.scale=Value(v);break;case 2:P.color_flag=(uchar)v;break;case 3:P.mode=(uint)v;break;case 4:P.strategy_risk=Value(v);break;case 5:P.frequency=(int)v;break;case 6:P.manual_lots=Value(v);break;case 7:P.allowed_dd=Value(v);break;case 8:P.cell_x=Value(v);break;case 9:P.cell_y=Value(v);break;case 10:P.cell_font_flag=(uchar)v;break;case 11:P.closed_star=(uchar)v;break;case 12:P.rows_ready=(uchar)v;break;case 13:P.closed[0]=Value(v);break;case 14:P.closed[1]=Value(v);break;case 15:P.closed[2]=Value(v);break;case 16:P.closed[3]=Value(v);break;case 17:P.closed[4]=Value(v);break;case 18:P.closed[5]=Value(v);break;case 19:P.closed[6]=Value(v);break;case 20:P.closed[7]=Value(v);break;case 21:P.closed[8]=Value(v);break;case 22:P.per_trade[0]=Value(v);break;case 23:P.per_trade[1]=Value(v);break;case 24:P.per_trade[2]=Value(v);break;case 25:P.per_trade[3]=Value(v);break;case 26:P.per_trade[4]=Value(v);break;case 27:P.per_trade[5]=Value(v);break;case 28:P.per_trade[6]=Value(v);break;case 29:P.per_trade[7]=Value(v);break;case 30:P.per_trade[8]=Value(v);break;case 31:P.lots[0]=Value(v);break;case 32:P.lots[1]=Value(v);break;case 33:P.lots[2]=Value(v);break;case 34:P.lots[3]=Value(v);break;case 35:P.lots[4]=Value(v);break;case 36:P.lots[5]=Value(v);break;case 37:P.lots[6]=Value(v);break;case 38:P.lots[7]=Value(v);break;case 39:P.lots[8]=Value(v);break;case 40:Events.nfp=(long)v;break;case 41:Events.interest=(long)v;break;case 42:Events.cpi=(long)v;break;case 43:Windows.nfp_enabled=(uchar)v;break;case 44:Windows.interest_enabled=(uchar)v;break;case 45:Windows.cpi_enabled=(uchar)v;break;case 46:Windows.nfp_after=(int)v;break;case 47:Windows.interest_after=(int)v;break;case 48:Windows.cpi_after=(int)v;break;case 49:Selection.block_time=(long)v;break;case 51:Index=(uint)v;break;case 52:StartLots=Value(v);break;case 53:Calendar.hour=(int)v;break;case 54:LastHour=(int)v;break;case 55:Show=(uchar)v;break;case 56:Tester=(uchar)v;break;case 57:HistoryWindow=(uchar)v;break;case 58:Magic=(int)v;break;case 59:Seed=(int)v;break;case 60:Balance=Value(v);break;case 61:LastTicket=v;break;case 62:Wins=Value(v);break;case 63:Losses=Value(v);break;case 70:State.flag_744a0=(uchar)v;break;case 71:BarTimes[0]=(long)v;break;case 72:BarTimes[1]=(long)v;break;case 73:BarTimes[2]=(long)v;break;case 74:BarTimes[3]=(long)v;break;case 75:BarTimes[4]=(long)v;break;case 76:BarTimes[5]=(long)v;break;case 77:BarTimes[6]=(long)v;break;case 78:BarTimes[7]=(long)v;break;case 79:BarTimes[8]=(long)v;break;}}}
long MockSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();End(1,(ulong)prop,2,0,symbol);Effect(1);return 2;}
int MockInfo(const ENUM_MQL_INFO_INTEGER prop){Begin();End(2,(ulong)prop,(ulong)(long)InfoReply);Effect(2);return InfoReply;}
bool MockSelect(const datetime from,const datetime to){Begin();End(3,(ulong)from,(ulong)to,(ulong)SelectReply);Effect(3);return SelectReply!=0;}
int MockTotal(){Begin();End(4,(ulong)(long)TotalReply);Effect(4);return TotalReply;}
ulong MockTicket(const int index){Begin();Selected=index;ulong v=index>=0 && index<DealCount ? Deals[index][0] : 0;End(5,(ulong)(long)index,v);Effect(5);return v;}
datetime MockTime(){Begin();long v=Times[Counts[6]%8];End(6,(ulong)v);Effect(6);return (datetime)v;}
long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop){Begin();long v=Selected>=0 && Selected<DealCount ? (long)Deals[Selected][prop==2 ? 1 : 2] : 0;End(7,ticket,(ulong)prop,(ulong)v);Effect(7);return v;}
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop){Begin();double v=Selected>=0 && Selected<DealCount ? Value(Deals[Selected][3]) : 0.;End(8,ticket,(ulong)prop,Bits(v));Effect(8);return v;}
void MockCreate(Bot3PanelCreationState &p,const Bot3NewsEvents &events,const Bot3NewsWindows &windows,Bot3NewsSelection &selection){Begin();End(20);Word((ulong)(long)p.font);
Word(Bits(p.scale));
Word((ulong)(long)p.color_flag);
Word((ulong)(long)p.mode);
Word(Bits(p.strategy_risk));
Word((ulong)(long)p.frequency);
Word(Bits(p.manual_lots));
Word(Bits(p.allowed_dd));
Word(Bits(p.cell_x));
Word(Bits(p.cell_y));
Word((ulong)(long)p.cell_font_flag);
Word((ulong)(long)p.closed_star);
Word((ulong)(long)p.rows_ready);
Word(Bits(p.closed[0]));
Word(Bits(p.closed[1]));
Word(Bits(p.closed[2]));
Word(Bits(p.closed[3]));
Word(Bits(p.closed[4]));
Word(Bits(p.closed[5]));
Word(Bits(p.closed[6]));
Word(Bits(p.closed[7]));
Word(Bits(p.closed[8]));
Word(Bits(p.per_trade[0]));
Word(Bits(p.per_trade[1]));
Word(Bits(p.per_trade[2]));
Word(Bits(p.per_trade[3]));
Word(Bits(p.per_trade[4]));
Word(Bits(p.per_trade[5]));
Word(Bits(p.per_trade[6]));
Word(Bits(p.per_trade[7]));
Word(Bits(p.per_trade[8]));
Word(Bits(p.lots[0]));
Word(Bits(p.lots[1]));
Word(Bits(p.lots[2]));
Word(Bits(p.lots[3]));
Word(Bits(p.lots[4]));
Word(Bits(p.lots[5]));
Word(Bits(p.lots[6]));
Word(Bits(p.lots[7]));
Word(Bits(p.lots[8]));
Word((ulong)(long)events.nfp);
Word((ulong)(long)events.interest);
Word((ulong)(long)events.cpi);
Word((ulong)(long)windows.nfp_enabled);
Word((ulong)(long)windows.interest_enabled);
Word((ulong)(long)windows.cpi_enabled);
Word((ulong)(long)windows.nfp_after);
Word((ulong)(long)windows.interest_after);
Word((ulong)(long)windows.cpi_after);
Word((ulong)(long)selection.block_time);
Text(selection.label); Effect(20);}
void MockOpen(const uchar &show,const uchar &tester,const int &seed,const string &symbol,const double &balance,const int &frequency,
              const uint &mode,const double &manual_lots,const double &allowed_dd,const double &strategy_risk,const Bot3NewsEvents &events,
              const Bot3NewsWindows &windows,Bot3NewsSelection &selection,ulong &ticket){Begin();End(21);Word((ulong)(long)show);
Word((ulong)(long)tester);
Word((ulong)(long)seed);
Text(symbol);
Word(Bits(balance));
Word((ulong)(long)frequency);
Word((ulong)(long)mode);
Word(Bits(manual_lots));
Word(Bits(allowed_dd));
Word(Bits(strategy_risk));
Word((ulong)(long)events.nfp);
Word((ulong)(long)events.interest);
Word((ulong)(long)events.cpi);
Word((ulong)(long)windows.nfp_enabled);
Word((ulong)(long)windows.interest_enabled);
Word((ulong)(long)windows.cpi_enabled);
Word((ulong)(long)windows.nfp_after);
Word((ulong)(long)windows.interest_after);
Word((ulong)(long)windows.cpi_after);
Word((ulong)(long)selection.block_time);
Text(selection.label);
Word((ulong)(long)ticket); Effect(21);}
void MockClosed(const uchar &show,const uchar &tester,const int &seed,const string &symbol,double &wins,double &losses){Begin();End(22);Word((ulong)(long)show);
Word((ulong)(long)tester);
Word((ulong)(long)seed);
Text(symbol);
Word(Bits(wins));
Word(Bits(losses)); Effect(22);}
int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-startup-tail\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x54414931 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),tapes=FileOpen(folder+"sdk-tape.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE || tapes==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);FileWriteInteger(tapes,magic);FileWriteInteger(tapes,version);FileWriteInteger(tapes,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);P.font=(int)FileReadLong(file);
P.scale=Value((ulong)FileReadLong(file));
P.color_flag=(uchar)FileReadLong(file);
P.mode=(uint)FileReadLong(file);
P.strategy_risk=Value((ulong)FileReadLong(file));
P.frequency=(int)FileReadLong(file);
P.manual_lots=Value((ulong)FileReadLong(file));
P.allowed_dd=Value((ulong)FileReadLong(file));
P.cell_x=Value((ulong)FileReadLong(file));
P.cell_y=Value((ulong)FileReadLong(file));
P.cell_font_flag=(uchar)FileReadLong(file);
P.closed_star=(uchar)FileReadLong(file);
P.rows_ready=(uchar)FileReadLong(file);
P.closed[0]=Value((ulong)FileReadLong(file));
P.closed[1]=Value((ulong)FileReadLong(file));
P.closed[2]=Value((ulong)FileReadLong(file));
P.closed[3]=Value((ulong)FileReadLong(file));
P.closed[4]=Value((ulong)FileReadLong(file));
P.closed[5]=Value((ulong)FileReadLong(file));
P.closed[6]=Value((ulong)FileReadLong(file));
P.closed[7]=Value((ulong)FileReadLong(file));
P.closed[8]=Value((ulong)FileReadLong(file));
P.per_trade[0]=Value((ulong)FileReadLong(file));
P.per_trade[1]=Value((ulong)FileReadLong(file));
P.per_trade[2]=Value((ulong)FileReadLong(file));
P.per_trade[3]=Value((ulong)FileReadLong(file));
P.per_trade[4]=Value((ulong)FileReadLong(file));
P.per_trade[5]=Value((ulong)FileReadLong(file));
P.per_trade[6]=Value((ulong)FileReadLong(file));
P.per_trade[7]=Value((ulong)FileReadLong(file));
P.per_trade[8]=Value((ulong)FileReadLong(file));
P.lots[0]=Value((ulong)FileReadLong(file));
P.lots[1]=Value((ulong)FileReadLong(file));
P.lots[2]=Value((ulong)FileReadLong(file));
P.lots[3]=Value((ulong)FileReadLong(file));
P.lots[4]=Value((ulong)FileReadLong(file));
P.lots[5]=Value((ulong)FileReadLong(file));
P.lots[6]=Value((ulong)FileReadLong(file));
P.lots[7]=Value((ulong)FileReadLong(file));
P.lots[8]=Value((ulong)FileReadLong(file));
Events.nfp=FileReadLong(file);
Events.interest=FileReadLong(file);
Events.cpi=FileReadLong(file);
Windows.nfp_enabled=(uchar)FileReadLong(file);
Windows.interest_enabled=(uchar)FileReadLong(file);
Windows.cpi_enabled=(uchar)FileReadLong(file);
Windows.nfp_after=(int)FileReadLong(file);
Windows.interest_after=(int)FileReadLong(file);
Windows.cpi_after=(int)FileReadLong(file);
Selection.block_time=FileReadLong(file);
Selection.label=ReadText(file);
Index=(uint)FileReadLong(file);
StartLots=Value((ulong)FileReadLong(file));
Calendar.hour=(int)FileReadLong(file);
LastHour=(int)FileReadLong(file);
Show=(uchar)FileReadLong(file);
Tester=(uchar)FileReadLong(file);
HistoryWindow=(uchar)FileReadLong(file);
Magic=(int)FileReadLong(file);
Seed=(int)FileReadLong(file);
Balance=Value((ulong)FileReadLong(file));
LastTicket=(ulong)FileReadLong(file);
Wins=Value((ulong)FileReadLong(file));
Losses=Value((ulong)FileReadLong(file));
TradeComment=ReadText(file);
TradeSymbol=ReadText(file);
State.buy_first=ReadText(file);
State.buy_second=ReadText(file);
State.sell_first=ReadText(file);
State.sell_second=ReadText(file);
State.flag_744a0=(uchar)FileReadLong(file);
BarTimes[0]=FileReadLong(file);
BarTimes[1]=FileReadLong(file);
BarTimes[2]=FileReadLong(file);
BarTimes[3]=FileReadLong(file);
BarTimes[4]=FileReadLong(file);
BarTimes[5]=FileReadLong(file);
BarTimes[6]=FileReadLong(file);
BarTimes[7]=FileReadLong(file);
BarTimes[8]=FileReadLong(file);
      InfoReply=FileReadInteger(file);SelectReply=FileReadInteger(file);TotalReply=FileReadInteger(file);DealCount=FileReadInteger(file);if(DealCount<0 || DealCount>32)return 8;
      for(int i=0;i<DealCount;i++)for(int j=0;j<4;j++)Deals[i][j]=(ulong)FileReadLong(file);
      for(int i=0;i<8;i++)Times[i]=FileReadLong(file);EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>32)return 8;
      for(int i=0;i<EffectCount;i++)for(int j=0;j<4;j++)Effects[i][j]=(ulong)FileReadLong(file);
      ArrayInitialize(Counts,0);Selected=-1;string part=folder+"tape-"+IntegerToString(id)+".bin";Tape=FileOpen(part,FILE_WRITE|FILE_BIN);if(Tape==INVALID_HANDLE)return 5;
      ResetLastError();ErrorOverride=-1;Final=false;
      Result=Bot3InitializeStartupTail(TradeComment,TradeSymbol,Index,StartLots,Calendar,BarTimes,Show,Tester,HistoryWindow,Magic,Seed,Balance,P,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,State);
      int error=GetLastError();FileClose(Tape);int section=FileOpen(part,FILE_READ|FILE_BIN);if(section==INVALID_HANDLE)return 6;int size=(int)FileSize(section);uchar raw[];ArrayResize(raw,size);if(size>0)FileReadArray(section,raw);FileClose(section);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0)FileWriteArray(tapes,raw);
      FileWriteInteger(output,id);Tape=output;ErrorOverride=error;Final=true;Begin();
   }
   if(FileTell(file)!=FileSize(file))return 9;FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
