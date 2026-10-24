// Native message functions 0x235c0,0x23fa0,0x26060,0x26360.
#ifndef BOT1_TRADE_MESSAGES_MQH
#define BOT1_TRADE_MESSAGES_MQH
string Bot1TradeUnsignedText(const uint value) { return (string)value; }
string Bot1TradeSignedText(const int value) { return (string)value; }
string Bot1TradeOrderTypeText(const uint type)
{
   switch(type)
   {
      case 0:return "buy";case 1:return "sell";
      case 2:return "buy limit";case 3:return "sell limit";
      case 4:return "buy stop";case 5:return "sell stop";
      case 6:return "buy stop limit";case 7:return "sell stop limit";
   }
   return "unknown order type "+Bot1TradeUnsignedText(type);
}
string Bot1TradePriceText(const double price,const double trigger,const int digits)
{
   string value=DoubleToString(price,digits);
   if(trigger!=0.0)
   {
      string stop=DoubleToString(trigger,digits);
      return StringFormat("%s (%s)",value,stop);
   }
   return value;
}
string Bot1FormatTradeResult(const MqlTradeRequest &request,const MqlTradeResult &result)
{
   string symbol=(request.symbol==NULL) ? _Symbol : request.symbol;
   int digits=_Digits;uint execution=0;long value=0;
   if(SymbolInfoInteger(symbol,SYMBOL_DIGITS,value)) digits=(int)value;
   if(SymbolInfoInteger(symbol,SYMBOL_TRADE_EXEMODE,value)) execution=(uint)value;
   switch(result.retcode)
   {
      case 10004:
      {
         string ask=DoubleToString(result.ask,digits);
         string bid=DoubleToString(result.bid,digits);
         return StringFormat("requote (%s/%s)",bid,ask);
      }
      case 10009:
         if(request.action==1 && execution<3) return StringFormat("done at %s",DoubleToString(result.price,digits));
         return "done";
      case 10010:
         if(request.action==1 && execution<3)
         {
            string price=DoubleToString(result.price,digits);
            string volume=DoubleToString(result.volume,2);
            return StringFormat("done partially %s at %s",volume,price);
         }
         return StringFormat("done partially %s",DoubleToString(result.volume,2));
      case 10006:return "rejected";case 10007:return "canceled";case 10008:return "placed";
      case 10011:return "common error";case 10012:return "timeout";case 10013:return "invalid request";
      case 10014:return "invalid volume";case 10015:return "invalid price";case 10016:return "invalid stops";
      case 10017:return "trade disabled";case 10018:return "market closed";case 10019:return "not enough money";
      case 10020:return "price changed";case 10021:return "off quotes";case 10022:return "invalid expiration";
      case 10023:return "order changed";case 10024:return "too many requests";case 10025:return "no changes";
      case 10026:return "auto trading disabled by server";case 10027:return "auto trading disabled by client";
      case 10028:return "locked";case 10029:return "frozen";case 10030:return "invalid fill";
      case 10031:return "no connection";case 10032:return "only real";case 10033:return "limit orders";
      case 10034:return "limit volume";case 10035:return "invalid order";case 10036:return "position closed";
      case 10039:return "close order already exists";case 10040:return "limit positions";
   }
   return "unknown retcode "+Bot1TradeUnsignedText(result.retcode);
}
string Bot1FormatTradeRequest(const MqlTradeRequest &request,const int margin_mode)
{
   string symbol=(request.symbol==NULL) ? _Symbol : request.symbol;
   int digits=_Digits;uint execution=0;long value=0;
   if(SymbolInfoInteger(symbol,SYMBOL_DIGITS,value)) digits=(int)value;
   if(SymbolInfoInteger(symbol,SYMBOL_TRADE_EXEMODE,value)) execution=(uint)value;
   bool position=margin_mode==2 && request.position!=0;
   string output="";
   switch(request.action)
   {
      case 1:
      {
         if(execution>3) return output;
         string price="";
         if(execution<2) price=DoubleToString(request.price,digits);
         string volume=DoubleToString(request.volume,2);
         string type=Bot1TradeOrderTypeText((uint)request.type);
         if(execution==0)
            output=position ? StringFormat("request %s %s position #%I64u %s at %s",type,volume,request.position,request.symbol,price)
                            : StringFormat("request %s %s %s at %s",type,volume,request.symbol,price);
         else if(execution==1)
            output=position ? StringFormat("instant %s %s position #%I64u %s at %s",type,volume,request.position,request.symbol,price)
                            : StringFormat("instant %s %s %s at %s",type,volume,request.symbol,price);
         else if(execution==2)
            output=position ? StringFormat("market %s %s position #%I64u %s",type,volume,request.position,request.symbol)
                            : StringFormat("market %s %s %s",type,volume,request.symbol);
         else
            output=position ? StringFormat("exchange %s %s position #%I64u %s",type,volume,request.position,request.symbol)
                            : StringFormat("exchange %s %s %s",type,volume,request.symbol);
         break;
      }
      case 5:
      {
         string price=Bot1TradePriceText(request.price,request.stoplimit,digits);
         string volume=DoubleToString(request.volume,2);
         string type=Bot1TradeOrderTypeText((uint)request.type);
         output=StringFormat("%s %s %s at %s",type,volume,request.symbol,price);
         break;
      }
      case 6:
      {
         string tp=DoubleToString(request.tp,digits),sl=DoubleToString(request.sl,digits);
         return position ? StringFormat("modify position #%I64u %s (sl: %s, tp: %s)",request.position,request.symbol,sl,tp)
                         : StringFormat("modify %s (sl: %s, tp: %s)",request.symbol,sl,tp);
      }
      case 7:
      {
         string tp=DoubleToString(request.tp,digits),sl=DoubleToString(request.sl,digits);
         string price=Bot1TradePriceText(request.price,request.stoplimit,digits);
         return StringFormat("modify #%I64u at %s (sl: %s tp: %s)",request.order,price,sl,tp);
      }
      case 8:return StringFormat("cancel #%I64u",request.order);
      case 10:
         return position ? StringFormat("close position #%I64u by #%I64u",request.position,request.position_by)
                         : StringFormat("wrong action close by (#%I64u by #%I64u)",request.position,request.position_by);
      default:return "unknown action "+Bot1TradeSignedText((int)request.action);
   }
   if(request.sl!=0.0) output+=StringFormat(" sl: %s",DoubleToString(request.sl,digits));
   if(request.tp!=0.0) output+=StringFormat(" tp: %s",DoubleToString(request.tp,digits));
   return output;
}
#endif
