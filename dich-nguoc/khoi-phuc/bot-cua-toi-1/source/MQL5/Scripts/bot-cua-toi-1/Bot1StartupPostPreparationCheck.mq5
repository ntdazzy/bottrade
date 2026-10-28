#property strict
input string CheckRun="";
#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1EntryLoop.mqh"
#include "../../Include/bot-cua-toi-1/Bot1EntryLevelCache.mqh"
#include "../../Include/bot-cua-toi-1/Bot1PositionManagement.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ReleaseFilters.mqh"
#include "../../Include/bot-cua-toi-1/Bot1PanelCreation.mqh"
#include "../../Include/bot-cua-toi-1/Bot1ClosedStatusPanel.mqh"
Bot1PreparationInputs Inputs;Bot1PreparationState P;Bot1EntryLoopState Entry;Bot1PositionManagementState Manager;
Bot1NfpFilterState Nfp;Bot1ReleaseFilterState Interest,Cpi;Bot1PendingQueue Queue;Bot1LevelCacheSettings Levels;
int Magic;double MinimumSpread;uchar FridayClosed;ulong LastTicket;
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
void MockCreate(Bot1PanelCreationState &p,const Bot1NewsEvents &events,const Bot1NewsWindows &windows,Bot1NewsSelection &selection);
void MockOpen(const uchar &show,const uchar &tester,const int &seed,const string &symbol,const double &balance,const double &volume,
              const int &mode,const double &risk,const double &strategy_risk,const int &step,const Bot1NewsEvents &events,
              const Bot1NewsWindows &windows,Bot1NewsSelection &selection,ulong &ticket);
void MockClosed(const uchar &show,const uchar &tester,const int &seed,const string &symbol,double &wins,double &losses);
long MockTailSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);int MockInfo(const ENUM_MQL_INFO_INTEGER prop);
bool MockSelect(const datetime from,const datetime to);int MockTotal();ulong MockTicket(const int index);
datetime MockTailTime();long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop);
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop);
#define Bot1CreateInfoPanel MockCreate
#define Bot1UpdateOpenStatusPanel MockOpen
#define Bot1UpdateClosedStatusPanel MockClosed
#define SymbolInfoInteger MockTailSymbol
#define MQLInfoInteger MockInfo
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define TimeCurrent MockTailTime
#define HistoryDealGetInteger MockDealInteger
#define HistoryDealGetDouble MockDealDouble
#include "../../Include/bot-cua-toi-1/Bot1StartupTail.mqh"
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
#include "../../Include/bot-cua-toi-1/Bot1StartupPostPreparation.mqh"
Bot1PanelCreationState Panel;Bot1NewsEvents Events;Bot1NewsWindows Windows;Bot1NewsSelection Selection;Bot1StartupTailState TailState;
int Seed,LastHour;double Balance,Wins,Losses;uchar Show,Tester,HistoryWindow;long TailBars[8];
Bot1StartupTradingState State;
int Tape,ErrorOverride=-1,Counts[23],DPos[4],IPos[3];bool Final=false;
double Doubles[4][8],AccountReply,LevelReply[2];long Integers[3][8],Times[8],BarsReply[2],BarTimes[3];ulong Effects[32][4];int EffectCount;
void Word(const ulong v){FileWriteLong(Tape,(long)v);}
void Text(const string v){int n=v==NULL ? -1 : StringLen(v);FileWriteInteger(Tape,n);if(n>0)FileWriteString(Tape,v,n);}
string ReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
ulong TablesHash(){ulong h=0xcbf29ce484222325;for(int i=0;i<500;i++)for(int j=0;j<3;j++)h=(h^Bits(Manager.table.rows[i][j]))*0x100000001b3;for(int i=0;i<100;i++)for(int j=0;j<3;j++)h=(h^Bits(Queue.orders[i][j]))*0x100000001b3;return h;}

