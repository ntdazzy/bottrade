#ifndef BOT3_ENTRY_SUBMISSION_LIVE_MQH
#define BOT3_ENTRY_SUBMISSION_LIVE_MQH
#include "Bot3NfpFilter.mqh"
#include "Bot3PendingQueueLive.mqh"
#include "Bot3PendingSubmission.mqh"

struct Bot3EntrySubmissionFlags
{
   uchar check_free_margin,omit_real_sl_tp;
};

bool Bot3SendEntryLive(const bool buy,const double price,const double sl,const double tp,
                       const Bot3EntrySubmissionFlags &flags,const Bot3PendingRestoreSettings &restore,
                       const double &unit,Bot3NfpExecution &execution,const double &volumes[],
                       const uint &strategy_index)
{
   datetime expiration=restore.expiration_base;
   double send_sl=0.0,send_tp=0.0;
   if(flags.omit_real_sl_tp==0) { send_sl=sl;send_tp=tp; }
   string comment=restore.comment;
   double volume=volumes[strategy_index];
   string symbol=execution.symbol;
   return Bot3OpenPending(execution.trade,execution.options,execution.strategy_magic,restore.virtual_expiration,symbol,
                          buy ? ORDER_TYPE_BUY_STOP : ORDER_TYPE_SELL_STOP,
                          volume,price,send_sl,send_tp,comment,expiration);
}

void Bot3SubmitEntryAfterPriceLive(const bool buy,const double base_price,
                                   const Bot3EntrySubmissionFlags &flags,
                                   const Bot3PendingRestoreSettings &restore,const double &unit,
                                   Bot3NfpExecution &execution,const double &volumes[],const uint &strategy_index,
                                   Bot3PendingQueue &queue)
{
   if(flags.check_free_margin!=0)
   {
      double margin_volume=volumes[strategy_index];
      string margin_symbol=execution.symbol;
      if(!Bot3MarginGuard(margin_symbol,buy ? ORDER_TYPE_BUY : ORDER_TYPE_SELL,margin_volume))
      {
         Print("Free margin not sufficient for setting order...");
         return;
      }
   }
   uint digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   double raw_price=unit*(buy ? 0.0 : -0.0)+base_price;
   double price=Bot3RoundPrice(raw_price,digits);
   digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   double raw_sl=buy ? Bot3SubmissionDifference(base_price,(restore.sl_distance+0.0)*unit)
                     : ((restore.sl_distance+0.0)*unit)+base_price;
   double sl=Bot3RoundPrice(raw_sl,digits);
   digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   double raw_tp=buy ? restore.tp_distance*unit+base_price
                     : Bot3SubmissionDifference(base_price,restore.tp_distance*unit);
   double tp=Bot3RoundPrice(raw_tp,digits);
   double volume=volumes[strategy_index];
   if(!Bot3ValidateVolume(execution.symbol,volume)) return;
   if(!Bot3AllowsPendingOrder()) return;
   if(buy)
   {
      double ask=execution.tick.ask;
      if(!(ask<price-execution.gap)) return;
      if(!(ask<price-execution.threshold_a)) return;
   }
   else
   {
      double bid=execution.tick.bid;
      if(!(execution.gap+price<bid)) return;
      if(!(execution.threshold_a+price<bid)) return;
   }
   bool accepted=Bot3SendEntryLive(buy,price,sl,tp,flags,restore,unit,execution,volumes,strategy_index);
   if(accepted)
   {
      for(int row=0;row<100;row++)
         if(queue.results[row][0]==0.0)
         {
            queue.results[row][0]=(double)(uint)accepted;
            queue.results[row][1]=base_price;
            return;
         }
      return;
   }
   while(GetLastError()==132)
   {
      Sleep(2500);
      Bot3SendEntryLive(buy,price,sl,tp,flags,restore,unit,execution,volumes,strategy_index);
   }
   string text=Bot3TradeErrorText(GetLastError(),queue.error_count);
   string prefix="error: '";
   prefix+=text;
   string message=prefix;
   message+="' when setting entry order";
   Print(message);
}

#endif
