#property strict
input string CheckRun="";

int PrepATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period);
int PrepCopy(const int handle,const int buffer,const int start,const int count,double &values[]);
bool PrepTick(const string symbol,MqlTick &tick);
datetime PrepTime(MqlDateTime &calendar);datetime PrepTime();
double PrepDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop);
long PrepInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);
void PrepPrint(const string value);void PrepPrint(const string value,const int error);
#define iATR PrepATR
#define CopyBuffer PrepCopy
#define SymbolInfoTick PrepTick
#define TimeCurrent PrepTime
#define SymbolInfoDouble PrepDouble
#define SymbolInfoInteger PrepInteger
#define Print PrepPrint
#include "../../Include/bot-cua-toi-1/Bot1Preparation.mqh"
#undef iATR
#undef CopyBuffer
#undef SymbolInfoTick
#undef TimeCurrent
#undef SymbolInfoDouble
#undef SymbolInfoInteger
#undef Print

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
#include "../../Include/bot-cua-toi-1/Bot1StartupPreparationFlow.mqh"
Bot1PanelCreationState Panel;Bot1NewsEvents Events;Bot1NewsWindows Windows;Bot1NewsSelection Selection;Bot1StartupTailState TailState;
int Seed,LastHour;double Balance,Wins,Losses;uchar Show,Tester,HistoryWindow;long TailBars[8];string OrderComment;
Bot1StartupTradingState State;
int Tape,ErrorOverride=-1,Counts[38],DPos[4],IPos[3];bool Final=false;
double Doubles[4][8],AccountReply,LevelReply[2];long Integers[3][8],Times[8],BarsReply[2],BarTimes[3];ulong Effects[32][4];int EffectCount;
void Word(const ulong v){FileWriteLong(Tape,(long)v);}
void Text(const string v){int n=v==NULL ? -1 : StringLen(v);FileWriteInteger(Tape,n);if(n>0)FileWriteString(Tape,v,n);}
string ReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
ulong TablesHash(){ulong h=0xcbf29ce484222325;for(int i=0;i<500;i++)for(int j=0;j<3;j++)h=(h^Bits(Manager.table.rows[i][j]))*0x100000001b3;for(int i=0;i<100;i++)for(int j=0;j<3;j++)h=(h^Bits(Queue.orders[i][j]))*0x100000001b3;return h;}

int InfoReply,SelectReply,TotalReply,DealCount,Selected,Result;ulong Deals[32][4];long TailTimes[8];

