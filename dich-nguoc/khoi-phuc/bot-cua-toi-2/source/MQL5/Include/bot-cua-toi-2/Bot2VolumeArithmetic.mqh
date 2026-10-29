// Pure numeric reconstruction of native RVA 0x35810..0x371f0.
// Scope: history adjustment is disabled (native history flag at RVA 0x68770 = 0).
// Currency conversion is supplied by the caller; this file does not claim to
// reconstruct RVA 0x371f0 or its account-currency string handling.
#ifndef BOT2_VOLUME_ARITHMETIC_MQH
#define BOT2_VOLUME_ARITHMETIC_MQH

double Bot2RoundVolume(const double price,const uint digits)
{
   long whole=(long)price;
   if(whole==LONG_MIN) return price;
   double powers[12]={1.0,10.0,100.0,1000.0,10000.0,100000.0,
                      1000000.0,10000000.0,100000000.0,1000000000.0,
                      10000000000.0,100000000000.0};
   uint precision=digits<11 ? digits : 11;
   double scale=powers[precision];
   return (double)(long)((price-(double)whole)*scale+
                         (0.0<price ? 0.5000001 : -0.5000001))/scale+
          (double)whole;
}

struct Bot2VolumeArithmeticSettings
{
   bool use_equity;       // native RVA 0x68780
   bool only_up;          // native RVA 0x68760
   double manual_balance; // native RVA 0x68730
   double start_lots;     // native RVA 0x5e528
   double max_lots;       // native RVA 0x5e530
   double lot_scale;      // native RVA 0x66230
   double manual_risk;    // native RVA 0x5e540
   double strategy_risk;  // native RVA 0x68748
};

struct Bot2VolumeArithmeticContext
{
   double balance;
   double equity;
   double converted_balance; // supplied result of native RVA 0x371f0
   double tick_value;
   double minimum;
   double maximum;
   double step;
   double stop_distance; // XMM0 / param_1
   int multiplier;        // EDX / param_2
};

struct Bot2VolumeArithmeticState
{
   double volume;          // native array RVA 0x649c0 + index*8
   double effective_balance; // native RVA 0x68260
   double highest_balance; // native RVA 0x68268
   uint mode;              // native RVA 0x5e538
   double strategy_loss;   // native RVA 0x67eb0
   int balance_step;       // native RVA 0x5e548
   uint warnings;
   uint alerts;
   uint peak_writes;
};

bool Bot2VolumeKnownStep(const double step)
{
   return step==0.1 || step==0.01 || step==0.001;
}

uint Bot2VolumeDigits(const double step)
{
   return step==0.1 ? 1 : (step==0.01 ? 2 : 3);
}

double Bot2VolumeRoundStep(const double value,const double step)
{
   return Bot2RoundVolume(value,Bot2VolumeDigits(step));
}

// Pure arithmetic contract. The caller supplies converted_balance and symbol
// properties. It intentionally does not call MT5, print, or mutate history.
bool Bot2PrepareVolumeArithmetic(const Bot2VolumeArithmeticSettings &r,
                                 const Bot2VolumeArithmeticContext &c,
                                 Bot2VolumeArithmeticState &s)
{
   s.warnings=0;s.alerts=0;s.peak_writes=0;
   double balance=r.use_equity ? c.equity : c.balance;
   if(r.only_up && s.highest_balance>balance) balance=s.highest_balance;
   else if(s.highest_balance<balance) { s.highest_balance=balance;s.peak_writes++; }
   if(r.manual_balance>0.0) balance=r.manual_balance;
   if(balance==0.0) balance=0.01;
   s.effective_balance=balance;

   double lots=s.volume;
   const bool known=Bot2VolumeKnownStep(c.step);
   if(s.mode>=1 && s.mode<=998)
   {
      if(c.tick_value==0.0 || c.stop_distance==0.0 || c.multiplier==0)
      { s.alerts++;lots=0.01; }
      else if(known)
      {
         double budget=((double)s.mode/1000.0)*balance;
         double divisor=c.tick_value*c.stop_distance;
         if(divisor==0.0) return false;
         double raw=(double)c.multiplier*0.01*(budget/divisor)*0.1;
         lots=Bot2VolumeRoundStep(raw,c.step);
      }
   }
   if(s.mode==999)
   {
      if(!(c.tick_value>0.0)) { s.alerts++;s.mode=9999; }
      else if(known)
      {
         double divisor=0.1*c.stop_distance;
         if(divisor==0.0) return false;
         double raw=(double)c.multiplier*0.01*
                    ((r.manual_risk/100.0*c.converted_balance)/
                     divisor)*0.1;
         lots=Bot2VolumeRoundStep(raw,c.step);
      }
   }
   if(s.mode==0 && known)
      lots=Bot2VolumeRoundStep((double)c.multiplier*0.01*r.start_lots,c.step);
   if(s.mode==9999 && known)
   {
      if(s.balance_step==0) return false;
      lots=Bot2VolumeRoundStep(0.01*(double)c.multiplier*
                               ((balance/(double)s.balance_step)*0.01),c.step);
   }
   // Native mode 3 is independent and runs after the generic 1..998 branch.
   if(s.mode==3 && known)
   {
      if(s.strategy_loss==0.0) return false;
      lots=Bot2VolumeRoundStep((((r.strategy_risk/s.strategy_loss)*balance)/100.0)*0.01,c.step);
   }
   lots*=r.lot_scale;
   if(lots<c.minimum) lots=c.minimum;
   // Native MINSD keeps its volume operand on unordered/equal inputs.
   if(lots>r.max_lots) lots=r.max_lots;
   if(lots<c.minimum) s.warnings++;
   if(c.maximum<lots && c.maximum!=0.0) { s.warnings++;lots=c.maximum; }
   if(known)
   {
      double power=c.step==0.1 ? 10.0 : (c.step==0.01 ? 100.0 : 1000.0);
      double floored=MathFloor(lots*power)/power;
      s.volume=Bot2RoundVolume(floored,Bot2VolumeDigits(c.step));
   }
   return true;
}

#endif
