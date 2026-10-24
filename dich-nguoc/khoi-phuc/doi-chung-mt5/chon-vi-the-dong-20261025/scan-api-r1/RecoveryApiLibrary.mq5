#property strict
#property library
#property version "1.00"

// Exported wrappers remain available for inspection. The driver calls Anchor only.
long P_Anchor(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Anchor");
   PrintFormat("CLOSE_ENUMS:%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d",(int)TRADE_ACTION_DEAL,(int)POSITION_MAGIC,(int)POSITION_TYPE,(int)POSITION_VOLUME,(int)POSITION_SL,(int)POSITION_TP,(int)POSITION_PRICE_CURRENT,(int)POSITION_SYMBOL,(int)SYMBOL_BID,(int)SYMBOL_ASK,(int)POSITION_TYPE_BUY,(int)POSITION_TYPE_SELL);
   PrintFormat("SCAN_ENUMS:%d|%d|%d",(int)SYMBOL_TRADE_STOPS_LEVEL,(int)SYMBOL_TRADE_FREEZE_LEVEL,(int)SYMBOL_POINT);
   return k;
}

double P_GlobalVariableGet(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:GlobalVariableGet");
   return GlobalVariableGet(s);
}

bool P_GlobalVariableGetRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:GlobalVariableGetRef");
   double value=0.0;
   return GlobalVariableGet(s,value);
}

long P_GlobalVariableSet(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:GlobalVariableSet");
   return (long)GlobalVariableSet(s,x);
}

bool P_GlobalVariableCheck(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:GlobalVariableCheck");
   return GlobalVariableCheck(s);
}

bool P_GlobalVariableDel(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:GlobalVariableDel");
   return GlobalVariableDel(s);
}

int P_ObjectsDeleteAll(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectsDeleteAll");
   return ObjectsDeleteAll(k,-1,-1);
}

int P_ObjectsDeleteAllPrefix(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectsDeleteAllPrefix");
   return ObjectsDeleteAll(k,s,-1,-1);
}

double P_TesterStatistics(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TesterStatistics");
   return TesterStatistics((ENUM_STATISTICS)k);
}

int P_MessageBox(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MessageBox");
   return MessageBox(s,s,(int)k);
}

int P_CalendarEventByCountry(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CalendarEventByCountry");
   MqlCalendarEvent events[];
   return CalendarEventByCountry(s,events);
}

int P_CalendarEventByCurrency(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CalendarEventByCurrency");
   MqlCalendarEvent events[];
   return CalendarEventByCurrency(s,events);
}

int P_CalendarValueHistoryByEvent(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CalendarValueHistoryByEvent");
   MqlCalendarValue values[];
   return CalendarValueHistoryByEvent((ulong)k,values,(datetime)x,0);
}

int P_CalendarValueHistory(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CalendarValueHistory");
   MqlCalendarValue values[];
   return CalendarValueHistory(values,(datetime)k,(datetime)x,s,NULL);
}

bool P_CalendarEventById(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CalendarEventById");
   MqlCalendarEvent event;
   return CalendarEventById((ulong)k,event);
}

bool P_CalendarCountryById(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CalendarCountryById");
   MqlCalendarCountry country;
   return CalendarCountryById((long)k,country);
}

bool P_CalendarValueById(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CalendarValueById");
   MqlCalendarValue value;
   return CalendarValueById((ulong)k,value);
}

string P_StringToLower(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringToLower");
   string value=s;
   StringToLower(value);
   return value;
}

double P_TickBid(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TickBid");
   MqlTick tick;
   if(!SymbolInfoTick(s,tick)) return x;
   return tick.bid;
}

double P_TickAsk(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TickAsk");
   MqlTick tick;
   if(!SymbolInfoTick(s,tick)) return x;
   return tick.ask;
}

double P_CancelPoint(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CancelPoint");
   return SymbolInfoDouble(s,SYMBOL_POINT);
}

long P_CancelFreeze(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CancelFreeze");
   return SymbolInfoInteger(s,SYMBOL_TRADE_FREEZE_LEVEL);
}

bool P_CloseSelect(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseSelect");
   return PositionSelectByTicket((ulong)k);
}

long P_CloseMagic(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseMagic");
   return PositionGetInteger(POSITION_MAGIC);
}

long P_CloseType(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseType");
   return PositionGetInteger(POSITION_TYPE);
}

double P_CloseVolume(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseVolume");
   return PositionGetDouble(POSITION_VOLUME);
}

double P_CloseSL(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseSL");
   return PositionGetDouble(POSITION_SL);
}

double P_CloseTP(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseTP");
   return PositionGetDouble(POSITION_TP);
}

double P_CloseCurrent(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseCurrent");
   return PositionGetDouble(POSITION_PRICE_CURRENT);
}

long P_CloseSymbol(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseSymbol");
   return StringLen(PositionGetString(POSITION_SYMBOL));
}

double P_CloseBid(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseBid");
   return SymbolInfoDouble(s,SYMBOL_BID);
}

double P_CloseAsk(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseAsk");
   return SymbolInfoDouble(s,SYMBOL_ASK);
}

double P_CloseAbs(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CloseAbs");
   return MathAbs(x);
}

int P_ScanTotal(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ScanTotal");
   return PositionsTotal();
}

ulong P_ScanTicket(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ScanTicket");
   return PositionGetTicket((int)k);
}

long P_ScanStops(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ScanStops");
   return SymbolInfoInteger(s,SYMBOL_TRADE_STOPS_LEVEL);
}