void PrepArraySnapshot();
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
Text(P.comment);
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
Text(OrderComment);
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
Word((ulong)(long)Inputs.indicator_period);
Word((ulong)(long)Inputs.indicator_day);
Word(Bits(Inputs.reference));
Word((ulong)(long)Inputs.variable_distances);
Word((ulong)(long)Inputs.adjust_lots);
Word(Bits(Inputs.max_spread));
Word((ulong)(long)Inputs.feature_flag);
Word((ulong)(long)Inputs.freeze_buffer_flag);
Word((ulong)(long)Inputs.entry.hour1_flag);
Word((ulong)(long)Inputs.entry.older_width);
Word((ulong)(long)Inputs.entry.recent_width);
Word((ulong)(long)Inputs.entry.last_shift);
Word(Bits(Inputs.entry.gap_points));
Word(Bits(Inputs.buy_offset));
Word(Bits(Inputs.sell_offset));
Word(Bits(Inputs.nearby_radius));
Word((ulong)(long)Inputs.expiration_hours);
Word((ulong)(long)Inputs.virtual_expiration);
Word(Bits(Inputs.stop_distance));
Word(Bits(Inputs.target_distance));
Word(Bits(Inputs.trail_distance));
Word(Bits(Inputs.trail_start));
Word(Bits(Inputs.trail_limit));
Word(Bits(Inputs.trail_step));
Word((ulong)(long)Inputs.aux_hour1);
Word((ulong)(long)Inputs.aux_scan50);
Word((ulong)(long)Inputs.aux_older);
Word((ulong)(long)Inputs.aux_recent);
Word(Bits(Inputs.aux_offset));
Word(Bits(Inputs.min_change));
Word(Bits(Inputs.native_62218));
Word((ulong)(long)Inputs.native_62220);
Word(Bits(Inputs.native_62228));
Word(Bits(Inputs.native_62230));
Word(Bits(Inputs.native_62238));
Word((ulong)(long)Inputs.native_62240);
Word((ulong)(long)Inputs.native_6a5d8);
Word((ulong)(long)Inputs.omit_real_sl_tp);
Word((ulong)(long)Inputs.virtual_stops);
Word((ulong)(long)Inputs.native_6a608);
Word((ulong)(long)Inputs.check_free_margin);
Word((ulong)(long)Inputs.native_62268);
Word((ulong)(long)Inputs.native_622a8);
Word((ulong)(long)Inputs.native_622ec);
Word((ulong)(long)Inputs.native_622f0);
Word(Bits(Inputs.native_62390));
Word((ulong)(long)Inputs.native_62398);
Word(Bits(Inputs.native_623a8));
Word(Bits(Inputs.native_6a740));
Word(Bits(Inputs.native_623b0));
Text(Inputs.comment);
Word(Bits(P.scale));
Word(Bits(P.lot_scale));
Word((ulong)(long)P.feature_flag);
Word(Bits(P.trail_start));
Word(Bits(P.trail_limit));
Word(Bits(P.trail_step));
Word((ulong)(long)P.aux_frame);
Word((ulong)(long)P.aux_scan);
Word((ulong)(long)P.aux_older);
Word((ulong)(long)P.aux_recent);
Word(Bits(P.aux_offset));
Word(Bits(P.native_623e8));
Word((ulong)(long)P.native_623f0);
Word(Bits(P.native_623f8));
Word(Bits(P.native_62400));
Word(Bits(P.native_62408));
Word((ulong)(long)P.native_62410);
Word((ulong)(long)P.omit_real_sl_tp);
Word((ulong)(long)P.mode);
Word((ulong)(long)P.native_62420);
Word((ulong)(long)P.check_free_margin);
Word((ulong)(long)P.native_62428);
Word((ulong)(long)P.native_62458);
Word((ulong)(long)P.native_62490);
Word(Bits(P.native_62510));
Word((ulong)(long)P.native_62518);
Word(Bits(P.native_62528));
Word((ulong)(long)P.native_62540);
Word(Bits(P.native_62548));
Word((ulong)(long)P.native_62550);
Word((ulong)(long)P.native_624d8);
Word((ulong)(long)P.native_624ec);
Word((ulong)(long)P.native_62508);
Word(Bits(P.point));
Word((ulong)(long)P.indicator_handle);
Word((ulong)(long)P.tick.time);
Word(Bits(P.tick.last));
Word((ulong)(long)P.tick.volume);
Word((ulong)(long)P.tick.time_msc);
Word((ulong)(long)P.tick.flags);
Word(Bits(P.tick.volume_real));
Word((ulong)(long)P.calendar.year);
Word((ulong)(long)P.calendar.mon);
Word((ulong)(long)P.calendar.day);
Word((ulong)(long)P.calendar.min);
Word((ulong)(long)P.calendar.sec);
Word((ulong)(long)P.calendar.day_of_week);
Word((ulong)(long)P.calendar.day_of_year);
PrepArraySnapshot();Word(TablesHash());Word(ErrorOverride<0 ? GetLastError() : (uint)ErrorOverride);
if(Final){for(int i=0;i<500;i++)for(int j=0;j<3;j++)Word(Bits(Manager.table.rows[i][j]));for(int i=0;i<100;i++)for(int j=0;j<3;j++)Word(Bits(Queue.orders[i][j]));Word((ulong)(long)Result);}}
void Begin(){ulong at=FileTell(Tape);FileWriteInteger(Tape,0);Snapshot();ulong end=FileTell(Tape);FileSeek(Tape,(long)at,SEEK_SET);FileWriteInteger(Tape,(int)(end-at-4));FileSeek(Tape,(long)end,SEEK_SET);}
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,const string t=NULL,const string u=NULL){FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Word(d);Text(t);Text(u);FileWriteInteger(Tape,(int)GetLastError());}
void Effect(const int api){int n=++Counts[api];for(int i=0;i<EffectCount;i++){if((int)Effects[i][0]!=api || (int)Effects[i][1]!=n)continue;ulong v=Effects[i][3];switch((int)Effects[i][2]){case 0:P.native_62414=(int)v;break;case 1:State.native_62555=(uchar)v;break;case 2:P.strategy_index=(uint)v;break;case 3:P.entry_frame=(int)v;break;case 4:P.native_6248c=(int)v;break;case 5:P.tick.ask=Value(v);break;case 6:P.tick.bid=Value(v);break;case 7:P.spread=Value(v);break;case 8:P.native_62530=Value(v);break;case 9:P.unit=Value(v);break;case 10:P.min_change=Value(v);break;case 11:P.stop_min_price=Value(v);break;case 12:P.freeze_min_price=Value(v);break;case 13:P.stop_distance=Value(v);break;case 14:P.target_distance=Value(v);break;case 15:P.trigger_distance=Value(v);break;case 16:P.locked_distance=Value(v);break;case 17:P.freeze_buffer=(int)v;break;case 18:P.trail_distance=Value(v);break;case 19:P.native_624f8=Value(v);break;case 20:P.native_62500=Value(v);break;case 21:P.gap_points=Value(v);break;case 22:P.older_width=(int)v;break;case 23:P.recent_width=(int)v;break;case 24:P.expiration_hours=(int)v;break;case 25:P.virtual_expiration=(uchar)v;break;case 26:P.expiration_seconds=(uint)v;break;case 27:P.expiration=(long)v;break;case 28:Nfp.notice=(uchar)v;break;case 29:Nfp.blocked=(uchar)v;break;case 30:Interest.blocked=(uchar)v;break;case 31:Cpi.blocked=(uchar)v;break;case 32:State.week_bar=(long)v;break;case 33:P.max_spread=Value(v);break;case 34:MinimumSpread=Value(v);break;case 35:Inputs.entry.confirmation_frame=(int)v;break;case 36:Magic=(int)v;break;case 37:P.last_shift=(int)v;break;case 38:P.buy_offset=Value(v);break;case 39:P.sell_offset=Value(v);break;case 40:P.nearby_radius=Value(v);break;case 41:LastTicket=v;break;case 42:Entry.candidate_buy=Value(v);break;case 43:Entry.candidate_sell=Value(v);break;case 44:Entry.rounded_buy=Value(v);break;case 45:Entry.rounded_sell=Value(v);break;case 46:Levels.blocked=(uchar)v;break;case 47:Manager.counter=(int)v;break;case 48:State.timed_delay_seconds=(int)v;break;case 49:Manager.current_stop=Value(v);break;case 50:P.native_62538=Value(v);break;case 51:Manager.table.guard=(uchar)v;break;case 52:Queue.enabled=(uchar)v;break;case 53:FridayClosed=(uchar)v;break;case 55:Panel.font=(int)v;break;case 56:Panel.scale=Value(v);break;case 57:Panel.color_flag=(uchar)v;break;case 58:Panel.mode=(int)v;break;case 59:Panel.strategy_risk=Value(v);break;case 60:Panel.trade_risk=Value(v);break;case 61:Panel.balance_step=(int)v;break;case 62:Panel.cell_x=Value(v);break;case 63:Panel.cell_y=Value(v);break;case 64:Panel.cell_font_flag=(uchar)v;break;case 65:Panel.closed_star=(uchar)v;break;case 66:Panel.rows_ready=(uchar)v;break;case 67:Panel.closed[0]=Value(v);break;case 68:Panel.closed[1]=Value(v);break;case 69:Panel.closed[2]=Value(v);break;case 70:Panel.closed[3]=Value(v);break;case 71:Panel.closed[4]=Value(v);break;case 72:Panel.closed[5]=Value(v);break;case 73:Panel.closed[6]=Value(v);break;case 74:Panel.closed[7]=Value(v);break;case 75:Panel.per_trade[0]=Value(v);break;case 76:Panel.per_trade[1]=Value(v);break;case 77:Panel.per_trade[2]=Value(v);break;case 78:Panel.per_trade[3]=Value(v);break;case 79:Panel.per_trade[4]=Value(v);break;case 80:Panel.per_trade[5]=Value(v);break;case 81:Panel.per_trade[6]=Value(v);break;case 82:Panel.per_trade[7]=Value(v);break;case 83:Panel.lots[0]=Value(v);break;case 84:Panel.lots[1]=Value(v);break;case 85:Panel.lots[2]=Value(v);break;case 86:Panel.lots[3]=Value(v);break;case 87:Panel.lots[4]=Value(v);break;case 88:Panel.lots[5]=Value(v);break;case 89:Panel.lots[6]=Value(v);break;case 90:Panel.lots[7]=Value(v);break;case 91:Events.nfp=(long)v;break;case 92:Events.interest=(long)v;break;case 93:Events.cpi=(long)v;break;case 94:Windows.nfp_enabled=(uchar)v;break;case 95:Windows.interest_enabled=(uchar)v;break;case 96:Windows.cpi_enabled=(uchar)v;break;case 97:Windows.nfp_after=(int)v;break;case 98:Windows.interest_after=(int)v;break;case 99:Windows.cpi_after=(int)v;break;case 100:Selection.block_time=(long)v;break;case 102:P.calendar.hour=(int)v;break;case 103:LastHour=(int)v;break;case 104:Show=(uchar)v;break;case 105:Tester=(uchar)v;break;case 106:HistoryWindow=(uchar)v;break;case 107:Seed=(int)v;break;case 108:Balance=Value(v);break;case 109:Wins=Value(v);break;case 110:Losses=Value(v);break;case 117:TailBars[0]=(long)v;break;case 118:TailBars[1]=(long)v;break;case 119:TailBars[2]=(long)v;break;case 120:TailBars[3]=(long)v;break;case 121:TailBars[4]=(long)v;break;case 122:TailBars[5]=(long)v;break;case 123:TailBars[6]=(long)v;break;case 124:TailBars[7]=(long)v;break;case 125:Inputs.indicator_period=(int)v;break;case 126:Inputs.indicator_day=(uchar)v;break;case 127:Inputs.reference=Value(v);break;case 128:Inputs.variable_distances=(uchar)v;break;case 129:Inputs.adjust_lots=(uchar)v;break;case 130:Inputs.max_spread=Value(v);break;case 131:Inputs.feature_flag=(uchar)v;break;case 132:Inputs.freeze_buffer_flag=(uchar)v;break;case 133:Inputs.entry.hour1_flag=(uchar)v;break;case 134:Inputs.entry.older_width=(int)v;break;case 135:Inputs.entry.recent_width=(int)v;break;case 136:Inputs.entry.last_shift=(int)v;break;case 137:Inputs.entry.gap_points=Value(v);break;case 138:Inputs.buy_offset=Value(v);break;case 139:Inputs.sell_offset=Value(v);break;case 140:Inputs.nearby_radius=Value(v);break;case 141:Inputs.expiration_hours=(int)v;break;case 142:Inputs.virtual_expiration=(uchar)v;break;case 143:Inputs.stop_distance=Value(v);break;case 144:Inputs.target_distance=Value(v);break;case 145:Inputs.trail_distance=Value(v);break;case 146:Inputs.trail_start=Value(v);break;case 147:Inputs.trail_limit=Value(v);break;case 148:Inputs.trail_step=Value(v);break;case 149:Inputs.aux_hour1=(uchar)v;break;case 150:Inputs.aux_scan50=(uchar)v;break;case 151:Inputs.aux_older=(int)v;break;case 152:Inputs.aux_recent=(int)v;break;case 153:Inputs.aux_offset=Value(v);break;case 154:Inputs.min_change=Value(v);break;case 155:Inputs.native_62218=Value(v);break;case 156:Inputs.native_62220=(uchar)v;break;case 157:Inputs.native_62228=Value(v);break;case 158:Inputs.native_62230=Value(v);break;case 159:Inputs.native_62238=Value(v);break;case 160:Inputs.native_62240=(uchar)v;break;case 161:Inputs.native_6a5d8=(int)v;break;case 162:Inputs.omit_real_sl_tp=(uchar)v;break;case 163:Inputs.virtual_stops=(uchar)v;break;case 164:Inputs.native_6a608=(int)v;break;case 165:Inputs.check_free_margin=(uchar)v;break;case 166:Inputs.native_62268=(uchar)v;break;case 167:Inputs.native_622a8=(uchar)v;break;case 168:Inputs.native_622ec=(int)v;break;case 169:Inputs.native_622f0=(uchar)v;break;case 170:Inputs.native_62390=Value(v);break;case 171:Inputs.native_62398=(uchar)v;break;case 172:Inputs.native_623a8=Value(v);break;case 173:Inputs.native_6a740=Value(v);break;case 174:Inputs.native_623b0=Value(v);break;case 176:P.scale=Value(v);break;case 177:P.lot_scale=Value(v);break;case 178:P.feature_flag=(uchar)v;break;case 179:P.trail_start=Value(v);break;case 180:P.trail_limit=Value(v);break;case 181:P.trail_step=Value(v);break;case 182:P.aux_frame=(int)v;break;case 183:P.aux_scan=(int)v;break;case 184:P.aux_older=(int)v;break;case 185:P.aux_recent=(int)v;break;case 186:P.aux_offset=Value(v);break;case 187:P.native_623e8=Value(v);break;case 188:P.native_623f0=(int)v;break;case 189:P.native_623f8=Value(v);break;case 190:P.native_62400=Value(v);break;case 191:P.native_62408=Value(v);break;case 192:P.native_62410=(uchar)v;break;case 193:P.omit_real_sl_tp=(uchar)v;break;case 194:P.mode=(int)v;break;case 195:P.native_62420=(int)v;break;case 196:P.check_free_margin=(uchar)v;break;case 197:P.native_62428=(int)v;break;case 198:P.native_62458=(int)v;break;case 199:P.native_62490=(uchar)v;break;case 200:P.native_62510=Value(v);break;case 201:P.native_62518=(int)v;break;case 202:P.native_62528=Value(v);break;case 203:P.native_62540=(int)v;break;case 204:P.native_62548=Value(v);break;case 205:P.native_62550=(int)v;break;case 206:P.native_624d8=(uchar)v;break;case 207:P.native_624ec=(uchar)v;break;case 208:P.native_62508=(uchar)v;break;case 209:P.point=Value(v);break;case 210:P.indicator_handle=(int)v;break;case 211:P.tick.time=(datetime)v;break;case 212:P.tick.last=Value(v);break;case 213:P.tick.volume=v;break;case 214:P.tick.time_msc=(long)v;break;case 215:P.tick.flags=(uint)v;break;case 216:P.tick.volume_real=Value(v);break;case 217:P.calendar.year=(int)v;break;case 218:P.calendar.mon=(int)v;break;case 219:P.calendar.day=(int)v;break;case 220:P.calendar.min=(int)v;break;case 221:P.calendar.sec=(int)v;break;case 222:P.calendar.day_of_week=(int)v;break;case 223:P.calendar.day_of_year=(int)v;break;}}}
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


