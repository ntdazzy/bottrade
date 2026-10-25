#property strict
#property library
#property version "1.00"
#include <bot-cua-toi-1/Bot1PendingQueue.mqh>
#include <bot-cua-toi-3/Bot3PendingQueue.mqh>

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

Bot1PendingQueue Queue1;
Bot1PendingQueueContext Context1;
Bot1PendingRequestState Trade1;
Bot1TradeSendOptions Options1;
Bot3PendingQueue Queue3;
Bot3PendingQueueContext Context3;
Bot3PendingRequestState Trade3;
Bot3TradeSendOptions Options3;
bool P_QueueBuilder1(const int index,const ENUM_ORDER_TYPE type) export
{
   Print("EX5_API_PROBE:QueueBuilder1");
   return Bot1SendQueuedPending(Queue1,Context1,Trade1,Options1,index,type);
}
bool P_QueueBuilder3(const int index,const ENUM_ORDER_TYPE type) export
{
   Print("EX5_API_PROBE:QueueBuilder3");
   return Bot3SendQueuedPending(Queue3,Context3,Trade3,Options3,index,type);
}
double P_Subtract(const double left,const double right) export
{
   Print("EX5_API_PROBE:Subtract");
   return left-right;
}
double P_SubtractCompound(const double left,const double right) export
{
   Print("EX5_API_PROBE:SubtractCompound");
   double value=left;
   value-=right;
   return value;
}
string P_Int32Text(const int value) export
{
   Print("EX5_API_PROBE:Int32Text");
   return (string)value;
}
string P_Uint32Text(const uint value) export
{
   Print("EX5_API_PROBE:Uint32Text");
   return (string)value;
}
string P_Int64Text(const long value) export
{
   Print("EX5_API_PROBE:Int64Text");
   return (string)value;
}
void P_QueueClear() export
{
   Print("EX5_API_PROBE:QueueClear");
   ZeroMemory(Queue1.orders);
}

string P_DoubleText(const double value) export
{
   Print("EX5_API_PROBE:DoubleText");
   return (string)value;
}
