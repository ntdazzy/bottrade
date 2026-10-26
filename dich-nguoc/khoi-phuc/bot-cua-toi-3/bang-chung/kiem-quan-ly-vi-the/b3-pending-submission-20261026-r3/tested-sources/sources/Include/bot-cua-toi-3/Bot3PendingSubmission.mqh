// Pending entry submission after the base price; a component, not a complete EA.
#ifndef BOT3_PENDING_SUBMISSION_MQH
#define BOT3_PENDING_SUBMISSION_MQH
#include "Bot3PriceLevels.mqh"
#include "Bot3Margin.mqh"
#include "Bot3VolumeValidation.mqh"
#include "Bot3OrderScan.mqh"
#include "Bot3TradeSend.mqh"
#include "Bot3TradeErrors.mqh"
struct Bot3PendingSubmissionSettings
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
double Bot3SubmissionDifference(const double left,const double right)
{
   if(left!=left) return left+0.0;
   if(right!=right) return right+0.0;
   return left-right;
}
// One send attempt for the first send and every retry; settings and volume are read fresh each time.
bool Bot3SendPendingEntry(const bool buy,const double price,const double sl,const double tp,
                          const Bot3PendingSubmissionSettings &settings,
                          const double &volumes[],const uint &strategy_index,
                          Bot3PendingRequestState &trade,Bot3TradeSendOptions &options)
{
   datetime expiration=settings.expiration;
   double send_sl=0.0,send_tp=0.0;
   if(settings.omit_real_sl_tp==0) { send_sl=sl;send_tp=tp; }
   string comment=settings.comment;
   double volume=volumes[strategy_index];
   string symbol=settings.symbol;
   return Bot3OpenPending(trade,options,settings.strategy_magic,settings.virtual_expiration,symbol,
                          buy ? ORDER_TYPE_BUY_STOP : ORDER_TYPE_SELL_STOP,
                          volume,price,send_sl,send_tp,comment,expiration);
}
void Bot3SubmitPendingAfterPrice(const bool buy,const double base_price,
                               const Bot3PendingSubmissionSettings &settings,
                               const double &volumes[],const uint &strategy_index,
                               double &results[][2],uint &error_count,
                               Bot3PendingRequestState &trade,Bot3TradeSendOptions &options)
{
   if(settings.check_free_margin!=0)
   {
      double margin_volume=volumes[strategy_index];
      string margin_symbol=settings.symbol;
      if(!Bot3MarginGuard(margin_symbol,buy ? ORDER_TYPE_BUY : ORDER_TYPE_SELL,margin_volume))
      {
         Print("Free margin not sufficient for setting order...");
         return;
      }
   }
   // Keep the signed-zero multiply and the +0.0: non-finite and signed-zero inputs depend on them.
   uint digits=(uint)SymbolInfoInteger(settings.symbol,SYMBOL_DIGITS);
   double raw_price=settings.unit*(buy ? 0.0 : -0.0)+base_price;
   double price=Bot3RoundPrice(raw_price,digits);
   digits=(uint)SymbolInfoInteger(settings.symbol,SYMBOL_DIGITS);
   double raw_sl=buy ? Bot3SubmissionDifference(base_price,(settings.stop_distance+0.0)*settings.unit)
                     : ((settings.stop_distance+0.0)*settings.unit)+base_price;
   double sl=Bot3RoundPrice(raw_sl,digits);
   digits=(uint)SymbolInfoInteger(settings.symbol,SYMBOL_DIGITS);
   double raw_tp=buy ? settings.take_distance*settings.unit+base_price
                     : Bot3SubmissionDifference(base_price,settings.take_distance*settings.unit);
   double tp=Bot3RoundPrice(raw_tp,digits);
   double volume=volumes[strategy_index];
   if(!Bot3ValidateVolume(settings.symbol,volume)) return;
   if(!Bot3AllowsPendingOrder()) return;
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
   bool accepted=Bot3SendPendingEntry(buy,price,sl,tp,settings,volumes,strategy_index,trade,options);
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
   // Retry results are ignored and there is no retry limit; only the last error decides.
   while(GetLastError()==132)
   {
      Sleep(2500);
      Bot3SendPendingEntry(buy,price,sl,tp,settings,volumes,strategy_index,trade,options);
   }
   string text=Bot3TradeErrorText(GetLastError(),error_count);
   string prefix="error: '";
   prefix+=text;
   string message=prefix;
   message+="' when setting entry order";
   Print(message);
}
#endif
