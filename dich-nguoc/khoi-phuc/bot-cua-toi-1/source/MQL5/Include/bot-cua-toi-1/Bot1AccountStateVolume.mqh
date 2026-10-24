// Full ordering: withdrawal update, highest-balance persistence, currency, volume.
// The caller supplies the restored timestamps and original key names.
#ifndef BOT1_ACCOUNT_STATE_VOLUME_MQH
#define BOT1_ACCOUNT_STATE_VOLUME_MQH
#include "Bot1AccountVolume.mqh"
#include "Bot1Withdrawal.mqh"
bool Bot1PrepareAccountStateVolume(const Bot1VolumeSettings &r,const Bot1VolumeContext &c,
                                      Bot1VolumeState &s,const string currency,const string suffix,
                                      const bool reset_on_withdrawal,const string peak_key,const string time_key,
                                      long &last_check,long &last_deal_time)
{
   s.warnings=0;s.alerts=0;s.peak_writes=0;
   double balance=r.use_equity ? c.equity : c.balance;
   s.effective_balance=balance;
   Bot1UpdateWithdrawals(reset_on_withdrawal,balance,peak_key,time_key,last_check,last_deal_time,s.highest_balance);
   uint peak_write=0;
   if(s.highest_balance<balance)
   {
      s.highest_balance=balance;
      GlobalVariableSet(peak_key,balance);
      peak_write=1;
   }
   if(r.only_up && s.highest_balance>balance) balance=s.highest_balance;
   if(r.manual_balance>0.0) balance=r.manual_balance;
   if(balance==0.0) balance=0.01;
   s.effective_balance=balance;
   bool ok=Bot1PrepareAccountVolume(r,c,s,currency,suffix);
   if(ok) s.peak_writes+=peak_write;
   return ok;
}
#endif
