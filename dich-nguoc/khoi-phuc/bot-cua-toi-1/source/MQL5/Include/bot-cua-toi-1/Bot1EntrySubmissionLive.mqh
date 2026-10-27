#ifndef BOT1_ENTRY_SUBMISSION_LIVE_MQH
#define BOT1_ENTRY_SUBMISSION_LIVE_MQH
#include "Bot1NfpFilter.mqh"
#include "Bot1PendingQueueLive.mqh"
#include "Bot1PendingSubmission.mqh"

struct Bot1EntrySubmissionFlags
{
   uchar check_free_margin,omit_real_sl_tp;
};

bool Bot1SendEntryLive(const bool first_attempt,const bool buy,const double price,
                       const double sl,const double tp,const Bot1EntrySubmissionFlags &flags,
                       const Bot1PendingRestoreSettings &restore,const double &unit,
                       Bot1NfpExecution &execution,const double &volumes[],const uint &strategy_index)
{
   uchar omit;
   datetime expiration;
   if(first_attempt)
   {
      omit=flags.omit_real_sl_tp;
      expiration=restore.expiration_base;
   }
   else
   {
      expiration=restore.expiration_base;
      omit=flags.omit_real_sl_tp;
   }
   double send_sl=0.0,send_tp=0.0;
   if(omit==0) { send_sl=sl;send_tp=tp; }
   string comment=restore.comment;
   double volume=volumes[strategy_index];
   string symbol=execution.symbol;
   return Bot1OpenPending(execution.trade,execution.options,execution.strategy_magic,restore.virtual_expiration,symbol,
                          buy ? ORDER_TYPE_BUY_STOP : ORDER_TYPE_SELL_STOP,
                          volume,price,send_sl,send_tp,comment,expiration);
}

void Bot1SubmitEntryAfterPriceLive(const bool buy,const double base_price,
                                   const Bot1EntrySubmissionFlags &flags,
                                   const Bot1PendingRestoreSettings &restore,const double &unit,
                                   Bot1NfpExecution &execution,const double &volumes[],const uint &strategy_index,
                                   Bot1PendingQueue &queue)
{
   if(flags.check_free_margin!=0)
   {
      double margin_volume=volumes[strategy_index];
      string margin_symbol=execution.symbol;
      if(!Bot1MarginGuard(margin_symbol,buy ? ORDER_TYPE_BUY : ORDER_TYPE_SELL,margin_volume))
      {
         Print("Free margin not sufficient for setting order...");
         return;
      }
   }
   uint digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   double raw_price=unit*(buy ? 0.0 : -0.0)+base_price;
   double price=Bot1RoundPrice(raw_price,digits);
   digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   double raw_sl=buy ? Bot1SubmissionDifference(base_price,(restore.sl_distance+0.0)*unit)
                     : ((restore.sl_distance+0.0)*unit)+base_price;
   double sl=Bot1RoundPrice(raw_sl,digits);
   digits=(uint)SymbolInfoInteger(execution.symbol,SYMBOL_DIGITS);
   double raw_tp=buy ? restore.tp_distance*unit+base_price
                     : Bot1SubmissionDifference(base_price,restore.tp_distance*unit);
   double tp=Bot1RoundPrice(raw_tp,digits);
   double volume=volumes[strategy_index];
   if(!Bot1ValidateVolume(execution.symbol,volume)) return;
   int limit=(int)AccountInfoInteger(ACCOUNT_LIMIT_ORDERS);
   if(limit!=0 && OrdersTotal()>=limit) return;
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
   bool accepted=Bot1SendEntryLive(true,buy,price,sl,tp,flags,restore,unit,execution,volumes,strategy_index);
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
      Bot1SendEntryLive(false,buy,price,sl,tp,flags,restore,unit,execution,volumes,strategy_index);
   }
   string text=Bot1TradeErrorText(GetLastError(),queue.error_count);
   string prefix="error: '";
   prefix+=text;
   string message=prefix;
   message+="' when setting entry order";
   Print(message);
}

#endif
