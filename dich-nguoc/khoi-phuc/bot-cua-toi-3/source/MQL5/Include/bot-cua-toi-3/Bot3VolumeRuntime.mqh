// Complete volume caller 3f900: live terminal reads, withdrawal and currency helpers.
#ifndef BOT3_VOLUME_RUNTIME_MQH
#define BOT3_VOLUME_RUNTIME_MQH
#include "Bot3Volume.mqh"
#include "Bot3VolumeWithdrawal.mqh"
#include "Bot3VolumeCurrency.mqh"
#ifndef BOT3_VOLUME_NUMBER_EXTERNAL
string Bot3VolumeNumber(const double value) { return (string)value; }
#endif
void Bot3PrepareVolumeRuntime(const double stop_distance,const int multiplier,
                             const string &symbol,const string &suffix,const Bot3VolumeSettings &r,
                             Bot3VolumeState &s,const bool reset_on_withdrawal,
                             const string &peak_key,const string &time_key,long &last_check,long &last_deal_time,
                             const double &weight_denominator,const uchar &enabled[],
                             const uint &index,double &volumes[])
{
   s.effective_balance=AccountInfoDouble(ACCOUNT_BALANCE);
   if(r.use_equity) s.effective_balance=AccountInfoDouble(ACCOUNT_EQUITY);
   Bot3VolumeWithdrawals(reset_on_withdrawal,s.effective_balance,peak_key,time_key,
                         last_check,last_deal_time,s.highest_balance);
   if(r.only_up && s.highest_balance>s.effective_balance) s.effective_balance=s.highest_balance;
   else if(s.highest_balance<s.effective_balance)
   {
      s.highest_balance=s.effective_balance;
      GlobalVariableSet(peak_key,s.effective_balance);
   }
   if(r.manual_balance>0.0) s.effective_balance=r.manual_balance;
   if(s.effective_balance==0.0) s.effective_balance=0.01;
   double lots=volumes[index];
   const double tick_value=SymbolInfoDouble(symbol,SYMBOL_TRADE_TICK_VALUE);
   const double steps[]={0.1,0.01,0.001};
   if(s.mode==999 && tick_value>0.0)
   {
      const double converted=Bot3VolumeCurrency(s.effective_balance,suffix,false);
      const double budget=(r.manual_risk/100.0)*converted;
      for(int i=0;i<3;i++)
         if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP)==steps[i])
         {
            const double scaled=(budget/(0.1*stop_distance))*0.1;
            lots=Bot3RoundPrice(((double)multiplier*0.01)*scaled,(uint)i+1);
         }
   }
   if(s.mode==0)
      for(int i=0;i<3;i++)
         if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP)==steps[i])
            lots=Bot3RoundPrice(((double)multiplier*0.01)*r.start_lots,(uint)i+1);
   if(s.mode==9999)
      for(int i=0;i<3;i++)
         if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP)==steps[i])
         {
            const double scaled=(s.effective_balance/(double)s.balance_step)*0.01;
            lots=Bot3RoundPrice(((double)multiplier*0.01)*scaled,(uint)i+1);
         }
   if(s.mode==1234)
   {
      if(r.weighted)
      {
         if(s.strategy_loss==0.0) s.strategy_loss=9999999999.0;
         s.adaptive_fraction=r.max_total_dd/weight_denominator;
         for(int i=0;i<3;i++)
            if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP)==steps[i])
               lots=Bot3RoundPrice((((s.adaptive_fraction/s.strategy_loss)*s.effective_balance)/100.0)*0.01,(uint)i+1);
      }
      else
      {
         const double converted=Bot3VolumeCurrency(s.effective_balance,suffix,true);
         if(r.frequency>=0 && r.frequency<=4)
         {
            const double bases[]={200.0,330.0,560.0,810.0,1150.0};
            const double amount=enabled[r.frequency]!=0 ? bases[r.frequency] : 0.0;
            s.balance_step=(int)(amount/(r.max_total_dd/100.0));
         }
         for(int i=0;i<3;i++)
            if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP)==steps[i])
            {
               const double scaled=(converted/(double)s.balance_step)*0.01;
               lots=Bot3RoundPrice(((double)multiplier*0.01)*scaled,(uint)i+1);
            }
      }
   }
   if(s.mode==3)
      for(int i=0;i<3;i++)
         if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP)==steps[i])
            lots=Bot3RoundPrice((((r.strategy_risk/s.strategy_loss)*s.effective_balance)/100.0)*0.01,(uint)i+1);
   lots=lots*r.lot_scale;
   if(lots<SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN)) lots=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN);
   lots=r.max_lots<lots ? r.max_lots : lots;
   if(lots<SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN))
      Print("Minimum lotsize for this broker is "+Bot3VolumeNumber(SymbolInfoDouble(symbol,SYMBOL_VOLUME_MIN))+" lots!!");
   if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_MAX)<lots)
   {
      if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_MAX)!=0.0)
      {
         Print("Maximum lotsize for this broker is "+Bot3VolumeNumber(SymbolInfoDouble(symbol,SYMBOL_VOLUME_MAX))+" lots!!");
         lots=SymbolInfoDouble(symbol,SYMBOL_VOLUME_MAX);
      }
   }
   double power=0.0;uint digits=0;
   if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP)==0.1) { power=10.0;digits=1; }
   else if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP)==0.01) { power=100.0;digits=2; }
   else if(SymbolInfoDouble(symbol,SYMBOL_VOLUME_STEP)==0.001) { power=1000.0;digits=3; }
   if(digits!=0) volumes[index]=Bot3RoundPrice(MathFloor(lots*power)/power,digits);
}
#endif
