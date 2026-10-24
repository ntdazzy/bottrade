// Numeric volume preparation, native RVA 0x34780.
// Currency conversion and withdrawal-history changes must be supplied by the caller.
// Only use resulting state when this function returns true.
#ifndef BOT1_VOLUME_MQH
#define BOT1_VOLUME_MQH
#include "Bot1PriceLevels.mqh"
struct Bot1VolumeSettings
{
   bool use_equity; // Native 0x6a790
   bool only_up; // Native 0x6a770
   double manual_balance; // Native 0x6a738
   double start_lots; // Native 0x62530
   double max_lots; // Native 0x62538
   double lot_scale; // Native 0x682f0
   double manual_risk; // Native 0x62548
   double strategy_risk; // Native 0x6a758
};
struct Bot1VolumeContext
{
   double balance;
   double equity;
   double converted_balance;
   double converted_dd_balance;
   double tick_value;
   double minimum;
   double maximum;
   double step;
   double stop_distance;
   int multiplier;
   uint enabled_mask;
};
struct Bot1VolumeState
{
   double volume; // Native 0x66a80
   double effective_balance; // Native 0x6a320
   double highest_balance; // Native 0x6a328
   uint mode; // Native 0x62540
   double strategy_loss; // Native 0x69f70
   int balance_step; // Native 0x62550
   uint warnings;
   uint alerts;
   uint peak_writes;
};
bool Bot1PrepareVolume(const Bot1VolumeSettings &r,const Bot1VolumeContext &c,Bot1VolumeState &s)
{
   s.warnings=0;s.alerts=0;s.peak_writes=0;
   double balance=r.use_equity ? c.equity : c.balance;
   if(r.only_up && s.highest_balance>balance) balance=s.highest_balance;
   else if(s.highest_balance<balance) { s.highest_balance=balance;s.peak_writes++; }
   if(r.manual_balance>0.0) balance=r.manual_balance;
   if(balance==0.0) balance=0.01;
   s.effective_balance=balance;
   double lots=s.volume;
   bool known_step=c.step==0.1 || c.step==0.01 || c.step==0.001;
   uint digits=c.step==0.1 ? 1 : (c.step==0.01 ? 2 : 3);
   if(s.mode>=1 && s.mode<=998)
   {
      if(c.tick_value==0.0 || c.stop_distance==0.0 || c.multiplier==0)
      { s.alerts++;lots=0.01; }
      else if(known_step)
      {
         double budget=((double)s.mode/1000.0)*balance;
         double divisor=c.tick_value*c.stop_distance;
         if(divisor==0.0) return false;
         lots=Bot1RoundPrice((double)c.multiplier*0.01*(budget/divisor)*0.1,digits);
      }
   }
   if(s.mode==999)
   {
      if(c.tick_value<=0.0) { s.alerts++;s.mode=9999; }
      else if(known_step)
      {
         double budget=(r.manual_risk/100.0)*c.converted_balance;
         double divisor=0.1*c.stop_distance;
         if(divisor==0.0) return false;
         lots=Bot1RoundPrice((double)c.multiplier*0.01*(budget/divisor)*0.1,digits);
      }
   }
   if(s.mode==0 && known_step)
      lots=Bot1RoundPrice((double)c.multiplier*0.01*r.start_lots,digits);
   if(s.mode==9999 && known_step)
   {
      if(s.balance_step==0) return false;
      lots=Bot1RoundPrice(0.01*(double)c.multiplier*(balance/(double)s.balance_step)*0.01,digits);
   }
   if(s.mode==3 && known_step)
   {
      if(s.strategy_loss==0.0) return false;
      lots=Bot1RoundPrice((((r.strategy_risk/s.strategy_loss)*balance)/100.0)*0.01,digits);
   }
   lots=lots*r.lot_scale;
   if(lots<c.minimum) lots=c.minimum;
   lots=r.start_lots<=lots ? lots : r.start_lots;
   lots=lots<=r.max_lots ? lots : r.max_lots;
   if(lots<c.minimum) s.warnings++;
   if(c.maximum<lots && c.maximum!=0.0) { s.warnings++;lots=c.maximum; }
   // The native function leaves the previous array element for other step sizes.
   if(known_step)
   {
      double power=c.step==0.1 ? 10.0 : (c.step==0.01 ? 100.0 : 1000.0);
      double floored=MathFloor(lots*power)/power;
      s.volume=Bot1RoundPrice(floored,digits);
   }
   return true;
}
#endif
