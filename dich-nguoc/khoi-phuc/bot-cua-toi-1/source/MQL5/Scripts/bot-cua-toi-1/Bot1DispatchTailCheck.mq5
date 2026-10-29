#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1PanelCreation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1StartupTail.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ClosedStatusPanel.mqh"
void MockCreate(Bot1PanelCreationState &p,const Bot1NewsEvents &events,const Bot1NewsWindows &windows,Bot1NewsSelection &selection);
void MockOpen(const uchar &show,const uchar &tester,const int &seed,const string &symbol,const double &balance,const double &volume,
              const int &mode,const double &risk,const double &strategy_risk,const int &step,const Bot1NewsEvents &events,
              const Bot1NewsWindows &windows,Bot1NewsSelection &selection,ulong &ticket);
void MockClosed(const uchar &show,const uchar &tester,const int &seed,const string &symbol,double &wins,double &losses);
long MockSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);int MockInfo(const ENUM_MQL_INFO_INTEGER prop);
bool MockSelect(const datetime from,const datetime to);int MockTotal();ulong MockTicket(const int index);
datetime MockTime();long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop);
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop);
#define Bot1CreateInfoPanel MockCreate
#define Bot1UpdateOpenStatusPanel MockOpen
#define Bot1UpdateClosedStatusPanel MockClosed
#define SymbolInfoInteger MockSymbol
#define MQLInfoInteger MockInfo
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define TimeCurrent MockTime
#define HistoryDealGetInteger MockDealInteger
#define HistoryDealGetDouble MockDealDouble
datetime TailBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
double TailBalance(const ENUM_ACCOUNT_INFO_DOUBLE property);
string TailDouble(const double value,const int digits=8);
string TailInteger(const long value,const int width=0,const ushort fill=32);
bool TailObject(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value);
#define iTime TailBar
#define AccountInfoDouble TailBalance
#define DoubleToString TailDouble
#define IntegerToString TailInteger
#define ObjectSetString TailObject
#include "../../Include/bot-cua-toi-1/Bot1DispatchTail.mqh"
#undef iTime
#undef AccountInfoDouble
#undef DoubleToString
#undef IntegerToString
#undef ObjectSetString
#undef Bot1CreateInfoPanel
#undef Bot1UpdateOpenStatusPanel
#undef Bot1UpdateClosedStatusPanel
#undef SymbolInfoInteger
#undef MQLInfoInteger
#undef HistorySelect
#undef HistoryDealsTotal
#undef HistoryDealGetTicket
#undef TimeCurrent
#undef HistoryDealGetInteger
#undef HistoryDealGetDouble
Bot1PanelCreationState P;Bot1NewsEvents Events;Bot1NewsWindows Windows;Bot1NewsSelection Selection;Bot1StartupTailState State;
MqlDateTime Calendar;uint Index;double StartLots,Balance,Wins,Losses;int LastHour,Magic,Seed;uchar Show,Tester,HistoryWindow;
string TradeComment,TradeSymbol;ulong LastTicket;long BarTimes[8];
union Number{double value;ulong word;};
ulong Bits(const double v){Number n;n.value=v;return n.word;}double Value(const ulong v){Number n;n.word=v;return n.value;}
long PreviousM5;int BalanceCalls;double CachedBalance,BankReply;int ObjectReply,ObjectError;uint LogicalError;
int Tape,ErrorOverride=-1,Counts[28],InfoReply,SelectReply,TotalReply,DealCount,Selected,EffectCount,Result;
ulong Deals[32][4],Effects[32][4];long Times[8];bool Final=false;
void Word(const ulong v){FileWriteLong(Tape,(long)v);}
void Text(const string v){int n=v==NULL ? -1 : StringLen(v);FileWriteInteger(Tape,n);if(n>0)FileWriteString(Tape,v,n);}
string ReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
void Snapshot(){Word((ulong)(long)P.font);
Word(Bits(P.scale));
Word((ulong)(long)P.color_flag);
Word((ulong)(long)P.mode);
Word(Bits(P.strategy_risk));
Word(Bits(P.trade_risk));
Word((ulong)(long)P.balance_step);
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
Word(Bits(P.per_trade[0]));
Word(Bits(P.per_trade[1]));
Word(Bits(P.per_trade[2]));
Word(Bits(P.per_trade[3]));
Word(Bits(P.per_trade[4]));
Word(Bits(P.per_trade[5]));
Word(Bits(P.per_trade[6]));
Word(Bits(P.per_trade[7]));
Word(Bits(P.lots[0]));
Word(Bits(P.lots[1]));
Word(Bits(P.lots[2]));
Word(Bits(P.lots[3]));
Word(Bits(P.lots[4]));
Word(Bits(P.lots[5]));
Word(Bits(P.lots[6]));
Word(Bits(P.lots[7]));
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
Word((ulong)(long)BarTimes[0]);
Word((ulong)(long)BarTimes[1]);
Word((ulong)(long)BarTimes[2]);
Word((ulong)(long)BarTimes[3]);
Word((ulong)(long)BarTimes[4]);
Word((ulong)(long)BarTimes[5]);
Word((ulong)(long)BarTimes[6]);
Word((ulong)(long)BarTimes[7]);
Word((ulong)(long)PreviousM5);
Word((ulong)(long)BalanceCalls);
Word(Bits(CachedBalance)); Word(ErrorOverride<0 ? LogicalError : (uint)ErrorOverride);if(Final)Word((ulong)(long)Result);}
void Begin(){ulong at=FileTell(Tape);FileWriteInteger(Tape,0);Snapshot();ulong end=FileTell(Tape);FileSeek(Tape,(long)at,SEEK_SET);FileWriteInteger(Tape,(int)(end-at-4));FileSeek(Tape,(long)end,SEEK_SET);}
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const string value=NULL){FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Text(value);FileWriteInteger(Tape,(int)LogicalError);}
void Effect(const int api){int n=++Counts[api];for(int i=0;i<EffectCount;i++){if((int)Effects[i][0]!=api || (int)Effects[i][1]!=n)continue;ulong v=Effects[i][3];switch((int)Effects[i][2]){case 0:P.font=(int)v;break;case 1:P.scale=Value(v);break;case 2:P.color_flag=(uchar)v;break;case 3:P.mode=(int)v;break;case 4:P.strategy_risk=Value(v);break;case 5:P.trade_risk=Value(v);break;case 6:P.balance_step=(int)v;break;case 7:P.cell_x=Value(v);break;case 8:P.cell_y=Value(v);break;case 9:P.cell_font_flag=(uchar)v;break;case 10:P.closed_star=(uchar)v;break;case 11:P.rows_ready=(uchar)v;break;case 12:P.closed[0]=Value(v);break;case 13:P.closed[1]=Value(v);break;case 14:P.closed[2]=Value(v);break;case 15:P.closed[3]=Value(v);break;case 16:P.closed[4]=Value(v);break;case 17:P.closed[5]=Value(v);break;case 18:P.closed[6]=Value(v);break;case 19:P.closed[7]=Value(v);break;case 20:P.per_trade[0]=Value(v);break;case 21:P.per_trade[1]=Value(v);break;case 22:P.per_trade[2]=Value(v);break;case 23:P.per_trade[3]=Value(v);break;case 24:P.per_trade[4]=Value(v);break;case 25:P.per_trade[5]=Value(v);break;case 26:P.per_trade[6]=Value(v);break;case 27:P.per_trade[7]=Value(v);break;case 28:P.lots[0]=Value(v);break;case 29:P.lots[1]=Value(v);break;case 30:P.lots[2]=Value(v);break;case 31:P.lots[3]=Value(v);break;case 32:P.lots[4]=Value(v);break;case 33:P.lots[5]=Value(v);break;case 34:P.lots[6]=Value(v);break;case 35:P.lots[7]=Value(v);break;case 36:Events.nfp=(long)v;break;case 37:Events.interest=(long)v;break;case 38:Events.cpi=(long)v;break;case 39:Windows.nfp_enabled=(uchar)v;break;case 40:Windows.interest_enabled=(uchar)v;break;case 41:Windows.cpi_enabled=(uchar)v;break;case 42:Windows.nfp_after=(int)v;break;case 43:Windows.interest_after=(int)v;break;case 44:Windows.cpi_after=(int)v;break;case 45:Selection.block_time=(long)v;break;case 47:Index=(uint)v;break;case 48:StartLots=Value(v);break;case 49:Calendar.hour=(int)v;break;case 50:LastHour=(int)v;break;case 51:Show=(uchar)v;break;case 52:Tester=(uchar)v;break;case 53:HistoryWindow=(uchar)v;break;case 54:Magic=(int)v;break;case 55:Seed=(int)v;break;case 56:Balance=Value(v);break;case 57:LastTicket=v;break;case 58:Wins=Value(v);break;case 59:Losses=Value(v);break;case 66:BarTimes[0]=(long)v;break;case 67:BarTimes[1]=(long)v;break;case 68:BarTimes[2]=(long)v;break;case 69:BarTimes[3]=(long)v;break;case 70:BarTimes[4]=(long)v;break;case 71:BarTimes[5]=(long)v;break;case 72:BarTimes[6]=(long)v;break;case 73:BarTimes[7]=(long)v;break;case 74:PreviousM5=(long)v;break;case 75:BalanceCalls=(int)v;break;case 76:CachedBalance=Value(v);break;}}}
long MockSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();End(1,(ulong)prop,2,0,symbol);Effect(1);return 2;}
int MockInfo(const ENUM_MQL_INFO_INTEGER prop){Begin();End(2,(ulong)prop,(ulong)(long)InfoReply);Effect(2);return InfoReply;}
bool MockSelect(const datetime from,const datetime to){Begin();End(3,(ulong)from,(ulong)to,(ulong)SelectReply);Effect(3);return SelectReply!=0;}
int MockTotal(){Begin();End(4,(ulong)(long)TotalReply);Effect(4);return TotalReply;}
ulong MockTicket(const int index){Begin();Selected=index;ulong v=index>=0 && index<DealCount ? Deals[index][0] : 0;End(5,(ulong)(long)index,v);Effect(5);return v;}
datetime MockTime(){Begin();long v=Times[Counts[6]%8];End(6,(ulong)v);Effect(6);return (datetime)v;}
long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop){Begin();long v=Selected>=0 && Selected<DealCount ? (long)Deals[Selected][prop==2 ? 1 : 2] : 0;End(7,ticket,(ulong)prop,(ulong)v);Effect(7);return v;}
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop){Begin();double v=Selected>=0 && Selected<DealCount ? Value(Deals[Selected][3]) : 0.;End(8,ticket,(ulong)prop,Bits(v));Effect(8);return v;}
void MockCreate(Bot1PanelCreationState &p,const Bot1NewsEvents &events,const Bot1NewsWindows &windows,Bot1NewsSelection &selection){Begin();End(20);Word((ulong)(long)p.font);
Word(Bits(p.scale));
Word((ulong)(long)p.color_flag);
Word((ulong)(long)p.mode);
Word(Bits(p.strategy_risk));
Word(Bits(p.trade_risk));
Word((ulong)(long)p.balance_step);
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
Word(Bits(p.per_trade[0]));
Word(Bits(p.per_trade[1]));
Word(Bits(p.per_trade[2]));
Word(Bits(p.per_trade[3]));
Word(Bits(p.per_trade[4]));
Word(Bits(p.per_trade[5]));
Word(Bits(p.per_trade[6]));
Word(Bits(p.per_trade[7]));
Word(Bits(p.lots[0]));
Word(Bits(p.lots[1]));
Word(Bits(p.lots[2]));
Word(Bits(p.lots[3]));
Word(Bits(p.lots[4]));
Word(Bits(p.lots[5]));
Word(Bits(p.lots[6]));
Word(Bits(p.lots[7]));
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
void MockOpen(const uchar &show,const uchar &tester,const int &seed,const string &symbol,const double &balance,const double &volume,
              const int &mode,const double &risk,const double &strategy_risk,const int &step,const Bot1NewsEvents &events,
              const Bot1NewsWindows &windows,Bot1NewsSelection &selection,ulong &ticket){Begin();End(21);Word((ulong)(long)show);
Word((ulong)(long)tester);
Word((ulong)(long)seed);
Text(symbol);
Word(Bits(balance));
Word(Bits(volume));
Word((ulong)(long)mode);
Word(Bits(risk));
Word(Bits(strategy_risk));
Word((ulong)(long)step);
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
datetime TailBar(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();long value=Times[Counts[23]%8];End(23,(ulong)frame,(ulong)(long)shift,(ulong)value,symbol);Effect(23);return (datetime)value;}
double TailBalance(const ENUM_ACCOUNT_INFO_DOUBLE property){Begin();double value=BankReply;End(24,(ulong)property,Bits(value));Effect(24);return value;}
string TailDouble(const double value,const int digits){Begin();string result=DoubleToString(value,digits);End(25,Bits(value),(ulong)(long)digits,0,result);Effect(25);return result;}
string TailInteger(const long value,const int width,const ushort fill){Begin();string result=IntegerToString(value,width,fill);End(26,(ulong)value,(ulong)(long)width,(ulong)fill,result);Effect(26);return result;}
bool TailObject(const long chart,const string name,const ENUM_OBJECT_PROPERTY_STRING property,const string value){Begin();LogicalError=(uint)ObjectError;End(27,(ulong)chart,(ulong)property,(ulong)ObjectReply,name);Text(value);Effect(27);return ObjectReply!=0;}

int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-dispatch-tail\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x54414931 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),tapes=FileOpen(folder+"sdk-tape.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE || tapes==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);FileWriteInteger(tapes,magic);FileWriteInteger(tapes,version);FileWriteInteger(tapes,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);P.font=(int)FileReadLong(file);
P.scale=Value((ulong)FileReadLong(file));
P.color_flag=(uchar)FileReadLong(file);
P.mode=(int)FileReadLong(file);
P.strategy_risk=Value((ulong)FileReadLong(file));
P.trade_risk=Value((ulong)FileReadLong(file));
P.balance_step=(int)FileReadLong(file);
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
P.per_trade[0]=Value((ulong)FileReadLong(file));
P.per_trade[1]=Value((ulong)FileReadLong(file));
P.per_trade[2]=Value((ulong)FileReadLong(file));
P.per_trade[3]=Value((ulong)FileReadLong(file));
P.per_trade[4]=Value((ulong)FileReadLong(file));
P.per_trade[5]=Value((ulong)FileReadLong(file));
P.per_trade[6]=Value((ulong)FileReadLong(file));
P.per_trade[7]=Value((ulong)FileReadLong(file));
P.lots[0]=Value((ulong)FileReadLong(file));
P.lots[1]=Value((ulong)FileReadLong(file));
P.lots[2]=Value((ulong)FileReadLong(file));
P.lots[3]=Value((ulong)FileReadLong(file));
P.lots[4]=Value((ulong)FileReadLong(file));
P.lots[5]=Value((ulong)FileReadLong(file));
P.lots[6]=Value((ulong)FileReadLong(file));
P.lots[7]=Value((ulong)FileReadLong(file));
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
BarTimes[0]=FileReadLong(file);
BarTimes[1]=FileReadLong(file);
BarTimes[2]=FileReadLong(file);
BarTimes[3]=FileReadLong(file);
BarTimes[4]=FileReadLong(file);
BarTimes[5]=FileReadLong(file);
BarTimes[6]=FileReadLong(file);
BarTimes[7]=FileReadLong(file);
PreviousM5=FileReadLong(file);
BalanceCalls=(int)FileReadLong(file);
CachedBalance=Value((ulong)FileReadLong(file));
      InfoReply=FileReadInteger(file);SelectReply=FileReadInteger(file);TotalReply=FileReadInteger(file);DealCount=FileReadInteger(file);if(DealCount<0 || DealCount>32)return 8;
      for(int i=0;i<DealCount;i++)for(int j=0;j<4;j++)Deals[i][j]=(ulong)FileReadLong(file);
      for(int i=0;i<8;i++)Times[i]=FileReadLong(file);EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>32)return 8;
      for(int i=0;i<EffectCount;i++)for(int j=0;j<4;j++)Effects[i][j]=(ulong)FileReadLong(file);
      BankReply=Value((ulong)FileReadLong(file));ObjectReply=FileReadInteger(file);ObjectError=FileReadInteger(file);LogicalError=0;ArrayInitialize(Counts,0);Selected=-1;string part=folder+"tape-"+IntegerToString(id)+".bin";Tape=FileOpen(part,FILE_WRITE|FILE_BIN);if(Tape==INVALID_HANDLE)return 5;
      ResetLastError();ErrorOverride=-1;Final=false;
      Bot1FinishDispatch(Show,Tester,Seed,TradeSymbol,Balance,P,Events,Windows,Selection,LastTicket,Wins,Losses,PreviousM5,BalanceCalls,CachedBalance);Result=0;
      int error=(int)LogicalError;FileClose(Tape);int section=FileOpen(part,FILE_READ|FILE_BIN);if(section==INVALID_HANDLE)return 6;int size=(int)FileSize(section);uchar raw[];ArrayResize(raw,size);if(size>0)FileReadArray(section,raw);FileClose(section);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0)FileWriteArray(tapes,raw);
      FileWriteInteger(output,id);Tape=output;ErrorOverride=error;Final=true;Begin();
   }
   if(FileTell(file)!=FileSize(file))return 9;FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
