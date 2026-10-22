#property strict
#property library
#property version "1.00"
class CProbeBase { public: int value; virtual ~CProbeBase(void) {} };
class CProbeDerived : public CProbeBase { public: int other; };

long P_IdentityLong(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:IdentityLong");
   return k;
}

double P_IdentityDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:IdentityDouble");
   return x;
}

string P_IdentityString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:IdentityString");
   return s;
}

long P_GetLastError(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:GetLastError");
   return GetLastError();
}

long P_GetTickCount(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:GetTickCount");
   return (long)GetTickCount();
}

long P_GetTickCount64(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:GetTickCount64");
   return (long)GetTickCount64();
}

long P_GetMicrosecondCount(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:GetMicrosecondCount");
   return (long)GetMicrosecondCount();
}

long P_MQLInfoInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MQLInfoInteger");
   return MQLInfoInteger((ENUM_MQL_INFO_INTEGER)k);
}

long P_TerminalInfoInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TerminalInfoInteger");
   return TerminalInfoInteger((ENUM_TERMINAL_INFO_INTEGER)k);
}

bool P_IsStopped(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:IsStopped");
   return IsStopped();
}

long P_AccountInfoInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:AccountInfoInteger");
   return AccountInfoInteger(ACCOUNT_LEVERAGE);
}

double P_AccountInfoDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:AccountInfoDouble");
   return AccountInfoDouble(ACCOUNT_BALANCE);
}

string P_AccountInfoString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:AccountInfoString");
   return AccountInfoString(ACCOUNT_CURRENCY);
}

long P_SymbolInfoInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SymbolInfoInteger");
   return SymbolInfoInteger(s,(ENUM_SYMBOL_INFO_INTEGER)k);
}

double P_SymbolInfoDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SymbolInfoDouble");
   return SymbolInfoDouble(s,(ENUM_SYMBOL_INFO_DOUBLE)k);
}

string P_SymbolInfoString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SymbolInfoString");
   return SymbolInfoString(s,(ENUM_SYMBOL_INFO_STRING)k);
}

string P_Symbol(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Symbol");
   return Symbol();
}

long P_Period(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Period");
   return Period();
}

long P_Digits(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Digits");
   return Digits();
}

double P_Point(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Point");
   return Point();
}

long P_TimeCurrent(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TimeCurrent");
   return (long)TimeCurrent();
}

long P_TimeLocal(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TimeLocal");
   return (long)TimeLocal();
}

long P_TimeGMT(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TimeGMT");
   return (long)TimeGMT();
}

long P_TimeGMTOffset(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TimeGMTOffset");
   return (long)TimeGMTOffset();
}

long P_TimeTradeServer(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TimeTradeServer");
   return (long)TimeTradeServer();
}

string P_TimeToString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TimeToString");
   return TimeToString((datetime)k,(int)x);
}

long P_StringToTime(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringToTime");
   return (long)StringToTime(s);
}

string P_IntegerToString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:IntegerToString");
   return IntegerToString(k);
}

string P_DoubleToString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:DoubleToString");
   return DoubleToString(x,(int)k);
}

long P_StringLen(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringLen");
   return StringLen(s);
}

long P_StringFind(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringFind");
   return StringFind(s,"x",(int)k);
}

string P_StringSubstr(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringSubstr");
   return StringSubstr(s,(int)k,2);
}

long P_StringGetCharacter(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringGetCharacter");
   return StringGetCharacter(s,(int)k);
}

long P_StringToInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringToInteger");
   return StringToInteger(s);
}

double P_StringToDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringToDouble");
   return StringToDouble(s);
}

double P_NormalizeDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:NormalizeDouble");
   return NormalizeDouble(x,(int)k);
}

double P_MathRound(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathRound");
   return MathRound(x);
}

double P_MathFloor(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathFloor");
   return MathFloor(x);
}

double P_MathCeil(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathCeil");
   return MathCeil(x);
}

double P_MathAbs(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathAbs");
   return MathAbs(x);
}

double P_MathPow(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathPow");
   return MathPow(x,(double)k);
}

long P_PositionsTotal(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionsTotal");
   return PositionsTotal();
}

long P_PositionGetTicket(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionGetTicket");
   return (long)PositionGetTicket((int)k);
}

string P_PositionGetSymbol(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionGetSymbol");
   return PositionGetSymbol((int)k);
}

bool P_PositionSelect(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionSelect");
   return PositionSelect(s);
}

bool P_PositionSelectByTicket(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionSelectByTicket");
   return PositionSelectByTicket((ulong)k);
}

long P_PositionGetInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionGetInteger");
   return PositionGetInteger((ENUM_POSITION_PROPERTY_INTEGER)k);
}

double P_PositionGetDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionGetDouble");
   return PositionGetDouble((ENUM_POSITION_PROPERTY_DOUBLE)k);
}

string P_PositionGetString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionGetString");
   return PositionGetString((ENUM_POSITION_PROPERTY_STRING)k);
}

