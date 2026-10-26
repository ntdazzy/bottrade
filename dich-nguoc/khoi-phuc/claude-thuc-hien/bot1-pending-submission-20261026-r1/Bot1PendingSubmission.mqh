// Pending entry submission after the base price; a component, not a complete EA.
#ifndef BOT1_PENDING_SUBMISSION_MQH
#define BOT1_PENDING_SUBMISSION_MQH
#include "Bot1PriceLevels.mqh"
#include "Bot1Margin.mqh"
#include "Bot1VolumeValidation.mqh"
#include "Bot1TradeSend.mqh"
#include "Bot1TradeErrors.mqh"
struct Bot1PendingSubmissionSettings
{
   string symbol,comment;
   uchar check_free_margin,omit_real_sl_tp,virtual_expiration;
   int strategy_magic;
   datetime expiration;
   double unit,stop_distance,take_distance;
   double minimum_stop_price,minimum_freeze_price;
   double ask,bid;
};
// left-right that returns a NaN operand with its sign and payload; a compiled negate-then-add could flip the sign.
double Bot1SubmissionDifference(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left-right;
}
// One send attempt (procedure C); settings and volume are read fresh, prices are never recomputed.
// The first send reads omit_real_sl_tp before expiration; a retry reads expiration first.
bool Bot1SendPendingEntry(const bool first_attempt,const bool buy,const double price,
                          const double sl,const double tp,
                          const Bot1PendingSubmissionSettings &settings,
                          const double &volumes[],const uint &strategy_index,
                          Bot1PendingRequestState &trade,Bot1TradeSendOptions &options)
{
   uchar omit;
   datetime expiration;
   if(first_attempt)
   {
      omit=settings.omit_real_sl_tp;
      expiration=settings.expiration;
   }
   else
   {
      expiration=settings.expiration;
      omit=settings.omit_real_sl_tp;
   }
   double send_sl=0.0,send_tp=0.0;
   if(omit==0) { send_sl=sl;send_tp=tp; }
   string comment=settings.comment;
   double volume=volumes[strategy_index];
   string symbol=settings.symbol;
   return Bot1OpenPending(trade,options,settings.strategy_magic,settings.virtual_expiration,symbol,
                          buy ? ORDER_TYPE_BUY_STOP : ORDER_TYPE_SELL_STOP,
                          volume,price,send_sl,send_tp,comment,expiration);
}
void Bot1SubmitPendingAfterPrice(const bool buy,const double base_price,
                               const Bot1PendingSubmissionSettings &settings,
                               const double &volumes[],const uint &strategy_index,
                               double &results[][2],uint &error_count,
                               Bot1PendingRequestState &trade,Bot1TradeSendOptions &options)
{
   if(settings.check_free_margin!=0)
   {
      double margin_volume=volumes[strategy_index];
      string margin_symbol=settings.symbol;
      if(!Bot1MarginGuard(margin_symbol,buy ? ORDER_TYPE_BUY : ORDER_TYPE_SELL,margin_volume))
      {
         Print("Free margin not sufficient for setting order...");
         return;
      }
   }
   // Keep the signed-zero multiply and the +0.0: non-finite and signed-zero inputs depend on them.
   uint digits=(uint)SymbolInfoInteger(settings.symbol,SYMBOL_DIGITS);
   double raw_price=settings.unit*(buy ? 0.0 : -0.0)+base_price;
   double price=Bot1RoundPrice(raw_price,digits);
   digits=(uint)SymbolInfoInteger(settings.symbol,SYMBOL_DIGITS);
   double raw_sl=buy ? Bot1SubmissionDifference(base_price,(settings.stop_distance+0.0)*settings.unit)
                     : ((settings.stop_distance+0.0)*settings.unit)+base_price;
   double sl=Bot1RoundPrice(raw_sl,digits);
   digits=(uint)SymbolInfoInteger(settings.symbol,SYMBOL_DIGITS);
   double raw_tp=buy ? settings.take_distance*settings.unit+base_price
                     : Bot1SubmissionDifference(base_price,settings.take_distance*settings.unit);
   double tp=Bot1RoundPrice(raw_tp,digits);
   double volume=volumes[strategy_index];
   if(!Bot1ValidateVolume(settings.symbol,volume)) return;
   // Account pending-order limit read directly; OrdersTotal is called only for a non-zero limit.
   int limit=(int)AccountInfoInteger(ACCOUNT_LIMIT_ORDERS);
   if(limit!=0 && OrdersTotal()>=limit) return;
   if(buy)
   {
      double ask=settings.ask;
      if(!(ask<price-settings.minimum_freeze_price)) return;
      if(!(ask<price-settings.minimum_stop_price)) return;
   }
   else
   {
      double bid=settings.bid;
      if(!(settings.minimum_freeze_price+price<bid)) return;
      if(!(settings.minimum_stop_price+price<bid)) return;
   }
   bool accepted=Bot1SendPendingEntry(true,buy,price,sl,tp,settings,volumes,strategy_index,trade,options);
   // Column 0 gets the send result (1.0), not a ticket; column 1 gets the unrounded base price.
   if(accepted)
   {
      for(int row=0;row<100;row++)
         if(results[row][0]==0.0)
         {
            results[row][0]=(double)(uint)accepted;
            results[row][1]=base_price;
            return;
         }
      return;
   }
   // Retries have no limit and their results are ignored; the error below is reported even after a retry succeeds.
   while(GetLastError()==132)
   {
      Sleep(2500);
      Bot1SendPendingEntry(false,buy,price,sl,tp,settings,volumes,strategy_index,trade,options);
   }
   string text=Bot1TradeErrorText(GetLastError(),error_count);
   string prefix="error: '";
   prefix+=text;
   string message=prefix;
   message+="' when setting entry order";
   Print(message);
}
#endif
