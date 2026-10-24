// Connect the verified currency and numeric-volume components.
// Withdrawal-history changes must be applied to highest_balance before this call.
#ifndef BOT1_ACCOUNT_VOLUME_MQH
#define BOT1_ACCOUNT_VOLUME_MQH
#include "Bot1Volume.mqh"
#include "Bot1Currency.mqh"
bool Bot1PrepareAccountVolume(const Bot1VolumeSettings &r,const Bot1VolumeContext &c,
                                 Bot1VolumeState &s,const string currency,const string suffix)
{
   Bot1VolumeContext values=c;
   double balance=r.use_equity ? c.equity : c.balance;
   if(r.only_up && s.highest_balance>balance) balance=s.highest_balance;
   if(r.manual_balance>0.0) balance=r.manual_balance;
   if(balance==0.0) balance=0.01;
   if(s.mode==999 && !(c.tick_value<=0.0))
      if(!Bot1ConvertCurrency(balance,currency,suffix,true,values.converted_balance)) return false;
   return Bot1PrepareVolume(r,values,s);
}
#endif
