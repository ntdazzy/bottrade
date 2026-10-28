#property strict
input string CheckRun="";

double EntryHigh(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
double EntryLow(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
int EntryOrdersTotal();ulong EntryOrderTicket(const int index);
long EntryOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property);
string EntryOrderString(const ENUM_ORDER_PROPERTY_STRING property);
double EntryOrderDouble(const ENUM_ORDER_PROPERTY_DOUBLE property);
long EntrySymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property);
#define iHigh EntryHigh
#define iLow EntryLow
#define OrdersTotal EntryOrdersTotal
#define OrderGetTicket EntryOrderTicket
#define OrderGetInteger EntryOrderInteger
#define OrderGetString EntryOrderString
#define OrderGetDouble EntryOrderDouble
#define SymbolInfoInteger EntrySymbolInteger
#include "../../Include/bot-cua-toi-3/Bot3EntryLevels.mqh"
#undef iHigh
#undef iLow
#undef OrdersTotal
#undef OrderGetTicket
#undef OrderGetInteger
#undef OrderGetString
#undef OrderGetDouble
#undef SymbolInfoInteger


int InjectedCalendarError=-1;int CalendarError();
string CalendarStringSubstr(const string value,const int start,const int length=-1);
#define StringSubstr CalendarStringSubstr
int CalendarStringFind(const string value,const string needle,const int start=0);
#define GetLastError CalendarError
datetime RealCalendarServer();
int RealEventsCurrency(const string currency,MqlCalendarEvent &events[]);
int RealEventsCountry(const string country,MqlCalendarEvent &events[]);
int RealCalendarValues(const ulong event_id,MqlCalendarValue &values[],const datetime from,const datetime to=0);
void RealCalendarPrint(const string value);
#define TimeTradeServer RealCalendarServer
#define CalendarEventByCurrency RealEventsCurrency
#define CalendarEventByCountry RealEventsCountry
#define CalendarValueHistoryByEvent RealCalendarValues
#define Print RealCalendarPrint
#define StringFind CalendarStringFind
#include "../../Include/bot-cua-toi-3/Bot3NfpCalendar.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ReleaseCalendars.mqh"
#undef TimeTradeServer
#undef CalendarEventByCurrency
#undef CalendarEventByCountry
#undef CalendarValueHistoryByEvent
#undef Print
#undef StringFind


datetime StartupNewsServer();
#define TimeTradeServer StartupNewsServer
#include "../../Include/bot-cua-toi-3/Bot3NewsSelector.mqh"
#undef TimeTradeServer
#include "../../Include/bot-cua-toi-3/Bot3NfpCalendar.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ReleaseCalendars.mqh"
long StartupNfp();long StartupInterest();long StartupCpi();
string Bot3InitializationTimeText(const datetime value);
void StartupNewsPrint(const string value);
#define BOT3_INITIALIZATION_TIME_TEXT_MQH
#define Bot3FindNfpTime StartupNfp
#define Bot3FindInterestRateTime StartupInterest
#define Bot3FindCpiTime StartupCpi
#define Print StartupNewsPrint
#include "../../Include/bot-cua-toi-3/Bot3NewsInitialization.mqh"
#undef Bot3FindNfpTime
#undef Bot3FindInterestRateTime
#undef Bot3FindCpiTime
#undef Print

long InitCalendarInfo(const ENUM_MQL_INFO_INTEGER property);

double InitAccountDouble(const ENUM_ACCOUNT_INFO_DOUBLE property);
long InitAccountInteger(const ENUM_ACCOUNT_INFO_INTEGER property);
double InitGlobalGet(const string name);datetime InitGlobalSet(const string name,const double value);
bool InitGlobalCheck(const string name);void InitSleep(const int milliseconds);
datetime InitAccountTime();void InitAccountPrint(const string message);
#define AccountInfoDouble InitAccountDouble
#define AccountInfoInteger InitAccountInteger
#define GlobalVariableGet InitGlobalGet
#define GlobalVariableSet InitGlobalSet
#define GlobalVariableCheck InitGlobalCheck
#define Sleep InitSleep
#define TimeCurrent InitAccountTime
#define Print InitAccountPrint
#include "../../Include/bot-cua-toi-3/Bot3AccountInitialization.mqh"
#define MQLInfoInteger InitCalendarInfo
#include "../../Include/bot-cua-toi-3/Bot3BuiltInNewsHistory.mqh"
#undef MQLInfoInteger
#undef AccountInfoDouble
#undef AccountInfoInteger
#undef GlobalVariableGet
#undef GlobalVariableSet
#undef GlobalVariableCheck
#undef Sleep
#undef TimeCurrent
#undef Print

datetime SelNow();
bool SelStruct(datetime value,MqlDateTime &result);
double SelMod(double left,double right);
int SelConcat(string &output,int year,const string &suffix);
datetime SelDate(string value);
double SelBalance(ENUM_ACCOUNT_INFO_DOUBLE property);
string SelCurrency(ENUM_ACCOUNT_INFO_STRING property);
double SelClose(string symbol,ENUM_TIMEFRAMES timeframe,int shift);
void SelPrint(string message);

#define TimeCurrent SelNow
#define TimeToStruct SelStruct
#define MathMod SelMod
#define StringConcatenate SelConcat
#define StringToTime SelDate
#define AccountInfoString SelCurrency
#define iClose SelClose
#define Print SelPrint

#include "../../Include/bot-cua-toi-3/Bot3AmericanDST.mqh"
#include "../../Include/bot-cua-toi-3/Bot3VolumeCurrency.mqh"

#undef TimeCurrent
#undef TimeToStruct
#undef MathMod
#undef StringConcatenate
#undef StringToTime
#undef AccountInfoString
#undef iClose
#undef Print


int PrepATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period);
int PrepCopy(const int handle,const int buffer,const int start,const int count,double &values[]);
bool PrepTick(const string symbol,MqlTick &tick);
double PrepOpen(const string symbol,const ENUM_TIMEFRAMES frame,const int shift);
datetime PrepTime(MqlDateTime &calendar);datetime PrepTime();
double PrepDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop);
long PrepInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);
void PrepPrint(const string value);void PrepPrint(const string value,const int error);
#define iOpen PrepOpen
#define iATR PrepATR
#define CopyBuffer PrepCopy
#define SymbolInfoTick PrepTick
#define TimeCurrent PrepTime
#define SymbolInfoDouble PrepDouble
#define SymbolInfoInteger PrepInteger
#define Print PrepPrint
#include "../../Include/bot-cua-toi-3/Bot3Preparation.mqh"
#undef iOpen
#undef iATR
#undef CopyBuffer
#undef SymbolInfoTick
#undef TimeCurrent
#undef SymbolInfoDouble
#undef SymbolInfoInteger
#undef Print

#include "../../Include/bot-cua-toi-3/Bot3EntryLoop.mqh"
#include "../../Include/bot-cua-toi-3/Bot3EntryLevelCache.mqh"
#include "../../Include/bot-cua-toi-3/Bot3PositionManagement.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ReleaseFilters.mqh"
#include "../../Include/bot-cua-toi-3/Bot3PanelCreation.mqh"
#include "../../Include/bot-cua-toi-3/Bot3ClosedStatusPanel.mqh"
Bot3PreparationInputs Inputs;Bot3PreparationState P;Bot3EntryLoopState Entry;Bot3PositionManagementState Manager;
Bot3NfpFilterState Nfp;Bot3ReleaseFilterState Interest,Cpi;Bot3PendingQueue Queue;Bot3LevelCacheSettings Levels;
double MinimumSpread;ulong LastTicket;
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
void MockPrint(const string value);string Bot3StartupNumber(const double value);
#define BOT3_STARTUP_NUMBER_EXTERNAL
#define SymbolInfoDouble MockDouble
#define SymbolInfoInteger MockInteger
#define Bars MockBars
#define TimeCurrent MockTime
#define iTime MockBar
#define AccountInfoDouble MockAccount
#define Print MockPrint
#include "../../Include/bot-cua-toi-3/Bot3StartupTradingState.mqh"
#undef SymbolInfoDouble
#undef SymbolInfoInteger
#undef Bars
#undef TimeCurrent
#undef iTime
#undef AccountInfoDouble
#undef Print
void MockCreate(Bot3PanelCreationState &p,const Bot3NewsEvents &events,const Bot3NewsWindows &windows,Bot3NewsSelection &selection);
void MockOpen(const uchar &show,const uchar &tester,const int &seed,const string &symbol,const double &balance,const int &frequency,
              const uint &mode,const double &manual_lots,const double &allowed_dd,const double &strategy_risk,const Bot3NewsEvents &events,
              const Bot3NewsWindows &windows,Bot3NewsSelection &selection,ulong &ticket);