int PrepHandle,PrepCopied,PrepCount,PrepTickOk,PrepTickWrite,PrepHour,PrepDPos,PrepIPos[3];double PrepSample;long PrepNow;
void PrepArraySnapshot(){int n=ArraySize(P.indicator_values);Word((ulong)n);Word((ulong)ArrayGetAsSeries(P.indicator_values));for(int i=0;i<n;i++)Word(Bits(P.indicator_values[i]));}
int PrepATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period){Begin();End(30,(ulong)frame,(ulong)(long)period,(ulong)(long)PrepHandle,0,symbol);Effect(30);return PrepHandle;}
int PrepCopy(const int handle,const int buffer,const int start,const int count,double &values[]){Begin();End(31,(ulong)(long)handle,(ulong)(long)buffer,(ulong)(long)start,(ulong)(long)count);Word((ulong)(long)PrepCopied);Word((ulong)PrepCount);Word(Bits(PrepSample));if(PrepCopied!=0){ArraySetAsSeries(values,false);ArrayResize(values,PrepCount);for(int i=0;i<PrepCount;i++)values[i]=PrepSample+(double)i*.125;}Effect(31);return PrepCopied;}
bool PrepTick(const string symbol,MqlTick &tick){Begin();End(32,(ulong)PrepTickOk,(ulong)PrepTickWrite,0,0,symbol);if(PrepTickWrite!=0){tick.time=(datetime)PrepNow;tick.bid=2000.;tick.ask=2002.;tick.last=2001.;tick.volume=31;tick.time_msc=PrepNow*1000;tick.flags=7;tick.volume_real=31.5;}Effect(32);return PrepTickOk!=0;}
datetime PrepTime(MqlDateTime &calendar){Begin();End(33,(ulong)PrepNow,(ulong)(long)PrepHour);calendar.year=2026;calendar.mon=10;calendar.day=28;calendar.hour=PrepHour;calendar.min=17;calendar.sec=19;calendar.day_of_week=3;calendar.day_of_year=300;Effect(33);return (datetime)PrepNow;}
datetime PrepTime(){Begin();End(36,(ulong)PrepNow);Effect(36);return (datetime)PrepNow;}
double PrepDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop){Begin();int n=PrepDPos++;double value=Doubles[0][n<8 ? n : 7];End(34,(ulong)prop,Bits(value),0,0,symbol);Effect(34);return value;}
long PrepInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();int p=prop==SYMBOL_TRADE_STOPS_LEVEL ? 0 : (prop==SYMBOL_TRADE_FREEZE_LEVEL ? 1 : 2);int n=PrepIPos[p]++;long value=Integers[p][n<8 ? n : 7];End(35,(ulong)prop,(ulong)value,0,0,symbol);Effect(35);return value;}
void PrepPrint(const string value){Begin();End(37,1,0,0,0,value);Effect(37);}
void PrepPrint(const string value,const int error){Begin();End(37,2,(ulong)(long)error,0,0,value);Effect(37);}

