#property strict
#property library
#property version "1.00"

// Exported wrappers remain available for inspection. The driver calls Anchor only.
long P_Anchor(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Anchor");
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