void MockClosed(const uchar &show,const uchar &tester,const int &seed,const string &symbol,double &wins,double &losses);
long MockTailSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop);int MockInfo(const ENUM_MQL_INFO_INTEGER prop);
bool MockSelect(const datetime from,const datetime to);int MockTotal();ulong MockTicket(const int index);
datetime MockTailTime();long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop);
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop);
#define Bot3CreateInfoPanel MockCreate
#define Bot3UpdateOpenStatusPanel MockOpen
#define Bot3UpdateClosedStatusPanel MockClosed
#define SymbolInfoInteger MockTailSymbol
#define MQLInfoInteger MockInfo
#define HistorySelect MockSelect
#define HistoryDealsTotal MockTotal
#define HistoryDealGetTicket MockTicket
#define TimeCurrent MockTailTime
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
#include "../../Include/bot-cua-toi-3/Bot3StartupPreparationFlow.mqh"
#include "../../Include/bot-cua-toi-3/Bot3StrategyContext.mqh"
#include "../../Include/bot-cua-toi-3/Bot3StrategyHistory.mqh"
#include "../../Include/bot-cua-toi-3/Bot3DailyLossGuard.mqh"
#define Print MockPrint
#include "../../Include/bot-cua-toi-3/Bot3StartupContext.mqh"
#undef Print
#include "../../Include/bot-cua-toi-3/Bot3StartupContextFlow.mqh"
#define TimeCurrent SelNow
#define AccountInfoDouble SelBalance
#include "../../Include/bot-cua-toi-3/Bot3StartupSelectionContext.mqh"
#undef AccountInfoDouble
#undef TimeCurrent
#include "../../Include/bot-cua-toi-3/Bot3StartupNewsFlow.mqh"

Bot3PanelCreationState Panel;Bot3NewsEvents Events;Bot3NewsWindows Windows;Bot3NewsSelection Selection;Bot3StartupTailState TailState;
int LastHour;double Balance,Wins,Losses;uchar Show,Tester,HistoryWindow;long TailBars[9];
Bot3StrategyContextInputs ContextInputs;Bot3StrategyContextState Context;Bot3StrategyHistoryCache History;Bot3DailyLossState Daily;Bot3StartupContextState Startup;string ChartName;
int WinterHours,SummerHours,Frequency;long AdjustedTime;uchar Thresholds[3],Manual[9],Enabled[9];double FrequencyDivisor;
long SelClocks[4];
int SelClockIndex;
double SelBalanceReply;
string SelCurrencies[64];
int SelCurrencyCount;
int SelCurrencyIndex;
double SelPrices[64];
int SelPriceCount;
int SelPriceIndex;

Bot3StartupTradingState State;
int Tape,ErrorOverride=-1,Counts[98],DPos[4],IPos[3];bool Final=false;
double Doubles[4][8],AccountReply,LevelReply[2];long Integers[3][8],Times[8],BarsReply[2],BarTimes[3];ulong Effects[32][4];int EffectCount;
void Word(const ulong v){FileWriteLong(Tape,(long)v);}
void Text(const string v){int n=v==NULL ? -1 : StringLen(v);FileWriteInteger(Tape,n);if(n>0)FileWriteString(Tape,v,n);}
string ReadText(const int file){int n=FileReadInteger(file);return n<0 ? NULL : (n==0 ? "" : FileReadString(file,n));}
ulong TablesHash(){ulong h=0xcbf29ce484222325;for(int i=0;i<500;i++)for(int j=0;j<3;j++)h=(h^Bits(Manager.table.rows[i][j]))*0x100000001b3;for(int i=0;i<500;i++)for(int j=0;j<2;j++)h=(h^Bits(Manager.table.take_rows[i][j]))*0x100000001b3;for(int i=0;i<100;i++)for(int j=0;j<3;j++)h=(h^Bits(Queue.orders[i][j]))*0x100000001b3;return h;}

int InfoReply,SelectReply,TotalReply,DealCount,Selected,Result;ulong Deals[32][4];long TailTimes[8];


uchar UseEquity,ResetHighest,NewsFlag0,NewsFlag1;
double ManualBalance,HighestBalance;string PeakKey,TimeKey;long AccountLastTime;
long NewsNfp[300],NewsInterest[300],NewsCpi[300];
long BankLogin,BankNow,NewsSeed;double BankBalance,BankEquity,BankPeak,BankTime;bool BankHasPeak,BankHasTime;
string BankPeakKey,BankTimeKey;

double EntryHighValues[],EntryLowValues[];long EntryDigits;int EntrySelected=-1;
struct EntryOrderData{ulong ticket;long magic;int kind;double price;string symbol;};EntryOrderData EntryOrders[];

int CalendarKind=-1;
struct CalendarReply {long now;int event_return,value_return,event_series,value_series,value_error;ulong ids[];string names[];long times[];};
CalendarReply CalendarReplies[3];

long StartupReplies[3],StartupClocks[3];
void NewsSnapshot(){ulong h=0xcbf29ce484222325;for(int i=0;i<300;i++)h=(h^(ulong)NewsNfp[i])*0x100000001b3;for(int i=0;i<300;i++)h=(h^(ulong)NewsInterest[i])*0x100000001b3;for(int i=0;i<300;i++)h=(h^(ulong)NewsCpi[i])*0x100000001b3;Word(h);}
void NewsFinal(){for(int i=0;i<300;i++)Word((ulong)NewsNfp[i]);for(int i=0;i<300;i++)Word((ulong)NewsInterest[i]);for(int i=0;i<300;i++)Word((ulong)NewsCpi[i]);}

long BankInfo;

