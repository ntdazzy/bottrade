// Native withdrawal update: RVA 0x173f0.
// Keys are provided by the caller; terminal access can be replaced for isolated checks.
#ifndef BOT1_WITHDRAWAL_MQH
#define BOT1_WITHDRAWAL_MQH
void Bot1UpdateWithdrawals(const bool enabled,const double balance,const string peak_key,
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
         Print("Peak balance reset after withdrawal: ",balance);
         highest_balance=balance;
         GlobalVariableSet(peak_key,balance);
      }
   }
   HistorySelect(0,2147483647);
}
#endif