int InfoReply,SelectReply,TotalReply,DealCount,Selected,Result;ulong Deals[32][4];long TailTimes[8];

void Snapshot(){
Word((ulong)(long)P.native_62414);
Word((ulong)(long)State.native_62555);
Word((ulong)(long)P.strategy_index);
Word((ulong)(long)P.entry_frame);
Word((ulong)(long)P.native_6248c);
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
Word((ulong)(long)P.freeze_buffer);
Word(Bits(P.trail_distance));
Word(Bits(P.native_624f8));
Word(Bits(P.native_62500));
Word(Bits(P.gap_points));
Word((ulong)(long)P.older_width);
Word((ulong)(long)P.recent_width);
Word((ulong)(long)P.expiration_hours);
Word((ulong)(long)P.virtual_expiration);
Word((ulong)(long)P.expiration_seconds);
Word((ulong)(long)P.expiration);
Word((ulong)(long)Nfp.notice);
Word((ulong)(long)Nfp.blocked);
Word((ulong)(long)Interest.blocked);
Word((ulong)(long)Cpi.blocked);
Word((ulong)(long)State.week_bar);
Word(Bits(P.max_spread));
Word(Bits(MinimumSpread));
Word((ulong)(long)Inputs.entry.confirmation_frame);
Word((ulong)(long)Magic);
Word((ulong)(long)P.last_shift);
Word(Bits(P.buy_offset));
Word(Bits(P.sell_offset));
Word(Bits(P.nearby_radius));
Word((ulong)(long)LastTicket);
Word(Bits(Entry.candidate_buy));
Word(Bits(Entry.candidate_sell));
Word(Bits(Entry.rounded_buy));
Word(Bits(Entry.rounded_sell));
Word((ulong)(long)Levels.blocked);
Word((ulong)(long)Manager.counter);
Word((ulong)(long)State.timed_delay_seconds);
Word(Bits(Manager.current_stop));
Word(Bits(P.native_62538));
Word((ulong)(long)Manager.table.guard);
Word((ulong)(long)Queue.enabled);
Word((ulong)(long)FridayClosed);
Word((ulong)(long)Panel.font);
Word(Bits(Panel.scale));
Word((ulong)(long)Panel.color_flag);
Word((ulong)(long)Panel.mode);
Word(Bits(Panel.strategy_risk));
Word(Bits(Panel.trade_risk));
Word((ulong)(long)Panel.balance_step);
Word(Bits(Panel.cell_x));
Word(Bits(Panel.cell_y));
Word((ulong)(long)Panel.cell_font_flag);
Word((ulong)(long)Panel.closed_star);
Word((ulong)(long)Panel.rows_ready);
Word(Bits(Panel.closed[0]));
Word(Bits(Panel.closed[1]));
Word(Bits(Panel.closed[2]));
Word(Bits(Panel.closed[3]));
Word(Bits(Panel.closed[4]));
Word(Bits(Panel.closed[5]));
Word(Bits(Panel.closed[6]));
Word(Bits(Panel.closed[7]));
Word(Bits(Panel.per_trade[0]));
Word(Bits(Panel.per_trade[1]));
Word(Bits(Panel.per_trade[2]));
Word(Bits(Panel.per_trade[3]));
Word(Bits(Panel.per_trade[4]));
Word(Bits(Panel.per_trade[5]));
Word(Bits(Panel.per_trade[6]));
Word(Bits(Panel.per_trade[7]));
Word(Bits(Panel.lots[0]));
Word(Bits(Panel.lots[1]));
Word(Bits(Panel.lots[2]));
Word(Bits(Panel.lots[3]));
Word(Bits(Panel.lots[4]));
Word(Bits(Panel.lots[5]));
Word(Bits(Panel.lots[6]));
Word(Bits(Panel.lots[7]));
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
Word((ulong)(long)P.calendar.hour);
Word((ulong)(long)LastHour);
Word((ulong)(long)Show);
Word((ulong)(long)Tester);
Word((ulong)(long)HistoryWindow);
Word((ulong)(long)Seed);
Word(Bits(Balance));
Word(Bits(Wins));
Word(Bits(Losses));
Text(P.comment);
Text(Inputs.symbol);
Text(TailState.buy_first);
Text(TailState.buy_second);
Text(TailState.sell_first);
Text(TailState.sell_second);
Word((ulong)(long)TailBars[0]);
Word((ulong)(long)TailBars[1]);
Word((ulong)(long)TailBars[2]);
Word((ulong)(long)TailBars[3]);
Word((ulong)(long)TailBars[4]);
Word((ulong)(long)TailBars[5]);
Word((ulong)(long)TailBars[6]);
Word((ulong)(long)TailBars[7]);
Word(TablesHash());Word(ErrorOverride<0 ? GetLastError() : (uint)ErrorOverride);
if(Final){for(int i=0;i<500;i++)for(int j=0;j<3;j++)Word(Bits(Manager.table.rows[i][j]));for(int i=0;i<100;i++)for(int j=0;j<3;j++)Word(Bits(Queue.orders[i][j]));Word((ulong)(long)Result);}}
void Begin(){ulong at=FileTell(Tape);FileWriteInteger(Tape,0);Snapshot();ulong end=FileTell(Tape);FileSeek(Tape,(long)at,SEEK_SET);FileWriteInteger(Tape,(int)(end-at-4));FileSeek(Tape,(long)end,SEEK_SET);}
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,const string t=NULL,const string u=NULL){FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Word(d);Text(t);Text(u);FileWriteInteger(Tape,(int)GetLastError());}
void Effect(const int api){int n=++Counts[api];for(int i=0;i<EffectCount;i++){if((int)Effects[i][0]!=api || (int)Effects[i][1]!=n)continue;ulong v=Effects[i][3];switch((int)Effects[i][2]){case 0:P.native_62414=(int)v;break;case 1:State.native_62555=(uchar)v;break;case 2:P.strategy_index=(uint)v;break;case 3:P.entry_frame=(int)v;break;case 4:P.native_6248c=(int)v;break;case 5:P.tick.ask=Value(v);break;case 6:P.tick.bid=Value(v);break;case 7:P.spread=Value(v);break;case 8:P.native_62530=Value(v);break;case 9:P.unit=Value(v);break;case 10:P.min_change=Value(v);break;case 11:P.stop_min_price=Value(v);break;case 12:P.freeze_min_price=Value(v);break;case 13:P.stop_distance=Value(v);break;case 14:P.target_distance=Value(v);break;case 15:P.trigger_distance=Value(v);break;case 16:P.locked_distance=Value(v);break;case 17:P.freeze_buffer=(int)v;break;case 18:P.trail_distance=Value(v);break;case 19:P.native_624f8=Value(v);break;case 20:P.native_62500=Value(v);break;case 21:P.gap_points=Value(v);break;case 22:P.older_width=(int)v;break;case 23:P.recent_width=(int)v;break;case 24:P.expiration_hours=(int)v;break;case 25:P.virtual_expiration=(uchar)v;break;case 26:P.expiration_seconds=(uint)v;break;case 27:P.expiration=(long)v;break;case 28:Nfp.notice=(uchar)v;break;case 29:Nfp.blocked=(uchar)v;break;case 30:Interest.blocked=(uchar)v;break;case 31:Cpi.blocked=(uchar)v;break;case 32:State.week_bar=(long)v;break;case 33:P.max_spread=Value(v);break;case 34:MinimumSpread=Value(v);break;case 35:Inputs.entry.confirmation_frame=(int)v;break;case 36:Magic=(int)v;break;case 37:P.last_shift=(int)v;break;case 38:P.buy_offset=Value(v);break;case 39:P.sell_offset=Value(v);break;case 40:P.nearby_radius=Value(v);break;case 41:LastTicket=v;break;case 42:Entry.candidate_buy=Value(v);break;case 43:Entry.candidate_sell=Value(v);break;case 44:Entry.rounded_buy=Value(v);break;case 45:Entry.rounded_sell=Value(v);break;case 46:Levels.blocked=(uchar)v;break;case 47:Manager.counter=(int)v;break;case 48:State.timed_delay_seconds=(int)v;break;case 49:Manager.current_stop=Value(v);break;case 50:P.native_62538=Value(v);break;case 51:Manager.table.guard=(uchar)v;break;case 52:Queue.enabled=(uchar)v;break;case 53:FridayClosed=(uchar)v;break;case 54:Panel.font=(int)v;break;case 55:Panel.scale=Value(v);break;case 56:Panel.color_flag=(uchar)v;break;case 57:Panel.mode=(int)v;break;case 58:Panel.strategy_risk=Value(v);break;case 59:Panel.trade_risk=Value(v);break;case 60:Panel.balance_step=(int)v;break;case 61:Panel.cell_x=Value(v);break;case 62:Panel.cell_y=Value(v);break;case 63:Panel.cell_font_flag=(uchar)v;break;case 64:Panel.closed_star=(uchar)v;break;case 65:Panel.rows_ready=(uchar)v;break;case 66:Panel.closed[0]=Value(v);break;case 67:Panel.closed[1]=Value(v);break;case 68:Panel.closed[2]=Value(v);break;case 69:Panel.closed[3]=Value(v);break;case 70:Panel.closed[4]=Value(v);break;case 71:Panel.closed[5]=Value(v);break;case 72:Panel.closed[6]=Value(v);break;case 73:Panel.closed[7]=Value(v);break;case 74:Panel.per_trade[0]=Value(v);break;case 75:Panel.per_trade[1]=Value(v);break;case 76:Panel.per_trade[2]=Value(v);break;case 77:Panel.per_trade[3]=Value(v);break;case 78:Panel.per_trade[4]=Value(v);break;case 79:Panel.per_trade[5]=Value(v);break;case 80:Panel.per_trade[6]=Value(v);break;case 81:Panel.per_trade[7]=Value(v);break;case 82:Panel.lots[0]=Value(v);break;case 83:Panel.lots[1]=Value(v);break;case 84:Panel.lots[2]=Value(v);break;case 85:Panel.lots[3]=Value(v);break;case 86:Panel.lots[4]=Value(v);break;case 87:Panel.lots[5]=Value(v);break;case 88:Panel.lots[6]=Value(v);break;case 89:Panel.lots[7]=Value(v);break;case 90:Events.nfp=(long)v;break;case 91:Events.interest=(long)v;break;case 92:Events.cpi=(long)v;break;case 93:Windows.nfp_enabled=(uchar)v;break;case 94:Windows.interest_enabled=(uchar)v;break;case 95:Windows.cpi_enabled=(uchar)v;break;case 96:Windows.nfp_after=(int)v;break;case 97:Windows.interest_after=(int)v;break;case 98:Windows.cpi_after=(int)v;break;case 99:Selection.block_time=(long)v;break;case 101:P.calendar.hour=(int)v;break;case 102:LastHour=(int)v;break;case 103:Show=(uchar)v;break;case 104:Tester=(uchar)v;break;case 105:HistoryWindow=(uchar)v;break;case 106:Seed=(int)v;break;case 107:Balance=Value(v);break;case 108:Wins=Value(v);break;case 109:Losses=Value(v);break;case 116:TailBars[0]=(long)v;break;case 117:TailBars[1]=(long)v;break;case 118:TailBars[2]=(long)v;break;case 119:TailBars[3]=(long)v;break;case 120:TailBars[4]=(long)v;break;case 121:TailBars[5]=(long)v;break;case 122:TailBars[6]=(long)v;break;case 123:TailBars[7]=(long)v;break;}}}
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
long MockTailSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();End(16,(ulong)prop,2,0,0,symbol);Effect(16);return 2;}
int MockInfo(const ENUM_MQL_INFO_INTEGER prop){Begin();End(10,(ulong)prop,(ulong)(long)InfoReply);Effect(10);return InfoReply;}
bool MockSelect(const datetime from,const datetime to){Begin();End(11,(ulong)from,(ulong)to,(ulong)SelectReply);Effect(11);return SelectReply!=0;}
int MockTotal(){Begin();End(12,(ulong)(long)TotalReply);Effect(12);return TotalReply;}
ulong MockTicket(const int index){Begin();Selected=index;ulong v=index>=0 && index<DealCount ? Deals[index][0] : 0;End(13,(ulong)(long)index,v);Effect(13);return v;}
datetime MockTailTime(){Begin();long v=TailTimes[Counts[17]%8];End(17,(ulong)v);Effect(17);return (datetime)v;}
long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop){Begin();long v=Selected>=0 && Selected<DealCount ? (long)Deals[Selected][prop==2 ? 1 : 2] : 0;End(14,ticket,(ulong)prop,(ulong)v);Effect(14);return v;}
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop){Begin();double v=Selected>=0 && Selected<DealCount ? Value(Deals[Selected][3]) : 0.;End(15,ticket,(ulong)prop,Bits(v));Effect(15);return v;}
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