void PrepArraySnapshot();
void Snapshot(){
Word((ulong)(long)P.native_6d50c);
Word((ulong)(long)State.native_6d645);
Word((ulong)(long)P.strategy_index);
Word((ulong)(long)P.entry_frame);
Word((ulong)(long)P.management_timeframe);
Word(Bits(P.tick.ask));
Word(Bits(P.tick.bid));
Word(Bits(P.spread));
Word(Bits(P.native_6d620));
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
Word(Bits(P.native_6d5e8));
Word(Bits(P.native_6d5f0));
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
Word((ulong)(long)Context.magic);
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
Word(Bits(P.native_6d628));
Word((ulong)(long)Manager.table.guard);
Word((ulong)(long)Queue.enabled);
Text(P.comment);
Word((ulong)(long)Panel.font);
Word(Bits(Panel.scale));
Word((ulong)(long)Panel.color_flag);
Word((ulong)(long)Panel.mode);
Word(Bits(Panel.strategy_risk));
Word((ulong)(long)Panel.frequency);
Word(Bits(Panel.manual_lots));
Word(Bits(Panel.allowed_dd));
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
Word(Bits(Panel.closed[8]));
Word(Bits(Panel.per_trade[0]));
Word(Bits(Panel.per_trade[1]));
Word(Bits(Panel.per_trade[2]));
Word(Bits(Panel.per_trade[3]));
Word(Bits(Panel.per_trade[4]));
Word(Bits(Panel.per_trade[5]));
Word(Bits(Panel.per_trade[6]));
Word(Bits(Panel.per_trade[7]));
Word(Bits(Panel.per_trade[8]));
Word(Bits(Panel.lots[0]));
Word(Bits(Panel.lots[1]));
Word(Bits(Panel.lots[2]));
Word(Bits(Panel.lots[3]));
Word(Bits(Panel.lots[4]));
Word(Bits(Panel.lots[5]));
Word(Bits(Panel.lots[6]));
Word(Bits(Panel.lots[7]));
Word(Bits(Panel.lots[8]));
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
Word((ulong)(long)ContextInputs.base_magic);
Word(Bits(Balance));
Word(Bits(Wins));
Word(Bits(Losses));
Text(Context.order_comment);
Text(Inputs.symbol);
Text(TailState.buy_first);
Text(TailState.buy_second);
Text(TailState.sell_first);
Text(TailState.sell_second);
Word((ulong)(long)TailState.flag_744a0);
Word((ulong)(long)TailBars[0]);
Word((ulong)(long)TailBars[1]);
Word((ulong)(long)TailBars[2]);
Word((ulong)(long)TailBars[3]);
Word((ulong)(long)TailBars[4]);
Word((ulong)(long)TailBars[5]);
Word((ulong)(long)TailBars[6]);
Word((ulong)(long)TailBars[7]);
Word((ulong)(long)TailBars[8]);
Word((ulong)(long)Inputs.indicator_period);
Word((ulong)(long)Inputs.indicator_timeframe);
Word(Bits(Inputs.reference));
Word((ulong)(long)Inputs.variable_distances);
Word((ulong)(long)Inputs.adjust_lots);
Word(Bits(Inputs.max_spread));
Word((ulong)(long)Inputs.feature_flag);
Word((ulong)(long)Inputs.freeze_buffer_flag);
Word((ulong)(long)Inputs.entry.entry_frame);
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
Word(Bits(Inputs.native_6d368));
Word(Bits(Inputs.native_6d370));
Word(Bits(Inputs.trigger_distance));
Word(Bits(Inputs.locked_distance));
Word((ulong)(long)Inputs.aux_hour1);
Word((ulong)(long)Inputs.aux_scan50);
Word((ulong)(long)Inputs.aux_older);
Word((ulong)(long)Inputs.aux_recent);
Word(Bits(Inputs.aux_offset));
Word(Bits(Inputs.min_change));
Word(Bits(Inputs.native_6d250));
Word((ulong)(long)Inputs.native_6d258);
Word(Bits(Inputs.native_6d260));
Word(Bits(Inputs.native_6d268));
Word(Bits(Inputs.native_6d270));
Word((ulong)(long)Inputs.native_6d278);
Word((ulong)(long)Inputs.native_1d6fa8);
Word((ulong)(long)Inputs.native_1d6fc0);
Word((ulong)(long)Inputs.virtual_stops);
Word((ulong)(long)Inputs.native_1d6fe8);
Word((ulong)(long)Inputs.native_1d7178);
Word((ulong)(long)Inputs.native_6d2a3);
Word((ulong)(long)Inputs.native_6d2e0);
Word((ulong)(long)Inputs.management_timeframe);
Word((ulong)(long)Inputs.native_6d3f8);
Word(Bits(Inputs.native_6d3f0));
Word(Bits(Inputs.native_6d408));
Word(Bits(Inputs.native_6d410));
Word((ulong)(long)Inputs.native_1d7130);
Word(Bits(Inputs.native_6d418));
Word((ulong)(long)Inputs.native_6d420);
Text(Inputs.comment);
Word(Bits(P.scale));
Word(Bits(P.lot_scale));
Word((ulong)(long)P.feature_flag);
Word(Bits(P.trail_start));
Word(Bits(P.trail_limit));
Word(Bits(P.trail_step));
Word(Bits(P.native_6d378));
Word(Bits(P.native_6d380));
Word((ulong)(long)P.aux_frame);
Word((ulong)(long)P.aux_scan);
Word((ulong)(long)P.aux_older);
Word((ulong)(long)P.aux_recent);
Word(Bits(P.aux_offset));
Word(Bits(P.native_6d4e0));
Word((ulong)(long)P.native_6d4e8);
Word(Bits(P.native_6d4f0));
Word(Bits(P.native_6d4f8));
Word(Bits(P.native_6d500));
Word((ulong)(long)P.native_6d508);
Word((ulong)(long)P.native_6d510);
Word((ulong)(long)P.mode);
Word((ulong)(long)P.native_6d518);
Word((ulong)(long)P.native_6d51c);
Word((ulong)(long)P.native_6d520);
Word((ulong)(long)P.native_6d550);
Word((ulong)(long)P.native_6d608);
Word(Bits(P.native_6d600));
Word(Bits(P.native_6d618));
Word(Bits(P.native_6d638));
Word((ulong)(long)P.native_6d640);
Word((ulong)(long)P.native_6d5c8);
Word((ulong)(long)P.native_6d5dc);
Word((ulong)(long)P.native_6d5f8);
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
Word(Bits(Context.converted_value));
Word((ulong)(long)ContextInputs.keep_comment);
Word(Bits(Daily.peak));
Word((ulong)(long)Daily.blocked);
Word((ulong)(long)Daily.bars);
Word((ulong)(long)Startup.panel_bar);
Word((ulong)(long)History.total);
Word((ulong)(long)History.count);
Word((ulong)(long)Startup.extended_cleanup);
Word(Bits(Startup.cell_base_x));
Word(Bits(Startup.cell_base_y));
Text(ContextInputs.comment_prefix);
Text(ContextInputs.symbol_suffix);
Text(ChartName);
Word((ulong)(long)WinterHours);
Word((ulong)(long)SummerHours);
Word((ulong)(long)AdjustedTime);
Word((ulong)(long)Frequency);
Word(Bits(FrequencyDivisor));
Word((ulong)(long)Thresholds[0]);
Word((ulong)(long)Thresholds[1]);
Word((ulong)(long)Thresholds[2]);
Word((ulong)(long)Manual[0]);
Word((ulong)(long)Manual[1]);
Word((ulong)(long)Manual[2]);
Word((ulong)(long)Manual[3]);
Word((ulong)(long)Manual[4]);
Word((ulong)(long)Manual[5]);
Word((ulong)(long)Manual[6]);
Word((ulong)(long)Manual[7]);
Word((ulong)(long)Manual[8]);
Word((ulong)(long)Enabled[0]);
Word((ulong)(long)Enabled[1]);
Word((ulong)(long)Enabled[2]);
Word((ulong)(long)Enabled[3]);
Word((ulong)(long)Enabled[4]);
Word((ulong)(long)Enabled[5]);
Word((ulong)(long)Enabled[6]);
Word((ulong)(long)Enabled[7]);
Word((ulong)(long)Enabled[8]);
Word((ulong)(long)UseEquity);
Word((ulong)(long)ResetHighest);
Word(Bits(ManualBalance));
Word(Bits(HighestBalance));
Text(PeakKey);
Text(TimeKey);
Word((ulong)(long)AccountLastTime);
Word((ulong)(long)NewsFlag0);
Word((ulong)(long)NewsFlag1);
Word((ulong)(long)Nfp.last_query);
PrepArraySnapshot();NewsSnapshot();Word(TablesHash());Word(ErrorOverride<0 ? GetLastError() : (uint)ErrorOverride);
if(Final){for(int i=0;i<500;i++)for(int j=0;j<3;j++)Word(Bits(Manager.table.rows[i][j]));for(int i=0;i<500;i++)for(int j=0;j<2;j++)Word(Bits(Manager.table.take_rows[i][j]));for(int i=0;i<100;i++)for(int j=0;j<3;j++)Word(Bits(Queue.orders[i][j]));Word((ulong)(long)Result);NewsFinal();}}
void Begin(){ulong at=FileTell(Tape);FileWriteInteger(Tape,0);Snapshot();ulong end=FileTell(Tape);FileSeek(Tape,(long)at,SEEK_SET);FileWriteInteger(Tape,(int)(end-at-4));FileSeek(Tape,(long)end,SEEK_SET);}
void End(const int api,const ulong a=0,const ulong b=0,const ulong c=0,const ulong d=0,const string t=NULL,const string u=NULL){FileWriteInteger(Tape,api);Word(a);Word(b);Word(c);Word(d);Text(t);Text(u);FileWriteInteger(Tape,(int)GetLastError());}
void Effect(const int api){int n=++Counts[api];for(int i=0;i<EffectCount;i++){if((int)Effects[i][0]!=api || (int)Effects[i][1]!=n)continue;ulong v=Effects[i][3];switch((int)Effects[i][2]){case 0:P.native_6d50c=(int)v;break;case 1:State.native_6d645=(uchar)v;break;case 2:P.strategy_index=(uint)v;break;case 3:P.entry_frame=(int)v;break;case 4:P.management_timeframe=(int)v;break;case 5:P.tick.ask=Value(v);break;case 6:P.tick.bid=Value(v);break;case 7:P.spread=Value(v);break;case 8:P.native_6d620=Value(v);break;case 9:P.unit=Value(v);break;case 10:P.min_change=Value(v);break;case 11:P.stop_min_price=Value(v);break;case 12:P.freeze_min_price=Value(v);break;case 13:P.stop_distance=Value(v);break;case 14:P.target_distance=Value(v);break;case 15:P.trigger_distance=Value(v);break;case 16:P.locked_distance=Value(v);break;case 17:P.freeze_buffer=(int)v;break;case 18:P.trail_distance=Value(v);break;case 19:P.native_6d5e8=Value(v);break;case 20:P.native_6d5f0=Value(v);break;case 21:P.gap_points=Value(v);break;case 22:P.older_width=(int)v;break;case 23:P.recent_width=(int)v;break;case 24:P.expiration_hours=(int)v;break;case 25:P.virtual_expiration=(uchar)v;break;case 26:P.expiration_seconds=(uint)v;break;case 27:P.expiration=(long)v;break;case 28:Nfp.notice=(uchar)v;break;case 29:Nfp.blocked=(uchar)v;break;case 30:Interest.blocked=(uchar)v;break;case 31:Cpi.blocked=(uchar)v;break;case 32:State.week_bar=(long)v;break;case 33:P.max_spread=Value(v);break;case 34:MinimumSpread=Value(v);break;case 35:Inputs.entry.confirmation_frame=(int)v;break;case 36:Context.magic=(int)v;break;case 37:P.last_shift=(int)v;break;case 38:P.buy_offset=Value(v);break;case 39:P.sell_offset=Value(v);break;case 40:P.nearby_radius=Value(v);break;case 41:LastTicket=v;break;case 42:Entry.candidate_buy=Value(v);break;case 43:Entry.candidate_sell=Value(v);break;case 44:Entry.rounded_buy=Value(v);break;case 45:Entry.rounded_sell=Value(v);break;case 46:Levels.blocked=(uchar)v;break;case 47:Manager.counter=(int)v;break;case 48:State.timed_delay_seconds=(int)v;break;case 49:Manager.current_stop=Value(v);break;case 50:P.native_6d628=Value(v);break;case 51:Manager.table.guard=(uchar)v;break;case 52:Queue.enabled=(uchar)v;break;case 54:Panel.font=(int)v;break;case 55:Panel.scale=Value(v);break;case 56:Panel.color_flag=(uchar)v;break;case 57:Panel.mode=(uint)v;break;case 58:Panel.strategy_risk=Value(v);break;case 59:Panel.frequency=(int)v;break;case 60:Panel.manual_lots=Value(v);break;case 61:Panel.allowed_dd=Value(v);break;case 62:Panel.cell_x=Value(v);break;case 63:Panel.cell_y=Value(v);break;case 64:Panel.cell_font_flag=(uchar)v;break;case 65:Panel.closed_star=(uchar)v;break;case 66:Panel.rows_ready=(uchar)v;break;case 67:Panel.closed[0]=Value(v);break;case 68:Panel.closed[1]=Value(v);break;case 69:Panel.closed[2]=Value(v);break;case 70:Panel.closed[3]=Value(v);break;case 71:Panel.closed[4]=Value(v);break;case 72:Panel.closed[5]=Value(v);break;case 73:Panel.closed[6]=Value(v);break;case 74:Panel.closed[7]=Value(v);break;case 75:Panel.closed[8]=Value(v);break;case 76:Panel.per_trade[0]=Value(v);break;case 77:Panel.per_trade[1]=Value(v);break;case 78:Panel.per_trade[2]=Value(v);break;case 79:Panel.per_trade[3]=Value(v);break;case 80:Panel.per_trade[4]=Value(v);break;case 81:Panel.per_trade[5]=Value(v);break;case 82:Panel.per_trade[6]=Value(v);break;case 83:Panel.per_trade[7]=Value(v);break;case 84:Panel.per_trade[8]=Value(v);break;case 85:Panel.lots[0]=Value(v);break;case 86:Panel.lots[1]=Value(v);break;case 87:Panel.lots[2]=Value(v);break;case 88:Panel.lots[3]=Value(v);break;case 89:Panel.lots[4]=Value(v);break;case 90:Panel.lots[5]=Value(v);break;case 91:Panel.lots[6]=Value(v);break;case 92:Panel.lots[7]=Value(v);break;case 93:Panel.lots[8]=Value(v);break;case 94:Events.nfp=(long)v;break;case 95:Events.interest=(long)v;break;case 96:Events.cpi=(long)v;break;case 97:Windows.nfp_enabled=(uchar)v;break;case 98:Windows.interest_enabled=(uchar)v;break;case 99:Windows.cpi_enabled=(uchar)v;break;case 100:Windows.nfp_after=(int)v;break;case 101:Windows.interest_after=(int)v;break;case 102:Windows.cpi_after=(int)v;break;case 103:Selection.block_time=(long)v;break;case 105:P.calendar.hour=(int)v;break;case 106:LastHour=(int)v;break;case 107:Show=(uchar)v;break;case 108:Tester=(uchar)v;break;case 109:HistoryWindow=(uchar)v;break;case 110:ContextInputs.base_magic=(int)v;break;case 111:Balance=Value(v);break;case 112:Wins=Value(v);break;case 113:Losses=Value(v);break;case 120:TailState.flag_744a0=(uchar)v;break;case 121:TailBars[0]=(long)v;break;case 122:TailBars[1]=(long)v;break;case 123:TailBars[2]=(long)v;break;case 124:TailBars[3]=(long)v;break;case 125:TailBars[4]=(long)v;break;case 126:TailBars[5]=(long)v;break;case 127:TailBars[6]=(long)v;break;case 128:TailBars[7]=(long)v;break;case 129:TailBars[8]=(long)v;break;case 130:Inputs.indicator_period=(int)v;break;case 131:Inputs.indicator_timeframe=(int)v;break;case 132:Inputs.reference=Value(v);break;case 133:Inputs.variable_distances=(uchar)v;break;case 134:Inputs.adjust_lots=(uchar)v;break;case 135:Inputs.max_spread=Value(v);break;case 136:Inputs.feature_flag=(uchar)v;break;case 137:Inputs.freeze_buffer_flag=(uchar)v;break;case 138:Inputs.entry.entry_frame=(int)v;break;case 139:Inputs.entry.older_width=(int)v;break;case 140:Inputs.entry.recent_width=(int)v;break;case 141:Inputs.entry.last_shift=(int)v;break;case 142:Inputs.entry.gap_points=Value(v);break;case 143:Inputs.buy_offset=Value(v);break;case 144:Inputs.sell_offset=Value(v);break;case 145:Inputs.nearby_radius=Value(v);break;case 146:Inputs.expiration_hours=(int)v;break;case 147:Inputs.virtual_expiration=(uchar)v;break;case 148:Inputs.stop_distance=Value(v);break;case 149:Inputs.target_distance=Value(v);break;case 150:Inputs.trail_distance=Value(v);break;case 151:Inputs.trail_start=Value(v);break;case 152:Inputs.trail_limit=Value(v);break;case 153:Inputs.trail_step=Value(v);break;case 154:Inputs.native_6d368=Value(v);break;case 155:Inputs.native_6d370=Value(v);break;case 156:Inputs.trigger_distance=Value(v);break;case 157:Inputs.locked_distance=Value(v);break;case 158:Inputs.aux_hour1=(uchar)v;break;case 159:Inputs.aux_scan50=(uchar)v;break;case 160:Inputs.aux_older=(int)v;break;case 161:Inputs.aux_recent=(int)v;break;case 162:Inputs.aux_offset=Value(v);break;case 163:Inputs.min_change=Value(v);break;case 164:Inputs.native_6d250=Value(v);break;case 165:Inputs.native_6d258=(uchar)v;break;case 166:Inputs.native_6d260=Value(v);break;case 167:Inputs.native_6d268=Value(v);break;case 168:Inputs.native_6d270=Value(v);break;case 169:Inputs.native_6d278=(uchar)v;break;case 170:Inputs.native_1d6fa8=(int)v;break;case 171:Inputs.native_1d6fc0=(uchar)v;break;case 172:Inputs.virtual_stops=(uchar)v;break;case 173:Inputs.native_1d6fe8=(int)v;break;case 174:Inputs.native_1d7178=(uchar)v;break;case 175:Inputs.native_6d2a3=(uchar)v;break;case 176:Inputs.native_6d2e0=(int)v;break;case 177:Inputs.management_timeframe=(int)v;break;case 178:Inputs.native_6d3f8=(uchar)v;break;case 179:Inputs.native_6d3f0=Value(v);break;case 180:Inputs.native_6d408=Value(v);break;case 181:Inputs.native_6d410=Value(v);break;case 182:Inputs.native_1d7130=(int)v;break;case 183:Inputs.native_6d418=Value(v);break;case 184:Inputs.native_6d420=(uchar)v;break;case 186:P.scale=Value(v);break;case 187:P.lot_scale=Value(v);break;case 188:P.feature_flag=(uchar)v;break;case 189:P.trail_start=Value(v);break;case 190:P.trail_limit=Value(v);break;case 191:P.trail_step=Value(v);break;case 192:P.native_6d378=Value(v);break;case 193:P.native_6d380=Value(v);break;case 194:P.aux_frame=(int)v;break;case 195:P.aux_scan=(int)v;break;case 196:P.aux_older=(int)v;break;case 197:P.aux_recent=(int)v;break;case 198:P.aux_offset=Value(v);break;case 199:P.native_6d4e0=Value(v);break;case 200:P.native_6d4e8=(int)v;break;case 201:P.native_6d4f0=Value(v);break;case 202:P.native_6d4f8=Value(v);break;case 203:P.native_6d500=Value(v);break;case 204:P.native_6d508=(uchar)v;break;case 205:P.native_6d510=(uchar)v;break;case 206:P.mode=(int)v;break;case 207:P.native_6d518=(int)v;break;case 208:P.native_6d51c=(uchar)v;break;case 209:P.native_6d520=(int)v;break;case 210:P.native_6d550=(int)v;break;case 211:P.native_6d608=(int)v;break;case 212:P.native_6d600=Value(v);break;case 213:P.native_6d618=Value(v);break;case 214:P.native_6d638=Value(v);break;case 215:P.native_6d640=(int)v;break;case 216:P.native_6d5c8=(uchar)v;break;case 217:P.native_6d5dc=(uchar)v;break;case 218:P.native_6d5f8=(uchar)v;break;case 219:P.point=Value(v);break;case 220:P.indicator_handle=(int)v;break;case 221:P.tick.time=(datetime)v;break;case 222:P.tick.last=Value(v);break;case 223:P.tick.volume=v;break;case 224:P.tick.time_msc=(long)v;break;case 225:P.tick.flags=(uint)v;break;case 226:P.tick.volume_real=Value(v);break;case 227:P.calendar.year=(int)v;break;case 228:P.calendar.mon=(int)v;break;case 229:P.calendar.day=(int)v;break;case 230:P.calendar.min=(int)v;break;case 231:P.calendar.sec=(int)v;break;case 232:P.calendar.day_of_week=(int)v;break;case 233:P.calendar.day_of_year=(int)v;break;case 234:Context.converted_value=Value(v);break;case 235:ContextInputs.keep_comment=(uchar)v;break;case 236:Daily.peak=Value(v);break;case 237:Daily.blocked=(uchar)v;break;case 238:Daily.bars=(int)v;break;case 239:Startup.panel_bar=(long)v;break;case 240:History.total=(int)v;break;case 241:History.count=(int)v;break;case 242:Startup.extended_cleanup=(uchar)v;break;case 243:Startup.cell_base_x=Value(v);break;case 244:Startup.cell_base_y=Value(v);break;case 248:WinterHours=(int)v;break;case 249:SummerHours=(int)v;break;case 250:AdjustedTime=(long)v;break;case 251:Frequency=(int)v;break;case 252:FrequencyDivisor=Value(v);break;case 253:Thresholds[0]=(uchar)v;break;case 254:Thresholds[1]=(uchar)v;break;case 255:Thresholds[2]=(uchar)v;break;case 256:Manual[0]=(uchar)v;break;case 257:Manual[1]=(uchar)v;break;case 258:Manual[2]=(uchar)v;break;case 259:Manual[3]=(uchar)v;break;case 260:Manual[4]=(uchar)v;break;case 261:Manual[5]=(uchar)v;break;case 262:Manual[6]=(uchar)v;break;case 263:Manual[7]=(uchar)v;break;case 264:Manual[8]=(uchar)v;break;case 265:Enabled[0]=(uchar)v;break;case 266:Enabled[1]=(uchar)v;break;case 267:Enabled[2]=(uchar)v;break;case 268:Enabled[3]=(uchar)v;break;case 269:Enabled[4]=(uchar)v;break;case 270:Enabled[5]=(uchar)v;break;case 271:Enabled[6]=(uchar)v;break;case 272:Enabled[7]=(uchar)v;break;case 273:Enabled[8]=(uchar)v;break;case 274:UseEquity=(uchar)v;break;case 275:ResetHighest=(uchar)v;break;case 276:ManualBalance=Value(v);break;case 277:HighestBalance=Value(v);break;case 280:AccountLastTime=(long)v;break;case 281:NewsFlag0=(uchar)v;break;case 282:NewsFlag1=(uchar)v;break;case 283:Nfp.last_query=(long)v;break;}}}
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
string Bot3StartupNumber(const double value){Begin();string v=(string)value;Effect(8);End(8,Bits(value),0,0,0,v);return v;}
void MockPrint(const string value){Begin();Effect(9);End(9,0,0,0,0,value);}
long MockTailSymbol(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();End(16,(ulong)prop,2,0,0,symbol);Effect(16);return 2;}
int MockInfo(const ENUM_MQL_INFO_INTEGER prop){Begin();End(10,(ulong)prop,(ulong)(long)InfoReply);Effect(10);return InfoReply;}
bool MockSelect(const datetime from,const datetime to){Begin();End(11,(ulong)from,(ulong)to,(ulong)SelectReply);Effect(11);return SelectReply!=0;}
int MockTotal(){Begin();End(12,(ulong)(long)TotalReply);Effect(12);return TotalReply;}
ulong MockTicket(const int index){Begin();Selected=index;ulong v=index>=0 && index<DealCount ? Deals[index][0] : 0;End(13,(ulong)(long)index,v);Effect(13);return v;}
datetime MockTailTime(){Begin();long v=TailTimes[Counts[17]%8];End(17,(ulong)v);Effect(17);return (datetime)v;}
long MockDealInteger(const ulong ticket,const ENUM_DEAL_PROPERTY_INTEGER prop){Begin();long v=Selected>=0 && Selected<DealCount ? (long)Deals[Selected][prop==2 ? 1 : 2] : 0;End(14,ticket,(ulong)prop,(ulong)v);Effect(14);return v;}
double MockDealDouble(const ulong ticket,const ENUM_DEAL_PROPERTY_DOUBLE prop){Begin();double v=Selected>=0 && Selected<DealCount ? Value(Deals[Selected][3]) : 0.;End(15,ticket,(ulong)prop,Bits(v));Effect(15);return v;}
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


