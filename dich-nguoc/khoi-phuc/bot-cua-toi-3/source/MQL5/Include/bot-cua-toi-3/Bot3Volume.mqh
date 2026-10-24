// Numeric volume preparation, native RVA 0x3f900.
// Currency conversion and withdrawal-history changes must be supplied by the caller.
// Only use resulting state when this function returns true.
#ifndef BOT3_VOLUME_MQH
#define BOT3_VOLUME_MQH
#include "Bot3PriceLevels.mqh"
struct Bot3VolumeSettings
{
   bool use_equity; // Native 0x1d7180
   bool only_up; // Native 0x1d7160
   double manual_balance; // Native 0x1d7128
   double start_lots; // Native 0x6d620
   double max_lots; // Native 0x6d628
   double lot_scale; // Native 0x6d1c8
   double manual_risk; // Native 0x6d638
   double strategy_risk; // Native 0x1d7150
   double max_total_dd; // Native 0x1d7140
   bool weighted; // Native 0x1d7148
   int frequency; // Native 0x6d21c
};
struct Bot3VolumeContext
{
   double balance;
   double equity;
   double converted_balance;
   double converted_dd_balance;
   double weight_denominator;
   double tick_value;
   double minimum;
   double maximum;
   double step;
   double stop_distance;
   int multiplier;
   uint enabled_mask;
};
struct Bot3VolumeState
{
   double volume; // Native 0x73ac0
   double effective_balance; // Native 0x1d6c60
   double highest_balance; // Native 0x1d6c68
   uint mode; // Native 0x6d630
   double strategy_loss; // Native 0x76fa0
   int balance_step; // Native 0x6d640
   double adaptive_fraction; // Native 0x6d428
   uint warnings;
   uint alerts;
   uint peak_writes;
};
bool Bot3PrepareVolume(const Bot3VolumeSettings &r,const Bot3VolumeContext &c,Bot3VolumeState &s)
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
   if(s.mode==999 && !(c.tick_value<=0.0) && known_step)
   {
      double budget=(r.manual_risk/100.0)*c.converted_balance;
      double divisor=0.1*c.stop_distance;
      if(divisor==0.0) return false;
      lots=Bot3RoundPrice((double)c.multiplier*0.01*(budget/divisor)*0.1,digits);
   }
   if(s.mode==0 && known_step)
      lots=Bot3RoundPrice((double)c.multiplier*0.01*r.start_lots,digits);
   if(s.mode==9999 && known_step)
   {
      if(s.balance_step==0) return false;
      lots=Bot3RoundPrice(0.01*(double)c.multiplier*(balance/(double)s.balance_step)*0.01,digits);
   }
   if(s.mode==1234)
   {
      if(r.weighted)
      {
         if(s.strategy_loss==0.0) s.strategy_loss=9999999999.0;
         // The denominator is stored separately from the strategy-loss value.
         if(c.weight_denominator==0.0) return false;
         s.adaptive_fraction=r.max_total_dd/c.weight_denominator;
         if(known_step)
         {
            if(s.strategy_loss==0.0) return false;
            lots=Bot3RoundPrice((((s.adaptive_fraction/s.strategy_loss)*balance)/100.0)*0.01,digits);
         }
      }
      else
      {
         if(r.frequency>=0 && r.frequency<=4)
         {
            double fraction=r.max_total_dd/100.0;
            if(fraction==0.0) return false;
            double bases[5]={200.0,330.0,560.0,810.0,1150.0};
            double amount=(c.enabled_mask & ((uint)1<<r.frequency))!=0 ? bases[r.frequency] : 0.0;
            s.balance_step=(int)(amount/fraction);
         }
         if(known_step)
         {
            if(s.balance_step==0) return false;
            lots=Bot3RoundPrice(0.01*(double)c.multiplier*(c.converted_dd_balance/(double)s.balance_step)*0.01,digits);
         }
      }
   }
   if(s.mode==3 && known_step)
   {
      if(s.strategy_loss==0.0) return false;
      lots=Bot3RoundPrice((((r.strategy_risk/s.strategy_loss)*balance)/100.0)*0.01,digits);
   }
   lots=lots*r.lot_scale;
   if(lots<c.minimum) lots=c.minimum;
   lots=lots<=r.max_lots ? lots : r.max_lots;
   if(lots<c.minimum) s.warnings++;
   if(c.maximum<lots && c.maximum!=0.0) { s.warnings++;lots=c.maximum; }
   // The native function leaves the previous array element for other step sizes.
   if(known_step)
   {
      double power=c.step==0.1 ? 10.0 : (c.step==0.01 ? 100.0 : 1000.0);
      double floored=MathFloor(lots*power)/power;
      s.volume=Bot3RoundPrice(floored,digits);
   }
   return true;
}
#endif