long P_OrdersTotal(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrdersTotal");
   return OrdersTotal();
}

long P_OrderGetTicket(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderGetTicket");
   return (long)OrderGetTicket((int)k);
}

bool P_OrderSelect(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderSelect");
   return OrderSelect((ulong)k);
}

long P_OrderGetInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderGetInteger");
   return OrderGetInteger((ENUM_ORDER_PROPERTY_INTEGER)k);
}

double P_OrderGetDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderGetDouble");
   return OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)k);
}

string P_OrderGetString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderGetString");
   return OrderGetString((ENUM_ORDER_PROPERTY_STRING)k);
}

bool P_HistorySelect(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistorySelect");
   return HistorySelect((datetime)k,(datetime)(k+60));
}

bool P_HistoryDealSelect(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryDealSelect");
   return HistoryDealSelect((ulong)k);
}

long P_HistoryDealsTotal(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryDealsTotal");
   return HistoryDealsTotal();
}

long P_HistoryDealGetTicket(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryDealGetTicket");
   return (long)HistoryDealGetTicket((int)k);
}

long P_HistoryDealGetInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryDealGetInteger");
   return HistoryDealGetInteger((ulong)k,(ENUM_DEAL_PROPERTY_INTEGER)(int)x);
}

double P_HistoryDealGetDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryDealGetDouble");
   return HistoryDealGetDouble((ulong)k,(ENUM_DEAL_PROPERTY_DOUBLE)(int)x);
}

string P_HistoryDealGetString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryDealGetString");
   return HistoryDealGetString((ulong)k,(ENUM_DEAL_PROPERTY_STRING)(int)x);
}

long P_iATR(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iATR");
   return iATR(s,(ENUM_TIMEFRAMES)(int)k,(int)x);
}

double P_iOpen(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iOpen");
   return iOpen(s,(ENUM_TIMEFRAMES)(int)k,(int)x);
}

double P_iHigh(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iHigh");
   return iHigh(s,(ENUM_TIMEFRAMES)(int)k,(int)x);
}

double P_iLow(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iLow");
   return iLow(s,(ENUM_TIMEFRAMES)(int)k,(int)x);
}

double P_iClose(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iClose");
   return iClose(s,(ENUM_TIMEFRAMES)(int)k,(int)x);
}

long P_iTime(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iTime");
   return (long)iTime(s,(ENUM_TIMEFRAMES)(int)k,(int)x);
}

long P_Bars(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Bars");
   return Bars(s,(ENUM_TIMEFRAMES)(int)k);
}

bool P_IndicatorRelease(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:IndicatorRelease");
   return IndicatorRelease((int)k);
}

long P_ChartID(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ChartID");
   return ChartID();
}

long P_ChartGetInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ChartGetInteger");
   return ChartGetInteger(k,(ENUM_CHART_PROPERTY_INTEGER)(int)x,0);
}

long P_ObjectFind(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectFind");
   return ObjectFind(k,s);
}

bool P_ObjectDelete(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectDelete");
   return ObjectDelete(k,s);
}

long P_ObjectsDeleteAllPrefix(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectsDeleteAllPrefix");
   return ObjectsDeleteAll(k,s,-1,-1);
}

long P_ObjectGetInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectGetInteger");
   return ObjectGetInteger(k,s,(ENUM_OBJECT_PROPERTY_INTEGER)(int)x,0);
}

double P_ObjectGetDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectGetDouble");
   return ObjectGetDouble(k,s,(ENUM_OBJECT_PROPERTY_DOUBLE)(int)x,0);
}

string P_ObjectGetString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectGetString");
   return ObjectGetString(k,s,(ENUM_OBJECT_PROPERTY_STRING)(int)x,0);
}

bool P_ObjectSetInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectSetInteger");
   return ObjectSetInteger(k,s,OBJPROP_XDISTANCE,(long)x);
}

bool P_ObjectSetDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectSetDouble");
   return ObjectSetDouble(k,s,OBJPROP_PRICE,x);
}

bool P_ObjectSetString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectSetString");
   return ObjectSetString(k,s,OBJPROP_TEXT,s);
}

bool P_ResourceFree(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ResourceFree");
   return ResourceFree(s);
}

bool P_TextSetFont(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TextSetFont");
   return TextSetFont(s,(int)k,0,0);
}

long P_ColorToARGB(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ColorToARGB");
   return (long)ColorToARGB((color)k,(uchar)x);
}

long P_ResetLastError(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ResetLastError");
   ResetLastError(); return 0;
}

long P_ChartRedraw(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ChartRedraw");
   ChartRedraw(k); return 0;
}

bool P_EventSetTimer(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:EventSetTimer");
   return EventSetTimer((int)k);
}

long P_EventKillTimer(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:EventKillTimer");
   EventKillTimer(); return 0;
}

bool P_SymbolInfoIntegerRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SymbolInfoIntegerRef");
   long v; return SymbolInfoInteger(s,(ENUM_SYMBOL_INFO_INTEGER)k,v);
}

