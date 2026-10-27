// Native conversion with fresh account reads: 36220 (bot1), 8300/41780 (bot3).
#ifndef BOT1_VOLUME_CURRENCY_MQH
#define BOT1_VOLUME_CURRENCY_MQH
double Bot1VolumeCurrency(const double amount,const string &suffix)
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
#endif
