// Connect the verified currency and numeric-volume components.
// Withdrawal-history changes must be applied to highest_balance before this call.
#ifndef BOT3_ACCOUNT_VOLUME_MQH
#define BOT3_ACCOUNT_VOLUME_MQH
#include "Bot3Volume.mqh"
#include "Bot3Currency.mqh"
bool Bot3PrepareAccountVolume(const Bot3VolumeSettings &r,const Bot3VolumeContext &c,
                                 Bot3VolumeState &s,const string currency,const string suffix)
{
   Bot3VolumeContext values=c;
   double balance=r.use_equity ? c.equity : c.balance;
   if(r.only_up && s.highest_balance>balance) balance=s.highest_balance;
   if(r.manual_balance>0.0) balance=r.manual_balance;
   if(balance==0.0) balance=0.01;
   if(s.mode==999 && !(c.tick_value<=0.0))
      if(!Bot3ConvertCurrency(balance,currency,suffix,false,values.converted_balance)) return false;
   if(s.mode==1234 && !r.weighted)
      if(!Bot3ConvertCurrency(balance,currency,suffix,true,values.converted_dd_balance)) return false;
   return Bot3PrepareVolume(r,values,s);
}
#endif
