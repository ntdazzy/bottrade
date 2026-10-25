// Native 0x2e8f0. Preserve mutations of request, result and preferred policy.
#ifndef BOT3_FILLING_MQH
#define BOT3_FILLING_MQH
bool Bot3ExpirationAllowed(const string symbol,const ENUM_ORDER_TYPE_TIME type_time)
{
   string name=(symbol==NULL) ? _Symbol : symbol;
   long value=0;
   uint flags=0;
   if(SymbolInfoInteger(name,SYMBOL_EXPIRATION_MODE,value)) flags=(uint)value;
   switch(type_time)
   {
      case ORDER_TIME_GTC: return (flags&1)!=0;
      case ORDER_TIME_DAY: return (flags&2)!=0;
      case ORDER_TIME_SPECIFIED: return (flags&4)!=0;
      case ORDER_TIME_SPECIFIED_DAY: return (flags&8)!=0;
      default: Print("CTrade::ExpirationCheck: Unknown expiration type");
   }
   return false;
}
bool Bot3CheckFilling(const string symbol,MqlTradeRequest &request,MqlTradeResult &result,
                     ENUM_ORDER_TYPE_FILLING &preferred)
{
   uint execution=(uint)SymbolInfoInteger(symbol,SYMBOL_TRADE_EXEMODE);
   if(execution<2) return true;
   ulong flags=(ulong)SymbolInfoInteger(symbol,SYMBOL_FILLING_MODE);
   if(execution==2)
   {
      if(request.action==TRADE_ACTION_PENDING) return true;
      if((flags&1)!=0)
      {
         preferred=ORDER_FILLING_FOK;
         request.type_filling=preferred;
         return true;
      }
      if((flags&2)!=0)
      {
         preferred=ORDER_FILLING_IOC;
         request.type_filling=preferred;
         return true;
      }
      result.retcode=10030;
      return false;
   }
   if(preferred==ORDER_FILLING_RETURN)
   {
      request.type_filling=ORDER_FILLING_RETURN;
      return true;
   }
   if(preferred==ORDER_FILLING_FOK || preferred==ORDER_FILLING_IOC)
   {
      if(request.action==TRADE_ACTION_PENDING)
      {
         if(!Bot3ExpirationAllowed(symbol,request.type_time)) request.type_time=ORDER_TIME_DAY;
         uint kind=(uint)request.type;
         if(kind-2<3 || kind==5)
         {
            request.type_filling=ORDER_FILLING_RETURN;
            return true;
         }
      }
      ulong flag=preferred==ORDER_FILLING_FOK ? 1 : 2;
      if((flags&flag)!=0)
      {
         request.type_filling=preferred;
         return true;
      }
      result.retcode=10030;
      return false;
   }
   result.retcode=10011;
   return false;
}
#endif