int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-startup-joined\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x4a4f4931 || version!=1 || count<1)return 3;
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
Panel.font=(int)FileReadLong(file);
Panel.scale=Value((ulong)FileReadLong(file));
Panel.color_flag=(uchar)FileReadLong(file);
Panel.mode=(int)FileReadLong(file);
Panel.strategy_risk=Value((ulong)FileReadLong(file));
Panel.trade_risk=Value((ulong)FileReadLong(file));
Panel.balance_step=(int)FileReadLong(file);
Panel.cell_x=Value((ulong)FileReadLong(file));
Panel.cell_y=Value((ulong)FileReadLong(file));
Panel.cell_font_flag=(uchar)FileReadLong(file);
Panel.closed_star=(uchar)FileReadLong(file);
Panel.rows_ready=(uchar)FileReadLong(file);
Panel.closed[0]=Value((ulong)FileReadLong(file));
Panel.closed[1]=Value((ulong)FileReadLong(file));
Panel.closed[2]=Value((ulong)FileReadLong(file));
Panel.closed[3]=Value((ulong)FileReadLong(file));
Panel.closed[4]=Value((ulong)FileReadLong(file));
Panel.closed[5]=Value((ulong)FileReadLong(file));
Panel.closed[6]=Value((ulong)FileReadLong(file));
Panel.closed[7]=Value((ulong)FileReadLong(file));
Panel.per_trade[0]=Value((ulong)FileReadLong(file));
Panel.per_trade[1]=Value((ulong)FileReadLong(file));
Panel.per_trade[2]=Value((ulong)FileReadLong(file));
Panel.per_trade[3]=Value((ulong)FileReadLong(file));
Panel.per_trade[4]=Value((ulong)FileReadLong(file));
Panel.per_trade[5]=Value((ulong)FileReadLong(file));
Panel.per_trade[6]=Value((ulong)FileReadLong(file));
Panel.per_trade[7]=Value((ulong)FileReadLong(file));
Panel.lots[0]=Value((ulong)FileReadLong(file));
Panel.lots[1]=Value((ulong)FileReadLong(file));
Panel.lots[2]=Value((ulong)FileReadLong(file));
Panel.lots[3]=Value((ulong)FileReadLong(file));
Panel.lots[4]=Value((ulong)FileReadLong(file));
Panel.lots[5]=Value((ulong)FileReadLong(file));
Panel.lots[6]=Value((ulong)FileReadLong(file));
Panel.lots[7]=Value((ulong)FileReadLong(file));
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
P.calendar.hour=(int)FileReadLong(file);
LastHour=(int)FileReadLong(file);
Show=(uchar)FileReadLong(file);
Tester=(uchar)FileReadLong(file);
HistoryWindow=(uchar)FileReadLong(file);
Seed=(int)FileReadLong(file);
Balance=Value((ulong)FileReadLong(file));
Wins=Value((ulong)FileReadLong(file));
Losses=Value((ulong)FileReadLong(file));
P.comment=ReadText(file);
Inputs.symbol=ReadText(file);
TailState.buy_first=ReadText(file);
TailState.buy_second=ReadText(file);
TailState.sell_first=ReadText(file);
TailState.sell_second=ReadText(file);
TailBars[0]=FileReadLong(file);
TailBars[1]=FileReadLong(file);
TailBars[2]=FileReadLong(file);
TailBars[3]=FileReadLong(file);
TailBars[4]=FileReadLong(file);
TailBars[5]=FileReadLong(file);
TailBars[6]=FileReadLong(file);
TailBars[7]=FileReadLong(file);

      for(int i=0;i<4;i++)for(int j=0;j<8;j++)Doubles[i][j]=Value((ulong)FileReadLong(file));
      for(int i=0;i<3;i++)for(int j=0;j<8;j++)Integers[i][j]=FileReadLong(file);
      for(int i=0;i<8;i++)Times[i]=FileReadLong(file);for(int i=0;i<2;i++)BarsReply[i]=FileReadLong(file);for(int i=0;i<3;i++)BarTimes[i]=FileReadLong(file);
      AccountReply=Value((ulong)FileReadLong(file));for(int i=0;i<2;i++)LevelReply[i]=Value((ulong)FileReadLong(file));
      EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>32)return 8;for(int i=0;i<EffectCount;i++)for(int j=0;j<4;j++)Effects[i][j]=(ulong)FileReadLong(file);
      InfoReply=FileReadInteger(file);SelectReply=FileReadInteger(file);TotalReply=FileReadInteger(file);DealCount=FileReadInteger(file);if(DealCount<0 || DealCount>32)return 8;
      for(int i=0;i<DealCount;i++)for(int j=0;j<4;j++)Deals[i][j]=(ulong)FileReadLong(file);
      for(int i=0;i<8;i++)TailTimes[i]=FileReadLong(file);Selected=-1;
      for(int i=0;i<500;i++)for(int j=0;j<3;j++)Manager.table.rows[i][j]=(double)(3*i+j+1)*.125;
      for(int i=0;i<100;i++)for(int j=0;j<3;j++)Queue.orders[i][j]=(double)(3*i+j+1)*.25;
      ArrayInitialize(Counts,0);ArrayInitialize(DPos,0);ArrayInitialize(IPos,0);string part=folder+"tape-"+IntegerToString(id)+".bin";Tape=FileOpen(part,FILE_WRITE|FILE_BIN);if(Tape==INVALID_HANDLE)return 5;
      ResetLastError();Final=false;ErrorOverride=-1;
      Result=Bot1InitializeStartupPostPreparation(Inputs,P,Magic,Entry,Nfp,Interest,Cpi,Manager,Queue,Levels,MinimumSpread,FridayClosed,TailBars,Show,Tester,HistoryWindow,Seed,Balance,Panel,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,State,TailState);
      int error=GetLastError();FileClose(Tape);int section=FileOpen(part,FILE_READ|FILE_BIN);if(section==INVALID_HANDLE)return 6;int size=(int)FileSize(section);uchar raw[];ArrayResize(raw,size);if(size>0)FileReadArray(section,raw);FileClose(section);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0)FileWriteArray(tapes,raw);
      FileWriteInteger(output,id);Tape=output;Final=true;ErrorOverride=error;Begin();
   }
   if(FileTell(file)!=FileSize(file))return 9;FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
