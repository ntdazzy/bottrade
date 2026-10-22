#property strict
#property version "1.00"
void Dump_ENUM_MQL_INFO_INTEGER()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_MQL_INFO_INTEGER)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_MQL_INFO_INTEGER|",value,"|",label);
   }
}
void Dump_ENUM_ACCOUNT_INFO_INTEGER()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ACCOUNT_INFO_INTEGER)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ACCOUNT_INFO_INTEGER|",value,"|",label);
   }
}
void Dump_ENUM_ACCOUNT_INFO_DOUBLE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ACCOUNT_INFO_DOUBLE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ACCOUNT_INFO_DOUBLE|",value,"|",label);
   }
}
void Dump_ENUM_ACCOUNT_INFO_STRING()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ACCOUNT_INFO_STRING)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ACCOUNT_INFO_STRING|",value,"|",label);
   }
}
void Dump_ENUM_SYMBOL_INFO_INTEGER()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_SYMBOL_INFO_INTEGER)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_SYMBOL_INFO_INTEGER|",value,"|",label);
   }
}
void Dump_ENUM_SYMBOL_INFO_DOUBLE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_SYMBOL_INFO_DOUBLE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_SYMBOL_INFO_DOUBLE|",value,"|",label);
   }
}
void Dump_ENUM_SYMBOL_INFO_STRING()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_SYMBOL_INFO_STRING)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_SYMBOL_INFO_STRING|",value,"|",label);
   }
}
void Dump_ENUM_POSITION_PROPERTY_INTEGER()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_POSITION_PROPERTY_INTEGER)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_POSITION_PROPERTY_INTEGER|",value,"|",label);
   }
}
void Dump_ENUM_POSITION_PROPERTY_DOUBLE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_POSITION_PROPERTY_DOUBLE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_POSITION_PROPERTY_DOUBLE|",value,"|",label);
   }
}
void Dump_ENUM_POSITION_PROPERTY_STRING()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_POSITION_PROPERTY_STRING)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_POSITION_PROPERTY_STRING|",value,"|",label);
   }
}
void Dump_ENUM_ORDER_PROPERTY_INTEGER()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ORDER_PROPERTY_INTEGER)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ORDER_PROPERTY_INTEGER|",value,"|",label);
   }
}
void Dump_ENUM_ORDER_PROPERTY_DOUBLE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ORDER_PROPERTY_DOUBLE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ORDER_PROPERTY_DOUBLE|",value,"|",label);
   }
}
void Dump_ENUM_ORDER_PROPERTY_STRING()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ORDER_PROPERTY_STRING)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ORDER_PROPERTY_STRING|",value,"|",label);
   }
}
void Dump_ENUM_DEAL_PROPERTY_INTEGER()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_DEAL_PROPERTY_INTEGER)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_DEAL_PROPERTY_INTEGER|",value,"|",label);
   }
}
void Dump_ENUM_DEAL_PROPERTY_DOUBLE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_DEAL_PROPERTY_DOUBLE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_DEAL_PROPERTY_DOUBLE|",value,"|",label);
   }
}
void Dump_ENUM_DEAL_PROPERTY_STRING()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_DEAL_PROPERTY_STRING)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_DEAL_PROPERTY_STRING|",value,"|",label);
   }
}
void Dump_ENUM_OBJECT_PROPERTY_INTEGER()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_OBJECT_PROPERTY_INTEGER)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_OBJECT_PROPERTY_INTEGER|",value,"|",label);
   }
}
void Dump_ENUM_OBJECT_PROPERTY_DOUBLE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_OBJECT_PROPERTY_DOUBLE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_OBJECT_PROPERTY_DOUBLE|",value,"|",label);
   }
}
void Dump_ENUM_OBJECT_PROPERTY_STRING()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_OBJECT_PROPERTY_STRING)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_OBJECT_PROPERTY_STRING|",value,"|",label);
   }
}
void Dump_ENUM_CHART_PROPERTY_INTEGER()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_CHART_PROPERTY_INTEGER)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_CHART_PROPERTY_INTEGER|",value,"|",label);
   }
}
void Dump_ENUM_CHART_PROPERTY_DOUBLE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_CHART_PROPERTY_DOUBLE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_CHART_PROPERTY_DOUBLE|",value,"|",label);
   }
}
void Dump_ENUM_CHART_PROPERTY_STRING()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_CHART_PROPERTY_STRING)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_CHART_PROPERTY_STRING|",value,"|",label);
   }
}
void Dump_ENUM_TIMEFRAMES()
{
   for(int value=0;value<65536;value++)
   {
      string label=EnumToString((ENUM_TIMEFRAMES)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_TIMEFRAMES|",value,"|",label);
   }
}
void Dump_ENUM_MA_METHOD()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_MA_METHOD)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_MA_METHOD|",value,"|",label);
   }
}
void Dump_ENUM_APPLIED_PRICE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_APPLIED_PRICE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_APPLIED_PRICE|",value,"|",label);
   }
}
void Dump_ENUM_DAY_OF_WEEK()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_DAY_OF_WEEK)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_DAY_OF_WEEK|",value,"|",label);
   }
}
void Dump_ENUM_TRADE_TRANSACTION_TYPE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_TRADE_TRANSACTION_TYPE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_TRADE_TRANSACTION_TYPE|",value,"|",label);
   }
}
void Dump_ENUM_DEAL_ENTRY()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_DEAL_ENTRY)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_DEAL_ENTRY|",value,"|",label);
   }
}
void Dump_ENUM_DEAL_TYPE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_DEAL_TYPE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_DEAL_TYPE|",value,"|",label);
   }
}
void Dump_ENUM_ORDER_TYPE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ORDER_TYPE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ORDER_TYPE|",value,"|",label);
   }
}
void Dump_ENUM_POSITION_TYPE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_POSITION_TYPE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_POSITION_TYPE|",value,"|",label);
   }
}
void Dump_ENUM_TRADE_REQUEST_ACTIONS()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_TRADE_REQUEST_ACTIONS)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_TRADE_REQUEST_ACTIONS|",value,"|",label);
   }
}
void Dump_ENUM_ORDER_STATE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ORDER_STATE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ORDER_STATE|",value,"|",label);
   }
}
void Dump_ENUM_ORDER_TYPE_FILLING()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ORDER_TYPE_FILLING)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ORDER_TYPE_FILLING|",value,"|",label);
   }
}
void Dump_ENUM_ORDER_TYPE_TIME()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ORDER_TYPE_TIME)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ORDER_TYPE_TIME|",value,"|",label);
   }
}
void Dump_ENUM_ACCOUNT_MARGIN_MODE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ACCOUNT_MARGIN_MODE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ACCOUNT_MARGIN_MODE|",value,"|",label);
   }
}
void Dump_ENUM_ACCOUNT_TRADE_MODE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_ACCOUNT_TRADE_MODE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_ACCOUNT_TRADE_MODE|",value,"|",label);
   }
}
void Dump_ENUM_SYMBOL_TRADE_MODE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_SYMBOL_TRADE_MODE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_SYMBOL_TRADE_MODE|",value,"|",label);
   }
}
void Dump_ENUM_SYMBOL_CALC_MODE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_SYMBOL_CALC_MODE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_SYMBOL_CALC_MODE|",value,"|",label);
   }
}
void Dump_ENUM_PROGRAM_TYPE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_PROGRAM_TYPE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_PROGRAM_TYPE|",value,"|",label);
   }
}
void Dump_ENUM_OBJECT()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_OBJECT)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_OBJECT|",value,"|",label);
   }
}
void Dump_ENUM_COLOR_FORMAT()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_COLOR_FORMAT)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_COLOR_FORMAT|",value,"|",label);
   }
}
void Dump_ENUM_SERIESMODE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_SERIESMODE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_SERIESMODE|",value,"|",label);
   }
}
void Dump_ENUM_SERIES_INFO_INTEGER()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_SERIES_INFO_INTEGER)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_SERIES_INFO_INTEGER|",value,"|",label);
   }
}
void Dump_ENUM_POINTER_TYPE()
{
   for(int value=0;value<1024;value++)
   {
      string label=EnumToString((ENUM_POINTER_TYPE)value);
      if(label!="" && StringFind(label,"::")<0) Print("ENUM_MAP|ENUM_POINTER_TYPE|",value,"|",label);
   }
}
int OnInit()
{
   if(!MQLInfoInteger(MQL_TESTER)) return INIT_FAILED;
   Dump_ENUM_MQL_INFO_INTEGER();
   Dump_ENUM_ACCOUNT_INFO_INTEGER();
   Dump_ENUM_ACCOUNT_INFO_DOUBLE();
   Dump_ENUM_ACCOUNT_INFO_STRING();
   Dump_ENUM_SYMBOL_INFO_INTEGER();
   Dump_ENUM_SYMBOL_INFO_DOUBLE();
   Dump_ENUM_SYMBOL_INFO_STRING();
   Dump_ENUM_POSITION_PROPERTY_INTEGER();
   Dump_ENUM_POSITION_PROPERTY_DOUBLE();
   Dump_ENUM_POSITION_PROPERTY_STRING();
   Dump_ENUM_ORDER_PROPERTY_INTEGER();
   Dump_ENUM_ORDER_PROPERTY_DOUBLE();
   Dump_ENUM_ORDER_PROPERTY_STRING();
   Dump_ENUM_DEAL_PROPERTY_INTEGER();
   Dump_ENUM_DEAL_PROPERTY_DOUBLE();
   Dump_ENUM_DEAL_PROPERTY_STRING();
   Dump_ENUM_OBJECT_PROPERTY_INTEGER();
   Dump_ENUM_OBJECT_PROPERTY_DOUBLE();
   Dump_ENUM_OBJECT_PROPERTY_STRING();
   Dump_ENUM_CHART_PROPERTY_INTEGER();
   Dump_ENUM_CHART_PROPERTY_DOUBLE();
   Dump_ENUM_CHART_PROPERTY_STRING();
   Dump_ENUM_TIMEFRAMES();
   Dump_ENUM_MA_METHOD();
   Dump_ENUM_APPLIED_PRICE();
   Dump_ENUM_DAY_OF_WEEK();
   Dump_ENUM_TRADE_TRANSACTION_TYPE();
   Dump_ENUM_DEAL_ENTRY();
   Dump_ENUM_DEAL_TYPE();
   Dump_ENUM_ORDER_TYPE();
   Dump_ENUM_POSITION_TYPE();
   Dump_ENUM_TRADE_REQUEST_ACTIONS();
   Dump_ENUM_ORDER_STATE();
   Dump_ENUM_ORDER_TYPE_FILLING();
   Dump_ENUM_ORDER_TYPE_TIME();
   Dump_ENUM_ACCOUNT_MARGIN_MODE();
   Dump_ENUM_ACCOUNT_TRADE_MODE();
   Dump_ENUM_SYMBOL_TRADE_MODE();
   Dump_ENUM_SYMBOL_CALC_MODE();
   Dump_ENUM_PROGRAM_TYPE();
   Dump_ENUM_OBJECT();
   Dump_ENUM_COLOR_FORMAT();
   Dump_ENUM_SERIESMODE();
   Dump_ENUM_SERIES_INFO_INTEGER();
   Dump_ENUM_POINTER_TYPE();
   Print("CONST_MAP|TRADE_RETCODE_CANCEL|",TRADE_RETCODE_CANCEL);
   Print("CONST_MAP|TRADE_RETCODE_CLIENT_DISABLES_AT|",TRADE_RETCODE_CLIENT_DISABLES_AT);
   Print("CONST_MAP|TRADE_RETCODE_CLOSE_ORDER_EXIST|",TRADE_RETCODE_CLOSE_ORDER_EXIST);
   Print("CONST_MAP|TRADE_RETCODE_CONNECTION|",TRADE_RETCODE_CONNECTION);
   Print("CONST_MAP|TRADE_RETCODE_DONE|",TRADE_RETCODE_DONE);
   Print("CONST_MAP|TRADE_RETCODE_DONE_PARTIAL|",TRADE_RETCODE_DONE_PARTIAL);
   Print("CONST_MAP|TRADE_RETCODE_ERROR|",TRADE_RETCODE_ERROR);
   Print("CONST_MAP|TRADE_RETCODE_FROZEN|",TRADE_RETCODE_FROZEN);
   Print("CONST_MAP|TRADE_RETCODE_INVALID|",TRADE_RETCODE_INVALID);
   Print("CONST_MAP|TRADE_RETCODE_INVALID_EXPIRATION|",TRADE_RETCODE_INVALID_EXPIRATION);
   Print("CONST_MAP|TRADE_RETCODE_INVALID_FILL|",TRADE_RETCODE_INVALID_FILL);
   Print("CONST_MAP|TRADE_RETCODE_INVALID_ORDER|",TRADE_RETCODE_INVALID_ORDER);
   Print("CONST_MAP|TRADE_RETCODE_INVALID_PRICE|",TRADE_RETCODE_INVALID_PRICE);
   Print("CONST_MAP|TRADE_RETCODE_INVALID_STOPS|",TRADE_RETCODE_INVALID_STOPS);
   Print("CONST_MAP|TRADE_RETCODE_INVALID_VOLUME|",TRADE_RETCODE_INVALID_VOLUME);
   Print("CONST_MAP|TRADE_RETCODE_LIMIT_ORDERS|",TRADE_RETCODE_LIMIT_ORDERS);
   Print("CONST_MAP|TRADE_RETCODE_LIMIT_POSITIONS|",TRADE_RETCODE_LIMIT_POSITIONS);
   Print("CONST_MAP|TRADE_RETCODE_LIMIT_VOLUME|",TRADE_RETCODE_LIMIT_VOLUME);
   Print("CONST_MAP|TRADE_RETCODE_LOCKED|",TRADE_RETCODE_LOCKED);
   Print("CONST_MAP|TRADE_RETCODE_MARKET_CLOSED|",TRADE_RETCODE_MARKET_CLOSED);
   Print("CONST_MAP|TRADE_RETCODE_NO_CHANGES|",TRADE_RETCODE_NO_CHANGES);
   Print("CONST_MAP|TRADE_RETCODE_NO_MONEY|",TRADE_RETCODE_NO_MONEY);
   Print("CONST_MAP|TRADE_RETCODE_ONLY_REAL|",TRADE_RETCODE_ONLY_REAL);
   Print("CONST_MAP|TRADE_RETCODE_ORDER_CHANGED|",TRADE_RETCODE_ORDER_CHANGED);
   Print("CONST_MAP|TRADE_RETCODE_PLACED|",TRADE_RETCODE_PLACED);
   Print("CONST_MAP|TRADE_RETCODE_POSITION_CLOSED|",TRADE_RETCODE_POSITION_CLOSED);
   Print("CONST_MAP|TRADE_RETCODE_PRICE_CHANGED|",TRADE_RETCODE_PRICE_CHANGED);
   Print("CONST_MAP|TRADE_RETCODE_PRICE_OFF|",TRADE_RETCODE_PRICE_OFF);
   Print("CONST_MAP|TRADE_RETCODE_REJECT|",TRADE_RETCODE_REJECT);
   Print("CONST_MAP|TRADE_RETCODE_REQUOTE|",TRADE_RETCODE_REQUOTE);
   Print("CONST_MAP|TRADE_RETCODE_SERVER_DISABLES_AT|",TRADE_RETCODE_SERVER_DISABLES_AT);
   Print("CONST_MAP|TRADE_RETCODE_TIMEOUT|",TRADE_RETCODE_TIMEOUT);
   Print("CONST_MAP|TRADE_RETCODE_TOO_MANY_REQUESTS|",TRADE_RETCODE_TOO_MANY_REQUESTS);
   Print("CONST_MAP|TRADE_RETCODE_TRADE_DISABLED|",TRADE_RETCODE_TRADE_DISABLED);
   Print("ENUM_MAP_DONE");
   return INIT_SUCCEEDED;
}
void OnTick() {}
