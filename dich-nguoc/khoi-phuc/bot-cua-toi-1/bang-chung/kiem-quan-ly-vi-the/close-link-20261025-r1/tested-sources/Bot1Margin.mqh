// Native margin guard and direct margin check.
// Follows native branch order; reads only, never places an order.
#ifndef BOT1_MARGIN_MQH
#define BOT1_MARGIN_MQH
bool Bot1MarginAvailable(const string symbol,const double volume,const ENUM_ORDER_TYPE type)
{
   MqlTick tick;
   SymbolInfoTick(symbol,tick);
   double price=type==ORDER_TYPE_SELL ? tick.bid : tick.ask;
   double free=AccountInfoDouble(ACCOUNT_MARGIN_FREE);
   double required=0.0;
   if(!OrderCalcMargin(type,symbol,volume,price,required))
   { Print("Margin calculation failed");return false; }
   if(required>free)
   { Print("Insufficient margin");return false; }
   return true;
}
bool Bot1MarginGuard(const string symbol,const ENUM_ORDER_TYPE type,const double volume)
{
   if(volume<=0.0) return false;
   if(AccountInfoString(ACCOUNT_CURRENCY)!="BTC" && AccountInfoString(ACCOUNT_CURRENCY)!="btc" &&
      AccountInfoString(ACCOUNT_CURRENCY)!="ETH" && AccountInfoString(ACCOUNT_CURRENCY)!="eth")
   {
      double equity=AccountInfoDouble(ACCOUNT_EQUITY);
      double units=volume/0.01;
      if(units==0.0) return false;
      if(equity/units<70.0 || AccountInfoDouble(ACCOUNT_MARGIN_FREE)/units<70.0)
      { Print("Insufficient funds per volume unit");return false; }
   }
   return Bot1MarginAvailable(symbol,volume,type);
}
#endif
