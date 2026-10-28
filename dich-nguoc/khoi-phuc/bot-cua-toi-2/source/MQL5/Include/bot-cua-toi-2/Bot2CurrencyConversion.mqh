// Native account -> USD 0x371f0; USD -> account 0x45400. Read currency afresh for each comparison.
#ifndef BOT2_CURRENCY_CONVERSION_MQH
#define BOT2_CURRENCY_CONVERSION_MQH

int Bot2CurrencyPair(const double amount,const string pair,const bool multiply,double &result)
{
   if(!(iClose(pair,PERIOD_D1,1)>0.0)) return 0;
   double close=iClose(pair,PERIOD_D1,1);
   if(multiply) result=close*amount;
   else
   {
      if(close==0.0) return -1;
      result=amount/close;
   }
   return 1;
}

double Bot2CurrencyFromUsd(const double amount,const string &suffix)
{
   // The USD check has no conversion, but its account reads still occur.
   if(AccountInfoString(ACCOUNT_CURRENCY)!="USD") AccountInfoString(ACCOUNT_CURRENCY);
   // Native 0x46383 and 0x46685 both test CHF; the second is not CZK.
   const string codes[]={"EUR","GBP","AUD","JPY","YEN","CHF","CHF","HKD","RUB","SGD",
                         "BTC","ETH","BCH","BCC","XRP","LTC","XMR","DSH","EOS","TRX","ADA","BSV","XLM","GLD","ZEC","XEM"};
   const string lower[]={"eur","gbp","aud","jpy","yen","chf","chf","hkd","rub","sgd",
                         "btc","eth","bch","bcc","xrp","ltc","xmr","dsh","eos","trx","ada","bsv","xlm","gld","zec","xem"};
   const string pairs[]={"EURUSD","GBPUSD","AUDUSD","USDJPY","USDJPY","USDCHF","USDCHF","USDHKD","USDRUB","USDSGD",
                         "BTCUSD","ETHUSD","BCHUSD","BCCUSD","XRPUSD","LTCUSD","XMRUSD","DSHUSD","EOSUSD","TRXUSD","ADAUSD","BSVUSD","XLMUSD","GLDUSD","ZECUSD","XEMUSD"};
   double value=amount;
   for(int i=0;i<ArraySize(codes);i++)
   {
      // Independent checks, with a fresh account read for each comparison.
      if(AccountInfoString(ACCOUNT_CURRENCY)==codes[i] || AccountInfoString(ACCOUNT_CURRENCY)==lower[i])
      {
         if(Bot2CurrencyPair(amount,pairs[i]+suffix,i>=3 && i<=9,value)<0)
         {
            // The original stops before its caller can store this conversion.
            double zero=0.0;
            return amount/zero;
         }
         // JPY and YEN are alternatives in one native condition.
         if(i==3) i++;
      }
   }
   return value;
}

double Bot2CurrencyToUsd(const double amount,const string &suffix)
{
   if(AccountInfoString(ACCOUNT_CURRENCY)!="USD") AccountInfoString(ACCOUNT_CURRENCY);
   const string upper[]={"EUR","GBP","AUD","JPY","YEN","CHF","CZK","HKD","RUB","CNH","CNY","SGD",
                         "BTC","ETH","BCH","BCC","XRP","LTC","XMR","DSH","EOS","TRX","ADA","BSV","XLM","GLD","ZEC","XEM"};
   const string lower[]={"eur","gbp","aud","jpy","yen","chf","czk","hkd","rub","cnh","cny","sgd",
                         "btc","eth","bch","bcc","xrp","ltc","xmr","dsh","eos","trx","ada","bsv","xlm","gld","zec","xem"};
   const string pairs[]={"EURUSD","GBPUSD","AUDUSD","USDJPY","USDJPY","USDCHF","USDCZK","USDHKD","USDRUB","USDCNH","USDCNH","USDSGD",
                         "BTCUSD","ETHUSD","BCHUSD","BCCUSD","XRPUSD","LTCUSD","XMRUSD","DSHUSD","EOSUSD","TRXUSD","ADAUSD","BSVUSD","XLMUSD","GLDUSD","ZECUSD","XEMUSD"};
   double value=amount;
   for(int i=0;i<ArraySize(upper);i++)
      if(AccountInfoString(ACCOUNT_CURRENCY)==upper[i] || AccountInfoString(ACCOUNT_CURRENCY)==lower[i])
      {
         const string pair=pairs[i]+suffix;
         if(iClose(pair,PERIOD_D1,1)>0.0)
         {
            const double rate=iClose(pair,PERIOD_D1,1);
            value=i>=3 && i<=11 ? amount/rate : rate*amount;
         }
         else if(i==9 || i==10)
         {
            const string fallback="USDCNY"+suffix;
            if(iClose(fallback,PERIOD_D1,1)>0.0) value=amount/iClose(fallback,PERIOD_D1,1);
         }
         if(i==3) i++;
      }
   return MathRound(value);
}

double Bot2CurrencyConversion(const double amount,const string &suffix,const bool to_usd)
{
   if(to_usd) return Bot2CurrencyToUsd(amount,suffix);
   return Bot2CurrencyFromUsd(amount,suffix);
}
#endif
