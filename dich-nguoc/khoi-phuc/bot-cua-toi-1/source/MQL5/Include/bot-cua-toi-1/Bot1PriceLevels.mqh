// Reconstructed components only, not a complete EA.
// Bot 1 native RVAs 0x32890 (upper level) and 0x32ac0 (lower level).
// Call-site settings and strategy selection are not reconstructed here.
#ifndef BOT1_PRICE_LEVELS_MQH
#define BOT1_PRICE_LEVELS_MQH

double Bot1RoundPrice(const double price,const uint digits)
{
   long whole=(long)price;
   if(whole==LONG_MIN) return price;
   double powers[12]={1.0,10.0,100.0,1000.0,10000.0,100000.0,
                     1000000.0,10000000.0,100000000.0,1000000000.0,10000000000.0,100000000000.0};
   uint precision=digits<11 ? digits : 11;
   double scale=powers[precision];
   return (double)(long)((price-(double)whole)*scale+(0.0<price ? 0.5000001 : -0.5000001))/scale+(double)whole;
}

double Bot1UpperLevel(const string &symbol,const ENUM_TIMEFRAMES timeframe,
                     const int older_width,const int recent_width,const int &last_shift,
                     const double &ask,const double &gap)
{
   int shift=recent_width+1;
   do
   {
      bool rejected=false;
      for(int i=shift;i>=shift-recent_width;i--)
      {
         double neighbor=iHigh(symbol,timeframe,i);
         double candidate=iHigh(symbol,timeframe,shift);
         if(candidate<neighbor) { rejected=true; break; }
      }
      if(!rejected)
         for(int i=shift;i<=shift+older_width;i++)
         {
            double neighbor=iHigh(symbol,timeframe,i);
            double candidate=iHigh(symbol,timeframe,shift);
            if(candidate<neighbor) { rejected=true; break; }
         }
      if(!rejected)
      {
         double candidate=iHigh(symbol,timeframe,shift);
         if(ask+gap<candidate)
         {
            uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
            double value=iHigh(symbol,timeframe,shift);
            return Bot1RoundPrice(value,digits);
         }
      }
      shift++;
   } while(shift<=last_shift);
   return 9999.0;
}

double Bot1LowerLevel(const string &symbol,const ENUM_TIMEFRAMES timeframe,
                     const int older_width,const int recent_width,const int &last_shift,
                     const double &bid,const double &gap)
{
   int shift=recent_width+1;
   do
   {
      bool rejected=false;
      for(int i=shift;i>=shift-recent_width;i--)
      {
         double neighbor=iLow(symbol,timeframe,i);
         double candidate=iLow(symbol,timeframe,shift);
         if(neighbor<candidate) { rejected=true; break; }
      }
      if(!rejected)
         for(int i=shift;i<=shift+older_width;i++)
         {
            double neighbor=iLow(symbol,timeframe,i);
            double candidate=iLow(symbol,timeframe,shift);
            if(neighbor<candidate) { rejected=true; break; }
         }
      if(!rejected)
      {
         double candidate=iLow(symbol,timeframe,shift);
         if(candidate<bid-gap)
         {
            uint digits=(uint)SymbolInfoInteger(symbol,SYMBOL_DIGITS);
            double value=iLow(symbol,timeframe,shift);
            return Bot1RoundPrice(value,digits);
         }
      }
      shift++;
   } while(shift<=last_shift);
   return 0.0;
}
#endif