bool P_SymbolInfoDoubleRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SymbolInfoDoubleRef");
   double v; return SymbolInfoDouble(s,(ENUM_SYMBOL_INFO_DOUBLE)k,v);
}

bool P_SymbolInfoStringRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SymbolInfoStringRef");
   string v; return SymbolInfoString(s,(ENUM_SYMBOL_INFO_STRING)k,v);
}

bool P_SymbolInfoTick(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SymbolInfoTick");
   MqlTick v; return SymbolInfoTick(s,v);
}

bool P_SymbolInfoSessionTrade(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SymbolInfoSessionTrade");
   datetime a,b; return SymbolInfoSessionTrade(s,(ENUM_DAY_OF_WEEK)k,0,a,b);
}

bool P_TimeToStruct(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TimeToStruct");
   MqlDateTime v; return TimeToStruct((datetime)k,v);
}

long P_StructToTime(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StructToTime");
   MqlDateTime v; ZeroMemory(v); v.year=(int)k; return (long)StructToTime(v);
}

string P_StringToUpper(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringToUpper");
   string v=s; StringToUpper(v); return v;
}

string P_StringToLower(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringToLower");
   string v=s; StringToLower(v); return v;
}

string P_StringTrimLeft(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringTrimLeft");
   string v=s; StringTrimLeft(v); return v;
}

string P_StringTrimRight(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringTrimRight");
   string v=s; StringTrimRight(v); return v;
}

long P_StringReplace(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringReplace");
   string v=s; return StringReplace(v,"a","b");
}

long P_StringSplit(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringSplit");
   string values[]; return StringSplit(s,ushort(k),values);
}

string P_StringFormat(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringFormat");
   return StringFormat("%I64d %.3f %s",k,x,s);
}

long P_CopyBuffer(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CopyBuffer");
   double values[]; return CopyBuffer((int)k,0,0,1,values);
}

long P_CopyRates(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CopyRates");
   MqlRates values[]; return CopyRates(s,(ENUM_TIMEFRAMES)k,0,1,values);
}

bool P_OrderCheck(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderCheck");
   MqlTradeRequest q; MqlTradeCheckResult r; ZeroMemory(q); return OrderCheck(q,r);
}

bool P_OrderSend(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderSend");
   MqlTradeRequest q; MqlTradeResult r; ZeroMemory(q); return OrderSend(q,r);
}

bool P_OrderSendAsync(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderSendAsync");
   MqlTradeRequest q; MqlTradeResult r; ZeroMemory(q); return OrderSendAsync(q,r);
}

bool P_OrderCalcMargin(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderCalcMargin");
   double margin; return OrderCalcMargin(ORDER_TYPE_BUY,s,x,x,margin);
}

bool P_OrderCalcProfit(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderCalcProfit");
   double profit; return OrderCalcProfit(ORDER_TYPE_BUY,s,x,x,x,profit);
}

bool P_ObjectCreate(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectCreate");
   return ObjectCreate(k,s,OBJ_LABEL,0,0,0);
}

bool P_TextGetSize(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TextGetSize");
   uint w,h; return TextGetSize(s,w,h);
}

bool P_ResourceCreate(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ResourceCreate");
   uint pixels[]; ArrayResize(pixels,4); pixels[0]=(uint)k; return ResourceCreate(s,pixels,2,2,0,0,2,COLOR_FORMAT_ARGB_NORMALIZE);
}

bool P_TextOut(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TextOut");
   uint pixels[]; ArrayResize(pixels,16); return TextOut(s,(int)k,0,0,pixels,4,4,(uint)k,COLOR_FORMAT_ARGB_NORMALIZE);
}

long P_ArrayResizeDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArrayResizeDouble");
   double a[]; return ArrayResize(a,(int)k);
}

long P_ArrayInitializeDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArrayInitializeDouble");
   double a[]; ArrayResize(a,4); return ArrayInitialize(a,x);
}

long P_ArrayFillUInt(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArrayFillUInt");
   uint a[]; ArrayResize(a,4); ArrayFill(a,0,4,(uint)k); return a[0];
}

long P_ArrayCopyUInt(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArrayCopyUInt");
   uint a[],b[]; ArrayResize(a,4); a[0]=(uint)k; return ArrayCopy(b,a);
}

long P_ArrayFreeDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArrayFreeDouble");
   double a[]; ArrayResize(a,(int)k); ArrayFree(a); return ArraySize(a);
}

bool P_ArraySetAsSeries(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArraySetAsSeries");
   double a[]; return ArraySetAsSeries(a,(bool)k);
}

string P_CharArrayToString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CharArrayToString");
   uchar a[]; ArrayResize(a,2); a[0]=(uchar)k; a[1]=0; return CharArrayToString(a,0,-1,CP_UTF8);
}

long P_StringToCharArray(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringToCharArray");
   uchar a[]; return StringToCharArray(s,a,0,-1,CP_UTF8);
}