int PrepHandle,PrepCopied,PrepCount,PrepTickOk,PrepTickWrite,PrepHour,PrepDPos,PrepIPos[3];double PrepSample,PrepOpenReply;long PrepNow;
void PrepArraySnapshot(){int n=ArraySize(P.indicator_values);Word((ulong)n);Word((ulong)ArrayGetAsSeries(P.indicator_values));for(int i=0;i<n;i++)Word(Bits(P.indicator_values[i]));}
double PrepOpen(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();End(38,(ulong)frame,(ulong)(long)shift,Bits(PrepOpenReply),0,symbol);Effect(38);return PrepOpenReply;}
int PrepATR(const string symbol,const ENUM_TIMEFRAMES frame,const int period){Begin();End(30,(ulong)frame,(ulong)(long)period,(ulong)(long)PrepHandle,0,symbol);Effect(30);return PrepHandle;}
int PrepCopy(const int handle,const int buffer,const int start,const int count,double &values[]){Begin();End(31,(ulong)(long)handle,(ulong)(long)buffer,(ulong)(long)start,(ulong)(long)count);Word((ulong)(long)PrepCopied);Word((ulong)PrepCount);Word(Bits(PrepSample));if(PrepCopied!=0){ArraySetAsSeries(values,false);ArrayResize(values,PrepCount);for(int i=0;i<PrepCount;i++)values[i]=PrepSample+(double)i*.125;}Effect(31);return PrepCopied;}
bool PrepTick(const string symbol,MqlTick &tick){Begin();End(32,(ulong)PrepTickOk,(ulong)PrepTickWrite,0,0,symbol);if(PrepTickWrite!=0){tick.time=(datetime)PrepNow;tick.bid=2000.;tick.ask=2002.;tick.last=2001.;tick.volume=31;tick.time_msc=PrepNow*1000;tick.flags=7;tick.volume_real=31.5;}Effect(32);return PrepTickOk!=0;}
datetime PrepTime(MqlDateTime &calendar){Begin();End(33,(ulong)PrepNow,(ulong)(long)PrepHour);calendar.year=2026;calendar.mon=10;calendar.day=28;calendar.hour=PrepHour;calendar.min=17;calendar.sec=19;calendar.day_of_week=3;calendar.day_of_year=300;Effect(33);return (datetime)PrepNow;}
datetime PrepTime(){Begin();End(36,(ulong)PrepNow);Effect(36);return (datetime)PrepNow;}
double PrepDouble(const string symbol,const ENUM_SYMBOL_INFO_DOUBLE prop){Begin();int n=PrepDPos++;double value=Doubles[0][n<8 ? n : 7];End(34,(ulong)prop,Bits(value),0,0,symbol);Effect(34);return value;}
long PrepInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER prop){Begin();int p=prop==SYMBOL_TRADE_STOPS_LEVEL ? 0 : (prop==SYMBOL_TRADE_FREEZE_LEVEL ? 1 : 2);int n=PrepIPos[p]++;long value=Integers[p][n<8 ? n : 7];End(35,(ulong)prop,(ulong)value,0,0,symbol);Effect(35);return value;}
void PrepPrint(const string value){Begin();End(37,1,0,0,0,value);Effect(37);}
void PrepPrint(const string value,const int error){Begin();End(37,2,(ulong)(long)error,0,0,value);Effect(37);}