int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot1-startup-preparation-flow\\"+CheckRun+"\\";
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
P.comment=ReadText(file);
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
OrderComment=ReadText(file);
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
Inputs.indicator_period=(int)FileReadLong(file);
Inputs.indicator_day=(uchar)FileReadLong(file);
Inputs.reference=Value((ulong)FileReadLong(file));
Inputs.variable_distances=(uchar)FileReadLong(file);
Inputs.adjust_lots=(uchar)FileReadLong(file);
Inputs.max_spread=Value((ulong)FileReadLong(file));
Inputs.feature_flag=(uchar)FileReadLong(file);
Inputs.freeze_buffer_flag=(uchar)FileReadLong(file);
Inputs.entry.hour1_flag=(uchar)FileReadLong(file);
Inputs.entry.older_width=(int)FileReadLong(file);
Inputs.entry.recent_width=(int)FileReadLong(file);
Inputs.entry.last_shift=(int)FileReadLong(file);
Inputs.entry.gap_points=Value((ulong)FileReadLong(file));
Inputs.buy_offset=Value((ulong)FileReadLong(file));
Inputs.sell_offset=Value((ulong)FileReadLong(file));
Inputs.nearby_radius=Value((ulong)FileReadLong(file));
Inputs.expiration_hours=(int)FileReadLong(file);
Inputs.virtual_expiration=(uchar)FileReadLong(file);
Inputs.stop_distance=Value((ulong)FileReadLong(file));
Inputs.target_distance=Value((ulong)FileReadLong(file));
Inputs.trail_distance=Value((ulong)FileReadLong(file));
Inputs.trail_start=Value((ulong)FileReadLong(file));
Inputs.trail_limit=Value((ulong)FileReadLong(file));
Inputs.trail_step=Value((ulong)FileReadLong(file));
Inputs.aux_hour1=(uchar)FileReadLong(file);
Inputs.aux_scan50=(uchar)FileReadLong(file);
Inputs.aux_older=(int)FileReadLong(file);
Inputs.aux_recent=(int)FileReadLong(file);
Inputs.aux_offset=Value((ulong)FileReadLong(file));
Inputs.min_change=Value((ulong)FileReadLong(file));
Inputs.native_62218=Value((ulong)FileReadLong(file));
Inputs.native_62220=(uchar)FileReadLong(file);
Inputs.native_62228=Value((ulong)FileReadLong(file));
Inputs.native_62230=Value((ulong)FileReadLong(file));
Inputs.native_62238=Value((ulong)FileReadLong(file));
Inputs.native_62240=(uchar)FileReadLong(file);
Inputs.native_6a5d8=(int)FileReadLong(file);
Inputs.omit_real_sl_tp=(uchar)FileReadLong(file);
Inputs.virtual_stops=(uchar)FileReadLong(file);
Inputs.native_6a608=(int)FileReadLong(file);
Inputs.check_free_margin=(uchar)FileReadLong(file);
Inputs.native_62268=(uchar)FileReadLong(file);
Inputs.native_622a8=(uchar)FileReadLong(file);
Inputs.native_622ec=(int)FileReadLong(file);
Inputs.native_622f0=(uchar)FileReadLong(file);
Inputs.native_62390=Value((ulong)FileReadLong(file));
Inputs.native_62398=(uchar)FileReadLong(file);
Inputs.native_623a8=Value((ulong)FileReadLong(file));
Inputs.native_6a740=Value((ulong)FileReadLong(file));
Inputs.native_623b0=Value((ulong)FileReadLong(file));
Inputs.comment=ReadText(file);
P.scale=Value((ulong)FileReadLong(file));
P.lot_scale=Value((ulong)FileReadLong(file));
P.feature_flag=(uchar)FileReadLong(file);
P.trail_start=Value((ulong)FileReadLong(file));
P.trail_limit=Value((ulong)FileReadLong(file));
P.trail_step=Value((ulong)FileReadLong(file));
P.aux_frame=(int)FileReadLong(file);
P.aux_scan=(int)FileReadLong(file);
P.aux_older=(int)FileReadLong(file);
P.aux_recent=(int)FileReadLong(file);
P.aux_offset=Value((ulong)FileReadLong(file));
P.native_623e8=Value((ulong)FileReadLong(file));
P.native_623f0=(int)FileReadLong(file);
P.native_623f8=Value((ulong)FileReadLong(file));
P.native_62400=Value((ulong)FileReadLong(file));
P.native_62408=Value((ulong)FileReadLong(file));
P.native_62410=(uchar)FileReadLong(file);
P.omit_real_sl_tp=(uchar)FileReadLong(file);
P.mode=(int)FileReadLong(file);
P.native_62420=(int)FileReadLong(file);
P.check_free_margin=(uchar)FileReadLong(file);
P.native_62428=(int)FileReadLong(file);
P.native_62458=(int)FileReadLong(file);
P.native_62490=(uchar)FileReadLong(file);
P.native_62510=Value((ulong)FileReadLong(file));
P.native_62518=(int)FileReadLong(file);
P.native_62528=Value((ulong)FileReadLong(file));
P.native_62540=(int)FileReadLong(file);
P.native_62548=Value((ulong)FileReadLong(file));
P.native_62550=(int)FileReadLong(file);
P.native_624d8=(uchar)FileReadLong(file);
P.native_624ec=(uchar)FileReadLong(file);
P.native_62508=(uchar)FileReadLong(file);
P.point=Value((ulong)FileReadLong(file));
P.indicator_handle=(int)FileReadLong(file);
P.tick.time=(datetime)FileReadLong(file);
P.tick.last=Value((ulong)FileReadLong(file));
P.tick.volume=(ulong)FileReadLong(file);
P.tick.time_msc=FileReadLong(file);
P.tick.flags=(uint)FileReadLong(file);
P.tick.volume_real=Value((ulong)FileReadLong(file));
P.calendar.year=(int)FileReadLong(file);
P.calendar.mon=(int)FileReadLong(file);
P.calendar.day=(int)FileReadLong(file);
P.calendar.min=(int)FileReadLong(file);
P.calendar.sec=(int)FileReadLong(file);
P.calendar.day_of_week=(int)FileReadLong(file);
P.calendar.day_of_year=(int)FileReadLong(file);

      for(int i=0;i<4;i++)for(int j=0;j<8;j++)Doubles[i][j]=Value((ulong)FileReadLong(file));
      for(int i=0;i<3;i++)for(int j=0;j<8;j++)Integers[i][j]=FileReadLong(file);
      for(int i=0;i<8;i++)Times[i]=FileReadLong(file);for(int i=0;i<2;i++)BarsReply[i]=FileReadLong(file);for(int i=0;i<3;i++)BarTimes[i]=FileReadLong(file);
      AccountReply=Value((ulong)FileReadLong(file));for(int i=0;i<2;i++)LevelReply[i]=Value((ulong)FileReadLong(file));
      EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>32)return 8;for(int i=0;i<EffectCount;i++)for(int j=0;j<4;j++)Effects[i][j]=(ulong)FileReadLong(file);
      InfoReply=FileReadInteger(file);SelectReply=FileReadInteger(file);TotalReply=FileReadInteger(file);DealCount=FileReadInteger(file);if(DealCount<0 || DealCount>32)return 8;
      for(int i=0;i<DealCount;i++)for(int j=0;j<4;j++)Deals[i][j]=(ulong)FileReadLong(file);
      for(int i=0;i<8;i++)TailTimes[i]=FileReadLong(file);Selected=-1;