long P_WebRequest(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:WebRequest");
   char request[],response[]; string headers; return WebRequest("GET",s,"",(int)k,request,response,headers);
}

long P_PrintFormat(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PrintFormat");
   PrintFormat("%I64d %.3f %s",k,x,s); return 0;
}

long P_Comment(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Comment");
   Comment(s,k,x); return 0;
}

long P_StringConcatenate(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringConcatenate");
   string value; return StringConcatenate(value,s,k,x);
}

long P_iMA(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iMA");
   return iMA(s,(ENUM_TIMEFRAMES)k,(int)x,0,MODE_EMA,PRICE_OPEN);
}

bool P_ObjectSetIntegerModifier(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectSetIntegerModifier");
   return ObjectSetInteger(k,s,OBJPROP_XDISTANCE,0,(long)x);
}

bool P_ObjectSetDoubleModifier(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectSetDoubleModifier");
   return ObjectSetDouble(k,s,OBJPROP_PRICE,0,x);
}

bool P_ObjectSetStringModifier(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectSetStringModifier");
   return ObjectSetString(k,s,OBJPROP_TEXT,0,s);
}

bool P_ObjectGetIntegerRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectGetIntegerRef");
   long v; return ObjectGetInteger(k,s,OBJPROP_XDISTANCE,0,v);
}

bool P_ObjectGetDoubleRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectGetDoubleRef");
   double v; return ObjectGetDouble(k,s,OBJPROP_PRICE,0,v);
}

bool P_ObjectGetStringRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectGetStringRef");
   string v; return ObjectGetString(k,s,OBJPROP_TEXT,0,v);
}

bool P_ChartGetIntegerRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ChartGetIntegerRef");
   long v; return ChartGetInteger(k,CHART_WIDTH_IN_PIXELS,0,v);
}

double P_ChartGetDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ChartGetDouble");
   return ChartGetDouble(k,CHART_PRICE_MIN,0);
}

string P_ChartGetString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ChartGetString");
   return ChartGetString(k,CHART_COMMENT);
}

string P_MQLInfoString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MQLInfoString");
   return MQLInfoString(MQL_PROGRAM_NAME);
}

string P_TerminalInfoString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TerminalInfoString");
   return TerminalInfoString(TERMINAL_NAME);
}

double P_TerminalInfoDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:TerminalInfoDouble");
   return TerminalInfoDouble(TERMINAL_COMMUNITY_BALANCE);
}

long P_UninitializeReason(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:UninitializeReason");
   return UninitializeReason();
}

long P_PeriodSeconds(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PeriodSeconds");
   return PeriodSeconds((ENUM_TIMEFRAMES)k);
}

long P_Sleep(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Sleep");
   Sleep((int)k); return 0;
}

long P_HistoryOrdersTotal(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryOrdersTotal");
   return HistoryOrdersTotal();
}

bool P_HistoryOrderSelect(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryOrderSelect");
   return HistoryOrderSelect((ulong)k);
}

long P_HistoryOrderGetTicket(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryOrderGetTicket");
   return (long)HistoryOrderGetTicket((int)k);
}

long P_HistoryOrderGetInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryOrderGetInteger");
   return HistoryOrderGetInteger((ulong)k,(ENUM_ORDER_PROPERTY_INTEGER)(int)x);
}

double P_HistoryOrderGetDouble(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryOrderGetDouble");
   return HistoryOrderGetDouble((ulong)k,(ENUM_ORDER_PROPERTY_DOUBLE)(int)x);
}

string P_HistoryOrderGetString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistoryOrderGetString");
   return HistoryOrderGetString((ulong)k,(ENUM_ORDER_PROPERTY_STRING)(int)x);
}

bool P_HistorySelectByPosition(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:HistorySelectByPosition");
   return HistorySelectByPosition((ulong)k);
}

bool P_PositionGetIntegerRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionGetIntegerRef");
   long v; return PositionGetInteger((ENUM_POSITION_PROPERTY_INTEGER)k,v);
}

bool P_PositionGetDoubleRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionGetDoubleRef");
   double v; return PositionGetDouble((ENUM_POSITION_PROPERTY_DOUBLE)k,v);
}

bool P_PositionGetStringRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:PositionGetStringRef");
   string v; return PositionGetString((ENUM_POSITION_PROPERTY_STRING)k,v);
}

bool P_OrderGetIntegerRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderGetIntegerRef");
   long v; return OrderGetInteger((ENUM_ORDER_PROPERTY_INTEGER)k,v);
}

bool P_OrderGetDoubleRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderGetDoubleRef");
   double v; return OrderGetDouble((ENUM_ORDER_PROPERTY_DOUBLE)k,v);
}

bool P_OrderGetStringRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:OrderGetStringRef");
   string v; return OrderGetString((ENUM_ORDER_PROPERTY_STRING)k,v);
}

long P_StringCompare(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringCompare");
   return StringCompare(s,"X",true);
}