datetime SelNow()
{
   Begin();
   int index=SelClockIndex;
   if(index<4) SelClockIndex++;
   else index=3;
   datetime value=(datetime)SelClocks[index];
   End(40,(ulong)value);
   Effect(40);
   return value;
}

bool SelStruct(datetime value,MqlDateTime &result)
{
   Begin();
   bool ok=TimeToStruct(value,result);
   End(41,(ulong)value,(ulong)ok);
   FileWriteInteger(Tape,result.year);
   FileWriteInteger(Tape,result.mon);
   FileWriteInteger(Tape,result.day);
   FileWriteInteger(Tape,result.hour);
   FileWriteInteger(Tape,result.min);
   FileWriteInteger(Tape,result.sec);
   FileWriteInteger(Tape,result.day_of_week);
   FileWriteInteger(Tape,result.day_of_year);
   Effect(41);
   return ok;
}

double SelMod(double left,double right)
{
   Begin();
   double value=MathMod(left,right);
   End(42,Bits(left),Bits(right),Bits(value));
   Effect(42);
   return value;
}

int SelConcat(string &output,int year,const string &suffix)
{
   Begin();
   if(output!="") SetUserError(900);
   int value=StringConcatenate(output,year,suffix);
   End(43,(ulong)(long)year,(ulong)(long)value,0,0,suffix,output);
   Effect(43);
   return value;
}

datetime SelDate(string value)
{
   Begin();
   datetime result=StringToTime(value);
   End(44,(ulong)result,0,0,0,value);
   Effect(44);
   return result;
}

double SelBalance(ENUM_ACCOUNT_INFO_DOUBLE property)
{
   Begin();
   if(property!=ACCOUNT_BALANCE) SetUserError(901);
   double value=SelBalanceReply;
   End(45,(ulong)property,Bits(value));
   Effect(45);
   return value;
}

string SelCurrency(ENUM_ACCOUNT_INFO_STRING property)
{
   Begin();
   if(property!=ACCOUNT_CURRENCY) SetUserError(901);
   int index=SelCurrencyIndex;
   if(index<SelCurrencyCount) SelCurrencyIndex++;
   else index=SelCurrencyCount-1;
   string value=SelCurrencies[index];
   End(46,(ulong)property,0,0,0,value);
   Effect(46);
   return value;
}

double SelClose(string symbol,ENUM_TIMEFRAMES timeframe,int shift)
{
   Begin();
   if(timeframe!=PERIOD_D1 || shift!=1) SetUserError(901);
   int index=SelPriceIndex;
   if(index<SelPriceCount) SelPriceIndex++;
   else index=SelPriceCount-1;
   double value=SelPrices[index];
   End(47,(ulong)timeframe,(ulong)(long)shift,Bits(value),0,symbol);
   Effect(47);
   return value;
}

