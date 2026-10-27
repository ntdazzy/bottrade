// Native withdrawal update: RVA 0x173f0.
// Keys are provided by the caller; terminal access can be replaced for isolated checks.
#ifndef BOT1_VOLUME_WITHDRAWAL_MQH
#define BOT1_VOLUME_WITHDRAWAL_MQH
void Bot1VolumeWithdrawals(const bool enabled,const double balance,const string peak_key,
                              const string time_key,long &last_check,long &last_deal_time,double &highest_balance)
{
   if(!enabled) return;
   if(MQLInfoInteger(MQL_TESTER)==1) return;
   if(TimeCurrent()-last_check<=59) return;
   last_check=TimeCurrent();
   bool selected=HistorySelect(last_deal_time,TimeCurrent()+86400);
   if(selected)
   {
      long latest=last_deal_time;
      double withdrawals=0.0;
      int total=HistoryDealsTotal();
      for(int i=0;i<total;i++)
      {
         ulong ticket=HistoryDealGetTicket(i);
         if(ticket==0) continue;
         if((int)HistoryDealGetInteger(ticket,DEAL_TYPE)!=2) continue;
         long time=HistoryDealGetInteger(ticket,DEAL_TIME);
         if(time<=last_deal_time) continue;
         if(latest<time) latest=time;
         double profit=HistoryDealGetDouble(ticket,DEAL_PROFIT);
         if(profit<0.0) withdrawals+=profit;
      }
      if(last_deal_time<latest)
      {
         last_deal_time=latest;
         GlobalVariableSet(time_key,(double)latest);
      }
      if(withdrawals<0.0 && balance<highest_balance)
      {
         const string balance_text=DoubleToString(balance,2);
         const string peak_text=DoubleToString(highest_balance,2);
         const string withdrawal_text=DoubleToString(-withdrawals,2);
         Print("Withdrawal of ",withdrawal_text," detected - OnlyUp highest balance reset from ",peak_text," to ",balance_text);
         highest_balance=balance;
         GlobalVariableSet(peak_key,balance);
      }
   }
   HistorySelect(0,2147483647);
}
#endif