PrepHandle=(int)FileReadLong(file);PrepCopied=(int)FileReadLong(file);PrepCount=(int)FileReadLong(file);PrepSample=Value((ulong)FileReadLong(file));PrepTickOk=(int)FileReadLong(file);PrepTickWrite=(int)FileReadLong(file);PrepHour=(int)FileReadLong(file);PrepNow=FileReadLong(file);
ArraySetAsSeries(P.indicator_values,false);ArrayResize(P.indicator_values,2);P.indicator_values[0]=-11.;P.indicator_values[1]=-12.;PrepDPos=0;ArrayInitialize(PrepIPos,0);
Inputs.native_6a748=Panel.mode;
Inputs.native_6a750=Panel.trade_risk;
Inputs.native_6a768=Panel.balance_step;

      for(int i=0;i<500;i++)for(int j=0;j<3;j++)Manager.table.rows[i][j]=(double)(3*i+j+1)*.125;
      for(int i=0;i<100;i++)for(int j=0;j<3;j++)Queue.orders[i][j]=(double)(3*i+j+1)*.25;
      ArrayInitialize(Counts,0);ArrayInitialize(DPos,0);ArrayInitialize(IPos,0);string part=folder+"tape-"+IntegerToString(id)+".bin";Tape=FileOpen(part,FILE_WRITE|FILE_BIN);if(Tape==INVALID_HANDLE)return 5;
      ResetLastError();Final=false;ErrorOverride=-1;
      Result=Bot1InitializeStartupPreparationFlow(Inputs,P,Magic,OrderComment,Entry,Nfp,Interest,Cpi,Manager,Queue,Levels,MinimumSpread,FridayClosed,TailBars,Show,Tester,HistoryWindow,Seed,Balance,Panel,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,State,TailState);
      int error=GetLastError();FileClose(Tape);int section=FileOpen(part,FILE_READ|FILE_BIN);if(section==INVALID_HANDLE)return 6;int size=(int)FileSize(section);uchar raw[];ArrayResize(raw,size);if(size>0)FileReadArray(section,raw);FileClose(section);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0)FileWriteArray(tapes,raw);
      FileWriteInteger(output,id);Tape=output;Final=true;ErrorOverride=error;Begin();
   }
   if(FileTell(file)!=FileSize(file))return 9;FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}