void SelPrint(string message)
{
   Begin();
   End(48,0,0,0,0,message);
   Effect(48);
}


double InitAccountDouble(const ENUM_ACCOUNT_INFO_DOUBLE property){Begin();double v=property==ACCOUNT_BALANCE ? BankBalance : BankEquity;End(60,(ulong)property,Bits(v));Effect(60);return v;}
long InitAccountInteger(const ENUM_ACCOUNT_INFO_INTEGER property){Begin();End(61,(ulong)property,(ulong)BankLogin);Effect(61);return BankLogin;}
double InitGlobalGet(const string name){Begin();double v=name==BankPeakKey ? (BankHasPeak ? BankPeak : 0.) : (BankHasTime ? BankTime : 0.);End(62,Bits(v),0,0,0,name);Effect(62);return v;}
datetime InitGlobalSet(const string name,const double value){Begin();End(63,Bits(value),0,0,0,name);if(name==BankPeakKey){BankPeak=value;BankHasPeak=true;}else{BankTime=value;BankHasTime=true;}Effect(63);return 0;}
bool InitGlobalCheck(const string name){Begin();End(64,(ulong)BankHasTime,0,0,0,name);Effect(64);return BankHasTime;}
void InitSleep(const int milliseconds){Begin();End(65,(ulong)(long)milliseconds);Effect(65);}
datetime InitAccountTime(){Begin();End(66,(ulong)BankNow);Effect(66);return (datetime)BankNow;}
void InitAccountPrint(const string message){Begin();End(67,0,0,0,0,message);Effect(67);}

long InitCalendarInfo(const ENUM_MQL_INFO_INTEGER property){Begin();End(71,(ulong)property,(ulong)BankInfo);Effect(71);return BankInfo;}


long StartupNfp(){CalendarKind=0;return Bot3FindNfpTime();}
long StartupInterest(){CalendarKind=1;return Bot3FindInterestRateTime();}
long StartupCpi(){CalendarKind=2;return Bot3FindCpiTime();}
string Bot3InitializationTimeText(const datetime value){Begin();string text=(string)value;End(54,(ulong)value,0,0,0,text);Effect(54);return text;}
void StartupNewsPrint(const string value){Begin();End(55,0,0,0,0,value);Effect(55);}
datetime StartupNewsServer(){Begin();int i=Counts[56];long value=StartupClocks[i<3 ? i : 2];End(56,(ulong)value);Effect(56);return (datetime)value;}


datetime RealCalendarServer(){Begin();long value=CalendarReplies[CalendarKind].now;End(81,(ulong)value,(ulong)CalendarKind);Effect(81);return (datetime)value;}
int FillCalendarEvents(const int api,const string query,MqlCalendarEvent &events[]){Begin();int count=ArraySize(CalendarReplies[CalendarKind].ids);End(api,(ulong)(long)CalendarReplies[CalendarKind].event_return,(ulong)count,(ulong)CalendarReplies[CalendarKind].event_series,(ulong)CalendarKind,query);ArrayResize(events,count);ArraySetAsSeries(events,false);for(int i=0;i<count;i++){ZeroMemory(events[i]);events[i].id=CalendarReplies[CalendarKind].ids[i];events[i].name=CalendarReplies[CalendarKind].names[i];}ArraySetAsSeries(events,CalendarReplies[CalendarKind].event_series!=0);Effect(api);return CalendarReplies[CalendarKind].event_return;}
int RealEventsCurrency(const string currency,MqlCalendarEvent &events[]){return FillCalendarEvents(82,currency,events);}
int RealEventsCountry(const string country,MqlCalendarEvent &events[]){return FillCalendarEvents(83,country,events);}
int RealCalendarValues(const ulong event_id,MqlCalendarValue &values[],const datetime from,const datetime to=0){Begin();End(84,event_id,(ulong)from,(ulong)to,(ulong)(long)CalendarReplies[CalendarKind].value_return);Word((ulong)(long)CalendarReplies[CalendarKind].value_error);int count=ArraySize(CalendarReplies[CalendarKind].times);ArrayResize(values,count);ArraySetAsSeries(values,false);for(int i=0;i<count;i++){ZeroMemory(values[i]);values[i].time=(datetime)CalendarReplies[CalendarKind].times[i];}ArraySetAsSeries(values,CalendarReplies[CalendarKind].value_series!=0);if(CalendarReplies[CalendarKind].value_error>=0)InjectedCalendarError=CalendarReplies[CalendarKind].value_error;Effect(84);return CalendarReplies[CalendarKind].value_return;}
void RealCalendarPrint(const string value){Begin();End(85,0,0,0,0,value);Effect(85);}


double EntryHigh(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();double value=shift>=0 && shift<ArraySize(EntryHighValues) ? EntryHighValues[shift] : 0.;End(90,(ulong)frame,(ulong)(long)shift,Bits(value),0,symbol);Effect(90);return value;}
double EntryLow(const string symbol,const ENUM_TIMEFRAMES frame,const int shift){Begin();double value=shift>=0 && shift<ArraySize(EntryLowValues) ? EntryLowValues[shift] : 0.;End(91,(ulong)frame,(ulong)(long)shift,Bits(value),0,symbol);Effect(91);return value;}
int EntryOrdersTotal(){Begin();int value=ArraySize(EntryOrders);End(92,(ulong)value);Effect(92);return value;}
ulong EntryOrderTicket(const int index){Begin();EntrySelected=index;ulong value=index>=0 && index<ArraySize(EntryOrders) ? EntryOrders[index].ticket : 0;End(93,(ulong)(long)index,value);Effect(93);return value;}
long EntryOrderInteger(const ENUM_ORDER_PROPERTY_INTEGER property){Begin();long value=property==ORDER_MAGIC ? EntryOrders[EntrySelected].magic : EntryOrders[EntrySelected].kind;End(94,(ulong)property,(ulong)value);Effect(94);return value;}
string EntryOrderString(const ENUM_ORDER_PROPERTY_STRING property){Begin();string value=EntryOrders[EntrySelected].symbol;End(95,(ulong)property,0,0,0,value);Effect(95);return value;}
double EntryOrderDouble(const ENUM_ORDER_PROPERTY_DOUBLE property){Begin();double value=EntryOrders[EntrySelected].price;End(96,(ulong)property,Bits(value));Effect(96);return value;}
long EntrySymbolInteger(const string symbol,const ENUM_SYMBOL_INFO_INTEGER property){Begin();End(97,(ulong)property,(ulong)EntryDigits,0,0,symbol);Effect(97);return EntryDigits;}