bool P_StringEqual(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringEqual");
   return s=="X";
}

bool P_StringLess(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringLess");
   return s<"X";
}

string P_StringAdd(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringAdd");
   string v=s; StringAdd(v,s); return v;
}

string P_StringInit(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringInit");
   string v; StringInit(v,(int)k,(ushort)x); return v;
}

string P_StringSetCharacter(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringSetCharacter");
   string v=s; StringSetCharacter(v,(int)k,(ushort)x); return v;
}

string P_ShortToString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ShortToString");
   return ShortToString((ushort)k);
}

string P_ShortArrayToString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ShortArrayToString");
   ushort v[]; ArrayResize(v,2);v[0]=(ushort)k;v[1]=0;return ShortArrayToString(v);
}

double P_MathLog(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathLog");
   return MathLog(x);
}

double P_MathLog10(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathLog10");
   return MathLog10(x);
}

double P_MathSqrt(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathSqrt");
   return MathSqrt(x);
}

double P_MathMod(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathMod");
   return MathMod(x,(double)k);
}

long P_iHighest(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iHighest");
   return iHighest(s,(ENUM_TIMEFRAMES)k,MODE_HIGH,(int)x,1);
}

long P_iLowest(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iLowest");
   return iLowest(s,(ENUM_TIMEFRAMES)k,MODE_LOW,(int)x,1);
}

long P_iBars(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iBars");
   return iBars(s,(ENUM_TIMEFRAMES)k);
}

long P_iBarShift(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:iBarShift");
   return iBarShift(s,(ENUM_TIMEFRAMES)k,(datetime)x,false);
}

long P_SeriesInfoInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SeriesInfoInteger");
   return SeriesInfoInteger(s,(ENUM_TIMEFRAMES)k,SERIES_LASTBAR_DATE);
}

bool P_SeriesInfoIntegerRef(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:SeriesInfoIntegerRef");
   long v;return SeriesInfoInteger(s,(ENUM_TIMEFRAMES)k,SERIES_LASTBAR_DATE,v);
}

long P_CopyTime(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CopyTime");
   datetime v[];return CopyTime(s,(ENUM_TIMEFRAMES)k,0,1,v);
}

long P_CopyHigh(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CopyHigh");
   double v[];return CopyHigh(s,(ENUM_TIMEFRAMES)k,0,1,v);
}

long P_CopyLow(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CopyLow");
   double v[];return CopyLow(s,(ENUM_TIMEFRAMES)k,0,1,v);
}

long P_CopyOpen(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CopyOpen");
   double v[];return CopyOpen(s,(ENUM_TIMEFRAMES)k,0,1,v);
}

long P_CopyClose(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CopyClose");
   double v[];return CopyClose(s,(ENUM_TIMEFRAMES)k,0,1,v);
}

long P_ArrayMaximum(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArrayMaximum");
   double v[];ArrayResize(v,2);v[0]=x;v[1]=(double)k;return ArrayMaximum(v);
}

long P_ArrayMinimum(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArrayMinimum");
   double v[];ArrayResize(v,2);v[0]=x;v[1]=(double)k;return ArrayMinimum(v);
}

bool P_ArraySetAsSeriesUInt(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArraySetAsSeriesUInt");
   uint a[];return ArraySetAsSeries(a,(bool)k);
}

bool P_StringReserve(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringReserve");
   string v=s;return StringReserve(v,(int)k);
}

long P_StringBufferLen(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StringBufferLen");
   return StringBufferLen(s);
}

double P_MathMin(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathMin");
   return MathMin(x,(double)k);
}

double P_MathMax(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:MathMax");
   return MathMax(x,(double)k);
}

long P_ZeroMemoryRequest(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ZeroMemoryRequest");
   MqlTradeRequest v; ZeroMemory(v);v.magic=(ulong)k;return (long)v.magic;
}

long P_StructCopyRequest(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:StructCopyRequest");
   MqlTradeRequest a,b;ZeroMemory(a);a.magic=(ulong)k;a.comment=s;b=a;return(long)b.magic;
}

bool P_ChartSetInteger(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ChartSetInteger");
   return ChartSetInteger(k,CHART_SHOW_GRID,(long)x);
}

long P_ObjectsTotal(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectsTotal");
   return ObjectsTotal(k,-1,-1);
}

string P_ObjectName(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ObjectName");
   return ObjectName(k,(int)x,-1,-1);
}

long P_WebRequestNine(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:WebRequestNine");
   char request[],response[]; string headers; return WebRequest("GET",s,"","",(int)k,request,0,response,headers);
}

string P_CastLongString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CastLongString");
   return (string)k;
}

string P_CastUIntString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CastUIntString");
   return (string)(uint)k;
}

string P_CastDoubleString(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CastDoubleString");
   return (string)x;
}

long P_LocalClass(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:LocalClass");
   CProbeBase object;object.value=(int)k;return (long)CheckPointer(GetPointer(object));
}

