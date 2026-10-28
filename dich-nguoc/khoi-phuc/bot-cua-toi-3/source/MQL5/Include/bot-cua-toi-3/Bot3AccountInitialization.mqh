// Native account-state initialization, bounded part of RVA 0xc30.
#ifndef BOT3_ACCOUNT_INITIALIZATION_MQH
#define BOT3_ACCOUNT_INITIALIZATION_MQH
void Bot3InitializeAccountStateWithSharedInputs(const uchar &use_equity,const uchar &reset_highest,const double &manual_balance,
                                                double &effective_balance,double &highest_balance,string &peak_key,
                                                string &time_key,long &last_deal_time)
{
   // Read the live account value before applying the manual override at the end.
   effective_balance=AccountInfoDouble(ACCOUNT_BALANCE);
   if(use_equity!=0) effective_balance=AccountInfoDouble(ACCOUNT_EQUITY);
   peak_key="HighestBalance"+(string)StringToInteger(IntegerToString(AccountInfoInteger(ACCOUNT_LOGIN)));
   const bool reset=reset_highest!=0;
   // Use one cached reset decision for both persisted-state branches.
   if(reset)
   {
      GlobalVariableSet(peak_key,0.0);
      Sleep(5000);
   }
   double stored=GlobalVariableGet(peak_key);
   double chosen=effective_balance;
   if(effective_balance<stored)
   {
      Print("HighestBalance value found: "+(string)stored);
      chosen=stored;
   }
   highest_balance=chosen;
   GlobalVariableSet(peak_key,highest_balance);
   time_key="LastBalanceOp"+IntegerToString(AccountInfoInteger(ACCOUNT_LOGIN));
   bool exists=GlobalVariableCheck(time_key);
   if(!reset && exists) last_deal_time=(long)GlobalVariableGet(time_key);
   else last_deal_time=(long)TimeCurrent();
   GlobalVariableSet(time_key,(double)last_deal_time);
   if(manual_balance>0.0) effective_balance=manual_balance;
}

void Bot3InitializeAccountState(const bool use_equity,const bool reset_highest,const double manual_balance,
                                double &effective_balance,double &highest_balance,string &peak_key,
                                string &time_key,long &last_deal_time)
{
   uchar use_equity_shared=use_equity ? 1 : 0;
   uchar reset_highest_shared=reset_highest ? 1 : 0;
   Bot3InitializeAccountStateWithSharedInputs(use_equity_shared,reset_highest_shared,manual_balance,
                                              effective_balance,highest_balance,peak_key,time_key,last_deal_time);
}
#endif