int OnStart()
{
   if(CheckRun=="")return 1;string folder="bot3-startup-real-entry\\"+CheckRun+"\\";
   int file=FileOpen(folder+"cases.bin",FILE_READ|FILE_BIN);if(file==INVALID_HANDLE)return 2;
   int magic=FileReadInteger(file),version=FileReadInteger(file),count=FileReadInteger(file);if(magic!=0x4a4f4931 || version!=1 || count<1)return 3;
   int output=FileOpen(folder+"mql5-results.bin",FILE_WRITE|FILE_BIN),tapes=FileOpen(folder+"sdk-tape.bin",FILE_WRITE|FILE_BIN);if(output==INVALID_HANDLE || tapes==INVALID_HANDLE)return 4;
   FileWriteInteger(output,magic);FileWriteInteger(output,version);FileWriteInteger(output,count);FileWriteInteger(tapes,magic);FileWriteInteger(tapes,version);FileWriteInteger(tapes,count);
   for(int k=0;k<count;k++)
   {
      int id=FileReadInteger(file);
P.native_6d50c=(int)FileReadLong(file);
State.native_6d645=(uchar)FileReadLong(file);
P.strategy_index=(uint)FileReadLong(file);
P.entry_frame=(int)FileReadLong(file);
P.management_timeframe=(int)FileReadLong(file);
P.tick.ask=Value((ulong)FileReadLong(file));
P.tick.bid=Value((ulong)FileReadLong(file));
P.spread=Value((ulong)FileReadLong(file));
P.native_6d620=Value((ulong)FileReadLong(file));
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
P.native_6d5e8=Value((ulong)FileReadLong(file));
P.native_6d5f0=Value((ulong)FileReadLong(file));
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
Context.magic=(int)FileReadLong(file);
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
P.native_6d628=Value((ulong)FileReadLong(file));
Manager.table.guard=(uchar)FileReadLong(file);
Queue.enabled=(uchar)FileReadLong(file);
P.comment=ReadText(file);
Panel.font=(int)FileReadLong(file);
Panel.scale=Value((ulong)FileReadLong(file));
Panel.color_flag=(uchar)FileReadLong(file);
Panel.mode=(uint)FileReadLong(file);
Panel.strategy_risk=Value((ulong)FileReadLong(file));
Panel.frequency=(int)FileReadLong(file);
Panel.manual_lots=Value((ulong)FileReadLong(file));
Panel.allowed_dd=Value((ulong)FileReadLong(file));
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
Panel.closed[8]=Value((ulong)FileReadLong(file));
Panel.per_trade[0]=Value((ulong)FileReadLong(file));
Panel.per_trade[1]=Value((ulong)FileReadLong(file));
Panel.per_trade[2]=Value((ulong)FileReadLong(file));
Panel.per_trade[3]=Value((ulong)FileReadLong(file));
Panel.per_trade[4]=Value((ulong)FileReadLong(file));
Panel.per_trade[5]=Value((ulong)FileReadLong(file));
Panel.per_trade[6]=Value((ulong)FileReadLong(file));
Panel.per_trade[7]=Value((ulong)FileReadLong(file));
Panel.per_trade[8]=Value((ulong)FileReadLong(file));
Panel.lots[0]=Value((ulong)FileReadLong(file));
Panel.lots[1]=Value((ulong)FileReadLong(file));
Panel.lots[2]=Value((ulong)FileReadLong(file));
Panel.lots[3]=Value((ulong)FileReadLong(file));
Panel.lots[4]=Value((ulong)FileReadLong(file));
Panel.lots[5]=Value((ulong)FileReadLong(file));
Panel.lots[6]=Value((ulong)FileReadLong(file));
Panel.lots[7]=Value((ulong)FileReadLong(file));
Panel.lots[8]=Value((ulong)FileReadLong(file));
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
ContextInputs.base_magic=(int)FileReadLong(file);
Balance=Value((ulong)FileReadLong(file));
Wins=Value((ulong)FileReadLong(file));
Losses=Value((ulong)FileReadLong(file));
Context.order_comment=ReadText(file);
Inputs.symbol=ReadText(file);
TailState.buy_first=ReadText(file);
TailState.buy_second=ReadText(file);
TailState.sell_first=ReadText(file);
TailState.sell_second=ReadText(file);
TailState.flag_744a0=(uchar)FileReadLong(file);
TailBars[0]=FileReadLong(file);
TailBars[1]=FileReadLong(file);
TailBars[2]=FileReadLong(file);
TailBars[3]=FileReadLong(file);
TailBars[4]=FileReadLong(file);
TailBars[5]=FileReadLong(file);
TailBars[6]=FileReadLong(file);
TailBars[7]=FileReadLong(file);
TailBars[8]=FileReadLong(file);
Inputs.indicator_period=(int)FileReadLong(file);
Inputs.indicator_timeframe=(int)FileReadLong(file);
Inputs.reference=Value((ulong)FileReadLong(file));
Inputs.variable_distances=(uchar)FileReadLong(file);
Inputs.adjust_lots=(uchar)FileReadLong(file);
Inputs.max_spread=Value((ulong)FileReadLong(file));
Inputs.feature_flag=(uchar)FileReadLong(file);
Inputs.freeze_buffer_flag=(uchar)FileReadLong(file);
Inputs.entry.entry_frame=(int)FileReadLong(file);
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
Inputs.native_6d368=Value((ulong)FileReadLong(file));
Inputs.native_6d370=Value((ulong)FileReadLong(file));
Inputs.trigger_distance=Value((ulong)FileReadLong(file));
Inputs.locked_distance=Value((ulong)FileReadLong(file));
Inputs.aux_hour1=(uchar)FileReadLong(file);
Inputs.aux_scan50=(uchar)FileReadLong(file);
Inputs.aux_older=(int)FileReadLong(file);
Inputs.aux_recent=(int)FileReadLong(file);
Inputs.aux_offset=Value((ulong)FileReadLong(file));
Inputs.min_change=Value((ulong)FileReadLong(file));
Inputs.native_6d250=Value((ulong)FileReadLong(file));
Inputs.native_6d258=(uchar)FileReadLong(file);
Inputs.native_6d260=Value((ulong)FileReadLong(file));
Inputs.native_6d268=Value((ulong)FileReadLong(file));
Inputs.native_6d270=Value((ulong)FileReadLong(file));
Inputs.native_6d278=(uchar)FileReadLong(file);
Inputs.native_1d6fa8=(int)FileReadLong(file);
Inputs.native_1d6fc0=(uchar)FileReadLong(file);
Inputs.virtual_stops=(uchar)FileReadLong(file);
Inputs.native_1d6fe8=(int)FileReadLong(file);
Inputs.native_1d7178=(uchar)FileReadLong(file);
Inputs.native_6d2a3=(uchar)FileReadLong(file);
Inputs.native_6d2e0=(int)FileReadLong(file);
Inputs.management_timeframe=(int)FileReadLong(file);
Inputs.native_6d3f8=(uchar)FileReadLong(file);
Inputs.native_6d3f0=Value((ulong)FileReadLong(file));
Inputs.native_6d408=Value((ulong)FileReadLong(file));
Inputs.native_6d410=Value((ulong)FileReadLong(file));
Inputs.native_1d7130=(int)FileReadLong(file);
Inputs.native_6d418=Value((ulong)FileReadLong(file));
Inputs.native_6d420=(uchar)FileReadLong(file);
Inputs.comment=ReadText(file);
P.scale=Value((ulong)FileReadLong(file));
P.lot_scale=Value((ulong)FileReadLong(file));
P.feature_flag=(uchar)FileReadLong(file);
P.trail_start=Value((ulong)FileReadLong(file));
P.trail_limit=Value((ulong)FileReadLong(file));
P.trail_step=Value((ulong)FileReadLong(file));
P.native_6d378=Value((ulong)FileReadLong(file));
P.native_6d380=Value((ulong)FileReadLong(file));
P.aux_frame=(int)FileReadLong(file);
P.aux_scan=(int)FileReadLong(file);
P.aux_older=(int)FileReadLong(file);
P.aux_recent=(int)FileReadLong(file);
P.aux_offset=Value((ulong)FileReadLong(file));
P.native_6d4e0=Value((ulong)FileReadLong(file));
P.native_6d4e8=(int)FileReadLong(file);
P.native_6d4f0=Value((ulong)FileReadLong(file));
P.native_6d4f8=Value((ulong)FileReadLong(file));
P.native_6d500=Value((ulong)FileReadLong(file));
P.native_6d508=(uchar)FileReadLong(file);
P.native_6d510=(uchar)FileReadLong(file);
P.mode=(int)FileReadLong(file);
P.native_6d518=(int)FileReadLong(file);
P.native_6d51c=(uchar)FileReadLong(file);
P.native_6d520=(int)FileReadLong(file);
P.native_6d550=(int)FileReadLong(file);
P.native_6d608=(int)FileReadLong(file);
P.native_6d600=Value((ulong)FileReadLong(file));
P.native_6d618=Value((ulong)FileReadLong(file));
P.native_6d638=Value((ulong)FileReadLong(file));
P.native_6d640=(int)FileReadLong(file);
P.native_6d5c8=(uchar)FileReadLong(file);
P.native_6d5dc=(uchar)FileReadLong(file);
P.native_6d5f8=(uchar)FileReadLong(file);
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
Context.converted_value=Value((ulong)FileReadLong(file));
ContextInputs.keep_comment=(uchar)FileReadLong(file);
Daily.peak=Value((ulong)FileReadLong(file));
Daily.blocked=(uchar)FileReadLong(file);
Daily.bars=(int)FileReadLong(file);
Startup.panel_bar=FileReadLong(file);
History.total=(int)FileReadLong(file);
History.count=(int)FileReadLong(file);
Startup.extended_cleanup=(uchar)FileReadLong(file);
Startup.cell_base_x=Value((ulong)FileReadLong(file));
Startup.cell_base_y=Value((ulong)FileReadLong(file));
ContextInputs.comment_prefix=ReadText(file);
ContextInputs.symbol_suffix=ReadText(file);
ChartName=ReadText(file);
WinterHours=(int)FileReadLong(file);
SummerHours=(int)FileReadLong(file);
AdjustedTime=FileReadLong(file);
Frequency=(int)FileReadLong(file);
FrequencyDivisor=Value((ulong)FileReadLong(file));
Thresholds[0]=(uchar)FileReadLong(file);
Thresholds[1]=(uchar)FileReadLong(file);
Thresholds[2]=(uchar)FileReadLong(file);
Manual[0]=(uchar)FileReadLong(file);
Manual[1]=(uchar)FileReadLong(file);
Manual[2]=(uchar)FileReadLong(file);
Manual[3]=(uchar)FileReadLong(file);
Manual[4]=(uchar)FileReadLong(file);
Manual[5]=(uchar)FileReadLong(file);
Manual[6]=(uchar)FileReadLong(file);
Manual[7]=(uchar)FileReadLong(file);
Manual[8]=(uchar)FileReadLong(file);
Enabled[0]=(uchar)FileReadLong(file);
Enabled[1]=(uchar)FileReadLong(file);
Enabled[2]=(uchar)FileReadLong(file);
Enabled[3]=(uchar)FileReadLong(file);
Enabled[4]=(uchar)FileReadLong(file);
Enabled[5]=(uchar)FileReadLong(file);
Enabled[6]=(uchar)FileReadLong(file);
Enabled[7]=(uchar)FileReadLong(file);
Enabled[8]=(uchar)FileReadLong(file);
UseEquity=(uchar)FileReadLong(file);
ResetHighest=(uchar)FileReadLong(file);
ManualBalance=Value((ulong)FileReadLong(file));
HighestBalance=Value((ulong)FileReadLong(file));
PeakKey=ReadText(file);
TimeKey=ReadText(file);
AccountLastTime=FileReadLong(file);
NewsFlag0=(uchar)FileReadLong(file);
NewsFlag1=(uchar)FileReadLong(file);
Nfp.last_query=FileReadLong(file);

      for(int i=0;i<4;i++)for(int j=0;j<8;j++)Doubles[i][j]=Value((ulong)FileReadLong(file));
      for(int i=0;i<3;i++)for(int j=0;j<8;j++)Integers[i][j]=FileReadLong(file);
      for(int i=0;i<8;i++)Times[i]=FileReadLong(file);for(int i=0;i<2;i++)BarsReply[i]=FileReadLong(file);for(int i=0;i<3;i++)BarTimes[i]=FileReadLong(file);
      AccountReply=Value((ulong)FileReadLong(file));for(int i=0;i<2;i++)LevelReply[i]=Value((ulong)FileReadLong(file));
      EffectCount=FileReadInteger(file);if(EffectCount<0 || EffectCount>32)return 8;for(int i=0;i<EffectCount;i++)for(int j=0;j<4;j++)Effects[i][j]=(ulong)FileReadLong(file);
      InfoReply=FileReadInteger(file);SelectReply=FileReadInteger(file);TotalReply=FileReadInteger(file);DealCount=FileReadInteger(file);if(DealCount<0 || DealCount>32)return 8;
      for(int i=0;i<DealCount;i++)for(int j=0;j<4;j++)Deals[i][j]=(ulong)FileReadLong(file);
      for(int i=0;i<8;i++)TailTimes[i]=FileReadLong(file);Selected=-1;
PrepHandle=(int)FileReadLong(file);PrepCopied=(int)FileReadLong(file);PrepCount=(int)FileReadLong(file);PrepSample=Value((ulong)FileReadLong(file));PrepTickOk=(int)FileReadLong(file);PrepTickWrite=(int)FileReadLong(file);PrepHour=(int)FileReadLong(file);PrepNow=FileReadLong(file);PrepOpenReply=Value((ulong)FileReadLong(file));
   for(int i=0;i<4;i++) SelClocks[i]=FileReadLong(file);
   SelBalanceReply=Value((ulong)FileReadLong(file));
   SelCurrencyCount=FileReadInteger(file);
   if(SelCurrencyCount<1 || SelCurrencyCount>64) return 8;
   for(int i=0;i<SelCurrencyCount;i++) SelCurrencies[i]=ReadText(file);
   SelPriceCount=FileReadInteger(file);
   if(SelPriceCount<1 || SelPriceCount>64) return 8;
   for(int i=0;i<SelPriceCount;i++) SelPrices[i]=Value((ulong)FileReadLong(file));
   SelClockIndex=0;
   SelCurrencyIndex=0;
   SelPriceIndex=0;
BankLogin=FileReadLong(file);BankBalance=Value((ulong)FileReadLong(file));BankEquity=Value((ulong)FileReadLong(file));BankHasPeak=FileReadLong(file)!=0;BankPeak=Value((ulong)FileReadLong(file));BankHasTime=FileReadLong(file)!=0;BankTime=Value((ulong)FileReadLong(file));BankNow=FileReadLong(file);NewsSeed=FileReadLong(file);BankInfo=FileReadLong(file);for(int i=0;i<3;i++)StartupReplies[i]=FileReadLong(file);for(int i=0;i<3;i++)StartupClocks[i]=FileReadLong(file);
for(int k=0;k<3;k++){CalendarReplies[k].now=FileReadLong(file);CalendarReplies[k].event_return=(int)FileReadLong(file);CalendarReplies[k].value_return=(int)FileReadLong(file);CalendarReplies[k].event_series=(int)FileReadLong(file);CalendarReplies[k].value_series=(int)FileReadLong(file);CalendarReplies[k].value_error=(int)FileReadLong(file);int count=(int)FileReadLong(file);if(count<0 || count>32)return 8;ArrayResize(CalendarReplies[k].ids,count);ArrayResize(CalendarReplies[k].names,count);for(int i=0;i<count;i++){CalendarReplies[k].ids[i]=(ulong)FileReadLong(file);CalendarReplies[k].names[i]=ReadText(file);}count=(int)FileReadLong(file);if(count<0 || count>32)return 8;ArrayResize(CalendarReplies[k].times,count);for(int i=0;i<count;i++)CalendarReplies[k].times[i]=FileReadLong(file);}InjectedCalendarError=-1;CalendarKind=-1;
EntryDigits=FileReadLong(file);int entry_count=(int)FileReadInteger(file);if(entry_count<0 || entry_count>128)return 8;ArrayResize(EntryHighValues,entry_count);for(int i=0;i<entry_count;i++)EntryHighValues[i]=FileReadDouble(file);entry_count=FileReadInteger(file);if(entry_count<0 || entry_count>128)return 8;ArrayResize(EntryLowValues,entry_count);for(int i=0;i<entry_count;i++)EntryLowValues[i]=FileReadDouble(file);entry_count=FileReadInteger(file);if(entry_count<0 || entry_count>32)return 8;ArrayResize(EntryOrders,entry_count);for(int i=0;i<entry_count;i++){EntryOrders[i].ticket=(ulong)FileReadLong(file);EntryOrders[i].magic=FileReadLong(file);EntryOrders[i].kind=FileReadInteger(file);EntryOrders[i].price=FileReadDouble(file);EntryOrders[i].symbol=ReadText(file);}EntrySelected=-1;


BankPeakKey="HighestBalance"+IntegerToString(BankLogin);BankTimeKey="LastBalanceOp"+IntegerToString(BankLogin);for(int i=0;i<300;i++){NewsNfp[i]=NewsSeed+i*17;NewsInterest[i]=NewsSeed+10000+i*17;NewsCpi[i]=NewsSeed+20000+i*17;}


ArraySetAsSeries(P.indicator_values,false);ArrayResize(P.indicator_values,2);P.indicator_values[0]=-11.;P.indicator_values[1]=-12.;PrepDPos=0;ArrayInitialize(PrepIPos,0);
Inputs.native_1d7138=Panel.manual_lots;
P.native_6d630=(int)Panel.mode;

      for(int i=0;i<500;i++)for(int j=0;j<3;j++)Manager.table.rows[i][j]=(double)(3*i+j+1)*.125;
      for(int i=0;i<500;i++)for(int j=0;j<2;j++)Manager.table.take_rows[i][j]=(double)(2*i+j+1)*.375;
      for(int i=0;i<100;i++)for(int j=0;j<3;j++)Queue.orders[i][j]=(double)(3*i+j+1)*.25;
      ArrayInitialize(Counts,0);ArrayInitialize(DPos,0);ArrayInitialize(IPos,0);string part=folder+"tape-"+IntegerToString(id)+".bin";Tape=FileOpen(part,FILE_WRITE|FILE_BIN);if(Tape==INVALID_HANDLE)return 5;
      ResetLastError();Final=false;ErrorOverride=-1;
      Result=Bot3InitializeStartupNewsFlow(UseEquity,ResetHighest,ManualBalance,HighestBalance,PeakKey,TimeKey,AccountLastTime,NewsFlag0,NewsFlag1,NewsNfp,NewsInterest,NewsCpi,WinterHours,SummerHours,AdjustedTime,Frequency,Thresholds,Manual,Enabled,FrequencyDivisor,ChartName,ContextInputs,Context,History,Daily,Startup,Inputs,P,Entry,Nfp,Interest,Cpi,Manager,Queue,Levels,MinimumSpread,TailBars,Show,Tester,HistoryWindow,Balance,Panel,Events,Windows,Selection,LastTicket,LastHour,Wins,Losses,State,TailState);
      int error=GetLastError();FileClose(Tape);int section=FileOpen(part,FILE_READ|FILE_BIN);if(section==INVALID_HANDLE)return 6;int size=(int)FileSize(section);uchar raw[];ArrayResize(raw,size);if(size>0)FileReadArray(section,raw);FileClose(section);
      FileWriteInteger(tapes,id);FileWriteInteger(tapes,size);if(size>0)FileWriteArray(tapes,raw);
      FileWriteInteger(output,id);Tape=output;Final=true;ErrorOverride=error;Begin();
   }
   if(FileTell(file)!=FileSize(file))return 9;FileClose(file);FileClose(output);FileClose(tapes);int status=FileOpen(folder+"script-status.bin",FILE_WRITE|FILE_BIN);if(status==INVALID_HANDLE)return 7;FileWriteInteger(status,0);FileWriteInteger(status,count);FileClose(status);return 0;
}

#undef GetLastError
int CalendarError(){return InjectedCalendarError<0 ? GetLastError() : InjectedCalendarError;}
int CalendarStringFind(const string value,const string needle,const int start=0){int previous=CalendarError();ResetLastError();int result=StringFind(value,needle,start);int error=GetLastError();InjectedCalendarError=error==0 ? previous : error;return result;}

#undef StringSubstr
string CalendarStringSubstr(const string value,const int start,const int length){int previous=CalendarError();ResetLastError();string result=StringSubstr(value,start,length);int error=GetLastError();InjectedCalendarError=error==0 ? previous : error;return result;}
