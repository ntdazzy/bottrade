// Native currency helpers: bot 1, both conversion directions.
// Account currency is stable for a call; preserve case and repeated price reads.
#ifndef BOT1_CURRENCY_MQH
#define BOT1_CURRENCY_MQH
int Bot1CurrencyPair(const double amount,const string pair,const bool multiply,double &result)
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
bool Bot1ConvertCurrency(const double amount,const string currency,const string suffix,
                            const bool to_usd,double &result)
{
   result=amount;
   string codes[]={"EUR","GBP","AUD","JPY","YEN","CHF","HKD","RUB","SGD","BTC","ETH",
                   "BCH","BCC","XRP","LTC","XMR","DSH","EOS","TRX","ADA","BSV","XLM","GLD","ZEC","XEM",
                   "CZK","CNH","CNY"};
   string lower[]={"eur","gbp","aud","jpy","yen","chf","hkd","rub","sgd","btc","eth",
                   "bch","bcc","xrp","ltc","xmr","dsh","eos","trx","ada","bsv","xlm","gld","zec","xem",
                   "czk","cnh","cny"};
   string pairs[]={"EURUSD","GBPUSD","AUDUSD","USDJPY","USDJPY","USDCHF","USDHKD","USDRUB","USDSGD","BTCUSD","ETHUSD",
                   "BCHUSD","BCCUSD","XRPUSD","LTCUSD","XMRUSD","DSHUSD","EOSUSD","TRXUSD","ADAUSD","BSVUSD","XLMUSD","GLDUSD","ZECUSD","XEMUSD",
                   "USDCZK","USDCNH","USDCNH"};
   for(int i=0;i<ArraySize(codes);i++)
   {
      if(currency!=codes[i] && currency!=lower[i]) continue;
      // These three currencies have no conversion branch in the reverse helper.
      if(!to_usd && i>=25) break;
      bool usd_first=(i>=3 && i<=8) || i>=25;
      bool multiply=to_usd ? !usd_first : usd_first;
      int status=Bot1CurrencyPair(amount,pairs[i]+suffix,multiply,result);
      if(status<0) return false;
      // Native reverse CHF code reads the same pair a second time.
      if(!to_usd && i==5)
         if(Bot1CurrencyPair(amount,pairs[i]+suffix,multiply,result)<0) return false;
      if(to_usd && i>=26 && status==0)
         if(Bot1CurrencyPair(amount,"USDCNY"+suffix,false,result)<0) return false;
      break;
   }
   if(to_usd) result=MathRound(result);
   return true;
}
#endif
