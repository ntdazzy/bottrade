// Native account-state initialization, bounded part of RVA 0xc30.
#ifndef BOT1_ACCOUNT_INITIALIZATION_MQH
#define BOT1_ACCOUNT_INITIALIZATION_MQH
void Bot1InitializeAccountState(const bool use_equity,const bool reset_highest,const double manual_balance,
                                  double &effective_balance,double &highest_balance,string &peak_key,
                                  string &time_key,long &last_deal_time)
{
   effective_balance=AccountInfoDouble(ACCOUNT_BALANCE);
   if(use_equity) effective_balance=AccountInfoDouble(ACCOUNT_EQUITY);
   peak_key="HighestBalance"+(string)StringToInteger(IntegerToString(AccountInfoInteger(ACCOUNT_LOGIN)));
   if(reset_highest)
   {
      GlobalVariableSet(peak_key,0.0);
      Sleep(5000);
   }
   double stored=GlobalVariableGet(peak_key);
   highest_balance=effective_balance;
   if(effective_balance<stored)
   {
      Print("HighestBalance value found: "+(string)stored);
      highest_balance=stored;
   }
   GlobalVariableSet(peak_key,highest_balance);
   time_key="LastBalanceOp"+IntegerToString(AccountInfoInteger(ACCOUNT_LOGIN));
   bool exists=GlobalVariableCheck(time_key);
   if(!reset_highest && exists) last_deal_time=(long)GlobalVariableGet(time_key);
   else last_deal_time=(long)TimeCurrent();
   GlobalVariableSet(time_key,(double)last_deal_time);
   if(manual_balance>0.0) effective_balance=manual_balance;
}
#endif