long P_DynamicClass(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:DynamicClass");
   CProbeBase *object=new CProbeBase;object.value=(int)k;long result=object.value;delete object;return result;
}

long P_DerivedClass(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:DerivedClass");
   CProbeDerived object;object.value=(int)k;return (long)CheckPointer(GetPointer(object));
}

long P_LargeStaticBuffer(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:LargeStaticBuffer");
   uint a[2048];ArrayInitialize(a,0);a[(int)(k%2048)]=(uint)x;return (long)a[0];
}

double P_ArrayBounds(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:ArrayBounds");
   double a[2];a[0]=x;a[1]=x+1;return a[(int)k];
}

double P_Divide(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:Divide");
   return x/(double)k;
}

long P_NullObject(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:NullObject");
   CProbeBase *object=NULL;return object.value;
}

long P_CopyTickVolume(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CopyTickVolume");
   long v[];return CopyTickVolume(s,(ENUM_TIMEFRAMES)k,0,1,v);
}

long P_CopyRealVolume(const long k,const double x,const string s) export
{
   Print("EX5_API_PROBE:CopyRealVolume");
   long v[];return CopyRealVolume(s,(ENUM_TIMEFRAMES)k,0,1,v);
}

void ProbeDispatch(const int selected) export
{
   if(!MQLInfoInteger(MQL_TESTER) || selected<0) return;
   switch(selected)
   {
      case 0: Print("PROBE_RESULT",P_IdentityLong(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 1: Print("PROBE_RESULT",P_IdentityDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 2: Print("PROBE_RESULT",P_IdentityString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 3: Print("PROBE_RESULT",P_GetLastError(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 4: Print("PROBE_RESULT",P_GetTickCount(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 5: Print("PROBE_RESULT",P_GetTickCount64(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 6: Print("PROBE_RESULT",P_GetMicrosecondCount(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 7: Print("PROBE_RESULT",P_MQLInfoInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 8: Print("PROBE_RESULT",P_TerminalInfoInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 9: Print("PROBE_RESULT",P_IsStopped(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 10: Print("PROBE_RESULT",P_AccountInfoInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 11: Print("PROBE_RESULT",P_AccountInfoDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 12: Print("PROBE_RESULT",P_AccountInfoString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 13: Print("PROBE_RESULT",P_SymbolInfoInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 14: Print("PROBE_RESULT",P_SymbolInfoDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 15: Print("PROBE_RESULT",P_SymbolInfoString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 16: Print("PROBE_RESULT",P_Symbol(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 17: Print("PROBE_RESULT",P_Period(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 18: Print("PROBE_RESULT",P_Digits(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 19: Print("PROBE_RESULT",P_Point(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 20: Print("PROBE_RESULT",P_TimeCurrent(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 21: Print("PROBE_RESULT",P_TimeLocal(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 22: Print("PROBE_RESULT",P_TimeGMT(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 23: Print("PROBE_RESULT",P_TimeGMTOffset(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 24: Print("PROBE_RESULT",P_TimeTradeServer(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 25: Print("PROBE_RESULT",P_TimeToString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 26: Print("PROBE_RESULT",P_StringToTime(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 27: Print("PROBE_RESULT",P_IntegerToString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 28: Print("PROBE_RESULT",P_DoubleToString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 29: Print("PROBE_RESULT",P_StringLen(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 30: Print("PROBE_RESULT",P_StringFind(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 31: Print("PROBE_RESULT",P_StringSubstr(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 32: Print("PROBE_RESULT",P_StringGetCharacter(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 33: Print("PROBE_RESULT",P_StringToInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 34: Print("PROBE_RESULT",P_StringToDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 35: Print("PROBE_RESULT",P_NormalizeDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 36: Print("PROBE_RESULT",P_MathRound(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 37: Print("PROBE_RESULT",P_MathFloor(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 38: Print("PROBE_RESULT",P_MathCeil(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 39: Print("PROBE_RESULT",P_MathAbs(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 40: Print("PROBE_RESULT",P_MathPow(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 41: Print("PROBE_RESULT",P_PositionsTotal(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 42: Print("PROBE_RESULT",P_PositionGetTicket(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 43: Print("PROBE_RESULT",P_PositionGetSymbol(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 44: Print("PROBE_RESULT",P_PositionSelect(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 45: Print("PROBE_RESULT",P_PositionSelectByTicket(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 46: Print("PROBE_RESULT",P_PositionGetInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 47: Print("PROBE_RESULT",P_PositionGetDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 48: Print("PROBE_RESULT",P_PositionGetString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 49: Print("PROBE_RESULT",P_OrdersTotal(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 50: Print("PROBE_RESULT",P_OrderGetTicket(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 51: Print("PROBE_RESULT",P_OrderSelect(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 52: Print("PROBE_RESULT",P_OrderGetInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 53: Print("PROBE_RESULT",P_OrderGetDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 54: Print("PROBE_RESULT",P_OrderGetString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 55: Print("PROBE_RESULT",P_HistorySelect(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 56: Print("PROBE_RESULT",P_HistoryDealSelect(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 57: Print("PROBE_RESULT",P_HistoryDealsTotal(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 58: Print("PROBE_RESULT",P_HistoryDealGetTicket(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 59: Print("PROBE_RESULT",P_HistoryDealGetInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 60: Print("PROBE_RESULT",P_HistoryDealGetDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 61: Print("PROBE_RESULT",P_HistoryDealGetString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 62: Print("PROBE_RESULT",P_iATR(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 63: Print("PROBE_RESULT",P_iOpen(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 64: Print("PROBE_RESULT",P_iHigh(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 65: Print("PROBE_RESULT",P_iLow(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 66: Print("PROBE_RESULT",P_iClose(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 67: Print("PROBE_RESULT",P_iTime(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 68: Print("PROBE_RESULT",P_Bars(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 69: Print("PROBE_RESULT",P_IndicatorRelease(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 70: Print("PROBE_RESULT",P_ChartID(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 71: Print("PROBE_RESULT",P_ChartGetInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 72: Print("PROBE_RESULT",P_ObjectFind(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 73: Print("PROBE_RESULT",P_ObjectDelete(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 74: Print("PROBE_RESULT",P_ObjectsDeleteAllPrefix(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 75: Print("PROBE_RESULT",P_ObjectGetInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 76: Print("PROBE_RESULT",P_ObjectGetDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 77: Print("PROBE_RESULT",P_ObjectGetString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 78: Print("PROBE_RESULT",P_ObjectSetInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 79: Print("PROBE_RESULT",P_ObjectSetDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 80: Print("PROBE_RESULT",P_ObjectSetString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 81: Print("PROBE_RESULT",P_ResourceFree(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 82: Print("PROBE_RESULT",P_TextSetFont(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 83: Print("PROBE_RESULT",P_ColorToARGB(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 84: Print("PROBE_RESULT",P_ResetLastError(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 85: Print("PROBE_RESULT",P_ChartRedraw(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 86: Print("PROBE_RESULT",P_EventSetTimer(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 87: Print("PROBE_RESULT",P_EventKillTimer(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 88: Print("PROBE_RESULT",P_SymbolInfoIntegerRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 89: Print("PROBE_RESULT",P_SymbolInfoDoubleRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 90: Print("PROBE_RESULT",P_SymbolInfoStringRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 91: Print("PROBE_RESULT",P_SymbolInfoTick(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 92: Print("PROBE_RESULT",P_SymbolInfoSessionTrade(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 93: Print("PROBE_RESULT",P_TimeToStruct(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 94: Print("PROBE_RESULT",P_StructToTime(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 95: Print("PROBE_RESULT",P_StringToUpper(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 96: Print("PROBE_RESULT",P_StringToLower(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 97: Print("PROBE_RESULT",P_StringTrimLeft(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 98: Print("PROBE_RESULT",P_StringTrimRight(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 99: Print("PROBE_RESULT",P_StringReplace(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 100: Print("PROBE_RESULT",P_StringSplit(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 101: Print("PROBE_RESULT",P_StringFormat(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 102: Print("PROBE_RESULT",P_CopyBuffer(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 103: Print("PROBE_RESULT",P_CopyRates(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 104: Print("PROBE_RESULT",P_OrderCheck(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 105: Print("PROBE_RESULT",P_OrderSend(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 106: Print("PROBE_RESULT",P_OrderSendAsync(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 107: Print("PROBE_RESULT",P_OrderCalcMargin(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 108: Print("PROBE_RESULT",P_OrderCalcProfit(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 109: Print("PROBE_RESULT",P_ObjectCreate(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 110: Print("PROBE_RESULT",P_TextGetSize(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 111: Print("PROBE_RESULT",P_ResourceCreate(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 112: Print("PROBE_RESULT",P_TextOut(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 113: Print("PROBE_RESULT",P_ArrayResizeDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 114: Print("PROBE_RESULT",P_ArrayInitializeDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 115: Print("PROBE_RESULT",P_ArrayFillUInt(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 116: Print("PROBE_RESULT",P_ArrayCopyUInt(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 117: Print("PROBE_RESULT",P_ArrayFreeDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 118: Print("PROBE_RESULT",P_ArraySetAsSeries(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 119: Print("PROBE_RESULT",P_CharArrayToString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 120: Print("PROBE_RESULT",P_StringToCharArray(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 121: Print("PROBE_RESULT",P_WebRequest(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 122: Print("PROBE_RESULT",P_PrintFormat(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 123: Print("PROBE_RESULT",P_Comment(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 124: Print("PROBE_RESULT",P_StringConcatenate(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 125: Print("PROBE_RESULT",P_iMA(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 126: Print("PROBE_RESULT",P_ObjectSetIntegerModifier(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 127: Print("PROBE_RESULT",P_ObjectSetDoubleModifier(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 128: Print("PROBE_RESULT",P_ObjectSetStringModifier(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 129: Print("PROBE_RESULT",P_ObjectGetIntegerRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 130: Print("PROBE_RESULT",P_ObjectGetDoubleRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 131: Print("PROBE_RESULT",P_ObjectGetStringRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 132: Print("PROBE_RESULT",P_ChartGetIntegerRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 133: Print("PROBE_RESULT",P_ChartGetDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 134: Print("PROBE_RESULT",P_ChartGetString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 135: Print("PROBE_RESULT",P_MQLInfoString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 136: Print("PROBE_RESULT",P_TerminalInfoString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 137: Print("PROBE_RESULT",P_TerminalInfoDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 138: Print("PROBE_RESULT",P_UninitializeReason(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 139: Print("PROBE_RESULT",P_PeriodSeconds(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 140: Print("PROBE_RESULT",P_Sleep(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 141: Print("PROBE_RESULT",P_HistoryOrdersTotal(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 142: Print("PROBE_RESULT",P_HistoryOrderSelect(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 143: Print("PROBE_RESULT",P_HistoryOrderGetTicket(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 144: Print("PROBE_RESULT",P_HistoryOrderGetInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 145: Print("PROBE_RESULT",P_HistoryOrderGetDouble(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 146: Print("PROBE_RESULT",P_HistoryOrderGetString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 147: Print("PROBE_RESULT",P_HistorySelectByPosition(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 148: Print("PROBE_RESULT",P_PositionGetIntegerRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 149: Print("PROBE_RESULT",P_PositionGetDoubleRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 150: Print("PROBE_RESULT",P_PositionGetStringRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 151: Print("PROBE_RESULT",P_OrderGetIntegerRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 152: Print("PROBE_RESULT",P_OrderGetDoubleRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 153: Print("PROBE_RESULT",P_OrderGetStringRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 154: Print("PROBE_RESULT",P_StringCompare(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 155: Print("PROBE_RESULT",P_StringEqual(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 156: Print("PROBE_RESULT",P_StringLess(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 157: Print("PROBE_RESULT",P_StringAdd(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 158: Print("PROBE_RESULT",P_StringInit(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 159: Print("PROBE_RESULT",P_StringSetCharacter(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 160: Print("PROBE_RESULT",P_ShortToString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 161: Print("PROBE_RESULT",P_ShortArrayToString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 162: Print("PROBE_RESULT",P_MathLog(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 163: Print("PROBE_RESULT",P_MathLog10(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 164: Print("PROBE_RESULT",P_MathSqrt(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 165: Print("PROBE_RESULT",P_MathMod(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 166: Print("PROBE_RESULT",P_iHighest(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 167: Print("PROBE_RESULT",P_iLowest(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 168: Print("PROBE_RESULT",P_iBars(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 169: Print("PROBE_RESULT",P_iBarShift(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 170: Print("PROBE_RESULT",P_SeriesInfoInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 171: Print("PROBE_RESULT",P_SeriesInfoIntegerRef(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 172: Print("PROBE_RESULT",P_CopyTime(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 173: Print("PROBE_RESULT",P_CopyHigh(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 174: Print("PROBE_RESULT",P_CopyLow(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 175: Print("PROBE_RESULT",P_CopyOpen(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 176: Print("PROBE_RESULT",P_CopyClose(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 177: Print("PROBE_RESULT",P_ArrayMaximum(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 178: Print("PROBE_RESULT",P_ArrayMinimum(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 179: Print("PROBE_RESULT",P_ArraySetAsSeriesUInt(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 180: Print("PROBE_RESULT",P_StringReserve(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 181: Print("PROBE_RESULT",P_StringBufferLen(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 182: Print("PROBE_RESULT",P_MathMin(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 183: Print("PROBE_RESULT",P_MathMax(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 184: Print("PROBE_RESULT",P_ZeroMemoryRequest(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 185: Print("PROBE_RESULT",P_StructCopyRequest(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 186: Print("PROBE_RESULT",P_ChartSetInteger(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 187: Print("PROBE_RESULT",P_ObjectsTotal(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 188: Print("PROBE_RESULT",P_ObjectName(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 189: Print("PROBE_RESULT",P_WebRequestNine(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 190: Print("PROBE_RESULT",P_CastLongString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 191: Print("PROBE_RESULT",P_CastUIntString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 192: Print("PROBE_RESULT",P_CastDoubleString(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 193: Print("PROBE_RESULT",P_LocalClass(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 194: Print("PROBE_RESULT",P_DynamicClass(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 195: Print("PROBE_RESULT",P_DerivedClass(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 196: Print("PROBE_RESULT",P_LargeStaticBuffer(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 197: Print("PROBE_RESULT",P_ArrayBounds(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 198: Print("PROBE_RESULT",P_Divide(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 199: Print("PROBE_RESULT",P_NullObject(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 200: Print("PROBE_RESULT",P_CopyTickVolume(1,1.25,"XAUUSD_NOCOST_V2")); break;
      case 201: Print("PROBE_RESULT",P_CopyRealVolume(1,1.25,"XAUUSD_NOCOST_V2")); break;
   }
}
